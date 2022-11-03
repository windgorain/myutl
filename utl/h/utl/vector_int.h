#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include <stdbool.h>
#include "utl/vector_utl.h"

#define DEFAULT_VECTOR_INT_SIZE 16
#define DEFAULT_VECTOR_FACTOR_SIZE 32

typedef VECTOR_S * VECTOR_INT_HDL; 

static inline VECTOR_INT_HDL VectorInt_Create(int32_t isize)
{
    VECTOR_PARAM_S p = {0};

    p.ele_size = sizeof(int);
    p.init_size = isize ? isize : DEFAULT_VECTOR_INT_SIZE;
    p.resize_factor = DEFAULT_VECTOR_FACTOR_SIZE;

    return VECTOR_Create(&p);
}

static inline void VectorInt_Destroy(VECTOR_INT_HDL vec)
{
    VECTOR_Destroy(vec);
    return;
}

static inline BOOL_T VectorInt_Append(VECTOR_INT_HDL vec, int val)
{
    int ret = VECTOR_Add(vec, &val);
    return (ret == BS_OK) ? TRUE: FALSE;
}

static inline int VectorInt_Get(VECTOR_INT_HDL vec, int pos)
{
    int val = 0;
    VECTOR_Copy(vec, pos, &val);
    return val;
}

BOOL_T VectorInt_IsExist(VECTOR_INT_HDL vec, int val);
void VectorInt_Sort(VECTOR_INT_HDL vec);
int VectorInt_DelByVal(VECTOR_INT_HDL vec, int32_t val);

#endif
