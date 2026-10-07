#include "effect_vu0_internal.h"
#include "effect_geometry_internal.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effLineNova.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "include_asm.h"

void func_004833f0(void *arg);
void func_0044ea90(u8 *file, s32 line);
void func_0046d730(u8 *file, s32 line);
void *func_00481460(u16 arg0);
void *func_00481540(u16 arg0);
void func_00460ac0(void *arg0, void *arg1);
void memcpy(void *dst, const void *src, u32 size);
void func_004b4430(u8 *arg0, u8 *arg1);
f32 effMiscRandFloat(u32 param);

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
    p = (u16 *)func_00482f70(n & 0xFFFF, 4, 6, D_00713310, 0x48);
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
                r = 65535.0f * effMiscRandFloat(0);
                *(u16 *)dst = (u16)r;
                r = 255.0f * (f22 + f24 * effMiscRandFloat(0));
                *(u8 *)(dst + 1) = (u8)r;
                r = f21 + f25 * effMiscRandFloat(0);
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


static inline f32 novaMultiply(f32 first, f32 second) { return first * second; }
static inline f32 novaAdd(f32 first, f32 second) { return first + second; }
static inline f32 novaCameraOffset(f32 center, const f32 *scale, f32 depth, f32 screen, f32 origin)
{
    f32 difference = origin - center;
    f32 factor = 2.0f * *scale;
    factor = factor * depth;
    return difference * factor / screen;
}

