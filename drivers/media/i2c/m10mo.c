/*
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
#include <asm/intel-mid.h>
#include <asm/irq.h>
#include <linux/atomisp_platform.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/kernel.h>
#include <linux/kmod.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-chip-ident.h>
#include <media/v4l2-device.h>
#include "m10mo.h"

struct m10mo_resolution {
	unsigned int width;
	unsigned int height;
	unsigned int fps;
};

static const struct m10mo_resolution const m10mo_res_modes[] = {
	{
		.width = 640,
		.height = 480,
		.fps = 30,
	},
	{
		.width = 1280,
		.height = 720,
		.fps = 30,
	}
};

#define M10MO_FORMAT	V4L2_MBUS_FMT_UYVY8_1X16

/*
 * m10mo_read -  I2C read function
 * @reg: combination of size, category and command for the I2C packet
 * @size: desired size of I2C packet
 * @val: read value
 *
 * Returns 0 on success, or else negative errno.
*/

static int m10mo_read(struct v4l2_subdev *sd, u8 len, u8 category, u8 byte, int *val)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	unsigned char data[5];
	struct i2c_msg msg[2];
	unsigned char recv_data[len + 1];
	int ret;

	if (!client->adapter)
		return -ENODEV;

	if (len != 0x01 && len != 0x02 && len != 0x04)	{
		dev_err(&client->dev, "m10mo Wrong data size\n");
		return -EINVAL;
	}

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = sizeof(data);
	msg[0].buf = data;

	data[0] = 5;
	data[1] = M10MO_BYTE_READ;
	data[2] = category;
        data[3] = byte;
        data[4] = len;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = len + 1;
	msg[1].buf = recv_data;

	/* isp firmware becomes stable during this time*/
	usleep_range(200, 200);

	ret = i2c_transfer(client->adapter, msg, 2);

	if (ret == 2) {
		if (len == 0x01)
			*val = recv_data[1];
		else if (len == 0x02)
			*val = recv_data[1] << 8 | recv_data[2];
		else
			*val = recv_data[1] << 24 | recv_data[2] << 16
				| recv_data[3] << 8 | recv_data[4];
	}
	return 0;
	}

/**
 * m10mo_write - I2C command write function
 * @reg: combination of size, category and command for the I2C packet
 * @val: value to write
 *
 * Returns 0 on success, or else negative errno.
 */
static int m10mo_write(struct v4l2_subdev *sd, u8 len, u8 category, u8 byte, int val)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	u8 data[len + 4];
	struct i2c_msg msg;
	int ret;
	const int num_msg = 1;

	if (!client->adapter)
		return -ENODEV;

	if (len != 0x01 && len != 0x02 && len != 0x04) {
		dev_err(&client->dev, "m10mo Wrong data size\n");
		return -EINVAL;
	}

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = sizeof(data);
	msg.buf = data;

	data[0] = msg.len;
	data[1] = M10MO_BYTE_WRITE;
	data[2] = category;
	data[3] = byte;
	data[4] = val;

	/* isp firmware becomes stable during this time*/
	usleep_range(200, 200);

	ret = i2c_transfer(client->adapter, &msg, 1);

	return ret == num_msg ? 0 : -EIO;
}

static int m10mo_memory_write(struct v4l2_subdev *sd, u8 cmd, u16 len, u32 addr, u8 val)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct i2c_msg msg;
	unsigned char data[9];
	int i, ret;

	if (!client->adapter)
		return -ENODEV;

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = sizeof(data);
	msg.buf = data;

	/* high byte goes out first */
	data[0] = 0x00;
	data[1] = cmd;
	data[2] = (u8)((addr >> 24) & 0xFF);
	data[3] = (u8)((addr >> 16) & 0xFF);
	data[4] = (u8)((addr >> 8) & 0xFF);
	data[5] = (u8)(addr & 0xFF);
	data[6] = 0x0;
	data[7] = 0x1;
	data[8] = val;

	usleep_range(200, 200);

	for (i = M10MO_I2C_RETRY; i; i--) {
		ret = i2c_transfer(client->adapter, &msg, 1);
		if (ret == 1) {
			return 0;
		}
		msleep(20);
	}

	return ret;
}

