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


#ifndef _REF_VECTOR_FUNC_H_INCLUDED_
#define _REF_VECTOR_FUNC_H_INCLUDED_

#ifndef STORAGE_CLASS_REF_VECTOR_FUNC_C
#define STORAGE_CLASS_REF_VECTOR_FUNC_C extern
#endif

#include "ref_vector_func_types.h"


/*
 * Normalised FIR with coefficients [3,4,1], -5dB at Fs/2, -90 degree phase shift (quarter pixel)
 */

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_5dB_m90_nrm (
	const s_1w_1x3_matrix		m);

/*
 * Normalised FIR with coefficients [1,4,3], -5dB at Fs/2, +90 degree phase shift (quarter pixel)
 */

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_5dB_p90_nrm (
	const s_1w_1x3_matrix		m);

/*
 * Normalised FIR with coefficients [1,2,1], -6dB at Fs/2
 */

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm (
	const s_1w_1x3_matrix		m);
/*
 * Normalised FIR for 1.5/1.25
 */

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm_ph0 (
	const s_1w_1x3_matrix		m);

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm_ph1 (
	const s_1w_1x3_matrix		m);

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm_ph2 (
	const s_1w_1x3_matrix		m);

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm_ph3 (
	const s_1w_1x3_matrix		m);

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_6dB_nrm_calc_coeff (
	const s_1w_1x3_matrix		m);

/*
 * Normalised FIR with coefficients [1,1,1], -9dB at Fs/2
 */
STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir1x3m_9dB_nrm (
	const s_1w_1x3_matrix		m);


/*
 * Normalised FIR with coefficients [1;2;1] * [1,2,1]
 *
 * Unity gain filter through repeated scaling and rounding
 *	- 6 rotate operations per output
 *	- 8 vector operations per output
 * _______
 *   14
 */

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir3x3m_6dB_nrm (
	const s_1w_3x3_matrix		m);

/*
 * Normalised FIR with coefficients [1;1;1] * [1,1,1]
 *
 * (near) Unity gain filter through repeated scaling and rounding
 *	- 6 rotate operations per output
 *	- 8 vector operations per output
 * _______
 *   14
 */
STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir3x3m_9dB_nrm (
	const s_1w_3x3_matrix		m);

/*
 * Normalised dual output FIR with coefficients [1;2;1] * [1,2,1]
 *
 * Unity gain filter through repeated scaling and rounding
 * compute two outputs per call to re-use common intermediates
 *	- 4 rotate operations per output
 *	- 6 vector operations per output (alternative possible, but in this
 *	    form it's not obvious to re-use variables)
 * _______
 *   10
 */
STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w_1x2 fir3x3m_6dB_out2x1_nrm (
	const s_1w_4x3_matrix		m);

/*
 * Normalised dual output FIR with coefficients [1;1;1] * [1,1,1]
 *
 * (near) Unity gain filter through repeated scaling and rounding
 * compute two outputs per call to re-use common intermediates
 *	- 4 rotate operations per output
 *	- 7 vector operations per output (alternative possible, but in this
 *	    form it's not obvious to re-use variables)
 * _______
 *   11
 */
STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w_1x2 fir3x3m_9dB_out2x1_nrm (
	const s_1w_4x3_matrix		m);

STORAGE_CLASS_REF_VECTOR_FUNC_C tvector1w fir5x5m_12dB_nrm (
	s_1w_5x5_matrix	m);

#endif /*_REF_VECTOR_FUNC_H_INCLUDED_*/

