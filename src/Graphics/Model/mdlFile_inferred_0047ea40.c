#include "mdl_file_internal.h"
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
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];



struct MdlFlags78ec0;


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

extern s32 mdlSeUpdateRecord(void **owner);
extern s32 mdlSeFillEntryState(u8 *state, s16 column, s16 rowIndex, u16 baseSlot);
extern s32 hsndSlotIsStarting(s16 slotIndex);
extern s32 sdkSndIsChannelPlaying(s16 channelIndex);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0047; members 0047ea40-0047ed60 */

extern void sdkSndStartSourceStream(s16 channelIndex, s32 source, s16 sourceAux);
static inline void code1_0047_abd0(s16 state, s32 animation, s16 blendTicks)
{
    sdkSndStartSourceStream(state, animation, blendTicks);
}
/* Retain the source object and store it in the destination slot when non-null. */
// FUN_0047EA40
void mdlRetainObject(u8 **destination, u8 **source)
{
    u8 *object;

    object = *source;
    if (object != NULL) {
        ((MdlFileObject *)object)->references = ((MdlFileObject *)object)->references + 1;
        *destination = object;
    }
}

/* Reset motion object slots, timers and retry state, retaining flag 0x20 for deferred dispatch. */
// FUN_0047EA70
void mdlInitObjectSlots(u8 *state)
{
    /* Initialization clears the object pointer through its original integer-word representation. */
    *(s32 *)(state + 0) = 0;
    ((MdlMotionState *)state)->retries = -1;
    ((MdlMotionState *)state)->waitTicks = -1;
    ((MdlMotionState *)state)->pendingTicks = -1;
    ((MdlMotionState *)state)->activeSlot = -1;
    ((MdlMotionState *)state)->flags |= 0x20;
}

/* Drops one reference on the object held in *state (the count at +8, paired with mdlRetainObject). At zero it frees the object and its inner block, then clears the slot. */
// FUN_0047EAA0
void mdlReleaseObject(u8 *state)
{
    u8 *object;
    s32 refCount;
    u8 *inner;

    object = *(u8 **)state;
    if (object != NULL) {
        refCount = ((MdlFileObject *)object)->references - 1;
        ((MdlFileObject *)object)->references = refCount;
        if (refCount == 0) {
            inner = *(u8 **)object;
            if (inner != NULL) {
                jtbl_008873EC[0](inner);
            }
            jtbl_008873EC[0](object);
        }
        *(s32 *)state = 0;
    }
}

/* Requests animation animation with blend ticks blendTicks on a motion state, restarting it when the state's current request does not match. Requests tied to a starting sound slot are queued in the pending fields and started by mdlTickMotionState. */
// FUN_0047EB20
void mdlRequestMotionAnim(u8 *state, s16 animation, u16 blendTicks)
{
    u16 status;
    s32 kind;
    u16 type;

    if ((((MdlMotionState *)state)->flags & 0x10) == 0) {
        return;
    }
    if (*(u8 **)state == NULL) {
        return;
    }
    if ((((MdlFileObject *)*(u8 **)state)->flags & 1) == 0) {
        return;
    }
    if (((MdlMotionState *)state)->request != 0) {
        type = ((MdlFileObject *)*(u8 **)state)->type;
        if (type == 1) {
            status = 2;
        } else {
            status = 3;
        }
        if ((type == 1 &&
             (animation != 0xE || ((MdlMotionState *)state)->animation != animation ||
              sdkSndIsChannelPlaying(status) == 0)) ||
            (((MdlFileObject *)*(u8 **)state)->type == 2 &&
             (animation != 2 || ((MdlMotionState *)state)->animation != animation ||
              sdkSndIsChannelPlaying(status) == 0))) {
            if (mdlSeFillEntryState(state, 0, animation, blendTicks) != 0) {
                ((MdlMotionState *)state)->retries = 0;
                ((MdlMotionState *)state)->animation = animation;
                ((MdlMotionState *)state)->blendTicks = blendTicks;
                return;
            }
            ((MdlMotionState *)state)->retries = -1;
            return;
        }
        ((MdlMotionState *)state)->retries = -1;
        return;
    }
    if (((MdlFileObject *)*(u8 **)state)->mode == 2 &&
        (animation == 4 || animation == 5) &&
        hsndSlotIsStarting((s16)((MdlFileObject *)*(u8 **)state)->slot) != 0) {
        ((MdlMotionState *)state)->pendingSlot = ((MdlFileObject *)*(u8 **)state)->slot;
        ((MdlMotionState *)state)->pendingTicks = blendTicks;
        ((MdlMotionState *)state)->pendingFlags = 0;
        ((MdlMotionState *)state)->pendingKind = animation - 4;
        kind = ((MdlFileObject *)*(u8 **)state)->slot;
        switch (kind) {
        case 3:
            ((MdlMotionState *)state)->pendingChannel = 1;
            break;
        case 4:
            ((MdlMotionState *)state)->pendingChannel = 2;
            break;
        case 5:
            ((MdlMotionState *)state)->pendingChannel = 3;
            break;
        }
        ((MdlMotionState *)state)->animation = animation;
    }
}

