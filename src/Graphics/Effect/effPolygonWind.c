#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonWind.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));

/* 4-byte color state at 0x00724C54..57, accessed gp-relative in retail. */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;

extern PolygonWindColor iGpffffbb64; /* 0x00724C54 */
extern void func_0044ea90(char *, s32);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *func_00483e10(u16, u16, void *, s32, s32);
extern s32 func_00481300(s32);
extern void func_004842d0(void *, s32);
extern void func_004843f0(void *, s32);
extern void func_004a1d70(void *, void *);
extern void func_004a30e0(u8 *, u8 *);
extern void func_004a4450(u8 *, u8 *);
extern s32 func_00484010(void *);
extern u8 *func_003c2290(u8 *, s32);
extern void func_0043f810(void *, const void *, u32);
extern char D_00713330[];
extern char D_00714148[];
extern u_long128 D_00713CE0;

extern void *func_004844d0(void);
extern void *func_00484490(void *);
extern void func_0046d730(void *, s32);
extern s32 func_0048abd0(u8 *, u8 *, s32, s32);
extern void func_004843a0();
extern void func_00484280();
extern f32 func_004bd0b0(u32);
extern u32 func_004bd050(u32);
extern void func_0043f9c8(void *, s32, s32);
extern void func_004bd1a0(u32, f32);
extern void func_004bd3c0(f32);
extern void func_004bd450(void);
extern f32 func_0044b610(f32);
extern f32 func_0044b7b0(f32);
extern void func_003c22f0(void *);
extern f32 D_00713D10[4];
extern f32 D_00713D14[4];
extern f32 D_00713D18[4];
extern f32 iGpffff8084; /* 0x00761174 */
extern f32 fGpffff8044; /* 0x00761134 */
extern f32 iGpffff8080; /* 0x00761170 */
extern void *func_004a5630(s32, void *);
extern char D_00714134[];
extern char D_00714130[];
extern char D_00714110[];

// FUN_004A20B0
u8 *func_004a20b0(u8 *arg0, s32 arg1)
{
    u8 *work;
    s32 size;

    size = *(s32 *)(arg0 + 0x38) * 0x30 + 0xC;
    func_0044ea90(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x53);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(arg0 + 0x8C) < 3U) {
        *(u32 *)(arg0 + 0x8C) = 3U;
    }
    *(void **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), D_00713330, 4, 0x4C);
    if (arg1 == 0) {
        func_004842d0(*(void **)(work + 4), func_00481300(0x14));
    } else {
        func_004843f0(*(void **)(work + 4), arg1);
    }
    func_004a1d70(work, arg0);
    return work;
}

// FUN_004A21E0
u8 *func_004a21e0(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u8 *work;
    s32 size;

    p16 = *(u8 **)(arg0 + 0x3C);
    p17 = *(u8 **)(arg0 + 0x40);
    size = *(s32 *)(p17 + 0x38) * 0x30 + 0xC;
    func_0044ea90(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x53);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(p17 + 0x8C) < 3U) {
        *(u32 *)(p17 + 0x8C) = 3U;
    }
    *(s32 *)(work + 4) = func_00484010(*(void **)(p16 + 4));
    func_004a1d70(work, p17);
    return work;
}

/* measured: same s128-canonicalization floor family as func_004A4A10 in
   this file (and the floored effPolygonFlash FUN_0049AA30 family): retail
   `sq $3,0x120($29)` (3A2390) stores a 32-bit value into a 16-byte slot
   with a bare sq, and the loop re-reads the slots with bare lq + sltu;
   mwcc b210 always inserts the dsll32/dsra32 pair on both sides
   (probe-verified on this toolchain, 5 spellings - no bare sq is
   reachable). Not attempted separately: the identical mechanism is
   measured in func_004A4A10 (nd 1927 attempt) and the floor is provable
   at the toolchain level. */
// FUN_004A2310
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a2310);

