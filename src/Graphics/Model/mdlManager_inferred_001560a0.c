#include "h_cdvd.h"
#include "byte_address_internal.h"

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_frame_internal.h"
#include "rw_types_internal.h"
#include "field_scene_internal.h"
#include "scene_resource_internal.h"
#include "h_cdvd_request_internal.h"
#include "rw_camera_internal.h"
#include "member_access.h"
typedef struct FldTileAttributePair {
    union { s16 directions; u8 directionBytes[2]; };
    s16 attributes;
} FldTileAttributePair;

/* The template copy is 0x2B halfwords; the three-by-three attributes start
 * at 0x32 and the five-by-five placement mask starts at 0x18. */
typedef struct FldTileTemplate {
    s8 type;
    u8 width;
    u8 height;
    u8 unk03;
    u8 attributeIds[9];
    u8 flags[9];
    s8 maskX;
    s8 maskY;
    u8 placementMask[25];
    u8 unk31;
    FldTileAttributePair attributes[9];
} FldTileTemplate;

/* Selection rows have a 12-byte stride: two counts and ten signed template IDs. */
typedef struct FldTileTemplateSet {
    u8 count;
    u8 bandBCount;
    s8 templates[10];
} FldTileTemplateSet;

/* Allocated as 0x48 bytes by FldStepTaskCreate. */
typedef struct FldStepWork {
    s32 state;
    union { s32 stepIndex; u32 unsignedStepIndex; };
    union { s32 entryValue; u16 entryHalf[2]; };
    s32 finished;
    u8 unk10[4];
    union { s32 fileHandle; u8 *filePointer; };
    union { s32 rootTask; u8 *rootPointer; };
    s32 panelTask;
    union { u8 *entries; s32 entriesAddress; };
    s32 flags;
    u8 unk28[4];
    union { u8 *scriptData; s32 scriptAddress; u32 scriptWord; };
    s32 scriptSize;
    u8 unk34[4];
    s32 modelObject;
    u8 unk3C[4];
    s32 preloadTasks[2];
} FldStepWork;

/* The root-task getters and value-step writer establish these offsets. */
typedef struct FldRootWork {
    s32 state;
    u8 unk04[4];
    s32 workValue;
    u8 unk0C[0x0C];
    u16 fieldId;
    u16 roomId;
    u8 unk1C[4];
    u16 mapState;
    u8 unk22[0xB6];
    s16 stepValues[5];
} FldRootWork;

/* Eight encounter slots occupy 0xB40 bytes; each record pointer is at 0x160. */
typedef struct FldEncounterSlot {
    s32 active;
    u8 unk04[4];
    s32 mode;
    u8 unk0C[2];
    u16 id;
    u8 unk10[0x150];
    u8 *record;
    u8 unk164[4];
} FldEncounterSlot;
typedef struct FldSavedCell {
    u8 occupied, flags, type, kind, shapeX, shapeZ, exits, attributes;
} FldSavedCell;
typedef struct FldSavedEncounter {
    u8 active, mode;
    u16 id;
    s32 recordKind;
} FldSavedEncounter;
/* The twenty floor grids, reveal masks, encounter rows and count tables
 * exactly span the 0xF8FC-byte block cleared by FldStepResetTables. */
typedef struct FldStepSavedTables {
    u8 visited[20];
    FldSavedCell grids[20][24][16];
    u8 revealMasks[20][0x30];
    FldSavedEncounter encounters[20][8];
    u8 activeCounts[20];
    u8 bandValues[20];
} FldStepSavedTables;
typedef struct FldUnitVisibilityState {
    u8 unk00[0x48];
    s32 active;
    u8 unk4C[8];
    u8 *resource;
} FldUnitVisibilityState;
/* Later versions append more count/pointer pairs before the record stream. */
typedef struct FldPointTableHeader {
    u32 unk00;
    u32 version;
    u32 volumeCount;
    u32 unk0C;
    u32 pointCount;
    u32 unk14;
    u32 secondaryPointCount;
    u32 unk1C;
    u32 tertiaryPointCount;
    u32 unk24;
    u32 extraPointCount;
    u32 unk2C;
    u32 lightCount;
    u32 unk34;
    u32 finalPointCount;
} FldPointTableHeader;
/* Step records have a 0x10-byte stride; the root-task call consumes this prefix. */
typedef struct FldStepEntryRecord {
    u16 fieldId, roomId;
    s32 value;
    u8 unk08, unk09;
    u16 flags;
    u8 unk0C[4];
} FldStepEntryRecord;
/* Field-model resources use the common scene prefix and store a parent
 * at 0x140 and model at 0x144. The toggle at 0x150 remains unidentified. */
typedef struct SceneFieldModelResource {
    ResrcHeader base;
    union { u32 parentAddress; u8 *parent; };
    union { s32 modelAddress; u8 *model; };
    u8 unk148[8];
    union { s32 unk150; u32 unk150Bits; };
} SceneFieldModelResource;

extern s32 iGpffffb210;

extern s32 kwlnGetCurrentWorkValue(void);
extern void fieldSceneUnload();
extern void FldAuxBufferRelease(void);
extern u8 *D_00764334;
extern void func_00440b68();
extern s32 iGpffff9e28;
extern s32 iGpffffb218;
extern u8 D_007D3E10[];
extern u8 D_007E36E4[];
extern u8 D_007E36F8[];
extern u8 D_005F05E8[];
extern u8 D_005F06C0[];
extern u8 D_005F0740[];
extern u8 D_005F0760[];
extern u8 D_005F06E0[];
extern u8 D_005F0700[];
extern u8 D_005F0770[];
extern u8 D_005F0720[];
extern u8 D_005F0670[];
extern s16 D_005F05D0[];
extern u8 D_005F05CE[];
extern u8 D_007D3E2B[];
extern void memset(void *dst, s32 value, u32 size);
extern void sprintf(void *dst, const char *fmt, ...);
extern void strcpy(void *dst, const char *fmt);
extern u8 *iGpffffb244;
extern s32 D_007E8060[];
extern u8 *iGpffff9db0;
extern s32 FldMap_IsCurrentInBandA();
extern s32 FldMap_IsCurrentInBandB(void);
extern void FldResource_Destroy(s32 resource);
extern s32 FldRc_FileLoadIsReady();
extern void kAssertFail();
extern void memcpy();
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 FldRc_CreateFileLoadTask();
extern s32 H_Cdvd_FileExists(void *path);
extern s32 H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern u8 D_005EFF60[];
extern s32 D_007D2510[];
extern u8 D_007D24F0[];
extern u8 D_005EFFE0[];
extern s32 FldLoadTaskUpdate(u8 *task);
extern void fldLoadTaskOnDestroy(u8 *unusedTask);

extern void MT_Scene_SetWorkPresentFlag(s32 task, s32 presentWork);
extern u8 D_007E31E4[];
extern u8 D_005F0650[];
extern u32 datGetFlag(s32 bit);
extern s32 datSetFlag(s32 flagId, s32 enabled);
extern s32 FldStepTaskUpdate(u8 *task);
extern void FldStepTaskDestroy(u8 *task);
extern void FldCellCreateResources(u16 parentId, u32 column, u32 row);
extern s32 FldMap_IsCurrentInEitherBand(void);
extern void FldFrame_SetStateFlags(s32 task, s32 value);
extern void MT_Scene_ReleaseWork(s32 task);
extern void mdlDestroyModelObject(u8 *model);
/* measured: retail adds the offset first at two board scans and the preload-task lookup, so
 * byteAddressAdd is used there. */


extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern s32 mdlGetClump(s32 model);
extern s32 *MT_Scene_GetFrameState(void);
extern u8 *mdlGetMatrix(s32 model);
extern s32 K_Clump_ClumpHasMatUsrData(s32 clump, const void *name);
extern u8 D_005F0690[];
extern u8 D_005F06A0[];
extern s32 FldFrameTask_GetTileX(s32 task);
extern s32 FldFrameTask_GetTileZ(s32 task);
extern f32 KDraw_MatrixYawDeg(u8 *matrix);
extern void FldCellFloodFillDirected(s32 column, s32 row, u8 incoming, u8 limitedDirections,
                          s32 axisMask, s32 depth, u8 limit, s32 *visibleCount);
extern s32 D_0076430C;
extern u8 D_007E8C00[];
extern s32 D_007E8020[];
extern u8 D_005F057C[];
extern u8 D_005F0590[];
extern u8 D_007E80A0[];
extern s32 D_0076432C;
extern s32 iGpffffb2e4;
extern void smapClearRevealTable(void);
extern u8 *smapRevealTablePtr(void);
extern u8 *Encount_FindRecord(s32 field, s32 room, u16 index, u16 mode);
extern u8 D_005F0080[];
extern u8 D_005F0591[];
extern u32 D_00764314;
extern u32 D_00764324;
extern u32 D_00764328;
extern u32 RpRandom(void);
extern void FldTileRotateAttributes(void *templateData, u32 directionMask);
extern s32 FldCellFindPlacement(void *templateData, u32 *outX, u32 *outY);
extern void FldCellPlaceShape(u8 *shape, u16 x0, u16 y0, s16 kind);
extern void FldCellFloodFill(s32 x, s32 y, s32 incoming, s32 depth,
                          s32 limit, s32 *foundTypeTwo, s32 *foundHighType);
/* Place the selected special tile using its direction and narrowed cell coordinates. measured:
 * calling FldCellPlaceShape directly changes argument load order in the spread routine. */
static inline void fldPlaceSpecialShape(u8 specialDirection, s32 x, s32 y,
                                        u8 *tile)
{
    FldCellPlaceShape(tile, (u16)x, (u16)y, specialDirection);
}

extern s32 kwlnGetCamera(void);
extern s32 mdlPrepareModel(s32 model);
extern void (*jtbl_008873EC[])(void *);
/* Unit settings shared by the surrounding scene, board and step routines. */
#pragma opt_loop_invariants on
#pragma opt_propagation on
// Stores three values into the task's work block, clears two halfwords, starts the step and sets
// the state to 0x11.
// FUN_001560A0
void MT_Scene_BeginValueStep(u8 *task, u16 firstValue, u16 secondValue, u16 thirdValue) {
    u8 *workBlock;

    workBlock = (u8 *)(((SdkTask *)task)->work);
    ((FldRootWork *)workBlock)->stepValues[0] = firstValue;
    ((FldRootWork *)workBlock)->stepValues[1] = secondValue;
    ((FldRootWork *)workBlock)->stepValues[2] = thirdValue;
    ((FldRootWork *)workBlock)->stepValues[3] = 0;
    ((FldRootWork *)workBlock)->stepValues[4] = 0;
    fadeBeginTransition(1, 0);
    ((FldRootWork *)workBlock)->state = 0x11;
}

// Sets the work block's workValue after the subsystem reset call.
// FUN_001560F0
void MT_Scene_SetWorkValue(u8 *task, s32 value) {
    u8 *p;

    if (task != NULL) {
        p = ((SdkTask *)task)->work;
        func_00440b68(D_005EFF60);
        ((FldRootWork *)p)->workValue = value;
    }
}

// Reports whether a field-load task has reached state 13 or later; a null task counts as done.
// FUN_00156140
s32 FldLoadTaskIsDone(u8 *task)
{
    if (task == NULL) {
        return 1;
    }
    return ((FldRootWork *)((SdkTask *)task)->work)->state >= 0xD;
}

// Returns the field id requested by a field-load task.
// FUN_00156170
s32 FldLoadTaskFieldId(u8 *task)
{
    return ((FldRootWork *)((SdkTask *)task)->work)->fieldId;
}

// Returns the room id requested by a field-load task.
// FUN_00156180
s32 FldLoadTaskRoomId(u8 *task)
{
    return ((FldRootWork *)((SdkTask *)task)->work)->roomId;
}

// Returns the map state requested by a field-load task.
// FUN_00156190
s32 FldLoadTaskMapState(u8 *task)
{
    return ((FldRootWork *)((SdkTask *)task)->work)->mapState;
}

typedef struct FldLoadWork {
    s32 state;
    s32 mode;
    u16 fieldId;
    u16 roomId;
    s16 mapState;
    s16 environmentState;
    s32 storyGroup;
    s32 storyEntry;
    u8 *file;
    s32 scriptTask;
} FldLoadWork;

void MT_Scene_ApplyCameraParams(void);

#pragma push
/* measured: with propagation on, retail's argument loads come out in a different form, so
 * propagation is off. */
