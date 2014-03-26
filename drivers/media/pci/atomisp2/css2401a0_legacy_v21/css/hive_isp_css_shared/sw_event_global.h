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

#ifndef __SW_EVENT_GLOBAL_H_INCLUDED__
#define __SW_EVENT_GLOBAL_H_INCLUDED__

#define MAX_NR_OF_PAYLOADS_PER_SW_EVENT 4

#define SP_SW_EVENT_ID_0	0	/* for the error		*/
#define SP_SW_EVENT_ID_1	1	/* for the host2sp_buffer_queue */
#define SP_SW_EVENT_ID_2	2	/* for the sp2host_buffer_queue */
#define SP_SW_EVENT_ID_3	3	/* for the sp2host_event_queue  */
#define SP_SW_EVENT_ID_4	4	/* for the start stream cmd */
#define SP_SW_EVENT_ID_5	5	/* for the stop stream cmd  */
#define SP_SW_EVENT_ID_6	6	/* for the host2sp empty mipi buffers */

#endif /* __SW_EVENT_GLOBAL_H_INCLUDED__ */
