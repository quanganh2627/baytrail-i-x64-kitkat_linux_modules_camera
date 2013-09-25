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

#ifndef _sp_map_h_
#define _sp_map_h_


#ifndef _hrt_dummy_use_blob_sp
#define _hrt_dummy_use_blob_sp()
#endif

#define _hrt_cell_load_program_sp(proc) _hrt_cell_load_program_embedded(proc, sp)

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_input_line
#define HIVE_MEM_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_input_line 0x5324
#define HIVE_SIZE_isp_vectors_per_input_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_input_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_input_line 0x5324
#define HIVE_SIZE_sp_isp_vectors_per_input_line 4

/* function longjmp: 4B17 */

/* function ia_css_dmaproxy_sp_set_addr_B: 2797 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_id 0x45B8
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_id 0x45B8
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_id 4

/* function debug_buffer_set_ddr_addr: D2 */

/* function ia_css_circbuf_sp_create: 12C2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_mipi
#define HIVE_MEM_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_mipi 0x308
#define HIVE_SIZE_vbuf_mipi 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_mipi 0x308
#define HIVE_SIZE_sp_vbuf_mipi 4

/* function ia_css_event_sp_decode: 283F */

/* function setjmp: 4B20 */

/* function ia_css_ispctrl_sp_dma_configure_io: 3B16 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x598C
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_cp_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x598C
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 4

/* function __dmaproxy_sp_read_write_text: 2801 */

/* function ia_css_dmaproxy_sp_wait_for_ack: 512F */

/* function ia_css_circbuf_sp_mark: 118B */

/* function ia_css_virtual_isys_sp_sync_N: 4737 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stage 0x5360
#define HIVE_SIZE_isp_stage 600
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stage 0x5360
#define HIVE_SIZE_sp_isp_stage 600

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_raw
#define HIVE_MEM_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_raw 0x304
#define HIVE_SIZE_vbuf_raw 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_raw 0x304
#define HIVE_SIZE_sp_vbuf_raw 4

/* function ia_css_sp_bin_copy_func: 4729 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_buffer_bufs 0x45BC
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_buffer_bufs 128
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 0x45BC
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 128

/* function sp_start_isp: 388 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_binary_group 0x5674
#define HIVE_SIZE_sp_binary_group 72
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x5674
#define HIVE_SIZE_sp_sp_binary_group 72

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x35A8
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x35A8
#define HIVE_SIZE_sp_sp_sw_state 4

/* function generate_sw_interrupt: 77F */

/* function ia_css_thread_sp_main: 13EA */

/* function ia_css_ispctrl_sp_init_internal_buffers: 29F4 */

/* function pixelgen_unit_test: CA2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x5328
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_vfout_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 0x5328
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_vfout_cropping_a 4

/* function ibuf_ctrl_sync: ACD */

/* function ia_css_tagger_sp_propagate_frame: 1DEB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x5990
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x5990
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_handles
#define HIVE_MEM_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_handles 0x59F4
#define HIVE_SIZE_vbuf_handles 400
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_handles 0x59F4
#define HIVE_SIZE_sp_vbuf_handles 400

/* function ia_css_sp_flash_register: 2240 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_elems_params_capture_pipe
#define HIVE_MEM_cb_elems_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_elems_params_capture_pipe 0x4274
#define HIVE_SIZE_cb_elems_params_capture_pipe 16
#else
#endif
#endif
#define HIVE_MEM_sp_cb_elems_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_elems_params_capture_pipe 0x4274
#define HIVE_SIZE_sp_cb_elems_params_capture_pipe 16

/* function ia_css_circbuf_sp_unmark: 1163 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_event_proxy_thread
#define HIVE_MEM_ia_css_thread_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_event_proxy_thread 0x4400
#define HIVE_SIZE_ia_css_thread_sp_event_proxy_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_event_proxy_thread 0x4400
#define HIVE_SIZE_sp_ia_css_thread_sp_event_proxy_thread 64

/* function ia_css_pipeline_sp_init: 1951 */

/* function ia_css_tagger_sp_configure: 1D86 */

/* function ia_css_ispctrl_sp_end_binary: 287A */

/* function pixelgen_tpg_run: D45 */

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

/* function ia_css_circbuf_sp_pop_marked: 108F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_com 0x35AC
#define HIVE_SIZE_host_sp_com 116
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_com 0x35AC
#define HIVE_SIZE_sp_host_sp_com 116

/* function exec_image_pipe: 504 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x3620
#define HIVE_SIZE_sp_init_dmem_data 36
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x3620
#define HIVE_SIZE_sp_sp_init_dmem_data 36

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_thread_sp_copy_pipe_thread
#define HIVE_MEM_thread_sp_copy_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_thread_sp_copy_pipe_thread 0x4440
#define HIVE_SIZE_thread_sp_copy_pipe_thread 64
#else
#endif
#endif
#define HIVE_MEM_sp_thread_sp_copy_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_thread_sp_copy_pipe_thread 0x4440
#define HIVE_SIZE_sp_thread_sp_copy_pipe_thread 64

/* function ia_css_pipeline_sp_stop: 1934 */

