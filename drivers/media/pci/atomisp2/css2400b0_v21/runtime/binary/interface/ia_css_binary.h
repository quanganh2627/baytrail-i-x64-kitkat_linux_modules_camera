/* Release Version: ci_master_20131030_2214 */
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

#ifndef _IA_CSS_BINARY_H_
#define _IA_CSS_BINARY_H_

/* The binary mode is used in pre-processor expressions so we cannot
 * use an enum here. */
#define IA_CSS_BINARY_MODE_COPY       0
#define IA_CSS_BINARY_MODE_PREVIEW    1
#define IA_CSS_BINARY_MODE_PRIMARY    2
#define IA_CSS_BINARY_MODE_VIDEO      3
#define IA_CSS_BINARY_MODE_PRE_ISP    4
#define IA_CSS_BINARY_MODE_GDC        5
#define IA_CSS_BINARY_MODE_POST_ISP   6
#define IA_CSS_BINARY_MODE_ANR        7
#define IA_CSS_BINARY_MODE_CAPTURE_PP 8
#define IA_CSS_BINARY_MODE_VF_PP      9
#define IA_CSS_BINARY_MODE_PRE_DE     10
#define IA_CSS_BINARY_NUM_MODES       11

/* Indicate where binaries can read input from */
#define IA_CSS_BINARY_INPUT_SENSOR   0
#define IA_CSS_BINARY_INPUT_MEMORY   1
#define IA_CSS_BINARY_INPUT_VARIABLE 2

/* enumeration of the bayer downscale factors. When a binary supports multiple
 * factors, the OR of these defines is used to build the mask of supported
 * factors. The BDS factor is used in pre-processor expressions so we cannot
 * use an enum here. */
/* THIS SHOULD BE MOVED TO THE PUBLIC INTERFACE OF THE BDS KERNEL */
#define SH_CSS_BDS_FACTOR_1_00 (1<<0)
#define SH_CSS_BDS_FACTOR_1_25 (1<<1)
#define SH_CSS_BDS_FACTOR_1_50 (1<<2)
#define SH_CSS_BDS_FACTOR_2_00 (1<<3)
#define SH_CSS_BDS_FACTOR_2_25 (1<<4)
#define SH_CSS_BDS_FACTOR_2_50 (1<<5)
#define SH_CSS_BDS_FACTOR_3_00 (1<<6)
#define SH_CSS_BDS_FACTOR_4_00 (1<<7)
#define SH_CSS_BDS_FACTOR_4_50 (1<<8)
#define SH_CSS_BDS_FACTOR_5_00 (1<<9)
#define SH_CSS_BDS_FACTOR_6_00 (1<<10)
#define SH_CSS_BDS_FACTOR_8_00 (1<<11)

struct sh_css_bds_factor {
	unsigned numerator;
	unsigned denominator;
	unsigned int bds_factor;
};

#include "ia_css.h"
#include "sh_css_metrics.h"

struct ia_css_binary_descr {
	int mode;
	bool online;
	bool continuous;
	bool two_ppc;
	bool enable_yuv_ds;
	bool enable_high_speed;
	bool enable_dvs_6axis;
	bool enable_reduced_pipe;
	bool enable_dz;
	bool enable_fractional_ds;
	struct ia_css_resolution dvs_env;
	enum ia_css_stream_format stream_format;
	struct ia_css_frame_info *in_info;
	struct ia_css_frame_info *bds_out_info;
	struct ia_css_frame_info *out_info;
	struct ia_css_frame_info *vf_info;
	unsigned int isp_pipe_version;
	unsigned int required_bds_factor;
};

