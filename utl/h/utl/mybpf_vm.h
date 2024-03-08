/*================================================================
*   Created by LiXingang, Copyright LiXingang
*   Description: 
*
================================================================*/
#ifndef _MYBPF_VM_H
#define _MYBPF_VM_H

#include "utl/bpf_helper_utl.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    int tail_call_index;
    PF_PRINT_FUNC print_func;
}MYBPF_VM_S;

typedef struct {
    uint64_t bpf_ret;
    void *start_addr; 
    void *mybpf_prog; 
    void *insts; 
    void *mem;        
    uint32_t mem_len; 
    uint32_t mem_check: 1; 
    uint32_t auto_stack: 1; 
    uint32_t helper_fixed: 1; 
    int stack_size;
    char *stack;
}MYBPF_CTX_S;

int MYBPF_SetTailCallIndex(MYBPF_VM_S *vm, unsigned int idx);
BOOL_T MYBPF_Validate(MYBPF_VM_S *vm, void *insn, UINT num_insts);
int MYBPF_Run(MYBPF_VM_S *vm, MYBPF_CTX_S *ctx, UINT64 p1, UINT64 p2, UINT64 p3, UINT64 p4, UINT64 p5);
int MYBPF_RunP3(MYBPF_VM_S *vm, MYBPF_CTX_S *ctx, UINT64 p1, UINT64 p2, UINT64 p3);


int MYBPF_DefultRun(MYBPF_CTX_S *ctx, U64 r1, U64 r2, U64 r3, U64 r4, U64 r5);

int MYBPF_DefultRunCode(void *code, OUT UINT64 *bpf_ret, U64 r1, U64 r2, U64 r3, U64 r4, U64 r5);

#ifdef __cplusplus
}
#endif
#endif 
