/* Original translation unit btlShuffleCalc.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "sdk_snd_internal.h"
#include "btl_shuffle_motion_internal.h"
#include "rw_camera_internal.h"

/* RwCamera.viewWindow starts at offset 0x68 and is read through a byte-pointer base. */
typedef struct BtlShuffleCameraWindow { f32 x, y; } BtlShuffleCameraWindow;

extern void kAssertFail(const void *file, u32 line);
extern u32 D_0064E9C0[];
extern u8 *kwlnGetCamera(void);
extern u8 *func_003e9700(s32 a0);
extern void func_003e42a0(void *a0, void *a1, void *a2);
extern f32 RwV3dLength(void *vector);
extern void btlShuffleCalcRotatePointAroundAxis(u8 *center, u8 *axis, u8 *point, f32 angle, u8 *output);
extern void RwV3dNormalize(f32 *a0, f32 *a1);
extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
extern void func_003dcc70(void *a0, void *a1, void *a2);
extern s32 func_003e0f80(void);
extern void RwMatrixRotate(s32 a0, void *a1, f32 fparg0, s32 a2);
extern void func_003e0f40(s32 a0);
extern f32 D_00761144;
extern f32 D_00761148;
extern f32 D_00761150;
extern f32 D_00761434;
extern f32 D_00761438;
extern f32 D_007614E8;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
extern f32 D_00761470;
f32 btlShuffleCalcEase(f32 depth);
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef BtlShuffleVec3 ShuffleVec3;
typedef struct { f32 v[9]; s32 flag; } ShuffleOut;
typedef struct ShuffleCalcUnit {
    u16 count;
    u16 pad02;
    f32 duration;
    f32 rate;
    f32 output[3];
    f32 start[3];
    f32 target[3];
    f32 scale;
} ShuffleCalcUnit;
f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);

/* Retail loads the constant 100.0f into its register before the camera value, and a named local
 * keeps that order. Retail halves with both / 2 and >> 1. */
// FUN_00371260
void btlShuffleCalcResetPose(u8 *output) {
    s32 viewport[8];
    u8 *cameraWindow;
    f32 scale;
    f32 depth;

    depth = 100.0f;
    cameraWindow = kwlnGetCamera() + 0x68;
    if (((BtlShuffleCameraWindow *)cameraWindow)->x * depth <= 0.0f) {
        kAssertFail(D_0064E9C0, 0x109);
    }
    func_003e8970(&viewport[0], func_003e89c0());
    scale = (60.0f * (f32)(viewport[0] / 2)) / (depth * ((BtlShuffleCameraWindow *)cameraWindow)->x);
    ((RwV3d *)output)->x = scale * (((BtlShuffleCameraWindow *)cameraWindow)->x * (1.0f + (-320.0f / (f32)(viewport[0] >> 1))));
    ((RwV3d *)output)->y = scale * (((BtlShuffleCameraWindow *)cameraWindow)->y * (1.0f + (-224.0f / (f32)(viewport[1] >> 1))));
    ((RwV3d *)output)->z = scale;
}
/* Construct the default projected position at depth 84 using the camera view window. */
// FUN_003713B0
void btlShuffleCalcResetTrack(u8 *output) {
    s32 viewport[8];
    u8 *cameraWindow;
    f32 scale;
    f32 depth;

    depth = 84.0f;
    cameraWindow = kwlnGetCamera() + 0x68;
    if (((BtlShuffleCameraWindow *)cameraWindow)->x * depth <= 0.0f) {
        kAssertFail(D_0064E9C0, 0x109);
    }
    func_003e8970(&viewport[0], func_003e89c0());
    scale = (60.0f * (f32)(viewport[0] / 2)) / (depth * ((BtlShuffleCameraWindow *)cameraWindow)->x);
    ((RwV3d *)output)->x = scale * (((BtlShuffleCameraWindow *)cameraWindow)->x * (1.0f + (-320.0f / (f32)(viewport[0] >> 1))));
    ((RwV3d *)output)->y = scale * (((BtlShuffleCameraWindow *)cameraWindow)->y * (1.0f + (-224.0f / (f32)(viewport[1] >> 1))));
    ((RwV3d *)output)->z = scale;
}
/* Project screen coordinates onto the camera plane at the supplied depth. */
// FUN_00371500
void btlShuffleCalcScaleStep(u8 *screen, f32 depth, u8 *output) {
    s32 viewport[8];
    u8 *cameraWindow;

    cameraWindow = kwlnGetCamera() + 0x68;
    func_003e8970(&viewport[0], func_003e89c0());
    ((RwV3d *)output)->x = depth * (((BtlShuffleCameraWindow *)cameraWindow)->x * (1.0f + (-(((RwV3d *)screen)->x) / (f32)(viewport[0] >> 1))));
    ((RwV3d *)output)->y = depth * (((BtlShuffleCameraWindow *)cameraWindow)->y * (1.0f + (-(((RwV3d *)screen)->y) / (f32)(viewport[1] >> 1))));
    ((RwV3d *)output)->z = depth;
}

