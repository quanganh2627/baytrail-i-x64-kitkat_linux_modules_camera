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

#include "ia_css_queue.h"

#include "sp.h"

#include "platform_support.h"

/* MW: The queue should be application agnostic */
#include "sh_css_internal.h"
/* sh_css_frame_id,  struct sh_css_circular_buf */

/* MW: The queue should not depend on principal interface types */
#include "ia_css_types.h"		/* ia_css_fw_info */

#include "assert_support.h"

/*
 * MW: The interface to get events is in "event_fifo.h" presently that is wired
 * to the HOST2SP (HW) FIFO In the case that events are signaled by interrupt
 * and retrieved from SP, then the access mechanism to that queue must be here
 * as it is addressed by SP_ID. The functions interpreting and acting on the
 * event are not part of the SP device interface.
 */

/*
 * Local declarations.
 *
 * NOTE: Linux checkpatch cannot handle the storage class macro
 * "STORAGE_CLASS_INLINE" that is used to hide compiler specific "inline"
 * specifiers. To maintain portability do not force inline.
 */

/************************************************************
 *
 * Generic queues.
 *
 ************************************************************/
/*! Push an element to the queue.

 @param	offset[in]	The target queue's offset that is
			relative to the base address of the struct
			"host_sp_communication".
 @param elem[in]	the element to be enqueued.
 */
/*STORAGE_CLASS_INLINE bool push_sp_queue(*/
static void push_sp_queue(
	ia_css_circbuf_t *offset, ia_css_circbuf_elem_t *offset_to_elems,
	unsigned int elem);

/*! Pop an element from the queue.

 @param	offset[in]	The target queue's offset that is
			relative to the base address of the struct
			"host_sp_communication".
 @param elem[in]	the element to be dequeued.
 */
/*STORAGE_CLASS_INLINE bool pop_sp_queue(*/
static void pop_sp_queue(
	ia_css_circbuf_t *offset, ia_css_circbuf_elem_t *offset_to_elems,
	unsigned int *elem);


/*! Check whether the "host2sp" queue is full or not.

 @param	offset[in]	The target queue's offset that is
			relative to the base address of the struct
			"host_sp_communication".

 \return true if the queue is full
 */
/*STORAGE_CLASS_INLINE bool is_sp_queue_full(*/
static bool is_sp_queue_full(
	ia_css_circbuf_t *offset);

/*! Check whether the "host2sp" queue is empty or not.

 \param	offset[in]	The target queue's offset that is
			relative to the base address of the struct
			"host_sp_queuemunication".

 \return true if the queue is empty
 */
/*STORAGE_CLASS_INLINE bool is_sp_queue_empty(*/
static bool is_sp_queue_empty(
	ia_css_circbuf_t *offset);

/*
 * The compiler complains that "warning: ‘dump_sp_queue’ defined
 * but not used", which treats warnings as errors. So ‘dump_sp_queue’
 * is disabled. Enable it as soon as it is used.
 */
#if 0
/*! The Host prints the contents within the target "host2sp" queue.

 \param	offset[in]	The target queue's offset that is
			relative to the base address of the struct
			"host_sp_queuemunication"
 */
/*STORAGE_CLASS_INLINE void dump_sp_queue(*/
static void dump_sp_queue(
	ia_css_circbuf_t *offset);
#endif
/* end of local declarations */

/************************************************************
 *
 * Application-specific queues.
 *
 ************************************************************/
/************************************************************
 *
 * Buffer queues (direction: the host -> the SP).
 *
 ************************************************************/
