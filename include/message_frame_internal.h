#ifndef P4_MESSAGE_FRAME_INTERNAL_H
#define P4_MESSAGE_FRAME_INTERNAL_H

#include "type.h"

/* The depth is the first float channel, between the screen position and size,
 * as in the adjacent frame renderer 00366670. Keep each caller on this type. */
void func_00366380(s32 x, s32 y, f32 depth, s32 width, s32 height,
                   s32 color, s32 alpha, s32 mode, s32 offsetX, s16 offsetY,
                   void *queue, f32 rotation, f32 scaleX, f32 scaleY);

#endif
