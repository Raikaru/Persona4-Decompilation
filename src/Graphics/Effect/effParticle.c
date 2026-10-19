/* Original translation unit effParticle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "particle_spawn_internal.h"

typedef char ParticleInstanceExtent[sizeof(EffParticleInstance) == 0x60 ? 1 : -1];

typedef unsigned int ParticleSnapshot __attribute__((mode(TI)));

void GeometryBlockDestroy(s32 object);
s32 GeometryCreateAtomicFromResource(s32 object, s32 value);

void mdlEffectReleaseTrackInstance(s32 object);
s32 mdlEffectCreateTrackInstance(s32 *object);
extern s32 mdlEffectShareTrackInstance(s32 object);

void TlpRelease(s32 object);
s32 TlpCreate(s32 *object);
extern s32 TlpAddRef(s32 object);

extern void mdlEffectResetEmitterTicks(s32 objectAddress);
extern void mdlEffectFreeEmitterAllocation(u8 *object);
extern u8 *func_00492b20(u16 object, u32 value, void *data);
extern s32 TnSlotObject(s32 object);
typedef struct RpMaterial RpMaterial;
typedef struct RwTexture RwTexture;

extern RpMaterial *func_003c42b0(RpMaterial *material, RwTexture *texture);
extern void *TnUploadStreamTagged(void *object);
extern void func_003ef3a0(void *object);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memset(void *dst, s32 value, u32 size);
extern void kAssertFail(void *file, s32 line);
extern u8 D_00713CC0[];
extern u8 D_00713CD0[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *func_00484570(u8 *object);
extern void func_004846d0(u8 *object);
extern u8 *mdlEffectCreateChildRecord(u8 *object);
extern void mdlEffectDestroyWithNodes(void *object);
extern u8 *GeometryCloneBlock(void *object);
void ParticleAllocRecords(u8 *object, s32 value, void *data);
void ParticleCopyModeFromSource(u8 *object, u8 *value);
void ParticleSetMaterialSlot(u8 *object, s32 value, s32 data);
void ParticleSetTextureFromHandle(u8 *object, s32 value);
void ParticleSetLinkedGroup(u8 *object, s32 *value);
void ParticleSetTextureById(u8 *object, s32 value);
void ParticleRebuildSubtypeChain(u8 *object, void *value);
void ParticleRebuildSubtypeChainAlt(u8 *object, void *value);
void ParticleSetAuxResource(u8 *object, s32 *value);
extern void mdlEffectStartChild(u8 *object);
extern void mdlEffectScaleChild(u8 *object, f32 value);
extern void mdlEffectUpdateChildData(u8 *object, void *value);
extern void mdlEffectCommitChild(u8 *object);
extern void mdlEffectStartChildren(u8 *object);
extern void mdlEffectSetChildScales(u8 *object, f32 value);
extern void mdlEffectSetChildPositions(u8 *object, f32 *value);
extern void func_00485630(u8 *object);
extern ParticleSnapshot mdlEffectLoadQuadB(s32 object, u32 *value);
extern ParticleSnapshot mdlEffectLoadQuadA(s32 object, u32 *value);
extern void effMiscBuildRotationVU(void);

// Allocates a 0x60-byte particle block with the given count, unit scale and no links.
// FUN_00486A50
void *ParticleCreateBlock(s32 recordCount)
{
    u8 *particle;

    chkmemAllocSiteTag(D_00713CC0, 0x171);
    particle = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    memset(particle, 0, 0x60);
    if (particle == NULL) {
        kAssertFail(D_00713CD0, 0x1F);
    }
    ((EffParticleInstance *)particle)->recordCount.signedValue = recordCount;
    ((EffParticleInstance *)particle)->packedColor.signedValue = -1;
    ((EffParticleInstance *)particle)->scale.signedBits = 0x3F800000;
    return particle;
}
// Creates a particle block from an emitter source: count from the emitter's params (capped at 300), records, then the source's mode.
// FUN_00486B00
/* Raw descriptor/handle accesses retain the measured retail instruction
 * ordering; replacing these fields with typed members regressed the match. */
void *ParticleCreateFromSource(void *opaqueSource)
{
    u8 *source = opaqueSource;
    u8 *settings;
    u32 allocatorAddress;
    u32 count;
    u32 emitCount;
    u8 *link;
    s32 *resource;

    settings = (u8 *)mdlEffectResolveRelPtrA(source);
    if (settings == NULL) {
        kAssertFail(D_00713CD0, 0x55);
    }
    emitCount = (u32)((WaveSpawnParameters *)settings)->emissionDuration;
    if (emitCount == 0) {
        count = (u32)((WaveSpawnParameters *)settings)->lifetime * ((WaveSpawnParameters *)settings)->emissionRate;
    } else {
        count = emitCount * ((WaveSpawnParameters *)settings)->emissionRate;
    }
    if (count > 300) {
        count = 300;
    }
    chkmemAllocSiteTag(D_00713CC0, 0x171);
    allocatorAddress = (u32)jtbl_008873E8;
    {
        u8 *const particle = (*(void *(**)(u32, u32))allocatorAddress)(0x60, 0x40000);
        memset(particle, 0, 0x60);
        if (particle == NULL) {
            kAssertFail(D_00713CD0, 0x1F);
        }
        ((EffParticleInstance *)particle)->recordCount.value = count;
        ((EffParticleInstance *)particle)->packedColor.signedValue = -1;
        ((EffParticleInstance *)particle)->scale.value = 1.0f;
        if (particle == NULL) {
            kAssertFail(D_00713CD0, 0x57);
        }
        ParticleAllocRecords(particle, *(u16 *)(source + 0xC), settings);
        if (*(u32 *)particle == 0) {
            return particle;
        }
        resource = (s32 *)mdlEffectResolveRelPtrB(source);
        if (resource != NULL) {
            switch (*(u16 *)(source + 0x1C)) {
            case 1:
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 1);
                ParticleSetTextureFromHandle(particle, (s32)resource);
                break;
            case 2:
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 2);
                ParticleSetLinkedGroup(particle, resource);
                break;
            case 4:
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 4);
                ParticleSetTextureById(particle, *resource);
                break;
            case 5:
                ParticleRebuildSubtypeChain(particle, resource);
                break;
            case 6:
                ParticleRebuildSubtypeChainAlt(particle, resource);
                break;
            case 7:
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 7);
                ParticleSetAuxResource(particle, resource);
                chkmemAllocSiteTag(D_00713CC0, 0x171);
                link = (*(void *(**)(u32, u32))allocatorAddress)(0x30, 0x40000);
                memset(link, 0, 0x30);
                ((EffParticleInstance *)particle)->link = (ParticleLinkNode *)link;
                ((ParticleLinkNode *)link)->tag = 0x19;
                ((EffParticleInstance *)particle)->link->owner = particle;
                break;
            default:
                kAssertFail(D_00713CD0, 0x7E);
                break;
            }
            ((EffParticleInstance *)particle)->kind = *(u16 *)(source + 0x1C);
        }
        return particle;
    }
}

