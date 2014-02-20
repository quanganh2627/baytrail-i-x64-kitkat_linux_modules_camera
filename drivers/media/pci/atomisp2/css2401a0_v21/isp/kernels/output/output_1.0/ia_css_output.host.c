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

#include "ia_css_frame.h"
#include "ia_css.h"
#define IA_CSS_INCLUDE_CONFIGURATIONS
#include "ia_css_isp_configs.h"
#include "ia_css_output.host.h"
#include "isp.h"

#include "assert_support.h"

void
ia_css_output_config(
	struct sh_css_isp_output_isp_config *to,
	const struct ia_css_output_configuration  *from)
{
	unsigned elems_a = ISP_VEC_NELEMS;
	ia_css_dma_configure_from_info(&to->port_b, from->info);
	to->width_a_over_b = elems_a / to->port_b.elems;
	to->height = from->info->res.height;

	/* Assume divisiblity here, may need to generalize to fixed point. */
	assert (elems_a % to->port_b.elems == 0);
}

void
ia_css_output0_config(
	struct sh_css_isp_output_isp_config      *to,
	const struct ia_css_output0_configuration *from)
{
	ia_css_output_config (
		to, (const struct ia_css_output_configuration *)from);
}

void
ia_css_output1_config(
	struct sh_css_isp_output_isp_config      *to,
	const struct ia_css_output1_configuration *from)
{
	ia_css_output_config (
		to, (const struct ia_css_output_configuration *)from);
}

void
ia_css_output_configure(
	const struct ia_css_binary     *binary,
	const struct ia_css_frame_info *info)
{
	const struct ia_css_output_configuration config =
		{ info };
	if (info)
		ia_css_configure_output(binary, &config);
}

void
ia_css_output0_configure(
	const struct ia_css_binary     *binary,
	const struct ia_css_frame_info *info)
{
	const struct ia_css_output0_configuration config =
		{ info };
	if (info)
		ia_css_configure_output0(binary, &config);
}

void
ia_css_output1_configure(
	const struct ia_css_binary     *binary,
	const struct ia_css_frame_info *info)
{
	const struct ia_css_output1_configuration config =
		{ info };
	if (info)
		ia_css_configure_output1(binary, &config);
}