/* Eight-byte particles follow the four camera corners; the VU computes the
 * edge length, normalized cross product and six real XYZ vertices. Both
 * VU0 bridges that retail writes through $v0 (the colour unpack and the
 * edge-length cfc2/mtc1) name $2: the retail call result moves to $v1 before
 * the first unpack, and no loop invariant takes $v0. The call's last two
 * arguments are (s32) conversions so they load before the first two; the
 * screen products use novaMultiply for retail's operand order. */
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// FUN_004B36B0
void func_004b36b0(u8 *unused, u8 *effect)
{

    extern s32 func_0048abd0(u8 *, u8 *, s32, s32);
    extern u8 *func_00457120(void);
    extern u8 *RpGeometryLock(u8 *, s32);
    extern u8 *func_003c22f0(u8 *);
    extern u8 *func_003e9700(u8 *);
    extern u8 *func_003e9cb0(u8 *, u8 *, s32);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[], D_00713D10[], D_00713D14[], D_00713D18[];
    typedef struct { u8 r, g, b, a; } NovaRgba;
    union { u32 word; u8 byte[4]; NovaRgba color; } rgba;
    u32 effectColor, sampled, packed;
    u32 sampleResult;
    const u32 *colorInput;
    u8 *instance, *state, *config, *owner;
    u8 *cameraDimensions;
    u8 *particle;
    f32 normalization;
    u32 count, index;
    f32 *vertices;

    extern u8 *func_003e42a0(u8 *, u8 *, u8 *);
    EffectVuVector projected;
    union { EffectVuVector vector; u32 word[4]; } center;
    EffectVuVector corners[4], interpolated;
    f32 farClip, xScale, yScale, xExtent, yExtent, minusX, minusY;
    f32 width, spread, divisor;
    u8 mode;

    instance = effect;
    state = *(u8 **)(instance + 0x20);
    config = *(u8 **)(instance + 0x24);
    owner = *(u8 **)(state + 4);

    sampleResult = (u32)func_0048abd0(config, config + 0x24, (s32)*(u32 *)(instance + 0x14), (s32)*(u32 *)(config + 0x34));
    effectColor = *(u32 *)(instance + 0x10);
    colorInput = &effectColor;
    normalization = fGpffff8044;
    effectVuUnpackColor10V0(colorInput, normalization);
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
    sampled = sampleResult;
    effectVuUnpackColor10V0(&sampled, normalization);
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
    {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packed\n"
            : "=&r"(transfer), "=m"(packed) : "r"(255.0f) : "$vf2", "$vf10", "memory");
    }
    rgba.word = packed;
    if (rgba.byte[3] != 255) {
        u8 *target = *(u8 **)(owner + 0x14);
        *(NovaRgba *)(target + 4) = rgba.color;
    } else {
        u8 *target;
        rgba.byte[3] = 254;
        target = *(u8 **)(owner + 0x14);
        *(NovaRgba *)(target + 4) = rgba.color;
        rgba.byte[3] = 255;
    }
    if (*(u8 *)(*(u8 **)(owner + 0x14) + 7) == 0) return;

    cameraDimensions = func_00457120() + 0x68;
    farClip = *(f32 *)(func_00457120() + 0x80);
    xScale = *(f32 *)cameraDimensions;
    xExtent = xScale * farClip;
    yScale = *(f32 *)(cameraDimensions + 4);
    yExtent = yScale * farClip;
    minusX = -xExtent;
    corners[0].lane[0] = minusX;
    minusY = -yExtent;
    corners[0].lane[1] = minusY; corners[0].lane[2] = farClip;
    corners[1].lane[0] = xExtent; corners[1].lane[1] = minusY; corners[1].lane[2] = farClip;
    corners[2].lane[0] = xExtent; corners[2].lane[1] = yExtent; corners[2].lane[2] = farClip;
    corners[3].lane[0] = minusX; corners[3].lane[1] = yExtent; corners[3].lane[2] = farClip;
    center.word[0] = 0; center.word[1] = 0; center.vector.lane[2] = farClip;
    mode = *(u8 *)(config + 0x7c);
    switch (mode) {
    case 0: {
        f32 depth, x, y;
        {
            u8 *view = func_00457120() + 0x20;
            func_003e42a0((u8 *)&interpolated, instance, view);
        }
        depth = interpolated.lane[2];
        x = *(f32 *)cameraDimensions * depth;
        y = *(f32 *)(cameraDimensions + 4) * depth;
        projected.lane[0] = (2.0f * -x) * (interpolated.lane[0] / depth - 0.5f);
        projected.lane[1] = (2.0f * -y) * (interpolated.lane[1] / depth - 0.5f);
        projected.lane[2] = depth;
    } break;
    case 1: {
        f32 x, y;
        f32 half, two;
        farClip = novaMultiply(300.0f, farClip);
        xScale = xScale * farClip;
        yScale = yScale * farClip;
        half = 0.5f;
        two = 2.0f;
        x = (f32)*(s16 *)(config + 0x7e);
        x = (x / 640.0f) - half;
        projected.lane[0] = novaMultiply(two * -xScale, x);
        y = (f32)*(s16 *)(config + 0x80);
        y = (y / 448.0f) - half;
        projected.lane[1] = novaMultiply(two * -yScale, y);
        projected.lane[2] = farClip;
    } break;
    }
    particle = *(u8 **)state;
    count = *(u32 *)(config + 0x38);
    RpGeometryLock(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18), 2);
    vertices = *(f32 **)(*(u8 **)(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18) + 0x5c) + 0x14);
    {
        f32 opacity = (f32)(u32)particle[2] / 255.0f;
        width = *(f32 *)(config + 0x5c) * opacity;
        spread = *(f32 *)(config + 0x60) * opacity;
    }
    index = 0;
    divisor = (f32)65535;
    for (; index < count; index++, particle += 8, vertices += 18) {
        f32 length, factor;
        effectVuLoad10(&corners[index & 3]);
        effectVuLoad11(&corners[(index + 1) & 3]);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vaddy.x $vf2, $vf2, $vf2y\n"
            "vaddz.x $vf2, $vf2, $vf2z\n"
            ".word 0x4a0203bd\n"
            "vwaitq\n"
            "cfc2.ni $2, $vi22\n"
            "mtc1 $2, %0\n"
            : "=f"(length) : : "$2", "$vf2", "Q");
        factor = length * ((f32)(u32)*(u16 *)particle / divisor);
