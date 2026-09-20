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

/* measured 001c04e0: 302/302 (0.0%) inside 293-311 band; guarded 205 words via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c04e0` (GUARDED_SCORE 205); probe 205 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c04e0 --candidate v5=/tmp/v5_declswap.c` (v1 208, v5 205, v6 207, v10 208); fnalign retail 302 vs object 302, 159 edits (+5 reloc-only) via `python3 -E -s tools/fnalign.py src/promoted/code1_001c.c func_001c04e0 --candidate /tmp/v5_declswap.c --quiet`. M2C/romwright de-noise triple-checked against Ghidra/IDA plus docs/probe_archive/M_001c04e0_body.c (1208B inside-gate shape) to file idiom with block externs (func_001bcd40(f32,u8*,u8*,u8*,u16) float-first per src/Battle/btlCamera.c, func_0044b868(f32)->f32 per 001c5500 lesson, func_003dcb40 void, func_001ec3d0(u8*) per btlCamera.c, fGpffff80fc/8030/8110). Frame 0x130 sparse with pad_to_E0/F0/100/110/120 (was packed 0xD0, +82 instrs). Per-arm 2.5*f6 + 2.25 var_f24 + obj1=obj2 switch recovered (was fused temp_f25 for D0/D8; 140-instr hole at retail[59:199]). Decl swap var_f23/var_f22 208->205; dot orders and branch flips tie. Top remaining: FPR colors (len f20 vs f25, 2.25 f21 vs f24), mula/madd vs mul/add, ld/sd scheduling, branch polarity (7p class per func_001c79f0 note). Within 3% gate, banked as floor. Prior 248/299 outside gate (219/301) not comparable per 7y. */
// FUN_001C04E0 NONMATCHING
#ifdef NON_MATCHING
void func_001c04e0(u8 *arg0)
{
    typedef union { s64 pair; struct { f32 x; f32 y; } xy; } PairF32;
    struct {
        f32 sp60[8];
        f32 sp80;
        f32 sp84;
        f32 sp88;
        f32 sp8C;
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        f32 spA4;
        f32 spA8;
        f32 spAC;
        f32 spB0;
        f32 spB4;
        f32 spB8;
        f32 spBC;
        f32 spC0;
        f32 spC4;
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
        PairF32 sp100;
        f32 sp108;
        u8 pad_to_110[4];
        PairF32 sp110;
        f32 sp118;
        u8 pad_to_120[4];
        PairF32 sp120;
        f32 sp128;
        u8 pad_tail[4];
    } frame;
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 func_0044b868(f32 arg0);
    extern void func_001bcd40(f32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u16 arg4);
    extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
    extern void func_003dcb40(void *arg0, const void *arg1, s32 arg2, const void *arg3);
    extern void func_001bd5a0(f32 *arg0, f32 *arg1);
    extern void func_001c8e90(u8 *arg0, f32 *arg1, f32 *arg2);
    extern void func_001bab00(u8 *arg0, void *arg1);
    extern f32 fGpffff80fc;
    extern f32 fGpffff8030;
    extern f32 fGpffff8110;
    extern u8 D_0060A0E0[];
    extern u8 D_0060A100[];
    u8 *obj_base;
    u8 *obj1;
    u8 *obj2;
    f32 var_f20;
    f32 var_f21;
    f32 var_f23;
    f32 var_f22;
    f32 var_f24;
    f32 var_f25;
    f32 scale;
    f32 f6;
    f32 a0;
    f32 a4;

    obj_base = *(u8 **)(arg0 + 0xE0);
    obj1 = *(u8 **)(obj_base + 0x30);
    obj2 = *(u8 **)(*(u8 **)(obj_base + 0x38) + 0x30);

    func_00195850(obj1, &frame.sp120.xy.x);
    func_00195850(obj2, &frame.sp110.xy.x);

    var_f23 = *(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C);
    var_f22 = *(f32 *)(obj2 + 0x90) * *(f32 *)(obj2 + 0x2C);

    frame.spE0 = frame.sp120.xy.x - frame.sp110.xy.x;
    frame.spE4 = frame.sp120.xy.y - frame.sp110.xy.y;
    frame.spE8 = frame.sp128 - frame.sp118;

    var_f25 = func_003e40b0(&frame.spE0, &frame.spE0);

    frame.spA8 = *(f32 *)(arg0 + 0x9C) - frame.sp120.xy.x;
    frame.spAC = *(f32 *)(arg0 + 0xA4) - frame.sp128;

    func_003e41e0(&frame.spA8, &frame.spA8);

    {
        f32 temp_f2 = fGpffff80fc * var_f25;
        frame.spF0 = frame.spE0 * temp_f2;
        frame.spF4 = frame.spE4 * temp_f2;
        frame.spF8 = frame.spE8 * temp_f2;
        frame.spF0 = frame.spF0 + frame.sp110.xy.x;
        frame.spF4 = frame.spF4 + frame.sp110.xy.y;
        frame.spF8 = frame.spF8 + frame.sp118;
    }

    a0 = frame.spE0;
    a4 = frame.spE8;
    frame.spA0 = a0;
    frame.spA4 = a4;

    {
        f32 dot1 = a0 * frame.spA8 + a4 * frame.spAC;
        if (dot1 < 0.0f) {
            obj1 = obj2;
            frame.sp100.pair = frame.sp110.pair;
            frame.sp108 = frame.sp118;
            f6 = 2.5f * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));
            var_f24 = 2.25f;
        } else {
            frame.sp100.pair = frame.sp120.pair;
            frame.sp108 = frame.sp128;
            if (frame.sp100.xy.y < 125.0f) {
                frame.sp100.xy.y = 125.0f;
            }
            f6 = 2.5f * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));
            var_f24 = 2.25f;
        }
    }

    a0 = frame.spE0;
    a4 = frame.spE8;
    frame.spA0 = a4;
    frame.spA4 = -a0;

    var_f20 = frame.sp100.xy.y;
    frame.spD4 = 0.0f + var_f20 + fGpffff8030 * (*(f32 *)(obj1 + 0x8C) * *(f32 *)(obj1 + 0x2C));

    {
        f32 b0 = a4;
        f32 b4 = -a0;
        f32 dot2 = b0 * frame.spA8 + b4 * frame.spAC;
        if (dot2 < 0.0f) {
            frame.spD0 = 0.0f + frame.sp100.xy.x - b0 * f6;
            frame.spD8 = 0.0f + frame.sp108 + a0 * f6;
        } else {
            frame.spD0 = 0.0f + frame.sp100.xy.x + b0 * f6;
            frame.spD8 = 0.0f + frame.sp108 - a0 * f6;
        }
    }

    func_001bd780(&frame.sp8C, &frame.spD0, &frame.spF0, D_0060A0E0);
    func_003dcb40(&frame.spE0, D_0060A100, 1, &frame.sp8C);

    frame.spB0 = frame.spF0;
    frame.spB4 = frame.spF8;
    frame.spB8 = frame.spD0;
    frame.spBC = frame.spD8;
    frame.spC8 = frame.sp100.xy.x;
    frame.spCC = frame.sp108;

    var_f21 = 0.0f + func_001ec3d0((u8 *)&frame.spB0, (u8 *)&frame.spB8, (u8 *)&frame.spC8, (u8 *)&frame.spC0) +
              var_f24 * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));

    frame.spD0 = frame.spC0;
    frame.spD4 = var_f20;
    frame.spD8 = frame.spC4;

    scale = var_f21 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    if (scale < 500.0f) {
        scale = 500.0f;
    }

    frame.spE0 = frame.spE0 * scale;
    frame.spE4 = frame.spE4 * scale;
    frame.spE8 = frame.spE8 * scale;

    frame.sp80 = frame.spD0 + frame.spE0;
    frame.sp84 = frame.spD4 + frame.spE4;
    frame.sp88 = frame.spD8 + frame.spE8;
    if (frame.sp84 < 25.0f) {
        frame.sp84 = 25.0f;
    }

    func_001bd5a0((f32 *)(arg0 + 0x9C), &frame.sp80);
    func_001c8e90(arg0, &frame.sp80, (f32 *)&frame.sp60[0]);
    func_001bab00(arg0, &frame.sp60[0]);

    func_001bcd40(0.5f * (var_f22 + (var_f25 + var_f23)), *(u8 **)(arg0 + 0xE0), arg0 + 0x9C, arg0 + 0x100, 3);
    if (var_f23 <= var_f22) {
        var_f23 = var_f22;
    }
    func_001bcd40(var_f23, *(u8 **)(arg0 + 0xE0), (u8 *)&frame.sp120.xy.x, (u8 *)&frame.sp110.xy.x, 3);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c04e0);
#endif
// FUN_001C09A0
void func_001c09a0(void) {}
/* Sine-poly camera floor (1168B window; obj 1156B probe 34 fnalign 40; width check
   2026-09-19: no dsll/dsra pairs, clean; frame -0xF0 matches retail). Open:
   accumulator-chain fusion (mula/madd/adda/msub via Horner + 0.0f seeds), saved-reg
   pressure, scheduler ordering. Chains decoded from retail to zero-seeded Horner sine
   polys (coeffs iGpffff8054-8108/8180); closed forms cross-checked against IDA Hex-Rays
   + Ghidra bodies. Spill model: 1bd560 writes sp40-sp58, 194ff0 writes spC8-spD0, 1bd780
   writes sp68-sp77, 3dcc70 writes sp80-spA4 (incl. spA0/A4). Family 7z (stores the compiler
   deleted as UB: loose scalars overflow callee writes, uninit f20poly/sp48 reads) / 7x
   (sd deficit tell: retail ld/sd pairs vs few-field assigns; whole-aggregate copy restores).
   Prior 900B/261 now 1156B/34 with explicit-frame struct; numbers reproducible with --candidate on extracted body.
*/
/* gate: object 289 against retail 289, +0.0% - INSIDE
   the +-3% band (280-296). fnalign 40 edits (+18 reloc-only)
   via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c09b0 --candidate <body> --quiet`.
   Prior 225/288 (-21.9%, 63 short, 183 edits) recovered via explicit-frame struct. */
/* measured 001c09b0 (owner, 2026-09-19): 289/289 exact, **34 edits**, and the most
   structural floor in the near-MATCH tail - tools/tail_classify.py counts 14 structural
   hunks against 14 register ones, where most tail floors are almost pure rotation.
   Two shapes account for nearly all of it and both were attacked and both refused:
     (a) retail batches a three-float copy - `lwc1 $f3/$f2/$f1` then `swc1` x3 - where the
         object interleaves load/store per component.  Three named temporaries measure 35,
         and a 12-byte struct assignment through a local `Trio001c09b0` type measures 40.
     (b) retail spells the float guards `c.ole.s` + `bc1t` where the object emits
         `c.olt.s` + `bc1f`.  Rewriting `a < b` as `!(b <= a)` measures 37 at the first
         site, 43 at the second, 42 at the third and 42 with all three together.
   So the 34 stands and the `c.ole.s` shape here is NOT the same lever as the
   float-to-unsigned guard, which really does respond to constant-on-the-left spelling
   (func_003768e0, 677 -> 658).  Two comparisons that look identical in the listing, one
   source-addressable and one not. */
