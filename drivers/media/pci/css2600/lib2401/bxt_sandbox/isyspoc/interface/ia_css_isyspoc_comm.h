/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2010 - 2014 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef _IA_CSS_ISYSPOC_COMM_H
#define _IA_CSS_ISYSPOC_COMM_H

#include "ia_css_isys_comm.h"    /* ia_css_isys_stream_cfg_t */
#include "ia_css_isysapi_fw_types.h"


/* The following two macros need to be expanded to use
 * basic data types but all of these have enums and
 * non-sharable data types which has to be fixed there.
 * We need to get agreement from BXT ISYS team and 2401
 * CHV team */
#define SIZE_OF_VISYS_STRUCT	sizeof(ia_css_isys_stream_cfg_t)
#define SIZE_OF_FBS_STRUCT	sizeof(ia_css_isys_frame_buff_set)

#define SIZE_OF_ISYSPOC_PAYLOAD_UNION				\
	(MAX(SIZE_OF_VISYS_STRUCT, SIZE_OF_FBS_STRUCT))

#define SIZE_OF_ISYSPOC_CMD_MSG_STRUCT	\
	((5 * sizeof(uint32_t)) +			\
	sizeof(virtual_input_system_t) +	\
	(2 * sizeof(unsigned long)) +		\
	SIZE_OF_ISYSPOC_PAYLOAD_UNION)

/* In the above macro we need
 * to change unsigned long to an
 * appropriate type. There is none
 * for unsigned long in type_support.h
 * virtual_input_system_t has
 * non-sharable types and we need agreement
 * from 2401 CHV team to get it fixed */

typedef struct {
	uint32_t send_type;
	uint32_t resp_type;
	unsigned long timestamp[2];
	uint32_t stream_handle;
	uint32_t pin_available;
	uint32_t ret;
	virtual_input_system_t virtual_input_system;
	union {
		ia_css_isys_stream_cfg_t virtual_input_system_cfg;
		struct ia_css_isys_frame_buff_set next_frame;
	} payload;
} ia_css_isyspoc_cmd_msg_t;

#endif				/* _IA_CSS_ISYSPOC_COMM_H */
