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

#include "ia_css_psys_sppipeline.h"
#include "ia_css_psys_cmd_comm.h"
#include "sh_css_internal.h"
#include "ia_css_memory_access.h"
#include "assert_support.h"
#include "ia_css_pgvfpp_param_internal.h"
#include "ia_css_psys_frameadapter.h"
#include "ia_css_program_group.h"
#include "ia_css_program_group_internal.h"
#include "ia_css_process_group.h"
#include "ia_css_process_group_internal.h"
#include "ia_css_binary.h"
#include "ia_css_frame.h"
#include "ia_css_isp_param.h"
#include "ia_css_bufq_comm.h"

#include "memory_access.h"

#define IA_CSS_INCLUDE_CONFIGURATIONS
#include "ia_css_isp_configs.h"
#define IA_CSS_INCLUDE_STATES
#include "ia_css_isp_states.h"

static struct ia_css_binary_xinfo *get_binary_xinfo(
	const ia_css_process_group_t *process_group)
{
	struct ia_css_binary_xinfo *all_binaries = NULL;
	struct ia_css_binary_xinfo *binary_xinfo = NULL;
	uint32_t pgid, no_of_binaries, i;

	assert(process_group != NULL);

	pgid = (uint32_t) ia_css_process_group_get_program_group_ID(process_group);
	ia_css_binary_get_isp_binaries(&all_binaries, &no_of_binaries);
	assert(all_binaries != NULL);

	for(i = 0; i < no_of_binaries; i++) {
		binary_xinfo = &all_binaries[i];
		assert(binary_xinfo != NULL);
		if(binary_xinfo->sp.id == pgid)
			break;
	}

	return binary_xinfo;
}

static void
copy_buffer_to_spframe(
	struct sh_css_sp_stage *sp_stage,
	struct ia_css_frame_sp *sp_frame_out,
	struct ia_css_frame *frame_in,
	enum ia_css_buffer_type type)
{
	assert(sp_stage != NULL && sp_frame_out != NULL && frame_in != NULL);
	/* No dynamic frames. */
	assert(frame_in->dynamic_data_index == -1);

	sp_stage->frames.static_frame_data[type] = frame_in->data;
	sp_stage->frames.buf_type[type] = frame_in->buf_type;
	ia_css_frame_info_to_frame_sp_info(&sp_frame_out->info, &frame_in->info);

	switch (frame_in->info.format) {
	case IA_CSS_FRAME_FORMAT_RAW_PACKED:
	case IA_CSS_FRAME_FORMAT_RAW:
		sp_frame_out->planes.raw.offset = frame_in->planes.raw.offset;
		break;
	case IA_CSS_FRAME_FORMAT_RGB565:
	case IA_CSS_FRAME_FORMAT_RGBA888:
		sp_frame_out->planes.rgb.offset = frame_in->planes.rgb.offset;
		break;
	case IA_CSS_FRAME_FORMAT_PLANAR_RGB888:
		sp_frame_out->planes.planar_rgb.r.offset =
			frame_in->planes.planar_rgb.r.offset;
		sp_frame_out->planes.planar_rgb.g.offset =
			frame_in->planes.planar_rgb.g.offset;
		sp_frame_out->planes.planar_rgb.b.offset =
			frame_in->planes.planar_rgb.b.offset;
		break;
	case IA_CSS_FRAME_FORMAT_YUYV:
	case IA_CSS_FRAME_FORMAT_UYVY:
	case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8:
	case IA_CSS_FRAME_FORMAT_YUV_LINE:
		sp_frame_out->planes.yuyv.offset = frame_in->planes.yuyv.offset;
		break;
	case IA_CSS_FRAME_FORMAT_NV11:
	case IA_CSS_FRAME_FORMAT_NV12:
	case IA_CSS_FRAME_FORMAT_NV21:
	case IA_CSS_FRAME_FORMAT_NV16:
	case IA_CSS_FRAME_FORMAT_NV61:
		sp_frame_out->planes.nv.y.offset =
			frame_in->planes.nv.y.offset;
		sp_frame_out->planes.nv.uv.offset =
			frame_in->planes.nv.uv.offset;
		break;
	case IA_CSS_FRAME_FORMAT_YUV420:
	case IA_CSS_FRAME_FORMAT_YUV422:
	case IA_CSS_FRAME_FORMAT_YUV444:
	case IA_CSS_FRAME_FORMAT_YUV420_16:
	case IA_CSS_FRAME_FORMAT_YUV422_16:
	case IA_CSS_FRAME_FORMAT_YV12:
	case IA_CSS_FRAME_FORMAT_YV16:
		sp_frame_out->planes.yuv.y.offset =
			frame_in->planes.yuv.y.offset;
		sp_frame_out->planes.yuv.u.offset =
			frame_in->planes.yuv.u.offset;
		sp_frame_out->planes.yuv.v.offset =
			frame_in->planes.yuv.v.offset;
		break;
	case IA_CSS_FRAME_FORMAT_QPLANE6:
		sp_frame_out->planes.plane6.r.offset =
			frame_in->planes.plane6.r.offset;
		sp_frame_out->planes.plane6.r_at_b.offset =
			frame_in->planes.plane6.r_at_b.offset;
		sp_frame_out->planes.plane6.gr.offset =
			frame_in->planes.plane6.gr.offset;
		sp_frame_out->planes.plane6.gb.offset =
			frame_in->planes.plane6.gb.offset;
		sp_frame_out->planes.plane6.b.offset =
			frame_in->planes.plane6.b.offset;
		sp_frame_out->planes.plane6.b_at_r.offset =
			frame_in->planes.plane6.b_at_r.offset;
		break;
	case IA_CSS_FRAME_FORMAT_BINARY_8:
		sp_frame_out->planes.binary.data.offset =
			frame_in->planes.binary.data.offset;
		break;
	default:
		/* This should not happen, but in case it does,
		 * nullify the planes
		 */
		memset(&sp_frame_out->planes, 0, sizeof(sp_frame_out->planes));
		break;
	}
}

