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

#ifndef CSS2600_ISYS_H
#define CSS2600_ISYS_H

#include <linux/spinlock.h>

#include <media/v4l2-device.h>
#include <media/media-device.h>

#include "css2600.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-lib.h"
#include "css2600-isys-tpg.h"
#include "css2600-isys-video.h"
#include "css2600-pdata.h"

#define CSS2600_ISYS_2401_MEM_LINE_ALIGN	128

#define CSS2600_ISYS_MAX_CSI2_PORTS		4
/*
 * 2401 has a test pattern generator per port (3) whereas 2600 has two
 * port-independent ones.
 */
#define CSS2600_ISYS_MAX_TPGS			3

/*
 * struct css2600_isys
 *
 * @lock: serialise access to pipes
 * @pipes: pipelines per stream ID
 * @ssi: ssi library private pointer
 * @line_align: line alignment in memory
 */
struct css2600_isys {
	struct media_device media_dev;
	struct v4l2_device v4l2_dev;
	struct css2600_bus_device *adev;
	spinlock_t lock;
	struct css2600_isys_pipeline *pipes[N_IA_CSS_ISYS_STREAM_SRC];
	void *ssi;
	unsigned int line_align;

	struct css2600_isys_pdata *pdata;

	struct css2600_isys_csi2 csi2[CSS2600_ISYS_MAX_CSI2_PORTS];
	struct css2600_isys_tpg tpg[CSS2600_ISYS_MAX_TPGS];
};

extern const struct v4l2_ioctl_ops css2600_isys_ioctl_ops;

int css2600_pipeline_pm_use(struct media_entity *entity, int use);

#endif /* CSS2600_ISYS_H */
