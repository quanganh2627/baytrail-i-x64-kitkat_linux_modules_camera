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
#include "atomisp-isys.h"

static int atomisp_isys_probe(struct atomisp_bus_device *adev)
{
	struct atomisp_isys_device *isys;

	isys = devm_kzalloc(&adev->dev, sizeof(*isys), GFP_KERNEL);
	if (!isys)
		return -ENOMEM;

	dev_info(&adev->dev, "isys probe %p %p\n", adev, &adev->dev);
	atomisp_bus_set_drvdata(adev, isys);

	return 0;
}

static void atomisp_isys_remove(struct atomisp_bus_device *adev)
{
	struct atomisp_isys_device *isys = atomisp_bus_get_drvdata(adev);

	dev_info(&adev->dev, "removed\n");
}

static void atomisp_isys_isr(struct atomisp_bus_device *adev)
{
	struct atomisp_isys_device *isys = atomisp_bus_get_drvdata(adev);

	dev_info(&adev->dev, "Yeah!\n");
}

static struct atomisp_bus_driver atomisp_isys_driver = {
	.probe = atomisp_isys_probe,
	.remove = atomisp_isys_remove,
	.isr = atomisp_isys_isr,
	.wanted = ATOMISP_ISYS_NAME,
	.drv = {
		.name = ATOMISP_ISYS_NAME,
		.owner = THIS_MODULE,
	},
};

module_atomisp_bus_driver(atomisp_isys_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
