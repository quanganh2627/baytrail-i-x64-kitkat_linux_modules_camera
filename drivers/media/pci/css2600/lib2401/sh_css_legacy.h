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

#ifndef _SH_CSS_LEGACY_H_
#define _SH_CSS_LEGACY_H_

#include "ia_css.h"

/** The pipe id type, distinguishes the kind of pipes that
 *  can be run in parallel.
 */
enum ia_css_pipe_id {
	IA_CSS_PIPE_ID_PREVIEW,
	IA_CSS_PIPE_ID_COPY,
	IA_CSS_PIPE_ID_VIDEO,
	IA_CSS_PIPE_ID_CAPTURE,
	IA_CSS_PIPE_ID_ACC,
};
#define IA_CSS_PIPE_ID_NUM (IA_CSS_PIPE_ID_ACC + 1)

struct ia_css_pipe_extra_config {
	bool enable_raw_binning;
	bool enable_yuv_ds;
	bool enable_high_speed;
	bool enable_dvs_6axis;
	bool enable_reduced_pipe;
	bool enable_fractional_ds;
	bool disable_vf_pp;
};

enum ia_css_err
ia_css_pipe_create_extra(const struct ia_css_pipe_config *config,
			 const struct ia_css_pipe_extra_config *extra_config,
			 struct ia_css_pipe **pipe);

void
ia_css_pipe_extra_config_defaults(struct ia_css_pipe_extra_config *extra_config);

enum ia_css_err
ia_css_temp_pipe_to_pipe_id(const struct ia_css_pipe *pipe,
			    enum ia_css_pipe_id *pipe_id);

/** @brief Enable cont_capt mode (continuous preview+capture running together).
 *
 * @param	enable	Enabling value.
 *
 * Enable or disable continuous binaries if available. Default is disabled.
 */
void
sh_css_enable_cont_capt(bool enable, bool stop_copy_preview);

/* DEPRECATED. FPN is not supported. */
enum ia_css_err
sh_css_set_black_frame(struct ia_css_stream *stream,
			const struct ia_css_frame *raw_black_frame);

#endif /* _SH_CSS_LEGACY_H_ */
