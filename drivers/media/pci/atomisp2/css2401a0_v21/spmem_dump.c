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
#define HIVE_MEM_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_input_line 0x5FFC
#define HIVE_SIZE_isp_vectors_per_input_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_input_line 0x5FFC
#define HIVE_SIZE_sp_isp_vectors_per_input_line 4

/* function longjmp: 4D27 */

/* function ia_css_dmaproxy_sp_set_addr_B: 281B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_id 0x5358
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_id 0x5358
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_id 4

/* function debug_buffer_set_ddr_addr: D2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_mipi
#define HIVE_MEM_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_mipi 0xF54
#define HIVE_SIZE_vbuf_mipi 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_mipi 0xF54
#define HIVE_SIZE_sp_vbuf_mipi 4

/* function ia_css_event_sp_decode: 28C2 */

/* function setjmp: 4D30 */

/* function ia_css_ispctrl_sp_dma_configure_io: 3B65 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x6638
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_cp_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x6638
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 4

/* function __dmaproxy_sp_read_write_text: 288A */

/* function ia_css_dmaproxy_sp_wait_for_ack: 5362 */

/* function ia_css_tagger_buf_sp_pop_marked: 213C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stage 0x6038
#define HIVE_SIZE_isp_stage 552
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stage 0x6038
#define HIVE_SIZE_sp_isp_stage 552

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_raw
#define HIVE_MEM_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_raw 0xF50
#define HIVE_SIZE_vbuf_raw 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_raw 0xF50
#define HIVE_SIZE_sp_vbuf_raw 4

/* function ia_css_sp_bin_copy_func: 4829 */

/* function input_system_reset: FC0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_buffer_bufs 0x535C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_buffer_bufs 112
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 0x535C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 112

/* function sp_start_isp: 388 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_binary_group 0x6320
#define HIVE_SIZE_sp_binary_group 72
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x6320
#define HIVE_SIZE_sp_sp_binary_group 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x4400
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x4400
#define HIVE_SIZE_sp_sp_sw_state 4

/* function generate_sw_interrupt: 76B */

/* function ia_css_thread_sp_main: 1234 */

/* function ia_css_ispctrl_sp_init_internal_buffers: 2A68 */

/* function pixelgen_unit_test: C91 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x6000
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_vfout_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x6000
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 4

/* function ibuf_ctrl_sync: ABC */

/* function ia_css_tagger_sp_propagate_frame: 1BF3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x663C
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x663C
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_handles
#define HIVE_MEM_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_handles 0x66BC
#define HIVE_SIZE_vbuf_handles 400
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_handles 0x66BC
#define HIVE_SIZE_sp_vbuf_handles 400

/* function ia_css_sp_flash_register: 229C */

/* function ia_css_pipeline_sp_init: 16E1 */

/* function ia_css_tagger_sp_configure: 1B7F */

/* function ia_css_ispctrl_sp_end_binary: 28FD */

/* function ia_css_s3a_sp_get_buffer_ddr_addr: 25C1 */

/* function pixelgen_tpg_run: D34 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_is_pending_mask
#define HIVE_MEM_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_is_pending_mask 0x140
#define HIVE_SIZE_event_is_pending_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_is_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_is_pending_mask 0x140
#define HIVE_SIZE_sp_event_is_pending_mask 44

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cb_elems_frame
#define HIVE_MEM_sp_all_cb_elems_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cb_elems_frame 0x50CC
#define HIVE_SIZE_sp_all_cb_elems_frame 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_frame 0x50CC
#define HIVE_SIZE_sp_sp_all_cb_elems_frame 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_com 0x4404
#define HIVE_SIZE_host_sp_com 116
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_com 0x4404
#define HIVE_SIZE_sp_host_sp_com 116

/* function exec_image_pipe: 558 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x6660
#define HIVE_SIZE_sp_init_dmem_data 36
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x6660
#define HIVE_SIZE_sp_sp_init_dmem_data 36

/* function ia_css_tagger_buf_sp_is_marked: 2220 */

/* function ia_css_bufq_sp_init_buffer_queues: 230B */

/* function ia_css_pipeline_sp_stop: 16C4 */

/* function ia_css_tagger_sp_connect_pipes: 1FEA */

/* function is_isp_debug_buffer_full: 323 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_per_frame_data 0x4478
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x4478
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_rmgr_sp_vbuf_dequeue: 4B06 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_xmem_bin_addr
#define HIVE_MEM_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_xmem_bin_addr 0x447C
#define HIVE_SIZE_xmem_bin_addr 4
#else
#endif
#endif
#define HIVE_MEM_sp_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_sp_xmem_bin_addr 0x447C
#define HIVE_SIZE_sp_xmem_bin_addr 4

/* function ia_css_pipeline_sp_run: 14FB */

