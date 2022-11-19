/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      lixingang  Version: 1.0  Date: 2007-2-11
* Description: 
* History:     
******************************************************************************/

#ifndef __HEAD_H_
#define __HEAD_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "baseos.h"
#include "types.h"

/*define*/

typedef enum
{
    BS_NO_WAIT = 0,
    BS_WAIT
}BS_WAIT_E;

#define BS_WAIT_FOREVER	0

#define BS_OFFSET(type,item) ((ULONG)&(((type *) 0)->item))
#define BS_ENTRY(pAddr, item, type) ((type *) ((UCHAR*)(pAddr) - BS_OFFSET (type, item)))

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifndef container_of
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })
#endif

#define BS_PRINT_ERR(...) fprintf(stderr, __VA_ARGS__)

#ifdef IN_DEBUG
#define BS_DBGASSERT(X)  do { \
    if (! (X)) { \
        BackTrace_Print(); \
        assert(0); \
    } \
} while(0)
#else
#define BS_DBGASSERT(X)
#endif

#define DBGASSERT(X) BS_DBGASSERT(X)

#define BS_DBG_OUTPUT(_ulFlag,_ulSwitch,_X)  \
    do {if ((_ulFlag) & (_ulSwitch)){IC_DbgInfo _X;}}while(0)

#define BS_WARNNING(X)  \
    do {    \
        printf("Warnning:%s(%d):\r\n ", __FILE__, __LINE__); \
        printf X;   \
        printf ("\r\n");    \
    }while(0)

#ifdef IN_DEBUG
#define BS_DBG_WARNNING(X) BS_WARNNING(X)
#else
#define BS_DBG_WARNNING(X)
#endif

typedef struct
{
    HANDLE ahUserHandle[4];
}USER_HANDLE_S;

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__HEAD_H_*/


