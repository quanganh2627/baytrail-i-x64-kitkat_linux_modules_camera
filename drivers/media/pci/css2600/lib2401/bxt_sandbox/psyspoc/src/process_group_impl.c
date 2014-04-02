/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is sh_css_free software; you can redistribute it and/or
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

#include "ia_css_process_group_internal.h"
#include "ia_css_program_group_internal.h"
#include "ia_css_process_group.h"
#include "ia_css_psys_system_global.h"
#include "ia_css_psys_state_change_actions.h"

#include <error_support.h>
#include <assert_support.h>
#include <misc_support.h>

#include <sh_css_internal.h>

#define verifexit(cond,error_tag)   \
do {                                \
	if (!(cond)){                   \
		errno_local = (error_tag); \
		goto EXIT;                  \
	}                               \
} while(0)

#define verifjmpexit(cond)          \
do {                                \
	if (!(cond)){                   \
		goto EXIT;                  \
	}                               \
} while(0)



size_t ia_css_sizeof_terminal(
	const ia_css_terminal_manifest_t		*manifest,
	const ia_css_program_group_param_t		*param)
{
	size_t		size = 0;
	uint16_t	fragment_count;
	int errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	size += sizeof(ia_css_terminal_t);

	fragment_count = ia_css_program_group_param_get_fragment_count(param);

	size += fragment_count*sizeof(ia_css_fragment_descriptor_t);

EXIT:
	return size;
}

bool ia_css_is_terminal_input(
	const ia_css_terminal_t					*terminal)
{
	bool is_input = false;
	int errno_local = 0;
	ia_css_terminal_type_t	terminal_type = ia_css_terminal_get_type(terminal);

	verifexit(terminal != NULL, EINVAL);

	switch (terminal_type) {
	case IA_CSS_TERMINAL_TYPE_DATA_IN:			/* Fall through */
	case IA_CSS_TERMINAL_TYPE_STATE_IN:			/* Fall through */
	case IA_CSS_TERMINAL_TYPE_PARAM_STREAM:		/* Fall through */
	case IA_CSS_TERMINAL_TYPE_PARAM_CACHED:
		is_input = true;
		break;
	case IA_CSS_TERMINAL_TYPE_DATA_OUT:			/* Fall through */
	case IA_CSS_TERMINAL_TYPE_STATE_OUT:
		is_input = false;
		break;
	default:
		verifexit(false, EINVAL);
		break;
	}

EXIT:
	return is_input;
}

ia_css_terminal_type_t ia_css_terminal_get_type(
	const ia_css_terminal_t					*terminal)
{
	ia_css_terminal_type_t	terminal_type = IA_CSS_N_TERMINAL_TYPE;

	if (terminal != NULL) {
		terminal_type = terminal->terminal_type;
	}

	return terminal_type;
}

int ia_css_terminal_set_type(
	ia_css_terminal_t						*terminal,
	const ia_css_terminal_type_t			terminal_type)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);
	terminal->terminal_type = terminal_type;

	retval = 0;
EXIT:
	return retval;
}

uint8_t *ia_css_frame_get_buffer(
	const ia_css_psys_frame_t				*frame)
{
	uint8_t	*buffer = NULL;
	int errno_local = 0;

	verifexit(frame != NULL, EINVAL);
	buffer = (uint8_t *)frame->css_frame.data;
EXIT:
	return buffer;
}

int ia_css_frame_set_buffer(
	ia_css_psys_frame_t						*frame,
	uint8_t									*buffer)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(frame != NULL, EINVAL);
	/* frame->css_frame.data = (ia_css_ptr)buffer; */
	if(buffer)
		frame->css_frame = *((ia_css_frame_t *)buffer);
	else
		frame->css_frame.data = 0;

	retval = 0;
EXIT:
	return retval;
}

ia_css_buffer_state_t ia_css_frame_get_buffer_state(
	const ia_css_psys_frame_t					*frame)
{
	int errno_local = 0;
	ia_css_buffer_state_t	buffer_state = IA_CSS_N_BUFFER_STATES;

	verifexit(frame != NULL, EINVAL);
	buffer_state = frame->buffer_state;
EXIT:
	return buffer_state;
}

int ia_css_frame_set_buffer_state(
	ia_css_psys_frame_t						*frame,
	const ia_css_buffer_state_t				buffer_state)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(frame != NULL, EINVAL);
	frame->buffer_state = buffer_state;

	retval = 0;
EXIT:
	return retval;
}

size_t ia_css_sizeof_process_group(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	size_t	size = 0;
	int		i;
	int errno_local = 0;
	uint8_t	program_count, terminal_count;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	size += sizeof(ia_css_process_group_t);

	program_count = ia_css_program_group_manifest_get_program_count(manifest);
	terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	size += program_count*sizeof(ia_css_process_t *);
	size += terminal_count*sizeof(ia_css_terminal_t *);

/* All functions in the loops below can set errno_local, thus no need to exit on error, all can fail silently */
	for (i = 0; i < (int)program_count; i++) {
		ia_css_program_manifest_t	*program_manifest = ia_css_program_group_manifest_get_program_manifest(manifest, i);
		ia_css_program_param_t		*program_param = ia_css_program_group_param_get_program_param(param, i);
		size += ia_css_sizeof_process(program_manifest, program_param);
	}

	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_manifest_t	*terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(manifest, i);
		size += ia_css_sizeof_terminal(terminal_manifest, param);
	}

EXIT:
	return size;
}


bool ia_css_is_process_group_valid(
	const ia_css_process_group_t			*process_group,
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	bool is_valid = false;
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);
	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	is_valid = true;
EXIT:
	return is_valid;
}

