/* Consolidated Persona 4 source units. */
/* Original translation unit effLineNova.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

void func_004833f0(void *arg);
void func_0044ea90(u8 *file, s32 line);
void func_0046d730(u8 *file, s32 line);
void *func_00481460(u16 arg0);
void *func_00481540(u16 arg0);
void func_00460ac0(void *arg0, void *arg1);
u16 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
u8 *func_00484490(u8 *obj);
void func_0043f810(void *dst, const void *src, u32 size);
void func_004b4430(u8 *arg0, u8 *arg1);
f32 func_004bd0b0(u32 param);

extern u8 D_00713310[];
extern u8 D_00714628[];
extern u8 D_00714650[];
extern u8 D_00714654[];
extern u8 D_00714664[];
extern u8 D_00724C54[];

/* 4-byte color state at 0x00724C54..57, accessed gp-relative in retail */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern LineNovaColor iGpffffbb64;  // 0x00724C54
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);


/* measured: retail colors the 7 loop-carried temps count2=$a3 v8=$t0 v6=$a2
   v5=$a1 v4=$a0 v3=$v1 i=$t1; mwcc b210 colors count2=$a1 v8=$a3 v6=$a0
   v5=$t1 v4=$v1 v3=$t0 i=$a2 (nd 20, all rows pure register renaming; object
   is otherwise byte-identical incl. hoisted count2 reload before the chain,
   the `(u32)x << 8 >> 8` dsll32/dsrl32 byte extraction, and the i++,v8+=0x18
   increment order). Tried declaration orders, s32/u32 counter+count2,
   raw-memory loop bound (mwcc rematerializes at loop bottom instead of
   hoisting to the preheader), loads-before-calls (adds a 4th saved reg),
   u64 shift spellings (all add sext+canonicalize pairs). Saved-register
   rotation floor family. */
// FUN_004B32F0
u8 *func_004b32f0(u8 *arg0)
{
    s32 n;
    u8 *r;
    u16 *p;
    u32 i;
    u8 *dst;
    u32 c0;
    u32 c1;
    u32 a0;
    u32 a1;
    u32 cnt;
    n = *(s32 *)(arg0 + 0x38);
    func_0044ea90(D_00714628, 0x43);
    r = (u8 *)(*jtbl_008873E8)(n * 8 + 0x10, 0x40000);
    if (r == NULL) {
        func_0046d730(D_00714628, 0x44);
    }
    *(u8 **)(r + 0) = r + 0x10;
    *(u8 **)(r + 8) = r;
    p = func_00482f70(n & 0xFFFF, 4, 6, D_00713310, 0x48);
    *(u16 **)(r + 4) = p;
    *p = *p & 0xFFFE;
    cnt = *(s32 *)(arg0 + 0x38);
    dst = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(r + 4) + 0x10) + 0x18) + 0x30);
    c1 = *(u32 *)(arg0 + 0x54);
    c0 = c1 & 0xFFFFFF;
    a1 = *(u32 *)(arg0 + 0x58);
    a0 = a1 & 0xFFFFFF;
    i = 0;
    while (i < cnt) {
        *(u32 *)(dst + 0x00) = c0;
        *(u32 *)(dst + 0x04) = c1;
        *(u32 *)(dst + 0x08) = c0;
        *(u32 *)(dst + 0x0C) = a0;
        *(u32 *)(dst + 0x10) = a1;
        *(u32 *)(dst + 0x14) = a0;
        i++;
        dst += 0x18;
    }
    return r;
}