/* Project screen coordinates using the camera-derived scale for the supplied depth. */
// FUN_003715E0
void btlShuffleCalcStepPose(u8 *screen, u8 *output, f32 depth) {
    f32 scale;
    s32 viewport[8];
    u8 *cameraWindow;

    scale = btlShuffleCalcEase(depth);
    cameraWindow = kwlnGetCamera() + 0x68;
    func_003e8970(&viewport[0], func_003e89c0());
    ((RwV3d *)output)->x = scale * (((BtlShuffleCameraWindow *)cameraWindow)->x * (1.0f + (-(((RwV3d *)screen)->x) / (f32)(viewport[0] >> 1))));
    ((RwV3d *)output)->y = scale * (((BtlShuffleCameraWindow *)cameraWindow)->y * (1.0f + (-(((RwV3d *)screen)->y) / (f32)(viewport[1] >> 1))));
    ((RwV3d *)output)->z = scale;
}

/* Return viewport half-width divided by depth times the horizontal camera view window. */
// FUN_003716D0
f32 btlShuffleCalcEase(f32 depth) {
    s32 viewport[8];
    u8 *cameraWindow;

    cameraWindow = kwlnGetCamera() + 0x68;
    if (depth * ((BtlShuffleCameraWindow *)cameraWindow)->x <= 0.0f) {
        kAssertFail(D_0064E9C0, 0x145);
    }
    func_003e8970(&viewport[0], func_003e89c0());
    return (f32)(viewport[0] / 2) / (depth * ((BtlShuffleCameraWindow *)cameraWindow)->x);
}
/* Transform a point by the active camera frame matrix. */
// FUN_00371780
void btlShuffleCalcLookAt(u8 *output, u8 *point) {
    /* The camera frame is stored as a raw address word, so it is read as an integer rather than a
     * pointer. */
    func_003e42a0(output, point, func_003e9700((s32)((RwCamera *)kwlnGetCamera())->object.object.parent));
}

/* Convert a camera-space point to screen coordinates and report whether it is inside 640 by 448. */
// FUN_003717E0
s32 btlShuffleCalcUpdateSpeed(u8 *point, u8 *screen) {
    s32 viewport[8];
    BtlShuffleCameraWindow *cameraWindow;
    f32 x;
    f32 y;
    RwV3d *pointVector = (RwV3d *)point;
    RwV3d *screenVector = (RwV3d *)screen;

    cameraWindow = (BtlShuffleCameraWindow *)(kwlnGetCamera() + 0x68);
    if (pointVector->z <= 0.0f || cameraWindow->x <= 0.0f ||
        cameraWindow->y <= 0.0f) {
        kAssertFail(D_0064E9C0, 0x15F);
    }
    func_003e8970(&viewport[0], func_003e89c0());
    x = (f32)(viewport[0] / 2) *
        -((pointVector->x / pointVector->z) / cameraWindow->x - 1.0f);
    screenVector->x = x;
    y = (f32)(viewport[1] / 2) *
        -((pointVector->y / pointVector->z) / cameraWindow->y - 1.0f);
    screenVector->y = y;
    if (x >= 0.0f && x < 640.0f && y >= 0.0f && y < 448.0f) {
        return 1;
    }
    return 0;
}
/* Initialize a vector interpolation, using the existing output when no start is supplied. */
// FUN_00371990
void btlShuffleCalcSetBlend(u8 *state, u8 *start, u8 *target, f32 delay, f32 duration) {
    *(s16 *)&((BtlShuffleVectorTrack *)state)->frame = 0;
    ((BtlShuffleVectorTrack *)state)->duration = duration;
    ((BtlShuffleVectorTrack *)state)->delay = delay;
    if (start != NULL) {
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->start = *(ShuffleVec3 *)&((RwV3d *)start)->x;
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->output = *(ShuffleVec3 *)&((RwV3d *)start)->x;
    } else {
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->start = *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->output;
    }
    if (target == NULL) {
        kAssertFail(&D_0064E9C0, 0x17C);
    }
    *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->target = *(ShuffleVec3 *)&((RwV3d *)target)->x;
}

/* Separate difference locals keep retail's subtract, multiply, add order, and the in-place count
 * increment reproduces retail's reload of the count. Advance a vector interpolation with the
 * requested linear or sinusoidal timing curve. */
