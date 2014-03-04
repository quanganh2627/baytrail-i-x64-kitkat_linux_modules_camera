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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_input_line
#define HIVE_MEM_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_input_line 0x4DF0
#define HIVE_SIZE_isp_vectors_per_input_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_input_line 0x4DF0
#define HIVE_SIZE_sp_isp_vectors_per_input_line 4

/* function longjmp: 3FC7 */

/* function ia_css_dmaproxy_sp_set_addr_B: 1713 */

/* function debug_buffer_set_ddr_addr: EE */

/* function ia_css_queue_get_size: 3203 */

/* function ia_css_queue_load: 38C3 */

/* function setjmp: 3FD0 */

/* function __dmaproxy_sp_read_write_text: 1816 */

/* function ia_css_dmaproxy_sp_wait_for_ack: 43D7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stage 0x4F48
#define HIVE_SIZE_isp_stage 800
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stage 0x4F48
#define HIVE_SIZE_sp_isp_stage 800

/* function pocapp_register_isr: 679 */

/* function ia_css_queue_item_store: 3599 */

/* function input_system_reset: 1445 */

/* function sp_start_isp: 412 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_binary_group 0x5320
#define HIVE_SIZE_sp_binary_group 72
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x5320
#define HIVE_SIZE_sp_sp_binary_group 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x55E8
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x55E8
#define HIVE_SIZE_sp_sp_sw_state 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle
#define HIVE_MEM_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_host2sp_psys_cmd_queue_handle 0x4B90
#define HIVE_SIZE_psyspoc_host2sp_psys_cmd_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_host2sp_psys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_host2sp_psys_cmd_queue_handle 0x4B90
#define HIVE_SIZE_sp_psyspoc_host2sp_psys_cmd_queue_handle 12

/* function ia_css_thread_sp_main: 3DB2 */

/* function ia_css_ispctrl_sp_init_internal_buffers: 1A83 */

/* function pixelgen_unit_test: 1116 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x4DF4
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_vfout_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x4DF4
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 4

/* function ibuf_ctrl_sync: EE7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x2FF0
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x2FF0
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sem_for_sp2host_event_queue
#define HIVE_MEM_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sem_for_sp2host_event_queue 0x2FDC
#define HIVE_SIZE_pocapp_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sem_for_sp2host_event_queue 0x2FDC
#define HIVE_SIZE_sp_pocapp_sem_for_sp2host_event_queue 20

/* function ia_css_queue_store: 373C */

/* function ia_css_ispctrl_sp_end_binary: 1892 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack_size
#define HIVE_MEM_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack_size 0x470
#define HIVE_SIZE_pocapp_sp_threads_stack_size 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack_size 0x470
#define HIVE_SIZE_sp_pocapp_sp_threads_stack_size 12

/* function pocapp_post_signalling_event: 68E */

/* function pixelgen_tpg_run: 11B9 */

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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_com 0x2FF4
#define HIVE_SIZE_host_sp_com 180
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_com 0x2FF4
#define HIVE_SIZE_sp_host_sp_com 180

/* function ia_css_queue_get_free_space: 335B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x55EC
#define HIVE_SIZE_sp_init_dmem_data 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x55EC
#define HIVE_SIZE_sp_sp_init_dmem_data 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_stack
#define HIVE_MEM_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_stack 0x464
#define HIVE_SIZE_pocapp_sp_threads_stack 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_stack 0x464
#define HIVE_SIZE_sp_pocapp_sp_threads_stack 12

/* function ia_css_isys_stream_dequeue_message: 9E6 */

/* function is_isp_debug_buffer_full: 3AB */

/* function ia_css_dmaproxy_sp_configure_channel_from_info: 1690 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_per_frame_data 0x30A8
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x30A8
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_isys_stream_set_state: A56 */

/* function pocapp_generate_sw_interrupt: 6B5 */

/* function memcpy: 4070 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0xD24
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0xD24
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0xD0C
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0xD0C
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 152D */

/* function ia_css_uds_sp_scale_params: 3012 */

/* function __divu: 3FEE */

/* function ia_css_thread_sp_get_state: 3CE1 */

/* function thread_fiber_sp_main: 3E90 */

/* function ia_css_spctrl_sp_set_state: 3A51 */

/* function ia_css_thread_sem_sp_signal: 45EC */

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

/* function ia_css_virtual_isys_sp_isr_init: 3AE1 */

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

/* function ia_css_thread_sem_sp_init: 46BF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_is_isp_requested 0x2CF4
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_sp_is_isp_requested 0x2CF4
#define HIVE_SIZE_sp_is_isp_requested 4

/* function ia_css_dmaproxy_sp_execute: 15E8 */

