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

#ifndef ATOMISP_CSI2_H
#define ATOMISP_CSI2_H

struct atomisp_csi2_pdata;
struct atomisp_isys;

struct atomisp_csi2 {
	struct atomisp_csi2_pdata *pdata;
	struct atomisp_isys *isys;
	struct v4l2_subdev sd;

	void __iomem *base;
	unsigned int nlanes;
};

int atomisp_csi2_init(struct atomisp_csi2 *csi2, struct atomisp_isys *isys,
		      void __iomem *base, unsigned int lanes);
void atomisp_csi2_cleanup(struct atomisp_csi2 *csi2);
void atomisp_csi2_isr(struct atomisp_csi2 *csi2);

#endif