// FUN_00371A60
s32 btlShuffleCalcSelectFrame(u8 *state, s32 curve) {
    f32 half;
    f32 zero;
    f32 progress;
    f32 startX;
    f32 diff0;
    f32 diff1;
    f32 diff2;
    BtlShuffleVectorTrack *track = (BtlShuffleVectorTrack *)state;

    zero = 0.0f;
    half = (f32)(u32)track->frame;
    if (!(half < track->duration)) {
        return 1;
    }
    track->frame += 1;
    half = (f32)(u32)track->frame;
    progress = btlShuffleCalcWave(half + zero, track->delay, track->duration, curve);
    startX = track->start.x;
    diff0 = track->target.x - startX;
    diff1 = track->target.y - track->start.y;
    diff2 = track->target.z - track->start.z;
    diff0 = diff0 * progress;
    diff1 = diff1 * progress;
    diff2 = diff2 * progress;
    track->output.x = diff0 + startX;
    track->output.y = diff1 + track->start.y;
    track->output.z = diff2 + track->start.z;
    return 0;
}
/* Initialize cubic interpolation timing and copy all four control points. */
// FUN_00371BA0
void btlShuffleCalcStoreTiming(u8 *state, u8 *points, u32 delay, u32 duration) {
    f32 f0;
    s32 i;

    *(s16 *)&((BtlShuffleBezierTrack *)state)->frame = 0;
    if (duration >= 0) {
        f0 = (f32)duration;
    } else {
        duration = (duration >> 1) | (duration & 1);
        f0 = (f32)(s32)duration;
        f0 += f0;
    }
    ((BtlShuffleBezierTrack *)state)->duration = f0;
    if (delay >= 0) {
        f0 = (f32)delay;
    } else {
        delay = (delay >> 1) | (delay & 1);
        f0 = (f32)(s32)delay;
        f0 += f0;
    }
    ((BtlShuffleBezierTrack *)state)->delay = f0;
    for (i = 0; i < 4; i++) {
        ((BtlShuffleBezierTrack *)state)->points[i] = ((ShuffleVec3 *)points)[i];
    }
}
/* Advance a cubic Bezier vector track with linear normalized timing. */
// FUN_00371C70
s32 btlShuffleCalcTimeFromFrame(u8 *state) {
    f32 progress;
    f32 frameValue;
    f32 inv;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    BtlShuffleBezierTrack *track = (BtlShuffleBezierTrack *)state;

    frameValue = (f32)(u16)track->frame;
    if (!(frameValue < track->duration)) {
        return 1;
    }
    track->frame += 1;
    progress = (f32)(u16)track->frame;
    progress = btlShuffleCalcWave(progress, track->delay, track->duration, 0);
    inv = 1.0f - progress;

    f6 = progress * (track->points[3].x * progress);
    f5 = progress * (3.0f * track->points[2].x * inv);
    f4 = inv * (track->points[0].x * inv);
    f3 = inv * (3.0f * track->points[1].x * inv);
    track->output.x = inv * f4 + progress * f3 + progress * f5 + progress * f6;

    f6 = progress * (track->points[3].y * progress);
    f5 = progress * (3.0f * track->points[2].y * inv);
    f4 = inv * (track->points[0].y * inv);
    f3 = inv * (3.0f * track->points[1].y * inv);
    track->output.y = inv * f4 + progress * f3 + progress * f5 + progress * f6;

    f6 = progress * (track->points[3].z * progress);
    f5 = progress * (3.0f * track->points[2].z * inv);
    f4 = inv * (track->points[0].z * inv);
    f3 = inv * (3.0f * track->points[1].z * inv);
    track->output.z = inv * f4 + progress * f3 + progress * f5 + progress * f6;
    return 0;
}
/* Initialize an orbit track from its axis, center, point, and angle range. */
// FUN_00371E50
void btlShuffleCalcSetVectors(u8 *state, u32 duration, ShuffleVec3 *axis, ShuffleVec3 *center, ShuffleVec3 *point, f32 startAngle, f32 endAngle) {
    ShuffleVec3 axisCopy;
    ShuffleVec3 centerCopy;
    ShuffleVec3 pointCopy;
    f32 f0;

    axisCopy = *axis;
    centerCopy = *center;
    pointCopy = *point;
    *(s16 *)&((BtlShuffleOrbitTrack *)state)->frame = 0;
    if (duration >= 0) {
        f0 = (f32)duration;
    } else {
        duration = (duration >> 1) | (duration & 1);
        f0 = (f32)(s32)duration;
        f0 += f0;
    }
    ((BtlShuffleOrbitTrack *)state)->duration = f0;
    ((BtlShuffleOrbitTrack *)state)->startAngle = startAngle;
    ((BtlShuffleOrbitTrack *)state)->endAngle = endAngle;
    *(ShuffleVec3 *)&((BtlShuffleOrbitTrack *)state)->axis = axisCopy;
    *(ShuffleVec3 *)&((BtlShuffleOrbitTrack *)state)->center = centerCopy;
    *(ShuffleVec3 *)&((BtlShuffleOrbitTrack *)state)->point = pointCopy;
}
/* Sample an orbit at a fractional frame offset without advancing the track. */
// FUN_00371F40
void btlShuffleCalcRotateVector(u8 *state, f32 frameOffset, u8 *output) {
    f32 angle;
    s32 matrix;
    f32 relativePoint[3];
    u32 value;
    f32 half;
    BtlShuffleOrbitTrack *track = (BtlShuffleOrbitTrack *)state;
    RwV3d *outputVector = (RwV3d *)output;

    if (track->duration <= 0.0f) {
        kAssertFail(&D_0064E9C0, 0x1EF);
    }
    value = track->frame;
    if (value >= 0) {
        half = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        half = (f32)(s32)value;
        half += half;
    }
    angle = track->startAngle + ((half + frameOffset) / track->duration) * (track->endAngle - track->startAngle);
    matrix = func_003e0f80();
    relativePoint[0] = track->point.x - track->center.x;
    relativePoint[1] = track->point.y - track->center.y;
    relativePoint[2] = track->point.z - track->center.z;
    RwMatrixRotate(matrix, state + 0x20, angle, 0);
    func_003e42a0(output, &relativePoint[0], (void *)matrix);
    outputVector->x += track->center.x;
    outputVector->y += track->center.y;
    outputVector->z += track->center.z;
    func_003e0f40(matrix);
}
/* Advance an orbit track and rotate its point around the stored center. */
// FUN_003720C0
s32 btlShuffleCalcAdvanceTrack(u8 *state) {
    f32 frameValue;
    f32 count;
    f32 ratio;
    f32 startv;
    f32 diff;
    f32 zero;
    BtlShuffleOrbitTrack *track = (BtlShuffleOrbitTrack *)state;

    frameValue = (f32)(u16)track->frame;
    if (!(frameValue < track->duration)) {
        return 1;
    }
    track->frame += 1;
    if (track->duration <= 0.0f) {
        kAssertFail(&D_0064E9C0, 0x1EF);
    }
    startv = track->startAngle;
    count = (f32)(u16)track->frame;
    zero = 0.0f;
    ratio = count + zero;
    ratio = ratio / track->duration;
    diff = track->endAngle - startv;
    btlShuffleCalcRotatePointAroundAxis(
        state + 0x2C,
        state + 0x20,
        state + 0x38,
        0.0f + startv + ratio * diff,
        state + 0xC);
    return 0;
}
/* Advance a vector track with the additional quadratic displacement term. The diff locals are
 * computed first, so the subtraction happens separately from the multiply, as in retail. */
