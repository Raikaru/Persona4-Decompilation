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
extern s32 mdlSeFillEntryState(u8 *arg0, s16 arg1, s16 arg2, u16 arg3);
extern s32 hsndSlotIsStarting(s16 arg0);
extern s32 sdkSndIsChannelPlaying(s16 arg0);
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

/* Source unit: src/promoted/code1_0047.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0047.c; members 0047ea40-0047ed60 */

extern void func_0045abd0(s16 arg0, s32 arg1, s16 arg2);
static inline void code1_0047_abd0(s16 arg0, s32 arg1, s16 arg2)
{
    func_0045abd0(arg0, arg1, arg2);
}
// FUN_0047EA40
void mdlRetainObject(u8 **arg0, u8 **arg1)
{
    u8 *object;

    object = *arg1;
    if (object != NULL) {
        *(s32 *)(object + 8) = *(s32 *)(object + 8) + 1;
        *arg0 = object;
    }
}

// FUN_0047EA70
void mdlInitObjectSlots(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 8) = -1;
    *(s16 *)(arg0 + 0x16) = -1;
    *(s16 *)(arg0 + 0x24) = -1;
    *(s16 *)(arg0 + 0x26) = -1;
    *(u16 *)(arg0 + 0x10) |= 0x20;
}

/* Drops one reference on the object held in *arg0 (the count at +8, paired with mdlRetainObject). At zero it frees the object and its inner block, then clears the slot. */
// FUN_0047EAA0
void mdlReleaseObject(u8 *arg0)
{
    u8 *object;
    s32 refCount;
    u8 *inner;

    object = *(u8 **)arg0;
    if (object != NULL) {
        refCount = *(s32 *)(object + 8) - 1;
        *(s32 *)(object + 8) = refCount;
        if (refCount == 0) {
            inner = *(u8 **)object;
            if (inner != NULL) {
                jtbl_008873EC[0](inner);
            }
            jtbl_008873EC[0](object);
        }
        *(s32 *)arg0 = 0;
    }
}

/* Requests animation arg1 with blend ticks arg2 on a motion state, restarting it when the state's current request does not match. Requests tied to a starting sound slot are queued in the pending fields and started by mdlTickMotionState. */
// FUN_0047EB20
void mdlRequestMotionAnim(u8 *arg0, s16 arg1, u16 arg2)
{
    u16 status;
    s32 kind;
    u16 type;

    if ((*(u16 *)(arg0 + 0x10) & 0x10) == 0) {
        return;
    }
    if (*(u8 **)arg0 == NULL) {
        return;
    }
    if ((*(u16 *)(*(u8 **)arg0 + 0x12) & 1) == 0) {
        return;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        type = *(u16 *)(*(u8 **)arg0 + 0xC);
        if (type == 1) {
            status = 2;
        } else {
            status = 3;
        }
        if ((type == 1 &&
             (arg1 != 0xE || *(s16 *)(arg0 + 4) != arg1 ||
              sdkSndIsChannelPlaying(status) == 0)) ||
            (*(u16 *)(*(u8 **)arg0 + 0xC) == 2 &&
             (arg1 != 2 || *(s16 *)(arg0 + 4) != arg1 ||
              sdkSndIsChannelPlaying(status) == 0))) {
            if (mdlSeFillEntryState(arg0, 0, arg1, arg2) != 0) {
                *(s16 *)(arg0 + 8) = 0;
                *(s16 *)(arg0 + 4) = arg1;
                *(u16 *)(arg0 + 6) = arg2;
                return;
            }
            *(s16 *)(arg0 + 8) = -1;
            return;
        }
        *(s16 *)(arg0 + 8) = -1;
        return;
    }
    if (*(u16 *)(*(u8 **)arg0 + 0x10) == 2 &&
        (arg1 == 4 || arg1 == 5) &&
        hsndSlotIsStarting(*(s16 *)(*(u8 **)arg0 + 4)) != 0) {
        *(s16 *)(arg0 + 0x1C) = *(s32 *)(*(u8 **)arg0 + 4);
        *(s16 *)(arg0 + 0x24) = arg2;
        *(s16 *)(arg0 + 0x20) = 0;
        *(s16 *)(arg0 + 0x22) = arg1 - 4;
        kind = *(s32 *)(*(u8 **)arg0 + 4);
        switch (kind) {
        case 3:
            *(s16 *)(arg0 + 0x1E) = 1;
            break;
        case 4:
            *(s16 *)(arg0 + 0x1E) = 2;
            break;
        case 5:
            *(s16 *)(arg0 + 0x1E) = 3;
            break;
        }
        *(s16 *)(arg0 + 4) = arg1;
    }
}

