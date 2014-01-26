/*
 * Support for GalaxyCore GC2235 2M camera sensor.
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

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/kmod.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/moduleparam.h>
#include <media/v4l2-device.h>
#include <media/v4l2-chip-ident.h>
#include <linux/io.h>

#include "gc2235.h"

/* i2c read/write stuff */
static int gc2235_read_reg(struct i2c_client *client,
			   u16 data_length, u16 reg, u16 *val)
{
	int err;
	struct i2c_msg msg[2];
	unsigned char data[6];

	if (!client->adapter) {
		dev_err(&client->dev, "%s error, no client->adapter\n",
			__func__);
		return -ENODEV;
	}

	if (data_length != GC2235_8BIT) {
		dev_err(&client->dev, "%s error, invalid data length\n",
			__func__);
		return -EINVAL;
	}

	memset(msg, 0 , sizeof(msg));

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = 1;
	msg[0].buf = data;

	/* high byte goes out first */
	data[0] = (u8)(reg & 0xff);

	msg[1].addr = client->addr;
	msg[1].len = data_length;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = data;

	err = i2c_transfer(client->adapter, msg, 2);
	if (err != 2) {
		if (err >= 0)
			err = -EIO;
		dev_err(&client->dev,
			"read from offset 0x%x error %d", reg, err);
		return err;
	}

	*val = 0;
	/* high byte comes first */
	if (data_length == GC2235_8BIT)
		*val = (u8)data[0];

	return 0;
}

static int gc2235_i2c_write(struct i2c_client *client, u16 len, u8 *data)
{
	struct i2c_msg msg;
	const int num_msg = 1;
	int ret;

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = len;
	msg.buf = data;
	ret = i2c_transfer(client->adapter, &msg, 1);

	return ret == num_msg ? 0 : -EIO;
}

static int gc2235_write_reg(struct i2c_client *client, u16 data_length,
							u8 reg, u8 val)
{
	int ret;
	unsigned char data[4] = {0};
	const u16 len = data_length + sizeof(u8); /* 16-bit address + data */

	if (data_length != GC2235_8BIT) {
		dev_err(&client->dev,
			"%s error, invalid data_length\n", __func__);
		return -EINVAL;
	}

	/* high byte goes out first */
	data[0] = reg;
	data[1] = val;

	ret = gc2235_i2c_write(client, len, data);
	if (ret)
		dev_err(&client->dev,
			"write error: wrote 0x%x to offset 0x%x error %d",
			val, reg, ret);

	return ret;
}
static int __gc2235_flush_reg_array(struct i2c_client *client,
				    struct gc2235_write_ctrl *ctrl)
{
	u16 size;

	if (ctrl->index == 0)
		return 0;

	size = sizeof(u8) + ctrl->index; /* 8-bit address + data */
	ctrl->index = 0;

	return gc2235_i2c_write(client, size, (u8 *)&ctrl->buffer);
}

static int __gc2235_buf_reg_array(struct i2c_client *client,
				  struct gc2235_write_ctrl *ctrl,
				  const struct gc2235_reg *next)
{
	int size;

	if (next->type != GC2235_8BIT)
		return -EINVAL;

	size = 1;
	ctrl->buffer.data[ctrl->index] = (u8)next->val;

	/* When first item is added, we need to store its starting address */
	if (ctrl->index == 0)
		ctrl->buffer.addr = next->reg;

	ctrl->index += size;

	/*
	 * Buffer cannot guarantee free space for u32? Better flush it to avoid
	 * possible lack of memory for next item.
	 */
	if (ctrl->index + sizeof(u8) >= GC2235_MAX_WRITE_BUF_SIZE)
		return __gc2235_flush_reg_array(client, ctrl);

	return 0;
}
static int __gc2235_write_reg_is_consecutive(struct i2c_client *client,
					     struct gc2235_write_ctrl *ctrl,
					     const struct gc2235_reg *next)
{
	if (ctrl->index == 0)
		return 1;

	return ctrl->buffer.addr + ctrl->index == next->reg;
}
static int gc2235_write_reg_array(struct i2c_client *client,
				  const struct gc2235_reg *reglist)
{
	const struct gc2235_reg *next = reglist;
	struct gc2235_write_ctrl ctrl;
	int err;

	ctrl.index = 0;
	for (; next->type != GC2235_TOK_TERM; next++) {
		switch (next->type & GC2235_TOK_MASK) {
		case GC2235_TOK_DELAY:
			err = __gc2235_flush_reg_array(client, &ctrl);
			if (err)
				return err;
			msleep(next->val);
			break;
		default:
			/*
			 * If next address is not consecutive, data needs to be
			 * flushed before proceed.
			 */
			if (!__gc2235_write_reg_is_consecutive(client, &ctrl,
								next)) {
				err = __gc2235_flush_reg_array(client, &ctrl);
				if (err)
					return err;
			}
			err = __gc2235_buf_reg_array(client, &ctrl, next);
			if (err) {
				dev_err(&client->dev, "%s: write error, aborted\n",
					 __func__);
				return err;
			}
			break;
		}
	}

	return __gc2235_flush_reg_array(client, &ctrl);
}

