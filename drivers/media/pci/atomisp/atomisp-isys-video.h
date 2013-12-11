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

#ifndef ATOMISP_ISYS_VIDEO_H
#define ATOMISP_ISYS_VIDEO_H

#include <media/media-entity.h>
#include <media/v4l2-device.h>

struct atomisp_isys;

struct atomisp_isys_video {
	struct media_pad pad;
	struct video_device vdev;
};

int atomisp_isys_video_init(struct atomisp_isys_video *av,
			    struct atomisp_isys *isys);
void atomisp_isys_video_cleanup(struct atomisp_isys_video *av);

#endif /* ATOMISP_ISYS_VIDEO_H */
