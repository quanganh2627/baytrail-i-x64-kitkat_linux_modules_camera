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

#include "ia_css_psysapi.h"
#include "ia_css_debug.h"
#include "ia_css_fwctrl.h"
#include "memory_access.h"

/*Only used to verify PSYS Dummy event and payload
Remove this once PSYS Implementation is done*/
#define DUMMY_EVENT_FINISHED 0x00A0B0C0
#define MSG_CHECK 0xC0C0C0C0


/*Dummy Code to test PSYSPOC module*/
int ia_css_psysapi_init(unsigned int* task_buffer_size, unsigned int time_to_live)
{
	NOT_USED(task_buffer_size);
	NOT_USED(time_to_live);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_psysapi_init enter\n");
	return 0;
}

/*To DO : Implement actual PSYS API
 * This is used to showcase host/sp communication using queues*/
int ia_css_psysapi_task_start(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_resource_list* assigned_resources,
	struct ia_css_psysapi_resource_mapping resource_mapping
)
{
	uint32_t send_msg ;
	hrt_vaddress xmem_psys_msg;
	int status = -1;
	NOT_USED (assigned_resources);
	NOT_USED (resource_mapping);
	NOT_USED (task);
	/*MSG_CHECK is dummy message
	 * Remove this once we implement PSYS*/
	send_msg = MSG_CHECK;
	xmem_psys_msg = mmgr_malloc(sizeof (uint32_t));
	if(xmem_psys_msg == mmgr_NULL)
		return ENOMEM;
	mmgr_store(xmem_psys_msg, (void *)&send_msg, sizeof(uint32_t));
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_psysapi_start SEND MESSAGE = 0x%x\n",send_msg);

	status = ia_css_fwctrl_psys_send_msg(xmem_psys_msg);
	return status;
}

int ia_css_psysapi_task_get_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	void** delegator_cookie
)
{
	int ret = 0;
	uint32_t msg;
	hrt_vaddress xmem_psys_response;
	NOT_USED(delegator_cookie);
	ret = ia_css_fwctrl_psys_receive_msg(&xmem_psys_response);
	if(ret == 0)
	{
		mmgr_load(xmem_psys_response, (void*) (&msg), sizeof(uint32_t));
		mmgr_free(xmem_psys_response);
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "psyspoc_receive msg() = 0x%x \n",msg);
		if(msg == MSG_CHECK )
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "PSYS POC msg Send/Rec SUCCESS\n");
			/*To DO : Design raw_event for PSYS.*/
			raw_event->reserved[0] = DUMMY_EVENT_FINISHED;
		}
	}
	return ret;
}

int ia_css_psysapi_task_translate_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	struct ia_css_psysapi_task_event* event
)
{
	if(raw_event->reserved[0] == DUMMY_EVENT_FINISHED)
		event->type = IA_CSS_PSYSAPI_TASK_FINISHED;
	return 0;
}
