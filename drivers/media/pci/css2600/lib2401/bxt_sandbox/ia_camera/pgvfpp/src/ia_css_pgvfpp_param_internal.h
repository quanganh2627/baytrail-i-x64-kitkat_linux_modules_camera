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

#ifndef __IA_CSS_PG_VFPP_PARAM_INTERNAL_H__
#define __IA_CSS_PG_VFPP_PARAM_INTERNAL_H__

#include "ia_css_program_group.h"
#include "sh_css_uds.h"
#include "ia_css_buffer.h"

/* TODO: belongs to a helper. */
enum ia_css_frame_pin_type {
	IA_CSS_FRAME_PIN_CC_FRAME = 0,
	IA_CSS_FRAME_PIN_IN_FRAME,
	IA_CSS_FRAME_PIN_IN_REF_FRAME,
	IA_CSS_FRAME_PIN_IN_TNR_FRAME,
	IA_CSS_FRAME_PIN_OUT_FRAME,
	IA_CSS_FRAME_PIN_OUT_REF_FRAME,
	IA_CSS_FRAME_PIN_OUT_TNR_FRAME,
	IA_CSS_FRAME_PIN_OUT_VF_FRAME,
	IA_CSS_FRAME_PIN_EXTRA_REF_FRAME,
	IA_CSS_FRAME_PIN_NUM_TYPES
};

struct ia_css_supported_frame_pins {
	uint8_t enable;
	ia_css_frame_descriptor_t desc;
};

struct ia_css_pgvfpp_param {
	ia_css_dimension_t dvs_envelope[IA_CSS_N_DATA_DIMENSION];
	ia_css_dimension_t effective_in_frame_res[IA_CSS_N_DATA_DIMENSION];
	ia_css_frame_descriptor_t internal_frame_desc;
	uint8_t xnr;
	uint8_t enable_vf_output;
	uint8_t isp_vf_downscale_bits;
	uint8_t isp_deci_log_factor;
	uint8_t isp_pipe_version;
	uint32_t required_bds_factor;
	uint32_t dvs_frame_delay;
	uint32_t top_cropping;
	/* Add support for zoom config. */
	struct sh_css_uds_info uds;
	struct sh_css_crop_pos sp_out_crop_pos;
	struct ia_css_supported_frame_pins supported_pins[IA_CSS_FRAME_PIN_NUM_TYPES];
};

#endif /* __IA_CSS_PG_VFPP_PARAM_INTERNAL_H__ */
