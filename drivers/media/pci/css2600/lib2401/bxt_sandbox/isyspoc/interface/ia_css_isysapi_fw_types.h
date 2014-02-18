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

#ifndef __IA_CSS_ISYSAPI_FW_TYPES_H__
#define __IA_CSS_ISYSAPI_FW_TYPES_H__


#include "type_support.h"
/* TODO: REMOVE --> START IF EXTERNALLY INCLUDED/DEFINED */
#define MAX_IPINS 6
#define MAX_OPINS 18
/*       REMOVE --> END   IF EXTERNALLY INCLUDED/DEFINED */

/* Max number of supported virtual streams To be determined*/
#define  STREAM_ID_MAX 6

typedef void* HANDLE;
typedef unsigned int FW_VADDRESS;

/**
 * enum ia_css_isys_resp_type
 */
enum ia_css_isys_resp_type {
	IA_CSS_ISYS_RESP_TYPE_STREAM_OPEN_DONE,
	IA_CSS_ISYS_RESP_TYPE_STREAM_START_ACK,
	IA_CSS_ISYS_RESP_TYPE_STREAM_START_AND_CAPTURE_ACK,
	IA_CSS_ISYS_RESP_TYPE_STREAM_CAPTURE_ACK,
	IA_CSS_ISYS_RESP_TYPE_STREAM_STOP_ACK,
	IA_CSS_ISYS_RESP_TYPE_STREAM_FLUSH_ACK,
	IA_CSS_ISYS_RESP_TYPE_STREAM_CLOSE_ACK,
	IA_CSS_ISYS_RESP_TYPE_PIN_DATA_READY,
	IA_CSS_ISYS_RESP_TYPE_PIN_DATA_WATERMARK,
	IA_CSS_ISYS_RESP_TYPE_FRAME_SOF,
	IA_CSS_ISYS_RESP_TYPE_FRAME_EOF,
	IA_CSS_ISYS_RESP_TYPE_STREAM_START_AND_CAPTURE_DONE,
	IA_CSS_ISYS_RESP_TYPE_STREAM_CAPTURE_DONE,
	N_IA_CSS_ISYS_RESP_TYPE
};

/**
 * enum ia_css_isys_send_type
 */
enum ia_css_isys_send_type {
	IA_CSS_ISYS_SEND_TYPE_STREAM_OPEN,
	IA_CSS_ISYS_SEND_TYPE_STREAM_START,
	IA_CSS_ISYS_SEND_TYPE_STREAM_START_AND_CAPTURE,
	IA_CSS_ISYS_SEND_TYPE_STREAM_CAPTURE,
	IA_CSS_ISYS_SEND_TYPE_STREAM_STOP,
	IA_CSS_ISYS_SEND_TYPE_STREAM_FLUSH,
	IA_CSS_ISYS_SEND_TYPE_STREAM_CLOSE,
	N_IA_CSS_ISYS_SEND_TYPE
};

/**
 * struct ia_css_isys_resolution: Generic resolution structure.
 * @Width
 * @height
 */
struct ia_css_isys_resolution {
	unsigned int width;
	unsigned int height;
};

/**
 * enum ia_css_isys_stream_source: Specifies a source for a stream
 */
enum ia_css_isys_stream_source {
    IA_CSS_ISYS_STREAM_SRC_CSI2_PORT0,
    IA_CSS_ISYS_STREAM_SRC_CSI2_PORT1,
    IA_CSS_ISYS_STREAM_SRC_CSI2_PORT2,
    IA_CSS_ISYS_STREAM_SRC_CSI2_PORT3,
    IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT0,
    IA_CSS_ISYS_STREAM_SRC_MIPIGEN_PORT1,
    N_IA_CSS_ISYS_STREAM_SRC
};

/**
 * enum ia_css_isys_mipi_vc: MIPI csi2 spec
 * supports upto 4 virtual per physical channel
 */
