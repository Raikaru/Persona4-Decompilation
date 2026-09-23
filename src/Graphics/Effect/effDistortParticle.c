#include "include_asm.h"
/* Persona 4 USA decompilation - effDistortParticle.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00714538[];
extern char D_00714550[];

extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern void *memset(void *dest, s32 value, s32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern void func_00492cd0(void *ptr);
extern u8 *func_00484490(void);
extern s32 func_004844d0(void *obj);
extern u8 *func_00492b20(u32 arg0, s32 arg1, u8 *arg2);
extern void func_00492d10(void *ptr);
extern s32 func_00481300(u16 param);
extern void func_00492df0(void *arg0, void *arg1);
extern void func_00492db0(void *arg0, void *arg1);
extern s32 effMiscRand(s32 arg0);
extern s32 func_004afe20(u8 *arg0, u8 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
extern void func_004bceb0(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern f32 effMiscRandFloat(u32 arg0);
extern f32 fGpffff8080;
extern f32 fGpffff8098;
extern f32 fGpffff809c;
extern s32 iGpffff81f4; /* 0x007612E4 */
void func_004afc80(u8 *arg0, u8 *arg1);
void func_004afb10(u8 *arg0, u32 arg1, u8 *arg2);
void func_004afa60(u8 *arg0, s32 arg1);
void func_004afaa0(u8 *arg0, u8 *arg1);
extern s32 func_00481390();

// FUN_004AF680
u8 *func_004af680(u32 arg0) {
    u8 *temp;

    func_0044ea90(D_00714538, 0x171);
    temp = (u8 *)(*jtbl_008873E8)(0x9C, 0x40000);
    memset(temp, 0, 0x9C);
    if (temp == NULL) {
        func_0046d730(D_00714550, 0x2F);
    }
    *(u32 *)(temp + 0) = arg0;
    *(s32 *)(temp + 4) = -1;
    *(u32 *)(temp + 8) = 0x3F800000;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    *(s16 *)(temp + 0x84) = 0x1A;
    *(u32 *)(temp + 0x88) = (u32)temp;
    return temp;
}

// FUN_004AF740
u8 *func_004af740(u8 *arg0) {
    s32 temp_3;
    u32 var_4;
    u8 *temp_2_2;
    u8 *temp_2;
    s32 temp_2_3;

    temp_2_2 = func_00484490();
    if (temp_2_2 == NULL) {
        func_0046d730(D_00714550, 0x69);
    }
    temp_3 = *(s32 *)(temp_2_2 + 0x68);
    if (temp_3 == 0) {
        var_4 = *(u32 *)(temp_2_2 + 0x100) * *(u32 *)(temp_2_2 + 0x6C);
    } else {
        var_4 = (u32)temp_3 * *(u32 *)(temp_2_2 + 0x6C);
    }
    if (var_4 > 0x64) {
        var_4 = 0x64;
    }
    temp_2 = func_004af680(var_4);
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0x6B);
    }
    memcpy(temp_2 + 0xC, temp_2_2, 0x48);
    func_004afb10(temp_2, *(u16 *)(arg0 + 0xC), temp_2_2 + 0x48);
    if (*(s32 *)(*(u8 **)(temp_2 + 0x5C) + 8) == 0) {
        return temp_2;
    }
    temp_2_3 = func_004844d0(arg0);
    if (temp_2_3 != 0) {
        switch (*(u16 *)(arg0 + 0x1C)) {
        case 1:
            func_004afa60(temp_2, temp_2_3);
            break;
        default:
            func_0046d730(D_00714550, 0x80);
            break;
        }
    }
    return temp_2;
}

// FUN_004AF8A0
void func_004af8a0(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x60);
    if (temp != NULL) {
        func_003ef3a0(temp);
    }
    temp = *(u8 **)(arg0 + 0x5C);
    if (temp != NULL) {
        func_00492cd0(temp);
    }
    temp = *(u8 **)(arg0 + 0x68);
    if (temp != NULL) {
        (*jtbl_008873EC)(temp);
    }
    (*jtbl_008873EC)(arg0);
}

