/*
 * Copyright (c) 2013--2014 Intel Corporation. All Rights Reserved.
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

#include <linux/delay.h>
#include <linux/device.h>
#include <linux/dma-attrs.h>
#include <linux/intel_mid_pm.h>
#include <linux/iommu.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>
#include <linux/string.h>

#include <media/css2600-isys.h>
#include <media/v4l2-subdev.h>
#include <media/videobuf2-core.h>

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-mmu.h"
#include "css2600-dma.h"
#include "css2600-isys.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-csi2-2401.h"
#include "css2600-isys-lib.h"
#include "css2600-isys-tpg.h"
#include "css2600-isys-tpg-2401.h"
#include "css2600-isys-video.h"
#include "css2600-regs.h"
#include "css2600-wrapper-2401.h"

/*
 * BEGIN adapted code from drivers/media/platform/omap3isp/isp.c.
 * FIXME: This (in terms of functionality if not code) should be most
 * likely generalised in the framework, and use made optional for
 * drivers.
 */
/*
 * css2600_pipeline_pm_use_count - Count the number of users of a pipeline
 * @entity: The entity
 *
 * Return the total number of users of all video device nodes in the pipeline.
 */
static int css2600_pipeline_pm_use_count(struct media_entity *entity)
{
	struct media_entity_graph graph;
	int use = 0;

	media_entity_graph_walk_start(&graph, entity);

	while ((entity = media_entity_graph_walk_next(&graph))) {
		if (media_entity_type(entity) == MEDIA_ENT_T_DEVNODE)
			use += entity->use_count;
	}

	return use;
}

/*
 * css2600_pipeline_pm_power_one - Apply power change to an entity
 * @entity: The entity
 * @change: Use count change
 *
 * Change the entity use count by @change. If the entity is a subdev update its
 * power state by calling the core::s_power operation when the use count goes
 * from 0 to != 0 or from != 0 to 0.
 *
 * Return 0 on success or a negative error code on failure.
 */
static int css2600_pipeline_pm_power_one(struct media_entity *entity,
					 int change)
{
	struct v4l2_subdev *subdev;
	int ret;

	subdev = media_entity_type(entity) == MEDIA_ENT_T_V4L2_SUBDEV
	       ? media_entity_to_v4l2_subdev(entity) : NULL;

	if (entity->use_count == 0 && change > 0 && subdev != NULL) {
		ret = v4l2_subdev_call(subdev, core, s_power, 1);
		if (ret < 0 && ret != -ENOIOCTLCMD)
			return ret;
	}

	entity->use_count += change;
	WARN_ON(entity->use_count < 0);

	if (entity->use_count == 0 && change < 0 && subdev != NULL)
		v4l2_subdev_call(subdev, core, s_power, 0);

	return 0;
}

/*
 * css2600_pipeline_pm_power - Apply power change to all entities in a pipeline
 * @entity: The entity
 * @change: Use count change
 *
 * Walk the pipeline to update the use count and the power state of all non-node
 * entities.
 *
 * Return 0 on success or a negative error code on failure.
 */
static int css2600_pipeline_pm_power(struct media_entity *entity, int change)
{
	struct media_entity_graph graph;
	struct media_entity *first = entity;
	int ret = 0;

	if (!change)
		return 0;

	media_entity_graph_walk_start(&graph, entity);

	while (!ret && (entity = media_entity_graph_walk_next(&graph)))
		if (media_entity_type(entity) != MEDIA_ENT_T_DEVNODE)
			ret = css2600_pipeline_pm_power_one(entity, change);

	if (!ret)
		return 0;

	media_entity_graph_walk_start(&graph, first);

	while ((first = media_entity_graph_walk_next(&graph))
	       && first != entity)
		if (media_entity_type(first) != MEDIA_ENT_T_DEVNODE)
			css2600_pipeline_pm_power_one(first, -change);

	return ret;
}

/*
 * css2600_pipeline_pm_use - Update the use count of an entity
 * @entity: The entity
 * @use: Use (1) or stop using (0) the entity
 *
 * Update the use count of all entities in the pipeline and power entities on or
 * off accordingly.
 *
 * Return 0 on success or a negative error code on failure. Powering entities
 * off is assumed to never fail. No failure can occur when the use parameter is
 * set to 0.
 */
