/*
 * Support for OmniVision ov8858 camera sensor.
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

#include <linux/delay.h>
#include <linux/module.h>
#include <media/v4l2-chip-ident.h>
#include <media/v4l2-device.h>
#include "ov8858.h"

static int
ov8858_read_reg(struct i2c_client *client, u16 len, u16 reg, u16 *val)
{
	struct i2c_msg msg[2];
	u16 data[OV8858_SHORT_MAX];
	int err, i;

	if (!client->adapter) {
		dev_err(&client->dev, "%s error, no adapter\n", __func__);
		return -ENODEV;
	}

	/* @len should be even when > 1 */
	if (len > OV8858_BYTE_MAX) {
		dev_err(&client->dev, "%s error, invalid data length\n",
			__func__);
		return -EINVAL;
	}

	memset(msg, 0, sizeof(msg));
	memset(data, 0, sizeof(data));

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = I2C_MSG_LENGTH;
	msg[0].buf = (u8 *)data;
	/* high byte goes first */
	data[0] = cpu_to_be16(reg);

	msg[1].addr = client->addr;
	msg[1].len = len;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = (u8 *)data;

	err = i2c_transfer(client->adapter, msg, 2);
	if (err != 2) {
		if (err >= 0)
			err = -EIO;
		goto error;
	}

	/* high byte comes first */
	if (len == OV8858_8BIT) {
		*val = (u8)data[0];
	} else {
		/* 16-bit access is default when len > 1 */
		for (i = 0; i < (len >> 1); i++)
			val[i] = be16_to_cpu(data[i]);
	}

	return 0;

error:
	dev_err(&client->dev, "read from offset 0x%x error %d", reg, err);
	return err;
}

static int ov8858_i2c_write(struct i2c_client *client, u16 len, u8 *data)
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

static int
ov8858_write_reg(struct i2c_client *client, u16 data_length, u16 reg, u16 val)
{
	int ret;
	unsigned char data[4] = {0};
	u16 *wreg;
	const u16 len = data_length + sizeof(u16); /* 16-bit address + data */

	if (!client->adapter) {
		dev_err(&client->dev, "%s error, no adapter\n", __func__);
		return -ENODEV;
	}

	if (data_length != OV8858_8BIT && data_length != OV8858_16BIT) {
		dev_err(&client->dev, "%s error, invalid length\n", __func__);
		return -EINVAL;
	}

	/* high byte goes out first */
	wreg = (u16 *)data;
	*wreg = cpu_to_be16(reg);

	if (data_length == OV8858_8BIT) {
		data[2] = (u8)(val);
	} else {
		/* OV8858_16BIT */
		u16 *wdata = (u16 *)&data[2];
		*wdata = be16_to_cpu(val);
	}

	ret = ov8858_i2c_write(client, len, data);
	if (ret)
		dev_err(&client->dev,
			"write error: wrote 0x%x to offset 0x%x error %d",
			val, reg, ret);

	return ret;
}

/*
 * ov8858_write_reg_array - Initializes a list of registers
 * @client: i2c driver client structure
 * @reglist: list of registers to be written
 *
 * This function initializes a list of registers. When consecutive addresses
 * are found in a row on the list, this function creates a buffer and sends
 * consecutive data in a single i2c_transfer().
 *
 * __ov8858_flush_reg_array(), __ov8858_buf_reg_array() and
 * __ov8858_write_reg_is_consecutive() are internal functions to
 * ov8858_write_reg_array() and should be not used anywhere else.
 *
 */
static int __ov8858_flush_reg_array(struct i2c_client *client,
				    struct ov8858_write_ctrl *ctrl)
{
	u16 size;
	if (ctrl->index == 0)
		return 0;

	size = sizeof(u16) + ctrl->index; /* 16-bit address + data */
	ctrl->buffer.addr = cpu_to_be16(ctrl->buffer.addr);
	ctrl->index = 0;

	return ov8858_i2c_write(client, size, (u8 *)&ctrl->buffer);
}

static int __ov8858_buf_reg_array(struct i2c_client *client,
				  struct ov8858_write_ctrl *ctrl,
				  const struct ov8858_reg *next)
{
	int size;
	u16 *data16;
	switch (next->type) {
	case OV8858_8BIT:
		size = 1;
		ctrl->buffer.data[ctrl->index] = (u8)next->val;
		break;
	case OV8858_16BIT:
		size = 2;
		data16 = (u16 *)&ctrl->buffer.data[ctrl->index];
		*data16 = cpu_to_be16((u16)next->val);
		break;
	default:
		return -EINVAL;
	}

	/* When first item is added, we need to store its starting address */
	if (ctrl->index == 0)
		ctrl->buffer.addr = next->sreg;

	ctrl->index += size;

	/*
	 * Buffer cannot guarantee free space for u32? Better flush it to avoid
	 * possible lack of memory for next item.
	 */
	if (ctrl->index + sizeof(u16) >= OV8858_MAX_WRITE_BUF_SIZE)
		__ov8858_flush_reg_array(client, ctrl);

	return 0;
}

static int
__ov8858_write_reg_is_consecutive(struct i2c_client *client,
				  struct ov8858_write_ctrl *ctrl,
				  const struct ov8858_reg *next)
{
	if (ctrl->index == 0)
		return 1;

	return ctrl->buffer.addr + ctrl->index == next->sreg;
}

static int ov8858_write_reg_array(struct i2c_client *client,
				  const struct ov8858_reg *reglist)
{
	const struct ov8858_reg *next = reglist;
	struct ov8858_write_ctrl ctrl;
	int err;

	ctrl.index = 0;
	for (; next->type != OV8858_TOK_TERM; next++) {
		switch (next->type & OV8858_TOK_MASK) {
		case OV8858_TOK_DELAY:
			err = __ov8858_flush_reg_array(client, &ctrl);
			if (err)
				return err;
			msleep(next->val);
			break;

		default:
			/*
			 * If next address is not consecutive, data needs to be
			 * flushed before proceeding
			 */
			if (!__ov8858_write_reg_is_consecutive(client,
							       &ctrl, next)) {
				err = __ov8858_flush_reg_array(client, &ctrl);
				if (err)
					return err;
			}
			err = __ov8858_buf_reg_array(client, &ctrl, next);
			if (err) {
				dev_err(&client->dev, "%s: write error\n",
					__func__);
				return err;
			}
			break;
		}
	}

	return __ov8858_flush_reg_array(client, &ctrl);
}

static int __ov8858_min_fps_diff(int fps,
				 const struct ov8858_fps_setting *fps_list)
{
	int diff = INT_MAX;
	int i;

	if (fps == 0)
		return 0;

	for (i = 0; i < MAX_FPS_OPTIONS_SUPPORTED; i++) {
		if (!fps_list[i].fps)
			break;
		if (abs(fps_list[i].fps - fps) < diff)
			diff = abs(fps_list[i].fps - fps);
	}

	return diff;
}

static int __ov8858_nearest_fps_index(int fps,
				      const struct ov8858_fps_setting *fps_list)
{
	int fps_index = 0;
	int i;

	for (i = 0; i < MAX_FPS_OPTIONS_SUPPORTED; i++) {
		if (!fps_list[i].fps)
			break;
		if (abs(fps_list[i].fps - fps)
		    < abs(fps_list[fps_index].fps - fps))
			fps_index = i;
	}
	return fps_index;
}

