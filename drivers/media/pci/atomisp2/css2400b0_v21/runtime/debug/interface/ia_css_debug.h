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

#ifndef _IA_CSS_DEBUG_H_
#define _IA_CSS_DEBUG_H_

/*! \file */

#ifndef __INLINE_STREAM2MMIO__
#define __INLINE_STREAM2MMIO__
#endif
#include "ia_css.h"
#include "sh_css_internal.h"

/* available levels */
/*! Level for tracing errors */
#define IA_CSS_DEBUG_ERROR   1
/*! Level for tracing warnings */
#define IA_CSS_DEBUG_WARNING 3
/*! Level for tracing debug messages */
#define IA_CSS_DEBUG_VERBOSE   5
/*! Level for tracing trace messages a.o. ia_css public function calls */
#define IA_CSS_DEBUG_TRACE   6
/*! Level for tracing trace messages a.o. ia_css private function calls */
#define IA_CSS_DEBUG_TRACE_PRIVATE   7
/*! Level for tracing parameter messages e.g. in and out params of functions */
#define IA_CSS_DEBUG_PARAM   8
/*! Level for tracing info messages */
#define IA_CSS_DEBUG_INFO    9
/* Global variable which controls the verbosity levels of the debug tracing */
extern unsigned int ia_css_debug_trace_level;

/*! \brief Enum defining the different isp parameters to dump.
 *  Values can be combined to dump a combination of sets.
 */
enum ia_css_debug_enable_param_dump {
	IA_CSS_DEBUG_DUMP_FPN = 1 << 0, /**< FPN table */
	IA_CSS_DEBUG_DUMP_OB = 1 << 1,  /**< OB table */
	IA_CSS_DEBUG_DUMP_SC = 1 << 2,  /**< Shading table */
	IA_CSS_DEBUG_DUMP_WB = 1 << 3,  /**< White balance */
	IA_CSS_DEBUG_DUMP_DP = 1 << 4,  /**< Defect Pixel */
	IA_CSS_DEBUG_DUMP_BNR = 1 << 5,  /**< Bayer Noise Reductions */
	IA_CSS_DEBUG_DUMP_S3A = 1 << 6,  /**< 3A Statistics */
	IA_CSS_DEBUG_DUMP_DE = 1 << 7,  /**< De Mosaicing */
	IA_CSS_DEBUG_DUMP_YNR = 1 << 8,  /**< Luma Noise Reduction */
	IA_CSS_DEBUG_DUMP_CSC = 1 << 9,  /**< Color Space Conversion */
	IA_CSS_DEBUG_DUMP_GC = 1 << 10,  /**< Gamma Correction */
	IA_CSS_DEBUG_DUMP_TNR = 1 << 11,  /**< Temporal Noise Reduction */
	IA_CSS_DEBUG_DUMP_ANR = 1 << 12,  /**< Advanced Noise Reduction */
	IA_CSS_DEBUG_DUMP_CE = 1 << 13,  /**< Chroma Enhancement */
	IA_CSS_DEBUG_DUMP_ALL = 1 << 14  /**< Dump all device parameters */
};

/*! \brief Function for tracing to the provided printf function in the
 *	environment.
 * \param[in]	level		Level of the message.
 * \param[in]	fmt		printf like format string
 * \param[in]	args		arguments for the format string
 */
STORAGE_CLASS_INLINE void
ia_css_debug_vdtrace(unsigned int level, const char *fmt, va_list args)
{
	if (ia_css_debug_trace_level >= level)
		sh_css_vprint(fmt, args);
}

STORAGE_CLASS_INLINE void
ia_css_debug_dtrace(unsigned int level, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	ia_css_debug_vdtrace(level, fmt, ap);
	va_end(ap);
}

/*! \brief Function to set the global dtrace verbosity level.
 * \param[in]	trace_level	Maximum level of the messages to be traced.
 * \return	None
 */
extern void ia_css_debug_set_dtrace_level(
	const unsigned int	trace_level);

/*! \brief Dump input formatter state.
 * Dumps the input formatter state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_if_state(void);

/*! \brief Dump isp hardware state.
 * Dumps the isp hardware state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_isp_state(void);

/*! \brief Dump sp hardware state.
 * Dumps the sp hardware state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_sp_state(void);

/*! \brief Dump dma controller state.
 * Dumps the dma controller state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_dma_state(void);

/*! \brief Dump internal sp software state.
 * Dumps the sp software state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_sp_sw_debug_info(void);

/*! \brief Dump all related hardware state to the trace output
 * \param[in]  context	String to identify context in output.
 * \return	None
 */
extern void ia_css_debug_dump_debug_info(
	const char	*context);

