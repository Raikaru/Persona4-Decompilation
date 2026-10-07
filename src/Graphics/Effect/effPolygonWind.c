#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonWind.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RpGeometry RpGeometry;

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
extern u8 *func_00483e10(s32, s32, s32, s32, s32);
extern s32 func_00481300(s32);
extern void func_004842d0(void *, s32);
extern void func_004843f0(void *, s32);
extern void func_004a1d70(void *, void *);
extern void func_004a30e0(u8 *, u8 *);
extern void func_004a4450(u8 *, u8 *);
extern u8 *func_00484010(u8 *);
extern RpGeometry *RpGeometryLock(RpGeometry *, s32);
extern void *memcpy(void *, const void *, u32);
extern char D_00713330[];
extern char D_00714148[];
extern u_long128 D_00713CE0;

extern void func_0046d730(void *, s32);
extern s32 func_0048abd0(u8 *, u8 *, s32, s32);
extern void func_004843a0();
extern void func_00484280();
extern f32 effMiscRandFloat(u32);
extern u32 effMiscRand(u32);
extern void memset(void *, s32, s32);
extern void func_004bd1a0(f32);
extern void func_004bd3c0(f32);
extern void func_004bd450(void);
extern f32 cosf(f32);
extern f32 sinf(f32);
extern RpGeometry *func_003c22f0(RpGeometry *);
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
    *(u8 **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
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
    *(u8 **)(work + 4) = func_00484010(*(u8 **)(p16 + 4));
    func_004a1d70(work, p17);
    return work;
}

/* Funnel wind strip update, the func_004a4a10 sibling without the VU0 matrix:
 * each sample sits on a ring of radius base + swell * (s - centre)^2 at a
 * rising height, and the strip is widened along the normalised ring offset.
 * One float local carries the spawn start, every spawn interpolation weight
 * and the cosine; another carries the end weight and the swell term, as
 * retail's shared $f20/$f23 show. FPR declarations follow the order a
 * regalloc_whatif.py replay of the captured colouring derived; the spilled
 * locals are declared in retail's spill-slot order. */