// FUN_004A2C90
void func_004a2c90(u8 *arg0)
{
    union {
        s32 w;
        u8 b[4];
    } spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 temp_3_2;
    u8 *temp_3;
    u32 *var_19;
    u8 *temp_18;
    u32 var_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;
    u32 temp_23;
    u32 temp_21;
    u32 temp_6_2;
    u32 combined;
    f32 scale;

    temp_3 = *(u8 **)(arg0 + 0x3C);
    temp_18 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_3 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_18 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0)) {
        s32 *pt;

        var_19 = *(u32 **)temp_3;
        temp_3_2 = func_0048abd0(temp_18, temp_18 + 0x24, temp_6, temp_7);
        spA8 = *(s32 *)(arg0 + 0x30);
        pt = &spA8;
        scale = fGpffff8044;
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
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        spA4 = temp_3_2;
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
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0xA0($sp)      \n"
            :
            : "r"(&spA4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&spA0;
        temp_23 = *(u32 *)(temp_18 + 0x38);
        temp_21 = *(u32 *)(temp_18 + 0x80);
        var_17 = 0;
        while (var_17 < temp_23) {
            temp_6_2 = *var_19;
            if (temp_6_2 < temp_21) {
                sp9C = func_0048abd0(temp_18 + 0x3C, temp_18 + 0x60, temp_6_2, temp_21);
                scale = fGpffff8044;
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
                    "vmove.xyzw $vf11, $vf10 \n"
                    :
                    : "r"(&sp9C), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                sp98 = combined;
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
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0x94($sp)      \n"
                    :
                    : "r"(&sp98), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                spAC.w = *(s32 *)&sp94;
                if (spAC.b[3] != 0xFF) {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                } else {
                    spAC.b[3] = 0xFE;
                    {
                        u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                        *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                    }
                    spAC.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            var_17 += 1;
            var_19 += 0xC;
        }
        func_004843a0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_18 + 0xB9) != 0) {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        } else {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        func_00484280(temp_16, *(u16 *)(temp_18 + 0x28));
    }
}

/* measured: without #pragma opt_loop_invariants on, mwcc rematerializes the
 * 0xFF/0xFE/-1 constants inside the loop instead of hoisting them to the
 * preheader (and hoists the p11 load that retail re-issues per iteration);
 * with it the loop matches retail exactly. */
// FUN_004A3010
#pragma opt_loop_invariants on
void func_004a3010(u8 *arg0)
{
    u8 *p5;
    u8 *p7;
    u32 count;
    u32 i;
    u8 *p11;
    u8 *p13;

    p5 = *(u8 **)(arg0 + 0x3C);
    p7 = *(u8 **)p5;
    count = *(u32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    i = 0;
    while (i < count) {
        p11 = *(u8 **)(p5 + 4);
        if (iGpffffbb64.c3 != 0xFF) {
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)p7 = -1;
        i++;
        p7 += 0x30;
    }
}
#pragma opt_loop_invariants off

/* measured: the reconstructed XWND_004a30e0_body.c candidate is 764B/768B
   at 10 differing words: nine replication-loop register differences and
   one zero tail word. Native unsigned conversions, the four-byte color
   aggregate, and scoped invariant hoisting reproduce both OR/mtc1 sites
   exactly; the old unconditional coalescing-floor claim was false.
   The historically reported nd5 body was not recoverable, so this is a
   reproducible reconstruction, not a lower score than that lost body. */
// FUN_004A30E0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a30e0);

// FUN_004A33E0
u8 *func_004a33e0(u8 *arg0, s32 arg1)
{
    u8 *work;
    s32 size;

    size = *(s32 *)(arg0 + 0x38) * 0x30 + 0xC;
    func_0044ea90(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x213);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(arg0 + 0x8C) < 3U) {
        *(u32 *)(arg0 + 0x8C) = 3U;
    }
    *(void **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), D_00713330, 4, 0x4C);
    if (arg1 == 0) {
        func_004842d0(*(void **)(work + 4), func_00481300(0x14));
    } else {
        func_004843f0(*(void **)(work + 4), arg1);
    }
    func_004a30e0(work, arg0);
    return work;
}

// FUN_004A3510
u8 *func_004a3510(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u8 *work;
    s32 size;

    p16 = *(u8 **)(arg0 + 0x3C);
    p17 = *(u8 **)(arg0 + 0x40);
    size = *(s32 *)(p17 + 0x38) * 0x30 + 0xC;
    func_0044ea90(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x213);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(p17 + 0x8C) < 3U) {
        *(u32 *)(p17 + 0x8C) = 3U;
    }
    *(s32 *)(work + 4) = func_00484010(*(void **)(p16 + 4));
    func_004a30e0(work, p17);
    return work;
}

