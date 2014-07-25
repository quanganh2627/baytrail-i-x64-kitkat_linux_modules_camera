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

#ifndef __IA_CSS_BNR22_PARAM_H
#define __IA_CSS_BNR22_PARAM_H

#include "type_support.h"

/* BNR22 filter size. Must be 5x5. */
#define BNR_FILTER_SIZE		5

/* BNR22 enable disparity correction. */
#define BNR_DISPARITY_CORRECTION	1

/* BNR22 Mode (#number of directions) */
/* Currently only mode 4 is supported (ISP2.6.1.) */
#define BNR_MODE		4

/* TEMP, for implementation purpose.... */
#define SCALER_IMPLEMENTATION	1

/* TEMP: for implementation purpose.... */
#define STATE_IMPLEMENTATION	1

/* TEMP: for implementation purpose.... */
#define BYPASS_BNR22		0

/* Define boundary behavior */
#define MIRROR_CORNER

/* BNR (Bayer Noise Reduction) ISP parameters */
struct sh_css_isp_bnr22_params {
	int32_t BnrDVarGain_R0;		/**Directional variance gain for R, in dark region. */
	int32_t BnrDVarGain_G0;		/**Directional variance gain for R, in dark region. */
	int32_t BnrDVarGain_B0;		/**Directional variance gain for R, in dark region. */
	int32_t BnrDVarGain_R1;		/**Directional variance gain for R, in bright region. */
	int32_t BnrDVarGain_G1;		/**Directional variance gain for R, in bright region. */
	int32_t BnrDVarGain_B1;		/**Directional variance gain for R, in bright region. */
	int32_t BnrNVarGain_R0;		/**Non-Directional variance gain for R, in dark region. */
	int32_t BnrNVarGain_G0;		/**Non-Directional variance gain for R, in dark region. */
	int32_t BnrNVarGain_B0;		/**Non-Directional variance gain for R, in dark region. */
	int32_t BnrNVarGain_R1;		/**Non-Directional variance gain for R, in bright region. */
	int32_t BnrNVarGain_G1;		/**Non-Directional variance gain for R, in bright region. */
	int32_t BnrNVarGain_B1;		/**Non-Directional variance gain for R, in bright region. */
	int32_t BnrDThres;		/**Threshold for directional filtering */
	int32_t BnrDThresW;		/**Threshold width for directional filtering */
	int32_t BnrVarOffsetCoef;	/**Variance offset coefficient noise subtraction level */
	int32_t BnrDGain;		/**Gain for directional coefficient */
	int32_t BnrDetailThreshold;	/**Threshold for low contrast texture control */
	int32_t BnrDetailLevelOffset;	/**Offset value for low contrast texture control */
	int32_t BnrDValThMin;		/**Minimum clipping value for directional variance*/
	int32_t BnrDVarThMax;		/**Maximum clipping value for diretional variance*/
	int32_t BnrNVarThMin;		/**Minimum clipping value for non-directional variance*/
	int32_t BnrNVarThMax;		/**Maximum clipping value for non-directional variance*/
};

#endif /* __IA_CSS_BNR22_PARAM_H */
