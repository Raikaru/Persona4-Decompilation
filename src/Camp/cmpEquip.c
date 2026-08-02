#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

// FUN_001312B0
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_001312b0);

// FUN_00131730
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131730);

// FUN_001318C0
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_001318c0);

// FUN_00131910
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131910);

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
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_001344d0);

// FUN_00134560
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00134560);

