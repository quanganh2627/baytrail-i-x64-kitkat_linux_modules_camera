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

#ifndef CSS2600_ISYS_SUBDEV_H
#define CSS2600_ISYS_SUBDEV_H

#include <linux/mutex.h>

#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/v4l2-ctrls.h>

#include "css2600-isys-queue.h"

struct css2600_isys_ffmt_entry {
	uint32_t code;
	uint32_t bpp;
};

#define FMT_ENTRY (struct css2600_isys_fmt_entry [])

#define CSS2600_ISYS_MAX_PAD		2

enum isys_subdev_prop_tgt {
	CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_FMT,
	CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_CROP,
	CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_COMPOSE,
	CSS2600_ISYS_SUBDEV_PROP_TGT_SOURCE_CROP,
};
#define	CSS2600_ISYS_SUBDEV_PROP_TGT_NR_OF \
	(CSS2600_ISYS_SUBDEV_PROP_TGT_SOURCE_CROP + 1)

struct css2600_isys_subdev {
	/* Serialise access to any other field in the struct */
	struct mutex mutex;
	struct v4l2_subdev sd;
	uint32_t const * const *supported_codes;
	struct media_pad pad[CSS2600_ISYS_MAX_PAD];
	struct v4l2_mbus_framefmt ffmt[CSS2600_ISYS_MAX_PAD];
	struct v4l2_rect crop[CSS2600_ISYS_MAX_PAD];
	struct v4l2_rect compose;
	struct v4l2_ctrl_handler ctrl_handler;
	struct {
		bool crop;
		bool compose;
	} valid_tgts[CSS2600_ISYS_MAX_PAD];
	bool allow_source_fmt_change;
	int source; /* SSI stream source; -1 if unset */
};

#define to_css2600_isys_subdev(__sd) \
	container_of(__sd, struct css2600_isys_subdev, sd)

struct v4l2_mbus_framefmt *__css2600_isys_get_ffmt(
	struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
	unsigned int pad, unsigned int which);

int css2600_isys_subdev_set_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt);
int css2600_isys_subdev_get_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt);

int css2600_isys_subdev_init(struct css2600_isys_subdev *asd,
			     struct v4l2_subdev_ops *ops,
			     unsigned int nr_ctrls, unsigned int num_pads);
void css2600_isys_subdev_cleanup(struct css2600_isys_subdev *asd);

#endif /* CSS2600_ISYS_SUBDEV_H */