#pragma opt_propagation off
// Field-load task state machine: opens the primary file, loads map and environment, runs the scene
// load and applies camera parameters; returns -1 when finished.
// FUN_001561A0
s32 FldLoadTaskUpdate(u8 *task)
{
    extern s16 datGetDateIndex(void);
    extern u8 datGetTimeSlot(void);
    extern s64 calGetDayEntryByPhase(s32 day, u32 phase);
    extern s32 cmmTableLookupFlagged(s32 keyHigh, s32 keyLow, s32 kind);
    extern void calendarPushValue(s16 value);
    extern void loadingSpinnerRequestShow(void);
    extern s32 FldResource_IsPrimaryFileLoaded(void);
    extern s32 FldMap_IsInBandA(s32 fieldId, s32 roomId);
    extern u8 *FldHbnOpenScript(s32 fieldId);
    extern s32 FldHbnLoadScriptBuffer(u8 *request, s32 fieldId);
    extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
    extern s32 kwlnTaskIsLinked(void *target);
    extern void fieldSceneLoad(s32 fieldId, s32 roomId);
    extern void fieldSceneRequestRoom(s64 roomId);
    extern void fieldSceneRequestSecondaryRoom(s64 roomId);
    extern s32 FldHbnLoadEntryTable(u8 *request);
    extern s32 fieldSceneLoadStep(void);
    extern s32 FldMap_IsInEitherBand(s32 fieldId, s32 roomId);
    extern s32 FldRc_CreateFileLoadTask(u8 *parent, u8 *path, s32 duration, s32 loadSource);
    extern s32 FldRc_FileLoadIsReady(u8 *task);
    extern s32 FldCameraTaskCreate(s32 parentTask);
    extern s32 D_007D3D64[];
    extern s32 D_007D3D68[];
    extern s32 iGpffffb268;
    extern s32 iGpffffb20c;
    extern s32 D_007D2544[];
    extern u8 D_005EFF80[];
    extern u8 D_005EFFA0[];
    extern u8 D_005EFFC0[];
    extern s32 D_007D2514[];
    extern s32 D_007D2548[];
    extern s32 D_007D254C[];
    extern s32 D_007E3710[];
    extern s32 D_007E3714[];
    extern s32 D_007E3718[];
    s32 selection;
    s32 selectedEnvironment;
    s32 day;
    s32 initialDay;
    s32 condition;
    s32 script;
    s32 scriptSize;
    u8 *file;
    s32 fieldId;
    FldLoadWork *work;

    work = (FldLoadWork *)((SdkTask *)task)->work;
    if (work->state > 2 && datGetFlag(0x1470) == 0) {
        loadingSpinnerRequestShow();
    }
    switch (work->state) {
    case 0:
        if (FldResource_IsPrimaryFileLoaded() == 0) {
            break;
        }
        if (FldMap_IsInBandA(work->fieldId, work->roomId) == 0) {
            work->file = FldHbnOpenScript(work->fieldId);
        }
        work->state = 1;
        /* Begin polling the request submitted above. */
    case 1:
        file = work->file;
        if (FldHbnLoadScriptBuffer(file, work->fieldId) == 0) {
            break;
        }
        work->file = NULL;
        iGpffffb210 = 0;
        if (work->mode == 0 && D_007D3D64[0] != 0 && iGpffffb268 == 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = scrStartProcedureChecked(0xF, D_007D3D64[0], scriptSize, work->roomId - 1);
        }
        work->state++;
    case 2:
        if (work->mode == 0) {
            script = work->scriptTask;
            if (script != 0 && kwlnTaskIsLinked((void *)script) == 1) {
                break;
            }
        }
        fieldId = work->fieldId;
        work->file = FldHbnOpenTable(fieldId, work->roomId);
        fieldSceneLoad(work->fieldId, work->roomId);
        fieldSceneRequestRoom(work->mapState);
        if (work->environmentState != 0) {
            fieldSceneRequestSecondaryRoom(work->environmentState);
        } else {
            selection = -1;
            selectedEnvironment = 0;
            if (work->mode == 1) {
                initialDay = (s16)datGetDateIndex();
                condition = (s8)calGetDayEntryByPhase(initialDay, datGetTimeSlot() & 0xFF);
                selection = cmmTableLookupFlagged(work->storyGroup, work->storyEntry, condition);
                if (selection != -1) {
                    if ((selection & 0x8000) != 0) {
                        selectedEnvironment = selection & 0x7FF;
                    } else {
                        iGpffffb20c = 1;
                        calendarPushValue((s16)selection);
                    }
                }
            }
            if (selectedEnvironment == 0) {
                if (selection == -1) {
                    day = (s16)datGetDateIndex();
                    selection = (s8)calGetDayEntryByPhase(day, datGetTimeSlot() & 0xFF);
                }
                work->environmentState = FldEnvResolveState(work->fieldId, work->roomId, selection);
            } else {
                work->environmentState = selectedEnvironment;
            }
            fieldSceneRequestSecondaryRoom(work->environmentState);
        }
        work->state++;
    case 3:
        if (FldHbnLoadEntryTable(work->file) == 0) {
            break;
        }
        work->file = NULL;
        if (fieldSceneLoadStep() == 0) {
            break;
        }
        iGpffffb210 = 1;
        if (D_007D3D64[0] != 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = scrStartProcedureChecked(0xF, D_007D3D64[0], scriptSize, work->roomId - 1);
        }
        work->state++;
    case 4:
        script = work->scriptTask;
        if (script != 0 && kwlnTaskIsLinked((void *)script) == 1) {
            break;
        }
        if (FldMap_IsInEitherBand(work->fieldId, work->roomId) == 0) {
            D_007D2544[0] = FldRc_CreateFileLoadTask(NULL, D_005EFF80, -1, D_007E3710[0]);
            D_007D2548[0] = FldRc_CreateFileLoadTask(NULL, D_005EFFA0, -1, D_007E3714[0]);
            D_007D254C[0] = FldRc_CreateFileLoadTask(NULL, D_005EFFC0, -1, D_007E3718[0]);
        }
        work->state++;
    case 5:
        if (FldMap_IsInEitherBand(work->fieldId, work->roomId) == 0 &&
            (FldRc_FileLoadIsReady((u8 *)D_007D2544[0]) == 0 ||
             FldRc_FileLoadIsReady((u8 *)D_007D2548[0]) == 0 ||
             FldRc_FileLoadIsReady((u8 *)D_007D254C[0]) == 0)) {
            break;
        }
        /* The camera task is parented to the active field task. */
        D_007D2514[0] = FldCameraTaskCreate(D_007D2510[0]);
        MT_Scene_ApplyCameraParams();
        work->state = 8;
    case 8:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma pop

/* Registered field-load task destructor; the native callback performs no cleanup. */
// FUN_00156630
void fldLoadTaskOnDestroy(u8 *unusedTask)
{
}

// Creates a field-load task under the given parent, stores its request fields and opens the primary
// file.
// FUN_00156640
s32 FldLoadTaskCreate(u8 *parent, s32 fieldId, s32 roomId, s16 mapState, s16 environmentState,
                  s32 mode, s32 storyGroup, s32 storyEntry)
{
    FldLoadWork *base;
    s32 loadTask;

    memset(D_007D24F0, 0, 0x20);
    base = (FldLoadWork *)D_007D24F0;
    loadTask = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFFE0), 0xF, 0, 0, FldLoadTaskUpdate, fldLoadTaskOnDestroy, (u8 *)(base));
    base->fieldId = fieldId;
    base->roomId = roomId;
    base->mapState = mapState;
    base->environmentState = environmentState;
    base->mode = mode;
    base->storyGroup = storyGroup;
    base->storyEntry = storyEntry;
    FldResource_OpenPrimaryFile(fieldId, roomId);
    return loadTask;
}

// Unloads the previous field scene for the task's request; a second unload runs for the listed map
// states.
// FUN_00156750
void FldLoadTaskUnloadScene(u8 *task)
{
    u8 *work;
    u16 value;

    work = ((SdkTask *)task)->work;
    FldAuxBufferRelease();
    if ((kwlnGetCurrentWorkValue() != 9) && (kwlnGetCurrentWorkValue() != 0xB) && (kwlnGetCurrentWorkValue() != 0xA)) {
        fieldSceneUnload();
    }
    value = ((FldRootWork *)work)->fieldId;
    if ((((s32)value >= 0x15) && ((s32)value <= 0x1E)) ||
        ((value == 6) && (value = ((FldRootWork *)work)->roomId, value == 1))) {
        fieldSceneUnload(value);
    }
}


/* Rotate the low four directional bits and wrap their overflow into the nibble. */
static inline u32 fldTileRotateNibble(u32 bits, s32 turns)
{
    u32 shifted = (bits & 0xF) << turns;
    return (shifted & 0xF) | (shifted >> 4);
}

/* Rotates the field tile's attribute pairs by the direction mask; each saved pair is the actual
 * record displaced along its rotation cycle. */
// FUN_00156800
void FldTileRotateAttributes(void *templateData, u32 directionMask)
{
    extern u8 D_005F0000[];
    FldTileAttributePair savedSmall;
    FldTileAttributePair savedLarge;
    s32 turnCount;
    u8 *tile;
    s32 sourceRow;
    s32 sourceColumn;
    s32 direction;
    s32 smallStep;
    s32 largeStep;
    s32 attributeRow;
    s32 attributeColumn;
    s32 outerStep;
    s32 innerStep;
    u8 width;
    u8 *attribute;
    u8 attributeId;
    u8 *cell;
    u8 firstDirections;
    u8 secondDirections;
    u8 outerCorner;
    u8 innerCorner;

    tile = (u8 *)templateData;
    turnCount = 0;
    for (sourceRow = 0; sourceRow < 3; sourceRow = sourceRow + 1) {
        for (sourceColumn = 0; sourceColumn < 3; sourceColumn = sourceColumn + 1) {
            attributeId = *(tile + sourceRow * 3 + sourceColumn + 4);
            attribute = D_005F0000 + attributeId * 4;
            ((FldTileTemplate *)(tile + sourceRow * 12 + sourceColumn * 4))->attributes[0] = *(FldTileAttributePair *)attribute;
        }
    }
    for (direction = 0; direction < 4; direction = direction + 1) {
        if ((1U << direction) == directionMask) {
            turnCount = direction;
            break;
        }
    }
    /* measured: retail reads the width once into a local instead of reloading it through the typed
     * struct. */
    width = tile[1];
    if (width != 1 || ((FldTileTemplate *)tile)->height != 1) {
        if (width == 2 && ((FldTileTemplate *)tile)->height == 2) {
            for (smallStep = 0; smallStep < turnCount; smallStep = smallStep + 1) {
                u8 savedFlags;
                savedSmall = ((FldTileTemplate *)tile)->attributes[0];
                ((FldTileTemplate *)tile)->attributes[0] =
                    ((FldTileTemplate *)tile)->attributes[1];
                ((FldTileTemplate *)tile)->attributes[1] =
                    ((FldTileTemplate *)tile)->attributes[4];
                ((FldTileTemplate *)tile)->attributes[4] =
                    ((FldTileTemplate *)tile)->attributes[3];
                ((FldTileTemplate *)tile)->attributes[3] = savedSmall;
                savedFlags = ((FldTileTemplate *)tile)->flags[0];
                ((FldTileTemplate *)tile)->flags[0] = ((FldTileTemplate *)tile)->flags[1];
                ((FldTileTemplate *)tile)->flags[1] = ((FldTileTemplate *)tile)->flags[4];
                ((FldTileTemplate *)tile)->flags[4] = ((FldTileTemplate *)tile)->flags[3];
                ((FldTileTemplate *)tile)->flags[3] = savedFlags;
            }
        } else if (width == 3 && ((FldTileTemplate *)tile)->height == 3) {
            for (largeStep = 0; largeStep < turnCount * 2; largeStep = largeStep + 1) {
                u8 savedFlags;
                savedLarge = ((FldTileTemplate *)tile)->attributes[0];
                ((FldTileTemplate *)tile)->attributes[0] =
                    ((FldTileTemplate *)tile)->attributes[1];
                ((FldTileTemplate *)tile)->attributes[1] =
                    ((FldTileTemplate *)tile)->attributes[2];
                ((FldTileTemplate *)tile)->attributes[2] =
                    ((FldTileTemplate *)tile)->attributes[5];
                ((FldTileTemplate *)tile)->attributes[5] =
                    ((FldTileTemplate *)tile)->attributes[8];
                ((FldTileTemplate *)tile)->attributes[8] =
                    ((FldTileTemplate *)tile)->attributes[7];
                ((FldTileTemplate *)tile)->attributes[7] =
                    ((FldTileTemplate *)tile)->attributes[6];
                ((FldTileTemplate *)tile)->attributes[6] =
                    ((FldTileTemplate *)tile)->attributes[3];
                ((FldTileTemplate *)tile)->attributes[3] = savedLarge;
                savedFlags = ((FldTileTemplate *)tile)->flags[0];
                ((FldTileTemplate *)tile)->flags[0] = ((FldTileTemplate *)tile)->flags[1];
                ((FldTileTemplate *)tile)->flags[1] = ((FldTileTemplate *)tile)->flags[2];
                ((FldTileTemplate *)tile)->flags[2] = ((FldTileTemplate *)tile)->flags[5];
                ((FldTileTemplate *)tile)->flags[5] = ((FldTileTemplate *)tile)->flags[8];
                ((FldTileTemplate *)tile)->flags[8] = ((FldTileTemplate *)tile)->flags[7];
                ((FldTileTemplate *)tile)->flags[7] = ((FldTileTemplate *)tile)->flags[6];
                ((FldTileTemplate *)tile)->flags[6] = ((FldTileTemplate *)tile)->flags[3];
                ((FldTileTemplate *)tile)->flags[3] = savedFlags;
            }
        }
    }
    /* Rotate both independent direction nibbles for every attribute pair. */
    for (attributeRow = 0; attributeRow < 3; attributeRow = attributeRow + 1) {
        for (attributeColumn = 0; attributeColumn < 3; attributeColumn = attributeColumn + 1) {
            cell = tile + attributeRow * 12 + attributeColumn * 4;
            firstDirections = ((FldTileTemplate *)cell)->attributes[0].directionBytes[0];
            {
                u32 low;
                u32 high;
                low = fldTileRotateNibble(firstDirections & 0xF, turnCount);
                high = fldTileRotateNibble((firstDirections & 0xF0) >> 4, turnCount);
                ((FldTileTemplate *)cell)->attributes[0].directionBytes[0] = low | (high << 4);
            }
            secondDirections = ((FldTileTemplate *)cell)->attributes[0].directionBytes[1];
            {
                u32 low;
                u32 high;
                low = fldTileRotateNibble(secondDirections & 0xF, turnCount);
                high = fldTileRotateNibble((secondDirections & 0xF0) >> 4, turnCount);
                ((FldTileTemplate *)cell)->attributes[0].directionBytes[1] = low | (high << 4);
            }
        }
    }
    if (tile[1] == 2 && ((FldTileTemplate *)tile)->height == 2) {
        switch (turnCount) {
        case 0:
            break;
        case 1:
            ((FldTileTemplate *)tile)->maskX = -2;
            ((FldTileTemplate *)tile)->maskY = -1;
            break;
        case 2:
            ((FldTileTemplate *)tile)->maskX = -1;
            ((FldTileTemplate *)tile)->maskY = -1;
            break;
        case 3:
            ((FldTileTemplate *)tile)->maskX = -1;
            ((FldTileTemplate *)tile)->maskY = -2;
            break;
        }
    }
    /* A quarter turn advances the outer ring four cells and the inner ring two. */
    for (outerStep = 0; outerStep < turnCount * 4; outerStep = outerStep + 1) {
        outerCorner = *(tile + 24);
        *(tile + 24) = *(tile + 25);
        *(tile + 25) = *(tile + 26);
        *(tile + 26) = *(tile + 27);
        *(tile + 27) = *(tile + 28);
        *(tile + 28) = *(tile + 33);
        *(tile + 33) = *(tile + 38);
        *(tile + 38) = *(tile + 43);
        *(tile + 43) = *(tile + 48);
        *(tile + 48) = *(tile + 47);
        *(tile + 47) = *(tile + 46);
        *(tile + 46) = *(tile + 45);
        *(tile + 45) = *(tile + 44);
        *(tile + 44) = *(tile + 39);
        *(tile + 39) = *(tile + 34);
        *(tile + 34) = *(tile + 29);
        *(tile + 29) = outerCorner;
    }
    for (innerStep = 0; innerStep < turnCount * 2; innerStep = innerStep + 1) {
        innerCorner = *(tile + 30);
        *(tile + 30) = *(tile + 31);
        *(tile + 31) = *(tile + 32);
        *(tile + 32) = *(tile + 37);
        *(tile + 37) = *(tile + 42);
        *(tile + 42) = *(tile + 41);
        *(tile + 41) = *(tile + 40);
        *(tile + 40) = *(tile + 35);
        *(tile + 35) = innerCorner;
    }
}

