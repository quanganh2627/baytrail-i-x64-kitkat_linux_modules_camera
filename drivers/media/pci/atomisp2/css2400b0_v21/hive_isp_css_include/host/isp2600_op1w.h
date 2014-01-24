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

#ifndef __ISP2600_OP1W_H_INCLUDED__
#define __ISP2600_OP1W_H_INCLUDED__

/*
 * This file is part of the Multi-precision vector operations exstension package.
 */

/*
 * Single-precision vector operations
 */

/*
 * Prerequisites:
 *
 */

#ifndef STORAGE_CLASS_ISP2600_OP1W_H
#define STORAGE_CLASS_ISP2600_OP1W_H extern
#endif

/*
 * Single-precision data type specification
 */

#include "isp2600_op1w_types.h"
#include "isp2600_op2w_types.h" // for doubling operations.

#include "isp2600_opNw_native_types.h"

/*
 * Single-precision prototype specification
 */

/* Arithmetic */

/* Use standard operations */
#define   OP_vec1w_and      OP_vec_and
#define   OP_vec1w_and_c    OP_vec_and_c
#define   OP_vec1w_or       OP_vec_or
#define   OP_vec1w_or_c     OP_vec_or_c
#define   OP_vec1w_xor      OP_vec_xor
#define   OP_vec1w_xor_c    OP_vec_xor_c
#define   OP_vec1w_inv      OP_vec_inv


/* Additive */

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_add(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_sub(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_addsat(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_subsat(
    const tvector1w     _a,
    const tvector1w     _b);

/* Multiplicative */

STORAGE_CLASS_ISP2600_OP1W_H tvector2w OP_vec1w_muld(
    const tvector1w     _a,
    const tvector1w     _b);

/* Comparative */

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_eq(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_neq(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_le(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_lt(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_ge(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_gt(
    const tvector1w     _a,
    const tvector1w     _b);

/* Shift */

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_asr(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_asrrnd(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_lsl(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_lslsat(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_lsr(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_lsrrnd(
    const tvector1w     _a,
    const tvector1w     _b);


/* Cast */

STORAGE_CLASS_ISP2600_OP1W_H tscalar1w OP_int_cast_scalar1w (
    const int           _a);

STORAGE_CLASS_ISP2600_OP1W_H int OP_scalar1w_cast_int (
    const tscalar1w      _a);

STORAGE_CLASS_ISP2600_OP1W_H tvector2w OP_vec1w_cast_vec2w (
    const tvector1w     _a);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec2w_cast_vec1w (
    const tvector2w    _a);


/* Vector-slice */

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vec1w_slice_select_low(
    const tslice1w          _a,
    const tvector1w         _b,
    const sp_fragment_s_t   _c);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vec1w_slice_select_high(
    const tslice1w          _a,
    const tvector1w         _b,
    const sp_fragment_s_t   _c);

#define   OP_vec1w_slice        OP_vec_slice
#define   OP_vec1w_select_low   OP_vec_select_low
#define   OP_vec1w_select_high  OP_vec_select_high


/* Vector and vector-slice */

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_addsat(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_addnextsat(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_subabs(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_subsat(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_subnextabs(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_subnextsat(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_nextsubabs(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tslice1w OP_vecsl1w_nextsubsat(
    const tslice1w      _a,
    const tvector1w     _b,
    const tslice1w      _c,
    const tvector1w     _d);


/* Miscellaneous */

STORAGE_CLASS_ISP2600_OP1W_H tvector1w OP_vec1w_clone(
    const tscalar1w     _b);

/* Use standard operations */
#define   OP_vec1w_mux      OP_vec_mux
#define   OP_vec1w_mux_c    OP_vec_mux_c
#define   OP_vec1w_mux_csel OP_vec_mux_csel
#define   OP_vec1w_max      OP_vec_max
#define   OP_vec1w_min      OP_vec_min

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tflags1w OP_vec1w_max_gt(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tflags1w OP_vec1w_max_gt_c(
    const tvector1w     _a,
    const tscalar1w     _c);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tflags1w OP_vec1w_min_le(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tvector1w_tflags1w OP_vec1w_min_le_c(
    const tvector1w     _a,
    const tscalar1w     _c);

/* Use standard operations */
#define   OP_vec1w_imax             OP_vec_imax
#define   OP_vec1w_imin             OP_vec_imin
#define   OP_vec1w_even             OP_vec_even
#define   OP_vec1w_odd              OP_vec_odd
#define   OP_vec1w_clipz            OP_vec_clipz
#define   OP_vec1w_clipz_c          OP_vec_clipz_c
#define   OP_vec1w_clip_asym        OP_vec_clip_asym
#define   OP_vec1w_clip_asym_c      OP_vec_clip_asym_c
#define   OP_vec1w_get              OP_vec_get
#define   OP_vec1w_set              OP_vec_set
#define   OP_vec1w_neg              OP_vec_neg
#define   OP_vec1w_abs              OP_vec_abs
#define   OP_vec1w_subabs           OP_vec_subabs
#define   OP_vec1w_mergeh           OP_vec_mergeh
#define   OP_vec1w_mergel           OP_vec_mergel
#define   OP_vec1w_avgrnd           OP_vec_avgrnd
#define   OP_vec1w_avgrnd_c         OP_vec_avgrnd_c
#define   OP_vec1w_subhalfrnd       OP_vec_subhalfrnd
#define   OP_vec1w_subhalfrnd_c     OP_vec_subhalfrnd_c
#define   OP_vec1w_deint3           OP_vec_deint3
#define   OP_vec1w_groupshuffle8    OP_vec_groupshuffle8
#define   OP_vec1w_groupshuffle16   OP_vec_groupshuffle16
#define   OP_vec1w_shuffle16        OP_vec_shuffle16


/* Supporting functions */

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_comparator(
    const tvector1w     _a,
    const tvector1w     _b,
    const tflags1w        eq);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_comparator_lt(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP2600_OP1W_H tflags1w OP_vec1w_comparator_le(
    const tvector1w     _a,
    const tvector1w     _b);


#endif /* __ISP2400_VEC1W_H_INCLUDED__ */
