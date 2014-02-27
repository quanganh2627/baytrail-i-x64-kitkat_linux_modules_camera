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
 */

#ifndef CSS2600_ISYS_VIDEO_H
#define CSS2600_ISYS_VIDEO_H

#include <linux/mutex.h>
#include <linux/videodev2.h>
#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/v4l2-subdev.h>

#include "css2600-isys-queue.h"

struct css2600_isys;

struct css2600_isys_pixelformat {
	uint32_t pixelformat;
	uint32_t bpp;
	uint32_t bpp_packed;
	uint32_t code;
};

struct css2600_isys_pipeline {
	struct media_pipeline pipe;
	struct media_entity *external;
	bool continuous;
};

struct css2600_isys_video {
	/* Serialise access to other fields in the struct. */
	struct mutex mutex;
	struct media_pad pad;
	struct video_device vdev;
	struct v4l2_pix_format pix;
	const struct css2600_isys_pixelformat *pfmt;
	struct css2600_isys_queue aq;
	struct css2600_isys *isys;
	struct css2600_isys_pipeline ip;
	unsigned int streaming;
};

#define css2600_isys_queue_to_video(__aq) \
	container_of(__aq, struct css2600_isys_video, aq)

const struct css2600_isys_pixelformat *css2600_isys_get_pixelformat(
	struct css2600_isys_video *av, uint32_t pixelformat);

int css2600_isys_video_set_streaming(struct css2600_isys_video *av,
				     unsigned int state);
int css2600_isys_video_init(struct css2600_isys_video *av,
			    struct media_entity *source,
			    unsigned int source_pad,
			    unsigned int flags);
void css2600_isys_video_cleanup(struct css2600_isys_video *av);

#endif /* CSS2600_ISYS_VIDEO_H */