/* measured: same s128-canonicalization floor family as func_004A4A10 in
   this file (and the floored effPolygonFlash FUN_0049AA30 family): retail
   `sq $3,0x110($29)` (3A36C0) stores a 32-bit value into a 16-byte slot
   with a bare sq and re-reads it with bare lq + sltu; mwcc b210 always
   inserts the dsll32/dsra32 pair on both sides (probe-verified on this
   toolchain, 5 spellings - no bare sq is reachable). Not attempted
   separately: the identical mechanism is measured in func_004A4A10
   (nd 1927 attempt) and the floor is provable at the toolchain level. */
// FUN_004A3640
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3640);

// FUN_004A4000
void func_004a4000(u8 *arg0)
{
    union {
        s32 w;
        u8 b[4];
    } spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 temp_3_2;
    u8 *temp_3;
    u32 *var_19;
    u8 *temp_18;
    u32 var_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;
    u32 temp_23;
    u32 temp_21;
    u32 temp_6_2;
    u32 combined;
    f32 scale;

    temp_3 = *(u8 **)(arg0 + 0x3C);
    temp_18 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_3 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_18 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0)) {
        s32 *pt;

        var_19 = *(u32 **)temp_3;
        temp_3_2 = func_0048abd0(temp_18, temp_18 + 0x24, temp_6, temp_7);
        spA8 = *(s32 *)(arg0 + 0x30);
        pt = &spA8;
        scale = fGpffff8044;
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
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        spA4 = temp_3_2;
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
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0xA0($sp)      \n"
            :
            : "r"(&spA4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&spA0;
        temp_23 = *(u32 *)(temp_18 + 0x38);
        temp_21 = *(u32 *)(temp_18 + 0x80);
        var_17 = 0;
        while (var_17 < temp_23) {
            temp_6_2 = *var_19;
            if (temp_6_2 < temp_21) {
                sp9C = func_0048abd0(temp_18 + 0x3C, temp_18 + 0x60, temp_6_2, temp_21);
                scale = fGpffff8044;
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
                    "vmove.xyzw $vf11, $vf10 \n"
                    :
                    : "r"(&sp9C), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                sp98 = combined;
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
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0x94($sp)      \n"
                    :
                    : "r"(&sp98), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                spAC.w = *(s32 *)&sp94;
                if (spAC.b[3] != 0xFF) {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                } else {
                    spAC.b[3] = 0xFE;
                    {
                        u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                        *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                    }
                    spAC.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            var_17 += 1;
            var_19 += 0xC;
        }
        func_004843a0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_18 + 0xB9) != 0) {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        } else {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        func_00484280(temp_16, *(u16 *)(temp_18 + 0x28));
    }
}

/* measured: same loop-shape as func_004a3010; without #pragma
 * opt_loop_invariants on, mwcc rematerializes the 0xFF/0xFE/-1 constants
 * inside the loop instead of hoisting them to the preheader; with it the
 * loop matches retail exactly (0x2C stride variant). */
// FUN_004A4380
#pragma opt_loop_invariants on
void func_004a4380(u8 *arg0)
{
    u8 *p5;
    u8 *p7;
    u32 count;
    u32 i;
    u8 *p11;
    u8 *p13;

    p5 = *(u8 **)(arg0 + 0x3C);
    p7 = *(u8 **)p5;
    count = *(u32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    i = 0;
    while (i < count) {
        p11 = *(u8 **)(p5 + 4);
        if (iGpffffbb64.c3 != 0xFF) {
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)p7 = -1;
        i++;
        p7 += 0x2C;
    }
}
#pragma opt_loop_invariants off

/* measured: structure converges exactly onto retail's shape (preheader
   hoists, both loops, conversion blocks) but mwcc b210 keeps the
   negative-conversion `or` result in the SECOND operand's register
   (`or $t1,$t2,$t1`) where retail keeps the FIRST (`or $t2,$t2,$t1`) at
   both conversion sites (4 words) — same coalescing floor as
   func_004A30E0 (exhaustively documented there). Also a second floor:
   the 2^31 clamp emits `c.olt.s $f0,$f1; bc1t->else` for every spelling
   tried (const-first, m2c-inverted, +opt_propagation off which was
   worse, nd 94) vs retail's `c.ole.s $f1,$f0; bc1t->then`. Attempts:
   inline u32 cast nd 181 (mwcc recursively re-applies its sign idiom to
   the inner cast), named s32 intermediate nd 161, s32 loop counter
   nd 47 (converged), probe batch best nd 48. */
// FUN_004A4450 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4450);

// FUN_004A4790
u8 *func_004a4790(u8 *arg0, s32 arg1)
{
    u8 *work;
    s32 size;

    size = *(s32 *)(arg0 + 0x38) * 0x2C + 0xC;
    func_0044ea90(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x3E5);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(arg0 + 0x8C) < 3U) {
        *(u32 *)(arg0 + 0x8C) = 3U;
    }
    *(void **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), D_00713330, 4, 0x4C);
    if (arg1 == 0) {
        func_004842d0(*(void **)(work + 4), func_00481300(0x14));
    } else {
        func_004843f0(*(void **)(work + 4), arg1);
    }
    func_004a4450(work, arg0);
    return work;
}

