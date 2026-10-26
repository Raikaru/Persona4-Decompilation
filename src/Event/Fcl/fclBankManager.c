/* Original translation unit fclBankManager.c (from __FILE__ assert strings). */
#include "type.h"
#include "scene_event_internal.h"
#include "include_asm.h"
#include "fcl_bank_internal.h"


typedef struct FclBankPosition { f32 x, y; } FclBankPosition;

extern char iGpffffa890[8];
extern int iGpffffa898;

extern s32 vprintf(u8 *, s32 *);
extern u8 *nmListAppendNode(void *, void *, s32);
typedef struct NmlistNode NmlistNode;
typedef struct NmlistList NmlistList;
extern NmlistNode *comuDataRemoveAndReleaseNode(NmlistList *, NmlistList *, int *);
extern s32 func_00440b68(const char *, ...);
extern void fclBankSlotConfigure(s16, s16, s16, s16);
extern void fclBankSetActive(s64, s32);
extern char D_0063FBB0[];
extern char D_0063FBC8[];

/* Slot flags: 1 occupied, 2 loading, 4 settled, 8 visible, 0x10 fading;
   0x20 skips the slide, 0x40 delays fade-out, 0x100 selects the slide side.
   Requests: 0x200 show, 0x400 hide, 0x800 release, 0x1000 retire. */
/* Pending-list links and request payload, as read by acquire/queue/update.
   Keep the public integer-pointer list API at its existing call boundary. */
typedef struct FclBankRequest {
    s16 flags;
    u8 pad02[2];
    u32 descriptor;
} FclBankRequest;

typedef struct FclBankRequestNode {
    u8 pad00[0x10];
    s32 *next;
    FclBankRequest *request;
} FclBankRequestNode;

// Variadic wrapper (PS2 SDK pattern, mirrors src/h_dbprt.c); call sites pass
// whatever tail args they have.
extern void fclBankLogf(u8 *, ...);

// PS2 SDK va_list: va_start points into the register-save spill block the compiler emits for
// __builtin_args_info.
typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)


/* Variadic bank log: forwards the format and its varargs to func_00446e88. */
// FUN_002E0EA0
void fclBankLogf(u8 *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vprintf(fmt, (s32 *)args);
}