/* measured: the retry counter is stored as an s32 sum and re-read through the s16 slot
   (`n = x + 1; x = n; temp = x;`): the reload forwards to a dsll32/dsra32 after the sh,
   as retail. The call argument re-reads the slot as `*(s16 *)((u32)arg0 + 8)` so it is
   not CSE'd with the forwarded value and stays a real lh (retail). */
/* Advances a motion state by one tick: counts down the wait and pending-start timers, starts a queued request when its timer expires, and retries a failed start up to eight times. */
// FUN_0047ED60
void mdlTickMotionState(u8 *arg0)
{
    s16 waitTicks;
    s16 scratch;
    s16 retryCount;
    s16 pendingTicks;
    s16 pendingSlot;
    s32 retryReady;
    u8 *object;
    s16 call_a0;
    s16 call_a2;
    s32 call_a1;
    s32 retry;

    mdlSeUpdateRecord((void **)arg0);
    object = *(u8 **)arg0;
    if (object != NULL && (*(u16 *)(object + 0x12) & 1) != 0) {
        retryReady = 1;
        waitTicks = *(s16 *)(arg0 + 0x16);
        if (waitTicks >= 0) {
            if (waitTicks == 0) {
                scratch = ((*(u16 *)(arg0 + 0x10) & 0x20) != 0);
                if (scratch != 0) {
                    call_a0 = *(s16 *)(arg0 + 0x12);
                    call_a2 = *(s16 *)(arg0 + 0x14);
                    call_a1 = *(s32 *)(arg0 + 0x18);
                    code1_0047_abd0((s16)call_a0, (s32)call_a1, (s16)call_a2);
                }
                *(s16 *)(arg0 + 0x16) = -1;
            } else {
                *(s16 *)(arg0 + 0x16) = waitTicks - 1;
                retryReady = 0;
            }
        }
        pendingTicks = *(s16 *)(arg0 + 0x24);
        if (pendingTicks >= 0) {
            if (pendingTicks == 0) {
                call_a0 = *(s16 *)(arg0 + 0x1E);
                call_a2 = *(s16 *)(arg0 + 0x20);
                scratch = *(s16 *)(arg0 + 0x22);
                sdkSndStartStream(*(s16 *)(arg0 + 0x1C), call_a0, call_a2,
                              scratch);
                *(s16 *)(arg0 + 0x26) = *(s16 *)(arg0 + 0x1C);
                *(s16 *)(arg0 + 0x24) = -1;
            } else {
                *(s16 *)(arg0 + 0x24) = pendingTicks - 1;
                retryReady = 0;
            }
        } else if (pendingTicks == -2) {
            pendingSlot = *(s16 *)(arg0 + 0x26);
            if (pendingSlot >= 0) {
                sdkSndStopStream(pendingSlot, *(s16 *)(arg0 + 0x1E));
                *(s16 *)(arg0 + 0x26) = -1;
            }
            *(s16 *)(arg0 + 0x24) = -1;
        }
        if (*(s32 *)(arg0 + 0xC) != 0 && retryReady == 1 &&
            *(s16 *)(arg0 + 8) != -1) {
            retry = *(s16 *)(arg0 + 8) + 1;
            *(s16 *)(arg0 + 8) = retry;
            retryCount = *(s16 *)(arg0 + 8);
            if (retryCount < 8) {
                call_a1 = *(u16 *)(arg0 + 0x06);
                if (mdlSeFillEntryState(arg0, *(s16 *)((u32)arg0 + 8),
                                  *(s16 *)(arg0 + 0x04), (u16)call_a1) == 0) {
                    *(s16 *)(arg0 + 8) = -1;
                }
            } else {
                *(s16 *)(arg0 + 8) = -1;
            }
        }
    }
}

