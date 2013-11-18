/*
 * Copyright (c) 2013 Intel Corporation. All Rights Reserved.
 *
 * Bus implementation based on the bt8xx driver.
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

#include <linux/delay.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/iommu.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/pci.h>

#include "atomisp.h"
#include "atomisp-dma.h"

static int atomisp_bus_match(struct device *dev, struct device_driver *drv)
{
	struct atomisp_bus_driver *adrv = to_atomisp_bus_driver(drv);

	dev_info(dev, "bus match: \"%s\" --- \"%s\"\n", dev_name(dev),
		 adrv->wanted);

	return !strncmp(dev_name(dev), adrv->wanted, strlen(adrv->wanted));
}

static int atomisp_bus_probe(struct device *dev)
{
	struct atomisp_bus_device *adev = to_atomisp_bus_device(dev);
	struct atomisp_bus_driver *adrv = to_atomisp_bus_driver(dev->driver);
	int rval;

	adev->adrv = adrv;
	rval = adrv->probe ? adrv->probe(adev) : -ENODEV;

	if (rval) {
		atomisp_bus_set_drvdata(adev, NULL);
		adev->adrv = NULL;
	}

	return rval;
}

static int atomisp_bus_remove(struct device *dev)
{
	struct atomisp_bus_device *adev = to_atomisp_bus_device(dev);
	struct atomisp_bus_driver *adrv = to_atomisp_bus_driver(dev->driver);

	if (adrv->remove)
		adrv->remove(adev);

	return 0;
}

static struct bus_type atomisp_bus = {
	.name = ATOMISP_BUS_NAME,
	.match = atomisp_bus_match,
	.probe = atomisp_bus_probe,
	.remove = atomisp_bus_remove,
};

struct mutex atomisp_bus_mutex;

static void atomisp_bus_release(struct device *dev)
{
	struct atomisp_bus_device *adev = to_atomisp_bus_device(dev);

	kfree(adev);
}

struct device *atomisp_bus_add_device(struct pci_dev *pdev, void *pdata,
				      void *iommu, char *name, unsigned int nr)
{
	struct atomisp_bus_device *adev;
	struct atomisp_device *isp = pci_get_drvdata(pdev);
	int rval;

	adev = kzalloc(sizeof(*adev), GFP_KERNEL);
	if (!adev)
		return ERR_PTR(-ENOMEM);

	adev->dev.parent = &pdev->dev;
	adev->dev.bus = &atomisp_bus;
	adev->dev.release = atomisp_bus_release;
	adev->dev.archdata.iommu = iommu;
	adev->dev.archdata.dma_ops = &atomisp_dma_ops;
	adev->pdata = pdata;
	dev_set_name(&adev->dev, "%s%d", name, nr);

	rval = device_register(&adev->dev);
	if (rval) {
		put_device(&adev->dev);
		return ERR_PTR(rval);
	}

	mutex_lock(&atomisp_bus_mutex);
	list_add(&adev->list, &isp->devices);
	mutex_unlock(&atomisp_bus_mutex);

	return &adev->dev;
}

void atomisp_bus_del_devices(struct pci_dev *pdev)
{
	struct atomisp_device *isp = pci_get_drvdata(pdev);
	struct atomisp_bus_device *adev, *save;

	mutex_lock(&atomisp_bus_mutex);

	list_for_each_entry_safe(adev, save, &isp->devices, list) {
		list_del(&adev->list);
		device_unregister(&adev->dev);
	}

	mutex_unlock(&atomisp_bus_mutex);
}

int atomisp_bus_register_driver(struct atomisp_bus_driver *adrv)
{
	adrv->drv.bus = &atomisp_bus;
	return driver_register(&adrv->drv);
}
EXPORT_SYMBOL(atomisp_bus_register_driver);

int atomisp_bus_unregister_driver(struct atomisp_bus_driver *adrv)
{
	driver_unregister(&adrv->drv);
	return 0;
}
EXPORT_SYMBOL(atomisp_bus_unregister_driver);

int atomisp_bus_register(void)
{
	mutex_init(&atomisp_bus_mutex);
	return bus_register(&atomisp_bus);
}
EXPORT_SYMBOL(atomisp_bus_register);

void atomisp_bus_unregister(void)
{
	mutex_destroy(&atomisp_bus_mutex);
	return bus_unregister(&atomisp_bus);
}
EXPORT_SYMBOL(atomisp_bus_unregister);

void atomisp_bus_set_iommu(struct iommu_ops *ops)
{
	bus_set_iommu(&atomisp_bus, ops);
}
EXPORT_SYMBOL(atomisp_bus_set_iommu);