// FUN_00372200
s32 btlShuffleCalcFinishTrack(u8 *state) {
    f32 t;
    f32 t2;
    f32 d0;
    f32 d1;
    f32 d2;
    f32 diff0;
    f32 diff1;
    f32 diff2;
    BtlShuffleVectorTrack *track = (BtlShuffleVectorTrack *)state;

    d2 = track->duration;
    t = (f32)(u16)track->frame;
    if (!(t < d2)) {
        return 1;
    }
    if (track->duration <= 0.0f) {
        kAssertFail(&D_0064E9C0, 0x22F);
    }
    t = (f32)(u16)(track->frame += 1);
    t = t + 0.0f;
    d2 = track->duration;
    t = t / d2;
    t2 = 2.0f * t;
    t2 = t2 * t;
    t2 = t - t2;
    d0 = track->displacement.x * t2;
    d1 = track->displacement.y * t2;
    d2 = track->displacement.z * t2;
    diff0 = track->target.x - track->start.x;
    diff1 = track->target.y - track->start.y;
    diff2 = track->target.z - track->start.z;
    diff0 = diff0 * t;
    diff1 = diff1 * t;
    diff2 = diff2 * t;
    track->output.x = diff0 + track->start.x;
    track->output.y = diff1 + track->start.y;
    track->output.z = diff2 + track->start.z;
    track->output.x += d0;
    track->output.y += d1;
    track->output.z += d2;
    return 0;
}
/* Initialize vector timing, start and target positions, and the displacement magnitude. */
// FUN_003723A0
void btlShuffleCalcScheduleMove(u8 *state, u16 delay, u16 duration, u8 *start, u8 *target, f32 displacement) {
    *(s16 *)&((BtlShuffleVectorTrack *)state)->frame = 0;
    ((BtlShuffleVectorTrack *)state)->duration = duration;
    ((BtlShuffleVectorTrack *)state)->delay = delay;
    if (start != NULL) {
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->start = *(ShuffleVec3 *)&((RwV3d *)start)->x;
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->output = *(ShuffleVec3 *)&((RwV3d *)start)->x;
    } else {
        *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->start = *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->output;
    }
    if (target == NULL) {
        kAssertFail(&D_0064E9C0, 0x24F);
    }
    *(ShuffleVec3 *)&((BtlShuffleVectorTrack *)state)->target = *(ShuffleVec3 *)&((RwV3d *)target)->x;
    ((ShuffleCalcUnit *)state)->scale = displacement;
}
/* Advance a vector track using a normalized direction scaled by the stored displacement. */
// FUN_003724F0
/* measured: retail's code shape needs copy propagation disabled for this function; restructured
 * locals or branches do not reproduce it. */
#pragma opt_propagation off
s32 btlShuffleCalcUnitStep(ShuffleCalcUnit *unit) {
    u32 value2;
    u16 *count;
    u32 value;
    f32 direction[3];
    f32 displacement[3];
    f32 progress;
    f32 scaleValue;
    f32 component;
    f32 nextFrame;
    f32 frameValue;

    count = &unit->count;
    value = *count;
    if (value >= 0) {
        frameValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        frameValue = (f32)value;
        frameValue += frameValue;
    }
    if (!(frameValue < unit->duration)) {
        return 1;
    }
    unit->count = (u16)(unit->count + 1);
    value2 = unit->count;
    if (value2 >= 0) {
        nextFrame = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        nextFrame = (f32)value2;
        nextFrame += nextFrame;
    }
    component = unit->rate;
    scaleValue = unit->duration;
    progress = btlShuffleCalcWave(nextFrame, component, scaleValue, 0);
    direction[0] = unit->start[0] - unit->target[0];
    direction[1] = unit->start[1] - unit->target[1];
    direction[2] = unit->start[2] - unit->target[2];
    RwV3dNormalize(&displacement[0], &direction[0]);
    component = displacement[0];
    scaleValue = unit->scale;
    displacement[0] = component * scaleValue;
    component = displacement[1];
    scaleValue = unit->scale;
    displacement[1] = component * scaleValue;
    component = displacement[2];
    scaleValue = unit->scale;
    displacement[2] = component * scaleValue;
    component = displacement[0] + direction[0];
    unit->output[0] = unit->start[0] +
        (displacement[0] * progress - progress * (progress * component));
    component = displacement[1] + direction[1];
    unit->output[1] = unit->start[1] +
        (displacement[1] * progress - progress * (progress * component));
    component = displacement[2] + direction[2];
    unit->output[2] = unit->start[2] +
        (displacement[2] * progress - progress * (progress * component));
    return 0;
}
/* measured: propagation is turned back on once this body is done. */
#pragma opt_propagation on
/* Advance the alternate quadratic vector displacement curve. */
// FUN_003726B0
/* measured: retail does not propagate copies in this function, so copy propagation must stay off. */
#pragma opt_propagation off
s32 btlShuffleCalcUnitStepB(ShuffleCalcUnit *unit) {
    u32 value2;
    u16 *count;
    u32 value;
    f32 direction[3];
    f32 displacement[3];
    f32 scaleValue;
    f32 component;
    f32 progress;
    f32 nextFrame;
    f32 frameValue;

    count = &unit->count;
    value = *count;
    if (value >= 0) {
        frameValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        frameValue = (f32)value;
        frameValue += frameValue;
    }
    if (!(frameValue < unit->duration)) {
        return 1;
    }
    unit->count = (u16)(unit->count + 1);
    value2 = unit->count;
    if (value2 >= 0) {
        nextFrame = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        nextFrame = (f32)value2;
        nextFrame += nextFrame;
    }
    scaleValue = unit->rate;
    progress = btlShuffleCalcWave(nextFrame, scaleValue, unit->duration, 0);
    direction[0] = unit->start[0] - unit->target[0];
    direction[1] = unit->start[1] - unit->target[1];
    direction[2] = unit->start[2] - unit->target[2];
    RwV3dNormalize(&displacement[0], &direction[0]);
    component = displacement[0];
    scaleValue = unit->scale;
    displacement[0] = component * scaleValue;
    component = displacement[1];
    displacement[1] = component * scaleValue;
    component = displacement[2];
    displacement[2] = component * scaleValue;
    unit->output[0] = unit->start[0] +
        (progress * (displacement[0] - direction[0]) - progress * (displacement[0] * progress));
    unit->output[1] = unit->start[1] +
        (progress * (displacement[1] - direction[1]) - progress * (displacement[1] * progress));
    unit->output[2] = unit->start[2] +
        (progress * (displacement[2] - direction[2]) - progress * (displacement[2] * progress));
    return 0;
}
/* measured: propagation is turned back on once this body is done. */
#pragma opt_propagation on
/* Initialize quaternion interpolation, retaining the current output if no start is supplied. */
// FUN_00372870
void btlShuffleCalcSetQuat(u8 *state, u16 delay, u16 duration, u8 *start, ShuffleVec4 *target) {
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->frame = 0;
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->duration = duration;
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->delay = delay;
    if (start != NULL) {
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->start = *(ShuffleVec4 *)start;
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->output = *(ShuffleVec4 *)start;
    } else {
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->start = *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->output;
    }
    if (target == NULL) {
        kAssertFail(&D_0064E9C0, 0x2B6);
    }
    *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->target = *(ShuffleVec4 *)target;
}