// Searches the board for a free placement matching the shape's rule; returns 1 with its origin in
// the out-params when one exists.
// FUN_00156CF0
s32 FldCellFindPlacement(void *templateData, u32 *outX, u32 *outY)
{
    u8 *shape;
    u8 *row;
    u8 *rule;
    FldFrameCell *board;
    s32 x;
    s32 y;
    s32 savedRow;
    s32 by;
    s32 ry;
    s32 bx;
    s32 i;
    s32 k;
    s32 j;
    s32 r;
    s32 c;
    u8 cell;

    shape = (u8 *)templateData;
    for (i = 0, y = *outY; i < shape[2]; i++, y--) {
        for (j = 0, x = *outX; j < shape[1]; j++, x--) {
            for (r = 0; r < 5; r++) {
                for (c = 0, row = shape + r * 5, ry = y + r; c < 5; c++) {
                    cell = row[c + 0x18];
                    if (cell == 0) {
                        continue;
                    }
                    bx = ((FldTileTemplate *)shape)->maskX + (x + c);
                    by = ((FldTileTemplate *)shape)->maskY + ry;
                    if (cell == 1) {
                        board = &((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx];
                        if (board->occupied != 0) {
                            goto next_x;
                        }
                    }
                    if (row[c + 0x18] == 2) {
                        if (((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx].occupied == 1) {
                            goto next_x;
                        }
                        if (((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx + 1].occupied == 1 &&
                            (((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx + 1].exits & 0x20)) {
                            goto next_x;
                        }
                        if (((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx - 1].occupied == 1 &&
                            (((FldFrame *)MT_Scene_GetFrameState())->cells[by][bx - 1].exits & 0x80)) {
                            goto next_x;
                        }
                        if (((FldFrame *)MT_Scene_GetFrameState())->cells[by + 1][bx].occupied == 1 &&
                            (((FldFrame *)MT_Scene_GetFrameState())->cells[by + 1][bx].exits & 0x10)) {
                            goto next_x;
                        }
                        if (((FldFrame *)MT_Scene_GetFrameState())->cells[by - 1][bx].occupied == 1 &&
                            (((FldFrame *)MT_Scene_GetFrameState())->cells[by - 1][bx].exits & 0x40)) {
                            goto next_x;
                        }
                    }
                }
            }
            goto fits;
        next_x:
            ;
        }
    }
    return 0;
fits:
    savedRow = y;
    for (k = 0; k < shape[2]; k++, y++) {
        for (r = 0, bx = x, rule = shape + k * 0xC; r < shape[1]; r++, bx++) {
            if (y == 0x16 && (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x40)) {
                return 0;
            }
            if (y == 1 && (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x10)) {
                return 0;
            }
            if (bx == 0xE && (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x80)) {
                return 0;
            }
            if (bx == 1 && (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x20)) {
                return 0;
            }
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[y - 1][bx].occupied != 0) {
                if (((FldFrame *)MT_Scene_GetFrameState())->cells[y - 1][bx].exits & 0x40) {
                    if (!(((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x10)) {
                        return 0;
                    }
                } else if (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x10) {
                    return 0;
                }
            }
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[y][bx - 1].occupied != 0) {
                if (((FldFrame *)MT_Scene_GetFrameState())->cells[y][bx - 1].exits & 0x80) {
                    if (!(((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x20)) {
                        return 0;
                    }
                } else if (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x20) {
                    return 0;
                }
            }
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[y + 1][bx].occupied != 0) {
                if (((FldFrame *)MT_Scene_GetFrameState())->cells[y + 1][bx].exits & 0x10) {
                    if (!(((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x40)) {
                        return 0;
                    }
                } else if (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x40) {
                    return 0;
                }
            }
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[y][bx + 1].occupied != 0) {
                if (((FldFrame *)MT_Scene_GetFrameState())->cells[y][bx + 1].exits & 0x20) {
                    if (!(((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x80)) {
                        return 0;
                    }
                } else if (((FldTileTemplate *)(rule + r * 4))->attributes[0].directionBytes[0] & 0x80) {
                    return 0;
                }
            }
        }
    }
    *outX = x;
    *outY = savedRow;
    return 1;
}

#pragma push
/* measured: the mask and occupied scalars need propagation and common-subexpression elimination off
 * to keep retail's reloads. */
#pragma opt_propagation off
#pragma opt_common_subs off
// Place a shape on the field grid at the given cell with its kind, marking the cells it occupies.
// FUN_00157310
void FldCellPlaceShape(u8 *shape, u16 x0, u16 y0, s16 kind)
{
    extern s32 iGpffffb230;
    extern s32 iGpffffb22c;
    extern s32 iGpffffb228;
    extern s32 iGpffffb224;
    s32 placed;
    s32 px;
    s32 py;
    s32 y;
    s32 x;
    s32 gridRowOffset;
    s32 rowSpan;
    s32 gridColumnOffset;
    s8 occupied;
    u8 *flags;
    u8 *rule;
    u8 *entry;
    s32 r;
    s32 c;
    s32 by;
    s32 bx;
    u8 *row;
    u32 maskValue;

    placed = 0;
    px = x0 & 0xFFFF;
    if (px + ((FldTileTemplate *)shape)->width - 1 >= 0x10) {
        kAssertFail(D_005F05E8, 0x20B);
    }
    py = y0 & 0xFFFF;
    if (py + ((FldTileTemplate *)shape)->height - 1 >= 0x18) {
        kAssertFail(D_005F05E8, 0x20C);
    }
    ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + (y0 << 8) + (x0 * 0x10) + 0x54))->flags = 1;
    for (y = 0; y < ((FldTileTemplate *)shape)->height; y++) {
        for (x = 0, gridRowOffset = (py + y) << 8, rowSpan = y * 3, flags = shape + rowSpan, rule = shape + rowSpan * 4; x < ((FldTileTemplate *)shape)->width; x++) {
            gridColumnOffset = (px + x) * 0x10;
            if (((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->occupied == 0) {
                row = shape + (y - ((FldTileTemplate *)shape)->maskY) * 5;
                maskValue = row[(x - ((FldTileTemplate *)shape)->maskX) + 0x18];
                occupied = 1;
                if (maskValue == occupied) {
                    gridColumnOffset = (px + x) * 0x10;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->occupied = occupied;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->flags |= ((FldTileTemplate *)flags)->flags[x];
                    entry = rule + x * 4;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->exits = ((FldTileTemplate *)entry)->attributes[0].directionBytes[0];
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->shapeX = ((FldTileTemplate *)shape)->width;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->shapeZ = ((FldTileTemplate *)shape)->height;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->type = ((FldTileTemplate *)shape)->type;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->kind = (u8)kind;
                    ((FldFrameCell *)((u8 *)(gridRowOffset + (s32)MT_Scene_GetFrameState()) + gridColumnOffset + 0x54))->unk0B = ((FldTileTemplate *)entry)->attributes[0].directionBytes[1];
                    placed = 1;
                }
            }
        }
    }
    if (placed == 1) {
        for (r = 0; r < 5; r++) {
            for (c = 0, by = py + r, row = shape + r * 5; c < 5; c++) {
                if (((FldTileTemplate *)shape)->maskY + by < 0x18) {
                    bx = px + c;
                    if (((FldTileTemplate *)shape)->maskX + bx < 0x10) {
                        if (((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + ((((FldTileTemplate *)shape)->maskY + by) << 8) + ((((FldTileTemplate *)shape)->maskX + bx) * 0x10) + 0x54))->occupied == 0 &&
                            row[c + 0x18] != 0) {
                            ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + ((((FldTileTemplate *)shape)->maskY + by) << 8) + ((((FldTileTemplate *)shape)->maskX + bx) * 0x10) + 0x54))->occupied = 2;
                        }
                    }
                }
            }
        }
    }
    iGpffffb230 += 1;
    if (((FldTileTemplate *)shape)->type == 2) {
        iGpffffb228 += 1;
    }
    if (((FldTileTemplate *)shape)->type >= 9) {
        iGpffffb22c += 1;
    }
    iGpffffb224 += ((FldTileTemplate *)shape)->width * ((FldTileTemplate *)shape)->height;
}
#pragma pop

/* Flood-fills outward from a field cell through its neighbours within the depth limit, recording
 * the cell types reached; exits are read before outputs are written. */
// FUN_00157700
void FldCellFloodFill(s32 x, s32 y, s32 incoming, s32 depth,
                  s32 limit, s32 *foundTypeTwo, s32 *foundHighType)
{
    s32 exits;
    s32 nextDepth;
    s32 rightDepth;

    if (depth < limit) {
        if (((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->occupied == 1) {
            exits = ~incoming & ((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->exits;
            if (((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type == 2) {
                *foundTypeTwo = 1;
            }
            if (((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type >= 9) {
                *foundHighType = 1;
            }
            if (exits & 1) {
                FldCellFloodFill(x, y - 1, 4, depth + 1, limit, foundTypeTwo, foundHighType);
            }
            if (exits & 2) {
                if ((((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type == 7 ||
                     ((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type == 8) &&
                    limit == 4) {
                    nextDepth = depth;
                } else {
                    nextDepth = depth + 1;
                }
                FldCellFloodFill(x - 1, y, 8, nextDepth, limit, foundTypeTwo, foundHighType);
            }
            if (exits & 4) {
                FldCellFloodFill(x, y + 1, 1, depth + 1, limit, foundTypeTwo, foundHighType);
            }
            if (exits & 8) {
                if ((((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type == 7 ||
                     ((FldFrameCell *)(((u8 *)MT_Scene_GetFrameState() + y * 0x100 + x * 0x10) + 0x54))->type == 8) &&
                    limit == 4) {
                    rightDepth = depth;
                } else {
                    rightDepth = depth + 1;
                }
                FldCellFloodFill(x + 1, y, 2, rightDepth, limit, foundTypeTwo, foundHighType);
            }
        }
    }
}

#pragma push
/* measured: retail reloads the direction and coordinate arguments, which needs propagation off. */
#pragma opt_propagation off
// Spread a tile template from a field cell into a neighbouring cell, choosing a direction at random
// and copying its attributes.
// FUN_001579B0
void FldCellSpreadToNeighbour(s32 column, s32 row, s32 sourceColumn, s32 sourceRow)
{
    u8 tile[0x56];
    u8 *work;
    u8 *choices;
    s16 *src;
    s16 *dst;
    s32 remainingHalfwords;
    s32 sourceCellOffset;
    u32 cellOffset;
    u32 candidateColumn;
    u32 candidateRow;
    s32 foundTypeTwo;
    s32 foundHighType;
    s32 mode;
    s8 templateId;
    s16 copiedHalfword;
    u32 choice;
    u32 direction;
    u32 randomValue;
    u32 attempt;
    u32 found;
    u32 columnOffset;
    u32 rowOffset;
    s32 y;
    s32 x;
    u32 edge;
    s32 previousRow;
    s32 nextRow;
    s32 previousColumn;
    s32 nextColumn;
    u32 rowByteOffset;

    work = (u8 *)MT_Scene_GetFrameState();
    work = ((work) + (row << 8));
    work = ((work) + (column << 4));
    if (((FldFrameCell *)(work + 0x54))->occupied != 0) {
        return;
    }
    if (D_00764328 == 1) {
        return;
    }

    work = (u8 *)MT_Scene_GetFrameState();
    if (column == ((FldFrame *)work)->cellPick[0]) {
        work = (u8 *)MT_Scene_GetFrameState();
        if (row == ((FldFrame *)work)->cellPick[1]) {
            mode = D_0076432C;
            templateId = ((s8 *)(D_005F0591 + mode * 0xC))[D_005F0590[mode * 0xC]];
            src = (s16 *)(D_005F0080 + templateId * 0x56);
            dst = (s16 *)tile;
            remainingHalfwords = 0x2B;
copy_special:
            copiedHalfword = *src;
            src++;
            remainingHalfwords--;
            *dst = copiedHalfword;
            dst++;
            if (remainingHalfwords > 0) {
                goto copy_special;
            }
            work = (u8 *)MT_Scene_GetFrameState();
            FldTileRotateAttributes(tile, 1U << ((FldFrame *)work)->unk48[1]);
            work = (u8 *)MT_Scene_GetFrameState();
            fldPlaceSpecialShape(((FldFrame *)work)->unk48[1], column, row, tile);
            goto propagate;
        }
    }

    D_00764324 = 0;
    foundTypeTwo = 0;
    foundHighType = 0;
    sourceCellOffset = (sourceRow << 8) + (sourceColumn << 4);
main_loop:
    D_00764324++;
    if (D_00764324 > 0x32) {
        D_00764328 = 1;
        return;
    }

    if ((sourceColumn == column) && (sourceRow < row)) {
        FldCellFloodFill(column, row - 1, 4, 0, 5, &foundTypeTwo, &foundHighType);
    }
    if ((sourceColumn < column) && (sourceRow == row)) {
        FldCellFloodFill(column - 1, row, 8, 0, 5, &foundTypeTwo, &foundHighType);
    }
    if ((sourceColumn == column) && (row < sourceRow)) {
        FldCellFloodFill(column, row + 1, 1, 0, 5, &foundTypeTwo, &foundHighType);
    }
    if ((column < sourceColumn) && (sourceRow == row)) {
        FldCellFloodFill(column + 1, row, 2, 0, 5, &foundTypeTwo, &foundHighType);
    }

    work = (u8 *)MT_Scene_GetFrameState();
    if (((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 3) {
        mode = ((FieldSceneState *)iGpffff9db0)->field.value;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            foundTypeTwo = 1;
        }
    }

    randomValue = RpRandom();
    if (((randomValue % 100) < 0x1E) && (foundTypeTwo == 0)) {
        choice = 1;
        direction = RpRandom() & 3;
        goto try_choice;
    }

    work = (u8 *)MT_Scene_GetFrameState();
    if (((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 2) {
        mode = ((FieldSceneState *)iGpffff9db0)->field.value;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            choice = 0;
            direction = RpRandom() & 3;
            goto try_choice;
        }
    }

    if (D_0076432C == 0) {
        work = (u8 *)MT_Scene_GetFrameState();
        if (((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 2) {
            choice = 0;
            direction = RpRandom() & 3;
            goto try_choice;
        }
    }

    work = (u8 *)MT_Scene_GetFrameState();
    if (((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type < 9) {
        goto choose_limited;
    }
    mode = D_0076432C;

    randomValue = RpRandom();
    choice = randomValue % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        choice = 0;
    }
    direction = RpRandom() & 3;
    if (((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xC + choice))->templates[0] == 6) {
        goto main_loop;
    }
    goto try_choice;

choose_limited:
    mode = D_0076432C;
    randomValue = RpRandom();
    choice = randomValue % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        randomValue = D_00764314;
        work = (u8 *)MT_Scene_GetFrameState();
        if (randomValue < ((u32)((FldFrame *)work)->unk48[2] >> 1)) {
            if ((choice == 3) || (choice == 6)) {
                goto main_loop;
            }
        }
    }

    randomValue = RpRandom();
    if (((randomValue % 100) < 0x32) && (foundHighType == 0)) {
        choice = D_005F0590[D_0076432C * 0xC] - 2;
    }
    direction = RpRandom() & 3;
    if (((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xC + choice))->templates[0] == 6) {
        goto main_loop;
    }
    if ((choice == 1) && (foundTypeTwo == 1)) {
        goto main_loop;
    }

    work = (u8 *)MT_Scene_GetFrameState();
    if ((((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 3) &&
        (((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xC + choice))->templates[0] == 3)) {
        goto main_loop;
    }
    work = (u8 *)MT_Scene_GetFrameState();
    if ((((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 7) &&
        (((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xC + choice))->templates[0] == 7)) {
        goto main_loop;
    }
    work = (u8 *)MT_Scene_GetFrameState();
    if ((((FldFrameCell *)((u8 *)(((u32)sourceCellOffset) + ((u32)work)) + 0x54))->type == 8) &&
        (((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xC + choice))->templates[0] == 8)) {
        goto main_loop;
    }

try_choice:
    found = 0;
    attempt = 0;
    choices = D_005F0590 + choice;
    goto attempt_test;
attempt_body:
    mode = D_0076432C;
    templateId = ((FldTileTemplateSet *)(choices + mode * 0xC))->templates[0];
    src = (s16 *)(D_005F0080 + templateId * 0x56);
    dst = (s16 *)tile;
    remainingHalfwords = 0x2B;
copy_candidate:
    copiedHalfword = *src;
    src++;
    remainingHalfwords--;
    *dst = copiedHalfword;
    dst++;
    if (remainingHalfwords > 0) {
        goto copy_candidate;
    }
    FldTileRotateAttributes(tile, 1U << direction);
    candidateColumn = column;
    candidateRow = row;
    if (FldCellFindPlacement(tile, &candidateColumn, &candidateRow) == 1) {
        FldCellPlaceShape(tile, (u16)candidateColumn, (u16)candidateRow, (s16)direction);
        found = 1;
        column = candidateColumn;
        row = candidateRow;
        goto attempt_done;
    }
    direction++;
    if (direction >= 4) {
        direction = 0;
    }
    attempt++;
attempt_test:
    if (attempt < 4) {
        goto attempt_body;
    }
attempt_done:
    if (found != 0) {
        goto propagate;
    }
    if (choice == 1) {
        foundTypeTwo = 1;
    }
    if (choice < (u32)(D_005F0590[D_0076432C * 0xC] - 2)) {
        goto main_loop;
    }
    foundHighType = 1;
    goto main_loop;

propagate:
    rowOffset = 0;
    goto y_test;
y_body:
    columnOffset = 0;
    y = row + rowOffset;
    rowByteOffset = y << 8;
    previousRow = y - 1;
    nextRow = y + 1;
    goto x_test;
x_body:
    edge = 0;
    x = column + columnOffset;
    cellOffset = rowByteOffset + (x << 4);
    previousColumn = x - 1;
    nextColumn = x + 1;
    goto edge_test;
edge_body:
    work = (u8 *)MT_Scene_GetFrameState();
    if ((((FldFrameCell *)((u8 *)(((u32)cellOffset) + ((u32)work)) + 0x54))->exits &
         (1U << (edge + 4))) != 0) {
        switch (edge) {
        case 0:
            FldCellSpreadToNeighbour(x, previousRow, x, y);
            break;
        case 1:
            FldCellSpreadToNeighbour(previousColumn, y, x, y);
            break;
        case 2:
            FldCellSpreadToNeighbour(x, nextRow, x, y);
            break;
        case 3:
            FldCellSpreadToNeighbour(nextColumn, y, x, y);
            break;
        }
    }
    edge++;
edge_test:
    if (edge < 4) {
        goto edge_body;
    }
    columnOffset++;
x_test:
    if (columnOffset < ((FldTileTemplate *)tile)->width) {
        goto x_body;
    }
    rowOffset++;
y_test:
    if (rowOffset < ((FldTileTemplate *)tile)->height) {
        goto y_body;
    }
}
#pragma pop

#pragma push
/* measured: with propagation on, the border loops rematerialize constants that retail does not. */
#pragma opt_propagation off
// Generate the field board: reseed the RNG and fill the board walls and tile states by the given
// mode.
// FUN_001582F0
void FldBoardGenerate(s32 mode, s32 seed, s32 unused)
{
    extern void RpRandomSeed(s32 seed);
    extern s32 func_0043c6a0(s32 value);
    extern u8 D_005F05B8[];
    extern u8 D_005F0600[];
    extern u8 D_005F0620[];
    extern s32 iGpffffb240;
    extern s32 iGpffffb1a0;
    extern s32 iGpffffb214;
    extern s32 iGpffffb220;
    extern s32 iGpffffb238;
    extern s32 iGpffffb230;
    extern s32 iGpffffb22c;
    extern s32 iGpffffb228;
    extern s32 iGpffffb224;
    extern s32 iGpffffb23c;
    s16 tileHalfwords[43];
    u32 originColumn;
    u32 originRow;
    u8 *t;
    s16 *templateWords;
    u8 *roomSet;
    s16 *dst;
    s32 n;
    u32 i;
    u32 borderIndex;
    s32 farthestColumn;
    s32 farthestRow;
    u32 maximumDistance;
    u32 j;
    s32 columnDistance;
    s32 rowDistance;
    u8 selectedByte;
    u8 r;
    s32 border;
    s32 offset;
    s16 copyValue;
    s32 startX;
    u32 areaCount;

    if (seed == 0) {
        iGpffffb240 = iGpffffb1a0;
    } else {
        iGpffffb240 = seed;
    }
    if (iGpffffb214 != 0) {
        iGpffffb240 = iGpffffb214;
    }
    RpRandomSeed(iGpffffb240);
    iGpffffb220 = 0;
    iGpffffb238 = 1;
    while (iGpffffb238 == 1) {
        iGpffffb220 = iGpffffb220 + 1;
        iGpffffb238 = 0;
        iGpffffb230 = 0;
        iGpffffb22c = 0;
        iGpffffb228 = 0;
        iGpffffb224 = 0;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrame *)t)->spawnColumn = 0;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrame *)t)->spawnRow = 0;
        iGpffffb23c = D_005F05B8[mode];
        t = (u8 *)MT_Scene_GetFrameState();
        memset(t + 0x54, 0, 6144);
        borderIndex = 0;
        goto border_columns_test;
border_columns_body:
        offset = borderIndex * 0x10;
        border = 2;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrameCell *)(t + offset + 0x54))->occupied = border;
        t = (u8 *)MT_Scene_GetFrameState();
        *(t + offset + 0x1754) = border;
        borderIndex += 1;
border_columns_test:
        if (borderIndex < 0x10) {
            goto border_columns_body;
        }
        borderIndex = 0;
        goto border_rows_test;
border_rows_body:
        offset = borderIndex * 0x100;
        border = 2;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrameCell *)(t + offset + 0x54))->occupied = border;
        t = (u8 *)MT_Scene_GetFrameState();
        *(t + offset + 0x144) = border;
        borderIndex += 1;
border_rows_test:
        if (borderIndex < 0x18) {
            goto border_rows_body;
        }
        do {
            r = (RpRandom() % 0xB) + 2;
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrame *)t)->cellPick[0] = (u8)r;
            originColumn = r & 0xFF;
            r = (RpRandom() % 0x13) + 2;
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrame *)t)->cellPick[1] = (u8)r;
            originRow = r & 0xFF;
            selectedByte = (u8)(RpRandom() & 3);
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrame *)t)->unk48[1] = selectedByte;
            roomSet = D_005F0590 + iGpffffb23c * 12;
            templateWords = (s16 *)(D_005F0080 + ((s8 *)roomSet)[roomSet[0] + 1] * 0x56);
            dst = tileHalfwords;
            n = 43;
            do {
                copyValue = *templateWords;
                templateWords = templateWords + 1;
                n = n - 1;
                *dst = copyValue;
                dst = dst + 1;
            } while (n > 0);
            t = (u8 *)MT_Scene_GetFrameState();
            FldTileRotateAttributes(tileHalfwords, 1U << ((FldFrame *)t)->unk48[1]);
        } while (FldCellFindPlacement(tileHalfwords, &originColumn, &originRow) == 0);
        selectedByte = (u8)originColumn;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrame *)t)->cellPick[0] = selectedByte;
        selectedByte = (u8)originRow;
        t = (u8 *)MT_Scene_GetFrameState();
        ((FldFrame *)t)->cellPick[1] = selectedByte;
        t = (u8 *)MT_Scene_GetFrameState();
        startX = ((FldFrame *)t)->cellPick[0];
        t = (u8 *)MT_Scene_GetFrameState();
        FldCellSpreadToNeighbour(startX, ((FldFrame *)t)->cellPick[1], 0, 0);
        maximumDistance = 0;
        for (j = 0; j < 0x18; j = j + 1) {
            for (i = 0; i < 0x10; i = i + 1) {
                offset = i * 0x10;
                t = (u8 *)MT_Scene_GetFrameState();
                if (((FldFrameCell *)((u8 *)((u32)byteAddressAdd((u32)(j * 0x100), (u8 *)((u32)t))) + offset + 0x54))->occupied == 1) {
                    t = (u8 *)MT_Scene_GetFrameState();
                    if (((FldFrameCell *)((u8 *)((u32)byteAddressAdd((u32)(j * 0x100), (u8 *)((u32)t))) + offset + 0x54))->type == 5) {
                        t = (u8 *)MT_Scene_GetFrameState();
                        columnDistance = func_0043c6a0(((FldFrame *)t)->cellPick[0] - i);
                        t = (u8 *)MT_Scene_GetFrameState();
                        rowDistance = func_0043c6a0(((FldFrame *)t)->cellPick[1] - j);
                        if (maximumDistance < (u32)(columnDistance + rowDistance)) {
                            farthestColumn = i;
                            farthestRow = j;
                            maximumDistance = columnDistance + rowDistance;
                        }
                    }
                }
            }
        }
        if (maximumDistance != 0) {
            selectedByte = (u8)farthestColumn;
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrame *)t)->spawnColumn = selectedByte;
            selectedByte = (u8)farthestRow;
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrame *)t)->spawnRow = selectedByte;
            border = 6;
            t = (u8 *)MT_Scene_GetFrameState();
            ((FldFrameCell *)(t + farthestRow * 0x100 + farthestColumn * 0x10 + 0x54))->type = border;
        } else {
            iGpffffb238 = 1;
        }
        if (iGpffffb228 == 0) {
            iGpffffb238 = 1;
        }
        areaCount = iGpffffb224;
        t = (u8 *)MT_Scene_GetFrameState();
        if ((areaCount > ((FldFrame *)t)->unk48[3]) ||
            (areaCount = iGpffffb224, t = (u8 *)MT_Scene_GetFrameState(),
             areaCount < (u32)*(t + 0x4A))) {
            iGpffffb238 = 1;
        }
        if ((u32)iGpffffb22c < 2U) {
            iGpffffb238 = 1;
        }
    }
    func_00440b68(D_005F0600, iGpffffb224, iGpffffb230, iGpffffb220);
    func_00440b68(D_005F0620, iGpffffb22c, iGpffffb228, iGpffffb224);
}
#pragma pop

#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
/* Serialized light records occupy 32 bytes. Creators convert their legacy
 * f32 pointer argument back to SVec3 and copy the complete object. Pass
 * complete SVec3 addresses, never an address of one scalar member. */
typedef struct FieldSerializedLightRecord {
    u16 unk00;
    u16 unk02;
    FieldRgba8 color;
    SVec3 position;
    f32 parameters[3];
} FieldSerializedLightRecord;

/* Point groups advance by 0x14; each contains a 12-byte position and yaw. */
typedef struct FieldSerializedPointRecord {
    u32 unk00;
    SVec3 position;
    f32 angle;
} FieldSerializedPointRecord;

/* Complete clone and child layouts from the field resource provider. */
typedef struct {
    u16 type;
    u16 flags;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} k_fldSubEntry;

typedef struct {
    u32 flags;
    s16 field_04;
    s16 field_06;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    u32 count1;
    s32 arr1[32];
    s32 arr2[32];
    u32 count2;
    k_fldSubEntry entries[96];
    s32 field_a20;
    RwV3d scale;
    u8 unkA30[0x10];
    union { u8 *pointData; s32 pointDataAddress; };
} k_fldResource;

typedef struct RuntimeVec3 { f32 x; f32 y; f32 z; } RuntimeVec3;

#pragma push
#pragma optimization_level 1
// Create the resources for one field cell from its kind: model, point and field resources in the
// active band.
// FUN_001587D0
void FldCellCreateResources(u16 parentId, u32 column, u32 row)
{
    extern u8 D_005F0590[];
    extern u8 D_005F0591[];
    extern u8 D_005F05E8[];
    extern u8 D_00756510[];
    extern s32 D_0076432C;
    extern u8 *iGpffff9db0;
    extern s32 *MT_Scene_GetFrameState(void);
    extern k_fldResource *FldResource_CloneRotated(k_fldResource *src, void *translation, u32 quarterTurns);
    extern s32 MT_Scene_CreateModelFldRes(u16 resourceId, s32 model);
    extern s32 MT_Scene_CreateRes11(u16 resourceId, s32 model);
    extern s32 MT_Scene_CreateFldRes(u16 resourceId, s32 model);
    extern s32 MT_Scene_CreatePointRes14(u16 resourceId, f32 *position, f32 radius);
    extern s32 MT_Scene_CreatePointRes15(u16 resourceId, f32 *position, f32 radius);
    extern s32 MT_Scene_CreatePointRes16(u16 resourceId, f32 *position, f32 radius);
    extern s32 MT_Scene_CreatePointRes17(u16 resourceId, f32 *position, f32 radius);
    extern s32 MT_Scene_CreatePointRes18(u16 resourceId, f32 *position, f32 radius);
    extern void resrcMngResetRenderSlots(void);
    extern void SceneDraw_SetResVisible(u16 resTypeId, u32 visible);
    extern s32 FldMap_IsCurrentInBandA(void);
    extern s32 FldMap_IsCurrentInBandB(void);
    extern u16 MT_Scene_FindFreeResId(s32 resourceType);
    extern void Vpad_BuildRotatedQuad(RuntimeVec3 *vertices, const RuntimeVec3 *translation, f32 width, f32 depth, f32 angle);
    extern void *RwMatrixRotate(void *matrix, const void *axis, f32 angle, s32 combine);
    extern void *func_003e42a0(void *out, const void *in, const void *matrix);
    extern void *func_003e0f80(void);
    extern s32 func_003e0f40(void *matrix);
    extern void kAssertFail(const void *file, s32 line);
  s32 templateKind;
  s32 volumeId;
  u32 templateCount;
  s32 checkedY;
  s32 checkedX;
  u8 *grid;
  s32 validExtent;
  s32 validTemplate;
  s32 cloneRow;
  s32 cloneColumn;
  u32 rotation;
  u32 childType;
  u16 resourceId;
  u16 *resourceSlot;
  f32 worldScale;
  k_fldResource *clonedModel;
  s32 columnIndex;
  u8 *parentUnit;
  u32 templateIndex;
  s32 occupiedRowOffset;
  u32 childIndex;
  u32 volumeIndex;
  u32 recordIndex;
  u8 *record;
  s32 rowIndex;
  s32 worldColumnOffset;
  s32 templateOffset;
  s32 occupiedColumnOffset;
  f32 worldCoordinate;
  f32 angle;
  RwV3d worldPosition;
  SVec3 primaryPoint;
  SVec3 secondaryPoint;
  SVec3 tertiaryPoint;
  SVec3 extraPoint;
  SVec3 lightPosition;
  u16 placedResourceIds [4];
  SVec3 finalPoint;
  enum { c10000 = 0x10000, c10001 = 0x10001, c10002 = 0x10002 };
  
  /* These values belong to the placement operation. templateScan first
   * carries the world-row displacement, then the template-list index.
   * gridOffset gains rowOffset once and survives all record groups. */
  {
  s32 rowOffset;
  s32 gridOffset;
  u32 placementX;
  u32 placementY;
  u32 templateScan;
  placementX = column;
  placementY = row;
  templateIndex = 0xffffffff;
  rowOffset = (placementY & 0xffff) * 0x100;
  gridOffset = (placementX & 0xffff) * 0x10;
  grid = (u8 *)MT_Scene_GetFrameState();
  if ((((FldFrameCell *)(grid + rowOffset + gridOffset + 0x54))->occupied == '\x01') &&
     (grid = (u8 *)MT_Scene_GetFrameState(), (((FldFrameCell *)(grid + rowOffset + gridOffset + 0x54))->flags & 0xf) != 0)) {
    checkedX = (s32)(placementX & 0xffff);
    grid = (u8 *)MT_Scene_GetFrameState();
    validExtent = (s32)(checkedX + ((FldFrameCell *)(grid + rowOffset + gridOffset + 0x54))->shapeX - 1) < 0x10;
    if (!validExtent) {
      kAssertFail(D_005F05E8,0x40d);
    }
    checkedY = (s32)(placementY & 0xffff);
    grid = (u8 *)MT_Scene_GetFrameState();
    validExtent = (s32)(checkedY + ((FldFrameCell *)(grid + rowOffset + gridOffset + 0x54))->shapeZ - 1) < 0x18;
    if (!validExtent) {
      kAssertFail(D_005F05E8,0x40e);
    }
    templateScan = (placementY & 0xffff) * 0x100;
    worldColumnOffset = (placementX & 0xffff) * 0x10;
    worldScale = 1200.0f;
    worldCoordinate = (f32)(u32)placementX;
    grid = (u8 *)MT_Scene_GetFrameState();
    worldPosition.x = worldScale * worldCoordinate + (f32)(s32)(((FldFrameCell *)(grid + templateScan + worldColumnOffset + 0x54))->shapeX - 1) * 600.0f
    ;
    grid = (u8 *)MT_Scene_GetFrameState();
    worldPosition.y = (f32)(s32)*(s8 *)&((FldFrameCell *)(grid + templateScan + worldColumnOffset + 0x54))->unk08[1] * 300.0f;
    worldScale = 1200.0f;
    worldCoordinate = (f32)(u32)placementY;
    grid = (u8 *)MT_Scene_GetFrameState();
    worldPosition.z = worldScale * worldCoordinate + (f32)(s32)(((FldFrameCell *)(grid + templateScan + worldColumnOffset + 0x54))->shapeZ - 1) * 600.0f;
    templateCount = D_005F0590[D_0076432C * 0xc];
    if (FldMap_IsCurrentInBandB() != 0) {
      templateCount = D_005F0591[D_0076432C * 0xc];
    }
    templateScan = 0;
    gridOffset = (((u32)rowOffset) + ((u32)gridOffset));
    while (templateScan < templateCount) {
      templateKind = ((FldTileTemplateSet *)(D_005F0590 + D_0076432C * 0xc + templateScan))->templates[0];
      grid = (u8 *)MT_Scene_GetFrameState();
      if (templateKind == ((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->type) {
        templateIndex = templateScan;
        break;
      }
      templateScan = templateScan + 1;
    }
    validTemplate = templateIndex < templateCount;
    if (!validTemplate) {
      kAssertFail(D_005F05E8,0x42a);
    }
    cloneRow = (u16)placementY * 0x100;
    cloneColumn = (u16)placementX * 0x10;
    templateOffset = templateIndex * 4;
    grid = (u8 *)MT_Scene_GetFrameState();
    rotation = (u16)((((FldFrameCell *)(grid + cloneRow + cloneColumn + 0x54))->kind + 4) % 4);
    clonedModel = FldResource_CloneRotated((k_fldResource *)(s32)((FieldSceneState *)(((u32)templateOffset) + ((u32)iGpffff9db0)))->templates[0].address, &worldPosition, rotation);
    resourceId = (u16)MT_Scene_CreateFldRes(parentId,(s32)clonedModel);
    parentUnit = (u8 *)MT_Scene_GetRes(resourceId);
    SceneDraw_SetResVisible((u16)resourceId,1);
    resrcMngResetRenderSlots();
    for (rowIndex = 0; grid = (u8 *)MT_Scene_GetFrameState(), rowIndex < (s32)(u32)(((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->shapeZ);
        rowIndex = rowIndex + 1) {
      columnIndex = 0;
      occupiedRowOffset = (checkedY + rowIndex) * 0x100;
      for (; grid = (u8 *)MT_Scene_GetFrameState(), columnIndex < (s32)(u32)(((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->shapeX);
          columnIndex = columnIndex + 1) {
        occupiedColumnOffset = (checkedX + columnIndex) * 0x10;
        grid = (u8 *)MT_Scene_GetFrameState();
        ((FldFrameCell *)((u8 *)(((u32)occupiedRowOffset) + ((u32)grid)) + occupiedColumnOffset + 0x54))->resourceId = (u16)resourceId;
        grid = (u8 *)MT_Scene_GetFrameState();
        {
          u8 *cell = (u8 *)(((u32)occupiedRowOffset) + ((u32)grid)) + occupiedColumnOffset;
          cell[0x5c] = 1;
        }
      }
    }
    /* For unrecognized child kinds, retail retains the preceding resource ID. */
    for (childIndex = 0; childIndex < clonedModel->count2; childIndex = childIndex + 1) {
      u8 *child = (u8 *)clonedModel + childIndex * 0x18;
      childType = ((k_fldSubEntry *)(child + 0x120))->type;
      if (childType == 0) {
        u8 *unit;
        resourceId = MT_Scene_CreateModelFldRes(MT_Scene_FindFreeResId(10),((k_fldSubEntry *)(child + 0x120))->field_c);
        unit = (u8 *)MT_Scene_GetRes(resourceId);
        ((SceneFieldModelResource *)unit)->parentAddress = (u32)parentUnit;
        if ((((k_fldSubEntry *)(child + 0x120))->flags & 2) != 0) {
          ((SceneFieldModelResource *)unit)->unk150Bits = 1;
        }
      }
      else if (childType == 1) {
        resourceId = MT_Scene_CreateRes11(MT_Scene_FindFreeResId(0xb),((k_fldSubEntry *)(child + 0x120))->field_10);
        child = (u8 *)MT_Scene_GetRes(resourceId);
        ((SceneFieldModelResource *)child)->parentAddress = (u32)parentUnit;
      }
      SceneDraw_SetResVisible((u16)resourceId,1);
    }
    clonedModel->count2 = 0;
    if (((k_fldResource *)((FieldSceneState *)(((u32)templateOffset) + ((u32)iGpffff9db0)))->templates[0].signedAddress)->pointDataAddress != 0) {
      u32 *matrix;
      s32 cornerIndex;
      u8 *data;
      u32 format;
      u32 versionBase;
      matrix = (u32 *)func_003e0f80();
      data = (u8 *)((k_fldResource *)((FieldSceneState *)(((u32)templateOffset) + ((u32)iGpffff9db0)))->templates[0].signedAddress)->pointDataAddress;
      format = ((FldPointTableHeader *)data)->version;
      versionBase = 0x10000;
      if (format == versionBase) {
        record = data + 0x28;
      }
      else if (format == (versionBase | 1)) {
        record = data + 0x30;
      }
      else if (format == (versionBase | 2)) {
        record = data + 0x38;
      }
      else {
        record = data + 0x48;
      }
      for (volumeIndex = 0; volumeIndex < ((FldPointTableHeader *)data)->volumeCount;
          volumeIndex = volumeIndex + 1, record = record + 0x20) {
        u8 *volumeUnit;
        if ((FldMap_IsCurrentInBandA() == 1) || (FldMap_IsCurrentInBandB() == 1)) {
          grid = (u8 *)MT_Scene_GetFrameState();
          if (((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->type == '\x06') {
            volumeId = 0x3fe;
          }
          else {
            volumeId = 0x3ff;
          }
          volumeUnit = (u8 *)MT_Scene_GetRes((u16)MT_Scene_CreateFldHitLight(volumeId, (f32 *)&((FieldSerializedLightRecord *)record)->position, ((FieldSerializedLightRecord *)record)->parameters[0],
                                 ((FieldSerializedLightRecord *)record)->parameters[1], ((FieldSerializedLightRecord *)record)->parameters[2], ((FieldSerializedLightRecord *)record)->color));
          Vpad_BuildRotatedQuad((RuntimeVec3 *)(volumeUnit + 0x15c),(const RuntimeVec3 *)(volumeUnit + 0x144),((SceneQuadResource *)volumeUnit)->width
                        ,((SceneQuadResource *)volumeUnit)->height,((SceneQuadResource *)volumeUnit)->angle);
          for (cornerIndex = 0; cornerIndex < 4; cornerIndex = cornerIndex + 1) {
            f32 cornerAngle;
            u8 *cornerBase;
            grid = (u8 *)MT_Scene_GetFrameState();
            cornerAngle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
            *matrix = matrix[5] = matrix[10] = 0x3f800000;
            matrix[4] = 0;
            matrix[2] = 0;
            matrix[1] = 0;
            matrix[9] = 0;
            matrix[8] = 0;
            matrix[6] = 0;
            matrix[0xe] = 0;
            matrix[0xd] = 0;
            matrix[0xc] = 0;
            matrix[3] = matrix[3] | 0x20003;
            RwMatrixRotate(matrix, D_00756510, cornerAngle, 2);
            cornerBase = volumeUnit + cornerIndex * 0xc;
            {
              RwV3d *corner = (RwV3d *)(cornerBase + 0x15c);
              func_003e42a0(corner, corner, matrix);
            }
            ((SceneQuadResource *)cornerBase)->corners[0].x = ((SceneQuadResource *)cornerBase)->corners[0].x + worldPosition.x;
            ((SceneQuadResource *)cornerBase)->corners[0].y = ((SceneQuadResource *)cornerBase)->corners[0].y + worldPosition.y;
            ((SceneQuadResource *)cornerBase)->corners[0].z = ((SceneQuadResource *)cornerBase)->corners[0].z + worldPosition.z;
          }
        }
      }
      for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->pointCount; recordIndex = recordIndex + 1, record = record + 0x14) {
        if ((FldMap_IsCurrentInBandA() == 1) || (FldMap_IsCurrentInBandB() == 1)) {
          primaryPoint = ((FieldSerializedPointRecord *)record)->position;
          grid = (u8 *)MT_Scene_GetFrameState();
          angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &primaryPoint; func_003e42a0(position, position, matrix); }
          primaryPoint.x = primaryPoint.x + worldPosition.x;
          primaryPoint.y = primaryPoint.y + worldPosition.y;
          primaryPoint.z = primaryPoint.z + worldPosition.z;
          angle = angle + ((FieldSerializedPointRecord *)record)->angle;
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          MT_Scene_CreatePointRes14(0x3ff,(f32 *)&primaryPoint,angle);
        }
      }
      for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->secondaryPointCount; recordIndex = recordIndex + 1, record = record + 0x14) {
        if (FldMap_IsCurrentInBandA() == 1) {
          secondaryPoint = ((FieldSerializedPointRecord *)record)->position;
          grid = (u8 *)MT_Scene_GetFrameState();
          angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &secondaryPoint; func_003e42a0(position, position, matrix); }
          secondaryPoint.x = secondaryPoint.x + worldPosition.x;
          secondaryPoint.y = secondaryPoint.y + worldPosition.y;
          secondaryPoint.z = secondaryPoint.z + worldPosition.z;
          angle = angle + ((FieldSerializedPointRecord *)record)->angle;
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          MT_Scene_CreatePointRes15(MT_Scene_FindFreeResId(0xf),(f32 *)&secondaryPoint,angle);
        }
      }
      for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->tertiaryPointCount; recordIndex = recordIndex + 1, record = record + 0x14) {
        if (FldMap_IsCurrentInBandA() == 1) {
          tertiaryPoint = ((FieldSerializedPointRecord *)record)->position;
          grid = (u8 *)MT_Scene_GetFrameState();
          angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &tertiaryPoint; func_003e42a0(position, position, matrix); }
          tertiaryPoint.x = tertiaryPoint.x + worldPosition.x;
          tertiaryPoint.y = tertiaryPoint.y + worldPosition.y;
          tertiaryPoint.z = tertiaryPoint.z + worldPosition.z;
          angle = angle + ((FieldSerializedPointRecord *)record)->angle;
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          MT_Scene_CreatePointRes16(MT_Scene_FindFreeResId(0x10),(f32 *)&tertiaryPoint,angle);
        }
      }
      if (c10000 < ((FldPointTableHeader *)data)->version) {
        for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->extraPointCount; recordIndex = recordIndex + 1, record = record + 0x14) {
          if (FldMap_IsCurrentInBandA() == 1) {
            extraPoint = ((FieldSerializedPointRecord *)record)->position;
            grid = (u8 *)MT_Scene_GetFrameState();
            angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
            *matrix = matrix[5] = matrix[10] = 0x3f800000;
            matrix[4] = 0;
            matrix[2] = 0;
            matrix[1] = 0;
            matrix[9] = 0;
            matrix[8] = 0;
            matrix[6] = 0;
            matrix[0xe] = 0;
            matrix[0xd] = 0;
            matrix[0xc] = 0;
            matrix[3] = matrix[3] | 0x20003;
            RwMatrixRotate(matrix, D_00756510, angle, 2);
            { SVec3 *position = &extraPoint; func_003e42a0(position, position, matrix); }
            extraPoint.x = extraPoint.x + worldPosition.x;
            extraPoint.y = extraPoint.y + worldPosition.y;
            extraPoint.z = extraPoint.z + worldPosition.z;
            angle = angle + ((FieldSerializedPointRecord *)record)->angle;
            { f32 f360 = 360.0f;
            for (; angle > f360;
                angle = angle - f360) {
            }
            }
            MT_Scene_CreatePointRes17(MT_Scene_FindFreeResId(0x11),(f32 *)&extraPoint,angle);
          }
        }
      }
      if (c10001 < ((FldPointTableHeader *)data)->version) {
        for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->lightCount; recordIndex = recordIndex + 1, record = record + 0x20) {
          u8 *lightUnit;
          lightPosition = ((FieldSerializedLightRecord *)record)->position;
          grid = (u8 *)MT_Scene_GetFrameState();
          angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &lightPosition; func_003e42a0(position, position, matrix); }
          lightPosition.x = lightPosition.x + worldPosition.x;
          lightPosition.y = lightPosition.y + worldPosition.y;
          lightPosition.z = lightPosition.z + worldPosition.z;
          angle = angle + ((FieldSerializedLightRecord *)record)->parameters[2];
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          lightUnit = (u8 *)MT_Scene_GetRes((u16)MT_Scene_CreateRes21Light(MT_Scene_FindFreeResId(0x15), (f32 *)&lightPosition, ((FieldSerializedLightRecord *)record)->parameters[0],
                                 ((FieldSerializedLightRecord *)record)->parameters[1], angle, ((FieldSerializedLightRecord *)record)->color));
          *(u32 *)&((SceneQuadResource *)lightUnit)->terrain = (u32)((FieldSerializedLightRecord *)record)->unk02;
        }
      }
      if (c10002 < ((FldPointTableHeader *)data)->version) {
        if (4 < ((FldPointTableHeader *)data)->finalPointCount) {
          kAssertFail(D_005F05E8,0x541);
        }
        for (recordIndex = 0; recordIndex < ((FldPointTableHeader *)data)->finalPointCount; recordIndex = recordIndex + 1, record = record + 0x14) {
          finalPoint = ((FieldSerializedPointRecord *)record)->position;
          grid = (u8 *)MT_Scene_GetFrameState();
          angle = (f32)((((FldFrameCell *)((u8 *)(((u32)gridOffset) + ((u32)grid)) + 0x54))->kind + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &finalPoint; func_003e42a0(position, position, matrix); }
          finalPoint.x = finalPoint.x + worldPosition.x;
          finalPoint.y = finalPoint.y + worldPosition.y;
          finalPoint.z = finalPoint.z + worldPosition.z;
          angle = angle + ((FieldSerializedPointRecord *)record)->angle;
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          resourceSlot = &placedResourceIds[recordIndex];
          *resourceSlot = MT_Scene_FindFreeResId(0x12);
          MT_Scene_CreatePointRes18(*resourceSlot,(f32 *)&finalPoint,angle);
        }
      }
      func_003e0f40(matrix);
    }
  }
  }
  return;
}
#pragma pop

#pragma push
/* measured: retail does not hoist the row conversion out of the loop or use an extra saved
 * register. */
#pragma opt_loop_invariants off
// Create the resources for every cell of the 16 by 24 field grid.
// FUN_001599D0
void FldCellCreateGrid(void)
{
    s32 rowIndex;
    s32 columnIndex;
    s32 resourceRowBase;

    rowIndex = 0;
    goto loop_5_test;
loop_5_body:
    columnIndex = 0;
    resourceRowBase = rowIndex * 0x10;
    goto loop_3_test;
loop_3_body:
    FldCellCreateResources((u16)(columnIndex + resourceRowBase),
                  (u16)columnIndex, (u16)rowIndex);
    columnIndex += 1;
loop_3_test:
    if (columnIndex < 0x10) {
        goto loop_3_body;
    }
    rowIndex += 1;
loop_5_test:
    if (rowIndex < 0x18) {
        goto loop_5_body;
    }
}
#pragma pop

// Per-frame update for the step task: dispatches on the task's state and sets up its model objects
// and records.
// FUN_00159A60
/* Case-1 conditions fall out to break so every early exit shares the single return 0 after the
 * switch. */
s32 FldStepTaskUpdate(u8 *task)
{
    extern s32 FldRootCreate(u8 *parent, u16 field, u16 room, s32 entry, s16 spawn, s16 direction, s32 sceneFlags, u8 loadMode, s64 secondaryMode, s64 transitionValue, s64 eventId, s64 eventMajor, s64 eventMinor, s64 eventFlags);
    extern void *mdlCreateModelObjectFromData(u32 type, u16 id, void *resource, u32 flags);
    extern s32 cmpPartyPanelTaskCreate(s32 parentTask);
    extern void FldStepUpdateBandRes(void);
    extern void FldStepPreloadBegin(void);
    extern s32 FldStepPreloadCreateTasks(void);
    extern s32 FldStepPreloadFinish(void);
    extern s32 FldStepOpenDataFile(void);
    extern s32 FldStepCopyLoadedFile(u8 *handle);
    extern char D_005F0630[];
    extern u8 D_007E3720[];
    u8 clearedRecord[12];
    u8 *work;
    u8 *rec;
    u8 *p;
    u32 n;
    u8 *base;
    FldStepWork *stepWork;

    work = ((SdkTask *)task)->work;
    stepWork = (FldStepWork *)work;
    FldStepUpdateBandRes();
    switch (((FldStepWork *)work)->state) {
    case 0:
        ((FldStepWork *)work)->fileHandle = FldStepOpenDataFile();
        ((FldStepWork *)work)->modelObject = (s32)mdlCreateModelObjectFromData(4, 0xFFFF, D_005F0630, 0);
        FldStepPreloadBegin();
        *(s32 *)work += 1;
    case 1:
        if (FldStepCopyLoadedFile(stepWork->filePointer) != 0) {
            ((FldStepWork *)work)->fileHandle = 0;
            if (((FldStepWork *)work)->modelObject == 0 || mdlPrepareModel(((FldStepWork *)work)->modelObject) != 0) {
                if (FldStepPreloadCreateTasks() != 0 && FldStepPreloadFinish() != 0) {
                    ((FldStepWork *)work)->entries = D_007E3720;
                    if (((FldStepWork *)work)->stepIndex != 0x9F) {
                        ((FldStepWork *)work)->panelTask = cmpPartyPanelTaskCreate(0);
                    }
                    *(s32 *)work += 1;
    case 2:
                    *(s32 *)work += 1;
    case 3:
                    base = ((FldStepWork *)work)->entries;
                    stepWork->flags = ((FldStepEntryRecord *)((u8 *)(((FldStepWork *)work)->stepIndex * 0x10) + (s32)base))->flags | 0x80000000;
                    rec = (u8 *)(((FldStepWork *)work)->stepIndex * 0x10) + (s32)((FldStepWork *)work)->entries;
                    ((FldStepWork *)work)->rootTask = FldRootCreate(task, ((FldStepEntryRecord *)rec)->fieldId, ((FldStepEntryRecord *)rec)->roomId, ((FldStepWork *)work)->entryHalf[0], 0, 0,
                                                          ((FldStepWork *)work)->flags, ((FldStepEntryRecord *)rec)->unk08, ((FldStepEntryRecord *)rec)->unk09,
                                                          ((FldStepEntryRecord *)rec)->value, -1, -1, -1, -1);
                    stepWork->flags = 0;
                    *(s32 *)work += 1;
                }
            }
        }
        break;
    case 4:
        if (((FldStepWork *)work)->finished == 1) {
            *(s32 *)work = 0xC;
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        *(s32 *)work += 1;
        break;
    case 10:
        p = clearedRecord;
        n = 12;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        if (FldStepCopyLoadedFile(stepWork->filePointer) != 0) {
            ((FldStepWork *)work)->fileHandle = 0;
            base = ((FldStepWork *)work)->entries;
            stepWork->flags |= ((FldStepEntryRecord *)((u8 *)(((FldStepWork *)work)->stepIndex * 0x10) + (s32)base))->flags;
            rec = (u8 *)(((FldStepWork *)work)->stepIndex * 0x10) + (s32)((FldStepWork *)work)->entries;
            ((FldStepWork *)work)->rootTask = FldRootCreate(task, ((FldStepEntryRecord *)rec)->fieldId, ((FldStepEntryRecord *)rec)->roomId, ((FldStepWork *)work)->entryHalf[0], 0, 0,
                                                  ((FldStepWork *)work)->flags, ((FldStepEntryRecord *)rec)->unk08, ((FldStepEntryRecord *)rec)->unk09,
                                                  ((FldStepEntryRecord *)rec)->value, -1, -1, -1, -1);
            stepWork->flags = 0;
            *(s32 *)work = 4;
        }
        break;
    case 12:
        return -1;
    default:
        break;
    }
    return 0;
}

// Destroy the step task: clear the step records and run the state destroy hook from the hook table.
// FUN_00159D50
void FldStepTaskDestroy(u8 *task)
{
    s32 *resourceSlot;
    s32 resourceOffset;
    s32 panelTask;
    s32 modelObject;
    s32 resource;
    s32 columnIndex;
    u8 *workBlock;
    u8 *scriptData;
    SdkTask *stepTask = (SdkTask *)task;

    workBlock = stepTask->work;
    if (FldMap_IsCurrentInEitherBand() == 1) {
        fldStepSaveBoard(((FldStepWork *)workBlock)->stepIndex);
    }
    panelTask = ((FldStepWork *)workBlock)->panelTask;
    if (panelTask != 0) {
        MT_Scene_ReleaseWork(panelTask);
    }
    scriptData = ((FldStepWork *)workBlock)->scriptData;
    if (scriptData != NULL) {
        jtbl_008873EC[0](scriptData);
    }
    if (((FldFrame *)MT_Scene_GetFrameState())->cameraTask != 0) {
        FldFrame_SetStateFlags((s32)((FldFrame *)MT_Scene_GetFrameState())->cameraTask, 1);
    }
    modelObject = ((FldStepWork *)workBlock)->modelObject;
    if (modelObject != 0) {
        mdlDestroyModelObject((u8*)(modelObject));
    }
    columnIndex = 0;
    goto loop_14_test;
loop_14_body:
    resourceOffset = columnIndex * 4;
    resourceSlot = (s32 *)((u8 *)D_007E8060 + resourceOffset);
    resource = *resourceSlot;
    if (resource != 0) {
        FldResource_Destroy(resource);
        *resourceSlot = 0;
        ((FieldSceneState *)(iGpffff9db0 + resourceOffset))->templates[0].signedAddress = 0;
    }
    columnIndex++;
loop_14_test:
    if (columnIndex < 0x10) {
        goto loop_14_body;
    }
    ((FieldSceneState *)iGpffff9db0)->field.value = 0;
    jtbl_008873EC[0](stepTask->work);
}

// Create the step task under the given parent with its update and destroy callbacks, store its two
// parameters and clear flag 0xC25.
// FUN_00159E90
s32 FldStepTaskCreate(s32 parent, s32 stepIndex, s32 entryValue) {
    s32 taskResult;
    u8 *allocation;

    chkmemAllocSiteTag(D_005F05E8, 0x718);
    allocation = (u8 *)D_008873F4[0](1, 0x48, 0x40000);
    if (allocation == NULL) {
        return 0;
    }
    taskResult = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F0650), 0xF, 0, 0, FldStepTaskUpdate, FldStepTaskDestroy, (u8 *)(allocation));
    ((FldStepWork *)allocation)->stepIndex = stepIndex;
    ((FldStepWork *)allocation)->entryValue = entryValue;
    datSetFlag((s32)(0xC25), (s32)( 0));
    return taskResult;
}

// Advance the step counter by the argument and reset the step state; when the step lands on a
// different entry, the grid entries are freed.
// FUN_00159F70
void FldStepAdvance(s32 stepDelta)
{
    u8 *root;
    u8 *state;
    s32 stepByteDelta;
    s32 entryOffset;
    s32 base;
    s32 index;
    s32 *entry;
    u8 *first;
    FldStepWork *stepWork;

    root = D_00764334;
    if (root != NULL) {
        state = ((SdkTask *)root)->work;
        stepWork = (FldStepWork *)state;
        if (stepDelta < 0) {
            ((FldStepWork *)state)->entryValue = 0x3FF;
        } else {
            ((FldStepWork *)state)->entryValue = 0xFFFF;
        }
        stepByteDelta = stepDelta * 0x10;
        entryOffset = ((FldStepWork *)state)->stepIndex * 0x10;
        base = ((FldStepWork *)state)->entriesAddress;
        first = (u8 *)(base + entryOffset);
        /* Preserve the room-halfword cursor while naming its proven member. */
        if (((((FldStepEntryRecord *)first)->fieldId != ((FldStepEntryRecord *)(first + stepByteDelta))->fieldId) ||
             (*(u16 *)(base + MEMBER_OFFSET(FldStepEntryRecord, roomId) + entryOffset) !=
              *(u16 *)(((u8 *)(base + MEMBER_OFFSET(FldStepEntryRecord, roomId) + entryOffset)) + (stepByteDelta)))) &&
            (((((FldStepWork *)state)->flags |= 0x80000000),
              FldMap_IsCurrentInBandA(base, entryOffset, stepByteDelta) == 1) ||
             (FldMap_IsCurrentInBandB() == 1))) {
            index = 0;
            while (index < 0x10) {
                entry = &D_007E8060[index];
                if (*entry != 0) {
                    FldResource_Destroy(*entry);
                    *entry = 0;
                }
                index += 1;
            }
        }
        stepWork->stepIndex += stepDelta;
        MT_Scene_SetWorkValue(((FldStepWork *)state)->rootPointer, 1);
        *(s32 *)state = 5;
    }
}

// Return the current step entry address, or 0 when there is no step task.
// FUN_0015A0C0
s32 FldStepEntry(void)
{
    u8 *work;
    u8 *p;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = ((SdkTask *)work)->work;
    return ((FldStepWork *)p)->entriesAddress + (((FldStepWork *)p)->stepIndex * 0x10);
}

/* Return the loaded step-script buffer address, or zero without a step task. */
// FUN_0015A100
s32 FldStepGetScriptData(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return ((FldStepWork *)((SdkTask *)work)->work)->scriptAddress;
}

/* Return the step-script buffer's byte count, or zero without a step task. */
// FUN_0015A130
s32 FldStepGetScriptSize(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return ((FldStepWork *)((SdkTask *)work)->work)->scriptSize;
}

// Return the step counter, or 0 when there is no step task.
// FUN_0015A160
s32 FldStepIndex(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return ((FldStepWork *)((SdkTask *)work)->work)->stepIndex;
}

// Report whether the flag for the current step band (0x11 to 0x17) is set.
// FUN_0015A190
s32 FldStepBandFlagSet(void)
{
    s32 result;
    u32 value;
    u8 *work;

    result = 0;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    value = ((FldStepWork *)((SdkTask *)work)->work)->unsignedStepIndex;
    if (value < 0x14U) {
        if (datGetFlag(0x11) == 1) {
            result = 1;
        }
    } else if (value < 0x28U) {
        if (datGetFlag(0x12) == 1) {
            result = 1;
        }
    } else if (value < 0x3CU) {
        if (datGetFlag(0x13) == 1) {
            result = 1;
        }
    } else if (value < 0x50U) {
        if (datGetFlag(0x14) == 1) {
            result = 1;
        }
    } else if (value < 0x64U) {
        if (datGetFlag(0x15) == 1) {
            result = 1;
        }
    } else if (value < 0x78U) {
        if (datGetFlag(0x16) == 1) {
            result = 1;
        }
    } else if (value < 0x8CU) {
        if (datGetFlag(0x17) == 1) {
            result = 1;
        }
    }
    return result;
}

/* Return the address of the step model-handle slot, or zero without a step task. */
// FUN_0015A320
s32 fldStepGetModelSlot(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return (s32)&((FldStepWork *)((SdkTask *)work)->work)->modelObject;
}

/* Write the occupied grid cells' bounding-box midpoint in 1200-unit world coordinates. */
// FUN_0015A350
void fldBoardGetOccupiedCenter(RwV3d *center)
{
    RwV3d out;
    f32 minWorldX;
    f32 minWorldZ;
    s32 y;
    s32 x;
    s32 minColumn;
    s32 minRow;
    s32 maxColumn;
    s32 maxRow;
    s32 row;

    out.z = 0.0f;
    out.y = 0.0f;
    out.x = 0.0f;
    minColumn = 0x10;
    minRow = 0x18;
    maxColumn = 0;
    maxRow = 0;
    y = 0;
    while (y < 0x18) {
        x = 0;
        row = y << 8;
        while (x < 0x10) {
            if (((FldFrameCell *)((((u8 *)(row + (s32)(u8 *)MT_Scene_GetFrameState())) + (x << 4)) + 0x54))->occupied == 1) {
                if (x <= minColumn) {
                    minColumn = x;
                }
                if (y <= minRow) {
                    minRow = y;
                }
                if (x >= maxColumn) {
                    maxColumn = x;
                }
                if (y >= maxRow) {
                    maxRow = y;
                }
            }
            x += 1;
        }
        y += 1;
    }
    minWorldX = 1200.0f * (f32)minColumn;
    out.x = minWorldX + (((1200.0f * (f32)maxColumn) - minWorldX) / 2.0f);
    minWorldZ = 1200.0f * (f32)minRow;
    out.z = minWorldZ + (((1200.0f * (f32)maxRow) - minWorldZ) / 2.0f);
    func_00440b68(D_005F0670, minColumn, minRow, maxColumn, maxRow);
    *center = out;
}

// Set the step's present flag from the argument, using the step work block's panel task.
// FUN_0015A520
void FldStepSetPresentFlag(s32 present)
{
    u8 *work;
    s32 value;

    work = D_00764334;
    if (work != NULL) {
        value = ((FldStepWork *)((SdkTask *)work)->work)->panelTask;
        if (value != 0) {
            MT_Scene_SetWorkPresentFlag(value, present);
        }
    }
}

// Return 0 when the current step value is a band boundary (0 to 5, or 0x14 to 0x8C), otherwise 1.
// FUN_0015A560
s32 FldStepNotAtBoundary(void) {
    s32 result;
    s32 stepIndex;
    u8 *stepTask;

    result = 1;
    stepTask = iGpffffb244;
    if (stepTask == NULL) {
        stepIndex = 0;
    } else {
        stepIndex = ((FldStepWork *)((SdkTask *)stepTask)->work)->stepIndex;
    }
    if ((stepIndex == 0) || (stepIndex == 1) || (stepIndex == 2) ||
        (stepIndex == 3) || (stepIndex == 4) || (stepIndex == 5) ||
        (stepIndex == 0x14) || (stepIndex == 0x28) || (stepIndex == 0x3C) ||
        (stepIndex == 0x50) || (stepIndex == 0x64) || (stepIndex == 0x78) ||
        (stepIndex == 0x8C)) {
        result = 0;
    }
    return result;
}

// Clear the step table and fill the two index tables with 0xFF.
// FUN_0015A630
void FldStepResetTables(void) {
    memset(D_007D3E10, 0, 0xF8FC);
    memset(D_007E36E4, 0xFF, 0x14);
    memset(D_007E36F8, 0xFF, 0x14);
}

// Return the step table address.
// FUN_0015A690
u8 *FldStepTable(void)
{
    return D_007D3E10;
}

// FUN_0015A6A0
s32 FldStepTableSize(void)
{
    return 0xF8FC;
}

/* The saved-board and file-loader run uses conditional rebuilding. */
#pragma opt_rebuildconditionals on
// Look up the step's band in the threshold table and return 1 when that entry's flag is set.
// FUN_0015A6B0
s32 FldStepTableEntryFlag(s32 stepIndex)
{
    s16 threshold;
    s32 result;
    s32 index;

    result = 0;
    index = 0;
    goto load;
compare:
    if (stepIndex < threshold) {
        goto done;
    }
    index++;
load:
    threshold = D_005F05D0[index];
    if (threshold >= 0) {
        goto compare;
    }
done:
    if (index == 0) {
        return 0;
    }
    if (((FldSavedEncounter (*)[8])D_007E31E4)[stepIndex - (s32)((s16 *)D_005F05CE)[index]][0].active != 0) {
        result = 1;
    }
    return result;
}

// Return the second table's value for the step's band; 0xFF before the first band.
// FUN_0015A740
u8 FldStepBandValue(s32 stepIndex) {
    s32 i = 0;

    while (D_005F05D0[i] >= 0) {
        if (stepIndex < D_005F05D0[i]) {
            break;
        }
        i++;
    }
    if (i == 0) {
        return 0xFF;
    }
    return D_007E36E4[stepIndex - ((s16 *)D_005F05CE)[i]];
}

/* Save this step's first board snapshot, current reveal mask, and encounter slots. */
// FUN_0015A7C0
s32 fldStepSaveBoard(s32 stepIndex)
{
    s32 thresholdIndex;
    s16 threshold;
    s32 mapIndex;
    s32 columnIndex;
    s32 rowIndex;
    s32 sourceRow;
    s32 sourceColumn;
    u8 *destCell;
    s32 slotIndex;
    u8 *slot;
    u8 *slotEntry;
    extern s32 FldUnit_GetActiveCount();

    thresholdIndex = 0;
    goto threshold_test;
threshold_body:
    if (stepIndex < threshold) {
        goto threshold_done;
    }
    thresholdIndex++;
threshold_test:
    threshold = D_005F05D0[thresholdIndex];
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (thresholdIndex == 0) {
        return 0;
    }

    mapIndex = stepIndex - ((s16 *)D_005F05CE)[thresholdIndex];
    if (mapIndex >= 0x14) {
        kAssertFail(D_005F05E8, 0x889);
    }

    if (D_007D3E10[mapIndex] == 0) {
        D_007D3E10[mapIndex] = 1;

        rowIndex = 0;
        goto copy_outer_test;
copy_outer_body:
        columnIndex = 0;
        sourceRow = rowIndex * 0x100;
        goto copy_inner_test;
copy_inner_body:
        sourceColumn = columnIndex * 0x10;
        destCell = (u8 *)D_007D3E10 + mapIndex * 0xC00 + (rowIndex * 0x80) + (columnIndex * 8);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].occupied = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x54);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].flags = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x55);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].type = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x58);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].kind = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x59);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].shapeX = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x5A);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].shapeZ = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x5B);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].exits = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x5E);
        ((FldStepSavedTables *)destCell)->grids[0][0][0].attributes = (u8) * ((u8 *)MT_Scene_GetFrameState() + sourceRow + sourceColumn + 0x5F);
        columnIndex++;
