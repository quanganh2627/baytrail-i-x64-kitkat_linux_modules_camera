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

#ifndef _IA_CSS_BUFQ_H
#define _IA_CSS_BUFQ_H

#include <type_support.h>
#include "ia_css_bufq_comm.h"

/**
 * @brief Query the internal frame ID.
 *
 * @param[in]	key	The query key.
 * @param[out]	val	The query value.
 *
 * @return
 *	true, if the query succeeds;
 *	false, if the query fails.
 */
bool ia_css_query_internal_queue_id(enum ia_css_buffer_type buf_type,
	unsigned int thread_id,
	enum sh_css_queue_id *val);

void ia_css_queue_map(unsigned int thread_id,
	enum ia_css_buffer_type buf_type,
	bool map);

void ia_css_queue_map_init(void);
#endif
