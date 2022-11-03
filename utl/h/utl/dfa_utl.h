/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2014-10-9
* Description: 
* History:     
******************************************************************************/

#ifndef __DFA_UTL_H_
#define __DFA_UTL_H_

#include "utl/action_utl.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define DFA_DBG_FLAG_PROCESS 0x1

typedef struct tagDFA_NODE_S
{
    UINT uiCode;
    UINT uiNextState;  /* state是从0开始的连续数字 */
    CHAR *pcActions;
    ACTION_INDEX_S stActionIndex;
}DFA_NODE_S;

#define DFA_NODE(_uiCode,_uiNextState,_pcActions) \
    {(UINT)(_uiCode),(_uiNextState),(_pcActions),{{ACTION_INDEX_INVALID}}}

typedef struct
{
    DFA_NODE_S *pstDfaNode;
    UINT uiDfaNodeNum;
}DFA_TBL_LINE_S;

typedef struct
{
    UINT uiDbgFlag;
    UINT uiCurrentState;
    UINT uiOldState;
    UINT uiInputCode;
    DFA_TBL_LINE_S *pstDfaLines;
    ACTION_S *pstActions;
    VOID *pUserData;  /* 用户存在DFA中的私有数据 */
}DFA_S;

typedef void *DFA_HANDLE; /* DFA_S * */

#define DFA_TBL_LINE(_astDfaNode) {(_astDfaNode), sizeof(_astDfaNode)/sizeof(DFA_NODE_S)}
#define DFA_TBL_END {NULL, 0}


/* 正常字符 0 - 255 */
#define DFA_CODE_CHAR(_X) (_X)
#define DFA_CODE_CHAR_MAX  255

/* 控制字符 0x100 - 0x1ff */
#define DFA_CODE_EDGE   0x100   /* 遇到不连续缓冲的结束边界 */
#define DFA_CODE_END    0x101   /* 结束 */
#define DFA_CODE_MAX    0x1ff

/* 字符模式 0x200-0x2ff */
#define DFA_CODE_LWS    0x200 /* 空白字符 */
#define DFA_CODE_ALPHA  0x201 /* A-Z a-z */
#define DFA_CODE_NUMBER 0x202 /* 0-9 */
#define DFA_CODE_WORD   0x203 /* 字母数字下划线 */
#define DFA_CODE_HEX    0x204 /* 16进制字母 */
#define DFA_CODE_OTHER  0x205 /* 其他字符0-255 */


#define DFA_STATE_SELF  65535 /* 状态不变 */
#define DFA_STATE_BACK  65534 /* 回退到上一个状态 */

VOID DFA_Compile(DFA_TBL_LINE_S *pstDfaLines, ACTION_S *pstActions);
void DFA_Init(DFA_S *dfa, DFA_TBL_LINE_S *pstDfaLines, ACTION_S *pstActions, UINT uiInitState);
DFA_HANDLE DFA_Create(DFA_TBL_LINE_S *pstDfaLines, ACTION_S *pstActions, UINT uiInitState);
VOID DFA_Destory(IN DFA_HANDLE hDfa);
VOID DFA_SetDbgFlag(IN DFA_HANDLE hDfa, IN UINT uiDbgFlag);
VOID DFA_ClrDbgFlag(IN DFA_HANDLE hDfa, IN UINT uiDbgFlag);
VOID DFA_Input(IN DFA_HANDLE hDfa, IN UINT uiInputCode);
VOID DFA_InputChar(IN DFA_HANDLE hDfa, IN CHAR cInputCode);
VOID DFA_Edge(IN DFA_HANDLE hDfa);
VOID DFA_End(IN DFA_HANDLE hDfa);
VOID DFA_SetState(IN DFA_HANDLE hDfa, IN UINT uiNewState);
UINT DFA_GetInputCode(IN DFA_HANDLE hDfa);
UINT DFA_GetOldState(IN DFA_HANDLE hDfa);
VOID DFA_SetUserData(IN DFA_HANDLE hDfa, IN VOID *pData);
VOID * DFA_GetUserData(IN DFA_HANDLE hDfa);
BOOL_T DFA_IsWord(IN UCHAR ucInputCode);
BOOL_T DFA_IsLws(IN UCHAR ucInputCode);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__DFA_UTL_H_*/