copy_inner_test:
        if (columnIndex < 0x10) {
            goto copy_inner_body;
        }
        rowIndex++;
copy_outer_test:
        if (rowIndex < 0x18) {
            goto copy_outer_body;
        }
        return 1;
    }

    memcpy(D_007D3E10 + mapIndex * 0x30 + 0xF014, smapRevealTablePtr(), 0x30);

    slotIndex = 0;
    goto slot_test;
slot_body:
    slot = D_007E80A0 + slotIndex * 0x168;
    if (((FldEncounterSlot *)slot)->active == 0) {
        ((FldStepSavedTables *)(D_007D3E10 + mapIndex * 0x40 + slotIndex * 8))->encounters[0][0].active = 0;
    } else {
        slotEntry = (u8 *)(D_007D3E10 + mapIndex * 0x40 + slotIndex * 8);
        ((FldStepSavedTables *)slotEntry)->encounters[0][0].active = 1;
        ((FldStepSavedTables *)slotEntry)->encounters[0][0].mode = (s8)(((FldEncounterSlot *)slot)->mode != 0);
        ((FldStepSavedTables *)slotEntry)->encounters[0][0].id = ((FldEncounterSlot *)slot)->id;
        /* Only serialized byte seven's low flag is used from the encounter record here. */
        if ((((FldEncounterSlot *)slot)->record[7] & 1) != 0) {
            ((FldStepSavedTables *)slotEntry)->encounters[0][0].recordKind = 1;
        } else {
            ((FldStepSavedTables *)slotEntry)->encounters[0][0].recordKind = 0;
        }
    }
    slotIndex++;