/* function memcpy: 4DD0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0xFAC
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0xFAC
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x6E8
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x6E8
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 2692 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_in_buf 0x6004
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_in_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_in_buf 0x6004
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_in_buf 4

/* function ia_css_uds_sp_scale_params: 452E */

/* function __divu: 4D4E */

/* function ia_css_thread_sp_get_state: 1163 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_stop
#define HIVE_MEM_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_stop 0x50DC
#define HIVE_SIZE_sem_for_cont_capt_stop 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_stop 0x50DC
#define HIVE_SIZE_sp_sem_for_cont_capt_stop 20

/* function thread_fiber_sp_main: 1312 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_pipe_thread
#define HIVE_MEM_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_pipe_thread 0x51FC
#define HIVE_SIZE_sp_isp_pipe_thread 256
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_pipe_thread 0x51FC
#define HIVE_SIZE_sp_sp_isp_pipe_thread 256

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_start_bq
#define HIVE_MEM_sp_obarea_start_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_obarea_start_bq 0x4480
#define HIVE_SIZE_sp_obarea_start_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_start_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_obarea_start_bq 0x4480
#define HIVE_SIZE_sp_sp_obarea_start_bq 4

/* function ia_css_parambuf_sp_handle_parameter_sets: 13B3 */

/* function ia_css_spctrl_sp_set_state: 483E */

/* function ia_css_thread_sem_sp_signal: 4FD1 */

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

/* function ia_css_virtual_isys_sp_isr_init: 48D1 */

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

/* function ia_css_rmgr_sp_init: 4A12 */

/* function ia_css_thread_sem_sp_init: 50A2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_is_isp_requested 0xFBC
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_sp_is_isp_requested 0xFBC
#define HIVE_SIZE_sp_is_isp_requested 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_frame
#define HIVE_MEM_sem_for_reading_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_frame 0x50F0
#define HIVE_SIZE_sem_for_reading_cb_frame 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_frame 0x50F0
#define HIVE_SIZE_sp_sem_for_reading_cb_frame 40

/* function ia_css_dmaproxy_sp_execute: 274B */

/* function csi_rx_backend_rst: 9FD */

/* function ia_css_pipeline_sp_has_stopped: 16BA */

/* function ia_css_circbuf_extract: FFD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0x6E4
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x6E4
#define HIVE_SIZE_sp_current_sp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_cur_co_fr_ct 0x6640
#define HIVE_SIZE_ia_css_rawcopy_sp_cur_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_cur_co_fr_ct 0x6640
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_cur_co_fr_ct 4

/* function ia_css_spctrl_sp_get_spid: 4845 */

/* function ia_css_dmaproxy_sp_read_byte_addr: 5390 */

/* function ia_css_rmgr_sp_uninit: 4A0B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack
#define HIVE_MEM_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_stack 0x548
#define HIVE_SIZE_sp_threads_stack 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_stack 0x548
#define HIVE_SIZE_sp_sp_threads_stack 20

/* function ia_css_circbuf_peek: FD9 */

/* function ia_css_parambuf_sp_wait_for_in_param: 1319 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cb_elems_param
#define HIVE_MEM_sp_all_cb_elems_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cb_elems_param 0x5118
#define HIVE_SIZE_sp_all_cb_elems_param 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_param 0x5118
#define HIVE_SIZE_sp_sp_all_cb_elems_param 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0x78C
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0x78C
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_param
#define HIVE_MEM_sem_for_reading_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_param 0x5128
#define HIVE_SIZE_sem_for_reading_cb_param 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_param 0x5128
#define HIVE_SIZE_sp_sem_for_reading_cb_param 40

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_start
#define HIVE_MEM_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_start 0x5150
#define HIVE_SIZE_sem_for_cont_capt_start 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_start 0x5150
#define HIVE_SIZE_sp_sem_for_cont_capt_start 20

/* function host2sp_event_queue_is_empty: 54A3 */

/* function ia_css_tagger_buf_sp_mark: 2271 */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 35AB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x53CC
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x53CC
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function debug_buffer_init_isp: D9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem
#define HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rmgr_sp_mipi_frame_sem 0x684C
#define HIVE_SIZE_ia_css_rmgr_sp_mipi_frame_sem 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rmgr_sp_mipi_frame_sem 0x684C
#define HIVE_SIZE_sp_ia_css_rmgr_sp_mipi_frame_sem 20

/* function ia_css_sp_raw_copy_func: 4830 */

/* function ia_css_rmgr_sp_refcount_dump: 4AE1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_pipe_threads
#define HIVE_MEM_sp_pipe_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipe_threads 0x538
#define HIVE_SIZE_sp_pipe_threads 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_pipe_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_pipe_threads 0x538
#define HIVE_SIZE_sp_sp_pipe_threads 16

/* function sp_event_proxy_func: 5C4 */

/* function ibuf_ctrl_run: AF0 */

/* function ia_css_thread_sp_yield: 4F4A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x5FF4
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x5FF4
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

/* function ia_css_thread_sp_fork: 11F0 */