/* function ia_css_tagger_sp_connect_pipes: 21D3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_pipeline_sp_capture_thread_id
#define HIVE_MEM_ia_css_pipeline_sp_capture_thread_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_pipeline_sp_capture_thread_id 0x45A4
#define HIVE_SIZE_ia_css_pipeline_sp_capture_thread_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_pipeline_sp_capture_thread_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_pipeline_sp_capture_thread_id 0x45A4
#define HIVE_SIZE_sp_ia_css_pipeline_sp_capture_thread_id 4

/* function is_isp_debug_buffer_full: 323 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_pipeline_sp_preview_thread_id
#define HIVE_MEM_ia_css_pipeline_sp_preview_thread_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_pipeline_sp_preview_thread_id 0x45A8
#define HIVE_SIZE_ia_css_pipeline_sp_preview_thread_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_pipeline_sp_preview_thread_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_pipeline_sp_preview_thread_id 0x45A8
#define HIVE_SIZE_sp_ia_css_pipeline_sp_preview_thread_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_params_preview_pipe
#define HIVE_MEM_sem_for_writing_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_params_preview_pipe 0x4284
#define HIVE_SIZE_sem_for_writing_cb_params_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_params_preview_pipe 0x4284
#define HIVE_SIZE_sp_sem_for_writing_cb_params_preview_pipe 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_per_frame_data 0x3644
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x3644
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_rmgr_sp_vbuf_dequeue: 490B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_xmem_bin_addr
#define HIVE_MEM_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_xmem_bin_addr 0x3648
#define HIVE_SIZE_xmem_bin_addr 4
#else
#endif
#endif
#define HIVE_MEM_sp_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_sp_xmem_bin_addr 0x3648
#define HIVE_SIZE_sp_xmem_bin_addr 4

/* function ia_css_pipeline_sp_run: 16F6 */

/* function memcpy: 4BAA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0x314
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0x314
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x188
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x188
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 260E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_in_buf 0x532C
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_in_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_in_buf scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_in_buf 0x532C
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_in_buf 4

/* function ia_css_uds_sp_scale_params: 44D0 */

/* function __divu: 4B28 */

/* function ia_css_thread_sp_get_state: 1319 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_stop
#define HIVE_MEM_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_stop 0x4298
#define HIVE_SIZE_sem_for_cont_capt_stop 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_stop 0x4298
#define HIVE_SIZE_sp_sem_for_cont_capt_stop 20

/* function thread_fiber_sp_main: 14C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_start_bq
#define HIVE_MEM_sp_obarea_start_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_obarea_start_bq 0x364C
#define HIVE_SIZE_sp_obarea_start_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_start_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_obarea_start_bq 0x364C
#define HIVE_SIZE_sp_sp_obarea_start_bq 4

/* function ia_css_parambuf_sp_handle_parameter_sets: 1565 */

/* function ia_css_thread_sem_sp_signal: 4D77 */

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

/* function ia_css_rmgr_sp_init: 4817 */

/* function ia_css_thread_sem_sp_init: 4E48 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_is_isp_requested 0x324
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_sp_is_isp_requested 0x324
#define HIVE_SIZE_sp_is_isp_requested 4

/* function ia_css_dmaproxy_sp_execute: 26C7 */

/* function ia_css_pipeline_sp_has_stopped: 192A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0x184
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x184
#define HIVE_SIZE_sp_current_sp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_cur_co_fr_ct 0x5994
#define HIVE_SIZE_ia_css_rawcopy_sp_cur_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_cur_co_fr_ct 0x5994
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_cur_co_fr_ct 4

/* function ia_css_dmaproxy_sp_read_byte_addr: 515D */

/* function ia_css_rmgr_sp_uninit: 4810 */

/* function ia_css_parambuf_sp_wait_for_in_param: 14CF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0x1E0
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0x1E0
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_start
#define HIVE_MEM_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_start 0x42AC
#define HIVE_SIZE_sem_for_cont_capt_start 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_start 0x42AC
#define HIVE_SIZE_sp_sem_for_cont_capt_start 20

/* function host2sp_event_queue_is_empty: 5260 */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 352A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x463C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x463C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 48

/* function debug_buffer_init_isp: D9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem
#define HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rmgr_sp_mipi_frame_sem 0x5B84
#define HIVE_SIZE_ia_css_rmgr_sp_mipi_frame_sem 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rmgr_sp_mipi_frame_sem 0x5B84
#define HIVE_SIZE_sp_ia_css_rmgr_sp_mipi_frame_sem 20

/* function ia_css_sp_raw_copy_func: 4730 */

