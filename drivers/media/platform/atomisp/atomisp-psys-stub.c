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

#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>

#include "atomisp-psys-stub.h"

#define ATOMISP_NUM_DEVICES	4

static dev_t atomisp_dev_t;
static DECLARE_BITMAP(atomisp_devices, ATOMISP_NUM_DEVICES);
static DEFINE_MUTEX(atomisp_devices_mutex);

static struct bus_type atomisp_psys_bus = {
	.name = ATOMISP_PSYS_STUB_NAME,
};

static int atomisp_open(struct inode *inode, struct file *file)
{
	struct atomisp_device *isp = inode_to_atomisp_device(inode);
	struct atomisp_fh *fh;

	fh = kzalloc(sizeof(*fh), GFP_KERNEL);
	if (!fh)
		return -ENOMEM;

	file->private_data = fh;

	mutex_lock(&isp->mutex);
	list_add(&fh->list, &isp->fhs);
	mutex_unlock(&isp->mutex);

	return 0;
}

static int atomisp_release(struct inode *inode, struct file *file)
{
	struct atomisp_device *isp = inode_to_atomisp_device(inode);
	struct atomisp_fh *fh = file->private_data;

	mutex_lock(&isp->mutex);
	list_del(&fh->list);
	mutex_unlock(&isp->mutex);
	kfree(fh);

	return 0;
}

static const struct file_operations atomisp_fops = {
	.open = atomisp_open,
	.release = atomisp_release,
	.owner = THIS_MODULE,
};

static int atomisp_platform_probe(struct platform_device *pdev)
{
	struct atomisp_device *isp;
	unsigned int minor;
	int rval = -E2BIG;

	mutex_lock(&atomisp_devices_mutex);

	minor = find_next_zero_bit(atomisp_devices, ATOMISP_NUM_DEVICES, 0);
	if (minor == ATOMISP_NUM_DEVICES) {
		dev_err(&pdev->dev, "too many devices\n");
		goto out_unlock;
	}

	isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
	if (!isp) {
		dev_err(&pdev->dev, "Failed to alloc CI ISP structure\n");
		rval = -ENOMEM;
		goto out_unlock;
	}

	cdev_init(&isp->cdev, &atomisp_fops);
	isp->cdev.owner = atomisp_fops.owner;

	rval = cdev_add(&isp->cdev, MKDEV(MAJOR(atomisp_dev_t), minor), 1);
	if (rval) {
		dev_err(&pdev->dev, "cdev_add failed (%d)\n", rval);
		goto out_unlock;
	}

	set_bit(minor, atomisp_devices);

	isp->dev.bus = &atomisp_psys_bus;
	isp->dev.devt = MKDEV(MAJOR(atomisp_dev_t), minor);
	dev_set_name(&isp->dev, ATOMISP_PSYS_STUB_NAME "%d", minor);
	rval = device_register(&isp->dev);
	if (rval < 0) {
		dev_err(&isp->dev, "device_register failed\n");
		goto out_unlock;
	}
	
	mutex_unlock(&atomisp_devices_mutex);
	mutex_init(&isp->mutex);
	INIT_LIST_HEAD(&isp->fhs);

	return 0;

out_unlock:
	mutex_unlock(&atomisp_devices_mutex);

	return rval;
}

static int atomisp_platform_remove(struct platform_device *pdev)
{
	struct atomisp_device *isp = platform_get_drvdata(pdev);

	mutex_lock(&atomisp_devices_mutex);

	device_unregister(&isp->dev);

	clear_bit(MINOR(isp->cdev.dev), atomisp_devices);
	cdev_del(&isp->cdev);

	mutex_unlock(&atomisp_devices_mutex);

	mutex_destroy(&isp->mutex);

	return 0;
}

static struct platform_device_id atomisp_psys_id_table[] = {
        { ATOMISP_PSYS_STUB_NAME, 0 },
        { },
};

static struct platform_driver atomisp_platform_driver = {
	.driver = {
#ifdef CONFIG_PM
		.pm = &(const struct dev_pm_ops){},
#endif /* CONFIG_PM */
		.name = ATOMISP_PSYS_STUB_NAME,
		.owner = THIS_MODULE,
	},
	.probe = atomisp_platform_probe,
	.remove = atomisp_platform_remove,
	.id_table = atomisp_psys_id_table,
};

static struct platform_device atomisp_platform_device = {
	.name           = ATOMISP_PSYS_STUB_NAME,
        .id             = -1,
};

static int __init atomisp_init(void)
{
	int rval = alloc_chrdev_region(&atomisp_dev_t, 0, ATOMISP_NUM_DEVICES,
				       ATOMISP_PSYS_STUB_NAME);

	if (rval) {
		pr_warn("can't allocate atomisp chrdev region (%d)\n", rval);
		return rval;
	}

	rval = bus_register(&atomisp_psys_bus);
	if (rval) {
		pr_warn("can't register atomisp bus (%d)\n", rval);
		goto out_bus_register;
	}

	rval = platform_device_register(&atomisp_platform_device);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_platform_device_register;
	}

	rval = platform_driver_register(&atomisp_platform_driver);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_platform_driver_register;
	}

	return 0;

out_platform_driver_register:
	platform_device_unregister(&atomisp_platform_device);

out_platform_device_register:
	bus_unregister(&atomisp_psys_bus);

out_bus_register:
	unregister_chrdev_region(atomisp_dev_t, ATOMISP_NUM_DEVICES);

	return rval;
}

static void __exit atomisp_exit(void)
{
	platform_driver_unregister(&atomisp_platform_driver);
	platform_device_unregister(&atomisp_platform_device);
	bus_unregister(&atomisp_psys_bus);
	unregister_chrdev_region(atomisp_dev_t, ATOMISP_NUM_DEVICES);
}

module_init(atomisp_init);
module_exit(atomisp_exit);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