static int __ov8858_get_max_fps_index(
				const struct ov8858_fps_setting *fps_settings)
{
	int i;
	for (i = 0; i < MAX_FPS_OPTIONS_SUPPORTED; i++) {
		if (fps_settings[i].fps == 0)
			break;
	}

	return i - 1;
}

static int __ov8858_update_frame_timing(struct v4l2_subdev *sd, int exposure,
					u16 *hts, u16 *vts)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	/* Increase the VTS to match exposure + 14 */
	if (exposure > *vts - OV8858_INTEGRATION_TIME_MARGIN)
		*vts = (u16) exposure + OV8858_INTEGRATION_TIME_MARGIN;

	ret = ov8858_write_reg(client, OV8858_16BIT, OV8858_TIMING_HTS, *hts);
	if (ret)
		return ret;
	return ov8858_write_reg(client, OV8858_16BIT, OV8858_TIMING_VTS, *vts);
}

static int __ov8858_set_exposure(struct v4l2_subdev *sd, int exposure, int gain,
				 int dig_gain, u16 *hts, u16 *vts)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int exp_val, ret;

	/* Update frame timings. Exposure must be minimum <  vts-14 */
	ret = __ov8858_update_frame_timing(sd, exposure, hts, vts);
	if (ret)
		return ret;

	/* For OV8835, the low 4 bits are fraction bits and must be kept 0 */
	exp_val = exposure << 4;
	ret = ov8858_write_reg(client, OV8858_8BIT,
			       OV8858_LONG_EXPO+2, exp_val & 0xFF);
	if (ret)
		return ret;

	ret = ov8858_write_reg(client, OV8858_8BIT,
			       OV8858_LONG_EXPO+1, (exp_val >> 8) & 0xFF);
	if (ret)
		return ret;

	ret = ov8858_write_reg(client, OV8858_8BIT,
			       OV8858_LONG_EXPO, (exp_val >> 16) & 0x0F);
	if (ret)
		return ret;

	/* Digital gain : to all MWB channel gains */
	if (dig_gain) {
		ret = ov8858_write_reg(client, OV8858_16BIT,
				OV8858_MWB_RED_GAIN_H, dig_gain);
		if (ret)
			return ret;

		ret = ov8858_write_reg(client, OV8858_16BIT,
				OV8858_MWB_GREEN_GAIN_H, dig_gain);
		if (ret)
			return ret;

		ret = ov8858_write_reg(client, OV8858_16BIT,
				OV8858_MWB_BLUE_GAIN_H, dig_gain);
		if (ret)
			return ret;
	}

	/* set global gain */
	return ov8858_write_reg(client, OV8858_8BIT, OV8858_AGC_ADJ, gain);
}

static int ov8858_set_exposure(struct v4l2_subdev *sd, int exposure, int gain,
				int dig_gain)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	const struct ov8858_resolution *res;
	u16 hts, vts;
	int ret;

	mutex_lock(&dev->input_lock);

	/* Validate exposure:  cannot exceed 16bit value */
	exposure = clamp_t(int, exposure, 0, OV8858_MAX_EXPOSURE_VALUE);

	/* Validate gain: must not exceed maximum 8bit value */
	gain = clamp_t(int, gain, 0, OV8858_MAX_GAIN_VALUE);

	/* Validate digital gain: must not exceed 12 bit value*/
	dig_gain = clamp_t(int, dig_gain, 0, OV8858_MWB_GAIN_MAX);

	/* Group hold is valid only if sensor is streaming. */
	if (dev->streaming) {
		ret = ov8858_write_reg_array(client, ov8858_param_hold);
		if (ret)
			goto out;
	}

	res = &dev->curr_res_table[dev->fmt_idx];
	hts = res->fps_options[dev->fps_index].pixels_per_line;
	vts = res->fps_options[dev->fps_index].lines_per_frame;

	ret = __ov8858_set_exposure(sd, exposure, gain, dig_gain, &hts, &vts);
	if (ret)
		goto out;

	/* Updated the device variable. These are the current values. */
	dev->gain = gain;
	dev->exposure = exposure;
	dev->digital_gain = dig_gain;

out:
	/* Group hold launch - delayed launch */
	if (dev->streaming)
		ret = ov8858_write_reg_array(client, ov8858_param_update);


	mutex_unlock(&dev->input_lock);

	return ret;
}

static int ov8858_s_exposure(struct v4l2_subdev *sd,
			     struct atomisp_exposure *exposure)
{
	return ov8858_set_exposure(sd, exposure->integration_time[0],
				exposure->gain[0], exposure->gain[1]);
}

static int ov8858_g_priv_int_data(struct v4l2_subdev *sd,
				  struct v4l2_private_int_data *priv)
{
	u32 size;
	/* TODO: Need to add reading of OTP data here */
	void *b = NULL; /*le24l042cs_read(v4l2_get_subdevdata(sd), &size);*/
	int r = 0;

	if (!b)
		return -EIO;

	if (copy_to_user(priv->data, b, min_t(__u32, priv->size, size)))
		r = -EFAULT;

	priv->size = size;
	kfree(b);

	return r;
}

static int __ov8858_init(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	if (dev->sensor_id == OV8858_ID_DEFAULT)
		return 0;

	/* Sets the default FPS */
	dev->fps_index = 0;
	return ov8858_write_reg_array(client, ov8858_BasicSettings);
}

static int ov8858_init(struct v4l2_subdev *sd, u32 val)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	ret = __ov8858_init(sd);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static void ov8858_uninit(struct v4l2_subdev *sd)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	dev->exposure = 0;
	dev->gain     = 0;
	dev->digital_gain = 0;
}

static long ov8858_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
	switch (cmd) {
	case ATOMISP_IOC_S_EXPOSURE:
		return ov8858_s_exposure(sd, (struct atomisp_exposure *)arg);
	case ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA:
		return ov8858_g_priv_int_data(sd, arg);
	default:
		return -EINVAL;
	}
	return 0;
}

static int power_up(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	int ret;

	/* Enable power */
	ret = dev->platform_data->power_ctrl(sd, 1);
	if (ret)
		goto fail_power;

	/* Enable clock */
	ret = dev->platform_data->flisclk_ctrl(sd, 1);
	if (ret)
		goto fail_clk;

	/* Release reset */
	ret = dev->platform_data->gpio_ctrl(sd, 1);
	if (ret)
		goto fail_gpio;

	/* Minumum delay is 8192 clock cycles before first i2c transaction,
	 * which is 1.37 ms at the lowest allowed clock rate 6 MHz */
	usleep_range(2000, 2500);
	return 0;

fail_gpio:
	dev->platform_data->gpio_ctrl(sd, 0);
fail_clk:
	dev->platform_data->flisclk_ctrl(sd, 0);
fail_power:
	dev->platform_data->power_ctrl(sd, 0);
	dev_err(&client->dev, "Sensor power-up failed\n");

	return ret;
}

static int power_down(struct v4l2_subdev *sd)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	ret = dev->platform_data->flisclk_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "flisclk failed\n");

	ret = dev->platform_data->gpio_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "Failed to set reset line off\n");

	ret = dev->platform_data->power_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "vprog failed.\n");

	return ret;
}

