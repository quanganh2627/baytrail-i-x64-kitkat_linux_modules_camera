/* Release Version: ci_master_20131001_0952 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2013 Intel Corporation. All Rights Reserved.
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

#ifndef __INPUT_SYSTEM_LOCAL_H_INCLUDED__
#define __INPUT_SYSTEM_LOCAL_H_INCLUDED__

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdbool.h>
#endif

#include "input_system_global.h"

typedef input_system_err_t input_system_error_t;

typedef enum {
	MIPI_FORMAT_RGB888 = 0,
	MIPI_FORMAT_RGB555,
	MIPI_FORMAT_RGB444,
	MIPI_FORMAT_RGB565,
	MIPI_FORMAT_RGB666,
	MIPI_FORMAT_RAW8,		/* 5 */
	MIPI_FORMAT_RAW10,
	MIPI_FORMAT_RAW6,
	MIPI_FORMAT_RAW7,
	MIPI_FORMAT_RAW12,
	MIPI_FORMAT_RAW14,		/* 10 */
	MIPI_FORMAT_YUV420_8,
	MIPI_FORMAT_YUV420_10,
	MIPI_FORMAT_YUV422_8,
	MIPI_FORMAT_YUV422_10,
	MIPI_FORMAT_CUSTOM0,		/* 15 */
	MIPI_FORMAT_YUV420_8_LEGACY,
	MIPI_FORMAT_EMBEDDED,
	MIPI_FORMAT_CUSTOM1,
	MIPI_FORMAT_CUSTOM2,
	MIPI_FORMAT_CUSTOM3,		/* 20 */
	MIPI_FORMAT_CUSTOM4,
	MIPI_FORMAT_CUSTOM5,
	MIPI_FORMAT_CUSTOM6,
	MIPI_FORMAT_CUSTOM7,
	MIPI_FORMAT_YUV420_8_SHIFT,	/* 25 */
	MIPI_FORMAT_YUV420_10_SHIFT,
	MIPI_FORMAT_RAW16,
	MIPI_FORMAT_RAW18,
	N_MIPI_FORMAT,
} mipi_format_t;

#define MIPI_FORMAT_JPEG	MIPI_FORMAT_CUSTOM0
#define MIPI_FORMAT_BINARY_8	MIPI_FORMAT_CUSTOM0
#define N_MIPI_FORMAT_CUSTOM	8

/* The number of stores for compressed format types */
#define	N_MIPI_COMPRESSOR_CONTEXT	(N_RX_CHANNEL_ID * N_MIPI_FORMAT_CUSTOM)

typedef enum {
	MIPI_PREDICTOR_NONE = 0,
	MIPI_PREDICTOR_TYPE1,
	MIPI_PREDICTOR_TYPE2,
	N_MIPI_PREDICTOR_TYPES
} mipi_predictor_t;

#endif /* __INPUT_SYSTEM_LOCAL_H_INCLUDED__ */
