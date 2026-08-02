#include "include_asm.h"
#include "type.h"


/* measured: #pragma schedule on is load-bearing -- retail sinks the second
 * sw into the jr return delay slot; O2 alone emits sw/sw/jr/nop (nd 6). */
#pragma schedule on

// FUN_004D12A0
void func_004d12a0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x60) = arg1;
    *(s32 *)(arg0 + 0x3C) = arg1;
}
#pragma schedule off


extern s32 D_00723F10[];

/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_004D18D8 NONMATCHING
#ifdef NON_MATCHING
void func_004d18d8(s32 arg0)
{
    D_00723F10[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d18d8);
#endif
#pragma schedule off


extern s32 D_00723F20[];

/* measured: all void shapes color the address scratch $v1 (nd 2); pointer-
 * return re-materializes (nd 9, 20B > window); opt1/opt3 unchanged. Pure
 * $v0/$v1 swap vs retail = allocator floor (same residual in sibling files
 * code1_004e/code1_0052). NONMATCHING */
#pragma schedule on

// FUN_004D3148 NONMATCHING
#ifdef NON_MATCHING
void func_004d3148(s32 arg0)
{
    D_00723F20[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3148);
#endif
#pragma schedule off


extern s32 D_00723F20[];

/* measured: O2/schedule/opt3/static/const/volatile all reuse $v0 for the
 * address (nd 2); retail keeps it in $v1. Pure $v1/$v0 swap = allocator
 * floor (same residual in sibling files code1_004e/code1_0052). NONMATCHING */
#pragma schedule on

// FUN_004D3190 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3190(void)
{
    return D_00723F20[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3190);
#endif
#pragma schedule off


extern s32 D_00724E58[];

/* measured: #pragma schedule on is load-bearing for the sw-in-return-delay-
 * slot placement; address colors $v1 vs retail $v0 (nd 2, allocator
 * floor). NONMATCHING */
#pragma schedule on

// FUN_004D3678 NONMATCHING
#ifdef NON_MATCHING
void func_004d3678(s32 arg0)
{
    D_00724E58[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3678);
#endif
#pragma schedule off


extern s32 D_00724E58[];

/* measured: #pragma schedule on is load-bearing for the lw-in-return-delay-
 * slot placement; address reuses $v0 vs retail $v1 (nd 2, allocator
 * floor). NONMATCHING */
#pragma schedule on

// FUN_004D3688 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3688(void)
{
    return D_00724E58[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3688);
#endif
#pragma schedule off


extern s32 D_00724E60[];

/* measured: #pragma schedule on is load-bearing for the lw-in-return-delay-
 * slot placement; address reuses $v0 vs retail $v1 (nd 2, allocator
 * floor). NONMATCHING */
#pragma schedule on

// FUN_004D3698 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3698(void)
{
    return D_00724E60[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3698);
#endif
#pragma schedule off


extern s32 D_00724E60[];

/* measured: #pragma schedule on is load-bearing for the sw-in-return-delay-
 * slot placement; address colors $v1 vs retail $v0 (nd 2, allocator
 * floor). NONMATCHING */
#pragma schedule on

// FUN_004D36A8 NONMATCHING
#ifdef NON_MATCHING
void func_004d36a8(s32 arg0)
{
    D_00724E60[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d36a8);
#endif
#pragma schedule off


/* measured: #pragma schedule on is load-bearing for the sw-in-return-delay-
 * slot placement (without it mwcc emits addiu/sw/jr/nop, nd 3). Returning
 * the stored constant 1 makes mwcc materialize it in $v0 (a void return
 * colors it $v1, nd 2), so the stored value doubles as the return value
 * and no extra instruction is needed. */
#pragma schedule on

// FUN_004DE2B0
s32 func_004de2b0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = 1;
    return 1;
}
#pragma schedule off