/* Advance quaternion interpolation with the helper-provided angular weights. */
// FUN_00372960
s32 btlShuffleCalcUpdateArc(u8 *state) {
    u32 v3;
    u32 v2;
    u32 value;
    u32 value2;
    u32 value3;
    f32 progress;
    f32 delay;
    f32 duration;
    f32 weight;
    f32 startWeight;
    f32 frameValue;
    f32 polynomial;
    f32 angleSquared;
    f32 angle;
    ShuffleOut out;
    BtlShuffleQuaternionTrack *track = (BtlShuffleQuaternionTrack *)state;

    v3 = track->frame;
    v2 = track->duration;
    if (!((s32)v3 < (s32)v2)) {
        return 1;
    }
    track->frame = v3 + 1;
    value = track->frame;
    if (value >= 0) {
        progress = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        progress = (f32)value;
        progress += progress;
    }
    value2 = track->delay;
    if (value2 >= 0) {
        delay = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        delay = (f32)value2;
        delay += delay;
    }
    value3 = track->duration;
    if (value3 >= 0) {
        duration = (f32)value3;
    } else {
        value3 = (value3 >> 1) | (value3 & 1);
        duration = (f32)value3;
        duration += duration;
    }
    weight = btlShuffleCalcWave(progress, delay, duration, 0);
    func_003dcc70(state + 0x18, state + 0x28, &out);

    if (weight <= 0.0f) {
        angleSquared = track->start.x;
        polynomial = track->start.y;
        frameValue = track->start.z;
        startWeight = track->start.w;
        track->output.x = angleSquared;
        track->output.y = polynomial;
        track->output.z = frameValue;
        track->output.w = startWeight;
    } else if (1.0f <= weight) {
        angleSquared = track->target.x;
        polynomial = track->target.y;
        frameValue = track->target.z;
        startWeight = track->target.w;
        track->output.x = angleSquared;
        track->output.y = polynomial;
        track->output.z = frameValue;
        track->output.w = startWeight;
    } else {
        startWeight = 1.0f - weight;
        if (out.flag == 0) {
            angle = startWeight * out.v[8];
            angleSquared = angle * angle;
            polynomial = D_007614E8 * angleSquared + D_00761144;
            polynomial = angleSquared * polynomial + D_00761148;
            polynomial = angleSquared * polynomial + D_00761434;
            polynomial = angleSquared * polynomial + D_00761150;
            frameValue = angleSquared * polynomial + D_00761438;
            polynomial = angleSquared * angle;
            startWeight = polynomial * frameValue + angle;

            angle = weight * out.v[8];
            angleSquared = angle * angle;
            frameValue = D_007614E8 * angleSquared + D_00761144;
            frameValue = angleSquared * frameValue + D_00761148;
            frameValue = angleSquared * frameValue + D_00761434;
            frameValue = angleSquared * frameValue + D_00761150;
            polynomial = angleSquared * frameValue + D_00761438;
            frameValue = angleSquared * angle;
            weight = frameValue * polynomial + angle;
        }
        track->output.x = out.v[0] * startWeight;
        track->output.y = out.v[1] * startWeight;
        track->output.z = out.v[2] * startWeight;
        track->output.x = track->output.x + out.v[4] * weight;
        track->output.y = track->output.y + out.v[5] * weight;
        track->output.z = track->output.z + out.v[6] * weight;
        track->output.w = out.v[3] * startWeight + out.v[7] * weight;
    }
    return 0;
}

