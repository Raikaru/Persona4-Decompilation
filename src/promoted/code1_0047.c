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

extern void sdkListStateSetCount(u8 *arg0, s32 arg1);
extern s32 sdkListStateGetCount(u8 *arg0);
extern s32 sdkListStateGetScroll(u8 *arg0);
extern s32 sdkListStateGetCursor(u8 *arg0);
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
extern s32 mdlSeUpdateRecord(void **owner);
extern s32 mdlSeFillEntryState(u8 *arg0, s16 arg1, s16 arg2, u16 arg3);
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
extern void mdlSeRequestLoad(void **arg0, u32 arg1, u16 arg2, s32 arg3, u32 arg4);
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
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
/* measured: the static exact mdlSampleVec4Track body preserves $t1/$f13 across
 * the call. Computing bytes 1 and 2 before byte 0 assigns retail's $f4/$f3
 * roles; staging each addend after its normalized value prevents load
 * hoisting, and the reverse-order inline madd helper reproduces all three
 * accumulator operand orders. Object 348B/window 352B, normalized_diff 0;
 * the final retail word is zero tail padding. The sample callback returns
 * its borrowed output buffer, which the dispatcher passes to each apply
 * callback. */
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
