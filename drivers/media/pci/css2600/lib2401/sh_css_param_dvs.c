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

#include "sh_css_param_dvs.h"
#include <assert_support.h>
#include <type_support.h>
#include <ia_css_err.h>
#include <ia_css_types.h>
#include "ia_css_debug.h"
#include "memory_access.h"

#if defined(IS_ISP_2500_SYSTEM)
#include <components/acc_cluster/acc_dvs_stat/dvs_stat_private.h>
#include <components/acc_cluster/acc_dvs_stat/host/dvs_stat.host.h>
#endif

struct ia_css_dvs_6axis_config *
generate_dvs_6axis_table(const struct ia_css_resolution	*frame_res, const struct ia_css_resolution *dvs_offset)
{
	
	unsigned int x,y;
	unsigned int width_y;
	unsigned int height_y;
	unsigned int width_uv;
	unsigned int height_uv;
	enum ia_css_err err = IA_CSS_SUCCESS;	
	struct ia_css_dvs_6axis_config  *dvs_config = NULL;

	assert(frame_res != NULL);
	assert(dvs_offset != NULL);
	
	dvs_config = (struct ia_css_dvs_6axis_config *)sh_css_malloc(sizeof(struct ia_css_dvs_6axis_config));
	if(dvs_config == NULL)
	{
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "out of memory\n");
		err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
	}
	else
	{	/*Initialize new struct with latest config settings*/	
		dvs_config->width_y = width_y = DVS_TABLE_IN_BLOCKDIM_X_LUMA(frame_res->width);
		dvs_config->height_y = height_y = DVS_TABLE_IN_BLOCKDIM_Y_LUMA(frame_res->height);
		dvs_config->width_uv = width_uv = DVS_TABLE_IN_BLOCKDIM_X_CHROMA(frame_res->width / 2); /* UV = Y/2, depens on colour format YUV 4.2.0*/
		dvs_config->height_uv = height_uv = DVS_TABLE_IN_BLOCKDIM_Y_CHROMA(frame_res->height / 2);/* UV = Y/2, depens on colour format YUV 4.2.0*/

		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "generate_dvs_6axis_table: Env_X %d Env_Y %d\n",dvs_offset->width,dvs_offset->height);
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "generate_dvs_6axis_table Y: W %d H %d\n",width_y,height_y);
		/* Generate Y buffers  */
		dvs_config->xcoords_y = (uint32_t *)sh_css_malloc( width_y * height_y * sizeof(uint32_t));	
		if(dvs_config->xcoords_y == NULL)
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "out of memory\n");
			err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
		}
		else
		{
			for(y = 0; y < height_y; y++)
			{
				for(x=0;x<width_y;x++)
				{
					dvs_config->xcoords_y[y*width_y + x] =  (  ( dvs_offset->width + x*DVS_BLOCKDIM_X) << DVS_COORD_FRAC_BITS );
				}
			}
		}

		dvs_config->ycoords_y = (uint32_t *)sh_css_malloc( width_y * height_y * sizeof(uint32_t));
		if(dvs_config->ycoords_y == NULL)
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "out of memory\n");
			err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
		}
		else
		{			
			for(y = 0; y < height_y; y++)
			{
				for(x=0;x<width_y;x++)
				{
					dvs_config->ycoords_y[y*width_y + x] =  (  ( dvs_offset->height + y*DVS_BLOCKDIM_Y_LUMA) << DVS_COORD_FRAC_BITS );
				}
			}
		}
		
		/* Generate UV buffers  */		
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "generate_dvs_6axis_table UV W %d H %d\n",width_uv,height_uv);
		
		dvs_config->xcoords_uv = (uint32_t *)sh_css_malloc( width_uv * height_uv * sizeof(uint32_t));	
		if(dvs_config->xcoords_uv == NULL)
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "out of memory\n");
			err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
		}
		else
		{			
			for(y = 0; y < height_uv; y++)
			{
				for(x=0;x<width_uv;x++)
				{	/* Envelope dimesions set in Ypixels hence offset UV = offset Y/2 */
					dvs_config->xcoords_uv[y*width_uv + x] =  (  ( (dvs_offset->width / 2) + x*DVS_BLOCKDIM_X) << DVS_COORD_FRAC_BITS ); 
				}
			}
		}
		    
		dvs_config->ycoords_uv = (uint32_t *)sh_css_malloc( width_uv * height_uv * sizeof(uint32_t));
		if(dvs_config->ycoords_uv == NULL)
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "out of memory\n");
			err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
		}
		else
		{	
			for(y = 0; y < height_uv; y++)
			{
				for(x=0;x<width_uv;x++)
				{ 	/* Envelope dimesions set in Ypixels hence offset UV = offset Y/2 */
					dvs_config->ycoords_uv[y*width_uv + x] =  (  ( (dvs_offset->height / 2) + y*DVS_BLOCKDIM_Y_CHROMA) << DVS_COORD_FRAC_BITS );
				}
			}
		}
		