/* Initialize quaternion timing and its start, midpoint, and target rotations. */
// FUN_00372C30
void btlShuffleCalcSetKeyframe(u8 *state, u16 delay, u16 duration, u8 *start, u8 *target, u8 *middle) {
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->frame = 0;
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->duration = duration;
    *(s16 *)&((BtlShuffleQuaternionTrack *)state)->delay = delay;
    if (start != NULL) {
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->start = *(ShuffleVec4 *)start;
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->output = *(ShuffleVec4 *)start;
    } else {
        *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->start = *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->output;
    }
    if (middle == NULL) {
        kAssertFail(&D_0064E9C0, 0x2E0);
    }
    if (target == NULL) {
        kAssertFail(&D_0064E9C0, 0x2E1);
    }
    *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->middle = *(ShuffleVec4 *)middle;
    *(ShuffleVec4 *)&((BtlShuffleQuaternionTrack *)state)->target = *(ShuffleVec4 *)target;
}

/* Interpolate through the midpoint quaternion, one half of the duration per segment. */
// FUN_00372D60
s32 btlShuffleCalcUpdateCurve(u8 *state) {
    ShuffleOut out;
    f32 B[4];
    f32 A[4];
    u32 v3;
    u32 v2;
    u32 value;
    u32 value2;
    u32 value3;
    f32 progress;
    f32 delay;
    f32 duration;
    f32 weight;
    f32 startWeight;
    f32 frameValue;
    f32 polynomial;
    f32 angleSquared;
    f32 angle;
    BtlShuffleQuaternionTrack *track = (BtlShuffleQuaternionTrack *)state;
    v3 = track->frame;
    v2 = track->duration;
    if (!((s32)v3 < (s32)v2)) {
        return 1;
    }
    track->frame = v3 + 1;
    value = track->frame;
    if (value >= 0) {
        progress = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        progress = (f32)value;
        progress += progress;
    }
    value2 = track->delay;
    if (value2 >= 0) {
        delay = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        delay = (f32)value2;
        delay += delay;
    }
    value3 = track->duration;
    if (value3 >= 0) {
        duration = (f32)value3;
    } else {
        value3 = (value3 >> 1) | (value3 & 1);
        duration = (f32)value3;
        duration += duration;
    }
    weight = btlShuffleCalcWave(progress, delay, duration, 0);
    if (weight < 0.5f) {
        *(ShuffleVec4 *)B = *(ShuffleVec4 *)&track->start;
        *(ShuffleVec4 *)A = *(ShuffleVec4 *)&track->middle;
        weight = weight * 2.0f;
    } else {
        *(ShuffleVec4 *)B = *(ShuffleVec4 *)&track->middle;
        *(ShuffleVec4 *)A = *(ShuffleVec4 *)&track->target;
        weight = 2.0f * (weight - 0.5f);
    }
    func_003dcc70(B, A, &out);

    if (weight <= 0.0f) {
        *(ShuffleVec4 *)&track->output = *(ShuffleVec4 *)B;
    } else if (1.0f <= weight) {
        *(ShuffleVec4 *)&track->output = *(ShuffleVec4 *)A;
    } else {
        startWeight = 1.0f - weight;
        if (out.flag == 0) {
            angle = startWeight * out.v[8];
            angleSquared = angle * angle;
            polynomial = D_007614E8 * angleSquared + D_00761144;
            polynomial = angleSquared * polynomial + D_00761148;
            polynomial = angleSquared * polynomial + D_00761434;
            polynomial = angleSquared * polynomial + D_00761150;
            frameValue = angleSquared * polynomial + D_00761438;
            polynomial = angleSquared * angle;
            startWeight = polynomial * frameValue + angle;

            angle = weight * out.v[8];
            angleSquared = angle * angle;
            frameValue = D_007614E8 * angleSquared + D_00761144;
            frameValue = angleSquared * frameValue + D_00761148;
            frameValue = angleSquared * frameValue + D_00761434;
            frameValue = angleSquared * frameValue + D_00761150;
            polynomial = angleSquared * frameValue + D_00761438;
            frameValue = angleSquared * angle;
            weight = frameValue * polynomial + angle;
        }
        track->output.x = out.v[0] * startWeight;
        track->output.y = out.v[1] * startWeight;
        track->output.z = out.v[2] * startWeight;
        track->output.x = track->output.x + out.v[4] * weight;
        track->output.y = track->output.y + out.v[5] * weight;
        track->output.z = track->output.z + out.v[6] * weight;
        track->output.w = out.v[3] * startWeight + out.v[7] * weight;
    }
    return 0;
}

/* Initialize an axis-angle rotation track from the current quaternion and angle range. */
// FUN_003730F0
void btlShuffleCalcSetCurveSample(u8 *state, u16 delay, u16 duration, const ShuffleVec3 *axis, f32 startAngle, f32 endAngle) {
    ShuffleVec3 axisCopy;

    axisCopy = *axis;
    ((BtlShuffleAxisRotationTrack *)state)->frame = 0;
    ((BtlShuffleAxisRotationTrack *)state)->duration = duration;
    ((BtlShuffleAxisRotationTrack *)state)->delay = delay;
    *(ShuffleVec4 *)&((BtlShuffleAxisRotationTrack *)state)->start = *(ShuffleVec4 *)&((BtlShuffleAxisRotationTrack *)state)->output;
    *(ShuffleVec3 *)&((BtlShuffleAxisRotationTrack *)state)->axis = axisCopy;
    ((BtlShuffleAxisRotationTrack *)state)->startAngle = startAngle;
    ((BtlShuffleAxisRotationTrack *)state)->endAngle = endAngle;
}

