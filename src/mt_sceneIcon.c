#include "resrc_manager_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit mt_sceneIcon.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern s32 H_Cdvd_LookupRequest(s32 pathAddress, void *slot);
extern u8 *mdlEffectCreateFromResource(s32 resource);
extern void MT_Scene_SpawnIconTask(s32 effectHandle);
extern s32 D_0063B4F0[];

/* Allocated by mtSceneIconSpawnTask (0x10 bytes); resource index and request
 * result are words, while the scene resource id is a halfword. */
typedef struct MtSceneIconLoadWork {
    u32 state;
    u16 resourceId;
    u8 pad06[2];
    u32 iconIndex;
    s32 request;
} MtSceneIconLoadWork;

typedef int (*code)();
extern code DAT_008873ec_abs[];

/* gp - 0x5908 = 0x007637E8. */
extern u8 iGpffffa6f8;
/* gp - 0x5900 = 0x007637F0. */
extern u8 iGpffffa700;
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

// lint: allow H011 -- measured: u16 prototype regresses func_0026da30 (andi on the wide icon id); retail declared this old-style
extern u8 *MT_Scene_GetRes();
extern void mdlEffectStart(s32 a);
/* measured: returns 0 / -1 in $v0; the task dispatcher discards it, so the callback site casts. */
extern s32 mtSceneIconTaskUpdate(u8 *unusedTask);
extern u8 D_0063B558[];
extern u8 D_0063B568[];
extern void func_00440b68(u8 *fmt, u8 *file, s32 line);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void H_Cdvd_ReadSync(u8 *cdvd);



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// Loads the scene icon directory: logs its debug name and syncs the directory read [inferred].
// FUN_0026D840
void mtSceneIconLoadDirectory(void)
{
    func_00440b68(&iGpffffa6f8, D_0063B558, 0x38);
    H_Cdvd_ReadSync(H_Cdvd_AcquireDirectory(D_0063B568, 1));
}

// Scene icon task update: state 0 starts the icon lookup request; state 1 attaches the loaded handle to the icon resource and spawns any previous handle [inferred].
// FUN_0026D890
s32 mtSceneIconTaskUpdate(u8 *unusedTask)
{
    u8 requestInfo[4];
    u8 *handle;
    u8 *work;
    ResrcRecord *icon;
    s32 resourceAddress;
    s32 kind;
    s32 previousEffect;
    u32 iconIndex;
    s32 request;

    work = (u8 *)kwlnTaskGetWork();
    switch (((MtSceneIconLoadWork *)work)->state) {
    case 0:
        iconIndex = ((MtSceneIconLoadWork *)work)->iconIndex;
        if (iconIndex > 0x1AU) {
            request = 0;
        } else if (D_0063B4F0[iconIndex] == 0) {
            request = 0;
        } else {
            request = H_Cdvd_LookupRequest(D_0063B4F0[iconIndex], &requestInfo[0]);
        }
        ((MtSceneIconLoadWork *)work)->request = request;
        ((MtSceneIconLoadWork *)work)->state = 1;
        break;
    case 1:
        handle = mdlEffectCreateFromResource(((MtSceneIconLoadWork *)work)->request);
        if ((resourceAddress = (s32)MT_Scene_GetRes(((MtSceneIconLoadWork *)work)->resourceId)) != 0) {
            icon = (ResrcRecord *)resourceAddress;
            kind = (icon->resTypeId & 0xFFC00) >> 0xA;
            if (kind == 1) {
                previousEffect = (s32)icon->slotHandle[0];
                if (previousEffect != 0) {
                    MT_Scene_SpawnIconTask(previousEffect);
                }
                icon->slotHandle[0] = handle;
            } else if (kind == 3) {
                previousEffect = (s32)icon->slotHandle[0];
                if (previousEffect != 0) {
                    MT_Scene_SpawnIconTask(previousEffect);
                }
                icon->slotHandle[0] = handle;
            }
        }
        return -1;
    }
    return 0;
}
// Scene icon task destroy: calls the release callback on the task's work block [inferred].
// FUN_0026D9F0
void mtSceneIconTaskDestroy(u8 *unusedTask)
{
    int workAddress;

    workAddress = kwlnTaskGetWork();
    DAT_008873ec_abs[0](workAddress);
}

// Starts the icon effect for kind 1 or 3 when arg1 is 0xA and the icon handle is set (returns 0); otherwise spawns mtSceneIconTaskUpdate for the resource [inferred].
// FUN_0026DA30
s32 mtSceneIconSpawnTask(s32 resourceId, s32 iconIndex)
{
    u8 *icon;
    u8 *work;
    s32 kind;

    if (iconIndex == 0xA) {
        icon = MT_Scene_GetRes(resourceId);
        /* measured: the NULL return is an `else` clause, not an early return, so
           its zero lands after the two kind blocks exactly as retail places it. */
        if (icon != NULL) {
            kind = (((ResrcRecord *)icon)->resTypeId & 0xFFC00) >> 10;
            if (kind == 1) {
                if ((s32)((ResrcRecord *)icon)->slotHandle[1] != 0) {
                    mdlEffectStart((s32)((ResrcRecord *)icon)->slotHandle[1]);
                    return 0;
                }
            } else if (kind == 3) {
                if ((s32)((ResrcRecord *)icon)->slotHandle[1] != 0) {
                    mdlEffectStart((s32)((ResrcRecord *)icon)->slotHandle[1]);
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
    chkmemAllocSiteTag(D_0063B558, 0xC1);
    work = D_008873F4[0](1, 0x10, 0x40000);
    ((MtSceneIconLoadWork *)work)->resourceId = resourceId;
    ((MtSceneIconLoadWork *)work)->iconIndex = iconIndex;
    return (s32)kwlnTaskCreate((const void *)(&iGpffffa700), 0xF, 0, 0, mtSceneIconTaskUpdate, mtSceneIconTaskDestroy, (u8 *)(work));
}

