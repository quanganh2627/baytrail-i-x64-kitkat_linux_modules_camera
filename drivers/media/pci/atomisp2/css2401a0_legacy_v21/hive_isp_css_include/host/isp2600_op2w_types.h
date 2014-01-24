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

#ifndef __ISP2600_OP2W_TYPES_H_INCLUDED__
#define __ISP2600_OP2W_TYPES_H_INCLUDED__

/*
 * This file is part of the Multi-precision vector operations exstension package.
 */

/*
 * Double-precision vector operations
 */

/*
 * Prerequisites:
 *
 */
#include "mpmath.h"
#include "isp2600_config.h"

/*
 * Single-precision data type specification
 */


typedef mpsdata_t             tvector2w;
typedef mpsdata_t       tscalar2w;
typedef spsdata_t        tflags2w; // no double precision in flags

typedef struct {
	mpsdata_t slice[NUM_SLICE_ELEMS]; // array of slice elements.
}        tslice2w;


typedef struct {
  tvector2w       d;
  tflags2w        f;
} tvector2w_tflags;

#endif /* __ISP2600_OP2W_TYPES_H_INCLUDED__ */
