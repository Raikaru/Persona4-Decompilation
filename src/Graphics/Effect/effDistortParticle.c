#include "include_asm.h"
/* Persona 4 USA decompilation - effDistortParticle.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "effect_instance_internal.h"
#include "rw_camera_internal.h"
#include "particle_spawn_internal.h"

typedef struct DistortParticleNode {
    u8 pad00[0x18];
    s16 tag;
    u8 pad1A[2];
    u32 owner;
    u8 pad20[0x10];
} DistortParticleNode;

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00714538[];
extern char D_00714550[];

extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const char *file, s32 line);
extern void *memset(void *dest, s32 value, s32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern void mdlEffectFreeEmitterAllocation(void *instance);
extern u8 *mdlEffectAllocateTrackPath(u32 kind, s32 primaryCount, u8 *parameters);
extern void mdlEffectAdvanceEmitter(void *object);
extern s32 TnSlotObject(u16 slotIndex);
extern void mdlEffectLoadQuadB(void *instance, void *quadData);
extern void mdlEffectLoadQuadA(void *instance, void *quadData);
extern void DistortParticleDrawSky(u8 *particle, u8 *record, void *sourceRecord, void *position, void *colorScale, void *textureSize, s32 drawMode, s32 uvIndex);
extern void effMiscBuildRotationVU(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern f32 fGpffff8080;
extern f32 fGpffff8098;
extern f32 fGpffff809c;
extern s32 iGpffff81f4; /* 0x007612E4 */
void DistortParticleSeedRecord(u8 *particle, u8 *record);
void DistortParticleRebuildRecords(u8 *particle, u32 sourceId, u8 *parameters);
void DistortParticleUploadTexture(u8 *particle, s32 handle);
void DistortParticleShareTexture(u8 *destination, u8 *source);
extern s32 TnUploadStreamTagged();

/* The header fills DistortParticleInstance::field_0x00; the copied settings
 * occupy +0x0C..+0x53 and the two running scroll values end at +0x5C.
 * Allocation/strides prove the record layouts; resource gaps stay opaque. */
typedef struct DistortParticleHeader {
    union {
        s32 signedValue;
        u32 unsignedValue;
    } recordCount; /* +0x00 */
    s32 color; /* +0x04 */
    u32 scale; /* +0x08 */
    f32 sizeVariation; /* +0x0C */
    f32 xAmplitude; /* +0x10 */
    f32 yAmplitude; /* +0x14 */
    f32 phaseStep; /* +0x18 */
    f32 xScrollStep; /* +0x1C */
    f32 yScrollStep; /* +0x20 */
    f32 fadeVariation; /* +0x24 */
    f32 xSize; /* +0x28 */
    f32 ySize; /* +0x2C */
    u8 pad30[0x24];
    union {
        f32 scalar;
        s32 signedValue;
    } xScroll; /* +0x54 */
    union {
        f32 scalar;
        s32 signedValue;
    } yScroll; /* +0x58 */
} DistortParticleHeader;

typedef struct DistortParticleSourceData {
    u8 pad00[0x68];
    s32 count; /* +0x68 */
    u32 multiplier; /* +0x6C */
    u8 pad70[0x90];
    u32 fallbackCount; /* +0x100 */
} DistortParticleSourceData;

typedef struct DistortParticleParameters {
    u8 pad00[0x20];
    s32 count; /* +0x20 */
    u32 multiplier; /* +0x24 */
    u8 pad28[0x28];
    u32 alphaDivisor; /* +0x50: mode-one draw divides the source alpha by this value */
    u8 pad54[0x64];
    u32 fallbackCount; /* +0xB8 */
    u8 padBC[0x4];
    s32 unkC0; /* +0xC0 */
} DistortParticleParameters;

typedef struct DistortTextureReference {
    u8 *raster; /* +0x00: native RwTexture raster link */
    u8 pad04[0x50];
    s32 references; /* +0x54 */
} DistortTextureReference;

