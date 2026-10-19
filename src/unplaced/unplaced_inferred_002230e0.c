/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 002230e0-002238c0 */

#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
typedef struct KwlnTask KwlnTask;

u8 *kwlnTaskGetTaskByName(s8 *name);
u32 kwlnTaskGetWork(void *task);
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag();
extern void memset();
extern s32 btlResultHeroLvUpRun(u8 *task);
extern void btlResultDestroyHeroLevelUpWork(u8 *task);
extern void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback);
extern s32 btlResultOverlayTick(u8 *task);
extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern void PrimAppendNode(u8 *list, u8 *node);
extern u8 *shdPersonaTaskCreate(s32 parent, s32 priority, s32 mode, s32 layout, s32 option);
extern void shdPersonaSetPersonaId(u8 *window, s32 value);
extern void shdPersonaSetOrigin(u8 *window, f32 *position);
extern void shdPersonaStartSlideIn(u8 *window);
extern void shdPersonaSetDisplayState(u8 *window, s32 mode, u32 persona, s8 option);
extern u8 *shdPersonaLevelUpCreate(s32 parent, s32 window, u8 *record, s32 payload, s32 option, s32 *messages);
extern u32 shdPersonaLevelUpIsDone(u8 *child);
extern s32 shdPersonaDestroyTask(u8 *child);
extern s32 datMemberNoticeTryBegin(s32 mode);
extern s32 btlShuffleOverlayIdle(void);
extern void kAssertFail(const void *file, u32 line);
extern void btlResultOverlayOnEvent();
extern void btlResultOverlayDestroy(u8 *task);
extern u8 D_00629640[];
extern u8 D_006296B0[];
extern u8 D_006296E8[];
u8 *H_Cdvd_GetArchiveEntry(u8 *arg0, s32 arg1, s32 *arg2);
extern void (*jtbl_008873EC[])(void *arg0);
extern void shdPersonaFinishPhase(u8 *arg0);
// Intent: Create the logo title task and its child draw. [inferred]
// FUN_002230E0
s32 btlLogoTitleCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_00629698, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x74, 0x40000);
    memset(temp_2, 0, 0x74);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00629640), 0xF, 0, 0, btlResultHeroLvUpRun, btlResultDestroyHeroLevelUpWork, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 0xC, 0, 0x30);
    *(void (**)(u8 *, s32, void *))((u8 *)(temp_2) + 0x14) = btlLogoDraw;
    *(u8 **)((u8 *)(temp_2) + 0x1C) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}

// Intent: Advance the logo title task state after its overlay finishes. [inferred]
// FUN_002231E0
void btlLogoTitleAdvance(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(kwlnTaskGetWork(task));
    *(s32 *)((u8 *)(temp_2) + 8) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        btlShuffleStartOverlay();
        *(s32 *)((u8 *)(temp_2) + 4) = 4;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 5;
}

// Intent: Report whether the logo title task is ready (flag bit 1). [inferred]
// FUN_00223240
s32 btlLogoTitleIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}

// Intent: Report whether the logo title task exists by name. [inferred]
// FUN_00223270
s32 btlLogoTitleExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_00629640) != 0;
}