int css2600_pipeline_pm_use(struct media_entity *entity, int use)
{
	int change = use ? 1 : -1;
	int ret;

	mutex_lock(&entity->parent->graph_mutex);

	/* Apply use count to node. */
	entity->use_count += change;
	WARN_ON(entity->use_count < 0);

	/* Apply power change to connected non-nodes. */
	ret = css2600_pipeline_pm_power(entity, change);
	if (ret < 0)
		entity->use_count -= change;

	mutex_unlock(&entity->parent->graph_mutex);

	return ret;
}

/*
 * css2600_pipeline_link_notify - Link management notification callback
 * @link: The link
 * @flags: New link flags that will be applied
 * @notification: The link's state change notification type (MEDIA_DEV_NOTIFY_*)
 *
 * React to link management on powered pipelines by updating the use count of
 * all entities in the source and sink sides of the link. Entities are powered
 * on or off accordingly.
 *
 * Return 0 on success or a negative error code on failure. Powering entities
 * off is assumed to never fail. This function will not fail for disconnection
 * events.
 */
static int css2600_pipeline_link_notify(struct media_link *link, u32 flags,
					unsigned int notification)
{
	struct media_entity *source = link->source->entity;
	struct media_entity *sink = link->sink->entity;
	int source_use = css2600_pipeline_pm_use_count(source);
	int sink_use = css2600_pipeline_pm_use_count(sink);
	int ret;

	if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
	    !(link->flags & MEDIA_LNK_FL_ENABLED)) {
		/* Powering off entities is assumed to never fail. */
		css2600_pipeline_pm_power(source, -sink_use);
		css2600_pipeline_pm_power(sink, -source_use);
		return 0;
	}

	if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
		(flags & MEDIA_LNK_FL_ENABLED)) {

		ret = css2600_pipeline_pm_power(source, sink_use);
		if (ret < 0)
			return ret;

		ret = css2600_pipeline_pm_power(sink, source_use);
		if (ret < 0)
			css2600_pipeline_pm_power(source, -sink_use);

		return ret;
	}

	return 0;
}
/* END adapted code from drivers/media/platform/omap3isp/isp.c */

struct csi2_config {
	unsigned int nports;
	unsigned int nlanes[CSS2600_ISYS_MAX_CSI2_PORTS];
	unsigned int offsets[CSS2600_ISYS_MAX_CSI2_PORTS];
	unsigned int tpg_offsets[CSS2600_ISYS_MAX_TPGS];
};

struct csi2_config csi2_config_2600 = {
	.nports = 4,
	.nlanes = { 4, 1, 2, 2 },
};

struct csi2_config csi2_config_2401 = {
	.nports = 3,
	.nlanes = { 4, 1, 2 },
	.offsets = { 0x000c0400, 0x000c2400, 0x000c4400 },
};

static void isys_unregister_csi2(struct css2600_isys *isys)
{
	struct csi2_config *cfg = &csi2_config_2600;
	unsigned int i;

	for (i = 0; i < cfg->nports; i++)
		css2600_isys_csi2_cleanup(&isys->csi2[i]);
}

static void isys_unregister_csi2_2401(struct css2600_isys *isys)
{
	struct csi2_config *cfg = &csi2_config_2401;
	unsigned int i;

	for (i = 0; i < cfg->nports; i++) {
		css2600_isys_csi2_2401_cleanup(&isys->csi2[i]);
		css2600_isys_tpg_2401_cleanup(&isys->tpg[i]);
	}
}

static int isys_register_csi2(struct css2600_isys *isys)
{
	struct csi2_config *cfg = &csi2_config_2600;
	unsigned int i;
	int rval;

	BUG_ON(cfg->nports > CSS2600_ISYS_MAX_CSI2_PORTS);

	for (i = 0; i < cfg->nports; i++) {
		int rval = css2600_isys_csi2_init(
			&isys->csi2[i], isys,
			isys->pdata->base + cfg->offsets[i], cfg->nlanes[i],
			i);
		if (rval)
			goto fail;
	}

	return 0;

fail:
	isys_unregister_csi2(isys);
	return rval;
}

