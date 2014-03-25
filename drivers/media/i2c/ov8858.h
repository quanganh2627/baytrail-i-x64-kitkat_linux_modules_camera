/*
 * Support for Omnivision OV8858 camera sensor.
 *
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
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

#ifndef __OV8858_H__
#define __OV8858_H__
#include <linux/atomisp_platform.h>
#include <media/v4l2-ctrls.h>


#define I2C_MSG_LENGTH		0x2

/*
 * This should be added into include/linux/videodev2.h
 * NOTE: This is most likely not used anywhere.
 * */
#define V4L2_IDENT_OV8858	V4L2_IDENT_UNKNOWN


/* Indexes for VCM driver lists */
#define OV8858_ID_DEFAULT	0
#define OV8858_SUNNY		1

/*
 * ov8858 System control registers
 */
#define OV8858_PLL_PLL10			0x3090 // Soren: Fix
#define OV8858_PLL_PLL11			0x3091 // Soren: Fix
#define OV8858_PLL_PLL12			0x3092 // Soren: Fix
#define OV8858_PLL_PLL13			0x3093 // Soren: Fix

#define OV8858_TIMING_HTS			0x380C
#define OV8858_TIMING_VTS			0x380E

#define OV8858_HORIZONTAL_START_H		0x3800
#define OV8858_VERTICAL_START_H			0x3802
#define OV8858_HORIZONTAL_END_H			0x3804
#define OV8858_VERTICAL_END_H			0x3806
#define OV8858_HORIZONTAL_OUTPUT_SIZE_H		0x3808
#define OV8858_VERTICAL_OUTPUT_SIZE_H		0x380A

#define OV8858_GROUP_ACCESS			0x3208
#define OV8858_GROUP_ZERO			0x00
#define OV8858_GROUP_ACCESS_HOLD_START		0x00
#define OV8858_GROUP_ACCESS_HOLD_END		0x10
#define OV8858_GROUP_ACCESS_DELAY_LAUNCH	0xA0
#define OV8858_GROUP_ACCESS_QUICK_LAUNCH	0xE0

#define OV_SUBDEV_PREFIX			"ov"
#define OV_ID_DEFAULT				0x0000
#define	OV8858_NAME				"ov8858"
#define OV8858_CHIP_ID				0x8858

#define OV8858_LONG_EXPO			0x3500
#define OV8858_AGC_ADJ				0x350B // Soren: Fix

#define OV8858_MWB_RED_GAIN_H			0x3400 // Soren: Fix
#define OV8858_MWB_GREEN_GAIN_H			0x3402 // Soren: Fix
#define OV8858_MWB_BLUE_GAIN_H			0x3404 // Soren: Fix
#define OV8858_MWB_GAIN_MAX			0x0FFF // Soren: ??

#define OV8858_CHIP_ID_HIGH			0x300B
#define OV8858_CHIP_ID_LOW			0x300C
#define OV8858_STREAM_MODE			0x0100

#define OV8858_FOCAL_LENGTH_NUM			294	/* 2.94mm */
#define OV8858_FOCAL_LENGTH_DEM			100
#define OV8858_F_NUMBER_DEFAULT_NUM		24	/* 2.4 */
#define OV8858_F_NUMBER_DEM			10

#define OV8858_H_INC_ODD			0x3814
#define OV8858_H_INC_EVEN			0x3815
#define OV8858_V_INC_ODD			0x382A
#define OV8858_V_INC_EVEN			0x382B

/* sensor_mode_data read_mode adaptation */
#define OV8858_READ_MODE_BINNING_ON		0x0400 // Soren: Check this
#define OV8858_READ_MODE_BINNING_OFF		0x00 // Soren: Check this
#define OV8858_BIN_FACTOR_MAX			2
#define OV8858_INTEGRATION_TIME_MARGIN		14

#define OV8858_MAX_VTS_VALUE			0x7FFF // Soren: ??
#define OV8858_MAX_EXPOSURE_VALUE \
		(OV8858_MAX_VTS_VALUE - OV8858_INTEGRATION_TIME_MARGIN)
#define OV8858_MAX_GAIN_VALUE			0xFF // Soren: ??

#define OV8858_MAX_FOCUS_POS			1023

#define OV8858_TEST_PATTERN_REG			0x5E00

struct ov8858_vcm {
	int (*power_up)(struct v4l2_subdev *sd);
	int (*power_down)(struct v4l2_subdev *sd);
	int (*init)(struct v4l2_subdev *sd);
	int (*t_focus_vcm)(struct v4l2_subdev *sd, u16 val);
	int (*t_focus_abs)(struct v4l2_subdev *sd, s32 value);
	int (*t_focus_rel)(struct v4l2_subdev *sd, s32 value);
	int (*q_focus_status)(struct v4l2_subdev *sd, s32 *value);
	int (*q_focus_abs)(struct v4l2_subdev *sd, s32 *value);
	int (*t_vcm_slew)(struct v4l2_subdev *sd, s32 value);
	int (*t_vcm_timing)(struct v4l2_subdev *sd, s32 value);
};

/* Defines for register writes and register array processing */
#define OV8858_BYTE_MAX				32
#define OV8858_SHORT_MAX			16
#define OV8858_TOK_MASK				0xFFF0

#define MAX_FPS_OPTIONS_SUPPORTED		3

enum ov8858_tok_type {
	OV8858_8BIT  = 0x0001,
	OV8858_16BIT = 0x0002,
	OV8858_TOK_TERM   = 0xF000,	/* terminating token for reg list */
	OV8858_TOK_DELAY  = 0xFE00	/* delay token for reg list */
};

/*
 * If register address or register width is not 32 bit width,
 * user needs to convert it manually
 */
struct s_register_setting {
	u32 reg;
	u32 val;
};

/**
 * struct ov8858_reg - MI sensor register format
 * @type: type of the register
 * @reg: 16-bit offset to register
 * @val: 8/16/32-bit register value
 *
 * Define a structure for sensor register initialization values
 */
struct ov8858_reg {
	enum ov8858_tok_type type;
	u16 sreg;
	u32 val;	/* @set value for read/mod/write, @mask */
};

struct ov8858_fps_setting {
	int fps;
	unsigned short pixels_per_line;
	unsigned short lines_per_frame;
	const struct ov8858_reg *regs; /* regs that the fps setting needs */
};

struct ov8858_resolution {
	u8 *desc;
	const struct ov8858_reg *regs;
	int res;
	int width;
	int height;
	bool used;
	u8 bin_factor_x;
	u8 bin_factor_y;
	unsigned short skip_frames;
	const struct ov8858_fps_setting fps_options[MAX_FPS_OPTIONS_SUPPORTED];
};

/* ov8858 device structure */
struct ov8858_device {
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_mbus_framefmt format;

	struct camera_sensor_platform_data *platform_data;
	struct mutex input_lock; /* serialize sensor's ioctl */
	int fmt_idx;
	int streaming;
	int vt_pix_clk_freq_mhz;
	int fps_index;
	u16 sensor_id;			/* Sensor id from registers */
	u16 i2c_id;			/* Sensor id from i2c_device_id */
	int exposure;
	int gain;
	u16 digital_gain;
	u16 pixels_per_line;
	u16 lines_per_frame;
	u8 fps;
	const struct ov8858_reg *regs;
	struct ov8858_vcm *vcm_driver;
	const struct ov8858_resolution *curr_res_table;
	int entries_curr_table;

	struct v4l2_ctrl_handler ctrl_handler;
	struct v4l2_ctrl *run_mode;
};

#define to_ov8858_sensor(x) container_of(x, struct ov8858_device, sd)

#define OV8858_MAX_WRITE_BUF_SIZE	32
struct ov8858_write_buffer {
	u16 addr;
	u8 data[OV8858_MAX_WRITE_BUF_SIZE];
};

struct ov8858_write_ctrl {
	int index;
	struct ov8858_write_buffer buffer;
};

