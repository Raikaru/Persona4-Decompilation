/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonThunder.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

/* FUN_004833F0 is a texture release helper shared by the eff* units. */
extern void func_004833f0(void *arg0);
extern u32 effMiscRand(u32 arg0);
extern f32 effMiscRandFloat(u32 arg0);
extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern void memcpy(void *dst, void *src, u32 size);
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
extern u8 *func_00482dc0(u16 copies, void *indices, s32 vertices, s32 flags);

/* 4-byte color, copied field-by-field by retail. */
typedef struct
{
    u8 c[4];
} Color4;
extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
extern void func_00483700(void *dst, void *obj, void *src, f32 arg3);
extern void func_003e9cb0(void *a, void *b, s32 c);
extern void func_00483490(void *a, u16 b);


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1216/1216 bytes, eleven resolved relocations,
 * 0 zero alignment bytes. Recompute each sample fade and
 * copy complete four-byte colors into the five-color row.
 * See docs/probe_archive/Thunder_constructors_20260924.md. */
// FUN_00495160
u8 *func_00495160(u8 *parameters)
{
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;

    copyCount = *(u32 *)(parameters + 0x38);
    func_0044ea90(D_00713E50, 0x50);
    list = (*jtbl_008873E8)(copyCount * 0x10 + 4, 0x40000);
    if (list == 0) {
        func_0046d730(D_00713E50, 0x51);
    }
    *(u8 **)(list + 0) = list + 4;
    if (*(u32 *)(parameters + 0x3C) < 3) {
        *(u32 *)(parameters + 0x3C) = 3;
    }
    color0 = *(u32 *)(parameters + 0x70);
    rgb0 = color0 & 0xFFFFFF;
    color1 = *(u32 *)(parameters + 0x74);
    rgb1 = color1 & 0xFFFFFF;
    color2 = *(u32 *)(parameters + 0x78);
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = *(u8 **)list;
    sampleTotal = (f32)(*(s32 *)(parameters + 0x3C) + 1);
    fadeStart = (s32)(*(f32 *)(parameters + 0x68) * sampleTotal);
    endIndex = (s32)(*(f32 *)(parameters + 0x6C) * sampleTotal);
    fadeEnd = (u32)endIndex;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        geometry = func_00482dc0(*(u16 *)(parameters + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)entry = geometry;
        sampleCount = *(s16 *)(geometry + 8) / 5;
        {
            u32 sampleIndex;
            u8 *colors;

            colors = *(u8 **)(*(u8 **)(*(u8 **)(geometry + 0x10) + 0x18) + 0x30);
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                if (sampleIndex < (u32)fadeStart) {
                    scaledAlpha = (f32)sampleIndex;
                    fade = scaledAlpha / (f32)fadeStart;
                } else if (fadeEnd < sampleIndex) {
                    s32 d1 = sampleCount - (s32)sampleIndex;
                    f32 v1 = (f32)(u32)d1;
                    f32 v0 = (f32)(u32)fadeOutCount;
                    fade = v1 / v0;
                } else {
                    fade = 1.0f;
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)colors = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 4) = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 8) = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    color1 = *(Color4 *)(colors + 4);
                    *(Color4 *)(colors + 12) = color1;
                    color0 = *(Color4 *)colors;
                    *(Color4 *)(colors + 16) = color0;
                }
                sampleIndex += 1;
                colors += 0x14;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            *(s32 *)(entry + 4) = value;
        }
        *(s32 *)(entry + 0xC) = 0;
        copyIndex += 1;
        entry += 0x10;
    }
    return list;
}
#pragma pop


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


/* Thunder bolt update. A live bolt rebuilds its strip: the first row is the
 * bolt cross-section from the forward/up cross products, and each further
 * row follows a sine-wave heading, rotated by func_004bd380 and pushed along
 * the transformed forward axis with per-column drift. The two
 * 5-column loops use separate counters, as retail's $t2/$v0 show. FPR
 * declarations follow the order a regalloc_whatif.py replay derived.
 * func_004bd380 is declared angle-first here: retail sets $f12 before $a0,
 * and b210 emits argument setup in declaration order (handoff 7a-bis). */