bool host2sp_enqueue_buffer(
	unsigned int pipe_num,
	unsigned int stage_num,
	enum sh_css_buffer_queue_id index,
	uint32_t buffer_ptr)
{
	bool is_full;
//	struct host_sp_queues *my_queues = NULL;
	ia_css_circbuf_t *offset_to_queue;
	ia_css_circbuf_elem_t *offset_to_elems;
	(void)stage_num;

	assert(pipe_num < SH_CSS_MAX_SP_THREADS);
	assert((index < SH_CSS_NUM_BUFFER_QUEUES));

	if (pipe_num >= SH_CSS_MAX_SP_THREADS)
		return false;

	/* This is just the first step of introducing the queue API */
	/* The implementation is still the old non-queue implementation */
	/* till the new queue implementation is there */
	offset_to_queue = (ia_css_circbuf_t *)
		offsetof(struct host_sp_queues,
			host2sp_buffer_queues[pipe_num][index]);

	offset_to_elems = (ia_css_circbuf_elem_t *)
		offsetof(struct host_sp_queues,
			host2sp_buffer_queues_elems[pipe_num][index]);

	/* check whether both queues are full or not */
	is_full = is_sp_queue_full(offset_to_queue);

	if (!is_full) {
		/* push elements into the queues */
		push_sp_queue(offset_to_queue, offset_to_elems,
			      (uint32_t)buffer_ptr);
	}


	return !is_full;
}

/************************************************************
 *
 * Buffer queues (direction: the host -> the SP).
 *
 ************************************************************/
bool host2sp_dequeue_buffer(
	unsigned int thread_id,
	unsigned int stage_num,
	enum sh_css_buffer_queue_id index,
	uint32_t *buffer_ptr)
{
	bool is_empty;
	uint32_t elem;
//	struct host_sp_queues *my_queues = NULL;
	ia_css_circbuf_t *offset_to_queue;
	ia_css_circbuf_elem_t *offset_to_elems;

	(void)stage_num;

	assert(thread_id < SH_CSS_MAX_SP_THREADS);
	assert((index < SH_CSS_NUM_BUFFER_QUEUES));
	assert(buffer_ptr != NULL);

	if (thread_id >= SH_CSS_MAX_SP_THREADS)
		return false;

	/* This is just the first step of introducing the queue API */
	/* The implementation is still the old non-queue implementation */
	/* till the new queue implementation is there */
	offset_to_queue = (ia_css_circbuf_t *)
		offsetof(struct host_sp_queues,
			host2sp_buffer_queues[thread_id][index]);

	offset_to_elems = (ia_css_circbuf_elem_t *)
		offsetof(struct host_sp_queues,
			host2sp_buffer_queues_elems[thread_id][index]);

	/* check whether the queue is empty or not */
	is_empty = is_sp_queue_empty(offset_to_queue);

	/* pop when both queue is not empty */
	if (!is_empty) {
		/* pop element from the queue */
		pop_sp_queue(offset_to_queue, offset_to_elems, &elem);

		/* set the frame data */
		*buffer_ptr = elem;
	}

	return !is_empty;
}

/************************************************************
 *
 * Event queues (the host -> the SP).
 *
 ************************************************************/
bool host2sp_enqueue_sp_event(
		uint32_t event)
{
	bool is_full;
	//struct host_sp_queues *my_queues = NULL;
	ia_css_circbuf_t *offset_to_queue;
	ia_css_circbuf_elem_t *offset_to_elems;

	offset_to_queue = (ia_css_circbuf_t *)
		offsetof(struct host_sp_queues,
			host2sp_event_queue);

	offset_to_elems = (ia_css_circbuf_elem_t *)
		offsetof(struct host_sp_queues,
			 host2sp_event_queue_elems);

	/* check whether the queue is full or not */
	is_full = is_sp_queue_full(offset_to_queue);

	if (!is_full) {
		/* push elements into the queues */
		push_sp_queue(offset_to_queue, offset_to_elems, event);
	}

	return !is_full;
}

/************************************************************
 *
 * Buffer queues (the SP -> the host).
 *
 ************************************************************/
