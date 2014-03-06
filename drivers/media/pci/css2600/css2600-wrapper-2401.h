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

#ifndef CSS2600_WRAPPER_2401_H
#define CSS2600_WRAPPER_2401_H

struct device;
struct ia_css_env;
struct css2600_isys_iomem_filter;

int css2600_isys_iomem_filter_add(struct device *dev, void __iomem *addr,
				  size_t size);
int css2600_isys_iomem_filters_add(struct device *dev, void __iomem **addr,
				   unsigned int naddr, size_t size);
void css2600_isys_iomem_filter_remove(struct device *dev);

void css2600_wrapper_init(
	struct device *dev, struct ia_css_env *mycssmapenv, void __iomem *base);

#endif /* CSS2600_WRAPPER_2401_H */
