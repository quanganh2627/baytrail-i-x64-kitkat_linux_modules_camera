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

#ifndef _IA_CSS_CIRCBUF_H
#define _IA_CSS_CIRCBUF_H

#include "assert_support.h"
#ifdef __SP
#include <hive_isp_css_sp_api_modified.h>
#include <system_types.h>
#endif

#include "type_support.h"
#include "platform_support.h"

/****************************************************************
 *
 * Macro definitions.
 *
 ****************************************************************/
/**
 * @brief Define the circular buffer state.
 * The circular buffer state should ONLY be used inside
 * the circular buffer APIs.
 */
#define _CB_STATE_NULL		0
#define _CB_STATE_NEUTRAL	1
#define _CB_STATE_EMPTY		2
#define _CB_STATE_FULL		3

/****************************************************************
 *
 * Data structures.
 *
 ****************************************************************/
/**
 * @brief Data structure for the circular buffer element.
 */
typedef struct ia_css_circbuf_elem_s ia_css_circbuf_elem_t;
struct ia_css_circbuf_elem_s {
	uint32_t val;	/* the value stored in the element */
};

/**
 * @brief Data structure for the circular buffer.
 */
typedef struct ia_css_circbuf_s ia_css_circbuf_t;
struct ia_css_circbuf_s {
	uint8_t size;	/* the maximum number of elements
			   (always one empty slot) */
	uint8_t start;	/* index of the oldest element             */
	uint8_t end;	/* index at which to write the new element */

	ia_css_circbuf_elem_t *elems;	/* an array of elements    */
};

/**********************************************************************
 *
 * Forward declarations.
 *
 **********************************************************************/
/**
 * @brief Create the circular buffer.
 *
 * @param cb	The pointer to the circular buffer.
 * @param elems	An array of elements.
 * @param sz	The maximum number of elements.
 */
extern void ia_css_circbuf_create(ia_css_circbuf_t *cb,
				       ia_css_circbuf_elem_t *elems,
				       uint32_t sz);

/**
 * @brief Destroy the circular buffer.
 *
 * @param cb The pointer to the circular buffer.
 */
extern void ia_css_circbuf_destroy(ia_css_circbuf_t *cb);

/**
 * @brief Push a value in the circular buffer.
 * Put a new value at the tail of the circular buffer.
 * The user should call "ia_css_circbuf_is_full()"
 * to avoid accessing to a full buffer.
 *
 * @param cb	The pointer to the circular buffer.
 * @param val	The value to be pushed in.
 */
static inline void ia_css_circbuf_push(ia_css_circbuf_t *cb,
					    uint32_t val);

/**
 * @brief Pop a value out of the circular buffer.
 * Get a value at the head of the circular buffer.
 * The user should call "ia_css_circbuf_is_empty()"
 * to avoid accessing to an empty buffer.
 *
 * @param cb	The pointer to the circular buffer.
 *
 * @return the pop-out value.
 */
extern uint32_t ia_css_circbuf_pop(ia_css_circbuf_t *cb);

/**
 * @brief Extract a value out of the circular buffer.
 * Get a value at an arbitrary poistion in the circular
 * buffer. The user should call "ia_css_circbuf_is_empty()"
 * to avoid accessing to an empty buffer.
 *
 * @param cb	 The pointer to the circular buffer.
 * @param offset The offset from "start" to the target position.
 *
 * @return the extracted value.
 */
extern uint32_t ia_css_circbuf_extract(ia_css_circbuf_t *cb,
						int offset);

#if 0
/**
 * @brief Test if the circular buffer becomes not full.
 * Test whether the previous state is "full" and the current
 * state is "neutral".
 *
 * @param cb	The pointer to the circular buffer.
 *
 * @return
 *	- true when it is full.
 *	- false when it is not full.
 */
extern bool ia_css_circbuf_becomes_not_full(ia_css_circbuf_t *cb);
#endif
/**
 * @brief Get a position in the circular buffer.
 *
 * @param cb     The pointer to the circular buffer.
 * @param base   The base position.
 * @param offset The offset.
 *
 * @return the position in the circular buffer.
 */
static inline uint8_t ia_css_circbuf_get_pos(ia_css_circbuf_t *
						       cb, uint32_t base,
						       int offset);
/**
 * @brief Get the offset between two positions in the circular buffer.
 * Get the offset from the source position to the terminal position,
 * along the direction in which the new elements come in.
 *
 * @param cb	   The pointer to the circular buffer.
 * @param src_pos  The source position.
 * @param dest_pos The terminal position.
 *
 * @return the offset.
 */
