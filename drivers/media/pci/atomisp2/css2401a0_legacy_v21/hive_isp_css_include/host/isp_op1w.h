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

#ifndef __ISP_OP1W_H_INCLUDED__
#define __ISP_OP1W_H_INCLUDED__

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

#ifndef STORAGE_CLASS_ISP_OP1W_H
#define STORAGE_CLASS_ISP_OP1W_H extern
#endif

/*
 * Single-precision data type specification
 */

#include "isp_op1w_types.h"
#include "isp_op2w_types.h" // for doubling operations.

/*
 * Single-precision prototype specification
 */

/* Arithmetic */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_and(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_or(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_xor(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_inv(
    const tvector1w     _a);

/* Additive */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_add(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_sub(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_addsat(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_subsat(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_subasr1(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_abs(
    const tvector1w     _a);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_subabs(
    const tvector1w     _a,
    const tvector1w     _b);

/* Multiplicative */

STORAGE_CLASS_ISP_OP1W_H tvector2w OP_1w_muld(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_mul(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_qmul(
    const tvector1w     _a,
    const tvector1w     _b);

/* Comparative */

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_eq(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_ne(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_le(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_lt(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_ge(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tflags OP_1w_gt(
    const tvector1w     _a,
    const tvector1w     _b);

/* Shift */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_asr(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_asl(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_asrrnd(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_lsl(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_lslsat(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_lsr(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_lsrrnd(
    const tvector1w     _a,
    const tvector1w     _b);


/* Cast */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_int_cast_to_1w (
    const int           _a);

STORAGE_CLASS_ISP_OP1W_H int OP_1w_cast_to_int (
    const tvector1w      _a);

STORAGE_CLASS_ISP_OP1W_H tvector2w OP_1w_cast_to_2w (
    const tvector1w     _a);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_2w_cast_to_1w (
    const tvector2w    _a);

/* clipping */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_clip_asym(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_clipz(
    const tvector1w     _a,
    const tvector1w     _b);

/* division */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_div(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_mod(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_sqrt(
    const tvector1w     _a,
    const tvector1w     _b);

/* Miscellaneous */

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_mux(
    const tvector1w     _a,
    const tvector1w     _b,
    const tflags           _c);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_avgrnd(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_min(
    const tvector1w     _a,
    const tvector1w     _b);

STORAGE_CLASS_ISP_OP1W_H tvector1w OP_1w_max(
    const tvector1w     _a,
    const tvector1w     _b);

#endif /* __ISP_OP1W_H_INCLUDED__ */
