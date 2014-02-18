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



/* TODO: REMOVE --> START IF EXTERNALLY INCLUDED/DEFINED */
/* These are temporary, the correct numbers need to be inserted/linked */
/* Until this happens, the following definitions stay here             */
#define input_mipi_min_width        2
#define input_mipi_max_width        16384
#define input_mipi_min_height       2
#define input_mipi_max_height       16384
#define output_min_width			2
#define output_max_width			16384
#define output_min_height			2
#define output_max_height			16384
/*       REMOVE --> END   IF EXTERNALLY INCLUDED/DEFINED */

#include "input_system.h"
#include "ia_css_isys.h"
#include "memory_access.h"
/* The FW bridged types are included through the following */
#include "ia_css_isysapi.h"
/* The following provides the isys-sys context */
#include "ia_css_fwctrl.h"
#include "ia_css_isyspoc_comm.h"
#include "ia_css_debug.h"

#include "isyspoc_2401.h"

#include "type_support.h"
#include "assert_support.h"
#include "error_support.h"
#include "sh_css_internal.h"

#define HOST_MALLOC        sh_css_malloc
#define HOST_FREE          sh_css_free

#define	ISYS_IP_PIN0	0

static int isyspoc_create_reponse(
	struct ia_css_isys_resp_info *received_response,
	ia_css_isyspoc_cmd_msg_t *isys_msg
);

/**
 * ia_css_isys_device_cfg() - configure ISYS device
 */
int ia_css_isys_device_configure(
	HANDLE *context,
	struct ia_css_isys_device_cfg_data *config
)
{
	unsigned int stream_handle;
	struct ia_css_isys_context *ctx;
	int retval = 0;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_isys_device_configure() enter: void\n");
	assert(config != NULL);

	assert(config->mipi.nof_blocks <= STREAM_ID_MAX);
	for (stream_handle = 0; stream_handle < config->mipi.nof_blocks; stream_handle++) {
		assert(config->mipi.block_size[stream_handle] > 0);
	}

	assert(config->pixel.nof_blocks <= STREAM_ID_MAX);
	for (stream_handle = 0; stream_handle < config->pixel.nof_blocks; stream_handle++) {
		assert(config->pixel.block_size[stream_handle] > 0);
	}

	ctx = (struct ia_css_isys_context *)HOST_MALLOC(sizeof(struct ia_css_isys_context));
	assert(ctx != NULL);
	*context = (HANDLE)ctx;

	for (stream_handle = 0; stream_handle < STREAM_ID_MAX; stream_handle++) {
		ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_IDLE;
		ctx->stream_nof_output_pins[stream_handle] = 0;
	}

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_isys_device_configure() return: return_err=%d\n", retval);
	return retval;
}

 /**
 * ia_css_isys_stream_open() - open and configure a virtual stream
 */
int ia_css_isys_stream_open(
	HANDLE context,
	unsigned int stream_handle,
	const struct ia_css_isys_stream_cfg_data *stream_cfg
)
{
	bool rc;
	ia_css_isys_descr_t			isys_stream_descr;
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);

	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_IDLE);

	assert(stream_cfg != NULL);

	rc = ia_css_isys_translate_stream_cfg_to_isys_stream_descr(
				stream_cfg,
				&isys_stream_descr,
				ISYS_IP_PIN0);
	if(true != rc)
		return 1;      /*This will be changed to an appropriate error code*/

	/* create the virtual Input System (2401) */
	rc =  ia_css_isys_stream_create(
			&(isys_stream_descr),
			&(ctx->virtual_input_system[stream_handle]));
	if (rc != true)
		return 1;      /*This will be changed to an appropriate error code*/

	/* calculate the configuration of the virtual Input System (2401) */
	rc = ia_css_isys_stream_calculate_cfg(
			&(ctx->virtual_input_system[stream_handle]),
			&(isys_stream_descr),
			&(isys_msg.payload.virtual_input_system_cfg));
	if (rc != true) {
		ia_css_isys_stream_destroy(&(ctx->virtual_input_system[stream_handle]));
		return 1;      /*This will be changed to an appropriate error code*/
	}

	isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_OPEN;
	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	if ((retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg)) == 0) {
        ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_OPENED;
		ctx->stream_nof_output_pins[stream_handle] = stream_cfg->nof_output_pins;
    }

	return retval;
}

