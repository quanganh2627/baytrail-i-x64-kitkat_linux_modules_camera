/*
 * Support for ov2685 Camera Sensor.
 *
 * Copyright (c) 2012 Intel Corporation. All Rights Reserved.
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

#ifndef __OV2685_H__
#define __OV2685_H__

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/videodev2.h>
#include <linux/spinlock.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-device.h>
#include <media/v4l2-chip-ident.h>
#include <linux/v4l2-mediabus.h>
#include <media/media-entity.h>
#include <linux/atomisp_platform.h>
#include <linux/atomisp.h>

#define OV2685_NAME	"ov2685"
#define V4L2_IDENT_OV2685 1111
#define	LAST_REG_SETING	{0xffff, 0xff}

/* #defines for register writes and register array processing */
#define MISENSOR_8BIT		1
#define MISENSOR_16BIT		2
#define MISENSOR_32BIT		4

#define MISENSOR_TOK_TERM	0xf000	/* terminating token for reg list */
#define MISENSOR_TOK_DELAY	0xfe00	/* delay token for reg list */
#define MISENSOR_TOK_FWLOAD	0xfd00	/* token indicating load FW */
#define MISENSOR_TOK_POLL	0xfc00	/* token indicating poll instruction */

#define I2C_RETRY_COUNT		5
#define MSG_LEN_OFFSET		2

/*register */
#define OV2685_REG_GAIN_0	0x350a
#define OV2685_REG_GAIN_1	0x350b
#define OV2685_REG_EXPOSURE_0	0x3500
#define OV2685_REG_EXPOSURE_1	0x3501
#define OV2685_REG_EXPOSURE_2	0x3502
#define OV2685_REG_EXPOSURE_AUTO	0x3503
#define OV2685_REG_SMIA	0x0100
#define OV2685_REG_PID	0x300a
#define OV2685_REG_SYS_RESET	0x3000
#define OV2685_REG_FW_START	0x8000

/*value */
#define OV2685_FRAME_START	0x01
#define OV2685_FRAME_STOP	0x00
#define OV2685_AWB_GAIN_AUTO	0
#define OV2685_AWB_GAIN_MANUAL	1

#define MIN_SYSCLK		10
#define MIN_VTS			8
#define MIN_HTS			8
#define MIN_SHUTTER		0
#define MIN_GAIN		0

/* OV2685_DEVICE_ID */
#define OV2685_MOD_ID		0x2685

#define OV2685_RES_5M_SIZE_H		2560
#define OV2685_RES_5M_SIZE_V		1920
#define OV2685_RES_D5M_SIZE_H		2496
#define OV2685_RES_D5M_SIZE_V		1664
#define OV2685_RES_D3M_SIZE_H		2112
#define OV2685_RES_D3M_SIZE_V		1408
#define OV2685_RES_3M_SIZE_H		2048
#define OV2685_RES_3M_SIZE_V		1536
#define OV2685_RES_2M_SIZE_H		1600
#define OV2685_RES_2M_SIZE_V		1200
#define OV2685_RES_1088P_SIZE_H		1920
#define OV2685_RES_1088P_SIZE_V		1088
#define OV2685_RES_1080P_SIZE_H		1920
#define OV2685_RES_1080P_SIZE_V		1080
#define OV2685_RES_720P_SIZE_H		1280
#define OV2685_RES_720P_SIZE_V		720
#define OV2685_RES_480P_SIZE_H		720
#define OV2685_RES_480P_SIZE_V		480
#define OV2685_RES_VGA_SIZE_H		640
#define OV2685_RES_VGA_SIZE_V		480
#define OV2685_RES_360P_SIZE_H		640
#define OV2685_RES_360P_SIZE_V		360
#define OV2685_RES_320P_SIZE_H		480
#define OV2685_RES_320P_SIZE_V		320
#define OV2685_RES_DVGA_SIZE_H		416
#define OV2685_RES_DVGA_SIZE_V		312
#define OV2685_RES_QVGA_SIZE_H		320
#define OV2685_RES_QVGA_SIZE_V		240

/*
 * struct misensor_reg - MI sensor  register format
 * @length: length of the register
 * @reg: 16-bit offset to register
 * @val: 8/16/32-bit register value
 * Define a structure for sensor register initialization values
 */
struct misensor_reg {
	u16 length;
	u16 reg;
	u32 val;	/* value or for read/mod/write */
};

struct regval_list {
	u16 reg_num;
	u8 value;
};

struct ov2685_device {
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_mbus_framefmt format;
	struct mutex input_lock;
	struct firmware *firmware;

	struct camera_sensor_platform_data *platform_data;
	int run_mode;
	int focus_mode;
	int night_mode;
	bool focus_mode_change;
	int color_effect;
	bool streaming;
	bool preview_ag_ae;
	u16 sensor_id;
	u8 sensor_revision;
	unsigned int ae_high;
	unsigned int ae_low;
	unsigned int preview_shutter;
	unsigned int preview_gain16;
	unsigned int average;
	unsigned int preview_sysclk;
	unsigned int preview_hts;
	unsigned int preview_vts;
	unsigned int fmt_idx;
};

struct ov2685_priv_data {
	u32 port;
	u32 num_of_lane;
	u32 input_format;
	u32 raw_bayer_order;
};

struct ov2685_format_struct {
	u8 *desc;
	u32 pixelformat;
	struct regval_list *regs;
};

struct ov2685_res_struct {
	u8 *desc;
	int res;
	int width;
	int height;
	int fps;
	int skip_frames;
	int lanes;
	bool used;
	struct regval_list *regs;
};

#define OV2685_MAX_WRITE_BUF_SIZE	32
struct ov2685_write_buffer {
	u16 addr;
	u8 data[OV2685_MAX_WRITE_BUF_SIZE];
};

struct ov2685_write_ctrl {
	int index;
	struct ov2685_write_buffer buffer;
};

struct ov2685_control {
	struct v4l2_queryctrl qc;
	int (*query)(struct v4l2_subdev *sd, s32 *value);
	int (*tweak)(struct v4l2_subdev *sd, int value);
};

/* Supported resolutions */
enum {
	OV2685_RES_720P,
	OV2685_RES_2M,
};

static struct ov2685_res_struct ov2685_res[] = {
	{
	.desc	= "720P",
	.res	= OV2685_RES_720P,
	.width	= 1280,
	.height	= 720,
	.fps	= 30,
	.used	= 0,
	.regs	= NULL,
	.skip_frames = 1,
	.lanes = 1,
	},
	{
	.desc	= "2M",
	.res	= OV2685_RES_2M,
	.width	= 1600,
	.height	= 1200,
	.fps	= 30,
	.used	= 0,
	.regs	= NULL,
	.skip_frames = 0,
	.lanes = 2,
	},
};
#define N_RES (ARRAY_SIZE(ov2685_res))

static const struct i2c_device_id ov2685_id[] = {
	{"ov2685", 0},
	{}
};

