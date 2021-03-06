/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2010 - 2013 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef _COMMON_ISP_CONST_H_
#define _COMMON_ISP_CONST_H_

/*#include "isp.h"*/	/* ISP_VEC_NELEMS */

/* Binary independent constants */

#ifdef MODE
//#error __FILE__ "is mode independent"
#endif

#ifndef NO_HOIST
#  define		NO_HOIST 	HIVE_ATTRIBUTE (( no_hoist ))
#endif

#define NO_HOIST_CSE HIVE_ATTRIBUTE ((no_hoist, no_cse))

#ifdef __HIVECC
#define UNION union
#else
#define UNION struct /* Union constructors not allowed in C++ */
#endif

/* ISP binary identifiers.
   These determine the order in which the binaries are looked up, do not change
   this!
   Also, the SP firmware uses this same order (isp_loader.hive.c).
   Also, gen_firmware.c uses this order in its firmware_header.
*/
/* The binary id is used in pre-processor expressions so we cannot
 * use an enum here. */
 /* 24xx pipelines*/
#define SH_CSS_BINARY_ID_COPY                      0
#define SH_CSS_BINARY_ID_BAYER_DS                  1
#define SH_CSS_BINARY_ID_VF_PP_FULL                2
#define SH_CSS_BINARY_ID_VF_PP_OPT                 3
#define SH_CSS_BINARY_ID_YUV_SCALE                 4
#define SH_CSS_BINARY_ID_CAPTURE_PP                5
#define SH_CSS_BINARY_ID_PRE_ISP                   6
#define SH_CSS_BINARY_ID_PRE_ISP_ISP2              7
#define SH_CSS_BINARY_ID_GDC                       8
#define SH_CSS_BINARY_ID_POST_ISP                  9
#define SH_CSS_BINARY_ID_POST_ISP_ISP2            10
#define SH_CSS_BINARY_ID_ANR                      11
#define SH_CSS_BINARY_ID_ANR_ISP2                 12
#define SH_CSS_BINARY_ID_PREVIEW_CONT_DS          13
#define SH_CSS_BINARY_ID_PREVIEW_DS               14
#define SH_CSS_BINARY_ID_PREVIEW_DEC              15
#define SH_CSS_BINARY_ID_PREVIEW_CONT_BDS125_ISP2 16
#define SH_CSS_BINARY_ID_PREVIEW_CONT_BDS150_ISP2 17
#define SH_CSS_BINARY_ID_PREVIEW_CONT_BDS200_ISP2 18
#define SH_CSS_BINARY_ID_PREVIEW_DZ               19
#define SH_CSS_BINARY_ID_PREVIEW_DZ_ISP2          20
#define SH_CSS_BINARY_ID_PRIMARY_DS               21
#define SH_CSS_BINARY_ID_PRIMARY_VAR              22
#define SH_CSS_BINARY_ID_PRIMARY_VAR_ISP2         23
#define SH_CSS_BINARY_ID_PRIMARY_SMALL            24
#define SH_CSS_BINARY_ID_PRIMARY_STRIPED          25
#define SH_CSS_BINARY_ID_PRIMARY_STRIPED_ISP2     26
#define SH_CSS_BINARY_ID_PRIMARY_8MP              27
#define SH_CSS_BINARY_ID_PRIMARY_14MP             28
#define SH_CSS_BINARY_ID_PRIMARY_16MP             29
#define SH_CSS_BINARY_ID_PRIMARY_REF              30
#define SH_CSS_BINARY_ID_VIDEO_OFFLINE            31
#define SH_CSS_BINARY_ID_VIDEO_DS                 32
#define SH_CSS_BINARY_ID_VIDEO_YUV_DS             33
#define SH_CSS_BINARY_ID_VIDEO_DZ                 34
#define SH_CSS_BINARY_ID_VIDEO_DZ_2400_ONLY       35
#define SH_CSS_BINARY_ID_VIDEO_HIGH               36
#define SH_CSS_BINARY_ID_VIDEO_NODZ               37
#define SH_CSS_BINARY_ID_VIDEO_CONT_MULTIBDS_ISP2_MIN 38
#define SH_CSS_BINARY_ID_VIDEO_CONT_BDS_300_600_ISP2_MIN 39
#define SH_CSS_BINARY_ID_VIDEO_CONT_BDS150_ISP2_MIN   40
#define SH_CSS_BINARY_ID_VIDEO_CONT_BDS200_ISP2_MIN   41
#define SH_CSS_BINARY_ID_VIDEO_CONT_NOBDS_ISP2_MIN    42
#define SH_CSS_BINARY_ID_VIDEO_DZ_ISP2_MIN      43
#define SH_CSS_BINARY_ID_VIDEO_DZ_ISP2          44
#define SH_CSS_BINARY_ID_VIDEO_DZ_ISP2_ROTATED  45
#define SH_CSS_BINARY_ID_RESERVED1              46
#define SH_CSS_BINARY_ID_ACCELERATION           47
#define SH_CSS_BINARY_ID_PRE_DE_ISP2            48
#define SH_CSS_BINARY_ID_KERNEL_TEST_LOAD_STORE 49

