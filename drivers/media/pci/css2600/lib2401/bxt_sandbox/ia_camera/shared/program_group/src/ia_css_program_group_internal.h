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

#ifndef __IA_CSS_PROGRAM_GROUP_INTERNAL_H__
#define __IA_CSS_PROGRAM_GROUP_INTERNAL_H__

#include "ia_css_program_group.h"
#include "type_support.h"
#include "ia_css_psys_system_global.h"

extern size_t ia_css_sizeof_program_param(void);

extern ia_css_program_param_t *ia_css_program_param_alloc(void);

extern ia_css_program_param_t *ia_css_program_param_free(
	ia_css_program_param_t					*program_param);

extern void ia_css_program_manifest_init(
	ia_css_program_manifest_t	*blob,
	const uint8_t	program_dependency_count,
	const uint8_t	terminal_dependency_count);

extern ia_css_program_manifest_t *ia_css_program_manifest_alloc(
	const uint8_t							program_dependency_count,
	const uint8_t							terminal_dependency_count);

extern ia_css_program_manifest_t *ia_css_program_manifest_free(
	ia_css_program_manifest_t				*manifest);

extern size_t ia_css_program_manifest_get_size(
	const ia_css_program_manifest_t			*manifest);

extern uint8_t ia_css_program_manifest_get_program_dependency_count(
	const ia_css_program_manifest_t			*manifest);

extern uint8_t ia_css_program_manifest_get_terminal_dependency_count(
	const ia_css_program_manifest_t			*manifest);


extern bool ia_css_program_manifest_has_fixed_cell(
	const ia_css_program_manifest_t			*manifest);

extern ia_css_program_ID_t ia_css_program_manifest_get_program_ID(
	const ia_css_program_manifest_t			*manifest);

extern vied_nci_cell_ID_t ia_css_program_manifest_get_cell_ID(
	const ia_css_program_manifest_t			*manifest);

extern void ia_css_terminal_manifest_init(ia_css_terminal_manifest_t *blob);

extern ia_css_terminal_manifest_t *ia_css_terminal_manifest_alloc(void);

extern ia_css_terminal_manifest_t *ia_css_terminal_manifest_free(
	ia_css_terminal_manifest_t *			manifest);

extern size_t ia_css_sizeof_terminal_manifest(void);

extern size_t ia_css_terminal_manifest_get_size(
	const ia_css_terminal_manifest_t		*manifest);

extern ia_css_terminal_type_t ia_css_terminal_manifest_get_type(
	const ia_css_terminal_manifest_t		*manifest);

extern size_t ia_css_program_group_manifest_get_size(
	const ia_css_program_group_manifest_t	*manifest);

extern ia_css_program_group_ID_t ia_css_program_group_manifest_get_program_group_ID(
	const ia_css_program_group_manifest_t	*manifest);

extern size_t ia_css_sizeof_program_manifest(
	const uint8_t	program_dependency_count,
	const uint8_t terminal_dependency_count);

/*
 * To build a working model, generate FW, test, verify etc ... Needs some sorting
 */
extern ia_css_program_param_t *ia_css_program_group_param_get_program_param(
	const ia_css_program_group_param_t		*param,
	const int								i);

extern uint8_t ia_css_program_group_param_get_program_count(
	const ia_css_program_group_param_t		*param);

extern uint16_t ia_css_program_group_param_get_fragment_count(
	const ia_css_program_group_param_t		*param);

#endif /* __IA_CSS_PROGRAM_GROUP_INTERNAL_H__ */
