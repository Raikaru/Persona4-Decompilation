#include "include_asm.h"
#include "type.h"

/* Preserve source operand order in the camera's height products. */
static inline f32 p4_cacd0_mul(f32 left, f32 right)
{
    return left * right;
}

typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct RwV3d RwV3d;
typedef struct RwMatrixTag RwMatrix;
typedef struct RtQuat RtQuat;

struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
};

struct RwMatrixTag {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
};

extern void func_001bdeb0();
extern void func_001c9820(u8 *arg0, s32 arg1, s32 arg2, f32 arg3);
extern void func_001ce620(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001ce8c0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001b73f0(u8 *arg0);
extern void func_004b3110(s32 arg0);
extern void func_001bab00(u8 *arg0, void *arg1);
extern void func_001c6f40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
extern void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 func_003e40b0(RwV3d *arg0, const RwV3d *arg1);
extern f32 func_003e4180(f32 *arg0);
extern void func_001bd560();
extern void func_001958f0(u8 *arg0, f32 *arg1);
extern void func_001959d0(BtlUnit *arg0, RwV3d *arg1);
extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, void *outCenter, f32 *outTop, f32 *outBottom, u32 options);
extern RwMatrix *func_003e0870(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern void func_001bc3a0(f32 *arg0, f32 *arg1);
extern f32 tanf(f32 arg0);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void func_001bcd40(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, u16 arg4);
extern void func_001ca590(u8 *arg0, f32 arg1, f32 arg2);
extern void func_001cacd0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_0019de70(BtlUnitStateWork *work, u16 value);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern s16 func_001d7f10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_001d8df0(u8 *arg0);
extern u8 *func_001d8bc0(u8 *arg0);
extern void func_001c79f0(u8 *arg0, s32 arg1);
extern void func_001c80f0(u8 *arg0, s32 arg1);
extern void func_001c8b00(u8 *arg0);
extern void func_001bd4f0(u8 *arg0);
extern void func_001bd530(u8 *arg0);
extern u8 *func_00457120(void);
extern void func_001c8e90(u8 *arg0, f32 *arg1, f32 *arg2);
extern void func_001bac20(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_004bd050(s32 arg0);
extern s16 func_001991c0(u8 *arg0, s32 arg1, f32 arg2);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 func_001f0ff0(u8 *arg0);
extern void func_001c2ee0(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 func_00231d70(u32 arg0);
extern s32 func_001bc140(u8 *arg0);
extern s32 func_001eb440(u8 *arg0);
extern s32 func_001f1030(u8 *arg0);
extern s32 func_001f11e0(s16 arg0);
extern s32 func_001f1210(s32 arg0, s16 arg1, s32 arg2);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern s32 func_0022f950(u8 *arg0, u8 *arg1);
extern void func_00194fa0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern RwMatrix *func_003e0870(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern u8 D_0060A0D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern u8 D_0060A100[];
extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
extern f32 func_001ec250(f32 *arg0, u8 *arg1);
extern s32 func_0044dcd8(f32 arg0);
extern s32 func_0044b310(s32 arg0);
extern f32 func_0044e7d8(s32 arg0);
extern f32 fGpffff819c;
extern u8 D_00607DD0[];
extern u8 D_00607DD8[];
extern f32 D_00607DDC[];
extern f32 D_00607DE0[];
extern f32 D_00607DE4[];
extern f32 D_00607DF0[];
extern f32 D_00607DFC[];
extern f32 D_00607E10[];
extern f32 D_00607E14[];
extern f32 D_00607E18[];
extern f32 D_00607E1C[];
extern f32 D_00607E20[];
extern f32 D_00607E24[];
extern f32 D_00607E30[];
extern f32 D_00607E3C[];
extern u16 *func_001d0730(s32 arg0, s32 arg1);
extern RwV3d *func_003dcb40(RwV3d *arg0, const RwV3d *arg1, s32 arg2, const RtQuat *arg3);
extern void func_001c1040(u8 *arg0, s32 arg1);
extern void func_001c17a0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001c21d0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001c3f70(u8 *arg0, s32 arg1, s32 arg2);
static inline f32 func_001c_mul_add(f32 arg0, f32 arg1, f32 arg2)
{
    return arg0 * arg1 + arg2;
}
static inline void func_001c_copy_pair(s64 *arg0, f32 *arg1,
                                       s64 *arg2, f32 *arg3)
{
    s64 pair;
    f32 value;

    pair = *arg2;
    value = *arg3;
    *arg0 = pair;
    *arg1 = value;
}
static inline void func_001c_rotate(RwMatrix *arg0, const RwV3d *arg1,
                                    f32 arg2, s32 arg3)
{
    func_003e0870(arg0, arg1, arg2, arg3);
}

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Camera-track floor (1216B window; obj 876B fndiff 248 verify 594; width check 2026-09-17:
   no dsll/dsra pairs, clean; frame -0xD0 vs -0x130 retail, saved-reg set verified, stack
   layout divergent (packed vs spread)). Open: frame layout, madd/msub fusion, scheduler
   ordering. Triple-built (m2c+IDA+Ghidra, retail-arbitrated: 1bcd40 TU-decl order,
   0.5-first 44b868, max-form update). Prior 263 now 248; reproducible with --candidate.
*/
// FUN_001C04E0 NONMATCHING
#ifdef NON_MATCHING
void func_001c04e0(u8 *arg0)
{
    extern void func_001bd5a0();
    extern f32 func_001ec3d0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868();
    extern u8 D_0060A100[];
    extern f32 iGpffff80fc;
    extern f32 iGpffff8030;
    extern f32 iGpffff8110;
    f32 sp120;
    f32 sp124;
    f32 sp128;
    f32 sp110;
    f32 sp114;
    f32 sp118;
    f32 spE0;
    f32 spE4;
    f32 spE8;
    f32 spA8;
    f32 spAC;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f25;
    f32 spF0;
    f32 spF4;
    f32 spF8;
    f32 sp108;
    f32 spA0;
    f32 spA4;
    f32 spD4;
    f32 spCC;
    f32 spD0;
    f32 spD8;
    f32 spB0;
    f32 spB4;
    f32 spB8;
    f32 spBC;
    f32 spC8;
    f32 spC0;
    f32 spC4;
    f32 ec3ret;
    f32 fblend;
    f32 fdiv;
    f32 var_f2;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    s64 sp100;
    u8 pbuf[20];
    u8 dbuf[32];
    u8 *iVar3;
    u8 *iVar1;

    iVar3 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    iVar1 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x38) + 0x30);
    func_00195850(iVar3, &sp120);
    func_00195850(iVar1, &sp110);
    temp_f23 = *(f32 *)(iVar3 + 0x90) * *(f32 *)(iVar3 + 0x2C);
    temp_f22 = *(f32 *)(iVar1 + 0x90) * *(f32 *)(iVar1 + 0x2C);
    spE0 = sp120 - sp110;
    spE4 = sp124 - sp114;
    spE8 = sp128 - sp118;
    temp_f25 = func_003e40b0((RwV3d *)&spE0, (const RwV3d *)&spE0);
    spA8 = *(f32 *)(arg0 + 0x9C) - sp120;
    spAC = *(f32 *)(arg0 + 0xA4) - sp128;
    func_003e41e0(&spA8, &spA8);
    temp_f25 = iGpffff80fc * temp_f25;
    spA0 = spE8;
    spA4 = -spE0;
    spF0 = spE0 * temp_f25 + sp110;
    spF4 = spE4 * temp_f25 + sp114;
    spF8 = spE8 * temp_f25 + sp118;
    if (0.0f <= spE0 * spA8 + spE8 * spAC) {
        sp100 = *(s64 *)&sp120;
        sp108 = sp128;
        if (*(f32 *)((u8 *)&sp100 + 4) < 125.0f) {
            *(f32 *)((u8 *)&sp100 + 4) = 125.0f;
        }
    } else {
        sp100 = *(s64 *)&sp110;
        sp108 = sp118;
    }
    spA0 = spE8;
    spA4 = -spE0;
    spD0 = iGpffff8030 * *(f32 *)(iVar3 + 0x8C) * *(f32 *)(iVar3 + 0x2C) + *(f32 *)((u8 *)&sp100 + 4);
    if (0.0f <= spE8 * spA8 + spA4 * spAC) {
        spD0 = spA4 + spE8 * temp_f25;
        spD8 = spA0 + spE0 * temp_f25;
    } else {
        spD0 = spA0 - spE8 * temp_f25;
        spD8 = spA4 + spE0 * temp_f25;
    }
    func_001bd780(pbuf, &spD0, &spF0, D_0060A0E0);
    func_003dcb40((RwV3d *)&spE0, (const RwV3d *)D_0060A100, 1, (const RtQuat *)pbuf);
    spB0 = spF0;
    spB4 = spF8;
    spB8 = spD0;
    spBC = spD8;
    spC8 = *(f32 *)&sp100;
    spCC = sp108;
    ec3ret = func_001ec3d0(&spB0, &spB8, &spC8, &spC0);
    spD0 = spC0;
    spD4 = *(f32 *)((u8 *)&sp100 + 4);
    spD4 = *(f32 *)((u8 *)&sp100 + 4);
    spD8 = spC4;
    fblend = (*(f32 *)(iVar3 + 0x90) * *(f32 *)(iVar3 + 0x2C)) * 2.25f + ec3ret;
    fdiv = func_0044b868(iGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    var_f2 = 500.0f;
    if (500.0f <= fblend / fdiv) {
        var_f2 = fblend / fdiv;
    }
    spE0 = spE0 * var_f2;
    spE4 = spE4 * var_f2;
    spE8 = spE8 * var_f2;
    sp80 = spD0 + spE0;
    sp84 = spD4 + spE4;
    sp88 = spD8 + spE8;
    if (sp84 < 25.0f) {
        sp84 = 25.0f;
    }
    func_001bd5a0(arg0 + 0x9C, &sp80);
    func_001c8e90(arg0, &sp80, (f32 *)dbuf);
    func_001bab00(arg0, dbuf);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, arg0 + 0x100, 0.5f * ((temp_f25 + temp_f23) + temp_f22), 3);
    if (temp_f23 <= temp_f22) {
        temp_f23 = temp_f22;
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), (u8 *)&sp120, (u8 *)&sp110, temp_f23, 3);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c04e0);
#endif
// FUN_001C09A0
void func_001c09a0(void) {}
/* Sine-poly camera floor (1168B window; obj 900B fndiff 261 verify 654; width check
   2026-09-17: no dsll/dsra pairs, clean; frame -0x80 vs -0xF0 retail, thinner). Open:
   accumulator-chain fusion (mula/madd/adda/msub un-emittable in plain C), saved-reg
   pressure, scheduler ordering. Chains decoded from retail to zero-seeded Horner sine
   polys (coeffs iGpffff8054-8108/8180); closed forms cross-checked against IDA Hex-Rays
   + Ghidra bodies. Spill model: 1bd560 writes sp40+, 1ec2b0 writes sp4C..spA4, 1bd780
   writes sp68+, 3dcc70 writes sp80..sp9C. +0.0f ACC seeds measured worse. Prior 273 now
   261 with current tree; numbers reproducible with --candidate on extracted body.
*/
// FUN_001C09B0 NONMATCHING
#ifdef NON_MATCHING
void func_001c09b0(u8 *arg0)
{
    extern f32 iGpffff8054;
    extern f32 iGpffff8058;
    extern f32 iGpffff805C;
    extern f32 iGpffff8060;
    extern f32 iGpffff8108;
    extern f32 iGpffff8180;
    extern f32 iGpffff8118;
    extern f32 iGpffff815C;
    extern f32 iGpffff804C;
    extern f32 iGpffff8160;
    extern f32 iGpffff8110;
    extern f32 iGpffff818C;
    extern f32 func_001ec2b0();
    extern f32 func_0044b868();
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_003dc740(u8 *arg0, u8 *arg1, s32 arg2, f32 farg);
    extern u8 D_0060A100[];
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 sp80;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp4C;
    f32 sp48;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp6C;
    f32 sp70;
    f32 sp74;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 sp9C;
    f32 spDC;
    f32 spA0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 chA;
    f32 chB;
    f32 tA;
    f32 xA;
    f32 tB;
    f32 xB;
    f32 f20poly;
    f32 temp_t;
    s64 spD8;
    s64 sp40;
    s32 spA4;
    u8 *temp_17;

    temp_17 = (*(u8 **)((u8 *)(*(u8 **)(arg0 + 0xE0)) + 0x30));
    func_001bd560(&sp40, arg0 + 0x9C);
    func_00194ff0(temp_17, &spC8, 0, 0);
    temp_t = *(f32 *)(temp_17 + 0x2C);
    spCC = *(f32 *)(temp_17 + 0x84) * temp_t + iGpffff8118 * (*(f32 *)(temp_17 + 0x8C) * temp_t);
    spD8 = sp40;
    spE0 = sp48;
    spDC = spCC;
    func_001bd780(&sp68, &spD8, &spC8, D_0060A0E0);
    temp_f0 = func_001ec2b0(&sp4C, &sp68);
    temp_f1_2 = (f32)(s32)iGpffff815C;
    if (temp_f1_2 < temp_f0) {
        temp_f20 = temp_f1_2 / temp_f0;
        func_003dcc70(&sp4C, &sp68, &sp80);
        if (temp_f20 <= 0.0f) {
            spB0 = sp4C;
            spB4 = sp50;
            spB8 = sp54;
            spBC = sp58;
        } else if (temp_f20 >= 1.0f) {
            spB0 = sp68;
            spB4 = sp6C;
            spB8 = sp70;
            spBC = sp74;
        } else {
            var_f0 = 1.0f - temp_f20;
            /* spA0/spA4 arrive via the pre-chain call-spill region
               (1ec2b0 out-struct); m2c, IDA and Ghidra all read the
               slots with no in-function write. */
            if (spA4 == 0) {
                tA = var_f0 * spA0;
                xA = tA * tA;
                chA = iGpffff8054 + iGpffff8180 * xA;
                chA = iGpffff8058 + xA * chA;
                chA = iGpffff805C + xA * chA;
                chA = iGpffff8060 + xA * chA;
                chB = iGpffff8108 + xA * chA;
                var_f0 = tA + (xA * tA) * chB;
                tB = temp_f20 * spA0;
                xB = tB * tB;
                chA = iGpffff8054 + iGpffff8180 * xB;
                chA = iGpffff8058 + xB * chA;
                chA = iGpffff805C + xB * chA;
                chA = iGpffff8060 + xB * chA;
                chB = iGpffff8108 + xB * chA;
                f20poly = tB + (xB * tB) * chB;
            }
            spB0 = sp80 * var_f0;
            spB4 = sp84 * var_f0;
            spB8 = sp88 * var_f0;
            spB0 = spB0 + sp90 * f20poly;
            spB4 = spB4 + sp94 * f20poly;
            spB8 = spB8 + sp98 * f20poly;
            spBC = sp9C * f20poly + sp8C * var_f0;
        }
        func_003dcb40((RwV3d *)&spD8, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&spB0);
        *(f32 *)&spD8 = *(f32 *)&spD8 + spC8;
        spDC = spDC + spCC;
        spE0 = spE0 + spD0;
        func_001bd780(&sp68, &spD8, &spC8, D_0060A0E0);
    } else if (temp_f0 < iGpffff804C) {
        func_003dc740((u8 *)&sp68, D_0060A0E0, 2, iGpffff8160);
    }
    func_003dcb40((RwV3d *)&spD8, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&sp68);
    temp_f20_2 = (f32)0x177 / func_0044b868(iGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    temp_f0_2 = *(f32 *)&spD8 * temp_f20_2;
    *(f32 *)&spD8 = temp_f0_2;
    spDC = spDC * temp_f20_2;
    temp_f0_3 = spE0 * temp_f20_2;
    spE0 = temp_f0_3;
    f20poly = temp_f20_2 * func_0044b868(iGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f;
    spE8 = temp_f0_2;
    spEC = temp_f0_3;
    func_003e41e0(&spE8, &spE8);
    temp_f3 = spC8 + spEC * f20poly;
    spC8 = temp_f3;
    temp_f2 = spD0 - spE8 * f20poly;
    spD0 = temp_f2;
    sp5C = temp_f3 + *(f32 *)&spD8;
    temp_f1_3 = spCC + spDC;
    sp60 = temp_f1_3;
    sp64 = temp_f2 + spE0;
    if (temp_f1_3 < 25.0f) {
        sp60 = 25.0f;
    }
    func_001bac20((u16 *)arg0, (f32 *)&sp40, &sp5C, 1);
    func_001bbef0(arg0, iGpffff818C);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c09b0);
#endif
// FUN_001C0E40
void func_001c0e40(void) {}
// FUN_001C0E50
s32 func_001c0e50(u8 *arg0) {
    s16 mode;
    s32 state;
    s32 check;
    s32 result;
    u8 *work;
    u8 *data;
    u8 *other;

    work = *(u8 **)(arg0 + 0xE0);
    mode = *(s16 *)(work + 0x6E);
    if (func_001f0ff0(work) != 0) {
        data = *(u8 **)(arg0 + 0xE0);
        if (*(s32 *)(data + 0x38) == (s32)data) {
            return 1;
        }
        if (func_001bc140(arg0) != 0) {
            return 2;
        }
        if (func_001f11e0(mode) == 0) {
            return 2;
        }
        other = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        if ((*(u8 *)(other + 0xA2) == 0) &&
            (func_001f1210(*(s32 *)(other + 0xA0C), mode, 1) == 0)) {
            return 2;
        }
        return 4;
    }
    state = func_001eb440(*(u8 **)(arg0 + 0xE0) + 0x38) & 0xFFFF;
    if (((state & 3) == 3) ||
        (((check = *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64),
           check != 0) &&
          (func_00232710(check, 0x100) != 0)))) {
        return 6;
    }
    work = *(u8 **)(arg0 + 0xE0);
    if ((*(u8 *)(*(u8 **)(work + 0x30) + 0xA2) == 0) && ((state & 1) != 0)) {
        if (func_001f1030(work) != 0) {
            return 6;
        }
        data = *(u8 **)(arg0 + 0xE0);
        if (*(s32 *)(data + 0x38) == (s32)data) {
            return 1;
        }
        if (func_001f11e0(mode) != 0) {
            result = 4;
        } else {
            result = 2;
        }
        return result;
    }
    if (func_001f11e0(mode) == 0) {
        return 3;
    }
    return 5;
}
/* measured 001c1040: 298 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c1040` (GUARDED_SCORE 298); probe 298 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c1040 --candidate r1040=$HOME/cand_1040r.c`; fnalign retail 470 vs object 469 instrs, 197 edits (+8 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c1040 --candidate $HOME/cand_1040r.c --quiet`. Re-measured (archived note claimed 312/1876B; drifted). Repair to current contracts: block `extern f32 fGpffff8128/fGpffff807c/func_0044b868(f32)` (truthful float return, avoids mtc1/cvt cascade per 001c5500 171w lesson), (u8*)center.c/(s32)&top for six-arg func_00196040, (BtlUnitStateWork*)resource, (RwV3d*)/(RwMatrix*)/(u16*) casts per 001c79f0 idioms. Extern audit: func_00196040(s32,s32,u8*,s32,s32,s32)->f32 (mov.s $f0), func_0044b868(f32)->f32, func_003e40b0/4320/0870 (RwV3d/RwMatrix), func_0019de70(BtlUnitStateWork*,u16). Ordinary C emits both adda/madd+adda/msub pairs as mul/add (prior ASM-only claim false); residual is FPU-register/scheduling wall. Frame 0x150. */
// FUN_001C1040 NONMATCHING
#ifdef NON_MATCHING
void func_001c1040(u8 *arg0, s32 arg1)
{
    extern f32 fGpffff8128;
    extern f32 fGpffff807c;
    extern f32 func_0044b868(f32 arg0);
    union MotionVector {
        f32 c[3];
        struct { s64 xy; f32 z; } bits;
    } unitCenter, center, target, direction, delta, focus, flat1, flat2;
    f32 top;
    f32 horizontal[2];
    f32 matrix[16];
    f32 second[7];
    f32 first[7];
    f32 radius;
    f32 distance;
    f32 half;
    f32 angleScale;
    f32 side;
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    u8 *unit;
    u8 *resource;

    func_001bd560(first, arg0 + 0x9C);
    unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_00195850(unit, unitCenter.c);
    radius = func_00196040(3, 1, center.c, &top, 0, 0);
    if (func_001bc240(arg0) != 0 || func_001bc1b0(arg0) != 0) {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70((BtlUnitStateWork *)resource, 0);
            *(u8 **)(arg0 + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(arg0 + 0x130) = 1;
        }
        center.c[1] = 0.75f * top;
        unitCenter.c[1] = center.c[1];
        half = 0.5f;
        angleScale = fGpffff8110;
        distance = radius / func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)));
        if (distance < 1000.0f) distance = 1000.0f;
        if (center.c[0] == unitCenter.c[0] && center.c[2] == unitCenter.c[2]) {
            func_001c_copy_pair(&direction.bits.xy, &direction.bits.z,
                               (s64 *)D_0060A0F0, (f32 *)(D_0060A0F0 + 8));
        } else {
            direction.c[0] = center.c[0] - unitCenter.c[0];
            direction.c[1] = center.c[1] - unitCenter.c[1];
            direction.c[2] = center.c[2] - unitCenter.c[2];
            func_003e40b0((RwV3d *)direction.c, (const RwV3d *)direction.c);
        }
        x = direction.c[0] * radius;
        direction.c[0] = x;
        y = direction.c[1] * radius;
        direction.c[1] = y;
        z = direction.c[2] * radius;
        direction.c[2] = z;
        target.c[0] = center.c[0] + x;
        target.c[1] = center.c[1] + y;
        target.c[2] = center.c[2] + z;
        target.c[1] = 1.25f * top;
    } else {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70((BtlUnitStateWork *)resource, 0);
            *(u8 **)(arg0 + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(arg0 + 0x130) = 1;
        }
        center.c[1] = 0.75f * top;
        unitCenter.c[1] = center.c[1];
        half = 0.5f;
        angleScale = fGpffff8110;
        distance = radius / func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)));
        if (distance < 1200.0f) distance = 1200.0f;
        if (center.c[0] == unitCenter.c[0] && center.c[2] == unitCenter.c[2]) {
            func_001c_copy_pair(&direction.bits.xy, &direction.bits.z,
                               (s64 *)D_0060A0F0, (f32 *)(D_0060A0F0 + 8));
        } else {
            direction.c[0] = center.c[0] - unitCenter.c[0];
            direction.c[1] = center.c[1] - unitCenter.c[1];
            direction.c[2] = center.c[2] - unitCenter.c[2];
            func_003e40b0((RwV3d *)direction.c, (const RwV3d *)direction.c);
        }
        x = direction.c[0] * radius;
        direction.c[0] = x;
        y = direction.c[1] * radius;
        direction.c[1] = y;
        z = direction.c[2] * radius;
        direction.c[2] = z;
        target.c[0] = center.c[0] + x;
        target.c[1] = center.c[1] + y;
        target.c[2] = center.c[2] + z;
        target.c[1] = fGpffff807c * top;
        if (!(target.c[1] <= 200.0f)) target.c[1] = 200.0f;
        func_001c_copy_pair(&flat1.bits.xy, &flat1.bits.z,
                           &target.bits.xy, &target.bits.z);
        flat1.c[1] = center.c[1];
        delta.c[0] = flat1.c[0] - center.c[0];
        delta.c[1] = flat1.c[1] - center.c[1];
        delta.c[2] = flat1.c[2] - center.c[2];
        scale = fGpffff8128 * func_003e40b0((RwV3d *)delta.c, (const RwV3d *)delta.c);
        x = delta.c[0] * scale;
        focus.c[0] = x;
        y = delta.c[1] * scale;
        focus.c[1] = y;
        z = delta.c[2] * scale;
        focus.c[2] = z;
        focus.c[0] = x + center.c[0];
        focus.c[1] = y + center.c[1];
        focus.c[2] = z + center.c[2];
    }
    func_001c_copy_pair(&flat2.bits.xy, &flat2.bits.z,
                       &target.bits.xy, &target.bits.z);
    flat2.c[1] = center.c[1];
    delta.c[0] = flat2.c[0] - center.c[0];
    delta.c[1] = flat2.c[1] - center.c[1];
    delta.c[2] = flat2.c[2] - center.c[2];
    scale = fGpffff8128 * func_003e40b0((RwV3d *)delta.c, (const RwV3d *)delta.c);
    x = delta.c[0] * scale;
    focus.c[0] = x;
    y = delta.c[1] * scale;
    focus.c[1] = y;
    z = delta.c[2] * scale;
    focus.c[2] = z;
    focus.c[0] = x + center.c[0];
    focus.c[1] = y + center.c[1];
    focus.c[2] = z + center.c[2];
    func_001bd780(second + 3, target.c, focus.c, D_0060A0E0);
    direction.c[0] = target.c[0] - focus.c[0];
    direction.c[1] = target.c[1] - focus.c[1];
    direction.c[2] = target.c[2] - focus.c[2];
    func_003e40b0((RwV3d *)direction.c, (const RwV3d *)direction.c);
    side = (distance * func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)))) * 0.21875f;
    horizontal[0] = direction.c[0];
    horizontal[1] = direction.c[2];
    func_003e41e0(horizontal, horizontal);
    focus.c[0] = (0.0f + focus.c[0]) + horizontal[1] * side;
    focus.c[2] = (0.0f + focus.c[2]) - horizontal[0] * side;
    x = direction.c[0] * distance;
    delta.c[0] = x;
    y = direction.c[1] * distance;
    delta.c[1] = y;
    z = direction.c[2] * distance;
    delta.c[2] = z;
    second[0] = focus.c[0] + x;
    second[1] = focus.c[1] + y;
    second[2] = focus.c[2] + z;
    if (func_004bd050(0) & 1) {
        func_003e0870((RwMatrix *)matrix, (const RwV3d *)D_0060A0E0, -30.0f, 0);
    } else {
        func_003e0870((RwMatrix *)matrix, (const RwV3d *)D_0060A0E0, 30.0f, 0);
    }
    func_003e4320((RwV3d *)delta.c, (const RwV3d *)direction.c, (const RwMatrix *)matrix);
    x = delta.c[0] * distance;
    delta.c[0] = x;
    y = delta.c[1] * distance;
    delta.c[1] = y;
    z = delta.c[2] * distance;
    delta.c[2] = z;
    first[0] = focus.c[0] + x;
    first[1] = focus.c[1] + y;
    first[2] = focus.c[2] + z;
    func_001bd780(first + 3, first, focus.c, D_0060A0E0);
    func_004b3110(8);
    func_001bc3a0(first, first);
    func_001bc3a0(second, second);
    if (first[1] < 25.0f) first[1] = 25.0f;
    if (second[1] < 25.0f) second[1] = 25.0f;
    func_001bac20((u16 *)arg0, first, second, 1);
    func_001bbef0(arg0, 10.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c1040);
