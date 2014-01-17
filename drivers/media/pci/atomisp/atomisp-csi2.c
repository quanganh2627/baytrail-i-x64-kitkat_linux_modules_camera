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

#include "atomisp.h"
#include "atomisp-bus.h"
#include "atomisp-csi2.h"
#include "atomisp-csi2-reg.h"
#include "atomisp-isys.h"
#include "atomisp-isys-subdev.h"
#include "atomisp-isys-video.h"

static struct atomisp_isys_pixelformat csi2_pfmts[] = {
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

static struct v4l2_subdev_internal_ops csi2_sd_internal_ops = {
};

static const struct v4l2_subdev_core_ops csi2_sd_core_ops = {
};

static const struct v4l2_subdev_video_ops csi2_sd_video_ops = {
};

static const struct v4l2_subdev_pad_ops csi2_sd_pad_ops = {
	.set_fmt = atomisp_isys_subdev_set_ffmt
};

static struct v4l2_subdev_ops csi2_sd_ops = {
	.core = &csi2_sd_core_ops,
	.video = &csi2_sd_video_ops,
	.pad = &csi2_sd_pad_ops,
};

void atomisp_csi2_cleanup(struct atomisp_csi2 *csi2)
{
	v4l2_device_unregister_subdev(&csi2->asd.sd);
	media_entity_cleanup(&csi2->asd.sd.entity);
	atomisp_isys_video_cleanup(&csi2->av);
}

int atomisp_csi2_init(struct atomisp_csi2 *csi2, struct atomisp_isys *isys,
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
		 "AtomISP CSI-2 %u capture", index);
	csi2->av.pfmts = csi2_pfmts;
	csi2->av.isys = isys;
	rval = atomisp_isys_video_init(&csi2->av);
	if (rval) {
		dev_info(&isys->adev->dev, "can't init video node\n");
		goto fail;
	}

	csi2->pad[CSI2_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
	csi2->pad[CSI2_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;

	atomisp_isys_subdev_init(&csi2->asd, &csi2_sd_ops);

	rval = media_entity_init(&csi2->asd.sd.entity, NR_OF_CSI2_PADS,
				 csi2->asd.pad, 0);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register media entity\n");
		goto fail;
	}

	csi2->asd.supported_fmts = csi2_supported_fmts;
	atomisp_isys_subdev_set_ffmt(&csi2->asd.sd, NULL, &fmt);

	csi2->asd.sd.internal_ops = &csi2_sd_internal_ops;
	snprintf(csi2->asd.sd.name, sizeof(csi2->asd.sd.name),
		 "AtomISP CSI-2 %u", index);
	v4l2_set_subdevdata(&csi2->asd.sd, csi2);
	rval = v4l2_device_register_subdev(&isys->v4l2_dev, &csi2->asd.sd);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register v4l2 subdev\n");
		goto fail;
	}

	rval = media_entity_create_link(&csi2->asd.sd.entity, CSI2_PAD_SOURCE,
					&csi2->av.vdev.entity, 0, 0);
	if (rval) {
		dev_info(&isys->adev->dev, "can't create link\n");
		goto fail;
	}

	return 0;

fail:
	atomisp_csi2_cleanup(csi2);

	return rval;
}

void atomisp_csi2_isr(struct atomisp_csi2 *csi2)
{
}

void atomisp_csi2_set_stream(struct atomisp_csi2 *csi2, bool enable)
{
	unsigned int i;

	if (!enable) {
		writel(0, csi2->base + CSI2_REG_CSI_RX_ENABLE);
		return;
	}

	writel(csi2->sensor_cfg.termen[ATOMISP_CSI2_SENSOR_CFG_LANE_CLOCK],
	       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_TERMEN_CLANE);
	writel(csi2->sensor_cfg.settle[ATOMISP_CSI2_SENSOR_CFG_LANE_CLOCK],
	       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_SETTLE_CLANE);

	for (i = 0; i < MAX_CSI2_LANES; i++) {
		writel(csi2->sensor_cfg.termen[ATOMISP_CSI2_SENSOR_CFG_LANE_DATA(i)],
		       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_TERMEN_DLANE(i));
		writel(csi2->sensor_cfg.settle[ATOMISP_CSI2_SENSOR_CFG_LANE_DATA(i)],
		       csi2->base + CSI2_REG_CSI_RX_DLY_CNT_SETTLE_DLANE(i));
	}

	writel(CSI2_CSI_RX_ENABLE_ENABLE, csi2->base + CSI2_REG_CSI_RX_ENABLE);
}

static bool atomisp_csi2_is_idle(struct atomisp_csi2 *csi2)
{
	return readl(csi2->base + CSI2_REG_CSI_RX_STATUS)
		!= CSI2_CSI_RX_STATUS_BUSY;
}