typedef struct DistortParticleRecord {
    f32 xPhase; /* +0x00 */
    f32 xStep; /* +0x04 */
    f32 xAmplitude; /* +0x08 */
    f32 yPhase; /* +0x0C */
    f32 yStep; /* +0x10 */
    f32 yAmplitude; /* +0x14 */
    f32 scale; /* +0x18 */
} DistortParticleRecord;

typedef struct DistortParticleSourceRecord {
    u8 pad00[0x10];
    s32 state; /* +0x10 */
    s32 color; /* +0x14 */
    f32 scale; /* +0x18 */
    f32 angle; /* +0x1C */
} DistortParticleSourceRecord;

typedef struct DistortParticleSourceList {
    u8 pad00[0x8];
    s32 count; /* +0x08 */
    s32 flags; /* +0x0C */
    s32 active; /* +0x10 */
    u8 pad14[0x4];
    u8 * records; /* +0x18 */
} DistortParticleSourceList;

typedef struct DistortParticleRaster {
    u8 pad00[0xC];
    s32 unk0C; /* +0x0C */
    s32 unk10; /* +0x10 */
} DistortParticleRaster;

// Allocates a zeroed 0x9C-byte record; stores object at +0, -1 at +4, 1.0f at +8 and points +0x88 at itself.
// FUN_004AF680
u8 *DistortParticleAlloc(u32 recordCount) {
    u8 *particle;

    chkmemAllocSiteTag(D_00714538, 0x171);
    particle = (u8 *)(*jtbl_008873E8)(0x9C, 0x40000);
    memset(particle, 0, 0x9C);
    if (particle == NULL) {
        kAssertFail(D_00714550, 0x2F);
    }
    ((DistortParticleHeader *)particle)->recordCount.unsignedValue = recordCount;
    ((DistortParticleHeader *)particle)->color = -1;
    ((DistortParticleHeader *)particle)->scale = 0x3F800000;
    ((DistortParticleHeader *)particle)->xScroll.signedValue = 0;
    ((DistortParticleHeader *)particle)->yScroll.signedValue = 0;
    ((DistortParticleNode *)(particle + 0x6C))->tag = 0x1A;
    ((DistortParticleNode *)(particle + 0x6C))->owner = (u32)particle;
    return particle;
}

// Creates a distortion particle from an effect source: sizes the record buffer from the source's count (capped at 100) and copies its 0x48-byte header; rebuilds the records and uploads the texture when the kind at +0x1C is 1 and the lookup returns one.
// FUN_004AF740
void *DistortParticleCreateFromSource(void *opaqueSource) {
    u8 *source = opaqueSource;
    s32 sourceCount;
    u32 recordCount;
    u8 *sourceData;
    u8 *particle;
    s32 textureData;

    sourceData = mdlEffectResolveRelPtrA(source);
    if (sourceData == NULL) {
        kAssertFail(D_00714550, 0x69);
    }
    sourceCount = ((DistortParticleSourceData *)sourceData)->count;
    if (sourceCount == 0) {
        recordCount = ((DistortParticleSourceData *)sourceData)->fallbackCount * ((DistortParticleSourceData *)sourceData)->multiplier;
    } else {
        recordCount = (u32)sourceCount * ((DistortParticleSourceData *)sourceData)->multiplier;
    }
    if (recordCount > 0x64) {
        recordCount = 0x64;
    }
    particle = DistortParticleAlloc(recordCount);
    if (particle == NULL) {
        kAssertFail(D_00714550, 0x6B);
    }
    memcpy(particle + 0xC, sourceData, 0x48);
    DistortParticleRebuildRecords(particle, ((EffSourceDescriptor *)source)->id, sourceData + 0x48);
    if (((DistortParticleSourceList *)((DistortParticleInstance *)particle)->list)->count == 0) {
        return particle;
    }
    textureData = (s32)mdlEffectResolveRelPtrB(source);
    if (textureData != 0) {
        switch (((EffSourceDescriptor *)source)->kind) {
        case 1:
            DistortParticleUploadTexture(particle, textureData);
            break;
        default:
            kAssertFail(D_00714550, 0x80);
            break;
        }
    }
    return particle;
}

