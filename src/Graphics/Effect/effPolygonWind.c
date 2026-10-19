#include "include_asm.h"
/* Original translation unit effPolygonWind.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "rw_geometry_internal.h"
#include "effect_vu0_internal.h"
extern void mdlEffectDestroyMultipartGeometry(void *instance);
extern void (*D_008873ec[])(void *);

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));

/* 4-byte color state at 0x00724C54..57, accessed gp-relative in retail. */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;

/* Wind layouts follow the 0xC-byte block header, allocator sizes and strip strides.
 * Subtypes give different meanings to the remaining scalar fields. */

typedef struct WindGeometryInstance {
    u8 pad0[0x8];
    s16 vertexCount; /* +0x8 */
    u8 padA[0x6];
    u8 * atomic; /* +0x10 */
    u8 pad14[0x40];
    u8 * materials; /* +0x54 */
} WindGeometryInstance;

typedef struct WindConfig {
    u8 pad0[0x28];
    u16 unk28; /* +0x28 */
    u8 pad2A[0xA];
    u32 duration; /* +0x34 */
    union { s32 signedWord; u16 half; u32 word; } particleCount; /* +0x38 */
    u8 pad3C[0x3C];
    f32 fadeIn; /* +0x78 */
    f32 fadeOut; /* +0x7C */
    u32 lifetime; /* +0x80 */
    u32 spawnCount; /* +0x84 */
    u8 respawn; /* +0x88 */
    u8 pad89[0x3];
    union { s32 signedWord; u16 half; u32 word; } segments; /* +0x8C */
    f32 unk90; /* +0x90 */
    u8 pad94[0x4];
    f32 unk98; /* +0x98 */
    f32 unk9C; /* +0x9C */
    u8 padA0[0x4];
    f32 unkA4; /* +0xA4 */
    f32 unkA8; /* +0xA8 */
    f32 unkAC; /* +0xAC */
    f32 unkB0; /* +0xB0 */
    f32 unkB4; /* +0xB4 */
    u8 spawnAll; /* +0xB8 */
    u8 drawFlag; /* +0xB9 */
    u8 padBA[0x2];
    f32 unkBC; /* +0xBC */
    f32 unkC0; /* +0xC0 */
    f32 unkC4; /* +0xC4 */
    f32 unkC8; /* +0xC8 */
    f32 unkCC; /* +0xCC */
    f32 unkD0; /* +0xD0 */
    f32 unkD4; /* +0xD4 */
    f32 unkD8; /* +0xD8 */
    f32 unkDC; /* +0xDC */
    f32 unkE0; /* +0xE0 */
    f32 unkE4; /* +0xE4 */
    f32 unkE8; /* +0xE8 */
    f32 unkEC; /* +0xEC */
    f32 unkF0; /* +0xF0 */
    f32 unkF4; /* +0xF4 */
} WindConfig;

typedef struct WindEffect {
    u8 pad0[0x20];
    u_long128 unk20; /* +0x20 */
    union { s32 signedWord; u32 word; } tint; /* +0x30 */
    u32 elapsed; /* +0x34 */
    u32 kind; /* +0x38 */
    union { u32 word; u8 * bytes; } block; /* +0x3C */
    union { u32 word; u8 * bytes; void * pointer; } config; /* +0x40 */
} WindEffect;

typedef struct WindMaterial {
    u8 pad0[0x4];
    PolygonWindColor unk4; /* +0x4 */
} WindMaterial;

typedef struct WindBlock {
    u8 pad0[0x4];
    union { s32 signedWord; u16 * halves; u8 * bytes; void * pointer; } instance; /* +0x4 */
    union { u8 * bytes; void * pointer; } allocation; /* +0x8 */
} WindBlock;

extern PolygonWindColor iGpffffbb64; /* 0x00724C54: colour for inactive wind entries */
extern void chkmemAllocSiteTag(char *, s32);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *GeometryCreateStripGridMultiPart(s32, s32, s32, s32, s32);
extern s32 TnSlotObject(s32);
extern void mdlEffectSetGeometryTexture(void *, s32);
extern void mdlEffectUploadGeometryTexture(void *, s32);
extern void mdlEffectBuildWindFadeRows(void *, void *);
extern void FallingFunnelWindInitEntries(u8 *, u8 *);
extern void SpiralWindInitEntries(u8 *, u8 *);
extern u8 *mdlEffectCloneMultipartGeometry(u8 *);
extern void *memcpy(void *, const void *, u32);
extern char D_00713330[];
extern char D_00714148[];
extern u_long128 D_00713CE0;

extern void kAssertFail(void *, s32);
extern s32 mdlEffectSamplePackedColor(u8 *, u8 *, s32, s32);
/* lint-allow: declared with no parameters and called with four. The definition in mdlEffect.c takes one; the one-argument form moved the codegen of all three call sites (verify MISMATCH 3). */
extern void mdlEffectApplyCombinedGeometryMatrix();
extern void mdlEffectAppendGeometryPrimitive();
extern void memset(void *, s32, s32);
extern void effMiscRotateXVU(f32);
extern void effMiscRotateYVU(f32);
extern void effMiscCombineRotationVU(void);
extern f32 cosf(f32);
extern f32 sinf(f32);
extern RpGeometry *func_003c22f0(RpGeometry *);
extern f32 D_00713D10[4];
extern f32 D_00713D14[4];
extern f32 D_00713D18[4];
extern f32 iGpffff8084; /* 0x00761174 */
extern f32 fGpffff8044; /* 0x00761134 */
extern f32 iGpffff8080; /* 0x00761170 */
extern void *WindAllocKindEntry(s32, void *);
extern char D_00714134[];
extern char D_00714130[];
extern char D_00714110[];

