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

//#include <hive_isp_css_hrt.h>
#include "ia_css_psysapi.h"
#include "ia_css_pg_info.h"
#include "ia_css_frame_format.h"
#include "ia_css_acc_types.h"
#include "assert_support.h"
#include "system_types.h"  /* for hrt_vaddress */
#include "ia_css_memory_access.h"
#include "ia_css_psys_task_internal.h"
#include "memory_access.h"
#include "ia_css_psys_sppipeline.h"
#include "ia_css_fwctrl.h"

//int (*psysapi_dbg_print)(const char *fmt, va_list args);
int (*psysapi_dbg_print)(const char *fmt, ... );

int ia_css_psysapi_init(unsigned int *task_buffer_size, unsigned int ttl)
{
	(void) ttl;

	*task_buffer_size = sizeof(struct ia_css_psys_task);
#ifndef __KERNEL__
	psysapi_dbg_print = printf;
#endif
	return 0;
}

int ia_css_psysapi_task_create(
	struct ia_css_psys_task **task,
	struct ia_css_pg_info *pg_info,
	struct ia_css_psysapi_task_buffer* task_buffer,
	void* originator_cookie )
{
	struct ia_css_psys_task *tmp_task;
	int ret = 0;
	hrt_vaddress task_ptr;

	psysapi_dbg_print("ia_css_psysapi_task_create: enter\n");

	assert(pg_info->terminal_list.no_of_terminals <=
		IA_CSS_PSYSAPI_MAX_TERMINALS);

	tmp_task = (struct ia_css_psys_task *)(task_buffer->driver_address);
	memset(tmp_task, 0, sizeof(struct ia_css_psys_task));

	tmp_task->task_buffer = *task_buffer;
	/* ASK: @kai: How do you map pginfo ptrs to driver space. */
	tmp_task->pg_info = pg_info;
	tmp_task->cookie = originator_cookie;

	/* ASK: why do we need this if we are returning the task? */
	task_buffer->client_address = tmp_task;

	/* Need to setup the updated task info in firmware_address */
	task_ptr = (hrt_vaddress) task_buffer->firmware_address;
	mmgr_store(task_ptr,
		tmp_task,
		sizeof(struct ia_css_psys_task));

	*task = tmp_task;

	psysapi_dbg_print("ia_css_psysapi_task_create: done\n");
	return ret;
}

int ia_css_psysapi_task_start(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_resource_list* assigned_resources,
	struct ia_css_psysapi_resource_mapping resource_mapping)
{
	int ret=0;
	struct ia_css_pg_info *pg_info;
	struct ia_css_psysapi_cmd cmd;
	hrt_vaddress cmd_ptr, task_ptr;

	NOT_USED(assigned_resources);
	NOT_USED(resource_mapping);
	NOT_USED(cmd);
	psysapi_dbg_print("ia_css_psysapi_task_start: enter\n");

	pg_info = task->pg_info;
	task_ptr = (hrt_vaddress) task->task_buffer.firmware_address;
	cmd_ptr = (hrt_vaddress) &((struct ia_css_psys_task *)task_ptr)->cmd;

	/* ASK: Can we assume task buffer is uncached. Otherwise, the function below
	 * would only update a (write-back) cache but the device may not see it. */
	/* Adaptation to run a program via CSS based sp pipeline. */
	ia_css_psys_sppipeline_create(task);

	/* This should not be needed when the same command address can be reached
	 * from task as well as task_buffer. */
	mmgr_store(cmd_ptr,
		&task->cmd,
		sizeof(struct ia_css_psysapi_cmd));
#if 0
	/* TODO: Enqueue "cmd_ptr" to SP via POC helper modules
	 * under development */
	*((hrt_vaddress *)_hrt_cell_get_crun_symbol(SP, psyspoc_cmd_addr)) =
		cmd_ptr;
#endif
	/*Enqueue the psys_cmd_addr*/
	psysapi_dbg_print("PSYS SEND msg address = ox%x\n", cmd_ptr);
	ret = ia_css_fwctrl_psys_send_msg(cmd_ptr);
	if(ret != 0){
		psysapi_dbg_print("ia_css_psysapi_task_start: fwctrl send msg FAILED\n");
		return ret;
	}
	psysapi_dbg_print("ia_css_psysapi_task_start: leave\n");
	return ret;
}

