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

#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/wait.h>

#include "atomisp-psys-stub.h"
#include "atomisp-psys.h"
#include "psysstub.h"

#define ATOMISP_NUM_DEVICES	4

static dev_t atomisp_dev_t;
static DECLARE_BITMAP(atomisp_devices, ATOMISP_NUM_DEVICES);
static DEFINE_MUTEX(atomisp_devices_mutex);

static struct bus_type atomisp_psys_bus = {
	.name = ATOMISP_PSYS_STUB_NAME,
};

static int atomisp_open(struct inode *inode, struct file *file)
{
	struct atomisp_device *isp = inode_to_atomisp_device(inode);
	struct atomisp_fh *fh;

	fh = kzalloc(sizeof(*fh), GFP_KERNEL);
	if (!fh)
		return -ENOMEM;

	init_waitqueue_head(&fh->wait);
	INIT_LIST_HEAD(&fh->bufmap);
	INIT_LIST_HEAD(&fh->eventq);

	fh->dev = &isp->dev;
	file->private_data = fh;

	mutex_lock(&isp->mutex);
	list_add(&fh->list, &isp->fhs);
	mutex_unlock(&isp->mutex);

	return 0;
}

static const struct atomisp_capability caps = {
	.version = 1,
	.driver = "atomisp-psys-stub",
};

static struct atomisp_kbuffer *atomisp_lookup_kbuffer(struct atomisp_fh *fh, int fd)
{
	struct atomisp_kbuffer *kbuffer = NULL;

	list_for_each_entry(kbuffer, &fh->bufmap, list) {
		if (kbuffer->fd == fd)
			return kbuffer;
	}

	return 0;
}

static long atomisp_ioctl_mapbuf(struct file *file, struct atomisp_buffer __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_kbuffer *kbuffer;
	struct atomisp_buffer buf;

	if (copy_from_user(&buf, arg, sizeof buf))
		return -EFAULT;
	kbuffer = atomisp_lookup_kbuffer(fh, buf.fd);
	if (!kbuffer)
		return -EINVAL;
	if (kbuffer->mapped)
		return -EINVAL;
	buf.flags |= ATOMISP_BUFFER_FLAG_MAPPED;
	if (copy_to_user(arg, &buf, sizeof buf)) {
		kfree(kbuffer);
		return -EFAULT;
	}
	kbuffer->mapped = 1;
	dev_dbg(fh->dev, "IOC_MAPBUF: mapped fd %d\n", kbuffer->fd);

	return 0;
}

static long atomisp_ioctl_unmapbuf(struct file *file, struct atomisp_buffer __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_kbuffer *kbuffer;
	struct atomisp_buffer buf;

	if (copy_from_user(&buf, arg, sizeof buf))
		return -EFAULT;
	kbuffer = atomisp_lookup_kbuffer(fh, buf.fd);
	if (!kbuffer)
		return -EINVAL;
	if (!kbuffer->mapped)
		return -EINVAL;
	buf.flags &= ~ATOMISP_BUFFER_FLAG_MAPPED;
	if (copy_to_user(arg, &buf, sizeof buf)) {
		kfree(kbuffer);
		return -EFAULT;
	}
	kbuffer->mapped = 0;
	dev_dbg(fh->dev, "IOC_UNMAPBUF: fd %d\n", kbuffer->fd);

	return 0;
}

static long atomisp_ioctl_getbuf(struct file *file, struct atomisp_buffer __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_kbuffer *kbuffer;
	struct atomisp_buffer buffer;

	if (copy_from_user(&buffer, arg, sizeof buffer))
		return -EFAULT;
	kbuffer = kzalloc(sizeof(*kbuffer), GFP_KERNEL);
	if (!kbuffer)
		return -ENOMEM;
	/* TODO: allocate with DMABUF */
	kbuffer->fd = (int)kbuffer;
	kbuffer->userptr = buffer.userptr;
	buffer.fd = kbuffer->fd;
	if (copy_to_user(arg, &buffer, sizeof buffer)) {
		kfree(kbuffer);
		return -EFAULT;
	}
	list_add_tail(&kbuffer->list, &fh->bufmap);
	dev_dbg(fh->dev, "IOC_GETBUF: userptr %p to %d\n", buffer.userptr, buffer.fd);
	return 0;
}

static long atomisp_ioctl_putbuf(struct file *file, struct atomisp_buffer __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_kbuffer *kbuffer = NULL;
	struct atomisp_buffer buffer;

	if (copy_from_user(&buffer, arg, sizeof buffer))
		return -EFAULT;
	kbuffer = atomisp_lookup_kbuffer(fh, buffer.fd);
	if (!kbuffer)
		return -EINVAL;
	list_del(&kbuffer->list);
	kfree(kbuffer);
	dev_dbg(fh->dev, "IOC_PUTBUF: buffer %d\n", buffer.fd);

	return 0;
}

