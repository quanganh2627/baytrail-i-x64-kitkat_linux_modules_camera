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

#include "ia_css_types.h"
#include "sh_css_defs.h"
/* ToDo: check how to dump using the debug trace functions */
//#include "ia_css_debug.h"
#include "type_support.h"

#include "ia_css_bnr22.host.h"

#ifndef __HIVECC
#include <stdio.h>
#endif

/* Default kernel parameters. */
const struct ia_css_bnr22_config default_bnr22_config = {
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	0,
	4096,
	8191,
	128,
	0,
	0,
	0,
	8191,
	0,
	8191
};

void
ia_css_bnr22_encode(
	struct sh_css_isp_bnr22_params *to,
	const struct ia_css_bnr22_config *from)
{
	/* BNR (Bayer Noise Reduction) */

	/* TODO:
	 * RB: for now, blindly copy
	 * No checks/digitfitting is applied
	 */
	to->BnrDVarGain_R0 		= from->BnrDVarGain_R0;
	to->BnrDVarGain_G0 		= from->BnrDVarGain_G0;
	to->BnrDVarGain_B0 		= from->BnrDVarGain_B0;
	to->BnrDVarGain_R1 		= from->BnrDVarGain_R1;
	to->BnrDVarGain_G1 		= from->BnrDVarGain_G1;
	to->BnrDVarGain_B1 		= from->BnrDVarGain_B1;
	to->BnrNVarGain_R0 		= from->BnrNVarGain_R0;
	to->BnrNVarGain_G0 		= from->BnrNVarGain_G0;
	to->BnrNVarGain_B0 		= from->BnrNVarGain_B0;
	to->BnrNVarGain_R1 		= from->BnrNVarGain_R1;
	to->BnrNVarGain_G1 		= from->BnrNVarGain_G1;
	to->BnrNVarGain_B1 		= from->BnrNVarGain_B1;
	to->BnrDThres 			= from->BnrDThres;
	to->BnrDThresW 			= from->BnrDThresW;
	to->BnrVarOffsetCoef 		= from->BnrVarOffsetCoef;
	to->BnrDGain			= from->BnrDGain;
	to->BnrDetailThreshold 		= from->BnrDetailThreshold;
	to->BnrDetailLevelOffset	= from->BnrDetailLevelOffset;
	to->BnrDValThMin 		= from->BnrDValThMin;
	to->BnrDVarThMax 		= from->BnrDVarThMax;
	to->BnrNVarThMin 		= from->BnrNVarThMin;
	to->BnrNVarThMax 		= from->BnrNVarThMax;
}

void
ia_css_bnr22_debug_trace(
	const struct ia_css_bnr22_config *bnr,
	unsigned level)
{
	if (!bnr)
		return;

#if 1
	/* isp_test_bench can not access ia_css_debug_dtrace because of css
	 * dependencies included in ia_css_debug.h.
	 * This debug is enabled till ia_css_debug_dtrace() function access is
	 * restored for isp_test_bench. */
	(void)level;

	printf("Bayer Noise Reduction 2.2:\n");
	printf("\t%-32s = %d\n", "BnrDVarGain_R0", bnr->BnrDVarGain_R0);
	printf("\t%-32s = %d\n", "BnrDVarGain_G0", bnr->BnrDVarGain_G0);
	printf("\t%-32s = %d\n", "BnrDVarGain_B0", bnr->BnrDVarGain_B0);
	printf("\t%-32s = %d\n", "BnrDVarGain_R1", bnr->BnrDVarGain_R1);
	printf("\t%-32s = %d\n", "BnrDVarGain_G1", bnr->BnrDVarGain_G1);
	printf("\t%-32s = %d\n", "BnrDVarGain_B1", bnr->BnrDVarGain_B1);

	printf("\t%-32s = %d\n", "BnrNVarGain_R0", bnr->BnrNVarGain_R0);
	printf("\t%-32s = %d\n", "BnrNVarGain_G0", bnr->BnrNVarGain_G0);
	printf("\t%-32s = %d\n", "BnrNVarGain_B0", bnr->BnrNVarGain_B0);
	printf("\t%-32s = %d\n", "BnrNVarGain_R1", bnr->BnrNVarGain_R1);
	printf("\t%-32s = %d\n", "BnrNVarGain_G1", bnr->BnrNVarGain_G1);
	printf("\t%-32s = %d\n", "BnrNVarGain_B1", bnr->BnrNVarGain_B1);

	printf("\t%-32s = %d\n", "BnrDThres", bnr->BnrDThres);
	printf("\t%-32s = %d\n", "BnrDThresW", bnr->BnrDThresW);
	printf("\t%-32s = %d\n", "BnrVarOffsetCoef", bnr->BnrVarOffsetCoef);
	printf("\t%-32s = %d\n", "BnrDGain", bnr->BnrDGain);
	printf("\t%-32s = %d\n", "BnrDetailThreshold", bnr->BnrDetailThreshold);
	printf("\t%-32s = %d\n", "BnrDetailLevelOffset", bnr->BnrDetailLevelOffset);

	printf("\t%-32s = %d\n", "BnrDValThMin", bnr->BnrDValThMin);
	printf("\t%-32s = %d\n", "BnrDVarThMax", bnr->BnrDVarThMax);
	printf("\t%-32s = %d\n", "BnrNVarThMin", bnr->BnrNVarThMin);
	printf("\t%-32s = %d\n", "BnrNVarThMax", bnr->BnrNVarThMax);
#else
	ia_css_debug_dtrace(level, "Bayer Noise Reduction 2.2:\n");
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_R0", bnr->BnrDVarGain_R0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_G0", bnr->BnrDVarGain_G0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_B0", bnr->BnrDVarGain_B0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_R1", bnr->BnrDVarGain_R1);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_G1", bnr->BnrDVarGain_G1);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarGain_B1", bnr->BnrDVarGain_B1);

	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_R0", bnr->BnrNVarGain_R0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_G0", bnr->BnrNVarGain_G0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_B0", bnr->BnrNVarGain_B0);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_R1", bnr->BnrNVarGain_R1);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_G1", bnr->BnrNVarGain_G1);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarGain_B1", bnr->BnrNVarGain_B1);

	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDThres", bnr->BnrDThres);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDThresW", bnr->BnrDThresW);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrVarOffsetCoef", bnr->BnrVarOffsetCoef);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDGain", bnr->BnrDGain);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDetailThreshold", bnr->BnrDetailThreshold);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDetailLevelOffset", bnr->BnrDetailLevelOffset);

	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDValThMin", bnr->BnrDValThMin);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrDVarThMax", bnr->BnrDVarThMax);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarThMin", bnr->BnrNVarThMin);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"BnrNVarThMax", bnr->BnrNVarThMax);
#endif
}
