#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void func_001437b0(void *arg0, s32 arg1, s32 arg2);
void func_001344d0(u8 *arg0);
void func_00131a00(u8 *arg0);
s16 func_00106cd0(s32 arg0, s16 arg1);
u8 func_00106600(s16 arg0);
s32 func_00106c30(s16 arg0, s32 arg1);
s32 func_00106c80(s16 arg0);
void func_0046d730(void *arg0, s32 arg1);
extern u8 D_005E9FA0[];

// FUN_001312B0
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_001312b0);

/* measured: retail materialises the s16 clamp value v into $a0 (dsll32/dsra32
   $a0, slti $at, addiu $a0,0x63, sh $a0,0x4C) and count's sign-extension
   in-place into $v1 (dsll32/dsra32/sll all $v1), with `count + 1` reading the
   home $s2. mwcc b210 always colours v's materialisation into $a1 and count's
   into $a0, so the increment reads $a0 instead of $s2 (10 words, every other
   instruction matched). Tried: s16 vs s32 v, `>` vs `>=` clamp forms (the `>`
   form fixed the slti $at target), pointer-local store base, named s32 c4 =
   count*4, for-header comma init (fixed the zero-move order), explicit
   (s16) truncation on the increment, explicit (s32) cast on the compare - all
   nd 10. s16-materialisation scratch-register colouring floor. */
// FUN_00131730
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131730);
// FUN_001318C0
s32 func_001318c0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00131910
s32 func_00131910(u8 *arg0) {
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (*(s16 *)(arg0 + 0x20) < 0x64) {
        *(s16 *)(arg0 + 0x20) = *(s16 *)(arg0 + 0x20) + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0xC80, *(s16 *)(arg0 + 0x20), 0);
        if (*(u8 *)(p + 0xC9A) != 0) {
            rv = 0;
        }
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) >= 0x168) {
        *(s16 *)(arg0 + 0x22) = 0;
    }
    func_001344d0(arg0);
    func_00131a00(arg0);
    return rv;
}
// FUN_00131A00
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131a00);

// FUN_001344B0
s32 func_001344b0(u8 *arg0, s32 arg1, s16 arg2) {
    /* The offset must be computed before the base is added: writing
       `arg0 + arg1 * 2` makes mwcc emit `addu $v1,$a0,$v0`, retail has
       `addu $v1,$v0,$a0`. */
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x30) = *(s16 *)(p + 0x28);
    *(s16 *)(p + 0x28) = arg2;
    return 1;
}

// FUN_001344D0
void func_001344d0(u8 *arg0) {
    s32 i;
    s16 v;

    v = *(s16 *)(arg0 + 0x24);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x24) = v + 1;
    }
    for (i = 0; i < 3; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1430, *(s16 *)(arg0 + 0x24), 0);
    }
}

// FUN_00134560
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00134560);