static const struct ov8858_reg ov8858_soft_standby[] = {
	{OV8858_8BIT, 0x0100, 0x00},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_streaming[] = {
	{OV8858_8BIT, 0x0100, 0x01},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_param_hold[] = {
	{OV8858_8BIT, OV8858_GROUP_ACCESS,
			OV8858_GROUP_ZERO | OV8858_GROUP_ACCESS_HOLD_START},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_param_update[] = {
	{OV8858_8BIT, OV8858_GROUP_ACCESS,
			OV8858_GROUP_ZERO | OV8858_GROUP_ACCESS_HOLD_END},
	{OV8858_8BIT, OV8858_GROUP_ACCESS,
			OV8858_GROUP_ZERO | OV8858_GROUP_ACCESS_DELAY_LAUNCH},
	{OV8858_TOK_TERM, 0, 0}
};

extern int dw9718_vcm_power_up(struct v4l2_subdev *sd);
extern int dw9718_vcm_power_down(struct v4l2_subdev *sd);
extern int dw9718_vcm_init(struct v4l2_subdev *sd);
extern int dw9718_t_focus_vcm(struct v4l2_subdev *sd, u16 val);
extern int dw9718_t_focus_abs(struct v4l2_subdev *sd, s32 value);
extern int dw9718_t_focus_rel(struct v4l2_subdev *sd, s32 value);
extern int dw9718_q_focus_status(struct v4l2_subdev *sd, s32 *value);
extern int dw9718_q_focus_abs(struct v4l2_subdev *sd, s32 *value);
extern int dw9718_t_vcm_slew(struct v4l2_subdev *sd, s32 value);
extern int dw9718_t_vcm_timing(struct v4l2_subdev *sd, s32 value);

extern int vcm_power_up(struct v4l2_subdev *sd);
extern int vcm_power_down(struct v4l2_subdev *sd);

struct ov8858_vcm ov8858_vcms[] = {
	[OV8858_SUNNY] = {
		.power_up = dw9718_vcm_power_up,
		.power_down = dw9718_vcm_power_down,
		.init = dw9718_vcm_init,
		.t_focus_vcm = dw9718_t_focus_vcm,
		.t_focus_abs = dw9718_t_focus_abs,
		.t_focus_rel = dw9718_t_focus_rel,
		.q_focus_status = dw9718_q_focus_status,
		.q_focus_abs = dw9718_q_focus_abs,
		.t_vcm_slew = dw9718_t_vcm_slew,
		.t_vcm_timing = dw9718_t_vcm_timing,
	},
	[OV8858_ID_DEFAULT] = {
		.power_up = vcm_power_up,
		.power_down = vcm_power_down,
	},
};


#define OV8858_RES_WIDTH_MAX	3280
#define OV8858_RES_HEIGHT_MAX	2464

static const struct ov8858_reg ov8858_module_detection[] = {
	{OV8858_8BIT, OV8858_STREAM_MODE, 0x01}, /* Stream on */
	{OV8858_8BIT, 0x3d84, 0xc0}, /* Select Bank 0 */
	{OV8858_8BIT, 0x3d81, 0x01}, /* OTP read enable */
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_BasicSettings[] = {
	{OV8858_8BIT, 0x0103, 0x01}, /* software_reset */
	{OV8858_8BIT, 0x0100, 0x00}, /* software_standby */
	/* PLL settings */
	{OV8858_8BIT, 0x0300, 0x02}, /* pll1_pre_div = /2 */
	{OV8858_8BIT, 0x0302, 0x4B}, /* pll1_multiplier = 75 */
	{OV8858_8BIT, 0x0303, 0x00}, /* pll1_divm = /(1 + 0) */
	{OV8858_8BIT, 0x0304, 0x03}, /* pll1_div_mipi = /8 */
	{OV8858_8BIT, 0x030B, 0x02}, /* pll2_pre_div = /2 */
	{OV8858_8BIT, 0x030D, 0x4B}, /* pll2_r_divp = 75 */
	{OV8858_8BIT, 0x030E, 0x00}, /* pll2_r_divs = /1 */
	{OV8858_8BIT, 0x030F, 0x04}, /* pll2_r_divsp = /(1 + 4) */
	/* pll2_pre_div0 = /1, pll2_r_divdac = /(1 + 1) */
	{OV8858_8BIT, 0x0312, 0x01},
	{OV8858_8BIT, 0x031E, 0x0C}, /* pll1_no_lat = 1, mipi_bitsel_man = 0 */

	{OV8858_8BIT, 0x3600, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3601, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3602, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3603, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3604, 0x22}, /* Unknown */
	{OV8858_8BIT, 0x3605, 0x30}, /* Unknown */
	{OV8858_8BIT, 0x3606, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3607, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x3608, 0x11}, /* Unknown */
	{OV8858_8BIT, 0x3609, 0x28}, /* Unknown */
	{OV8858_8BIT, 0x360A, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x360B, 0x06}, /* Unknown */
	{OV8858_8BIT, 0x360C, 0xDC}, /* Unknown */
	{OV8858_8BIT, 0x360D, 0x40}, /* Unknown */
	{OV8858_8BIT, 0x360E, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x360F, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x3610, 0x07}, /* Unknown */
	{OV8858_8BIT, 0x3611, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x3612, 0x88}, /* Unknown */
	{OV8858_8BIT, 0x3613, 0x80}, /* Unknown */
	{OV8858_8BIT, 0x3614, 0x58}, /* Unknown */
	{OV8858_8BIT, 0x3615, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3616, 0x4A}, /* Unknown */
	{OV8858_8BIT, 0x3617, 0x90}, /* Unknown */
	{OV8858_8BIT, 0x3618, 0x56}, /* Unknown */
	{OV8858_8BIT, 0x3619, 0x70}, /* Unknown */
	{OV8858_8BIT, 0x361A, 0x99}, /* Unknown */
	{OV8858_8BIT, 0x361B, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x361C, 0x07}, /* Unknown */
	{OV8858_8BIT, 0x361D, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x361E, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x361F, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3633, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3634, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3635, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3636, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3638, 0xFF}, /* Unknown */
	{OV8858_8BIT, 0x3645, 0x13}, /* Unknown */
	{OV8858_8BIT, 0x3646, 0x83}, /* Unknown */
	{OV8858_8BIT, 0x364A, 0x07}, /* Unknown */

	/* Npump clock div = /2, Ppump clock div = /4 */
	{OV8858_8BIT, 0x3015, 0x01},
	/* mipi_lane_mode = 1+3, mipi_lvds_sel = 1 = MIPI enable,
	 * r_phy_pd_mipi_man = 0, lane_dis_option = 0 */
	{OV8858_8BIT, 0x3018, 0x72},
	/*Clock switch output = normal, pclk_div = /1 */
	{OV8858_8BIT, 0x3020, 0x93},
	/* lvds_mode_o = 0, clock lane disable when pd_mipi = 0,
	 * pd_mipi enable when rst_sync = 1 */
	{OV8858_8BIT, 0x3022, 0x01},
	{OV8858_8BIT, 0x3031, 0x0A}, /* mipi_bit_sel = 10 */
	{OV8858_8BIT, 0x3034, 0x00}, /* Unknown */
	/* sclk_div = /1, sclk_pre_div = /1, chip debug = 1 */
	{OV8858_8BIT, 0x3106, 0x01},

	{OV8858_8BIT, 0x3305, 0xF1}, /* Unknown */
	{OV8858_8BIT, 0x3307, 0x04}, /* Unknown */
	{OV8858_8BIT, 0x3308, 0x28}, /* Unknown */
	{OV8858_8BIT, 0x3309, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x330A, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x330B, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x330C, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x330D, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x330E, 0x40}, /* Unknown */
	{OV8858_8BIT, 0x330F, 0x04}, /* Unknown */

	{OV8858_8BIT, 0x3500, 0x00}, /* long exposure = 0x9A20 */
	{OV8858_8BIT, 0x3501, 0x9A}, /* long exposure = 0x9A20 */
	{OV8858_8BIT, 0x3502, 0x20}, /* long exposure = 0x9A20 */
	/* Digital fraction gain delay option = Delay 1 frame,
	 * Gain change delay option = Delay 1 frame,
	 * Gain delay option = Delay 1 frame,
	 * Gain manual as sensor gain = Input gain as real gain format,
	 * Exposure delay option (must be 0 = Delay 1 frame,
	 * Exposure change delay option (must be 0) = Delay 1 frame */
	{OV8858_8BIT, 0x3503, 0x00},
	{OV8858_8BIT, 0x3505, 0x80}, /* gain conversation option */
	/* [10:7] are integer gain, [6:0] are fraction gain. For example:
	 * 0x80 is 1x gain, 0x100 is 2x gain, 0x1C0 is 3.5x gain */
	{OV8858_8BIT, 0x3508, 0x02}, /* long gain = 0x0200 */
	{OV8858_8BIT, 0x3509, 0x00}, /* long gain = 0x0200 */
	{OV8858_8BIT, 0x350C, 0x00}, /* short gain = 0x0080 */
	{OV8858_8BIT, 0x350D, 0x80}, /* short gain = 0x0080 */
	{OV8858_8BIT, 0x3510, 0x00}, /* short exposure = 0x000200 */
	{OV8858_8BIT, 0x3511, 0x02}, /* short exposure = 0x000200 */
	{OV8858_8BIT, 0x3512, 0x00}, /* short exposure = 0x000200 */

	{OV8858_8BIT, 0x3700, 0x30}, /* Unknown */
	{OV8858_8BIT, 0x3701, 0x18}, /* Unknown */
	{OV8858_8BIT, 0x3702, 0x50}, /* Unknown */
	{OV8858_8BIT, 0x3703, 0x32}, /* Unknown */
	{OV8858_8BIT, 0x3704, 0x28}, /* Unknown */
	{OV8858_8BIT, 0x3705, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3706, 0x6A}, /* Unknown */
	{OV8858_8BIT, 0x3707, 0x08}, /* Unknown */
	{OV8858_8BIT, 0x3708, 0x48}, /* Unknown */
	{OV8858_8BIT, 0x3709, 0x66}, /* Unknown */
	{OV8858_8BIT, 0x370A, 0x01}, /* Unknown */
	{OV8858_8BIT, 0x370B, 0x6A}, /* Unknown */
	{OV8858_8BIT, 0x370C, 0x07}, /* Unknown */
	{OV8858_8BIT, 0x3712, 0x44}, /* Unknown */
	{OV8858_8BIT, 0x3714, 0x24}, /* Unknown */
	{OV8858_8BIT, 0x3718, 0x14}, /* Unknown */
	{OV8858_8BIT, 0x3719, 0x31}, /* Unknown */
	{OV8858_8BIT, 0x371E, 0x31}, /* Unknown */
	{OV8858_8BIT, 0x371F, 0x7F}, /* Unknown */
	{OV8858_8BIT, 0x3720, 0x0A}, /* Unknown */
	{OV8858_8BIT, 0x3721, 0x0A}, /* Unknown */
	{OV8858_8BIT, 0x3724, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3725, 0x02}, /* Unknown */
	{OV8858_8BIT, 0x3726, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3728, 0x0A}, /* Unknown */
	{OV8858_8BIT, 0x3729, 0x03}, /* Unknown */
	{OV8858_8BIT, 0x372A, 0x06}, /* Unknown */
	{OV8858_8BIT, 0x372B, 0xA6}, /* Unknown */
	{OV8858_8BIT, 0x372C, 0xA6}, /* Unknown */
	{OV8858_8BIT, 0x372D, 0xA6}, /* Unknown */
	{OV8858_8BIT, 0x372E, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x372F, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x3730, 0x02}, /* Unknown */
	{OV8858_8BIT, 0x3731, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x3732, 0x28}, /* Unknown */
	{OV8858_8BIT, 0x3733, 0x10}, /* Unknown */
	{OV8858_8BIT, 0x3734, 0x40}, /* Unknown */
	{OV8858_8BIT, 0x3736, 0x30}, /* Unknown */
	{OV8858_8BIT, 0x373A, 0x0A}, /* Unknown */
	{OV8858_8BIT, 0x373B, 0x0B}, /* Unknown */
	{OV8858_8BIT, 0x373C, 0x14}, /* Unknown */
	{OV8858_8BIT, 0x373E, 0x06}, /* Unknown */
	{OV8858_8BIT, 0x3755, 0x10}, /* Unknown */
	{OV8858_8BIT, 0x3758, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3759, 0x4C}, /* Unknown */
	{OV8858_8BIT, 0x375A, 0x0C}, /* Unknown */
	{OV8858_8BIT, 0x375B, 0x26}, /* Unknown */
	{OV8858_8BIT, 0x375C, 0x20}, /* Unknown */
	{OV8858_8BIT, 0x375D, 0x04}, /* Unknown */
	{OV8858_8BIT, 0x375E, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x375F, 0x28}, /* Unknown */
	{OV8858_8BIT, 0x3760, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3761, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3762, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3763, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3766, 0xFF}, /* Unknown */
	{OV8858_8BIT, 0x3768, 0x22}, /* Unknown */
	{OV8858_8BIT, 0x3769, 0x44}, /* Unknown */
	{OV8858_8BIT, 0x376A, 0x44}, /* Unknown */
	{OV8858_8BIT, 0x376B, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x376F, 0x01}, /* Unknown */
	{OV8858_8BIT, 0x3772, 0x46}, /* Unknown */
	{OV8858_8BIT, 0x3773, 0x04}, /* Unknown */
	{OV8858_8BIT, 0x3774, 0x2C}, /* Unknown */
	{OV8858_8BIT, 0x3775, 0x13}, /* Unknown */
	{OV8858_8BIT, 0x3776, 0x08}, /* Unknown */
	{OV8858_8BIT, 0x3777, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x3778, 0x16}, /* Unknown */
	{OV8858_8BIT, 0x37A0, 0x88}, /* Unknown */
	{OV8858_8BIT, 0x37A1, 0x7A}, /* Unknown */
	{OV8858_8BIT, 0x37A2, 0x7A}, /* Unknown */
	{OV8858_8BIT, 0x37A3, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37A4, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37A5, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37A6, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37A7, 0x88}, /* Unknown */
	{OV8858_8BIT, 0x37A8, 0x98}, /* Unknown */
	{OV8858_8BIT, 0x37A9, 0x98}, /* Unknown */
	{OV8858_8BIT, 0x37AA, 0x88}, /* Unknown */
	{OV8858_8BIT, 0x37AB, 0x5C}, /* Unknown */
	{OV8858_8BIT, 0x37AC, 0x5C}, /* Unknown */
	{OV8858_8BIT, 0x37AD, 0x55}, /* Unknown */
	{OV8858_8BIT, 0x37AE, 0x19}, /* Unknown */
	{OV8858_8BIT, 0x37AF, 0x19}, /* Unknown */
	{OV8858_8BIT, 0x37B0, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B1, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B2, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B3, 0x84}, /* Unknown */
	{OV8858_8BIT, 0x37B4, 0x84}, /* Unknown */
	{OV8858_8BIT, 0x37B5, 0x66}, /* Unknown */
	{OV8858_8BIT, 0x37B6, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B7, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B8, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x37B9, 0xFF}, /* Unknown */

	{OV8858_8BIT, 0x3800, 0x00}, /* h_crop_start high */
	{OV8858_8BIT, 0x3801, 0x0C}, /* h_crop_start low */
	{OV8858_8BIT, 0x3802, 0x00}, /* v_crop_start high */
	{OV8858_8BIT, 0x3803, 0x0C}, /* v_crop_start low */
	{OV8858_8BIT, 0x3804, 0x0C}, /* h_crop_end high */
	{OV8858_8BIT, 0x3805, 0xD3}, /* h_crop_end low */
	{OV8858_8BIT, 0x3806, 0x09}, /* v_crop_end high */
	{OV8858_8BIT, 0x3807, 0xA3}, /* v_crop_end low */
	{OV8858_8BIT, 0x3808, 0x0C}, /* h_output_size high */
	{OV8858_8BIT, 0x3809, 0xC0}, /* h_output_size low */
	{OV8858_8BIT, 0x380A, 0x09}, /* v_output_size high */
	{OV8858_8BIT, 0x380B, 0x90}, /* v_output_size low */
	{OV8858_8BIT, 0x380C, 0x07}, /* horizontal timing size high */
	{OV8858_8BIT, 0x380D, 0x94}, /* horizontal timing size low */
	{OV8858_8BIT, 0x380E, 0x09}, /* vertical timing size high */
	{OV8858_8BIT, 0x380F, 0xAA}, /* vertical timing size low */
	{OV8858_8BIT, 0x3810, 0x00}, /* h_win offset high */
	{OV8858_8BIT, 0x3811, 0x04}, /* h_win offset low */
	{OV8858_8BIT, 0x3812, 0x00}, /* v_win offset high */
	{OV8858_8BIT, 0x3813, 0x02}, /* v_win offset low */
	{OV8858_8BIT, 0x3814, 0x01}, /* h_odd_inc */
	{OV8858_8BIT, 0x3815, 0x01}, /* h_even_inc */
	{OV8858_8BIT, 0x3820, 0x00}, /* format1 */
	{OV8858_8BIT, 0x3821, 0x46}, /* format2 */
	{OV8858_8BIT, 0x382A, 0x01}, /* v_odd_inc */
	{OV8858_8BIT, 0x382B, 0x01}, /* v_even_inc */

	{OV8858_8BIT, 0x3830, 0x06}, /* Unknown */
	{OV8858_8BIT, 0x3836, 0x01}, /* Unknown */
	{OV8858_8BIT, 0x3837, 0x18}, /* Unknown */
	{OV8858_8BIT, 0x3841, 0xFF}, /* AUTO_SIZE_CTRL */
	{OV8858_8BIT, 0x3846, 0x48}, /* Unknown */

	{OV8858_8BIT, 0x3D85, 0x14}, /* OTP_REG85 */
	{OV8858_8BIT, 0x3F08, 0x10}, /* PSRAM control register */

	{OV8858_8BIT, 0x4000, 0xF1}, /* BLC CTRL00 = default */
	{OV8858_8BIT, 0x4001, 0x00}, /* BLC CTRL01 */
	{OV8858_8BIT, 0x4002, 0x27}, /* BLC offset = 0x27 */
	{OV8858_8BIT, 0x4005, 0x10}, /* BLC target = 0x0010 */
	{OV8858_8BIT, 0x4009, 0x81}, /* BLC CTRL09 */
	{OV8858_8BIT, 0x400B, 0x0C}, /* BLC CTRL0B = default */
	{OV8858_8BIT, 0x401B, 0x00}, /* Zero line R coeff. = 0x0000 */
	{OV8858_8BIT, 0x401D, 0x00}, /* Zero line T coeff. = 0x0000 */
	{OV8858_8BIT, 0x401F, 0x00}, /* BLC CTRL1F */
	{OV8858_8BIT, 0x4020, 0x00}, /* Anchor left start = 0x0004 */
	{OV8858_8BIT, 0x4021, 0x04}, /* Anchor left start = 0x0004 */
	{OV8858_8BIT, 0x4022, 0x0B}, /* Anchor left end = 0x0BC3 */
	{OV8858_8BIT, 0x4023, 0xC3}, /* Anchor left end = 0x0BC3 */
	{OV8858_8BIT, 0x4024, 0x0C}, /* Anchor right start = 0x0C36 */
	{OV8858_8BIT, 0x4025, 0x36}, /* Anchor right start = 0x0C36 */
	{OV8858_8BIT, 0x4026, 0x0C}, /* Anchor right end = 0x0C37 */
	{OV8858_8BIT, 0x4027, 0x37}, /* Anchor right end = 0x0C37 */
	{OV8858_8BIT, 0x4028, 0x00}, /* Top zero line start = 0 */
	{OV8858_8BIT, 0x4029, 0x02}, /* Top zero line number = 2 */
	{OV8858_8BIT, 0x402A, 0x04}, /* Top black line start = 4 */
	{OV8858_8BIT, 0x402B, 0x08}, /* Top black line number = 8 */
	{OV8858_8BIT, 0x402C, 0x02}, /* Bottom zero start line = 2 */
	{OV8858_8BIT, 0x402D, 0x02}, /* Bottom zero line number = 2 */
	{OV8858_8BIT, 0x402E, 0x0C}, /* Bottom black line start = 12 */
	{OV8858_8BIT, 0x402F, 0x02}, /* Bottom black line number = 2 */

	{OV8858_8BIT, 0x4034, 0x3F}, /* Unknown */
	{OV8858_8BIT, 0x403D, 0x04}, /* BLC CTRL3D */
	{OV8858_8BIT, 0x4300, 0xFF}, /* clip_max[11:4] = 0xFFF */
	{OV8858_8BIT, 0x4301, 0x00}, /* clip_min[11:4] = 0 */
	{OV8858_8BIT, 0x4302, 0x0F}, /* clip_min/max[3:0] */
	{OV8858_8BIT, 0x4316, 0x00}, /* CTRL16 = default */
	{OV8858_8BIT, 0x4503, 0x18}, /* Unknown */
	{OV8858_8BIT, 0x4600, 0x01}, /* Unknown */
	{OV8858_8BIT, 0x4601, 0x97}, /* Unknown */
	/* wkup_dly = Mark1 wakeup delay/2^10 = 0x25 */
	{OV8858_8BIT, 0x4808, 0x25},
	{OV8858_8BIT, 0x481F, 0x32}, /* clk_prepare_min = 0x32 */
	{OV8858_8BIT, 0x4825, 0x3A}, /* lpx_p_min = 0x3A */
	{OV8858_8BIT, 0x4826, 0x40}, /* hs_prepare_min = 0x40 */
	{OV8858_8BIT, 0x4837, 0x16}, /* pclk_period = 0x16 */
	{OV8858_8BIT, 0x4850, 0x10}, /* LANE SEL01 */
	{OV8858_8BIT, 0x4851, 0x32}, /* LANE SEL02 */

	{OV8858_8BIT, 0x4B00, 0x2A}, /* Unknown */
	{OV8858_8BIT, 0x4B0D, 0x00}, /* Unknown */
	{OV8858_8BIT, 0x4D00, 0x04}, /* TPM_CTRL_REG */
	{OV8858_8BIT, 0x4D01, 0x18}, /* TPM_CTRL_REG */
	{OV8858_8BIT, 0x4D02, 0xC3}, /* TPM_CTRL_REG */
	{OV8858_8BIT, 0x4D03, 0xFF}, /* TPM_CTRL_REG */
	{OV8858_8BIT, 0x4D04, 0xFF}, /* TPM_CTRL_REG */
	{OV8858_8BIT, 0x4D05, 0xFF}, /* TPM_CTRL_REG */

	/* Lens correction (LENC) function enable = 0
	 * Slave sensor AWB Gain function enable = 1
	 * Slave sensor AWB Statistics function enable = 1
	 * Master sensor AWB Gain function enable = 1
	 * Master sensor AWB Statistics function enable = 1
	 * Black DPC function enable = 1
	 * White DPC function enable =1 */
	{OV8858_8BIT, 0x5000, 0x7E},
	{OV8858_8BIT, 0x5001, 0x01}, /* BLC function enable = 1 */
	/* Horizontal scale function enable = 0
	 * WBMATCH bypass mode = Select slave sensor's gain
	 * WBMATCH function enable = 0
	 * Master MWB gain support RGBC = 0
	 * OTP_DPC function enable = 1
	 * Manual mode of VarioPixel function enable = 0
	 * Manual enable of VarioPixel function enable = 0
	 * Use VSYNC to latch ISP modules's function enable signals = 0 */
	{OV8858_8BIT, 0x5002, 0x08},
	/* Bypass all ISP modules after BLC module = 0
	 * DPC_DBC buffer control enable = 1
	 * WBMATCH VSYNC selection = Select master sensor's VSYNC fall
	 * Select master AWB gain to embed line = AWB gain before manual mode
	 * Enable BLC's input flip_i signal = 0 */
	{OV8858_8BIT, 0x5003, 0x20},
	{OV8858_8BIT, 0x5046, 0x12}, /* ISP CTRL46 = default */
	/* Tail enable = 1
	 * Saturate cross cluster enable = 1
	 * Remove cross cluster enable = 1
	 * Enable to remove connected defect pixels in same channel = 1
	 * Enable to remove connected defect pixels in different channel = 1
	 * Smooth enable, use average G for recovery = 1
	 * Black/white sensor mode enable = 0
	 * Manual mode enable = 0 */
	{OV8858_8BIT, 0x5780, 0xFC},
	{OV8858_8BIT, 0x5784, 0x0C}, /* DPC CTRL04 */
	{OV8858_8BIT, 0x5787, 0x40}, /* DPC CTRL07 */
	{OV8858_8BIT, 0x5788, 0x08}, /* DPC CTRL08 */
	{OV8858_8BIT, 0x578A, 0x02}, /* DPC CTRL0A */
	{OV8858_8BIT, 0x578B, 0x01}, /* DPC CTRL0B */
	{OV8858_8BIT, 0x578C, 0x01}, /* DPC CTRL0C */
	{OV8858_8BIT, 0x578E, 0x02}, /* DPC CTRL0E */
	{OV8858_8BIT, 0x578F, 0x01}, /* DPC CTRL0F */
	{OV8858_8BIT, 0x5790, 0x01}, /* DPC CTRL10 */
	{OV8858_8BIT, 0x5901, 0x00}, /* VAP CTRL01 = default */
	{OV8858_8BIT, 0x5B00, 0x02}, /* OTP CTRL00 */
	{OV8858_8BIT, 0x5B01, 0x10}, /* OTP CTRL01 */
	{OV8858_8BIT, 0x5B02, 0x03}, /* OTP CTRL02 */
	{OV8858_8BIT, 0x5B03, 0xCF}, /* OTP CTRL03 */
	{OV8858_8BIT, 0x5B05, 0x6C}, /* OTP CTRL05 = default */
	{OV8858_8BIT, 0x5E00, 0x00}, /* PRE CTRL00 = default */
	{OV8858_8BIT, 0x5E01, 0x41}, /* PRE_CTRL01 = default */

	{OV8858_8BIT, 0x0100, 0x01}, /* Streaming enable */
	{OV8858_TOK_TERM, 0, 0}
};

#if 0
	{OV8858_8BIT, 0x0102, 0x01},
	{OV8858_8BIT, 0x3000, 0x00},
	{OV8858_8BIT, 0x3001, 0x2a},
	{OV8858_8BIT, 0x3002, 0x88},
	{OV8858_8BIT, 0x3003, 0x00},
	{OV8858_8BIT, 0x3004, 0x00},
	{OV8858_8BIT, 0x3005, 0x00},
	{OV8858_8BIT, 0x3006, 0x00},
	{OV8858_8BIT, 0x3007, 0x00},
	{OV8858_8BIT, 0x3008, 0x00},
	{OV8858_8BIT, 0x3009, 0x00},
	{OV8858_8BIT, 0x3011, 0x41},
	{OV8858_8BIT, 0x3012, 0x08},
	{OV8858_8BIT, 0x3013, 0x10},
	{OV8858_8BIT, 0x3014, 0x00},
	{OV8858_8BIT, 0x3015, 0x08},
	{OV8858_8BIT, 0x3016, 0xf0},
	{OV8858_8BIT, 0x3017, 0xf0},
	{OV8858_8BIT, 0x3018, 0xf0},
	{OV8858_8BIT, 0x301b, 0xb4},
	{OV8858_8BIT, 0x301d, 0x02},
	{OV8858_8BIT, 0x3021, 0x00},
	{OV8858_8BIT, 0x3022, 0x00},
	{OV8858_8BIT, 0x3024, 0x00},
	{OV8858_8BIT, 0x3026, 0x00},
	{OV8858_8BIT, 0x3027, 0x00},
	{OV8858_8BIT, 0x3081, 0x02},
	{OV8858_8BIT, 0x3083, 0x01},
	{OV8858_8BIT, 0x3090, 0x01}, /* PLL2 Settings SCLK 192mhZ*/
	{OV8858_8BIT, 0x3091, 0x14},
	{OV8858_8BIT, 0x3094, 0x00},
	{OV8858_8BIT, 0x3092, 0x01},
	{OV8858_8BIT, 0x3093, 0x00},
	{OV8858_8BIT, 0x3098, 0x03}, /* PLL3 Settings REF_CLK */
	{OV8858_8BIT, 0x3099, 0x13},
	{OV8858_8BIT, 0x309a, 0x00},
	{OV8858_8BIT, 0x309b, 0x00},
	{OV8858_8BIT, 0x309c, 0x01},
	{OV8858_8BIT, 0x30b3, 0x6b}, /* MIPI PLL1 Settings 684.4Mbps */
	{OV8858_8BIT, 0x30b4, 0x03},
	{OV8858_8BIT, 0x30b5, 0x04},
	{OV8858_8BIT, 0x30b6, 0x01},
	{OV8858_8BIT, 0x3104, 0xa1},
	{OV8858_8BIT, 0x3106, 0x01},
	{OV8858_8BIT, 0x3300, 0x00},
	{OV8858_8BIT, 0x3400, 0x04},
	{OV8858_8BIT, 0x3401, 0x00},
	{OV8858_8BIT, 0x3402, 0x04},
	{OV8858_8BIT, 0x3403, 0x00},
	{OV8858_8BIT, 0x3404, 0x04},
	{OV8858_8BIT, 0x3405, 0x00},
	{OV8858_8BIT, 0x3406, 0x01},
	{OV8858_8BIT, 0x3500, 0x00},
	{OV8858_8BIT, 0x3501, 0x30},
	{OV8858_8BIT, 0x3502, 0x00},
	{OV8858_8BIT, 0x3503, 0x07},
	{OV8858_8BIT, 0x3504, 0x00},
	{OV8858_8BIT, 0x3505, 0x30},
	{OV8858_8BIT, 0x3506, 0x00},
	{OV8858_8BIT, 0x3507, 0x10},
	{OV8858_8BIT, 0x3508, 0x80},
	{OV8858_8BIT, 0x3509, 0x10},
	{OV8858_8BIT, 0x350a, 0x00},
	{OV8858_8BIT, 0x350b, 0x38},
	{OV8858_8BIT, 0x350c, 0x00},
	{OV8858_8BIT, 0x350d, 0x00},
	{OV8858_8BIT, 0x3600, 0x78},
	/* Next 2 values As Per OV recomm. Only for OV8858 */
	{OV8858_8BIT, 0x3601, 0x0a},
	{OV8858_8BIT, 0x3602, 0x9c},
	{OV8858_8BIT, 0x3604, 0x38},
	{OV8858_8BIT, 0x3620, 0x64},
	{OV8858_8BIT, 0x3621, 0xb5},
	{OV8858_8BIT, 0x3622, 0x03},
	{OV8858_8BIT, 0x3625, 0x64},
	{OV8858_8BIT, 0x3630, 0x55},
	{OV8858_8BIT, 0x3631, 0xd2},
	{OV8858_8BIT, 0x3632, 0x00},
	{OV8858_8BIT, 0x3633, 0x34},
	{OV8858_8BIT, 0x3634, 0x03},
	{OV8858_8BIT, 0x3660, 0x80},
	{OV8858_8BIT, 0x3662, 0x10},
	{OV8858_8BIT, 0x3665, 0x00},
	{OV8858_8BIT, 0x3666, 0x00},
	{OV8858_8BIT, 0x3667, 0x00},
	{OV8858_8BIT, 0x366a, 0x80},
	{OV8858_8BIT, 0x366c, 0x00},
	{OV8858_8BIT, 0x366d, 0x00},
	{OV8858_8BIT, 0x366e, 0x00},
	{OV8858_8BIT, 0x366f, 0x20},
	{OV8858_8BIT, 0x3680, 0xe0},
	{OV8858_8BIT, 0x3681, 0x00},
	{OV8858_8BIT, 0x3701, 0x14},
	{OV8858_8BIT, 0x3702, 0xbf},
	{OV8858_8BIT, 0x3703, 0x8c},
	{OV8858_8BIT, 0x3704, 0x78},
	{OV8858_8BIT, 0x3705, 0x02},
	{OV8858_8BIT, 0x3708, 0xe4},
	{OV8858_8BIT, 0x3709, 0x03},
	{OV8858_8BIT, 0x370a, 0x00},
	{OV8858_8BIT, 0x370b, 0x20},
	{OV8858_8BIT, 0x370c, 0x0c},
	{OV8858_8BIT, 0x370d, 0x11},
	{OV8858_8BIT, 0x370e, 0x00},
	{OV8858_8BIT, 0x370f, 0x00},
	{OV8858_8BIT, 0x3710, 0x00},
	{OV8858_8BIT, 0x371c, 0x01},
	{OV8858_8BIT, 0x371f, 0x0c},
	{OV8858_8BIT, 0x3721, 0x00},
	{OV8858_8BIT, 0x3724, 0x10},
	{OV8858_8BIT, 0x3726, 0x00},
	{OV8858_8BIT, 0x372a, 0x01},
	{OV8858_8BIT, 0x3730, 0x18},
	{OV8858_8BIT, 0x3738, 0x22},
	{OV8858_8BIT, 0x3739, 0x08},
	{OV8858_8BIT, 0x373a, 0x51},
	{OV8858_8BIT, 0x373b, 0x02},
	{OV8858_8BIT, 0x373c, 0x20},
	{OV8858_8BIT, 0x373f, 0x02},
	{OV8858_8BIT, 0x3740, 0x42},
	{OV8858_8BIT, 0x3741, 0x02},
	{OV8858_8BIT, 0x3742, 0x18},
	{OV8858_8BIT, 0x3743, 0x01},
	{OV8858_8BIT, 0x3744, 0x02},
	{OV8858_8BIT, 0x3747, 0x10},
	{OV8858_8BIT, 0x374c, 0x04},
	{OV8858_8BIT, 0x3751, 0xf0},
	{OV8858_8BIT, 0x3752, 0x00},
	{OV8858_8BIT, 0x3753, 0x00},
	{OV8858_8BIT, 0x3754, 0xc0},
	{OV8858_8BIT, 0x3755, 0x00},
	{OV8858_8BIT, 0x3756, 0x1a},
	{OV8858_8BIT, 0x3758, 0x00},
	{OV8858_8BIT, 0x3759, 0x0f},
	{OV8858_8BIT, 0x375c, 0x04},
	{OV8858_8BIT, 0x3767, 0x01},
	{OV8858_8BIT, 0x376b, 0x44},
	{OV8858_8BIT, 0x3774, 0x10},
	{OV8858_8BIT, 0x3776, 0x00},
	{OV8858_8BIT, 0x377f, 0x08},
	{OV8858_8BIT, 0x3780, 0x22},
	{OV8858_8BIT, 0x3781, 0x0c},
	{OV8858_8BIT, 0x3784, 0x2c},
	{OV8858_8BIT, 0x3785, 0x1e},
	{OV8858_8BIT, 0x378f, 0xf5},
	{OV8858_8BIT, 0x3791, 0xb0},
	{OV8858_8BIT, 0x3795, 0x00},
	{OV8858_8BIT, 0x3796, 0x64},
	{OV8858_8BIT, 0x3797, 0x11},
	{OV8858_8BIT, 0x3798, 0x30},
	{OV8858_8BIT, 0x3799, 0x41},
	{OV8858_8BIT, 0x379a, 0x07},
	{OV8858_8BIT, 0x379b, 0xb0},
	{OV8858_8BIT, 0x379c, 0x0c},
	{OV8858_8BIT, 0x37c0, 0x00},
	{OV8858_8BIT, 0x37c1, 0x00},
	{OV8858_8BIT, 0x37c2, 0x00},
	{OV8858_8BIT, 0x37c3, 0x00},
	{OV8858_8BIT, 0x37c4, 0x00},
	{OV8858_8BIT, 0x37c5, 0x00},
	{OV8858_8BIT, 0x37c6, 0xa0},
	{OV8858_8BIT, 0x37c7, 0x00},
	{OV8858_8BIT, 0x37c8, 0x00},
	{OV8858_8BIT, 0x37c9, 0x00},
	{OV8858_8BIT, 0x37ca, 0x00},
	{OV8858_8BIT, 0x37cb, 0x00},
	{OV8858_8BIT, 0x37cc, 0x00},
	{OV8858_8BIT, 0x37cd, 0x00},
	{OV8858_8BIT, 0x37ce, 0x01},
	{OV8858_8BIT, 0x37cf, 0x00},
	{OV8858_8BIT, 0x37d1, 0x01},
	{OV8858_8BIT, 0x37de, 0x00},
	{OV8858_8BIT, 0x37df, 0x00},
	{OV8858_8BIT, 0x3820, 0x10},
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_8BIT, 0x3823, 0x00},
	{OV8858_8BIT, 0x3824, 0x00},
	{OV8858_8BIT, 0x3825, 0x00},
	{OV8858_8BIT, 0x3826, 0x00},
	{OV8858_8BIT, 0x3827, 0x00},
	{OV8858_8BIT, 0x382a, 0x04},
	{OV8858_8BIT, 0x3a04, 0x09},
	{OV8858_8BIT, 0x3a05, 0xa9},
	{OV8858_8BIT, 0x3a06, 0x00},
	{OV8858_8BIT, 0x3a07, 0xf8},
	{OV8858_8BIT, 0x3a18, 0x00},
	{OV8858_8BIT, 0x3a19, 0x00},
	{OV8858_8BIT, 0x3b00, 0x00},
	{OV8858_8BIT, 0x3b01, 0x00},
	{OV8858_8BIT, 0x3b02, 0x00},
	{OV8858_8BIT, 0x3b03, 0x00},
	{OV8858_8BIT, 0x3b04, 0x00},
	{OV8858_8BIT, 0x3b05, 0x00},
	{OV8858_8BIT, 0x3d00, 0x00},
	{OV8858_8BIT, 0x3d01, 0x00},
	{OV8858_8BIT, 0x3d02, 0x00},
	{OV8858_8BIT, 0x3d03, 0x00},
	{OV8858_8BIT, 0x3d04, 0x00},
	{OV8858_8BIT, 0x3d05, 0x00},
	{OV8858_8BIT, 0x3d06, 0x00},
	{OV8858_8BIT, 0x3d07, 0x00},
	{OV8858_8BIT, 0x3d08, 0x00},
	{OV8858_8BIT, 0x3d09, 0x00},
	{OV8858_8BIT, 0x3d0a, 0x00},
	{OV8858_8BIT, 0x3d0b, 0x00},
	{OV8858_8BIT, 0x3d0c, 0x00},
	{OV8858_8BIT, 0x3d0d, 0x00},
	{OV8858_8BIT, 0x3d0e, 0x00},
	{OV8858_8BIT, 0x3d0f, 0x00},
	{OV8858_8BIT, 0x3d80, 0x00},
	{OV8858_8BIT, 0x3d81, 0x00},
	{OV8858_8BIT, 0x3d84, 0x00},
	{OV8858_8BIT, 0x3e07, 0x20},
	{OV8858_8BIT, 0x4000, 0x18},
	{OV8858_8BIT, 0x4001, 0x04},
	{OV8858_8BIT, 0x4002, 0x45},
	{OV8858_8BIT, 0x4004, 0x02},
	{OV8858_8BIT, 0x4005, 0x18},
	{OV8858_8BIT, 0x4006, 0x16},
	{OV8858_8BIT, 0x4008, 0x20},
	{OV8858_8BIT, 0x4009, 0x10},
	{OV8858_8BIT, 0x400c, 0x00},
	{OV8858_8BIT, 0x400d, 0x00},
	{OV8858_8BIT, 0x4058, 0x00},
	{OV8858_8BIT, 0x4101, 0x12},
	{OV8858_8BIT, 0x4104, 0x5b},
	{OV8858_8BIT, 0x4303, 0x00},
	{OV8858_8BIT, 0x4304, 0x08},
	{OV8858_8BIT, 0x4307, 0x30},
	{OV8858_8BIT, 0x4315, 0x00},
	{OV8858_8BIT, 0x4511, 0x05},
	{OV8858_8BIT, 0x4512, 0x01}, /* Binning option = Average */
	{OV8858_8BIT, 0x4750, 0x00},
	{OV8858_8BIT, 0x4751, 0x00},
	{OV8858_8BIT, 0x4752, 0x00},
	{OV8858_8BIT, 0x4753, 0x00},
	{OV8858_8BIT, 0x4805, 0x01},
	{OV8858_8BIT, 0x4806, 0x00},
	{OV8858_8BIT, 0x481f, 0x36},
	{OV8858_8BIT, 0x4831, 0x6c},
	{OV8858_8BIT, 0x4837, 0x0c}, /* MIPI global timing */
	{OV8858_8BIT, 0x4a00, 0xaa},
	{OV8858_8BIT, 0x4a03, 0x01},
	{OV8858_8BIT, 0x4a05, 0x08},
	{OV8858_8BIT, 0x4a0a, 0x88},
	{OV8858_8BIT, 0x5000, 0x06},
	{OV8858_8BIT, 0x5001, 0x01},
	{OV8858_8BIT, 0x5002, 0x80},
	{OV8858_8BIT, 0x5003, 0x20},
	{OV8858_8BIT, 0x5013, 0x00},
	{OV8858_8BIT, 0x5046, 0x4a},
	{OV8858_8BIT, 0x5780, 0x1c},
	{OV8858_8BIT, 0x5786, 0x20},
	{OV8858_8BIT, 0x5787, 0x10},
	{OV8858_8BIT, 0x5788, 0x18},
	{OV8858_8BIT, 0x578a, 0x04},
	{OV8858_8BIT, 0x578b, 0x02},
	{OV8858_8BIT, 0x578c, 0x02},
	{OV8858_8BIT, 0x578e, 0x06},
	{OV8858_8BIT, 0x578f, 0x02},
	{OV8858_8BIT, 0x5790, 0x02},
	{OV8858_8BIT, 0x5791, 0xff},
	{OV8858_8BIT, 0x5a08, 0x02},
	{OV8858_8BIT, 0x5e00, 0x00},
	{OV8858_8BIT, 0x5e10, 0x0c},
#endif

/*****************************STILL********************************/

#if 0
static const struct ov8858_reg ov8858_cont_cap_720P[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x0c},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x40},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xe3},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x75},
	{OV8858_8BIT, 0x3808, 0x05}, /* Output size 1296x736 */
	{OV8858_8BIT, 0x3809, 0x10},
	{OV8858_8BIT, 0x380a, 0x02},
	{OV8858_8BIT, 0x380b, 0xe0},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Binning on */
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_1080P_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x0c},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x40},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xe3},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x75},
	{OV8858_8BIT, 0x3808, 0x07}, /* Output size 1936x1104 */
	{OV8858_8BIT, 0x3809, 0x90},
	{OV8858_8BIT, 0x380a, 0x04},
	{OV8858_8BIT, 0x380b, 0x50},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_cont_cap_qvga[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x01}, /* O/p 336x256 Bin+skip+scale */
	{OV8858_8BIT, 0x3809, 0x50},
	{OV8858_8BIT, 0x380a, 0x01},
	{OV8858_8BIT, 0x380b, 0x00},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x71},
	{OV8858_8BIT, 0x3815, 0x71},
	{OV8858_8BIT, 0x3820, 0x11}, /* Binning+skipping on */
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_VGA_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x02}, /* Ouput Size 656x496 */
	{OV8858_8BIT, 0x3809, 0x90},
	{OV8858_8BIT, 0x380a, 0x01},
	{OV8858_8BIT, 0x380b, 0xf0},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Binning on */
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_1M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x04}, /* Ouput Size 1040x784 1229x922 */
	{OV8858_8BIT, 0x3809, 0x10},
	{OV8858_8BIT, 0x380a, 0x03},
	{OV8858_8BIT, 0x380b, 0x10},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_2M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x06}, /* Ouput Size 1640x1232 */
	{OV8858_8BIT, 0x3809, 0x68},
	{OV8858_8BIT, 0x380a, 0x04},
	{OV8858_8BIT, 0x380b, 0xd0},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_3M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x08}, /* Ouput Size 2064x1552 */
	{OV8858_8BIT, 0x3809, 0x10},
	{OV8858_8BIT, 0x380a, 0x06},
	{OV8858_8BIT, 0x380b, 0x10},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_5M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x0a}, /* Ouput Size 2576x1936 */
	{OV8858_8BIT, 0x3809, 0x10},
	{OV8858_8BIT, 0x380a, 0x07},
	{OV8858_8BIT, 0x380b, 0x90},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_6M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x36},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x79}, /* Read Array: 3291 x 2169 */
	{OV8858_8BIT, 0x3808, 0x0c}, /* Output size 3280x1852 */
	{OV8858_8BIT, 0x3809, 0xd0},
	{OV8858_8BIT, 0x380a, 0x07},
	{OV8858_8BIT, 0x380b, 0x3c},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_8M_STILL[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x04},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x04},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xdb},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xab},
	{OV8858_8BIT, 0x3808, 0x0c}, /* Output size 3280x2464 */
	{OV8858_8BIT, 0x3809, 0xd0},
	{OV8858_8BIT, 0x380a, 0x09},
	{OV8858_8BIT, 0x380b, 0xa0},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10}, /* Binning off */
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};
#endif

