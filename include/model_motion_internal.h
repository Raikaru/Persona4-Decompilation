#ifndef MODEL_MOTION_INTERNAL_H
#define MODEL_MOTION_INTERNAL_H

#include "type.h"

/* The animation index is signed-short and blend ticks are unsigned-short.
 * Layer and flags remain promoted words and are narrowed by their consumers. */
s32 mdlDispatchAnimIfPresent(u8 *mdl, u32 layer, s16 animation, u16 frame, s32 flags);
s32 mdlLayerHasAnimation(u8 *model, u32 layer, s16 animation);
void mdlRequestMotionAnim(u8 *state, s16 animation, u16 blendTicks);
/* Model registry bucket table: head of each model-object list, indexed by model type (retail D_00922BE0). */
extern void *D_00922BE0[];

#endif