// FUN_004A2310
void func_004a2310(u8 *arg0)
{
    EffectVuVector point;
    EffectVuVector normal;
    f32 width;
    f32 vStep;
    f32 angle;
    f32 step;
    f32 height;
    f32 rise;
    f32 c;
    f32 t;
    f32 sampleScale;
    f32 radius;
    f32 end;
    f32 one;
    f32 zero;
    f32 v0;
    f32 base;
    f32 accel;
    f32 vSpan;
    f32 swell;
    f32 centre;
    f32 spin;
    f32 half;
    f32 quarter;
    u32 index;
    s32 segmentCount;
    u8 *instance;
    u32 lifetime;
    u8 *particle;
    u32 sample;
    u8 *vertices;
    u8 *texCoords;
    u8 *config;
    u32 particleCount;
    u32 respawn;
    u32 sampleCount;
    s32 spawnAll;
    u32 pending;
    u32 elapsed;
    u32 limit;
    u8 *list;
    u8 *geometry;
    u32 state;

    config = *(u8 **)(arg0 + 0x40);
    limit = *(u32 *)(config + 0x34);
    elapsed = *(u32 *)(arg0 + 0x34);
    if ((limit < elapsed) && (limit != 0)) {
        return;
    }
    particleCount = *(u32 *)(config + 0x38);
    lifetime = *(u32 *)(config + 0x80);
    if (lifetime == 0) {
        return;
    }
    if ((*(u8 *)(config + 0xB8) != 0) && (elapsed == 0)) {
        spawnAll = 1;
        pending = particleCount;
    } else {
        spawnAll = 0;
        pending = *(u32 *)(config + 0x84);
    }
    list = *(u8 **)(arg0 + 0x3C);
    particle = *(u8 **)list;
    instance = *(u8 **)(list + 4);
    respawn = *(u8 *)(config + 0x88);
    accel = *(f32 *)(config + 0xF4);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(instance + 0x10) + 0x18), 0xFF2);
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    vertices = *(u8 **)(*(u8 **)(geometry + 0x5C) + 0x14);
    texCoords = *(u8 **)(geometry + 0x34);
    segmentCount = *(s16 *)(instance + 8);
    sampleCount = *(u32 *)(config + 0x8C) + 1;
    sampleScale = (f32)sampleCount;
    vSpan = *(f32 *)(config + 0x98);
    centre = *(f32 *)(config + 0xE4);
    vStep = *(f32 *)(config + 0xA4);
    index = 0;
    one = 1.0f;
    spin = iGpffff8080;
    half = 0.5f;
    zero = 0.0f;
    quarter = 0.25f;
    for (; index < particleCount; index++, particle += 0x30) {
        state = *(u32 *)particle;
        if (state == (u32)-2) {
            goto skip;
        }
        if (state == (u32)-1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            t = *(f32 *)(config + 0xC0);
            t = *(f32 *)(config + 0xBC) * ((one - t) + t * effMiscRandFloat(0));
            end = *(f32 *)(config + 0xC8);
            *(f32 *)(particle + 0xC) = (*(f32 *)(config + 0xC4) * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            *(f32 *)(particle + 0x8) = t;
            t = *(f32 *)(config + 0xD0);
            t = *(f32 *)(config + 0xCC) * ((one - t) + t * effMiscRandFloat(0));
            end = *(f32 *)(config + 0xD8);
            *(f32 *)(particle + 0x14) = (*(f32 *)(config + 0xD4) * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            *(f32 *)(particle + 0x10) = t;
            t = *(f32 *)(config + 0xE0);
            *(f32 *)(particle + 0x28) = *(f32 *)(config + 0xE8) * ((one - t) + t * effMiscRandFloat(0));
            *(f32 *)(particle + 0x1C) = spin * effMiscRandFloat(0);
            t = *(f32 *)(config + 0xF0);
            *(f32 *)(particle + 0x18) = *(f32 *)(config + 0xEC) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xB4);
            *(f32 *)(particle + 0x20) = *(f32 *)(config + 0xB0) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xAC);
            *(f32 *)(particle + 0x24) = *(f32 *)(config + 0xA8) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0x9C);
            *(f32 *)(particle + 0x2C) = *(f32 *)(config + 0x98) * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                *(u32 *)particle = effMiscRand(0) % lifetime;
                t = (f32)*(s32 *)particle;
                *(f32 *)(particle + 0x10) = *(f32 *)(particle + 0x10) + *(f32 *)(particle + 0x14) * t;
                *(f32 *)(particle + 0x8) = *(f32 *)(particle + 0x8) + *(f32 *)(particle + 0xC) * t;
            } else {
                *(u32 *)particle = 0;
            }
            pending--;
            goto skip;
        }
        if (state >= lifetime) {
            if (respawn != 0) {
                *(u32 *)particle = (u32)-1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                *(u32 *)particle = (u32)-2;
            }
            if (iGpffffbb64.c3 != 0xFF) {
                u8 *color = *(u8 **)(*(u8 **)(instance + 0x54) + (u16)index * 4);
                *(PolygonWindColor *)(color + 4) = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *color = *(u8 **)(*(u8 **)(instance + 0x54) + (u16)index * 4);
                    *(PolygonWindColor *)(color + 4) = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            goto skip;
        }
        t = (f32)(s32)state;
        angle = t * (*(f32 *)(particle + 0x18) + half * (accel * t));
        angle += *(f32 *)(particle + 0x1C);
        *(f32 *)(particle + 0x10) = *(f32 *)(particle + 0x10) + *(f32 *)(particle + 0x14);
        *(f32 *)(particle + 0x8) = *(f32 *)(particle + 0x8) + *(f32 *)(particle + 0xC);
        height = zero;
        rise = *(f32 *)(particle + 0x10) / sampleScale;
        base = *(f32 *)(particle + 0x8);
        width = quarter * *(f32 *)(particle + 0x20);
        if (!(*(f32 *)(particle + 0x18) < zero)) {
            step = *(f32 *)(particle + 0x24) / sampleScale;
        } else {
            step = -*(f32 *)(particle + 0x24) / sampleScale;
        }
        normal.lane[1] = rise;
        swell = *(f32 *)(particle + 0x28);
        v0 = *(f32 *)(particle + 0x2C);
        for (sample = 0; sample < sampleCount; sample++) {
            f32 s;

            c = (f32)sample / sampleScale - centre;
            end = swell * (c * c);
            radius = base + end;
            t = cosf(angle);
            s = sinf(angle);
            point.lane[0] = t * radius;
            point.lane[1] = height;
            point.lane[2] = s * radius;
            normal.lane[0] = t * end;
            normal.lane[2] = s * end;
            effectVuLoad10(&normal);
            __asm__ volatile(
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuScale10(width);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            effectVuLoad10(&point);
            __asm__ volatile(
                "vmove.xyzw $vf12, $vf10\n"
                "vadd.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf12");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0xC) = D_00713D10[0];
            *(f32 *)(vertices + 0x10) = D_00713D14[0];
            *(f32 *)(vertices + 0x14) = D_00713D18[0];
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x0) = D_00713D10[0];
            *(f32 *)(vertices + 0x4) = D_00713D14[0];
            *(f32 *)(vertices + 0x8) = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x18) = D_00713D10[0];
            *(f32 *)(vertices + 0x1C) = D_00713D14[0];
            *(f32 *)(vertices + 0x20) = D_00713D18[0];
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x24) = D_00713D10[0];
            *(f32 *)(vertices + 0x28) = D_00713D14[0];
            *(f32 *)(vertices + 0x2C) = D_00713D18[0];
            vertices += 0x30;
            {
                f32 v = v0 + vSpan * ((f32)sample / sampleScale);
                *(f32 *)(texCoords + 0x4) = v;
                *(f32 *)(texCoords + 0xC) = v;
                *(f32 *)(texCoords + 0x14) = v;
                *(f32 *)(texCoords + 0x1C) = v;
            }
            texCoords += 0x20;
            angle += step;
            height += rise;
        }
        *(f32 *)(particle + 0x2C) = *(f32 *)(particle + 0x2C) + vStep;
        *(u32 *)particle = *(u32 *)particle + 1;
        continue;
skip:
        vertices += segmentCount * 12;
        texCoords += segmentCount * 8;
    }
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    func_003c22f0((RpGeometry *)geometry);
    if ((*(u16 *)instance & 4) != 0) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}

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

// FUN_004A30E0
/* Reusing arg1 as the replica index after its last dereference preserves the
 * retail saved-register allocation for the replication loop. */
