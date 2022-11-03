/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-18
* Description: 
* History:     
******************************************************************************/

#ifndef __DES_UTL_H_
#define __DES_UTL_H_

#include "openssl/des.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define DES_CIPHER_LEN(ulClearLen) NUM_UP_ALIGN(ulClearLen, 8)
#define DES_CIPHER_PAD_LEN(ulClearLen) (((ulClearLen) & 0x7) == 0 ? 0: (8 - ((ulClearLen) & 0x7)))

typedef unsigned char DES_cblock[8];
typedef /* const */ unsigned char const_DES_cblock[8];

extern void DES_Ecb_encrypt
(
    IN const_DES_cblock *input,
    OUT DES_cblock *output,
    IN DES_key_schedule *ks,
    IN int enc
);
extern void DES_Ecb3Encrypt
(
    IN DES_cblock *pstInput,
    IN DES_cblock *pstOutput,
    IN DES_key_schedule *pstKs1, 
    IN DES_key_schedule *pstKs2,
    IN DES_key_schedule *pstKs3,
    IN BOOL_T bIsEnc
);
extern void DES_Ede3CbcEncrypt
(
    IN UCHAR *pucInput,
    OUT UCHAR *pucOutput,
    INT lLength,
    DES_key_schedule *pstKs1,
    DES_key_schedule *pstKs2,
    DES_key_schedule *pstKs3,
    DES_cblock *pstIvec,
    BOOL_T bIsEnc
);
extern void DES_Ede3Cfb64Encrypt
(
    IN UCHAR *pucIn,
    OUT UCHAR *pucOut,
    IN long lLength, 
    IN DES_key_schedule *pstKs1,
    IN DES_key_schedule *pstKs2,
    IN DES_key_schedule *pstKs3, 
    INOUT DES_cblock *pstIvec,
	INOUT INT *plNum, 
	IN BOOL_T bIsEnc
);

extern void DES_Ede3CfbEncrypt
(
    IN UCHAR *pucIn,
    OUT UCHAR *pucOut,
    IN INT lNumbits,
    IN long lLength, 
    IN DES_key_schedule *pstKs1,
    IN DES_key_schedule *pstKs2,
    IN DES_key_schedule *pstKs3, 
    INOUT DES_cblock *pstIvec,
	IN BOOL_T bIsEnc
);

extern void DES_Ede3Ofb64Encrypt
(
    IN UCHAR *pucIn,
    OUT UCHAR *pucOut,
    IN long lLength, 
    IN DES_key_schedule *pstKs1,
    IN DES_key_schedule *pstKs2,
    IN DES_key_schedule *pstKs3, 
    INOUT DES_cblock *pstIvec,
    INOUT INT *plNum
);

DES_key_schedule * DES_GetSysKey1();
DES_key_schedule * DES_GetSysKey2();
DES_key_schedule * DES_GetSysKey3();

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__DES_UTL_H_*/