static int __ov8858_s_power(struct v4l2_subdev *sd, int on)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	int ret, r;

	if (on == 0) {
		ov8858_uninit(sd);
		ret = power_down(sd);
		if (dev->vcm_driver && dev->vcm_driver->power_down) {
			r = dev->vcm_driver->power_down(sd);
			if (ret == 0)
				ret = r;
		}
	} else {
		ret = power_up(sd);
		if (ret)
			power_down(sd);
		if (dev->vcm_driver && dev->vcm_driver->power_up) {
			ret = dev->vcm_driver->power_up(sd);
			if (ret) {
				power_down(sd);
				return ret;
			}
		}
		return __ov8858_init(sd);
	}

	return ret;
}

static int ov8858_s_power(struct v4l2_subdev *sd, int on)
{
	int ret;
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	mutex_lock(&dev->input_lock);
	ret = __ov8858_s_power(sd, on);
	mutex_unlock(&dev->input_lock);

	/*
	 * FIXME: Compatibility with old behaviour: return to preview
	 * when the device is power cycled.
	 */
	if (!ret && on)
		v4l2_ctrl_s_ctrl(dev->run_mode, ATOMISP_RUN_MODE_PREVIEW);

	return ret;
}

static int ov8858_g_chip_ident(struct v4l2_subdev *sd,
			       struct v4l2_dbg_chip_ident *chip)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	if (!chip)
		return -EINVAL;

	v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_OV8858, 0);

	return 0;
}

/* Return value of the specified register, first try getting it from
 * the register list and if not found, get from the sensor via i2c.
 */
static int ov8858_get_register(struct v4l2_subdev *sd, int reg,
			       const struct ov8858_reg *reglist)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	const struct ov8858_reg *next;
	u16 val;

	/* Try if the values are in the register list */
	for (next = reglist; next->type != OV8858_TOK_TERM; next++) {
		if (next->type != OV8858_8BIT) {
			dev_err(&client->dev, "register not 8-bit\n");
			return -ENXIO;
		}
		if (next->sreg == reg)
			return next->val;
	}

	/* If not, read from sensor */
	if (ov8858_read_reg(client, OV8858_8BIT, reg, &val)) {
		dev_err(&client->dev, "failed to read register 0x%04X\n", reg);
		return -EIO;
	}

	return val;
}

static int ov8858_get_register_16bit(struct v4l2_subdev *sd, int reg,
				     const struct ov8858_reg *reglist,
				     unsigned int *value)
{
	int high, low;
	high = ov8858_get_register(sd, reg, reglist);
	if (high < 0)
		return high;

	low = ov8858_get_register(sd, reg + 1, reglist);
	if (low < 0)
		return low;

	*value = ((u8) high << 8) | (u8) low;
	return 0;
}

static int __ov8858_get_pll1_values(struct v4l2_subdev *sd,
				    int *value,
				    const struct ov8858_reg *reglist)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	unsigned int prediv_idx;
	unsigned int multiplier;
	unsigned int sys_prediv;
	unsigned int prediv_coef[] = {2, 3, 4, 5, 6, 8, 12, 16};
	int ret;

	ret = ov8858_get_register(sd, OV8858_PLL1_PREDIV0, reglist);

	if (ret < 0)
		return ret;

	if (ret & OV8858_PLL1_PREDIV0_MASK)
		*value /= 2;

	ret = ov8858_get_register(sd, OV8858_PLL1_PREDIV, reglist);

	if (ret < 0)
		return ret;

	prediv_idx = ret & OV8858_PLL1_PREDIV_MASK;
	*value = *value * 2 / prediv_coef[prediv_idx];

	ret = ov8858_get_register_16bit(sd, OV8858_PLL1_MULTIPLIER, reglist,
					&multiplier);
	if (ret < 0)
		return ret;

	*value *= multiplier & OV8858_PLL1_MULTIPLIER_MASK;
	ret = ov8858_get_register(sd, OV8858_PLL1_SYS_PRE_DIV, reglist);

	if (ret < 0)
		return ret;

	sys_prediv = ret & OV8858_PLL1_SYS_PRE_DIV_MASK;
	*value /= (sys_prediv + 3);
	ret = ov8858_get_register(sd, OV8858_PLL1_SYS_DIVIDER, reglist);

	if (ret < 0)
		return ret;

	if (ret & OV8858_PLL1_SYS_DIVIDER_MASK)
		*value /= 2;

	dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);

	return 0;
}

static int __ov8858_get_pll2a_values(struct v4l2_subdev *sd, int *value,
				     const struct ov8858_reg *reglist)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	unsigned int prediv_idx;
	unsigned int multiplier;
	unsigned int prediv_coef[] = {2, 3, 4, 5, 6, 8, 12, 16};
	int ret;

	ret = ov8858_get_register(sd, OV8858_PLL2_PREDIV0, reglist);
	if (ret < 0)
		return ret;

	if (ret & OV8858_PLL2_PREDIV0_MASK)
		*value /= 2;

	ret = ov8858_get_register(sd, OV8858_PLL2_PREDIV, reglist);
	if (ret < 0)
		return ret;

	prediv_idx = (ret & OV8858_PLL2_PREDIV_MASK);
	*value = *value * 2 / prediv_coef[prediv_idx];

	ret = ov8858_get_register_16bit(sd, OV8858_PLL2_MULTIPLIER, reglist,
					&multiplier);
	if (ret < 0)
		return ret;

	*value *= multiplier & OV8858_PLL2_MULTIPLIER_MASK;
	dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);

	return 0;
}
static int __ov8858_get_pll2b_values(struct v4l2_subdev *sd, int *value,
				     const struct ov8858_reg *reglist)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	unsigned int dac_divider;
	int ret;

	ret = ov8858_get_register(sd, OV8858_PLL2_DAC_DIVIDER, reglist);
	if (ret < 0)
		return ret;

	dac_divider = (ret & OV8858_PLL2_DAC_DIVIDER_MASK) + 1;
	*value /= dac_divider;

	dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);

	return 0;
}
static int __ov8858_get_pll2c_values(struct v4l2_subdev *sd, int *value,
				     const struct ov8858_reg *reglist)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	unsigned int sys_pre_div;
	unsigned int sys_divider_idx;
	unsigned int sys_divider_coef[] = {2, 3, 4, 5, 6, 7, 8, 10};
	int ret;

	ret = ov8858_get_register(sd, OV8858_PLL2_SYS_PRE_DIV, reglist);
	if (ret < 0)
		return ret;

	sys_pre_div = (ret & OV8858_PLL2_SYS_PRE_DIV_MASK) + 1;
	*value /= sys_pre_div;

	ret = ov8858_get_register(sd, OV8858_PLL2_SYS_DIVIDER, reglist);
	if (ret < 0)
		return ret;

	sys_divider_idx = ret & OV8858_PLL2_SYS_DIVIDER_MASK;
	*value *= 2 /  sys_divider_coef[sys_divider_idx];

	dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);

	return 0;
}

