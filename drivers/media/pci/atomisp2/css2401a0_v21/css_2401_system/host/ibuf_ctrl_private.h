/* Release Version: ci_master_20131024_0113 */
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

#ifndef __IBUF_CTRL_PRIVATE_H_INCLUDED__
#define __IBUF_CTRL_PRIVATE_H_INCLUDED__

#include "ibuf_ctrl_public.h"

#include "device_access.h"	/* ia_css_device_load_uint32 */

#include "assert_support.h" /* assert */


/*****************************************************
 *
 * Native command interface (NCI).
 *
 *****************************************************/
/**
 * @brief Get the ibuf-controller state.
 * Refer to "ibuf_ctrl_public.h" for details.
 */
STORAGE_CLASS_IBUF_CTRL_C void ibuf_ctrl_get_state(
		const ibuf_ctrl_ID_t ID,
		ibuf_ctrl_state_t *state)
{
	uint32_t i;

	state->recalc_words =
		ibuf_ctrl_reg_load(ID, _IBUF_CNTRL_RECALC_WORDS_STATUS);
	state->arbiters =
		ibuf_ctrl_reg_load(ID, _IBUF_CNTRL_ARBITERS_STATUS);

	/*
	 * Get the values of the register-set per
	 * ibuf-controller process.
	 */
	for (i = 0; i < N_IBUF_CTRL_PROCS[ID]; i++) {
		ibuf_ctrl_get_proc_state(
				ID,
				i,
				&(state->proc_state[i]));
	}
}

/**
 * @brief Get the state of the ibuf-controller process.
 * Refer to "ibuf_ctrl_public.h" for details.
 */
STORAGE_CLASS_IBUF_CTRL_C void ibuf_ctrl_get_proc_state(
		const ibuf_ctrl_ID_t ID,
		const uint32_t proc_id,
		ibuf_ctrl_proc_state_t	*state)
{
	hrt_address reg_bank_offset;

	reg_bank_offset =
		_IBUF_CNTRL_PROC_REG_ALIGN * (1 + proc_id);

	state->num_items =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_NUM_ITEMS_PER_STORE);

	state->num_stores =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_NUM_STORES_PER_FRAME);

	state->dma_channel =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DMA_CHANNEL);

	state->dma_command =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DMA_CMD);

	state->ibuf_st_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_BUFFER_START_ADDRESS);

	state->ibuf_stride =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_BUFFER_STRIDE);

	state->ibuf_end_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_BUFFER_END_ADDRESS);

	state->dest_st_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DEST_START_ADDRESS);

	state->dest_stride =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DEST_STRIDE);

	state->dest_end_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DEST_END_ADDRESS);

	state->sync_frame =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_SYNC_FRAME);

	state->sync_command =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_STR2MMIO_SYNC_CMD);

	state->store_command =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_STR2MMIO_STORE_CMD);

	state->shift_returned_items =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_SHIFT_ITEMS);

	state->elems_ibuf =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_ELEMS_P_WORD_IBUF);

	state->elems_dest =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_ELEMS_P_WORD_DEST);

	state->cur_stores =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_STORES);

	state->cur_acks =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_ACKS);

	state->cur_s2m_ibuf_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_S2M_IBUF_ADDR);

	state->cur_dma_ibuf_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_DMA_IBUF_ADDR);

	state->cur_dma_dest_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_DMA_DEST_ADDR);

	state->cur_isp_dest_addr =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_ISP_DEST_ADDR);

	state->dma_cmds_send =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_CUR_NR_DMA_CMDS_SEND);

	state->main_cntrl_state =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_MAIN_CNTRL_STATE);

	state->dma_sync_state =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_DMA_SYNC_STATE);

	state->isp_sync_state =
		ibuf_ctrl_reg_load(ID, reg_bank_offset + _IBUF_CNTRL_ISP_SYNC_STATE);
}
/** end of NCI */

/*****************************************************
 *
 * Device level interface (DLI).
 *
 *****************************************************/
/**
 * @brief Load the register value.
 * Refer to "ibuf_ctrl_public.h" for details.
 */
STORAGE_CLASS_IBUF_CTRL_C hrt_data ibuf_ctrl_reg_load(
	const ibuf_ctrl_ID_t ID,
	const hrt_address reg)
{
	assert(ID < N_IBUF_CTRL_ID);
	assert(IBUF_CTRL_BASE[ID] != (hrt_address)-1);
	return ia_css_device_load_uint32(IBUF_CTRL_BASE[ID] + reg*sizeof(hrt_data));
}


/**
 * @brief Store a value to the register.
 * Refer to "ibuf_ctrl_public.h" for details.
 */
STORAGE_CLASS_IBUF_CTRL_C void ibuf_ctrl_reg_store(
	const ibuf_ctrl_ID_t ID,
	const hrt_address reg,
	const hrt_data value)
{
	assert(ID < N_IBUF_CTRL_ID);
	assert(IBUF_CTRL_BASE[ID] != (hrt_address)-1);

	ia_css_device_store_uint32(IBUF_CTRL_BASE[ID] + reg*sizeof(hrt_data), value);
}
/** end of DLI */


#endif /* __IBUF_CTRL_PRIVATE_H_INCLUDED__ */
