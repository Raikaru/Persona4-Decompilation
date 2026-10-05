#ifndef BTL_CAMERA_SEQUENCE_INTERNAL_H
#define BTL_CAMERA_SEQUENCE_INTERNAL_H

#include "type.h"

struct RwV3d;
struct RtQuat;

/* Controller work fields read by 001b4880 and its 001b5300 update. */
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
u8 *func_001ba530(s32 color, s32 frames);
u8 *func_001ba710(f32 *rotation, s32 frames);
u8 *func_001d3b50(u8 *action);

#endif
