/*
 * Copyright (c) 2013 Intel Corporation. All Rights Reserved.
 */

#include "psys_ia_css_types.h"

enum {
	ATOMISP_PSYS_STUB_PREVIEW = 1,
};

#define ATOMISP_PSYS_STUB_INPUT_BUFS_MIN	2
#define ATOMISP_PSYS_STUB_OUTPUT_BUFS_MIN	1
#define ATOMISP_PSYS_STUB_BUFS_MIN \
(ATOMISP_PSYS_STUB_INPUT_BUFS_MIN + ATOMISP_PSYS_STUB_OUTPUT_BUFS_MIN)

#define ATOMISP_PSYS_STUB_VIDEO_INPUT_IDX	0
#define ATOMISP_PSYS_STUB_VIDEO_OUTPUT_IDX	1
#define ATOMISP_PSYS_STUB_PARAMS_IDX		2

struct atomisp_rect {
	uint32_t left;
	uint32_t top;
	uint32_t width;
	uint32_t height;
};

/**
 * struct atomisp_frame_info - describe a frame
 * @width:		frame width in pixels
 * @height:		frame height in pixels
 * @bytesperline:	line length in bytes
 * @frame_format:	frame format
 * @bayer_order:	bayer order
 * @bit_depth:		bits per pixel
 * @rect:		area of interest
 *
 * Describes a videoframe.
 */
struct atomisp_frame_info {
	uint32_t width;
	uint32_t height;
	uint32_t bytesperline;
	uint32_t frame_format; /* enum ia_css_frame_format */
	uint32_t bayer_order; /* enum ia_css_bayer_order, valid for raw only */
	uint32_t bit_depth;
	struct atomisp_rect rect;
	uint32_t reserved[2];
};

struct psysparam {
	struct atomisp_frame_info input;	/* describe input frame */
	struct atomisp_frame_info output;	/* describe output frame */
	struct ia_css_isp_parameters isp_params;
};
