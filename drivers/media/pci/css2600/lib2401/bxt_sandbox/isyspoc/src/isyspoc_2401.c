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

#include "math_support.h"
#include "assert_support.h"
#include "input_system.h"
#include "isyspoc_2401.h"

#define	ISYS_CSI_VIRTUAL_CH0	0
#define	ISYS_CSI_VIRTUAL_CH1	1
#define	ISYS_CSI_VIRTUAL_CH2	2
#define	ISYS_CSI_VIRTUAL_CH3	3

#define	MAX_ISYS_SENSOR_LANES	2

static bool ia_css_isys_translate_stream_cfg_to_input_system_input_port_type(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
		ia_css_isys_descr_t	*isys_stream_descr
);

static bool ia_css_isys_translate_stream_cfg_to_input_port_id(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr
);

static bool ia_css_isys_translate_stream_cfg_to_input_port_attr(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr,
	unsigned int ip_num
);

static bool ia_css_isys_translate_stream_cfg_to_input_port_resolution(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr,
	unsigned int ip_num
);

static bool isys_convert_mipi_dt_to_mipi_format(
	enum ia_css_isys_mipi_data_type dt,
	mipi_predictor_t compression,
	unsigned int *fmt_type
);

static unsigned int isys_mipi_dt_to_bits_per_subpixel(
	enum ia_css_isys_mipi_data_type dt
);

static unsigned int csi2_calc_max_subpixels_per_line(
	enum ia_css_isys_mipi_data_type dt,
	unsigned int pixels_per_line
);

static void init_tpg_config_defaults(
	pixelgen_tpg_cfg_t *attr
);

/**
 * isys_translate_stream_cfg_to_isys_stream_descr()
 */
bool ia_css_isys_translate_stream_cfg_to_isys_stream_descr(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr,
	unsigned int ip_num
) {
	bool rc;

	rc = ia_css_isys_translate_stream_cfg_to_input_system_input_port_type(stream_cfg,
			isys_stream_descr);

	rc  &= ia_css_isys_translate_stream_cfg_to_input_port_id(stream_cfg,
		isys_stream_descr);

	rc &= ia_css_isys_translate_stream_cfg_to_input_port_attr(
		stream_cfg,
		isys_stream_descr,
		ip_num);

	rc &= ia_css_isys_translate_stream_cfg_to_input_port_resolution(
		stream_cfg,
		isys_stream_descr,
		ip_num);

	return rc;
}

static bool ia_css_isys_translate_stream_cfg_to_input_system_input_port_type(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
		ia_css_isys_descr_t	*isys_stream_descr)
{
	bool rc;

	rc = true;

	switch (stream_cfg->src) {
	case IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT0:
		isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_TPG;
		break;

	case IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT1:
		isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_PRBS;
		break;

	case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT0:
	case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT1:
	case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT2:
		isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_SENSOR;
		break;

	default:
		rc = false;
		break;
	}

	return rc;
}
static bool ia_css_isys_translate_stream_cfg_to_input_port_id(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr
) {
	bool rc;

	rc = true;

	switch (stream_cfg->src) {
		case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT0:
			isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT0_ID;
			break;
		case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT1:
			isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT1_ID;
			break;
		case IA_CSS_ISYS_STREAM_SRC_CSI2_PORT2:
			isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT2_ID;
			break;
		case IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT0:
			isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT0_ID;
			break;
		case IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT1:
			isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT0_ID;
			break;
		default:
			rc = false;
	}

	return rc;
}

