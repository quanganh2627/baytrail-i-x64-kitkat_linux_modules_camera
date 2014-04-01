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

/* function longjmp: 3EF3 */

/* function ia_css_dmaproxy_sp_set_addr_B: 175B */

/* function debug_buffer_set_ddr_addr: EE */

/* function ia_css_queue_get_size: 30A0 */

/* function ia_css_queue_load: 3760 */

/* function setjmp: 3EFC */

/* function __dmaproxy_sp_read_write_text: 1874 */

/* function ia_css_dmaproxy_sp_wait_for_ack: 42FF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_CSI_RX_BE_SID_WIDTH
#define HIVE_MEM_N_CSI_RX_BE_SID_WIDTH scalar_processor_2400_dmem
#define HIVE_ADDR_N_CSI_RX_BE_SID_WIDTH 0x168
#define HIVE_SIZE_N_CSI_RX_BE_SID_WIDTH 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_CSI_RX_BE_SID_WIDTH scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_CSI_RX_BE_SID_WIDTH 0x168
#define HIVE_SIZE_sp_N_CSI_RX_BE_SID_WIDTH 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stage 0x4C48
#define HIVE_SIZE_isp_stage 832
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stage 0x4C48
#define HIVE_SIZE_sp_isp_stage 832

/* function pocapp_register_isr: 680 */

/* function ia_css_queue_item_store: 3436 */

/* function input_system_reset: 146B */

/* function sp_start_isp: 419 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_binary_group 0x5040
#define HIVE_SIZE_sp_binary_group 72
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x5040
#define HIVE_SIZE_sp_sp_binary_group 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x5308
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x5308
#define HIVE_SIZE_sp_sp_sw_state 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle
#define HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_host2sp_psys_cmd_queue_handle 0x49C8
#define HIVE_SIZE_psyspoc_host2sp_psys_cmd_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_host2sp_psys_cmd_queue_handle 0x49C8
#define HIVE_SIZE_sp_psyspoc_host2sp_psys_cmd_queue_handle 12

/* function ia_css_thread_sp_main: 3CDE */

/* function ia_css_ispctrl_sp_init_internal_buffers: 1AE7 */

/* function pixelgen_unit_test: 112C */

/* function ibuf_ctrl_sync: EFD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x2680
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x2680
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sem_for_sp2host_event_queue
#define HIVE_MEM_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sem_for_sp2host_event_queue 0x2668
#define HIVE_SIZE_pocapp_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sem_for_sp2host_event_queue 0x2668
#define HIVE_SIZE_sp_pocapp_sem_for_sp2host_event_queue 20

/* function ia_css_queue_store: 35D9 */

/* function ia_css_ispctrl_sp_end_binary: 18F0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack_size
#define HIVE_MEM_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack_size 0xE0
#define HIVE_SIZE_pocapp_sp_threads_stack_size 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack_size 0xE0
#define HIVE_SIZE_sp_pocapp_sp_threads_stack_size 12

/* function pocapp_post_signalling_event: 695 */

/* function pixelgen_tpg_run: 11CF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_is_pending_mask
#define HIVE_MEM_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_is_pending_mask 0x5C
#define HIVE_SIZE_event_is_pending_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_is_pending_mask 0x5C
#define HIVE_SIZE_sp_event_is_pending_mask 44

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_com 0x2684
#define HIVE_SIZE_host_sp_com 188
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_com 0x2684
#define HIVE_SIZE_sp_host_sp_com 188

/* function ia_css_queue_get_free_space: 31F8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x530C
#define HIVE_SIZE_sp_init_dmem_data 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x530C
#define HIVE_SIZE_sp_sp_init_dmem_data 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack
#define HIVE_MEM_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack 0xD4
#define HIVE_SIZE_pocapp_sp_threads_stack 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack 0xD4
#define HIVE_SIZE_sp_pocapp_sp_threads_stack 12

/* function ia_css_isys_stream_dequeue_message: 9DD */

