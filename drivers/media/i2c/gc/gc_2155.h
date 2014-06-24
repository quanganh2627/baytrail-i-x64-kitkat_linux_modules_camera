/* Private header file for GC2155
 *
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
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
#ifndef __GC_2155_H__
#define __GC_2155_H__


#define GC2155_IMG_ORIENTATION			0x17
#define GC2155_FOCAL_LENGTH_NUM	208	/*2.08mm*/
#define GC2155_FOCAL_LENGTH_DEM	100
#define GC_F_NUMBER_DEFAULT_NUM	24
#define GC2155_F_NUMBER_DEM	10
#define GC2155_REG_EXPO_COARSE		  0x03
#define GC2155_REG_MAX_AEC			  0x3c
#define GC2155_REG_COLOR_EFFECT		 0x83
#define GC2155_REG_BLOCK_ENABLE			0x82

/*
 * focal length bits definition:
 * bits 31-16: numerator, bits 15-0: denominator
 */

#define GC_FOCAL_LENGTH_DEFAULT 0x1710064
/*
 * current f-number bits definition:
 * bits 31-16: numerator, bits 15-0: denominator
 */
#define GC_F_NUMBER_DEFAULT 0x16000a

/*
 * f-number range bits definition:
 * bits 31-24: max f-number numerator
 * bits 23-16: max f-number denominator
 * bits 15-8: min f-number numerator
 * bits 7-0: min f-number denominator
 */
#define GC_F_NUMBER_RANGE 0x160a160a

#define GC2155_FOCAL_VALUE ((GC2155_FOCAL_LENGTH_NUM << 16) | GC2155_FOCAL_LENGTH_DEM)

#define GC2155_FNUMBER_VALUE ((GC_F_NUMBER_DEFAULT_NUM << 16) | GC2155_F_NUMBER_DEM)

#define GC2155_FNUMBER_RANGE_VALUE ((GC_F_NUMBER_DEFAULT_NUM << 24) | \
		(GC2155_F_NUMBER_DEM << 16) |\
		(GC_F_NUMBER_DEFAULT_NUM << 8) | GC2155_F_NUMBER_DEM)





static struct gc_register  gc2155_exposure_neg4[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x40 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0xc0 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},

};