/* function ia_css_rmgr_sp_refcount_dump: 48E6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_frames_capture_pipe
#define HIVE_MEM_sem_for_reading_cb_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_frames_capture_pipe 0x42C0
#define HIVE_SIZE_sem_for_reading_cb_frames_capture_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_frames_capture_pipe 0x42C0
#define HIVE_SIZE_sp_sem_for_reading_cb_frames_capture_pipe 20

/* function sp_event_proxy_func: 5DA */

/* function ibuf_ctrl_run: B01 */

/* function ia_css_thread_sp_yield: 4CF0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x531C
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x531C
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_params_preview_pipe
#define HIVE_MEM_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_params_preview_pipe 0x42D4
#define HIVE_SIZE_cb_params_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_params_preview_pipe 0x42D4
#define HIVE_SIZE_sp_cb_params_preview_pipe 20

/* function ia_css_virtual_isys_sp_start: 47C2 */

/* function ia_css_thread_sp_fork: 13A6 */

/* function ia_css_tagger_sp_destroy: 21DD */

/* function ia_css_dmaproxy_sp_vmem_read: 2650 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ispctrl_sp_dma_configs
#define HIVE_MEM_ispctrl_sp_dma_configs scalar_processor_2400_dmem
#define HIVE_ADDR_ispctrl_sp_dma_configs 0x593C
#define HIVE_SIZE_ispctrl_sp_dma_configs 80
#else
#endif
#endif
#define HIVE_MEM_sp_ispctrl_sp_dma_configs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ispctrl_sp_dma_configs 0x593C
#define HIVE_SIZE_sp_ispctrl_sp_dma_configs 80

/* function initialize_sp_group: 57E */

/* function csi_rx_unit_test: 9A8 */

/* function ia_css_thread_sp_init: 13D2 */

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

/* function ibuf_ctrl_transfer: ADF */

/* function ia_css_dmaproxy_sp_read: 26E8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_raw_copy_line_count 0x2EC
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0x2EC
#define HIVE_SIZE_sp_raw_copy_line_count 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_frames_preview_pipe
#define HIVE_MEM_sem_for_writing_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_frames_preview_pipe 0x42E8
#define HIVE_SIZE_sem_for_writing_cb_frames_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_frames_preview_pipe 0x42E8
#define HIVE_SIZE_sp_sem_for_writing_cb_frames_preview_pipe 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_frame_cnt
#define HIVE_MEM_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_frame_cnt 0x45AC
#define HIVE_SIZE_ia_css_flash_sp_frame_cnt 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_frame_cnt 0x45AC
#define HIVE_SIZE_sp_ia_css_flash_sp_frame_cnt 4

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

/* function ia_css_virtual_isys_sp_transfer: 4797 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_isp_thread 0x55B8
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_thread 0x55B8
#define HIVE_SIZE_sp_isp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_obarea_length_bq
#define HIVE_MEM_sp_obarea_length_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_obarea_length_bq 0x3650
#define HIVE_SIZE_sp_obarea_length_bq 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_obarea_length_bq scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_obarea_length_bq 0x3650
#define HIVE_SIZE_sp_sp_obarea_length_bq 4

/* function is_ddr_debug_buffer_full: 2BB */

/* function sp_dma_proxy_isp_write_addr: 2668 */

/* function encode_and_post_sp_event: 898 */

/* function debug_enqueue_ddr: E3 */

/* function ia_css_rmgr_sp_refcount_init_vbuf: 48B2 */

/* function dmaproxy_sp_read_write: 51E0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x5320
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x5320
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 4E8E */

/* function host2sp_dequeue_buffer: 470D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_service
#define HIVE_MEM_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_service 0x2F04
#define HIVE_SIZE_ia_css_flash_sp_in_service 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_service 0x2F04
#define HIVE_SIZE_sp_ia_css_flash_sp_in_service 4

/* function ia_css_dmaproxy_sp_process: 4EDD */

/* function sp2host_enqueue_buffer: 46ED */

/* function ia_css_ispctrl_sp_init_cs: 2939 */

/* function sp_event_proxy_init: 5FC */

/* function ia_css_circbuf_sp_extract: 11B3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_elems_params_preview_pipe
#define HIVE_MEM_cb_elems_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_elems_params_preview_pipe 0x42FC
#define HIVE_SIZE_cb_elems_params_preview_pipe 16
#else
#endif
#endif
#define HIVE_MEM_sp_cb_elems_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_elems_params_preview_pipe 0x42FC
#define HIVE_SIZE_sp_cb_elems_params_preview_pipe 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_output 0x3654
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_output 0x3654
#define HIVE_SIZE_sp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x466C
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_host2sp_buf_queues 640
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x466C
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 640

/* function pixelgen_prbs_config: CBB */

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
#define HIVE_ADDR_sem_for_sp2host_event_queue 0x4260
#define HIVE_SIZE_sem_for_sp2host_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp2host_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp2host_event_queue 0x4260
#define HIVE_SIZE_sp_sem_for_sp2host_event_queue 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_copy_pack
#define HIVE_MEM_sp_copy_pack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_copy_pack 0x5998
#define HIVE_SIZE_sp_copy_pack 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_copy_pack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_copy_pack 0x5998
#define HIVE_SIZE_sp_sp_copy_pack 4

