#include "include_asm.h"
#include "type.h"


extern s32 D_00925BE0[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F13B0
#pragma schedule on
s32 *func_004f13b0(void) {
    return D_00925BE0;
}
#pragma schedule off


extern s32 D_0075D370[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F1538
#pragma schedule on
s32 *func_004f1538(void) {
    return D_0075D370;
}
#pragma schedule off


extern s32 D_0075D620[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F34A0
#pragma schedule on
s32 *func_004f34a0(void) {
    return D_0075D620;
}
#pragma schedule off


/* measured: the segment-return form (CRI ADX "set param" family) is
   load-bearing: retail's sw $zero uses $v0 as base because the segment
   address is the live return value; a void store compiles to a $v1 base.
   The schedule-on pragma fills the jr $ra delay slot (nd 6 -> 0). */

// FUN_004F54A0
#pragma schedule on
u32 func_004f54a0(void) {
    u32 segment = 0x00740000;
    *(u32 *)(segment + 0x3a54) = 0;
    return segment;
}
#pragma schedule off


/* measured: the segment-return form (CRI ADX family) is used for family
   consistency; the schedule-on pragma fills the jr $ra delay slot. */

#pragma schedule on
// FUN_004F54B0 NONMATCHING
#ifdef NON_MATCHING
u32 func_004f54b0(void) {
    u32 segment = 0x00740000;
    return *(u32 *)(segment + 0x3a54);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f54b0);
#endif
#pragma schedule off


/* measured: the segment-return form (CRI ADX "set param" family) is
   load-bearing: retail's sw $a0 uses $v0 as base because the segment
   address is the live return value; a void store compiles to a $v1 base.
   The schedule-on pragma fills the jr $ra delay slot (nd 6 -> 0). */

// FUN_004F69B8
#pragma schedule on
u32 func_004f69b8(u32 value) {
    u32 segment = 0x00740000;
    *(u32 *)(segment + 0x3b58) = value;
    return segment;
}
#pragma schedule off


extern s32 D_0075D9E8[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F69C8
#pragma schedule on
s32 *func_004f69c8(void) {
    return D_0075D9E8;
}
#pragma schedule off


extern s32 D_0075DB88[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F8508
#pragma schedule on
s32 *func_004f8508(void) {
    return D_0075DB88;
}
#pragma schedule off


extern s32 D_0075DBC8[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F9368
#pragma schedule on
s32 *func_004f9368(void) {
    return D_0075DBC8;
}
#pragma schedule off
