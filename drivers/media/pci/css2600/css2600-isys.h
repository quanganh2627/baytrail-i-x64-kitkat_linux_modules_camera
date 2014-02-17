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

#ifndef CSS2600_ISYS_H
#define CSS2600_ISYS_H

#include <media/v4l2-device.h>
#include <media/media-device.h>

#include "css2600.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-tpg.h"
#include "css2600-pdata.h"

#define CSS2600_ISYS_MAX_CSI2_PORTS		4
#define CSS2600_ISYS_MAX_TPGS			CSS2600_ISYS_MAX_CSI2_PORTS

struct css2600_isys {
	struct media_device media_dev;
	struct v4l2_device v4l2_dev;
	struct css2600_bus_device *adev;

	struct css2600_isys_pdata *pdata;

	struct css2600_isys_csi2 csi2[CSS2600_ISYS_MAX_CSI2_PORTS];
	/* 2401 has a test pattern generator per port */
	struct css2600_isys_tpg tpg[CSS2600_ISYS_MAX_TPGS];
};

extern const struct v4l2_ioctl_ops css2600_isys_ioctl_ops;

int css2600_pipeline_pm_use(struct media_entity *entity, int use);

#endif /* CSS2600_ISYS_H */
