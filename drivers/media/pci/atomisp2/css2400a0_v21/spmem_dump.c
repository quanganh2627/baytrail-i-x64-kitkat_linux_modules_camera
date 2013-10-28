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

#ifndef _sp_map_h_
#define _sp_map_h_


#ifndef _hrt_dummy_use_blob_sp
#define _hrt_dummy_use_blob_sp()
#endif

#define _hrt_cell_load_program_sp(proc) _hrt_cell_load_program_embedded(proc, sp)

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_input_line
#define HIVE_MEM_isp_vectors_per_input_line scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_vectors_per_input_line 0x363C
#define HIVE_SIZE_isp_vectors_per_input_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_input_line scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_vectors_per_input_line 0x363C
#define HIVE_SIZE_sp_isp_vectors_per_input_line 4

/* function input_system_acquisition_stop: 99F */

/* function longjmp: 5402 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_HIVE_IF_SRST_MASK
#define HIVE_MEM_HIVE_IF_SRST_MASK scalar_processor_2400A0_dmem
#define HIVE_ADDR_HIVE_IF_SRST_MASK 0x168
#define HIVE_SIZE_HIVE_IF_SRST_MASK 16
#else
#endif
#endif
#define HIVE_MEM_sp_HIVE_IF_SRST_MASK scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_HIVE_IF_SRST_MASK 0x168
#define HIVE_SIZE_sp_HIVE_IF_SRST_MASK 16

/* function ia_css_isys_sp_token_map_receive_ack: 4EB9 */

/* function ia_css_dmaproxy_sp_set_addr_B: 231D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_id 0x2E68
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_id 0x2E68
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_id 4

/* function debug_buffer_set_ddr_addr: D2 */

/* function receiver_port_reg_load: 983 */

/* function ia_css_circbuf_sp_create: DBA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_mipi
#define HIVE_MEM_vbuf_mipi scalar_processor_2400A0_dmem
#define HIVE_ADDR_vbuf_mipi 0x31C
#define HIVE_SIZE_vbuf_mipi 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_mipi scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_vbuf_mipi 0x31C
#define HIVE_SIZE_sp_vbuf_mipi 4

/* function ia_css_event_sp_decode: 23BA */

/* function setjmp: 540B */

/* function ia_css_ispctrl_sp_dma_configure_io: 3603 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x3C34
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_cp_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x3C34
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 4

/* function __dmaproxy_sp_read_write_text: 2387 */

/* function ia_css_dmaproxy_sp_wait_for_ack: 5A4F */

/* function ia_css_circbuf_sp_mark: C83 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_stage 0x3678
#define HIVE_SIZE_isp_stage 488
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_stage 0x3678
#define HIVE_SIZE_sp_isp_stage 488

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_raw
#define HIVE_MEM_vbuf_raw scalar_processor_2400A0_dmem
#define HIVE_ADDR_vbuf_raw 0x318
#define HIVE_SIZE_vbuf_raw 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_raw scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_vbuf_raw 0x318
#define HIVE_SIZE_sp_vbuf_raw 4

/* function ia_css_sp_bin_copy_func: 439E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_buffer_bufs 0x2E6C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_buffer_bufs 112
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 0x2E6C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 112

/* function sp_start_isp: 388 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_binary_group 0x391C
#define HIVE_SIZE_sp_binary_group 72
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x391C
#define HIVE_SIZE_sp_sp_binary_group 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sw_state 0x2670
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x2670
#define HIVE_SIZE_sp_sp_sw_state 4

/* function generate_sw_interrupt: 852 */

/* function ia_css_thread_sp_main: ED3 */

/* function ia_css_ispctrl_sp_init_internal_buffers: 257B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x3640
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_vfout_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x3640
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 4

/* function ia_css_tagger_sp_propagate_frame: 1982 */

/* function ispctrl_sp_dma_sct_configure: 3BBD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x3C38
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x3C38
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

/* function input_system_reg_load: 9DF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_handles
#define HIVE_MEM_vbuf_handles scalar_processor_2400A0_dmem
#define HIVE_ADDR_vbuf_handles 0x3CAC
#define HIVE_SIZE_vbuf_handles 240
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_handles scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_vbuf_handles 0x3CAC
#define HIVE_SIZE_sp_vbuf_handles 240

/* function ia_css_isys_sp_token_map_destroy: 4FF1 */

/* function ia_css_sp_flash_register: 1DD7 */

/* function ia_css_isys_sp_backend_create: 4B1F */

/* function ia_css_circbuf_sp_unmark: C5B */

/* function ia_css_pipeline_sp_init: 1415 */

/* function ia_css_tagger_sp_configure: 191D */

/* function ia_css_ispctrl_sp_end_binary: 23F5 */

/* function receiver_port_reg_store: 98A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_is_pending_mask
#define HIVE_MEM_event_is_pending_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_event_is_pending_mask 0x58
#define HIVE_SIZE_event_is_pending_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_is_pending_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_event_is_pending_mask 0x58
#define HIVE_SIZE_sp_event_is_pending_mask 44

/* function ispctrl_sp_dma_ref_set_start_addr: 3D76 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cb_elems_frame
#define HIVE_MEM_sp_all_cb_elems_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_all_cb_elems_frame 0x2BA4
#define HIVE_SIZE_sp_all_cb_elems_frame 32
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_frame 0x2BA4
#define HIVE_SIZE_sp_sp_all_cb_elems_frame 32

/* function ia_css_circbuf_sp_pop_marked: B87 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400A0_dmem
#define HIVE_ADDR_host_sp_com 0x2674
#define HIVE_SIZE_host_sp_com 96
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_host_sp_com 0x2674
#define HIVE_SIZE_sp_host_sp_com 96

/* function exec_image_pipe: 538 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x26D4
#define HIVE_SIZE_sp_init_dmem_data 36
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x26D4
#define HIVE_SIZE_sp_sp_init_dmem_data 36

/* function ia_css_pipeline_sp_stop: 13F8 */

/* function ia_css_tagger_sp_connect_pipes: 1D6A */

/* function ispctrl_sp_dma_dvs_configure: 3B2B */

/* function is_isp_debug_buffer_full: 323 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_per_frame_data 0x26F8
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x26F8
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_rmgr_sp_vbuf_dequeue: 51F4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_xmem_bin_addr
#define HIVE_MEM_xmem_bin_addr scalar_processor_2400A0_dmem
#define HIVE_ADDR_xmem_bin_addr 0x26FC
#define HIVE_SIZE_xmem_bin_addr 4
#else
#endif
#endif
#define HIVE_MEM_sp_xmem_bin_addr scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_xmem_bin_addr 0x26FC
#define HIVE_SIZE_sp_xmem_bin_addr 4

/* function ia_css_pipeline_sp_run: 1194 */

/* function memcpy: 54AB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0x32C
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0x32C
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x180
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x180
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function input_system_reg_store: 9E6 */

/* function sp_dma_proxy_set_width_ab: 21A4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_in_buf 0x3644
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_in_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_in_buf 0x3644
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_in_buf 4

/* function ia_css_isys_sp_frontend_start: 4D59 */

/* function ia_css_uds_sp_scale_params: 4145 */

/* function __divu: 5429 */

/* function ia_css_thread_sp_get_state: E02 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_stop
#define HIVE_MEM_sem_for_cont_capt_stop scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_cont_capt_stop 0x2BC4
#define HIVE_SIZE_sem_for_cont_capt_stop 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_stop scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_stop 0x2BC4
#define HIVE_SIZE_sp_sem_for_cont_capt_stop 20

/* function thread_fiber_sp_main: FB1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_pipe_thread
#define HIVE_MEM_sp_isp_pipe_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_pipe_thread 0x2D10
#define HIVE_SIZE_sp_isp_pipe_thread 256
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_pipe_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_isp_pipe_thread 0x2D10
#define HIVE_SIZE_sp_sp_isp_pipe_thread 256

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_start_bq
#define HIVE_MEM_sp_obarea_start_bq scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_obarea_start_bq 0x2700
#define HIVE_SIZE_sp_obarea_start_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_start_bq scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_obarea_start_bq 0x2700
#define HIVE_SIZE_sp_sp_obarea_start_bq 4

/* function ia_css_parambuf_sp_handle_parameter_sets: 1053 */

/* function ia_css_thread_sem_sp_signal: 56A5 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_IRQ_BASE
#define HIVE_MEM_IRQ_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_IRQ_BASE 0x28
#define HIVE_SIZE_IRQ_BASE 16
#else
#endif
#endif
#define HIVE_MEM_sp_IRQ_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_IRQ_BASE 0x28
#define HIVE_SIZE_sp_IRQ_BASE 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_TIMED_CTRL_BASE
#define HIVE_MEM_TIMED_CTRL_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_TIMED_CTRL_BASE 0x3C
#define HIVE_SIZE_TIMED_CTRL_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_TIMED_CTRL_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_TIMED_CTRL_BASE 0x3C
#define HIVE_SIZE_sp_TIMED_CTRL_BASE 4

/* function ia_css_isys_sp_isr: 5BE7 */

/* function ispctrl_sp_dma_tnr_out_reconfigure: 3C21 */

/* function ia_css_rmgr_sp_init: 50FF */

/* function ia_css_thread_sem_sp_init: 5771 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400A0_dmem
#define HIVE_ADDR_is_isp_requested 0x338
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_is_isp_requested 0x338
#define HIVE_SIZE_sp_is_isp_requested 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_frame
#define HIVE_MEM_sem_for_reading_cb_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_reading_cb_frame 0x2BD8
#define HIVE_SIZE_sem_for_reading_cb_frame 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_frame 0x2BD8
#define HIVE_SIZE_sp_sem_for_reading_cb_frame 40

/* function ia_css_dmaproxy_sp_execute: 225D */