#pragma push
#pragma opt_loop_invariants on
void func_004a30e0(u8 *arg0, u8 *arg1)
{
    u8 *var_19;
    u8 *temp_18;
    u8 *temp_3;
    u8 *var_17;
    u8 *temp_16;
    u32 var_9;
    u32 temp_23;
    u32 var_10;
    s32 temp_4;
    s32 temp_5;
    s32 temp_6;
    s32 temp_7;
    s32 temp_8;
    s32 temp_10;
    f32 var_f0_3;
    f32 var_f0_2;
    f32 var_f0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;

    temp_23 = *(u32 *)(arg1 + 0x38);
    if (temp_23 != 0) {
        RpGeometryLock((RpGeometry *)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18)), 0xFF8);
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        temp_18 = *(u8 **)(temp_3 + 0x30);
        var_19 = temp_18;
        temp_16 = *(u8 **)(temp_3 + 0x34);
        var_17 = temp_16;
        temp_f2 = 3.0f;
        temp_f8 = *(f32 *)(arg1 + 0x90) / temp_f2;
        temp_8 = *(s32 *)(arg1 + 0x8C);
        temp_f1 = (f32)temp_8;
        temp_7 = (s32)(*(f32 *)(arg1 + 0x78) * temp_f1);
        temp_6 = (s32)(*(f32 *)(arg1 + 0x7C) * temp_f1);
        temp_5 = temp_8 + 1;
        temp_4 = temp_5 * 4;
        temp_f2 = 255.0f;
        var_9 = 0;
        while (var_9 < (u32)temp_5) {
            if (var_9 < (u32)temp_7) {
                var_f0 = (f32)(u32)var_9;
                var_f0_2 = var_f0 / (f32)temp_7;
            } else if ((u32)temp_6 < var_9) {
                temp_10 = temp_8 - var_9;
                var_f0_3 = (f32)(u32)temp_10;
                var_f0_2 = var_f0_3 / (f32)(temp_8 - temp_6);
            } else {
                var_f0_2 = 1.0f;
            }
            *(s32 *)var_19 = 0xFFFFFF;
            temp_f0 = temp_f2 * var_f0_2;
            var_10 = (u32)temp_f0;
            *(s32 *)(var_19 + 4) = (var_10 << 24) | 0xFFFFFF;
            *(PolygonWindColor *)(var_19 + 8) = *(PolygonWindColor *)(var_19 + 4);
            *(s32 *)(var_19 + 0xC) = 0xFFFFFF;
            var_19 += 0x10;
            *(s32 *)var_17 = 0;
            temp_f7 = 2.0f * temp_f8;
            temp_f6 = 3.0f * temp_f8;
            *(f32 *)(var_17 + 8) = temp_f8;
            *(f32 *)(var_17 + 0x10) = temp_f7;
            *(f32 *)(var_17 + 0x18) = temp_f6;
            var_17 += 0x20;
            var_9 += 1;
        }
        arg1 = (u8 *)1;
        temp_6 = temp_4 * 4;
        temp_7 = temp_4 * 8;
        while ((uintptr_t)arg1 < temp_23) {
            memcpy(var_19, temp_18, (u32)temp_6);
            var_19 += temp_6;
            memcpy(var_17, temp_16, (u32)temp_7);
            var_17 += temp_7;
            arg1 = (u8 *)((uintptr_t)arg1 + 1);
        }
    }
}
#pragma pop

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
    *(u8 **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
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
    *(u8 **)(work + 4) = func_00484010(*(u8 **)(p16 + 4));
    func_004a30e0(work, p17);
    return work;
}

/* honest no-body per Main 2026-09-18: best faithful guarded draft 562/542 (unsigned st/idf, loopinv+p2choist) still -78 (-12.6% outside 3% gate 601-639 for fnalign retail 620; assignment retail 624), v1 584/514 (-106), loopinv 562/504 (-116). Recovery m2c 298 + romwright 376 (7-arg wrong arity, single u8* wins). File idiom u8*+u32/f32/s16, (f32)u32 unsigned (st/idf unsigned +38 vs signed, faithful per retail srl/andi/or), (1.0f-x)+x*r, D_ per-vertex 12 loads, var_17 tail hoisted p2c (-1). Ties: unroll/schedule off, P[i], var18/17, base/tmp. Regressed: s128a/b, periter unfaithful. Open walls: 163-word VU/square (retail 350:404 49 + 409:432 20 + 443:470 26 + 471:499 27 + 97:110 12, incl. two-stage e23 div/sub/mul, swc1 to 0x150($sp), bbit/dmtc2/dpau/lui 0x71), s128 bare sq/lq+sltu/paddub (5 spellings no bare sq), saved-reg rotation, frame 0x50 short. Banked 561/504 draft 19% short must not stay per Main; reverting to plain. 2026-09-18b repro unsigned 562/542 (-78) + mixed-signed 561/504 (-116, faithful: retail idx/st use plain cvt, srl only for divisor/var_f25/fi, so unsigned +38 unfaithful; faithful gap 116). VU plain-C (u_long128+aligned f32[4], no asm) 575/555 (+13/worse, 0 COP2/lqc2 vs retail 23/9, only lq/sq 24->26, frame 0x120->0x150): handoff VU + btlMain (0 VU in MATCH) + effWind MATCH VU (2c90/4000/5630 all via bridges, incl 5630 2x sqc2 vf0) prove interior vopmula/vrsqrt/vmulq/vadd/vsub has no plain-C control, wall stands. s32 word color (ed70 shape) 562/537 (-5/worse, retail lbu/sb not word masks, opposite direction). Single normalize bridge 541/567 (+25/frame 0x160 closed, still -53), double 544/578 (+36, still -42) vs prior full 692/minimal 662 overshoot: bridges bracket but dummy vectors unfaithful + asm-banned, no faithful middle. Ties: decl-reord 562, propag-off 563. jal 15 equal, no dropped arm/bound/collapse per prior. Leave plain ASM. */