static bool ia_css_isys_translate_stream_cfg_to_input_port_attr(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr,
	unsigned int ip_num
) {
	bool rc;
	unsigned int fmt_type=0;

	rc = true;

	switch (isys_stream_descr->mode) {
	case INPUT_SYSTEM_SOURCE_TYPE_TPG: {

		isys_stream_descr->tpg_port_attr.color_cfg.R1 = 51;
		isys_stream_descr->tpg_port_attr.color_cfg.G1 = 102;
		isys_stream_descr->tpg_port_attr.color_cfg.B1 = 255;
		isys_stream_descr->tpg_port_attr.color_cfg.R2 = 0;
		isys_stream_descr->tpg_port_attr.color_cfg.G2 = 100;
		isys_stream_descr->tpg_port_attr.color_cfg.B2 = 160;

		init_tpg_config_defaults(&(isys_stream_descr->tpg_port_attr));

		isys_stream_descr->tpg_port_attr.sync_gen_cfg.hblank_cycles = 100;
		isys_stream_descr->tpg_port_attr.sync_gen_cfg.vblank_cycles = 100;
		isys_stream_descr->tpg_port_attr.sync_gen_cfg.nr_of_frames = ~(0x0);
		isys_stream_descr->tpg_port_attr.sync_gen_cfg.pixels_per_line = stream_cfg->input_pins[ip_num].input_res.width;
		isys_stream_descr->tpg_port_attr.sync_gen_cfg.lines_per_frame = stream_cfg->input_pins[ip_num].input_res.height;
		break;
		}
	case INPUT_SYSTEM_SOURCE_TYPE_PRBS: {
		isys_stream_descr->prbs_port_attr.seed0 = 0x355FFAA5;
		isys_stream_descr->prbs_port_attr.seed1 = 0xA3300FFB;

		isys_stream_descr->prbs_port_attr.sync_gen_cfg.hblank_cycles = 100;
		isys_stream_descr->prbs_port_attr.sync_gen_cfg.vblank_cycles = 100;
		isys_stream_descr->prbs_port_attr.sync_gen_cfg.pixels_per_clock = 1;
		isys_stream_descr->prbs_port_attr.sync_gen_cfg.nr_of_frames = ~(0x0);
		isys_stream_descr->prbs_port_attr.sync_gen_cfg.pixels_per_line = stream_cfg->input_pins[ip_num].input_res.width;
		isys_stream_descr->prbs_port_attr.sync_gen_cfg.lines_per_frame = stream_cfg->input_pins[ip_num].input_res.height;

		break;
		}
	case INPUT_SYSTEM_SOURCE_TYPE_SENSOR: {
		isys_stream_descr->csi_port_attr.active_lanes = MAX_ISYS_SENSOR_LANES;

		rc = isys_convert_mipi_dt_to_mipi_format(
				stream_cfg->input_pins[ip_num].dt,
				MIPI_PREDICTOR_NONE,
				&fmt_type);
		isys_stream_descr->csi_port_attr.fmt_type = fmt_type;

		switch (stream_cfg->vc) {
		case IA_CSS_ISYS_MIPI_VC_0:
			isys_stream_descr->csi_port_attr.ch_id = ISYS_CSI_VIRTUAL_CH0;
			break;
		case IA_CSS_ISYS_MIPI_VC_1:
			isys_stream_descr->csi_port_attr.ch_id = ISYS_CSI_VIRTUAL_CH1;
			break;
		case IA_CSS_ISYS_MIPI_VC_2:
			isys_stream_descr->csi_port_attr.ch_id = ISYS_CSI_VIRTUAL_CH2;
			break;
		case IA_CSS_ISYS_MIPI_VC_3:
			isys_stream_descr->csi_port_attr.ch_id = ISYS_CSI_VIRTUAL_CH3;
			break;
		default:
			rc = false;
		}
		break;
	}
	default:
			rc = false;
	}
	return rc;
}

