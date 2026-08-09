#include "include_asm.h"
#include "type.h"
extern s32 D_0072ACC0[];
extern s32 D_00758C58[];
extern s32 D_007597C8[];
extern s32 D_00759890[];
extern s32 D_007598C0[];
extern s32 D_007598F0[];
extern s32 D_00759920[];
extern s32 D_007599B0[];
extern s32 D_00759A10[];

/* Retail saves callee-saved $s registers with sd; MWCCPS2 3.0.1 emits sq;
 * toolchain-blocked, see build/ORCH_sd_toolchain_blocked.txt. */
/* measured: #pragma schedule on is load-bearing -- retail sinks the second
 * sw into the jr return delay slot; O2 alone emits sw/sw/jr/nop (nd 6). */
#pragma schedule on

// FUN_004D12A0
void func_004d12a0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x60) = arg1;
    *(s32 *)(arg0 + 0x3C) = arg1;
}
/* measured: close schedule-on bracket after func_004d12a0. */
#pragma schedule off



/* Framed tail-jump floor (measured): the 24-byte ASM tier has three retail
 * variants. Plain: 004D1880, 004D1898, 004D18B0, 004D3528, 004D3540,
 * 004D3558, 004D3570, 004D36E8, 004D3738, 004D3F90, 004DE2C0.
 * Load-then-tail: 004DE168, 004DE180, 004DE198, 004DE1B0, 004DE1C8,
 * 004DE218, 004DE230, 004DE248, 004DE260, 004DE278, 004DE290.
 * Move-arg: 004D32E0. b210 emits 8, 28, or 32 bytes for these spellings;
 * leave all 23 INCLUDE_ASM fallbacks bare. */
// FUN_004D15D8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d15d8);
// FUN_004D1748
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d1748);
// FUN_004D17E0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d17e0);
// FUN_004D1820
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d1820);
// FUN_004D1880
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d1880);
// FUN_004D1898
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d1898);
// FUN_004D18B0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d18b0);
// FUN_004D18C8
void func_004d18c8(void)
{
}
// FUN_004D18D0
void func_004d18d0(void)
{
}
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
/* measured: close schedule-on bracket after func_004d18d8. */
#pragma schedule off


extern s32 D_00723F20[];


// FUN_004D30B8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d30b8);
// FUN_004D30F8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d30f8);
// FUN_004D3118
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3118);
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
/* measured: close schedule-on bracket after func_004d3148. */
#pragma schedule off


extern s32 D_00723F20[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Re-probed here today: old-style () prototype, #pragma peephole
 * off, #pragma optimize_level 1 -- all nd 2. Same tree-wide floor as
 * code1_004e func_004e3da8/3db8/4180/4280/4290/4688 (16 spellings tried
 * there, all nd 2; 19 accessors tree-wide, none matched). NONMATCHING */


extern s32 D_00724E58[];


// FUN_004D3158
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3158);
// FUN_004D31A0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d31a0);
// FUN_004D31D8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d31d8);
// FUN_004D31E8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d31e8);
/* measured: schedule on preserves the retail return delay-slot fill. */
#pragma schedule on
// FUN_004D3220
s8 func_004d3220(u8 *arg0)
{
    return *(s8 *)(arg0 + 2);
}
/* measured: close schedule-on bracket after func_004d3220. */
#pragma schedule off
// FUN_004D3228
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3228);
// FUN_004D3258
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3258);
// FUN_004D32E0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d32e0);
// FUN_004D32F8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d32f8);
// FUN_004D33F8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d33f8);
// FUN_004D3458
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3458);
// FUN_004D34C0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d34c0);
// FUN_004D3528
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3528);
// FUN_004D3540
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3540);
// FUN_004D3558
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3558);
// FUN_004D3570
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3570);
// FUN_004D3588
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3588);
// FUN_004D35D8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d35d8);
// FUN_004D3628
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3628);
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
/* measured: close schedule-on bracket after func_004d3678. */
#pragma schedule off