bool ia_css_can_process_group_submit (
	const ia_css_process_group_t			*process_group)
{
	int		i;
	bool	can_submit = false;
	uint8_t	terminal_count = ia_css_process_group_get_terminal_count(process_group);
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_t		*terminal = ia_css_process_group_get_terminal(process_group, i);
		ia_css_psys_frame_t		*frame = ia_css_terminal_get_frame(terminal);
		uint8_t					*buffer;
		ia_css_buffer_state_t	buffer_state;

		verifexit(terminal != NULL, EINVAL);
		verifexit(frame != NULL, EINVAL);

		buffer = ia_css_frame_get_buffer(frame);
		buffer_state = ia_css_frame_get_buffer_state(frame);

/* FAS allows for attaching NULL buffers to satisfy SDF, but only if l-Scheduler is embedded */
		if ((buffer == NULL) || (buffer_state == IA_CSS_BUFFER_NULL) || (buffer_state == IA_CSS_N_BUFFER_STATES)) {
			break;
		}
	}
/* Only true if no check failed */
	can_submit = (i == terminal_count);
EXIT:
	return can_submit;
}

bool ia_css_can_process_group_start (
	const ia_css_process_group_t			*process_group)
{
	int		i;
	bool	can_start = false;
	uint8_t	terminal_count = ia_css_process_group_get_terminal_count(process_group);
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_t		*terminal = ia_css_process_group_get_terminal(process_group, i);
		ia_css_psys_frame_t		*frame = ia_css_terminal_get_frame(terminal);
		ia_css_buffer_state_t	buffer_state;
		bool					is_input = ia_css_is_terminal_input(terminal);
		bool					ok;

		verifexit(terminal != NULL, EINVAL);
		verifexit(frame != NULL, EINVAL);

		buffer_state = ia_css_frame_get_buffer_state(frame);

		ok = ((is_input && (buffer_state == IA_CSS_BUFFER_FULL)) || (!is_input && (buffer_state == IA_CSS_BUFFER_EMPTY)));
/*		nok = ((!is_input || (buffer_state != IA_CSS_BUFFER_FULL)) && (is_input || (buffer_state != IA_CSS_BUFFER_EMPTY))); */
		if (!ok) {
			break;
		}
	}
/* Only true if no check failed */
	can_start = (i == terminal_count);
EXIT:
	return can_start;
}

size_t ia_css_sizeof_process(
	const ia_css_program_manifest_t			*manifest,
	const ia_css_program_param_t			*param)
{
	size_t	size = 0;
	int errno_local = 0;

	uint8_t	program_dependency_count, terminal_dependency_count;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	size += sizeof(ia_css_process_t);

	program_dependency_count = ia_css_program_manifest_get_program_dependency_count(manifest);
	terminal_dependency_count = ia_css_program_manifest_get_terminal_dependency_count(manifest);

	size += program_dependency_count*sizeof(vied_nci_resource_id_t);
	size += terminal_dependency_count*sizeof(uint8_t);

EXIT:
	return size;
}

ia_css_process_t *ia_css_process_create(
	const ia_css_program_manifest_t		*manifest,
	const ia_css_program_param_t		*param)
{
	size_t	size = 0;
	ia_css_process_t	*process = NULL;

	int errno_local = 0;

//	size_t	size = ia_css_sizeof_process(manifest, param);
	uint8_t	program_dependency_count, terminal_dependency_count;

	errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	process = (ia_css_process_t *)sh_css_calloc(1, sizeof(ia_css_process_t));
	verifexit(process != NULL, EINVAL);
	size += sizeof(ia_css_process_t);

	process->state = IA_CSS_PROCESS_CREATED;

	program_dependency_count = ia_css_program_manifest_get_program_dependency_count(manifest);
	terminal_dependency_count = ia_css_program_manifest_get_terminal_dependency_count(manifest);

/* A process requires at least one input or output */
    verifexit((program_dependency_count + terminal_dependency_count) != 0, EINVAL);

	if (program_dependency_count != 0) {
		process->cell_dependencies = (vied_nci_resource_id_t *)sh_css_calloc(program_dependency_count, sizeof(vied_nci_resource_id_t));
		verifexit(process->cell_dependencies != NULL, EINVAL);
		size += program_dependency_count * sizeof(vied_nci_resource_id_t);
	}

	if (terminal_dependency_count != 0) {
		process->terminal_dependencies = (uint8_t *)sh_css_calloc(terminal_dependency_count, sizeof(uint8_t));
		verifexit(process->terminal_dependencies != NULL, EINVAL);
		size += terminal_dependency_count * sizeof(uint8_t);
	}

	process->size = ia_css_sizeof_process(manifest, param);
	verifexit(process->size == size, EINVAL);

	process->ID = ia_css_program_manifest_get_program_ID(manifest);

	verifexit(process->ID != 0, EINVAL);

	process->cell_dependency_count = program_dependency_count;
	process->terminal_dependency_count = terminal_dependency_count;

	process->parent = NULL;

	verifexit(ia_css_process_clear_all(process) == 0, EINVAL);

	process->state = IA_CSS_PROCESS_READY;

EXIT:
	if (errno_local != 0) {
		process = ia_css_process_destroy(process);
	}
	return process;
}

ia_css_process_t *ia_css_process_destroy(
	ia_css_process_t				 		*process)
{
	if (process != NULL) {
		sh_css_free((void *)process->cell_dependencies);
		sh_css_free((void *)process->terminal_dependencies);
		sh_css_free((void *)process);
		process = NULL;
	}
	return process;
}

