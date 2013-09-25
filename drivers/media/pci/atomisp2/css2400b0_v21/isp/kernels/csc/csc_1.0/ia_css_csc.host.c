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

#include "ia_css_types.h"
#include "sh_css_defs.h"
#include "ia_css_debug.h"

#include "ia_css_csc.host.h"

void
ia_css_encode_cc(struct sh_css_isp_csc_params *to,
		 const struct ia_css_cc_config *from)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_encode_cc() enter:\n");

	to->m_shift    = (int) from->fraction_bits;
	to->m00 = (int) from->matrix[0];
	to->m01 = (int) from->matrix[1];
	to->m02 = (int) from->matrix[2];
	to->m10 = (int) from->matrix[3];
	to->m11 = (int) from->matrix[4];
	to->m12 = (int) from->matrix[5];
	to->m20 = (int) from->matrix[6];
	to->m21 = (int) from->matrix[7];
	to->m22 = (int) from->matrix[8];

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_encode_cc() leave:\n");
}

void
ia_css_csc_encode(struct sh_css_isp_csc_params *to,
		  const struct ia_css_cc_config *from)
{
	ia_css_encode_cc(to, from);
}

void
ia_css_cc_dump(const struct sh_css_isp_csc_params *csc, unsigned level,
	       const char *name)
{
	ia_css_debug_dtrace(level, "%s\n", name);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m_shift",
		csc->m_shift);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m00",
		csc->m00);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m01",
		csc->m01);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m02",
		csc->m02);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m10",
		csc->m10);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m11",
		csc->m11);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m12",
		csc->m12);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m20",
		csc->m20);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m21",
		csc->m21);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
		"m22",
		csc->m22);
}

void
ia_css_csc_dump(const struct sh_css_isp_csc_params *csc, unsigned level)
{
	ia_css_cc_dump(csc, level, "Color Space Conversion");
}
