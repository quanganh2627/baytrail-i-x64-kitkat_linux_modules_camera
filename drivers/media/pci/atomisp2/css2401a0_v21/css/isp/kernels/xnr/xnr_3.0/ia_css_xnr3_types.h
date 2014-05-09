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

#ifndef __IA_CSS_XNR3_TYPES_H
#define __IA_CSS_XNR3_TYPES_H


struct ia_css_xnr3_sigma_params {
	// XNR Sigma Parameters
	double sgm0_y;
	double sgm1_y;
	double sgm0_u;
	double sgm1_u;
	double sgm0_v;
	double sgm1_v;
};

struct ia_css_xnr3_alpha_params {
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

struct ia_css_xnr3_coring_params{
	double m_CnrCoringU0 ;
	double m_CnrCoringU1 ;
	double m_CnrCoringV0 ;
	double m_CnrCoringV1 ;
	int m_CnrCoringU01 ;
	int m_CnrCoringV01 ;
};

struct ia_css_xnr3_config {
	int kernel_size;
	struct ia_css_xnr3_sigma_params     sigma_p;
	struct ia_css_xnr3_alpha_params     alpha_p;
	struct ia_css_xnr3_coring_params    coring_p;
};

#endif /* __IA_CSS_XNR3_TYPES_H */