slot_test:
    if (slotIndex < 8) {
        goto slot_body;
    }

    D_007E36E4[mapIndex] = (u8)FldUnit_GetActiveCount(slotIndex, slotIndex < 8);
    return 0;
}

// Copy one entry from the frame state's work block into the step table if the band is marked
// active.
// FUN_0015AB20
s32 FldStepCopyTableEntry(s32 stepIndex, s32 column, s32 row) {
    s16 threshold;
    s32 mapIndex;
    s32 thresholdIndex;
    u8 *work;

    thresholdIndex = 0;
    goto loop_test;
loop_body:
    if (stepIndex < threshold) {
        goto done;
    }
    thresholdIndex += 1;
loop_test:
    threshold = D_005F05D0[thresholdIndex];
    if (threshold >= 0) {
        goto loop_body;
    }
done:
    if (thresholdIndex == 0) {
        return 0;
    }
    mapIndex = stepIndex - ((s16 *)D_005F05CE)[thresholdIndex];
    if (mapIndex >= 0x14) {
        kAssertFail(D_005F05E8, 0x8E3, thresholdIndex);
    }
    if (((FldStepSavedTables *)D_007D3E10)->visited[mapIndex] == 1) {
        work = (u8 *)MT_Scene_GetFrameState();
        work += row << 8;
        work += column << 4;
        /* D_007D3E2B is the first saved-cell attribute byte; the row offset is added separately
         * from the column index. */
        ((u8 *)(D_007D3E2B + mapIndex * 0xC00 +
                (row << 7)))[column << 3] = ((FldFrameCell *)(work + 0x54))->unk0B;
        return 1;
    }
    kAssertFail(D_005F05E8, 0x8ED);
    return 0;
}

