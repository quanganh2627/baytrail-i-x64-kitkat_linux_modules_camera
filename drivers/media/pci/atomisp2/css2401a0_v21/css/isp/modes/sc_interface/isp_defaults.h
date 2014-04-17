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

#ifndef _SC_INTERFACE_ISP_DEFAULTS
#define _SC_INTERFACE_ISP_DEFAULTS

#if !defined(USE_DMA_PROXY)
#define USE_DMA_PROXY 1
#endif

#if !defined(ENABLE_DIS_CROP)
#define ENABLE_DIS_CROP 0
#endif

/* Duplicates from "isp/common/defs.h" */
#if !defined(ENABLE_FIXED_BAYER_DS)
#define ENABLE_FIXED_BAYER_DS 0
#endif

#if !defined(SUPPORTED_BDS_FACTORS)
#define SUPPORTED_BDS_FACTORS PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_1_00)
#endif

#if !defined(ENABLE_RAW_BINNING)
#define ENABLE_RAW_BINNING 0
#endif

#if !defined(ENABLE_PARAMS)
#define ENABLE_PARAMS		1
#endif

#if !defined(ENABLE_RAW)
#define ENABLE_RAW		0
#endif

#if !defined(ENABLE_DVS_6AXIS)
#define ENABLE_DVS_6AXIS	0
#endif

#if !defined(ENABLE_TNR)
#define ENABLE_TNR              0
#endif

#if !defined(ENABLE_UDS)
#define ENABLE_UDS              0
#endif

#if !defined(ENABLE_OUTPUT)
#define ENABLE_OUTPUT           0
#endif

#if !defined(ENABLE_BAYER_OUTPUT)
#define ENABLE_BAYER_OUTPUT     0
#endif


#if !defined(ENABLE_OBROW)
#define ENABLE_OBROW          0
#endif
#if !defined(ENABLE_OBCOL)
#define ENABLE_OBCOL          0
#endif
#if !defined(ENABLE_OBGRID)
#define ENABLE_OBGRID         0
#endif

#if !defined(ENABLE_LIN)
#define ENABLE_LIN            0
#endif

#if !defined(ENABLE_RGBA)
#define ENABLE_RGBA 0
#endif

#if !defined(ENABLE_XNR)
#define ENABLE_XNR            0
#endif

#if !defined(ENABLE_HIGH_SPEED)
#define ENABLE_HIGH_SPEED 0
#endif

#if !defined(ENABLE_HIGH_QUALITY)
#define ENABLE_HIGH_QUALITY 0
#endif

#if !defined(ENABLE_KERNELTEST)
#define ENABLE_KERNELTEST 0
#endif

#define ENABLE_REF_FRAME        (ENABLE_TNR || ENABLE_DIS_CROP || \
				ENABLE_UDS || ENABLE_DVS_6AXIS)

#ifndef ENABLE_CONTINUOUS
#define ENABLE_CONTINUOUS       0
#endif

#ifndef ENABLE_CA_GDC
#define ENABLE_CA_GDC           0
#endif

#ifndef ENABLE_OVERLAY
#define ENABLE_OVERLAY          0
#endif

#ifndef ENABLE_ISP_ADDRESSES
#define ENABLE_ISP_ADDRESSES    1
#endif

#ifndef ENABLE_IN_FRAME
#define ENABLE_IN_FRAME		0
#endif

#ifndef ENABLE_OUT_FRAME
#define ENABLE_OUT_FRAME	0
#endif

#ifndef ISP_DMEM_PARAMETERS_SIZE
#define ISP_DMEM_PARAMETERS_SIZE	0
#endif

#ifndef ISP_DMEM_RESULTS_SIZE
#define ISP_DMEM_RESULTS_SIZE		0
#endif

#ifndef ISP_VMEM_PARAMETERS_SIZE
#define ISP_VMEM_PARAMETERS_SIZE	0
#endif

#ifndef ISP_VMEM_RESULTS_SIZE
#define ISP_VMEM_RESULTS_SIZE		0
#endif

#ifndef ISP_VAMEM0_PARAMETERS_SIZE
#define ISP_VAMEM0_PARAMETERS_SIZE	0
#endif

#ifndef ISP_VAMEM0_RESULTS_SIZE
#define ISP_VAMEM0_RESULTS_SIZE		0
#endif

#ifndef ISP_VAMEM1_PARAMETERS_SIZE
#define ISP_VAMEM1_PARAMETERS_SIZE	0
#endif

#ifndef ISP_VAMEM1_RESULTS_SIZE
#define ISP_VAMEM1_RESULTS_SIZE		0
#endif

#ifndef ISP_VAMEM2_PARAMETERS_SIZE
#define ISP_VAMEM2_PARAMETERS_SIZE	0
#endif

#ifndef ISP_VAMEM2_RESULTS_SIZE
#define ISP_VAMEM2_RESULTS_SIZE		0
#endif

#ifndef ISP_NUM_STRIPES
#define ISP_NUM_STRIPES         1
#endif

#ifndef ISP_ROW_STRIPES_HEIGHT
#define ISP_ROW_STRIPES_HEIGHT         0
#endif

#ifndef ISP_ROW_STRIPES_OVERLAP_LINES
#define ISP_ROW_STRIPES_OVERLAP_LINES         0
#endif

#ifndef VARIABLE_OUTPUT_FORMAT
#define VARIABLE_OUTPUT_FORMAT  1
#endif

#ifndef VARIABLE_RESOLUTION
#define VARIABLE_RESOLUTION  1
#endif

#ifndef ISP_MAX_INTERNAL_WIDTH
#define ISP_MAX_INTERNAL_WIDTH  0
#endif

#ifndef ENABLE_INPUT_CHUNKING
#define ENABLE_INPUT_CHUNKING  0
#endif

#endif /* _ISP_DEFAULTS */

