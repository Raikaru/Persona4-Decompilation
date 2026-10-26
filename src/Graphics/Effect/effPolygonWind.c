#include "effect_geometry_internal.h"
#include "operand_order_internal.h"
#include "include_asm.h"
/* Original translation unit effPolygonWind.c (from __FILE__ assert strings). */
#include "type.h"
#include "effect_instance_internal.h"
#include "rw_geometry_internal.h"
#include "effect_vu0_internal.h"
#include "effect_mesh_internal.h"

/* Unit settings: loop-invariant motion enabled. */
#pragma opt_loop_invariants on
extern void mdlEffectDestroyMultipartGeometry(void *source);
extern void (*D_008873ec[])(void *);

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));

/* Each alias starts at one callback/size column of a 0x1C-byte kind row. */
typedef struct WindKindSize { s32 parameterBytes; u8 pad04[0x18]; } WindKindSize;
typedef struct WindKindAllocator { void *(*allocate)(void *, void *); u8 pad04[0x18]; } WindKindAllocator;
typedef struct WindKindInitializer { void (*initialize)(void *); u8 pad04[0x18]; } WindKindInitializer;

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
    u16 flags;
    u8 pad2[0x6];
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
    union { u8 *bytes; u32 *ages; } particles; /* +0x0 */
    union { s32 signedWord; u16 * halves; u8 * bytes; void * pointer; } instance; /* +0x4 */
    union { u8 * bytes; void * pointer; } allocation; /* +0x8 */
} WindBlock;

/* Record strides are 0x30 for funnel variants and 0x2C for spiral wind. */
typedef struct WindParticle {
    union { s32 signedWord; u32 word; } age;
    u8 pad4[4];
    f32 unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
} WindParticle;

typedef struct WindFunnelParticle {
    WindParticle motion;
    f32 unk2C;
} WindFunnelParticle;

typedef struct WindStripVertices { f32 position[4][3]; } WindStripVertices;
typedef struct WindStripTexCoords {
    union { f32 value; s32 signedBits; u32 bits; } coordinates[4][2];
} WindStripTexCoords;
typedef struct WindStripColors {
    union { s32 signedWord; u32 word; PolygonWindColor color; } colors[4];
} WindStripColors;


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
extern WindKindSize D_00714148[];
extern u_long128 D_00713CE0;

extern void kAssertFail(void *, s32);
extern s32 mdlEffectSamplePackedColor(u8 *, u8 *, s32, s32);
/* lint-allow: declared without parameters and called with four; the real one-argument prototype in
 * mdlEffect.c changes codegen at all three call sites. */
extern void mdlEffectApplyCombinedGeometryMatrix(u8 *instance, struct RwV3d *translation, void *basis, struct RwV3d *scale);
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
extern WindKindAllocator D_00714134[];
extern WindKindInitializer D_00714130[];
extern char D_00714110[];

// Allocates a funnel wind block: count * 48 entry bytes plus a 12-byte header.
// FUN_004A20B0
u8 *FunnelWindAllocBlock(u8 *config, s32 texture)
{
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x53);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = GeometryCreateStripGridMultiPart(settings->particleCount.half, settings->segments.half, (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(allocation->instance.pointer, TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(allocation->instance.pointer, texture);
    }
    mdlEffectBuildWindFadeRows(work, config);
    return work;
}

// Allocates a funnel wind block that inherits its entry layout from a parent block.
// FUN_004A21E0
u8 *FunnelWindAllocFromParent(u8 *parent)
{
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    parentBlock = ((WindEffect *)parent)->block.bytes;
    config = ((WindEffect *)parent)->config.bytes;
    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x52);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x53);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = mdlEffectCloneMultipartGeometry(((WindBlock *)parentBlock)->instance.bytes);
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

#pragma push
/* measured: retail built FunnelWindUpdateStrip and FunnelWindPackColors with loop-invariant
 * hoisting off. */
#pragma opt_loop_invariants off
/* Funnel wind strip update, the SpiralWindUpdateStrip sibling without the VU0 matrix: each sample
 * sits on a ring of radius base + swell (s - centre)^2 at a rising height, and the strip is widened
 * along the normalised ring offset. */
