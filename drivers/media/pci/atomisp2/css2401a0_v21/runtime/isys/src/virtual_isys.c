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

#include "input_system.h"
#include "ia_css_isys.h"

/* cmd for storing a number of packets indicated by reg _STREAM2MMIO_NUM_ITEMS*/
#define _STREAM2MMIO_CMD_TOKEN_STORE_PACKETS	1

/* command for waiting for a frame start */
#define _STREAM2MMIO_CMD_TOKEN_SYNC_FRAME	2

/*************************************************
 *
 * Forwarded Declaration
 *
 *************************************************/
#ifndef ceil_div
#define ceil_div(a,b)       (((a)+(b)-1)/(b))
#endif

static bool create_input_system_channel(
	input_system_cfg_t	*cfg,
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
	input_system_channel_cfg_t	*channel_cfg);

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
	ib_buffer_t *buf);

static void release_ib_buffer(
	ib_buffer_t *buf);

static bool acquire_dma_channel(
	isys2401_dma_channel *channel);

static void release_dma_channel(
	isys2401_dma_channel *channel);

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
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	csi_rx_frontend_cfg_t		*cfg);

static bool calculate_be_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	csi_rx_backend_cfg_t		*cfg);

static bool calculate_stream2mmio_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	stream2mmio_cfg_t		*cfg);

static bool calculate_ibuf_ctrl_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	ibuf_ctrl_cfg_t			*cfg);

static bool calculate_isys2401_dma_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	isys2401_dma_cfg_t		*cfg);

static bool calculate_isys2401_dma_port_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	bool				is_compact_mode,
	isys2401_dma_port_cfg_t		*cfg);

static csi_mipi_packet_type_t get_csi_mipi_packet_type(
	int32_t data_type);
/** end of Forwarded Declaration */

/**************************************************
 *
 * Public Method
 *
 **************************************************/
bool ia_css_virtual_isys_create(
	ia_css_isys_cfg_t	*cfg,
	ia_css_virtual_isys_t	*me)
{
	bool rc;

	if (cfg == NULL || me == NULL) {
		return	false;
	}

	rc = create_input_system_input_port(cfg, &(me->input_port));
	if (rc == false) {
		return false;
	}

	rc = create_input_system_channel(cfg, &(me->channel));
	if (rc == false) {
		destroy_input_system_input_port(&(me->input_port));
		return false;
	}

	return true;
}

void ia_css_virtual_isys_destroy(
	ia_css_virtual_isys_t	*me)
{
	destroy_input_system_input_port(&(me->input_port));
	destroy_input_system_channel(&(me->channel));
}

