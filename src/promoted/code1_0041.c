#include "include_asm.h"
#include "type.h"

s32 func_0041e8d8(); /* old-style: retail callers leave $a0..$a3 materialized */

/* measured: baseline -O2 emits lw/sw/srl/andi/jr/nop with the return andi
   before jr (nd 6); schedule-on fills the jr delay slot with the andi but
   reorders the srl ahead of the store (nd 8), so the plain -O2 form is
   kept. Residual vs retail (lw/sw/srl/jr/andi): the andi/jr pair swapped.
   Translation-unit hypothesis: the parked bodies below were audited together;
   eight +0x40 loaders currently active in the probe had nd/object 46/68/72
   (f178), 39/64/72 (f1c0), 2/16/16 (f2a8), 8/32/32 (f2d0), 5/24/24
   (f550), 3/24/24 (f5e0), and 2/36/40 (f788/f7b0). Named locals, parameter
   reassignment, fully inline expressions, declaration orders, pointer and
   scalar types, and pragma wrappers did not move any destination. */
/* measured: compared with matching code1_0048 and code1_0051, this TU has the
   same include set (`include_asm.h`, `type.h`), no data externs/globals, and
   only the three helper declarations. Each pragma is locally closed; none
   spans the file. One-at-a-time probes of old/prototyped helper forms,
   explicit extern, helper widths, include order, and a file-wide schedule
   extension left all eight active rows exactly unchanged. The uniform
   register divergence is therefore not a declaration environment defect. */
/* measured: retail call-site audit confirms func_0041e8d8 is old-style:
   f178/f1c0/f500 enter its jal with the existing a0-a3 values and do not
   materialize a prototype-defined argument list. The promoted TU now uses
   `s32 func_0041e8d8();`; typed one-pointer declarations for 00420e50 and
   00420f38 agree with their retail callers. No data globals are declared in
   this TU, so there is no array-versus-scalar global correction to test.
   Declaration-environment audit left every parked nd unchanged. */

void func_00420e50(u8 *);

void func_00420f38(u8 *);


/* measured: object/window 24/24; candidate loads the old u32, stores arg1,
   then returns bit 8 of the old value. Exact residual: off 12 candidate
   andi $v0,$v0,1 versus retail jr $ra; off 16 candidate jr $ra versus
   retail andi $v0,$v0,1 (2 words, nd 6). Ruled out schedule on (nd 8),
   schedule off, optimization levels 1/3, opt_common_subs, direct-return
   and masked-expression forms, s32/u32/u8/u16 return types, local pointer
   and casted load/store aliases, control-flow/ternary/switch forms, and
   inline side-effect expressions. Delay-slot scheduling remains the best
   measured body. Committed at nd 6. */
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

/* measured: object/window 16/16; candidate loads the +0x40 base and tests
   its +4 u32 field for zero. Exact residual: off 0 candidate
   lw $v0,0x40($a0) versus retail lw $v1,0x40($a0); off 4 candidate
   lw $v0,4($v0) versus retail lw $v0,4($v1) (2 words, nd 2). Ruled out
   direct/local/full-inline chains, pointer/scalar/struct views, register
   qualifiers, declaration and assignment orders, pointer advance, result
   locals and initializers, live-value identities, and schedule/optimization
   pragma variants. Retail's first-load destination remains unresponsive.
   Committed at nd 2. */
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



/* measured: object/window 32/32; candidate returns the final loaded value
   after storing all three outputs, improving nd 9 -> nd 8. Exact residual:
   off 0 candidate lw $v1,0x40($a0) versus retail lw $t0,0x40($a0);
   off 4 candidate lw $v0,0xa8($v1) versus retail lw $v0,0xa8($t0);
   off 12 candidate lw $v0,0xac($v1) versus retail lw $v1,0xac($t0);
   off 16 candidate sw $v0,($a2) versus retail sw $v1,($a2); off 20
   candidate lw $v0,0xb0($v1) versus retail lw $v0,0xb0($t0) (5 words).
   Ruled out pointer/output types, declaration order, simultaneous-load and
   grouped-load forms, final-load/direct/output/unsigned returns, identity
   uses, arrays and pointer aliases, and optimization/pragmas. Retail's
   three-live-value colouring remains. Committed at nd 8. */