// Allocates a funnel wind block: count * 48 entry bytes plus a 12-byte header.
// FUN_004A20B0
u8 *FunnelWindAllocBlock(u8 *config, s32 texture)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 235 differing bytes). Offsets remain as observed. */
    u8 *work;
    s32 size;

    size = *(s32 *)(config + 0x38) * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x53);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = GeometryCreateStripGridMultiPart(*(u16 *)(config + 0x38), *(u16 *)(config + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(*(void **)(work + 4), TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(*(void **)(work + 4), texture);
    }
    mdlEffectBuildWindFadeRows(work, config);
    return work;
}

// Allocates a funnel wind block that inherits its entry layout from a parent block.
// FUN_004A21E0
u8 *FunnelWindAllocFromParent(u8 *parent)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 71 differing bytes). Offsets remain as observed. */
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;

    parentBlock = *(u8 **)(parent + 0x3C);
    config = *(u8 **)(parent + 0x40);
    size = *(s32 *)(config + 0x38) * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x53);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = mdlEffectCloneMultipartGeometry(*(u8 **)(parentBlock + 4));
    mdlEffectBuildWindFadeRows(work, config);
    return work;
}

// Frees a funnel wind block: its geometry handle, then the block itself.
// FUN_004A22C0
void FunnelWindFreeBlock(u8 *effect) {
    u8 *block;

    block = ((WindEffect *)effect)->block.bytes;
    mdlEffectDestroyMultipartGeometry((void *)((WindBlock *)block)->instance.signedWord);
    D_008873ec[0](((WindBlock *)block)->allocation.pointer);
}

/* Funnel wind strip update, the SpiralWindUpdateStrip sibling without the VU0 matrix:
 * each sample sits on a ring of radius base + swell * (s - centre)^2 at a
 * rising height, and the strip is widened along the normalised ring offset.
 * One float local carries the spawn start, every spawn interpolation weight
 * and the cosine; another carries the end weight and the swell term, as
 * retail's shared $f20/$f23 show. FPR declarations follow the order a
 * regalloc_whatif.py replay of the captured colouring derived; the spilled
 * locals are declared in retail's spill-slot order. */
// Updates the funnel wind strip: the ring point gives a direction that is widened along the normalised ring offset.
// FUN_004A2310
void FunnelWindUpdateStrip(u8 *effect)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 1693 differing bytes). Offsets remain as observed. */
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

    config = *(u8 **)(effect + 0x40);
    limit = *(u32 *)(config + 0x34);
    elapsed = *(u32 *)(effect + 0x34);
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
    list = *(u8 **)(effect + 0x3C);
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

