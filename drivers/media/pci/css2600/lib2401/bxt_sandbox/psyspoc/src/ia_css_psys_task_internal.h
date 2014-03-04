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

#ifndef __IA_CSS_PSYS_TASK_INTERNAL_H__
#define __IA_CSS_PSYS_TASK_INTERNAL_H__

#include "ia_css_psysapi.h"
#include "ia_css_pg_info.h"
#include "ia_css_binary.h"
#include "ia_css_psys_cmd_comm.h"

#define IA_CSS_PSYSAPI_MAX_TERMINALS 10

struct ia_css_psys_task {
	struct ia_css_psysapi_task_buffer task_buffer;
	struct ia_css_pg_info *pg_info;
	struct ia_css_psysapi_cmd cmd;
	struct ia_css_binary binary;
	/* ASK: Assuming one terminal per buffer */
	struct ia_css_psys_buffer *terminals[IA_CSS_PSYSAPI_MAX_TERMINALS];
	void *cookie;
};

#endif /* __IA_CSS_PSYS_TASK_INTERNAL_H__ */