/* measured: first guarded draft from 004a2310 skeleton (u8*+u32/f32/s16, (f32)(s32)state, (1.0f-x)+x*r, D_ per-vertex 12 loads) + dc 0xD8 fix + 10.0f on 0x24 + outer VU-emulation (cA/sA via 0044b610/7b0, vx0/vz0 normalize + cross to scl/div2/d1, no asm) to close VU count wall; fnalign retail 624/obj 640 (+16, +2.6% within 605-643) edits 890 - inside true 3% gate and assignment 633-671 overlap. Prior honest no-body (562/542 -78 outside 601-639) preserved above as history. */
/* 2026-09-19 run table (Main request): before loopinv 640/624, 575w probe / 594w floor, 890e; */
/* after prop_off alone 623/623 exact, 553w, 843e (-17 counts to exact, -22w, -47e). */
/* Singles+28 pairs (`pragma_sweep --pairs`, banked 575): best 553 prop_off alone */
/* (also prop+strength/unroll/peephole 553); combo loopinv+prop 561/627 (+3) worse; */
/* O4 566, O3 569, dead 598. No pair beats prop alone. Sibling dead_off tested */
/* here ties 598 (does not transfer); prop does not help 2310 beyond its own dead. */
/* Frame 0x150 vs retail 0x160 closed to exact via prop with no source change. */
/* 2026-09-20 cross diagnosis (Main correction: deficit ZERO so runs are CROSSES, not missing; deficit_scan now prints CROSS): baseline 623/623 exact, 572w, 843e with retail-only 155 at 0x004a3c2c-0x004a3e98 (vs 1 obj) + 147 at 0x004a3964-0x004a3bb0 (vs 0) + 24 at 0x004a3ed8, all CROSS; opcode retail +15 swc1/+15 ??/+10 lwc1/+6 addiu/+5 bbit132/+4 bbit032/+3 mul.s/+2 dmtc2. block_move_scan 155-vs-221 ratio 0.287 MIXED (genuine divergence, not clean move/recolour). */
/* Spawn offsets were unfaithful (D0/D8 for 0x10/0x14, E0 for 0x28, F0 for 0x18); faithful per Ghidra 468-495 + IDA 760-779 + retail asm (0x10 from 0xDC/E0, 0x14 from 0xCC single, 0x28 from 0xF0/E8, 0x18 from 0xD0/D4): 615/620 (-8 counts, -5w), 834e (-9) INSIDE (601-639), banked (xD8/yD4 now dead, eliminated, no frame change; frame stays 0x140 vs 0x160). */
/* Losses (all INSIDE, none banked): spawn+flag double (0x14 = 0x10*idf+0x14 then -idf*(baseE4*idf)*0.5f per IDA 782-786/Ghidra 500-501) 627/624 (+4), 842e (-1 vs baseline, +8 vs spawn alone; missing +0.0 madd/msub shape); color arms swapped (==0xFF vs !=) 623/623 exact, 843e (tie, confirms retail order matches body); scale reload inside loop (re-read iGpffff8080 before 0x1C) 622/622 (-1), 858e (+15 worse, reload not the desync). */
/* Open walls: VU/COP2 (lui 0x71/dpau/bbit/dmtc2/?? + D_ bbit132 chains, plain-C cross vs VU) + spill gap (retail reloads scale/10/0.25/0.0 from 0xE0/0xDC/0xD8/0xD4 stack where body keeps regs) + frame 0x20 short; saved set same ($f20-$f31) so 7bh STRUCT not the lever here. Floor stands; production stays ASM. */
// FUN_004A3640 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_004a3640(u8 *arg0)
{
    u32 outer;
    u32 flag2;
    u32 innerCnt;
    s32 flag;
    u32 budget;
    f32 dc;
    f32 base98;
    f32 baseE4;
    f32 scale;
    f32 quarter;
    f32 div1;
    f32 base8;
    f32 scl;
    f32 p28;
    f32 p2c;
    f32 var_f0;
    f32 var_f25;
    f32 acc0;
    f32 div2;
    f32 ang;
    s16 hcount;
    u32 state;
    u32 tmp5;
    u32 outerCount;
    u32 divisor;
    u32 var_19;
    u32 var_30;
    u8 *ctx2;
    u8 *base;
    u8 *pvar20;
    u8 *ctx;
    u8 *tmp;
    u8 *var_18;
    u8 *var_17;
    f32 fA4;
    u32 c;
    u32 v;
    f32 xC0;
    f32 r0;
    f32 yBC;
    f32 xC8;
    f32 r1;
    f32 yC4;
    f32 xD0;
    f32 r2;
    f32 yCC;
    f32 xD8;
    f32 r3;
    f32 yD4;
    f32 xE0;
    f32 r4;
    f32 yE8;
    f32 r5;
    f32 xF0;
    f32 r6;
    f32 yEC;
    f32 xB4;
    f32 r7;
    f32 yB0;
    f32 xAC;
    f32 r8;
    f32 yA8;
    f32 x9C;
    f32 r9;
    f32 y98;
    u32 rr;
    u32 idx;
    f32 a;
    f32 b;
    f32 idf;
    u8 *dst;
    f32 st;
    f32 e18;
    f32 e1C;
    f32 s10a;
    f32 s10b;
    f32 e18v;
    f32 e24;
    f32 d1;
    f32 d2;
    f32 c0;
    f32 s0;
    f32 fi;
    f32 ftmp;
    f32 f23tmp;
    f32 f24tmp;
    f32 vx0;
    f32 vy0;
    f32 vz0;
    f32 vx1;
    f32 vy1;
    f32 vz1;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len2;
    f32 inv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 cA;
    f32 sA;
    base = *(u8 **)(arg0 + 0x40);
    tmp5 = *(u32 *)(arg0 + 0x34);
    outerCount = *(u32 *)(base + 0x34);
    if ((outerCount < tmp5) && (outerCount != 0)) {
        return;
    }
    {
        c = *(u32 *)(base + 0x38);
        outer = c;
    }
    divisor = *(u32 *)(base + 0x80);
    if (divisor == 0) {
        return;
    }
    if ((*(u8 *)(base + 0xB8) == 0) || (tmp5 != 0)) {
        flag = 0;
        budget = *(u32 *)(base + 0x84);
    } else {
        flag = 1;
        budget = *(u32 *)(base + 0x38);
    }
    tmp = *(u8 **)(arg0 + 0x3C);
    pvar20 = *(u8 **)tmp;
    ctx = *(u8 **)(tmp + 4);
    flag2 = (u32)*(u8 *)(base + 0x88);
    dc = *(f32 *)(base + 0xD8);
    {
        u8 *p10;
        u8 *p18;
        p10 = *(u8 **)(*(u8 **)(ctx + 0x10) + 0x18);
        RpGeometryLock((RpGeometry *)(p10), 0xFF2);
        p18 = *(u8 **)(*(u8 **)(ctx + 0x10) + 0x18);
        var_18 = *(u8 **)(*(u8 **)(p18 + 0x5C) + 0x14);
        var_17 = *(u8 **)(p18 + 0x34);
        hcount = *(s16 *)(ctx + 8);
        v = *(u32 *)(base + 0x8C) + 1;
        innerCnt = v;
        var_f25 = (f32)v;
        base98 = *(f32 *)(base + 0x98);
        baseE4 = *(f32 *)(base + 0xE4);
        fA4 = *(f32 *)(base + 0xA4);
        var_30 = 0;
        scale = iGpffff8080;
        quarter = 0.25f;
        while (var_30 < outer) {
            state = *(u32 *)pvar20;
            if (state == 0xFFFFFFFEU) {
                goto next_outer;
            }
            if (state == 0xFFFFFFFFU) {
                memset(var_18, 0, (s32)hcount * 12);
                if (budget != 0) {
                    xC0 = *(f32 *)(base + 0xC0);
                    r0 = effMiscRandFloat(0);
                    yBC = *(f32 *)(base + 0xBC);
                    ftmp = yBC * ((1.0f - xC0) + xC0 * r0);
                    xC8 = *(f32 *)(base + 0xC8);
                    r1 = effMiscRandFloat(0);
                    yC4 = *(f32 *)(base + 0xC4);
                    var_f0 = (f32)divisor;
                    *(f32 *)(pvar20 + 0xC) = (yC4 * ((1.0f - xC8) + xC8 * r1) - ftmp) / var_f0;
                    *(f32 *)(pvar20 + 0x8) = ftmp;
                    xD0 = *(f32 *)(base + 0xE0);
                    r2 = effMiscRandFloat(0);
                    yCC = *(f32 *)(base + 0xDC);
                    *(f32 *)(pvar20 + 0x10) = yCC * ((1.0f - xD0) + xD0 * r2);
                    r3 = effMiscRandFloat(0);
                    *(f32 *)(pvar20 + 0x14) = *(f32 *)(base + 0xCC) * r3;
                    xE0 = *(f32 *)(base + 0xE8);
                    r4 = effMiscRandFloat(0);
                    yE8 = *(f32 *)(base + 0xF0);
                    *(f32 *)(pvar20 + 0x28) = yE8 * ((1.0f - xE0) + xE0 * r4);
                    r5 = effMiscRandFloat(0);
                    *(f32 *)(pvar20 + 0x1C) = scale * r5;
                    xF0 = *(f32 *)(base + 0xD4);
                    r6 = effMiscRandFloat(0);
                    yEC = *(f32 *)(base + 0xD0);
                    *(f32 *)(pvar20 + 0x18) = yEC * ((1.0f - xF0) + xF0 * r6);
                    xB4 = *(f32 *)(base + 0xB4);
                    r7 = effMiscRandFloat(0);
                    yB0 = *(f32 *)(base + 0xB0);
                    *(f32 *)(pvar20 + 0x20) = yB0 * ((1.0f - xB4) + xB4 * r7);
                    xAC = *(f32 *)(base + 0xAC);
                    r8 = effMiscRandFloat(0);
                    yA8 = *(f32 *)(base + 0xA8);
                    *(f32 *)(pvar20 + 0x24) = 10.0f * (yA8 * ((1.0f - xAC) + xAC * r8));
                    x9C = *(f32 *)(base + 0x9C);
                    r9 = effMiscRandFloat(0);
                    y98 = *(f32 *)(base + 0x98);
                    *(f32 *)(pvar20 + 0x2C) = y98 * ((1.0f - x9C) + x9C * r9);
                    if (flag != 0) {
                        rr = effMiscRand(0);
                        idx = rr % divisor;
                        *(u32 *)pvar20 = idx;
                        {
                            a = *(f32 *)(pvar20 + 0x14);
                            b = *(f32 *)(pvar20 + 0x10);
                            idf = (f32)(s32)idx;
                            *(f32 *)(pvar20 + 0x10) = a * idf + b;
                        }
                        {
                            a = *(f32 *)(pvar20 + 0xC);
                            b = *(f32 *)(pvar20 + 0x8);
                            idf = (f32)(s32)idx;
                            *(f32 *)(pvar20 + 0x8) = a * idf + b;
                        }
                    } else {
                        *(u32 *)pvar20 = 0;
                    }
                    budget -= 1;
                }
                goto next_outer;
            }
            if (state >= divisor) {
                if (flag2 != 0) {
                    *(u32 *)pvar20 = 0xFFFFFFFFU;
                } else {
                    memset(var_18, 0, (s32)hcount * 12);
                    *(u32 *)pvar20 = 0xFFFFFFFEU;
                }
                {
                    if (iGpffffbb64.c3 != 0xFF) {
                        dst = *(u8 **)(*(u8 **)(ctx + 0x54) + (var_30 & 0xFFFF) * 4);
                        *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
                    } else {
                        iGpffffbb64.c3 = 0xFE;
                        {
                            dst = *(u8 **)(*(u8 **)(ctx + 0x54) + (var_30 & 0xFFFF) * 4);
                            *(PolygonWindColor *)(dst + 4) = iGpffffbb64;
                        }
                        iGpffffbb64.c3 = 0xFF;
                    }
                }
                goto next_outer;
            }
            {
                st = (f32)(s32)state;
                e18 = *(f32 *)(pvar20 + 0x18);
                e1C = *(f32 *)(pvar20 + 0x1C);
                ang = st * (e18 + 0.5f * (dc * st)) + e1C;
                s10a = *(f32 *)(pvar20 + 0x10) + *(f32 *)(pvar20 + 0x14);
                s10b = *(f32 *)(pvar20 + 0x8) + *(f32 *)(pvar20 + 0xC);
                *(f32 *)(pvar20 + 0x8) = s10b;
                *(f32 *)(pvar20 + 0x14) = s10a - baseE4 * st;
                scl = quarter * *(f32 *)(pvar20 + 0x20);
                e24 = *(f32 *)(pvar20 + 0x24);
                d2 = e24 / var_f25;
                d1 = s10a / var_f25;
                acc0 = 0.0f;
                div2 = d2;
                base8 = *(f32 *)(pvar20 + 0x8);
                p28 = *(f32 *)(pvar20 + 0x28);
                p2c = *(f32 *)(pvar20 + 0x2C);
                cA = cosf(ang);
                sA = sinf(ang);
                vx0 = cA * scl;
                vy0 = s10b;
                vz0 = sA * scl;
                vx1 = cA * p28;
                vy1 = s10a;
                vz1 = sA * p28;
                dx = vx1 - vx0;
                dy = vy1 - vy0;
                dz = vz1 - vz0;
                len2 = dx * dx + dy * dy + dz * dz;
                inv = 1.0f / (len2 + 1.0f);
                nx = dx * inv;
                ny = dy * inv;
                nz = dz * inv;
                cx = ny * vz1 - nz * vy1;
                cy = nz * vx1 - nx * vz1;
                cz = nx * vy1 - ny * vx1;
                scl = scl + cx * 0.5f;
                div2 = div2 + cy * 0.5f;
                d1 = d1 + cz * 0.5f;
                var_19 = 0;
                while (var_19 < innerCnt) {
                    fi = (f32)var_19;
                    ftmp = fi / var_f25 - baseE4;
                    f23tmp = p28 * (ftmp * ftmp);
                    f24tmp = base8 + f23tmp;
                    c0 = cosf(ang);
                    s0 = sinf(ang);
                    *(f32 *)(var_18 + 0xC) = D_00713D10[0];
                    *(f32 *)(var_18 + 0x10) = D_00713D14[0];
                    *(f32 *)(var_18 + 0x14) = D_00713D18[0];
                    *(f32 *)var_18 = D_00713D10[0];
                    *(f32 *)(var_18 + 4) = D_00713D14[0];
                    *(f32 *)(var_18 + 8) = D_00713D18[0];
                    *(f32 *)(var_18 + 0x18) = D_00713D10[0];
                    *(f32 *)(var_18 + 0x1C) = D_00713D14[0];
                    *(f32 *)(var_18 + 0x20) = D_00713D18[0];
                    *(f32 *)(var_18 + 0x24) = D_00713D10[0];
                    *(f32 *)(var_18 + 0x28) = D_00713D14[0];
                    *(f32 *)(var_18 + 0x2C) = D_00713D18[0];
                    var_18 += 0x30;
                    {
                        fi = (f32)var_19;
                        {
                            v = base98 * (fi / var_f25) + p2c;
                            *(f32 *)(var_17 + 4) = v;
                            *(f32 *)(var_17 + 0xC) = v;
                            *(f32 *)(var_17 + 0x14) = v;
                            *(f32 *)(var_17 + 0x1C) = v;
                        }
                    }
                    var_17 += 0x20;
                    ang += div2;
                    acc0 += d1;
                    var_19 += 1;
                }
                *(f32 *)(pvar20 + 0x2C) = *(f32 *)(pvar20 + 0x2C) + fA4;
                *(u32 *)pvar20 = state + 1;
            }
next_outer:
            {
                var_18 += (s32)hcount * 12;
                var_17 += (s32)hcount * 8;
            }
            var_30 += 1;
            pvar20 += 0x30;
        }
        ctx2 = *(u8 **)(*(u8 **)(ctx + 0x10) + 0x18);
        func_003c22f0((RpGeometry *)(ctx2));
        if ((*(u16 *)ctx & 4) != 0) {
            *(u16 *)(ctx2 + 0xC) = *(u16 *)(ctx2 + 0xC) | 1;
        }
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3640);
#endif
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
/* 74 -> 66 (2026-09-18): the hand-written float-to-unsigned conversion(s)
   replaced by the plain cast.  b210 generates the same compare / subtract /
   or-0x80000000 sequence for the cast and colours its temporaries the way
   retail does; the m2c-expanded copy colours them the other way.  Same lever
   as func_00348330 in src/promoted/y_CmbCardEff.c. */
/* measured: live object 824B/window 832B, normalized_diff 67 (installed guard below; replaces bare ASM). Recovery: XWND skeleton fixed to compile ((u32) 3rd f810 args per file convention) plus #pragma opt_loop_invariants on (128 -> 67, the file's own 004a4380/004a3010 idiom). Open walls: saved-register rotation (args $s0/$s1 vs $s3/$s4 class), or-dest regs ($t3 vs $t2 at both conversion sites), 2^31 clamp compare form. Ruled out: s32 loop counters (tie alone and on loopinv base), or-operand commutation (tie), (u32)(s32) conversion two-step (160). Prior in-file note's nd47 batch is not on disk; closest reproduced here is 67. Banked as floor. */
/* The earlier floors above are superseded by the identical retail initializer
   at 004a1d70. Distinct unsigned row/replication counters and sizes reproduce
   the entire stream with the native geometry/copy interfaces: 824/832 bytes,
   four resolved calls and eight zero alignment bytes. This initializes the
   first color/UV strip, then duplicates it for the remaining meshes.
   See docs/probe_archive/Wind_004a4450_shared_initializer.md. */
#pragma push
#pragma opt_loop_invariants on
// FUN_004A4450
void func_004a4450(u8 *arg0, u8 *arg1)
{
    u32 meshCount;
    u8 *geometry;
    u8 *colors;
    u8 *colorsBase;
    u8 *verticesBase;
    u8 *vertices;
    s32 frames;
    u32 fadeIn;
    u32 fadeOut;
    u32 pointCount;
    u32 i;
    f32 opacity;
    f32 step;
    u32 colorBytes;
    u32 wordCount;
    u32 vertexBytes;
    u32 copies;
    u16 *model;

    meshCount = *(u32 *)(arg1 + 0x38);
    if (meshCount != 0) {
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        RpGeometryLock((RpGeometry *)(geometry), 0xFF8);
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        colorsBase = *(u8 **)(geometry + 0x30);
        colors = colorsBase;
        verticesBase = *(u8 **)(geometry + 0x34);
        vertices = verticesBase;
        step = *(f32 *)(arg1 + 0x90) / 3.0f;
        frames = *(s32 *)(arg1 + 0x8C);
        fadeIn = (s32)(*(f32 *)(arg1 + 0x78) * (f32)frames);
        fadeOut = (s32)(*(f32 *)(arg1 + 0x7C) * (f32)frames);
        pointCount = frames + 1;
        wordCount = pointCount * 4;
        i = 0;
        while (i < pointCount) {
            if (i < fadeIn) {
                opacity = (f32)i / (f32)(s32)fadeIn;
            } else if (fadeOut < i) {
                opacity = (f32)(u32)(frames - i) / (f32)(s32)(frames - fadeOut);
            } else {
                opacity = 1.0f;
            }
            *(u32 *)(colors + 0) = 0xFFFFFF;
            *(u32 *)(colors + 4) = ((u32)(opacity * 255.0f) << 24) | 0xFFFFFF;
            *(PolygonWindColor *)(colors + 8) = *(PolygonWindColor *)(colors + 4);
            *(u32 *)(colors + 12) = 0xFFFFFF;
            colors += 0x10;
            *(u32 *)(vertices + 0) = 0;
            *(f32 *)(vertices + 8) = step;
            *(f32 *)(vertices + 0x10) = step * 2.0f;
            *(f32 *)(vertices + 0x18) = step * 3.0f;
            vertices += 0x20;
            i += 1;
        }
        copies = 1;
        colorBytes = wordCount * 4;
        vertexBytes = wordCount * 8;
        while (copies < meshCount) {
            memcpy(colors, colorsBase, colorBytes);
            colors += colorBytes;
            memcpy(vertices, verticesBase, vertexBytes);
            vertices += vertexBytes;
            copies += 1;
        }
        model = *(u16 **)(arg0 + 4);
        geometry = *(u8 **)(*(u8 **)((u8 *)model + 0x10) + 0x18);
        func_003c22f0((RpGeometry *)(geometry));
        if ((*model & 4) != 0) {
            *(u16 *)(geometry + 0xC) |= 1;
        }
    }
}
#pragma pop

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
    *(u8 **)(work + 4) = func_00483e10(*(u16 *)(arg0 + 0x38), *(u16 *)(arg0 + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
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
    *(u8 **)(work + 4) = func_00484010(*(u8 **)(p16 + 4));
    func_004a4450(work, p17);
    return work;
}

/* Spiral wind strip update. Each live particle samples sampleCount points on a
 * circle (cosf/sinf), transforms them by the VU0 matrix set up by
 * func_004bd1a0/3c0/450, and widens the strip along the normalised cross
 * product; the results pass through D_00713D10 as in effLineNova. The FPU
 * constants are named locals assigned in retail's preheader order, and the
 * FPR locals are declared in the order regalloc_whatif.py derived from the
 * captured colouring (start/end/t, then width..radius). */
// FUN_004A4A10
void func_004a4a10(u8 *arg0)
{
    EffectVuVector point;
    f32 sampleScale;
    f32 one;
    f32 half;
    f32 two;
    f32 spread;
    f32 zero;
    f32 start;
    f32 end;
    f32 t;
    f32 width;
    f32 vStep;
    f32 v0;
    f32 angle;
    f32 step;
    f32 radius;
    f32 accel;
    f32 vSpan;
    f32 spin;
    f32 quarter;
    u32 index;
    s32 segmentCount;
    u8 *instance;
    u32 lifetime;
    u8 *particle;
    u32 sample;
    u8 *vertices;
    u8 *texCoords;
    u8 *config;
    u32 particleCount;
    u32 respawn;
    u32 sampleCount;
    s32 spawnAll;
    u32 pending;
    u32 elapsed;
    u32 limit;
    u8 *list;
    u8 *geometry;
    u32 state;

    config = *(u8 **)(arg0 + 0x40);
    limit = *(u32 *)(config + 0x34);
    elapsed = *(u32 *)(arg0 + 0x34);
    if ((limit < elapsed) && (limit != 0)) {
        return;
    }
    particleCount = *(u32 *)(config + 0x38);
    lifetime = *(u32 *)(config + 0x80);
    if (lifetime == 0) {
        return;
    }
    if ((*(u8 *)(config + 0xB8) != 0) && (elapsed == 0)) {
        spawnAll = 1;
        pending = particleCount;
    } else {
        spawnAll = 0;
        pending = *(u32 *)(config + 0x84);
    }
    list = *(u8 **)(arg0 + 0x3C);
    particle = *(u8 **)list;
    instance = *(u8 **)(list + 4);
    respawn = *(u8 *)(config + 0x88);
    accel = *(f32 *)(config + 0xD4);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(instance + 0x10) + 0x18), 0xFF2);
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    vertices = *(u8 **)(*(u8 **)(geometry + 0x5C) + 0x14);
    texCoords = *(u8 **)(geometry + 0x34);
    segmentCount = *(s16 *)(instance + 8);
    sampleCount = *(u32 *)(config + 0x8C) + 1;
    sampleScale = (f32)sampleCount;
    vSpan = *(f32 *)(config + 0x98);
    vStep = *(f32 *)(config + 0xA4);
    index = 0;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    spread = iGpffff8084;
    spin = iGpffff8080;
    quarter = 0.25f;
    zero = 0.0f;
    for (; index < particleCount; index++, particle += 0x2C) {
        state = *(u32 *)particle;
        if (state == (u32)-2) {
            goto skip;
        }
        if (state == (u32)-1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            start = *(f32 *)(config + 0xC0);
            start = *(f32 *)(config + 0xBC) * ((one - start) + start * effMiscRandFloat(0));
            end = *(f32 *)(config + 0xC8);
            *(f32 *)(particle + 0x14) = (*(f32 *)(config + 0xC4) * ((one - end) + end * effMiscRandFloat(0)) - start) / (f32)lifetime;
            *(f32 *)(particle + 0x10) = start;
            *(f32 *)(particle + 0x8) = spread * (two * (effMiscRandFloat(0) - half));
            *(f32 *)(particle + 0xC) = spread * (two * (effMiscRandFloat(0) - half));
            *(f32 *)(particle + 0x1C) = spin * effMiscRandFloat(0);
            t = *(f32 *)(config + 0xD0);
            *(f32 *)(particle + 0x18) = *(f32 *)(config + 0xCC) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xB4);
            *(f32 *)(particle + 0x20) = *(f32 *)(config + 0xB0) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xAC);
            *(f32 *)(particle + 0x24) = *(f32 *)(config + 0xA8) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0x9C);
            *(f32 *)(particle + 0x28) = *(f32 *)(config + 0x98) * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                *(u32 *)particle = effMiscRand(0) % lifetime;
                t = (f32)*(s32 *)particle;
                *(f32 *)(particle + 0x10) = *(f32 *)(particle + 0x10) + *(f32 *)(particle + 0x14) * t;
            } else {
                *(u32 *)particle = 0;
            }
            pending--;
            goto skip;
        }
        if (state >= lifetime) {
            if (respawn != 0) {
                *(u32 *)particle = (u32)-1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                *(u32 *)particle = (u32)-2;
            }
            if (iGpffffbb64.c3 != 0xFF) {
                u8 *color = *(u8 **)(*(u8 **)(instance + 0x54) + (u16)index * 4);
                *(PolygonWindColor *)(color + 4) = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *color = *(u8 **)(*(u8 **)(instance + 0x54) + (u16)index * 4);
                    *(PolygonWindColor *)(color + 4) = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            goto skip;
        }
        t = (f32)(s32)state;
        angle = t * (*(f32 *)(particle + 0x18) + half * (accel * t));
        angle += *(f32 *)(particle + 0x1C);
        radius = (*(f32 *)(particle + 0x10) += *(f32 *)(particle + 0x14));
        width = quarter * *(f32 *)(particle + 0x20);
        if (!(*(f32 *)(particle + 0x18) < zero)) {
            step = *(f32 *)(particle + 0x24) / sampleScale;
        } else {
            step = -*(f32 *)(particle + 0x24) / sampleScale;
        }
        v0 = *(f32 *)(particle + 0x28);
        func_004bd1a0(*(f32 *)(particle + 0x8));
        func_004bd3c0(*(f32 *)(particle + 0xC));
        func_004bd450();
        point.lane[0] = cosf(angle);
        point.lane[1] = zero;
        point.lane[2] = sinf(angle);
        for (sample = 0; sample < sampleCount; sample++) {
            effectVuLoad10(&point);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuScale10(radius);
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            angle += step;
            point.lane[0] = cosf(angle);
            point.lane[1] = zero;
            point.lane[2] = sinf(angle);
            effectVuLoad10(&point);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuScale10(radius);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf12\n"
                "vsub.xyzw $vf10, $vf10, $vf11\n"
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10", "$vf11");
            effectVuScale10(width);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vmove.xyzw $vf10, $vf12\n"
                "vadd.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0xC) = D_00713D10[0];
            *(f32 *)(vertices + 0x10) = D_00713D14[0];
            *(f32 *)(vertices + 0x14) = D_00713D18[0];
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x0) = D_00713D10[0];
            *(f32 *)(vertices + 0x4) = D_00713D14[0];
            *(f32 *)(vertices + 0x8) = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x18) = D_00713D10[0];
            *(f32 *)(vertices + 0x1C) = D_00713D14[0];
            *(f32 *)(vertices + 0x20) = D_00713D18[0];
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            *(f32 *)(vertices + 0x24) = D_00713D10[0];
            *(f32 *)(vertices + 0x28) = D_00713D14[0];
            *(f32 *)(vertices + 0x2C) = D_00713D18[0];
            vertices += 0x30;
            {
                f32 v = v0 + vSpan * ((f32)sample / sampleScale);
                *(f32 *)(texCoords + 0x4) = v;
                *(f32 *)(texCoords + 0xC) = v;
                *(f32 *)(texCoords + 0x14) = v;
                *(f32 *)(texCoords + 0x1C) = v;
            }
            texCoords += 0x20;
        }
        *(f32 *)(particle + 0x28) = *(f32 *)(particle + 0x28) + vStep;
        *(u32 *)particle = *(u32 *)particle + 1;
        continue;
