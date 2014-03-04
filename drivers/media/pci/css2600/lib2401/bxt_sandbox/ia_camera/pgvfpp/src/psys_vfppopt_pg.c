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

#include "ia_css_psys_vfppopt_pg.h"
#include "gdc_device.h"
#include "assert_support.h"
#include "ia_css_psys_vfppopt_param_internal.h"
#include "vf/vf_1.0/ia_css_vf.host.h"
#include "sh_css_defs.h"
#include "ia_css_psys_frameadapter.h"
#include "ia_css_psysapi.h" /*NOT_USED to silent the compiler*/

#define PSYS_VFPPOPT_N_TERMINALS 		3
#define PSYS_VFPPOPT_N_PROGRAMS			1
#define PSYS_VFPPOPT_N_INPUT_FORMATS	1
#define PSYS_VFPPOPT_N_OUTPUT_FORMATS	1
#define PSYS_VFPPOPT_PROGRAM_ID			2

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

uint32_t calc_deci_log_factor(
	struct ia_css_pg_frame_info *in_frame_info)
{
	/* TODO: Handle bds out info and fixed_s3a_deci_log when available. */
	unsigned int sc_3a_dis_width = in_frame_info->res.width;
	unsigned int sc_3a_dis_padded_width = in_frame_info->padded_width;
	unsigned int sc_3a_dis_height = in_frame_info->res.height;
	unsigned int s3a_isp_width;
	/*Silent the compiler*/
	NOT_USED(sc_3a_dis_width);
	s3a_isp_width = _ISP_S3A_ELEMS_ISP_WIDTH(sc_3a_dis_padded_width, 0);
	return binary_grid_deci_factor_log2(s3a_isp_width, sc_3a_dis_height);
}

uint32_t ia_css_vfppopt_pg_get_param_size(void)
{
	return sizeof(struct ia_css_vfppopt_param);
}


void ia_css_vfppopt_pg_get_param(
	void *param_buffer,
	struct ia_css_pg_frame_info *in_frame_info,
	struct ia_css_pg_frame_info *out_frame_info)
{
	struct ia_css_vfppopt_param *param =
		(struct ia_css_vfppopt_param *)param_buffer;

	assert(param_buffer != NULL);
	assert(in_frame_info != NULL);
	assert(out_frame_info != NULL);

	memset(param, 0, sizeof(struct ia_css_vfppopt_param));

	param->isp_pipe_version = 1;
	param->required_bds_factor = SH_CSS_BDS_FACTOR_1_00;
	param->dvs_frame_delay = IA_CSS_FRAME_DELAY_1;

	param->uds.curr_dx = HRT_GDC_N;
	param->uds.curr_dy = HRT_GDC_N;
	param->uds.xc = (uint16_t)in_frame_info->res.width / 2;
	param->uds.yc = (uint16_t)in_frame_info->res.height / 2;

	param->isp_deci_log_factor =
		(uint8_t) calc_deci_log_factor(in_frame_info);

	in_frame_info->format = IA_CSS_PG_IO_FRAME_FORMAT_YUV_LINE;
	param->in_frame_info = *in_frame_info;
	param->supported_frames.in_frame = 1;
	param->effective_in_frame_res.width = param->in_frame_info.res.width;
	param->effective_in_frame_res.height = param->in_frame_info.res.height;

	/* vfppopt actually supports more formats. See SUPPORTED_OUTPUT_FORMATS
	 * from modes/vf_pp/opt/isp_defs_for_hive.h. TODO: Add support for more
	 * output formats.
	 *
	 * The only difference between vfppopt and vfppfull is the number of output
	 * formats supported. TODO: rename this module to vfpp and handle both cases
	 * here? */
	out_frame_info->format = IA_CSS_PG_IO_FRAME_FORMAT_YUV420;
	param->out_frame_info = *out_frame_info;
	param->internal_frame_info = *out_frame_info;
	param->supported_frames.out_frame = 1;

	return;
}


uint32_t ia_css_vfppopt_pg_get_num_terminals(void)
{
	return PSYS_VFPPOPT_N_TERMINALS;
}

uint32_t ia_css_vfppopt_pg_get_num_programs(void)
{
	return PSYS_VFPPOPT_N_PROGRAMS;
}

uint32_t ia_css_vfppopt_pg_get_num_io_formats(uint8_t input)
{
	return input?(PSYS_VFPPOPT_N_INPUT_FORMATS):(PSYS_VFPPOPT_N_OUTPUT_FORMATS);
}

uint32_t ia_css_vfppopt_pg_get_size()
{
	uint32_t size;
	size = sizeof(struct ia_css_pg_info);
	size += PSYS_VFPPOPT_N_TERMINALS * sizeof(struct ia_css_pg_terminal);
	size += PSYS_VFPPOPT_N_PROGRAMS * sizeof(struct ia_css_program_info);
	/* TODO: Support multiple input/output
	terminal attributes */
	return size;
}

void ia_css_vfppopt_pg_get_pginfo(struct ia_css_pg_info *pg_info)
{
	unsigned int i;
	struct ia_css_pg_terminal *terminal;
	uint8_t *pg_info_blob = (uint8_t*) pg_info;

	assert(pg_info);

	pg_info->terminal_list.terminals = (struct ia_css_pg_terminal *)
		(pg_info_blob + sizeof(struct ia_css_pg_info));
	pg_info->program_info = (struct ia_css_program_info *)
		(pg_info_blob + sizeof(struct ia_css_pg_info) +
		PSYS_VFPPOPT_N_TERMINALS * sizeof(struct ia_css_pg_terminal));

	pg_info->no_of_programs = PSYS_VFPPOPT_N_PROGRAMS;
	pg_info->terminal_list.no_of_terminals = PSYS_VFPPOPT_N_TERMINALS;
	pg_info->program_info->program_id = PSYS_VFPPOPT_PROGRAM_ID;
	/* Number the terminals */
	for(i = 0 ; i < PSYS_VFPPOPT_N_TERMINALS ; i++) {
		terminal = &pg_info->terminal_list.terminals[i];
		terminal->descr.index = i;
	}

	/* Input terminals */
	terminal = &pg_info->terminal_list.terminals[0];
	terminal->descr.type = IA_CSS_PG_TERMINAL_TYPE_INPUT;
	terminal->descr.snooped = 0;
	/*terminal->attr.input_terminal_attr.num_frame_formats =
		PSYS_VFPPOPT_N_INPUT_FORMATS;*/
	terminal->attr.input_terminal_attr.format =
		IA_CSS_PG_IO_FRAME_FORMAT_YUV_LINE;

	/* Output terminals */
	terminal = &pg_info->terminal_list.terminals[1];
	terminal->descr.type = IA_CSS_PG_TERMINAL_TYPE_OUTPUT;
	terminal->descr.snooped = 1;
	/*terminal->attr.input_terminal_attr.num_frame_formats =
		PSYS_VFPPOPT_N_OUTPUT_FORMATS;*/
	terminal->attr.input_terminal_attr.format =
		IA_CSS_PG_IO_FRAME_FORMAT_YUV420;

	/* Param terminals */
	terminal = &pg_info->terminal_list.terminals[2];
	terminal->descr.type = IA_CSS_PG_TERMINAL_TYPE_PARAM;
	terminal->descr.snooped = 1;
}

