
#include "ia_css_program_group_internal.h"
#include "ia_css_program_group.h"
#include "ia_css_psys_system_global.h"
#include <error_support.h>
#include <assert_support.h>
#include <misc_support.h>

#define verifjmpexit(cond)          \
do {                                \
	if (!(cond)){                   \
		goto EXIT;                  \
	}                               \
} while(0)

size_t ia_css_program_group_manifest_get_size(
	const ia_css_program_group_manifest_t	*manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		size = manifest->size;
	}

	return size;
}

ia_css_program_group_ID_t ia_css_program_group_manifest_get_program_group_ID(
	const ia_css_program_group_manifest_t	*manifest)
{
	ia_css_program_group_ID_t	id = 0;

	verifjmpexit(manifest != NULL);

	id = manifest->ID;

EXIT:
	return id;
}

uint8_t ia_css_program_group_manifest_get_program_count(
	const ia_css_program_group_manifest_t	*manifest)
{
	uint8_t	program_count = 0;
	if (manifest != NULL) {
		program_count = manifest->program_count;
	}

	return program_count;
}

uint8_t ia_css_program_group_manifest_get_terminal_count(
	const ia_css_program_group_manifest_t	*manifest)
{
	uint8_t	terminal_count = 0;
	if (manifest != NULL) {
		terminal_count = manifest->terminal_count;
	}

	return terminal_count;
}

ia_css_program_manifest_t *ia_css_program_group_manifest_get_program_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						program_index)
{
	ia_css_program_manifest_t	*program_manifest = NULL;
	uint8_t						program_count = ia_css_program_group_manifest_get_program_count(manifest);

	verifjmpexit(manifest != NULL);
	verifjmpexit(program_index < program_count);

	program_manifest = manifest->program_manifest[program_index];
EXIT:
	return program_manifest;
}

ia_css_terminal_manifest_t *ia_css_program_group_manifest_get_terminal_manifest(
	const ia_css_program_group_manifest_t	*manifest,
	const unsigned int						terminal_index)
{
	ia_css_terminal_manifest_t *terminal_manifest = NULL;
	uint8_t						terminal_count = ia_css_program_group_manifest_get_terminal_count(manifest);

	verifjmpexit(manifest != NULL);
	verifjmpexit(terminal_index < terminal_count);

	terminal_manifest = manifest->terminal_manifest[terminal_index];
EXIT:
	return terminal_manifest;
}

size_t ia_css_sizeof_terminal_manifest(
	const ia_css_terminal_manifest_t			*manifest)
{
	size_t	size = 0;

	verifjmpexit(manifest != NULL);

	size += sizeof(ia_css_terminal_manifest_t);

EXIT:
	return size;
}

size_t ia_css_terminal_manifest_get_size(
	const ia_css_terminal_manifest_t		*manifest)
{
	size_t	size = 0;

	if (manifest != NULL) {
		size = manifest->size;
	}

	return size;
}

ia_css_terminal_type_t ia_css_terminal_manifest_get_type(
	const ia_css_terminal_manifest_t		*manifest)
{
	ia_css_terminal_type_t	terminal_type = IA_CSS_N_TERMINAL_TYPE;

	if (manifest != NULL) {
		terminal_type = manifest->terminal_type;
	}

	return terminal_type;
}

bool ia_css_program_manifest_has_fixed_cell(
	const ia_css_program_manifest_t			*manifest)
{
	bool	has_fixed_cell = false;

	vied_nci_cell_ID_t		cell_id;
	vied_nci_cell_type_ID_t	cell_type_id;

	verifjmpexit(manifest != NULL);

	cell_id = ia_css_program_manifest_get_cell_ID(manifest);
	cell_type_id = (vied_nci_cell_type_ID_t)(manifest->cell_type_id);
	has_fixed_cell = ((cell_id != VIED_NCI_N_CELL_ID) && (cell_type_id == VIED_NCI_N_CELL_TYPE_ID));
EXIT:
	return has_fixed_cell;
}

ia_css_program_ID_t ia_css_program_manifest_get_program_ID(
	const ia_css_program_manifest_t			*manifest)
{
	ia_css_program_ID_t		program_id = 0;

	verifjmpexit(manifest != NULL);

	program_id = manifest->ID;

EXIT:
	return program_id;
}

vied_nci_cell_ID_t ia_css_program_manifest_get_cell_ID(
	const ia_css_program_manifest_t			*manifest)
{
	vied_nci_cell_ID_t		cell_id = VIED_NCI_N_CELL_ID;

	verifjmpexit(manifest != NULL);

	cell_id = (vied_nci_cell_ID_t)(manifest->cell_id);
EXIT:
	return cell_id;
}

ia_css_program_param_t *ia_css_program_group_param_get_program_param(
	const ia_css_program_group_param_t		*param,
	const int								i)
{
	ia_css_program_param_t	*program_param = NULL;
	if (param != NULL) {
		program_param = param->program_param[i];
	}

	return program_param;
}

uint8_t ia_css_program_group_param_get_program_count(
	const ia_css_program_group_param_t		*param)
{
	uint8_t	program_count = 0;
	if (param != NULL) {
		program_count = param->program_count;
	}

	return program_count;
}

uint16_t ia_css_program_group_param_get_fragment_count(
	const ia_css_program_group_param_t		*param)
{
	uint8_t	fragment_count = 0;
	if (param != NULL) {
		fragment_count = param->fragment_count;
	}

	return fragment_count;
}

uint8_t ia_css_program_manifest_get_program_dependency_count(
	const ia_css_program_manifest_t			*manifest)
{
	uint8_t	program_dependency_count = 0;
	if (manifest != NULL) {
		program_dependency_count = manifest->program_dependency_count;
	}
	return program_dependency_count;
}

uint8_t ia_css_program_manifest_get_terminal_dependency_count(
	const ia_css_program_manifest_t			*manifest)
{
	uint8_t	terminal_dependency_count = 0;
	if (manifest != NULL) {
		terminal_dependency_count = manifest->terminal_dependency_count;
	}
	return terminal_dependency_count;
}

