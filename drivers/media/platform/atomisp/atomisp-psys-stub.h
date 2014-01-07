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

#ifndef ATOMISP_PSYS_STUB_H
#define ATOMISP_PSYS_STUB_H

#include <linux/cdev.h>
#include <linux/list.h>

#define ATOMISP_PSYS_STUB_NAME		"atomisp-psys-stub"

#define inode_to_atomisp_device(inode) \
	container_of((inode)->i_cdev, struct atomisp_device, cdev)

struct atomisp_event;

struct atomisp_kbuffer {
	void *userptr;
	int mapped;
	int fd;
	struct list_head list;
};

struct atomisp_eventq {
	struct atomisp_event *ev;
	struct list_head list;
};

struct atomisp_run_cmd {
	struct atomisp_command *command;
	struct list_head list;
};

struct atomisp_fh {
	struct device *dev;
	wait_queue_head_t wait;
	struct list_head list;
	struct list_head bufmap;
	struct list_head eventq;
	struct list_head command;
	struct workqueue_struct	*run_cmd_queue;
	struct work_struct run_cmd;
};

struct atomisp_device {
	struct cdev cdev;
	struct device dev;

	/* Serialise access to everything below mutex. */
	struct mutex mutex;
	struct list_head fhs;
};

#endif
