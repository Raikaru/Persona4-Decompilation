#ifndef BTL_CAMERA_SEQUENCE_INTERNAL_H
#define BTL_CAMERA_SEQUENCE_INTERNAL_H

#include "type.h"

struct RwV3d;
struct RtQuat;

/* Phase work passed to the WIN phase handlers (btlMainWinInit/Update) at
 * iGpffffb3ac+0x2FC. The first word is the current phase index, shared with
 * every phase handler (WIN is 0xB). */
typedef struct BtlCameraSequenceWork {
    s32 state;
    s32 field04;
    s32 frame;
    u16 delay;
    u16 duration;
    u16 animationFrames;
    u16 soundFrame;
    s32 interrupted;
    s32 singleUnit;
} BtlCameraSequenceWork;

typedef struct BtlCameraSequenceRotation {
    f32 x, y, z, w;
} BtlCameraSequenceRotation;

/* Camera color and quaternion packet factories return the allocation that
 * their caller subsequently schedules and associates with an action UID. */
u8 *btlColorBlendPacketCreate(s32 color, s32 frames);
u8 *func_001ba710(f32 *rotation, s32 frames);
u8 *btlFormationCreateActionPacket(u8 *action);

/* Camera work predicate: enable bit (bit 0 of +0x0E) read from the camera work;
 * the retail callee reads only its first argument and returns 0 or 1. */
u32 btlCameraIsEnabled(void *camera);

#endif