/* function ia_css_tagger_sp_update_size: 2237 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x48EC
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 2352
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x48EC
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 2352

/* function thread_fiber_sp_create: 1437 */

/* function host2sp_dequeue_sp_event: 46CA */

/* function ia_css_dmaproxy_sp_set_increments: 2786 */

/* function pixelgen_tpg_is_done: D34 */

/* function sp_start_isp_entry: 37E */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x37E
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x37E

/* function ia_css_dmaproxy_sp_channel_acquire: 524C */

/* function sp2host_enqueue_irq_event: 46AB */

/* function ia_css_rmgr_sp_add_num_vbuf: 4A8E */

/* function ibuf_ctrl_config: B13 */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 2605 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_vectors_per_line
#define HIVE_MEM_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vectors_per_line 0x5330
#define HIVE_SIZE_isp_vectors_per_line 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vectors_per_line scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vectors_per_line 0x5330
#define HIVE_SIZE_sp_isp_vectors_per_line 4

/* function ia_css_bufq_sp_is_dynamic_buffer: 24A4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x3668
#define HIVE_SIZE_sp_group 2768
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x3668
#define HIVE_SIZE_sp_sp_group 2768

/* function sp2host_buffer_queue_get_size: 46E1 */

/* function ia_css_thread_sp_kill: 136C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_uv_internal_width_vecs
#define HIVE_MEM_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_uv_internal_width_vecs 0x5334
#define HIVE_SIZE_isp_uv_internal_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_uv_internal_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_uv_internal_width_vecs 0x5334
#define HIVE_SIZE_sp_isp_uv_internal_width_vecs 4

/* function ia_css_tagger_sp_create: 21FE */

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

/* function ia_css_dmaproxy_sp_channel_release: 5238 */

/* function pixelgen_prbs_run: CA9 */

/* function ia_css_dmaproxy_sp_is_idle: 282A */

/* function sp2host_event_queue_get_size: 46A2 */

/* function isp_hmem_load: 905 */

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
#ifndef HIVE_MEM_ia_css_i_mipi_exp_id
#define HIVE_MEM_ia_css_i_mipi_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_i_mipi_exp_id 0x30C
#define HIVE_SIZE_ia_css_i_mipi_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_mipi_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_i_mipi_exp_id 0x30C
#define HIVE_SIZE_sp_ia_css_i_mipi_exp_id 1

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_frames_preview_pipe
#define HIVE_MEM_sem_for_reading_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_frames_preview_pipe 0x430C
#define HIVE_SIZE_sem_for_reading_cb_frames_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_frames_preview_pipe 0x430C
#define HIVE_SIZE_sp_sem_for_reading_cb_frames_preview_pipe 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_b 0x5338
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_b 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_b scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 0x5338
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_b 4

/* function ia_css_rmgr_sp_refcount_retain_vbuf: 4970 */

/* function ia_css_thread_sp_set_priority: 1364 */

/* function sizeof_hmem: 9A1 */

/* function input_system_channel_open: F8B */

/* function pixelgen_tpg_stop: D23 */

/* function __ia_css_dmaproxy_sp_process_text: 2529 */

/* function ia_css_dmaproxy_sp_set_width_exception: 2772 */

/* function ia_css_flash_sp_init_internal_params: 2282 */

/* function ia_css_virtual_isys_sp_configure: 47F3 */

/* function sp_generate_events: 795 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_stack_sizes
#define HIVE_MEM_ia_css_thread_sp_stack_sizes scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_stack_sizes 0x1B8
#define HIVE_SIZE_ia_css_thread_sp_stack_sizes 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_stack_sizes scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_stack_sizes 0x1B8
#define HIVE_SIZE_sp_ia_css_thread_sp_stack_sizes 20

/* function __modu: 4B6E */

/* function ia_css_dmaproxy_sp_init_isp_vector: 2622 */

/* function input_system_channel_transfer: F74 */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horiproj_num
#define HIVE_MEM_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horiproj_num 0x533C
#define HIVE_SIZE_isp_sdis_horiproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horiproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horiproj_num 0x533C
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

/* function sp_event_proxy_callout_func: 4BED */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x43F8
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x43F8
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

/* function ia_css_circbuf_sp_pop: 1274 */

