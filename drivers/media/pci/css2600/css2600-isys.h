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

#if IS_ENABLED(CONFIG_VIDEO_CSS2600_2401)
#include <lib2401.h>
#endif /* IS_ENABLED(CONFIG_VIDEO_CSS2600_2401) */
#include <linux/firmware.h>
#include <linux/spinlock.h>

#include <media/v4l2-device.h>
#include <media/media-device.h>

#include "css2600.h"
#include "css2600-isys-csi2-2401.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-lib.h"
#include "css2600-isys-tpg.h"
#include "css2600-isys-video.h"
#include "css2600-isys-wrapper-2401.h"
#include "css2600-pdata.h"
#if IS_ENABLED(CONFIG_VIDEO_CSS2600_2401)
#include "lib2401/ia_css_env.h"
#endif /* IS_ENABLED(CONFIG_VIDEO_CSS2600_2401) */

#define CSS2600_ISYS_MAX_CSI2_PORTS		4
#define CSS2600_ISYS_MAX_TPGS			CSS2600_ISYS_MAX_CSI2_PORTS

/*
 * struct css2600_isys
 *
 * @lock: serialise access to pipes
 * @pipes: pipelines per stream ID
 */
struct css2600_isys {
	struct media_device media_dev;
	struct v4l2_device v4l2_dev;
	struct css2600_bus_device *adev;
	spinlock_t lock;
	struct css2600_isys_pipeline *pipes[N_IA_CSS_ISYS_STREAM_SRC];

	struct css2600_isys_pdata *pdata;

	struct css2600_isys_csi2 csi2[CSS2600_ISYS_MAX_CSI2_PORTS];
	struct css2600_isys_csi2_2401 csi2_2401[CSS2600_ISYS_MAX_CSI2_PORTS];
	/* 2401 has a test pattern generator per port */
	struct css2600_isys_tpg tpg[CSS2600_ISYS_MAX_TPGS];

#if IS_ENABLED(CONFIG_VIDEO_CSS2600_2401)
	struct ia_css_env css_env;
	struct ia_css_fw css_fw;
	const struct firmware *fw;
#endif /* IS_ENABLED(CONFIG_VIDEO_CSS2600_2401) */
};

extern const struct v4l2_ioctl_ops css2600_isys_ioctl_ops;

int css2600_pipeline_pm_use(struct media_entity *entity, int use);

#define CSS2401_FIRMWARE "shisp_2401a0_v21_bxtpoc.bin"

#endif /* CSS2600_ISYS_H */