static int gc2235_g_focal(struct v4l2_subdev *sd, s32 *val)
{
	*val = (GC2235_FOCAL_LENGTH_NUM << 16) | GC2235_FOCAL_LENGTH_DEM;
	return 0;
}

static int gc2235_g_fnumber(struct v4l2_subdev *sd, s32 *val)
{
	/*const f number for imx*/
	*val = (GC2235_F_NUMBER_DEFAULT_NUM << 16) | GC2235_F_NUMBER_DEM;
	return 0;
}

static int gc2235_g_fnumber_range(struct v4l2_subdev *sd, s32 *val)
{
	*val = (GC2235_F_NUMBER_DEFAULT_NUM << 24) |
		(GC2235_F_NUMBER_DEM << 16) |
		(GC2235_F_NUMBER_DEFAULT_NUM << 8) | GC2235_F_NUMBER_DEM;
	return 0;
}


static int gc2235_get_intg_factor(struct i2c_client *client,
				struct camera_mipi_info *info,
				const struct gc2235_resolution *res)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct atomisp_sensor_mode_data *buf = &info->data;
	u16 reg_val, reg_val_h, dummy;
	int ret;

	if (info == NULL)
		return -EINVAL;

	/* pixel clock calculattion */
	buf->vt_pix_clk_freq_mhz = dev->vt_pix_clk_freq_mhz = 43750000;

	/* get integration time */
	buf->coarse_integration_time_min = GC2235_COARSE_INTG_TIME_MIN;
	buf->coarse_integration_time_max_margin =
					GC2235_COARSE_INTG_TIME_MAX_MARGIN;

	buf->fine_integration_time_min = GC2235_FINE_INTG_TIME_MIN;
	buf->fine_integration_time_max_margin =
					GC2235_FINE_INTG_TIME_MAX_MARGIN;

	buf->fine_integration_time_def = GC2235_FINE_INTG_TIME_MIN;
	buf->frame_length_lines = res->lines_per_frame;
	buf->line_length_pck = res->pixels_per_line;
	buf->read_mode = res->bin_mode;

	/* get the cropping and output resolution to ISP for this mode. */
	ret =  gc2235_read_reg(client, GC2235_8BIT,
					GC2235_H_CROP_START_H, &reg_val_h);
	ret =  gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_H_CROP_START_L, &reg_val);
	if (ret)
		return ret;

	buf->crop_horizontal_start = ((u16)reg_val_h << 8) | (u16)reg_val;

	ret =  gc2235_read_reg(client, GC2235_8BIT,
					GC2235_V_CROP_START_H, &reg_val_h);
	ret =  gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_V_CROP_START_L, &reg_val);
	if (ret)
		return ret;

	buf->crop_vertical_start = ((u16)reg_val_h << 8) | (u16)reg_val;

	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_H_OUTSIZE_H, &reg_val_h);
	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_H_OUTSIZE_L, &reg_val);
	if (ret)
		return ret;
	buf->output_width = ((u16)reg_val_h << 8) | (u16)reg_val;

	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_V_OUTSIZE_H, &reg_val_h);
	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_V_OUTSIZE_L, &reg_val);
	if (ret)
		return ret;
	buf->output_height = ((u16)reg_val_h << 8) | (u16)reg_val;

	buf->crop_horizontal_end = buf->crop_horizontal_start +
						buf->output_width - 1;
	buf->crop_vertical_end = buf->crop_vertical_start +
						buf->output_height - 1;

	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_HB_H, &reg_val_h);
	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_HB_L, &reg_val);
	if (ret)
		return ret;

	dummy = ((u16)reg_val_h << 8) | (u16)reg_val;

	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_SH_DELAY_H, &reg_val_h);
	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_SH_DELAY_L, &reg_val);

	buf->line_length_pck = buf->output_width + 16 + dummy +
				(((u16)reg_val_h << 8) | (u16)reg_val) + 4;
	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_VB_H, &reg_val_h);
	ret = gc2235_read_reg(client, GC2235_8BIT,
                                        GC2235_VB_L, &reg_val);
	if (ret)
		return ret;

	buf->frame_length_lines = buf->output_height + 32 +
				(((u16)reg_val_h << 8) | (u16)reg_val);
	buf->binning_factor_x = res->bin_factor_x ?
					res->bin_factor_x : 1;
	buf->binning_factor_y = res->bin_factor_y ?
					res->bin_factor_y : 1;
	return 0;
}