bool sp2host_dequeue_buffer(
	unsigned int pipe_num,
	unsigned int stage_num,
	enum sh_css_buffer_queue_id index,
	uint32_t *buffer_ptr)
{
	uint32_t elem;
	bool is_empty;
	//struct host_sp_queues *my_queues = NULL;
	ia_css_circbuf_t *offset_to_queue;
	ia_css_circbuf_elem_t *offset_to_elems;

	offset_to_queue = (ia_css_circbuf_t *)
		offsetof(struct host_sp_queues,
			sp2host_buffer_queues[index]);

	offset_to_elems = (ia_css_circbuf_elem_t *)
		offsetof(struct host_sp_queues,
			sp2host_buffer_queues_elems[index]);

	(void)stage_num;
	(void)pipe_num;

	assert(buffer_ptr != NULL);
	assert((index < SH_CSS_NUM_BUFFER_QUEUES));

	/* This is just the first step of introducing the queue API */
	/* The implementation is still the old non-queue implementation */
	/* till the new queue implementation is there */

	/* check whether the queue is empty or not */
	is_empty = is_sp_queue_empty(offset_to_queue);

	/* pop when both queue is not empty */
	if (!is_empty) {
		/* pop element from the queue */
		pop_sp_queue(offset_to_queue, offset_to_elems, &elem);

		/* set the frame data */
		*buffer_ptr = elem;
	}

	return !is_empty;
}

/************************************************************
 *
 * Event queues (the SP -> the host).
 *
 ************************************************************/
bool sp2host_dequeue_irq_event(
	uint32_t *event)
{
	unsigned int elem;
	bool is_empty;
	//struct host_sp_queues *my_queues = NULL;

	ia_css_circbuf_t *offset_to_queue;
	ia_css_circbuf_elem_t *offset_to_elems;
	assert(event != NULL);

	offset_to_queue = (ia_css_circbuf_t *)
		offsetof(struct host_sp_queues,
			sp2host_event_queue);

	offset_to_elems = (ia_css_circbuf_elem_t *)
		offsetof(struct host_sp_queues,
			sp2host_event_queue_elems);

	/* check whether the queue is empty or not */
	is_empty = is_sp_queue_empty(offset_to_queue);

	/* pop when both queue is not empty */
	if (!is_empty) {
		/* pop element from the queue */
		pop_sp_queue(offset_to_queue, offset_to_elems, &elem);

		/* fill in the IRQ event */
		*event = elem;
	}

	return !is_empty;
}

static void store_sp_queue(
	ia_css_circbuf_t *offset,
	unsigned int *size,
	unsigned int *elems,
	unsigned int *start,
	unsigned int *end)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif
	unsigned int entry_to_cb_size  = 0;
	unsigned int entry_to_cb_elems = 0;
	unsigned int entry_to_cb_start = 0;
	unsigned int entry_to_cb_end   = 0;

	assert((uintptr_t)offset < (UINT32_MAX - sizeof(ia_css_circbuf_t)));
	entry_to_cb_size  = (unsigned)(UINT32_MAX & (uintptr_t)&offset->size);
	entry_to_cb_elems = (unsigned)(UINT32_MAX & (uintptr_t)&offset->elems);
	entry_to_cb_start = (unsigned)(UINT32_MAX & (uintptr_t)&offset->start);
	entry_to_cb_end   = (unsigned)(UINT32_MAX & (uintptr_t)&offset->end);

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	/* update the contents at the entries */
	if (size)
		store_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_size / sizeof(offset->size),
		        (const uint8_t)*size);

	if (elems)
		store_sp_array_uint(ia_css_bufq_host_sp_queue,
			entry_to_cb_elems / sizeof(offset->elems),
			(const uint8_t)*elems);

	if (start)
		store_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_start / sizeof(offset->start),
			(const uint8_t)*start);

	if (end)
		store_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_end / sizeof(offset->end),
			(const uint8_t)*end);
}