// Releases the particle's source block, texture reference, record table and the particle itself.
// FUN_004AF8A0
void DistortParticleFree(u8 *particle) {
    u8 *allocation;
    DistortParticleInstance *inst = (DistortParticleInstance *)particle;

    allocation = inst->texture;
    if (allocation != NULL) {
        func_003ef3a0(allocation);
    }
    allocation = inst->list;
    if (allocation != NULL) {
        mdlEffectFreeEmitterAllocation(allocation);
    }
    allocation = inst->table;
    if (allocation != NULL) {
        (*jtbl_008873EC)(allocation);
    }
    (*jtbl_008873EC)(particle);
}

// Creates a distortion particle from a parent record: sizes the record buffer from the parent's block and shares its texture; asserts the parent block exists.
// FUN_004AF920
void *DistortParticleCreateFromParent(void *opaqueSource) {
    /* Access-site typing differed by 218 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    u8 *parent = opaqueSource;
    s32 sourceCount;
    u32 recordCount;
    u8 *parameters;
    u8 *particle;
    DistortParticleInstance *parentInstance = (DistortParticleInstance *)parent;
    DistortParticleInstance *instance;
    DistortParticleParameters *settings;

    if (parentInstance->list == NULL) {
        kAssertFail(D_00714550, 0xB3);
    }
    parameters = (u8 *)((WaveSpawnEmitter *)parentInstance->list)->originalParameters;
    settings = (DistortParticleParameters *)parameters;
    if (parameters == NULL) {
        kAssertFail(D_00714550, 0xB5);
    }
    sourceCount = settings->count;
    if (sourceCount == 0) {
        recordCount = settings->fallbackCount * settings->multiplier;
    } else {
        recordCount = (u32)sourceCount * settings->multiplier;
    }
    if (recordCount > 0x64) {
        recordCount = 0x64;
    }
    particle = DistortParticleAlloc(recordCount);
    instance = (DistortParticleInstance *)particle;
    if (particle == NULL) {
        kAssertFail(D_00714550, 0xB7);
    }
    memcpy(particle + 0xC, parent + 0xC, 0x48);
    DistortParticleRebuildRecords(particle, ((WaveSpawnEmitter *)parentInstance->list)->kind, parameters);
    if (((DistortParticleSourceList *)instance->list)->count == 0) {
        return particle;
    }
    DistortParticleShareTexture(particle, parent);
    return particle;
}

// Uploads the tagged texture for slot value through TnUploadStreamTagged and stores that call's result at +0x60.
// FUN_004AFA60
void DistortParticleUploadTexture(u8 *particle, s32 handle) {
    ((DistortParticleInstance *)particle)->texture = (u8 *)TnUploadStreamTagged(handle);
}

// Shares the texture object of handle with particle and bumps its reference count at +0x54; asserts that handle holds one.
// FUN_004AFAA0
void DistortParticleShareTexture(u8 *destination, u8 *source) {
    u8 *texture;
    DistortParticleInstance *dst = (DistortParticleInstance *)destination;
    DistortParticleInstance *src = (DistortParticleInstance *)source;

    if (src->texture == 0) {
        kAssertFail(D_00714550, 0xDA);
    }
    texture = src->texture;
    dst->texture = texture;
    ((DistortTextureReference *)texture)->references += 1;
}

// Rebuilds the source block for id source with parameters options, then re-allocates the record table and seeds every record.
// FUN_004AFB10
void DistortParticleRebuildRecords(u8 *particle, u32 sourceId, u8 *parameters) {
    /* Access-site typing differed by 212 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    u32 recordCount;
    u8 *record;
    u32 recordIndex;
    u8 *records;
    DistortParticleInstance *instance = (DistortParticleInstance *)particle;
    DistortParticleHeader *header = (DistortParticleHeader *)particle;

    if (instance->list != NULL) {
        mdlEffectFreeEmitterAllocation(instance->list);
    }
    if (((DistortParticleParameters *)parameters)->unkC0 != 0) {
        kAssertFail(D_00714550, 0xF4);
    }
    instance->list = mdlEffectAllocateTrackPath(sourceId & 0xFFFF, header->recordCount.signedValue, parameters);
    if (instance->table != NULL) {
        (*jtbl_008873EC)(instance->table);
    }
    recordCount = (u32)((DistortParticleSourceList *)instance->list)->count;
    chkmemAllocSiteTag(D_00714550, 0xFE);
    records = (u8 *)(*jtbl_008873E8)(recordCount * 0x1C, 0x40000);
    instance->table = records;
    if (records == NULL) {
        kAssertFail(D_00714550, 0xFF);
    }
    record = instance->table;
    instance->field_0x64 = record;
    recordIndex = 0;
    while (recordIndex < recordCount) {
        DistortParticleSeedRecord(particle, record);
        recordIndex += 1;
        record += 0x1C;
    }
}

// Releases the source block at +0x5C through func_00492d00 when one is set.
// FUN_004AFC50
void DistortParticleReleaseSource(u8 *particle)
{
    u32 sourceList;
    DistortParticleInstance *inst = (DistortParticleInstance *)particle;

    sourceList = (u32)inst->list;
    if (sourceList != 0) {
        mdlEffectResetEmitterTicks(sourceList);
    }
}

// Seeds one 0x1C-byte record from the particle's parameters: random offsets, sizes, scale and the fade value at +0x24.
// FUN_004AFC80
void DistortParticleSeedRecord(u8 *particle, u8 *record) {
    /* Access-site typing differed by 295 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    f32 sizeVariation;
    f32 sizeFactor;
    f32 fadeVariation;
    DistortParticleHeader *header = (DistortParticleHeader *)particle;
    DistortParticleRecord *entry = (DistortParticleRecord *)record;

    sizeVariation = header->sizeVariation;
    sizeFactor = (1.0f - sizeVariation) + sizeVariation * effMiscRandFloat(0);
    entry->xPhase = fGpffff8080 * effMiscRandFloat(0);
    entry->yPhase = fGpffff8080 * effMiscRandFloat(0);
    entry->xStep = header->phaseStep * (0.5f + 0.5f * effMiscRandFloat(0));
    entry->yStep = header->phaseStep * (0.5f + 0.5f * effMiscRandFloat(0));
    entry->xAmplitude = sizeFactor * (header->xAmplitude * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
    entry->yAmplitude = sizeFactor * (header->yAmplitude * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
    fadeVariation = header->fadeVariation;
    entry->scale = (1.0f - fadeVariation) + fadeVariation * effMiscRandFloat(0);
}

/* DistortParticleDrawSky, MATCH 2026-10-07. Rewritten from retail asm on the matched
   effParticle sibling's pattern (ParticleDrawBillboards): one 64-byte sky vertex quad,
   per-channel unsigned colour conversions, and the projected-depth formula.
   The colour unpack asm names $2 and the COP2 pack stores the packed word to
   its frame slot (both user-approved VU0 forms). Retail returns nothing, so
   the prototype is void. (u32) address casts stop the CSE of options + 0x14/0x1C;
   the render tables are read through u32 locals, which keeps them in $s1/$s0.
   The mode-1 alpha byte is stored through a byte pointer so particle's sizes are
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
// Draws one sky-quad record: builds the 64-byte vertex quad from the particle's sizes and colour tables, then sets the sky render states through RpSkyRenderStateSet.
// FUN_004AFE20
void DistortParticleDrawSky(u8 *particle, u8 *record, void *sourceRecord, void *position, void *colorScale, void *textureSize, s32 drawMode, s32 uvIndex)
{
    /* Access-site typing differed by 1319 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    extern void RpSkyRenderStateGet(s32 param, void *out);
    extern void RpSkyRenderStateSet(s32 param, s32 value);
    extern f32 cosf(f32 param);
    extern f32 sinf(f32 param);
    extern s32 kwlnGetCamera(void);
    extern void func_003e42a0(DistortVec3 *out, DistortVec3 *in, void *matrix);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern void mdlEffectEmitSlotPacket(void);
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
    s32 savedTextureState;
    s32 savedBlendState;
    s32 sourceColor;
    u32 packedColor;
    DistortVec3 worldPosition __attribute__((aligned(16)));
    DistortVec3 cameraPosition __attribute__((aligned(16)));
    DistortVertex quad[4];
    f32 base;
    f32 horizontalScale;
    f32 verticalScale;
    f32 sizeX;
    f32 sizeY;
    u32 mode;
    f32 bufferNear;
    f32 bufferFar;
    f32 cameraFar;
    f32 cameraNear;
    f32 recip;
    f32 depth;
    f32 cosine;
    f32 sine;
    f32 xCosine;
    f32 yCosine;
    f32 xSine;
    f32 ySine;
    s32 outsideView;
    DistortParticleHeader *header = (DistortParticleHeader *)particle;
    DistortParticleInstance *instance = (DistortParticleInstance *)particle;
    DistortParticleRecord *entry = (DistortParticleRecord *)record;
    DistortParticleSourceRecord *source = (DistortParticleSourceRecord *)sourceRecord;

    sourceColor = source->color;
    {
        const s32 *word = &sourceColor;
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
            : : "r"(word), "r"(scale), "r"(colorScale), "m"(sourceColor) : "$2", "$vf2", "$vf10", "$vf11");
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
            "sw %0, packedColor\n"
            : "=&r"(work), "=m"(packedColor) : "r"(0x437F0000U) : "$vf2", "$vf10");
    }
    packed.word = packedColor;
    if (packed.bytes.alpha == 0) {
        return;
    }
    RpSkyRenderStateGet(2, &savedTextureState);
    RpSkyRenderStateGet(3, &savedBlendState);
    base = source->scale;
    horizontalScale = base + entry->xAmplitude * cosf(entry->xPhase);
    verticalScale = base + entry->yAmplitude * cosf(entry->yPhase);
    mode = drawMode & 0xFF;
    switch (mode) {
    case 0:
        sizeX = (((f32 *)textureSize)[0] * horizontalScale) / 32.0f;
        sizeY = (((f32 *)textureSize)[1] * verticalScale) / 32.0f;
        quad[0].r = (f32)(u32)packed.bytes.red;
        quad[0].g = (f32)(u32)packed.bytes.green;
        quad[0].b = (f32)(u32)packed.bytes.blue;
        quad[0].a = (f32)(u32)packed.bytes.alpha;
        quad[1].r = (f32)(u32)packed.bytes.red;
        quad[1].g = (f32)(u32)packed.bytes.green;
        quad[1].b = (f32)(u32)packed.bytes.blue;
        quad[1].a = (f32)(u32)packed.bytes.alpha;
        quad[2].r = (f32)(u32)packed.bytes.red;
        quad[2].g = (f32)(u32)packed.bytes.green;
        quad[2].b = (f32)(u32)packed.bytes.blue;
        quad[2].a = (f32)(u32)packed.bytes.alpha;
        quad[3].r = (f32)(u32)packed.bytes.red;
        quad[3].g = (f32)(u32)packed.bytes.green;
        quad[3].b = (f32)(u32)packed.bytes.blue;
        quad[3].a = (f32)(u32)packed.bytes.alpha;
        break;
    case 1: {
        f32 scale;

        if (header->xSize < fGpffff80f0 || header->ySize < ((f32 *)&fGpffff80f0)[0]) {
            return;
        }
        ((u8 *)&packed)[3] = (u8)((255.0f * (f32)((u32)source->color >> 24)) /
                                  (f32)((DistortParticleParameters *)((WaveSpawnEmitter *)instance->list)->parameters)->alphaDivisor);
        scale = entry->scale;
        sizeX = scale * (header->xSize * ((((f32 *)textureSize)[0] * horizontalScale) / 32.0f));
        sizeY = scale * (header->ySize * ((((f32 *)textureSize)[1] * verticalScale) / 32.0f));
        quad[0].r = 255.0f;
        quad[0].g = 255.0f;
        quad[0].b = 255.0f;
        quad[0].a = (f32)(u32)packed.bytes.alpha;
        quad[1].r = 255.0f;
        quad[1].g = 255.0f;
        quad[1].b = 255.0f;
        quad[1].a = (f32)(u32)packed.bytes.alpha;
        quad[2].r = 255.0f;
        quad[2].g = 255.0f;
        quad[2].b = 255.0f;
        quad[2].a = (f32)(u32)packed.bytes.alpha;
        quad[3].r = 255.0f;
        quad[3].g = 255.0f;
        quad[3].b = 255.0f;
        quad[3].a = (f32)(u32)packed.bytes.alpha;
        break;
    }
    }
    worldPosition.x = ((f32 *)position)[0];
    worldPosition.y = ((f32 *)position)[1];
    worldPosition.z = ((f32 *)position)[2];
    func_003e42a0(&cameraPosition, &worldPosition, (u8 *)kwlnGetCamera() + 0x20);
    {
        f32 ry = cameraPosition.y / cameraPosition.z;
        f32 rx = cameraPosition.x / cameraPosition.z;

        if (rx < -2.0f || !(rx <= 2.0f) || ry < -2.0f || !(ry <= 2.0f)) {
            outsideView = 1;
        } else {
            outsideView = 0;
        }
    }
    if (outsideView != 0) {
        return;
    }
    bufferNear = D_008872FC[0];
    bufferFar = D_008872F8[0];
    cameraFar = ((RwCamera *)kwlnGetCamera())->farPlane;
    cameraNear = ((RwCamera *)kwlnGetCamera())->nearPlane;
    depth = (cameraNear / cameraPosition.z) * ((cameraPosition.z - cameraFar) * ((bufferFar - bufferNear) / (cameraNear - cameraFar))) + (bufferNear + 0.0f);
    if (depth < 0.0f) {
        depth = 0.0f;
    }
    recip = 1.0f / depth;
    cosine = cosf(fGpffff8084 + source->angle);
    sine = sinf(fGpffff8084 + source->angle);
    xCosine = sizeX * cosine;
    yCosine = sizeY * cosine;
    xSine = sizeX * sine;
    ySine = sizeY * sine;
    quad[0].u = 0.0f;
    quad[0].v = 0.0f;
    quad[1].u = 1.0f;
    quad[1].v = 0.0f;
    quad[2].u = 0.0f;
    quad[2].v = 1.0f;
    quad[3].u = 1.0f;
    quad[3].v = 1.0f;
    quad[0].x = 640.0f * ((cameraPosition.x + (-xCosine + ySine)) / cameraPosition.z);
    quad[0].y = 448.0f * ((cameraPosition.y - (-xSine - yCosine)) / cameraPosition.z);
    quad[0].z = depth;
    quad[0].recipZ = recip;
    quad[1].x = 640.0f * ((cameraPosition.x + (xCosine + ySine)) / cameraPosition.z);
    quad[1].y = 448.0f * ((cameraPosition.y - (xSine - yCosine)) / cameraPosition.z);
    quad[1].z = depth;
    quad[1].recipZ = recip;
    quad[2].x = 640.0f * ((cameraPosition.x + (-xCosine - ySine)) / cameraPosition.z);
    quad[2].y = 448.0f * ((cameraPosition.y - (-xSine + yCosine)) / cameraPosition.z);
    quad[2].z = depth;
    quad[2].recipZ = recip;
    quad[3].x = 640.0f * ((cameraPosition.x + (xCosine - ySine)) / cameraPosition.z);
    quad[3].y = 448.0f * ((cameraPosition.y - (xSine + yCosine)) / cameraPosition.z);
    quad[3].z = depth;
    quad[3].recipZ = recip;
    switch (mode) {
    case 0: {
        u32 uv;
        u32 *texture = (u32 *)TnSlotObject(0x15);
        u32 setStateTable = (u32)D_00887300;
        u32 primitiveTable;

        ((void (**)(u32, u32))setStateTable)[0](1, *texture);
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31001);
        primitiveTable = (u32)D_00887310;
        ((s32 (**)(s32, DistortVertex *, s32))primitiveTable)[0](4, quad, 4);
        mdlEffectEmitTagPair();
        ((void (**)(u32, u32))setStateTable)[0](1, *(u32 *)instance->texture);
        RpSkyRenderStateSet(2, savedTextureState | 0x10);
        uv = (uvIndex & 0xFF) << 5;
        /* Interleaved UV-table linker interior aliases: each label names one lane of a 0x20-byte row. */
        quad[0].u = *(f32 *)((u8 *)D_00714570 + uv);
        quad[0].v = *(f32 *)((u8 *)D_00714574 + uv);
        quad[1].u = *(f32 *)((u8 *)D_00714578 + uv);
        quad[1].v = *(f32 *)((u8 *)D_0071457C + uv);
        quad[2].u = *(f32 *)((u8 *)D_00714580 + uv);
        quad[2].v = *(f32 *)((u8 *)D_00714584 + uv);
        quad[3].u = *(f32 *)((u8 *)D_00714588 + uv);
        quad[3].v = *(f32 *)((u8 *)D_0071458C + uv);
        ((s32 (**)(s32, DistortVertex *, s32))primitiveTable)[0](4, quad, 4);
        mdlEffectEmitSlotPacket();
        break;
    }
    case 1:
        RpSkyRenderStateSet(2, 0x42);
        D_00887310[0](4, quad, 4);
        break;
    }
    RpSkyRenderStateSet(2, savedTextureState);
    RpSkyRenderStateSet(3, savedBlendState);
}

