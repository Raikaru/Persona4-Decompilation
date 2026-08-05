#include "include_asm.h"
#include "type.h"

/* measured: baseline -O2 emits lw/sw/srl/andi/jr/nop with the return andi
   before jr (nd 6); schedule-on fills the jr delay slot with the andi but
   reorders the srl ahead of the store (nd 8), so the plain -O2 form is
   kept. Residual vs retail (lw/sw/srl/jr/andi): the andi/jr pair swapped. */

void func_00420e50(u8 *);

void func_00420f38(u8 *);


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

// FUN_0041F178
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f178);

// FUN_0041F1C0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f1c0);

// FUN_0041F2A8
#pragma schedule on
#ifdef NON_MATCHING
s32 func_0041f2a8(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    return *(u32 *)(p + 4) < 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2a8);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f2a8). */
#pragma schedule off


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



// FUN_0041F2D0
#pragma schedule on
#ifdef NON_MATCHING
void func_0041f2d0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *arg1 = *(s32 *)(p + 0xA8);
    *arg2 = *(s32 *)(p + 0xAC);
    *arg3 = *(s32 *)(p + 0xB0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2d0);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f2d0). */
#pragma schedule off
// FUN_0041F550
/* measured: see the annotation above the matching `on` pragma (func_0041f550). */
#pragma opt_common_subs off
#pragma schedule on
#ifdef NON_MATCHING
s32 func_0041f550(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = arg1;
    *(s32 *)(p + 0x8C) = 1;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f550);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f550). */
#pragma schedule off
#pragma opt_common_subs on


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


// FUN_0041F5E0
/* measured: see the annotation above the matching `on` pragma (func_0041f5e0). */
#pragma opt_common_subs off
#pragma schedule on
#ifdef NON_MATCHING
s32 func_0041f5e0(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0x108) = 1;
    *(s64 *)(p + 0x100) = arg1;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f5e0);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f5e0). */
#pragma schedule off
#pragma opt_common_subs on


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


// FUN_0041F788
#pragma schedule on
#ifdef NON_MATCHING
s32 func_0041f788(u8 *arg0)
{
    func_00420e50(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f788);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f788). */
#pragma schedule off


// FUN_0041F7B0
#pragma schedule on
#ifdef NON_MATCHING
s32 func_0041f7b0(u8 *arg0)
{
    func_00420f38(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f7b0);
#endif
/* measured: see the annotation above the matching `on` pragma (func_0041f7b0). */
#pragma schedule off
