#ifndef __GC_PRODUCTS_H__
#define __GC_PRODUCTS_H__

#include "gc.h"
/* #include "gc_0310.h" */
#include "gc_2155.h"

struct gc_product_mapping product_mappings[] = {
	{ GC2155_ID, &gc2155_product_info },
/*	{ GC0310_ID, &gc0310_product_info }, */
};

#endif /* __GC_PRODUCTS_H__ */