#endif
// FUN_001C17A0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c17a0);
// FUN_001C1F70
void func_001c1f70(u8 *arg0)
{
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 value5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 value6C;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 value7C;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 value8C;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 value9C;
        f32 valueA0;
        f32 valueA4;
        f32 valueA8;
    } frame;
    f32 var_f1;
    u16 *temp_16;
    u16 temp_2;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((*(u16 *)(temp_4 + 0x1A) & 0x10) != 0) {
        temp_17 = *(u8 **)(temp_4 + 0x30);
        temp_18 = *(u8 **)(temp_17 + 0xA0C);
        temp_16 = func_001d0730(*(u16 *)(temp_18 + 0xA4), 0);
        if ((*(u16 *)(iGpffffb3e0 +
                      *(u16 *)(temp_18 + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)temp_18, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)temp_18, 1);
        }
        func_003dcb40((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 4),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_003dcb40((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x1C),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_001bd780(&frame.value5C, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value50 = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value54 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value58 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        func_003dcb40((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 0x10),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_003dcb40((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x28),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_001bd780(&frame.value78, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value6C = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value70 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value74 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value50, &frame.value6C, 1);
        temp_2 = *temp_16;
        var_f1 = (f32)(u16)temp_2;
        func_001bbef0(iGpffffb3ac + 0x24, var_f1 / 30.0f);
    }
}
// FUN_001C21D0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c21d0);
// FUN_001C2EE0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c2ee0);
// FUN_001C3EB0
void func_001c3eb0(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) && ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        if (*(s32 *)(arg0 + 0xDC) == 0) {
            if (arg1 == 0) {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 3);
            } else {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 0x11);
            }
        }
        if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}
// FUN_001C3F70
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c3f70);
// FUN_001C5110
void func_001c5110(u8 *arg0)
{
    u8 *temp;
    s32 arg1;
    s32 arg2;
    s32 mode;

    temp = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp = *(u8 **)(temp + 0xA0C);
    arg1 = 1;
    arg2 = 1;
    *(u16 *)(arg0 + 0x110) = (u16)func_001c0e50(arg0);
    if (*(u16 *)(arg0 + 0xE4) == 0x1D) {
        arg1 = 0;
        arg2 = 0;
    }
    if ((temp != NULL) &&
        (func_0022f950(*(u8 **)(arg0 + 0xE0), temp) != 0)) {
        *(s32 *)(arg0 + 0x114) = 1;
    } else {
        *(s32 *)(arg0 + 0x114) = 0;
    }
    mode = *(u16 *)(arg0 + 0x110);
    switch (mode) {
    case 1:
        func_001c17a0(arg0, arg1, arg2);
        return;
    case 2:
        func_001c21d0(arg0, arg1, arg2);
        return;
    case 3:
        func_001c2ee0(arg0, arg1, arg2);
        return;
    case 4:
        if ((*(s32 *)(arg0 + 0x114) == 0) &&
            ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)) {
            func_001c3f70(arg0, arg1, arg2);
            return;
        }
        func_001c21d0(arg0, arg1, arg2);
        return;
    case 5:
        func_001c2ee0(arg0, arg1, arg2);
        return;
    case 6:
        func_001c1040(arg0, 1);
    default:
        return;
    }
}
// FUN_001C52C0
void func_001c52c0(u8 *arg0)
{
    switch (*(u16 *)(arg0 + 0x110)) {
    case 0:
    case 1:
        break;
    case 2:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
            return;
        }
        break;
    case 3:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0)) {
            if (*(s32 *)(arg0 + 0xDC) == 0) {
                func_001bcd40(*(u8 **)(arg0 + 0xE0),
                              NULL, NULL, 0.0f, 3);
            }
            if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
                func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                              *(u16 *)(arg0 + 0x130));
                return;
            }
        }
        break;
    case 4:
        if (*(s32 *)(arg0 + 0x114) == 0) {
            if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
                (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A) == 1) &&
                (*(s32 *)(arg0 + 0x100) ==
                 *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38)) &&
                ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0)) {
                if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
                    func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                                  *(u16 *)(arg0 + 0x130));
                }
                func_001bcd40(*(u8 **)(arg0 + 0xE0),
                              arg0 + 0x9C, arg0 + 0x104, 10.0f, 0xC3);
                return;
            }
        } else {
            if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
                ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
                (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
                func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                              *(u16 *)(arg0 + 0x130));
            }
        }
        break;
    case 5:
        func_001c3eb0(arg0, 0);
        break;
    case 6:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
        }
        break;
    default:
        return;
    }
}
/* measured 001c5500 (pragma exhaustion): all eight cheap pragmas and all
   twenty-eight pairs measured via `tools/pragma_sweep.py --pairs`; nothing
   beats the banked 78.  `opt_loop_invariants on`, `opt_strength_reduction
   off`, `opt_unroll_loops off` and their pairs tie at 78; `opt_propagation
   off` and `opt_dead_assignments off` cost 313; `peephole off` pairs 310-325.
   Source shapes also measured flat at 78: a two-temp hoist of
   geometry.horizontal[0]/[1] before the cross product, swapping the two
   cross-product terms (crossflip 311 words but only 13 edits - a different
   shape, not an improvement), commuting each product, and all four
   permutations of the tanFov/distScale/var_f20 declarations.  Inlining
   unitY costs 354 and adding a baseZ temp 308.
   WALL, two causes at an exact 416/416: retail loads geometry.horizontal[0]
   (sp+0xc8) before [1] (sp+0xcc) although [1] is consumed first by the
   `mula.s`; and retail holds basePosition.y in $f20 with basePosition.z in
   $f21 while b210 assigns them the other way round, which also shifts the
   low FPRs by one ($f5/$f6 for the zero compare, $f4/$f5 for the negate,
   $f6/$f7 for three multiplies).  Both are allocation, not spelling. */
