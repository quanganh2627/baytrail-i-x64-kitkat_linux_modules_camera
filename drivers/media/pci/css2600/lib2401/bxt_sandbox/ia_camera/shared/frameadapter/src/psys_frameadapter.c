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
#include "assert_support.h"
#include "platform_support.h"

void ia_css_psys_helper_framedesc_to_frameinfo(
	struct ia_css_frame_info *info,
	const ia_css_frame_descriptor_t *desc)
{
	assert(info != NULL && desc != NULL);
	memset(info, 0, sizeof(struct ia_css_frame_info));
	info->res.width = desc->size[IA_CSS_COL_DIMENSION];
	info->res.height = desc->size[IA_CSS_ROW_DIMENSION];
	info->padded_width = desc->stride[IA_CSS_COL_DIMENSION];
	info->format = desc->frame_format_type;
	info->raw_bit_depth = desc->bit_depth;
	/* info->raw_bayer_order = ? */
}