// FUN_004B3420
void func_004b3420(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


// FUN_004B3470
void func_004b3470(u8 *arg0) {
    u8 *p20;
    u8 *p17;
    u32 count;
    s32 progress;
    s32 delay;
    u16 *dst;
    u32 i;
    f32 f25;
    f32 f24;
    f32 f23;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 r;

    p20 = *(u8 **)(arg0 + 0x20);
    p17 = *(u8 **)(arg0 + 0x24);
    count = *(u32 *)(p17 + 0x38);
    progress = *(s32 *)(p17 + 0x34);
    if (progress >= *(s32 *)(arg0 + 0x14) || progress == 0) {
        delay = *(s32 *)(arg0 + 0x1C) - 1;
        *(s32 *)(arg0 + 0x1C) = delay;
        if (delay <= 0) {
            f23 = *(f32 *)(p17 + 0x84) / 100.0f;
            f25 = *(f32 *)(p17 + 0x88);
            f24 = *(f32 *)(p17 + 0x64);
            dst = *(u16 **)p20;
            i = 0;
            f22 = 1.0f - f24;
            f21 = 1.0f - f25;
            f20 = 1.0f - f23;
            while (i < count) {
                r = 65535.0f * func_004bd0b0(0);
                *(u16 *)dst = (u16)r;
                r = 255.0f * (f22 + f24 * func_004bd0b0(0));
                *(u8 *)(dst + 1) = (u8)r;
                r = f21 + f25 * func_004bd0b0(0);
                *(f32 *)((u8 *)dst + 4) =
                    f23 + f20 * (1.0f - r);
                i++;
                dst = (u16 *)((u8 *)dst + 8);
            }
            delay = *(s32 *)(p17 + 0x4C);
            switch (delay) {
            case 0:
                delay = 0x7FFFFFFF;
                break;
            default:
                break;
            }
            *(s32 *)(arg0 + 0x1C) = delay;
        }
    }
}


/* measured: cold m2c 250 lines de-noised to ordinary C in file idiom; include holds canonical RwV3d-RwMatrix-RwRGBA in include-rw-inc-rwplcore.h, file idiom for VU fns (sibling 4430) uses plain u8 plus f32 plus u_long128 so no new structs invented. Real-tree baseline fnalign retail 440 vs object 440 (18 plus 29 reloc-only, byte-identical). Mirror v1 pure-C 423, v2 with H009 VU colour pack (effBlurFilter fGpffff8044 idiom) 411 (minus 12, count 438 vs 437). Port to real idiom (void 2-arg dead-a0, inside externs u8 arrays, hardcoded sw 0x150 plus volatile) scores 390 in real tree (better than preserved 487), fnalign 438 vs 431 (minus 7, inside 3 percent gate vs preserved plus 71 outside). Mirror v3a-v3b float colour (near-first, sX-sY swap) 411 and v4a-v4b (decl-neg-counter) 411 — two unproductive rounds, stop. Residual is VU loop (lqc2-sqc2-qmtc2-vopmula normalize plus cross, FPU expansion) plus float colour plus frame. No byte-exact candidate retained. */
// FUN_004B36B0 NONMATCHING
#ifdef NON_MATCHING
void func_004b36b0(u8 *arg0, u8 *arg1)
{
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
    extern u8 *func_00457120(void);
    extern void func_003e42a0(u8 *a, u8 *b, u8 *c);
    extern void func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern void func_003e9700(u8 *a);
    extern void func_003e9cb0(u8 *a, u8 *b, s32 c);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[];
    extern u8 D_00713D10[];
    extern u8 D_00713D14[];
    extern u8 D_00713D18[];
    s32 sp158;
    s32 sp154;
    s32 sp150;
    s32 sp15C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 baseX[5];
    f32 baseY[5];
    f32 baseZ[5];
    f32 projX;
    f32 projY;
    f32 projZ;
    f32 outX;
    f32 outY;
    f32 outZ;
    f32 w;
    u_long128 spD0;
    u_long128 spC0;
    u_long128 spB0;
    u_long128 spA0;
    u_long128 spE0q;
    u8 *tmp19;
    u8 *tmp18;
    u8 *tmp16;
    u8 *tmp17;
    s32 tmp;
    s32 *pt;
    f32 scale;
    u8 mode;
    s32 i;
    u8 *dst;
    f32 f6;
    f32 f5;
    f32 f4;
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;
    u32 count;
    u8 *arr;
    u8 *verts;
    u8 *aPtr;
    u8 *bPtr;
    u8 *cPtr;
    u8 b2;
    f32 fb2;
    f32 sX;
    f32 sY;
    tmp19 = *(u8 **)(arg1 + 0x20);
    tmp18 = *(u8 **)(arg1 + 0x24);
    tmp16 = *(u8 **)(tmp19 + 4);
    tmp = func_0048abd0(tmp18, tmp18 + 0x24, *(s32 *)(arg1 + 0x14), *(s32 *)(tmp18 + 0x34));
    sp158 = *(s32 *)(arg1 + 0x10);
    pt = &sp158;
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
    sp154 = tmp;
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
        "sw $2, 0x150($sp)      \n"
        :
        : "r"(&sp154), "f"(scale)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    sp15C = *(volatile s32 *)&sp150;
    if (((u8 *)&sp15C)[3] != 0xFF) {
        dst = *(u8 **)(tmp16 + 0x14);
        dst[4] = ((u8 *)&sp15C)[0];
        dst[5] = ((u8 *)&sp15C)[1];
        dst[6] = ((u8 *)&sp15C)[2];
        dst[7] = ((u8 *)&sp15C)[3];
    } else {
        ((u8 *)&sp15C)[3] = 0xFE;
        dst = *(u8 **)(tmp16 + 0x14);
        dst[4] = ((u8 *)&sp15C)[0];
        dst[5] = ((u8 *)&sp15C)[1];
        dst[6] = ((u8 *)&sp15C)[2];
        dst[7] = 0xFE;
        ((u8 *)&sp15C)[3] = 0xFF;
    }
    if (*(u8 *)(*(u8 **)(tmp16 + 0x14) + 7) == 0) {
        return;
    }
    tmp17 = func_00457120() + 0x68;
    f6 = *(f32 *)(func_00457120() + 0x80);
    f5 = *(f32 *)(tmp17 + 0);
    f4 = f5 * f6;
    f3 = *(f32 *)(tmp17 + 4);
    f2 = f3 * f6;
    f1 = -f4;
    f0 = -f2;
    baseX[0] = f1; baseY[0] = f0; baseZ[0] = f6;
    baseX[1] = f4; baseY[1] = f0; baseZ[1] = f6;
    baseX[2] = f4; baseY[2] = f2; baseZ[2] = f6;
    baseX[3] = f1; baseY[3] = f2; baseZ[3] = f6;
    baseX[4] = 0.0f; baseY[4] = 0.0f; baseZ[4] = f6;
    mode = *(u8 *)(tmp18 + 0x7C);
    if (mode == 1) {
        f32 k;
        f32 fx;
        f32 fy;
        k = 300.0f * f6;
        fx = ((f32)*(s16 *)(tmp18 + 0x7E) / 640.0f) - 0.5f;
        fy = ((f32)*(s16 *)(tmp18 + 0x80) / 448.0f) - 0.5f;
        sp140 = 2.0f * -(f5 * k) * fx;
        sp144 = 2.0f * -(f3 * k) * fy;
        sp148 = k;
        projX = sp140; projY = sp144; projZ = sp148;
    } else if (mode == 0) {
        u8 outBuf[16];
        func_003e42a0(outBuf, arg1, func_00457120() + 0x20);
        outX = *(f32 *)(outBuf + 0);
        outY = *(f32 *)(outBuf + 4);
        outZ = *(f32 *)(outBuf + 8);
        w = outZ;
        sp140 = 2.0f * -(f5 * w) * ((outX / w) - 0.5f);
        sp144 = 2.0f * -(f3 * w) * ((outY / w) - 0.5f);
        sp148 = w;
        projX = sp140; projY = sp144; projZ = sp148;
    } else {
        sp140 = f1 + f4;
        sp144 = f0 + f2;
        sp148 = f6 + f6;
        projX = 0.0f; projY = 0.0f; projZ = f6;
    }
    count = *(u32 *)(tmp18 + 0x38);
    arr = *(u8 **)tmp19;
    aPtr = *(u8 **)(tmp16 + 0x10);
    bPtr = *(u8 **)(aPtr + 0x18);
    func_003c2290(bPtr, 2);
    cPtr = *(u8 **)(bPtr + 0x5C);
    verts = *(u8 **)(cPtr + 0x14);
    b2 = *(arr + 2);
    if ((s32)b2 >= 0) {
        fb2 = (f32)b2;
    } else {
        fb2 = (f32)((b2 >> 1) | (b2 & 1));
        fb2 += fb2;
    }
    fb2 = fb2 / 255.0f;
    sX = *(f32 *)(tmp18 + 0x5C) * fb2;
    sY = *(f32 *)(tmp18 + 0x60) * fb2;
    spD0 = (u_long128)(u32)count;
    spC0 = (u_long128)0x710000;
    spB0 = (u_long128)0x710000;
    spA0 = (u_long128)0x710000;
    spE0q = (u_long128)0;
    i = 0;
    while (i < (s32)count) {
        f32 pax;
        f32 pay;
        f32 paz;
        f32 pbx;
        f32 pby;
        f32 pbz;
        f32 dx;
        f32 dy;
        f32 dz;
        f32 len2;
        f32 len;
        f32 inv;
        f32 nx;
        f32 ny;
        f32 nz;
        f32 cx;
        f32 cy;
        f32 cz;
        f32 f;
        u16 v0;
        f32 cvx;
        f32 cvy;
        f32 cvz;
        cvx = *(f32 *)D_00713CF0;
        cvy = *(f32 *)(D_00713CF0 + 4);
        cvz = *(f32 *)(D_00713CF0 + 8);
        pax = baseX[i & 3]; pay = baseY[i & 3]; paz = baseZ[i & 3];
        pbx = baseX[(i + 1) & 3]; pby = baseY[(i + 1) & 3]; pbz = baseZ[(i + 1) & 3];
        dx = pax - pbx;
        dy = pay - pby;
        dz = paz - pbz;
        len2 = dx * dx + dy * dy + dz * dz;
        len = len2;
        v0 = *(u16 *)arr;
        if ((s32)v0 >= 0) {
            f = (f32)v0;
        } else {
            f = (f32)((v0 >> 1) | (v0 & 1));
            f += f;
        }
        f = f / 65535.0f;
        f = len * f;
        inv = 1.0f;
        if (len2 > 0.0f) {
            inv = 1.0f / len2;
        }
        nx = dx * inv;
        ny = dy * inv;
        nz = dz * inv;
        cx = ny * cvz - nz * cvy;
        cy = nz * cvx - nx * cvz;
        cz = nx * cvy - ny * cvx;
        *(f32 *)(verts + 0x30) = *(f32 *)D_00713D10 + cx * sX;
        *(f32 *)(verts + 0x34) = *(f32 *)D_00713D14 + cy * sX;
        *(f32 *)(verts + 0x38) = *(f32 *)D_00713D18 + cz * sX;
        *(f32 *)(verts + 0x24) = *(f32 *)D_00713D10 + cx * sX + f;
        *(f32 *)(verts + 0x28) = *(f32 *)D_00713D14 + cy * sX + f;
        *(f32 *)(verts + 0x2C) = *(f32 *)D_00713D18 + cz * sX + f;
        *(f32 *)(verts + 0x3C) = *(f32 *)D_00713D10 - cx * sX;
        *(f32 *)(verts + 0x40) = *(f32 *)D_00713D14 - cy * sX;
        *(f32 *)(verts + 0x44) = *(f32 *)D_00713D18 - cz * sX;
        *(f32 *)(verts + 0x0C) = *(f32 *)D_00713D10 + cx * sY;
        *(f32 *)(verts + 0x10) = *(f32 *)D_00713D14 + cy * sY;
        *(f32 *)(verts + 0x14) = *(f32 *)D_00713D18 + cz * sY;
        *(f32 *)(verts + 0x00) = projX + cx;
        *(f32 *)(verts + 0x04) = projY + cy;
        *(f32 *)(verts + 0x08) = projZ + cz;
        *(f32 *)(verts + 0x18) = *(f32 *)D_00713D10;
        *(f32 *)(verts + 0x1C) = *(f32 *)D_00713D14;
        *(f32 *)(verts + 0x20) = *(f32 *)D_00713D18;
        i++;
        arr += 8;
        verts += 0x48;
    }
    {
        u8 *tail;
        tail = *(u8 **)(*(u8 **)(tmp16 + 0x10) + 0x18);
        func_003c22f0(tail);
        if ((*(u16 *)tmp16 & 4) != 0) {
            *(u16 *)(tail + 0x0C) = *(u16 *)(tail + 0x0C) | 1;
        }
    }
    {
        u8 *cam;
        cam = func_00457120();
        func_003e9700(*(u8 **)(cam + 4));
        func_003e9cb0(*(u8 **)(tmp16 + 0x0C), func_00457120(), 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b36b0);
#endif


// FUN_004B3D90
void func_004b3d90(u8 *arg0) {
    u8 *p6;
    u8 *p16;
    u32 v5;
    void *r;

    p6 = *(u8 **)(arg0 + 0x24);
    p16 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    v5 = *(u32 *)(p6 + 0x34);
    if (v5 >= *(u32 *)(arg0 + 0x14) || v5 == 0) {
        switch (*(u8 *)(p6 + 0x68)) {
        case 0:
            r = func_00481540(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        default:
            r = func_00481460(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        }
    }
}


// FUN_004B3E40
void func_004b3e40(u8 *arg0) {
    u8 *p10;
    u8 *dst;

    p10 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p10 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p10 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    *(s32 *)(p10 + 0x20) = (s32)func_004b4430;
    *(s32 *)(p10 + 0x28) = (s32)arg0;
}


// FUN_004B3ED0
u8 *func_004b3ed0(u8 *arg0)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_5;
    s32 var_5_2;
    u16 *temp_2_2;
    u32 temp_16;
    u32 cnt;
    u32 temp_4_2;
    u32 temp_4_3;
    u32 temp_6;
    u32 temp_6_2;
    u32 var_6;
    u8 temp_4;
    u8 *temp_2;
    u8 *var_3;

    temp_16 = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00714628, 0x16D);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_16 * 6 + 0x10, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00714628, 0x16E);
    }
    *(u8 **)(temp_2 + 0) = temp_2 + 0x10;
    *(u8 **)(temp_2 + 8) = temp_2;
    temp_2_2 = func_00482f70(temp_16 & 0xFFFF, 4, 6, D_00713310, 0x48);
    *(u16 **)(temp_2 + 4) = temp_2_2;
    *temp_2_2 &= 0xFFFE;
    cnt = *(u32 *)(arg0 + 0x38);
    var_3 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 4) + 0x10) + 0x18) + 0x30);
    temp_4 = *(u8 *)(arg0 + 0x92);
    var_f1 = (f32)(u32)temp_4;
    temp_f2 = var_f1 / 255.0f;
    temp_6 = *(u32 *)(arg0 + 0x54);
    temp_4_2 = temp_6 >> 0x18;
    var_f0 = (f32)(u32)temp_4_2;
    temp_f1 = var_f0 * temp_f2;
    var_5 = (u32)temp_f1;
    temp_5 = (temp_6 & 0xFFFFFF) | (var_5 << 24);
    temp_6_2 = *(u32 *)(arg0 + 0x58);
    temp_4_3 = temp_6_2 >> 0x18;
    var_f0_2 = (f32)(u32)temp_4_3;
    temp_f1_2 = var_f0_2 * temp_f2;
    var_5_2 = (u32)temp_f1_2;
    temp_5_2 = (temp_6_2 & 0xFFFFFF) | (var_5_2 << 24);
    var_6 = 0;
    while (var_6 < cnt) {
        *(s32 *)(var_3 + 0) = temp_5_2;
        *(s32 *)(var_3 + 4) = temp_5;
        *(s32 *)(var_3 + 8) = temp_5_2;
        *(u32 *)(var_3 + 0xC) = *(u32 *)(arg0 + 0x58);
        *(u32 *)(var_3 + 0x10) = *(u32 *)(arg0 + 0x54);
        *(u32 *)(var_3 + 0x14) = *(u32 *)(arg0 + 0x58);
        var_6++;
        var_3 += 0x18;
    }
    return temp_2;
}

