/* Release Version: irci_master_20140204_0655 */
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

/*! \file */

#ifndef _IA_CSS_H_
#define _IA_CSS_H_

#include <type_support.h>
#include <stdarg.h> /* va_list */
#include "ia_css_types.h"
#include "ia_css_err.h"
#include "ia_css_env.h"
#include "ia_css_frame_public.h"
#include "ia_css_acc_types.h"
#include "ia_css_tpg.h"
#include "ia_css_prbs.h"
#include "ia_css_stream_format.h"
#include "ia_css_metadata.h"
#include "ia_css_dvs.h"
#include "ia_css_3a.h"
#include "ia_css_buffer.h"
#include "ia_css_event_public.h"
#include "ia_css_input_port.h"
#include "ia_css_pipe_public.h"
#include "ia_css_stream_public.h"

/* ID's for refcount */
#define IA_CSS_REFCOUNT_PARAM_SET_POOL  0xCAFE0001
#define IA_CSS_REFCOUNT_PARAM_BUFFER    0xCAFE0002

/** Interrupt types, these enumerate all supported interrupt types.
 */
enum ia_css_irq_type {
	IA_CSS_IRQ_TYPE_EDGE,  /**< Edge (level) sensitive interrupt */
	IA_CSS_IRQ_TYPE_PULSE  /**< Pulse-shaped interrupt */
};

/** Interrupt request type.
 *  When the CSS hardware generates an interrupt, a function in this API
 *  needs to be called to retrieve information about the interrupt.
 *  This interrupt type is part of this information and indicates what
 *  type of information the interrupt signals.
 *
 *  Note that one interrupt can carry multiple interrupt types. For
 *  example: the online video ISP will generate only 2 interrupts, one to
 *  signal that the statistics (3a and DIS) are ready and one to signal
 *  that all output frames are done (output and viewfinder).
 *
 * DEPRECATED, this interface is not portable it should only define user
 * (SW) interrupts
 */
enum ia_css_irq_info {
	IA_CSS_IRQ_INFO_CSS_RECEIVER_ERROR            = 1 << 0,
	/**< the css receiver has encountered an error */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_FIFO_OVERFLOW    = 1 << 1,
	/**< the FIFO in the csi receiver has overflown */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_SOF              = 1 << 2,
	/**< the css receiver received the start of frame */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_EOF              = 1 << 3,
	/**< the css receiver received the end of frame */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_SOL              = 1 << 4,
	/**< the css receiver received the start of line */
	IA_CSS_IRQ_INFO_EVENTS_READY                  = 1 << 5,
	/**< One or more events are available in the event queue */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_EOL              = 1 << 6,
	/**< the css receiver received the end of line */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_SIDEBAND_CHANGED = 1 << 7,
	/**< the css receiver received a change in side band signals */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_GEN_SHORT_0      = 1 << 8,
	/**< generic short packets (0) */
	IA_CSS_IRQ_INFO_CSS_RECEIVER_GEN_SHORT_1      = 1 << 9,
	/**< generic short packets (1) */
	IA_CSS_IRQ_INFO_IF_PRIM_ERROR                 = 1 << 10,
	/**< the primary input formatter (A) has encountered an error */
	IA_CSS_IRQ_INFO_IF_PRIM_B_ERROR               = 1 << 11,
	/**< the primary input formatter (B) has encountered an error */
	IA_CSS_IRQ_INFO_IF_SEC_ERROR                  = 1 << 12,
	/**< the secondary input formatter has encountered an error */
	IA_CSS_IRQ_INFO_STREAM_TO_MEM_ERROR           = 1 << 13,
	/**< the stream-to-memory device has encountered an error */
	IA_CSS_IRQ_INFO_SW_0                          = 1 << 14,
	/**< software interrupt 0 */
	IA_CSS_IRQ_INFO_SW_1                          = 1 << 15,
	/**< software interrupt 1 */
	IA_CSS_IRQ_INFO_SW_2                          = 1 << 16,
	/**< software interrupt 2 */
	IA_CSS_IRQ_INFO_ISP_BINARY_STATISTICS_READY   = 1 << 17,
	/**< ISP binary statistics are ready */
	IA_CSS_IRQ_INFO_INPUT_SYSTEM_ERROR            = 1 << 18,
	/**< the input system in in error */
	IA_CSS_IRQ_INFO_IF_ERROR                      = 1 << 19,
	/**< the input formatter in in error */
	IA_CSS_IRQ_INFO_DMA_ERROR                     = 1 << 20,
	/**< the dma in in error */
};