static int isys_register_csi2_2401(struct css2600_isys *isys)
{
	struct csi2_config *cfg = &csi2_config_2401;
	unsigned int i;
	int rval;

	BUG_ON(cfg->nports > CSS2600_ISYS_MAX_CSI2_PORTS);

	for (i = 0; i < cfg->nports; i++) {
		int rval = css2600_isys_csi2_2401_init(
			&isys->csi2[i], isys,
			isys->pdata->base + cfg->offsets[i], cfg->nlanes[i],
			i);
		if (rval)
			goto fail;

		rval = css2600_isys_tpg_2401_init(
			&isys->tpg[i], isys,
			isys->pdata->base + cfg->tpg_offsets[i], i);
		if (rval)
			goto fail;

		rval = media_entity_create_link(
			&isys->tpg[i].asd.sd.entity, TPG_PAD_SOURCE,
			&isys->csi2[i].asd.sd.entity, CSI2_PAD_SINK,
			0);
		if (rval)
			goto fail;
	}

	return 0;

fail:
	isys_unregister_csi2(isys);
	return rval;
}

static int isys_register_ext_subdev(struct css2600_isys *isys,
				    struct css2600_isys_subdev_info *sd_info)
{
	struct i2c_adapter *adapter =
		i2c_get_adapter(sd_info->i2c.i2c_adapter_id);
	struct v4l2_subdev *sd;
	unsigned int i;
	int rval;

	dev_info(&isys->adev->dev,
		 "creating new i2c subdev for %s (address %2.2x, bus %d) on port %u\n",
		 sd_info->i2c.board_info.type, sd_info->i2c.board_info.addr,
		 sd_info->i2c.i2c_adapter_id, sd_info->csi2->port);

	if (!adapter) {
		dev_warn(&isys->adev->dev, "can't find adapter\n");
		return -ENOENT;
	}

	if (sd_info->csi2->port >= CSS2600_ISYS_MAX_CSI2_PORTS ||
	    !isys->csi2[sd_info->csi2->port].isys) {
		dev_warn(&isys->adev->dev, "invalid csi2 port %u\n",
			 sd_info->csi2->port);
		rval = -EINVAL;
		goto skip_put_adapter;
	}

	sd = v4l2_i2c_new_subdev_board(&isys->v4l2_dev, adapter,
				       &sd_info->i2c.board_info, 0);

	if (!sd) {
		dev_warn(&isys->adev->dev, "can't create new i2c subdev\n");
		rval = -EINVAL;
		goto skip_put_adapter;
	}

	v4l2_set_subdev_hostdata(sd, sd_info->csi2);

	for (i = 0; i < sd->entity.num_pads; i++) {
		if (sd->entity.pads[i].flags & MEDIA_PAD_FL_SOURCE)
			break;
	}

	if (i == sd->entity.num_pads) {
		dev_warn(&isys->adev->dev,
			 "no source pad in external entity\n");
		v4l2_device_unregister_subdev(sd);
		rval = -ENOENT;
		goto skip_unregister_subdev;
	}

	rval = media_entity_create_link(
		&sd->entity, i,
		&isys->csi2[sd_info->csi2->port].asd.sd.entity, 0, 0);
	if (rval) {
		dev_warn(&isys->adev->dev, "can't create link\n");
		goto skip_unregister_subdev;
	}

	return 0;

skip_unregister_subdev:
	v4l2_device_unregister_subdev(sd);

skip_put_adapter:
	i2c_put_adapter(adapter);

	return rval;
}

static void isys_register_ext_subdevs(struct css2600_isys *isys)
{
	struct css2600_isys_subdev_pdata *spdata = isys->pdata->spdata;
	struct css2600_isys_subdev_info **sd_info;

	if (!spdata) {
		dev_info(&isys->adev->dev, "no external subdevs found\n");
		return;
	}

	for (sd_info = spdata->subdevs; *sd_info; sd_info++)
		isys_register_ext_subdev(isys, *sd_info);
}

