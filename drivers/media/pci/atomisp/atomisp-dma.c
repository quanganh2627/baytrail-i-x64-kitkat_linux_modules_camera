/*
 * Copyright (c) 2013 Intel Corporation. All Rights Reserved.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include <asm/cacheflush.h>

#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/gfp.h>
#include <linux/highmem.h>
#include <linux/iommu.h>
#include <linux/iova.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/sizes.h>
#include <linux/vmalloc.h>

#include "atomisp-dma.h"
#include "atomisp-mmu.h"

/* Begin of things adapted from arch/arm/mm/dma-mapping.c */
static void __dma_clear_buffer(struct page *page, size_t size)
{
	/*
	 * Ensure that the allocated pages are zeroed, and that any data
	 * lurking in the kernel direct-mapped region is invalidated.
	 */
	if (PageHighMem(page)) {
		while (size > 0) {
			void *ptr = kmap_atomic(page);
			memset(ptr, 0, PAGE_SIZE);
			clflush_cache_range(ptr, PAGE_SIZE);
			kunmap_atomic(ptr);
			page++;
			size -= PAGE_SIZE;
		}
	} else {
		void *ptr = page_address(page);
		memset(ptr, 0, size);
		clflush_cache_range(ptr, size);
	}
}

static struct page **__iommu_alloc_buffer(struct device *dev, size_t size,
					  gfp_t gfp, struct dma_attrs *attrs)
{
	struct page **pages;
	int count = size >> PAGE_SHIFT;
	int array_size = count * sizeof(struct page *);
	int i = 0;

	if (array_size <= PAGE_SIZE)
		pages = kzalloc(array_size, gfp);
	else
		pages = vzalloc(array_size);
	if (!pages)
		return NULL;

	/*
	 * IOMMU can map any pages, so himem can also be used here
	 */
	gfp |= __GFP_NOWARN | __GFP_HIGHMEM;

	while (count) {
		int j, order = __fls(count);

		pages[i] = alloc_pages(gfp, order);
		while (!pages[i] && order)
			pages[i] = alloc_pages(gfp, --order);
		if (!pages[i])
			goto error;

		if (order) {
			split_page(pages[i], order);
			j = 1 << order;
			while (--j)
				pages[i + j] = pages[i] + j;
		}

		__dma_clear_buffer(pages[i], PAGE_SIZE << order);
		i += 1 << order;
		count -= 1 << order;
	}

	return pages;
error:
	while (i--)
		if (pages[i])
			__free_pages(pages[i], 0);
	if (array_size <= PAGE_SIZE)
		kfree(pages);
	else
		vfree(pages);
	return NULL;
}

static int __iommu_free_buffer(struct device *dev, struct page **pages,
			       size_t size, struct dma_attrs *attrs)
{
	int count = size >> PAGE_SHIFT;
	int array_size = count * sizeof(struct page *);
	int i;

	for (i = 0; i < count; i++)
		if (pages[i])
			__free_pages(pages[i], 0);

	if (array_size <= PAGE_SIZE)
		kfree(pages);
	else
		vfree(pages);
	return 0;
}

/*
 * Create a CPU mapping for a specified pages
 */
static void *
__iommu_alloc_remap(struct page **pages, size_t size, gfp_t gfp, pgprot_t prot,
		    const void *caller)
{
	unsigned int i, nr_pages = PAGE_ALIGN(size) >> PAGE_SHIFT;
	struct vm_struct *area;
	unsigned long p;

	area = get_vm_area_caller(size, VM_USERMAP, caller);
	if (!area)
		return NULL;

	area->pages = pages;
	area->nr_pages = nr_pages;
	p = (unsigned long)area->addr;

	for (i = 0; i < nr_pages; i++) {
		phys_addr_t phys = page_to_pfn(pages[i]) << PAGE_SHIFT;
		if (ioremap_page_range(p, p + PAGE_SIZE, phys, prot))
			goto err;
		p += PAGE_SIZE;
	}
	return area->addr;
err:
	unmap_kernel_range((unsigned long)area->addr, size);
	vunmap(area->addr);
	return NULL;
}

static struct page **__iommu_get_pages(void *cpu_addr, struct dma_attrs *attrs)
{
	struct vm_struct *area;

	area = find_vm_area(cpu_addr);
	if (area)
		return area->pages;
	return NULL;
}

/* End of things adapted from arch/arm/mm/dma-mapping.c */

static void *atomisp_dma_alloc(struct device *dev, size_t size,
			       dma_addr_t *dma_handle, gfp_t gfp,
			       struct dma_attrs *attrs)
{
	struct atomisp_mmu *mmu = dev_get_drvdata(dev->archdata.iommu);
	struct page **pages;
	struct iova *iova;
	uint32_t iova_addr;
	void *addr;
	int i;
	int rval;

	iova = alloc_iova(&mmu->dmap->iovad, size,
			  DMA_BIT_MASK(32) >> PAGE_SHIFT, 0);
	if (!iova)
		return NULL;

	pages = __iommu_alloc_buffer(dev, size, gfp, attrs);
	if (!pages)
		goto out_free_iova;

