#include "include_asm.h"
#include "type.h"

extern s32 D_00745AF8[];

extern s32 D_00745ABC[];

extern s32 D_007609B0[];

extern s32 D_00745C84[];

extern s32 D_00745C6C[];

extern s32 D_0074613C[];


/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_005207F8 NONMATCHING
#ifdef NON_MATCHING
void func_005207f8(s32 arg0)
{
    D_00745AF8[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005207f8);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_005230B8 NONMATCHING
#ifdef NON_MATCHING
void func_005230b8(s32 arg0)
{
    D_00745ABC[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230b8);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_005230C8 NONMATCHING
#ifdef NON_MATCHING
s32 func_005230c8(void)
{
    return D_00745ABC[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230c8);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/addiu/jr/nop (unfilled return delay slot);
 * retail is lui $v0 / jr $ra / addiu $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill. */
#pragma schedule on

// FUN_00528C30
s32 *func_00528c30(void)
{
    return D_007609B0;
}
#pragma schedule off


/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_0052B9E0 NONMATCHING
#ifdef NON_MATCHING
void func_0052b9e0(s32 arg0)
{
    D_00745C84[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9e0);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_0052B9F0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0052b9f0(void)
{
    return D_00745C84[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9f0);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_0052BA00 NONMATCHING
#ifdef NON_MATCHING
void func_0052ba00(s32 arg0)
{
    D_00745C6C[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba00);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_0052BA10 NONMATCHING
#ifdef NON_MATCHING
s32 func_0052ba10(void)
{
    return D_00745C6C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba10);
#endif
#pragma schedule off


/* measured: b210 O2 emits lui/sw/jr/nop (v1 scratch, unfilled return delay
 * slot); retail is lui $v0 / jr $ra / sw-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; address color stays
 * $v1 vs retail $v0 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

// FUN_0052C870 NONMATCHING
#ifdef NON_MATCHING
void func_0052c870(s32 arg0)
{
    D_0074613C[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c870);
#endif
#pragma schedule off
