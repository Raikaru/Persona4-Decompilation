#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_00105ed0();

void func_002b82d0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5);

void func_002b8300(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);

void func_002b8340(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);

void func_002e2a10(s32 arg0, s32 arg1, s8 arg2, s32 arg3);

void func_002e3560(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4);

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);

s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00105fa0(s32 arg0);
extern u8 D_0063F560[];
extern void func_002b2970(s64 *out, f32 x, f32 y);



// FUN_002E04E0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e04e0);
// FUN_002E04F0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e04f0);
// FUN_002E0570
s64 func_002e0570(u8 *arg0, s32 arg1)
{
    s16 flags;

    flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 4);
    return (s8)((flags & ((1 << (arg1 & 0xFFFF)) & 0xFFFF)) >> (arg1 & 0xFFFF));
}



// FUN_002E05A0
s32 func_002e05a0(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x4);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

// FUN_002E0620
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0620);
// FUN_002E0660
void func_002e0660(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s64 arg5)
{
    func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}



// FUN_002E0690
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0690);
// FUN_002E06D0
void func_002e06d0(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    func_002b8300(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}



// FUN_002E0700
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0700);
// FUN_002E0940
void func_002e0940(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    func_002b8340(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}



/* measured: replacing the two scalar result stores with a two-f32 aggregate
   copy preserves retail's grouped output loads and store-source registers. */

// FUN_002E0970
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0970);

// FUN_002E09B0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e09b0);
// FUN_002E09E0
void func_002e09e0(u8 *arg0, s32 arg1, f32 fparg0) {
    struct Out2 { f32 x; f32 y; };
    u8 *temp_6 = *(u8 **)(arg0 + 0x38);
    f32 *entry = (f32 *)(D_0063F560 + *(s16 *)(temp_6 + 0xF8) * 8);
    u8 *temp_16;
    struct Out2 out;
    *(s16 *)(temp_6 + 4) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = fparg0;
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002b2970((s64 *)&out, entry[0], entry[1]);
    *(struct Out2 *)(temp_16 + 0x2C) = out;
}

// FUN_002E0A60
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0a60);
// FUN_002E0B20
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0b20);
// FUN_002E0BE0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0be0);
// FUN_002E0CA0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0ca0);
// FUN_002E0D60
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0d60);
// FUN_002E0DA0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0da0);
// FUN_002E1CD0
s32 func_002e1cd0(void)
{
    return 0;
}

// FUN_002E1CE0
s32 func_002e1ce0(void)
{
    return 0;
}

// FUN_002E1CF0
s32 func_002e1cf0(void)
{
    return 0;
}

// FUN_002E23B0
s32 func_002e23b0(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e2a10(*(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}



// FUN_002E2410
s32 func_002e2410(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e3560(arg0, *(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}



// FUN_002E2470
void func_002e2470(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* measured: retail normalises the (s16) search value once in the loop
   preheader; plain -O2 re-narrows it inside the body (nd 69 at 132 bytes
   against a 128-byte window). With the hoist it is byte-exact. */
// FUN_002E6F90
#pragma opt_loop_invariants on
s32 func_002e6f90(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s16 val = (s16)arg1;
    s16 n = *(s16 *)(arg0 + 0x60);

    while ((s16)i < n) {
        if (*(s16 *)(arg0 + (s16)i * 2) == val) {
            return 0;
        }
        i = (s16)(i + 1);
    }
    *(s16 *)(arg0 + n * 2) = arg1;
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) + 1;
    return 1;
}
/* measured: hoist (s16)arg1 normalization out of loop */
#pragma opt_loop_invariants off

// FUN_002E7010
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7010);
// FUN_002E7190
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7190);
// FUN_002E71C0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e71c0);
// FUN_002E72C0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e72c0);
// FUN_002E74E0
void func_002e74e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002E7510
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7510);
// FUN_002E7870
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7870);
// FUN_002E78A0
u8 func_002e78a0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp18;
}



// FUN_002E78E0
u8 func_002e78e0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp1C;
}



// FUN_002E7920
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7920);
// FUN_002E7A60
void func_002e7a60(void)
{
    func_00105ed0();
}

// FUN_002E7A80
void func_002e7a80(s32 arg0)
{
    func_00105fa0(func_002b2cb0(arg0, 0, 0x98967F, 0, 1));
}

// FUN_002E7AC0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7ac0);
// FUN_002E82B0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e82b0);