/* function ia_css_tagger_sp_destroy: 1FF4 */

/* function ia_css_dmaproxy_sp_vmem_read: 26D4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ispctrl_sp_dma_configs
#define HIVE_MEM_ispctrl_sp_dma_configs scalar_processor_2400_dmem
#define HIVE_ADDR_ispctrl_sp_dma_configs 0x65E8
#define HIVE_SIZE_ispctrl_sp_dma_configs 80
#else
#endif
#endif
#define HIVE_MEM_sp_ispctrl_sp_dma_configs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ispctrl_sp_dma_configs 0x65E8
#define HIVE_SIZE_sp_ispctrl_sp_dma_configs 80

/* function initialize_sp_group: 568 */

/* function csi_rx_unit_test: 968 */

/* function ia_css_thread_sp_init: 121C */

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

/* function ibuf_ctrl_transfer: ACE */

/* function ia_css_dmaproxy_sp_read: 276C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_raw_copy_line_count 0xD70
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0xD70
#define HIVE_SIZE_sp_raw_copy_line_count 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_frame_cnt
#define HIVE_MEM_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_frame_cnt 0x534C
#define HIVE_SIZE_ia_css_flash_sp_frame_cnt 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_frame_cnt 0x534C
#define HIVE_SIZE_sp_ia_css_flash_sp_frame_cnt 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_can_send_token_mask
#define HIVE_MEM_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_can_send_token_mask 0x16C
#define HIVE_SIZE_event_can_send_token_mask 44
#else
#endif
#endif
#define HIVE_MEM_sp_event_can_send_token_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_can_send_token_mask 0x16C
#define HIVE_SIZE_sp_event_can_send_token_mask 44

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_isp_thread 0x6260
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_thread 0x6260
#define HIVE_SIZE_sp_isp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_length_bq
#define HIVE_MEM_sp_obarea_length_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_obarea_length_bq 0x4484
#define HIVE_SIZE_sp_obarea_length_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_length_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_obarea_length_bq 0x4484
#define HIVE_SIZE_sp_sp_obarea_length_bq 4

/* function is_ddr_debug_buffer_full: 2BB */

/* function sp_dma_proxy_isp_write_addr: 26EC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_fiber
#define HIVE_MEM_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_fiber 0x570
#define HIVE_SIZE_sp_threads_fiber 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_fiber 0x570
#define HIVE_SIZE_sp_sp_threads_fiber 20

/* function encode_and_post_sp_event: 857 */

/* function debug_enqueue_ddr: E3 */

/* function ia_css_rmgr_sp_refcount_init_vbuf: 4AAD */

/* function dmaproxy_sp_read_write: 541E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x5FF8
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x5FF8
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 50CA */

/* function host2sp_dequeue_buffer: 4800 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_service
#define HIVE_MEM_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_service 0x3C34
#define HIVE_SIZE_ia_css_flash_sp_in_service 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_service 0x3C34
#define HIVE_SIZE_sp_ia_css_flash_sp_in_service 4

/* function ia_css_dmaproxy_sp_process: 50F6 */

/* function sp2host_enqueue_buffer: 47A4 */

/* function ia_css_ispctrl_sp_init_cs: 29AD */

/* function ia_css_spctrl_sp_init: 4853 */

/* function sp_event_proxy_init: 5E6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_output 0x4488
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_output 0x4488
#define HIVE_SIZE_sp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x53FC
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_host2sp_buf_queues 560
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x53FC
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 560

/* function pixelgen_prbs_config: CAA */

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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp2host_event_queue
#define HIVE_MEM_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp2host_event_queue 0x50B8
#define HIVE_SIZE_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp2host_event_queue 0x50B8
#define HIVE_SIZE_sp_sem_for_sp2host_event_queue 20

/* function ia_css_tagger_sp_update_size: 2061 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x562C
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 2220
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x562C
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 2220

/* function thread_fiber_sp_create: 1281 */

/* function host2sp_dequeue_sp_event: 4775 */

/* function ia_css_dmaproxy_sp_set_increments: 280A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_frame
#define HIVE_MEM_sem_for_writing_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_frame 0x5164
#define HIVE_SIZE_sem_for_writing_cb_frame 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_frame 0x5164
#define HIVE_SIZE_sp_sem_for_writing_cb_frame 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_param
#define HIVE_MEM_sem_for_writing_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_param 0x5178
#define HIVE_SIZE_sem_for_writing_cb_param 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_param 0x5178
#define HIVE_SIZE_sp_sem_for_writing_cb_param 20

/* function pixelgen_tpg_is_done: D23 */

/* function ia_css_isys_stream_capture_indication: 497B */

/* function sp_start_isp_entry: 37E */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x37E
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x37E

/* function ia_css_dmaproxy_sp_channel_acquire: 548F */

