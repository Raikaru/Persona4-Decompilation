#ifndef BTL_MOTION_INTERNAL_H
#define BTL_MOTION_INTERNAL_H

#include "type.h"

/* Animation and blend frames retain their signed/unsigned halfword domains.
 * Rate occupies f12; integer arguments are unit, motion, frame and option. */
void func_00198920(u8 *unit, s16 motion, u16 frame, f32 rate, u16 option);
void func_00198dd0(u8 *unit, u16 frame);
s64 func_001990d0(u8 *unit, u16 motion);
/* Animation-table and boss-override selectors use their low unsigned halfword. */
f32 func_00196bd0(u8 *unit, u8 *target, u16 motion);

u32 func_00199e70(void *work);
u32 func_0019a030(void *work);
u32 func_0019ab00(void *work);

/* Opening-motion selection and its boss-state predicate consume signed
 * halfword identifiers, not 64-bit action/animation values. */
s32 func_00199d00(s32 unused, u8 *unit, s16 skill, s32 paired);
s32 func_0022fa90(u8 *action, s16 motion);

/* Boss motion overrides use both the unit and motion selector. A missing
 * override is -1; the timing helpers consume the returned signed halfword. */
s32 func_0022cb90(u8 *unit, u16 motion);
/* The timing queries and distance helper share that selector domain. */
s16 func_001991c0(u8 *unit, u16 motion, f32 rate);
s16 func_00199350(u8 *unit, u16 motion, f32 rate);
s16 func_001996d0(u8 *unit, u16 motion);
f32 func_0022cf00(u8 *unit, u8 *target, u16 motion);
s16 func_00199500(u8 *unit, u16 motion, f32 rate);
s16 func_001999f0(u8 *unit, u16 motion, f32 rate, s64 hit);

#endif
