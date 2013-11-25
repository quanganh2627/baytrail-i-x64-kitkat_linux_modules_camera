/*
 *
 * Copyright (c) 2013 Intel Corporation. All Rights Reserved.
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

#include <linux/atomisp.h>
#include <linux/delay.h>
#include <linux/firmware.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/string.h>
#include <linux/types.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include "ap1302.h"

#define to_ap1302_device(sub_dev) container_of(sub_dev, struct ap1302_device, sd)

/* Static definitions */
static struct regmap_config ap1302_reg16_config = {
	.reg_bits = 16,
	.val_bits = 16,
	.reg_format_endian = REGMAP_ENDIAN_BIG,
	.val_format_endian = REGMAP_ENDIAN_BIG,
};

static struct regmap_config ap1302_reg32_config = {
	.reg_bits = 16,
	.val_bits = 32,
	.reg_format_endian = REGMAP_ENDIAN_BIG,
	.val_format_endian = REGMAP_ENDIAN_BIG,
};

static enum ap1302_contexts ap1302_cntx_mapping[] = {
	CONTEXT_PREVIEW,	/* Invalid atomisp run mode */
	CONTEXT_VIDEO,		/* ATOMISP_RUN_MODE_VIDEO */
	CONTEXT_SNAPSHOT,	/* ATOMISP_RUN_MODE_STILL_CAPTURE */
	CONTEXT_SNAPSHOT,	/* ATOMISP_RUN_MODE_CONTINUOUS_CAPTURE */
	CONTEXT_PREVIEW,	/* ATOMISP_RUN_MODE_PREVIEW */
};

static struct ap1302_res_struct ap1302_preview_res[] = {
	{
		.width = 640,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 720,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 1280,
		.height = 720,
		.fps = 30,
	},
	{
		.width = 1920,
		.height = 1080,
		.fps = 30,
	}
};

static struct ap1302_res_struct ap1302_snapshot_res[] = {
	{
		.width = 640,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 720,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 1280,
		.height = 720,
		.fps = 30,
	},
	{
		.width = 1920,
		.height = 1080,
		.fps = 30,
	}
};

static struct ap1302_res_struct ap1302_video_res[] = {
	{
		.width = 640,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 720,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 1280,
		.height = 720,
		.fps = 30,
	},
	{
		.width = 1920,
		.height = 1080,
		.fps = 30,
	}
};
/* End of static definitions */

static int ap1302_i2c_read_reg(struct v4l2_subdev *sd,
				u16 reg, u16 len, void *val)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	if (len == AP1302_REG16)
		return regmap_read(dev->regmap16, reg, val);
	else if (len == AP1302_REG32)
		return regmap_read(dev->regmap32, reg, val);
	else
		return -EINVAL;
}

static int ap1302_i2c_write_reg(struct v4l2_subdev *sd,
				u16 reg, u16 len, u32 val)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	if (len == AP1302_REG16)
		return regmap_write(dev->regmap16, reg, val);
	else if (len == AP1302_REG32)
		return regmap_write(dev->regmap32, reg, val);
	else
		return -EINVAL;
}

static u16
ap1302_calculate_context_reg_addr(enum ap1302_contexts context, u16 offset)
{
	u16 reg_addr;
	/* The register offset is defined according to preview/video registers.
	   Preview and video context have the same register definition.
	   But snapshot context does not have register S1_SENSOR_MODE.
	   When setting snapshot registers, if the offset exceeds
	   S1_SENSOR_MODE, the actual offset needs to minus 2. */
	if (context == CONTEXT_SNAPSHOT) {
		if (offset == CNTX_S1_SENSOR_MODE)
			return 0;
		if (offset > CNTX_S1_SENSOR_MODE)
			offset -= 2;
	}
	if (context == CONTEXT_PREVIEW)
		reg_addr = REG_SNAPSHOT_BASE + offset;
	else if (context == CONTEXT_VIDEO)
		reg_addr = REG_VIDEO_BASE + offset;
	else
		reg_addr = REG_PREVIEW_BASE + offset;
	return reg_addr;
}