/* function sp2host_enqueue_irq_event: 471C */

/* function ia_css_rmgr_sp_add_num_vbuf: 4C9D */

/* function ibuf_ctrl_config: B02 */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 2689 */

/* function ia_css_tagger_buf_sp_push_marked: 21B1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_line
#define HIVE_MEM_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_line 0x6008
#define HIVE_SIZE_isp_vectors_per_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_line 0x6008
#define HIVE_SIZE_sp_isp_vectors_per_line 4

/* function ia_css_bufq_sp_is_dynamic_buffer: 25A6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x4498
#define HIVE_SIZE_sp_group 2824
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x4498
#define HIVE_SIZE_sp_sp_group 2824

/* function sp2host_buffer_queue_get_size: 479A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_event_proxy_thread
#define HIVE_MEM_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_proxy_thread 0x52FC
#define HIVE_SIZE_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_event_proxy_thread 0x52FC
#define HIVE_SIZE_sp_sp_event_proxy_thread 64

/* function ia_css_thread_sp_kill: 11B6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_uv_internal_width_vecs
#define HIVE_MEM_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_uv_internal_width_vecs 0x600C
#define HIVE_SIZE_isp_uv_internal_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_uv_internal_width_vecs 0x600C
#define HIVE_SIZE_sp_isp_uv_internal_width_vecs 4

/* function ia_css_tagger_sp_create: 2015 */

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

/* function ia_css_dmaproxy_sp_channel_release: 547B */

/* function pixelgen_prbs_run: C98 */

/* function ia_css_dmaproxy_sp_is_idle: 28AD */

/* function sp2host_event_queue_get_size: 4713 */

/* function isp_hmem_load: 8C5 */

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
#ifndef HIVE_MEM_ia_css_i_mipi_exp_id
#define HIVE_MEM_ia_css_i_mipi_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_i_mipi_exp_id 0xF58
#define HIVE_SIZE_ia_css_i_mipi_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_mipi_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_i_mipi_exp_id 0xF58
#define HIVE_SIZE_sp_ia_css_i_mipi_exp_id 1

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_b 0x6010
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_b 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 0x6010
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 4

/* function ia_css_rmgr_sp_refcount_retain_vbuf: 4B6B */

/* function ia_css_thread_sp_set_priority: 11AE */

/* function sizeof_hmem: 961 */

/* function input_system_channel_open: F83 */

/* function pixelgen_tpg_stop: D12 */

/* function __ia_css_dmaproxy_sp_process_text: 2608 */

/* function ia_css_dmaproxy_sp_set_width_exception: 27F6 */

/* function ia_css_flash_sp_init_internal_params: 2300 */

/* function sp_generate_events: 781 */

/* function __modu: 4D94 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 26A6 */

/* function input_system_channel_transfer: F6C */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horiproj_num
#define HIVE_MEM_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horiproj_num 0x6014
#define HIVE_SIZE_isp_sdis_horiproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horiproj_num 0x6014
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

/* function sp_event_proxy_callout_func: 4E4E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x5340
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x5340
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack_size
#define HIVE_MEM_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_stack_size 0x55C
#define HIVE_SIZE_sp_threads_stack_size 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_stack_size 0x55C
#define HIVE_SIZE_sp_sp_threads_stack_size 20

/* function ia_css_ispctrl_sp_isp_done_row_striping: 34F7 */

/* function __ia_css_virtual_isys_sp_isr_text: 4895 */

/* function ia_css_dmaproxy_sp_configure_channel: 53A7 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x5348
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x5348
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function ia_css_circbuf_pop: 10BD */

/* function memset: 4E13 */

/* function irq_raise_set_token: AB */

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

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_ph
#define HIVE_MEM_isp_ph scalar_processor_2400_dmem
#define HIVE_ADDR_isp_ph 0x6684
#define HIVE_SIZE_isp_ph 28
#else
#endif
#endif
#define HIVE_MEM_sp_isp_ph scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_ph 0x6684
#define HIVE_SIZE_sp_isp_ph 28

/* function ia_css_ispctrl_sp_init_ds: 2B1E */

/* function get_xmem_base_addr_raw: 2E92 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_param
#define HIVE_MEM_sp_all_cbs_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_param 0x518C
#define HIVE_SIZE_sp_all_cbs_param 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_param 0x518C
#define HIVE_SIZE_sp_sp_all_cbs_param 16

/* function pixelgen_tpg_config: D46 */

/* function ia_css_circbuf_create: 1109 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_co_fr_ct 0x6644
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 0x6644
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp_group
#define HIVE_MEM_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp_group 0x519C
#define HIVE_SIZE_sem_for_sp_group 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp_group 0x519C
#define HIVE_SIZE_sp_sem_for_sp_group 20

/* function csi_rx_frontend_run: 98B */