static inline f32 thunderAdd(f32 first, f32 second) { return first + second; }
#pragma push
#pragma opt_loop_invariants on
// FUN_004956B0
void func_004956b0(u8 *arg0)
{
    extern void func_0048a1f0(f32 *arg0);
    extern void func_004bceb0(void);
    extern f32 sinf(f32 arg0);
    extern f32 cosf(f32 arg0);
    extern f32 sqrtf(f32 arg0);
    extern f32 func_0044b938(f32 arg0);
    extern void func_004bd380(f32 angle, f32 *axis);
    extern void RpGeometryLock(u8 *geometry, s32 lockMode);
    extern void func_003c22f0(u8 *geometry);
    extern f32 fGpffff8084;
    extern f32 iGpffff8084;
    extern f32 fGpffff80e4;
    extern f32 fGpffff80e8;
    extern f32 fGpffff80ec;
    extern EffectVuVector D_00713D00;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    f32 drift[5];
    f32 widths[5];
    EffectVuVector forward;
    EffectVuVector up;
    EffectVuVector axis;
    f32 segmentLength;
    f32 segmentScale;
    f32 phase;
    f32 wave;
    f32 amplitude;
    f32 previous;
    f32 angle;
    f32 jitter;
    f32 offset;
    f32 length;
    f32 negone;
    f32 zero;
    f32 phaseStep;
    f32 shift;
    f32 base;
    f32 lengthScale;
    f32 lengthSpread;
    f32 hypot;
    f32 one;
    f32 twoPi;
    f32 waveRange;
    f32 waveBase;
    f32 jitterRange;
    f32 jitterBase;
    f32 half;
    f32 next;
    f32 nextAngle;
    u8 *config;
    u8 *bolt;
    u8 *list;
    u32 state;
    s32 index;
    s32 count;
    s32 respawnRange;
    u8 *instance;
    s32 row;
    u8 *vertices;
    s32 rows;
    s32 j;
    s32 k;

    list = *(u8 **)(arg0 + 0x30);
    config = *(u8 **)(arg0 + 0x34);
    bolt = *(u8 **)list;
    if ((*(u32 *)(config + 0x34) < *(u32 *)(arg0 + 0x28)) && (*(u32 *)(config + 0x34) != 0)) {
        return;
    }
    count = *(s32 *)(config + 0x38);
    respawnRange = *(s32 *)(config + 0x40);
    lengthScale = *(f32 *)(config + 0x54);
    lengthSpread = *(f32 *)(config + 0x58);
    segmentScale = (f32)*(u32 *)(config + 0x3C);
    segmentLength = *(f32 *)(config + 0x84) / segmentScale;
    twoPi = fGpffff8084;
    /* Retail reloads the 2pi literal here instead of reusing twoPi. */
    phaseStep = (iGpffff8084 * (f32)*(u32 *)(config + 0x4C)) / segmentScale;
    amplitude = *(f32 *)(config + 0x50);
    if (segmentLength <= 0.0f) {
        return;
    }
    func_0048a1f0(up.lane);
    effectVuLoad10((EffectVuVector *)(arg0 + 0x10));
    func_004bceb0();
    effectVuLoad10(&D_00713D00);
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
    effectVuStore10(&forward);
    jitter = fGpffff80e4;
    zero = 0.0f;
    widths[0] = 0.0f;
    widths[1] = *(f32 *)(config + 0x80);
    widths[2] = widths[1] + *(f32 *)(config + 0x7C);
    widths[3] = widths[2] + *(f32 *)(config + 0x7C);
    widths[4] = widths[3] + widths[1];
    index = 0;
    one = 1.0f;
    negone = -1.0f;
    waveRange = fGpffff80e8;
    waveBase = fGpffff80ec;
    jitterRange = 0.75f;
    jitterBase = 0.25f;
    half = 0.5f;
    for (; index < count; index++, bolt += 0x10) {
        if (*(s32 *)(bolt + 4) == -1) {
            *(s32 *)(bolt + 8) = -1;
            goto advance;
        }
        length = (lengthScale * ((one - lengthSpread) + lengthSpread * effMiscRandFloat(0))) / segmentScale;
        base = *(f32 *)(bolt + 0xC);
        if ((effMiscRand(0) & 1) != 0) {
            length = length * negone;
        }
        offset = length;
        state = *(u32 *)(bolt + 8);
        if ((state & 0xFF000000) > 0x40000000U) {
            *(u32 *)(bolt + 8) = state + 0xC0000000;
        } else {
            *(s32 *)(bolt + 4) = -1;
            if (respawnRange > 0) {
                *(s32 *)(bolt + 4) = *(s32 *)(bolt + 4) - effMiscRand(0) % respawnRange;
            }
            continue;
        }
        instance = *(u8 **)bolt;
        rows = *(s16 *)(instance + 8) / 5;
        RpGeometryLock(*(u8 **)(*(u8 **)(instance + 0x10) + 0x18), 2);
        vertices = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(instance + 0x10) + 0x18) + 0x5C) + 0x14);
        if ((effMiscRand(0) & 1) != 0) {
            amplitude = amplitude * negone;
        }
        phase = twoPi * effMiscRandFloat(0);
        wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
        angle = wave * sinf(phase);
        phase += phaseStep;
        previous = wave * sinf(phase);
        {
            f32 rise = previous - angle;
            f32 inner;
            f32 outer;

            angle = func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength));
            inner = *(f32 *)(config + 0x7C);
            outer = inner + *(f32 *)(config + 0x80);
            angle = angle + base;
            effectVuLoad10(&forward);
            effectVuLoad11(&up);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf2", "$vf10", "$vf12");
            effectVuLoad11(&forward);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n" : : : "$vf10");
            effectVuStore10(&axis);
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vmove.xyzw $vf11, $vf12\n" : : : "$vf10", "$vf11");
            effectVuScale10(outer);
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x0) = D_00713D10[0];
            *(f32 *)(vertices + 0x4) = D_00713D14[0];
            *(f32 *)(vertices + 0x8) = D_00713D18[0];
            __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x30) = D_00713D10[0];
            *(f32 *)(vertices + 0x34) = D_00713D14[0];
            *(f32 *)(vertices + 0x38) = D_00713D18[0];
            effectVuScale11(inner);
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0xC) = D_00713D10[0];
            *(f32 *)(vertices + 0x10) = D_00713D14[0];
            *(f32 *)(vertices + 0x14) = D_00713D18[0];
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x24) = D_00713D10[0];
            *(f32 *)(vertices + 0x28) = D_00713D14[0];
            *(f32 *)(vertices + 0x2C) = D_00713D18[0];
            *(f32 *)(vertices + 0x18) = zero;
            *(f32 *)(vertices + 0x1C) = zero;
            *(f32 *)(vertices + 0x20) = zero;
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
            effectVuScale11(previous);
        }
        for (j = 0; j < 5; j++) {
            u8 *vertex = vertices + j * 12;
            D_00713D10[0] = *(f32 *)(vertex + 0x0);
            D_00713D14[0] = *(f32 *)(vertex + 0x4);
            D_00713D18[0] = *(f32 *)(vertex + 0x8);
            effectVuLoad10((EffectVuVector *)D_00713D10);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertex + 0x0) = D_00713D10[0];
            *(f32 *)(vertex + 0x4) = D_00713D14[0];
            *(f32 *)(vertex + 0x8) = D_00713D18[0];
            drift[j] = zero;
        }
        vertices += 0x3C;
        for (row = 1; row < rows; row++, vertices += 0x3C) {
            f32 slope;

            shift = jitter * (jitterBase + jitterRange * effMiscRandFloat(0));
            if ((effMiscRand(0) & 1) != 0) {
                jitter = jitter * negone;
            }
            phase += phaseStep;
            if (!(phase < twoPi)) {
                phase -= twoPi;
                amplitude = amplitude * negone;
                wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
            }
            next = wave * sinf(phase);
            {
                f32 rise = next - previous;

                hypot = sqrtf(rise * rise + segmentLength * segmentLength);
                nextAngle = thunderAdd(thunderAdd(func_0044b938(rise / hypot), shift + offset), base);
            }
            func_004bd380(angle, axis.lane);
            effectVuLoad10(&forward);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            previous = half * (nextAngle - angle);
            angle = sinf(previous);
            slope = angle / cosf(previous);
            previous = next;
            angle = nextAngle;
            offset += length;
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            for (k = 0; k < 5; k++) {
                u8 *vertex;
                f32 step = slope * widths[k];

                drift[k] = drift[k] + step;
                __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
                vertex = vertices + k * 12;
                D_00713D10[0] = *(f32 *)(vertex - 0x3C);
                D_00713D14[0] = *(f32 *)(vertex - 0x38);
                D_00713D18[0] = *(f32 *)(vertex - 0x34);
                effectVuLoad10((EffectVuVector *)D_00713D10);
                effectVuScale11(hypot + drift[k]);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                *(f32 *)(vertex + 0x0) = D_00713D10[0];
                *(f32 *)(vertex + 0x4) = D_00713D14[0];
                *(f32 *)(vertex + 0x8) = D_00713D18[0];
                drift[k] = step;
            }
        }
        vertices = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
        func_003c22f0(vertices);
        if ((*(u16 *)instance & 4) != 0) {
            *(u16 *)(vertices + 0xC) |= 1;
        }