/**
 * m10mo_wait_interrupt - Clear interrupt pending bits and unmask interrupts
 *
 * Before writing desired interrupt value the INT_FACTOR register should
 * be read to clear pending interrupts.
 */

static int m10mo_wait_interrupt(struct v4l2_subdev *sd, u32 timeout)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	dev->irq = 0;

	ret = wait_event_interruptible_timeout(dev->irq_waitq,
					       dev->irq != 0,
					       msecs_to_jiffies(timeout));
	if (ret <= 0) {
		dev_err(&client->dev, "m10mo_wait_interrupt timed out");
		return -ETIMEDOUT;
	}

	ret = m10mo_read(sd, 1, CATEGORY_SYSTEM, SYSTEM_INT_FACTOR,
			 &dev->int_factor);

	return ret;
}

static int m10mo_detect(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct m10mo_version *ver = &dev->ver;
	int ret;

        ret = m10mo_read(sd, 1, CATEGORY_SYSTEM, SYSTEM_CUSTOMER_CODE,
			&ver->customer);
	if (!ret)
		ret = m10mo_read(sd, 1, CATEGORY_SYSTEM, SYSTEM_PROJECT_CODE,
				&ver->project);
	dev_info(&client->dev, "Customer/Project[0x%x/0x%x]", dev->ver.customer,
				dev->ver.project);
	return 0;
}

static int __m10mo_fw_start(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	/* Temporary Fix, Bug in M10MO Firmware */
	ret = m10mo_memory_write(sd, 0x04, 1, 0x13000005, 0x7F);
	if (ret)
		return ret;
	/* Start the Camera firmware */
	ret = m10mo_write(sd, 1, CATEGORY_FLASHROM, FLASH_CAM_START, 0x01);
	if (ret < 0) {
		dev_err(&client->dev, "m10mo i2c failed");
		return ret;
	}

	ret = m10mo_wait_interrupt(sd, M10MO_INIT_TIMEOUT);
	if (ret < 0) {
		dev_err(&client->dev, "m10mo initialization timeout");
		return ret;
	}

	ret = m10mo_detect(sd);
	if (ret)
		return ret;

	dev_info(&client->dev, "ISP Booted Successfully\n");
	return 0;
}

static int m10mo_fw_start(struct v4l2_subdev *sd, u32 val)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret = 0;

	mutex_lock(&dev->input_lock);
	ret = __m10mo_fw_start(sd);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static int m10mo_set_streaming(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret;

	/*Change to Monitor Size (e,g. VGA) */
	ret = m10mo_write(sd, 1, CATEGORY_PARAM, PARAM_MON_SIZE, 0x17);

	ret = m10mo_write(sd, 1, CATEGORY_PARAM, PARAM_MON_FPS, 0x02);
	/* Enable interrupt signal */
	ret = m10mo_write(sd, 1, CATEGORY_SYSTEM, SYSTEM_INT_ENABLE, 0x01);

	/* Go to Monitor mode and output YUV Data */
	ret = m10mo_write(sd, 1, CATEGORY_SYSTEM, SYSTEM_SYSMODE, 0x02);

	dev->streaming = true;

	return 0;
}

static int m10mo_set_suspend(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	dev->streaming = false;
	return 0;
}

static int power_up(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret;

	/**ISP RESET**/
	ret = dev->platform_data->gpio_ctrl(sd, 1);
	if (ret)
		goto fail_gpio;
	return 0;

fail_gpio:
	dev->platform_data->gpio_ctrl(sd, 0);
	return ret;
}

static int power_down(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	ret = dev->platform_data->gpio_ctrl(sd, 0);
	if (ret)
		dev_err(&client->dev, "gpio failed");

	return ret;
}