bool ia_css_virtual_isys_calculate_cfg(
	ia_css_virtual_isys_t		*me,
	ia_css_isys_cfg_t		*isys_cfg,
	ia_css_virtual_isys_cfg_t	*virtual_isys_cfg)
{
	bool rc;

	if (virtual_isys_cfg == NULL	||
		isys_cfg == NULL	||
		me == NULL)
		return false;

	rc  = calculate_input_system_channel_cfg(
			&(me->channel),
			&(me->input_port),
			isys_cfg,
			&(virtual_isys_cfg->channel_cfg));
	if (rc == false)
		return false;

	rc = calculate_input_system_input_port_cfg(
			&(me->channel),
			&(me->input_port),
			isys_cfg,
			&(virtual_isys_cfg->input_port_cfg));
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


	if (!acquire_sid(me->stream2mmio_id,
			&(me->stream2mmio_sid_id))) {
		return false;
	}

	if (!acquire_ib_buffer(
			cfg->input_port_resolution.bits_per_pixel,
			cfg->input_port_resolution.pixels_per_line,
			cfg->input_port_resolution.lines_per_frame,
			&(me->ib_buffer))) {
		release_sid(me->stream2mmio_id,
			&(me->stream2mmio_sid_id));
		return false;
	}

	if (!acquire_dma_channel(&(me->dma_channel))) {
		release_sid(me->stream2mmio_id,
			&(me->stream2mmio_sid_id));

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

	release_dma_channel(&(me->dma_channel));
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
	input_system_channel_cfg_t	*channel_cfg)
{
	bool rc;

	rc = calculate_stream2mmio_cfg(
			channel,
			input_port,
			isys_cfg,
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

	rc = calculate_isys2401_dma_cfg(
			channel,
			input_port,
			isys_cfg,
			&(channel_cfg->dma_cfg));
	if (rc == false)
		return false;

	rc = calculate_isys2401_dma_port_cfg(
			channel,
			input_port,
			isys_cfg,
			false,
			&(channel_cfg->dma_src_port_cfg));
	if (rc == false)
		return false;

	rc = calculate_isys2401_dma_port_cfg(
			channel,
			input_port,
			isys_cfg,
			false,
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
				channel,
				input_port,
				isys_cfg,
				&(input_port_cfg->csi_rx_cfg.frontend_cfg));

		rc &= calculate_be_cfg(
				channel,
				input_port,
				isys_cfg,
				&(input_port_cfg->csi_rx_cfg.backend_cfg));
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
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */
	(void)(stream2mmio);

	/* TODO: acquire the resource */

	*sid = STREAM2MMIO_SID0_ID;
	return true;
}

static void release_sid(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */
	(void)(stream2mmio);
	(void)(sid);

	/* TODO: release the resource */
}

static bool acquire_ib_buffer(
	int32_t bits_per_pixel,
	int32_t pixels_per_line,
	int32_t lines_per_frame,
	ib_buffer_t *buf)
{
	const int32_t bits_per_byte = 8;
	int32_t	bytes_per_pixel;
	int32_t bytes_per_line;

	bytes_per_pixel = ceil_div(bits_per_pixel, bits_per_byte);
	bytes_per_line  = bytes_per_pixel * pixels_per_line;

	buf->stride = bytes_per_line;

	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */

	/* TODO: acquire the resource */
	(void)lines_per_frame;

	buf->start_addr = 0;
	buf->lines = 2; /* ISYS2401 hardware can handle at most 4 lines */

	return true;
}

static void release_ib_buffer(
	ib_buffer_t *buf)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */

	/* TODO: release the resource */
	(void)buf;
}

static bool acquire_dma_channel(
	isys2401_dma_channel *channel)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */
	
	/* TODO: acquire the resource */
	
	*channel = 0;
	return true;
}

static void release_dma_channel(
	isys2401_dma_channel *channel)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */
	(void)(channel);
	/* TODO: release the resource */
}

static bool acquire_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */

	/* TODO: acquire the resource */
	entry->long_packet_entry = 0;
	entry->short_packet_entry = 0;

	(void)(backend);
	(void)(packet_type);

	return true;
}

static void release_be_lut_entry(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry)
{
	/*
	 * zhengjie.lu@intel.com:
	 * implment this interface after the 1st stage.
	 */

	/* TODO: release the resource */
	(void)backend;
	(void)packet_type;
	(void)entry;
}

static bool calculate_tpg_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	pixelgen_tpg_cfg_t		*cfg)
{
	(void)channel;
	(void)input_port;

	memcpy(
		(void*)cfg,
		(void*)(&(isys_cfg->tpg_port_attr)),
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

	memcpy(
		(void *)cfg,
		(void *)(&(isys_cfg->prbs_port_attr)),
		sizeof(pixelgen_prbs_cfg_t));

	return true;
}

static bool calculate_fe_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	csi_rx_frontend_cfg_t		*cfg)
{
	(void)channel;
	(void)input_port;

	cfg->active_lanes = isys_cfg->csi_port_attr.active_lanes;
	return true;
}