/* function ia_css_psyspoc_execute_stage: B3F */

/* function is_isp_debug_buffer_full: 3B2 */

/* function ia_css_dmaproxy_sp_configure_channel_from_info: 16D8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_IBUF_CTRL_PROCS
#define HIVE_MEM_N_IBUF_CTRL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_IBUF_CTRL_PROCS 0x19C
#define HIVE_SIZE_N_IBUF_CTRL_PROCS 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_IBUF_CTRL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_IBUF_CTRL_PROCS 0x19C
#define HIVE_SIZE_sp_N_IBUF_CTRL_PROCS 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_per_frame_data 0x2740
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x2740
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_isys_stream_set_state: A4D */

/* function pocapp_generate_sw_interrupt: 6AC */

/* function memcpy: 3F9C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_ISYS2401_DMA_CHANNEL_PROCS
#define HIVE_MEM_N_ISYS2401_DMA_CHANNEL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_ISYS2401_DMA_CHANNEL_PROCS 0x1C0
#define HIVE_SIZE_N_ISYS2401_DMA_CHANNEL_PROCS 4
#else
#endif
#endif
#define HIVE_MEM_sp_N_ISYS2401_DMA_CHANNEL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_ISYS2401_DMA_CHANNEL_PROCS 0x1C0
#define HIVE_SIZE_sp_N_ISYS2401_DMA_CHANNEL_PROCS 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0x304
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0x304
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x2E4
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x2E4
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 1575 */

/* function ia_css_uds_sp_scale_params: 2E92 */

/* function __divu: 3F1A */

/* function ia_css_thread_sp_get_state: 3C0D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_SHORT_PACKET_LUT_ENTRIES
#define HIVE_MEM_N_SHORT_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_N_SHORT_PACKET_LUT_ENTRIES 0x144
#define HIVE_SIZE_N_SHORT_PACKET_LUT_ENTRIES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_SHORT_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_SHORT_PACKET_LUT_ENTRIES 0x144
#define HIVE_SIZE_sp_N_SHORT_PACKET_LUT_ENTRIES 12

/* function thread_fiber_sp_main: 3DBC */

/* function ia_css_spctrl_sp_set_state: 38EE */

/* function ia_css_thread_sem_sp_signal: 4517 */

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

/* function ia_css_virtual_isys_sp_isr_init: 397E */

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

/* function ia_css_thread_sem_sp_init: 45EA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_is_isp_requested 0x2380
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_sp_is_isp_requested 0x2380
#define HIVE_SIZE_sp_is_isp_requested 4

/* function ia_css_dmaproxy_sp_execute: 1630 */

/* function csi_rx_backend_rst: E52 */

/* function ia_css_queue_is_empty: 30DB */

/* function ia_css_circbuf_extract: 3DE4 */

/* function ia_css_isys_stream_get_state: A6A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_fiber
#define HIVE_MEM_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_fiber 0xEC
#define HIVE_SIZE_pocapp_sp_threads_fiber 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_fiber 0xEC
#define HIVE_SIZE_sp_pocapp_sp_threads_fiber 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0x2E0
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x2E0
#define HIVE_SIZE_sp_current_sp_thread 4

/* function ia_css_spctrl_sp_get_spid: 38F5 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle
#define HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sp2host_psys_event_queue_handle 0x49D4
#define HIVE_SIZE_psyspoc_sp2host_psys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sp2host_psys_event_queue_handle 0x49D4
#define HIVE_SIZE_sp_psyspoc_sp2host_psys_event_queue_handle 12

/* function ia_css_dmaproxy_sp_read_byte_addr: 4330 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_STREAM2MMIO_SID_PROCS
#define HIVE_MEM_N_STREAM2MMIO_SID_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_STREAM2MMIO_SID_PROCS 0x1C4
#define HIVE_SIZE_N_STREAM2MMIO_SID_PROCS 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_STREAM2MMIO_SID_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_STREAM2MMIO_SID_PROCS 0x1C4
#define HIVE_SIZE_sp_N_STREAM2MMIO_SID_PROCS 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isp_stop_req
#define HIVE_MEM_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isp_stop_req 0x2384
#define HIVE_SIZE_pocapp_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isp_stop_req 0x2384
#define HIVE_SIZE_sp_pocapp_isp_stop_req 4

/* function ia_css_circbuf_peek: 3DC3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0xF8
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0xF8
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

/* function ia_css_queue_get_used_space: 31AA */

