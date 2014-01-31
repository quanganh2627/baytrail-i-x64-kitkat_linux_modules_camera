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

struct v4l2_rect *__css2600_isys_get_selection(
	struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh, unsigned int target,
	unsigned int pad, unsigned int which)
{
	struct css2600_isys_subdev *asd = to_css2600_isys_subdev(sd);

	if (which == V4L2_SUBDEV_FORMAT_ACTIVE) {
		switch (target) {
		case V4L2_SEL_TGT_CROP:
			return &asd->crop[pad];
		case V4L2_SEL_TGT_COMPOSE:
			/*
			 * Compose is valid for sink pads only, and
			 * for css2600 sink pads are always zero.
			 */
			BUG_ON(pad);
			return &asd->compose;
		}
	} else {
		switch (target) {
		case V4L2_SEL_TGT_CROP:
			return v4l2_subdev_get_try_crop(fh, pad);
		case V4L2_SEL_TGT_COMPOSE:
			BUG_ON(pad);
			return v4l2_subdev_get_try_compose(fh, pad);
		}
	}
	BUG();
}

static void fmt_propagate(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
			  struct v4l2_mbus_framefmt *ffmt, struct v4l2_rect *r,
			  enum isys_subdev_prop_tgt tgt, unsigned int pad,
			  unsigned int which)
{
	struct v4l2_mbus_framefmt *ffmts[CSS2600_ISYS_MAX_PAD];
	struct v4l2_rect *crops[CSS2600_ISYS_MAX_PAD];
	struct v4l2_rect *compose;
	unsigned int i;

	if (tgt == CSS2600_ISYS_SUBDEV_PROP_TGT_NR_OF)
		return;

	for (i = 0; i < sd->entity.num_pads; i++) {
		ffmts[i] = __css2600_isys_get_ffmt(sd, fh, i, which);
		crops[i] = __css2600_isys_get_selection(
			sd, fh, V4L2_SEL_TGT_CROP, i, which);
	}
	compose = __css2600_isys_get_selection(sd, fh, V4L2_SEL_TGT_COMPOSE,
					       0, which);

	switch (tgt) {
	case CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_FMT:
		crops[pad]->left = crops[pad]->top = 0;
		crops[pad]->width = ffmt->width;
		crops[pad]->height = ffmt->height;
		for (i = 1; i < sd->entity.num_pads; i++)
			ffmts[i]->code = ffmt->code;
		fmt_propagate(sd, fh, NULL, crops[pad], tgt + 1, pad, which);
		return;
	case CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_CROP:
		compose->left = compose->top = 0;
		compose->width = r->width;
		compose->height = r->height;
		fmt_propagate(sd, fh, NULL, compose, tgt + 1, pad, which);
		return;
	case CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_COMPOSE:
		for (i = 1; i < sd->entity.num_pads; i++) {
			crops[pad]->left = crops[pad]->top = 0;
			crops[pad]->width = r->width;
			crops[pad]->height = r->height;
			fmt_propagate(sd, fh, NULL, crops[pad], tgt + 1, i,
				      which);
		}
		return;
	case CSS2600_ISYS_SUBDEV_PROP_TGT_SOURCE_CROP:
		ffmts[pad]->width = r->width;
		ffmts[pad]->height = r->height;
		return;
	}
}

int css2600_isys_subdev_set_ffmt(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_format *fmt)
{
	struct css2600_isys_subdev *asd = to_css2600_isys_subdev(sd);
	struct media_entity *ent = &sd->entity;
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

	fmt->format.code = code;

	if (!fmt->pad) {
		/* This is either a sink pad or an entity has no sink pads. */
		*ffmt = fmt->format;

		fmt_propagate(sd, fh, ffmt, NULL,
			      CSS2600_ISYS_SUBDEV_PROP_TGT_SINK_FMT, fmt->pad,
			      fmt->which);
	} else {
		/* Source pad */
		ffmt->code = fmt->format.code;
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
