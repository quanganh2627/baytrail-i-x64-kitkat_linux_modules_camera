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

#include "ia_css_program_group_internal.h"
#include "ia_css_program_group.h"
#include "ia_css_psys_system_global.h"
#include <error_support.h>
#include <assert_support.h>
#include <misc_support.h>

#define verify_and_jmp_to_exit(cond)\
do {                                \
	if (!(cond)){                   \
		goto EXIT;                  \
	}                               \
} while(0)

extern size_t ia_css_terminal_manifest_get_size(
	const ia_css_terminal_manifest_t		*manifest);

extern ia_css_terminal_type_t ia_css_terminal_manifest_get_type(
	const ia_css_terminal_manifest_t		*manifest);

extern ia_css_program_group_ID_t ia_css_program_group_manifest_get_program_group_ID(
	const ia_css_program_group_manifest_t	*manifest);

extern uint8_t ia_css_program_group_manifest_get_program_count(
	const ia_css_program_group_manifest_t	*manifest);


void ia_css_program_group_manifest_init(
	ia_css_program_group_manifest_t *blob,
	const uint8_t	program_count,
	const uint8_t	terminal_count)
{
	int i;
	void *prg_manifest_base, *terminal_manifest_base;

	assert(blob != NULL);

	/* A program group ID cannot be zero */
	blob->ID = 1;
	blob->size = ia_css_sizeof_program_group_manifest(program_count,
		terminal_count);;

	blob->program_count = program_count;
	blob->terminal_count = terminal_count;

	blob->program_manifest_offset = sizeof(ia_css_program_group_manifest_t);
	blob->terminal_manifest_offset = blob->program_manifest_offset +
		ia_css_sizeof_program_manifest(program_count, terminal_count) *
		program_count;

	prg_manifest_base = (ia_css_program_manifest_t *)
		(((char*)blob) + blob->program_manifest_offset);
	for (i = 0; i < (int)program_count; i++) {
		ia_css_program_manifest_init(
			(ia_css_program_manifest_t *)prg_manifest_base,
			program_count, terminal_count);
		prg_manifest_base += ia_css_sizeof_program_manifest(program_count,
			terminal_count);
	}

	terminal_manifest_base = (ia_css_terminal_manifest_t *)
		(((char*)blob) + blob->terminal_manifest_offset);
	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_manifest_init(
			(ia_css_terminal_manifest_t *)terminal_manifest_base);
		terminal_manifest_base += ia_css_sizeof_terminal_manifest();
	}
}

void ia_css_program_manifest_init(
	ia_css_program_manifest_t	*blob,
	const uint8_t	program_dependency_count,
	const uint8_t	terminal_dependency_count)
{
	assert(blob != NULL);

	blob->ID = 1;
	blob->program_dependency_count = program_dependency_count;
	blob->terminal_dependency_count = terminal_dependency_count;
	blob->program_dependency_offset = sizeof(ia_css_program_manifest_t);
	blob->terminal_dependency_offset = blob->program_dependency_offset +
		sizeof(uint8_t) * program_dependency_count;
	blob->size = ia_css_sizeof_program_manifest(program_dependency_count,
		terminal_dependency_count);
}

void ia_css_terminal_manifest_init(ia_css_terminal_manifest_t *blob)
{
	assert(blob != NULL);
	blob->size = ia_css_sizeof_terminal_manifest();
}

size_t ia_css_program_group_manifest_get_size(
	const ia_css_program_group_manifest_t	*manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		size = manifest->size;
	}

	return size;
}

ia_css_program_group_ID_t ia_css_program_group_manifest_get_program_group_ID(
	const ia_css_program_group_manifest_t	*manifest)
{
	ia_css_program_group_ID_t	id = 0;

	verify_and_jmp_to_exit(manifest != NULL);

	id = manifest->ID;

EXIT:
	return id;
}

uint8_t ia_css_program_group_manifest_get_program_count(
	const ia_css_program_group_manifest_t	*manifest)
{
	uint8_t	program_count = 0;
	if (manifest != NULL) {
		program_count = manifest->program_count;
	}

	return program_count;
}

uint8_t ia_css_program_group_manifest_get_terminal_count(
	const ia_css_program_group_manifest_t	*manifest)
{
	uint8_t	terminal_count = 0;
	if (manifest != NULL) {
		terminal_count = manifest->terminal_count;
	}

	return terminal_count;
}

ia_css_program_manifest_t *ia_css_program_group_manifest_get_program_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						program_index)
{
	ia_css_program_manifest_t	*program_manifest = NULL;
	ia_css_program_manifest_t	*prg_manifest_base;
	uint8_t						program_count = ia_css_program_group_manifest_get_program_count(manifest);

	verify_and_jmp_to_exit(manifest != NULL);
	verify_and_jmp_to_exit(program_index < program_count);

	prg_manifest_base = (ia_css_program_manifest_t *)((char *)manifest +
		manifest->program_manifest_offset);
	program_manifest = &prg_manifest_base[program_index];
EXIT:
	return program_manifest;
}

