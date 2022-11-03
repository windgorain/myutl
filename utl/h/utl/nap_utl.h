/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2014-11-16
* Description: node id pool
* History:     
******************************************************************************/

#ifndef __NAP_UTL_H_
#define __NAP_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define NAP_INVALID_ID    0 /* 无效ID */
#define NAP_INVALID_INDEX ((UINT)-1)/* 无效index */

typedef VOID* NAP_HANDLE;

typedef enum
{
    NAP_TYPE_ARRAY = 0,   /* 节点数组. 所有节点是预先申请好的, 不支持动态个数, 不支持RCU */
    NAP_TYPE_PTR_ARRAY,   /* 指针数组, 不支持动态个数 */
    NAP_TYPE_HASH,        /* Hash, 支持动态个数, 允许MaxNum设置为0 */
    NAP_TYPE_AVL,         /* AVL, 支持动态个数, 允许MaxNum设置为0 */
}NAP_TYPE_E;

typedef struct {
    void *memcap;    /* NULL表示使用默认内存申请释放函数 */
    NAP_TYPE_E enType;
    UINT uiMaxNum;   /* 0表示动态,数组类型不支持0 */
    UINT uiNodeSize;
}NAP_PARAM_S;

NAP_HANDLE NAP_Create(NAP_PARAM_S *p);

/* 序列号,会在每次申请节点时进行变化 */
BS_STATUS NAP_EnableSeq
(
    IN HANDLE hNAPHandle,
    IN UINT   ulSeqMask, /* 0表示自动计算Seq, 只在低32位内进行自动计算 */
    IN UINT   uiSeqCount /* 创建多少个序列数 */
);
UINT NAP_GetNodeSize(IN NAP_HANDLE hNapHandle);
/* 申请一个Node */
VOID * NAP_Alloc(IN NAP_HANDLE hNapHandle);
VOID * NAP_ZAlloc(IN NAP_HANDLE hNapHandle);
/* 申请一个特定Index的Node, 如果已经被占用了，则返回NULL.
   如果Index为INVALID,则表示忽略此参数,按非spec方式申请 */
VOID * NAP_AllocByIndex(NAP_HANDLE hNapHandle, UINT uiSpecIndex);
VOID * NAP_ZAllocByIndex(IN NAP_HANDLE hNapHandle, IN UINT uiSpecIndex);
/* 申请一个特定ID 的Node, 如果已经被占用了，则返回NULL. 如果ID为INVALID,
   则表示忽略此参数,按非NAP_Alloc方式申请 */
VOID * NAP_AllocByID(IN NAP_HANDLE hNapHandle, IN UINT ulSpecID);
VOID * NAP_ZAllocByID(IN NAP_HANDLE hNapHandle, IN UINT ulSpecID);
VOID NAP_Free(IN NAP_HANDLE hNapHandle, IN VOID *pstNode);
VOID NAP_FreeByID(IN NAP_HANDLE hNapHandle, IN UINT ulID);
VOID NAP_FreeByIndex(IN NAP_HANDLE hNapHandle, IN UINT index);
VOID NAP_FreeAll(IN NAP_HANDLE hNapHandle);
VOID * NAP_GetNodeByID(IN NAP_HANDLE hNAPHandle, IN UINT ulID);
VOID * NAP_GetNodeByIndex(IN NAP_HANDLE hNAPHandle, IN UINT uiIndex);
UINT NAP_GetIDByNode(IN NAP_HANDLE hNAPHandle, IN VOID *pstNode);
UINT NAP_GetIDByIndex(IN NAP_HANDLE hNAPHandle, UINT index);
UINT NAP_GetIndexByID(IN NAP_HANDLE hNAPHandle, UINT id);
UINT NAP_GetIndexByID(IN NAP_HANDLE hNAPHandle, UINT id);
VOID NAP_Destory(IN NAP_HANDLE hNAPHandle);
void * NAP_GetMemCap(NAP_HANDLE hNAPHandle);
/* 相比于NAP_GetNextID, 其性能会更高 */
UINT NAP_GetNextIndex(IN NAP_HANDLE hNAPHandle, IN UINT uiCurrentIndex);
UINT NAP_GetNextID(IN NAP_HANDLE hNAPHandle, IN UINT ulCurrentID);
UINT NAP_GetCount(IN NAP_HANDLE hNAPHandle);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__NAP_UTL_H_*/


