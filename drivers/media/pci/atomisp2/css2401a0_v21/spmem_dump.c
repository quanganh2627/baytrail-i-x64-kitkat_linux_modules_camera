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

/* function longjmp: 63C9 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_buff_pool_lock_frame_handles
#define HIVE_MEM_raw_buff_pool_lock_frame_handles scalar_processor_2400_dmem
#define HIVE_ADDR_raw_buff_pool_lock_frame_handles 0x72C8
#define HIVE_SIZE_raw_buff_pool_lock_frame_handles 60
#else
#endif
#endif
#define HIVE_MEM_sp_raw_buff_pool_lock_frame_handles scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_buff_pool_lock_frame_handles 0x72C8
#define HIVE_SIZE_sp_raw_buff_pool_lock_frame_handles 60

/* function ia_css_dmaproxy_sp_set_addr_B: 372F */

/* function debug_buffer_set_ddr_addr: EE */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_mipi
#define HIVE_MEM_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_mipi 0x73D0
#define HIVE_SIZE_vbuf_mipi 12
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_mipi scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_mipi 0x73D0
#define HIVE_SIZE_sp_vbuf_mipi 12

/* function ia_css_event_sp_decode: 3929 */

/* function ia_css_queue_get_size: 4D43 */

/* function ia_css_queue_load: 5403 */

/* function setjmp: 63D2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x7304
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_cp_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 0x7304
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_cp_fr_ct 4

/* function __dmaproxy_sp_read_write_text: 3847 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp2host_isys_event_queue
#define HIVE_MEM_sem_for_sp2host_isys_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp2host_isys_event_queue 0x570C
#define HIVE_SIZE_sem_for_sp2host_isys_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp2host_isys_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp2host_isys_event_queue 0x570C
#define HIVE_SIZE_sp_sem_for_sp2host_isys_event_queue 20

/* function ia_css_dmaproxy_sp_wait_for_ack: 6A18 */

/* function ia_css_tagger_buf_sp_pop_marked: 2E9C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_CSI_RX_BE_SID_WIDTH
#define HIVE_MEM_N_CSI_RX_BE_SID_WIDTH scalar_processor_2400_dmem
#define HIVE_ADDR_N_CSI_RX_BE_SID_WIDTH 0x1C8
#define HIVE_SIZE_N_CSI_RX_BE_SID_WIDTH 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_CSI_RX_BE_SID_WIDTH scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_CSI_RX_BE_SID_WIDTH 0x1C8
#define HIVE_SIZE_sp_N_CSI_RX_BE_SID_WIDTH 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stage
#define HIVE_MEM_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stage 0x6C48
#define HIVE_SIZE_isp_stage 824
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stage scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stage 0x6C48
#define HIVE_SIZE_sp_isp_stage 824

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_raw
#define HIVE_MEM_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_raw 0x364
#define HIVE_SIZE_vbuf_raw 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_raw scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_raw 0x364
#define HIVE_SIZE_sp_vbuf_raw 4

/* function ia_css_sp_bin_copy_func: 558A */

/* function ia_css_queue_item_store: 50D9 */

/* function input_system_reset: 1393 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_metadata_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_metadata_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_metadata_bufs 0x5A28
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_metadata_bufs 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_metadata_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_metadata_bufs 0x5A28
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_metadata_bufs 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_buffer_bufs 0x5A3C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_buffer_bufs 180
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_buffer_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 0x5A3C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_buffer_bufs 180

/* function sp_start_isp: 419 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_binary_group
#define HIVE_MEM_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_binary_group 0x7028
#define HIVE_SIZE_sp_binary_group 32
#else
#endif
#endif
#define HIVE_MEM_sp_sp_binary_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_binary_group 0x7028
#define HIVE_SIZE_sp_sp_binary_group 32

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sw_state
#define HIVE_MEM_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sw_state 0x737C
#define HIVE_SIZE_sp_sw_state 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sw_state scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sw_state 0x737C
#define HIVE_SIZE_sp_sp_sw_state 4

/* function ia_css_sp_is_exp_id_locked: 5A58 */

/* function ia_css_thread_sp_main: 1505 */

/* function ia_css_ispctrl_sp_init_internal_buffers: 3B70 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp2host_psys_event_queue_handle
#define HIVE_MEM_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp2host_psys_event_queue_handle 0x5AF0
#define HIVE_SIZE_sp2host_psys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_sp2host_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp2host_psys_event_queue_handle 0x5AF0
#define HIVE_SIZE_sp_sp2host_psys_event_queue_handle 12

/* function pixelgen_unit_test: FEF */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp2host_psys_event_queue
#define HIVE_MEM_sem_for_sp2host_psys_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp2host_psys_event_queue 0x5720
#define HIVE_SIZE_sem_for_sp2host_psys_event_queue 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp2host_psys_event_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp2host_psys_event_queue 0x5720
#define HIVE_SIZE_sp_sem_for_sp2host_psys_event_queue 20

/* function ibuf_ctrl_sync: DC0 */

/* function ia_css_tagger_sp_propagate_frame: 2968 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_stop_copy_preview
#define HIVE_MEM_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_stop_copy_preview 0x7308
#define HIVE_SIZE_sp_stop_copy_preview 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_stop_copy_preview scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_stop_copy_preview 0x7308
#define HIVE_SIZE_sp_sp_stop_copy_preview 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_handles
#define HIVE_MEM_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_handles 0x73DC
#define HIVE_SIZE_vbuf_handles 600
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_handles scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_handles 0x73DC
#define HIVE_SIZE_sp_vbuf_handles 600

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_max_mm_tracer
#define HIVE_MEM_max_mm_tracer scalar_processor_2400_dmem
#define HIVE_ADDR_max_mm_tracer 0x1A0
#define HIVE_SIZE_max_mm_tracer 4
#else
#endif
#endif
#define HIVE_MEM_sp_max_mm_tracer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_max_mm_tracer 0x1A0
#define HIVE_SIZE_sp_max_mm_tracer 4

/* function ia_css_queue_store: 527C */

/* function ia_css_sp_flash_register: 306A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_lock_unlock
#define HIVE_MEM_sem_for_lock_unlock scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_lock_unlock 0x730C
#define HIVE_SIZE_sem_for_lock_unlock 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_lock_unlock scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_lock_unlock 0x730C
#define HIVE_SIZE_sp_sem_for_lock_unlock 20

/* function ia_css_pipeline_sp_init: 20AB */

/* function ia_css_tagger_sp_configure: 284D */

