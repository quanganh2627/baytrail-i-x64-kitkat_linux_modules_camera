/* Release Version: ci_master_20131001_0952 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2013 Intel Corporation. All Rights Reserved.
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

#include "ia_css.h"
#include "ia_css_debug.h"
#include "sw_event_global.h"		/* encode_sw_event */
#include "sp.h"			/* cnd_sp_irq_enable() */
#include "assert_support.h"
#include "memory_access.h"
#include "sh_css_sp.h"
#include "ia_css_pipeline.h"

#define PIPELINE_SP_THREAD_EMPTY_TOKEN          (0x0)
#define PIPELINE_SP_THREAD_RESERVED_TOKEN       (0x1)
#define PIPELINE_NUM_EMPTY_TOKEN                (0xFFFF)
#define PIPELINE_NUM_RESERVED_TOKEN             (0x1)
#define PIPELINE_NUM_UNMAPPED                   (0xFFFF)

/*******************************************************
*** Static variables
********************************************************/
static uint32_t pipeline_num_counter;
static uint32_t pipeline_num_list[IA_CSS_PIPELINE_NUM_MAX];
static unsigned int pipeline_num_to_sp_thread_map[IA_CSS_PIPELINE_NUM_MAX];
static unsigned int pipeline_sp_thread_list[SH_CSS_MAX_SP_THREADS];

/*******************************************************
*** Static functions
********************************************************/
static uint8_t pipeline_generate_num(void);
static void pipeline_release_num(unsigned int pipe_num);
static void pipeline_init_sp_thread_map(void);
static void pipeline_map_num_to_sp_thread(unsigned int pipe_num);
static void pipeline_unmap_num_to_sp_thread(unsigned int pipe_num);
static void pipeline_init_defaults(struct ia_css_pipeline *pipeline,
	enum ia_css_pipe_id pipe_id);

static void pipeline_stage_destroy(struct ia_css_pipeline_stage *stage);
static enum ia_css_err pipeline_stage_create(
	struct ia_css_pipeline_stage_desc *stage_desc,
	struct ia_css_pipeline_stage **new_stage);

/*******************************************************
*** Public functions
********************************************************/
void ia_css_pipeline_init(void)
{
	unsigned int i;
	pipeline_num_counter = 0;
	for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++)
		pipeline_num_list[i] = PIPELINE_NUM_EMPTY_TOKEN;

	pipeline_init_sp_thread_map();
}

enum ia_css_err ia_css_pipeline_create(struct ia_css_pipeline *pipeline,
			      enum ia_css_pipe_id pipe_id)
{
	assert(pipeline != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_create() enter:\n");

	pipeline_init_defaults(pipeline, pipe_id);

	/* Allocate the pipe number */
	pipeline->pipe_num = pipeline_generate_num();
	if (pipeline_num_counter > IA_CSS_PIPELINE_NUM_MAX) {
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
			"ia_css_pipeline_create() exit: reached max pipes\n");
		return IA_CSS_ERR_RESOURCE_LIST_TO_SMALL;
	}

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_create() exit: pipe_num=%d\n",
		pipeline->pipe_num);

	return IA_CSS_SUCCESS;
}

/** @brief destroy a pipeline
 *
 * @param[in] pipeline
 * @return    None
 *
 */
void ia_css_pipeline_destroy(struct ia_css_pipeline *pipeline)
{
	assert(pipeline != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_destroy() enter: pipe_num=%d\n",
		pipeline->pipe_num);
	/* Free the pipeline number */
	pipeline_release_num(pipeline->pipe_num);

	ia_css_pipeline_clean(pipeline);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_destroy() exit:");
}

/* Run a pipeline and wait till it completes. */
void ia_css_pipeline_start(enum ia_css_pipe_id pipe_id,
			   struct ia_css_pipeline *pipeline)
{
	uint8_t pipe_num = 0;
	unsigned int thread_id;