/* function ia_css_pipeline_sp_has_stopped: 13EE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_current_sp_thread 0x17C
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x17C
#define HIVE_SIZE_sp_current_sp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_cur_co_fr_ct 0x3C3C
#define HIVE_SIZE_ia_css_rawcopy_sp_cur_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_cur_co_fr_ct 0x3C3C
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_cur_co_fr_ct 4

/* function ia_css_dmaproxy_sp_read_byte_addr: 5A7D */

/* function ia_css_rmgr_sp_uninit: 50F8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack
#define HIVE_MEM_sp_threads_stack scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_threads_stack 0x11C
#define HIVE_SIZE_sp_threads_stack 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_threads_stack 0x11C
#define HIVE_SIZE_sp_sp_threads_stack 20

/* function ia_css_parambuf_sp_wait_for_in_param: FB8 */

/* function ia_css_isys_sp_token_map_get_exp_id: 4F8A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cb_elems_param
#define HIVE_MEM_sp_all_cb_elems_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_all_cb_elems_param 0x2C00
#define HIVE_SIZE_sp_all_cb_elems_param 32
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_param 0x2C00
#define HIVE_SIZE_sp_sp_all_cb_elems_param 32

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0x190
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0x190
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_param
#define HIVE_MEM_sem_for_reading_cb_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_reading_cb_param 0x2C20
#define HIVE_SIZE_sem_for_reading_cb_param 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_param 0x2C20
#define HIVE_SIZE_sp_sem_for_reading_cb_param 40

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_start
#define HIVE_MEM_sem_for_cont_capt_start scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_cont_capt_start 0x2C48
#define HIVE_SIZE_sem_for_cont_capt_start 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_start scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_start 0x2C48
#define HIVE_SIZE_sp_sem_for_cont_capt_start 20

/* function host2sp_event_queue_is_empty: 5B80 */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 3063 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x2EDC
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x2EDC
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function ispctrl_sp_dma_ref_configure: 3C72 */

/* function debug_buffer_init_isp: D9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem
#define HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_rmgr_sp_mipi_frame_sem 0x3D9C
#define HIVE_SIZE_ia_css_rmgr_sp_mipi_frame_sem 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_rmgr_sp_mipi_frame_sem 0x3D9C
#define HIVE_SIZE_sp_ia_css_rmgr_sp_mipi_frame_sem 20

/* function ia_css_sp_raw_copy_func: 444E */

/* function ia_css_rmgr_sp_refcount_dump: 51CF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_pipe_threads
#define HIVE_MEM_sp_pipe_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_pipe_threads 0x10C
#define HIVE_SIZE_sp_pipe_threads 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_pipe_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_pipe_threads 0x10C
#define HIVE_SIZE_sp_sp_pipe_threads 16

/* function sp_event_proxy_func: 6B3 */

/* function ia_css_thread_sp_yield: 561F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x3634
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x3634
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

/* function ia_css_thread_sp_fork: E8F */

/* function ia_css_tagger_sp_destroy: 1D74 */

/* function ia_css_dmaproxy_sp_vmem_read: 21E6 */

/* function ispctrl_sp_dma_fpn_configure: 3B96 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ispctrl_sp_dma_configs
#define HIVE_MEM_ispctrl_sp_dma_configs scalar_processor_2400A0_dmem
#define HIVE_ADDR_ispctrl_sp_dma_configs 0x3BE4
#define HIVE_SIZE_ispctrl_sp_dma_configs 80
#else
#endif
#endif
#define HIVE_MEM_sp_ispctrl_sp_dma_configs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ispctrl_sp_dma_configs 0x3BE4
#define HIVE_SIZE_sp_ispctrl_sp_dma_configs 80

/* function ia_css_ifmtr_sp_init: 5066 */

/* function initialize_sp_group: 68A */

/* function __ia_css_sp_raw_copy_func_critical: 5B8A */

/* function ispctrl_sp_dma_yuv_configure_stream: 3EAA */

/* function ia_css_thread_sp_init: EBB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_DMEM_BASE
#define HIVE_MEM_ISP_DMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_DMEM_BASE 0x10
#define HIVE_SIZE_ISP_DMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_DMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_DMEM_BASE 0x10
#define HIVE_SIZE_sp_ISP_DMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_SP_DMEM_BASE
#define HIVE_MEM_SP_DMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_SP_DMEM_BASE 0x4
#define HIVE_SIZE_SP_DMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_SP_DMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_SP_DMEM_BASE 0x4
#define HIVE_SIZE_sp_SP_DMEM_BASE 4

/* function ia_css_dmaproxy_sp_read: 227E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400A0_dmem
#define HIVE_ADDR_raw_copy_line_count 0x2EC
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0x2EC
#define HIVE_SIZE_sp_raw_copy_line_count 4

/* function ispctrl_sp_dma_crop_configure: 3A82 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_frame_cnt
#define HIVE_MEM_ia_css_flash_sp_frame_cnt scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_flash_sp_frame_cnt 0x2E5C
#define HIVE_SIZE_ia_css_flash_sp_frame_cnt 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_frame_cnt scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_frame_cnt 0x2E5C
#define HIVE_SIZE_sp_ia_css_flash_sp_frame_cnt 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_can_send_token_mask
#define HIVE_MEM_event_can_send_token_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_event_can_send_token_mask 0x84
#define HIVE_SIZE_event_can_send_token_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_can_send_token_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_event_can_send_token_mask 0x84
#define HIVE_SIZE_sp_event_can_send_token_mask 44

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_thread 0x3860
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_thread 0x3860
#define HIVE_SIZE_sp_isp_thread 4

/* function ia_css_isys_sp_frontend_destroy: 4DDA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_length_bq
#define HIVE_MEM_sp_obarea_length_bq scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_obarea_length_bq 0x2704
#define HIVE_SIZE_sp_obarea_length_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_length_bq scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_obarea_length_bq 0x2704
#define HIVE_SIZE_sp_sp_obarea_length_bq 4

/* function is_ddr_debug_buffer_full: 2BB */

/* function ia_css_isys_sp_frontend_stop: 4D2B */

/* function ispctrl_sp_dma_tnr_configure: 3BE0 */

/* function ia_css_isys_sp_token_map_init: 5032 */

/* function sp_dma_proxy_isp_write_addr: 21FE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_fiber
#define HIVE_MEM_sp_threads_fiber scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_threads_fiber 0x144
#define HIVE_SIZE_sp_threads_fiber 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_fiber scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_threads_fiber 0x144
#define HIVE_SIZE_sp_sp_threads_fiber 20

/* function ispctrl_sp_dma_yuv_configure_nonstream: 3F66 */

/* function encode_and_post_sp_event: 93E */

/* function debug_enqueue_ddr: E3 */

/* function ispctrl_sp_dma_channel_configure: 3DFC */

/* function ia_css_rmgr_sp_refcount_init_vbuf: 519A */

/* function dmaproxy_sp_read_write: 5B00 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x3638
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x3638
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 57A9 */

/* function host2sp_dequeue_buffer: 4382 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_service
#define HIVE_MEM_ia_css_flash_sp_in_service scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_service 0x1EAC
#define HIVE_SIZE_ia_css_flash_sp_in_service 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_service scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_service 0x1EAC
#define HIVE_SIZE_sp_ia_css_flash_sp_in_service 4

/* function ia_css_dmaproxy_sp_process: 57F8 */

/* function sp2host_enqueue_buffer: 4362 */

/* function ia_css_isys_sp_backend_rcv_acquire_ack: 49BC */

/* function ia_css_isys_sp_backend_pre_acquire_request: 49D2 */

/* function ia_css_ispctrl_sp_init_cs: 24B4 */

/* function sp_event_proxy_init: 6DA */

/* function ia_css_circbuf_sp_extract: CAB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_output 0x2708
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_output 0x2708
#define HIVE_SIZE_sp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x2F0C
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_host2sp_buf_queues 560
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x2F0C
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 560

/* function ispctrl_sp_dma_tnr_set_start_addr: 3C2C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_CTRL_BASE
#define HIVE_MEM_ISP_CTRL_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_CTRL_BASE 0x8
#define HIVE_SIZE_ISP_CTRL_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_CTRL_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_CTRL_BASE 0x8
#define HIVE_SIZE_sp_ISP_CTRL_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_INPUT_FORMATTER_BASE
#define HIVE_MEM_INPUT_FORMATTER_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_INPUT_FORMATTER_BASE 0x48
#define HIVE_SIZE_INPUT_FORMATTER_BASE 16
#else
#endif
#endif
#define HIVE_MEM_sp_INPUT_FORMATTER_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_INPUT_FORMATTER_BASE 0x48
#define HIVE_SIZE_sp_INPUT_FORMATTER_BASE 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp2host_event_queue
#define HIVE_MEM_sem_for_sp2host_event_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_sp2host_event_queue 0x2B90
#define HIVE_SIZE_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp2host_event_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_sp2host_event_queue 0x2B90
#define HIVE_SIZE_sp_sem_for_sp2host_event_queue 20

/* function ia_css_isys_sp_backend_acquire: 4AF5 */

/* function ia_css_tagger_sp_update_size: 1DCE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x313C
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 1036
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x313C
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 1036

/* function thread_fiber_sp_create: F20 */

/* function host2sp_dequeue_sp_event: 433F */