#define OMNIVISION_SETTINGS 1

static const struct ov8858_reg ov8858_8M[] = {
#if OMNIVISION_SETTINGS
	{OV8858_8BIT, 0x3800, 0x00}, /* h_crop_start high */
	{OV8858_8BIT, 0x3801, 0x0C}, /* h_crop_start low */
	{OV8858_8BIT, 0x3802, 0x00}, /* v_crop_start high */
	{OV8858_8BIT, 0x3803, 0x0C}, /* v_crop_start low */
	{OV8858_8BIT, 0x3804, 0x0C}, /* h_crop_end high */
	{OV8858_8BIT, 0x3805, 0xD3}, /* h_crop_end low */
	{OV8858_8BIT, 0x3806, 0x09}, /* v_crop_end high */
	{OV8858_8BIT, 0x3807, 0xA3}, /* v_crop_end low */	
	{OV8858_8BIT, 0x3808, 0x0C}, /* h_output_size high */
	{OV8858_8BIT, 0x3809, 0xD0}, /* h_output_size low */
	{OV8858_8BIT, 0x380A, 0x09}, /* v_output_size high */
	{OV8858_8BIT, 0x380B, 0xa0}, /* v_output_size low */
	{OV8858_8BIT, 0x3810, 0x00}, /* h_win offset high */
	{OV8858_8BIT, 0x3811, 0x04}, /* h_win offset low */
	{OV8858_8BIT, 0x3812, 0x00}, /* v_win offset high */
	{OV8858_8BIT, 0x3813, 0x02}, /* v_win offset low */
#else // Settings from OV8830
	{OV8858_8BIT, 0x3800, 0x00}, /* h_crop_start high */
	{OV8858_8BIT, 0x3801, 0x04}, /* h_crop_start low */
	{OV8858_8BIT, 0x3802, 0x00}, /* v_crop_start high */
	{OV8858_8BIT, 0x3803, 0x04}, /* v_crop_start low */
	{OV8858_8BIT, 0x3804, 0x0C}, /* h_crop_end high */
	{OV8858_8BIT, 0x3805, 0xDB}, /* h_crop_end low */
	{OV8858_8BIT, 0x3806, 0x09}, /* v_crop_end high */
	{OV8858_8BIT, 0x3807, 0xAB}, /* v_crop_end low */
	{OV8858_8BIT, 0x3808, 0x0C}, /* h_output_size high */
	{OV8858_8BIT, 0x3809, 0xD0}, /* h_output_size low */
	{OV8858_8BIT, 0x380A, 0x09}, /* v_output_size high */
	{OV8858_8BIT, 0x380B, 0xA0}, /* v_output_size low */
	{OV8858_8BIT, 0x380C, 0x07}, /* horizontal timing size high */
	{OV8858_8BIT, 0x380D, 0x4C}, /* horizontal timing size low */
	{OV8858_8BIT, 0x380E, 0x0A}, /* vertical timing size high */
	{OV8858_8BIT, 0x380F, 0x74}, /* vertical timing size low */
	{OV8858_8BIT, 0x3810, 0x00}, /* h_win offset high */
	{OV8858_8BIT, 0x3811, 0x04}, /* h_win offset low */
	{OV8858_8BIT, 0x3812, 0x00}, /* v_win offset high */
	{OV8858_8BIT, 0x3813, 0x04}, /* v_win offset low */
	{OV8858_8BIT, 0x3814, 0x01}, /* h_odd_inc */
	{OV8858_8BIT, 0x3815, 0x01}, /* h_even_inc */
	{OV8858_8BIT, 0x3820, 0x00}, /* format1 */
	{OV8858_8BIT, 0x3821, 0x46}, /* format2 */
	{OV8858_8BIT, 0x382A, 0x01}, /* v_odd_inc */
	{OV8858_8BIT, 0x382B, 0x01}, /* v_even_inc */
#endif
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_6M[] = {
#if OMNIVISION_SETTINGS
	{OV8858_8BIT, 0x3800, 0x00}, /* h_crop_start high */
	{OV8858_8BIT, 0x3801, 0x0C}, /* h_crop_start low */
	{OV8858_8BIT, 0x3802, 0x01}, /* v_crop_start high */
	{OV8858_8BIT, 0x3803, 0x3E}, /* v_crop_start low */
	{OV8858_8BIT, 0x3804, 0x0C}, /* h_crop_end high */
	{OV8858_8BIT, 0x3805, 0xD3}, /* h_crop_end low */
	{OV8858_8BIT, 0x3806, 0x08}, /* v_crop_end high */
	{OV8858_8BIT, 0x3807, 0x71}, /* v_crop_end low */
	{OV8858_8BIT, 0x3808, 0x0C}, /* h_output_size high */
	{OV8858_8BIT, 0x3809, 0xD0}, /* h_output_size low */
	{OV8858_8BIT, 0x380A, 0x07}, /* v_output_size high */
	{OV8858_8BIT, 0x380B, 0x3C}, /* v_output_size low */
	{OV8858_8BIT, 0x3810, 0x00}, /* h_win offset high */
	{OV8858_8BIT, 0x3811, 0x04}, /* h_win offset low */
	{OV8858_8BIT, 0x3812, 0x00}, /* v_win offset high */
	{OV8858_8BIT, 0x3813, 0x02}, /* v_win offset low */
#else // Settings from OV8830
	{OV8858_8BIT, 0x3800, 0x00}, /* h_crop_start high */
	{OV8858_8BIT, 0x3801, 0x04}, /* h_crop_start low */
	{OV8858_8BIT, 0x3802, 0x01}, /* v_crop_start high */
	{OV8858_8BIT, 0x3803, 0x36}, /* v_crop_start low */
	{OV8858_8BIT, 0x3804, 0x0C}, /* h_crop_end high */
	{OV8858_8BIT, 0x3805, 0xDB}, /* h_crop_end low */
	{OV8858_8BIT, 0x3806, 0x08}, /* v_crop_end high */
	{OV8858_8BIT, 0x3807, 0x79}, /* v_crop_end low */
	{OV8858_8BIT, 0x3808, 0x0C}, /* h_output_size high */
	{OV8858_8BIT, 0x3809, 0xD0}, /* h_output_size low */
	{OV8858_8BIT, 0x380A, 0x07}, /* v_output_size high */
	{OV8858_8BIT, 0x380B, 0x3C}, /* v_output_size low */
	{OV8858_8BIT, 0x380C, 0x07}, /* horizontal timing size high */
	{OV8858_8BIT, 0x380D, 0x4C}, /* horizontal timing size low */
	{OV8858_8BIT, 0x380E, 0x0A}, /* vertical timing size high */
	{OV8858_8BIT, 0x380F, 0x74}, /* vertical timing size low */
	{OV8858_8BIT, 0x3810, 0x00}, /* h_win offset high */
	{OV8858_8BIT, 0x3811, 0x04}, /* h_win offset low */
	{OV8858_8BIT, 0x3812, 0x00}, /* v_win offset high */
	{OV8858_8BIT, 0x3813, 0x04}, /* v_win offset low */
	{OV8858_8BIT, 0x3814, 0x01}, /* h_odd_inc */
	{OV8858_8BIT, 0x3815, 0x01}, /* h_even_inc */
	{OV8858_8BIT, 0x3820, 0x00}, /* format1 */
	{OV8858_8BIT, 0x3821, 0x46}, /* format2 */
	{OV8858_8BIT, 0x382A, 0x01}, /* v_odd_inc */
	{OV8858_8BIT, 0x382B, 0x01}, /* v_even_inc */
#endif
	{OV8858_TOK_TERM, 0, 0}
};

#if 0
/*****************************OV8858 PREVIEW********************************/

static struct ov8858_reg const ov8858_PREVIEW_848x616[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x08},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x08},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd7},
	{OV8858_8BIT, 0x3806, 0x09}, /* 8, 3287, 8, 2471 Binning*/
	{OV8858_8BIT, 0x3807, 0xa7}, /* Actual Size 3280x2464 */
	{OV8858_8BIT, 0x3808, 0x03},
	{OV8858_8BIT, 0x3809, 0x50},
	{OV8858_8BIT, 0x380a, 0x02},
	{OV8858_8BIT, 0x380b, 0x68}, /* O/p 848x616 Binning+Scaling */
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Vertical Binning 0n */
	{OV8858_8BIT, 0x3821, 0x0f}, /* Horizontal Binning 0n */
	{OV8858_TOK_TERM, 0, 0}
};

