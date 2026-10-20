#ifndef BTL_MOTION_INTERNAL_H
#define BTL_MOTION_INTERNAL_H

#include "type.h"


/* Unit movementFlags (+0xC8). Path walking sets MOVE; turning toward the target
 * sets ROTATE. Matching stateFlags bits (+0xC4) are cleared with them. */
#define BTLUNIT_MOVEMENTFLAGS_MOVE   (1 << 0)
#define BTLUNIT_MOVEMENTFLAGS_ROTATE (1 << 1)
/* Animation and blend frames retain their signed/unsigned halfword domains.
 * Rate occupies f12; integer arguments are unit, motion, frame and option. */
void btlUnitSetMotion(u8 *unit, s16 motion, u16 frame, f32 rate, u16 option);
void btlUnitUpdateStatusMotion(u8 *unit, u16 frame);
s64 btlUnitGetMotionId(u8 *unit, u16 motion);
/* Animation-table and boss-override selectors use their low unsigned halfword. */
f32 btlUnitGetMotionDistance(u8 *unit, u8 *target, u16 motion);

u32 btlUnitPlayMotionPacketUpdate(void *workData);
u32 btlUnitMotionRequestPacketUpdate(void *workData);
u32 btlUnitMotionSpeedPacketUpdate(void *workData);

/* Opening-motion selection and its boss-state predicate consume signed
 * halfword identifiers, not 64-bit action/animation values. */
s32 btlUnitOpeningMotionMode(s32 unused, u8 *unit, s16 skill, s32 openingMode);
s32 btlUnitSlotIsOpen(u8 *action, s16 slotIndex);

/* Boss motion overrides use both the unit and motion selector. A missing
 * override is -1; the timing helpers consume the returned signed halfword. */
s32 btlFormationLookupSlot(u8 *unit, u16 slotIndex);
/* The timing queries and distance helper share that selector domain. */
s16 btlUnitMotionFrames(u8 *unit, u16 motion, f32 rate);
s16 btlUnitMotionFollowFrames(u8 *unit, u16 motion, f32 rate);
s16 btlUnitGetMotionTableFrames(u8 *unit, u16 motion);
f32 btlUnitGetActionAnchorHeight(u8 *source, u8 *unit, u16 actionKind);
s16 btlUnitMotionModelFrames(u8 *unit, u16 motion, f32 rate);
s16 btlUnitMotionHitFrames(u8 *unit, u16 motion, f32 rate, s64 hitOrdinal);

#endif