static int ov8858_get_intg_factor(struct v4l2_subdev *sd,
				  struct camera_mipi_info *info,
				  const struct ov8858_reg *reglist)
{
	const unsigned int ext_clk = 19200000; /* Hz */
	struct atomisp_sensor_mode_data *m = &info->data;
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct device *d = &client->dev;
	const struct ov8858_resolution *res =
				&dev->curr_res_table[dev->fmt_idx];
	unsigned int pll_sclksel1;
	unsigned int pll_sclksel2;
	unsigned int sys_pre_div;
	unsigned int sclk_pdiv;
	unsigned int sclk = ext_clk;
	int ret;

	memset(&info->data, 0, sizeof(info->data));

	ret = ov8858_get_register(sd, OV8858_PLL_SCLKSEL1, reglist);
	if (ret < 0)
		return ret;

	dev_dbg(d, "%s: OV8858_PLL_SCLKSEL1: 0x%02x\n", __func__, ret);
	pll_sclksel1 = ret & OV8858_PLL_SCLKSEL1_MASK;

	ret = ov8858_get_register(sd, OV8858_PLL_SCLKSEL2, reglist);
	if (ret < 0)
		return ret;

	dev_dbg(d, "%s: OV8858_PLL_SCLKSEL2: 0x%02x\n", __func__, ret);
	pll_sclksel2 = ret & OV8858_PLL_SCLKSEL2_MASK;

	if (pll_sclksel2) {
		ret = __ov8858_get_pll2a_values(sd, &sclk, reglist);
		if (ret < 0)
			return ret;
		ret = __ov8858_get_pll2b_values(sd, &sclk, reglist);
		if (ret < 0)
			return ret;
	} else if (pll_sclksel1) {
		ret = __ov8858_get_pll2a_values(sd, &sclk, reglist);
		if (ret < 0)
			return ret;
		ret = __ov8858_get_pll2c_values(sd, &sclk, reglist);
		if (ret < 0)
			return ret;
	} else {
		ret = __ov8858_get_pll1_values(sd, &sclk, reglist);
		if (ret < 0)
			return ret;
	}

	ret = ov8858_get_register(sd, OV8858_SRB_HOST_INPUT_DIS, reglist);
	if (ret < 0)
		return ret;

	dev_dbg(d, "%s: OV8858_SRB_HOST_INPUT_DIS: 0x%02x\n", __func__, ret);

	sys_pre_div = ret & OV8858_SYS_PRE_DIV_MASK;
	sys_pre_div >>= OV8858_SYS_PRE_DIV_OFFSET;

	if (sys_pre_div == 1)
		sclk /= 2;
	else if (sys_pre_div == 2)
		sclk /= 4;

	sclk_pdiv = ret & OV8858_SCLK_PDIV_MASK;
	sclk_pdiv >>= OV8858_SCLK_PDIV_OFFSET;

	if (sclk_pdiv > 1)
		sclk /= sclk_pdiv;

	dev_dbg(d, "%s: sclk: %d\n", __func__, sclk);

	m->vt_pix_clk_freq_mhz = sclk;

	/* HTS and VTS */
	m->frame_length_lines =
			res->fps_options[dev->fps_index].lines_per_frame;
	m->line_length_pck = res->fps_options[dev->fps_index].pixels_per_line;

	m->coarse_integration_time_min = 0;
	m->coarse_integration_time_max_margin = OV8858_INTEGRATION_TIME_MARGIN;

	/* OV Sensor do not use fine integration time. */
	m->fine_integration_time_min = 0;
	m->fine_integration_time_max_margin = 0;

	/*
	 * read_mode indicate whether binning is used for calculating
	 * the correct exposure value from the user side. So adapt the
	 * read mode values accordingly.
	 */
	m->read_mode = res->bin_factor_x ?
		OV8858_READ_MODE_BINNING_ON : OV8858_READ_MODE_BINNING_OFF;

	ret = ov8858_get_register(sd, OV8858_H_INC_ODD, res->regs);
	if (ret < 0)
		return ret;
	m->binning_factor_x = (ret + 1) / 2;

	ret = ov8858_get_register(sd, OV8858_V_INC_ODD, res->regs);
	if (ret < 0)
		return ret;
	m->binning_factor_y = (ret + 1) / 2;

	/* Get the cropping and output resolution to ISP for this mode. */
	ret =  ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_START_H,
		res->regs, &m->crop_horizontal_start);
	if (ret)
		return ret;

	ret = ov8858_get_register_16bit(sd, OV8858_VERTICAL_START_H,
		res->regs, &m->crop_vertical_start);
	if (ret)
		return ret;

	ret = ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_END_H,
		res->regs, &m->crop_horizontal_end);
	if (ret)
		return ret;

	ret = ov8858_get_register_16bit(sd, OV8858_VERTICAL_END_H,
		res->regs, &m->crop_vertical_end);
	if (ret)
		return ret;

	ret = ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_OUTPUT_SIZE_H,
		res->regs, &m->output_width);
	if (ret)
		return ret;

	return ov8858_get_register_16bit(sd, OV8858_VERTICAL_OUTPUT_SIZE_H,
		res->regs, &m->output_height);
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
/* tune this value so that the DVS resolutions get selected properly,
 * but make sure 16:9 does not match 4:3.
 */
#define LARGEST_ALLOWED_RATIO_MISMATCH 500
static int distance(struct ov8858_resolution const *res, const u32 w,
		    const u32 h)
{
	unsigned int w_ratio = ((res->width<<13)/w);
	unsigned int h_ratio = ((res->height<<13)/h);
	int match   = abs(((w_ratio<<13)/h_ratio) - ((int)8192));

	if ((w_ratio < (int)8192) ||
	    (h_ratio < (int)8192) || (match > LARGEST_ALLOWED_RATIO_MISMATCH))
		return -1;

	return w_ratio + h_ratio;
}

/*
 * Returns the nearest higher resolution index.
 * @w: width
 * @h: height
 * matching is done based on enveloping resolution and
 * aspect ratio. If the aspect ratio cannot be matched
 * to any index, -1 is returned.
 */
static int nearest_resolution_index(struct v4l2_subdev *sd, int w, int h)
{
	int i;
	int idx = -1;
	int dist;
	int fps_diff;
	int min_fps_diff = INT_MAX;
	int min_dist = INT_MAX;
	const struct ov8858_resolution *tmp_res = NULL;
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	for (i = 0; i < dev->entries_curr_table; i++) {
		tmp_res = &dev->curr_res_table[i];
		dist = distance(tmp_res, w, h);
		if (dist == -1)
			continue;
		if (dist < min_dist) {
			min_dist = dist;
			idx = i;
		}
		if (dist == min_dist) {
			fps_diff = __ov8858_min_fps_diff(dev->fps,
						tmp_res->fps_options);
			if (fps_diff < min_fps_diff) {
				min_fps_diff = fps_diff;
				idx = i;
			}
		}
	}
	return idx;
}

static int __ov8858_try_mbus_fmt(struct v4l2_subdev *sd,
				 struct v4l2_mbus_framefmt *fmt)
{
	int idx;
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	if (!fmt)
		return -EINVAL;

