/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _DSA_UTL_H
#define _DSA_UTL_H
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/err.h>
#ifdef __cplusplus
extern "C"
{
#endif

DSA * DSA_BuildKey(int bits);


#ifdef __cplusplus
}
#endif
#endif //DSA_UTL_H_
