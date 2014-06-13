#ifndef __GC_PRODUCTS_H_
#define __GC_PRODUCTS_H__


#include "gc.h"

#ifdef CONFIG_GC_0310
#include "gc_0310.h"
#endif

#ifdef CONFIG_GC_2155
#include "gc_2155.h"
#endif

struct gc_product_mapping product_mappings[] = {

#ifdef CONFIG_GC_2155
	{ GC2155_ID, &gc2155_product_info },
#endif

#ifdef CONFIG_GC_0310
	{ 0xa310, &gc0310_product_info }, 
#endif
};

#endif /* __GC_PRODUCTS_H__ */