	assert(pipeline != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
	      "ia_css_pipeline_start() enter: pipe_id=%d, pipeline=%p\n",
	      pipe_id, pipeline);
	pipeline->pipe_id = pipe_id;
	sh_css_sp_init_pipeline(pipeline, pipe_id, pipe_num,
				false, false, false, false, true, false, false,
				SH_CSS_PIPE_CONFIG_OVRD_NO_OVRD,
				IA_CSS_INPUT_MODE_MEMORY
#if !defined(HAS_NO_INPUT_SYSTEM)
				, (mipi_port_ID_t) 0
#endif
				);

	ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
	sh_css_sp_snd_event(SP_SW_EVENT_ID_4, thread_id, 0, 0);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
	      "ia_css_pipeline_start() leave: return_void\n");
}

/**
 * @brief Query the SP thread ID.
 * Refer to "sh_css_internal.h" for details.
 */
bool ia_css_pipeline_get_sp_thread_id(unsigned int key, unsigned int *val)
{
	assert(key < IA_CSS_PIPELINE_NUM_MAX);
	assert(key < IA_CSS_PIPE_ID_NUM);
	assert(val != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
	      "ia_css_pipeline_get_sp_thread_id() enter: key=%d\n",
	      key);
	*val = pipeline_num_to_sp_thread_map[key];

	assert(*val != PIPELINE_NUM_UNMAPPED);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
	      "ia_css_pipeline_get_sp_thread_id() leave: return_val=%d\n",
	      *val);
	return true;
}

enum ia_css_err ia_css_pipeline_request_stop(struct ia_css_pipeline *pipeline)
{
	enum ia_css_err err = IA_CSS_SUCCESS;
	unsigned int thread_id;

	assert(pipeline != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_request_stop() enter: pipeline=%p\n",
		pipeline);
	pipeline->stop_requested = true;

	/* Send stop event to the sp*/
	/* This needs improvement, stop on all the pipes available
	 * in the stream*/
	ia_css_pipeline_get_sp_thread_id(pipeline->pipe_num, &thread_id);
	sh_css_sp_snd_event(SP_SW_EVENT_ID_5, thread_id, 0,  0);
	sh_css_sp_uninit_pipeline(pipeline->pipe_num);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		      "ia_css_pipeline_request_stop() leave: return_err=%d\n",
		      err);
	return err;
}

void ia_css_pipeline_restart(struct ia_css_pipeline *pipeline)
{
	assert(pipeline != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_restart() enter:\n");
	pipeline->current_stage = NULL;
}

void ia_css_pipeline_clean(struct ia_css_pipeline *pipeline)
{
	struct ia_css_pipeline_stage *s;

	assert(pipeline != NULL);
	s = pipeline->stages;
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_pipeline_clean() enter:\n");

	while (s) {
		struct ia_css_pipeline_stage *next = s->next;
		pipeline_stage_destroy(s);
		s = next;
	}
	pipeline_init_defaults(pipeline, pipeline->pipe_id);
}

/** @brief Add a stage to pipeline.
 *
 * @param       pipeline      Pointer to the pipeline to be added to.
 * @param[in]   stage_desc    The description of the stage
 * @param[out]	stage         The successor of the stage.
 * @return      IA_CSS_SUCCESS or error code upon error.
 *
 * Add a new stage to a non-NULL pipeline.
 * The stage consists of an ISP binary or firmware and input and
 * output arguments.
*/
enum ia_css_err ia_css_pipeline_create_and_add_stage(
		struct ia_css_pipeline *pipeline,
		struct ia_css_pipeline_stage_desc *stage_desc,
		struct ia_css_pipeline_stage **stage)
{
	struct ia_css_pipeline_stage *last, *new_stage = NULL;
	enum ia_css_err err;

	/* other arguments can be NULL */
	assert(pipeline != NULL);
	assert(stage_desc != NULL);
	last = pipeline->stages;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		      "ia_css_pipeline_create_and_add_stage() enter:\n");
	if (!stage_desc->binary && !stage_desc->firmware
	    && (stage_desc->sp_func == IA_CSS_PIPELINE_NO_FUNC)) {
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
			      "ia_css_pipeline_create_and_add_stage() done:"
			      " Invalid args\n");

		return IA_CSS_ERR_INTERNAL_ERROR;
	}

	/* Find the last stage */
	while (last && last->next)
		last = last->next;

	/* if in_frame is not set, we use the out_frame from the previous
	 * stage, if no previous stage, it's an error.
	 */
	if ((stage_desc->sp_func == IA_CSS_PIPELINE_NO_FUNC)
		&& (!stage_desc->in_frame)
		&& (!stage_desc->firmware)
		&& (!stage_desc->binary->online)) {

		/* Do this only for ISP stages*/
		if (last)
			stage_desc->in_frame = last->args.out_frame;

		if (!stage_desc->in_frame)
			return IA_CSS_ERR_INTERNAL_ERROR;
	}

	/* Create the new stage */
	err = pipeline_stage_create(stage_desc, &new_stage);
	if (err != IA_CSS_SUCCESS) {
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
			      "ia_css_pipeline_create_and_add_stage() done:"
			      " stage_create_failed\n");
		return err;
	}

	if (last)
		last->next = new_stage;
	else
		pipeline->stages = new_stage;

	/* Output the new stage */
	if (stage)
		*stage = new_stage;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		      "ia_css_pipeline_create_and_add_stage() done:");
	return IA_CSS_SUCCESS;
}

