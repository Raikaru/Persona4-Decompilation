/* Original translation unit effParticle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "particle_spawn_internal.h"
#include "effect_mesh_internal.h"
#include "rw_raster_internal.h"

typedef char ParticleInstanceExtent[sizeof(EffParticleInstance) == 0x60 ? 1 : -1];

typedef unsigned int ParticleSnapshot __attribute__((mode(TI)));

void GeometryBlockDestroy(s32 block);
s32 GeometryCreateAtomicFromResource(s32 resourceId, s32 flags);

void mdlEffectReleaseTrackInstance(s32 instance);
s32 mdlEffectCreateTrackInstance(s32 *source);
extern s32 mdlEffectShareTrackInstance(s32 source);

void TlpRelease(s32 work);
s32 TlpCreate(s32 *desc);
extern s32 TlpAddRef(s32 work);

extern void mdlEffectResetEmitterTicks(s32 instance);
extern void mdlEffectFreeEmitterAllocation(u8 *instance);
extern u8 *mdlEffectAllocateTrackPath(u16 kind, u32 primaryCount, void *parameters);
extern s32 TnSlotObject(s32 slotIndex);
typedef struct RpMaterial RpMaterial;
typedef struct RwTexture RwTexture;

extern RpMaterial *func_003c42b0(RpMaterial *material, RwTexture *texture);
extern void *TnUploadStreamTagged(void *stream);
extern void func_003ef3a0(void *object);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memset(void *dst, s32 value, u32 size);
extern void kAssertFail(void *file, s32 line);
extern u8 D_00713CC0[];
extern u8 D_00713CD0[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *mdlEffectCreatePrimitiveRecord(u8 *source);
extern void mdlEffectDestroyPrimitiveRecord(u8 *recordData);
extern u8 *mdlEffectCreateChildRecord(u8 *record);
extern void mdlEffectDestroyWithNodes(void *effect);
extern u8 *GeometryCloneBlock(void *source);
void ParticleAllocRecords(u8 *particle, s32 source, void *options);
void ParticleCopyModeFromSource(u8 *particle, u8 *source);
void ParticleSetMaterialSlot(u8 *particle, s32 source, s32 options);
void ParticleSetTextureFromHandle(u8 *particle, s32 source);
void ParticleSetLinkedGroup(u8 *particle, s32 *source);
void ParticleSetTextureById(u8 *particle, s32 source);
void ParticleRebuildSubtypeChain(u8 *particle, void *source);
void ParticleRebuildSubtypeChainAlt(u8 *particle, void *source);
void ParticleSetAuxResource(u8 *particle, s32 *source);
extern void mdlEffectStartChild(u8 *record);
extern void mdlEffectScaleChild(u8 *record, f32 scale);
extern void mdlEffectUpdateChildData(u8 *record, void *data);
extern void mdlEffectCommitChild(u8 *record);
extern void mdlEffectStartChildren(u8 *effect);
extern void mdlEffectSetChildScales(u8 *effect, f32 value);
extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
extern void mdlEffectCommitTreeFrame(u8 *effect);
extern ParticleSnapshot mdlEffectLoadQuadB(s32 instance, u32 *quadData);
extern ParticleSnapshot mdlEffectLoadQuadA(s32 instance, u32 *quadData);
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
/* Access-site trials isolated the remaining raw descriptor/handle accesses below. */
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
        ParticleAllocRecords(particle, ((EffSourceDescriptor *)source)->id, settings);
        if (((EffParticleInstance *)particle)->recordCount.value == 0) {
            return particle;
        }
        resource = (s32 *)mdlEffectResolveRelPtrB(source);
        if (resource != NULL) {
            switch (((EffSourceDescriptor *)source)->kind) {
            case 1:
                /* measured: this access-site member conversion makes the owning function MISMATCH. */
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 1);
                ParticleSetTextureFromHandle(particle, (s32)resource);
                break;
            case 2:
                /* measured: this access-site member conversion makes the owning function MISMATCH. */
                ParticleSetMaterialSlot(particle, *(s32 *)(((EffParticleInstance *)particle)->emitter.bytes + 8), 2);
                ParticleSetLinkedGroup(particle, resource);
                break;
            case 4:
                /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
                /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            ((EffParticleInstance *)particle)->kind = *(u16 *)(source + 0x1C);
        }
        return particle;
    }
}