// Packs the funnel wind vertex colours from the inner and outer colour words.
// FUN_004A2C90
void FunnelWindPackColors(u8 *effect)
{
    union {
        s32 w;
        u8 b[4];
    } packedColor;
    /* VU/MMI packing stores into the following scalar slots; retain their order. */
    s32 tintColor;
    s32 sampledColor;
    s32 combinedColor;
    s32 particleColor;
    s32 effectColor;
    s32 modulatedColor;
    s32 sampled;
    u8 *block;
    u32 *particleAges;
    u8 *config;
    u32 particleIndex;
    u8 *instance;
    u32 elapsed;
    u32 duration;
    u32 particleCount;
    u32 lifetime;
    u32 age;
    u32 combined;
    f32 scale;

    block = ((WindEffect *)effect)->block.bytes;
    config = ((WindEffect *)effect)->config.bytes;
    instance = ((WindBlock *)block)->instance.bytes;
    elapsed = ((WindEffect *)effect)->elapsed;
    duration = ((WindConfig *)config)->duration;
    if ((duration >= elapsed) || (duration == 0)) {
        s32 *pt;

        particleAges = *(u32 **)block;
        sampled = mdlEffectSamplePackedColor(config, config + 0x24, elapsed, duration);
        tintColor = ((WindEffect *)effect)->tint.signedWord;
        pt = &tintColor;
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
        sampledColor = sampled;
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
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&combinedColor;
        particleCount = ((WindConfig *)config)->particleCount.word;
        lifetime = ((WindConfig *)config)->lifetime;
        particleIndex = 0;
        while (particleIndex < particleCount) {
            age = *particleAges;
            if (age < lifetime) {
                particleColor = mdlEffectSamplePackedColor(config + 0x3C, config + 0x60, age, lifetime);
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
                    : "r"(&particleColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                effectColor = combined;
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
                    : "r"(&effectColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                packedColor.w = *(s32 *)&modulatedColor;
                if (packedColor.b[3] != 0xFF) {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                } else {
                    packedColor.b[3] = 0xFE;
                    {
                        u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                        ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                    }
                    packedColor.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                ((WindMaterial *)dst)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            particleIndex += 1;
            particleAges += 0xC;
        }
        mdlEffectApplyCombinedGeometryMatrix(instance, effect, effect + 0x10, effect + 0x20);
        if (((WindConfig *)config)->drawFlag != 0) {
            *(u16 *)instance = *(u16 *)instance | 1;
        } else {
            *(u16 *)instance = *(u16 *)instance & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}

/* measured: without #pragma opt_loop_invariants on, mwcc rematerializes the
 * 0xFF/0xFE/-1 constants inside the loop instead of hoisting them to the
 * preheader (and hoists the p11 load that retail re-issues per iteration);
 * with it the loop matches retail exactly. */
// Updates the funnel entries in a per-entry loop (0x30 stride).
// FUN_004A3010
#pragma opt_loop_invariants on
void FunnelWindUpdateEntries(u8 *effect)
{
    u8 *block;
    u8 *particle;
    u32 count;
    u32 particleIndex;
    u8 *instance;
    u8 *material;

    block = ((WindEffect *)effect)->block.bytes;
    particle = *(u8 **)block;
    count = ((WindConfig *)((WindEffect *)effect)->config.bytes)->particleCount.word;
    particleIndex = 0;
    while (particleIndex < count) {
        instance = ((WindBlock *)block)->instance.bytes;
        if (iGpffffbb64.c3 != 0xFF) {
            material = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
            ((WindMaterial *)material)->unk4 = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            material = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
            ((WindMaterial *)material)->unk4 = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)particle = -1;
        particleIndex++;
        particle += 0x30;
    }
}
#pragma opt_loop_invariants off

// Initialises the falling funnel entries from the config (0x30 stride).
// FUN_004A30E0
/* Reusing configOrCopyIndex as the replica index after its last dereference preserves the
 * retail saved-register allocation for the replication loop. */
#pragma push
#pragma opt_loop_invariants on
void FallingFunnelWindInitEntries(u8 *block, u8 *configOrCopyIndex)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 214 differing bytes). Offsets remain as observed. */
    u8 *colors;
    u8 *colorsBase;
    u8 *geometry;
    u8 *texCoords;
    u8 *texCoordsBase;
    u32 sampleIndex;
    u32 particleCount;
    u32 alpha;
    s32 vertexCount;
    s32 sampleCount;
    s32 fadeOutOrColorBytes;
    s32 fadeInOrTexCoordBytes;
    s32 segments;
    s32 remaining;
    f32 remainingFloat;
    f32 opacity;
    f32 sampleFloat;
    f32 scaledAlpha;
    f32 segmentScale;
    f32 scale;
    f32 thirdU;
    f32 secondU;
    f32 uStep;

    particleCount = *(u32 *)(configOrCopyIndex + 0x38);
    if (particleCount != 0) {
        RpGeometryLock((RpGeometry *)(*(u8 **)(*(u8 **)(*(u8 **)(block + 4) + 0x10) + 0x18)), 0xFF8);
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(block + 4) + 0x10) + 0x18);
        colorsBase = *(u8 **)(geometry + 0x30);
        colors = colorsBase;
        texCoordsBase = *(u8 **)(geometry + 0x34);
        texCoords = texCoordsBase;
        scale = 3.0f;
        uStep = *(f32 *)(configOrCopyIndex + 0x90) / scale;
        segments = *(s32 *)(configOrCopyIndex + 0x8C);
        segmentScale = (f32)segments;
        fadeInOrTexCoordBytes = (s32)(*(f32 *)(configOrCopyIndex + 0x78) * segmentScale);
        fadeOutOrColorBytes = (s32)(*(f32 *)(configOrCopyIndex + 0x7C) * segmentScale);
        sampleCount = segments + 1;
        vertexCount = sampleCount * 4;
        scale = 255.0f;
        sampleIndex = 0;
        while (sampleIndex < (u32)sampleCount) {
            if (sampleIndex < (u32)fadeInOrTexCoordBytes) {
                sampleFloat = (f32)(u32)sampleIndex;
                opacity = sampleFloat / (f32)fadeInOrTexCoordBytes;
            } else if ((u32)fadeOutOrColorBytes < sampleIndex) {
                remaining = segments - sampleIndex;
                remainingFloat = (f32)(u32)remaining;
                opacity = remainingFloat / (f32)(segments - fadeOutOrColorBytes);
            } else {
                opacity = 1.0f;
            }
            *(s32 *)colors = 0xFFFFFF;
            scaledAlpha = scale * opacity;
            alpha = (u32)scaledAlpha;
            *(s32 *)(colors + 4) = (alpha << 24) | 0xFFFFFF;
            *(PolygonWindColor *)(colors + 8) = *(PolygonWindColor *)(colors + 4);
            *(s32 *)(colors + 0xC) = 0xFFFFFF;
            colors += 0x10;
            *(s32 *)texCoords = 0;
            secondU = 2.0f * uStep;
            thirdU = 3.0f * uStep;
            *(f32 *)(texCoords + 8) = uStep;
            *(f32 *)(texCoords + 0x10) = secondU;
            *(f32 *)(texCoords + 0x18) = thirdU;
            texCoords += 0x20;
            sampleIndex += 1;
        }
        configOrCopyIndex = (u8 *)1;
        fadeOutOrColorBytes = vertexCount * 4;
        fadeInOrTexCoordBytes = vertexCount * 8;
        while ((uintptr_t)configOrCopyIndex < particleCount) {
            memcpy(colors, colorsBase, (u32)fadeOutOrColorBytes);
            colors += fadeOutOrColorBytes;
            memcpy(texCoords, texCoordsBase, (u32)fadeInOrTexCoordBytes);
            texCoords += fadeInOrTexCoordBytes;
            configOrCopyIndex = (u8 *)((uintptr_t)configOrCopyIndex + 1);
        }
    }
}
#pragma pop

// Allocates a falling funnel wind block: count * 48 entry bytes plus a 12-byte header.
// FUN_004A33E0
u8 *FallingFunnelWindAllocBlock(u8 *config, s32 texture)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 238 differing bytes). Offsets remain as observed. */
    u8 *work;
    s32 size;

    size = *(s32 *)(config + 0x38) * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x213);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = GeometryCreateStripGridMultiPart(*(u16 *)(config + 0x38), *(u16 *)(config + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(*(void **)(work + 4), TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(*(void **)(work + 4), texture);
    }
    FallingFunnelWindInitEntries(work, config);
    return work;
}

// Allocates a falling funnel wind block that inherits its entry layout from a parent block.
// FUN_004A3510
u8 *FallingFunnelWindAllocFromParent(u8 *parent)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 71 differing bytes). Offsets remain as observed. */
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;

    parentBlock = *(u8 **)(parent + 0x3C);
    config = *(u8 **)(parent + 0x40);
    size = *(s32 *)(config + 0x38) * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x213);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = mdlEffectCloneMultipartGeometry(*(u8 **)(parentBlock + 4));
    FallingFunnelWindInitEntries(work, config);
    return work;
}

