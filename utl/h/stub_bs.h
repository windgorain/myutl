/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _STUB_BS_H
#define _STUB_BS_H
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef USE_BS
#define SSHOW_Add _sshow_Add
#define SSHOW_Del _sshow_Del
#else
#define SSHOW_Add(x,f,l)
#define SSHOW_Del(x)
#endif

#ifdef __cplusplus
}
#endif
#endif //STUB_BS_H_
