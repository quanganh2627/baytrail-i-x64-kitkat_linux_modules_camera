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

#ifndef _IA_CSS_SDIS_COMMON_HOST_H
#define _IA_CSS_SDIS_COMMON_HOST_H

#define ISP_SDIS_COEF_SHIFT               SH_CSS_DIS_COEF_SHIFT

#define ISP_MAX_SDIS_HOR_PROJ_NUM_ISP \
	__ISP_SDIS_HOR_PROJ_NUM_ISP(ISP_MAX_INTERNAL_WIDTH, ISP_MAX_INTERNAL_HEIGHT, \
		SH_CSS_DIS_DECI_FACTOR_LOG2, ISP_PIPE_VERSION)
#define ISP_MAX_SDIS_VER_PROJ_NUM_ISP \
	__ISP_SDIS_VER_PROJ_NUM_ISP(ISP_MAX_INTERNAL_WIDTH, ISP_MAX_INTERNAL_HEIGHT, \
		SH_CSS_DIS_DECI_FACTOR_LOG2, ISP_PIPE_VERSION)

#define ISP_MAX_SDIS_HOR_COEF_NUM_VECS \
	__ISP_SDIS_HOR_COEF_NUM_VECS(ISP_MAX_INTERNAL_WIDTH)
#define ISP_MAX_SDIS_VER_COEF_NUM_VECS \
	__ISP_SDIS_VER_COEF_NUM_VECS(ISP_MAX_INTERNAL_HEIGHT)
#define ISP_MAX_SDIS_VER_COEF_NUM_ISP \
	_ISP_SDIS_VER_COEF_NUM_ISP(ISP_MAX_INTERNAL_HEIGHT)

#define ISP_SDIS_VER_COEF_NUM_3A \
	_ISP_SDIS_VER_COEF_NUM_3A(ISP_INTERNAL_HEIGHT, SH_CSS_DIS_DECI_FACTOR_LOG2)
#define ISP_SDIS_VER_COEF_NUM_ISP \
	_ISP_SDIS_VER_COEF_NUM_ISP(ISP_INTERNAL_HEIGHT)

#define ISP_SDIS_HOR_PROJ_NUM_ISP  isp_sdis_horiproj_num
#define ISP_SDIS_VER_PROJ_NUM_ISP  isp_sdis_vertproj_num

/* For YUV upscaling, the internal size is used for DIS statistics */
#define _ISP_SDIS_ELEMS_ISP(input, internal, enable_us) \
	((enable_us) ? (internal) : (input))

#define _ISP_SDIS_HOR_GRID_NUM_3A(in_width, deci_factor_log2) \
	(_ISP_BQS(in_width) >> deci_factor_log2)
#define _ISP_SDIS_VER_GRID_NUM_3A(in_height, deci_factor_log2) \
	(_ISP_BQS(in_height) >> deci_factor_log2)

/* SDIS Number of Grid */
#define _ISP_SDIS_HOR_GRID_NUM_ISP(in_width, deci_factor_log2) \
	CEIL_SHIFT(_ISP_BQS(in_width), deci_factor_log2)
#define _ISP_SDIS_VER_GRID_NUM_ISP(in_height, deci_factor_log2) \
	CEIL_SHIFT(_ISP_BQS(in_height), deci_factor_log2)

/* The number of coefficients used by the 3A library. This excludes
   coefficients from grid cells that do not fall completely within the image. */
#define _ISP_SDIS_HOR_COEF_NUM_3A(in_width, deci_factor_log2) \
	((_ISP_BQS(in_width) >> deci_factor_log2) << deci_factor_log2)
#define _ISP_SDIS_VER_COEF_NUM_3A(in_height, deci_factor_log2) \
	((_ISP_BQS(in_height) >> deci_factor_log2) << deci_factor_log2)

/* SDIS Coefficients: */
/* The ISP uses vectors to store the coefficients, so we round
   the number of coefficients up to vectors. */
