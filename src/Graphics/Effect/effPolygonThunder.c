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


/* measured: GUARDED_SCORE 496 via tools/measure_guarded.py
   src/Graphics/Effect/effPolygonThunder.c func_004956b0 (fnalign retail
   560/object 559 instrs, true window 2256B/564, -5/-0.9% inside 3% gate;
   probe 496 via tools/probe_variants.py --candidate v6=/var/tmp/cold4956b0/v6.c).
   M2C 316 lines + romwright --types (8 vector args from VF live-ins, retail
   GPR single u8* wins) + --raw 310 lines (cross/normalize + af40/af20[8]);
   de-noised to file idiom (plain (f32)(u32) per micro_codegen 14, sqrtf for
   sqrt.s+mula/madd, c10/cNeg1/c075/c025/c05 hoisted, D_00713D10 bridges,
   VU lqc2/vopmula/vrsqrt in genuine COP2 asm, FPU MAC plain C). Count v1
   511/560 (513w) -> v3 518 (+sqrtf, 496w) -> v5 530 (+3 lanes) -> v6 559/560
   (inside gate, 496w). Float colouring v7/v8 tie 496 -- two fails, stopping
   rule above 60 met. Remaining: saved-reg perm, FPR colour, scheduling. */
// FUN_004956B0 NONMATCHING
#ifdef NON_MATCHING
void func_004956b0(u8 *arg0)
{
    extern void func_0048a1f0(u8 *arg0);
    extern void func_004bceb0(void);
    extern u32 func_004bd050(u32 arg0);
    extern f32 func_004bd0b0(u32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern f32 func_0044b938(f32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 sqrtf(f32 arg0);
    extern void func_004bd380(u8 *axis, f32 angle);
    extern void func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern f32 fGpffff8084;
    extern f32 fGpffff80e4;
    extern f32 fGpffff80e8;
    extern f32 fGpffff80ec;
    extern u_long128 D_00713D00;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    u8 *ctrl;
    u8 *list;
    u32 cnt34;
    s32 n;
    s32 outerCount;
    s32 divisor;
    f32 f54;
    f32 f58;
    f32 f30;
    f32 f84div;
    f32 f4c;
    f32 f10c;
    f32 f50;
    f32 gp8084;
    f32 gp80e4;
    f32 gp80e8;
    f32 gp80ec;
    f32 sp130[4];
    f32 sp120[4];
    f32 sp110[4];
    f32 af40[8];
    f32 af20[8];
    f32 f80;
    f32 f7c;
    f32 c10;
    f32 cNeg1;
    f32 c075;
    f32 c025;
    f32 c05;
    s32 i;
    s32 j;
    s32 k;
    f32 tmpF;
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **) (*(u8 **)(arg0 + 0x30));
    cnt34 = *(u32 *)(ctrl + 0x34);
    n = *(s32 *)(arg0 + 0x28);
    if ((cnt34 < (u32)n) && (cnt34 != 0)) {
        return;
    }
    outerCount = *(s32 *)(ctrl + 0x38);
    divisor = *(s32 *)(ctrl + 0x40);
    f54 = *(f32 *)(ctrl + 0x54);
    f58 = *(f32 *)(ctrl + 0x58);
    f30 = (f32)*(u32 *)(ctrl + 0x3C);
    f84div = *(f32 *)(ctrl + 0x84) / f30;
    gp8084 = fGpffff8084;
    f4c = (f32)*(u32 *)(ctrl + 0x4C);
    f10c = (gp8084 * f4c) / f30;
    f50 = *(f32 *)(ctrl + 0x50);
    if (!(f84div > 0.0f)) {
        return;
    }
    func_0048a1f0((u8 *)sp120);
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(arg0) : "$vf10", "memory");
    func_004bceb0();
    __asm__ volatile(
        "lqc2 $vf10, 0(%0)\n"
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
        "sqc2 $vf10, 0(%1)\n"
        : : "r"(&D_00713D00), "r"(sp130) : "$vf10", "memory");
    gp80e4 = fGpffff80e4;
    af40[0] = 0.0f;
    f80 = *(f32 *)(ctrl + 0x80);
    af40[1] = f80;
    f7c = *(f32 *)(ctrl + 0x7C);
    tmpF = f80 + f7c;
    af40[2] = tmpF;
    tmpF = tmpF + f7c;
    af40[3] = tmpF;
    af40[4] = tmpF + f80;
    i = 0;
    c10 = 1.0f;
    cNeg1 = -1.0f;
    c075 = 0.75f;
    c025 = 0.25f;
    c05 = 0.5f;
    tmpF = c10;
    gp80e8 = fGpffff80e8;
    gp80ec = fGpffff80ec;
    while (1) {
        f32 f22;
        f32 f23;
        f32 f27;
        f32 f28;
        f32 f29;
        f32 f24;
        if (i >= outerCount) {
            return;
        }
        if (*(s32 *)(list + 4) == -1) {
            *(s32 *)(list + 8) = -1;
        } else {
            f32 r;
            u32 rnd;
            s32 timer;
            r = func_004bd0b0(0);
            f22 = (f54 * (f58 * r + (c10 - f58))) / f30;
            f27 = f50;
            rnd = func_004bd050(0);
            if ((rnd & 1) != 0) {
                f22 = f22 * cNeg1;
            }
            f23 = f22;
            timer = *(s32 *)(list + 8);
            if ((u32)(timer & 0xFF000000) >= 0x40000001U) {
                u8 *e0;
                s32 segs;
                u8 *vtx;
                *(s32 *)(list + 8) = timer + 0xC0000000;
                e0 = *(u8 **)list;
                segs = *(s16 *)(e0 + 8) / 5;
                func_003c2290(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18), 2);
                vtx = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0x5C) + 0x14);
                rnd = func_004bd050(0);
                if ((rnd & 1) != 0) {
                    f27 = f27 * cNeg1;
                }
                f29 = gp8084 * func_004bd0b0(0);
                r = func_004bd0b0(0);
                f28 = f27 * (gp80e8 * r + gp80ec);
                f24 = f28 * func_0044b7b0(f29);
                f29 = f29 + f10c;
                f28 = f28 * func_0044b7b0(f29);
                f24 = f28 - f24;
                {
                    f32 len = f24 * f24 + f84div * f84div;
                    f32 sq = sqrtf(len);
                    f24 = func_0044b938(f24 / sq);
                    f24 = f24 + *(f32 *)(list + 0xC);
                }
                {
                    f32 ax = sp130[0];
                    f32 ay = sp130[1];
                    f32 az = sp130[2];
                    f32 bx = sp120[0];
                    f32 by = sp120[1];
                    f32 bz = sp120[2];
                    f32 cx = by * az - bz * ay;
                    f32 cy = bz * ax - bx * az;
                    f32 cz = bx * ay - by * ax;
                    f32 dot = cx * cx + cy * cy + cz * cz;
                    f32 inv = 1.0f;
                    if (dot > 0.0f) {
                        inv = c10 / dot;
                    }
                    cx = cx * inv;
                    cy = cy * inv;
                    cz = cz * inv;
                    __asm__ volatile(
                        "lqc2 $vf11, 0(%0)\n"
                        "vopmula.xyz $ACC, $vf10, $vf11\n"
                        "vopmsub.xyz $vf10, $vf11, $vf10\n"
                        "sqc2 $vf10, 0(%1)\n"
                        : : "r"(sp130), "r"(sp110) : "$vf10", "$vf11", "memory");
                    sp110[0] = cx;
                    sp110[1] = cy;
                    sp110[2] = cz;
                }
                {
                    f32 s = f7c + f80;
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "sqc2 $vf10, 0(%1)\n"
                        : : "r"(*(u32 *)&s), "r"(&D_00713D10) : "$vf10", "$vf2", "memory");
                    vtx[0] = D_00713D10[0];
                    vtx[1] = D_00713D14[0];
                    vtx[2] = D_00713D18[0];
                }
                for (j = 0; j < 5; j++) {
                    u8 *p = vtx + j * 12;
                    D_00713D10[0] = *(f32 *)(p + 0);
                    D_00713D14[0] = *(f32 *)(p + 4);
                    D_00713D18[0] = *(f32 *)(p + 8);
                    __asm__ volatile(
                        "lqc2 $vf10, 0(%0)\n"
                        "vadd.xyzw $vf10, $vf10, $vf11\n"
                        "sqc2 $vf10, 0(%0)\n"
                        : : "r"(&D_00713D10) : "$vf10", "$vf11", "memory");
                    *(f32 *)(p + 0) = D_00713D10[0];
                    *(f32 *)(p + 4) = D_00713D14[0];
                    *(f32 *)(p + 8) = D_00713D18[0];
                    af20[j] = 0.0f;
                }
                {
                    u8 *nxt = vtx + 0x3C;
                    s32 it = 1;
                    f32 curA = f24;
                    f32 curB = f28;
                    f32 curC = f23;
                    while (it < segs) {
                        f32 rr = func_004bd0b0(0);
                        f32 sc = gp80e4 * (rr * c075 + c025);
                        rnd = func_004bd050(0);
                        if ((rnd & 1) != 0) {
                            gp80e4 = gp80e4 * cNeg1;
                        }
                        f29 = f29 + f10c;
                        if (!(f29 < gp8084)) {
                            f29 = f29 - gp8084;
                            f27 = f27 * cNeg1;
                            r = func_004bd0b0(0);
                            f28 = f27 * (gp80e8 * r + gp80ec);
                        }
                        curB = f28 * func_0044b7b0(f29) - curB;
                        {
                            f32 l2 = curB * curB + f84div * f84div;
                            f32 sq2 = sqrtf(l2);
                            curB = func_0044b938(curB / sq2);
                        }
                        curA = curB + sc + f22 + *(f32 *)(list + 0xC);
                        func_004bd380((u8 *)sp110, curA);
                        {
                            f32 d = (curA - f24) * c05;
                            f32 s0 = func_0044b7b0(d);
                            f32 c0 = func_0044b610(d);
                            f22 = f22 + f23;
                            for (k = 0; k < 5; k++) {
                                f32 w = (s0 / c0) * af40[k];
                                af20[k] = af20[k] + w;
                                *(f32 *)(nxt + k * 12 + 0) = *(f32 *)(nxt + k * 12 - 0x3C + 0) + w;
                                *(f32 *)(nxt + k * 12 + 4) = *(f32 *)(nxt + k * 12 - 0x3C + 4) + w;
                                *(f32 *)(nxt + k * 12 + 8) = *(f32 *)(nxt + k * 12 - 0x3C + 8) + w;
                                D_00713D10[0] = *(f32 *)(nxt + k * 12 - 0x3C + 0);
                                D_00713D14[0] = *(f32 *)(nxt + k * 12 - 0x3C + 4);
                                D_00713D18[0] = *(f32 *)(nxt + k * 12 - 0x3C + 8);
                                __asm__ volatile(
                                    "lqc2 $vf10, 0(%0)\n"
                                    "vadd.xyzw $vf10, $vf10, $vf11\n"
                                    "sqc2 $vf10, 0(%0)\n"
                                    : : "r"(&D_00713D10) : "$vf10", "$vf11", "memory");
                                *(f32 *)(nxt + k * 12 + 0) = D_00713D10[0];
                                *(f32 *)(nxt + k * 12 + 4) = D_00713D14[0];
                                *(f32 *)(nxt + k * 12 + 8) = D_00713D18[0];
                                af20[k] = w;
                            }
                            f24 = curA;
                            curB = f28 * func_0044b7b0(f29);
                        }
                        it++;
                        nxt += 0x3C;
                    }
                }
                func_003c22f0(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18));
                if ((*(u16 *)e0 & 4) != 0) {
                    *(u16 *)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0xC) |= 1;
                }
            }
            *(s32 *)(list + 4) += 1;
        }
        i++;
        list += 0x10;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004956b0);