static struct misensor_reg const ov2685_2M_init[] = {
	/*2lanes, 30fps*/
	{MISENSOR_8BIT, 0x0103 , 0x01},
	{MISENSOR_8BIT, 0x3002 , 0x00},
	{MISENSOR_8BIT, 0x3016 , 0x1c},
	{MISENSOR_8BIT, 0x3018 , 0x84},
	{MISENSOR_8BIT, 0x301d , 0xf0},
	{MISENSOR_8BIT, 0x3020 , 0x00},
	{MISENSOR_8BIT, 0x3082 , 0x37},/*mclk = 19.2Mhz*/
	{MISENSOR_8BIT, 0x3083 , 0x03},
	{MISENSOR_8BIT, 0x3084 , 0x07},
	{MISENSOR_8BIT, 0x3085 , 0x03},
	{MISENSOR_8BIT, 0x3086 , 0x00},
	{MISENSOR_8BIT, 0x3087 , 0x00},
	{MISENSOR_8BIT, 0x3501 , 0x4e},
	{MISENSOR_8BIT, 0x3502 , 0xe0},
	{MISENSOR_8BIT, 0x3503 , 0x03},
	{MISENSOR_8BIT, 0x350b , 0x36},
	{MISENSOR_8BIT, 0x3600 , 0xb4},
	{MISENSOR_8BIT, 0x3603 , 0x35},
	{MISENSOR_8BIT, 0x3604 , 0x24},
	{MISENSOR_8BIT, 0x3605 , 0x00},
	{MISENSOR_8BIT, 0x3620 , 0x24},
	{MISENSOR_8BIT, 0x3621 , 0x34},
	{MISENSOR_8BIT, 0x3622 , 0x03},
	{MISENSOR_8BIT, 0x3628 , 0x10},
	{MISENSOR_8BIT, 0x3705 , 0x3c},
	{MISENSOR_8BIT, 0x370a , 0x21},
	{MISENSOR_8BIT, 0x370c , 0x50},
	{MISENSOR_8BIT, 0x370d , 0xc0},
	{MISENSOR_8BIT, 0x3717 , 0x58},
	{MISENSOR_8BIT, 0x3718 , 0x80},
	{MISENSOR_8BIT, 0x3720 , 0x00},
	{MISENSOR_8BIT, 0x3721 , 0x09},
	{MISENSOR_8BIT, 0x3722 , 0x06},
	{MISENSOR_8BIT, 0x3723 , 0x59},
	{MISENSOR_8BIT, 0x3738 , 0x99},
	{MISENSOR_8BIT, 0x3781 , 0x80},
	{MISENSOR_8BIT, 0x3784 , 0x0c},
	{MISENSOR_8BIT, 0x3789 , 0x60},
	{MISENSOR_8BIT, 0x3800 , 0x00},
	{MISENSOR_8BIT, 0x3801 , 0x00},
	{MISENSOR_8BIT, 0x3802 , 0x00},
	{MISENSOR_8BIT, 0x3803 , 0x00},
	{MISENSOR_8BIT, 0x3804 , 0x06},
	{MISENSOR_8BIT, 0x3805 , 0x4f},
	{MISENSOR_8BIT, 0x3806 , 0x04},
	{MISENSOR_8BIT, 0x3807 , 0xbf},
	{MISENSOR_8BIT, 0x3808 , 0x06},
	{MISENSOR_8BIT, 0x3809 , 0x40},
	{MISENSOR_8BIT, 0x380a , 0x04},
	{MISENSOR_8BIT, 0x380b , 0xb0},
	{MISENSOR_8BIT, 0x380c , 0x06},
	{MISENSOR_8BIT, 0x380d , 0xa4},
	{MISENSOR_8BIT, 0x380e , 0x05},
	{MISENSOR_8BIT, 0x380f , 0x0e},
	{MISENSOR_8BIT, 0x3810 , 0x00},
	{MISENSOR_8BIT, 0x3811 , 0x08},
	{MISENSOR_8BIT, 0x3812 , 0x00},
	{MISENSOR_8BIT, 0x3813 , 0x08},
	{MISENSOR_8BIT, 0x3814 , 0x11},
	{MISENSOR_8BIT, 0x3815 , 0x11},
	{MISENSOR_8BIT, 0x3819 , 0x04},
	{MISENSOR_8BIT, 0x3820 , 0xc0},
	{MISENSOR_8BIT, 0x3821 , 0x00},
	{MISENSOR_8BIT, 0x3a06 , 0x01},
	{MISENSOR_8BIT, 0x3a07 , 0x84},
	{MISENSOR_8BIT, 0x3a08 , 0x01},
	{MISENSOR_8BIT, 0x3a09 , 0x43},
	{MISENSOR_8BIT, 0x3a0a , 0x24},
	{MISENSOR_8BIT, 0x3a0b , 0x60},
	{MISENSOR_8BIT, 0x3a0c , 0x28},
	{MISENSOR_8BIT, 0x3a0d , 0x60},
	{MISENSOR_8BIT, 0x3a0e , 0x04},
	{MISENSOR_8BIT, 0x3a0f , 0x8c},
	{MISENSOR_8BIT, 0x3a10 , 0x05},
	{MISENSOR_8BIT, 0x3a11 , 0x0c},
	{MISENSOR_8BIT, 0x4000 , 0x81},
	{MISENSOR_8BIT, 0x4001 , 0x40},
	{MISENSOR_8BIT, 0x4008 , 0x02},
	{MISENSOR_8BIT, 0x4009 , 0x09},
	{MISENSOR_8BIT, 0x4300 , 0x32},
	{MISENSOR_8BIT, 0x430e , 0x00},
	{MISENSOR_8BIT, 0x4602 , 0x02},
	{MISENSOR_8BIT, 0x4837 , 0x1e},
	{MISENSOR_8BIT, 0x5000 , 0xff},
	{MISENSOR_8BIT, 0x5001 , 0x05},
	{MISENSOR_8BIT, 0x5002 , 0x32},
	{MISENSOR_8BIT, 0x5003 , 0x04},
	{MISENSOR_8BIT, 0x5004 , 0xff},
	{MISENSOR_8BIT, 0x5005 , 0x12},
	{MISENSOR_8BIT, 0x0100 , 0x01},
	{MISENSOR_8BIT, 0x5180 , 0xf4},
	{MISENSOR_8BIT, 0x5181 , 0x11},
	{MISENSOR_8BIT, 0x5182 , 0x41},
	{MISENSOR_8BIT, 0x5183 , 0x42},
	{MISENSOR_8BIT, 0x5184 , 0x78},
	{MISENSOR_8BIT, 0x5185 , 0x58},
	{MISENSOR_8BIT, 0x5186 , 0xb5},
	{MISENSOR_8BIT, 0x5187 , 0xb2},
	{MISENSOR_8BIT, 0x5188 , 0x08},
	{MISENSOR_8BIT, 0x5189 , 0x0e},
	{MISENSOR_8BIT, 0x518a , 0x0c},
	{MISENSOR_8BIT, 0x518b , 0x4c},
	{MISENSOR_8BIT, 0x518c , 0x38},
	{MISENSOR_8BIT, 0x518d , 0xf8},
	{MISENSOR_8BIT, 0x518e , 0x04},
	{MISENSOR_8BIT, 0x518f , 0x7f},
	{MISENSOR_8BIT, 0x5190 , 0x40},
	{MISENSOR_8BIT, 0x5191 , 0x5f},
	{MISENSOR_8BIT, 0x5192 , 0x40},
	{MISENSOR_8BIT, 0x5193 , 0xff},
	{MISENSOR_8BIT, 0x5194 , 0x40},
	{MISENSOR_8BIT, 0x5195 , 0x07},
	{MISENSOR_8BIT, 0x5196 , 0x04},
	{MISENSOR_8BIT, 0x5197 , 0x04},
	{MISENSOR_8BIT, 0x5198 , 0x00},
	{MISENSOR_8BIT, 0x5199 , 0x05},
	{MISENSOR_8BIT, 0x519a , 0xd2},
	{MISENSOR_8BIT, 0x519b , 0x10},
	{MISENSOR_8BIT, 0x5200 , 0x09},
	{MISENSOR_8BIT, 0x5201 , 0x00},
	{MISENSOR_8BIT, 0x5202 , 0x06},
	{MISENSOR_8BIT, 0x5203 , 0x20},
	{MISENSOR_8BIT, 0x5204 , 0x41},
	{MISENSOR_8BIT, 0x5205 , 0x16},
	{MISENSOR_8BIT, 0x5206 , 0x00},
	{MISENSOR_8BIT, 0x5207 , 0x05},
	{MISENSOR_8BIT, 0x520b , 0x30},
	{MISENSOR_8BIT, 0x520c , 0x75},
	{MISENSOR_8BIT, 0x520d , 0x00},
	{MISENSOR_8BIT, 0x520e , 0x30},
	{MISENSOR_8BIT, 0x520f , 0x75},
	{MISENSOR_8BIT, 0x5210 , 0x00},
	{MISENSOR_8BIT, 0x5280 , 0x14},
	{MISENSOR_8BIT, 0x5281 , 0x02},
	{MISENSOR_8BIT, 0x5282 , 0x02},
	{MISENSOR_8BIT, 0x5283 , 0x04},
	{MISENSOR_8BIT, 0x5284 , 0x06},
	{MISENSOR_8BIT, 0x5285 , 0x08},
	{MISENSOR_8BIT, 0x5286 , 0x0c},
	{MISENSOR_8BIT, 0x5287 , 0x10},
	{MISENSOR_8BIT, 0x5300 , 0xc5},
	{MISENSOR_8BIT, 0x5301 , 0xa0},
	{MISENSOR_8BIT, 0x5302 , 0x06},
	{MISENSOR_8BIT, 0x5303 , 0x0a},
	{MISENSOR_8BIT, 0x5304 , 0x30},
	{MISENSOR_8BIT, 0x5305 , 0x60},
	{MISENSOR_8BIT, 0x5306 , 0x90},
	{MISENSOR_8BIT, 0x5307 , 0xc0},
	{MISENSOR_8BIT, 0x5308 , 0x82},
	{MISENSOR_8BIT, 0x5309 , 0x00},
	{MISENSOR_8BIT, 0x530a , 0x26},
	{MISENSOR_8BIT, 0x530b , 0x02},
	{MISENSOR_8BIT, 0x530c , 0x02},
	{MISENSOR_8BIT, 0x530d , 0x00},
	{MISENSOR_8BIT, 0x530e , 0x0c},
	{MISENSOR_8BIT, 0x530f , 0x14},
	{MISENSOR_8BIT, 0x5310 , 0x1a},
	{MISENSOR_8BIT, 0x5311 , 0x20},
	{MISENSOR_8BIT, 0x5312 , 0x80},
	{MISENSOR_8BIT, 0x5313 , 0x4b},
	{MISENSOR_8BIT, 0x5380 , 0x01},
	{MISENSOR_8BIT, 0x5381 , 0x52},
	{MISENSOR_8BIT, 0x5382 , 0x00},
	{MISENSOR_8BIT, 0x5383 , 0x4a},
	{MISENSOR_8BIT, 0x5384 , 0x00},
	{MISENSOR_8BIT, 0x5385 , 0xb6},
	{MISENSOR_8BIT, 0x5386 , 0x00},
	{MISENSOR_8BIT, 0x5387 , 0x8d},
	{MISENSOR_8BIT, 0x5388 , 0x00},
	{MISENSOR_8BIT, 0x5389 , 0x3a},
	{MISENSOR_8BIT, 0x538a , 0x00},
	{MISENSOR_8BIT, 0x538b , 0xa6},
	{MISENSOR_8BIT, 0x538c , 0x00},
	{MISENSOR_8BIT, 0x5400 , 0x0d},
	{MISENSOR_8BIT, 0x5401 , 0x18},
	{MISENSOR_8BIT, 0x5402 , 0x31},
	{MISENSOR_8BIT, 0x5403 , 0x5a},
	{MISENSOR_8BIT, 0x5404 , 0x65},
	{MISENSOR_8BIT, 0x5405 , 0x6f},
	{MISENSOR_8BIT, 0x5406 , 0x77},
	{MISENSOR_8BIT, 0x5407 , 0x80},
	{MISENSOR_8BIT, 0x5408 , 0x87},
	{MISENSOR_8BIT, 0x5409 , 0x8f},
	{MISENSOR_8BIT, 0x540a , 0xa2},
	{MISENSOR_8BIT, 0x540b , 0xb2},
	{MISENSOR_8BIT, 0x540c , 0xcc},
	{MISENSOR_8BIT, 0x540d , 0xe4},
	{MISENSOR_8BIT, 0x540e , 0xf0},
	{MISENSOR_8BIT, 0x540f , 0xa0},
	{MISENSOR_8BIT, 0x5410 , 0x6e},
	{MISENSOR_8BIT, 0x5411 , 0x06},
	{MISENSOR_8BIT, 0x5480 , 0x19},
	{MISENSOR_8BIT, 0x5481 , 0x00},
	{MISENSOR_8BIT, 0x5482 , 0x09},
	{MISENSOR_8BIT, 0x5483 , 0x12},
	{MISENSOR_8BIT, 0x5484 , 0x04},
	{MISENSOR_8BIT, 0x5485 , 0x06},
	{MISENSOR_8BIT, 0x5486 , 0x08},
	{MISENSOR_8BIT, 0x5487 , 0x0c},
	{MISENSOR_8BIT, 0x5488 , 0x10},
	{MISENSOR_8BIT, 0x5489 , 0x18},
	{MISENSOR_8BIT, 0x5500 , 0x02},
	{MISENSOR_8BIT, 0x5501 , 0x03},
	{MISENSOR_8BIT, 0x5502 , 0x04},
	{MISENSOR_8BIT, 0x5503 , 0x05},
	{MISENSOR_8BIT, 0x5504 , 0x06},
	{MISENSOR_8BIT, 0x5505 , 0x08},
	{MISENSOR_8BIT, 0x5506 , 0x00},
	{MISENSOR_8BIT, 0x5600 , 0x02},
	{MISENSOR_8BIT, 0x5603 , 0x40},
	{MISENSOR_8BIT, 0x5604 , 0x28},
	{MISENSOR_8BIT, 0x5609 , 0x20},
	{MISENSOR_8BIT, 0x560a , 0x60},
	{MISENSOR_8BIT, 0x5800 , 0x03},
	{MISENSOR_8BIT, 0x5801 , 0x24},
	{MISENSOR_8BIT, 0x5802 , 0x02},
	{MISENSOR_8BIT, 0x5803 , 0x40},
	{MISENSOR_8BIT, 0x5804 , 0x34},
	{MISENSOR_8BIT, 0x5805 , 0x05},
	{MISENSOR_8BIT, 0x5806 , 0x12},
	{MISENSOR_8BIT, 0x5807 , 0x05},
	{MISENSOR_8BIT, 0x5808 , 0x03},
	{MISENSOR_8BIT, 0x5809 , 0x3c},
	{MISENSOR_8BIT, 0x580a , 0x02},
	{MISENSOR_8BIT, 0x580b , 0x40},
	{MISENSOR_8BIT, 0x580c , 0x26},
	{MISENSOR_8BIT, 0x580d , 0x05},
	{MISENSOR_8BIT, 0x580e , 0x52},
	{MISENSOR_8BIT, 0x580f , 0x06},
	{MISENSOR_8BIT, 0x5810 , 0x03},
	{MISENSOR_8BIT, 0x5811 , 0x28},
	{MISENSOR_8BIT, 0x5812 , 0x02},
	{MISENSOR_8BIT, 0x5813 , 0x40},
	{MISENSOR_8BIT, 0x5814 , 0x24},
	{MISENSOR_8BIT, 0x5815 , 0x05},
	{MISENSOR_8BIT, 0x5816 , 0x42},
	{MISENSOR_8BIT, 0x5817 , 0x06},
	{MISENSOR_8BIT, 0x5818 , 0x0d},
	{MISENSOR_8BIT, 0x5819 , 0x40},
	{MISENSOR_8BIT, 0x581a , 0x04},
	{MISENSOR_8BIT, 0x581b , 0x0c},
	{MISENSOR_8BIT, 0x3a03 , 0x4c},
	{MISENSOR_8BIT, 0x3a04 , 0x40},
	{MISENSOR_8BIT, 0x3503 , 0x00},
	{MISENSOR_TOK_TERM, 0, 0}
};

