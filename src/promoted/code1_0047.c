#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern void (*iGpffffbb3c)();
extern void sdkLboxClear(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffbb28;
extern void Vpad_RefreshSelection(u8 *arg0);
extern void Vpad_Noop(u8 *arg0);
struct RuntimeWork;
extern void Vpad_SetColor(struct RuntimeWork* work, const u8* color);
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];

extern u8 *sdkLboxFindEntry(u8 *arg0, s32 arg1);
extern void sdkLboxRecalcLayout(u8 *arg0);

extern void mdlAdvanceModel(u8 *arg0, s32 arg1);

struct MdlFlags78ec0;
extern void mdlApplyDrawState(void* context, struct MdlFlags78ec0* model);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

extern s32 mdlLayerIsPresent(u8 *arg0, s32 arg1);

extern void func_00453ce0(u8 *arg0, s32 arg1);
extern s32 func_00453e10(u8 *arg0);
extern s32 func_00453d70(u8 *arg0);
extern s32 func_00453dc0(u8 *arg0);
/* measured: sdkLboxGetSelectedId's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

extern s32 mdlPrepareModel(u8 *arg0);
extern s32 func_0047e6f0(void **owner);
extern s32 func_0047e0f0(u8 *arg0, s16 arg1, s16 arg2, u16 arg3);
extern void func_0045abd0(s16 arg0, s32 arg1, s16 arg2);
extern s32 hsndSlotIsStarting(s16 arg0);
extern s32 func_0045af90(s16 arg0);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_Destroy(u8 *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_ReadSync(u8 *arg0);
extern void K_Clump_FreeTextureNameList(void *arg0);
extern s32 mdlReadAuxChunks(u8 *arg0);
extern s32 mdlPollAuxResources(u8 *arg0);
extern void func_0047e450(void **arg0, u32 arg1, u16 arg2, s32 arg3, u32 arg4);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
static inline f32 code1_0047_mul(f32 left, f32 right)
{
    return left * right;
}
static inline f32 code1_0047_madd(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + left * right;
}
static inline f32 code1_0047_madd_reverse(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + right * left;
}
















// FUN_0047DD40
/* All three retail callers pass the owning model in a1 (00476808,
   00476BB0, 00478CC4); this secondary-effect updater does not read it. */
void mdlRefreshSecondaryEffect(u8 *arg0, void *model)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_RefreshSelection(effect);
    }
}

// FUN_0047DDA0
void mdlNoopSecondaryEffect(u8 *arg0)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_Noop(effect);
    }
}
/* Retail forwards the requested color in a1 to the runtime color consumer. */
// FUN_0047DDD0
void mdlSetAttachmentColor(u8* attachment, const u8* color)
{
    struct RuntimeWork* work;

    work = *(struct RuntimeWork**)(attachment + 4);
    if (work != NULL) {
        Vpad_SetColor(work, color);
    }
}
static inline void code1_0047_abd0(s16 arg0, s32 arg1, s16 arg2)
{
    func_0045abd0(arg0, arg1, arg2);
}