static bool ia_css_isys_translate_stream_cfg_to_input_port_resolution(
	const struct ia_css_isys_stream_cfg_data *stream_cfg,
	ia_css_isys_descr_t	*isys_stream_descr,
	unsigned int ip_num
) {
	unsigned int bits_per_subpixel;
	unsigned int max_subpixels_per_line;
	unsigned int lines_per_frame;

	bits_per_subpixel = isys_mipi_dt_to_bits_per_subpixel(
					stream_cfg->input_pins[ip_num].dt);
	if (bits_per_subpixel == 0)
		return false;

	max_subpixels_per_line = csi2_calc_max_subpixels_per_line(
						stream_cfg->input_pins[ip_num].dt,
						stream_cfg->input_pins[ip_num].input_res.width);

	if (max_subpixels_per_line == 0)
		return false;

	/* for jpeg/embedded data with odd number of lines, round up to even.
	   this is required by hw ISYS2401 */
	lines_per_frame = CEIL_MUL2(
						stream_cfg->input_pins[ip_num].input_res.height,
						2);
	if (lines_per_frame == 0)
		return false;

	/* HW needs subpixel info for their settings */
	isys_stream_descr->input_port_resolution.bits_per_pixel	= bits_per_subpixel;
	isys_stream_descr->input_port_resolution.pixels_per_line = max_subpixels_per_line;
	isys_stream_descr->input_port_resolution.lines_per_frame = lines_per_frame;

	return true;
}

static bool isys_convert_mipi_dt_to_mipi_format(
	enum ia_css_isys_mipi_data_type dt,
	mipi_predictor_t compression,
	unsigned int *fmt_type
) {
	OP___assert(fmt_type != NULL);
	/*
	 * Custom (user defined) modes. Used for compressed
	 * MIPI transfers
	 *
	 * Checkpatch thinks the indent before "if" is suspect
	 * I think the only suspect part is the missing "else"
	 * because of the return.
	 */
	if (compression != MIPI_PREDICTOR_NONE) {
		switch (dt) {
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_6:
				*fmt_type = 6;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_7:
				*fmt_type = 7;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8:
				*fmt_type = 8;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10:
				*fmt_type = 10;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_12:
				*fmt_type = 12;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_14:
				*fmt_type = 14;
				break;
			case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_16:
				*fmt_type = 16;
				break;
			default:
				return false;
		}
		return true;
	}
	/*
	 * This mapping comes from the Arasan CSS function spec
	 * (CSS_func_spec1.08_ahb_sep29_08.pdf).
	 *
	 * MW: For some reason the mapping is not 1-to-1
	 */
	switch (dt) {
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_888:
			*fmt_type = MIPI_FORMAT_RGB888;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_555:
			*fmt_type = MIPI_FORMAT_RGB555;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_444:
			*fmt_type = MIPI_FORMAT_RGB444;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_565:
			*fmt_type = MIPI_FORMAT_RGB565;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_666:
			*fmt_type = MIPI_FORMAT_RGB666;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8:
			*fmt_type = MIPI_FORMAT_RAW8;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10:
			*fmt_type = MIPI_FORMAT_RAW10;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_6:
			*fmt_type = MIPI_FORMAT_RAW6;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_7:
			*fmt_type = MIPI_FORMAT_RAW7;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_12:
			*fmt_type = MIPI_FORMAT_RAW12;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_14:
			*fmt_type = MIPI_FORMAT_RAW14;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8:
			*fmt_type = MIPI_FORMAT_YUV420_8;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_10:
			*fmt_type = MIPI_FORMAT_YUV420_10;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_8:
			*fmt_type = MIPI_FORMAT_YUV422_8;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_10:
			*fmt_type = MIPI_FORMAT_YUV422_10;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_BINARY_8:
			*fmt_type = MIPI_FORMAT_BINARY_8;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8_LEGACY:
			*fmt_type = MIPI_FORMAT_YUV420_8_LEGACY;
			break;
		case IA_CSS_ISYS_MIPI_DATA_TYPE_EMBEDDED:
			*fmt_type = MIPI_FORMAT_EMBEDDED;
			break;
		default:
			return false;
	}

	return true;
}

static unsigned int isys_mipi_dt_to_bits_per_subpixel(
	enum ia_css_isys_mipi_data_type dt
) {
	unsigned int rval;

	switch (dt) {
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_444:
		rval = 4;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_555:
		rval = 5;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_565:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_666:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_6:
		rval = 6;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_7:
		rval = 7;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8_LEGACY:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_8:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_888:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8:
		rval = 8;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_10:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_10:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10:
		rval = 10;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_12:
		rval = 12;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_14:
		rval = 14;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_16:
		rval = 16;
		break;
	default:
		rval = 0;
		break;
	}

	return rval;
}