/* function ia_css_virtual_isys_sp_async_transfer_N: 476D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isys_token_handler
#define HIVE_MEM_sem_for_isys_token_handler scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isys_token_handler 0x4320
#define HIVE_SIZE_sem_for_isys_token_handler 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isys_token_handler scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isys_token_handler 0x4320
#define HIVE_SIZE_sp_sem_for_isys_token_handler 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_thread_sp_isp_pipe_thread
#define HIVE_MEM_thread_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_thread_sp_isp_pipe_thread 0x4480
#define HIVE_SIZE_thread_sp_isp_pipe_thread 192
#else
#endif
#endif
#define HIVE_MEM_sp_thread_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_thread_sp_isp_pipe_thread 0x4480
#define HIVE_SIZE_sp_thread_sp_isp_pipe_thread 192

/* function ia_css_dmaproxy_sp_configure_channel: 5174 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x45A0
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x45A0
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

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
#define HIVE_ADDR_isp_ph 0x59BC
#define HIVE_SIZE_isp_ph 28
#else
#endif
#endif
#define HIVE_MEM_sp_isp_ph scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_ph 0x59BC
#define HIVE_SIZE_sp_isp_ph 28

/* function ia_css_ispctrl_sp_init_ds: 2AA2 */

/* function ia_css_circbuf_sp_push_marked: 10DB */

/* function ia_css_circbuf_sp_pop_unmarked: FC8 */

/* function pixelgen_tpg_config: D57 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_co_fr_ct 0x599C
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 0x599C
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp_group
#define HIVE_MEM_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp_group 0x4334
#define HIVE_SIZE_sem_for_sp_group 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp_group 0x4334
#define HIVE_SIZE_sp_sem_for_sp_group 20

/* function csi_rx_frontend_run: 9CB */

/* function ia_css_framebuf_sp_wait_for_in_frame: 4AAE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_i_raw_exp_id
#define HIVE_MEM_ia_css_i_raw_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_i_raw_exp_id 0x5B98
#define HIVE_SIZE_ia_css_i_raw_exp_id 1
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_i_raw_exp_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_i_raw_exp_id 0x5B98
#define HIVE_SIZE_sp_ia_css_i_raw_exp_id 1

/* function input_system_channel_configure: F9F */

/* function isp_hmem_clear: 8D6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_params_preview_pipe
#define HIVE_MEM_sem_for_reading_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_params_preview_pipe 0x4348
#define HIVE_SIZE_sem_for_reading_cb_params_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_params_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_params_preview_pipe 0x4348
#define HIVE_SIZE_sp_sem_for_reading_cb_params_preview_pipe 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_pack_bits
#define HIVE_MEM_sp_pack_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pack_bits 0x59A0
#define HIVE_SIZE_sp_pack_bits 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_pack_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_pack_bits 0x59A0
#define HIVE_SIZE_sp_sp_pack_bits 4

/* function ia_css_framebuf_sp_release_in_frame: 4AEA */

/* function stream2mmio_config: C58 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_params_capture_pipe
#define HIVE_MEM_sem_for_reading_cb_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_params_capture_pipe 0x435C
#define HIVE_SIZE_sem_for_reading_cb_params_capture_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_params_capture_pipe 0x435C
#define HIVE_SIZE_sp_sem_for_reading_cb_params_capture_pipe 20

/* function ia_css_ispctrl_sp_start_binary: 2917 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertproj_num
#define HIVE_MEM_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertproj_num 0x5340
#define HIVE_SIZE_isp_sdis_vertproj_num 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertproj_num scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertproj_num 0x5340
#define HIVE_SIZE_sp_isp_sdis_vertproj_num 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_params_capture_pipe
#define HIVE_MEM_cb_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_params_capture_pipe 0x4370
#define HIVE_SIZE_cb_params_capture_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_cb_params_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_params_capture_pipe 0x4370
#define HIVE_SIZE_sp_cb_params_capture_pipe 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs
#define HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x521C
#define HIVE_SIZE_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x521C
#define HIVE_SIZE_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 16

/* function csi_rx_frontend_config: 9EF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_frames_capture_pipe
#define HIVE_MEM_cb_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_frames_capture_pipe 0x4384
#define HIVE_SIZE_cb_frames_capture_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_cb_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_frames_capture_pipe 0x4384
#define HIVE_SIZE_sp_cb_frames_capture_pipe 20

/* function ia_css_circbuf_sp_destroy: 12B6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_pool
#define HIVE_MEM_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_isp_pool 0x2FC
#define HIVE_SIZE_isp_pool 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_pool 0x2FC
#define HIVE_SIZE_sp_isp_pool 4

/* function ia_css_rmgr_sp_rel_gen: 4859 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0x318
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0x318
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ibuf_ctrl_unit_test: A8A */

/* function sh_css_decode_tag_descr: 33E */

/* function ia_css_circbuf_sp_is_marked: 113E */

/* function debug_enqueue_isp: 26A */

/* function csi_rx_backend_run: 9DD */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x522C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 32
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x522C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 32

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x4398
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x4398
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 2696 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_fibers
#define HIVE_MEM_ia_css_thread_sp_fibers scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_fibers 0x1CC
#define HIVE_SIZE_ia_css_thread_sp_fibers 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_fibers scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_fibers 0x1CC
#define HIVE_SIZE_sp_ia_css_thread_sp_fibers 20

