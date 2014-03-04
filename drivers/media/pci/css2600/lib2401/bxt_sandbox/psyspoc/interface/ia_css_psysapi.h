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

/**
 * @file   ia_css_psysapi.h
 * @Author Theo.Roelands@intel.com
 * @date   07 December, 2013
 * @brief  The CSS Broxton PSYS task API
 *
 *  --- API description ---
 *
 *     The central concept in this API is a 'PSYS task' ("struct ia_css_psys_task;").
 *
 *     A PSYS task is presented to the API client as a pointer to an opaque structure.
 *     The task defines an action that the PSYS firmware can execute.
 *     At creation time the task receives an attribute called 'program_group'.
 *     This 'program_group' attribute defines the main structure of the task.
 *     Among other things, the 'program_group' attribute defines terminals at which
 *     storage buffers need to be attached.
 *
 *     These storage buffers can be input buffers, output buffers, state buffers, or parameter buffers.
 *     The client needs to know the properties of the program_group and its terminals,
 *     because without the required buffers attached the task can not be started.
 *
 *     The lifetime of a task starts with API call 'ia_css_psysapi_task_create'.
 *     The client can use the 'attach' function for populating a task with buffers.
 *     These can be a local buffers, an input buffers, an output buffers, parameter buffers, etc.),
 *     When the task is properly populated, the client will decide when the task needs to run
 *     and what internal PSYS resources are going to be assigned to the tasks. Making
 *     these decisions is called scheduling. When scheduling is done, and the time to
 *     start the task has arrived, the client shall call 'ia_css_psysapi_task_start'.
 *
 *     The API provides an event type to signal an early release of a buffer, but
 *     typically the attached buffers are released together with the task when it finishes.
 *     At that moment the client can collect the buffers and do whatever cleanup is necessary.
 *     For example recycling the buffers, forwarding the result, and removing the task from
 *     its administration.
 *
 *     During the life time of a task the client may choose to temporarily free resources
 *     at the firmware level, by forcing the task to suspend, and resume it at a later stage.
 *     The client may also choose to simply abort the task.
 *
 *     This API makes use of cookies. A cookie is used to restore context during an event notification.
 *     E.g. in case of a buffer: Each time the client attaches a buffer, it associates it with a cookie.
 *     When the buffer is returned to the client, the associated cookie is also returned to the client.
 *     It is completely up to the client what to put in the cookie, but typically it could be a reference to a
 *     client held data structure that has recorded the full context and history of the buffer, including its
 *     relations with other client objects, like where the buffer came from, where it is destined, etc.
 *
 *     This api optionally offers the notion of delegation_context. This is to help a driver that needs
 *     to route return events back to a higher level user mode client. See the optional function.
 *     ia_css_psysapi_task_set_delegation_context().
 *
 *  --- API summary ---
 *
 *     // initialize the psys task api
 *     ia_css_psysapi_init();
 *
 *     // to create a task
 *     ia_css_psysapi_task_create(&task, &pg_info, task_buffer,cookie);
 *
 *     // to configure a tasks
 *     ia_css_psysapi_task_attach_buffer(task,terminal_id,bufffer,status);
 *
 *     // operations on fully configured tasks
 *     ia_css_psysapi_task_start(task,assigned_resources,resource_mapping);
 *     ia_css_psysapi_task_suspend(task,resources_to_give_up);
 *     ia_css_psysapi_task_resume(task,assigned_resources,resource_mapping);
 *     ia_css_psysapi_task_abort(task);
 *
 *     // operations for return events
 *     ia_css_psysapi_task_get_event(&raw_event);
 *     ia_css_psysapi_task_translate_event(raw_event,&event);
 *
 *     // to clean up and destroy a task
 *     ia_css_psysapi_task_detach_buffer(task,&terminal_id,&bufffer,&status);
 *     ia_css_psysapi_task_destroy(task);
 */


#ifndef __IA_CSS_PSYSAPI_H_INCLUDED__
#define __IA_CSS_PSYSAPI_H_INCLUDED__

/*--------------------------------------------------------------------------------------
*  Include section
*/
#include "type_support.h"       /* for <errno.h>, for uint32_t etc. */
#include "ia_css_pg_info.h"

/*--------------------------------------------------------------------------------------
* firmware and driver virtual addresses
*/
typedef uint32_t ia_css_psys_fw_addr_t;
typedef uint64_t ia_css_psys_drv_addr_t;

