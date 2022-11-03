/*================================================================
*   Created by LiXingang
*   Description: 内存帽, 用于封装用户设置的内存管理函数
*                允许mem_cap为NULL，表示使用缺省函数
*
================================================================*/
#ifndef _MEM_CAP_H
#define _MEM_CAP_H
#ifdef __cplusplus
extern "C"
{
#endif

typedef void * (*PF_MemCap_Malloc)(int size, char *file, int line);
typedef void   (*PF_MemCap_Free)(void *buf);

typedef struct {
    PF_MemCap_Malloc cap_malloc;
    PF_MemCap_Free  cap_free;
}MEM_CAP_S;

static inline void * memcap_defaule_alloc(int size, char *file, int line)
{
    return mem_Malloc(size, file, line);
}

static inline void memcap_defaule_free(void *buf, char *file, int line)
{
    mem_Free(buf, file, line);
}

static inline int MemCap_Init(MEM_CAP_S *mem_cap, PF_MemCap_Malloc cap_malloc, PF_MemCap_Free cap_free)
{
    mem_cap->cap_malloc = cap_malloc;
    mem_cap->cap_free = cap_free;
    return 0;
}

static inline void * _MemCap_Malloc(MEM_CAP_S *mem_cap, int size, char *file, int line)
{
    if ((! mem_cap) || (! mem_cap->cap_malloc)) {
        return memcap_defaule_alloc(size, file, line);
    }

    return mem_cap->cap_malloc(size, file, line);
}

#define MemCap_Malloc(memcap, size) _MemCap_Malloc(memcap, size, __FILE__, __LINE__)

static inline void _MemCap_Free(MEM_CAP_S *mem_cap, void *buf, char *file, int line)
{
    if ((! mem_cap) || (! mem_cap->cap_free)) {
        return memcap_defaule_free(buf, file, line);
    }

    return mem_cap->cap_free(buf);
}

#define MemCap_Free(memcap, buf) _MemCap_Free(memcap, buf, __FILE__, __LINE__)

static inline void * _MemCap_ZMalloc(MEM_CAP_S *mem_cap, int size, char *file, int line)
{
    void *buf = _MemCap_Malloc(mem_cap, size, file, line);

    if (buf) {
        memset(buf, 0, size);
    }

    return buf;
}

#define MemCap_ZMalloc(memcap, size) _MemCap_ZMalloc(memcap, size, __FILE__, __LINE__)

static inline void * MemCap_Dup(MEM_CAP_S *mem_cap, void *data, int len)
{
    void *buf = MemCap_Malloc(mem_cap, len);
    if (buf) {
        memcpy(buf, data, len);
    }
    return buf;
}

#ifdef __cplusplus
}
#endif
#endif //MEM_CAP_H_
