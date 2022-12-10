/*================================================================
*   Created by LiXingang: 2018.12.11
*   Description: 
*
================================================================*/
#ifndef _RSA_UTL_H
#define _RSA_UTL_H

#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/err.h>

#ifdef __cplusplus
extern "C"
{
#endif

EVP_PKEY * RSA_DftPrivateKey();
EVP_PKEY * RSA_DftPublicKey();

EVP_PKEY * EVP_BuildKey(int type, UINT bits);
EVP_PKEY * RSA_BuildKey(UINT bits);
EVP_PKEY * DSA_BuildKey(UINT bits);
EVP_PKEY * EC_BuildKey(UINT bits);

/* 非对称加密, 返回加密后的数据长度 */
int RSA_Encrypt(IN EVP_PKEY *key, IN void *in, int in_len, OUT void *out, int out_size);
/* 非对称解密, 返回解密后的数据长度 */
int RSA_Decrypt(IN EVP_PKEY *key, IN void *in, int in_len, OUT void *out, int out_size);

#ifdef __cplusplus
}
#endif
#endif //RSA_UTL_H_
