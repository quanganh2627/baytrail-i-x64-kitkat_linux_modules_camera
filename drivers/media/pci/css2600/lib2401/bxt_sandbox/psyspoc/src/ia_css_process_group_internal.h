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

#ifndef __IA_CSS_PSYSAPI_H_INCLUDED__
#define __IA_CSS_PSYSAPI_H_INCLUDED__

#include <type_support.h>
#include <print_support.h>
#include "ia_css_psys_system_global.h"
#include "ia_css_program_group.h"
#include "ia_css_process_group.h"
#include "ia_css_frame_public.h"

/*
 * All types and data structures; Not organised look for {private, public}
 */

typedef struct ia_css_frame						ia_css_frame_t;
typedef struct ia_css_process					ia_css_process_t;
typedef struct ia_css_psys_frame				ia_css_psys_frame_t;

/* private */
typedef enum ia_css_process_group_cmd {
	IA_CSS_PROCESS_GROUP_CMD_NOP = 0,
	IA_CSS_PROCESS_GROUP_CMD_SUBMIT,
	IA_CSS_PROCESS_GROUP_CMD_ATTACH,
	IA_CSS_PROCESS_GROUP_CMD_DETACH,
	IA_CSS_PROCESS_GROUP_CMD_START,
	IA_CSS_PROCESS_GROUP_CMD_RUN,
	IA_CSS_PROCESS_GROUP_CMD_STOP,
	IA_CSS_PROCESS_GROUP_CMD_SUSPEND,
	IA_CSS_PROCESS_GROUP_CMD_RESUME,
	IA_CSS_PROCESS_GROUP_CMD_ABORT,
	IA_CSS_PROCESS_GROUP_CMD_RESET,
	IA_CSS_N_PROCESS_GROUP_CMDS
} ia_css_process_group_cmd_t;

/* private */
typedef enum ia_css_process_group_state {
	IA_CSS_PROCESS_GROUP_ERROR = 0,
	IA_CSS_PROCESS_GROUP_CREATED,
	IA_CSS_PROCESS_GROUP_READY,
	IA_CSS_PROCESS_GROUP_BLOCKED,
	IA_CSS_PROCESS_GROUP_STARTED,
	IA_CSS_PROCESS_GROUP_RUNNING,
	IA_CSS_PROCESS_GROUP_STOPPED,
	IA_CSS_N_PROCESS_GROUP_STATES
} ia_css_process_group_state_t;

/* private */
typedef enum ia_css_process_cmd {
	IA_CSS_PROCESS_CMD_NOP = 0,
	IA_CSS_PROCESS_CMD_ACQUIRE,
	IA_CSS_PROCESS_CMD_RELEASE,
	IA_CSS_PROCESS_CMD_START,
	IA_CSS_PROCESS_CMD_LOAD,
	IA_CSS_PROCESS_CMD_STOP,
	IA_CSS_PROCESS_CMD_SUSPEND,
	IA_CSS_PROCESS_CMD_RESUME,
	IA_CSS_N_PROCESS_CMDS
} ia_css_process_cmd_t;

/* private */
typedef enum ia_css_process_state {
	IA_CSS_PROCESS_ERROR = 0,
	IA_CSS_PROCESS_CREATED,
	IA_CSS_PROCESS_READY,
	IA_CSS_PROCESS_STARTED,
	IA_CSS_PROCESS_RUNNING,
	IA_CSS_PROCESS_STOPPED,
	IA_CSS_PROCESS_SUSPENDED,
	IA_CSS_N_PROCESS_STATES
} ia_css_process_state_t;

/* private */
typedef enum ia_css_location_mem {
	IA_CSS_INTERNAL_MEM = 0,
	IA_CSS_EXTERNAL_MEM,
	IA_CSS_N_LOCATION_MEM
} ia_css_location_mem_t;

struct ia_css_psys_frame {
	ia_css_frame_t			css_frame;
	ia_css_buffer_state_t	buffer_state;
};

