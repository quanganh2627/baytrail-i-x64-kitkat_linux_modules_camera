/*
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

#ifndef M10MO_REG_H
#define M10MO_REG_H
#include <linux/atomisp_platform.h>
#include <linux/atomisp.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/types.h>
#include <linux/videodev2.h>
#include <linux/v4l2-mediabus.h>
#include <media/media-entity.h>
#include <media/v4l2-chip-ident.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include <media/v4l2-subdev.h>

#define M10MO_NAME 			"m10mo"
#define M10MO_ADDR   			0x1f
#define M10MO_BYTE_READ			0x01
#define M10MO_BYTE_WRITE		0x02
#define M10MO_I2C_RETRY			5
#define M10MO_MIPI_FREQ			(963000000/2)
#define M10MO_INIT_TIMEOUT		500

#define M10MO_MIN_EV -3
#define M10MO_MAX_EV  3

struct m10mo_version {
	int customer;
	int project;
	int firmware;
	int hardware;
	int parameter;
	int awb;
};

struct m10mo_device {
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_mbus_framefmt format;
	struct camera_sensor_platform_data *platform_data;
	struct mutex input_lock; /* serialize sensor's ioctl */
	int res_type;
	int power;
	u8 fps;
	u8 mode;
	bool streaming;
	int fmt_idx;
	unsigned int irq;	/* irq issued by ISP */
	wait_queue_head_t irq_waitq;
	unsigned int int_factor;
	unsigned int bad_fw:1;
	unsigned int isp_ready:1;
	unsigned int initialized;
	struct m10mo_version ver;
	struct v4l2_ctrl_handler ctrl_handler;
	struct v4l2_ctrl *run_mode;
	struct v4l2_ctrl *link_freq;
	unsigned int num_lanes;
};

#define to_m10mo_sensor(x) container_of(x, struct m10mo_device, sd)

/* Below contents are based on the M10MO_categoryParameter-a1.xls */

/* Category register */
#define CATEGORY_SYSTEM		0x00
#define CATEGORY_PARAM		0x01	/* Monitor & Still Parameter A */
#define CATEGORY_MONITOR	0x02  /* Monitor & Still Parameter B */
#define CATEGORY_AE		0x03
#define CATEGORY_WB		0x06
#define CATEGORY_EXIF		0x07  /* Exif Information */
#define CATEGORY_LENS		0x0a	/* AF Control */
#define CATEGORY_CAPTURE_PARAM	0x0b	/* Still Picture parameter */
#define CATEGORY_CAPTURE_CTRL	0x0c  /* Still picture control */
#define CATEGORY_FLASHROM	0x0f	/* FlashROM-Writer Mode only */

/* Category 0_SYSTEM mode */
#define SYSTEM_CUSTOMER_CODE	0x00
#define SYSTEM_PROJECT_CODE	0x01
#define SYSTEM_VER_FIRMWARE	0x02
#define SYSTEM_VER_HARDWARE	0x04
#define SYSTEM_VER_PARAMETER	0x06
#define SYSTEM_VER_AWB		0x08

#define SYSTEM_SYSMODE			0x0b
/* SYSTEM mode status */
#define SYSTEM_STATUS			0x0c

/* interrupt enable register */
#define SYSTEM_INT_ENABLE		0x10
#define REG_INT_EN_MODE			(1 << 0)
#define REG_INT_AF			(1 << 1)
#define REG_INT_EN_ZOOM			(1 << 2)
#define REG_INT_EN_CAPTURE		(1 << 3)
#define REG_INT_EN_FRAMESYNC		(1 << 4)
#define REG_INT_EN_FD			(1 << 5)
#define REG_INT_EN_SOUND		(1 << 7)
#define REG_REG_INT_MASK		0x0f

/* Interrupt factor (pending) register */
#define SYSTEM_INT_FACTOR	0x1c
#define REG_INT_STATUS_MODE	(1 << 0)
#define REG_INT_STATUS_ZOOM	(1 << 2)
#define REG_INT_STATUS_CAPTURE	(1 << 3)
#define REG_INT_STATUS_FRAMESYNC (1 << 4)
#define REG_INT_STATUS_FD	(1 << 5)
#define REG_INT_STATUS_SOUND	(1 << 7)

/* category 1_PARAMETER mode */
#define PARAM_MON_SIZE			0x01
#define PARAM_MON_FPS			0x02
#define REG_FPS_30			0x02
#define PARAM_OUTPUT_IF_SEL		0x00
#define REG_OUTPUT_INTERFACE_MIPI	0x02
#define PARAM_MIPI_OUT_LANE_NUM		0x3e
#define REG_OUTPUT_MIPI_4LANE		0x04

