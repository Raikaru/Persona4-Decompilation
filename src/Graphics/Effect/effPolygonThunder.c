/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonThunder.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

/* FUN_004833F0 is a texture release helper shared by the eff* units. */
extern void func_004833f0(void *arg0);
extern u32 func_004bd050(u32 arg0);
extern f32 func_004bd0b0(u32 arg0);
extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern u8 *func_00484490(u8 *obj);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *);
extern char D_00713E50[];
extern u32 D_00713E70[];
extern u32 D_00713E74[];
extern u32 D_00713E84[];
/* iGpffff8044 is an anonymous gp-relative slot in retail (-0x7FBC($28)), not a
   defined link symbol; the VU0 funcs load it via C so the verifier masks the
   GPREL16 reloc. */
extern f32 iGpffff8044;
extern u32 D_00713360[];
extern void *func_00482dc0(u16 arg0, void *arg1, s32 arg2, s32 arg3);

/* 4-byte color, copied field-by-field by retail. */
typedef struct
{
    u8 c[4];
} Color4;
extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
extern void func_00483700(void *dst, void *obj, void *src, f32 arg3);
extern void func_003e9cb0(void *a, void *b, s32 c);
extern void func_00483490(void *a, u16 b);
u8 *func_004988c0(u16 arg0, u8 *arg1);


/* measured: fresh simple-cast (not inherited). Transferable lever: write `(f32)(u32)x` and let b210 emit the bltz/srl/andi/or/mtc1/cvt/add.s block itself; hand-written halving/doubling emits ten extra copies (opclass mtc1+12/cvt+10/srl+10/andi+10/or+10/add.s+10/b+10/bltz+10). Fade-signed/color-unsigned. */
// FUN_00495160 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00495160(u8 *arg0)
{
    u_long128 spD0;
    u_long128 spC0;
    u_long128 spB0;
    u_long128 spA0;
    u8 *alloc;
    u8 *innerBase;
    u32 outerCount;
    u32 outerIdx;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 b0;
    u32 b1;
    u32 b2;
    s32 first;
    f32 f1;
    u8 *p;
    s32 innerCount;
    u8 *dst;
    u32 innerIdx;
    s32 second;
    s32 tmp7;
    f32 f0;
    f32 fade;
    u32 iv;

    outerCount = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713E50, 0x50);
    alloc = (*jtbl_008873E8)(outerCount * 0x10 + 4, 0x40000);
    if (alloc == 0) {
        func_0046d730(D_00713E50, 0x51);
    }
    *(u8 **)(alloc + 0) = alloc + 4;
    if (*(u32 *)(arg0 + 0x3C) < 3) {
        *(u32 *)(arg0 + 0x3C) = 3;
    }
    c0 = *(u32 *)(arg0 + 0x70);
    spD0 = (u_long128)(c0 & 0xFFFFFF);
    c1 = *(u32 *)(arg0 + 0x74);
    spC0 = (u_long128)(c1 & 0xFFFFFF);
    c2 = *(u32 *)(arg0 + 0x78);
    spB0 = (u_long128)(c2 & 0xFFFFFF);
    b0 = c0 >> 24;
    b1 = c1 >> 24;
    b2 = c2 >> 24;
    innerBase = *(u8 **)alloc;
    f1 = (f32)(*(s32 *)(arg0 + 0x3C) + 1);
    first = (s32)(*(f32 *)(arg0 + 0x68) * f1);
    second = (s32)(*(f32 *)(arg0 + 0x6C) * f1);
    spA0 = (u_long128)second;
    outerIdx = 0;
    while (outerIdx < outerCount) {
        p = func_00482dc0(*(u16 *)(arg0 + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)innerBase = p;
        innerCount = *(s16 *)(p + 8) / 5;
        dst = *(u8 **)(*(u8 **)(*(u8 **)(p + 0x10) + 0x18) + 0x30);
        innerIdx = 0;
        second = (s32)spA0;
        tmp7 = innerCount - second;
        while (innerIdx < (u32)innerCount) {
            if (innerIdx < (u32)first) {
                f0 = (f32)innerIdx;
                fade = f0 / (f32)first;
            } else if ((u32)second < innerIdx) {
                s32 d1 = innerCount - (s32)innerIdx;
                f32 v1 = (f32)d1;
                f32 v0 = (f32)tmp7;
                fade = v1 / v0;
            } else {
                fade = 1.0f;
            }
            f0 = (f32)b2 * fade;
            iv = (u32)f0;
            *(u32 *)dst = (u32)spB0 | ((u32)iv << 24);
            f0 = (f32)b1 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 4) = (u32)spC0 | ((u32)iv << 24);
            f0 = (f32)b0 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 8) = (u32)spD0 | ((u32)iv << 24);
            dst[12] = dst[4];
            dst[13] = dst[5];
            dst[14] = dst[6];
            dst[15] = dst[7];
            dst[16] = dst[0];
            dst[17] = dst[1];
            dst[18] = dst[2];
            dst[19] = dst[3];
            innerIdx += 1;
            dst += 0x14;
        }
        *(s32 *)(innerBase + 4) = -1 - (s32)(outerIdx * 4);
        *(s32 *)(innerBase + 0xC) = 0;
        outerIdx += 1;
        innerBase += 0x10;
    }
    return alloc;
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00495160);
#endif


