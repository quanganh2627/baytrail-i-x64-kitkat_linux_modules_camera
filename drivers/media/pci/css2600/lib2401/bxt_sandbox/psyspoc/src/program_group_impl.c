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
#include <print_support.h>
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

	verifexit(manifest != NULL, EINVAL);

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
	uint8_t						program_count = ia_css_program_group_manifest_get_program_count(manifest);

	verifexit(manifest != NULL, EINVAL);
	verifexit(program_index < program_count, EINVAL);

	program_manifest = manifest->program_manifest[program_index];
EXIT:
	return program_manifest;
}

ia_css_terminal_manifest_t *ia_css_program_group_manifest_get_terminal_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						terminal_index)
{
	ia_css_terminal_manifest_t *terminal_manifest = NULL;
	uint8_t						terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	verifexit(manifest != NULL, EINVAL);
	verifexit(terminal_index < terminal_count, EINVAL);

	terminal_manifest = manifest->terminal_manifest[terminal_index];
EXIT:
	return terminal_manifest;
}

size_t ia_css_sizeof_terminal_manifest(
	const ia_css_terminal_manifest_t			*manifest)
{
	size_t	size = 0;

	verifexit(manifest != NULL, EINVAL);

	size += sizeof(ia_css_terminal_manifest_t);

EXIT:
	return size;
}

