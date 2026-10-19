/* Translation unit brp_param.c (P3 twin src/Main/Battle/Result/brp_param.c). 0x38F590-0x38F5F0 are the HIGH-tier audit group; 0x38F600 is a census inferred_tu row. */
#include "type.h"
#include "brp_param_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u8 *D_007246AC;

// FUN_0038F590
void brpParamFree(u8 *allocation)
{
    jtbl_008873EC[0](allocation);
}

// FUN_0038F5C0
u32 brpParamGetEntry(const u32 *work, u32 index)
{
    return ((const u32 *)work[2])[index];
}

// FUN_0038F5E0
u32 brpParamReadWord4(const u32 *work)
{
    return work[4];
}

// FUN_0038F5F0
u32 brpParamReadWord1(const u32 *work)
{
    return work[1];
}

// FUN_0038F600
void brpParamSetCurrent(u8 *work)
{
    ((s32 *)work)[0] = 0;
    ((s32 *)work)[1] = 0;
    D_007246AC = work;
}
