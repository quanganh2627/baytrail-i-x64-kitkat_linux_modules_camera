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

#include <linux/types.h>
#include <linux/v4l2-mediabus.h>
#include <linux/videodev2.h>

#include <media/media-entity.h>

#include "css2600-isys-subdev.h"

struct v4l2_mbus_framefmt *__css2600_isys_get_ffmt(
	struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
	unsigned int pad, unsigned int which)
{
	struct css2600_isys_subdev *asd = to_css2600_isys_subdev(sd);

	if (which == V4L2_SUBDEV_FORMAT_ACTIVE)
		return &asd->ffmt[pad];
	else
		return v4l2_subdev_get_try_format(fh, pad);
}

int css2600_isys_subdev_set_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt)
{
	struct css2600_isys_subdev *asd = to_css2600_isys_subdev(sd);
	struct media_entity *ent = &sd->entity;
	struct media_pad *pad = &ent->pads[fmt->pad];
	struct v4l2_mbus_framefmt *ffmt =
		__css2600_isys_get_ffmt(sd, fh, fmt->pad, fmt->which);
	uint32_t code = asd->supported_fmts[fmt->pad][0];
	unsigned int i;

	for (i = 0; asd->supported_fmts[fmt->pad][i]; i++) {
		if (asd->supported_fmts[fmt->pad][i] == fmt->format.code) {
			code = asd->supported_fmts[fmt->pad][i];
			break;
		}
	}

	ffmt->code = code;

	if (pad->flags & MEDIA_PAD_FL_SINK) {
		/* Assume pads other than zero are source */
		for (i = 1; i < ent->num_pads; i++) {
			struct v4l2_mbus_framefmt *sink_ffmt =
				__css2600_isys_get_ffmt(sd, fh, i, fmt->which);

			*sink_ffmt = *ffmt;
		}
	} else {
		/* Source pad */
	}

	fmt->format = *ffmt;

	return 0;
}

int css2600_isys_subdev_get_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt)
{
	fmt->format = *__css2600_isys_get_ffmt(sd, fh, fmt->pad, fmt->which);

	return 0;
}

int css2600_isys_subdev_init(struct css2600_isys_subdev *asd,
			     struct v4l2_subdev_ops *ops, unsigned int nr_ctrls,
			     unsigned int num_pads)
{
	int rval;

	v4l2_subdev_init(&asd->sd, ops);

	asd->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	asd->sd.owner = THIS_MODULE;

	rval = v4l2_ctrl_handler_init(&asd->ctrl_handler, nr_ctrls);
	if (rval)
		return rval;

	rval = media_entity_init(&asd->sd.entity, num_pads, asd->pad, 0);
	if (rval)
		goto fail;

	return 0;

fail:
	v4l2_ctrl_handler_free(&asd->ctrl_handler);

	return rval;
}

void css2600_isys_subdev_cleanup(struct css2600_isys_subdev *asd)
{
	media_entity_cleanup(&asd->sd.entity);
	v4l2_ctrl_handler_free(&asd->ctrl_handler);
}
