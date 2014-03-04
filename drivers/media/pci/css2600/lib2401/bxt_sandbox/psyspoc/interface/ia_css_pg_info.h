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

#ifndef __IA_CSS_PG_INFO_H__
#define __IA_CSS_PG_INFO_H__

#include "type_support.h"	/* for <errno.h>, for uint32_t etc. */
#include "system_types.h"	/* for hrt_vaddress */

/* Terminal types, as enumerated in the FAS */
enum ia_css_pg_terminal_type
{
	IA_CSS_PG_TERMINAL_TYPE_INPUT = 0,
	IA_CSS_PG_TERMINAL_TYPE_OUTPUT,
	IA_CSS_PG_TERMINAL_TYPE_PARAM,
	IA_CSS_PG_TERMINAL_TYPE_STATE_IN,
	IA_CSS_PG_TERMINAL_TYPE_STATE_OUT,
	IA_CSS_N_PG_TERMINAL_TYPE,
};

/* Frame formats for input and output terminals */
enum ia_css_pg_io_frame_format {
	IA_CSS_PG_IO_FRAME_FORMAT_NV11,       /**< 12 bit YUV 411, Y, UV plane */
	IA_CSS_PG_IO_FRAME_FORMAT_NV12,       /**< 12 bit YUV 420, Y, UV plane */
	IA_CSS_PG_IO_FRAME_FORMAT_NV16,       /**< 16 bit YUV 422, Y, UV plane */
	IA_CSS_PG_IO_FRAME_FORMAT_NV21,       /**< 12 bit YUV 420, Y, VU plane */
	IA_CSS_PG_IO_FRAME_FORMAT_NV61,       /**< 16 bit YUV 422, Y, VU plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YV12,       /**< 12 bit YUV 420, Y, V, U plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YV16,       /**< 16 bit YUV 422, Y, V, U plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV420,     /**< 12 bit YUV 420, Y, U, V plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV420_16,  /**< yuv420, 16 bits per subpixel */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV422,     /**< 16 bit YUV 422, Y, U, V plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV422_16,  /**< yuv422, 16 bits per subpixel */
	IA_CSS_PG_IO_FRAME_FORMAT_UYVY,       /**< 16 bit YUV 422, UYVY interleaved */
	IA_CSS_PG_IO_FRAME_FORMAT_YUYV,       /**< 16 bit YUV 422, YUYV interleaved */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV444,     /**< 24 bit YUV 444, Y, U, V plane */
	IA_CSS_PG_IO_FRAME_FORMAT_YUV_LINE,   /**< Internal format, 2 y lines followed
					     by a uvinterleaved line */
	IA_CSS_PG_IO_FRAME_FORMAT_RAW,	/**< RAW, 1 plane */
	IA_CSS_PG_IO_FRAME_FORMAT_RGB565,     /**< 16 bit RGB, 1 plane. Each 3 sub
					     pixels are packed into one 16 bit
					     value, 5 bits for R, 6 bits for G
					     and 5 bits for B. */
	IA_CSS_PG_IO_FRAME_FORMAT_PLANAR_RGB888, /**< 24 bit RGB, 3 planes */
	IA_CSS_PG_IO_FRAME_FORMAT_RGBA888,	/**< 32 bit RGBA, 1 plane, A=Alpha
					     (alpha is unused) */
	IA_CSS_PG_IO_FRAME_FORMAT_QPLANE6, /**< Internal, for advanced ISP */
	IA_CSS_PG_IO_FRAME_FORMAT_BINARY_8,	/**< byte stream, used for jpeg. For
					     frames of this type, we set the
					     height to 1 and the width to the
					     number of allocated bytes. */
	IA_CSS_PG_IO_FRAME_FORMAT_MIPI,	/**< MIPI frame, 1 plane */
	IA_CSS_PG_IO_FRAME_FORMAT_RAW_PACKED, /**< RAW, 1 plane, packed */
};

/*****************************************************************************
* Terminal type independent descriptor.
* Ref: https://icggerrit.ir.intel.com/#/c/702/1
*
*	"index" - index value unique to a terminal within a program group
*			  index values start from zero.
*	"type"  - type of terminal
*	"snooped" - whether the frames attached to this terminal are private to
				IUNIT or share with host.
*****************************************************************************/
struct ia_css_pg_terminal_descr
{
	uint32_t index;
	enum ia_css_pg_terminal_type type;
	uint8_t snooped;
};

/*****************************************************************************
* Input and Output Terminal attributes.
* TODO: Needs recategorization or explanation
*****************************************************************************/
struct ia_css_pg_io_terminal_attr
{
	uint32_t min_width;
	uint32_t min_height;
	uint32_t max_width;
	uint32_t max_height;
	uint32_t max_internal_width;
	uint32_t max_internal_height;
	uint32_t max_dvs_envelope_width;
	uint32_t max_dvs_envelope_height;

