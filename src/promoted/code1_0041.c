#include "include_asm.h"
#include "type.h"

extern void func_0041e8d8(u8 *arg0, s32 arg1);

/* measured: baseline -O2 emits lw/sw/srl/andi/jr/nop with the return andi
   before jr (nd 6); schedule-on fills the jr delay slot with the andi but
   reorders the srl ahead of the store (nd 8), so the plain -O2 form is
   kept. Residual vs retail (lw/sw/srl/jr/andi): the andi/jr pair swapped. */

void func_00420e50(u8 *);

void func_00420f38(u8 *);


/* measured: candidate loads the old u32, stores arg1, then returns bit 8 of the old value. Retail places the final andi in the jr delay slot while b210 schedules it before jr; plain -O2 is nd 6 and schedule-on worsens it to nd 8. Committed at nd 6. */
// FUN_00419628 NONMATCHING
#ifdef NON_MATCHING
s32 func_00419628(u32 *arg0, u32 arg1)
{
    u32 temp = *arg0;

    *arg0 = arg1;
    return (temp >> 8) & 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419628);
#endif


/* measured: retail fills the jr delay slot with the return value
   (jr $ra; addiu $v0,$zero,1 = 8 bytes). Scheduling is off at file scope here,
   so without this pragma b210 emits addiu; jr; nop and the object is 12 bytes
   against an 8-byte window. */
#pragma schedule on
// FUN_0041C2F8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c2f8);

// FUN_0041E198
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e198);

// FUN_0041F130
s32 func_0041f130(void)
{
    return 1;
}
/* measured: see the annotation above the matching `on` pragma (func_0041f130). */
#pragma schedule off

/* measured: the whole body is right -- retail's jal passes $a0 and $a1
   untouched from entry (arg0 and the masked tag), the 0x40 pointer lives in
   $a3, and #pragma schedule on puts the last store in the jal delay slot.
   The single residual is how b210 lowers `& 0x0FFFFFFF`: it clears the top
   36 bits of the 64-bit register with `dsll32 4 / dsrl32 4` (2 words) where
   retail materialises the constant and ANDs (`lui 0xfff / ori 0xffff / and`,
   3 words), so the object is 68 bytes in a 72-byte window and everything
   after the mask slides by one. Measured unchanged at nd 45-46: u32 and u8*
   parameter types, `~0xF0000000`, an explicit (u32) cast, splitting the and
   and the or into separate statements, a named s32/u32 local for the result,
   and `(u32)(x << 4) >> 4`; optimization_level 1 reaches nd 37 and level 3
   nd 36 but both shrink the object further. Constant-mask lowering floor. */
// FUN_0041F178 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
void func_0041f178(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p = *(u8 **)(arg0 + 0x40);

    arg1 = (arg1 & 0x0FFFFFFF) | 0x20000000;
    *(s32 *)(p + 0xC4) = 1;
    *(s32 *)(p + 0xEC) = arg1;
    *(s32 *)(p + 0xF8) = arg2;
    *(s32 *)(p + 0xF0) = 0;
    *(s32 *)(p + 0xF4) = 0;
    func_0041e8d8(arg0, arg1);
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f178);
#endif

/* measured: the whole body is right -- retail's jal passes $a0 and $a1
   untouched from entry (arg0 and the masked tag), the 0x40 pointer lives in
   $a3, and #pragma schedule on puts the last store in the jal delay slot.
   The single residual is how b210 lowers `& 0x0FFFFFFF`: it clears the top
   36 bits of the 64-bit register with `dsll32 4 / dsrl32 4` (2 words) where
   retail materialises the constant and ANDs (`lui 0xfff / ori 0xffff / and`,
   3 words), so the object is 68 bytes in a 72-byte window and everything
   after the mask slides by one. Measured unchanged at nd 45-46: u32 and u8*
   parameter types, `~0xF0000000`, an explicit (u32) cast, splitting the and
   and the or into separate statements, a named s32/u32 local for the result,
   and `(u32)(x << 4) >> 4`; optimization_level 1 reaches nd 37 and level 3
   nd 36 but both shrink the object further. Constant-mask lowering floor. */
// FUN_0041F1C0 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
void func_0041f1c0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p = *(u8 **)(arg0 + 0x40);

    arg1 = (arg1 & 0x0FFFFFFF) | 0x20000000;
    *(s32 *)(p + 0xF8) = arg2;
    *(s32 *)(p + 0xEC) = arg1;
    *(s32 *)(p + 0xF0) = 0;
    *(s32 *)(p + 0xC4) = 0;
    *(s32 *)(p + 0xF4) = 0;
    func_0041e8d8(arg0, arg1);
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f1c0);
#endif

