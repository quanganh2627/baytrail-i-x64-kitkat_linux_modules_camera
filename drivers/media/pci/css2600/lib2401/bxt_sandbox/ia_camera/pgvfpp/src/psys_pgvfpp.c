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

#include "ia_css_pgvfpp.h"
#include "assert_support.h"
#include "gdc_device.h"
#include "sh_css_defs.h"
#include "vf/vf_1.0/ia_css_vf.host.h"
#include "isp/modes/interface/isp_const.h"
#include "ia_css_pgvfpp_param_internal.h"

/* TODO: This needs to come from manifest compiler */
#define PSYS_VFPPOPT_N_TERMINALS 		3
#define PSYS_VFPPOPT_N_PROGRAMS			1
#define PSYS_VFPPOPT_PROGRAM_GROUP_ID	SH_CSS_BINARY_ID_VF_PP_OPT

static int32_t
binary_grid_deci_factor_log2(int width, int height)
{
	int fact, fact1;
	fact = 5;
	while (ISP_BQ_GRID_WIDTH(width, fact - 1) <= SH_CSS_MAX_BQ_GRID_WIDTH &&
	       ISP_BQ_GRID_HEIGHT(height, fact - 1) <= SH_CSS_MAX_BQ_GRID_HEIGHT
	       && fact > 3)
		fact--;

	/* fact1 satisfies the specification of grid size. fact and fact1 is
	   not the same for some resolution (fact=4 and fact1=5 for 5mp). */
	if (width >= 2560)
		fact1 = 5;
	else if (width >= 1280)
		fact1 = 4;
	else
		fact1 = 3;
	return max(fact, fact1);
}

static uint32_t calc_deci_log_factor(
	ia_css_frame_descriptor_t *desc)
{
	/* TODO: Handle bds out info and fixed_s3a_deci_log when available. */
	unsigned int sc_3a_dis_width = desc->size[IA_CSS_COL_DIMENSION];
	unsigned int sc_3a_dis_padded_width = desc->stride[IA_CSS_COL_DIMENSION];
	unsigned int sc_3a_dis_height = desc->size[IA_CSS_ROW_DIMENSION];
	unsigned int s3a_isp_width;
	/*Silent the compiler*/
	(void)sc_3a_dis_width;
	s3a_isp_width = _ISP_S3A_ELEMS_ISP_WIDTH(sc_3a_dis_padded_width, 0);
	return binary_grid_deci_factor_log2(s3a_isp_width, sc_3a_dis_height);
}

size_t
ia_camera_sizeof_vfpp_opt_program_group_manifest(void)
{
	return ia_css_sizeof_program_group_manifest(PSYS_VFPPOPT_N_PROGRAMS,
		PSYS_VFPPOPT_N_TERMINALS);
}