static int ap1302_read_context_reg(struct v4l2_subdev *sd,
		enum ap1302_contexts context, u16 offset, u16 len)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	u16 reg_addr = ap1302_calculate_context_reg_addr(context, offset);
	if (reg_addr == 0)
		return -EINVAL;
	return ap1302_i2c_read_reg(sd, reg_addr, len,
			    ((u8*)&dev->cntx_config[context]) + offset);
}

static int ap1302_write_context_reg(struct v4l2_subdev *sd,
		enum ap1302_contexts context, u16 offset, u16 len)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	u16 reg_addr = ap1302_calculate_context_reg_addr(context, offset);
	if (reg_addr == 0)
		return -EINVAL;
	return ap1302_i2c_write_reg(sd, reg_addr, len,
			*(u32*)(((u8*)&dev->cntx_config[context]) + offset));
}

static int ap1302_request_firmware(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct ap1302_device *dev = to_ap1302_device(sd);
	int ret;
	ret = request_firmware(&dev->fw, "ap1302_fw.bin", &client->dev);
	if (ret)
		dev_err(&client->dev,
			"ap1302_request_firmware failed. ret=%d\n", ret);
	return ret;
}

/* When loading firmware, host writes firmware data from address 0x8000.
   When the address reaches 0x9FFF, the next address should return to 0x8000.
   This function handles this address window and load firmware data to AP1302.
   win_pos indicates the offset within this window. Firmware loading procedure
   may call this function several times. win_pos records the current position
   that has been written to.*/
static int ap1302_write_fw_window(struct v4l2_subdev *sd,
				  u16 *win_pos, const u8 *buf, u32 len)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	int ret;
	u32 pos;
	u32 sub_len;
	for (pos = 0; pos < len; pos += sub_len) {
		if (len - pos < AP1302_FW_WINDOW_SIZE - *win_pos)
			sub_len = len - pos;
		else
			sub_len = AP1302_FW_WINDOW_SIZE - *win_pos;
		ret = regmap_raw_write(dev->regmap16,
					*win_pos + AP1302_FW_WINDOW_OFFSET,
					buf + pos, sub_len);
		if (ret)
			return ret;
		*win_pos += sub_len;
		if (*win_pos >= AP1302_FW_WINDOW_SIZE)
			*win_pos = 0;
	}
	return 0;
}

static int ap1302_load_firmware(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct ap1302_device *dev = to_ap1302_device(sd);
	const struct ap1302_firmware *fw;
	const u8* fw_data;
	u16 reg_val = 0;
	u16 win_pos = 0;
	int ret;

	if (!dev->fw) {
		dev_err(&client->dev, "firmware not requested.\n");
		return -EINVAL;
	}
	fw = (const struct ap1302_firmware*) dev->fw->data;
	if (dev->fw->size != (sizeof(*fw) + fw->total_size)) {
		dev_err(&client->dev, "firmware size does not match.\n");
		return -EINVAL;
	}
	/* The fw binary contains a header of struct ap1302_firmware.
	   Following the header is the bootdata of AP1302.
	   The bootdata pointer can be referenced as &fw[1]. */
	fw_data = (u8*)&fw[1];

	/* Clear crc register. */
	ret = ap1302_i2c_write_reg(sd, REG_SIP_CRC, AP1302_REG16, 0xFFFF);
	if (ret)
		return ret;

	/* Load FW data for PLL init stage. */
	ret = ap1302_write_fw_window(sd, &win_pos, fw_data, fw->pll_init_size);
	if (ret)
		return ret;

	/* Write 2 to bootdata_stage register to apply basic_init_hp
	   settings and enable PLL. */
	ret = ap1302_i2c_write_reg(sd, REG_BOOTDATA_STAGE,
				   AP1302_REG16, 0x0002);
	if (ret)
		return ret;

	/* Wait 1ms for PLL to lock. */
	msleep(1);

	/* Load the rest of bootdata content. */
	ret = ap1302_write_fw_window(sd, &win_pos, fw_data + fw->pll_init_size,
				     fw->total_size - fw->pll_init_size);
	if (ret)
		return ret;

	/* Check crc. */
	ret = ap1302_i2c_read_reg(sd, REG_SIP_CRC, AP1302_REG16, &reg_val);
	if (ret)
		return ret;
	if (reg_val != fw->crc) {
		dev_err(&client->dev,
			"crc does not match. T:0x%04X F:0x%04X\n",
			fw->crc, reg_val);
		return -EAGAIN;
	}

	/* Write 0xFFFF to bootdata_stage register to indicate AP1302 that
	   the whole bootdata content has been loaded. */
	ret = ap1302_i2c_write_reg(sd, REG_BOOTDATA_STAGE,
				   AP1302_REG16, 0xFFFF);
	if (ret)
		return ret;

	return 0;
}

