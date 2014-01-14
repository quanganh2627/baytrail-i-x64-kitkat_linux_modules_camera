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

#ifndef ATOMISP_H
#define ATOMISP_H

#include <linux/ioport.h>
#include <linux/list.h>

#include "atomisp-pdata.h"
#include "atomisp-bus.h"

#define ATOMISP_NAME		"atomisp"

#define ATOMISP_HW_BXT_PSS_1	0x22e0

struct pci_dev;
struct list_head;

#define NR_OF_MMU_RESOURCES			2

struct atomisp_device {
	struct pci_dev *pdev;
	struct list_head devices;
	struct atomisp_bus_device *isys_iommu, *isys;
};

#endif
