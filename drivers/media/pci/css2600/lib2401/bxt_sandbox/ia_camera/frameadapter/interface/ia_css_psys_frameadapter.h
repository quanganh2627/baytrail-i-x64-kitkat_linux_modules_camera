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

#ifndef __IA_CSS_PSYS_FRAME_ADAPTER_H__
#define __IA_CSS_PSYS_FRAME_ADAPTER_H__

#include "ia_css_pg_info.h"

/*****************************************************************************
* This module provides a buffer description that can be used to allocate psys
* buffers. Supports YUV line and vfpp only.
*****************************************************************************/

/* Support for max no.of planes based on qplane6 definition in CSS */
#define PSYS_MAX_PLANES	6

/* Frame resolution for input and output terminals */
struct ia_css_pg_resolution {
	unsigned int width;  /**< Width */
	unsigned int height; /**< Height */
};

/* Bayer order for input and output terminals */
enum ia_css_pg_io_bayer_order {
	IA_CSS_PG_IO_BAYER_ORDER_GRBG, /**< GRGRGRGRGR .. BGBGBGBGBG */
	IA_CSS_PG_IO_BAYER_ORDER_RGGB, /**< RGRGRGRGRG .. GBGBGBGBGB */
	IA_CSS_PG_IO_BAYER_ORDER_BGGR, /**< BGBGBGBGBG .. GRGRGRGRGR */
	IA_CSS_PG_IO_BAYER_ORDER_GBRG, /**< GBGBGBGBGB .. RGRGRGRGRG */
};

/* Frame header for input and output terminals */
struct ia_css_pg_frame_info {
	struct ia_css_pg_resolution res; /**< Frame resolution (valid data) */
	unsigned int padded_width; /**< stride of line in memory (in pixels) */
	enum ia_css_pg_io_frame_format format; /**< format of the frame data */
	unsigned int raw_bit_depth; /**< number of valid bits per pixel,
					 only valid for RAW bayer frames */
	enum ia_css_pg_io_bayer_order raw_bayer_order; /**< bayer order, only valid
						      for RAW bayer frames */
};

/* Plane description in a psys buffer */
struct ia_css_psys_buffer_plane_descr {
	uint32_t width;
	uint32_t stride;
	uint32_t height;
	uint32_t size;
	uint32_t offset;
};

/* Description of a psys buffer */
struct ia_css_psys_buffer_descr {
	uint32_t nof_planes;
	uint32_t size;
	enum ia_css_pg_io_frame_format format;
	struct ia_css_psys_buffer_plane_descr planes[PSYS_MAX_PLANES];
};

/* Get a buffer descriptor for the give frame info. */
extern void ia_css_psys_frameadapter_get_descr(
	struct ia_css_psys_buffer_descr *buffer_descr,
	const struct ia_css_pg_frame_info *info);

#endif /* __IA_CSS_PSYS_FRAME_ADAPTER_H__ */
