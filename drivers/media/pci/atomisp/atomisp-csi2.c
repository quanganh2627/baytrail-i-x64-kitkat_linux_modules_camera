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

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include <media/v4l2-device.h>

#include "atomisp.h"
#include "atomisp-bus.h"
#include "atomisp-isys.h"
#include "atomisp-csi2.h"

int atomisp_csi2_init(struct atomisp_csi2 *csi2, struct atomisp_isys *isys,
		      void __iomem *base, unsigned int nlanes)
{
	csi2->isys = isys;
	csi2->base = base;
	csi2->nlanes = nlanes;

	return v4l2_device_register_subdev(&isys->v4l2_dev, &csi2->sd);
}

void atomisp_csi2_cleanup(struct atomisp_csi2 *csi2)
{
	v4l2_device_unregister_subdev(&csi2->sd);
}

void atomisp_csi2_isr(struct atomisp_csi2 *csi2)
{
}