advance:
        *(s32 *)(bolt + 4) = *(s32 *)(bolt + 4) + 1;
    }
}
#pragma pop


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
    v = *(f32 *)(obj1 + 0x8C) * (a * effMiscRandFloat(0) + (1.0f - a));
    if (count > 0)
    {
        f32 b = *(f32 *)(obj1 + 0x98);
        f32 w = *(f32 *)(obj1 + 0x94) * (b * effMiscRandFloat(0) + (1.0f - b));
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
        p[5] = -1 - (effMiscRand(0) & 7);
        i++;
        p += 0xC;
    }
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1224/1232 bytes, eleven resolved relocations,
 * 8 zero alignment bytes. Recompute each sample fade and
 * copy complete four-byte colors into the five-color row.
 * See docs/probe_archive/Thunder_constructors_20260924.md. */
// FUN_00496340
u8 *func_00496340(u8 *parameters)
{
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;

    copyCount = *(u32 *)(parameters + 0x38);
    func_0044ea90(D_00713E50, 0x2B5);
    list = (*jtbl_008873E8)(copyCount * 0x30 + 0x10, 0x40000);
    if (list == 0) {
        func_0046d730(D_00713E50, 0x2B6);
    }
    *(u8 **)(list + 0) = list + 0x10;
    *(u8 **)(list + 0x0C) = list;
    if (*(u32 *)(parameters + 0x3C) < 3) {
        *(u32 *)(parameters + 0x3C) = 3;
    }
    color0 = *(u32 *)(parameters + 0x70);
    rgb0 = color0 & 0xFFFFFF;
    color1 = *(u32 *)(parameters + 0x74);
    rgb1 = color1 & 0xFFFFFF;
    color2 = *(u32 *)(parameters + 0x78);
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = *(u8 **)list;
    sampleTotal = (f32)(*(s32 *)(parameters + 0x3C) + 1);
    fadeStart = (s32)(*(f32 *)(parameters + 0x68) * sampleTotal);
    endIndex = (s32)(*(f32 *)(parameters + 0x6C) * sampleTotal);
    fadeEnd = (u32)endIndex;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        geometry = func_00482dc0(*(u16 *)(parameters + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)entry = geometry;
        sampleCount = *(s16 *)(geometry + 8) / 5;
        {
            u32 sampleIndex;
            u8 *colors;

            colors = *(u8 **)(*(u8 **)(*(u8 **)(geometry + 0x10) + 0x18) + 0x30);
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                if (sampleIndex < (u32)fadeStart) {
                    scaledAlpha = (f32)sampleIndex;
                    fade = scaledAlpha / (f32)fadeStart;
                } else if (fadeEnd < sampleIndex) {
                    s32 d1 = sampleCount - (s32)sampleIndex;
                    f32 v1 = (f32)(u32)d1;
                    f32 v0 = (f32)(u32)fadeOutCount;
                    fade = v1 / v0;
                } else {
                    fade = 1.0f;
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)colors = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 4) = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 8) = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    color1 = *(Color4 *)(colors + 4);
                    *(Color4 *)(colors + 12) = color1;
                    color0 = *(Color4 *)colors;
                    *(Color4 *)(colors + 16) = color0;
                }
                sampleIndex += 1;
                colors += 0x14;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            *(s32 *)(entry + 0x14) = value;
        }
        copyIndex += 1;
        entry += 0x30;
    }
    return list;
}
#pragma pop


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