static struct ov8858_reg const ov8858_PREVIEW_WIDE_PREVIEW[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x0c},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x40},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd3},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x73}, /* 3268x1840 */
	{OV8858_8BIT, 0x3808, 0x05},
	{OV8858_8BIT, 0x3809, 0x00},
	{OV8858_8BIT, 0x380a, 0x02},
	{OV8858_8BIT, 0x380b, 0xd0}, /* 1280X720*/
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Binning on */
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static struct ov8858_reg const ov8858_PREVIEW_1632x1224[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x08},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x08},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd7},
	{OV8858_8BIT, 0x3806, 0x09},
	{OV8858_8BIT, 0x3807, 0xa7}, /* Actual Size 3280x2464 */
	{OV8858_8BIT, 0x3808, 0x06},
	{OV8858_8BIT, 0x3809, 0x60},
	{OV8858_8BIT, 0x380a, 0x04},
	{OV8858_8BIT, 0x380b, 0xc8}, /* Output size: 1632x1224 */
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Vertical Binning 0n */
	{OV8858_8BIT, 0x3821, 0x0f}, /* Horizontal Binning 0n */
	{OV8858_TOK_TERM, 0, 0}
};

/***************** OV8858 VIDEO ***************************************/

static const struct ov8858_reg ov8858_QCIF_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x08},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x08},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd7},
	{OV8858_8BIT, 0x3806, 0x09}, /* 8, 3287, 8, 2471 Binning on*/
	{OV8858_8BIT, 0x3807, 0xa7}, /* Actual Size 3280x2464 */
	{OV8858_8BIT, 0x3808, 0x00}, /* O/p Binning + Scaling 216x176 */
	{OV8858_8BIT, 0x3809, 0xd8},
	{OV8858_8BIT, 0x380a, 0x00},
	{OV8858_8BIT, 0x380b, 0xb0},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11},
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_QVGA_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x08},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x08},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd7},
	{OV8858_8BIT, 0x3806, 0x09}, /* 8, 3287, 8, 2471 Binning on*/
	{OV8858_8BIT, 0x3807, 0xa7}, /* Actual Size 3280x2464 */
	{OV8858_8BIT, 0x3808, 0x01}, /* 408x308 Binning+Scaling */
	{OV8858_8BIT, 0x3809, 0x98},
	{OV8858_8BIT, 0x380a, 0x01},
	{OV8858_8BIT, 0x380b, 0x34},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11},
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_VGA_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x08},
	{OV8858_8BIT, 0x3802, 0x00},
	{OV8858_8BIT, 0x3803, 0x08},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd7},
	{OV8858_8BIT, 0x3806, 0x09}, /* 8, 3287, 8, 2471 Binning on*/
	{OV8858_8BIT, 0x3807, 0xa7}, /* Actual Size 3280x2464 */
	{OV8858_8BIT, 0x3808, 0x03}, /* 820x616 Binning + Scaling */
	{OV8858_8BIT, 0x3809, 0x34},
	{OV8858_8BIT, 0x380a, 0x02},
	{OV8858_8BIT, 0x380b, 0x68},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11},
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static struct ov8858_reg const ov8858_480p_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x01},
	{OV8858_8BIT, 0x3801, 0x09},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x40},
	{OV8858_8BIT, 0x3804, 0x0b},
	{OV8858_8BIT, 0x3805, 0xd6},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x73}, /* TODO! 2766 x 1844 */
	{OV8858_8BIT, 0x3808, 0x03}, /* 936x602 Binning + Scaling */
	{OV8858_8BIT, 0x3809, 0xa8},
	{OV8858_8BIT, 0x380a, 0x02},
	{OV8858_8BIT, 0x380b, 0x5a},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11}, /* Binning on */
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static struct ov8858_reg const ov8858_720p_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x00},
	{OV8858_8BIT, 0x3801, 0x0c},
	{OV8858_8BIT, 0x3802, 0x01},
	{OV8858_8BIT, 0x3803, 0x40},
	{OV8858_8BIT, 0x3804, 0x0c},
	{OV8858_8BIT, 0x3805, 0xd3},
	{OV8858_8BIT, 0x3806, 0x08},
	{OV8858_8BIT, 0x3807, 0x73},
	{OV8858_8BIT, 0x3808, 0x06}, /* O/p 1568*880 Bin+Scale */
	{OV8858_8BIT, 0x3809, 0x20},
	{OV8858_8BIT, 0x380a, 0x03},
	{OV8858_8BIT, 0x380b, 0x70},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x31},
	{OV8858_8BIT, 0x3815, 0x31},
	{OV8858_8BIT, 0x3820, 0x11},
	{OV8858_8BIT, 0x3821, 0x0f},
	{OV8858_TOK_TERM, 0, 0}
};