static hrt_vaddress get_param_addr(
	ia_css_process_group_t *process_group)
{
	uint32_t i, terminal_count;
	ia_css_terminal_type_t type;
	ia_css_terminal_t *terminal;
	struct ia_css_frame *frame;

	assert(process_group != NULL);

	terminal_count = ia_css_process_group_get_terminal_count(process_group);
	for (i = 0; i < terminal_count; i++) {
		terminal = ia_css_process_group_get_terminal(process_group, i);
		if(terminal != NULL) {
			type = ia_css_terminal_get_type(terminal);
			if(type == IA_CSS_TERMINAL_TYPE_PARAM_CACHED) {
				ia_css_psys_frame_t *psys_frame;
				/* TODO: Terminals must have generic buffers, not frames. */
				/* TODO: check for num planes to be 1 if possible */
				psys_frame = ia_css_terminal_get_frame(terminal);
				assert(psys_frame != NULL);
				frame = &psys_frame->css_frame;
				return (hrt_vaddress) frame->data;
			}
		}
	}

	return 0;
}

static void store_spframes_in_spstage(
	struct sh_css_sp_stage *sp_stage,
	const ia_css_process_group_t *process_group)
{
	uint32_t i, terminal_count;
	ia_css_terminal_type_t type;
	ia_css_terminal_t *terminal;

	assert(sp_stage);
	assert(process_group);

	terminal_count = ia_css_process_group_get_terminal_count(process_group);
	for (i = 0; i < terminal_count; i++) {
		ia_css_frame_t *frame;
		terminal = ia_css_process_group_get_terminal(process_group, i); 
		if(terminal != NULL) {
			ia_css_psys_frame_t *psys_frame;
			type = ia_css_terminal_get_type(terminal);
			psys_frame = ia_css_terminal_get_frame(terminal);
			assert(psys_frame != NULL);
			frame = &psys_frame->css_frame;
			if(type == IA_CSS_TERMINAL_TYPE_DATA_IN) {
				/* @conv@ Assuming css frame at terminal, otherwise
				 * conversions are needed. */
				copy_buffer_to_spframe(sp_stage, 
					&sp_stage->frames.in,
					frame,
					IA_CSS_BUFFER_TYPE_INPUT_FRAME);
			} else if(type == IA_CSS_TERMINAL_TYPE_DATA_OUT) {
				/* @conv@ Assuming css frame at terminal, otherwise
				 * conversions are needed. */
				copy_buffer_to_spframe(sp_stage,
					/* using port 0 only for now. */
					&sp_stage->frames.out[0],
					frame,	
					IA_CSS_BUFFER_TYPE_OUTPUT_FRAME);
			}
		}
	}
}

