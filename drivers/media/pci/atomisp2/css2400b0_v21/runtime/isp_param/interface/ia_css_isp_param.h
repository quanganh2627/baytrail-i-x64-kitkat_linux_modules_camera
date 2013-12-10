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

#ifndef _IA_CSS_ISP_PARAM_H_
#define _IA_CSS_ISP_PARAM_H_

#include "ia_css_acc_types.h"

void
ia_css_isp_param_set_css_mem_init(
	struct ia_css_data *mem_init,
	enum ia_css_param_class pclass,
	enum ia_css_isp_memories mem,
	hrt_vaddress address, size_t size);

const struct ia_css_data*
ia_css_isp_param_get_mem_init(
	const struct ia_css_data *mem_init,
	enum ia_css_param_class pclass,
	enum ia_css_isp_memories mem);

const struct ia_css_isp_data*
ia_css_isp_param_get_isp_mem_init(
	const struct ia_css_isp_data *mem_init,
	enum ia_css_param_class pclass,
	enum ia_css_isp_memories mem);

#endif
