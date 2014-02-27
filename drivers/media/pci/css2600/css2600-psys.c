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
 */

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-psys.h"

static int css2600_psys_probe(struct css2600_bus_device *adev)
{
	struct css2600_psys *psys;

	psys = devm_kzalloc(&adev->dev, sizeof(*psys), GFP_KERNEL);
	if (!psys)
		return -ENOMEM;

	dev_info(&adev->dev, "psys probe %p %p\n", adev, &adev->dev);
	css2600_bus_set_drvdata(adev, psys);

	return 0;
}

static void css2600_psys_remove(struct css2600_bus_device *adev)
{
	dev_info(&adev->dev, "removed\n");
}

static struct css2600_bus_driver css2600_psys_driver = {
	.probe = css2600_psys_probe,
	.remove = css2600_psys_remove,
	.wanted = CSS2600_PSYS_NAME,
	.drv = {
		.name = CSS2600_PSYS_NAME,
		.owner = THIS_MODULE,
	},
};

module_css2600_bus_driver(css2600_psys_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel css2600 processing system driver");