/* function ia_css_dmaproxy_sp_init: 25DF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_vf_downscale_bits
#define HIVE_MEM_sp_vf_downscale_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vf_downscale_bits 0x4138
#define HIVE_SIZE_sp_vf_downscale_bits 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_vf_downscale_bits scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_vf_downscale_bits 0x4138
#define HIVE_SIZE_sp_sp_vf_downscale_bits 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_vertcoef_vectors
#define HIVE_MEM_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_vertcoef_vectors 0x5344
#define HIVE_SIZE_isp_sdis_vertcoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_vertcoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_vertcoef_vectors 0x5344
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

/* function input_system_channel_sync: F60 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tagger
#define HIVE_MEM_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tagger 0x59A4
#define HIVE_SIZE_ia_css_rawcopy_sp_tagger 24
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tagger 0x59A4
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tagger 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x43F4
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x43F4
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function thread_fiber_sp_init: 14BE */

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
#define HIVE_ADDR_sp_isp_input_stream_format 0x413C
#define HIVE_SIZE_sp_isp_input_stream_format 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x413C
#define HIVE_SIZE_sp_sp_isp_input_stream_format 16

/* function __mod: 4B5A */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 2702 */

/* function ia_css_thread_sp_join: 1395 */

/* function ia_css_dmaproxy_sp_add_command: 521C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_pipe
#define HIVE_MEM_ia_css_thread_sp_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_pipe 0x194
#define HIVE_SIZE_ia_css_thread_sp_pipe 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_pipe 0x194
#define HIVE_SIZE_sp_ia_css_thread_sp_pipe 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_stacks
#define HIVE_MEM_ia_css_thread_sp_stacks scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_stacks 0x1A4
#define HIVE_SIZE_ia_css_thread_sp_stacks 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_stacks scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_stacks 0x1A4
#define HIVE_SIZE_sp_ia_css_thread_sp_stacks 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x248
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x248
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_circbuf_sp_peek: 106A */

/* function ia_css_event_sp_encode: 2869 */

/* function stream2mmio_unit_test: C47 */

/* function ia_css_thread_sp_run: 1401 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_pipe_start_sem
#define HIVE_MEM_ia_css_thread_sp_pipe_start_sem scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_pipe_start_sem 0x4540
#define HIVE_SIZE_ia_css_thread_sp_pipe_start_sem 80
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_pipe_start_sem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_pipe_start_sem 0x4540
#define HIVE_SIZE_sp_ia_css_thread_sp_pipe_start_sem 80

/* function sp_isys_copy_func: 5A0 */

/* function register_isr: 6E9 */

/* function irq_raise: BD */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 24BF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_elems_frames_preview_pipe
#define HIVE_MEM_cb_elems_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_elems_frames_preview_pipe 0x43AC
#define HIVE_SIZE_cb_elems_frames_preview_pipe 16
#else
#endif
#endif
#define HIVE_MEM_sp_cb_elems_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_elems_frames_preview_pipe 0x43AC
#define HIVE_SIZE_sp_cb_elems_frames_preview_pipe 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_frames_preview_pipe
#define HIVE_MEM_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_frames_preview_pipe 0x43BC
#define HIVE_SIZE_cb_frames_preview_pipe 20
#else
#endif
#endif
#define HIVE_MEM_sp_cb_frames_preview_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_frames_preview_pipe 0x43BC
#define HIVE_SIZE_sp_cb_frames_preview_pipe 20

/* function pipeline_sp_initialize_stage: 1974 */

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 5146 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cb_elems_frames_capture_pipe
#define HIVE_MEM_cb_elems_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_cb_elems_frames_capture_pipe 0x43D0
#define HIVE_SIZE_cb_elems_frames_capture_pipe 16
#else
#endif
#endif
#define HIVE_MEM_sp_cb_elems_frames_capture_pipe scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cb_elems_frames_capture_pipe 0x43D0
#define HIVE_SIZE_sp_cb_elems_frames_capture_pipe 16

/* function ia_css_ispctrl_sp_done_ds: 2A84 */

/* function csi_rx_backend_config: A00 */

/* function ia_css_parambuf_sp_init_buffer_queues: 16E3 */

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
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x524C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 48
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x524C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 48

/* function ia_css_ispctrl_sp_init_isp_vars: 37EC */

/* function ia_css_rmgr_sp_vbuf_enqueue: 4936 */

/* function ia_css_tagger_sp_tag_exp_id: 1D2E */

/* function ia_css_dmaproxy_sp_write: 26AD */

/* function ia_css_parambuf_sp_release_in_param: 1531 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x35A4
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x35A4
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_addresses 0x55BC
#define HIVE_SIZE_sp_isp_addresses 184
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x55BC
#define HIVE_SIZE_sp_sp_isp_addresses 184

/* function ia_css_rmgr_sp_acq_gen: 4871 */

