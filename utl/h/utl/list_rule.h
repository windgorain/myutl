/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2016-10-14
* Description: 
* History:     
******************************************************************************/

#ifndef __LIST_RULE_H_
#define __LIST_RULE_H_

#include "utl/rule_list.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

typedef HANDLE LIST_RULE_HANDLE;

typedef struct
{
    NAP_HANDLE hListNap;
    void *memcap;
}LIST_RULE_CTRL_S;

typedef struct
{
    CHAR *pcListName;
    UINT uiRefCount;
    BS_ACTION_E default_action;
    RULE_LIST_S stRuleList;
}LIST_RULE_LIST_S;

typedef struct
{
    LIST_RULE_LIST_S *pstListRule;
}LIST_RULE_HEAD_S;

BS_STATUS ListRule_Init(INOUT LIST_RULE_CTRL_S *pstCtx, void *memcap);
void ListRule_Finit(INOUT LIST_RULE_CTRL_S *pstCtx, PF_RULE_FREE pfFunc, VOID *pUserHandle);

LIST_RULE_HANDLE ListRule_Create(void *memcap);
VOID ListRule_Destroy(IN LIST_RULE_HANDLE hListRule, IN PF_RULE_FREE pfFunc, IN VOID *pUserHandle);
void ListRule_Reset(IN LIST_RULE_HANDLE hListRule, IN PF_RULE_FREE pfFunc, IN VOID *pUserHandle);

LIST_RULE_LIST_S *ListRule_CreateList(IN LIST_RULE_HANDLE hListRule, IN CHAR *pcListName);
VOID ListRule_DestroyList(IN LIST_RULE_HANDLE hListRule, LIST_RULE_LIST_S *pstList, IN PF_RULE_FREE pfFunc, IN VOID *pUserHandle);
UINT ListRule_AddList(IN LIST_RULE_HANDLE hListRule, IN CHAR *pcListName);
VOID ListRule_DelList
(
    IN LIST_RULE_HANDLE hListRule,
    IN UINT uiListID,
    IN PF_RULE_FREE pfFunc,
    IN VOID *pUserHandle
);
BS_STATUS ListRule_ReplaceList(IN LIST_RULE_HANDLE hListRule, 
                               IN UINT uiListID, IN PF_RULE_FREE pfFunc, IN VOID *pUserHandle, 
                               IN LIST_RULE_LIST_S *pstListNew);

/* 增加List的引用计数 */
BS_STATUS ListRule_AddListRef(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID);
/* 减少List的引用计数 */
BS_STATUS ListRule_DelListRef(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID);
/* 获取List的引用计数 */
UINT ListRule_GetListRef(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID);
BS_ACTION_E ListRule_GetDefaultActionByID(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID);
BS_STATUS ListRule_SetDefaultActionByID(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID, BS_ACTION_E enAciton);
UINT ListRule_GetListIDByName(IN LIST_RULE_HANDLE hListRule, IN CHAR *pcListName);
LIST_RULE_LIST_S* ListRule_GetListByID(IN LIST_RULE_HANDLE hListRule, IN UINT uiListID);
LIST_RULE_LIST_S* ListRule_GetListByName(IN LIST_RULE_HANDLE hListRule, IN CHAR *pcListName);
UINT ListRule_GetNextList(IN LIST_RULE_HANDLE hListRule, IN UINT ulCurrentListID/* 0表示获取第一个 */);
CHAR * ListRule_GetListNameByID(IN LIST_RULE_HANDLE hListRule, IN UINT ulListID);

BS_STATUS ListRule_AddRule2List(LIST_RULE_LIST_S *pstList, IN UINT uiRuleID, IN RULE_NODE_S *pstRule);
BS_STATUS ListRule_AddRule
(
    IN LIST_RULE_HANDLE hCtx,
    IN UINT uiListID,
    IN UINT uiRuleID,
    IN RULE_NODE_S *pstRule
);
RULE_NODE_S * ListRule_DelRule(IN LIST_RULE_HANDLE hCtx, IN UINT uiListID, IN UINT uiRuleID);
RULE_NODE_S * ListRule_GetRule(IN LIST_RULE_HANDLE hCtx, IN UINT uiListID, IN UINT uiRuleID);
RULE_NODE_S *ListRule_GetLastRule(IN LIST_RULE_HANDLE hCtx, IN UINT uiListID);
BS_STATUS ListRule_IncreaseID(IN LIST_RULE_HANDLE hCtx, IN UINT uiListID, IN UINT uiStart, IN UINT uiEnd, IN UINT uiStep);
/* 移动rule */
BS_STATUS ListRule_MoveRule
(
    IN LIST_RULE_HANDLE hCtx,
    IN UINT uiListID,
    IN UINT uiOldRuleID,
    IN UINT uiNewRuleID
);
RULE_NODE_S * ListRule_GetNextRule
(
    IN LIST_RULE_HANDLE hCtx,
    IN UINT uiListID,
    IN UINT uiCurrentRuleID/* RULE_ID_INVALID 表示从头开始 */
);
BS_STATUS ListRule_ResetID(IN LIST_RULE_HANDLE hCtx, IN UINT uiListID, IN UINT uiStep);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__LIST_RULE_H_*/


