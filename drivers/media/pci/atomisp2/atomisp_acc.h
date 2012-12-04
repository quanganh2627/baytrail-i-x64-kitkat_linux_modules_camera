/*
 * Support for Clovertrail PNW Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2012 Intel Corporation. All Rights Reserved.
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

#ifndef __ATOMISP_ACC_H__
#define __ATOMISP_ACC_H__

#include <linux/atomisp.h>
#include "sh_css_types.h"
#include "atomisp_internal.h"

/*
 * Interface functions for AtomISP driver acceleration API implementation.
 */

struct atomisp_device;

/*
 * Initialize acceleration interface.
 * Must be called once when the driver is loaded.
 */
void atomisp_acc_init(struct atomisp_device *isp);

/*
 * Free up any allocated resources.
 * Must be called each time when the device is closed.
 * Note that there isn't corresponding open() call;
 * this function may be called sequentially multiple times.
 * Must be called to free up resources before driver is unloaded.
 */
void atomisp_acc_release(struct atomisp_device *isp);

/* Load acceleration binary */
int atomisp_acc_load(struct atomisp_device *isp,
		     struct atomisp_acc_fw_load *fw);

/* Unload specified acceleration binary */
int atomisp_acc_unload(struct atomisp_device *isp,
		       unsigned int *handle);

/*
 * Map a memory region into ISP memory space.
 */
int atomisp_acc_map(struct atomisp_device *isp,
		    struct atomisp_acc_map *map);

/*
 * Unmap a mapped memory region.
 */
int atomisp_acc_unmap(struct atomisp_device *isp,
		      struct atomisp_acc_map *map);

/*
 * Set acceleration binary argument to a previously mapped memory region.
 */
int atomisp_acc_s_mapped_arg(struct atomisp_device *isp,
			     struct atomisp_acc_s_mapped_arg *arg);


/*
 * Start acceleration.
 * Return immediately, acceleration is left running in background.
 * Specify either acceleration binary or pipeline which to start.
 */
int atomisp_acc_start(struct atomisp_device *isp,
		      unsigned int *handle);

/*
 * Wait until acceleration finishes.
 * This MUST be called after each acceleration has been started.
 * Specify either acceleration binary or pipeline handle.
 */
int atomisp_acc_wait(struct atomisp_device *isp,
		     unsigned int *handle);

#endif /* __ATOMISP_ACC_H__ */