static long __gc2235_set_exposure(struct v4l2_subdev *sd, int coarse_itg,
				 int gain, int digitgain)

{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u16 coarse_integration = (u16)coarse_itg;
	int ret = 0;
	u16 expo_coarse_h,expo_coarse_l, gain_val = 0xF0, gain_val2 = 0xF0;
	expo_coarse_h = coarse_integration>>8;
	expo_coarse_l = coarse_integration & 0xff;

	ret = gc2235_write_reg(client, GC2235_8BIT,
					GC2235_EXPOSURE_H, expo_coarse_h);
	ret = gc2235_write_reg(client, GC2235_8BIT,
					GC2235_EXPOSURE_L, expo_coarse_l);

	if (gain <= 0x58) {
		gain_val = 0x40;
		gain_val2 = 0x58;
	} else if (gain < 256) {
		gain_val = 0x40;
		gain_val2 = gain;
	} else {
		gain_val2 = 64 * gain / 256;
		gain_val = 0xff;
	}

	ret = gc2235_write_reg(client, GC2235_8BIT,
					GC2235_GLOBAL_GAIN, (u8)gain_val);
	ret = gc2235_write_reg(client, GC2235_8BIT,
					GC2235_PRE_GAIN, (u8)gain_val2);

	return ret;
}

static int gc2235_set_exposure(struct v4l2_subdev *sd, int exposure,
	int gain, int digitgain)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	ret = __gc2235_set_exposure(sd, exposure, gain, digitgain);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static long gc2235_s_exposure(struct v4l2_subdev *sd,
			       struct atomisp_exposure *exposure)
{
	int exp = exposure->integration_time[0];
	int gain = exposure->gain[0];
	int digitgain = exposure->gain[1];

	/* we should not accept the invalid value below. */
	if (gain == 0) {
		struct i2c_client *client = v4l2_get_subdevdata(sd);
		v4l2_err(client, "%s: invalid value\n", __func__);
		return -EINVAL;
	}

	return gc2235_set_exposure(sd, exp, gain, digitgain);
}

static long gc2235_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{

	switch (cmd) {
	case ATOMISP_IOC_S_EXPOSURE:
		return gc2235_s_exposure(sd, arg);
	default:
		return -EINVAL;
	}
	return 0;
}

/* This returns the exposure time being used. This should only be used
   for filling in EXIF data, not for actual image processing. */
static int gc2235_q_exposure(struct v4l2_subdev *sd, s32 *value)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u16 reg_v, reg_v2;
	int ret;

	/* get exposure */
	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_EXPOSURE_L,
					&reg_v);
	if (ret)
		goto err;

	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_EXPOSURE_H,
					&reg_v2);
	if (ret)
		goto err;

	reg_v += reg_v2 << 8;

	*value = reg_v;
err:
	return ret;
}