/* function ia_css_ispctrl_sp_end_binary: 3973 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs
#define HIVE_MEM_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs 0x5AFC
#define HIVE_SIZE_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs 0x5AFC
#define HIVE_SIZE_sp_ia_css_bufq_sp_h_pipe_private_per_frame_ddr_ptrs 20

/* function ia_css_s3a_sp_get_buffer_ddr_addr: 3440 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_lace_stat_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_lace_stat_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_lace_stat_bufs 0x5B10
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_lace_stat_bufs 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_lace_stat_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_lace_stat_bufs 0x5B10
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_lace_stat_bufs 20

/* function pixelgen_tpg_run: 10A5 */

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
#ifndef HIVE_MEM_sp_all_cb_elems_frame
#define HIVE_MEM_sp_all_cb_elems_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cb_elems_frame 0x5734
#define HIVE_SIZE_sp_all_cb_elems_frame 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_frame 0x5734
#define HIVE_SIZE_sp_sp_all_cb_elems_frame 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp2host_isys_event_queue_handle
#define HIVE_MEM_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp2host_isys_event_queue_handle 0x5B24
#define HIVE_SIZE_sp2host_isys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_sp2host_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp2host_isys_event_queue_handle 0x5B24
#define HIVE_SIZE_sp_sp2host_isys_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_com
#define HIVE_MEM_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_com 0x3E28
#define HIVE_SIZE_host_sp_com 220
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_com scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_com 0x3E28
#define HIVE_SIZE_sp_host_sp_com 220

/* function ia_css_queue_get_free_space: 4E9B */

/* function exec_image_pipe: 612 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_init_dmem_data
#define HIVE_MEM_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_init_dmem_data 0x7380
#define HIVE_SIZE_sp_init_dmem_data 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_init_dmem_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_init_dmem_data 0x7380
#define HIVE_SIZE_sp_sp_init_dmem_data 24

/* function ia_css_sp_metadata_start: 5B34 */

/* function ia_css_tagger_buf_sp_is_marked: 2FB7 */

/* function ia_css_bufq_sp_init_buffer_queues: 30BB */

/* function ia_css_pipeline_sp_stop: 208E */

/* function ia_css_tagger_sp_connect_pipes: 2D38 */

/* function sp_isys_copy_wait: 670 */

/* function is_isp_debug_buffer_full: 3B2 */

/* function ia_css_dmaproxy_sp_configure_channel_from_info: 36AC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_IBUF_CTRL_PROCS
#define HIVE_MEM_N_IBUF_CTRL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_IBUF_CTRL_PROCS 0x1FC
#define HIVE_SIZE_N_IBUF_CTRL_PROCS 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_IBUF_CTRL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_IBUF_CTRL_PROCS 0x1FC
#define HIVE_SIZE_sp_N_IBUF_CTRL_PROCS 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_per_frame_data
#define HIVE_MEM_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_per_frame_data 0x3F04
#define HIVE_SIZE_sp_per_frame_data 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_per_frame_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_per_frame_data 0x3F04
#define HIVE_SIZE_sp_sp_per_frame_data 4

/* function ia_css_rmgr_sp_vbuf_dequeue: 5F5D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host2sp_psys_event_queue_handle
#define HIVE_MEM_host2sp_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_host2sp_psys_event_queue_handle 0x5B30
#define HIVE_SIZE_host2sp_psys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_host2sp_psys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host2sp_psys_event_queue_handle 0x5B30
#define HIVE_SIZE_sp_host2sp_psys_event_queue_handle 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_xmem_bin_addr
#define HIVE_MEM_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_xmem_bin_addr 0x3F08
#define HIVE_SIZE_xmem_bin_addr 4
#else
#endif
#endif
#define HIVE_MEM_sp_xmem_bin_addr scalar_processor_2400_dmem
#define HIVE_ADDR_sp_xmem_bin_addr 0x3F08
#define HIVE_SIZE_sp_xmem_bin_addr 4

/* function tmr_clock_init: B2B */

/* function ia_css_pipeline_sp_run: 1BA5 */

/* function memcpy: 6472 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_ISYS2401_DMA_CHANNEL_PROCS
#define HIVE_MEM_N_ISYS2401_DMA_CHANNEL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_ISYS2401_DMA_CHANNEL_PROCS 0x220
#define HIVE_SIZE_N_ISYS2401_DMA_CHANNEL_PROCS 4
#else
#endif
#endif
#define HIVE_MEM_sp_N_ISYS2401_DMA_CHANNEL_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_ISYS2401_DMA_CHANNEL_PROCS 0x220
#define HIVE_SIZE_sp_N_ISYS2401_DMA_CHANNEL_PROCS 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_GP_DEVICE_BASE
#define HIVE_MEM_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_GP_DEVICE_BASE 0x36C
#define HIVE_SIZE_GP_DEVICE_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_GP_DEVICE_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_GP_DEVICE_BASE 0x36C
#define HIVE_SIZE_sp_GP_DEVICE_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_ready_queue
#define HIVE_MEM_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_ready_queue 0x284
#define HIVE_SIZE_ia_css_thread_sp_ready_queue 12
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_ready_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_ready_queue 0x284
#define HIVE_SIZE_sp_ia_css_thread_sp_ready_queue 12

/* function sp_dma_proxy_set_width_ab: 3549 */

/* function ia_css_uds_sp_scale_params: 61BC */

/* function ia_css_circbuf_increase_size: 15EA */

/* function __divu: 63F0 */

/* function ia_css_thread_sp_get_state: 142D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_stop
#define HIVE_MEM_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_stop 0x5744
#define HIVE_SIZE_sem_for_cont_capt_stop 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_stop scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_stop 0x5744
#define HIVE_SIZE_sp_sem_for_cont_capt_stop 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_SHORT_PACKET_LUT_ENTRIES
#define HIVE_MEM_N_SHORT_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_N_SHORT_PACKET_LUT_ENTRIES 0x1A4
#define HIVE_SIZE_N_SHORT_PACKET_LUT_ENTRIES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_SHORT_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_SHORT_PACKET_LUT_ENTRIES 0x1A4
#define HIVE_SIZE_sp_N_SHORT_PACKET_LUT_ENTRIES 12

/* function thread_fiber_sp_main: 15E3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_pipe_thread
#define HIVE_MEM_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_pipe_thread 0x5874
#define HIVE_SIZE_sp_isp_pipe_thread 340
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_pipe_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_pipe_thread 0x5874
#define HIVE_SIZE_sp_sp_isp_pipe_thread 340

/* function ia_css_parambuf_sp_handle_parameter_sets: 1A41 */

/* function ia_css_spctrl_sp_set_state: 5B50 */

/* function ia_css_thread_sem_sp_signal: 6666 */

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

/* function ia_css_virtual_isys_sp_isr_init: 5BE1 */

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

/* function ia_css_isys_sp_generate_exp_id: 5E31 */

