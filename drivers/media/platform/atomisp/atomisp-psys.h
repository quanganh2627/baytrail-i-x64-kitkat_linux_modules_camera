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
 */

#ifndef ATOMISP_PSYS_H
#define ATOMISP_PSYS_H

#include <linux/types.h>

struct atomisp_capability {
	uint32_t version;
	uint8_t driver[20];
} __attribute__ ((packed));

struct atomisp_event {
	uint32_t type;		/* ATOMISP_EVENT_TYPE_ */
	union {
		struct {
			uint32_t id;
		} cmd_done;
	} ev;
	uint32_t reserved[4];
} __attribute__ ((packed));

#define ATOMISP_EVENT_TYPE_CMD_COMPLETE      1

/**
 * struct atomisp_buffer - input/output port descriptor
 * @len:	buffer size
 * @userptr:	user pointer (NULL if not mapped to user space)
 * @fd:	DMA-BUF handle (filled by driver)
 * @flags:	flags
 */
struct atomisp_buffer {
	uint64_t len;
	void __user *userptr;
	int fd;
	uint32_t flags;
	uint32_t reserved2[4];
} __attribute__ ((packed)) ;

#define ATOMISP_BUFFER_FLAG_INPUT	(1 << 0)
#define ATOMISP_BUFFER_FLAG_OUTPUT	(1 << 1)
#define ATOMISP_BUFFER_FLAG_MAPPED	(1 << 2)

#define	ATOMISP_CMD_PRIORITY_HIGH	0
#define	ATOMISP_CMD_PRIORITY_MED	1
#define	ATOMISP_CMD_PRIORITY_LOW	2
#define	ATOMISP_CMD_PRIORITY_NUM	3

/**
 * struct atomisp_command - processing command
 * @id:	id of the command
 * @priority:	priority of the command
 * @bufcount:	number of buffers in bufs array
 * @bufs:	userspace pointers to array of atomisp_buffer structs
 *
 * Specifies a processing command including input and output buffers.
 */
struct atomisp_command {
	uint32_t id;
	uint32_t priority;
	uint32_t bufcount;
	struct atomisp_buffer __user *buffers;
	uint32_t reserved[4];
} __attribute__ ((packed));

#define ATOMISP_IOC_QUERYCAP _IOWR('A', 1, struct atomisp_capability)
#define ATOMISP_IOC_MAPBUF _IOWR('A', 2, struct atomisp_buffer)
#define ATOMISP_IOC_UNMAPBUF _IOWR('A', 3, struct atomisp_buffer)
#define ATOMISP_IOC_GETBUF _IOWR('A', 4, struct atomisp_buffer)
#define ATOMISP_IOC_PUTBUF _IOWR('A', 5, struct atomisp_buffer)
#define ATOMISP_IOC_QCMD _IOWR('A', 6, struct atomisp_command)
#define ATOMISP_IOC_DQEVENT _IOWR('A', 7, struct atomisp_event)

#endif
