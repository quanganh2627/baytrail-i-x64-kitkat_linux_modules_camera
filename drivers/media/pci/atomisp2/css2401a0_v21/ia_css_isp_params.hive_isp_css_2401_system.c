/* Release Version: ci_master_20131024_0113 */
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

#define IA_CSS_INCLUDE_PARAMETERS
#include "sh_css_params.h"
#include "isp/kernels/aa/aa_2/ia_css_aa2.host.h"
#include "isp/kernels/anr/anr_1.0/ia_css_anr.host.h"
#include "isp/kernels/bh/bh_2/ia_css_bh.host.h"
#include "isp/kernels/bnr/bnr_1.0/ia_css_bnr.host.h"
#include "isp/kernels/cnr/cnr_2/ia_css_cnr2.host.h"
#include "isp/kernels/csc/csc_1.0/ia_css_csc.host.h"
#include "isp/kernels/ctc/ctc_1.0/ia_css_ctc.host.h"
#include "isp/kernels/ctc/ctc_2/ia_css_ctc2.host.h"
#include "isp/kernels/de/de_1.0/ia_css_de.host.h"
#include "isp/kernels/de/de_2/ia_css_de2.host.h"
#include "isp/kernels/dp/dp_1.0/ia_css_dp.host.h"
#include "isp/kernels/fpn/fpn_1.0/ia_css_fpn.host.h"
#include "isp/kernels/gc/gc_1.0/ia_css_gc.host.h"
#include "isp/kernels/gc/gc_2/ia_css_gc2.host.h"
#include "isp/kernels/macc/macc_1.0/ia_css_macc.host.h"
#include "isp/kernels/ob/ob_1.0/ia_css_ob.host.h"
#include "isp/kernels/raw/raw_1.0/ia_css_raw.host.h"
#include "isp/kernels/raw_aa_binning/raw_aa_binning_1.0/ia_css_raa.host.h"
#include "isp/kernels/s3a/s3a_1.0/ia_css_s3a.host.h"
#include "isp/kernels/sc/sc_1.0/ia_css_sc.host.h"
#include "isp/kernels/tnr/tnr_1.0/ia_css_tnr.host.h"
#include "isp/kernels/uds/uds_1.0/ia_css_uds.host.h"
#include "isp/kernels/wb/wb_1.0/ia_css_wb.host.h"
#include "isp/kernels/xnr/xnr_1.0/ia_css_xnr.host.h"
#include "isp/kernels/ynr/ynr_1.0/ia_css_ynr.host.h"
#include "isp/kernels/ynr/ynr_2/ia_css_ynr2.host.h"
/* Generated code: do not edit or commmit. */

#include HRTSTR(ia_css_isp_params.SYSTEM.h)
#include "ia_css_debug.h"