static bool calculate_be_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	csi_rx_backend_cfg_t		*cfg)
{
	(void)channel;

	memcpy(
		(void *)(&(cfg->lut_entry)),
		(void *)(&(input_port->csi_rx.backend_lut_entry)),
		sizeof(csi_rx_backend_lut_entry_t));

	cfg->csi_mipi_packet_type =
		get_csi_mipi_packet_type(isys_cfg->csi_port_attr.fmt_type);

	cfg->csi_mipi_cfg.virtual_channel	= isys_cfg->csi_port_attr.ch_id;
	cfg->csi_mipi_cfg.data_type		= isys_cfg->csi_port_attr.fmt_type;

	return true;
}

static bool calculate_stream2mmio_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	stream2mmio_cfg_t		*cfg)
{
	(void)channel;
	(void)input_port;

	cfg->bits_per_pixel = isys_cfg->input_port_resolution.bits_per_pixel;
	return true;
}

static bool calculate_ibuf_ctrl_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	ibuf_ctrl_cfg_t			*cfg)
{
	(void)input_port;

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
	cfg->dest_buf_cfg.stride	= channel->ib_buffer.stride;

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
	cfg->stream2mmio_cfg.store_cmd	= _STREAM2MMIO_CMD_TOKEN_STORE_PACKETS;

	return true;
}

static bool calculate_isys2401_dma_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	isys2401_dma_cfg_t		*cfg)
{
	(void)input_port;
	(void)isys_cfg;

	cfg->channel	= channel->dma_channel;

	/**
	 * zhengjie.lu@intel.com:
	 * The connection is hard coded to "ibuf => ddr". It is not
	 * applicable for the offline case.
	 */
	cfg->connection = isys2401_dma_ibuf_to_ddr_connection;

	cfg->extension	= isys2401_dma_zero_extension;
	cfg->height	= 1;

	return true;
}

static bool calculate_isys2401_dma_port_cfg(
	input_system_channel_t		*channel,
	input_system_input_port_t	*input_port,
	input_system_cfg_t		*isys_cfg,
	bool				is_compact_mode,
	isys2401_dma_port_cfg_t		*cfg)
{
	const int32_t bits_per_byte = 8;
	const int32_t bits_per_word = 256;

	int32_t bits_per_pixel;
	int32_t pixels_per_line;

	int32_t bytes_per_pixel;
	int32_t bytes_per_line;

	int32_t pixels_per_word;
	int32_t words_per_line;
	int32_t bytes_per_word;

	(void)channel;
	(void)input_port;

	bits_per_pixel  = isys_cfg->input_port_resolution.bits_per_pixel;
	pixels_per_line = isys_cfg->input_port_resolution.pixels_per_line;

	bytes_per_word  = bits_per_word / bits_per_byte;

	if (is_compact_mode) {
		/* compact as many pixels as possible into a word */
		pixels_per_word = bits_per_word / bits_per_pixel;

		words_per_line  = ceil_div(pixels_per_line, pixels_per_word);
		bytes_per_line  = bytes_per_word * words_per_line;
	} else {
		/* up-round "bits_per_pixel" to N times of 8-bit */
		bytes_per_pixel = ceil_div(bits_per_pixel, bits_per_byte);
		bits_per_pixel	= bytes_per_pixel *  bits_per_byte;

		bytes_per_line  = bytes_per_pixel * pixels_per_line;
		pixels_per_word = bits_per_word / bits_per_pixel;
		words_per_line  = ceil_div(pixels_per_line, pixels_per_word);
	}

	cfg->stride	= bytes_per_line;
	cfg->elements	= pixels_per_word;
	cfg->cropping	= 0;
	cfg->width	= words_per_line;
	return true;
}

static csi_mipi_packet_type_t get_csi_mipi_packet_type(
	int32_t data_type)
{
	csi_mipi_packet_type_t packet_type;

	if (data_type >= 0 && data_type <= 15) {
		packet_type = CSI_MIPI_PACKET_TYPE_SHORT;
	} else if (data_type >= 16 && data_type <= 55) {
		packet_type = CSI_MIPI_PACKET_TYPE_LONG;
	} else {
		packet_type = CSI_MIPI_PACKET_TYPE_RESERVED;
	}

	return packet_type;
}
/** end of Private Method */