static int isys_register_devices(struct css2600_isys *isys)
{
	int rval;

	isys->media_dev.dev = &isys->adev->dev;
	isys->media_dev.link_notify = css2600_pipeline_link_notify;
	snprintf(isys->media_dev.model, sizeof(isys->media_dev.model),
		 "css%u", isys->pdata->type);
	strlcpy(isys->media_dev.bus_info, CSS2600_BUS_NAME,
		sizeof(isys->media_dev.bus_info));
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

	if (isys->pdata->type == CSS2600_ISYS_TYPE_CSS2401)
		rval = isys_register_csi2_2401(isys);
	else
		rval = isys_register_csi2(isys);
	if (rval) {
		dev_info(&isys->adev->dev, "can't register csi2 devices\n");
		goto out_v4l2_device_unregister;
	}

	isys_register_ext_subdevs(isys);

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

static void isys_unregister_devices(struct css2600_isys *isys)
{
	if (isys->pdata->type == CSS2600_ISYS_TYPE_CSS2401)
		isys_unregister_csi2_2401(isys);
	else
		isys_unregister_csi2(isys);
	v4l2_device_unregister(&isys->v4l2_dev);
	media_device_unregister(&isys->media_dev);
}

#ifdef CONFIG_PM_RUNTIME
static int isys_runtime_pm(int on)
{
	unsigned long timeout;
	u32 reg_value;
	u32 power;

	if (on)
		power = CSS2401_REG_ISPSSPM0_IUNIT_POWER_ON;
	else
		power = CSS2401_REG_ISPSSPM0_IUNIT_POWER_OFF;

	/* writing 0x0 to ISPSSPM0 bit[1:0] to power off the IUNIT */
	reg_value = intel_mid_msgbus_read32(CSS2401_PUNIT_PORT,
					    CSS2401_REG_ISPSSPM0);
	reg_value &= ~CSS2401_REG_ISPSSPM0_ISPSSC_MASK;
	reg_value |= power;
	intel_mid_msgbus_write32(CSS2401_PUNIT_PORT, CSS2401_REG_ISPSSPM0,
				 reg_value);

	/*
	 * There should be no iunit access while power-down is
	 * in progress HW sighting: 4567865
	 */
	timeout = jiffies + msecs_to_jiffies(50);
	while (!time_after(jiffies, timeout)) {
		reg_value = intel_mid_msgbus_read32(CSS2401_PUNIT_PORT,
						    CSS2401_REG_ISPSSPM0);

		/* wait until ISPSSPM0 bit[25:24] shows correct value */
		if ((reg_value >> CSS2401_REG_ISPSSPM0_ISPSSS_SHIFT &
		    ~CSS2401_REG_ISPSSPM0_IUNIT_POWER_MASK) == power)
			return 0;

		usleep_range(100, 150);
	};

	return -EBUSY;
}
#endif /* CONFIG_PM_RUNTIME */

static void isys_remove(struct css2600_bus_device *adev)
{
	struct css2600_isys *isys = css2600_bus_get_drvdata(adev);

	dev_info(&adev->dev, "removed\n");
	isys_unregister_devices(isys);
	isys_runtime_pm(0);
}

static int isys_probe(struct css2600_bus_device *adev)
{
	struct css2600_bus_iommu *aiommu =
		to_css2600_bus_device(&adev->dev)->iommu;
	struct css2600_mmu *mmu = dev_get_drvdata(aiommu->dev);
	struct css2600_mmu_domain *adom;
	struct ia_css_isys_device_cfg_data isys_cfg = { };
	struct css2600_isys *isys;
	int rval = 0;

	/* Has the domain been attached? */
	if (!mmu)
		return -EPROBE_DEFER;

	adom = mmu->dmap->domain->priv;

	if (!css2600_wrapper_init_done())
		return -EPROBE_DEFER;

	isys = devm_kzalloc(&adev->dev, sizeof(*isys), GFP_KERNEL);
	if (!isys)
		return -ENOMEM;

	isys->adev = adev;
	isys->pdata = adev->pdata;

	spin_lock_init(&isys->lock);

	dev_info(&adev->dev, "isys probe %p %p\n", adev, &adev->dev);
	css2600_bus_set_drvdata(adev, isys);

	if (isys->pdata->type == CSS2600_ISYS_TYPE_CSS2401)
		isys->line_align = CSS2600_ISYS_2401_MEM_LINE_ALIGN;
	else
		isys->line_align = 128; /* FIXME! What's this for 2600? */

#if IS_ENABLED(CONFIG_VIDEO_CSS2600_2401)
	rval = isys_runtime_pm(1);
	if (rval) {
		dev_err(&adev->dev, "isys_runtime_pm failed: %d\n", rval);
		return rval;
	}
#endif /* IS_ENABLED(CONFIG_VIDEO_CSS2600_2401) */

	rval = isys_register_devices(isys);
	if (rval)
		goto err_power_off;

	isys_cfg.driver_sys.mmio_base_address = isys->pdata->base;
	isys_cfg.driver_sys.page_table_base_address = adom->pgtbl;
	isys_cfg.driver_sys.firmware_address = lib2401_get_sp_fw(); /* FIXME */
	rval = -ia_css_isys_device_configure(&isys->ssi, &isys_cfg);
	if (rval < 0)
		goto err_remove;

	return 0;

err_remove:
	isys_remove(adev);

err_power_off:
	isys_runtime_pm(0);

	return rval;
}

static void isys_isr(struct css2600_bus_device *adev)
{
	struct css2600_isys *isys = css2600_bus_get_drvdata(adev);
	struct ia_css_isys_resp_info resp;
	struct css2600_isys_pipeline *pipe;
	int rval;

	if (!isys->ssi) {
		dev_dbg(&isys->adev->dev,
			"got interrupt but device not configured yet\n");
		return;
	}

	rval = -ia_css_isys_stream_handle_response(isys->ssi, &resp);
	if (rval < 0) {
		dev_dbg(&adev->dev, "isys_isr: error %d\n", rval);
		return;
	}

	dev_dbg(&adev->dev, "resp type %u\n", resp.type);
	dev_dbg(&adev->dev, "resp error %d\n", resp.error);
	dev_dbg(&adev->dev, "resp stream %u\n", resp.stream_handle);
	dev_dbg(&adev->dev, "resp stream %u\n", resp.stream_handle);

	if (resp.stream_handle >= N_IA_CSS_ISYS_STREAM_SRC) {
		dev_err(&adev->dev, "bad stream handle %u\n",
			resp.stream_handle);
		return;
	}

	pipe = isys->pipes[resp.stream_handle];
	if (!pipe) {
		dev_err(&adev->dev, "no pipeline for stream %u\n",
			resp.stream_handle);
		return;
	}

	switch (resp.type) {
	case IA_CSS_ISYS_RESP_TYPE_STREAM_OPEN_DONE:
		complete(&pipe->stream_open_completion);
		break;
	case IA_CSS_ISYS_RESP_TYPE_STREAM_CLOSE_ACK:
		complete(&pipe->stream_close_completion);
		break;
	case IA_CSS_ISYS_RESP_TYPE_STREAM_START_ACK:
	case IA_CSS_ISYS_RESP_TYPE_STREAM_START_AND_CAPTURE_ACK:
		complete(&pipe->stream_start_completion);
		break;
	case IA_CSS_ISYS_RESP_TYPE_STREAM_STOP_ACK:
		complete(&pipe->stream_stop_completion);
		break;
	case IA_CSS_ISYS_RESP_TYPE_STREAM_CAPTURE_DONE:
		css2600_isys_queue_buf_done(pipe, &resp);
		break;
	default:
		break;
	}
}

static struct css2600_bus_driver isys_driver = {
	.probe = isys_probe,
	.remove = isys_remove,
	.isr = isys_isr,
	.wanted = CSS2600_ISYS_NAME,
	.drv = {
		.name = CSS2600_ISYS_NAME,
		.owner = THIS_MODULE,
	},
};

module_css2600_bus_driver(isys_driver);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel css2600 input system driver");