static const struct ov8858_reg ov8858_1080p_strong_dvs[] = {
	{OV8858_8BIT, 0x3800, 0x01},
	{OV8858_8BIT, 0x3801, 0xd8},
	{OV8858_8BIT, 0x3802, 0x02},
	{OV8858_8BIT, 0x3803, 0x36},
	{OV8858_8BIT, 0x3804, 0x0a},
	{OV8858_8BIT, 0x3805, 0xff},
	{OV8858_8BIT, 0x3806, 0x07},
	{OV8858_8BIT, 0x3807, 0x65}, /* 2344 x 1328 Crop */
	{OV8858_8BIT, 0x3808, 0x09}, /* 2336x1320 DVS O/p */
	{OV8858_8BIT, 0x3809, 0x20},
	{OV8858_8BIT, 0x380a, 0x05},
	{OV8858_8BIT, 0x380b, 0x28},
	{OV8858_8BIT, 0x3810, 0x00},
	{OV8858_8BIT, 0x3811, 0x04},
	{OV8858_8BIT, 0x3812, 0x00},
	{OV8858_8BIT, 0x3813, 0x04},
	{OV8858_8BIT, 0x3814, 0x11},
	{OV8858_8BIT, 0x3815, 0x11},
	{OV8858_8BIT, 0x3820, 0x10},
	{OV8858_8BIT, 0x3821, 0x0e},
	{OV8858_TOK_TERM, 0, 0}
};