// Frees a particle block: its records and sub-objects, then the block itself.
// FUN_00486E10
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleFree(u8 *particle)
{
    u32 count;
    u32 i;

    if (((EffParticleInstance *)particle)->childAllocation.handle != 0) {
        if (((EffParticleInstance *)particle)->emitter.handle != 0) {
            count = (s32)((WaveSpawnEmitter *)((EffParticleInstance *)particle)->emitter.handle)->totalCount;
        } else {
            count = ((EffParticleInstance *)particle)->recordCount.signedValue;
        }
        for (i = 0; i < count; i++) {
            mdlEffectDestroyPrimitiveRecord(((u8 **)((EffParticleInstance *)particle)->children.bytes)[i]);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        jtbl_008873EC[0](*(void **)(particle + 0x38));
    }
    if (((EffParticleInstance *)particle)->modelAllocation.handle != 0) {
        if (((EffParticleInstance *)particle)->emitter.handle != 0) {
            count = (s32)((WaveSpawnEmitter *)((EffParticleInstance *)particle)->emitter.handle)->totalCount;
        } else {
            count = ((EffParticleInstance *)particle)->recordCount.signedValue;
        }
        for (i = 0; i < count; i++) {
            mdlEffectDestroyWithNodes(((u8 **)((EffParticleInstance *)particle)->models.bytes)[i]);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        jtbl_008873EC[0](*(void **)(particle + 0x40));
    }
    if (((EffParticleInstance *)particle)->animation.handle != 0) {
        mdlEffectReleaseTrackInstance(((EffParticleInstance *)particle)->animation.handle);
    }
    if (((EffParticleInstance *)particle)->tlpRef != 0) {
        TlpRelease(((EffParticleInstance *)particle)->tlpRef);
    }
    if (((EffParticleInstance *)particle)->flags & 1) {
        mdlEffectFreeEmitterAllocation((u8 *)((EffParticleInstance *)particle)->emitter.handle);
    }
    if (((EffParticleInstance *)particle)->geometry.handle != 0) {
        GeometryBlockDestroy(((EffParticleInstance *)particle)->geometry.handle);
    }
    if (((EffParticleInstance *)particle)->link != NULL) {
        jtbl_008873EC[0](((EffParticleInstance *)particle)->link);
    }
    jtbl_008873EC[0](particle);
}
// Creates a particle block from a parent particle block, copying its records and mode.
// FUN_00486FB0
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void *ParticleCreateFromParent(void *opaqueSource)
{
    u8 *particle = opaqueSource;
    u32 recordCapacity;
    u8 *parameters;
    u8 *createdParticle;
    u32 emissionCount;

    if (((EffParticleInstance *)particle)->emitter.handle == 0) {
        kAssertFail(D_00713CD0, 0xE0);
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    parameters = (u8*)((WaveSpawnEmitter *)*(u8 **)(particle + 0x4C))->originalParameters;
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
    ((EffParticleInstance *)createdParticle)->recordCount.value = recordCapacity;
    ((EffParticleInstance *)createdParticle)->packedColor.signedValue = -1;
    ((EffParticleInstance *)createdParticle)->scale.signedBits = 0x3F800000;
    if (createdParticle == NULL) {
        kAssertFail(D_00713CD0, 0xE4);
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    ParticleAllocRecords(createdParticle, ((WaveSpawnEmitter *)*(u8 **)(particle + 0x4C))->kind, (void *)parameters);
    if (((EffParticleInstance *)createdParticle)->recordCount.signedValue == 0) {
        return createdParticle;
    }
    if (((EffParticleInstance *)particle)->geometry.handle != 0) {
        ((EffParticleInstance *)createdParticle)->geometry.handle = (s32)GeometryCloneBlock((void *)((EffParticleInstance *)particle)->geometry.handle);
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
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleCopyModeFromSource(u8 *particle, u8 *source)
{
    switch (((EffParticleInstance *)source)->kind) {
    case 1:
    case 4:
        ((EffParticleInstance *)particle)->texScaleX = ((EffParticleInstance *)source)->texScaleX;
        ((EffParticleInstance *)particle)->texScaleY = ((EffParticleInstance *)source)->texScaleY;
        break;
    case 2:
        if (((EffParticleInstance *)source)->animation.handle == 0) {
            kAssertFail(D_00713CD0, 0x10D);
        }
        if (((EffParticleInstance *)source)->emitter.handle == 0) {
            kAssertFail(D_00713CD0, 0x10E);
        }
        if (((EffParticleInstance *)particle)->animation.handle != 0) {
            mdlEffectReleaseTrackInstance(((EffParticleInstance *)particle)->animation.handle);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(s32 *)(particle + 0x44) = mdlEffectShareTrackInstance(*(s32 *)(source + 0x44));
        break;
    case 5: {
        u32 count5;
        u32 i5;

        count5 = ((WaveSpawnEmitter *)((EffParticleInstance *)source)->emitter.bytes)->totalCount;
        if (count5 == 0) {
            return;
        }
        if (((EffParticleInstance *)source)->childAllocation.handle == 0) {
            kAssertFail(D_00713CD0, 0x119);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(s32 *)(source + 0x4C) == 0) {
            kAssertFail(D_00713CD0, 0x11A);
        }
        if (((EffParticleInstance *)particle)->childAllocation.handle != 0) {
            for (i5 = 0; i5 < count5; i5++) {
                mdlEffectDestroyPrimitiveRecord(((u8 **)((EffParticleInstance *)particle)->children.bytes)[i5]);
            }
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            jtbl_008873EC[0](*(void **)(particle + 0x38));
            ((EffParticleInstance *)particle)->children.bytes = NULL;
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            *(u8 **)(particle + 0x38) = NULL;
        }
        if (count5 * 4 == 0) {
            return;
        }
        chkmemAllocSiteTag(D_00713CD0, 0x12C);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x38) = (u8 *)(*jtbl_008873E8)(count5 * 4, 0x40000);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(u8 **)(particle + 0x38) == NULL) {
            kAssertFail(D_00713CD0, 0x12D);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x34) = *(u8 **)(particle + 0x38);
        for (i5 = 0; i5 < count5; i5++) {
            ((u8 **)((EffParticleInstance *)particle)->children.bytes)[i5] =
                mdlEffectCreateChildRecord(((u8 **)((EffParticleInstance *)source)->children.bytes)[0]);
        }
        break;
    }
    case 6: {
        u32 count6;
        u32 i6;

        count6 = ((WaveSpawnEmitter *)((EffParticleInstance *)source)->emitter.bytes)->totalCount;
        if (count6 == 0) {
            return;
        }
        if (((EffParticleInstance *)source)->modelAllocation.handle == 0) {
            kAssertFail(D_00713CD0, 0x139);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(s32 *)(source + 0x4C) == 0) {
            kAssertFail(D_00713CD0, 0x13A);
        }
        if (((EffParticleInstance *)particle)->modelAllocation.handle != 0) {
            for (i6 = 0; i6 < count6; i6++) {
                mdlEffectDestroyWithNodes(((u8 **)((EffParticleInstance *)particle)->models.bytes)[i6]);
            }
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            jtbl_008873EC[0](*(void **)(particle + 0x40));
            ((EffParticleInstance *)particle)->models.bytes = NULL;
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            *(u8 **)(particle + 0x40) = NULL;
        }
        if (count6 * 4 == 0) {
            return;
        }
        chkmemAllocSiteTag(D_00713CD0, 0x14C);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x40) = (u8 *)(*jtbl_008873E8)(count6 * 4, 0x40000);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(u8 **)(particle + 0x40) == NULL) {
            kAssertFail(D_00713CD0, 0x14D);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x3C) = *(u8 **)(particle + 0x40);
        for (i6 = 0; i6 < count6; i6++) {
            ((u8 **)((EffParticleInstance *)particle)->models.bytes)[i6] =
                mdlEffectCloneWithNodes(((u8 **)((EffParticleInstance *)source)->models.bytes)[0]);
        }
        break;
    }
    case 7: {
        u8 *p;

        /* The source handle reads and the store stay as raw offsets: typed forms changed the codegen (measured). */
        if (((EffParticleInstance *)source)->tlpRef == 0) {
            kAssertFail(D_00713CD0, 0x156);
        }
        if (((EffParticleInstance *)particle)->tlpRef != 0) {
            TlpRelease(((EffParticleInstance *)particle)->tlpRef);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    ((EffParticleInstance *)particle)->kind = *(u16 *)(source + 0xC);
}

// Allocates the particle record block (count times the record size) and marks the block dirty.
// FUN_004875D0
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleAllocRecords(u8 *particle, s32 source, void *options)
{
    if (((EffParticleInstance *)particle)->emitter.bits != 0) {
        mdlEffectFreeEmitterAllocation((u8 *)((EffParticleInstance *)particle)->emitter.bits);
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(u32 *)(particle + 0x4C) = (u32)mdlEffectAllocateTrackPath(source & 0xFFFF, ((EffParticleInstance *)particle)->recordCount.value, options);
    ((EffParticleInstance *)particle)->flags |= 1;
}




// Sets the material slot from the type: types 1 and 4 take a material by id, type 2 takes the second material id, type 7 leaves it.
// FUN_00487650
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleSetMaterialSlot(u8 *particle, s32 source, s32 options)
{
    s32 previousHandle = ((EffParticleInstance *)particle)->geometry.handle;

    if (previousHandle != 0) {
        GeometryBlockDestroy(previousHandle);
    }
    switch (options) {
    case 1:
    case 4:
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(s32 *)(particle + 0x50) = GeometryCreateAtomicFromResource(source & 0xFFFF, 0x20080027);
        return;
    case 2:
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(s32 *)(particle + 0x50) = GeometryCreateAtomicFromResource(source & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}

/* Native raster dimensions and geometry/atomic/material layouts are shared with the SDK helpers. */
// Sets the texture scale from the texture table entry by id and applies the texture to the material.
// FUN_00487710
void ParticleSetTextureById(u8 *particle, s32 source)
{
    void *texture = (void *)TnSlotObject(source & 0xFFFF);
    u8 *raster = *(u8 **)texture;
    f32 rasterHeight = (f32)((RwRaster *)raster)->height;
    f32 rasterWidth = (f32)((RwRaster *)raster)->width;

    ((EffParticleInstance *)particle)->texScaleX = rasterWidth / 2.0f / 16.0f;
    ((EffParticleInstance *)particle)->texScaleY = rasterHeight / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)((RpAtomic *)((EffGeometryBlock *)((EffParticleInstance *)particle)->geometry.bytes)->atomic)->geometry->materials[0], (RwTexture *)texture);
}
/* Uses the same native raster/material chain as the ID setter. */
// Sets the texture scale from a texture handle, applies the texture to the material, then releases the handle.
// FUN_004877B0
void ParticleSetTextureFromHandle(u8 *particle, s32 source)
{
    void *texture = TnUploadStreamTagged((void *)source);
    u8 *raster = *(u8 **)texture;
    f32 rasterHeight = (f32)((RwRaster *)raster)->height;
    f32 rasterWidth = (f32)((RwRaster *)raster)->width;

    ((EffParticleInstance *)particle)->texScaleX = rasterWidth / 2.0f / 16.0f;
    ((EffParticleInstance *)particle)->texScaleY = rasterHeight / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)((RpAtomic *)((EffGeometryBlock *)((EffParticleInstance *)particle)->geometry.bytes)->atomic)->geometry->materials[0], (RwTexture *)texture);
    func_003ef3a0(texture);
}




// Replaces the linked group handle with the one returned for the given list.
// FUN_00487860
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleSetLinkedGroup(u8 *particle, s32 *source)
{
    s32 previousHandle = ((EffParticleInstance *)particle)->animation.handle;

    if (previousHandle != 0) {
        mdlEffectReleaseTrackInstance(previousHandle);
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(s32 *)(particle + 0x44) = mdlEffectCreateTrackInstance(source);
}

// Rebuilds the subtype chain: releases the old chain, then builds count entries from the resource (entry 0 from the resource, the rest linked).
// FUN_004878C0
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleRebuildSubtypeChain(u8 *particle, void *source)
{
    u32 count;
    u32 i;

    if (((EffParticleInstance *)particle)->emitter.handle != 0) {
        count = (s32)((WaveSpawnEmitter *)((EffParticleInstance *)particle)->emitter.handle)->totalCount;
    } else {
        count = ((EffParticleInstance *)particle)->recordCount.signedValue;
    }
    if (((EffParticleInstance *)particle)->childAllocation.handle != 0) {
        for (i = 0; i < count; i++) {
            mdlEffectDestroyPrimitiveRecord(((u8 **)((EffParticleInstance *)particle)->children.bytes)[i]);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        jtbl_008873EC[0](*(void **)(particle + 0x38));
        ((EffParticleInstance *)particle)->children.bytes = NULL;
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x38) = NULL;
    }
    if (count * 4 != 0) {
        chkmemAllocSiteTag(D_00713CD0, 0x21C);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x38) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(u8 **)(particle + 0x38) == NULL) {
            kAssertFail(D_00713CD0, 0x21D);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x34) = *(u8 **)(particle + 0x38);
        ((u8 **)((EffParticleInstance *)particle)->children.bytes)[0] = mdlEffectCreatePrimitiveRecord((u8 *)source);
        for (i = 1; i < count; i++) {
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            ((u8 **)*(u8 **)(particle + 0x34))[i] = mdlEffectCreateChildRecord(((u8 **)*(u8 **)(particle + 0x34))[0]);
        }
    }
}
// Rebuilds the alternate subtype chain: releases the old chain, then builds count entries linked from the resource; same shape as ParticleRebuildSubtypeChain.
// FUN_00487A30
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleRebuildSubtypeChainAlt(u8 *particle, void *source)
{
    u32 count;
    u32 i;

    if (((EffParticleInstance *)particle)->emitter.handle != 0) {
        count = (s32)((WaveSpawnEmitter *)((EffParticleInstance *)particle)->emitter.handle)->totalCount;
    } else {
        count = ((EffParticleInstance *)particle)->recordCount.signedValue;
    }
    if (((EffParticleInstance *)particle)->modelAllocation.handle != 0) {
        for (i = 0; i < count; i++) {
            mdlEffectDestroyWithNodes(((u8 **)((EffParticleInstance *)particle)->models.bytes)[i]);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        jtbl_008873EC[0](*(void **)(particle + 0x40));
        ((EffParticleInstance *)particle)->models.bytes = NULL;
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x40) = NULL;
    }
    if (count * 4 != 0) {
        chkmemAllocSiteTag(D_00713CD0, 0x24F);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x40) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        if (*(u8 **)(particle + 0x40) == NULL) {
            kAssertFail(D_00713CD0, 0x250);
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u8 **)(particle + 0x3C) = *(u8 **)(particle + 0x40);
        ((u8 **)((EffParticleInstance *)particle)->models.bytes)[0] = mdlEffectBuildFromResource((u8 *)source);
        for (i = 1; i < count; i++) {
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
            ((u8 **)*(u8 **)(particle + 0x3C))[i] = mdlEffectCloneWithNodes(((u8 **)*(u8 **)(particle + 0x3C))[0]);
        }
    }
}




// Replaces the auxiliary resource handle with the one returned for the given list.
// FUN_00487BA0
/* Access-site trials isolated the remaining raw descriptor/handle accesses below. */
void ParticleSetAuxResource(u8 *particle, s32 *source)
{
    s32 previousHandle = ((EffParticleInstance *)particle)->tlpRef;

    if (previousHandle != 0) {
        TlpRelease(previousHandle);
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
                            mdlEffectCommitTreeFrame(*objects);
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
                        mdlEffectCommitTreeFrame(*objects);
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
/* Native two-real stream element (rw/plcore/batypes.h). */
typedef struct RwV2d { f32 x, y; } RwV2d;

/* Per-atomic PTank plugin prefix reached through the registered plugin offset. */
typedef struct ParticleTankState {
    u8 pad0[4];
    s32 activeCount;
    u8 pad8[0x38];
    s32 flags;
} ParticleTankState;

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
/* Emitter/record members and PTank stream elements are typed at their access sites;
 * only individually measured culprits retain raw object accesses. */
/* Remaining raw instance sites were isolated by individual owning-file trials. */
void ParticleProjectVertices(u8* particle, f32 scale)
{
    extern s32 func_003a5180(RpAtomic * atomic);
    extern s32 func_003a2770(RpAtomic * atomic, RpPTankLockStruct * lock, u32 dataFlags, RpPTankLockFlags access);
    extern RpAtomic *func_003a2920(RpAtomic *atomic);
    extern void mdlEffectWrapTrackFrames(s32 instance, u32 frame);
    extern void mdlEffectEvalSubPose(s32 instance, f32* output);
    extern s32 mdlEffectGetStreamHandle(u8 * *owner, u32 streamIndex);
    extern void GeometryBlockSetPartState(u8 * block, s32 state);
    extern void GeometryBlockBindResource(u8 * block, s32 resourceId);
    extern void mdlEffectSetChildColor(u8 * record, s32 packedColor);
    extern void mdlEffectFlushChild(u8 * record);
    extern void mdlEffectApplyPackedColor(u8 * effect, s32 value);
    extern void mdlEffectFlushTreeFrame(s32 effect);
    extern s32 TnGetOffset1C(u16 slotIndex);
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
    emitterOrObjects = ((EffParticleInstance *)particle)->emitter.bytes;
    {
        s32 inputColor = ((EffParticleInstance *)particle)->packedColor.signedValue;
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
    particleCount = (s32)((WaveSpawnEmitter *)emitterOrObjects)->totalCount;
    if (particleCount == 0)
    {
        goto particle_render_done;
    }
    if (((WaveSpawnEmitter *)emitterOrObjects)->ticks == 0)
    {
        goto particle_render_done;
    }
    record = (u8*)((WaveSpawnEmitter *)emitterOrObjects)->particles;
    switch (((EffParticleInstance *)particle)->kind)
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
        atomicAddress = ((EffGeometryBlock *)((EffParticleInstance *)particle)->geometry.bytes)->atomic;
        settings = (u8*)((WaveSpawnEmitter *)emitterOrObjects)->parameters;
        func_003a5180((RpAtomic*)atomicAddress);
        func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
        if ((((WaveSpawnEmitter *)emitterOrObjects)->flags & 1) == 0)
        {
            plainIndex = 0;
            angleStep = fGpffff8080;
            upperAngle = fGpffff8084;
            lowerAngle = fGpffff80a0;
            while (plainIndex < particleCount)
            {
                if (((SpawnParticle *)record)->age >= 0)
                {
                    ((BtlShuffleVec3 *)positionLock.data)->x = ((SpawnParticle *)record)->position.lane[0];
                    ((BtlShuffleVec3 *)positionLock.data)->y = ((SpawnParticle *)record)->position.lane[1];
                    ((BtlShuffleVec3 *)positionLock.data)->z = ((SpawnParticle *)record)->position.lane[2];
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = (s32)((SpawnParticle *)record)->color;
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = ((SpawnParticle *)record)->angle;
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
                        /* measured: this access-site member conversion makes the owning function MISMATCH. */
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = ((SpawnParticle *)record)->size;
                        ((RwV2d *)sizeLock.data)->x = scaleX * s;
                        ((RwV2d *)sizeLock.data)->y = scaleY * s;
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
                if (((SpawnParticle *)record)->age >= 0)
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
                    ((BtlShuffleVec3 *)positionLock.data)->x = ((EffectVuVector *)transformedPoint)->lane[0];
                    ((BtlShuffleVec3 *)positionLock.data)->y = ((EffectVuVector *)transformedPoint)->lane[1];
                    ((BtlShuffleVec3 *)positionLock.data)->z = ((EffectVuVector *)transformedPoint)->lane[2];
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = (s32)((SpawnParticle *)record)->color;
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = ((SpawnParticle *)record)->angle;
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
                        /* measured: this access-site member conversion makes the owning function MISMATCH. */
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = ((SpawnParticle *)record)->size;
                        ((RwV2d *)sizeLock.data)->x = scaleX * s;
                        ((RwV2d *)sizeLock.data)->y = scaleY * s;
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
            materialColor.word = ((EffParticleInstance *)particle)->packedColor.value;
            material = *((RpGeometry *)(u8*)((RpAtomic *)atomicAddress)->geometry)->materials;
            ((RpMaterial *)material)->color = *(EffMeshColor *)&materialColor.bytes;
            {
                /* Runtime PTank plugin-offset slot, not a fixed RpAtomic member. */
                ((ParticleTankState *)*(u8**)(atomicAddress + iGpffffb610))->flags |= 0x800000;
                /* Runtime PTank plugin-offset slot, not a fixed RpAtomic member. */
                ((ParticleTankState *)*(u8**)(atomicAddress + iGpffffb610))->activeCount = activeCount;
            }
            /* Packed halfword in the shared emitter parameter word span (unknown2c). */
            GeometryBlockSetPartState(((EffParticleInstance *)particle)->geometry.bytes, *(u16*)(settings + 0x54));
            /* Packed halfword in the shared emitter parameter word span (unknown2c). */
            GeometryBlockBindResource(*(u8**)(particle + 0x50), *(u16*)(settings + 0x54));
        }
        break;
    }
    case 2:
    {
        u8* animationResource = ((EffParticleInstance *)particle)->animation.bytes;
        if (animationResource == 0)
        {
            kAssertFail(D_00713CD0, 0x380);
        }
        /* Count only active particles in either animation path. This
         * initialized lifetime begins after the resource diagnostic and
         * ends after the active-count guard and PTank count store. */
        {
            s32 animatedActiveCount = 0;
            atomicAddress = ((EffGeometryBlock *)((EffParticleInstance *)particle)->geometry.bytes)->atomic;
            animationSettings = (u8*)((WaveSpawnEmitter *)emitterOrObjects)->parameters;
            func_003a5180((RpAtomic*)atomicAddress);
            func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &uvLock, 0x80, 0x40000000);
            {
                s32 t = mdlEffectGetStreamHandle((u8**)animationResource, 0);
                func_003c42b0((RpMaterial *)((RpAtomic *)atomicAddress)->geometry->materials[0], (RwTexture*)t);
            }
            if ((((WaveSpawnEmitter *)emitterOrObjects)->flags & 1) == 0)
            {
                animatedIndex = 0;
                while (animatedIndex < particleCount)
                {
                    if (((SpawnParticle *)record)->age >= 0)
                    {
                        mdlEffectWrapTrackFrames((s32)animationResource, (u32)((SpawnParticle *)record)->age);
                        mdlEffectEvalSubPose((s32)animationResource, (f32*)&animation);
                        ((RwV2d *)uvLock.data)[0].x = animation.u0;
                        ((RwV2d *)uvLock.data)[0].y = animation.v0;
                        ((RwV2d *)uvLock.data)[1].x = animation.u1;
                        ((RwV2d *)uvLock.data)[1].y = animation.v1;
                        uvLock.data += uvLock.stride;
                        ((BtlShuffleVec3 *)positionLock.data)->x = ((SpawnParticle *)record)->position.lane[0];
                        ((BtlShuffleVec3 *)positionLock.data)->y = ((SpawnParticle *)record)->position.lane[1];
                        ((BtlShuffleVec3 *)positionLock.data)->z = ((SpawnParticle *)record)->position.lane[2];
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = ((SpawnParticle *)record)->color;
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
                            f32 f = ((SpawnParticle *)record)->angle + animation.angle;
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
                            f32 s = ((SpawnParticle *)record)->size * scale;
                            ((RwV2d *)sizeLock.data)->x = animation.width * s;
                            ((RwV2d *)sizeLock.data)->y = animation.height * s;
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
                    if (((SpawnParticle *)record)->age >= 0)
                    {
                        mdlEffectWrapTrackFrames((s32)animationResource, (u32)((SpawnParticle *)record)->age);
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
                        ((RwV2d *)uvLock.data)[0].x = animation.u0;
                        ((RwV2d *)uvLock.data)[0].y = animation.v0;
                        ((RwV2d *)uvLock.data)[1].x = animation.u1;
                        ((RwV2d *)uvLock.data)[1].y = animation.v1;
                        uvLock.data += uvLock.stride;
                        ((BtlShuffleVec3 *)positionLock.data)->x = ((EffectVuVector *)transformedPoint)->lane[0];
                        ((BtlShuffleVec3 *)positionLock.data)->y = ((EffectVuVector *)transformedPoint)->lane[1];
                        ((BtlShuffleVec3 *)positionLock.data)->z = ((EffectVuVector *)transformedPoint)->lane[2];
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = ((SpawnParticle *)record)->color;
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
                            f32 f = ((SpawnParticle *)record)->angle + animation.angle;
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
                            f32 s = ((SpawnParticle *)record)->size * scale;
                            ((RwV2d *)sizeLock.data)->x = animation.width * s;
                            ((RwV2d *)sizeLock.data)->y = animation.height * s;
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
                materialColor.word = ((EffParticleInstance *)particle)->packedColor.value;
                material = *((RpGeometry *)(u8*)((RpAtomic *)atomicAddress)->geometry)->materials;
                ((RpMaterial *)material)->color = *(EffMeshColor *)&materialColor.bytes;
                {
                    /* Runtime PTank plugin-offset slot, not a fixed RpAtomic member. */
                    ((ParticleTankState *)*(u8**)(atomicAddress + iGpffffb610))->flags |= 0x800000;
                    /* Runtime PTank plugin-offset slot, not a fixed RpAtomic member. */
                    ((ParticleTankState *)*(u8**)(atomicAddress + iGpffffb610))->activeCount = animatedActiveCount;
                }
                /* Packed halfword in the shared emitter parameter word span (unknown2c). */
                GeometryBlockSetPartState(((EffParticleInstance *)particle)->geometry.bytes, *(u16*)(animationSettings + 0x54));
                /* Packed halfword in the shared emitter parameter word span (unknown2c). */
                GeometryBlockBindResource(*(u8**)(particle + 0x50), *(u16*)(animationSettings + 0x54));
            }
        }
    }
    break;
    case 5:
    {
        emitterOrObjects = ((EffParticleInstance *)particle)->children.bytes;
        if (emitterOrObjects == 0)
        {
            kAssertFail(D_00713CD0, 0x3F3);
        }
        effectIndex = 0;
        while (effectIndex < particleCount)
        {
            if (((SpawnParticle *)record)->age >= 0)
            {
                u32 particleColor = ((SpawnParticle *)record)->color;
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
        emitterOrObjects = ((EffParticleInstance *)particle)->models.bytes;
        if (emitterOrObjects == 0)
        {
            kAssertFail(D_00713CD0, 0x406);
        }
        modelIndex = 0;
        while (modelIndex < particleCount)
        {
            if (((SpawnParticle *)record)->age >= 0)
            {
                u32 particleColor = ((SpawnParticle *)record)->color;
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
                mdlEffectFlushTreeFrame(*(s32*)emitterOrObjects);
            }
            modelIndex++;
            record += 0x20;
            emitterOrObjects += sizeof(s32);
        }
    }
    break;
    case 7:
    {
        u8* t = (u8*)((WaveSpawnEmitter *)emitterOrObjects)->parameters;
        ((EffParticleInstance *)particle)->link->field_0x00 = 0;
        ((EffParticleInstance *)particle)->link->field_0x04 = 0;
        {
            /* Packed halfword in the shared emitter parameter word span (unknown2c). */
            u8* pb = (u8*)TnGetOffset1C(*(u16*)(t + 0x54));
            /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
    return (u32)((const SpawnParticle *)record)->age;
}

/* measured: b210 -O2, full unmasked 4236/4240-byte proof and four zero tail bytes.
 * Native vertex/selection fields and VU outputs preserve the retail memory order.
 * The transformed path reads its unsigned frame index through the accessor before
 * loading the texture resource; both the reload and argument order are significant.
 * Receipt: build/first-party-continue-live/particle/resume-20260922-closure/. */
/* Camera and billboard code now share the canonical RwMatrixTag declaration. */
// Draws the particle billboards: builds each quad from the projected corners and submits them with the camera near and far planes.
// FUN_00488D70
/* Emitter/record members and PTank stream elements are typed at their access sites;
 * only individually measured culprits retain raw object accesses. */
void ParticleDrawBillboards(u8 *particle)
{
    extern s32 kwlnGetCamera(void);
    extern void effMiscBuildRotationVU(void);
    extern void TlpSelectFrame(TLP *work, u32 index, TlpSel *out);
    extern BtlShuffleRenderStateSet D_00887300[];
    extern BtlShuffleRenderPrimitive D_00887310[];
    extern f32 cosf(f32);
    extern f32 sinf(f32);
    extern ParticleProjectedVec3 *func_003e42a0(ParticleProjectedVec3 *a, const ParticleProjectedVec3 *b, const BtlShuffleMatrix *c);
    extern void kAssertFail(void *file, s32 line);
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
    record = (u8*)((WaveSpawnEmitter *)emitter)->particles;
    bufferNear = D_008872FC[0];
    bufferFar = D_008872F8[0];
    cameraFar = ((RwCamera *)(u32)kwlnGetCamera())->farPlane;
    cameraNear = ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    particleCount = (s32)((WaveSpawnEmitter *)emitter)->totalCount;
    switch (((EffParticleInstance *)particle)->kind) {
    case 7:
    if (((s32)((WaveSpawnEmitter *)emitter)->flags & 1) == 0) {
        f32 reciprocalDepth;
        f32 projectedDepth;
        f32 planeSpan;
        i = 0;
        planeSpan = cameraNear - cameraFar;
        bufferFar = bufferFar - bufferNear;
        while (i < particleCount) {
            if (((SpawnParticle *)record)->age >= 0) {
                u32 work;
                sourceColor = (s32)((SpawnParticle *)record)->color;
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
                    TlpSelectFrame((TLP *)((EffParticleInstance *)particle)->tlpRef, (u32)((SpawnParticle *)record)->age, &selection);
                    D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)selection.tex);
                    /* measured: this access-site member conversion makes the owning function MISMATCH. */
                    width = *(f32 *)(record + 0x18) * ((selection.w / 32.0f) * selection.a);
                    /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
                    worldPosition.x = ((SpawnParticle *)record)->position.lane[0];
                    worldPosition.y = ((SpawnParticle *)record)->position.lane[1];
                    worldPosition.z = ((SpawnParticle *)record)->position.lane[2];
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
                            cosine = cosf(((SpawnParticle *)record)->angle);
                            /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
            if (((SpawnParticle *)record)->age >= 0) {
                __asm__ volatile("lqc2 $vf28, 0(%0)\nlqc2 $vf29, 16(%0)\nlqc2 $vf30, 32(%0)\nlqc2 $vf31, 48(%0)\nlqc2 $vf10, 0(%1)\nvmulax.xyzw $ACC, $vf28, $vf10x\nvmadday.xyzw $ACC, $vf29, $vf10y\nvmaddaz.xyzw $ACC, $vf30, $vf10z\nvmaddw.xyzw $vf10, $vf31, $vf0w\n" : : "r"(base), "r"(record) : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%1)\n" : "=m"(*(ParticleSnapshot *)D_00713D10) : "r"(D_00713D10) : "$vf10", "memory");
                worldPosition.x = ((EffectVuVector *)D_00713D10)->lane[0];
                worldPosition.y = ((EffectVuVector *)D_00713D10)->lane[1];
                worldPosition.z = ((EffectVuVector *)D_00713D10)->lane[2];
                {
                    u32 work;
                    transformedColor = (s32)((SpawnParticle *)record)->color;
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
                        TlpSelectFrame((TLP *)((EffParticleInstance *)particle)->tlpRef, frameIndex, &selection);
                        D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)selection.tex);
                        {
                            f32 particleScale = ((SpawnParticle *)record)->size;
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
                                cosine = cosf(((SpawnParticle *)record)->angle);
                                /* measured: this access-site member conversion makes the owning function MISMATCH. */
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