ia_css_process_state_t ia_css_process_get_state(
	const ia_css_process_t					*process)
{
	ia_css_process_state_t	state = IA_CSS_N_PROCESS_STATES;

	if (process != NULL) {
		state = process->state;
	}

	return state;
}

size_t ia_css_process_get_size(
	const ia_css_process_t					*process)
{
	size_t	size = 0;

	if (process != NULL) {
		size = process->size;
	}

	return size;
}

uint8_t ia_css_process_get_cell_dependency_count(
	const ia_css_process_t					*process)
{
	uint8_t	cell_dependency_count = 0;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	cell_dependency_count = process->cell_dependency_count;

EXIT:
	return cell_dependency_count;
}

uint8_t ia_css_process_get_terminal_dependency_count(
	const ia_css_process_t					*process)
{
	uint8_t	terminal_dependency_count = 0;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	terminal_dependency_count = process->terminal_dependency_count;

EXIT:
	return terminal_dependency_count;
}

ia_css_process_group_t *ia_css_process_group_create(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	size_t		size = 0;
	int			i;
	ia_css_process_group_t	*process_group = NULL;
	uint8_t		process_count, terminal_count;
	uint16_t	fragment_count;
	int errno_local = 0;

//	size_t	size = ia_css_sizeof_process_group(manifest, param);

	errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	process_group = (ia_css_process_group_t	*)sh_css_calloc(1, sizeof(ia_css_process_group_t));
	verifexit(process_group != NULL, EINVAL);
	size += sizeof(ia_css_process_group_t);

	process_group->state = IA_CSS_PROCESS_GROUP_CREATED;

	fragment_count = ia_css_program_group_param_get_fragment_count(param);
	process_count = ia_css_process_group_compute_process_count(manifest, param);
	terminal_count = ia_css_process_group_compute_terminal_count(manifest, param);

	process_group->fragment_count = fragment_count;
	process_group->process_count = process_count;
	process_group->terminal_count = terminal_count;

	process_group->processes = (ia_css_process_t **)sh_css_calloc(process_count, sizeof(ia_css_process_t *));
	verifexit(process_group->processes != NULL, ENOBUFS);
	size += process_count * sizeof(ia_css_process_t *);

	for (i = 0; i < process_count; i++) {
		ia_css_program_manifest_t *program_manifest = ia_css_program_group_manifest_get_program_manifest(manifest, i);
		ia_css_program_param_t *program_param = ia_css_program_group_param_get_program_param(param, i);
		process_group->processes[i] = ia_css_process_create(program_manifest, program_param);
		verifexit(process_group->processes[i] != NULL, ENOBUFS);
		size += ia_css_process_get_size(process_group->processes[i]);

		ia_css_process_set_parent(process_group->processes[i], process_group);
		if (ia_css_program_manifest_has_fixed_cell(program_manifest)) {
			vied_nci_cell_ID_t	cell_id = ia_css_program_manifest_get_cell_ID(program_manifest);
			ia_css_process_set_cell(process_group->processes[i], cell_id);
		}
	}

	process_group->terminals = (ia_css_terminal_t **)sh_css_calloc(terminal_count, sizeof(ia_css_terminal_t *));
	verifexit(process_group->terminals != NULL, ENOBUFS);
	size += terminal_count * sizeof(ia_css_terminal_t *);

	for (i = 0; i < terminal_count; i++) {
		ia_css_terminal_manifest_t *terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(manifest, i);
//		ia_css_terminal_param_t *terminal_param = ia_css_program_group_param_get_terminal_param(param);
		process_group->terminals[i] = ia_css_terminal_create(terminal_manifest, param);
//		process_group->terminals[i] = ia_css_terminal_create(terminal_manifest, terminal_param);
		verifexit(process_group->terminals[i] != NULL, ENOBUFS);
		size += ia_css_terminal_get_size(process_group->terminals[i]);

/* Terminal may not require access to the parent */
		ia_css_terminal_set_parent(process_group->terminals[i], process_group);
	}

	process_group->size = ia_css_sizeof_process_group(manifest, param);
	verifexit(process_group->size == size, EINVAL);
	process_group->ID = ia_css_program_group_manifest_get_program_group_ID(manifest);

	verifexit(process_group->ID != 0, EINVAL);

	process_group->state = IA_CSS_PROCESS_GROUP_READY;

	ia_css_process_group_state_change(process_group, manifest, param);

EXIT:
	if (errno_local != 0) {
		process_group = ia_css_process_group_destroy(process_group);
	}
	return process_group;
}

ia_css_process_group_t *ia_css_process_group_destroy(
	ia_css_process_group_t			 		*process_group)
{
	int		i;

	if (process_group != NULL) {
		if (process_group->terminals != NULL) {
			uint8_t	terminal_count = ia_css_process_group_get_terminal_count(process_group);
			for (i = (int)terminal_count - 1; i >= 0; i--) {
				process_group->terminals[i] = ia_css_terminal_destroy(process_group->terminals[i]);
			}

			sh_css_free((void *)process_group->terminals);
			process_group->terminals = NULL;
		}

		if (process_group->processes != NULL) {
			uint8_t	process_count = ia_css_process_group_get_process_count(process_group);
			for (i = (int)process_count - 1; i >= 0; i--) {
				process_group->processes[i] = ia_css_process_destroy(process_group->processes[i]);
			}

			sh_css_free((void *)process_group->processes);
			process_group->processes = NULL;
		}

		sh_css_free((void *)process_group);
		process_group = NULL;
	}
	return process_group;
}

ia_css_process_group_state_t ia_css_process_group_get_state(
	const ia_css_process_group_t			*process_group)
{
	ia_css_process_group_state_t	state = IA_CSS_N_PROCESS_GROUP_STATES;

	if (process_group != NULL) {
		state = process_group->state;
	}

	return state;
}