// FUN_001C09B0 NONMATCHING
#ifdef NON_MATCHING
void func_001c09b0(u8 *arg0)
{
    extern u8 D_0060A0E0[];
    extern u8 D_0060A100[];
    extern void func_001bd560(f32 *arg0, f32 *arg1);
    extern void func_00194ff0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3);
    extern void func_001bd780(void *arg0, void *arg1, void *arg2, void *arg3);
    extern f32 func_001ec2b0(f32 *arg0, f32 *arg1);
    extern f32 func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);
    extern void func_003dcb40(s64 *arg0, s64 *arg1, s32 arg2, u8 *arg3);
    extern void func_003dc740(u8 *arg0, u8 *arg1, s32 arg2, f32 farg);
    extern f32 func_0044b868(f32 arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 fGpffff815c;
    extern f32 fGpffff804c;
    extern f32 fGpffff8160;
    extern f32 fGpffff818c;
    extern f32 fGpffff8110;
    extern f32 fGpffff8180;
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff8108;
    extern f32 fGpffff8118;

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
        f32 sp78;
        f32 sp7C;
        f32 sp80;
        f32 sp84;
        f32 sp88;
        f32 sp8C;
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        s32 spA4;
        u8 pad_A8[0x8];
        f32 spB0;
        f32 spB4;
        f32 spB8;
        f32 spBC;
        f32 spC0;
        f32 spC4;
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        f32 spDC;
        f32 spE0;
        f32 spE4;
        f32 spE8;
        f32 spEC;
    } frame;

    u8 *work;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 t;

    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_001bd560(&frame.sp40, (f32 *)(arg0 + 0x9C));
    func_00194ff0(work, (u8 *)&frame.spC8, NULL, NULL);
    frame.spCC = *(f32 *)(work + 0x84) * *(f32 *)(work + 0x2C) +
                 fGpffff8118 * (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C));
    *(s64 *)&frame.spD8 = *(s64 *)&frame.sp40;
    frame.spE0 = frame.sp48;
    frame.spDC = frame.spCC;
    func_001bd780(&frame.sp68, &frame.spD8, &frame.spC8, D_0060A0E0);
    temp_f0 = func_001ec2b0(&frame.sp4C, &frame.sp68);

    if (fGpffff815c < temp_f0) {
        t = fGpffff815c / temp_f0;
        func_003dcc70(&frame.sp4C, &frame.sp68, &frame.sp80);

        if (t <= 0.0f) {
            frame.spB0 = frame.sp4C;
            frame.spB4 = frame.sp50;
            frame.spB8 = frame.sp54;
            frame.spBC = frame.sp58;
        } else if (t >= 1.0f) {
            frame.spB0 = frame.sp68;
            frame.spB4 = frame.sp6C;
            frame.spB8 = frame.sp70;
            frame.spBC = frame.sp74;
        } else {
            temp_f0 = 1.0f - t;

            if (frame.spA4 == 0) {
                temp_f4 = temp_f0 * frame.spA0;
                temp_f3 = temp_f4 * temp_f4;
                temp_f0 = fGpffff8180 * temp_f3 + fGpffff8054;
                temp_f0 = temp_f3 * temp_f0 + fGpffff8058;
                temp_f0 = temp_f3 * temp_f0 + fGpffff805c;
                temp_f0 = temp_f3 * temp_f0 + fGpffff8060;
                temp_f1 = temp_f3 * temp_f0 + fGpffff8108;
                temp_f0 = temp_f3 * temp_f4;
                temp_f0 = temp_f0 * temp_f1 + temp_f4;

                temp_f4 = t * frame.spA0;
                temp_f3 = temp_f4 * temp_f4;
                temp_f2 = fGpffff8180 * temp_f3 + fGpffff8054;
                temp_f2 = temp_f3 * temp_f2 + fGpffff8058;
                temp_f2 = temp_f3 * temp_f2 + fGpffff805c;
                temp_f2 = temp_f3 * temp_f2 + fGpffff8060;
                temp_f1 = temp_f3 * temp_f2 + fGpffff8108;
                temp_f2 = temp_f3 * temp_f4;
                t = temp_f2 * temp_f1 + temp_f4;
            }

            frame.spB0 = frame.sp80 * temp_f0;
            frame.spB4 = frame.sp84 * temp_f0;
            frame.spB8 = frame.sp88 * temp_f0;
            frame.spB0 = 0.0f + frame.spB0 + frame.sp90 * t;
            frame.spB4 = 0.0f + frame.spB4 + frame.sp94 * t;
            frame.spB8 = 0.0f + frame.spB8 + frame.sp98 * t;
            frame.spBC = frame.sp8C * temp_f0 + frame.sp9C * t;
        }

        func_003dcb40((s64 *)&frame.spD8, (s64 *)D_0060A100, 1, (u8 *)&frame.spB0);
        frame.spD8 = frame.spD8 + frame.spC8;
        frame.spDC = frame.spDC + frame.spCC;
        frame.spE0 = frame.spE0 + frame.spD0;
        func_001bd780(&frame.sp68, &frame.spD8, &frame.spC8, D_0060A0E0);
    } else if (temp_f0 < fGpffff804c) {
        func_003dc740((u8 *)&frame.sp68, D_0060A0E0, 2, fGpffff8160);
    }

    func_003dcb40((s64 *)&frame.spD8, (s64 *)D_0060A100, 1, (u8 *)&frame.sp68);

    t = 375.0f / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.spD8 = frame.spD8 * t;
    frame.spDC = frame.spDC * t;
    frame.spE0 = frame.spE0 * t;

    temp_f0 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    t = t * temp_f0 * 0.21875f;

    frame.spE8 = frame.spD8;
    frame.spEC = frame.spE0;
    func_003e41e0(&frame.spE8, &frame.spE8);

    frame.spC8 = 0.0f + frame.spC8 + frame.spEC * t;
    frame.spD0 = 0.0f + frame.spD0 - frame.spE8 * t;
    frame.sp5C = frame.spC8 + frame.spD8;
    frame.sp60 = frame.spCC + frame.spDC;
    frame.sp64 = frame.spD0 + frame.spE0;

    if (frame.sp60 < 25.0f) {
        frame.sp60 = 25.0f;
    }

    func_001bac20((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, fGpffff818c);
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
/* measured 001c17a0: 332 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c17a0` (GUARDED_SCORE 332); probe 332 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c17a0 --candidate v3=/var/tmp/cold1c17a0/v3.c`; fnalign retail 499 vs object 496 instrs, 41 edits (+24 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c17a0 --candidate /var/tmp/cold1c17a0/v3.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c17a0 -o /var/tmp/cold1c17a0/m2c.c`; de-noised to file idiom reusing existing decls (func_001bc330(u8*), func_00195850(u8*,f32*), func_003dcb40(RwV3d*,const RwV3d*,s32,const RtQuat*), func_001bd780, func_003e41e0(f32*,f32*), func_003e40b0, func_003e0870, func_003e4320, func_0044b868(f32)->f32, func_0019de70(BtlUnitStateWork*,u16), func_001d0730, func_001bcd40(u8*,u8*,u8*,f32,u16), func_001bac20, func_001bbef0, D_0060A0E0/D_0060A0F0, iGpffffb3ac/iGpffffb3e0, fGpffff8110/fGpffff80e8). Frame 0x1A0 with mat80+2+2+3+16+3+16+3+pad+2+3+pad+3+pad+3+pad+3+pad+3+pad+3+pad+3+pad (0x120 locals). Round1 v1 457 (500 vs 506, 77+22) -> v2 450 (499 vs 495, 60+22): s32 var_16 (was u16, removes bltz/srl tail) + dot order [0]*[0]+[1]*[1]. Round2 v3 332 (499 vs 496, 41+24, -118): reversed float decls (var_f20 first) + baseY/baseZ cache of base160[1]/[2] removes second-phase reloads and restores 8 FPU saves; v4 split side (var*tan then *0.21875) ties 450. Round3 v5 338 (hoisted unk2C/unk8C/unk90 before copies, worse +6), v6 332 tie (split side on v3 base). Round4 v7/v8 332 ties (dot revert, plain 0.0f+ removal). Two unproductive rounds, stopping. Top remaining: 0x8C/0x90 vs copy scheduling (retail loads 0x90 before ld/sd, object after), FPU coloring shift (retail $f27/$f22/$f24 vs object $f24/$f25/$f22; side retail mul $f25,$f1,$f0 vs object $f27,$f0,$f1), CSE reuse of focus170 (object sub $f0,$f0,$f20 from center) vs retail reload 0x178, quat/DC argument scheduling. */
// FUN_001C17A0 NONMATCHING
#ifdef NON_MATCHING
void func_001c17a0(u8 *arg0, s32 arg1, s32 arg2)
{
    struct Frame {
        u8 mat80[0x40];
        f32 horizC0[2];
        f32 horizC8[2];
        f32 outD0[3];
        u8 quatDC[0x10];
        f32 outEC[3];
        u8 quatF8[0x10];
        f32 saved108[3];
        u8 pad114[4];
        f32 horiz118[2];
        f32 dir120[3];
        u8 pad12C[4];
        f32 tmp130[3];
        u8 pad13C[4];
        f32 center140[3];
        u8 pad14C[4];
        f32 center150[3];
        u8 pad15C[4];
        f32 base160[3];
        u8 pad16C[4];
        f32 focus170[3];
        u8 pad17C[4];
        f32 tmp180[3];
        u8 pad18C[4];
        f32 dir190[3];
        u8 pad19C[4];
    } frame;
    extern s32 func_001bc330(u8 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);
    extern f32 fGpffff80e8;
    extern f32 fGpffff8110;
    s32 isAlt;
    u8 *work;
    u8 *unit;
    u8 *res;
    u16 *anim;
    s32 var_16;
    f32 var_f20;
    f32 var_f25;
    f32 var_f26;
    f32 var_f22;
    f32 var_f27;
    f32 var_f23;
    f32 var_f24;
    f32 baseY;
    f32 baseZ;
    (void)arg2;
    isAlt = func_001bc330(arg0) != 0;
    work = *(u8 **)(arg0 + 0xE0);
    if ((*(u16 *)(work + 0x1A) & 0x10) == 0) {
        return;
    }
    unit = *(u8 **)(work + 0x30);
    res = *(u8 **)(unit + 0xA0C);
    if (isAlt == 0) {
        anim = func_001d0730(*(u16 *)(res + 0xA4), 1);
        if ((*(u16 *)(iGpffffb3e0 + *(u16 *)(res + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)res, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)res, 1);
        }
        func_003dcb40((RwV3d *)&frame.tmp180, (const RwV3d *)((u8 *)anim + 4), 1, (const RtQuat *)(unit + 0x1C));
        func_003dcb40((RwV3d *)&frame.focus170, (const RwV3d *)((u8 *)anim + 0x1C), 1, (const RtQuat *)(unit + 0x1C));
        func_001bd780(&frame.quatDC, &frame.tmp180, &frame.focus170, D_0060A0E0);
        frame.outD0[0] = frame.tmp180[0] + *(f32 *)(unit + 4);
        frame.outD0[1] = frame.tmp180[1] + *(f32 *)(unit + 8);
        frame.outD0[2] = frame.tmp180[2] + *(f32 *)(unit + 0xC);
        func_003dcb40((RwV3d *)&frame.tmp180, (const RwV3d *)((u8 *)anim + 0x10), 1, (const RtQuat *)(unit + 0x1C));
        func_003dcb40((RwV3d *)&frame.focus170, (const RwV3d *)((u8 *)anim + 0x28), 1, (const RtQuat *)(unit + 0x1C));
        func_001bd780(&frame.quatF8, &frame.tmp180, &frame.focus170, D_0060A0E0);
        frame.outEC[0] = frame.tmp180[0] + *(f32 *)(unit + 4);
        frame.outEC[1] = frame.tmp180[1] + *(f32 *)(unit + 8);
        frame.outEC[2] = frame.tmp180[2] + *(f32 *)(unit + 0xC);
        var_16 = *anim;
    } else {
        func_00195850(unit, frame.center150);
        func_00195850(res, frame.center140);
        var_f24 = 0.0f + frame.center150[1] + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        func_001c_copy_pair((s64 *)&frame.saved108[0], &frame.saved108[2], (s64 *)&frame.center150[0], &frame.center150[2]);
        func_001c_copy_pair((s64 *)&frame.base160[0], &frame.base160[2], (s64 *)&frame.saved108[0], &frame.saved108[2]);
        func_001c_copy_pair((s64 *)&frame.focus170[0], &frame.focus170[2], (s64 *)&frame.saved108[0], &frame.saved108[2]);
        baseY = frame.base160[1];
        baseZ = frame.base160[2];
        var_f23 = 1.0f + var_f24;
        var_f27 = 5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
        frame.horizC8[0] = *(f32 *)(arg0 + 0x9C) - frame.focus170[0];
        frame.horizC8[1] = *(f32 *)(arg0 + 0xA4) - frame.focus170[2];
        func_003e41e0(frame.horizC8, frame.horizC8);
        func_003dcb40((RwV3d *)&frame.dir120, (const RwV3d *)D_0060A0F0, 1, (const RtQuat *)(unit + 0x1C));
        frame.horizC0[0] = frame.dir120[2];
        frame.horizC0[1] = -frame.dir120[0];
        func_003e41e0(frame.horizC0, frame.horizC0);
        var_f22 = frame.horizC0[0] * frame.horizC8[0] + frame.horizC0[1] * frame.horizC8[1];
        if (!(var_f22 < 0.0f)) {
            func_003e0870((RwMatrix *)frame.mat80, (const RwV3d *)D_0060A0E0, 37.5f, 0);
        } else {
            func_003e0870((RwMatrix *)frame.mat80, (const RwV3d *)D_0060A0E0, -37.5f, 0);
        }
        func_003e4320((RwV3d *)&frame.dir190, (const RwV3d *)&frame.dir120, (const RwMatrix *)frame.mat80);
        frame.dir190[0] = frame.dir190[0] * var_f27;
        frame.dir190[1] = frame.dir190[1] * var_f27;
        frame.dir190[2] = frame.dir190[2] * var_f27;
        frame.tmp130[0] = frame.dir190[0] + frame.base160[0];
        frame.tmp130[1] = frame.dir190[1] + baseY;
        frame.tmp130[2] = frame.dir190[2] + baseZ;
        if (var_f24 < var_f23) {
            frame.tmp130[1] = fGpffff80e8 * var_f23;
        }
        frame.dir190[0] = frame.tmp130[0] - frame.focus170[0];
        frame.dir190[1] = frame.tmp130[1] - frame.focus170[1];
        frame.dir190[2] = frame.tmp130[2] - frame.focus170[2];
        func_003e40b0((RwV3d *)&frame.dir190, (const RwV3d *)&frame.dir190);
        func_001bd780(&frame.quatF8, &frame.tmp130, &frame.focus170, D_0060A0E0);
        var_f26 = var_f27 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        var_f25 = var_f26 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f;
        frame.horiz118[0] = frame.dir190[0];
        frame.horiz118[1] = frame.dir190[2];
        func_003e41e0(frame.horiz118, frame.horiz118);
        frame.focus170[0] = 0.0f + frame.focus170[0] + frame.horiz118[1] * var_f25;
        frame.focus170[2] = 0.0f + frame.focus170[2] - frame.horiz118[0] * var_f25;
        frame.tmp130[0] = frame.dir190[0] * var_f26;
        frame.tmp130[1] = frame.dir190[1] * var_f26;
        frame.tmp130[2] = frame.dir190[2] * var_f26;
        frame.outEC[0] = frame.focus170[0] + frame.tmp130[0];
        frame.outEC[1] = frame.focus170[1] + frame.tmp130[1];
        frame.outEC[2] = frame.focus170[2] + frame.tmp130[2];
        if (!(var_f22 < 0.0f)) {
            func_003e0870((RwMatrix *)frame.mat80, (const RwV3d *)D_0060A0E0, 70.0f, 0);
        } else {
            func_003e0870((RwMatrix *)frame.mat80, (const RwV3d *)D_0060A0E0, -70.0f, 0);
        }
        func_003e4320((RwV3d *)&frame.dir190, (const RwV3d *)&frame.dir120, (const RwMatrix *)frame.mat80);
        frame.dir190[0] = frame.dir190[0] * var_f27;
        frame.dir190[1] = frame.dir190[1] * var_f27;
        frame.dir190[2] = frame.dir190[2] * var_f27;
        frame.tmp130[0] = frame.dir190[0] + frame.base160[0];
        frame.tmp130[1] = frame.dir190[1] + baseY;
        frame.tmp130[2] = frame.dir190[2] + baseZ;
        if (var_f24 < var_f23) {
            frame.tmp130[1] = fGpffff80e8 * var_f23;
        }
        frame.dir190[0] = frame.tmp130[0] - frame.focus170[0];
        frame.dir190[1] = frame.tmp130[1] - frame.focus170[1];
        frame.dir190[2] = frame.tmp130[2] - frame.focus170[2];
        func_003e40b0((RwV3d *)&frame.dir190, (const RwV3d *)&frame.dir190);
        func_001c_copy_pair((s64 *)&frame.focus170[0], &frame.focus170[2], (s64 *)&frame.saved108[0], &frame.saved108[2]);
        func_001bd780(&frame.quatDC, &frame.tmp130, &frame.focus170, D_0060A0E0);
        var_f20 = var_f26 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f;
        frame.horiz118[0] = frame.dir190[0];
        frame.horiz118[1] = frame.dir190[2];
        func_003e41e0(frame.horiz118, frame.horiz118);
        frame.focus170[0] = 0.0f + frame.focus170[0] + frame.horiz118[1] * var_f20;
        frame.focus170[2] = 0.0f + frame.focus170[2] - frame.horiz118[0] * var_f20;
        frame.tmp130[0] = frame.dir190[0] * var_f26;
        frame.tmp130[1] = frame.dir190[1] * var_f26;
        frame.tmp130[2] = frame.dir190[2] * var_f26;
        frame.outD0[0] = frame.focus170[0] + frame.tmp130[0];
        frame.outD0[1] = frame.focus170[1] + frame.tmp130[1];
        frame.outD0[2] = frame.focus170[2] + frame.tmp130[2];
        var_16 = 0x4B;
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
    func_001bac20((u16 *)(iGpffffb3ac + 0x24), frame.outD0, frame.outEC, 1);
    func_001bbef0(iGpffffb3ac + 0x24, (f32)var_16 / 30.0f);
    if (arg1 != 0) {
        func_004b3110(8);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c17a0);
#endif
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
/* cold 001c21d0 (2026-09-18): refused - outside 3% count gate, production stays INCLUDE_ASM. */
/* probe 689 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c21d0 --candidate commons_off=/var/tmp/cold1c21d0/v3_commons_off.c` (v1 695, v3 696, v4 696, decl swaps tie 689); fnalign retail 833 vs object 710 instrs (123 short, -14.8%; gate 808-858) 1026 edits (+2 reloc-only) via `python3 -E -s tools/fnalign.py src/promoted/code1_001c.c func_001c21d0 --candidate /var/tmp/cold1c21d0/v3_commons_off.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c21d0 -o /var/tmp/cold1c21d0/m2c.c`; romwright via `python3 -E -s tools/romwright_decompile.py func_001c21d0 > /var/tmp/cold1c21d0/rw.c` (--types: arity 3, arg0 pointer, arg1/2 scalar; prologue reads $4/$5/$6 before write, so (u8 *, s32, s32) stands) plus --raw. De-noised to file idiom reusing existing decls (func_00195850, func_0022f950, func_001bc330/0240/01b0, func_003e40b0, func_003e41e0, func_003dcb40, func_001bd780, func_001ec3d0, func_0044b868, func_004bd050, func_001bac20/bbef0/9de70/bcd40). Read func_001c79f0 MATCH note (7p snapshot placement: before first Y output 0, one statement earlier 5, three earlier 20) and code1_001f.c func_001f4e50 57->13 (row address plus two element pointers dereferenced at zero, second assigned lazily). Recipe in order: (1) free pragmas - opt_common_subs off 696->689 scoped push/pop, opt_loop_invariants on tie, opt_unroll_loops off tie, schedule off tie; (2) subscript form - no variable index in this unit (constant 0x2C/0x8C/0x90/0xA4 field loads), P[i] probe not applicable; (3) fresh loop counters (7n) - no backwards branches in retail (all forward b/bc1, zero for/while in either decompiler), nothing to split; (4) colouring - decl swaps for temp_v9/temp_v12 and vis21/alt16 tie at 689. Branch-order fix (romwright swapped the two large arms: 1.25f path first vs retail 2.5f path first) moved fnalign 960->929 edits but words 695->696. Width fixes (u64->u32, int quat->f32) scored 696. Two non-improving rounds above 60, stopping per batch. Gap lives in missing aggregate spills, not calls: jal counts exact both sides (4x00195850, 3x0019de70, 1x001bac20/bbef0/bc1b0/bc240/bc330/bcd40, 3x001bd780, 2x001ec3d0, 1x0022f950, 2x003dcb40, 1x003e0870, 2x003e40b0/41e0, 1x003e4320, 3x0044b868, 1x004b3110/bd050); frame retail -0x200 vs object -0x140 (192B of spills absent); largest fnalign holes are retail[434:471] 37 vs object 1 (quatFC copy plus out10C add plus 25.0 clamp), retail[138:156] 18 (0x2EE/cvt plus fGp80fc/8140 select plus fGp8118 scale), retail[565:585] 20. Excluded: scheduling (off tie), loop-invariant hoists, unrolling, declaration colouring, inverted-condition vs swapped-arm spellings. Best candidate kept at /var/tmp/cold1c21d0/v3_commons_off.c (689) for the next pass, which should rebuild it on a Frame from 0xB0 to 0x1F8 with 16-byte-aligned vector/quat fields. */
/* cold 001c21d0 (2026-09-19): honest redo per Main — 138:156 recovered (18, real, explicit (f32)0x2EE + volatile f32, gone from >15 list); surplus at 740:761 removed (pure-float 548 vs 833 -285 774 edits, no object-larger vs baseline 710 with 11 vs 40 + 9 vs 41); 434:471 37 vs 1 (quatFC copy + out10C add + 25.0 clamp) and 565:585 24 vs 1 (saves + madd) still missing (61); volatile 855 vs 836 +19 1008 edits frame -0x200 vs -0x180 128B game jal 32 exact in band only via cancelling (61 missing +64 lump 21 vs 85 at 740:761) refused per 7u; production stays INCLUDE_ASM. */
/* measured 001c21d0: probe 764 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c21d0 --candidate frame=/tmp/cand_21d0_frame.c` (v3_commons_off 689 is a short-body artefact per handoff 7y: 710 instrs sliding out of alignment); fnalign retail 833 vs object 832 instrs (-0.1%, 1 short, gate 808-858), 218 edits (+22 reloc-only); composition max pure hole 11 (reg-name phantom over retail h5/h21 f5/f21 vs object f6/f20, same 11 instrs present) max pure lump 2 - CLEAN, no hole-against-lump. Explicit frame struct at retail offsets (matB0..ctr1F0, no pad00 so the struct sits at sp+0xB0 for a 0x200 frame); 0.0f-seeded adda/madd shapes; (f32)0x2EE/(f32)0x226 int-converts; per-use tanf recompute; NEG-path focus recompute with 0.5*len (f25). */
/* gate: object 832 against retail 833, -0.1% - INSIDE the +-3% band (808-858). */
// FUN_001C21D0 NONMATCHING
#ifdef NON_MATCHING
void func_001c21d0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 func_001bc330(u8 *arg0);
    extern s32 func_001bc240(u8 *arg0);
    extern s32 func_001bc1b0(u8 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_003dcb40(void *arg0, const void *arg1, s32 arg2, const void *arg3);
    extern f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 func_0044b868(f32 arg0);
    extern f32 fGpffff8030;
    extern f32 fGpffff8098;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;
    extern f32 fGpffff813c;
    extern f32 fGpffff8140;
    struct {
        u8 matB0[0x40];
        f32 outF0[3];
        f32 quatFC[4];
        f32 out10C[3];
        f32 copy118[4];
        u8 pad128[8];
        f32 side130[2];
        f32 horiz138[2];
        f32 in140[4];
        u8 pad150[8];
        f32 dir158[3];
        u8 pad164[4];
        f32 norm168[2];
        f32 out170[2];
        f32 copy178[2];
        f32 save180[3];
        u8 pad18C[4];
        f32 tgt190[3];
        u8 pad19C[4];
        f32 dir1A0[3];
        u8 pad1AC[4];
        f32 focus1B0[3];
        u8 pad1BC[4];
        f32 save1C0[3];
        u8 pad1CC[4];
        f32 ctr1D0[3];
        u8 pad1DC[4];
        f32 ctr1E0[3];
        u8 pad1EC[4];
        f32 ctr1F0[3];
        u8 pad1FC[4];
    } frame;
    u8 *work;
    u8 *unit;
    u8 *target;
    u8 *res;
    s32 vis;
    s32 alt;
    s32 need240;
    f32 A;
    f32 B;
    f32 E;
    f32 C;
    f32 scale;
    f32 dot;
    f32 len;
    f32 ecRet;

    work = *(u8 **)(arg0 + 0xE0);
    unit = *(u8 **)(work + 0x30);
    target = *(u8 **)(*(u8 **)(work + 0x38) + 0x30);
    res = *(u8 **)(unit + 0xA0C);
    vis = func_0022f950(work, res) != 0;
    alt = func_001bc330(arg0) != 0;
    func_00195850(unit, frame.ctr1F0);
    func_00195850(res, frame.ctr1D0);
    A = 0.0f + frame.ctr1F0[1] + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    B = 0.0f + frame.ctr1D0[1] + 0.5f * (*(f32 *)(res + 0x8C) * *(f32 *)(res + 0x2C));
    if ((vis == 0) && (A < B) && (alt == 0)) {
        frame.ctr1F0[1] = 0.25f * (A + B);
        A = B;
    }
    C = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    {
        f32 D = *(f32 *)(res + 0x90) * *(f32 *)(res + 0x2C);
        if ((vis == 0) && (C < D) && (alt == 0)) {
            C = D;
        }
    }
    func_00195850(target, frame.ctr1E0);
    {
        f32 prod = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
        E = 0.0f + frame.ctr1E0[1] + 0.5f * prod;
        if (E >= 450.0f) {
            frame.ctr1E0[1] = (0.0f + frame.ctr1E0[1]) - fGpffff8098 * prod;
            E = 450.0f;
        }
    }
    need240 = func_001bc240(arg0);
    scale = 1.0f;
    if ((alt == 0) && (need240 == 0) && ((*(u16 *)(iGpffffb3e0 + *(u16 *)(res + 0xA4) * 0x58) & 1) != 0)) {
        if (B < (f32)0x2EE) {
            frame.ctr1F0[1] = fGpffff80fc * B;
        } else {
            frame.ctr1F0[1] = fGpffff8140 * B;
        }
        frame.ctr1E0[1] = fGpffff8118 * E;
        scale = 1.5f;
    }
    frame.dir1A0[0] = frame.ctr1F0[0] - frame.ctr1E0[0];
    frame.dir1A0[1] = frame.ctr1F0[1] - frame.ctr1E0[1];
    frame.dir1A0[2] = frame.ctr1F0[2] - frame.ctr1E0[2];
    len = func_003e40b0((RwV3d *)&frame.dir1A0[0], (const RwV3d *)&frame.dir1A0[0]);
    {
        f32 s1 = fGpffff8128 * len;
        frame.focus1B0[0] = frame.dir1A0[0] * s1;
        frame.focus1B0[1] = frame.dir1A0[1] * s1;
        frame.focus1B0[2] = frame.dir1A0[2] * s1;
        frame.focus1B0[0] = frame.focus1B0[0] + frame.ctr1E0[0];
        frame.focus1B0[1] = frame.focus1B0[1] + frame.ctr1E0[1];
        frame.focus1B0[2] = frame.focus1B0[2] + frame.ctr1E0[2];
    }
    frame.horiz138[0] = *(f32 *)(arg0 + 0x9C) - frame.focus1B0[0];
    frame.horiz138[1] = *(f32 *)(arg0 + 0xA4) - frame.focus1B0[2];
    func_003e41e0(frame.horiz138, frame.horiz138);
    if ((need240 != 0) || (((func_004bd050(0) & 1) != 0) && (func_001bc1b0(arg0) != 0))) {
        f32 side;
        f32 tprod;
        func_0019de70((BtlUnitStateWork *)res, 1);
        *(u8 **)(arg0 + 0x12C) = res;
        *(u16 *)(arg0 + 0x130) = 0;
        unit = target;
        func_001c_copy_pair((s64 *)&frame.save1C0[0], &frame.save1C0[2], (s64 *)&frame.ctr1F0[0], &frame.ctr1F0[2]);
        side = 2.25f * C;
        scale = fGpffff8138 * scale;
        frame.side130[0] = frame.dir1A0[2];
        frame.side130[1] = -frame.dir1A0[0];
        dot = frame.side130[1] * frame.horiz138[1] + frame.side130[0] * frame.horiz138[0];
        if (A < E) {
            frame.tgt190[1] = 0.0f + frame.save1C0[1] + fGpffff8030 * A;
        } else {
            frame.tgt190[1] = (0.0f + frame.save1C0[1]) - fGpffff8030 * A;
        }
        if (dot >= 0.0f) {
            frame.tgt190[0] = 0.0f + frame.save1C0[0] + frame.dir1A0[2] * side;
            frame.tgt190[2] = (0.0f + frame.save1C0[2]) - frame.dir1A0[0] * side;
        } else {
            frame.tgt190[0] = (0.0f + frame.save1C0[0]) - frame.dir1A0[2] * side;
            frame.tgt190[2] = 0.0f + frame.save1C0[2] + frame.dir1A0[0] * side;
            {
                f32 rs = 0.5f * len;
                frame.focus1B0[0] = frame.dir1A0[0] * rs;
                frame.focus1B0[1] = frame.dir1A0[1] * rs;
                frame.focus1B0[2] = frame.dir1A0[2] * rs;
                frame.focus1B0[0] = frame.focus1B0[0] + frame.ctr1E0[0];
                frame.focus1B0[1] = frame.focus1B0[1] + frame.ctr1E0[1];
                frame.focus1B0[2] = frame.focus1B0[2] + frame.ctr1E0[2];
            }
        }
        tprod = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
        frame.focus1B0[1] = (0.0f + frame.focus1B0[1]) + fGpffff8030 * tprod;
        if (dot >= 0.0f) {
            func_003e0870((RwMatrix *)frame.matB0, (const RwV3d *)D_0060A0F0, 2.5f, 0);
        } else {
            func_003e0870((RwMatrix *)frame.matB0, (const RwV3d *)D_0060A0F0, -2.5f, 0);
        }
        func_003e4320((RwV3d *)&frame.dir158[0], (const RwV3d *)D_0060A0E0, (const RwMatrix *)frame.matB0);
        func_001bd780(&frame.quatFC[0], &frame.tgt190[0], &frame.focus1B0[0], &frame.dir158[0]);
        func_003dcb40((RwV3d *)&frame.dir1A0[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quatFC[0]);
        frame.in140[0] = frame.focus1B0[0];
        frame.in140[1] = frame.focus1B0[2];
        frame.in140[2] = frame.tgt190[0];
        frame.in140[3] = frame.tgt190[2];
        frame.copy178[0] = frame.save1C0[0];
        frame.copy178[1] = frame.save1C0[2];
        ecRet = func_001ec3d0((u8 *)&frame.in140[0], (u8 *)&frame.in140[2], (u8 *)&frame.copy178[0], (u8 *)&frame.out170[0]);
        scale = 0.0f + ecRet + C * scale;
        frame.tgt190[0] = frame.out170[0];
        frame.tgt190[1] = 0.0f + frame.save1C0[1] + 0.25f * A;
        frame.tgt190[2] = frame.out170[1];
        scale = scale / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        frame.dir1A0[0] = frame.dir1A0[0] * scale;
        frame.dir1A0[1] = frame.dir1A0[1] * scale;
        frame.dir1A0[2] = frame.dir1A0[2] * scale;
        if (dot < 0.0f) {
            scale = scale * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f * 1.25f;
            frame.norm168[0] = frame.dir1A0[0];
            frame.norm168[1] = frame.dir1A0[2];
            func_003e41e0(frame.norm168, frame.norm168);
            frame.tgt190[0] = 0.0f + frame.tgt190[0] + frame.norm168[1] * scale;
            frame.tgt190[2] = (0.0f + frame.tgt190[2]) - frame.norm168[0] * scale;
        }
        frame.copy118[0] = frame.quatFC[0];
        frame.copy118[1] = frame.quatFC[1];
        frame.copy118[2] = frame.quatFC[2];
        frame.copy118[3] = frame.quatFC[3];
        frame.out10C[0] = frame.dir1A0[0] + frame.tgt190[0];
        frame.out10C[1] = frame.dir1A0[1] + frame.tgt190[1];
        frame.out10C[2] = frame.dir1A0[2] + frame.tgt190[2];
        if (frame.out10C[1] < 25.0f) {
            frame.out10C[1] = 25.0f;
        }
        frame.tgt190[1] = (0.0f + frame.tgt190[1]) - fGpffff8118 * A;
        frame.outF0[0] = frame.tgt190[0] + frame.dir1A0[0];
        frame.outF0[1] = frame.tgt190[1] + frame.dir1A0[1];
        frame.outF0[2] = frame.tgt190[2] + frame.dir1A0[2];
        if (frame.outF0[1] < 25.0f) {
            frame.outF0[1] = 25.0f;
        }
        scale = 3.0f;
    } else {
        f32 h5;
        f32 h21;
        if ((*(u16 *)(iGpffffb3e0 + *(u16 *)(res + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)res, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)res, 1);
        }
        *(u8 **)(arg0 + 0x12C) = res;
        *(u16 *)(arg0 + 0x130) = 1;
        func_001c_copy_pair((s64 *)&frame.save1C0[0], &frame.save1C0[2], (s64 *)&frame.ctr1E0[0], &frame.ctr1E0[2]);
        if (frame.save1C0[1] < 125.0f) {
            frame.save1C0[1] = 125.0f;
        }
        h5 = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        h21 = 1.5f * scale;
        frame.side130[0] = frame.dir1A0[2];
        frame.side130[1] = -frame.dir1A0[0];
        dot = frame.side130[1] * frame.horiz138[1] + frame.side130[0] * frame.horiz138[0];
        frame.tgt190[1] = frame.save1C0[1];
        if (dot >= 0.0f) {
            frame.tgt190[0] = 0.0f + frame.save1C0[0] + frame.dir1A0[2] * h5;
            frame.tgt190[2] = (0.0f + frame.save1C0[2]) - frame.dir1A0[0] * h5;
            func_001c_copy_pair((s64 *)&frame.save180[0], &frame.save180[2], (s64 *)&frame.dir1A0[0], &frame.dir1A0[2]);
        } else {
            frame.tgt190[0] = (0.0f + frame.save1C0[0]) - frame.dir1A0[2] * h5;
            frame.tgt190[2] = 0.0f + frame.save1C0[2] + frame.dir1A0[0] * h5;
        }
        func_001bd780(&frame.quatFC[0], &frame.tgt190[0], &frame.focus1B0[0], D_0060A0E0);
        func_003dcb40((RwV3d *)&frame.dir1A0[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quatFC[0]);
        frame.in140[0] = frame.focus1B0[0];
        frame.in140[1] = frame.focus1B0[2];
        frame.in140[2] = frame.tgt190[0];
        frame.in140[3] = frame.tgt190[2];
        frame.copy178[0] = frame.save1C0[0];
        frame.copy178[1] = frame.save1C0[2];
        ecRet = func_001ec3d0((u8 *)&frame.in140[0], (u8 *)&frame.in140[2], (u8 *)&frame.copy178[0], (u8 *)&frame.out170[0]);
        h21 = 0.0f + ecRet + h21 * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        frame.tgt190[0] = frame.out170[0];
        frame.tgt190[1] = frame.save1C0[1];
        frame.tgt190[2] = frame.out170[1];
        {
            f32 sc = h21 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
            if (sc < (f32)0x226) {
                sc = (f32)0x226;
            }
            frame.dir1A0[0] = frame.dir1A0[0] * sc;
            frame.dir1A0[1] = frame.dir1A0[1] * sc;
            frame.dir1A0[2] = frame.dir1A0[2] * sc;
        }
        if (dot >= 0.0f) {
            f32 h = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            frame.tgt190[0] = (0.0f + frame.tgt190[0]) - frame.save180[2] * h;
            frame.tgt190[2] = 0.0f + frame.tgt190[2] + frame.save180[0] * h;
        }
        frame.outF0[0] = frame.tgt190[0] + frame.dir1A0[0];
        frame.outF0[1] = frame.tgt190[1] + frame.dir1A0[1];
        frame.outF0[2] = frame.tgt190[2] + frame.dir1A0[2];
        frame.copy118[0] = frame.quatFC[0];
        frame.copy118[1] = frame.quatFC[1];
        frame.copy118[2] = frame.quatFC[2];
        frame.copy118[3] = frame.quatFC[3];
        frame.out10C[0] = frame.outF0[0];
        frame.out10C[1] = frame.outF0[1];
        frame.out10C[2] = frame.outF0[2];
        frame.dir1A0[0] = frame.ctr1F0[0] - frame.out10C[0];
        frame.dir1A0[1] = frame.ctr1F0[1] - frame.out10C[1];
        frame.dir1A0[2] = frame.ctr1F0[2] - frame.out10C[2];
        len = func_003e40b0((RwV3d *)&frame.dir1A0[0], (const RwV3d *)&frame.dir1A0[0]);
        func_00195850(unit, (f32 *)&frame.save1C0[0]);
        frame.save1C0[1] = 0.0f + frame.save1C0[1] + 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        func_001bd780(&frame.quatFC[0], &frame.out10C[0], (f32 *)&frame.save1C0[0], D_0060A0E0);
        {
            f32 s2 = fGpffff813c * len;
            frame.dir1A0[0] = frame.dir1A0[0] * s2;
            frame.dir1A0[1] = frame.dir1A0[1] * s2;
            frame.dir1A0[2] = frame.dir1A0[2] * s2;
            frame.outF0[0] = frame.out10C[0] + frame.dir1A0[0];
            frame.outF0[1] = frame.out10C[1] + frame.dir1A0[1];
            frame.outF0[2] = frame.out10C[2] + frame.dir1A0[2];
        }
        if (frame.outF0[1] < 25.0f) {
            frame.outF0[1] = 25.0f;
        }
        if (frame.out10C[1] < 25.0f) {
            frame.out10C[1] = 25.0f;
        }
        scale = 2.25f;
    }
    if (arg2 == 0) {
        frame.outF0[0] = frame.out10C[0];
        frame.outF0[1] = frame.out10C[1];
        frame.outF0[2] = frame.out10C[2];
        frame.quatFC[0] = frame.copy118[0];
        frame.quatFC[1] = frame.copy118[1];
        frame.quatFC[2] = frame.copy118[2];
        frame.quatFC[3] = frame.copy118[3];
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), unit + 4, (u8 *)&frame.outF0[0], 50.0f, 3);
    func_001bac20((u16 *)arg0, frame.outF0, frame.out10C, 1);
    func_001bbef0(arg0, scale);
    if (arg1 != 0) {
        func_004b3110(8);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c21d0);
#endif
/* cold 001c2ee0 (2026-09-18): faithful direction only - production stays INCLUDE_ASM. */
/* counts: retail 1012 header (1009 fnalign) vs 793 faithful (762 v1 +31); band 982-1042 -> OUTSIDE (189 short of floor). Faithful = 3 duplicated scalings + t13 recompute (no pragmas) via /tmp/base_3dup.c: `fnalign --candidate /tmp/base_3dup.c --quiet` 793 instrs, 654 edits (+13 reloc) vs v1 651; `probe_variants --candidate base=/tmp/base_3dup.c` 904 vs v1 897. jal 49/49 both sides (tanf x9, grep/objdump), 5 switch arms present (0x4E/0x38/0x35/0x34/default). Side-by-side both tanf deletes (fnalign retail[640:649] + retail[729:738], 9 each): retail recomputes 0.5*B8 per use (mul $f1,$f1,$f0), GP per-use load (lwc1 -0x7EF0), mul GP*(0.5*B8), jal tanf, post-scale mul + lui 0x3E60/mtc1/nop; candidate caches t13=GP*B8*0.5 once for 4 tanfs and merges scalings into one path (retail 19 vs object 4 at 222:258; 38 vs 15 at 400:438). Same merge repeats all three scalings (first 2-elem t8, second 3-elem t12, third 3-elem aux t12) per 7k do-not-hoist-what-retail-recomputes. Remaining 1009-793=216 diffuse recompute-vs-cache of the same kind. */
/* rejected: pragma inflation into band measured +185 and refused as gate-defeating per Main (gate proves shape, not volume; real wins 10-60 words per 7s). `opt_common_subs off` 811 (+49), `commons+dead` 832 (+70), triple `commons+dead+peephole` 947 (+185); triple+3dup 982 (890 edits/probe 929) and +prop 984 (892/probe 926) via /tmp/cand_982.c + /tmp/cand_984.c -- DO NOT INSTALL. Re-assoc of 4 tanf args closed (v9_7p 758 instrs, probe 901 vs 897). Method: M2C/romwright de-noise as before with block externs func_0044b868/func_003e41e0; faithful diff held in /tmp/base_3dup.c. */
/* measured 001c2ee0: fnalign retail 1009 vs object 990 instrs (-1.9%, 19 short, gate 979-1039), 269 edits (+30 reloc-only); composition max pure hole 4 max pure lump 2 - CLEAN, no hole-against-lump. 463:466 tanf hole closed (fresh tanf for t11/t10 divisor; base carried a stale divisor). Explicit frame struct at retail offsets (sideC0..fTop1DC with retail pads at 15C/16C/17C/18C/19C/1AC/1BC/1CC); 0.0f-seeded adda/madd shapes; (f32)0x113 int-convert for 275.0; per-use tanf recompute as fGpffff8110*(0.5f*B8); E0 reloaded per use (frees s-reg, drops v0 spill, struct at sp+0xC0 for a 0x1E0 frame); ld/sd copy_pairs; all-three dir1D0 scaling with hoisted neg; save160 (not save150) for ctr1B0 adds. */
/* gate: object 990 against retail 1009, -1.9% - INSIDE the +-3% band (979-1039). */
/* measured 001c2ee0 (owner, 2026-09-19): fnalign edits **269 -> 208** by writing the
   `if (mode == c) ... else if` chain as a `switch (mode)` with the cases ascending and the
   trailing `else` as `default`.  Swept with a brace-aware converter over the 26
   highest-edit first-party floors that carry a chain; seven improved, six got worse and
   the rest have no convertible chain, so this is measured per function. */
// FUN_001C2EE0 NONMATCHING
#ifdef NON_MATCHING
void func_001c2ee0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 func_001bc330(u8 *arg0);
    extern s32 func_001bc240(u8 *arg0);
    extern s32 func_001bc630(u8 *arg0);
    extern s32 func_001bc1b0(u8 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);
    extern void func_001bbf40(u8 *arg0, f32 arg1);
    extern f32 fGpffff80cc;
    extern f32 fGpffff80e8;
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8130;
    extern f32 fGpffff8138;
    extern f32 fGpffff8144;
    extern f32 fGpffff8148;
    extern f32 fGpffff814c;
    extern s32 func_00196040(u32 groupFlags, u32 excludedFlags, void *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern RwV3d *func_003dcb40(RwV3d *arg0, const RwV3d *arg1, s32 arg2, const RtQuat *arg3);
    extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
    extern s32 func_004bd050(s32 arg0);
    extern void func_0019de70(BtlUnitStateWork *work, u16 value);
    extern void func_001bcd40(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, u16 arg4);
    extern void func_001bc3a0(f32 *arg0, f32 *arg1);
    extern void func_001bac20(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
    extern void func_001bbef0(u8 *arg0, f32 arg1);
    extern void func_004b3110(s32 arg0);
    struct {
        f32 sideC0[2];
        f32 horizC8[2];
        u8 matD0[0x40];
        f32 out110[3];
        f32 quat11C[4];
        f32 out12C[3];
        f32 quat138[4];
        f32 norm148[2];
        f32 save150[3];
        u8 pad15C[4];
        f32 save160[3];
        u8 pad16C[4];
        f32 pair170[2];
        f32 save178;
        u8 pad17C[4];
        f32 focus180[3];
        u8 pad18C[4];
        f32 ctr190[3];
        u8 pad19C[4];
        f32 ctr1A0[3];
        u8 pad1AC[4];
        f32 ctr1B0[3];
        u8 pad1BC[4];
        f32 dir1C0[3];
        u8 pad1CC[4];
        f32 dir1D0[3];
        f32 fTop1DC;
    } frame;
    u8 *actor;
    u8 *target;
    u8 *aux;
    s32 alt;
    s32 bc240;
    s32 bc630;
    s32 isBbf;
    u16 mode;
    f32 t7;
    f32 t8;
    f32 t9;
    f32 t10;
    f32 t11;
    f32 t12;

    actor = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    target = *(u8 **)(actor + 0xA0C);
    alt = (func_001bc330(arg0) != 0);
    isBbf = 0;
    func_00195850(actor, frame.ctr1B0);
    func_00195850(target, frame.ctr190);
    t12 = 0.0f + frame.ctr1B0[1] + 0.5f * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
    t10 = 0.0f + frame.ctr190[1] + 0.5f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if ((t12 < t10) && (alt == 0)) {
        frame.ctr1B0[1] = (t12 + t10) * 0.25f;
        t12 = t10;
    }
    t11 = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    t10 = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
    if ((t10 < t11) && (alt == 0)) {
        t10 = t11;
    }
    if (t12 < (f32)0x113) {
        frame.ctr1B0[1] = fGpffff8144;
        t12 = (f32)0x113;
    }
    t7 = func_00196040(2, 0, frame.ctr1A0, &frame.fTop1DC, NULL, 1);
    func_003dcb40((RwV3d *)&frame.dir1D0[0], (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
    frame.ctr1A0[1] = frame.fTop1DC * 0.5f;
    frame.dir1C0[0] = frame.ctr1B0[0] - frame.ctr1A0[0];
    frame.dir1C0[1] = frame.ctr1B0[1] - frame.ctr1A0[1];
    frame.dir1C0[2] = frame.ctr1B0[2] - frame.ctr1A0[2];
    t11 = func_003e40b0((RwV3d *)&frame.dir1C0[0], (const RwV3d *)&frame.dir1C0[0]);
    t11 = fGpffff8128 * t11;
    frame.focus180[0] = frame.dir1C0[0] * t11;
    frame.focus180[1] = frame.dir1C0[1] * t11;
    frame.focus180[2] = frame.dir1C0[2] * t11;
    frame.focus180[0] = frame.focus180[0] + frame.ctr1A0[0];
    frame.focus180[1] = frame.focus180[1] + frame.ctr1A0[1];
    frame.focus180[2] = frame.focus180[2] + frame.ctr1A0[2];
    func_001c_copy_pair((s64 *)&frame.pair170[0], &frame.save178, (s64 *)&frame.focus180[0], &frame.focus180[2]);
    frame.horizC8[0] = *(f32 *)(arg0 + 0x9C) - frame.focus180[0];
    frame.horizC8[1] = *(f32 *)(arg0 + 0xA4) - frame.focus180[2];
    func_003e41e0(frame.horizC8, frame.horizC8);
    frame.sideC0[0] = frame.dir1C0[2];
    frame.sideC0[1] = -frame.dir1C0[0];
    t11 = frame.sideC0[1] * frame.horizC8[1] + frame.sideC0[0] * frame.horizC8[0];
    bc240 = func_001bc240(arg0);
    bc630 = func_001bc630(arg0);
    if ((alt != 0) || ((*(u16 *)(iGpffffb3e0 + (*(u16 *)(target + 0xA4) * 10 + *(u16 *)(target + 0xA4)) * 8) & 0x20) == 0)) {
        alt = (func_004bd050(0) & 1) != 0;
    } else {
        alt = 0;
    }
    if ((bc240 != 0) || ((alt != 0) && (func_001bc1b0(arg0) != 0) && (bc630 == 0))) {
        func_0019de70((BtlUnitStateWork *)target, 1);
        *(u8 **)(arg0 + 0x12C) = target;
        *(u16 *)(arg0 + 0x130) = 0;
        if (0.0f <= t11) {
            frame.dir1D0[0] = frame.dir1D0[0] * t10;
            frame.dir1D0[1] = frame.dir1D0[1] * t10;
            frame.dir1D0[2] = frame.dir1D0[2] * t10;
        } else {
            f32 nt = -t10;
            frame.dir1D0[0] = frame.dir1D0[0] * nt;
            frame.dir1D0[1] = frame.dir1D0[1] * nt;
            frame.dir1D0[2] = frame.dir1D0[2] * nt;
        }
        frame.save160[0] = frame.ctr1B0[0] + frame.dir1D0[0];
        frame.save160[1] = frame.ctr1B0[1] + frame.dir1D0[1];
        frame.save160[2] = frame.ctr1B0[2] + frame.dir1D0[2];
        t12 = fGpffff80cc * t12;
        frame.dir1D0[0] = frame.save160[0] - frame.focus180[0];
        frame.dir1D0[1] = t12 - frame.focus180[1];
        frame.dir1D0[2] = frame.save160[2] - frame.focus180[2];
        frame.save160[1] = t12;
        t10 = t10 / t9;
        t9 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        if (t10 <= t12 / t9) {
            t10 = t12 / t9;
        }
        t8 = t8 + t10;
        t12 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        if (t8 <= t7 / t12) {
            t8 = t7 / t12;
        }
        t12 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        t12 = t8 * t12 * 0.21875f;
        frame.norm148[0] = frame.dir1D0[0];
        frame.norm148[1] = frame.dir1D0[2];
        func_003e41e0(frame.norm148, frame.norm148);
        frame.focus180[0] = 0.0f + frame.focus180[0] + frame.norm148[1] * t12;
        frame.focus180[2] = (0.0f + frame.focus180[2]) - frame.norm148[0] * t12;
        frame.out12C[0] = frame.focus180[0] + frame.dir1D0[0] * t8;
        frame.out12C[1] = frame.focus180[1] + frame.dir1D0[1] * t8;
        frame.out12C[2] = frame.focus180[2] + frame.dir1D0[2] * t8;
        func_001bd780(&frame.quat138[0], &frame.out12C[0], &frame.focus180[0], D_0060A0E0);
        func_00195850(actor, frame.ctr1B0);
        frame.ctr1B0[1] = 0.0f + frame.ctr1B0[1] + fGpffff8118 * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
        t12 = 2.5f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        func_003dcb40((RwV3d *)&frame.dir1D0[0], (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
        if (0.0f <= t11) {
            frame.dir1D0[0] = frame.dir1D0[0] * -t12;
            frame.dir1D0[1] = frame.dir1D0[1] * -t12;
            frame.dir1D0[2] = frame.dir1D0[2] * -t12;
        } else {
            frame.dir1D0[0] = frame.dir1D0[0] * t12;
            frame.dir1D0[1] = frame.dir1D0[1] * t12;
            frame.dir1D0[2] = frame.dir1D0[2] * t12;
        }
        frame.save150[0] = frame.ctr1B0[0] + frame.dir1D0[0];
        frame.save150[1] = frame.ctr1B0[1] + frame.dir1D0[1];
        frame.save150[2] = frame.ctr1B0[2] + frame.dir1D0[2];
        func_001bd780(&frame.quat11C[0], &frame.save150[0], (f32 *)&frame.pair170[0], D_0060A0E0);
        t11 = 4.0f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        frame.dir1D0[0] = frame.save150[0] - frame.pair170[0];
        frame.dir1D0[1] = frame.save150[1] - frame.pair170[1];
        frame.dir1D0[2] = frame.save150[2] - frame.save178;
        t12 = func_003e40b0((RwV3d *)&frame.dir1D0[0], (const RwV3d *)&frame.dir1D0[0]);
        t10 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        t12 = t12 + t11 / t10;
        func_003dcb40((RwV3d *)&frame.dir1D0[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quat11C[0]);
        t10 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        t10 = t12 * t10 * 0.21875f;
        frame.norm148[0] = frame.dir1D0[0];
        frame.norm148[1] = frame.dir1D0[2];
        func_003e41e0(frame.norm148, frame.norm148);
        frame.out110[0] = 0.0f + frame.pair170[0] + frame.norm148[1] * t10;
        frame.pair170[0] = frame.out110[0];
        frame.focus180[2] = (0.0f + frame.focus180[2]) - frame.norm148[0] * t10;
        frame.dir1D0[0] = frame.dir1D0[0] * t12;
        frame.dir1D0[1] = frame.dir1D0[1] * t12;
        frame.dir1D0[2] = frame.dir1D0[2] * t12;
        frame.out110[0] = frame.out110[0] + frame.dir1D0[0];
        frame.out110[1] = frame.pair170[1] + frame.dir1D0[1];
        frame.out110[2] = frame.focus180[2] + frame.dir1D0[2];
        t12 = fGpffff8148;
    } else {
        func_0019de70((BtlUnitStateWork *)target, 0);
        *(u8 **)(arg0 + 0x12C) = target;
        *(u16 *)(arg0 + 0x130) = 1;
        func_001c_copy_pair((s64 *)&frame.save160[0], &frame.save160[2], (s64 *)&frame.ctr1A0[0], &frame.ctr1A0[2]);
        frame.save160[1] = fGpffff814c * frame.fTop1DC;
        if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A) == 1) {
            aux = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x38) + 0x30);
            if (0.0f <= t11) {
                t12 = *(f32 *)(aux + 0x90) * *(f32 *)(aux + 0x2C);
                frame.dir1D0[0] = frame.dir1D0[0] * t12;
                frame.dir1D0[1] = frame.dir1D0[1] * t12;
                frame.dir1D0[2] = frame.dir1D0[2] * t12;
            } else {
                t12 = -(*(f32 *)(aux + 0x90) * *(f32 *)(aux + 0x2C));
                frame.dir1D0[0] = frame.dir1D0[0] * t12;
                frame.dir1D0[1] = frame.dir1D0[1] * t12;
                frame.dir1D0[2] = frame.dir1D0[2] * t12;
            }
            frame.save160[0] = frame.save160[0] + frame.dir1D0[0];
            frame.save160[1] = frame.save160[1] + frame.dir1D0[1];
            frame.save160[2] = frame.save160[2] + frame.dir1D0[2];
        }
        if (frame.save160[1] < 125.0f) {
            frame.save160[1] = 125.0f;
        }
        frame.dir1D0[0] = frame.save160[0] - frame.focus180[0];
        frame.dir1D0[1] = frame.save160[1] - frame.focus180[1];
        frame.dir1D0[2] = frame.save160[2] - frame.focus180[2];
        t10 = func_003e40b0((RwV3d *)&frame.dir1D0[0], (const RwV3d *)&frame.dir1D0[0]);
        t12 = 300.0f;
        if (300.0f <= t7) {
            t12 = t7;
        }
        t7 = func_0044b868(*(f32 *)(arg0 + 0xB8) * 0.5f);
        t10 = t10 + t12 / t7;
        t12 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        t12 = t10 * t12 * 0.21875f * 0.5f;
        frame.norm148[0] = frame.dir1D0[0];
        frame.norm148[1] = frame.dir1D0[2];
        func_003e41e0(frame.norm148, frame.norm148);
        frame.focus180[0] = 0.0f + frame.focus180[0] + frame.norm148[1] * t12;
        frame.focus180[2] = (0.0f + frame.focus180[2]) - frame.norm148[0] * t12;
        frame.out12C[0] = frame.focus180[0] + frame.dir1D0[0] * t10;
        frame.out12C[1] = frame.focus180[1] + frame.dir1D0[1] * t10;
        frame.out12C[2] = frame.focus180[2] + frame.dir1D0[2] * t10;
        func_001bd780(&frame.quat138[0], &frame.out12C[0], &frame.focus180[0], D_0060A0E0);
        if (bc630 == 0) {
            if (0.0f <= t11) {
                func_003e0870((RwMatrix *)frame.matD0, (const RwV3d *)D_0060A0E0, -27.5f, 0);
            } else {
                func_003e0870((RwMatrix *)frame.matD0, (const RwV3d *)D_0060A0E0, 27.5f, 0);
            }
            func_003e4320((RwV3d *)&frame.dir1C0[0], (const RwV3d *)&frame.dir1D0[0], (const RwMatrix *)frame.matD0);
            t10 = t10 * fGpffff80e8;
            t12 = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
            t12 = t10 * t12 * 0.21875f * 0.5f;
            frame.norm148[0] = frame.dir1C0[0];
            frame.norm148[1] = frame.dir1C0[2];
            func_003e41e0(frame.norm148, frame.norm148);
            frame.focus180[0] = 0.0f + frame.focus180[0] + frame.norm148[1] * t12;
            frame.focus180[2] = (0.0f + frame.focus180[2]) - frame.norm148[0] * t12;
            frame.out110[0] = frame.focus180[0] + frame.dir1C0[0] * t10;
            frame.out110[2] = frame.focus180[2] + frame.dir1C0[2] * t10;
            frame.out110[1] = fGpffff80cc * frame.fTop1DC;
            frame.dir1C0[0] = frame.ctr1B0[0] - frame.ctr1A0[0];
            frame.dir1C0[1] = frame.ctr1B0[1] - frame.ctr1A0[1];
            frame.dir1C0[2] = frame.ctr1B0[2] - frame.ctr1A0[2];
            t12 = func_003e40b0((RwV3d *)&frame.dir1C0[0], (const RwV3d *)&frame.dir1C0[0]);
            t12 = t12 * 0.25f;
            frame.focus180[0] = frame.dir1C0[0] * t12;
            frame.focus180[1] = frame.dir1C0[1] * t12;
            frame.focus180[2] = frame.dir1C0[2] * t12;
            frame.focus180[0] = frame.focus180[0] + frame.ctr1A0[0];
            frame.focus180[1] = frame.focus180[1] + frame.ctr1A0[1];
            frame.focus180[2] = frame.focus180[2] + frame.ctr1A0[2];
            func_001bd780(&frame.quat11C[0], &frame.out110[0], &frame.focus180[0], D_0060A0E0);
            t12 = 3.75f;
        } else {
            mode = *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6E);
            switch (mode) {
            case 52:
                frame.focus180[1] = 500.0f;
                frame.out110[1] = 200.0f;
                t12 = 1.25f;
                isBbf = 1;
                *(s32 *)(arg0 + 0xDC) = 0xC;
                break;
            case 53:
                frame.focus180[1] = 600.0f;
                frame.out110[1] = 200.0f;
                isBbf = 0;
                *(s32 *)(arg0 + 0xDC) = 8;
                t12 = fGpffff8130;
                break;
            case 56:
                frame.focus180[1] = 800.0f;
                frame.out110[1] = 500.0f;
                t12 = 2.0f;
                isBbf = 1;
                *(s32 *)(arg0 + 0xDC) = 0xC;
                break;
            case 78:
                frame.focus180[1] = 1000.0f;
                frame.out110[1] = 500.0f;
                t12 = 1.5f;
                isBbf = 0;
                *(s32 *)(arg0 + 0xDC) = 4;
                break;
            default:
                frame.focus180[1] = 500.0f;
                frame.out110[1] = 200.0f;
                isBbf = 1;
                *(s32 *)(arg0 + 0xDC) = 0;
                t12 = fGpffff8138;
                break;
            }
            arg1 = 0;
            frame.out110[0] = frame.out12C[0];
            frame.out110[2] = frame.out12C[2];
            func_001bd780(&frame.quat11C[0], &frame.out110[0], &frame.focus180[0], D_0060A0E0);
        }
    }
    if ((arg2 == 0) && (bc630 == 0)) {
        frame.quat11C[0] = frame.quat138[0];
        frame.quat11C[1] = frame.quat138[1];
        frame.quat11C[2] = frame.quat138[2];
        frame.quat11C[3] = frame.quat138[3];
        func_003dcb40((RwV3d *)&frame.dir1D0[0], (const RwV3d *)D_0060A0F0, 1, (const RtQuat *)&frame.quat11C[0]);
        frame.dir1D0[0] = frame.dir1D0[0] * 100.0f;
        frame.dir1D0[1] = frame.dir1D0[1] * 100.0f;
        frame.dir1D0[2] = frame.dir1D0[2] * 100.0f;
        frame.out110[0] = frame.out12C[0] + frame.dir1D0[0];
        frame.out110[1] = frame.out12C[1] + frame.dir1D0[1];
        frame.out110[2] = frame.out12C[2] + frame.dir1D0[2];
    }
    if (*(s32 *)(arg0 + 0xDC) > 0) {
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
    }
    func_001bc3a0(&frame.out110[0], &frame.out110[0]);
    func_001bc3a0(&frame.out12C[0], &frame.out12C[0]);
    func_001bac20((u16 *)arg0, &frame.out110[0], &frame.out12C[0], 1);
    if (isBbf != 0) {
        func_001bbf40(arg0, t12);
    } else {
        func_001bbef0(arg0, t12);
    }
    if (arg1 != 0) {
        func_004b3110(8);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c2ee0);
#endif
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
/* measured 001c3f70: retail 1126 instrs (4512B window, 1128 with zero tail) vs object 1126 instrs (0.0%) inside 1094-1162 band; guarded 1059 words via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c3f70` (GUARDED_SCORE 1059); fnalign 484 edits +23 reloc-only via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c3f70 --candidate /tmp/installed_3f70.c --quiet` (was 741 +8 at 1051/1125). Truthful fixes: work 0x70->0xE0, height products recomputed per use via work chain (hA/hC/hD via work+0x30, hB via work+0x38 chain; freed 3 float regs, closed +4 8C-loads signature, struct 0xB0->0xA0, frame 0x1B0->0x1A0). Frame matches (0x1A0); all 37 jals present. Prior cold pass 1051/1125 noted retail pads at 17C/18C, second 1bd780/3dcb40/ec3d0 sequence, E/B block (8118-focus, inverted order, duplicated 0.25-madds). Best legal plain-C; banked as floor. */
/* 114 finding: sp+0x114 is func_001ec3d0's second output word, never explicitly stored, read back as lwc1 0x114 -> swc1 0x138 three times. A callee output that is only ever observed through the frame is exactly the kind of thing that makes a body look correct while producing a hole. */
// FUN_001C3F70 NONMATCHING
#ifdef NON_MATCHING
void func_001c3f70(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 func_001bc240(u8 *arg0);
    extern s32 func_001bc1b0(u8 *arg0);
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_003dcb40(void *arg0, const void *arg1, s32 arg2, const void *arg3);
    extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
    extern f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 func_0044b868(f32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern void func_0019de70(BtlUnitStateWork *work, u16 value);
    extern void func_001bcd40(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, u16 arg4);
    extern void func_001bac20(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
    extern void func_001bbef0(u8 *arg0, f32 arg1);
    extern void func_004b3110(s32 arg0);
    extern f32 fGpffff8030;
    extern f32 fGpffff803c;
    extern f32 fGpffff80f0;
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;
    extern f32 fGpffff8150;
    extern f32 fGpffff8154;
    struct {
        f32 outA0[3];
        f32 quatAC[4];
        f32 copyBC[3];
        f32 quatC8[4];
        u8 padD8[8];
        f32 sideE0[2];
        f32 horizE8[2];
        f32 inF0[4];
        u8 pad100[8];
        f32 norm108[2];
        f32 ecOut110[2];
        f32 copy118[2];
        f32 pair120[2];
        f32 save128;
        u8 pad12C[4];
        f32 tgt130[3];
        u8 pad13C[4];
        f32 dir140[3];
        u8 pad14C[4];
        f32 focus150[3];
        u8 pad15C[4];
        f32 save160[3];
        u8 pad16C[4];
        f32 ctr170[3];
        u8 pad17C[4];
        f32 ctr180[3];
        u8 pad18C[4];
        f32 ctr190[3];
        u8 pad19C[4];
    } frame;
    u8 *work;
    u8 *unitA;
    u8 *unitB;
    u8 *res;
    s32 branch;
    f32 hE;
    f32 dot;
    f32 len;
    f32 norm;
    f32 ecRet;
    f32 sc;

    work = *(u8 **)(arg0 + 0xE0);
    unitA = *(u8 **)(work + 0x30);
    unitB = *(u8 **)(*(u8 **)(work + 0x38) + 0x30);
    res = *(u8 **)(unitA + 0xA0C);
    func_00195850(unitA, frame.ctr190);
    func_00195850(unitB, frame.ctr180);
    func_00195850(res, frame.ctr170);
    hE = 0.0f + frame.ctr170[1] + 0.5f * (*(f32 *)(res + 0x8C) * *(f32 *)(res + 0x2C));
    *(f32 *)(arg0 + 0x104) = frame.ctr180[0];
    *(f32 *)(arg0 + 0x108) = frame.ctr180[1];
    *(f32 *)(arg0 + 0x10C) = frame.ctr180[2];
    *(u8 **)(arg0 + 0x100) = *(u8 **)(work + 0x38);
    if (hE < 135.0f) {
        hE = 135.0f;
        frame.ctr170[1] = 67.5f;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        branch = 1;
    } else {
        branch = func_001bc240(arg0);
        if ((hE - (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C)))) < 125.0f) {
            branch = (branch != 0);
            if (branch == 0) {
                branch = (func_004bd050(0) & 1) != 0;
                if (branch != 0) {
                    branch = (func_001bc1b0(arg0) != 0);
                }
            }
        } else {
            branch = 0;
        }
    }
    if (branch != 0) {
        frame.dir140[0] = frame.ctr170[0] - frame.ctr180[0];
        frame.dir140[1] = frame.ctr170[1] - frame.ctr180[1];
        frame.dir140[2] = frame.ctr170[2] - frame.ctr180[2];
        len = func_003e40b0((RwV3d *)&frame.dir140[0], (const RwV3d *)&frame.dir140[0]);
        norm = len;
        {
            f32 s1 = fGpffff8128 * len;
            frame.focus150[0] = frame.dir140[0] * s1;
            frame.focus150[1] = frame.dir140[1] * s1;
            frame.focus150[2] = frame.dir140[2] * s1;
        }
    } else {
        f32 t3;
        f32 t2;
        f32 t1;
        t3 = frame.ctr170[0] + frame.ctr190[0];
        frame.save160[0] = t3;
        t2 = frame.ctr170[1] + frame.ctr190[1];
        frame.save160[1] = t2;
        t1 = frame.ctr170[2] + frame.ctr190[2];
        frame.save160[2] = t1;
        t3 = t3 * 0.5f;
        frame.save160[0] = t3;
        t2 = t2 * 0.5f;
        frame.save160[1] = t2;
        t1 = t1 * 0.5f;
        frame.save160[2] = t1;
        frame.dir140[0] = t3 - frame.ctr180[0];
        frame.dir140[1] = t2 - frame.ctr180[1];
        frame.dir140[2] = t1 - frame.ctr180[2];
        len = func_003e40b0((RwV3d *)&frame.dir140[0], (const RwV3d *)&frame.dir140[0]);
        norm = len;
        {
            f32 s1 = fGpffff8128 * len;
            frame.focus150[0] = frame.dir140[0] * s1;
            frame.focus150[1] = frame.dir140[1] * s1;
            frame.focus150[2] = frame.dir140[2] * s1;
        }
    }
    frame.focus150[0] = frame.focus150[0] + frame.ctr180[0];
    frame.focus150[1] = frame.focus150[1] + frame.ctr180[1];
    frame.focus150[2] = frame.focus150[2] + frame.ctr180[2];
    frame.horizE8[0] = *(f32 *)(arg0 + 0x9C) - frame.focus150[0];
    frame.horizE8[1] = *(f32 *)(arg0 + 0xA4) - frame.focus150[2];
    func_003e41e0(frame.horizE8, frame.horizE8);
    if (branch != 0) {
        f32 side;
        f32 tprod;
        func_0019de70((BtlUnitStateWork *)res, 1);
        *(u8 **)(arg0 + 0x12C) = res;
        *(u16 *)(arg0 + 0x130) = 0;
        unitA = unitB;
        func_001c_copy_pair((s64 *)&frame.save160[0], &frame.save160[2], (s64 *)&frame.ctr170[0], &frame.ctr170[2]);
        frame.sideE0[0] = frame.dir140[2];
        frame.sideE0[1] = -frame.dir140[0];
        dot = frame.sideE0[1] * frame.horizE8[1] + frame.sideE0[0] * frame.horizE8[0];
        if (dot >= 0.0f) {
            frame.tgt130[0] = 0.0f + frame.save160[0] + frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = (0.0f + frame.save160[2]) - frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
        } else {
            frame.tgt130[0] = (0.0f + frame.save160[0]) - frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = 0.0f + frame.save160[2] + frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            {
                f32 rs = 0.5f * norm;
                frame.focus150[0] = frame.dir140[0] * rs;
                frame.focus150[1] = frame.dir140[1] * rs;
                frame.focus150[2] = frame.dir140[2] * rs;
                frame.focus150[0] = frame.focus150[0] + frame.ctr180[0];
                frame.focus150[1] = frame.focus150[1] + frame.ctr180[1];
                frame.focus150[2] = frame.focus150[2] + frame.ctr180[2];
            }
        }
        if (hE < (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C)))) {
            frame.focus150[1] = 0.0f + frame.save160[1] + fGpffff8030 * hE;
            if (hE <= frame.focus150[1]) {
                frame.tgt130[1] = 0.0f + frame.save160[1] + fGpffff8030 * hE;
            } else {
                frame.tgt130[1] = 0.0f + frame.save160[1] + fGpffff8030 * hE;
            }
        } else {
            frame.tgt130[1] = (0.0f + frame.save160[1]) - fGpffff80f0 * hE;
            frame.focus150[1] = (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C))) * 0.25f + frame.ctr170[1] + 0.0f;
        }
        func_001bd780(&frame.quatC8[0], &frame.tgt130[0], &frame.focus150[0], D_0060A0E0);
        func_003dcb40((RwV3d *)&frame.dir140[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quatC8[0]);
        frame.inF0[0] = frame.focus150[0];
        frame.inF0[1] = frame.focus150[2];
        frame.inF0[2] = frame.tgt130[0];
        frame.inF0[3] = frame.tgt130[2];
        frame.copy118[0] = frame.save160[0];
        frame.copy118[1] = frame.save160[2];
        ecRet = func_001ec3d0((u8 *)&frame.inF0[0], (u8 *)&frame.inF0[2], (u8 *)&frame.copy118[0], (u8 *)&frame.ecOut110[0]);
        sc = 0.0f + ecRet + (*(f32 *)(res + 0x90) * *(f32 *)(res + 0x2C)) * fGpffff8138;
        if (sc < (f32)0x113) {
            sc = (f32)0x113;
        }
        frame.tgt130[0] = frame.ecOut110[0];
        if (hE < (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C)))) {
            if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) && !(hE < 500.0f)) {
                frame.focus150[1] = 0.0f + frame.focus150[1] + fGpffff8030 * (*(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C));
                frame.tgt130[1] = 0.0f + frame.save160[1] + 0.25f * hE;
            } else {
                frame.focus150[1] = (0.0f + frame.focus150[1]) - fGpffff80f0 * (*(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C));
                frame.tgt130[1] = 0.0f + frame.save160[1] + 0.25f * hE;
            }
        } else {
            frame.focus150[1] = 0.0f + frame.focus150[1] + fGpffff8118 * (*(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C));
            if (hE <= frame.focus150[1]) {
                frame.tgt130[1] = frame.save160[1];
            } else {
                frame.tgt130[1] = 0.0f + frame.focus150[1] + fGpffff8030 * (*(f32 *)(res + 0x8C) * *(f32 *)(res + 0x2C));
            }
        }
        frame.tgt130[2] = frame.ecOut110[1];
        sc = sc / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        frame.dir140[0] = frame.dir140[0] * sc;
        frame.dir140[1] = frame.dir140[1] * sc;
        frame.dir140[2] = frame.dir140[2] * sc;
        if (dot < 0.0f) {
            sc = sc * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f * 1.25f;
            frame.norm108[0] = frame.dir140[0];
            frame.norm108[1] = frame.dir140[2];
            func_003e41e0(frame.norm108, frame.norm108);
            frame.tgt130[0] = 0.0f + frame.tgt130[0] + frame.norm108[1] * sc;
            frame.tgt130[2] = (0.0f + frame.tgt130[2]) - frame.norm108[0] * sc;
        }
        frame.copyBC[0] = frame.tgt130[0] + frame.dir140[0];
        frame.copyBC[1] = frame.tgt130[1] + frame.dir140[1];
        frame.copyBC[2] = frame.tgt130[2] + frame.dir140[2];
        if (frame.copyBC[1] < 25.0f) {
            frame.copyBC[1] = 25.0f;
        }
        frame.dir140[0] = frame.ctr190[0] - frame.ctr180[0];
        frame.dir140[1] = frame.ctr190[1] - frame.ctr180[1];
        frame.dir140[2] = frame.ctr190[2] - frame.ctr180[2];
        len = func_003e40b0((RwV3d *)&frame.dir140[0], (const RwV3d *)&frame.dir140[0]);
        {
            f32 s1 = fGpffff8128 * len;
            frame.focus150[0] = frame.dir140[0] * s1;
            frame.focus150[1] = frame.dir140[1] * s1;
            frame.focus150[2] = frame.dir140[2] * s1;
            frame.focus150[0] = frame.focus150[0] + frame.ctr180[0];
            frame.focus150[1] = frame.focus150[1] + frame.ctr180[1];
            frame.focus150[2] = frame.focus150[2] + frame.ctr180[2];
        }
        func_001c_copy_pair((s64 *)&frame.save160[0], &frame.save160[2], (s64 *)&frame.ctr190[0], &frame.ctr190[2]);
        frame.tgt130[1] = 0.0f + frame.save160[1] + (0.0f + frame.ctr190[1] + 0.5f * (*(f32 *)(*(u8 **)(work + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C))) * frame.dir140[2];
        if (dot >= 0.0f) {
            frame.tgt130[0] = 0.0f + frame.save160[0] + frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = (0.0f + frame.save160[2]) - frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
        } else {
            frame.tgt130[0] = (0.0f + frame.save160[0]) - frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = 0.0f + frame.save160[2] + frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
        }
        frame.focus150[1] = 0.0f + frame.save160[1] + (0.0f + frame.ctr190[1] + 0.5f * (*(f32 *)(*(u8 **)(work + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C))) * (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C)));
        func_001bd780(&frame.quatAC[0], &frame.tgt130[0], &frame.focus150[0], D_0060A0E0);
        func_003dcb40((RwV3d *)&frame.dir140[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quatAC[0]);
        frame.inF0[0] = frame.focus150[0];
        frame.inF0[1] = frame.focus150[2];
        frame.inF0[2] = frame.tgt130[0];
        frame.inF0[3] = frame.tgt130[2];
        frame.copy118[0] = frame.save160[0];
        frame.copy118[1] = frame.save160[2];
        ecRet = func_001ec3d0((u8 *)&frame.inF0[0], (u8 *)&frame.inF0[2], (u8 *)&frame.copy118[0], (u8 *)&frame.ecOut110[0]);
        sc = 0.0f + ecRet + (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C)) * 3.0f;
        frame.tgt130[0] = frame.ecOut110[0];
        frame.tgt130[1] = 0.0f + frame.save160[1] + 0.25f * hE;
        frame.tgt130[2] = frame.ecOut110[1];
        sc = sc / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        frame.dir140[0] = frame.dir140[0] * sc;
        frame.dir140[1] = frame.dir140[1] * sc;
        frame.dir140[2] = frame.dir140[2] * sc;
        if (dot < 0.0f) {
            sc = sc * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f * 1.25f;
            frame.norm108[0] = frame.dir140[0];
            frame.norm108[1] = frame.dir140[2];
            func_003e41e0(frame.norm108, frame.norm108);
            frame.tgt130[0] = 0.0f + frame.tgt130[0] + frame.norm108[1] * sc;
            frame.tgt130[2] = (0.0f + frame.tgt130[2]) - frame.norm108[0] * sc;
        }
        frame.outA0[0] = frame.tgt130[0] + frame.dir140[0];
        frame.outA0[1] = frame.tgt130[1] + frame.dir140[1];
        frame.outA0[2] = frame.tgt130[2] + frame.dir140[2];
        if (frame.outA0[1] < 25.0f) {
            frame.outA0[1] = 25.0f;
        }
        sc = 2.5f;
    } else {
        func_0019de70((BtlUnitStateWork *)res, 0);
        *(u8 **)(arg0 + 0x12C) = res;
        *(u16 *)(arg0 + 0x130) = 1;
        func_001c_copy_pair((s64 *)&frame.save160[0], &frame.save160[2], (s64 *)&frame.ctr180[0], &frame.ctr180[2]);
        if ((0.75f * (*(f32 *)(res + 0x90) * *(f32 *)(res + 0x2C))) <= (fGpffff8150 * (*(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C)))) {
        }
        if (frame.save160[1] < 125.0f) {
            frame.save160[1] = 125.0f;
        }
        frame.sideE0[0] = frame.dir140[2];
        frame.sideE0[1] = -frame.dir140[0];
        dot = frame.sideE0[1] * frame.horizE8[1] + frame.sideE0[0] * frame.horizE8[0];
        frame.tgt130[1] = frame.save160[1];
        if (dot >= 0.0f) {
            frame.tgt130[0] = 0.0f + frame.save160[0] + frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = (0.0f + frame.save160[2]) - frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            func_001c_copy_pair((s64 *)&frame.pair120[0], &frame.save128, (s64 *)&frame.dir140[0], &frame.dir140[2]);
        } else {
            frame.tgt130[0] = (0.0f + frame.save160[0]) - frame.dir140[2] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
            frame.tgt130[2] = 0.0f + frame.save160[2] + frame.dir140[0] * (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C));
        }
        if (hE < (0.0f + frame.ctr180[1] + 0.5f * (*(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x8C) * *(f32 *)(*(u8 **)(*(u8 **)(work + 0x38) + 0x30) + 0x2C)))) {
            frame.focus150[1] = 0.0f + frame.save160[1] + fGpffff8030 * hE;
        } else {
            frame.focus150[1] = 0.0f + frame.save160[1] + fGpffff8154 * hE;
        }
        func_001bd780(&frame.quatAC[0], &frame.tgt130[0], &frame.focus150[0], D_0060A0E0);
        func_003dcb40((RwV3d *)&frame.dir140[0], (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.quatAC[0]);
        frame.inF0[0] = frame.focus150[0];
        frame.inF0[1] = frame.focus150[2];
        frame.inF0[2] = frame.tgt130[0];
        frame.inF0[3] = frame.tgt130[2];
        frame.copy118[0] = frame.save160[0];
        frame.copy118[1] = frame.save160[2];
        ecRet = func_001ec3d0((u8 *)&frame.inF0[0], (u8 *)&frame.inF0[2], (u8 *)&frame.copy118[0], (u8 *)&frame.ecOut110[0]);
        frame.tgt130[0] = frame.ecOut110[0];
        frame.tgt130[1] = frame.save160[1];
        frame.tgt130[2] = frame.ecOut110[1];
        {
            f32 div = ecRet + (*(f32 *)(*(u8 **)(work + 0x30) + 0x90) * *(f32 *)(*(u8 **)(work + 0x30) + 0x2C)) * fGpffff8138;
            div = div / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
            if (div < (f32)0x226) {
                div = (f32)0x226;
            }
            frame.dir140[0] = frame.dir140[0] * div;
            frame.dir140[1] = frame.dir140[1] * div;
            frame.dir140[2] = frame.dir140[2] * div;
            sc = div;
        }
        if (dot >= 0.0f) {
            f32 t = sc * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8))) * 0.21875f * 2.0f;
            frame.norm108[0] = frame.pair120[0];
            frame.norm108[1] = frame.save128;
            func_003e41e0(frame.norm108, frame.norm108);
            frame.tgt130[0] = (0.0f + frame.tgt130[0]) - frame.save128 * t;
            frame.tgt130[2] = frame.norm108[0] * t + frame.tgt130[2] + 0.0f;
        }
        frame.outA0[0] = frame.tgt130[0] + frame.dir140[0];
        frame.outA0[1] = frame.tgt130[1] + frame.dir140[1];
        frame.outA0[2] = frame.tgt130[2] + frame.dir140[2];
        frame.quatC8[0] = frame.quatAC[0];
        frame.quatC8[1] = frame.quatAC[1];
        frame.quatC8[2] = frame.quatAC[2];
        frame.quatC8[3] = frame.quatAC[3];
        frame.copyBC[0] = frame.outA0[0];
        frame.copyBC[1] = frame.outA0[1];
        frame.copyBC[2] = frame.outA0[2];
        frame.dir140[0] = frame.ctr190[0] - frame.copyBC[0];
        frame.dir140[1] = frame.ctr190[1] - frame.copyBC[1];
        frame.dir140[2] = frame.ctr190[2] - frame.copyBC[2];
        len = func_003e40b0((RwV3d *)&frame.dir140[0], (const RwV3d *)&frame.dir140[0]);
        func_00195850(unitA, (f32 *)&frame.save160[0]);
        frame.save160[1] = 0.0f + frame.save160[1] + fGpffff8030 * (*(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C));
        func_001bd780(&frame.quatAC[0], &frame.copyBC[0], (f32 *)&frame.save160[0], D_0060A0E0);
        {
            f32 s1 = fGpffff8128 * len;
            frame.dir140[0] = frame.dir140[0] * s1;
            frame.dir140[1] = frame.dir140[1] * s1;
            frame.dir140[2] = frame.dir140[2] * s1;
            frame.outA0[0] = frame.copyBC[0] + frame.dir140[0];
            frame.outA0[1] = frame.copyBC[1] + frame.dir140[1];
            frame.outA0[2] = frame.copyBC[2] + frame.dir140[2];
        }
        if (frame.outA0[1] < 25.0f) {
            frame.outA0[1] = 25.0f;
        }
        if (frame.copyBC[1] < 25.0f) {
            frame.copyBC[1] = 25.0f;
        }
        sc = 2.25f;
    }
    if (arg2 == 0) {
        frame.outA0[0] = frame.copyBC[0];
        frame.outA0[1] = frame.copyBC[1];
        frame.outA0[2] = frame.copyBC[2];
        frame.quatAC[0] = frame.quatC8[0];
        frame.quatAC[1] = frame.quatC8[1];
        frame.quatAC[2] = frame.quatC8[2];
        frame.quatAC[3] = frame.quatC8[3];
    }
    func_001bcd40(work, unitA + 4, (u8 *)&frame.outA0[0], 50.0f, 3);
    func_001bac20((u16 *)arg0, frame.outA0, frame.copyBC, 1);
    func_001bbef0(arg0, sc);
    if (arg1 != 0) {
        func_004b3110(8);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c3f70);