/* private */
struct ia_css_terminal {
	uint32_t							size;											/**< Size of this structure */
	ia_css_terminal_type_t				terminal_type;									/**< Type {in, out, state, ...} */
	ia_css_process_group_t				*parent;										/**< Reference to the process group */
	ia_css_frame_descriptor_t			frame_descriptor;								/**< Properties of the frame attached to the terminal */
	ia_css_psys_frame_t					frame;											/**< Frame handle attached to the terminal */
	ia_css_fragment_descriptor_t		*fragment_descriptor;							/**< Array[fragment_count] (equal for all terminals) of fragment descriptors */
};

/* private */
struct ia_css_process_group {
	uint32_t							size;											/**< Size of this structure */
	ia_css_program_group_ID_t			ID;												/**< Referal ID to program group FW */
	ia_css_process_group_state_t		state;											/**< State of the process group FSM */
	uint64_t							token;											/**< User (callback) token / user context reference, zero is an error value */
	uint8_t								process_count;									/**< Parameter dependent number of processes in this process group */
	uint8_t				 				terminal_count;									/**< Parameter dependent number of terminals on this process group */
	uint16_t							fragment_count;									/**< Number of fragments offered on each terminal */
	uint16_t							fragment_state;									/**< Current fragment of of processing */
	uint16_t							fragment_limit;									/**< Watermark to control fragment processing */
	vied_nci_resource_bitmap_t			resource_bitmap;								/**< Bitmap of the compute resources used by the process group  */
	ia_css_process_t					**processes;									/**< Array[process_count] of process addresses in this process group */
	ia_css_terminal_t					**terminals;									/**< Array[terminal_count] of terminal addresses on this process group */
};

/* private */
struct ia_css_process {
	uint32_t							size;											/**< Size of this structure */
	ia_css_program_ID_t					ID;												/**< Referal ID to a specific program FW */
	ia_css_process_state_t				state;											/**< State of the process FSM dependent on the parent FSM */
	ia_css_process_group_t				*parent;										/**< Reference to the process group */
	vied_nci_resource_id_t				cell_id;										/**< (mandatory) specification of a cell to be used by this process */
	vied_nci_resource_id_t				int_mem_id[VIED_NCI_N_MEM_TYPE_ID];				/**< (internal) Memory ID; This is redundant, derived from cell_id */
	vied_nci_resource_size_t			int_mem_offset[VIED_NCI_N_MEM_TYPE_ID];			/**< (internal) Memory allocation offset given to this process */
	vied_nci_resource_id_t				ext_mem_id[VIED_NCI_N_DATA_MEM_TYPE_ID];		/**< (external) Memory ID */
	vied_nci_resource_size_t			ext_mem_offset[VIED_NCI_N_DATA_MEM_TYPE_ID];	/**< (external) Memory allocation offset given to this process */
	vied_nci_resource_size_t			chn_offset[VIED_NCI_N_DEV_CHN_ID];				/**< Device channel allocation offset given to this process */
	uint8_t								cell_dependency_count;							/**< Number of processes (mapped on cells) this process depends on */
	uint8_t								terminal_dependency_count;						/**< Number of terminals this process depends on */
	vied_nci_resource_id_t				*cell_dependencies;								/**< Array[dependency_count] of ID's of the cells that provide input */
	uint8_t								*terminal_dependencies;							/**< Array[terminal_dependency_count] of indices of connected terminals */
};


/* API */

/*
 * Sequencing resources
 */
extern int ia_css_process_group_set_barrier(
	ia_css_process_group_t					*process_group,
	const vied_nci_barrier_ID_t				barrier_index);

extern int ia_css_process_group_clear_barrier(
	ia_css_process_group_t					*process_group,
	const vied_nci_barrier_ID_t				barrier_index);

/*
 * Internal resources
 */
extern int ia_css_process_clear_all(
	ia_css_process_t						*process);

extern int ia_css_process_set_cell(
	ia_css_process_t						*process,
	const vied_nci_cell_ID_t				cell_id);

extern int ia_css_process_clear_cell(
	ia_css_process_t						*process);