ia_css_program_group_manifest_t *
ia_camera_vfpp_opt_program_group_manifest_get(void *blob)
{
	ia_css_program_group_manifest_t *prg_group_manifest;
	ia_css_program_manifest_t *prg_manifest;
	ia_css_terminal_manifest_t *terminal_manifest;
	uint32_t program_count;
	uint32_t terminal_count;

	assert(blob != NULL);

	prg_group_manifest = (ia_css_program_group_manifest_t *)blob;
	memset(prg_group_manifest, 0,
		ia_camera_sizeof_vfpp_opt_program_group_manifest());
	program_count = PSYS_VFPPOPT_N_PROGRAMS;
	terminal_count = PSYS_VFPPOPT_N_TERMINALS;
	ia_css_program_group_manifest_init(
		blob,
		program_count,
		terminal_count);

	prg_group_manifest->ID = PSYS_VFPPOPT_PROGRAM_GROUP_ID;

	/* Program manifest */
	prg_manifest = ia_css_program_group_manifest_get_program_manifest(
		prg_group_manifest, 0);
	prg_manifest->ID = PSYS_VFPPOPT_PROGRAM_GROUP_ID;
	prg_manifest->cell_type_id = VIED_NCI_VP_TYPE_ID;

	/* Input terminal */
	terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(
		prg_group_manifest, 0);
	terminal_manifest->terminal_type = IA_CSS_TERMINAL_TYPE_DATA_IN;
	terminal_manifest->frame_format_bitmap	= IA_CSS_FRAME_FORMAT_YUV_LINE;

#if 0 /* to be filled later */
	terminal_manifest->min_size[]			= {
	terminal_manifest->max_size[]			= {	obtain from binary headers	};
	terminal_manifest->min_fragment_size[]	= {
	terminal_manifest->max_fragment_size[]	= {
#endif

	/* Output terminal */
	terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(
		prg_group_manifest, 1);
	terminal_manifest->terminal_type = IA_CSS_TERMINAL_TYPE_DATA_OUT;
	terminal_manifest->frame_format_bitmap = IA_CSS_FRAME_FORMAT_YUV420;

	/* Cached Param terminal */
	terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(
		prg_group_manifest, 2);
	terminal_manifest->terminal_type = IA_CSS_TERMINAL_TYPE_PARAM_CACHED;

	return prg_group_manifest;
}

size_t
ia_camera_sizeof_vfpp_program_group_param(void)
{
	return ia_css_sizeof_program_group_param(PSYS_VFPPOPT_N_PROGRAMS, 1);
}

ia_css_program_group_param_t *
ia_camera_vfpp_program_group_param_get(void *blob)
{
	ia_css_program_group_param_t *prg_group_param;

	assert(blob != NULL);

	prg_group_param = (ia_css_program_group_param_t *)blob;
	memset(prg_group_param, 0, ia_camera_sizeof_vfpp_program_group_param());
	ia_css_program_group_param_init(blob,
		PSYS_VFPPOPT_N_PROGRAMS, 1);

	/* param->kernel_enable_bitmap =
		ENABLE_DS | ENABLE_OUTPUT | ENABLE_PARAMS; */

	return prg_group_param;
}

size_t
ia_camera_sizeof_vfpp_cached_param(void)
{
	return sizeof(ia_css_pgvfpp_param_t);
}

ia_css_pgvfpp_param_t *
ia_camera_vfpp_cached_param_get(
	void *blob,
	ia_css_frame_descriptor_t *in_desc,
	ia_css_frame_descriptor_t *out_desc)
{
	ia_css_pgvfpp_param_t *param = NULL;

	if(in_desc == NULL || out_desc == NULL) {
		return NULL;
	}

	assert(blob != NULL);
	param = (ia_css_pgvfpp_param_t *)blob;

	/* replace with relevant callbacks */
	if(param != NULL) {
		param->isp_pipe_version = 1;
		param->required_bds_factor = SH_CSS_BDS_FACTOR_1_00;
		param->dvs_frame_delay = IA_CSS_FRAME_DELAY_1;

		param->uds.curr_dx = HRT_GDC_N;
		param->uds.curr_dy = HRT_GDC_N;
		param->uds.xc = (uint16_t)in_desc->size[IA_CSS_COL_DIMENSION] / 2;
		param->uds.yc = (uint16_t)in_desc->size[IA_CSS_ROW_DIMENSION] / 2;

		param->isp_deci_log_factor =
			(uint8_t) calc_deci_log_factor(in_desc);

		assert(in_desc->frame_format_type == IA_CSS_FRAME_FORMAT_YUV_LINE);
		param->supported_pins[IA_CSS_FRAME_PIN_IN_FRAME].desc = *in_desc;
		param->supported_pins[IA_CSS_FRAME_PIN_IN_FRAME].enable = 1;
		param->effective_in_frame_res[IA_CSS_COL_DIMENSION] =
			in_desc->size[IA_CSS_COL_DIMENSION];
		param->effective_in_frame_res[IA_CSS_ROW_DIMENSION] =
			in_desc->size[IA_CSS_ROW_DIMENSION];

		/* vfppopt actually supports more formats. See SUPPORTED_OUTPUT_FORMATS
		 * from modes/vf_pp/opt/isp_defs_for_hive.h. TODO: Add support for more
		 * output formats.
		 *
		 * The only difference between vfppopt and vfppfull is the number of
		 * output formats supported. TODO: rename this module to vfpp and handle
		 * both cases here? */
		assert(out_desc->frame_format_type == IA_CSS_FRAME_FORMAT_YUV420);
		param->supported_pins[IA_CSS_FRAME_PIN_OUT_FRAME].desc = *out_desc;
		param->supported_pins[IA_CSS_FRAME_PIN_OUT_FRAME].enable = 1;
		param->internal_frame_desc = *out_desc;
	}

	return param;
}
