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

#include "system_types.h"  /* for hrt_vaddress */
#include "type_support.h"
#include "ia_css_psys_event.h"
#include "ia_css_fwctrl.h"
#include "ia_css_psys_cmd_comm.h"
#include "ia_css_process_group_internal.h"
#include "memory_access.h"

int ia_css_psys_handle_event(ia_css_psys_event_descriptor_t *event)
{
	int ret;
	hrt_vaddress xmem_psys_response;
	ia_css_psysapi_cmd_t cmd_resp;

	if(event == NULL) {
		return -1;
	}

	ret = ia_css_fwctrl_psys_receive_msg(&xmem_psys_response);
	if(ret == 0) {
		mmgr_load(xmem_psys_response, &cmd_resp, sizeof(struct ia_css_psysapi_cmd));
		if(cmd_resp.psys_event == IA_CSS_PSYSPOC_CMD_FINISHED){
			event->type = IA_CSS_PSYS_EVENT_TYPE_CMD_COMPLETE;
			/* Get the process group address */
			event->cookie = (void *) (cmd_resp.cookie);
			ia_css_process_group_stop(cmd_resp.cookie);
		} else {
			/* TODO: Handle other events when fw supports them. */
			event->cookie = 0;
		}


		/* TODO: Change state of output buffers in output termina here? It may
		 * be better to do it under explicit control of the application since it
		 * knows more about explicit fragmentation */
	}
	return ret;
}