/* function ia_css_psyspoc_prepare_io: A95 */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 2569 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4B18
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4B18
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function ia_css_queue_is_full: 3247 */

/* function debug_buffer_init_isp: FB */

/* function pocapp_sp_event_proxy_init: 608 */

/* function ibuf_ctrl_run: F4D */

/* function ia_css_isys_stream_container_reset: A74 */

/* function ia_css_thread_sp_yield: 448D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x4C38
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x4C38
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_psys_thread
#define HIVE_MEM_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_psys_thread 0x25A8
#define HIVE_SIZE_pocapp_psys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_psys_thread 0x25A8
#define HIVE_SIZE_sp_pocapp_psys_thread 64

/* function ia_css_thread_sp_fork: 3C9A */

/* function pocapp_sp_event_proxy_func: 5BC */

/* function ia_css_dmaproxy_sp_vmem_read: 15B9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_LONG_PACKET_LUT_ENTRIES
#define HIVE_MEM_N_LONG_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_N_LONG_PACKET_LUT_ENTRIES 0x150
#define HIVE_SIZE_N_LONG_PACKET_LUT_ENTRIES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_LONG_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_LONG_PACKET_LUT_ENTRIES 0x150
#define HIVE_SIZE_sp_N_LONG_PACKET_LUT_ENTRIES 12

/* function ia_css_thread_sp_init: 3CC6 */

/* function ia_css_ispctrl_sp_set_stream_base_addr: 2C47 */

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

/* function ibuf_ctrl_transfer: F0F */

/* function ia_css_dmaproxy_sp_read: 1651 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_raw_copy_line_count 0xFC
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0xFC
#define HIVE_SIZE_sp_raw_copy_line_count 4

/* function ia_css_queue_peek: 311F */

/* function ia_css_isys_stream_block_handler: 944 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_can_send_token_mask
#define HIVE_MEM_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_can_send_token_mask 0x88
#define HIVE_SIZE_event_can_send_token_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_can_send_token_mask 0x88
#define HIVE_SIZE_sp_event_can_send_token_mask 44

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_isp_thread 0x4F88
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_thread 0x4F88
#define HIVE_SIZE_sp_isp_thread 4

/* function is_ddr_debug_buffer_full: 334 */

/* function ia_css_isyspoc_isys_thread_func: 711 */

/* function sp_dma_proxy_isp_write_addr: 15D1 */

/* function ia_css_psyspoc_psys_thread_func: A83 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_stream_container
#define HIVE_MEM_ia_css_isys_stream_container scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_isys_stream_container 0x39F4
#define HIVE_SIZE_ia_css_isys_stream_container 4032
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_stream_container scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_stream_container 0x39F4
#define HIVE_SIZE_sp_ia_css_isys_stream_container 4032

/* function debug_enqueue_ddr: 10A */

/* function ia_css_isys_stream_ack_send_event: 9A7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sem_for_isys_sp2host_event_queue
#define HIVE_MEM_isyspoc_sem_for_isys_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sem_for_isys_sp2host_event_queue 0x3978
#define HIVE_SIZE_isyspoc_sem_for_isys_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sem_for_isys_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sem_for_isys_sp2host_event_queue 0x3978
#define HIVE_SIZE_sp_isyspoc_sem_for_isys_sp2host_event_queue 20

/* function dmaproxy_sp_read_write: 43C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4C3C
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4C3C
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 4048 */

