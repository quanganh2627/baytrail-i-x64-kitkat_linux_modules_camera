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

#include "atomisp.h"
#include "atomisp-bus.h"
#include "atomisp-csi2.h"

static int atomisp_csi2_probe(struct atomisp_bus_device *adev)
{
	struct atomisp_csi2_device *csi2;
	int rval;

	csi2 = devm_kzalloc(&adev->dev, sizeof(*csi2), GFP_KERNEL);
	if (!csi2)
		return -ENOMEM;

	sg_set_page(&csi2->sg, alloc_page(GFP_KERNEL), PAGE_SIZE, 0);
	if (!sg_page(&csi2->sg))
		return -ENOMEM;

	dev_info(&adev->dev, "csi2 probe %p %p\n", adev, &adev->dev);
	atomisp_bus_set_drvdata(adev, csi2);

	sg_mark_end(&csi2->sg);

	rval = dma_map_sg(&adev->dev, &csi2->sg, 1, DMA_FROM_DEVICE);
	if (rval)
		goto out_dma_map_sg;

	return 0;

out_dma_map_sg:
	__free_page(sg_page(&csi2->sg));

	return rval;
}

static void atomisp_csi2_remove(struct atomisp_bus_device *adev)
{
	struct atomisp_csi2_device *csi2 = atomisp_bus_get_drvdata(adev);

	dma_unmap_sg(&adev->dev, &csi2->sg, 1, DMA_FROM_DEVICE);

	__free_page(sg_page(&csi2->sg));
	dev_info(&adev->dev, "removed\n");
}

static struct atomisp_bus_driver atomisp_csi2_driver = {
	.probe = atomisp_csi2_probe,
	.remove = atomisp_csi2_remove,
	.wanted = ATOMISP_CSI2_NAME,
	.drv = {
		.name = ATOMISP_CSI2_NAME,
		.owner = THIS_MODULE,
	},
};

module_atomisp_bus_driver(atomisp_csi2_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