extern int ia_css_process_set_int_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_ID_t					mem_id,
	const vied_nci_resource_size_t			offset);

extern int ia_css_process_clear_int_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_type_ID_t			mem_type_id);

extern int ia_css_process_set_ext_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_ID_t					mem_id,
	const vied_nci_resource_size_t			offset);

extern int ia_css_process_clear_ext_mem(
	ia_css_process_t						*process,
	const vied_nci_mem_type_ID_t			mem_type_id);

extern int ia_css_process_set_dev_chn(
	ia_css_process_t						*process,
	const vied_nci_dev_chn_ID_t				dev_chn_id,
	const vied_nci_resource_size_t			offset);

extern int ia_css_process_clear_dev_chn(
	ia_css_process_t						*process,
	const vied_nci_dev_chn_ID_t				dev_chn_id);

/*
 * Resources needs
 */

/* OPEN access to manifests */


/* private: embedded */
/*
 * Dispatcher
 */
extern int ia_css_process_group_run(
	ia_css_process_group_t					*process_group);

extern int ia_css_process_group_stop(
	ia_css_process_group_t					*process_group);

/*
 * Process manager
 */
extern int ia_css_process_acquire(
	ia_css_process_t						*process);

extern int ia_css_process_release(
	ia_css_process_t						*process);

/*
 * Command processor
 */
extern int ia_css_process_group_cmd(
	ia_css_process_group_t					*process_group,
	const ia_css_process_group_cmd_t		cmd);

extern int ia_css_process_cmd(
	ia_css_process_t						*process,
	const ia_css_process_cmd_t				cmd);

/* private */
/*
 * To build a working model, generate FW, test, verify etc ... Needs some sorting
 */

extern ia_css_process_group_state_t ia_css_process_group_get_state(
	const ia_css_process_group_t			*process_group);

extern size_t ia_css_sizeof_terminal(
	const ia_css_terminal_manifest_t		*manifest,
	const ia_css_program_group_param_t		*param);

extern int ia_css_terminal_set_type(
	ia_css_terminal_t						*terminal,
	const ia_css_terminal_type_t			terminal_type);


extern uint8_t *ia_css_frame_get_buffer(
	const ia_css_psys_frame_t				*frame);

extern int ia_css_frame_set_buffer(
	ia_css_psys_frame_t						*frame,
	uint8_t									*buffer);

extern ia_css_buffer_state_t ia_css_frame_get_buffer_state(
	const ia_css_psys_frame_t				*frame);

extern int ia_css_frame_set_buffer_state(
	ia_css_psys_frame_t						*frame,
	const ia_css_buffer_state_t				buffer_state);

extern ia_css_terminal_t *ia_css_terminal_create(
	const ia_css_terminal_manifest_t		*manifest,
	const ia_css_program_group_param_t		*param);

extern ia_css_terminal_t *ia_css_terminal_destroy(
	ia_css_terminal_t						*terminal);

extern int ia_css_terminal_set_parent(
	ia_css_terminal_t						*terminal,
	ia_css_process_group_t					*parent);

extern ia_css_process_group_t *ia_css_terminal_get_parent(
	const ia_css_terminal_t					*terminal);