/* function ia_css_rmgr_sp_init: 5E4C */

/* function ia_css_thread_sem_sp_init: 6739 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_is_isp_requested
#define HIVE_MEM_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_is_isp_requested 0x378
#define HIVE_SIZE_is_isp_requested 4
#else
#endif
#endif
#define HIVE_MEM_sp_is_isp_requested scalar_processor_2400_dmem
#define HIVE_ADDR_sp_is_isp_requested 0x378
#define HIVE_SIZE_sp_is_isp_requested 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_frame
#define HIVE_MEM_sem_for_reading_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_frame 0x5758
#define HIVE_SIZE_sem_for_reading_cb_frame 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_frame 0x5758
#define HIVE_SIZE_sp_sem_for_reading_cb_frame 40

/* function ia_css_dmaproxy_sp_execute: 3604 */

/* function csi_rx_backend_rst: D15 */

/* function ia_css_queue_is_empty: 4D7E */

/* function ia_css_pipeline_sp_has_stopped: 2084 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_verbosity
#define HIVE_MEM_verbosity scalar_processor_2400_dmem
#define HIVE_ADDR_verbosity 0x2500
#define HIVE_SIZE_verbosity 4
#else
#endif
#endif
#define HIVE_MEM_sp_verbosity scalar_processor_2400_dmem
#define HIVE_ADDR_sp_verbosity 0x2500
#define HIVE_SIZE_sp_verbosity 4

/* function ia_css_circbuf_extract: 16E4 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_sp_thread
#define HIVE_MEM_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_current_sp_thread 0x280
#define HIVE_SIZE_current_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_sp_thread 0x280
#define HIVE_SIZE_sp_current_sp_thread 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_cur_co_fr_ct 0x7320
#define HIVE_SIZE_ia_css_rawcopy_sp_cur_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_cur_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_cur_co_fr_ct 0x7320
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_cur_co_fr_ct 4

/* function ia_css_spctrl_sp_get_spid: 5B57 */

/* function ia_css_dmaproxy_sp_read_byte_addr: 6A49 */

/* function ia_css_rmgr_sp_uninit: 5E45 */

/* function ia_css_virtual_isys_sync_all: 5C05 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack
#define HIVE_MEM_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_stack 0x150
#define HIVE_SIZE_sp_threads_stack 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_stack 0x150
#define HIVE_SIZE_sp_sp_threads_stack 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_STREAM2MMIO_SID_PROCS
#define HIVE_MEM_N_STREAM2MMIO_SID_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_N_STREAM2MMIO_SID_PROCS 0x224
#define HIVE_SIZE_N_STREAM2MMIO_SID_PROCS 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_STREAM2MMIO_SID_PROCS scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_STREAM2MMIO_SID_PROCS 0x224
#define HIVE_SIZE_sp_N_STREAM2MMIO_SID_PROCS 12

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_trace_buffer_sp
#define HIVE_MEM_trace_buffer_sp scalar_processor_2400_dmem
#define HIVE_ADDR_trace_buffer_sp 0x19C
#define HIVE_SIZE_trace_buffer_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_trace_buffer_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_trace_buffer_sp 0x19C
#define HIVE_SIZE_sp_trace_buffer_sp 4

/* function ia_css_sp_unlock_raw_buff: 59A0 */

/* function ia_css_circbuf_peek: 16C3 */

/* function ia_css_parambuf_sp_wait_for_in_param: 17F3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cb_elems_param
#define HIVE_MEM_sp_all_cb_elems_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cb_elems_param 0x5780
#define HIVE_SIZE_sp_all_cb_elems_param 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cb_elems_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cb_elems_param 0x5780
#define HIVE_SIZE_sp_sp_all_cb_elems_param 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_pipeline_sp_curr_binary_id
#define HIVE_MEM_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_pipeline_sp_curr_binary_id 0x290
#define HIVE_SIZE_pipeline_sp_curr_binary_id 4
#else
#endif
#endif
#define HIVE_MEM_sp_pipeline_sp_curr_binary_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipeline_sp_curr_binary_id 0x290
#define HIVE_SIZE_sp_pipeline_sp_curr_binary_id 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_frame_desc
#define HIVE_MEM_sp_all_cbs_frame_desc scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_frame_desc 0x5790
#define HIVE_SIZE_sp_all_cbs_frame_desc 8
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_frame_desc scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_frame_desc 0x5790
#define HIVE_SIZE_sp_sp_all_cbs_frame_desc 8

/* function sp_isys_copy_func_v2: 655 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_cb_param
#define HIVE_MEM_sem_for_reading_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_cb_param 0x5798
#define HIVE_SIZE_sem_for_reading_cb_param 40
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_cb_param 0x5798
#define HIVE_SIZE_sp_sem_for_reading_cb_param 40

/* function ia_css_queue_get_used_space: 4E4D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_cont_capt_start
#define HIVE_MEM_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_cont_capt_start 0x57C0
#define HIVE_SIZE_sem_for_cont_capt_start 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_cont_capt_start scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_cont_capt_start 0x57C0
#define HIVE_SIZE_sp_sem_for_cont_capt_start 20

/* function ia_css_tagger_buf_sp_mark: 3043 */

/* function ia_css_ispctrl_sp_output_compute_dma_info: 4302 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_s3a_bufs 0x5B3C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_s3a_bufs 60
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_s3a_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 0x5B3C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_s3a_bufs 60

/* function ia_css_queue_is_full: 4EEA */

/* function debug_buffer_init_isp: FB */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem
#define HIVE_MEM_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rmgr_sp_mipi_frame_sem 0x7634
#define HIVE_SIZE_ia_css_rmgr_sp_mipi_frame_sem 60
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rmgr_sp_mipi_frame_sem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rmgr_sp_mipi_frame_sem 0x7634
#define HIVE_SIZE_sp_ia_css_rmgr_sp_mipi_frame_sem 60

/* function ia_css_sp_raw_copy_func: 5591 */

/* function ia_css_rmgr_sp_refcount_dump: 5F38 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_isp_parameters_id
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_isp_parameters_id scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_isp_parameters_id 0x5B78
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_isp_parameters_id 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_isp_parameters_id scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_isp_parameters_id 0x5B78
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_isp_parameters_id 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_pipe_threads
#define HIVE_MEM_sp_pipe_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_pipe_threads 0x13C
#define HIVE_SIZE_sp_pipe_threads 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_pipe_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_pipe_threads 0x13C
#define HIVE_SIZE_sp_sp_pipe_threads 20

/* function sp_event_proxy_func: 796 */