/* Advance the axis-angle track and compose its rotation with the saved quaternion. */
// FUN_00373170
s32 btlShuffleCalcUpdateBounce(u8 *state) {
    f32 rotation[4];
    f32 progress;
    f32 delay;
    f32 duration;
    f32 t;
    u32 v3;
    u32 v2;
    u32 value;
    u32 value2;
    u32 value3;
    BtlShuffleAxisRotationTrack *track = (BtlShuffleAxisRotationTrack *)state;

    v3 = track->frame;
    v2 = track->duration;
    if (!((s32)v3 < (s32)v2)) {
        return 1;
    }
    track->frame = v3 + 1;
    value = track->frame;
    if (value >= 0) {
        progress = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        progress = (f32)value;
        progress += progress;
    }
    value2 = track->delay;
    if (value2 >= 0) {
        delay = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        delay = (f32)value2;
        delay += delay;
    }
    value3 = track->duration;
    if (value3 >= 0) {
        duration = (f32)value3;
    } else {
        value3 = (value3 >> 1) | (value3 & 1);
        duration = (f32)value3;
        duration += duration;
    }
    t = btlShuffleCalcWave(progress, delay, duration, 0);
    func_003dc740(&rotation[0], state + 0x28, 0, 0.0f + track->startAngle + t * (track->endAngle - track->startAngle));
    track->output.w = track->start.w * rotation[3] - (track->start.x * rotation[0] + track->start.y * rotation[1] + track->start.z * rotation[2]);
    track->output.x = track->start.y * rotation[2] - track->start.z * rotation[1];
    track->output.y = track->start.z * rotation[0] - track->start.x * rotation[2];
    track->output.z = track->start.x * rotation[1] - track->start.y * rotation[0];
    track->output.x = 0.0f + track->output.x + rotation[0] * track->start.w;
    track->output.y = 0.0f + track->output.y + rotation[1] * track->start.w;
    track->output.z = 0.0f + track->output.z + rotation[2] * track->start.w;
    track->output.x = 0.0f + track->output.x + track->start.x * rotation[3];
    track->output.y = 0.0f + track->output.y + track->start.y * rotation[3];
    track->output.z = 0.0f + track->output.z + track->start.z * rotation[3];
    return 0;
}

/* Initialize a byte interpolation with start, target, and frame duration. */
// FUN_003733D0
void btlShuffleCalcSetFrameRange(u8 *state, s16 duration, s8 start, s8 target) {
    ((BtlShuffleByteTrack *)state)->frame = 0;
    ((BtlShuffleByteTrack *)state)->duration = duration;
    ((BtlShuffleByteTrack *)state)->start = start;
    ((BtlShuffleByteTrack *)state)->output = start;
    ((BtlShuffleByteTrack *)state)->target = target;
}

/* Advance a byte interpolation and report when its frame duration is exhausted. */
// FUN_003733F0
s32 btlShuffleCalcGetFrameRange(u8 *state) {
    f32 difference;
    f32 durationOrOutput;
    f32 progress;
    f32 frameOrBase;
    u32 base;
    s32 diff;
    BtlShuffleByteTrack *track = (BtlShuffleByteTrack *)state;

    if ((s32)track->frame >= (s32)track->duration) {
        return 1;
    }
    if ((s32)track->duration <= 0) {
        kAssertFail(&D_0064E9C0, 0x344);
    }
    durationOrOutput = (f32)(u16)track->duration;
    frameOrBase = (f32)(u16)(track->frame += 1);
    progress = frameOrBase / durationOrOutput;
    base = track->start;
    diff = (s32)track->target - (s32)base;
    difference = (f32)(s32)diff;
    frameOrBase = (f32)(u32)base;
    durationOrOutput = 0.0f + frameOrBase + progress * difference;
    track->output = (u8)durationOrOutput;
    return 0;
}

/* Schedule a sound stream and channel after a frame delay. */
// FUN_00373590
void btlShuffleCalcSetFrameFlags(u8 *state, s16 delay, s8 stream, u8 channel) {
    if ((channel & 0xFF) >= 5) {
        kAssertFail(&D_0064E9C0, 0x350);
    }
    *(s16 *)&((BtlShuffleSoundCue *)state)->frame = 0;
    *(s16 *)&((BtlShuffleSoundCue *)state)->delay = delay;
    *(s8 *)&((BtlShuffleSoundCue *)state)->stream = stream;
    *(s8 *)&((BtlShuffleSoundCue *)state)->channel = channel;
}

/* Using the compound assignment's value plus a single trailing return 0 reproduces retail's store
 * order and shared zero-return block; cases are declared ascending on purpose. */
