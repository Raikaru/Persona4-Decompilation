/* Inferred unit: no __FILE__ evidence; boundaries from shared TU with static helper; members 0047ef10-0047f1a0 */

#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "mdl_file_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
/* measured: sdkLboxGetSelectedId's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 mdlTrackAddKeyOffset(s32 base, s32 offset)
{
    return offset + base;
}

extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
static inline f32 mdlTrackMultiply(f32 left, f32 right)
{
    return left * right;
}

static inline f32 mdlTrackMultiplyAdd(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + left * right;
}

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

/* measured: duplicating the scalar sampler around the static exact
 * mdlFindTrackKeyIndex preserves both track pointers, times, and the blend factor.
 * Assigning each GP result pair to a two-float aggregate forces retail's
 * 0x20 frame and exact stack snapshots across the second call; the staged
 * inline madd helper closes the final blend. Object 340B/window 352B,
 * normalized_diff 0 with three retail zero-tail words. */
/* Samples two scalar tracks at sampleTime and otherTime and blends the two values by blendFactor. Returns &fGpffffbb50 with the result. */
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
        fGpffffbb4c = ((MdlFileScalarKey *)mdlTrackAddKeyOffset((s32)base, index))->value;
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
            mdlTrackMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = sampleTime;
    first = *(MdlScalarSample *)&fGpffffbb48;

    base = ((MdlFileTrack *)other)->keys;
    index = mdlFindTrackKeyIndex(other, otherTime);
    if ((u32)index >= (u32)(((MdlFileTrack *)other)->count - 1)) {
        index *= 8;
        fGpffffbb4c = ((MdlFileScalarKey *)mdlTrackAddKeyOffset((s32)base, index))->value;
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
            mdlTrackMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = otherTime;
    second = *(MdlScalarSample *)&fGpffffbb48;

    difference = second.value - first.value;
    fGpffffbb54 = mdlTrackMultiplyAdd(difference, blendFactor, first.value);
    return &fGpffffbb50;
}

/* measured: keeping the exact mdlFindTrackKeyIndex helper static exposes its narrow
 * clobber set, preserving the caller's $t2/$t1/$f13 values. Caching the track
 * base before the call, scaling `index` in place in each branch, and carrying
 * the GP output address as an integer reproduce retail's register lifetimes.
 * Splitting the final difference/addend before the inline madd helper preserves
 * both evaluation order and FMA operand order. The object is 276B in a 288B
 * retail window with only three retail zero-tail words. */
/* Samples the scalar track track at sampleTime and moves the value toward (1 - byte 3 of other / 255) by otherTime. Returns the sample pair in fGpffffbb48. */
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
        fGpffffbb4c = ((MdlFileScalarKey *)mdlTrackAddKeyOffset((s32)base, index))->value;
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
            mdlTrackMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = sampleTime;
    out = (s32)&fGpffffbb48;
    difference = (1.0f -
        ((f32)(u32)other[3]) / 255.0f);
    addend = ((MdlFileScalarKey *)out)->value;
    difference -= addend;
    ((MdlFileScalarKey *)out)->value = mdlTrackMultiplyAdd(
        difference, otherTime, addend);
    return (f32 *)out;
}