int ia_css_psysapi_task_attach_buffer(
	struct ia_css_psys_task* task,
	/* ASK: Does terminal id refer to type of terminal or the terminal index?
	 * Assuming terminal index for now. Need to change psysapi documentation to
	 * reflect this (if we agree with this interpretation) */
	ia_css_psys_terminal_id_t terminal_id,
	struct ia_css_psys_buffer* buffer)
{
	int ret = 0;

	assert((uint32_t)terminal_id < IA_CSS_PSYSAPI_MAX_TERMINALS);
	NOT_USED(terminal_id);
	NOT_USED(buffer);
	NOT_USED(task);

	/* TODO: validate against terminal list */

	/* TODO: How do I store the terminals? */
	task->terminals[(uint32_t)terminal_id] = buffer;

	return ret;
}

int ia_css_psysapi_task_detach_buffer(
	struct ia_css_psys_task* task,
	ia_css_psys_terminal_id_t* terminal_id,
	struct ia_css_psys_buffer** buffer)
{
	int ret = 0;
	NOT_USED(task);
	NOT_USED(terminal_id);
	NOT_USED(buffer);
#if 0
	assert(terminal_id < IA_CSS_PSYSAPI_MAX_TERMINALS);

	if(task->terminals[(uint32_t)terminal_id]->nof_planes == 0) {
		return -1;
	}

	/* ASK: What else is needed here? */
	*buffer = task->terminals[(uint32_t)terminal_id];
	memset(task->terminals[terminal_id], 0,
		sizeof(struct ia_css_psys_buffer));
#endif
	return ret;
}
int ia_css_psysapi_task_get_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	void** delegator_cookie
)
{
	int ret = 0;
	struct ia_css_psysapi_cmd cmd_resp;
	hrt_vaddress xmem_psys_response;
	struct ia_css_psysapi_task_event* event = (struct ia_css_psysapi_task_event*) raw_event;
	hrt_vaddress task_ptr;
	struct ia_css_psys_task task;

	assert(raw_event);
	/*Silent the compiler*/
	NOT_USED(delegator_cookie);

	/*Reset the event to all 0s */
	memset(event, 0, sizeof(*event));

	ret = ia_css_fwctrl_psys_receive_msg(&xmem_psys_response);
	if(ret == 0)
	{
		psysapi_dbg_print("ia_css_psysapi_task_get_event: PSYS RX msg address = ox%x\n", xmem_psys_response);

		mmgr_load(xmem_psys_response, &cmd_resp, sizeof(struct ia_css_psysapi_cmd));
		if(cmd_resp.psys_event == IA_CSS_PSYSPOC_CMD_FINISHED){
			event->type = IA_CSS_PSYSAPI_TASK_FINISHED;
		}
		/* Get the firmware task address*/
		task_ptr = (hrt_vaddress) (xmem_psys_response - offsetof(struct ia_css_psys_task, cmd));

		/* Load the contents of the task in a local variable*/
		mmgr_load(task_ptr, &task, sizeof(struct ia_css_psys_task));
		/* Fill in the task driver address */
		/*Note : This is used to find who is the originator of the task
		 * task.task_buffer.driver_address is tested for crun and sched*/
		event->task = (struct ia_css_psys_task*)(task.task_buffer.driver_address);

		/*TODO: Fill in the following in the event
			1. delegator_cookie
			2. buffer
		*/
	}
	return ret;
}

int ia_css_psysapi_task_translate_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	struct ia_css_psysapi_task_event* event
)
{
	struct ia_css_psysapi_task_event* local_event = (struct ia_css_psysapi_task_event*) raw_event;
	assert(event);
	assert(raw_event);

	*event = *local_event;
	return 0;
}