/** CSS receiver error types. Whenever the CSS receiver has encountered
 *  an error, this enumeration is used to indicate which errors have occurred.
 *
 *  Note that multiple error flags can be enabled at once and that this is in
 *  fact common (whenever an error occurs, it usually results in multiple
 *  errors).
 *
 * DEPRECATED: This interface is not portable, different systems have
 * different receiver types, or possibly none in case of tests systems.
 */
enum ia_css_rx_irq_info {
	IA_CSS_RX_IRQ_INFO_BUFFER_OVERRUN   = 1U << 0, /**< buffer overrun */
	IA_CSS_RX_IRQ_INFO_ENTER_SLEEP_MODE = 1U << 1, /**< entering sleep mode */
	IA_CSS_RX_IRQ_INFO_EXIT_SLEEP_MODE  = 1U << 2, /**< exited sleep mode */
	IA_CSS_RX_IRQ_INFO_ECC_CORRECTED    = 1U << 3, /**< ECC corrected */
	IA_CSS_RX_IRQ_INFO_ERR_SOT          = 1U << 4,
						/**< Start of transmission */
	IA_CSS_RX_IRQ_INFO_ERR_SOT_SYNC     = 1U << 5, /**< SOT sync (??) */
	IA_CSS_RX_IRQ_INFO_ERR_CONTROL      = 1U << 6, /**< Control (??) */
	IA_CSS_RX_IRQ_INFO_ERR_ECC_DOUBLE   = 1U << 7, /**< Double ECC */
	IA_CSS_RX_IRQ_INFO_ERR_CRC          = 1U << 8, /**< CRC error */
	IA_CSS_RX_IRQ_INFO_ERR_UNKNOWN_ID   = 1U << 9, /**< Unknown ID */
	IA_CSS_RX_IRQ_INFO_ERR_FRAME_SYNC   = 1U << 10,/**< Frame sync error */
	IA_CSS_RX_IRQ_INFO_ERR_FRAME_DATA   = 1U << 11,/**< Frame data error */
	IA_CSS_RX_IRQ_INFO_ERR_DATA_TIMEOUT = 1U << 12,/**< Timeout occurred */
	IA_CSS_RX_IRQ_INFO_ERR_UNKNOWN_ESC  = 1U << 13,/**< Unknown escape seq. */
	IA_CSS_RX_IRQ_INFO_ERR_LINE_SYNC    = 1U << 14,/**< Line Sync error */
	IA_CSS_RX_IRQ_INFO_INIT_TIMEOUT     = 1U << 15,
};

/** CSS firmware package structure.
 */
struct ia_css_fw {
	void	    *data;  /**< pointer to the firmware data */
	unsigned int bytes; /**< length in bytes of firmware data */
};

struct ia_css_properties {
	int  gdc_coord_one;
	bool l1_base_is_index; /**< Indicate whether the L1 page base
				    is a page index or a byte address. */
	enum ia_css_vamem_type vamem_type;
};

/** Interrupt info structure. This structure contains information about an
 *  interrupt. This needs to be used after an interrupt is received on the IA
 *  to perform the correct action.
 */
struct ia_css_irq {
	enum ia_css_irq_info type; /**< Interrupt type. */
	unsigned int sw_irq_0_val; /**< In case of SW interrupt 0, value. */
	unsigned int sw_irq_1_val; /**< In case of SW interrupt 1, value. */
	unsigned int sw_irq_2_val; /**< In case of SW interrupt 2, value. */
	struct ia_css_pipe *pipe;
	/**< The image pipe that generated the interrupt. */
};

/* ===== GENERIC ===== */

/** @brief Loads the firmware
 * @param[in]	env		Environment, provides functions to access the
 *				environment in which the CSS code runs. This is
 *				used for host side memory access and message
 *				printing.
 * @param[in]	fw		Firmware package containing the firmware for all
 *				predefined ISP binaries.
 * @return			Returns IA_CSS_ERR_INTERNAL_ERROR in case of any
 *				errors and IA_CSS_SUCCESS otherwise.
 *
 * This function interprets the firmware package. All
 * contents of this firmware package are copied into local data structures, so
 * the fw pointer could be freed after this function completes.
 *
 * Rationale for this function is that it can be called before ia_css_init, and thus
 * speeds up ia_css_init (ia_css_init is called each time a stream is created but the
 * firmware only needs to be loaded once).
 */
enum ia_css_err
ia_css_load_firmware(const struct ia_css_env *env,
	    const struct ia_css_fw  *fw);

/** @brief Unloads the firmware
 * @return	None
 *
 * This function unloads the firmware loaded by ia_css_load_firmware.
 * It is pointless to call this function if no firmware is loaded,
 * but it won't harm. Use this to deallocate all memory associated with the firmware.
 */
void
ia_css_unload_firmware(void);

