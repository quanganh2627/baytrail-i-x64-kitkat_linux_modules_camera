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
#include <linux/iommu.h>
#include <linux/iova.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include "atomisp.h"
#include "atomisp-bus.h"
#include "atomisp-dma.h"
#include "atomisp-mmu.h"

/* begin: Taken from isp_mmu.h */

#define ISP_PAGE_SHIFT		12
#define ISP_PAGE_SIZE		(1U << ISP_PAGE_SHIFT)
#define ISP_PAGE_MASK		(~(ISP_PAGE_SIZE - 1))

#define ISP_L1PT_SHIFT		22
#define ISP_L1PT_MASK		(~((1U << ISP_L1PT_SHIFT) - 1))

#define ISP_L2PT_SHIFT		12
#define ISP_L2PT_MASK		(~(ISP_L1PT_MASK|(~(ISP_PAGE_MASK))))

#define ISP_L1PT_PTES           1024
#define ISP_L2PT_PTES           1024

#define INVALID_PAGE		((phys_addr_t)(-1) & ISP_PAGE_MASK)

/* end: Taken from isp_mmu.h */

static void page_table_dump(struct atomisp_mmu_domain *adom)
{
	uint32_t l1_idx;

	pr_info("begin IOMMU page table dump\n");

	for (l1_idx = 0; l1_idx < ISP_L1PT_PTES; l1_idx++) {
		uint32_t l2_idx;
		uint32_t l1_phys_start = (1 << ISP_L1PT_SHIFT) * l1_idx;

		if (adom->pgtbl[l1_idx] == INVALID_PAGE)
			continue;
		pr_info("l1 entry %u; iovas 0x%8.8x--0x%8.8x, at %p\n", l1_idx,
			l1_phys_start, l1_phys_start + (1 << ISP_L1PT_SHIFT),
			(void *)adom->pgtbl[l1_idx]);

		for (l2_idx = 0; l2_idx < ISP_L2PT_PTES; l2_idx++) {
			uint32_t *l2_pt = (uint32_t *)adom->pgtbl[l1_idx];
			uint32_t l2_phys_start = l1_phys_start
				+ l2_idx * (1 << ISP_L2PT_SHIFT);

			if (l2_pt[l2_idx] == INVALID_PAGE)
				continue;

			pr_info("\tl2 entry %u; iova 0x%8.8x, phys 0x%8.8x\n",
				l2_idx, l2_phys_start, l2_pt[l2_idx]);
		}
	}

	pr_info("end IOMMU page table dump\n");
}

static uint32_t *alloc_page_table(struct atomisp_mmu_domain *adom)
{
	uint32_t *pt = (uint32_t *)__get_free_page(GFP_KERNEL);
	int i;

	if (!pt)
		return (uint32_t *)INVALID_PAGE;

	pr_info("__get_free_page() == %p\n", pt);
	/* we need an uncacheable page table --- why? */
#ifdef	CONFIG_X86
	set_memory_uc((unsigned long)pt, 1);
#endif

	for (i = 0; i < ISP_L1PT_PTES; i++)
		pt[i] = INVALID_PAGE;

	return pt;
}

static void free_page_table(uint32_t *pt)
{
	if (pt == (uint32_t *)INVALID_PAGE)
		return;

	pr_info("free_page(%p)\n", pt);
#ifdef	CONFIG_X86
	set_memory_wb((unsigned long)pt, 1);
#endif

	free_page((unsigned long)pt);
}

static int atomisp_mmu_domain_init(struct iommu_domain *domain)
{
	struct atomisp_mmu_domain *adom;

	adom = kzalloc(sizeof(*adom), GFP_KERNEL);
	if (!adom)
		return -ENOMEM;

	domain->priv = adom;
	adom->domain = domain;

	/*
	 * We always map the L1 page table (a single page as well as
	 * the L2 page tables).
	 */
	adom->pgtbl = alloc_page_table(adom);
	INIT_LIST_HEAD(&adom->mmu_devs);
	spin_lock_init(&adom->lock);

	pr_info("domain initialised\n");
	pr_info("ops %p\n", domain->ops);

	return 0;
}

static void atomisp_mmu_domain_destroy(struct iommu_domain *domain)
{
	struct atomisp_mmu_domain *adom = domain->priv;
	uint32_t l1_idx;

	for (l1_idx = 0; l1_idx < ISP_L1PT_PTES; l1_idx++)
		free_page_table((uint32_t *)adom->pgtbl[l1_idx]);

	free_page_table(adom->pgtbl);
	kfree(adom);
}

static int atomisp_mmu_attach_dev(struct iommu_domain *domain,
				  struct device *dev)
{
	struct atomisp_mmu_domain *adom = domain->priv;
	int rval = 0;