size_t ia_css_process_group_get_size(
	const ia_css_process_group_t			*process_group)
{
	size_t	size = 0;

	if (process_group != NULL) {
		size = process_group->size;
	}

	return size;
}

int ia_css_process_group_set_token(
	ia_css_process_group_t					*process_group,
	const uint64_t							token)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);
	verifexit(token != 0, EINVAL);

	process_group->token = token;

	retval = 0;
EXIT:
	return retval;
}


ia_css_terminal_t *ia_css_terminal_create(
	const ia_css_terminal_manifest_t		*manifest,
	const ia_css_program_group_param_t		*param)
{
	size_t				size = 0;
	ia_css_terminal_t	*terminal = NULL;
	ia_css_psys_frame_t		*frame = NULL;
	uint16_t			fragment_count;
	int errno_local = 0;

//	size_t	size = ia_css_sizeof_terminal(manifest, param);

	fragment_count = ia_css_program_group_param_get_fragment_count(param);

	errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);
	terminal = (ia_css_terminal_t *)sh_css_calloc(1, sizeof(ia_css_terminal_t));
	verifexit(terminal != NULL, EINVAL);
	size += sizeof(ia_css_terminal_t);

	terminal->fragment_descriptor = (ia_css_fragment_descriptor_t *)sh_css_calloc(fragment_count, sizeof(ia_css_fragment_descriptor_t));
	size += fragment_count * sizeof(ia_css_fragment_descriptor_t);

	terminal->size = ia_css_sizeof_terminal(manifest, param);
	verifexit(terminal->size == size, EINVAL);

	verifexit(ia_css_terminal_set_type(terminal, ia_css_terminal_manifest_get_type(manifest)) == 0, EINVAL);

	frame = ia_css_terminal_get_frame(terminal);
/* Avoid dependency on definitions, although they are zero */
	verifexit(ia_css_frame_set_buffer(frame, NULL) == 0, EINVAL);
	verifexit(ia_css_frame_set_buffer_state(frame, IA_CSS_BUFFER_NULL) == 0, EINVAL);

EXIT:
	if (errno_local != 0) {
		terminal = ia_css_terminal_destroy(terminal);
	}
	return terminal;
}

ia_css_terminal_t *ia_css_terminal_destroy(
	ia_css_terminal_t						*terminal)
{
	sh_css_free((void *)terminal);
	terminal = NULL;
	return terminal;
}

size_t ia_css_terminal_get_size(
	const ia_css_terminal_t					*terminal)
{
	size_t	size = 0;

	if (terminal != NULL) {
		size = terminal->size;
	}

	return size;
}

int ia_css_terminal_set_parent(
	ia_css_terminal_t						*terminal,
	ia_css_process_group_t					*parent)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);
	verifexit(parent != NULL, EINVAL);

	terminal->parent = parent;

	retval = 0;
EXIT:
	return retval;
}

ia_css_process_group_t *ia_css_terminal_get_parent(
	const ia_css_terminal_t					*terminal)
{
	ia_css_process_group_t	*parent = NULL;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);

	parent = terminal->parent;
EXIT:
	return parent;
}

ia_css_psys_frame_t *ia_css_terminal_get_frame(
	const ia_css_terminal_t					*terminal)
{
	ia_css_psys_frame_t	*frame = NULL;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);

	frame = (ia_css_psys_frame_t *)(&(terminal->frame));
EXIT:
	return frame;
}

ia_css_frame_descriptor_t *ia_css_terminal_get_frame_descriptor(
	const ia_css_terminal_t					*terminal)
{
	ia_css_frame_descriptor_t	*frame_descriptor = NULL;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);

	frame_descriptor = (ia_css_frame_descriptor_t *)(&(terminal->frame_descriptor));
EXIT:
	return frame_descriptor;
}

ia_css_fragment_descriptor_t *ia_css_terminal_get_fragment_descriptor(
	const ia_css_terminal_t					*terminal,
	const unsigned int						fragment_index)
{
	ia_css_fragment_descriptor_t	*fragment_descriptor = NULL;
	uint16_t						fragment_count = ia_css_terminal_get_fragment_count(terminal);
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);
	verifexit(fragment_count != 0, EINVAL);

	verifexit(fragment_index < fragment_count, EINVAL);

	fragment_descriptor = (ia_css_fragment_descriptor_t *)(&(terminal->fragment_descriptor[fragment_index]));
EXIT:
	return fragment_descriptor;
}

uint16_t ia_css_terminal_get_fragment_count(
	const ia_css_terminal_t					*terminal)
{
	ia_css_process_group_t			*parent = ia_css_terminal_get_parent(terminal);
	uint16_t						fragment_count = 0;
	int errno_local = 0;

	verifexit(terminal != NULL, EINVAL);
	verifexit(parent != NULL, EINVAL);

	fragment_count = ia_css_process_group_get_fragment_count(parent);
EXIT:
	return fragment_count;
}

uint32_t ia_css_process_group_compute_cycle_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	uint32_t	cycle_count = 0;
	int errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

	cycle_count = 1;
EXIT:
	return cycle_count;
}

uint8_t ia_css_process_group_compute_process_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	uint8_t		process_count = 0;
	int errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

NOT_USED(param);

	process_count = ia_css_program_group_manifest_get_program_count(manifest);

EXIT:
	return process_count;
}

uint8_t ia_css_process_group_compute_terminal_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param)
{
	uint8_t		terminal_count = 0;
	int errno_local = 0;

	verifexit(manifest != NULL, EINVAL);
	verifexit(param != NULL, EINVAL);

NOT_USED(param);

	terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

EXIT:
	return terminal_count;
}

