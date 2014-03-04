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
#include "sh_css_internal.h"
#include "ia_css_memory_access.h"
#include "ia_css_pg_info.h"
#include "assert_support.h"
#include "ia_css_psys_vfppopt_param_internal.h"
#include "ia_css_psys_task_internal.h"
#include "ia_css_psys_frameadapter.h"
#include "ia_css_binary.h"
#include "ia_css_frame.h"
#include "ia_css_isp_param.h"
#include "ia_css_bufq_comm.h"

#include "memory_access.h"
#include "ia_css_psysapi.h" /*NOT_USED -silent the compiler*/

static struct ia_css_binary_xinfo *get_binary_xinfo(
	struct ia_css_psys_task *task)
{
	struct ia_css_binary_xinfo *all_binaries = NULL;
	struct ia_css_binary_xinfo *binary_xinfo = NULL;

	ia_css_binary_get_isp_binaries(&all_binaries, NULL);
	assert(all_binaries != NULL);
	binary_xinfo = &all_binaries[task->pg_info->program_info->program_id];
	assert(binary_xinfo != NULL);

	return binary_xinfo;
}

static void
copy_pgbuf_to_spframe(
	struct sh_css_sp_stage *sp_stage,
	const struct ia_css_pg_frame_info *frame_info,
	struct ia_css_frame_sp *sp_frame_out,
	const struct ia_css_psys_buffer *buf_in,
	enum ia_css_buffer_type id)
{
	struct ia_css_psys_buffer_descr buffer_descr;

	assert(buf_in && buf_in->nof_planes > 0);
	assert(sp_stage && sp_frame_out && frame_info);

	sp_stage->frames.static_frame_data[id] =
		buf_in->planes[0].firmware_address;

	ia_css_psys_frameadapter_get_descr(
		&buffer_descr, ((struct ia_css_pg_frame_info *)frame_info));
	switch (frame_info->format) {
	case IA_CSS_FRAME_FORMAT_YUV_LINE:
		assert(buffer_descr.nof_planes == 1);
		sp_frame_out->planes.yuyv.offset = buffer_descr.planes[0].offset;
		break;
	case IA_CSS_FRAME_FORMAT_YUV420:
		assert(buffer_descr.nof_planes == 3);
		sp_frame_out->planes.yuv.y.offset = buffer_descr.planes[0].offset;
		sp_frame_out->planes.yuv.u.offset = buffer_descr.planes[1].offset;
		sp_frame_out->planes.yuv.v.offset = buffer_descr.planes[2].offset;
		break;
	default:
		assert(0);
		break;
	}
}

static void store_spframes_in_spstage(
	struct sh_css_sp_stage *sp_stage,
	struct ia_css_psys_task *task,
	const struct ia_css_vfppopt_param *params)
{
	uint32_t i;
	struct ia_css_pg_info *pg_info;
	struct ia_css_pg_terminal *terminal;

	assert(task && task->pg_info);
	assert(sp_stage && params);

	pg_info = task->pg_info;
	for (i = 0; i < pg_info->terminal_list.no_of_terminals; i++) {
		terminal = &pg_info->terminal_list.terminals[i];
		if(terminal->descr.type == IA_CSS_PG_TERMINAL_TYPE_INPUT) {
			copy_pgbuf_to_spframe(sp_stage,
				&params->in_frame_info,
				&sp_stage->frames.in,
				task->terminals[terminal->descr.index],
				IA_CSS_BUFFER_TYPE_INPUT_FRAME);
		} else if(terminal->descr.type == IA_CSS_PG_TERMINAL_TYPE_OUTPUT) {
			copy_pgbuf_to_spframe(sp_stage,
				&params->out_frame_info,
				/* using port 0 only for now. */
				&sp_stage->frames.out[0],
				task->terminals[terminal->descr.index],
				IA_CSS_BUFFER_TYPE_OUTPUT_FRAME);
		}
	}
}

