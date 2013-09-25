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

#ifndef __PIPELINE_GLOBAL_H_INCLUDED__
#define __PIPELINE_GLOBAL_H_INCLUDED__

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#include "system_types.h"	/* To get the DLI version, we should not need that */
#include "sh_css_defs.h"	/* SH_CSS_MAX_STAGES */
#ifndef PIPE_GENERATION
#include "sh_css_internal.h"	/* sh_css_uds_info and sh_css_crop_pos */
/* Requires cleanup. 
 * vamem should be included by the kernels needing it.
*/
#ifdef __ISP
#define __INLINE_VAMEM__
#endif
#include "vamem.h"
#endif

typedef struct sh_css_isp_params		pipeline_param_t;
typedef const struct sh_css_isp_params	*pipeline_param_h;

/*
 * Compose the pipeline (parameters) from one or more module parameter sets
 *
 * This file should be separated for pipeline versions, but separation is not
 * yet possible at CSS API level. *
 */

/* Include all kernel parameter types for ISP1 */
#include "anr/anr_1.0/ia_css_anr_param.h"
#include "cnr/cnr_1.0/ia_css_cnr_param.h"
#include "csc/csc_1.0/ia_css_csc_param.h"
#include "de/de_1.0/ia_css_de_param.h"
#include "dp/dp_1.0/ia_css_dp_param.h"
#include "bnr/bnr_1.0/ia_css_bnr_param.h"
#include "fpn/fpn_1.0/ia_css_fpn_param.h"
#include "gc/gc_1.0/ia_css_gc_param.h"
#include "macc/macc_1.0/ia_css_macc_param.h"
#include "ob/ob_1.0/ia_css_ob_param.h"
#include "s3a/s3a_1.0/ia_css_s3a_param.h"
#include "sc/sc_1.0/ia_css_sc_param.h"
#include "tnr/tnr_1.0/ia_css_tnr_param.h"
#include "uds/uds_1.0/ia_css_uds_param.h"
#include "wb/wb_1.0/ia_css_wb_param.h"
#include "ynr/ynr_1.0/ia_css_ynr_param.h"
#include "raw/raw_1.0/ia_css_raw_param.h"

/* Include additional kernel parameter types for ISP2 */
#include "aa/aa_2/ia_css_aa2_param.h"
#include "anr/anr_2/ia_css_anr2_param.h"
#include "cnr/cnr_2/ia_css_cnr2_param.h"
#include "de/de_2/ia_css_de2_param.h"
#include "gc/gc_2/ia_css_gc2_param.h"
#include "ctc/ctc_2/ia_css_ctc2_param.h"
#include "ynr/ynr_2/ia_css_ynr2_param.h"

#if !defined(IS_ISP_2500_SYSTEM)
struct ia_css_isp_gamma_table {
	uint16_t data[SH_CSS_ISP_GAMMA_TABLE_SIZE];
};

struct ia_css_isp_ctc_table {
	uint16_t data[SH_CSS_ISP_CTC_TABLE_SIZE];
};

struct ia_css_isp_rgb_gamma_table {
	uint16_t data[SH_CSS_ISP_RGB_GAMMA_TABLE_SIZE];
};

struct ia_css_isp_xnr_table {
	uint16_t data[SH_CSS_ISP_XNR_TABLE_SIZE];
};

struct sh_css_isp_param_configs {
	/* OB (Optical Black) */
	struct sh_css_isp_ob_stream_config ob;
};

/* Data structures shared with ISP dmem */
struct sh_css_isp_params {
	/* FPNR (Fixed Pattern Noise Reduction) */
	struct sh_css_isp_fpn_params fpn;

	/* OB (Optical Black) */
	struct sh_css_isp_ob_params ob;

	/* SC (Shading Corrction) */
	struct sh_css_isp_sc_params sc;

	/* WB (White Balance) */
	struct sh_css_isp_wb_params wb;

	/* DP (Defect Pixel Correction) */
	struct sh_css_isp_dp_params dp;

	/* BNR (Bayer Noise Reduction) */
	struct sh_css_isp_bnr_params bnr;

	/* S3A (3A Support) */
	struct sh_css_isp_s3a_params s3a;

	/* DE (Demosaic) */
	struct sh_css_isp_de_params de;

	/* YNR (Y Noise Reduction) */
	struct sh_css_isp_ynr_params ynr;

	/* YEE (Y Edge Enhancement) */
	struct sh_css_isp_yee_params yee;

	/* CSC (Color Space Conversion) */
	struct sh_css_isp_csc_params csc;

	/* YUV2RGB (YUV to RGB conversion) */
	struct sh_css_isp_csc_params yuv2rgb;

	/* RGB2YUV (RGB to YUV conversion) */
	struct sh_css_isp_csc_params rgb2yuv;

	/* GC (Gamma Correction) */
	struct sh_css_isp_gc_params gc;

	/* TNR (Temporal Noise Reduction) */
	struct sh_css_isp_tnr_params tnr;

	/* ANR (Advance Noise Reduction) */
	struct sh_css_isp_anr_params anr;

	/* CE (Chroma Enhancement) */
	struct sh_css_isp_ce_params ce;

	/* Bayer Anti-Aliasing */
	struct sh_css_isp_raw_params raw;

	/* MACC */
	struct sh_css_isp_macc_params macc;

	/* Anti-Aliasing */
	struct sh_css_isp_aa_params aa;

	/* DE (Demosaic) */
	struct sh_css_isp_ecd_params ecd;

	/* YNR (Y Noise Reduction), YEE (Y Edge Enhancement) */
	struct sh_css_isp_yee2_params yee2;

	/* Fringe Control */
	struct sh_css_isp_fc_params fc;

	/* CNR */
	struct sh_css_isp_cnr_params cnr;

	/* CTC */
	struct sh_css_isp_ctc_params ctc;

	/* SP parameters.
	 * To be moved to a separate struct.
	 * These are indexed with the satge number to apply them to the proper binary.
	 */

	/* UDS */
	struct sh_css_sp_uds_params uds[SH_CSS_MAX_STAGES];
};
#endif

#endif /* __PIPELINE_GLOBAL_H_INCLUDED__ */
