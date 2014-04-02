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

#ifndef __IA_CSS_PROCESS_GROUP_H__
#define __IA_CSS_PROCESS_GROUP_H__

#include "ia_css_types.h"
#include "type_support.h"
#include "ia_css_program_group.h"

typedef struct ia_css_process_group				ia_css_process_group_t;
typedef struct ia_css_terminal					ia_css_terminal_t;

/*
 * Creation
 */
extern size_t ia_css_sizeof_process_group(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern ia_css_process_group_t *ia_css_process_group_create(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern ia_css_process_group_t *ia_css_process_group_destroy(
	ia_css_process_group_t			 		*process_group);

/* Access functions */
extern uint8_t ia_css_process_group_get_terminal_count(
	const ia_css_process_group_t			*process_group);

extern ia_css_terminal_t *ia_css_process_group_get_terminal(
	const ia_css_process_group_t			*process_group,
	const unsigned int						terminal_index);

extern bool ia_css_is_terminal_input(
	const ia_css_terminal_t					*terminal);

extern ia_css_terminal_type_t ia_css_terminal_get_type(
	const ia_css_terminal_t					*terminal);

/*
 * Registration of user contexts / callback info
 */
extern int ia_css_process_group_set_token(
	ia_css_process_group_t					*process_group,
	const uint64_t							token);

/*
 * Commands
 */
extern int ia_css_process_group_submit(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_start(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_suspend(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_resume(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_reset(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_abort(
	ia_css_process_group_t					*process_group);

/*
 * External resources
 */
extern int ia_css_process_group_attach_buffer(
	ia_css_process_group_t					*process_group,
	uint8_t									*buffer,
	const ia_css_buffer_state_t				buffer_state,
	const unsigned int						terminal_index);

extern uint8_t *ia_css_process_group_detach_buffer(
	ia_css_process_group_t					*process_group,
	const unsigned int						terminal_index);

#endif /* __IA_CSS_PROCESS_GROUP_H__ */