#endif
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
/* measured 001c5500 (stacking): schedule-on alone 381, full triple (schedule on + no_branch_likely on + peephole off) 390, both worse than banked 416 exact - extends the pair-sweep null to the stacking method. Schedule fundamentally changes codegen here; the wall stands as allocation. Do not repeat. */
// FUN_001C5500 NONMATCHING
/* measured 001c5500: 78 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c5500`; fnalign retail 416 vs object 416, 15 edits (+8 reloc-only). Decisive lever: truthful `extern f32 func_0044b868(f32)` block decl (implicit int return emitted mtc1/cvt plus cascade) moved the same body from 249 to 78. Defect class: a missing float return type on an extern, invisible until you spot a stray `cvt.s.w` in your object that retail does not have — check every float-returning callee's declaration when one appears. */
/* Fresh independent-object layout (251w) beats explicit Frame pads (389w/392w); dot/cross decl swap fixes $f24 (251w to 249w); binary (u8*,s32) ties unary with no caller migration. Pragmas swept scoped on exact body: schedule on 387, commons off 457, loopinv on tie, prop off 306 — neutral/worse, none installed. Top remaining: mtc1 $zero $f5 vs $f6 extra live temp at dot compare, 1.5f ($f23) hoist before base copy, mul $f6 vs $f7, $f20/$f21 cycle (div/cvt region already fixed by 0044b868 prototype). */
/* measured 001c5500 2026-09-19: re-measured exact 416/416, 78 words, 24 edits (+10 reloc-only, 34 total) — no code change (before=after). Horiz assignment swap `[0]/[1]`→`[1]/[0]` tried: 416/416, 42 edits (worse +18), confirming retail loads [0] (sp+0xc8) before [1] (sp+0xcc) although [1] consumed first is allocation, not order. Remaining per fnalign: mtc1 $zero $f5 (retail 0x1c5640) vs $f6 + c.olt/bc1t shift, 1.5f $f23 hoist (lui/mtc1 at O[91:93] vs R 0x1c5678 + nop), mul $f6 vs $f7 (3 sites), mov/neg $f5 vs $f6 + lwc1 0xc8 vs 0xcc, $f20/$f21 cycle at 0x134/0x138/0xec/0x104/div (6 sites) + $f5/$f6 shift. Explicit Frame pads already ruled out (389/392 vs 251). */
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
/* measured 001c5b80: 515 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c5b80` (GUARDED_SCORE 515); probe 515 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c5b80 --candidate v16=/var/tmp/cold1c5b80/v16.c`; fnalign retail 629 vs object 626 instrs, 231 edits (+15 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c5b80 --candidate /var/tmp/cold1c5b80/v16.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c5b80 -o /var/tmp/cold1c5b80/m2c.c`; romwright raw via `python3 tools/romwright_decompile.py func_001c5b80 --raw -o /var/tmp/cold1c5b80/rw_raw.c` (m2c-shaped fails on CONCAT44 intrinsic); de-noised to file idiom reusing existing decls (func_001bd560, func_003e40b0, func_003e4180, func_001958f0, func_00196040, func_003e0870, func_003e4320, func_001bd780, func_001bc3a0, func_001bac20, func_001bbef0, func_004b3110, func_001eb440, func_004bd050, D_0060A0E0, iGpffffb3ac, fGpffff8110) plus block externs (func_001bc630(u8*), func_003e41e0(f32*,f32*), func_0044b868(f32)->f32, fGpffff8118/fGpffff8128). Frame 0x160 with pose50[7]+out6C[3]+quat78[4]+pad88+mat90+padD0+pairD8+valE0+padE4+pairE8[2]+pairF0+valF8+padFC+actor100[3]+pad10C+out110[3]+pad11C+dir120[3]+pad12C+tmp130[3]+pad13C+center140[3]+pad14C+center150[3]+top15C (0x110 locals). Round1 v1 535 (629 vs 629, 125+16) -> v2 535 tie (single-mask group + (f32)0x226/0x2EE for 550/750). Round2 v3 530 (reversed float decls, -5) vs v4 532 (branch >=2 first, -3). Round3 v5 518 (v3+branch+center-center zero, -12) vs v6 530 tie (u16 counter). Round4 v7 518 tie (switch descending 4E-first) vs v8 522 (50-first numerator, +4). Round5 v9 517 (for-loop, -1) vs v10 518 tie (1.25 reorder). Round6 v11/v12 517 ties (0.5/len and 8128/len swaps). Round7 v13 522 (len-first decls, +5) vs v14 516 (centerY/Z cache, -1). Round8 v15 516 tie (split side) vs v16 515 (double copy_pair, -1). Round9 v17/v18 515 ties (split on v16, p4_cacd0_mul). Round10 v19/v20 515 ties (plain +0 removal, inclusive compare). Two unproductive rounds, stopping. Top remaining: FPU color shift (retail $f23/$f21 vs object $f21/$f22), COP1 adda/madd at +0x3E8/+0x3EC and adda/madd+msub at +0x6AC..+0x6C4 per archive (plain C emits mul/add, source-unreachable floor), ld/sd vs lw/sw copy, branch $at vs $v0, switch dispatch. Pragma sweep singles+28 pairs: best ties 515 (loopinv/strength/unroll), none installed. Within 3% size gate (626/629=99.5%), banked as floor. */
/* measured 001c5b80 (owner, 2026-09-19): fnalign **231 -> 191 edits**, count
   626 -> 626 against retail 629, by putting one switch's arms in REVERSED
   order.  Case order is EMISSION order and the right one is whatever retail emitted:
   a chain converted to a switch wants ascending, a jump table wants the table's own
   layout, and a `beq` chain with no table can want the reverse of the source order.
   All three orderings were measured on every switch in this body and this is the
   only one that improved it; swept across the 167 first-party floors carrying a
   switch, just four responded at all. */
