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

#ifndef _IA_CSS_IEFD2_6_STATE_H
#define _IA_CSS_IEFD2_6_STATE_H

#include "type_support.h"
#include "vmem.h" /* for VMEM_ARRAY*/
#include "iefd2_6_vssnlm.isp.h"

struct sh_css_isp_iefd2_6_vmem_state {

	/* State buffers required for VSSNLM sub-kernel */
	VMEM_ARRAY(vssnlm_input_y[VSSNLM_STATE_INPUT_BUFFER_HEIGHT], VSSNLM_STATE_INPUT_BUFFER_WIDTH*ISP_NWAY);
	VMEM_ARRAY(vssnlm_input_diff_grad[1], VSSNLM_STATE_INPUT_BUFFER_WIDTH*ISP_NWAY);
};

#endif /* _IA_CSS_IEFD2_6_STATE_H */

