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

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>

#include <media/media-device.h>
#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/videobuf2-core.h>

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-csi2-reg.h"
#include "css2600-isys.h"
#include "css2600-isys-subdev.h"
#include "css2600-isys-video.h"

static struct css2600_isys_pixelformat csi2_pfmts[] = {
	{ V4L2_PIX_FMT_SBGGR10, 16, 10, V4L2_MBUS_FMT_SBGGR10_1X10 },
	{ V4L2_PIX_FMT_SGBRG10, 16, 10, V4L2_MBUS_FMT_SGBRG10_1X10 },
	{ V4L2_PIX_FMT_SGRBG10, 16, 10, V4L2_MBUS_FMT_SGRBG10_1X10 },
	{ V4L2_PIX_FMT_SRGGB10, 16, 10, V4L2_MBUS_FMT_SRGGB10_1X10 },
	{ }
};

static const uint32_t csi2_supported_fmts_pad[] = {
	V4L2_MBUS_FMT_SBGGR10_1X10,
	V4L2_MBUS_FMT_SGBRG10_1X10,
	V4L2_MBUS_FMT_SGRBG10_1X10,
	V4L2_MBUS_FMT_SRGGB10_1X10,
	0,
};

static const uint32_t *csi2_supported_fmts[] = {
	csi2_supported_fmts_pad,
	csi2_supported_fmts_pad,
};

static int link_validate(struct v4l2_subdev *sd, struct media_link *link,
			 struct v4l2_subdev_format *source_fmt,
			 struct v4l2_subdev_format *sink_fmt)
{
	struct css2600_isys_pipeline *pipe =
		container_of(sd->entity.pipe,
			     struct css2600_isys_pipeline, pipe);

	pipe->external = &sd->entity;

	return v4l2_subdev_link_validate_default(sd, link, source_fmt,
						 sink_fmt);
}

static struct v4l2_subdev_internal_ops csi2_sd_internal_ops = {
};

static const struct v4l2_subdev_core_ops csi2_sd_core_ops = {
};

static const struct v4l2_subdev_video_ops csi2_sd_video_ops = {
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

void css2600_isys_csi2_cleanup(struct css2600_isys_csi2 *csi2)
{
	v4l2_device_unregister_subdev(&csi2->asd.sd);
	css2600_isys_subdev_cleanup(&csi2->asd);
	css2600_isys_video_cleanup(&csi2->av);
}

int css2600_isys_csi2_init(struct css2600_isys_csi2 *csi2, struct css2600_isys *isys,
		      void __iomem *base, unsigned int nlanes,
		      unsigned int index)
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

	snprintf(csi2->av.vdev.name, sizeof(csi2->av.vdev.name),
		 CSS2600_NAME " CSI-2 %u capture", index);
	csi2->av.pfmts = csi2_pfmts;
	csi2->av.isys = isys;
	rval = css2600_isys_video_init(&csi2->av);
	if (rval) {
		dev_info(&isys->adev->dev, "can't init video node\n");
		goto fail;
	}

	BUG_ON(CSS2600_ISYS_MAX_PAD < NR_OF_CSI2_PADS);
	csi2->asd.pad[CSI2_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
	csi2->asd.pad[CSI2_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;

	rval = css2600_isys_subdev_init(&csi2->asd, &csi2_sd_ops, 0,
					NR_OF_CSI2_PADS);
	if (rval)
		goto fail;

	csi2->asd.supported_fmts = csi2_supported_fmts;
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

	rval = media_entity_create_link(
		&csi2->asd.sd.entity, CSI2_PAD_SOURCE, &csi2->av.vdev.entity,
		0, isys->pdata->type == CSS2600_ISYS_TYPE_CSS2401
		? MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE : 0);
	if (rval) {
		dev_info(&isys->adev->dev, "can't create link\n");
		goto fail;
	}

	return 0;

fail:
	css2600_isys_csi2_cleanup(csi2);

	return rval;
}

void css2600_isys_csi2_isr(struct css2600_isys_csi2 *csi2)
{
}

void css2600_isys_csi2_set_stream(struct css2600_isys_csi2 *csi2, bool enable)
{
	unsigned int i;

	if (!enable) {
		writel(0, csi2->base + CSI2_REG_CSI_RX_ENABLE);
		return;
	}

	writel(csi2->sensor_cfg.termen[CSS2600_ISYS_CSI2_SENSOR_CFG_LANE_CLOCK],
	       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_TERMEN_CLANE);
	writel(csi2->sensor_cfg.settle[CSS2600_ISYS_CSI2_SENSOR_CFG_LANE_CLOCK],
	       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_SETTLE_CLANE);

	for (i = 0; i < MAX_CSI2_LANES; i++) {
		writel(csi2->sensor_cfg.termen[CSS2600_ISYS_CSI2_SENSOR_CFG_LANE_DATA(i)],
		       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_TERMEN_DLANE(i));
		writel(csi2->sensor_cfg.settle[CSS2600_ISYS_CSI2_SENSOR_CFG_LANE_DATA(i)],
		       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_SETTLE_DLANE(i));
	}

	writel(CSI2_CSI_RX_ENABLE_ENABLE, csi2->base + CSI2_REG_CSI_RX_ENABLE);
}

static bool css2600_isys_csi2_is_idle(struct css2600_isys_csi2 *csi2)
{
	return readl(csi2->base + CSI2_REG_CSI_RX_STATUS)
		!= CSI2_CSI_RX_STATUS_BUSY;
}