static void construct_sppipeline(
	struct sh_css_sp_pipeline *sp_pipeline,
	hrt_vaddress sp_stage_addr,
	uint32_t required_bds_factor,
	uint32_t dvs_frame_delay)
{
	struct sh_css_sp_pipeline *this_pipeline = sp_pipeline;
	(void)dvs_frame_delay;
	assert(this_pipeline != NULL);

	memset(this_pipeline, 0 , sizeof(struct sh_css_sp_pipeline));
	this_pipeline->num_stages = 1;
	SH_CSS_PIPE_PORT_CONFIG_SET(this_pipeline->inout_port_config,
		(uint8_t)SH_CSS_PORT_INPUT,
		(uint8_t)SH_CSS_HOST_TYPE,1);
	SH_CSS_PIPE_PORT_CONFIG_SET(this_pipeline->inout_port_config,
		(uint8_t)SH_CSS_PORT_OUTPUT,
		(uint8_t)SH_CSS_HOST_TYPE,1);
	this_pipeline->required_bds_factor = required_bds_factor;
	this_pipeline->sp_stage_addr[0] = sp_stage_addr;
}

static void construct_spstage(
	ia_css_process_group_t *process_group,
	struct sh_css_sp_stage *sp_stage,
	hrt_vaddress isp_stage_addr,
	hrt_vaddress program_addr,
	hrt_vaddress param_addr,
	const struct ia_css_binary_info *binary_info,
	const struct ia_css_pgvfpp_param *params)
{
	struct sh_css_sp_stage *this_stage = sp_stage;
	struct ia_css_frame_info internal_frame_info;

	assert(this_stage != NULL);
	assert(process_group != NULL);
	assert(binary_info != NULL && params != NULL);

	memset(this_stage, 0 , sizeof(struct sh_css_sp_stage));
	this_stage->if_config_index = SH_CSS_IF_CONFIG_NOT_NEEDED;
	this_stage->stage_type = SH_CSS_ISP_STAGE_TYPE;
	this_stage->isp_stage_addr = isp_stage_addr;
	this_stage->xmem_bin_addr = program_addr;
	this_stage->xmem_map_addr = param_addr;

	this_stage->sp_enable_xnr = params->xnr;
	this_stage->top_cropping = params->top_cropping;
	this_stage->enable.vf_output = params->enable_vf_output;
	this_stage->isp_pipe_version = params->isp_pipe_version;
	this_stage->isp_deci_log_factor = params->isp_deci_log_factor;
	this_stage->isp_vf_downscale_bits = params->isp_vf_downscale_bits;
	this_stage->uds = params->uds;
	this_stage->dvs_envelope.width = params->dvs_envelope[IA_CSS_COL_DIMENSION];
	this_stage->dvs_envelope.height =
		params->dvs_envelope[IA_CSS_ROW_DIMENSION];
	this_stage->sp_out_crop_pos = params->sp_out_crop_pos;
	this_stage->frames.effective_in_res.width =
		params->effective_in_frame_res[IA_CSS_COL_DIMENSION];
	this_stage->frames.effective_in_res.height =
		params->effective_in_frame_res[IA_CSS_ROW_DIMENSION];

	ia_css_psys_helper_framedesc_to_frameinfo(&internal_frame_info,
		&params->internal_frame_desc);
	ia_css_frame_info_to_frame_sp_info(&this_stage->frames.internal_frame_info,
		&internal_frame_info);

	this_stage->enable.sdis = binary_info->enable.dis;
	this_stage->enable.s3a = binary_info->enable.s3a;

	/* ASK: should this also come from parameters */
	this_stage->num_stripes = binary_info->num_stripes;

	store_spframes_in_spstage(
		sp_stage,
		process_group);

	return;
}