/* Orbiting thunder bolt update, the func_004956b0 sibling. A bolt in its
 * spawn state picks an orbit and places its anchor through the VU0 matrix;
 * a live bolt advances the orbit, builds its first row across the travel
 * direction and steps each further row along the rotated travel vector,
 * whose length comes from VU0 vsqrt. The two 5-column loops use separate
 * counters. The spilled locals are declared in retail's spill-slot order.
 * func_004bd380 is declared angle-first, as for func_004956b0. */
#pragma push
#pragma opt_loop_invariants on
// FUN_004968A0
void func_004968a0(u8 *arg0)
{
    extern void func_0048a1f0(f32 *arg0);
    extern f32 sinf(f32 arg0);
    extern f32 cosf(f32 arg0);
    extern f32 sqrtf(f32 arg0);
    extern f32 func_0044b938(f32 arg0);
    extern f32 func_0044b340(f32 arg0);
    extern void func_004bd1a0(f32 arg0);
    extern void func_004bd3c0(f32 arg0);
    extern void func_004bd450(void);
    extern void func_004bd380(f32 angle, f32 *axis);
    extern void RpGeometryLock(u8 *geometry, s32 lockMode);
    extern void func_003c22f0(u8 *geometry);
    extern f32 fGpffff804c;
    extern f32 fGpffff8084;
    extern f32 fGpffff8098;
    extern f32 fGpffff809c;
    extern f32 iGpffff80d4;
    extern f32 fGpffff80d8;
    extern f32 fGpffff80dc;
    extern f32 fGpffff80e0;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    f32 drift[5];
    f32 widths[5];
    EffectVuVector delta;
    EffectVuVector heading;
    EffectVuVector side;
    EffectVuVector up;
    EffectVuVector point;
    EffectVuVector position;
    EffectVuVector step;
    f32 segmentLength;
    f32 phase;
    f32 wave;
    f32 amplitude;
    f32 previous;
    f32 angle;
    f32 jitter;
    f32 radius;
    f32 zero;
    f32 half;
    f32 two;
    f32 twoPi;
    f32 outer;
    f32 inner;
    f32 phaseStep;
    f32 shift;
    f32 spin;
    f32 dropScale;
    f32 drop;
    f32 stepLength;
    f32 one;
    f32 tilt;
    f32 negone;
    f32 waveRange;
    f32 waveBase;
    f32 dropRange;
    f32 dropBase;
    f32 jitterRange;
    f32 jitterBase;
    f32 orbit;
    f32 next;
    f32 nextAngle;
    u8 *config;
    u8 *bolt;
    u8 *list;
    u32 state;
    s32 index;
    s32 count;
    s32 respawnRange;
    u8 *instance;
    s32 row;
    u8 *vertices;
    s32 rows;
    s32 j;
    s32 k;
    u8 mode;

    list = *(u8 **)(arg0 + 0x30);
    config = *(u8 **)(arg0 + 0x34);
    bolt = *(u8 **)list;
    if ((*(u32 *)(config + 0x34) < *(u32 *)(arg0 + 0x28)) && (*(u32 *)(config + 0x34) != 0)) {
        return;
    }
    count = *(s32 *)(config + 0x38);
    respawnRange = *(s32 *)(config + 0x40);
    {
        f32 segmentScale = (f32)*(u32 *)(config + 0x3C);

        segmentLength = *(f32 *)(config + 0x84) / segmentScale;
        phaseStep = (fGpffff8084 * (f32)*(u32 *)(config + 0x4C)) / segmentScale;
    }
    amplitude = *(f32 *)(config + 0x50);
    spin = *(f32 *)(config + 0xA8);
    mode = *(u8 *)(config + 0x88);
    if (segmentLength <= 0.0f) {
        return;
    }
    func_0048a1f0(up.lane);
    jitter = fGpffff80d8;
    dropScale = -(fGpffff804c * (segmentLength / 10.0f));
    zero = 0.0f;
    widths[0] = 0.0f;
    widths[1] = *(f32 *)(config + 0x80);
    widths[2] = widths[1] + *(f32 *)(config + 0x7C);
    widths[3] = widths[2] + *(f32 *)(config + 0x7C);
    widths[4] = widths[3] + widths[1];
    one = 1.0f;
    delta.lane[3] = 1.0f;
    point.lane[3] = 1.0f;
    radius = *(f32 *)(list + 4);
    *(f32 *)(list + 4) = radius + *(f32 *)(list + 8);
    index = 0;
    half = 0.5f;
    two = 2.0f;
    twoPi = fGpffff8084;
    tilt = fGpffff80dc;
    negone = -1.0f;
    waveRange = iGpffff80d4;
    waveBase = fGpffff80e0;
    dropRange = fGpffff809c;
    dropBase = fGpffff8098;
    jitterRange = 0.75f;
    jitterBase = 0.25f;
    for (; index < count; index++, bolt += 0x30) {
        if (*(s32 *)(bolt + 0x14) == -1) {
            f32 t = *(f32 *)(config + 0xA4);

            *(f32 *)(bolt + 0x24) = *(f32 *)(config + 0xA0) * ((one - t) + t * effMiscRandFloat(0));
            *(f32 *)(bolt + 0x28) = zero;
            if (mode == 0) {
                *(f32 *)(bolt + 0x1C) = twoPi * (two * (effMiscRandFloat(0) - half));
                *(f32 *)(bolt + 0x2C) = zero;
            } else {
                *(f32 *)(bolt + 0x1C) = tilt * (two * (effMiscRandFloat(0) - half));
                *(f32 *)(bolt + 0x2C) = *(f32 *)(config + 0x9C) * effMiscRandFloat(0);
            }
            *(f32 *)(bolt + 0x20) = twoPi * (two * (effMiscRandFloat(0) - half));
            func_004bd1a0(*(f32 *)(bolt + 0x1C));
            func_004bd3c0(*(f32 *)(bolt + 0x20));
            func_004bd450();
            angle = *(f32 *)(bolt + 0x28);
            point.lane[0] = radius * cosf(angle);
            point.lane[1] = zero;
            point.lane[2] = radius * sinf(angle);
            effectVuLoad10(&point);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&point);
            *(f32 *)(bolt + 0x4) = point.lane[0];
            *(f32 *)(bolt + 0x8) = point.lane[1];
            *(f32 *)(bolt + 0xC) = point.lane[2];
            *(s32 *)(bolt + 0x18) = -1;
            goto advance;
        }
        state = *(u32 *)(bolt + 0x18);
        if ((state & 0xFF000000) > 0x40000000U) {
            *(u32 *)(bolt + 0x18) = state + 0xC0000000;
        } else {
            *(s32 *)(bolt + 0x14) = -1;
            if (respawnRange > 0) {
                *(s32 *)(bolt + 0x14) = *(s32 *)(bolt + 0x14) - effMiscRand(0) % respawnRange;
            }
            continue;
        }
        instance = *(u8 **)bolt;
        rows = *(s16 *)(instance + 8) / 5;
        RpGeometryLock(*(u8 **)(*(u8 **)(instance + 0x10) + 0x18), 2);
        vertices = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(instance + 0x10) + 0x18) + 0x5C) + 0x14);
        if ((effMiscRand(0) & 1) != 0) {
            amplitude = amplitude * negone;
        }
        phase = twoPi * effMiscRandFloat(0);
        wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
        angle = wave * sinf(phase);
        phase += phaseStep;
        previous = wave * sinf(phase);
        {
            f32 rise = previous - angle;

            f32 tilted = func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength));

            inner = *(f32 *)(config + 0x7C);
            outer = inner + *(f32 *)(config + 0x80);
            angle = tilted;
        }
        drop = dropScale * (dropBase + dropRange * effMiscRandFloat(0));
        {
            f32 t = (f32)(*(s32 *)(bolt + 0x14) + 1);

            orbit = t * (*(f32 *)(bolt + 0x24) + half * (spin * t));
            orbit += *(f32 *)(bolt + 0x28);
        }
        func_004bd1a0(*(f32 *)(bolt + 0x1C));
        func_004bd3c0(*(f32 *)(bolt + 0x20));
        func_004bd450();
        point.lane[0] = radius * cosf(orbit);
        point.lane[1] = zero;
        point.lane[2] = radius * sinf(orbit);
        effectVuLoad10(&point);
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x\n"
            "vmadday.xyzw $ACC, $vf29, $vf10y\n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
        effectVuStore10(&point);
        effectVuStore10(&position);
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
        effectVuStore10(&heading);
        delta.lane[0] = position.lane[0] - *(f32 *)(bolt + 0x4);
        delta.lane[1] = position.lane[1] - *(f32 *)(bolt + 0x8);
        delta.lane[2] = position.lane[2] - *(f32 *)(bolt + 0xC);
        effectVuLoad10(&delta);
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n"
            "vmove.xyzw $vf12, $vf10\n" : : : "$vf2", "$vf10", "$vf12");
        effectVuLoad11(&heading);
        effectVuStore10(&delta);
        __asm__ volatile(
            "vopmula.xyz $ACC, $vf10, $vf11\n"
            "vopmsub.xyz $vf10, $vf11, $vf10\n" : : : "$vf10");
        effectVuStore10(&side);
        effectVuLoad11(&up);
        __asm__ volatile(
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
            "vmove.xyzw $vf11, $vf10\n" : : : "$vf2", "$vf10", "$vf11", "$vf12");
        effectVuScale10(outer);
        __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        *(f32 *)(vertices + 0x0) = D_00713D10[0];
        *(f32 *)(vertices + 0x4) = D_00713D14[0];
        *(f32 *)(vertices + 0x8) = D_00713D18[0];
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10");
        __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        *(f32 *)(vertices + 0x30) = D_00713D10[0];
        *(f32 *)(vertices + 0x34) = D_00713D14[0];
        *(f32 *)(vertices + 0x38) = D_00713D18[0];
        effectVuScale11(inner);
        __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        *(f32 *)(vertices + 0xC) = D_00713D10[0];
        *(f32 *)(vertices + 0x10) = D_00713D14[0];
        *(f32 *)(vertices + 0x14) = D_00713D18[0];
        __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11");
        __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        *(f32 *)(vertices + 0x24) = D_00713D10[0];
        *(f32 *)(vertices + 0x28) = D_00713D14[0];
        *(f32 *)(vertices + 0x2C) = D_00713D18[0];
        *(f32 *)(vertices + 0x18) = zero;
        *(f32 *)(vertices + 0x1C) = zero;
        *(f32 *)(vertices + 0x20) = zero;
        point.lane[1] = point.lane[1] + *(f32 *)(bolt + 0x2C);
        effectVuLoad11(&point);
        for (j = 0; j < 5; j++) {
            u8 *vertex = vertices + j * 12;
            D_00713D10[0] = *(f32 *)(vertex + 0x0);
            D_00713D14[0] = *(f32 *)(vertex + 0x4);
            D_00713D18[0] = *(f32 *)(vertex + 0x8);
            effectVuLoad10((EffectVuVector *)D_00713D10);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertex + 0x0) = D_00713D10[0];
            *(f32 *)(vertex + 0x4) = D_00713D14[0];
            *(f32 *)(vertex + 0x8) = D_00713D18[0];
            drift[j] = zero;
        }
        vertices += 0x3C;
        *(f32 *)(bolt + 0x4) = position.lane[0];
        *(f32 *)(bolt + 0x8) = position.lane[1];
        *(f32 *)(bolt + 0xC) = position.lane[2];
        for (row = 1; row < rows; row++, vertices += 0x3C) {
            f32 slope;

            shift = jitter * (jitterBase + jitterRange * effMiscRandFloat(0));
            if ((effMiscRand(0) & 1) != 0) {
                jitter = jitter * negone;
            }
            phase += phaseStep;
            if (!(phase < twoPi)) {
                phase -= twoPi;
                amplitude = amplitude * negone;
                wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
                drop = dropScale * (dropBase + dropRange * effMiscRandFloat(0));
            }
            next = wave * sinf(phase);
            {
                f32 rise = next - previous;

                nextAngle = thunderAdd(func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength)), shift);
            }
            func_004bd380(angle, heading.lane);
            effectVuLoad10(&delta);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&step);
            func_004bd380(drop, side.lane);
            effectVuLoad10(&delta);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&delta);
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10", "$vf11");
            effectVuStore10(&position);
            /* Retail moves the vsqrt result through $2 (cfc2/mtc1 bridge). */
            __asm__ volatile(
                "vsub.xyzw $vf10, $vf10, $vf11\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vaddy.x $vf2, $vf2, $vf2y\n"
                "vaddz.x $vf2, $vf2, $vf2z\n"
                "vsqrt $Q, $vf2x\n"
                "vwaitq\n"
                "cfc2.ni $2, $vi22\n"
                "mtc1 $2, %0\n" : "=f"(stepLength) : : "$2", "$vf2", "$vf10");
            slope = func_0044b340(half * (nextAngle - angle));
            previous = next;
            angle = nextAngle;
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&step), "m"(step) : "$vf12");
            for (k = 0; k < 5; k++) {
                u8 *vertex;
                f32 offset = slope * widths[k];

                drift[k] = drift[k] + offset;
                __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
                vertex = vertices + k * 12;
                D_00713D10[0] = *(f32 *)(vertex - 0x3C);
                D_00713D14[0] = *(f32 *)(vertex - 0x38);
                D_00713D18[0] = *(f32 *)(vertex - 0x34);
                effectVuLoad10((EffectVuVector *)D_00713D10);
                effectVuScale11(stepLength + drift[k]);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                *(f32 *)(vertex + 0x0) = D_00713D10[0];
                *(f32 *)(vertex + 0x4) = D_00713D14[0];
                *(f32 *)(vertex + 0x8) = D_00713D18[0];
                drift[k] = offset;
            }
        }
        vertices = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
        func_003c22f0(vertices);
        if ((*(u16 *)instance & 4) != 0) {
            *(u16 *)(vertices + 0xC) |= 1;
        }