struct gc2235_control gc2235_controls[] = {
	{
		.qc = {
			.id = V4L2_CID_EXPOSURE_ABSOLUTE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "exposure",
			.minimum = 0x0,
			.maximum = 0xffff,
			.step = 0x01,
			.default_value = 0x00,
			.flags = 0,
		},
		.query = gc2235_q_exposure,
	},
	{
		.qc = {
			.id = V4L2_CID_FOCAL_ABSOLUTE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "focal length",
			.minimum = GC2235_FOCAL_LENGTH_DEFAULT,
			.maximum = GC2235_FOCAL_LENGTH_DEFAULT,
			.step = 0x01,
			.default_value = GC2235_FOCAL_LENGTH_DEFAULT,
			.flags = 0,
		},
		.query = gc2235_g_focal,
	},
	{
		.qc = {
			.id = V4L2_CID_FNUMBER_ABSOLUTE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "f-number",
			.minimum = GC2235_F_NUMBER_DEFAULT,
			.maximum = GC2235_F_NUMBER_DEFAULT,
			.step = 0x01,
			.default_value = GC2235_F_NUMBER_DEFAULT,
			.flags = 0,
		},
		.query = gc2235_g_fnumber,
	},
	{
		.qc = {
			.id = V4L2_CID_FNUMBER_RANGE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "f-number range",
			.minimum = GC2235_F_NUMBER_RANGE,
			.maximum =  GC2235_F_NUMBER_RANGE,
			.step = 0x01,
			.default_value = GC2235_F_NUMBER_RANGE,
			.flags = 0,
		},
		.query = gc2235_g_fnumber_range,
	},
};
#define N_CONTROLS (ARRAY_SIZE(gc2235_controls))

static struct gc2235_control *gc2235_find_control(u32 id)
{
	int i;

	for (i = 0; i < N_CONTROLS; i++)
		if (gc2235_controls[i].qc.id == id)
			return &gc2235_controls[i];
	return NULL;
}

static int gc2235_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
	struct gc2235_control *ctrl = gc2235_find_control(qc->id);
	struct gc2235_device *dev = to_gc2235_sensor(sd);

	if (ctrl == NULL)
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	*qc = ctrl->qc;
	mutex_unlock(&dev->input_lock);

	return 0;
}

/* imx control set/get */
static int gc2235_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
	struct gc2235_control *s_ctrl;
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	int ret;

	if (!ctrl)
		return -EINVAL;

	s_ctrl = gc2235_find_control(ctrl->id);
	if ((s_ctrl == NULL) || (s_ctrl->query == NULL))
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	ret = s_ctrl->query(sd, &ctrl->value);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int gc2235_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
	struct gc2235_control *octrl = gc2235_find_control(ctrl->id);
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	int ret;

	if ((octrl == NULL) || (octrl->tweak == NULL))
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	ret = octrl->tweak(sd, ctrl->value);
	mutex_unlock(&dev->input_lock);

	return ret;
}
static int __gc2235_init(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	/* restore settings */
	gc2235_res = gc2235_res_preview;
	N_RES = N_RES_PREVIEW;

	return gc2235_write_reg_array(client, gc2235_init_settings);
}

static int gc2235_init(struct v4l2_subdev *sd)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	int ret = 0;

	mutex_lock(&dev->input_lock);
	ret = __gc2235_init(sd);
	mutex_unlock(&dev->input_lock);

	return ret;
}


static int power_up(struct v4l2_subdev *sd)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	if (NULL == dev->platform_data) {
		dev_err(&client->dev,
			"no camera_sensor_platform_data");
		return -ENODEV;
	}
	/* power control */
	ret = dev->platform_data->power_ctrl(sd, 1);
	if (ret)
		goto fail_power;

	/* according to DS, at least 5ms is needed between DOVDD and PWDN */
	usleep_range(5000, 6000);

	ret = dev->platform_data->flisclk_ctrl(sd, 1);
	if (ret)
		goto fail_clk;
	usleep_range(5000, 6000);

	/* gpio ctrl */
	ret = dev->platform_data->gpio_ctrl(sd, 1);
	if (ret) {
		ret = dev->platform_data->gpio_ctrl(sd, 1);
		if (ret)
			goto fail_power;
	}

	msleep(50);

	return 0;

fail_clk:
	dev->platform_data->gpio_ctrl(sd, 0);
fail_power:
	dev->platform_data->power_ctrl(sd, 0);
	dev_err(&client->dev, "sensor power-up failed\n");

	return ret;
}