static int __m10mo_s_power(struct v4l2_subdev *sd, int on)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret = 0;
	int r = 0;

	if (on == 0) {
		ret = power_down(sd);
		if (ret == 0)
			ret = r;
		dev->power = 0;
	} else {
		ret = power_up(sd);
		if (!ret) {
			dev->power = 1;
			return __m10mo_fw_start(sd);
		}
	}

	return ret;
}

static int m10mo_s_power(struct v4l2_subdev *sd, int on)
{
	int ret;
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	mutex_lock(&dev->input_lock);
	ret = __m10mo_s_power(sd, on);
	mutex_unlock(&dev->input_lock);

	return ret;
}

static irqreturn_t m10mo_irq_handler(int irq, void *dev_id)
{
	struct v4l2_subdev *sd = (struct v4l2_subdev *)dev_id;
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	dev->irq = 1;
	wake_up_interruptible(&dev->irq_waitq);

	return IRQ_HANDLED;
}

static int m10mo_setup_irq(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int pin, ret;

	pin = dev->platform_data->gpio_intr_ctrl(sd);

	ret = gpio_to_irq(pin);

	if (ret < 0) {
		dev_err(&client->dev, "Configure gpio to irq failed!\n");
		goto out_free;
	}
	client->irq = ret;

	ret = request_irq(client->irq, m10mo_irq_handler,
			  IRQF_TRIGGER_RISING, M10MO_NAME, sd);
	if (ret < 0) {
		dev_err(&client->dev, "Cannot register IRQ: %d\n", ret);
		goto out_free;
	}
	return 0;
out_free:
	gpio_free(pin);
	return ret;
}

static int m10mo_try_mbus_fmt(struct v4l2_subdev *sd,
				struct v4l2_mbus_framefmt *fmt)
{
	int idx = 0;

	fmt->width = m10mo_res_modes[idx].width;
	fmt->height = m10mo_res_modes[idx].height;

	fmt->code = M10MO_FORMAT;
	return 0;
}

static int m10mo_get_mbus_fmt(struct v4l2_subdev *sd,
				struct v4l2_mbus_framefmt *fmt)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	mutex_lock(&dev->input_lock);

	fmt->width = m10mo_res_modes[dev->fmt_idx].width;
	fmt->height = m10mo_res_modes[dev->fmt_idx].height;
	fmt->code = M10MO_FORMAT;

	mutex_unlock(&dev->input_lock);

	return 0;
}

static int m10mo_set_mbus_fmt(struct v4l2_subdev *sd,
			      struct v4l2_mbus_framefmt *fmt)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret;

	mutex_lock(&dev->input_lock);

	if (dev->streaming) {
		ret = -EBUSY;
		goto out;
	}

	ret = m10mo_try_mbus_fmt(sd, fmt);
out:
	mutex_unlock(&dev->input_lock);
	return ret;
}


static int m10mo_s_config(struct v4l2_subdev *sd,
			    int irq, void *pdata)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;

	if (pdata == NULL)
		return -ENODEV;

	mutex_lock(&dev->input_lock);

	dev->platform_data = pdata;

	init_waitqueue_head(&dev->irq_waitq);

	/* set up irq */
	ret = m10mo_setup_irq(sd);
	if (ret) {
		dev_err(&client->dev, "IRQ err.\n");
		mutex_unlock(&dev->input_lock);
		return ret;
	}

	ret = __m10mo_s_power(sd, 1);
	if (ret) {
		dev_err(&client->dev, "power-up err.\n");
		mutex_unlock(&dev->input_lock);
		return ret;
	}

	ret = dev->platform_data->csi_cfg(sd, 1);
	if (ret)
		goto fail_csi_cfg;

	ret = __m10mo_s_power(sd, 0);
	mutex_unlock(&dev->input_lock);
	if (ret) {
		dev_err(&client->dev, "power-down err.\n");
		return ret;
	}

	return 0;

fail_csi_cfg:
	__m10mo_s_power(sd, 0);
	mutex_unlock(&dev->input_lock);
	dev_err(&client->dev, "External ISP power-gating failed\n");
	return ret;

}

