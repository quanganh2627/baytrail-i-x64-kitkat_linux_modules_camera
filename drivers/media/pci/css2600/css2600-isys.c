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

#include "css2600.h"
#include "css2600-bus.h"
#include "css2600-isys.h"
#include "css2600-isys-csi2.h"
#include "css2600-isys-video.h"

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
};

static struct csi2_config *isys_get_csi2_config(struct css2600_isys *isys)
{
	switch (isys->pdata->type) {
	case CSS2600_ISYS_TYPE_CSS2401:
		return &csi2_config_2401;
		break;
	case CSS2600_ISYS_TYPE_CSS2600:
		return &csi2_config_2600;
		break;
	default:
		BUG();
	}
}

static void isys_unregister_csi2(struct css2600_isys *isys)
{
	struct csi2_config *cfg = isys_get_csi2_config(isys);
	unsigned int i;

	for (i = 0; i < cfg->nports; i++) {
		css2600_isys_csi2_cleanup(&isys->csi2[i]);
		if (isys->pdata->type != CSS2600_ISYS_TYPE_CSS2401)
			continue;
		css2600_isys_tpg_cleanup(&isys->tpg[i]);
	}
}

static int isys_register_csi2(struct css2600_isys *isys)
{
	struct csi2_config *cfg = isys_get_csi2_config(isys);
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

		/* In 2401 the TPGs come with the CSI-2 receivers. */
		if (isys->pdata->type != CSS2600_ISYS_TYPE_CSS2401)
			continue;

		rval = css2600_isys_tpg_init(
			&isys->tpg[i], isys,
			isys->pdata->base + cfg->tpg_offsets[i], i);
		if (rval)
			goto fail;

		rval = media_entity_create_link(&isys->tpg[i].asd.sd.entity,
						TPG_PAD_SOURCE,
						&isys->csi2[i].asd.sd.entity,
						CSI2_PAD_SINK, 0);
		if (rval)
			goto fail;
	}

	return 0;

fail:
	isys_unregister_csi2(isys);
	return rval;
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

static void isys_unregister_devices(struct css2600_isys *isys)
{
	isys_unregister_csi2(isys);
	v4l2_device_unregister(&isys->v4l2_dev);
	media_device_unregister(&isys->media_dev);
}

static int isys_probe(struct css2600_bus_device *adev)
{
	struct css2600_isys *isys;

	isys = devm_kzalloc(&adev->dev, sizeof(*isys), GFP_KERNEL);
	if (!isys)
		return -ENOMEM;

	isys->adev = adev;
	isys->pdata = adev->pdata;

	dev_info(&adev->dev, "isys probe %p %p\n", adev, &adev->dev);
	css2600_bus_set_drvdata(adev, isys);

	return isys_register_devices(isys);
}

static void isys_remove(struct css2600_bus_device *adev)
{
	struct css2600_isys *isys = css2600_bus_get_drvdata(adev);

	dev_info(&adev->dev, "removed\n");
	isys_unregister_devices(isys);
}

static void isys_isr(struct css2600_bus_device *adev)
{
	dev_info(&adev->dev, "Yeah!\n");
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
