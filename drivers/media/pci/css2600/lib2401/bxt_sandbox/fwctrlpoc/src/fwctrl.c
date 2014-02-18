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

#include "ia_css.h"
#include "ia_css_acc_types.h"
#include "ia_css_spctrl.h"
#include "ia_css_debug.h"
#include "platform_support.h"	/* hrt_sleep() */
#include "error_support.h"
#include "mmu_device.h"
#include "sp.h"
#include "ia_css_pocapp_comm.h" /*bxt_poc_host_sp_queues SP_SW_EVENT_ISYS/PSYS*/
#include "ia_css_circbuf_comm.h" /* ia_css_circbuf_desc_t*/
#include "ia_css_queue.h"        /* ia_css_queue_t */
#include "ia_css_fwctrl_public.h"
#include "ia_css_fwctrl.h"

#define SP_START_TIMEOUT_US		200000
#define SP_STOP_TIMEOUT_US		200000

/* Name of the sp program: should not be built-in */
#define SP_PROG_NAME "sp"

/* host side handles of all queues */
struct fwctrl_comm_queues_s {
	ia_css_queue_t host2sp_isys_q_handle;
	ia_css_queue_t sp2host_isys_q_handle;
	ia_css_queue_t host2sp_psys_q_handle;
	ia_css_queue_t sp2host_psys_q_handle;
	ia_css_queue_t host2sp_generic_q_handle;
	ia_css_queue_t sp2host_generic_q_handle;
};
typedef struct fwctrl_comm_queues_s fwctrl_comm_queues_t;

/* Host SP communication queues */
fwctrl_comm_queues_t fwctrl_comm_queues;

/*This is used to maintain the state for device open/close
if PSYS/ISYS driver separately call this API*/
static int ref_count = 0;

static bool fwctrl_configure_spctrl(
	const struct ia_css_fw_info *fw,
	const char * program,
	ia_css_spctrl_cfg  *spctrl_cfg
);

static bool fwctrl_configure_spctrl(
	const struct ia_css_fw_info *fw,
	const char * program,
	ia_css_spctrl_cfg  *spctrl_cfg
)
{
	if((fw == NULL)||(spctrl_cfg == NULL))
		return false;
	spctrl_cfg->sp_entry = 0;
	spctrl_cfg->program_name = (char *)(program);

#if !defined(C_RUN) && !defined(HRT_UNSCHED)
	spctrl_cfg->ddr_data_offset =  fw->blob.data_source;
	spctrl_cfg->dmem_data_addr = fw->blob.data_target;
	spctrl_cfg->dmem_bss_addr = fw->blob.bss_target;
	spctrl_cfg->data_size = fw->blob.data_size ;
	spctrl_cfg->bss_size = fw->blob.bss_size;

	spctrl_cfg->spctrl_config_dmem_addr = fw->info.sp.init_dmem_data;
	spctrl_cfg->spctrl_state_dmem_addr = fw->info.sp.sw_state;

	spctrl_cfg->code_size = fw->blob.size;
	spctrl_cfg->code      = fw->blob.code;
	spctrl_cfg->sp_entry  = fw->info.sp.sp_entry; /* entry function ptr on SP */
#endif
	return true;
}

