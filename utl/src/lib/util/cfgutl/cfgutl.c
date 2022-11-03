/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-4-23
* Description: 
* History:     
******************************************************************************/
/* retcode所需要的宏 */
#define RETCODE_FILE_NUM RETCODE_FILE_NUM_CFGUTL

#include "bs.h"

#include "utl/txt_utl.h"
#include "utl/file_utl.h"
#include "utl/cfgutl.h"

#define _CFGUTL_MAX_KEY_NUM 255   /* 一行最大的单词数目 */

VOID _CFGUTL_ParseLine(IN CHAR *pszLine, IN CFGUTL_REG_TBL_S *pstRegTbl, IN UINT ulTblSize)
{
    CHAR       *paargz[_CFGUTL_MAX_KEY_NUM];
    UINT      ulKeyNum;
    UINT i;

    ulKeyNum = TXT_StrToToken(pszLine, " \t", paargz, _CFGUTL_MAX_KEY_NUM);
    if (ulKeyNum == 0)
    {
        return;
    }

    for (i=0; i<ulTblSize; i++)
    {
        if (strcmp(pstRegTbl[i].pszCmd, paargz[0]) != 0)
        {
            continue;
        }

        pstRegTbl[i].pfFunc(ulKeyNum, paargz, pstRegTbl[i].ulUsrHandle);
        break;
    }

    return;
}

VOID CFGUTL_Open(IN CHAR *pszFileName, IN CFGUTL_REG_TBL_S *pstRegTbl, IN UINT ulTblSize)
{
    CHAR       *pucLineHead = NULL;
    UINT      ulLineLen;
    FILE_MEM_S *pstMemMap;

    BS_DBGASSERT(NULL != pszFileName);
    BS_DBGASSERT(NULL != pstRegTbl);

    pstMemMap = FILE_Mem(pszFileName);
    if (NULL == pstMemMap)
    {
        return;
    }
    
    TXT_StrimAndMove((CHAR*)pstMemMap->pucFileData);

    TXT_SCAN_LINE_BEGIN((CHAR*)pstMemMap->pucFileData,pucLineHead,ulLineLen)
    {
        pucLineHead[ulLineLen] = '\0';
        TXT_StrimAndMove(pucLineHead);

        if (strlen(pucLineHead) != 0)
        {
            _CFGUTL_ParseLine(pucLineHead, pstRegTbl, ulTblSize);
        }
    }TXT_SCAN_LINE_END();

    FILE_MemFree(pstMemMap);

    return;
}

