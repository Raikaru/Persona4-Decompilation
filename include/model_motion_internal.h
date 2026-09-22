#ifndef MODEL_MOTION_INTERNAL_H
#define MODEL_MOTION_INTERNAL_H

#include "type.h"

/* The animation index is signed-short and blend ticks are unsigned-short.
 * Layer and flags remain promoted words and are narrowed by their consumers. */
s32 func_00479940(u8 *model, u32 layer, s16 animation, u16 blendTicks, s32 flags);
s32 func_00479d10(u8 *model, u32 layer, s16 animation);
void func_0047eb20(u8 *state, s16 animation, u16 blendTicks);

#endif
