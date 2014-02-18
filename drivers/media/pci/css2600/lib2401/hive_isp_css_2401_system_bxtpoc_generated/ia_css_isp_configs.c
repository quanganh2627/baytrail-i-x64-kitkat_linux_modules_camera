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

/* Generated code: do not edit or commmit. */

#include "ia_css.h"
#define IA_CSS_INCLUDE_CONFIGURATIONS
#include "ia_css_pipeline.h"
#include "ia_css_isp_configs.h"
#include "ia_css_debug.h"
#include "assert_support.h"

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_crop(
	const struct ia_css_binary *binary,
	const struct ia_css_crop_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_crop() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.crop;

		if (offset >= 0) {
			ia_css_crop_config((struct sh_css_isp_crop_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_crop() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_fpn(
	const struct ia_css_binary *binary,
	const struct ia_css_fpn_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_fpn() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.fpn;

		if (offset >= 0) {
			ia_css_fpn_config((struct sh_css_isp_fpn_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_fpn() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_dvs(
	const struct ia_css_binary *binary,
	const struct ia_css_dvs_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_dvs() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.dvs;

		if (offset >= 0) {
			ia_css_dvs_config((struct sh_css_isp_dvs_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_dvs() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_qplane(
	const struct ia_css_binary *binary,
	const struct ia_css_qplane_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_qplane() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.qplane;

		if (offset >= 0) {
			ia_css_qplane_config((struct sh_css_isp_qplane_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_qplane() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_output(
	const struct ia_css_binary *binary,
	const struct ia_css_output_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.output;

		if (offset >= 0) {
			ia_css_output_config((struct sh_css_isp_output_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_raw(
	const struct ia_css_binary *binary,
	const struct ia_css_raw_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_raw() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.raw;

		if (offset >= 0) {
			ia_css_raw_config((struct sh_css_isp_raw_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_raw() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_tnr(
	const struct ia_css_binary *binary,
	const struct ia_css_tnr_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_tnr() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.tnr;

		if (offset >= 0) {
			ia_css_tnr_config((struct sh_css_isp_tnr_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_tnr() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_ref(
	const struct ia_css_binary *binary,
	const struct ia_css_ref_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_ref() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.ref;

		if (offset >= 0) {
			ia_css_ref_config((struct sh_css_isp_ref_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_ref() leave:\n");
}

/* Code generated by genparam/genconfig.c:gen_configure_function() */

void
ia_css_configure_vf(
	const struct ia_css_binary *binary,
	const struct ia_css_vf_configuration *config_dmem)
{
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_vf() enter:\n");

	{
		short offset = -1;
		if (binary->info->mem_offsets.offsets.config)
			offset = binary->info->mem_offsets.offsets.config->dmem.vf;

		if (offset >= 0) {
			ia_css_vf_config((struct sh_css_isp_vf_isp_config *)
					&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
					config_dmem);		}
	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_vf() leave:\n");
}