// FUN_001C5B80 NONMATCHING
#ifdef NON_MATCHING
void func_001c5b80(u8 *arg0, s32 arg1)
{
    struct Frame {
        f32 pose50[7];
        f32 out6C[3];
        f32 quat78[4];
        u8 pad88[8];
        u8 mat90[0x40];
        u8 padD0[8];
        s64 pairD8;
        f32 valE0;
        u8 padE4[4];
        f32 pairE8[2];
        s64 pairF0;
        f32 valF8;
        u8 padFC[4];
        f32 actor100[3];
        u8 pad10C[4];
        f32 out110[3];
        u8 pad11C[4];
        f32 dir120[3];
        u8 pad12C[4];
        f32 tmp130[3];
        u8 pad13C[4];
        f32 center140[3];
        u8 pad14C[4];
        f32 center150[3];
        f32 top15C;
    } frame;
    extern s32 func_001bc630(u8 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    f32 centerY;
    f32 centerZ;
    f32 cand;
    f32 tanRes;
    f32 scale;
    f32 len;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    s32 isZero;
    s32 group;
    s32 var_17;
    u8 *saved_arg0;
    u8 *work;
    u8 *entry;
    u8 *unit;
    (void)arg1;
    saved_arg0 = arg0;
    isZero = func_001bc630(saved_arg0);
    func_001bd560(frame.pose50, saved_arg0 + 0x9C);
    work = *(u8 **)(saved_arg0 + 0xE0);
    if (*(u16 *)(work + 0x6A) >= 2) {
        group = func_001eb440(work + 0x38);
    } else {
        group = 3;
    }
    group = group & 0xFFFF;
    var_f21 = func_00196040(group, 1, frame.center150, &frame.top15C, NULL, 0);
    frame.center150[1] = 0.75f * frame.top15C;
    var_f23 = var_f21 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
    if (var_f23 < 1000.0f) {
        var_f23 = 1000.0f;
    }
    func_00196040(group, 1, frame.center140, NULL, NULL, 1);
    var_f20 = 0.0f;
    for (var_17 = 0; (var_17 & 0xFFFF) < *(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6A); var_17 = (var_17 + 1) & 0xFFFF) {
        work = *(u8 **)(saved_arg0 + 0xE0);
        entry = *(u8 **)(work + ((var_17 & 0xFFFF) * 4) + 0x38);
        if ((*(u16 *)(entry + 0x1A) & 1) != 0) {
            func_001958f0(*(u8 **)(entry + 0x30), frame.actor100);
            frame.tmp130[0] = frame.center140[0] - frame.actor100[0];
            frame.tmp130[1] = frame.center140[1] - frame.actor100[1];
            frame.tmp130[2] = frame.center140[2] - frame.actor100[2];
            len = func_003e4180(frame.tmp130);
            if (!(len <= var_f20)) {
                func_001c_copy_pair(&frame.pairF0, &frame.valF8, (s64 *)frame.actor100, &frame.actor100[2]);
                var_f20 = len;
            }
        }
    }
    work = *(u8 **)(saved_arg0 + 0xE0);
    unit = *(u8 **)(work + 0x30);
    func_001958f0(unit, frame.actor100);
    frame.tmp130[0] = frame.center140[0] - frame.actor100[0];
    frame.tmp130[1] = frame.center140[1] - frame.actor100[1];
    frame.tmp130[2] = frame.center140[2] - frame.actor100[2];
    len = func_003e4180(frame.tmp130);
    if (!(len <= var_f20)) {
        func_001c_copy_pair(&frame.pairD8, &frame.valE0, (s64 *)frame.actor100, &frame.actor100[2]);
        func_001c_copy_pair(&frame.pairF0, &frame.valF8, &frame.pairD8, &frame.valE0);
        frame.dir120[0] = frame.actor100[0] - frame.center150[0];
        frame.dir120[1] = frame.actor100[1] - frame.center150[1];
        frame.dir120[2] = frame.actor100[2] - frame.center150[2];
        len = func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
        var_f20 = len;
        scale = fGpffff8128 * len;
        frame.actor100[0] = frame.dir120[0] * scale;
        frame.actor100[1] = frame.dir120[1] * scale;
        frame.actor100[2] = frame.dir120[2] * scale;
        centerY = frame.center150[1];
        centerZ = frame.center150[2];
        frame.center150[0] = frame.center150[0] + frame.actor100[0];
        frame.center150[1] = centerY + frame.actor100[1];
        frame.center150[2] = centerZ + frame.actor100[2];
        unit = *(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30);
        cand = len + (1.25f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C))) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        if (!(cand <= var_f23)) {
            var_f23 = cand;
        }
    } else if (var_f20 != 0.0f) {
        if (*(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6A) >= 2) {
            frame.dir120[0] = frame.actor100[0] - frame.center150[0];
            frame.dir120[1] = frame.actor100[1] - frame.center150[1];
            frame.dir120[2] = frame.actor100[2] - frame.center150[2];
            len = func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
            cand = (len + *(f32 *)(*(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30) + 0x90) * *(f32 *)(*(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30) + 0x2C) + 50.0f) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
            if (!(cand <= var_f23)) {
                var_f23 = cand;
            }
            frame.dir120[0] = frame.actor100[0] - *(f32 *)&frame.pairF0;
            frame.dir120[1] = frame.actor100[1] - *(f32 *)((u8 *)&frame.pairF0 + 4);
            frame.dir120[2] = frame.actor100[2] - frame.valF8;
            scale = 0.5f * func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
            frame.actor100[0] = frame.dir120[0] * scale;
            frame.actor100[1] = frame.dir120[1] * scale;
            frame.actor100[2] = frame.dir120[2] * scale;
            *(f32 *)&frame.pairF0 = *(f32 *)&frame.pairF0 + frame.actor100[0];
            *(f32 *)((u8 *)&frame.pairF0 + 4) = *(f32 *)((u8 *)&frame.pairF0 + 4) + frame.actor100[1];
            frame.valF8 = frame.valF8 + frame.actor100[2];
        }
    } else if (var_f20 == 0.0f) {
        func_001958f0(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30), (f32 *)&frame.pairF0);
    }
    *(f32 *)((u8 *)&frame.pairF0 + 4) = frame.center150[1];
    frame.tmp130[0] = *(f32 *)&frame.pairF0 - frame.center150[0];
    frame.tmp130[1] = frame.center150[1] - frame.center150[1];
    frame.tmp130[2] = frame.valF8 - frame.center150[2];
    func_003e40b0((RwV3d *)frame.tmp130, (const RwV3d *)frame.tmp130);
    frame.tmp130[0] = frame.tmp130[0] * var_f21;
    frame.tmp130[1] = frame.tmp130[1] * var_f21;
    frame.tmp130[2] = frame.tmp130[2] * var_f21;
    var_f22 = frame.center150[0] + frame.tmp130[0];
    var_f20 = frame.center150[2] + frame.tmp130[2];
    var_f21 = 1.25f * frame.top15C;
    frame.dir120[0] = var_f22 - frame.center150[0];
    frame.dir120[2] = var_f20 - frame.center150[2];
    frame.dir120[1] = 0.0f;
    scale = fGpffff8118 * func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
    frame.dir120[0] = frame.dir120[0] * scale;
    frame.dir120[1] = frame.dir120[1] * scale;
    frame.dir120[2] = frame.dir120[2] * scale;
    frame.out110[0] = frame.center150[0] + frame.dir120[0];
    frame.out110[1] = frame.center150[1] + frame.dir120[1];
    frame.out110[2] = frame.center150[2] + frame.dir120[2];
    frame.out110[1] = frame.center150[1];
    if (var_f21 < 250.0f) {
        var_f21 = 250.0f;
    }
    frame.tmp130[0] = var_f22 - frame.out110[0];
    frame.tmp130[1] = var_f21 - frame.out110[1];
    frame.tmp130[2] = var_f20 - frame.out110[2];
    func_003e40b0((RwV3d *)frame.tmp130, (const RwV3d *)frame.tmp130);
    tanRes = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
    scale = var_f23 * tanRes * 0.21875f;
    frame.pairE8[0] = frame.tmp130[0];
    frame.pairE8[1] = frame.tmp130[2];
    func_003e41e0(frame.pairE8, frame.pairE8);
    frame.out110[0] = frame.pairE8[1] * scale + frame.out110[0] + 0.0f;
    frame.out110[2] = (frame.out110[2] + 0.0f) - frame.pairE8[0] * scale;
    if (func_004bd050(0) & 1) {
        scale = 7.5f;
    } else {
        scale = -7.5f;
    }
    func_003e0870((RwMatrix *)frame.mat90, (const RwV3d *)D_0060A0E0, scale, 0);
    func_003e4320((RwV3d *)frame.dir120, (const RwV3d *)frame.tmp130, (const RwMatrix *)frame.mat90);
    frame.dir120[0] = frame.dir120[0] * var_f23;
    frame.dir120[1] = frame.dir120[1] * var_f23;
    frame.dir120[2] = frame.dir120[2] * var_f23;
    frame.out6C[0] = frame.out110[0] + frame.dir120[0];
    frame.out6C[1] = frame.out110[1] + frame.dir120[1];
    frame.out6C[2] = frame.out110[2] + frame.dir120[2];
    func_001bd780(frame.quat78, frame.out6C, frame.out110, D_0060A0E0);
    if (isZero == 0) {
        func_003e0870((RwMatrix *)frame.mat90, (const RwV3d *)D_0060A0E0, -scale, 0);
        func_003e4320((RwV3d *)frame.dir120, (const RwV3d *)frame.tmp130, (const RwMatrix *)frame.mat90);
        frame.dir120[0] = frame.dir120[0] * var_f23;
        frame.dir120[1] = frame.dir120[1] * var_f23;
        frame.dir120[2] = frame.dir120[2] * var_f23;
        frame.pose50[0] = frame.out110[0] + frame.dir120[0];
        frame.pose50[1] = frame.out110[1] + frame.dir120[1];
        frame.pose50[2] = frame.out110[2] + frame.dir120[2];
        func_001bd780(&frame.pose50[3], frame.pose50, frame.out110, D_0060A0E0);
        func_004b3110(8);
        scale = 8.0f;
    } else {
        frame.pose50[0] = frame.out6C[0];
        frame.pose50[1] = frame.out6C[1];
        frame.pose50[2] = frame.out6C[2];
        switch (*(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6E)) {
        case 52:
            frame.pose50[1] = 500.0f;
            frame.out110[1] = 450.0f;
            scale = 2.75f;
            break;
        case 53:
            frame.pose50[1] = 600.0f;
            frame.out110[1] = (f32)0x226;
            scale = 3.0f;
            break;
        case 56:
            frame.pose50[1] = 800.0f;
            frame.out110[1] = 700.0f;
            scale = 3.75f;
            break;
        case 78:
            frame.pose50[1] = 1000.0f;
            frame.out110[1] = (f32)0x2EE;
            scale = 2.5f;
            break;
        default:
            frame.pose50[1] = 500.0f;
            frame.out110[1] = 450.0f;
            scale = 2.75f;
            break;
        }
        func_001bd780(&frame.pose50[3], frame.pose50, frame.out110, D_0060A0E0);
        func_004b3110(8);
    }
    func_001bc3a0(frame.pose50, frame.pose50);
    func_001bc3a0(frame.out6C, frame.out6C);
    func_001bac20((u16 *)saved_arg0, frame.pose50, frame.out6C, 1);
    func_001bbef0(saved_arg0, scale);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5b80);
