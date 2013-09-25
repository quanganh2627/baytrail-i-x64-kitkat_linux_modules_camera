/* Release Version: ci_master_20131001_0952 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2013 Intel Corporation. All Rights Reserved.
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

#ifndef __DEBUG_PRIVATE_H_INCLUDED__
#define __DEBUG_PRIVATE_H_INCLUDED__

#include "debug_public.h"

#include "sp.h"

#define __INLINE_ISP__
#include "isp.h"

#include "memory_access.h"

#include "assert_support.h"

STORAGE_CLASS_DEBUG_C bool is_debug_buffer_empty(void)
{
return (debug_data_ptr->head == debug_data_ptr->tail);
}

STORAGE_CLASS_DEBUG_C hrt_data debug_dequeue(void)
{
	hrt_data	value = 0;

assert(debug_buffer_address != ((hrt_address)-1));

	debug_synch_queue();

	if (!is_debug_buffer_empty()) {
		value = debug_data_ptr->buf[debug_data_ptr->head];
		debug_data_ptr->head = (debug_data_ptr->head + 1) & DEBUG_BUF_MASK;
		sp_dmem_store_uint32(SP0_ID, debug_buffer_address + DEBUG_DATA_HEAD_ADDR, debug_data_ptr->head);
	}

return value;
}

STORAGE_CLASS_DEBUG_C void debug_synch_queue(void)
{
	uint32_t	remote_tail	= sp_dmem_load_uint32(SP0_ID, debug_buffer_address + DEBUG_DATA_TAIL_ADDR);
/* We could move the remote head after the upload, but we would have to limit the upload w.r.t. the local head. This is easier */
	if (remote_tail > debug_data_ptr->tail) {
		size_t	delta = remote_tail - debug_data_ptr->tail;
		sp_dmem_load(SP0_ID, debug_buffer_address + DEBUG_DATA_BUF_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
	} else if (remote_tail < debug_data_ptr->tail) {
		size_t	delta = DEBUG_BUF_SIZE - debug_data_ptr->tail;
		sp_dmem_load(SP0_ID, debug_buffer_address + DEBUG_DATA_BUF_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
		sp_dmem_load(SP0_ID, debug_buffer_address + DEBUG_DATA_BUF_ADDR, (void *)&(debug_data_ptr->buf[0]), remote_tail*sizeof(uint32_t));
	} /* else we are up to date */
	debug_data_ptr->tail = remote_tail;
return;
}

STORAGE_CLASS_DEBUG_C void debug_synch_queue_isp(void)
{
	uint32_t	remote_tail	= isp_dmem_load_uint32(ISP0_ID, DEBUG_BUFFER_ISP_DMEM_ADDR + DEBUG_DATA_TAIL_ADDR);
/* We could move the remote head after the upload, but we would have to limit the upload w.r.t. the local head. This is easier */
	if (remote_tail > debug_data_ptr->tail) {
		size_t	delta = remote_tail - debug_data_ptr->tail;
		isp_dmem_load(ISP0_ID, DEBUG_BUFFER_ISP_DMEM_ADDR + DEBUG_DATA_BUF_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
	} else if (remote_tail < debug_data_ptr->tail) {
		size_t	delta = DEBUG_BUF_SIZE - debug_data_ptr->tail;
		isp_dmem_load(ISP0_ID, DEBUG_BUFFER_ISP_DMEM_ADDR + DEBUG_DATA_BUF_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
		isp_dmem_load(ISP0_ID, DEBUG_BUFFER_ISP_DMEM_ADDR + DEBUG_DATA_BUF_ADDR, (void *)&(debug_data_ptr->buf[0]), remote_tail*sizeof(uint32_t));
	} /* else we are up to date */
	debug_data_ptr->tail = remote_tail;
return;
}

STORAGE_CLASS_DEBUG_C void debug_synch_queue_ddr(void)
{
	uint32_t	remote_tail;

	mmgr_load(debug_buffer_ddr_address + DEBUG_DATA_TAIL_DDR_ADDR, &remote_tail, sizeof(uint32_t));
/* We could move the remote head after the upload, but we would have to limit the upload w.r.t. the local head. This is easier */
	if (remote_tail > debug_data_ptr->tail) {
		size_t	delta = remote_tail - debug_data_ptr->tail;
		mmgr_load(debug_buffer_ddr_address + DEBUG_DATA_BUF_DDR_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
	} else if (remote_tail < debug_data_ptr->tail) {
		size_t	delta = DEBUG_BUF_SIZE - debug_data_ptr->tail;
		mmgr_load(debug_buffer_ddr_address + DEBUG_DATA_BUF_DDR_ADDR + debug_data_ptr->tail*sizeof(uint32_t), (void *)&(debug_data_ptr->buf[debug_data_ptr->tail]), delta*sizeof(uint32_t));
		mmgr_load(debug_buffer_ddr_address + DEBUG_DATA_BUF_DDR_ADDR, (void *)&(debug_data_ptr->buf[0]), remote_tail*sizeof(uint32_t));
	} /* else we are up to date */
	debug_data_ptr->tail = remote_tail;
return;
}

#endif /* __DEBUG_PRIVATE_H_INCLUDED__ */