__asm__ volatile(
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuScale10(factor);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    "vmove.xyzw $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11(&projected);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        {
            __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x\n"
                : : "r"(*(u32 *)(particle + 4)) : "$vf2", "$vf10");
        }
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuStore10(&interpolated);
__asm__ volatile(
    "vmove.xyzw $vf10, $vf12\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11(&center.vector);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11((EffectVuVector *)D_00713CF0);
__asm__ volatile(
    "vopmula.xyz $ACC, $vf10, $vf11\n"
    "vopmsub.xyz $vf10, $vf11, $vf10\n"
    "vmove.xyzw $vf11, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuScale10(spread);
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[12] = *(f32 *)D_00713D10;
vertices[13] = *(f32 *)D_00713D14;
vertices[14] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vadd.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[9] = *(f32 *)D_00713D10;
vertices[10] = *(f32 *)D_00713D14;
vertices[11] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[15] = *(f32 *)D_00713D10;
vertices[16] = *(f32 *)D_00713D14;
vertices[17] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vmove.xyzw $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&interpolated), "m"(interpolated) : "$vf12");
        effectVuScale10(width);
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[3] = *(f32 *)D_00713D10;
vertices[4] = *(f32 *)D_00713D14;
vertices[5] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vadd.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[0] = *(f32 *)D_00713D10;
vertices[1] = *(f32 *)D_00713D14;
vertices[2] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[6] = *(f32 *)D_00713D10;
vertices[7] = *(f32 *)D_00713D14;
vertices[8] = *(f32 *)D_00713D18;

    }

    {
        u8 *geometry = *(u8 **)(*(u8 **)(owner + 0x10) + 0x18);
        func_003c22f0(geometry);
        if (*(u16 *)owner & 4) *(u16 *)(geometry + 0xc) |= 1;
    }

    {
        u8 *matrix = func_003e9700(*(u8 **)(func_00457120() + 4));
        func_003e9cb0(*(u8 **)(owner + 0xc), matrix, 0);
    }
}
#pragma pop


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
    temp_2_2 = (u16 *)func_00482f70(temp_16 & 0xFFFF, 4, 6, D_00713310, 0x48);
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
                r = 65535.0f * (f21 + f23 * effMiscRandFloat(0));
                *(u16 *)dst = (u16)r;
                r = 65535.0f * effMiscRandFloat(0);
                *(u16 *)(dst + 1) = (u16)r;
                r = 65535.0f * (f20 + f22 * effMiscRandFloat(0));
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

