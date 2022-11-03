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

RSA * RSA_DftPrivateKey();
RSA * RSA_DftPublicKey();

RSA *RSA_BuildKey(int bits);

/* 私钥加密, 返回加密后的数据长度 */
int RSA_PrivateEncrypt(IN RSA *pri_key, IN void *in, int in_len, OUT void *out, int out_size);

/* 公钥解密, 返回解密后的数据长度 */
int RSA_PublicDecrypt(IN RSA *pub_key, IN void *in, int in_len, OUT void *out, int out_size);

/* 公钥加密, 返回加密后的数据长度 */
int RSA_PublicEncrypt(IN RSA *pub_key, IN void *in, int in_len, OUT void *out, int out_size);

/* 私钥解密, 返回解密后的数据长度 */
int RSA_PrivateDecrypt(IN RSA *pri_key, IN void *in, int in_len, OUT void *out, int out_size);

#ifdef __cplusplus
}
#endif
#endif //RSA_UTL_H_
