/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2009-4-3
* Description: 
* History:     
******************************************************************************/

#ifndef __RAND_UTL_H_
#define __RAND_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif 

UINT RAND_Get(void);

UINT RAND_GetNonZero(void);


unsigned long RAND_GetRandom(void);


VOID RAND_Entropy(IN UINT uiEntropy);


void RAND_Mem(OUT UCHAR *buf, int len);

static inline UINT RAND_FastGet(UINT *seedp)
{
	*seedp ^= (*seedp << 13);
	*seedp ^= (*seedp >> 17);
	*seedp ^= (*seedp << 5);
	return *seedp;
}

#ifdef __cplusplus
    }
#endif 

#endif 


