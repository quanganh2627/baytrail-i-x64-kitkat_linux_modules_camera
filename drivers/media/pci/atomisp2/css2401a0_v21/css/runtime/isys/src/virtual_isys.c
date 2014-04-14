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

#include "ia_css_isys.h"
#include "math_support.h"
#include "string_support.h"
#include "virtual_isys.h"
#include "isp.h"
#include "sh_css_defs.h"


/*************************************************
 *
 * Forwarded Declaration
 *
 *************************************************/

static bool create_input_system_channel(
	input_system_cfg_t	*cfg,
	bool metadata,
	input_system_channel_t	*channel);

static void destroy_input_system_channel(
	input_system_channel_t	*channel);

static bool create_input_system_input_port(
	input_system_cfg_t		*cfg,
	input_system_input_port_t	*input_port);

static void destroy_input_system_input_port(
	input_system_input_port_t	*input_port);

static bool calculate_input_system_channel_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	input_system_channel_cfg_t	*channel_cfg,
	bool metadata);

static bool calculate_input_system_input_port_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	input_system_input_port_cfg_t	*input_port_cfg);

static bool acquire_sid(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid);

static void release_sid(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid);

static bool acquire_ib_buffer(
	int32_t bits_per_pixel,
	int32_t pixels_per_line,
	int32_t lines_per_frame,
	int32_t fmt_type,
	ib_buffer_t *buf);

static void release_ib_buffer(
	ib_buffer_t *buf);

static bool acquire_dma_channel(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel);

static void release_dma_channel(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel);

static bool acquire_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry);

static void release_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry);

static bool calculate_tpg_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	pixelgen_tpg_cfg_t		*cfg);

static bool calculate_prbs_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	pixelgen_prbs_cfg_t		*cfg);

static bool calculate_fe_cfg(
	const input_system_cfg_t		*isys_cfg,
	csi_rx_frontend_cfg_t		*cfg);

static bool calculate_be_cfg(
	const input_system_input_port_t	*input_port,
	const input_system_cfg_t		*isys_cfg,
	bool metadata,
	csi_rx_backend_cfg_t		*cfg);

static bool calculate_stream2mmio_cfg(
	const input_system_cfg_t		*isys_cfg,
	bool metadata,
	stream2mmio_cfg_t		*cfg);

static bool calculate_ibuf_ctrl_cfg(
	const input_system_channel_t		*channel,
	const input_system_input_port_t	*input_port,
	const input_system_cfg_t		*isys_cfg,
	ibuf_ctrl_cfg_t			*cfg);

static bool calculate_isys2401_dma_cfg(
	const input_system_channel_t		*channel,
	const input_system_cfg_t		*isys_cfg,
	isys2401_dma_cfg_t		*cfg);

static bool calculate_isys2401_dma_port_cfg(
	const input_system_cfg_t		*isys_cfg,
	bool				is_compact_mode,
	bool				metadata,
	isys2401_dma_port_cfg_t		*cfg);

static csi_mipi_packet_type_t get_csi_mipi_packet_type(
	int32_t data_type);

static int32_t calculate_input_system_alignment(
	int32_t fmt_type,
	int32_t bytes_per_pixel);

static int32_t calculate_packed_stride(
	int32_t bits_per_pixel,
	int32_t pixels_per_line);

/** end of Forwarded Declaration */

/**************************************************
 *
 * Public Method
 *
 **************************************************/
ia_css_isys_error_t ia_css_isys_stream_create(
	ia_css_isys_descr_t	*isys_stream_descr,
	ia_css_isys_stream_h	isys_stream)
{
	ia_css_isys_error_t rc;

	if (isys_stream_descr == NULL || isys_stream == NULL)
		return	false;

	rc = create_input_system_input_port(isys_stream_descr, &(isys_stream->input_port));
	if (rc == false)
		return false;

	rc = create_input_system_channel(isys_stream_descr, false, &(isys_stream->channel));
	if (rc == false) {
		destroy_input_system_input_port(&(isys_stream->input_port));
		return false;
	}

	/* create metadata channel */
	if (isys_stream_descr->metadata.enable) {
		rc = create_input_system_channel(isys_stream_descr, true, &isys_stream->md_channel);
		if (rc == false) {
			destroy_input_system_input_port(&isys_stream->input_port);
			destroy_input_system_channel(&isys_stream->channel);
			return false;
		}
	}

	return true;
}