static int power_down(struct v4l2_subdev *sd)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret = 0;

	if (NULL == dev->platform_data) {
		dev_err(&client->dev,
			"no camera_sensor_platform_data");
		return -ENODEV;
	}
	/* gpio ctrl */
	ret = dev->platform_data->gpio_ctrl(sd, 0);
	if (ret) {
		ret = dev->platform_data->gpio_ctrl(sd, 0);
		if (ret)
			dev_err(&client->dev, "gpio failed 2\n");
	}

	ret = dev->platform_data->flisclk_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "flisclk failed\n");

	/* power control */
	ret = dev->platform_data->power_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "vprog failed.\n");

	return ret;
}

static int gc2235_s_power(struct v4l2_subdev *sd, int on)
{
	int ret;
	if (on == 0)
		return power_down(sd);
	else {
		ret = power_up(sd);
		if (!ret)
			return gc2235_init(sd);
	}
	return ret;
}

/*
 * distance - calculate the distance
 * @res: resolution
 * @w: width
 * @h: height
 *
 * Get the gap between resolution and w/h.
 * res->width/height smaller than w/h wouldn't be considered.
 * Returns the value of gap or -1 if fail.
 */
#define LARGEST_ALLOWED_RATIO_MISMATCH 800
static int distance(struct gc2235_resolution *res, u32 w, u32 h)
{
	unsigned int w_ratio = ((res->width << 13)/w);
	unsigned int h_ratio;
	int match;

	if (h == 0)
		return -1;
	h_ratio = ((res->height << 13) / h);
	if (h_ratio == 0)
		return -1;
	match   = abs(((w_ratio << 13) / h_ratio) - ((int)8192));

	if ((w_ratio < (int)8192) || (h_ratio < (int)8192)  ||
		(match > LARGEST_ALLOWED_RATIO_MISMATCH))
		return -1;

	return w_ratio + h_ratio;
}

/* Return the nearest higher resolution index */
static int nearest_resolution_index(int w, int h)
{
	int i;
	int idx = -1;
	int dist;
	int min_dist = INT_MAX;
	struct gc2235_resolution *tmp_res = NULL;

	for (i = 0; i < N_RES; i++) {
		tmp_res = &gc2235_res[i];
		dist = distance(tmp_res, w, h);
		if (dist == -1)
			continue;
		if (dist < min_dist) {
			min_dist = dist;
			idx = i;
		}
	}

	return idx;
}

static int get_resolution_index(int w, int h)
{
	int i;

	for (i = 0; i < N_RES; i++) {
		if (w != gc2235_res[i].width)
			continue;
		if (h != gc2235_res[i].height)
			continue;

		return i;
	}

	return -1;
}

static int gc2235_try_mbus_fmt(struct v4l2_subdev *sd,
			struct v4l2_mbus_framefmt *fmt)
{
	int idx;

	if (!fmt)
		return -EINVAL;
	idx = nearest_resolution_index(fmt->width,
					fmt->height);
	if (idx == -1) {
		/* return the largest resolution */
		fmt->width = gc2235_res[N_RES - 1].width;
		fmt->height = gc2235_res[N_RES - 1].height;
	} else {
		fmt->width = gc2235_res[idx].width;
		fmt->height = gc2235_res[idx].height;
	}
	fmt->code = V4L2_MBUS_FMT_SGRBG10_1X10;

	return 0;
}

static int startup(struct v4l2_subdev *sd)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret = 0;

	ret = gc2235_write_reg_array(client, gc2235_res[dev->fmt_idx].regs);
	if (ret) {
		dev_err(&client->dev, "gc2235 write register err.\n");
		return ret;
	}

	return ret;
}

static int gc2235_s_mbus_fmt(struct v4l2_subdev *sd,
			     struct v4l2_mbus_framefmt *fmt)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct camera_mipi_info *gc2235_info = NULL;
	int ret = 0;

	gc2235_info = v4l2_get_subdev_hostdata(sd);
	if (gc2235_info == NULL)
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	ret = gc2235_try_mbus_fmt(sd, fmt);
	if (ret == -1) {
		dev_err(&client->dev, "try fmt fail\n");
		goto err;
	}

	dev->fmt_idx = get_resolution_index(fmt->width,
					      fmt->height);
	if (dev->fmt_idx == -1) {
		dev_err(&client->dev, "get resolution fail\n");
		mutex_unlock(&dev->input_lock);
		return -EINVAL;
	}

	ret = startup(sd);
	if (ret) {
		dev_err(&client->dev, "gc2235 startup err\n");
		goto err;
	}

	ret = gc2235_get_intg_factor(client, gc2235_info,
					&gc2235_res[dev->fmt_idx]);
	if (ret)
		dev_err(&client->dev, "failed to get integration_factor\n");

