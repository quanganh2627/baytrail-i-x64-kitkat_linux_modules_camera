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

#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/v4l2-ioctl.h>

#include "css2600-isys.h"
#include "css2600-isys-video.h"

static const struct css2600_isys_pixelformat isys_pfmts[] = {
	{ V4L2_PIX_FMT_SBGGR10, 16, 10, V4L2_MBUS_FMT_SBGGR10_1X10 },
	{ V4L2_PIX_FMT_SGBRG10, 16, 10, V4L2_MBUS_FMT_SGBRG10_1X10 },
	{ V4L2_PIX_FMT_SGRBG10, 16, 10, V4L2_MBUS_FMT_SGRBG10_1X10 },
	{ V4L2_PIX_FMT_SRGGB10, 16, 10, V4L2_MBUS_FMT_SRGGB10_1X10 },
	{ }
};

static int video_open(struct file *file)
{
	struct css2600_isys_video *av = video_drvdata(file);
	int rval;

	rval = v4l2_fh_open(file);
	if (rval)
		return rval;

	rval = css2600_pipeline_pm_use(&av->vdev.entity, 1);
	if (rval)
		goto out_v4l2_fh_release;

	return 0;

out_v4l2_fh_release:
	v4l2_fh_release(file);

	return rval;
}

static int video_release(struct file *file)
{
	struct css2600_isys_video *av = video_drvdata(file);

	vb2_fop_release(file);

	css2600_pipeline_pm_use(&av->vdev.entity, 0);

	return 0;
}

const struct css2600_isys_pixelformat *css2600_isys_get_pixelformat(
	struct css2600_isys_video *av, uint32_t pixelformat)
{
	struct media_pad *pad = av->vdev.entity.links[0].source;
	const uint32_t *supported_codes =
		to_css2600_isys_subdev(
			media_entity_to_v4l2_subdev(pad->entity))
		->supported_codes[pad->index];
	const struct css2600_isys_pixelformat *pfmt;

	for (pfmt = isys_pfmts; pfmt->bpp; pfmt++) {
		unsigned int i;

		if (pfmt->pixelformat != pixelformat)
			continue;

		for (i = 0; supported_codes[i]; i++) {
			if (pfmt->code == supported_codes[i])
				return pfmt;
		}
	}

	/* Not found. Get the default, i.e. the first defined one. */
	for (pfmt = isys_pfmts; pfmt->bpp; pfmt++) {
		if (pfmt->code == *supported_codes)
			return pfmt;
	}

	BUG();
}

static int vidioc_querycap(struct file *file, void *fh,
			   struct v4l2_capability *cap)
{
	struct css2600_isys_video *av = video_drvdata(file);

	strlcpy(cap->driver, CSS2600_ISYS_NAME, sizeof(cap->driver));
	strlcpy(cap->card, av->isys->media_dev.model, sizeof(cap->card));
	strlcpy(cap->bus_info, av->isys->media_dev.bus_info,
		sizeof(cap->bus_info));
	cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
	cap->device_caps = cap->capabilities;

	return 0;
}

static int vidioc_g_fmt_vid_cap(struct file *file, void *fh,
				struct v4l2_format *fmt)
{
	struct css2600_isys_video *av = video_drvdata(file);

	mutex_lock(&av->mutex);
	fmt->fmt.pix = av->pix;
	mutex_unlock(&av->mutex);

	return 0;
}

static const struct css2600_isys_pixelformat *__vidioc_try_fmt_vid_cap(
	struct css2600_isys_video *av, struct v4l2_pix_format *pix)
{
	const struct css2600_isys_pixelformat *pfmt =
		css2600_isys_get_pixelformat(av, pix->pixelformat);

	pix->pixelformat = pfmt->pixelformat;
	pix->bytesperline = max(
		pix->bytesperline, pix->width * DIV_ROUND_UP(pfmt->bpp, 8));
	pix->sizeimage = pix->bytesperline * pix->height;

	return pfmt;
}

static int vidioc_s_fmt_vid_cap(struct file *file, void *fh,
				struct v4l2_format *fmt)
{
	struct css2600_isys_video *av = video_drvdata(file);
	int rval = 0;

	mutex_lock(&av->mutex);

	if (av->streaming) {
		rval = -EBUSY;
		goto out;
	}