void ia_css_isys_stream_destroy(
	ia_css_isys_stream_h	isys_stream)
{
	destroy_input_system_input_port(&(isys_stream->input_port));
	destroy_input_system_channel(&(isys_stream->channel));
	destroy_input_system_channel(&isys_stream->md_channel);
}

ia_css_isys_error_t ia_css_isys_stream_calculate_cfg(
	ia_css_isys_stream_h		isys_stream,
	ia_css_isys_descr_t		*isys_stream_descr,
	ia_css_isys_stream_cfg_t	*isys_stream_cfg)
{
	ia_css_isys_error_t rc;

	if (isys_stream_cfg == NULL	||
		isys_stream_descr == NULL	||
		isys_stream == NULL)
		return false;

	rc  = calculate_input_system_channel_cfg(
			&(isys_stream->channel),
			&(isys_stream->input_port),
			isys_stream_descr,
			&(isys_stream_cfg->channel_cfg),
			false);
	if (rc == false)
		return false;

	/* configure metadata channel */
	if (isys_stream_descr->metadata.enable) {
		isys_stream_cfg->enable_metadata = true;
		rc  = calculate_input_system_channel_cfg(
				&isys_stream->md_channel,
				&isys_stream->input_port,
				isys_stream_descr,
				&isys_stream_cfg->md_channel_cfg,
				true);
		if (rc == false)
			return false;
	}

	rc = calculate_input_system_input_port_cfg(
			&(isys_stream->channel),
			&(isys_stream->input_port),
			isys_stream_descr,
			&(isys_stream_cfg->input_port_cfg));
	if (rc == false)
		return false;

	return true;
}

/** end of Public Method */

/**************************************************
 *
 * Private Method
 *
 **************************************************/
static bool create_input_system_channel(
	input_system_cfg_t	*cfg,
	bool metadata,
	input_system_channel_t	*me)
{
	bool rc = true;

	me->dma_id = ISYS2401_DMA0_ID;

	switch (cfg->input_port_id) {
	case INPUT_SYSTEM_CSI_PORT0_ID:
	case INPUT_SYSTEM_PIXELGEN_PORT0_ID:
		me->stream2mmio_id = STREAM2MMIO0_ID;
		me->ibuf_ctrl_id = IBUF_CTRL0_ID;
		break;

	case INPUT_SYSTEM_CSI_PORT1_ID:
	case INPUT_SYSTEM_PIXELGEN_PORT1_ID:
		me->stream2mmio_id = STREAM2MMIO1_ID;
		me->ibuf_ctrl_id = IBUF_CTRL1_ID;
		break;

	case INPUT_SYSTEM_CSI_PORT2_ID:
	case INPUT_SYSTEM_PIXELGEN_PORT2_ID:
		me->stream2mmio_id = STREAM2MMIO2_ID;
		me->ibuf_ctrl_id = IBUF_CTRL2_ID;
		break;
	default:
		rc = false;
		break;
	}

	if (rc == false)
		return false;


	if (!acquire_sid(me->stream2mmio_id, &(me->stream2mmio_sid_id))) {
		return false;
	}
	if ((cfg->csi_port_attr.fmt_type >= MIPI_FORMAT_CUSTOM0) &&
	    (cfg->csi_port_attr.fmt_type <= MIPI_FORMAT_CUSTOM7)) {
		/* set up for store_words's width for MIPI user defined types */
		cfg->input_port_resolution.lines_per_frame =
			ceil_div(cfg->input_port_resolution.pixels_per_line, HIVE_ISP_DDR_WORD_BYTES);
		cfg->input_port_resolution.pixels_per_line = HIVE_ISP_DDR_WORD_BYTES;
	}

	if (!acquire_ib_buffer(
			metadata ? cfg->metadata.bits_per_pixel : cfg->input_port_resolution.bits_per_pixel,
			metadata ? cfg->metadata.pixels_per_line : cfg->input_port_resolution.pixels_per_line,
			metadata ? cfg->metadata.lines_per_frame : cfg->input_port_resolution.lines_per_frame,
			metadata ? cfg->metadata.fmt_type : cfg->csi_port_attr.fmt_type,
			&(me->ib_buffer))) {
		release_sid(me->stream2mmio_id, &(me->stream2mmio_sid_id));
		return false;
	}

	if (!acquire_dma_channel(me->dma_id, &(me->dma_channel))) {
		release_sid(me->stream2mmio_id, &(me->stream2mmio_sid_id));
		release_ib_buffer(&(me->ib_buffer));
		return false;
	}

	return	true;
}