// FUN_001C5500 NONMATCHING
/* measured 001c5500: 78 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c5500`; fnalign retail 416 vs object 416, 15 edits (+8 reloc-only). Decisive lever: truthful `extern f32 func_0044b868(f32)` block decl (implicit int return emitted mtc1/cvt plus cascade) moved the same body from 249 to 78. Defect class: a missing float return type on an extern, invisible until you spot a stray `cvt.s.w` in your object that retail does not have — check every float-returning callee's declaration when one appears. */
/* Fresh independent-object layout (251w) beats explicit Frame pads (389w/392w); dot/cross decl swap fixes $f24 (251w to 249w); binary (u8*,s32) ties unary with no caller migration. Pragmas swept scoped on exact body: schedule on 387, commons off 457, loopinv on tie, prop off 306 — neutral/worse, none installed. Top remaining: mtc1 $zero $f5 vs $f6 extra live temp at dot compare, 1.5f ($f23) hoist before base copy, mul $f6 vs $f7, $f20/$f21 cycle (div/cvt region already fixed by 0044b868 prototype). */
#ifdef NON_MATCHING
void func_001c5500(u8 *arg0, s32 arg1)
{
    struct Quat5500 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct PosePair5500 {
        RwV3d first;
        struct Quat5500 firstRotation;
        RwV3d second;
        struct Quat5500 secondRotation;
    };
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
    } geometry;
    struct PosePair5500 poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *primaryUnit;
    u8 *secondaryUnit;
    f32 length;
    f32 scale;
    f32 crossProduct;
    f32 dotProduct;
    f32 radius;
    f32 radiusScale;
    f32 heightFactor;
    f32 offsetFactor;
    f32 unitY;
    f32 projDist;
    f32 accumDist;
    f32 tanFov;
    f32 distScale;
    f32 var_f20;
    u16 command;
    extern f32 fGpffff8128;
    extern f32 fGpffff8118;
    extern f32 fGpffff8158;
    extern f32 fGpffff814c;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 func_001ec2b0(void *arg0, void *arg1);
    extern void func_001bd5e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);

    (void)arg1;
    action = *(u8 **)(arg0 + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_00195850(actor, (f32 *)&actorPosition);
    func_00195850(target, (f32 *)&targetPosition);

    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    length = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);

    geometry.horizontal[0] = *(f32 *)(arg0 + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(arg0 + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    scale = fGpffff8128 * length;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetPosition.x;
    focus.y += targetPosition.y;
    focus.z += targetPosition.z;

    geometry.perpendicular[0] = direction.x;
    geometry.perpendicular[1] = direction.z;
    dotProduct = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];

    if (!(dotProduct < 0.0f)) {
        primaryUnit = actor;
        secondaryUnit = target;
        basePosition = actorPosition;
        radiusScale = 1.5f;
        radius = radiusScale * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        heightFactor = fGpffff8118;
        offsetFactor = 0.0f;
        if (basePosition.y < 125.0f) {
            basePosition.y = 125.0f;
        }
    } else {
        primaryUnit = target;
        secondaryUnit = actor;
        basePosition = targetPosition;
        if (*(u8 *)(target + 0xA2) == 0) {
            radius = 1.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 3.5f;
        } else {
            radius = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 1.75f;
        }
        heightFactor = 0.25f;
        offsetFactor = heightFactor;
    }

    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    crossProduct = geometry.perpendicular[1] * geometry.horizontal[1] + geometry.perpendicular[0] * geometry.horizontal[0];
    unitY = basePosition.y;
    eye.y = unitY + offsetFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));

    if (!(crossProduct < 0.0f)) {
        eye.x = basePosition.x + direction.z * radius;
        eye.z = basePosition.z - direction.x * radius;
    } else {
        eye.x = basePosition.x - direction.z * radius;
        eye.z = basePosition.z + direction.x * radius;
    }

    savedDirection = direction;
    func_001bd780(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.secondRotation);

    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = basePosition.z;
    projDist = func_001ec3d0((u8 *)geometry.focusXZ,
                             (u8 *)geometry.eyeXZ,
                             (u8 *)baseXZ,
                             (u8 *)projectionXZ);
    accumDist = projDist + radiusScale * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = unitY;
    eye.z = projectionXZ[1];

    tanFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    distScale = accumDist / tanFov;
    if (distScale < 500.0f) {
        distScale = 500.0f;
    }
    direction.x *= distScale;
    direction.y *= distScale;
    direction.z *= distScale;

    if (!(dotProduct < 0.0f)) {
        if (crossProduct < 0.0f) {
            eye.x += savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z -= savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    } else {
        if (!(crossProduct < 0.0f)) {
            eye.x -= savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z += savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    }

    eye.y = unitY + heightFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;

    func_001bd560((f32 *)&poses.first, (f32 *)(arg0 + 0x9C));
    if (!(func_001ec2b0(&poses.firstRotation, &poses.secondRotation) <= fGpffff8158)) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.firstRotation);
        direction.x *= 150.0f;
        direction.y *= 150.0f;
        direction.z *= 150.0f;
        poses.second.x += direction.x;
        poses.second.y += direction.y;
        poses.second.z += direction.z;
        command = 3;
        if (*(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x88) == 0) {
            func_004b3110(8);
        }
        var_f20 = 1.5f;
    } else {
        command = 0xC3;
        var_f20 = fGpffff814c;
    }

    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }

    func_001bcd40(*(u8 **)(arg0 + 0xE0), secondaryUnit + 4, (u8 *)&poses.second, 50.0f, command);
    func_001bac20((u16 *)arg0, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    func_001bbef0(arg0, var_f20);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5500);
#endif
// FUN_001C5B80
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5b80);
// FUN_001C79E0
void func_001c79e0(void) {}
// FUN_001C79F0 NONMATCHING
/* 9 -> 7 -> 2 (2026-09-18).  Three levers, all measured:
   1. splitting the trailing gp multiply into its own statement -
      `var_f20 = p4_cacd0_mul(chain, 0.21875f); var_f20 = var_f20 *
      fGpffff812c;` - fixes both `mul.s $f20, $f1, $f0` operand orders at
      143 and 380 at once (9 -> 7).  Written inline b210 puts the gp load in
      rs whichever way the factors are spelled; written as an accumulate it
      puts the chain there, as retail does.  Rejected: inline swap (9, edits
      11 -> 13), wrapping the outer multiply in p4_cacd0_mul chain-first (22)
      or constant-first (35), splitting only one of the two sites (8).
   2. func_00196040's out-parameters are pointers, as the MATCHed definition
      in src/Battle/btlUnit.c has always said - `(u32, u32, RwV3d *, f32 *,
      f32 *, u32)`.  This file declared arguments 4 and 5 as s32 and cast the
      addresses; b210 evaluates a cast address before the plain arguments, so
      the two `addiu $aN, $sp, ...` landed four slots early.  Dropping the
      casts restores retail's order (7 -> 2).  Rejected first: two-definition
      pins on both addresses, plain pointer locals, deriving one address from
      the other, a local for the constant arguments, a two-element array -
      all 7, and swapping the two float declarations costs 10.
   3. Remaining 2 words are the two loads at 406-407: for
      `frame.outC0[1] = frame.pos138[1] + frame.dir128[1] * var_f20;` retail
      loads the addend first, b210 the multiplicand.  Only index 1 has both
      operands in memory, so this is the only site that shows it.  Measured
      and rejected: a temp for the addend (2), explicit parentheses (2), a
      pointer-spelled load (2), commuting the multiply (3), swapping the two
      statements (17), a three-iteration loop (57), moving the later
      outC0[1] store ahead of this one (17). */
