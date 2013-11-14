/*
 * Copyright (c) 2013 Intel Corporation. All Rights Reserved.
 */

enum {
	ATOMISP_PSYS_STUB_PREVIEW = 1,
};

/** Unsigned fixed point value, 0 integer bits, 16 fractional bits */
#define u0_16 unsigned int

/** Optical black mode.
 */
enum sh_css_ob_mode {
	sh_css_ob_mode_none,
	sh_css_ob_mode_fixed,
	sh_css_ob_mode_raster
};

struct sh_css_ob_config {
	enum sh_css_ob_mode mode; /**< Mode (Fixed / Raster) */
	u0_16 level_gr;    /**< Black level for GR pixels */
	u0_16 level_r;     /**< Black level for R pixels */
	u0_16 level_b;     /**< Black level for B pixels */
	u0_16 level_gb;    /**< Black level for GB pixels */
	unsigned short start_position; /**< Start position of OB area (used for
				      raster mode only). Valid range is [0..63]. */
	unsigned short end_position;  /**< End position of OB area (used for
				      raster mode only).
				      Valid range is [start_pos..64]. */
};

struct preview_params {
	struct sh_css_ob_config ob;
};

struct psysparam {
	uint32_t len;
	union {
		struct preview_params params;
		uint8_t* buffer;
	} m;
};