static int fwctrl_sp_start(struct ia_css_fwctrl_devconfig *device_config)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "fwctrl_sp_start() enter: void\n");
	if (IA_CSS_SP_SW_TERMINATED == ia_css_spctrl_get_state(SP0_ID))
	{
		enum ia_css_err err;
		ia_css_spctrl_cfg spctrl_cfg;
		const struct ia_css_fw_info *fw;
		unsigned int HIVE_ADDR_sp_sw_state;
		unsigned int HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
		unsigned long timeout;

		fw = (const struct ia_css_fw_info *) device_config->firmware_address;
		HIVE_ADDR_sp_sw_state = fw->info.sp.sw_state;
		HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb = fw->info.sp.invalidate_tlb;

		(void)HIVE_ADDR_sp_sw_state; /* Suppres warnings in CRUN */
		(void)HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb; /* Suppres warnings in CRUN */

		if(!fwctrl_configure_spctrl(fw,SP_PROG_NAME,&spctrl_cfg))
			return IA_CSS_ERR_INTERNAL_ERROR;

		err = ia_css_spctrl_load_fw(SP0_ID, &spctrl_cfg);
		if (err != IA_CSS_SUCCESS) {
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "fwctrl_sp_start() leave: return_err=%d\n",err);
			return err;
		}

		sp_dmem_store_uint32(SP0_ID,
			(unsigned int)sp_address_of(ia_css_dmaproxy_sp_invalidate_tlb),
			true);

		/* Invalidate all MMU caches */
		mmu_invalidate_cache_all();

		ia_css_spctrl_start(SP0_ID);

		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "fwctrl_sp_start() waiting for sp\n");

        /* waiting for the SP is completely started */
		timeout = SP_START_TIMEOUT_US;
		while((ia_css_spctrl_get_state(SP0_ID) != IA_CSS_SP_SW_INITIALIZED) && timeout) {
			timeout--;
			hrt_sleep();
		}
		if (timeout == 0) {
			ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR, "fwctrl_sp_start() timeout\n");
			return IA_CSS_ERR_INTERNAL_ERROR;
		}
	}
	return 0;

}

static void fwctrl_init_queues(
	struct ia_css_fwctrl_devconfig *device_config
)
{
	ia_css_queue_remote_t remoteq;
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "fwctrl_init_queues()entered \n ");

	/*NOTE: this function's client should make sure
	 * fwctrl_sp_start() is called before this */

	 /*get DMEM queues base address*/
	fw = (const struct ia_css_fw_info *) device_config->firmware_address;
#ifdef C_RUN
	HIVE_ADDR_ia_css_bufq_host_sp_queue = (unsigned int)
		sp_address_of(ia_css_bufq_host_sp_queue);
#else
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	remoteq.location = IA_CSS_QUEUE_LOC_SP;
	remoteq.proc_id = SP0_ID;

	/* Queue Initlaizations :
	 * These queues are present in sp's DMEM(hence are remote to host) and
	 * by now (must have)already been initialized by SP via fwctrl_sp_start().
	 * With following calls, we get a host handle.*/

	/*initialize generic host2sp queues . */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_event_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_event_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.host2sp_generic_q_handle, &remoteq);

	/*initialize generic sp2host queue  */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_event_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_event_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.sp2host_generic_q_handle, &remoteq);

       /*initialize isys host2sp queue */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_isys_cmd_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_isys_cmd_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.host2sp_isys_q_handle, &remoteq);


       /*initialize isys sp2host queue */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_isys_event_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_isys_event_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.sp2host_isys_q_handle, &remoteq);

	/*initialize psys queues on host side*/
	/*initialize psys host2sp queue */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_psys_cmd_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						host2sp_psys_cmd_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.host2sp_psys_q_handle, &remoteq);


	/*initialize psys sp2host queue */
	remoteq.cb_desc_addr =  (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_psys_event_queue_desc));
	remoteq.cb_elems_addr = (uint32_t)(HIVE_ADDR_ia_css_bufq_host_sp_queue
				+ offsetof(struct bxt_poc_host_sp_queues,
						sp2host_psys_event_queue_elems));
	ia_css_queue_remote_init(&fwctrl_comm_queues.sp2host_psys_q_handle, &remoteq);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "fwctrl_init_queues() exit\n ");
}

static int fwctrl_sp_has_finished()
{
	/* TODO: read a DMEM variable flag from SP */
	 return false;
}

static int fwctrl_sp_sync_stop()
{
	int ret = -1;
	unsigned long timeout;
	timeout = SP_STOP_TIMEOUT_US;
	while (!fwctrl_sp_has_finished() && timeout){
		timeout--;
		hrt_sleep();
	}
	ret = 0;
	return ret;
}


int ia_css_fwctrl_device_open(
	struct ia_css_fwctrl_devconfig *device_config
)
{
	int status = 1;
	ref_count = ref_count + 1 ;
	if(ref_count == 1)
	{
		if(device_config == NULL)
			return 1;
		status = fwctrl_sp_start(device_config);
		if( status != 0)
			return status;
		fwctrl_init_queues(device_config);
	}
	else
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "Device is already open ref_count =%d\n", ref_count);
	return status;
}