/*--------------------------------------------------------------------------------------*/
/**
* @brief   definition of error return values
* For error return values this API reuses POSIX defined values as defined in <errno.h>
* See  also http://man7.org/linux/man-pages/man3/errno.3.html
* This API defines that variable errno remains untouched by the implementation of this API.
* This is an intentional deviation from the POSIX standard that is argumented in
* BXT_Error_And_Assertion_Handling_0.1.docx. The define below is only to stress that
* all functions of this API report success with a zero return value.
*/
#define IA_CSS_PSYS_SUCCESS  (0)

/*Silent the compiler*/
#define NOT_USED(a)            ((a) = (a))
/*--------------------------------------------------------------------------------------
*   terminal IDs
*
* A terminal ID is a point where a program group can interface to a provided buffer.
* These can be input buffers, output buffers, or buffers holdin state parameters or configurations.
* Al defined by the program group publisher.
* The number of terminals and their properties will vary per program group
* Defining constants for these terminals is left to the user, E.g.
*
*	MY_PROGRAM_GROUP_INPUT_TERMINAL
*	MY_PROGRAM_GROUP_OUTPUT_TERMINAL
*	MY_PROGRAM_GROUP_CONFIGURATION_TERMINAL
*	MY_PROGRAM_GROUP_STATE_BUFFER_TERMINAL
*	MY_PROGRAM_GROUP_PARAMETER_TERMINAL
*	MY_PROGRAM_GROUP_LATE_PARAMETER_TERMINAL
*/
typedef uint32_t ia_css_psys_terminal_id_t;

/*--------------------------------------------------------------------------------------
*  singular buffer definition
* Note that the client_address may be set to NULL when the host CPU does not need access.
* (e.g. when the buffer is a context\state buffer that is only used by the firmware.)
* (e.g. when pixel data is streamed from hw block to another, we don't have a need to map it to kernel or user-space)
*/
struct ia_css_psys_singular_buffer {
	void* cookie; /* client defined buffer identification, to be returned in buffer notification callbacks */
	ia_css_psys_fw_addr_t firmware_address; /* virtual adress in the psys (iunit) memory space */
	void* client_address; /* virtual adress in the host client memory space */
	unsigned int size; /* size in bytes */
};

/*--------------------------------------------------------------------------------------
*  general buffer definition
*/
struct ia_css_psys_buffer {
	void* cookie; /* client defined buffer identification, to be returned in buffer notification callbacks */
	unsigned int nof_planes; /* the number of planes in case of a planar frame buffer, or 1 in case of a singular buffer */
	struct ia_css_psys_singular_buffer* planes; /* array with frame buffer planes, or pointer to a singular buffer */
};

/*--------------------------------------------------------------------------------------
* A 'task' is an opaque unspecified data structure containing data like
* a reference to a program group, references to several types of buffers like input buffers
* output buffers, state buffers, parameter buffers etc.
*/
struct ia_css_psys_task;

/*--------------------------------------------------------------------------------------
* The 'ia_css_psysapi_task_buffer' structure carries pointers to access a single 'task buffer'
* containing a 'ia_css_psys_task', that is accessable from 3 memory spaces.
* In case the client is a user space client, the driver address is used to
* let the driver access the task object for delegating the task to the firmware.
* In case the client is a driver space client, the 'driver_address' is equal to
* 'client_address'.
*/
struct ia_css_psysapi_task_buffer
{
	void* cookie; /* client defined buffer identification, to be returned in buffer notification callbacks */
	ia_css_psys_fw_addr_t firmware_address;   /* virtual adress in the psys memory space */
	ia_css_psys_drv_addr_t driver_address;   /* virtual address in the driver memory space */
	struct ia_css_psys_task* client_address; /* virtual adress in the client memory space */
	unsigned int size; /* buffer size in bytes */
};

/*--------------------------------------------------------------------------------------
* Return event type
* Note that in case of IA_CSS_PSYSAPI_TASK_FINISHED the task can either be aborted or completed.
* The user shall discriminate by observing the status of the output buffers.
* If an output buffer is detached with status EMPTY the task was aborted.
* If an output buffer is detached with status FULL the task was completed.
* See ia_css_psysapi_task_detach_next_buffer().
*
*/
enum ia_css_psysapi_task_event_type
{
	IA_CSS_PSYSAPI_TASK_ABORTED,
	IA_CSS_PSYSAPI_TASK_FINISHED,
	IA_CSS_PSYSAPI_TASK_SUSPENDED,
	IA_CSS_PSYSAPI_TASK_BUFFER_RELEASED /* future API extension to support an early buffer release */
};

