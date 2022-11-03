/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-10
* Description: 
* History:     
******************************************************************************/

#ifndef __PASSWD_UTL_H_
#define __PASSWD_UTL_H_

#include "utl/md5_utl.h"
#include "utl/des_utl.h"
#include "utl/base64_utl.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#if 1
#define PW_BASE64_CIPHER_LEN(ulClearLen) BASE64_LEN(DES_CIPHER_LEN(((ulClearLen) + 1) + 1))
BS_STATUS PW_Base64Encrypt(IN CHAR *szClearText, OUT CHAR *szCipher, IN ULONG ulCipherSize);
BS_STATUS PW_Base64Decrypt(IN CHAR *szCipher, OUT CHAR *szClearText, IN ULONG ulClearSize);
#endif

#if 1
#define PW_HEX_CIPHER_LEN(ulClearLen) (DES_CIPHER_LEN((ulClearLen) + 1) * 2)
BS_STATUS PW_HexEncrypt(IN CHAR *szClearText, OUT CHAR *szCipher, IN ULONG ulCipherSize);
BS_STATUS PW_HexDecrypt(IN CHAR *szCipher, OUT CHAR *szClearText, IN ULONG ulClearSize);
#endif

#if 1
#define PW_MD5_ENCRYPT_LEN (MD5_LEN * 2)
/* 有损加密 */
BS_STATUS PW_Md5Encrypt(IN CHAR *szClearText, OUT CHAR szCipherText[PW_MD5_ENCRYPT_LEN + 1]);
/* 有损加密的比较 */
BOOL_T PW_Md5Check(IN CHAR *szClearText, IN CHAR *pcCipherText);
#endif

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__PASSWD_UTL_H_*/


