#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit eff_after.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007146E0[];

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern f32 func_003e4180(void *a0);
extern void func_003e40b0(f32 *a, f32 *b);
extern f32 func_004b7300(void *arg0, s32 arg1);
extern s32 func_004b7800(void *arg0, s32 arg1);
extern void func_004bb1d0();

/* 12-byte vector copy; mwcc emits all loads then all stores for a struct
   assignment, matching retail, where per-element statements interleave. */
typedef struct {
    f32 c[3];
} EffAfterVec;

/* measured: nd 461 with a full C body (object 936B against a 928B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_004B7460
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b7460);

// FUN_004B7830
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b7830);

// FUN_004B7DC0
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b7dc0);

// FUN_004B8350
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8350);

// FUN_004B8DF0
void func_004b8df0(u8 *arg0, u8 *arg1) {
    u8 *p;
    u8 *q;
    s32 size;

    size = 0;
    size += (*(s32 *)(arg1 + 8) * 3 << 3);
    size += (*(s32 *)(arg1 + 8) * 3 << 4);
    func_0044ea90(D_007146E0, 0x2A5);
    p = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    *(void **)(arg0 + 0x10) = p;
    q = p + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x14) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x18) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x1C) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x20) = q;
    *(void **)(arg0 + 0x24) = q + *(s32 *)(arg1 + 8) * 0xC;
    *(s32 *)(arg0 + 4) = 0;
    *(void **)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s16 *)(arg0 + 0x38) = *(s32 *)(arg1 + 0x10);
}

// FUN_004B8F10
void func_004b8f10(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x10));
}

// FUN_004B8F40
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8f40);

/* measured: retail materializes the case-1 comparison constant in $a1
   (addiu $a1,$zero,1; beq $a0,$a1) while mwcc b210 reuses $v1 from the
   case-2 test, leaving exactly 2 differing words (nd 2). Tried switch case
   orders (0,1,2) (0,2,1) (2,1,0) (0,2,D,1), default first/last, case 1 as
   break vs return, unsigned switch, named switch-value local, all-break +
   trailing return, and an if/else-if chain: every spelling either compiles to
   the identical $v1 reuse or breaks retail's test order/layout. Register-
   coalescing floor in the linear switch comparison chain. */
// FUN_004BAD70
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bad70);

// FUN_004BB1D0
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bb1d0);

/* measured: everything matches except block 2's instruction order: retail
   emits the var_3*0xC multiply chain first, then the arg2*4+arg0 address;
   mwcc b210 always hoists the load-address computation (sll+addu) above the
   multiply chain, whatever the spelling, and also emits the first v[i]-=p[i]
   with the accumulator load before the source load (retail: source first).
   nd 11. Tried 30+ spellings: inline vs s32-step local, off/off2 offset
   locals, signed vs unsigned mult (arg2*4U + (u32)arg0 defeats the addu CSE
   and fixed the operand order), (s32*)base+4 element arithmetic, shift vs
   mul, addend reorders, statement reorders, #pragma schedule on (worse),
   temp-per-component subtracts. Block 1 matches byte-for-byte with the off
   local + (s32)arg0 cast; block 2's residual is a fixed address-hoisting
   schedule, same family as the load-sinking floor. */
// FUN_004BC1E0
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bc1e0);

// FUN_004BC310
f32 func_004bc310(u8 *arg0, s32 arg1) {
    EffAfterVec v1;
    EffAfterVec v2;
    EffAfterVec *q;
    f32 d;
    f32 t;
    s32 i;
    s32 j;
    u8 *p;

    if (arg1 == *(s32 *)(arg0 + 8) - 1) {
        func_0046d730(D_007146E0, 0x709);
    }
    i = (*(s32 *)(arg0 + 0xC) - 1) - arg1;
    if (i < 0) {
        i += *(s32 *)(arg0 + 8);
    }
    p = (u8 *)(*(s32 *)(arg0 + 0x14) + i * 0xC);
    v1 = *(EffAfterVec *)p;
    p = (u8 *)(*(s32 *)(arg0 + 0x10) + i * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v1.c[0] -= t;
    v1.c[1] -= q->c[1];
    v1.c[2] -= q->c[2];
    func_003e40b0(&v1.c[0], &v1.c[0]);
    j = (-2 - arg1) + *(s32 *)(arg0 + 0xC);
    if (j < 0) {
        j += *(s32 *)(arg0 + 8);
    }
    p = (u8 *)(*(s32 *)(arg0 + 0x14) + j * 0xC);
    v2 = *(EffAfterVec *)p;
    p = (u8 *)(*(s32 *)(arg0 + 0x10) + j * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v2.c[0] -= t;
    v2.c[1] -= q->c[1];
    v2.c[2] -= q->c[2];
    func_003e40b0(&v2.c[0], &v2.c[0]);
    d = v1.c[0] * v2.c[0] + v1.c[1] * v2.c[1] + v1.c[2] * v2.c[2];
    return (1.0f - d) / 2.0f;
}
