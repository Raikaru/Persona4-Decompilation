#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit mt_sceneIcon.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern s32 H_Cdvd_LookupRequest(s32 arg0, void *arg1);
extern u8 *func_004b1130(s32 arg0);
extern void MT_Scene_SpawnIconTask(s32 arg0);
extern s32 D_0063B4F0[];

typedef int (*code)();
extern code DAT_008873ec_abs[];

/* gp - 0x5908 = 0x007637E8. */
extern u8 iGpffffa6f8;
/* gp - 0x5900 = 0x007637F0. */
extern u8 iGpffffa700;
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

// lint: allow H011 -- measured: u16 prototype regresses func_0026da30 (andi on the wide icon id); retail declared this old-style
extern u8 *MT_Scene_GetRes();
extern void func_004b1170(s32 a);
/* measured: returns 0 / -1 in $v0; the task dispatcher discards it, so the callback site casts. */
extern s32 mtSceneIconTaskUpdate(u8 *arg0);
extern u8 D_0063B558[];
extern u8 D_0063B568[];
extern void func_00440b68(u8 *fmt, u8 *file, s32 line);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 mode);
extern void H_Cdvd_ReadSync(u8 *handle);



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
s32 mtSceneIconTaskUpdate(u8 *arg0)
{
    u8 sp3C[4];
    u8 *handle;
    u8 *w;
    u8 *icon;
    s32 icon_raw;
    s32 kind;
    s32 prev;
    u32 idx;
    s32 res;

    w = (u8 *)kwlnTaskGetWork();
    switch (*(u32 *)w) {
    case 0:
        idx = *(u32 *)(w + 8);
        if (idx > 0x1AU) {
            res = 0;
        } else if (D_0063B4F0[idx] == 0) {
            res = 0;
        } else {
            res = H_Cdvd_LookupRequest(D_0063B4F0[idx], &sp3C[0]);
        }
        *(s32 *)(w + 0xC) = res;
        *(u32 *)w = 1;
        break;
    case 1:
        handle = func_004b1130(*(s32 *)(w + 0xC));
        if ((icon_raw = (s32)MT_Scene_GetRes(*(u16 *)(w + 4))) != 0) {
            icon = (u8 *)icon_raw;
            kind = (*(u16 *)icon & 0xFFC00) >> 0xA;
            if (kind == 1) {
                prev = *(s32 *)(icon + 0x140);
                if (prev != 0) {
                    MT_Scene_SpawnIconTask(prev);
                }
                *(u8 **)(icon + 0x140) = handle;
            } else if (kind == 3) {
                prev = *(s32 *)(icon + 0x140);
                if (prev != 0) {
                    MT_Scene_SpawnIconTask(prev);
                }
                *(u8 **)(icon + 0x140) = handle;
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
    int iVar1;

    iVar1 = kwlnTaskGetWork();
    DAT_008873ec_abs[0](iVar1);
}

// Releases the scene icon handle for kind 1 or 3 when it is set, returning 0 once released [inferred].
// FUN_0026DA30
s32 mtSceneIconReleaseRes(s32 arg0, s32 arg1)
{
    u8 *icon;
    u8 *mem;
    s32 kind;

    if (arg1 == 0xA) {
        icon = MT_Scene_GetRes(arg0);
        /* measured: the NULL return is an `else` clause, not an early return, so
           its zero lands after the two kind blocks exactly as retail places it. */
        if (icon != NULL) {
            kind = (*(u16 *)icon & 0xFFC00) >> 10;
            if (kind == 1) {
                if (*(s32 *)(icon + 0x144) != 0) {
                    func_004b1170(*(s32 *)(icon + 0x144));
                    return 0;
                }
            } else if (kind == 3) {
                if (*(s32 *)(icon + 0x144) != 0) {
                    func_004b1170(*(s32 *)(icon + 0x144));
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
    chkmemAllocSiteTag(D_0063B558, 0xC1);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    *(s16 *)(mem + 4) = arg0;
    *(s32 *)(mem + 8) = arg1;
    return (s32)kwlnTaskCreate((const void *)(&iGpffffa700), 0xF, 0, 0, mtSceneIconTaskUpdate, mtSceneIconTaskDestroy, (u8 *)(mem));
}

