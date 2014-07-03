/*
 * Copyright (c) 2014 Intel Corporation. All Rights Reserved.
 *
 * Partially based on m-5mols kernel driver,
 * Copyright (C) 2011 Samsung Electronics Co., Ltd.
 *
 * Partially based on jc_v4l2 kernel driver from http://opensource.samsung.com
 * Copyright (c) 2011, Code Aurora Forum. All rights reserved.
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
 */

#include <linux/atomisp_platform.h>
#include <media/m10mo_atomisp.h>
#include <linux/module.h>
#include "m10mo.h"

int m10mo_set_burst_mode_fw_type2(struct v4l2_subdev *sd, unsigned int val)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);

	switch (val) {
	case EXT_ISP_BURST_CAPTURE_CTRL_START:
		dev->capture_mode = M10MO_CAPTURE_MODE_ZSL_BURST;
		break;
	case EXT_ISP_BURST_CAPTURE_CTRL_STOP:
		dev->capture_mode = M10MO_CAPTURE_MODE_ZSL_NORMAL;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static int m10mo_set_monitor_mode(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	int ret;
	u32 val;
	int mode = M10MO_GET_RESOLUTION_MODE(dev->fw_type);

	dev_info(&client->dev, "%s mode: %d Width: %d, height: %d, cmd: 0x%x\n",
		__func__, dev->mode, dev->curr_res_table[dev->fmt_idx].width,
		dev->curr_res_table[dev->fmt_idx].height,
		dev->curr_res_table[dev->fmt_idx].command);

	/* Check if m10mo already streaming @ required resolution */
	ret = m10mo_readb(sd, CATEGORY_PARAM,  PARAM_MON_SIZE, &val);
	if (ret)
		goto out;

	/* If mode is monitor mode and size same, do not configure again*/
	if (dev->mode == M10MO_MONITOR_MODE &&
		val == dev->curr_res_table[dev->fmt_idx].command)
		return 0;

	/*Change to Monitor Size (e,g. VGA) */
	ret = m10mo_writeb(sd, CATEGORY_PARAM, PARAM_MON_SIZE,
			dev->curr_res_table[dev->fmt_idx].command);
	if (ret)
		goto out;

	if (mode == M10MO_RESOLUTION_MODE_0) {
		/* TODO: FPS setting must be changed */
		ret = m10mo_writeb(sd, CATEGORY_PARAM, PARAM_MON_FPS, 0x02);
		if (ret)
			goto out;

		ret = m10mo_writeb(sd, CATEGORY_PARAM, 0x67, 0x00);
		if (ret)
			goto out;
	}

	if (dev->run_mode == CI_MODE_VIDEO)
		ret = m10mo_writeb(sd, CATEGORY_PARAM,
				   MONITOR_TYPE, MONITOR_VIDEO);
	else
		ret = m10mo_writeb(sd, CATEGORY_PARAM,
				   MONITOR_TYPE, MONITOR_PREVIEW);

	/* Enable metadata */
	ret = m10mo_writeb(sd, CATEGORY_PARAM, MON_METADATA_SUPPORT_CTRL,
			   MON_METADATA_SUPPORT_CTRL_EN);
	if (ret)
		goto out;
	ret = m10mo_writeb(sd, CATEGORY_PARAM, MPO_FORMAT_META, 1);
	if (ret)
		goto out;

	/* Enable interrupt signal */
	ret = m10mo_writeb(sd, CATEGORY_SYSTEM, SYSTEM_INT_ENABLE, 0x01);
	if (ret)
		goto out;
	/* Go to Monitor mode and output YUV Data */
	ret = m10mo_request_mode_change(sd, M10MO_MONITOR_MODE);
	if (ret)
		goto out;

	return 0;
out:
	dev_err(&client->dev, "Streaming failed %d\n", ret);
	return ret;
}

static int m10mo_set_burst_capture(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	const struct m10mo_resolution *capture_res;
	int mode = M10MO_GET_RESOLUTION_MODE(dev->fw_type);
	int idx;
	int ret;

	dev_info(&client->dev, "%s mode: %d width: %d, height: %d, cmd: 0x%x\n",
		__func__, dev->mode, dev->curr_res_table[dev->fmt_idx].width,
		dev->curr_res_table[dev->fmt_idx].height,
		dev->curr_res_table[dev->fmt_idx].command);

	/* Exit from normal monitor mode. */
	ret = m10mo_request_mode_change(sd, M10MO_PARAMETER_MODE);
	if (ret)
		return ret;
	ret = m10mo_wait_mode_change(sd, M10MO_PARAMETER_MODE, M10MO_INIT_TIMEOUT);
	if (ret)
		return ret;

	/* Configure burst capture resolution.
	 * Map burst capture size to monitor size. Burst capture uses
	 * monitor parameters.
	 */
	capture_res = &resolutions[mode][M10MO_MODE_CAPTURE_INDEX]
		[dev->capture_res_idx];
	idx = get_resolution_index(
		resolutions[mode][M10MO_MODE_PREVIEW_INDEX],
		resolutions_sizes[mode][M10MO_MODE_PREVIEW_INDEX],
		capture_res->width, capture_res->height);
	if (idx == -1) {
		dev_err(&client->dev, "Unsupported burst capture size %dx%d\n",
			capture_res->width, capture_res->height);
		return -EINVAL;
	}
	ret = m10mo_writeb(sd, CATEGORY_PARAM, PARAM_MON_SIZE,
		resolutions[mode][M10MO_MODE_PREVIEW_INDEX][idx]
		.command);
	if (ret)
		return ret;

	/* Start burst capture. */
	ret = m10mo_request_mode_change(sd, M10MO_BURST_CAPTURE_MODE);

	return ret;
}

int m10mo_set_run_mode_fw_type2(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret;

	/*
	 * Handle RAW capture mode separately irrespective of the run mode
	 * being configured. Start the RAW capture right away.
	 */
	if (dev->capture_mode == M10MO_CAPTURE_MODE_ZSL_RAW) {
		/*
		 * As RAW capture is done from a command line tool, we are not
		 * restarting the preview after the RAW capture. So it is ok
		 * to reset the RAW capture mode here because the next RAW
		 * capture has to start from the Set format onwards.
		 */
		dev->capture_mode = M10MO_CAPTURE_MODE_ZSL_NORMAL;
		return m10mo_set_zsl_raw_capture(sd);
	}

	switch (dev->run_mode) {
	case CI_MODE_STILL_CAPTURE:
		ret = m10mo_set_still_capture(sd);
		break;
	default:
		/* Start still capture if M10MO is already in monitor mode. */
		if (dev->mode == M10MO_MONITOR_MODE) {
			if (dev->capture_mode ==
			    M10MO_CAPTURE_MODE_ZSL_BURST)
				ret = m10mo_set_burst_capture(sd);
			else
				ret = m10mo_set_still_capture(sd);
		} else {
			ret = m10mo_set_monitor_mode(sd);
		}
	}
	return ret;
}

static int __m10mo_monitor_mode_set(struct v4l2_subdev *sd)
{
	int ret;

	ret = m10mo_request_mode_change(sd, M10MO_MONITOR_MODE);
	if (ret)
		return ret;

	ret = m10mo_wait_mode_change(sd, M10MO_MONITOR_MODE,
				     M10MO_INIT_TIMEOUT);
	if (ret > 0)
		ret = 0;
	return ret;
}

int m10mo_streamoff_fw_type2(struct v4l2_subdev *sd)
{
	struct m10mo_device *dev = to_m10mo_sensor(sd);
	int ret = 0;

	if (dev->mode == M10MO_SINGLE_CAPTURE_MODE) {
		/* Exit capture mode and back to monitor mode */
		ret = m10mo_writeb(sd, CATEGORY_SYSTEM, SYSTEM_INT_ENABLE, 0x01);
		if (ret)
			goto out;
		ret = __m10mo_monitor_mode_set(sd);
		if (ret)
			return ret;
	} else if (dev->mode == M10MO_BURST_CAPTURE_MODE) {
		/* Exit burst capture mode. */
		ret = __m10mo_param_mode_set(sd);
		if (ret)
			goto out;
		/* Set monitor type as Preview. */
		ret = m10mo_writeb(sd, CATEGORY_PARAM,
				  MONITOR_TYPE, MONITOR_PREVIEW);
		if (ret)
			goto out;
		/* Restart monitor mode. */
		ret = m10mo_writeb(sd, CATEGORY_SYSTEM, SYSTEM_INT_ENABLE, 0x01);
		if (ret)
			return ret;
		ret = __m10mo_monitor_mode_set(sd);
	}
out:
	return ret;
}

const struct m10mo_fw_ops fw_type2_ops = {
	.set_run_mode   = m10mo_set_run_mode_fw_type2,
	.set_burst_mode = m10mo_set_burst_mode_fw_type2,
	.stream_off     = m10mo_streamoff_fw_type2,
};