// Frees a particle block: its records and sub-objects, then the block itself.
// FUN_00486E10
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleFree(u8 *particle)
{
    u32 count;
    u32 i;

    if (*(s32 *)(particle + 0x38) != 0) {
        if (*(s32 *)(particle + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(particle + 0x4C) + 8);
        } else {
            count = *(s32 *)(particle + 0);
        }
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(particle + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(particle + 0x38));
    }
    if (*(s32 *)(particle + 0x40) != 0) {
        if (*(s32 *)(particle + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(particle + 0x4C) + 8);
        } else {
            count = *(s32 *)(particle + 0);
        }
        for (i = 0; i < count; i++) {
            mdlEffectDestroyWithNodes(*(u8 **)(*(u8 **)(particle + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(particle + 0x40));
    }
    if (*(s32 *)(particle + 0x44) != 0) {
        mdlEffectReleaseTrackInstance(*(s32 *)(particle + 0x44));
    }
    if (*(s32 *)(particle + 0x48) != 0) {
        TlpRelease(*(s32 *)(particle + 0x48));
    }
    if (*(u8 *)(particle + 0xE) & 1) {
        mdlEffectFreeEmitterAllocation((u8 *)*(s32 *)(particle + 0x4C));
    }
    if (*(s32 *)(particle + 0x50) != 0) {
        GeometryBlockDestroy(*(s32 *)(particle + 0x50));
    }
    if (((EffParticleInstance *)particle)->link != NULL) {
        jtbl_008873EC[0](((EffParticleInstance *)particle)->link);
    }
    jtbl_008873EC[0](particle);
}
// Creates a particle block from a parent particle block, copying its records and mode.
// FUN_00486FB0
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void *ParticleCreateFromParent(void *opaqueSource)
{
    u8 *particle = opaqueSource;
    u32 recordCapacity;
    u8 *parameters;
    u8 *createdParticle;
    u32 emissionCount;

    if (*(s32 *)(particle + 0x4C) == 0) {
        kAssertFail(D_00713CD0, 0xE0);
    }
    parameters = *(u8 **)(*(u8 **)(particle + 0x4C) + 0x24);
    if (parameters == NULL) {
        kAssertFail(D_00713CD0, 0xE2);
    }
    emissionCount = (u32)((WaveSpawnParameters *)parameters)->emissionDuration;
    if (emissionCount == 0) {
        recordCapacity = (u32)((WaveSpawnParameters *)parameters)->lifetime * ((WaveSpawnParameters *)parameters)->emissionRate;
    } else {
        recordCapacity = emissionCount * ((WaveSpawnParameters *)parameters)->emissionRate;
    }
    if (recordCapacity > 0x12C) {
        recordCapacity = 0x12C;
    }
    chkmemAllocSiteTag(D_00713CC0, 0x171);
    createdParticle = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    memset(createdParticle, 0, 0x60);
    if (createdParticle == NULL) {
        kAssertFail(D_00713CD0, 0x1F);
    }
    *(u32 *)(createdParticle + 0) = recordCapacity;
    *(s32 *)(createdParticle + 4) = -1;
    *(s32 *)(createdParticle + 8) = 0x3F800000;
    if (createdParticle == NULL) {
        kAssertFail(D_00713CD0, 0xE4);
    }
    ParticleAllocRecords(createdParticle, *(u16 *)(*(u8 **)(particle + 0x4C)), (void *)parameters);
    if (*(s32 *)(createdParticle + 0) == 0) {
        return createdParticle;
    }
    if (*(s32 *)(particle + 0x50) != 0) {
        *(s32 *)(createdParticle + 0x50) = (s32)GeometryCloneBlock((void *)*(s32 *)(particle + 0x50));
    }
    ParticleCopyModeFromSource(createdParticle, particle);
    return createdParticle;
}
/* measured: case-local count/index pairs make b210 color the loop locals
   $s2/$s3 and the parameters $s1/$s0, matching retail. The named case-7
   allocation result remains in $s2 through memset before being stored at
   particle+0x5C. Shared function-scope counters rotate all four saved registers.
   Object/window 1136B, normalized_diff 0. */
// Copies the source's mode into the particle block: dispatches on the source's type word to the matching setter.
// FUN_00487160
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleCopyModeFromSource(u8 *particle, u8 *source)
{
    switch (*(u16 *)(source + 0xC)) {
    case 1:
    case 4:
        *(f32 *)(particle + 0x54) = *(f32 *)(source + 0x54);
        *(f32 *)(particle + 0x58) = *(f32 *)(source + 0x58);
        break;
    case 2:
        if (*(s32 *)(source + 0x44) == 0) {
            kAssertFail(D_00713CD0, 0x10D);
        }
        if (*(s32 *)(source + 0x4C) == 0) {
            kAssertFail(D_00713CD0, 0x10E);
        }
        if (*(s32 *)(particle + 0x44) != 0) {
            mdlEffectReleaseTrackInstance(*(s32 *)(particle + 0x44));
        }
        *(s32 *)(particle + 0x44) = mdlEffectShareTrackInstance(*(s32 *)(source + 0x44));
        break;
    case 5: {
        u32 count5;
        u32 i5;

        count5 = *(u32 *)(*(u8 **)(source + 0x4C) + 8);
        if (count5 == 0) {
            return;
        }
        if (*(s32 *)(source + 0x38) == 0) {
            kAssertFail(D_00713CD0, 0x119);
        }
        if (*(s32 *)(source + 0x4C) == 0) {
            kAssertFail(D_00713CD0, 0x11A);
        }
        if (*(s32 *)(particle + 0x38) != 0) {
            for (i5 = 0; i5 < count5; i5++) {
                func_004846d0(*(u8 **)(*(u8 **)(particle + 0x34) + i5 * 4));
            }
            jtbl_008873EC[0](*(void **)(particle + 0x38));
            *(u8 **)(particle + 0x34) = NULL;
            *(u8 **)(particle + 0x38) = NULL;
        }
        if (count5 * 4 == 0) {
            return;
        }
        chkmemAllocSiteTag(D_00713CD0, 0x12C);
        *(u8 **)(particle + 0x38) = (u8 *)(*jtbl_008873E8)(count5 * 4, 0x40000);
        if (*(u8 **)(particle + 0x38) == NULL) {
            kAssertFail(D_00713CD0, 0x12D);
        }
        *(u8 **)(particle + 0x34) = *(u8 **)(particle + 0x38);
        for (i5 = 0; i5 < count5; i5++) {
            *(u8 **)(*(u8 **)(particle + 0x34) + i5 * 4) =
                mdlEffectCreateChildRecord(*(u8 **)(*(u8 **)(source + 0x34)));
        }
        break;
    }
    case 6: {
        u32 count6;
        u32 i6;

        count6 = *(u32 *)(*(u8 **)(source + 0x4C) + 8);
        if (count6 == 0) {
            return;
        }
        if (*(s32 *)(source + 0x40) == 0) {
            kAssertFail(D_00713CD0, 0x139);
        }
        if (*(s32 *)(source + 0x4C) == 0) {
            kAssertFail(D_00713CD0, 0x13A);
        }
        if (*(s32 *)(particle + 0x40) != 0) {
            for (i6 = 0; i6 < count6; i6++) {
                mdlEffectDestroyWithNodes(*(u8 **)(*(u8 **)(particle + 0x3C) + i6 * 4));
            }
            jtbl_008873EC[0](*(void **)(particle + 0x40));
            *(u8 **)(particle + 0x3C) = NULL;
            *(u8 **)(particle + 0x40) = NULL;
        }
        if (count6 * 4 == 0) {
            return;
        }
        chkmemAllocSiteTag(D_00713CD0, 0x14C);
        *(u8 **)(particle + 0x40) = (u8 *)(*jtbl_008873E8)(count6 * 4, 0x40000);
        if (*(u8 **)(particle + 0x40) == NULL) {
            kAssertFail(D_00713CD0, 0x14D);
        }
        *(u8 **)(particle + 0x3C) = *(u8 **)(particle + 0x40);
        for (i6 = 0; i6 < count6; i6++) {
            *(u8 **)(*(u8 **)(particle + 0x3C) + i6 * 4) =
                mdlEffectCloneWithNodes(*(u8 **)(*(u8 **)(source + 0x3C)));
        }
        break;
    }
    case 7: {
        u8 *p;

        /* The source handle reads and the store stay as raw offsets: typed forms changed the codegen (measured). */
        if (*(s32 *)(source + 0x48) == 0) {
            kAssertFail(D_00713CD0, 0x156);
        }
        if (((EffParticleInstance *)particle)->tlpRef != 0) {
            TlpRelease(((EffParticleInstance *)particle)->tlpRef);
        }
        *(s32 *)(particle + 0x48) = TlpAddRef(*(s32 *)(source + 0x48));
        if (((EffParticleInstance *)particle)->link != NULL) {
            kAssertFail(D_00713CD0, 0x15F);
        }
        chkmemAllocSiteTag(D_00713CC0, 0x171);
        p = (u8 *)(*jtbl_008873E8)(0x30, 0x40000);
        memset(p, 0, 0x30);
        ((EffParticleInstance *)particle)->link = (ParticleLinkNode *)p;
        ((ParticleLinkNode *)p)->tag = 0x19;
        ((EffParticleInstance *)particle)->link->owner = particle;
        break;
    }
    default:
        kAssertFail(D_00713CD0, 0x16A);
        break;
    }
    *(u16 *)(particle + 0xC) = *(u16 *)(source + 0xC);
}

// Allocates the particle record block (count times the record size) and marks the block dirty.
// FUN_004875D0
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleAllocRecords(u8 *particle, s32 source, void *options)
{
    if (*(u32 *)(particle + 0x4C) != 0) {
        mdlEffectFreeEmitterAllocation((u8 *)*(u32 *)(particle + 0x4C));
    }
    *(u32 *)(particle + 0x4C) = (u32)func_00492b20(source & 0xFFFF, *(u32 *)(particle + 0), options);
    *(u8 *)(particle + 0xE) |= 1;
}




// Sets the material slot from the type: types 1 and 4 take a material by id, type 2 takes the second material id, type 7 leaves it.
// FUN_00487650
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleSetMaterialSlot(u8 *particle, s32 source, s32 options)
{
    s32 previousHandle = *(s32 *)(particle + 0x50);

    if (previousHandle != 0) {
        GeometryBlockDestroy(previousHandle);
    }
    switch (options) {
    case 1:
    case 4:
        *(s32 *)(particle + 0x50) = GeometryCreateAtomicFromResource(source & 0xFFFF, 0x20080027);
        return;
    case 2:
        *(s32 *)(particle + 0x50) = GeometryCreateAtomicFromResource(source & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}

/* Raster +0xC/+0x10 are width/height. Keep raw access: rw_camera_internal.h
 * conflicts with this unit's existing RwMatrixTag definition. The nested material
 * lookup is the native geometry block/atomic/geometry/material chain. */
// Sets the texture scale from the texture table entry by id and applies the texture to the material.
// FUN_00487710
void ParticleSetTextureById(u8 *particle, s32 source)
{
    void *texture = (void *)TnSlotObject(source & 0xFFFF);
    u8 *raster = *(u8 **)texture;
    f32 rasterHeight = (f32)*(s32 *)(raster + 0x10);
    f32 rasterWidth = (f32)*(s32 *)(raster + 0xC);

    ((EffParticleInstance *)particle)->texScaleX = rasterWidth / 2.0f / 16.0f;
    ((EffParticleInstance *)particle)->texScaleY = rasterHeight / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(((EffParticleInstance *)particle)->geometry.bytes + 0x10) + 0x18) + 0x20)), (RwTexture *)texture);
}
/* Same raster/material pointer layouts and header conflict as the ID setter. */
// Sets the texture scale from a texture handle, applies the texture to the material, then releases the handle.
// FUN_004877B0
void ParticleSetTextureFromHandle(u8 *particle, s32 source)
{
    void *texture = TnUploadStreamTagged((void *)source);
    u8 *raster = *(u8 **)texture;
    f32 rasterHeight = (f32)*(s32 *)(raster + 0x10);
    f32 rasterWidth = (f32)*(s32 *)(raster + 0xC);

    ((EffParticleInstance *)particle)->texScaleX = rasterWidth / 2.0f / 16.0f;
    ((EffParticleInstance *)particle)->texScaleY = rasterHeight / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(((EffParticleInstance *)particle)->geometry.bytes + 0x10) + 0x18) + 0x20)), (RwTexture *)texture);
    func_003ef3a0(texture);
}




