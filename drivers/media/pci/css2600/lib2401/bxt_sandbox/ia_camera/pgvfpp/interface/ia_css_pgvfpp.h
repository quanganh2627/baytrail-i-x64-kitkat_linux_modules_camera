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

#ifndef __IA_CSS_PGVFPP_H__
#define __IA_CSS_PGVFPP_H__

#include "ia_css_program_group.h"

extern ia_css_program_group_manifest_t *
ia_camera_vfpp_opt_program_group_manifest_alloc(void);

extern ia_css_program_group_manifest_t *
ia_camera_vfpp_full_program_group_manifest_alloc(void);

extern ia_css_program_group_param_t *
ia_camera_vfpp_program_group_param_alloc(void);

extern void *ia_camera_vfpp_cached_param_alloc(
	ia_css_frame_descriptor_t *in_desc,
	ia_css_frame_descriptor_t *out_desc);

extern void ia_camera_vfpp_cached_param_free(void *param_type5);
extern uint32_t ia_camera_sizeof_vfpp_cached_param(void);

/* TODO: Add symmetic _free() api's if something special needs to be done for
 * each PG while being freed. Otherwise, use base program_group_free() */

#endif /* __IA_CSS_PGVFPP_H__ */
