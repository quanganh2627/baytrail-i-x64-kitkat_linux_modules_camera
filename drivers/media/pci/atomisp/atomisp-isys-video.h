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

#ifndef ATOMISP_ISYS_VIDEO_H
#define ATOMISP_ISYS_VIDEO_H

#include <linux/videodev2.h>
#include <media/media-entity.h>
#include <media/v4l2-device.h>

#include "atomisp-isys-queue.h"

struct atomisp_isys;

struct atomisp_isys_video {
	struct media_pad pad;
	struct video_device vdev;
	struct v4l2_pix_format pix;
	const struct atomisp_isys_pixelformat *pfmts;
	const struct atomisp_isys_pixelformat *pfmt;
	struct atomisp_isys_queue aq;
	struct atomisp_isys *isys;
};

#define atomisp_isys_queue_to_video(__aq) \
	container_of(__aq, struct atomisp_isys_video, aq)

int atomisp_isys_video_init(struct atomisp_isys_video *av,
			    struct atomisp_isys *isys);
void atomisp_isys_video_cleanup(struct atomisp_isys_video *av);

#endif /* ATOMISP_ISYS_VIDEO_H */