#endif
// FUN_001C79E0
void func_001c79e0(void) {}
/* MATCH.  The last two words were the order of two operand loads feeding one
   add: retail loads the position Y coordinate into $f1 before the direction Y
   coordinate into $f0, this body did the reverse.  Snapshotting the position
   Y into an ordinary float local immediately before the first Y output, and
   using it in both Y expressions, gives retail's order - retail reuses that
   value in the final height calculation, which is why it loads it first.
   The position of the snapshot is the whole trick: taken before the X output
   it scores 5, and before the position X update 20, which is why the earlier
   pass recorded "hoisting pos138[1] into a local (5)" and concluded the load
   pair was a scheduler coin-flip.  It was not.
   Also measured at 2 and byte-identical on the way here: `schedule off`,
   `opt_loop_invariants on`, `opt_unroll_loops off`, an explicit `tmpMul`
   temporary, a reassociated `dir128[1] * var_f20 + pos138[1]`, and fully
   parenthesised operands.  Worse: reordering the three `outC0[i]` assignments
   (17 and 8), splitting the add into `= pos; += dir * f` (40), `schedule on`
   (388), `peephole off` (402), `opt_propagation off` (397),
   `opt_common_subs off` (401). */
// FUN_001C79F0
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
    f32 positionY;
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
        positionY = frame.pos138[1];
        frame.outC0[1] = positionY + frame.dir128[1] * var_f20;
        frame.outC0[2] = frame.pos138[2] + frame.dir128[2] * var_f20;
        frame.outC0[1] = positionY + var_f24 * var_f22;
        func_001bd780((void *)frame.quatCC, (void *)frame.outC0, (void *)frame.pos138, (void *)D_0060A0E0);
        func_001bcd40(var17, (u8 *)0, (u8 *)0, 0.0f, 1);
        func_001bab00(saved_arg0, (void *)frame.outC0);
    }
}
/* measured 001c80f0: 329 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c80f0` (GUARDED_SCORE 329); probe 329 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c80f0 --candidate v1=/var/tmp/cold1c80f0/v1.c`; fnalign retail 502 vs object 494 instrs, 156 edits (+17 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c80f0 --candidate /var/tmp/cold1c80f0/v1.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c80f0 -o /var/tmp/cold1c80f0/m2c.c`; de-noised to file idiom reusing existing decls (func_001bd560, func_00195850, func_00196040, func_003dcb40, func_003e40b0, func_001bd780, func_0044b868, tanf, func_001958f0, func_001bcd40, func_001bab00, func_001bac20, func_001bbef0, D_0060A0D0/D_0060A0E0/D_0060A100, fGpffff8110/8100/811c). Frame 0x180. Within 3% size gate (494/502=98.4%), banked as floor; residual is FPU coloring, adda/madd scheduling, ld/sd copy, and poly chain. Round2 v2 block-scope+copy_pair 374 (+45), v3 copy_pair-only 374, v4 scope-only 329 tie; Round3 v5 p4_cacd0_mul tie (329, same 156+17 edits), v6 inclusive 50.0 compare 352 (+23). Two unproductive rounds, stopping. Top remaining: FPU color shift (retail $f23/$f21 vs object $f22/$f23, $f20/$f22 vs $f20/$f21), COP1 adda/madd+msub vs mul/add, ld/sd vs lw/sw copy, double 003e40b0 call, poly adda/madd chain. */
// FUN_001C80F0 NONMATCHING
#ifdef NON_MATCHING
void func_001c80f0(u8 *arg0, s32 arg1)
{
    struct Frame {
        f32 quat70[4];
        f32 slerp80[8];
        f32 angleA0;
        s32 modeA4;
        u8 padA8[8];
        f32 outB0[3];
        f32 quatBC[4];
        f32 copyCC[3];
        f32 quatD8[4];
        u8 padE8[8];
        f32 poseF0[7];
        f32 out10C[3];
        f32 interp118[4];
        u8 pad128[8];
        f32 center130[3];
        f32 pad13C;
        f32 actor140[3];
        f32 pad14C;
        f32 cand150[3];
        f32 pad15C;
        f32 diff160[3];
        f32 pad16C;
        f32 dir170[3];
        f32 top17C;
    } frame;
    extern f32 fGpffff8118;
    extern f32 fGpffff80bc;
    extern f32 fGpffff8120;
    extern f32 fGpffff8124;
    extern f32 fGpffff8104;
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff8108;
    extern f32 func_0044b868(f32 arg0);
    extern void func_001ec1c0(void *arg0, void *arg1, void *arg2);
    extern void func_003dcc70(void *arg0, void *arg1, void *arg2);
    extern void func_001bd5e0(f32 *arg0, f32 *arg1);
    f32 var_f24;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    f32 minReq;
    f32 scaleTmp;
    f32 polyA;
    f32 polyB;
    f32 sqA;
    f32 sqB;
    u8 *saved_arg0;
    s32 saved_flag;
    u8 *unit;
    u8 *next;
    u8 *unit2;

    saved_arg0 = arg0;
    saved_flag = arg1;
    unit = *(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30);
    next = func_001d8bc0(*(u8 **)(saved_arg0 + 0xE0) + 0x98);
    func_001bd560(frame.poseF0, saved_arg0 + 0x9C);
    func_00195850(unit, frame.actor140);
    var_f23 = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C) * 2.0f;
    frame.actor140[1] = frame.actor140[1] + fGpffff8118 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C)) + 0.0f;
    var_f20 = func_00196040(2, 0, frame.center130, &frame.top17C, NULL, 1);
    frame.top17C = frame.top17C * fGpffff8100;
    frame.center130[1] = frame.top17C;
    func_001ec1c0(frame.quat70, frame.actor140, frame.center130);
    func_003dcb40((RwV3d *)frame.dir170, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)frame.quat70);
    frame.dir170[0] = frame.dir170[0] * var_f23;
    frame.dir170[1] = frame.dir170[1] * var_f23;
    frame.dir170[2] = frame.dir170[2] * var_f23;
    frame.actor140[0] = frame.actor140[0] + frame.dir170[0];
    frame.actor140[1] = frame.actor140[1] + frame.dir170[1];
    frame.actor140[2] = frame.actor140[2] + frame.dir170[2];
    frame.diff160[0] = frame.actor140[0] - frame.center130[0];
    frame.diff160[1] = frame.actor140[1] - frame.center130[1];
    frame.diff160[2] = frame.actor140[2] - frame.center130[2];
    var_f22 = func_003e40b0((RwV3d *)frame.diff160, (const RwV3d *)frame.diff160);
    scaleTmp = fGpffff811c * var_f22;
    frame.cand150[0] = frame.diff160[0] * scaleTmp + frame.center130[0];
    frame.cand150[1] = frame.diff160[1] * scaleTmp + frame.center130[1];
    frame.cand150[2] = frame.diff160[2] * scaleTmp + frame.center130[2];
    frame.dir170[0] = frame.actor140[0];
    frame.dir170[1] = frame.actor140[1];
    frame.dir170[2] = frame.actor140[2];
    func_001bd780(frame.quatBC, frame.dir170, frame.cand150, D_0060A0E0);
    var_f21 = 0.5f * *(f32 *)(saved_arg0 + 0xB8);
    if (*(u16 *)(saved_arg0 + 0x106) == 0) {
        var_f24 = 0.75f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        var_f24 = var_f24 / tanf(var_f21);
        minReq = (0.75f * var_f20) / tanf(var_f21);
    } else {
        var_f24 = fGpffff811c * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        var_f24 = var_f24 / tanf(var_f21);
        minReq = (fGpffff811c * var_f20) / tanf(var_f21);
    }
    var_f20 = var_f24 + var_f22;
    if (var_f20 <= minReq) {
        var_f20 = minReq;
    }
    func_003dcb40((RwV3d *)frame.dir170, (const RwV3d *)D_0060A100, 1, (const RtQuat *)frame.quatBC);
    scaleTmp = var_f20 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8))) * 0.109375f * fGpffff80bc;
    frame.center130[0] = frame.center130[0] + frame.dir170[2] * scaleTmp + 0.0f;
    frame.center130[2] = (frame.center130[2] + 0.0f) - frame.dir170[0] * scaleTmp;
    frame.dir170[0] = frame.dir170[0] * var_f20;
    frame.dir170[1] = frame.dir170[1] * var_f20;
    frame.dir170[2] = frame.dir170[2] * var_f20;
    frame.outB0[0] = frame.center130[0] + frame.dir170[0];
    frame.outB0[1] = frame.center130[1] + frame.dir170[1];
    frame.outB0[2] = frame.center130[2] + frame.dir170[2];
    if (*(u16 *)(saved_arg0 + 0x106) == 0) {
        unit2 = *(u8 **)(next + 0x30);
        func_001958f0(unit2, frame.center130);
        if (frame.center130[1] < 50.0f) {
            frame.center130[1] = 50.0f;
        }
        func_001ec1c0(frame.quat70, frame.actor140, frame.center130);
        func_003dcb40((RwV3d *)frame.dir170, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)frame.quat70);
        frame.dir170[0] = frame.dir170[0] * var_f23;
        frame.dir170[1] = frame.dir170[1] * var_f23;
        frame.dir170[2] = frame.dir170[2] * var_f23;
        frame.actor140[0] = frame.actor140[0] + frame.dir170[0];
        frame.actor140[1] = frame.actor140[1] + frame.dir170[1];
        frame.actor140[2] = frame.actor140[2] + frame.dir170[2];
        frame.diff160[0] = frame.actor140[0] - frame.center130[0];
        frame.diff160[1] = frame.actor140[1] - frame.center130[1];
        frame.diff160[2] = frame.actor140[2] - frame.center130[2];
        func_003e40b0((RwV3d *)frame.diff160, (const RwV3d *)frame.diff160);
        scaleTmp = fGpffff811c * func_003e40b0((RwV3d *)frame.diff160, (const RwV3d *)frame.diff160);
        frame.cand150[0] = frame.diff160[0] * scaleTmp + frame.center130[0];
        frame.cand150[1] = frame.diff160[1] * scaleTmp + frame.center130[1];
        frame.cand150[2] = frame.diff160[2] * scaleTmp + frame.center130[2];
        frame.dir170[0] = frame.actor140[0];
        frame.dir170[1] = frame.actor140[1];
        frame.dir170[2] = frame.actor140[2];
        func_001bd780(frame.quatD8, frame.dir170, frame.cand150, D_0060A0E0);
        frame.copyCC[0] = frame.outB0[0];
        frame.copyCC[1] = frame.outB0[1];
        frame.copyCC[2] = frame.outB0[2];
        func_003dcc70(frame.quatBC, frame.quatD8, frame.slerp80);
        polyA = fGpffff8120;
        polyB = fGpffff8124;
        if (frame.modeA4 == 0) {
            sqA = polyA * frame.angleA0;
            sqA = sqA * sqA;
            polyA = sqA * sqA * (sqA * (sqA * (sqA * (sqA * (fGpffff8104 * sqA + fGpffff8054 + 0.0f) + fGpffff8058 + 0.0f) + fGpffff805c + 0.0f) + fGpffff8060 + 0.0f) + fGpffff8108 + 0.0f) + sqA + 0.0f;
            sqB = polyB * frame.angleA0;
            sqB = sqB * sqB;
            polyB = sqB * sqB * (sqB * (sqB * (sqB * (sqB * (fGpffff8104 * sqB + fGpffff8054 + 0.0f) + fGpffff8058 + 0.0f) + fGpffff805c + 0.0f) + fGpffff8060 + 0.0f) + fGpffff8108 + 0.0f) + sqB + 0.0f;
        }
        frame.interp118[0] = frame.slerp80[0] * polyA + frame.slerp80[4] * polyB + 0.0f;
        frame.interp118[1] = frame.slerp80[1] * polyA + frame.slerp80[5] * polyB + 0.0f;
        frame.interp118[2] = frame.slerp80[2] * polyA + frame.slerp80[6] * polyB + 0.0f;
        frame.interp118[3] = frame.slerp80[3] * polyA + frame.slerp80[7] * polyB;
        frame.outB0[0] = frame.outB0[0] * polyA;
        frame.outB0[1] = frame.outB0[1] * polyA;
        frame.outB0[2] = frame.outB0[2] * polyA;
        frame.copyCC[0] = frame.copyCC[0] * polyB;
        frame.copyCC[1] = frame.copyCC[1] * polyB;
        frame.copyCC[2] = frame.copyCC[2] * polyB;
        frame.out10C[0] = frame.outB0[0] + frame.copyCC[0];
        frame.out10C[1] = frame.outB0[1] + frame.copyCC[1];
        frame.out10C[2] = frame.outB0[2] + frame.copyCC[2];
    } else {
        func_001bd5e0(frame.out10C, frame.outB0);
    }
    if (frame.poseF0[1] < 25.0f) {
        frame.poseF0[1] = 25.0f;
    }
    if (frame.out10C[1] < 25.0f) {
        frame.out10C[1] = 25.0f;
    }
    func_001bcd40(*(u8 **)(saved_arg0 + 0xE0), NULL, NULL, 0.0f, 0xE0);
    if (saved_flag != 0) {
        func_001bab00(saved_arg0, frame.out10C);
        return;
    }
    func_001bac20((u16 *)saved_arg0, frame.poseF0, frame.out10C, 1);
    func_001bbef0(saved_arg0, 0.75f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c80f0);
