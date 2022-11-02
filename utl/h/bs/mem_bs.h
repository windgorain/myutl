/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      lixingang  Version: 1.0  Date: 2007-2-2
* Description: 
* History:     
******************************************************************************/

#ifndef __MEM_H_
#define __MEM_H_

#include "types.h"
#include <memory.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

PLUG_API void * MEM_MallocMem(ULONG ulSize, CHAR *pszFileName, UINT ulLine);
PLUG_API VOID MEM_FreeMem(IN VOID *pMem, IN CHAR *pszFileName, IN UINT ulLine);

BS_STATUS MEM_ShowStat(IN UINT ulArgc, IN CHAR **argv);
BS_STATUS MEM_ShowSizeOfMemStat(int argc, char **argv);

int MemDebug_Check(int argc, char **argv);
BS_STATUS MemDebug_ShowSizeOfMem(int argc, char **argv);
BS_STATUS MemDebug_ShowLineConflict(int argc, char **argv);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__MEM_H_*/