/** @brief Initialize the CSS API.
 * @param[in]	env		Environment, provides functions to access the
 *				environment in which the CSS code runs. This is
 *				used for host side memory access and message
 *				printing. May not be NULL.
 * @param[in]	fw		Firmware package containing the firmware for all
 *				predefined ISP binaries.
 *				if fw is NULL the firmware must be loaded before
 *				through a call of ia_css_load_firmware
 * @param[in]	l1_base         Base index (isp2400)
 *                              of the L1 page table. This is a physical
 *                              address or index.
 * @param[in]	irq_type	The type of interrupt to be used (edge or level)
 * @return				Returns IA_CSS_ERR_INTERNAL_ERROR in case of any
 *				errors and IA_CSS_SUCCESS otherwise.
 *
 * This function initializes the API which includes allocating and initializing
 * internal data structures. This also interprets the firmware package. All
 * contents of this firmware package are copied into local data structures, so
 * the fw pointer could be freed after this function completes.
 */
enum ia_css_err ia_css_init(
	const struct ia_css_env *env,
	const struct ia_css_fw  *fw,
	uint32_t                 l1_base,
	enum ia_css_irq_type     irq_type);

/** @brief Un-initialize the CSS API.
 * @return	None
 *
 * This function deallocates all memory that has been allocated by the CSS API
 * Exception: if you explicitly loaded firmware through ia_css_load_firmware
 * you need to call ia_css_unload_firmware to deallocate the memory reserved
 * for the firmware.
 * After this function is called, no other CSS functions should be called
 * with the exception of ia_css_init which will re-initialize the CSS code,
 * ia_css_unload_firmware to unload the firmware or ia_css_load_firmware
 * to load new firmware
 */
void
ia_css_uninit(void);

/** @brief Suspend CSS API for power down (NOT IMPLEMENTED YET).
 *
 * IMPORTANT NOTE: This function is a place-holder for a future implementation
 * and it is not used at the moment. Below is the information what this
 * function should do when implemented.
 *
 * This function prepares the CSS API for a power down of the CSS hardware.
 * This will make sure the hardware is idle. After this function is called,
 * always call ia_css_resume before calling any other CSS functions.
 * This assumes that all buffers allocated in DDR will remain alive during
 * power down. If this is not the case, use ia_css_unit() followed by
 * ia_css_init() at power up.
 */
void
ia_css_suspend(void);

/** @brief Resume CSS API from power down
 *
 * @return	None
 *
 * After a power cycle, this function will bring the CSS API back into
 * a state where it can be started. This will re-initialize the hardware.
 * Call this function only after ia_css_suspend() has been called.
 */
void
ia_css_resume(void);

/** @brief Get hardware properties
 * @param[in,out]	properties The hardware properties
 * @return	None
 *
 * This function returns a number of hardware properties.
 */
void
ia_css_get_properties(struct ia_css_properties *properties);

/** @brief Obtain interrupt information.
 *
 * @param[out] info	Pointer to the interrupt info. The interrupt
 *			information wil be written to this info.
 * @return		If an error is encountered during the interrupt info
 *			and no interrupt could be translated successfully, this
 *			will return IA_CSS_INTERNAL_ERROR. Otherwise
 *			IA_CSS_SUCCESS.
 *
 * This function is expected to be executed after an interrupt has been sent
 * to the IA from the CSS. This function returns information about the interrupt
 * which is needed by the IA code to properly handle the interrupt. This
 * information includes the image pipe, buffer type etc.
 */
enum ia_css_err
ia_css_irq_translate(unsigned int *info);

/** @brief Get CSI receiver error info.
 *
 * @param[out] irq_bits	Pointer to the interrupt bits. The interrupt
 *			bits will be written this info.
 *			This will be the error bits that are enabled in the CSI
 *			receiver error register.
 * @return	None
 *
 * This function should be used whenever a CSI receiver error interrupt is
 * generated. It provides the detailed information (bits) on the exact error
 * that occurred.
 */
void
ia_css_rx_get_irq_info(unsigned int *irq_bits);

/** @brief Clear CSI receiver error info.
 *
 * @param[in] irq_bits	The bits that should be cleared from the CSI receiver
 *			interrupt bits register.
 * @return	None
 *
 * This function should be called after ia_css_rx_get_irq_info has been called
 * and the error bits have been interpreted. It is advised to use the return
 * value of that function as the argument to this function to make sure no new
 * error bits get overwritten.
 */
void
ia_css_rx_clear_irq_info(unsigned int irq_bits);