void ia_css_pipeline_finalize_stages(struct ia_css_pipeline *pipeline)
{
	unsigned i = 0;
	struct ia_css_pipeline_stage *stage;

	assert(pipeline != NULL);
	for (stage = pipeline->stages; stage; stage = stage->next) {
		stage->stage_num = i;
		i++;
	}
	pipeline->num_stages = i;
}

enum ia_css_err ia_css_pipeline_get_stage(struct ia_css_pipeline *pipeline,
					  int mode,
					  struct ia_css_pipeline_stage **stage)
{
	struct ia_css_pipeline_stage *s;
	assert(pipeline != NULL);
	assert(stage != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		      "ia_css_pipeline_get_stage() enter:\n");
	for (s = pipeline->stages; s; s = s->next) {
		if (s->mode == mode) {
			*stage = s;
			return IA_CSS_SUCCESS;
		}
	}
	return IA_CSS_ERR_INTERNAL_ERROR;
}

enum ia_css_err ia_css_pipeline_get_output_stage(
		struct ia_css_pipeline *pipeline,
		int mode,
		struct ia_css_pipeline_stage **stage)
{
	struct ia_css_pipeline_stage *s;
	assert(pipeline != NULL);
	assert(stage != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		      "ia_css_pipeline_get_output_stage() enter:\n");

	*stage = NULL;
	/* First find acceleration firmware at end of pipe */
	for (s = pipeline->stages; s; s = s->next) {
		if (s->firmware && s->mode == mode &&
		    s->firmware->info.isp.enable.output)
			*stage = s;
	}
	if (*stage)
		return IA_CSS_SUCCESS;
	/* If no firmware, find binary in pipe */
	return ia_css_pipeline_get_stage(pipeline, mode, stage);
}

bool ia_css_pipeline_has_stopped(struct ia_css_pipeline *pipeline)
{
	unsigned int thread_id;
	struct sh_css_sp_group sp_group;
	const struct ia_css_fw_info *fw;
	unsigned int HIVE_ADDR_sp_group;

	fw = &sh_css_sp_fw;
	HIVE_ADDR_sp_group = fw->info.sp.group;

	ia_css_pipeline_get_sp_thread_id(pipeline->pipe_num, &thread_id);
	sp_dmem_load(SP0_ID,
		     (unsigned int)sp_address_of(sp_group),
		     &sp_group, sizeof(struct sh_css_sp_group));
	return sp_group.pipe[thread_id].num_stages == 0;
}

/*******************************************************
*** Static functions
********************************************************/

/* Pipeline:
 * To organize the several different binaries for each type of mode,
 * we use a pipeline. A pipeline contains a number of stages, each with
 * their own binary and frame pointers.
 * When stages are added to a pipeline, output frames that are not passed
 * from outside are automatically allocated.
 * When input frames are not passed from outside, each stage will use the
 * output frame of the previous stage as input (the full resolution output,
 * not the viewfinder output).
 * Pipelines must be cleaned and re-created when settings of the binaries
 * change.
 */