#endif

static struct ov8858_resolution ov8858_res_preview[] = {
#if 0
	{
		 .desc = "OV8858_PREVIEW_848x616",
		 .width = 848,
		 .height = 616,
		 .used = 0,
		 .regs = ov8858_PREVIEW_848x616,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 3608,
				.lines_per_frame = 2773,
			},
			{
			}
		}
	},
	{
		 .desc = "ov8858_wide_preview",
		 .width = 1280,
		 .height = 720,
		 .used = 0,
		 .regs = ov8858_PREVIEW_WIDE_PREVIEW,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 3608,
				.lines_per_frame = 2773,
			},
			{
			}
		},
	},
	{
		 .desc = "ov8858_cont_cap_qvga",
		 .width = 336,
		 .height = 256,
		 .used = 0,
		 .regs = ov8858_cont_cap_qvga,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "ov8858_cont_cap_vga",
		 .width = 656,
		 .height = 496,
		 .used = 0,
		 .regs = ov8858_VGA_STILL,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		}
	},
	{
		 .desc = "OV8858_PREVIEW1600x1200",
		 .width = 1632,
		 .height = 1224,
		 .used = 0,
		 .regs = ov8858_PREVIEW_1632x1224,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 3608,
				.lines_per_frame = 2773,
			},
			{
			}
		},
	},
	{
		 .desc = "ov8858_cont_cap_720P",
		 .width = 1296,
		 .height = 736,
		 .used = 0,
		 .regs = ov8858_cont_cap_720P,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "ov8858_cont_cap_1M",
		 .width = 1040,
		 .height = 784,
		 .used = 0,
		 .regs = ov8858_1M_STILL,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 0,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "ov8858_cont_cap_1080P",
		 .width = 1936,
		 .height = 1104,
		 .used = 0,
		 .regs = ov8858_1080P,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 0,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		.desc = "ov8858_cont_cap_3M",
		.width = 2064,
		.height = 1552,
		.used = 0,
		.regs = ov8858_3M_STILL,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 0,
		.fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		.desc = "ov8858_cont_cap_5M",
		.width = 2576,
		.height = 1936,
		.used = 0,
		.regs = ov8858_5M_STILL,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 0,
		.fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
/*	
	{
		 .desc = "ov8858_cont_cap_6M",
		 .width = 3280,
		 .height = 1852,
		 .used = 0,
		 .regs = ov8858_6M,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 0,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	*/
#endif
	{
		.desc = "ov8858_6M_PREVIEW",
		.width = 3280,
		.height = 1852,
		.used = 0,
		.regs = ov8858_6M,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 0,
		.fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 4696,
				.lines_per_frame = 2867,
			},
			{
			}
		},
	},
	{
		.desc = "ov8858_8M_PREVIEW",
		.width = 3280,
		.height = 2464,
		.used = 0,
		.regs = ov8858_8M,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 0,
		.fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 4464,
				.lines_per_frame = 2867,
			},
			{
			}
		},
	},
};