/* skycam product pipelines */
#define SH_CSS_BINARY_ID_PRIMARY                            100
#define SH_CSS_BINARY_ID_VIDEO                              101
#define SH_CSS_BINARY_ID_SC_VIDEO_HIGH_RESOLUTION           102
#define SH_CSS_BINARY_ID_VIDEO_C0                           103

/* skycam kerneltest pipelines */
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_NORM              120
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_LIN               121
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_ACC_SHD           122
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_ACC_AWB           123
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_3A                124
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_ACC_AF            125
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_OBGRID            126
#define SH_CSS_BINARY_ID_VIDEO_TEST_INPUTCORRECTION         127
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_BAYER_DENOISE       128
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_DEMOSAIC            129
#define SH_CSS_BINARY_ID_VIDEO_TEST_SHD_BNR_DM_RGBPP        130
#define SH_CSS_BINARY_ID_VIDEO_TEST_ADD_RGBPP               131
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_YUVP1               132
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_YUVP1_C0            133
#define SH_CSS_BINARY_ID_VIDEO_TEST_SPATIAL_FF              134
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_DVS               135
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_YUVP2               136
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_XNR               137
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_TNR               138
#define SH_CSS_BINARY_ID_VIDEO_PARTIALPIPE_INPUTCOR_FULL    139
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_ACC_AE            140
#define SH_CSS_BINARY_ID_VIDEO_WITH_3A                      141
#define SH_CSS_BINARY_ID_VIDEO_RAW                          142
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_ACC_AWB_FR        143
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_DM_RGBPP          144
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_DM_RGBPP_STRIPED  145
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_ANR                 146
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_BDS_ACC           147
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_IF_STRIPED        148
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_OUTPUT_SYSTEM     149
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_TNR_STRIPED       150
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_DVS_STRIPED       151
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_OBGRID_STRIPED    152

/* skycam partial test pipelines*/
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_NO_ISP_EXITS           200
#define SH_CSS_BINARY_ID_IF_TO_DPC                          201
#define SH_CSS_BINARY_ID_IF_TO_BDS                          202
#define SH_CSS_BINARY_ID_IF_TO_NORM                         203
#define SH_CSS_BINARY_ID_IF_TO_OB                           204
#define SH_CSS_BINARY_ID_IF_TO_LIN                          205
#define SH_CSS_BINARY_ID_IF_TO_SHD                          206
#define SH_CSS_BINARY_ID_IF_TO_BNR                          207
#define SH_CSS_BINARY_ID_IF_TO_DM_WO_ANR_STATS              208
#define SH_CSS_BINARY_ID_IF_TO_DM_3A_WO_ANR                 209
#define SH_CSS_BINARY_ID_IF_TO_RGB                          210
#define SH_CSS_BINARY_ID_IF_TO_YUVP1                        211
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_WO_ANR                 212
#define SH_CSS_BINARY_ID_IF_TO_DM_WO_STATS                  213
#define SH_CSS_BINARY_ID_IF_TO_DM_3A                        214
#define SH_CSS_BINARY_ID_IF_TO_YUVP2                        215
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_C0                     216
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_ANR_VIA_ISP            217
#define SH_CSS_BINARY_ID_VIDEO_IF_TO_DVS                    218
#define SH_CSS_BINARY_ID_VIDEO_IF_TO_TNR                    219
#define SH_CSS_BINARY_ID_IF_NORM_LIN_SHD_BNR_STRIPED        220
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_DVS_STAT            221
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_LACE_STAT           222
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_YUVP1_S             223
#define SH_CSS_BINARY_ID_IF_TO_BDS_STRIPED                  224
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_ANR_STRIPED         225
#define SH_CSS_BINARY_ID_IF_NORM_LIN_SHD_AWB_BNR_STRIPED    226
#define SH_CSS_BINARY_ID_VIDEO_TEST_ACC_YUVP2_STRIPED       227
#define SH_CSS_BINARY_ID_IF_NORM_LIN_SHD_AF_BNR_STRIPED     228
#define SH_CSS_BINARY_ID_IF_NORM_LIN_SHD_AWBFR_BNR_STRIPED  229
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_NO_DPC_OB_STATS        230
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_NO_DPC_OB_AE           231
#define SH_CSS_BINARY_ID_IF_NORM_LIN_SHD_AE_BNR_STRIPED     232
#define SH_CSS_BINARY_ID_IF_TO_BDS_RGBP_DVS_STATS           233
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_NO_DPC_OB              234
#define SH_CSS_BINARY_ID_IF_TO_BDS_RGBP_DVS_STATS_STRIPED   235
#define SH_CSS_BINARY_ID_VIDEO_KERNELTEST_INPUT_YUV         236
#define SH_CSS_BINARY_ID_IF_TO_DVS_STRIPED                  237
#define SH_CSS_BINARY_ID_IF_TO_YUVP2_STRIPED                238
#define SH_CSS_BINARY_ID_IF_TO_YUVP1_STRIPED                239
#define SH_CSS_BINARY_ID_IF_TO_RGBPP_STRIPED                240
#define SH_CSS_BINARY_ID_IF_TO_ANR_STRIPED                  241
#define SH_CSS_BINARY_ID_IF_TO_BNR_STRIPED                  242
#define SH_CSS_BINARY_ID_IF_TO_SHD_STRIPED                  243
#define SH_CSS_BINARY_ID_IF_TO_LIN_STRIPED                  244
#define SH_CSS_BINARY_ID_IF_TO_OB_STRIPED                   245
#define SH_CSS_BINARY_ID_IF_TO_TNR_NO_DVS_STATS             246
#define SH_CSS_BINARY_ID_IF_TO_TNR_NO_DVS_STATS_HR          247