// FUN_0041F2D0 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe discarded final return */
#pragma schedule on
s32 func_0041f2d0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
    u8 *p;
    s32 value1;
    s32 value2;
    s32 value3;

    p = *(u8 **)(arg0 + 0x40);
    value1 = *(s32 *)(p + 0xA8);
    *arg1 = value1;
    value2 = *(s32 *)(p + 0xAC);
    *arg2 = value2;
    value3 = *(s32 *)(p + 0xB0);
    *arg3 = value3;
    return value3;
}
/* measured: close discarded return probe */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2d0);
#endif
/* measured: object/window 24/24; candidate stores the s64 argument at
   +0x90, stores 1 at +0x8C, and returns 1. Exact residual: off 0 candidate
   lw $a0,0x40($a0) versus retail lw $v1,0x40($a0); off 4 candidate
   addiu $v1,$zero,1 versus retail addiu $v0,$zero,1; off 8 candidate
   addiu $v0,$zero,1 versus retail addiu $a0,$zero,1; off 12 candidate
   sd $a1,0x90($a0) versus retail sd $a1,0x90($v1); off 20 candidate
   sw $v1,0x8c($a0) versus retail sw $a0,0x8c($v1) (5 words, nd 5).
   Ruled out local/pointer-type/struct views, declaration and assignment
   order, parameter captures, separate/reused constants, wide types,
   direct stores, return/store-value variants, and optimization/pragmas.
   Committed at nd 5. */
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


/* measured: object/window 24/24; candidate stores the 1 flag at +0x108,
   the s64 argument at +0x100, and returns 1. Exact residual: off 0
   candidate lw $a0,0x40($a0) versus retail lw $a2,0x40($a0); off 12
   candidate sw $v1,0x108($a0) versus retail sw $v1,0x108($a2); off 20
   candidate sd $a1,0x100($a0) versus retail sd $a1,0x100($a2) (3 words,
   nd 3). Ruled out constants and captures, pointer/scalar/struct and wide
   types, declaration/assignment order, direct-store/grouped-store forms,
   return/store-value variants, and optimization/pragmas. Committed at nd 3. */
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


/* measured: object/window 36/40; candidate calls func_00420e50 on the
   +0x68 address and returns 1. Exact residual: off 8 candidate
   lw $v0,0x40($a0) versus retail lw $a0,0x40($a0); off 16 candidate
   addiu $a0,$v0,0x68 versus retail addiu $a0,$a0,0x68; differing words 3
   including the relocation-masked jal, with the object 4 bytes short of the
   retail trailing nop (nd 2). Ruled out callee prototypes, argument reuse,
   parameter reassignment, pointer locals/shadows, inline/grouped/casted
   expressions, scalar and pointer types, register qualifiers, declaration
   order, and optimization/schedule pragma variants. Committed at nd 2. */
// FUN_0041F788 NONMATCHING
#ifdef NON_MATCHING
/* measured: inline argument-expression probe; schedule on retained the
   retail delay-slot form while the load destination remained a b210 floor. */
#pragma schedule on
s32 func_0041f788(u8 *arg0)
{
    func_00420e50((u8 *)(*(u8 **)((u8 *)arg0 + 0x40) + 0x68));
    return 1;
}
/* measured: closes the schedule scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f788);
#endif


/* measured: object/window 36/40; candidate calls func_00420f38 on the
   +0x68 address and returns 1. Exact residual: off 8 candidate
   lw $v0,0x40($a0) versus retail lw $a0,0x40($a0); off 16 candidate
   addiu $a0,$v0,0x68 versus retail addiu $a0,$a0,0x68; differing words 3
   including the relocation-masked jal, with the object 4 bytes short of the
   retail trailing nop (nd 2). Ruled out callee prototypes, argument reuse,
   parameter reassignment, pointer locals/shadows, inline/grouped/casted
   expressions, scalar and pointer types, register qualifiers, declaration
   order, and optimization/schedule pragma variants. Committed at nd 2. */
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