int ia_css_fwctrl_device_close(void)
{
	int ret = 0;
	ref_count = ref_count - 1 ;
	if(ref_count == 0)
	{
		ret = fwctrl_sp_sync_stop();
		if( ret != 0)
			return ret;
	}
	return ret;
}

/**********************************************************************************/
/* TODO: This function will be made generic by passing queue handle and message */
/**********************************************************************************/
int ia_css_fwctrl_isys_send_msg(
	const hrt_vaddress payload
)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "isyspoc_send_msg() : entered  payload = 0x%x \n", payload);

	/* enqueue it in ISYS command queue*/
	if (IA_CSS_SUCCESS != ia_css_queue_enqueue(
				&fwctrl_comm_queues.host2sp_isys_q_handle,
				payload)){
		return ENOTCONN;
	}
	else{
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "isyspoc_send_msg()\
				host2sp_isys_q_handle isys enqueue (0x%x) success\n", payload);

		/* send ISYS signal to SP, by posting a flag in generic queue.*/
		/*TODO: CHECK RETURN TYPE*/
		ia_css_queue_enqueue(
				&fwctrl_comm_queues.host2sp_generic_q_handle,
				SP_SW_EVENT_ISYS);
	}

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "isyspoc_send_msg() : leaving \n");

	return 0;
}

/**********************************************************************************/
/* TODO: This function will be made generic by passing queue handle and message */
/**********************************************************************************/
int ia_css_fwctrl_isys_receive_msg(
	hrt_vaddress *payload
)
{
	int ret = 0;
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "isyspoc_receive_msg() : entered \n");

	if (IA_CSS_SUCCESS != ia_css_queue_dequeue(
				&fwctrl_comm_queues.sp2host_isys_q_handle,
				payload)){
		ret = ENOTCONN;
	}

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "isyspoc_receive_msg() : leaving \n");

	return ret;
}

int ia_css_fwctrl_dequeue_event(
	enum ia_css_fwctrl_event_type *event_type
)
{
	int ret = 0;
	uint32_t signal;

	ia_css_debug_dtrace(IA_CSS_DEBUG_INFO, "ia_css_fwctrl_dequeue_event() : entered \n");

	if (IA_CSS_SUCCESS == ia_css_queue_dequeue(
					&fwctrl_comm_queues.sp2host_generic_q_handle,
					&signal)) {
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "received generic event %d, \n", *event_type);

		if (SP_SW_EVENT_ISYS == signal) {
			*event_type = IA_CSS_FWCTRL_ISYS_EVENT;
		}
		else if (SP_SW_EVENT_PSYS == signal) {
			*event_type = IA_CSS_FWCTRL_PSYS_EVENT;
		}
		else
		{
			ret = EBADE;
		}
	}
	else
	{
		ia_css_debug_dtrace(IA_CSS_DEBUG_INFO, "Failed to receive event \n");
		ret = ENOTCONN;
	}

	ia_css_debug_dtrace(IA_CSS_DEBUG_INFO, "ia_css_fwctrl_dequeue_event() : leaving\n");
	return ret;
}

int ia_css_fwctrl_psys_send_msg(hrt_vaddress psys_payload)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_fwctrl_psys_send_msg() : entered  payload = 0x%x \n", psys_payload);
	/*enqueue payload into psys command*/
	if(IA_CSS_SUCCESS == ia_css_queue_enqueue(&fwctrl_comm_queues.host2sp_psys_q_handle, psys_payload))
	{
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "psyspoc sending message from host side Success; payload = 0x%x\n", psys_payload);
		/*Send psys signal to SP, by posting falg into generic queue*/
		ia_css_queue_enqueue(&fwctrl_comm_queues.host2sp_generic_q_handle, SP_SW_EVENT_PSYS);
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_fwctrl_psys_send_msg() : Leaving\n");
	return 0;
}

int ia_css_fwctrl_psys_receive_msg(
	hrt_vaddress *payload)
{
	int ret = 0;
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_fwctrl_psys_receive_msg() : Entered \n");

	if (IA_CSS_SUCCESS != ia_css_queue_dequeue(
				&fwctrl_comm_queues.sp2host_psys_q_handle,
				payload)){
		ret = ENOTCONN;
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "psyspoc_receive_msg address()=0x%x\n",payload);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_fwctrl_psys_receive_msg() : Leaving \n");
	return ret;
}
