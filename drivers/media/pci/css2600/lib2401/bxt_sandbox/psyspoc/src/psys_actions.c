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

#include "ia_css_psys_state_change_actions.h"
#include "ia_css_psys_sppipeline.h"
#include "ia_css_process_group_internal.h"
#include "assert_support.h"
#include "ia_css_fwctrl.h"

#define PSYS_MAX_PROCESS_GROUPS 50

typedef struct ia_css_psys_context ia_css_psys_context_t;

struct ia_css_psys_context {
	ia_css_process_group_t *process_group;
	const ia_css_program_group_manifest_t *pg_manifest;
	const ia_css_program_group_param_t *param;
	hrt_vaddress cmd_ptr;
};

ia_css_psys_context_t context_list[PSYS_MAX_PROCESS_GROUPS];

void ia_css_process_group_state_change(
	ia_css_process_group_t *process_group,
	const ia_css_program_group_manifest_t *pg_manifest,
	const ia_css_program_group_param_t *param)
{
	int ret;
	assert(process_group != NULL);
	switch(process_group->state) {
		case IA_CSS_PROCESS_GROUP_READY:
		assert(process_group != NULL && param != NULL);
		assert(process_group->ID < PSYS_MAX_PROCESS_GROUPS);
		context_list[process_group->ID].process_group = process_group;
		context_list[process_group->ID].pg_manifest = pg_manifest;
		context_list[process_group->ID].param = param;
		break;

		case IA_CSS_PROCESS_GROUP_STARTED:
		context_list[process_group->ID].cmd_ptr =
			ia_css_psys_sppipeline_cmd_create(process_group);
		ret = ia_css_fwctrl_psys_send_msg(
			context_list[process_group->ID].cmd_ptr);
		assert(ret == 0);

		break;

		case IA_CSS_PROCESS_GROUP_STOPPED:
		ia_css_psys_sppipeline_cmd_free(
			context_list[process_group->ID].cmd_ptr);
		context_list[process_group->ID].process_group = NULL;
		context_list[process_group->ID].pg_manifest = NULL;
		context_list[process_group->ID].param = NULL;
		context_list[process_group->ID].cmd_ptr = 0;
		break;

		default:
		break;
	}

	return;
}