/**
 * ia_css_isys_stream_close() - close virtual stream
 */
int ia_css_isys_stream_close(
	HANDLE context,
	unsigned int stream_handle
)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);
	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_OPENED);

	isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_CLOSE;
	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	if ((retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg)) == 0) {
		ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_IDLE;
		ctx->stream_nof_output_pins[stream_handle] = 0;
	}

	return retval;
}

/**
 * ia_css_isys_stream_start() - starts handling a mipi virtual stream
 */
int ia_css_isys_stream_start(
		HANDLE context,
		unsigned int stream_handle,
		const struct ia_css_isys_frame_buff_set *next_frame
		)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	unsigned int i;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);
	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_OPENED);

	if (next_frame != NULL) {
		assert(ctx->stream_nof_output_pins[stream_handle] < MAX_OPINS);
		for (i=0; i<ctx->stream_nof_output_pins[stream_handle]; i++) {
			/* Verify output pin */
			assert(next_frame->output_pins[i].info.pt < N_IA_CSS_ISYS_PIN_TYPE);

			assert(next_frame->output_pins[i].info.pt != IA_CSS_ISYS_PIN_TYPE_MIPI);

			if ((next_frame->output_pins[i].info.pt == IA_CSS_ISYS_PIN_TYPE_RAW_NS) ||
				(next_frame->output_pins[i].info.pt == IA_CSS_ISYS_PIN_TYPE_RAW_S)) {
				assert(next_frame->output_pins[i].info.type_specifics.ft < N_IA_CSS_ISYS_FRAME_FORMAT);
			}

			assert(
					next_frame->output_pins[i].info.output_res.width >= output_min_width &&
					next_frame->output_pins[i].info.output_res.width <= output_max_width &&
					next_frame->output_pins[i].info.output_res.height >= output_min_height &&
					next_frame->output_pins[i].info.output_res.height <= output_max_height);
			assert(next_frame->output_pins[i].payload.addr != (hrt_vaddress)NULL);
		}

	}

	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];

	if (next_frame != NULL) {
		isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_START_AND_CAPTURE;
		memcpy(&(isys_msg.payload.next_frame), next_frame,
		sizeof(struct ia_css_isys_frame_buff_set));
	}
	else {
		isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_START;
	}

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	if ((retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg)) == 0) {
        ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_STARTED;
    }

	return retval;
}

/**
 * ia_css_isys_stream_stop() - Stops a mipi virtual stream
 */
  int ia_css_isys_stream_stop(
	HANDLE context,
	unsigned int stream_handle
)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);
	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_STARTED);

	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];
	isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_STOP;

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	if ((retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg)) == 0) {
        ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_OPENED;
	}

	return retval;
}

/**
 * ia_css_isys_stream_flush() - stops a mipi virtual stream but completes processing cmd backlog
 */
 int ia_css_isys_stream_flush(
	HANDLE context,
	unsigned int stream_handle
)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);
	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_STARTED);

	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];
	isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_FLUSH;

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	if ((retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg)) == 0) {
        ctx->stream_state_array[stream_handle] = IA_CSS_ISYS_STREAM_STATE_OPENED;
	}

	return retval;
}

/**
 * ia_css_isys_stream_capture_indication() - captures "next frame" on stream_handle
 */