// FUN_00495620
void func_00495620(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 4;
    }
    jtbl_008873EC[0](obj);
}


/* measured: retail contains COP2/VU0 normalize and cross-product work; H009
   permits inline asm for those instructions. Any FPU MAC remains plain C; no
   byte-exact candidate was retained in this wave. */
// FUN_004956B0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004956b0);


// FUN_00495F80
void func_00495f80(u8 *arg0)
{
    u8 *obj;
    u8 *ctrl;
    u8 *list;
    s32 n;
    s32 count;
    u8 spDCb[4];
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spB0[4];
    s32 tmp;
    f32 scale;
    s32 i;
    u8 *e0;
    u8 *dst;
    f32 sp70[16];

    obj = *(u8 **)(arg0 + 0x30);
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **)obj;
    n = *(s32 *)(arg0 + 0x28);
    count = *(s32 *)(ctrl + 0x34);
    if ((count >= n) || (count == 0))
    {
        s32 *pt;

        count = *(s32 *)(ctrl + 0x38);
        tmp = (s32)func_0048abd0(ctrl, ctrl + 0x24, n, *(s32 *)(ctrl + 0x34));
        spD8 = *(s32 *)(arg0 + 0x24);
        pt = &spD8;
        scale = iGpffff8044;
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
        spD4 = tmp;
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
            :
            : "r"(&spD4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spB0) : "memory");
        func_00483700(&sp70[0], arg0, 0, *(f32 *)(arg0 + 0x20));
        i = 0;
        while (i < count)
        {
            if (*(s32 *)(list + 4) > 0)
            {
                e0 = *(u8 **)list;
                func_003e9cb0(*(void **)(e0 + 0xC), &sp70[0], 0);
                spD0 = *(s32 *)(list + 8);
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
                    :
                    : "r"(&spD0), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(spB0)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the spCC reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)spDCb = *(volatile s32 *)&spCC;
                if (spDCb[3] != 0xFF)
                {
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                }
                else
                {
                    spDCb[3] = 0xFE;
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                    spDCb[3] = 0xFF;
                }
                if (*(u8 *)(ctrl + 0x5C) != 0)
                {
                    *(u16 *)e0 = *(u16 *)e0 | 1;
                }
                else
                {
                    *(u16 *)e0 = *(u16 *)e0 & 0xFFFE;
                }
                {
                    s32 b = *(u16 *)(ctrl + 0x28);
                    func_00483490(e0, b);
                }
            }
            i++;
            list += 0x10;
        }
    }
}