/*--------------------------------------------------------------------------------------
* This structure defines the opaque transport structure that contains return events.
* This raw form is provided by ia_css_psysapi_task_get_event().
* When a driver is delegating, this raw packet needs to be forwarded to the user space
* client. The client shall then call ia_css_psysapi_task_translate_event() to read the event.
*/
struct ia_css_psysapi_task_raw_event
{
	uint64_t reserved[8];
};

/*--------------------------------------------------------------------------------------
* This structure defines return events. These events are obtained from raw events by
* calling ia_css_psysapi_task_translate_event().
* Return events signal either that the task has finished, suspended, or in rare cases
* that one of the buffers was released early.
* The 'buffer' is NULL except when the event signals an early buffer release.
*/
struct ia_css_psysapi_task_event
{
	enum ia_css_psysapi_task_event_type type;
	struct ia_css_psys_task*            task;
	void*                               originator_cookie;
	struct ia_css_psys_buffer*          buffer;
};

/*--------------------------------------------------------------------------------------
* This api discriminates exchangeable resources and unique resources
*/
enum ia_css_psysapi_resource_limits
{
	IA_CSS_PSYSAPI_ISP_LIMIT = 4,  /* BXT_2600 ISP max availability */
	IA_CSS_PSYSAPI_GDC_LIMIT = 2,  /* BXT_2600 GDC max availability */
};

/*--------------------------------------------------------------------------------------
* This enumeration defines PSYS resources.
* The working assumption is that the resources in this enumeration can only be
* exclusively assigned to one task. So a set of resources can be represented as a bit mask.
* Note that resource constraints of shareable resources such as DMA and memory are not
* yet covered in this interface, as this is not yet needed for the first deliverables.
*/
enum ia_css_psysapi_resource_enumerator
{
	IA_CSS_PSYSAPI_GDC_0,                /* 2 GDCs are instances of the same resource class */
	IA_CSS_PSYSAPI_GDC_1,
	IA_CSS_PSYSAPI_ISP_0,                /* 4 ISPs are instances of the same resource class */
	IA_CSS_PSYSAPI_ISP_1,
	IA_CSS_PSYSAPI_ISP_2,
	IA_CSS_PSYSAPI_ISP_3,
	IA_CSS_PSYSAPI_FP_SCALAR_PROCESSOR,   /* SP with floating point hardware */
	IA_CSS_PSYSAPI_OUTPUT_FORMATTER,
	IA_CSS_PSYSAPI_INPUT_SLICE,
	IA_CSS_PSYSAPI_ACCELERATOR_WBA,       /* White Balance Apply  */
	IA_CSS_PSYSAPI_ACCELERATOR_ANR,       /* Advanced Noise Reduction  */
	IA_CSS_PSYSAPI_ACCELERATOR_BDM,       /* Bayer Demosaicing  */
	IA_CSS_PSYSAPI_ACCELERATOR_CCM,       /* Color correct matrix  */
	IA_CSS_PSYSAPI_ACCELERATOR_GAMMA_TM,  /* Gamma correction + Tone mapping  */
	IA_CSS_PSYSAPI_ACCELERATOR_CSC,       /* Color Space Conversion  */
	IA_CSS_PSYSAPI_ACCELERATOR_YEENR,     /* Y-Edge Enhancement Noise Reduction  */
	IA_CSS_PSYSAPI_ACCELERATOR_CE,        /* Color Enhancement  */
	IA_CSS_PSYSAPI_ACCELERATOR_LACE_STAT, /* Local histogram statistics  */
	IA_CSS_PSYSAPI_ACCELERATOR_DVS_STAT,  /* DVS statistics (DVS stat) */
	IA_CSS_PSYSAPI_N_RESOURCE
};
// TODO: Mark wrote: the Psys has 6 accelerators, each with different capabilities, not a list of FF's

