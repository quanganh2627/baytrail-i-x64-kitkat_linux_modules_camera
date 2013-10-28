/* Release Version: ci_master_20131024_0113 */
/*
* Support for Medfield PNW Camera Imaging ISP subsystem.
*
* Copyright (c) 2010 Intel Corporation. All Rights Reserved.
*
* Copyright (c) 2010 Silicon Hive www.siliconhive.com.
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

#ifndef __IA_CSS_ISYS_H__
#define __IA_CSS_ISYS_H__

#include "input_system.h"
#include "ia_css.h"

#ifdef USE_INPUT_SYSTEM_VERSION_2401
/**
 * Virtual Input System. (Input System 2401)
 */
typedef input_system_cfg_t ia_css_isys_cfg_t;
typedef virtual_input_system_t		ia_css_virtual_isys_t;
typedef virtual_input_system_cfg_t	ia_css_virtual_isys_cfg_t;
/** end of Virtual Input System */
#endif

#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
input_system_error_t ia_css_isys_init(void);
#endif

#if !defined(USE_INPUT_SYSTEM_VERSION_2401)
/* CSS Receiver */
void ia_css_isys_rx_configure(const rx_cfg_t *config,
		const enum ia_css_input_mode input_mode);

void ia_css_isys_rx_disable(void);

void ia_css_isys_rx_enable_all_interrupts(void);

unsigned int ia_css_isys_rx_get_interrupt_reg(void);
#endif /* #if !defined(USE_INPUT_SYSTEM_VERSION_2401) */

/** @brief Translate format and compression to format type.
 *
 * @param[in]	input_format	The input format.
 * @param[in]	compression	The compression scheme.
 * @param[out]	fmt_type	Pointer to the resulting format type.
 * @return			Error code.
 *
 * Translate an input format and mipi compression pair to the fmt_type.
 * This is normally done by the sensor, but when using the input fifo, this
 * format type must be sumitted correctly by the application.
 */
enum ia_css_err ia_css_isys_convert_stream_format_to_mipi_format(
		enum ia_css_stream_format input_format,
		mipi_predictor_t compression,
		unsigned int *fmt_type);

#ifdef USE_INPUT_SYSTEM_VERSION_2401
/**
 * Virtual Input System. (Input System 2401)
 */
extern bool ia_css_virtual_isys_create(
		ia_css_isys_cfg_t		*cfg,
		ia_css_virtual_isys_t	*me);

extern void ia_css_virtual_isys_destroy(
		ia_css_virtual_isys_t	*me);

extern bool ia_css_virtual_isys_calculate_cfg(
		ia_css_virtual_isys_t		*me,
		ia_css_isys_cfg_t			*isys_cfg,
		ia_css_virtual_isys_cfg_t	*virtual_isys_cfg);
/** end of Virtual Input System */
#endif

#endif				/* __IA_CSS_ISYS_H__ */