uint16_t ia_css_process_group_get_fragment_count(
	const ia_css_process_group_t			*process_group)
{
	uint16_t	fragment_count = 0;
	if (process_group != NULL) {
		fragment_count = process_group->fragment_count;
	}

	return fragment_count;
}

uint8_t ia_css_process_group_get_process_count(
	const ia_css_process_group_t			*process_group)
{
	uint8_t		process_count = 0;
	if (process_group != NULL) {
		process_count = process_group->process_count;
	}

	return process_count;
}

uint8_t ia_css_process_group_get_terminal_count(
	const ia_css_process_group_t			*process_group)
{
	uint8_t		terminal_count = 0;
	if (process_group != NULL) {
		terminal_count = process_group->terminal_count;
	}

	return terminal_count;
}

ia_css_terminal_t *ia_css_process_group_get_terminal(
	const ia_css_process_group_t			*process_group,
	const unsigned int						terminal_index)
{
	ia_css_terminal_t *terminal = NULL;

	int errno_local = 0;
	uint8_t		terminal_count = ia_css_process_group_get_terminal_count(process_group);

	verifexit(process_group != NULL, EINVAL);
	verifexit(terminal_index < terminal_count, EINVAL);

	terminal = process_group->terminals[terminal_index];
EXIT:
	return terminal;
}

ia_css_process_t *ia_css_process_group_get_process(
	const ia_css_process_group_t			*process_group,
	const unsigned int						process_index)
{
	ia_css_process_t *process = NULL;

	int errno_local = 0;
	uint8_t process_count = ia_css_process_group_get_process_count(process_group);

	verifexit(process_group != NULL, EINVAL);
	verifexit(process_index < process_count, EINVAL);

	process = process_group->processes[process_index];
EXIT:
	return process;
}

ia_css_program_group_ID_t ia_css_process_group_get_program_group_ID(
	const ia_css_process_group_t			*process_group)
{
	ia_css_program_group_ID_t	id = 0;
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	id = process_group->ID;

EXIT:
	return id;
}

vied_nci_resource_bitmap_t ia_css_process_group_get_resource_bitmap(
	const ia_css_process_group_t			*process_group)
{
	vied_nci_resource_bitmap_t	resource_bitmap = 0;
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	resource_bitmap = process_group->resource_bitmap;

EXIT:
	return resource_bitmap;
}

int ia_css_process_group_set_resource_bitmap(
	ia_css_process_group_t					*process_group,
	const vied_nci_resource_bitmap_t		resource_bitmap)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	process_group->resource_bitmap = resource_bitmap;

	retval = 0;
EXIT:
	return retval;
}



int ia_css_process_group_attach_buffer(
	ia_css_process_group_t					*process_group,
	uint8_t									*buffer,
	const ia_css_buffer_state_t				buffer_state,
	const unsigned int						terminal_index)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_terminal_t	*terminal = ia_css_process_group_get_terminal(process_group, terminal_index);
	ia_css_psys_frame_t	*frame = ia_css_terminal_get_frame(terminal);
	ia_css_process_group_state_t	state = ia_css_process_group_get_state(process_group);

	verifexit(terminal != NULL, EINVAL);
	verifexit(frame != NULL, EINVAL);
	verifexit(state == IA_CSS_PROCESS_GROUP_READY, EINVAL);

	retval = ia_css_frame_set_buffer(frame, buffer);
	verifexit(retval == 0, EINVAL);
	retval = ia_css_frame_set_buffer_state(frame, buffer_state);
EXIT:
	return retval;
}

uint8_t *ia_css_process_group_detach_buffer(
	ia_css_process_group_t					*process_group,
	const unsigned int						terminal_index)
{
	uint8_t *buffer = NULL;

	int errno_local = 0;
	ia_css_terminal_t	*terminal = ia_css_process_group_get_terminal(process_group, terminal_index);
	ia_css_psys_frame_t	*frame = ia_css_terminal_get_frame(terminal);
	ia_css_process_group_state_t	state = ia_css_process_group_get_state(process_group);

	verifexit(terminal != NULL, EINVAL);
	verifexit(frame != NULL, EINVAL);
	verifexit(state == IA_CSS_PROCESS_GROUP_READY, EINVAL);

	buffer = ia_css_frame_get_buffer(frame);

/* buffer pointer will appear on output, regardless of subsequent fails to avoid memory leaks */
	verifexit(ia_css_frame_set_buffer(frame, NULL) == 0, EINVAL);
	verifexit(ia_css_frame_set_buffer_state(frame, IA_CSS_BUFFER_NULL), EINVAL);
EXIT:
	return buffer;
}

int ia_css_process_group_set_barrier(
	ia_css_process_group_t					*process_group,
	const vied_nci_barrier_ID_t				barrier_index)
{
	int	retval = -1;
	vied_nci_resource_bitmap_t	bit_mask;
	vied_nci_resource_bitmap_t	resource_bitmap = ia_css_process_group_get_resource_bitmap(process_group);
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	bit_mask = vied_nci_barrier_bit_mask(barrier_index);

	verifexit(bit_mask != 0, EINVAL);
	verifexit(vied_nci_is_bitmap_clear(bit_mask, resource_bitmap), EINVAL);

	resource_bitmap = vied_nci_bitmap_set(resource_bitmap, bit_mask);

	retval = ia_css_process_group_set_resource_bitmap(process_group, resource_bitmap);
EXIT:
	return retval;
}