/* function input_system_input_port_open: EC2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isps
#define HIVE_MEM_isps scalar_processor_2400_dmem
#define HIVE_ADDR_isps 0x59D8
#define HIVE_SIZE_isps 28
#else
#endif
#endif
#define HIVE_MEM_sp_isps scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isps 0x59D8
#define HIVE_SIZE_sp_isps 28

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x414C
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x414C
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_buf_swap
#define HIVE_MEM_ia_css_ispctrl_sp_buf_swap scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_buf_swap 0x34D4
#define HIVE_SIZE_ia_css_ispctrl_sp_buf_swap 96
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_buf_swap scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_buf_swap 0x34D4
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_buf_swap 96

/* function ia_css_circbuf_sp_push_unmarked: 100C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x5348
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x5348
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_bufq_sp_release_dynamic_buf: 228D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_cropping_a 0x534C
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_cropping_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_cropping_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 0x534C
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_cropping_a 4

/* function ia_css_dmaproxy_sp_set_height_exception: 2764 */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 2732 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x43FC
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x43FC
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 267F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_spref
#define HIVE_MEM_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_spref 0x300
#define HIVE_SIZE_vbuf_spref 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_spref 0x300
#define HIVE_SIZE_sp_vbuf_spref 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_request
#define HIVE_MEM_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_request 0x45B0
#define HIVE_SIZE_ia_css_flash_sp_request 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_request 0x45B0
#define HIVE_SIZE_sp_ia_css_flash_sp_request 4

/* function ia_css_dmaproxy_sp_vmem_write: 2639 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_sdis_horicoef_vectors
#define HIVE_MEM_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_isp_sdis_horicoef_vectors 0x5350
#define HIVE_SIZE_isp_sdis_horicoef_vectors 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_sdis_horicoef_vectors scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_sdis_horicoef_vectors 0x5350
#define HIVE_SIZE_sp_isp_sdis_horicoef_vectors 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_if
#define HIVE_MEM_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_if 0x43E0
#define HIVE_SIZE_sem_for_reading_if 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_if 0x43E0
#define HIVE_SIZE_sp_sem_for_reading_if 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_pipe_stop
#define HIVE_MEM_ia_css_thread_sp_pipe_stop scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_pipe_stop 0x4590
#define HIVE_SIZE_ia_css_thread_sp_pipe_stop 16
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_pipe_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_pipe_stop 0x4590
#define HIVE_SIZE_sp_ia_css_thread_sp_pipe_stop 16

/* function sp_generate_interrupts: 6F1 */

/* function ia_css_pipeline_sp_start: 193C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_data 0x56BC
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_data 0x56BC
#define HIVE_SIZE_sp_sp_data 640

/* function input_system_input_port_configure: F0B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0x310
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0x310
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x527C
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_sp2host_buf_queues 160
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x527C
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 160

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_mem_map 0x4150
#define HIVE_SIZE_mem_map 264
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x4150
#define HIVE_SIZE_sp_mem_map 264

/* function isys2401_dma_config_legacy: C25 */

/* function sp_init_dmem: 514 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf
#define HIVE_MEM_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_ref_out_buf 0x5354
#define HIVE_SIZE_ia_css_ispctrl_sp_ref_out_buf 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_ref_out_buf scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_ref_out_buf 0x5354
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_ref_out_buf 4

/* function thread_sp_queue_print: 141E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a
#define HIVE_MEM_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_dma_crop_block_width_a 0x5358
#define HIVE_SIZE_ia_css_ispctrl_sp_dma_crop_block_width_a 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_dma_crop_block_width_a scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 0x5358
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_dma_crop_block_width_a 4

/* function ia_css_bufq_sp_acquire_dynamic_buf: 23F3 */

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
#ifndef HIVE_MEM_isp_vf_output_width_vecs
#define HIVE_MEM_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_isp_vf_output_width_vecs 0x535C
#define HIVE_SIZE_isp_vf_output_width_vecs 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_vf_output_width_vecs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_vf_output_width_vecs 0x535C
#define HIVE_SIZE_sp_isp_vf_output_width_vecs 4

/* function ia_css_rmgr_sp_refcount_release_vbuf: 494F */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_use
#define HIVE_MEM_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_use 0x45B4
#define HIVE_SIZE_ia_css_flash_sp_in_use 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_use 0x45B4
#define HIVE_SIZE_sp_ia_css_flash_sp_in_use 4

