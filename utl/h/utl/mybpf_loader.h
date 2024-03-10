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
#include "utl/mybpf_loader_def.h"
#include "utl/mybpf_prog_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

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
    UMAP_HEADER_S *maps[MYBPF_LOADER_MAX_MAPS];
    int global_data_count; 
    void *global_data[ELF_MAX_GLOBAL_DATA_SEC_NUM]; 
    void *main_progs[MYBPF_LOADER_MAX_PROGS];
    int progs_count;
    int insts_mem_len; 
    int insts_len; 
    ELF_PROG_INFO_S *progs; 
    void *insts_mem; 
    void *insts; 
    MYBPF_AOT_PROG_CTX_S aot_ctx; 
}MYBPF_LOADER_NODE_S;

int MYBPF_LoaderLoad(MYBPF_RUNTIME_S *runtime, MYBPF_LOADER_PARAM_S *p);
int MYBPF_AttachAuto(MYBPF_RUNTIME_S *runtime, char *instance);
void MYBPF_LoaderUnload(MYBPF_RUNTIME_S *runtime, char *instance);
void MYBPF_LoaderUnloadAll(MYBPF_RUNTIME_S *runtime);
MYBPF_LOADER_NODE_S * MYBPF_LoaderGet(MYBPF_RUNTIME_S *runtime, char *instance);
MYBPF_LOADER_NODE_S * MYBPF_LoaderGetNext(MYBPF_RUNTIME_S *runtime, INOUT void **iter);
void MYBPF_LoaderShowMaps(MYBPF_RUNTIME_S *r, PF_PRINT_FUNC print_func);
UINT64 MYBPF_CallAgent(UINT64 p1, UINT64 p2, UINT64 p3, UINT64 p4, UINT64 p5, UINT64 fid, void *ud);

#ifdef __cplusplus
}
#endif
#endif 
