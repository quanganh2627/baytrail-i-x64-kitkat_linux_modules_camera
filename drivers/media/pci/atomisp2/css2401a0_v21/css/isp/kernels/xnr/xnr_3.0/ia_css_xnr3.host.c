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
#include "sh_css_defs.h"
#include "ia_css_types.h"
#include "ia_css_xnr3.host.h"

/* Maximum value for alpha */
#define XNR_MAX_ALPHA  ((1 << (ISP_VEC_ELEMBITS-1)) - 1)
#define XNR_MIN_SIGMA  (0.01)

/*
 * Compute an alpha value for the ISP kernel from sigma value on the host
 * parameter interface as: scale * 1/sigma
 */
static int
compute_alpha(double sigma)
{
	int alpha;
	if (sigma < XNR_MIN_SIGMA)
	{
		alpha = XNR_MAX_ALPHA;
	}
	else
	{
		/* The scale factor here must be the same as on the ISP. The
		 * reference code (ATE) is not as precise as possible because
		 * it rounds 1/sigma to an integer, and then does the scaling.
		 * Better would be:
		 * alpha = (int)(XNR_ALPHA_SCALE_FACTOR / sigma);
		 */
		alpha = XNR_ALPHA_SCALE_FACTOR * (int)(1 / sigma);
		if (alpha > XNR_MAX_ALPHA)
		{
			alpha = XNR_MAX_ALPHA;
		}
	}

	return alpha;
}

/*
 * Compute the scaled coring value for the ISP kernel from the value on the
 * host parameter interface.
 */
static int
compute_coring(double coring)
{
	return (int)((coring * XNR_CORING_SCALE_FACTOR) + 0.5);
}


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

	/* alpha's are represented in qN.5 format */
	to->alpha_p.alpha0_y = compute_alpha(from->sigma_p.sgm0_y);
	to->alpha_p.alpha1_y = compute_alpha(from->sigma_p.sgm1_y);
	to->alpha_p.alpha0_u = compute_alpha(from->sigma_p.sgm0_u);
	to->alpha_p.alpha1_u = compute_alpha(from->sigma_p.sgm1_u);
	to->alpha_p.alpha0_v = compute_alpha(from->sigma_p.sgm0_v);
	to->alpha_p.alpha1_v = compute_alpha(from->sigma_p.sgm1_v);

	to->alpha_p.alpha10_y = adjust_factor*(to->alpha_p.alpha1_y-to->alpha_p.alpha0_y)/kernel_size;
	to->alpha_p.alpha10_u = adjust_factor*(to->alpha_p.alpha1_u-to->alpha_p.alpha0_u)/kernel_size;
	to->alpha_p.alpha10_v = adjust_factor*(to->alpha_p.alpha1_v-to->alpha_p.alpha0_v)/kernel_size;

	/* coring parameters are expressed in q1.NN format */
	to->coring_p.m_CnrCoringU0 = compute_coring(from->coring_p.m_CnrCoringU0);
	to->coring_p.m_CnrCoringU1 = compute_coring(from->coring_p.m_CnrCoringU1);
	to->coring_p.m_CnrCoringV0 = compute_coring(from->coring_p.m_CnrCoringV0);
	to->coring_p.m_CnrCoringV1 = compute_coring(from->coring_p.m_CnrCoringV1);

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
