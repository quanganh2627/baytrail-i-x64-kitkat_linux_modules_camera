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

#ifndef _isp_globals_hive_h_
#define _isp_globals_hive_h_

#ifndef SYNC_WITH
#define SYNC_WITH(x)
#endif
#ifndef MEM
#define MEM(x)
#endif
#ifndef NO_SYNC
#define NO_SYNC
#endif
#ifndef NO_HOIST
#define NO_HOIST
#endif

#include "isp_types.h"
#include <sh_css_internal.h>
#ifdef __SP
#include "product_specific.sp.h"
#endif
#ifdef __ISP
#include "product_specific.isp.h"
#endif
#if !defined(__HOST)
#include "dma_proxy.common.h"
#endif

#include <components/resolutions_mgr/src/resolutions_mgr_private.h>

/* Initialized by the SP: binary dependent */
/* Some of these globals are used inside dma transfer/configure commands.
   Therefore, their load will get a sync attribute. NO_SYNC prevents that.
*/
typedef struct s_isp_globals {
  /* Work around to get the skycam resource manager to work.
   * This belongs in isp_dmem_configurations.iterator.internal_info.
   */
  unsigned internal_width;

  /* DMA settings for output image */
  unsigned dma_output_block_width_a;
  unsigned dma_output_block_width_b;

  unsigned anr;

  struct stripe_private_per_stripe_data out_stripe;
} s_isp_globals;

#ifdef ISP_DMEM
#undef ISP_DMEM
#endif

#ifdef __SP
#define ISP_DMEM MEM(SP_XMEM)
#define PVECTOR short MEM(SP_XMEM) *
#else
#undef ISP_DMEM
#define ISP_DMEM
#define PVECTOR tmemvectoru MEM(VMEM) *
#endif


typedef struct s_isp_addresses {
  struct {
    struct sh_css_isp_params        ISP_DMEM *g_ispparm;
    unsigned                        ISP_DMEM *isp_deci_log_factor;
    struct s_isp_frames             ISP_DMEM *isp_frames;
    struct s_isp_globals            ISP_DMEM *isp_globals;
    unsigned                        ISP_DMEM *isp_online;
    struct s_output_dma_info        ISP_DMEM *output_dma_info;
    unsigned                        ISP_DMEM *vertical_upsampled;
    struct sh_css_ddr_address_map   ISP_DMEM *xmem_base;
    sh_dma_cmd*                     ISP_DMEM *sh_dma_cmd_ptr;
    unsigned                        ISP_DMEM *g_isp_do_zoom;
    struct isp_uds_config           ISP_DMEM *uds_config;
    int                             ISP_DMEM *g_sdis_horiproj_tbl;
    int                             ISP_DMEM *g_sdis_vertproj_tbl;
    unsigned                        ISP_DMEM *isp_enable_xnr;
    struct s_isp_gdcac_config       ISP_DMEM *isp_gdcac_config;
    unsigned                        ISP_DMEM *stripe_id;
    unsigned                        ISP_DMEM *stripe_row_id;
    unsigned                        ISP_DMEM *isp_continuous;
    unsigned                        ISP_DMEM *required_bds_factor;
    unsigned                        ISP_DMEM *isp_raw_stride_b;
	unsigned			            ISP_DMEM *isp_raw_block_width_b;
	unsigned			            ISP_DMEM *isp_raw_line_width_b;
	unsigned			            ISP_DMEM *isp_raw_stripe_offset_b;
  } dmem;
  struct {
    PVECTOR  input_buf;
    PVECTOR  g_obrow_vmask;
    PVECTOR  g_sdis_horicoef_tbl;
    PVECTOR  g_sdis_vertcoef_tbl; /* Can be vmem or dmem */
    PVECTOR  uds_data_via_sp;
    PVECTOR  uds_ipxs_via_sp;
    PVECTOR  uds_ibuf_via_sp;
    PVECTOR  uds_obuf_via_sp;
    PVECTOR  g_lin_lutlow_GR;
    PVECTOR  g_lin_lutlow_R;
    PVECTOR  g_lin_lutlow_B;
    PVECTOR  g_lin_lutlow_GB;
    PVECTOR  g_lin_lutdif_GR;
    PVECTOR  g_lin_lutdif_R;
    PVECTOR  g_lin_lutdif_B;
    PVECTOR  g_lin_lutdif_GB;
    PVECTOR  g_xnr_lut;
  } vmem;
  struct {
    unsigned g_ispparm;
    unsigned g_sdis_horiproj_tbl;
    unsigned g_sdis_vertproj_tbl;
  } sizes;
} s_isp_addresses;