static inline int ia_css_circbuf_get_offset(ia_css_circbuf_t *cb,
						 uint32_t src_pos,
						 uint32_t dest_pos);

/**
 * @brief Get the maximum number of elements.
 *
 * @param cb The pointer to the circular buffer.
 *
 * @return the maximum number of elements.
 *
 * TODO: Test this API.
 */
static inline uint32_t ia_css_circbuf_get_size(ia_css_circbuf_t *
							cb);

/**
 * @brief Get the number of availalbe elements.
 *
 * @param cb The pointer to the circular buffer.
 *
 * @return the number of available elements.
 */
static inline uint32_t
ia_css_circbuf_get_num_elems(ia_css_circbuf_t *cb);

/**
 * @brief Test if the circular buffer is empty.
 *
 * @param cb	The pointer to the circular buffer.
 *
 * @return
 *	- true when it is empty.
 *	- false when it is not empty.
 */
static inline bool ia_css_circbuf_is_empty(ia_css_circbuf_t *cb);

/**
 * @brief Test if the circular buffer is full.
 *
 * @param cb	The pointer to the circular buffer.
 *
 * @return
 *	- true when it is full.
 *	- false when it is not full.
 */
static inline bool ia_css_circbuf_is_full(ia_css_circbuf_t *cb);
#if 0
/**
 * @brief Test if the circular buffer becomes not empty.
 * Test whether the previous state is "empty" and the current
 * state is "neutral".
 *
 * @param cb	The pointer to the circular buffer.
 *
 * @return
 *	- true, if it succeeds.
 *	- false, otherwise.
 */
static inline bool ia_css_circbuf_becomes_not_empty(ia_css_circbuf_t *
							 cb);
#endif
/**
 * @brief Initialize the element.
 *
 * @param elem The pointer to the element.
 */
static inline void ia_css_circbuf_elem_init(ia_css_circbuf_elem_t *
						 elem);

/**
 * @brief Set the "val" field in the element.
 *
 * @param elem The pointer to the element.
 * @param val  The value to be set.
 */
static inline void ia_css_circbuf_elem_set_val(ia_css_circbuf_elem_t *
						    elem, uint32_t val);

/**
 * @brief Copy an element.
 *
 * @param src  The element as the copy source.
 * @param dest The element as the copy destination.
 */
static inline void ia_css_circbuf_elem_cpy(ia_css_circbuf_elem_t *
						src,
						ia_css_circbuf_elem_t *
						dest);

/**
 * @brief Write a new element into the circular buffer.
 * Write a new element WITHOUT checking whether the
 * circular buffer is full or not. So it also overwrites
 * the oldest element when the buffer is full.
 *
 * @param cb	The pointer to the circular buffer.
 * @param elem	The new element.
 */
static inline void ia_css_circbuf_write(ia_css_circbuf_t *cb,
					     ia_css_circbuf_elem_t elem);
#if 0
/**
 * @brief Update the state-machine of the circular buffer.
 *
 * @param[in/out]	cb		Point to the target circular buffer.
 */
static inline void ia_css_circbuf_update_fsm(ia_css_circbuf_t *cb);
#endif
/****************************************************************
 *
 * Inline functions.
 *
 ****************************************************************/
/**
 * @brief Initialize the element.
 * Refer to "Forward declarations" for details.
 */
static inline void
ia_css_circbuf_elem_init(ia_css_circbuf_elem_t *elem)
{
	ia_css_circbuf_elem_set_val(elem, 0);
}

/**
 * @brief Set the "val" field in the element.
 * Refer to "Forward declarations" for details.
 */
static inline void
ia_css_circbuf_elem_set_val(ia_css_circbuf_elem_t *elem,
				 uint32_t val)
{
	elem->val = val;
}

/**
 * @brief Copy an element.
 * Refer to "Forward declarations" for details.
 */
static inline void
ia_css_circbuf_elem_cpy(ia_css_circbuf_elem_t *src,
			     ia_css_circbuf_elem_t *dest)
{
	ia_css_circbuf_elem_set_val(dest, src->val);
}

/**
 * @brief Get a position in the circular buffer.
 * Refer to "Forward declarations" for details.
 */
static inline uint8_t
ia_css_circbuf_get_pos(ia_css_circbuf_t *cb,
			    uint32_t base, int offset)
{
	uint8_t dest;

	/* step 1: ajudst the offset  */
	while (offset < 0) {
		OP___assert(cb->size > 0);
		offset += cb->size;
	}

	/* step 2: shift and round by the upper limit */
	dest = (base + offset)%cb->size;

	return dest;
}

