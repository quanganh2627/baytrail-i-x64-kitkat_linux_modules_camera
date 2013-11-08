/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2013 Intel Corporation. All Rights Reserved.
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

#ifndef __TYPE_SUPPORT_H_INCLUDED__
#define __TYPE_SUPPORT_H_INCLUDED__

/* Per the DLI spec, types are in "type_support.h" and
 * "platform_support.h" is for uncalssified/to be refactored
 * platform specific definitions.
 */

#if defined(_MSC_VER)
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#elif defined(__HIVECC)
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#elif defined(__KERNEL__)
#include <linux/types.h>
#include <linux/limits.h>

#elif defined(__GNUC__)
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#else /* default is for the FIST environment */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#endif

#endif /* __TYPE_SUPPORT_H_INCLUDED__ */