// FUN_004A48D0
u8 *func_004a48d0(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u8 *work;
    s32 size;

    p16 = *(u8 **)(arg0 + 0x3C);
    p17 = *(u8 **)(arg0 + 0x40);
    size = *(s32 *)(p17 + 0x38) * 0x2C + 0xC;
    func_0044ea90(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        func_0046d730(D_00714110, 0x3E5);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(p17 + 0x8C) < 3U) {
        *(u32 *)(p17 + 0x8C) = 3U;
    }
    *(s32 *)(work + 4) = func_00484010(*(void **)(p16 + 4));
    func_004a4450(work, p17);
    return work;
}

/* measured: s128-canonicalization floor family (same code as the floored
   effPolygonFlash FUN_0049AA30/0049C3D0 etc.). retail stores 32-bit values
   into three 16-byte slots with bare `sq` (sp100 at 0x100, spF0, spE0) and
   re-reads them with bare `lq` + sltu/beqz; mwcc b210 always emits a
   dsll32/dsra32 widening pair before the sq (probe-verified here on b210
   with 5 spellings: (u_long128)cast, s128 cast, struct/union alias, u64
   alias, u32-alias write - none produce a bare sq) and another pair after
   every lq that feeds a comparison/zero-test (only the `if (q)` truthiness
   form escapes the read canon). That is a minimum nd 11 (3 write + 2
   compare sites + the one retail paddub for sp110) even with a perfect
   reconstruction. Attempt 1 (full m2c-derived body incl. the VU0 lqc2/
   vmulax/vrsqrt chain asm blocks and the (1.0f-x)+x*r FMA chains) measured
   nd 1927 / obj 2580 vs win 2208: the frame came out 0x130 vs 0x140 and
   the FP saved pool did not fill to retail's 12 registers, so the object
   diverges well before the canon floor dominates. */
// FUN_004A4A10
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4a10);

