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

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include <media/css2600-isys.h>
#include <media/media-device.h>
#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/videobuf2-core.h>

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-isys.h"
#include "css2600-isys-csi2-2401.h"
#include "css2600-isys-lib.h"
#include "css2600-isys-subdev.h"
#include "css2600-isys-video.h"

static const uint32_t csi2_supported_codes_pad[] = {
	V4L2_MBUS_FMT_SBGGR10_1X10,
	V4L2_MBUS_FMT_SGBRG10_1X10,
	V4L2_MBUS_FMT_SGRBG10_1X10,
	V4L2_MBUS_FMT_SRGGB10_1X10,
	V4L2_MBUS_FMT_SBGGR8_1X8,
	V4L2_MBUS_FMT_SGBRG8_1X8,
	V4L2_MBUS_FMT_SGRBG8_1X8,
	V4L2_MBUS_FMT_SRGGB8_1X8,
	0,
};

static const uint32_t *csi2_supported_codes[] = {
	csi2_supported_codes_pad,
	csi2_supported_codes_pad,
};

static int link_validate(struct v4l2_subdev *sd, struct media_link *link,
			 struct v4l2_subdev_format *source_fmt,
			 struct v4l2_subdev_format *sink_fmt)
{
	struct css2600_isys_csi2 *csi2 = to_css2600_isys_csi2(sd);
	struct css2600_isys_pipeline *pipe =
		container_of(sd->entity.pipe,
			     struct css2600_isys_pipeline, pipe);
	struct v4l2_subdev *ext_sd =
		media_entity_to_v4l2_subdev(link->source->entity);
	struct css2600_isys_subdev *ext_asd;

	pipe->external = link->source->entity;

	if (ext_sd->owner == THIS_MODULE) {
		ext_asd = to_css2600_isys_subdev(ext_sd);
		pipe->source = ext_asd->source;
		dev_dbg(&csi2->isys->adev->dev, "csi2: using source %d\n",
			ext_asd->source);
	} else {
		pipe->source = csi2->asd.source;
	}

	return v4l2_subdev_link_validate_default(sd, link, source_fmt,
						 sink_fmt);
}

static struct v4l2_subdev_internal_ops csi2_sd_internal_ops = {
};

static const struct v4l2_subdev_core_ops csi2_sd_core_ops = {
};

static int set_stream(struct v4l2_subdev *sd, int enable)
{
	struct css2600_isys_csi2 *csi2 = to_css2600_isys_csi2(sd);
	struct css2600_isys_pipeline *pipe =
		container_of(sd->entity.pipe,
			     struct css2600_isys_pipeline, pipe);
	struct v4l2_subdev *ext_sd =
		media_entity_to_v4l2_subdev(pipe->external);
	struct css2600_isys_csi2_config *cfg;

	dev_dbg(&csi2->isys->adev->dev, "csi2_2401 s_stream %d\n", enable);

	if (!enable)
		return 0;

	if (ext_sd->owner == THIS_MODULE) {
		ia_css_isysapi_rx_set_csi_port_cfg(
			csi2->isys->ssi, csi2->asd.ffmt_entry->mipi_data_type,
			0, pipe->source, 1);
		return 0;
	}

	cfg = v4l2_get_subdev_hostdata(ext_sd);

	ia_css_isysapi_rx_set_csi_port_cfg(
		csi2->isys->ssi, csi2->asd.ffmt_entry->mipi_data_type,
		0, pipe->source, cfg->nlanes);

	return 0;
}

static const struct v4l2_subdev_video_ops csi2_sd_video_ops = {
	.s_stream = set_stream,
};

static const struct v4l2_subdev_pad_ops csi2_sd_pad_ops = {
	.link_validate = link_validate,
	.get_fmt = css2600_isys_subdev_get_ffmt,
	.set_fmt = css2600_isys_subdev_set_ffmt,
};

static struct v4l2_subdev_ops csi2_sd_ops = {
	.core = &csi2_sd_core_ops,
	.video = &csi2_sd_video_ops,
	.pad = &csi2_sd_pad_ops,
};

static struct media_entity_operations csi2_entity_ops = {
	.link_validate = v4l2_subdev_link_validate,
};

void css2600_isys_csi2_2401_cleanup(struct css2600_isys_csi2 *csi2)
{
	v4l2_device_unregister_subdev(&csi2->asd.sd);
	css2600_isys_subdev_cleanup(&csi2->asd);
	css2600_isys_video_cleanup(&csi2->av);
}

int css2600_isys_csi2_2401_init(struct css2600_isys_csi2 *csi2,
				struct css2600_isys *isys, void __iomem *base,
				unsigned int nlanes, unsigned int index)
{
	struct v4l2_subdev_format fmt = {
		.which = V4L2_SUBDEV_FORMAT_ACTIVE,
		.pad = CSI2_PAD_SINK,
		.format = {
			.width = 4096,
			.height = 3072,
		},
	};
	int rval;

	csi2->isys = isys;
	csi2->base = base;
	csi2->nlanes = nlanes;
	csi2->index = index;

	BUG_ON(CSS2600_ISYS_MAX_PAD < NR_OF_CSI2_PADS);
	csi2->asd.pad[CSI2_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
	csi2->asd.pad[CSI2_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
	csi2->asd.sd.entity.ops = &csi2_entity_ops;

	rval = css2600_isys_subdev_init(&csi2->asd, &csi2_sd_ops, 0,
					NR_OF_CSI2_PADS);
	if (rval)
		goto fail;

	csi2->asd.source = IA_CSS_ISYS_STREAM_SRC_CSI2_PORT0 + index;
	csi2->asd.supported_codes = csi2_supported_codes;
	css2600_isys_subdev_set_ffmt(&csi2->asd.sd, NULL, &fmt);

	csi2->asd.sd.internal_ops = &csi2_sd_internal_ops;
	snprintf(csi2->asd.sd.name, sizeof(csi2->asd.sd.name),
		 CSS2600_NAME " CSI-2 %u", index);
	v4l2_set_subdevdata(&csi2->asd.sd, &csi2->asd);
	rval = v4l2_device_register_subdev(&isys->v4l2_dev, &csi2->asd.sd);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register v4l2 subdev\n");
		goto fail;
	}

	snprintf(csi2->av.vdev.name, sizeof(csi2->av.vdev.name),
		 CSS2600_NAME " CSI-2 %u capture", index);
	csi2->av.isys = isys;
	rval = css2600_isys_video_init(
		&csi2->av, &csi2->asd.sd.entity, CSI2_PAD_SOURCE,
		MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
	if (rval) {
		dev_info(&isys->adev->dev, "can't init video node\n");
		goto fail;
	}

	return 0;

fail:
	css2600_isys_csi2_2401_cleanup(csi2);

	return rval;
}

void css2600_isys_csi2_2401_isr(struct css2600_isys_csi2 *csi2)
{
}