/* function ia_css_dmaproxy_sp_process: 4077 */

/* function ia_css_ispctrl_sp_init_cs: 19F0 */

/* function ia_css_spctrl_sp_init: 3903 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue
#define HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sem_for_psys_host2sp_cmd_queue 0x49E0
#define HIVE_SIZE_psyspoc_sem_for_psys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 0x49E0
#define HIVE_SIZE_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_output 0x2744
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_output 0x2744
#define HIVE_SIZE_sp_sp_output 16

/* function pixelgen_prbs_config: 1145 */

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
#ifndef HIVE_MEM_ia_css_isys_stream_state_lock
#define HIVE_MEM_ia_css_isys_stream_state_lock scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_isys_stream_state_lock 0x49B4
#define HIVE_SIZE_ia_css_isys_stream_state_lock 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_stream_state_lock scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_stream_state_lock 0x49B4
#define HIVE_SIZE_sp_ia_css_isys_stream_state_lock 20

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

/* function psyspoc_send_psys_event: AF4 */

/* function sp_dma_proxy_reset_channels: 18AA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x23C4
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 484
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x23C4
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 484

/* function thread_fiber_sp_create: 3D2B */

/* function ia_css_dmaproxy_sp_set_increments: 1746 */

/* function pixelgen_tpg_is_done: 11BE */

/* function ia_css_isys_stream_capture_indication: 3A54 */

/* function sp_start_isp_entry: 40F */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x40F
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x40F

/* function ia_css_dmaproxy_sp_channel_acquire: 18D9 */

/* function ibuf_ctrl_config: F6D */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 156C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isys_thread
#define HIVE_MEM_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isys_thread 0x25E8
#define HIVE_SIZE_pocapp_isys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isys_thread 0x25E8
#define HIVE_SIZE_sp_pocapp_isys_thread 64

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x2758
#define HIVE_SIZE_sp_group 4616
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x2758
#define HIVE_SIZE_sp_sp_group 4616

/* function ia_css_thread_sp_kill: 3C60 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_output
#define HIVE_MEM_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_output 0x2388
#define HIVE_SIZE_pocapp_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_output 0x2388
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

/* function ia_css_dmaproxy_sp_channel_release: 18C2 */

/* function pixelgen_prbs_run: 1133 */

/* function ia_css_dmaproxy_sp_is_idle: 1895 */

/* function isp_hmem_load: CEC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_sp_error_cnt
#define HIVE_MEM_ia_css_isys_sp_error_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_isys_sp_error_cnt 0x3960
#define HIVE_SIZE_ia_css_isys_sp_error_cnt 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_sp_error_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_sp_error_cnt 0x3960
#define HIVE_SIZE_sp_ia_css_isys_sp_error_cnt 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_debug_buffer_ddr_address
#define HIVE_MEM_debug_buffer_ddr_address scalar_processor_2400_dmem
#define HIVE_ADDR_debug_buffer_ddr_address 0xBC
#define HIVE_SIZE_debug_buffer_ddr_address 4
#else
#endif
#endif
#define HIVE_MEM_sp_debug_buffer_ddr_address scalar_processor_2400_dmem
#define HIVE_ADDR_sp_debug_buffer_ddr_address 0xBC
#define HIVE_SIZE_sp_debug_buffer_ddr_address 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_host2sp_event_queue_handle
#define HIVE_MEM_pocapp_host2sp_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_host2sp_event_queue_handle 0x2398
#define HIVE_SIZE_pocapp_host2sp_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_host2sp_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_host2sp_event_queue_handle 0x2398
#define HIVE_SIZE_sp_pocapp_host2sp_event_queue_handle 12

/* function ia_css_thread_sp_set_priority: 3C58 */

/* function sizeof_hmem: D97 */