/* Cancel active non-retiring slots and drain the pending request list. */
// FUN_002E0DD0
void fclBankCancelPending(void)
{
    s32 i;
    FclBankSlot *slot = fclBankWork()->record->slots;
    s32 *node;

    i = 0;
    while (i < 2) {
        s16 v = slot->flags;
        if ((v & 1) && !(v & 0x1000)) {
            slot->flags = (s16)(v | 0x400);
        }
        slot++;
        i++;
    }
    node = (s32 *)fclBankWork()->pendingTail;
    while (node != NULL) {
        s32 *next = ((FclBankRequestNode *)node)->next;
        comuDataRemoveAndReleaseNode((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
        node = next;
    }
    func_00440b68(iGpffffa890, D_0063FBB0, 0xCA);
    fclBankLogf((u8 *)&iGpffffa898);
}

/* Mark loaded or visible slots for cancellation. */
// FUN_002E0F20
void fclBankMarkSettled(void)
{
    s32 i;
    FclBankSlot *slot = fclBankWork()->record->slots;

    i = 0;
    while (i < 2) {
        s16 v = slot->flags;
        if ((v & 1) && ((v & 8) || (v & 2))) {
            slot->flags = (s16)((s64)v | 0x400);
        }
        slot++;
        i++;
    }
}
// FUN_002E0F90
void fclBankSetReadyFlag(void)
{
    fclBankWork()->record->readyFlags |= 1;
}

/* Report pending requests or a slot whose load has not settled. */
// FUN_002E0FB0
s32 fclBankHasPendingLoad(void)
{
    s32 i;
    FclBankSlot *slot = fclBankWork()->record->slots;

    if (fclBankWork()->pendingTail != NULL) {
        return 1;
    }
    for (i = 0; i < 2; slot++, i++) {
        s16 w = slot->flags;
        if ((w & 1) && (w & 2)) {
            return 1;
        }
    }
    return 0;
}

/* Return the first unoccupied slot, or -1 when both are in use. */
/* Find the first bank slot whose allocation flag is clear. */
static inline s16 fclBankFindUnused(FclBankRecord *banks)
{
    s32 i;
    FclBankSlot *slot = banks->slots;
    for (i = 0; i < 2; i++) {
        if ((slot->flags & 1) == 0)
            return i;
        slot++;
    }
    return -1;
}

/* Reuse an occupied slot only when it is neither loading nor visible. */
/* Find an allocated bank that is neither locked nor visible. */
static inline s16 fclBankFindReusable(FclBankRecord *banks)
{
    s32 i;
    FclBankSlot *slot = banks->slots;
    for (i = 0; i < 2; i++) {
        s16 value = slot->flags;
        if ((value & 1) && !(value & 2) && !(value & 8))
            return i;
        slot++;
    }
    return -1;
}

/* Places node in a free or reusable bank slot; returns the slot index or -1. The selection and
 * return stay 64-bit, matching where retail narrows the value. */
// FUN_002E1030
s64 fclBankAcquire(int *node)
{
    FclBankSlot *slot;
    s64 selected;
    FclBankRecord *banks;
    FclBankRequest *payload;

    banks = fclBankWork()->record;
    selected = fclBankFindUnused(banks);
    if (selected == -1)
        selected = fclBankFindReusable(banks);
    if ((s16)selected == -1)
        return -1;
    payload = ((FclBankRequestNode *)node)->request;
    slot = &banks->slots[(s16)selected];
    slot->descriptor = payload->descriptor;
    slot->flags = payload->flags;
    slot->index = (u16)selected;
    fclBankSlotConfigure(selected, (s16)((slot->descriptor & 0xFFFF0000U) >> 16),
                 (s16)((slot->descriptor & 0xFF00) >> 8), (s16)(slot->descriptor & 0xFF));
    fclBankSetActive(slot->index, 1);
    slot->flags |= 1;
    slot->flags |= 2;
    comuDataRemoveAndReleaseNode((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
    func_00440b68(iGpffffa890, D_0063FBB0, 0x19D);
    fclBankLogf((u8 *)D_0063FBC8, slot->index);
    return selected;
}

/* Queue a descriptor and its high-byte request flags for bank acquisition. */
// FUN_002E1230
void *fclBankQueueRequest(s32 descriptor, s64 flags)
{
    s32 i;
    FclBankSlot *slot;
    FclBankRequest *request;
    void *node;

    slot = fclBankWork()->record->slots;
    i = 0;
    while (i < 2) {
        if ((slot->flags & 1) && ((s32)slot->descriptor == descriptor)) {
            break;
        }
        slot++;
        i++;
    }
    node = nmListAppendNode((void *)iGpffffb588, 0, 0x14);
    request = ((FclBankRequestNode *)node)->request;
    request->descriptor = descriptor;
    request->flags = (s16)(((s16)flags & 0xFF00) | 3);
    return node;
}

/* Marks the other slots with matching request flags; returns 0 if any lacks flag 4. */
// FUN_002E12E0
/* measured: retail keeps the invariant key mask in the loop preheader. */
#pragma opt_loop_invariants on
s32 fclBankScanOthers(FclBankSlot *currentSlot)
{
    FclBankSlot *p;
    s32 i;
    s32 result;

    result = 1;
    p = fclBankWork()->record->slots;
    i = 0;
    for (; i < 2; i++) {
        if (p != currentSlot) {
            s16 flags = p->flags;
            if ((flags & 1) && (flags & 8) &&
                ((flags & 0x100) == (currentSlot->flags & 0x100)) &&
                ((flags & 0x1000) == 0)) {
                p->flags = (s16)(flags | 0x400);
                if (((p->descriptor & 0xFFFF0000) >> 16) ==
                    ((currentSlot->descriptor & 0xFFFF0000) >> 16)) {
                    p->flags = (s16)(p->flags | 0x40);
                }
                if ((p->flags & 4) == 0) {
                    result = 0;
                }
            }
        }
        p++;
    }
    return result;
}
#pragma opt_loop_invariants off

/* measured: an explicit idle case keeps retail's six-entry switch table, and propagation off keeps
 * the fade ratio live across the position getter calls. */
#pragma opt_propagation off
/* Advances each bank's fade state (switch on the state halfword) once per frame. */
// FUN_002E13B0
void fclBankUpdateFades(void)
{
    extern u8 *fclBankGetPositionPtr(s64 bank);
    extern void fclBankSetAlpha(s64 bank, u8 alpha);
    extern void fclBankResume(s64 bank);
    FclBankSlot *slot;
    s32 i;
    s32 fadeTicks;
    s32 ticks;
    s32 x;
    f32 ratio;

    slot = fclBankWork()->record->slots;
    for (i = 0; i < 2; slot++, i++) {
        if (slot->flags & 1) {
            switch ((u16)slot->state) {
            case 0:
                break;
            case 1:
                slot->state = 2;
                slot->flags |= 8;
                slot->flags |= 16;
                slot->flags &= ~4;
                slot->fadeTicks = 0;
                /* fallthrough */
            case 2:
                slot->fadeTicks++;
                if (slot->flags & 0x20) {
                    ticks = slot->fadeTicks;
                    if (slot->flags & 0x100) x = -126;
                    else x = 280;
                } else if (slot->flags & 0x100) {
                    ticks = slot->fadeTicks;
                    x = (s32)((f32)(ticks * 32) / 5.0f + -158.0f);
                } else {
                    ticks = slot->fadeTicks;
                    x = (s32)((1.0f - (f32)ticks / 5.0f) * 32.0f + 280.0f);
                }
                ratio = (f32)ticks / 5.0f;
                /* The position accessor returns a byte pointer; the two f32 components are x then
                 * y. */
                *(f32 *)fclBankGetPositionPtr(slot->index) = (f32)x;
                ((FclBankPosition *)fclBankGetPositionPtr(slot->index))->y = 91.0f;
                fclBankSetAlpha(slot->index, (u8)(ratio * 255.0f));
                fclBankResume(slot->index);
                if (slot->fadeTicks >= 5) {
                    slot->fadeTicks = 0;
                    slot->flags |= 4;
                    slot->flags &= ~16;
                    slot->state = 3;
                }
                break;
            case 3:
                fclBankResume(slot->index);
                break;
            case 4:
                slot->state = 5;
                slot->flags |= 16;
                slot->flags &= ~4;
                slot->fadeTicks = 0;
                /* fallthrough */
            case 5:
                slot->fadeTicks++;
                if (slot->flags & 0x40) {
                    fadeTicks = slot->fadeTicks - 4;
                    if (fadeTicks < 0) fadeTicks = 0;
                } else fadeTicks = slot->fadeTicks;
                fclBankSetAlpha(slot->index, (u8)(255.0f - ((f32)(s32)fadeTicks * 255.0f) / 5.0f));
                fclBankResume(slot->index);
                if (fadeTicks >= 5) {
                    slot->fadeTicks = 0;
                    slot->flags &= ~0x40;
                    slot->flags &= ~8;
                    slot->flags |= 4;
                    slot->flags &= ~16;
                    slot->state = 0;
                }
                break;
            }
        }
    }
}
#pragma opt_propagation on

/* measured: loop invariants stay on so the inlined peer mask is hoisted into the loop preheader, as
 * retail does. */
#pragma opt_loop_invariants on
/* Test for a visible peer on the same side with the same descriptor high half. */
/* Test whether another visible allocated slot shares the descriptor class and bank flag. */
static inline s32 fclBankHasMatchingVisiblePeer(FclBankSlot *slot)
{
    FclBankSlot *peer;
    s32 i;

    peer = fclBankWork()->record->slots;
    i = 0;
    for (; i < 2; i++) {
        if (peer != slot) {
            s16 flags = peer->flags;
            if ((flags & 1) && (flags & 8) &&
                ((flags & 0x100) == (slot->flags & 0x100)) &&
                (((peer->descriptor & 0xFFFF0000) >> 16) ==
                 ((slot->descriptor & 0xFFFF0000) >> 16))) {
                return 1;
            }
        }
        peer++;
    }
    return 0;
}

struct KwlnTask;

/* Acquire queued requests, advance slot lifecycle flags, then step the fades. */
// FUN_002E17F0
s32 fclBankManagerUpdate(u8 *sdkTaskBytes)
{
    struct KwlnTask *task = (struct KwlnTask *)sdkTaskBytes;
    extern void kAssertFail(void *, s32);
    extern s32 fclBankIsWaiting(s64);
    extern void fclBankMarkDone(s64);
    extern u8 D_0063FBD8[], D_0063FBE8[], D_0063FBF8[];
    extern u8 D_0063FC08[], D_0063FC18[], D_0063FC28[];
    FclBankRecord *banks;
    s32 *node;
    s32 *next;
    FclBankSlot *slot;
    s32 i;

    if (iGpffffb588 == NULL) {
        kAssertFail(D_0063FBB0, 681);
    }
    banks = fclBankWork()->record;
    node = (s32 *)fclBankWork()->pendingTail;
    while (node != NULL) {
        next = ((FclBankRequestNode *)node)->next;
        if ((s16)fclBankAcquire(node) == -1) {
            func_00440b68(iGpffffa890, D_0063FBB0, 690);
            fclBankLogf(D_0063FBD8);
            break;
        }
        node = next;
    }
    slot = banks->slots;
    i = 0;
    for (; i < 2; i++) {
        s32 flags = slot->flags;
        if (flags & 1) {
            if (flags & 2) {
                if (fclBankIsWaiting((s16)i)) {
                    slot->flags &= ~2;
                    slot->flags |= 4;
                    if (slot->flags & 0x400) {
                        slot->flags &= ~0x200;
                        slot->flags &= ~0x400;
                    }
                }
            } else if (!(flags & 2) && (flags & 4)) {
                if ((flags & 0x200) && !(banks->readyFlags & 1)) {
                    if (flags & 8) {
                        slot->flags &= ~0x200;
                        func_00440b68(iGpffffa890, D_0063FBB0, 721);
                        fclBankLogf(D_0063FBE8, slot->index);
                    } else if (fclBankScanOthers(slot)) {
                        func_00440b68(iGpffffa890, D_0063FBB0, 725);
                        fclBankLogf(D_0063FBF8, slot->index);
                        slot->flags &= ~0x200;
                        slot->flags &= ~4;
                        slot->state = 1;
                        if (fclBankHasMatchingVisiblePeer(slot)) {
                            slot->flags |= 0x20;
                        }
                    }
                } else if (flags & 0x400) {
                    func_00440b68(iGpffffa890, D_0063FBB0, 736);
                    fclBankLogf(D_0063FC08, slot->index);
                    slot->flags &= ~0x400;
                    if (slot->flags & 8) {
                        slot->flags &= ~4;
                        slot->state = 4;
                    }
                    slot->flags |= 0x1000;
                } else if (flags & 0x800) {
                    if (flags & 8) {
                        slot->flags = (s16)flags | 0x400;
                    } else {
                        func_00440b68(iGpffffa890, D_0063FBB0, 753);
                        fclBankLogf(D_0063FC18, slot->index);
                        slot->flags &= ~0x800;
                        slot->flags &= ~4;
                        slot->flags &= ~1;
                        fclBankMarkDone(slot->index);
                    }
                } else if (flags & 0x1000) {
                    func_00440b68(iGpffffa890, D_0063FBB0, 763);
                    fclBankLogf(D_0063FC28, slot->index);
                    slot->flags &= ~0x1000;
                    slot->flags &= ~4;
                    slot->flags &= ~1;
                    fclBankMarkDone(slot->index);
                }
            }
        }
        slot++;
    }
    fclBankUpdateFades();
    banks->readyFlags &= ~1;
    return 0;
}

#pragma opt_loop_invariants off