/* function ibuf_ctrl_run: E10 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host2sp_isys_event_queue_handle
#define HIVE_MEM_host2sp_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_host2sp_isys_event_queue_handle 0x5B8C
#define HIVE_SIZE_host2sp_isys_event_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_host2sp_isys_event_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host2sp_isys_event_queue_handle 0x5B8C
#define HIVE_SIZE_sp_host2sp_isys_event_queue_handle 12

/* function ia_css_thread_sp_yield: 65DC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_param_desc
#define HIVE_MEM_sp_all_cbs_param_desc scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_param_desc 0x57D4
#define HIVE_SIZE_sp_all_cbs_param_desc 8
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_param_desc scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_param_desc 0x57D4
#define HIVE_SIZE_sp_sp_all_cbs_param_desc 8

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb
#define HIVE_MEM_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb 0x6C3C
#define HIVE_SIZE_ia_css_dmaproxy_sp_invalidate_tlb 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_sp_invalidate_tlb scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_sp_invalidate_tlb 0x6C3C
#define HIVE_SIZE_sp_ia_css_dmaproxy_sp_invalidate_tlb 4

/* function ia_css_thread_sp_fork: 14BA */

/* function ia_css_tagger_sp_destroy: 2D42 */

/* function ia_css_dmaproxy_sp_vmem_read: 358D */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_LONG_PACKET_LUT_ENTRIES
#define HIVE_MEM_N_LONG_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_N_LONG_PACKET_LUT_ENTRIES 0x1B0
#define HIVE_SIZE_N_LONG_PACKET_LUT_ENTRIES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_LONG_PACKET_LUT_ENTRIES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_LONG_PACKET_LUT_ENTRIES 0x1B0
#define HIVE_SIZE_sp_N_LONG_PACKET_LUT_ENTRIES 12

/* function initialize_sp_group: 622 */

/* function ia_css_thread_sp_init: 14E6 */

/* function ia_css_ispctrl_sp_set_stream_base_addr: 4AC8 */

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

/* function ibuf_ctrl_transfer: DD2 */

/* function ia_css_dmaproxy_sp_read: 3625 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_copy_line_count
#define HIVE_MEM_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_raw_copy_line_count 0x348
#define HIVE_SIZE_raw_copy_line_count 4
#else
#endif
#endif
#define HIVE_MEM_sp_raw_copy_line_count scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_copy_line_count 0x348
#define HIVE_SIZE_sp_raw_copy_line_count 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host2sp_tag_cmd_queue_handle
#define HIVE_MEM_host2sp_tag_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_host2sp_tag_cmd_queue_handle 0x5B98
#define HIVE_SIZE_host2sp_tag_cmd_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_host2sp_tag_cmd_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host2sp_tag_cmd_queue_handle 0x5B98
#define HIVE_SIZE_sp_host2sp_tag_cmd_queue_handle 12

/* function ia_css_queue_peek: 4DC2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_frame_cnt
#define HIVE_MEM_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_frame_cnt 0x5A1C
#define HIVE_SIZE_ia_css_flash_sp_frame_cnt 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_frame_cnt scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_frame_cnt 0x5A1C
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

/* function ia_css_lace_stat_sp_get_buffer_ddr_addr: 3439 */

/* function csi_rx_frontend_stop: C1E */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_started
#define HIVE_MEM_started scalar_processor_2400_dmem
#define HIVE_ADDR_started 0x24FC
#define HIVE_SIZE_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_started 0x24FC
#define HIVE_SIZE_sp_started 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_thread
#define HIVE_MEM_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_isp_thread 0x6F80
#define HIVE_SIZE_isp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_thread 0x6F80
#define HIVE_SIZE_sp_isp_thread 4

/* function is_ddr_debug_buffer_full: 334 */

/* function sp_dma_proxy_isp_write_addr: 35A5 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_fiber
#define HIVE_MEM_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_fiber 0x180
#define HIVE_SIZE_sp_threads_fiber 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_fiber scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_fiber 0x180
#define HIVE_SIZE_sp_sp_threads_fiber 24

/* function encode_and_post_sp_event: AD0 */

/* function debug_enqueue_ddr: 10A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host2sp_unlock_raw_buff_msg_queue_handle
#define HIVE_MEM_host2sp_unlock_raw_buff_msg_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_host2sp_unlock_raw_buff_msg_queue_handle 0x5BA4
#define HIVE_SIZE_host2sp_unlock_raw_buff_msg_queue_handle 12
#else
#endif
#endif
#define HIVE_MEM_sp_host2sp_unlock_raw_buff_msg_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host2sp_unlock_raw_buff_msg_queue_handle 0x5BA4
#define HIVE_SIZE_sp_host2sp_unlock_raw_buff_msg_queue_handle 12

/* function ia_css_rmgr_sp_refcount_init_vbuf: 5EF3 */

/* function dmaproxy_sp_read_write: 6AEA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer
#define HIVE_MEM_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_dmaproxy_isp_dma_cmd_buffer 0x6C40
#define HIVE_SIZE_ia_css_dmaproxy_isp_dma_cmd_buffer 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_dmaproxy_isp_dma_cmd_buffer scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 0x6C40
#define HIVE_SIZE_sp_ia_css_dmaproxy_isp_dma_cmd_buffer 4

/* function ia_css_dmaproxy_sp_ack: 6761 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host2sp_buffer_queue_handle
#define HIVE_MEM_host2sp_buffer_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_host2sp_buffer_queue_handle 0x5BB0
#define HIVE_SIZE_host2sp_buffer_queue_handle 540
#else
#endif
#endif
#define HIVE_MEM_sp_host2sp_buffer_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host2sp_buffer_queue_handle 0x5BB0
#define HIVE_SIZE_sp_host2sp_buffer_queue_handle 540

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_service
#define HIVE_MEM_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_service 0x30C0
#define HIVE_SIZE_ia_css_flash_sp_in_service 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_service scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_service 0x30C0
#define HIVE_SIZE_sp_ia_css_flash_sp_in_service 4

/* function ia_css_dmaproxy_sp_process: 6790 */

/* function ia_css_ispctrl_sp_init_cs: 3A79 */

/* function ia_css_spctrl_sp_init: 5B65 */

/* function sp_event_proxy_init: 7AB */

/* function input_system_input_port_close: 1222 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_output
#define HIVE_MEM_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_output 0x3F0C
#define HIVE_SIZE_sp_output 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_output scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_output 0x3F0C
#define HIVE_SIZE_sp_sp_output 16

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x5DCC
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_host2sp_buf_queues 900
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 0x5DCC
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_host2sp_buf_queues 900

/* function pixelgen_prbs_config: 101A */

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

/* function sp_dma_proxy_reset_channels: 388D */

