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

#include "css2600.h"
#include "css2600-pdata.h"
#include "css2600-bus.h"
#include "css2600-regs.h"

#define CSS2600_PCI_BAR		0

struct css2600_dma_mapping;

static struct css2600_bus_device *css2600_mmu_init(
	struct pci_dev *pdev, struct device *parent, void __iomem *base[],
	unsigned int nr_base, unsigned int nr)
{
	struct css2600_mmu_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	unsigned int i;

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	BUG_ON(nr_base > CSS2600_MMU_MAX_DEVICES);

	for (i = 0; i < nr_base; i++)
		pdata->base[i] = base[i];

	pdata->nr_base = nr_base;

	return css2600_bus_add_device(pdev, parent, pdata, NULL,
				      CSS2600_MMU_NAME, nr);
}

static struct css2600_bus_device *css2600_isys_init(
	struct pci_dev *pdev, struct device *parent,
	struct css2600_bus_iommu *iommu, void __iomem *base,
	unsigned int nr, unsigned int type)
{
	struct css2600_isys_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	pdata->base = base;
	pdata->type = type;

	return css2600_bus_add_device(pdev, parent, pdata, iommu,
				      CSS2600_ISYS_NAME, nr);
}

static struct css2600_bus_device *css2600_psys_init(
	struct pci_dev *pdev, struct device *parent,
	struct css2600_bus_iommu *iommu, void __iomem *base,
	unsigned int nr)
{
	struct css2600_psys_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	pdata->base = base;

	return css2600_bus_add_device(pdev, parent, pdata, iommu,
				      CSS2600_PSYS_NAME, nr);
}

static struct css2600_bus_device *css2600_buttress_init(
	struct pci_dev *pdev, struct device *parent,
	void __iomem *base, unsigned int nr)
{
	struct css2600_buttress_pdata *pdata =
		devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);

	if (!pdata)
		return ERR_PTR(-ENOMEM);

	pdata->base = base;

	return css2600_bus_add_device(pdev, parent, pdata, NULL,
				      CSS2600_BUTTRESS_NAME, nr);
}

static inline void css2600_call_isr(struct css2600_bus_device *adev)
{
	if (!adev || !adev->adrv || !adev->adrv->isr)
		return;

	adev->adrv->isr(adev);
}

static irqreturn_t css2600_isr(int irq, void *priv)
{
	struct css2600_device *isp = priv;

	if (isp->pdev->device == CSS2600_HW_BXT_FPGA
	    && IS_ENABLED(VIDEO_CSS2600_ISYS))
		css2600_call_isr(isp->isys);

	return IRQ_HANDLED;
}