	av->pfmt = __vidioc_try_fmt_vid_cap(av, &fmt->fmt.pix);
	av->pix = fmt->fmt.pix;

out:
	mutex_unlock(&av->mutex);

	return rval;
}

static int vidioc_try_fmt_vid_cap(struct file *file, void *fh,
				  struct v4l2_format *fmt)
{
	struct css2600_isys_video *av = video_drvdata(file);

	__vidioc_try_fmt_vid_cap(av, &fmt->fmt.pix);

	return 0;
}

static int link_validate(struct media_link *link)
{
	struct v4l2_subdev_format fmt = { 0 };
	struct v4l2_subdev *sd =
		media_entity_to_v4l2_subdev(link->source->entity);
	struct css2600_isys_video *av =
		container_of(link->sink, struct css2600_isys_video, pad);
	int rval;

	fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
	fmt.pad = link->source->index;
	rval = v4l2_subdev_call(sd, pad, get_fmt, NULL, &fmt);
	if (rval)
		return rval;

	if (fmt.format.width != av->pix.width
	    || fmt.format.height != av->pix.height
	    || fmt.format.code != av->pfmt->code)
		return -EINVAL;

	return 0;
}

int css2600_isys_video_set_streaming(struct css2600_isys_video *av,
				     unsigned int state)
{
	struct media_entity_graph graph;
	struct media_entity *entity, *entity2;
	unsigned int entities = 0;
	unsigned int i;
	int rval = 0;

	mutex_lock(&av->mutex);

	if (state == av->streaming)
		goto out_unlock;

	if (state) {
		av->ip.external = NULL;

		rval = media_entity_pipeline_start(&av->vdev.entity,
						   &av->ip.pipe);
		if (rval < 0)
			goto out_unlock;

		if (!av->ip.external) {
			dev_err(&av->isys->adev->dev,
				"no external entity set! Driver bug?\n");
			goto out_media_entity_pipeline_stop;
		}
		dev_dbg(&av->isys->adev->dev, "external entity %s\n",
			av->ip.external->name);

		av->ip.continuous = true;

		/*
		 * Any stream from the test pattern generators
		 * requires kicking them again to receive the next
		 * frame. Store the information whether this is
		 * necessary to the pipeline.
		 */
		for (i = 0; i < CSS2600_ISYS_MAX_TPGS &&
			     av->isys->tpg[i].isys; i++) {
			if (av->isys->tpg[i].asd.sd.entity.pipe != &av->ip.pipe)
				continue;

			av->ip.continuous = false;
			break;
		}

		dev_dbg(&av->isys->adev->dev, "continuous %d\n",
			av->ip.continuous);
	}

	media_entity_graph_walk_start(&graph, &av->vdev.entity);

	while ((entity = media_entity_graph_walk_next(&graph))) {
		struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);

		dev_dbg(&av->isys->adev->dev, "entity %s\n", entity->name);

		/*
		 * Is the entity external or not? This is a little bit
		 * hackish but entirely local and not intrusive at
		 * all. The first of such entity is the "sensor".
		 */
		if (entity->ops != av->isys->csi2[0].asd.sd.entity.ops)
			break;

		/* We don't support non-linear pipelines yet. */
		if (media_entity_type(entity) != MEDIA_ENT_T_V4L2_SUBDEV) {
			rval = -EINVAL;
			goto out_media_entity_stop_streaming;
		}

		if (entity != av->ip.external) {
			dev_dbg(&av->isys->adev->dev, "s_stream %s\n",
				entity->name);
			rval = v4l2_subdev_call(sd, video, s_stream, state);
		}
		if (!state)
			continue;
		if (rval)
			goto out_media_entity_stop_streaming;

		if (entity->id >= sizeof(entities) << 3) {
			WARN_ON(1);
			goto out_media_entity_stop_streaming;
		}

		if (entity != av->ip.external)
			entities |= 1 << entity->id;
	}

	dev_dbg(&av->isys->adev->dev, "s_stream %s\n", av->ip.external->name);
	rval = v4l2_subdev_call(media_entity_to_v4l2_subdev(av->ip.external),
				video, s_stream, state);
	if (rval && state)
		goto out_media_entity_pipeline_stop;

	if (!state)
		media_entity_pipeline_stop(&av->vdev.entity);

	av->streaming = state;

	mutex_unlock(&av->mutex);
	return 0;