/** @brief Enable or disable specific interrupts.
 *
 * @param[in] type	The interrupt type that will be enabled/disabled.
 * @param[in] enable	enable or disable.
 * @return		Returns IA_CSS_INTERNAL_ERROR if this interrupt
 *			type cannot be enabled/disabled which is true for
 *			CSS internal interrupts. Otherwise returns
 *			IA_CSS_SUCCESS.
 */
enum ia_css_err
ia_css_irq_enable(enum ia_css_irq_info type, bool enable);

/** @brief Invalidate the MMU internal cache.
 * @return	None
 *
 * This function triggers an invalidation of the translate-look-aside
 * buffer (TLB) that's inside the CSS MMU. This function should be called
 * every time the page tables used by the MMU change.
 */
void
ia_css_mmu_invalidate_cache(void);

/** @brief Test whether the ISP has started.
 *
 * @return	Boolean flag true if the ISP has started or false otherwise.
 *
 * Temporary function to poll whether the ISP has been started. Once it has,
 * the sensor can also be started. */
bool
ia_css_isp_has_started(void);

/** @brief Test whether the SP has initialized.
 *
 * @return	Boolean flag true if the SP has initialized or false otherwise.
 *
 * Temporary function to poll whether the SP has been initialized. Once it has,
 * we can enqueue buffers. */
bool
ia_css_sp_has_initialized(void);

/** @brief Test whether the SP has terminated.
 *
 * @return	Boolean flag true if the SP has terminated or false otherwise.
 *
 * Temporary function to poll whether the SP has been terminated. Once it has,
 * we can switch mode. */
bool
ia_css_sp_has_terminated(void);

/* Convenience functions for alloc/free of certain datatypes */

/** @brief Morphing table
 * @param[in]	width Width of the morphing table.
 * @param[in]	height Height of the morphing table.
 * @return		Pointer to the morphing table
*/
struct ia_css_morph_table *
ia_css_morph_table_allocate(unsigned int width, unsigned int height);

/** @brief Free the morph table
 * @param[in]	me Pointer to the morph table.
 * @return		None
*/
void
ia_css_morph_table_free(struct ia_css_morph_table *me);

/** @brief Shading table
 * @param[in]	width Width of the shading table.
 * @param[in]	height Height of the shading table.
 * @return		Pointer to the shading table
*/
struct ia_css_shading_table *
ia_css_shading_table_alloc(unsigned int width,
			   unsigned int height);

/** @brief Free shading table
 * @param[in]	table Pointer to the shading table.
 * @return		None
*/
void
ia_css_shading_table_free(struct ia_css_shading_table *table);

/** @brief start SP hardware
 *
 * @return			IA_CSS_SUCCESS or error code upon error.
 *
 * It will boot the SP hardware and start multi-threading infrastructure.
 * All threads will be started and blocked by semaphore. This function should
 * be called before any ia_css_stream_start().
 */
enum ia_css_err
ia_css_start_sp(void);


/** @brief stop SP hardware
 *
 * @return			IA_CSS_SUCCESS or error code upon error.
 *
 * This function will terminate all threads and shut down SP. It should be
 * called after all ia_css_stream_stop().
 */
enum ia_css_err
ia_css_stop_sp(void);

/** Backward compatible for CSS API 2.0 only
 * TO BE REMOVED when all drivers move to CSS API 2.1.
 */
/** @brief Specify a CSS MIPI frame buffer.
 *
 * @param[in]	size_mem_words	The frame size in memory words (32B).
 * @param[in]	contiguous	Allocate memory physically contiguously or not.
 * @return		The error code.
 *
 * Specifies a CSS MIPI frame buffer: size in memory words (32B).
 */
enum ia_css_err
ia_css_mipi_frame_specify(const unsigned int	size_mem_words,
				const bool contiguous);

#if !defined(HAS_NO_INPUT_SYSTEM)
/** @brief Register size of a CSS MIPI frame for check during capturing.
 *
 * @param[in]	port	CSI-2 port this check is registered.
 * @param[in]	size_mem_words	The frame size in memory words (32B).
 * @return		Return the error in case of failure. E.g. MAX_NOF_ENTRIES REACHED
 *
 * Register size of a CSS MIPI frame to check during capturing. Up to
 *		IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES entries per port allowed. Entries are reset
 *		when stream is stopped.
 *
 *
 */
enum ia_css_err
ia_css_mipi_frame_enable_check_on_size(const enum ia_css_csi2_port port,
				const unsigned int	size_mem_words);
#endif

/** @brief Dequeue param buffers from sp2host_queue
 *
 * @return                                       None
 *
 * This function must be called at every driver interrupt handler to prevent
 * overflow of sp2host_queue.
 */
void
ia_css_dequeue_param_buffers(void);

#endif /* _IA_CSS_H_ */