static void load_sp_queue(
	ia_css_circbuf_t *offset,
	unsigned int *size,
	unsigned int *elems,
	unsigned int *start,
	unsigned int *end)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif
	unsigned int entry_to_cb_size  = 0;
	unsigned int entry_to_cb_elems = 0;
	unsigned int entry_to_cb_start = 0;
	unsigned int entry_to_cb_end   = 0;

	assert((uintptr_t)offset < (UINT32_MAX - sizeof(ia_css_circbuf_t)));
	entry_to_cb_size  = (unsigned)(UINT32_MAX & (uintptr_t)&offset->size);
	entry_to_cb_elems = (unsigned)(UINT32_MAX & (uintptr_t)&offset->elems);
	entry_to_cb_start = (unsigned)(UINT32_MAX & (uintptr_t)&offset->start);
	entry_to_cb_end   = (unsigned)(UINT32_MAX & (uintptr_t)&offset->end);

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	/* update the contents at the entries */
	if (size)  *size  = load_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_size / sizeof(offset->size));

	if (elems) *elems  = load_sp_array_uint(ia_css_bufq_host_sp_queue,
			entry_to_cb_elems / sizeof(offset->elems));

	if (start) *start = load_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_start / sizeof(offset->start));

	if (end)   *end   = load_sp_array_uint8(ia_css_bufq_host_sp_queue,
			entry_to_cb_end / sizeof(offset->end));
}

/************************************************************
 *
 * Generic queues.
 *
 ************************************************************/
/*STORAGE_CLASS_INLINE void push_sp_queue(*/
static void push_sp_queue(
	ia_css_circbuf_t *offset,
	ia_css_circbuf_elem_t *offset_to_elems,
	unsigned int elem)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif

	unsigned int cb_size;
	unsigned int cb_start;
	unsigned int cb_end;
	unsigned int entry_to_cb_elem;
	ia_css_circbuf_elem_t cb_elem;

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	/* set a local copy of the circular buffer */
	load_sp_queue (offset, &cb_size, NULL, &cb_start, &cb_end);

	assert((uintptr_t)offset < (UINT32_MAX - sizeof(ia_css_circbuf_t)));
	entry_to_cb_elem = (unsigned)(UINT32_MAX & (uintptr_t)&offset_to_elems[cb_end]);

	/* enqueue the element */
	cb_elem.val = (uint32_t)elem;
	store_sp_var_with_offset(ia_css_bufq_host_sp_queue,
				 entry_to_cb_elem,
				 &cb_elem,
				 sizeof(ia_css_circbuf_elem_t));

	/* update the "end" index */
	cb_end = (cb_size == 0) ? (cb_end + 1) : (cb_end + 1) % cb_size;
	store_sp_queue (offset, NULL, NULL, NULL, &cb_end);
}

/*STORAGE_CLASS_INLINE void pop_sp_queue(*/
static void pop_sp_queue(
	ia_css_circbuf_t *offset,
	ia_css_circbuf_elem_t *offset_to_elems,
	unsigned int *elem)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif

	unsigned int cb_size;
	unsigned int cb_start;
	unsigned int cb_end;

	unsigned int entry_to_cb_elem;
	ia_css_circbuf_elem_t cb_elem;

	assert(elem != NULL);
#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	load_sp_queue(offset, &cb_size, NULL, &cb_start, &cb_end);

	/* read from the non-empty queue */
	assert((uintptr_t)offset < (UINT32_MAX - sizeof(ia_css_circbuf_t)));
	entry_to_cb_elem = (unsigned)(UINT32_MAX & (uintptr_t)&offset_to_elems[cb_start]);

	/* dequeue the buffer */
	load_sp_var_with_offset(ia_css_bufq_host_sp_queue,
				entry_to_cb_elem,
				&cb_elem,
				sizeof(ia_css_circbuf_elem_t));

	*elem = cb_elem.val;

	/* update the "start" index */
	cb_start = (cb_size == 0) ? (cb_start + 1) : (cb_start + 1) % cb_size;
	store_sp_queue(offset, NULL, NULL, &cb_start, NULL);
}

#if 1
/*STORAGE_CLASS_INLINE bool is_sp_queue_full(*/
static bool is_sp_queue_full(
	ia_css_circbuf_t *offset)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif

	unsigned int cb_size;
	unsigned int cb_start;
	unsigned int cb_end;

	bool is_full;

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	load_sp_queue (offset, &cb_size, NULL, &cb_start, &cb_end);

	/* check whether the queue is full or not */
	is_full = (0 == cb_size) ? true : ((cb_end + 1) % cb_size == cb_start);

	return is_full;
}

#else

