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

#ifndef ATOMISP_BUS_H
#define ATOMISP_BUS_H

#include <linux/device.h>
#include <linux/list.h>
#include <linux/mm.h>
#include <linux/pci.h>

#define ATOMISP_BUS_NAME	ATOMISP_NAME "-bus"

struct iommu_domain;

struct atomisp_bus_device {
	struct device dev;
	struct list_head list;
	void *pdata;
	struct atomisp_bus_driver *adrv;
};

#define to_atomisp_bus_device(_dev) \
	container_of(_dev, struct atomisp_bus_device, dev)

struct atomisp_bus_driver {
	struct device_driver	drv;
	char			wanted[20];
	int			(*probe)(struct atomisp_bus_device *adev);
	void			(*remove)(struct atomisp_bus_device *adev);
	void			(*isr)(struct atomisp_bus_device *adev);
};


#define to_atomisp_bus_driver(_drv) \
	container_of(_drv, struct atomisp_bus_driver, drv)

struct atomisp_bus_device *atomisp_bus_add_device(
	struct pci_dev *pdev, void *iommu, void *pdata, char *name,
	unsigned int nr);
void atomisp_bus_del_devices(struct pci_dev *pdev);

int atomisp_bus_register_driver(struct atomisp_bus_driver *adrv);
int atomisp_bus_unregister_driver(struct atomisp_bus_driver *adrv);

int atomisp_bus_register(void);
void atomisp_bus_unregister(void);

void atomisp_bus_set_iommu(struct iommu_ops *ops);

#define module_atomisp_bus_driver(drv)			\
	module_driver(drv, atomisp_bus_register_driver, \
		      atomisp_bus_unregister_driver)

#define atomisp_bus_set_drvdata(adev, data) dev_set_drvdata(&(adev)->dev, data)
#define atomisp_bus_get_drvdata(adev) dev_get_drvdata(&(adev)->dev)

#endif
