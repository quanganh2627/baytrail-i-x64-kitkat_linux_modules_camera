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

#ifndef __IA_CSS_XNR3_PARAM_H
#define __IA_CSS_XNR3_PARAM_H

#include "type_support.h"

/* Scaling factor of the alpha values: which fixed-point value represents 1.0?
 * It must be chosen such that 1/min_sigma still fits in an ISP vector
 * element. */
#define XNR_ALPHA_SCALE_LOG2        5
#define XNR_ALPHA_SCALE_FACTOR      (1 << XNR_ALPHA_SCALE_LOG2)

/* Scaling factor of the coring values. */
#define XNR_CORING_SCALE_LOG2       (ISP_VEC_ELEMBITS-1)
#define XNR_CORING_SCALE_FACTOR     (1 << XNR_CORING_SCALE_LOG2)



struct sh_css_xnr3_sigma_params {
	// XNR Sigma Parameters
	int sgm0_y;
	int sgm1_y;
	int sgm0_u;
	int sgm1_u;
	int sgm0_v;
	int sgm1_v;
};

struct sh_css_xnr3_alpha_params {
	// XNR alpha Parameters
	int  alpha0_y;
	int  alpha1_y;
	int  alpha0_u;
	int  alpha1_u;
	int  alpha0_v;
	int  alpha1_v;
	// XNR alpha diff parameters
	int  alpha10_y;
	int  alpha10_u;
	int  alpha10_v;
};

struct sh_css_xnr3_coring_params {
	int m_CnrCoringU0 ;
	int m_CnrCoringU1 ;
	int m_CnrCoringV0 ;
	int m_CnrCoringV1 ;
	int m_CnrCoringU01 ;
	int m_CnrCoringV01 ;
};

struct sh_css_isp_xnr3_params {
	int kernel_size;
	struct sh_css_xnr3_sigma_params     sigma_p;
	struct sh_css_xnr3_alpha_params     alpha_p;
	struct sh_css_xnr3_coring_params    coring_p;
};

#endif  /*__IA_CSS_XNR3_PARAM_H */