/* Restore a previously visited step's board, reveal mask, and encounter slots. */
// FUN_0015AC60
s32 fldStepRestoreBoard(s32 stepIndex)
{
    s32 thresholdIndex;
    s16 threshold;
    s32 mapIndex;
    s32 columnIndex;
    s32 rowIndex;
    s32 scanRow;
    s32 scanColumn;
    s32 slotIndex;
    s32 destRow;
    s32 destColumn;
    u8 *sourceBase;
    u8 *sourceRow;
    u8 *sourceCell;
    s32 *slotSource;
    u8 *dest;
    u8 value;
    s32 mode;
    s32 field;
    u16 h0;
    u16 h4;

    if (FldMap_IsCurrentInBandA(stepIndex) != 0) {
        D_0076432C = D_005F0590[((FieldSceneState *)iGpffff9db0)->field.value];
    } else {
        D_0076432C = D_005F057C[((FieldSceneState *)iGpffff9db0)->field.value];
    }

    thresholdIndex = 0;
    goto threshold_test;
threshold_body:
    if (stepIndex < threshold) {
        goto threshold_done;
    }
    thresholdIndex++;
threshold_test:
    threshold = D_005F05D0[thresholdIndex];
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (thresholdIndex == 0) {
        return 0;
    }

    mapIndex = stepIndex - ((s16 *)D_005F05CE)[thresholdIndex];
    if (mapIndex >= 0x14) {
        kAssertFail(D_005F05E8, 0x906);
    }
    memset(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    smapClearRevealTable();
    if (D_007D3E10[mapIndex] != 1) {
        goto fail;
    }
    if (kwlnGetCurrentWorkValue() == 0xA) {
        goto fail;
    }

    rowIndex = 0;
    sourceBase = D_007D3E10 + mapIndex * 0xC00;
    goto copy_outer_test;
copy_outer_body:
    columnIndex = 0;
    sourceRow = sourceBase + rowIndex * 0x80;
    destRow = rowIndex * 0x100;
    goto copy_inner_test;
copy_inner_body:
    sourceCell = sourceRow + columnIndex * 8;
    destColumn = columnIndex * 0x10;

    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].occupied;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->occupied = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].flags;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->flags = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].type;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->type = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].kind;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->kind = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].shapeX;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->shapeX = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].shapeZ;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->shapeZ = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].exits;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->exits = value;
    value = ((FldStepSavedTables *)sourceCell)->grids[0][0][0].attributes;
    ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->unk0B = value;

    columnIndex++;