/* function ia_css_framebuf_sp_wait_for_in_frame: 4CC1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_i_raw_exp_id
#define HIVE_MEM_ia_css_i_raw_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_i_raw_exp_id 0x6860
#define HIVE_SIZE_ia_css_i_raw_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_raw_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_i_raw_exp_id 0x6860
#define HIVE_SIZE_sp_ia_css_i_raw_exp_id 1

/* function ia_css_tagger_buf_sp_push_unmarked: 20D2 */

/* function ia_css_isys_stream_open: 49E5 */

/* function input_system_channel_configure: F97 */

/* function isp_hmem_clear: 895 */

/* function ia_css_framebuf_sp_release_in_frame: 4CFA */

/* function stream2mmio_config: C47 */

/* function ia_css_ispctrl_sp_start_binary: 298B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertproj_num
#define HIVE_MEM_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertproj_num 0x6018
#define HIVE_SIZE_isp_sdis_vertproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertproj_num 0x6018
#define HIVE_SIZE_sp_isp_sdis_vertproj_num 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs
#define HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x5ED8
#define HIVE_SIZE_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x5ED8
#define HIVE_SIZE_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16

/* function csi_rx_frontend_config: 9AF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_pool
#define HIVE_MEM_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_isp_pool 0xEFC
#define HIVE_SIZE_isp_pool 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_pool 0xEFC
#define HIVE_SIZE_sp_isp_pool 4

/* function ia_css_rmgr_sp_rel_gen: 4A54 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0xFB0
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0xFB0
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ibuf_ctrl_unit_test: A79 */

/* function ia_css_pipeline_sp_get_pipe_io_status: 14F4 */

/* function sh_css_decode_tag_descr: 33E */

/* function debug_enqueue_isp: 26A */

/* function ia_css_spctrl_sp_uninit: 484C */

/* function csi_rx_backend_run: 99D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x5EE8
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 80
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x5EE8
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 80

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x51B0
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x51B0
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 271A */

/* function ia_css_dmaproxy_sp_init: 2663 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_vf_downscale_bits
#define HIVE_MEM_sp_vf_downscale_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vf_downscale_bits 0x4FA0
#define HIVE_SIZE_sp_vf_downscale_bits 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_vf_downscale_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_vf_downscale_bits 0x4FA0
#define HIVE_SIZE_sp_sp_vf_downscale_bits 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertcoef_vectors
#define HIVE_MEM_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertcoef_vectors 0x601C
#define HIVE_SIZE_isp_sdis_vertcoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertcoef_vectors 0x601C
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

/* function input_system_channel_sync: F58 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tagger
#define HIVE_MEM_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tagger 0x6648
#define HIVE_SIZE_ia_css_rawcopy_sp_tagger 24
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tagger 0x6648
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tagger 24

/* function ia_css_spctrl_sp_get_state: 4837 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x533C
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x533C
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function thread_fiber_sp_init: 1308 */

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
#define HIVE_ADDR_sp_isp_input_stream_format 0x4FA4
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x4FA4
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 4D80 */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 2786 */

/* function ia_css_thread_sp_join: 11DF */

/* function ia_css_dmaproxy_sp_add_command: 545F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x96C
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x96C
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 494F */

/* function ia_css_event_sp_encode: 28EC */

/* function stream2mmio_unit_test: C36 */

/* function ia_css_thread_sp_run: 124B */

/* function sp_isys_copy_func: 58A */

/* function register_isr: 6E0 */

/* function irq_raise: BD */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 25C8 */

/* function pipeline_sp_initialize_stage: 1704 */

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 5379 */

/* function ia_css_ispctrl_sp_done_ds: 2AF8 */

/* function csi_rx_backend_config: 9C0 */

/* function ia_css_parambuf_sp_init_buffer_queues: 14E1 */

/* function ia_css_tagger_buf_sp_pop_unmarked: 206A */

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
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x5F38
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x5F38
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_ispctrl_sp_init_isp_vars: 388A */

/* function ia_css_isys_stream_start: 4996 */

/* function ia_css_rmgr_sp_vbuf_enqueue: 4B31 */

/* function ia_css_tagger_sp_tag_exp_id: 1B28 */

/* function ia_css_dmaproxy_sp_write: 2731 */

/* function ia_css_parambuf_sp_release_in_param: 137F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x43F8
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x43F8
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_addresses 0x6264
#define HIVE_SIZE_sp_isp_addresses 188
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x6264
#define HIVE_SIZE_sp_sp_isp_addresses 188

/* function ia_css_rmgr_sp_acq_gen: 4A6C */

