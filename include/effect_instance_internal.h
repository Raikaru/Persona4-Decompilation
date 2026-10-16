#ifndef EFFECT_INSTANCE_INTERNAL_H
#define EFFECT_INSTANCE_INTERNAL_H

#include "type.h"

/* Primitive table entries receive a source descriptor or an existing instance
 * and return the allocated instance, or NULL for an unsupported primitive. */
typedef void *(*EffectInstanceConstructor)(void *source);

/* Object particle instance (effObjectParticle.c). Only fields read by the update and
 * draw paths are named; gaps are kept as fields so offsets stay exact. */
typedef struct ObjectParticleInstance {
    u32 field_0x00;
    u32 packedColour;        /* +0x04: packed colour word read by the draw path */
    f32 field_0x08;
    u16 kind;                /* +0x0C: record kind compared by the update and draw switches */
    u8 field_0x0E[0x2C - 0x0E];
    f32 ageFactor;           /* +0x2C: multiplies the age in the draw path's trail step */
    u16 field_0x30;
    u8 field_0x32[0x54 - 0x32];
    u8 *clump;               /* +0x54 */
    u8 *list;                /* +0x58: record list; count at +0x8, entries at +0x18 */
    u8 *entries;             /* +0x5C: per-entry table walked by the update and draw paths */
} ObjectParticleInstance;

/* Effect RNG state (effMisc.c). A NULL state selects the global generator. */
typedef struct EffRandState EffRandState;
u32 effMiscRand(EffRandState *state);
f32 effMiscRandFloat(EffRandState *state);
void effMiscRandInit(EffRandState *state, u32 seed);

/* Resolve either a linked pointer or an offset within the source descriptor. */
void *mdlEffectResolveRelPtrA(void *source);
void *mdlEffectResolveRelPtrB(void *source);

u8 *func_00484bb0(u8 *resource);
u8 *mdlEffectCloneWithNodes(u8 *resource);
void mdlEffectCopyRecord(u8 *destination, u8 *source);
u8 *mdlEffectFindNodeById(u8 *root, s32 identifier);
void mdlEffectSlotSetZero(u8 *param_1, u16 param_2);
void mdlEffectSlotRelease(u8 *param_1, u16 param_2);
s32 mdlEffectSlotIsFree(u8 *param_1, u16 param_2);

u8 *ThunderTextureForIndex(u16 kind, u8 *parameters);
u8 *RingCreateKindInstance(u16 kind, u8 *parameters);
u8 *LineNovaCreateKindInstance(s32 kind, u8 *parameters);

void *func_00484530(void *source);
void *ParticleCreateFromSource(void *source);
void *ParticleCreateFromParent(void *source);
void *TrackCreateFromEmitter(void *source);
void *TrackCreateFromSource(void *source);
void *TrackCreateWithMode(void *source);
void *TrackCreateFromSourceCopy(void *source);
void *ThunderTextureForObject(void *source);
void *ThunderTextureForRecord(void *source);
void *RingCreateKindInstanceFromObject(void *source);
void *RingCreateInstanceForRecord(void *source);
void *FlashQuadCopyAllocFromParent(void *source);
void *FlashQuadCopyAllocFromRecord(void *source);
void *WindCreateKindEntry(void *source);
void *WindCreateKindEntryAlt(void *source);
void *mdlEffectCreateInstance(void *source);
void *mdlEffectCloneInstance(void *source);
void *mdlEffectCreateGridForObject(void *source);
void *mdlEffectCreateGridFromInstance(void *source);
void *func_004a7a90(void *source);
void *func_004a7b70(void *source);
void *effBlurFilterCopiedInstantiate(void *source);
void *effBlurFilterCopiedDuplicate(void *source);
void *effBlurFilterDirectInstantiate(void *source);
void *effBlurFilterDirectDuplicate(void *source);
u8 *effBlurFilterCopiedCreate(u32 type, const void *initialData);
u8 *effBlurFilterDirectCreate(u32 type, const void *initialData);
void effBlurFilterCopiedDestroy(void *param_1);
void effBlurFilterDirectDestroy(void *param_1);
void effBlurFilterCopiedDispatch(void *param_1);
void effBlurFilterDirectDispatch(void *param_1);
void effBlurFilterCopiedAdvanceAndSync(u8 *param_1);
void effBlurFilterDirectAdvanceAndSync(u8 *param_1);
void *EffModelCreate(void *source);
void *EffModelClone(void *source);
void *EffModelCreateDrawable(void *source);
void *EffModelCloneDrawable(void *source);
void *EffHelperCreate(void *source);
void *EffHelperClone(void *source);
void *ObjectParticleCreateFromSource(void *source);
void *ObjectParticleCreateFromParent(void *source);
void *DistortParticleCreateFromSource(void *source);
void *DistortParticleCreateFromParent(void *source);
void *func_004b16c0(void *source);
void *func_004b1950(void *source);
void *LineNovaCreateKindInstanceFromObject(void *source);
void *LineNovaCreateInstanceForRecord(void *source);
void *EffBattleCreate(void *source);
void *EffBattleCreateFromRecord(void *source);

#endif
