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

// FUN_0052C870
u32 func_0052c870(u32 arg0)
{
    u32 segment = 0x00740000;

    *(u32 *)(segment + 0x613C) = arg0;
    return segment;
}
#pragma schedule off