static int m10mo_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret;

	mutex_lock(&dev->input_lock);
	if (enable)
		ret = m10mo_set_streaming(sd);
	else
		ret = m10mo_set_suspend(sd);
	mutex_unlock(&dev->input_lock);
	return ret;
}

static int
m10mo_enum_framesizes(struct v4l2_subdev *sd, struct v4l2_frmsizeenum *fsize)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	if (fsize->index >= ARRAY_SIZE(m10mo_res_modes))
		return -EINVAL;

	mutex_lock(&dev->input_lock);
	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
	fsize->discrete.width = m10mo_res_modes[fsize->index].width;
	fsize->discrete.height = m10mo_res_modes[fsize->index].height;
	mutex_unlock(&dev->input_lock);

	return 0;
}

static int m10mo_enum_mbus_code(struct v4l2_subdev *sd,
				  struct v4l2_subdev_fh *fh,
				  struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->index)
		return -EINVAL;

	code->code = V4L2_MBUS_FMT_UYVY8_1X16;
	return 0;
}

static struct v4l2_mbus_framefmt *
__m10mo_get_pad_format(struct m10mo_device *sensor,
			 struct v4l2_subdev_fh *fh, unsigned int pad,
			 enum v4l2_subdev_format_whence which)
{
	switch (which) {
	case V4L2_SUBDEV_FORMAT_TRY:
		return v4l2_subdev_get_try_format(fh, pad);
	case V4L2_SUBDEV_FORMAT_ACTIVE:
		return &sensor->format;
	default:
		return NULL;
	}
}

static int
m10mo_get_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		       struct v4l2_subdev_format *fmt)
{
	struct m10mo_device *snr = to_m10mo_sensor(sd);
	struct v4l2_mbus_framefmt *format =
			__m10mo_get_pad_format(snr, fh, fmt->pad, fmt->which);

	if (format == NULL)
		return -EINVAL;

	mutex_lock(&snr->input_lock);
	fmt->format = *format;
	mutex_unlock(&snr->input_lock);

	return 0;
}

static int
m10mo_set_pad_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
		       struct v4l2_subdev_format *fmt)
{
	struct m10mo_device *snr = to_m10mo_sensor(sd);
	struct v4l2_mbus_framefmt *format =
			__m10mo_get_pad_format(snr, fh, fmt->pad, fmt->which);

	if (format == NULL)
		return -EINVAL;

	mutex_lock(&snr->input_lock);
	if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE)
		snr->format = fmt->format;
	mutex_unlock(&snr->input_lock);

	return 0;
}

static const struct media_entity_operations m10mo_entity_ops = {
	.link_setup = NULL,
};

static int m10mo_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	if (dev->platform_data->platform_deinit)
		dev->platform_data->platform_deinit();

	media_entity_cleanup(&dev->sd.entity);
	v4l2_device_unregister_subdev(sd);
	free_irq(client->irq, sd);
	kfree(dev);

	return 0;
}

static int m10mo_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
	switch (ctrl->id) {
	case V4L2_CID_LINK_FREQ:
		ctrl->val = M10MO_MIPI_FREQ;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}
static struct v4l2_ctrl_ops m10mo_ctrl_ops = {
	.g_volatile_ctrl = m10mo_g_volatile_ctrl,
};

static const struct v4l2_ctrl_config v4l2_ctrl_link_freq = {
	.ops = &m10mo_ctrl_ops,
	.id = V4L2_CID_LINK_FREQ,
	.name = "Link Frequency",
	.type = V4L2_CTRL_TYPE_INTEGER,
	.min = 1,
	.max = 1500000 * 1000,
	.step = 1,
	.def = 1,
	.flags = V4L2_CTRL_FLAG_VOLATILE | V4L2_CTRL_FLAG_READ_ONLY,
};

