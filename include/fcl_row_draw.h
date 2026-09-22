#ifndef FCL_ROW_DRAW_H
#define FCL_ROW_DRAW_H

#include "fcl_color.h"
#include "fcl_draw_types.h"

/* The EE row transition consumes native position and color packets. */
void func_002b77d0(s16 resource, FclVec2 position, s16 image,
                   FclDrawColor color, s16 order, s8 mode,
                   s16 duration, s16 alternate_duration, f32 depth,
                   s16 argument, u32 source);

void func_00320970(u8 *task, s8 mode);
void func_00329310(u8 *task, s16 duration, s8 mode);

#endif