// FUN_004A2310
void FunnelWindUpdateStrip(u8 *effect)
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
    WindGeometryInstance *geometryInstance;
    u32 lifetime;
    u8 *particle;
    WindParticle *entry;
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

    config = ((WindEffect *)effect)->config.bytes;
    limit = ((WindConfig *)config)->duration;
    elapsed = ((WindEffect *)effect)->elapsed;
    if ((limit < elapsed) && (limit != 0)) {
        return;
    }
    particleCount = ((WindConfig *)config)->particleCount.word;
    lifetime = ((WindConfig *)config)->lifetime;
    if (lifetime == 0) {
        return;
    }
    if ((((WindConfig *)config)->spawnAll != 0) && (elapsed == 0)) {
        spawnAll = 1;
        pending = particleCount;
    } else {
        spawnAll = 0;
        pending = ((WindConfig *)config)->spawnCount;
    }
    list = ((WindEffect *)effect)->block.bytes;
    particle = ((WindBlock *)list)->particles.bytes;
    instance = ((WindBlock *)list)->instance.bytes;
    geometryInstance = (WindGeometryInstance *)instance;
    respawn = ((WindConfig *)config)->respawn;
    accel = ((WindConfig *)config)->unkF4;
    RpGeometryLock(((RpAtomic *)geometryInstance->atomic)->geometry, 0xFF2);
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    vertices = (u8*)((RpMorphTarget *)(u8 *)((RpGeometry *)geometry)->morphTarget)->vertices;
    texCoords = (u8 *)((RpGeometry *)geometry)->texCoords[0];
    segmentCount = geometryInstance->vertexCount;
    sampleCount = ((WindConfig *)config)->segments.word + 1;
    sampleScale = (f32)sampleCount;
    vSpan = ((WindConfig *)config)->unk98;
    centre = ((WindConfig *)config)->unkE4;
    vStep = ((WindConfig *)config)->unkA4;
    index = 0;
    one = 1.0f;
    spin = iGpffff8080;
    half = 0.5f;
    zero = 0.0f;
    quarter = 0.25f;
    for (; index < particleCount; index++, particle += 0x30) {
        entry = (WindParticle *)particle;
        state = entry->age.word;
        if (state == (u32)-2) {
            goto skip;
        }
        if (state == (u32)-1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            t = ((WindConfig *)config)->unkC0;
            t = ((WindConfig *)config)->unkBC * ((one - t) + t * effMiscRandFloat(0));
            end = ((WindConfig *)config)->unkC8;
            entry->unkC = (((WindConfig *)config)->unkC4 * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            entry->unk8 = t;
            t = ((WindConfig *)config)->unkD0;
            t = ((WindConfig *)config)->unkCC * ((one - t) + t * effMiscRandFloat(0));
            end = ((WindConfig *)config)->unkD8;
            entry->unk14 = (((WindConfig *)config)->unkD4 * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            entry->unk10 = t;
            t = ((WindConfig *)config)->unkE0;
            entry->unk28 = ((WindConfig *)config)->unkE8 * ((one - t) + t * effMiscRandFloat(0));
            entry->unk1C = spin * effMiscRandFloat(0);
            t = ((WindConfig *)config)->unkF0;
            entry->unk18 = ((WindConfig *)config)->unkEC * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkB4;
            entry->unk20 = ((WindConfig *)config)->unkB0 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkAC;
            entry->unk24 = ((WindConfig *)config)->unkA8 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unk9C;
            ((WindFunnelParticle *)particle)->unk2C = ((WindConfig *)config)->unk98 * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                entry->age.word = effMiscRand(0) % lifetime;
                t = (f32)entry->age.signedWord;
                entry->unk10 = entry->unk10 + entry->unk14 * t;
                entry->unk8 = entry->unk8 + entry->unkC * t;
            } else {
                entry->age.word = 0;
            }
            pending--;
            goto skip;
        }
        if (state >= lifetime) {
            if (respawn != 0) {
                entry->age.word = (u32)-1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                entry->age.word = (u32)-2;
            }
            if (iGpffffbb64.c3 != 0xFF) {
                u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                ((WindMaterial *)color)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                    ((WindMaterial *)color)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            goto skip;
        }
        t = (f32)(s32)state;
        angle = t * (entry->unk18 + half * (accel * t));
        angle += entry->unk1C;
        entry->unk10 = entry->unk10 + entry->unk14;
        entry->unk8 = entry->unk8 + entry->unkC;
        height = zero;
        rise = entry->unk10 / sampleScale;
        base = entry->unk8;
        width = quarter * entry->unk20;
        if (!(entry->unk18 < zero)) {
            step = entry->unk24 / sampleScale;
        } else {
            step = -entry->unk24 / sampleScale;
        }
        normal.lane[1] = rise;
        swell = entry->unk28;
        v0 = ((WindFunnelParticle *)particle)->unk2C;
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
            ((WindStripVertices *)vertices)->position[1][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[1][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[1][2] = D_00713D18[0];
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[0][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[0][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[0][2] = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[2][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[2][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[2][2] = D_00713D18[0];
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[3][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[3][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[3][2] = D_00713D18[0];
            vertices += 0x30;
            {
                f32 v = v0 + vSpan * ((f32)sample / sampleScale);
                ((WindStripTexCoords *)texCoords)->coordinates[0][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[1][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[2][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[3][1].value = v;
            }
            texCoords += 0x20;
            angle += step;
            height += rise;
        }
        ((WindFunnelParticle *)particle)->unk2C = ((WindFunnelParticle *)particle)->unk2C + vStep;
        entry->age.word = entry->age.word + 1;
        continue;
skip:
        vertices += segmentCount * 12;
        texCoords += segmentCount * 8;
    }
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    func_003c22f0((RpGeometry *)geometry);
    if ((geometryInstance->flags & 4) != 0) {
        ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
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

        particleAges = ((WindBlock *)block)->particles.ages;
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
        mdlEffectApplyCombinedGeometryMatrix((u8 *)(instance), (struct RwV3d *)( effect), (void *)( effect + 0x10), (struct RwV3d *)( effect + 0x20));
        if (((WindConfig *)config)->drawFlag != 0) {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags | 1;
        } else {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}
#pragma pop

/* measured: opt_loop_invariants keeps the 0xFF/0xFE/-1 constants hoisted out of the loop, as in
 * retail. Updates the funnel entries in a loop with a 0x30 stride. */
/* Apply the shared wind colour to each particle's material, keeping its alpha below 0xFF, and reset
 * every particle's age to -1. */
// FUN_004A3010
void FunnelWindUpdateEntries(u8 *effect)
{
    u8 *block;
    u8 *particle;
    u32 count;
    u32 particleIndex;
    u8 *instance;
    u8 *material;

    block = ((WindEffect *)effect)->block.bytes;
    particle = ((WindBlock *)block)->particles.bytes;
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
        ((WindParticle *)particle)->age.signedWord = -1;
        particleIndex++;
        particle += 0x30;
    }
}

// Initialises the falling funnel entries from the config (0x30 stride).
// FUN_004A30E0
/* Reusing configOrCopyIndex as the replica index after its last dereference keeps retail's saved-
 * register allocation for the replication loop. */
void FallingFunnelWindInitEntries(u8 *block, u8 *configOrCopyIndex)
{
    u8 *colors;
    WindBlock *windBlock = (WindBlock *)block;
    WindStripColors *colorRow;
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

    particleCount = ((WindConfig *)configOrCopyIndex)->particleCount.word;
    if (particleCount != 0) {
        RpGeometryLock((RpGeometry *)((u8*)((RpAtomic *)((WindGeometryInstance *)windBlock->instance.bytes)->atomic)->geometry), 0xFF8);
        geometry = (u8*)((RpAtomic *)((WindGeometryInstance *)windBlock->instance.bytes)->atomic)->geometry;
        colorsBase = (u8 *)((RpGeometry *)geometry)->colors;
        colors = colorsBase;
        texCoordsBase = (u8 *)((RpGeometry *)geometry)->texCoords[0];
        texCoords = texCoordsBase;
        scale = 3.0f;
        uStep = ((WindConfig *)configOrCopyIndex)->unk90 / scale;
        segments = ((WindConfig *)configOrCopyIndex)->segments.signedWord;
        segmentScale = (f32)segments;
        fadeInOrTexCoordBytes = (s32)(((WindConfig *)configOrCopyIndex)->fadeIn * segmentScale);
        fadeOutOrColorBytes = (s32)(((WindConfig *)configOrCopyIndex)->fadeOut * segmentScale);
        sampleCount = segments + 1;
        vertexCount = sampleCount * 4;
        scale = 255.0f;
        sampleIndex = 0;
        while (sampleIndex < (u32)sampleCount) {
            colorRow = (WindStripColors *)colors;
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
            colorRow->colors[0].signedWord = 0xFFFFFF;
            scaledAlpha = scale * opacity;
            alpha = (u32)scaledAlpha;
            colorRow->colors[1].signedWord = (alpha << 24) | 0xFFFFFF;
            colorRow->colors[2].color = colorRow->colors[1].color;
            colorRow->colors[3].signedWord = 0xFFFFFF;
            colors += 0x10;
            ((WindStripTexCoords *)texCoords)->coordinates[0][0].signedBits = 0;
            secondU = 2.0f * uStep;
            thirdU = 3.0f * uStep;
            ((WindStripTexCoords *)texCoords)->coordinates[1][0].value = uStep;
            ((WindStripTexCoords *)texCoords)->coordinates[2][0].value = secondU;
            ((WindStripTexCoords *)texCoords)->coordinates[3][0].value = thirdU;
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

// Allocates a falling funnel wind block: count * 48 entry bytes plus a 12-byte header.
// FUN_004A33E0
u8 *FallingFunnelWindAllocBlock(u8 *config, s32 texture)
{
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x213);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = GeometryCreateStripGridMultiPart(settings->particleCount.half, settings->segments.half, (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(allocation->instance.pointer, TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(allocation->instance.pointer, texture);
    }
    FallingFunnelWindInitEntries(work, config);
    return work;
}

// Allocates a falling funnel wind block that inherits its entry layout from a parent block.
// FUN_004A3510
u8 *FallingFunnelWindAllocFromParent(u8 *parent)
{
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    parentBlock = ((WindEffect *)parent)->block.bytes;
    config = ((WindEffect *)parent)->config.bytes;
    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x30 + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x212);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x213);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = mdlEffectCloneMultipartGeometry(((WindBlock *)parentBlock)->instance.bytes);
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

/* Sibling of FunnelWindUpdateStrip with a call-free inner loop; the particle state is signed so its
 * -1/-2 markers stay in the loop body. */

/* Updates the falling funnel wind strip: a call-free inner loop steps the centre along the
 * normalised direction. */
// FUN_004A3640
void FallingFunnelWindUpdateStrip(u8 *effect)
{
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
    WindGeometryInstance *geometryInstance;
    u32 lifetime;
    u8 *particle;
    WindParticle *entry;
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

    config = ((WindEffect *)effect)->config.bytes;
    limit = ((WindConfig *)config)->duration;
    elapsed = ((WindEffect *)effect)->elapsed;
    if ((limit < elapsed) && (limit != 0)) {
        return;
    }
    particleCount = ((WindConfig *)config)->particleCount.word;
    lifetime = ((WindConfig *)config)->lifetime;
    if (lifetime == 0) {
        return;
    }
    if ((((WindConfig *)config)->spawnAll != 0) && (elapsed == 0)) {
        spawnAll = 1;
        pending = particleCount;
    } else {
        spawnAll = 0;
        pending = ((WindConfig *)config)->spawnCount;
    }
    list = ((WindEffect *)effect)->block.bytes;
    particle = ((WindBlock *)list)->particles.bytes;
    instance = ((WindBlock *)list)->instance.bytes;
    geometryInstance = (WindGeometryInstance *)instance;
    respawn = ((WindConfig *)config)->respawn;
    accel = ((WindConfig *)config)->unkD8;
    gravity = ((WindConfig *)config)->unkE4;
    RpGeometryLock(((RpAtomic *)geometryInstance->atomic)->geometry, 0xFF2);
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    vertices = (u8*)((RpMorphTarget *)(u8 *)((RpGeometry *)geometry)->morphTarget)->vertices;
    texCoords = (u8 *)((RpGeometry *)geometry)->texCoords[0];
    segmentCount = geometryInstance->vertexCount;
    sampleCount = ((WindConfig *)config)->segments.word + 1;
    sampleScale = (f32)sampleCount;
    vSpan = ((WindConfig *)config)->unk98;
    centre = ((WindConfig *)config)->unkEC;
    vStep = ((WindConfig *)config)->unkA4;
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
        entry = (WindParticle *)particle;
        state = entry->age.signedWord;
        if (state == -2) {
            goto skip;
        }
        if (state == -1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            t = ((WindConfig *)config)->unkC0;
            t = ((WindConfig *)config)->unkBC * ((one - t) + t * effMiscRandFloat(0));
            end = ((WindConfig *)config)->unkC8;
            entry->unkC = (((WindConfig *)config)->unkC4 * ((one - end) + end * effMiscRandFloat(0)) - t) / (f32)lifetime;
            entry->unk8 = t;
            t = ((WindConfig *)config)->unkE0;
            entry->unk10 = ((WindConfig *)config)->unkDC * ((one - t) + t * effMiscRandFloat(0));
            entry->unk14 = ((WindConfig *)config)->unkCC * effMiscRandFloat(0);
            t = ((WindConfig *)config)->unkE8;
            entry->unk28 = ((WindConfig *)config)->unkF0 * ((one - t) + t * effMiscRandFloat(0));
            entry->unk1C = spin * effMiscRandFloat(0);
            t = ((WindConfig *)config)->unkD4;
            entry->unk18 = ((WindConfig *)config)->unkD0 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkB4;
            entry->unk20 = ((WindConfig *)config)->unkB0 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkAC;
            entry->unk24 = ten * (((WindConfig *)config)->unkA8 * ((one - t) + t * effMiscRandFloat(0)));
            t = ((WindConfig *)config)->unk9C;
            ((WindFunnelParticle *)particle)->unk2C = ((WindConfig *)config)->unk98 * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                entry->age.word = effMiscRand(0) % lifetime;
                t = (f32)entry->age.signedWord;
                entry->unk14 = entry->unk14 + entry->unk10 * t;
                entry->unk14 = entry->unk14 - half * (t * (gravity * t));
                entry->unk8 = entry->unk8 + entry->unkC * t;
            } else {
                entry->age.word = 0;
            }
            pending--;
            goto skip;
        }
        if ((u32)state >= lifetime) {
            if (respawn != 0) {
                entry->age.signedWord = -1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                entry->age.signedWord = -2;
            }
            if (iGpffffbb64.c3 != 0xFF) {
                u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                ((WindMaterial *)color)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                    ((WindMaterial *)color)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            goto skip;
        }
        v0 = ((WindFunnelParticle *)particle)->unk2C;
        end = (f32)state;
        angle = end * (entry->unk18 + half * (accel * end));
        angle += entry->unk1C;
        {
            f32 base = entry->unk8;
            f32 offset;
            f32 width;
            f32 stepLength;
            f32 s;

            height = entry->unk14;
            swell = entry->unk28;
            offset = end / (f32)lifetime - centre;
            t = base + swell * (offset * offset);
            c = cosf(angle);
            s = sinf(angle);
            point.lane[0] = c * t;
            point.lane[1] = height;
            point.lane[2] = s * t;
            effectVuLoad11(&point);
            __asm__ volatile("vmove.xyzw $vf12, $vf11" : : : "$vf12");
            height = (height + entry->unk10) - gravity * end;
            base = operandOrderAddFloat(entry->unk8, entry->unkC) + swell * (((one + end) / (f32)lifetime - centre) * ((one + end) / (f32)lifetime - centre));
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
            entry->unk14 = height;
            entry->unk8 = entry->unk8 + entry->unkC;
            width = quarter * entry->unk20;
            stepLength = entry->unk24 / sampleScale;
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
                ((WindStripVertices *)vertices)->position[1][0] = D_00713D10[0];
                ((WindStripVertices *)vertices)->position[1][1] = D_00713D14[0];
                ((WindStripVertices *)vertices)->position[1][2] = D_00713D18[0];
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                ((WindStripVertices *)vertices)->position[0][0] = D_00713D10[0];
                ((WindStripVertices *)vertices)->position[0][1] = D_00713D14[0];
                ((WindStripVertices *)vertices)->position[0][2] = D_00713D18[0];
                __asm__ volatile(
                    "vmove.xyzw $vf10, $vf12\n"
                    "vsub.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                ((WindStripVertices *)vertices)->position[2][0] = D_00713D10[0];
                ((WindStripVertices *)vertices)->position[2][1] = D_00713D14[0];
                ((WindStripVertices *)vertices)->position[2][2] = D_00713D18[0];
                __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                ((WindStripVertices *)vertices)->position[3][0] = D_00713D10[0];
                ((WindStripVertices *)vertices)->position[3][1] = D_00713D14[0];
                ((WindStripVertices *)vertices)->position[3][2] = D_00713D18[0];
                vertices += 0x30;
                {
                    f32 v = v0 + vSpan * ((f32)sample / sampleScale);
                    ((WindStripTexCoords *)texCoords)->coordinates[0][1].value = v;
                    ((WindStripTexCoords *)texCoords)->coordinates[1][1].value = v;
                    ((WindStripTexCoords *)texCoords)->coordinates[2][1].value = v;
                    ((WindStripTexCoords *)texCoords)->coordinates[3][1].value = v;
                }
                texCoords += 0x20;
                effectVuLoad10(&direction);
                effectVuScale10(stepLength);
                __asm__ volatile("vadd.xyzw $vf12, $vf12, $vf10" : : : "$vf12");
            }
        }
        ((WindFunnelParticle *)particle)->unk2C = ((WindFunnelParticle *)particle)->unk2C + vStep;
        entry->age.word = entry->age.word + 1;
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
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    func_003c22f0((RpGeometry *)geometry);
    if ((geometryInstance->flags & 4) != 0) {
        ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
}
#pragma push
/* measured: retail does not hoist loop invariants in FallingFunnelWindPackColors. */
#pragma opt_loop_invariants off
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

        particleAges = ((WindBlock *)block)->particles.ages;
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
        mdlEffectApplyCombinedGeometryMatrix((u8 *)(instance), (struct RwV3d *)( effect), (void *)( effect + 0x10), (struct RwV3d *)( effect + 0x20));
        if (((WindConfig *)config)->drawFlag != 0) {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags | 1;
        } else {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}
#pragma pop

/* measured: without opt_loop_invariants, the 0xFF/0xFE/-1 constants are recomputed inside the loop
 * instead of hoisted out as retail does. Updates falling funnel entries (0x2C stride). */
/* Write the current material color into each particle's geometry material and mark every particle's
 * age as -1. If the color's alpha is 0xFF, it is temporarily set to 0xFE for the write. */
// FUN_004A4380
void FallingFunnelWindUpdateEntries(u8 *effect)
{
    u8 *block;
    u8 *particle;
    u32 count;
    u32 particleIndex;
    u8 *instance;
    u8 *material;

    block = ((WindEffect *)effect)->block.bytes;
    particle = ((WindBlock *)block)->particles.bytes;
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
        ((WindParticle *)particle)->age.signedWord = -1;
        particleIndex++;
        particle += 0x2C;
    }
}

/* Initialises the spiral wind entries from the config (0x2C stride): fills the first color/UV
 * strip, then duplicates it for the remaining meshes. Identical to the initializer at 004a1d70. */
// FUN_004A4450
void SpiralWindInitEntries(u8 *block, u8 *config)
{
    u32 meshCount;
    u8 *geometry;
    u8 *colors;
    WindBlock *windBlock = (WindBlock *)block;
    WindStripColors *colorRow;
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

    meshCount = ((WindConfig *)config)->particleCount.word;
    if (meshCount != 0) {
        geometry = (u8*)((RpAtomic *)((WindGeometryInstance *)windBlock->instance.bytes)->atomic)->geometry;
        RpGeometryLock((RpGeometry *)(geometry), 0xFF8);
        geometry = (u8*)((RpAtomic *)((WindGeometryInstance *)windBlock->instance.bytes)->atomic)->geometry;
        colorsBase = (u8 *)((RpGeometry *)geometry)->colors;
        colors = colorsBase;
        texCoordsBase = (u8 *)((RpGeometry *)geometry)->texCoords[0];
        texCoords = texCoordsBase;
        step = ((WindConfig *)config)->unk90 / 3.0f;
        frames = ((WindConfig *)config)->segments.signedWord;
        fadeIn = (s32)(((WindConfig *)config)->fadeIn * (f32)frames);
        fadeOut = (s32)(((WindConfig *)config)->fadeOut * (f32)frames);
        pointCount = frames + 1;
        wordCount = pointCount * 4;
        i = 0;
        while (i < pointCount) {
            colorRow = (WindStripColors *)colors;
            if (i < fadeIn) {
                opacity = (f32)i / (f32)(s32)fadeIn;
            } else if (fadeOut < i) {
                opacity = (f32)(u32)(frames - i) / (f32)(s32)(frames - fadeOut);
            } else {
                opacity = 1.0f;
            }
            colorRow->colors[0].word = 0xFFFFFF;
            colorRow->colors[1].word = ((u32)(opacity * 255.0f) << 24) | 0xFFFFFF;
            colorRow->colors[2].color = colorRow->colors[1].color;
            colorRow->colors[3].word = 0xFFFFFF;
            colors += 0x10;
            ((WindStripTexCoords *)texCoords)->coordinates[0][0].bits = 0;
            ((WindStripTexCoords *)texCoords)->coordinates[1][0].value = step;
            ((WindStripTexCoords *)texCoords)->coordinates[2][0].value = step * 2.0f;
            ((WindStripTexCoords *)texCoords)->coordinates[3][0].value = step * 3.0f;
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
        model = windBlock->instance.halves;
        geometry = (u8*)((RpAtomic *)((WindGeometryInstance *)(u8 *)model)->atomic)->geometry;
        func_003c22f0((RpGeometry *)(geometry));
        if ((*model & 4) != 0) {
            ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
}

// Allocates a spiral wind block: count * 44 entry bytes plus a 12-byte header.
// FUN_004A4790
u8 *SpiralWindAllocBlock(u8 *config, s32 texture)
{
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x2C + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x3E5);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = GeometryCreateStripGridMultiPart(settings->particleCount.half, settings->segments.half, (s32)(u32)D_00713330, 4, 0x4C);
    if (texture == 0) {
        mdlEffectSetGeometryTexture(allocation->instance.pointer, TnSlotObject(0x14));
    } else {
        mdlEffectUploadGeometryTexture(allocation->instance.pointer, texture);
    }
    SpiralWindInitEntries(work, config);
    return work;
}

// Allocates a spiral wind block that inherits its entry layout from a parent block.
// FUN_004A48D0
u8 *SpiralWindAllocFromParent(u8 *parent)
{
    u8 *parentBlock;
    u8 *config;
    u8 *work;
    s32 size;
    WindConfig *settings;
    WindBlock *allocation;

    parentBlock = ((WindEffect *)parent)->block.bytes;
    config = ((WindEffect *)parent)->config.bytes;
    settings = (WindConfig *)config;
    size = settings->particleCount.signedWord * 0x2C + 0xC;
    chkmemAllocSiteTag(D_00714110, 0x3E4);
    work = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (WindBlock *)work;
    if (work == NULL) {
        kAssertFail(D_00714110, 0x3E5);
    }
    allocation->particles.bytes = work + 0xC;
    allocation->allocation.bytes = work;
    if (settings->segments.word < 3U) {
        settings->segments.word = 3U;
    }
    allocation->instance.bytes = mdlEffectCloneMultipartGeometry(((WindBlock *)parentBlock)->instance.bytes);
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

#pragma push
/* measured: retail does not hoist loop invariants in SpiralWindUpdateStrip or SpiralWindPackColors. */
#pragma opt_loop_invariants off
/* Updates the spiral wind strip: each live particle samples points on a circle, transforms them by
 * the VU0 rotation matrix, and widens the strip along the normalised cross product. */
// FUN_004A4A10
void SpiralWindUpdateStrip(u8 *effect)
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
    WindGeometryInstance *geometryInstance;
    u32 lifetime;
    u8 *particle;
    WindParticle *entry;
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

    config = ((WindEffect *)effect)->config.bytes;
    limit = ((WindConfig *)config)->duration;
    elapsed = ((WindEffect *)effect)->elapsed;
    if ((limit < elapsed) && (limit != 0)) {
        return;
    }
    particleCount = ((WindConfig *)config)->particleCount.word;
    lifetime = ((WindConfig *)config)->lifetime;
    if (lifetime == 0) {
        return;
    }
    if ((((WindConfig *)config)->spawnAll != 0) && (elapsed == 0)) {
        spawnAll = 1;
        pending = particleCount;
    } else {
        spawnAll = 0;
        pending = ((WindConfig *)config)->spawnCount;
    }
    list = ((WindEffect *)effect)->block.bytes;
    particle = ((WindBlock *)list)->particles.bytes;
    instance = ((WindBlock *)list)->instance.bytes;
    geometryInstance = (WindGeometryInstance *)instance;
    respawn = ((WindConfig *)config)->respawn;
    accel = ((WindConfig *)config)->unkD4;
    RpGeometryLock(((RpAtomic *)geometryInstance->atomic)->geometry, 0xFF2);
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    vertices = (u8*)((RpMorphTarget *)(u8 *)((RpGeometry *)geometry)->morphTarget)->vertices;
    texCoords = (u8 *)((RpGeometry *)geometry)->texCoords[0];
    segmentCount = geometryInstance->vertexCount;
    sampleCount = ((WindConfig *)config)->segments.word + 1;
    sampleScale = (f32)sampleCount;
    vSpan = ((WindConfig *)config)->unk98;
    vStep = ((WindConfig *)config)->unkA4;
    index = 0;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    spread = iGpffff8084;
    spin = iGpffff8080;
    quarter = 0.25f;
    zero = 0.0f;
    for (; index < particleCount; index++, particle += 0x2C) {
        entry = (WindParticle *)particle;
        state = entry->age.word;
        if (state == (u32)-2) {
            goto skip;
        }
        if (state == (u32)-1) {
            memset(vertices, 0, segmentCount * 12);
            if (pending == 0) {
                goto skip;
            }
            start = ((WindConfig *)config)->unkC0;
            start = ((WindConfig *)config)->unkBC * ((one - start) + start * effMiscRandFloat(0));
            end = ((WindConfig *)config)->unkC8;
            entry->unk14 = (((WindConfig *)config)->unkC4 * ((one - end) + end * effMiscRandFloat(0)) - start) / (f32)lifetime;
            entry->unk10 = start;
            entry->unk8 = spread * (two * (effMiscRandFloat(0) - half));
            entry->unkC = spread * (two * (effMiscRandFloat(0) - half));
            entry->unk1C = spin * effMiscRandFloat(0);
            t = ((WindConfig *)config)->unkD0;
            entry->unk18 = ((WindConfig *)config)->unkCC * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkB4;
            entry->unk20 = ((WindConfig *)config)->unkB0 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unkAC;
            entry->unk24 = ((WindConfig *)config)->unkA8 * ((one - t) + t * effMiscRandFloat(0));
            t = ((WindConfig *)config)->unk9C;
            entry->unk28 = ((WindConfig *)config)->unk98 * ((one - t) + t * effMiscRandFloat(0));
            if (spawnAll != 0) {
                entry->age.word = effMiscRand(0) % lifetime;
                t = (f32)entry->age.signedWord;
                entry->unk10 = entry->unk10 + entry->unk14 * t;
            } else {
                entry->age.word = 0;
            }
            pending--;
            goto skip;
        }
        if (state >= lifetime) {
            if (respawn != 0) {
                entry->age.word = (u32)-1;
            } else {
                memset(vertices, 0, segmentCount * 12);
                entry->age.word = (u32)-2;
            }
            if (iGpffffbb64.c3 != 0xFF) {
                u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                ((WindMaterial *)color)->unk4 = iGpffffbb64;
            } else {
                iGpffffbb64.c3 = 0xFE;
                {
                    u8 *color = ((u8 **)geometryInstance->materials)[(u16)index];
                    ((WindMaterial *)color)->unk4 = iGpffffbb64;
                }
                iGpffffbb64.c3 = 0xFF;
            }
            goto skip;
        }
        t = (f32)(s32)state;
        angle = t * (entry->unk18 + half * (accel * t));
        angle += entry->unk1C;
        radius = (entry->unk10 += entry->unk14);
        width = quarter * entry->unk20;
        if (!(entry->unk18 < zero)) {
            step = entry->unk24 / sampleScale;
        } else {
            step = -entry->unk24 / sampleScale;
        }
        v0 = entry->unk28;
        effMiscRotateXVU(entry->unk8);
        effMiscRotateYVU(entry->unkC);
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
            ((WindStripVertices *)vertices)->position[1][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[1][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[1][2] = D_00713D18[0];
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[0][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[0][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[0][2] = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[2][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[2][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[2][2] = D_00713D18[0];
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((WindStripVertices *)vertices)->position[3][0] = D_00713D10[0];
            ((WindStripVertices *)vertices)->position[3][1] = D_00713D14[0];
            ((WindStripVertices *)vertices)->position[3][2] = D_00713D18[0];
            vertices += 0x30;
            {
                f32 v = v0 + vSpan * ((f32)sample / sampleScale);
                ((WindStripTexCoords *)texCoords)->coordinates[0][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[1][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[2][1].value = v;
                ((WindStripTexCoords *)texCoords)->coordinates[3][1].value = v;
            }
            texCoords += 0x20;
        }
        entry->unk28 = entry->unk28 + vStep;
        entry->age.word = entry->age.word + 1;
        continue;
skip:
        vertices += segmentCount * 12;
        texCoords += segmentCount * 8;
    }
    geometry = (u8*)((RpAtomic *)geometryInstance->atomic)->geometry;
    func_003c22f0((RpGeometry *)geometry);
    if ((geometryInstance->flags & 4) != 0) {
        ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
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

        particleAges = ((WindBlock *)block)->particles.ages;
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
        mdlEffectApplyCombinedGeometryMatrix((u8 *)(instance), (struct RwV3d *)( effect), (void *)( effect + 0x10), (struct RwV3d *)( effect + 0x20));
        if (((WindConfig *)config)->drawFlag != 0) {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags | 1;
        } else {
            ((WindGeometryInstance *)instance)->flags = ((WindGeometryInstance *)instance)->flags & 0xFFFE;
        }
        mdlEffectAppendGeometryPrimitive(instance, ((WindConfig *)config)->unk28);
    }
}
#pragma pop

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
    parameterBytes = D_00714148[kindIndex].parameterBytes;
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
    u32 kindIndex;

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
    kindIndex = ((u32)kind & 0xFFFF);
    ((WindEffect *)effect)->block.word = (u32)D_00714134[kindIndex].allocate(parameters, texture);
    D_00714130[kindIndex].initialize(effect);
    if (effect == NULL) {
        kAssertFail(D_00714110, 0x5E5);
    }
    return effect;
}
