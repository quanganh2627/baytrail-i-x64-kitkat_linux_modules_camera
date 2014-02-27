/*
 * Copyright (c) 2013--2014 Intel Corporation. All Rights Reserved.
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

#ifndef CSS2600_PDATA_H
#define CSS2600_PDATA_H

#define CSS2600_MMU_NAME CSS2600_NAME "-mmu"
#define CSS2600_ISYS_CSI2_NAME CSS2600_NAME "-csi2"
#define CSS2600_ISYS_NAME CSS2600_NAME "-isys"
#define CSS2600_PSYS_NAME CSS2600_NAME "-psys"
#define CSS2600_BUTTRESS_NAME CSS2600_NAME "-buttress"

#define CSS2600_MMU_MAX_DEVICES		2

struct css2600_mmu_pdata {
	void __iomem *base[CSS2600_MMU_MAX_DEVICES];
	unsigned int nr_base;
};

struct css2600_isys_csi2_pdata {
	void __iomem *base;
};

#define CSS2600_ISYS_TYPE_CSS2401	2401
#define CSS2600_ISYS_TYPE_CSS2600	2600

struct css2600_isys_pdata {
	void __iomem *base;
	unsigned int type;
};

struct css2600_psys_pdata {
	void __iomem *base;
};

struct css2600_buttress_pdata {
	void __iomem *base;
};

#endif