#define __ISP_SDIS_HOR_COEF_NUM_VECS(in_width)  _ISP_VECS(_ISP_BQS(in_width))
#define __ISP_SDIS_VER_COEF_NUM_VECS(in_height) _ISP_VECS(_ISP_BQS(in_height))

/* The number of coefficients produced by the ISP */
#define _ISP_SDIS_HOR_COEF_NUM_ISP(in_width) \
	(__ISP_SDIS_HOR_COEF_NUM_VECS(in_width) * ISP_VEC_NELEMS)
#define _ISP_SDIS_VER_COEF_NUM_ISP(in_height) \
	(__ISP_SDIS_VER_COEF_NUM_VECS(in_height) * ISP_VEC_NELEMS)

/* SDIS Projections:
 * SDIS1: Horizontal projections are calculated for each line.
 * Vertical projections are calculated for each column.
 * SDIS2: Projections are calculated for each grid cell.
 * Grid cells that do not fall completely within the image are not
 * valid. The host needs to use the bigger one for the stride but
 * should only return the valid ones to the 3A. */
#define __ISP_SDIS_HOR_PROJ_NUM_ISP(in_width, in_height, deci_factor_log2, \
	isp_pipe_version) \
	((isp_pipe_version == 1) ? \
		CEIL_SHIFT(_ISP_BQS(in_height), deci_factor_log2) : \
		(CEIL_SHIFT(_ISP_BQS(in_width), deci_factor_log2) * \
		 CEIL_SHIFT(_ISP_BQS(in_height), deci_factor_log2)))

#define __ISP_SDIS_VER_PROJ_NUM_ISP(in_width, in_height, deci_factor_log2, \
	isp_pipe_version) \
	((isp_pipe_version == 1) ? \
		CEIL_SHIFT(_ISP_BQS(in_width), deci_factor_log2) : \
		(CEIL_SHIFT(_ISP_BQS(in_width), deci_factor_log2) * \
		 CEIL_SHIFT(_ISP_BQS(in_height), deci_factor_log2)))

#define _ISP_SDIS_HOR_PROJ_NUM_3A(in_width, in_height, deci_factor_log2, \
	isp_pipe_version) \
	((isp_pipe_version == 1) ? \
		(_ISP_BQS(in_height) >> deci_factor_log2) : \
		((_ISP_BQS(in_width) >> deci_factor_log2) * \
		 (_ISP_BQS(in_height) >> deci_factor_log2)))

#define _ISP_SDIS_VER_PROJ_NUM_3A(in_width, in_height, deci_factor_log2, \
	isp_pipe_version) \
	((isp_pipe_version == 1) ? \
		(_ISP_BQS(in_width) >> deci_factor_log2) : \
		((_ISP_BQS(in_width) >> deci_factor_log2) * \
		 (_ISP_BQS(in_height) >> deci_factor_log2)))

/* Some binaries put the vertical coefficients in DMEM instead
   of VMEM to save VMEM. */
#define _SDIS_VER_COEF_TBL_USE_DMEM(mode, enable_sdis, enable_ds, isp_pipe_version) \
	(mode == IA_CSS_BINARY_MODE_VIDEO \
	&& enable_sdis && enable_ds != 2 && isp_pipe_version == 1)
#define SDIS_VER_COEF_TBL__IN_DMEM(b) \
	_SDIS_VER_COEF_TBL_USE_DMEM((b)->info->sp.mode, (b)->info->sp.enable.dis,  (b)->info->sp.enable.ds, (b)->info->sp.isp_pipe_version)

#define SH_CSS_DIS_VER_NUM_COEF_TYPES(b) \
  (((b)->info->sp.isp_pipe_version == 2) ? IA_CSS_DVS2_NUM_COEF_TYPES : \
	(SDIS_VER_COEF_TBL__IN_DMEM(b) ? \
		IA_CSS_DVS_COEF_TYPES_ON_DMEM : \
		IA_CSS_DVS_NUM_COEF_TYPES))

