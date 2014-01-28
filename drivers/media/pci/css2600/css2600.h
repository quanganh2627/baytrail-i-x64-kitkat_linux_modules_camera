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

#ifndef CSS2600_H
#define CSS2600_H

#include <linux/ioport.h>
#include <linux/list.h>

#include "css2600-pdata.h"
#include "css2600-bus.h"

#define CSS2600_NAME		"css2600"

#define CSS2600_HW_MRFLD_2401	0x1478
#define CSS2600_HW_BXT		0x10000 /* FIXME */
#define CSS2600_HW_BXT_FPGA	0x22e0

struct pci_dev;
struct list_head;

#define NR_OF_MMU_RESOURCES			2

struct css2600_device {
	struct pci_dev *pdev;
	struct list_head devices;
	struct css2600_bus_device *isys_iommu, *isys;
	struct css2600_bus_device *psys_iommu, *psys;
};

#endif
