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
#include "sh_css_frac.h"
#include "vamem.h"

#include "ia_css_gc.host.h"

void
ia_css_gc_encode(struct sh_css_isp_gc_params *to,
	 const struct ia_css_gc_config *from)
{
	to->gain_k1 =
	    uDIGIT_FITTING((int)from->gain_k1, 16,
		IA_CSS_GAMMA_GAIN_K_SHIFT);
	to->gain_k2 =
	    uDIGIT_FITTING((int)from->gain_k2, 16,
		IA_CSS_GAMMA_GAIN_K_SHIFT);
}

void
ia_css_ce_encode(struct sh_css_isp_ce_params *to,
	 const struct ia_css_ce_config *from)
{
	to->uv_level_min = from->uv_level_min;
	to->uv_level_max = from->uv_level_max;
}

void
ia_css_gc_vamem_encode(struct sh_css_isp_gc_vamem_params *to,
		  const struct ia_css_gamma_table *from)
{
	memcpy (&to->gc,  &from->data, sizeof(to->gc));
}

void
ia_css_gc_dump(const struct sh_css_isp_gc_params *gc, unsigned level)
{
	ia_css_debug_dtrace(level, "Gamma Correction:\n");
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"gamma_gain_k1", gc->gain_k1);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"gamma_gain_k2", gc->gain_k2);
}

void
ia_css_ce_dump(const struct sh_css_isp_ce_params *ce, unsigned level)
{
	ia_css_debug_dtrace(level, "Chroma Enhancement:\n");
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"ce_uv_level_min", ce->uv_level_min);
	ia_css_debug_dtrace(level, "\t%-32s = %d\n",
			"ce_uv_level_max", ce->uv_level_max);
}