static struct ov8858_resolution ov8858_res_still[] = {
#if 0
	{
		 .desc = "STILL_VGA",
		 .width = 656,
		 .height = 496,
		 .used = 0,
		 .regs = ov8858_VGA_STILL,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 1,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "STILL_1080P",
		 .width = 1936,
		 .height = 1104,
		 .used = 0,
		 .regs = ov8858_1080P,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 1,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "STILL_1M",
		 .width = 1040,
		 .height = 784,
		 .used = 0,
		 .regs = ov8858_1M_STILL,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 1,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		 .desc = "STILL_2M",
		 .width = 1640,
		 .height = 1232,
		 .used = 0,
		 .regs = ov8858_2M_STILL,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 1,
		 .fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		.desc = "STILL_3M",
		.width = 2064,
		.height = 1552,
		.used = 0,
		.regs = ov8858_3M_STILL,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 1,
		.fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
	{
		.desc = "STILL_5M",
		.width = 2576,
		.height = 1936,
		.used = 0,
		.regs = ov8858_5M_STILL,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 1,
		.fps_options =  {
			{
				.fps = 15,
				.pixels_per_line = 4696,
				.lines_per_frame = 2724,
			},
			{
			}
		},
	},
#endif
	{
		 .desc = "ov8858_6M_STILL",
		 .width = 3280,
		 .height = 1852,
		 .used = 0,
		 .regs = ov8858_6M,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 1,
		 .fps_options =  {
			{
				.fps = 30,
				.pixels_per_line = 4464,
				.lines_per_frame = 2867,
			},
			{
			}
		},
	},
	{
		.desc = "ov8858_8M_STILL",
		.width = 3280,
		.height = 2464,
		.used = 0,
		.regs = ov8858_8M,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 1,
		.fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 4464,
				.lines_per_frame = 2867,
			},
			{
			}
		},
	},
};

