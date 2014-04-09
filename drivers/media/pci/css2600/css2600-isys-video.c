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
#include "css2600-isys-lib.h"
#include "css2600-isys-video.h"

static const struct css2600_isys_pixelformat isys_pfmts[] = {
	{ V4L2_PIX_FMT_SBGGR10, 16, 10, V4L2_MBUS_FMT_SBGGR10_1X10, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10 },
	{ V4L2_PIX_FMT_SGBRG10, 16, 10, V4L2_MBUS_FMT_SGBRG10_1X10, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10 },
	{ V4L2_PIX_FMT_SGRBG10, 16, 10, V4L2_MBUS_FMT_SGRBG10_1X10, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10 },
	{ V4L2_PIX_FMT_SRGGB10, 16, 10, V4L2_MBUS_FMT_SRGGB10_1X10, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10 },
	{ V4L2_PIX_FMT_SBGGR8, 8, 8, V4L2_MBUS_FMT_SBGGR8_1X8, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8 },
	{ V4L2_PIX_FMT_SGBRG8, 8, 8, V4L2_MBUS_FMT_SGBRG8_1X8, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8 },
	{ V4L2_PIX_FMT_SGRBG8, 8, 8, V4L2_MBUS_FMT_SGRBG8_1X8, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8 },
	{ V4L2_PIX_FMT_SRGGB8, 8, 8, V4L2_MBUS_FMT_SRGGB8_1X8, IA_CSS_ISYS_FRAME_FORMAT_RAW, IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8 },
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
	pix->bytesperline = ALIGN(pix->width * DIV_ROUND_UP(pfmt->bpp, 8),
				  av->isys->line_align);
	pix->sizeimage = max(pix->sizeimage, pix->bytesperline * pix->height);

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

/* Create stream and start it using the CSS library API. */
static int start_stream_firmware(struct css2600_isys_video *av,
				 struct css2600_isys_buffer *ib)
{
	struct ia_css_isys_stream_cfg_data stream_cfg = {
		.vc = 0,
		.nof_input_pins = 1,
		.input_pins = {
			{
				.dt = av->pfmt->mipi_data_type,
				.input_res = {
					.width = av->pix.width,
					.height = av->pix.height,
				},
				.crop = {
					 .top_offset = 0,
					 .left_offset = 0,
					 .bottom_offset = av->pix.width,
					 .right_offset = av->pix.height,
				 },
			},
		},
		.nof_output_pins = 1,
		.output_pins = {
			{
				.pt = IA_CSS_ISYS_PIN_TYPE_RAW_NS,
				.type_specifics.ft = av->pfmt->css_pixelformat,
				.output_res = {
					.width = av->pix.width,
					.height = av->pix.height,
				},
				.send_irq = 1,
			},
		 },
		.src = av->ip.source,
	};
	struct ia_css_isys_frame_buff_set buf = {
		.output_pins = {
			{
				.info.type_specifics.dt =
					av->pfmt->mipi_data_type,
				.info.pt = IA_CSS_ISYS_PIN_TYPE_RAW_NS,
				.info.output_res = {
					.width = av->pix.width,
					.height = av->pix.height,
				},
			}
		},
		.send_irq_sof = 1,
		.send_irq_eof = 1,
	};
	struct ia_css_isys_frame_buff_set *__buf = NULL;
	int rval;

	if (ib) {
		struct vb2_buffer *vb = css2600_isys_buffer_to_vb2_buffer(ib);

		buf.output_pins[0].payload.addr =
			*(dma_addr_t *)vb2_plane_cookie(vb, 0);
		__buf = &buf;
	}

	reinit_completion(&av->ip.stream_open_completion);
	rval = -ia_css_isys_stream_open(av->isys->ssi, av->ip.source,
					&stream_cfg);
	if (rval < 0) {
		dev_dbg(&av->isys->adev->dev, "can't open stream (%d)\n",
			rval);
		return rval;;
	}

	wait_for_completion(&av->ip.stream_open_completion);
	dev_dbg(&av->isys->adev->dev, "stream open complete\n");

	reinit_completion(&av->ip.stream_start_completion);
	rval = -ia_css_isys_stream_start(av->isys->ssi, av->ip.source, __buf);
	if (rval < 0) {
		dev_dbg(&av->isys->adev->dev, "can't start streaning (%d)\n",
			rval);
		goto out_stream_close;
	}

	wait_for_completion(&av->ip.stream_start_completion);
	dev_dbg(&av->isys->adev->dev, "stream start complete\n");

	return 0;

out_stream_close:
	reinit_completion(&av->ip.stream_close_completion);
	rval = -ia_css_isys_stream_close(av->isys->ssi, av->ip.source);
	if (rval < 0) {
		dev_dbg(&av->isys->adev->dev, "can't close stream (%d)\n",
			rval);
	} else {
		wait_for_completion(&av->ip.stream_close_completion);
		dev_dbg(&av->isys->adev->dev, "stream close complete\n");
	}
	return rval;
}

static void stop_streaming_firmware(struct css2600_isys_video *av)
{
	int rval;

	reinit_completion(&av->ip.stream_stop_completion);
	rval = -ia_css_isys_stream_stop(av->isys->ssi, av->ip.source);
	if (rval < 0) {
		dev_dbg(&av->isys->adev->dev, "can't stop stream (%d)\n",
			rval);
	} else {
		wait_for_completion(&av->ip.stream_stop_completion);
		dev_dbg(&av->isys->adev->dev, "stream stop complete\n");
	}

	reinit_completion(&av->ip.stream_close_completion);
	rval = -ia_css_isys_stream_close(av->isys->ssi, av->ip.source);
	if (rval < 0) {
		dev_dbg(&av->isys->adev->dev, "can't close stream (%d)\n",
			rval);
	} else {
		wait_for_completion(&av->ip.stream_close_completion);
		dev_dbg(&av->isys->adev->dev, "stream close complete\n");
	}
}

int css2600_isys_video_set_streaming(struct css2600_isys_video *av,
				     unsigned int state,
				     struct css2600_isys_buffer *ib)
{
	struct media_entity_graph graph;
	struct media_entity *entity, *entity2;
	unsigned long flags;
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
			rval = -EINVAL;
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

		/* We don't support non-linear pipelines yet. */
		if (media_entity_type(entity) != MEDIA_ENT_T_V4L2_SUBDEV)
			continue;
		/*
		 * Is the entity external or not? This is a little bit
		 * hackish but entirely local and not intrusive at
		 * all. The last such entity is the "sensor".
		 */
		if (sd->owner != THIS_MODULE) {
			av->ip.external = entity;
			continue;
		}

		dev_dbg(&av->isys->adev->dev, "s_stream %s\n",
			entity->name);
		rval = v4l2_subdev_call(sd, video, s_stream, state);
		if (!state)
			continue;
		if (rval && rval != -ENOIOCTLCMD)
			goto out_media_entity_stop_streaming;

		if (entity->id >= sizeof(entities) << 3) {
			WARN_ON(1);
			goto out_media_entity_stop_streaming;
		}

		entities |= 1 << entity->id;
	}

	spin_lock_irqsave(&av->isys->lock, flags);
	av->isys->pipes[av->ip.source] = &av->ip;
	spin_unlock_irqrestore(&av->isys->lock, flags);

	/* Oh crap */
	if (state) {
		rval = start_stream_firmware(av, ib);
		if (rval)
			goto out_media_entity_stop_streaming;
	} else {
		stop_streaming_firmware(av);
	}

	dev_dbg(&av->isys->adev->dev, "s_stream %s\n", av->ip.external->name);
	rval = v4l2_subdev_call(media_entity_to_v4l2_subdev(av->ip.external),
				video, s_stream, state);
	if (rval && state)
		goto out_media_entity_stop_streaming_firmware;

	if (!state)
		media_entity_pipeline_stop(&av->vdev.entity);
	else
		dev_dbg(&av->isys->adev->dev, "source %d\n", av->ip.source);

	av->streaming = state;

	mutex_unlock(&av->mutex);
	return 0;

out_media_entity_stop_streaming_firmware:
	stop_streaming_firmware(av);

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
	init_completion(&av->ip.stream_open_completion);
	init_completion(&av->ip.stream_close_completion);
	init_completion(&av->ip.stream_start_completion);
	init_completion(&av->ip.stream_stop_completion);

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
