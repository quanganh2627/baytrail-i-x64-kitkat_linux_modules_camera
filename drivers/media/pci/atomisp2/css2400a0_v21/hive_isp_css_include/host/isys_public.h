/* Release Version: ci_master_20131024_0113 */
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

#ifndef __ISYS_PUBLIC_H_INCLUDED__
#define __ISYS_PUBLIC_H_INCLUDED__

#ifdef USE_INPUT_SYSTEM_VERSION_2401
STORAGE_CLASS_INPUT_SYSTEM_H input_system_err_t input_system_get_state(
	const input_system_ID_t	ID,
	input_system_state_t *state);
#endif /* USE_INPUT_SYSTEM_VERSION_2401 */

#endif /* __ISYS_PUBLIC_H_INCLUDED__ */