/*--------------------------------------------------------------------------------------
* This struct defines a resource assignment by presenting a locical to physical mapping of
* exchangeable resources.
* Note that a program group will identify a logical resource numbering, where the scheduler
* will select physical resources, and map them on the logical numbering.
* E.g.  the scheduler could decide that a task, which needs 3 logical ISPs, gets ISP0 ISP1 and ISP3.
* The mapping would then look like this:
*     map[] = {0,1,3,-1};
* E.g.  the scheduler could decide that a task, which needs 1 logical ISPs, gets ISP2
* The mapping would then look like this:
*     map[] = {2,-1,-1,-1};
*/
struct ia_css_psysapi_resource_mapping
{
	int vector_processors[IA_CSS_PSYSAPI_ISP_LIMIT]; /* ISP logical to physical index mapping */
	int gdcs[IA_CSS_PSYSAPI_GDC_LIMIT];              /* GDC logical to physical index mapping */
};

/*--------------------------------------------------------------------------------------
* This struct provides a bit pattern to list resources
* Each bit that is set to 1 marks a listed resource.
* For the bit position definitions see: enum ia_css_psysapi_resource_enumerator
*/
struct ia_css_psysapi_resource_list
{
	uint32_t  nof_masks; /* This number is 1 when IA_CSS_PSYSAPI_RESOURCE_ENUM_TOTAL_NR <= 32
                          * More general: it equals IA_CSS_PSYSAPI_RESOURCE_ENUM_TOTAL_NR / 32
	                      * Or, in other words, there should be enough masks to carry all the
	                      * resource bits.
	                      */
	uint32_t* mask; /* Pointer to the first element of a array of masks */
};

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Initialize the task functionality of the psys API
 *
 * The variable 'time_to_live' exists to avoid that task wait forever in the firmware,
 * waiting for a condition that never comes. After their 'time_to_live' expires, they
 * will be forcefully aborted.
 *
 * @param [out] task_buffer_size       the size that the client must allocate when creating task buffers.
 * @param [in]  time_to_live           the maximum time in msec that tasks can live in the firmware
 */
int ia_css_psysapi_init(unsigned int* task_buffer_size, unsigned int time_to_live);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Create a psys task.
 *
 * This function takes an externally provided 'task_buffer' as input and uses that to
 * create a stil unpopulated task object. It associates it with the specified program id.
 *
 * The implementation of ia_css_psysapi_task_create() will likely make the resulting '*task'
 * identical to the provided task_buffer. I.e.:
 *     *task = task_buffer->client_address
 * but the API client may not assume that this is always the case.
 *
 * After successful creation, the task 'knows' the basic structure defined by the passed program id,
 * and the task is ready to be populated with buffers.
 *
 * After population, the task can be queued for execution using the function ia_css_psysapi_task_submit().
 * For each submitted task, the client will receive a return event that
 * signals when the task has finished or when it has been aborted at the firmware level.
 *
 * The client is free to define any value to 'originator_cookie'. E.g. it
 * could hold a reference to its creator.
 *
 * From firmware point of view, the life-time of a task ends when it sends
 * the 'IA_CSS_PSYSAPI_TASK_FINISHED' notification. But the task object
 * remains valid until the client decides to destroy\recycle the object.
 * This means that when the client receives 'IA_CSS_PSYSAPI_TASK_FINISHED'
 * it can still query the task object. See: ia_css_psysapi_task_detach_buffer().
 * With this call the client can collect all buffers, and then destroy or recyle them.
 * Finally the client can destroy or recyle the task buffer.
 * See: ia_css_psysapi_task_destroy()
 *
 * @param [out] task               pointer to receive the created task.
 * @param [in]  pg_info            defines the program group structure for the task
 * @param [in]  task_buffer        shared IPC buffer used to transfer the task to the firmware
 * @param [in]  originator_cookie  pointer to client defined originator context structure
 *
 * @retval 0            on success
 * @retval EINVAL       when the pointer to receive the new task is NULL
 * @retval EBADR        when 'pg_id' holds an unrecognised program id
 * @retval EOVERFLOW    when 'task_buffer' does not have the size required for this 'pg_id'
 *
 */