static int __ap1302_s_power(struct v4l2_subdev *sd, int on, int load_fw)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	dev_info(&client->dev, "ap1302_s_power is called.\n");
	ret = dev->platform_data->power_ctrl(sd, on);
	if (ret) {
		dev_err(&client->dev,
			"ap1302_s_power error. on=%d ret=%d\n", on, ret);
		return ret;
	}

	if (!on && !load_fw)
		return 0;
	/* Load firmware after power on. */
	ret = ap1302_load_firmware(sd);
	if (ret)
		dev_err(&client->dev,
			"ap1302_load_firmware failed. ret=%d\n", ret);
	return ret;
}

static int ap1302_s_power(struct v4l2_subdev *sd, int on)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;
	int ret;

	mutex_lock(&dev->input_lock);
	ret = __ap1302_s_power(sd, on, 1);
	if (ret)
		goto failed;

	for (context = 0; context < CONTEXT_NUM; context++) {
		/* Configure mipi lane number */
		ret = ap1302_read_context_reg(sd, context,
			CNTX_HINF_CTRL, AP1302_REG16);
		if (ret)
			goto failed;
		dev->cntx_config[context].hinf_ctrl &= ~CTRL_CNTX_MASK;
		dev->cntx_config[context].hinf_ctrl |=
			(dev->num_lanes << CTRL_CNTX_OFFSET);
		ret = ap1302_write_context_reg(sd, context,
			CNTX_HINF_CTRL, AP1302_REG16);
		if (ret)
			goto failed;
		/* Configure VC id for main streams. */
		dev->cntx_config[context].mipi_ctrl = MIPI_CTRL_IMGTYPE_AUTO;
		dev->cntx_config[context].mipi_ctrl |=
			(context << MIPI_CTRL_IMGVC_OFFSET);
		ret = ap1302_write_context_reg(sd, context,
			CNTX_MIPI_CTRL, AP1302_REG16);
		if (ret)
			goto failed;
	}
failed:
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int ap1302_s_config(struct v4l2_subdev *sd, void *pdata)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct camera_mipi_info *mipi_info;
	u16 reg_val = 0;
	int ret;

	dev_info(&client->dev, "ap1302_s_config is called.\n");
	if (pdata == NULL)
		return -ENODEV;

	dev->platform_data = pdata;

	mutex_lock(&dev->input_lock);

	if (dev->platform_data->platform_init) {
		ret = dev->platform_data->platform_init(client);
		if (ret)
			goto fail_power;
	}

	ret = __ap1302_s_power(sd, 1, 0);
	if (ret)
		goto fail_power;

	/* Detect for AP1302 */
	ret = ap1302_i2c_read_reg(sd, REG_CHIP_VERSION, AP1302_REG16, &reg_val);
	if (ret || (reg_val != AP1302_CHIP_ID)) {
		dev_err(&client->dev,
			"Chip version does no match. ret=%d ver=0x%04x\n",
			ret, reg_val);
		goto fail_config;
	}

	ret = dev->platform_data->csi_cfg(sd, 1);
	if (ret)
		goto fail_config;

	mipi_info = v4l2_get_subdev_hostdata(sd);
	if (!mipi_info)
		goto fail_config;
	dev->num_lanes = mipi_info->num_lanes;

	ret = __ap1302_s_power(sd, 0, 0);
	if (ret)
		goto fail_power;

	mutex_unlock(&dev->input_lock);

	return ret;