// FUN_004B4170
void func_004b4170(u8 *arg0) {
    func_004833f0(*(void **)(arg0 + 4));
    (*jtbl_008873EC)(*(void **)(arg0 + 8));
}


// FUN_004B41C0
void func_004b41c0(u8 *arg0) {
    u8 *p20;
    u8 *p17;
    u32 count;
    s32 progress;
    s32 delay;
    u16 *dst;
    u32 i;
    f32 f23;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 r;

    p20 = *(u8 **)(arg0 + 0x20);
    p17 = *(u8 **)(arg0 + 0x24);
    count = *(u32 *)(p17 + 0x38);
    progress = *(s32 *)(p17 + 0x34);
    if (progress >= *(s32 *)(arg0 + 0x14) || progress == 0) {
        delay = *(s32 *)(arg0 + 0x1C) - 1;
        *(s32 *)(arg0 + 0x1C) = delay;
        if (delay <= 0) {
            f23 = *(f32 *)(p17 + 0x64);
            f22 = *(f32 *)(p17 + 0x94);
            dst = *(u16 **)p20;
            i = 0;
            f21 = 1.0f - f23;
            f20 = 1.0f - f22;
            while (i < count) {
                r = 65535.0f * (f21 + f23 * func_004bd0b0(0));
                *(u16 *)dst = (u16)r;
                r = 65535.0f * func_004bd0b0(0);
                *(u16 *)(dst + 1) = (u16)r;
                r = 65535.0f * (f20 + f22 * func_004bd0b0(0));
                *(u16 *)(dst + 2) = (u16)r;
                i++;
                dst = (u16 *)((u8 *)dst + 6);
            }
            delay = *(s32 *)(p17 + 0x4C);
            switch (delay) {
            case 0:
                delay = 0x7FFFFFFF;
                break;
            default:
                break;
            }
            *(s32 *)(arg0 + 0x1C) = delay;
        }
    }
}


