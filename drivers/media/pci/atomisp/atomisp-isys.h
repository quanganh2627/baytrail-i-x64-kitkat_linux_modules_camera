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

#ifndef ATOMISP_ISYS_H
#define ATOMISP_ISYS_H

#include <media/media-device.h>
#include <media/v4l2-device.h>

#include "atomisp.h"
#include "atomisp-pdata.h"
#include "atomisp-csi2.h"

#define MAX_CSI2_PORTS			4

struct atomisp_isys {
	struct media_device media_dev;
	struct v4l2_device v4l2_dev;
	struct atomisp_bus_device *adev;

	struct atomisp_isys_pdata *pdata;

	struct atomisp_csi2 csi2[MAX_CSI2_PORTS];
};

#endif /* ATOMISP_ISYS_H */