err:
	mutex_unlock(&dev->input_lock);
	return ret;
}
static int gc2235_g_mbus_fmt(struct v4l2_subdev *sd,
			     struct v4l2_mbus_framefmt *fmt)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);

	if (!fmt)
		return -EINVAL;

	fmt->width = gc2235_res[dev->fmt_idx].width;
	fmt->height = gc2235_res[dev->fmt_idx].height;
	fmt->code = V4L2_MBUS_FMT_SGRBG10_1X10;

	return 0;
}

static int gc2235_detect(struct i2c_client *client)
{
	struct i2c_adapter *adapter = client->adapter;
	u16 high, low;
	int ret;
	u16 id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C))
		return -ENODEV;

	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_SENSOR_ID_H, &high);
	if (ret) {
		dev_err(&client->dev, "sensor_id_high = 0x%x\n", high);
		return -ENODEV;
	}
	ret = gc2235_read_reg(client, GC2235_8BIT,
					GC2235_SENSOR_ID_L, &low);
	id = ((((u16) high) << 8) | (u16) low);

	if (id != GC2235_ID) {
		dev_err(&client->dev, "sensor ID error, 0x%x\n", id);
		return -ENODEV;
	}

	dev_dbg(&client->dev, "detect gc2235 success\n");
	return 0;
}

static int gc2235_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	mutex_lock(&dev->input_lock);

	if (enable)
		ret = gc2235_write_reg_array(client, gc2235_stream_on);
	else
		ret = gc2235_write_reg_array(client, gc2235_stream_off);

	mutex_unlock(&dev->input_lock);
	return ret;
}

/* gc2235 enum frame size, frame intervals */
static int gc2235_enum_framesizes(struct v4l2_subdev *sd,
				  struct v4l2_frmsizeenum *fsize)
{
	unsigned int index = fsize->index;

	if (index >= N_RES)
		return -EINVAL;

	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
	fsize->discrete.width = gc2235_res[index].width;
	fsize->discrete.height = gc2235_res[index].height;
	fsize->reserved[0] = gc2235_res[index].used;

	return 0;
}

static int gc2235_enum_frameintervals(struct v4l2_subdev *sd,
				      struct v4l2_frmivalenum *fival)
{
	unsigned int index = fival->index;

	if (index >= N_RES)
		return -EINVAL;

	fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
	fival->width = gc2235_res[index].width;
	fival->height = gc2235_res[index].height;
	fival->discrete.numerator = 1;
	fival->discrete.denominator = gc2235_res[index].fps;

	return 0;
}

static int gc2235_enum_mbus_fmt(struct v4l2_subdev *sd,
				unsigned int index,
				enum v4l2_mbus_pixelcode *code)
{
	*code = V4L2_MBUS_FMT_SBGGR10_1X10;

	return 0;
}

static int gc2235_s_config(struct v4l2_subdev *sd,
			   int irq, void *platform_data)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret = 0;

	if (platform_data == NULL)
		return -ENODEV;

	dev->platform_data =
		(struct camera_sensor_platform_data *)platform_data;

	mutex_lock(&dev->input_lock);
	/* power off the module, then power on it in future
	 * as first power on by board may not fulfill the
	 * power on sequqence needed by the module
	 */
	ret = power_down(sd);
	if (ret) {
		dev_err(&client->dev, "gc2235 power-off err.\n");
		goto fail_power_off;
	}

	ret = power_up(sd);
	if (ret) {
		dev_err(&client->dev, "gc2235 power-up err.\n");
		goto fail_power_on;
	}

	ret = dev->platform_data->csi_cfg(sd, 1);
	if (ret)
		goto fail_csi_cfg;

	/* config & detect sensor */
	ret = gc2235_detect(client);
	if (ret) {
		dev_err(&client->dev, "gc2235_detect err s_config.\n");
		goto fail_csi_cfg;
	}

	/* turn off sensor, after probed */
	ret = power_down(sd);
	if (ret) {
		dev_err(&client->dev, "gc2235 power-off err.\n");
		goto fail_csi_cfg;
	}
	mutex_unlock(&dev->input_lock);

	return 0;

