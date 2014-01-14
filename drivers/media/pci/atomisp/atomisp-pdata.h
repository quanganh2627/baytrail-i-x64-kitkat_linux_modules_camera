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

#ifndef ATOMISP_PDATA_H
#define ATOMISP_PDATA_H

#define ATOMISP_MMU_NAME ATOMISP_NAME "-mmu"
#define ATOMISP_CSI2_NAME ATOMISP_NAME "-csi2"
#define ATOMISP_ISYS_NAME ATOMISP_NAME "-isys"
#define ATOMISP_PSYS_NAME ATOMISP_NAME "-psys"

#define ATOMISP_MMU_MAX_DEVICES		2

struct atomisp_mmu_pdata {
	void __iomem *base[ATOMISP_MMU_MAX_DEVICES];
	unsigned int nr_base;
};

struct atomisp_csi2_pdata {
	void __iomem *base;
};

struct atomisp_isys_pdata {
	void __iomem *base;
};

struct atomisp_psys_pdata {
	void __iomem *base;
};

#endif
