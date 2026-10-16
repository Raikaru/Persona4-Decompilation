#include "include_asm.h"
/* Original translation unit sequenceList.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void btlTaskCreate(void);
extern void btlSetFreeUnitsOnTeardown(void);

extern s32 func_00103590(void);
extern s32 fclBankTaskCreate(void);
extern void titleStartSoundTask(s32);
extern s32 btlIsRunning(void);
extern void func_002853b0(void);
extern s32 func_002853c0(void);
extern void func_0029e8d0(void *);
extern void seqYajiTaskCreate(void);
extern s32 func_002bdb50(s32, s8);
extern s32 func_002e7510(s32);
extern s32 fclCombineTaskCreate(s32);
extern void func_0034b8c0(void);
extern s32 kwlnTaskGetTaskByName(void *);
extern void kwlnTaskDestroyWithHierarchy(s32);
extern void kAssertFail(const void *, u32);
extern s32 mwPlayerCreate(s32, s16, void *);
extern void *mwPlayerGetTaskName(void);

extern char D_005DCB58[];
extern char D_005DCB68[];
extern char D_005DCB80[];
extern char D_005DCB98[];
extern char D_005DCBB0[];
extern char D_005DCBC0[];
extern char D_005DCBD0[];
extern char D_005DCBE8[];
extern char D_005DCC00[];
extern char D_00763A30[];
extern char D_007963A0[];
extern char D_007616B0;



// FUN_00102BE0
void SeqInitDataRead_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCB58);

    if (handle != 0) {
        if (handle == 0) {
            kAssertFail(D_005DCB68, 0x56);
        }
        kwlnTaskDestroyWithHierarchy(handle);
    }
}

// FUN_00102C50
void SeqMemcardBootCheck_Start(void)
{
    titleStartSoundTask(0);
}

// FUN_00102C80
s32 SeqMemcardBootCheck_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCB80) != 0);
}

// FUN_00102CB0
void SeqMemcardBootCheck_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCB80);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x74);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00102D10
void SeqDebugMenu_Start(void)
{
    func_00103590();
}

// FUN_00102D30
s32 SeqDebugMenu_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCB98) != 0);
}

// FUN_00102D60
void SeqDebugMenu_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCB98);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x95);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00102DC0
void SeqSample_Start(void)
{
    fclBankTaskCreate();
}

// FUN_00102DE0
s32 SeqSample_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(&D_007616B0) != 0);
}

// FUN_00102E10
void SeqSample_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(&D_007616B0);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0xB2);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// Intent: the BATTLE sequence's start callback (sequence id 6). It destroys the
// field resource archives before the battle loads.
// FUN_00102E70
void K_Fldrc_DestroyArchives(void)
{
    btlTaskCreate();
    btlSetFreeUnitsOnTeardown();
}

// FUN_00102EA0
s32 SeqBattle_IsRunning(void)
{
    return (s32)(btlIsRunning() != 0);
}

// FUN_00102ED0
void SeqBattle_End(void)
{
    s32 handle = btlIsRunning();

    if (handle != 0) {
        kwlnTaskDestroyWithHierarchy(handle);
    }
}

// FUN_00102F10
void SeqScriptViewer_Start(void)
{
    if (kwlnTaskGetTaskByName(D_005DCBB0) == 0) {
        func_0029e8d0(0);
    }
}

// FUN_00102F50
s32 SeqScriptViewer_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCBB0) != 0);
}

// FUN_00102F80
void SeqScriptViewer_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCBB0);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x145);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00102FE0
void SeqEvent_Start(void)
{
    if (func_002853c0() == 0) {
        func_002853b0();
    }
}

// FUN_00103010
s32 SeqEvent_IsRunning(void)
{
    return (s32)(func_002853c0() != 0);
}

// FUN_00103040
void SeqEvent_End(void)
{
    s32 handle = func_002853c0();

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x165);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_001030A0
void SeqYaji_Start(void)
{
    seqYajiTaskCreate();
}

// FUN_001030C0
s32 SeqYaji_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCBC0) != 0);
}

// FUN_001030F0
void SeqYaji_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCBC0);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x180);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00103150
void SeqNowatari_Start(void)
{
    func_0034b8c0();
}

// FUN_00103170
s32 SeqNowatari_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_00763A30) != 0);
}

// FUN_001031A0
void SeqNowatari_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_00763A30);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x19B);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00103200
void SeqWeaponStore_Start(void)
{
    func_002bdb50(0, 0);
}

// FUN_00103230
s32 SeqWeaponStore_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCBD0) != 0);
}

// FUN_00103260
void SeqWeaponStore_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCBD0);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x1B8);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_001032C0
void SeqItemStore_Start(void)
{
    func_002e7510(0);
}

// FUN_001032F0
s32 SeqItemStore_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCBE8) != 0);
}

// FUN_00103320
void SeqItemStore_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCBE8);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x1D7);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00103380
void SeqCombine_Start(void)
{
    fclCombineTaskCreate(0);
}

// FUN_001033B0
s32 SeqCombine_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005DCC00) != 0);
}

// FUN_001033E0
void SeqCombine_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005DCC00);

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x1F3);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

// FUN_00103440
void SeqMovie_Start(s16 *arg0)
{
    mwPlayerCreate(0, *arg0, &D_007963A0);
}

// FUN_00103480
s32 SeqMovie_IsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(mwPlayerGetTaskName()) != 0);
}

// FUN_001034B0
void SeqMovie_End(void)
{
    s32 handle = kwlnTaskGetTaskByName(mwPlayerGetTaskName());

    if (handle == 0) {
        kAssertFail(D_005DCB68, 0x20F);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}
