#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_clump_internal.h"

extern void (*jtbl_008873EC[])(void *ptr);
extern void func_00492cd0(void *ptr);
extern void func_003c0700(void *arg0);
extern u8 *func_003c0520(void *ptr);
extern void func_0046d730(const char *file, s32 line);
extern char D_00714520[];
extern void *func_004ae080(void *object, void *data);
extern void func_00492d10(void *arg0);
extern void func_004ae0a0(void *arg0, void *arg1);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern void func_0044ea90(const void *msg, s32 id);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern char D_00714508[];
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern u8 *func_003e6a90(s32 arg0);
extern void func_003ef260(void *arg0, s32 (*arg1)(s32, void *), s32 *arg2);
extern void func_003ef1b0(void *arg0);
extern u8 *func_003c0f20(s32 arg0);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void func_00463250(void *arg0);
extern s32 func_00463100(s32 arg0, void *arg1);
extern u8 *func_00484490(void);
extern s32 func_004844d0(void *obj);

void func_004aea70(u8 *arg0, s32 arg1, s32 arg2);

void func_004ae880(u8 *arg0, u8 *arg1);
void func_004ae930(u8 *arg0, u32 arg1, u8 *arg2);

// FUN_004AE460
u8 *func_004ae460(u8 *arg0)
{
    s32 temp_2_3;
    s32 temp_3;
    u32 var_19;
    u8 *temp_2_2;
    u8 *temp_2;

    temp_2_2 = func_00484490();
    if (temp_2_2 == 0) {
        func_0046d730(D_00714520, 0xFD);
    }
    temp_3 = *(s32 *)(temp_2_2 + 0x64);
    if (temp_3 == 0) {
        var_19 = *(u32 *)(temp_2_2 + 0xFC) * *(u32 *)(temp_2_2 + 0x68);
    } else {
        var_19 = temp_3 * *(u32 *)(temp_2_2 + 0x68);
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    func_0044ea90(D_00714508, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    func_0043f9c8(temp_2, 0, 0x94);
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xC5);
    }
    *(u32 *)(temp_2 + 0) = var_19;
    *(u32 *)(temp_2 + 4) = -1;
    *(u32 *)(temp_2 + 8) = 0x3F800000;
    *(u16 *)(temp_2 + 0x7C) = 0x18;
    *(u8 **)(temp_2 + 0x80) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xFF);
    }
    func_0043f810(temp_2 + 0x10, temp_2_2, 0x44);
    func_004ae930(temp_2, *(u16 *)(arg0 + 0xC), temp_2_2 + 0x44);
    if (*(u32 *)(*(u8 **)(temp_2 + 0x58) + 8) == 0) {
        return temp_2;
    }
    temp_2_3 = func_004844d0(arg0);
    if (temp_2_3 != 0) {
        switch (*(u16 *)(arg0 + 0x1C)) {
        case 3:
            func_004aea70(temp_2, temp_2_3, *(u32 *)(arg0 + 0x24));
            break;
        default:
            func_0046d730(D_00714520, 0x114);
            break;
        }
        *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0x1C);
    }
    return temp_2;
}