/* measured: candidate loads the +0x40 base and tests its +4 u32 field for zero. Retail keeps the base in $v1 before loading the result into $v0; direct, local, pointer-type, struct-view, register-qualified, declaration-order, and pointer-advance spellings stayed at nd 2. Committed at nd 2. */
// FUN_0041F2A8 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail fills delay slots this function leaves empty at -O2. */
#pragma schedule on
s32 func_0041f2a8(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    return *(u32 *)(p + 4) < 1;
}
/* measured: closes the scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2a8);
#endif


/* measured: retail sinks the third store into the jr $ra delay slot, which
   b210 only does under schedule on -- and only while the stored-through
   pointer is already in $v0, which needs the discarded `return p`. Without
   the return the pointer colours $v1 and the slot stays a nop (nd 4). */
// FUN_0041F2B8
#pragma schedule on
u8 *func_0041f2b8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0xB0) = arg3;
    *(s32 *)(p + 0xA8) = arg1;
    *(s32 *)(p + 0xAC) = arg2;

    return p;
}
#pragma schedule off



/* measured: candidate reads +0xA8, +0xAC, and +0xB0 through the +0x40 base and writes the three output pointers. Retail keeps the base in $t0 and alternates value registers ($v0/$v1/$v0), while b210 reuses $a0/$v1; pointer/output types, declaration order, simultaneous-load, and optimization probes stayed at nd 9. Committed at nd 9. */
// FUN_0041F2D0 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail fills delay slots this function leaves empty at -O2. */
#pragma schedule on
void func_0041f2d0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *arg1 = *(s32 *)(p + 0xA8);
    *arg2 = *(s32 *)(p + 0xAC);
    *arg3 = *(s32 *)(p + 0xB0);
}
/* measured: closes the scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2d0);
#endif
/* measured: candidate stores the s64 argument at +0x90, stores 1 at +0x8C, and returns 1. Retail keeps the base in $v1 and uses $a0 for the status constant while b210 reuses $a0 for the base; local, pointer-type, return/store-value, and optimization probes stayed at nd 5. Committed at nd 5. */
// FUN_0041F550 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail both fills delay slots this function leaves empty and
   re-issues a value b210 would share; both pragmas are needed. */
#pragma schedule on
#pragma opt_common_subs off
s32 func_0041f550(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = arg1;
    *(s32 *)(p + 0x8C) = 1;
    return 1;
}
/* measured: closes both scopes above at the file's -O2 baseline. */
#pragma opt_common_subs on
/* measured: closes both scopes above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f550);
#endif


// FUN_0041F568
#pragma schedule on
s32 func_0041f568(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x8C) = 0;
    return 1;
}
/* measured: see the annotation above the matching `on` pragma (func_0041f568). */
#pragma schedule off


/* measured: candidate stores the 1 flag at +0x108, the s64 argument at +0x100, and returns 1. Retail keeps the base in $a2 while b210 reuses $a0; parameter, pointer-type, declaration-order, direct-store, and optimization-level probes stayed at nd 3. Committed at nd 3. */
// FUN_0041F5E0 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail both fills delay slots this function leaves empty and
   re-issues a value b210 would share; both pragmas are needed. */
#pragma schedule on
#pragma opt_common_subs off
s32 func_0041f5e0(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0x108) = 1;
    *(s64 *)(p + 0x100) = arg1;
    return 1;
}
/* measured: closes both scopes above at the file's -O2 baseline. */
#pragma opt_common_subs on
/* measured: closes both scopes above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f5e0);
#endif


// FUN_0041F6C8
#pragma schedule on
void func_0041f6c8(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 8) = arg1;
}
/* measured: see the annotation above the matching `on` pragma (func_0041f6c8). */
#pragma schedule off


/* measured: candidate calls func_00420e50 on the +0x68 address and returns 1. Retail materializes the base directly in $a0, while b210 uses $v0 then moves to $a0; callee-prototype, argument-reuse, pointer-local, and optimization-level probes stayed at nd 2 with a 36-byte object in the 40-byte window. Committed at nd 2. */
// FUN_0041F788 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail fills delay slots this function leaves empty at -O2. */
#pragma schedule on
s32 func_0041f788(u8 *arg0)
{
    func_00420e50(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
/* measured: closes the scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f788);
#endif


/* measured: candidate calls func_00420f38 on the +0x68 address and returns 1. Retail materializes the base directly in $a0, while b210 uses $v0 then moves to $a0; argument-reuse, pointer-local, and optimization-level probes stayed at nd 2 with a 36-byte object in the 40-byte window. Committed at nd 2. */
// FUN_0041F7B0 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail fills delay slots this function leaves empty at -O2. */
#pragma schedule on
s32 func_0041f7b0(u8 *arg0)
{
    func_00420f38(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
/* measured: closes the scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f7b0);
#endif