int ia_css_psysapi_task_create(
	struct ia_css_psys_task** task,
	struct ia_css_pg_info *pg_info,
	struct ia_css_psysapi_task_buffer* task_buffer,
	void* originator_cookie
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Attach a buffer to a terminal
 *
 * This function shall be used to populate a task.
 *
 * Note that the buffer pointer passed here, is NOT stored into the task object.
 * Instead the passed buffer attributes are copied into the task buffer.
 * That means that the client does not need to preserve the struct ia_css_psys_buffer
 * which was used to pass the buffer attributes.
 * This also means that whenever this api passes a buffer pointer back to the client
 * it will be a pointer, pointing into the task object, to the location where the
 * buffer attributes were copied.
 *
 * Normally a buffer is released at the same time when when the task finishes.
 * See ia_css_psysapi_task_get_event()
 * However, if the "data sheet" of the program group defines that the buffer is
 * released before the task's completion. Then one event 'IA_CSS_PSYSAPI_TASK_BUFFER_RELEASED'
 * will be sent to the client.
 * Note that the supported formats and dimensioning of buffers is specified by the
 * program group publisher.
 * If the program group supports a range of formats and\or a range of dimensions,
 * the client shall present the chosen buffer dimension and format by attaching
 * a 'configuration buffer', to a separate 'configuration terminal' as specified by
 * the program group publication.
 *
 * @param [in]  task           the associated task
 * @param [in]  terminal_id    the terminal to attach to
 * @param [in]  buffer         the buffer
 *
 * @retval 0            on success
 * @retval EINVAL       when 'task' does not point to a valid task
 * @retval EBADE        the size of 'buffer' is too small to match the current task construction status
 *
 */
int ia_css_psysapi_task_attach_buffer(
	struct ia_css_psys_task* task,
	ia_css_psys_terminal_id_t terminal_id,
	struct ia_css_psys_buffer* buffer
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Associate a task with a delegation context
 *
 * This function is optional.
 *
 * The 'delegator_cookie' can be used by the driver when it is not the
 * originator of a task. If the driver is the originator, then this function shall not be used.
 * The cookie can be used by the driver to attach a reference to a delegation context of the task.
 * E.g. the cookie could refer to a file descriptor or any other information needed at the
 * time when a return event needs to be routed back to the user-mode client (originator).
 *
 * @param [in] task
 * @param [in] delegator_cookie      delegation context in case the driver is delegator and not originator, else NULL
 *
 * @retval 0            on success
 * @retval EINVAL       when 'task' does not point to a valid task
 */
int ia_css_psysapi_task_set_delegation_context(
	struct ia_css_psys_task* task,
	void* delegator_cookie
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Request the starting of a task.
 *
 * This function shall be called when the scheduler has decided that the task can start now.
 * The result will be that the task is passed to the firmware-dispatcher who will
 * blindly assume that given resources are available, and proceed loading and executing the task.
 *
 * When the task finishes the client gets a notification. See ia_css_psysapi_task_get_event().
 *
 * @param [in] task
 * @param [in] assigned_resources      PSYS internal resources assigned to run the task now
 * @param [in] resource_mapping        logical to physical resource mapping
 *
 * @retval 0           on success
 * @retval EINVAL      the 'task' does not point to a valid task
 * @retval ENODATA     not all of the required terminals are populated
 */
int ia_css_psysapi_task_start(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_resource_list* assigned_resources,
	struct ia_css_psysapi_resource_mapping resource_mapping
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Request the suspension a task.
 *
 * This function suspends the task asynchronously. The purpose of suspending is to free
 * resources to make room for a another higher priority task. In a later stage the
 * client may call ia_css_psysapi_task_resume() to resume the suspended task.
 *
 * Details:
 * A task will only be able to suspend at discrete moments in time, so the
 * time of the actual suspend will be delayed until the first of such discrete moments
 * occurs. The maximum delay will depend on the program group and the contents of its
 * configuration. But typically this delay will be much less than 1 msec.
 * The client will get a 'IA_CSS_PSYSAPI_TASK_SUSPENDED' notification when the suspension
 * has completed.
 *
 * @param [in] task
 * @param [in] resources      specifies the PSYS internal resources that the task must give up
 *
 * @retval 0         on success
 * @retval EINVAL    when 'task' does not point to a valid task
 * @retval EPERM     when the task is 'aborted' or in any other state that does not allows suspension.
 *
 */
int ia_css_psysapi_task_suspend(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_resource_list* resources_to_give_up
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Request the resumption of a task.
 *
 * This function resumes the task asynchronously. The purpose of suspending is to free
 * The client will get a 'IA_CSS_PSYSAPI_TASK_FINISHED' notification when the suspension
 * has completed.
 *
 * @param [in] task
 * @param [in] assigned_resources
 * @param [in] resource_mapping     the assigned logical to physical resource mapping
 * @param [in] resource_mapping     logical to physical resource mapping
 *
 * @retval 0         on success
 * @retval EINVAL    when 'task' does not point to a valid task
 * @retval EPERM     when the task is not in a suspended state.
 *
 */
int ia_css_psysapi_task_resume(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_resource_list* assigned_resources,
	struct ia_css_psysapi_resource_mapping resource_mapping
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Request the abortion of a task.
 *
 * This function request an asynchronous abortion of the specified task. Note that this API
 * does not offer any synchronous method of destroying a task. The client can only request an abort.
 * And then wait for the life-time of the task to end. This life-time ends at the moment the
 * API client gets a ia_css_psys_response_end_of_task response.
 *
 * @param [in] task
 *
 * @retval 0         on success
 * @retval EINVAL    when 'task' does not point to a valid task
 *
 */
int ia_css_psysapi_task_abort(
	struct ia_css_psys_task* task
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Get the next raw event from the PSYS task API return queue
 *
 * This function shall be called when the client is notified that an event is present.
 * The notification will typically be an interrupt to wake up the driver.
 * but this mechanism is platform dependent, and outside the scope of this API.
 * To turn the received raw event into readable format the function
 * ia_css_psysapi_task_translate_event() shall be called.
 *
 * @param [out] raw_event         to receive an event still in the internal opaque format
 * @param [out] delegator_cookie  to receive the delegation cookie if applicable,
 *                                see ia_css_psysapi_task_set_delegation_context()
 *
 * @retval 0         on success
 * @retval EINVAL    when 'raw_event' is a NULL pointer
 * @retval ENOBUFS   no more events available
 */
int ia_css_psysapi_task_get_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	void** delegator_cookie
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Translate a raw opaque event into a strongly typed event
 *
 * The purpose of this function is to hide the casts needed to let an event
 * travel from an environment with 32 bit data pointers to an environment with
 * 64 bit data pointers, or vise versa.
 *
 * @param [in] raw_event   to pass an opaque raw event
 * @param [out] event      to receive the corresponding translated event
 *
 * @retval 0         on success
 * @retval EINVAL    when one or more NULL pointers are passed
 */
int ia_css_psysapi_task_translate_event(
	struct ia_css_psysapi_task_raw_event* raw_event,
	struct ia_css_psysapi_task_event* event
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   To collect the next still attached buffer after a task has ended
 *
 * Note: the client shall call this function repeatedly until all buffers are detached.
 * When all buffers are detached, any subsequent call will result in returning ENOBUFS
 * Note: in case of detaching an output buffer the client shall check the output 'status'.
 * A status EMPTY signals that the task finished without filling the output buffer.
 *
 * Note that the buffer pointer collected here, is different from the original buffer pointer
 * that was passed to 'ia_css_psysapi_task_attach_buffer()'. The original pointer is
 * used to copy all buffer attributes into the task object. The 'buffer' pointer received from
 * ia_css_psysapi_task_detach_buffer is a pointer into the task object, pointing to a structure
 * with copies of the originally passed buffer attributes.
 *
 * The above implies that the received 'buffer' pointer value can not be used to
 * determine the buffer identity. Instead the client shall use cookies. When calling
 * the buffer attach function the user shall store context in the buffer's cookie,
 * and recover the cookie when detaching the buffer.
 *
 * @param [in] task
 * @param [out] terminal_id  the terminal id from which a buffer has just been detached
 * @param [out] buffer       to receive the detached buffer
 * @param [out] status       FULL in case an output buffer has successfully been filled, else EMPTY
 *
 * @retval 0         on success
 * @retval EINVAL    when 'task' does not point to a valid task
 * @retval ENOBUFS   when all buffers are detached
 */
int ia_css_psysapi_task_detach_buffer(
	struct ia_css_psys_task* task,
	ia_css_psys_terminal_id_t* terminal_id,
	struct ia_css_psys_buffer** buffer
);

/*--------------------------------------------------------------------------------------*/
/**
 * @brief   Detach the task buffer.
 *
 * This function marks the task buffer as destroyed. This is only for debugging purposes
 * to catch any attempt to access the task buffer after destruction.
 * After this call the user shall destroy or recycle the 'task_buffer'
 *
 * @param [in] task
 * @param [out] task_buffer  to receive a pointer to the no longer used task buffer
 *
 * @retval 0         on success
 * @retval EINVAL    when 'task' does not point to a valid task
 */
int ia_css_psysapi_task_destroy(
	struct ia_css_psys_task* task,
	struct ia_css_psysapi_task_buffer** task_buffer
);

/*--------------------------------------------------------------------------------------*/

#endif /* __IA_CSS_PSYSAPI_H_INCLUDED__  */