/* function input_system_channel_open: 142E */

/* function pixelgen_tpg_stop: 11AD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads
#define HIVE_MEM_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads 0xCC
#define HIVE_SIZE_pocapp_sp_threads 8
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads 0xCC
#define HIVE_SIZE_sp_pocapp_sp_threads 8

/* function __ia_css_dmaproxy_sp_process_text: 14C9 */

/* function ia_css_dmaproxy_sp_set_width_exception: 1730 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_param_handle
#define HIVE_MEM_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_param_handle 0x4B48
#define HIVE_SIZE_param_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_param_handle 0x4B48
#define HIVE_SIZE_sp_param_handle 12

/* function __modu: 3F60 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 158B */

/* function input_system_channel_transfer: 1417 */

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

/* function ia_css_queue_local_init: 3410 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp2host_event_queue_handle
#define HIVE_MEM_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp2host_event_queue_handle 0x23A4
#define HIVE_SIZE_pocapp_sp2host_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp2host_event_queue_handle 0x23A4
#define HIVE_SIZE_sp_pocapp_sp2host_event_queue_handle 12

/* function ia_css_dmaproxy_sp_deregister_channel_from_port: 1553 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x5328
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x5328
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

/* function ia_css_ispctrl_sp_isp_done_row_striping: 24B8 */

/* function __ia_css_virtual_isys_sp_isr_text: 3942 */

/* function ia_css_queue_dequeue: 328F */

/* function ia_css_dmaproxy_sp_configure_channel: 4347 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue
#define HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sem_for_isys_host2sp_cmd_queue 0x398C
#define HIVE_SIZE_isyspoc_sem_for_isys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 0x398C
#define HIVE_SIZE_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x5330
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x5330
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function ia_css_circbuf_pop: 3E7C */

/* function memset: 3FDF */

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

/* function ia_css_ispctrl_sp_init_ds: 1B9F */

/* function get_xmem_base_addr_raw: 1EF6 */

/* function pixelgen_tpg_config: 11E1 */

/* function ia_css_circbuf_create: 3EC6 */

/* function csi_rx_frontend_run: D9F */

/* function ia_css_isys_stream_open: 3B1B */

/* function input_system_channel_configure: 1442 */

/* function isp_hmem_clear: CB3 */

/* function stream2mmio_config: 10DF */

/* function ia_css_ispctrl_sp_start_binary: 19CE */

/* function csi_rx_frontend_config: DE6 */

/* function ia_css_rmgr_sp_rel_gen: 3B6C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0x308
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0x308
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ia_css_pipeline_sp_get_pipe_io_status: 6C2 */

/* function sh_css_decode_tag_descr: 3CD */

/* function debug_enqueue_isp: 2DF */

/* function ia_css_spctrl_sp_uninit: 38FC */

/* function csi_rx_backend_run: DD4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x4B54
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 112
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x4B54
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 112

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x23B0
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x23B0
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 15FF */

/* function ia_css_dmaproxy_sp_init: 1525 */

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

/* function input_system_channel_sync: 1403 */

/* function pocapp_sp_event_proxy_callout_func: 401A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_ids 0x4BC4
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_ids 52
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_ids 0x4BC4
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_ids 52

/* function ia_css_queue_item_load: 3525 */

/* function ia_css_spctrl_sp_get_state: 38E7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x5324
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x5324
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function ia_css_isys_stream_update_block: 9BF */

/* function thread_fiber_sp_init: 3DB2 */

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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_input_stream_format
#define HIVE_MEM_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_input_stream_format 0x4BF8
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x4BF8
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 3F4C */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 166B */

/* function ia_css_thread_sp_join: 3C89 */

/* function ia_css_dmaproxy_sp_add_command: 440A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x214
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x214
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 3A03 */

/* function ia_css_thread_sp_run: 3CF5 */

/* function ia_css_sp_isp_param_init_isp_memories: 2D5D */