static void
psys_pgframeinfo_to_spframeinfo(
	struct ia_css_frame_sp_info *sp,
	const struct ia_css_pg_frame_info *host)
{

	sp->width	      = (uint16_t)host->res.width;
	sp->height	      = (uint16_t)host->res.height;
	sp->padded_width    = (uint16_t)host->padded_width;
	sp->format	      = (unsigned char )host->format;
	sp->raw_bit_depth   = (unsigned char )host->raw_bit_depth;
	sp->raw_bayer_order = host->raw_bayer_order;
}

static void
psys_pgframeinfo_to_cssframeinfo(
	struct ia_css_frame_info *css,
	const struct ia_css_pg_frame_info *host)
{

	css->res.width	      = (uint16_t)host->res.width;
	css->res.height	      = (uint16_t)host->res.height;
	css->padded_width    = (uint16_t)host->padded_width;
	css->format	      = (unsigned char )host->format;
	css->raw_bit_depth   = (unsigned char )host->raw_bit_depth;
	css->raw_bayer_order = host->raw_bayer_order;
}

static void construct_sppipeline(
	struct sh_css_sp_pipeline *sp_pipeline,
	hrt_vaddress sp_stage_addr,
	uint32_t required_bds_factor,
	uint32_t dvs_frame_delay)
{
	struct sh_css_sp_pipeline *this_pipeline = sp_pipeline;
	NOT_USED(dvs_frame_delay);
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
	struct ia_css_psys_task *task,
	struct sh_css_sp_stage *sp_stage,
	hrt_vaddress isp_stage_addr,
	hrt_vaddress program_addr,
	hrt_vaddress param_addr,
	const struct ia_css_binary_info *binary_info,
	const struct ia_css_vfppopt_param *params)
{
	struct sh_css_sp_stage *this_stage = sp_stage;

	assert(this_stage != NULL);

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
	this_stage->dvs_envelope.width = params->dvs_envelope.width;
	this_stage->dvs_envelope.height = params->dvs_envelope.height;
	this_stage->sp_out_crop_pos = params->sp_out_crop_pos;
	this_stage->frames.effective_in_res.width =
		params->effective_in_frame_res.width;
	this_stage->frames.effective_in_res.height =
		params->effective_in_frame_res.height;

	psys_pgframeinfo_to_spframeinfo(&this_stage->frames.in.info,
		&params->in_frame_info);
	psys_pgframeinfo_to_spframeinfo(&this_stage->frames.out[0].info,
		&params->out_frame_info);
	psys_pgframeinfo_to_spframeinfo(&this_stage->frames.internal_frame_info,
		&params->internal_frame_info);

	this_stage->enable.sdis = binary_info->enable.dis;
	this_stage->enable.s3a = binary_info->enable.s3a;

	/* ASK: should this also come from parameters */
	this_stage->num_stripes = binary_info->num_stripes;

	store_spframes_in_spstage(
		sp_stage,
		task,
		params);

	return;
}

