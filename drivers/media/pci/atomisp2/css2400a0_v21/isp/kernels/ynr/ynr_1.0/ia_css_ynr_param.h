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

#ifndef __IA_CSS_YNR_PARAM_H
#define __IA_CSS_YNR_PARAM_H

#ifdef __KERNEL__
#include <linux/kernel.h>
#else
#include <stdint.h>
#endif

/* YNR (Y Noise Reduction) */
struct sh_css_isp_ynr_params {
	int32_t threshold;
	int32_t gain_all;
	int32_t gain_dir;
};

/* YEE (Y Edge Enhancement) */
struct sh_css_isp_yee_params {
	int32_t dirthreshold_s;
	int32_t dirthreshold_g;
	int32_t dirthreshold_width_log2;
	int32_t dirthreshold_width;
	int32_t detailgain;
	int32_t coring_s;
	int32_t coring_g;
	int32_t scale_plus_s;
	int32_t scale_plus_g;
	int32_t scale_minus_s;
	int32_t scale_minus_g;
	int32_t clip_plus_s;
	int32_t clip_plus_g;
	int32_t clip_minus_s;
	int32_t clip_minus_g;
	int32_t Yclip;
};

#endif /* __IA_CSS_YNR_PARAM_H */