static void pipeline_stage_destroy(struct ia_css_pipeline_stage *pipeline)
{
	unsigned mem;
	if (pipeline->out_frame_allocated) {
		ia_css_frame_free(pipeline->args.out_frame);
		pipeline->args.out_frame = NULL;
	}
	if (pipeline->vf_frame_allocated) {
		ia_css_frame_free(pipeline->args.out_vf_frame);
		pipeline->args.out_vf_frame = NULL;
	}
	for (mem = 0; mem < IA_CSS_NUM_ISP_MEMORIES; mem++) {
		if (!pipeline->isp_mem_params[mem].size) continue;
		if (!pipeline->isp_mem_params[mem].address) continue;
		sh_css_free(pipeline->isp_mem_params[mem].address);
	}
	sh_css_free(pipeline);
}

static void pipeline_init_sp_thread_map(void)
{
	unsigned int i;

	for (i = 1; i < SH_CSS_MAX_SP_THREADS; i++)
		pipeline_sp_thread_list[i] = PIPELINE_SP_THREAD_EMPTY_TOKEN;

	for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++)
		pipeline_num_to_sp_thread_map[i] = PIPELINE_NUM_UNMAPPED;
}

static void pipeline_map_num_to_sp_thread(unsigned int pipe_num)
{
	unsigned int i;
	/* pipe is not mapped to any thread */
	assert(pipeline_num_to_sp_thread_map[pipe_num]
		== PIPELINE_NUM_UNMAPPED);

	for (i = 0; i < SH_CSS_MAX_SP_THREADS; i++) {
		if (pipeline_sp_thread_list[i] ==
		    PIPELINE_SP_THREAD_EMPTY_TOKEN) {
			pipeline_sp_thread_list[i] =
			    PIPELINE_SP_THREAD_RESERVED_TOKEN;
			pipeline_num_to_sp_thread_map[pipe_num] = i;
			break;
		}
	}
}

static void pipeline_unmap_num_to_sp_thread(unsigned int pipe_num)
{
	unsigned int thread_id;
	assert(pipeline_num_to_sp_thread_map[pipe_num]
		!= PIPELINE_NUM_UNMAPPED);

	thread_id = pipeline_num_to_sp_thread_map[pipe_num];
	pipeline_num_to_sp_thread_map[pipe_num] = PIPELINE_NUM_UNMAPPED;
	pipeline_sp_thread_list[thread_id] = PIPELINE_SP_THREAD_EMPTY_TOKEN;
}

static uint8_t pipeline_generate_num(void)
{
	uint8_t i;
	uint8_t pipe_num = ~0; /* UINT8_MAX; but Linux does not have this macro */
	/*Assign a new pipe_num .... search for empty place */
	for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++) {
		if (pipeline_num_list[i] == PIPELINE_NUM_EMPTY_TOKEN) {
			/*position is reserved */
			pipeline_num_list[i] = PIPELINE_NUM_RESERVED_TOKEN;
			pipe_num = i;
			break;
		}
	}
	assert(pipe_num != (uint8_t)~0); /* UINT8_MAX; but Linux does not have this macro */
	pipeline_num_counter++;
	pipeline_map_num_to_sp_thread(pipe_num);
	return pipe_num;
}

static void pipeline_release_num(unsigned int pipe_num)
{
	pipeline_num_list[pipe_num] = PIPELINE_NUM_EMPTY_TOKEN;
	pipeline_num_counter--;
	pipeline_unmap_num_to_sp_thread(pipe_num);
}

static enum ia_css_err pipeline_stage_create(
	struct ia_css_pipeline_stage_desc *stage_desc,
	struct ia_css_pipeline_stage **new_stage)
{
	struct ia_css_pipeline_stage *stage;
	struct sh_css_binary *binary;
	struct ia_css_frame *vf_frame;
	struct ia_css_frame *out_frame;
	const struct ia_css_fw_info *firmware;
	unsigned mem;