fail_csi_cfg:
	dev->platform_data->csi_cfg(sd, 0);
fail_power_on:
	power_down(sd);
	dev_err(&client->dev, "sensor power-gating failed\n");
fail_power_off:
	mutex_unlock(&dev->input_lock);
	return ret;
}

static int gc2235_g_parm(struct v4l2_subdev *sd,
			struct v4l2_streamparm *param)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	if (!param)
		return -EINVAL;

	if (param->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
		dev_err(&client->dev,  "unsupported buffer type.\n");
		return -EINVAL;
	}

	memset(param, 0, sizeof(*param));
	param->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if (dev->fmt_idx >= 0 && dev->fmt_idx < N_RES) {
		param->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
		param->parm.capture.timeperframe.numerator = 1;
		param->parm.capture.capturemode = dev->run_mode;
		param->parm.capture.timeperframe.denominator =
			gc2235_res[dev->fmt_idx].fps;
	}
	return 0;
}

static int gc2235_s_parm(struct v4l2_subdev *sd,
			struct v4l2_streamparm *param)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	dev->run_mode = param->parm.capture.capturemode;

	mutex_lock(&dev->input_lock);
	switch (dev->run_mode) {
	case CI_MODE_VIDEO:
		gc2235_res = gc2235_res_video;
		N_RES = N_RES_VIDEO;
		break;
	case CI_MODE_STILL_CAPTURE:
		gc2235_res = gc2235_res_still;
		N_RES = N_RES_STILL;
		break;
	default:
		gc2235_res = gc2235_res_preview;
		N_RES = N_RES_PREVIEW;
	}
	mutex_unlock(&dev->input_lock);
	return 0;
}

static int gc2235_g_frame_interval(struct v4l2_subdev *sd,
				   struct v4l2_subdev_frame_interval *interval)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);

	interval->interval.numerator = 1;
	interval->interval.denominator = gc2235_res[dev->fmt_idx].fps;

	return 0;
}

static int gc2235_enum_mbus_code(struct v4l2_subdev *sd,
				struct v4l2_subdev_fh *fh,
				struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->index >= MAX_FMTS)
		return -EINVAL;

	code->code = V4L2_MBUS_FMT_SBGGR10_1X10;
	return 0;
}

static int gc2235_enum_frame_size(struct v4l2_subdev *sd,
				struct v4l2_subdev_fh *fh,
				struct v4l2_subdev_frame_size_enum *fse)
{
	int index = fse->index;

	if (index >= N_RES)
		return -EINVAL;

	fse->min_width = gc2235_res[index].width;
	fse->min_height = gc2235_res[index].height;
	fse->max_width = gc2235_res[index].width;
	fse->max_height = gc2235_res[index].height;

	return 0;

}

static struct v4l2_mbus_framefmt *
__gc2235_get_pad_format(struct gc2235_device *sensor,
			struct v4l2_subdev_fh *fh, unsigned int pad,
			enum v4l2_subdev_format_whence which)
{
	struct i2c_client *client = v4l2_get_subdevdata(&sensor->sd);

	if (pad != 0) {
		dev_err(&client->dev,
			"__gc2235_get_pad_format err. pad %x\n", pad);
		return NULL;
	}

	switch (which) {
	case V4L2_SUBDEV_FORMAT_TRY:
		return v4l2_subdev_get_try_format(fh, pad);
	case V4L2_SUBDEV_FORMAT_ACTIVE:
		return &sensor->format;
	default:
		return NULL;
	}
}

static int gc2235_get_pad_format(struct v4l2_subdev *sd,
				struct v4l2_subdev_fh *fh,
				struct v4l2_subdev_format *fmt)
{
	struct gc2235_device *snr = to_gc2235_sensor(sd);
	struct v4l2_mbus_framefmt *format =
			__gc2235_get_pad_format(snr, fh, fmt->pad, fmt->which);
	if (!format)
		return -EINVAL;

	fmt->format = *format;
	return 0;
}