#ifdef NON_MATCHING
void func_001c79f0(u8 *arg0, s32 arg1)
{
    struct Frame {
        u8 mat60[0x40];
        f32 poseA0[7];
        u8 padBC[4];
        f32 outC0[3];
        f32 quatCC[4];
        f32 padDC;
        f32 horizE0[2];
        f32 actorE8[3];
        f32 padF4;
        f32 baseF8[3];
        f32 pad104;
        f32 eye108[3];
        f32 pad114;
        f32 target118[3];
        f32 pad124;
        f32 dir128[3];
        f32 pad134;
        f32 pos138[3];
        f32 pad144;
        f32 min148;
        f32 max14C;
    } frame;
    extern f32 fGpffff8110;
    extern f32 fGpffff8128;
    extern f32 fGpffff812c;
    extern f32 fGpffff8118;
    extern f32 fGpffff8130;
    extern f32 fGpffff8134;
    extern f32 fGpffff8138;
    extern f32 fGpffff813c;
    extern f32 fGpffff8030;
    extern void func_00195d50(u8 *arg0, f32 *arg1);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern s32 func_00243e30(s32 arg0);
    extern s32 func_00242930(s32 arg0);
    extern f32 func_0044b868(f32 arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    f32 var_f24;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    u8 *saved_arg0;
    u8 *var17;
    u8 *var16;
    (void)arg1;

    saved_arg0 = arg0;
    if (*(u16 *)(saved_arg0 + 0x106) != 0) {
        func_001bd560(frame.poseA0, (f32 *)(saved_arg0 + 0x9C));
        var16 = *(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30);
        var_f20 = func_00196040(3, 0, frame.target118, 0, 0, 1);
        func_00196040(1, 0, NULL, &frame.max14C, &frame.min148, 1);
        frame.target118[1] = frame.min148 + 0.5f * (frame.max14C - frame.min148);
        var_f20 = (0.75f * var_f20) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        func_001958f0(var16, frame.actorE8);
        frame.eye108[0] = frame.actorE8[0];
        frame.eye108[1] = frame.target118[1];
        frame.eye108[2] = frame.actorE8[2];
        frame.dir128[0] = frame.actorE8[0] - frame.target118[0];
        frame.dir128[1] = frame.target118[1] - frame.target118[1];
        frame.dir128[2] = frame.actorE8[2] - frame.target118[2];
        {
            f32 tmpLen;
            tmpLen = func_003e40b0((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128);
            tmpLen = p4_cacd0_mul(fGpffff8128, tmpLen);
            frame.dir128[0] = frame.dir128[0] * tmpLen;
            frame.dir128[1] = frame.dir128[1] * tmpLen;
            frame.dir128[2] = frame.dir128[2] * tmpLen;
        }
        frame.baseF8[0] = frame.target118[0] + frame.dir128[0];
        frame.baseF8[1] = frame.target118[1] + frame.dir128[1];
        frame.baseF8[2] = frame.target118[2] + frame.dir128[2];
        frame.eye108[0] = frame.actorE8[0];
        frame.eye108[1] = frame.max14C;
        frame.eye108[2] = frame.actorE8[2];
        func_001bd780((void *)frame.quatCC, (void *)frame.eye108, (void *)frame.baseF8, (void *)D_0060A0E0);
        func_003dcb40((RwV3d *)frame.dir128, (const RwV3d *)D_0060A100, 1, (const RtQuat *)frame.quatCC);
        frame.dir128[0] = frame.dir128[0] * var_f20;
        frame.dir128[1] = frame.dir128[1] * var_f20;
        frame.dir128[2] = frame.dir128[2] * var_f20;
        var_f20 = p4_cacd0_mul(var_f20 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8))), 0.21875f);
        var_f20 = var_f20 * fGpffff812c;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.baseF8[0] = frame.horizE0[1] * var_f20 + frame.baseF8[0] + 0.0f;
        frame.baseF8[2] = (frame.baseF8[2] + 0.0f) - frame.horizE0[0] * var_f20;
        frame.outC0[0] = frame.baseF8[0] + frame.dir128[0];
        frame.outC0[1] = frame.baseF8[1] + frame.dir128[1];
        frame.outC0[2] = frame.baseF8[2] + frame.dir128[2];
        func_001bc3a0(frame.outC0, frame.outC0);
        func_001bac20((u16 *)saved_arg0, frame.poseA0, frame.outC0, 1);
        func_001bbef0(saved_arg0, 0.75f);
    } else {
        *(s32 *)(saved_arg0 + 0x148) = 1;
        var17 = func_001d8bc0(*(u8 **)(saved_arg0 + 0xE0) + 0x98);
        var16 = *(u8 **)(var17 + 0x30);
        var_f20 = *(f32 *)(var16 + 0x90) * *(f32 *)(var16 + 0x2C);
        var_f24 = 0.5f * (*(f32 *)(var16 + 0x8C) * *(f32 *)(var16 + 0x2C));
        if (func_002428f0(*(s32 *)(var16 + 0xA64), 0) != 0) {
            func_00195d50(var16, frame.pos138);
            var_f23 = 1.5f;
            var_f22 = 3.5f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * var_f24;
        } else if (func_00232710(*(s32 *)(var16 + 0xA64), 0x100000) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8130;
            var_f22 = fGpffff8134;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * var_f24;
        } else if (func_00243e30(*(s32 *)(var16 + 0xA64)) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8138;
            var_f22 = 0.75f;
            var_f21 = 15.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff8118 * var_f24;
        } else if (func_00242930(*(s32 *)(var16 + 0xA64)) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8138;
            var_f22 = 1.0f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8030 * var_f24;
        } else {
            func_00195850(var16, frame.pos138);
            var_f23 = 1.25f;
            var_f22 = 1.0f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff813c * var_f24;
        }
        if (var_f20 > var_f24) {
            var_f20 = (var_f20 * var_f23) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        } else {
            var_f20 = (var_f24 * var_f23) / func_0044b868(0.5f * *(f32 *)(saved_arg0 + 0xB8));
        }
        func_003dcb40((RwV3d *)frame.dir128, (const RwV3d *)D_0060A0F0, 1, (const RtQuat *)(var16 + 0x1C));
        func_003e0870((RwMatrix *)frame.mat60, (const RwV3d *)D_0060A0E0, var_f21, 0);
        func_003e4320((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128, (const RwMatrix *)frame.mat60);
        var_f21 = p4_cacd0_mul(var_f20 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8))), 0.21875f);
        var_f21 = var_f21 * fGpffff8118;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.pos138[0] = frame.horizE0[1] * var_f21 + frame.pos138[0] + 0.0f;
        frame.pos138[2] = (frame.pos138[2] + 0.0f) - frame.horizE0[0] * var_f21;
        frame.outC0[0] = frame.pos138[0] + frame.dir128[0] * var_f20;
        frame.outC0[1] = frame.pos138[1] + frame.dir128[1] * var_f20;
        frame.outC0[2] = frame.pos138[2] + frame.dir128[2] * var_f20;
        frame.outC0[1] = frame.pos138[1] + var_f24 * var_f22;
        func_001bd780((void *)frame.quatCC, (void *)frame.outC0, (void *)frame.pos138, (void *)D_0060A0E0);
        func_001bcd40(var17, (u8 *)0, (u8 *)0, 0.0f, 1);
        func_001bab00(saved_arg0, (void *)frame.outC0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c79f0);