static struct misensor_reg const ov2685_720p_init[] = {
	/*1lane 30fps*/
	{MISENSOR_8BIT, 0x0103 , 0x01},
	{MISENSOR_8BIT, 0x3002 , 0x00},
	{MISENSOR_8BIT, 0x3016 , 0x1c},
	{MISENSOR_8BIT, 0x3018 , 0x44},
	{MISENSOR_8BIT, 0x301d , 0xf0},
	{MISENSOR_8BIT, 0x3020 , 0x00},
	{MISENSOR_8BIT, 0x3082 , 0x37},
	{MISENSOR_8BIT, 0x3083 , 0x03},
	{MISENSOR_8BIT, 0x3084 , 0x0f},
	{MISENSOR_8BIT, 0x3085 , 0x03},
	{MISENSOR_8BIT, 0x3086 , 0x00},
	{MISENSOR_8BIT, 0x3087 , 0x00},
	{MISENSOR_8BIT, 0x3501 , 0x2d},
	{MISENSOR_8BIT, 0x3502 , 0x80},
	{MISENSOR_8BIT, 0x3503 , 0x03},
	{MISENSOR_8BIT, 0x350b , 0x36},
	{MISENSOR_8BIT, 0x3600 , 0xb4},
	{MISENSOR_8BIT, 0x3603 , 0x35},
	{MISENSOR_8BIT, 0x3604 , 0x24},
	{MISENSOR_8BIT, 0x3605 , 0x00},
	{MISENSOR_8BIT, 0x3620 , 0x26},
	{MISENSOR_8BIT, 0x3621 , 0x37},
	{MISENSOR_8BIT, 0x3622 , 0x04},
	{MISENSOR_8BIT, 0x3628 , 0x10},
	{MISENSOR_8BIT, 0x3705 , 0x3c},
	{MISENSOR_8BIT, 0x370a , 0x21},
	{MISENSOR_8BIT, 0x370c , 0x50},
	{MISENSOR_8BIT, 0x370d , 0xc0},
	{MISENSOR_8BIT, 0x3717 , 0x58},
	{MISENSOR_8BIT, 0x3718 , 0x88},
	{MISENSOR_8BIT, 0x3720 , 0x00},
	{MISENSOR_8BIT, 0x3721 , 0x00},
	{MISENSOR_8BIT, 0x3722 , 0x00},
	{MISENSOR_8BIT, 0x3723 , 0x00},
	{MISENSOR_8BIT, 0x3738 , 0x00},
	{MISENSOR_8BIT, 0x3781 , 0x80},
	{MISENSOR_8BIT, 0x3789 , 0x60},
	{MISENSOR_8BIT, 0x3800 , 0x00},
	{MISENSOR_8BIT, 0x3801 , 0xa0},
	{MISENSOR_8BIT, 0x3802 , 0x00},
	{MISENSOR_8BIT, 0x3803 , 0xf2},
	{MISENSOR_8BIT, 0x3804 , 0x05},
	{MISENSOR_8BIT, 0x3805 , 0xaf},
	{MISENSOR_8BIT, 0x3806 , 0x03},
	{MISENSOR_8BIT, 0x3807 , 0xcd},
	{MISENSOR_8BIT, 0x3808 , 0x05},
	{MISENSOR_8BIT, 0x3809 , 0x00},
	{MISENSOR_8BIT, 0x380a , 0x02},
	{MISENSOR_8BIT, 0x380b , 0xd0},
	{MISENSOR_8BIT, 0x380c , 0x05},
	{MISENSOR_8BIT, 0x380d , 0xa6},
	{MISENSOR_8BIT, 0x380e , 0x02},
	{MISENSOR_8BIT, 0x380f , 0xf8},
	{MISENSOR_8BIT, 0x3810 , 0x00},
	{MISENSOR_8BIT, 0x3811 , 0x08},
	{MISENSOR_8BIT, 0x3812 , 0x00},
	{MISENSOR_8BIT, 0x3813 , 0x06},
	{MISENSOR_8BIT, 0x3814 , 0x11},
	{MISENSOR_8BIT, 0x3815 , 0x11},
	{MISENSOR_8BIT, 0x3819 , 0x04},
	{MISENSOR_8BIT, 0x3820 , 0xc0},
	{MISENSOR_8BIT, 0x3821 , 0x00},
	{MISENSOR_8BIT, 0x3a06 , 0x00},
	{MISENSOR_8BIT, 0x3a07 , 0xe4},
	{MISENSOR_8BIT, 0x3a08 , 0x00},
	{MISENSOR_8BIT, 0x3a09 , 0xbe},
	{MISENSOR_8BIT, 0x3a0a , 0x15},
	{MISENSOR_8BIT, 0x3a0b , 0x60},
	{MISENSOR_8BIT, 0x3a0c , 0x17},
	{MISENSOR_8BIT, 0x3a0d , 0xc0},
	{MISENSOR_8BIT, 0x3a0e , 0x02},
	{MISENSOR_8BIT, 0x3a0f , 0xac},
	{MISENSOR_8BIT, 0x3a10 , 0x02},
	{MISENSOR_8BIT, 0x3a11 , 0xf8},
	{MISENSOR_8BIT, 0x4000 , 0x81},
	{MISENSOR_8BIT, 0x4001 , 0x40},
	{MISENSOR_8BIT, 0x4008 , 0x02},
	{MISENSOR_8BIT, 0x4009 , 0x09},
	{MISENSOR_8BIT, 0x4300 , 0x32},
	{MISENSOR_8BIT, 0x430e , 0x00},
	{MISENSOR_8BIT, 0x4602 , 0x02},
	{MISENSOR_8BIT, 0x4837 , 0x1e},
	{MISENSOR_8BIT, 0x5000 , 0xff},
	{MISENSOR_8BIT, 0x5001 , 0x05},
	{MISENSOR_8BIT, 0x5002 , 0x32},
	{MISENSOR_8BIT, 0x5003 , 0x04},
	{MISENSOR_8BIT, 0x5004 , 0xff},
	{MISENSOR_8BIT, 0x5005 , 0x12},
	{MISENSOR_8BIT, 0x0100 , 0x01},
	{MISENSOR_8BIT, 0x5180 , 0xf4},
	{MISENSOR_8BIT, 0x5181 , 0x11},
	{MISENSOR_8BIT, 0x5182 , 0x41},
	{MISENSOR_8BIT, 0x5183 , 0x42},
	{MISENSOR_8BIT, 0x5184 , 0x78},
	{MISENSOR_8BIT, 0x5185 , 0x58},
	{MISENSOR_8BIT, 0x5186 , 0xb5},
	{MISENSOR_8BIT, 0x5187 , 0xb2},
	{MISENSOR_8BIT, 0x5188 , 0x08},
	{MISENSOR_8BIT, 0x5189 , 0x0e},
	{MISENSOR_8BIT, 0x518a , 0x0c},
	{MISENSOR_8BIT, 0x518b , 0x4c},
	{MISENSOR_8BIT, 0x518c , 0x38},
	{MISENSOR_8BIT, 0x518d , 0xf8},
	{MISENSOR_8BIT, 0x518e , 0x04},
	{MISENSOR_8BIT, 0x518f , 0x7f},
	{MISENSOR_8BIT, 0x5190 , 0x40},
	{MISENSOR_8BIT, 0x5191 , 0x5f},
	{MISENSOR_8BIT, 0x5192 , 0x40},
	{MISENSOR_8BIT, 0x5193 , 0xff},
	{MISENSOR_8BIT, 0x5194 , 0x40},
	{MISENSOR_8BIT, 0x5195 , 0x07},
	{MISENSOR_8BIT, 0x5196 , 0x04},
	{MISENSOR_8BIT, 0x5197 , 0x04},
	{MISENSOR_8BIT, 0x5198 , 0x00},
	{MISENSOR_8BIT, 0x5199 , 0x05},
	{MISENSOR_8BIT, 0x519a , 0xd2},
	{MISENSOR_8BIT, 0x519b , 0x10},
	{MISENSOR_8BIT, 0x5200 , 0x09},
	{MISENSOR_8BIT, 0x5201 , 0x00},
	{MISENSOR_8BIT, 0x5202 , 0x06},
	{MISENSOR_8BIT, 0x5203 , 0x20},
	{MISENSOR_8BIT, 0x5204 , 0x41},
	{MISENSOR_8BIT, 0x5205 , 0x16},
	{MISENSOR_8BIT, 0x5206 , 0x00},
	{MISENSOR_8BIT, 0x5207 , 0x05},
	{MISENSOR_8BIT, 0x520b , 0x30},
	{MISENSOR_8BIT, 0x520c , 0x75},
	{MISENSOR_8BIT, 0x520d , 0x00},
	{MISENSOR_8BIT, 0x520e , 0x30},
	{MISENSOR_8BIT, 0x520f , 0x75},
	{MISENSOR_8BIT, 0x5210 , 0x00},
	{MISENSOR_8BIT, 0x5280 , 0x14},
	{MISENSOR_8BIT, 0x5281 , 0x02},
	{MISENSOR_8BIT, 0x5282 , 0x02},
	{MISENSOR_8BIT, 0x5283 , 0x04},
	{MISENSOR_8BIT, 0x5284 , 0x06},
	{MISENSOR_8BIT, 0x5285 , 0x08},
	{MISENSOR_8BIT, 0x5286 , 0x0c},
	{MISENSOR_8BIT, 0x5287 , 0x10},
	{MISENSOR_8BIT, 0x5300 , 0xc5},
	{MISENSOR_8BIT, 0x5301 , 0xa0},
	{MISENSOR_8BIT, 0x5302 , 0x06},
	{MISENSOR_8BIT, 0x5303 , 0x0a},
	{MISENSOR_8BIT, 0x5304 , 0x30},
	{MISENSOR_8BIT, 0x5305 , 0x60},
	{MISENSOR_8BIT, 0x5306 , 0x90},
	{MISENSOR_8BIT, 0x5307 , 0xc0},
	{MISENSOR_8BIT, 0x5308 , 0x82},
	{MISENSOR_8BIT, 0x5309 , 0x00},
	{MISENSOR_8BIT, 0x530a , 0x26},
	{MISENSOR_8BIT, 0x530b , 0x02},
	{MISENSOR_8BIT, 0x530c , 0x02},
	{MISENSOR_8BIT, 0x530d , 0x00},
	{MISENSOR_8BIT, 0x530e , 0x0c},
	{MISENSOR_8BIT, 0x530f , 0x14},
	{MISENSOR_8BIT, 0x5310 , 0x1a},
	{MISENSOR_8BIT, 0x5311 , 0x20},
	{MISENSOR_8BIT, 0x5312 , 0x80},
	{MISENSOR_8BIT, 0x5313 , 0x4b},
	{MISENSOR_8BIT, 0x5380 , 0x01},
	{MISENSOR_8BIT, 0x5381 , 0x52},
	{MISENSOR_8BIT, 0x5382 , 0x00},
	{MISENSOR_8BIT, 0x5383 , 0x4a},
	{MISENSOR_8BIT, 0x5384 , 0x00},
	{MISENSOR_8BIT, 0x5385 , 0xb6},
	{MISENSOR_8BIT, 0x5386 , 0x00},
	{MISENSOR_8BIT, 0x5387 , 0x8d},
	{MISENSOR_8BIT, 0x5388 , 0x00},
	{MISENSOR_8BIT, 0x5389 , 0x3a},
	{MISENSOR_8BIT, 0x538a , 0x00},
	{MISENSOR_8BIT, 0x538b , 0xa6},
	{MISENSOR_8BIT, 0x538c , 0x00},
	{MISENSOR_8BIT, 0x5400 , 0x0d},
	{MISENSOR_8BIT, 0x5401 , 0x18},
	{MISENSOR_8BIT, 0x5402 , 0x31},
	{MISENSOR_8BIT, 0x5403 , 0x5a},
	{MISENSOR_8BIT, 0x5404 , 0x65},
	{MISENSOR_8BIT, 0x5405 , 0x6f},
	{MISENSOR_8BIT, 0x5406 , 0x77},
	{MISENSOR_8BIT, 0x5407 , 0x80},
	{MISENSOR_8BIT, 0x5408 , 0x87},
	{MISENSOR_8BIT, 0x5409 , 0x8f},
	{MISENSOR_8BIT, 0x540a , 0xa2},
	{MISENSOR_8BIT, 0x540b , 0xb2},
	{MISENSOR_8BIT, 0x540c , 0xcc},
	{MISENSOR_8BIT, 0x540d , 0xe4},
	{MISENSOR_8BIT, 0x540e , 0xf0},
	{MISENSOR_8BIT, 0x540f , 0xa0},
	{MISENSOR_8BIT, 0x5410 , 0x6e},
	{MISENSOR_8BIT, 0x5411 , 0x06},
	{MISENSOR_8BIT, 0x5480 , 0x19},
	{MISENSOR_8BIT, 0x5481 , 0x00},
	{MISENSOR_8BIT, 0x5482 , 0x09},
	{MISENSOR_8BIT, 0x5483 , 0x12},
	{MISENSOR_8BIT, 0x5484 , 0x04},
	{MISENSOR_8BIT, 0x5485 , 0x06},
	{MISENSOR_8BIT, 0x5486 , 0x08},
	{MISENSOR_8BIT, 0x5487 , 0x0c},
	{MISENSOR_8BIT, 0x5488 , 0x10},
	{MISENSOR_8BIT, 0x5489 , 0x18},
	{MISENSOR_8BIT, 0x5500 , 0x02},
	{MISENSOR_8BIT, 0x5501 , 0x03},
	{MISENSOR_8BIT, 0x5502 , 0x04},
	{MISENSOR_8BIT, 0x5503 , 0x05},
	{MISENSOR_8BIT, 0x5504 , 0x06},
	{MISENSOR_8BIT, 0x5505 , 0x08},
	{MISENSOR_8BIT, 0x5506 , 0x00},
	{MISENSOR_8BIT, 0x5600 , 0x02},
	{MISENSOR_8BIT, 0x5603 , 0x40},
	{MISENSOR_8BIT, 0x5604 , 0x28},
	{MISENSOR_8BIT, 0x5609 , 0x20},
	{MISENSOR_8BIT, 0x560a , 0x60},
	{MISENSOR_8BIT, 0x5800 , 0x03},
	{MISENSOR_8BIT, 0x5801 , 0x24},
	{MISENSOR_8BIT, 0x5802 , 0x02},
	{MISENSOR_8BIT, 0x5803 , 0x40},
	{MISENSOR_8BIT, 0x5804 , 0x34},
	{MISENSOR_8BIT, 0x5805 , 0x05},
	{MISENSOR_8BIT, 0x5806 , 0x12},
	{MISENSOR_8BIT, 0x5807 , 0x05},
	{MISENSOR_8BIT, 0x5808 , 0x03},
	{MISENSOR_8BIT, 0x5809 , 0x3c},
	{MISENSOR_8BIT, 0x580a , 0x02},
	{MISENSOR_8BIT, 0x580b , 0x40},
	{MISENSOR_8BIT, 0x580c , 0x26},
	{MISENSOR_8BIT, 0x580d , 0x05},
	{MISENSOR_8BIT, 0x580e , 0x52},
	{MISENSOR_8BIT, 0x580f , 0x06},
	{MISENSOR_8BIT, 0x5810 , 0x03},
	{MISENSOR_8BIT, 0x5811 , 0x28},
	{MISENSOR_8BIT, 0x5812 , 0x02},
	{MISENSOR_8BIT, 0x5813 , 0x40},
	{MISENSOR_8BIT, 0x5814 , 0x24},
	{MISENSOR_8BIT, 0x5815 , 0x05},
	{MISENSOR_8BIT, 0x5816 , 0x42},
	{MISENSOR_8BIT, 0x5817 , 0x06},
	{MISENSOR_8BIT, 0x5818 , 0x0d},
	{MISENSOR_8BIT, 0x5819 , 0x40},
	{MISENSOR_8BIT, 0x581a , 0x04},
	{MISENSOR_8BIT, 0x581b , 0x0c},
	{MISENSOR_8BIT, 0x3a03 , 0x4c},
	{MISENSOR_8BIT, 0x3a04 , 0x40},
	{MISENSOR_8BIT, 0x3503 , 0x00},
	{MISENSOR_TOK_TERM, 0, 0}
};