// Replaces the linked group handle with the one returned for the given list.
// FUN_00487860
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleSetLinkedGroup(u8 *particle, s32 *source)
{
    s32 previousHandle = *(s32 *)(particle + 0x44);

    if (previousHandle != 0) {
        mdlEffectReleaseTrackInstance(previousHandle);
    }
    *(s32 *)(particle + 0x44) = mdlEffectCreateTrackInstance(source);
}

// Rebuilds the subtype chain: releases the old chain, then builds count entries from the resource (entry 0 from the resource, the rest linked).
// FUN_004878C0
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleRebuildSubtypeChain(u8 *particle, void *source)
{
    u32 count;
    u32 i;

    if (*(s32 *)(particle + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(particle + 0x4C) + 8);
    } else {
        count = *(s32 *)(particle + 0);
    }
    if (*(s32 *)(particle + 0x38) != 0) {
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(particle + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(particle + 0x38));
        *(u8 **)(particle + 0x34) = NULL;
        *(u8 **)(particle + 0x38) = NULL;
    }
    if (count * 4 != 0) {
        chkmemAllocSiteTag(D_00713CD0, 0x21C);
        *(u8 **)(particle + 0x38) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(particle + 0x38) == NULL) {
            kAssertFail(D_00713CD0, 0x21D);
        }
        *(u8 **)(particle + 0x34) = *(u8 **)(particle + 0x38);
        *(u8 **)(*(u8 **)(particle + 0x34)) = func_00484570((u8 *)source);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(particle + 0x34) + i * 4) = mdlEffectCreateChildRecord(*(u8 **)(*(u8 **)(particle + 0x34)));
        }
    }
}
// Rebuilds the alternate subtype chain: releases the old chain, then builds count entries linked from the resource; same shape as ParticleRebuildSubtypeChain.
// FUN_00487A30
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleRebuildSubtypeChainAlt(u8 *particle, void *source)
{
    u32 count;
    u32 i;

    if (*(s32 *)(particle + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(particle + 0x4C) + 8);
    } else {
        count = *(s32 *)(particle + 0);
    }
    if (*(s32 *)(particle + 0x40) != 0) {
        for (i = 0; i < count; i++) {
            mdlEffectDestroyWithNodes(*(u8 **)(*(u8 **)(particle + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(particle + 0x40));
        *(u8 **)(particle + 0x3C) = NULL;
        *(u8 **)(particle + 0x40) = NULL;
    }
    if (count * 4 != 0) {
        chkmemAllocSiteTag(D_00713CD0, 0x24F);
        *(u8 **)(particle + 0x40) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(particle + 0x40) == NULL) {
            kAssertFail(D_00713CD0, 0x250);
        }
        *(u8 **)(particle + 0x3C) = *(u8 **)(particle + 0x40);
        *(u8 **)(*(u8 **)(particle + 0x3C)) = mdlEffectBuildFromResource((u8 *)source);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(particle + 0x3C) + i * 4) = mdlEffectCloneWithNodes(*(u8 **)(*(u8 **)(particle + 0x3C)));
        }
    }
}




// Replaces the auxiliary resource handle with the one returned for the given list.
// FUN_00487BA0
/* Raw descriptor/handle accesses retain the measured retail instruction
 * ordering; replacing these fields with typed members regressed the match. */
void ParticleSetAuxResource(u8 *particle, s32 *source)
{
    s32 previousHandle = *(s32 *)(particle + 0x48);

    if (previousHandle != 0) {
        TlpRelease(previousHandle);
    }
    *(s32 *)(particle + 0x48) = TlpCreate(source);
}



// Releases the particle record block, if present.
// FUN_00487C00
void ParticleReleaseRecords(s32 particleAddress)
{
  if (((EffParticleInstance *)particleAddress)->emitter.handle != 0) {
    mdlEffectResetEmitterTicks(((EffParticleInstance *)particleAddress)->emitter.handle);
  }
  return;
}

typedef struct ParticleUpdateRecord
{
    f32 position[4];
    s32 age;
    u32 color;
    f32 scale;
    f32 angle;
} ParticleUpdateRecord __attribute__((aligned(16)));

/* measured: native b210 -O2 emits 892 exact bytes and four zero alignment bytes.
 * Each real loop index is initialized after its emitter/setup phase. The object
 * cursor's initialized scope begins at the existing subtype array lookup.
 * These lifetimes preserve the signed count snapshot, per-record reloads, and
 * all VU0 operations, including the transformed subtype-5 start-call omission.
 * Evidence: build/finish-first-party-20260922/particle-next-03/. */