static int atomisp_queue_event(struct atomisp_fh *fh, struct atomisp_event *e)
{
	struct atomisp_eventq *eventq;
	struct atomisp_event *ev;

	eventq = kzalloc(sizeof(*eventq), GFP_KERNEL);
	if (!eventq)
		return -ENOMEM;
	ev = kzalloc(sizeof(*ev), GFP_KERNEL);
	if (!ev)
		goto out;
	*ev = *e;
	eventq->ev = ev;
	dev_dbg(fh->dev, "queue event %u (%p)\n", ev->type, ev);
	list_add_tail(&eventq->list, &fh->eventq);
	wake_up_interruptible(&fh->wait);
	return 0;
out:
	kfree(eventq);
	return -ENOMEM;
}

/**
 * This should be moved to a separate file as this part will be
 * replaced by the actual PSYS hardware API.
 */
static int psysstub_command(struct atomisp_fh *fh, struct atomisp_command *command)
{
	struct atomisp_event ev;
	int err = 0;

	switch(command->id) {
	case ATOMISP_PSYS_STUB_PREVIEW:
		/* TODO: add some fake processing to the data buffers
		   passed */
		ev.type = ATOMISP_EVENT_TYPE_CMD_COMPLETE;
		ev.ev.cmd_done.id = command->id;
		atomisp_queue_event(fh, &ev);
		break;
	default:
		err = -EINVAL;
	}

	return err;
}

static long atomisp_ioctl_qcmd(struct file *file, struct atomisp_command __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_command command;

	if (copy_from_user(&command, arg, sizeof command))
		return -EFAULT;

	dev_dbg(fh->dev, "IOC_QCMD: length %u\n", command.bufcount);

	return psysstub_command(fh, &command);
}

static long atomisp_ioctl_dqevent(struct file *file, struct atomisp_event __user *arg)
{
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_eventq *evq;
	struct atomisp_event *ev;

	dev_dbg(fh->dev, "IOC_DQEVENT\n");

	/* TODO: eventq accesses must be serialized */
	/* TODO: should be able to block on this */

	if (list_empty(&fh->eventq))
		return -EINVAL;

	evq = list_first_entry(&fh->eventq, struct atomisp_eventq, list);
	ev = evq->ev;

	if (copy_to_user(arg, ev, sizeof *ev))
		return -EFAULT;

	list_del(&evq->list);
	kfree(evq);
	kfree(ev);

	return 0;
}

static long atomisp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int err = 0;
	void __user *argp = (void __user*)arg;

	switch (cmd) {
	case ATOMISP_IOC_QUERYCAP:
		return copy_to_user((void __user*)arg,
				&caps, sizeof caps);
	case ATOMISP_IOC_MAPBUF:
		return atomisp_ioctl_mapbuf(file, argp);
	case ATOMISP_IOC_UNMAPBUF:
		return atomisp_ioctl_unmapbuf(file, argp);
	case ATOMISP_IOC_GETBUF:
		return atomisp_ioctl_getbuf(file, argp);
	case ATOMISP_IOC_PUTBUF:
		return atomisp_ioctl_putbuf(file, argp);
	case ATOMISP_IOC_QCMD:
		return atomisp_ioctl_qcmd(file, argp);
	case ATOMISP_IOC_DQEVENT:
		return atomisp_ioctl_dqevent(file, argp);
	default:
		err = -ENOTTY;
	}
	return err;
}

static unsigned int atomisp_poll(struct file *file, struct poll_table_struct *wait)
{
	struct atomisp_fh *fh = file->private_data;
	unsigned int res = 0;

	dev_dbg(fh->dev, "atomisp poll\n");

	poll_wait(file, &fh->wait, wait);

	if (!list_empty(&fh->eventq))
		res = POLLIN;

	dev_dbg(fh->dev, "atomisp poll res %u\n", res);

	return res;
}


static int atomisp_release(struct inode *inode, struct file *file)
{
	struct atomisp_device *isp = inode_to_atomisp_device(inode);
	struct atomisp_fh *fh = file->private_data;
	struct atomisp_kbuffer *bm, *bm0;

	mutex_lock(&isp->mutex);
	list_del(&fh->list);
	list_for_each_entry_safe(bm, bm0, &fh->bufmap, list) {
		list_del(&bm->list);
		kfree(bm);
	}
	mutex_unlock(&isp->mutex);
	kfree(fh);

	return 0;
}

static const struct file_operations atomisp_fops = {
	.open = atomisp_open,
	.release = atomisp_release,
	.unlocked_ioctl = atomisp_ioctl,
	.poll = atomisp_poll,
	.owner = THIS_MODULE,
};