	iova_addr = iova->pfn_lo;

	for (i = 0; i < (size >> PAGE_SHIFT) && iova_addr < iova->pfn_hi; i++) {
		rval = iommu_map(mmu->dmap->domain, iova_addr << PAGE_SHIFT,
				 page_to_phys(pages[i]), PAGE_SIZE, 0);
		if (rval)
			goto out_unmap;

		iova_addr++;
	}

	addr = __iommu_alloc_remap(pages, size, gfp, __pgprot(0),
				   __builtin_return_address(0));
	if (!addr)
		goto out_unmap;

	return addr;

out_unmap:
	__iommu_free_buffer(dev, pages, size, attrs);
	for (i--; i >= 0; i--) {
		iova_addr--;
		iommu_unmap(mmu->dmap->domain, iova_addr << PAGE_SHIFT,
			    PAGE_SIZE);
	}
out_free_iova:
	__free_iova(&mmu->dmap->iovad, iova);

	return NULL;
}

static void atomisp_dma_free(struct device *dev, size_t size, void *vaddr,
			     dma_addr_t dma_handle, struct dma_attrs *attrs)
{
	struct atomisp_mmu *mmu = dev_get_drvdata(dev->archdata.iommu);
	struct iova *iova =
		find_iova(&mmu->dmap->iovad, dma_handle >> PAGE_SHIFT);
	struct page **pages = __iommu_get_pages(vaddr, attrs);

	if (WARN_ON(!pages))
		return;

	unmap_kernel_range((unsigned long)vaddr, size);
	vunmap(vaddr);

	__free_iova(&mmu->dmap->iovad, iova);

	__iommu_free_buffer(dev, pages, size, attrs);
}

static void atomisp_dma_unmap_sg(struct device *dev, struct scatterlist *sglist,
				 int nents, enum dma_data_direction dir,
				 struct dma_attrs *attrs)
{
	struct atomisp_mmu *mmu = dev_get_drvdata(dev->archdata.iommu);
	struct iova *iova = find_iova(&mmu->dmap->iovad,
				      sg_dma_address(sglist) >> PAGE_SHIFT);

	if (!nents)
		return;

	BUG_ON(!iova);

	iommu_unmap(mmu->dmap->domain, iova->pfn_lo << PAGE_SHIFT,
		    (iova->pfn_hi - iova->pfn_lo + 1) << PAGE_SHIFT);

	mmu->tlb_invalidate(mmu);
}

static int atomisp_dma_map_sg(struct device *dev, struct scatterlist *sglist,
			      int nents, enum dma_data_direction dir,
			      struct dma_attrs *attrs)
{
	struct atomisp_mmu *mmu = dev_get_drvdata(dev->archdata.iommu);
	struct scatterlist *sg;
	struct iova *iova;
	size_t size = 0;
	uint32_t iova_addr;
	int i;
	int rval;

	for_each_sg(sglist, sg, nents, i)
		size += PAGE_ALIGN(sg->length) >> PAGE_SHIFT;

	dev_info(dev, "mapping sg %d entries, %zu pages\n", nents, size);

	iova = alloc_iova(&mmu->dmap->iovad, size,
			  DMA_BIT_MASK(32) >> PAGE_SHIFT, 0);
	if (!iova)
		return -ENOMEM;

	dev_info(dev, "iova low pfn %lu, high pfn %lu\n", iova->pfn_lo,
		 iova->pfn_hi);

	iova_addr = iova->pfn_lo;

	for_each_sg(sglist, sg, nents, i) {
		dev_info(dev,
			 "mapping entry %d: iova 0x%8.8x, physical 0x%16.16llx\n",
			 i, iova_addr << PAGE_SHIFT, page_to_phys(sg_page(sg)));
		rval = iommu_map(mmu->dmap->domain, iova_addr << PAGE_SHIFT,
				 page_to_phys(sg_page(sg)),
				 PAGE_ALIGN(sg->length), 0);
		if (rval)
			goto out_fail;
		sg_dma_address(sg) = iova_addr << PAGE_SHIFT;

		iova_addr += PAGE_ALIGN(sg->length) >> PAGE_SHIFT;
	}

	mmu->tlb_invalidate(mmu);

	return 0;

out_fail:
	atomisp_dma_unmap_sg(dev, sglist, i, dir, attrs);

	return rval;
}

static void atomisp_dma_sync_sg_for_cpu(
	struct device *dev, struct scatterlist *sglist, int nents,
	enum dma_data_direction dir)
{
	struct scatterlist *sg;
	int i;

	for_each_sg(sglist, sg, nents, i)
		clflush_cache_range(sg_page(sg), sg->length);
}

struct dma_map_ops atomisp_dma_ops = {
	.alloc = atomisp_dma_alloc,
	.free = atomisp_dma_free,
	.map_sg = atomisp_dma_map_sg,
	.unmap_sg = atomisp_dma_unmap_sg,
	.sync_sg_for_cpu = atomisp_dma_sync_sg_for_cpu,
};
EXPORT_SYMBOL_GPL(atomisp_dma_ops);
