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

#include "math_support.h"
#include "ia_css_types.h"
#include "ia_css_xnr3.host.h"

#define WORD_MAX 0x7FFF
#define MIN_SIGMA 0.01

/*TEMP FIX FOR COMPILATION WARNINGS FOR MIN FUNCTION
  PROPER HEADER FILE WILL BE INCLUDED LATER*/
#define MIN(X,Y) (X<Y?X:Y)

void
ia_css_xnr3_encode(
	struct sh_css_isp_xnr3_params *to,
	const struct ia_css_xnr3_config *from)
{
	int kernel_size= from->kernel_size;
	int adjust_factor = 2*(kernel_size-1);

	to->sigma_p.sgm0_y = (int)from->sigma_p.sgm0_y;
	to->sigma_p.sgm1_y = (int)from->sigma_p.sgm1_y;
	to->sigma_p.sgm0_u = (int)from->sigma_p.sgm0_u;
	to->sigma_p.sgm1_u = (int)from->sigma_p.sgm1_u;
	to->sigma_p.sgm0_v = (int)from->sigma_p.sgm0_v;
	to->sigma_p.sgm1_v = (int)from->sigma_p.sgm1_v;
	/*Alpha's are represented in q11.5 format*/
	to->alpha_p.alpha0_y = (from->sigma_p.sgm0_y<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm0_y)))),WORD_MAX);
	to->alpha_p.alpha1_y = (from->sigma_p.sgm1_y<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm1_y)))),WORD_MAX);
	to->alpha_p.alpha0_u = (from->sigma_p.sgm0_u<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm0_u)))),WORD_MAX);
	to->alpha_p.alpha1_u = (from->sigma_p.sgm1_u<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm1_u)))),WORD_MAX);
	to->alpha_p.alpha0_v = (from->sigma_p.sgm0_v<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm0_v)))),WORD_MAX);
	to->alpha_p.alpha1_v = (from->sigma_p.sgm1_v<MIN_SIGMA) ? WORD_MAX : MIN(((int)(32*((int)(1/from->sigma_p.sgm1_v)))),WORD_MAX);

	to->alpha_p.alpha10_y = adjust_factor*(to->alpha_p.alpha1_y-to->alpha_p.alpha0_y)/kernel_size;
	to->alpha_p.alpha10_u = adjust_factor*(to->alpha_p.alpha1_u-to->alpha_p.alpha0_u)/kernel_size;
	to->alpha_p.alpha10_v = adjust_factor*(to->alpha_p.alpha1_v-to->alpha_p.alpha0_v)/kernel_size;

	/*coring parameters are expressed in q1.15 format*/
	to->coring_p.m_CnrCoringU0 = (int) (from->coring_p.m_CnrCoringU0 * (1<<15) + 0.5);
	to->coring_p.m_CnrCoringU1 = (int) (from->coring_p.m_CnrCoringU1 * (1<<15) + 0.5);
	to->coring_p.m_CnrCoringV0 = (int) (from->coring_p.m_CnrCoringV0 * (1<<15) + 0.5);
	to->coring_p.m_CnrCoringV1 = (int) (from->coring_p.m_CnrCoringV1 * (1<<15) + 0.5);

	to->coring_p.m_CnrCoringU01 = adjust_factor*(to->coring_p.m_CnrCoringU1-to->coring_p.m_CnrCoringU0)/kernel_size;
	to->coring_p.m_CnrCoringV01 = adjust_factor*(to->coring_p.m_CnrCoringV1-to->coring_p.m_CnrCoringV0)/kernel_size;



}
/* Dummy Function added as the tool expects it*/
void
ia_css_xnr3_debug_dtrace(
	const struct ia_css_xnr3_config *config,
	unsigned level)
{
	(void)config;
	(void)level;
}
