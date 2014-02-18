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

#ifndef _sp_map_h_
#define _sp_map_h_


#ifndef _hrt_dummy_use_blob_sp
#define _hrt_dummy_use_blob_sp()
#endif

#define _hrt_cell_load_program_sp(proc) _hrt_cell_load_program_embedded(proc, sp)

/* function longjmp: 232B */

/* function ia_css_dmaproxy_sp_set_addr_B: 1409 */

/* function debug_buffer_set_ddr_addr: EE */

/* function ia_css_queue_get_size: 1588 */

/* function ia_css_queue_load: 1C48 */

/* function setjmp: 2334 */

/* function __dmaproxy_sp_read_write_text: 150C */

/* function ia_css_dmaproxy_sp_wait_for_ack: 2725 */

/* function pocapp_register_isr: 618 */

/* function ia_css_queue_item_store: 191E */

/* function input_system_reset: 113B */

/* function sp_start_isp: 412 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x2BE0
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x2BE0
#define HIVE_SIZE_sp_sp_sw_state 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle
#define HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_host2sp_psys_cmd_queue_handle 0x2BAC
#define HIVE_SIZE_psyspoc_host2sp_psys_cmd_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_host2sp_psys_cmd_queue_handle 0x2BAC
#define HIVE_SIZE_sp_psyspoc_host2sp_psys_cmd_queue_handle 12

/* function ia_css_thread_sp_main: 2116 */

/* function pixelgen_unit_test: E0C */

/* function ibuf_ctrl_sync: C17 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sem_for_sp2host_event_queue
#define HIVE_MEM_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sem_for_sp2host_event_queue 0x2040
#define HIVE_SIZE_pocapp_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sem_for_sp2host_event_queue 0x2040
#define HIVE_SIZE_sp_pocapp_sem_for_sp2host_event_queue 20

/* function ia_css_queue_store: 1AC1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack_size
#define HIVE_MEM_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack_size 0x424
#define HIVE_SIZE_pocapp_sp_threads_stack_size 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack_size 0x424
#define HIVE_SIZE_sp_pocapp_sp_threads_stack_size 12

/* function pocapp_post_signalling_event: 62D */

/* function pixelgen_tpg_run: EAF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_is_pending_mask
#define HIVE_MEM_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_is_pending_mask 0x18C
#define HIVE_SIZE_event_is_pending_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_is_pending_mask 0x18C
#define HIVE_SIZE_sp_event_is_pending_mask 44

/* function ia_css_queue_get_free_space: 16E0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x2BE4
#define HIVE_SIZE_sp_init_dmem_data 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x2BE4
#define HIVE_SIZE_sp_sp_init_dmem_data 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack
#define HIVE_MEM_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack 0x418
#define HIVE_SIZE_pocapp_sp_threads_stack 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack 0x418
#define HIVE_SIZE_sp_pocapp_sp_threads_stack 12

/* function is_isp_debug_buffer_full: 3AB */

/* function ia_css_dmaproxy_sp_configure_channel_from_info: 1386 */

/* function pocapp_generate_sw_interrupt: 654 */

/* function memcpy: 23BE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0x8F4
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0x8F4
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x8E0
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x8E0
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 1223 */

/* function __divu: 233C */

/* function ia_css_thread_sp_get_state: 2045 */

/* function thread_fiber_sp_main: 21F4 */

/* function ia_css_spctrl_sp_set_state: 1DD6 */

/* function ia_css_thread_sem_sp_signal: 293A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_IRQ_BASE
#define HIVE_MEM_IRQ_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_IRQ_BASE 0x2C
#define HIVE_SIZE_IRQ_BASE 16
#else
#endif
#endif
#define HIVE_MEM_sp_IRQ_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_IRQ_BASE 0x2C
#define HIVE_SIZE_sp_IRQ_BASE 16

/* function ia_css_virtual_isys_sp_isr_init: 1E66 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_TIMED_CTRL_BASE
#define HIVE_MEM_TIMED_CTRL_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_TIMED_CTRL_BASE 0x40
#define HIVE_SIZE_TIMED_CTRL_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_TIMED_CTRL_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_TIMED_CTRL_BASE 0x40
#define HIVE_SIZE_sp_TIMED_CTRL_BASE 4

/* function ia_css_thread_sem_sp_init: 2A0D */

/* function ia_css_dmaproxy_sp_execute: 12DE */

/* function csi_rx_backend_rst: B29 */

/* function ia_css_queue_is_empty: 15C3 */