#if SP_DEBUG != SP_DEBUG_NONE
extern void ia_css_debug_print_sp_debug_state(
	const struct sh_css_sp_debug_state *state);
#endif

/*! \brief Dump all related binary info data
 * \param[in]  bi	Binary info struct.
 * \return	None
 */
extern void ia_css_debug_binary_print(
	const struct ia_css_binary *bi);

extern void
ia_css_debug_sp_dump_mipi_fifo_high_water(void);

/*! \brief Dump isp gdc fifo state to the trace output
 * Dumps the isp gdc fifo state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_isp_gdc_fifo_state(void);

/*! \brief Dump dma isp fifo state
 * Dumps the dma isp fifo state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_dma_isp_fifo_state(void);

/*! \brief Dump dma sp fifo state
 * Dumps the dma sp fifo state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_dma_sp_fifo_state(void);

/*! \brief Dump pif isp fifo state
 * Dumps the primary input formatter state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_pif_isp_fifo_state(void);

/*! \brief Dump isp sp fifo state
 * Dumps the isp sp fifo state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_isp_sp_fifo_state(void);

/*! \brief Dump all fifo state info to the output
 * Dumps all fifo state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_all_fifo_state(void);

/*! \brief Dump the rx state to the output
 * Dumps the rx state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_rx_state(void);

/*! \brief Dump the input system state to the output
 * Dumps the input system state to tracing output.
 * \return	None
 */
extern void ia_css_debug_dump_isys_state(void);

/*! \brief Dump the frame info to the trace output
 * Dumps the frame info to tracing output.
 * \param[in]	frame		pointer to struct ia_css_frame
 * \param[in]	descr		description output along with the frame info
 * \return	None
 */
extern void ia_css_debug_frame_print(
	const struct ia_css_frame	*frame,
	const char	*descr);

/*! \brief Function to enable sp sleep mode.
 * Function that enables sp sleep mode
 * \param[in]	mode		indicates when to put sp to sleep
 * \return	None
 */
extern void
ia_css_debug_enable_sp_sleep_mode(enum ia_css_sp_sleep_mode mode);

/*! \brief Function to wake up sp when in sleep mode.
 * After sp has been put to sleep, use this function to let it continue
 * to run again.
 * \return	None
 */
extern void
ia_css_debug_wake_up_sp(void);

/*! \brief Function to dump isp parameters.
 * Dump isp parameters to tracing output
 * \param[in]	enable		flag indicating which parameters to dump.
 * \return	None
 */
extern void
ia_css_debug_dump_isp_params(struct ia_css_stream *stream, unsigned int enable);

/*! \brief Function to dump some sp performance counters.
 * Dump sp performance counters, currently input system errors.
 * \return	None
 */
extern void
ia_css_debug_dump_perf_counters(void);

#ifdef HAS_WATCHDOG_SP_THREAD_DEBUG
void sh_css_dump_thread_wait_info(void);
void	sh_css_dump_pipe_stage_info(void);
void	sh_css_dump_pipe_stripe_info(void);
#endif

extern void
ia_css_debug_dump_isp_binary(void);

extern void sh_css_dump_sp_raw_copy_linecount(bool reduced);

/*
extern void sh_css_init_ddr_debug_queue(void);
extern void sh_css_load_ddr_debug_queue(void);
extern void sh_css_dump_ddr_debug_queue(void); */

/**
 * @brief Initialize the debug mode.
 *
 * WARNING:
 * This API should be called ONLY once in the debug mode.
 *
 * @return
 *	- true, if it is successful.
 *	- false, otherwise.
 */
extern bool ia_css_debug_mode_init(void);

/**
 * @brief Disable the DMA channel.
 *
 * @param[in]	dma_ID		The ID of the target DMA.
 * @param[in]	channel_id	The ID of the target DMA channel.
 * @param[in]	request_type	The type of the DMA request.
 *				For example:
 *				- "0" indicates the writing request.
 *				- "1" indicates the reading request.
 *
 * This is part of the DMA API -> dma.h
 *
 * @return
 *	- true, if it is successful.
 *	- false, otherwise.
 */
extern bool ia_css_debug_mode_disable_dma_channel(
	int dma_ID,
		int channel_id,
		int request_type);
/**
 * @brief Enable the DMA channel.
 *
 * @param[in]	dma_id		The ID of the target DMA.
 * @param[in]	channel_id	The ID of the target DMA channel.
 * @param[in]	request_type	The type of the DMA request.
 *				For example:
 *				- "0" indicates the writing request.
 *				- "1" indicates the reading request.
 *
 *	- true, if it is successful.
 *	- false, otherwise.
 */
extern bool ia_css_debug_mode_enable_dma_channel(
	int dma_ID,
		int channel_id,
		int request_type);



#endif /* _IA_CSS_DEBUG_H_ */