	if ((fmt->width > OV8858_RES_WIDTH_MAX) ||
	    (fmt->height > OV8858_RES_HEIGHT_MAX)) {
		fmt->width = OV8858_RES_WIDTH_MAX;
		fmt->height = OV8858_RES_HEIGHT_MAX;
	} else {
		idx = nearest_resolution_index(sd, fmt->width, fmt->height);

		/*
		 * nearest_resolution_index() doesn't return smaller
		 * resolutions. If it fails, it means the requested resolution
		 * is higher than we can support. Fallback to highest possible
		 * resolution in this case.
		 */
		if (idx == -1)
			idx = dev->entries_curr_table - 1;

		fmt->width = dev->curr_res_table[idx].width;
		fmt->height = dev->curr_res_table[idx].height;
	}

	fmt->code = V4L2_MBUS_FMT_SBGGR10_1X10;
	return 0;
}

static int ov8858_try_mbus_fmt(struct v4l2_subdev *sd,
			       struct v4l2_mbus_framefmt *fmt)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	int r;

	mutex_lock(&dev->input_lock);
	r = __ov8858_try_mbus_fmt(sd, fmt);
	mutex_unlock(&dev->input_lock);

	return r;
}

static int ov8858_s_mbus_fmt(struct v4l2_subdev *sd,
			     struct v4l2_mbus_framefmt *fmt)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct camera_mipi_info *ov8858_info = NULL;
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	const struct ov8858_resolution *res;
	int ret;

	ov8858_info = v4l2_get_subdev_hostdata(sd);
	if (ov8858_info == NULL)
		return -EINVAL;

	mutex_lock(&dev->input_lock);

	ret = __ov8858_try_mbus_fmt(sd, fmt);
	if (ret)
		goto out;

	dev->fmt_idx = nearest_resolution_index(sd, fmt->width, fmt->height);
	if (dev->fmt_idx == -1) {
		ret = -EINVAL;
		goto out;
	}
	res = &dev->curr_res_table[dev->fmt_idx];

	/* Adjust the FPS selection based on the resolution selected */
	dev->fps_index = __ov8858_nearest_fps_index(dev->fps, res->fps_options);
	dev->fps = res->fps_options[dev->fps_index].fps;
	dev->regs = res->fps_options[dev->fps_index].regs;
	if (!dev->regs)
		dev->regs = res->regs;

	ret = ov8858_write_reg_array(client, dev->regs);
	if (ret)
		goto out;

	dev->pixels_per_line = res->fps_options[dev->fps_index].pixels_per_line;
	dev->lines_per_frame = res->fps_options[dev->fps_index].lines_per_frame;

	ret = __ov8858_set_exposure(sd, dev->exposure, dev->gain,
				    dev->digital_gain, &dev->pixels_per_line,
				    &dev->lines_per_frame);
	if (ret)
		goto out;

	ret = ov8858_get_intg_factor(sd, ov8858_info, dev->regs);

out:
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int ov8858_g_mbus_fmt(struct v4l2_subdev *sd,
			     struct v4l2_mbus_framefmt *fmt)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	if (!fmt)
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	fmt->width = dev->curr_res_table[dev->fmt_idx].width;
	fmt->height = dev->curr_res_table[dev->fmt_idx].height;
	fmt->code = V4L2_MBUS_FMT_SBGGR10_1X10;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int ov8858_detect(struct i2c_client *client, u16 *id)
{
	struct i2c_adapter *adapter = client->adapter;
	u16 id_hi = 0;
	u16 id_low = 0;
	int ret;
	/* i2c check */
	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C))
		return -ENODEV;

	ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_CHIP_ID_HIGH, &id_hi);
	if (ret)
		return ret;
	ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_CHIP_ID_LOW, &id_low);
	if (ret)
		return ret;
	*id = (id_hi << 8) | id_low;

	dev_info(&client->dev, "%s: chip_id = 0x%4.4x\n", __func__, *id);
	if (*id != OV8858_CHIP_ID)
		return -ENODEV;

	/* Stream off now. */
	return ov8858_write_reg(client, OV8858_8BIT, OV8858_STREAM_MODE, 0);
}

static void __ov8858_print_timing(struct v4l2_subdev *sd)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u16 width = dev->curr_res_table[dev->fmt_idx].width;
	u16 height = dev->curr_res_table[dev->fmt_idx].height;

	dev_dbg(&client->dev, "Dump imx timing in stream on:\n");
	dev_dbg(&client->dev, "width: %d:\n", width);
	dev_dbg(&client->dev, "height: %d:\n", height);
	dev_dbg(&client->dev, "pixels_per_line: %d:\n", dev->pixels_per_line);
	dev_dbg(&client->dev, "line per frame: %d:\n", dev->lines_per_frame);
	dev_dbg(&client->dev, "pix freq: %d:\n", dev->vt_pix_clk_freq_mhz);
	dev_dbg(&client->dev, "init fps: %d:\n", dev->vt_pix_clk_freq_mhz /
		dev->pixels_per_line / dev->lines_per_frame);
	dev_dbg(&client->dev, "HBlank: %d nS:\n",
		1000 * (dev->pixels_per_line - width) /
		(dev->vt_pix_clk_freq_mhz / 1000000));
	dev_dbg(&client->dev, "VBlank: %d uS:\n",
		(dev->lines_per_frame - height) * dev->pixels_per_line /
		(dev->vt_pix_clk_freq_mhz / 1000000));
}

/*
 * ov8858 stream on/off
 */
static int ov8858_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	if (enable) {
		__ov8858_print_timing(sd);
		ret = ov8858_write_reg_array(client, ov8858_streaming);
		if (ret != 0) {
			dev_err(&client->dev, "write_reg_array err\n");
			mutex_unlock(&dev->input_lock);
			return ret;
		}
		dev->streaming = 1;
	} else {
		ret = ov8858_write_reg_array(client, ov8858_soft_standby);
		if (ret != 0) {
			dev_err(&client->dev, "write_reg_array err\n");
			mutex_unlock(&dev->input_lock);
			return ret;
		}
		dev->streaming = 0;
		dev->fps_index = 0;
		dev->fps = 0;
	}
	mutex_unlock(&dev->input_lock);

	return 0;
}

/*
 * ov8858 enum frame size, frame intervals
 */
static int ov8858_enum_framesizes(struct v4l2_subdev *sd,
				  struct v4l2_frmsizeenum *fsize)
{
	unsigned int index = fsize->index;
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	mutex_lock(&dev->input_lock);
	if (index >= dev->entries_curr_table) {
		mutex_unlock(&dev->input_lock);
		return -EINVAL;
	}

	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
	fsize->discrete.width = dev->curr_res_table[index].width;
	fsize->discrete.height = dev->curr_res_table[index].height;
	fsize->reserved[0] = dev->curr_res_table[index].used;
	mutex_unlock(&dev->input_lock);
	return 0;
}

static int ov8858_enum_frameintervals(struct v4l2_subdev *sd,
				      struct v4l2_frmivalenum *fival)
{
	unsigned int index = fival->index;
	int i;
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	mutex_lock(&dev->input_lock);
	/* since the isp will donwscale the resolution to the right size,
	  * find the nearest one that will allow the isp to do so
	  * important to ensure that the resolution requested is padded
	  * correctly by the requester, which is the atomisp driver in
	  * this case.
	  */
	i = nearest_resolution_index(sd, fival->width, fival->height);

	if (i == -1)
		i = dev->entries_curr_table - 1;

