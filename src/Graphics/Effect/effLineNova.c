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
s32 func_004b4430(u8 *arg1);
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


/* measured: floor for func_004b36b0 (obj 2044B vs window 1760B, probe_variants 487 differing words reloc-masked, fnalign 511 vs 440 instrs). */
/* measured: Frame 0xC0 vs retail 0x160 (-160B, saved-reg + quadword-slot floor); logic confirmed against retail asm (asm/nonmatchings/effLineNova/func_004b36b0.s via `grep -rl func_004b36b0 asm/`), */
/* measured: IDA/Ghidra and M2C P4_UNIT_004B36B0 in src/generated/code1_004b.c (500+ draft lines, noise from M2C_ERROR VU blocks): 2-arg (unused, work) signature (retail uses $a1 primary, $a0 dead), */
/* measured: 3-phase colour (arg+0x10 via scale to vf11, tmp via scale*vf11 to 0x437F pack to 0x150->0x15C, FE/FF branch), early exit on *(0x14+7)==0, dual func_00457120 + float array, switch on 0x7C, loop via 003c2290, VU normalize/cross in plain C + 18 D_00713D10 constants + quadword bases, tail 003c22f0/003e9700/003e9cb0. */
/* measured: Sibling conventions read first: effLineNova.c func_004b3d90/004b3e40/004b41c0 and effBlurFilter.c func_004a93d0 colour-unpack (copied verbatim including hard-coded sw $2,0x150($sp) and volatile reload). */
/* measured: Residual is compiler floor per docs/matching.md: saved-reg rotation, scheduling, FPU choice (plain-C mul/add for retail vopmula/vopmsub/vmul/vsub/vrsqrt, 2 VF->9 FPU expansion), quadword spills (retail sq/lq vs b210 sw), call-site reuse. Exhausted u_long128 per 16B slot, volatile reload, mode switch forms. */
/* measured: No pooled float constants to bank (only lui 0x437F/0x3F80/0x4000 immediates, no gp loads; D_00713D10 etc. absolute lui bases, already extern). Unit confirmed via `grep -rl func_004b36b0 asm/` -> asm/nonmatchings/effLineNova/func_004b36b0.s. */
/* measured: Production stays INCLUDE_ASM fallback; body preserved here as NON_MATCHING seed. */
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
    f32 spF0a;
    f32 spF0b;
    f32 spF0c;
    f32 spF0d;
    f32 spF0e;
    f32 spF0f;
    f32 spF0g;
    f32 spF0h;
    f32 spF0i;
    f32 spF0j;
    f32 spF0k;
    f32 spF0l;
    f32 spF0m;
    f32 spF0n;
    f32 spF0o;
    f32 spF0p;
    f32 spE8;
    f32 spE4;
    f32 spE0a;
    f32 spE0b;
    f32 spE0c;
    f32 spE0d;
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
    /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
       hoists the reload above the asm, so the read is volatile. */
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
    spF0a = f1;
    spF0b = -f2;
    spF0c = f6;
    spF0d = f4;
    spF0e = -f2;
    spF0f = f6;
    spF0g = f4;
    spF0h = f2;
    spF0i = f6;
    spF0j = f1;
    spF0k = f2;
    spF0l = f6;
    spF0m = 0.0f;
    spF0n = 0.0f;
    spF0o = f6;
    spF0p = f1 + f2 + f6 + spF0a + spF0b + spF0c;
    mode = *(u8 *)(tmp18 + 0x7C);
    if (mode == 1) {
        f32 base300 = 300.0f * f6;
        f32 h0 = (f32)*(s16 *)(tmp18 + 0x7E);
        f32 h1 = (f32)*(s16 *)(tmp18 + 0x80);
        sp140 = 2.0f * -f5 * ((h0 / 640.0f) - 0.5f);
        sp144 = 2.0f * -f3 * ((h1 / 448.0f) - 0.5f);
        sp148 = base300 + spF0p;
    } else if (mode == 0) {
        u8 *e0 = (u8 *)&spE0q;
        f32 v0;
        f32 v1;
        func_003e42a0(e0, arg1, func_00457120() + 0x20);
        v0 = spE8;
        v1 = spE4;
        spE0a = v0;
        spE0b = v1;
        spE0c = spE0a + spE0b;
        spE0d = spE0c * 2.0f;
        sp140 = 2.0f * -(f5 * v0) * ((spE0a / v0) - 0.5f) + spF0m;
        sp144 = 2.0f * -(f3 * v0) * ((v1 / v0) - 0.5f) + spF0n;
        sp148 = v0 + spF0o + spE0d;
    } else {
        sp140 = spF0a + spF0d + f4;
        sp144 = spF0b + spF0e + f2;
        sp148 = spF0c + spF0f + f6;
    }
    {
        u8 *nobj = *(u8 **)tmp19;
        s32 n = *(s32 *)(tmp18 + 0x38);
        u8 *cfg = *(u8 **)(tmp16 + 0x10);
        u8 *out = *(u8 **)(*(u8 **)(cfg + 0x18) + 0x5C);
        s32 cnt = *(s32 *)(out + 0x14);
        u8 *list = *(u8 **)nobj;
        s32 k = 0;
        spD0 = (u_long128)(u32)n;
        spC0 = (u_long128)0x710000;
        spB0 = (u_long128)0x710000;
        spA0 = (u_long128)0x710000;
        spE0q = (u_long128)0;
        func_003c2290(*(u8 **)(cfg + 0x18), 2);
        {
            f32 t0 = (f32)((u32)spD0 & 0xFFFF);
            f32 t1 = (f32)((u32)spC0 & 0xFFFF);
            f32 t2 = (f32)((u32)spB0 & 0xFFFF);
            f32 t3 = (f32)((u32)spA0 & 0xFFFF);
            f32 t4 = (f32)((u32)spE0q & 0xFFFF);
            spF0p = t0 + t1 + t2 + t3 + t4 + sp140 + sp144 + sp148;
        }
        while (k < n) {
            f32 dx;
            f32 dy;
            f32 dz;
            f32 len2;
            f32 rlen;
            f32 nx;
            f32 ny;
            f32 nz;
            f32 cx;
            f32 cy;
            f32 cz;
            dx = spF0a - spF0d + *(f32 *)(out + 0x30);
            dy = spF0b - spF0e + *(f32 *)(out + 0x34);
            dz = spF0c - spF0f + *(f32 *)(out + 0x38);
            len2 = dx * dx + dy * dy + dz * dz;
            rlen = 1.0f / len2;
            rlen = rlen * spF0p;
            nx = dx * rlen + sp140;
            ny = dy * rlen + sp144;
            nz = dz * rlen + sp148;
            cx = spF0g * nz - spF0h * ny;
            cy = spF0h * nx - spF0g * nz;
            cz = spF0g * ny - spF0h * nx;
            *(f32 *)(out + 0x30) = *(f32 *)D_00713D10 + cx;
            *(f32 *)(out + 0x34) = *(f32 *)D_00713D14 + cy;
            *(f32 *)(out + 0x38) = *(f32 *)D_00713D18 + cz;
            *(f32 *)(out + 0x24) = *(f32 *)D_00713D10 + nx;
            *(f32 *)(out + 0x28) = *(f32 *)D_00713D14 + ny;
            *(f32 *)(out + 0x2C) = *(f32 *)D_00713D18 + nz;
            *(f32 *)(out + 0x3C) = *(f32 *)D_00713D10 - nx;
            *(f32 *)(out + 0x40) = *(f32 *)D_00713D14 - ny;
            *(f32 *)(out + 0x44) = *(f32 *)D_00713D18 - nz;
            *(f32 *)(out + 0x0C) = *(f32 *)D_00713D10 + spF0j;
            *(f32 *)(out + 0x10) = *(f32 *)D_00713D14 + spF0k;
            *(f32 *)(out + 0x14) = *(f32 *)D_00713D18 + spF0l;
            *(f32 *)(out + 0x00) = *(f32 *)D_00713D10 + spF0m;
            *(f32 *)(out + 0x04) = *(f32 *)D_00713D14 + spF0n;
            *(f32 *)(out + 0x08) = *(f32 *)D_00713D18 + spF0o;
            *(f32 *)(out + 0x18) = *(f32 *)D_00713D10 + (f32)((u32)spC0 & 0xFF);
            *(f32 *)(out + 0x1C) = *(f32 *)D_00713D14 + (f32)((u32)spB0 & 0xFF);
            *(f32 *)(out + 0x20) = *(f32 *)D_00713D18 + (f32)((u32)spA0 & 0xFF);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&spE0q) : "memory");
            k++;
            list += 8;
            out += 0x48;
        }
        func_003c22f0(*(u8 **)(cfg + 0x18));
        if ((*(u16 *)tmp16 & 4) != 0) {
            *(u16 *)(*(u8 **)(cfg + 0x18) + 0x0C) |= 1;
        }
        func_003e9700(*(u8 **)(func_00457120() + 4));
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
// FUN_004B4430
INCLUDE_ASM("asm/nonmatchings/effLineNova", func_004b4430);


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
