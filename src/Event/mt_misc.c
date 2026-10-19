#include "mt_scene_internal.h"
/* Whole-file translation unit: src/Event/mt_misc.c */

/* Source unit: src/Event/mt_misc_00290ec0.c */
#include "type.h"
#include "scene_event_internal.h"
#include "evt_effect_internal.h"

extern int MT_Scene_GetObject();
extern int MT_Scene_DestroyRes();
extern u16 MT_Scene_CreateObjectRes(u32, int, u64);
extern void func_00440b68(...);
extern void MT_Scene_SetResActiveById(u16, int);
extern char DAT_0063c8a0[];
extern char DAT_0063c8c0[];

extern int sdkSndPlayCue();

extern int sdkSndFadeOutChannelFrames();
extern int sdkSndResetChannel();


/* opt_loop_invariants on: measured nd 124 -> 0, object 292/304 -> 292/304. */

/* Append a direct resource-data entry to the effect table and advance its count. */
// FUN_00290EC0
void mtMiscAppendEntry(int tableAddress, u32 resourceData)
{
    int entryAddress;

    entryAddress = ((EvtEffectTable *)tableAddress)->count * 0x2c;
    entryAddress = entryAddress + tableAddress;

    ((EvtEffectEntry *)(entryAddress + 0x10))->filename[0] = 0;
    ((EvtEffectEntry *)(entryAddress + 0x10))->kind = 0;
    ((EvtEffectEntry *)(entryAddress + 0x10))->request = NULL;
    ((EvtEffectEntry *)(entryAddress + 0x10))->lookupResult = resourceData;
    ((EvtEffectTable *)tableAddress)->count = ((EvtEffectTable *)tableAddress)->count + 1;

    return;
}



/* Replace a slot resource with the object created from the selected effect entry. */
// FUN_00291220
void mtMiscSetSlotRes(int tableAddress, int slotIndex, int entryIndex, u64 creationFlags)
{
    u16 oldResourceId;
    u16 resourceId;
    u16 *slot;
    int value;

    if (((slotIndex < 0x10) && (entryIndex < ((EvtEffectTable *)tableAddress)->count)) &&
        MT_Scene_GetObject() != 0) {
        value = (int)slotIndex * 2;
        value = value + tableAddress;
        slot = &((EvtEffectTable *)value)->slots[0];
        oldResourceId = ((EvtEffectTable *)value)->slots[0];
        if (oldResourceId != 0) {
            if (MT_Scene_GetRes(oldResourceId) != 0) {
                MT_Scene_DestroyRes(oldResourceId);
            }
            *slot = 0;
        }
        /* measured: typing this remaining count reload loses MATCH across the resource callbacks. */
        if (*(int *)(tableAddress + 4) <= entryIndex) {
            value = 0;
        }
        else {
            value = ((EvtEffectEntry *)((u8 *)(uintptr_t)(entryIndex * 0x2c) + (uintptr_t)tableAddress + 0x10))->lookupResult;
        }
        if (value != 0) {
            resourceId = MT_Scene_CreateObjectRes((int)slotIndex + 200U & 0xffff, value, creationFlags);
            func_00440b68(DAT_0063c8a0, resourceId);
            MT_Scene_SetResActiveById(resourceId, 1);
            *slot = resourceId;
        }
    }
    return;
}



/* Return the slot resource id, or zero for an unavailable slot or scene. */
// FUN_00291360
s32 mtMiscGetSlotRes(int tableAddress, int slotIndex)
{
    int sceneObject;

    if (slotIndex >= 0x10) {
        return 0;
    }

    sceneObject = MT_Scene_GetObject();

    if (sceneObject == 0) {
        return 0;
    }

    return ((EvtEffectTable *)((u8 *)((int)slotIndex * 2) + tableAddress))->slots[0];
}



/* Destroy the selected slot resource, if present, and clear its resource id. */
// FUN_002913D0
void mtMiscClearSlotRes(int tableAddress, int slotIndex)
{
    u16 *slot;
    u16 oldResourceId;
    int value;

    if ((slotIndex < 0x10) && (MT_Scene_GetObject() != 0)) {
        value = (int)slotIndex * 2;
        value = value + tableAddress;
        slot = &((EvtEffectTable *)value)->slots[0];
        oldResourceId = ((EvtEffectTable *)value)->slots[0];
        if (oldResourceId != 0) {
            if (MT_Scene_GetRes(oldResourceId) != 0) {
                MT_Scene_DestroyRes(oldResourceId);
                func_00440b68(DAT_0063c8c0);
            }
            *slot = 0;
        }
    }
    return;
}



// Intent: Destroys every slot resource of the table and clears the slots [inferred]
// FUN_00291470
void mtMiscClearAllSlotRes(int tableAddress)
{
    u16 *slot;
    u16 oldResourceId;
    int slotAddress;
    int slotIndex;

    for (slotIndex = 0; slotIndex < 0x10; slotIndex = slotIndex + 1) {
        if ((slotIndex < 0x10) && (MT_Scene_GetObject() != 0)) {
            slotAddress = tableAddress + slotIndex * 2;
            slot = &((EvtEffectTable *)slotAddress)->slots[0];
            oldResourceId = ((EvtEffectTable *)slotAddress)->slots[0];
            if (oldResourceId != 0) {
                if (MT_Scene_GetRes(oldResourceId) != 0) {
                    MT_Scene_DestroyRes(oldResourceId);
                    func_00440b68(DAT_0063c8c0);
                }
                *slot = 0;
            }
        }
    }
    return;
}



/* Play the cue on the sound system; the command result is always zero. */
// FUN_00298100
u64 mtMiscPlayCue(s16 cueId)
{
    sdkSndPlayCue(cueId, 1);

    return 0;
}



/* Stop a channel by fading over fadeFrames, or reset it immediately for zero. */
// FUN_00298190
u64 mtMiscStopSoundChannel(s16 channel, int fadeFrames)
{
    int duration;

    duration = fadeFrames;
    if (duration != 0) {
        sdkSndFadeOutChannelFrames(channel, 0, fadeFrames);
    }
    else {
        sdkSndResetChannel(channel, 0, fadeFrames);
    }

    return 0;
}