	/* Check if this index is supported */
	if (index >
	    __ov8858_get_max_fps_index(dev->curr_res_table[i].fps_options))
		goto out;
	fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
	fival->discrete.numerator = 1;
	fival->discrete.denominator =
			dev->curr_res_table[i].fps_options[index].fps;
	mutex_unlock(&dev->input_lock);
	return 0;
out:
	mutex_unlock(&dev->input_lock);
	return -EINVAL;
}

static int ov8858_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned int index,
				enum v4l2_mbus_pixelcode *code)
{
	*code = V4L2_MBUS_FMT_SBGGR10_1X10;
	return 0;
}

static int __update_ov8858_device_settings(struct ov8858_device *dev,
					   u16 sensor_id)
{
	if (sensor_id == OV8858_CHIP_ID)
		dev->vcm_driver = &ov8858_vcms[OV8858_SUNNY];
	else
		return -ENODEV;

	return dev->vcm_driver->init(&dev->sd);
}

static int ov8858_s_config(struct v4l2_subdev *sd,
			   int irq, void *pdata)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u16 sensor_id;
	int ret;

	if (pdata == NULL)
		return -ENODEV;

	dev->platform_data = pdata;

	mutex_lock(&dev->input_lock);

	if (dev->platform_data->platform_init) {
		ret = dev->platform_data->platform_init(client);
		if (ret) {
			mutex_unlock(&dev->input_lock);
			dev_err(&client->dev, "ov8858 platform init err\n");
			return ret;
		}
	}

	ret = __ov8858_s_power(sd, 1);
	if (ret) {
		dev_err(&client->dev, "ov8858 power-up err.\n");
		mutex_unlock(&dev->input_lock);
		return ret;
	}

	ret = dev->platform_data->csi_cfg(sd, 1);
	if (ret)
		goto fail_csi_cfg;

	/* config & detect sensor */
	ret = ov8858_detect(client, &sensor_id);
	if (ret) {
		dev_err(&client->dev, "ov8858_detect err s_config.\n");
		goto fail_detect;
	}

	dev->sensor_id = sensor_id;

	/* Resolution settings depend on sensor type and platform */
	ret = __update_ov8858_device_settings(dev, dev->sensor_id);
	if (ret)
		goto fail_detect;

	/* power off sensor */
	ret = __ov8858_s_power(sd, 0);

	mutex_unlock(&dev->input_lock);
	if (ret)
		dev_err(&client->dev, "ov8858 power-down err.\n");

	return ret;

fail_detect:
	dev->platform_data->csi_cfg(sd, 0);
fail_csi_cfg:
	__ov8858_s_power(sd, 0);
	if (dev->platform_data->platform_deinit)
		dev->platform_data->platform_deinit();
	mutex_unlock(&dev->input_lock);
	dev_err(&client->dev, "sensor power-gating failed\n");
	return ret;
}

static int
ov8858_enum_mbus_code(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		      struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->index)
		return -EINVAL;
	code->code = V4L2_MBUS_FMT_SBGGR10_1X10;

	return 0;
}

static int
ov8858_enum_frame_size(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		       struct v4l2_subdev_frame_size_enum *fse)
{
	int index = fse->index;
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	mutex_lock(&dev->input_lock);
	if (index >= dev->entries_curr_table) {
		mutex_unlock(&dev->input_lock);
		return -EINVAL;
	}

	fse->min_width = dev->curr_res_table[index].width;
	fse->min_height = dev->curr_res_table[index].height;
	fse->max_width = dev->curr_res_table[index].width;
	fse->max_height = dev->curr_res_table[index].height;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static struct v4l2_mbus_framefmt *
__ov8858_get_pad_format(struct ov8858_device *sensor,
			struct v4l2_subdev_fh *fh, unsigned int pad,
			enum v4l2_subdev_format_whence which)
{
	if (which == V4L2_SUBDEV_FORMAT_TRY)
		return v4l2_subdev_get_try_format(fh, pad);

	return &sensor->format;
}

static int
ov8858_get_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		      struct v4l2_subdev_format *fmt)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	fmt->format = *__ov8858_get_pad_format(dev, fh, fmt->pad, fmt->which);

	return 0;
}

static int
ov8858_set_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		      struct v4l2_subdev_format *fmt)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct v4l2_mbus_framefmt *format =
			__ov8858_get_pad_format(dev, fh, fmt->pad, fmt->which);

	*format = fmt->format;

	return 0;
}

static int ov8858_s_ctrl(struct v4l2_ctrl *ctrl)
{
	struct ov8858_device *dev = container_of(
		ctrl->handler, struct ov8858_device, ctrl_handler);
	struct i2c_client *client = v4l2_get_subdevdata(&dev->sd);

	/* input_lock is taken by the control framework, so it
	 * doesn't need to be taken here.
	 */

	/* We only handle V4L2_CID_RUN_MODE for now. */
	switch (ctrl->id) {
	case V4L2_CID_RUN_MODE:
		switch (ctrl->val) {
		case ATOMISP_RUN_MODE_VIDEO:
			dev->curr_res_table = ov8858_res_video;
			dev->entries_curr_table = ARRAY_SIZE(ov8858_res_video);
			break;
		case ATOMISP_RUN_MODE_STILL_CAPTURE:
			dev->curr_res_table = ov8858_res_still;
			dev->entries_curr_table = ARRAY_SIZE(ov8858_res_still);
			break;
		default:
			dev->curr_res_table = ov8858_res_preview;
			dev->entries_curr_table =
					ARRAY_SIZE(ov8858_res_preview);
		}

		dev->fmt_idx = 0;
		dev->fps_index = 0;

		return 0;
	case V4L2_CID_TEST_PATTERN:
		return ov8858_write_reg(client, OV8858_16BIT,
					OV8858_TEST_PATTERN_REG, ctrl->val);
	case V4L2_CID_FOCUS_ABSOLUTE:
		if (dev->vcm_driver && dev->vcm_driver->t_focus_abs)
			return dev->vcm_driver->t_focus_abs(&dev->sd,
							    ctrl->val);
	default:
		dev_err(&client->dev, "%s: Error: Invalid ctrl: 0x%X\n",
			__func__, ctrl->id);
		return -EINVAL;
	}
}

static int ov8858_g_ctrl(struct v4l2_ctrl *ctrl)
{
	struct ov8858_device *dev = container_of(
		ctrl->handler, struct ov8858_device, ctrl_handler);
	int r_odd, r_even;

	switch (ctrl->id) {
	case V4L2_CID_FOCUS_STATUS: {
		if (dev->vcm_driver && dev->vcm_driver->q_focus_status)
			return dev->vcm_driver->q_focus_status(
						&dev->sd, &(ctrl->val));
	}
	case V4L2_CID_BIN_FACTOR_HORZ:
		r_odd = ov8858_get_register(&dev->sd, OV8858_H_INC_ODD,
					dev->curr_res_table[dev->fmt_idx].regs);
		if (r_odd < 0)
			return r_odd;
		r_even = ov8858_get_register(&dev->sd, OV8858_H_INC_EVEN,
					dev->curr_res_table[dev->fmt_idx].regs);
		if (r_even < 0)
			return r_even;
		ctrl->val = fls(r_odd + (r_even)) - 2;
		return 0;

	case V4L2_CID_BIN_FACTOR_VERT: {
		r_odd = ov8858_get_register(&dev->sd, OV8858_V_INC_ODD,
					dev->curr_res_table[dev->fmt_idx].regs);
		if (r_odd < 0)
			return r_odd;
		r_even = ov8858_get_register(&dev->sd, OV8858_V_INC_EVEN,
					dev->curr_res_table[dev->fmt_idx].regs);
		if (r_even < 0)
			return r_even;
		ctrl->val = fls(r_odd + (r_even)) - 2;
		return 0;
	}
	default: {
		return -EINVAL;
	}
	}

	return 0;
}