#endif
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
/* measured 001c8e90: 499 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c8e90` (GUARDED_SCORE 499); probe 499 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c8e90 --candidate v1=/var/tmp/cold1c8e90/v1.c`; fnalign retail 556 vs object 555 instrs, 321 edits (+16 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c8e90 --candidate /var/tmp/cold1c8e90/v1.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c8e90 -o /var/tmp/cold1c8e90/m2c.c`; romwright raw via `python3 tools/romwright_decompile.py func_001c8e90 --raw -o /var/tmp/cold1c8e90/rw_raw.c` (m2c-shaped fails on CONCAT44 intrinsic); de-noised to file idiom reusing existing decls (func_001bd560, func_003e40b0, func_001bd780, func_003dcb40, D_0060A0E0/D_0060A100, fGpffff8110/fGpffff8118). Frame 0x160 with slerp70[8]+angle90+mode94+pad98+quatA0+quatB0+quatC0+padD0+vecD8+padE4+pairE8+valF0+padF4+pairF8+val100+pad104+out108+pad114+diff118+pad124+vec128+pad134+vec138+pad144+vec148+pad154+vec158 (0xF0 locals). Round1 v1 499 (556 vs 555, 321+16). Round2 v2 527 (s64 split, +28, frame 0x170 spill), v3 504 (lean s64, +5), v4 507 (split out108 temps, +8). Round3 v5 499 tie (reversed float decls), v6 505 (p4_cacd0_mul, +6), v7 499 tie (dot order [1]+[0]+[2]). Two unproductive rounds, stopping. Top remaining: FPU color shift, COP1 adda/madd+msub vs mul/add chains, ld/sd vs lw/sw copy, polynomial chain, branch layout. */
// FUN_001C8E90 NONMATCHING
#ifdef NON_MATCHING
void func_001c8e90(u8 *arg0, f32 *arg1, f32 *arg2)
{
    struct Frame {
        f32 slerp70[8];
        f32 angle90;
        s32 mode94;
        u8 pad98[8];
        f32 quatA0[4];
        f32 quatB0[4];
        f32 quatC0[4];
        u8 padD0[8];
        f32 vecD8[3];
        u8 padE4[4];
        s64 pairE8;
        f32 valF0;
        u8 padF4[4];
        s64 pairF8;
        f32 val100;
        u8 pad104[4];
        f32 out108[3];
        u8 pad114[4];
        f32 diff118[3];
        u8 pad124[4];
        f32 vec128[3];
        u8 pad134[4];
        f32 vec138[3];
        u8 pad144[4];
        f32 vec148[3];
        u8 pad154[4];
        f32 vec158[2];
    } frame;
    extern f32 fGpffff8118;
    extern f32 fGpffff815c;
    extern f32 iGpffff804c;
    extern f32 fGpffff8110;
    extern f32 fGpffff8104;
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff8108;
    extern f32 iGpffff8160;
    extern f32 func_0044b868(f32 arg0);
    extern f32 func_001ec2b0(void *arg0, void *arg1);
    extern void func_003dcc70(void *arg0, void *arg1, void *arg2);
    extern void func_003dc740(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3);
    extern f32 func_003e41b0(f32 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_00195aa0(u8 *arg0, u8 *arg1, f32 *arg2);
    u8 *work;
    u8 *unitA;
    u8 *tmp;
    u8 *unitB;
    f32 heightSum;
    f32 widthSum;
    f32 dotA;
    f32 blend;
    f32 thresh;
    f32 t;
    f32 oneMinus;
    f32 sqA;
    f32 sqB;
    f32 polyA;
    f32 polyB;
    f32 len;
    f32 inv;
    f32 dotB;
    f32 dotC;
    f32 absA;
    f32 absB;
    f32 dist;
    f32 scale2;

    work = *(u8 **)(arg0 + 0xE0);
    unitA = *(u8 **)(work + 0x30);
    tmp = *(u8 **)(work + 0x38);
    unitB = *(u8 **)(tmp + 0x30);
    *(u8 **)(arg0 + 0x124) = tmp;
    func_001bd560(arg1, arg0 + 0x9C);
    frame.pairE8 = *(s64 *)(unitA + 0xDC);
    frame.valF0 = *(f32 *)(unitA + 0xE4);
    func_00195aa0(unitB, unitA, frame.vecD8);
    heightSum = fGpffff8118 * (*(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C)) + 0.0f + fGpffff8118 * (*(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C)) + 0.0f;
    widthSum = *(f32 *)(unitA + 0xE8) + 0.0f + *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C) + *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) + 0.0f;
    frame.vecD8[1] = 0.0f;
    *(f32 *)((u8 *)&frame.pairE8 + 4) = 0.0f;
    frame.vec128[0] = *(f32 *)(unitA + 0xDC) - frame.vecD8[0];
    frame.vec128[1] = *(f32 *)(unitA + 0xE0) - 0.0f;
    frame.vec128[2] = *(f32 *)(unitA + 0xE4) - frame.valF0;
    func_003e40b0((RwV3d *)frame.vec128, (const RwV3d *)frame.vec128);
    dotA = 0.25f * widthSum;
    frame.out108[0] = frame.vec128[0] * dotA + frame.vecD8[0];
    frame.out108[1] = frame.vec128[1] * dotA + 0.0f;
    frame.out108[2] = frame.vec128[2] * dotA + frame.valF0;
    heightSum = 0.5f * heightSum;
    frame.out108[1] = heightSum;
    frame.vec138[0] = arg1[0];
    frame.vec138[1] = arg1[1];
    frame.vec138[2] = arg1[2];
    frame.vec138[1] = heightSum;
    *(f32 *)(arg0 + 0x10C) = 0.5f * *(f32 *)(unitA + 0xE8);
    *(f32 *)(arg0 + 0x100) = frame.out108[0];
    *(f32 *)(arg0 + 0x104) = heightSum;
    *(f32 *)(arg0 + 0x108) = frame.out108[2];
    func_001bd780(arg2 + 3, frame.vec138, frame.out108, D_0060A0E0);
    heightSum = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) + *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C) + widthSum + 0.0f;
    blend = func_001ec2b0(arg1 + 3, arg2 + 3);
    thresh = fGpffff815c;
    if (!(blend <= thresh)) {
        t = thresh / blend;
        func_003dcc70(arg1 + 3, arg2 + 3, frame.slerp70);
        if (t <= 0.0f) {
            frame.quatC0[0] = arg1[3];
            frame.quatC0[1] = arg1[4];
            frame.quatC0[2] = arg1[5];
            frame.quatC0[3] = arg1[6];
        } else if (t >= 1.0f) {
            frame.quatC0[0] = arg2[3];
            frame.quatC0[1] = arg2[4];
            frame.quatC0[2] = arg2[5];
            frame.quatC0[3] = arg2[6];
        } else {
            oneMinus = 1.0f - t;
            if (frame.mode94 == 0) {
                sqA = oneMinus * frame.angle90;
                sqA = sqA * sqA;
                polyA = sqA * sqA * (sqA * (sqA * (sqA * (sqA * (fGpffff8104 * sqA + fGpffff8054 + 0.0f) + fGpffff8058 + 0.0f) + fGpffff805c + 0.0f) + fGpffff8060 + 0.0f) + fGpffff8108 + 0.0f) + sqA + 0.0f;
                sqB = t * frame.angle90;
                sqB = sqB * sqB;
                polyB = sqB * sqB * (sqB * (sqB * (sqB * (sqB * (fGpffff8104 * sqB + fGpffff8054 + 0.0f) + fGpffff8058 + 0.0f) + fGpffff805c + 0.0f) + fGpffff8060 + 0.0f) + fGpffff8108 + 0.0f) + sqB + 0.0f;
                oneMinus = polyA;
                t = polyB;
            }
            frame.quatC0[0] = frame.slerp70[4] * t + frame.slerp70[0] * oneMinus + 0.0f;
            frame.quatC0[1] = frame.slerp70[5] * t + frame.slerp70[1] * oneMinus + 0.0f;
            frame.quatC0[2] = frame.slerp70[6] * t + frame.slerp70[2] * oneMinus + 0.0f;
            frame.quatC0[3] = frame.slerp70[7] * t + frame.slerp70[3] * oneMinus;
        }
        func_003dcb40((RwV3d *)frame.vec138, (const RwV3d *)D_0060A100, 1, (const RtQuat *)frame.quatC0);
        frame.vec138[0] = frame.vec138[0] + frame.out108[0];
        frame.vec138[1] = frame.vec138[1] + frame.out108[1];
        frame.vec138[2] = frame.vec138[2] + frame.out108[2];
        func_001bd780(arg2 + 3, frame.vec138, frame.out108, D_0060A0E0);
    } else if (blend < iGpffff804c) {
        func_003dc740((u8 *)(arg2 + 3), D_0060A0E0, 2, iGpffff8160);
    }
    if (heightSum < 450.0f) {
        heightSum = 450.0f;
    }
    inv = (0.5f * heightSum) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    func_003dcb40((RwV3d *)frame.vec138, (const RwV3d *)D_0060A100, 1, (const RtQuat *)(arg2 + 3));
    frame.vec128[1] = frame.vec138[1];
    func_003e40b0((RwV3d *)frame.vec128, (const RwV3d *)frame.vec128);
    dotB = frame.vec138[2] * frame.vec128[2] + frame.vec138[0] * frame.vec128[0] + frame.vec138[1] * frame.vec128[1];
    if (!(dotB < 0.0f)) {
        dotA = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C);
        frame.pairF8 = frame.pairE8;
        frame.val100 = frame.valF0;
    } else {
        dotA = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C);
        frame.pairF8 = *(s64 *)frame.vecD8;
        frame.val100 = frame.vecD8[2];
    }
    frame.vec148[0] = frame.vecD8[0] + 0.0f + frame.vec128[2] * dotA + 0.0f;
    frame.vec148[1] = frame.out108[1];
    frame.vec148[2] = (frame.valF0 + 0.0f) - frame.vec128[0] * dotA;
    frame.diff118[0] = frame.vec148[0] - frame.out108[0];
    frame.diff118[1] = frame.vec148[1] - frame.vec148[1];
    frame.diff118[2] = frame.vec148[2] - frame.out108[2];
    func_003e40b0((RwV3d *)frame.diff118, (const RwV3d *)frame.diff118);
    dotC = frame.diff118[2] * frame.vec128[2] + frame.diff118[0] * frame.vec128[0] + frame.diff118[1] * frame.vec128[1];
    absA = dotB < 0.0f ? -dotB : dotB;
    absB = dotC < 0.0f ? -dotC : dotC;
    if (!(absA <= absB) && dotC != 0.0f && dotB != 0.0f) {
        frame.vec158[0] = frame.out108[0] - *(f32 *)&frame.pairF8;
        frame.vec158[1] = frame.out108[2] - frame.val100;
        dist = func_003e41b0(frame.vec158);
        frame.vec148[1] = frame.out108[1] + (heightSum * dist) / inv;
        frame.vec148[0] = *(f32 *)&frame.pairF8 + 0.0f + frame.vec128[2] * dotA + 0.0f;
        frame.vec148[2] = (frame.val100 + 0.0f) - frame.vec128[0] * dotA;
        func_001bd780(frame.quatA0, frame.vec148, frame.out108, D_0060A0E0);
        blend = func_001ec2b0(arg1 + 3, frame.quatA0);
        frame.vec148[0] = (*(f32 *)&frame.pairF8 + 0.0f) - frame.vec128[2] * dotA;
        frame.vec148[2] = frame.vec128[0] * dotA + frame.val100 + 0.0f;
        func_001bd780(frame.quatB0, frame.vec148, frame.out108, D_0060A0E0);
        scale2 = func_001ec2b0(arg1 + 3, frame.quatB0);
        if (blend < scale2) {
            arg2[3] = frame.quatA0[0];
            arg2[4] = frame.quatA0[1];
            arg2[5] = frame.quatA0[2];
            arg2[6] = frame.quatA0[3];
        } else {
            arg2[3] = frame.quatB0[0];
            arg2[4] = frame.quatB0[1];
            arg2[5] = frame.quatB0[2];
            arg2[6] = frame.quatB0[3];
        }
        func_003dcb40((RwV3d *)frame.vec138, (const RwV3d *)D_0060A100, 1, (const RtQuat *)(arg2 + 3));
    }
    frame.vec138[0] = frame.vec138[0] * inv;
    frame.vec138[1] = frame.vec138[1] * inv;
    frame.vec138[2] = frame.vec138[2] * inv;
    len = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    scale2 = inv * len * 0.21875f * 0.5f;
    frame.vec158[0] = frame.vec138[0];
    frame.vec158[1] = frame.vec138[2];
    func_003e41e0(frame.vec158, frame.vec158);
    frame.out108[0] = frame.vec158[1] * scale2 + frame.out108[0] + 0.0f + frame.vec138[0];
    frame.out108[1] = frame.vec148[1] + frame.vec138[1];
    frame.out108[2] = ((frame.out108[2] + 0.0f) - frame.vec158[0] * scale2) + frame.vec138[2];
    arg2[0] = frame.out108[0];
    arg2[1] = frame.out108[1];
    arg2[2] = frame.out108[2];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c8e90);
