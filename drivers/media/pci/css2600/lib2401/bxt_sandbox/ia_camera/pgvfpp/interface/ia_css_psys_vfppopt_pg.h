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

#ifndef __IA_CSS_PSYS_VFPPOPT_PG_H__
#define __IA_CSS_PSYS_VFPPOPT_PG_H__

#include "type_support.h"
#include "ia_css_pg_info.h"
#include "ia_css_psys_frameadapter.h"

/*****************************************************************************
* Get
* 1. the pg info for vfpp
* 2. populate buffers to be used with param terminals for vfpp.
*****************************************************************************/

/* Get the size of vfpp param object. This can be used to allocate memory for a
 * parameter buffer */
uint32_t ia_css_vfppopt_pg_get_size(void);
/* Get the size of vfpp pg info object. This can be used to allocate memory for a
 * vfpp pg info (including terminals, its attributes, program info, etc)*/
extern uint32_t ia_css_vfppopt_pg_get_param_size(void);


/* "param_buffer" is allocated with size obtained from
 * ia_css_vfppopt_pg_get_param_size(). This function will populate the buffer
 * based on input and output frame headers for the process. */
extern void ia_css_get_vfppopt_pg_get_param(
	void *param_buffer,
	struct ia_css_pg_frame_info *in_frame_info,
	struct ia_css_pg_frame_info *out_frame_info);

/* TODO: These can be generic function of program group */
extern uint32_t ia_css_vfppopt_pg_get_num_terminals(void);
extern uint32_t ia_css_vfppopt_pg_get_num_programs(void);

uint32_t ia_css_vfppopt_pg_get_num_io_formats(uint8_t input);

extern void ia_css_vfppopt_pg_get_pginfo(struct ia_css_pg_info *pg_info);

extern void ia_css_vfppopt_pg_get_param(
	void *param_buffer,
	struct ia_css_pg_frame_info *in_frame_info,
	struct ia_css_pg_frame_info *out_frame_info);

#endif /* __IA_CSS_PSYS_VFPPOPT_PG_H__ */
