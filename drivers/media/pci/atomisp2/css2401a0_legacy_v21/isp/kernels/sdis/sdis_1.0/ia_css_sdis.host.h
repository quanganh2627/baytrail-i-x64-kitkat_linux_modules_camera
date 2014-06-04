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

#ifndef __IA_CSS_SDIS_HOST_H
#define __IA_CSS_SDIS_HOST_H

#include "ia_css_sdis_types.h"
#include "ia_css_binary.h"
#include "ia_css_stream.h"
#include "sh_css_params.h"

extern const struct ia_css_dvs_coefficients default_sdis_config;

/* Opaque here, since size is binary dependent. */
struct sh_css_isp_sdis_dmem_params;
struct sh_css_isp_sdis_vmem_params;

void ia_css_sdis_encode (
	struct sh_css_isp_sdis_dmem_params   *to,
	const struct ia_css_dvs_coefficients *from);

void ia_css_sdis_vmem_encode (
	struct sh_css_isp_sdis_vmem_params   *to,
	const struct ia_css_dvs_coefficients *from);

void ia_css_sdis_store_coefficients(
	const struct ia_css_dvs_coefficients *dvs_coefs,
	const struct ia_css_binary *binary,
	hrt_vaddress ddr_addr_hor,
	hrt_vaddress ddr_addr_ver);

void ia_css_get_isp_dis_coefficients(
	struct ia_css_stream *stream,
	short *horizontal_coefficients,
	short *vertical_coefficients);

size_t ia_css_sdis_hor_coef_tbl_bytes(
	const struct ia_css_binary *binary);

size_t ia_css_sdis_ver_coef_tbl_bytes(
	const struct ia_css_binary *binary);

void
ia_css_sdis_init_info(
	struct ia_css_sdis_info *dis,
	unsigned sc_3a_dis_width,
	unsigned sc_3a_dis_padded_width,
	unsigned sc_3a_dis_height,
	unsigned isp_pipe_version,
	unsigned enabled);

void ia_css_sdis_clear_coefficients(
	struct ia_css_dvs_coefficients *dvs_coefs);

void ia_css_sdis_debug_dtrace(
	const struct ia_css_dvs_coefficients *config, unsigned level);

#endif /* __IA_CSS_SDIS_HOST_H */