extern s32 D_00724E58[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Same tree-wide floor as code1_004e func_004e3da8/3db8/4180/
 * 4280/4290/4688 (16 spellings tried there, all nd 2; 19 accessors
 * tree-wide, none matched). NONMATCHING */


extern s32 D_00724E60[];

/* measured (2026-08-03): nd 2 (verify normalized_diff; fndiff reports 3
 * including the all-zero padding nop) = global-address base register only:
 * retail lui $v1 + lw $v0, b210 always lui $v0 + lw $v0 (base reuses
 * $v0). Same tree-wide floor as code1_004e func_004e3da8/3db8/4180/
 * 4280/4290/4688 (16 spellings tried there, all nd 2; 19 accessors
 * tree-wide, none matched). NONMATCHING */


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
/* measured: close schedule-on bracket after func_004d36a8. */
#pragma schedule off


/* measured: #pragma schedule on is load-bearing for the sw-in-return-delay-
 * slot placement (without it mwcc emits addiu/sw/jr/nop, nd 3). Returning
 * the stored constant 1 makes mwcc materialize it in $v0 (a void return
 * colors it $v1, nd 2), so the stored value doubles as the return value
 * and no extra instruction is needed. */

// FUN_004D36B8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d36b8);
// FUN_004D36E8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d36e8);
// FUN_004D3700
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3700);
// FUN_004D3738
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3738);
// FUN_004D3750
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3750);
// FUN_004D3850
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3850);
// FUN_004D38A8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d38a8);
// FUN_004D3BC0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3bc0);
// FUN_004D3C08
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3c08);
// FUN_004D3C60
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3c60);
// FUN_004D3C88
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3c88);
// FUN_004D3CB0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3cb0);
// FUN_004D3CD8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3cd8);
// FUN_004D3D08
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3d08);
// FUN_004D3EE0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3ee0);
// FUN_004D3F08
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3f08);
// FUN_004D3F68
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3f68);
// FUN_004D3F90
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3f90);
// FUN_004D3FA8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3fa8);
// FUN_004D40A0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d40a0);
// FUN_004D4170
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4170);
// FUN_004D41B0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d41b0);
// FUN_004D4238
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4238);
// FUN_004D4268
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4268);
// FUN_004D4308
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4308);
// FUN_004D4338
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4338);
// FUN_004D43F8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d43f8);
/* measured: optimization level 3 reproduces the null-accessor branch shape. */
#pragma optimization_level 3
// FUN_004D4430
s8 func_004d4430(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004c6a98(D_00758C58);
        return -1;
    }
    return *(s8 *)(arg0 + 1);
}
/* measured: restore optimization level 2 after func_004d4430. */
#pragma optimization_level 2
// FUN_004D4460
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4460);
// FUN_004D4490
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4490);
// FUN_004D44C8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d44c8);
// FUN_004D4518
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4518);
// FUN_004D45E0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d45e0);
// FUN_004D4630
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d4630);
// FUN_004DE168
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de168);
// FUN_004DE180
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de180);
// FUN_004DE198
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de198);
// FUN_004DE1B0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de1b0);
// FUN_004DE1C8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de1c8);
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE1E0
s32 func_004de1e0(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de1e0. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE1E8
s32 func_004de1e8(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de1e8. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE1F0
s32 func_004de1f0(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de1f0. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE1F8
s32 func_004de1f8(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de1f8. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE200
s32 func_004de200(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de200. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE208
s32 func_004de208(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de208. */
#pragma schedule off
/* measured: schedule on preserves the retail zero-return delay-slot fill. */
#pragma schedule on
// FUN_004DE210
s32 func_004de210(void)
{
    return 0;
}
/* measured: close schedule-on bracket after func_004de210. */
#pragma schedule off
// FUN_004DE218
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de218);
// FUN_004DE230
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de230);
// FUN_004DE248
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de248);
// FUN_004DE260
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de260);
// FUN_004DE278
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de278);
// FUN_004DE290
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de290);
/* measured: schedule on preserves the retail store/return delay-slot fill. */
#pragma schedule on
// FUN_004DE2A8
void func_004de2a8(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x2C) = arg1;
}
/* measured: close schedule-on bracket after func_004de2a8. */
#pragma schedule off
/* measured: schedule on preserves the retail store/return delay-slot fill. */
#pragma schedule on
// FUN_004DE2B0
s32 func_004de2b0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = 1;
    return 1;
}
/* measured: close schedule-on bracket after func_004de2b0. */
#pragma schedule off

