/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
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

/* CSS API version file */

#ifndef __CSS_API_VERSION_H
#define __CSS_API_VERSION_H

/*
The last two digits of the CSS_API_VERSION_STRING give the major and minor
versions of the CSS-API. The minor version number will be increased by one when
a backwards-compatible change is made. The major version number will be
increased (and the minor version number reset) when a non-backwards-compatbile
change is made.
*/
#define CSS_API_VERSION_STRING	"2.0.1.1"

/*
Change log
V2.0.1.0, initial version:
 - added API versioning
V2.0.1.1, activate CSS-API versioning:
 - added description of major and minor version numbers
*/

#endif __CSS_API_VERSION_H