static void construct_ispstage(
	struct ia_css_psys_task *task,
	struct sh_css_isp_stage *isp_stage,
	const struct ia_css_blob_info *blob_info,
	const char *binary_name,
	const struct ia_css_binary_info *binary_info,
	const struct ia_css_vfppopt_param *params)
{
	struct sh_css_isp_stage *this_isp_stage = isp_stage;
	struct ia_css_isp_param_css_segments mem_if;
	struct ia_css_binary_xinfo *binary_xinfo = NULL;
	struct ia_css_binary *binary = &task->binary;
	struct ia_css_frame_info in_info, out_info;
	const struct ia_css_frame_info *ptr_out_info[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
	struct ia_css_resolution dvs_env;
	enum ia_css_err err;
	uint32_t i = 0;

	assert(task != NULL);
	assert(blob_info != NULL);
	assert(binary_info != NULL);
	assert(this_isp_stage != NULL);
	assert(binary != NULL);

	this_isp_stage->blob_info = *blob_info;
	this_isp_stage->binary_info = *binary_info;

	if(binary_name) {
		memcpy(this_isp_stage->binary_name, binary_name,
			strlen(binary_name)+1);
	}

	/* TODO Move this to user space? */
	memset(&mem_if, 0, sizeof(struct ia_css_isp_param_css_segments));
	binary_xinfo = get_binary_xinfo(task);
	dvs_env.width = params->dvs_envelope.width;
	dvs_env.height = params->dvs_envelope.height;
	psys_pgframeinfo_to_cssframeinfo(&in_info, &params->in_frame_info);
	psys_pgframeinfo_to_cssframeinfo(&out_info, &params->out_frame_info);

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

	/* No late binding of parameters. ASK: Is this ok? CSS does not do it. */
	err = ia_css_isp_param_copy_isp_mem_if_to_ddr(
		&binary->css_params,
		&binary->mem_params,
		IA_CSS_PARAM_CLASS_PARAM);
	assert(err == IA_CSS_SUCCESS);

	this_isp_stage->mem_initializers = mem_if;

	return;
}

static hrt_vaddress get_param_addr(
	struct ia_css_psys_task *task)
{
	unsigned int i;
	struct ia_css_pg_terminal *terminal;
	struct ia_css_psys_buffer *buf;
	for (i = 0; i < task->pg_info->terminal_list.no_of_terminals; i++) {
		terminal = &task->pg_info->terminal_list.terminals[i];
		if(terminal->descr.type == IA_CSS_PG_TERMINAL_TYPE_PARAM) {
			buf = task->terminals[terminal->descr.index];
			break;
		}
	}
	assert(buf && (buf->nof_planes == 1) && buf->planes);
	return (hrt_vaddress)buf->planes[0].firmware_address;
}

void ia_css_psys_sppipeline_create(
	struct ia_css_psys_task *task)
{
	struct ia_css_binary_xinfo *binary_xinfo = NULL;
	struct ia_css_vfppopt_param param;
	hrt_vaddress isp_stage_addr, sp_stage_addr, task_fw_addr, param_addr,
		cmd_ptr;

	task_fw_addr = (hrt_vaddress)(task->task_buffer.firmware_address);
	binary_xinfo = get_binary_xinfo(task);

	param_addr = get_param_addr(task);
	mmgr_load(param_addr, &param, sizeof(struct ia_css_vfppopt_param));

	/* Create ISP stage */
	construct_ispstage(
		task,
		&task->cmd.isp_stage,
		&binary_xinfo->blob->header.blob,
		binary_xinfo->blob->name,
		&binary_xinfo->sp,
		&param);
	isp_stage_addr =
		(hrt_vaddress)&((struct ia_css_psys_task *)task_fw_addr)->cmd.isp_stage;

	/* Create SP stage */
	param_addr =
		(hrt_vaddress) &((struct ia_css_psys_task *)task_fw_addr)->cmd.params;
	construct_spstage(
		task,
		&task->cmd.sp_stage,
		isp_stage_addr,
		binary_xinfo->xmem_addr,
		param_addr,
		&binary_xinfo->sp,
		&param);

	sp_stage_addr =
		(hrt_vaddress)&((struct ia_css_psys_task *)task_fw_addr)->cmd.sp_stage;
	/* Create SP pipeline */
	construct_sppipeline(
		&task->cmd.sp_pipeline,
		sp_stage_addr,
		param.required_bds_factor,
		param.dvs_frame_delay);

	/* TODO: stores params in the command */
	task->cmd.uds_params[0].uds = param.uds;
	task->cmd.uds_params[0].crop_pos = param.sp_out_crop_pos;
	task_fw_addr = (hrt_vaddress) task->task_buffer.firmware_address;
	cmd_ptr = (hrt_vaddress) &((struct ia_css_psys_task *)task_fw_addr)->cmd;
	task->cmd.params.isp_param =
		(hrt_vaddress) &((struct ia_css_psysapi_cmd *)cmd_ptr)->uds_params[0];
}