enum ia_css_isys_mipi_vc {
    IA_CSS_ISYS_MIPI_VC_0,
    IA_CSS_ISYS_MIPI_VC_1,
    IA_CSS_ISYS_MIPI_VC_2,
    IA_CSS_ISYS_MIPI_VC_3,
    N_IA_CSS_ISYS_MIPI_VC
};

/**
 *  Supported Pixel Frame formats. TODO: ensure following format list is valid
 */
enum ia_css_isys_frame_format_type {
    IA_CSS_ISYS_FRAME_FORMAT_NV11,          /* 12 bit YUV 411, Y, UV plane */
    IA_CSS_ISYS_FRAME_FORMAT_NV12,          /* 12 bit YUV 420, Y, UV plane */
    IA_CSS_ISYS_FRAME_FORMAT_NV16,          /* 16 bit YUV 422, Y, UV plane */
    IA_CSS_ISYS_FRAME_FORMAT_NV21,          /* 12 bit YUV 420, Y, VU plane */
    IA_CSS_ISYS_FRAME_FORMAT_NV61,          /* 16 bit YUV 422, Y, VU plane */
    IA_CSS_ISYS_FRAME_FORMAT_YV12,          /* 12 bit YUV 420, Y, V, U plane */
    IA_CSS_ISYS_FRAME_FORMAT_YV16,          /* 16 bit YUV 422, Y, V, U plane */
    IA_CSS_ISYS_FRAME_FORMAT_YUV420,        /* 12 bit YUV 420, Y, U, V plane */
    IA_CSS_ISYS_FRAME_FORMAT_YUV420_16,     /* yuv420, 16 bits per subpixel */
    IA_CSS_ISYS_FRAME_FORMAT_YUV422,        /* 16 bit YUV 422, Y, U, V plane */
    IA_CSS_ISYS_FRAME_FORMAT_YUV422_16,     /* yuv422, 16 bits per subpixel */
    IA_CSS_ISYS_FRAME_FORMAT_UYVY,          /* 16 bit YUV 422, UYVY interleaved */
    IA_CSS_ISYS_FRAME_FORMAT_YUYV,          /* 16 bit YUV 422, YUYV interleaved */
    IA_CSS_ISYS_FRAME_FORMAT_YUV444,        /* 24 bit YUV 444, Y, U, V plane */
    IA_CSS_ISYS_FRAME_FORMAT_YUV_LINE,      /* Internal format, 2 y lines followed
					by a uvinterleaved line */
    IA_CSS_ISYS_FRAME_FORMAT_RAW,	        /* RAW, 1 plane */
    IA_CSS_ISYS_FRAME_FORMAT_RGB565,        /* 16 bit RGB, 1 plane. Each 3 sub
					pixels are packed into one 16 bit value, 5 bits for R, 6 bits
					for G and 5 bits for B. */
    IA_CSS_ISYS_FRAME_FORMAT_PLANAR_RGB888, /* 24 bit RGB, 3 planes */
    IA_CSS_ISYS_FRAME_FORMAT_RGBA888,	    /* 32 bit RGBA, 1 plane, A=Alpha
					(alpha is unused) */
	IA_CSS_ISYS_FRAME_FORMAT_QPLANE6,       /* Internal, for advanced ISP */
	IA_CSS_ISYS_FRAME_FORMAT_BINARY_8,	    /* byte stream, used for jpeg. For
					frames of this type, we set the height to 1 and the width to the
					number of allocated bytes. */
	N_IA_CSS_ISYS_FRAME_FORMAT
};

/**
 *  Supported MIPI data type. TODO: ensure following format list is valid
 */