struct ia_css_binary {
	const struct ia_css_binary_xinfo *info;
	enum ia_css_stream_format input_format;
	struct ia_css_frame_info in_frame_info;
	struct ia_css_frame_info internal_frame_info;
	struct ia_css_frame_info out_frame_info;
	struct ia_css_frame_info vf_frame_info;
	int                      input_buf_vectors;
	int                      deci_factor_log2;
	int                      dis_deci_factor_log2;
	int                      vf_downscale_log2;
	int                      s3atbl_width;
	int                      s3atbl_height;
	int                      s3atbl_isp_width;
	int                      s3atbl_isp_height;
	unsigned int             morph_tbl_width;
	unsigned int             morph_tbl_aligned_width;
	unsigned int             morph_tbl_height;
	int                      sctbl_width_per_color;
	int                      sctbl_aligned_width_per_color;
	int                      sctbl_height;
	int                      dis_hor_grid_num_3a;
	int                      dis_ver_grid_num_3a;
	int                      dis_hor_grid_num_isp;
	int                      dis_ver_grid_num_isp;
	int                      dis_hor_coef_num_3a;
	int                      dis_ver_coef_num_3a;
	int                      dis_hor_coef_num_isp;
	int                      dis_ver_coef_num_isp;
	int                      dis_hor_proj_num_3a;
	int                      dis_ver_proj_num_3a;
	int                      dis_hor_proj_num_isp;
	int                      dis_ver_proj_num_isp;
	struct ia_css_resolution dvs_envelope;
	bool                     online;
	unsigned int             uds_xc;
	unsigned int             uds_yc;
	unsigned int             left_padding;
	struct sh_css_binary_metrics metrics;
};

#define IA_CSS_BINARY_DEFAULT_FRAME_INFO \
{ \
	{0,                      /* width */ \
	 0},                     /* height */ \
	0,                       /* padded_width */ \
	IA_CSS_FRAME_FORMAT_NUM, /* format */ \
	0,                       /* raw_bit_depth */ \
	IA_CSS_BAYER_ORDER_NUM   /* raw_bayer_order */ \
}

#define IA_CSS_BINARY_DEFAULT_SETTINGS \
{ \
	NULL, \
	IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY, \
	IA_CSS_BINARY_DEFAULT_FRAME_INFO, \
	IA_CSS_BINARY_DEFAULT_FRAME_INFO, \
	IA_CSS_BINARY_DEFAULT_FRAME_INFO, \
	IA_CSS_BINARY_DEFAULT_FRAME_INFO, \
	0,	/* input_buf_vectors */ \
	0,	/* deci_factor_log2 */ \
	0,	/* dis_deci_factor_log2 */ \
	0,	/* vf_downscale_log2 */ \
	0,	/* s3atbl_width */ \
	0,	/* s3atbl_height */ \
	0,	/* s3atbl_isp_width */ \
	0,	/* s3atbl_isp_height */ \
	0,	/* morph_tbl_width */ \
	0,	/* morph_tbl_aligned_width */ \
	0,	/* morph_tbl_height */ \
	0,	/* sctbl_width_per_color */ \
	0,	/* sctbl_aligned_width_per_color */ \
	0,	/* sctbl_height */ \
	0,	/* dis_hor_grid_num_3a */ \
	0,	/* dis_ver_grid_num_3a */ \
	0,	/* dis_hor_grid_num_isp */ \
	0,	/* dis_ver_grid_num_isp */ \
	0,	/* dis_hor_coef_num_3a */ \
	0,	/* dis_ver_coef_num_3a */ \
	0,	/* dis_hor_coef_num_isp */ \
	0,	/* dis_ver_coef_num_isp */ \
	0,	/* dis_hor_proj_num_3a */ \
	0,	/* dis_ver_proj_num_3a */ \
	0,	/* dis_hor_proj_num_isp */ \
	0,	/* dis_ver_proj_num_isp */ \
	{ 0, 0 },/* dvs_envelope_info */ \
	false,	/* online */ \
	0,	/* uds_xc */ \
	0,	/* uds_yc */ \
	0,	/* left_padding */ \
	DEFAULT_BINARY_METRICS	/* metrics */ \
}

enum ia_css_err
ia_css_binary_init_infos(void);

enum ia_css_err
ia_css_binary_uninit(void);

enum ia_css_err
ia_css_binary_fill_info(const struct ia_css_binary_xinfo *xinfo,
		 bool online,
		 bool two_ppc,
		 enum ia_css_stream_format stream_format,
		 const struct ia_css_frame_info *in_info,
		 const struct ia_css_frame_info *bds_out_info,
		 const struct ia_css_frame_info *out_info,
		 const struct ia_css_frame_info *vf_info,
		 struct ia_css_binary *binary,
		 struct ia_css_resolution *dvs_env);

enum ia_css_err
ia_css_binary_find(struct ia_css_binary_descr *descr,
		   struct ia_css_binary *binary);

void
ia_css_binary_grid_info(const struct ia_css_binary *binary,
			struct ia_css_grid_info *info);

unsigned
ia_css_binary_max_vf_width(void);

#endif /* _IA_CSS_BINARY_H_ */
