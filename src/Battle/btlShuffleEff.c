#include "byte_address_internal.h"
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
/* The callee's real signature is (f32 *, f32 *, f32); this prototype puts the float second because
 * retail loads the arguments in that order. */
extern void btlShuffleCalcStepPose(f32 *screen, f32 output, f32 *depth);
extern void btlShuffleCalcLookAt(f32 *output, f32 *point);

/* measured: retail adds the index before the base, which only happens when the operands go through
 * this helper's parameters. */


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
    BtlShuffleEffectSlot *slot;

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < 9; i++) {
        if (((BtlShuffleEffectWork *)work)->activeMask & (u16)(1 << i)) {
            slotBase = work + i * 8 + 8;
            slot = (BtlShuffleEffectSlot *)slotBase;
            src = &D_0064F110[i * 7];
            stepPoint[0] = src[0];
            stepPoint[1] = src[1];
            btlShuffleCalcStepPose(&stepPoint[0], src[2], &position[0]);
            btlShuffleCalcLookAt(position, position);
            /* A dedicated slot alias keeps retail's reload of slot->effect before each effect call. */
            mdlEffectSetChildPositionVec(slot->effect, position);
            mdlEffectSetEulerRotation(slot->effect, src[3], src[4], src[5]);
            mdlEffectSetUniformScale(slot->effect, src[6]);
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
    BtlShuffleEffectWork *effects;

    work = ((struct KwlnTask *)task)->work;
    effects = (BtlShuffleEffectWork *)work;
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
        if (!(effects->activeMask & (u16)mask)) {
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
    slot = (u8 **)((u32)byteAddressAdd(slotIndex * 8, (u8 *)((u32)eff)) + 0xC);
    held = ((BtlShuffleEffectSlot *)(((slotIndex * 8) + ((u32)eff)) + 8))->effect;
    if (held != 0) {
        mdlEffectDestroy(held);
        *slot = 0;
    }
    /* measured: retail computes the mask before loading the halfword, which the compound assignment
     * does and a separate load does not. */
    ((BtlShuffleEffectWork *)eff)->activeMask &= ~(1 << slotIndex);
}
