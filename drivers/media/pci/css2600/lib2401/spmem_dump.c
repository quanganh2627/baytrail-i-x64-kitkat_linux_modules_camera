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

/* function longjmp: 3F26 */

/* function ia_css_dmaproxy_sp_set_addr_B: 1754 */

/* function debug_buffer_set_ddr_addr: EE */

/* function ia_css_queue_get_size: 30BA */

/* function ia_css_queue_load: 377A */

/* function setjmp: 3F2F */

/* function __dmaproxy_sp_read_write_text: 186D */

/* function ia_css_dmaproxy_sp_wait_for_ack: 4332 */

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

/* function pocapp_register_isr: 679 */

/* function ia_css_queue_item_store: 3450 */

/* function input_system_reset: 1464 */

/* function sp_start_isp: 412 */

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

/* function ia_css_thread_sp_main: 3D11 */

/* function ia_css_ispctrl_sp_init_internal_buffers: 1AE0 */

/* function pixelgen_unit_test: 1125 */

/* function ibuf_ctrl_sync: EF6 */

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

/* function ia_css_queue_store: 35F3 */

/* function ia_css_ispctrl_sp_end_binary: 18E9 */

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

/* function pocapp_post_signalling_event: 68E */

/* function pixelgen_tpg_run: 11C8 */

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

/* function ia_css_queue_get_free_space: 3212 */

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

/* function ia_css_isys_stream_dequeue_message: 9D6 */

/* function ia_css_psyspoc_execute_stage: B38 */

/* function is_isp_debug_buffer_full: 3AB */

/* function ia_css_dmaproxy_sp_configure_channel_from_info: 16D1 */

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

/* function ia_css_isys_stream_set_state: A46 */

/* function pocapp_generate_sw_interrupt: 6A5 */

/* function memcpy: 3FCF */

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

/* function sp_dma_proxy_set_width_ab: 156E */

/* function ia_css_uds_sp_scale_params: 2EAC */

/* function __divu: 3F4D */

/* function ia_css_thread_sp_get_state: 3C40 */

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

/* function thread_fiber_sp_main: 3DEF */

/* function ia_css_spctrl_sp_set_state: 3908 */

/* function ia_css_thread_sem_sp_signal: 454A */

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

/* function ia_css_virtual_isys_sp_isr_init: 3998 */

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

/* function ia_css_thread_sem_sp_init: 461D */

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

/* function ia_css_dmaproxy_sp_execute: 1629 */

/* function csi_rx_backend_rst: E4B */

/* function ia_css_queue_is_empty: 30F5 */

/* function ia_css_circbuf_extract: 3E17 */

/* function ia_css_isys_stream_get_state: A63 */

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

/* function ia_css_spctrl_sp_get_spid: 390F */

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

/* function ia_css_dmaproxy_sp_read_byte_addr: 4363 */

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

/* function ia_css_circbuf_peek: 3DF6 */

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

/* function ia_css_queue_get_used_space: 31C4 */

/* function ia_css_psyspoc_prepare_io: A8E */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 2562 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4B1C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4B1C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function ia_css_queue_is_full: 3261 */

/* function debug_buffer_init_isp: FB */

/* function pocapp_sp_event_proxy_init: 601 */

/* function ibuf_ctrl_run: F46 */

/* function ia_css_isys_stream_container_reset: A6D */

/* function ia_css_thread_sp_yield: 44C0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x4C3C
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x4C3C
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

/* function ia_css_thread_sp_fork: 3CCD */

/* function pocapp_sp_event_proxy_func: 5B5 */

/* function ia_css_dmaproxy_sp_vmem_read: 15B2 */

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

/* function ia_css_thread_sp_init: 3CF9 */

/* function ia_css_ispctrl_sp_set_stream_base_addr: 2C61 */

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

/* function ibuf_ctrl_transfer: F08 */

/* function ia_css_dmaproxy_sp_read: 164A */

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

/* function ia_css_queue_peek: 3139 */

/* function ia_css_isys_stream_block_handler: 93D */

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

/* function is_ddr_debug_buffer_full: 330 */

/* function ia_css_isyspoc_isys_thread_func: 70A */

/* function sp_dma_proxy_isp_write_addr: 15CA */

/* function ia_css_psyspoc_psys_thread_func: A7C */

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

/* function ia_css_isys_stream_ack_send_event: 9A0 */

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

/* function dmaproxy_sp_read_write: 43FB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4C40
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4C40
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 407B */

/* function ia_css_dmaproxy_sp_process: 40AA */

/* function ia_css_ispctrl_sp_init_cs: 19E9 */

/* function ia_css_spctrl_sp_init: 391D */

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

/* function pixelgen_prbs_config: 113E */

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

/* function psyspoc_send_psys_event: AED */

/* function sp_dma_proxy_reset_channels: 18A3 */

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

/* function thread_fiber_sp_create: 3D5E */

/* function ia_css_dmaproxy_sp_set_increments: 173F */

/* function pixelgen_tpg_is_done: 11B7 */

/* function ia_css_isys_stream_capture_indication: 3A6E */

/* function sp_start_isp_entry: 408 */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x408
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x408

/* function ia_css_dmaproxy_sp_channel_acquire: 18D2 */

/* function ibuf_ctrl_config: F66 */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 1565 */

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

/* function ia_css_thread_sp_kill: 3C93 */

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