/* function ia_css_thread_sem_sp_wait: 4DC2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sleep_mode 0x4258
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x4258
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: C8 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stop_req
#define HIVE_MEM_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stop_req 0x425C
#define HIVE_SIZE_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stop_req 0x425C
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
  sh_css_print("sp_group.config.is_offline ="
    "                              0x%x\n",
    sp_group.config.is_offline);
  sh_css_print("sp_group.config.input_needs_raw_binning ="
    "                 0x%x\n",
    sp_group.config.input_needs_raw_binning);
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
  sh_css_print("sp_group.pipe[0].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[0].input_system_mode);
  sh_css_print("sp_group.pipe[0].port_id ="
    "                                0x%x\n",
    sp_group.pipe[0].port_id);
  sh_css_print("sp_group.pipe[0].is_pipemodecopy ="
    "                        0x%x\n",
    sp_group.pipe[0].is_pipemodecopy);
  sh_css_print("sp_group.pipe[0].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[0].num_stages);
  sh_css_print("sp_group.pipe[0].running ="
    "                                0x%x\n",
    sp_group.pipe[0].running);
  sh_css_print("sp_group.pipe[0].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[0].dvs_frame_delay);
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
  sh_css_print("sp_group.pipe[0].acc_num_execs ="
    "                          0x%x\n",
    sp_group.pipe[0].acc_num_execs);
  sh_css_print("sp_group.pipe[0].process_metadata ="
    "                       0x%x\n",
    sp_group.pipe[0].process_metadata);
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
  sh_css_print("sp_group.pipe[1].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[1].input_system_mode);
  sh_css_print("sp_group.pipe[1].port_id ="
    "                                0x%x\n",
    sp_group.pipe[1].port_id);
  sh_css_print("sp_group.pipe[1].is_pipemodecopy ="
    "                        0x%x\n",
    sp_group.pipe[1].is_pipemodecopy);
  sh_css_print("sp_group.pipe[1].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[1].num_stages);
  sh_css_print("sp_group.pipe[1].running ="
    "                                0x%x\n",
    sp_group.pipe[1].running);
  sh_css_print("sp_group.pipe[1].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[1].dvs_frame_delay);
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
  sh_css_print("sp_group.pipe[1].acc_num_execs ="
    "                          0x%x\n",
    sp_group.pipe[1].acc_num_execs);
  sh_css_print("sp_group.pipe[1].process_metadata ="
    "                       0x%x\n",
    sp_group.pipe[1].process_metadata);
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
  sh_css_print("sp_group.pipe[2].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[2].input_system_mode);
  sh_css_print("sp_group.pipe[2].port_id ="
    "                                0x%x\n",
    sp_group.pipe[2].port_id);
  sh_css_print("sp_group.pipe[2].is_pipemodecopy ="
    "                        0x%x\n",
    sp_group.pipe[2].is_pipemodecopy);
  sh_css_print("sp_group.pipe[2].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[2].num_stages);
  sh_css_print("sp_group.pipe[2].running ="
    "                                0x%x\n",
    sp_group.pipe[2].running);
  sh_css_print("sp_group.pipe[2].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[2].dvs_frame_delay);
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
  sh_css_print("sp_group.pipe[2].acc_num_execs ="
    "                          0x%x\n",
    sp_group.pipe[2].acc_num_execs);
  sh_css_print("sp_group.pipe[2].process_metadata ="
    "                       0x%x\n",
    sp_group.pipe[2].process_metadata);
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
  sh_css_print("sp_group.pipe[3].input_system_mode ="
    "                      0x%x\n",
    sp_group.pipe[3].input_system_mode);
  sh_css_print("sp_group.pipe[3].port_id ="
    "                                0x%x\n",
    sp_group.pipe[3].port_id);
  sh_css_print("sp_group.pipe[3].is_pipemodecopy ="
    "                        0x%x\n",
    sp_group.pipe[3].is_pipemodecopy);
  sh_css_print("sp_group.pipe[3].num_stages ="
    "                             0x%x\n",
    sp_group.pipe[3].num_stages);
  sh_css_print("sp_group.pipe[3].running ="
    "                                0x%x\n",
    sp_group.pipe[3].running);
  sh_css_print("sp_group.pipe[3].dvs_frame_delay ="
    "                        0x%x\n",
    sp_group.pipe[3].dvs_frame_delay);
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
  sh_css_print("sp_group.pipe[3].acc_num_execs ="
    "                          0x%x\n",
    sp_group.pipe[3].acc_num_execs);
  sh_css_print("sp_group.pipe[3].process_metadata ="
    "                       0x%x\n",
    sp_group.pipe[3].process_metadata);
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
  sh_css_print("mem_map.xnr_tbl ="
    "                                         0x%x\n",
    mem_map.xnr_tbl);
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
  sh_css_print("mem_map.r_gamma_tbl ="
    "                                     0x%x\n",
    mem_map.r_gamma_tbl);
  sh_css_print("mem_map.g_gamma_tbl ="
    "                                     0x%x\n",
    mem_map.g_gamma_tbl);
  sh_css_print("mem_map.b_gamma_tbl ="
    "                                     0x%x\n",
    mem_map.b_gamma_tbl);
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