/* function ia_css_circbuf_extract: 221C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_fiber
#define HIVE_MEM_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_fiber 0x430
#define HIVE_SIZE_pocapp_sp_threads_fiber 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_fiber 0x430
#define HIVE_SIZE_sp_pocapp_sp_threads_fiber 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0x8DC
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x8DC
#define HIVE_SIZE_sp_current_sp_thread 4

/* function ia_css_spctrl_sp_get_spid: 1DDD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle
#define HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sp2host_psys_event_queue_handle 0x2BB8
#define HIVE_SIZE_psyspoc_sp2host_psys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sp2host_psys_event_queue_handle 0x2BB8
#define HIVE_SIZE_sp_psyspoc_sp2host_psys_event_queue_handle 12

/* function ia_css_dmaproxy_sp_read_byte_addr: 2756 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isp_stop_req
#define HIVE_MEM_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isp_stop_req 0x1E4C
#define HIVE_SIZE_pocapp_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isp_stop_req 0x1E4C
#define HIVE_SIZE_sp_pocapp_isp_stop_req 4

/* function ia_css_circbuf_peek: 21FB */

/* function ia_css_queue_get_used_space: 1692 */

/* function ia_css_queue_is_full: 172F */

/* function debug_buffer_init_isp: FB */

/* function pocapp_sp_event_proxy_init: 5A1 */

/* function ibuf_ctrl_run: C59 */

/* function ia_css_thread_sp_yield: 28B0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x2BD8
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x2BD8
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_psys_thread
#define HIVE_MEM_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_psys_thread 0x1F80
#define HIVE_SIZE_pocapp_psys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_psys_thread 0x1F80
#define HIVE_SIZE_sp_pocapp_psys_thread 64

/* function ia_css_thread_sp_fork: 20D2 */

/* function pocapp_sp_event_proxy_func: 57F */

/* function ia_css_dmaproxy_sp_vmem_read: 1267 */

/* function csi_rx_unit_test: A76 */

/* function ia_css_thread_sp_init: 20FE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_DMEM_BASE
#define HIVE_MEM_ISP_DMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_DMEM_BASE 0x10
#define HIVE_SIZE_ISP_DMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_DMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_DMEM_BASE 0x10
#define HIVE_SIZE_sp_ISP_DMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_SP_DMEM_BASE
#define HIVE_MEM_SP_DMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_SP_DMEM_BASE 0x4
#define HIVE_SIZE_SP_DMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_SP_DMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_SP_DMEM_BASE 0x4
#define HIVE_SIZE_sp_SP_DMEM_BASE 4

/* function ibuf_ctrl_transfer: C29 */

/* function ia_css_dmaproxy_sp_read: 12FF */

/* function ia_css_queue_peek: 1607 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_can_send_token_mask
#define HIVE_MEM_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_can_send_token_mask 0x1B8
#define HIVE_SIZE_event_can_send_token_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_can_send_token_mask 0x1B8
#define HIVE_SIZE_sp_event_can_send_token_mask 44

/* function is_ddr_debug_buffer_full: 330 */

/* function ia_css_isyspoc_isys_thread_func: 671 */

/* function sp_dma_proxy_isp_write_addr: 127F */

/* function ia_css_psyspoc_psys_thread_func: 869 */

/* function debug_enqueue_ddr: 10A */

/* function dmaproxy_sp_read_write: 27EB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x2BDC
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x2BDC
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 246A */

/* function ia_css_dmaproxy_sp_process: 2499 */

/* function ia_css_spctrl_sp_init: 1DEB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue
#define HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sem_for_psys_host2sp_cmd_queue 0x2BC4
#define HIVE_SIZE_psyspoc_sem_for_psys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 0x2BC4
#define HIVE_SIZE_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 20

/* function pixelgen_prbs_config: E25 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_CTRL_BASE
#define HIVE_MEM_ISP_CTRL_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_CTRL_BASE 0x8
#define HIVE_SIZE_ISP_CTRL_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_CTRL_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_CTRL_BASE 0x8
#define HIVE_SIZE_sp_ISP_CTRL_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_INPUT_FORMATTER_BASE
#define HIVE_MEM_INPUT_FORMATTER_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_INPUT_FORMATTER_BASE 0x4C
#define HIVE_SIZE_INPUT_FORMATTER_BASE 16
#else
#endif
#endif
#define HIVE_MEM_sp_INPUT_FORMATTER_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_INPUT_FORMATTER_BASE 0x4C
#define HIVE_SIZE_sp_INPUT_FORMATTER_BASE 16

/* function sp_dma_proxy_reset_channels: 1542 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x1E78
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 264
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x1E78
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 264

/* function thread_fiber_sp_create: 2163 */

/* function ia_css_dmaproxy_sp_set_increments: 13F5 */

/* function pixelgen_tpg_is_done: E9E */

/* function ia_css_isys_stream_capture_indication: 1F11 */