static struct gc_register  gc2155_exposure_neg3[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x50 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0xd0 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_neg2[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x60 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0xe0 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_neg1[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x70 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0xf0 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_zero[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x80 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0x00 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_pos1[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x98 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0x10 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_pos2[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0xb0 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0x20 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_pos3[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0xc0 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register  gc2155_exposure_pos4[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0xd0 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd5, 0x50 },
	{ GC_8BIT, 0xfe, 0x00 },
	/* end of the list marker */
	{GC_TOK_TERM, 0, 0},
};

/* For GC2155 setting, the value is skewed by 2 */
static struct gc_table_map gc2155_exposure_tables[] = {
	{-4, gc2155_exposure_neg4},
	{-3, gc2155_exposure_neg3},
	{-2, gc2155_exposure_neg2},
	{-1, gc2155_exposure_neg1},
	{0, gc2155_exposure_zero},
	{1, gc2155_exposure_pos1},
	{2, gc2155_exposure_pos2},
	{3, gc2155_exposure_pos3},
	{4, gc2155_exposure_pos4},
};



static struct gc_register gc2155_init_settings[] = {
	{ GC_8BIT, 0xfe, 0xf0 },
	{ GC_8BIT, 0xfe, 0xf0 },
	{ GC_8BIT, 0xfe, 0xf0 },
	{ GC_8BIT, 0xfc, 0x06 },
	{ GC_8BIT, 0xf6, 0x00 },
	{ GC_8BIT, 0xf7, 0x1d },
	{ GC_8BIT, 0xf8, 0x84 },
	{ GC_8BIT, 0xfa, 0x00 },
	{ GC_8BIT, 0xf9, 0x8e },
	{ GC_8BIT, 0xf2, 0x00 },



	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0xb0 },
	{ GC_8BIT, 0x09, 0x00 },
	{ GC_8BIT, 0x0a, 0x00 },
	{ GC_8BIT, 0x0b, 0x00 },
	{ GC_8BIT, 0x0c, 0x00 },
	{ GC_8BIT, 0x0d, 0x04 },
	{ GC_8BIT, 0x0e, 0xc0 },
	{ GC_8BIT, 0x0f, 0x06 },
	{ GC_8BIT, 0x10, 0x50 },
	{ GC_8BIT, 0x12, 0x2e },
	{ GC_8BIT, 0x17, 0x14 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x19, 0x0e },
	{ GC_8BIT, 0x1a, 0x01 },
	{ GC_8BIT, 0x1b, 0x4b },
	{ GC_8BIT, 0x1c, 0x07 },
	{ GC_8BIT, 0x1d, 0x10 },
	{ GC_8BIT, 0x1e, 0x98 },
	{ GC_8BIT, 0x1f, 0x78 },
	{ GC_8BIT, 0x20, 0x05 },
	{ GC_8BIT, 0x21, 0x40 },
	{ GC_8BIT, 0x22, 0xf0 },
	{ GC_8BIT, 0x24, 0x16 },
	{ GC_8BIT, 0x25, 0x01 },
	{ GC_8BIT, 0x26, 0x10 },
	{ GC_8BIT, 0x2d, 0x40 },
	{ GC_8BIT, 0x30, 0x01 },
	{ GC_8BIT, 0x31, 0x90 },
	{ GC_8BIT, 0x33, 0x04 },
	{ GC_8BIT, 0x34, 0x01 },



	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x80, 0xff },
	{ GC_8BIT, 0x81, 0x2c },
	{ GC_8BIT, 0x82, 0xfa },
	{ GC_8BIT, 0x83, 0x00 },
	{ GC_8BIT, 0x84, 0x00 },
	{ GC_8BIT, 0x85, 0x08 },
	{ GC_8BIT, 0x86, 0x02 },
	{ GC_8BIT, 0x89, 0x03 },
	{ GC_8BIT, 0x8a, 0x00 },
	{ GC_8BIT, 0x8b, 0x00 },
	{ GC_8BIT, 0xb0, 0x55 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xc6, 0x38 },
	{ GC_8BIT, 0xc7, 0x40 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xb6, 0x01 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x00 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x04 },
	{ GC_8BIT, 0x96, 0xb0 },
	{ GC_8BIT, 0x97, 0x06 },
	{ GC_8BIT, 0x98, 0x40 },



	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x40, 0x42 },
	{ GC_8BIT, 0x41, 0x00 },
	{ GC_8BIT, 0x43, 0x54 },
	{ GC_8BIT, 0x5e, 0x00 },
	{ GC_8BIT, 0x5f, 0x00 },
	{ GC_8BIT, 0x60, 0x00 },
	{ GC_8BIT, 0x61, 0x00 },
	{ GC_8BIT, 0x62, 0x00 },
	{ GC_8BIT, 0x63, 0x00 },
	{ GC_8BIT, 0x64, 0x00 },
	{ GC_8BIT, 0x65, 0x00 },
	{ GC_8BIT, 0x66, 0x20 },
	{ GC_8BIT, 0x67, 0x20 },
	{ GC_8BIT, 0x68, 0x20 },
	{ GC_8BIT, 0x69, 0x20 },
	{ GC_8BIT, 0x6a, 0x08 },
	{ GC_8BIT, 0x6b, 0x08 },
	{ GC_8BIT, 0x6c, 0x08 },
	{ GC_8BIT, 0x6d, 0x08 },
	{ GC_8BIT, 0x6e, 0x08 },
	{ GC_8BIT, 0x6f, 0x08 },
	{ GC_8BIT, 0x70, 0x08 },
	{ GC_8BIT, 0x71, 0x08 },
	{ GC_8BIT, 0x72, 0xf0 },
	{ GC_8BIT, 0x7e, 0x3c },
	{ GC_8BIT, 0x7f, 0x00 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x09, 0x00 },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x0b, 0x11 },
	{ GC_8BIT, 0x0c, 0x10 },
	{ GC_8BIT, 0x13, 0x2d },
	{ GC_8BIT, 0x17, 0x00 },
	{ GC_8BIT, 0x1c, 0x11 },
	{ GC_8BIT, 0x1e, 0x61 },
	{ GC_8BIT, 0x1f, 0x30 },
	{ GC_8BIT, 0x20, 0x40 },
	{ GC_8BIT, 0x22, 0x80 },
	{ GC_8BIT, 0x23, 0x20 },

	{ GC_8BIT, 0x12, 0x35 },
	{ GC_8BIT, 0x15, 0x50 },
	{ GC_8BIT, 0x10, 0x31 },
	{ GC_8BIT, 0x3e, 0x28 },
	{ GC_8BIT, 0x3f, 0xe0 },
	{ GC_8BIT, 0x40, 0xe0 },
	{ GC_8BIT, 0x41, 0x08 },

	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x0f, 0x05 },



	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x90, 0x6c },
	{ GC_8BIT, 0x91, 0x03 },
	{ GC_8BIT, 0x92, 0xc4 },
	{ GC_8BIT, 0x97, 0x64 },
	{ GC_8BIT, 0x98, 0x88 },
	{ GC_8BIT, 0x9d, 0x08 },
	{ GC_8BIT, 0xa2, 0x11 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x80, 0xc1 },
	{ GC_8BIT, 0x81, 0x08 },
	{ GC_8BIT, 0x82, 0x05 },
	{ GC_8BIT, 0x83, 0x04 },
	{ GC_8BIT, 0x84, 0x0a },
	{ GC_8BIT, 0x86, 0x80 },
	{ GC_8BIT, 0x87, 0x30 },
	{ GC_8BIT, 0x88, 0x15 },
	{ GC_8BIT, 0x89, 0x80 },
	{ GC_8BIT, 0x8a, 0x60 },
	{ GC_8BIT, 0x8b, 0x30 },



	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x3c, 0x06 },
	{ GC_8BIT, 0x3d, 0x40 },
	{ GC_8BIT, 0x48, 0x30 },
	{ GC_8BIT, 0x49, 0x06 },
	{ GC_8BIT, 0x4b, 0x08 },
	{ GC_8BIT, 0x4c, 0x20 },
	{ GC_8BIT, 0xa3, 0x50 },
	{ GC_8BIT, 0xa4, 0x30 },
	{ GC_8BIT, 0xa5, 0x40 },
	{ GC_8BIT, 0xa6, 0x80 },
	{ GC_8BIT, 0xab, 0x40 },
	{ GC_8BIT, 0xae, 0x0c },
	{ GC_8BIT, 0xb3, 0x42 },
	{ GC_8BIT, 0xb4, 0x24 },
	{ GC_8BIT, 0xb6, 0x50 },
	{ GC_8BIT, 0xb7, 0x01 },
	{ GC_8BIT, 0xb9, 0x28 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x10, 0x0d },
	{ GC_8BIT, 0x11, 0x12 },
	{ GC_8BIT, 0x12, 0x17 },
	{ GC_8BIT, 0x13, 0x1c },
	{ GC_8BIT, 0x14, 0x27 },
	{ GC_8BIT, 0x15, 0x34 },
	{ GC_8BIT, 0x16, 0x44 },
	{ GC_8BIT, 0x17, 0x55 },
	{ GC_8BIT, 0x18, 0x6e },
	{ GC_8BIT, 0x19, 0x81 },
	{ GC_8BIT, 0x1a, 0x91 },
	{ GC_8BIT, 0x1b, 0x9c },
	{ GC_8BIT, 0x1c, 0xaa },
	{ GC_8BIT, 0x1d, 0xbb },
	{ GC_8BIT, 0x1e, 0xca },
	{ GC_8BIT, 0x1f, 0xd5 },
	{ GC_8BIT, 0x20, 0xe0 },
	{ GC_8BIT, 0x21, 0xe7 },
	{ GC_8BIT, 0x22, 0xed },
	{ GC_8BIT, 0x23, 0xf6 },
	{ GC_8BIT, 0x24, 0xfb },
	{ GC_8BIT, 0x25, 0xff },

	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0x26, 0x0d },
	{ GC_8BIT, 0x27, 0x12 },
	{ GC_8BIT, 0x28, 0x17 },
	{ GC_8BIT, 0x29, 0x1c },
	{ GC_8BIT, 0x2a, 0x27 },
	{ GC_8BIT, 0x2b, 0x34 },
	{ GC_8BIT, 0x2c, 0x44 },
	{ GC_8BIT, 0x2d, 0x55 },
	{ GC_8BIT, 0x2e, 0x6e },
	{ GC_8BIT, 0x2f, 0x81 },
	{ GC_8BIT, 0x30, 0x91 },
	{ GC_8BIT, 0x31, 0x9c },
	{ GC_8BIT, 0x32, 0xaa },
	{ GC_8BIT, 0x33, 0xbb },
	{ GC_8BIT, 0x34, 0xca },
	{ GC_8BIT, 0x35, 0xd5 },
	{ GC_8BIT, 0x36, 0xe0 },
	{ GC_8BIT, 0x37, 0xe7 },
	{ GC_8BIT, 0x38, 0xed },
	{ GC_8BIT, 0x39, 0xf6 },
	{ GC_8BIT, 0x3a, 0xfb },
	{ GC_8BIT, 0x3b, 0xff },



	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xd1, 0x28 },
	{ GC_8BIT, 0xd2, 0x28 },
	{ GC_8BIT, 0xdd, 0x14 },
	{ GC_8BIT, 0xde, 0x88 },
	{ GC_8BIT, 0xed, 0x80 },



	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xc2, 0x13 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x0e },
	{ GC_8BIT, 0xc8, 0x11 },
	{ GC_8BIT, 0xc9, 0x0f },
	{ GC_8BIT, 0xca, 0x06 },
	{ GC_8BIT, 0xbc, 0x38 },
	{ GC_8BIT, 0xbd, 0x2c },
	{ GC_8BIT, 0xbe, 0x25 },
	{ GC_8BIT, 0xb6, 0x38 },
	{ GC_8BIT, 0xb7, 0x31 },
	{ GC_8BIT, 0xb8, 0x2f },
	{ GC_8BIT, 0xc5, 0x00 },
	{ GC_8BIT, 0xc6, 0x00 },
	{ GC_8BIT, 0xc7, 0x00 },
	{ GC_8BIT, 0xcb, 0x00 },
	{ GC_8BIT, 0xcc, 0x00 },
	{ GC_8BIT, 0xcd, 0x00 },
	{ GC_8BIT, 0xbf, 0x11 },
	{ GC_8BIT, 0xc0, 0x00 },
	{ GC_8BIT, 0xc1, 0x00 },
	{ GC_8BIT, 0xb9, 0x08 },
	{ GC_8BIT, 0xba, 0x00 },
	{ GC_8BIT, 0xbb, 0x00 },
	{ GC_8BIT, 0xaa, 0x0a },
	{ GC_8BIT, 0xab, 0x0c },
	{ GC_8BIT, 0xac, 0x0d },
	{ GC_8BIT, 0xad, 0x02 },
	{ GC_8BIT, 0xae, 0x06 },
	{ GC_8BIT, 0xaf, 0x05 },
	{ GC_8BIT, 0xb0, 0x0a },
	{ GC_8BIT, 0xb1, 0x08 },
	{ GC_8BIT, 0xb2, 0x00 },
	{ GC_8BIT, 0xb3, 0x04 },
	{ GC_8BIT, 0xb4, 0x04 },
	{ GC_8BIT, 0xb5, 0x05 },
	{ GC_8BIT, 0xd0, 0x00 },
	{ GC_8BIT, 0xd1, 0x00 },
	{ GC_8BIT, 0xd2, 0x00 },
	{ GC_8BIT, 0xd6, 0x02 },
	{ GC_8BIT, 0xd7, 0x00 },
	{ GC_8BIT, 0xd8, 0x00 },
	{ GC_8BIT, 0xd9, 0x00 },
	{ GC_8BIT, 0xda, 0x00 },
	{ GC_8BIT, 0xdb, 0x00 },
	{ GC_8BIT, 0xd3, 0x00 },
	{ GC_8BIT, 0xd4, 0x00 },
	{ GC_8BIT, 0xd5, 0x00 },
	{ GC_8BIT, 0xa4, 0x04 },
	{ GC_8BIT, 0xa5, 0x00 },
	{ GC_8BIT, 0xa6, 0x77 },
	{ GC_8BIT, 0xa7, 0x77 },
	{ GC_8BIT, 0xa8, 0x77 },
	{ GC_8BIT, 0xa9, 0x77 },
	{ GC_8BIT, 0xa1, 0x80 },
	{ GC_8BIT, 0xa2, 0x80 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xdc, 0x35 },
	{ GC_8BIT, 0xdd, 0x28 },
	{ GC_8BIT, 0xdf, 0x0d },
	{ GC_8BIT, 0xe0, 0x70 },
	{ GC_8BIT, 0xe1, 0x78 },
	{ GC_8BIT, 0xe2, 0x70 },
	{ GC_8BIT, 0xe3, 0x78 },
	{ GC_8BIT, 0xe6, 0x90 },
	{ GC_8BIT, 0xe7, 0x70 },
	{ GC_8BIT, 0xe8, 0x90 },
	{ GC_8BIT, 0xe9, 0x70 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x4f, 0x00 },
	{ GC_8BIT, 0x4f, 0x00 },
	{ GC_8BIT, 0x4b, 0x01 },
	{ GC_8BIT, 0x4f, 0x00 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x71 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x91 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x50 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x70 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x90 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xb0 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xd0 },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x4f },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x6f },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8f },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xaf },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xcf },
	{ GC_8BIT, 0x4e, 0x02 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x6e },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8e },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xae },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xce },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x4d },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x6d },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8d },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xad },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xcd },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x4c },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x6c },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8c },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xac },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xcc },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xec },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x4b },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x6b },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8b },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xab },
	{ GC_8BIT, 0x4e, 0x03 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0x8a },
	{ GC_8BIT, 0x4e, 0x04 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xaa },
	{ GC_8BIT, 0x4e, 0x04 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xca },
	{ GC_8BIT, 0x4e, 0x04 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xa9 },
	{ GC_8BIT, 0x4e, 0x04 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xc9 },
	{ GC_8BIT, 0x4e, 0x04 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xcb },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xeb },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x0b },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x2b },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x4b },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x01 },
	{ GC_8BIT, 0x4d, 0xea },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x0a },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x2a },
	{ GC_8BIT, 0x4e, 0x05 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x6a },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x29 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x49 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x69 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x89 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xa9 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xc9 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x48 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x68 },
	{ GC_8BIT, 0x4e, 0x06 },
	{ GC_8BIT, 0x4c, 0x03 },
	{ GC_8BIT, 0x4d, 0x09 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xa8 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xc8 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xe8 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x03 },
	{ GC_8BIT, 0x4d, 0x08 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x03 },
	{ GC_8BIT, 0x4d, 0x28 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0x87 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xa7 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xc7 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x02 },
	{ GC_8BIT, 0x4d, 0xe7 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0x4c, 0x03 },
	{ GC_8BIT, 0x4d, 0x07 },
	{ GC_8BIT, 0x4e, 0x07 },
	{ GC_8BIT, 0xfe, 0x01 },

	{ GC_8BIT, 0x50, 0x80 },
	{ GC_8BIT, 0x51, 0xa8 },
	{ GC_8BIT, 0x52, 0x57 },
	{ GC_8BIT, 0x53, 0x38 },
	{ GC_8BIT, 0x54, 0xc7 },
	{ GC_8BIT, 0x56, 0x0e },
	{ GC_8BIT, 0x58, 0x08 },
	{ GC_8BIT, 0x5b, 0x00 },
	{ GC_8BIT, 0x5c, 0x74 },
	{ GC_8BIT, 0x5d, 0x8b },
	{ GC_8BIT, 0x61, 0xd3 },
	{ GC_8BIT, 0x62, 0x90 },
	{ GC_8BIT, 0x63, 0xaa },
	{ GC_8BIT, 0x65, 0x04 },
	{ GC_8BIT, 0x67, 0xb2 },
	{ GC_8BIT, 0x68, 0xac },
	{ GC_8BIT, 0x69, 0x00 },
	{ GC_8BIT, 0x6a, 0xb2 },
	{ GC_8BIT, 0x6b, 0xac },
	{ GC_8BIT, 0x6c, 0xdc },
	{ GC_8BIT, 0x6d, 0xb0 },
	{ GC_8BIT, 0x6e, 0x30 },
	{ GC_8BIT, 0x6f, 0x40 },
	{ GC_8BIT, 0x70, 0x05 },
	{ GC_8BIT, 0x71, 0x80 },
	{ GC_8BIT, 0x72, 0x80 },
	{ GC_8BIT, 0x73, 0x30 },
	{ GC_8BIT, 0x74, 0x01 },
	{ GC_8BIT, 0x75, 0x01 },
	{ GC_8BIT, 0x7f, 0x08 },
	{ GC_8BIT, 0x76, 0x70 },
	{ GC_8BIT, 0x77, 0x48 },
	{ GC_8BIT, 0x78, 0xa0 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x02 },
	{ GC_8BIT, 0xc0, 0x01 },
	{ GC_8BIT, 0xc1, 0x4a },
	{ GC_8BIT, 0xc2, 0xf3 },
	{ GC_8BIT, 0xc3, 0xfc },
	{ GC_8BIT, 0xc4, 0xe4 },
	{ GC_8BIT, 0xc5, 0x48 },
	{ GC_8BIT, 0xc6, 0xec },
	{ GC_8BIT, 0xc7, 0x40 },
	{ GC_8BIT, 0xc8, 0xf0 },
	{ GC_8BIT, 0xc9, 0xff },
	{ GC_8BIT, 0xca, 0xf8 },
	{ GC_8BIT, 0xcb, 0x46 },
	{ GC_8BIT, 0xcc, 0xdc },
	{ GC_8BIT, 0xcd, 0x40 },
	{ GC_8BIT, 0xce, 0xf8 },
	{ GC_8BIT, 0xcf, 0xf4 },
	{ GC_8BIT, 0xe3, 0xe8 },
	{ GC_8BIT, 0xe4, 0x48 },
	{ GC_8BIT, 0xe5, 0xe4 },



	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x9f, 0x42 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xf2, 0x00 },


	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x06, 0x56 },
	{ GC_8BIT, 0x07, 0x00 },
	{ GC_8BIT, 0x08, 0x22 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x25, 0x00 },
	{ GC_8BIT, 0x26, 0xc8 },
	{ GC_8BIT, 0x27, 0x04 },
	{ GC_8BIT, 0x28, 0xb0 },
	{ GC_8BIT, 0x29, 0x06 },
	{ GC_8BIT, 0x2a, 0x40 },
	{ GC_8BIT, 0x2b, 0x07 },
	{ GC_8BIT, 0x2c, 0xd0 },
	{ GC_8BIT, 0x2d, 0x09 },
	{ GC_8BIT, 0x2e, 0x60 },
	{ GC_8BIT, 0xfe, 0x00 },




	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x01, 0x87 },
	{ GC_8BIT, 0x02, 0x22 },
	{ GC_8BIT, 0x03, 0x12 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x06, 0x88 },
	{ GC_8BIT, 0x11, 0x1e },
	{ GC_8BIT, 0x12, 0x80 },
	{ GC_8BIT, 0x13, 0x0c },
	{ GC_8BIT, 0x15, 0x12 },
	{ GC_8BIT, 0x17, 0xf0 },

	{ GC_8BIT, 0x21, 0x01 },
	{ GC_8BIT, 0x22, 0x02 },
	{ GC_8BIT, 0x23, 0x01 },
	{ GC_8BIT, 0x24, 0x10 },
	{ GC_8BIT, 0x29, 0x03 },
	{ GC_8BIT, 0x2a, 0x05 },
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xf8, 0x85 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x13, 0x2d },
	{ GC_8BIT, 0x2b, 0x04 },

	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_640x480[] = {
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfd, 0x00 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x55 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x02 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x00 },
	{ GC_8BIT, 0x9e, 0x00 },
	{ GC_8BIT, 0x9f, 0x02 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x00 },
	{ GC_8BIT, 0xa2, 0x00 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x00 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x01 },
	{ GC_8BIT, 0x96, 0xe0 },
	{ GC_8BIT, 0x97, 0x02 },
	{ GC_8BIT, 0x98, 0x80 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x01 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },


	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x12, 0x00 },
	{ GC_8BIT, 0x13, 0x05 },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_800x600[] = {
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfd, 0x01 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x11 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x00 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x00 },
	{ GC_8BIT, 0x9e, 0x00 },
	{ GC_8BIT, 0x9f, 0x00 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x00 },
	{ GC_8BIT, 0xa2, 0x00 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x00 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x02 },
	{ GC_8BIT, 0x96, 0x58 },
	{ GC_8BIT, 0x97, 0x03 },
	{ GC_8BIT, 0x98, 0x20 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x01 },
	{ GC_8BIT, 0xed, 0x02 },
	{ GC_8BIT, 0xee, 0x30 },
	{ GC_8BIT, 0xef, 0x48 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x00 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x04 },
	{ GC_8BIT, 0x02, 0x60 },
	{ GC_8BIT, 0x03, 0x02 },
	{ GC_8BIT, 0x04, 0x48 },
	{ GC_8BIT, 0x05, 0x18 },
	{ GC_8BIT, 0x06, 0x4c },
	{ GC_8BIT, 0x07, 0x14 },
	{ GC_8BIT, 0x08, 0x36 },
	{ GC_8BIT, 0x0a, 0xc0 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x12, 0x40 },
	{ GC_8BIT, 0x13, 0x06 },
	{ GC_8BIT, 0xfe, 0x00 },


	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_720x480[] = {
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfd, 0x01 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x11 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x00 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x00 },
	{ GC_8BIT, 0x9e, 0x00 },
	{ GC_8BIT, 0x9f, 0x00 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x00 },
	{ GC_8BIT, 0xa2, 0x00 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x3c },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x28 },
	{ GC_8BIT, 0x95, 0x01 },
	{ GC_8BIT, 0x96, 0xe8 },
	{ GC_8BIT, 0x97, 0x02 },
	{ GC_8BIT, 0x98, 0xd8 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x01 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },


	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x12, 0xb0 },
	{ GC_8BIT, 0x13, 0x05 },
	{ GC_8BIT, 0xfe, 0x00 },


	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_1280x720[] = {
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfd, 0x00 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x55 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x00 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x01 },
	{ GC_8BIT, 0x9e, 0x23 },
	{ GC_8BIT, 0x9f, 0x00 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x01 },
	{ GC_8BIT, 0xa2, 0x23 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x78 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x02 },
	{ GC_8BIT, 0x96, 0xd0 },
	{ GC_8BIT, 0x97, 0x05 },
	{ GC_8BIT, 0x98, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x01 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },


	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x12, 0x00 },
	{ GC_8BIT, 0x13, 0x0a },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_1280x960[] = {
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfd, 0x00 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x55 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x00 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x01 },
	{ GC_8BIT, 0x9e, 0x23 },
	{ GC_8BIT, 0x9f, 0x00 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x01 },
	{ GC_8BIT, 0xa2, 0x23 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x00 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x03 },
	{ GC_8BIT, 0x96, 0xc0 },
	{ GC_8BIT, 0x97, 0x05 },
	{ GC_8BIT, 0x98, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x01 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },


	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x01 },
	{ GC_8BIT, 0x12, 0x00 },
	{ GC_8BIT, 0x13, 0x0a },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_1600x1200[] =  {
	{ GC_8BIT, 0xfe, 0x00 },



	{ GC_8BIT, 0xfd, 0x00 },
	{ GC_8BIT, 0x18, 0x02 },
	{ GC_8BIT, 0x99, 0x11 },
	{ GC_8BIT, 0x9a, 0x06 },
	{ GC_8BIT, 0x9b, 0x00 },
	{ GC_8BIT, 0x9c, 0x00 },
	{ GC_8BIT, 0x9d, 0x00 },
	{ GC_8BIT, 0x9e, 0x00 },
	{ GC_8BIT, 0x9f, 0x00 },
	{ GC_8BIT, 0xa0, 0x00 },
	{ GC_8BIT, 0xa1, 0x00 },
	{ GC_8BIT, 0xa2, 0x00 },
	{ GC_8BIT, 0x90, 0x01 },
	{ GC_8BIT, 0x91, 0x00 },
	{ GC_8BIT, 0x92, 0x00 },
	{ GC_8BIT, 0x93, 0x00 },
	{ GC_8BIT, 0x94, 0x00 },
	{ GC_8BIT, 0x95, 0x04 },
	{ GC_8BIT, 0x96, 0xb0 },
	{ GC_8BIT, 0x97, 0x06 },
	{ GC_8BIT, 0x98, 0x40 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xec, 0x02 },
	{ GC_8BIT, 0xed, 0x04 },
	{ GC_8BIT, 0xee, 0x60 },
	{ GC_8BIT, 0xef, 0x90 },
	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x74, 0x01 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0x01, 0x08 },
	{ GC_8BIT, 0x02, 0xc0 },
	{ GC_8BIT, 0x03, 0x04 },
	{ GC_8BIT, 0x04, 0x90 },
	{ GC_8BIT, 0x05, 0x30 },
	{ GC_8BIT, 0x06, 0x98 },
	{ GC_8BIT, 0x07, 0x28 },
	{ GC_8BIT, 0x08, 0x6c },
	{ GC_8BIT, 0x0a, 0xc2 },
	{ GC_8BIT, 0x21, 0x14 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x01 },
	{ GC_8BIT, 0xa0, 0x03 },
	{ GC_8BIT, 0xfe, 0x00 },

	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xc3, 0x11 },
	{ GC_8BIT, 0xc4, 0x20 },
	{ GC_8BIT, 0xc5, 0x30 },
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x04, 0x01 },
	{ GC_8BIT, 0x05, 0x00 },
	{ GC_8BIT, 0x12, 0x80 },
	{ GC_8BIT, 0x13, 0x0c },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};




