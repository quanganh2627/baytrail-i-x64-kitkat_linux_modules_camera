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
#include <malloc.h>

#define verifexit(cond,error_tag)   \
do {                                \
	if (!(cond)){                   \
		errno = error_tag;          \
		goto EXIT;                  \
	}                               \
} while(0)

#define verifjmpexit(cond)          \
do {                                \
	if (!(cond)){                   \
		goto EXIT;                  \
	}                               \
} while(0)


ia_css_program_group_param_t *ia_css_program_group_param_alloc(
	const uint8_t							program_count,
	const uint16_t							fragment_count)
{
	int		i;

	ia_css_program_group_param_t *program_group_param = (ia_css_program_group_param_t *)calloc(1, sizeof(ia_css_program_group_param_t));
	errno = 0;
	verifexit(program_group_param != NULL, ENOBUFS);

	program_group_param->program_count = program_count;
	program_group_param->fragment_count = fragment_count;

	program_group_param->program_param = (ia_css_program_param_t **)calloc(program_count, sizeof(ia_css_program_param_t *));
	verifexit(program_group_param->program_param != NULL, ENOBUFS);

	for (i = 0; i < program_count; i++) {
		program_group_param->program_param[i] = ia_css_program_param_alloc();
		verifexit(program_group_param->program_param[i] != NULL, ENOBUFS);
	}

EXIT:

	if (errno != 0) {
		program_group_param = ia_css_program_group_param_free(program_group_param);
	}

	return program_group_param;
}

ia_css_program_group_param_t *ia_css_program_group_param_free(
	ia_css_program_group_param_t			*program_group_param)
{
	int		i;

	if (program_group_param != NULL) {
		if (program_group_param->program_param != NULL) {
			uint8_t	program_count = ia_css_program_group_param_get_program_count(program_group_param);

			for (i = (int)program_count - 1; i >= 0; i--) {
				program_group_param->program_param[i] = ia_css_program_param_free(program_group_param->program_param[i]);
			}
			free((void *)program_group_param->program_param);
			program_group_param->program_param = NULL;
		}
		free((void *)program_group_param);
		program_group_param = NULL;
	}
	return program_group_param;
}

ia_css_program_param_t *ia_css_program_param_alloc(void)
{
	return (ia_css_program_param_t *)calloc(1, sizeof(ia_css_program_param_t));
}

ia_css_program_param_t *ia_css_program_param_free(
	ia_css_program_param_t					*program_param)
{
	free((void *)program_param);
	program_param = NULL;
	return program_param;
}

ia_css_program_group_manifest_t *ia_css_program_group_manifest_alloc(
	const uint8_t							program_count,
	const uint8_t							terminal_count)
{
	size_t	size = 0;
	int		i;

	ia_css_program_group_manifest_t *manifest = (ia_css_program_group_manifest_t *)calloc(1, sizeof(ia_css_program_group_manifest_t));
	errno = 0;
	verifexit(manifest != NULL, ENOBUFS);
	size += sizeof(ia_css_program_group_manifest_t);

	/* A program group ID cannot be zero */
	manifest->ID = 1;

	manifest->program_count = program_count;
	manifest->terminal_count = terminal_count;

	manifest->program_manifest = (ia_css_program_manifest_t **)calloc(program_count, sizeof(ia_css_program_manifest_t *));
	verifexit(manifest->program_manifest != NULL, ENOBUFS);
	size += program_count * sizeof(ia_css_program_manifest_t *);

	for (i = 0; i < (int)program_count; i++) {
	/* Worst case, correct specification requires a DAG */
		manifest->program_manifest[i] = ia_css_program_manifest_alloc(program_count, terminal_count);
		verifexit(manifest->program_manifest[i] != NULL, ENOBUFS);
		size += ia_css_program_manifest_get_size(manifest->program_manifest[i]);
	}

	manifest->terminal_manifest = (ia_css_terminal_manifest_t **)calloc(terminal_count, sizeof(ia_css_terminal_manifest_t *));
	verifexit(manifest->terminal_manifest != NULL, ENOBUFS);
	size += terminal_count * sizeof(ia_css_terminal_manifest_t *);

	for (i = 0; i < (int)terminal_count; i++) {
		manifest->terminal_manifest[i] = ia_css_terminal_manifest_alloc();
		verifexit(manifest->terminal_manifest[i] != NULL, ENOBUFS);
		size += ia_css_terminal_manifest_get_size(manifest->terminal_manifest[i]);
	}

	manifest->size = ia_css_sizeof_program_group_manifest(manifest);
	verifexit(manifest->size == size, EINVAL);

EXIT:

	if (errno != 0) {
		manifest = ia_css_program_group_manifest_free(manifest);
	}

	return manifest;
}