#endif


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


/* measured: GUARDED_SCORE 666 via tools/measure_guarded.py
   src/Graphics/Effect/effPolygonThunder.c func_004968a0 (fnalign retail
   752/object 752 instrs, exact count inside 3% gate;
   probe 666 via tools/probe_variants.py --candidate v2=/var/tmp/cold4968a0/v2.c).
   M2C 424 lines + romwright --types (8 vector args from VF live-ins, retail
   GPR single u8* wins) + --raw 651 lines (cross/normalize + af40/af20[8]);
   de-noised to file idiom (plain (f32)(u32) per micro_codegen 14, sqrtf for
   sqrt.s+mula/madd, c10/cNeg1/c075/c025/c05/c20 hoisted, D_00713D10 bridges,
   VU lqc2/vopmula/vrsqrt in genuine COP2 asm, FPU MAC plain C). Count v1
   788/752 (690w) -> v2 770/752 candidate (666w, retail-ordered early,
   single-sc fix, dummy-free) -> installed 752/752 exact. Pragma probes
   loopinv 679/nounroll 657 tie/nosched 657 tie/nocommon 726 -- no help.
   Subscript off=i*12 tie 657, colour hdr/ctrl swap 659 worse -- two fails,
   stopping rule above 60 met. Remaining: saved-reg perm, FPR colour,
   scheduling. */