struct gc_resolution gc2155_res_video[] = {
	{
		.desc = "gc2155_1280x960",
		.regs = gc2155_1280x960,
		.width = 1280,
		.height = 960,
		.fps = 30, /* TODO */
		.pixels_per_line = 1280,
		.lines_per_frame = 960,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 4,
	},
	{
		.desc = "gc2155_640x480",
		.regs = gc2155_640x480,
		.width = 640,
		.height = 480,
		.fps = 30,
		.pixels_per_line = 640,
		.lines_per_frame = 480,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 4,
	},
	{
		.desc = "gc2155_720x480",
		.regs = gc2155_720x480,
		.width = 720,
		.height = 480,
		.fps = 30,
		.pixels_per_line = 720,
		.lines_per_frame = 480,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 4,
	},
	{
		.desc = "gc2155_800x600",
		.regs = gc2155_800x600,
		.width = 800,
		.height = 600,
		.fps = 30, /* TODO */
		.pixels_per_line = 800,
		.lines_per_frame = 600,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 4,
	},
	{
		.desc = "gc2155_1280x720",
		.regs = gc2155_1280x720,
		.width = 1280,
		.height = 720,
		.fps = 30, /* TODO */
		.pixels_per_line = 1280,
		.lines_per_frame = 720,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 4,
	},
	{
		.desc = "gc2155_1600x1200",
		.regs = gc2155_1600x1200,
		.width = 1600,
		.height = 1200,

		.fps = 30,
		.pixels_per_line = 1600,
		.lines_per_frame = 1200,

		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.used = 0,
		.skip_frames = 2,
		.bin_mode = 0,
	},
};