static void construct_ispstage(
	struct sh_css_isp_stage *isp_stage,
	struct ia_css_binary *binary,
	struct ia_css_binary_xinfo *binary_xinfo,
	const struct ia_css_pgvfpp_param *params)
{
	struct sh_css_isp_stage *this_isp_stage = isp_stage;
	struct ia_css_isp_param_css_segments mem_if;
	struct ia_css_frame_info in_info, out_info;
	const struct ia_css_frame_info *ptr_out_info[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
	struct ia_css_resolution dvs_env;
	enum ia_css_err err;
	uint32_t i = 0;

	assert(this_isp_stage != NULL);
	assert(binary != NULL);
	assert(binary_xinfo != NULL);
	assert(params != NULL);

	this_isp_stage->blob_info = binary_xinfo->blob->header.blob;
	this_isp_stage->binary_info = binary_xinfo->sp;

	if(binary_xinfo->blob->name) {
		memcpy(this_isp_stage->binary_name, binary_xinfo->blob->name,
			strlen(binary_xinfo->blob->name)+1);
	}

	/* TODO Move this to user space? */
	memset(&mem_if, 0, sizeof(struct ia_css_isp_param_css_segments));
	dvs_env.width = params->dvs_envelope[IA_CSS_COL_DIMENSION];
	dvs_env.height = params->dvs_envelope[IA_CSS_ROW_DIMENSION];

	/* TODO: Enable other pins */
	ia_css_psys_helper_framedesc_to_frameinfo(&in_info,
		&params->supported_pins[IA_CSS_FRAME_PIN_IN_FRAME].desc);
	ia_css_psys_helper_framedesc_to_frameinfo(&out_info,
		&params->supported_pins[IA_CSS_FRAME_PIN_OUT_FRAME].desc);

	ptr_out_info[i] = &out_info;
	for (i = 1; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
		ptr_out_info[i] = NULL;
	}
	/* isp params are allocated here. We only need
	 * ia_css_isp_param_allocate_isp_parameters but some of the isp host
	 * configure functions take a binary, so we might as well use it. */
	ia_css_binary_fill_info(binary_xinfo, false, false,
		0, &in_info, NULL, ptr_out_info, NULL,
		binary, &dvs_env, -1, false);
	ia_css_init_memory_interface(&mem_if, &binary->mem_params, &binary->css_params);

	/* Configure ISP via ISP specific host side functions.
	TODO: Add other host configure's here. */
	ia_css_iterator_configure (binary, &in_info);
	ia_css_output0_configure(binary, &out_info);
	ia_css_output_configure(binary, &out_info);

	for (i = 0; i < IA_CSS_NUM_STATE_IDS; i++) {
		ia_css_kernel_init_state[i](binary);
	}

	err = ia_css_isp_param_copy_isp_mem_if_to_ddr(
		&binary->css_params,
		&binary->mem_params,
		IA_CSS_PARAM_CLASS_CONFIG);
	assert(err == IA_CSS_SUCCESS);

	err = ia_css_isp_param_copy_isp_mem_if_to_ddr(
		&binary->css_params,
		&binary->mem_params,
		IA_CSS_PARAM_CLASS_STATE);
	assert(err == IA_CSS_SUCCESS);

	this_isp_stage->mem_initializers = mem_if;

	return;
}

hrt_vaddress ia_css_psys_sppipeline_cmd_create(
	ia_css_process_group_t *process_group)
{
	struct ia_css_binary_xinfo *binary_xinfo = NULL;
	struct ia_css_pgvfpp_param param;
	hrt_vaddress isp_stage_addr, sp_stage_addr, param_addr,
		cmd_ptr;
	ia_css_psysapi_cmd_t temp_cmd;
	struct ia_css_binary binary;

	assert(process_group != NULL);

	memset((void*) &temp_cmd, 0, sizeof(ia_css_psysapi_cmd_t));
	cmd_ptr =
		mmgr_malloc(sizeof(ia_css_psysapi_cmd_t));

	binary_xinfo = get_binary_xinfo(process_group);
	assert(binary_xinfo != NULL);

	param_addr = get_param_addr(process_group);
	mmgr_load(param_addr, &param, sizeof(struct ia_css_pgvfpp_param));

	/* Create ISP stage */
	construct_ispstage(
		&temp_cmd.isp_stage,
		&binary,
		binary_xinfo,
		&param);
	isp_stage_addr =
		(hrt_vaddress)&((ia_css_psysapi_cmd_t *)cmd_ptr)->isp_stage;

	/* Create SP stage */
	param_addr =
		(hrt_vaddress) &((ia_css_psysapi_cmd_t *)cmd_ptr)->isp_param_info;
	construct_spstage(
		process_group,
		&temp_cmd.sp_stage,
		isp_stage_addr,
		binary_xinfo->xmem_addr,
		param_addr,
		&binary_xinfo->sp,
		&param);

	sp_stage_addr =
		(hrt_vaddress)&((ia_css_psysapi_cmd_t*)cmd_ptr)->sp_stage;
	/* Create SP pipeline */
	construct_sppipeline(
		&temp_cmd.sp_pipeline,
		sp_stage_addr,
		param.required_bds_factor,
		param.dvs_frame_delay);

	temp_cmd.uds_params[0].uds = param.uds;
	temp_cmd.uds_params[0].crop_pos = param.sp_out_crop_pos;
	temp_cmd.isp_param_info.mem_map.isp_param =
		(hrt_vaddress) &((ia_css_psysapi_cmd_t *)cmd_ptr)->uds_params[0];
	temp_cmd.cookie = (void *) process_group;

	mmgr_store(cmd_ptr,
		&temp_cmd,
		sizeof(ia_css_psysapi_cmd_t));

	return cmd_ptr;
}

void ia_css_psys_sppipeline_cmd_free(hrt_vaddress cmd)
{
	if(cmd)
		mmgr_free(cmd);
}