// Frees a falling funnel wind block: its geometry handle, then the block itself.
// FUN_004A35F0
void FallingFunnelWindFreeBlock(u8 *effect) {
    u8 *block;

    block = ((WindEffect *)effect)->block.bytes;
    mdlEffectDestroyMultipartGeometry((void *)((WindBlock *)block)->instance.signedWord);
    D_008873ec[0](((WindBlock *)block)->allocation.pointer);
}

/* Falling funnel wind strip, the FunnelWindUpdateStrip sibling with a call-free inner
 * loop: the ring point for the current and the next state gives a normalised
 * direction, crossed with the radial axis and scaled to the strip width; the
 * loop then steps the centre along that direction. Loop invariants hoist the
 * bridge addresses as retail does. The particle state is signed so its -1/-2
 * markers stay in the loop body, and windAdd keeps the (p8 + pC) operand order
 * that retail evaluates before the bulge term. FPR declarations follow the
 * order a regalloc_whatif.py replay of the captured colouring derived. */
static inline f32 windAdd(f32 first, f32 second) { return first + second; }
#pragma push
#pragma opt_loop_invariants on
// Updates the falling funnel wind strip: a call-free inner loop steps the centre along the normalised direction.
// FUN_004A3640
void FallingFunnelWindUpdateStrip(u8 *effect)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 1760 differing bytes). Offsets remain as observed. */
    EffectVuVector point;
    EffectVuVector direction;
    f32 t;
    f32 vStep;
    f32 gravity;
    f32 angle;
    f32 height;
    f32 sampleScale;
    f32 c;
    f32 swell;
    f32 centre;
    f32 one;
    f32 half;
    f32 end;
    f32 v0;
    f32 accel;
    f32 vSpan;
    f32 spin;
    f32 ten;
    f32 quarter;
    f32 zero;
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
    s32 state;

    config = *(u8 **)(effect + 0x40);
    limit = *(u32 *)(config + 0x34);
    elapsed = *(u32 *)(effect + 0x34);
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
    list = *(u8 **)(effect + 0x3C);
    particle = *(u8 **)list;
    instance = *(u8 **)(list + 4);
    respawn = *(u8 *)(config + 0x88);
    accel = *(f32 *)(config + 0xD8);
    gravity = *(f32 *)(config + 0xE4);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(instance + 0x10) + 0x18), 0xFF2);
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    vertices = *(u8 **)(*(u8 **)(geometry + 0x5C) + 0x14);
    texCoords = *(u8 **)(geometry + 0x34);
    segmentCount = *(s16 *)(instance + 8);
    sampleCount = *(u32 *)(config + 0x8C) + 1;
    sampleScale = (f32)sampleCount;
    vSpan = *(f32 *)(config + 0x98);
    centre = *(f32 *)(config + 0xEC);
    vStep = *(f32 *)(config + 0xA4);
    index = 0;
    one = 1.0f;
    spin = iGpffff8080;
    ten = 10.0f;
    half = 0.5f;
    quarter = 0.25f;
    zero = 0.0f;
    goto check;
