/*
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

#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>
#include <linux/string.h>

#include <media/videobuf2-core.h>

#include "atomisp.h"
#include "atomisp-bus.h"
#include "atomisp-csi2.h"
#include "atomisp-isys.h"

static unsigned int bxt_nlanes[] = { 4, 1, 2, 2 };

static int isys_open(struct file *file)
{
	struct video_device *vdev = video_devdata(file);
	struct atomisp_isys *isys = video_get_drvdata(vdev);
	int rval;

	return v4l2_fh_open(file);
}

static int isys_release(struct file *file)
{
	struct video_device *vdev = video_devdata(file);
	struct atomisp_isys *isys = video_get_drvdata(vdev);

	v4l2_fh_release(file);

	return 0;
}

const struct v4l2_file_operations atomisp_isys_fops = {
	.owner = THIS_MODULE,
	.open = isys_open,
	.release = isys_release,
	.poll = vb2_fop_poll,
	.mmap = vb2_fop_mmap,
};

static void isys_unregister_csi2(struct atomisp_isys *isys)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(bxt_nlanes); i++)
		atomisp_csi2_cleanup(&isys->csi2[i]);
}

static int isys_register_csi2(struct atomisp_isys *isys)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(bxt_nlanes); i++) {
		int rval = atomisp_csi2_init(
			&isys->csi2[i], isys, isys->pdata->base, bxt_nlanes[i],
			i);
		if (rval) {
			isys_unregister_csi2(isys);
			return rval;
		}
	}

	return 0;
}

static int isys_register_devices(struct atomisp_isys *isys)
{
	int rval;

	isys->media_dev.dev = &isys->adev->dev;
	strlcpy(isys->media_dev.model, "Intel ISP",
		sizeof(isys->media_dev.model));
	strlcpy(isys->v4l2_dev.name, isys->media_dev.model,
		sizeof(isys->v4l2_dev.name));

	rval = media_device_register(&isys->media_dev);
	if (rval < 0) {
		dev_info(&isys->adev->dev, "can't register media device\n");
		return rval;
	}

	isys->v4l2_dev.mdev = &isys->media_dev;

	rval = v4l2_device_register(&isys->adev->dev, &isys->v4l2_dev);
	if (rval < 0) {
		dev_info(&isys->adev->dev, "can't register v4l2 device\n");
		goto out_media_device_unregister;
	}

	rval = isys_register_csi2(isys);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register csi2 devices\n");
		goto out_v4l2_device_unregister;
	}

	rval = v4l2_device_register_subdev_nodes(&isys->v4l2_dev);
	if (rval)
		goto out_isys_unregister_csi2;

	return 0;

out_isys_unregister_csi2:
	isys_unregister_csi2(isys);

out_v4l2_device_unregister:
	v4l2_device_unregister(&isys->v4l2_dev);

out_media_device_unregister:
	media_device_unregister(&isys->media_dev);

	return rval;
}

static void isys_unregister_devices(struct atomisp_isys *isys)
{
	isys_unregister_csi2(isys);
	v4l2_device_unregister(&isys->v4l2_dev);
	media_device_unregister(&isys->media_dev);
}

static int isys_probe(struct atomisp_bus_device *adev)
{
	struct atomisp_isys *isys;

	isys = devm_kzalloc(&adev->dev, sizeof(*isys), GFP_KERNEL);
	if (!isys)
		return -ENOMEM;

	isys->adev = adev;
	isys->pdata = adev->pdata;

	dev_info(&adev->dev, "isys probe %p %p\n", adev, &adev->dev);
	atomisp_bus_set_drvdata(adev, isys);

	return isys_register_devices(isys);
}

static void isys_remove(struct atomisp_bus_device *adev)
{
	struct atomisp_isys *isys = atomisp_bus_get_drvdata(adev);

	dev_info(&adev->dev, "removed\n");
	isys_unregister_devices(isys);
}

static void isys_isr(struct atomisp_bus_device *adev)
{
	struct atomisp_isys *isys = atomisp_bus_get_drvdata(adev);

	dev_info(&adev->dev, "Yeah!\n");
}

static struct atomisp_bus_driver isys_driver = {
	.probe = isys_probe,
	.remove = isys_remove,
	.isr = isys_isr,
	.wanted = ATOMISP_ISYS_NAME,
	.drv = {
		.name = ATOMISP_ISYS_NAME,
		.owner = THIS_MODULE,
	},
};

module_atomisp_bus_driver(isys_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