#if 0
		for(y = 0; y < height_y; y++)
		{
			for(x=0;x<width_y;x++)
				ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "xcoords_y: %d \n",dvs_config->xcoords_y[y*width_y + x]);
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "\n");
		}
		
		for(y = 0; y < height_y; y++)
		{
			for(x=0;x<width_y;x++)
				ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ycoords_y: %d \n",dvs_config->ycoords_y[y*width_y + x]);
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "\n");
		}	
		
				for(y = 0; y < height_y; y++)
		{
			for(x=0;x<width_uv;x++)
				ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "xcoords_uv: %d \n",dvs_config->xcoords_uv[y*width_uv + x]);
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "\n");
		}
		
		for(y = 0; y < height_uv; y++)
		{
			for(x=0;x<width_uv;x++)
				ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ycoords_uv: %d \n",dvs_config->ycoords_uv[y*width_uv + x]);
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "\n");
		}				
#endif		    
		if (err != IA_CSS_SUCCESS)
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "generate_dvs_6axis_table: err %d\n, leave() ",(int)err);
			free_dvs_6axis_table(&dvs_config); /* we might have allocated some memory, release this */
		}
		else
		{
			ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "generate_dvs_6axis_table leave() , dvs_config %p\n",dvs_config);
		}
	}
	
	return dvs_config;
}

void
free_dvs_6axis_table(struct ia_css_dvs_6axis_config  **dvs_6axis_config)
{
	assert(dvs_6axis_config != NULL);
	assert(*dvs_6axis_config != NULL);

	if( (dvs_6axis_config != NULL) && (*dvs_6axis_config != NULL) ) 
	{
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "-> free_dvs_6axis_table dvs_6axis_config %p\n",(*dvs_6axis_config));
		if((*dvs_6axis_config)->xcoords_y != NULL)
		{
			 sh_css_free((*dvs_6axis_config)->xcoords_y);
			 (*dvs_6axis_config)->xcoords_y = NULL;
		}
		
		if((*dvs_6axis_config)->ycoords_y != NULL)
		{
			sh_css_free((*dvs_6axis_config)->ycoords_y);
			(*dvs_6axis_config)->ycoords_y = NULL;
		}	
		
		/* Free up UV buffers */
		if((*dvs_6axis_config)->xcoords_uv != NULL)
		{
			sh_css_free((*dvs_6axis_config)->xcoords_uv);
			(*dvs_6axis_config)->xcoords_uv = NULL;
		}
		
		if((*dvs_6axis_config)->ycoords_uv != NULL)
		{
			sh_css_free((*dvs_6axis_config)->ycoords_uv);
			(*dvs_6axis_config)->ycoords_uv = NULL;
		}
		
		sh_css_free(*dvs_6axis_config);
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "<- free_dvs_6axis_table dvs_6axis_config %p\n",(*dvs_6axis_config));
		*dvs_6axis_config = NULL;
	}
}

void copy_dvs_6axis_table(struct ia_css_dvs_6axis_config *dvs_config_dst,
			const struct ia_css_dvs_6axis_config *dvs_config_src)
{	
	unsigned int width_y;
	unsigned int height_y;
	unsigned int width_uv;
	unsigned int height_uv;

	assert(dvs_config_src!= NULL);
	assert(dvs_config_dst != NULL);
	assert(dvs_config_src->xcoords_y != NULL);
	assert(dvs_config_src->xcoords_uv != NULL);
	assert(dvs_config_src->ycoords_y != NULL);
	assert(dvs_config_src->ycoords_uv != NULL);
	assert(dvs_config_src->width_y == dvs_config_dst->width_y);
	assert(dvs_config_src->width_uv == dvs_config_dst->width_uv);
	assert(dvs_config_src->height_y == dvs_config_dst->height_y);
	assert(dvs_config_src->height_uv == dvs_config_dst->height_uv);

	width_y = dvs_config_src->width_y;
	height_y = dvs_config_src->height_y;
	width_uv = dvs_config_src->width_uv; /* = Y/2, depens on colour format YUV 4.2.0*/
	height_uv = dvs_config_src->height_uv;
		
	memcpy(dvs_config_dst->xcoords_y,dvs_config_src->xcoords_y, (width_y * height_y * sizeof(uint32_t)));
	memcpy(dvs_config_dst->ycoords_y,dvs_config_src->ycoords_y, (width_y * height_y * sizeof(uint32_t)));

	memcpy(dvs_config_dst->xcoords_uv,dvs_config_src->xcoords_uv, (width_uv * height_uv * sizeof(uint32_t)));
	memcpy(dvs_config_dst->ycoords_uv,dvs_config_src->ycoords_uv, (width_uv * height_uv * sizeof(uint32_t)));

}

