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

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/fs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-psys.h"

#define CSS2600_PSYS_NUM_DEVICES	4

static dev_t css2600_psys_dev_t;
static DECLARE_BITMAP(css2600_psys_devices, CSS2600_PSYS_NUM_DEVICES);
static DEFINE_MUTEX(css2600_psys_mutex);

static int css2600_psys_open(struct inode *inode, struct file *file)
{
	struct css2600_psys *psys = inode_to_css2600_psys(inode);
	struct css2600_psys_fh *fh;

	fh = kzalloc(sizeof(*fh), GFP_KERNEL);
	if (!fh)
		return -ENOMEM;

	file->private_data = fh;

	mutex_lock(&psys->mutex);
	list_add(&fh->list, &psys->fhs);
	mutex_unlock(&psys->mutex);

	return 0;
}

static int css2600_psys_release(struct inode *inode, struct file *file)
{
	struct css2600_psys *psys = inode_to_css2600_psys(inode);
	struct css2600_psys_fh *fh = file->private_data;

	mutex_lock(&psys->mutex);
	list_del(&fh->list);
	mutex_unlock(&psys->mutex);

	kfree(fh);

	return 0;
}

static const struct file_operations css2600_psys_fops = {
	.open = css2600_psys_open,
	.release = css2600_psys_release,
	.owner = THIS_MODULE,
};

void css2600_psys_dev_release(struct device *dev)
{
}

static int css2600_psys_probe(struct css2600_bus_device *adev)
{
	struct css2600_psys *psys;
	unsigned int minor;
	int rval = -E2BIG;

	mutex_lock(&css2600_psys_mutex);

	minor = find_next_zero_bit(css2600_psys_devices,
				   CSS2600_PSYS_NUM_DEVICES, 0);
	if (minor == CSS2600_PSYS_NUM_DEVICES) {
		dev_err(&adev->dev, "too many devices\n");
		goto out_unlock;
	}

	psys = devm_kzalloc(&adev->dev, sizeof(*psys), GFP_KERNEL);
	if (!psys) {
		rval = -ENOMEM;
		goto out_unlock;
	}

	cdev_init(&psys->cdev, &css2600_psys_fops);
	psys->cdev.owner = css2600_psys_fops.owner;

	rval = cdev_add(&psys->cdev,
			MKDEV(MAJOR(css2600_psys_dev_t), minor), 1);
	if (rval) {
		dev_err(&adev->dev, "cdev_add failed (%d)\n", rval);
		goto out_unlock;
	}

	mutex_init(&psys->mutex);
	INIT_LIST_HEAD(&psys->fhs);

	css2600_bus_set_drvdata(adev, psys);

	psys->dev.parent = &adev->dev;
	psys->dev.devt = MKDEV(MAJOR(css2600_psys_dev_t), minor);
	psys->dev.release = css2600_psys_dev_release;
	dev_set_name(&psys->dev, "psys" "%d", minor);
	rval = device_register(&psys->dev);
	if (rval < 0) {
		dev_err(&psys->dev, "psys device_register failed\n");
		goto out_mutex_destroy;
	}

	set_bit(minor, css2600_psys_devices);

	dev_info(&adev->dev, "psys probe minor: %d\n", minor);

	mutex_unlock(&css2600_psys_mutex);

	return 0;

out_mutex_destroy:
	mutex_destroy(&psys->mutex);

out_unlock:
	mutex_unlock(&css2600_psys_mutex);

	return rval;
}

static void css2600_psys_remove(struct css2600_bus_device *adev)
{
	struct css2600_psys *psys = css2600_bus_get_drvdata(adev);

	mutex_lock(&css2600_psys_mutex);

	device_unregister(&psys->dev);

	clear_bit(MINOR(psys->cdev.dev), css2600_psys_devices);
	cdev_del(&psys->cdev);

	mutex_unlock(&css2600_psys_mutex);

	mutex_destroy(&psys->mutex);

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

static int __init css2600_psys_init(void)
{
	int rval = alloc_chrdev_region(&css2600_psys_dev_t, 0,
				   CSS2600_PSYS_NUM_DEVICES, CSS2600_PSYS_NAME);
	if (rval) {
		pr_err("can't alloc css2600 psys chrdev region (%d)\n", rval);
		return rval;
	}

	css2600_bus_register_driver(&css2600_psys_driver);

	return rval;
}

static void __exit css2600_psys_exit(void)
{
	css2600_bus_unregister_driver(&css2600_psys_driver);
	unregister_chrdev_region(css2600_psys_dev_t, CSS2600_PSYS_NUM_DEVICES);
}

module_init(css2600_psys_init);
module_exit(css2600_psys_exit);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel css2600 processing system driver");