/* function csi_rx_backend_rst: E3C */

/* function ia_css_queue_is_empty: 323E */

/* function ia_css_ispctrl_sp_swap_isp_buffers: 2DB4 */

/* function ia_css_circbuf_extract: 3EB8 */

/* function ia_css_isys_stream_get_state: A73 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads_fiber
#define HIVE_MEM_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads_fiber 0x47C
#define HIVE_SIZE_pocapp_sp_threads_fiber 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads_fiber 0x47C
#define HIVE_SIZE_sp_pocapp_sp_threads_fiber 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0xD08
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0xD08
#define HIVE_SIZE_sp_current_sp_thread 4

/* function ia_css_spctrl_sp_get_spid: 3A58 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle
#define HIVE_MEM_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sp2host_psys_event_queue_handle 0x4B9C
#define HIVE_SIZE_psyspoc_sp2host_psys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sp2host_psys_event_queue_handle 0x4B9C
#define HIVE_SIZE_sp_psyspoc_sp2host_psys_event_queue_handle 12

/* function ia_css_dmaproxy_sp_read_byte_addr: 4408 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isp_stop_req
#define HIVE_MEM_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isp_stop_req 0x2CF8
#define HIVE_SIZE_pocapp_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isp_stop_req 0x2CF8
#define HIVE_SIZE_sp_pocapp_isp_stop_req 4

/* function ia_css_circbuf_peek: 3E97 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0x524
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0x524
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_delay_in_idx
#define HIVE_MEM_ia_css_ispctrl_sp_delay_in_idx scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_delay_in_idx 0x4DF8
#define HIVE_SIZE_ia_css_ispctrl_sp_delay_in_idx 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_delay_in_idx scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_delay_in_idx 0x4DF8
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_delay_in_idx 96

/* function ia_css_queue_get_used_space: 330D */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 2642 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4BBC
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x4BBC
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function ia_css_queue_is_full: 33AA */

/* function debug_buffer_init_isp: FB */

/* function pocapp_sp_event_proxy_init: 601 */

/* function ia_css_sp_isp_param_hmem_load: 2E8F */

/* function ibuf_ctrl_run: F37 */

/* function ia_css_isys_stream_container_reset: A7D */

/* function ia_css_thread_sp_yield: 4562 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x4DE8
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x4DE8
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_psys_thread
#define HIVE_MEM_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_psys_thread 0x2F1C
#define HIVE_SIZE_pocapp_psys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_psys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_psys_thread 0x2F1C
#define HIVE_SIZE_sp_pocapp_psys_thread 64

/* function ia_css_thread_sp_fork: 3D6E */

/* function pocapp_sp_event_proxy_func: 5B5 */

/* function ia_css_dmaproxy_sp_vmem_read: 1571 */

/* function ia_css_thread_sp_init: 3D9A */

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

/* function ibuf_ctrl_transfer: EF9 */

/* function ia_css_dmaproxy_sp_read: 1609 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_raw_copy_line_count 0x528
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0x528
#define HIVE_SIZE_sp_raw_copy_line_count 4

/* function ia_css_queue_peek: 3282 */

/* function ia_css_isys_stream_block_handler: 94D */

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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_isp_thread 0x5268
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_thread 0x5268
#define HIVE_SIZE_sp_isp_thread 4

/* function is_ddr_debug_buffer_full: 330 */

/* function ia_css_isyspoc_isys_thread_func: 71A */

/* function sp_dma_proxy_isp_write_addr: 1589 */

/* function ia_css_psyspoc_psys_thread_func: A8C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_stream_container
#define HIVE_MEM_ia_css_isys_stream_container scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_isys_stream_container 0x3CDC
#define HIVE_SIZE_ia_css_isys_stream_container 3744
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_stream_container scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_stream_container 0x3CDC
#define HIVE_SIZE_sp_ia_css_isys_stream_container 3744

/* function debug_enqueue_ddr: 10A */

/* function ia_css_isys_stream_ack_send_event: 9B0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sem_for_isys_sp2host_event_queue
#define HIVE_MEM_isyspoc_sem_for_isys_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sem_for_isys_sp2host_event_queue 0x3C60
#define HIVE_SIZE_isyspoc_sem_for_isys_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sem_for_isys_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sem_for_isys_sp2host_event_queue 0x3C60
#define HIVE_SIZE_sp_isyspoc_sem_for_isys_sp2host_event_queue 20

/* function dmaproxy_sp_read_write: 449D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4DEC
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x4DEC
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 411C */