#if defined(IS_ISP_2500_SYSTEM)
enum ia_css_err ia_css_get_skc_dvs_statistics(struct ia_css_skc_dvs_statistics *host_stats,
				   const struct ia_css_isp_skc_dvs_statistics *isp_stats)
{
	dvs_stat_private_dvs_stat_cfg_t	dvs_stat_cfg;
	dvs_stat_private_motion_vec_t*	dvs_stat_mv_p = NULL;
	unsigned char			set_idx, entry_idx, idx, i;
	hrt_vaddress			dvs_stat_ddr_addr;
	hrt_vaddress			dvs_stat_cfg_ddr_addr;
	dvs_stat_private_raw_buffer_t*	raw_buffer_p =
			(dvs_stat_private_raw_buffer_t*)isp_stats;
	struct dvs_stat_mv_entry_public *p_host_entry;
	struct dvs_stat_mv_private *p_isp_entry;

	dvs_stat_mv_p =
		(dvs_stat_private_motion_vec_t*)
			malloc(sizeof(dvs_stat_private_motion_vec_t));
	if(dvs_stat_mv_p == NULL)
	{
		ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
			"ia_css_get_skc_dvs_statistics() malloc error\n");
		return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
	}

	dvs_stat_ddr_addr = (hrt_vaddress) &raw_buffer_p->dvs_motion_vec;
	dvs_stat_cfg_ddr_addr = (hrt_vaddress) &raw_buffer_p->dvs_stat_cfg;

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
			"ia_css_get_skc_dvs_statistics() enter: "
			"host_stats=%p, isp_stats=%p\n",
			host_stats, isp_stats);

	mmgr_load(dvs_stat_ddr_addr,
			(void*)dvs_stat_mv_p,
			sizeof(dvs_stat_private_motion_vec_t));


	/* Load configuration */
	mmgr_load(dvs_stat_cfg_ddr_addr,
			(void*)&(dvs_stat_cfg),
			sizeof(dvs_stat_private_dvs_stat_cfg_t));

	/* Translate between private and public configuration */
	ia_css_dvs_stat_private_to_public_cfg(&host_stats->dvs_stat_cfg, &dvs_stat_cfg);

	// Translate between private and public motion vectors
	for(i = 0; i < IA_CSS_SKC_DVS_STAT_NUM_OF_LEVELS; i++) {

		for(set_idx = 0;
		     set_idx < host_stats->dvs_stat_cfg.grd_cfg[i].grd_cfg.grid_height;
		     set_idx++)
		{
			if(i == 0) {
				p_host_entry = host_stats->dvs_stat_mv_l0;
				p_isp_entry = &dvs_stat_mv_p->dvs_mv_output_l0[set_idx].mv_entry[0];
			} else if(i == 1) {
				p_host_entry = host_stats->dvs_stat_mv_l1;
				p_isp_entry = &dvs_stat_mv_p->dvs_mv_output_l1[set_idx].mv_entry[0];
			} else {
				p_host_entry = host_stats->dvs_stat_mv_l2;
				p_isp_entry = &dvs_stat_mv_p->dvs_mv_output_l2[set_idx].mv_entry[0];
			}
			for(entry_idx = 0;
			     entry_idx < host_stats->dvs_stat_cfg.grd_cfg[i].grd_cfg.grid_width;
			     entry_idx++)
			{
				idx = set_idx * host_stats->dvs_stat_cfg.grd_cfg[i].grd_cfg.grid_width + entry_idx;
				p_host_entry[idx].vec_fe_x_pos =
					p_isp_entry->part0.vec_fe_x_pos;
				p_host_entry[idx].vec_fe_y_pos =
					p_isp_entry->part0.vec_fe_y_pos;
				p_host_entry[idx].vec_fm_x_pos =
					p_isp_entry->part1.vec_fm_x_pos;
				p_host_entry[idx].vec_fm_y_pos =
					p_isp_entry->part1.vec_fm_y_pos;
				p_host_entry[idx].harris_grade =
					p_isp_entry->part2.harris_grade;
				p_host_entry[idx].match_grade =
					p_isp_entry->part3.match_grade;
				p_host_entry[idx].level =
					p_isp_entry->part3.level;
				p_isp_entry++;
			}
		}
	}

	free(dvs_stat_mv_p);

	ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
		"ia_css_get_skc_dvs_statistics() leave: return_void\n");

	return IA_CSS_SUCCESS;
}
#endif

void
ia_css_dvs_statistics_get(enum dvs_statistics_type type,
                          union ia_css_dvs_statistics_host  *host_stats,
                          const union ia_css_dvs_statistics_isp *isp_stats)
{
	if(DVS_STATISTICS == type)
	{
		ia_css_get_dvs_statistics(host_stats->p_dvs_statistics_host,
			isp_stats->p_dvs_statistics_isp);
	} else if(DVS2_STATISTICS == type)
	{
		ia_css_get_dvs2_statistics(host_stats->p_dvs2_statistics_host,
			isp_stats->p_dvs_statistics_isp);
	}
#if defined(IS_ISP_2500_SYSTEM)
	else if(SKC_DVS_STATISTICS == type)
	{
		ia_css_get_skc_dvs_statistics(host_stats->p_skc_dvs_statistics_host,
			(struct ia_css_isp_skc_dvs_statistics*)isp_stats);
	}
#endif
	return;
}

