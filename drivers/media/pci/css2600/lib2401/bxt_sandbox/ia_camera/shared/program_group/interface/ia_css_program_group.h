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

#ifndef __IA_CSS_PROGRAM_GROUP_H__
#define __IA_CSS_PROGRAM_GROUP_H__

#include "ia_css_frame_format.h"
#include "type_support.h"
#include "ia_css_psys_system_global.h"
#include "ia_css_frame_format.h"
#include "sh_css_uds.h"

typedef enum ia_css_terminal_type {
	IA_CSS_TERMINAL_TYPE_DATA_IN = 0,
	IA_CSS_TERMINAL_TYPE_DATA_OUT,
	IA_CSS_TERMINAL_TYPE_PARAM_STREAM,
	IA_CSS_TERMINAL_TYPE_PARAM_CACHED,
	IA_CSS_TERMINAL_TYPE_STATE_IN,
	IA_CSS_TERMINAL_TYPE_STATE_OUT,
	IA_CSS_N_TERMINAL_TYPE,
} ia_css_terminal_type_t;

typedef enum ia_css_buffer_state {
	IA_CSS_BUFFER_NULL = 0,
	IA_CSS_BUFFER_INVALID,
	IA_CSS_BUFFER_VALID,
	IA_CSS_BUFFER_EMPTY,
	IA_CSS_BUFFER_NONEMPTY,
	IA_CSS_BUFFER_FULL,
	IA_CSS_N_BUFFER_STATES
} ia_css_buffer_state_t;

typedef enum ia_css_dimension {
	IA_CSS_COL_DIMENSION = 0,
	IA_CSS_ROW_DIMENSION,
	IA_CSS_N_DATA_DIMENSION
} ia_css_dimension_t;

#define IA_CSS_N_FRAME_PLANES					6

#define IA_CSS_KERNEL_ENABLE_BITMAP_BITS		32
typedef uint32_t								ia_css_kernel_enable_bitmap_t;
#define IA_CSS_FRAME_FORMAT_BITMAP_BITS			32
typedef uint32_t								ia_css_frame_format_bitmap_t;

typedef uint32_t								ia_css_program_group_ID_t;
typedef struct ia_css_program_group_param		ia_css_program_group_param_t;
typedef struct ia_css_program_group_manifest	ia_css_program_group_manifest_t;
typedef struct ia_css_frame_descriptor			ia_css_frame_descriptor_t;
typedef struct ia_css_fragment_descriptor		ia_css_fragment_descriptor_t;
typedef enum ia_css_frame_format				ia_css_frame_format_type_t;

typedef uint32_t								ia_css_program_ID_t;
typedef struct ia_css_program_param				ia_css_program_param_t;
typedef struct ia_css_terminal_param			ia_css_terminal_param_t;
typedef struct ia_css_terminal_manifest			ia_css_terminal_manifest_t;
typedef struct ia_css_program_manifest			ia_css_program_manifest_t;

/* tentative; co-design with ISP algorithm */
struct ia_css_program_group_param {
	uint16_t							fragment_count;
	uint8_t								program_count;
	uint32_t							program_param_offset;
};

/* public */
struct ia_css_terminal_param {
	uint32_t							frame_settings;
};

struct ia_css_terminal_manifest {
	uint32_t							size;											/**< Size of this structure */
	ia_css_terminal_type_t				terminal_type;									/**< Type {in, out, state, ...} */
	ia_css_frame_format_bitmap_t		frame_format_bitmap;							/**< Supported (4CC / MIPI) formats */
	uint16_t							terminal_dependency;							/**< Indicate if this terminal is derived from a principal terminal */
	uint16_t							min_size[IA_CSS_N_DATA_DIMENSION];				/**< Minimum size of the frame */
	uint16_t							max_size[IA_CSS_N_DATA_DIMENSION];				/**< Maximum size of the frame */
	uint16_t							min_fragment_size[IA_CSS_N_DATA_DIMENSION];		/**< Minimum size of a fragment that the program port can accept */
	uint16_t							max_fragment_size[IA_CSS_N_DATA_DIMENSION];		/**< Maximum size of a fragment that the program port can accept */
};