extern bool ia_css_is_process_group_valid(
	const ia_css_process_group_t			*process_group,
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern bool ia_css_can_process_group_submit (
	const ia_css_process_group_t			*process_group);

extern bool ia_css_can_process_group_start (
	const ia_css_process_group_t			*process_group);

extern ia_css_program_group_ID_t ia_css_process_group_get_program_group_ID(
	const ia_css_process_group_t			*process_group);

extern vied_nci_resource_bitmap_t ia_css_process_group_get_resource_bitmap(
	const ia_css_process_group_t			*process_group);

extern int ia_css_process_group_set_resource_bitmap(
	ia_css_process_group_t					*process_group,
	const vied_nci_resource_bitmap_t		resource_bitmap);


extern uint32_t ia_css_process_group_compute_cycle_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern uint8_t ia_css_process_group_compute_process_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern uint8_t ia_css_process_group_compute_terminal_count(
	const ia_css_program_group_manifest_t	*manifest,
	const ia_css_program_group_param_t		*param);

extern size_t ia_css_sizeof_process(
	const ia_css_program_manifest_t			*manifest,
	const ia_css_program_param_t			*param);

extern ia_css_process_t *ia_css_process_create(
	const ia_css_program_manifest_t			*manifest,
	const ia_css_program_param_t			*param);

extern ia_css_process_t *ia_css_process_destroy(
	ia_css_process_t						*process);

extern int ia_css_process_set_parent(
	ia_css_process_t						*process,
	ia_css_process_group_t					*parent);

extern ia_css_process_group_t *ia_css_process_get_parent(
	const ia_css_process_t					*process);

extern size_t ia_css_process_get_size(
	const ia_css_process_t					*process);

extern ia_css_program_ID_t ia_css_process_get_program_ID(
	const ia_css_process_t					*process);

extern ia_css_process_state_t ia_css_process_get_state(
	const ia_css_process_t					*process_group);

extern vied_nci_cell_ID_t ia_css_process_get_cell(
	const ia_css_process_t					*process);

extern uint8_t ia_css_process_get_cell_dependency_count(
	const ia_css_process_t					*process);

extern uint8_t ia_css_process_get_terminal_dependency_count(
	const ia_css_process_t					*process);

extern vied_nci_cell_ID_t ia_css_program_manifest_get_cell_id(
	const ia_css_program_manifest_t			*manifest);

extern vied_nci_cell_type_ID_t ia_css_program_manifest_get_cell_type_id(
	const ia_css_program_manifest_t			*manifest);

extern vied_nci_resource_size_t ia_css_program_manifest_get_mem_size(
	const ia_css_program_manifest_t			*manifest,
	const uint16_t							mem_index,
	const ia_css_location_mem_t				mem_location);

extern vied_nci_resource_size_t ia_css_program_manifest_get_chn_size(
	const ia_css_program_manifest_t			*manifest,
	const vied_nci_dev_chn_ID_t				chn_id);

extern size_t ia_css_program_manifest_get_size(
	const ia_css_program_manifest_t			*manifest);

extern uint8_t ia_css_program_manifest_get_program_dependency_count(
	const ia_css_program_manifest_t			*manifest);

extern uint8_t ia_css_program_manifest_get_terminal_dependency_count(
	const ia_css_program_manifest_t			*manifest);

extern size_t ia_css_terminal_get_size(
	const ia_css_terminal_t					*terminal);

/*
 * Access to sub-structure handles / fields
 */
extern uint16_t ia_css_process_group_get_fragment_count(
	const ia_css_process_group_t			*process_group);

extern uint8_t ia_css_process_group_get_process_count(
	const ia_css_process_group_t			*process_group);

extern ia_css_process_t *ia_css_process_group_get_process(
	const ia_css_process_group_t			*process_group,
	const unsigned int						process_index);

extern size_t ia_css_process_group_get_size(
	const ia_css_process_group_t			*process_group);

extern ia_css_frame_descriptor_t *ia_css_terminal_get_frame_descriptor(
	const ia_css_terminal_t					*terminal);

extern ia_css_fragment_descriptor_t *ia_css_terminal_get_fragment_descriptor(
	const ia_css_terminal_t					*terminal,
	const unsigned int						fragment_index);

extern uint16_t ia_css_terminal_get_fragment_count(
	const ia_css_terminal_t					*terminal);

extern ia_css_psys_frame_t *ia_css_terminal_get_frame(
	const ia_css_terminal_t					*terminal);


/*
 * Test / BIST
 */
extern void ia_css_psys_ran_set_seed (
    const unsigned int      seed);

extern unsigned int ia_css_psys_ran_var (
    const unsigned int      bit_depth);

extern unsigned int ia_css_psys_ran_val (
    const unsigned int      range);

#endif /* __IA_CSS_PSYSAPI_H_INCLUDED__  */