int ia_css_process_group_clear_barrier(
	ia_css_process_group_t					*process_group,
	const vied_nci_barrier_ID_t				barrier_index)
{
	int	retval = -1;
	vied_nci_resource_bitmap_t	bit_mask;
	vied_nci_resource_bitmap_t	resource_bitmap = ia_css_process_group_get_resource_bitmap(process_group);
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);

	bit_mask = vied_nci_barrier_bit_mask(barrier_index);

	verifexit(bit_mask != 0, EINVAL);
	verifexit(vied_nci_is_bitmap_set(bit_mask, resource_bitmap), EINVAL);

	resource_bitmap = vied_nci_bitmap_clear(resource_bitmap, bit_mask);

	retval = ia_css_process_group_set_resource_bitmap(process_group, resource_bitmap);
EXIT:
	return retval;
}

int ia_css_process_acquire(
	ia_css_process_t						*process)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	retval = 0;
EXIT:
	return retval;
}

int ia_css_process_release(
	ia_css_process_t						*process)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	retval = 0;
EXIT:
	return retval;
}

int ia_css_process_set_parent(
	ia_css_process_t						*process,
	ia_css_process_group_t					*parent)
{
	int	retval = -1;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	verifexit(parent != NULL, EINVAL);

	process->parent = parent;
	retval = 0;
EXIT:
	return retval;
}

ia_css_process_group_t *ia_css_process_get_parent(
	const ia_css_process_t					*process)
{
	ia_css_process_group_t	*parent = NULL;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);

	parent = process->parent;
EXIT:
	return parent;
}

ia_css_program_ID_t ia_css_process_get_program_ID(
	const ia_css_process_t					*process)
{
	ia_css_program_ID_t		id = 0;
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);

	id = process->ID;

EXIT:
	return id;
}

int ia_css_process_set_cell(
	ia_css_process_t						*process,
	const vied_nci_cell_ID_t				cell_id)
{
	int errno_local = 0;
	int	retval = -1;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	vied_nci_resource_bitmap_t		resource_bitmap, bit_mask;
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(parent != NULL, EINVAL);
/* Some programs are mapped on a fixed cell, when the process group is created */
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED) || (parent_state == IA_CSS_PROCESS_GROUP_CREATED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

/* Some programs are mapped on a fixed cell, thus check is not secure, but it will detect a preset, the process manager will do the secure check */
	verifexit(ia_css_process_get_cell(process) == VIED_NCI_N_CELL_ID, EINVAL);

	bit_mask = vied_nci_cell_bit_mask(cell_id);
	resource_bitmap = ia_css_process_group_get_resource_bitmap(parent);

	verifexit(bit_mask != 0, EINVAL);
	verifexit(vied_nci_is_bitmap_clear(bit_mask, resource_bitmap), EINVAL);

	process->cell_id = (vied_nci_resource_id_t)cell_id;
	resource_bitmap = vied_nci_bitmap_set(resource_bitmap, bit_mask);

	retval = ia_css_process_group_set_resource_bitmap(parent, resource_bitmap);
EXIT:
	return retval;
}

int ia_css_process_clear_cell(
	ia_css_process_t						*process)
{
	int	retval = -1;
	int errno_local = 0;
	vied_nci_cell_ID_t				cell_id = ia_css_process_get_cell(process);
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	vied_nci_resource_bitmap_t		resource_bitmap, bit_mask;
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(parent != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

	bit_mask = vied_nci_cell_bit_mask(cell_id);
	resource_bitmap = ia_css_process_group_get_resource_bitmap(parent);

	verifexit(bit_mask != 0, EINVAL);
	verifexit(vied_nci_is_bitmap_set(bit_mask, resource_bitmap), EINVAL);

	process->cell_id = (vied_nci_resource_id_t)VIED_NCI_N_CELL_ID;
	resource_bitmap = vied_nci_bitmap_clear(resource_bitmap, bit_mask);

	retval = ia_css_process_group_set_resource_bitmap(parent, resource_bitmap);
EXIT:
	return retval;
}

vied_nci_cell_ID_t ia_css_process_get_cell(
	const ia_css_process_t					*process)
{
	vied_nci_cell_ID_t	cell_id = VIED_NCI_N_CELL_ID;
	if (process != NULL) {
		cell_id = (vied_nci_cell_ID_t)(process->cell_id);
	}
	return cell_id;
}

int ia_css_process_set_int_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_ID_t					mem_id,
	const vied_nci_resource_size_t			offset)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	vied_nci_cell_ID_t				cell_id = ia_css_process_get_cell(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

/* "vied_nci_has_cell_mem_of_id()" will return false on error, e.g. when the cell or mem id is invalid  */
	if (vied_nci_has_cell_mem_of_id(cell_id, mem_id)) {
		vied_nci_mem_type_ID_t	mem_type = vied_nci_mem_get_type(mem_id);
assert(mem_type < VIED_NCI_N_MEM_TYPE_ID);
		process->int_mem_id[mem_type] = mem_id;
		process->int_mem_offset[mem_type] = offset;
		retval = 0;
	}
EXIT:
	return retval;
}

int ia_css_process_clear_int_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_type_ID_t			mem_type_id)
{
	int	retval = -1;
	int	mem_index;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	vied_nci_cell_ID_t				cell_id = ia_css_process_get_cell(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);
	int errno_local = 0;

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);
	verifexit(mem_type_id < VIED_NCI_N_MEM_TYPE_ID, EINVAL);