#endif
// FUN_001C80F0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c80f0);
// FUN_001C88D0
s32 func_001c88d0(u8 *arg0, s32 *arg1, f32 *arg2, u8 *arg3)
{
    struct Frame {
        u8 pad48[0x8];
        f32 value58;
        f32 value5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 value6C;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 value7C;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 value8C;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 value9C;
        f32 valueA0;
        f32 valueA4;
        f32 valueA8;
        f32 valueAC;
    } frame;
    f32 product;
    f32 distance1;
    f32 distance2;
    product = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    distance1 = fGpffff809c * product;
    product = *(f32 *)(arg0 + 0x8C) * *(f32 *)(arg0 + 0x2C);
    distance2 = 0.5f * (fGpffff809c * product);
    func_00195850(arg0, &frame.valueA0);
    frame.value90 = frame.valueA0;
    frame.value94 = frame.valueA4 + distance2;
    frame.value98 = frame.valueA8;
    func_003e4320((RwV3d *)(u8 *)&frame.value70, (const RwV3d *)D_0060A0D0, (const RwMatrix *)arg3);
    frame.value70 = frame.value70 * distance1;
    frame.value74 = frame.value74 * distance1;
    frame.value78 = frame.value78 * distance1;
    frame.value80 = frame.valueA0 + frame.value70;
    frame.value84 = frame.valueA4 + frame.value74;
    frame.value88 = frame.valueA8 + frame.value78;
    if ((func_001ec4a0(&frame.valueA0, &frame.value68) != 0) &&
        (func_001ec4a0(&frame.value90, &frame.value60) != 0) &&
        (func_001ec4a0(&frame.value80, &frame.value58) != 0)) {
        *arg2 = func_001ec250(&frame.valueA0, arg3 + 0x30);
        distance1 = func_0044e7d8(
            func_0044b310(func_0044dcd8(frame.value64 - frame.value6C)));
        distance2 = func_0044e7d8(
            func_0044b310(func_0044dcd8(frame.value58 - frame.value68)));
        arg1[0] = (s32)(frame.value68 - distance2);
        arg1[1] = (s32)(frame.value6C - distance1);
        arg1[3] = (s32)(2.0f * distance1);
        arg1[2] = (s32)(2.0f * distance2);
        return 1;
    }
    return 0;
}
// FUN_001C8B00
void func_001c8b00(u8 *arg0)
{
    struct Frame {
        s32 value60;
        s32 value64;
        s32 value68;
        s32 value6C;
        s32 value70;
        s32 value74;
        s32 value78;
        s32 value7C;
        u8 pad80[8];
        f32 value88;
        f32 value8C;
    } frame;
    u8 *var20;
    u8 *temp19;
    u8 *temp18;
    s32 var17;
    u8 *temp16;

    if (*(u16 *)(arg0 + 0x106) == 0) {
        temp18 = *(u8 **)(func_00457120() + 4) + 0x10;
        temp19 = *(u8 **)(func_001d8bc0(*(u8 **)(arg0 + 0xE0) + 0x98) + 0x30);
        temp16 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        if (func_001c88d0(temp19, &frame.value60, &frame.value88, temp18) != 0) {
            func_001bd530(temp19);
            var17 = 0;
            goto outer_test;
outer_body:
            var20 = *(u8 **)(iGpffffb3ac + (var17 << 3) + 0x178);
            goto inner_test;
inner_body:
            if (((*(s32 *)(var20 + 0x9C) & 8) != 0) &&
                (temp19 != var20) &&
                (temp16 != var20)) {
                if (func_001c88d0(var20, &frame.value70, &frame.value8C, temp18) == 0) {
                    func_001bd530(temp19);
                } else if (!(frame.value8C <= frame.value88)) {
                    func_001bd530(temp19);
                } else {
                    if (frame.value60 > frame.value70 + frame.value78) {
                        goto range_reject;
                    }
                    if (frame.value70 > frame.value60 + frame.value68) {
                        goto range_reject;
                    }
                    if (frame.value64 > frame.value74 + frame.value7C) {
                        goto range_reject;
                    }
                    if (frame.value74 > frame.value64 + frame.value6C) {
                        goto range_reject;
                    }
                    func_001bd4f0(var20);
                    goto range_done;
range_reject:
                    func_001bd530(temp19);
range_done:
                    ;
                }
            }
            var20 = *(u8 **)(var20 + 0xA6C);
inner_test:
            if (var20 != NULL) {
                goto inner_body;
            }
            var17 += 1;
outer_test:
            if (var17 < 2) {
                goto outer_body;
            }
        }
    }
}
/* measured: optimization_level 1 probe for c8cf0 argument order. */
#pragma optimization_level 1
// FUN_001C8CF0
void func_001c8cf0(u8 *arg0)
{
    u8 *temp_16;
    u8 *call_arg0;
    s32 call_arg1;
    s32 call_arg2;

    temp_16 = *(u8 **)(arg0 + 0xE0);
    call_arg0 = temp_16;
    call_arg1 = 0;
    call_arg2 = *(u16 *)(temp_16 + 0x6E);
    *(s16 *)(arg0 + 0x106) = func_001d7f10((s32)call_arg0, call_arg1, call_arg2, 0);
    *(s16 *)(arg0 + 0x104) = func_001d8df0(temp_16 + 0x98);
    *(s32 *)(arg0 + 0x100) = 0;
}
/* measured: close optimization_level after c8cf0. */
#pragma optimization_level 2
// FUN_001C8D50
void func_001c8d50(u8 *arg0)
{
    s32 flag;
    u16 mode;
    u16 type;
    u8 *next;
    u8 *current;

    next = func_001d8bc0(*(u8 **)(arg0 + 0xE0) + 0x98);
    if (*(u16 *)(arg0 + 0x104) == 2) {
        func_001c8b00(arg0);
    }
    if ((next == NULL) ||
        ((current = *(u8 **)(arg0 + 0x100), current == next)) ||
        ((current != NULL) && (*(u16 *)(arg0 + 0x106) != 0))) {
        return;
    }
    if (current == NULL) {
        mode = *(u16 *)(iGpffffb3ac + 0x108);
        switch (mode) {
        case 0x21:
        case 0x28:
        case 2:
        case 0x29:
            flag = 0;
            break;
        default:
            flag = 1;
            break;
        }
    } else {
        flag = 0;
    }
    *(u8 **)(arg0 + 0x100) = next;
    type = *(u16 *)(arg0 + 0x104);
    switch (type) {
    case 2:
        func_001c80f0(arg0, flag);
        return;
    case 1:
    default:
        func_001c79f0(arg0, flag);
        return;
    }
}
// FUN_001C8E90
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c8e90);
// FUN_001C9750
void func_001c9750(u8 *arg0)
{
    struct Work {
        f32 first;
        u8 gap[0x18];
        f32 second;
        u8 tail[0x20];
    } work;

    func_001c8e90(arg0, &work.first, &work.second);
    func_001bac20((u16 *)arg0, &work.first, &work.second, 1);
    func_001bbef0(arg0, fGpffff811c);
}
// FUN_001C97B0
void func_001c97b0(u8 *arg0)
{
    u8 *temp_4;
    f32 value;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x124) == *(s32 *)(temp_4 + 0x38)) &&
        ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        value = *(f32 *)(arg0 + 0x10C);
        func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100, value, 0xC3);
    }
}
// FUN_001C9820
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c9820);
// FUN_001CA550
void func_001ca550(u8 *arg0) {
    func_001c9820(arg0, 0, 0, 50.0f);
}
// FUN_001CA590 NONMATCHING
#ifdef NON_MATCHING
/* measured 001ca590: 248 differing words via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001ca590 --candidate best=/var/tmp/main/ca590_best.c`; fnalign 464 retail vs 465 object, 66 edits (+15 reloc-only). */
/* Work layout mirrors 001cacd0 (frames[2]+pad8+matrix+2 quats+perp/horiz+unit/actor/base/scaled/eye/diff/saved/eye2+xz, 0x140 bytes); retail-arbitrated 0.0f+adda/madd, 0.25*accum focus + 0.5*height staging, dual 003e41e0, mula/madd dot. */
/* P01C_001ca590_body.c re-derived: COP1-floor note only, not a body. Pragmas swept on exact v1/v3: plain 248 best; loopinv 248 same; propoff 422; sched 428. No byte loads in window (lb/lbu N/A). Next: dot x-first order, dot2 !( <0) branch, decl-order f20/f21/f22 + distScale f23, double-def pinning for sunk address arithmetic. */
void func_001ca590(u8 *arg0, f32 fparg0, f32 fparg1)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Frame {
        struct Vec3 pos;
        struct Quat rot;
    };
    struct Work {
        struct Frame frames[2];
        u8 pad38[8];
        u8 matrix[0x40];
        struct Quat quatE0;
        struct Quat quatF0;
        f32 perp[2];
        f32 horiz[2];
        u8 padB0[8];
        struct Vec3 unit;
        u8 padC4[4];
        struct Vec3 actor;
        u8 padD4[4];
        struct Vec3 base;
        u8 padE4[4];
        struct Vec3 scaled;
        u8 padF4[4];
        struct Vec3 eye;
        u8 pad104[4];
        struct Vec3 diff;
        u8 pad114[4];
        struct Vec3 saved;
        u8 pad124[4];
        struct Vec3 eye2;
        u8 pad134[4];
        f32 xz[2];
    } work;
    u8 *action;
    u8 *s0;
    u8 *s1;
    f32 height;
    f32 halfHeight;
    f32 accum;
    f32 dot;
    f32 dot2;
    f32 dot3;
    f32 radius;
    f32 tanRes;
    f32 tanRes2;
    f32 distScale;
    f32 finalScale;
    f32 proj1;
    f32 proj2;
    f32 len2;
    f32 baseZ;
    f32 zero;
    extern f32 fGpffff8118;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_003e41b0(f32 *arg0);
    extern f32 fabsf(f32 x);
    extern f32 func_001ec2b0(void *first, void *second);
    extern f32 func_0044b868(f32 arg0);
    extern void func_001bd560(f32 *arg0, f32 *arg1);
    action = *(u8 **)(arg0 + 0xE0);
    s0 = *(u8 **)(action + 0x30);
    s1 = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560((f32 *)&work.frames[0], (f32 *)(arg0 + 0x9C));
    work.actor.x = *(f32 *)(s0 + 0xDC);
    work.actor.y = *(f32 *)(s0 + 0x84) * *(f32 *)(s0 + 0x2C);
    work.actor.z = *(f32 *)(s0 + 0xE4);
    func_00195850(s1, (f32 *)&work.unit);
    height = (0.0f + work.actor.y + p4_cacd0_mul(*(f32 *)(s0 + 0x8C), *(f32 *)(s0 + 0x2C)) * fGpffff8118);
    height += (0.0f + work.unit.y + p4_cacd0_mul(*(f32 *)(s1 + 0x8C), *(f32 *)(s1 + 0x2C)) * fGpffff8118);
    accum = 0.0f + *(f32 *)(s0 + 0xE8) + *(f32 *)(s0 + 0x90) * *(f32 *)(s0 + 0x2C) + *(f32 *)(s1 + 0x90) * *(f32 *)(s1 + 0x2C);
    work.unit.y = 0.0f;
    work.actor.y = 0.0f;
    zero = 0.0f;
    work.diff.x = *(f32 *)(s0 + 0xDC) - work.unit.x;
    work.diff.y = *(f32 *)(s0 + 0xE0) - zero;
    work.diff.z = *(f32 *)(s0 + 0xE4) - work.unit.z;
    func_003e40b0((RwV3d *)&work.diff, (const RwV3d *)&work.diff);
    work.scaled.x = work.diff.x * (0.25f * accum);
    work.scaled.y = work.diff.y * (0.25f * accum);
    work.scaled.z = work.diff.z * (0.25f * accum);
    work.scaled.x = work.scaled.x + work.unit.x;
    work.scaled.y = work.scaled.y + work.unit.y;
    work.scaled.z = work.scaled.z + work.unit.z;
    halfHeight = p4_cacd0_mul(0.5f, height);
    work.scaled.y = halfHeight;
    *(f32 *)(arg0 + 0x10C) = 0.5f * *(f32 *)(s0 + 0xE8);
    *(struct Vec3 *)(arg0 + 0x100) = work.scaled;
    work.perp[0] = work.diff.z;
    work.perp[1] = -work.diff.x;
    work.horiz[0] = work.frames[0].pos.x - work.scaled.x;
    work.horiz[1] = work.frames[0].pos.z - work.scaled.z;
    func_003e41e0(work.perp, work.perp);
    func_003e41e0(work.horiz, work.horiz);
    work.saved.x = work.frames[0].pos.x - work.scaled.x;
    work.saved.y = work.frames[0].pos.y - work.scaled.y;
    work.saved.z = work.frames[0].pos.z - work.scaled.z;
    dot = work.perp[1] * work.horiz[1] + work.perp[0] * work.horiz[0];
    if (!(dot < 0.0f)) {
        func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, fparg0, 0);
    } else {
        func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, -fparg0, 0);
    }
    func_003e4320((RwV3d *)&work.saved, (const RwV3d *)&work.saved, (const RwMatrix *)work.matrix);
    work.saved.x = work.saved.x + work.scaled.x;
    work.saved.y = work.saved.y + work.scaled.y;
    work.saved.z = work.saved.z + work.scaled.z;
    func_001bd780(&work.frames[1].rot, &work.saved, &work.scaled, D_0060A0E0);
    if (accum < 400.0f) {
        accum = 400.0f;
    }
    tanRes = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    distScale = (0.5f * accum) / tanRes;
    func_003dcb40((RwV3d *)&work.saved, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.frames[1].rot);
    work.diff.y = work.saved.y;
    func_003e40b0((RwV3d *)&work.diff, (const RwV3d *)&work.diff);
    dot2 = work.saved.y * work.diff.y + work.saved.x * work.diff.x + work.saved.z * work.diff.z;
    if (dot2 < 0.0f) {
        radius = *(f32 *)(s1 + 0x90) * *(f32 *)(s1 + 0x2C);
        func_001c_copy_pair((s64 *)&work.base.x, &work.base.z, (s64 *)&work.unit.x, &work.unit.z);
    } else {
        radius = *(f32 *)(s0 + 0x90) * *(f32 *)(s0 + 0x2C);
        func_001c_copy_pair((s64 *)&work.base.x, &work.base.z, (s64 *)&work.actor.x, &work.actor.z);
    }
    work.eye2.x = 0.0f + work.unit.x + work.diff.z * radius;
    work.eye2.y = work.scaled.y;
    work.eye2.z = 0.0f + work.unit.z - work.diff.x * radius;
    work.eye.x = work.eye2.x - work.scaled.x;
    work.eye.y = work.scaled.y - work.scaled.y;
    work.eye.z = work.eye2.z - work.scaled.z;
    func_003e40b0((RwV3d *)&work.eye, (const RwV3d *)&work.eye);
    dot3 = work.eye.y * work.diff.y + work.eye.x * work.diff.x + work.eye.z * work.diff.z;
    if ((fabsf(dot2) > fabsf(dot3)) && (dot3 != 0.0f) && (dot2 != 0.0f)) {
        work.xz[0] = work.scaled.x - work.base.x;
        baseZ = work.base.z;
        work.xz[1] = work.scaled.z - baseZ;
        len2 = func_003e41b0(work.xz);
        work.eye2.y = work.scaled.y + (halfHeight * len2) / distScale;
        work.eye2.x = 0.0f + work.base.x + work.diff.z * radius;
        work.eye2.z = 0.0f + baseZ - work.diff.x * radius;
        func_001bd780(&work.quatE0, &work.eye2, &work.scaled, D_0060A0E0);
        proj1 = func_001ec2b0(&work.frames[0].rot, &work.quatE0);
        work.eye2.x = 0.0f + work.base.x - work.diff.z * radius;
        work.eye2.z = 0.0f + baseZ + work.diff.x * radius;
        func_001bd780(&work.quatF0, &work.eye2, &work.scaled, D_0060A0E0);
        proj2 = func_001ec2b0(&work.frames[0].rot, &work.quatF0);
        if (proj1 < proj2) {
            work.frames[1].rot = work.quatE0;
        } else {
            work.frames[1].rot = work.quatF0;
        }
        func_003dcb40((RwV3d *)&work.saved, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.frames[1].rot);
    }
    work.saved.x = work.saved.x * distScale;
    work.saved.y = work.saved.y * distScale;
    work.saved.z = work.saved.z * distScale;
    tanRes2 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    finalScale = (distScale * tanRes2) * 0.21875f;
    work.xz[0] = work.saved.x;
    work.xz[1] = work.saved.z;
    func_003e41e0(work.xz, work.xz);
    work.scaled.x = 0.0f + work.scaled.x + work.xz[1] * finalScale;
    work.scaled.z = 0.0f + work.scaled.z - work.xz[0] * finalScale;
    work.frames[1].pos.x = work.scaled.x + work.saved.x;
    work.frames[1].pos.y = work.scaled.y + work.saved.y;
    work.frames[1].pos.z = work.scaled.z + work.saved.z;
    func_001bac20((u16 *)arg0, (f32 *)&work.frames[0].pos, (f32 *)&work.frames[1].pos, 1);
    func_001bbef0(arg0, fparg1);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ca590);
#endif
/* 1052/1056 bytes; 19 resolved relocations; four zero alignment bytes.
 * Build the current pose plus three orbit keys with a halfword frame index. */