/* function ia_css_dmaproxy_sp_set_increments: 230F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_frame
#define HIVE_MEM_sem_for_writing_cb_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_writing_cb_frame 0x2C5C
#define HIVE_SIZE_sem_for_writing_cb_frame 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_frame 0x2C5C
#define HIVE_SIZE_sp_sem_for_writing_cb_frame 20

/* function receiver_reg_store: 998 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_param
#define HIVE_MEM_sem_for_writing_cb_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_writing_cb_param 0x2C70
#define HIVE_SIZE_sem_for_writing_cb_param 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_param 0x2C70
#define HIVE_SIZE_sp_sem_for_writing_cb_param 20

/* function sp_start_isp_entry: 37E */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x37E
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x37E

/* function ia_css_dmaproxy_sp_channel_acquire: 5B6C */

/* function sp2host_enqueue_irq_event: 4320 */

/* function ia_css_rmgr_sp_add_num_vbuf: 5377 */

/* function ia_css_isys_sp_token_map_create: 505F */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 219B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_line
#define HIVE_MEM_isp_vectors_per_line scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_vectors_per_line 0x3648
#define HIVE_SIZE_isp_vectors_per_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_line scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_vectors_per_line 0x3648
#define HIVE_SIZE_sp_isp_vectors_per_line 4

/* function ia_css_bufq_sp_is_dynamic_buffer: 2045 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_group 0x2718
#define HIVE_SIZE_sp_group 864
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_group 0x2718
#define HIVE_SIZE_sp_sp_group 864

/* function sp2host_buffer_queue_get_size: 4356 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_event_proxy_thread
#define HIVE_MEM_sp_event_proxy_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_event_proxy_thread 0x2E10
#define HIVE_SIZE_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_sp_event_proxy_thread scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_event_proxy_thread 0x2E10
#define HIVE_SIZE_sp_sp_event_proxy_thread 64

/* function ia_css_thread_sp_kill: E55 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_uv_internal_width_vecs
#define HIVE_MEM_isp_uv_internal_width_vecs scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_uv_internal_width_vecs 0x364C
#define HIVE_SIZE_isp_uv_internal_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_uv_internal_width_vecs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_uv_internal_width_vecs 0x364C
#define HIVE_SIZE_sp_isp_uv_internal_width_vecs 4

/* function ia_css_tagger_sp_create: 1D95 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_MMU_BASE
#define HIVE_MEM_MMU_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_MMU_BASE 0x24
#define HIVE_SIZE_MMU_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_MMU_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_MMU_BASE 0x24
#define HIVE_SIZE_sp_MMU_BASE 4

/* function ia_css_dmaproxy_sp_channel_release: 5B58 */

/* function ia_css_dmaproxy_sp_is_idle: 23A5 */

/* function sp2host_event_queue_get_size: 4317 */

/* function isp_hmem_load: A1D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_sp_error_cnt
#define HIVE_MEM_ia_css_isys_sp_error_cnt scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_isys_sp_error_cnt 0x3C68
#define HIVE_SIZE_ia_css_isys_sp_error_cnt 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_sp_error_cnt scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_isys_sp_error_cnt 0x3C68
#define HIVE_SIZE_sp_ia_css_isys_sp_error_cnt 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_debug_buffer_ddr_address
#define HIVE_MEM_debug_buffer_ddr_address scalar_processor_2400A0_dmem
#define HIVE_ADDR_debug_buffer_ddr_address 0xB8
#define HIVE_SIZE_debug_buffer_ddr_address 4
#else
#endif
#endif
#define HIVE_MEM_sp_debug_buffer_ddr_address scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_debug_buffer_ddr_address 0xB8
#define HIVE_SIZE_sp_debug_buffer_ddr_address 4

/* function ispctrl_sp_dma_vf_configure: 36B8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_i_mipi_exp_id
#define HIVE_MEM_ia_css_i_mipi_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_i_mipi_exp_id 0x320
#define HIVE_SIZE_ia_css_i_mipi_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_mipi_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_i_mipi_exp_id 0x320
#define HIVE_SIZE_sp_ia_css_i_mipi_exp_id 1

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_b 0x3650
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_b 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 0x3650
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 4

/* function ia_css_rmgr_sp_refcount_retain_vbuf: 5259 */

/* function ia_css_thread_sp_set_priority: E4D */

/* function sizeof_hmem: AB9 */

/* function cnd_input_system_cfg: 548 */

/* function __ia_css_dmaproxy_sp_process_text: 20CA */

/* function ia_css_dmaproxy_sp_set_width_exception: 2308 */

/* function ia_css_flash_sp_init_internal_params: 1E2C */

/* function sp_generate_events: 868 */

/* function __modu: 546F */

/* function ia_css_dmaproxy_sp_init_isp_vector: 21B8 */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horiproj_num
#define HIVE_MEM_isp_sdis_horiproj_num scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_sdis_horiproj_num 0x3654
#define HIVE_SIZE_isp_sdis_horiproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horiproj_num scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_sdis_horiproj_num 0x3654
#define HIVE_SIZE_sp_isp_sdis_horiproj_num 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GDC_BASE
#define HIVE_MEM_GDC_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_GDC_BASE 0x40
#define HIVE_SIZE_GDC_BASE 8
#else
#endif
#endif
#define HIVE_MEM_sp_GDC_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_GDC_BASE 0x40
#define HIVE_SIZE_sp_GDC_BASE 8

/* function sp_event_proxy_callout_func: 54EE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x2E50
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x2E50
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack_size
#define HIVE_MEM_sp_threads_stack_size scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_threads_stack_size 0x130
#define HIVE_SIZE_sp_threads_stack_size 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack_size scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_threads_stack_size 0x130
#define HIVE_SIZE_sp_sp_threads_stack_size 20

/* function __ia_css_isys_sp_isr_text: 4E1D */

/* function ia_css_circbuf_sp_pop: D6C */

/* function ispctrl_sp_dma_yuv_configure: 3E55 */

/* function ia_css_dmaproxy_sp_configure_channel: 5A94 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400A0_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x2E58
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x2E58
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function irq_raise_set_token: AB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GPIO_BASE
#define HIVE_MEM_GPIO_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_GPIO_BASE 0x38
#define HIVE_SIZE_GPIO_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GPIO_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_GPIO_BASE 0x38
#define HIVE_SIZE_sp_GPIO_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_ph
#define HIVE_MEM_isp_ph scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_ph 0x3C74
#define HIVE_SIZE_isp_ph 28
#else
#endif
#endif
#define HIVE_MEM_sp_isp_ph scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_ph 0x3C74
#define HIVE_SIZE_sp_isp_ph 28

/* function ia_css_isys_sp_token_map_flush: 4FD4 */

/* function ia_css_ispctrl_sp_init_ds: 2631 */

/* function ia_css_circbuf_sp_push_marked: BD3 */

/* function get_xmem_base_addr_raw: 2984 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_param
#define HIVE_MEM_sp_all_cbs_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_all_cbs_param 0x2C84
#define HIVE_SIZE_sp_all_cbs_param 40
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_param scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_all_cbs_param 0x2C84
#define HIVE_SIZE_sp_sp_all_cbs_param 40

/* function ia_css_circbuf_sp_pop_unmarked: AC0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_co_fr_ct 0x3C40
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 0x3C40
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp_group
#define HIVE_MEM_sem_for_sp_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_sp_group 0x2CAC
#define HIVE_SIZE_sem_for_sp_group 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp_group scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_sp_group 0x2CAC
#define HIVE_SIZE_sp_sem_for_sp_group 20

/* function ia_css_framebuf_sp_wait_for_in_frame: 539B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_i_raw_exp_id
#define HIVE_MEM_ia_css_i_raw_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_i_raw_exp_id 0x3DB0
#define HIVE_SIZE_ia_css_i_raw_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_raw_exp_id scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_i_raw_exp_id 0x3DB0
#define HIVE_SIZE_sp_ia_css_i_raw_exp_id 1

/* function isp_hmem_clear: 9ED */

/* function ia_css_framebuf_sp_release_in_frame: 53D5 */

/* function ia_css_isys_sp_backend_snd_acquire_request: 4A43 */

/* function ia_css_isys_sp_token_map_is_full: 4E88 */

/* function input_system_acquisition_run: 9BD */

/* function ia_css_ispctrl_sp_start_binary: 2491 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertproj_num
#define HIVE_MEM_isp_sdis_vertproj_num scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_sdis_vertproj_num 0x3658
#define HIVE_SIZE_isp_sdis_vertproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertproj_num scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_sdis_vertproj_num 0x3658
#define HIVE_SIZE_sp_isp_sdis_vertproj_num 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs
#define HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x3548
#define HIVE_SIZE_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x3548
#define HIVE_SIZE_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16

/* function ia_css_circbuf_sp_destroy: DAE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_pool
#define HIVE_MEM_isp_pool scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_pool 0x310
#define HIVE_SIZE_isp_pool 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_pool scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_pool 0x310
#define HIVE_SIZE_sp_isp_pool 4

/* function ia_css_rmgr_sp_rel_gen: 5141 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_event_any_pending_mask 0x330
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0x330
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ia_css_isys_sp_backend_push: 49E6 */

/* function sh_css_decode_tag_descr: 33E */

/* function ia_css_circbuf_sp_is_marked: C36 */

/* function debug_enqueue_isp: 26A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_HIVE_IF_SWITCH_CODE
#define HIVE_MEM_HIVE_IF_SWITCH_CODE scalar_processor_2400A0_dmem
#define HIVE_ADDR_HIVE_IF_SWITCH_CODE 0x178
#define HIVE_SIZE_HIVE_IF_SWITCH_CODE 4
#else
#endif
#endif
#define HIVE_MEM_sp_HIVE_IF_SWITCH_CODE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_HIVE_IF_SWITCH_CODE 0x178
#define HIVE_SIZE_sp_HIVE_IF_SWITCH_CODE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x3558
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 32
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x3558
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 32

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x2CC0
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x2CC0
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 222C */