/**** SDIS defs ********/
#define _ISP_SDIS_HOR_PROJ_NUM_ISP \
  __ISP_SDIS_HOR_PROJ_NUM_ISP(ISP_INTERNAL_WIDTH, \
                              ISP_INTERNAL_HEIGHT, \
                              SH_CSS_DIS_DECI_FACTOR_LOG2, ISP_PIPE_VERSION)
#define _ISP_SDIS_VER_PROJ_NUM_ISP \
  __ISP_SDIS_VER_PROJ_NUM_ISP(ISP_INTERNAL_WIDTH, \
                              ISP_INTERNAL_HEIGHT, \
                              SH_CSS_DIS_DECI_FACTOR_LOG2, ISP_PIPE_VERSION)

#define _ISP_SDIS_HOR_COEF_NUM_VECS \
  __ISP_SDIS_HOR_COEF_NUM_VECS(ISP_INTERNAL_WIDTH)
#define _ISP_SDIS_VER_COEF_NUM_VECS \
  __ISP_SDIS_VER_COEF_NUM_VECS(ISP_INTERNAL_HEIGHT)

/* Use dmem to store sdis vertical coefficients */
#ifndef SDIS_VER_COEF_TBL_USE_DMEM
#define SDIS_VER_COEF_TBL_USE_DMEM \
	_SDIS_VER_COEF_TBL_USE_DMEM(MODE, ENABLE_SDIS, ENABLE_DS, ISP_PIPE_VERSION)
#endif

#ifndef PIPE_GENERATION
#if defined(__ISP) || defined (MK_FIRMWARE)
#if SDIS_VER_COEF_TBL_USE_DMEM
/* Only type 0,1 is allcated on dmem.
  Type 0,2,4 is the same shape.
  Type 1,3,5 is the same shape.
	W = frame width
  type0: sin curve from W*0.0 to W*0.4
  type1: cos curve from W*0.0 to W*0.4
  type2: sin curve from W*0.3 to W*0.7
  type3: cos curve from W*0.3 to W*0.7
  type4: sin curve from W*0.6 to W*1.0
  type5: cos curve from W*0.6 to W*1.0
*/
#endif

struct sh_css_isp_sdis_dmem_params {
#if SDIS_VER_COEF_TBL_USE_DMEM
  short vertcoef_tbl[ISP_DVS_COEF_TYPES_ON_DMEM * ISP_MAX_SDIS_VER_COEF_NUM_ISP];
#endif
  int   horiproj_tbl[ISP_DVS_NUM_COEF_TYPES * ISP_MAX_SDIS_HOR_PROJ_NUM_ISP + DVS2_PROJ_MARGIN];
  int   vertproj_tbl[ISP_DVS_NUM_COEF_TYPES * ISP_MAX_SDIS_VER_PROJ_NUM_ISP + DVS2_PROJ_MARGIN];
};

struct sh_css_isp_sdis_vmem_params {
  tmemvectoru horicoef_tbl[ISP_DVS_NUM_COEF_TYPES * ISP_MAX_SDIS_HOR_COEF_NUM_VECS];
#if !SDIS_VER_COEF_TBL_USE_DMEM
  tmemvectoru vertcoef_tbl[ISP_DVS_NUM_COEF_TYPES * ISP_MAX_SDIS_VER_COEF_NUM_VECS];
#endif
};
#endif /* defined(__ISP) || defined (MK_FIRMWARE) */
#endif /* PIPE_GENERATION */

#ifndef PIPE_GENERATION
struct s_sdis_config {
  unsigned horicoef_vectors;
  unsigned vertcoef_vectors;
  unsigned horiproj_num;
  unsigned vertproj_num;
};

extern struct s_sdis_config sdis_config;
#endif

#endif /* _IA_CSS_SDIS_COMMON_HOST_H */
