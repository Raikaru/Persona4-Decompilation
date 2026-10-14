/* Translation unit brp_param.c (P3 twin src/Main/Battle/Result/brp_param.c). 0x38F590-0x38F5F0 are the HIGH-tier audit group; 0x38F600 is a census inferred_tu row. */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);
extern u8 *D_007246AC;

// FUN_0038F590
void func_0038f590(u8 *allocation)
{
    jtbl_008873EC[0](allocation);
}

// FUN_0038F5C0
u32 func_0038f5c0(const u32 *work, u32 index)
{
    return *(const u32 *)(index * sizeof(u32) + work[2]);
}

// FUN_0038F5E0
u32 func_0038f5e0(const u32 *work)
{
    return work[4];
}

// FUN_0038F5F0
u32 func_0038f5f0(const u32 *work)
{
    return work[1];
}

// FUN_0038F600
void func_0038f600(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}