/*STORAGE_CLASS_INLINE bool is_sp_queue_full(*/
static bool is_sp_queue_full(
        unsigned int base)
{
#ifndef C_RUN
        unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
        const struct ia_css_fw_info *fw;
#endif

        unsigned int offset;

        unsigned int entry_to_cb_fsm;

        uint32_t cb_fsm;

        bool is_full;

#ifndef C_RUN
        /* get the variable address from the firmware */
        fw = &sh_css_sp_fw;
        HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

        /* get the offsets (in words) */
        offset = offsetof(ia_css_circbuf_t, fsm)
                / sizeof(int);

        /* get the entries (in words) */
        entry_to_cb_fsm = base + offset;

        /* get a local copy of the circular buffer */
        cb_fsm = load_sp_array_uint(ia_css_bufq_host_sp_queue, entry_to_cb_fsm);

        /* check whether the queue is full or not */
        is_full = (SP_QUEUE_FSM_GET_CURR_STATE(cb_fsm) == SP_QUEUE_STATE_FULL);

        return is_full;
}
#endif

/*STORAGE_CLASS_INLINE bool is_sp_queue_empty(*/
static bool is_sp_queue_empty(
	ia_css_circbuf_t *offset)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif

	unsigned int cb_size;
	unsigned int cb_start;
	unsigned int cb_end;

	bool is_empty;

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	load_sp_queue (offset, &cb_size, NULL, &cb_start, &cb_end);

	/* check whether the queue is full or not */
	is_empty = (0 == cb_size) ? true : (cb_start == cb_end);

	return is_empty;
}

/*
 * The compiler complains that "warning: ‘dump_sp_queue’ defined
 * but not used", which treats warnings as errors. So ‘dump_sp_queue’
 * is disabled. Enable it as soon as it is used.
 */
#if 0
/*STORAGE_CLASS_INLINE void dump_sp_queue(*/
static void dump_sp_queue(
	struct sh_ccs_circular_buf *offset)
{
#ifndef C_RUN
	unsigned int HIVE_ADDR_ia_css_bufq_host_sp_queue;
	const struct ia_css_fw_info *fw;
#endif

	unsigned int offset_4;

	unsigned int entry_to_cb_elems[SH_CSS_CIRCULAR_BUF_NUM_ELEMS];

	unsigned int cb_size;
	unsigned int cb_step;
	unsigned int cb_start;
	unsigned int cb_end;
	uint32_t cb_elems[SH_CSS_CIRCULAR_BUF_NUM_ELEMS];

	unsigned int i;

#ifndef C_RUN
	/* get the variable address from the firmware */
	fw = &sh_css_sp_fw;
	HIVE_ADDR_ia_css_bufq_host_sp_queue = fw->info.sp.host_sp_queue;
#endif

	/* get the offsets (in words) */
	offset_4 = offsetof(ia_css_circbuf_t, elems)
		/ sizeof(int);

	/* get the entries (in words) */
	for (i = 0; i < SH_CSS_CIRCULAR_BUF_NUM_ELEMS; i++) {
		entry_to_cb_elems[i] = base + offset_4;
		entry_to_cb_elems[i] +=	i;
	}

	/* update the contents at the entries */
	load_sp_queue (offset, &cb_size, &cb_step, &cb_start, &cb_end);

	for (i = 0 ; i < SH_CSS_CIRCULAR_BUF_NUM_ELEMS; i++) {
		cb_elems[i] = load_sp_array_uint(ia_css_bufq_host_sp_queue,
						entry_to_cb_elems[i]);
	}

#ifdef C_RUN
	printf("base     = %d\n", base);
	printf("cb_size  = %d\n", cb_size);
	printf("cb_step  = %d (bytes)\n", cb_step);
	printf("cb_start = %d\n", cb_start);
	printf("cb_end   = %d\n", cb_end);
	for (i = 0 ; i < SH_CSS_CIRCULAR_BUF_NUM_ELEMS; i++)
		printf("cb_elems[%d] = %d\n", i, cb_elems[i]);

	printf("\n");
#endif
}
#endif
/* end of local definitions */