/* Category 2_MONITOR mode */

#define MONITOR_ZOOM		0x01
#define MONITOR_CFIXR		0x0a
#define MONITOR_CFIXB		0x09
#define MONITOR_COLOR_EFFECT	0x0b
#define MONITOR_ZSL_MODE_STATUS	0x5f
#define REG_NORMAL_MONITOR	0x00
#define REG_ZSL_MONITOR 	0x01


/* Category 3_Auto Exposure */

#define AE_LOCK			0x00
#define REG_AE_UNLOCK		0x00
#define REG_AE_LOCK		0x01
#define AE_MODE			0x01
#define REG_AE_OFF		0x00
#define AE_TARGET		0x02
#define AE_SPEED		0x03
#define AE_FLICKER		0x06
#define AE_FLICKER_AUTO		0x07
#define AE_EV_BIAS		0x09
#define AE_AUTO_BRACKET_EV1	0x20
#define AE_AUTO_BRACKET_EV2	0x21



/* Category 6_White Balance */

#define AWB_LOCK		0x00
#define REG_AWB_OFF		0x00
#define REG_AWB_ON		0x01
#define AWB_ADJUST_MODE 	0x01
#define AWB_MODE		0x02
#define REG_AWB_AUTO		0x01
#define AWB_MANUAL		0x03
#define REG_AWB_INCANDESCENT	0x01
#define REG_AWB_FLUORESCENT_1	0x02
#define REG_AWB_FLUORESCENT_2	0x03
#define REG_AWB_DAYLIGHT	0x04
#define REG_AWB_CLOUDY		0x05
#define REG_AWB_SHADE		0x06
#define REG_AWB_HORIZON		0x07
#define REG_AWB_LEDLIGHT	0x09
#define AWB_SPEED		0x04
#define AWB_RANGE		0x05

/* Category 7_EXIF */
#define EXIF_INFO_EXPTIME_NU	0x00
#define EXIF_INFO_EXPTIME_DE	0x04
#define EXIF_INFO_TV_NU		0x08
#define EXIF_INFO_TV_DE		0x0c
#define EXIF_INFO_AV_NU		0x10
#define EXIF_INFO_AV_DE		0x14
#define EXIF_INFO_BV_NU		0x18
#define EXIF_INFO_BV_DE		0x1c
#define EXIF_INFO_EBV_NU	0x20
#define EXIF_INFO_EBV_DE	0x24
#define EXIF_INFO_ISO		0x28
#define EXIF_INFO_FLASH		0x2a
#define EXIF_INFO_SDR		0x2c
#define EXIF_INFO_QVAL		0x2e


/* Category A_Lens Parameter */
#define AF_MODE			0x01
#define REG_AF_NORMAL		0x01
#define REG_AF_MACRO		0x03
#define REG_AF_POWEROFF		0x07

#define AF_START		0x02
#define REG_AF_STOP		0x00
#define REG_AF_EXE_AUTO		0x01
#define REG_AF_EXE_CAF		0x02

#define AF_RESULT		0x03
#define REG_AF_FAIL		0x02
#define REG_AF_SUCCESS		0x01
#define REG_AF_IDLE		0x03
#define REG_AF_BUSY		0x04

/* Category B_CAPTURE Parameter */
#define CAPP_YUVOUT_MAIN	0x00
#define REG_YUV422		0x00
#define REG_BAYER10		0x07
#define REG_BAYER8		0x08
#define REG_JPEG		0x01

#define CAPP_MAIN_IMAGE_SIZE	0x01
#define CAPP_JPEG_SIZE_MAX	0x0f
#define CAPP_JPEG_RATIO		0x17
#define CAPP_JPEG_DUAL_RATIO	0x18

/* Category C_CAPTURE Control */
#define CAPC_MODE		0x00
#define REG_CAP_NONE		0x00
#define REG_CAP_ANTI_SHAKE	0x02
#define CAPC_SEL_FRAME_MAIN	0x06
#define CAPC_TRANSFER_START	0x09
#define REG_CAP_START_MAIN	0x01

/* Category F_Flash */

/* Starts internal ARM core, 1st command to be sent to ISP */
#define FLASH_CAM_START			0x12

/* Internal modes of M10MO */
#define M10MO_SYSTEM_INIT_MODE		0x0
#define M10MO_PARAM_SETTING_MODE	0x1
#define M10MO_MONITOR_MODE		0x2
#define M10MO_SINGLE_CAPTURE_MODE	0x3

#endif	/* M10MO_H */