extern s_isp_globals   NO_SYNC NO_HOIST isp_globals;
extern s_isp_addresses NO_SYNC NO_HOIST isp_addresses;

#ifdef __ISP
#define isp_envelope_width         isp_dmem_configurations.iterator.dvs_envelope.width
#define isp_envelope_height        isp_dmem_configurations.iterator.dvs_envelope.height
#define isp_bits_per_pixel         isp_dmem_configurations.iterator.input_info.raw_bit_depth
#define isp_deinterleaved          isp_dmem_configurations.raw.deinterleaved
#define isp_2ppc                   isp_dmem_configurations.raw.two_ppc
#define isp_vectors_per_line       iterator_config.vectors_per_line
#define isp_vectors_per_input_line iterator_config.vectors_per_input_line
#define isp_uv_internal_width_vecs iterator_config.uv_internal_width_vecs

/* Still used by SP */
#define isp_vf_output_width_vecs   vf_config.output_width_vecs

#define g_dma_output_block_width_a isp_globals.dma_output_block_width_a
#define g_dma_output_block_width_b isp_globals.dma_output_block_width_b

#if ENABLE_VF_VECEVEN
#define isp_vf_downscale_bits      isp_dmem_configurations.vf.vf_downscale_bits
#else
#define isp_vf_downscale_bits      0
#endif

#endif /* __ISP */

extern unsigned isp_deci_log_factor;
extern unsigned isp_online;

extern struct sh_css_ddr_address_map xmem_base;
extern struct s_isp_frames isp_frames;
extern struct isp_uds_config uds_config;

/* *****************************************************************
 * 		isp parameters
 *				1value per 32bit
 * *****************************************************************/
extern NO_HOIST struct sh_css_isp_params g_ispparm;

/* DMA settings for viewfinder image */

#define isp_do_zoom (ENABLE_DVS_ENVELOPE ? 1 : g_isp_do_zoom)
extern unsigned g_isp_do_zoom;

#define INPUT_BUF_LINES 2

#if !defined(__ISP)
/* Treat as flat for the outside world */
extern volatile tmemvectoru input_buf[];
#else
typedef struct {
  tmemvectoru  raw[INPUT_BUF_HEIGHT][INPUT_BUF_LINES][MAX_VECTORS_PER_INPUT_LINE]; /* 2 bayer lines */
} input_line_type;

typedef struct {
  tmemvectoru raw[INPUT_BUF_HEIGHT][2][MAX_VECTORS_PER_INPUT_STRIPE]; /* 2 bayer lines */
} raw_line_type;

typedef struct {
  tmemvectoru raw[OUTPUT_BUF_HEIGHT][2][MAX_VECTORS_PER_LINE]; /* 2 bayer lines */
} output_line_type;

extern input_line_type SYNC_WITH (INPUT_BUF) MEM (VMEM) input_buf;
extern output_line_type SYNC_WITH (OUTPUT_BUF) MEM (VMEM) raw_output_buf;

#endif

/* DMA proxy buffer */
#if !defined(__HOST)
extern unsigned     NO_SYNC sh_dma_cmd_buffer_idx;
extern unsigned     NO_SYNC sh_dma_cmd_buffer_cnt;
extern unsigned     NO_SYNC sh_dma_cmd_buffer_need_ack;
extern unsigned     NO_SYNC sh_dma_cmd_buffer_enabled;
#if defined(__ISP) && defined(__HIVECC)
extern sh_dma_cmd SYNC_WITH(DMA_PROXY_BUF) * NO_SYNC sh_dma_cmd_ptr;
#else
extern sh_dma_cmd *sh_dma_cmd_ptr;
#endif
#endif

/* striped-ISP information */
extern unsigned stripe_id;
extern unsigned stripe_row_id;

extern unsigned isp_continuous;
extern unsigned required_bds_factor;
extern unsigned isp_raw_stride_b;
extern unsigned isp_raw_block_width_b;
extern unsigned isp_raw_line_width_b;
extern unsigned isp_raw_stripe_offset_b;

#endif /* _isp_globals_hive_h_ */