/* function input_system_input_port_open: EB1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isps
#define HIVE_MEM_isps scalar_processor_2400_dmem
#define HIVE_ADDR_isps 0x66A0
#define HIVE_SIZE_isps 28
#else
#endif
#endif
#define HIVE_MEM_sp_isps scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isps 0x66A0
#define HIVE_SIZE_sp_isps 28

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x4FB4
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x4FB4
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_buf_swap
#define HIVE_MEM_ia_css_ispctrl_sp_buf_swap scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_buf_swap 0x4264
#define HIVE_SIZE_ia_css_ispctrl_sp_buf_swap 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_buf_swap scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_buf_swap 0x4264
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_buf_swap 96

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x6020
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x6020
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_bufq_sp_release_dynamic_buf: 2357 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_cropping_a 0x6024
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 0x6024
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 4

/* function ia_css_dmaproxy_sp_set_height_exception: 27E8 */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 27B6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x5344
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x5344
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 2703 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_spref
#define HIVE_MEM_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_spref 0xF4C
#define HIVE_SIZE_vbuf_spref 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_spref 0xF4C
#define HIVE_SIZE_sp_vbuf_spref 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_request
#define HIVE_MEM_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_request 0x5350
#define HIVE_SIZE_ia_css_flash_sp_request 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_request 0x5350
#define HIVE_SIZE_sp_ia_css_flash_sp_request 4

/* function ia_css_dmaproxy_sp_vmem_write: 26BD */

/* function ia_css_tagger_buf_sp_unmark: 2245 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horicoef_vectors
#define HIVE_MEM_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horicoef_vectors 0x6028
#define HIVE_SIZE_isp_sdis_horicoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horicoef_vectors 0x6028
#define HIVE_SIZE_sp_isp_sdis_horicoef_vectors 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_if
#define HIVE_MEM_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_if 0x51C4
#define HIVE_SIZE_sem_for_reading_if 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_if 0x51C4
#define HIVE_SIZE_sp_sem_for_reading_if 20

/* function sp_generate_interrupts: 6E8 */

/* function ia_css_pipeline_sp_start: 16CC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_data 0x6368
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_data 0x6368
#define HIVE_SIZE_sp_sp_data 640

/* function input_system_input_port_configure: F03 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0xFA8
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0xFA8
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x5F68
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_sp2host_buf_queues 140
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x5F68
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 140

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_mem_map 0x4FB8
#define HIVE_SIZE_mem_map 248
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x4FB8
#define HIVE_SIZE_sp_mem_map 248

/* function isys2401_dma_config_legacy: C14 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_frame
#define HIVE_MEM_sp_all_cbs_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_frame 0x51D8
#define HIVE_SIZE_sp_all_cbs_frame 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_frame 0x51D8
#define HIVE_SIZE_sp_sp_all_cbs_frame 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_out_buf 0x602C
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_out_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_out_buf 0x602C
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_out_buf 4

/* function ia_css_virtual_isys_sp_isr: 54AD */

/* function thread_sp_queue_print: 1268 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_str2mem
#define HIVE_MEM_sem_for_str2mem scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_str2mem 0x51E8
#define HIVE_SIZE_sem_for_str2mem 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_str2mem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_str2mem 0x51E8
#define HIVE_SIZE_sp_sem_for_str2mem 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_a 0x6030
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 0x6030
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 4

/* function ia_css_bufq_sp_acquire_dynamic_buf: 24EF */

/* function ia_css_circbuf_destroy: 10FE */

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

