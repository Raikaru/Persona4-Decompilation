#include "include_asm.h"
/* Persona 4 USA decompilation - effDistortParticle.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "effect_instance_internal.h"

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
extern u8 *func_00492b20(u32 arg0, s32 arg1, u8 *arg2);
extern void func_00492d10(void *ptr);
extern s32 func_00481300(u16 param);
extern void func_00492df0(void *arg0, void *arg1);
extern void func_00492db0(void *arg0, void *arg1);
extern s32 effMiscRand(s32 arg0);
extern void func_004afe20(u8 *arg0, u8 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
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
void *func_004af740(void *opaqueSource) {
    u8 *arg0 = opaqueSource;
    s32 temp_3;
    u32 var_4;
    u8 *temp_2_2;
    u8 *temp_2;
    s32 temp_2_3;

    temp_2_2 = func_00484490(arg0);
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
    temp_2_3 = (s32)func_004844d0(arg0);
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
void *func_004af920(void *opaqueSource) {
    u8 *arg0 = opaqueSource;
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

/* func_004afe20, MATCH 2026-10-07. Rewritten from retail asm on the matched
   effParticle sibling's pattern (func_00488d70): one 64-byte sky vertex quad,
   per-channel unsigned colour conversions, and the projected-depth formula.
   The colour unpack asm names $2 and the COP2 pack stores the packed word to
   its frame slot (both user-approved VU0 forms). Retail returns nothing, so
   the prototype is void. (u32) address casts stop the CSE of arg2 + 0x14/0x1C;
   the render tables are read through u32 locals, which keeps them in $s1/$s0.
   The mode-1 alpha byte is stored through a byte pointer so arg0's sizes are
   reloaded. The second size check indexes fGpffff80f0 as an array: IRO_CommonSubs
   would otherwise hoist the shared read above the first size load. */
