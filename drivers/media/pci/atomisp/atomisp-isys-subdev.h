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

#ifndef ATOMISP_ISYS_SUBDEV_H
#define ATOMISP_ISYS_SUBDEV_H

#include <media/media-entity.h>
#include <media/v4l2-device.h>

#include "atomisp-isys-queue.h"

struct atomisp_isys_ffmt_entry {
	uint32_t code;
	uint32_t bpp;
};

#define FMT_ENTRY (struct atomisp_isys_fmt_entry [])

#define ATOMISP_ISYS_MAX_PAD		2

struct atomisp_isys_subdev {
	struct v4l2_subdev sd;
	uint32_t const * const *supported_fmts;
	struct media_pad pad[ATOMISP_ISYS_MAX_PAD];
	struct v4l2_mbus_framefmt ffmt[ATOMISP_ISYS_MAX_PAD];
};

#define to_atomisp_isys_subdev(__sd) \
	container_of(__sd, struct atomisp_isys_subdev, sd)

int atomisp_isys_subdev_set_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt);
int atomisp_isys_subdev_get_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt);

void atomisp_isys_subdev_init(struct atomisp_isys_subdev *asd,
			      struct v4l2_subdev_ops *ops);

#endif /* ATOMISP_ISYS_SUBDEV_H */