static void destroy_input_system_channel(
	input_system_channel_t	*me)
{
	release_sid(me->stream2mmio_id,
		&(me->stream2mmio_sid_id));

	release_ib_buffer(&(me->ib_buffer));

	release_dma_channel(me->dma_id, &(me->dma_channel));
}

static bool create_input_system_input_port(
	input_system_cfg_t		*cfg,
	input_system_input_port_t	*me)
{
	csi_mipi_packet_type_t packet_type;
	bool rc;

	rc = true;
	switch (cfg->input_port_id) {
	case INPUT_SYSTEM_CSI_PORT0_ID:
		me->csi_rx.frontend_id = CSI_RX_FRONTEND0_ID;
		me->csi_rx.backend_id = CSI_RX_BACKEND0_ID;

		packet_type = get_csi_mipi_packet_type(cfg->csi_port_attr.fmt_type);
		me->csi_rx.packet_type = packet_type;

		rc = acquire_be_lut_entry(
				me->csi_rx.backend_id,
				packet_type,
				&(me->csi_rx.backend_lut_entry));

		/* for metadata */
		if (rc && cfg->metadata.enable) {
			me->metadata.packet_type = get_csi_mipi_packet_type(
					cfg->metadata.fmt_type);
			rc = acquire_be_lut_entry(
					me->csi_rx.backend_id,
					me->metadata.packet_type,
					&me->metadata.backend_lut_entry);
		}
		break;
	case INPUT_SYSTEM_PIXELGEN_PORT0_ID:
		me->pixelgen.pixelgen_id = PIXELGEN0_ID;
		break;
	case INPUT_SYSTEM_CSI_PORT1_ID:
		me->csi_rx.frontend_id = CSI_RX_FRONTEND1_ID;
		me->csi_rx.backend_id = CSI_RX_BACKEND1_ID;

		packet_type = get_csi_mipi_packet_type(cfg->csi_port_attr.fmt_type);
		me->csi_rx.packet_type = packet_type;

		rc = acquire_be_lut_entry(
				me->csi_rx.backend_id,
				packet_type,
				&(me->csi_rx.backend_lut_entry));
		break;
	case INPUT_SYSTEM_PIXELGEN_PORT1_ID:
		me->pixelgen.pixelgen_id = PIXELGEN1_ID;

		break;
	case INPUT_SYSTEM_CSI_PORT2_ID:
		me->csi_rx.frontend_id = CSI_RX_FRONTEND2_ID;
		me->csi_rx.backend_id = CSI_RX_BACKEND2_ID;

		packet_type = get_csi_mipi_packet_type(cfg->csi_port_attr.fmt_type);
		me->csi_rx.packet_type = packet_type;

		rc = acquire_be_lut_entry(
				me->csi_rx.backend_id,
				packet_type,
				&(me->csi_rx.backend_lut_entry));
		break;
	case INPUT_SYSTEM_PIXELGEN_PORT2_ID:
		me->pixelgen.pixelgen_id = PIXELGEN2_ID;
		break;
	default:
		rc = false;
		break;
	}

	me->source_type = cfg->mode;

	return rc;
}

static void destroy_input_system_input_port(
	input_system_input_port_t	*me)
{
	if (me->source_type == INPUT_SYSTEM_SOURCE_TYPE_SENSOR) {
		release_be_lut_entry(
				me->csi_rx.backend_id,
				me->csi_rx.packet_type,
				&me->csi_rx.backend_lut_entry);
	}
}

