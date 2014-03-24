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

#ifndef CSS2600_PSYS_H
#define CSS2600_PSYS_H

#include <linux/cdev.h>

#include "css2600.h"
#include "css2600-pdata.h"

struct css2600_psys {
	struct cdev cdev;
	struct device dev;

	struct mutex mutex;
	struct list_head fhs;
	struct css2600_psys_pdata *pdata;
};

struct css2600_psys_fh {
	struct list_head list;
};

#define inode_to_css2600_psys(inode) \
	container_of((inode)->i_cdev, struct css2600_psys, cdev)

#endif /* CSS2600_PSYS_H */