// FUN_004AE650
void func_004ae650(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;

    temp_4 = *(u32 *)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492cd0((void *)temp_4);
    }
    temp_4_2 = *(u32 *)(arg0 + 0x60);
    if (temp_4_2 != 0) {
        jtbl_008873EC[0]((void *)temp_4_2);
    }
    temp_4_3 = *(u8 **)(arg0 + 0x54);
    if (temp_4_3 != 0) {
        func_003c0700(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004AE6D0
u8 *func_004ae6d0(u8 *arg0)
{
    u32 temp_3;
    u32 var_19;
    u8 *temp_17;
    u8 *temp_2;
    if (*(u8 **)(arg0 + 0x58) == 0) {
        func_0046d730(D_00714520, 0x148);
    }
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x58) + 0x24);
    if (temp_17 == 0) {
        func_0046d730(D_00714520, 0x14A);
    }
    temp_3 = *(u32 *)(temp_17 + 0x20);
    if (temp_3 == 0) {
        var_19 = *(u32 *)(temp_17 + 0xB8) * *(u32 *)(temp_17 + 0x24);
    } else {
        var_19 = temp_3 * *(u32 *)(temp_17 + 0x24);
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    func_0044ea90(D_00714508, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    func_0043f9c8(temp_2, 0, 0x94);
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xC5);
    }
    *(u32 *)(temp_2 + 0) = var_19;
    *(u32 *)(temp_2 + 4) = -1;
    *(u32 *)(temp_2 + 8) = 0x3F800000;
    *(u16 *)(temp_2 + 0x7C) = 0x18;
    *(u8 **)(temp_2 + 0x80) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0x14C);
    }
    func_0043f810(temp_2 + 0x10, arg0 + 0x10, 0x44);
    func_004ae930(temp_2, *(u16 *)(*(u8 **)(arg0 + 0x58) + 0), temp_17);
    if (*(u32 *)(*(u8 **)(temp_2 + 0x58) + 8) == 0) {
        return temp_2;
    }
    func_004ae880(temp_2, arg0);
    return temp_2;
}
// FUN_004AE880
void func_004ae880(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;

    switch (*(u16 *)(arg1 + 0xC)) {
    case 3:
        if (*(u32 *)(arg0 + 0x54) != 0) {
            func_003c0700((void *)*(u32 *)(arg0 + 0x54));
        }
        temp_2 = func_003c0520((void *)*(u32 *)(arg1 + 0x54));
        *(u8 **)(arg0 + 0x54) = temp_2;
        func_003bff30(temp_2, func_004ae080, 0);
        break;
    default:
        func_0046d730(D_00714520, 0x172);
        break;
    }
    *(u16 *)(arg0 + 0xC) = *(u16 *)(arg1 + 0xC);
}

// FUN_004AE930
void func_004ae930(u8 *arg0, u32 arg1, u8 *arg2)
{
    u32 temp_16;
    u8 *var_19;
    u32 var_18;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492cd0(temp_4);
    }
    if (*(u32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(D_00714520, 0x18B);
    }
    *(u8 **)(arg0 + 0x58) = func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
    if (*(u32 *)(arg0 + 0x60) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(arg0 + 0x60));
    }
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x58) + 8);
    func_0044ea90(D_00714520, 0x195);
    *(u8 **)(arg0 + 0x60) = (u8 *)jtbl_008873E8[0](temp_16 * 0x18, 0x40000);
    if (*(u8 **)(arg0 + 0x60) == 0) {
        func_0046d730(D_00714520, 0x196);
    }
    var_19 = *(u8 **)(arg0 + 0x60);
    *(u8 **)(arg0 + 0x5C) = var_19;
    var_18 = 0;
    while (var_18 < temp_16) {
        func_004ae0a0(arg0, var_19);
        var_18++;
        var_19 += 0x18;
    }
}

/* measured MATCH: aggregate-stack body is object 472B in the 480B retail
   window with normalized_diff 0. The decisive source fact is unsigned
   `u32 value` in the aggregate, which flips the default-call argument
   materialization to retail's move $a0,$s2 then lw $a1,0x64($sp).
   Probed and rejected before the type fix: pointer-local body (nd 292/object
   456), initial aggregate (nd 42/object 472), stack/register variants (nd
   28, 75, 77, 79/object 472), explicit zero-dispatch forms (nd 8/object
   472), no-op/cast argument expressions, named argument assignments,
   optimization_level 1, opt_propagation off, opt_common_subs off, and
   schedule on. */
// FUN_004AEA70
void func_004aea70(u8 *arg0, s32 arg1, s32 arg2) {
    struct AeaWork { s32 code; u32 value; u8 pad8[0x18]; s32 in1; s32 in2; s32 outpad; s32 out; } work;
    s32 temp18; u8 *var17; u8 *var16;
    var17 = NULL; var16 = NULL; work.out = 0;
    if (*(u8 **)(arg0 + 0x58) == NULL) func_0046d730(D_00714520, 0x1B3);
    if (*(s32 *)(*(u8 **)(arg0 + 0x58) + 8) == 0) func_0046d730(D_00714520, 0x1B4);
    work.in1 = arg1; work.in2 = arg2; temp18 = func_003e2f60(3, 1, &work.in1);
    while (func_003df3c0(temp18, &work.code) != 0) {
      if (work.code == 0) goto done;
      switch (work.code) {
      case 22:
        if (var16 == NULL) {
          var16 = func_003e6a90(temp18);
          func_003ef260(var16, func_00463100, &work.out);
          func_003ef1b0(var16);
        }
        break;
      case 16:
        if (var17 == NULL) var17 = func_003c0f20(temp18);
        break;
      default:
        func_003e2ce0(temp18, work.value);
        break;
      }
    }
  done:
    func_003e2e40(temp18, &work.in1); if (work.out != 0) func_00463250((void *)work.out); if (var17 == NULL) func_0046d730(D_00714520, 0x1DF); *(u8 **)(arg0 + 0x54) = var17; func_003bff30(var17, func_004ae080, NULL);
}





