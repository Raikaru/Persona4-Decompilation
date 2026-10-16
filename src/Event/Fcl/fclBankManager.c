/* Original translation unit fclBankManager.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "include_asm.h"
#include "fcl_bank_internal.h"



extern char iGpffffa890[8];
extern int iGpffffa898;

extern void func_00446e88(u8 *, s32 *);
extern u8 *func_002e2170(void *, void *, s32);
typedef struct NmlistNode NmlistNode;
typedef struct NmlistList NmlistList;
extern NmlistNode *func_002e2240(NmlistList *, NmlistList *, int *);
extern s32 func_00440b68(const char *, ...);
extern void fclBankSlotConfigure(s16, s16, s16, s16);
extern void fclBankSetActive(s64, s32);
extern char D_0063FBB0[];
extern char D_0063FBC8[];

// Variadic wrapper (PS2 SDK pattern, mirrors src/h_dbprt.c); call sites pass
// whatever tail args they have.
extern void fclBankLogf(u8 *, ...);

// PS2 SDK va_list: the register-save area is the spill block mwcc emits for
// __builtin_args_info; mirrors src/h_dbprt.c.
typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)




/* Variadic bank log: forwards the format and its varargs to func_00446e88. */
// FUN_002E0EA0
void fclBankLogf(u8 *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    func_00446e88(fmt, (s32 *)args);
}

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
        s32 *next = *(s32 **)((u8 *)node + 0x10);
        func_002e2240((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
        node = next;
    }
    func_00440b68(iGpffffa890, D_0063FBB0, 0xCA);
    fclBankLogf((u8 *)&iGpffffa898);
}

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

// FUN_002E0FB0
s32 func_002e0fb0(void)
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

static inline s16 findUnusedBank(FclBankRecord *banks)
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

static inline s16 findReusableBank(FclBankRecord *banks)
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

/* Measured: wide selection and return retain retail narrowing boundaries;
   the low-halfword index store keeps the original selected register.
   Exact 500/512 bytes, with twelve zero tail bytes. */
/* Places node in a free or reusable bank slot; returns the slot index or -1. */
// FUN_002E1030
s64 fclBankAcquire(int *node)
{
    FclBankSlot *slot;
    s64 selected;
    FclBankRecord *banks;
    u8 *payload;

    banks = fclBankWork()->record;
    selected = findUnusedBank(banks);
    if (selected == -1)
        selected = findReusableBank(banks);
    if ((s16)selected == -1)
        return -1;
    payload = *(u8 **)((u8 *)node + 0x14);
    slot = (FclBankSlot *)((u8 *)banks + 4 + (s16)selected * 20);
    slot->descriptor = *(u32 *)(payload + 4);
    slot->flags = *(s16 *)payload;
    slot->index = (u16)selected;
    fclBankSlotConfigure(selected, (s16)((slot->descriptor & 0xFFFF0000U) >> 16),
                 (s16)((slot->descriptor & 0xFF00) >> 8), (s16)(slot->descriptor & 0xFF));
    fclBankSetActive(slot->index, 1);
    slot->flags |= 1;
    slot->flags |= 2;
    func_002e2240((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
    func_00440b68(iGpffffa890, D_0063FBB0, 0x19D);
    fclBankLogf((u8 *)D_0063FBC8, slot->index);
    return selected;
}

// FUN_002E1230
void fclBankQueueRequest(s32 arg0, s64 arg1)
{
    s32 i;
    FclBankSlot *slot;
    u8 *q;

    slot = fclBankWork()->record->slots;
    i = 0;
    while (i < 2) {
        if ((slot->flags & 1) && ((s32)slot->descriptor == arg0)) {
            break;
        }
        slot++;
        i++;
    }
    q = *(u8 **)(func_002e2170((void *)iGpffffb588, 0, 0x14) + 0x14);
    *(s32 *)(q + 4) = arg0;
    *(s16 *)q = (s16)(((s16)arg1 & 0xFF00) | 3);
}

/* measured: retail hoists the 0xFFFF0000 mask into the loop preheader
   (lui $t0,0xffff between i=0 and the branch) and keeps v in $t1; mwcc b210
   sinks the lui to the first use inside the loop (rematerializing at the
   first and) and cascades every following register choice/branch offset
   (nd 26). Tried: inline mask, u32 local mask (declared first/last/mid,
   assigned at declaration or as a pre-loop statement), 0xFFFF0000U suffix —
   all give the identical nd 26. This is the load-sinking floor. */
/* measured: the best exploratory C scored nd 117 (object 184B / window
   208B); it was size-deficit and discarded. The historical nd 26 note above
   describes a discarded body, not a retained target. */
/* Marks the other slots whose key matches arg0; returns 0 if any of them lacks flag 4. */
// FUN_002E12E0
/* measured: retail keeps the invariant key mask in the loop preheader. */
#pragma opt_loop_invariants on
s32 fclBankScanOthers(FclBankSlot *arg0)
{
    FclBankSlot *p;
    s32 i;
    s32 result;

    result = 1;
    p = fclBankWork()->record->slots;
    i = 0;
    for (; i < 2; i++) {
        if (p != arg0) {
            s16 flags = p->flags;
            if ((flags & 1) && (flags & 8) &&
                ((flags & 0x100) == (arg0->flags & 0x100)) &&
                ((flags & 0x1000) == 0)) {
                p->flags = (s16)(flags | 0x400);
                if (((p->descriptor & 0xFFFF0000) >> 16) ==
                    ((arg0->descriptor & 0xFFFF0000) >> 16)) {
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

/* Measured: explicit idle case retains the six-entry switch table, while
   propagation off keeps the fade ratio across position getters. Direct
   float-to-u8 conversion retains both retail conversion branches. */
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
                *(f32 *)fclBankGetPositionPtr(slot->index) = (f32)x;
                *(f32 *)(fclBankGetPositionPtr(slot->index) + 4) = 91.0f;
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

/* measured: 1236/1248B, 54 resolved relocations, zero executable differences,
   twelve zero tail bytes. Keep the inlined peer mask in its loop preheader. */
#pragma opt_loop_invariants on
static inline s32 bankSlotHasMatchingVisiblePeer(FclBankSlot *slot)
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
        next = *(s32 **)((u8 *)node + 0x10);
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
                        if (bankSlotHasMatchingVisiblePeer(slot)) {
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