/* function sp_start_isp_entry: 408 */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x408
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x408

/* function ia_css_dmaproxy_sp_channel_acquire: 1571 */

/* function ibuf_ctrl_config: C79 */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 121A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isys_thread
#define HIVE_MEM_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isys_thread 0x1FC0
#define HIVE_SIZE_pocapp_isys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isys_thread 0x1FC0
#define HIVE_SIZE_sp_pocapp_isys_thread 64

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x2058
#define HIVE_SIZE_sp_group 2856
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x2058
#define HIVE_SIZE_sp_sp_group 2856

/* function ia_css_thread_sp_kill: 2098 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_output
#define HIVE_MEM_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_output 0x1E50
#define HIVE_SIZE_pocapp_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_output 0x1E50
#define HIVE_SIZE_sp_pocapp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_MMU_BASE
#define HIVE_MEM_MMU_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_MMU_BASE 0x24
#define HIVE_SIZE_MMU_BASE 8
#else
#endif
#endif
#define HIVE_MEM_sp_MMU_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_MMU_BASE 0x24
#define HIVE_SIZE_sp_MMU_BASE 8

/* function ia_css_dmaproxy_sp_channel_release: 155A */

/* function pixelgen_prbs_run: E13 */

/* function ia_css_dmaproxy_sp_is_idle: 152D */

/* function isp_hmem_load: 9C3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_debug_buffer_ddr_address
#define HIVE_MEM_debug_buffer_ddr_address scalar_processor_2400_dmem
#define HIVE_ADDR_debug_buffer_ddr_address 0x284
#define HIVE_SIZE_debug_buffer_ddr_address 4
#else
#endif
#endif
#define HIVE_MEM_sp_debug_buffer_ddr_address scalar_processor_2400_dmem
#define HIVE_ADDR_sp_debug_buffer_ddr_address 0x284
#define HIVE_SIZE_sp_debug_buffer_ddr_address 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_host2sp_event_queue_handle
#define HIVE_MEM_pocapp_host2sp_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_host2sp_event_queue_handle 0x1E60
#define HIVE_SIZE_pocapp_host2sp_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_host2sp_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_host2sp_event_queue_handle 0x1E60
#define HIVE_SIZE_sp_pocapp_host2sp_event_queue_handle 12

/* function ia_css_thread_sp_set_priority: 2090 */

/* function sizeof_hmem: A6E */

/* function input_system_channel_open: 10FE */

/* function pixelgen_tpg_stop: E8D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads
#define HIVE_MEM_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads 0x410
#define HIVE_SIZE_pocapp_sp_threads 8
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads 0x410
#define HIVE_SIZE_sp_pocapp_sp_threads 8

/* function __ia_css_dmaproxy_sp_process_text: 1199 */

/* function ia_css_dmaproxy_sp_set_width_exception: 13DF */

/* function __modu: 2382 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 1239 */

/* function input_system_channel_transfer: 10E7 */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GDC_BASE
#define HIVE_MEM_GDC_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GDC_BASE 0x44
#define HIVE_SIZE_GDC_BASE 8
#else
#endif
#endif
#define HIVE_MEM_sp_GDC_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GDC_BASE 0x44
#define HIVE_SIZE_sp_GDC_BASE 8

/* function ia_css_queue_local_init: 18F8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp2host_event_queue_handle
#define HIVE_MEM_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp2host_event_queue_handle 0x1E6C
#define HIVE_SIZE_pocapp_sp2host_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp2host_event_queue_handle 0x1E6C
#define HIVE_SIZE_sp_pocapp_sp2host_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x2C00
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x2C00
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

/* function __ia_css_virtual_isys_sp_isr_text: 1E2A */

/* function ia_css_queue_dequeue: 1777 */

/* function ia_css_dmaproxy_sp_configure_channel: 276D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue
#define HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sem_for_isys_host2sp_cmd_queue 0x2B80
#define HIVE_SIZE_isyspoc_sem_for_isys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 0x2B80
#define HIVE_SIZE_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x2C08
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x2C08
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function ia_css_circbuf_pop: 22B4 */

/* function memset: 2401 */

/* function irq_raise_set_token: B7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GPIO_BASE
#define HIVE_MEM_GPIO_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GPIO_BASE 0x3C
#define HIVE_SIZE_GPIO_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GPIO_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GPIO_BASE 0x3C
#define HIVE_SIZE_sp_GPIO_BASE 4

/* function pixelgen_tpg_config: EC1 */

/* function ia_css_circbuf_create: 22FE */

/* function csi_rx_frontend_run: A99 */

/* function ia_css_isys_stream_open: 1F7D */

/* function input_system_channel_configure: 1112 */