	/* Verify input parameters*/
	if (!(stage_desc->in_frame) && !(stage_desc->firmware)
	    && (stage_desc->binary) && !(stage_desc->binary->online))
		return IA_CSS_ERR_INTERNAL_ERROR;

	binary = stage_desc->binary;
	firmware = stage_desc->firmware;
	vf_frame = stage_desc->vf_frame;
	out_frame = stage_desc->out_frame;

	stage = sh_css_malloc(sizeof(*stage));
	if (!stage)
		return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;

	if (firmware) {
		stage->binary = NULL;
		stage->binary_info =
		    (struct ia_css_binary_info *)&firmware->info.isp;
	} else {
		stage->binary = binary;
		if (binary)
			stage->binary_info =
			    (struct ia_css_binary_info *)binary->info;
		else
			stage->binary_info = NULL;
	}
	
	for (mem = 0; mem < N_IA_CSS_ISP_MEMORIES; mem++) {
		if (stage->binary_info) {
			size_t size = stage->binary_info->mem_initializers[mem].size;
			stage->isp_mem_params[mem].size = size;
			stage->isp_mem_params[mem].address = NULL;
			if (!size) continue;
			stage->isp_mem_params[mem].address = sh_css_malloc(size);
		}
		else {
			/* Init. to zero to avoid freeing junk addresses
			   during stage destroy */
			stage->isp_mem_params[mem].size = 0;
			stage->isp_mem_params[mem].address = NULL;
		}
	}
	
	stage->firmware = firmware;
	stage->sp_func = stage_desc->sp_func;
	stage->max_input_width = stage_desc->max_input_width;
	stage->mode = stage_desc->mode;
	stage->out_frame_allocated = false;
	stage->vf_frame_allocated = false;
	stage->irq_buf_flags = 0x0;
	stage->next = NULL;
	sh_css_binary_args_reset(&stage->args);

	if (!(out_frame) && (binary)
	    && (binary->out_frame_info.res.width)) {
		enum ia_css_err ret =
		    ia_css_frame_allocate_from_info(&out_frame,
						    &binary->out_frame_info);
		if (ret != IA_CSS_SUCCESS) {
			sh_css_free(stage);
			return ret;
		}
		stage->out_frame_allocated = true;
	}
	/* VF frame is not needed in case of need_pp
	   However, the capture binary needs a vf frame to write to.
	 */
	if (!vf_frame) {
		if ((binary && binary->vf_frame_info.res.width) ||
		    (firmware && firmware->info.isp.enable.vf_veceven)
		    ) {
			enum ia_css_err ret =
			    ia_css_frame_allocate_from_info(&vf_frame,
							    &binary->
							    vf_frame_info);
			if (ret != IA_CSS_SUCCESS) {
				if (stage->out_frame_allocated) {
					ia_css_frame_free(out_frame);
					out_frame = NULL;
				}
				sh_css_free(stage);
				return ret;
			}
			stage->vf_frame_allocated = true;
		}
	} else if (vf_frame && binary && binary->vf_frame_info.res.width) {
		/* only mark as allocated if buffer pointer available */
		if (vf_frame->data != mmgr_NULL)
			stage->vf_frame_allocated = true;
	}

	stage->args.cc_frame = stage_desc->cc_frame;
	stage->args.in_frame = stage_desc->in_frame;
	stage->args.out_frame = out_frame;
	stage->args.out_vf_frame = vf_frame;
	*new_stage = stage;
	return IA_CSS_SUCCESS;
}

static void pipeline_init_defaults(struct ia_css_pipeline *pipeline,
	enum ia_css_pipe_id pipe_id)
{
	struct ia_css_frame init_frame;
	init_frame.dynamic_data_index = SH_CSS_INVALID_FRAME_ID;

	pipeline->pipe_id = pipe_id;
	pipeline->stages = NULL;
	pipeline->stop_requested = false;
	pipeline->reload = true;
	pipeline->current_stage = NULL;
	pipeline->in_frame = init_frame;
	pipeline->out_frame = init_frame;
	pipeline->vf_frame = init_frame;
}