typedef struct DistortVertex {
    f32 x, y, z;
    f32 camZ;
    f32 u, v;
    f32 recipZ;
    f32 pad1;
    f32 r, g, b, a;
    f32 nx, ny, nz;
    f32 pad2;
} DistortVertex;
typedef struct DistortColorBytes {
    u8 red, green, blue, alpha;
} DistortColorBytes;
typedef union DistortColor {
    u32 word;
    DistortColorBytes bytes;
} DistortColor;
typedef struct DistortVec3 {
    f32 x, y, z;
} DistortVec3;
// FUN_004AFE20
void func_004afe20(u8 *arg0, u8 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg6, s32 arg7)
{
    extern void func_003f6690(s32 param, void *out);
    extern void RpSkyRenderStateSet(s32 param, s32 value);
    extern f32 cosf(f32 param);
    extern f32 sinf(f32 param);
    extern s32 func_00457120(void);
    extern void func_003e42a0(DistortVec3 *out, DistortVec3 *in, void *matrix);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void func_0048a0e0(void);
    extern s32 (*D_00887310[])(s32, DistortVertex *, s32);
    extern f32 D_008872F8[];
    extern f32 D_008872FC[];
    extern f32 fGpffff8084;
    extern f32 fGpffff80f0;
    extern f32 fGpffff81f4;
    extern f32 D_00714570[];
    extern f32 D_00714574[];
    extern f32 D_00714578[];
    extern f32 D_0071457C[];
    extern f32 D_00714580[];
    extern f32 D_00714584[];
    extern f32 D_00714588[];
    extern f32 D_0071458C[];
    DistortColor packed;
    s32 st2;
    s32 st3;
    s32 cw;
    u32 pk;
    DistortVec3 tmpPos __attribute__((aligned(16)));
    DistortVec3 tmpOut __attribute__((aligned(16)));
    DistortVertex qb[4];
    f32 base;
    f32 t0;
    f32 t1;
    f32 sizeX;
    f32 sizeY;
    u32 mode;
    f32 bufferNear;
    f32 bufferFar;
    f32 cameraFar;
    f32 cameraNear;
    f32 recip;
    f32 depth;
    f32 c;
    f32 s;
    f32 f8;
    f32 f7;
    f32 f6;
    f32 f5;
    s32 bad;

    cw = *(s32 *)((u8 *)arg2 + 0x14);
    {
        const s32 *word = &cw;
        f32 scale;

        scale = fGpffff81f4;
        __asm__ volatile(
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "qmtc2.ni %1, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "lqc2 $vf11, 0(%2)\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            : : "r"(word), "r"(scale), "r"(arg4), "m"(cw) : "$2", "$vf2", "$vf10", "$vf11");
    }
    {
        u32 work;

        __asm__ volatile(
            "qmtc2.ni %2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $0, %0\n"
            "ppacb %0, $0, %0\n"
            "sw %0, pk\n"
            : "=&r"(work), "=m"(pk) : "r"(0x437F0000U) : "$vf2", "$vf10");
    }
    packed.word = pk;
    if (packed.bytes.alpha == 0) {
        return;
    }
    func_003f6690(2, &st2);
    func_003f6690(3, &st3);
    base = *(f32 *)((u8 *)arg2 + 0x18);
    t0 = base + *(f32 *)(arg1 + 0x8) * cosf(*(f32 *)(arg1 + 0x0));
    t1 = base + *(f32 *)(arg1 + 0x14) * cosf(*(f32 *)(arg1 + 0xC));
    mode = arg6 & 0xFF;
    switch (mode) {
    case 0:
        sizeX = (((f32 *)arg5)[0] * t0) / 32.0f;
        sizeY = (((f32 *)arg5)[1] * t1) / 32.0f;
        qb[0].r = (f32)(u32)packed.bytes.red;
        qb[0].g = (f32)(u32)packed.bytes.green;
        qb[0].b = (f32)(u32)packed.bytes.blue;
        qb[0].a = (f32)(u32)packed.bytes.alpha;
        qb[1].r = (f32)(u32)packed.bytes.red;
        qb[1].g = (f32)(u32)packed.bytes.green;
        qb[1].b = (f32)(u32)packed.bytes.blue;
        qb[1].a = (f32)(u32)packed.bytes.alpha;
        qb[2].r = (f32)(u32)packed.bytes.red;
        qb[2].g = (f32)(u32)packed.bytes.green;
        qb[2].b = (f32)(u32)packed.bytes.blue;
        qb[2].a = (f32)(u32)packed.bytes.alpha;
        qb[3].r = (f32)(u32)packed.bytes.red;
        qb[3].g = (f32)(u32)packed.bytes.green;
        qb[3].b = (f32)(u32)packed.bytes.blue;
        qb[3].a = (f32)(u32)packed.bytes.alpha;
        break;
    case 1: {
        f32 scale;

        if (*(f32 *)(arg0 + 0x28) < fGpffff80f0 || *(f32 *)(arg0 + 0x2C) < ((f32 *)&fGpffff80f0)[0]) {
            return;
        }
        ((u8 *)&packed)[3] = (u8)((255.0f * (f32)(*(u32 *)((u32)arg2 + 0x14) >> 24)) /
                                  (f32)*(u32 *)(*(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x20) + 0x50));
        scale = *(f32 *)(arg1 + 0x18);
        sizeX = scale * (*(f32 *)(arg0 + 0x28) * ((((f32 *)arg5)[0] * t0) / 32.0f));
        sizeY = scale * (*(f32 *)(arg0 + 0x2C) * ((((f32 *)arg5)[1] * t1) / 32.0f));
        qb[0].r = 255.0f;
        qb[0].g = 255.0f;
        qb[0].b = 255.0f;
        qb[0].a = (f32)(u32)packed.bytes.alpha;
        qb[1].r = 255.0f;
        qb[1].g = 255.0f;
        qb[1].b = 255.0f;
        qb[1].a = (f32)(u32)packed.bytes.alpha;
        qb[2].r = 255.0f;
        qb[2].g = 255.0f;
        qb[2].b = 255.0f;
        qb[2].a = (f32)(u32)packed.bytes.alpha;
        qb[3].r = 255.0f;
        qb[3].g = 255.0f;
        qb[3].b = 255.0f;
        qb[3].a = (f32)(u32)packed.bytes.alpha;
        break;
    }
    }
    tmpPos.x = ((f32 *)arg3)[0];
    tmpPos.y = ((f32 *)arg3)[1];
    tmpPos.z = ((f32 *)arg3)[2];
    func_003e42a0(&tmpOut, &tmpPos, (u8 *)func_00457120() + 0x20);
    {
        f32 ry = tmpOut.y / tmpOut.z;
        f32 rx = tmpOut.x / tmpOut.z;

        if (rx < -2.0f || !(rx <= 2.0f) || ry < -2.0f || !(ry <= 2.0f)) {
            bad = 1;
        } else {
            bad = 0;
        }
    }
    if (bad != 0) {
        return;
    }
    bufferNear = D_008872FC[0];
    bufferFar = D_008872F8[0];
    cameraFar = *(f32 *)((u8 *)func_00457120() + 0x84);
    cameraNear = *(f32 *)((u8 *)func_00457120() + 0x80);
    depth = (cameraNear / tmpOut.z) * ((tmpOut.z - cameraFar) * ((bufferFar - bufferNear) / (cameraNear - cameraFar))) + (bufferNear + 0.0f);
    if (depth < 0.0f) {
        depth = 0.0f;
    }
    recip = 1.0f / depth;
    c = cosf(fGpffff8084 + *(f32 *)((u8 *)arg2 + 0x1C));
    s = sinf(fGpffff8084 + *(f32 *)((u32)arg2 + 0x1C));
    f8 = sizeX * c;
    f7 = sizeY * c;
    f6 = sizeX * s;
    f5 = sizeY * s;
    qb[0].u = 0.0f;
    qb[0].v = 0.0f;
    qb[1].u = 1.0f;
    qb[1].v = 0.0f;
    qb[2].u = 0.0f;
    qb[2].v = 1.0f;
    qb[3].u = 1.0f;
    qb[3].v = 1.0f;
    qb[0].x = 640.0f * ((tmpOut.x + (-f8 + f5)) / tmpOut.z);
    qb[0].y = 448.0f * ((tmpOut.y - (-f6 - f7)) / tmpOut.z);
    qb[0].z = depth;
    qb[0].recipZ = recip;
    qb[1].x = 640.0f * ((tmpOut.x + (f8 + f5)) / tmpOut.z);
    qb[1].y = 448.0f * ((tmpOut.y - (f6 - f7)) / tmpOut.z);
    qb[1].z = depth;
    qb[1].recipZ = recip;
    qb[2].x = 640.0f * ((tmpOut.x + (-f8 - f5)) / tmpOut.z);
    qb[2].y = 448.0f * ((tmpOut.y - (-f6 + f7)) / tmpOut.z);
    qb[2].z = depth;
    qb[2].recipZ = recip;
    qb[3].x = 640.0f * ((tmpOut.x + (f8 - f5)) / tmpOut.z);
    qb[3].y = 448.0f * ((tmpOut.y - (f6 + f7)) / tmpOut.z);
    qb[3].z = depth;
    qb[3].recipZ = recip;
    switch (mode) {
    case 0: {
        u32 uv;
        u32 *texture = (u32 *)func_00481300(0x15);
        u32 setStateTable = (u32)D_00887300;
        u32 primitiveTable;

        ((void (**)(u32, u32))setStateTable)[0](1, *texture);
        func_00489f80();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31001);
        primitiveTable = (u32)D_00887310;
        ((s32 (**)(s32, DistortVertex *, s32))primitiveTable)[0](4, qb, 4);
        func_0048a000();
        ((void (**)(u32, u32))setStateTable)[0](1, **(u32 **)(arg0 + 0x60));
        RpSkyRenderStateSet(2, st2 | 0x10);
        uv = (arg7 & 0xFF) << 5;
        qb[0].u = *(f32 *)((u8 *)D_00714570 + uv);
        qb[0].v = *(f32 *)((u8 *)D_00714574 + uv);
        qb[1].u = *(f32 *)((u8 *)D_00714578 + uv);
        qb[1].v = *(f32 *)((u8 *)D_0071457C + uv);
        qb[2].u = *(f32 *)((u8 *)D_00714580 + uv);
        qb[2].v = *(f32 *)((u8 *)D_00714584 + uv);
        qb[3].u = *(f32 *)((u8 *)D_00714588 + uv);
        qb[3].v = *(f32 *)((u8 *)D_0071458C + uv);
        ((s32 (**)(s32, DistortVertex *, s32))primitiveTable)[0](4, qb, 4);
        func_0048a0e0();
        break;
    }
    case 1:
        RpSkyRenderStateSet(2, 0x42);
        D_00887310[0](4, qb, 4);
        break;
    }
    RpSkyRenderStateSet(2, st2);
    RpSkyRenderStateSet(3, st3);
}

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