/* private */
struct ia_css_program_group_manifest {
	uint32_t							size;											/**< Size of this structure */
	ia_css_program_group_ID_t			ID;												/**< Referal ID to program group FW */
	uint8_t								program_count;									/**< Total number of program in this program group */
	uint8_t								terminal_count;									/**< Total number of terminals on this program group */
	uint32_t							program_manifest_offset;
	uint32_t							terminal_manifest_offset;
};

/* private */
struct ia_css_program_manifest {
	uint32_t							size;											/**< Size of this structure */
	ia_css_program_ID_t					ID;												/**< Referal ID to a specific program FW, valid ID's != 0 */
	vied_nci_resource_id_t				cell_id;										/**< (optional) specification of a cell to be used by this program */
	vied_nci_resource_id_t				cell_type_id;									/**< (exclusive) indication of a cell type to be used by this program */
	vied_nci_resource_size_t			int_mem_size[VIED_NCI_N_MEM_TYPE_ID];			/**< (internal) Memory allocation size needs of this program */
	vied_nci_resource_size_t			ext_mem_size[VIED_NCI_N_DATA_MEM_TYPE_ID];		/**< (external) Memory allocation size needs of this program */
	vied_nci_resource_size_t			chn_size[VIED_NCI_N_DEV_CHN_ID];				/**< Device channel allocation size needs of this program */
	uint8_t								program_dependency_count;						/**< Number of programs this program depends on */
	uint8_t								terminal_dependency_count;						/**< Number of terminals this program depends on */
	uint32_t							program_dependency_offset;
	uint32_t							terminal_dependency_offset;
};

struct ia_css_frame_descriptor {
	ia_css_frame_format_type_t			frame_format_type;
	uint8_t								access_unit_size;							/**< Size of each packed logical element */
	uint8_t								bit_depth;									/**< (approximate) Nominal accuracy of a single datum */
	uint32_t							plane_offsets[IA_CSS_N_FRAME_PLANES];		/**< Plane offsets accounting for fragments */
	uint16_t							size[IA_CSS_N_DATA_DIMENSION];				/**< Logical size */
	uint32_t							stride[IA_CSS_N_DATA_DIMENSION - 1];		/**< Physical size aspects */
};

/*
 * All cropping and padding effects are described by the difference between
 * the frame size and its location and the fragment size(s) and location(s)
 */
struct ia_css_fragment_descriptor {
	uint16_t							size[IA_CSS_N_DATA_DIMENSION];
	uint16_t							index[IA_CSS_N_DATA_DIMENSION];
	uint16_t							offset[IA_CSS_N_DATA_DIMENSION];
};

struct ia_css_program_param {
	ia_css_kernel_enable_bitmap_t		kernel_enable_bitmap;
};


extern size_t ia_css_program_group_param_get_size(
	const ia_css_program_group_param_t *manifest);

extern size_t ia_css_sizeof_program_group_param(
	const uint8_t							program_count,
	const uint16_t							fragment_count);

extern void ia_css_program_group_param_init(
	ia_css_program_group_param_t *blob,
	const uint8_t	program_count,
	const uint16_t	fragment_count);

extern ia_css_program_group_param_t *ia_css_program_group_param_alloc(
	const uint8_t							program_count,
	const uint16_t							fragment_count);

extern ia_css_program_group_param_t *ia_css_program_group_param_free(
	ia_css_program_group_param_t			*program_group_param);

extern size_t ia_css_program_group_manifest_get_size(
	const ia_css_program_group_manifest_t	*manifest);

extern size_t ia_css_sizeof_program_group_manifest(
	const uint8_t program_count,
	const uint8_t terminal_count);

extern void ia_css_program_group_manifest_init(
	ia_css_program_group_manifest_t *blob,
	const uint8_t	program_count,
	const uint8_t	terminal_count);

extern uint8_t ia_css_program_group_manifest_get_program_count(
	const ia_css_program_group_manifest_t	*manifest);

extern uint8_t ia_css_program_group_manifest_get_terminal_count(
	const ia_css_program_group_manifest_t	*manifest);

extern ia_css_program_manifest_t *ia_css_program_group_manifest_get_program_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						program_index);

extern ia_css_terminal_manifest_t *ia_css_program_group_manifest_get_terminal_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						terminal_index);

#endif /* __IA_CSS_PROGRAM_GROUP_H__ */
