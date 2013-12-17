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
#include "atomisp-isys-video.h"

static struct v4l2_subdev_internal_ops csi2_sd_internal_ops = {
};

static struct v4l2_subdev_ops csi2_sd_ops = {
};

void atomisp_csi2_cleanup(struct atomisp_csi2 *csi2)
{
	v4l2_device_unregister_subdev(&csi2->sd);
	media_entity_cleanup(&csi2->sd.entity);
	atomisp_isys_video_cleanup(&csi2->av);
}

int atomisp_csi2_init(struct atomisp_csi2 *csi2, struct atomisp_isys *isys,
		      void __iomem *base, unsigned int nlanes,
		      unsigned int index)
{
	int rval;

	csi2->isys = isys;
	csi2->base = base;
	csi2->nlanes = nlanes;
	csi2->index = index;

	snprintf(csi2->av.vdev.name, sizeof(csi2->av.vdev.name),
		 "AtomISP CSI-2 %u capture", index);
	rval = atomisp_isys_video_init(&csi2->av, csi2->isys);
	if (rval) {
		dev_info(&isys->adev->dev, "can't init video node\n");
		goto fail;
	}

	v4l2_subdev_init(&csi2->sd, &csi2_sd_ops);

	csi2->pad[CSI2_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
	csi2->pad[CSI2_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;

	rval = media_entity_init(&csi2->sd.entity, NR_OF_CSI2_PADS,
				 csi2->pad, 0);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register media entity\n");
		goto fail;
	}

	csi2->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	csi2->sd.internal_ops = &csi2_sd_internal_ops;
	csi2->sd.owner = THIS_MODULE;
	snprintf(csi2->sd.name, sizeof(csi2->sd.name), "AtomISP CSI-2 %u",
		 index);
	v4l2_set_subdevdata(&csi2->sd, csi2);
	rval = v4l2_device_register_subdev(&isys->v4l2_dev, &csi2->sd);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register v4l2 subdev\n");
		goto fail;
	}

	rval = media_entity_create_link(&csi2->sd.entity, CSI2_PAD_SOURCE,
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