// FUN_004AF920
u8 *func_004af920(u8 *arg0) {
    s32 temp_3;
    u32 var_4;
    u8 *temp_16;
    u8 *temp_2;

    if (*(u8 **)(arg0 + 0x5C) == NULL) {
        func_0046d730(D_00714550, 0xB3);
    }
    temp_16 = *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x24);
    if (temp_16 == NULL) {
        func_0046d730(D_00714550, 0xB5);
    }
    temp_3 = *(s32 *)(temp_16 + 0x20);
    if (temp_3 == 0) {
        var_4 = *(u32 *)(temp_16 + 0xB8) * *(u32 *)(temp_16 + 0x24);
    } else {
        var_4 = (u32)temp_3 * *(u32 *)(temp_16 + 0x24);
    }
    if (var_4 > 0x64) {
        var_4 = 0x64;
    }
    temp_2 = func_004af680(var_4);
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0xB7);
    }
    memcpy(temp_2 + 0xC, arg0 + 0xC, 0x48);
    func_004afb10(temp_2, *(u16 *)(*(u8 **)(arg0 + 0x5C) + 0), temp_16);
    if (*(s32 *)(*(u8 **)(temp_2 + 0x5C) + 8) == 0) {
        return temp_2;
    }
    func_004afaa0(temp_2, arg0);
    return temp_2;
}

// FUN_004AFA60
void func_004afa60(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x60) = func_00481390(arg1);
}

// FUN_004AFAA0
void func_004afaa0(u8 *arg0, u8 *arg1) {
    u8 *temp;

    if (*(u32 *)(arg1 + 0x60) == 0) {
        func_0046d730(D_00714550, 0xDA);
    }
    temp = *(u8 **)(arg1 + 0x60);
    *(u8 **)(arg0 + 0x60) = temp;
    *(s32 *)(temp + 0x54) += 1;
}

// FUN_004AFB10
void func_004afb10(u8 *arg0, u32 arg1, u8 *arg2) {
    u32 temp_16;
    u8 *var_19;
    u32 var_18;
    u8 *temp_2;

    if (*(u8 **)(arg0 + 0x5C) != NULL) {
        func_00492cd0(*(u8 **)(arg0 + 0x5C));
    }
    if (*(s32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(D_00714550, 0xF4);
    }
    *(u8 **)(arg0 + 0x5C) = func_00492b20(arg1 & 0xFFFF, *(s32 *)(arg0 + 0), arg2);
    if (*(u8 **)(arg0 + 0x68) != NULL) {
        (*jtbl_008873EC)(*(u8 **)(arg0 + 0x68));
    }
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x5C) + 8);
    func_0044ea90(D_00714550, 0xFE);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_16 * 0x1C, 0x40000);
    *(u8 **)(arg0 + 0x68) = temp_2;
    if (temp_2 == NULL) {
        func_0046d730(D_00714550, 0xFF);
    }
    var_19 = *(u8 **)(arg0 + 0x68);
    *(u8 **)(arg0 + 0x64) = var_19;
    var_18 = 0;
    while (var_18 < temp_16) {
        func_004afc80(arg0, var_19);
        var_18 += 1;
        var_19 += 0x1C;
    }
}

// FUN_004AFC50
void func_004afc50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x5C);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AFC80
void func_004afc80(u8 *arg0, u8 *arg1) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;

    temp_f20 = *(f32 *)(arg0 + 0xC);
    temp_f20_2 = (1.0f - temp_f20) + temp_f20 * effMiscRandFloat(0);
    *(f32 *)(arg1 + 0) = fGpffff8080 * effMiscRandFloat(0);
    *(f32 *)(arg1 + 0xC) = fGpffff8080 * effMiscRandFloat(0);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * effMiscRandFloat(0));
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * effMiscRandFloat(0));
    *(f32 *)(arg1 + 8) = temp_f20_2 * (*(f32 *)(arg0 + 0x10) * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
    *(f32 *)(arg1 + 0x14) = temp_f20_2 * (*(f32 *)(arg0 + 0x14) * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
    temp_f20_3 = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x18) = (1.0f - temp_f20_3) + temp_f20_3 * effMiscRandFloat(0);
}

