/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
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

#include "ia_css_psys_frameadapter.h"
#include "ia_css_pg_info.h"

#include "math_support.h"
#include "assert_support.h"

static void psys_frameadapter_init_plane(
	struct ia_css_psys_buffer_plane_descr *plane,
	unsigned int width,
	unsigned int stride,
	unsigned int height,
	unsigned int offset)
{
	plane->width = width;
	plane->height = height;
	plane->stride = stride;
	plane->offset = offset;
	plane->size = stride * height;
}

static void psys_frameadapter_init_single_plane(
	struct ia_css_psys_buffer_descr *buffer_descr,
	unsigned int height,
	unsigned int subpixels_per_line,
	unsigned int bytes_per_pixel)
{
	unsigned int stride;

	stride = subpixels_per_line * bytes_per_pixel;
	buffer_descr->size = stride * CEIL_MUL2(height, 2);
	psys_frameadapter_init_plane(&buffer_descr->planes[0],
		subpixels_per_line, stride, height, 0);
}

static void psys_frameadapater_init_yuv_planes(
	struct ia_css_psys_buffer_descr *buffer_descr,
	const struct ia_css_pg_frame_info *info,
	unsigned int horizontal_decimation,
	unsigned int vertical_decimation,
	bool swap_uv,
	unsigned int bytes_per_element)
{
	unsigned int y_width = info->padded_width,
	    y_height = info->res.height,
	    uv_width = y_width / horizontal_decimation,
	    uv_height = y_height / vertical_decimation,
	    y_stride, y_bytes, uv_bytes, uv_stride;

	y_stride = y_width * bytes_per_element;
	uv_stride = uv_width * bytes_per_element;
	y_bytes = y_stride * y_height;
	uv_bytes = uv_stride * uv_height;

	buffer_descr->size = y_bytes + 2 * uv_bytes;
	psys_frameadapter_init_plane(&buffer_descr->planes[0], y_width, y_stride, y_height, 0);
	if (swap_uv) {
		psys_frameadapter_init_plane(&buffer_descr->planes[2], uv_width, uv_stride,
				 uv_height, y_bytes);
		psys_frameadapter_init_plane(&buffer_descr->planes[1], uv_width, uv_stride,
				 uv_height, y_bytes + uv_bytes);
	} else {
		psys_frameadapter_init_plane(&buffer_descr->planes[1], uv_width, uv_stride,
				 uv_height, y_bytes);
		psys_frameadapter_init_plane(&buffer_descr->planes[2], uv_width, uv_stride,
				 uv_height, y_bytes + uv_bytes);
	}
	return;
}

void ia_css_psys_frameadapter_get_descr(
	struct ia_css_psys_buffer_descr *buffer_descr,
	const struct ia_css_pg_frame_info *info)
{
	assert(buffer_descr != NULL);
	assert(info != NULL);

	buffer_descr->format = info->format;
	switch(info->format) {
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV_LINE:
		buffer_descr->nof_planes = 1;
		/* Needs 3 extra lines to allow vf_pp prefetching */
		psys_frameadapter_init_single_plane(buffer_descr,
			info->res.height * 3 / 2 + 3,
			info->padded_width, 1);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV420:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 2, false, 1);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV422:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 1, false, 1);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV444:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 1, 1, false, 1);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV420_16:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 2, false, 2);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YUV422_16:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 1, false, 2);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YV12:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 2, true, 1);
		break;
	case IA_CSS_PG_IO_FRAME_FORMAT_YV16:
		buffer_descr->nof_planes = 3;
		psys_frameadapater_init_yuv_planes(buffer_descr, info, 2, 1, true, 1);
		break;
	default:
		assert(0);
	}
}