static bool calculate_input_system_channel_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	input_system_channel_cfg_t	*channel_cfg,
	bool metadata)
{
	bool rc;

	rc = calculate_stream2mmio_cfg(isys_cfg, metadata,
			&(channel_cfg->stream2mmio_cfg));
	if (rc == false)
		return false;

	rc = calculate_ibuf_ctrl_cfg(
			channel,
			input_port,
			isys_cfg,
			&(channel_cfg->ibuf_ctrl_cfg));
	if (rc == false)
		return false;
	if (metadata)
		channel_cfg->ibuf_ctrl_cfg.stores_per_frame = isys_cfg->metadata.lines_per_frame;

	rc = calculate_isys2401_dma_cfg(
			channel,
			isys_cfg,
			&(channel_cfg->dma_cfg));
	if (rc == false)
		return false;

	rc = calculate_isys2401_dma_port_cfg(
			isys_cfg,
			false,
			metadata,
			&(channel_cfg->dma_src_port_cfg));
	if (rc == false)
		return false;

	rc = calculate_isys2401_dma_port_cfg(
			isys_cfg,
			isys_cfg->raw_packed,
			metadata,
			&(channel_cfg->dma_dest_port_cfg));
	if (rc == false)
		return false;

	return true;
}

static bool calculate_input_system_input_port_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	input_system_input_port_cfg_t	*input_port_cfg)
{
	bool rc;

	switch (input_port->source_type) {
	case INPUT_SYSTEM_SOURCE_TYPE_SENSOR:
		rc  = calculate_fe_cfg(
				isys_cfg,
				&(input_port_cfg->csi_rx_cfg.frontend_cfg));

		rc &= calculate_be_cfg(
				input_port,
				isys_cfg,
				false,
				&(input_port_cfg->csi_rx_cfg.backend_cfg));

		if (rc && isys_cfg->metadata.enable)
			rc &= calculate_be_cfg(input_port, isys_cfg, true,
					&input_port_cfg->csi_rx_cfg.md_backend_cfg);
		break;
	case INPUT_SYSTEM_SOURCE_TYPE_TPG:
		rc = calculate_tpg_cfg(
				channel,
				input_port,
				isys_cfg,
				&(input_port_cfg->pixelgen_cfg.tpg_cfg));
		break;
	case INPUT_SYSTEM_SOURCE_TYPE_PRBS:
		rc = calculate_prbs_cfg(
				channel,
				input_port,
				isys_cfg,
				&(input_port_cfg->pixelgen_cfg.prbs_cfg));
		break;
	default:
		rc = false;
		break;
	}

	return rc;
}

static bool acquire_sid(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid)
{
	return ia_css_isys_stream2mmio_sid_rmgr_acquire(stream2mmio, sid);
}

static void release_sid(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid)
{
	ia_css_isys_stream2mmio_sid_rmgr_release(stream2mmio, sid);
}

static int32_t calculate_input_system_alignment(
	int32_t fmt_type,
	int32_t bytes_per_pixel)
{
	int32_t memory_alignment_in_bytes;

		/* make input system 2401 stride aligned with frame buffer
			ISP_VEC_NELEMS is 64 for ISP on 2401 css system */
		if (fmt_type <= MIPI_FORMAT_RAW14 && fmt_type >= MIPI_FORMAT_RAW6)
			memory_alignment_in_bytes = bytes_per_pixel * 2 * ISP_VEC_NELEMS;
		/* YUV420 double the Y plane to make all plane aligned
			YUV422 2 subpixles per pixel, need double the alignment */
		else if (fmt_type == MIPI_FORMAT_YUV420_8 ||
				fmt_type == MIPI_FORMAT_YUV422_8)
			memory_alignment_in_bytes = bytes_per_pixel * 2 * HIVE_ISP_DDR_WORD_BYTES;
		else
			memory_alignment_in_bytes = bytes_per_pixel * HIVE_ISP_DDR_WORD_BYTES;

	return memory_alignment_in_bytes;
}