int ia_css_isys_stream_capture_indication(
	HANDLE context,
	unsigned int stream_handle,
	const struct ia_css_isys_frame_buff_set *next_frame
)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_msg;
	unsigned int i;
	int retval = 0;

	assert(stream_handle < STREAM_ID_MAX);
	assert(ctx->stream_state_array[stream_handle] == IA_CSS_ISYS_STREAM_STATE_STARTED);

	assert(next_frame != NULL);
	assert(ctx->stream_nof_output_pins[stream_handle] < MAX_OPINS);
	for (i=0; i<ctx->stream_nof_output_pins[stream_handle]; i++) {
		/* Verify output pin */
		assert(next_frame->output_pins[i].info.pt < N_IA_CSS_ISYS_PIN_TYPE);

		assert(next_frame->output_pins[i].info.pt != IA_CSS_ISYS_PIN_TYPE_MIPI);

		if ((next_frame->output_pins[i].info.pt == IA_CSS_ISYS_PIN_TYPE_RAW_NS) ||
				(next_frame->output_pins[i].info.pt == IA_CSS_ISYS_PIN_TYPE_RAW_S)) {
			assert(next_frame->output_pins[i].info.type_specifics.ft < N_IA_CSS_ISYS_FRAME_FORMAT);
		}

		assert(
				next_frame->output_pins[i].info.output_res.width >= output_min_width &&
				next_frame->output_pins[i].info.output_res.width <= output_max_width &&
				next_frame->output_pins[i].info.output_res.height >= output_min_height &&
				next_frame->output_pins[i].info.output_res.height <= output_max_height);
		assert(next_frame->output_pins[i].payload.addr != (hrt_vaddress)NULL);
	}

	isys_msg.stream_handle = stream_handle;
	isys_msg.ret = 0;
	isys_msg.virtual_input_system = ctx->virtual_input_system[stream_handle];
	isys_msg.send_type = IA_CSS_ISYS_SEND_TYPE_STREAM_CAPTURE;
	memcpy(&(isys_msg.payload.next_frame), next_frame,
			sizeof(struct ia_css_isys_frame_buff_set));

	xmem_isys_msg = mmgr_malloc(sizeof(ia_css_isyspoc_cmd_msg_t));
	if (xmem_isys_msg == mmgr_NULL) {
		return ENOMEM;
	}
	mmgr_store(xmem_isys_msg, &isys_msg, sizeof(ia_css_isyspoc_cmd_msg_t));

	retval =  ia_css_fwctrl_isys_send_msg(xmem_isys_msg);

	return retval;
}

/**
 * ia_css_isys_stream_handle_response() - handle ISYS responses
 */
 int ia_css_isys_stream_handle_response(
	HANDLE context,
	struct ia_css_isys_resp_info *received_response
)
{
	struct ia_css_isys_context *ctx = (struct ia_css_isys_context *)context;
	ia_css_isyspoc_cmd_msg_t isys_msg;
	hrt_vaddress xmem_isys_response;
	int ret = 0;

	assert(received_response != NULL);
	assert(ctx != NULL);

	ret =  ia_css_fwctrl_isys_receive_msg(&xmem_isys_response);
	if (0 == ret) {
		mmgr_load(xmem_isys_response, (void*)(&isys_msg),
				sizeof(ia_css_isyspoc_cmd_msg_t));
		mmgr_free(xmem_isys_response);

		ret = isyspoc_create_reponse(received_response, &isys_msg);
    }

	return ret;
}

static int isyspoc_create_reponse(
	struct ia_css_isys_resp_info *received_response,
	ia_css_isyspoc_cmd_msg_t *isys_msg
) {
	int ret = 0;
	uint32_t pin_available;

	received_response->error = isys_msg->ret;
	received_response->timestamp[0] = isys_msg->timestamp[0];
	received_response->timestamp[1] = isys_msg->timestamp[1];
	received_response->stream_handle = isys_msg->stream_handle;
	received_response->type = isys_msg->resp_type;

	switch(isys_msg->resp_type) {
		case IA_CSS_ISYS_RESP_TYPE_STREAM_OPEN_DONE:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_START_ACK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_START_AND_CAPTURE_ACK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_CAPTURE_ACK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_STOP_ACK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_FLUSH_ACK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_CLOSE_ACK:

			break;


		case IA_CSS_ISYS_RESP_TYPE_PIN_DATA_READY:
		case IA_CSS_ISYS_RESP_TYPE_PIN_DATA_WATERMARK:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_START_AND_CAPTURE_DONE:
		case IA_CSS_ISYS_RESP_TYPE_STREAM_CAPTURE_DONE:
			pin_available = isys_msg->pin_available;
			memcpy(&(received_response->pin), &(isys_msg->payload.next_frame.output_pins[pin_available]),
					sizeof(struct ia_css_isys_output_pin));
			break;

		/* Need to find out if these events are handled
		 in software for CHV 2401 system */
		case IA_CSS_ISYS_RESP_TYPE_FRAME_SOF:
		case IA_CSS_ISYS_RESP_TYPE_FRAME_EOF:

			break;

		default:
            ret = -1;
            break;
	}

	return ret;
}

#undef HOST_MALLOC
#undef HOST_FREE