copy_inner_test:
    if (columnIndex < 0x10) {
        goto copy_inner_body;
    }
    rowIndex++;
copy_outer_test:
    if (rowIndex < 0x18) {
        goto copy_outer_body;
    }

    memcpy(smapRevealTablePtr(),
                  D_007D3E10 + mapIndex * 0x30 + 0xF014, 0x30);

    scanRow = 0;
    goto scan_outer_test;
scan_outer_body:
    scanColumn = 0;
    destRow = scanRow * 0x100;
    goto scan_inner_test;
scan_inner_body:
    destColumn = scanColumn * 0x10;
    if ((((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->occupied == 1) &&
        ((((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->flags & 0xF) != 0)) {
        if (((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->type == 6) {
            ((FldFrame *)MT_Scene_GetFrameState())->spawnColumn = (u8)scanColumn;
            ((FldFrame *)MT_Scene_GetFrameState())->spawnRow = (u8)scanRow;
        }
        if ((((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->type == 0xA) ||
            (((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->type == 0xC) ||
            (((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->type == 0xE)) {
            ((FldFrame *)MT_Scene_GetFrameState())->cellPick[0] = (u8)scanColumn;
            ((FldFrame *)MT_Scene_GetFrameState())->cellPick[1] = (u8)scanRow;
            value = ((FldFrameCell *)((u8 *)(((u32)destRow) + ((u32)MT_Scene_GetFrameState())) + destColumn + 0x54))->kind;
            ((FldFrame *)MT_Scene_GetFrameState())->unk48[1] = value;
        }
    }
    scanColumn++;
scan_inner_test:
    if (scanColumn < 0x10) {
        goto scan_inner_body;
    }
    scanRow++;
scan_outer_test:
    if (scanRow < 0x18) {
        goto scan_outer_body;
    }

    slotIndex = 0;
    sourceBase = D_007D3E10 + mapIndex * 0x40;
    goto slots_test;
slots_body:
    slotSource = (s32 *)(sourceBase + slotIndex * 8);
    if (((FldStepSavedTables *)slotSource)->encounters[0][0].active != 0) {
        dest = D_007E80A0 + slotIndex * 0x168;
        ((FldEncounterSlot *)dest)->active = 1;
        ((FldEncounterSlot *)dest)->mode = ((FldStepSavedTables *)slotSource)->encounters[0][0].mode;
        ((FldEncounterSlot *)dest)->id = ((FldStepSavedTables *)slotSource)->encounters[0][0].id;
        slotSource = (s32 *)((u8 *)slotSource + 0xF3D8);
        mode = *slotSource;
        if (mode == 0) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = ((FldStepWork *)((SdkTask *)D_00764334)->work)->stepIndex;
            }
            h0 = ((FieldSceneState *)iGpffff9db0)->field.half[0];
            h4 = ((FieldSceneState *)iGpffff9db0)->room.half[0];
            ((FldEncounterSlot *)dest)->record =
                Encount_FindRecord(h0, h4, field, 0);
        } else if (mode == 1) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = ((FldStepWork *)((SdkTask *)D_00764334)->work)->stepIndex;
            }
            h0 = ((FieldSceneState *)iGpffff9db0)->field.half[0];
            h4 = ((FieldSceneState *)iGpffff9db0)->room.half[0];
            ((FldEncounterSlot *)dest)->record =
                Encount_FindRecord(h0, h4, field, 1);
        } else {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = ((FldStepWork *)((SdkTask *)D_00764334)->work)->stepIndex;
            }
            h0 = ((FieldSceneState *)iGpffff9db0)->field.half[0];
            h4 = ((FieldSceneState *)iGpffff9db0)->room.half[0];
            ((FldEncounterSlot *)dest)->record =
                Encount_FindRecord(h0, h4, field, 2);
        }
    }
    slotIndex++;
slots_test:
    if (slotIndex < 8) {
        goto slots_body;
    }
    return 1;
fail:
    return 0;
}

// Refresh visibility of the band's resource list from each entry's grid cell and the frame state
// flags.
// FUN_0015B240
void FldStepRefreshBandResVisibility(void)
{
    u8 *entry;
    s32 flag;
    s32 cellColumn;
    s32 cellRow;
    SceneFieldModelResource *modelResource;

    entry = MT_Scene_GetResListHead(0xA);
    if (FldMap_IsCurrentInBandA() == 0) {
        if (FldMap_IsCurrentInBandB() == 0) {
            return;
        }
    }
    while (entry != NULL) {
body:
            modelResource = (SceneFieldModelResource *)entry;
            cellColumn = (s32)((((RwMatrixTag *)mdlGetMatrix(((SceneFieldModelResource *)entry)->modelAddress))->pos.x +
                             600.0f) /
                            1200.0f);
            /* measured: retail reads the model handle through the typed resource pointer. */
            cellRow = (s32)((((RwMatrixTag *)mdlGetMatrix(modelResource->modelAddress))->pos.z +
                             600.0f) /
                            1200.0f);
            flag = 0;
            if ((((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + (cellRow << 8) +
                         (cellColumn << 4) + 0x54))->unk0B & 0xF0) != 0) {
                flag = 1;
            }
            if (flag == 1) {
                if (K_Clump_ClumpHasMatUsrData(
                        mdlGetClump(modelResource->modelAddress),
                        D_005F0690) != 0) {
                    mdlDispatchAnimIfPresent((u8*)modelResource->modelAddress, 0, 2, 0, 0);
                }
                if (K_Clump_ClumpHasMatUsrData(
                        mdlGetClump(modelResource->modelAddress),
                        D_005F06A0) != 0) {
                    ((SceneFieldModelResource *)entry)->unk150 = 0;
                }
            }
            entry = (u8 *)((ResrcHeader *)entry)->next;
        }
}

/* Flood-fills cells reachable from a field cell in each direction up to the per-direction limits
 * and sets their resources visible. Retail leaves next_depth unwritten for kinds 7/8 with axis mask
 * 0xA at depth zero; this omission is preserved. */
// FUN_0015B3E0
void FldCellFloodFillDirected(s32 column, s32 row, u8 incoming, u8 limitedDirections, s32 axisMask, s32 depth, u8 limit, s32 *visibleCount)
{
    extern void SceneDraw_SetResVisible(u16 resTypeId, u32 visible);
    s32 depthValue;
    s32 limitValue;
    u8 northLimit;
    u8 southLimit;
    u8 westLimit;
    s32 eastLimited;
    /* Retail leaves this unwritten on the limit-extension paths below. */
    s32 nextDepth;
    s32 mode;
    s32 exits;

    limitValue = limit & 0xFF;
    depthValue = depth & 0xFF;
    if (depthValue < limitValue) {
        if (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].occupied == 1) {
            SceneDraw_SetResVisible(((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].resourceId, 1);
            *visibleCount += 1;
            exits = (~incoming & ((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].exits) & 0xFF;
            if (exits & 1) {
                northLimit = (limitedDirections & 1) ? 3 : limitValue;
                if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 2) && (((mode = ((FieldSceneState *)iGpffff9db0)->field.value) == 0x2C) || (mode == 0x40)) && (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].flags & 0x20)) {
                    nextDepth = (u8)depth;
                } else if (((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 7) || (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 8)) && (((u8)axisMask & 0xA) != 0) && (depthValue == 0)) {
                    /* 0015B5DC..0015B5E8: no next_depth assignment. */
                    northLimit += 1;
                } else if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 3) && (((u8)axisMask & 1) != 0)) {
                    nextDepth = (u8)depth;
                } else {
                    nextDepth = (u8)(depthValue + 1);
                }
                FldCellFloodFillDirected(column, row - 1, 4, 0, axisMask, nextDepth, northLimit, visibleCount);
            }
            if (exits & 2) {
                westLimit = (limitedDirections & 2) ? 3 : limitValue;
                if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 2) && (((mode = ((FieldSceneState *)iGpffff9db0)->field.value) == 0x2C) || (mode == 0x40)) && (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].flags & 0x20)) {
                    nextDepth = (u8)depth;
                } else if (((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 7) || (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 8)) && (limitValue == 4)) {
                    nextDepth = (u8)depth;
                } else if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 3) && (((u8)axisMask & 2) != 0)) {
                    nextDepth = (u8)depth;
                } else {
                    nextDepth = (u8)(depthValue + 1);
                }
                FldCellFloodFillDirected(column - 1, row, 8, 0, axisMask, nextDepth, westLimit, visibleCount);
            }
            if (exits & 4) {
                southLimit = (limitedDirections & 4) ? 3 : limitValue;
                if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 2) && (((mode = ((FieldSceneState *)iGpffff9db0)->field.value) == 0x2C) || (mode == 0x40)) && (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].flags & 0x20)) {
                    nextDepth = (u8)depth;
                } else if (((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 7) || (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 8)) && (((u8)axisMask & 0xA) != 0) && (depthValue == 0)) {
                    /* 0015B8C0..0015B8CC: retain the prior next_depth. */
                    southLimit += 1;
                } else if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 3) && (((u8)axisMask & 4) != 0)) {
                    nextDepth = (u8)depth;
                } else {
                    nextDepth = (u8)(depthValue + 1);
                }
                FldCellFloodFillDirected(column, row + 1, 1, 0, axisMask, nextDepth, southLimit, visibleCount);
            }
            if (exits & 8) {
                eastLimited = limitedDirections & 8;
                if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 2) && (((mode = ((FieldSceneState *)iGpffff9db0)->field.value) == 0x2C) || (mode == 0x40)) && (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].flags & 0x20)) {
                    nextDepth = (u8)depth;
                } else if (((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 7) || (((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 8)) && (limitValue == 4)) {
                    nextDepth = (u8)depth;
                } else if ((((FldFrame *)MT_Scene_GetFrameState())->cells[row][column].type == 3) && (((u8)axisMask & 8) != 0)) {
                    nextDepth = (u8)depth;
                } else {
                    nextDepth = (u8)(depthValue + 1);
                }
                if (eastLimited != 0) {
                    limitValue = 3;
                }
                limit = (u8)limitValue;
                column = column + 1;
                FldCellFloodFillDirected(column, row, 2, 0, axisMask, nextDepth, limit, visibleCount);
            }
        }
    }
}

