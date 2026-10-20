#ifndef BTL_CAMERA_FRAMING_INTERNAL_H
#define BTL_CAMERA_FRAMING_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"

typedef struct BtlUnit BtlUnit;

/* Choose the larger framing radius; equal or unordered inputs select the second. */
static inline f32 btlCameraMaxRadius(f32 first, f32 second)
{
    if (first > second) return first;
    return second;
}

/* Mode-specific work begins at camera+0x100. The rotating frame initializers
 * and updaters agree on these fields; other camera states reuse this storage. */
typedef struct BtlCameraOrbitWork {
    union { f32 yaw; s32 yawBits; } angle;
    RwV3d focus;
    RwV3d direction;
    f32 radius;
    s32 refreshBounds;
} BtlCameraOrbitWork;

/* Shared by the sweep/duel pose builders and their geometry refresh callbacks. */
typedef struct BtlCameraFocusWork {
    RwV3d focus;
    f32 radius;
} BtlCameraFocusWork;

/* ApplyPreset retains both horizontal side decisions between updates. */
typedef struct BtlCameraPresetWork {
    s32 target;
    s32 actorSide;
    s32 rightSide;
} BtlCameraPresetWork;

/* WaitMotionFrames initializes the target address and two signed frame counters. */
typedef struct BtlCameraMotionWaitWork {
    s32 targetAction;
    u8 pad04[8];
    s16 elapsed;
    s16 duration;
} BtlCameraMotionWaitWork;

/* Status framing classifies the target, then tracks the selected action. */
typedef struct BtlCameraStatusWork {
    u8 *action;
    u16 genusMask;
    u16 groupMode;
} BtlCameraStatusWork;

/* Split framing keeps the target action and center at +0x100/+0x104.
 * SelectMode/UpdateMode own +0x110/+0x114; pose and sweep builders retain
 * their target actions separately at +0x124 and +0x128. */
typedef struct BtlCameraActionWork {
    u8 *target;
    RwV3d center;
    u16 mode;
    u8 pad12[2];
    s32 blocked;
    u8 pad18[0x0C];
    u8 *geometryTarget;
    u8 *sweepTarget;
} BtlCameraActionWork;

/* Formation rows are 0xE0 bytes: four party slots, five enemy slots and
 * three capacity counters. AssignFormationSlots proves the 0x18 slot stride. */
typedef struct BtlCameraFormationSlot {
    u8 enabled;
    u8 pad01[3];
    f32 x;
    f32 z;
    f32 unk0C;
    f32 radius;
    f32 height;
} BtlCameraFormationSlot;

typedef struct BtlCameraFormation {
    BtlCameraFormationSlot party[4];
    BtlCameraFormationSlot enemies[5];
    u16 capacity[3];
    u8 padDE[2];
} BtlCameraFormation;

/* The formation initializer clears this complete 0x24-byte occupancy block
 * at battle+0xA74; genus selects the party or enemy array. */
typedef struct BtlCameraFormationOccupancy {
    s32 party[4];
    s32 enemies[5];
} BtlCameraFormationOccupancy;

/* NudgeUnitPair reads two unit pointers, a separation and the movement mask. */
typedef struct BtlCameraUnitPair {
    BtlUnit *first;
    BtlUnit *second;
    f32 separation;
    u16 flags;
} BtlCameraUnitPair;

typedef char BtlCameraFormationSlotSizeCheck[sizeof(BtlCameraFormationSlot) == 0x18 ? 1 : -1];
typedef char BtlCameraFormationSizeCheck[sizeof(BtlCameraFormation) == 0xE0 ? 1 : -1];

#endif