/* function isp_hmem_clear: 98A */

/* function stream2mmio_config: DBF */

/* function csi_rx_frontend_config: ABD */

/* function ia_css_rmgr_sp_rel_gen: 1FA4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0x8F8
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0x8F8
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ibuf_ctrl_unit_test: BD4 */

/* function ia_css_pipeline_sp_get_pipe_io_status: 66A */

/* function sh_css_decode_tag_descr: 3C6 */

/* function debug_enqueue_isp: 2DB */

/* function ia_css_spctrl_sp_uninit: 1DE4 */

/* function csi_rx_backend_run: AAB */

/* function ia_css_dmaproxy_sp_write_byte_addr: 12AD */

/* function ia_css_dmaproxy_sp_init: 11F4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_VAMEM_BASE
#define HIVE_MEM_ISP_VAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_VAMEM_BASE 0x14
#define HIVE_SIZE_ISP_VAMEM_BASE 12
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_VAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_VAMEM_BASE 0x14
#define HIVE_SIZE_sp_ISP_VAMEM_BASE 12

/* function input_system_channel_sync: 10D3 */

/* function pocapp_sp_event_proxy_callout_func: 243C */

/* function ia_css_queue_item_load: 1A0D */

/* function ia_css_spctrl_sp_get_state: 1DCF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x2BFC
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x2BFC
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function thread_fiber_sp_init: 21EA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_SP_PMEM_BASE
#define HIVE_MEM_SP_PMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_SP_PMEM_BASE 0x0
#define HIVE_SIZE_SP_PMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_SP_PMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_SP_PMEM_BASE 0x0
#define HIVE_SIZE_sp_SP_PMEM_BASE 4

/* function __mod: 236E */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 1319 */

/* function ia_css_thread_sp_join: 20C1 */

/* function ia_css_dmaproxy_sp_add_command: 282D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x73C
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x73C
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 1EE4 */

/* function stream2mmio_unit_test: DAE */

/* function ia_css_thread_sp_run: 212D */

/* function pocapp_init_psys_event_queues: 960 */

/* function irq_raise: C9 */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 1154 */

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 273F */

/* function csi_rx_backend_config: ACE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_HMEM_BASE
#define HIVE_MEM_ISP_HMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_HMEM_BASE 0x20
#define HIVE_SIZE_ISP_HMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_HMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_HMEM_BASE 0x20
#define HIVE_SIZE_sp_ISP_HMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_event_proxy_thread
#define HIVE_MEM_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_event_proxy_thread 0x2000
#define HIVE_SIZE_pocapp_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_event_proxy_thread 0x2000
#define HIVE_SIZE_sp_pocapp_sp_event_proxy_thread 64

/* function ia_css_isys_stream_start: 1F2D */

/* function ia_css_dmaproxy_sp_write: 12C4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x1E48
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x1E48
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

/* function ia_css_rmgr_sp_acq_gen: 1FC8 */

/* function input_system_input_port_open: 102C */

/* function ia_css_queue_uninit: 18B6 */

/* function ia_css_dmaproxy_sp_set_height_exception: 13CD */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 134F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle
#define HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_host2sp_isys_cmd_queue_handle 0x2B94
#define HIVE_SIZE_isyspoc_host2sp_isys_cmd_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_host2sp_isys_cmd_queue_handle 0x2B94
#define HIVE_SIZE_sp_isyspoc_host2sp_isys_cmd_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x2C04
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x2C04
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 1296 */

/* function ia_css_queue_enqueue: 1801 */

/* function ia_css_dmaproxy_sp_vmem_write: 1250 */

/* function input_system_input_port_configure: 107E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0x8F0
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0x8F0
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

/* function isys2401_dma_config_legacy: D8C */

/* function ia_css_virtual_isys_sp_isr: 2849 */

/* function thread_sp_queue_print: 214A */

/* function ia_css_circbuf_destroy: 22F5 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_PMEM_BASE
#define HIVE_MEM_ISP_PMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_PMEM_BASE 0xC
#define HIVE_SIZE_ISP_PMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_PMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_PMEM_BASE 0xC
#define HIVE_SIZE_sp_ISP_PMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sp2host_isys_event_queue_handle
#define HIVE_MEM_isyspoc_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sp2host_isys_event_queue_handle 0x2BA0
#define HIVE_SIZE_isyspoc_sp2host_isys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sp2host_isys_event_queue_handle 0x2BA0
#define HIVE_SIZE_sp_isyspoc_sp2host_isys_event_queue_handle 12

/* function ia_css_thread_sem_sp_wait: 2985 */

/* function mmu_invalidate_cache: E0 */

/* function ia_css_queue_remote_init: 18D8 */

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
}