#define XMEM_WIDTH_BITS              HIVE_ISP_DDR_WORD_BITS
#define XMEM_SHORTS_PER_WORD         (HIVE_ISP_DDR_WORD_BITS/16)
#define XMEM_INTS_PER_WORD           (HIVE_ISP_DDR_WORD_BITS/32)
#define XMEM_POW2_BYTES_PER_WORD      HIVE_ISP_DDR_WORD_BYTES

#define BITS8_ELEMENTS_PER_XMEM_ADDR    CEIL_DIV(XMEM_WIDTH_BITS, 8)
#define BITS16_ELEMENTS_PER_XMEM_ADDR    CEIL_DIV(XMEM_WIDTH_BITS, 16)

#if ISP_VEC_NELEMS == 64
#define ISP_NWAY_LOG2  6
#elif ISP_VEC_NELEMS == 32
#define ISP_NWAY_LOG2  5
#elif ISP_VEC_NELEMS == 16
#define ISP_NWAY_LOG2  4
#elif ISP_VEC_NELEMS == 8
#define ISP_NWAY_LOG2  3
#else
#error "isp_const.h ISP_VEC_NELEMS must be one of {8, 16, 32, 64}"
#endif

/* *****************************
 * ISP input/output buffer sizes
 * ****************************/
/* input image */
#define INPUT_BUF_DMA_HEIGHT          2
#define INPUT_BUF_HEIGHT              2 /* double buffer */
#define OUTPUT_BUF_DMA_HEIGHT         2
#define OUTPUT_BUF_HEIGHT             2 /* double buffer */
#define OUTPUT_NUM_TRANSFERS	      4

/* GDC accelerator: Up/Down Scaling */
/* These should be moved to the gdc_defs.h in the device */
#define UDS_SCALING_N                 HRT_GDC_N
/* AB: This should cover the zooming up to 16MP */
#define UDS_MAX_OXDIM                 5000
/* We support maximally 2 planes with different parameters
       - luma and chroma (YUV420) */
#define UDS_MAX_PLANES                2
#define UDS_BLI_BLOCK_HEIGHT          2
#define UDS_BCI_BLOCK_HEIGHT          4
#define UDS_BLI_INTERP_ENVELOPE       1
#define UDS_BCI_INTERP_ENVELOPE       3
#define UDS_MAX_ZOOM_FAC              64
/* Make it always one FPGA vector.
   Four FPGA vectors are required and
   four of them fit in one ASIC vector.*/
#define UDS_MAX_CHUNKS                16

#define ISP_LEFT_PADDING	_ISP_LEFT_CROP_EXTRA(ISP_LEFT_CROPPING)
#define ISP_LEFT_PADDING_VECS	CEIL_DIV(ISP_LEFT_PADDING, ISP_VEC_NELEMS)

#define CEIL_ROUND_DIV_STRIPE(width, stripe, padding) \
	CEIL_MUL(padding + CEIL_DIV(width - padding, stripe), ((ENABLE_RAW_BINNING || ENABLE_FIXED_BAYER_DS)?4:2))