skip:
        vertices += segmentCount * 12;
        texCoords += segmentCount * 8;
    }
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    func_003c22f0((RpGeometry *)geometry);
    if ((*(u16 *)instance & 4) != 0) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}

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
    memcpy(*(void **)(p18 + 0x40), arg1, (u32)temp_17);
    return p18;
}
#pragma opt_propagation on

// FUN_004A5750
void *func_004a5750(void *arg0)
{
    u8 *p16;
    u8 *p19;
    u8 *p18;
    u8 *p17;
    u32 idx;

    p18 = func_004844d0(arg0);
    if (p18 == NULL) {
        func_0046d730(D_00714110, 0x5D5);
    }
    switch (*(u16 *)((u8 *)arg0 + 0x1C)) {
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
    p16 = (u8 *)(*(u16 *)((u8 *)arg0 + 0xC) & 0xFFFF);
    p17 = func_004a5630((s32)p16, p19);
    idx = ((u32)p16 & 0xFFFF) * 28;
    *(u32 *)(p17 + 0x3C) = (u32)((void *(*)(void *, void *))(*(void **)(D_00714134 + idx)))(p19, p18);
    ((void (*)(void *))(*(void **)(D_00714130 + idx)))(p17);
    if (p17 == NULL) {
        func_0046d730(D_00714110, 0x5E5);
    }
    return p17;
}
