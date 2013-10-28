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

#include "sh_css_firmware.h"

#include "sh_css_defs.h"
#include "sh_css_internal.h"
#include "sh_css_sp_start.h"

#include "memory_access.h"
#include "assert_support.h"

#include "isp.h"				/* PMEM_WIDTH_LOG2 */


struct firmware_header {
	struct sh_css_fw_bi_file_h file_header;
	struct ia_css_fw_info      binary_header;
};

/* Warning: same order as SH_CSS_BINARY_ID_* */
static struct firmware_header *firmware_header;

struct ia_css_fw_info	  sh_css_sp_fw;
struct ia_css_blob_descr *sh_css_blob_info; /* Only ISP blob info (no SP) */
unsigned		  sh_css_num_binaries; /* This includes 1 SP binary */

/*
 * Split the loaded firmware into blobs
 */

/* Setup sp binary */
static void
setup_sp(struct ia_css_fw_info *fw, const char *fw_data)
{
	const char *blob_data;

	assert(fw != NULL);
	assert(fw_data != NULL);

	blob_data = fw_data + fw->blob.offset;

	sh_css_sp_fw = *fw;
	/* MW: code starts at "offset" */
	sh_css_sp_fw.blob.code = blob_data /* + fw->blob.text_source */;
	sh_css_sp_fw.blob.data = blob_data + fw->blob.data_source;
}

enum ia_css_err
sh_css_load_blob_info(const char *fw, const struct ia_css_fw_info *bi, struct ia_css_blob_descr *bd)
{
	const char *name;
	const unsigned char *blob;
	const struct ia_css_memory_offsets *mem_offsets;

	assert(fw != NULL);
	assert(bd != NULL);
	
	/* Special case: only one binary in fw */
	if (bi == NULL) bi = (const struct ia_css_fw_info *)fw;

	mem_offsets = (const struct ia_css_memory_offsets *)(fw + bi->blob.memory_offset);
	name = (const char *)fw + bi->blob.prog_name_offset;
	blob = (const unsigned char *)fw + bi->blob.offset;

	/* sanity check */
	if (bi->blob.size != bi->blob.text_size + bi->blob.icache_size + bi->blob.data_size + bi->blob.padding_size) {
		/* sanity check, note the padding bytes added for section to DDR alignment */
		return IA_CSS_ERR_INVALID_ARGUMENTS;
	}

	if ((bi->blob.offset % (1UL<<(ISP_PMEM_WIDTH_LOG2-3))) != 0)
		return IA_CSS_ERR_INVALID_ARGUMENTS;

	bd->blob = blob;
	bd->header = *bi;
	bd->name = name;
	bd->mem_offsets = NULL;
	if (bi->type == ia_css_isp_firmware)
		bd->mem_offsets = mem_offsets;
	return IA_CSS_SUCCESS;
}

enum ia_css_err
sh_css_load_firmware(const char *fw_data,
		     unsigned int fw_size)
{
	unsigned i;
	struct ia_css_fw_info *binaries;
	struct sh_css_fw_bi_file_h *file_header;

	firmware_header = (struct firmware_header*)fw_data;
	file_header = (struct sh_css_fw_bi_file_h *)&firmware_header->file_header;
	binaries = (struct ia_css_fw_info *)&firmware_header->binary_header;

	/* some sanity checks */
	if (!fw_data || fw_size < sizeof(struct sh_css_fw_bi_file_h))
		return IA_CSS_ERR_INTERNAL_ERROR;

	if (file_header->h_size != sizeof(struct sh_css_fw_bi_file_h))
		return IA_CSS_ERR_INTERNAL_ERROR;

	sh_css_num_binaries = file_header->binary_nr;
	/* Only allocate memory for ISP blob info */
	sh_css_blob_info = sh_css_malloc((sh_css_num_binaries - 1) *
						sizeof(*sh_css_blob_info));

	if (sh_css_blob_info == NULL)
		return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;

	for (i = 0; i < sh_css_num_binaries; i++) {
		struct ia_css_fw_info *bi = &binaries[i];
		struct ia_css_blob_descr bd;
		enum ia_css_err err;

		err = sh_css_load_blob_info (fw_data, bi, &bd);
		if (err != IA_CSS_SUCCESS)
			return IA_CSS_ERR_INTERNAL_ERROR;

		if (bi->blob.offset + bi->blob.size > fw_size)
			return IA_CSS_ERR_INTERNAL_ERROR;

		if (bi->type == ia_css_sp_firmware) {
			/* The first binary (i==0) is always the SP firmware */
			if (i != 0)
				return IA_CSS_ERR_INTERNAL_ERROR;
			setup_sp(bi, fw_data);
		} else {
			/* All subsequent binaries (i>=1) are ISP firmware */
			if (i == 0)
				return IA_CSS_ERR_INTERNAL_ERROR;
			if (bi->type != ia_css_isp_firmware)
				return IA_CSS_ERR_INTERNAL_ERROR;
			sh_css_blob_info[i-1] = bd;
		}
	}
	return IA_CSS_SUCCESS;
}

void sh_css_unload_firmware(void)
{
	memset(&sh_css_sp_fw, 0, sizeof(sh_css_sp_fw));
	if (sh_css_blob_info) {
		sh_css_free(sh_css_blob_info);
		sh_css_blob_info = NULL;
	}
	sh_css_num_binaries = 0;
}

hrt_vaddress
sh_css_load_blob(const unsigned char *blob, unsigned size)
{
	hrt_vaddress target_addr = mmgr_malloc(size);
	/* this will allocate memory aligned to a DDR word boundary which
	   is required for the CSS DMA to read the instructions. */

	assert(blob != NULL);
	if (target_addr) {
		mmgr_store(target_addr, blob, size);
#if SH_CSS_PREVENT_UNINIT_READS == 1
		{
			unsigned padded_size = CEIL_MUL(size, HIVE_ISP_DDR_WORD_BYTES);
			mmgr_clear(target_addr + size, padded_size - size);
		}
#endif
	}
	return target_addr;
}