/* function ia_css_dmaproxy_sp_process: 414B */

/* function ia_css_ispctrl_sp_init_cs: 198C */

/* function ia_css_spctrl_sp_init: 3A66 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue
#define HIVE_MEM_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_psyspoc_sem_for_psys_host2sp_cmd_queue 0x4BA8
#define HIVE_SIZE_psyspoc_sem_for_psys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_psyspoc_sem_for_psys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 0x4BA8
#define HIVE_SIZE_sp_psyspoc_sem_for_psys_host2sp_cmd_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_output 0x30AC
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_output 0x30AC
#define HIVE_SIZE_sp_sp_output 16

/* function pixelgen_prbs_config: 112F */

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
#define HIVE_ADDR_ia_css_isys_stream_state_lock 0x4B7C
#define HIVE_SIZE_ia_css_isys_stream_state_lock 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_stream_state_lock scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_stream_state_lock 0x4B7C
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

/* function psyspoc_send_psys_event: AF6 */

/* function sp_dma_proxy_reset_channels: 184C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x2D38
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 484
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x2D38
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 484

/* function thread_fiber_sp_create: 3DFF */

/* function ia_css_dmaproxy_sp_set_increments: 16FF */

/* function pixelgen_tpg_is_done: 11A8 */

/* function ia_css_isys_stream_capture_indication: 3B8C */

/* function sp_start_isp_entry: 408 */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x408
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x408

/* function ia_css_dmaproxy_sp_channel_acquire: 187B */

/* function execute_stage: B41 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_delay_out_idx
#define HIVE_MEM_ia_css_ispctrl_sp_delay_out_idx scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_delay_out_idx 0x4E58
#define HIVE_SIZE_ia_css_ispctrl_sp_delay_out_idx 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_delay_out_idx scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_delay_out_idx 0x4E58
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_delay_out_idx 96

/* function ibuf_ctrl_config: F57 */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 1524 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_line
#define HIVE_MEM_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_line 0x4EB8
#define HIVE_SIZE_isp_vectors_per_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_line 0x4EB8
#define HIVE_SIZE_sp_isp_vectors_per_line 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_isys_thread
#define HIVE_MEM_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_isys_thread 0x2F5C
#define HIVE_SIZE_pocapp_isys_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_isys_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_isys_thread 0x2F5C
#define HIVE_SIZE_sp_pocapp_isys_thread 64

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x30C0
#define HIVE_SIZE_sp_group 2952
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x30C0
#define HIVE_SIZE_sp_sp_group 2952

/* function ia_css_thread_sp_kill: 3D34 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_output
#define HIVE_MEM_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_output 0x2CFC
#define HIVE_SIZE_pocapp_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_output 0x2CFC
#define HIVE_SIZE_sp_pocapp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_uv_internal_width_vecs
#define HIVE_MEM_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_uv_internal_width_vecs 0x4EBC
#define HIVE_SIZE_isp_uv_internal_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_uv_internal_width_vecs 0x4EBC
#define HIVE_SIZE_sp_isp_uv_internal_width_vecs 4

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

/* function ia_css_dmaproxy_sp_channel_release: 1864 */

/* function pixelgen_prbs_run: 111D */

/* function ia_css_dmaproxy_sp_is_idle: 1837 */

/* function isp_hmem_load: CF9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_sp_error_cnt
#define HIVE_MEM_ia_css_isys_sp_error_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_isys_sp_error_cnt 0x3C48
#define HIVE_SIZE_ia_css_isys_sp_error_cnt 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_sp_error_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_isys_sp_error_cnt 0x3C48
#define HIVE_SIZE_sp_ia_css_isys_sp_error_cnt 16

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
#define HIVE_ADDR_pocapp_host2sp_event_queue_handle 0x2D0C
#define HIVE_SIZE_pocapp_host2sp_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_host2sp_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_host2sp_event_queue_handle 0x2D0C
#define HIVE_SIZE_sp_pocapp_host2sp_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_b 0x4EC0
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_b 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 0x4EC0
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 4

/* function ia_css_thread_sp_set_priority: 3D2C */

/* function sizeof_hmem: DA4 */

/* function input_system_channel_open: 1408 */

/* function pixelgen_tpg_stop: 1197 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_threads
#define HIVE_MEM_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_threads 0x45C
#define HIVE_SIZE_pocapp_sp_threads 8
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_threads 0x45C
#define HIVE_SIZE_sp_pocapp_sp_threads 8

/* function __ia_css_dmaproxy_sp_process_text: 14A3 */