static int atomisp_platform_probe(struct platform_device *pdev)
{
	struct atomisp_device *isp;
	unsigned int minor;
	int rval = -E2BIG;

	mutex_lock(&atomisp_devices_mutex);

	minor = find_next_zero_bit(atomisp_devices, ATOMISP_NUM_DEVICES, 0);
	if (minor == ATOMISP_NUM_DEVICES) {
		dev_err(&pdev->dev, "too many devices\n");
		goto out_unlock;
	}

	isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
	if (!isp) {
		dev_err(&pdev->dev, "Failed to alloc CI ISP structure\n");
		rval = -ENOMEM;
		goto out_unlock;
	}

	cdev_init(&isp->cdev, &atomisp_fops);
	isp->cdev.owner = atomisp_fops.owner;

	rval = cdev_add(&isp->cdev, MKDEV(MAJOR(atomisp_dev_t), minor), 1);
	if (rval) {
		dev_err(&pdev->dev, "cdev_add failed (%d)\n", rval);
		goto out_unlock;
	}

	set_bit(minor, atomisp_devices);

	isp->dev.bus = &atomisp_psys_bus;
	isp->dev.devt = MKDEV(MAJOR(atomisp_dev_t), minor);
	dev_set_name(&isp->dev, ATOMISP_PSYS_STUB_NAME "%d", minor);
	rval = device_register(&isp->dev);
	if (rval < 0) {
		dev_err(&isp->dev, "device_register failed\n");
		goto out_unlock;
	}
	
	mutex_unlock(&atomisp_devices_mutex);
	mutex_init(&isp->mutex);
	INIT_LIST_HEAD(&isp->fhs);

	return 0;

out_unlock:
	mutex_unlock(&atomisp_devices_mutex);

	return rval;
}

static int atomisp_platform_remove(struct platform_device *pdev)
{
	struct atomisp_device *isp = platform_get_drvdata(pdev);

	mutex_lock(&atomisp_devices_mutex);

	device_unregister(&isp->dev);

	clear_bit(MINOR(isp->cdev.dev), atomisp_devices);
	cdev_del(&isp->cdev);

	mutex_unlock(&atomisp_devices_mutex);

	mutex_destroy(&isp->mutex);

	return 0;
}

static struct platform_device_id atomisp_psys_id_table[] = {
        { ATOMISP_PSYS_STUB_NAME, 0 },
        { },
};

static struct platform_driver atomisp_platform_driver = {
	.driver = {
#ifdef CONFIG_PM
		.pm = &(const struct dev_pm_ops){},
#endif /* CONFIG_PM */
		.name = ATOMISP_PSYS_STUB_NAME,
		.owner = THIS_MODULE,
	},
	.probe = atomisp_platform_probe,
	.remove = atomisp_platform_remove,
	.id_table = atomisp_psys_id_table,
};

static struct platform_device atomisp_platform_device = {
	.name           = ATOMISP_PSYS_STUB_NAME,
        .id             = -1,
};

static int __init atomisp_init(void)
{
	int rval = alloc_chrdev_region(&atomisp_dev_t, 0, ATOMISP_NUM_DEVICES,
				       ATOMISP_PSYS_STUB_NAME);

	if (rval) {
		pr_warn("can't allocate atomisp chrdev region (%d)\n", rval);
		return rval;
	}

	rval = bus_register(&atomisp_psys_bus);
	if (rval) {
		pr_warn("can't register atomisp bus (%d)\n", rval);
		goto out_bus_register;
	}

	rval = platform_device_register(&atomisp_platform_device);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_platform_device_register;
	}

	rval = platform_driver_register(&atomisp_platform_driver);
	if (rval) {
		pr_warn("can't register pci driver (%d)\n", rval);
		goto out_platform_driver_register;
	}

	return 0;

out_platform_driver_register:
	platform_device_unregister(&atomisp_platform_device);

out_platform_device_register:
	bus_unregister(&atomisp_psys_bus);

out_bus_register:
	unregister_chrdev_region(atomisp_dev_t, ATOMISP_NUM_DEVICES);

	return rval;
}

static void __exit atomisp_exit(void)
{
	platform_driver_unregister(&atomisp_platform_driver);
	platform_device_unregister(&atomisp_platform_device);
	bus_unregister(&atomisp_psys_bus);
	unregister_chrdev_region(atomisp_dev_t, ATOMISP_NUM_DEVICES);
}

module_init(atomisp_init);
module_exit(atomisp_exit);

MODULE_AUTHOR("Sakari Ailus <sakari.ailus@intel.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Intel Atom ISP driver");