#endif
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
// FUN_001C9820 NONMATCHING
#ifdef NON_MATCHING
/* measured 001c9820: 809 differing words via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c9820 --candidate v1=/var/tmp/lead1c9820/v1.c` (sched 787 draft-short, commons 898, loopinv 809 tie, sched_scoped 787 draft-short); fnalign retail 844 vs object 850 instrs (+6, +0.7% inside 3% gate 819-869), 670 edits (+2 reloc-only) via `python3 -E -s tools/fnalign.py src/promoted/code1_001c.c func_001c9820 --candidate /var/tmp/lead1c9820/v1.c --quiet`. */
/* M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c9820 -o /var/tmp/lead1c9820/m2c_fresh.c`; romwright via `python3 -E -s tools/romwright_decompile.py func_001c9820` (+ --types: arg0 *{+0x9C,+0xA4,+0xB8,+0xE0}, float param). Signature (u8*,s32,s32,f32) from prologue $a0/$f12/$a1/$a2; romwright (float,ushort*,long,int) wrong. */
/* Camera idiom as MATCHED 001c79f0 (arg0+0x9C, *(arg0+0xE0), s0/s1 units, 001bd560/00195850/003e40b0/003e41e0/001bd780/003dcb40/001ec3d0/001bac20/001bbef0/001bcd40). MAC (adda/mula/madd/msub) as plain C per 7r (+0.0f, two-product mula/madd, copy_pair ld/sd); no inline asm. Ghidra/IDA bodies + retail 844i + P01C COP1 archive note read; archive floor claim overturned (plain C reaches 850). */
void func_001c9820(u8 *arg0, s32 arg1, s32 arg2, f32 arg3)
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
    struct Work {
        f32 pose90[7];
        f32 outAC[3];
        struct Quat quatB8;
        f32 horizD0[2];
        f32 perpD8[2];
        f32 vecE0[2];
        f32 vecE8[2];
        f32 vecF0[2];
        f32 vecF8[2];
        s64 pair100;
        f32 val108;
        f32 eye110[3];
        struct Vec3 dir120;
        struct Vec3 base130;
        s64 pair140;
        f32 val148;
        struct Vec3 centerB150;
        struct Vec3 centerA160;
    } work;
    extern f32 fGpffff8098;
    extern f32 fGpffff80cc;
    extern f32 fGpffff810c;
    extern f32 fGpffff8110;
    extern f32 fGpffff8128;
    extern f32 fGpffff816c;
    extern f32 fGpffff8168;
    extern f32 fGpffff8170;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec3d0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
    extern f32 func_001ec2b0(void *first, void *second);
    extern f32 func_0044b868(f32 arg0);
    u8 *saved_arg0;
    u8 *action;
    u8 *unitA;
    u8 *unitB;
    u8 *var17;
    u8 *var18;
    f32 var_f20;
    f32 var_f22;
    f32 var_f23;
    f32 dot;
    f32 scaleA;
    f32 scaleB;
    f32 tmp;
    f32 len;
    f32 grow;
    f32 div;
    f32 eth;
    f32 fVar5;
    f32 fVar8;

    saved_arg0 = arg0;
    action = *(u8 **)(saved_arg0 + 0xE0);
    unitA = *(u8 **)(action + 0x30);
    unitB = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560(work.pose90, (f32 *)(saved_arg0 + 0x9C));
    func_00195850(unitA, (f32 *)&work.centerA160);
    func_00195850(unitB, (f32 *)&work.centerB150);
    var_f23 = *(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C) * 0.5f + work.centerB150.y + 0.0f;
    if (work.centerB150.y < 125.0f) {
        work.centerB150.y = 125.0f;
    }
    var_f22 = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C);
    tmp = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C);
    work.dir120.x = work.centerA160.x - work.centerB150.x;
    work.dir120.y = work.centerA160.y - work.centerB150.y;
    work.dir120.z = work.centerA160.z - work.centerB150.z;
    len = func_003e40b0((RwV3d *)&work.dir120, (const RwV3d *)&work.dir120);
    scaleA = fGpffff8128 * len;
    work.base130.x = work.dir120.x * scaleA + work.centerB150.x;
    work.base130.y = work.dir120.y * scaleA + work.centerB150.y;
    work.base130.z = work.dir120.z * scaleA + work.centerB150.z;
    work.perpD8[0] = *(f32 *)(saved_arg0 + 0x9C) - work.base130.x;
    work.perpD8[1] = *(f32 *)(saved_arg0 + 0xA4) - work.base130.z;
    func_003e41e0(work.perpD8, work.perpD8);
    work.horizD0[0] = work.dir120.x;
    work.horizD0[1] = work.dir120.z;
    dot = work.dir120.x * work.perpD8[0] + work.dir120.z * work.perpD8[1];
    if (((dot < 0.0f) && (arg2 != 1)) || (arg1 != 0)) {
        var17 = unitB;
        var18 = unitA;
        eth = 0.5f * len;
        work.base130.x = work.dir120.x * eth + work.centerB150.x;
        work.base130.y = work.dir120.y * eth + work.centerB150.y;
        work.base130.z = work.dir120.z * eth + work.centerB150.z;
        func_001c_copy_pair(&work.pair140, &work.val148, (s64 *)&work.centerB150.x, &work.centerB150.z);
        scaleB = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) * 2.5f;
        if (var_f23 <= 400.0f) {
            work.base130.y = fGpffff8098 * *(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C) + work.base130.y + 0.0f;
        } else {
            work.base130.y = fGpffff810c * *(f32 *)(unitB + 0x8C) * *(f32 *)(unitB + 0x2C) + work.base130.y + 0.0f;
        }
        work.horizD0[0] = work.dir120.z;
        work.horizD0[1] = -work.dir120.x;
        var_f23 = work.dir120.z * work.perpD8[0] + work.horizD0[1] * work.perpD8[1];
        work.eye110[2] = *(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C) * 0.5f + work.centerA160.y + 0.0f;
        if (work.centerB150.y < work.centerA160.y) {
            work.eye110[2] = work.centerA160.y;
        }
        if (!(var_f23 < 0.0f)) {
            work.eye110[0] = work.dir120.z * scaleB + work.centerB150.x + 0.0f;
            work.eye110[1] = (work.centerB150.z + 0.0f) - work.dir120.x * scaleB;
            func_001c_copy_pair(&work.pair100, &work.val108, (s64 *)&work.dir120.x, &work.dir120.z);
        } else {
            work.eye110[0] = (work.centerB150.x + 0.0f) - work.dir120.z * scaleB;
            work.eye110[1] = work.dir120.x * scaleB + work.centerB150.z + 0.0f;
        }
        fVar8 = work.centerB150.y;
        func_001bd780((void *)&work.quatB8, (void *)work.eye110, (void *)&work.base130, (void *)D_0060A0E0);
        func_003dcb40((RwV3d *)&work.dir120, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.quatB8);
        work.vecE0[0] = work.base130.x;
        work.vecE0[1] = work.base130.z;
        work.vecE8[0] = work.eye110[0];
        work.vecE8[1] = work.eye110[1];
        func_001c_copy_pair(&work.pair140, &work.val148, (s64 *)&work.centerB150.x, &work.centerB150.z);
        fVar5 = func_001ec3d0(work.vecE0, work.vecE8, (f32 *)&work.pair140, work.vecF0);
        fVar8 = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C) * 2.0f + fVar5 + 0.0f;
        work.eye110[0] = work.vecF0[0];
        work.eye110[2] = *(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C) * 0.25f + fVar8 + 0.0f;
        work.eye110[1] = work.vecF0[1];
        div = func_0044b868(fGpffff8110 * *(f32 *)(saved_arg0 + 0xB8) * 0.5f);
        fVar5 = fVar8 / div;
        work.dir120.x = work.dir120.x * fVar5;
        work.dir120.y = work.dir120.y * fVar5;
        work.dir120.z = work.dir120.z * fVar5;
        if (var_f23 < 0.0f) {
            scaleA = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C) * 2.0f;
            work.eye110[0] = work.val108 * scaleA + work.eye110[0] + 0.0f;
            work.eye110[1] = (work.eye110[1] + 0.0f) - *(f32 *)&work.pair100 * scaleA;
        }
        work.outAC[0] = work.eye110[0] + work.dir120.x;
        work.outAC[1] = work.eye110[2] + work.dir120.y;
        work.outAC[2] = work.eye110[1] + work.dir120.z;
        var17 = unitA;
        var18 = unitB;
    } else {
        var17 = unitA;
        var18 = unitB;
        func_001c_copy_pair(&work.pair140, &work.val148, (s64 *)&work.centerA160.x, &work.centerA160.z);
        scaleB = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C) * 1.25f;
        work.horizD0[0] = work.dir120.z;
        work.horizD0[1] = -work.dir120.x;
        var_f23 = work.dir120.z * work.perpD8[0] + work.horizD0[1] * work.perpD8[1];
        work.eye110[2] = work.centerA160.y;
        if (work.centerA160.y < work.centerB150.y) {
            work.eye110[2] = work.centerB150.y;
        }
        if (var_f23 < 0.0f) {
            work.eye110[0] = work.centerB150.x + 0.0f - work.dir120.z * 1.25f * tmp;
            work.eye110[1] = work.dir120.x * 1.25f * tmp + work.centerB150.z + 0.0f;
        } else {
            work.eye110[0] = work.dir120.z * 1.25f * tmp + work.centerB150.x + 0.0f;
            work.eye110[1] = (work.centerB150.z + 0.0f) - work.dir120.x * 1.25f * tmp;
            func_001c_copy_pair(&work.pair100, &work.val108, (s64 *)&work.dir120.x, &work.dir120.z);
        }
        func_001bd780((void *)&work.quatB8, (void *)work.eye110, (void *)&work.base130, (void *)D_0060A0E0);
        func_003dcb40((RwV3d *)&work.dir120, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.quatB8);
        work.vecE0[0] = work.base130.x;
        work.vecE0[1] = work.base130.z;
        work.vecE8[0] = work.eye110[0];
        work.vecE8[1] = work.eye110[1];
        func_001c_copy_pair(&work.pair140, &work.val148, (s64 *)&work.centerA160.x, &work.centerA160.z);
        fVar5 = func_001ec3d0(work.vecE0, work.vecE8, (f32 *)&work.pair140, work.vecF0);
        work.eye110[0] = work.vecF0[0];
        work.eye110[1] = work.vecF0[1];
        div = func_0044b868(fGpffff8110 * *(f32 *)(saved_arg0 + 0xB8) * 0.5f);
        grow = 550.0f;
        tmp = (*(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) * 1.5f + fVar5 + 0.0f) / div;
        if (550.0f <= tmp) {
            grow = tmp;
        }
        work.dir120.x = work.dir120.x * grow;
        work.dir120.y = work.dir120.y * grow;
        work.dir120.z = work.dir120.z * grow;
        if (!(var_f23 < 0.0f)) {
            scaleA = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) * 0.5f;
            work.eye110[0] = (work.eye110[0] + 0.0f) - work.val108 * scaleA;
            work.eye110[1] = *(f32 *)&work.pair100 * scaleA + work.eye110[1] + 0.0f;
        }
        work.outAC[0] = work.eye110[0] + work.dir120.x;
        work.outAC[1] = work.eye110[2] + work.dir120.y;
        work.outAC[2] = work.eye110[1] + work.dir120.z;
    }
    tmp = func_001ec2b0((void *)&work.pose90[3], (void *)&work.quatB8.x);
    if ((arg3 <= 0.0f) || (grow = fGpffff816c * arg3, !(tmp <= grow))) {
        if (dot < 0.0f) {
            func_001bab00(saved_arg0, (void *)work.outAC);
            func_003dcb40((RwV3d *)&work.dir120, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.quatB8);
            work.dir120.x = work.dir120.x * 200.0f;
            work.dir120.y = work.dir120.y * 200.0f;
            work.dir120.z = work.dir120.z * 200.0f;
            work.pose90[0] = work.outAC[0] + work.dir120.x;
            work.pose90[1] = work.outAC[1] + work.dir120.y;
            work.pose90[2] = work.outAC[2] + work.dir120.z;
            work.pose90[3] = work.quatB8.x;
            work.pose90[4] = work.quatB8.y;
            work.pose90[5] = work.quatB8.z;
            work.pose90[6] = work.quatB8.w;
            if (work.pose90[1] < 25.0f) {
                work.pose90[1] = 25.0f;
            }
            if (work.outAC[1] < 25.0f) {
                work.outAC[1] = 25.0f;
            }
            func_001bac20((u16 *)saved_arg0, work.pose90, work.outAC, 1);
            func_001bbef0(saved_arg0, fGpffff8168);
        } else {
            tmp = *(f32 *)(var17 + 0x90) * *(f32 *)(var17 + 0x2C);
            work.dir120.x = work.centerA160.x - work.centerB150.x;
            work.dir120.y = work.centerA160.y - work.centerB150.y;
            work.dir120.z = work.centerA160.z - work.centerB150.z;
            func_003e40b0((RwV3d *)&work.dir120, (const RwV3d *)&work.dir120);
            work.eye110[2] = fGpffff8170 * *(f32 *)(var17 + 0x8C) * *(f32 *)(var17 + 0x2C) + grow + 0.0f;
            if (!(var_f23 < 0.0f)) {
                work.eye110[0] = (*(f32 *)&work.pair140 + 0.0f) - work.dir120.z * tmp;
                work.eye110[1] = work.dir120.x * tmp + fVar5 + 0.0f;
            } else {
                work.eye110[0] = work.dir120.z * tmp + *(f32 *)&work.pair140 + 0.0f;
                work.eye110[1] = (fVar5 + 0.0f) - work.dir120.x * tmp;
            }
            func_001bd780((void *)&work.pose90[3], (void *)work.eye110, (void *)&work.base130, (void *)D_0060A0E0);
            func_003dcb40((RwV3d *)&work.dir120, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&work.pose90[3]);
            work.vecE0[0] = work.base130.x;
            work.vecE0[1] = work.base130.z;
            work.vecE8[0] = work.eye110[0];
            work.vecE8[1] = work.eye110[1];
            func_001c_copy_pair(&work.pair140, &work.val148, (s64 *)&work.centerA160.x, &work.centerA160.z);
            func_001ec3d0(work.vecE0, work.vecE8, (f32 *)&work.pair140, work.vecF0);
            work.eye110[0] = work.vecF0[0];
            work.eye110[2] = fGpffff8170 * *(f32 *)(var17 + 0x8C) * *(f32 *)(var17 + 0x2C) + grow + 0.0f;
            work.eye110[1] = work.vecF0[1];
            div = func_0044b868(fVar8 * *(f32 *)(saved_arg0 + 0xB8) * 0.5f);
            fVar5 = (*(f32 *)(var17 + 0x90) * *(f32 *)(var17 + 0x2C) * 4.0f) / div;
            work.dir120.x = work.dir120.x * fVar5;
            work.dir120.y = work.dir120.y * fVar5;
            work.dir120.z = work.dir120.z * fVar5;
            work.pose90[0] = work.eye110[0] + work.dir120.x;
            work.pose90[1] = work.eye110[2] + work.dir120.y;
            work.pose90[2] = work.eye110[1] + work.dir120.z;
            if (work.pose90[1] < 25.0f) {
                work.pose90[1] = 25.0f;
            }
            if (work.outAC[1] < 25.0f) {
                work.outAC[1] = 25.0f;
            }
            func_001bac20((u16 *)saved_arg0, work.pose90, work.outAC, 1);
            func_001bbef0(saved_arg0, fGpffff8168);
        }
        if (!(var_f22 <= tmp)) {
        } else {
            var_f22 = tmp;
        }
        func_001bcd40(*(u8 **)(saved_arg0 + 0xE0), var18 + 4, (u8 *)work.outAC, var_f22, 3);
        return;
    }
    if (!(var_f22 <= tmp)) {
    } else {
        var_f22 = tmp;
    }
    func_001bcd40(*(u8 **)(saved_arg0 + 0xE0), var18 + 4, (u8 *)work.outAC, var_f22, 0xC3);
    if (work.pose90[1] < 25.0f) {
        work.pose90[1] = 25.0f;
    }
    if (work.outAC[1] < 25.0f) {
        work.outAC[1] = 25.0f;
    }
    tmp = func_001ec2b0((void *)&work.pose90[3], (void *)&work.quatB8.x);
    var_f20 = 1.25f;
    if (!(tmp <= 0.0f)) {
        div = grow / tmp;
        if (!(div <= 1.0f)) {
            var_f20 = div * fGpffff80cc;
        } else {
            var_f20 = fGpffff80cc;
        }
        if (!(var_f20 <= 1.25f)) {
            var_f20 = 1.25f;
        }
    }
    func_001bac20((u16 *)saved_arg0, work.pose90, work.outAC, 1);
    func_001bbef0(saved_arg0, var_f20);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c9820);
