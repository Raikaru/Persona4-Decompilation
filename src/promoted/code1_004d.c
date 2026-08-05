#include "include_asm.h"
#include "type.h"


/* measured: #pragma schedule on is load-bearing -- retail sinks the second
 * sw into the jr return delay slot; O2 alone emits sw/sw/jr/nop (nd 6). */
#pragma schedule on

// FUN_004D12A0
void func_004d12a0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x60) = arg1;
    *(s32 *)(arg0 + 0x3C) = arg1;
}
#pragma schedule off


/* measured: #pragma schedule on is load-bearing (delay-slot fill, nd 3
 * without it); retail's $v0 base is the live return value, so the store
 * must return the zero-lo segment base: a void store colors the address
 * $v1 (nd 2), returning the base folds the sw into 0x3F10($v0) and the
 * object matches byte-for-byte (tail nop is all-zero window padding). */
#pragma schedule on

// FUN_004D18D8
s32 *func_004d18d8(s32 arg0)
{
    s32 *segment = (s32 *)0x00720000;
    segment[0xFC4] = arg0;
    return segment;
}
#pragma schedule off


extern s32 D_00723F20[];

/* measured: #pragma schedule on is load-bearing (delay-slot fill);
 * retail's $v0 base is the live return value, so the store returns the
 * zero-lo segment base: a void store colors the address $v1 (nd 2),
 * returning the base folds the sw into 0x3F20($v0) and the object
 * matches byte-for-byte (tail nop is all-zero window padding). */
#pragma schedule on

// FUN_004D3148
s32 *func_004d3148(s32 arg0)
{
    s32 *segment = (s32 *)0x00720000;
    segment[0xFC8] = arg0;
    return segment;
}
#pragma schedule off


extern s32 D_00723F20[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Re-probed here today: old-style () prototype, #pragma peephole
 * off, #pragma optimize_level 1 -- all nd 2. Same tree-wide floor as
 * code1_004e func_004e3da8/3db8/4180/4280/4290/4688 (16 spellings tried
 * there, all nd 2; 19 accessors tree-wide, none matched). NONMATCHING */
#pragma schedule on

/* measured: schedule on keeps the lw in the jr delay slot (without it the
 * delay slot is unfilled, nd 3). */
#pragma schedule off


extern s32 D_00724E58[];

/* measured: #pragma schedule on is load-bearing (delay-slot fill);
 * retail's $v0 base is the live return value, so the store returns the
 * zero-lo segment base: a void store colors the address $v1 (nd 2),
 * returning the base folds the sw into 0x4E58($v0) and the object
 * matches byte-for-byte (tail nop is all-zero window padding). */
#pragma schedule on

// FUN_004D3678
s32 *func_004d3678(s32 arg0)
{
    s32 *segment = (s32 *)0x00720000;
    segment[0x1396] = arg0;
    return segment;
}
#pragma schedule off


extern s32 D_00724E58[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Same tree-wide floor as code1_004e func_004e3da8/3db8/4180/
 * 4280/4290/4688 (16 spellings tried there, all nd 2; 19 accessors
 * tree-wide, none matched). NONMATCHING */
#pragma schedule on

/* measured: schedule on keeps the lw in the jr delay slot (without it the
 * delay slot is unfilled, nd 3). */
#pragma schedule off


extern s32 D_00724E60[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Same tree-wide floor as code1_004e func_004e3da8/3db8/4180/
 * 4280/4290/4688 (16 spellings tried there, all nd 2; 19 accessors
 * tree-wide, none matched). NONMATCHING */
#pragma schedule on

/* measured: schedule on keeps the lw in the jr delay slot (without it the
 * delay slot is unfilled, nd 3). */
#pragma schedule off


extern s32 D_00724E60[];

/* measured: #pragma schedule on is load-bearing (delay-slot fill);
 * retail's $v0 base is the live return value, so the store returns the
 * zero-lo segment base: a void store colors the address $v1 (nd 2),
 * returning the base folds the sw into 0x4E60($v0) and the object
 * matches byte-for-byte (tail nop is all-zero window padding). */
#pragma schedule on

// FUN_004D36A8
s32 *func_004d36a8(s32 arg0)
{
    s32 *segment = (s32 *)0x00720000;
    segment[0x1398] = arg0;
    return segment;
}
#pragma schedule off


/* measured: #pragma schedule on is load-bearing for the sw-in-return-delay-
 * slot placement (without it mwcc emits addiu/sw/jr/nop, nd 3). Returning
 * the stored constant 1 makes mwcc materialize it in $v0 (a void return
 * colors it $v1, nd 2), so the stored value doubles as the return value
 * and no extra instruction is needed. */
#pragma schedule on

// FUN_004DE2B0
s32 func_004de2b0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = 1;
    return 1;
}
#pragma schedule off