// Per-frame update: scales each live particle record through the VU0 transform and writes its colour and angle.
// FUN_00487C30
void ParticleUpdateScaled(u8* particle, f32 scale)
{
    f32 transformedPosition[4] __attribute__((aligned(16)));
    u32 translationSnapshot[4] __attribute__((aligned(16)));
    u32 rotationSnapshot[4] __attribute__((aligned(16)));
    f32 transform[4][4] __attribute__((aligned(16)));
    s32 particleCount;
    u16 subtype;
    s32 emitterAddress;
    ParticleUpdateRecord* record;

    emitterAddress = ((EffParticleInstance *)particle)->emitter.handle;
    subtype = ((EffParticleInstance *)particle)->kind;
    switch (subtype)
    {
    case 5:
        record = (ParticleUpdateRecord *)((WaveSpawnEmitter *)emitterAddress)->particles;
        /* The object-array traversal starts after the record-base lookup. */
        {
            u8** objects = ((EffParticleInstance *)particle)->children.objects;
            particleCount = (s32)((WaveSpawnEmitter *)emitterAddress)->totalCount;
            if ((((WaveSpawnEmitter *)emitterAddress)->flags & 1) == 0)
            {
                {
                    /* This traversal starts only after its emitter/setup phase. */
                    s32 index = 0;
                    while (index < particleCount)
                    {
                        if (record->age == 0)
                        {
                            mdlEffectStartChild(*objects);
                        }
                        if (record->age >= 0)
                        {
                            mdlEffectScaleChild(*objects, record->scale * scale);
                            mdlEffectUpdateChildData(*objects, record);
                            mdlEffectCommitChild(*objects);
                        }
                        index++;
                        record++;
                        objects++;
                    }
                }
                return;
            }
            mdlEffectLoadQuadB(emitterAddress, (u32*)rotationSnapshot);
            mdlEffectLoadQuadA(emitterAddress, (u32*)translationSnapshot);
            __asm__ volatile(".set noreorder       \n"
                             "lqc2 $vf10, 0(%0)    \n"
                             ".set reorder         \n"
                             :
                             : "r"(rotationSnapshot)
                             : "$vf10", "memory");
            /* VU0 quaternion input is VF10; the helper produces VF28..VF31. */
            effMiscBuildRotationVU();
            __asm__ volatile(".set noreorder       \n"
                             "lqc2 $vf31, 0(%0)    \n"
                             ".set reorder         \n"
                             :
                             : "r"(translationSnapshot)
                             : "$vf31", "memory");
            __asm__ volatile(".set noreorder       \n"
                             "sqc2 $vf28, 0(%0)    \n"
                             "sqc2 $vf29, 16(%0)   \n"
                             "sqc2 $vf30, 32(%0)   \n"
                             "sqc2 $vf31, 48(%0)   \n"
                             ".set reorder         \n"
                             :
                             : "r"(transform)
                             : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            {
                /* This traversal starts only after its emitter/setup phase. */
                s32 index = 0;
                while (index < particleCount)
                {
                    if (record->age >= 0)
                    {
                        __asm__ volatile(".set noreorder                  \n"
                                         "lqc2 $vf28, 0(%0)                \n"
                                         "lqc2 $vf29, 16(%0)               \n"
                                         "lqc2 $vf30, 32(%0)               \n"
                                         "lqc2 $vf31, 48(%0)               \n"
                                         "lqc2 $vf10, 0(%1)                \n"
                                         "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                                         "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                                         "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                                         "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                                         ".set reorder                    \n"
                                         :
                                         : "r"(transform), "r"(record)
                                         : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                        __asm__ volatile(".set noreorder       \n"
                                         "sqc2 $vf10, 0(%0)    \n"
                                         ".set reorder         \n"
                                         :
                                         : "r"(transformedPosition)
                                         : "$vf10", "memory");
                        mdlEffectScaleChild(*objects, record->scale * scale);
                        mdlEffectUpdateChildData(*objects, transformedPosition);
                        mdlEffectCommitChild(*objects);
                    }
                    index++;
                    record++;
                    objects++;
                }
            }
            return;
        }
    case 6:
        record = (ParticleUpdateRecord *)((WaveSpawnEmitter *)emitterAddress)->particles;
        /* The object-array traversal starts after the record-base lookup. */
        {
            u8** objects = ((EffParticleInstance *)particle)->models.objects;
            particleCount = (s32)((WaveSpawnEmitter *)emitterAddress)->totalCount;
            if ((((WaveSpawnEmitter *)emitterAddress)->flags & 1) == 0)
            {
                {
                    /* This traversal starts only after its emitter/setup phase. */
                    s32 index = 0;
                    while (index < particleCount)
                    {
                        if (record->age == 0)
                        {
                            mdlEffectStartChildren(*objects);
                        }
                        if (record->age >= 0)
                        {
                            mdlEffectSetChildScales(*objects, record->scale * scale);
                            mdlEffectSetChildPositions(*objects, (f32*)record);
                            func_00485630(*objects);
                        }
                        index++;
                        record++;
                        objects++;
                    }
                }
                return;
            }
            mdlEffectLoadQuadB(emitterAddress, (u32*)rotationSnapshot);
            mdlEffectLoadQuadA(emitterAddress, (u32*)translationSnapshot);
            __asm__ volatile(".set noreorder       \n"
                             "lqc2 $vf10, 0(%0)    \n"
                             ".set reorder         \n"
                             :
                             : "r"(rotationSnapshot)
                             : "$vf10", "memory");
            /* VU0 quaternion input is VF10; the helper produces VF28..VF31. */
            effMiscBuildRotationVU();
            __asm__ volatile(".set noreorder       \n"
                             "lqc2 $vf31, 0(%0)    \n"
                             ".set reorder         \n"
                             :
                             : "r"(translationSnapshot)
                             : "$vf31", "memory");
            __asm__ volatile(".set noreorder       \n"
                             "sqc2 $vf28, 0(%0)    \n"
                             "sqc2 $vf29, 16(%0)   \n"
                             "sqc2 $vf30, 32(%0)   \n"
                             "sqc2 $vf31, 48(%0)   \n"
                             ".set reorder         \n"
                             :
                             : "r"(transform)
                             : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            {
                /* This traversal starts only after its emitter/setup phase. */
                s32 index = 0;
                while (index < particleCount)
                {
                    if (record->age == 0)
                    {
                        mdlEffectStartChildren(*objects);
                    }
                    if (record->age >= 0)
                    {
                        __asm__ volatile(".set noreorder                  \n"
                                         "lqc2 $vf28, 0(%0)                \n"
                                         "lqc2 $vf29, 16(%0)               \n"
                                         "lqc2 $vf30, 32(%0)               \n"
                                         "lqc2 $vf31, 48(%0)               \n"
                                         "lqc2 $vf10, 0(%1)                \n"
                                         "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                                         "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                                         "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                                         "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                                         ".set reorder                    \n"
                                         :
                                         : "r"(transform), "r"(record)
                                         : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                        __asm__ volatile(".set noreorder       \n"
                                         "sqc2 $vf10, 0(%0)    \n"
                                         ".set reorder         \n"
                                         :
                                         : "r"(transformedPosition)
                                         : "$vf10", "memory");
                        mdlEffectSetChildScales(*objects, record->scale * scale);
                        mdlEffectSetChildPositions(*objects, (f32*)transformedPosition);
                        func_00485630(*objects);
                    }
                    index++;
                    record++;
                    objects++;
                }
            }
            return;
        }
    }
}
typedef struct RpAtomic RpAtomic;
typedef enum RpPTankLockFlags
{
    rpPTANKLOCKWRITE = ((s32)0x40000000),
    rpPTANKLOCKREAD = ((s32)0x80000000)
} RpPTankLockFlags;
typedef struct RpPTankLockStruct
{
    u8* data;
    s32 stride;
} RpPTankLockStruct;

typedef struct ParticleRenderColorBytes
{
    u8 red, green, blue, alpha;
} ParticleRenderColorBytes;
typedef union ParticleRenderColor
{
    u32 word;
    ParticleRenderColorBytes bytes;
} ParticleRenderColor;
typedef char ParticleRenderColorSize[(sizeof(ParticleRenderColor) == 4) ? 1 : -1];

typedef struct ParticleAnimationOutput
{
    f32 x, y, width, height;
    f32 angle;
    void* texture;
    f32 u0, v0, u1, v1;
    u16 type;
    u16 unknown2A;
    u32 color;
    f32 textureWidth, textureHeight;
} ParticleAnimationOutput;
typedef char ParticleAnimationOutputSize[(sizeof(ParticleAnimationOutput) == 56) ? 1 : -1];

/* VU0 boundary: VF10 contains the normalized animated particle color.
 * Packing produces the real four-byte scalar consumed by the color stream. */
static inline u32 particlePackAnimatedColor(void)
{
    u32 result;
    u32 work;
    work = 0x437F0000U;
    __asm__ volatile("qmtc2.ni %0, $vf2\n"
                     "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                     "vftoi0.xyzw $vf10, $vf10\n"
                     "qmfc2.ni %0, $vf10\n"
                     "ppach %0, $0, %0\n"
                     "ppacb %0, $0, %0\n"
                     "sw %0, result\n"
                     : "+r"(work), "=m"(result)
                     :
                     : "$vf2", "$vf10", "memory");
    return result;
}

/* The transformed pass keeps the color-byte scale in an FPR. */
static inline u32 particlePackAnimatedColorTransformed(f32 scale)
{
    u32 result;
    u32 work;
    __asm__ volatile("mfc1 %0, %2\n"
                     "nop\n"
                     "qmtc2.ni %0, $vf2\n"
                     "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                     "vftoi0.xyzw $vf10, $vf10\n"
                     "qmfc2.ni %0, $vf10\n"
                     "ppach %0, $0, %0\n"
                     "ppacb %0, $0, %0\n"
                     "sw %0, result\n"
                     : "=&r"(work), "=m"(result)
                     : "f"(scale)
                     : "$vf2", "$vf10", "memory");
    return result;
}

/* measured: native b210 -O2 emits3516 exact bytes and four alignment bytes.
 * Native lock records, color results, and phase-local matrix/angle/count
 * lifetimes preserve the full renderer and its eight-entry switch table.
 * Evidence: build/finish-first-party-20260922/particle-next-02/. */

// Projects the particle vertices through the VU0 matrix and writes the packed colour per vertex.
// FUN_00487FB0
/* Raw emitter/record accesses are intentional: typed SpawnParticle and
 * WaveSpawnEmitter fields changed this renderer's register/load ordering.
 * PTank buffers below are dynamically strided streams, not object fields. */
/* Raw instance accesses preserve retail aliasing and load order; the typed
 * EffParticleInstance rewrite changed this function's instruction stream. */
void ParticleProjectVertices(u8* particle, f32 scale)
{
    extern s32 func_003a5180(RpAtomic * atomic);
    extern s32 func_003a2770(RpAtomic * atomic, RpPTankLockStruct * lock, u32 dataFlags, RpPTankLockFlags access);
    extern RpAtomic *func_003a2920(RpAtomic *atomic);
    extern void mdlEffectWrapTrackFrames(s32 a, u32 b);
    extern void mdlEffectEvalSubPose(s32 a, f32* b);
    extern s32 func_00482790(u8 * *a, u32 b);
    extern void GeometryBlockSetPartState(u8 * a, s32 b);
    extern void GeometryBlockBindResource(u8 * a, s32 b);
    extern void mdlEffectSetChildColor(u8 * a, s32 b);
    extern void mdlEffectFlushChild(u8 * a);
    extern void mdlEffectApplyPackedColor(u8 * a, s32 b);
    extern void func_00485870(s32 a);
    extern s32 TnGetOffset1C(u16 a);
    extern void PrimAppendNode(u8 * list, u8 * node);
    extern f32 fGpffff8044;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff80a0;
    extern f32 fGpffff80a4;
    extern f32 fGpffff80a8;
    extern f32 fGpffff80ac;
    extern f32 fGpffff80b0;
    extern f32 fGpffff80b4;
    extern f32 fGpffff80b8;
    extern s32 iGpffffb610;
    extern u8 D_00713CD0[];
    ParticleRenderColor materialColor;
    u8 transformedPoint[16] __attribute__((aligned(16)));
    u8 translationSnapshot[16] __attribute__((aligned(16)));
    u8 rotationSnapshot[16] __attribute__((aligned(16)));
    u8 transformStorage[64] __attribute__((aligned(16)));
    f32 parentColor[4] __attribute__((aligned(16)));
    ParticleAnimationOutput animation;
    RpPTankLockStruct rotationLock;
    RpPTankLockStruct positionLock;
    RpPTankLockStruct sizeLock;
    RpPTankLockStruct colorLock;
    RpPTankLockStruct uvLock;
    u8* emitterOrObjects;
    u8* record;
    u8* atomicAddress;
    u8* settings;
    u8* animationSettings;
    s32 particleCount;
    s32 activeCount;
    f32 colorScale;
    f32 scaleX;
    f32 scaleY;
    s32 plainIndex;
    s32 transformedIndex;
    s32 animatedIndex;
    s32 animatedTransformedIndex;
    s32 effectIndex;
    s32 modelIndex;
    emitterOrObjects = *(u8**)(particle + 0x4C);
    {
        s32 inputColor = *(s32*)(particle + 4);
        const s32* word = &inputColor;
        colorScale = fGpffff8044;
        __asm__ volatile("lw $2, 0(%0)\n"
                         "pextlb $2, $0, $2\n"
                         "pextlh $2, $0, $2\n"
                         "qmtc2.ni $2, $vf10\n"
                         "vitof0.xyzw $vf10, $vf10\n"
                         "mfc1 $3, %1\n"
                         "nop\n"
                         "qmtc2.ni $3, $vf2\n"
                         "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                         :
                         : "r"(word), "f"(colorScale), "m"(inputColor)
                         : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%1)\n" : "=m"(parentColor) : "r"(parentColor) : "memory");
    }
    particleCount = *(s32*)(emitterOrObjects + 8);
    if (particleCount == 0)
    {
        goto particle_render_done;
    }
    if (*(s32*)(emitterOrObjects + 0x10) == 0)
    {
        goto particle_render_done;
    }
    record = *(u8**)(emitterOrObjects + 0x18);
    switch (*(u16*)(particle + 0xC))
    {
    case 1:
    case 4:
    {
        f32 upperAngle;
        f32 angleStep;
        f32 lowerAngle;
        activeCount = 0;
        scaleX = ((EffParticleInstance *)particle)->texScaleX * scale;
        scaleY = ((EffParticleInstance *)particle)->texScaleY * scale;
        atomicAddress = *(u8**)(*(u8**)(particle + 0x50) + 0x10);
        settings = *(u8**)(emitterOrObjects + 0x20);
        func_003a5180((RpAtomic*)atomicAddress);
        func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
        if ((*(u32*)(emitterOrObjects + 0xC) & 1) == 0)
        {
            plainIndex = 0;
            angleStep = fGpffff8080;
            upperAngle = fGpffff8084;
            lowerAngle = fGpffff80a0;
            while (plainIndex < particleCount)
            {
                if (*(s32*)(record + 0x10) >= 0)
                {
                    *(f32*)(positionLock.data + 0) = *(f32*)(record + 0);
                    *(f32*)(positionLock.data + 4) = *(f32*)(record + 4);
                    *(f32*)(positionLock.data + 8) = *(f32*)(record + 8);
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = *(s32*)(record + 0x14);
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = *(f32*)(record + 0x1C);
                        if (!(f <= upperAngle))
                        {
                            while (!(f <= upperAngle))
                            {
                                f -= angleStep;
                            }
                        }
                        else if (f < lowerAngle)
                        {
                            while (f < lowerAngle)
                            {
                                f += angleStep;
                            }
                        }
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = *(f32*)(record + 0x18);
                        *(f32*)(sizeLock.data + 0) = scaleX * s;
                        *(f32*)(sizeLock.data + 4) = scaleY * s;
                        sizeLock.data += sizeLock.stride;
                    }
                    activeCount++;
                }
                plainIndex++;
                record += 0x20;
            }
        }
        else
        {
            f32(*transformMatrix)[4];
            f32* transformedPosition;
            mdlEffectLoadQuadB((s32)emitterOrObjects, (u32*)rotationSnapshot);
            mdlEffectLoadQuadA((s32)emitterOrObjects, (u32*)translationSnapshot);
            __asm__ volatile("lqc2 $vf10, 0(%0)\n"
                             :
                             : "r"(rotationSnapshot), "m"(rotationSnapshot)
                             : "$vf10", "memory");
            effMiscBuildRotationVU();
            __asm__ volatile("lqc2 $vf31, 0(%0)\n"
                             :
                             : "r"(translationSnapshot), "m"(translationSnapshot)
                             : "$vf31", "memory");
            transformMatrix = (f32(*)[4])transformStorage;
            __asm__ volatile("sqc2 $vf28, 0(%1)\n"
                             "sqc2 $vf29, 16(%1)\n"
                             "sqc2 $vf30, 32(%1)\n"
                             "sqc2 $vf31, 48(%1)\n"
                             : "=m"(transformStorage)
                             : "r"(transformMatrix)
                             : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            transformedIndex = 0;
            upperAngle = fGpffff8084;
            angleStep = fGpffff80a4;
            lowerAngle = fGpffff80a8;
            transformedPosition = (f32*)transformedPoint;
            while (transformedIndex < particleCount)
            {
                if (*(s32*)(record + 0x10) >= 0)
                {
                    __asm__ volatile("lqc2 $vf28, 0(%0)\n"
                                     "lqc2 $vf29, 16(%0)\n"
                                     "lqc2 $vf30, 32(%0)\n"
                                     "lqc2 $vf31, 48(%0)\n"
                                     "lqc2 $vf10, 0(%1)\n"
                                     "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                     "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                     "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                                     "vmaddw.xyzw $vf10, $vf31, $vf0w\n"
                                     :
                                     : "r"(transformMatrix), "r"(record)
                                     : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%1)\n"
                                     : "=m"(transformedPoint)
                                     : "r"(transformedPosition)
                                     : "$vf10", "memory");
                    *(f32*)(positionLock.data + 0) = *(f32*)(transformedPoint + 0);
                    *(f32*)(positionLock.data + 4) = *(f32*)(transformedPoint + 4);
                    *(f32*)(positionLock.data + 8) = *(f32*)(transformedPoint + 8);
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = *(s32*)(record + 0x14);
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = *(f32*)(record + 0x1C);
                        if (!(f <= upperAngle))
                        {
                            while (!(f <= upperAngle))
                            {
                                f -= angleStep;
                            }
                        }
                        else if (f < lowerAngle)
                        {
                            while (f < lowerAngle)
                            {
                                f += angleStep;
                            }
                        }
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = *(f32*)(record + 0x18);
                        *(f32*)(sizeLock.data + 0) = scaleX * s;
                        *(f32*)(sizeLock.data + 4) = scaleY * s;
                        sizeLock.data += sizeLock.stride;
                    }
                    activeCount++;
                }
                transformedIndex++;
                record += 0x20;
            }
        }
        func_003a2920((RpAtomic *)atomicAddress);
        if (activeCount != 0)
        {
            u8* material;
            materialColor.word = *(u32*)(particle + 4);
            material = **(u8***)(*(u8**)(atomicAddress + 0x18) + 0x20);
            *(ParticleRenderColorBytes*)(material + 4) = materialColor.bytes;
            {
                *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 0x40) |= 0x800000;
                *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 4) = activeCount;
            }
            GeometryBlockSetPartState(*(u8**)(particle + 0x50), *(u16*)(settings + 0x54));
            GeometryBlockBindResource(*(u8**)(particle + 0x50), *(u16*)(settings + 0x54));
        }
        break;
    }
    case 2:
    {
        u8* animationResource = *(u8**)(particle + 0x44);
        if (animationResource == 0)
        {
            kAssertFail(D_00713CD0, 0x380);
        }
        /* Count only active particles in either animation path. This
         * initialized lifetime begins after the resource diagnostic and
         * ends after the active-count guard and PTank count store. */
        {
            s32 animatedActiveCount = 0;
            atomicAddress = *(u8**)(*(u8**)(particle + 0x50) + 0x10);
            animationSettings = *(u8**)(emitterOrObjects + 0x20);
            func_003a5180((RpAtomic*)atomicAddress);
            func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &uvLock, 0x80, 0x40000000);
            {
                s32 t = func_00482790((u8**)animationResource, 0);
                func_003c42b0(**(RpMaterial***)(*(u8**)(atomicAddress + 0x18) + 0x20), (RwTexture*)t);
            }
            if ((*(u32*)(emitterOrObjects + 0xC) & 1) == 0)
            {
                animatedIndex = 0;
                while (animatedIndex < particleCount)
                {
                    if (*(s32*)(record + 0x10) >= 0)
                    {
                        mdlEffectWrapTrackFrames((s32)animationResource, *(u32*)(record + 0x10));
                        mdlEffectEvalSubPose((s32)animationResource, (f32*)&animation);
                        *(f32*)(uvLock.data + 0) = animation.u0;
                        *(f32*)(uvLock.data + 4) = animation.v0;
                        *(f32*)(uvLock.data + 8) = animation.u1;
                        *(f32*)(uvLock.data + 12) = animation.v1;
                        uvLock.data += uvLock.stride;
                        *(f32*)(positionLock.data + 0) = *(f32*)(record + 0);
                        *(f32*)(positionLock.data + 4) = *(f32*)(record + 4);
                        *(f32*)(positionLock.data + 8) = *(f32*)(record + 8);
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = *(u32*)(record + 0x14);
                            u32 animationColor;
                            f32 colorScale = fGpffff8044;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf11\n"
                                             "vitof0.xyzw $vf11, $vf11\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                             :
                                             : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                             : "$2", "$vf2", "$vf11", "memory");
                            animationColor = animation.color;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf10\n"
                                             "vitof0.xyzw $vf10, $vf10\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                             :
                                             : "r"(&animationColor), "f"(colorScale), "m"(animationColor)
                                             : "$2", "$vf2", "$vf10", "memory");
                            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf11", "memory");
                            *(s32*)colorLock.data = (s32)particlePackAnimatedColor();
                            colorLock.data += colorLock.stride;
                        }
                        {
                            f32 f = *(f32*)(record + 0x1C) + animation.angle;
                            f32 upperAngle = fGpffff8084;
                            if (!(f <= upperAngle))
                            {
                                f32 angleStep = fGpffff80ac;
                                while (!(f <= upperAngle))
                                {
                                    f -= angleStep;
                                }
                            }
                            else
                            {
                                f32 lowerAngle = fGpffff80b0;
                                if (f < lowerAngle)
                                {
                                    f32 angleStep = fGpffff80b4;
                                    while (f < lowerAngle)
                                    {
                                        f += angleStep;
                                    }
                                }
                            }
                            *(f32*)rotationLock.data = f;
                            rotationLock.data += rotationLock.stride;
                        }
                        {
                            f32 s = *(f32*)(record + 0x18) * scale;
                            *(f32*)(sizeLock.data + 0) = animation.width * s;
                            *(f32*)(sizeLock.data + 4) = animation.height * s;
                            sizeLock.data += sizeLock.stride;
                        }
                        animatedActiveCount++;
                    }
                    animatedIndex++;
                    record += 0x20;
                }
            }
            else
            {
                f32 colorByteScale;
                f32 upperAngle;
                f32 angleStep;
                f32 lowerAngle;
                mdlEffectLoadQuadB((s32)emitterOrObjects, (u32*)rotationSnapshot);
                mdlEffectLoadQuadA((s32)emitterOrObjects, (u32*)translationSnapshot);
                __asm__ volatile("lqc2 $vf10, 0(%0)\n"
                                 :
                                 : "r"(rotationSnapshot), "m"(rotationSnapshot)
                                 : "$vf10", "memory");
                effMiscBuildRotationVU();
                __asm__ volatile("lqc2 $vf31, 0(%0)\n"
                                 :
                                 : "r"(translationSnapshot), "m"(translationSnapshot)
                                 : "$vf31", "memory");
                __asm__ volatile("sqc2 $vf28, 0(%1)\n"
                                 "sqc2 $vf29, 16(%1)\n"
                                 "sqc2 $vf30, 32(%1)\n"
                                 "sqc2 $vf31, 48(%1)\n"
                                 : "=m"(transformStorage)
                                 : "r"(transformStorage)
                                 : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
                animatedTransformedIndex = 0;
                colorByteScale = 255.0f;
                upperAngle = fGpffff8084;
                angleStep = fGpffff80b4;
                lowerAngle = fGpffff80b8;
                while (animatedTransformedIndex < particleCount)
                {
                    if (*(s32*)(record + 0x10) >= 0)
                    {
                        mdlEffectWrapTrackFrames((s32)animationResource, *(u32*)(record + 0x10));
                        mdlEffectEvalSubPose((s32)animationResource, (f32*)&animation);
                        __asm__ volatile("lqc2 $vf28, 0(%0)\n"
                                         "lqc2 $vf29, 16(%0)\n"
                                         "lqc2 $vf30, 32(%0)\n"
                                         "lqc2 $vf31, 48(%0)\n"
                                         "lqc2 $vf10, 0(%1)\n"
                                         "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                         "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                         "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                                         "vmaddw.xyzw $vf10, $vf31, $vf0w\n"
                                         :
                                         : "r"(transformStorage), "r"(record)
                                         : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                        __asm__ volatile("sqc2 $vf10, 0(%1)\n"
                                         : "=m"(transformedPoint)
                                         : "r"(transformedPoint)
                                         : "$vf10", "memory");
                        *(f32*)(uvLock.data + 0) = animation.u0;
                        *(f32*)(uvLock.data + 4) = animation.v0;
                        *(f32*)(uvLock.data + 8) = animation.u1;
                        *(f32*)(uvLock.data + 12) = animation.v1;
                        uvLock.data += uvLock.stride;
                        *(f32*)(positionLock.data + 0) = *(f32*)(transformedPoint + 0);
                        *(f32*)(positionLock.data + 4) = *(f32*)(transformedPoint + 4);
                        *(f32*)(positionLock.data + 8) = *(f32*)(transformedPoint + 8);
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = *(u32*)(record + 0x14);
                            u32 animationColor;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf11\n"
                                             "vitof0.xyzw $vf11, $vf11\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                             :
                                             : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                             : "$2", "$vf2", "$vf11", "memory");
                            animationColor = animation.color;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf10\n"
                                             "vitof0.xyzw $vf10, $vf10\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                             :
                                             : "r"(&animationColor), "f"(colorScale), "m"(animationColor)
                                             : "$2", "$vf2", "$vf10", "memory");
                            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf11", "memory");
                            *(s32*)colorLock.data = (s32)particlePackAnimatedColorTransformed(colorByteScale);
                            colorLock.data += colorLock.stride;
                        }
                        {
                            f32 f = *(f32*)(record + 0x1C) + animation.angle;
                            if (!(f <= upperAngle))
                            {
                                while (!(f <= upperAngle))
                                {
                                    f -= angleStep;
                                }
                            }
                            else if (f < lowerAngle)
                            {
                                while (f < lowerAngle)
                                {
                                    f += angleStep;
                                }
                            }
                            *(f32*)rotationLock.data = f;
                            rotationLock.data += rotationLock.stride;
                        }
                        {
                            f32 s = *(f32*)(record + 0x18) * scale;
                            *(f32*)(sizeLock.data + 0) = animation.width * s;
                            *(f32*)(sizeLock.data + 4) = animation.height * s;
                            sizeLock.data += sizeLock.stride;
                        }
                        animatedActiveCount++;
                    }
                    animatedTransformedIndex++;
                    record += 0x20;
                }
            }
            func_003a2920((RpAtomic *)atomicAddress);
            if (animatedActiveCount != 0)
            {
                u8* material;
                materialColor.word = *(u32*)(particle + 4);
                material = **(u8***)(*(u8**)(atomicAddress + 0x18) + 0x20);
                *(ParticleRenderColorBytes*)(material + 4) = materialColor.bytes;
                {
                    *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 0x40) |= 0x800000;
                    *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 4) = animatedActiveCount;
                }
                GeometryBlockSetPartState(*(u8**)(particle + 0x50), *(u16*)(animationSettings + 0x54));
                GeometryBlockBindResource(*(u8**)(particle + 0x50), *(u16*)(animationSettings + 0x54));
            }
        }
    }
    break;
    case 5:
    {
        emitterOrObjects = *(u8**)(particle + 0x34);
        if (emitterOrObjects == 0)
        {
            kAssertFail(D_00713CD0, 0x3F3);
        }
        effectIndex = 0;
        while (effectIndex < particleCount)
        {
            if (*(s32*)(record + 0x10) >= 0)
            {
                u32 particleColor = *(u32*)(record + 0x14);
                u32 packedColor;
                u32 colorWord;
                __asm__ volatile("lw $2, 0(%0)\n"
                                 "pextlb $2, $0, $2\n"
                                 "pextlh $2, $0, $2\n"
                                 "qmtc2.ni $2, $vf10\n"
                                 "vitof0.xyzw $vf10, $vf10\n"
                                 "mfc1 $2, %1\n"
                                 "nop\n"
                                 "qmtc2.ni $2, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 :
                                 : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                 : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile("lqc2 $vf11, 0(%0)\n"
                                 "vmul.xyzw $vf10, $vf10, $vf11\n"
                                 :
                                 : "r"(parentColor), "m"(parentColor)
                                 : "$vf10", "$vf11", "memory");
                colorWord = 0x437F0000U;
                __asm__ volatile("qmtc2.ni %0, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 "vftoi0.xyzw $vf10, $vf10\n"
                                 "qmfc2.ni %0, $vf10\n"
                                 "ppach %0, $0, %0\n"
                                 "ppacb %0, $0, %0\n"
                                 "sw %0, packedColor\n"
                                 : "+r"(colorWord), "=m"(packedColor)
                                 :
                                 : "$vf2", "$vf10", "memory");
                mdlEffectSetChildColor((u8*)*(s32*)emitterOrObjects, packedColor);
                mdlEffectFlushChild((u8*)*(s32*)emitterOrObjects);
            }
            effectIndex++;
            record += 0x20;
            emitterOrObjects += sizeof(s32);
        }
    }
    break;
    case 6:
    {
        emitterOrObjects = *(u8**)(particle + 0x3C);
        if (emitterOrObjects == 0)
        {
            kAssertFail(D_00713CD0, 0x406);
        }
        modelIndex = 0;
        while (modelIndex < particleCount)
        {
            if (*(s32*)(record + 0x10) >= 0)
            {
                u32 particleColor = *(u32*)(record + 0x14);
                u32 packedColor;
                u32 colorWord;
                __asm__ volatile("lw $2, 0(%0)\n"
                                 "pextlb $2, $0, $2\n"
                                 "pextlh $2, $0, $2\n"
                                 "qmtc2.ni $2, $vf10\n"
                                 "vitof0.xyzw $vf10, $vf10\n"
                                 "mfc1 $2, %1\n"
                                 "nop\n"
                                 "qmtc2.ni $2, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 :
                                 : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                 : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile("lqc2 $vf11, 0(%0)\n"
                                 "vmul.xyzw $vf10, $vf10, $vf11\n"
                                 :
                                 : "r"(parentColor), "m"(parentColor)
                                 : "$vf10", "$vf11", "memory");
                colorWord = 0x437F0000U;
                __asm__ volatile("qmtc2.ni %0, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 "vftoi0.xyzw $vf10, $vf10\n"
                                 "qmfc2.ni %0, $vf10\n"
                                 "ppach %0, $0, %0\n"
                                 "ppacb %0, $0, %0\n"
                                 "sw %0, packedColor\n"
                                 : "+r"(colorWord), "=m"(packedColor)
                                 :
                                 : "$vf2", "$vf10", "memory");
                mdlEffectApplyPackedColor((u8*)*(s32*)emitterOrObjects, packedColor);
                func_00485870(*(s32*)emitterOrObjects);
            }
            modelIndex++;
            record += 0x20;
            emitterOrObjects += sizeof(s32);
        }
    }
    break;
    case 7:
    {
        u8* t = *(u8**)(emitterOrObjects + 0x20);
        ((EffParticleInstance *)particle)->link->field_0x00 = 0;
        ((EffParticleInstance *)particle)->link->field_0x04 = 0;
        {
            u8* pb = (u8*)TnGetOffset1C(*(u16*)(t + 0x54));
            PrimAppendNode(pb, *(u8**)(particle + 0x5C));
        }
    }
    break;
    default:
        kAssertFail(D_00713CD0, 0x41D);
        break;
    }
particle_render_done:
    return;
}
typedef struct ParticleProjectedColorBytes {
    u8 red, green, blue, alpha;
} ParticleProjectedColorBytes;
typedef union ParticleProjectedColor {
    u32 word;
    ParticleProjectedColorBytes bytes;
} ParticleProjectedColor;
typedef char ParticleProjectedColorSize[(sizeof(ParticleProjectedColor) == 4) ? 1 : -1];