body:
    {
        state = *(s32 *)particle;
        if (state == -2) {
            goto skip;
        }
        if (state == -1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            t = *(f32 *)(config + 0xC0);
            t = *(f32 *)(config + 0xBC) * ((one - t) + t * effMiscRandFloat(0));
            end = *(f32 *)(config + 0xC8);
            *(f32 *)(particle + 0xC) = (*(f32 *)(config + 0xC4) * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            *(f32 *)(particle + 0x8) = t;
            t = *(f32 *)(config + 0xE0);
            *(f32 *)(particle + 0x10) = *(f32 *)(config + 0xDC) * ((one - t) + t * effMiscRandFloat(0));
            *(f32 *)(particle + 0x14) = *(f32 *)(config + 0xCC) * effMiscRandFloat(0);
            t = *(f32 *)(config + 0xE8);
            *(f32 *)(particle + 0x28) = *(f32 *)(config + 0xF0) * ((one - t) + t * effMiscRandFloat(0));
            *(f32 *)(particle + 0x1C) = spin * effMiscRandFloat(0);
            t = *(f32 *)(config + 0xD4);
            *(f32 *)(particle + 0x18) = *(f32 *)(config + 0xD0) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xB4);
            *(f32 *)(particle + 0x20) = *(f32 *)(config + 0xB0) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xAC);
            *(f32 *)(particle + 0x24) = ten * (*(f32 *)(config + 0xA8) * ((one - t) + t * effMiscRandFloat(0)));
            t = *(f32 *)(config + 0x9C);
            *(f32 *)(particle + 0x2C) = *(f32 *)(config + 0x98) * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                *(u32 *)particle = effMiscRand(0) % lifetime;
                t = (f32)*(s32 *)particle;
                *(f32 *)(particle + 0x14) = *(f32 *)(particle + 0x14) + *(f32 *)(particle + 0x10) * t;
                *(f32 *)(particle + 0x14) = *(f32 *)(particle + 0x14) - half * (t * (gravity * t));
                *(f32 *)(particle + 0x8) = *(f32 *)(particle + 0x8) + *(f32 *)(particle + 0xC) * t;
            } else {
                *(u32 *)particle = 0;
            }
            pending--;
            goto skip;
        }
        if ((u32)state >= lifetime) {
            if (respawn != 0) {
                *(s32 *)particle = -1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                *(s32 *)particle = -2;
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
        v0 = *(f32 *)(particle + 0x2C);
        end = (f32)state;
        angle = end * (*(f32 *)(particle + 0x18) + half * (accel * end));
        angle += *(f32 *)(particle + 0x1C);
        {
            f32 base = *(f32 *)(particle + 0x8);
            f32 offset;
            f32 width;
            f32 stepLength;
            f32 s;

            height = *(f32 *)(particle + 0x14);
            swell = *(f32 *)(particle + 0x28);
            offset = end / (f32)lifetime - centre;
            t = base + swell * (offset * offset);
            c = cosf(angle);
            s = sinf(angle);
            point.lane[0] = c * t;
            point.lane[1] = height;
            point.lane[2] = s * t;
            effectVuLoad11(&point);
            __asm__ volatile("vmove.xyzw $vf12, $vf11" : : : "$vf12");
            height = (height + *(f32 *)(particle + 0x10)) - gravity * end;
            base = windAdd(*(f32 *)(particle + 0x8), *(f32 *)(particle + 0xC)) + swell * (((one + end) / (f32)lifetime - centre) * ((one + end) / (f32)lifetime - centre));
            point.lane[0] = c * base;
            point.lane[1] = height;
            point.lane[2] = s * base;
            effectVuLoad10(&point);
            __asm__ volatile(
                "vsub.xyzw $vf10, $vf10, $vf11\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuStore10(&direction);
            *(f32 *)(particle + 0x14) = height;
            *(f32 *)(particle + 0x8) = *(f32 *)(particle + 0x8) + *(f32 *)(particle + 0xC);
            width = quarter * *(f32 *)(particle + 0x20);
            stepLength = *(f32 *)(particle + 0x24) / sampleScale;
            point.lane[0] = c;
            point.lane[1] = zero;
            point.lane[2] = s;
            effectVuLoad11(&point);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n" : : : "$vf10");
            effectVuScale10(width);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            for (sample = 0; sample < sampleCount; sample++) {
                __asm__ volatile(
                    "vmove.xyzw $vf10, $vf12\n"
                    "vadd.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
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
                effectVuLoad10(&direction);
                effectVuScale10(stepLength);
                __asm__ volatile("vadd.xyzw $vf12, $vf12, $vf10" : : : "$vf12");
            }
        }
        *(f32 *)(particle + 0x2C) = *(f32 *)(particle + 0x2C) + vStep;
        *(u32 *)particle = *(u32 *)particle + 1;
        goto next;
skip:
        vertices += segmentCount * 12;
        texCoords += segmentCount * 8;
    }
next:
    index++;
    particle += 0x30;
check:
    if (index < particleCount) {
        goto body;
    }
    geometry = *(u8 **)(*(u8 **)(instance + 0x10) + 0x18);
    func_003c22f0((RpGeometry *)geometry);
    if ((*(u16 *)instance & 4) != 0) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}
#pragma pop
// Packs the falling funnel vertex colours from the inner and outer colour words.
// FUN_004A4000
void FallingFunnelWindPackColors(u8 *effect)
{
    union {
        s32 w;
        u8 b[4];
    } packedColor;
    /* VU/MMI packing stores into the following scalar slots; retain their order. */
    s32 tintColor;
    s32 sampledColor;
    s32 combinedColor;
    s32 particleColor;
    s32 effectColor;
    s32 modulatedColor;
    s32 sampled;
    u8 *block;
    u32 *particleAges;
    u8 *config;
    u32 particleIndex;
    u8 *instance;
    u32 elapsed;
    u32 duration;
    u32 particleCount;
    u32 lifetime;
    u32 age;
    u32 combined;
    f32 scale;

    block = ((WindEffect *)effect)->block.bytes;
    config = ((WindEffect *)effect)->config.bytes;
    instance = ((WindBlock *)block)->instance.bytes;
    elapsed = ((WindEffect *)effect)->elapsed;
    duration = ((WindConfig *)config)->duration;
    if ((duration >= elapsed) || (duration == 0)) {
        s32 *pt;

        particleAges = *(u32 **)block;
        sampled = mdlEffectSamplePackedColor(config, config + 0x24, elapsed, duration);
        tintColor = ((WindEffect *)effect)->tint.signedWord;
        pt = &tintColor;
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
        sampledColor = sampled;
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
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&combinedColor;
        particleCount = ((WindConfig *)config)->particleCount.word;
        lifetime = ((WindConfig *)config)->lifetime;
        particleIndex = 0;
        while (particleIndex < particleCount) {
            age = *particleAges;
            if (age < lifetime) {
                particleColor = mdlEffectSamplePackedColor(config + 0x3C, config + 0x60, age, lifetime);
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
                    : "r"(&particleColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                effectColor = combined;
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
                    : "r"(&effectColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                packedColor.w = *(s32 *)&modulatedColor;
                if (packedColor.b[3] != 0xFF) {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                } else {
                    packedColor.b[3] = 0xFE;
                    {
                        u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                        ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                    }
                    packedColor.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                ((WindMaterial *)dst)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            particleIndex += 1;
            particleAges += 0xC;
        }
        mdlEffectApplyCombinedGeometryMatrix(instance, effect, effect + 0x10, effect + 0x20);
        if (((WindConfig *)config)->drawFlag != 0) {
            *(u16 *)instance = *(u16 *)instance | 1;
        } else {
            *(u16 *)instance = *(u16 *)instance & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}

/* measured: same loop-shape as FunnelWindUpdateEntries; without #pragma
 * opt_loop_invariants on, mwcc rematerializes the 0xFF/0xFE/-1 constants
 * inside the loop instead of hoisting them to the preheader; with it the
 * loop matches retail exactly (0x2C stride variant). */
// Updates the falling funnel entries in a per-entry loop (0x2C stride variant).
// FUN_004A4380
#pragma opt_loop_invariants on
void FallingFunnelWindUpdateEntries(u8 *effect)
{
    u8 *block;
    u8 *particle;
    u32 count;
    u32 particleIndex;
    u8 *instance;
    u8 *material;

    block = ((WindEffect *)effect)->block.bytes;
    particle = *(u8 **)block;
    count = ((WindConfig *)((WindEffect *)effect)->config.bytes)->particleCount.word;
    particleIndex = 0;
    while (particleIndex < count) {
        instance = ((WindBlock *)block)->instance.bytes;
        if (iGpffffbb64.c3 != 0xFF) {
            material = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
            ((WindMaterial *)material)->unk4 = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            material = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
            ((WindMaterial *)material)->unk4 = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)particle = -1;
        particleIndex++;
        particle += 0x2C;
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
// Initialises the spiral wind entries from the config (0x2C stride).
// FUN_004A4450
void SpiralWindInitEntries(u8 *block, u8 *config)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 260 differing bytes). Offsets remain as observed. */
    u32 meshCount;
    u8 *geometry;
    u8 *colors;
    u8 *colorsBase;
    u8 *texCoordsBase;
    u8 *texCoords;
    s32 frames;
    u32 fadeIn;
    u32 fadeOut;
    u32 pointCount;
    u32 i;
    f32 opacity;
    f32 step;
    u32 colorBytes;
    u32 wordCount;
    u32 texCoordBytes;
    u32 copies;
    u16 *model;

    meshCount = *(u32 *)(config + 0x38);
    if (meshCount != 0) {
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(block + 4) + 0x10) + 0x18);
        RpGeometryLock((RpGeometry *)(geometry), 0xFF8);
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(block + 4) + 0x10) + 0x18);
        colorsBase = *(u8 **)(geometry + 0x30);
        colors = colorsBase;
        texCoordsBase = *(u8 **)(geometry + 0x34);
        texCoords = texCoordsBase;
        step = *(f32 *)(config + 0x90) / 3.0f;
        frames = *(s32 *)(config + 0x8C);
        fadeIn = (s32)(*(f32 *)(config + 0x78) * (f32)frames);
        fadeOut = (s32)(*(f32 *)(config + 0x7C) * (f32)frames);
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
            *(u32 *)(texCoords + 0) = 0;
            *(f32 *)(texCoords + 8) = step;
            *(f32 *)(texCoords + 0x10) = step * 2.0f;
            *(f32 *)(texCoords + 0x18) = step * 3.0f;
            texCoords += 0x20;
            i += 1;
        }
        copies = 1;
        colorBytes = wordCount * 4;
        texCoordBytes = wordCount * 8;
        while (copies < meshCount) {
            memcpy(colors, colorsBase, colorBytes);
            colors += colorBytes;
            memcpy(texCoords, texCoordsBase, texCoordBytes);
            texCoords += texCoordBytes;
            copies += 1;
        }
        model = *(u16 **)(block + 4);
        geometry = *(u8 **)(*(u8 **)((u8 *)model + 0x10) + 0x18);
        func_003c22f0((RpGeometry *)(geometry));
        if ((*model & 4) != 0) {
            *(u16 *)(geometry + 0xC) |= 1;
        }
    }
}
#pragma pop

// Allocates a spiral wind block: count * 44 entry bytes plus a 12-byte header.
// FUN_004A4790
u8 *SpiralWindAllocBlock(u8 *config, s32 texture)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 240 differing bytes). Offsets remain as observed. */
    u8 *work;
    s32 size;

    size = *(s32 *)(config + 0x38) * 0x2C + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x3E5);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = GeometryCreateStripGridMultiPart(*(u16 *)(config + 0x38), *(u16 *)(config + 0x8C), (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(*(void **)(work + 4), TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(*(void **)(work + 4), texture);
    }
    SpiralWindInitEntries(work, config);
    return work;
}

// Allocates a spiral wind block that inherits its entry layout from a parent block.
// FUN_004A48D0
u8 *SpiralWindAllocFromParent(u8 *parent)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 67 differing bytes). Offsets remain as observed. */
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;

    parentBlock = *(u8 **)(parent + 0x3C);
    config = *(u8 **)(parent + 0x40);
    size = *(s32 *)(config + 0x38) * 0x2C + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (work == NULL) {
        kAssertFail(D_00714110, 0x3E5);
    }
    *(u8 **)work = work + 0xC;
    *(u8 **)(work + 8) = work;
    if (*(u32 *)(config + 0x8C) < 3U) {
        *(u32 *)(config + 0x8C) = 3U;
    }
    *(u8 **)(work + 4) = mdlEffectCloneMultipartGeometry(*(u8 **)(parentBlock + 4));
    SpiralWindInitEntries(work, config);
    return work;
}