static int css2600_pci_probe(struct pci_dev *pdev,
			     const struct pci_device_id *id)
{
	struct css2600_device *isp;
	phys_addr_t phys;
	void __iomem *base;
	void __iomem *mmu_base[CSS2600_MMU_MAX_DEVICES];
	struct css2600_bus_iommu *isys_iommu, *psys_iommu;
	int rval;

	isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
	if (!isp) {
		dev_err(&pdev->dev, "Failed to alloc CI ISP structure\n");
		return -ENOMEM;
	}
	isp->pdev = pdev;
	INIT_LIST_HEAD(&isp->devices);

	isys_iommu = devm_kzalloc(&pdev->dev, sizeof(*isys_iommu), GFP_KERNEL);
	psys_iommu = devm_kzalloc(&pdev->dev, sizeof(*psys_iommu), GFP_KERNEL);
	if (!isys_iommu || !psys_iommu) {
		dev_err(&pdev->dev, "Can't allocate memory for iommu\n");
		return -ENOMEM;
	}

	/* Share IOMMU mapping between isys and psys */
	isys_iommu->m = psys_iommu->m = devm_kzalloc(
		&pdev->dev, sizeof(*isys_iommu->m), GFP_KERNEL);
	if (!isys_iommu->m) {
		dev_err(&pdev->dev,
			"Can't allocate memory for iommu mapping\n");
		return -ENOMEM;
	}

	rval = pcim_enable_device(pdev);
	if (rval) {
		dev_err(&pdev->dev, "Failed to enable CI ISP device (%d)\n",
			rval);
		return rval;
	}

	phys = pci_resource_start(pdev, CSS2600_PCI_BAR);

	rval = pcim_iomap_regions(pdev, 1 << CSS2600_PCI_BAR, pci_name(pdev));
	if (rval) {
		dev_err(&pdev->dev, "Failed to I/O memory remapping (%d)\n",
			rval);
		return rval;
	}
	dev_info(&pdev->dev, "physical base address 0x%llx\n", phys);

	base = pcim_iomap_table(pdev)[CSS2600_PCI_BAR];
	dev_info(&pdev->dev, "mapped as: 0x%p\n", base);

	pci_set_drvdata(pdev, isp);

	if (pdev->device == CSS2600_HW_BXT) {
		isp->buttress = css2600_buttress_init(pdev, &pdev->dev, base, 0);
		rval = PTR_ERR(isp->buttress);
		if (IS_ERR(isp->buttress))
			goto out_css2600_bus_del_devices;
	}
	if (pdev->device == CSS2600_HW_BXT
	    || (pdev->device == CSS2600_HW_BXT_FPGA
		&& IS_ENABLED(CONFIG_VIDEO_CSS2600_ISYS))) {
		mmu_base[0] = base + CSS2600_BXT_A0_ISYS_IOMMU0_OFFSET;
		mmu_base[1] = base + CSS2600_BXT_A0_ISYS_IOMMU1_OFFSET;
		isp->isys_iommu = css2600_mmu_init(pdev, &isp->buttress->dev, mmu_base, 2, 0);
		rval = PTR_ERR(isp->isys_iommu);
		if (IS_ERR(isp->isys_iommu)) {
			dev_err(&pdev->dev, "can't create isys iommu device\n");
			return -ENOMEM;
		}

		isys_iommu->dev = &isp->isys_iommu->dev;

		isp->isys = css2600_isys_init(pdev, &isp->buttress->dev, isys_iommu, base,
					      0, CSS2600_ISYS_TYPE_CSS2600);
		rval = PTR_ERR(isp->isys);
		if (IS_ERR(isp->isys))
			goto out_css2600_bus_del_devices;
	}

	if (pdev->device == CSS2600_HW_BXT
	    || (pdev->device == CSS2600_HW_BXT_FPGA
		&& IS_ENABLED(CONFIG_VIDEO_CSS2600_PSYS))) {
		mmu_base[0] = base + CSS2600_BXT_A0_PSYS_IOMMU0_OFFSET;
		mmu_base[1] = base + CSS2600_BXT_A0_PSYS_IOMMU1_OFFSET;
		isp->psys_iommu = css2600_mmu_init(pdev, &isp->isys->dev, mmu_base, 2, 1);
		rval = PTR_ERR(isp->psys_iommu);
		if (IS_ERR(isp->psys_iommu)) {
			dev_err(&pdev->dev, "can't create psys iommu device\n");
			goto out_css2600_bus_del_devices;
		}

		psys_iommu->dev = &isp->psys_iommu->dev;
		isp->psys = css2600_psys_init(pdev, &isp->buttress->dev, psys_iommu, base, 0);
		rval = PTR_ERR(isp->isys);
		if (IS_ERR(isp->isys))
			goto out_css2600_bus_del_devices;
	}

	if (pdev->device == CSS2600_HW_MRFLD_2401) {
		mmu_base[0] = base + CSS2600_MRFLD_DATA_IOMMU_OFFSET;
		mmu_base[1] = base + CSS2600_MRFLD_ICACHE_IOMMU_OFFSET;
		isp->isys_iommu = css2600_mmu_init(pdev, &pdev->dev, mmu_base, 2, 0);
		rval = PTR_ERR(isp->isys_iommu);
		if (IS_ERR(isp->isys_iommu)) {
			dev_err(&pdev->dev, "can't create iommu device\n");
			goto out_css2600_bus_del_devices;
		}
		isys_iommu->dev = &isp->isys_iommu->dev;
		isp->isys = css2600_isys_init(pdev, &pdev->dev, isys_iommu, base, 0,
					      CSS2600_ISYS_TYPE_CSS2401);
		rval = PTR_ERR(isp->isys);
		if (rval < 0)
			goto out_css2600_bus_del_devices;
		isp->psys = css2600_psys_init(pdev, &pdev->dev, isys_iommu, base, 0);
		rval = PTR_ERR(isp->psys);
		if (rval < 0)
			goto out_css2600_bus_del_devices;
	}

	pci_set_master(pdev);

	if (isp->pdev->device != CSS2600_HW_BXT_FPGA) {
		rval = pci_enable_msi(pdev);
		if (rval) {
			dev_err(&pdev->dev, "Failed to enable msi (%d)\n",
				rval);
			goto out_css2600_bus_del_devices;
		}
	}

	rval = devm_request_irq(&pdev->dev, pdev->irq, css2600_isr, IRQF_SHARED,
				CSS2600_NAME, isp);
	if (rval) {
		dev_err(&pdev->dev, "Failed to request irq (%d)\n", rval);
		goto out_css2600_bus_del_devices;
	}

	pm_runtime_put_noidle(&pdev->dev);
	pm_runtime_allow(&pdev->dev);

	return 0;

out_css2600_bus_del_devices:
	css2600_bus_del_devices(pdev);

	return rval;
}

static void css2600_pci_remove(struct pci_dev *pdev)
{
	css2600_bus_del_devices(pdev);

	pm_runtime_forbid(&pdev->dev);
	pm_runtime_get_noresume(&pdev->dev);
}

static DEFINE_PCI_DEVICE_TABLE(css2600_pci_tbl) = {
	{PCI_DEVICE(PCI_VENDOR_ID_INTEL, CSS2600_HW_BXT_FPGA)},
	{PCI_DEVICE(PCI_VENDOR_ID_INTEL, CSS2600_HW_MRFLD_2401)},
	{0,}
};

MODULE_DEVICE_TABLE(pci, css2600_pci_tbl);

static struct pci_driver css2600_pci_driver = {
	.driver = {
#ifdef CONFIG_PM
		.pm = &(const struct dev_pm_ops){},
#endif /* CONFIG_PM */
	},
	.name = CSS2600_NAME,
	.id_table = css2600_pci_tbl,
	.probe = css2600_pci_probe,
	.remove = css2600_pci_remove,
};

static int __init css2600_init(void)
{
	int rval = css2600_bus_register();
	if (rval) {
		pr_warn("can't register css2600 bus (%d)\n", rval);
		return rval;
	}

	rval = pci_register_driver(&css2600_pci_driver);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_pci_register_driver;
	}

	return 0;

out_pci_register_driver:
	css2600_bus_unregister();

	return rval;
}

static void __exit css2600_exit(void)
{
	pci_unregister_driver(&css2600_pci_driver);
	css2600_bus_unregister();
}

module_init(css2600_init);
module_exit(css2600_exit);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
