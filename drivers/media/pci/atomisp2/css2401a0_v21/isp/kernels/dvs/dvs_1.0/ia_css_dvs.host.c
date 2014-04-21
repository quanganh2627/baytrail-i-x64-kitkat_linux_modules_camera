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

#include "ia_css_frame_public.h"
#define IA_CSS_INCLUDE_CONFIGURATIONS
#include "ia_css_isp_configs.h"

#include "sh_css_param_dvs.h"
#include "sh_css_params.h"
#include "ia_css_binary.h"
#include "ia_css_debug.h"
#include "memory_access.h"
#include "assert_support.h"

#include "ia_css_dvs.host.h"


void
ia_css_dvs_config(
	struct sh_css_isp_dvs_isp_config *to,
	const struct ia_css_dvs_configuration  *from)
{
	to->num_horizontal_blocks =
	    DVS_NUM_BLOCKS_X(from->info->res.width);
	to->num_vertical_blocks =
	    DVS_NUM_BLOCKS_Y(from->info->res.height);
}

void
ia_css_dvs_configure(
	const struct ia_css_binary     *binary,
	const struct ia_css_frame_info *info)
{
	const struct ia_css_dvs_configuration config =
		{ info };
	ia_css_configure_dvs(binary, &config);
}

static void
convert_coords_to_ispparams(
	hrt_vaddress ddr_addr,
	const struct ia_css_dvs_6axis_config *config,
	unsigned int i_stride,
	unsigned int o_width,
	unsigned int o_height,
	unsigned int uv_flag)
{
	unsigned int i, j;
	gdc_warp_param_mem_t s;
	unsigned int x00, x01, x10, x11,
		     y00, y01, y10, y11;

	unsigned int xmin, ymin;
	unsigned int topleft_x, topleft_y,
		     topleft_x_frac, topleft_y_frac;

	/* number of blocks per height and width */
	unsigned int num_blocks_y =  (uv_flag ? DVS_NUM_BLOCKS_Y_CHROMA(o_height) : DVS_NUM_BLOCKS_Y(o_height) );
	unsigned int num_blocks_x =  (uv_flag ? DVS_NUM_BLOCKS_X_CHROMA(o_width)  : DVS_NUM_BLOCKS_X(o_width)  ); // round num_x up to blockdim_x, if it concerns the Y0Y1 block (uv_flag==0) round up to even


	unsigned int in_stride = i_stride * DVS_INPUT_BYTES_PER_PIXEL << uv_flag;
	unsigned width, height;
	unsigned int *xbuff = NULL;
	unsigned int *ybuff = NULL;

	assert(config != NULL);
	assert(ddr_addr != mmgr_NULL);

	ddr_addr += (2* DVS_6AXIS_COORDS_ELEMS * uv_flag); /* format is Y0 Y1 UV, so UV starts at 3rd position */

	if(uv_flag == 0)
	{
		xbuff = config->xcoords_y;
		ybuff = config->ycoords_y;
		width = config->width_y;
		height = config->height_y;
	}
	else
	{
		xbuff = config->xcoords_uv;
		ybuff = config->ycoords_uv;
		width = config->width_uv;
		height = config->height_uv;
	}

	IA_CSS_LOG("blockdim_x %d blockdim_y %d",
		   DVS_BLOCKDIM_X, DVS_BLOCKDIM_Y_LUMA >> uv_flag);
	IA_CSS_LOG("num_blocks_x %d num_blocks_y %d", num_blocks_x,num_blocks_y);
	IA_CSS_LOG("width %d height %d", width, height);

	assert(width == num_blocks_x + 1); // the width and height of the provided morphing table should be 1 more than the number of blocks
	assert(height == num_blocks_y + 1);

	for (j = 0; j < num_blocks_y; j++) {
		for (i = 0; i < num_blocks_x; i++) {

			x00 = xbuff[j * width + i];
			x01 = xbuff[j * width + (i+1)];
			x10 = xbuff[(j+1) * width + i];
			x11 = xbuff[(j+1) * width + (i+1)];

			y00 = ybuff[j * width + i];
			y01 = ybuff[j * width + (i+1)];
			y10 = ybuff[(j+1) * width + i];
			y11 = ybuff[(j+1) * width + (i+1)];

			xmin = min(x00, x10);
			ymin = min(y00, y01);

			/* Assert that right column's X is greater */
			assert ( x01 >= xmin);
			assert ( x11 >= xmin);
			/* Assert that bottom row's Y is greater */
			assert ( y10 >= ymin);
			assert ( y11 >= ymin);

#if 0
			/* TODO: Round width to the multiple of bus width */
			xmax = max(x01, x11);
			ymax = max(y10, y11);
			in_block_width  = xmax - xmin;
			in_block_height = ymax - ymin;
#else
			/*
			 * For initial testing, we are using constant input
			 * block size
			 * */
			s.in_block_width  = 128;
			s.in_block_height = 96 >> uv_flag;
#endif

			topleft_y = ymin >> DVS_COORD_FRAC_BITS;
			topleft_x = ((xmin >> DVS_COORD_FRAC_BITS)
					>> XMEM_ALIGN_LOG2)
					<< (XMEM_ALIGN_LOG2);

			s.in_addr_offset = topleft_y * in_stride + topleft_x;

			topleft_x_frac = topleft_x << (DVS_COORD_FRAC_BITS);
			topleft_y_frac = topleft_y << (DVS_COORD_FRAC_BITS);

			s.p0_x = x00 - topleft_x_frac;
			s.p1_x = x01 - topleft_x_frac;
			s.p2_x = x10 - topleft_x_frac;
			s.p3_x = x11 - topleft_x_frac;

			s.p0_y = y00 - topleft_y_frac;
			s.p1_y = y01 - topleft_y_frac;
			s.p2_y = y10 - topleft_y_frac;
			s.p3_y = y11 - topleft_y_frac;

			// block should fit within the boundingbox.
			assert(s.p0_x < (s.in_block_width << DVS_COORD_FRAC_BITS));
			assert(s.p1_x < (s.in_block_width << DVS_COORD_FRAC_BITS));
			assert(s.p2_x < (s.in_block_width << DVS_COORD_FRAC_BITS));
			assert(s.p3_x < (s.in_block_width << DVS_COORD_FRAC_BITS));
			assert(s.p0_y < (s.in_block_height << DVS_COORD_FRAC_BITS));
			assert(s.p1_y < (s.in_block_height << DVS_COORD_FRAC_BITS));
			assert(s.p2_y < (s.in_block_height << DVS_COORD_FRAC_BITS));
			assert(s.p3_y < (s.in_block_height << DVS_COORD_FRAC_BITS));

			// block size should be greater than zero.
			assert(s.p0_x < s.p1_x);
			assert(s.p2_x < s.p3_x);
			assert(s.p0_y < s.p2_y);
			assert(s.p1_y < s.p3_y);

#if 0
			printf("j: %d\ti:%d\n", j, i);
			printf("offset: %d\n", s.in_addr_offset);
			printf("p0_x: %d\n", s.p0_x);
			printf("p0_y: %d\n", s.p0_y);
			printf("p1_x: %d\n", s.p1_x);
			printf("p1_y: %d\n", s.p1_y);
			printf("p2_x: %d\n", s.p2_x);
			printf("p2_y: %d\n", s.p2_y);
			printf("p3_x: %d\n", s.p3_x);
			printf("p3_y: %d\n", s.p3_y);

			printf("p0_x_nofrac[0]: %d\n", s.p0_x>>DVS_COORD_FRAC_BITS);
			printf("p0_y_nofrac[1]: %d\n", s.p0_y>>DVS_COORD_FRAC_BITS);
			printf("p1_x_nofrac[2]: %d\n", s.p1_x>>DVS_COORD_FRAC_BITS);
			printf("p1_y_nofrac[3]: %d\n", s.p1_y>>DVS_COORD_FRAC_BITS);
			printf("p2_x_nofrac[0]: %d\n", s.p2_x>>DVS_COORD_FRAC_BITS);
			printf("p2_y_nofrac[1]: %d\n", s.p2_y>>DVS_COORD_FRAC_BITS);
			printf("p3_x_nofrac[2]: %d\n", s.p3_x>>DVS_COORD_FRAC_BITS);
			printf("p3_y_nofrac[3]: %d\n", s.p3_y>>DVS_COORD_FRAC_BITS);
			printf("\n");
#endif

			/* HMM STORE the struct "s" */
			mmgr_store(ddr_addr,
				   (void *)(&s),
				   sizeof(gdc_warp_param_mem_t));

			// storage format:
			// Y0 Y1 UV0 Y2 Y3 UV1
			if (uv_flag)
				ddr_addr += DVS_6AXIS_COORDS_ELEMS * 3;
			else
			    /* increment with 2 incase x is odd, this to
			       skip the uv position. */
				ddr_addr += DVS_6AXIS_COORDS_ELEMS * (1 + (i&1));
		}
	}
}

void
store_dvs_6axis_config(
	struct ia_css_isp_parameters *params,
	const struct ia_css_binary *binary,
	hrt_vaddress ddr_addr_y)
{
	unsigned int i_stride;
	unsigned int o_width;
	unsigned int o_height;

	assert(params != NULL);
	assert(binary != NULL);
	assert(ddr_addr_y != mmgr_NULL);
	assert(params->dvs_6axis_config != NULL);

	/* bgz115: replaced binary->in_frame_info.res.width for
	   'padded_width=stride' */
	i_stride  = binary->internal_frame_info.padded_width;
	o_width  = binary->out_frame_info[0].res.width;
	o_height = binary->out_frame_info[0].res.height;

	/* Y plane */
	convert_coords_to_ispparams(ddr_addr_y, params->dvs_6axis_config,
				    i_stride, o_width, o_height, 0);
	/* UV plane (packed inside the y plane) */
	convert_coords_to_ispparams(ddr_addr_y, params->dvs_6axis_config,
				    i_stride/2, o_width/2, o_height/2, 1);


	params->isp_params_changed = true;
}