// FUN_001CACD0
void func_001cacd0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Frame {
        struct Vec3 pos;
        struct Quat rot;
    };
    struct Work {
        struct Frame frames[4];
        u8 matrix[0x40];
        f32 xzA[2];
        f32 xzB[2];
        struct Vec3 unit;
        u8 pad12C[4];
        struct Vec3 delta;
        u8 pad13C[4];
        struct Vec3 rotated;
        u8 pad14C[4];
        struct Vec3 scaled;
        u8 pad15C[4];
        struct Vec3 diff;
        u8 pad16C[4];
    } work;
    u8 *action;
    u8 *s0;
    u8 *s2;
    f32 prod;
    f32 height;
    f32 dot;
    f32 len;
    f32 angle;
    f32 step;
    f32 zero;
    u16 i;
    struct Frame *base;
    extern f32 fGpffff8118;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_001bb3d0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u16 arg5);
    extern void func_001bd560(f32 *arg0, f32 *arg1);

    action = *(u8 **)(arg0 + 0xE0);
    s0 = *(u8 **)(action + 0x30);
    s2 = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560((f32 *)&work.frames[0], (f32 *)(arg0 + 0x9C));
    prod = *(f32 *)(s0 + 0x84) * *(f32 *)(s0 + 0x2C);
    func_00195850(s2, (f32 *)&work.unit);
    height = (0.0f + prod + p4_cacd0_mul(*(f32 *)(s0 + 0x8C), *(f32 *)(s0 + 0x2C)) * fGpffff8118);
    height += (0.0f + work.unit.y + (*(f32 *)(s2 + 0x8C) * *(f32 *)(s2 + 0x2C)) * fGpffff8118);
    work.unit.y = 0.0f;
    zero = 0.0f;
    work.diff.x = *(f32 *)(s0 + 0xDC) - work.unit.x;
    work.diff.y = *(f32 *)(s0 + 0xE0) - zero;
    work.diff.z = *(f32 *)(s0 + 0xE4) - work.unit.z;
    len = func_003e40b0((RwV3d *)&work.diff, (const RwV3d *)&work.diff);
    work.scaled.x = work.diff.x * (0.5f * len);
    work.scaled.y = work.diff.y * (0.5f * len);
    work.scaled.z = work.diff.z * (0.5f * len);
    work.scaled.x = work.scaled.x + work.unit.x;
    work.scaled.y = work.scaled.y + work.unit.y;
    work.scaled.z = work.scaled.z + work.unit.z;
    height = p4_cacd0_mul(0.5f, height);
    work.scaled.y = height;
    work.xzA[0] = work.diff.z;
    work.xzA[1] = -work.diff.x;
    work.xzB[0] = work.frames[0].pos.x - work.scaled.x;
    work.xzB[1] = work.frames[0].pos.z - work.scaled.z;
    func_003e41e0(work.xzA, work.xzA);
    func_003e41e0(work.xzB, work.xzB);
    dot = work.xzA[0] * work.xzB[0] + work.xzA[1] * work.xzB[1];
    if (!(dot < 0.0f)) {
        work.scaled.x = work.diff.x * (fGpffff8118 * len);
        work.scaled.y = work.diff.y * (fGpffff8118 * len);
        work.scaled.z = work.diff.z * (fGpffff8118 * len);
    } else {
        work.scaled.x = work.diff.x * (0.5f * len);
        work.scaled.y = work.diff.y * (0.5f * len);
        work.scaled.z = work.diff.z * (0.5f * len);
    }
    work.scaled.x = work.scaled.x + work.unit.x;
    work.scaled.y = work.scaled.y + work.unit.y;
    work.scaled.z = work.scaled.z + work.unit.z;
    work.scaled.y = height;
    *(f32 *)(arg0 + 0x10C) = 0.5f * *(f32 *)(s0 + 0xE8);
    *(struct Vec3 *)(arg0 + 0x100) = work.scaled;
    work.delta.x = work.frames[0].pos.x - work.scaled.x;
    work.delta.y = work.frames[0].pos.y - work.scaled.y;
    work.delta.z = work.frames[0].pos.z - work.scaled.z;
    angle = fparg0 / 3.0f;
    step = angle;
    i = 1;
    while (i < 4) {
        if (!(dot < 0.0f)) {
            func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, angle, 0);
        } else {
            func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
        }
        func_003e4320((RwV3d *)&work.rotated, (const RwV3d *)&work.delta, (const RwMatrix *)work.matrix);
        base = &work.frames[(u16)i];
        base->pos.x = work.rotated.x + work.scaled.x;
        base->pos.y = work.rotated.y + work.scaled.y;
        base->pos.z = work.rotated.z + work.scaled.z;
        func_001bd780(&base->rot, &base->pos, &work.scaled, D_0060A0E0);
        angle = angle + step;
        i++;
    }
    func_001bb3d0(arg0, &work.frames[0], &work.frames[1], &work.frames[2], &work.frames[3], 1);
    func_001bbef0(arg0, fparg1);
}
// FUN_001CB0F0
void func_001cb0f0(u8 *arg0)
{
    u8 *temp_5;
    u8 *temp_6;
    u16 temp_5_2;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) != 0) {
        return;
    }
    *(s32 *)(arg0 + 0x128) = *(s32 *)(temp_5 + 0x38);
    temp_6 = iGpffffb3ac;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) == 0) {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 40.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 100.0f, 3.0f);
            return;
        }
    } else {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 20.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 50.0f, 3.0f);
            return;
        }
    }
}
// FUN_001CB200
void func_001cb200(u8 *arg0)
{
    s32 temp_5;
    u16 temp_3;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    temp_5 = 0;
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x128) == *(s32 *)(temp_4 + 0x38)) &&
        ((temp_5 = *(u16 *)(temp_4 + 0x1A) & 1, temp_5 != 0)) &&
        (*(u8 *)(*(u8 **)(temp_4 + 0x30) + 0xA2) == 0)) {
        temp_3 = *(u16 *)(iGpffffb3ac + 0x10E);
        switch (temp_3) {
        case 0:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100,
                              *(f32 *)(arg0 + 0x10C), 0xC3);
                return;
            }
            break;
        case 1:
        default:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100,
                              *(f32 *)(arg0 + 0x10C), 0xC3);
            }
            break;
        }
    }
}
// FUN_001CB2E0
void func_001cb2e0(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = (value & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_005F7CA0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB380
void func_001cb380(void) {
    func_001bdeb0();
}
// FUN_001CB3A0
void func_001cb3a0(u8 *arg0)
{
    u8 *temp;
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    temp = *(u8 **)(arg0 + 0xE0);
    value = *(u16 *)(*(u8 **)(temp + 0x30) + 0xA4);
    func_001b73f0(*(u8 **)(temp + 0x30));
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
    target = (u8 *)&D_005F91A0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB440
void func_001cb440(void) {
    func_001bdeb0();
}
// FUN_001CB460
void func_001cb460(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (func_004bd050(0) & 1) * 0xF4;
        index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
        target = (u8 *)&D_005FA2D0 + index_offset;
        func_001bdd80(arg0, target + flag_offset, 2);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
    } else {
        func_001c2ee0(arg0, 0, 1);
    }
}
// FUN_001CB540
void func_001cb540(u8 *arg0)
{
    u8 *temp;

    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        func_001bdeb0(arg0);
        goto done;
    }
    temp = *(u8 **)(arg0 + 0xE0);
    if (temp == NULL)
        goto done;
    if (*(s32 *)(arg0 + 0xD8) != 0)
        goto done;
    if (temp == NULL)
        goto done;
    if ((*(u16 *)(temp + 0x1A) & 1) == 0)
        goto done;
    if (*(s32 *)(arg0 + 0xDC) == 0) {
        func_001bcd40(temp, NULL, NULL, 0.0f, 0x11);
    }
    if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
        func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
    }
done:
    ;
}
/* 840/848 bytes; 27 resolved relocations; eight zero alignment bytes.
   Build both position/quaternion keys before clamping their heights. */
