#include "include_asm.h"
#include "type.h"

extern s8 D_00923640[];

extern u8 D_00731C7C[];

extern s32 D_00731C78[];
extern s32 D_00731C84[];

extern s32 D_00731C3C[];

extern s8 D_00731C01[];

extern s32 D_00731C34[];
/* Measured: retail saves callee-saved $s registers with sd; MWCCPS2 3.0.1 emits sq;
 * toolchain-blocked, see build/ORCH_sd_toolchain_blocked.txt. */
#pragma schedule on

// FUN_004E0058
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0058);
// FUN_004E00D8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e00d8);
// FUN_004E0158
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0158);
// FUN_004E01C0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e01c0);
// FUN_004E0268
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0268);
// FUN_004E0308
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0308);
// FUN_004E0380
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0380);
// FUN_004E0398
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0398);
// FUN_004E03B0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e03b0);
// FUN_004E0408
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0408);
// FUN_004E0458
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0458);
// FUN_004E04B0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e04b0);
// FUN_004E0560
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0560);
// FUN_004E0590
s8 func_004e0590(u8 *arg0)
{
    return *(s8 *)(arg0 + 1);
}
// FUN_004E0598
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e0598);
// FUN_004E05D0
void func_004e05d0(u8 *arg0)
{
    *(s8 *)(arg0 + 1) = 0;
}
// FUN_004E13C8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e13c8);
// FUN_004E1418
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1418);
// FUN_004E14B0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e14b0);
// FUN_004E1528
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1528);
// FUN_004E1578
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1578);
// FUN_004E15A8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e15a8);
// FUN_004E15D0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e15d0);
// FUN_004E1698
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1698);
// FUN_004E17A0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e17a0);
// FUN_004E1830
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1830);
// FUN_004E1908
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1908);
// FUN_004E19A0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e19a0);
// FUN_004E1A00
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1a00);
// FUN_004E1AD8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1ad8);
// FUN_004E1BA0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1ba0);
// FUN_004E1C20
s8 *func_004e1c20(void) {
    return D_00923640;
}
/* measured: without scheduling the addiu leaves the jr $ra delay slot; nd 0 -> 6 */
#pragma schedule off


#pragma schedule on

// FUN_004E1C30
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1c30);
// FUN_004E1CD8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1cd8);
// FUN_004E1E00
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e1e00);
// FUN_004E39E8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e39e8);
// FUN_004E3A10
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3a10);
// FUN_004E3AE0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3ae0);
// FUN_004E3BF0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3bf0);
// FUN_004E3C10
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3c10);
// FUN_004E3C78
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3c78);
// FUN_004E3D88
u8 *func_004e3d88(u8 arg0) {
    u8 *segment = (u8 *)0x00730000;
    segment[0x1C7C] = arg0;
    return segment;
}
/* measured: sb uses $v0 base because zero-lo segment is the live return (void store colors $v1, nd 2; returning 0x00731C7C adds ori, nd 3); schedule on fills the jr delay slot (nd 3 -> 0, tail nop is padding) */
#pragma schedule off


#pragma schedule on

// FUN_004E3D98
s32 *func_004e3d98(s32 arg0) {
    s32 *segment = (s32 *)0x00730000;
    segment[0x71E] = arg0;
    return segment;
}
/* measured: sw uses $v0 base because zero-lo segment is the live return (void store colors $v1, nd 2; returning 0x00731C78 adds ori, nd 3); schedule on fills the jr delay slot (nd 3 -> 0, tail nop is padding) */
#pragma schedule off


#pragma schedule on

#pragma schedule off


#pragma schedule on

#pragma schedule off


#pragma schedule on

#pragma schedule off


#pragma schedule on

#pragma schedule off


#pragma schedule on

#pragma schedule off


#pragma schedule on

#pragma schedule off

// FUN_004E4698
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4698);
// FUN_004E46F0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e46f0);
// FUN_004E4700
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4700);
// FUN_004E4738
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4738);
// FUN_004E4770
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4770);
// FUN_004E47F8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e47f8);
// FUN_004E48B0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e48b0);
// FUN_004E4928
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4928);
// FUN_004E4990
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4990);
// FUN_004E49E8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e49e8);
// FUN_004E4A60
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4a60);
/* measured: schedule on moves the byte load into the jr delay slot. */
#pragma schedule on
// FUN_004E4DC8
s8 func_004e4dc8(u8 *arg0)
{
    return *(s8 *)(arg0 + 1);
}
/* measured: closes the schedule-on tiny accessor scope. */
#pragma schedule off
// FUN_004E4DD0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4dd0);
// FUN_004E4E90
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4e90);
/* measured: schedule on keeps the store in the jr return delay slot. */
#pragma schedule on
// FUN_004E4EF8
s32 func_004e4ef8(void)
{
    u8 *base = (u8 *)D_00731C84;
    s32 *slot = (s32 *)(base + 0);
    s32 value = *slot;
    value -= 1;
    *slot = value;
    return value;
}
/* measured: close schedule-on scope after func_004e4ef8. */
#pragma schedule off
// FUN_004E4F10
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4f10);
// FUN_004E5000
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e5000);
// FUN_004E76F8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e76f8);
// FUN_004E77C0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e77c0);
// FUN_004E7978
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7978);
/* Known floor: standalone R5900 movz in func_004e7a00; b210 cannot emit it. */
// FUN_004E7A00
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7a00);
// FUN_004E7A38
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7a38);
// FUN_004E7A58
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7a58);
// FUN_004E7BD0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7bd0);
// FUN_004E7C70
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7c70);
// FUN_004E7D08
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7d08);
// FUN_004E7D40
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7d40);
// FUN_004E7ED0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7ed0);
// FUN_004E7FC8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e7fc8);
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_004E8000
s32 func_004e8000(void)
{
    return 0x800;
}
/* measured: closes the schedule-on constant-return scope. */
#pragma schedule off
// FUN_004E8008
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e8008);
// FUN_004E8058
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e8058);
// FUN_004E80E0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e80e0);
// FUN_004E8110
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e8110);
// FUN_004E81D8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e81d8);
// FUN_004E8248
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e8248);
// FUN_004E82A0
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e82a0);