// FUN_004A52B0
void func_004a52b0(u8 *arg0)
{
    union {
        s32 w;
        u8 b[4];
    } spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 temp_3_2;
    u8 *temp_3;
    u32 *var_19;
    u8 *temp_18;
    u32 var_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;
    u32 temp_23;
    u32 temp_21;
    u32 temp_6_2;
    u32 combined;
    f32 scale;

    temp_3 = *(u8 **)(arg0 + 0x3C);
    temp_18 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_3 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_18 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0)) {
        s32 *pt;

        var_19 = *(u32 **)temp_3;
        temp_3_2 = func_0048abd0(temp_18, temp_18 + 0x24, temp_6, temp_7);
        spA8 = *(s32 *)(arg0 + 0x30);
        pt = &spA8;
        scale = fGpffff8044;
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
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        spA4 = temp_3_2;
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
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0xA0($sp)      \n"
            :
            : "r"(&spA4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&spA0;
        temp_23 = *(u32 *)(temp_18 + 0x38);
        temp_21 = *(u32 *)(temp_18 + 0x80);
        var_17 = 0;
        while (var_17 < temp_23) {
            temp_6_2 = *var_19;
            if (temp_6_2 < temp_21) {
                sp9C = func_0048abd0(temp_18 + 0x3C, temp_18 + 0x60, temp_6_2, temp_21);
                scale = fGpffff8044;
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
                    "vmove.xyzw $vf11, $vf10 \n"
                    :
                    : "r"(&sp9C), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                sp98 = combined;
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
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0x94($sp)      \n"
                    :
                    : "r"(&sp98), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                spAC.w = *(s32 *)&sp94;
                if (spAC.b[3] != 0xFF) {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                } else {
                    spAC.b[3] = 0xFE;
                    {
                        u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                        *(PolygonWindColor *)(dst + 4) = *(PolygonWindColor *)&spAC;
                    }
                    spAC.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = *(u8 **)(*(u8 **)(temp_16 + 0x54) + (var_17 & 0xFFFF) * 4);
                    *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            var_17 += 1;
            var_19 += 0xB;
        }
        func_004843a0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_18 + 0xB9) != 0) {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        } else {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        func_00484280(temp_16, *(u16 *)(temp_18 + 0x28));
    }
}

/* measured: same loop-shape as func_004a3010; without #pragma
 * opt_loop_invariants on, mwcc rematerializes the 0xFF/0xFE/-1 constants
 * inside the loop instead of hoisting them to the preheader; with it the
 * loop matches retail exactly (0x2C stride variant). */

// FUN_004A5630
#pragma opt_propagation off
void *func_004a5630(s32 arg0, void *arg1)
{
    u8 *p18;
    u_long128 *dst128;
    s32 temp_16;
    s32 temp_17;

    if ((u16)arg0 >= 4) {
        func_0046d730(D_00714110, 0x59F);
    }
    temp_16 = arg0 & 0xFFFF;
    temp_17 = *(s32 *)(D_00714148 + temp_16 * 0x1C);
    func_0044ea90(D_00714110, 0x5A3);
    p18 = jtbl_008873E8[0](temp_17 + 0x50, 0x40000);
    if (p18 == NULL) {
        func_0046d730(D_00714110, 0x5A4);
    }
    *(u32 *)(p18 + 0x40) = (u32)(p18 + 0x50);
    *(u32 *)(p18 + 0x34) = 0;
    *(u32 *)(p18 + 0x38) = (u32)temp_16;
    *(u32 *)(p18 + 0x30) = -1;
    dst128 = &D_00713CE0;
    *(u_long128 *)(p18 + 0x20) = *dst128;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(p18) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(p18) : "memory");
    func_0043f810(*(void **)(p18 + 0x40), arg1, (u32)temp_17);
    return p18;
}
#pragma opt_propagation on

// FUN_004A5750
void *func_004a5750(u8 *arg0)
{
    u8 *p16;
    u8 *p19;
    u8 *p18;
    u8 *p17;
    u32 idx;

    p18 = func_004844d0();
    if (p18 == NULL) {
        func_0046d730(D_00714110, 0x5D5);
    }
    switch (*(u16 *)(arg0 + 0x1C)) {
    case 1:
        break;
    case 4:
        p18 = NULL;
        break;
    default:
        func_0046d730(D_00714110, 0x5DE);
        break;
    }
    p19 = func_00484490(arg0);
    if (p19 == NULL) {
        func_0046d730(D_00714110, 0x5E3);
    }
    p16 = (u8 *)(*(u16 *)(arg0 + 0xC) & 0xFFFF);
    p17 = func_004a5630((s32)p16, p19);
    idx = ((u32)p16 & 0xFFFF) * 28;
    *(u32 *)(p17 + 0x3C) = (u32)((void *(*)(void *, void *))(*(void **)(D_00714134 + idx)))(p19, p18);
    ((void (*)(void *))(*(void **)(D_00714130 + idx)))(p17);
    if (p17 == NULL) {
        func_0046d730(D_00714110, 0x5E5);
    }
    return p17;
}