/* Six-byte particles place six XYZ vertices between the projected endpoints.
 * The rotation axis is twelve bytes, with both source parts loaded first.
 * As in func_004b36b0: (s32) conversions on the last two sampler arguments,
 * effectVuUnpackColor10V0 for the $v0 colour transfers, and the vertex pointer
 * declared after the loop counter. The Y camera offset forms its depth factor
 * before the 224 difference, unlike the X call through novaCameraOffset. */
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// FUN_004B4430
void func_004b4430(u8 *unused, u8 *effect)
{

    extern s32 func_0048abd0(u8 *, u8 *, s32, s32);
    extern u8 *func_00457120(void);
    extern u8 *RpGeometryLock(u8 *, s32);
    extern u8 *func_003c22f0(u8 *);
    extern u8 *func_003e9700(u8 *);
    extern u8 *func_003e9cb0(u8 *, u8 *, s32);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[], D_00713D10[], D_00713D14[], D_00713D18[];
    typedef struct { u8 r, g, b, a; } NovaRgba;
    union { u32 word; u8 byte[4]; NovaRgba color; } rgba;
    u32 effectColor, sampled, packed;
    u32 sampleResult;
    const u32 *colorInput;
    u8 *instance, *state, *config, *owner;
    u8 *cameraDimensions;
    u8 *particle;
    f32 normalization;
    u32 count, index;
    f32 *vertices;

    extern u8 *RwMatrixMultiply(u8 *, u8 *, u8 *);
    extern u8 *func_003e0870(u8 *, const u8 *, f32, s32);
    extern u8 D_00714638[], D_00714640[];
    #pragma push
    #pragma pack(4)
    typedef struct { s64 xy; f32 z; } NovaAxis;
    #pragma pop
    NovaAxis axis;
    s64 axisXY;
    f32 axisZ;
    EffectVuVector top, bottom;
    u8 rotation[64] __attribute__((aligned(16)));
    u8 transform[64] __attribute__((aligned(16)));
    f32 centerX, centerY, depth, extentX, extentY;
    f32 width, spread, screenX, screenY;
    u32 progress, duration;
    u8 *matrix;
    axisXY = *(s64 *)D_00714638;
    axisZ = *(f32 *)D_00714640;
    axis.xy = axisXY;
    axis.z = axisZ;

    instance = effect;
    state = *(u8 **)(instance + 0x20);
    config = *(u8 **)(instance + 0x24);
    owner = *(u8 **)(state + 4);

    progress = *(u32 *)(instance + 0x14);

    sampleResult = (u32)func_0048abd0(config, config + 0x24, (s32)*(u32 *)(instance + 0x14), (s32)*(u32 *)(config + 0x34));
    effectColor = *(u32 *)(instance + 0x10);
    colorInput = &effectColor;
    normalization = fGpffff8044;
    effectVuUnpackColor10V0(colorInput, normalization);
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
    sampled = sampleResult;
    effectVuUnpackColor10V0(&sampled, normalization);
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
    {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packed\n"
            : "=&r"(transfer), "=m"(packed) : "r"(255.0f) : "$vf2", "$vf10", "memory");
    }
    rgba.word = packed;
    if (rgba.byte[3] != 255) {
        u8 *target = *(u8 **)(owner + 0x14);
        *(NovaRgba *)(target + 4) = rgba.color;
    } else {
        u8 *target;
        rgba.byte[3] = 254;
        target = *(u8 **)(owner + 0x14);
        *(NovaRgba *)(target + 4) = rgba.color;
        rgba.byte[3] = 255;
    }
    if (*(u8 *)(*(u8 **)(owner + 0x14) + 7) == 0) return;

    duration = *(u32 *)(config + 0x7c);
    if (duration != 0) {
        if (progress < duration) {
            f32 time = (f32)progress / (f32)duration;
            centerX = 0.0f + (f32)*(s16 *)(config + 0x80) + time * (f32)(*(s16 *)(config + 0x88) - *(s16 *)(config + 0x80));
            centerY = 0.0f + (f32)*(s16 *)(config + 0x82) + time * (f32)(*(s16 *)(config + 0x8a) - *(s16 *)(config + 0x82));
            extentX = 0.0f + (f32)*(s16 *)(config + 0x84) + time * (f32)(*(s16 *)(config + 0x8c) - *(s16 *)(config + 0x84));
            extentY = 0.0f + (f32)*(s16 *)(config + 0x86) + time * (f32)(*(s16 *)(config + 0x8e) - *(s16 *)(config + 0x86));
        } else {
            centerX = (f32)*(s16 *)(config + 0x88);
            centerY = (f32)*(s16 *)(config + 0x8a);
            extentX = (f32)*(s16 *)(config + 0x8c);
            extentY = (f32)*(s16 *)(config + 0x8e);
        }
    } else {
        centerX = (f32)*(s16 *)(config + 0x80);
        centerY = (f32)*(s16 *)(config + 0x82);
        extentX = (f32)*(s16 *)(config + 0x84);
        extentY = (f32)*(s16 *)(config + 0x86);
    }
    cameraDimensions = func_00457120() + 0x68;
    depth = novaAdd(*(f32 *)(func_00457120() + 0x80), 1.0f);
    screenX = 640.0f;
    {
        f32 x = extentX * (*(f32 *)cameraDimensions * depth) / screenX;
        f32 y;
        screenY = 448.0f;
        y = extentY * (*(f32 *)(cameraDimensions + 4) * depth) / screenY;
        bottom.lane[0] = -x; bottom.lane[1] = -y; bottom.lane[2] = depth;
        top.lane[0] = -x; top.lane[1] = y; top.lane[2] = depth;
        extentX = novaMultiply(y, 2.0f);
        extentY = novaMultiply(x, 2.0f);
    }
    particle = *(u8 **)state;
    count = *(u32 *)(config + 0x38);
    RpGeometryLock(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18), 2);
    vertices = *(f32 **)(*(u8 **)(*(u8 **)(*(u8 **)(owner + 0x10) + 0x18) + 0x5c) + 0x14);
    width = *(f32 *)(config + 0x5c) / 10.0f;
    spread = *(f32 *)(config + 0x60) / 10.0f;
    index = 0;
    for (; index < count; index++, particle += 6, vertices += 18) {
        const f32 divisor = (f32)65535;
        f32 opacity = (f32)(u32)*(u16 *)particle / divisor;
        f32 horizontalWidth = width * opacity;
        f32 verticalWidth = spread * opacity;
        f32 horizontalPosition = extentY * (f32)(u32)*(u16 *)(particle + 4) / divisor;
        f32 verticalPosition;
        effectVuLoad10(&bottom);
        effectVuLoad11(&top);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    "vmove.xyzw $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        verticalPosition = extentX * (f32)(u32)*(u16 *)(particle + 2) / divisor;
        effectVuScale10(verticalPosition);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[12] = *(f32 *)D_00713D10;
vertices[13] = *(f32 *)D_00713D14;
vertices[14] = *(f32 *)D_00713D18;
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[9] = *(f32 *)D_00713D10;
vertices[10] = *(f32 *)D_00713D14;
vertices[11] = *(f32 *)D_00713D18;
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[15] = *(f32 *)D_00713D10;
vertices[16] = *(f32 *)D_00713D14;
vertices[17] = *(f32 *)D_00713D18;

        vertices[1] = vertices[10] - verticalWidth;
        vertices[7] = vertices[16] + verticalWidth;
        vertices[10] = vertices[10] - horizontalWidth;
        vertices[16] = vertices[16] + horizontalWidth;
        vertices[0] = vertices[9] + horizontalPosition;
        vertices[2] = vertices[11];
        vertices[3] = vertices[12] + horizontalPosition;
        vertices[4] = vertices[13]; vertices[5] = vertices[14];
        vertices[6] = vertices[15] + horizontalPosition;
        vertices[8] = vertices[17];
    }

    {
        u8 *geometry = *(u8 **)(*(u8 **)(owner + 0x10) + 0x18);
        func_003c22f0(geometry);
        if (*(u16 *)owner & 4) *(u16 *)(geometry + 0xc) |= 1;
    }

    matrix = func_003e9700(*(u8 **)(func_00457120() + 4));
    func_003e0870(rotation, (const u8 *)&axis, (f32)*(s16 *)(config + 0x90), 0);
    *(f32 *)(rotation + 0x30) += novaCameraOffset(centerX, (const f32 *)cameraDimensions, depth, screenX, 320.0f);
    {
        f32 factor = 2.0f * *(const f32 *)(cameraDimensions + 4);
        factor = factor * depth;
        *(f32 *)(rotation + 0x34) += (224.0f - centerY) * factor / screenY;
    }
    RwMatrixMultiply(transform, rotation, matrix);
    func_003e9cb0(*(u8 **)(owner + 0xc), transform, 0);
}
#pragma pop




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
    memcpy(*(void **)(w + 0x24), arg1, size);
    idx2 = (u16)arg0 * 0x18;
    *(s32 *)(w + 0x20) = (*(s32 (**)(u8 *))(&D_00714654[0] + idx2))(arg1);
    (*(void (**)(u8 *))(&D_00714650[0] + idx2))(w);
    return w;
}
// FUN_004B4E10
void *func_004b4e10(void *arg0) {
    u8 *p;

    p = func_00484490(arg0);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B3);
    }
    p = func_004b4cb0(*(u16 *)((u8 *)arg0 + 0xC), p);
    if (p == NULL) {
        func_0046d730(D_00714628, 0x2B5);
    }
    return p;
}