// FUN_004968A0 NONMATCHING
#ifdef NON_MATCHING
void func_004968a0(u8 *arg0)
{
    extern void func_0048a1f0(u8 *arg0);
    extern u32 func_004bd050(u32 arg0);
    extern f32 func_004bd0b0(u32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern f32 func_0044b938(f32 arg0);
    extern f32 func_0044b340(f32 arg0);
    extern f32 sqrtf(f32 arg0);
    extern void func_004bd1a0(f32 arg0);
    extern void func_004bd3c0(f32 arg0);
    extern void func_004bd450(void);
    extern void func_004bd380(u8 *axis, f32 angle);
    extern void func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern f32 fGpffff804c;
    extern f32 fGpffff8084;
    extern f32 fGpffff8098;
    extern f32 fGpffff809c;
    extern f32 fGpffff80d4;
    extern f32 fGpffff80d8;
    extern f32 fGpffff80dc;
    extern f32 fGpffff80e0;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    u8 *hdr;
    u8 *ctrl;
    u8 *list;
    u32 cnt34;
    s32 n;
    s32 outerCount;
    s32 divisor;
    f32 f30;
    f32 f84div;
    f32 f4c;
    f32 f10c;
    f32 f50;
    f32 fA8;
    f32 gp804c;
    f32 gp8084;
    f32 gp8098;
    f32 gp809c;
    f32 gp80d4;
    f32 gp80d8;
    f32 gp80dc;
    f32 gp80e0;
    f32 hdr4;
    f32 c10;
    f32 cNeg1;
    f32 c075;
    f32 c025;
    f32 c05;
    f32 c20;
    f32 sp108s;
    f32 af40[8];
    f32 af20[8];
    f32 sp160[4];
    f32 sp150[4];
    f32 sp140[4];
    f32 sp130[4];
    f32 sp180[4];
    f32 sp170[4];
    u8 mode88;
    s32 i;
    s32 j;
    s32 k;
    f32 tmpF;
    hdr = *(u8 **)(arg0 + 0x30);
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **)hdr;
    cnt34 = *(u32 *)(ctrl + 0x34);
    n = *(s32 *)(arg0 + 0x28);
    if ((cnt34 < (u32)n) && (cnt34 != 0)) {
        return;
    }
    outerCount = *(s32 *)(ctrl + 0x38);
    divisor = *(s32 *)(ctrl + 0x40);
    f30 = (f32)*(u32 *)(ctrl + 0x3C);
    f84div = *(f32 *)(ctrl + 0x84) / f30;
    f4c = (f32)*(u32 *)(ctrl + 0x4C);
    gp8084 = fGpffff8084;
    f10c = (gp8084 * f4c) / f30;
    f50 = *(f32 *)(ctrl + 0x50);
    fA8 = *(f32 *)(ctrl + 0xA8);
    mode88 = *(u8 *)(ctrl + 0x88);
    if (!(f84div > 0.0f)) {
        return;
    }
    func_0048a1f0((u8 *)sp160);
    gp804c = fGpffff804c;
    tmpF = f84div / 10.0f;
    sp108s = -(gp804c * tmpF);
    af40[0] = 0.0f;
    tmpF = *(f32 *)(ctrl + 0x80);
    af40[1] = tmpF;
    tmpF = tmpF + *(f32 *)(ctrl + 0x7C);
    af40[2] = tmpF;
    tmpF = tmpF + *(f32 *)(ctrl + 0x7C);
    af40[3] = tmpF;
    af40[4] = tmpF + *(f32 *)(ctrl + 0x80);
    c10 = 1.0f;
    cNeg1 = -1.0f;
    hdr4 = *(f32 *)(hdr + 4);
    *(f32 *)(hdr + 4) = hdr4 + *(f32 *)(hdr + 8);
    i = 0;
    c05 = 0.5f;
    c20 = 2.0f;
    c075 = 0.75f;
    c025 = 0.25f;
    gp8098 = fGpffff8098;
    gp809c = fGpffff809c;
    gp80d4 = fGpffff80d4;
    gp80d8 = fGpffff80d8;
    gp80dc = fGpffff80dc;
    gp80e0 = fGpffff80e0;
    while (1) {
        f32 f22;
        f32 f23;
        f32 f27;
        f32 f28;
        f32 f29;
        f32 f30loc;
        if (i >= outerCount) {
            return;
        }
        if (*(s32 *)(list + 0x14) == -1) {
            f32 r;
            f32 a4;
            a4 = *(f32 *)(ctrl + 0xA4);
            r = func_004bd0b0(0);
            *(f32 *)(list + 0x24) = *(f32 *)(ctrl + 0xA0) * (a4 * r + (c10 - a4));
            *(f32 *)(list + 0x28) = 0.0f;
            if (mode88 == 0) {
                r = func_004bd0b0(0);
                *(f32 *)(list + 0x1C) = gp8084 * (c20 * (r - c05));
                *(f32 *)(list + 0x2C) = 0.0f;
            } else {
                r = func_004bd0b0(0);
                *(f32 *)(list + 0x1C) = gp80dc * (c20 * (r - c05));
                r = func_004bd0b0(0);
                *(f32 *)(list + 0x2C) = *(f32 *)(ctrl + 0x9C) * r;
            }
            r = func_004bd0b0(0);
            *(f32 *)(list + 0x20) = gp8084 * (c20 * (r - c05));
            func_004bd1a0(*(f32 *)(list + 0x1C));
            func_004bd3c0(*(f32 *)(list + 0x20));
            func_004bd450();
            {
                f32 ang = *(f32 *)(list + 0x28);
                f32 cx = hdr4 * func_0044b610(ang);
                f32 sx = hdr4 * func_0044b7b0(ang);
                sp150[0] = cx;
                sp150[1] = 0.0f;
                sp150[2] = sx;
                __asm__ volatile(
                    "lqc2 $vf10, 0(%0)\n"
                    "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                    "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                    "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                    "sqc2 $vf10, 0(%0)\n"
                    : : "r"(sp150) : "$vf10", "memory");
                *(f32 *)(list + 0x4) = sp150[0];
                *(f32 *)(list + 0x8) = sp150[1];
                *(f32 *)(list + 0xC) = sp150[2];
            }
            *(s32 *)(list + 0x18) = -1;
        } else {
            s32 timer = *(s32 *)(list + 0x18);
            if ((u32)(timer & 0xFF000000) >= 0x40000001U) {
                u8 *e0;
                s32 segs;
                u8 *vtx;
                *(s32 *)(list + 0x18) = timer + 0xC0000000;
                e0 = *(u8 **)list;
                segs = *(s16 *)(e0 + 8) / 5;
                func_003c2290(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18), 2);
                vtx = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0x5C) + 0x14);
                {
                    u32 rnd = func_004bd050(0);
                    if ((rnd & 1) != 0) {
                        f50 = f50 * cNeg1;
                    }
                }
                f27 = f50;
                f29 = gp8084 * func_004bd0b0(0);
                {
                    f32 r = func_004bd0b0(0);
                    f28 = f27 * (gp80d4 * r + gp80e0);
                }
                {
                    f32 s1 = f28 * func_0044b7b0(f29);
                    f29 = f29 + f10c;
                    f28 = f28 * func_0044b7b0(f29);
                    f22 = s1;
                    f23 = f28 - s1;
                    {
                        f32 len = f23 * f23 + f84div * f84div;
                        f32 sq = sqrtf(len);
                        f30loc = func_0044b938(f23 / sq);
                        f30loc = f30loc + *(f32 *)(list + 0xC);
                    }
                    {
                        f32 r;
                        f32 sc;
                        f32 ang2;
                        r = func_004bd0b0(0);
                        sc = sp108s * (gp809c * r + gp8098);
                        ang2 = ((f32)(*(s32 *)(list + 0x14) + 1) * (fA8 * (f32)(*(s32 *)(list + 0x14) + 1) * c05 + *(f32 *)(list + 0x24))) + *(f32 *)(list + 0x28);
                        func_004bd1a0(*(f32 *)(list + 0x1C));
                        func_004bd3c0(*(f32 *)(list + 0x20));
                        func_004bd450();
                        {
                            f32 cx = hdr4 * func_0044b610(ang2);
                            f32 sx = hdr4 * func_0044b7b0(ang2);
                            sp150[0] = cx;
                            sp150[1] = 0.0f;
                            sp150[2] = sx;
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                                "sqc2 $vf10, 0(%0)\n"
                                : : "r"(sp150) : "$vf10", "memory");
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "sqc2 $vf10, 0(%1)\n"
                                : : "r"(sp150), "r"(sp140) : "$vf2", "$vf10", "memory");
                        }
                        {
                            f32 ax = sp140[0] - *(f32 *)(list + 0x4);
                            f32 ay = sp140[1] - *(f32 *)(list + 0x8);
                            f32 az = sp140[2] - *(f32 *)(list + 0xC);
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "sqc2 $vf10, 0(%2)\n"
                                "vopmula.xyz $ACC, $vf10, $vf11\n"
                                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                                "sqc2 $vf10, 0(%2)\n"
                                : : "r"(sp140), "r"(sp160), "r"(sp130) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            {
                                f32 bx = sp160[0];
                                f32 by = sp160[1];
                                f32 bz = sp160[2];
                                f32 cx = by * az - bz * ay;
                                f32 cy = bz * ax - bx * az;
                                f32 cz = bx * ay - by * ax;
                                f32 dot = cx * cx + cy * cy + cz * cz;
                                f32 inv = 1.0f;
                                if (dot > 0.0f) {
                                    inv = c10 / dot;
                                }
                                sp130[0] = cx * inv;
                                sp130[1] = cy * inv;
                                sp130[2] = cz * inv;
                            }
                            __asm__ volatile(
                                "lqc2 $vf11, 0(%0)\n"
                                "vmove.xyzw $vf10, $vf12\n"
                                "vopmula.xyz $ACC, $vf10, $vf11\n"
                                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "vmove.xyzw $vf11, $vf10\n"
                                : : "r"(sp130) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            {
                                f32 s = *(f32 *)(ctrl + 0x7C) + *(f32 *)(ctrl + 0x80);
                                __asm__ volatile(
                                    "qmtc2.ni %0, $vf2\n"
                                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                    "sqc2 $vf10, 0(%1)\n"
                                    : : "r"(*(u32 *)&s), "r"(&D_00713D10) : "$vf10", "$vf2", "memory");
                                vtx[0] = D_00713D10[0];
                                vtx[1] = D_00713D14[0];
                                vtx[2] = D_00713D18[0];
                            }
                            {
                                f32 s = *(f32 *)(ctrl + 0x7C);
                                __asm__ volatile(
                                    "qmtc2.ni %0, $vf2\n"
                                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                    "sqc2 $vf10, 0(%1)\n"
                                    : : "r"(*(u32 *)&s), "r"(&D_00713D10) : "$vf10", "$vf2", "memory");
                                *(f32 *)(vtx + 0x30) = D_00713D10[0];
                                *(f32 *)(vtx + 0x34) = D_00713D14[0];
                                *(f32 *)(vtx + 0x38) = D_00713D18[0];
                            }
                            vtx[0x18] = 0.0f;
                            vtx[0x1C] = 0.0f;
                            vtx[0x20] = 0.0f;
                            sp150[1] = sp150[1] + *(f32 *)(list + 0x2C);
                            for (j = 0; j < 5; j++) {
                                u8 *p = vtx + j * 12;
                                D_00713D10[0] = *(f32 *)(p + 0);
                                D_00713D14[0] = *(f32 *)(p + 4);
                                D_00713D18[0] = *(f32 *)(p + 8);
                                __asm__ volatile(
                                    "lqc2 $vf10, 0(%0)\n"
                                    "vadd.xyzw $vf10, $vf10, $vf11\n"
                                    "sqc2 $vf10, 0(%0)\n"
                                    : : "r"(&D_00713D10) : "$vf10", "$vf11", "memory");
                                *(f32 *)(p + 0) = D_00713D10[0];
                                *(f32 *)(p + 4) = D_00713D14[0];
                                *(f32 *)(p + 8) = D_00713D18[0];
                                af20[j] = 0.0f;
                            }
                            {
                                u8 *nxt = vtx + 0x3C;
                                s32 it = 1;
                                f32 curA = f30loc;
                                f32 curB = f28;
                                while (it < segs) {
                                    f32 rr = func_004bd0b0(0);
                                    f32 sc2 = gp80d8 * (rr * c075 + c025);
                                    u32 rnd2 = func_004bd050(0);
                                    if ((rnd2 & 1) != 0) {
                                        gp80d8 = gp80d8 * cNeg1;
                                    }
                                    f29 = f29 + f10c;
                                    if (!(f29 < gp8084)) {
                                        f29 = f29 - gp8084;
                                        f27 = f27 * cNeg1;
                                        r = func_004bd0b0(0);
                                        f28 = f27 * (gp80d4 * r + gp80e0);
                                        r = func_004bd0b0(0);
                                        sc = sp108s * (gp809c * r + gp8098);
                                    }
                                    {
                                        f32 nb = f28 * func_0044b7b0(f29);
                                        f32 l2 = nb * nb + f84div * f84div;
                                        f32 sq2 = sqrtf(l2);
                                        nb = func_0044b938(nb / sq2);
                                        curA = nb + sc2 + *(f32 *)(list + 0xC);
                                    }
                                    func_004bd380((u8 *)sp180, curA);
                                    __asm__ volatile(
                                        "lqc2 $vf10, 0(%0)\n"
                                        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                        "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                                        "sqc2 $vf10, 0(%0)\n"
                                        : : "r"(sp180) : "$vf10", "memory");
                                    func_004bd380((u8 *)sp170, sc);
                                    __asm__ volatile(
                                        "lqc2 $vf10, 0(%0)\n"
                                        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                        "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                                        "sqc2 $vf10, 0(%0)\n"
                                        : : "r"(sp170) : "$vf10", "memory");
                                    {
                                        f32 d = (curA - f30loc) * c05;
                                        f32 w = func_0044b340(d);
                                        for (k = 0; k < 5; k++) {
                                            f32 ww = w * af40[k];
                                            af20[k] = af20[k] + ww;
                                            *(f32 *)(nxt + k * 12 + 0) = *(f32 *)(nxt + k * 12 - 0x3C + 0) + ww;
                                            *(f32 *)(nxt + k * 12 + 4) = *(f32 *)(nxt + k * 12 - 0x3C + 4) + ww;
                                            *(f32 *)(nxt + k * 12 + 8) = *(f32 *)(nxt + k * 12 - 0x3C + 8) + ww;
                                            D_00713D10[0] = *(f32 *)(nxt + k * 12 - 0x3C + 0);
                                            D_00713D14[0] = *(f32 *)(nxt + k * 12 - 0x3C + 4);
                                            D_00713D18[0] = *(f32 *)(nxt + k * 12 - 0x3C + 8);
                                            __asm__ volatile(
                                                "lqc2 $vf10, 0(%0)\n"
                                                "vadd.xyzw $vf10, $vf10, $vf11\n"
                                                "sqc2 $vf10, 0(%0)\n"
                                                : : "r"(&D_00713D10) : "$vf10", "$vf11", "memory");
                                            *(f32 *)(nxt + k * 12 + 0) = D_00713D10[0];
                                            *(f32 *)(nxt + k * 12 + 4) = D_00713D14[0];
                                            *(f32 *)(nxt + k * 12 + 8) = D_00713D18[0];
                                            af20[k] = ww;
                                        }
                                        f30loc = curA;
                                        curB = f28 * func_0044b7b0(f29);
                                    }
                                    it++;
                                    nxt += 0x3C;
                                }
                            }
                            func_003c22f0(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18));
                            if ((*(u16 *)e0 & 4) != 0) {
                                *(u16 *)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0xC) |= 1;
                            }
                        }
                    }
                }
                *(s32 *)(list + 0x14) += 1;
            } else {
                *(s32 *)(list + 0x14) = -1;
                if (divisor > 0) {
                    *(s32 *)(list + 0x14) -= func_004bd050(0) % (u32)divisor;
                }
            }
        }
        i++;
        list += 0x30;
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004968a0);
#endif


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
/* measured 00497750 (owner, 2026-09-19): 327/320 with 278 fnalign edits and one missing
   float save, `$f20`, which `regsave_scan` confirms is live across the call at R90.
   Retail holds the fade ratio there, initialised **before the outer loop** with
   `mtc1 $zero, $f20` at R81 - that is `fade = 0.0f` in the source - and then written by
   the two divisions at R145 and R184, the `mov.s` at R190, and read at R202, R230, R258.
   Three spellings measured, all exactly 278: inlining the three `(f32)bN * fade`
   multiplications so they stop sharing the `f0` temporary; initialising `fade = 0.0f`
   before the outer loop as retail does; and both together.  MWCC deletes the initial
   store because every path assigns `fade` before reading it, so the body cannot give the
   value the lifetime retail gives it from this shape.  Whatever keeps it alive in retail
   is outside this loop - look for a use of the ratio after the loop ends. */
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


