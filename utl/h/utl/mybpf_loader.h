/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _MYBPF_LOADER_H
#define _MYBPF_LOADER_H

#include "utl/file_utl.h"
#include "utl/elf_utl.h"
#include "utl/umap_utl.h"
#include "utl/mybpf_runtime.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define MYBPF_LOADER_FLAG_AUTO_ATTACH 0x1  
#define MYBPF_LOADER_FLAG_KEEP_MAP    0x2  
#define MYBPF_LOADER_FLAG_JIT         0x4  

typedef struct {
    char *instance; 
    char *filename; 
    FILE_MEM_S *simple_mem;
    UINT flag;
}MYBPF_LOADER_PARAM_S;

#define MYBPF_LOADER_MAX_MAPS 32
#define MYBPF_LOADER_MAX_PROGS 32

typedef struct {
    MYBPF_LOADER_PARAM_S param;
    MAP_LINK_NODE_S link_node;
    RCU_NODE_S rcu;
    void *runtime;
    UINT jitted: 1;
    UINT reserved: 7;
    UINT main_prog_count: 8;
    UINT map_count: 8;
    int map_def_size;
    int map_fds[MYBPF_LOADER_MAX_MAPS];
    UMAP_HEADER_S *maps[MYBPF_LOADER_MAX_MAPS];
    int global_data_count; 
    void *global_data[ELF_MAX_GLOBAL_DATA_SEC_NUM]; 
    int main_prog_fd[MYBPF_LOADER_MAX_PROGS];
    int progs_count;
    int insts_len; 
    ELF_PROG_INFO_S *progs; 
    void *insts; 
}MYBPF_LOADER_NODE_S;

int MYBPF_LoaderLoad(MYBPF_RUNTIME_S *runtime, MYBPF_LOADER_PARAM_S *p);
int MYBPF_AttachAuto(MYBPF_RUNTIME_S *runtime, char *instance);
void MYBPF_LoaderUnload(MYBPF_RUNTIME_S *runtime, char *instance);
void MYBPF_LoaderUnloadAll(MYBPF_RUNTIME_S *runtime);
MYBPF_LOADER_NODE_S * MYBPF_LoaderGet(MYBPF_RUNTIME_S *runtime, char *instance);
MYBPF_LOADER_NODE_S * MYBPF_LoaderGetNext(MYBPF_RUNTIME_S *runtime, INOUT void **iter);

#ifdef __cplusplus
}
#endif
#endif 