// FUN_004961F0
void func_004961f0(u8 *arg0)
{
    u8 *obj0;
    u8 *obj1;
    u32 *p;
    s32 count;
    f32 a;
    f32 v;
    u32 i;

    obj0 = *(u8 **)(arg0 + 0x30);
    obj1 = *(u8 **)(arg0 + 0x34);
    p = *(u32 **)obj0;
    count = *(s32 *)(obj1 + 0x34);
    a = *(f32 *)(obj1 + 0x90);
    v = *(f32 *)(obj1 + 0x8C) * (a * func_004bd0b0(0) + (1.0f - a));
    if (count > 0)
    {
        f32 b = *(f32 *)(obj1 + 0x98);
        f32 w = *(f32 *)(obj1 + 0x94) * (b * func_004bd0b0(0) + (1.0f - b));
        *(f32 *)(obj0 + 4) = v;
        *(f32 *)(obj0 + 8) = (w - v) / (f32)count;
    }
    else
    {
        *(f32 *)(obj0 + 4) = v;
        *(f32 *)(obj0 + 8) = 0.0f;
    }
    count = *(s32 *)(obj1 + 0x38);
    i = 0;
    while (i < (u32)count)
    {
        p[5] = -1 - (func_004bd050(0) & 7);
        i++;
        p += 0xC;
    }
}


/* measured: fresh simple-cast ported from 495160 fade-signed/color-unsigned. Transferable lever: write `(f32)(u32)x` and let b210 emit block itself. Base 1192/1232 fails gate by 3B; with opt_propagation off 1212/1232 passes. */
// FUN_00496340 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
u8 *func_00496340(u8 *arg0)
{
    u_long128 spD0;
    u_long128 spC0;
    u_long128 spB0;
    u_long128 spA0;
    u8 *alloc;
    u8 *innerBase;
    u32 outerCount;
    u32 outerIdx;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 b0;
    u32 b1;
    u32 b2;
    s32 first;
    f32 f1;
    u8 *p;
    s32 innerCount;
    u8 *dst;
    u32 innerIdx;
    s32 second;
    s32 tmp7;
    f32 f0;
    f32 fade;
    u32 iv;

    outerCount = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713E50, 0x2B5);
    alloc = (*jtbl_008873E8)(outerCount * 0x30 + 0x10, 0x40000);
    if (alloc == 0) {
        func_0046d730(D_00713E50, 0x2B6);
    }
    *(u8 **)(alloc + 0) = alloc + 0x10;
    *(u8 **)(alloc + 0x0C) = alloc;
    if (*(u32 *)(arg0 + 0x3C) < 3) {
        *(u32 *)(arg0 + 0x3C) = 3;
    }
    c0 = *(u32 *)(arg0 + 0x70);
    spD0 = (u_long128)(c0 & 0xFFFFFF);
    c1 = *(u32 *)(arg0 + 0x74);
    spC0 = (u_long128)(c1 & 0xFFFFFF);
    c2 = *(u32 *)(arg0 + 0x78);
    spB0 = (u_long128)(c2 & 0xFFFFFF);
    b0 = c0 >> 24;
    b1 = c1 >> 24;
    b2 = c2 >> 24;
    innerBase = *(u8 **)alloc;
    f1 = (f32)(*(s32 *)(arg0 + 0x3C) + 1);
    first = (s32)(*(f32 *)(arg0 + 0x68) * f1);
    second = (s32)(*(f32 *)(arg0 + 0x6C) * f1);
    spA0 = (u_long128)second;
    outerIdx = 0;
    while (outerIdx < outerCount) {
        p = func_00482dc0(*(u16 *)(arg0 + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)innerBase = p;
        innerCount = *(s16 *)(p + 8) / 5;
        dst = *(u8 **)(*(u8 **)(*(u8 **)(p + 0x10) + 0x18) + 0x30);
        innerIdx = 0;
        second = (s32)spA0;
        tmp7 = innerCount - second;
        while (innerIdx < (u32)innerCount) {
            if (innerIdx < (u32)first) {
                f0 = (f32)innerIdx;
                fade = f0 / (f32)first;
            } else if ((u32)second < innerIdx) {
                s32 d1 = innerCount - (s32)innerIdx;
                f32 v1 = (f32)d1;
                f32 v0 = (f32)tmp7;
                fade = v1 / v0;
            } else {
                fade = 1.0f;
            }
            f0 = (f32)b2 * fade;
            iv = (u32)f0;
            *(u32 *)dst = (u32)spB0 | ((u32)iv << 24);
            f0 = (f32)b1 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 4) = (u32)spC0 | ((u32)iv << 24);
            f0 = (f32)b0 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 8) = (u32)spD0 | ((u32)iv << 24);
            dst[12] = dst[4];
            dst[13] = dst[5];
            dst[14] = dst[6];
            dst[15] = dst[7];
            dst[16] = dst[0];
            dst[17] = dst[1];
            dst[18] = dst[2];
            dst[19] = dst[3];
            innerIdx += 1;
            dst += 0x14;
        }
        *(s32 *)(innerBase + 0x14) = -1 - (s32)(outerIdx * 4);
        outerIdx += 1;
        innerBase += 0x30;
    }
    return alloc;
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00496340);
#endif


