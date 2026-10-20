#ifndef EFFECT_INSTANCE_INTERNAL_H
#define EFFECT_INSTANCE_INTERNAL_H

#include "type.h"

/* Primitive table entries receive a source descriptor or an existing instance
 * and return the allocated instance, or NULL for an unsupported primitive. */
typedef void *(*EffectInstanceConstructor)(void *source);

/* Object particle instance (effObjectParticle.c). Its allocation is 0x94 bytes. Only fields
 * read or written by the create, update, draw and release paths are named; gaps are kept as
 * fields so offsets stay exact. */
typedef struct ObjectParticleInstance {
    u32 recordCount;         /* +0x00: record count written at create (source count times multiplier, capped at 100) */
    u32 packedColour;        /* +0x04: packed colour word read by the draw path; create stores -1 */
    f32 field_0x08;          /* create stores the bit pattern 0x3F800000 (1.0f) */
    u16 kind;                /* +0x0C: record kind compared by the update and draw switches */
    u8 field_0x0E[0x2C - 0x0E];
    f32 ageFactor;           /* +0x2C: multiplies the age in the draw path's trail step */
    u16 field_0x30;
    u8 field_0x32[0x54 - 0x32];
    u8 *clump;               /* +0x54 */
    u8 *list;                /* +0x58: record list; count at +0x8, entries at +0x18 */
    u8 *entries;             /* +0x5C: per-entry table walked by the update and draw paths */
    u8 *recordTable;         /* +0x60: owned allocation with 0x18 bytes per record; ObjectParticleFree releases it */
    u8 field_0x64[0x7C - 0x64];
    u16 recordStride;        /* +0x7C: 0x18 at create, the per-record size of recordTable */
    u8 field_0x7E[0x80 - 0x7E];
    struct ObjectParticleInstance *self;  /* +0x80: self back-pointer written at create */
    u8 field_0x84[0x94 - 0x84];
} ObjectParticleInstance;

/* Source block resolved from a source descriptor by mdlEffectResolveRelPtrA. Its first 0x44
 * bytes are the object particle header copied into the instance at +0x10. */
typedef struct EffSourceBlock {
    u8 header[0x44];
    u8 field_0x44[0x64 - 0x44];  /* +0x44: record sub-block passed to ObjectParticleRebuildRecords */
    s32 recordCount;             /* +0x64: zero selects fallbackCount */
    u32 recordMultiplier;        /* +0x68: record count is recordCount (or fallbackCount) times this */
    u8 field_0x6C[0xFC - 0x6C];
    u32 fallbackCount;           /* +0xFC */
} EffSourceBlock;

/* Source descriptor received by ObjectParticleCreateFromSource. Only the fields read by the
 * create path are named. */
typedef struct EffSourceDescriptor {
    u8 field_0x00[0x0C];
    u16 id;                  /* +0x0C: source id, masked to 16 bits when the records are rebuilt */
    u8 field_0x0E[0x1C - 0x0E];
    u16 kind;                /* +0x1C: 3 loads the clump through the resource walk */
    u8 field_0x1E[0x24 - 0x1E];
    u32 clumpInput;          /* +0x24: passed through as the second input of the resource walk */
} EffSourceDescriptor;

/* Effect particle link node (effParticle.c). Each particle with a link owns one 0x30-byte node
 * that carries the 0x19 tag and points back at the owning particle. */
typedef struct ParticleLinkNode {
    s32 field_0x00;          /* zeroed by the drawing path before the node is appended */
    s32 field_0x04;
    u8 field_0x08[0x18 - 0x08];
    u16 tag;                 /* +0x18: 0x19 at creation */
    u8 field_0x1A[0x1C - 0x1A];
    u8 *owner;               /* +0x1C: the particle that owns this node */
} ParticleLinkNode;

/* Effect particle: the allocator reserves 0x60 bytes. Handle words are also
 * consumed as pointers by subtype-specific paths; retain both representations. */
typedef struct EffParticleInstance {
    union { s32 signedValue; u32 value; } recordCount; /* +0x00 */
    union { s32 signedValue; u32 value; } packedColor; /* +0x04 */
    union { f32 value; s32 signedBits; u32 bits; } scale; /* +0x08 */
    u16 kind;                /* +0x0C: subtype dispatch */
    u8 flags;                /* +0x0E: bit zero owns the emitter */
    u8 padF;
    u8 pad10[0x24];
    union { s32 handle; u8 *bytes; u8 **objects; } children; /* +0x34 */
    union { s32 handle; u8 *bytes; void *pointer; } childAllocation; /* +0x38 */
    union { s32 handle; u8 *bytes; u8 **objects; } models; /* +0x3C */
    union { s32 handle; u8 *bytes; void *pointer; } modelAllocation; /* +0x40 */
    union { s32 handle; u8 *bytes; } animation; /* +0x44 */
    s32 tlpRef;              /* +0x48: TLP handle, reference-counted by ParticleCopyModeFromSource */
    union { s32 handle; u32 bits; u8 *bytes; } emitter; /* +0x4C */
    union { s32 handle; u8 *bytes; } geometry; /* +0x50 */
    f32 texScaleX;           /* +0x54: texture scale, the texture's +0xC word divided by 32 */
    f32 texScaleY;           /* +0x58: texture scale, the texture's +0x10 word divided by 32 */
    ParticleLinkNode *link;  /* +0x5C */
} EffParticleInstance;

