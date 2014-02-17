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
#include "css2600-isys.h"
#include "css2600-isys-subdev.h"
#include "css2600-isys-tpg.h"
#include "css2600-isys-video.h"

static const uint32_t tpg_supported_codes_pad[] = {
	V4L2_MBUS_FMT_SBGGR10_1X10,
	V4L2_MBUS_FMT_SGBRG10_1X10,
	V4L2_MBUS_FMT_SGRBG10_1X10,
	V4L2_MBUS_FMT_SRGGB10_1X10,
	0,
};

static const uint32_t *tpg_supported_codes[] = {
	tpg_supported_codes_pad,
	tpg_supported_codes_pad,
};

static struct v4l2_subdev_internal_ops tpg_sd_internal_ops = {
};

static const struct v4l2_subdev_core_ops tpg_sd_core_ops = {
};

static const struct v4l2_subdev_video_ops tpg_sd_video_ops = {
};

static const struct v4l2_subdev_pad_ops tpg_sd_pad_ops = {
	.get_fmt = css2600_isys_subdev_get_ffmt,
	.set_fmt = css2600_isys_subdev_set_ffmt,
};

static struct v4l2_subdev_ops tpg_sd_ops = {
	.core = &tpg_sd_core_ops,
	.video = &tpg_sd_video_ops,
	.pad = &tpg_sd_pad_ops,
};

void css2600_isys_tpg_cleanup(struct css2600_isys_tpg *tpg)
{
	v4l2_device_unregister_subdev(&tpg->asd.sd);
	css2600_isys_subdev_cleanup(&tpg->asd);
	css2600_isys_video_cleanup(&tpg->av);
}

int css2600_isys_tpg_init(struct css2600_isys_tpg *tpg, struct css2600_isys *isys,
		      void __iomem *base, unsigned int index)
{
	struct v4l2_subdev_format fmt = {
		.which = V4L2_SUBDEV_FORMAT_ACTIVE,
		.pad = TPG_PAD_SOURCE,
		.format = {
			.width = 4096,
			.height = 3072,
		},
	};
	int rval;

	tpg->isys = isys;
	tpg->base = base;
	tpg->index = index;

	BUG_ON(CSS2600_ISYS_MAX_PAD < NR_OF_TPG_PADS);
	tpg->asd.pad[TPG_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;

	css2600_isys_subdev_init(&tpg->asd, &tpg_sd_ops, 0, NR_OF_TPG_PADS);

	tpg->asd.supported_codes = tpg_supported_codes;
	css2600_isys_subdev_set_ffmt(&tpg->asd.sd, NULL, &fmt);

	tpg->asd.sd.internal_ops = &tpg_sd_internal_ops;
	snprintf(tpg->asd.sd.name, sizeof(tpg->asd.sd.name),
		 CSS2600_NAME " TPG %u", index);
	v4l2_set_subdevdata(&tpg->asd.sd, &tpg->asd);
	rval = v4l2_device_register_subdev(&isys->v4l2_dev, &tpg->asd.sd);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register v4l2 subdev\n");
		goto fail;
	}

	if (isys->pdata->type == CSS2600_ISYS_TYPE_CSS2401)
		return 0;

	snprintf(tpg->av.vdev.name, sizeof(tpg->av.vdev.name),
		 CSS2600_NAME " TPG %u capture", index);
	tpg->av.isys = isys;
	rval = css2600_isys_video_init(
		&tpg->av, &tpg->asd.sd.entity, TPG_PAD_SOURCE,
		MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
	if (rval) {
		dev_info(&isys->adev->dev, "can't init video node\n");
		goto fail;
	}

	return 0;

fail:
	css2600_isys_tpg_cleanup(tpg);

	return rval;
}

void css2600_isys_tpg_isr(struct css2600_isys_tpg *tpg)
{
}

void css2600_isys_tpg_set_stream(struct css2600_isys_tpg *tpg, bool enable)
{
}