enum ia_css_isys_mipi_data_type {
    IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8_LEGACY, /* 8 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8,        /* 8 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_10,       /* 10 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_8,        /* UYVY..UVYV, 8 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_YUV422_10,       /* UYVY..UVYV, 10 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_444,         /* BGR..BGR, 4 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_555,         /* BGR..BGR, 5 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_565,         /* BGR..BGR, 5 bits B and R, 6 bits G */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_666,         /* BGR..BGR, 6 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RGB_888,         /* BGR..BGR, 8 bits per subpixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_6,           /* RAW data, 6 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_7,           /* RAW data, 7 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_8,           /* RAW data, 8 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_10,          /* RAW data, 10 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_12,          /* RAW data, 12 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_14,          /* RAW data, 14 bits per pixel */
    IA_CSS_ISYS_MIPI_DATA_TYPE_RAW_16,          /* RAW data, 16 bits per pixel,
					which is not specified in CSI-MIPI standard */
    IA_CSS_ISYS_MIPI_DATA_TYPE_BINARY_8,        /* Binary byte stream,
					which is target at JPEG. */

    /** CSI2-MIPI specific format: Generic short packet data. It is used to
    *  keep the timing information for the opening/closing of shutters,
    *  triggering of flashes and etc.
    */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT1,  /* Generic Short Packet Code 1 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT2,  /* Generic Short Packet Code 2 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT3,  /* Generic Short Packet Code 3 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT4,  /* Generic Short Packet Code 4 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT5,  /* Generic Short Packet Code 5 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT6,  /* Generic Short Packet Code 6 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT7,  /* Generic Short Packet Code 7 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_GENERIC_SHORT8,  /* Generic Short Packet Code 8 */

	/** CSI2-MIPI specific format: YUV data.
	*/
	IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_8_SHIFT,  /* YUV420 8-bit
					Chroma Shifted Pixel Sampling) */
	IA_CSS_ISYS_MIPI_DATA_TYPE_YUV420_10_SHIFT, /* YUV420 8-bit
					(Chroma Shifted Pixel Sampling) */

	/** CSI2-MIPI specific format: Generic long packet data
	*/
	IA_CSS_ISYS_MIPI_DATA_TYPE_EMBEDDED,        /* Embedded 8-bit non Image Data */

    /** CSI2-MIPI specific format: User defined byte-based data. For example,
    *  the data transmitter (e.g. the SoC sensor) can keep the JPEG data as
    *  the User Defined Data Type 4 and the MPEG data as the
    *  User Defined Data Type 7.
    */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF1,       /* User defined 8-bit data type 1 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF2,       /* User defined 8-bit data type 2 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF3,       /* User defined 8-bit data type 3 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF4,       /* User defined 8-bit data type 4 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF5,       /* User defined 8-bit data type 5 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF6,       /* User defined 8-bit data type 6 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF7,       /* User defined 8-bit data type 7 */
    IA_CSS_ISYS_MIPI_DATA_TYPE_USER_DEF8,       /* User defined 8-bit data type 8 */
    N_IA_CSS_ISYS_MIPI_DATA_TYPE                /* Keep always last and max value */
};

/** enum ia_css_isys_pin_type: output pin buffer types.
 * Buffers can be queued and de-queued to hand them over between IA and ISYS
 */
enum ia_css_isys_pin_type {
    IA_CSS_ISYS_PIN_TYPE_MIPI,
    IA_CSS_ISYS_PIN_TYPE_RAW_NS,
    IA_CSS_ISYS_PIN_TYPE_RAW_S,
    IA_CSS_ISYS_PIN_TYPE_METADATA_0,
    IA_CSS_ISYS_PIN_TYPE_METADATA_1,
    IA_CSS_ISYS_PIN_TYPE_AF_STATS,
    IA_CSS_ISYS_PIN_TYPE_AWB_STATS,
    IA_CSS_ISYS_PIN_TYPE_HIST_STATS,
    N_IA_CSS_ISYS_PIN_TYPE /*Keep always last and max value */
};


/**
 * struct ia_css_isys_output_pin_payload
 * @addr: Points to ouput pin buffer
 */
struct ia_css_isys_output_pin_payload {
	FW_VADDRESS addr;
};

