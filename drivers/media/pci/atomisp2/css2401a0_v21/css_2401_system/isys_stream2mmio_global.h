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

#ifndef __ISYS_STREAM2MMIO_GLOBAL_H_INCLUDED__
#define __ISYS_STREAM2MMIO_GLOBAL_H_INCLUDED__

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

typedef struct stream2mmio_cfg_s stream2mmio_cfg_t;
struct stream2mmio_cfg_s {
	uint32_t				bits_per_pixel;
};

#endif /* __ISYS_STREAM2MMIO_GLOBAL_H_INCLUDED__ */
