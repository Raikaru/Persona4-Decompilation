#include "mt_scene_internal.h"
/* Whole-file translation unit: src/Event/mt_misc.c */

/* Source unit: src/Event/mt_misc_00290ec0.c */
#include "type.h"
#include "scene_event_internal.h"

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

// Appends a 0x2C-byte entry (param_2 stored at +0x34) to the table at param_1 and bumps its count at +4 [inferred].
// FUN_00290EC0
void mtMiscAppendEntry(int param_1, u32 param_2)
{
    int iVar1;

    iVar1 = *(int *)(param_1 + 4) * 0x2c;
    iVar1 = iVar1 + param_1;

    *(u8 *)(iVar1 + 0x14) = 0;
    *(u32 *)(iVar1 + 0x10) = 0;
    *(u32 *)(iVar1 + 0x38) = 0;
    *(u32 *)(iVar1 + 0x34) = param_2;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;

    return;
}



// Intent: Sets slot arg2 (below 16) of the table to the object resource built from entry arg3 after destroying the slot's previous resource [inferred]
// FUN_00291220
void mtMiscSetSlotRes(int param_1, int param_2, int param_3, u64 param_4)
{
    u16 sVar1;
    u16 uVar2;
    u16 *puVar5;
    int iVar4;

    if (((param_2 < 0x10) && (param_3 < *(int *)(param_1 + 4))) &&
        MT_Scene_GetObject() != 0) {
        iVar4 = (int)param_2 * 2;
        iVar4 = iVar4 + param_1;
        puVar5 = (u16 *)(iVar4 + 0x170);
        sVar1 = *(u16 *)(iVar4 + 0x170);
        if (sVar1 != 0) {
            if (MT_Scene_GetRes(sVar1) != 0) {
                MT_Scene_DestroyRes(sVar1);
            }
            *puVar5 = 0;
        }
        if (*(int *)(param_1 + 4) <= param_3) {
            iVar4 = 0;
        }
        else {
            iVar4 = *(int *)((u8 *)(uintptr_t)(param_3 * 0x2c) + (uintptr_t)param_1 + 0x34);
        }
        if (iVar4 != 0) {
            uVar2 = MT_Scene_CreateObjectRes((int)param_2 + 200U & 0xffff, iVar4, param_4);
            func_00440b68(DAT_0063c8a0, uVar2);
            MT_Scene_SetResActiveById(uVar2, 1);
            *puVar5 = uVar2;
        }
    }
    return;
}



// Intent: Returns the resource id held in slot arg2 (below 16), or 0 when the slot is empty or no object is active [inferred]
// FUN_00291360
s32 mtMiscGetSlotRes(int param_1, int param_2)
{
    int lVar2;

    if (param_2 >= 0x10) {
        return 0;
    }

    lVar2 = MT_Scene_GetObject();

    if (lVar2 == 0) {
        return 0;
    }

    return *(u16 *)((u8 *)((int)param_2 * 2) + param_1 + 0x170);
}



// Intent: Destroys the resource in slot arg2 (below 16) and clears the slot [inferred]
// FUN_002913D0
void mtMiscClearSlotRes(int param_1, int param_2)
{
    u16 *puVar5;
    u16 sVar1;
    int iVar4;

    if ((param_2 < 0x10) && (MT_Scene_GetObject() != 0)) {
        iVar4 = (int)param_2 * 2;
        iVar4 = iVar4 + param_1;
        puVar5 = (u16 *)(iVar4 + 0x170);
        sVar1 = *(u16 *)(iVar4 + 0x170);
        if (sVar1 != 0) {
            if (MT_Scene_GetRes(sVar1) != 0) {
                MT_Scene_DestroyRes(sVar1);
                func_00440b68(DAT_0063c8c0);
            }
            *puVar5 = 0;
        }
    }
    return;
}



// Intent: Destroys every slot resource of the table and clears the slots [inferred]
// FUN_00291470
void mtMiscClearAllSlotRes(int param_1)
{
    u16 *puVar5;
    u16 sVar1;
    int iVar3;
    int iVar4;

    for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {
        if ((iVar4 < 0x10) && (MT_Scene_GetObject() != 0)) {
            iVar3 = param_1 + iVar4 * 2;
            puVar5 = (u16 *)(iVar3 + 0x170);
            sVar1 = *(u16 *)(iVar3 + 0x170);
            if (sVar1 != 0) {
                if (MT_Scene_GetRes(sVar1) != 0) {
                    MT_Scene_DestroyRes(sVar1);
                    func_00440b68(DAT_0063c8c0);
                }
                *puVar5 = 0;
            }
        }
    }
    return;
}



// Plays sound cue param_1 on the sound system; returns 0 [inferred].
// FUN_00298100
u64 mtMiscPlayCue(s16 param_1)
{
    sdkSndPlayCue(param_1, 1);

    return 0;
}



// Intent: Stops sound channel arg1 by fading it out over arg2 frames when arg2 is nonzero, otherwise resets the channel [inferred]
// FUN_00298190
u64 mtMiscStopSoundChannel(s16 param_1, int param_2)
{
    int iVar1;

    iVar1 = param_2;
    if (iVar1 != 0) {
        sdkSndFadeOutChannelFrames(param_1, 0, param_2);
    }
    else {
        sdkSndResetChannel(param_1, 0, param_2);
    }

    return 0;
}