/* function ia_css_tagger_sp_update_size: 2DAC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_host_sp_queue
#define HIVE_MEM_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_host_sp_queue 0x6150
#define HIVE_SIZE_ia_css_bufq_host_sp_queue 1976
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_host_sp_queue scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_host_sp_queue 0x6150
#define HIVE_SIZE_sp_ia_css_bufq_host_sp_queue 1976

/* function thread_fiber_sp_create: 1552 */

/* function ia_css_dmaproxy_sp_set_increments: 371A */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_frame
#define HIVE_MEM_sem_for_writing_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_frame 0x57DC
#define HIVE_SIZE_sem_for_writing_cb_frame 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_frame 0x57DC
#define HIVE_SIZE_sp_sem_for_writing_cb_frame 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_writing_cb_param
#define HIVE_MEM_sem_for_writing_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_writing_cb_param 0x57F0
#define HIVE_SIZE_sem_for_writing_cb_param 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_writing_cb_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_writing_cb_param 0x57F0
#define HIVE_SIZE_sp_sem_for_writing_cb_param 20

/* function pixelgen_tpg_is_done: 1094 */

/* function ia_css_isys_stream_capture_indication: 5CD4 */

/* function sp_start_isp_entry: 40F */
#ifndef HIVE_MULTIPLE_PROGRAMS
#ifdef HIVE_ADDR_sp_start_isp_entry
#endif
#define HIVE_ADDR_sp_start_isp_entry 0x40F
#endif
#define HIVE_ADDR_sp_sp_start_isp_entry 0x40F

/* function ia_css_tagger_buf_sp_unmark_all: 2FDB */

/* function ia_css_dmaproxy_sp_channel_acquire: 38BC */

/* function ia_css_rmgr_sp_add_num_vbuf: 6126 */

/* function ibuf_ctrl_config: E30 */

/* function ia_css_isys_stream_stop: 5D4C */

/* function __ia_css_dmaproxy_sp_wait_for_ack_text: 3540 */

/* function ia_css_tagger_buf_sp_push_marked: 2F11 */

/* function ia_css_bufq_sp_is_dynamic_buffer: 3418 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_group
#define HIVE_MEM_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_group 0x3F20
#define HIVE_SIZE_sp_group 6120
#else
#endif
#endif
#define HIVE_MEM_sp_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_group 0x3F20
#define HIVE_SIZE_sp_sp_group 6120

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_event_proxy_thread
#define HIVE_MEM_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_proxy_thread 0x59C8
#define HIVE_SIZE_sp_event_proxy_thread 68
#else
#endif
#endif
#define HIVE_MEM_sp_sp_event_proxy_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_event_proxy_thread 0x59C8
#define HIVE_SIZE_sp_sp_event_proxy_thread 68

/* function ia_css_thread_sp_kill: 1480 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_cur_loc
#define HIVE_MEM_cur_loc scalar_processor_2400_dmem
#define HIVE_ADDR_cur_loc 0x24F4
#define HIVE_SIZE_cur_loc 4
#else
#endif
#endif
#define HIVE_MEM_sp_cur_loc scalar_processor_2400_dmem
#define HIVE_ADDR_sp_cur_loc 0x24F4
#define HIVE_SIZE_sp_cur_loc 4

/* function ia_css_tagger_sp_create: 2D63 */

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

/* function ia_css_dmaproxy_sp_channel_release: 38A5 */

/* function pixelgen_prbs_run: 1008 */

/* function ia_css_dmaproxy_sp_is_idle: 3878 */

/* function isp_hmem_load: B6B */

/* function ia_css_eventq_sp_send: 3901 */

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

/* function sp_isys_copy_request: 6F5 */

/* function ia_css_rmgr_sp_refcount_retain_vbuf: 5FC3 */

/* function ia_css_thread_sp_set_priority: 1478 */

/* function sizeof_hmem: C16 */

/* function input_system_channel_open: 1356 */

/* function pixelgen_tpg_stop: 1082 */

/* function __ia_css_dmaproxy_sp_process_text: 348C */

/* function ia_css_dmaproxy_sp_set_width_exception: 3704 */

/* function ia_css_flash_sp_init_internal_params: 30B0 */

/* function ia_css_tagger_buf_sp_pop_unmarked_and_unlocked: 2DD1 */

/* function sp_generate_events: 9E4 */

/* function __modu: 6436 */

/* function ia_css_dmaproxy_sp_init_isp_vector: 355F */

/* function input_system_channel_transfer: 133F */

/* function isp_vamem_store: 0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_counter
#define HIVE_MEM_counter scalar_processor_2400_dmem
#define HIVE_ADDR_counter 0x24F8
#define HIVE_SIZE_counter 2
#else
#endif
#endif
#define HIVE_MEM_sp_counter scalar_processor_2400_dmem
#define HIVE_ADDR_sp_counter 0x24F8
#define HIVE_SIZE_sp_counter 2

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_major_masks
#define HIVE_MEM_major_masks scalar_processor_2400_dmem
#define HIVE_ADDR_major_masks 0x198
#define HIVE_SIZE_major_masks 4
#else
#endif
#endif
#define HIVE_MEM_sp_major_masks scalar_processor_2400_dmem
#define HIVE_ADDR_sp_major_masks 0x198
#define HIVE_SIZE_sp_major_masks 4

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

/* function ia_css_queue_local_init: 50B3 */

/* function sp_event_proxy_callout_func: 6503 */

/* function ia_css_dmaproxy_sp_deregister_channel_from_port: 3527 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_thread_sp_num_ready_threads
#define HIVE_MEM_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_thread_sp_num_ready_threads 0x5A10
#define HIVE_SIZE_ia_css_thread_sp_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_thread_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_thread_sp_num_ready_threads 0x5A10
#define HIVE_SIZE_sp_ia_css_thread_sp_num_ready_threads 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_threads_stack_size
#define HIVE_MEM_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_threads_stack_size 0x168
#define HIVE_SIZE_sp_threads_stack_size 24
#else
#endif
#endif
#define HIVE_MEM_sp_sp_threads_stack_size scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_threads_stack_size 0x168
#define HIVE_SIZE_sp_sp_threads_stack_size 24

/* function ia_css_ispctrl_sp_isp_done_row_striping: 42E8 */

/* function __ia_css_virtual_isys_sp_isr_text: 5BA4 */

/* function ia_css_queue_dequeue: 4F32 */

/* function ia_css_dmaproxy_sp_configure_channel: 6A60 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_current_thread_fiber_sp
#define HIVE_MEM_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_current_thread_fiber_sp 0x5A18
#define HIVE_SIZE_current_thread_fiber_sp 4
#else
#endif
#endif
#define HIVE_MEM_sp_current_thread_fiber_sp scalar_processor_2400_dmem
#define HIVE_ADDR_sp_current_thread_fiber_sp 0x5A18
#define HIVE_SIZE_sp_current_thread_fiber_sp 4

/* function ia_css_circbuf_pop: 177C */