static int32_t calculate_packed_stride(
	int32_t bits_per_pixel,
	int32_t pixels_per_line)
{
	const int32_t bits_per_byte = 8;
	const int32_t bits_per_word = 256;

	int32_t bytes_per_line;
	int32_t pixels_per_word;
	int32_t words_per_line;
	int32_t bytes_per_word;
	int32_t pixels_per_line_padded;

	bytes_per_word  = bits_per_word / bits_per_byte;

	pixels_per_line_padded = CEIL_MUL(pixels_per_line, 2 * ISP_VEC_NELEMS);

	/* compact as many pixels as possible into a word */
	pixels_per_word = bits_per_word / bits_per_pixel;
	words_per_line  = ceil_div(pixels_per_line_padded, pixels_per_word);
	bytes_per_line  = bytes_per_word * words_per_line;

	return bytes_per_line;
}

static bool acquire_ib_buffer(
	int32_t bits_per_pixel,
	int32_t pixels_per_line,
	int32_t lines_per_frame,
	int32_t fmt_type,
	ib_buffer_t *buf)
{
	const int32_t bits_per_byte = 8;
	int32_t memory_alignment_in_bytes;
	int32_t	bytes_per_pixel;
	int32_t bytes_per_line;

	bytes_per_pixel = ceil_div(bits_per_pixel, bits_per_byte);
	bytes_per_line  = bytes_per_pixel * pixels_per_line;

	memory_alignment_in_bytes = calculate_input_system_alignment(fmt_type,
					bytes_per_pixel);

	buf->stride = CEIL_MUL(bytes_per_line, memory_alignment_in_bytes);
	buf->lines = 2; /* ISYS2401 hardware can handle at most 4 lines */

	(void)(lines_per_frame);
	return ia_css_isys_ibuf_rmgr_acquire(buf->stride * buf->lines, &buf->start_addr);
}

static void release_ib_buffer(
	ib_buffer_t *buf)
{
	ia_css_isys_ibuf_rmgr_release(&buf->start_addr);
}

static bool acquire_dma_channel(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel)
{
	return ia_css_isys_dma_channel_rmgr_acquire(dma_id, channel);
}

static void release_dma_channel(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel)
{
	ia_css_isys_dma_channel_rmgr_release(dma_id, channel);
}

static bool acquire_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry)
{
	return ia_css_isys_csi_rx_lut_rmgr_acquire(backend, packet_type, entry);
}

static void release_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry)
{
	ia_css_isys_csi_rx_lut_rmgr_release(backend, packet_type, entry);
}

static bool calculate_tpg_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	pixelgen_tpg_cfg_t		*cfg)
{
	(void)channel;
	(void)input_port;

	memcpy_s(
		(void *)cfg,
		sizeof(pixelgen_tpg_cfg_t),
		(void *)(&(isys_cfg->tpg_port_attr)),
		sizeof(pixelgen_tpg_cfg_t));
	return true;
}

static bool calculate_prbs_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	pixelgen_prbs_cfg_t		*cfg)
{
	(void)channel;
	(void)input_port;

	memcpy_s(
		(void *)cfg,
		sizeof(pixelgen_prbs_cfg_t),
		(void *)(&(isys_cfg->prbs_port_attr)),
		sizeof(pixelgen_prbs_cfg_t));
	return true;
}

static bool calculate_fe_cfg(
	const input_system_cfg_t		*isys_cfg,
	csi_rx_frontend_cfg_t		*cfg)
{
	cfg->active_lanes = isys_cfg->csi_port_attr.active_lanes;
	return true;
}

static bool calculate_be_cfg(
	const input_system_input_port_t	*input_port,
	const input_system_cfg_t		*isys_cfg,
	bool metadata,
	csi_rx_backend_cfg_t		*cfg)
{

	memcpy_s(
		(void *)(&cfg->lut_entry),
		sizeof(csi_rx_backend_lut_entry_t),
		metadata ? (void *)(&input_port->metadata.backend_lut_entry) :
			(void *)(&input_port->csi_rx.backend_lut_entry),
		sizeof(csi_rx_backend_lut_entry_t));

	cfg->csi_mipi_packet_type = metadata ?
		get_csi_mipi_packet_type(isys_cfg->metadata.fmt_type) :
		get_csi_mipi_packet_type(isys_cfg->csi_port_attr.fmt_type);
	cfg->csi_mipi_cfg.virtual_channel = isys_cfg->csi_port_attr.ch_id;
	cfg->csi_mipi_cfg.data_type = metadata ? isys_cfg->metadata.fmt_type :
		isys_cfg->csi_port_attr.fmt_type;

	return true;
}