/* We could just clear the field, but lets check the state for consistency first */
	for (mem_index = 0; mem_index < (int)VIED_NCI_N_MEM_TYPE_ID; mem_index++) {
		if (vied_nci_is_cell_mem_of_type(cell_id, mem_index, mem_type_id)) {
			vied_nci_mem_ID_t	mem_id = vied_nci_cell_get_mem(cell_id, mem_index);
assert(vied_nci_is_mem_of_type(mem_id, mem_type_id));
assert((process->int_mem_id[mem_type_id] == mem_id) || (process->int_mem_id[mem_type_id] == VIED_NCI_N_MEM_ID));
			process->int_mem_id[mem_type_id] = VIED_NCI_N_MEM_ID;
			process->int_mem_offset[mem_type_id] = ~0;
			retval = 0;
		}
	}

EXIT:
	return retval;
}


int ia_css_process_set_ext_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_ID_t					mem_id,
	const vied_nci_resource_size_t			offset)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	vied_nci_cell_ID_t				cell_id = ia_css_process_get_cell(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

/* Check that the memory actually exists, "vied_nci_has_cell_mem_of_id()" will return false on error */
	if (!vied_nci_has_cell_mem_of_id(cell_id, mem_id) && (mem_id < VIED_NCI_N_MEM_ID)) {
		vied_nci_mem_type_ID_t	mem_type = vied_nci_mem_get_type(mem_id);
assert(mem_type < VIED_NCI_N_DATA_MEM_TYPE_ID);
		process->ext_mem_id[mem_type] = mem_id;
		process->ext_mem_offset[mem_type] = offset;
		retval = 0;
	}

EXIT:
	return retval;
}

int ia_css_process_clear_ext_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_type_ID_t			mem_type_id)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);
	verifexit(mem_type_id < VIED_NCI_N_DATA_MEM_TYPE_ID, EINVAL);

	process->ext_mem_id[mem_type_id] = VIED_NCI_N_MEM_ID;
	process->ext_mem_offset[mem_type_id] = ~0;

	retval = 0;
EXIT:
	return retval;
}

int ia_css_process_set_dev_chn(
	ia_css_process_t						*process,
	const vied_nci_dev_chn_ID_t				dev_chn_id,
	const vied_nci_resource_size_t			offset)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

	verifexit(dev_chn_id <= VIED_NCI_N_DEV_CHN_ID, EINVAL);

	process->chn_offset[dev_chn_id] = offset;

	retval = 0;
EXIT:
	return retval;
}

int ia_css_process_clear_dev_chn(
	ia_css_process_t						*process,
	const vied_nci_dev_chn_ID_t				dev_chn_id)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	ia_css_process_group_state_t	parent_state = ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(((parent_state == IA_CSS_PROCESS_GROUP_BLOCKED) || (parent_state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
	verifexit(state == IA_CSS_PROCESS_READY, EINVAL);

	verifexit(dev_chn_id <= VIED_NCI_N_DEV_CHN_ID, EINVAL);

	process->chn_offset[dev_chn_id] = ~0;

	retval = 0;
EXIT:
	return retval;
}

int ia_css_process_clear_all(
	ia_css_process_t						*process)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_group_t			*parent = ia_css_process_get_parent(process);
	ia_css_process_group_state_t	parent_state =  ia_css_process_group_get_state(parent);
	ia_css_process_state_t			state = ia_css_process_get_state(process);
	int	mem_index;
	int	dev_chn_index;

	verifexit(process != NULL, EINVAL);
/* Resource clear can only be called in excluded states contrary to set */
	verifexit((parent_state != IA_CSS_PROCESS_GROUP_RUNNING) || (parent_state == IA_CSS_N_PROCESS_GROUP_STATES), EINVAL);
	verifexit((state == IA_CSS_PROCESS_CREATED) || (state == IA_CSS_PROCESS_READY), EINVAL);

	for (dev_chn_index = 0; dev_chn_index < VIED_NCI_N_DEV_CHN_ID; dev_chn_index++) {
		process->chn_offset[dev_chn_index] = ~0;
	}
/* No difference whether a cell_id has been set or not, clear all */
	for (mem_index = 0; mem_index < VIED_NCI_N_DATA_MEM_TYPE_ID; mem_index++) {
		process->ext_mem_id[mem_index] = VIED_NCI_N_MEM_ID;
		process->ext_mem_offset[mem_index] = ~0;
	}
	for (mem_index = 0; mem_index < VIED_NCI_N_MEM_TYPE_ID; mem_index++) {
		process->int_mem_id[mem_index] = VIED_NCI_N_MEM_ID;
		process->int_mem_offset[mem_index] = ~0;
	}
	process->cell_id = (vied_nci_resource_id_t)VIED_NCI_N_CELL_ID;

	retval = 0;
EXIT:
	return retval;
}



int ia_css_process_group_submit(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_SUBMIT);
}

int ia_css_process_group_start(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_START);
}

int ia_css_process_group_stop(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_STOP);
}

int ia_css_process_group_run(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_RUN);
}

int ia_css_process_group_suspend(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_SUSPEND);
}

int ia_css_process_group_resume(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_RESUME);
}

int ia_css_process_group_reset(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_RESET);
}

int ia_css_process_group_abort(
	ia_css_process_group_t					*process_group)
{
	return ia_css_process_group_cmd(process_group, IA_CSS_PROCESS_GROUP_CMD_ABORT);
}