/* function memset: 64B5 */

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

/* function pixelgen_prbs_stop: FF6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_ph
#define HIVE_MEM_isp_ph scalar_processor_2400_dmem
#define HIVE_ADDR_isp_ph 0x7398
#define HIVE_SIZE_isp_ph 28
#else
#endif
#endif
#define HIVE_MEM_sp_isp_ph scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_ph 0x7398
#define HIVE_SIZE_sp_isp_ph 28

/* function ia_css_ispctrl_sp_init_ds: 3C17 */

/* function get_xmem_base_addr_raw: 3F7B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_param
#define HIVE_MEM_sp_all_cbs_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_param 0x5804
#define HIVE_SIZE_sp_all_cbs_param 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_param scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_param 0x5804
#define HIVE_SIZE_sp_sp_all_cbs_param 16

/* function pixelgen_tpg_config: 10B7 */

/* function ia_css_circbuf_create: 17C6 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct
#define HIVE_MEM_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tgt_co_fr_ct 0x7324
#define HIVE_SIZE_ia_css_rawcopy_sp_tgt_co_fr_ct 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tgt_co_fr_ct scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 0x7324
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tgt_co_fr_ct 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_sp_group
#define HIVE_MEM_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_sp_group 0x5814
#define HIVE_SIZE_sem_for_sp_group 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_sp_group scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_sp_group 0x5814
#define HIVE_SIZE_sp_sem_for_sp_group 20

/* function csi_rx_frontend_run: C2F */

/* function ia_css_framebuf_sp_wait_for_in_frame: 614A */

/* function ia_css_tagger_buf_sp_push_unmarked: 2E44 */

/* function ia_css_isys_stream_open: 5DE0 */

/* function input_system_channel_configure: 136A */

/* function isp_hmem_clear: B32 */

/* function ia_css_framebuf_sp_release_in_frame: 618D */

/* function stream2mmio_config: FA2 */

/* function ia_css_ispctrl_sp_start_binary: 3A57 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs
#define HIVE_MEM_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x6908
#define HIVE_SIZE_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 0x6908
#define HIVE_SIZE_sp_ia_css_bufq_sp_h_pipe_private_ddr_ptrs 20

/* function ia_css_eventq_sp_recv: 38D3 */

/* function csi_rx_frontend_config: C87 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_pool
#define HIVE_MEM_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_isp_pool 0x358
#define HIVE_SIZE_isp_pool 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_pool scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_pool 0x358
#define HIVE_SIZE_sp_isp_pool 4

/* function ia_css_rmgr_sp_rel_gen: 5E8E */

/* function css_get_frame_processing_time_end: 27E3 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_event_any_pending_mask
#define HIVE_MEM_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_event_any_pending_mask 0x370
#define HIVE_SIZE_event_any_pending_mask 8
#else
#endif
#endif
#define HIVE_MEM_sp_event_any_pending_mask scalar_processor_2400_dmem
#define HIVE_ADDR_sp_event_any_pending_mask 0x370
#define HIVE_SIZE_sp_event_any_pending_mask 8

/* function ia_css_pipeline_sp_get_pipe_io_status: 1B9E */

/* function sh_css_decode_tag_descr: 3CD */

/* function debug_enqueue_isp: 2DF */

/* function ia_css_spctrl_sp_uninit: 5B5E */

/* function csi_rx_backend_run: C75 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dis_bufs 0x691C
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dis_bufs 140
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dis_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dis_bufs 0x691C
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dis_bufs 140

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_isp_idle
#define HIVE_MEM_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_isp_idle 0x5828
#define HIVE_SIZE_sem_for_isp_idle 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_isp_idle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_isp_idle 0x5828
#define HIVE_SIZE_sp_sem_for_isp_idle 20

/* function ia_css_dmaproxy_sp_write_byte_addr: 35D3 */

/* function ia_css_dmaproxy_sp_init: 34F9 */

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

/* function input_system_channel_sync: 132B */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_rawcopy_sp_tagger
#define HIVE_MEM_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_rawcopy_sp_tagger 0x7328
#define HIVE_SIZE_ia_css_rawcopy_sp_tagger 24
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_rawcopy_sp_tagger scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_rawcopy_sp_tagger 0x7328
#define HIVE_SIZE_sp_ia_css_rawcopy_sp_tagger 24

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_exp_ids 0x69A8
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_exp_ids 70
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_exp_ids scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_exp_ids 0x69A8
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_exp_ids 70

/* function ia_css_queue_item_load: 51C8 */

/* function ia_css_spctrl_sp_get_state: 5B49 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_callout_sp_thread
#define HIVE_MEM_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_callout_sp_thread 0x5A0C
#define HIVE_SIZE_callout_sp_thread 4
#else
#endif
#endif
#define HIVE_MEM_sp_callout_sp_thread scalar_processor_2400_dmem
#define HIVE_ADDR_sp_callout_sp_thread 0x5A0C
#define HIVE_SIZE_sp_callout_sp_thread 4

/* function thread_fiber_sp_init: 15D9 */

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
#define HIVE_ADDR_sp_isp_input_stream_format 0x3CEC
#define HIVE_SIZE_sp_isp_input_stream_format 20
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_input_stream_format scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_input_stream_format 0x3CEC
#define HIVE_SIZE_sp_sp_isp_input_stream_format 20

/* function __mod: 6422 */

/* function ia_css_dmaproxy_sp_init_dmem_channel: 363F */

/* function ia_css_thread_sp_join: 14A9 */

/* function ia_css_dmaproxy_sp_add_command: 6B2C */

/* function ia_css_sp_metadata_thread_func: 5B42 */

/* function __sp_event_proxy_func_critical: 64F0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_dmaproxy_sp_proxy_status
#define HIVE_MEM_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_dmaproxy_sp_proxy_status 0x2A8
#define HIVE_SIZE_dmaproxy_sp_proxy_status 4
#else
#endif
#endif
#define HIVE_MEM_sp_dmaproxy_sp_proxy_status scalar_processor_2400_dmem
#define HIVE_ADDR_sp_dmaproxy_sp_proxy_status 0x2A8
#define HIVE_SIZE_sp_dmaproxy_sp_proxy_status 4

/* function ia_css_pipeline_sp_wait_for_isys_stream_N: 5C7F */

/* function ia_css_sp_metadata_wait: 5B3B */

/* function ia_css_circbuf_peek_from_start: 16A2 */

/* function ia_css_event_sp_encode: 395F */

/* function ia_css_thread_sp_run: 151C */

/* function sp_isys_copy_func: 644 */

/* function ia_css_sp_isp_param_init_isp_memories: 4C0E */