/* function ia_css_dmaproxy_sp_channel_release: 18BB */

/* function pixelgen_prbs_run: 112C */

/* function ia_css_dmaproxy_sp_is_idle: 188E */

/* function isp_hmem_load: CE5 */

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

/* function ia_css_thread_sp_set_priority: 3C8B */

/* function sizeof_hmem: D90 */

/* function input_system_channel_open: 1427 */

/* function pixelgen_tpg_stop: 11A6 */

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

/* function __ia_css_dmaproxy_sp_process_text: 14C2 */

/* function ia_css_dmaproxy_sp_set_width_exception: 1729 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_param_handle
#define HIVE_MEM_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_param_handle 0x4B4C
#define HIVE_SIZE_param_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_param_handle 0x4B4C
#define HIVE_SIZE_sp_param_handle 12

/* function __modu: 3F93 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 1584 */

/* function input_system_channel_transfer: 1410 */

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

/* function ia_css_queue_local_init: 342A */

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

/* function ia_css_dmaproxy_sp_deregister_channel_from_port: 154C */

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

/* function ia_css_ispctrl_sp_isp_done_row_striping: 24B1 */

/* function __ia_css_virtual_isys_sp_isr_text: 395C */

/* function ia_css_queue_dequeue: 32A9 */

/* function ia_css_dmaproxy_sp_configure_channel: 437A */

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

/* function ia_css_circbuf_pop: 3EAF */

/* function memset: 4012 */

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

/* function ia_css_ispctrl_sp_init_ds: 1B98 */

/* function get_xmem_base_addr_raw: 1EEF */

/* function pixelgen_tpg_config: 11DA */

/* function ia_css_circbuf_create: 3EF9 */

/* function csi_rx_frontend_run: D98 */

/* function ia_css_isys_stream_open: 3B4E */

/* function input_system_channel_configure: 143B */

/* function isp_hmem_clear: CAC */

/* function stream2mmio_config: 10D8 */

/* function ia_css_ispctrl_sp_start_binary: 19C7 */

/* function csi_rx_frontend_config: DDF */

/* function ia_css_rmgr_sp_rel_gen: 3B9F */

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

/* function ia_css_pipeline_sp_get_pipe_io_status: 6BB */

/* function sh_css_decode_tag_descr: 3C6 */

/* function debug_enqueue_isp: 2DB */

/* function ia_css_spctrl_sp_uninit: 3916 */

/* function csi_rx_backend_run: DCD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x4B58
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 112
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x4B58
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

/* function ia_css_dmaproxy_sp_write_byte_addr: 15F8 */

/* function ia_css_dmaproxy_sp_init: 151E */

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

/* function input_system_channel_sync: 13FC */

/* function pocapp_sp_event_proxy_callout_func: 404D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_ids 0x4BC8
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_ids 52
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_ids 0x4BC8
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_ids 52

/* function ia_css_queue_item_load: 353F */

/* function ia_css_spctrl_sp_get_state: 3901 */

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

/* function ia_css_isys_stream_update_block: 9B8 */

/* function thread_fiber_sp_init: 3DE5 */

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
#define HIVE_ADDR_sp_isp_input_stream_format 0x4BFC
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x4BFC
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 3F7F */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 1664 */

/* function ia_css_thread_sp_join: 3CBC */

/* function ia_css_dmaproxy_sp_add_command: 443D */

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

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 3A1D */

/* function ia_css_thread_sp_run: 3D28 */

/* function ia_css_sp_isp_param_init_isp_memories: 2D77 */

/* function pocapp_init_psys_event_queues: B0E */

/* function irq_raise: C9 */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 147D */

/* function csi_rx_backend_disable: DAA */

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

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 434C */

/* function ia_css_ispctrl_sp_done_ds: 1B7B */

/* function csi_rx_backend_config: DF0 */

/* function ia_css_sp_isp_param_get_mem_inits: 2D52 */

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
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x4C0C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x4C0C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_ispctrl_sp_init_isp_vars: 29F7 */

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

/* function ia_css_isys_stream_start: 3AC7 */

/* function ia_css_dmaproxy_sp_write: 160F */

/* function ia_css_isys_stream_start_async: 3AF1 */

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

/* function ia_css_rmgr_sp_acq_gen: 3BC3 */

/* function input_system_input_port_open: 1345 */

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

/* function ia_css_queue_uninit: 33E8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x4C44
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x4C44
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_dmaproxy_sp_set_height_exception: 1717 */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 169A */

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

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 15E1 */

/* function ia_css_queue_enqueue: 3333 */

/* function ia_css_dmaproxy_sp_vmem_write: 159B */

/* function csi_rx_backend_enable: DBB */

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

/* function input_system_input_port_configure: 1397 */

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
#define HIVE_SIZE_mem_map 296
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x49F4
#define HIVE_SIZE_sp_mem_map 296

/* function isys2401_dma_config_legacy: 10AE */

/* function ia_css_virtual_isys_sp_isr: 4459 */

/* function thread_sp_queue_print: 3D45 */

/* function ia_css_circbuf_destroy: 3EF0 */

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

/* function ia_css_sp_isp_param_mem_load: 2CDA */

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

/* function __div: 3F37 */

/* function ia_css_thread_sem_sp_wait: 4595 */

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

/* function ia_css_dmaproxy_sp_register_channel_to_port: 1559 */

/* function ia_css_queue_remote_init: 340A */

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
}