/**
 * @brief Get the offset between two positions in the circular buffer.
 * Refer to "Forward declarations" for details.
 */
static inline int
ia_css_circbuf_get_offset(ia_css_circbuf_t *cb,
			       uint32_t src_pos, uint32_t dest_pos)
{
	int offset;

	offset = (int)(dest_pos - src_pos);
	offset += (offset < 0) ? cb->size : 0;

	return offset;
}

/**
 * @brief Get the maximum number of elements.
 * Refer to "Forward declarations" for details.
 *
 * TODO: Test this API.
 */
static inline uint32_t
ia_css_circbuf_get_size(ia_css_circbuf_t *cb)
{
	return cb->size;
}

/**
 * @brief Get the number of availalbe elements.
 * Refer to "Forward declarations" for details.
 */
static inline uint32_t
ia_css_circbuf_get_num_elems(ia_css_circbuf_t *cb)
{
	int num;

	num = ia_css_circbuf_get_offset(cb, cb->start, cb->end);

	return (uint32_t)num;
}

/**
 * @brief Test if the circular buffer is empty.
 * Refer to "Forward declarations" for details.
 */
static inline bool ia_css_circbuf_is_empty(ia_css_circbuf_t *cb)
{
	return (cb->end == cb->start);
}

/**
 * @brief Test if the circular buffer is full.
 * Refer to "Forward declarations" for details.
 */
static inline bool ia_css_circbuf_is_full(ia_css_circbuf_t *cb)
{
#ifdef __SP
	return (OP_std_modadd(cb->end, 1, cb->size) == cb->start);
#else
	return (((cb->end + 1) % cb->size) == cb->start);
#endif
}

#if 0
/**
 * @brief Test if the circular buffer becomes not empty.
 * Refer to "Forward declarations" for details.
 */
static inline bool
ia_css_circbuf_becomes_not_empty(ia_css_circbuf_t *cb)
{
	bool ret;

	ret = (cb->attr.fsm.prev_state == _CB_STATE_EMPTY);
	ret &= (cb->attr.fsm.curr_state != _CB_STATE_EMPTY);

	return ret;
#pragma hivecc section="critical"
}
#endif
/**
 * @brief Write a new element into the circular buffer.
 * Refer to "Forward declarations" for details.
 */
static inline void
ia_css_circbuf_write(ia_css_circbuf_t *cb,
			  ia_css_circbuf_elem_t elem)
{
	if (ia_css_circbuf_is_full(cb))
#ifdef __SP
		OP_std_break();
#else
		assert(0);
#endif

	ia_css_circbuf_elem_cpy(&elem, &cb->elems[cb->end]);

	cb->end = ia_css_circbuf_get_pos(cb, cb->end, 1);

	/* overwrite the oldest element when the buffer is full */
	if (cb->end == cb->start)
		cb->start = ia_css_circbuf_get_pos(cb, cb->start, 1);
}

/**
 * @brief Push a value in the circular buffer.
 * Refer to "Forward declarations" for details.
 */
static inline void
ia_css_circbuf_push(ia_css_circbuf_t *cb, uint32_t val)
{
	ia_css_circbuf_elem_t elem;

	/* set up an element */
	ia_css_circbuf_elem_init(&elem);
	ia_css_circbuf_elem_set_val(&elem, val);

	/* write the element into the buffer */
	ia_css_circbuf_write(cb, elem);
#if 0
	/* update the state of the circular buffer */
	ia_css_circbuf_update_fsm(cb);
#endif
}

#if 0
/**
 * @brief Update the state-machine of the circular buffer.
 * Refer to "Forward declarations" for details.
 */
static inline void ia_css_circbuf_update_fsm(ia_css_circbuf_t *cb)
{
	unsigned int next_state;
	ia_css_circbuf_attr_t *attr;

	next_state = _CB_STATE_NEUTRAL;

	/* step 1: determine the next state */
	if (ia_css_circbuf_is_empty(cb))
		next_state = _CB_STATE_EMPTY;
	else if (ia_css_circbuf_is_full(cb))
		next_state = _CB_STATE_FULL;

	/* step 2: make the state transistion */
	attr = &(cb->attr);

	attr->fsm.prev_state = attr->fsm.curr_state;
	attr->fsm.curr_state = next_state;
}
#endif
extern uint32_t
ia_css_circbuf_peek(ia_css_circbuf_t *cb, int offset);

#endif /*_IA_CSS_CIRCBUF_H */