/* function register_isr: 8F1 */

/* function irq_raise: C9 */

/* function ia_css_dmaproxy_sp_mmu_invalidate: 3447 */

/* function csi_rx_backend_disable: C41 */

/* function pipeline_sp_initialize_stage: 2183 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_N_CSI_RX_FE_CTRL_DLANES
#define HIVE_MEM_N_CSI_RX_FE_CTRL_DLANES scalar_processor_2400_dmem
#define HIVE_ADDR_N_CSI_RX_FE_CTRL_DLANES 0x1BC
#define HIVE_SIZE_N_CSI_RX_FE_CTRL_DLANES 12
#else
#endif
#endif
#define HIVE_MEM_sp_N_CSI_RX_FE_CTRL_DLANES scalar_processor_2400_dmem
#define HIVE_ADDR_sp_N_CSI_RX_FE_CTRL_DLANES 0x1BC
#define HIVE_SIZE_sp_N_CSI_RX_FE_CTRL_DLANES 12

/* function ia_css_dmaproxy_sp_read_byte_addr_mmio: 6A32 */

/* function ia_css_ispctrl_sp_done_ds: 3BFA */

/* function csi_rx_backend_config: C98 */

/* function ia_css_sp_isp_param_get_mem_inits: 4BE9 */

/* function ia_css_parambuf_sp_init_buffer_queues: 1B86 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_pfp_spref
#define HIVE_MEM_vbuf_pfp_spref scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_pfp_spref 0x360
#define HIVE_SIZE_vbuf_pfp_spref 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_pfp_spref scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_pfp_spref 0x360
#define HIVE_SIZE_sp_vbuf_pfp_spref 4

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
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_dvs_stat_bufs
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_dvs_stat_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_dvs_stat_bufs 0x69F0
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_dvs_stat_bufs 20
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_dvs_stat_bufs scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_dvs_stat_bufs 0x69F0
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_dvs_stat_bufs 20

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_pipe_private_frames
#define HIVE_MEM_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_pipe_private_frames 0x6A04
#define HIVE_SIZE_ia_css_bufq_sp_pipe_private_frames 280
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_pipe_private_frames scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_pipe_private_frames 0x6A04
#define HIVE_SIZE_sp_ia_css_bufq_sp_pipe_private_frames 280

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp2host_buffer_queue_handle
#define HIVE_MEM_sp2host_buffer_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp2host_buffer_queue_handle 0x6B1C
#define HIVE_SIZE_sp2host_buffer_queue_handle 108
#else
#endif
#endif
#define HIVE_MEM_sp_sp2host_buffer_queue_handle scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp2host_buffer_queue_handle 0x6B1C
#define HIVE_SIZE_sp_sp2host_buffer_queue_handle 108

/* function ia_css_ispctrl_sp_init_isp_vars: 4996 */

/* function ia_css_dvs_stat_sp_get_buffer_ddr_addr: 3432 */

/* function ia_css_isys_stream_start: 5D1F */

/* function ia_css_rmgr_sp_vbuf_enqueue: 5F8B */

/* function ia_css_tagger_sp_tag_exp_id: 27F1 */

/* function ia_css_dmaproxy_sp_write: 35EA */

/* function ia_css_isys_stream_start_async: 5D83 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_raw_buff_pool_lock_params_handles
#define HIVE_MEM_raw_buff_pool_lock_params_handles scalar_processor_2400_dmem
#define HIVE_ADDR_raw_buff_pool_lock_params_handles 0x7340
#define HIVE_SIZE_raw_buff_pool_lock_params_handles 60
#else
#endif
#endif
#define HIVE_MEM_sp_raw_buff_pool_lock_params_handles scalar_processor_2400_dmem
#define HIVE_ADDR_sp_raw_buff_pool_lock_params_handles 0x7340
#define HIVE_SIZE_sp_raw_buff_pool_lock_params_handles 60

/* function ia_css_parambuf_sp_release_in_param: 1A06 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_irq_sw_interrupt_token
#define HIVE_MEM_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_irq_sw_interrupt_token 0x3CE8
#define HIVE_SIZE_irq_sw_interrupt_token 4
#else
#endif
#endif
#define HIVE_MEM_sp_irq_sw_interrupt_token scalar_processor_2400_dmem
#define HIVE_ADDR_sp_irq_sw_interrupt_token 0x3CE8
#define HIVE_SIZE_sp_irq_sw_interrupt_token 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_isp_addresses
#define HIVE_MEM_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_addresses 0x6F84
#define HIVE_SIZE_sp_isp_addresses 164
#else
#endif
#endif
#define HIVE_MEM_sp_sp_isp_addresses scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_isp_addresses 0x6F84
#define HIVE_SIZE_sp_sp_isp_addresses 164

/* function ia_css_rmgr_sp_acq_gen: 5EB2 */

/* function input_system_input_port_open: 1274 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isps
#define HIVE_MEM_isps scalar_processor_2400_dmem
#define HIVE_ADDR_isps 0x73B4
#define HIVE_SIZE_isps 28
#else
#endif
#endif
#define HIVE_MEM_sp_isps scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isps 0x73B4
#define HIVE_SIZE_sp_isps 28

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_host_sp_queues_initialized
#define HIVE_MEM_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_host_sp_queues_initialized 0x3D00
#define HIVE_SIZE_host_sp_queues_initialized 4
#else
#endif
#endif
#define HIVE_MEM_sp_host_sp_queues_initialized scalar_processor_2400_dmem
#define HIVE_ADDR_sp_host_sp_queues_initialized 0x3D00
#define HIVE_SIZE_sp_host_sp_queues_initialized 4

/* function ia_css_queue_uninit: 5071 */

/* function ia_css_tagger_buf_sp_is_locked: 2F73 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_ispctrl_sp_isp_started
#define HIVE_MEM_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_ispctrl_sp_isp_started 0x6C44
#define HIVE_SIZE_ia_css_ispctrl_sp_isp_started 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_ispctrl_sp_isp_started scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_ispctrl_sp_isp_started 0x6C44
#define HIVE_SIZE_sp_ia_css_ispctrl_sp_isp_started 4

/* function ia_css_bufq_sp_release_dynamic_buf: 3145 */

/* function ia_css_sp_metadata_thread_terminate: 5B2D */

/* function ia_css_dmaproxy_sp_set_height_exception: 36F2 */

/* function ia_css_dmaproxy_sp_init_vmem_channel: 3675 */