static void
ia_css_process_bh(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_bh() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.bh;

		if (offset >= 0) {
			ia_css_bh_encode((struct sh_css_isp_bh_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->s3a_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	{
		short offset = stage->binary->info->mem_offsets->hmem0.bh;

		if (offset >= 0) {
			ia_css_bh_hmem_encode((struct sh_css_isp_bh_hmem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_HMEM0].address[offset],
					&params->s3a_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_HMEM0] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_bh() leave:\n");
}

static void
ia_css_process_dp(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_dp() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.dp;

		if (offset >= 0) {
			ia_css_dp_encode((struct sh_css_isp_dp_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->dp_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_dp() leave:\n");
}

static void
ia_css_process_aa(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_aa() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.aa;

		if (offset >= 0) {
			ia_css_aa_encode((struct sh_css_isp_aa_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->aa_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_aa() leave:\n");
}

static void
ia_css_process_anr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_anr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.anr;

		if (offset >= 0) {
			ia_css_anr_encode((struct sh_css_isp_anr_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->anr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_anr() leave:\n");
}

static void
ia_css_process_nr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_nr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.nr;

		if (offset >= 0) {
			ia_css_nr_encode((struct sh_css_isp_ynr_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->nr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_nr() leave:\n");
}

static void
ia_css_process_raa(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_raa() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.raa;

		if (offset >= 0) {
			ia_css_raa_encode((struct sh_css_isp_aa_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->raa_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_raa() leave:\n");
}

static void
ia_css_process_wb(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_wb() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.wb;

		if (offset >= 0) {
			ia_css_wb_encode((struct sh_css_isp_wb_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->wb_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_wb() leave:\n");
}

static void
ia_css_process_yee(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_yee() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.yee;

		if (offset >= 0) {
			ia_css_yee_encode((struct sh_css_isp_yee_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->yee_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_yee() leave:\n");
}

static void
ia_css_process_ob(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ob() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.ob;

		if (offset >= 0) {
			ia_css_ob_encode((struct sh_css_isp_ob_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->ob_config, &params->stream_configs.ob);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	{
		short offset = stage->binary->info->mem_offsets->vmem.ob;

		if (offset >= 0) {
			ia_css_ob_vmem_encode((struct sh_css_isp_ob_vmem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VMEM].address[offset],
					&params->ob_config, &params->stream_configs.ob);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ob() leave:\n");
}

static void
ia_css_process_bnr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_bnr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.bnr;

		if (offset >= 0) {
			ia_css_bnr_encode((struct sh_css_isp_bnr_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->nr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_bnr() leave:\n");
}

static void
ia_css_process_s3a(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_s3a() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.s3a;

		if (offset >= 0) {
			ia_css_s3a_encode((struct sh_css_isp_s3a_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->s3a_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_s3a() leave:\n");
}

static void
ia_css_process_csc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_csc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.csc;

		if (offset >= 0) {
			ia_css_csc_encode((struct sh_css_isp_csc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->csc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_csc() leave:\n");
}

static void
ia_css_process_rgb2yuv(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_rgb2yuv() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.rgb2yuv;

		if (offset >= 0) {
			ia_css_rgb2yuv_encode((struct sh_css_isp_csc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->rgb2yuv_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_rgb2yuv() leave:\n");
}

static void
ia_css_process_yuv2rgb(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_yuv2rgb() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.yuv2rgb;

		if (offset >= 0) {
			ia_css_yuv2rgb_encode((struct sh_css_isp_csc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->yuv2rgb_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_yuv2rgb() leave:\n");
}

static void
ia_css_process_ce(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ce() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.ce;

		if (offset >= 0) {
			ia_css_ce_encode((struct sh_css_isp_ce_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->ce_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ce() leave:\n");
}

static void
ia_css_process_gc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_gc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.gc;

		if (offset >= 0) {
			ia_css_gc_encode((struct sh_css_isp_gc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->gc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	{
		short offset = stage->binary->info->mem_offsets->vamem1.gc;

		if (offset >= 0) {
			ia_css_gc_vamem_encode((struct sh_css_isp_gc_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM1].address[offset],
					&params->gc_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM1] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_gc() leave:\n");
}

static void
ia_css_process_fc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_fc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.fc;

		if (offset >= 0) {
			ia_css_fc_encode((struct sh_css_isp_fc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->fc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_fc() leave:\n");
}

static void
ia_css_process_de(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_de() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.de;

		if (offset >= 0) {
			ia_css_de_encode((struct sh_css_isp_de_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->de_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_de() leave:\n");
}

static void
ia_css_process_cnr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_cnr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.cnr;

		if (offset >= 0) {
			ia_css_cnr_encode((struct sh_css_isp_cnr_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->cnr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_cnr() leave:\n");
}

static void
ia_css_process_ctc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ctc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.ctc;

		if (offset >= 0) {
			ia_css_ctc_encode((struct sh_css_isp_ctc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->ctc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	{
		short offset = stage->binary->info->mem_offsets->vamem0.ctc;

		if (offset >= 0) {
			ia_css_ctc_vamem_encode((struct sh_css_isp_ctc_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM0].address[offset],
					&params->ctc_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM0] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ctc() leave:\n");
}

static void
ia_css_process_ecd(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ecd() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.ecd;

		if (offset >= 0) {
			ia_css_ecd_encode((struct sh_css_isp_ecd_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->ecd_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ecd() leave:\n");
}

static void
ia_css_process_fpn(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_fpn() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.fpn;

		if (offset >= 0) {
			ia_css_fpn_encode((struct sh_css_isp_fpn_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->fpn_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_fpn() leave:\n");
}

static void
ia_css_process_macc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_macc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.macc;

		if (offset >= 0) {
			ia_css_macc_encode((struct sh_css_isp_macc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->macc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_macc() leave:\n");
}

static void
ia_css_process_raw(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_raw() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.raw;

		if (offset >= 0) {
			ia_css_raw_encode((struct sh_css_isp_raw_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->raw_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_raw() leave:\n");
}

static void
ia_css_process_sc(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_sc() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.sc;

		if (offset >= 0) {
			ia_css_sc_encode((struct sh_css_isp_sc_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->sc_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_sc() leave:\n");
}

static void
ia_css_process_tnr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_tnr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.tnr;

		if (offset >= 0) {
			ia_css_tnr_encode((struct sh_css_isp_tnr_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->tnr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_tnr() leave:\n");
}

static void
ia_css_process_ynr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ynr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->dmem.ynr;

		if (offset >= 0) {
			ia_css_ynr_encode((struct sh_css_isp_yee2_params *)
					&stage->isp_mem_params[IA_CSS_ISP_DMEM].address[offset],
					&params->ynr_config);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_ynr() leave:\n");
}

static void
ia_css_process_r_gamma(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_r_gamma() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->vamem0.r_gamma;

		if (offset >= 0) {
			ia_css_r_gamma_vamem_encode((struct sh_css_isp_rgb_gamma_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM0].address[offset],
					&params->r_gamma_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM0] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_r_gamma() leave:\n");
}

static void
ia_css_process_g_gamma(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_g_gamma() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->vamem1.g_gamma;

		if (offset >= 0) {
			ia_css_g_gamma_vamem_encode((struct sh_css_isp_rgb_gamma_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM1].address[offset],
					&params->g_gamma_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM1] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_g_gamma() leave:\n");
}

static void
ia_css_process_xnr(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_xnr() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->vamem1.xnr;

		if (offset >= 0) {
			ia_css_xnr_vamem_encode((struct sh_css_isp_xnr_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM1].address[offset],
					&params->xnr_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM1] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_xnr() leave:\n");
}

static void
ia_css_process_b_gamma(unsigned pipe_id,
		const struct ia_css_pipeline_stage *stage,
		struct ia_css_isp_parameters *params)
{
	assert(params != NULL);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_b_gamma() enter:\n");

	{
		short offset = stage->binary->info->mem_offsets->vamem2.b_gamma;

		if (offset >= 0) {
			ia_css_b_gamma_vamem_encode((struct sh_css_isp_rgb_gamma_vamem_params *)
					&stage->isp_mem_params[IA_CSS_ISP_VAMEM2].address[offset],
					&params->b_gamma_table);
			params->isp_params_changed = true;
			params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_VAMEM2] = true;
		}

	}
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_process_b_gamma() leave:\n");
}

void (* ia_css_kernel_process[IA_CSS_NUM_PARAMETER_IDS])(unsigned pipe_id,
                            const struct ia_css_pipeline_stage *stage,
                            struct ia_css_isp_parameters *params) = {
	ia_css_process_bh,
	ia_css_process_dp,
	ia_css_process_aa,
	ia_css_process_anr,
	ia_css_process_nr,
	ia_css_process_raa,
	ia_css_process_wb,
	ia_css_process_yee,
	ia_css_process_ob,
	ia_css_process_bnr,
	ia_css_process_s3a,
	ia_css_process_csc,
	ia_css_process_rgb2yuv,
	ia_css_process_yuv2rgb,
	ia_css_process_ce,
	ia_css_process_gc,
	ia_css_process_fc,
	ia_css_process_de,
	ia_css_process_cnr,
	ia_css_process_ctc,
	ia_css_process_ecd,
	ia_css_process_fpn,
	ia_css_process_macc,
	ia_css_process_raw,
	ia_css_process_sc,
	ia_css_process_tnr,
	ia_css_process_ynr,
	ia_css_process_r_gamma,
	ia_css_process_g_gamma,
	ia_css_process_xnr,
	ia_css_process_b_gamma,
};

static void
ia_css_get_dp_config(const struct ia_css_isp_parameters *params,
			struct ia_css_dp_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_dp_config() enter: "
		"config=%p\n",config);

	*config = params->dp_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_dp_config() leave\n");
	ia_css_dp_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_dp_config(struct ia_css_isp_parameters *params,
			const struct ia_css_dp_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_dp_config() enter:\n");
	ia_css_dp_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->dp_config = *config;
	params->config_changed[IA_CSS_DP_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_dp_config() leave: "
		"return_void\n");
}

static void
ia_css_get_wb_config(const struct ia_css_isp_parameters *params,
			struct ia_css_wb_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_wb_config() enter: "
		"config=%p\n",config);

	*config = params->wb_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_wb_config() leave\n");
	ia_css_wb_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_wb_config(struct ia_css_isp_parameters *params,
			const struct ia_css_wb_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_wb_config() enter:\n");
	ia_css_wb_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->wb_config = *config;
	params->config_changed[IA_CSS_WB_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_wb_config() leave: "
		"return_void\n");
}

static void
ia_css_get_tnr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_tnr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_tnr_config() enter: "
		"config=%p\n",config);

	*config = params->tnr_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_tnr_config() leave\n");
	ia_css_tnr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_tnr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_tnr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_tnr_config() enter:\n");
	ia_css_tnr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->tnr_config = *config;
	params->config_changed[IA_CSS_TNR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_tnr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_ob_config(const struct ia_css_isp_parameters *params,
			struct ia_css_ob_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ob_config() enter: "
		"config=%p\n",config);

	*config = params->ob_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ob_config() leave\n");
	ia_css_ob_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_ob_config(struct ia_css_isp_parameters *params,
			const struct ia_css_ob_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_ob_config() enter:\n");
	ia_css_ob_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->ob_config = *config;
	params->config_changed[IA_CSS_OB_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_ob_config() leave: "
		"return_void\n");
}

static void
ia_css_get_de_config(const struct ia_css_isp_parameters *params,
			struct ia_css_de_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_de_config() enter: "
		"config=%p\n",config);

	*config = params->de_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_de_config() leave\n");
	ia_css_de_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_de_config(struct ia_css_isp_parameters *params,
			const struct ia_css_de_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_de_config() enter:\n");
	ia_css_de_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->de_config = *config;
	params->config_changed[IA_CSS_DE_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_de_config() leave: "
		"return_void\n");
}

static void
ia_css_get_anr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_anr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_anr_config() enter: "
		"config=%p\n",config);

	*config = params->anr_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_anr_config() leave\n");
	ia_css_anr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_anr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_anr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_anr_config() enter:\n");
	ia_css_anr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->anr_config = *config;
	params->config_changed[IA_CSS_ANR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_anr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_ce_config(const struct ia_css_isp_parameters *params,
			struct ia_css_ce_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ce_config() enter: "
		"config=%p\n",config);

	*config = params->ce_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ce_config() leave\n");
	ia_css_ce_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_ce_config(struct ia_css_isp_parameters *params,
			const struct ia_css_ce_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_ce_config() enter:\n");
	ia_css_ce_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->ce_config = *config;
	params->config_changed[IA_CSS_CE_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_ce_config() leave: "
		"return_void\n");
}

static void
ia_css_get_ecd_config(const struct ia_css_isp_parameters *params,
			struct ia_css_ecd_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ecd_config() enter: "
		"config=%p\n",config);

	*config = params->ecd_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ecd_config() leave\n");
	ia_css_ecd_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_ecd_config(struct ia_css_isp_parameters *params,
			const struct ia_css_ecd_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_ecd_config() enter:\n");
	ia_css_ecd_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->ecd_config = *config;
	params->config_changed[IA_CSS_ECD_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_ecd_config() leave: "
		"return_void\n");
}

static void
ia_css_get_ynr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_ynr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ynr_config() enter: "
		"config=%p\n",config);

	*config = params->ynr_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ynr_config() leave\n");
	ia_css_ynr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_ynr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_ynr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_ynr_config() enter:\n");
	ia_css_ynr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->ynr_config = *config;
	params->config_changed[IA_CSS_YNR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_ynr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_fc_config(const struct ia_css_isp_parameters *params,
			struct ia_css_fc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_fc_config() enter: "
		"config=%p\n",config);

	*config = params->fc_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_fc_config() leave\n");
	ia_css_fc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_fc_config(struct ia_css_isp_parameters *params,
			const struct ia_css_fc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_fc_config() enter:\n");
	ia_css_fc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->fc_config = *config;
	params->config_changed[IA_CSS_FC_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_fc_config() leave: "
		"return_void\n");
}

static void
ia_css_get_cnr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_cnr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_cnr_config() enter: "
		"config=%p\n",config);

	*config = params->cnr_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_cnr_config() leave\n");
	ia_css_cnr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_cnr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_cnr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_cnr_config() enter:\n");
	ia_css_cnr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->cnr_config = *config;
	params->config_changed[IA_CSS_CNR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_cnr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_macc_config(const struct ia_css_isp_parameters *params,
			struct ia_css_macc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_macc_config() enter: "
		"config=%p\n",config);

	*config = params->macc_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_macc_config() leave\n");
	ia_css_macc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_macc_config(struct ia_css_isp_parameters *params,
			const struct ia_css_macc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_macc_config() enter:\n");
	ia_css_macc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->macc_config = *config;
	params->config_changed[IA_CSS_MACC_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_macc_config() leave: "
		"return_void\n");
}

static void
ia_css_get_ctc_config(const struct ia_css_isp_parameters *params,
			struct ia_css_ctc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ctc_config() enter: "
		"config=%p\n",config);

	*config = params->ctc_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_ctc_config() leave\n");
	ia_css_ctc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_ctc_config(struct ia_css_isp_parameters *params,
			const struct ia_css_ctc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_ctc_config() enter:\n");
	ia_css_ctc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->ctc_config = *config;
	params->config_changed[IA_CSS_CTC_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_ctc_config() leave: "
		"return_void\n");
}

static void
ia_css_get_aa_config(const struct ia_css_isp_parameters *params,
			struct ia_css_aa_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_aa_config() enter: "
		"config=%p\n",config);

	*config = params->aa_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_aa_config() leave\n");
	ia_css_aa_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_aa_config(struct ia_css_isp_parameters *params,
			const struct ia_css_aa_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_aa_config() enter:\n");
	ia_css_aa_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->aa_config = *config;
	params->config_changed[IA_CSS_AA_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_aa_config() leave: "
		"return_void\n");
}

static void
ia_css_get_yuv2rgb_config(const struct ia_css_isp_parameters *params,
			struct ia_css_cc_config *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_yuv2rgb_config() enter: "
		"config=%p\n",config);

	*config = params->yuv2rgb_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_yuv2rgb_config() leave\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_yuv2rgb_config(struct ia_css_isp_parameters *params,
			const struct ia_css_cc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_yuv2rgb_config() enter:\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->yuv2rgb_config = *config;
	params->config_changed[IA_CSS_YUV2RGB_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_yuv2rgb_config() leave: "
		"return_void\n");
}

static void
ia_css_get_rgb2yuv_config(const struct ia_css_isp_parameters *params,
			struct ia_css_cc_config *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_rgb2yuv_config() enter: "
		"config=%p\n",config);

	*config = params->rgb2yuv_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_rgb2yuv_config() leave\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_rgb2yuv_config(struct ia_css_isp_parameters *params,
			const struct ia_css_cc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_rgb2yuv_config() enter:\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->rgb2yuv_config = *config;
	params->config_changed[IA_CSS_RGB2YUV_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_rgb2yuv_config() leave: "
		"return_void\n");
}

static void
ia_css_get_csc_config(const struct ia_css_isp_parameters *params,
			struct ia_css_cc_config *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_csc_config() enter: "
		"config=%p\n",config);

	*config = params->csc_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_csc_config() leave\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_csc_config(struct ia_css_isp_parameters *params,
			const struct ia_css_cc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_csc_config() enter:\n");
	ia_css_cc_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->csc_config = *config;
	params->config_changed[IA_CSS_CSC_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_csc_config() leave: "
		"return_void\n");
}

static void
ia_css_get_nr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_nr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_nr_config() enter: "
		"config=%p\n",config);

	*config = params->nr_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_nr_config() leave\n");
	ia_css_nr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_nr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_nr_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_nr_config() enter:\n");
	ia_css_nr_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->nr_config = *config;
	params->config_changed[IA_CSS_BNR_ID] = true;
	params->config_changed[IA_CSS_NR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_nr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_gc_config(const struct ia_css_isp_parameters *params,
			struct ia_css_gc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_gc_config() enter: "
		"config=%p\n",config);

	*config = params->gc_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_gc_config() leave\n");
	ia_css_gc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_gc_config(struct ia_css_isp_parameters *params,
			const struct ia_css_gc_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_gc_config() enter:\n");
	ia_css_gc_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->gc_config = *config;
	params->config_changed[IA_CSS_GC_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_gc_config() leave: "
		"return_void\n");
}

static void
ia_css_get_r_gamma_config(const struct ia_css_isp_parameters *params,
			struct ia_css_rgb_gamma_table *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_r_gamma_config() enter: "
		"config=%p\n",config);

	*config = params->r_gamma_table;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_r_gamma_config() leave\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_r_gamma_config(struct ia_css_isp_parameters *params,
			const struct ia_css_rgb_gamma_table *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_r_gamma_config() enter:\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->r_gamma_table = *config;
	params->config_changed[IA_CSS_R_GAMMA_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_r_gamma_config() leave: "
		"return_void\n");
}

static void
ia_css_get_g_gamma_config(const struct ia_css_isp_parameters *params,
			struct ia_css_rgb_gamma_table *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_g_gamma_config() enter: "
		"config=%p\n",config);

	*config = params->g_gamma_table;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_g_gamma_config() leave\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_g_gamma_config(struct ia_css_isp_parameters *params,
			const struct ia_css_rgb_gamma_table *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_g_gamma_config() enter:\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->g_gamma_table = *config;
	params->config_changed[IA_CSS_G_GAMMA_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_g_gamma_config() leave: "
		"return_void\n");
}

static void
ia_css_get_b_gamma_config(const struct ia_css_isp_parameters *params,
			struct ia_css_rgb_gamma_table *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_b_gamma_config() enter: "
		"config=%p\n",config);

	*config = params->b_gamma_table;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_b_gamma_config() leave\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_b_gamma_config(struct ia_css_isp_parameters *params,
			const struct ia_css_rgb_gamma_table *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_b_gamma_config() enter:\n");
	ia_css_rgb_gamma_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->b_gamma_table = *config;
	params->config_changed[IA_CSS_B_GAMMA_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_b_gamma_config() leave: "
		"return_void\n");
}

static void
ia_css_get_xnr_config(const struct ia_css_isp_parameters *params,
			struct ia_css_xnr_table *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_xnr_config() enter: "
		"config=%p\n",config);

	*config = params->xnr_table;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_xnr_config() leave\n");
	ia_css_xnr_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_xnr_config(struct ia_css_isp_parameters *params,
			const struct ia_css_xnr_table *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_xnr_config() enter:\n");
	ia_css_xnr_table_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->xnr_table = *config;
	params->config_changed[IA_CSS_XNR_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_xnr_config() leave: "
		"return_void\n");
}

static void
ia_css_get_s3a_config(const struct ia_css_isp_parameters *params,
			struct ia_css_3a_config *config){
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_s3a_config() enter: "
		"config=%p\n",config);

	*config = params->s3a_config;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_get_s3a_config() leave\n");
	ia_css_3a_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
}

void
ia_css_set_s3a_config(struct ia_css_isp_parameters *params,
			const struct ia_css_3a_config *config)
{
	if (config == NULL)
		return;

	assert(params != NULL);
	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_set_s3a_config() enter:\n");
	ia_css_3a_config_debug_dtrace(config, IA_CSS_DEBUG_TRACE);
	params->s3a_config = *config;
	params->config_changed[IA_CSS_BH_ID] = true;
	params->config_changed[IA_CSS_S3A_ID] = true;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_set_s3a_config() leave: "
		"return_void\n");
}

void
ia_css_get_configs(struct ia_css_isp_parameters *params,
		const struct ia_css_isp_config *config)
{
	ia_css_get_dp_config(params, config->dp_config);
	ia_css_get_wb_config(params, config->wb_config);
	ia_css_get_tnr_config(params, config->tnr_config);
	ia_css_get_ob_config(params, config->ob_config);
	ia_css_get_de_config(params, config->de_config);
	ia_css_get_anr_config(params, config->anr_config);
	ia_css_get_ce_config(params, config->ce_config);
	ia_css_get_ecd_config(params, config->ecd_config);
	ia_css_get_ynr_config(params, config->ynr_config);
	ia_css_get_fc_config(params, config->fc_config);
	ia_css_get_cnr_config(params, config->cnr_config);
	ia_css_get_macc_config(params, config->macc_config);
	ia_css_get_ctc_config(params, config->ctc_config);
	ia_css_get_aa_config(params, config->aa_config);
	ia_css_get_yuv2rgb_config(params, config->yuv2rgb_cc_config);
	ia_css_get_rgb2yuv_config(params, config->rgb2yuv_cc_config);
	ia_css_get_csc_config(params, config->cc_config);
	ia_css_get_nr_config(params, config->nr_config);
	ia_css_get_gc_config(params, config->gc_config);
	ia_css_get_r_gamma_config(params, config->r_gamma_table);
	ia_css_get_g_gamma_config(params, config->g_gamma_table);
	ia_css_get_b_gamma_config(params, config->b_gamma_table);
	ia_css_get_xnr_config(params, config->xnr_table);
	ia_css_get_s3a_config(params, config->s3a_config);
}

void
ia_css_set_configs(struct ia_css_isp_parameters *params,
		const struct ia_css_isp_config *config)
{
	ia_css_set_dp_config(params, config->dp_config);
	ia_css_set_wb_config(params, config->wb_config);
	ia_css_set_tnr_config(params, config->tnr_config);
	ia_css_set_ob_config(params, config->ob_config);
	ia_css_set_de_config(params, config->de_config);
	ia_css_set_anr_config(params, config->anr_config);
	ia_css_set_ce_config(params, config->ce_config);
	ia_css_set_ecd_config(params, config->ecd_config);
	ia_css_set_ynr_config(params, config->ynr_config);
	ia_css_set_fc_config(params, config->fc_config);
	ia_css_set_cnr_config(params, config->cnr_config);
	ia_css_set_macc_config(params, config->macc_config);
	ia_css_set_ctc_config(params, config->ctc_config);
	ia_css_set_aa_config(params, config->aa_config);
	ia_css_set_yuv2rgb_config(params, config->yuv2rgb_cc_config);
	ia_css_set_rgb2yuv_config(params, config->rgb2yuv_cc_config);
	ia_css_set_csc_config(params, config->cc_config);
	ia_css_set_nr_config(params, config->nr_config);
	ia_css_set_gc_config(params, config->gc_config);
	ia_css_set_r_gamma_config(params, config->r_gamma_table);
	ia_css_set_g_gamma_config(params, config->g_gamma_table);
	ia_css_set_b_gamma_config(params, config->b_gamma_table);
	ia_css_set_xnr_config(params, config->xnr_table);
	ia_css_set_s3a_config(params, config->s3a_config);
}