	spin_lock(&adom->lock);

	adom->users++;

	dev_info(dev, "domain attached\n");

	spin_unlock(&adom->lock);

	return rval;
}

static void atomisp_mmu_detach_dev(struct iommu_domain *domain,
				   struct device *dev)
{
	struct atomisp_mmu_domain *adom = domain->priv;

	spin_lock(&adom->lock);

	if (!--adom->users) {
	}
	dev_info(dev, "domain detached\n");

	spin_unlock(&adom->lock);
}

static int l2_map(struct iommu_domain *domain, unsigned long iova,
		  phys_addr_t paddr, size_t size)
{
	struct atomisp_mmu_domain *adom = domain->priv;
	uint32_t l1_idx = iova >> ISP_L1PT_SHIFT;
	uint32_t *l2_pt;
	uint32_t iova_start = iova;
	unsigned int l2_idx;

	pr_info("mapping l2 page table for l1 index %u (iova %p)\n", l1_idx,
		(void *)iova);

	if (adom->pgtbl[l1_idx] == INVALID_PAGE) {
		adom->pgtbl[l1_idx] = (unsigned long)alloc_page_table(adom);
		pr_info("allocated page for l1_idx %u\n", l1_idx);
	}

	if (adom->pgtbl[l1_idx] == INVALID_PAGE)
		return -ENOMEM;

	l2_pt = (uint32_t *)adom->pgtbl[l1_idx];

	pr_info("l2_pt at %p\n", l2_pt);

	paddr = ALIGN(paddr, ISP_PAGE_SIZE);

	for (l2_idx = (iova_start & ISP_L2PT_MASK) >> ISP_L2PT_SHIFT;
	     (iova_start & ISP_L1PT_MASK) + (l2_idx << ISP_L2PT_SHIFT)
		     < iova_start + size;
	     l2_idx++) {
		pr_info("l2_idx %u\n", l2_idx);
		if (l2_pt[l2_idx] == INVALID_PAGE)
			l2_pt[l2_idx] = paddr;
		else
			return -EBUSY;
		pr_info("l2 index %u mapped as 0x%8.8x\n", l2_idx,
			l2_pt[l2_idx]);
		paddr += ISP_PAGE_SIZE;
	}

	return 0;
}

static int atomisp_mmu_map(struct iommu_domain *domain, unsigned long iova,
			   phys_addr_t paddr, size_t size, int prot)
{
	uint32_t iova_start = round_down(iova, ISP_PAGE_SIZE);
	uint32_t iova_end = ALIGN(iova + size, ISP_PAGE_SIZE);

	pr_info("mapping iova 0x%8.8x--0x%8.8x, size %u at paddr %p\n",
		iova_start, iova_end, size, (void *)(uint32_t)paddr);

	return l2_map(domain, iova_start, paddr, size);
}

static int l2_unmap(struct iommu_domain *domain, unsigned long iova,
		    phys_addr_t dummy, size_t size)
{
	struct atomisp_mmu_domain *adom = domain->priv;
	uint32_t l1_idx = iova >> ISP_L1PT_SHIFT;
	uint32_t *l2_pt = (uint32_t *)adom->pgtbl[l1_idx];
	uint32_t iova_start = iova;
	unsigned int l2_idx;

	pr_info("unmapping l2 page table for l1 index %u (iova 0x%8.8lx)\n",
		l1_idx, iova);

	if (adom->pgtbl[l1_idx] == INVALID_PAGE)
		return -EINVAL;

	pr_info("l2_pt at %p\n", l2_pt);

	for (l2_idx = (iova_start & ISP_L2PT_MASK) >> ISP_L2PT_SHIFT;
	     (iova_start & ISP_L1PT_MASK) + (l2_idx << ISP_PAGE_SHIFT)
		     < iova_start + size;
	     l2_idx++) {
		pr_info("l2 index %u unmapped, was 0x%8.8x\n", l2_idx,
			l2_pt[l2_idx]);
		l2_pt[l2_idx] = INVALID_PAGE;
	}

	return 0;
}

static size_t atomisp_mmu_unmap(struct iommu_domain *domain, unsigned long iova,
				size_t size)
{
	return l2_unmap(domain, iova, 0, size);
}

static phys_addr_t atomisp_mmu_iova_to_phys(struct iommu_domain *domain,
					    dma_addr_t iova)
{
	struct atomisp_mmu_domain *adom = domain->priv;
	uint32_t *l2_pt = (uint32_t *)adom->pgtbl[iova >> ISP_L1PT_SHIFT];

	return l2_pt[(iova & ISP_L2PT_MASK) >> ISP_L2PT_SHIFT];
}

static int atomisp_mmu_device_group(struct device *dev, unsigned int *groupid)
{
	return 0;
}

