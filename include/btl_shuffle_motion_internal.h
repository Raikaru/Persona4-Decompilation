#ifndef BTL_SHUFFLE_MOTION_INTERNAL_H
#define BTL_SHUFFLE_MOTION_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"

/* Layouts shared by the shuffle initializers and their frame-step consumers.
 * Vector tracks occupy 0x60 bytes and rotation tracks 0x6C in each 0xE8 record. */
typedef struct BtlShuffleQuat { f32 x, y, z, w; } BtlShuffleQuat;

typedef struct BtlShuffleBezierPoints {
    RwV3d start, controlA, controlB, end;
} BtlShuffleBezierPoints;

typedef struct BtlShuffleBezierMotion {
    u16 frame, pad02;
    f32 duration, delay;
    RwV3d output, origin;
    BtlShuffleBezierPoints points;
    f32 spread, tangentLength, scale;
} BtlShuffleBezierMotion;

typedef struct BtlShuffleBezierRotation {
    u16 frame, duration, delay, pad06;
    BtlShuffleQuat output, origin;
    BtlShuffleBezierPoints points;
    RwV3d spread;
    f32 tangentLength, scale;
} BtlShuffleBezierRotation;

typedef struct BtlShuffleVectorTrack {
    u16 frame, pad02;
    f32 duration, delay;
    RwV3d output, start, target, displacement;
} BtlShuffleVectorTrack;

/* Cubic tracks copy and evaluate an actual four-element control-point array. */
typedef struct BtlShuffleBezierTrack {
    u16 frame, pad02;
    f32 duration, delay;
    RwV3d output;
    RwV3d points[4];
} BtlShuffleBezierTrack;

typedef struct BtlShuffleOrbitTrack {
    u16 frame, pad02;
    f32 duration, delay;
    RwV3d output;
    f32 startAngle, endAngle;
    RwV3d axis, center, point;
} BtlShuffleOrbitTrack;

typedef struct BtlShuffleQuaternionTrack {
    u16 frame, duration, delay, pad06;
    BtlShuffleQuat output, start, target, middle;
} BtlShuffleQuaternionTrack;

typedef struct BtlShuffleAxisRotationTrack {
    u16 frame, duration, delay, pad06;
    BtlShuffleQuat output, start;
    RwV3d axis;
    f32 startAngle, endAngle;
} BtlShuffleAxisRotationTrack;

typedef struct BtlShuffleByteTrack {
    u8 output, start, target, pad03;
    u16 frame, duration;
} BtlShuffleByteTrack;

typedef struct BtlShuffleSoundCue {
    u8 stream, channel;
    u16 frame, delay;
} BtlShuffleSoundCue;

#endif
