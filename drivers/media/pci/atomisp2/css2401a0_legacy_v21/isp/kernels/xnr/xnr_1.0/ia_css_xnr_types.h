/* Release Version: ci_master_20131030_2214 */
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

#ifndef __IA_CSS_XNR_TYPES_H
#define __IA_CSS_XNR_TYPES_H

/** XNR table.
 *
 *  NOTE: The driver does not need to set this table,
 *        because the default values are set inside the css.
 *
 *  This table contains coefficients used for division in XNR.
 *
 *  	u0.12, [0,4095],
 *      {4095, 2048, 1365, .........., 65, 64}
 *      ({1/1, 1/2, 1/3, ............., 1/63, 1/64})
 *
 *  ISP block: XNR1
 *  ISP1: XNR1 is used.
 *  ISP2: XNR1 is used.
 *
 */

/** Number of elements in the xnr table. */
#define IA_CSS_VAMEM_1_XNR_TABLE_SIZE_LOG2      6
#define IA_CSS_VAMEM_1_XNR_TABLE_SIZE           (1U<<IA_CSS_VAMEM_1_XNR_TABLE_SIZE_LOG2)

/** Number of elements in the xnr table. */
#define IA_CSS_VAMEM_2_XNR_TABLE_SIZE_LOG2      6
#define IA_CSS_VAMEM_2_XNR_TABLE_SIZE	        (1U<<IA_CSS_VAMEM_2_XNR_TABLE_SIZE_LOG2)

/**< IA_CSS_VAMEM_TYPE_1(ISP2300) or
     IA_CSS_VAMEM_TYPE_2(ISP2400) */
union ia_css_xnr_data {
	uint16_t vamem_1[IA_CSS_VAMEM_1_XNR_TABLE_SIZE];
	/**< Coefficients table on vamem type1. u0.12, [0,4095] */
	uint16_t vamem_2[IA_CSS_VAMEM_2_XNR_TABLE_SIZE];
	/**< Coefficients table on vamem type2. u0.12, [0,4095] */
};

struct ia_css_xnr_table {
	enum ia_css_vamem_type vamem_type;
	union ia_css_xnr_data data;
};

/** eXtra Noise Reduction configuration.
 *
 *  NOTE: This paramater is not passed to ISP.
 *        ISP1 and ISP2 use XNR1, but the threshold in ia_css_xnr_config is not used.
 *        The threshold is set as constant value inside ISP.
 *
 *  ISP block: XNR1
 */
struct ia_css_xnr_config {
	uint32_t threshold;  /**< Threshold.
				u0.16, [0,65535], default/ineffective 0 */
};

#endif /* __IA_CSS_XNR_TYPES_H */