/* measured: GUARDED_SCORE 564 via tools/measure_guarded.py
   src/Graphics/Effect/effPolygonThunder.c func_00497ce0 (fnalign retail
   604/object 621 instrs, true window 2416B/604, +17/+2.8% inside 3% gate;
   probe 564 via tools/probe_variants.py --candidate v2=/var/tmp/cold497ce0/v2.c).
   M2C 357 lines + romwright --types (6 vector args from VF live-ins, retail
   GPR single u8* wins) + --raw 595 lines (cross/normalize + Q/dot bridges);
   de-noised to file idiom (plain (f32)(u32) per micro_codegen 14, mfc1+qmtc2
   for D_00713CE0 scales, D_00713D10 bridges, VU lqc2/vopmula/vrsqrt in genuine
   COP2 asm, FPU MAC plain C). Count v1 621/604 (570w) -> v2 621/604 (564w,
   +mfc1 for D_00713CE0 scales) -> v4 619-620/604 (576-569w, Q/qmfc2 direct,
   worse). Float colouring v5/v6 tie 564 -- two fails, stopping rule above 60
   met. Remaining: saved-reg perm, FPR colour, scheduling. */
// FUN_00497CE0 NONMATCHING
#ifdef NON_MATCHING
void func_00497ce0(u8 *arg0)
{
    extern void func_0048a1f0(u8 *arg0);
    extern void func_004bceb0(void);
    extern u32 func_004bd050(u32 arg0);
    extern f32 func_004bd0b0(u32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_004bd380(u8 *axis, f32 angle);
    extern void func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern f32 fGpffff8084;
    extern f32 fGpffff80d0;
    extern f32 fGpffff80d4;
    extern f32 fGpffff80d8;
    extern u_long128 D_00713CE0;
    extern u_long128 D_00713D00;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    u8 *ctrl;
    u8 *list;
    u32 cnt34;
    s32 n;
    s32 outerCount;
    s32 divisor;
    f32 f3C;
    f32 f31q;
    f32 f44;
    f32 gp8084;
    f32 gp80d0;
    f32 gp80d4;
    f32 gp80d8s;
    f32 c20;
    f32 c40;
    f32 stkEC;
    f32 stkE8;
    f32 stkE0;
    f32 stkE4;
    f32 spillDC;
    f32 sp100[4];
    f32 sp110[4];
    f32 sp120[4];
    f32 sp130[4];
    f32 sp140[4];
    f32 sp150[4];
    f32 sp160[4];
    f32 sp170[4];
    f32 sp180[4];
    f32 sp190[4];
    f32 spF0[4];
    u32 qbits;
    s32 i;
    s32 j;
    ctrl = *(u8 **)(arg0 + 0x34);
    list = *(u8 **)(*(u8 **)(arg0 + 0x30));
    cnt34 = *(u32 *)(ctrl + 0x34);
    n = *(s32 *)(arg0 + 0x28);
    if ((cnt34 < (u32)n) && (cnt34 != 0)) {
        return;
    }
    outerCount = *(s32 *)(ctrl + 0x38);
    divisor = *(s32 *)(ctrl + 0x40);
    func_0048a1f0((u8 *)sp100);
    __asm__ volatile(
        "lqc2 $vf10, 0(%0)\n"
        "vmove.xyzw $vf12, $vf10\n"
        : : "r"(&D_00713CE0) : "$vf10", "$vf12", "memory");
    {
        f32 s = *(f32 *)(ctrl + 0x7C);
        __asm__ volatile(
            "mfc1 $2, %0\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "sqc2 $vf10, 0(%1)\n"
            : : "f"(s), "r"(sp190) : "$2", "$vf10", "$vf2", "memory");
    }
    __asm__ volatile("vmove.xyzw $vf10, $vf12\n" : : : "$vf10", "$vf12", "memory");
    {
        f32 s = *(f32 *)(ctrl + 0x7C) + *(f32 *)(ctrl + 0x80);
        __asm__ volatile(
            "mfc1 $2, %0\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "sqc2 $vf10, 0(%1)\n"
            : : "f"(s), "r"(sp180) : "$2", "$vf10", "$vf2", "memory");
    }
    __asm__ volatile(
        "vsub.xyz $vf10, $vf0, $vf10\n"
        "sqc2 $vf10, 0(%0)\n"
        : : "r"(sp170) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(arg0) : "$vf10", "memory");
    func_004bceb0();
    __asm__ volatile(
        "lqc2 $vf10, 0(%0)\n"
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
        : : "r"(&D_00713D00) : "$vf10", "memory");
    {
        u32 b = *(u32 *)(ctrl + 0x84);
        __asm__ volatile(
            "qmtc2.ni %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vmove.xyzw $vf11, $vf0\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vaddy.x $vf2, $vf2, $vf2y\n"
            "vaddz.x $vf2, $vf2, $vf2z\n"
            "vsqrt $Q, $vf2x\n"
            "vwaitq\n"
            "cfc2 %0, $vi22\n"
            : "+r"(b) : : "$vf2", "$vf10", "$vf11", "memory");
        qbits = b;
    }
    {
        f32 q = *(f32 *)&qbits;
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n"
            "sqc2 $vf10, 0(%0)\n"
            : : "r"(sp160) : "$vf2", "$vf10", "memory");
        f3C = (f32)*(u32 *)(ctrl + 0x3C);
        f31q = (2.0f * q) / f3C;
    }
    f44 = *(f32 *)(ctrl + 0x44);
    gp8084 = fGpffff8084;
    gp80d0 = fGpffff80d0;
    gp80d4 = fGpffff80d4;
    c20 = 2.0f;
    c40 = 4.0f;
    stkE0 = 0.0f;
    stkEC = 1.0f;
    stkE8 = 0.5f;
    stkE4 = fGpffff80d8;
    i = 0;
    {
        f32 f27loc = f44;
        f32 f30loc;
        f32 f29loc;
        f32 f28loc;
        f32 f20loc;
        s32 neg1 = -1;
        (void)neg1;
        while (i < outerCount) {
            if (*(s32 *)(list + 4) == -1) {
                *(s32 *)(list + 8) = -1;
            } else {
                s32 timer = *(s32 *)(list + 8);
                if ((u32)(timer & 0xFF000000) >= 0x40000001U) {
                    u8 *e0;
                    s32 segs;
                    u8 *vtx;
                    *(s32 *)(list + 8) = timer + 0xC0000000;
                    e0 = *(u8 **)list;
                    segs = (*(s16 *)(e0 + 8) / 5) >> 1;
                    func_003c2290(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18), 2);
                    vtx = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0x5C) + 0x14);
                    __asm__ volatile(
                        "lqc2 $vf10, 0(%0)\n"
                        "lqc2 $vf11, 0(%1)\n"
                        "vopmula.xyz $ACC, $vf10, $vf11\n"
                        "vopmsub.xyz $vf10, $vf11, $vf10\n"
                        "vmul.xyz $vf2, $vf10, $vf10\n"
                        "vmulax.w $ACC, $vf0, $vf2x\n"
                        "vmadday.w $ACC, $vf0, $vf2y\n"
                        "vmaddz.w $vf2, $vf0, $vf2z\n"
                        "vrsqrt $Q, $vf0w, $vf2w\n"
                        "vwaitq\n"
                        "vmulq.xyz $vf10, $vf10, $Q\n"
                        "sqc2 $vf10, 0(%2)\n"
                        : : "r"(sp100), "r"(sp160), "r"(sp150) : "$vf10", "$vf11", "$vf2", "memory");
                    f30loc = gp80d0 * func_004bd0b0(0);
                    f29loc = f30loc - gp80d0;
                    f28loc = f27loc * func_0044b7b0(f30loc);
                    {
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)\n"
                            "qmtc2.ni %1, $vf2\n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                            "sqc2 $vf10, 0(%2)\n"
                            : : "r"(sp150), "r"(*(u32 *)&f28loc), "r"(sp120) : "$vf10", "$vf2", "memory");
                    }
                    f20loc = f27loc * func_0044b7b0(f30loc);
                    {
                        f32 d = f20loc - f28loc;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)\n"
                            "qmtc2.ni %1, $vf2\n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                            "vmove.xyzw $vf12, $vf10\n"
                            : : "r"(sp160), "r"(*(u32 *)&f31q), "r"(sp150) : "$vf10", "$vf12", "$vf2", "memory");
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)\n"
                            "qmtc2.ni %1, $vf2\n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                            "vadd.xyzw $vf10, $vf10, $vf12\n"
                            "vmove.xyzw $vf12, $vf10\n"
                            : : "r"(sp150), "r"(*(u32 *)&d), "r"(sp150) : "$vf10", "$vf12", "$vf2", "memory");
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)\n"
                            "vadd.xyzw $vf11, $vf11, $vf10\n"
                            "sqc2 $vf11, 0(%1)\n"
                            "vmove.xyzw $vf10, $vf12\n"
                            "vmul.xyz $vf2, $vf10, $vf10\n"
                            "vmulax.w $ACC, $vf0, $vf2x\n"
                            "vmadday.w $ACC, $vf0, $vf2y\n"
                            "vmaddz.w $vf2, $vf0, $vf2z\n"
                            "vrsqrt $Q, $vf0w, $vf2w\n"
                            "vwaitq\n"
                            "vmulq.xyz $vf10, $vf10, $Q\n"
                            "sqc2 $vf10, 0(%2)\n"
                            : : "r"(sp120), "r"(sp110), "r"(sp140) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                    }
                    {
                        f32 step = c40 * (gp8084 / (f32)segs);
                        f28loc = step;
                        for (j = 0; j < segs; j++) {
                            u8 *base = vtx + j * 0x78;
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vopmula.xyz $ACC, $vf10, $vf11\n"
                                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "sqc2 $vf10, 0(%0)\n"
                                : : "r"(sp140), "r"(sp100) : "$vf10", "$vf11", "$vf2", "memory");
                            D_00713D10[0] = sp120[0];
                            D_00713D14[0] = sp120[1];
                            D_00713D18[0] = sp120[2];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "sqc2 $vf10, 0(%1)\n"
                                : : "r"(sp120), "r"(&D_00713D10) : "$vf10", "memory");
                            *(f32 *)(base + 0x18) = D_00713D10[0];
                            *(f32 *)(base + 0x1C) = D_00713D14[0];
                            *(f32 *)(base + 0x20) = D_00713D18[0];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "lqc2 $vf10, 0(%2)\n"
                                "vmove.xyzw $vf11, $vf10\n"
                                "vadd.xyzw $vf10, $vf10, $vf12\n"
                                "sqc2 $vf10, 0(%3)\n"
                                : : "r"(sp140), "r"(sp190), "r"(sp120), "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            *(f32 *)(base + 0x0C) = D_00713D10[0];
                            *(f32 *)(base + 0x10) = D_00713D14[0];
                            *(f32 *)(base + 0x14) = D_00713D18[0];
                            __asm__ volatile(
                                "vmove.xyzw $vf10, $vf12\n"
                                "vsub.xyzw $vf11, $vf11, $vf10\n"
                                "sqc2 $vf11, 0(%0)\n"
                                : : "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "memory");
                            *(f32 *)(base + 0x24) = D_00713D10[0];
                            *(f32 *)(base + 0x28) = D_00713D14[0];
                            *(f32 *)(base + 0x2C) = D_00713D18[0];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "lqc2 $vf10, 0(%2)\n"
                                "vmove.xyzw $vf11, $vf10\n"
                                "vadd.xyzw $vf10, $vf10, $vf12\n"
                                "sqc2 $vf10, 0(%3)\n"
                                : : "r"(sp140), "r"(sp180), "r"(sp120), "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            *(f32 *)(base + 0x00) = D_00713D10[0];
                            *(f32 *)(base + 0x04) = D_00713D14[0];
                            *(f32 *)(base + 0x08) = D_00713D18[0];
                            __asm__ volatile(
                                "vmove.xyzw $vf10, $vf12\n"
                                "vsub.xyzw $vf11, $vf11, $vf10\n"
                                "sqc2 $vf11, 0(%0)\n"
                                : : "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "memory");
                            *(f32 *)(base + 0x30) = D_00713D10[0];
                            *(f32 *)(base + 0x34) = D_00713D14[0];
                            *(f32 *)(base + 0x38) = D_00713D18[0];
                            {
                                u32 a = *(u32 *)(sp140);
                                u32 b2 = *(u32 *)(sp110);
                                (void)a; (void)b2;
                            }
                            __asm__ volatile(
                                "lq $2, 0(%0)\n"
                                "sq $2, 0(%1)\n"
                                : : "r"(sp140), "r"(sp130) : "$2", "memory");
                            __asm__ volatile(
                                "lq $2, 0(%0)\n"
                                "sq $2, 0(%1)\n"
                                : : "r"(sp110), "r"(sp120) : "$2", "memory");
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "sqc2 $vf10, 0(%1)\n"
                                : : "r"(sp120), "r"(&D_00713D10) : "$vf10", "memory");
                            *(f32 *)(base + 0x54) = D_00713D10[0];
                            *(f32 *)(base + 0x58) = D_00713D14[0];
                            *(f32 *)(base + 0x5C) = D_00713D18[0];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "lqc2 $vf10, 0(%2)\n"
                                "vmove.xyzw $vf11, $vf10\n"
                                "vadd.xyzw $vf10, $vf10, $vf12\n"
                                "sqc2 $vf10, 0(%3)\n"
                                : : "r"(sp140), "r"(sp100), "r"(sp120), "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            *(f32 *)(base + 0x48) = D_00713D10[0];
                            *(f32 *)(base + 0x4C) = D_00713D14[0];
                            *(f32 *)(base + 0x50) = D_00713D18[0];
                            __asm__ volatile(
                                "vmove.xyzw $vf10, $vf12\n"
                                "vsub.xyzw $vf11, $vf11, $vf10\n"
                                "sqc2 $vf11, 0(%0)\n"
                                : : "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "memory");
                            *(f32 *)(base + 0x60) = D_00713D10[0];
                            *(f32 *)(base + 0x64) = D_00713D14[0];
                            *(f32 *)(base + 0x68) = D_00713D18[0];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                "lqc2 $vf10, 0(%2)\n"
                                "vmove.xyzw $vf11, $vf10\n"
                                "vadd.xyzw $vf10, $vf10, $vf12\n"
                                "sqc2 $vf10, 0(%3)\n"
                                : : "r"(sp140), "r"(sp100), "r"(sp120), "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            *(f32 *)(base + 0x3C) = D_00713D10[0];
                            *(f32 *)(base + 0x40) = D_00713D14[0];
                            *(f32 *)(base + 0x44) = D_00713D18[0];
                            __asm__ volatile(
                                "vmove.xyzw $vf10, $vf12\n"
                                "vsub.xyzw $vf11, $vf11, $vf10\n"
                                "sqc2 $vf11, 0(%0)\n"
                                : : "r"(&D_00713D10) : "$vf10", "$vf11", "$vf12", "memory");
                            *(f32 *)(base + 0x6C) = D_00713D10[0];
                            *(f32 *)(base + 0x70) = D_00713D14[0];
                            *(f32 *)(base + 0x74) = D_00713D18[0];
                            f30loc = f30loc + f28loc;
                            f29loc = f29loc + f28loc;
                            if (!(f29loc <= gp8084)) {
                                f32 r;
                                f29loc = f29loc - gp8084;
                                r = func_004bd0b0(0);
                                f27loc = f44 * (stkEC - gp80d4 * r);
                                (void)stkE0; (void)stkE4; (void)stkE8;
                            }
                            spillDC = f20loc;
                            f20loc = f27loc * func_0044b7b0(f30loc);
                            {
                                f32 d2 = f20loc - f28loc;
                                __asm__ volatile(
                                    "lqc2 $vf10, 0(%0)\n"
                                    "qmtc2.ni %1, $vf2\n"
                                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                    "vmove.xyzw $vf12, $vf10\n"
                                    : : "r"(sp160), "r"(*(u32 *)&f31q) : "$vf10", "$vf12", "$vf2", "memory");
                                __asm__ volatile(
                                    "lqc2 $vf10, 0(%0)\n"
                                    "qmtc2.ni %1, $vf2\n"
                                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                    "vadd.xyzw $vf10, $vf10, $vf12\n"
                                    "sqc2 $vf10, 0(%2)\n"
                                    : : "r"(sp150), "r"(*(u32 *)&d2), "r"(spF0) : "$vf10", "$vf12", "$vf2", "memory");
                            }
                            {
                                f32 r2 = func_004bd0b0(0);
                                f32 ang = stkE4 * (c20 * (r2 - stkE8));
                                func_004bd380((u8 *)sp100, ang);
                            }
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                                "vmove.xyzw $vf12, $vf10\n"
                                : : "r"(spF0) : "$vf10", "$vf12", "memory");
                            __asm__ volatile(
                                "lqc2 $vf11, 0(%0)\n"
                                "vadd.xyzw $vf11, $vf11, $vf10\n"
                                "sqc2 $vf11, 0(%1)\n"
                                "vmove.xyzw $vf10, $vf12\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "sqc2 $vf10, 0(%2)\n"
                                : : "r"(sp120), "r"(sp110), "r"(sp140) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)\n"
                                "lqc2 $vf11, 0(%1)\n"
                                "vsub.xyzw $vf10, $vf10, $vf11\n"
                                "vmul.xyz $vf2, $vf10, $vf10\n"
                                "vmulax.w $ACC, $vf0, $vf2x\n"
                                "vmadday.w $ACC, $vf0, $vf2y\n"
                                "vmaddz.w $vf2, $vf0, $vf2z\n"
                                "vrsqrt $Q, $vf0w, $vf2w\n"
                                "vwaitq\n"
                                "vmulq.xyz $vf10, $vf10, $Q\n"
                                "lqc2 $vf11, 0(%2)\n"
                                "vmul.xyz $vf2, $vf10, $vf11\n"
                                "vaddy.x $vf2, $vf2, $vf2y\n"
                                "vaddz.x $vf2, $vf2, $vf2z\n"
                                "qmfc2.ni $2, $vf2\n"
                                : : "r"(sp110), "r"(sp120), "r"(sp130) : "$vf2", "$vf10", "$vf11", "$2", "memory");
                            {
                                u32 dbits;
                                __asm__ volatile("qmfc2.ni %0, $vf2" : "=r"(dbits) : : "memory");
                                {
                                    f32 dot = *(f32 *)&dbits;
                                    u8 *sel;
                                    if (!(dot < stkE0)) {
                                        sel = vtx + j * 0x78 + 0x3C - 0x3C;
                                        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(sp170) : "$vf12", "memory");
                                    } else {
                                        sel = vtx + j * 0x78 + 0x3C - 0x0C;
                                        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(sp180) : "$vf12", "memory");
                                    }
                                    __asm__ volatile(
                                        "lqc2 $vf10, 0(%0)\n"
                                        "lqc2 $vf11, 0(%1)\n"
                                        "vopmula.xyz $ACC, $vf10, $vf11\n"
                                        "vopmsub.xyz $vf10, $vf11, $vf10\n"
                                        "vmul.xyz $vf2, $vf10, $vf10\n"
                                        "vmulax.w $ACC, $vf0, $vf2x\n"
                                        "vmadday.w $ACC, $vf0, $vf2y\n"
                                        "vmaddz.w $vf2, $vf0, $vf2z\n"
                                        "vrsqrt $Q, $vf0w, $vf2w\n"
                                        "vwaitq\n"
                                        "vmulq.xyz $vf10, $vf10, $Q\n"
                                        "vmove.xyzw $vf11, $vf12\n"
                                        "vmul.xyzw $vf10, $vf10, $vf11\n"
                                        : : "r"(sp140), "r"(sp100) : "$vf10", "$vf11", "$vf12", "$vf2", "memory");
                                    D_00713D10[0] = *(f32 *)(sel + 0);
                                    D_00713D14[0] = *(f32 *)(sel + 4);
                                    D_00713D18[0] = *(f32 *)(sel + 8);
                                    __asm__ volatile(
                                        "lqc2 $vf11, 0(%0)\n"
                                        "vadd.xyzw $vf10, $vf10, $vf11\n"
                                        "sqc2 $vf10, 0(%1)\n"
                                        : : "r"(&D_00713D10), "r"(sp120) : "$vf10", "$vf11", "memory");
                                }
                            }
                        }
                    }
                    func_003c22f0(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18));
                    if ((*(u16 *)e0 & 4) != 0) {
                        *(u16 *)(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18) + 0xC) |= 1;
                    }
                    *(s32 *)(list + 4) += 1;
                } else {
                    *(s32 *)(list + 4) = -1;
                    if (divisor > 0) {
                        u32 rnd = func_004bd050(0);
                        *(s32 *)(list + 4) -= (s32)(rnd % (u32)divisor);
                    }
                    goto outer_next;
                }
            }
            *(s32 *)(list + 4) += 1;
outer_next:
            i++;
            list += 0xC;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497ce0);
#endif


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