/* Distortion particle instance (effDistortParticle.c). Its layout differs from
 * ObjectParticleInstance: +0x5C is the record list, +0x60 the texture object and +0x68 the
 * record table. Fields before +0x5C are not yet named. */
typedef struct DistortParticleInstance {
    u8 field_0x00[0x5C];
    u8 *list;                /* +0x5C: released by DistortParticleFree and DistortParticleReleaseSource */
    u8 *texture;             /* +0x60: texture object, refcount at its +0x54 */
    u8 *field_0x64;
    u8 *table;               /* +0x68: record table released through the allocator table */
} DistortParticleInstance;

/* Effect RNG state (effMisc.c). A NULL state selects the global generator. */
typedef struct EffRandState EffRandState;
u32 effMiscRand(EffRandState *state);
f32 effMiscRandFloat(EffRandState *state);
void effMiscRandInit(EffRandState *state, u32 seed);

/* Resolve either a linked pointer or an offset within the source descriptor. */
void *mdlEffectResolveRelPtrA(void *source);
void *mdlEffectResolveRelPtrB(void *source);

u8 *mdlEffectBuildFromResource(u8 *effect);
u8 *mdlEffectCloneWithNodes(u8 *effect);
void mdlEffectCopyRecord(u8 *destination, u8 *source);
u8 *mdlEffectFindNodeById(u8 *root, s32 identifier);
void mdlEffectSlotSetZero(u8 *instance, u16 slotIndex);
void mdlEffectSlotRelease(u8 *instance, u16 slotIndex);
s32 mdlEffectSlotIsFree(u8 *instance, u16 slotIndex);

u8 *ThunderTextureForIndex(u16 kind, u8 *parameters);
u8 *RingCreateKindInstance(u16 kind, u8 *parameters);
u8 *LineNovaCreateKindInstance(s32 kind, u8 *parameters);

void *mdlEffectPrimitiveCreateNull(void *input);
void *ParticleCreateFromSource(void *opaqueSource);
void *ParticleCreateFromParent(void *opaqueSource);
void *TrackCreateFromEmitter(void *opaqueSource);
void *TrackCreateFromSource(void *opaqueSource);
void *TrackCreateWithMode(void *opaqueSource);
void *TrackCreateFromSourceCopy(void *opaqueSource);
void *ThunderTextureForObject(void *source);
void *ThunderTextureForRecord(void *source);
void *RingCreateKindInstanceFromObject(void *source);
void *RingCreateInstanceForRecord(void *source);
void *FlashQuadCopyAllocFromParent(void *input);
void *FlashQuadCopyAllocFromRecord(void *source);
void *WindCreateKindEntry(void *source);
void *WindCreateKindEntryAlt(void *source);
void *mdlEffectCreateInstance(void *source);
void *mdlEffectCloneInstance(void *source);
void *mdlEffectCreateGridForObject(void *source);
void *mdlEffectCreateGridFromInstance(void *source);
void *func_004a7a90(void *source);
void *mdlEffectCloneShakeRecord(void *record);
void *effBlurFilterCopiedInstantiate(void *object);
void *effBlurFilterCopiedDuplicate(void *object);
void *effBlurFilterDirectInstantiate(void *object);
void *effBlurFilterDirectDuplicate(void *object);
u8 *effBlurFilterCopiedCreate(u32 type, const void *initialData);
u8 *effBlurFilterDirectCreate(u32 type, const void *initialData);
void effBlurFilterCopiedDestroy(void *object);
void effBlurFilterDirectDestroy(void *object);
void effBlurFilterCopiedDispatch(void *object);
void effBlurFilterDirectDispatch(void *object);
void effBlurFilterCopiedAdvanceAndSync(u8 *object);
void effBlurFilterDirectAdvanceAndSync(u8 *object);
void *EffModelCreate(void *source);
void *EffModelClone(void *effect);
void *EffModelCreateDrawable(void *source);
void *EffModelCloneDrawable(void *effect);
void *EffHelperCreate(void *source);
void *EffHelperClone(void *source);
void *ObjectParticleCreateFromSource(void *opaqueSource);
void *ObjectParticleCreateFromParent(void *opaqueSource);
void *DistortParticleCreateFromSource(void *opaqueSource);
void *DistortParticleCreateFromParent(void *opaqueSource);
void *mdlEffectCreateScreenSprite(void *opaqueSource);
void *mdlEffectCloneHelperInstance(void *opaqueSource);
void *LineNovaCreateKindInstanceFromObject(void *source);
void *LineNovaCreateInstanceForRecord(void *opaqueSource);
void *EffBattleCreate(void *source);
void *EffBattleCreateFromRecord(void *opaqueSource);

#endif
