/* Original translation unit k_sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern s32 FldStepTaskCreate(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00764334;

extern u8 *MT_Scene_GetFrameState(void);
extern s32 FldRootCreate(s32 arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4,
                         s16 arg5, s32 arg6, u8 arg7, s64 arg8, s64 arg9,
                         s64 arg10, s64 arg11, s64 arg12, s64 arg13);
extern void kAssertFail(const char *file, s32 line);
extern s32 kwlnTaskGetTaskByName(void *path);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern s32 kwlnTaskIsLinked(s32 buf);
extern void FldLmapCreate(s32 arg0, s32 arg1, s32 arg2);
extern void FldViewerCreate(s32 arg0);
extern void K_Viewer_Create(s32 arg0);
extern void K_MapEdit_Create(s32 arg0);
extern void K_FldFoodCourt_Create(s32 arg0);

extern char D_005F16F8[];
extern u8 D_005F1708[];
extern u8 D_005F1718[];
extern u8 D_005F1730[];
extern u8 D_005F1748[];
extern s32 D_00763028;
extern s32 D_00764434;

/* Source unit: src/promoted/k_sequence.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_sequence.c; members 00170220-00170900 */

// FUN_00170220
void K_SeqFieldRecordStart(u8 *arg0)
{
    s32 temp;

    if (*(u16 *)(arg0 + 0) == 0) {
        kAssertFail(D_005F16F8, 0x38);
    }
    temp = FldRootCreate(0, *(u16 *)(arg0 + 0), *(u16 *)(arg0 + 2),
                         *(u16 *)(arg0 + 4), *(s16 *)(arg0 + 6),
                         *(s16 *)(arg0 + 8), 0, 6, 0x80, 0, -1, -1, -1, -1);
    *(s32 *)MT_Scene_GetFrameState() = temp;
}

// FUN_001702C0
void K_SeqFieldRecordStop(void)
{
    if (*(s32 *)MT_Scene_GetFrameState() != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32 *)MT_Scene_GetFrameState());
        *(s32 *)MT_Scene_GetFrameState() = 0;
    }
}

// FUN_00170310
s32 K_SeqFrameTaskLinked(void)
{
    return kwlnTaskIsLinked(*(s32 *)MT_Scene_GetFrameState()) == 1;
}

// FUN_00170350
void K_SeqFieldPosStart(u8 *arg0)
{
    s32 temp;

    if (*(s32 *)(arg0 + 0xC) == 0) {
        kAssertFail(D_005F16F8, 0x69);
    }
    temp = FldRootCreate(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, *(s32 *)(arg0 + 0xC),
                         *(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x14), 0);
    *(s32 *)MT_Scene_GetFrameState() = temp;
}

// FUN_001703F0
void K_SeqFieldPosStop(void)
{
    if (*(s32 *)MT_Scene_GetFrameState() != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32 *)MT_Scene_GetFrameState());
        *(s32 *)MT_Scene_GetFrameState() = 0;
    }
}

// FUN_00170440
s32 K_SeqFrameTaskAlive(void)
{
    if (kwlnTaskIsLinked(*(s32 *)MT_Scene_GetFrameState()) == 1) {
        return 1;
    }
    *(s32 *)MT_Scene_GetFrameState() = 0;
    return 0;
}

// FUN_001704A0
void K_SeqFldStepStart(u8 *arg0)
{
    D_00764334 = FldStepTaskCreate(0, *(s32 *)(arg0 + 0), *(s32 *)(arg0 + 4));
}

// FUN_001704E0
void K_SeqStepTaskStop(void)
{
    if (D_00764434 != 0) {
        kwlnTaskDestroyWithHierarchy(D_00764434);
        D_00764434 = 0;
        *(s32 *)MT_Scene_GetFrameState() = 0;
    }
}

// FUN_00170520
s32 K_SeqStepTaskAlive(void)
{
    if (kwlnTaskIsLinked(D_00764434) == 1) {
        return 1;
    }
    D_00764434 = 0;
    return 0;
}

// FUN_00170570
void K_SeqFieldViewerStart(void)
{
    FldViewerCreate(0);
}

// FUN_001705A0
s32 K_SeqFieldViewerExists(void)
{
    return kwlnTaskGetTaskByName(D_005F1708) != 0;
}

// FUN_001705D0
void K_SeqFieldViewerStop(void)
{
    s32 temp;

    temp = kwlnTaskGetTaskByName(D_005F1708);
    if (temp == 0) {
        kAssertFail(D_005F16F8, 0xCB);
    }
    kwlnTaskDestroyWithHierarchy(temp);
}

// FUN_00170630
void K_SeqDungeonViewerStart(void)
{
    K_Viewer_Create(0);
}

// FUN_00170660
s32 K_SeqDungeonViewerExists(void)
{
    return kwlnTaskGetTaskByName(D_005F1718) != 0;
}

// FUN_00170690
void K_SeqDungeonViewerStop(void)
{
    s32 temp;

    temp = kwlnTaskGetTaskByName(D_005F1718);
    if (temp == 0) {
        kAssertFail(D_005F16F8, 0xE8);
    }
    kwlnTaskDestroyWithHierarchy(temp);
}

// FUN_001706F0
void K_SeqMapEditStart(void)
{
    K_MapEdit_Create(0);
}

// FUN_00170720
s32 K_SeqMapEditExists(void)
{
    return kwlnTaskGetTaskByName(D_005F1730) != 0;
}

// FUN_00170750
void K_SeqMapEditStop(void)
{
    s32 temp;

    temp = kwlnTaskGetTaskByName(D_005F1730);
    if (temp == 0) {
        kAssertFail(D_005F16F8, 0x105);
    }
    kwlnTaskDestroyWithHierarchy(temp);
}

// FUN_001707B0
void K_SeqLmapStart(s32 *arg0)
{
    FldLmapCreate(0, *arg0, 0);
}

// FUN_001707E0
void K_SeqLmapStartFlagged(void)
{
    FldLmapCreate(0, 0, 1);
}

// FUN_00170810
s32 K_SeqLmapExists(void)
{
    return kwlnTaskGetTaskByName(&D_00763028) != 0;
}

// FUN_00170840
void K_SeqLmapStop(void)
{
    s32 temp;

    temp = kwlnTaskGetTaskByName(&D_00763028);
    if (temp == 0) {
        kAssertFail(D_005F16F8, 0x12B);
    }
    kwlnTaskDestroyWithHierarchy(temp);
}

// FUN_001708A0
void K_SeqFoodCourtStart(void)
{
    K_FldFoodCourt_Create(0);
}

// FUN_001708D0
s32 K_SeqFoodCourtExists(void)
{
    return kwlnTaskGetTaskByName(D_005F1748) != 0;
}

// FUN_00170900
void K_SeqFoodCourtStop(void)
{
    s32 temp;

    temp = kwlnTaskGetTaskByName(D_005F1748);
    if (temp == 0) {
        kAssertFail(D_005F16F8, 0x14A);
    }
    kwlnTaskDestroyWithHierarchy(temp);
}

