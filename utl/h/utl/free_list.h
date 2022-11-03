/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _FREE_LIST_H
#define _FREE_LIST_H
#include "utl/list_sl.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    SL_HEAD_S free_list;
}FREE_LIST_S;

int FreeList_Init(FREE_LIST_S *list);
void FreeList_Put(FREE_LIST_S *list, void *node);
int FreeList_Puts(FREE_LIST_S *list, void *nodes, UINT node_len,
        UINT max_nodes);
void * FreeList_Get(FREE_LIST_S *list);

#ifdef __cplusplus
}
#endif
#endif //_FREE_LIST_H