static bool calculate_stream2mmio_cfg(
	const input_system_cfg_t		*isys_cfg,
	bool metadata,
	stream2mmio_cfg_t		*cfg
)
{
	cfg->bits_per_pixel = metadata ? isys_cfg->metadata.bits_per_pixel :
		isys_cfg->input_port_resolution.bits_per_pixel;

	cfg->enable_blocking =
		((isys_cfg->mode == INPUT_SYSTEM_SOURCE_TYPE_TPG) ||
		 (isys_cfg->mode == INPUT_SYSTEM_SOURCE_TYPE_PRBS));

	return true;
}

static bool calculate_ibuf_ctrl_cfg(
	const input_system_channel_t		*channel,
	const input_system_input_port_t	*input_port,
	const input_system_cfg_t		*isys_cfg,
	ibuf_ctrl_cfg_t			*cfg)
{
	const int32_t bits_per_byte = 8;
	int32_t bits_per_pixel;
	int32_t bytes_per_pixel;
	int32_t left_padding;

	(void)input_port;

	bits_per_pixel = isys_cfg->input_port_resolution.bits_per_pixel;
	bytes_per_pixel = ceil_div(bits_per_pixel, bits_per_byte);

	left_padding = CEIL_MUL(isys_cfg->output_port_attr.left_padding, ISP_VEC_NELEMS)
			* bytes_per_pixel;

	cfg->online	= isys_cfg->online;

	cfg->dma_cfg.channel	= channel->dma_channel;
	cfg->dma_cfg.cmd	= _DMA_V2_MOVE_A2B_NO_SYNC_CHK_COMMAND;

	cfg->dma_cfg.shift_returned_items	= 0;
	cfg->dma_cfg.elems_per_word_in_ibuf	= 0;
	cfg->dma_cfg.elems_per_word_in_dest	= 0;

	cfg->ib_buffer.start_addr		= channel->ib_buffer.start_addr;
	cfg->ib_buffer.stride			= channel->ib_buffer.stride;
	cfg->ib_buffer.lines			= channel->ib_buffer.lines;

	/*
	 * zhengjie.lu@intel.com:
	 * "dest_buf_cfg" should be part of the input system output
	 * port configuration.
	 *
	 * TODO: move "dest_buf_cfg" to the input system output
	 * port configuration.
	 */

	 /* input_buf addr only available in sched mode;
	this buffer is allocated in isp, crun mode addr
	can be passed by after ISP allocation */
	if (cfg->online) {
		cfg->dest_buf_cfg.start_addr	= ISP_INPUT_BUF_START_ADDR + left_padding;
		cfg->dest_buf_cfg.stride	= bytes_per_pixel
			* isys_cfg->output_port_attr.max_isp_input_width;
		cfg->dest_buf_cfg.lines		= LINES_OF_ISP_INPUT_BUF;
	} else if (isys_cfg->raw_packed) {
		cfg->dest_buf_cfg.stride	= calculate_packed_stride(bits_per_pixel,
							isys_cfg->input_port_resolution.pixels_per_line);
	} else {
		cfg->dest_buf_cfg.stride	= channel->ib_buffer.stride;
	}

	/*
	 * zhengjie.lu@intel.com:
	 * "items_per_store" is hard coded as "1", which is ONLY valid
	 * when the CSI-MIPI long packet is transferred.
	 *
	 * TODO: After the 1st stage of MERR+,  make the proper solution to
	 * configure "items_per_store" so that it can also handle the CSI-MIPI
	 * short packet.
	 */
	cfg->items_per_store		= 1;

	cfg->stores_per_frame		= isys_cfg->input_port_resolution.lines_per_frame;


	cfg->stream2mmio_cfg.sync_cmd	= _STREAM2MMIO_CMD_TOKEN_SYNC_FRAME;
	if ((isys_cfg->csi_port_attr.fmt_type >= MIPI_FORMAT_CUSTOM0) &&
	    (isys_cfg->csi_port_attr.fmt_type <= MIPI_FORMAT_CUSTOM7))
		/* setup store_words for JPEG and other MIPI USER-DEFINED data types */
		cfg->stream2mmio_cfg.store_cmd	= _STREAM2MMIO_CMD_TOKEN_STORE_WORDS;
	else
		cfg->stream2mmio_cfg.store_cmd	= _STREAM2MMIO_CMD_TOKEN_STORE_PACKETS;

	return true;
}