static struct ov8858_resolution ov8858_res_video[] = {
#if 0
	{
		 .desc = "QCIF_strong_dvs",
		 .width = 216,
		 .height = 176,
		 .used = 0,
		 .regs = ov8858_QCIF_strong_dvs,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4128,
				 .lines_per_frame = 1550,
			},
			{
			}
		},
	},
	{
		 .desc = "QVGA_strong_dvs",
		 .width = 408,
		 .height = 308,
		 .used = 0,
		 .regs = ov8858_QVGA_strong_dvs,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4128,
				 .lines_per_frame = 1550,
			},
			{
			}
		},
	},
	{
		 .desc = "VGA_strong_dvs",
		 .width = 820,
		 .height = 616,
		 .used = 0,
		 .regs = ov8858_VGA_strong_dvs,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4128,
				 .lines_per_frame = 1550,
			},
			{
			}
		},
	},
	{
		.desc = "480p_strong_dvs",
		.width = 936,
		.height = 602,
		.regs = ov8858_480p_strong_dvs,
		.bin_factor_x = 1,
		.bin_factor_y = 1,
		.skip_frames = 0,
		.fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4128,
				 .lines_per_frame = 1550,
			},
			{
			}
		},
	},
	{
		 .desc = "720p_strong_dvs",
		 .width = 1568,
		 .height = 880,
		 .used = 0,
		 .regs = ov8858_720p_strong_dvs,
		 .bin_factor_x = 1,
		 .bin_factor_y = 1,
		 .skip_frames = 0,
		 .fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4128,
				 .lines_per_frame = 1550,
			},
			{
			}
		},
	},
	{
		 .desc = "MODE1920x1080",
		 .width = 2336,
		 .height = 1320,
		 .used = 0,
		 .regs = ov8858_1080p_strong_dvs,
		 .bin_factor_x = 0,
		 .bin_factor_y = 0,
		 .skip_frames = 0,
		 .fps_options = {
			{
				 .fps = 30,
				 .pixels_per_line = 4100,
				 .lines_per_frame = 1561,
			},
			{
			}
		},
	},
#endif
	{
		.desc = "ov8858_8M_VIDEO",
		.width = 3280,
		.height = 2464,
		.used = 0,
		.regs = ov8858_8M,
		.bin_factor_x = 0,
		.bin_factor_y = 0,
		.skip_frames = 1,
		.fps_options = {
			{
				.fps = 30,
				.pixels_per_line = 4464,
				.lines_per_frame = 2867,
			},
			{
			}
		},
	},
};

#endif /* __OV8858_H__ */
