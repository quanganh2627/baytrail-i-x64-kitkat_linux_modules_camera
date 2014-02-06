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

#include <media/media-entity.h>
#include <media/v4l2-device.h>
#include <media/v4l2-ioctl.h>

#include "css2600-isys.h"
#include "css2600-isys-video.h"

const struct css2600_isys_pixelformat *css2600_isys_get_pixelformat(
	struct css2600_isys_video *av, uint32_t pixelformat)
{
	const struct css2600_isys_pixelformat *pfmt, *found = av->pfmts;

	for (pfmt = av->pfmts; pfmt->bpp; pfmt++) {
		if (pfmt->pixelformat == pixelformat) {
			found = pfmt;
			break;
		}
	}

	return found;
}

static int vidioc_querycap(struct file *file, void *fh,
			   struct v4l2_capability *cap)
{
	return 0;
}

static int vidioc_enum_fmt_vid_cap(struct file *file, void *fh,
				   struct v4l2_fmtdesc *fmtdesc)
{
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

	mutex_lock(&av->mutex);

	av->pfmt = __vidioc_try_fmt_vid_cap(av, &fmt->fmt.pix);
	av->pix = fmt->fmt.pix;

	mutex_unlock(&av->mutex);

	return 0;
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

static const struct v4l2_ioctl_ops ioctl_ops = {
	.vidioc_querycap = vidioc_querycap,
	.vidioc_enum_fmt_vid_cap = vidioc_enum_fmt_vid_cap,
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

/*
 * Do everything that's needed to initialise things related to video
 * buffer queue, video node, and the related media entity. The caller
 * is expected to assign isys and pfmts fields.
 */
int css2600_isys_video_init(struct css2600_isys_video *av)
{
	int rval;

	mutex_init(&av->mutex);

	av->pfmt = __vidioc_try_fmt_vid_cap(av, &av->pix);

	rval = css2600_isys_queue_init(&av->aq);
	if (rval)
		goto out_mutex_destroy;

	av->pad.flags = MEDIA_PAD_FL_SINK;
	rval = media_entity_init(&av->vdev.entity, 1, &av->pad, 0);
	if (rval)
		goto out_css2600_isys_queue_cleanup;

	av->vdev.release = video_device_release_empty;
	av->vdev.fops = &css2600_isys_fops;
	av->vdev.v4l2_dev = &av->isys->v4l2_dev;
	av->vdev.ioctl_ops = &ioctl_ops;
	set_bit(V4L2_FL_USES_V4L2_FH, &av->vdev.flags);
	video_set_drvdata(&av->vdev, av);

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