ia_css_terminal_manifest_t *ia_css_program_group_manifest_get_terminal_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						terminal_index)
{
	ia_css_terminal_manifest_t *terminal_manifest = NULL;
	ia_css_terminal_manifest_t *terminal_manifest_base;
	uint8_t						terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	verify_and_jmp_to_exit(manifest != NULL);
	verify_and_jmp_to_exit(terminal_index < terminal_count);

	terminal_manifest_base = (ia_css_terminal_manifest_t *)((char *)manifest +
		manifest->terminal_manifest_offset);
	terminal_manifest = &terminal_manifest_base[terminal_index];
EXIT:
	return terminal_manifest;
}

size_t ia_css_sizeof_terminal_manifest(void)
{
	size_t	size = 0;

	size += sizeof(ia_css_terminal_manifest_t);

	return size;
}


size_t ia_css_terminal_manifest_get_size(
	const ia_css_terminal_manifest_t		*manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		size = manifest->size;
	}

	return size;
}

ia_css_terminal_type_t ia_css_terminal_manifest_get_type(
	const ia_css_terminal_manifest_t		*manifest)
{
	ia_css_terminal_type_t	terminal_type = IA_CSS_N_TERMINAL_TYPE;

	if (manifest != NULL) {
		terminal_type = manifest->terminal_type;
	}

	return terminal_type;
}

size_t ia_css_sizeof_program_group_manifest(
	const uint8_t program_count,
	const uint8_t terminal_count)
{
	size_t	size = 0;
	int		i;

	size += sizeof(ia_css_program_group_manifest_t);

	for (i = 0; i < (int)program_count; i++) {
		size += ia_css_sizeof_program_manifest(program_count, terminal_count);
	}

	for (i = 0; i < (int)terminal_count; i++) {
		size += ia_css_sizeof_terminal_manifest();
	}

	return size;
}

size_t ia_css_program_manifest_get_size(
	const ia_css_program_manifest_t			*manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		size = manifest->size;
	}

	return size;
}

uint8_t ia_css_program_manifest_get_program_dependency_count(
	const ia_css_program_manifest_t			*manifest)
{
	uint8_t	program_dependency_count = 0;
	if (manifest != NULL) {
		program_dependency_count = manifest->program_dependency_count;
	}
	return program_dependency_count;
}

uint8_t ia_css_program_manifest_get_terminal_dependency_count(
	const ia_css_program_manifest_t			*manifest)
{
	uint8_t	terminal_dependency_count = 0;
	if (manifest != NULL) {
		terminal_dependency_count = manifest->terminal_dependency_count;
	}
	return terminal_dependency_count;
}

size_t ia_css_sizeof_program_manifest(
	const uint8_t	program_dependency_count,
	const uint8_t terminal_dependency_count)
{
	size_t	size = 0;

	size += sizeof(ia_css_program_manifest_t);
	size += program_dependency_count * sizeof(uint8_t);
	size += terminal_dependency_count * sizeof(uint8_t);

	return size;
}

bool ia_css_program_manifest_has_fixed_cell(
	const ia_css_program_manifest_t			*manifest)
{
	bool	has_fixed_cell = false;

	vied_nci_cell_ID_t		cell_id;
	vied_nci_cell_type_ID_t	cell_type_id;

	verify_and_jmp_to_exit(manifest != NULL);

	cell_id = ia_css_program_manifest_get_cell_ID(manifest);
	cell_type_id = (vied_nci_cell_type_ID_t)(manifest->cell_type_id);
	has_fixed_cell = ((cell_id != VIED_NCI_N_CELL_ID) && (cell_type_id == VIED_NCI_N_CELL_TYPE_ID));
EXIT:
	return has_fixed_cell;
}

ia_css_program_ID_t ia_css_program_manifest_get_program_ID(
	const ia_css_program_manifest_t			*manifest)
{
	ia_css_program_ID_t		program_id = 0;

	verify_and_jmp_to_exit(manifest != NULL);

	program_id = manifest->ID;

EXIT:
	return program_id;
}

vied_nci_cell_ID_t ia_css_program_manifest_get_cell_ID(
	const ia_css_program_manifest_t			*manifest)
{
	vied_nci_cell_ID_t		cell_id = VIED_NCI_N_CELL_ID;

	verify_and_jmp_to_exit(manifest != NULL);

	cell_id = (vied_nci_cell_ID_t)(manifest->cell_id);
EXIT:
	return cell_id;
}