out_media_entity_stop_streaming:
	media_entity_graph_walk_start(&graph, &av->vdev.entity);

	while (state && (entity2 = media_entity_graph_walk_next(&graph))
		&& entity2 != entity) {
		struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity2);

		if (!(entity2->id << 1 & entities))
			continue;

		v4l2_subdev_call(sd, video, s_stream, 0);
	}

out_media_entity_pipeline_stop:
	if (state)
		media_entity_pipeline_stop(&av->vdev.entity);

out_unlock:
	mutex_unlock(&av->mutex);

	return rval;
}

static const struct v4l2_ioctl_ops ioctl_ops = {
	.vidioc_querycap = vidioc_querycap,
	.vidioc_g_fmt_vid_cap = vidioc_g_fmt_vid_cap,
	.vidioc_s_fmt_vid_cap = vidioc_s_fmt_vid_cap,
	.vidioc_try_fmt_vid_cap = vidioc_try_fmt_vid_cap,
	.vidioc_reqbufs = vb2_ioctl_reqbufs,
	.vidioc_create_bufs = vb2_ioctl_create_bufs,
	.vidioc_prepare_buf = vb2_ioctl_prepare_buf,
	.vidioc_querybuf = vb2_ioctl_querybuf,
	.vidioc_qbuf = vb2_ioctl_qbuf,
	.vidioc_dqbuf = vb2_ioctl_dqbuf,
	.vidioc_streamon = vb2_ioctl_streamon,
	.vidioc_streamoff = vb2_ioctl_streamoff,
};

static const struct media_entity_operations entity_ops = {
	.link_validate = link_validate,
};

static const struct v4l2_file_operations isys_fops = {
	.owner = THIS_MODULE,
	.poll = vb2_fop_poll,
	.unlocked_ioctl = video_ioctl2,
	.mmap = vb2_fop_mmap,
	.open = video_open,
	.release = video_release,
};

/*
 * Do everything that's needed to initialise things related to video
 * buffer queue, video node, and the related media entity. The caller
 * is expected to assign isys field and set the name of the video
 * device.
 */
int css2600_isys_video_init(struct css2600_isys_video *av,
			    struct media_entity *source,
			    unsigned int source_pad,
			    unsigned int flags)
{
	int rval;

	mutex_init(&av->mutex);

	rval = css2600_isys_queue_init(&av->aq);
	if (rval)
		goto out_mutex_destroy;

	av->pad.flags = MEDIA_PAD_FL_SINK;
	rval = media_entity_init(&av->vdev.entity, 1, &av->pad, 0);
	if (rval)
		goto out_css2600_isys_queue_cleanup;

	av->vdev.entity.ops = &entity_ops;
	av->vdev.release = video_device_release_empty;
	av->vdev.fops = &isys_fops;
	av->vdev.v4l2_dev = &av->isys->v4l2_dev;
	av->vdev.ioctl_ops = &ioctl_ops;
	av->vdev.queue = &av->aq.vbq;
	set_bit(V4L2_FL_USES_V4L2_FH, &av->vdev.flags);
	video_set_drvdata(&av->vdev, av);

	rval = media_entity_create_link(
		source, source_pad, &av->vdev.entity, 0, flags);
	if (rval) {
		dev_info(&av->isys->adev->dev, "can't create link\n");
		goto out_media_entity_cleanup;
	}

	av->pfmt = __vidioc_try_fmt_vid_cap(av, &av->pix);

	rval = video_register_device(&av->vdev, VFL_TYPE_GRABBER, -1);
	if (rval)
		goto out_media_entity_cleanup;

	return rval;

out_media_entity_cleanup:
	media_entity_cleanup(&av->vdev.entity);

out_css2600_isys_queue_cleanup:
	css2600_isys_queue_cleanup(&av->aq);

out_mutex_destroy:
	mutex_destroy(&av->mutex);

	return rval;
}

void css2600_isys_video_cleanup(struct css2600_isys_video *av)
{
	video_unregister_device(&av->vdev);
	media_entity_cleanup(&av->vdev.entity);
	mutex_destroy(&av->mutex);
}