fail_config:
	__ap1302_s_power(sd, 0, 0);
fail_power:
	mutex_unlock(&dev->input_lock);
	dev_err(&client->dev, "ap1302_s_config failed\n");
	return ret;
}

static enum ap1302_contexts ap1302_get_context(struct v4l2_subdev *sd)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	return dev->cur_context;
}

static int ap1302_enum_mbus_code(struct v4l2_subdev *sd,
				 struct v4l2_subdev_fh *fh,
				 struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->index)
		return -EINVAL;

	code->code = V4L2_MBUS_FMT_UYVY8_1X16;

	return 0;
}

static int ap1302_match_resolution(struct ap1302_context_res *res,
				   struct v4l2_mbus_framefmt *fmt)
{
	s32 w0, h0, mismatch, distance;
	s32 w1 = fmt->width;
	s32 h1 = fmt->height;
	s32 min_distance = INT_MAX;
	u32 i, idx = -1;

	if (w1 == 0 || h1 == 0)
		return -1;

	for (i = 0; i < res->res_num; i++) {
		w0 = res->res_table[i].width;
		h0 = res->res_table[i].height;
		if (w0 < w1 || h0 < h1)
			continue;
		mismatch = abs(w0 * h1 - w1 * h0) * 8192 / w1 / h0;
		if (mismatch > 8192 * AP1302_MAX_RATIO_MISMATCH / 100)
			continue;
		distance = (w0 *h1 + w1 * h0) * 8192 / w1 / h1;
		if (distance < min_distance) {
			min_distance = distance;
			idx = i;
		}
	}

	return idx;
}

static int ap1302_try_mbus_fmt_locked(struct v4l2_subdev *sd,
			       struct v4l2_mbus_framefmt *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;
	struct ap1302_res_struct *res_table;
	u32 res_num, idx;

	context = ap1302_get_context(sd);
	res_table = dev->cntx_res[context].res_table;
	res_num = dev->cntx_res[context].res_num;

	if ((fmt->width > res_table[res_num - 1].width)
		|| (fmt->height > res_table[res_num - 1].height)) {
		fmt->width  = res_table[res_num - 1].width;
		fmt->height = res_table[res_num - 1].height;
	} else {
		idx = ap1302_match_resolution(&dev->cntx_res[context], fmt);

		if (idx == -1) {
			fmt->width = res_table[res_num - 1].width;
			fmt->height = res_table[res_num - 1].height;
		}
	}

	fmt->code = V4L2_MBUS_FMT_UYVY8_1X16;
	return 0;
}

static int ap1302_try_mbus_fmt(struct v4l2_subdev *sd,
			       struct v4l2_mbus_framefmt *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	int ret;
	mutex_lock(&dev->input_lock);
	ret = ap1302_try_mbus_fmt_locked(sd, fmt);
	mutex_unlock(&dev->input_lock);
	return ret;
}

static int ap1302_get_mbus_fmt(struct v4l2_subdev *sd,
				struct v4l2_mbus_framefmt *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;

	mutex_lock(&dev->input_lock);
	context = ap1302_get_context(sd);
	fmt->code = V4L2_MBUS_FMT_UYVY8_1X16;
	fmt->width = dev->cntx_config[context].width;
	fmt->height = dev->cntx_config[context].height;
	mutex_unlock(&dev->input_lock);
	return 0;
}