// Frees a spiral wind block: its geometry handle, then the block itself.
// FUN_004A49C0
void SpiralWindFreeBlock(u8 *effect) {
    u8 *block;

    block = ((WindEffect *)effect)->block.bytes;
    mdlEffectDestroyMultipartGeometry((void *)((WindBlock *)block)->instance.signedWord);
    D_008873ec[0](((WindBlock *)block)->allocation.pointer);
}

/* Spiral wind strip update. Each live particle samples sampleCount points on a
 * circle (cosf/sinf), transforms them by the VU0 matrix set up by
 * effMiscRotateXVU, effMiscRotateYVU and effMiscCombineRotationVU, and widens the strip along the normalised cross
 * product; the results pass through D_00713D10 as in effLineNova. The FPU
 * constants are named locals assigned in retail's preheader order, and the
 * FPR locals are declared in the order regalloc_whatif.py derived from the
 * captured colouring (start/end/t, then width..radius). */
// Updates the spiral wind strip: samples the spiral ring through the VU0 matrix and widens the strip along the normalised cross product.
// FUN_004A4A10
void SpiralWindUpdateStrip(u8 *effect)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 1484 differing bytes). Offsets remain as observed. */
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

    config = *(u8 **)(effect + 0x40);
    limit = *(u32 *)(config + 0x34);
    elapsed = *(u32 *)(effect + 0x34);
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
    list = *(u8 **)(effect + 0x3C);
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
        effMiscRotateXVU(*(f32 *)(particle + 0x8));
        effMiscRotateYVU(*(f32 *)(particle + 0xC));
        effMiscCombineRotationVU();
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