// FUN_00496810
void func_00496810(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 0xC;
    }
    jtbl_008873EC[0](*(void **)(obj + 0xC));
}


/* measured: retail contains COP2/VU0 normalize, cross-product, and matrix work;
   H009 permits inline asm. The FPU setup remains plain C; no byte-exact body
   was retained in this wave. */
// FUN_004968A0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004968a0);


// FUN_00497460
void func_00497460(u8 *arg0)
{
    u8 *obj;
    u8 *ctrl;
    u8 *list;
    s32 n;
    s32 count;
    u8 spDCb[4];
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spB0[4];
    s32 tmp;
    f32 scale;
    s32 i;
    u8 *e0;
    u8 *dst;
    f32 sp70[16];

    obj = *(u8 **)(arg0 + 0x30);
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **)obj;
    n = *(s32 *)(arg0 + 0x28);
    count = *(s32 *)(ctrl + 0x34);
    if ((count >= n) || (count == 0))
    {
        s32 *pt;

        count = *(s32 *)(ctrl + 0x38);
        tmp = (s32)func_0048abd0(ctrl, ctrl + 0x24, n, *(s32 *)(ctrl + 0x34));
        spD8 = *(s32 *)(arg0 + 0x24);
        pt = &spD8;
        scale = iGpffff8044;
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
        spD4 = tmp;
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
            :
            : "r"(&spD4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spB0) : "memory");
        func_00483700(&sp70[0], arg0, arg0 + 0x10, *(f32 *)(arg0 + 0x20));
        i = 0;
        while (i < count)
        {
            if (*(s32 *)(list + 0x14) > 0)
            {
                e0 = *(u8 **)list;
                func_003e9cb0(*(void **)(e0 + 0xC), &sp70[0], 0);
                spD0 = *(s32 *)(list + 0x18);
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
                    :
                    : "r"(&spD0), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(spB0)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the spCC reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)spDCb = *(volatile s32 *)&spCC;
                if (spDCb[3] != 0xFF)
                {
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                }
                else
                {
                    spDCb[3] = 0xFE;
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                    spDCb[3] = 0xFF;
                }
                if (*(u8 *)(ctrl + 0x5C) != 0)
                {
                    *(u16 *)e0 = *(u16 *)e0 | 1;
                }
                else
                {
                    *(u16 *)e0 = *(u16 *)e0 & 0xFFFE;
                }
                {
                    s32 b = *(u16 *)(ctrl + 0x28);
                    func_00483490(e0, b);
                }
            }
            i++;
            list += 0x30;
        }
    }
}



// FUN_004976D0
void func_004976d0(u8 *arg0)
{
    u32 *p;
    u32 count;
    u32 i;

    p = **(u32 ***)(arg0 + 0x30);
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        p[1] = -1 - (func_004bd050(0) & 3);
        i++;
        p += 3;
    }
}


