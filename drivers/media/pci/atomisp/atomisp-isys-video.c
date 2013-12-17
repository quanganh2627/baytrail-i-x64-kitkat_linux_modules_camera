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

#include <media/media-entity.h>
#include <media/v4l2-device.h>

#include "atomisp-isys.h"
#include "atomisp-isys-video.h"

int atomisp_isys_video_init(struct atomisp_isys_video *av,
			    struct atomisp_isys *isys)
{
	int rval;

	av->pad.flags = MEDIA_PAD_FL_SINK;
	rval = media_entity_init(&av->vdev.entity, 1, &av->pad, 0);
	if (rval)
		return rval;

	av->vdev.release = video_device_release_empty;
	av->vdev.fops = &atomisp_isys_fops;
	av->vdev.v4l2_dev = &isys->v4l2_dev;

	rval = video_register_device(&av->vdev, VFL_TYPE_GRABBER, -1);
	if (rval)
		media_entity_cleanup(&av->vdev.entity);

	return rval;
}

void atomisp_isys_video_cleanup(struct atomisp_isys_video *av)
{
	video_unregister_device(&av->vdev);
	media_entity_cleanup(&av->vdev.entity);
}