static unsigned int csi2_calc_max_subpixels_per_line(
	enum ia_css_isys_mipi_data_type dt,
	unsigned int pixels_per_line
) {
	unsigned int rval;

	switch (dt) {
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8_LEGACY:
		/*
		 * The frame format layout is shown below.
		 *
		 *		Line	0:	UYY UYY ... UYY
		 *		Line	1:	VYY VYY ... VYY
		 *		Line	2:	UYY UYY ... UYY
		 *		Line	3:	VYY VYY ... VYY
		 *		...
		 *		Line (n-2):	UYY UYY ... UYY
		 *		Line (n-1):	VYY VYY ... VYY
		 *
		 *	In this frame format, the even-line is
		 *	as wide as the odd-line.
		 */
		rval = pixels_per_line + pixels_per_line / 2;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_10:
		/*
		 * The frame format layout is shown below.
		 *
		 *		Line	0:	YYYY YYYY ... YYYY
		 *		Line	1:	UYVY UYVY ... UYVY UYVY
		 *		Line	2:	YYYY YYYY ... YYYY
		 *		Line	3:	UYVY UYVY ... UYVY UYVY
		 *		...
		 *		Line (n-2):	YYYY YYYY ... YYYY
		 *		Line (n-1):	UYVY UYVY ... UYVY UYVY
		 *
		 * In this frame format, the odd-line is twice
		 * wider than the even-line.
		 */
		rval = pixels_per_line * 2;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_8:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_10:
		/*
		 * The frame format layout is shown below.
		 *
		 *		Line	0:	UYVY UYVY ... UYVY
		 *		Line	1:	UYVY UYVY ... UYVY
		 *		Line	2:	UYVY UYVY ... UYVY
		 *		Line	3:	UYVY UYVY ... UYVY
		 *		...
		 *		Line (n-2):	UYVY UYVY ... UYVY
		 *		Line (n-1):	UYVY UYVY ... UYVY
		 *
		 * In this frame format, the even-line is
		 * as wide as the odd-line.
		 */
		rval = pixels_per_line * 2;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_444:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_555:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_565:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_666:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_888:
		/*
		 * The frame format layout is shown below.
		 *
		 *		Line	0:	ABGR ABGR ... ABGR
		 *		Line	1:	ABGR ABGR ... ABGR
		 *		Line	2:	ABGR ABGR ... ABGR
		 *		Line	3:	ABGR ABGR ... ABGR
		 *		...
		 *		Line (n-2):	ABGR ABGR ... ABGR
		 *		Line (n-1):	ABGR ABGR ... ABGR
		 *
		 * In this frame format, the even-line is
		 * as wide as the odd-line.
		 */
		rval = pixels_per_line * 4;
		break;
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_6:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_7:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_12:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_14:
	case IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_16:
		/*
		 * The frame format layout is shown below.
		 *
		 *		Line	0:	Pixel Pixel ... Pixel
		 *		Line	1:	Pixel Pixel ... Pixel
		 *		Line	2:	Pixel Pixel ... Pixel
		 *		Line	3:	Pixel Pixel ... Pixel
		 *		...
		 *		Line (n-2):	Pixel Pixel ... Pixel
		 *		Line (n-1):	Pixel Pixel ... Pixel
		 *
		 * In this frame format, the even-line is
		 * as wide as the odd-line.
		 */
		rval = pixels_per_line;
		break;
	default:
		rval = 0;
		break;
	}

	return rval;
}

static void init_tpg_config_defaults(pixelgen_tpg_cfg_t *attr)
{
		attr->mode = PIXELGEN_TPG_MODE_CHBO;
		attr->mask_cfg.h_mask = (1 << 4)-1;
		attr->mask_cfg.v_mask = (1 << 4)-1;
		attr->mask_cfg.hv_mask = (1 << 8)-1;

		attr->delta_cfg.h_delta = -2;
		attr->delta_cfg.v_delta = 3;
		attr->sync_gen_cfg.pixels_per_clock = 1;
}
