#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_shuffle_effect_internal.h"

extern void kAssertFail(const void *file, u32 line);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0064F0F0[];
extern f32 D_0064F110[];
extern u8 D_0064F210[];
extern s32 btlShuffleGetDrawContext(void *task);
extern s32 btlShuffleEffStep(u8 *task);
extern void btlShuffleEffRelease(u8 *task);
extern void btlShuffleEffInitTrail(u8 *task, s32 slotIndex);

extern u8 *mdlEffectCreateFromResource();
extern void mdlEffectDestroy(u8 *model);
extern void mdlEffectStart(s32 a);
extern void mdlEffectSetChildPositionVec(void *object, void *position);
extern void mdlEffectSetEulerRotation(u8 *object, f32 angleX, f32 angleY, f32 angleZ);
extern void mdlEffectSetUniformScale(u8 *effect, f32 scale);
/* The callee's real signature is (f32 *, f32 *, f32); this caller-side prototype keeps the
   float in the second position because mwcc b210 materialises call args in declaration
   order, and retail's bytes (addiu a0 / lwc1 f12 / addiu a1 before the jal) require that. */
extern void btlShuffleCalcStepPose(f32 *screen, f32 output, f32 *depth);
extern void btlShuffleCalcLookAt(f32 *output, f32 *point);

/* measured: the operands must travel through this helper's parameters to get
   retail's index-first `addu $v1,$v1,$s0`; rewriting the callsite expression as
   `offset + (u32)base` is canonicalized straight back to the base-first form. */
static inline u32 bseSlot(u32 offset, u32 contextAddress)
{
    return offset + contextAddress;
}

/* Destroy every live trail effect and release the task work allocation. */
// FUN_0038D6C0
void btlShuffleEffFree(u8 *task) {
    u8 *work;
    s32 i;
    u8 *slotBase;
    u8 **eff;

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < 9; i++) {
        if (i < 0 || i >= 9) {
            kAssertFail(&D_0064F210[0], 0x55);
        }
        slotBase = work + i * 8;
        eff = &((BtlShuffleEffectSlot *)(slotBase + 8))->effect;
        if (*eff != 0) {
            mdlEffectDestroy(*eff);
            *eff = 0;
        }
        ((BtlShuffleEffectWork *)work)->activeMask &= ~(1 << i);
    }
    (*jtbl_008873EC)(work);
}
/* Allocate nine trail slots and create their child task with the persistent trail enabled. */
// FUN_0038D790
u8 *btlShuffleEffSpawn(u8 *task) {
    u8 *work;
    u8 *childTask;

    chkmemAllocSiteTag(&D_0064F210[0], 0x103);
    work = D_008873F4[0](1, 0x50, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064F210[0], 0x104);
    }
    childTask = (u8 *)(s32)kwlnTaskCreateChild((void *)(task), (const void *)(&D_0064F0F0[0]), 0x13, 0, 0, btlShuffleEffStep, btlShuffleEffFree, (u8 *)(work));
    if (childTask == NULL) {
        kAssertFail(&D_0064F210[0], 0x10E);
    }
    ((BtlShuffleEffectWork *)work)->context = (s32)btlShuffleGetDrawContext(task);
    btlShuffleEffRelease(childTask);
    return childTask;
}

/* Clear transient trails while preserving and initializing the persistent ninth slot. */
// FUN_0038D890
void btlShuffleEffRelease(u8 *task) {
    s32 i;
    u8 *work;
    u8 *slotBase;
    u8 **eff;

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < 9; i++) {
        if (i != 8) {
            if (i < 0 || i >= 9) {
                kAssertFail(&D_0064F210[0], 0x55);
            }
            slotBase = work + i * 8;
            eff = &((BtlShuffleEffectSlot *)(slotBase + 8))->effect;
            if (*eff != 0) {
                mdlEffectDestroy(*eff);
                *eff = 0;
            }
            ((BtlShuffleEffectWork *)work)->activeMask &= ~(1 << i);
        }
    }
    btlShuffleEffInitTrail(task, 8);
}

/* Restart each effect selected by the active-slot mask. */
// FUN_0038D970
void btlShuffleEffEnd(u8 *task) {
    s32 i;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < 9; i++) {
        if (((BtlShuffleEffectWork *)work)->activeMask & (u16)(1 << i)) {
            mdlEffectStart((s32)((BtlShuffleEffectWork *)work)->slots[i].effect);
        }
    }
}