/* Binary search over a track's key times: returns the index of the last key whose time is at or before fparg0. */
// FUN_0047EF10
static s32 mdlFindTrackKeyIndex(u8 *arg0, f32 fparg0)
{
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;
    u8 *base;

    lo = 0;
    hi = *(s32 *)arg0 - 1;
    stride = *(s32 *)(arg0 + 8);
    base = *(u8 **)(arg0 + 0xC);
    do {
        mid = (lo + hi + 1) >> 1;
        if (fparg0 < *(f32 *)(base + (stride * mid))) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    return mid;
}
/* Samples a scalar track at fparg0 by linear interpolation between the surrounding keys, clamped to the last key. Writes the value to fGpffffbb4c and returns &fGpffffbb48, which holds the time. */
// FUN_0047EF70
u8 *mdlSampleTrackScalar(u8 *arg0, f32 fparg0)
{
    s32 lastIndex;
    s32 pairs;
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;

    pairs = (s32)*(u8 **)(arg0 + 0xC);
    lo = 0;
    lastIndex = *(s32 *)arg0 - 1;
    hi = lastIndex;
    stride = *(s32 *)(arg0 + 8);
    do {
        mid = (lo + hi + 1) >> 1;
        if (fparg0 < *(f32 *)(pairs + (stride * mid))) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    if ((u32)mid >= (u32)lastIndex) {
        fGpffffbb4c = *(f32 *)(viewAddReverse(pairs, mid * 8) + 4);
    } else {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        x0 = *(f32 *)(pairs + (mid * 8));
        y0 = *(f32 *)(pairs + (mid * 8) + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(pairs + (mid * 8) + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(pairs + (mid * 8) + 0xC);
        fGpffffbb4c = y0 + code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    return (u8 *)&fGpffffbb48;
}
/* measured: duplicating the scalar sampler around the static exact
 * mdlFindTrackKeyIndex preserves both track pointers, times, and the blend factor.
 * Assigning each GP result pair to a two-float aggregate forces retail's
 * 0x20 frame and exact stack snapshots across the second call; the staged
 * inline madd helper closes the final blend. Object 340B/window 352B,
 * normalized_diff 0 with three retail zero-tail words. */
/* Samples two scalar tracks at fparg0 and fparg1 and blends the two values by fparg2. Returns &fGpffffbb50 with the result. */
// FUN_0047F040
void *mdlBlendTrackSamples(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    s32 index;
    u8 *base;
    typedef struct Code47Pair {
        f32 time;
        f32 value;
    } Code47Pair;
    Code47Pair first;
    Code47Pair second;
    f32 difference;

    base = *(u8 **)(arg0 + 0xC);
    index = mdlFindTrackKeyIndex(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    first = *(Code47Pair *)&fGpffffbb48;

    base = *(u8 **)(arg1 + 0xC);
    index = mdlFindTrackKeyIndex(arg1, fparg1);
    if ((u32)index >= (u32)(*(s32 *)arg1 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg1 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg1;
    second = *(Code47Pair *)&fGpffffbb48;

    difference = second.value - first.value;
    fGpffffbb54 = code1_0047_madd(difference, fparg2, first.value);
    return &fGpffffbb50;
}
/* measured: keeping the exact mdlFindTrackKeyIndex helper static exposes its narrow
 * clobber set, preserving the caller's $t2/$t1/$f13 values. Caching the track
 * base before the call, scaling `index` in place in each branch, and carrying
 * the GP output address as an integer reproduce retail's register lifetimes.
 * Splitting the final difference/addend before the inline madd helper preserves
 * both evaluation order and FMA operand order. The object is 276B in a 288B
 * retail window with only three retail zero-tail words. */
/* Samples the scalar track arg0 at fparg0 and moves the value toward (1 - byte 3 of arg1 / 255) by fparg1. Returns the sample pair in fGpffffbb48. */
// FUN_0047F1A0
void *mdlBlendTrackWithAlpha(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    s32 index;
    u8 *base;
    s32 out;
    f32 difference;
    f32 addend;

    base = *(u8 **)(arg0 + 0xC);
    index = mdlFindTrackKeyIndex(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    out = (s32)&fGpffffbb48;
    difference = (1.0f -
        ((f32)(u32)*(u8 *)(arg1 + 3)) / 255.0f);
    addend = *(f32 *)(out + 4);
    difference -= addend;
    *(f32 *)(out + 4) = code1_0047_madd(
        difference, fparg1, addend);
    return (f32 *)out;
}
/* measured: mdlSampleVec4Track remains 300B in a 304B retail window with
 * only one retail zero-tail word. Keeping the exact helper static in this
 * code1 TU exposes its real register clobbers to MWCC, so mdlBlendVec4Tracks
 * retains $t1/$f13/$f14 across both calls. The pointer-first source signature
 * preserves the independent integer/float ABI while ordering the second
 * call's $a0 setup before $f12; mdlBlendVec4Tracks is 216B in a 224B window with
 * only two retail zero-tail words. */
/* Samples the Vec4 track table at t: binary search over the key times, interpolates the four components into DAT_00922c30, and returns that buffer with t in its first word. */
// FUN_0047F3A0
static u32 *mdlSampleVec4Track(int *table, float t)
{
  float *entry;
  float fraction;
  float start;
  float value;
  float delta;
  int hi;
  int lo;
  int stride;
  u8 *keys;
  int mid;
  u32 entryAddr;

  keys = (u8 *)table[3];
  lo = 0;
  hi = *table - 1;
  stride = table[2];
  do {
    mid = (lo + hi + 1) >> 1;
    if (t < *(float *)(keys + stride * mid)) {
      hi = --mid;
    }
    else {
      lo = mid;
    }
  } while (lo < hi);
  if ((u32)mid >= (u32)(*table - 1)) {
    entryAddr = mid * 0x10;
    entryAddr += (u32)keys;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(entryAddr + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(entryAddr + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(entryAddr + 0xc);
  }
  else {
    entry = (float *)((u32)(mid * 0x10) + (u32)keys);
    start = entry[0];
    fraction = t - start;
    fraction /= entry[4] - start;
    value = entry[1];
    delta = entry[5] - value;
    *(float *)(DAT_00922c30_abs + 4) = fraction * delta + value;
    value = entry[2];
    delta = entry[6] - value;
    *(float *)(DAT_00922c30_abs + 8) = fraction * delta + value;
    value = entry[3];
    delta = entry[7] - value;
    *(float *)(DAT_00922c30_abs + 12) = fraction * delta + value;
  }
  *(float *)DAT_00922c30_abs = t;
  return (u32 *)DAT_00922c30_abs;
}
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
/* Samples two Vec4 tracks at fparg0 and fparg1 and linearly blends their y, z and w components by fparg2 into D_00922C40. */
// FUN_0047F4D0
void *mdlBlendVec4Tracks(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    Code47Vec4 first;
    Code47Vec4 second;

    first = *(Code47Vec4 *)mdlSampleVec4Track((int *)arg0, fparg0);
    second = *(Code47Vec4 *)mdlSampleVec4Track((int *)arg1, fparg1);
    D_00922C40.y = 0.0f + first.y + fparg2 * (second.y - first.y);
    D_00922C40.z = 0.0f + first.z + fparg2 * (second.z - first.z);
    D_00922C40.w = 0.0f + first.w + fparg2 * (second.w - first.w);
    return &D_00922C40;
}
/* measured: the static exact mdlSampleVec4Track body preserves $t1/$f13 across
 * the call. Computing bytes 1 and 2 before byte 0 assigns retail's $f4/$f3
 * roles; staging each addend after its normalized value prevents load
 * hoisting, and the reverse-order inline madd helper reproduces all three
 * accumulator operand orders. Object 348B/window 352B, normalized_diff 0;
 * the final retail word is zero tail padding. The sample callback returns
 * its borrowed output buffer, which the dispatcher passes to each apply
 * callback. */
/* Samples the Vec4 track arg0 at fparg0, then blends its three components toward the byte colour in arg1 (bytes 0..2 divided by 255) by fparg1. Returns the sampled buffer. */
// FUN_0047F5B0
void *mdlBlendTrackColorBytes(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    f32 *out;
    f32 second;
    f32 third;
    f32 first;
    f32 addend;
    f32 difference;

    out = (f32 *)mdlSampleVec4Track((int *)arg0, fparg0);
    second = (f32)(u32)arg1[1] / 255.0f;
    third = (f32)(u32)arg1[2] / 255.0f;
    first = (f32)(u32)arg1[0] / 255.0f;

    difference = first;
    addend = out[1];
    difference -= addend;
    out[1] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = second;
    addend = out[2];
    difference -= addend;
    out[2] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = third;
    addend = out[3];
    difference -= addend;
    out[3] = code1_0047_madd_reverse(difference, fparg1, addend);
    return out;
}
/* Converts the float RGB components of arg0 (words 1..3) to bytes at arg1 + 4. */
// FUN_0047F710
void mdlStoreColorBytes(void *arg0, void *arg1)
{
    u8 *dst;

    dst = (u8 *)arg1 + 4;
    dst[0] = (u8)(255.0f * ((f32 *)arg0)[1]);
    dst[1] = (u8)(255.0f * ((f32 *)arg0)[2]);
    dst[2] = (u8)(255.0f * ((f32 *)arg0)[3]);
}
/* The callback rows share one C interface. Borrowed sample/blend buffers
 * carry kind-specific values; apply callbacks interpret those values and
 * their target objects. */
typedef struct Code47Dispatch {
    void *unused;
    void *(*blend)(u8 *left, f32 left_time, u8 *right, f32 right_time,
                   f32 ratio);
    void *(*sample)(u8 *track, f32 time, u8 *defaults, f32 ratio);
    void (*apply)(void *result, void *target);
} Code47Dispatch;

/* Read-only prefix of the shared target-list allocation. */
typedef struct Code47Targets {
    void **items;
    u16 count;
} Code47Targets;

extern Code47Dispatch D_00713220[4];

#pragma push
#pragma opt_loop_invariants on
#pragma pop