static int gc2235_set_pad_format(struct v4l2_subdev *sd,
				struct v4l2_subdev_fh *fh,
				struct v4l2_subdev_format *fmt)
{
	struct gc2235_device *snr = to_gc2235_sensor(sd);

	if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE)
		snr->format = fmt->format;

	return 0;
}

static int gc2235_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
	struct gc2235_device *dev = to_gc2235_sensor(sd);

	mutex_lock(&dev->input_lock);
	*frames = gc2235_res[dev->fmt_idx].skip_frames;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static const struct v4l2_subdev_sensor_ops gc2235_sensor_ops = {
	.g_skip_frames	= gc2235_g_skip_frames,
};

static const struct v4l2_subdev_video_ops gc2235_video_ops = {
	.s_stream = gc2235_s_stream,
	.g_parm = gc2235_g_parm,
	.s_parm = gc2235_s_parm,
	.enum_framesizes = gc2235_enum_framesizes,
	.enum_frameintervals = gc2235_enum_frameintervals,
	.enum_mbus_fmt = gc2235_enum_mbus_fmt,
	.try_mbus_fmt = gc2235_try_mbus_fmt,
	.g_mbus_fmt = gc2235_g_mbus_fmt,
	.s_mbus_fmt = gc2235_s_mbus_fmt,
	.g_frame_interval = gc2235_g_frame_interval,
};

static const struct v4l2_subdev_core_ops gc2235_core_ops = {
	.s_power = gc2235_s_power,
	.queryctrl = gc2235_queryctrl,
	.g_ctrl = gc2235_g_ctrl,
	.s_ctrl = gc2235_s_ctrl,
	.ioctl = gc2235_ioctl,
};

static const struct v4l2_subdev_pad_ops gc2235_pad_ops = {
	.enum_mbus_code = gc2235_enum_mbus_code,
	.enum_frame_size = gc2235_enum_frame_size,
	.get_fmt = gc2235_get_pad_format,
	.set_fmt = gc2235_set_pad_format,
};

static const struct v4l2_subdev_ops gc2235_ops = {
	.core = &gc2235_core_ops,
	.video = &gc2235_video_ops,
	.pad = &gc2235_pad_ops,
	.sensor = &gc2235_sensor_ops,
};

static int gc2235_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct gc2235_device *dev = to_gc2235_sensor(sd);
	dev_dbg(&client->dev, "gc2235_remove...\n");

	dev->platform_data->csi_cfg(sd, 0);

	v4l2_device_unregister_subdev(sd);
	media_entity_cleanup(&dev->sd.entity);
	kfree(dev);

	return 0;
}

static int gc2235_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct gc2235_device *dev;
	int ret;

	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev) {
		dev_err(&client->dev, "out of memory\n");
		return -ENOMEM;
	}

	mutex_init(&dev->input_lock);

	dev->fmt_idx = 0;
	v4l2_i2c_subdev_init(&(dev->sd), client, &gc2235_ops);

	if (client->dev.platform_data) {
		ret = gc2235_s_config(&dev->sd, client->irq,
				       client->dev.platform_data);
		if (ret)
			goto out_free;
	}

	dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	dev->pad.flags = MEDIA_PAD_FL_SOURCE;
	dev->format.code = V4L2_MBUS_FMT_SBGGR10_1X10;
	dev->sd.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;

	ret = media_entity_init(&dev->sd.entity, 1, &dev->pad, 0);
	if (ret)
		gc2235_remove(client);

	return ret;
out_free:
	v4l2_device_unregister_subdev(&dev->sd);
	kfree(dev);
	return ret;
}

MODULE_DEVICE_TABLE(i2c, gc2235_id);
static struct i2c_driver gc2235_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = GC2235_NAME,
	},
	.probe = gc2235_probe,
	.remove = gc2235_remove,
	.id_table = gc2235_id,
};

static int init_gc2235(void)
{
	return i2c_add_driver(&gc2235_driver);
}

static void exit_gc2235(void)
{

	i2c_del_driver(&gc2235_driver);
}

module_init(init_gc2235);
module_exit(exit_gc2235);

MODULE_AUTHOR("Shuguang Gong <Shuguang.Gong@intel.com>");
MODULE_DESCRIPTION("A low-level driver for GC2235 sensors");
MODULE_LICENSE("GPL");