/* measured: fresh simple-cast ported from 495160 with 0x499/0x49A, *0x0C+4, odd-ensure, stride 0x0C, tail +4 single. Transferable lever: write `(f32)(u32)x` and let b210 emit block itself. SU 1216 fail vs UU-fixed 1308/1280 passes. */
// FUN_00497750 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00497750(u8 *arg0)
{
    u_long128 spD0;
    u_long128 spC0;
    u_long128 spB0;
    u_long128 spA0;
    u8 *alloc;
    u8 *innerBase;
    u32 outerCount;
    u32 outerIdx;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 b0;
    u32 b1;
    u32 b2;
    s32 first;
    f32 f1;
    u8 *p;
    s32 innerCount;
    u8 *dst;
    u32 innerIdx;
    s32 second;
    s32 tmp7;
    f32 f0;
    f32 fade;
    u32 iv;

    outerCount = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713E50, 0x499);
    alloc = (*jtbl_008873E8)(outerCount * 0x0C + 4, 0x40000);
    if (alloc == 0) {
        func_0046d730(D_00713E50, 0x49A);
    }
    *(u8 **)(alloc + 0) = alloc + 4;
    if (*(u32 *)(arg0 + 0x3C) < 3) {
        *(u32 *)(arg0 + 0x3C) = 3;
    }
    if ((*(u32 *)(arg0 + 0x3C) & 1) == 0) {
        *(u32 *)(arg0 + 0x3C) += 1;
    }
    c0 = *(u32 *)(arg0 + 0x70);
    spD0 = (u_long128)(c0 & 0xFFFFFF);
    c1 = *(u32 *)(arg0 + 0x74);
    spC0 = (u_long128)(c1 & 0xFFFFFF);
    c2 = *(u32 *)(arg0 + 0x78);
    spB0 = (u_long128)(c2 & 0xFFFFFF);
    b0 = c0 >> 24;
    b1 = c1 >> 24;
    b2 = c2 >> 24;
    innerBase = *(u8 **)alloc;
    f1 = (f32)(*(s32 *)(arg0 + 0x3C) + 1);
    first = (s32)(*(f32 *)(arg0 + 0x68) * f1);
    second = (s32)(*(f32 *)(arg0 + 0x6C) * f1);
    spA0 = (u_long128)second;
    outerIdx = 0;
    while (outerIdx < outerCount) {
        p = func_00482dc0(*(u16 *)(arg0 + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)innerBase = p;
        innerCount = *(s16 *)(p + 8) / 5;
        dst = *(u8 **)(*(u8 **)(*(u8 **)(p + 0x10) + 0x18) + 0x30);
        innerIdx = 0;
        second = (s32)spA0;
        tmp7 = innerCount - second;
        while (innerIdx < (u32)innerCount) {
            if (innerIdx < (u32)first) {
                f0 = (f32)innerIdx;
                fade = f0 / (f32)first;
            } else if ((u32)second < innerIdx) {
                s32 d1 = innerCount - (s32)innerIdx;
                f32 v1 = (f32)(u32)d1;
                f32 v0 = (f32)(u32)tmp7;
                fade = v1 / v0;
            } else {
                fade = 1.0f;
            }
            f0 = (f32)b2 * fade;
            iv = (u32)f0;
            *(u32 *)dst = (u32)spB0 | ((u32)iv << 24);
            f0 = (f32)b1 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 4) = (u32)spC0 | ((u32)iv << 24);
            f0 = (f32)b0 * fade;
            iv = (u32)f0;
            *(u32 *)(dst + 8) = (u32)spD0 | ((u32)iv << 24);
            dst[12] = dst[4];
            dst[13] = dst[5];
            dst[14] = dst[6];
            dst[15] = dst[7];
            dst[16] = dst[0];
            dst[17] = dst[1];
            dst[18] = dst[2];
            dst[19] = dst[3];
            innerIdx += 1;
            dst += 0x14;
        }
        *(s32 *)(innerBase + 4) = -1 - (s32)(outerIdx * 4);
        outerIdx += 1;
        innerBase += 0x0C;
    }
    return alloc;
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497750);
#endif


// FUN_00497C50
void func_00497c50(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 3;
    }
    jtbl_008873EC[0](obj);
}