static int
ov8858_g_frame_interval(struct v4l2_subdev *sd,
			struct v4l2_subdev_frame_interval *interval)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	const struct ov8858_resolution *res =
				&dev->curr_res_table[dev->fmt_idx];

	mutex_lock(&dev->input_lock);
	interval->interval.denominator = res->fps_options[dev->fps_index].fps;
	interval->interval.numerator = 1;
	mutex_unlock(&dev->input_lock);
	return 0;
}

static int __ov8858_s_frame_interval(struct v4l2_subdev *sd,
				    struct v4l2_subdev_frame_interval *interval)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	const struct ov8858_resolution *res =
				&dev->curr_res_table[dev->fmt_idx];
	struct camera_mipi_info *info = NULL;
	unsigned int fps_index;
	int ret = 0;
	int fps;

	info = v4l2_get_subdev_hostdata(sd);
	if (info == NULL)
		return -EINVAL;

	if (!interval->interval.numerator)
		interval->interval.numerator = 1;

	fps = interval->interval.denominator / interval->interval.numerator;

	/* No need to proceed further if we are not streaming */
	if (!dev->streaming) {
		/* Save the new FPS and use it while selecting setting */
		dev->fps = fps;
		return 0;
	}

	 /* Ignore if we are already using the required FPS. */
	if (fps == res->fps_options[dev->fps_index].fps)
		return 0;

	fps_index = __ov8858_nearest_fps_index(fps, res->fps_options);

	if (res->fps_options[fps_index].regs &&
	    res->fps_options[fps_index].regs != dev->regs) {
		dev_err(&client->dev,
			"Sensor is streaming, can't apply new configuration\n");
		return -EBUSY;
	}

	dev->fps_index = fps_index;
	dev->fps = res->fps_options[dev->fps_index].fps;

	/* Update the new frametimings based on FPS */
	dev->pixels_per_line =
		res->fps_options[dev->fps_index].pixels_per_line;
	dev->lines_per_frame =
		res->fps_options[dev->fps_index].lines_per_frame;

	/* update frametiming. Conside the curren exposure/gain as well */
	ret = __ov8858_set_exposure(sd, dev->exposure, dev->gain,
	      dev->digital_gain, &dev->pixels_per_line, &dev->lines_per_frame);
	if (ret)
		return ret;

	/* Update the new values so that user side knows the current settings */
	ret = ov8858_get_intg_factor(sd, info, dev->regs);
	if (ret)
		return ret;

	interval->interval.denominator = res->fps_options[dev->fps_index].fps;
	interval->interval.numerator = 1;
	__ov8858_print_timing(sd);

	return ret;
}

static int ov8858_s_frame_interval(struct v4l2_subdev *sd,
				   struct v4l2_subdev_frame_interval *interval)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	ret = __ov8858_s_frame_interval(sd, interval);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int ov8858_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
	struct ov8858_device *dev = to_ov8858_sensor(sd);

	mutex_lock(&dev->input_lock);
	*frames = dev->curr_res_table[dev->fmt_idx].skip_frames;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static const struct v4l2_subdev_sensor_ops ov8858_sensor_ops = {
	.g_skip_frames	= ov8858_g_skip_frames,
};

static const struct v4l2_ctrl_ops ctrl_ops = {
	.s_ctrl = ov8858_s_ctrl,
	.g_volatile_ctrl = ov8858_g_ctrl,
};

static const struct v4l2_subdev_video_ops ov8858_video_ops = {
	.s_stream = ov8858_s_stream,
	.enum_framesizes = ov8858_enum_framesizes,
	.enum_frameintervals = ov8858_enum_frameintervals,
	.enum_mbus_fmt = ov8858_enum_mbus_fmt,
	.try_mbus_fmt = ov8858_try_mbus_fmt,
	.g_mbus_fmt = ov8858_g_mbus_fmt,
	.s_mbus_fmt = ov8858_s_mbus_fmt,
	.g_frame_interval = ov8858_g_frame_interval,
	.s_frame_interval = ov8858_s_frame_interval,
};

static const struct v4l2_subdev_core_ops ov8858_core_ops = {
	.g_chip_ident = ov8858_g_chip_ident,
	.queryctrl = v4l2_subdev_queryctrl,
	.g_ctrl = v4l2_subdev_g_ctrl,
	.s_ctrl = v4l2_subdev_s_ctrl,
	.s_power = ov8858_s_power,
	.ioctl = ov8858_ioctl,
	.init = ov8858_init,
};

static const struct v4l2_subdev_pad_ops ov8858_pad_ops = {
	.enum_mbus_code = ov8858_enum_mbus_code,
	.enum_frame_size = ov8858_enum_frame_size,
	.get_fmt = ov8858_get_pad_format,
	.set_fmt = ov8858_set_pad_format,
};

static const struct v4l2_subdev_ops ov8858_ops = {
	.core = &ov8858_core_ops,
	.video = &ov8858_video_ops,
	.pad = &ov8858_pad_ops,
	.sensor = &ov8858_sensor_ops,
};

static const struct media_entity_operations ov_entity_ops = {
	.link_setup = NULL,
};

static int ov8858_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct ov8858_device *dev = to_ov8858_sensor(sd);
	if (dev->platform_data->platform_deinit)
		dev->platform_data->platform_deinit();

	media_entity_cleanup(&dev->sd.entity);
	v4l2_ctrl_handler_free(&dev->ctrl_handler);
	dev->platform_data->csi_cfg(sd, 0);
	v4l2_device_unregister_subdev(sd);
	kfree(dev);

	return 0;
}

static const char * const ctrl_run_mode_menu[] = {
	NULL,
	"Video",
	"Still capture",
	"Continuous capture",
	"Preview",
};

static const struct v4l2_ctrl_config ctrl_run_mode = {
	.ops = &ctrl_ops,
	.id = V4L2_CID_RUN_MODE,
	.name = "run mode",
	.type = V4L2_CTRL_TYPE_MENU,
	.min = 1,
	.def = 4,
	.max = 4,
	.qmenu = ctrl_run_mode_menu,
};