/* function csi_rx_backend_stop: C64 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_num_ready_threads
#define HIVE_MEM_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_num_ready_threads 0x5A14
#define HIVE_SIZE_num_ready_threads 4
#else
#endif
#endif
#define HIVE_MEM_sp_num_ready_threads scalar_processor_2400_dmem
#define HIVE_ADDR_sp_num_ready_threads 0x5A14
#define HIVE_SIZE_sp_num_ready_threads 4

/* function ia_css_dmaproxy_sp_write_byte_addr_mmio: 35BC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_vbuf_spref
#define HIVE_MEM_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_vbuf_spref 0x35C
#define HIVE_SIZE_vbuf_spref 4
#else
#endif
#endif
#define HIVE_MEM_sp_vbuf_spref scalar_processor_2400_dmem
#define HIVE_ADDR_sp_vbuf_spref 0x35C
#define HIVE_SIZE_sp_vbuf_spref 4

/* function ia_css_queue_enqueue: 4FBC */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_request
#define HIVE_MEM_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_request 0x5A20
#define HIVE_SIZE_ia_css_flash_sp_request 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_request scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_request 0x5A20
#define HIVE_SIZE_sp_ia_css_flash_sp_request 4

/* function ia_css_dmaproxy_sp_vmem_write: 3576 */

/* function ia_css_tagger_buf_sp_unmark: 301C */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_reading_if
#define HIVE_MEM_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_reading_if 0x583C
#define HIVE_SIZE_sem_for_reading_if 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_reading_if scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_reading_if 0x583C
#define HIVE_SIZE_sp_sem_for_reading_if 20

/* function sp_generate_interrupts: 940 */

/* function ia_css_pipeline_sp_start: 2096 */

/* function csi_rx_backend_enable: C52 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_data
#define HIVE_MEM_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_data 0x7048
#define HIVE_SIZE_sp_data 640
#else
#endif
#endif
#define HIVE_MEM_sp_sp_data scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_data 0x7048
#define HIVE_SIZE_sp_sp_data 640

/* function input_system_input_port_configure: 12C6 */

/* function tmr_clock_read: B24 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ISP_BAMEM_BASE
#define HIVE_MEM_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_ISP_BAMEM_BASE 0x368
#define HIVE_SIZE_ISP_BAMEM_BASE 4
#else
#endif
#endif
#define HIVE_MEM_sp_ISP_BAMEM_BASE scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ISP_BAMEM_BASE 0x368
#define HIVE_SIZE_sp_ISP_BAMEM_BASE 4

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues
#define HIVE_MEM_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x6B88
#define HIVE_SIZE_ia_css_bufq_sp_sems_for_sp2host_buf_queues 180
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 0x6B88
#define HIVE_SIZE_sp_ia_css_bufq_sp_sems_for_sp2host_buf_queues 180

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_mem_map
#define HIVE_MEM_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_mem_map 0x3D04
#define HIVE_SIZE_mem_map 284
#else
#endif
#endif
#define HIVE_MEM_sp_mem_map scalar_processor_2400_dmem
#define HIVE_ADDR_sp_mem_map 0x3D04
#define HIVE_SIZE_sp_mem_map 284

/* function isys2401_dma_config_legacy: F78 */

/* function css_get_frame_processing_time_start: 27EA */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_all_cbs_frame
#define HIVE_MEM_sp_all_cbs_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_all_cbs_frame 0x5850
#define HIVE_SIZE_sp_all_cbs_frame 16
#else
#endif
#endif
#define HIVE_MEM_sp_sp_all_cbs_frame scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_all_cbs_frame 0x5850
#define HIVE_SIZE_sp_sp_all_cbs_frame 16

/* function ia_css_virtual_isys_sp_isr: 6B48 */

/* function thread_sp_queue_print: 1539 */

/* function sp_notify_eof: 906 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sem_for_str2mem
#define HIVE_MEM_sem_for_str2mem scalar_processor_2400_dmem
#define HIVE_ADDR_sem_for_str2mem 0x5860
#define HIVE_SIZE_sem_for_str2mem 20
#else
#endif
#endif
#define HIVE_MEM_sp_sem_for_str2mem scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sem_for_str2mem 0x5860
#define HIVE_SIZE_sp_sem_for_str2mem 20

/* function ia_css_bufq_sp_acquire_dynamic_buf: 333D */

/* function ia_css_circbuf_destroy: 17BD */

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

/* function ia_css_sp_isp_param_mem_load: 4B71 */

/* function __div: 63DA */

/* function ia_css_rmgr_sp_refcount_release_vbuf: 5FA2 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_ia_css_flash_sp_in_use
#define HIVE_MEM_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_ia_css_flash_sp_in_use 0x5A24
#define HIVE_SIZE_ia_css_flash_sp_in_use 4
#else
#endif
#endif
#define HIVE_MEM_sp_ia_css_flash_sp_in_use scalar_processor_2400_dmem
#define HIVE_ADDR_sp_ia_css_flash_sp_in_use 0x5A24
#define HIVE_SIZE_sp_ia_css_flash_sp_in_use 4

/* function ia_css_thread_sem_sp_wait: 66B1 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_sleep_mode
#define HIVE_MEM_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sleep_mode 0x3E20
#define HIVE_SIZE_sp_sleep_mode 4
#else
#endif
#endif
#define HIVE_MEM_sp_sp_sleep_mode scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_sleep_mode 0x3E20
#define HIVE_SIZE_sp_sp_sleep_mode 4

/* function mmu_invalidate_cache: E0 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_sp_max_cb_elems
#define HIVE_MEM_sp_max_cb_elems scalar_processor_2400_dmem
#define HIVE_ADDR_sp_max_cb_elems 0x134
#define HIVE_SIZE_sp_max_cb_elems 8
#else
#endif
#endif
#define HIVE_MEM_sp_sp_max_cb_elems scalar_processor_2400_dmem
#define HIVE_ADDR_sp_sp_max_cb_elems 0x134
#define HIVE_SIZE_sp_sp_max_cb_elems 8

/* function ia_css_dmaproxy_sp_register_channel_to_port: 3534 */

/* function ia_css_queue_remote_init: 5093 */

#ifndef HIVE_MULTIPLE_PROGRAMS
#ifndef HIVE_MEM_isp_stop_req
#define HIVE_MEM_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_isp_stop_req 0x5708
#define HIVE_SIZE_isp_stop_req 4
#else
#endif
#endif
#define HIVE_MEM_sp_isp_stop_req scalar_processor_2400_dmem
#define HIVE_ADDR_sp_isp_stop_req 0x5708
#define HIVE_SIZE_sp_isp_stop_req 4

#define HIVE_ICACHE_sp_critical_SEGMENT_START 0
#define HIVE_ICACHE_sp_critical_NUM_SEGMENTS  1

#endif /* _sp_map_h_ */
extern void sh_css_dump_sp_dmem(void);
void sh_css_dump_sp_dmem(void)
{
}