// FUN_004AEC50
void func_004aec50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AEC80
void func_004aec80(u8 *arg0)
{
    s32 temp_16;
    s32 var_20;
    u8 *var_18;
    u8 *var_17;
    u8 *temp_4;

    func_00492d10((void *)*(u32 *)(arg0 + 0x58));
    temp_4 = *(u8 **)(arg0 + 0x58);
    temp_16 = *(s32 *)(temp_4 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_4 + 0x10) != 0)) {
        var_18 = *(u8 **)(temp_4 + 0x18);
        var_17 = *(u8 **)(arg0 + 0x5C);
        switch (*(u16 *)(arg0 + 0xC)) {
        case 3:
            var_20 = 0;
            while (var_20 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) == 0) {
                    func_004ae0a0(arg0, var_17);
                }
                var_20++;
                var_18 += 0x20;
                var_17 += 0x18;
            }
            break;
        default:
            func_0046d730(D_00714520, 0x213);
            break;
        }
    }
}

/* measured clean_v4: retail 492 vs object 493 (+1, +0.2% inside 3% gate), probe 455 words, fnalign 678 edits. Fix chain: v1 scalar 815/782 -> v3 signed colour (s32 word+mask unpack, s32 pack with shifts) 553/523 -> v4 single VU bridge per loop after call (unpack+modulate+pack, lui 0x437F first loop, mfc1 full second) 493/455. Parent stays signed s32+mask (20 instrs vs VU 9) to hold size. Banked as guarded floor. Remeasure 2026-09-19: hoist 0.5f in small branch (f32 half=0.5f before loop, use half in f computation) 678->675 (-3, words 479 same, 493/492 same); still missing $f26 (retail 0x230 vs object 0x200, retail saves $f26) so retail holds one more float (likely 0.5f/full/gscale/inv held vs recomputed) - opposite case from sinking floors, needs hoist not sink. */
// FUN_004AED70 NONMATCHING
#ifdef NON_MATCHING
void func_004aed70(u8 *arg0)
{
    extern void func_00492df0(void *a, void *b);
    extern void func_00492db0(void *a, void *b);
    extern void func_004bceb0(void);
    extern void func_004ae2f0(u8 *a, u8 *b, s32 c);
    extern u32 *func_004ae020(u32 *a, u8 *b);
    extern void func_003bff30(void *a, void *b, void *c);
    extern void func_003bfe90(void *a);
    extern void func_003e0870(void *a, void *b, s32 c, f32 d);
    extern void *func_003e05f0(void *a, void *b, void *c);
    extern void func_003e0a90(void *a, void *b, s32 c);
    extern void func_003e0c90(void *a, void *b, s32 c);
    extern void func_003e9cb0(void *a, void *b, s32 c);
    extern void func_004813f0(void);
    extern f32 fGpffff81f4;
    extern f32 fGpffff8048;
    extern u8 D_00713D20[];
    extern u8 D_00713D24[];
    extern u8 D_00713D28[];
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    f32 parent[4] __attribute__((aligned(16)));
    u8 snapA[16];
    u8 snapB[16];
    f32 snap[16];
    f32 base[12];
    f32 matA[16];
    f32 matB[16];
    f32 axis[4];
    f32 scale[3];
    f32 pos[3];
    u8 *tmp4;
    s32 cnt;
    u8 *p18;
    u8 *p17;
    u8 *tmp16;
    f32 inv;
    s32 k;
    {
        s32 w = *(s32 *)(arg0 + 4);
        parent[0] = fGpffff81f4 * (f32)(w & 0xFF);
        parent[1] = fGpffff81f4 * (f32)((w >> 8) & 0xFF);
        parent[2] = fGpffff81f4 * (f32)((w >> 16) & 0xFF);
        parent[3] = fGpffff81f4 * (f32)((w >> 24) & 0xFF);
    }
    tmp4 = *(u8 **)(arg0 + 0x58);
    cnt = *(s32 *)(tmp4 + 8);
    if (cnt == 0 || *(s32 *)(tmp4 + 0x10) == 0) {
        return;
    }
    p18 = *(u8 **)(tmp4 + 0x18);
    p17 = *(u8 **)(arg0 + 0x5C);
    tmp16 = *(u8 **)(arg0 + 0x54);
    {
        f32 v = *(f32 *)(arg0 + 8);
        if (v == 0.0f) {
            inv = 1.0f;
        } else {
            inv = 1.0f / v;
        }
    }
    if (*(u16 *)(arg0 + 0x0C) != 3) {
        func_0046d730(D_00714520, 0x2A2);
    } else if ((*(s32 *)(tmp4 + 0x0C) & 1) == 0) {
        s32 i;
        f32 half = 0.5f;
        func_00492df0(tmp4, snapA);
        func_004bceb0();
        for (i = 0; i < 12; i++) {
            base[i] = snap[i];
        }
        k = 0;
        while (k < cnt) {
            if (*(s32 *)(p18 + 0x10) >= 0) {
                s32 cw = *(s32 *)(p18 + 0x14);
                u32 packed;
                f32 f;
                f32 cscale = fGpffff81f4;
                if (*(s8 *)(p17 + 0x14) >= 0) {
                    func_004ae2f0(arg0, p17, *(s32 *)(p18 + 0x10));
                }
                __asm__ volatile(
                    "lw $2, 0(%0)          \n"
                    "pextlb $2, $0, $2     \n"
                    "pextlh $2, $0, $2     \n"
                    "qmtc2.ni $2, $vf10    \n"
                    "vitof0.xyzw $vf10, $vf10 \n"
                    "mfc1 $2, %1           \n"
                    "nop                   \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "lqc2 $vf11, 0(%2)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0(%3)          \n"
                    :
                    : "r"(&cw), "f"(cscale), "r"(parent), "r"(&packed)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                func_003bff30(tmp16, func_004ae020, &packed);
                {
                    f32 idf = (f32)*(s32 *)(p18 + 0x10);
                    f = *(f32 *)(p17 + 0x10) * idf + half * (idf * (*(f32 *)(arg0 + 0x2C) * idf));
                }
                if (f < 0.0f) {
                    matA[0] = 1.0f;
                    matA[1] = 0.0f;
                    matA[2] = 0.0f;
                    matA[3] = 0.0f;
                    matA[4] = 0.0f;
                    matA[5] = 1.0f;
                    matA[6] = 0.0f;
                    matA[7] = 0.0f;
                    matA[8] = 0.0f;
                    matA[9] = 0.0f;
                    matA[10] = 1.0f;
                    matA[11] = 0.0f;
                    matA[12] = 0.0f;
                    matA[13] = 0.0f;
                    matA[14] = 0.0f;
                    matA[15] = 0.0f;
                    *(s32 *)&matA[3] |= 0x20003;
                } else {
                    axis[0] = *(f32 *)(p17 + 0);
                    axis[1] = *(f32 *)(p17 + 4);
                    axis[2] = *(f32 *)(p17 + 8);
                    func_003e0870(matA, axis, 0, fGpffff8048 * (f + *(f32 *)(p17 + 0x0C)));
                }
                func_003e05f0(matB, matA, base);
                if (*(u16 *)(arg0 + 0x30) == 0) {
                    f32 s = *(f32 *)(p18 + 0x18);
                    scale[0] = *(f32 *)D_00713D20 * s;
                    scale[1] = *(f32 *)D_00713D24 * s;
                    scale[2] = *(f32 *)D_00713D28 * s;
                } else {
                    f32 s = *(f32 *)(p18 + 0x18) * inv;
                    scale[0] = *(f32 *)D_00713D20 * s;
                    scale[1] = *(f32 *)D_00713D24 * s;
                    scale[2] = *(f32 *)D_00713D28 * s;
                }
                func_003e0a90(matB, scale, 2);
                pos[0] = *(f32 *)(p18 + 0);
                pos[1] = *(f32 *)(p18 + 4);
                pos[2] = *(f32 *)(p18 + 8);
                func_003e0c90(matB, pos, 2);
                func_003e9cb0(*(void **)(tmp16 + 4), matB, 0);
                func_003bfe90(tmp16);
            }
            k++;
            p18 += 0x20;
            p17 += 0x18;
        }
    } else {
        f32 half = 0.5f;
        f32 zero = 0.0f;
        f32 full = 255.0f;
        s32 mask = 0x20003;
        f32 gscale = fGpffff8048;
        s32 i;
        func_00492df0(tmp4, snapA);
        func_00492db0(*(u8 **)(arg0 + 0x58), snapB);
        func_004bceb0();
        for (i = 0; i < 12; i++) {
            base[i] = snap[i];
        }
        k = 0;
        while (k < cnt) {
            if (*(s32 *)(p18 + 0x10) >= 0) {
                s32 cw = *(s32 *)(p18 + 0x14);
                u32 packed;
                f32 f;
                {
                    f32 px = *(f32 *)(p18 + 0);
                    f32 py = *(f32 *)(p18 + 4);
                    f32 pz = *(f32 *)(p18 + 8);
                    f32 pw = *(f32 *)(p18 + 0x0C);
                    f32 rx = base[0] * px + base[4] * py + base[8] * pz + base[12] * pw;
                    f32 ry = base[1] * px + base[5] * py + base[9] * pz + base[13] * pw;
                    f32 rz = base[2] * px + base[6] * py + base[10] * pz + base[14] * pw;
                    pos[0] = rx;
                    pos[1] = ry;
                    pos[2] = rz;
                }
                {
                    f32 cscale = fGpffff81f4;
                    if (*(s8 *)(p17 + 0x14) >= 0) {
                        func_004ae2f0(arg0, p17, *(s32 *)(p18 + 0x10));
                    }
                    __asm__ volatile(
                        "lw $2, 0(%0)          \n"
                        "pextlb $2, $0, $2     \n"
                        "pextlh $2, $0, $2     \n"
                        "qmtc2.ni $2, $vf10    \n"
                        "vitof0.xyzw $vf10, $vf10 \n"
                        "mfc1 $2, %1           \n"
                        "nop                   \n"
                        "qmtc2.ni $2, $vf2     \n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                        "lqc2 $vf11, 0(%2)     \n"
                        "vmul.xyzw $vf10, $vf10, $vf11 \n"
                        "mfc1 $2, %3           \n"
                        "nop                   \n"
                        "qmtc2.ni $2, $vf2     \n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                        "vftoi0.xyzw $vf10, $vf10 \n"
                        "qmfc2.ni $2, $vf10    \n"
                        "ppach $2, $0, $2      \n"
                        "ppacb $2, $0, $2      \n"
                        "sw $2, 0(%4)          \n"
                        :
                        : "r"(&cw), "f"(cscale), "r"(parent), "f"(full), "r"(&packed)
                        : "$2", "$vf2", "$vf10", "$vf11", "memory");
                }
                func_003bff30(tmp16, func_004ae020, &packed);
                {
                    f32 idf = (f32)*(s32 *)(p18 + 0x10);
                    f = *(f32 *)(p17 + 0x10) * idf + half * (idf * (*(f32 *)(arg0 + 0x2C) * idf));
                }
                if (f < zero) {
                    matB[0] = 1.0f;
                    matB[1] = zero;
                    matB[2] = zero;
                    matB[3] = zero;
                    matB[4] = zero;
                    matB[5] = 1.0f;
                    matB[6] = zero;
                    matB[7] = zero;
                    matB[8] = zero;
                    matB[9] = zero;
                    matB[10] = 1.0f;
                    matB[11] = zero;
                    matB[12] = zero;
                    matB[13] = zero;
                    matB[14] = zero;
                    matB[15] = zero;
                    *(s32 *)&matB[3] |= mask;
                } else {
                    axis[0] = *(f32 *)(p17 + 0);
                    axis[1] = *(f32 *)(p17 + 4);
                    axis[2] = *(f32 *)(p17 + 8);
                    func_003e0870(matB, axis, 0, gscale * (f + *(f32 *)(p17 + 0x0C)));
                }
                if (*(u16 *)(arg0 + 0x30) == 0) {
                    f32 s = *(f32 *)(p18 + 0x18);
                    scale[0] = *(f32 *)D_00713D20 * s;
                    scale[1] = *(f32 *)D_00713D24 * s;
                    scale[2] = *(f32 *)D_00713D28 * s;
                } else {
                    f32 s = *(f32 *)(p18 + 0x18) * inv;
                    scale[0] = *(f32 *)D_00713D20 * s;
                    scale[1] = *(f32 *)D_00713D24 * s;
                    scale[2] = *(f32 *)D_00713D28 * s;
                }
                func_003e0a90(matB, scale, 2);
                func_003e0c90(matB, pos, 2);
                func_003e9cb0(*(void **)(tmp16 + 4), matB, 0);
                func_003bfe90(tmp16);
            }
            k++;
            p18 += 0x20;
            p17 += 0x18;
        }
    }
    func_004813f0();
}

#else
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aed70);
#endif