static const struct v4l2_ctrl_config ctrls[] = {
	{
		.ops = &ctrl_ops,
		.id = V4L2_CID_EXPOSURE_ABSOLUTE,
		.name = "Absolute exposure",
		.type = V4L2_CTRL_TYPE_MENU,
		.max = 0xffff,
		.qmenu = ctrl_run_mode_menu,
	}, {
		.ops = &ctrl_ops,
		.id = V4L2_CID_TEST_PATTERN,
		.name = "Test pattern",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.step = 1,
		.max = 0xffff,
	}, {
		.ops = &ctrl_ops,
		.id = V4L2_CID_FOCUS_ABSOLUTE,
		.name = "Focus absolute",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.step = 1,
		.max = OV8858_MAX_FOCUS_POS,
	}, {
		/* This one is junk: see the spec for proper use of this CID. */
		.ops = &ctrl_ops,
		.id = V4L2_CID_FOCUS_STATUS,
		.name = "Focus status",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.step = 1,
		.max = 100,
		.flags = V4L2_CTRL_FLAG_READ_ONLY | V4L2_CTRL_FLAG_VOLATILE,
	}, {
		/* This is crap. For compatibility use only. */
		.ops = &ctrl_ops,
		.id = V4L2_CID_FOCAL_ABSOLUTE,
		.name = "Focal lenght",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.min = (OV8858_FOCAL_LENGTH_NUM << 16) |
		       OV8858_FOCAL_LENGTH_DEM,
		.max = (OV8858_FOCAL_LENGTH_NUM << 16) |
		       OV8858_FOCAL_LENGTH_DEM,
		.step = 1,
		.def = (OV8858_FOCAL_LENGTH_NUM << 16) |
		       OV8858_FOCAL_LENGTH_DEM,
		.flags = V4L2_CTRL_FLAG_READ_ONLY,
	}, {
		/* This one is crap, too. For compatibility use only. */
		.ops = &ctrl_ops,
		.id = V4L2_CID_FNUMBER_ABSOLUTE,
		.name = "F-number",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.min = (OV8858_F_NUMBER_DEFAULT_NUM << 16) |
		       OV8858_F_NUMBER_DEM,
		.max = (OV8858_F_NUMBER_DEFAULT_NUM << 16) |
		       OV8858_F_NUMBER_DEM,
		.step = 1,
		.def = (OV8858_F_NUMBER_DEFAULT_NUM << 16) |
		       OV8858_F_NUMBER_DEM,
		.flags = V4L2_CTRL_FLAG_READ_ONLY,
	}, {
		/*
		 * The most utter crap. _Never_ use this, even for
		 * compatibility reasons!
		 */
		.ops = &ctrl_ops,
		.id = V4L2_CID_FNUMBER_RANGE,
		.name = "F-number range",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.min = (OV8858_F_NUMBER_DEFAULT_NUM << 24) |
		       (OV8858_F_NUMBER_DEM << 16) |
		       (OV8858_F_NUMBER_DEFAULT_NUM << 8) |
		       OV8858_F_NUMBER_DEM,
		.max = (OV8858_F_NUMBER_DEFAULT_NUM << 24) |
		       (OV8858_F_NUMBER_DEM << 16) |
		       (OV8858_F_NUMBER_DEFAULT_NUM << 8) |
		       OV8858_F_NUMBER_DEM,
		.step = 1,
		.def = (OV8858_F_NUMBER_DEFAULT_NUM << 24) |
		       (OV8858_F_NUMBER_DEM << 16) |
		       (OV8858_F_NUMBER_DEFAULT_NUM << 8) |
		       OV8858_F_NUMBER_DEM,
		.flags = V4L2_CTRL_FLAG_READ_ONLY,
	}, {
		.ops = &ctrl_ops,
		.id = V4L2_CID_BIN_FACTOR_HORZ,
		.name = "Horizontal binning factor",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.max = OV8858_BIN_FACTOR_MAX,
		.step = 1,
		.flags = V4L2_CTRL_FLAG_READ_ONLY | V4L2_CTRL_FLAG_VOLATILE,
	}, {
		.ops = &ctrl_ops,
		.id = V4L2_CID_BIN_FACTOR_VERT,
		.name = "Vertical binning factor",
		.type = V4L2_CTRL_TYPE_INTEGER,
		.max = OV8858_BIN_FACTOR_MAX,
		.step = 1,
		.flags = V4L2_CTRL_FLAG_READ_ONLY | V4L2_CTRL_FLAG_VOLATILE,
	}
};

static int ov8858_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct ov8858_device *dev;
	unsigned int i;
	int ret;

	/* allocate sensor device & init sub device */
	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev) {
		dev_err(&client->dev, "%s: out of memory\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&dev->input_lock);

	dev->i2c_id = id->driver_data;
	dev->fmt_idx = 0;
	dev->sensor_id = OV_ID_DEFAULT;
	dev->vcm_driver = &ov8858_vcms[OV8858_ID_DEFAULT];

	v4l2_i2c_subdev_init(&(dev->sd), client, &ov8858_ops);

	if (client->dev.platform_data) {
		ret = ov8858_s_config(&dev->sd, client->irq,
				      client->dev.platform_data);
		if (ret)
			goto out_free;
	}

	/*
	 * sd->name is updated with sensor driver name by the v4l2.
	 * change it to sensor name in this case.
	 */
	snprintf(dev->sd.name, sizeof(dev->sd.name), "%s%x %d-%04x",
		 OV_SUBDEV_PREFIX, dev->sensor_id,
		 i2c_adapter_id(client->adapter), client->addr);

	dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	dev->pad.flags = MEDIA_PAD_FL_SOURCE;
	dev->format.code = V4L2_MBUS_FMT_SBGGR10_1X10;
	dev->sd.entity.ops = &ov_entity_ops;
	dev->sd.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;

	ret = v4l2_ctrl_handler_init(&dev->ctrl_handler, ARRAY_SIZE(ctrls) + 1);
	if (ret) {
		ov8858_remove(client);
		return ret;
	}

	dev->run_mode = v4l2_ctrl_new_custom(&dev->ctrl_handler,
					     &ctrl_run_mode, NULL);

	for (i = 0; i < ARRAY_SIZE(ctrls); i++)
		v4l2_ctrl_new_custom(&dev->ctrl_handler, &ctrls[i], NULL);

	if (dev->ctrl_handler.error) {
		ov8858_remove(client);
		return dev->ctrl_handler.error;
	}

	/* Use same lock for controls as for everything else. */
	dev->ctrl_handler.lock = &dev->input_lock;
	dev->sd.ctrl_handler = &dev->ctrl_handler;
	v4l2_ctrl_handler_setup(&dev->ctrl_handler);

	ret = media_entity_init(&dev->sd.entity, 1, &dev->pad, 0);
	if (ret) {
		ov8858_remove(client);
		return ret;
	}

	return 0;

out_free:
	v4l2_device_unregister_subdev(&dev->sd);
	kfree(dev);
	return ret;
}

static const struct i2c_device_id ov8858_id[] = {
	{OV8858_NAME, 0},
	{}
};

MODULE_DEVICE_TABLE(i2c, ov8858_id);

static struct i2c_driver ov8858_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = OV8858_NAME,
	},
	.probe = ov8858_probe,
	.remove = ov8858_remove,
	.id_table = ov8858_id,
};

static __init int ov8858_init_mod(void)
{
	int ret;
	ret = i2c_add_driver(&ov8858_driver);
	return ret;
}

static __exit void ov8858_exit_mod(void)
{
	i2c_del_driver(&ov8858_driver);
}

module_init(ov8858_init_mod);
module_exit(ov8858_exit_mod);

MODULE_DESCRIPTION("A low-level driver for Omnivision OV8858 sensors");
MODULE_LICENSE("GPL");