/* measured: retail contains COP2/VU0 normalize, cross-product, and transform
   work; H009 permits inline asm, with FPU setup kept in plain C. No byte-exact
   candidate was retained in this wave. */
// FUN_00497CE0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497ce0);


// FUN_00498650
void func_00498650(u8 *arg0)
{
    u8 *obj;
    u8 *ctrl;
    u8 *list;
    s32 n;
    s32 count;
    u8 spDCb[4];
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spB0[4];
    s32 tmp;
    f32 scale;
    s32 i;
    u8 *e0;
    u8 *dst;
    f32 sp70[16];

    obj = *(u8 **)(arg0 + 0x30);
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **)obj;
    n = *(s32 *)(arg0 + 0x28);
    count = *(s32 *)(ctrl + 0x34);
    if ((count >= n) || (count == 0))
    {
        s32 *pt;

        count = *(s32 *)(ctrl + 0x38);
        tmp = (s32)func_0048abd0(ctrl, ctrl + 0x24, n, *(s32 *)(ctrl + 0x34));
        spD8 = *(s32 *)(arg0 + 0x24);
        pt = &spD8;
        scale = iGpffff8044;
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
        spD4 = tmp;
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
            :
            : "r"(&spD4), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spB0) : "memory");
        func_00483700(&sp70[0], arg0, 0, *(f32 *)(arg0 + 0x20));
        i = 0;
        while (i < count)
        {
            if (*(s32 *)(list + 4) > 0)
            {
                e0 = *(u8 **)list;
                func_003e9cb0(*(void **)(e0 + 0xC), &sp70[0], 0);
                spD0 = *(s32 *)(list + 8);
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
                    :
                    : "r"(&spD0), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(spB0)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the spCC reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)spDCb = *(volatile s32 *)&spCC;
                if (spDCb[3] != 0xFF)
                {
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                }
                else
                {
                    spDCb[3] = 0xFE;
                    dst = *(u8 **)(e0 + 0x14);
                    *(Color4 *)(dst + 4) = *(Color4 *)spDCb;
                    spDCb[3] = 0xFF;
                }
                if (*(u8 *)(ctrl + 0x5C) != 0)
                {
                    *(u16 *)e0 = *(u16 *)e0 | 1;
                }
                else
                {
                    *(u16 *)e0 = *(u16 *)e0 & 0xFFFE;
                }
                {
                    s32 b = *(u16 *)(ctrl + 0x28);
                    func_00483490(e0, b);
                }
            }
            i++;
            list += 0xC;
        }
    }
}



// FUN_004988C0
u8 *func_004988c0(u16 arg0, u8 *arg1)
{
    u8 *p;
    s32 size;
    u32 idx;

    if (arg0 >= 5)
    {
        func_0046d730(D_00713E50, 0x6A1);
    }
    idx = arg0;
    size = D_00713E84[idx * 6];
    func_0044ea90(D_00713E50, 0x6A5);
    p = (u8 *)(*jtbl_008873E8)(size + 0x40, 0x40000);
    if (p == NULL)
    {
        func_0046d730(D_00713E50, 0x6A6);
    }
    *(u32 *)(p + 0x34) = (u32)(p + 0x40);
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x2C) = idx;
    *(u32 *)(p + 0x24) = -1;
    *(u32 *)(p + 0x20) = 0x3F800000;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 vf0, 0x10(%0)" : : "r"(p) : "memory");
    func_0043f810(*(void **)(p + 0x34), arg1, size);
    *(u32 *)(p + 0x30) = ((u32 (*)(u8 *))D_00713E74[arg0 * 6])(arg1);
    ((void (*)(u8 *))D_00713E70[arg0 * 6])(p);
    return p;
}


// FUN_00498A30
u8 *func_00498a30(u8 *arg0)
{
    u8 *tex;

    tex = func_00484490(arg0);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6C9);
    }
    tex = func_004988c0(*(u16 *)(arg0 + 0xC), tex);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6CB);
    }
    return tex;
}