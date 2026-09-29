#ifndef BTL_MOTION_INTERNAL_H
#define BTL_MOTION_INTERNAL_H

#include "type.h"

/* Animation and blend frames retain their signed/unsigned halfword domains.
 * Rate occupies f12; integer arguments are unit, motion, frame and option. */
void func_00198920(u8 *unit, s16 motion, u16 frame, f32 rate, u16 option);
void func_00198dd0(u8 *unit, u16 frame);
s64 func_001990d0(u8 *unit, s32 motion);
/* The motion selector remains a word until the animation-table lookup narrows it. */
f32 func_00196bd0(u8 *unit, u8 *target, s32 motion);

u32 func_00199e70(void *work);
u32 func_0019a030(void *work);
u32 func_0019ab00(void *work);

#endif