#endif
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
/* measured 001cb970 2026-09-19: landed (was described but never written): explicit frame pad00[0x90] + pad15C[4] at retail 0x90-0x158 + schedule pragmas removed; object 385/retail 385 exact INSIDE, 343 words, 192 edits (+3 reloc-only) (was 344/384 -10.4%, 357 words, 395 edits with schedule on + relative frame). 35-hole at 0x1cbd78-0x1cbe00 (targetXZ spill lwc1 0x120/swc1 0xE0 etc + 001ec3d0(E0,E8,F8,F0) + ecRet mul/adda/madd) closed; a2=F8/a3=F0 already correct in tree. No pure deletes remain (all replaces); residual is base-reg mirror at 0x1cbd80 (E0/E4 spill pair, same order/width, wrong base). Prior schedule note (367->357) superseded — retail is unscheduled here, schedule on compacted 385->344. */
// FUN_001CB970 NONMATCHING
#ifdef NON_MATCHING
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
    struct {
        u8 pad00[0x90];
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        f32 spA4;
        f32 spA8;
        f32 spAC;
        f32 spB0;
        f32 spB4;
        f32 spB8;
        f32 spBC;
        f32 spC0;
        f32 spC4;
        u8 pad_C8[8];
        f32 spD0;
        f32 spD4;
        f32 spD8;
        f32 spDC;
        f32 spE0;
        f32 spE4;
        f32 spE8;
        f32 spEC;
        f32 spF0;
        f32 spF4;
        f32 spF8;
        f32 spFC;
        f32 sp100;
        f32 sp104;
        f32 sp108;
        u8 pad_10C[4];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        u8 pad_11C[4];
        f32 sp120;
        f32 sp124;
        f32 sp128;
        u8 pad_12C[4];
        f32 sp130;
        f32 sp134;
        f32 sp138;
        u8 pad_13C[4];
        f32 sp140;
        f32 sp144;
        f32 sp148;
        u8 pad_14C[4];
        f32 sp150;
        f32 sp154;
        f32 sp158;
        u8 pad15C[4];
    } frame;
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
    func_001959d0((BtlUnit *)unitA, (RwV3d *)&frame.sp150);
    func_001959d0((BtlUnit *)unitB, (RwV3d *)&frame.sp140);
    frame.sp110 = frame.sp150 - frame.sp140;
    frame.sp114 = frame.sp154 - frame.sp144;
    frame.sp118 = frame.sp158 - frame.sp148;
    len = func_003e40b0((RwV3d *)&frame.sp110, (const RwV3d *)&frame.sp110);
    frame.spD8 = *(f32 *)(camera + 0x9C) - frame.sp150;
    frame.spDC = *(f32 *)(camera + 0xA4) - frame.sp158;
    func_003e41e0(&frame.spD8, &frame.spD8);
    frame.spD0 = frame.sp110;
    frame.spD4 = frame.sp118;
    dot1 = frame.spD4 * frame.spDC + frame.spD0 * frame.spD8;
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
        func_001c_copy_pair((s64 *)&frame.sp130, &frame.sp138,
                            (s64 *)&frame.sp150, &frame.sp158);
        scaleOther = 1.25f * p4_cacd0_mul(*(f32 *)(unitA + 0x90), *(f32 *)(unitA + 0x2C));
        scaleXZ = 0.35f * len;
        finalMul = 1.35f;
        frame.sp120 = frame.sp110 * scaleXZ;
        frame.sp124 = frame.sp114 * scaleXZ;
        frame.sp128 = frame.sp118 * scaleXZ;
        if (frame.sp134 < 100.0f) {
            frame.sp134 = 100.0f;
        }
        frame.sp104 = frame.sp134;
    } else {
        selUnit = unitB;
        otherUnit = unitA;
        func_001c_copy_pair((s64 *)&frame.sp130, &frame.sp138,
                            (s64 *)&frame.sp140, &frame.sp148);
        scaleOther = 0.35f * p4_cacd0_mul(*(f32 *)(unitB + 0x90), *(f32 *)(unitB + 0x2C));
        finalMul = 2.5f;
        frame.sp154 = (frame.sp154 + 0.0f) - 0.25f * p4_cacd0_mul(*(f32 *)(unitB + 0x8C), *(f32 *)(unitB + 0x2C));
        if (frame.sp154 < 100.0f) {
            frame.sp154 = 100.0f;
        }
        frame.sp110 = frame.sp150 - frame.sp140;
        frame.sp114 = frame.sp154 - frame.sp144;
        frame.sp118 = frame.sp158 - frame.sp148;
        len = func_003e40b0((RwV3d *)&frame.sp110, (const RwV3d *)&frame.sp110);
        scaleXZ = 0.25f * len;
        frame.sp120 = frame.sp110 * scaleXZ;
        frame.sp124 = frame.sp114 * scaleXZ;
        frame.sp128 = frame.sp118 * scaleXZ;
        frame.sp104 = frame.sp134;
    }
    frame.sp120 = frame.sp120 + frame.sp140;
    frame.sp124 = frame.sp124 + frame.sp144;
    frame.sp128 = frame.sp128 + frame.sp148;
    frame.spD0 = frame.sp118;
    frame.spD4 = -frame.sp110;
    dot2 = frame.spD0 * frame.spD8 + frame.spD4 * frame.spDC;
    if (arg1 != 0) {
        *(s32 *)(camera + 0x108) = (dot2 >= 0.0f) ? 1 : 0;
    }
    if (*(s32 *)(camera + 0x108) == 1) {
        frame.sp100 = (frame.sp130 + 0.0f) + frame.sp118 * scaleOther;
        frame.sp108 = (frame.sp138 + 0.0f) - frame.sp110 * scaleOther;
    } else {
        frame.sp100 = (frame.sp130 + 0.0f) - frame.sp118 * scaleOther;
        frame.sp108 = (frame.sp138 + 0.0f) + frame.sp110 * scaleOther;
    }
    selZ = frame.sp138;
    func_001bd780(&frame.spB8, &frame.sp100, &frame.sp120, D_0060A0E0);
    func_003dcb40((RwV3d *)&frame.sp110, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.spB8);
    frame.spE0 = frame.sp120;
    frame.spE4 = frame.sp128;
    frame.spE8 = frame.sp100;
    frame.spEC = frame.sp108;
    frame.spF8 = frame.sp130;
    frame.spFC = selZ;
    ecRet = func_001ec3d0((u8 *)&frame.spE0, (u8 *)&frame.spE8, (u8 *)&frame.spF8, (u8 *)&frame.spF0);
    ecRet = ecRet + 0.0f + finalMul * p4_cacd0_mul(*(f32 *)(selUnit + 0x90), *(f32 *)(selUnit + 0x2C));
    frame.sp100 = frame.spF0;
    frame.sp104 = frame.sp134;
    frame.sp108 = frame.spF4;
    tanRes = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    finalScale = ecRet / tanRes;
    if (finalScale < 500.0f) {
        finalScale = 500.0f;
    }
    frame.sp110 = frame.sp110 * finalScale;
    frame.sp114 = frame.sp114 * finalScale;
    frame.sp118 = frame.sp118 * finalScale;
    frame.spAC = frame.sp100 + frame.sp110;
    frame.spB0 = frame.sp104 + frame.sp114;
    frame.spB4 = frame.sp108 + frame.sp118;
    if (frame.spB0 < 12.5f) {
        frame.spB0 = 12.5f;
    }
    func_001bd560(&frame.sp90, (f32 *)(camera + 0x9C));
    if (arg1 != 0) {
        if (func_001ec2b0(&frame.sp9C, &frame.spB8) > fGpffff80dc) {
            func_001bd5e0((u8 *)&frame.sp90, (u8 *)&frame.spAC);
            mode = 3;
        } else {
            mode = 0x83;
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), otherUnit + 4, (u8 *)&frame.spAC, 50.0f, mode);
    }
    func_001bac20((u16 *)camera, &frame.sp90, &frame.spAC, 1);
    func_001bbef0(camera, fparg0);
}
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
