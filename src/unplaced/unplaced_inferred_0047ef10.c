
#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "mdl_file_internal.h"
#include "include_asm.h"
#include "type.h"
#include "operand_order_internal.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
/* Binary search over a track's key times: returns the index of the last key whose time is at or before sampleTime. */
/* Key payload stride is supplied by the track; only the leading time float is common to every key format. */
// FUN_0047EF10
static s32 mdlFindTrackKeyIndex(u8 *track, f32 sampleTime)
{
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;
    u8 *base;

    lo = 0;
    hi = ((MdlFileTrack *)track)->count - 1;
    stride = ((MdlFileTrack *)track)->stride;
    base = ((MdlFileTrack *)track)->keys;
    do {
        mid = (lo + hi + 1) >> 1;
        if (sampleTime < ((MdlFileScalarKey *)(base + (stride * mid)))->time) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    return mid;
}

/* Each sampled time/value pair is stored in a two-float struct so the stack frame and saved values
 * across the second call match retail. Samples two scalar tracks at sampleTime and otherTime and
 * blends the two values by blendFactor. Returns &fGpffffbb50 with the result. */
// FUN_0047F040
void *mdlBlendTrackSamples(u8 *track, f32 sampleTime, u8 *other, f32 otherTime,
                   f32 blendFactor)
{
    s32 index;
    u8 *base;
    typedef struct MdlScalarSample {
        f32 time;
        f32 value;
    } MdlScalarSample;
    MdlScalarSample first;
    MdlScalarSample second;
    f32 difference;

    base = ((MdlFileTrack *)track)->keys;
    index = mdlFindTrackKeyIndex(track, sampleTime);
    if ((u32)index >= (u32)(((MdlFileTrack *)track)->count - 1)) {
        index *= 8;
        fGpffffbb4c = ((MdlFileScalarKey *)((index) + ((s32)base)))->value;
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = ((MdlFileScalarKey *)point)[0].time;
        y0 = ((MdlFileScalarKey *)point)[0].value;
        ratio = sampleTime - x0;
        x1 = ((MdlFileScalarKey *)point)[1].time;
        ratio = ratio / (x1 - x0);
        y1 = ((MdlFileScalarKey *)point)[1].value;
        fGpffffbb4c = 0.0f + y0 +
            operandOrderMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = sampleTime;
    first = *(MdlScalarSample *)&fGpffffbb48;

    base = ((MdlFileTrack *)other)->keys;
    index = mdlFindTrackKeyIndex(other, otherTime);
    if ((u32)index >= (u32)(((MdlFileTrack *)other)->count - 1)) {
        index *= 8;
        fGpffffbb4c = ((MdlFileScalarKey *)((index) + ((s32)base)))->value;
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = ((MdlFileScalarKey *)point)[0].time;
        y0 = ((MdlFileScalarKey *)point)[0].value;
        ratio = otherTime - x0;
        x1 = ((MdlFileScalarKey *)point)[1].time;
        ratio = ratio / (x1 - x0);
        y1 = ((MdlFileScalarKey *)point)[1].value;
        fGpffffbb4c = 0.0f + y0 +
            operandOrderMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = otherTime;
    second = *(MdlScalarSample *)&fGpffffbb48;

    difference = second.value - first.value;
    fGpffffbb54 = (0.0f + (first.value) + (difference) * (blendFactor));
    return &fGpffffbb50;
}

/* Samples the scalar track at sampleTime and moves the value toward (1 - byte 3 of other / 255) by
 * otherTime. Returns the sample pair in fGpffffbb48. */
// FUN_0047F1A0
void *mdlBlendTrackWithAlpha(u8 *track, f32 sampleTime, u8 *other, f32 otherTime)
{
    s32 index;
    u8 *base;
    s32 out;
    f32 difference;
    f32 addend;

    base = ((MdlFileTrack *)track)->keys;
    index = mdlFindTrackKeyIndex(track, sampleTime);
    if ((u32)index >= (u32)(((MdlFileTrack *)track)->count - 1)) {
        index *= 8;
        fGpffffbb4c = ((MdlFileScalarKey *)((index) + ((s32)base)))->value;
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = ((MdlFileScalarKey *)point)[0].time;
        y0 = ((MdlFileScalarKey *)point)[0].value;
        ratio = sampleTime - x0;
        x1 = ((MdlFileScalarKey *)point)[1].time;
        ratio = ratio / (x1 - x0);
        y1 = ((MdlFileScalarKey *)point)[1].value;
        fGpffffbb4c = 0.0f + y0 +
            operandOrderMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = sampleTime;
    out = (s32)&fGpffffbb48;
    difference = (1.0f -
        ((f32)(u32)other[3]) / 255.0f);
    addend = ((MdlFileScalarKey *)out)->value;
    difference -= addend;
    ((MdlFileScalarKey *)out)->value = (0.0f + (addend) + (difference) * (otherTime));
    return (f32 *)out;
}
