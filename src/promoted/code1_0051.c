#include "include_asm.h"
#include "type.h"


extern u8 *D_00745888[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and retail fills it with the final addiu (nd 6 -> 0). */

// FUN_00510E30
#pragma schedule on
u8 **func_00510e30(void) {
    return (u8 **)D_00745888;
}
#pragma schedule off


extern u8 *D_00745888[];

/* measured: mwcc b210 coalesces the global base into $v0 (lui $v0 / lw $v0, 0($v0));
   retail 2.4.1.01 keeps the base in $v1 (lui $v1 / lw $v0, %lo($v1)). nd 2 (the two
   rt-register bytes). Tried typed pointer local, (u32) integer base, scalar-extern,
   result locals, single-expression chains, no-pragma (nd 6); best nd 2. This is the
   brief's corroborated "$v0/$v1 coalescing in tiny accessors" floor. */

#pragma schedule on
#pragma schedule off


extern u8 *D_00745AC0[];

/* measured: mwcc b210 coalesces the global base into $v0 (lui $v0 / lw $v0, 0($v0));
   retail 2.4.1.01 keeps the base in $v1 (lui $v1 / lw $v0, %lo($v1)). nd 2 (the two
   rt-register bytes). Tried typed pointer local, (u32) integer base, scalar-extern,
   result locals, single-expression chains, no-pragma (nd 6); best nd 2. This is the
   brief's corroborated "$v0/$v1 coalescing in tiny accessors" floor. */

#pragma schedule on
#pragma schedule off


extern u8 *D_00745AC0[];

/* measured: mwcc b210 emits lui $v0 / sw / jr / daddu $v0,$0,$0 (return const in
   the delay slot), base in $v0; retail 2.4.1.01 emits lui $v1 / daddu $v0,$0,$0 /
   jr / sw (store in the delay slot), base in $v1. nd 7 (rt byte + sw/daddu
   ordering). Tried pointer-local, (u32)-base, return-local, no-pragma (nd 6);
   best nd 7. $v0/$v1 coalescing floor (brief) + delay-slot preference. */

#pragma schedule on
// FUN_00513A40
/* measured: retail materialises the global's address once and keeps it live
   across the store; b210 shares that address with the returned constant
   unless common-subexpression sharing is off (nd 7 -> byte-exact). */
#pragma opt_common_subs off
s32 func_00513a40(u8 *arg0) {
    D_00745AC0[0] = arg0;
    return 0;
}
#pragma opt_common_subs on
#pragma schedule off



/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 8. */
// FUN_005179E8 NONMATCHING
#ifdef NON_MATCHING
void func_005179e8(u8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0x1FC);
    p[1] = 0;
    p[0] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005179e8);
#endif


typedef struct {
    s32 unk_0; /* 0 */
    s32 unk_4; /* 4 */
} Unit17C18;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 6 -> 0). */

// FUN_00517C18
#pragma schedule on
void func_00517c18(Unit17C18 *arg0, s32 arg1, s32 arg2) {
    arg0->unk_4 = arg2;
    arg0->unk_0 = arg1;
}
#pragma schedule off


/* measured: mwcc b210 loads the intermediate pointer into $v0 (lw $v0,0x1f7c($a0) /
   lw $v0,0x20($v0)); retail 2.4.1.01 keeps it in $v1 (lw $v1,0x1f7c($a0) /
   lw $v0,0x20($v1)). nd 2 (the two rt-register bytes). Tried s32/u32 locals,
   result locals, single-expression chains, pointer-arithmetic variants, no-pragma
   (nd 6); best nd 2. Corroborated $v0/$v1 coalescing floor (wave brief).
   Committed at nd 2. */

#pragma schedule on
// FUN_00519EE0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00519ee0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1F7C);
    return *(s32 *)(p + 0x20);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519ee0);
#endif
/* measured: closes the schedule bracket above and restores the -O2 baseline. */
#pragma schedule off


/* measured: mwcc b210 loads the intermediate pointer into $v0 (lw $v0,0x1fc0($a0) /
   lw $v0,0x7c($v0)); retail 2.4.1.01 keeps it in $v1 (lw $v1,0x1fc0($a0) /
   lw $v0,0x7c($v1)). nd 2 (the two rt-register bytes). Tried s32/u32 locals,
   result locals, single-expression chains, pointer-arithmetic variants, no-pragma
   (nd 6); best nd 2. Corroborated $v0/$v1 coalescing floor (wave brief). */

#pragma schedule on
// FUN_0051F5E8 NONMATCHING
#ifdef NON_MATCHING
s32 func_0051f5e8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    return *(s32 *)(p + 0x7C);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051f5e8);
#endif
#pragma schedule off


/* measured: without #pragma schedule on, the sw does not fill the jr $ra
   delay slot (nd 2 -> 0); the function returns the loaded pointer, which is
   what keeps it in $v0. */

// FUN_0051F5F8
#pragma schedule on
u8 *func_0051f5f8(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    *(s32 *)(p + 0x80) = arg1;
    return p;
}
#pragma schedule off
