#include "member_access.h"
#include "Kosaka/k_field_state_internal.h"
/* Original translation unit k_sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern s32 FldStepTaskCreate(s32 parent, s32 stepIndex, s32 entryValue);
extern s32 D_00764334;

extern u8 *MT_Scene_GetFrameState(void);
extern s32 FldRootCreate(s32 parent, u16 field, u16 room, u16 entry, s16 spawn,
                         s16 direction, s32 sceneFlags, u8 loadMode, s64 secondaryMode, s64 transitionValue,
                         s64 eventId, s64 eventMajor, s64 eventMinor, s64 eventFlags);
extern void kAssertFail(const char *file, s32 line);
extern s32 kwlnTaskGetTaskByName(void *name);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern s32 kwlnTaskIsLinked(s32 target);
extern void FldLmapCreate(s32 parent, s32 selectedSlot, s32 enableToggle);
extern void FldViewerCreate(s32 parentTask);
extern void K_Viewer_Create(s32 parentTask);
extern void K_MapEdit_Create(s32 parent);
extern void K_FldFoodCourt_Create(s32 parent);

extern char D_005F16F8[];
extern u8 D_005F1708[];
extern u8 D_005F1718[];
extern u8 D_005F1730[];
extern u8 D_005F1748[];
extern s32 D_00763028;
extern s32 D_00764434;

/* Source unit: src/promoted/k_sequence.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_sequence.c; members 00170220-00170900 */

/* Payload layouts are read by the corresponding sequence start callbacks. */
typedef struct KSeqFieldParameters {
    u16 fieldId, roomId, entryId;
    s16 unk06, unk08;
} KSeqFieldParameters;
typedef struct KSeqPositionParameters {
    u8 pad00[0xC];
    s32 values[3];
} KSeqPositionParameters;
typedef struct KSeqStepParameters { s32 field, floor; } KSeqStepParameters;

/* Create a root field task from the sequence payload and record its handle. */
// FUN_00170220
void K_SeqFieldRecordStart(u8 *parameters)
{
    s32 task;

    if (((KSeqFieldParameters *)parameters)->fieldId == 0) {
        kAssertFail(D_005F16F8, 0x38);
    }
    task = FldRootCreate(0, ((KSeqFieldParameters *)parameters)->fieldId, ((KSeqFieldParameters *)parameters)->roomId,
                         ((KSeqFieldParameters *)parameters)->entryId, ((KSeqFieldParameters *)parameters)->unk06,
                         ((KSeqFieldParameters *)parameters)->unk08, 0, 6, 0x80, 0, -1, -1, -1, -1);
    ((FldSceneTasks *)MT_Scene_GetFrameState())->root = task;
}

/* Destroy the recorded root field hierarchy and clear its handle. */
// FUN_001702C0
void K_SeqFieldRecordStop(void)
{
    if (((FldSceneTasks *)MT_Scene_GetFrameState())->root != 0) {
        kwlnTaskDestroyWithHierarchy(((FldSceneTasks *)MT_Scene_GetFrameState())->root);
        ((FldSceneTasks *)MT_Scene_GetFrameState())->root = 0;
    }
}

// FUN_00170310
s32 K_SeqFrameTaskLinked(void)
{
    return kwlnTaskIsLinked(((FldSceneTasks *)MT_Scene_GetFrameState())->root) == 1;
}

/* Create a root field task from the alternate payload words and record its handle. */
/* measured: access-site, typed-local, and indexed payload guard forms enlarge this function from
 * 160 to 172 bytes. MEMBER preserves the retail guard while naming the proven payload member. */
// FUN_00170350
void K_SeqFieldPosStart(u8 *parameters)
{
    s32 task;

    if (MEMBER(s32, parameters, KSeqPositionParameters, values[0]) == 0) {
        kAssertFail(D_005F16F8, 0x69);
    }
    task = FldRootCreate(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ((KSeqPositionParameters *)parameters)->values[0],
                         ((KSeqPositionParameters *)parameters)->values[1], ((KSeqPositionParameters *)parameters)->values[2], 0);
    ((FldSceneTasks *)MT_Scene_GetFrameState())->root = task;
}

/* Destroy the alternate field sequence root hierarchy and clear its handle. */
// FUN_001703F0
void K_SeqFieldPosStop(void)
{
    if (((FldSceneTasks *)MT_Scene_GetFrameState())->root != 0) {
        kwlnTaskDestroyWithHierarchy(((FldSceneTasks *)MT_Scene_GetFrameState())->root);
        ((FldSceneTasks *)MT_Scene_GetFrameState())->root = 0;
    }
}

/* Poll the root task and clear its recorded handle once it is unlinked. */
// FUN_00170440
s32 K_SeqFrameTaskAlive(void)
{
    if (kwlnTaskIsLinked(((FldSceneTasks *)MT_Scene_GetFrameState())->root) == 1) {
        return 1;
    }
    ((FldSceneTasks *)MT_Scene_GetFrameState())->root = 0;
    return 0;
}

// FUN_001704A0
void K_SeqFldStepStart(u8 *parameters)
{
    D_00764334 = FldStepTaskCreate(0, ((KSeqStepParameters *)parameters)->field, ((KSeqStepParameters *)parameters)->floor);
}

/* Destroy the recorded step task and clear both step and scene-root handles. */
// FUN_001704E0
void K_SeqStepTaskStop(void)
{
    if (D_00764434 != 0) {
        kwlnTaskDestroyWithHierarchy(D_00764434);
        D_00764434 = 0;
        ((FldSceneTasks *)MT_Scene_GetFrameState())->root = 0;
    }
}

/* Poll the step task and clear its recorded handle once it is unlinked. */
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

/* Look up the sequence task by name, assert when absent, and destroy its hierarchy. */
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

/* Look up the sequence task by name, assert when absent, and destroy its hierarchy. */
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

/* Look up the sequence task by name, assert when absent, and destroy its hierarchy. */
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
void K_SeqLmapStart(s32 *mapId)
{
    FldLmapCreate(0, *mapId, 0);
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

/* Look up the sequence task by name, assert when absent, and destroy its hierarchy. */
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

/* Look up the sequence task by name, assert when absent, and destroy its hierarchy. */
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

