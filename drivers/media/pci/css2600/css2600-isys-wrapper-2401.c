/*
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <asm/cacheflush.h>

#include <linux/iommu.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>

#include "css2600-bus.h"
#include "css2600-dma.h"
#include "css2600-isys-wrapper-2401.h"
#include "css2600-mmu.h"
#include "lib2401/ia_css_env.h"

struct my_css_memory_buffer_item {
	struct list_head list;
	dma_addr_t iova;
	void *addr;
	size_t bytes;
	struct dma_attrs attrs;
};

struct {
	struct device *dev; /*ISYS*/
	void __iomem *isp_base; /*IUNIT PCI base address*/
	struct iommu_domain *domain;
	struct list_head buffers;
	struct mutex lock;
} mine;

/*Virtual address to physical address convert*/
static phys_addr_t glue_virt_to_phys(ia_css_ptr virt)
{
	return iommu_iova_to_phys(mine.domain, virt);
}

/*Small buffers for CSS layer internal usage*/
static void *glue_ia_alloc(size_t bytes, bool zero_mem)
{
	if (zero_mem)
		return kmalloc(bytes, GFP_KERNEL);
	else
		return kzalloc(bytes, GFP_KERNEL);
}
static void glue_ia_free(void *ptr)
{
	kfree(ptr);
}

/*Flush cache*/
static void glue_ia_flush(struct ia_css_acc_fw *fw)
{
	wbinvd();
}

static ia_css_ptr glue_css_alloc(size_t bytes, uint32_t attributes)
{
	struct dma_map_ops *dma_ops = mine.dev->archdata.dma_ops;
	struct my_css_memory_buffer_item *buf;

	might_sleep();

	buf = kzalloc(sizeof(*buf), GFP_KERNEL);
	if (!buf)
		return 0;

	/*Attribute checking*/
	if (attributes & IA_CSS_MEM_ATTR_CONTIGUOUS)
		dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &buf->attrs);

	/*alloc using css2600 dma driver*/
	buf->bytes = PAGE_ALIGN(bytes);
	buf->addr = dma_ops->alloc(mine.dev, buf->bytes, &buf->iova,
				   GFP_KERNEL, &buf->attrs);

	if (!buf->addr) {
		kfree(buf);
		return 0;
	}

	mutex_lock(&mine.lock);
	list_add(&buf->list, &mine.buffers);
	mutex_unlock(&mine.lock);

	return buf->iova;
}

static void glue_css_free(ia_css_ptr iova)
{
	struct dma_map_ops *dma_ops = mine.dev->archdata.dma_ops;
	struct my_css_memory_buffer_item *buf = NULL;

	might_sleep();

	pr_debug("looking for iova %8.8x\n", iova);

	mutex_lock(&mine.lock);
	list_for_each_entry(buf, &mine.buffers, list) {
		pr_debug("buffer iova %8.8x\n", (uint32_t)buf->iova);
		if (buf->iova != iova)
			continue;

		pr_debug("found it!\n");
		dma_ops->free(mine.dev, buf->bytes, buf->addr,
			      buf->iova, &buf->attrs);
		goto out;
	}
	pr_warn("Can't find iova object %8.8x\n", iova);
out:
	mutex_unlock(&mine.lock);
}

static int glue_css_load(ia_css_ptr ptr, void *data, size_t bytes)
{
	/*Translate ISP MMU address to IA address*/
	void *cpu_ptr = phys_to_virt(glue_virt_to_phys(ptr));

	clflush_cache_range(cpu_ptr, bytes);
	memcpy(data, cpu_ptr, bytes);

	return 0;
}

static int glue_css_store(ia_css_ptr ptr, const void *data, size_t bytes)
{
	/*Translate ISP address to IA  address*/
	void *cpu_ptr = phys_to_virt(glue_virt_to_phys(ptr));

	memcpy(cpu_ptr, data, bytes);
	clflush_cache_range(cpu_ptr, bytes);

	return 0;
}


static ia_css_ptr glue_css_mmap(const void *ptr, const size_t size,
				uint16_t attribute, void *context)
{
	pr_err("Memory mapping from CSS not supported!\n");
	return 0;
}

static int glue_print_error(const char *fmt, va_list a)
{
	vprintk(fmt, a);
	return 0;
}