/* Place active effects from the seven-float position, rotation and scale table. */
// FUN_0038D9F0
void btlShuffleEffUpdate(u8 *task) {
    s32 i;
    u8 *work;
    u8 *slotBase;
    f32 *src;
    f32 stepPoint[2];
    f32 position[3];

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < 9; i++) {
        if (((BtlShuffleEffectWork *)work)->activeMask & (u16)(1 << i)) {
            slotBase = work + i * 8 + 8;
            src = &D_0064F110[i * 7];
            stepPoint[0] = src[0];
            stepPoint[1] = src[1];
            btlShuffleCalcStepPose(&stepPoint[0], src[2], &position[0]);
            btlShuffleCalcLookAt(position, position);
            /* measured: typing the earlier effect reloads grows this function from 256 to 268 bytes. */
            /* measured: either earlier typed effect reload grows Update from 256 to 268 bytes. */
            mdlEffectSetChildPositionVec(*(u8 **)(slotBase + 4), position);
            mdlEffectSetEulerRotation(*(u8 **)(slotBase + 4), src[3], src[4], src[5]);
            mdlEffectSetUniformScale(((BtlShuffleEffectSlot *)slotBase)->effect, src[6]);
        }
    }
}

/* Lazily create a resource-backed trail slot, restart it and play its category cue. */
// FUN_0038DAF0
void btlShuffleEffInitTrail(u8 *task, s32 slotIndex) {
    u8 *work;
    u8 *slotBase;
    u8 **eff;
    s32 contextAddress;
    s32 resourceOffset;
    s32 mask;
    s32 slotOffset;

    work = ((struct KwlnTask *)task)->work;
    contextAddress = ((BtlShuffleEffectWork *)work)->context;
    if (slotIndex < 0 || slotIndex >= 9) {
        kAssertFail(&D_0064F210[0], 0x165);
    }
    resourceOffset = slotIndex * 4;
    if (((BtlShuffleContext *)(resourceOffset + contextAddress))->modelBlobs[0] != 0) {
        if (slotIndex < 0 || slotIndex >= 9) {
            kAssertFail(&D_0064F210[0], 0x3E);
        }
        mask = 1 << slotIndex;
        /* measured: typing this mask test changes InitTrail register allocation; the mask store remains typed. */
        if (!(*(u16 *)(work + 4) & (u16)mask)) {
            slotOffset = slotIndex * 8;
            slotBase = (u8 *)(slotOffset + (s32)work);
            eff = &((BtlShuffleEffectSlot *)(slotBase + 8))->effect;
            if (*eff != 0) {
                kAssertFail(&D_0064F210[0], 0x42);
            }
            *eff = mdlEffectCreateFromResource(((BtlShuffleContext *)(resourceOffset + ((BtlShuffleEffectWork *)work)->context))->modelBlobs[0]);
            ((BtlShuffleEffectWork *)work)->activeMask |= (u16)mask;
        }
        slotOffset = slotIndex * 8;
        slotBase = (u8 *)(slotOffset + (s32)work);
        ((BtlShuffleEffectSlot *)(slotBase + 8))->frame = 0;
        mdlEffectStart((s32)((BtlShuffleEffectSlot *)(slotBase + 8))->effect);
        switch (slotIndex) {
        case 0:
        case 1:
        case 2:
            sdkSndStartStream(1, 5, 5, 9);
            break;
        case 3:
        case 4:
        case 5:
            sdkSndStartStream(1, 5, 5, 0xB);
            break;
        case 6:
        case 7:
        case 8:
            break;
        default:
            kAssertFail(&D_0064F210[0], 0x180);
            break;
        }
    }
}
/* The window artifact this note used to describe is fixed: 0x0038DD60 is now a
   canonical nullsub boundary (see DATA_REACHABLE_ENTRIES in
   tools/reconcile_function_boundaries.py, justified by the callback-table word
   at 0x005DD2A4), so the window is 160B and the body fills it exactly. */
/* Destroy one trail slot and clear its active bit. */
// FUN_0038DCC0
void btlShuffleEffSetup(u8 *task, s32 slotIndex)
{
    u8 *eff;
    u8 **slot;
    u8 *held;

    eff = ((struct KwlnTask *)task)->work;
    if (slotIndex < 0 || slotIndex >= 9) {
        kAssertFail(&D_0064F210[0], 0x55);
    }
    /* measured: typing only the slot address grows Setup from 160 to 164 bytes; the effect load is typed. */
    slot = (u8 **)(bseSlot(slotIndex * 8, (u32)eff) + 0xC);
    held = ((BtlShuffleEffectSlot *)(bseSlot(slotIndex * 8, (u32)eff) + 8))->effect;
    if (held != 0) {
        mdlEffectDestroy(held);
        *slot = 0;
    }
    /* measured: the compound assignment evaluates the mask before loading the
       halfword, which is retail's order; a mask local plus an explicit load lets
       b210 hoist the lhu above the shift chain. */
    ((BtlShuffleEffectWork *)eff)->activeMask &= ~(1 << slotIndex);
}