// Packs the spiral wind vertex colours from the inner and outer colour words.
// FUN_004A52B0
void SpiralWindPackColors(u8 *effect)
{
    union {
        s32 w;
        u8 b[4];
    } packedColor;
    /* VU/MMI packing stores into the following scalar slots; retain their order. */
    s32 tintColor;
    s32 sampledColor;
    s32 combinedColor;
    s32 particleColor;
    s32 effectColor;
    s32 modulatedColor;
    s32 sampled;
    u8 *block;
    u32 *particleAges;
    u8 *config;
    u32 particleIndex;
    u8 *instance;
    u32 elapsed;
    u32 duration;
    u32 particleCount;
    u32 lifetime;
    u32 age;
    u32 combined;
    f32 scale;

    block = ((WindEffect *)effect)->block.bytes;
    config = ((WindEffect *)effect)->config.bytes;
    instance = ((WindBlock *)block)->instance.bytes;
    elapsed = ((WindEffect *)effect)->elapsed;
    duration = ((WindConfig *)config)->duration;
    if ((duration >= elapsed) || (duration == 0)) {
        s32 *pt;

        particleAges = *(u32 **)block;
        sampled = mdlEffectSamplePackedColor(config, config + 0x24, elapsed, duration);
        tintColor = ((WindEffect *)effect)->tint.signedWord;
        pt = &tintColor;
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
        sampledColor = sampled;
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
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        combined = *(s32 *)&combinedColor;
        particleCount = ((WindConfig *)config)->particleCount.word;
        lifetime = ((WindConfig *)config)->lifetime;
        particleIndex = 0;
        while (particleIndex < particleCount) {
            age = *particleAges;
            if (age < lifetime) {
                particleColor = mdlEffectSamplePackedColor(config + 0x3C, config + 0x60, age, lifetime);
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
                    : "r"(&particleColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                effectColor = combined;
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
                    : "r"(&effectColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                packedColor.w = *(s32 *)&modulatedColor;
                if (packedColor.b[3] != 0xFF) {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                } else {
                    packedColor.b[3] = 0xFE;
                    {
                        u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                        ((WindMaterial *)dst)->unk4 = *(PolygonWindColor *)&packedColor;
                    }
                    packedColor.b[3] = 0xFF;
                }
            } else if (iGpffffbb64.c3 != 0xFF) {
                u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                ((WindMaterial *)dst)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *dst = ((u8 **)((WindGeometryInstance *)instance)->materials)[(particleIndex & 0xFFFF)];
                    ((WindMaterial *)dst)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            particleIndex += 1;
            particleAges += 0xB;
        }
        mdlEffectApplyCombinedGeometryMatrix(instance, effect, effect + 0x10, effect + 0x20);
        if (((WindConfig *)config)->drawFlag != 0) {
            *(u16 *)instance = *(u16 *)instance | 1;
        } else {
            *(u16 *)instance = *(u16 *)instance & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}

/* measured: same loop-shape as FunnelWindUpdateEntries; without #pragma
 * opt_loop_invariants on, mwcc rematerializes the 0xFF/0xFE/-1 constants
 * inside the loop instead of hoisting them to the preheader; with it the
 * loop matches retail exactly (0x2C stride variant). */

// Allocates a wind entry from the kind table (kind below 4), copying the kind's stride-0x1C record.
// FUN_004A5630
#pragma opt_propagation off
void *WindAllocKindEntry(s32 kind, void *parameters)
{
    u8 *effect;
    u_long128 *dst128;
    s32 kindIndex;
    s32 parameterBytes;

    if ((u16)kind >= 4) {
        kAssertFail(D_00714110, 0x59F);
    }
    kindIndex = kind & 0xFFFF;
    /* D_00714148 names the size column, not the start of the kind table. */
    parameterBytes = *(s32 *)(D_00714148 + kindIndex * 0x1C);
    chkmemAllocSiteTag(D_00714110, 0x5A3);
    effect = jtbl_008873E8[0](parameterBytes + 0x50, 0x40000);
    if (effect == NULL) {
        kAssertFail(D_00714110, 0x5A4);
    }
    ((WindEffect *)effect)->config.word = (u32)(effect + 0x50);
    ((WindEffect *)effect)->elapsed = 0;
    ((WindEffect *)effect)->kind = (u32)kindIndex;
    ((WindEffect *)effect)->tint.word = -1;
    dst128 = &D_00713CE0;
    ((WindEffect *)effect)->unk20 = *dst128;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(effect) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(effect) : "memory");
    memcpy(((WindEffect *)effect)->config.pointer, parameters, (u32)parameterBytes);
    return effect;
}
#pragma opt_propagation on

// Creates a wind entry by kind: switches on the entry's kind word and allocates through WindAllocKindEntry.
// FUN_004A5750
void *WindCreateKindEntry(void *source)
{
    u8 *kind;
    u8 *parameters;
    u8 *texture;
    u8 *effect;
    u32 tableOffset;

    texture = mdlEffectResolveRelPtrB(source);
    if (texture == NULL) {
        kAssertFail(D_00714110, 0x5D5);
    }
    switch (((EffSourceDescriptor *)source)->kind) {
    case 1:
        break;
    case 4:
        texture = NULL;
        break;
    default:
        kAssertFail(D_00714110, 0x5DE);
        break;
    }
    parameters = mdlEffectResolveRelPtrA(source);
    if (parameters == NULL) {
        kAssertFail(D_00714110, 0x5E3);
    }
    kind = (u8 *)(((EffSourceDescriptor *)source)->id & 0xFFFF);
    effect = WindAllocKindEntry((s32)kind, parameters);
    tableOffset = ((u32)kind & 0xFFFF) * 28;
    /* These linker symbols name callback columns inside 0x1C-byte records. */
    ((WindEffect *)effect)->block.word = (u32)((void *(*)(void *, void *))(*(void **)(D_00714134 + tableOffset)))(parameters, texture);
    ((void (*)(void *))(*(void **)(D_00714130 + tableOffset)))(effect);
    if (effect == NULL) {
        kAssertFail(D_00714110, 0x5E5);
    }
    return effect;
}
