#ifndef EFFECT_INSTANCE_INTERNAL_H
#define EFFECT_INSTANCE_INTERNAL_H

#include "type.h"

/* Primitive table entries receive a source descriptor or an existing instance
 * and return the allocated instance, or NULL for an unsupported primitive. */
typedef void *(*EffectInstanceConstructor)(void *source);

/* Effect RNG state (effMisc.c). A NULL state selects the global generator. */
typedef struct EffRandState EffRandState;
u32 effMiscRand(EffRandState *state);
f32 effMiscRandFloat(EffRandState *state);
void effMiscRandInit(EffRandState *state, u32 seed);

/* Resolve either a linked pointer or an offset within the source descriptor. */
void *func_00484490(void *source);
void *func_004844d0(void *source);

u8 *func_00484bb0(u8 *resource);
u8 *func_00485c80(u8 *resource);
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
void *func_00498b20(void *source);
void *RingCreateKindInstanceFromObject(void *source);
void *func_0049a5e0(void *source);
void *FlashQuadCopyAllocFromParent(void *source);
void *func_004a1950(void *source);
void *WindCreateKindEntry(void *source);
void *func_004a5910(void *source);
void *func_004a5bb0(void *source);
void *func_004a5e50(void *source);
void *func_004a6d90(void *source);
void *func_004a6e10(void *source);
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
void *func_004abe80(void *source);
void *func_004ac100(void *source);
void *func_004ac640(void *source);
void *func_004ac930(void *source);
void *func_004ad460(void *source);
void *func_004ad810(void *source);
void *func_004ae460(void *source);
void *func_004ae6d0(void *source);
void *DistortParticleCreateFromSource(void *source);
void *DistortParticleCreateFromParent(void *source);
void *func_004b16c0(void *source);
void *func_004b1950(void *source);
void *LineNovaCreateKindInstanceFromObject(void *source);
void *func_004b4f10(void *source);
void *func_004b5200(void *source);
void *func_004b53c0(void *source);

#endif
