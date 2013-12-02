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

#ifndef __IA_CSS_FIXEDBDS_PARAM_H
#define __IA_CSS_FIXEDBDS_PARAM_H

/* enumeration of the bayer downscale factors. When a binary supports multiple
 * factors, the OR of these defines is used to build the mask of supported
 * factors. The BDS factor is used in pre-processor expressions so we cannot
 * use an enum here. */
#define SH_CSS_BDS_FACTOR_1_00	(0)
#define SH_CSS_BDS_FACTOR_1_25	(1)
#define SH_CSS_BDS_FACTOR_1_50	(2)
#define SH_CSS_BDS_FACTOR_2_00	(3)
#define SH_CSS_BDS_FACTOR_2_25	(4)
#define SH_CSS_BDS_FACTOR_2_50	(5)
#define SH_CSS_BDS_FACTOR_3_00	(6)
#define SH_CSS_BDS_FACTOR_4_00	(7)
#define SH_CSS_BDS_FACTOR_4_50	(8)
#define SH_CSS_BDS_FACTOR_5_00	(9)
#define SH_CSS_BDS_FACTOR_6_00	(10)
#define SH_CSS_BDS_FACTOR_8_00	(11)
#define NUM_BDS_FACTORS	        (12)

#define PACK_BDS_FACTOR(factor)	(1<<(factor))

#endif	/*__IA_CSS_FIXEDBDS_PARAM_H*/