static int ap1302_set_mbus_fmt(struct v4l2_subdev *sd,
				struct v4l2_mbus_framefmt *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;
	int ret;

	mutex_lock(&dev->input_lock);
	ret = ap1302_try_mbus_fmt_locked(sd, fmt);
	if (ret)
		goto fail_set_fmt;

	context = ap1302_get_context(sd);
	dev->cntx_config[context].width = fmt->width;
	dev->cntx_config[context].height = fmt->height;
	dev->cntx_config[context].out_fmt = AP1302_FMT_UYVY422;
	ap1302_write_context_reg(sd, context, CNTX_WIDTH, AP1302_REG16);
	ap1302_write_context_reg(sd, context, CNTX_HEIGHT, AP1302_REG16);
	ap1302_write_context_reg(sd, context, CNTX_OUT_FMT, AP1302_REG16);
fail_set_fmt:
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int
ap1302_enum_framesizes(struct v4l2_subdev *sd, struct v4l2_frmsizeenum *fsize)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	unsigned int index = fsize->index;
	enum ap1302_contexts context;
	struct ap1302_res_struct *res_table;

	mutex_lock(&dev->input_lock);
	context = ap1302_get_context(sd);
	if (index >= dev->cntx_res[context].res_num) {
		mutex_unlock(&dev->input_lock);
		return -EINVAL;
	}

	res_table = dev->cntx_res[context].res_table;
	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
	fsize->discrete.width = res_table[index].width;
	fsize->discrete.height = res_table[index].height;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int ap1302_enum_frameintervals(struct v4l2_subdev *sd,
				       struct v4l2_frmivalenum *fival)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;
	struct ap1302_res_struct *res_table;
	unsigned int index = fival->index;
	u32 res_num;
	int i;

	if (index > 0)
		return -EINVAL;
	mutex_lock(&dev->input_lock);
	context = ap1302_get_context(sd);
	res_table = dev->cntx_res[context].res_table;
	res_num = dev->cntx_res[context].res_num;
	/* find out the first equal or bigger size */
	for (i = 0; i < res_num; i++) {
		if ((res_table[i].width >= fival->width) &&
		    (res_table[i].height >= fival->height))
			break;
	}
	if (i == res_num)
		i--;

	fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
	fival->width = res_table[i].width;
	fival->height = res_table[i].height;
	fival->discrete.numerator = 1;
	fival->discrete.denominator = res_table[i].fps;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int ap1302_enum_frame_size(struct v4l2_subdev *sd,
	struct v4l2_subdev_fh *fh,
	struct v4l2_subdev_frame_size_enum *fse)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	enum ap1302_contexts context;
	struct ap1302_res_struct *res_table;
	int index = fse->index;

	mutex_lock(&dev->input_lock);
	context = ap1302_get_context(sd);
	if (index >= dev->cntx_res[context].res_num) {
		mutex_unlock(&dev->input_lock);
		return -EINVAL;
	}

	res_table = dev->cntx_res[context].res_table;
	fse->min_width = res_table[index].width;
	fse->min_height = res_table[index].height;
	fse->max_width = res_table[index].width;
	fse->max_height = res_table[index].height;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static struct v4l2_mbus_framefmt *
__ap1302_get_pad_format(struct ap1302_device *dev,
			struct v4l2_subdev_fh *fh, unsigned int pad,
			enum v4l2_subdev_format_whence which)
{
	if (which == V4L2_SUBDEV_FORMAT_TRY)
		return v4l2_subdev_get_try_format(fh, pad);
	else
		return &dev->format;
}

static int
ap1302_get_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		      struct v4l2_subdev_format *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	struct v4l2_mbus_framefmt *format =
			__ap1302_get_pad_format(dev, fh, fmt->pad, fmt->which);

	mutex_lock(&dev->input_lock);
	fmt->format = *format;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int
ap1302_set_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		      struct v4l2_subdev_format *fmt)
{
	struct ap1302_device *dev = to_ap1302_device(sd);

	mutex_lock(&dev->input_lock);
	if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE)
		dev->format = fmt->format;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int ap1302_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
	*frames = 0;
	return 0;
}

static int ap1302_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct ap1302_device *dev = to_ap1302_device(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	/* AP1302 has the same register command for both stream on and off.
	   To stream on AP1302, write sys stall command to sys_start register.
	   To stream off AP1302, write sys stall command again. */
	ret = ap1302_i2c_write_reg(sd, REG_SYS_START,
				   AP1302_REG16, AP1302_STREAM_SWITCH);
	if (ret)
		dev_err(&client->dev,
			"AP1302 set stream failed. enable=%d\n", enable);
	mutex_unlock(&dev->input_lock);
	return ret;
}