/* Shared first-party views of the native vector and immediate vertex ABI. */
typedef BtlShuffleVec3 ParticleProjectedVec3;
typedef BtlShuffleSkyVertex ParticleProjectedVertex;
typedef struct TLP TLP;
typedef struct TlpSel {
    f32 a, b, w, h;
    void *tex;
} TlpSel;
typedef char ParticleProjectedVec3Size[(sizeof(ParticleProjectedVec3) == 12) ? 1 : -1];
typedef char ParticleProjectedVertexSize[(sizeof(ParticleProjectedVertex) == 64) ? 1 : -1];
typedef char ParticleProjectedSelectionSize[(sizeof(TlpSel) == 20) ? 1 : -1];

static inline u32 particleProjectedFrameIndex(const u8 *record)
{
    return *(const u32 *)(record + 0x10);
}

/* measured: b210 -O2, full unmasked 4236/4240-byte proof and four zero tail bytes.
 * Native vertex/selection fields and VU outputs preserve the retail memory order.
 * The transformed path reads its unsigned frame index through the accessor before
 * loading the texture resource; both the reload and argument order are significant.
 * Receipt: build/first-party-continue-live/particle/resume-20260922-closure/. */
/* Camera +0x20 is the view matrix, +0x80/+0x84 the clipping planes; its
 * shared header conflicts with the RwMatrixTag already included by this unit. */