int ia_css_process_group_cmd(
	ia_css_process_group_t					*process_group,
	const ia_css_process_group_cmd_t		cmd)
{
	int	retval = -1;
	ia_css_process_group_state_t	state = ia_css_process_group_get_state(process_group);
	int errno_local = 0;

	verifexit(process_group != NULL, EINVAL);
	verifexit(state != IA_CSS_PROCESS_GROUP_ERROR, EINVAL);
	verifexit(state < IA_CSS_N_PROCESS_GROUP_STATES, EINVAL);

	switch (cmd) {
	case IA_CSS_PROCESS_GROUP_CMD_NOP:
		break;
	case IA_CSS_PROCESS_GROUP_CMD_SUBMIT:
		verifexit(state == IA_CSS_PROCESS_GROUP_READY, EINVAL);

/* External resource availability checks */
		verifexit(ia_css_can_process_group_submit(process_group), EINVAL);

		process_group->state = IA_CSS_PROCESS_GROUP_BLOCKED;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_ATTACH:
		verifexit(state == IA_CSS_PROCESS_GROUP_READY, EINVAL);
		break;
	case IA_CSS_PROCESS_GROUP_CMD_DETACH:
		verifexit(state == IA_CSS_PROCESS_GROUP_READY, EINVAL);
		break;
	case IA_CSS_PROCESS_GROUP_CMD_START:
		verifexit(state == IA_CSS_PROCESS_GROUP_BLOCKED, EINVAL);

/* External resource state checks */
		verifexit(ia_css_can_process_group_start(process_group), EINVAL);

		process_group->state = IA_CSS_PROCESS_GROUP_STARTED;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_RUN:
		verifexit(state == IA_CSS_PROCESS_GROUP_STARTED, EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_RUNNING;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_STOP:
		verifexit(state == IA_CSS_PROCESS_GROUP_RUNNING, EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_STOPPED;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_SUSPEND:
		verifexit(state == IA_CSS_PROCESS_GROUP_RUNNING, EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_STARTED;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_RESUME:
		verifexit(state == IA_CSS_PROCESS_GROUP_STARTED, EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_RUNNING;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_ABORT:
		verifexit(((state == IA_CSS_PROCESS_GROUP_RUNNING) || (state == IA_CSS_PROCESS_GROUP_STARTED)), EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_STOPPED;
		break;
	case IA_CSS_PROCESS_GROUP_CMD_RESET:
/* We accept a rested command in the stopped state, but mostly for simplifying the statemachine test */
		verifexit(((state == IA_CSS_PROCESS_GROUP_RUNNING) || (state == IA_CSS_PROCESS_GROUP_STARTED) || (state == IA_CSS_PROCESS_GROUP_STOPPED)), EINVAL);
		process_group->state = IA_CSS_PROCESS_GROUP_BLOCKED;
		break;
	default:
		verifexit(false, EINVAL);
		break;
	}

	retval = 0;
	ia_css_process_group_state_change(process_group, NULL, NULL);
EXIT:
	return retval;
}

int ia_css_process_cmd(
	ia_css_process_t						*process,
	const ia_css_process_cmd_t				cmd)
{
	int	retval = -1;
	int errno_local = 0;
	ia_css_process_state_t	state = ia_css_process_get_state(process);

	verifexit(process != NULL, EINVAL);
	verifexit(state != IA_CSS_PROCESS_ERROR, EINVAL);
	verifexit(state < IA_CSS_N_PROCESS_STATES, EINVAL);

	switch (cmd) {
	case IA_CSS_PROCESS_CMD_NOP:
		break;
	case IA_CSS_PROCESS_CMD_ACQUIRE:
		verifexit(state == IA_CSS_PROCESS_READY, EINVAL);
		break;
	case IA_CSS_PROCESS_CMD_RELEASE:
		verifexit(state == IA_CSS_PROCESS_READY, EINVAL);
		break;
	case IA_CSS_PROCESS_CMD_START:
		verifexit((state == IA_CSS_PROCESS_READY) || (state == IA_CSS_PROCESS_STOPPED), EINVAL);
		process->state = IA_CSS_PROCESS_STARTED;
		break;
	case IA_CSS_PROCESS_CMD_LOAD:
		verifexit(state == IA_CSS_PROCESS_STARTED, EINVAL);
		process->state = IA_CSS_PROCESS_RUNNING;
		break;
	case IA_CSS_PROCESS_CMD_STOP:
		verifexit((state == IA_CSS_PROCESS_RUNNING) || (state == IA_CSS_PROCESS_SUSPENDED), EINVAL);
		process->state = IA_CSS_PROCESS_STOPPED;
		break;
	case IA_CSS_PROCESS_CMD_SUSPEND:
		verifexit(state == IA_CSS_PROCESS_RUNNING, EINVAL);
		process->state = IA_CSS_PROCESS_SUSPENDED;
		break;
	case IA_CSS_PROCESS_CMD_RESUME:
		verifexit(state == IA_CSS_PROCESS_SUSPENDED, EINVAL);
		process->state = IA_CSS_PROCESS_RUNNING;
		break;
	default:
		verifexit(false, EINVAL);
		break;
	}
	retval = 0;
EXIT:
	return retval;
}


/*
 * Simulation, to populate the data structures
 */
static unsigned int ia_css_psys_ran_seed = 0;

void ia_css_psys_ran_set_seed (
    const unsigned int      seed)
{
	ia_css_psys_ran_seed = seed;
	return;
}

static unsigned int ia_css_psys_ran_int (void)
{
	ia_css_psys_ran_seed = 1664525UL*ia_css_psys_ran_seed + 1013904223UL;
	return ia_css_psys_ran_seed;
}

unsigned int ia_css_psys_ran_var (
    const unsigned int      bit_depth)
{
	unsigned int     out,tmp = ia_css_psys_ran_int();

	if (bit_depth>32) {
	    out = tmp;
	} else if (bit_depth==0) {
	    out = 0;
	} else {
	    out = (unsigned short)(tmp>>(32-bit_depth));
	}

return out;
}

unsigned int ia_css_psys_ran_val (
    const unsigned int      range)
{
	unsigned int     out,tmp = ia_css_psys_ran_int();
	if (range > 1) {
		out = tmp % range;
	} else {
		out = 0;
	}
	return out;
}
