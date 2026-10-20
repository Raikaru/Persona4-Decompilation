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


extern s32 mdlSeUpdateRecord(void **owner);
extern s32 mdlSeFillEntryState(u8 *state, s16 column, s16 rowIndex, u16 baseSlot);
extern s32 hsndSlotIsStarting(s16 slotIndex);
extern s32 sdkSndIsChannelPlaying(s16 channelIndex);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;

extern void sdkSndStartSourceStream(s16 channelIndex, s32 source, s16 sourceAux);
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
    ((MdlMotionState *)state)->object = NULL;
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

/* Requests an animation with blend ticks on a motion state, restarting it if the current request
 * differs; sound-tied requests are queued and started by mdlTickMotionState. */
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

/* Advances a motion state by one tick: counts down the wait and pending-start timers, starts a
 * queued request when its timer expires, and retries a failed start up to eight times. The retry
 * counter is re-read through its s16 slot after each increment, as retail does. */
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
    MdlMotionState *motion;

    mdlSeUpdateRecord((void **)state);
    motion = (MdlMotionState *)state;
    object = *(u8 **)state;
    if (object != NULL && (((MdlFileObject *)object)->flags & 1) != 0) {
        retryReady = 1;
        waitTicks = motion->waitTicks;
        if (waitTicks >= 0) {
            if (waitTicks == 0) {
                scratch = ((((MdlMotionState *)state)->flags & 0x20) != 0);
                if (scratch != 0) {
                    channel = ((MdlMotionState *)state)->channel;
                    streamFlags = ((MdlMotionState *)state)->streamFlags;
                    requestValue = ((MdlMotionState *)state)->requestValue;
                    sdkSndStartSourceStream((s16)channel, (s32)requestValue, (s16)streamFlags);
                }
                ((MdlMotionState *)state)->waitTicks = -1;
            } else {
                ((MdlMotionState *)state)->waitTicks = waitTicks - 1;
                retryReady = 0;
            }
        }
        pendingTicks = motion->pendingTicks;
        if (pendingTicks >= 0) {
            if (pendingTicks == 0) {
                channel = ((MdlMotionState *)state)->pendingChannel;
                streamFlags = ((MdlMotionState *)state)->pendingFlags;
                scratch = ((MdlMotionState *)state)->pendingKind;
                sdkSndStartStream(motion->pendingSlot, channel, streamFlags,
                              scratch);
                ((MdlMotionState *)state)->activeSlot = ((MdlMotionState *)state)->pendingSlot;
                ((MdlMotionState *)state)->pendingTicks = -1;
            } else {
                ((MdlMotionState *)state)->pendingTicks = pendingTicks - 1;
                retryReady = 0;
            }
        } else if (pendingTicks == -2) {
            pendingSlot = motion->activeSlot;
            if (pendingSlot >= 0) {
                sdkSndStopStream(pendingSlot, ((MdlMotionState *)state)->pendingChannel);
                ((MdlMotionState *)state)->activeSlot = -1;
            }
            ((MdlMotionState *)state)->pendingTicks = -1;
        }
        if (((MdlMotionState *)state)->request != 0 && retryReady == 1 &&
            motion->retries != -1) {
            retry = motion->retries + 1;
            motion->retries = retry;
            retryCount = motion->retries;
            if (retryCount < 8) {
                requestValue = ((MdlMotionState *)state)->blendTicks;
                /* measured: retail reloads retries through the integer-address cast instead of
                 * reusing the forwarded halfword value. */
                if (mdlSeFillEntryState(state, ((MdlMotionState *)(u32)state)->retries,
                                  ((MdlMotionState *)state)->animation, (u16)requestValue) == 0) {
                    ((MdlMotionState *)state)->retries = -1;
                }
            } else {
                ((MdlMotionState *)state)->retries = -1;
            }
        }
    }
}