/**
 * struct ia_css_isys_output_pin_info
 * @pt: pin type
 * @ft: frame format type
 * @dt: mipi data type
 * @output_res: pin output resolution
 * @watermark_in_lines: pin watermark level in lines
 * @send_irq: assert if pin event should trigger irq
 *
 */
struct ia_css_isys_output_pin_info {
	enum ia_css_isys_pin_type pt;
	union {
		enum ia_css_isys_frame_format_type ft;
		enum ia_css_isys_mipi_data_type dt;
	} type_specifics;
	struct ia_css_isys_resolution output_res;
	unsigned int watermark_in_lines;
	unsigned int send_irq;
};

/**
 * struct ia_css_isys_input_pin
 * @addr: Points to input pin buffer in DDR
 *
 */
struct ia_css_isys_input_pin {
	FW_VADDRESS addr;
};

/**
 * struct ia_css_isys_input_pin_info
 * @dt
 * @input_res
 * @crop
 */
struct ia_css_isys_input_pin_info {
	enum ia_css_isys_mipi_data_type dt;
	struct ia_css_isys_resolution input_res;
	struct {
		unsigned int top_offset;
		unsigned int left_offset;
		unsigned int bottom_offset;
		unsigned int right_offset;
	} crop;
};

/**
 * struct ia_css_isys_output_pin
 * @payload: payload data
 * @info: info data
 */
struct ia_css_isys_output_pin {
	struct ia_css_isys_output_pin_payload payload;
	struct ia_css_isys_output_pin_info info;
};

 /**
 * struct ia_css_isys_stream_cfg_data
 * ISYS stream configuration data structure
 * @isl_enabled: indicates whether stream requores ISL
 * @src: Stream source index e.g. MIPI_generator_0, CSI2-rx_1
 * @vc: MIPI Virtual Channel (up to 4 virtual per physical channel)
 * @the rest: input/output pin descriptors
 */
struct ia_css_isys_stream_cfg_data {
	unsigned int isl_enabled;
	enum ia_css_isys_stream_source src;
	enum ia_css_isys_mipi_vc vc;

	unsigned int nof_input_pins;
	struct ia_css_isys_input_pin_info input_pins[MAX_IPINS];

	unsigned int nof_output_pins;
	struct ia_css_isys_output_pin_info output_pins[MAX_OPINS];
};

/**
 * struct ia_css_isys_frame_buff_set - frame buffer set
 * @the rest: output pin addresses and descriptors
 * @lsc_param:
 * @dpc_param:
 * @blc_param
 * @send_irq_sof: send irq on frame sof event
 * @send_irq_eof: send irq on frame eof event
 */

struct ia_css_isys_frame_buff_set {
	struct ia_css_isys_output_pin output_pins[MAX_OPINS];
	struct {
		struct ia_css_isys_input_pin lsc_param;
		struct ia_css_isys_input_pin dpc_param;
		struct ia_css_isys_input_pin blc_param;
	} input_pin_set;
	unsigned int send_irq_sof;
	unsigned int send_irq_eof;
};


/**
 * struct ia_css_isys_resp_info
 * @type
 * @error
 * @timestamp
 * @stream_handle
 * @pin: this member is only valid for pin event related responses
 */
struct ia_css_isys_resp_info {
	enum ia_css_isys_resp_type type;
	int error;
	unsigned long timestamp[2];
	unsigned int stream_handle;
	struct ia_css_isys_output_pin pin;
};


/**
 * struct ia_css_isys_buffer_partition - buffer partition information
 * @block_size: memory block size for a given stream
 * stream_id0 will make use of block 0
 * stream_id1 will make use of block 1
 * etc..
 * @nof_blocks: number of memory blocks to allocate
 *
 */
struct ia_css_isys_buffer_partition {
	unsigned int block_size[STREAM_ID_MAX];
	unsigned int nof_blocks;
};


#endif /*__IA_CSS_ISYSAPI_FW_TYPES_H__*/
