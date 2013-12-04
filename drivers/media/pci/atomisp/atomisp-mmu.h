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

#ifndef ATOMISP_MMU_H
#define ATOMISP_MMU_H

#include "atomisp.h"
#include "atomisp-pdata.h"

struct pci_dev;

/*
 * @pgtbl: virtual address of the l1 page table (one page)
 */
struct atomisp_mmu_domain {
	uint32_t __iomem *pgtbl;
	struct list_head mmu_devs;
	struct iommu_domain *domain;
	spinlock_t lock;
	unsigned int users;
	struct atomisp_dma_mapping *dmap;
};

/*
 * @pgtbl: physical address of the l1 page table
 */
struct atomisp_mmu {
	struct list_head node;
	unsigned int users;

	void __iomem *base;

	phys_addr_t pgtbl;
	struct device *dev;

	struct atomisp_mmu_pdata *pdata;
	struct atomisp_dma_mapping *dmap;
};

#endif