// Intent: Run the result overlay state machine for one tick. [inferred]
// FUN_002232A0
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma opt_propagation off
s32 btlResultOverlayTick(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *work;
    u8 *results;
    u8 *persona;
    u8 *payload;
    s32 index;
    s32 messages[11];
    f32 position[2];

    work = (u8 *)kwlnTaskGetWork(task);
    results = *(u8 **)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    PrimAppendNode(D_00795F20, work + 8);

    switch (*(u32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = (u16)datPersonaCountValidMembers();
        *(u8 **)(work + 0x4C) = shdPersonaTaskCreate(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0) {
            kAssertFail(D_006296D0, 0x2F);
        }
        shdPersonaSetPersonaId(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        shdPersonaSetOrigin(*(u8 **)(work + 0x4C), position);
        shdPersonaStartSlideIn(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        results += 0x60;
        while ((index = *(s32 *)(work + 0x3C)) < *(s32 *)(work + 0x38)) {
            u32 reward;

            persona = (u8 *)datPersonaRosterSlot((s16)index);
            reward = *(u32 *)(results + 8 + *(s32 *)(work + 0x3C) * 4);
            *(u32 *)(persona + 8) += reward;
            index = *(s32 *)(work + 0x3C);
            if (*(u8 *)(index * 0x88 + results + 0x38) > 0) {
                break;
            }
            *(s32 *)(work + 0x3C) = index + 1;
        }
        /* Constructor and transitions maintain 0 <= index <= count <= 12.
         * Consequently this arm always has a persona produced by the loop. */
        if (index != *(s32 *)(work + 0x38)) {
            s32 recordIndex;

            shdPersonaSetDisplayState(*(u8 **)(work + 0x4C), 1, (u32)persona, 0);
            messages[0] = 12;
            messages[1] = 0;
            messages[2] = 6;
            messages[3] = 9;
            messages[4] = 10;
            messages[5] = 11;
            messages[6] = 13;
            messages[7] = 14;
            messages[8] = 19;
            messages[9] = 20;
            messages[10] = 21;
            payload = H_Cdvd_GetArchiveEntry(
                *(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0);
            recordIndex = *(s32 *)(work + 0x3C);
            *(u8 **)(work + 0x50) = shdPersonaLevelUpCreate(
                (s32)task, *(s32 *)(work + 0x4C),
                results + recordIndex * 0x88 + 0x38,
                (s32)payload, 0, messages);
            *(u16 *)work |= 2;
            *(s32 *)(work + 4) = 2;
        } else if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;
    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (shdPersonaLevelUpIsDone(*(u8 **)(work + 0x50)) == 0) {
            break;
        }
        shdPersonaDestroyTask(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        if (++*(u16 *)(work + 0x48) < 45) {
            if ((*(u16 *)(D_008C0240 + 0xE) & 0x50) == 0) {
                if ((*(u16 *)(D_008C0240 + 0xC) & 0x10) == 0) {
                    break;
                }
                if (*(u16 *)(work + 0x48) < 4) {
                    break;
                }
            }
        }
        *(s32 *)(work + 0x3C) += 1;
        *(s32 *)(work + 4) = 1;
        break;
    case 5:
        if (datMemberNoticeTryBegin(1) != 0) {
            break;
        }
        *(u16 *)work &= 0xFFFE;
        *(s32 *)(work + 4) = 8;
        break;
    case 6:
        if (btlShuffleOverlayIdle() == 0) {
            break;
        }
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) == 0) {
            if (++*(u16 *)(work + 0x48) < 5) {
                break;
            }
        }
        *(u16 *)work &= 0xFFFD;
        return -1;
    case 8:
    default:
        break;
    }
    return 0;
}

#pragma push
#pragma opt_propagation on
// Intent: Result overlay event callback; ignores events once the flag is set. [inferred]
// FUN_002236B0
void btlResultOverlayOnEvent(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Destroy the result overlay task work. [inferred]
// FUN_002236C0
void btlResultOverlayDestroy(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *p;
    s32 h;

    p = (u8 *)kwlnTaskGetWork(task);
    if (*(u16 *)p & 4) {
        h = *(s32 *)(p + 0x4C);
        if (h != 0) {
            shdPersonaFinishPhase((u8 *)h);
            *(s32 *)(p + 0x4C) = 0;
        }
    }
    (*jtbl_008873EC)(p);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Create the result overlay task. [inferred]
// FUN_00223730
s32 btlResultOverlayCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_006296E8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x54, 0x40000);
    memset(temp_2, 0, 0x54);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_006296B0), 0xF, 0, 0, btlResultOverlayTick, btlResultOverlayDestroy, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x40) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(btlResultOverlayOnEvent);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Start the result overlay and set its state. [inferred]
// FUN_00223830
void btlResultOverlayStart(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(kwlnTaskGetWork(task));
    *(s16 *)((u8 *)(temp_2) + 0x48) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        btlShuffleStartOverlay();
        *(s32 *)((u8 *)(temp_2) + 4) = 6;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 7;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Report whether the result overlay is ready. [inferred]
// FUN_00223890
s32 btlResultOverlayIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Report whether the result overlay task exists by name. [inferred]
// FUN_002238C0
s32 btlResultOverlayExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_006296B0) != 0;
}
#pragma pop