// Each step, position the tile, rotate band resources by the frame angle, and show or hide them by
// band.
// FUN_0015BAE0
void FldStepUpdateBandRes(void)
{
    u8 *fieldResources;
    u8 *playerResource;
    u8 *modelResources;
    u8 *alternateResources;
    s32 tileColumn;
    s32 tileRow;
    f32 angle;
    s32 i;
    s32 j;
    u8 *work;
    u8 *object;
    ResrcRecord *player;

    fieldResources = MT_Scene_GetResListHead(0xC);
    playerResource = MT_Scene_GetRes(0x400);
    player = (ResrcRecord *)playerResource;
    modelResources = MT_Scene_GetResListHead(0xA);
    alternateResources = MT_Scene_GetResListHead(0xB);
    tileColumn = 0;
    tileRow = 0;
    if (FldMap_IsCurrentInEitherBand() != 0) {
        if (playerResource != NULL) {
            tileColumn = FldFrameTask_GetTileX(((ResrcRecord *)playerResource)->handle220);
            /* measured: retail reads the second tile coordinate through the typed player resource
             * pointer. */
            tileRow = FldFrameTask_GetTileZ(player->handle220);
            goto clear_test;
clear_body:
            ((ResrcHeader *)fieldResources)->flags &= ~2U;
            fieldResources = (u8 *)((ResrcHeader *)fieldResources)->next;
clear_test:
            if (fieldResources != NULL) {
                goto clear_body;
            }
            MT_Scene_GetResListHead(0xC);
        } else {
            goto set_test;
set_body:
            ((ResrcHeader *)fieldResources)->flags |= 2;
            fieldResources = (u8 *)((ResrcHeader *)fieldResources)->next;
set_test:
            if (fieldResources != NULL) {
                goto set_body;
            }
            MT_Scene_GetResListHead(0xC);
        }

        work = (u8 *)kwlnGetCamera();
        angle = KDraw_MatrixYawDeg((u8 *)((RwCamera *)work)->object.object.parent + 0x10);
        D_0076430C = 0;
        if ((angle <= 45.0f) && !(angle < -45.0f)) {
            if ((angle <= 25.0f) && !(angle < -25.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 0xB, 4, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 25.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 3, 4, 0, 4,
                              &D_0076430C);
            } else if (angle <= -25.0f) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 9, 4, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= 135.0f) && !(angle <= 45.0f)) {
            if ((angle <= 115.0f) && !(angle < 65.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 7, 8, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 115.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 6, 8, 0, 4,
                              &D_0076430C);
            } else if (angle <= 65.0f) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 3, 8, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -45.0f) && !(angle < -135.0f)) {
            if ((angle <= -65.0f) && !(angle < -115.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 0xD, 2, 0, 4,
                              &D_0076430C);
            } else if (!(angle < -65.0f)) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 9, 2, 0, 4,
                              &D_0076430C);
            } else if (angle <= -115.0f) {
                FldCellFloodFillDirected(tileColumn, tileRow, 0, 0xC, 2, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -155.0f) || !(angle < 155.0f)) {
            FldCellFloodFillDirected(tileColumn, tileRow, 0, 0xE, 1, 0, 4,
                          &D_0076430C);
        } else if (!(angle < -155.0f) && (angle < 0.0f)) {
            FldCellFloodFillDirected(tileColumn, tileRow, 0, 0xC, 1, 0, 4,
                          &D_0076430C);
        } else if ((angle <= 155.0f) && !(angle <= 0.0f)) {
            FldCellFloodFillDirected(tileColumn, tileRow, 0, 6, 1, 0, 4,
                          &D_0076430C);
        }

        goto list_a_test;
list_a_body:
        object = ((ResrcRecord *)modelResources)->slotHandle[0];
        if (object != NULL) {
            if ((((ResrcHeader *)object)->flags & 2) != 0) {
                ((ResrcHeader *)modelResources)->flags |= 2;
            } else {
                ((ResrcHeader *)modelResources)->flags &= ~2U;
            }
        }
        modelResources = (u8 *)((ResrcHeader *)modelResources)->next;
list_a_test:
        if (modelResources != NULL) {
            goto list_a_body;
        }

        goto list_b_test;
list_b_body:
        object = ((ResrcRecord *)alternateResources)->slotHandle[0];
        if ((((ResrcHeader *)object)->flags & 2) != 0) {
            ((ResrcHeader *)alternateResources)->flags |= 2;
        } else {
            ((ResrcHeader *)alternateResources)->flags &= ~2U;
        }
        alternateResources = (u8 *)((ResrcHeader *)alternateResources)->next;
list_b_test:
        if (alternateResources != NULL) {
            goto list_b_body;
        }

        i = 0;
        goto array_a_test;
array_a_body:
        work = D_007E8C00 + i * 0x750;
        if (((FldUnitVisibilityState *)work)->active != 0) {
            object = ((FldUnitVisibilityState *)work)->resource;
            if (object != NULL) {
                ((ResrcHeader *)object)->flags &= ~2U;
            }
        }
        i++;
array_a_test:
        if (i < 0xF) {
            goto array_a_body;
        }

        j = 0;
        goto array_b_test;
array_b_body:
        work = (u8 *)D_007E8020[j];
        if (work != NULL) {
            object = ((FldUnitVisibilityState *)work)->resource;
            if (object != NULL) {
                ((ResrcHeader *)object)->flags |= 2;
            }
        }
        j++;
array_b_test:
        if (j < 8) {
            goto array_b_body;
        }
    }
}

// Return preload file-load task 0 or 1 from the step work block.
// FUN_0015C1E0
s32 FldStepFileTask(s32 index)
{
    u8 *work;
    u8 *p;
    u32 offset;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = ((SdkTask *)work)->work;
    p = (u8 *)((u32)byteAddressAdd((u32)(index * 4), (u8 *)((u32)p)));
    return ((FldStepWork *)p)->preloadTasks[0];
}

// Start the step preload: open the preload file when none is active and the step block has no file
// tasks.
// FUN_0015C210
void FldStepPreloadBegin(void) {
    if (D_00764334 == NULL) {
        return;
    }
    if (((FldStepWork *)((SdkTask *)D_00764334)->work)->preloadTasks[0] != 0) {
        return;
    }
    if (iGpffffb218 != 0) {
        return;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xB48);
    iGpffffb218 = H_Cdvd_AcquireDirectory(D_005F06C0, 1);
}

// Once the preload file is loaded, create its two file-load tasks; returns 1 when nothing is left
// to wait for.
// FUN_0015C280
s32 FldStepPreloadCreateTasks(void) {
    u8 *workBlock;
    FldStepWork *stepWork;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        kAssertFail(D_005F05E8, 0xB58);
        return 1;
    }
    workBlock = ((SdkTask *)iGpffffb244)->work;
    stepWork = (FldStepWork *)workBlock;
    if (H_Cdvd_IsFileLoaded((struct HCdvd *)(iGpffffb218)) == 0) {
        return 0;
    }
    /* measured: retail reads both task slots through the typed work pointer. */
    if (stepWork->preloadTasks[0] == 0) {
        ((FldStepWork *)workBlock)->preloadTasks[0] =
            FldRc_CreateFileLoadTask(iGpffffb244, D_005F06E0, 0x1E, iGpffffb218);
    }
    if (stepWork->preloadTasks[1] == 0) {
        ((FldStepWork *)workBlock)->preloadTasks[1] =
            FldRc_CreateFileLoadTask(iGpffffb244, D_005F0700, 0x14, iGpffffb218);
    }
    return 1;
}

// Return 0 while either preload task is still loading; otherwise destroy the preload handle and
// return 1.
// FUN_0015C360
s32 FldStepPreloadFinish(void) {
    u8 *workBlock;
    s32 i;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        kAssertFail(D_005F05E8, 0xB79);
        return 1;
    }
    workBlock = ((SdkTask *)iGpffffb244)->work;
    i = 0;
    while (i < 2) {
        if (((FldStepWork *)(workBlock + i * 4))->preloadTasks[0] != 0 &&
            FldRc_FileLoadIsReady(((FldStepWork *)(workBlock + i * 4))->preloadTasks[0]) == 0) {
            return 0;
        }
        i++;
    }
    if (iGpffffb218 != 0) {
        H_Cdvd_Destroy((struct HCdvd *)(iGpffffb218));
        iGpffffb218 = 0;
    }
    return 1;
}

// Open the step data file when the step block has no buffer yet; returns the open result or 0.
// FUN_0015C440
s32 FldStepOpenDataFile(void)
{
    s32 r = 0;
    u8 *p = D_00764334;
    if (p == NULL) {
        return r;
    }
    if (((FldStepWork *)((SdkTask *)p)->work)->scriptWord == 0) {
        func_00440b68(&iGpffff9e28, D_005F05E8, 0xC19);
        r = H_Cdvd_AcquireDirectory(D_005F0720, 0);
    }
    return r;
}

// Once loaded, copy the handle's file into a new step-block buffer, destroy the handle and return
// 1; return 0 while loading.
// FUN_0015C4B0
s32 FldStepCopyLoadedFile(u8 *handle) {
    u8 *workBlock;
    u8 *copyDst;
    u8 *copySrc;
    u32 size;
    FldStepWork *stepWork;
    HCdvdRequest *request = (HCdvdRequest *)handle;
    if (iGpffffb244 == NULL) {
        return 1;
    }
    workBlock = ((SdkTask *)iGpffffb244)->work;
    stepWork = (FldStepWork *)workBlock;
    if (handle == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded((struct HCdvd *)(handle)) != 0) {
        chkmemAllocSiteTag(D_005F05E8, 0xC30);
        size = ((HCdvdRequest *)handle)->signedSize;
        /* measured: retail stores the allocated buffer through the typed work pointer. */
        stepWork->scriptData =
            (u8 *)D_008873F4[0](1, size, 0x40000);
        /* measured: retail rereads the size from the request after the allocation call. */
        ((FldStepWork *)workBlock)->scriptSize = request->signedSize;
        size = request->signedSize;
        copyDst = stepWork->scriptData;
        copySrc = request->data;
        memcpy(copyDst, copySrc, size);
        H_Cdvd_Destroy((struct HCdvd *)(handle));
        return 1;
    }
    return 0;
}

// Format a numbered file path from the id and open it.
// FUN_0015C590
s32 FldStepLoadNumberedFile(s32 id) {
    u8 path[0x80];

    sprintf(path, (const char *)D_005F0740, id);
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC49);
    return (s32)H_Cdvd_AcquireDirectory(path, 0);
}

// Return 1 when the id is zero or its file is loaded.
// FUN_0015C5F0
s32 FldStepLoadIdIsDone(s32 id)
{
    if (id == 0) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded((struct HCdvd *)(id)) != 0;
}

/* Constant-success handle predicate; unlike the neighboring load query it never polls. */
// FUN_0015C630
s32 fldStepLoadHandleAlwaysReady(u8 *unusedHandle)
{
    return 1;
}

// Format a file path from the two ids; return NULL if the file is missing, otherwise open it.
// FUN_0015C640
u8 *FldStepLoadFilePair(s32 fieldId, s32 roomId) {
    u8 directory[0x80];
    u8 path[0x80];

    strcpy(directory, (const char *)D_005F0760);
    sprintf(path, (const char *)D_005F0770, fieldId & 0xFFFF, roomId & 0xFFFF);
    if (H_Cdvd_FileExists(path) == 0) {
        return NULL;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC9E);
    return (u8 *)H_Cdvd_AcquireDirectory(path, 0);
}

// Return 1 for a null handle or when its file is loaded.
// FUN_0015C6F0
s32 FldStepLoadHandleIsDone(u8 *handle)
{
    if (handle == NULL) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded((struct HCdvd *)(handle)) != 0;
}

// FUN_0015C730
void FldStepLoadHandleDestroy(u8 *handle)
{
    H_Cdvd_Destroy((struct HCdvd *)(handle));
}
