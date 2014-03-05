/*
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
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

#ifndef CSS2600_REGS_H
#define CSS2600_REGS_H

/* Broxton A0 offsets */

#define CSS2600_MRFLD_DATA_IOMMU_OFFSET			0x00070000
#define CSS2600_MRFLD_ICACHE_IOMMU_OFFSET		0x000a0000

#define CSS2600_BXT_A0_ISYS_IOMMU0_OFFSET		0x000e0000
#define CSS2600_BXT_A0_ISYS_IOMMU1_OFFSET		0x000e0100

#define CSS2600_BXT_A0_PSYS_IOMMU0_OFFSET		0x003c0000
#define CSS2600_BXT_A0_PSYS_IOMMU1_OFFSET		0x003c0100

#define CSS2401_PUNIT_PORT				0x04
#define CSS2401_REG_ISPSSPM0				0x39
#define CSS2401_REG_ISPSSPM0_ISPSSS_SHIFT		24
#define CSS2401_REG_ISPSSPM0_ISPSSC_MASK		0x3
#define CSS2401_REG_ISPSSPM0_IUNIT_POWER_ON		0
#define CSS2401_REG_ISPSSPM0_IUNIT_POWER_OFF		3
#define CSS2401_REG_ISPSSPM0_IUNIT_POWER_MASK		0x3

/* PCI config space registers for 2401 */
#define CSS2401_REG_PCI_MSI_CAPID			0x90
#define CSS2401_PCI_MSI_CAPID_MSI_ENABLE_BIT		16
#define CSS2401_REG_PCI_INTERRUPT_CTRL			0x9c
#define CSS2401_PCI_INTERRUPT_CTRL_INTR_IER		24
#define CSS2401_PCI_INTERRUPT_CTRL_INTR_IIR		16

#endif /* CSS2600_REGS_H */