static bool calculate_isys2401_dma_cfg(
	const input_system_channel_t		*channel,
	const input_system_cfg_t		*isys_cfg,
	isys2401_dma_cfg_t		*cfg)
{
	cfg->channel	= channel->dma_channel;

	/* only online/sensor mode goto vmem
	   offline/buffered_sensor, tpg and prbs will go to ddr */
	if (isys_cfg->online)
		cfg->connection = isys2401_dma_ibuf_to_vmem_connection;
	else
		cfg->connection = isys2401_dma_ibuf_to_ddr_connection;

	cfg->extension	= isys2401_dma_zero_extension;
	cfg->height	= 1;

	return true;
}

static bool calculate_isys2401_dma_port_cfg(
	const input_system_cfg_t		*isys_cfg,
	bool				is_compact_mode,
	bool				metadata,
	isys2401_dma_port_cfg_t		*cfg)
{
	const int32_t bits_per_byte = 8;
	const int32_t bits_per_word = 256;
	int32_t memory_alignment_in_bytes = 32;

	int32_t bits_per_pixel;
	int32_t pixels_per_line;

	int32_t bytes_per_pixel;
	int32_t bytes_per_line;

	int32_t pixels_per_word;
	int32_t words_per_line;
	int32_t bytes_per_word;
	int32_t fmt_type;

	bits_per_pixel = metadata ? isys_cfg->metadata.bits_per_pixel :
		isys_cfg->input_port_resolution.bits_per_pixel;
	pixels_per_line = metadata ? isys_cfg->metadata.pixels_per_line :
		isys_cfg->input_port_resolution.pixels_per_line;
	fmt_type = metadata ? isys_cfg->metadata.fmt_type : isys_cfg->csi_port_attr.fmt_type;

	bytes_per_word  = bits_per_word / bits_per_byte;

	if (is_compact_mode) {
		pixels_per_word = bits_per_word / bits_per_pixel;
		bytes_per_line  = calculate_packed_stride(bits_per_pixel, pixels_per_line);
		words_per_line  = bytes_per_line / bytes_per_word;
	} else {
		/* up-round "bits_per_pixel" to N times of 8-bit */
		bytes_per_pixel = ceil_div(bits_per_pixel, bits_per_byte);
		bits_per_pixel	= bytes_per_pixel *  bits_per_byte;

		bytes_per_line  = bytes_per_pixel * pixels_per_line;
		pixels_per_word = bits_per_word / bits_per_pixel;
		words_per_line  = ceil_div(pixels_per_line, pixels_per_word);
		memory_alignment_in_bytes = calculate_input_system_alignment(fmt_type,
						bytes_per_pixel);
	}

	if (is_compact_mode) {
		cfg->stride = bytes_per_line;
	} else {
		cfg->stride = CEIL_MUL(bytes_per_line, memory_alignment_in_bytes);
	}

	cfg->elements	= pixels_per_word;
	cfg->cropping	= 0;
	cfg->width	= CEIL_MUL(words_per_line,
				(memory_alignment_in_bytes / bytes_per_word));
	return true;
}

static csi_mipi_packet_type_t get_csi_mipi_packet_type(
	int32_t data_type)
{
	csi_mipi_packet_type_t packet_type;

	if (data_type >= 0 && data_type <= 15)
		packet_type = CSI_MIPI_PACKET_TYPE_SHORT;
	else if (data_type >= 16 && data_type <= 55)
		packet_type = CSI_MIPI_PACKET_TYPE_LONG;
	else
		packet_type = CSI_MIPI_PACKET_TYPE_RESERVED;

	return packet_type;
}
/** end of Private Method */
