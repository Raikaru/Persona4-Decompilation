#include "include_asm.h"
#include "type.h"

extern s32 D_00745AF8[];

extern s32 D_00745ABC[];

extern s32 D_007609B0[];

extern s32 D_00745C84[];

extern s32 D_00745C6C[];

extern s32 D_0074613C[];


/* measured: void store colors the address scratch $v1 (lui $v1/sw/jr/nop,
 * delay slot unfilled); retail is lui $v0 / jr $ra / sw-in-delay-slot with
 * the base doubling as the returned segment. Returned-base local (segment +
 * 0x5AF8 store, return segment) forces $v0; #pragma schedule on fills slot. */
#pragma schedule on

// FUN_00520068
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520068);
// FUN_005200B8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005200b8);
// FUN_00520138
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520138);
// FUN_00520338
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520338);
// FUN_00520438
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520438);
// FUN_00520750
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520750);
// FUN_005207A8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005207a8);
// FUN_005207F8
u32 func_005207f8(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x5AF8) = arg0;
    return segment;
}
#pragma schedule off


/* measured: void store colors the address scratch $v1 (lui $v1/sw/jr/nop,
 * delay slot unfilled); retail is lui $v0 / jr $ra / sw-in-delay-slot with
 * the base doubling as the returned segment. Returned-base local (segment +
 * 0x5ABC store, return segment) forces $v0; #pragma schedule on fills slot. */
#pragma schedule on

// FUN_00522FD0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00522fd0);
// FUN_00522FF8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00522ff8);
// FUN_00523050
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523050);
// FUN_005230B8
u32 func_005230b8(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x5ABC) = arg0;
    return segment;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: b210 O2 emits lui/addiu/jr/nop (unfilled return delay slot);
 * retail is lui $v0 / jr $ra / addiu $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill. */
#pragma schedule on

// FUN_005230D8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230d8);
// FUN_00523138
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523138);
// FUN_00523508
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523508);
// FUN_00523578
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523578);
// FUN_005235F8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005235f8);
// FUN_005242D0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005242d0);
// FUN_00524318
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524318);
// FUN_00524480
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524480);
// FUN_00524500
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524500);
// FUN_005245A0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005245a0);
// FUN_00524610
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524610);
// FUN_00524680
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524680);
// FUN_00524720
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524720);
// FUN_00524770
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524770);
// FUN_00524778
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524778);
// FUN_00524820
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524820);
// FUN_005248A8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005248a8);
// FUN_005248B8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005248b8);
// FUN_005249B0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005249b0);
// FUN_00524A20
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524a20);
// FUN_00524AA8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524aa8);
// FUN_00524B18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524b18);
// FUN_00524B78
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524b78);
// FUN_00528C30
s32 *func_00528c30(void)
{
    return D_007609B0;
}
#pragma schedule off


/* measured: void store colors the address scratch $v1 (lui $v1/sw/jr/nop,
 * delay slot unfilled); retail is lui $v0 / jr $ra / sw-in-delay-slot with
 * the base doubling as the returned segment. Returned-base local (segment +
 * 0x5C84 store, return segment) forces $v0; #pragma schedule on fills slot. */
#pragma schedule on

// FUN_0052B950
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b950);
// FUN_0052B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9a0);
// FUN_0052B9E0
u32 func_0052b9e0(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x5C84) = arg0;
    return segment;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: void store colors the address scratch $v1 (lui $v1/sw/jr/nop,
 * delay slot unfilled); retail is lui $v0 / jr $ra / sw-in-delay-slot with
 * the base doubling as the returned segment. Returned-base local (segment +
 * 0x5C6C store, return segment) forces $v0; #pragma schedule on fills slot. */
#pragma schedule on

// FUN_0052BA00
u32 func_0052ba00(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x5C6C) = arg0;
    return segment;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: void store colors the address scratch $v1 (lui $v1/sw/jr/nop,
 * delay slot unfilled); retail is lui $v0 / jr $ra / sw-in-delay-slot with
 * the base doubling as the returned segment. Returned-base local (segment +
 * 0x613C store, return segment) forces $v0; #pragma schedule on fills slot. */
#pragma schedule on

// FUN_0052BA20
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba20);
// FUN_0052BA30
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba30);
// FUN_0052C840
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c840);
// FUN_0052C870
u32 func_0052c870(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x613C) = arg0;
    return segment;
}
#pragma schedule off

// FUN_0052C880
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c880);
// FUN_0052C890
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c890);
// FUN_0052C8E0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c8e0);
// FUN_0052C930
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c930);
// FUN_0052C980
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c980);
// FUN_0052CAB0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cab0);
// FUN_0052CC18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cc18);
// FUN_0052CD18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cd18);
// FUN_0052D9A0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052d9a0);