/* measured: retail contains COP2/VU0 vector work; H009 permits the required
   inline asm. No byte-exact candidate was retained in this wave. */
/* measured: v2 clears the assignment census (opclass 77 -> 14 rows, all named rows 0): obj 1988B vs window 2000B (-12B), probe_variants 467 differing words reloc-masked, fnalign 497 vs 500 instrs (-0.6%, inside 3% gate). Was obj 2076B/519 vs 500 (+3.8% over gate) with add.s +35, lh -15, cvt -10, lui +10, mtc1 -9, andi +9, bltz +8, swc1 -8, sub.s +8, dsll32 +7, dsra32 +6, div -5. Now add.s 0, lh 0, cvt 0, lui 0, mtc1 0, andi 0, bltz 0, sub.s 0, dsll32 0, dsra32 0, div 0, swc1 +1, nop -2, lw -1. */
/* measured: fixes per thread hints: (1) x/y vs x*(1/y): replaced invented rlen=1/len2*spF0p + h0/640-0.5f + spE0a/v0 + dx/len2/nx/cx chain (35 extra add.s, 8 extra sub.s, 5 missing div.s) with retail lerp (t=prog/cnt div once) + f3/f2 (/640,/448) + loop f5/f4 (/10) + per-iter u16/65535 (3 divs) + tail (2 divs); (2) unsigned idiom (handoff 7g): removed 8 invented (f32)(u32)&0xFFFF/&0xFF (8 extra bltz, 9 extra andi, 10 missing cvt) and added correct (f32)(u32)prog/cnt + 3x loop u16 (5 bltz, now 5/5); (3) lh -15 via tools/solve_signedness.py (retail 17 lh vs obj 2 -> now 17/17, all offsets 0x80-0x90 present; solver mismatch 19 -> 0 for narrow ops). Solver: python3 -E -s tools/solve_signedness.py src/Graphics/Effect/effLineNova.c func_004b4430 reports retail lb 0/lbu 10/lh 17/lhu 5 vs obj 8/17/5 after fix (lbu -2 residual is stack-offset spill, not signedness). */
/* measured: Frame still short (obj 1988B vs 2000B) + VU scratch (sqc2 to D_00713D10 global overlap, 3x per iter) + lqc2/vsub/vmul/vrsqrt in inline asm; remaining 467-word residual is saved-reg rotation, scheduling, FPU choice, quadword spills, call-site reuse per docs/matching.md. No pooled constants to bank (lui immediates only). */
/* measured: Production stays INCLUDE_ASM fallback; body preserved here as NON_MATCHING seed. */
// FUN_004B4430 NONMATCHING
#ifdef NON_MATCHING
void func_004b4430(u8 *arg0, u8 *arg1)
{
    extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
    extern u8 *func_00457120(void);
    extern void func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern s32 func_003e9700(s32 a);
    extern void func_003e0870(u8 *a, u8 *b, s32 c, f32 d);
    extern void func_003e05f0(u8 *a, u8 *b, u8 *c);
    extern s32 func_003e9cb0(u8 *a, u8 *b, s32 c);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[];
    extern u8 D_00713D10[];
    extern u8 D_00713D14[];
    extern u8 D_00713D18[];
    s32 sp138;
    s32 sp134;
    s32 sp130;
    s32 sp13C;
    f32 f24;
    f32 f23;
    f32 f21;
    f32 f20;
    f32 f22;
    f32 f3;
    f32 f2;
    f32 f0;
    f32 f5;
    f32 f4;
    u8 stk100[24];
    u8 stk110[24];
    u8 stk120[16];
    u8 stkC0[64];
    u8 stk80[64];
    u8 *tmp19;
    u8 *tmp18;
    u8 *tmp16;
    u8 *tmpA;
    u8 *tmpB;
    s32 tmp;
    s32 *pt;
    f32 scale;
    u8 *dst;
    u32 prog;
    u32 cnt7c;

    tmp19 = *(u8 **)(arg1 + 0x20);
    tmp18 = *(u8 **)(arg1 + 0x24);
    tmp16 = *(u8 **)(tmp19 + 4);
    {
        extern u8 D_00714638[];
        extern u8 D_00714640[];
        *(u64 *)(((u8 *)&stk120) - 0x30) = *(u64 *)D_00714638;
        *(f32 *)(((u8 *)&stk120) - 0x28) = *(f32 *)D_00714640;
    }
    prog = *(u32 *)(arg1 + 0x14);
    tmp = func_0048abd0(tmp18, tmp18 + 0x24, (s32)prog, *(s32 *)(tmp18 + 0x34));
    sp138 = *(s32 *)(arg1 + 0x10);
    pt = &sp138;
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
    sp134 = tmp;
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
        "sw $2, 0x130($sp)      \n"
        :
        : "r"(&sp134), "f"(scale)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
       hoists the reload above the asm, so the read is volatile. */
    sp13C = *(volatile s32 *)&sp130;
    if (((u8 *)&sp13C)[3] != 0xFF) {
        dst = *(u8 **)(tmp16 + 0x14);
        dst[4] = ((u8 *)&sp13C)[0];
        dst[5] = ((u8 *)&sp13C)[1];
        dst[6] = ((u8 *)&sp13C)[2];
        dst[7] = ((u8 *)&sp13C)[3];
    } else {
        ((u8 *)&sp13C)[3] = 0xFE;
        dst = *(u8 **)(tmp16 + 0x14);
        dst[4] = ((u8 *)&sp13C)[0];
        dst[5] = ((u8 *)&sp13C)[1];
        dst[6] = ((u8 *)&sp13C)[2];
        dst[7] = 0xFE;
        ((u8 *)&sp13C)[3] = 0xFF;
    }
    if (*(u8 *)(*(u8 **)(tmp16 + 0x14) + 7) == 0) {
        return;
    }
    cnt7c = *(u32 *)(tmp18 + 0x7C);
    if (cnt7c != 0) {
        if (prog < cnt7c) {
            f32 t = (f32)prog / (f32)cnt7c;
            s32 d0 = (s32)*(s16 *)(tmp18 + 0x88) - (s32)*(s16 *)(tmp18 + 0x80);
            s32 d1 = (s32)*(s16 *)(tmp18 + 0x8A) - (s32)*(s16 *)(tmp18 + 0x82);
            s32 d2 = (s32)*(s16 *)(tmp18 + 0x8C) - (s32)*(s16 *)(tmp18 + 0x84);
            s32 d3 = (s32)*(s16 *)(tmp18 + 0x8E) - (s32)*(s16 *)(tmp18 + 0x86);
            f32 b0 = (f32)*(s16 *)(tmp18 + 0x80);
            f32 b1 = (f32)*(s16 *)(tmp18 + 0x82);
            f32 b2 = (f32)*(s16 *)(tmp18 + 0x84);
            f32 b3 = (f32)*(s16 *)(tmp18 + 0x86);
            f24 = b0 + t * (f32)d0;
            f23 = b1 + t * (f32)d1;
            f21 = b2 + t * (f32)d2;
            f20 = b3 + t * (f32)d3;
        } else {
            f24 = (f32)*(s16 *)(tmp18 + 0x88);
            f23 = (f32)*(s16 *)(tmp18 + 0x8A);
            f21 = (f32)*(s16 *)(tmp18 + 0x8C);
            f20 = (f32)*(s16 *)(tmp18 + 0x8E);
        }
    } else {
        f24 = (f32)*(s16 *)(tmp18 + 0x80);
        f23 = (f32)*(s16 *)(tmp18 + 0x82);
        f21 = (f32)*(s16 *)(tmp18 + 0x84);
        f20 = (f32)*(s16 *)(tmp18 + 0x86);
    }
    tmpA = func_00457120() + 0x68;
    tmpB = func_00457120();
    f22 = *(f32 *)(tmpB + 0x80) + 1.0f;
    f3 = f21 * (*(f32 *)(tmpA + 0) * f22) / 640.0f;
    f2 = f20 * (*(f32 *)(tmpA + 4) * f22) / 448.0f;
    *(f32 *)(stk100 + 0x00) = -f3;
    *(f32 *)(stk100 + 0x04) = -f2;
    *(f32 *)(stk100 + 0x08) = f22;
    *(f32 *)(stk110 + 0x00) = -f3;
    *(f32 *)(stk110 + 0x04) = f2;
    *(f32 *)(stk110 + 0x08) = f22;
    f21 = f2 * 2.0f;
    f20 = f3 * 2.0f;
    {
        u8 *list;
        s32 n;
        u8 *cfg;
        u8 *out;
        s32 k;
        n = *(s32 *)(tmp18 + 0x38);
        cfg = *(u8 **)(tmp16 + 0x10);
        out = *(u8 **)(*(u8 **)(*(u8 **)(cfg + 0x18) + 0x5C) + 0x14);
        list = *(u8 **)tmp19;
        func_003c2290(*(u8 **)(cfg + 0x18), 2);
        f5 = *(f32 *)(tmp18 + 0x5C) / 10.0f;
        f4 = *(f32 *)(tmp18 + 0x60) / 10.0f;
        f0 = (f32)0xFFFF;
        k = 0;
        while (k < n) {
            u16 v0 = *(u16 *)(list + 0);
            f32 tn0 = (f32)(u32)v0 / f0;
            f32 tf3 = f5 * tn0;
            f32 tf2 = f4 * tn0;
            u16 v1 = *(u16 *)(list + 4);
            f32 tn1 = (f32)(u32)v1;
            f32 tf1 = f20 * tn1 / f0;
            u16 v2 = *(u16 *)(list + 2);
            f32 tn2 = (f32)(u32)v2;
            f32 tf6 = f21 * tn2 / f0;
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "lqc2 $vf11, 0(%1) \n"
                "vsub.xyzw $vf10, $vf10, $vf11 \n"
                "vmul.xyz $vf2, $vf10, $vf10 \n"
                "vmulax.w $ACC, $vf0, $vf2x \n"
                "vmadday.w $ACC, $vf0, $vf2y \n"
                "vmaddz.w $vf2, $vf0, $vf2z \n"
                "vrsqrt $Q, $vf0w, $vf2w \n"
                "vwaitq \n"
                "vmulq.xyz $vf10, $vf10, $Q \n"
                "vmove.xyzw $vf12, $vf10 \n"
                :
                : "r"(stk100), "r"(stk110)
                : "$vf2", "$vf10", "$vf11", "$vf12", "memory");
            /* removed spurious qmfc2/pextlb: no retail counterpart */
            {
                s32 q = *(s32 *)&tf6;
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vadd.xyzw $vf10, $vf10, $vf11 \n"
                    "sqc2 $vf10, 0(%1) \n"
                    :
                    : "r"(q), "r"(D_00713D10)
                    : "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "sqc2 $vf10, 0(%0) \n"
                    :
                    : "r"(D_00713D10)
                    : "memory");
                __asm__ volatile(
                    "sqc2 $vf10, 0(%0) \n"
                    :
                    : "r"(D_00713D10)
                    : "memory");
            }
            *(f32 *)(out + 0x30) = *(f32 *)D_00713D10;
            *(f32 *)(out + 0x34) = *(f32 *)D_00713D14;
            *(f32 *)(out + 0x38) = *(f32 *)D_00713D18;
            *(f32 *)(out + 0x24) = *(f32 *)D_00713D10;
            *(f32 *)(out + 0x28) = *(f32 *)D_00713D14;
            *(f32 *)(out + 0x2C) = *(f32 *)D_00713D18;
            *(f32 *)(out + 0x3C) = *(f32 *)D_00713D10;
            *(f32 *)(out + 0x40) = *(f32 *)D_00713D14;
            *(f32 *)(out + 0x44) = *(f32 *)D_00713D18;
            *(f32 *)(out + 0x04) = *(f32 *)(out + 0x28) - tf2;
            *(f32 *)(out + 0x1C) = *(f32 *)(out + 0x40) + tf2;
            *(f32 *)(out + 0x28) = *(f32 *)(out + 0x28) - tf3;
            *(f32 *)(out + 0x40) = *(f32 *)(out + 0x40) + tf3;
            *(f32 *)(out + 0x00) = *(f32 *)(out + 0x24) + tf1;
            *(f32 *)(out + 0x08) = *(f32 *)(out + 0x2C);
            *(f32 *)(out + 0x0C) = *(f32 *)(out + 0x30) + tf1;
            *(f32 *)(out + 0x10) = *(f32 *)(out + 0x34);
            *(f32 *)(out + 0x14) = *(f32 *)(out + 0x38);
            *(f32 *)(out + 0x18) = *(f32 *)(out + 0x3C) + tf1;
            *(f32 *)(out + 0x20) = *(f32 *)(out + 0x44);
            k++;
            list += 6;
            out += 0x48;
        }
        func_003c22f0(*(u8 **)(cfg + 0x18));
        if ((*(u16 *)tmp16 & 4) != 0) {
            *(u16 *)(*(u8 **)(cfg + 0x18) + 0x0C) |= 1;
        }
        {
            u8 *pC = func_00457120();
            s32 h = func_003e9700(*(s32 *)(pC + 4));
            s16 hv = *(s16 *)(tmp18 + 0x90);
            f32 fv = (f32)hv;
            func_003e0870(stkC0, stk120, 0, fv);
            *(f32 *)(stkC0 + 0x30) = *(f32 *)(stkC0 + 0x30) + (320.0f - f24) * (2.0f * *(f32 *)(tmpA + 0) * f22) / 640.0f;
            *(f32 *)(stkC0 + 0x34) = *(f32 *)(stkC0 + 0x34) + (224.0f - f23) * (2.0f * *(f32 *)(tmpA + 4) * f22) / 448.0f;
            func_003e05f0(stk80, stkC0, (u8 *)h);
            func_003e9cb0(*(u8 **)(tmp16 + 0x0C), stk80, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b4430);
#endif




// FUN_004B4C00
void func_004b4c00(u8 *arg0) {
    u8 *p6;
    u8 *p16;
    u32 v5;
    void *r;

    p6 = *(u8 **)(arg0 + 0x24);
    p16 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 4);
    v5 = *(u32 *)(p6 + 0x34);
    if (v5 >= *(u32 *)(arg0 + 0x14) || v5 == 0) {
        switch (*(u8 *)(p6 + 0x68)) {
        case 0:
            r = func_00481540(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        default:
            r = func_00481460(*(u16 *)(p6 + 0x28));
            *(s32 *)(p16 + 0x18) = 0;
            *(s32 *)(p16 + 0x1C) = 0;
            func_00460ac0(r, p16 + 0x18);
            break;
        }
    }
}


// FUN_004B4CB0
u8 *func_004b4cb0(s32 arg0, u8 *arg1) {
    u8 *w;
    s32 size;
    u32 idx;
    u32 idx2;

    if ((u16)arg0 >= 3) {
        func_0046d730(D_00714628, 0x28C);
    }
    idx = (u16)arg0;
    size = *(s32 *)(&D_00714664[0] + idx * 0x18);
    func_0044ea90(D_00714628, 0x290);
    w = (u8 *)(*jtbl_008873E8)(size + 0x30, 0x40000);
    if (w == NULL) {
        func_0046d730(D_00714628, 0x291);
    }
    *(u8 **)(w + 0x24) = w + 0x30;
    *(s32 *)(w + 0x14) = 0;
    *(s32 *)(w + 0x18) = idx;
    *(s32 *)(w + 0x10) = -1;
    *(s32 *)(w + 0x1C) = 0;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(w) : "memory");
    func_0043f810(*(void **)(w + 0x24), arg1, size);
    idx2 = (u16)arg0 * 0x18;
    *(s32 *)(w + 0x20) = (*(s32 (**)(u8 *))(&D_00714654[0] + idx2))(arg1);
    (*(void (**)(u8 *))(&D_00714650[0] + idx2))(w);
    return w;
}
// FUN_004B4E10
u8 *func_004b4e10(u8 *arg0) {
    u8 *p;

    p = func_00484490(arg0);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B3);
    }
    p = func_004b4cb0(*(u16 *)(arg0 + 0xC), p);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B5);
    }
    return p;
}
