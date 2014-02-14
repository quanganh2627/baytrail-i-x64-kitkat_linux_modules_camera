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

#include "assert_support.h"
#include "ia_css_bufq.h"
#include "ia_css_debug.h"

/*******************************************************
*** Static variables
********************************************************/
static int buffer_type_to_queue_id_map[SH_CSS_MAX_SP_THREADS][IA_CSS_NUM_DYNAMIC_BUFFER_TYPE];
static bool queue_availability[SH_CSS_MAX_SP_THREADS][SH_CSS_MAX_NUM_QUEUES];

/*******************************************************
*** Static functions
********************************************************/
static void map_buffer_type_to_queue_id(unsigned int thread_id,
	enum ia_css_buffer_type buf_type);
static void unmap_buffer_type_to_queue_id(unsigned int thread_id,
	enum ia_css_buffer_type buf_type);

/*******************************************************
*** Public functions
********************************************************/
void ia_css_queue_map_init(void)
{
	unsigned int i, j;

	for (i = 0; i < SH_CSS_MAX_SP_THREADS; i++) {
		for (j = 0; j < SH_CSS_MAX_NUM_QUEUES; j++) {
			queue_availability[i][j] = true;
		}
	}

	for (i = 0; i < SH_CSS_MAX_SP_THREADS; i++) {
		for (j = 0; j < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE; j++) {
			buffer_type_to_queue_id_map[i][j] = SH_CSS_INVALID_QUEUE_ID;
		}
	}
}

void ia_css_queue_map(unsigned int thread_id,
	enum ia_css_buffer_type buf_type,
	bool map)
{
	assert(buf_type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE);
	assert(thread_id < SH_CSS_MAX_SP_THREADS);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_queue_map() enter: buf_type=%d, thread_id=%d\n", buf_type, thread_id);

	if(map) {
		map_buffer_type_to_queue_id(thread_id, buf_type);
	} else {
		unmap_buffer_type_to_queue_id(thread_id, buf_type);
	}
}

/**
 * @brief Query the internal queue ID.
 */
bool ia_css_query_internal_queue_id(enum ia_css_buffer_type buf_type,
	unsigned int thread_id,
	enum sh_css_queue_id *val)
{
	assert(buf_type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE);
	assert(thread_id < SH_CSS_MAX_SP_THREADS);
	assert(val != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_query_internal_queue_id() enter: buf_type=%d, thread_id=%d\n", buf_type, thread_id);
	*val = buffer_type_to_queue_id_map[thread_id][buf_type];
	assert(*val != SH_CSS_INVALID_QUEUE_ID);
	assert(*val < SH_CSS_MAX_NUM_QUEUES);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_query_internal_queue_id() leave: return_val=%d\n",
		*val);
	return true;
}

/*******************************************************
*** Static functions
********************************************************/
static void map_buffer_type_to_queue_id(unsigned int thread_id,
	enum ia_css_buffer_type buf_type)
{
	unsigned int i;

	assert(thread_id < SH_CSS_MAX_SP_THREADS);
	assert(buf_type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE);
	assert(buffer_type_to_queue_id_map[thread_id][buf_type] == SH_CSS_INVALID_QUEUE_ID);

	//queue 0 is reserved for parameter because it doesn't depend on events
	if (buf_type == IA_CSS_BUFFER_TYPE_PARAMETER_SET) {
		assert(queue_availability[thread_id][0] == true);
		queue_availability[thread_id][0] = false;
		buffer_type_to_queue_id_map[thread_id][buf_type] = IA_CSS_PARAMETER_SET_QUEUE_ID;
		return;
	}

	for (i = 1; i < SH_CSS_MAX_NUM_QUEUES; i++) {
		if (queue_availability[thread_id][i] == true) {
			queue_availability[thread_id][i] = false;
			buffer_type_to_queue_id_map[thread_id][buf_type] = i;
			break;
		}
	}

	assert(i != SH_CSS_MAX_NUM_QUEUES);
	return;
}

static void unmap_buffer_type_to_queue_id(unsigned int thread_id,
	enum ia_css_buffer_type buf_type)
{
	int queue_id;

	assert(thread_id < SH_CSS_MAX_SP_THREADS);
	assert(buf_type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE);
	assert(buffer_type_to_queue_id_map[thread_id][buf_type] != SH_CSS_INVALID_QUEUE_ID);

	queue_id = buffer_type_to_queue_id_map[thread_id][buf_type];
	buffer_type_to_queue_id_map[thread_id][buf_type] = SH_CSS_INVALID_QUEUE_ID;
	queue_availability[thread_id][queue_id] = true;
}
