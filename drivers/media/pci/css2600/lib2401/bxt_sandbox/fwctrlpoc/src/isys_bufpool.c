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

#include "ia_css_buffer_pool.h"
#include "memory_access.h"

#include "type_support.h"
#include "assert_support.h"
#include "error_support.h"
#include "sh_css_internal.h"
#include "ia_css_isyspoc_comm.h"

#define HOST_MALLOC        sh_css_malloc
#define HOST_FREE          sh_css_free

typedef struct _isys_msg_buf_t
{
	bool free;
	hrt_vaddress isys_msg;
} isys_msg_buf_t;

static int init(
	struct ia_css_buffer_pool *this_bufpool,
	unsigned int num_bufs
);

static void uinit(struct ia_css_buffer_pool *this_bufpool);

static hrt_vaddress acquire_buf(struct ia_css_buffer_pool *this_bufpool);

static void release_buf(
	struct ia_css_buffer_pool *this_bufpool,
	hrt_vaddress buffer
);

void ia_css_create_isys_bufpool(
	struct ia_css_buffer_pool *isys_bufpool
) {

	assert(isys_bufpool != NULL);

	isys_bufpool->init = &init;
	isys_bufpool->uinit = &uinit;
	isys_bufpool->acquire_buf = &acquire_buf;
	isys_bufpool->release_buf = &release_buf;

	return;
}

static int init(
	struct ia_css_buffer_pool *this_bufpool,
	unsigned int num_bufs
) {

	int ret=0;
	unsigned int i;
	isys_msg_buf_t *iter;

	assert(this_bufpool != NULL);
	assert(num_bufs > 0);
	this_bufpool->num_buffers = num_bufs;

	this_bufpool->pool_head = HOST_MALLOC(num_bufs * sizeof(isys_msg_buf_t));
	if(this_bufpool->pool_head == NULL) {
		return ENOMEM;
	}

	iter = (isys_msg_buf_t *) this_bufpool->pool_head;
	for (i=0; i < this_bufpool->num_buffers; i++)
	{
		iter->isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
		if (iter->isys_msg == mmgr_NULL) {
			return ENOMEM;
		}
		iter->free = true;
		iter++;
	}

	return ret;
}

static void uinit(struct ia_css_buffer_pool *this_bufpool)
{
	unsigned int i;
	isys_msg_buf_t *iter;
	assert(this_bufpool != NULL);
	assert(this_bufpool->pool_head != NULL);

	iter = (isys_msg_buf_t *) this_bufpool->pool_head;
	for (i=0; i < this_bufpool->num_buffers; i++)
	{
		 mmgr_free(iter->isys_msg);
		iter->free = false;
		iter++;
	}

	HOST_FREE(this_bufpool->pool_head);
	this_bufpool->pool_head = NULL;
	this_bufpool->num_buffers = 0;
}

static hrt_vaddress acquire_buf(struct ia_css_buffer_pool *this_bufpool)
{
	unsigned int i;
	isys_msg_buf_t *iter;

	assert(this_bufpool != NULL);
	assert(this_bufpool->pool_head != NULL);

	iter = (isys_msg_buf_t *) this_bufpool->pool_head;

	for (i=0; i < this_bufpool->num_buffers; i++)
	{
		if(iter->free == true)
		{
			iter->free = false;
			return iter->isys_msg;
		}
		iter++;
	}

	return mmgr_NULL;
}

static void release_buf(
	struct ia_css_buffer_pool *this_bufpool,
	hrt_vaddress buffer
) {
	unsigned int i;
	isys_msg_buf_t *iter;

	assert(this_bufpool != NULL);
	assert(this_bufpool->pool_head != NULL);

	iter = (isys_msg_buf_t *) this_bufpool->pool_head;

	for (i=0; i < this_bufpool->num_buffers; i++)
	{
		if ((iter->free == false) &&
			(iter->isys_msg == buffer))
		{
			iter->free = true;
			return;
		}
		iter++;
	}

	return;
}