/* function pocapp_init_psys_event_queues: B15 */

/* function irq_raise: C9 */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 1484 */

/* function csi_rx_backend_disable: DB1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_CSI_RX_FE_CTRL_DLANES
#define HIVE_MEM_N_CSI_RX_FE_CTRL_DLANES scalar_processor_2400_dmem
#define HIVE_ADDR_N_CSI_RX_FE_CTRL_DLANES 0x15C
#define HIVE_SIZE_N_CSI_RX_FE_CTRL_DLANES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_CSI_RX_FE_CTRL_DLANES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_CSI_RX_FE_CTRL_DLANES 0x15C
#define HIVE_SIZE_sp_N_CSI_RX_FE_CTRL_DLANES 12

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 4319 */

/* function ia_css_ispctrl_sp_done_ds: 1B82 */

/* function csi_rx_backend_config: DF7 */

/* function ia_css_sp_isp_param_get_mem_inits: 2D38 */

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
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_frames
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x4C08
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x4C08
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_ispctrl_sp_init_isp_vars: 29FE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_event_proxy_thread
#define HIVE_MEM_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_event_proxy_thread 0x2628
#define HIVE_SIZE_pocapp_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_event_proxy_thread 0x2628
#define HIVE_SIZE_sp_pocapp_sp_event_proxy_thread 64

/* function ia_css_isys_stream_start: 3A94 */

/* function ia_css_dmaproxy_sp_write: 1616 */

/* function ia_css_isys_stream_start_async: 3ABE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x237C
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x237C
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_addresses 0x4F8C
#define HIVE_SIZE_sp_isp_addresses 180
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x4F8C
#define HIVE_SIZE_sp_sp_isp_addresses 180

/* function ia_css_rmgr_sp_acq_gen: 3B90 */

/* function input_system_input_port_open: 134C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x3970
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x3970
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

/* function ia_css_queue_uninit: 33CE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x4C40
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x4C40
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_dmaproxy_sp_set_height_exception: 171E */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 16A1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle
#define HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_host2sp_isys_cmd_queue_handle 0x39A0
#define HIVE_SIZE_isyspoc_host2sp_isys_cmd_queue_handle 72
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_host2sp_isys_cmd_queue_handle 0x39A0
#define HIVE_SIZE_sp_isyspoc_host2sp_isys_cmd_queue_handle 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x532C
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x532C
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 15E8 */

/* function ia_css_queue_enqueue: 3319 */

/* function ia_css_dmaproxy_sp_vmem_write: 15A2 */

/* function csi_rx_backend_enable: DC2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_data 0x5088
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_data 0x5088
#define HIVE_SIZE_sp_sp_data 640

/* function input_system_input_port_configure: 139E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0x300
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0x300
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_mem_map 0x49F4
#define HIVE_SIZE_mem_map 292
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x49F4
#define HIVE_SIZE_sp_mem_map 292

/* function isys2401_dma_config_legacy: 10B5 */

/* function ia_css_virtual_isys_sp_isr: 4426 */

/* function thread_sp_queue_print: 3D12 */

/* function ia_css_circbuf_destroy: 3EBD */

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

/* function ia_css_sp_isp_param_mem_load: 2CC0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sp2host_isys_event_queue_handle
#define HIVE_MEM_isyspoc_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sp2host_isys_event_queue_handle 0x39E8
#define HIVE_SIZE_isyspoc_sp2host_isys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sp2host_isys_event_queue_handle 0x39E8
#define HIVE_SIZE_sp_isyspoc_sp2host_isys_event_queue_handle 12

/* function __div: 3F04 */

/* function ia_css_thread_sem_sp_wait: 4562 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sleep_mode 0x3974
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x3974
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: E0 */

/* function ia_css_dmaproxy_sp_register_channel_to_port: 1560 */

/* function ia_css_queue_remote_init: 33F0 */

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
}