// FUN_001CB610
void func_001cb610(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Matrix {
        struct Vec3 right;
        u32 flags;
        struct Vec3 up;
        u32 pad1;
        struct Vec3 at;
        u32 pad2;
        struct Vec3 pos;
        u32 pad3;
    };
    struct Work {
        struct Vec3 firstPosition;
        u8 firstView[0x10];
        struct Vec3 secondPosition;
        u8 secondView[0x18];
        struct Matrix rotation;
        struct Vec3 center;
        u8 padBC[4];
        struct Vec3 direction;
        u8 padCC[4];
        struct Vec3 scaled;
        u8 padDC[4];
    } work;
    u8 *temp17;
    f32 angleScale;
    f32 rotationAngle;
    f32 y;

    temp17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x38);
    temp17 = *(u8 **)(temp17 + 0x30);
    func_001959d0((BtlUnit *)temp17, (RwV3d *)&work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (*(f32 *)(temp17 + 0x8C) *
                     *(f32 *)(temp17 + 0x2C));
    work.center.y = work.center.y + 10.0f;
    func_003dcb40((RwV3d *)&work.direction, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)(temp17 + 0x1C));
    work.scaled.x = work.direction.x * 200.0f;
    work.scaled.y = work.direction.y * 200.0f;
    work.scaled.z = work.direction.z * 200.0f;
    y = work.center.y + work.scaled.y;
    y = y + 10.0f;
    work.direction.x = (work.center.x + work.scaled.x) - work.center.x;
    work.direction.y = y - work.center.y;
    work.direction.z = (work.center.z + work.scaled.z) - work.center.z;
    func_003e40b0((RwV3d *)&work.direction, (const RwV3d *)&work.direction);
    rotationAngle = 30.0f;
    func_003e0870((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -rotationAngle, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 115.0f /
                 tanf(fGpffff8110 *
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.firstPosition.x = work.center.x + work.scaled.x;
    work.firstPosition.y = work.center.y + work.scaled.y;
    work.firstPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.firstView, &work.firstPosition, &work.center,
                  D_0060A0E0);
    func_003e0870((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 15.0f, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 165.0f /
                 tanf(fGpffff8110 *
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.secondPosition.x = work.center.x + work.scaled.x;
    work.secondPosition.y = work.center.y + work.scaled.y;
    work.secondPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.secondView, &work.secondPosition, &work.center,
                  D_0060A0E0);
    if (work.firstPosition.y < 25.0f) {
        work.firstPosition.y = 25.0f;
    }
    if (work.secondPosition.y < 25.0f) {
        work.secondPosition.y = 25.0f;
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
    func_001bac20((u16 *)arg0, (f32 *)&work.firstPosition, (f32 *)&work.secondPosition, 1);
    func_001bbef0(arg0, 2.0f);
}
// FUN_001CB960
void func_001cb960(void) {}
/* 1544/1552 bytes (386/388 instrs, 0.5% short, within 3% size gate); 195 edits +3 reloc-only. */
/* Prototype (u8*,f32,s32) parks a0/f12/a1 (camera/speed/flag); float-middle per parks, ABI-identical to the (u8*,u8*,f32) guess. */
/* Vector temps at sp+0x110 (delta), sp+0xD8 (camXZ), sp+0xD0 (deltaXZ); Pose at sp+0x90/0xAC, quat at 0xB8. */
/* Mined 48 MATCH neighbours (cb610/cacd0/c04e0): p4_cacd0_mul, func_001c_copy_pair, 0.0f+adda/madd, 100.0f/12.5f/500.0f clamps. */
/* FMA chains (mula/madd/msub/adda) + 001959d0x2/003e40b0/003e41e0 retained; fnalign top-down, same levers. */
/* measured 001cb970: `schedule on` inside the guard is worth 10 words (367 -> 357); retail fills delay slots plain -O2 leaves empty. */
// FUN_001CB970 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail fills delay slots this function leaves empty at -O2. */
#pragma schedule on
void func_001cb970(u8 *arg0, f32 fparg0, s32 arg1)
{
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec2b0(void *first, void *second);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 func_0044b868(f32 arg0);
    extern void func_001bd5e0(u8 *arg0, u8 *arg1);
    extern void func_001bd560(f32 *arg0, f32 *arg1);
    extern void func_001bcd40(u8 *a0, u8 *a1, u8 *a2, f32 a3, s32 a4);
    extern f32 fGpffff80dc;
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Pose {
        struct Vec3 pos;
        struct Quat quat;
    };
    struct Work {
        struct Pose poseOld;
        struct Pose poseNew;
        struct Vec3 firstPos;
        struct Vec3 secondPos;
        struct Vec3 delta;
        struct Vec3 scaled;
        struct Vec3 selPos;
        struct Vec3 computed;
        f32 camXZ[2];
        f32 deltaXZ[2];
        f32 targetXZ[2];
        f32 computedXZ[2];
        f32 selXZ[2];
        f32 outXZ[2];
    } work;
    u8 *camera;
    u8 *unitA;
    u8 *unitB;
    u8 *selUnit;
    u8 *otherUnit;
    f32 len;
    f32 scaleXZ;
    f32 scaleOther;
    f32 finalMul;
    f32 dot1;
    f32 dot2;
    f32 ecRet;
    f32 tanRes;
    f32 finalScale;
    f32 selZ;
    s32 mode;
    u8 *action;
    camera = arg0;
    action = *(u8 **)(camera + 0xE0);
    unitA = *(u8 **)(action + 0x30);
    unitB = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001959d0((BtlUnit *)unitA, (RwV3d *)&work.firstPos);
    func_001959d0((BtlUnit *)unitB, (RwV3d *)&work.secondPos);
    work.delta.x = work.firstPos.x - work.secondPos.x;
    work.delta.y = work.firstPos.y - work.secondPos.y;
    work.delta.z = work.firstPos.z - work.secondPos.z;
    len = func_003e40b0((RwV3d *)&work.delta, (const RwV3d *)&work.delta);
    work.camXZ[0] = *(f32 *)(camera + 0x9C) - work.firstPos.x;
    work.camXZ[1] = *(f32 *)(camera + 0xA4) - work.firstPos.z;
    func_003e41e0(work.camXZ, work.camXZ);
    work.deltaXZ[0] = work.delta.x;
    work.deltaXZ[1] = work.delta.z;
    dot1 = work.deltaXZ[1] * work.camXZ[1] + work.deltaXZ[0] * work.camXZ[0];
    if (arg1 != 0) {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
            *(s32 *)(camera + 0x104) = (dot1 >= 0.0f) ? 1 : 0;
        } else {
            *(s32 *)(camera + 0x104) = 0;
        }
    }
    if (*(s32 *)(camera + 0x104) == 1) {
        selUnit = unitA;
        otherUnit = unitB;
        func_001c_copy_pair((s64 *)&work.selPos.x, &work.selPos.z,
                            (s64 *)&work.firstPos.x, &work.firstPos.z);
        scaleOther = 1.25f * p4_cacd0_mul(*(f32 *)(unitA + 0x90), *(f32 *)(unitA + 0x2C));
        scaleXZ = 0.35f * len;
        finalMul = 1.35f;
        work.scaled.x = work.delta.x * scaleXZ;
        work.scaled.y = work.delta.y * scaleXZ;
        work.scaled.z = work.delta.z * scaleXZ;
        if (work.selPos.y < 100.0f) {
            work.selPos.y = 100.0f;
        }
        work.computed.y = work.selPos.y;
    } else {
        selUnit = unitB;
        otherUnit = unitA;
        func_001c_copy_pair((s64 *)&work.selPos.x, &work.selPos.z,
                            (s64 *)&work.secondPos.x, &work.secondPos.z);
        scaleOther = 0.35f * p4_cacd0_mul(*(f32 *)(unitB + 0x90), *(f32 *)(unitB + 0x2C));
        finalMul = 2.5f;
        work.firstPos.y = (work.firstPos.y + 0.0f) - 0.25f * p4_cacd0_mul(*(f32 *)(unitB + 0x8C), *(f32 *)(unitB + 0x2C));
        if (work.firstPos.y < 100.0f) {
            work.firstPos.y = 100.0f;
        }
        work.delta.x = work.firstPos.x - work.secondPos.x;
        work.delta.y = work.firstPos.y - work.secondPos.y;
        work.delta.z = work.firstPos.z - work.secondPos.z;
        len = func_003e40b0((RwV3d *)&work.delta, (const RwV3d *)&work.delta);
        scaleXZ = 0.25f * len;
        work.scaled.x = work.delta.x * scaleXZ;
        work.scaled.y = work.delta.y * scaleXZ;
        work.scaled.z = work.delta.z * scaleXZ;
        work.computed.y = work.selPos.y;
    }
    work.scaled.x = work.scaled.x + work.secondPos.x;
    work.scaled.y = work.scaled.y + work.secondPos.y;
    work.scaled.z = work.scaled.z + work.secondPos.z;
    work.deltaXZ[0] = work.delta.z;
    work.deltaXZ[1] = -work.delta.x;
    dot2 = work.deltaXZ[0] * work.camXZ[0] + work.deltaXZ[1] * work.camXZ[1];
    if (arg1 != 0) {
        *(s32 *)(camera + 0x108) = (dot2 >= 0.0f) ? 1 : 0;
    }
    if (*(s32 *)(camera + 0x108) == 1) {
        work.computed.x = (work.selPos.x + 0.0f) + work.delta.z * scaleOther;
        work.computed.z = (work.selPos.z + 0.0f) - work.delta.x * scaleOther;
    } else {
        work.computed.x = (work.selPos.x + 0.0f) - work.delta.z * scaleOther;
        work.computed.z = (work.selPos.z + 0.0f) + work.delta.x * scaleOther;
    }
    selZ = work.selPos.z;
    func_001bd780(&work.poseNew.quat, &work.computed, &work.scaled, D_0060A0E0);
    func_003dcb40((RwV3d *)&work.delta, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.poseNew.quat);
    work.targetXZ[0] = work.scaled.x;
    work.targetXZ[1] = work.scaled.z;
    work.computedXZ[0] = work.computed.x;
    work.computedXZ[1] = work.computed.z;
    work.selXZ[0] = work.selPos.x;
    work.selXZ[1] = selZ;
    ecRet = func_001ec3d0((u8 *)work.targetXZ, (u8 *)work.computedXZ, (u8 *)work.selXZ, (u8 *)work.outXZ);
    ecRet = ecRet + 0.0f + finalMul * p4_cacd0_mul(*(f32 *)(selUnit + 0x90), *(f32 *)(selUnit + 0x2C));
    work.computed.x = work.outXZ[0];
    work.computed.y = work.selPos.y;
    work.computed.z = work.outXZ[1];
    tanRes = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    finalScale = ecRet / tanRes;
    if (finalScale < 500.0f) {
        finalScale = 500.0f;
    }
    work.delta.x = work.delta.x * finalScale;
    work.delta.y = work.delta.y * finalScale;
    work.delta.z = work.delta.z * finalScale;
    work.poseNew.pos.x = work.computed.x + work.delta.x;
    work.poseNew.pos.y = work.computed.y + work.delta.y;
    work.poseNew.pos.z = work.computed.z + work.delta.z;
    if (work.poseNew.pos.y < 12.5f) {
        work.poseNew.pos.y = 12.5f;
    }
    func_001bd560((f32 *)&work.poseOld, (f32 *)(camera + 0x9C));
    if (arg1 != 0) {
        if (func_001ec2b0(&work.poseOld.quat, &work.poseNew.quat) > fGpffff80dc) {
            func_001bd5e0((u8 *)&work.poseOld, (u8 *)&work.poseNew);
            mode = 3;
        } else {
            mode = 0x83;
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), otherUnit + 4, (u8 *)&work.poseNew, 50.0f, mode);
    }
    func_001bac20((u16 *)camera, (f32 *)&work.poseOld, (f32 *)&work.poseNew, 1);
    func_001bbef0(camera, fparg0);
}
/* measured: closes the scope above at the file's -O2 baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cb970);
#endif
// FUN_001CBF80
void func_001cbf80(u8 *arg0) {
    *(s16 *)(arg0 + 0x10E) =
        func_001991c0(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30), 4, 1.0f);
    *(s32 *)(arg0 + 0x100) = *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38);
    *(s16 *)(arg0 + 0x10C) = 0;
}
/* measured: opt_propagation off probe for ce470 mixed-load ordering. */
#pragma opt_propagation off
// FUN_001CE470
void func_001ce470(u8 *arg0)
{
    struct Frame {
        f32 value10;
        f32 value14;
        f32 value18;
        f32 value1C;
        u8 pad20[0xC];
        f32 value2C;
        f32 value30;
        f32 value34;
        f32 value38;
        u8 tail3C[0x14];
    } frame;
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *vector;

    if (*(s32 *)(arg0 + 0xD8) == 0) {
        func_001bd780(&frame.value1C,
                      (f32 *)D_00607DD0, D_00607DF0, D_0060A0E0);
        func_001c_copy_pair((s64 *)&frame.value10,
                            &frame.value18,
                            (s64 *)D_00607DD0,
                            (f32 *)D_00607DD8);
        func_001bd780(&frame.value38,
                      D_00607E10, D_00607E30, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E10;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        func_001bbef0(iGpffffb3ac + 0x24, fGpffff819c);
        return;
    }
    if (*(s32 *)(arg0 + 0xD8) == 0x25) {
        func_001bd780(&frame.value1C,
                      D_00607DDC, D_00607DFC, D_0060A0E0);
        *(struct Vec3 *)&frame.value10 =
            *(struct Vec3 *)D_00607DDC;
        func_001bd780(&frame.value38,
                      D_00607E1C, D_00607E3C, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E1C;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        func_001bbef0(iGpffffb3ac + 0x24, fGpffff809c);
    }
}
/* measured: close ce470 opt_propagation off probe. */
#pragma opt_propagation on
// FUN_001CE620
void func_001ce620(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Frame {
        u8 matrix[0x40];
        f32 result[3];
        f32 quat[4];
        u8 pad5C[4];
        f32 transformed[3];
    } frame;
    f32 scale;

    if (*(s32 *)(arg0 + 0x120) != 0) {
        *(f32 *)(arg0 + 0x11C) =
            func_00196040(3, 0, arg0 + 0x104, 0, 0, 1);
        *(f32 *)(arg0 + 0x108) = 0.0f;
        *(s32 *)(arg0 + 0x120) = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, arg1, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)frame.transformed, (const RwV3d *)D_0060A0F0, (const RwMatrix *)frame.matrix);
    scale = (*(f32 *)(arg0 + 0x11C) * arg3) /
            tanf(fGpffff8110 *
                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.transformed[0] *= scale;
    frame.transformed[1] *= scale;
    frame.transformed[2] *= scale;
    frame.result[0] = frame.transformed[0] + *(f32 *)(arg0 + 0x104);
    frame.result[1] = frame.transformed[1] + *(f32 *)(arg0 + 0x108);
    frame.result[2] = frame.transformed[2] + *(f32 *)(arg0 + 0x10C);
    func_001bd780(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        func_001bc3a0(frame.result, frame.result);
    }
    func_001bab00(arg0, frame.result);
}
/* measured probe: optimization_level 1 for 001CE7F0 register coloring. */
#pragma optimization_level 1
// FUN_001CE7F0
void func_001ce7f0(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured probe: close optimization_level 1 for 001CE7F0. */
#pragma optimization_level 2
// FUN_001CE880
void func_001ce880(u8 *arg0) {
    func_001ce620(arg0, -17.5f, 0.25f, 0.75f);
}
// FUN_001CE8C0
void func_001ce8c0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Frame {
        u8 matrix[0x40];
        f32 result[3];
        f32 quat[4];
        u8 pad5C[4];
        f32 diff[3];
        u8 pad6C[4];
        f32 target[3];
    } frame;
    f32 scale;

    if (*(s32 *)(arg0 + 0x120) != 0) {
        func_00196040(2, 1, frame.target, 0, 0, 1);
        *(f32 *)(arg0 + 0x11C) =
            func_00196040(3, 0, arg0 + 0x104, 0, 0, 2);
        *(f32 *)(arg0 + 0x108) = 0.0f;
        frame.diff[0] = *(f32 *)(arg0 + 0x104) - frame.target[0];
        frame.diff[1] = *(f32 *)(arg0 + 0x108) - frame.target[1];
        frame.diff[2] = *(f32 *)(arg0 + 0x10C) - frame.target[2];
        scale = fGpffff8100 * func_003e40b0((RwV3d *)frame.diff, (const RwV3d *)frame.diff);
        frame.diff[0] *= scale;
        frame.diff[1] *= scale;
        frame.diff[2] *= scale;
        *(f32 *)(arg0 + 0x104) = frame.target[0] + frame.diff[0];
        *(f32 *)(arg0 + 0x108) = frame.target[1] + frame.diff[1];
        *(f32 *)(arg0 + 0x10C) = frame.target[2] + frame.diff[2];
        *(f32 *)(arg0 + 0x108) = frame.target[1];
        *(f32 *)(arg0 + 0x110) =
            *(f32 *)(arg0 + 0x104) - frame.target[0];
        *(f32 *)(arg0 + 0x114) =
            *(f32 *)(arg0 + 0x108) - frame.target[1];
        *(f32 *)(arg0 + 0x118) =
            *(f32 *)(arg0 + 0x10C) - frame.target[2];
        func_003e40b0((RwV3d *)(arg0 + 0x110),
                      (const RwV3d *)(arg0 + 0x110));
        *(s32 *)(arg0 + 0x120) = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, arg1, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)frame.diff, (const RwV3d *)(arg0 + 0x110), (const RwMatrix *)frame.matrix);
    if (*(f32 *)(arg0 + 0x11C) < 600.0f) {
        *(f32 *)(arg0 + 0x11C) = 600.0f;
    }
    scale = (*(f32 *)(arg0 + 0x11C) * arg3) /
            tanf(fGpffff8110 *
                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.diff[0] *= scale;
    frame.diff[1] *= scale;
    frame.diff[2] *= scale;
    frame.result[0] = frame.diff[0] + *(f32 *)(arg0 + 0x104);
    frame.result[1] = frame.diff[1] + *(f32 *)(arg0 + 0x108);
    frame.result[2] = frame.diff[2] + *(f32 *)(arg0 + 0x10C);
    func_001bd780(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        func_001bc3a0(frame.result, frame.result);
    }
    func_001bab00(arg0, frame.result);
}
// FUN_001CEBA0
void func_001ceba0(u8 *arg0)
{
    s32 index;
    s32 check;
    u16 index16;
    s32 count;
    u8 *current;

    *(s32 *)(arg0 + 0x100) = 0xC1900000;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
    if (*(u16 *)(arg0 + 0xD0) == 7) {
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            if (*(s32 *)(iGpffffb3ac + 0x170) != (s32)current) {
                if ((*(u16 *)(current + 0x1A) & 1) != 0) {
                    if (*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) != 1) {
                        index = 0;
                        count = *(u16 *)(iGpffffb3ac + 0xC58);
                        goto loop_test;
loop_body:
                        index16 = (u16)index;
                        if (*(u8 **)(iGpffffb3ac + 0xC48 +
                                     index16 * 4) == current) {
                            goto search_done;
                        }
                        index = (index + 1) & 0xFFFF;
loop_test:
                        check = index & 0xFFFF;
                        if (check < count) {
                            goto loop_body;
                        }
search_done:
                        if (check == count) {
                            func_00194fa0(*(u8 **)(current + 0x30), 2,
                                          count, iGpffffb3ac, index);
                            *(s8 *)(*(u8 **)(current + 0x30) + 0x37) = 0;
                        }
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
    }
}
// FUN_001CECB0
void func_001cecb0(u8 *arg0) {
    func_001ce8c0(arg0, -16.0f, fGpffff8198, fGpffff80fc);
}
// FUN_001CECE0
void func_001cece0(u8 *arg0)
{
    struct Frame {
        u8 first[0x1C];
        f32 result[3];
        u8 second[0x28];
        f32 source[4];
        f32 target[4];
    } frame;
    f32 scale;
    f32 length;
    u8 *work;

    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_001bd560(frame.first, arg0 + 0x9C);
    scale = func_00196040(3, 1, frame.target, 0, 0, 1);
    frame.target[1] = 0.0f;
    func_001958f0(work, frame.source);
    frame.source[1] +=
        (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    func_001bd780(frame.second, frame.source, frame.target, D_0060A0E0);
    scale /= tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    *(f32 *)(frame.second + 0x18) = frame.source[0] - frame.target[0];
    *(f32 *)(frame.second + 0x1C) = frame.source[1] - frame.target[1];
    *(f32 *)(frame.second + 0x20) = frame.source[2] - frame.target[2];
    length = func_003e40b0((RwV3d *)(frame.second + 0x18),
                           (const RwV3d *)(frame.second + 0x18));
    length += (*(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C) * 5.0f) /
              tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    scale = (scale > length) ? scale : length;
    *(f32 *)(frame.second + 0x18) *= scale;
    *(f32 *)(frame.second + 0x1C) *= scale;
    *(f32 *)(frame.second + 0x20) *= scale;
    frame.result[0] = *(f32 *)(frame.second + 0x18) + frame.target[0];
    frame.result[1] = *(f32 *)(frame.second + 0x1C) + frame.target[1];
    frame.result[2] = *(f32 *)(frame.second + 0x20) + frame.target[2];
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)
        func_001bc3a0(frame.result, frame.result);
    func_001bac20((u16 *)arg0, (f32 *)frame.first, frame.result, 1);
    func_001bbef0(arg0, 1.0f);
}
/* measured probe: optimization_level 1 preserves 001CEF20 low-bit OR coloring. */
#pragma optimization_level 1
// FUN_001CEF20
void func_001cef20(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured: closes optimization_level 1 for 001CEF20. */
#pragma optimization_level 2
// FUN_001CEFB0
void func_001cefb0(u8 *arg0) {
    func_001ce620(arg0, -10.0f, 0.125f, fGpffff809c);
}
// FUN_001CEFF0
void func_001ceff0(void) {
    func_001b73f0(NULL);
    func_004b3110(5);
}
// FUN_001CF020
void func_001cf020(u8 *arg0) {
    u8 sp20[0x20];

    func_001c6f40(arg0, 0, 0, 0, sp20);
    func_001bab00(arg0, sp20);
}
// FUN_001CF070
void func_001cf070(u8 *arg0, u8 *arg1)
{
    s16 mode;
    u8 *target;

    mode = *(s16 *)(*(u8 **)(arg0 + 0xE0) + 0x448);
    target = arg1;
    switch (mode) {
    case 1:
        target = (u8 *)&D_005F78C0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    case 0:
        target = (u8 *)&D_005F7AB0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    }
    func_001bdd80(arg0, target, 2);
    func_004b3110(5);
}
// FUN_001CF140
void func_001cf140(void) {
    func_001bdeb0();
}
/* measured probe: optimization_level 1 preserves 001CF160 low-bit OR coloring. */
#pragma optimization_level 1
// FUN_001CF160
void func_001cf160(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured: closes optimization_level 1 for 001CF160. */
#pragma optimization_level 2
// FUN_001CF1F0
void func_001cf1f0(u8 *arg0)
{
    struct Frame {
        u8 pad20[0x40];
        f32 vec60[3];
        f32 value6C;
        u8 pad70[0x10];
        f32 vec80[4];
        f32 vec90[4];
    } frame;

    func_00195850(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                  &frame.vec90[0]);
    frame.vec90[1] = 0.0f;
    func_003e0870((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0D0, -30.0f, 0);
    func_003e0870((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0E0,
                  *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)(u8 *)&frame.vec80[0], (const RwV3d *)D_0060A0F0, (const RwMatrix *)(u8 *)&frame);
    frame.vec60[0] = func_001c_mul_add(frame.vec80[0],
                                        400.0f, frame.vec90[0]);
    frame.vec60[1] = func_001c_mul_add(frame.vec80[1],
                                        400.0f, frame.vec90[1]);
    frame.vec60[2] = func_001c_mul_add(frame.vec80[2],
                                        400.0f, frame.vec90[2]);
    func_001bd780(&frame.value6C, &frame.vec60[0],
                  &frame.vec90[0], D_0060A0E0);
    if (frame.vec60[1] < 25.0f) {
        frame.vec60[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) = *(f32 *)(arg0 + 0x100) + 0.25f;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 4);
    func_001bab00(arg0, (u8 *)&frame.vec60[0]);
}
// FUN_001CF350
void func_001cf350(u8 *arg0)
{
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        u8 pad_to_80[8];
        u8 sp80[0x40];
        u8 pad_to_C8[8];
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        u8 pad_to_100[4];
        f32 sp100;
        f32 sp104;
        f32 sp108;
        u8 pad_to_110[4];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 var_f21;
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);

    work = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_f21 = func_00196040(3, 1, (u8 *)&frame.spD0, 0, 0, 1);
    if (var_f21 < 550.0f) {
        var_f21 = 550.0f;
    }
    func_001958f0(work, &frame.sp110);
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = 0.25f * func_003e40b0((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
    frame.spF0 = frame.sp100 * temp_f1;
    frame.spF4 = frame.sp104 * temp_f1;
    frame.spF8 = frame.sp108 * temp_f1;
    frame.spE0 = frame.spD0 + frame.spF0;
    frame.spE4 = frame.spD4 + frame.spF4;
    frame.spE8 = frame.spD8 + frame.spF8;
    var_f21 = var_f21 * fGpffff80e8;
    temp_f20 = var_f21 / tanf(fGpffff8110 *
                                         (0.5f * *(f32 *)(arg0 + 0xB8)));
    func_003e0870((RwMatrix *)frame.sp80, (const RwV3d *)D_0060A0D0, 32.5f, 0);
    func_003e4320((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.sp80);
    func_003dcb40((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    frame.sp110 = frame.sp110 + frame.spD0;
    frame.sp114 = frame.sp114 + frame.spD4;
    frame.sp118 = frame.sp118 + frame.spD8;
    func_001bd780(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    func_003dcb40((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.sp68);
    frame.sp100 = frame.spF0 * temp_f20;
    frame.sp104 = frame.spF4 * temp_f20;
    frame.sp108 = frame.spF8 * temp_f20;
    temp_f1 = temp_f20 * tanf(fGpffff8110 *
                                         (0.5f * *(f32 *)(arg0 + 0xB8)));
    temp_f1 = temp_f1 * 0.21875f;
    var_f21 = temp_f1 * fGpffff80e8;
    frame.spC8 = frame.sp100;
    frame.spCC = frame.sp108;
    func_003e41e0(&frame.spC8, &frame.spC8);
    frame.spE0 = 0.0f + frame.spE0 + frame.spCC * var_f21;
    frame.spE8 = 0.0f + frame.spE8 - frame.spC8 * var_f21;
    frame.sp5C = frame.spE0 + frame.sp100;
    frame.sp60 = frame.spE4 + frame.sp104;
    frame.sp64 = frame.spE8 + frame.sp108;
    temp_f1 = frame.sp68;
    temp_f2 = frame.sp6C;
    temp_f3 = frame.sp70;
    temp_f4 = frame.sp74;
    frame.sp4C = temp_f1;
    frame.sp50 = temp_f2;
    frame.sp54 = temp_f3;
    frame.sp58 = temp_f4;
    temp_f1 = temp_f20 - 100.0f;
    temp_f2 = frame.spF0 * temp_f1;
    frame.sp100 = temp_f2;
    temp_f3 = frame.spF4 * temp_f1;
    frame.sp104 = temp_f3;
    temp_f4 = frame.spF8 * temp_f1;
    frame.sp108 = temp_f4;
    frame.sp40 = frame.spE0 + temp_f2;
    frame.sp44 = frame.spE4 + temp_f3;
    frame.sp48 = frame.spE8 + temp_f4;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
    func_001bc3a0(&frame.sp40, &frame.sp40);
    func_001bc3a0(&frame.sp5C, &frame.sp5C);
    func_001bac20((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, 3.0f);
}
// FUN_001CF730
void func_001cf730(u8 *arg0)
{
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        u8 pad_to_80[8];
        u8 sp80[0x40];
        u8 pad_to_C8[8];
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        u8 pad_to_100[4];
        f32 sp100;
        f32 sp104;
        f32 sp108;
        u8 pad_to_110[4];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 var_f21;
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    extern f32 DAT_0076112c;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);

    work = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_f21 = func_00196040(2, 1, (u8 *)&frame.spD0, 0, 0, 1);
    func_001958f0(work, &frame.sp110);
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = DAT_0076112c * func_003e40b0((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
    frame.spF0 = frame.sp100 * temp_f1;
    frame.spF4 = frame.sp104 * temp_f1;
    frame.spF8 = frame.sp108 * temp_f1;
    frame.spE0 = frame.spD0 + frame.spF0;
    frame.spE4 = frame.spD4 + frame.spF4;
    frame.spE8 = frame.spD8 + frame.spF8;
    if (var_f21 < 450.0f) {
        var_f21 = 450.0f;
    }
    temp_f20 = var_f21 / tanf(fGpffff8110 *
                                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    func_001c_rotate((RwMatrix *)frame.sp80, (const RwV3d *)D_0060A0D0, 35.0f, 0);
    func_003e4320((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.sp80);
    func_003dcb40((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    func_001bd780(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    func_003dcb40((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.sp68);
    temp_f1 = 50.0f + temp_f20;
    frame.sp100 = frame.spF0 * temp_f1;
    frame.sp104 = frame.spF4 * temp_f1;
    frame.sp108 = frame.spF8 * temp_f1;
    var_f21 = temp_f20 * tanf(fGpffff8110 *
                                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    var_f21 = var_f21 * 0.21875f;
    var_f21 = var_f21 * fGpffff80e8;
    frame.spC8 = frame.sp100;
    frame.spCC = frame.sp108;
    func_003e41e0(&frame.spC8, &frame.spC8);
    frame.spE0 = 0.0f + frame.spE0 + frame.spCC * var_f21;
    frame.spE8 = 0.0f + frame.spE8 - frame.spC8 * var_f21;
    frame.sp5C = frame.spE0 + frame.sp100;
    frame.sp60 = frame.spE4 + frame.sp104;
    frame.sp64 = frame.spE8 + frame.sp108;
    temp_f1 = frame.sp68;
    temp_f2 = frame.sp6C;
    temp_f3 = frame.sp70;
    temp_f4 = frame.sp74;
    frame.sp4C = temp_f1;
    frame.sp50 = temp_f2;
    frame.sp54 = temp_f3;
    frame.sp58 = temp_f4;
    temp_f1 = temp_f20 - 50.0f;
    temp_f2 = frame.spF0 * temp_f1;
    frame.sp100 = temp_f2;
    temp_f3 = frame.spF4 * temp_f1;
    frame.sp104 = temp_f3;
    temp_f4 = frame.spF8 * temp_f1;
    frame.sp108 = temp_f4;
    frame.sp40 = frame.spE0 + temp_f2;
    frame.sp44 = frame.spE4 + temp_f3;
    frame.sp48 = frame.spE8 + temp_f4;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
    func_001bac20((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, 3.5f);
}
// FUN_001CFAD0
void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2)
{
    struct {
        f32 first[7];
        f32 second[7];
        RwMatrix rotation __attribute__((aligned(16)));
        f32 center[4];
        f32 direction[4];
        f32 scaled[4];
    } work;
    u8 *unit;
    u32 status;
    s32 choice;
    f32 extent;
    f32 firstScale;
    f32 y;
    extern f32 fGpffff810c;

    unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    status = func_00232710(*(s32 *)(unit + 0xA64), 0x100000);
    func_001959d0((BtlUnit *)unit, (RwV3d *)work.center);
    if (status == 0) {
        work.center[1] = 0.0f + work.center[1] + fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    } else {
        work.center[1] = 0.0f + work.center[1] - fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    }
    func_003dcb40((RwV3d *)work.direction, (const RwV3d *)D_0060A0F0, 1,
                  (const RtQuat *)(unit + 0x1C));
    work.scaled[0] = 200.0f * work.direction[0];
    work.scaled[1] = 200.0f * work.direction[1];
    work.scaled[2] = 200.0f * work.direction[2];
    y = work.center[1] + work.scaled[1];
    y = y + 55.0f;
    work.direction[0] = (work.center[0] + work.scaled[0]) - work.center[0];
    work.direction[1] = y - work.center[1];
    work.direction[2] = (work.center[2] + work.scaled[2]) - work.center[2];
    func_003e40b0((RwV3d *)work.direction, (const RwV3d *)work.direction);
    extent = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    if (extent < 75.0f) {
        extent = 75.0f;
    }
    firstScale = extent * arg1;
    arg1 = extent * arg2;
    choice = (s32)func_00231d70(2);
    switch (choice) {
    case 0:
        arg2 = 30.0f;
        break;
    case 1:
    default:
        arg2 = -30.0f;
        break;
    }
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -arg2, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    firstScale = firstScale /
        tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled[0] = work.scaled[0] * firstScale;
    work.scaled[1] = work.scaled[1] * firstScale;
    work.scaled[2] = work.scaled[2] * firstScale;
    work.first[0] = work.center[0] + work.scaled[0];
    work.first[1] = work.center[1] + work.scaled[1];
    work.first[2] = work.center[2] + work.scaled[2];
    func_001bd780(&work.first[3], work.first, work.center, D_0060A0E0);
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * arg2, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    arg1 = arg1 /
        tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled[0] = work.scaled[0] * arg1;
    work.scaled[1] = work.scaled[1] * arg1;
    work.scaled[2] = work.scaled[2] * arg1;
    work.second[0] = work.center[0] + work.scaled[0];
    work.second[1] = work.center[1] + work.scaled[1];
    work.second[2] = work.center[2] + work.scaled[2];
    func_001bd780(&work.second[3], work.second, work.center, D_0060A0E0);
    if (work.first[1] < 25.0f) {
        work.first[1] = 25.0f;
    }
    if (work.second[1] < 25.0f) {
        work.second[1] = 25.0f;
    }
    func_001b73f0(unit);
    func_001bac20((u16 *)arg0, work.first, work.second, 1);
    func_001bbef0(arg0, 3.0f);
}
// FUN_001CFED0
void func_001cfed0(u8 *arg0) {
    func_001cfad0(arg0, fGpffff8114, 2.5f);
}
// FUN_001CFF00
void func_001cff00(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec3 target;
    struct Vec3 source;
    struct {
        f32 first[10];
        u8 second[0x28];
    } fr;
    f32 speed;
    f32 half_speed;
    f32 scale;
    f32 length;
    f32 x;
    f32 y;
    f32 limit;
    u8 *work;

    func_001bd560(fr.first, arg0 + 0x9C);
    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_00195850(work, (f32 *)&target);
    target.y = *(f32 *)(work + 0x84) * *(f32 *)(work + 0x2C);
    speed = *(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C);
    half_speed = (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    source = target;
    source.y += half_speed * 0.25f;
    if (speed > half_speed) {
        scale = (3.0f * speed) /
                tanf(fGpffff8110 *
                              (0.5f * *(f32 *)(arg0 + 0xB8)));
    } else {
        scale = (3.0f * half_speed) /
                tanf(0.5f * *(f32 *)(arg0 + 0xB8));
    }
    *(f32 *)(fr.second + 0x18) =
        fr.first[0] - source.x;
    *(f32 *)(fr.second + 0x1C) =
        fr.first[1] - source.y;
    *(f32 *)(fr.second + 0x20) =
        fr.first[2] - source.z;
    length = func_003e4180((f32 *)(fr.second + 0x18));
    length *= fGpffff811c;
    *(f32 *)(fr.second + 0x18) =
        fr.first[0] - source.x;
    *(f32 *)(fr.second + 0x1C) =
        fr.first[1] - source.y;
    *(f32 *)(fr.second + 0x20) =
        fr.first[2] - source.z;
    func_003e40b0((RwV3d *)(fr.second + 0x18),
                  (const RwV3d *)(fr.second + 0x18));
    x = *(f32 *)(fr.second + 0x18) *
        ((scale > length) ? scale : length);
    y = *(f32 *)(fr.second + 0x1C) *
        ((scale > length) ? scale : length);
    scale = (scale > length) ? scale : length;
    fr.first[7] = source.x + x;
    fr.first[8] = source.y + y;
    fr.first[9] = source.z +
                      *(f32 *)(fr.second + 0x20) * scale;
    limit = target.y + half_speed * 1.25f;
    if (fr.first[8] < limit) {
        fr.first[8] = limit;
    }
    func_001bd780(fr.second, &fr.first[7], &source, D_0060A0E0);
    func_001bac20((u16 *)arg0, fr.first, &fr.first[7], 1);
    func_001bbef0(arg0, 4.5f);
}