/* measured GUARDED_SCORE 725: retail 792 vs object 796 (+4, +0.5% inside 3% gate), probe 725 words, fnalign 884 edits (+2 reloc-only). Priced casts via micro_codegen (u8->f32 14 vs s32 mask 4, u32 14 vs s32 3, srl+andi long 17 vs sra short 6); kept per-channel unsigned (lbu+bltz) to match retail long. Free pragmas tie (loopinv/unrolloff/schedoff 746, comsuboff 824 worse); subscript byte-offset wins 746->725 (-21), direct ties; colours tie (both 725). Branch order alpha-first 746 wins vs unpack-first 755. Frame -0x1E0 vs -0x1D0 (+16) with extra f25, UV single-base vs 8 separate lui, FPR $f24 vs $f21 and saved-reg perm. Verify 0 MISMATCH (11 MATCH/1 ASM), lint 0 errors. Banked as guarded floor. Remeasure 2026-09-19: sink t0/t1 into arms worsens 886->930 (+44, 796->813) so retail hoists; keep hoisted. Duplicate ang at uses (recompute *(arg2+0x1C)+8084 for s0/c0b) kills $f25, 886->884 (-2); per-arm packed_copy=packed (early check uses packed, reload after cam/in mode0) kills $s7, 884->666 (-218, frame 0x1E0->0x1D0 match, no spare GPR/FPR). New: retail 792 vs object 798 (+6), words 744, fnalign 666 edits. */
// FUN_004AFE20 NONMATCHING
#ifdef NON_MATCHING
s32 func_004afe20(u8 *arg0, u8 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg6, s32 arg7)
{
    extern void func_003f6690(s32 param, void *out);
    extern void RpSkyRenderStateSet(s32 param, s32 value);
    extern f32 cosf(f32 param);
    extern f32 sinf(f32 param);
    extern u8 *func_00457120(void);
    extern void func_003e42a0(void *a, void *b, void *c);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void func_0048a0e0(void);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8;
    extern f32 D_008872FC;
    extern f32 fGpffff8084;
    extern f32 fGpffff80f0;
    extern f32 D_00714570[];
    s32 cw_stack;
    s32 packed;
    s32 packed_copy;
    s32 st2;
    s32 st3;
    f32 t0;
    f32 t1;
    f32 f22;
    f32 f23;
    f32 base;
    f32 c0;
    f32 c1;
    f32 v0;
    f32 v1;
    s32 mode;
    u8 *cam;
    f32 in_x[3];
    f32 out_x[3];
    f32 depth;
    f32 inv;
    f32 s0;
    f32 c0b;
    f32 f8;
    f32 f7;
    f32 f6;
    f32 f5;
    f32 verts[64];
    s32 is_out;
    s32 uv_off;
    cw_stack = *(s32 *)((u8 *)arg2 + 0x14);
    {
        s32 scale = iGpffff81f4;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "nop                   \n"
            "qmtc2.ni %1, $vf2     \n"
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
            : "r"(&cw_stack), "r"(scale), "r"(arg4), "r"(&packed)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
    }
    if (((u8 *)&packed)[3] == 0) {
        return 0;
    }
    func_003f6690(2, &st2);
    func_003f6690(3, &st3);
    base = *(f32 *)((u8 *)arg2 + 0x18);
    c0 = *(f32 *)(arg1 + 0x0);
    v0 = *(f32 *)(arg1 + 0x8);
    t0 = base + v0 * cosf(c0);
    c1 = *(f32 *)(arg1 + 0xC);
    v1 = *(f32 *)(arg1 + 0x14);
    t1 = base + v1 * cosf(c1);
    mode = arg6 & 0xFF;
    if (mode == 1) {
        u32 denom;
        u32 abyte;
        f32 alpha;
        if (*(f32 *)(arg0 + 0x28) < fGpffff80f0) {
            return 0;
        }
        if (*(f32 *)(arg0 + 0x2C) < fGpffff80f0) {
            return 0;
        }
        cam = func_00457120();
        denom = *(u32 *)(*(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x20) + 0x50);
        abyte = (u32)*(s32 *)((u8 *)arg2 + 0x14) >> 24;
        packed_copy = packed;
        alpha = (255.0f * (f32)abyte) / (f32)denom;
        if (alpha >= 2147483648.0f) {
            ((u8 *)&packed_copy)[3] = (u8)(s32)(alpha - 2147483648.0f);
        } else {
            ((u8 *)&packed_copy)[3] = (u8)(s32)alpha;
        }
        f23 = *(f32 *)(arg1 + 0x18) * (*(f32 *)(arg0 + 0x28) * ((((f32 *)arg5)[0] * t0) / 32.0f));
        f22 = *(f32 *)(arg1 + 0x18) * (*(f32 *)(arg0 + 0x2C) * ((((f32 *)arg5)[1] * t1) / 32.0f));
        verts[0*16+8] = 255.0f;
        verts[0*16+9] = 255.0f;
        verts[0*16+10] = 255.0f;
        verts[0*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[1*16+8] = 255.0f;
        verts[1*16+9] = 255.0f;
        verts[1*16+10] = 255.0f;
        verts[1*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[2*16+8] = 255.0f;
        verts[2*16+9] = 255.0f;
        verts[2*16+10] = 255.0f;
        verts[2*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[3*16+8] = 255.0f;
        verts[3*16+9] = 255.0f;
        verts[3*16+10] = 255.0f;
        verts[3*16+11] = (f32)((u8 *)&packed_copy)[3];
    } else if (mode == 0) {
        packed_copy = packed;
        f23 = (((f32 *)arg5)[0] * t0) / 32.0f;
        f22 = (((f32 *)arg5)[1] * t1) / 32.0f;
        verts[0*16+8] = (f32)((u8 *)&packed_copy)[0];
        verts[0*16+9] = (f32)((u8 *)&packed_copy)[1];
        verts[0*16+10] = (f32)((u8 *)&packed_copy)[2];
        verts[0*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[1*16+8] = (f32)((u8 *)&packed_copy)[0];
        verts[1*16+9] = (f32)((u8 *)&packed_copy)[1];
        verts[1*16+10] = (f32)((u8 *)&packed_copy)[2];
        verts[1*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[2*16+8] = (f32)((u8 *)&packed_copy)[0];
        verts[2*16+9] = (f32)((u8 *)&packed_copy)[1];
        verts[2*16+10] = (f32)((u8 *)&packed_copy)[2];
        verts[2*16+11] = (f32)((u8 *)&packed_copy)[3];
        verts[3*16+8] = (f32)((u8 *)&packed_copy)[0];
        verts[3*16+9] = (f32)((u8 *)&packed_copy)[1];
        verts[3*16+10] = (f32)((u8 *)&packed_copy)[2];
        verts[3*16+11] = (f32)((u8 *)&packed_copy)[3];
    }
    in_x[0] = *(f32 *)((u8 *)arg3 + 0x0);
    in_x[1] = *(f32 *)((u8 *)arg3 + 0x4);
    in_x[2] = *(f32 *)((u8 *)arg3 + 0x8);
    cam = func_00457120();
    func_003e42a0(out_x, in_x, cam + 0x20);
    {
        f32 nx = out_x[1] / out_x[2];
        f32 ny = out_x[0] / out_x[2];
        if (ny < -2.0f || ny > 2.0f || nx < -2.0f || nx > 2.0f) {
            is_out = 1;
        } else {
            is_out = 0;
        }
        if (is_out != 0) {
            return 0;
        }
    }
    {
        u8 *c2;
        f32 zf;
        f32 wf;
        depth = D_008872FC;
        wf = D_008872F8;
        c2 = func_00457120();
        zf = *(f32 *)(c2 + 0x84);
        c2 = func_00457120();
        depth = (*(f32 *)(c2 + 0x80) / out_x[2]) * (out_x[2] - zf) * ((wf - depth) / (*(f32 *)(c2 + 0x80) - zf)) + depth;
        if (depth < 0.0f) {
            depth = 0.0f;
        }
        inv = 1.0f / depth;
        s0 = cosf(*(f32 *)((u8 *)arg2 + 0x1C) + fGpffff8084);
        c0b = sinf(*(f32 *)((u8 *)arg2 + 0x1C) + fGpffff8084);
        f8 = f23 * s0;
        f7 = f22 * s0;
        f6 = f23 * c0b;
        f5 = f22 * c0b;
        verts[0*16+4] = 0.0f;
        verts[0*16+5] = 0.0f;
        verts[1*16+4] = 1.0f;
        verts[1*16+5] = 0.0f;
        verts[2*16+4] = 0.0f;
        verts[2*16+5] = 1.0f;
        verts[3*16+4] = 1.0f;
        verts[3*16+5] = 1.0f;
        verts[0*16+0] = 640.0f * ((out_x[0] + (-f8 + f5)) / out_x[2]);
        verts[0*16+1] = 448.0f * ((out_x[1] - (-f6 - f7)) / out_x[2]);
        verts[0*16+2] = depth;
        verts[0*16+6] = inv;
        verts[1*16+0] = 640.0f * ((out_x[0] + (f8 + f5)) / out_x[2]);
        verts[1*16+1] = 448.0f * ((out_x[1] - (f6 - f7)) / out_x[2]);
        verts[1*16+2] = depth;
        verts[1*16+6] = inv;
        verts[2*16+0] = 640.0f * ((out_x[0] + (-f8 - f5)) / out_x[2]);
        verts[2*16+1] = 448.0f * ((out_x[1] - (-f6 + f7)) / out_x[2]);
        verts[2*16+2] = depth;
        verts[2*16+6] = inv;
        verts[3*16+0] = 640.0f * ((out_x[0] + (f8 - f5)) / out_x[2]);
        verts[3*16+1] = 448.0f * ((out_x[1] - (f6 + f7)) / out_x[2]);
        verts[3*16+2] = depth;
        verts[3*16+6] = inv;
        if (mode == 1) {
            RpSkyRenderStateSet(2, 0x42);
            D_00887310[0](4, verts, 4);
        } else if (mode == 0) {
            u8 *tbl;
            tbl = (u8 *)func_00481300(0x15);
            D_00887300[0](1, *(u32 *)tbl);
            func_00489f80();
            RpSkyRenderStateSet(2, 0x44);
            RpSkyRenderStateSet(3, 0x31001);
            D_00887310[0](4, verts, 4);
            func_0048a000();
            D_00887300[0](1, *(u32 *)(arg0 + 0x60));
            RpSkyRenderStateSet(2, st2 | 0x10);
            uv_off = (arg7 & 0xFF) << 5;
            verts[0*16+4] = *(f32 *)((u8 *)D_00714570 + uv_off + 0);
            verts[0*16+5] = *(f32 *)((u8 *)D_00714570 + uv_off + 4);
            verts[1*16+4] = *(f32 *)((u8 *)D_00714570 + uv_off + 8);
            verts[1*16+5] = *(f32 *)((u8 *)D_00714570 + uv_off + 12);
            verts[2*16+4] = *(f32 *)((u8 *)D_00714570 + uv_off + 16);
            verts[2*16+5] = *(f32 *)((u8 *)D_00714570 + uv_off + 20);
            verts[3*16+4] = *(f32 *)((u8 *)D_00714570 + uv_off + 24);
            verts[3*16+5] = *(f32 *)((u8 *)D_00714570 + uv_off + 28);
            D_00887310[0](4, verts, 4);
            func_0048a0e0();
        }
        RpSkyRenderStateSet(2, st2);
        RpSkyRenderStateSet(3, st3);
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afe20);
#endif

// FUN_004B0A80
void func_004b0a80(u8 *arg0) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    s32 temp_16;
    u8 *var_19;
    u8 *var_18;
    s32 var_17;
    u8 *temp_4;

    func_00492d10(*(u8 **)(arg0 + 0x5C));
    temp_4 = *(u8 **)(arg0 + 0x5C);
    temp_16 = *(s32 *)(temp_4 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_4 + 0x10) != 0)) {
        var_19 = *(u8 **)(temp_4 + 0x18);
        var_18 = *(u8 **)(arg0 + 0x64);
        *(f32 *)(arg0 + 0x54) = *(f32 *)(arg0 + 0x54) + *(f32 *)(arg0 + 0x1C);
        *(f32 *)(arg0 + 0x58) = *(f32 *)(arg0 + 0x58) + *(f32 *)(arg0 + 0x20);
        var_17 = 0;
        while (var_17 < temp_16) {
            if (*(s32 *)(var_19 + 0x10) == 0) {
                temp_f20 = *(f32 *)(arg0 + 0xC);
                temp_f20_2 = (1.0f - temp_f20) + temp_f20 * effMiscRandFloat(0);
                *(f32 *)(var_18 + 0) = fGpffff8080 * effMiscRandFloat(0);
                *(f32 *)(var_18 + 0xC) = fGpffff8080 * effMiscRandFloat(0);
                *(f32 *)(var_18 + 4) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * effMiscRandFloat(0));
                *(f32 *)(var_18 + 0x10) = *(f32 *)(arg0 + 0x18) * (0.5f + 0.5f * effMiscRandFloat(0));
                *(f32 *)(var_18 + 8) = temp_f20_2 * (*(f32 *)(arg0 + 0x10) * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
                *(f32 *)(var_18 + 0x14) = temp_f20_2 * (*(f32 *)(arg0 + 0x14) * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
                temp_f20_3 = *(f32 *)(arg0 + 0x24);
                *(f32 *)(var_18 + 0x18) = (1.0f - temp_f20_3) + temp_f20_3 * effMiscRandFloat(0);
            }
            if (*(s32 *)(var_19 + 0x10) >= 0) {
                *(f32 *)(var_18 + 0) = *(f32 *)(var_18 + 0) + *(f32 *)(var_18 + 4);
                *(f32 *)(var_18 + 0xC) = *(f32 *)(var_18 + 0xC) + *(f32 *)(var_18 + 0x10);
            }
            var_17 += 1;
            var_19 += 0x20;
            var_18 += 0x1C;
        }
    }
}

// FUN_004B0CE0
void func_004b0ce0(u8 *arg0, s32 arg1) {
    s32 spFC;
    s32 *pt;
    f32 spF0[2];
    u8 spE0[16];
    u8 spD0[16];
    u8 spC0[16];
    u8 spB0[16];
    u8 sp70[0x40];
    u8 *var_18;
    s32 temp_16;
    s32 var_21;
    s32 var_21_2;
    u8 *temp_21;
    u8 *temp_3;
    u8 *temp_4;
    u8 *var_17;
    s32 scale;

    temp_3 = *(u8 **)(arg0 + 0x5C);
    temp_16 = *(s32 *)(temp_3 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_3 + 0x10) != 0)) {
        if (*(s32 *)(arg0 + 0x60) == 0) {
            func_0046d730(D_00714550, 0x265);
        }
        var_18 = *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x18);
        var_17 = *(u8 **)(arg0 + 0x64);
        temp_21 = *(u8 **)(s32)func_00481300(0x15);
        if ((arg1 & 0xFF) == 1) {
            D_00887300[0](1, (u32)temp_21);
        }
        spF0[0] = (f32) * (s32 *)(temp_21 + 0xC);
        spF0[1] = (f32) * (s32 *)(temp_21 + 0x10);
        spFC = *(s32 *)(arg0 + 4);
        pt = &spFC;
        scale = iGpffff81f4;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "nop                   \n"
            "qmtc2.ni %1, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            :
            : "r"(pt), "r"(scale)
            : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spE0) : "$vf10", "memory");
        temp_4 = *(u8 **)(arg0 + 0x5C);
        if (!(*(s32 *)(temp_4 + 0xC) & 1)) {
            var_21 = 0;
            while (var_21 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    func_004afe20(arg0, var_17, var_18, var_18, spE0, spF0, arg1, effMiscRand(0) & 3);
                }
                var_21 += 1;
                var_18 += 0x20;
                var_17 += 0x1C;
            }
        } else {
            func_00492df0(temp_4, spB0);
            func_00492db0(*(u8 **)(arg0 + 0x5C), spC0);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(spB0) : "$vf10", "memory");
            func_004bceb0();
            __asm__ volatile("lqc2 $vf31, 0(%0)" : : "r"(spC0) : "$vf31", "memory");
            __asm__ volatile(
                "sqc2 $vf28, 0(%0)     \n"
                "sqc2 $vf29, 16(%0)    \n"
                "sqc2 $vf30, 32(%0)    \n"
                "sqc2 $vf31, 48(%0)    \n"
                :
                : "r"(sp70)
                : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            var_21_2 = 0;
            while (var_21_2 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    __asm__ volatile(
                        "lqc2 $vf28, 0(%0)     \n"
                        "lqc2 $vf29, 16(%0)    \n"
                        "lqc2 $vf30, 32(%0)    \n"
                        "lqc2 $vf31, 48(%0)    \n"
                        "lqc2 $vf10, 0(%1)     \n"
                        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                        "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                        "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                        :
                        : "r"(sp70), "r"(var_18)
                        : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(spD0) : "$vf10", "memory");
                    func_004afe20(arg0, var_17, var_18, spD0, spE0, spF0, arg1, effMiscRand(0) & 3);
                }
                var_21_2 += 1;
                var_18 += 0x20;
                var_17 += 0x1C;
            }
        }
        D_00887300[0](1, 0);
    }
}