static int atomisp_mmu_domain_has_cap(struct iommu_domain *domain,
				      unsigned long cap)
{
	return 0;
}

static struct atomisp_dma_mapping *alloc_dma_mapping(struct device *dev)
{
	struct atomisp_dma_mapping *dmap = kzalloc(sizeof(*dmap), GFP_KERNEL);

	if (!dmap)
		return NULL;

	dmap->domain = iommu_domain_alloc(dev->bus);
	if (!dmap->domain) {
		kfree(dmap);
		return NULL;
	}

	init_iova_domain(&dmap->iovad, DMA_BIT_MASK(32) >> PAGE_SHIFT);

	kref_init(&dmap->ref);

	pr_info("alloc mapping\n");

	return dmap;
}

static void free_dma_mapping(struct kref *ref)
{
	struct atomisp_dma_mapping *dmap =
		container_of(ref, struct atomisp_dma_mapping, ref);

	put_iova_domain(&dmap->iovad);
	iommu_domain_free(dmap->domain);
	kfree(dmap);
}

static int atomisp_mmu_add_device(struct device *dev)
{
	struct atomisp_mmu_device *mmu = dev_get_drvdata(dev->archdata.iommu);
	struct atomisp_dma_mapping *dmap;
	struct atomisp_mmu_domain *adom;
	int rval;

	pr_info("dev %s\n", dev_name(dev));

	if (!mmu)
		return 0;

	if (!mmu->dmap) {
		mmu->dmap = alloc_dma_mapping(dev);
		if (!mmu->dmap)
			return -ENOMEM;
	}
	dmap = mmu->dmap;
	pr_info("dmap %p\n", dmap);

	adom = dmap->domain->priv;
	adom->dmap = dmap;

	pr_info("attach %p\n", dmap->domain);
	pr_info("attach 2 %p\n", dmap->domain->ops);
	pr_info("attach 3 %p\n", dmap->domain->ops->attach_dev);

	rval = iommu_attach_device(dmap->domain, dev);
	if (rval)
		return rval;

	kref_get(&dmap->ref);

	return 0;
}

static void atomisp_mmu_remove_device(struct device *dev)
{
	struct atomisp_mmu_device *mmu = dev_get_drvdata(dev->archdata.iommu);

	kref_put(&mmu->dmap->ref, &free_dma_mapping);
}

struct iommu_ops atomisp_iommu_ops = {
	.domain_init	= atomisp_mmu_domain_init,
	.domain_destroy	= atomisp_mmu_domain_destroy,
	.attach_dev	= atomisp_mmu_attach_dev,
	.detach_dev	= atomisp_mmu_detach_dev,
	.map		= atomisp_mmu_map,
	.unmap		= atomisp_mmu_unmap,
	.iova_to_phys	= atomisp_mmu_iova_to_phys,
	.device_group	= atomisp_mmu_device_group,
	.domain_has_cap	= atomisp_mmu_domain_has_cap,
	.add_device	= atomisp_mmu_add_device,
	.remove_device	= atomisp_mmu_remove_device,
	.pgsize_bitmap	= SZ_4K,
};

static int atomisp_mmu_probe(struct atomisp_bus_device *adev)
{
	struct atomisp_mmu_device *mmu;

	mmu = devm_kzalloc(&adev->dev, sizeof(*mmu), GFP_KERNEL);
	if (!mmu)
		return -ENOMEM;

	iova_cache_init();

	dev_info(&adev->dev, "mmu probe %p %p\n", adev, &adev->dev);
	atomisp_bus_set_drvdata(adev, mmu);

	atomisp_bus_set_iommu(&atomisp_iommu_ops);

	/*
	 * FIXME: We can't unload this --- bus_set_iommu() will
	 * register a notifier which must stay until the devices are
	 * gone.
	 */
	__module_get(THIS_MODULE);

	return 0;
}

/*
 * Leave iommu ops as they were --- this means we must be called as
 * the very last.
 */
static void atomisp_mmu_remove(struct atomisp_bus_device *adev)
{
	dev_info(&adev->dev, "removed\n");
}

static void atomisp_mmu_isr(struct atomisp_bus_device *adev)
{
	struct atomisp_mmu_device *mmu = atomisp_bus_get_drvdata(adev);

	dev_info(&adev->dev, "Yeah!\n");
}

static struct atomisp_bus_driver atomisp_mmu_driver = {
	.probe = atomisp_mmu_probe,
	.remove = atomisp_mmu_remove,
	.isr = atomisp_mmu_isr,
	.wanted = ATOMISP_MMU_NAME,
	.drv = {
		.name = ATOMISP_MMU_NAME,
		.owner = THIS_MODULE,
	},
};

module_atomisp_bus_driver(atomisp_mmu_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