/* function ia_css_dmaproxy_sp_set_width_exception: 16E9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_param_handle
#define HIVE_MEM_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_param_handle 0x4BEC
#define HIVE_SIZE_param_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_param_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_param_handle 0x4BEC
#define HIVE_SIZE_sp_param_handle 12

/* function __modu: 4034 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 1543 */

/* function input_system_channel_transfer: 13F1 */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horiproj_num
#define HIVE_MEM_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horiproj_num 0x4EC4
#define HIVE_SIZE_isp_sdis_horiproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horiproj_num 0x4EC4
#define HIVE_SIZE_sp_isp_sdis_horiproj_num 4

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

/* function ia_css_queue_local_init: 3573 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp2host_event_queue_handle
#define HIVE_MEM_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp2host_event_queue_handle 0x2D18
#define HIVE_SIZE_pocapp_sp2host_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp2host_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp2host_event_queue_handle 0x2D18
#define HIVE_SIZE_sp_pocapp_sp2host_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x5608
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x5608
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

/* function ia_css_ispctrl_sp_isp_done_row_striping: 257D */

/* function __ia_css_virtual_isys_sp_isr_text: 3AA5 */

/* function ia_css_queue_dequeue: 33F2 */

/* function ia_css_dmaproxy_sp_configure_channel: 441F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue
#define HIVE_MEM_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_sem_for_isys_host2sp_cmd_queue 0x3C74
#define HIVE_SIZE_isyspoc_sem_for_isys_host2sp_cmd_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sem_for_isys_host2sp_cmd_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 0x3C74
#define HIVE_SIZE_sp_isyspoc_sem_for_isys_host2sp_cmd_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x5610
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x5610
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function ia_css_circbuf_pop: 3F50 */

/* function memset: 40B3 */

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

/* function ia_css_ispctrl_sp_init_ds: 1B35 */

/* function get_xmem_base_addr_raw: 1ED0 */

/* function pixelgen_tpg_config: 11CB */

/* function ia_css_circbuf_create: 3F9A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_out_frame_addr
#define HIVE_MEM_out_frame_addr scalar_processor_2400_dmem
#define HIVE_ADDR_out_frame_addr 0x4BF8
#define HIVE_SIZE_out_frame_addr 4
#else
#endif
#endif
#define HIVE_MEM_sp_out_frame_addr scalar_processor_2400_dmem
#define HIVE_ADDR_sp_out_frame_addr 0x4BF8
#define HIVE_SIZE_sp_out_frame_addr 4

/* function csi_rx_frontend_run: DAC */

/* function ia_css_isys_stream_open: 3C19 */

/* function input_system_channel_configure: 141C */

/* function isp_hmem_clear: CC0 */

/* function stream2mmio_config: 10C9 */

/* function ia_css_ispctrl_sp_start_binary: 196A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertproj_num
#define HIVE_MEM_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertproj_num 0x4EC8
#define HIVE_SIZE_isp_sdis_vertproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertproj_num 0x4EC8
#define HIVE_SIZE_sp_isp_sdis_vertproj_num 4

/* function csi_rx_frontend_config: DD0 */

/* function ia_css_rmgr_sp_rel_gen: 3C40 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0xD28
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0xD28
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ia_css_pipeline_sp_get_pipe_io_status: 6CB */

/* function sh_css_decode_tag_descr: 3C6 */

/* function debug_enqueue_isp: 2DB */

/* function ia_css_spctrl_sp_uninit: 3A5F */

/* function csi_rx_backend_run: DBE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x4BFC
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 80
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x4BFC
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 80

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x2D24
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x2D24
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 15B7 */

/* function ia_css_dmaproxy_sp_init: 14FE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertcoef_vectors
#define HIVE_MEM_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertcoef_vectors 0x4ECC
#define HIVE_SIZE_isp_sdis_vertcoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertcoef_vectors 0x4ECC
#define HIVE_SIZE_sp_isp_sdis_vertcoef_vectors 4

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

/* function input_system_channel_sync: 13DD */

/* function pocapp_sp_event_proxy_callout_func: 40EE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_ids 0x4C4C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_ids 52
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_ids 0x4C4C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_ids 52

/* function ia_css_queue_item_load: 3688 */

/* function ia_css_spctrl_sp_get_state: 3A4A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x5604
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x5604
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function ia_css_isys_stream_update_block: 9C8 */

/* function thread_fiber_sp_init: 3E86 */

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
#define HIVE_ADDR_sp_isp_input_stream_format 0x4C80
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x4C80
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 4020 */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 1623 */

