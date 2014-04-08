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

#include "ia_css_program_group.h"
#include "assert_support.h"
#include "ia_css_program_group_internal.h"

size_t ia_css_sizeof_program_group_param(
	const uint8_t							program_count,
	const uint16_t							fragment_count)
{
	size_t size = 0;

	size += sizeof(ia_css_program_group_param_t);
	size += program_count * fragment_count * sizeof(ia_css_program_param_t);

	return size;
}

size_t ia_css_program_group_param_get_size(
	const ia_css_program_group_param_t *manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		/* param has no "size" field, hence recalculating. */
		size = ia_css_sizeof_program_group_param(manifest->program_count,
			manifest->fragment_count);
	}

	return size;
}

void ia_css_program_group_param_init(
	ia_css_program_group_param_t *blob,
	const uint8_t	program_count,
	const uint16_t	fragment_count)
{
	assert(blob != 0);

	blob->program_count = program_count;
	blob->fragment_count = fragment_count;
	blob->program_param_offset = sizeof(ia_css_program_group_param_t);
}

size_t ia_css_sizeof_program_param(void)
{
	return sizeof(ia_css_program_param_t);
}

ia_css_program_param_t *ia_css_program_group_param_get_program_param(
	const ia_css_program_group_param_t		*param,
	const int								i)
{
	ia_css_program_param_t	*program_param = NULL;
	if (param != NULL) {
		ia_css_program_param_t	*program_param_base = NULL;
		program_param_base = (ia_css_program_param_t *)
			(((char *)param) + param->program_param_offset);
		program_param = &program_param_base[i];
	}

	return program_param;
}

uint8_t ia_css_program_group_param_get_program_count(
	const ia_css_program_group_param_t		*param)
{
	uint8_t	program_count = 0;
	if (param != NULL) {
		program_count = param->program_count;
	}

	return program_count;
}

uint16_t ia_css_program_group_param_get_fragment_count(
	const ia_css_program_group_param_t		*param)
{
	uint8_t	fragment_count = 0;
	if (param != NULL) {
		fragment_count = param->fragment_count;
	}

	return fragment_count;
}