/* measured: the retry counter is stored as an s32 sum and re-read through the s16 slot
   (`n = x + 1; x = n; temp = x;`): the reload forwards to a dsll32/dsra32 after the sh,
   as retail. The call argument re-reads the slot as `*(s16 *)((u32)state + 8)` so it is
   not CSE'd with the forwarded value and stays a real lh (retail). */
/* Advances a motion state by one tick: counts down the wait and pending-start timers, starts a queued request when its timer expires, and retries a failed start up to eight times. */
// FUN_0047ED60
void mdlTickMotionState(u8 *state)
{
    s16 waitTicks;
    s16 scratch;
    s16 retryCount;
    s16 pendingTicks;
    s16 pendingSlot;
    s32 retryReady;
    u8 *object;
    s16 channel;
    s16 streamFlags;
    s32 requestValue;
    s32 retry;

    mdlSeUpdateRecord((void **)state);
    object = *(u8 **)state;
    if (object != NULL && (((MdlFileObject *)object)->flags & 1) != 0) {
        retryReady = 1;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        waitTicks = *(s16 *)(state + 0x16);
        if (waitTicks >= 0) {
            if (waitTicks == 0) {
                scratch = ((((MdlMotionState *)state)->flags & 0x20) != 0);
                if (scratch != 0) {
                    channel = ((MdlMotionState *)state)->channel;
                    streamFlags = ((MdlMotionState *)state)->streamFlags;
                    requestValue = ((MdlMotionState *)state)->requestValue;
                    code1_0047_abd0((s16)channel, (s32)requestValue, (s16)streamFlags);
                }
                ((MdlMotionState *)state)->waitTicks = -1;
            } else {
                ((MdlMotionState *)state)->waitTicks = waitTicks - 1;
                retryReady = 0;
            }
        }
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        pendingTicks = *(s16 *)(state + 0x24);
        if (pendingTicks >= 0) {
            if (pendingTicks == 0) {
                channel = ((MdlMotionState *)state)->pendingChannel;
                streamFlags = ((MdlMotionState *)state)->pendingFlags;
                scratch = ((MdlMotionState *)state)->pendingKind;
                /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
                sdkSndStartStream(*(s16 *)(state + 0x1C), channel, streamFlags,
                              scratch);
                ((MdlMotionState *)state)->activeSlot = ((MdlMotionState *)state)->pendingSlot;
                ((MdlMotionState *)state)->pendingTicks = -1;
            } else {
                ((MdlMotionState *)state)->pendingTicks = pendingTicks - 1;
                retryReady = 0;
            }
        } else if (pendingTicks == -2) {
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            pendingSlot = *(s16 *)(state + 0x26);
            if (pendingSlot >= 0) {
                sdkSndStopStream(pendingSlot, ((MdlMotionState *)state)->pendingChannel);
                ((MdlMotionState *)state)->activeSlot = -1;
            }
            ((MdlMotionState *)state)->pendingTicks = -1;
        }
        if (((MdlMotionState *)state)->request != 0 && retryReady == 1 &&
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            *(s16 *)(state + 8) != -1) {
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            retry = *(s16 *)(state + 8) + 1;
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            *(s16 *)(state + 8) = retry;
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            retryCount = *(s16 *)(state + 8);
            if (retryCount < 8) {
                requestValue = ((MdlMotionState *)state)->blendTicks;
                /* measured: the integer-address retry reload must stay separate from the forwarded halfword value, as documented above. */
                if (mdlSeFillEntryState(state, *(s16 *)((u32)state + 8),
                                  ((MdlMotionState *)state)->animation, (u16)requestValue) == 0) {
                    ((MdlMotionState *)state)->retries = -1;
                }
            } else {
                ((MdlMotionState *)state)->retries = -1;
            }
        }
    }
}