/* function ia_css_thread_sp_join: 3D5D */

/* function ia_css_dmaproxy_sp_add_command: 44DF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x8A8
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x8A8
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 3B5F */

/* function ia_css_thread_sp_run: 3DC9 */

/* function ia_css_sp_isp_param_init_isp_memories: 2EDD */

/* function pocapp_init_psys_event_queues: B17 */

/* function irq_raise: C9 */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 145E */

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 43F1 */

/* function ia_css_ispctrl_sp_done_ds: 1B1E */

/* function csi_rx_backend_config: DE1 */

/* function ia_css_sp_isp_param_get_mem_inits: 2EB8 */

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
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x4C90
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x4C90
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_ispctrl_sp_init_isp_vars: 2AD7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pocapp_sp_event_proxy_thread
#define HIVE_MEM_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_pocapp_sp_event_proxy_thread 0x2F9C
#define HIVE_SIZE_pocapp_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_pocapp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pocapp_sp_event_proxy_thread 0x2F9C
#define HIVE_SIZE_sp_pocapp_sp_event_proxy_thread 64

/* function ia_css_isys_stream_start: 3BB7 */

/* function ia_css_dmaproxy_sp_write: 15CE */

/* function ia_css_isys_stream_start_async: 3BCF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x2CF0
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x2CF0
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_addresses 0x526C
#define HIVE_SIZE_sp_isp_addresses 180
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x526C
#define HIVE_SIZE_sp_sp_isp_addresses 180

/* function ia_css_rmgr_sp_acq_gen: 3C64 */

/* function input_system_input_port_open: 1336 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x3C58
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x3C58
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

/* function ia_css_queue_uninit: 3531 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x4ED0
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x4ED0
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_cropping_a 0x4ED4
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 0x4ED4
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 4

/* function ia_css_dmaproxy_sp_set_height_exception: 16D7 */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 1659 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle
#define HIVE_MEM_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_isyspoc_host2sp_isys_cmd_queue_handle 0x3C88
#define HIVE_SIZE_isyspoc_host2sp_isys_cmd_queue_handle 72
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_host2sp_isys_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_host2sp_isys_cmd_queue_handle 0x3C88
#define HIVE_SIZE_sp_isyspoc_host2sp_isys_cmd_queue_handle 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x560C
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x560C
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 15A0 */

/* function ia_css_queue_enqueue: 347C */

/* function ia_css_dmaproxy_sp_vmem_write: 155A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horicoef_vectors
#define HIVE_MEM_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horicoef_vectors 0x4ED8
#define HIVE_SIZE_isp_sdis_horicoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horicoef_vectors 0x4ED8
#define HIVE_SIZE_sp_isp_sdis_horicoef_vectors 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_data 0x5368
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_data 0x5368
#define HIVE_SIZE_sp_sp_data 640

/* function input_system_input_port_configure: 1388 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0xD20
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0xD20
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_mem_map 0x4CC0
#define HIVE_SIZE_mem_map 296
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x4CC0
#define HIVE_SIZE_sp_mem_map 296

/* function isys2401_dma_config_legacy: 109F */

/* function ia_css_virtual_isys_sp_isr: 44FB */

/* function thread_sp_queue_print: 3DE6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_a 0x4EDC
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 0x4EDC
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 4

/* function ia_css_circbuf_destroy: 3F91 */

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
#define HIVE_ADDR_isyspoc_sp2host_isys_event_queue_handle 0x3CD0
#define HIVE_SIZE_isyspoc_sp2host_isys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_isyspoc_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isyspoc_sp2host_isys_event_queue_handle 0x3CD0
#define HIVE_SIZE_sp_isyspoc_sp2host_isys_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_tnr_in_idx
#define HIVE_MEM_ia_css_ispctrl_sp_tnr_in_idx scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_tnr_in_idx 0x4EE0
#define HIVE_SIZE_ia_css_ispctrl_sp_tnr_in_idx 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_tnr_in_idx scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_tnr_in_idx 0x4EE0
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_tnr_in_idx 96

/* function __div: 3FD8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vf_output_width_vecs
#define HIVE_MEM_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vf_output_width_vecs 0x4F40
#define HIVE_SIZE_isp_vf_output_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vf_output_width_vecs 0x4F40
#define HIVE_SIZE_sp_isp_vf_output_width_vecs 4

/* function ia_css_thread_sem_sp_wait: 4637 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sleep_mode 0x3C5C
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x3C5C
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: E0 */

/* function ia_css_queue_remote_init: 3553 */

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
}