// Draws the particle billboards: builds each quad from the projected corners and submits them with the camera near and far planes.
// FUN_00488D70
/* Raw emitter/record accesses are intentional: typed SpawnParticle and
 * WaveSpawnEmitter fields changed this renderer's register/load ordering.
 * PTank buffers below are dynamically strided streams, not object fields. */
void ParticleDrawBillboards(u8 *particle)
{
    extern s32 kwlnGetCamera(void);
    extern void effMiscBuildRotationVU(void);
    extern void TlpSelectFrame(TLP *a, u32 b, TlpSel *c);
    extern BtlShuffleRenderStateSet D_00887300[];
    extern BtlShuffleRenderPrimitive D_00887310[];
    extern f32 cosf(f32);
    extern f32 sinf(f32);
    extern ParticleProjectedVec3 *func_003e42a0(ParticleProjectedVec3 *a, const ParticleProjectedVec3 *b, const BtlShuffleMatrix *c);
    extern void kAssertFail(void *a, s32 b);
    extern f32 fGpffff81f4;
    extern f32 D_008872F8[];
    extern f32 D_008872FC[];
    extern u8 D_00713CD0[];
    extern u8 D_00713D10[];
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    ParticleProjectedVec3 worldPosition;
    ParticleProjectedVec3 cameraPosition;
    f32 parent[4] __attribute__((aligned(16)));
    ParticleProjectedVertex vertices[4];
    u32 snapB[4] __attribute__((aligned(16)));
    u32 snapA[4] __attribute__((aligned(16)));
    u8 base[64] __attribute__((aligned(16)));
    TlpSel selection;
    u8 *emitter;
    u8 *record;
    s32 particleCount;
    s32 i;
    f32 bufferFar;
    f32 bufferNear;
    f32 cameraNear;
    f32 cameraFar;
    ParticleProjectedColor packed;
    s32 w;
    s32 sourceColor;
    s32 transformedColor;
    u32 packedColor;
    u32 transformedPackedColor;
    f32 colorScale;
    {
        w = ((EffParticleInstance *)particle)->packedColor.signedValue;
        __asm__ volatile(
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $2, %1\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            : : "r"(&w), "f"(colorScale = fGpffff81f4), "m"(w)
            : "$2", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%1)\n"
            : "=m"(parent) : "r"(parent) : "memory");
    }
    emitter = ((EffParticleInstance *)particle)->emitter.bytes;
    record = *(u8 **)(emitter + 0x18);
    bufferNear = D_008872FC[0];
    bufferFar = D_008872F8[0];
    cameraFar = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x84);
    cameraNear = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
    particleCount = *(s32 *)(emitter + 8);
    switch (((EffParticleInstance *)particle)->kind) {
    case 7:
    if ((*(s32 *)(emitter + 0xC) & 1) == 0) {
        f32 reciprocalDepth;
        f32 projectedDepth;
        f32 planeSpan;
        i = 0;
        planeSpan = cameraNear - cameraFar;
        bufferFar = bufferFar - bufferNear;
        while (i < particleCount) {
            if (*(s32 *)(record + 0x10) >= 0) {
                u32 work;
                sourceColor = *(s32 *)(record + 0x14);
                __asm__ volatile(
                    "lw $2, 0(%0)\n"
                    "pextlb $2, $0, $2\n"
                    "pextlh $2, $0, $2\n"
                    "qmtc2.ni $2, $vf10\n"
                    "vitof0.xyzw $vf10, $vf10\n"
                    "mfc1 $2, %1\n"
                    "nop\n"
                    "qmtc2.ni $2, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    : : "r"(&sourceColor), "f"(colorScale), "m"(sourceColor)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)\n"
                    "vmul.xyzw $vf10, $vf10, $vf11\n"
                    : : "r"(parent), "m"(parent)
                    : "$vf10", "$vf11", "memory");
                work = 0x437F0000U;
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    "vftoi0.xyzw $vf10, $vf10\n"
                    "qmfc2.ni %0, $vf10\n"
                    "ppach %0, $0, %0\n"
                    "ppacb %0, $0, %0\n"
                    "sw %0, packedColor\n"
                    : "+r"(work), "=m"(packedColor)
                    :
                    : "$vf2", "$vf10", "memory");
                packed.word = packedColor;
                if (packed.bytes.alpha != 0) {
                    f32 width;
                    f32 height;
                    TlpSelectFrame(*(TLP **)(particle + 0x48), (u32)*(s32 *)(record + 0x10), &selection);
                    D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)selection.tex);
                    width = *(f32 *)(record + 0x18) * ((selection.w / 32.0f) * selection.a);
                    height = *(f32 *)(record + 0x18) * ((selection.h / 32.0f) * selection.b);
                    vertices[0].u.els.color.r = (f32)(u32)packed.bytes.red;
                    vertices[0].u.els.color.g = (f32)(u32)packed.bytes.green;
                    vertices[0].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    vertices[0].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    vertices[1].u.els.color.r = (f32)(u32)packed.bytes.red;
                    vertices[1].u.els.color.g = (f32)(u32)packed.bytes.green;
                    vertices[1].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    vertices[1].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    vertices[2].u.els.color.r = (f32)(u32)packed.bytes.red;
                    vertices[2].u.els.color.g = (f32)(u32)packed.bytes.green;
                    vertices[2].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    vertices[2].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    vertices[3].u.els.color.r = (f32)(u32)packed.bytes.red;
                    vertices[3].u.els.color.g = (f32)(u32)packed.bytes.green;
                    vertices[3].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    vertices[3].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    worldPosition.x = *(f32 *)(record + 0);
                    worldPosition.y = *(f32 *)(record + 4);
                    worldPosition.z = *(f32 *)(record + 8);
                    func_003e42a0(&cameraPosition, &worldPosition, (const BtlShuffleMatrix *)((u8 *)(u32)kwlnGetCamera() + 0x20));
                    {
                        f32 ry = cameraPosition.y / cameraPosition.z;
                        f32 rx = cameraPosition.x / cameraPosition.z;
                        s32 bad;
                        if (rx < -2.0f || !(rx <= 2.0f) || ry < -2.0f || !(ry <= 2.0f)) {
                            bad = 1;
                        } else {
                            bad = 0;
                        }
                        if (bad == 0) {
                            f32 cosine;
                            f32 sine;
                            f32 widthCosine;
                            f32 heightCosine;
                            projectedDepth = (cameraNear / cameraPosition.z) * ((cameraPosition.z - cameraFar) * (bufferFar / planeSpan)) + (bufferNear + 0.0f);
                            if (projectedDepth < 0.0f) {
                                projectedDepth = 0.0f;
                            }
                            reciprocalDepth = 1.0f / projectedDepth;
                            cosine = cosf(*(f32 *)(record + 0x1C));
                            sine = sinf(*(f32 *)(record + 0x1C));
                            widthCosine = width * cosine;
                            heightCosine = height * cosine;
                            width = width * sine;
                            height = height * sine;
                            vertices[0].u.els.u = 0.0f; vertices[0].u.els.v = 0.0f;
                            vertices[1].u.els.u = 1.0f; vertices[1].u.els.v = 0.0f;
                            vertices[2].u.els.u = 0.0f; vertices[2].u.els.v = 1.0f;
                            vertices[3].u.els.u = 1.0f; vertices[3].u.els.v = 1.0f;
                            {
                                vertices[0].u.els.scrVertex.x = 640.0f * ((cameraPosition.x + (-widthCosine + height)) / cameraPosition.z);
                                vertices[0].u.els.scrVertex.y = 448.0f * ((cameraPosition.y - (-width - heightCosine)) / cameraPosition.z);
                                vertices[0].u.els.scrVertex.z = projectedDepth;
                                vertices[0].u.els.recipZ = reciprocalDepth;
                                vertices[1].u.els.scrVertex.x = 640.0f * ((cameraPosition.x + (widthCosine + height)) / cameraPosition.z);
                                vertices[1].u.els.scrVertex.y = 448.0f * ((cameraPosition.y - (width - heightCosine)) / cameraPosition.z);
                                vertices[1].u.els.scrVertex.z = projectedDepth;
                                vertices[1].u.els.recipZ = reciprocalDepth;
                                vertices[2].u.els.scrVertex.x = 640.0f * ((cameraPosition.x + (-widthCosine - height)) / cameraPosition.z);
                                vertices[2].u.els.scrVertex.y = 448.0f * ((cameraPosition.y - (-width + heightCosine)) / cameraPosition.z);
                                vertices[2].u.els.scrVertex.z = projectedDepth;
                                vertices[2].u.els.recipZ = reciprocalDepth;
                                vertices[3].u.els.scrVertex.x = 640.0f * ((cameraPosition.x + (widthCosine - height)) / cameraPosition.z);
                                vertices[3].u.els.scrVertex.y = 448.0f * ((cameraPosition.y - (width + heightCosine)) / cameraPosition.z);
                                vertices[3].u.els.scrVertex.z = projectedDepth;
                                vertices[3].u.els.recipZ = reciprocalDepth;
                            }
                            D_00887310[0](rwPRIMTYPETRISTRIP, vertices, 4);
                        }
                    }
                }
            }
            i++;
            record += 0x20;
        }
    } else {
        f32 full;
        f32 scale32;
        f32 neg2;
        f32 pos2;
        f32 zero;
        f32 one;
        f32 s640;
        f32 s448;
        mdlEffectLoadQuadB((s32)emitter, snapA);
        mdlEffectLoadQuadA((s32)emitter, snapB);
        __asm__ volatile("lqc2 $vf10, 0(%0)\n" : : "r"(snapA) : "$vf10", "memory");
        effMiscBuildRotationVU();
        __asm__ volatile("lqc2 $vf31, 0(%0)\n" : : "r"(snapB) : "$vf31", "memory");
        __asm__ volatile("sqc2 $vf28, 0(%0)\nsqc2 $vf29, 16(%0)\nsqc2 $vf30, 32(%0)\nsqc2 $vf31, 48(%0)\n" : : "r"(base) : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        i = 0;
        full = 255.0f;
        scale32 = 32.0f;
        neg2 = -2.0f;
        pos2 = 2.0f;
        zero = 0.0f;
        one = 1.0f;
        s640 = 640.0f;
        s448 = 448.0f;
        while (i < particleCount) {
            if (*(s32 *)(record + 0x10) >= 0) {
                __asm__ volatile("lqc2 $vf28, 0(%0)\nlqc2 $vf29, 16(%0)\nlqc2 $vf30, 32(%0)\nlqc2 $vf31, 48(%0)\nlqc2 $vf10, 0(%1)\nvmulax.xyzw $ACC, $vf28, $vf10x\nvmadday.xyzw $ACC, $vf29, $vf10y\nvmaddaz.xyzw $ACC, $vf30, $vf10z\nvmaddw.xyzw $vf10, $vf31, $vf0w\n" : : "r"(base), "r"(record) : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%1)\n" : "=m"(*(ParticleSnapshot *)D_00713D10) : "r"(D_00713D10) : "$vf10", "memory");
                worldPosition.x = *(f32 *)(D_00713D10 + 0);
                worldPosition.y = *(f32 *)(D_00713D10 + 4);
                worldPosition.z = *(f32 *)(D_00713D10 + 8);
                {
                    u32 work;
                    transformedColor = *(s32 *)(record + 0x14);
                    __asm__ volatile(
                        "lw $2, 0(%0)\n"
                        "pextlb $2, $0, $2\n"
                        "pextlh $2, $0, $2\n"
                        "qmtc2.ni $2, $vf10\n"
                        "vitof0.xyzw $vf10, $vf10\n"
                        "mfc1 $2, %1\n"
                        "nop\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        : : "r"(&transformedColor), "f"(colorScale), "m"(transformedColor)
                        : "$2", "$vf2", "$vf10", "memory");
                    __asm__ volatile(
                        "lqc2 $vf11, 0(%0)\n"
                        "vmul.xyzw $vf10, $vf10, $vf11\n"
                        : : "r"(parent), "m"(parent)
                        : "$vf10", "$vf11", "memory");
                    __asm__ volatile(
                        "mfc1 %0, %2\n"
                        "nop\n"
                        "qmtc2.ni %0, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni %0, $vf10\n"
                        "ppach %0, $0, %0\n"
                        "ppacb %0, $0, %0\n"
                        "sw %0, transformedPackedColor\n"
                        : "=&r"(work), "=m"(transformedPackedColor)
                        : "f"(full)
                        : "$vf2", "$vf10", "memory");
                    packed.word = transformedPackedColor;
                    if (packed.bytes.alpha != 0) {
                        f32 width;
                        f32 height;
                        u32 frameIndex;

                        frameIndex = particleProjectedFrameIndex(record);
                        TlpSelectFrame(*(TLP **)(particle + 0x48), frameIndex, &selection);
                        D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)selection.tex);
                        {
                            f32 particleScale = *(f32 *)(record + 0x18);
                            f32 dimension = selection.w / scale32;
                            dimension = dimension * selection.a;
                            width = particleScale * dimension;
                            dimension = selection.h / scale32;
                            dimension = dimension * selection.b;
                            height = particleScale * dimension;
                        }
                        vertices[0].u.els.color.r = (f32)(u32)packed.bytes.red;
                        vertices[0].u.els.color.g = (f32)(u32)packed.bytes.green;
                        vertices[0].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        vertices[0].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        vertices[1].u.els.color.r = (f32)(u32)packed.bytes.red;
                        vertices[1].u.els.color.g = (f32)(u32)packed.bytes.green;
                        vertices[1].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        vertices[1].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        vertices[2].u.els.color.r = (f32)(u32)packed.bytes.red;
                        vertices[2].u.els.color.g = (f32)(u32)packed.bytes.green;
                        vertices[2].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        vertices[2].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        vertices[3].u.els.color.r = (f32)(u32)packed.bytes.red;
                        vertices[3].u.els.color.g = (f32)(u32)packed.bytes.green;
                        vertices[3].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        vertices[3].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        func_003e42a0(&cameraPosition, &worldPosition, (const BtlShuffleMatrix *)((u8 *)(u32)kwlnGetCamera() + 0x20));
                        {
                            f32 ry2 = cameraPosition.y / cameraPosition.z;
                            f32 rx2 = cameraPosition.x / cameraPosition.z;
                            s32 bad2;
                            if (rx2 < neg2 || !(rx2 <= pos2) || ry2 < neg2 || !(ry2 <= pos2)) {
                                bad2 = 1;
                            } else {
                                bad2 = 0;
                            }
                            if (bad2 == 0) {
                                f32 projectedDepth;
                                f32 inv2;
                                f32 cosine;
                                f32 sine;
                                f32 widthCosine;
                                f32 heightCosine;
                                projectedDepth = (cameraNear / cameraPosition.z) * ((cameraPosition.z - cameraFar) * ((bufferFar - bufferNear) / (cameraNear - cameraFar))) + (bufferNear + 0.0f);
                                if (projectedDepth < zero) {
                                    projectedDepth = zero;
                                }
                                inv2 = one / projectedDepth;
                                cosine = cosf(*(f32 *)(record + 0x1C));
                                sine = sinf(*(f32 *)(record + 0x1C));
                                widthCosine = width * cosine;
                                heightCosine = height * cosine;
                                width = width * sine;
                                height = height * sine;
                                vertices[0].u.els.u = zero; vertices[0].u.els.v = zero;
                                vertices[1].u.els.u = one; vertices[1].u.els.v = zero;
                                vertices[2].u.els.u = zero; vertices[2].u.els.v = one;
                                vertices[3].u.els.u = one; vertices[3].u.els.v = one;
                                {
                                    vertices[0].u.els.scrVertex.x = s640 * ((cameraPosition.x + (-widthCosine + height)) / cameraPosition.z);
                                    vertices[0].u.els.scrVertex.y = s448 * ((cameraPosition.y - (-width - heightCosine)) / cameraPosition.z);
                                    vertices[0].u.els.scrVertex.z = projectedDepth;
                                    vertices[0].u.els.recipZ = inv2;
                                    vertices[1].u.els.scrVertex.x = s640 * ((cameraPosition.x + (widthCosine + height)) / cameraPosition.z);
                                    vertices[1].u.els.scrVertex.y = s448 * ((cameraPosition.y - (width - heightCosine)) / cameraPosition.z);
                                    vertices[1].u.els.scrVertex.z = projectedDepth;
                                    vertices[1].u.els.recipZ = inv2;
                                    vertices[2].u.els.scrVertex.x = s640 * ((cameraPosition.x + (-widthCosine - height)) / cameraPosition.z);
                                    vertices[2].u.els.scrVertex.y = s448 * ((cameraPosition.y - (-width + heightCosine)) / cameraPosition.z);
                                    vertices[2].u.els.scrVertex.z = projectedDepth;
                                    vertices[2].u.els.recipZ = inv2;
                                    vertices[3].u.els.scrVertex.x = s640 * ((cameraPosition.x + (widthCosine - height)) / cameraPosition.z);
                                    vertices[3].u.els.scrVertex.y = s448 * ((cameraPosition.y - (width + heightCosine)) / cameraPosition.z);
                                    vertices[3].u.els.scrVertex.z = projectedDepth;
                                    vertices[3].u.els.recipZ = inv2;
                                }
                                D_00887310[0](rwPRIMTYPETRISTRIP, vertices, 4);
                            }
                        }
                    }
                }
            }
            i++;
            record += 0x20;
        }
    }
    break;
    default:
        kAssertFail(D_00713CD0, 0x4F3);
        break;
    }
    D_00887300[0](rwRENDERSTATETEXTURERASTER, 0);
}
