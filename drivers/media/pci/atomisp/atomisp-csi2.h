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

#ifndef ATOMISP_CSI2_H
#define ATOMISP_CSI2_H

#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/videobuf2-core.h>

#include "atomisp-isys-video.h"

struct atomisp_csi2_pdata;
struct atomisp_isys;

#define CSI2_PAD_SINK			0
#define CSI2_PAD_SOURCE			1
#define NR_OF_CSI2_PADS			2

#define MAX_CSI2_LANES			4

#define ATOMISP_CSI2_SENSOR_CFG_LANE_CLOCK	0
#define ATOMISP_CSI2_SENSOR_CFG_LANE_DATA(n)	((n) + 1)

/*
 * struct atomisp_csi2
 *
 * @nlanes: number of lanes in the receiver
 */
struct atomisp_csi2 {
	struct atomisp_csi2_pdata *pdata;
	struct atomisp_isys *isys;
	struct v4l2_subdev sd;
	struct atomisp_isys_video av;
	struct media_pad pad[NR_OF_CSI2_PADS];

	void __iomem *base;
	unsigned int nlanes;
	unsigned int index;

	struct {
		unsigned int nlanes;
		/* Unit is 0,0625 ns */
		unsigned int termen[MAX_CSI2_LANES];
		unsigned int settle[MAX_CSI2_LANES];
	} sensor_cfg;
};

int atomisp_csi2_init(struct atomisp_csi2 *csi2, struct atomisp_isys *isys,
		      void __iomem *base, unsigned int lanes,
		      unsigned int index);
void atomisp_csi2_cleanup(struct atomisp_csi2 *csi2);
void atomisp_csi2_isr(struct atomisp_csi2 *csi2);

void atomisp_csi2_set_stream(struct atomisp_csi2 *csi2, bool enable);

#endif /* ATOMISP_CSI2_H */
