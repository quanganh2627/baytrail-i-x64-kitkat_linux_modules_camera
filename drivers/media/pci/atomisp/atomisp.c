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
#include <linux/interrupt.h>
#include <linux/pci.h>
#include <linux/module.h>
#include <linux/pm_qos.h>
#include <linux/pm_runtime.h>
#include <linux/timer.h>

#include "atomisp.h"
#include "atomisp-pdata.h"
#include "atomisp-bus.h"
#include "atomisp-regs.h"

#define ATOMISP_PCI_BAR		0

static struct atomisp_bus_device *atomisp_mmu_init(
	struct pci_dev *pdev, void __iomem *base[], unsigned int nr_base,
	unsigned int nr)
{
	struct atomisp_mmu_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	unsigned int i;

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	BUG_ON(nr_base > ATOMISP_MMU_MAX_DEVICES);

	for (i = 0; i < nr_base; i++)
		pdata->base[i] = base[i];

	pdata->nr_base = nr_base;

	return atomisp_bus_add_device(pdev, pdata, NULL, ATOMISP_MMU_NAME, nr);
}

static struct atomisp_bus_device *atomisp_isys_init(
	struct pci_dev *pdev, void *iommu, void __iomem *base, unsigned int nr)
{
	struct atomisp_isys_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	pdata->base = base;

	return atomisp_bus_add_device(pdev, pdata, iommu, ATOMISP_ISYS_NAME,
				      nr);
}

static inline void atomisp_call_isr(struct atomisp_bus_device *adev)
{
	if (!adev || !adev->adrv || !adev->adrv->isr)
		return;

	adev->adrv->isr(adev);
}

static irqreturn_t atomisp_isr(int irq, void *priv)
{
	struct atomisp_device *isp = priv;

	switch (isp->pdev->device) {
	case ATOMISP_HW_BXT_PSS_1:
		atomisp_call_isr(isp->isys);
		break;
	}

	return IRQ_HANDLED;
}

static int atomisp_pci_probe(struct pci_dev *pdev,
			     const struct pci_device_id *id)
{
	struct atomisp_device *isp;
	phys_addr_t phys;
	void __iomem *base;
	void __iomem *mmu_base[ATOMISP_MMU_MAX_DEVICES];
	int rval;

	rval = pcim_enable_device(pdev);
	if (rval) {
		dev_err(&pdev->dev, "Failed to enable CI ISP device (%d)\n",
			rval);
		return rval;
	}

	phys = pci_resource_start(pdev, ATOMISP_PCI_BAR);

	rval = pcim_iomap_regions(pdev, 1 << ATOMISP_PCI_BAR, pci_name(pdev));
	if (rval) {
		dev_err(&pdev->dev, "Failed to I/O memory remapping (%d)\n",
			rval);
		return rval;
	}
	dev_info(&pdev->dev, "physical base address 0x%llx\n", phys);

	base = pcim_iomap_table(pdev)[ATOMISP_PCI_BAR];
	dev_info(&pdev->dev, "mapped as: 0x%p\n", base);

	isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
	if (!isp) {
		dev_err(&pdev->dev, "Failed to alloc CI ISP structure\n");
		return -ENOMEM;
	}
	isp->pdev = pdev;
	INIT_LIST_HEAD(&isp->devices);
	pci_set_drvdata(pdev, isp);

	mmu_base[0] = base + ATOMISP_BXT_A0_ISYS_IOMMU0_OFFSET;
	mmu_base[1] = base + ATOMISP_BXT_A0_ISYS_IOMMU1_OFFSET;
	isp->iommu = atomisp_mmu_init(pdev, mmu_base, 2, 0);
	rval = PTR_ERR(isp->iommu);
	if (IS_ERR(isp->iommu)) {
		dev_err(&pdev->dev, "can't create iommu device\n");
		return -ENOMEM;
	}

	pr_info("mmu %p\n", isp->iommu);
	pr_info("a %p\n", isp->iommu->dev.archdata.iommu);

	isp->isys = atomisp_isys_init(pdev, &isp->iommu->dev, base, 0);
	rval = PTR_ERR(isp->isys);
	if (IS_ERR(isp->isys))
		goto out_atomisp_bus_del_devices;

	pci_set_master(pdev);

	switch (isp->pdev->device) {
	case ATOMISP_HW_BXT_PSS_1:
		break;
	default:
		rval = pci_enable_msi(pdev);
		if (rval) {
			dev_err(&pdev->dev, "Failed to enable msi (%d)\n", rval);
			goto out_atomisp_bus_del_devices;
		}
	}

	rval = devm_request_irq(&pdev->dev, pdev->irq, atomisp_isr, IRQF_SHARED,
				ATOMISP_NAME, isp);
	if (rval) {
		dev_err(&pdev->dev, "Failed to request irq (%d)\n", rval);
		goto out_atomisp_bus_del_devices;
	}

	pm_runtime_put_noidle(&pdev->dev);
	pm_runtime_allow(&pdev->dev);

	return 0;

out_atomisp_bus_del_devices:
	atomisp_bus_del_devices(pdev);

	return rval;
}

static void atomisp_pci_remove(struct pci_dev *pdev)
{
	atomisp_bus_del_devices(pdev);

	pm_runtime_forbid(&pdev->dev);
	pm_runtime_get_noresume(&pdev->dev);
}

static DEFINE_PCI_DEVICE_TABLE(atomisp_pci_tbl) = {
	{PCI_DEVICE(PCI_VENDOR_ID_INTEL, ATOMISP_HW_BXT_PSS_1)},
	{0,}
};

MODULE_DEVICE_TABLE(pci, atomisp_pci_tbl);

static struct pci_driver atomisp_pci_driver = {
	.driver = {
#ifdef CONFIG_PM
		.pm = &(const struct dev_pm_ops){},
#endif /* CONFIG_PM */
	},
	.name = ATOMISP_NAME,
	.id_table = atomisp_pci_tbl,
	.probe = atomisp_pci_probe,
	.remove = atomisp_pci_remove,
};

static int __init atomisp_init(void)
{
	int rval = atomisp_bus_register();
	if (rval) {
		pr_warn("can't register atomisp bus (%d)\n", rval);
		return rval;
	}

	rval = pci_register_driver(&atomisp_pci_driver);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_pci_register_driver;
	}

	return 0;

out_pci_register_driver:
	atomisp_bus_unregister();

	return rval;
}

static void __exit atomisp_exit(void)
{
	pci_unregister_driver(&atomisp_pci_driver);
	atomisp_bus_unregister();
}

module_init(atomisp_init);
module_exit(atomisp_exit);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