// Advances the record table: re-seeds each record whose source-side word at +0x10 is zero, then steps the live records by their +4 and +0x10 deltas.
// FUN_004B0A80
void DistortParticleUpdateRecords(u8 *particle) {
    /* Access-site typing differed by 466 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    f32 sizeVariation;
    f32 sizeFactor;
    f32 fadeVariation;
    s32 recordCount;
    u8 *sourceRecord;
    u8 *record;
    s32 recordIndex;
    u8 *sourceList;
    DistortParticleInstance *instance = (DistortParticleInstance *)particle;
    DistortParticleHeader *header = (DistortParticleHeader *)particle;
    DistortParticleSourceList *list;
    DistortParticleSourceRecord *source;
    DistortParticleRecord *entry;

    mdlEffectAdvanceEmitter(instance->list);
    sourceList = instance->list;
    list = (DistortParticleSourceList *)sourceList;
    recordCount = list->count;
    if ((recordCount != 0) && (list->active != 0)) {
        sourceRecord = list->records;
        record = instance->field_0x64;
        header->xScroll.scalar = header->xScroll.scalar + header->xScrollStep;
        header->yScroll.scalar = header->yScroll.scalar + header->yScrollStep;
        recordIndex = 0;
        while (recordIndex < recordCount) {
            source = (DistortParticleSourceRecord *)sourceRecord;
            entry = (DistortParticleRecord *)record;
            if (source->state == 0) {
                sizeVariation = header->sizeVariation;
                sizeFactor = (1.0f - sizeVariation) + sizeVariation * effMiscRandFloat(0);
                entry->xPhase = fGpffff8080 * effMiscRandFloat(0);
                entry->yPhase = fGpffff8080 * effMiscRandFloat(0);
                entry->xStep = header->phaseStep * (0.5f + 0.5f * effMiscRandFloat(0));
                entry->yStep = header->phaseStep * (0.5f + 0.5f * effMiscRandFloat(0));
                entry->xAmplitude = sizeFactor * (header->xAmplitude * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
                entry->yAmplitude = sizeFactor * (header->yAmplitude * (fGpffff809c + fGpffff8098 * effMiscRandFloat(0)));
                fadeVariation = header->fadeVariation;
                entry->scale = (1.0f - fadeVariation) + fadeVariation * effMiscRandFloat(0);
            }
            if (source->state >= 0) {
                entry->xPhase = entry->xPhase + entry->xStep;
                entry->yPhase = entry->yPhase + entry->yStep;
            }
            recordIndex += 1;
            sourceRecord += 0x20;
            record += 0x1C;
        }
    }
}

// Projects the live records: when bit 0 of the source word at +0xC is clear each record is drawn directly; when set, the matrix from TnSlotObject(0x15) is applied to each record first.
// FUN_004B0CE0
void DistortParticleProjectRecords(u8 *particle, s32 drawMode) {
    /* Access-site typing differed by 444 normalized bytes; separate typed locals preserve the original reload lifetimes. */
    s32 particleColor;
    s32 *pt;
    f32 textureSize[2];
    u8 colorScale[16];
    u8 transformedPosition[16];
    u8 translation[16];
    u8 rotation[16];
    u8 matrix[0x40];
    u8 *sourceRecord;
    s32 recordCount;
    s32 recordIndex;
    s32 transformedIndex;
    u8 *raster;
    u8 *sourceList;
    u8 *updatedList;
    u8 *record;
    s32 scale;
    DistortParticleInstance *instance = (DistortParticleInstance *)particle;
    DistortParticleHeader *header = (DistortParticleHeader *)particle;
    DistortParticleSourceList *list;
    DistortParticleRaster *textureRaster;

    sourceList = instance->list;
    list = (DistortParticleSourceList *)sourceList;
    recordCount = list->count;
    if ((recordCount != 0) && (list->active != 0)) {
        if ((s32)instance->texture == 0) {
            kAssertFail(D_00714550, 0x265);
        }
        sourceRecord = ((DistortParticleSourceList *)instance->list)->records;
        record = instance->field_0x64;
        raster = ((DistortTextureReference *)(s32)TnSlotObject(0x15))->raster;
        textureRaster = (DistortParticleRaster *)raster;
        if ((drawMode & 0xFF) == 1) {
            D_00887300[0](1, (u32)raster);
        }
        textureSize[0] = (f32)textureRaster->unk0C;
        textureSize[1] = (f32)textureRaster->unk10;
        particleColor = header->color;
        pt = &particleColor;
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
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(colorScale) : "$vf10", "memory");
        updatedList = instance->list;
        if (!(((DistortParticleSourceList *)updatedList)->flags & 1)) {
            recordIndex = 0;
            while (recordIndex < recordCount) {
                if (((DistortParticleSourceRecord *)sourceRecord)->state >= 0) {
                    DistortParticleDrawSky(particle, record, sourceRecord, sourceRecord, colorScale, textureSize, drawMode, effMiscRand(0) & 3);
                }
                recordIndex += 1;
                sourceRecord += 0x20;
                record += 0x1C;
            }
        } else {
            mdlEffectLoadQuadB(updatedList, rotation);
            mdlEffectLoadQuadA(instance->list, translation);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(rotation) : "$vf10", "memory");
            effMiscBuildRotationVU();
            __asm__ volatile("lqc2 $vf31, 0(%0)" : : "r"(translation) : "$vf31", "memory");
            __asm__ volatile(
                "sqc2 $vf28, 0(%0)     \n"
                "sqc2 $vf29, 16(%0)    \n"
                "sqc2 $vf30, 32(%0)    \n"
                "sqc2 $vf31, 48(%0)    \n"
                :
                : "r"(matrix)
                : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            transformedIndex = 0;
            while (transformedIndex < recordCount) {
                if (((DistortParticleSourceRecord *)sourceRecord)->state >= 0) {
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
                        : "r"(matrix), "r"(sourceRecord)
                        : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(transformedPosition) : "$vf10", "memory");
                    DistortParticleDrawSky(particle, record, sourceRecord, transformedPosition, colorScale, textureSize, drawMode, effMiscRand(0) & 3);
                }
                transformedIndex += 1;
                sourceRecord += 0x20;
                record += 0x1C;
            }
        }
        D_00887300[0](1, 0);
    }
}