int ia_css_terminal_manifest_print(
	const ia_css_terminal_manifest_t		*manifest,
	FILE									*fid)
{
	int	retval = -1;
	int	i;

	verifexit(manifest != NULL, EINVAL);
	verifexit(fid != NULL, EINVAL);

	fprintf(fid,"ia_css_terminal_manifest_print\n");
	fprintf(fid,"sizeof(manifest) = %d\n",(int)ia_css_sizeof_terminal_manifest(manifest));

	fprintf(fid,"typeof(manifest) = %d\n",(int)ia_css_terminal_manifest_get_type(manifest));
//	fprintf(fid,"typeof(manifest) = %s\n",(int)ia_css_terminal_type_string(ia_css_terminal_manifest_get_type(manifest)));
	fprintf(fid,"formats(manifest) = %04x\n",(int)manifest->frame_format_bitmap);
	fprintf(fid,"dependent(manifest) = %d\n",(int)manifest->terminal_dependency);

	fprintf(fid,"\tmin_size[%d]   = {",IA_CSS_N_DATA_DIMENSION);
	for (i = 0; i < (int)IA_CSS_N_DATA_DIMENSION - 1; i++) {
		fprintf(fid,"%4d, ",manifest->min_size[i]);
	}
	fprintf(fid,"%4d}\n",manifest->min_size[i]);

	fprintf(fid,"\tmax_size[%d]   = {",IA_CSS_N_DATA_DIMENSION);
	for (i = 0; i < (int)IA_CSS_N_DATA_DIMENSION - 1; i++) {
		fprintf(fid,"%4d, ",manifest->max_size[i]);
	}
	fprintf(fid,"%4d}\n",manifest->max_size[i]);

	fprintf(fid,"\tmin_fragment_size[%d]   = {",IA_CSS_N_DATA_DIMENSION);
	for (i = 0; i < (int)IA_CSS_N_DATA_DIMENSION - 1; i++) {
		fprintf(fid,"%4d, ",manifest->min_fragment_size[i]);
	}
	fprintf(fid,"%4d}\n",manifest->min_fragment_size[i]);

	fprintf(fid,"\tmax_fragment_size[%d]   = {",IA_CSS_N_DATA_DIMENSION);
	for (i = 0; i < (int)IA_CSS_N_DATA_DIMENSION - 1; i++) {
		fprintf(fid,"%4d, ",manifest->max_fragment_size[i]);
	}
	fprintf(fid,"%4d}\n",manifest->max_fragment_size[i]);

	retval = 0;
EXIT:
	return retval;
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

int ia_css_program_group_manifest_print(
	const ia_css_program_group_manifest_t	*manifest,
	FILE									*fid)
{
	int	retval = -1;

	int	i;
	uint8_t	program_count, terminal_count;

	verifexit(manifest != NULL, EINVAL);
	verifexit(fid != NULL, EINVAL);

	fprintf(fid,"ia_css_program_group_manifest_print\n");
	fprintf(fid,"sizeof(manifest) = %d\n",(int)ia_css_sizeof_program_group_manifest(manifest));

	fprintf(fid,"program group ID = %d\n",(int)ia_css_program_group_manifest_get_program_group_ID(manifest));
	program_count = ia_css_program_group_manifest_get_program_count(manifest);
	terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	fprintf(fid,"%d program manifests\n",(int)program_count);
	for (i = 0; i < (int)program_count; i++) {
		ia_css_program_manifest_t	*program_manifest = ia_css_program_group_manifest_get_program_manifest(manifest, i);
		retval = ia_css_program_manifest_print(program_manifest, fid);
		verifjmpexit(retval == 0);
	}
	fprintf(fid,"%d terminal manifests\n",(int)terminal_count);
	for (i = 0; i < (int)terminal_count; i++) {
		ia_css_terminal_manifest_t	*terminal_manifest = ia_css_program_group_manifest_get_terminal_manifest(manifest, i);
		retval = ia_css_terminal_manifest_print(terminal_manifest, fid);
		verifjmpexit(retval == 0);
	}

	retval = 0;
EXIT:
	return retval;
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

int ia_css_program_manifest_print(
	const ia_css_program_manifest_t			*manifest,
	FILE									*fid)
{
	int			retval = -1;
	int			i, mem_index, dev_chn_index;
	vied_nci_cell_type_ID_t	cell_type_id;
	uint8_t		program_dependency_count, terminal_dependency_count;

	verifexit(manifest != NULL, EINVAL);
	verifexit(fid != NULL, EINVAL);

	fprintf(fid,"ia_css_program_manifest_print\n");
	fprintf(fid,"sizeof(manifest) = %d\n",(int)ia_css_sizeof_program_manifest(manifest));
	fprintf(fid,"program ID = %d\n",(int)ia_css_program_manifest_get_program_ID(manifest));
//	fprintf(fid,"program ID = %s\n",ia_css_program_ID_string(ia_css_program_manifest_get_program_ID(manifest)));

	if (ia_css_program_manifest_has_fixed_cell(manifest)) {
		vied_nci_cell_ID_t	cell_id = ia_css_program_manifest_get_cell_ID(manifest);
		cell_type_id = vied_nci_cell_get_type(cell_id);
		fprintf(fid,"cell(program) = %d\n",(int)cell_id);
//		fprintf(fid,"cell(program) = %s\n",vied_nci_cell_string(cell_id));
	} else {
		cell_type_id = (vied_nci_cell_type_ID_t)(manifest->cell_type_id);
	}
	fprintf(fid,"cell type(program) = %d\n",(int)cell_type_id);
//	fprintf(fid,"cell_type(program) = %s\n",vied_nci_cell_type_string(cell_type_id));

	for (mem_index = 0; mem_index < (int)VIED_NCI_N_MEM_TYPE_ID; mem_index++) {
		vied_nci_mem_type_ID_t	mem_type = vied_nci_cell_type_get_mem_type(cell_type_id, mem_index);

		fprintf(fid,"\ttype(internal mem) type = %d\n",(int)mem_type);
//		fprintf(fid,"\ttype(internal mem) type = %s\n",vied_nci_mem_type_string(mem_type));
		fprintf(fid,"\ttype(internal mem) size = %d\n",manifest->int_mem_size[mem_index]);
	}

	for (mem_index = 0; mem_index < (int)VIED_NCI_N_DATA_MEM_TYPE_ID; mem_index++) {
		vied_nci_mem_type_ID_t	mem_type = (vied_nci_mem_type_ID_t)mem_index;

		fprintf(fid,"\ttype(external mem) type = %d\n",(int)mem_type);
//		fprintf(fid,"\ttype(external mem) type = %s\n",vied_nci_mem_type_string(mem_type));
		fprintf(fid,"\ttype(external mem) size = %d\n",manifest->ext_mem_size[mem_index]);
	}

	for (dev_chn_index = 0; dev_chn_index < (int)VIED_NCI_N_DEV_CHN_ID; dev_chn_index++) {
		fprintf(fid,"\ttype(device channel) type = %d\n",(int)dev_chn_index);
//		fprintf(fid,"\ttype(device channel) type = %s\n",vied_nci_dev_chn_type_string(dev_chn_index));
		fprintf(fid,"\ttype(device channel) size = %d\n",manifest->chn_size[dev_chn_index]);
	}

	program_dependency_count = ia_css_program_manifest_get_program_dependency_count(manifest);
	if (program_dependency_count == 0) {
		fprintf(fid,"program_dependencies[%d] {};\n",program_dependency_count);
	} else {
		fprintf(fid,"program_dependencies[%d] {",program_dependency_count);
		for (i = 0; i < (int)program_dependency_count; i++) {
			fprintf(fid,"%4d, ",manifest->program_dependencies[i]);
		}
		fprintf(fid,"%4d}\n",manifest->program_dependencies[i]);
	}

	terminal_dependency_count = ia_css_program_manifest_get_terminal_dependency_count(manifest);
	if (terminal_dependency_count == 0) {
		fprintf(fid,"terminal_dependencies[%d] {};\n",terminal_dependency_count);
	} else {
		fprintf(fid,"terminal_dependencies[%d] {",terminal_dependency_count);
		for (i = 0; i < (int)terminal_dependency_count; i++) {
			fprintf(fid,"%4d, ",manifest->terminal_dependencies[i]);
		}
		fprintf(fid,"%4d}\n",manifest->terminal_dependencies[i]);
	}

	retval = 0;
EXIT:
	return retval;
}

bool ia_css_program_manifest_has_fixed_cell(
	const ia_css_program_manifest_t			*manifest)
{
	bool	has_fixed_cell = false;

	vied_nci_cell_ID_t		cell_id;
	vied_nci_cell_type_ID_t	cell_type_id;

	verifexit(manifest != NULL, EINVAL);

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

	verifexit(manifest != NULL, EINVAL);

	program_id = manifest->ID;

EXIT:
	return program_id;
}

vied_nci_cell_ID_t ia_css_program_manifest_get_cell_ID(
	const ia_css_program_manifest_t			*manifest)
{
	vied_nci_cell_ID_t		cell_id = VIED_NCI_N_CELL_ID;

	verifexit(manifest != NULL, EINVAL);

	cell_id = (vied_nci_cell_ID_t)(manifest->cell_id);
EXIT:
	return cell_id;
}

ia_css_program_param_t *ia_css_program_group_param_get_program_param(
	const ia_css_program_group_param_t		*param,
	const int								i)
{
	ia_css_program_param_t	*program_param = NULL;
	if (param != NULL) {
		program_param = param->program_param[i];
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