advance:
        *(s32 *)(bolt + 0x14) = *(s32 *)(bolt + 0x14) + 1;
    }
}
#pragma pop


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
        p[1] = -1 - (effMiscRand(0) & 3);
        i++;
        p += 3;
    }
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1280/1280 bytes and eleven resolved relocations.
 * Sample zero and odd samples calculate a new fade; the following even
 * sample reuses it. The five packed colors form one twenty-byte row.
 * See docs/probe_archive/Thunder_constructor_00497750_20260924.md. */
// FUN_00497750
u8 *func_00497750(u8 *parameters)
{
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;

    copyCount = *(u32 *)(parameters + 0x38);
    func_0044ea90(D_00713E50, 0x499);
    list = (*jtbl_008873E8)(copyCount * 0x0C + 4, 0x40000);
    if (list == 0) {
        func_0046d730(D_00713E50, 0x49A);
    }
    *(u8 **)(list + 0) = list + 4;
    if (*(u32 *)(parameters + 0x3C) < 3) {
        *(u32 *)(parameters + 0x3C) = 3;
    }
    if ((*(u32 *)(parameters + 0x3C) & 1) == 0) {
        *(u32 *)(parameters + 0x3C) += 1;
    }
    color0 = *(u32 *)(parameters + 0x70);
    rgb0 = color0 & 0xFFFFFF;
    color1 = *(u32 *)(parameters + 0x74);
    rgb1 = color1 & 0xFFFFFF;
    color2 = *(u32 *)(parameters + 0x78);
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = *(u8 **)list;
    sampleTotal = (f32)(*(s32 *)(parameters + 0x3C) + 1);
    fadeStart = (s32)(*(f32 *)(parameters + 0x68) * sampleTotal);
    endIndex = (s32)(*(f32 *)(parameters + 0x6C) * sampleTotal);
    fadeEnd = (u32)endIndex;
    /* Retail retains this initial value across geometry allocations. */
    fade = 0.0f;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        geometry = func_00482dc0(*(u16 *)(parameters + 0x3C), D_00713360, 5, 0x48);
        *(u8 **)entry = geometry;
        sampleCount = *(s16 *)(geometry + 8) / 5;
        {
            u32 sampleIndex;
            u8 *colors;

            colors = *(u8 **)(*(u8 **)(*(u8 **)(geometry + 0x10) + 0x18) + 0x30);
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                if ((sampleIndex & 1) || (sampleIndex == 0)) {
                    if (sampleIndex < (u32)fadeStart) {
                        scaledAlpha = (f32)sampleIndex;
                        fade = scaledAlpha / (f32)fadeStart;
                    } else if (fadeEnd < sampleIndex) {
                        s32 d1 = sampleCount - (s32)sampleIndex - 1;
                        f32 v1 = (f32)(u32)d1;
                        f32 v0 = (f32)(u32)fadeOutCount;
                        fade = v1 / v0;
                    } else {
                        fade = 1.0f;
                    }
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)colors = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 4) = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                *(u32 *)(colors + 8) = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    color1 = *(Color4 *)(colors + 4);
                    *(Color4 *)(colors + 12) = color1;
                    color0 = *(Color4 *)colors;
                    *(Color4 *)(colors + 16) = color0;
                }
                colors += 0x14;
                sampleIndex += 1;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            *(s32 *)(entry + 4) = value;
        }
        copyIndex += 1;
        entry += 0x0C;
    }
    return list;
}
#pragma pop


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
    extern u32 effMiscRand(u32 arg0);
    extern f32 effMiscRandFloat(u32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_004bd380(u8 *axis, f32 angle);
    extern void RpGeometryLock(u8 *a, s32 b);
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
                    RpGeometryLock(*(u8 **)(*(u8 **)(e0 + 0x10) + 0x18), 2);
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
                    f30loc = gp80d0 * effMiscRandFloat(0);
                    f29loc = f30loc - gp80d0;
                    f28loc = f27loc * sinf(f30loc);
                    {
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)\n"
                            "qmtc2.ni %1, $vf2\n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                            "sqc2 $vf10, 0(%2)\n"
                            : : "r"(sp150), "r"(*(u32 *)&f28loc), "r"(sp120) : "$vf10", "$vf2", "memory");
                    }
                    f20loc = f27loc * sinf(f30loc);
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
                                r = effMiscRandFloat(0);
                                f27loc = f44 * (stkEC - gp80d4 * r);
                                (void)stkE0; (void)stkE4; (void)stkE8;
                            }
                            spillDC = f20loc;
                            f20loc = f27loc * sinf(f30loc);
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
                                f32 r2 = effMiscRandFloat(0);
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
                        u32 rnd = effMiscRand(0);
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
    memcpy(*(void **)(p + 0x34), arg1, size);
    *(u32 *)(p + 0x30) = ((u32 (*)(u8 *))D_00713E74[arg0 * 6])(arg1);
    ((void (*)(u8 *))D_00713E70[arg0 * 6])(p);
    return p;
}


// FUN_00498A30
void *func_00498a30(void *arg0)
{
    u8 *tex;

    tex = func_00484490(arg0);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6C9);
    }
    tex = func_004988c0(*(u16 *)((u8 *)arg0 + 0xC), tex);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6CB);
    }
    return tex;
}