	/* TODO: clarify why this belongs here */
	uint32_t variable_vf_veceven;
	struct {
		uint8_t vf_veceven;
		uint8_t	dvs_envelope;
		uint8_t	output;
		uint8_t	ref_frame;
		uint8_t	tnr;
		uint8_t	input_chunking;
	} enable;
	/* TODO: clarify why this belongs here */
	uint32_t max_vf_log_downscale;
	uint32_t top_cropping;
	uint32_t left_cropping;
	uint32_t c_subsampling;
	uint32_t output_num_chunks;
	uint32_t block_width;
	uint32_t block_height;
	uint32_t output_block_height;
	uint32_t dvs_in_block_width;
	uint32_t dvs_in_block_height;
	/* TODO: Support publishing attributes with multiple frame formats */
	// uint32_t num_frame_formats;
	enum ia_css_pg_io_frame_format format;
};

/*****************************************************************************
* Parameter Terminal attributes.
*****************************************************************************/
struct ia_css_pg_param_terminal_attr
{
	/*Silent the compiler*/
	uint32_t dummy1;
};

/*****************************************************************************
* State Terminal attributes.
*****************************************************************************/
struct ia_css_pg_state_terminal_attr
{
	/*Silent the compiler*/
	uint32_t dummy2;
};
/*****************************************************************************
* Each terminal contains one of these attributes depending on the terminal
* type.
*****************************************************************************/
union ia_css_pg_terminal_attr_union
{
	struct ia_css_pg_io_terminal_attr input_terminal_attr;
	struct ia_css_pg_io_terminal_attr output_terminal_attr;
	struct ia_css_pg_param_terminal_attr param_terminal_attr;
	struct ia_css_pg_state_terminal_attr statein_terminal_attr;
	struct ia_css_pg_state_terminal_attr stateout_terminal_attr;
};

/*****************************************************************************
* Object representation of a Terminal.
*	"descr" - general descriptor for the terminal
*	"attr" - Union describing attributes depending on the terminal type.
*****************************************************************************/
struct ia_css_pg_terminal
{
	struct ia_css_pg_terminal_descr descr;
	union ia_css_pg_terminal_attr_union attr;
};

/*****************************************************************************
* Object representation of a Terminal List.
* Ref: https://icggerrit.ir.intel.com/#/c/702/1
*
*	"no_of_terminals" - No. of terminals of all types.
*	"terminals" - Terminals with their description and attributes.
*
*	Example: To access input terminals:
*	struct ia_css_pg_terminal_list tl;
*	for(int i = 0; i < tl->no_of_terminals; i++) {
*		if(tl->terminals[i].descr.type == IA_CSS_PG_TERMINAL_TYPE_INPUT)
*			struct ia_css_pg_terminal *t = tl->terminals[i];
*	}
*
*****************************************************************************/
struct ia_css_pg_terminal_list
{
	uint32_t no_of_terminals;
	struct ia_css_pg_terminal *terminals;
};

/*****************************************************************************
* POC only object. List of all DMA channels that ISP assumes to own. SP cannot
* use these channels.
*****************************************************************************/
struct ia_css_pg_dma_resource_info
{
	uint8_t	crop_channel;
	uint8_t	multi_channel;
	uint8_t	raw_out_channel;
	uint8_t	ref_y_channel;
	uint8_t	ref_c_channel;
	uint8_t	tnr_channel;
	uint8_t	tnr_out_channel;
	uint8_t	dvs_in_channel;
	uint8_t	dvs_coords_channel;
	uint8_t	output_channel;
	uint8_t	c_channel;
	uint8_t	vfout_channel;
	uint8_t	vfout_c_channel;
};

/* TODO; Consider eliminating this. */
struct ia_css_pg_resource_info
{
	struct ia_css_pg_dma_resource_info dma;
};

/* TODO; Consider eliminating this. */
struct ia_css_pg_param_info
{
	/* TODO: transform this definition for psys */
	/* struct ia_css_isp_param_isp_segments mem_initializers; */

	struct {
		uint16_t	bpp;
		uint16_t	use_bci;
		uint16_t	use_str;
		uint16_t	woix;
		uint16_t	woiy;
		uint16_t	extra_out_vecs;
		uint16_t	vectors_per_line_in;
		uint16_t	vectors_per_line_out;
		uint16_t	vectors_c_per_line_in;
		uint16_t	vectors_c_per_line_out;
		uint16_t	vmem_gdc_in_block_height_y;
		uint16_t	vmem_gdc_in_block_height_c;
	} uds;
};

/*****************************************************************************
* Carry program header information. The program id is obtained after mapping
* the program via IMR.
*****************************************************************************/
struct ia_css_program_info
{
	uint32_t program_id;
};

/*****************************************************************************
* Structure that describes a program group. The fields here come from various
* librarians.
* "no_of_programs" - number of programs in this program group.
* "program_info" - array of program headers for each program.
* "terminal_list" - terminal array for each terminal in the PG.
*****************************************************************************/
struct ia_css_pg_info
{
	uint32_t no_of_programs;
	struct ia_css_program_info *program_info;
	struct ia_css_pg_terminal_list terminal_list;
};

#endif /* __IA_CSS_PG_INFO_H__ */

