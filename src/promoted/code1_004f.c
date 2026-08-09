#include "include_asm.h"
#include "type.h"


extern s32 D_00925BE0[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F1350
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1350);
// FUN_004F1380
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1380);
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

// FUN_004F13C0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f13c0);
// FUN_004F1418
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1418);
// FUN_004F1430
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1430);
// FUN_004F1448
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1448);
// FUN_004F1460
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1460);
// FUN_004F14B0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f14b0);
// FUN_004F14C8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f14c8);
// FUN_004F14E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f14e0);
// FUN_004F1518
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1518);
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

// FUN_004F1548
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1548);
// FUN_004F1600
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1600);
// FUN_004F16B0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f16b0);
// FUN_004F1708
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1708);
// FUN_004F1750
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1750);
// FUN_004F1820
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1820);
// FUN_004F1850
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1850);
// FUN_004F1F80
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1f80);
// FUN_004F1FB0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1fb0);
// FUN_004F2BC0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2bc0);
// FUN_004F2C08
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2c08);
// FUN_004F2E18
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2e18);
// FUN_004F2E80
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2e80);
// FUN_004F2F58
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2f58);
// FUN_004F30C0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f30c0);
// FUN_004F3108
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3108);
// FUN_004F3150
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3150);
// FUN_004F3258
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3258);
// FUN_004F3340
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3340);
// FUN_004F33E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f33e0);
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

// FUN_004F34B0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f34b0);
// FUN_004F34E8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f34e8);
// FUN_004F3780
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3780);
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
#pragma schedule off


/* measured: the segment-return form (CRI ADX "set param" family) is
   load-bearing: retail's sw $a0 uses $v0 as base because the segment
   address is the live return value; a void store compiles to a $v1 base.
   The schedule-on pragma fills the jr $ra delay slot (nd 6 -> 0). */

// FUN_004F5BD0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5bd0);
// FUN_004F5BF0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5bf0);
// FUN_004F5CD0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5cd0);
// FUN_004F5D38
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5d38);
// FUN_004F5FD8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5fd8);
// FUN_004F60F8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f60f8);
// FUN_004F6188
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6188);
// FUN_004F6870
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6870);
// FUN_004F6888
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6888);
// FUN_004F68A0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f68a0);
// FUN_004F68B8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f68b8);
// FUN_004F6948
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6948);
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

// FUN_004F7940
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f7940);
// FUN_004F8478
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8478);
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

// FUN_004F8518
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8518);
// FUN_004F8ED8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8ed8);
// FUN_004F8F60
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8f60);
// FUN_004F8FE8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8fe8);
// FUN_004F9040
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9040);
/* measured: schedule on tested for return-zero epilogue order. */
#pragma schedule on
// FUN_004F9130
s32 func_004f9130(void)
{
    func_004f8f60();
    return 0;
}
/* measured: restore schedule off after func_004f9130. */
#pragma schedule off
// FUN_004F9150
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9150);
// FUN_004F9198
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9198);
// FUN_004F9350
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9350);
// FUN_004F9368
#pragma schedule on
s32 *func_004f9368(void) {
    return D_0075DBC8;
}
#pragma schedule off

// FUN_004F9378
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9378);
// FUN_004F93D0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f93d0);
// FUN_004F9410
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9410);
// FUN_004F94B8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f94b8);
// FUN_004F94E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f94e0);
// FUN_004F9528
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9528);
// FUN_004F9590
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9590);
// FUN_004F95F8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f95f8);
// FUN_004F9638
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9638);
// FUN_004F96A0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f96a0);
// FUN_004F9708
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9708);
// FUN_004F9770
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9770);
// FUN_004F97D8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f97d8);
// FUN_004F9840
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9840);
// FUN_004F98A8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f98a8);
// FUN_004F9910
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9910);
// FUN_004F9978
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9978);
// FUN_004F99E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f99e0);
// FUN_004F99F8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f99f8);
// FUN_004F9A10
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a10);
// FUN_004F9A58
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a58);
// FUN_004F9A70
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a70);