// FUN_004DE2C0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de2c0);
/* measured: schedule on keeps the global store in the jr delay slot. */
#pragma schedule on
// FUN_004DE2D8
s32 *func_004de2d8(s32 arg0)
{
    s32 *segment = (s32 *)0x00730000;
    *(s32 *)((u8 *)segment - 0x5340) = arg0;
    return segment;
}
/* measured: close schedule-on probe after func_004de2d8. */
#pragma schedule off
// FUN_004DE2E8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de2e8);
/* measured: schedule on places the zero return in the jr delay slot. */
#pragma schedule on
// FUN_004DE310
s32 func_004de310(void)
{
    return 0;
}
/* measured: close schedule-on probe after func_004de310. */
#pragma schedule off
// FUN_004DE318
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de318);
// FUN_004DE340
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de340);
// FUN_004DE3F0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de3f0);
// FUN_004DE4C0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de4c0);
// FUN_004DE540
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de540);
// FUN_004DE5C0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de5c0);
// FUN_004DE860
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de860);
// FUN_004DE998
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de998);
// FUN_004DE9F8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004de9f8);
// FUN_004DEB38
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004deb38);
// FUN_004DEB58
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004deb58);
// FUN_004DEC30
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dec30);
// FUN_004DECB8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004decb8);
// FUN_004DED60
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004ded60);
/* measured: optimization level 3 reproduces the null-accessor branch shape. */
#pragma optimization_level 3
// FUN_004DEE18
s8 func_004dee18(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004de2c0(D_007597C8);
        return -1;
    }
    return *(s8 *)(arg0 + 1);
}
/* measured: restore optimization level 2 after func_004dee18. */
#pragma optimization_level 2
// FUN_004DEE48
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dee48);
// FUN_004DEEC0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004deec0);
// FUN_004DEF18
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004def18);
// FUN_004DEFA0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004defa0);
// FUN_004DEFE8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004defe8);
// FUN_004DF068
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df068);
// FUN_004DF098
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df098);
// FUN_004DF0C8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df0c8);
/* measured: optimization level 3 reproduces the null-accessor branch shape. */
#pragma optimization_level 3
// FUN_004DF0F8
s32 func_004df0f8(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004de2c0(D_00759920);
        return -1;
    }
    return *(s32 *)(arg0 + 0x1C0);
}
/* measured: restore optimization level 2 after func_004df0f8. */
#pragma optimization_level 2
// FUN_004DF128
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df128);
// FUN_004DF1A0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df1a0);
/* measured: optimization level 3 reproduces the null-accessor branch shape. */
#pragma optimization_level 3
// FUN_004DF1F0
s32 func_004df1f0(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004de2c0(D_007599B0);
        return 0;
    }
    return *(s32 *)(arg0 + 0x90);
}
/* measured: restore optimization level 2 after func_004df1f0. */
#pragma optimization_level 2
// FUN_004DF220
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df220);
// FUN_004DF260
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df260);
/* measured: optimization level 3 reproduces the null-accessor branch shape. */
#pragma optimization_level 3
// FUN_004DF2E8
s32 func_004df2e8(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004de2c0(D_00759A10);
        return 0;
    }
    return *(s32 *)(arg0 + 0x1A8);
}
/* measured: restore optimization level 2 after func_004df2e8. */
#pragma optimization_level 2
// FUN_004DF318
void func_004df318(void)
{
}
// FUN_004DF320
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df320);
// FUN_004DF3C0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df3c0);
// FUN_004DF418
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df418);
// FUN_004DF470
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df470);
// FUN_004DF4C8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df4c8);
// FUN_004DF5B0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df5b0);
// FUN_004DF708
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df708);
// FUN_004DF800
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df800);
// FUN_004DF850
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004df850);
// FUN_004DFC38
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfc38);
// FUN_004DFC98
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfc98);
// FUN_004DFCD8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfcd8);
// FUN_004DFD78
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfd78);
// FUN_004DFDC8
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfdc8);
// FUN_004DFE38
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfe38);
// FUN_004DFE60
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfe60);
// FUN_004DFF78
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dff78);
// FUN_004DFFF0
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004dfff0);