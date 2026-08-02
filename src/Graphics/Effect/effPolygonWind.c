#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonWind.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

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
extern void func_004a4450(void *, void *);
extern s32 func_00484010(void *);
extern void func_003c2290(void *, s32);
extern void func_0043f810(void *, void *, void *);
extern char D_00713330[];
extern char D_00714148[];
extern u_long128 D_00713CE0;

extern void *func_004844d0(void);
extern void *func_00484490(void *);
extern void func_0046d730(void *, s32);
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

// FUN_004A2310
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a2310);

// FUN_004A2C90
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a2c90);

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

/* measured: retail coalesces the doubling `or` result into the FIRST
   operand's register (`or $t3,$t3,$t2; mtc1 $t3,$f0`) while mwcc b210 always
   coalesces it into the SECOND operand's (`or $t2,$t3,$t2; mtc1 $t2,$f0`),
   at both doubling sites (4 words, nd 5). Tried: operand order swap (worse,
   nd 9, order flips), named locals for the whole expr / first operand /
   second operand / both operands, and a static inline `a|b` helper — all
   emit the identical second-operand coalescing. Register-coalescing floor. */
// FUN_004A30E0
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

// FUN_004A3640
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3640);

// FUN_004A4000
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4000);

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

// FUN_004A4450
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

// FUN_004A4A10
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4a10);

// FUN_004A52B0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a52b0);

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
    func_0043f810(*(void **)(p18 + 0x40), arg1, (void *)temp_17);
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