#define gc2155_res_preview	gc2155_res_video
#define gc2155_res_still	gc2155_res_video

struct gc_mode_info gc2155_mode_info[] = {
	[0] = {
		.init_settings = gc2155_init_settings,
		.res_preview = gc2155_res_preview,
		.res_still = gc2155_res_still,
		.res_video = gc2155_res_video,
		.n_res_preview = ARRAY_SIZE(gc2155_res_preview),
		.n_res_still = ARRAY_SIZE(gc2155_res_still),
		.n_res_video = ARRAY_SIZE(gc2155_res_video),
	},
};

#define GC2155_RES_WIDTH_MAX	1600
#define GC2155_RES_HEIGHT_MAX	1200

struct gc_max_res gc2155_max_res[] = {
	[0] = {
		.res_max_width = GC2155_RES_WIDTH_MAX,
		.res_max_height = GC2155_RES_HEIGHT_MAX,
	},
};


static struct gc_register gc2155_fmt_yuv422_uyvy16[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x00 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_fmt_yuv422_yuyv[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x02 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_register gc2155_fmt_yuv422_yvyu[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x03 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_fmt_yuv422_vyuy[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x01 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_fmt_yuv422_uyvy[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x00 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_fmt_raw[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x84, 0x18 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_mbus_fmt gc2155_mbus_formats[] = {
	{
		.desc		= "YUYV 4:2:2",
		.code		= V4L2_MBUS_FMT_UYVY8_1X16,
		.regs		= gc2155_fmt_yuv422_uyvy16,
		.size		= ARRAY_SIZE(gc2155_fmt_yuv422_uyvy16),
		.bpp		= 2,
	},
	{
		.desc		= "YUYV 4:2:2",
		.code		= V4L2_MBUS_FMT_YUYV8_2X8,
		.regs		= gc2155_fmt_yuv422_yuyv,
		.size		= ARRAY_SIZE(gc2155_fmt_yuv422_yuyv),
		.bpp		= 2,
	},
	{
		.desc		= "YVYU 4:2:2",
		.code		= V4L2_MBUS_FMT_YVYU8_2X8,
		.regs		= gc2155_fmt_yuv422_yvyu,
		.size		= ARRAY_SIZE(gc2155_fmt_yuv422_yvyu),
		.bpp		= 2,
	},
	{
		.desc		= "UYVY 4:2:2",
		.code		= V4L2_MBUS_FMT_UYVY8_2X8,
		.regs		= gc2155_fmt_yuv422_uyvy,
		.size		= ARRAY_SIZE(gc2155_fmt_yuv422_uyvy),
		.bpp		= 2,
	},
	{
		.desc		= "VYUY 4:2:2",
		.code		= V4L2_MBUS_FMT_VYUY8_2X8,
		.regs		= gc2155_fmt_yuv422_vyuy,
		.size		= ARRAY_SIZE(gc2155_fmt_yuv422_vyuy),
		.bpp		= 2,
	},
	{
		.desc		= "Raw RGB Bayer",
		.code		= V4L2_MBUS_FMT_SBGGR8_1X8,
		.regs		= gc2155_fmt_raw,
		.size		= ARRAY_SIZE(gc2155_fmt_raw),
		.bpp		= 1
	},

};

/* GC2155 stream_on and stream_off reg sequences */
static struct gc_register gc2155_stream_on[] = {
	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x10, 0x95 },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_stream_off[] = {
	{ GC_8BIT, 0xfe, 0x03 },
	{ GC_8BIT, 0x10, 0x81 },
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_table_map gc2155_stream_tables[] = {
	{ 0x0, gc2155_stream_off },
	{ 0x1, gc2155_stream_on  },
};

/* GC2155 vertical flip settings  */
static struct gc_register gc2155_vflip_on_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_8BIT_RMW_OR, GC2155_IMG_ORIENTATION, 0x02},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_vflip_off_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_8BIT_RMW_AND, GC2155_IMG_ORIENTATION, ~0x02},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_table_map gc2155_vflip_tables[] = {
	{0x0, gc2155_vflip_off_table },
	{0x1, gc2155_vflip_on_table  },
};

/* GC2155 horizontal flip settings */
static struct gc_register gc2155_hflip_on_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_8BIT_RMW_OR, GC2155_IMG_ORIENTATION, 0x01},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_hflip_off_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{GC_8BIT_RMW_AND, GC2155_IMG_ORIENTATION, ~0x01},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_table_map gc2155_hflip_tables[] = {
	{ 0x0, gc2155_hflip_off_table },
	{ 0x1, gc2155_hflip_on_table  },
};

/* GC2155 scene mode settings */
static struct gc_register gc2155_night_mode_on_table[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{GC_8BIT, GC2155_REG_MAX_AEC, 0x60},
	{GC_TOK_TERM, 0, 0},
};

/* Normal scene mode */
static struct gc_register gc2155_night_mode_off_table[] = {
	{ GC_8BIT, 0xfe, 0x01 },
	{GC_8BIT, GC2155_REG_MAX_AEC, 0x40},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_table_map gc2155_scene_mode_tables[] = {
	{ SCENE_MODE_AUTO, gc2155_night_mode_off_table },
	{ SCENE_MODE_NIGHT, gc2155_night_mode_on_table  },
};

/* GC2155 color settings */
static struct gc_register gc2155_color_none_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x00 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_mono_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x12 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_inverse_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x01 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_sepia_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x32 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_blue_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x62 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_green_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x52 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_skin_low_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x92 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_skin_med_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x72 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_color_skin_high_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0x83, 0x82 },
	{GC_TOK_TERM, 0, 0},
};

/* GC2155 settings for effect modes */
/* TODO: Get values from application - right now these are assumed values */
static struct gc_table_map gc2155_color_effect_tables[] = {
	{ 0x1, gc2155_color_none_table },
	{ 0x0, gc2155_color_mono_table },
	{ 0x2, gc2155_color_inverse_table },
	{ 0x3, gc2155_color_sepia_table },
	{ 0x4, gc2155_color_blue_table },
	{ 0x5, gc2155_color_green_table },
	{ 0x6, gc2155_color_skin_low_table },
	{ 0x7, gc2155_color_skin_med_table },
	{ 0x8, gc2155_color_skin_high_table },

};

/* GC2155 settings for auto white balance */
static struct gc_register gc2155_awb_mode_auto_table[] = {
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xb3, 0x61 },
	{ GC_8BIT, 0xb4, 0x40 },
	{ GC_8BIT, 0xb5, 0x61 },
	{GC_8BIT_RMW_OR, GC2155_REG_BLOCK_ENABLE, 0x02},
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_awb_mode_incandescent_table[] = {
	{GC_8BIT_RMW_AND, GC2155_REG_BLOCK_ENABLE, 0xfd},
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xb3, 0x50 },
	{ GC_8BIT, 0xb4, 0x40 },
	{ GC_8BIT, 0xb5, 0xa8 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_awb_mode_fluorescent_table[] = {
	{GC_8BIT_RMW_AND, GC2155_REG_BLOCK_ENABLE, 0xfd},
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xb3, 0x72 },
	{ GC_8BIT, 0xb4, 0x40 },
	{ GC_8BIT, 0xb5, 0x5b },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_awb_mode_daylight_table[] = {
	{GC_8BIT_RMW_AND, GC2155_REG_BLOCK_ENABLE, 0xfd},
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xb3, 0x70 },
	{ GC_8BIT, 0xb4, 0x40 },
	{ GC_8BIT, 0xb5, 0x50 },
	{GC_TOK_TERM, 0, 0},
};

static struct gc_register gc2155_awb_mode_cloudy_table[] = {
	{GC_8BIT_RMW_AND, GC2155_REG_BLOCK_ENABLE, 0xfd},
	{ GC_8BIT, 0xfe, 0x00 },
	{ GC_8BIT, 0xb3, 0x58 },
	{ GC_8BIT, 0xb4, 0x40 },
	{ GC_8BIT, 0xb5, 0x50 },
	{GC_TOK_TERM, 0, 0},
};


static struct gc_table_map gc2155_awb_mode_tables[] = {
	{ AWB_MODE_AUTO, gc2155_awb_mode_auto_table },
	{ AWB_MODE_INCANDESCENT, gc2155_awb_mode_incandescent_table },
	{ AWB_MODE_FLUORESCENT, gc2155_awb_mode_fluorescent_table },
	{ AWB_MODE_DAYLIGHT, gc2155_awb_mode_daylight_table },
	{ AWB_MODE_CLOUDY, gc2155_awb_mode_cloudy_table },
};


struct gc_product_info gc2155_product_info = {
	.name = "gc2155",
	.sensor_id = 0x2155,
	.mode_info = gc2155_mode_info,

	/* Optional controls */
	/*.ctrl_config = gc2155_ctrls,
	 .num_ctrls = ARRAY_SIZE(gc2155_ctrls),
*/

	.max_res = gc2155_max_res,

	.mbus_formats = gc2155_mbus_formats,
	.num_mbus_formats = ARRAY_SIZE(gc2155_mbus_formats),

	.focal	= GC2155_FOCAL_VALUE,
	.f_number =  GC2155_FNUMBER_VALUE,
	.f_number_range = GC2155_FNUMBER_RANGE_VALUE,

	.reg_expo_coarse = GC2155_REG_EXPO_COARSE,

	.settings_tables = {
		GC_ADD_SETTINGS_TABLES(GC_SETTING_STREAM, gc2155_stream_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_EXPOSURE, gc2155_exposure_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_VFLIP, gc2155_vflip_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_HFLIP, gc2155_hflip_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_SCENE_MODE, gc2155_scene_mode_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_COLOR_EFFECT, gc2155_color_effect_tables),
		GC_ADD_SETTINGS_TABLES(GC_SETTING_AWB_MODE, gc2155_awb_mode_tables),
	},

};


#endif /* __GC_2155_H__ */