/* output (Y,U,V) image, 4:2:0 */
#define MAX_VECTORS_PER_LINE \
	CEIL_ROUND_DIV_STRIPE(CEIL_DIV(ISP_MAX_INTERNAL_WIDTH, ISP_VEC_NELEMS), \
			      ISP_NUM_STRIPES, \
			      ISP_LEFT_PADDING_VECS)

/*
 * '+ VECTORS_PER_ITERATION' explanation:
 * when striping an even number of iterations, one of the stripes is
 * one iteration wider than the other to account for overlap
 * so the calc for the output buffer vmem size is:
 * ((width[vectors]/num_of_stripes) + 2[vectors])
 */
#define VECTORS_PER_ITERATION 2
#define LINES_PER_ITERATION 2
#define MAX_VECTORS_PER_OUTPUT_LINE \
	(CEIL_DIV(CEIL_DIV(ISP_MAX_OUTPUT_WIDTH, ISP_NUM_STRIPES) + ISP_LEFT_PADDING, ISP_VEC_NELEMS) + \
	VECTORS_PER_ITERATION)

#define MAX_VECTORS_PER_INPUT_LINE	CEIL_DIV(ISP_MAX_INPUT_WIDTH, ISP_VEC_NELEMS)
#define MAX_VECTORS_PER_INPUT_STRIPE	(CEIL_ROUND_DIV_STRIPE(CEIL_DIV(ISP_MAX_INPUT_WIDTH, ISP_VEC_NELEMS) , \
							      ISP_NUM_STRIPES, \
							      ISP_LEFT_PADDING_VECS) + \
							      VECTORS_PER_ITERATION)

/* Add 2 for left croppping */
#define MAX_SP_RAW_COPY_VECTORS_PER_INPUT_LINE	(CEIL_DIV(ISP_MAX_INPUT_WIDTH, ISP_VEC_NELEMS) + 2)

#define MAX_VECTORS_PER_BUF_LINE \
	(MAX_VECTORS_PER_LINE + DUMMY_BUF_VECTORS)
#define MAX_VECTORS_PER_BUF_INPUT_LINE \
	(MAX_VECTORS_PER_INPUT_STRIPE + DUMMY_BUF_VECTORS)
#define MAX_OUTPUT_Y_FRAME_WIDTH \
	(MAX_VECTORS_PER_LINE * ISP_VEC_NELEMS)
#define MAX_OUTPUT_Y_FRAME_SIMDWIDTH \
	MAX_VECTORS_PER_LINE
#define MAX_OUTPUT_C_FRAME_WIDTH \
	(MAX_OUTPUT_Y_FRAME_WIDTH / 2)
#define MAX_OUTPUT_C_FRAME_SIMDWIDTH \
	CEIL_DIV(MAX_OUTPUT_C_FRAME_WIDTH, ISP_VEC_NELEMS)

/* should be even */
#define NO_CHUNKING (OUTPUT_NUM_CHUNKS == 1)

#define MAX_VECTORS_PER_CHUNK \
	(NO_CHUNKING ? MAX_VECTORS_PER_LINE \
				: 2*CEIL_DIV(MAX_VECTORS_PER_LINE, \
					     2*OUTPUT_NUM_CHUNKS))

#define MAX_C_VECTORS_PER_CHUNK \
	(MAX_VECTORS_PER_CHUNK/2)

/* should be even */
#define MAX_VECTORS_PER_OUTPUT_CHUNK \
	(NO_CHUNKING ? MAX_VECTORS_PER_OUTPUT_LINE \
				: 2*CEIL_DIV(MAX_VECTORS_PER_OUTPUT_LINE, \
					     2*OUTPUT_NUM_CHUNKS))

#define MAX_C_VECTORS_PER_OUTPUT_CHUNK \
	(MAX_VECTORS_PER_OUTPUT_CHUNK/2)



/* should be even */
#define MAX_VECTORS_PER_INPUT_CHUNK \
	(INPUT_NUM_CHUNKS == 1 ? MAX_VECTORS_PER_INPUT_STRIPE \
			       : 2*CEIL_DIV(MAX_VECTORS_PER_INPUT_STRIPE, \
					    2*OUTPUT_NUM_CHUNKS))

#define DEFAULT_C_SUBSAMPLING      2

/****** DMA buffer properties */

#define RAW_BUF_LINES   2
#define RAW_BUF_STRIDE (MAX_VECTORS_PER_INPUT_STRIPE)

#define INPUT_YUV_YBUF_LINES   2
#define INPUT_YUV_YBUF_STRIDE (MAX_VECTORS_PER_INPUT_STRIPE)

#endif /* _COMMON_ISP_CONST_H_ */