static int __m10mo_init_ctrl_handler(struct m10mo_device *dev)
{
	struct v4l2_ctrl_handler *hdl;
	int ret;

	hdl = &dev->ctrl_handler;

	ret = v4l2_ctrl_handler_init(&dev->ctrl_handler, 1);
	if (ret)
		return ret;

	dev->link_freq = v4l2_ctrl_new_custom(&dev->ctrl_handler,
					      &v4l2_ctrl_link_freq,
					      NULL);

	if (dev->link_freq == NULL) {
		v4l2_ctrl_handler_free(&dev->ctrl_handler);
		return dev->ctrl_handler.error;
	}

	dev->sd.ctrl_handler = hdl;

	return 0;
}

static const struct v4l2_subdev_video_ops m10mo_video_ops = {
	.try_mbus_fmt = m10mo_try_mbus_fmt,
	.s_mbus_fmt = m10mo_set_mbus_fmt,
	.g_mbus_fmt = m10mo_get_mbus_fmt,
	.s_stream = m10mo_s_stream,
	.enum_framesizes = m10mo_enum_framesizes,
};

static const struct v4l2_subdev_core_ops m10mo_core_ops = {
	.g_ctrl = v4l2_subdev_g_ctrl,
	.s_ctrl = v4l2_subdev_s_ctrl,
	.s_power = m10mo_s_power,
	.init	= m10mo_fw_start,
};

static const struct v4l2_subdev_pad_ops m10mo_pad_ops = {
	.enum_mbus_code = m10mo_enum_mbus_code,
	.get_fmt = m10mo_get_pad_format,
	.set_fmt = m10mo_set_pad_format,

};

static const struct v4l2_subdev_ops m10mo_ops = {
	.core	= &m10mo_core_ops,
	.pad	= &m10mo_pad_ops,
	.video	= &m10mo_video_ops,
};

static int m10mo_probe(struct i2c_client *client,
				  const struct i2c_device_id *id)
{
	struct m10mo_device *dev;
	struct camera_mipi_info *mipi_info = NULL;
	int ret;

	/* allocate sensor device & init sub device */
	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev) {
		dev_err(&client->dev, "%s: out of memory\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&dev->input_lock);

	v4l2_i2c_subdev_init(&(dev->sd), client, &m10mo_ops);

	if (client->dev.platform_data) {
		ret = m10mo_s_config(&dev->sd, client->irq,
				       client->dev.platform_data);
		if (ret)
			goto out_free;
	}

	mipi_info = v4l2_get_subdev_hostdata(&dev->sd);

	ret = __m10mo_init_ctrl_handler(dev);
	if (ret)
		goto out_free;

	dev->num_lanes = mipi_info->num_lanes;

	dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	dev->pad.flags = MEDIA_PAD_FL_SOURCE;
	dev->sd.entity.ops = &m10mo_entity_ops;
	dev->sd.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
	dev->format.code = V4L2_MBUS_FMT_UYVY8_1X16;

	ret = media_entity_init(&dev->sd.entity, 1, &dev->pad, 0);
	if (ret)
		m10mo_remove(client);
	return ret;

out_free:
	v4l2_device_unregister_subdev(&dev->sd);
	kfree(dev);
	return ret;
}

static const struct i2c_device_id m10mo_id[] = {
	{ M10MO_NAME, 0 },
	{}
};
MODULE_DEVICE_TABLE(i2c, m10mo_id);

static struct i2c_driver m10mo_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = M10MO_NAME,
	},
	.probe = m10mo_probe,
	.remove = m10mo_remove,
	.id_table = m10mo_id,
};

static __init int init_m10mo(void)
{
	return i2c_add_driver(&m10mo_driver);
}

static __exit void exit_m10mo(void)
{
	i2c_del_driver(&m10mo_driver);
}

module_init(init_m10mo);
module_exit(exit_m10mo);

MODULE_DESCRIPTION("M10MO ISP driver");
MODULE_AUTHOR("Kriti Pachhandara <kriti.pachhandara@intel.com>");
MODULE_LICENSE("GPL");








