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

#ifndef __IA_CSS_PSYS_VFPPOPT_PARAM_INTERNAL_H__
#define __IA_CSS_PSYS_VFPPOPT_PARAM_INTERNAL_H__

#include "ia_css_pg_info.h"
#include "sh_css_uds.h"
#include "ia_css_psys_frameadapter.h"

struct ia_css_supported_frames {
	uint8_t cc_frame;       /* continuous capture frame */
	uint8_t in_frame;	     /* input frame */
	uint8_t in_ref_frame;   /* reference input frame */
	uint8_t in_tnr_frame;   /* tnr input frame */
	uint8_t out_frame;      /* output frame */
	uint8_t out_ref_frame;  /* reference output frame */
	uint8_t out_tnr_frame;  /* tnr output frame */
	uint8_t out_vf_frame;   /* viewfinder output frame */
	uint8_t extra_ref_frame;    /* reference extra frame */
};


struct ia_css_vfppopt_param {
	uint8_t xnr;
	uint8_t enable_vf_output;
	uint8_t isp_vf_downscale_bits;
	uint8_t isp_deci_log_factor;
	uint8_t isp_pipe_version;
	uint32_t required_bds_factor;
	uint32_t dvs_frame_delay;
	uint32_t top_cropping;
	/* Add support for zoom config */
	struct sh_css_uds_info uds;
	struct ia_css_pg_resolution dvs_envelope;
	struct ia_css_pg_resolution effective_in_frame_res;
	struct sh_css_crop_pos sp_out_crop_pos;
	struct ia_css_pg_frame_info in_frame_info;
	struct ia_css_pg_frame_info out_frame_info;
	struct ia_css_pg_frame_info internal_frame_info;
	struct ia_css_supported_frames supported_frames;
};

#endif /* __IA_CSS_PSYS_VFPPOPT_PARAM_INTERNAL_H__ */