// FUN_00373610
s32 btlShuffleCalcLoadTable(u8 *state)
{
    s32 bumped;
    BtlShuffleSoundCue *track = (BtlShuffleSoundCue *)state;

    if (track->channel == 0) {
        return 1;
    }
    /* Using the compound assignment's value stores the counter before it is masked, as retail does. */
    bumped = (track->frame += 1);
    /* measured: retail branches the positive test to one shared trailing zero-return block; an
     * inline return 0 here duplicates it. */
    if (!((s32)(bumped & 0xFFFF) < (s32)track->delay)) {
        /* Cases are declared ascending; the compiler emits the comparisons in reverse but lays out
         * bodies in declaration order. */
        switch (track->channel) {
        case 0:
            break;
        case 1:
            sdkSndStartStream(1, track->stream, 5, 1);
            break;
        case 2:
            sdkSndStartStream(1, track->stream, 5, 2);
            break;
        case 3:
            sdkSndStartStream(1, track->stream, 5, 3);
            break;
        case 4:
            sdkSndStartStream(1, track->stream, 5, 4);
            break;
        default:
            kAssertFail(D_0064E9C0, 0x379);
            break;
        }
        track->channel = 0;
        return 1;
    }
    return 0;
}

/* measured: preserving independent switch case bodies matches the retail layout; retail keeps
 * values unpropagated across the layout branches, so opt_propagation stays off. */
#pragma opt_propagation off
/* Place a card in the centered one-row or staggered two-row screen layout. */
// FUN_00373750
void btlShuffleCalcFillTable(s32 cardIndex, s32 cardCount, f32 *screen) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;

    if (screen == NULL) {
        kAssertFail(&D_0064E9C0, 0x38C);
    }
    switch (cardCount) {
    case 3:
    case 4:
        f3 = (f32)(cardCount - 1);
        f1 = 0.5f;
        f0 = (f32)cardIndex;
        *screen = 320.0f + 100.0f * (f0 - f1 * f3);
        f1 = 120.0f;
        f0 = 224.0f;
        f2 = 0.0f;
        screen[1] = f0 + f1 * f2;
        return;
    case 5:
        if (cardIndex < 3) {
            f2 = 100.0f;
            f0 = (f32)cardIndex;
            f1 = 1.0f;
            f1 = f0 - f1;
            *screen = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            screen[1] = f0 + f2 * f1;
            return;
        }
        f3 = (f32)(cardIndex - 3);
        f4 = 0.5f;
        f3 = f3 - f4;
        f1 = 100.0f;
        f0 = 320.0f;
        *screen = f0 + f1 * f3;
        f1 = 120.0f;
        f0 = 224.0f;
        screen[1] = f0 + f1 * f4;
        return;
    case 6:
        if (cardIndex < 3) {
            f2 = 100.0f;
            f0 = (f32)cardIndex;
            f1 = 1.0f;
            f1 = f0 - f1;
            *screen = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            screen[1] = f0 + f2 * f1;
            return;
        }
        f3 = (f32)(cardIndex - 3);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        *screen = f0 + f1 * f2;
        f2 = 120.0f;
        f1 = 0.5f;
        f0 = 224.0f;
        screen[1] = f0 + f2 * f1;
        return;
    case 7:
        if (cardIndex < 4) {
            f2 = 100.0f;
            f0 = (f32)cardIndex;
            f1 = 1.5f;
            f1 = f0 - f1;
            *screen = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            screen[1] = f0 + f2 * f1;
            return;
        }
        f3 = (f32)(cardIndex - 4);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        *screen = f0 + f1 * f2;
        f2 = 120.0f;
        f1 = 0.5f;
        f0 = 224.0f;
        screen[1] = f0 + f2 * f1;
        return;
    case 8:
        if (cardIndex < 4) {
            f2 = 100.0f;
            f0 = (f32)cardIndex;
            f1 = 1.5f;
            f1 = f0 - f1;
            *screen = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            screen[1] = f0 + f2 * f1;
            return;
        }
        f3 = (f32)(cardIndex - 4);
        f1 = 1.5f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        *screen = f0 + f1 * f2;
        f2 = 120.0f;
        f1 = 0.5f;
        f0 = 224.0f;
        screen[1] = f0 + f2 * f1;
        return;
    default:
        kAssertFail(&D_0064E9C0, 0x3BF);
        return;
    }
}
#pragma opt_propagation on

/* Measure the distance from a world-space point to the camera frame position. */
// FUN_00373C20
f32 btlShuffleCalcNormalizeOffset(u8 *point) {
    /* The camera frame is read as an address word; pointer-typed reads change argument-load
     * scheduling. */
    ShuffleVec3 cameraPosition;
    ShuffleVec3 difference;
    u8 *cameraMatrix;

    cameraMatrix = func_003e9700((s32)((RwCamera *)kwlnGetCamera())->object.object.parent);
    cameraPosition = ((BtlShuffleMatrix *)cameraMatrix)->pos;
    difference.x = ((RwV3d *)point)->x - cameraPosition.x;
    difference.y = ((RwV3d *)point)->y - cameraPosition.y;
    difference.z = ((RwV3d *)point)->z - cameraPosition.z;
    return RwV3dLength(&difference);
}

/* Clamp normalized timing and optionally apply sine or one-minus-cosine easing. */
// FUN_00373CB0
f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve) {
    f32 duration;

    if (frame < startFrame) {
        return 0.0f;
    }
    if (frame < endFrame) {
        duration = endFrame - startFrame;
        if (duration <= 0.0f) {
            kAssertFail(&D_0064E9C0, 0x3DD);
        }
        switch (curve) {
        case 0:
            return (frame - startFrame) / duration;
        case 1:
            return sinf((D_00761470 * (frame - startFrame)) / duration);
        case 2:
            return 1.0f - cosf((D_00761470 * (frame - startFrame)) / duration);
        default:
            kAssertFail(&D_0064E9C0, 0x3E9);
        }
    }
    return 1.0f;
}