/* camera vga 30fps, yuv, 1lanes */
static struct misensor_reg const ov2685_vga_init[] = {
	{MISENSOR_8BIT, 0x0103 , 0x01},
	{MISENSOR_8BIT, 0x3002 , 0x00},
	{MISENSOR_8BIT, 0x3016 , 0x1c},
	{MISENSOR_8BIT, 0x3018 , 0x44},
	{MISENSOR_8BIT, 0x301d , 0xf0},
	{MISENSOR_8BIT, 0x3020 , 0x00},
	{MISENSOR_8BIT, 0x3082 , 0x37},
	{MISENSOR_8BIT, 0x3083 , 0x03},
	{MISENSOR_8BIT, 0x3084 , 0x0f},
	{MISENSOR_8BIT, 0x3085 , 0x03},
	{MISENSOR_8BIT, 0x3086 , 0x00},
	{MISENSOR_8BIT, 0x3087 , 0x00},
	{MISENSOR_8BIT, 0x3501 , 0x26},
	{MISENSOR_8BIT, 0x3502 , 0x40},
	{MISENSOR_8BIT, 0x3503 , 0x03},
	{MISENSOR_8BIT, 0x350b , 0x36},
	{MISENSOR_8BIT, 0x3600 , 0xb4},
	{MISENSOR_8BIT, 0x3603 , 0x35},
	{MISENSOR_8BIT, 0x3604 , 0x24},
	{MISENSOR_8BIT, 0x3605 , 0x00},
	{MISENSOR_8BIT, 0x3620 , 0x26},
	{MISENSOR_8BIT, 0x3621 , 0x37},
	{MISENSOR_8BIT, 0x3622 , 0x04},
	{MISENSOR_8BIT, 0x3628 , 0x10},
	{MISENSOR_8BIT, 0x3705 , 0x3c},
	{MISENSOR_8BIT, 0x370a , 0x23},
	{MISENSOR_8BIT, 0x370c , 0x50},
	{MISENSOR_8BIT, 0x370d , 0xc0},
	{MISENSOR_8BIT, 0x3717 , 0x58},
	{MISENSOR_8BIT, 0x3718 , 0x88},
	{MISENSOR_8BIT, 0x3720 , 0x00},
	{MISENSOR_8BIT, 0x3721 , 0x00},
	{MISENSOR_8BIT, 0x3722 , 0x00},
	{MISENSOR_8BIT, 0x3723 , 0x00},
	{MISENSOR_8BIT, 0x3738 , 0x00},
	{MISENSOR_8BIT, 0x3781 , 0x80},
	{MISENSOR_8BIT, 0x3789 , 0x60},
	{MISENSOR_8BIT, 0x3800 , 0x00},
	{MISENSOR_8BIT, 0x3801 , 0xa0},
	{MISENSOR_8BIT, 0x3802 , 0x00},
	{MISENSOR_8BIT, 0x3803 , 0x78},
	{MISENSOR_8BIT, 0x3804 , 0x05},
	{MISENSOR_8BIT, 0x3805 , 0xaf},
	{MISENSOR_8BIT, 0x3806 , 0x04},
	{MISENSOR_8BIT, 0x3807 , 0x47},
	{MISENSOR_8BIT, 0x3808 , 0x02},
	{MISENSOR_8BIT, 0x3809 , 0x80},
	{MISENSOR_8BIT, 0x380a , 0x01},
	{MISENSOR_8BIT, 0x380b , 0xe0},
	{MISENSOR_8BIT, 0x380c , 0x06},
	{MISENSOR_8BIT, 0x380d , 0xac},
	{MISENSOR_8BIT, 0x380e , 0x02},
	{MISENSOR_8BIT, 0x380f , 0x84},
	{MISENSOR_8BIT, 0x3810 , 0x00},
	{MISENSOR_8BIT, 0x3811 , 0x04},
	{MISENSOR_8BIT, 0x3812 , 0x00},
	{MISENSOR_8BIT, 0x3813 , 0x04},
	{MISENSOR_8BIT, 0x3814 , 0x31},
	{MISENSOR_8BIT, 0x3815 , 0x31},
	{MISENSOR_8BIT, 0x3819 , 0x04},
	{MISENSOR_8BIT, 0x3820 , 0xc2},
	{MISENSOR_8BIT, 0x3821 , 0x01},
	{MISENSOR_8BIT, 0x3a06 , 0x00},
	{MISENSOR_8BIT, 0x3a07 , 0xc1},
	{MISENSOR_8BIT, 0x3a08 , 0x00},
	{MISENSOR_8BIT, 0x3a09 , 0xa1},
	{MISENSOR_8BIT, 0x3a0a , 0x12},
	{MISENSOR_8BIT, 0x3a0b , 0x18},
	{MISENSOR_8BIT, 0x3a0c , 0x14},
	{MISENSOR_8BIT, 0x3a0d , 0x20},
	{MISENSOR_8BIT, 0x3a0e , 0x02},
	{MISENSOR_8BIT, 0x3a0f , 0x43},
	{MISENSOR_8BIT, 0x3a10 , 0x02},
	{MISENSOR_8BIT, 0x3a11 , 0x84},
	{MISENSOR_8BIT, 0x4000 , 0x81},
	{MISENSOR_8BIT, 0x4001 , 0x40},
	{MISENSOR_8BIT, 0x4008 , 0x00},
	{MISENSOR_8BIT, 0x4009 , 0x03},
	{MISENSOR_8BIT, 0x4300 , 0x32},
	{MISENSOR_8BIT, 0x430e , 0x00},
	{MISENSOR_8BIT, 0x4602 , 0x02},
	{MISENSOR_8BIT, 0x4837 , 0x1e},
	{MISENSOR_8BIT, 0x5000 , 0xff},
	{MISENSOR_8BIT, 0x5001 , 0x05},
	{MISENSOR_8BIT, 0x5002 , 0x32},
	{MISENSOR_8BIT, 0x5003 , 0x04},
	{MISENSOR_8BIT, 0x5004 , 0xff},
	{MISENSOR_8BIT, 0x5005 , 0x12},
	{MISENSOR_8BIT, 0x0100 , 0x01},
	{MISENSOR_8BIT, 0x0101 , 0x01},
	{MISENSOR_8BIT, 0x1000 , 0x01},
	{MISENSOR_8BIT, 0x0129 , 0x10},
	{MISENSOR_8BIT, 0x5180 , 0xf4},
	{MISENSOR_8BIT, 0x5181 , 0x11},
	{MISENSOR_8BIT, 0x5182 , 0x41},
	{MISENSOR_8BIT, 0x5183 , 0x42},
	{MISENSOR_8BIT, 0x5184 , 0x78},
	{MISENSOR_8BIT, 0x5185 , 0x58},
	{MISENSOR_8BIT, 0x5186 , 0xb5},
	{MISENSOR_8BIT, 0x5187 , 0xb2},
	{MISENSOR_8BIT, 0x5188 , 0x08},
	{MISENSOR_8BIT, 0x5189 , 0x0e},
	{MISENSOR_8BIT, 0x518a , 0x0c},
	{MISENSOR_8BIT, 0x518b , 0x4c},
	{MISENSOR_8BIT, 0x518c , 0x38},
	{MISENSOR_8BIT, 0x518d , 0xf8},
	{MISENSOR_8BIT, 0x518e , 0x04},
	{MISENSOR_8BIT, 0x518f , 0x7f},
	{MISENSOR_8BIT, 0x5190 , 0x40},
	{MISENSOR_8BIT, 0x5191 , 0x5f},
	{MISENSOR_8BIT, 0x5192 , 0x40},
	{MISENSOR_8BIT, 0x5193 , 0xff},
	{MISENSOR_8BIT, 0x5194 , 0x40},
	{MISENSOR_8BIT, 0x5195 , 0x07},
	{MISENSOR_8BIT, 0x5196 , 0x04},
	{MISENSOR_8BIT, 0x5197 , 0x04},
	{MISENSOR_8BIT, 0x5198 , 0x00},
	{MISENSOR_8BIT, 0x5199 , 0x05},
	{MISENSOR_8BIT, 0x519a , 0xd2},
	{MISENSOR_8BIT, 0x519b , 0x10},
	{MISENSOR_8BIT, 0x5200 , 0x09},
	{MISENSOR_8BIT, 0x5201 , 0x00},
	{MISENSOR_8BIT, 0x5202 , 0x06},
	{MISENSOR_8BIT, 0x5203 , 0x20},
	{MISENSOR_8BIT, 0x5204 , 0x41},
	{MISENSOR_8BIT, 0x5205 , 0x16},
	{MISENSOR_8BIT, 0x5206 , 0x00},
	{MISENSOR_8BIT, 0x5207 , 0x05},
	{MISENSOR_8BIT, 0x520b , 0x30},
	{MISENSOR_8BIT, 0x520c , 0x75},
	{MISENSOR_8BIT, 0x520d , 0x00},
	{MISENSOR_8BIT, 0x520e , 0x30},
	{MISENSOR_8BIT, 0x520f , 0x75},
	{MISENSOR_8BIT, 0x5210 , 0x00},
	{MISENSOR_8BIT, 0x5280 , 0x14},
	{MISENSOR_8BIT, 0x5281 , 0x02},
	{MISENSOR_8BIT, 0x5282 , 0x02},
	{MISENSOR_8BIT, 0x5283 , 0x04},
	{MISENSOR_8BIT, 0x5284 , 0x06},
	{MISENSOR_8BIT, 0x5285 , 0x08},
	{MISENSOR_8BIT, 0x5286 , 0x0c},
	{MISENSOR_8BIT, 0x5287 , 0x10},
	{MISENSOR_8BIT, 0x5300 , 0xc5},
	{MISENSOR_8BIT, 0x5301 , 0xa0},
	{MISENSOR_8BIT, 0x5302 , 0x06},
	{MISENSOR_8BIT, 0x5303 , 0x0a},
	{MISENSOR_8BIT, 0x5304 , 0x30},
	{MISENSOR_8BIT, 0x5305 , 0x60},
	{MISENSOR_8BIT, 0x5306 , 0x90},
	{MISENSOR_8BIT, 0x5307 , 0xc0},
	{MISENSOR_8BIT, 0x5308 , 0x82},
	{MISENSOR_8BIT, 0x5309 , 0x00},
	{MISENSOR_8BIT, 0x530a , 0x26},
	{MISENSOR_8BIT, 0x530b , 0x02},
	{MISENSOR_8BIT, 0x530c , 0x02},
	{MISENSOR_8BIT, 0x530d , 0x00},
	{MISENSOR_8BIT, 0x530e , 0x0c},
	{MISENSOR_8BIT, 0x530f , 0x14},
	{MISENSOR_8BIT, 0x5310 , 0x1a},
	{MISENSOR_8BIT, 0x5311 , 0x20},
	{MISENSOR_8BIT, 0x5312 , 0x80},
	{MISENSOR_8BIT, 0x5313 , 0x4b},
	{MISENSOR_8BIT, 0x5380 , 0x01},
	{MISENSOR_8BIT, 0x5381 , 0x52},
	{MISENSOR_8BIT, 0x5382 , 0x00},
	{MISENSOR_8BIT, 0x5383 , 0x4a},
	{MISENSOR_8BIT, 0x5384 , 0x00},
	{MISENSOR_8BIT, 0x5385 , 0xb6},
	{MISENSOR_8BIT, 0x5386 , 0x00},
	{MISENSOR_8BIT, 0x5387 , 0x8d},
	{MISENSOR_8BIT, 0x5388 , 0x00},
	{MISENSOR_8BIT, 0x5389 , 0x3a},
	{MISENSOR_8BIT, 0x538a , 0x00},
	{MISENSOR_8BIT, 0x538b , 0xa6},
	{MISENSOR_8BIT, 0x538c , 0x00},
	{MISENSOR_8BIT, 0x5400 , 0x0d},
	{MISENSOR_8BIT, 0x5401 , 0x18},
	{MISENSOR_8BIT, 0x5402 , 0x31},
	{MISENSOR_8BIT, 0x5403 , 0x5a},
	{MISENSOR_8BIT, 0x5404 , 0x65},
	{MISENSOR_8BIT, 0x5405 , 0x6f},
	{MISENSOR_8BIT, 0x5406 , 0x77},
	{MISENSOR_8BIT, 0x5407 , 0x80},
	{MISENSOR_8BIT, 0x5408 , 0x87},
	{MISENSOR_8BIT, 0x5409 , 0x8f},
	{MISENSOR_8BIT, 0x540a , 0xa2},
	{MISENSOR_8BIT, 0x540b , 0xb2},
	{MISENSOR_8BIT, 0x540c , 0xcc},
	{MISENSOR_8BIT, 0x540d , 0xe4},
	{MISENSOR_8BIT, 0x540e , 0xf0},
	{MISENSOR_8BIT, 0x540f , 0xa0},
	{MISENSOR_8BIT, 0x5410 , 0x6e},
	{MISENSOR_8BIT, 0x5411 , 0x06},
	{MISENSOR_8BIT, 0x5480 , 0x19},
	{MISENSOR_8BIT, 0x5481 , 0x00},
	{MISENSOR_8BIT, 0x5482 , 0x09},
	{MISENSOR_8BIT, 0x5483 , 0x12},
	{MISENSOR_8BIT, 0x5484 , 0x04},
	{MISENSOR_8BIT, 0x5485 , 0x06},
	{MISENSOR_8BIT, 0x5486 , 0x08},
	{MISENSOR_8BIT, 0x5487 , 0x0c},
	{MISENSOR_8BIT, 0x5488 , 0x10},
	{MISENSOR_8BIT, 0x5489 , 0x18},
	{MISENSOR_8BIT, 0x5500 , 0x02},
	{MISENSOR_8BIT, 0x5501 , 0x03},
	{MISENSOR_8BIT, 0x5502 , 0x04},
	{MISENSOR_8BIT, 0x5503 , 0x05},
	{MISENSOR_8BIT, 0x5504 , 0x06},
	{MISENSOR_8BIT, 0x5505 , 0x08},
	{MISENSOR_8BIT, 0x5506 , 0x00},
	{MISENSOR_8BIT, 0x5600 , 0x02},
	{MISENSOR_8BIT, 0x5603 , 0x40},
	{MISENSOR_8BIT, 0x5604 , 0x28},
	{MISENSOR_8BIT, 0x5609 , 0x20},
	{MISENSOR_8BIT, 0x560a , 0x60},
	{MISENSOR_8BIT, 0x5800 , 0x03},
	{MISENSOR_8BIT, 0x5801 , 0x24},
	{MISENSOR_8BIT, 0x5802 , 0x02},
	{MISENSOR_8BIT, 0x5803 , 0x40},
	{MISENSOR_8BIT, 0x5804 , 0x34},
	{MISENSOR_8BIT, 0x5805 , 0x05},
	{MISENSOR_8BIT, 0x5806 , 0x12},
	{MISENSOR_8BIT, 0x5807 , 0x05},
	{MISENSOR_8BIT, 0x5808 , 0x03},
	{MISENSOR_8BIT, 0x5809 , 0x3c},
	{MISENSOR_8BIT, 0x580a , 0x02},
	{MISENSOR_8BIT, 0x580b , 0x40},
	{MISENSOR_8BIT, 0x580c , 0x26},
	{MISENSOR_8BIT, 0x580d , 0x05},
	{MISENSOR_8BIT, 0x580e , 0x52},
	{MISENSOR_8BIT, 0x580f , 0x06},
	{MISENSOR_8BIT, 0x5810 , 0x03},
	{MISENSOR_8BIT, 0x5811 , 0x28},
	{MISENSOR_8BIT, 0x5812 , 0x02},
	{MISENSOR_8BIT, 0x5813 , 0x40},
	{MISENSOR_8BIT, 0x5814 , 0x24},
	{MISENSOR_8BIT, 0x5815 , 0x05},
	{MISENSOR_8BIT, 0x5816 , 0x42},
	{MISENSOR_8BIT, 0x5817 , 0x06},
	{MISENSOR_8BIT, 0x5818 , 0x0d},
	{MISENSOR_8BIT, 0x5819 , 0x40},
	{MISENSOR_8BIT, 0x581a , 0x04},
	{MISENSOR_8BIT, 0x581b , 0x0c},
	{MISENSOR_8BIT, 0x3a03 , 0x4c},
	{MISENSOR_8BIT, 0x3a04 , 0x40},
	{MISENSOR_8BIT, 0x3503 , 0x00},
	{MISENSOR_TOK_TERM, 0, 0}
};

static struct misensor_reg const ov2685_common[] = {
	 {MISENSOR_TOK_TERM, 0, 0}
};

static struct misensor_reg const ov2685_iq[] = {
	{MISENSOR_TOK_TERM, 0, 0}
};

#endif