/* function __div: 4D38 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vf_output_width_vecs
#define HIVE_MEM_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vf_output_width_vecs 0x6034
#define HIVE_SIZE_isp_vf_output_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vf_output_width_vecs 0x6034
#define HIVE_SIZE_sp_isp_vf_output_width_vecs 4

/* function ia_css_rmgr_sp_refcount_release_vbuf: 4B4A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_use
#define HIVE_MEM_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_use 0x5354
#define HIVE_SIZE_ia_css_flash_sp_in_use 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_use 0x5354
#define HIVE_SIZE_sp_ia_css_flash_sp_in_use 4

/* function ia_css_thread_sem_sp_wait: 501C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sleep_mode 0x50B0
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x50B0
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_max_cb_elems
#define HIVE_MEM_sp_max_cb_elems scalar_processor_2400_dmem
#define HIVE_ADDR_sp_max_cb_elems 0x4E4
#define HIVE_SIZE_sp_max_cb_elems 8
#else
#endif
#endif
#define HIVE_MEM_sp_sp_max_cb_elems scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_max_cb_elems 0x4E4
#define HIVE_SIZE_sp_sp_max_cb_elems 8

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stop_req
#define HIVE_MEM_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stop_req 0x50B4
#define HIVE_SIZE_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stop_req 0x50B4
#define HIVE_SIZE_sp_isp_stop_req 4

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
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
  sh_css_print("sp_group.pipe[0].required_bds_factor ="
    "                    0x%x\n",
    sp_group.pipe[0].required_bds_factor);
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
  sh_css_print("sp_group.pipe[1].required_bds_factor ="
    "                    0x%x\n",
    sp_group.pipe[1].required_bds_factor);
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
  sh_css_print("sp_group.pipe[2].required_bds_factor ="
    "                    0x%x\n",
    sp_group.pipe[2].required_bds_factor);
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
  sh_css_print("sp_group.pipe[3].required_bds_factor ="
    "                    0x%x\n",
    sp_group.pipe[3].required_bds_factor);
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
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.source_type ="
    "0x%x             \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                   \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                    \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                      \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x             \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                 \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x           \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                   \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x               \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x              \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.dma_id ="
    "0x%x     \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[0].input.context.virtual_input_system.channel.dma_channel ="
    "0x%x          \n",
    sp_group.pipe_io[0].input.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                    \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                     \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                        \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                 \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                             \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                              \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                      \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                 \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                     \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                 \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                          \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                   \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                      \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                     \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                  \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                             \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                             \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                          \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[0].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.source_type ="
    "0x%x              \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                     \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                     \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                              \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                       \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x              \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                  \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x            \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                    \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x                \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x               \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.dma_id ="
    "0x%x      \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[0].output.context.virtual_input_system.channel.dma_channel ="
    "0x%x           \n",
    sp_group.pipe_io[0].output.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                           \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                           \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                     \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                 \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                             \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                           \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                       \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                          \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                              \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                               \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                 \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                 \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                       \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                      \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                  \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                    \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                       \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                      \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                   \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                             \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                               \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                               \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                            \n",
    sp_group.pipe_io[0].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.source_type ="
    "0x%x             \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                   \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                    \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                      \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x             \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                 \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x           \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                   \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x               \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x              \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.dma_id ="
    "0x%x     \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[1].input.context.virtual_input_system.channel.dma_channel ="
    "0x%x          \n",
    sp_group.pipe_io[1].input.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                    \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                     \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                        \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                 \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                             \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                              \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                      \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                 \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                     \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                 \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                          \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                   \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                      \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                     \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                  \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                             \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                             \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                          \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[1].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.source_type ="
    "0x%x              \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                     \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                     \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                              \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                       \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x              \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                  \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x            \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                    \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x                \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x               \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.dma_id ="
    "0x%x      \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[1].output.context.virtual_input_system.channel.dma_channel ="
    "0x%x           \n",
    sp_group.pipe_io[1].output.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                           \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                           \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                     \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                 \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                             \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                           \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                       \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                          \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                              \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                               \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                 \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                 \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                       \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                      \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                  \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                    \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                       \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                      \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                   \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                             \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                               \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                               \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                            \n",
    sp_group.pipe_io[1].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.source_type ="
    "0x%x             \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                   \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                    \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                      \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x             \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                 \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x           \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                   \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x               \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x              \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.dma_id ="
    "0x%x     \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[2].input.context.virtual_input_system.channel.dma_channel ="
    "0x%x          \n",
    sp_group.pipe_io[2].input.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                    \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                     \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                        \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                 \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                             \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                              \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                      \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                 \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                     \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                 \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                          \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                   \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                      \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                     \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                  \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                             \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                             \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                          \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[2].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.source_type ="
    "0x%x              \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                     \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                     \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                              \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                       \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x              \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                  \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x            \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                    \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x                \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x               \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.dma_id ="
    "0x%x      \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[2].output.context.virtual_input_system.channel.dma_channel ="
    "0x%x           \n",
    sp_group.pipe_io[2].output.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                           \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                           \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                     \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                 \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                             \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                           \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                       \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                          \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                              \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                               \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                 \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                 \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                       \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                      \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                  \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                    \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                       \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                      \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                   \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                             \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                               \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                               \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                            \n",
    sp_group.pipe_io[2].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.source_type ="
    "0x%x             \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                   \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                    \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                      \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x             \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                 \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x           \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                   \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x               \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x              \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.dma_id ="
    "0x%x     \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[3].input.context.virtual_input_system.channel.dma_channel ="
    "0x%x          \n",
    sp_group.pipe_io[3].input.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                    \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                             \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                      \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                     \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                        \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                 \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                             \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                              \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                      \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                 \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                     \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                 \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                          \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                   \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                      \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                     \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                  \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                             \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                             \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                          \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[3].input.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.source_type ="
    "0x%x              \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.source_type);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.frontend_id ="
    "0x%x                     \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.frontend_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_id ="
    "0x%x                    \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.packet_type ="
    "0x%x                     \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.packet_type);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry ="
    "0x%x                                             \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry ="
    "0x%x                                              \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.csi_rx.backend_lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id ="
    "0x%x                       \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.input_port.pixelgen.pixelgen_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.stream2mmio_id ="
    "0x%x              \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.stream2mmio_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.stream2mmio_sid_id ="
    "0x%x                  \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.stream2mmio_sid_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.ibuf_ctrl_id ="
    "0x%x            \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.ibuf_ctrl_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.start_addr ="
    "0x%x                    \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.stride ="
    "0x%x                \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.lines ="
    "0x%x               \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.dma_id ="
    "0x%x      \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.dma_id);
  sh_css_print("sp_group.pipe_io[3].output.context.virtual_input_system.channel.dma_channel ="
    "0x%x           \n",
    sp_group.pipe_io[3].output.context.virtual_input_system.channel.dma_channel);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.frontend_cfg.active_lanes);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.long_packet_entry);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry ="
    "0x%x                                                           \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.lut_entry.short_packet_entry);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type ="
    "0x%x                                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_packet_type);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel ="
    "0x%x                                                           \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.virtual_channel);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type ="
    "0x%x                                                     \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.csi_rx_cfg.backend_cfg.csi_mipi_cfg.data_type);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode ="
    "0x%x                                 \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mode);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R1);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G1);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B1);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.R2);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.G2);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2 ="
    "0x%x                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.color_cfg.B2);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.h_mask);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.v_mask);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask ="
    "0x%x                                             \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.mask_cfg.hv_mask);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.h_delta);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta ="
    "0x%x                                              \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.delta_cfg.v_delta);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                       \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                      \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                         \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.tpg_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0 ="
    "0x%x                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed0);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1 ="
    "0x%x                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.seed1);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.hblank_cycles);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles ="
    "0x%x                                                        \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.vblank_cycles);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock ="
    "0x%x                                                           \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_clock);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames ="
    "0x%x                                                       \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.nr_of_frames);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.pixels_per_line);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame ="
    "0x%x                                                          \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.input_port_cfg.pixelgen_cfg.prbs_cfg.sync_gen_cfg.lines_per_frame);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel ="
    "0x%x                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.stream2mmio_cfg.bits_per_pixel);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd ="
    "0x%x                              \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.cmd);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items ="
    "0x%x                                               \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.shift_returned_items);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf ="
    "0x%x                                                 \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_ibuf);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest ="
    "0x%x                                                 \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dma_cfg.elems_per_word_in_dest);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr ="
    "0x%x                                       \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.start_addr);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride ="
    "0x%x                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.stride);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.ib_buffer.lines);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride ="
    "0x%x                                      \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.dest_buf_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store ="
    "0x%x                                  \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.items_per_store);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame ="
    "0x%x                                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stores_per_frame);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd ="
    "0x%x                                           \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.sync_cmd);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd ="
    "0x%x                                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.ibuf_ctrl_cfg.stream2mmio_cfg.store_cmd);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel ="
    "0x%x                    \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.channel);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection ="
    "0x%x                       \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.connection);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension ="
    "0x%x                      \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.extension);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height ="
    "0x%x                   \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_cfg.height);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride ="
    "0x%x                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements ="
    "0x%x                              \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping ="
    "0x%x                              \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width ="
    "0x%x                           \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_src_port_cfg.width);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride ="
    "0x%x                             \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.stride);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements ="
    "0x%x                               \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.elements);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping ="
    "0x%x                               \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.cropping);
  sh_css_print("sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width ="
    "0x%x                            \n",
    sp_group.pipe_io[3].output.ctrl.virtual_input_system_cfg.channel_cfg.dma_dest_port_cfg.width);
  sh_css_print("sp_group.pipe_io_status.active[0] ="
    "                       0x%x\n",
    sp_group.pipe_io_status.active[0]);
  sh_css_print("sp_group.pipe_io_status.active[1] ="
    "                       0x%x\n",
    sp_group.pipe_io_status.active[1]);
  sh_css_print("sp_group.pipe_io_status.active[2] ="
    "                       0x%x\n",
    sp_group.pipe_io_status.active[2]);
  sh_css_print("sp_group.pipe_io_status.running[0] ="
    "                      0x%x\n",
    sp_group.pipe_io_status.running[0]);
  sh_css_print("sp_group.pipe_io_status.running[1] ="
    "                      0x%x\n",
    sp_group.pipe_io_status.running[1]);
  sh_css_print("sp_group.pipe_io_status.running[2] ="
    "                      0x%x\n",
    sp_group.pipe_io_status.running[2]);
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
  sh_css_print("host_sp_com.host2sp_offline_frames[10] ="
    "                  0x%x\n",
    host_sp_com.host2sp_offline_frames[10]);
  sh_css_print("host_sp_com.host2sp_offline_frames[11] ="
    "                  0x%x\n",
    host_sp_com.host2sp_offline_frames[11]);
  sh_css_print("host_sp_com.host2sp_offline_frames[12] ="
    "                  0x%x\n",
    host_sp_com.host2sp_offline_frames[12]);
  sh_css_print("host_sp_com.host2sp_offline_frames[13] ="
    "                  0x%x\n",
    host_sp_com.host2sp_offline_frames[13]);
  sh_css_print("host_sp_com.host2sp_offline_frames[14] ="
    "                  0x%x\n",
    host_sp_com.host2sp_offline_frames[14]);
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