/* function ia_css_dmaproxy_sp_init: 2175 */

/* function ispctrl_sp_dma_raw_configure: 3889 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_vf_downscale_bits
#define HIVE_MEM_sp_vf_downscale_bits scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_vf_downscale_bits 0x2A78
#define HIVE_SIZE_sp_vf_downscale_bits 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_vf_downscale_bits scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_vf_downscale_bits 0x2A78
#define HIVE_SIZE_sp_sp_vf_downscale_bits 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertcoef_vectors
#define HIVE_MEM_isp_sdis_vertcoef_vectors scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_sdis_vertcoef_vectors 0x365C
#define HIVE_SIZE_isp_sdis_vertcoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertcoef_vectors scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_sdis_vertcoef_vectors 0x365C
#define HIVE_SIZE_sp_isp_sdis_vertcoef_vectors 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_VAMEM_BASE
#define HIVE_MEM_ISP_VAMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_VAMEM_BASE 0x14
#define HIVE_SIZE_ISP_VAMEM_BASE 12
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_VAMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_VAMEM_BASE 0x14
#define HIVE_SIZE_sp_ISP_VAMEM_BASE 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tagger
#define HIVE_MEM_ia_css_rawcopy_sp_tagger scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tagger 0x3C44
#define HIVE_SIZE_ia_css_rawcopy_sp_tagger 24
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tagger scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tagger 0x3C44
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tagger 24

/* function thread_fiber_sp_init: FA7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_SP_PMEM_BASE
#define HIVE_MEM_SP_PMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_SP_PMEM_BASE 0x0
#define HIVE_SIZE_SP_PMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_SP_PMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_SP_PMEM_BASE 0x0
#define HIVE_SIZE_sp_SP_PMEM_BASE 4

/* function ia_css_isys_sp_token_map_snd_acquire_req: 4F73 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_input_stream_format
#define HIVE_MEM_sp_isp_input_stream_format scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_input_stream_format 0x2A7C
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x2A7C
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 545B */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 2298 */

/* function ia_css_thread_sp_join: E7E */

/* function ia_css_dmaproxy_sp_add_command: 5B3C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400A0_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x23C
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x23C
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_circbuf_sp_peek: B62 */

/* function ia_css_event_sp_encode: 23E4 */

/* function ia_css_thread_sp_run: EEA */

/* function sp_isys_copy_func: 6AC */

/* function ia_css_isys_sp_backend_flush: 4A64 */

/* function ia_css_sp_input_system_token_map_reset_capturing_buffer_on_error: 4E5E */

/* function register_isr: 7C7 */

/* function irq_raise: BD */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 2060 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_HIVE_IF_SRST_ADDRESS
#define HIVE_MEM_HIVE_IF_SRST_ADDRESS scalar_processor_2400A0_dmem
#define HIVE_ADDR_HIVE_IF_SRST_ADDRESS 0x158
#define HIVE_SIZE_HIVE_IF_SRST_ADDRESS 16
#else
#endif
#endif
#define HIVE_MEM_sp_HIVE_IF_SRST_ADDRESS scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_HIVE_IF_SRST_ADDRESS 0x158
#define HIVE_SIZE_sp_HIVE_IF_SRST_ADDRESS 16

/* function pipeline_sp_initialize_stage: 1438 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_isys_sp_frontend_states
#define HIVE_MEM_ia_css_isys_sp_frontend_states scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_isys_sp_frontend_states 0x3C5C
#define HIVE_SIZE_ia_css_isys_sp_frontend_states 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_isys_sp_frontend_states scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_isys_sp_frontend_states 0x3C5C
#define HIVE_SIZE_sp_ia_css_isys_sp_frontend_states 12

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 5A66 */

/* function ia_css_ispctrl_sp_done_ds: 260B */

/* function ia_css_parambuf_sp_init_buffer_queues: 1181 */

/* function input_system_cfg: 97C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_HMEM_BASE
#define HIVE_MEM_ISP_HMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_HMEM_BASE 0x20
#define HIVE_SIZE_ISP_HMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_HMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_HMEM_BASE 0x20
#define HIVE_SIZE_sp_ISP_HMEM_BASE 4

/* function ispctrl_sp_dma_s3at_configure: 36FF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_frames
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x3578
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x3578
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_isys_sp_backend_release: 4ADC */

/* function ia_css_isys_sp_backend_destroy: 4B06 */

/* function ia_css_isys_sp_token_map_check_mipi_frame_size: 4F3E */

/* function ia_css_ispctrl_sp_init_isp_vars: 3316 */

/* function ia_css_isys_sp_frontend_has_empty_mipi_buffer_cb: 4B53 */

/* function ia_css_rmgr_sp_vbuf_enqueue: 521F */

/* function ia_css_tagger_sp_tag_exp_id: 18C5 */

/* function ia_css_dmaproxy_sp_write: 2243 */

/* function ia_css_parambuf_sp_release_in_param: 101F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400A0_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x2668
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x2668
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_addresses 0x3864
#define HIVE_SIZE_sp_isp_addresses 184
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x3864
#define HIVE_SIZE_sp_sp_isp_addresses 184

/* function ia_css_rmgr_sp_acq_gen: 5159 */

/* function receiver_reg_load: 991 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isps
#define HIVE_MEM_isps scalar_processor_2400A0_dmem
#define HIVE_ADDR_isps 0x3C90
#define HIVE_SIZE_isps 28
#else
#endif
#endif
#define HIVE_MEM_sp_isps scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isps 0x3C90
#define HIVE_SIZE_sp_isps 28

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400A0_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x2A8C
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x2A8C
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_buf_swap
#define HIVE_MEM_ia_css_ispctrl_sp_buf_swap scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_buf_swap 0x2368
#define HIVE_SIZE_ia_css_ispctrl_sp_buf_swap 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_buf_swap scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_buf_swap 0x2368
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_buf_swap 96

/* function ia_css_circbuf_sp_push_unmarked: B04 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x3660
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x3660
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_bufq_sp_release_dynamic_buf: 1E37 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_cropping_a 0x3664
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 0x3664
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 4

/* function ia_css_dmaproxy_sp_set_height_exception: 22FA */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 22C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_num_ready_threads 0x2E54
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x2E54
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 2215 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_spref
#define HIVE_MEM_vbuf_spref scalar_processor_2400A0_dmem
#define HIVE_ADDR_vbuf_spref 0x314
#define HIVE_SIZE_vbuf_spref 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_spref scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_vbuf_spref 0x314
#define HIVE_SIZE_sp_vbuf_spref 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_request
#define HIVE_MEM_ia_css_flash_sp_request scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_flash_sp_request 0x2E60
#define HIVE_SIZE_ia_css_flash_sp_request 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_request scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_request 0x2E60
#define HIVE_SIZE_sp_ia_css_flash_sp_request 4

/* function ia_css_dmaproxy_sp_vmem_write: 21CF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horicoef_vectors
#define HIVE_MEM_isp_sdis_horicoef_vectors scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_sdis_horicoef_vectors 0x3668
#define HIVE_SIZE_isp_sdis_horicoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horicoef_vectors scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_sdis_horicoef_vectors 0x3668
#define HIVE_SIZE_sp_isp_sdis_horicoef_vectors 4

/* function ia_css_isys_sp_token_map_snd_capture_req: 4FAB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_if
#define HIVE_MEM_sem_for_reading_if scalar_processor_2400A0_dmem
#define HIVE_ADDR_sem_for_reading_if 0x2CD4
#define HIVE_SIZE_sem_for_reading_if 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_if scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sem_for_reading_if 0x2CD4
#define HIVE_SIZE_sp_sem_for_reading_if 20

/* function sp_generate_interrupts: 7CF */

/* function ia_css_pipeline_sp_start: 1400 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_data 0x3964
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_data 0x3964
#define HIVE_SIZE_sp_sp_data 640

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0x328
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0x328
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

/* function ia_css_isys_sp_frontend_rcv_capture_ack: 4C0E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x35A8
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_sp2host_buf_queues 140
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x35A8
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 140

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400A0_dmem
#define HIVE_ADDR_mem_map 0x2A90
#define HIVE_SIZE_mem_map 248
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_mem_map 0x2A90
#define HIVE_SIZE_sp_mem_map 248

/* function sp_init_dmem: 620 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_frame
#define HIVE_MEM_sp_all_cbs_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_all_cbs_frame 0x2CE8
#define HIVE_SIZE_sp_all_cbs_frame 40
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_frame scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_all_cbs_frame 0x2CE8
#define HIVE_SIZE_sp_sp_all_cbs_frame 40

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_out_buf 0x366C
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_out_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_out_buf 0x366C
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_out_buf 4

/* function thread_sp_queue_print: F07 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_a 0x3670
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 0x3670
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 4

/* function ia_css_bufq_sp_acquire_dynamic_buf: 1F9E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_PMEM_BASE
#define HIVE_MEM_ISP_PMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_ISP_PMEM_BASE 0xC
#define HIVE_SIZE_ISP_PMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_PMEM_BASE scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ISP_PMEM_BASE 0xC
#define HIVE_SIZE_sp_ISP_PMEM_BASE 4

/* function __div: 5413 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vf_output_width_vecs
#define HIVE_MEM_isp_vf_output_width_vecs scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_vf_output_width_vecs 0x3674
#define HIVE_SIZE_isp_vf_output_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vf_output_width_vecs scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_vf_output_width_vecs 0x3674
#define HIVE_SIZE_sp_isp_vf_output_width_vecs 4

/* function ia_css_isys_sp_frontend_create: 4DF0 */