ia_css_program_group_manifest_t *ia_css_program_group_manifest_free(
	ia_css_program_group_manifest_t		*manifest)
{
	int		i;

	if (manifest != NULL) {
		if (manifest->terminal_manifest != NULL) {
			uint8_t	terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

			for (i = (int)terminal_count - 1; i >= 0; i--) {
				manifest->terminal_manifest[i] = ia_css_terminal_manifest_free(manifest->terminal_manifest[i]);
			}
			free((void *)manifest->terminal_manifest);
			manifest->terminal_manifest = NULL;
		}

		if (manifest->program_manifest != NULL) {
			uint8_t	program_count = ia_css_program_group_manifest_get_program_count(manifest);

			for (i = (int)program_count - 1; i >= 0; i--) {
				manifest->program_manifest[i] = ia_css_program_manifest_free(manifest->program_manifest[i]);
			}
			free((void *)manifest->program_manifest);
			manifest->program_manifest = NULL;
		}
		free((void *)manifest);
		manifest = NULL;
	}

	return manifest;
}

ia_css_program_manifest_t *ia_css_program_manifest_alloc(
	const uint8_t							program_dependency_count,
	const uint8_t							terminal_dependency_count)
{
	size_t	size = 0;

	ia_css_program_manifest_t *manifest = (ia_css_program_manifest_t *)calloc(1, sizeof(ia_css_program_manifest_t));
	errno = 0;
	verifexit(manifest != NULL, ENOBUFS);
	size += sizeof(ia_css_program_manifest_t);

/* A program ID cannot be zero */
	manifest->ID = 1;
/* A program requires at least one input or output */
    verifexit((program_dependency_count + terminal_dependency_count) != 0, EINVAL);

	manifest->program_dependency_count = program_dependency_count;
	manifest->terminal_dependency_count = terminal_dependency_count;

    if (program_dependency_count != 0) {
		manifest->program_dependencies = (uint8_t *)calloc(program_dependency_count, sizeof(uint8_t));
		verifexit(manifest->program_dependencies != NULL, ENOBUFS);
		size += program_dependency_count * sizeof(uint8_t);
	}

    if (terminal_dependency_count != 0) {
		manifest->terminal_dependencies = (uint8_t *)calloc(terminal_dependency_count, sizeof(uint8_t));
		verifexit(manifest->terminal_dependencies != NULL, ENOBUFS);
		size += terminal_dependency_count * sizeof(uint8_t);
	}

	manifest->size = ia_css_sizeof_program_manifest(manifest);
	verifexit(manifest->size == size, EINVAL);

EXIT:

	if (errno != 0) {
		manifest = ia_css_program_manifest_free(manifest);
	}

	return manifest;
}

ia_css_program_manifest_t *ia_css_program_manifest_free(
	ia_css_program_manifest_t				*manifest)
{
	if (manifest != NULL) {
		free((void *)manifest->terminal_dependencies);
		manifest->terminal_dependencies = NULL;
		free((void *)manifest->program_dependencies);
		manifest->program_dependencies = NULL;

		free((void *)manifest);
		manifest = NULL;
	}
	return manifest;
}

ia_css_terminal_manifest_t *ia_css_terminal_manifest_alloc(void)
{
	size_t	size = 0;

	ia_css_terminal_manifest_t	*manifest = (ia_css_terminal_manifest_t *)calloc(1, sizeof(ia_css_terminal_manifest_t));
	size += sizeof(ia_css_terminal_manifest_t);
	errno = 0;

	manifest->size = ia_css_sizeof_terminal_manifest(manifest);
	verifexit(manifest->size == size, EINVAL);

EXIT:
	if (errno != 0) {
		manifest = ia_css_terminal_manifest_free(manifest);
	}

	return manifest;
}

ia_css_terminal_manifest_t *ia_css_terminal_manifest_free(
	ia_css_terminal_manifest_t				*manifest)
{
	free((void *)manifest);
	manifest = NULL;
	return manifest;
}


size_t ia_css_sizeof_program_group_manifest(
	const ia_css_program_group_manifest_t	*manifest)
{
	size_t	size = 0;
	int		i;
	uint8_t	program_count;
	uint8_t	terminal_count;

	verifexit(manifest != NULL, EINVAL);

	size += sizeof(ia_css_program_group_manifest_t);

	program_count = ia_css_program_group_manifest_get_program_count(manifest);
	terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	size += program_count*sizeof(ia_css_program_manifest_t *);
	size += terminal_count*sizeof(ia_css_terminal_manifest_t *);

/* All functions in the loops below can set errno, thus no need to exit on error, all can fail silently */
	for (i = 0; i < (int)program_count; i++) {
		ia_css_program_manifest_t	*program_manifest = ia_css_program_group_manifest_get_program_manifest(manifest, i);
		size += ia_css_sizeof_program_manifest(program_manifest);
	}

	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_manifest_t	*terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(manifest, i);
		size += ia_css_sizeof_terminal_manifest(terminal_manifest);
	}

EXIT:
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

size_t ia_css_sizeof_program_manifest(
	const ia_css_program_manifest_t			*manifest)
{
	size_t	size = 0;

	uint8_t	program_dependency_count, terminal_dependency_count;

	verifexit(manifest != NULL, EINVAL);

	size += sizeof(ia_css_program_manifest_t);

	program_dependency_count = ia_css_program_manifest_get_program_dependency_count(manifest);
	terminal_dependency_count = ia_css_program_manifest_get_terminal_dependency_count(manifest);

	size += program_dependency_count * sizeof(uint8_t);
	size += terminal_dependency_count * sizeof(uint8_t);

EXIT:
	return size;
}