static int glue_print_debug(const char *fmt, va_list a)
{
	vprintk(fmt, a);
	return 0;
}

/*Hw access functions*/
static inline void __iomem *glue_get_io_virt_addr(hrt_address address)
{
	void __iomem *ret = mine.isp_base + (address & 0x003FFFFF);
	return ret;
}


static void glue_hw_store8(hrt_address addr, uint8_t data)
{
	*((u8 __force *)glue_get_io_virt_addr(addr)) = (data);
}

static void glue_hw_store16(hrt_address addr, uint16_t data)
{
	*((u16 __force *)glue_get_io_virt_addr(addr)) = (data);
}

static void glue_hw_store32(hrt_address addr, uint32_t data)
{
	*((u32 __force *)glue_get_io_virt_addr(addr)) = (data);
}

static uint8_t glue_hw_load8(hrt_address addr)
{
	return *(u8 __force *)glue_get_io_virt_addr(addr);
}

static uint16_t glue_hw_load16(hrt_address addr)
{
	return *(u16 __force *)glue_get_io_virt_addr(addr);
}

static uint32_t glue_hw_load32(hrt_address addr)
{
	return *(u32 __force *)glue_get_io_virt_addr(addr);
}

/*Copied from HRT, unefficient???*/
static void glue_mem_store(hrt_address to, const void *from, uint32_t n)
{
	int i;
	hrt_address _to = to;
	const char *_from = (const char *)from;
	for (i = 0; i < n; i++, _to++, _from++)
		glue_hw_store8(_to, *_from);
}

static void glue_mem_load(hrt_address from, void *to, uint32_t n)
{
	int i;
	char *_to = (char *)to;
	hrt_address _from = from;
	for (i = 0; i < n; i++, _to++, _from++)
		*_to = glue_hw_load8(_from);
}

/*Call this from ISYS driver init*/
void css2600_isys_wrapper_init(
	struct device *dev, struct ia_css_env *mycssmapenv, void __iomem *base)
{
	struct css2600_bus_iommu *aiommu = to_css2600_bus_device(dev)->iommu;
	struct css2600_mmu *mmu = dev_get_drvdata(aiommu->dev);

	INIT_LIST_HEAD(&mine.buffers);
	mutex_init(&mine.lock);

	/*Store Needed device pointers locally*/
	mine.dev = dev;
	/*Set PCI base address for HW access*/
	mine.isp_base = base;
	/*Mmu domain pointer needed to address translation*/
	mine.domain = mmu->dmap->domain;

	/*Map functions to function pointer table*/
	/*IA memory alloc*/
	mycssmapenv->cpu_mem_env.alloc = glue_ia_alloc;
	mycssmapenv->cpu_mem_env.free = glue_ia_free;
	mycssmapenv->cpu_mem_env.flush = glue_ia_flush;

	/*CSS memory alloc*/
	mycssmapenv->css_mem_env.alloc = glue_css_alloc;
	mycssmapenv->css_mem_env.free = glue_css_free;
	mycssmapenv->css_mem_env.store = glue_css_store;
	mycssmapenv->css_mem_env.load = glue_css_load;
	mycssmapenv->css_mem_env.mmap = glue_css_mmap;
	/*CSS HW access*/
	mycssmapenv->hw_access_env.store_8 = glue_hw_store8;
	mycssmapenv->hw_access_env.store_16 = glue_hw_store16;
	mycssmapenv->hw_access_env.store_32 = glue_hw_store32;
	mycssmapenv->hw_access_env.load_8 = glue_hw_load8;
	mycssmapenv->hw_access_env.load_16 = glue_hw_load16;
	mycssmapenv->hw_access_env.load_32 = glue_hw_load32;
	mycssmapenv->hw_access_env.load = glue_mem_load;
	mycssmapenv->hw_access_env.store = glue_mem_store;

	/*Print functions*/
	mycssmapenv->print_env.error_print = glue_print_error;
	mycssmapenv->print_env.debug_print = glue_print_debug;
}
EXPORT_SYMBOL_GPL(css2600_isys_wrapper_init);

MODULE_AUTHOR("Jouni Ukkonen <jouni.ukkonen@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("CSS wrapper");
