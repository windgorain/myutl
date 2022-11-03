/******************************************************************************
* Copyright (C), 2000-2006,  Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2017-6-3
* Description: 
* History:     
******************************************************************************/

#ifndef __MAP_UTL_H_
#define __MAP_UTL_H_

#include "bs.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define MAP_FLAG_DUP_KEY 0x1

typedef struct tagMAP_CTRL_S * MAP_HANDLE;

typedef struct
{
    VOID *pKey;
    VOID *pData;
    UINT uiKeyLen;
    UINT dup_key: 1; /* key是mem_dup出来的 */
}MAP_ELE_S;

typedef struct {
    void *memcap;
    UINT bucket_num; /* used for hash map */
}MAP_PARAM_S;

typedef BS_WALK_RET_E (*PF_MAP_WALK_FUNC)(IN MAP_ELE_S *pstEle, IN VOID *pUserHandle);
typedef void (*PF_MAP_FREE_FUNC)(void *data, void *ud);

typedef void (*PF_MAP_Destroy)(MAP_HANDLE map, PF_MAP_FREE_FUNC free_func, void *ud);
typedef void (*PF_MAP_Reset)(MAP_HANDLE map, PF_MAP_FREE_FUNC free_func, void *ud);
typedef int (*PF_MAP_Add)(MAP_HANDLE map, VOID *pKey, UINT uiKeyLen, VOID *pData, UINT flag);
typedef MAP_ELE_S* (*PF_MAP_GetEle)(MAP_HANDLE map, void *key, UINT key_len);
typedef void* (*PF_MAP_Get)(MAP_HANDLE map, void *pKey, UINT uiKeyLen);
typedef void* (*PF_MAP_Del)(IN MAP_HANDLE map, IN VOID *pKey, IN UINT uiKeyLen);
typedef void (*PF_MAP_DelAll)(MAP_HANDLE map, PF_MAP_FREE_FUNC func, void * pUserData);
typedef UINT (*PF_MAP_Count)(MAP_HANDLE map);
typedef void (*PF_MAP_Walk)(IN MAP_HANDLE map, IN PF_MAP_WALK_FUNC pfWalkFunc, IN VOID *pUserData);
typedef MAP_ELE_S* (*PF_MAP_GetNext)(MAP_HANDLE map, MAP_ELE_S *pstCurrent);

typedef struct {
    PF_MAP_Destroy destroy_func;
    PF_MAP_Reset reset_func;
    PF_MAP_Add add_func;
    PF_MAP_GetEle get_ele_func;
    PF_MAP_Get get_func;
    PF_MAP_Del del_func;
    PF_MAP_DelAll del_all_func;
    PF_MAP_Count count_func;
    PF_MAP_Walk walk_func;
    PF_MAP_GetNext getnext_func;
}MAP_FUNC_S;

typedef struct tagMAP_CTRL_S{
    MAP_FUNC_S *funcs;
    void *memcap;
    void *impl_map;
    UINT uiCapacity;
}MAP_CTRL_S;

/* Hash Map */
MAP_HANDLE MAP_HashCreate(MAP_PARAM_S *p);
void MAP_HashSetResizeWatter(MAP_HANDLE map, UINT high_watter_percent, UINT low_watter_percent);
/* AVL Map */
MAP_HANDLE MAP_AvlCreate(void *memcap /* 可以为NULL */);
/* Red Black Tree Map */
MAP_HANDLE MAP_RBTreeCreate(void *memcap /* 可以为NULL */);
/* List Map */
MAP_HANDLE MAP_ListCreate(void *memcap /* 可以为NULL */);

static inline void MAP_Destroy(MAP_HANDLE map, PF_MAP_FREE_FUNC free_func, void *ud) {
    map->funcs->destroy_func(map, free_func, ud);
}

static inline void MAP_Reset(MAP_HANDLE map, PF_MAP_FREE_FUNC free_func, void *ud) {
    map->funcs->reset_func(map, free_func, ud);
}

static inline void MAP_SetCapacity(MAP_HANDLE map, UINT capacity) {
    map->uiCapacity = capacity;
}

static inline UINT MAP_GetCapacity(MAP_HANDLE map) {
    return map->uiCapacity;
}

/* pKey当做指针来用,则keylen为指针指向内容的长度; pKey当做数字来用,则keylen填写为0 */
static inline int MAP_Add(MAP_HANDLE map, VOID *pKey, UINT uiKeyLen, VOID *pData, UINT flag) {
    return map->funcs->add_func(map, pKey, uiKeyLen, pData, flag);
}

static inline MAP_ELE_S * MAP_GetEle(MAP_HANDLE map, void *key, UINT key_len) {
    return map->funcs->get_ele_func(map, key, key_len);
}

static inline BOOL_T MAP_IsExist(MAP_HANDLE map, void *key, UINT key_len) {
    if (MAP_GetEle(map, key, key_len)) {
        return TRUE;
    }
    return FALSE;
}

static inline void * MAP_Get(MAP_HANDLE map, void *pKey, UINT uiKeyLen) {
    return map->funcs->get_func(map, pKey, uiKeyLen);
}

/* 从集合中删除并返回pData */
static inline void * MAP_Del(IN MAP_HANDLE map, IN VOID *pKey, IN UINT uiKeyLen) {
    return map->funcs->del_func(map, pKey, uiKeyLen);
}

static inline void MAP_DelAll(MAP_HANDLE map, PF_MAP_FREE_FUNC func, void * pUserData) {
    map->funcs->del_all_func(map, func, pUserData);
}

static inline UINT MAP_Count(MAP_HANDLE map) {
    return map->funcs->count_func(map);
}

static inline void MAP_Walk(IN MAP_HANDLE map, IN PF_MAP_WALK_FUNC pfWalkFunc, IN VOID *pUserData) {
    map->funcs->walk_func(map, pfWalkFunc, pUserData);
}
 /* pstCurrent如果为NULL表示获取第一个. 只关心其中的pKye和uiKeyLen字段 */
static inline MAP_ELE_S * MAP_GetNext(MAP_HANDLE map, MAP_ELE_S *pstCurrent) {
    return map->funcs->getnext_func(map, pstCurrent);
}

static inline int MAP_AddStringKey(MAP_HANDLE map, char *key, void *pData, UINT flag)
{
    return MAP_Add(map, key, strlen(key), pData, flag);
}

static inline void * MAP_GetStringKey(MAP_HANDLE map, char *key)
{
    return MAP_Get(map, key, strlen(key));
}

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__MAP_UTL_H_*/

