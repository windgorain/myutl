#ifndef __VECTOR_STR_H__
#define __VECTOR_STR_H__
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utl/vector_utl.h"

#define DEFAULT_VECTOR_STRING_CAPACITY  16
#define DEFAULT_VECTOR_STRING_EXPAND_FACTOR  16

typedef VECTOR_S * VECTOR_STR_HDL;

static inline VECTOR_STR_HDL VectorStr_Create(int isize, int esize)
{   
    VECTOR_PARAM_S p = {0};

    p.ele_size = esize;
    p.init_size = (isize != 0) ? isize: DEFAULT_VECTOR_STRING_CAPACITY;
    p.resize_factor = DEFAULT_VECTOR_STRING_EXPAND_FACTOR;

    return VECTOR_Create(&p);
}

static inline void VectorStr_Destroy(VECTOR_STR_HDL sa)
{
    VECTOR_Destroy(sa);
}

static inline UINT VectorStr_Count(VECTOR_STR_HDL sa)
{
    return VECTOR_Count(sa);
}

static inline char * VectorStr_Get(VECTOR_STR_HDL sa, UINT pos)
{
    return VECTOR_Get(sa, pos);
}

static inline bool VectorStr_Append(VECTOR_STR_HDL sa, char *new_str)
{
    if (! new_str) {
        return FALSE;
    }

    if (VECTOR_AddBySize(sa, new_str, strlen(new_str)+1) != 0) {
        return FALSE;
    }

    return TRUE;
}


#endif