/* function ia_css_rmgr_sp_refcount_release_vbuf: 5238 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_use
#define HIVE_MEM_ia_css_flash_sp_in_use scalar_processor_2400A0_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_use 0x2E64
#define HIVE_SIZE_ia_css_flash_sp_in_use 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_use scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_use 0x2E64
#define HIVE_SIZE_sp_ia_css_flash_sp_in_use 4

/* function ia_css_thread_sem_sp_wait: 56F0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sleep_mode 0x2B88
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x2B88
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_max_cb_elems
#define HIVE_MEM_sp_max_cb_elems scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_max_cb_elems 0x104
#define HIVE_SIZE_sp_max_cb_elems 8
#else
#endif
#endif
#define HIVE_MEM_sp_sp_max_cb_elems scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_sp_max_cb_elems 0x104
#define HIVE_SIZE_sp_sp_max_cb_elems 8

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stop_req
#define HIVE_MEM_isp_stop_req scalar_processor_2400A0_dmem
#define HIVE_ADDR_isp_stop_req 0x2B8C
#define HIVE_SIZE_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stop_req scalar_processor_2400A0_dmem
#define HIVE_ADDR_sp_isp_stop_req 0x2B8C
#define HIVE_SIZE_sp_isp_stop_req 4

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_init_dmem_data (void);
void sh_css_dump_sp_init_dmem_data (void)
{
  static struct ia_css_sp_init_dmem_cfg sp_init_dmem_data;
  assert(sizeof(sp_init_dmem_data) ==
         HIVE_SIZE_sp_init_dmem_data);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_init_dmem_data),
    (char*)&sp_init_dmem_data,
    sizeof(sp_init_dmem_data));
  sh_css_print("sp_init_dmem_data.done ="
    "                                  0x%x\n",
    sp_init_dmem_data.done);
  sh_css_print("sp_init_dmem_data.ddr_code_addr ="
    "                         0x%x\n",
    sp_init_dmem_data.ddr_code_addr);
  sh_css_print("sp_init_dmem_data.ddr_data_addr ="
    "                         0x%x\n",
    sp_init_dmem_data.ddr_data_addr);
  sh_css_print("sp_init_dmem_data.pmem_text_addr ="
    "                        0x%x\n",
    sp_init_dmem_data.pmem_text_addr);
  sh_css_print("sp_init_dmem_data.dmem_data_addr ="
    "                        0x%x\n",
    sp_init_dmem_data.dmem_data_addr);
  sh_css_print("sp_init_dmem_data.dmem_bss_addr ="
    "                         0x%x\n",
    sp_init_dmem_data.dmem_bss_addr);
  sh_css_print("sp_init_dmem_data.text_size ="
    "                             0x%x\n",
    sp_init_dmem_data.text_size);
  sh_css_print("sp_init_dmem_data.data_size ="
    "                             0x%x\n",
    sp_init_dmem_data.data_size);
  sh_css_print("sp_init_dmem_data.bss_size ="
    "                              0x%x\n",
    sp_init_dmem_data.bss_size);
}

extern void sh_css_dump_xmem_bin_addr (void);
void sh_css_dump_xmem_bin_addr (void)
{
  hrt_vaddress xmem_bin_addr;
  assert(sizeof(xmem_bin_addr) ==
         HIVE_SIZE_xmem_bin_addr);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(xmem_bin_addr),
    (char*)&xmem_bin_addr,
    sizeof(xmem_bin_addr));
  sh_css_print("xmem_bin_addr ="
    "                                           0x%x\n",
    xmem_bin_addr);
}

extern void sh_css_dump_sp_vf_downscale_bits (void);
void sh_css_dump_sp_vf_downscale_bits (void)
{
  unsigned int sp_vf_downscale_bits;
  assert(sizeof(sp_vf_downscale_bits) ==
         HIVE_SIZE_sp_vf_downscale_bits);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_vf_downscale_bits),
    (char*)&sp_vf_downscale_bits,
    sizeof(sp_vf_downscale_bits));
  sh_css_print("sp_vf_downscale_bits ="
    "                                    0x%x\n",
    sp_vf_downscale_bits);
}

extern void sh_css_dump_sp_per_frame_data (void);
void sh_css_dump_sp_per_frame_data (void)
{
  static struct sh_css_sp_per_frame_data sp_per_frame_data;
  assert(sizeof(sp_per_frame_data) ==
         HIVE_SIZE_sp_per_frame_data);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_per_frame_data),
    (char*)&sp_per_frame_data,
    sizeof(sp_per_frame_data));
  sh_css_print("sp_per_frame_data.sp_group_addr ="
    "                         0x%x\n",
    sp_per_frame_data.sp_group_addr);
}

extern void sh_css_dump_sp_group (void);
void sh_css_dump_sp_group (void)
{
  static struct sh_css_sp_group sp_group;
  assert(sizeof(sp_group) ==
         HIVE_SIZE_sp_group);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_group),
    (char*)&sp_group,
    sizeof(sp_group));
  sh_css_print("sp_group.config.no_isp_sync ="
    "                             0x%x\n",
    sp_group.config.no_isp_sync);
  sh_css_print("sp_group.config.input_formatter.a_changed ="
    "               0x%x\n",
    sp_group.config.input_formatter.a_changed);
  sh_css_print("sp_group.config.input_formatter.b_changed ="
    "               0x%x\n",
    sp_group.config.input_formatter.b_changed);
  sh_css_print("sp_group.config.input_formatter.isp_2ppc ="
    "                0x%x\n",
    sp_group.config.input_formatter.isp_2ppc);
  sh_css_print("sp_group.config.input_formatter.set[0].stream_format ="
    "    0x%x\n",
    sp_group.config.input_formatter.set[0].stream_format);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.start_line);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.start_column);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[0].config_a.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_a.block_no_reqs);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.start_line);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.start_column);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[0].config_b.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[0].config_b.block_no_reqs);
  sh_css_print("sp_group.config.input_formatter.set[1].stream_format ="
    "    0x%x\n",
    sp_group.config.input_formatter.set[1].stream_format);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.start_line);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.start_column);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[1].config_a.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_a.block_no_reqs);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.start_line);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.start_column);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[1].config_b.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[1].config_b.block_no_reqs);
  sh_css_print("sp_group.config.input_formatter.set[2].stream_format ="
    "    0x%x\n",
    sp_group.config.input_formatter.set[2].stream_format);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.start_line);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.start_column);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[2].config_a.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_a.block_no_reqs);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.start_line ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.start_line);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.start_column ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.start_column);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.left_padding ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.left_padding);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.cropped_height ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.cropped_height);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.cropped_width ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.cropped_width);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.deinterleaving ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.deinterleaving);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.buf_vecs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.buf_vecs);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.buf_start_index ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.buf_start_index);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.buf_increment ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.buf_increment);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.buf_eol_offset ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.buf_eol_offset);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.is_yuv420_format ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.is_yuv420_format);
  sh_css_print("sp_group.config.input_formatter.set[2].config_b.block_no_reqs ="
    "0x%x\n",
    sp_group.config.input_formatter.set[2].config_b.block_no_reqs);
  sh_css_print("sp_group.config.sync_gen.width ="
    "                          0x%x\n",
    sp_group.config.sync_gen.width);
  sh_css_print("sp_group.config.sync_gen.height ="
    "                         0x%x\n",
    sp_group.config.sync_gen.height);
  sh_css_print("sp_group.config.sync_gen.hblank_cycles ="
    "                  0x%x\n",
    sp_group.config.sync_gen.hblank_cycles);
  sh_css_print("sp_group.config.sync_gen.vblank_cycles ="
    "                  0x%x\n",
    sp_group.config.sync_gen.vblank_cycles);
  sh_css_print("sp_group.config.tpg.x_mask ="
    "                              0x%x\n",
    sp_group.config.tpg.x_mask);
  sh_css_print("sp_group.config.tpg.y_mask ="
    "                              0x%x\n",
    sp_group.config.tpg.y_mask);
  sh_css_print("sp_group.config.tpg.x_delta ="
    "                             0x%x\n",
    sp_group.config.tpg.x_delta);
  sh_css_print("sp_group.config.tpg.y_delta ="
    "                             0x%x\n",
    sp_group.config.tpg.y_delta);
  sh_css_print("sp_group.config.tpg.xy_mask ="
    "                             0x%x\n",
    sp_group.config.tpg.xy_mask);
  sh_css_print("sp_group.config.tpg.sync_gen_cfg.width ="
    "                  0x%x\n",
    sp_group.config.tpg.sync_gen_cfg.width);
  sh_css_print("sp_group.config.tpg.sync_gen_cfg.height ="
    "                 0x%x\n",
    sp_group.config.tpg.sync_gen_cfg.height);
  sh_css_print("sp_group.config.tpg.sync_gen_cfg.hblank_cycles ="
    "          0x%x\n",
    sp_group.config.tpg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.config.tpg.sync_gen_cfg.vblank_cycles ="
    "          0x%x\n",
    sp_group.config.tpg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.config.prbs.seed ="
    "                               0x%x\n",
    sp_group.config.prbs.seed);
  sh_css_print("sp_group.config.prbs.sync_gen_cfg.width ="
    "                 0x%x\n",
    sp_group.config.prbs.sync_gen_cfg.width);
  sh_css_print("sp_group.config.prbs.sync_gen_cfg.height ="
    "                0x%x\n",
    sp_group.config.prbs.sync_gen_cfg.height);
  sh_css_print("sp_group.config.prbs.sync_gen_cfg.hblank_cycles ="
    "         0x%x\n",
    sp_group.config.prbs.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.config.prbs.sync_gen_cfg.vblank_cycles ="
    "         0x%x\n",
    sp_group.config.prbs.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.config.input_circuit.no_side_band ="
    "              0x%x\n",
    sp_group.config.input_circuit.no_side_band);
  sh_css_print("sp_group.config.input_circuit.fmt_type ="
    "                  0x%x\n",
    sp_group.config.input_circuit.fmt_type);
  sh_css_print("sp_group.config.input_circuit.ch_id ="
    "                     0x%x\n",
    sp_group.config.input_circuit.ch_id);
  sh_css_print("sp_group.config.input_circuit.input_mode ="
    "                0x%x\n",
    sp_group.config.input_circuit.input_mode);
  sh_css_print("sp_group.config.input_circuit_cfg_changed ="
    "               0x%x\n",
    sp_group.config.input_circuit_cfg_changed);
  sh_css_print("sp_group.config.mipi_sizes_for_check[0][0] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[0][0]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[0][1] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[0][1]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[0][2] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[0][2]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[1][0] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[1][0]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[1][1] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[1][1]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[1][2] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[1][2]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[2][0] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[2][0]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[2][1] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[2][1]);
  sh_css_print("sp_group.config.mipi_sizes_for_check[2][2] ="
    "              0x%x\n",
    sp_group.config.mipi_sizes_for_check[2][2]);
  sh_css_print("sp_group.pipe[0].pipe_id ="
    "                                0x%x\n",
    sp_group.pipe[0].pipe_id);
  sh_css_print("sp_group.pipe[0].pipe_num ="
    "                               0x%x\n",
    sp_group.pipe[0].pipe_num);
  sh_css_print("sp_group.pipe[0].thread_id ="
    "                              0x%x\n",
    sp_group.pipe[0].thread_id);
  sh_css_print("sp_group.pipe[0].pipe_config ="
    "                            0x%x\n",
    sp_group.pipe[0].pipe_config);
  sh_css_print("sp_group.pipe[0].inout_port_config ="
    "                      0x%x\n",
    sp_group.pipe[0].inout_port_config);
  sh_css_print("sp_group.pipe[0].input_needs_raw_binning ="
    "                0x%x\n",
    sp_group.pipe[0].input_needs_raw_binning);
  sh_css_print("sp_group.pipe[0].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[0].dvs_frame_delay);
  sh_css_print("sp_group.pipe[0].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[0].input_system_mode);
  sh_css_print("sp_group.pipe[0].port_id ="
    "                                0x%x\n",
    sp_group.pipe[0].port_id);
  sh_css_print("sp_group.pipe[0].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[0].num_stages);
  sh_css_print("sp_group.pipe[0].running ="
    "                                0x%x\n",
    sp_group.pipe[0].running);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[0] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[0]);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[1] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[1]);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[2] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[2]);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[3] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[3]);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[4] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[4]);
  sh_css_print("sp_group.pipe[0].sp_stage_addr[5] ="
    "                       0x%x\n",
    sp_group.pipe[0].sp_stage_addr[5]);
  sh_css_print("sp_group.pipe[0].stage ="
    "                                    %p\n",
    sp_group.pipe[0].stage);
  sh_css_print("sp_group.pipe[0].num_execs ="
    "                              0x%x\n",
    sp_group.pipe[0].num_execs);
  sh_css_print("sp_group.pipe[0].copy.bin.bytes_available ="
    "               0x%x\n",
    sp_group.pipe[0].copy.bin.bytes_available);
  sh_css_print("sp_group.pipe[0].copy.raw.height ="
    "                        0x%x\n",
    sp_group.pipe[0].copy.raw.height);
  sh_css_print("sp_group.pipe[0].copy.raw.width ="
    "                         0x%x\n",
    sp_group.pipe[0].copy.raw.width);
  sh_css_print("sp_group.pipe[0].copy.raw.padded_width ="
    "                  0x%x\n",
    sp_group.pipe[0].copy.raw.padded_width);
  sh_css_print("sp_group.pipe[0].copy.raw.max_input_width ="
    "               0x%x\n",
    sp_group.pipe[0].copy.raw.max_input_width);
  sh_css_print("sp_group.pipe[0].copy.raw.raw_bit_depth ="
    "                 0x%x\n",
    sp_group.pipe[0].copy.raw.raw_bit_depth);
  sh_css_print("sp_group.pipe[1].pipe_id ="
    "                                0x%x\n",
    sp_group.pipe[1].pipe_id);
  sh_css_print("sp_group.pipe[1].pipe_num ="
    "                               0x%x\n",
    sp_group.pipe[1].pipe_num);
  sh_css_print("sp_group.pipe[1].thread_id ="
    "                              0x%x\n",
    sp_group.pipe[1].thread_id);
  sh_css_print("sp_group.pipe[1].pipe_config ="
    "                            0x%x\n",
    sp_group.pipe[1].pipe_config);
  sh_css_print("sp_group.pipe[1].inout_port_config ="
    "                      0x%x\n",
    sp_group.pipe[1].inout_port_config);
  sh_css_print("sp_group.pipe[1].input_needs_raw_binning ="
    "                0x%x\n",
    sp_group.pipe[1].input_needs_raw_binning);
  sh_css_print("sp_group.pipe[1].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[1].dvs_frame_delay);
  sh_css_print("sp_group.pipe[1].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[1].input_system_mode);
  sh_css_print("sp_group.pipe[1].port_id ="
    "                                0x%x\n",
    sp_group.pipe[1].port_id);
  sh_css_print("sp_group.pipe[1].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[1].num_stages);
  sh_css_print("sp_group.pipe[1].running ="
    "                                0x%x\n",
    sp_group.pipe[1].running);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[0] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[0]);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[1] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[1]);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[2] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[2]);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[3] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[3]);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[4] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[4]);
  sh_css_print("sp_group.pipe[1].sp_stage_addr[5] ="
    "                       0x%x\n",
    sp_group.pipe[1].sp_stage_addr[5]);
  sh_css_print("sp_group.pipe[1].stage ="
    "                                    %p\n",
    sp_group.pipe[1].stage);
  sh_css_print("sp_group.pipe[1].num_execs ="
    "                              0x%x\n",
    sp_group.pipe[1].num_execs);
  sh_css_print("sp_group.pipe[1].copy.bin.bytes_available ="
    "               0x%x\n",
    sp_group.pipe[1].copy.bin.bytes_available);
  sh_css_print("sp_group.pipe[1].copy.raw.height ="
    "                        0x%x\n",
    sp_group.pipe[1].copy.raw.height);
  sh_css_print("sp_group.pipe[1].copy.raw.width ="
    "                         0x%x\n",
    sp_group.pipe[1].copy.raw.width);
  sh_css_print("sp_group.pipe[1].copy.raw.padded_width ="
    "                  0x%x\n",
    sp_group.pipe[1].copy.raw.padded_width);
  sh_css_print("sp_group.pipe[1].copy.raw.max_input_width ="
    "               0x%x\n",
    sp_group.pipe[1].copy.raw.max_input_width);
  sh_css_print("sp_group.pipe[1].copy.raw.raw_bit_depth ="
    "                 0x%x\n",
    sp_group.pipe[1].copy.raw.raw_bit_depth);
  sh_css_print("sp_group.pipe[2].pipe_id ="
    "                                0x%x\n",
    sp_group.pipe[2].pipe_id);
  sh_css_print("sp_group.pipe[2].pipe_num ="
    "                               0x%x\n",
    sp_group.pipe[2].pipe_num);
  sh_css_print("sp_group.pipe[2].thread_id ="
    "                              0x%x\n",
    sp_group.pipe[2].thread_id);
  sh_css_print("sp_group.pipe[2].pipe_config ="
    "                            0x%x\n",
    sp_group.pipe[2].pipe_config);
  sh_css_print("sp_group.pipe[2].inout_port_config ="
    "                      0x%x\n",
    sp_group.pipe[2].inout_port_config);
  sh_css_print("sp_group.pipe[2].input_needs_raw_binning ="
    "                0x%x\n",
    sp_group.pipe[2].input_needs_raw_binning);
  sh_css_print("sp_group.pipe[2].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[2].dvs_frame_delay);
  sh_css_print("sp_group.pipe[2].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[2].input_system_mode);
  sh_css_print("sp_group.pipe[2].port_id ="
    "                                0x%x\n",
    sp_group.pipe[2].port_id);
  sh_css_print("sp_group.pipe[2].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[2].num_stages);
  sh_css_print("sp_group.pipe[2].running ="
    "                                0x%x\n",
    sp_group.pipe[2].running);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[0] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[0]);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[1] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[1]);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[2] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[2]);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[3] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[3]);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[4] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[4]);
  sh_css_print("sp_group.pipe[2].sp_stage_addr[5] ="
    "                       0x%x\n",
    sp_group.pipe[2].sp_stage_addr[5]);
  sh_css_print("sp_group.pipe[2].stage ="
    "                                    %p\n",
    sp_group.pipe[2].stage);
  sh_css_print("sp_group.pipe[2].num_execs ="
    "                              0x%x\n",
    sp_group.pipe[2].num_execs);
  sh_css_print("sp_group.pipe[2].copy.bin.bytes_available ="
    "               0x%x\n",
    sp_group.pipe[2].copy.bin.bytes_available);
  sh_css_print("sp_group.pipe[2].copy.raw.height ="
    "                        0x%x\n",
    sp_group.pipe[2].copy.raw.height);
  sh_css_print("sp_group.pipe[2].copy.raw.width ="
    "                         0x%x\n",
    sp_group.pipe[2].copy.raw.width);
  sh_css_print("sp_group.pipe[2].copy.raw.padded_width ="
    "                  0x%x\n",
    sp_group.pipe[2].copy.raw.padded_width);
  sh_css_print("sp_group.pipe[2].copy.raw.max_input_width ="
    "               0x%x\n",
    sp_group.pipe[2].copy.raw.max_input_width);
  sh_css_print("sp_group.pipe[2].copy.raw.raw_bit_depth ="
    "                 0x%x\n",
    sp_group.pipe[2].copy.raw.raw_bit_depth);
  sh_css_print("sp_group.pipe[3].pipe_id ="
    "                                0x%x\n",
    sp_group.pipe[3].pipe_id);
  sh_css_print("sp_group.pipe[3].pipe_num ="
    "                               0x%x\n",
    sp_group.pipe[3].pipe_num);
  sh_css_print("sp_group.pipe[3].thread_id ="
    "                              0x%x\n",
    sp_group.pipe[3].thread_id);
  sh_css_print("sp_group.pipe[3].pipe_config ="
    "                            0x%x\n",
    sp_group.pipe[3].pipe_config);
  sh_css_print("sp_group.pipe[3].inout_port_config ="
    "                      0x%x\n",
    sp_group.pipe[3].inout_port_config);
  sh_css_print("sp_group.pipe[3].input_needs_raw_binning ="
    "                0x%x\n",
    sp_group.pipe[3].input_needs_raw_binning);
  sh_css_print("sp_group.pipe[3].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[3].dvs_frame_delay);
  sh_css_print("sp_group.pipe[3].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[3].input_system_mode);
  sh_css_print("sp_group.pipe[3].port_id ="
    "                                0x%x\n",
    sp_group.pipe[3].port_id);
  sh_css_print("sp_group.pipe[3].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[3].num_stages);
  sh_css_print("sp_group.pipe[3].running ="
    "                                0x%x\n",
    sp_group.pipe[3].running);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[0] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[0]);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[1] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[1]);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[2] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[2]);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[3] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[3]);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[4] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[4]);
  sh_css_print("sp_group.pipe[3].sp_stage_addr[5] ="
    "                       0x%x\n",
    sp_group.pipe[3].sp_stage_addr[5]);
  sh_css_print("sp_group.pipe[3].stage ="
    "                                    %p\n",
    sp_group.pipe[3].stage);
  sh_css_print("sp_group.pipe[3].num_execs ="
    "                              0x%x\n",
    sp_group.pipe[3].num_execs);
  sh_css_print("sp_group.pipe[3].copy.bin.bytes_available ="
    "               0x%x\n",
    sp_group.pipe[3].copy.bin.bytes_available);
  sh_css_print("sp_group.pipe[3].copy.raw.height ="
    "                        0x%x\n",
    sp_group.pipe[3].copy.raw.height);
  sh_css_print("sp_group.pipe[3].copy.raw.width ="
    "                         0x%x\n",
    sp_group.pipe[3].copy.raw.width);
  sh_css_print("sp_group.pipe[3].copy.raw.padded_width ="
    "                  0x%x\n",
    sp_group.pipe[3].copy.raw.padded_width);
  sh_css_print("sp_group.pipe[3].copy.raw.max_input_width ="
    "               0x%x\n",
    sp_group.pipe[3].copy.raw.max_input_width);
  sh_css_print("sp_group.pipe[3].copy.raw.raw_bit_depth ="
    "                 0x%x\n",
    sp_group.pipe[3].copy.raw.raw_bit_depth);
  sh_css_print("sp_group.debug.dma_sw_reg ="
    "                               0x%x\n",
    sp_group.debug.dma_sw_reg);
}

extern void sh_css_dump_sp_output (void);
void sh_css_dump_sp_output (void)
{
  static struct sh_css_sp_output sp_output;
  assert(sizeof(sp_output) ==
         HIVE_SIZE_sp_output);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_output),
    (char*)&sp_output,
    sizeof(sp_output));
  sh_css_print("sp_output.bin_copy_bytes_copied ="
    "                         0x%x\n",
    sp_output.bin_copy_bytes_copied);
  sh_css_print("sp_output.sw_interrupt_value[0] ="
    "                         0x%x\n",
    sp_output.sw_interrupt_value[0]);
  sh_css_print("sp_output.sw_interrupt_value[1] ="
    "                         0x%x\n",
    sp_output.sw_interrupt_value[1]);
  sh_css_print("sp_output.sw_interrupt_value[2] ="
    "                         0x%x\n",
    sp_output.sw_interrupt_value[2]);
}

extern void sh_css_dump_host_sp_com (void);
void sh_css_dump_host_sp_com (void)
{
  static volatile struct host_sp_communication host_sp_com;
  assert(sizeof(host_sp_com) ==
         HIVE_SIZE_host_sp_com);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(host_sp_com),
    (char*)&host_sp_com,
    sizeof(host_sp_com));
  sh_css_print("host_sp_com.host2sp_command ="
    "                             0x%x\n",
    host_sp_com.host2sp_command);
  sh_css_print("host_sp_com.host2sp_offline_frames[0] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[0]);
  sh_css_print("host_sp_com.host2sp_offline_frames[1] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[1]);
  sh_css_print("host_sp_com.host2sp_offline_frames[2] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[2]);
  sh_css_print("host_sp_com.host2sp_offline_frames[3] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[3]);
  sh_css_print("host_sp_com.host2sp_offline_frames[4] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[4]);
  sh_css_print("host_sp_com.host2sp_offline_frames[5] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[5]);
  sh_css_print("host_sp_com.host2sp_offline_frames[6] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[6]);
  sh_css_print("host_sp_com.host2sp_offline_frames[7] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[7]);
  sh_css_print("host_sp_com.host2sp_offline_frames[8] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[8]);
  sh_css_print("host_sp_com.host2sp_offline_frames[9] ="
    "                   0x%x\n",
    host_sp_com.host2sp_offline_frames[9]);
  sh_css_print("host_sp_com.host2sp_mipi_frames[0] ="
    "                      0x%x\n",
    host_sp_com.host2sp_mipi_frames[0]);
  sh_css_print("host_sp_com.host2sp_mipi_frames[1] ="
    "                      0x%x\n",
    host_sp_com.host2sp_mipi_frames[1]);
  sh_css_print("host_sp_com.host2sp_mipi_frames[2] ="
    "                      0x%x\n",
    host_sp_com.host2sp_mipi_frames[2]);
  sh_css_print("host_sp_com.host2sp_mipi_frames[3] ="
    "                      0x%x\n",
    host_sp_com.host2sp_mipi_frames[3]);
  sh_css_print("host_sp_com.host2sp_cont_avail_num_raw_frames ="
    "           0x%x\n",
    host_sp_com.host2sp_cont_avail_num_raw_frames);
  sh_css_print("host_sp_com.host2sp_cont_extra_num_raw_frames ="
    "           0x%x\n",
    host_sp_com.host2sp_cont_extra_num_raw_frames);
  sh_css_print("host_sp_com.host2sp_cont_target_num_raw_frames ="
    "          0x%x\n",
    host_sp_com.host2sp_cont_target_num_raw_frames);
  sh_css_print("host_sp_com.host2sp_cont_num_mipi_frames ="
    "                0x%x\n",
    host_sp_com.host2sp_cont_num_mipi_frames);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[0].or_mask ="
    "           0x%x\n",
    host_sp_com.host2sp_event_irq_mask[0].or_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[0].and_mask ="
    "          0x%x\n",
    host_sp_com.host2sp_event_irq_mask[0].and_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[1].or_mask ="
    "           0x%x\n",
    host_sp_com.host2sp_event_irq_mask[1].or_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[1].and_mask ="
    "          0x%x\n",
    host_sp_com.host2sp_event_irq_mask[1].and_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[2].or_mask ="
    "           0x%x\n",
    host_sp_com.host2sp_event_irq_mask[2].or_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[2].and_mask ="
    "          0x%x\n",
    host_sp_com.host2sp_event_irq_mask[2].and_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[3].or_mask ="
    "           0x%x\n",
    host_sp_com.host2sp_event_irq_mask[3].or_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[3].and_mask ="
    "          0x%x\n",
    host_sp_com.host2sp_event_irq_mask[3].and_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[4].or_mask ="
    "           0x%x\n",
    host_sp_com.host2sp_event_irq_mask[4].or_mask);
  sh_css_print("host_sp_com.host2sp_event_irq_mask[4].and_mask ="
    "          0x%x\n",
    host_sp_com.host2sp_event_irq_mask[4].and_mask);
}

extern void sh_css_dump_mem_map (void);
void sh_css_dump_mem_map (void)
{
  static volatile struct sh_css_ddr_address_map mem_map;
  assert(sizeof(mem_map) ==
         HIVE_SIZE_mem_map);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(mem_map),
    (char*)&mem_map,
    sizeof(mem_map));
  sh_css_print("mem_map.isp_param ="
    "                                       0x%x\n",
    mem_map.isp_param);
  sh_css_print("mem_map.isp_mem_param[0][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][0]);
  sh_css_print("mem_map.isp_mem_param[0][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][1]);
  sh_css_print("mem_map.isp_mem_param[0][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][2]);
  sh_css_print("mem_map.isp_mem_param[0][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][3]);
  sh_css_print("mem_map.isp_mem_param[0][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][4]);
  sh_css_print("mem_map.isp_mem_param[0][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][5]);
  sh_css_print("mem_map.isp_mem_param[0][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[0][6]);
  sh_css_print("mem_map.isp_mem_param[1][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][0]);
  sh_css_print("mem_map.isp_mem_param[1][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][1]);
  sh_css_print("mem_map.isp_mem_param[1][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][2]);
  sh_css_print("mem_map.isp_mem_param[1][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][3]);
  sh_css_print("mem_map.isp_mem_param[1][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][4]);
  sh_css_print("mem_map.isp_mem_param[1][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][5]);
  sh_css_print("mem_map.isp_mem_param[1][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[1][6]);
  sh_css_print("mem_map.isp_mem_param[2][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][0]);
  sh_css_print("mem_map.isp_mem_param[2][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][1]);
  sh_css_print("mem_map.isp_mem_param[2][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][2]);
  sh_css_print("mem_map.isp_mem_param[2][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][3]);
  sh_css_print("mem_map.isp_mem_param[2][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][4]);
  sh_css_print("mem_map.isp_mem_param[2][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][5]);
  sh_css_print("mem_map.isp_mem_param[2][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[2][6]);
  sh_css_print("mem_map.isp_mem_param[3][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][0]);
  sh_css_print("mem_map.isp_mem_param[3][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][1]);
  sh_css_print("mem_map.isp_mem_param[3][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][2]);
  sh_css_print("mem_map.isp_mem_param[3][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][3]);
  sh_css_print("mem_map.isp_mem_param[3][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][4]);
  sh_css_print("mem_map.isp_mem_param[3][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][5]);
  sh_css_print("mem_map.isp_mem_param[3][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[3][6]);
  sh_css_print("mem_map.isp_mem_param[4][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][0]);
  sh_css_print("mem_map.isp_mem_param[4][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][1]);
  sh_css_print("mem_map.isp_mem_param[4][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][2]);
  sh_css_print("mem_map.isp_mem_param[4][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][3]);
  sh_css_print("mem_map.isp_mem_param[4][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][4]);
  sh_css_print("mem_map.isp_mem_param[4][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][5]);
  sh_css_print("mem_map.isp_mem_param[4][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[4][6]);
  sh_css_print("mem_map.isp_mem_param[5][0] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][0]);
  sh_css_print("mem_map.isp_mem_param[5][1] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][1]);
  sh_css_print("mem_map.isp_mem_param[5][2] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][2]);
  sh_css_print("mem_map.isp_mem_param[5][3] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][3]);
  sh_css_print("mem_map.isp_mem_param[5][4] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][4]);
  sh_css_print("mem_map.isp_mem_param[5][5] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][5]);
  sh_css_print("mem_map.isp_mem_param[5][6] ="
    "                             0x%x\n",
    mem_map.isp_mem_param[5][6]);
  sh_css_print("mem_map.macc_tbl ="
    "                                        0x%x\n",
    mem_map.macc_tbl);
  sh_css_print("mem_map.fpn_tbl ="
    "                                         0x%x\n",
    mem_map.fpn_tbl);
  sh_css_print("mem_map.sc_tbl ="
    "                                          0x%x\n",
    mem_map.sc_tbl);
  sh_css_print("mem_map.sdis_hor_coef ="
    "                                   0x%x\n",
    mem_map.sdis_hor_coef);
  sh_css_print("mem_map.sdis_ver_coef ="
    "                                   0x%x\n",
    mem_map.sdis_ver_coef);
  sh_css_print("mem_map.tetra_r_x ="
    "                                       0x%x\n",
    mem_map.tetra_r_x);
  sh_css_print("mem_map.tetra_r_y ="
    "                                       0x%x\n",
    mem_map.tetra_r_y);
  sh_css_print("mem_map.tetra_gr_x ="
    "                                      0x%x\n",
    mem_map.tetra_gr_x);
  sh_css_print("mem_map.tetra_gr_y ="
    "                                      0x%x\n",
    mem_map.tetra_gr_y);
  sh_css_print("mem_map.tetra_gb_x ="
    "                                      0x%x\n",
    mem_map.tetra_gb_x);
  sh_css_print("mem_map.tetra_gb_y ="
    "                                      0x%x\n",
    mem_map.tetra_gb_y);
  sh_css_print("mem_map.tetra_b_x ="
    "                                       0x%x\n",
    mem_map.tetra_b_x);
  sh_css_print("mem_map.tetra_b_y ="
    "                                       0x%x\n",
    mem_map.tetra_b_y);
  sh_css_print("mem_map.tetra_ratb_x ="
    "                                    0x%x\n",
    mem_map.tetra_ratb_x);
  sh_css_print("mem_map.tetra_ratb_y ="
    "                                    0x%x\n",
    mem_map.tetra_ratb_y);
  sh_css_print("mem_map.tetra_batr_x ="
    "                                    0x%x\n",
    mem_map.tetra_batr_x);
  sh_css_print("mem_map.tetra_batr_y ="
    "                                    0x%x\n",
    mem_map.tetra_batr_y);
  sh_css_print("mem_map.dvs_6axis_params_y ="
    "                              0x%x\n",
    mem_map.dvs_6axis_params_y);
  sh_css_print("mem_map.anr_thres ="
    "                                       0x%x\n",
    mem_map.anr_thres);
}

extern void sh_css_dump_sp_sw_state (void);
void sh_css_dump_sp_sw_state (void)
{
  volatile int sp_sw_state;
  assert(sizeof(sp_sw_state) ==
         HIVE_SIZE_sp_sw_state);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_sw_state),
    (char*)&sp_sw_state,
    sizeof(sp_sw_state));
  sh_css_print("sp_sw_state ="
    "                                             0x%x\n",
    sp_sw_state);
}

extern void sh_css_dump_host_sp_queues_initialized (void);
void sh_css_dump_host_sp_queues_initialized (void)
{
  volatile int host_sp_queues_initialized;
  assert(sizeof(host_sp_queues_initialized) ==
         HIVE_SIZE_host_sp_queues_initialized);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(host_sp_queues_initialized),
    (char*)&host_sp_queues_initialized,
    sizeof(host_sp_queues_initialized));
  sh_css_print("host_sp_queues_initialized ="
    "                              0x%x\n",
    host_sp_queues_initialized);
}

extern void sh_css_dump_sp_sleep_mode (void);
void sh_css_dump_sp_sleep_mode (void)
{
  volatile int sp_sleep_mode;
  assert(sizeof(sp_sleep_mode) ==
         HIVE_SIZE_sp_sleep_mode);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_sleep_mode),
    (char*)&sp_sleep_mode,
    sizeof(sp_sleep_mode));
  sh_css_print("sp_sleep_mode ="
    "                                           0x%x\n",
    sp_sleep_mode);
}

extern void sh_css_dump_sp_isp_input_stream_format (void);
void sh_css_dump_sp_isp_input_stream_format (void)
{
  static enum sh_stream_format{ sh_stream_format_yuv420_legacy, sh_stream_format_yuv420, sh_stream_format_yuv422, sh_stream_format_rgb, sh_stream_format_raw, sh_stream_format_binary} sp_isp_input_stream_format[4];
  assert(sizeof(sp_isp_input_stream_format) ==
         HIVE_SIZE_sp_isp_input_stream_format);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_isp_input_stream_format),
    (char*)&sp_isp_input_stream_format,
    sizeof(sp_isp_input_stream_format));
  sh_css_print("sp_isp_input_stream_format[0] ="
    "                           0x%x\n",
    sp_isp_input_stream_format[0]);
  sh_css_print("sp_isp_input_stream_format[1] ="
    "                           0x%x\n",
    sp_isp_input_stream_format[1]);
  sh_css_print("sp_isp_input_stream_format[2] ="
    "                           0x%x\n",
    sp_isp_input_stream_format[2]);
  sh_css_print("sp_isp_input_stream_format[3] ="
    "                           0x%x\n",
    sp_isp_input_stream_format[3]);
}

extern void sh_css_dump_sp_obarea_start_bq (void);
void sh_css_dump_sp_obarea_start_bq (void)
{
  unsigned int sp_obarea_start_bq;
  assert(sizeof(sp_obarea_start_bq) ==
         HIVE_SIZE_sp_obarea_start_bq);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_obarea_start_bq),
    (char*)&sp_obarea_start_bq,
    sizeof(sp_obarea_start_bq));
  sh_css_print("sp_obarea_start_bq ="
    "                                      0x%x\n",
    sp_obarea_start_bq);
}

extern void sh_css_dump_sp_obarea_length_bq (void);
void sh_css_dump_sp_obarea_length_bq (void)
{
  unsigned int sp_obarea_length_bq;
  assert(sizeof(sp_obarea_length_bq) ==
         HIVE_SIZE_sp_obarea_length_bq);
  sp_dmem_load(SP0_ID, (unsigned int)sp_address_of(sp_obarea_length_bq),
    (char*)&sp_obarea_length_bq,
    sizeof(sp_obarea_length_bq));
  sh_css_print("sp_obarea_length_bq ="
    "                                     0x%x\n",
    sp_obarea_length_bq);
}

extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
  sh_css_dump_sp_init_dmem_data();
  sh_css_dump_xmem_bin_addr();
  sh_css_dump_sp_vf_downscale_bits();
  sh_css_dump_sp_per_frame_data();
  sh_css_dump_sp_group();
  sh_css_dump_sp_output();
  sh_css_dump_host_sp_com();
  sh_css_dump_mem_map();
  sh_css_dump_sp_sw_state();
  sh_css_dump_host_sp_queues_initialized();
  sh_css_dump_sp_sleep_mode();
  sh_css_dump_sp_isp_input_stream_format();
  sh_css_dump_sp_obarea_start_bq();
  sh_css_dump_sp_obarea_length_bq();
}