static int ap1302_s_ctrl(struct v4l2_ctrl *ctrl)
{
	struct ap1302_device *dev = container_of(
		ctrl->handler, struct ap1302_device, ctrl_handler);
	enum ap1302_contexts context;
	u16 reg_val = 0;
	int ret;

	switch (ctrl->id) {
	case V4L2_CID_RUN_MODE:
		context = dev->cur_context;
		ret = ap1302_i2c_read_reg(&dev->sd, REG_CTRL,
					  AP1302_REG16, &reg_val);
		if (ret)
			return -ENODEV;

		reg_val &= ~CTRL_CNTX_MASK;
		reg_val |= (ap1302_cntx_mapping[ctrl->val]<<CTRL_CNTX_OFFSET);
		context = ap1302_cntx_mapping[ctrl->val];
		if (context != dev->cur_context) {
			ret = ap1302_i2c_write_reg(&dev->sd,
				REG_CTRL, AP1302_REG16, reg_val);
			if (ret)
				return -ENODEV;
			dev->cur_context = context;
		}
		/* Reset output format. Disable aux stream. */
		dev->cntx_config[context].out_fmt = AP1302_FMT_UYVY422;
		ap1302_write_context_reg(&dev->sd, context,
			CNTX_OUT_FMT, AP1302_REG16);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static const struct v4l2_ctrl_ops ctrl_ops = {
	.s_ctrl = ap1302_s_ctrl,
};

static const char * const ctrl_run_mode_menu[] = {
	NULL,
	"Video",
	"Still capture",
	"Continuous capture",
	"Preview",
};

static const struct v4l2_ctrl_config ctrls[] = {
	{
		.ops = &ctrl_ops,
		.id = V4L2_CID_RUN_MODE,
		.name = "Run Mode",
		.type = V4L2_CTRL_TYPE_MENU,
		.min = 1,
		.def = 4,
		.max = 4,
		.qmenu = ctrl_run_mode_menu,
	},
};

static struct v4l2_subdev_sensor_ops ap1302_sensor_ops = {
	.g_skip_frames	= ap1302_g_skip_frames,
};

static const struct v4l2_subdev_video_ops ap1302_video_ops = {
	.try_mbus_fmt = ap1302_try_mbus_fmt,
	.s_mbus_fmt = ap1302_set_mbus_fmt,
	.g_mbus_fmt = ap1302_get_mbus_fmt,
	.s_stream = ap1302_s_stream,
	.enum_framesizes = ap1302_enum_framesizes,
	.enum_frameintervals = ap1302_enum_frameintervals,
};

static const struct v4l2_subdev_core_ops ap1302_core_ops = {
	.s_power	= ap1302_s_power,
	.queryctrl	= v4l2_subdev_queryctrl,
	.g_ctrl		= v4l2_subdev_g_ctrl,
	.s_ctrl		= v4l2_subdev_s_ctrl,
};

static const struct v4l2_subdev_pad_ops ap1302_pad_ops = {
	.enum_mbus_code	 = ap1302_enum_mbus_code,
	.enum_frame_size = ap1302_enum_frame_size,
	.get_fmt	 = ap1302_get_pad_format,
	.set_fmt	 = ap1302_set_pad_format,
};

static const struct v4l2_subdev_ops ap1302_ops = {
	.core		= &ap1302_core_ops,
	.pad		= &ap1302_pad_ops,
	.video		= &ap1302_video_ops,
	.sensor		= &ap1302_sensor_ops
};

static int ap1302_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct ap1302_device *dev = to_ap1302_device(sd);

	if (dev->platform_data->platform_deinit)
		dev->platform_data->platform_deinit();

	if (dev->fw)
		release_firmware(dev->fw);

	media_entity_cleanup(&dev->sd.entity);
	dev->platform_data->csi_cfg(sd, 0);
	v4l2_device_unregister_subdev(sd);

	return 0;
}

static int ap1302_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct ap1302_device *dev;
	int ret;
	unsigned int i;

	dev_info(&client->dev, "ap1302 probe called.\n");

	/* allocate device & init sub device */
	dev = devm_kzalloc(&client->dev, sizeof(*dev), GFP_KERNEL);
	if (!dev) {
		dev_err(&client->dev, "%s: out of memory\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&dev->input_lock);

	v4l2_i2c_subdev_init(&(dev->sd), client, &ap1302_ops);

	ret = ap1302_request_firmware(&(dev->sd));
	if (ret) {
		dev_err(&client->dev, "Cannot request ap1302 firmware.\n");
		goto out_free;
	}

	dev->regmap16 = devm_regmap_init_i2c(client, &ap1302_reg16_config);
	if (IS_ERR(dev->regmap16)) {
		ret = PTR_ERR(dev->regmap16);
		dev_err(&client->dev,
			"Failed to allocate 16bit register map: %d\n", ret);
		return ret;
	}

	dev->regmap32 = devm_regmap_init_i2c(client, &ap1302_reg32_config);
	if (IS_ERR(dev->regmap32)) {
		ret = PTR_ERR(dev->regmap32);
		dev_err(&client->dev,
			"Failed to allocate 32bit register map: %d\n", ret);
		return ret;
	}

	if (client->dev.platform_data) {
		ret = ap1302_s_config(&dev->sd, client->dev.platform_data);
		if (ret)
			goto out_free;
	}

	dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	dev->pad.flags = MEDIA_PAD_FL_SOURCE;
	dev->sd.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;

	dev->cntx_res[CONTEXT_PREVIEW].res_num = ARRAY_SIZE(ap1302_preview_res);
	dev->cntx_res[CONTEXT_PREVIEW].res_table = ap1302_preview_res;
	dev->cntx_res[CONTEXT_SNAPSHOT].res_num =
		ARRAY_SIZE(ap1302_snapshot_res);
	dev->cntx_res[CONTEXT_SNAPSHOT].res_table = ap1302_snapshot_res;
	dev->cntx_res[CONTEXT_VIDEO].res_num = ARRAY_SIZE(ap1302_video_res);
	dev->cntx_res[CONTEXT_VIDEO].res_table = ap1302_video_res;

	ret = v4l2_ctrl_handler_init(&dev->ctrl_handler, ARRAY_SIZE(ctrls));
	if (ret) {
		ap1302_remove(client);
		return ret;
	}

	for (i = 0; i < ARRAY_SIZE(ctrls); i++)
		v4l2_ctrl_new_custom(&dev->ctrl_handler, &ctrls[i], NULL);

	if (dev->ctrl_handler.error) {
		ap1302_remove(client);
		return dev->ctrl_handler.error;
	}

	/* Use same lock for controls as for everything else. */
	dev->ctrl_handler.lock = &dev->input_lock;
	dev->sd.ctrl_handler = &dev->ctrl_handler;
	v4l2_ctrl_handler_setup(&dev->ctrl_handler);

	dev->run_mode = v4l2_ctrl_find(&dev->ctrl_handler, V4L2_CID_RUN_MODE);
	v4l2_ctrl_s_ctrl(dev->run_mode, ATOMISP_RUN_MODE_PREVIEW);

	ret = media_entity_init(&dev->sd.entity, 1, &dev->pad, 0);
	if (ret)
		ap1302_remove(client);
	return ret;
out_free:
	v4l2_device_unregister_subdev(&dev->sd);
	return ret;
}

static const struct i2c_device_id ap1302_id[] = {
	{AP1302_NAME, 0},
	{}
};
MODULE_DEVICE_TABLE(i2c, ap1302_id);

static struct i2c_driver ap1302_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = AP1302_NAME,
	},
	.probe = ap1302_probe,
	.remove = ap1302_remove,
	.id_table = ap1302_id,
};

module_i2c_driver(ap1302_driver);

MODULE_AUTHOR("Tianshu Qiu <tian.shu.qiu@intel.com>");
MODULE_DESCRIPTION("AP1302 Driver");
MODULE_LICENSE("GPL");
