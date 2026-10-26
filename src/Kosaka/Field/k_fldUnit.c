#include "member_access.h"
#include "mt_scene_internal.h"
#include "model_motion_internal.h"
/* Original translation unit k_fldUnit.c (from __FILE__ assert strings). */
#include "type.h"
#include "datUnit_internal.h"
#include "h_cdvd_internal.h"
#include "resrc_manager_internal.h"
#include "scene_resource_internal.h"
#include "kwln_task_internal.h"
#include "sdk_task_registration.h"
#include "model_matrix_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "Kosaka/k_model_internal.h"
#include "rw/std/stddef.h"
#include "field_frame_internal.h"

/* Common-subexpression elimination and propagation are on for this unit outside the update scopes. */
#pragma opt_common_subs on
#pragma opt_propagation on

typedef struct HCdvd HCdvd;
typedef struct Model Model;
typedef struct Resrc Resrc;
typedef struct RwMatrix RwMatrix;

/* D_007EFB64 begins at the icon-task sub-object within each party slot. */
typedef struct FieldUnitIconTask { s32 task; } FieldUnitIconTask;
extern void (*DAT_008873EC[])(void *);
extern void *(*DAT_008873F4[])(size_t, size_t, u32);

extern s32 iGpffffb2e8;
extern s32 iGpffffb260;
extern s32 iGpffffb2e4;
extern s32 iGpffffb274;
extern u8 *iGpffffb414;
extern s32 D_00764344;
extern s32 D_00724504;
extern u8 *iGpffff9db0;
extern u8 iGpffff9f28;
extern u8 iGpffff9f29;
extern u8 iGpffff9f2a;
extern u8 iGpffff9f2b;
extern u8 iGpffff9f24;
extern s32 KMisc_CreateDelayMdlFree(s32 mdl, s32 countdown);
extern void datUnitFree(s32 allocation);
extern s32 mdlPrepareSlotModel(u8 *model, u16 slotIndex);
extern void mdlDetachSlotModel(u8 *model, u16 slotIndex);
extern u32 H_Cdvd_IsFileLoaded(HCdvd *cdvd);
extern u32 H_Cdvd_Destroy(HCdvd *cdvd);
extern void *memcpy(void *, const void *, u32);
extern s32 Encount_GetEntryRateOrOverride(u16 field, u16 room, u16 entryIndex);
extern s32 Encount_GetEntryFlags(u16 field, u16 room, u16 entryIndex);
extern void FldSlotBroadcastState(s32 state);
extern s32 FldUnit_SpawnEncounter(u32 limit, s32 refill);
extern DatUnitEc *datUnitCreateEncounterGroup(u16 encountId);
extern u8 *FldUnit_CreateEncounterUnit(u32 encounter, u8 *placement, s32 variant);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);
extern u32 RpRandom(void);
extern void mdlSetAttachedOwner(u8 *model, u8 *owner);
extern s32 FldEvent_AverageEntryValue(void);
extern void FldShadow_SetRingParticles(s32 task, f32 radius);
extern void mdlScale(Model *model, const RwV3d *scale, s32 combineOp);
extern void RwMatrixUpdate(u8 *);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
extern void FldFrameTask_SetPosition();
extern void SceneDraw_SetResVisibleChecked(u16 resTypeId, u32 visible);
extern void FldFrameTask_SetFlags(s32 task, s32 flags);
extern void FldFrameTask_SetHeight(s32 task, f32 height);
extern u32 *mdlCloneModelObject(u8 *source);
extern f32 FldFrameTask_GetHeight(s32 task);
extern void mdlAdvanceModelFromFlags(u8 *model);
extern s32 FldAI_SpawnPatrol(s32 parent, u8 *actor, s32 behavior);
extern s32 FldCharacterAnimSelect(s32 characterType);
extern s32 FldAI_SpawnChaser(s32 parent, u8 *follower, u8 *leader);
extern void FldAI_ChaserEnable(s32 task);
extern s32 FldPlayerIconTaskCreate(u8 *task);
extern void FldFrameTask_UpdateTile(s32 task);
extern f32 RwV3dLength(f32 *);
extern s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level);
extern u8 *FldUnit_FindNearestUnits(s32 unused, u32 limit, f32 minimumDistance);
extern u8 *FldEvent_GetGridCellEntry(s32 column, s32 row);
extern void FldEvent_BeginGridScan(void);
extern s32 FldEvent_NextGridCell(s32 *columnOut, s32 *rowOut);
extern s32 datGetFlag(s32 bit);
extern s32 MT_Scene_CreateModelFldRes(s32 resourceId, s32 model);
extern u8 *FldSlotFindFree(void);
extern DatUnitPc *datUnitCreatePc(u16 pcId);
extern u8 *FldPartyModelGet(u16 field, u16 room, s32 member);
extern u8 datPersonaGetLevelByPcId(u16 pcId);
extern s16 datGetPartyId(s32 idx);
extern s32 datCalcGetLevelById(s32 unitId);
extern s32 *MT_Scene_GetFrameState(void);
extern void SceneDraw_SetResVisible(u16 resTypeId, s32 visible);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern s32 FldNpcControlTaskCreate(s32 parent, s32 actor);

extern void *memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];
extern u8 D_007E8C00[];
extern u8 D_007EF9B0[];
extern u8 D_007E8BE0[];
extern u8 D_005F1500[];
extern u8 D_005F1510[];
extern u8 D_005F13C0[];
extern u8 D_005F1340[];
extern u8 D_005F12E0[];
extern u8 D_005F1520[];
extern u8 D_005F1528[];
extern u8 D_005DC920[];
extern u8 D_00756510[];
extern u8 D_005F1530[];
extern u8 D_005F1550[];
extern u8 D_005F1570[];
extern s32 D_007E8BE8[];
extern s32 D_00764364;
extern u8 D_007EF9F8[];
extern u8 D_007F16F0[];
extern u8 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 D_007EFB60[];
extern FieldUnitIconTask D_007EFB64[];
extern u8 D_007F00D8[];
extern u8 D_005F1590[];
extern SdkTaskUpdate D_005F15B0[];
extern u8 D_005F15C0[];
extern u8 D_005F15E0[];
extern u8 D_007E80A0[];

static s32 D_007643C8[2];
static s32 D_007643C0[2];
extern u8 D_00763008[8];
extern u8 D_00763010[4];
extern u8 *D_00762EA0;
static s32 D_00764350;
extern f32 D_007613EC;

typedef struct {
    u8 b[4];
} S4;

typedef struct {
    u32 h[2];
} S8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

s32 FldUnit_SetupSlot(s32 slotIndex);
void FldUnit_ReleaseSlot(u8 *unit);
void FldUnit_UpdateSlot(s32 slotIndex);
void FldUnit_SetSlotModel(u8 *unit, s32 destroyModel);
s32 mdlPrepareModel(u8 *model);
s32 func_00440b68(const char *fmt, ...);
u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
s32 FldMap_IsCurrentInBandA(void);
s32 FldMap_IsCurrentInBandB(void);
s32 FldUnit_SetupEncounter(u8 *task);
void chkmemAllocSiteTag(u8 *file, s32 line);
f32 sinf(f32);
u8 *mdlGetColor(s32 model);
void mdlSetColor(s32 model, u8 *color);
void mdlEffectGetPackedColor(u8 *object, u8 *color);
void mdlEffectSetPackedColor(u8 *object, u8 *packedColor);
void *mdlGetMatrix(void *model);
void MT_Scene_DestroyRes(u16 resTypeId);
void mdlClearAlphaBlend(s32 model);
void mdlDestroyModelObject(u8 *model);
void kwlnTaskDestroyWithHierarchy(s32 task);
s32 FldRoomIsListed(u16 field, u16 room);
s32 FldStepIndex(void);
s32 FldUnit_UpdatePartyState(u8 *task);
u8 *MT_Scene_GetResListHead(s32 resourceType);
void kAssertFail(void *file, s32 line);
void FldUnit_ApplySlotTint(u8 *entry, u8 *placement, s32 resourceId);
u8 *FldUnit_FindNearestSlot(u8 *limit, u32 *selectedIndex, s32 requestedIndex);
extern s64 datGetDateIndex(void);
extern s32 datGetScriptValue(s32 index);
extern s32 calGetDayWindowFlags(s16 day);
extern s32 D_007E8BF8[];
void *memset(void *, s32, u32);
s32 Encount_GetEntryRate(u16 field, u16 room, u16 entryIndex);
s32 fldStepGetModelSlot(void);
u8 *Encount_FindRecord(s32 field, s32 room, u16 index, u16 mode);

/* Word-aligned RenderWare matrix view; retail copies all 64 bytes. */
typedef struct {
    RwV3d right;       /* 0x00 */
    u32 flags;        /* 0x0C */
    RwV3d up;          /* 0x10 */
    u32 pad1C;
    RwV3d forward;     /* 0x20 */
    u32 pad2C;
    RwV3d position;    /* 0x30 */
    u32 pad3C;
} FieldUnitMatrix;

typedef struct {
    s32 fieldId;
    s32 roomId;
} FieldUnitRoomKey;
typedef struct FieldUnitPlacement {
    u16 resourceId;                       /* 0x000: low 10 bits are the ID */
    u8 unknown002[0x136];
    struct FieldUnitPlacement *next;      /* 0x138 */
    u8 unknown13C[4];
    RwV3d position;                       /* 0x140 */
    f32 yawDegrees;                       /* 0x14C */
} FieldUnitPlacement;
typedef struct {
    u8 flags;                            /* bit 0 is changed by the date test */
    u8 unknown01[3];
    void *resource;                       /* 0x04 */
    u8 unknown08[4];
} FieldUnitAnimationLayer;                /* 0x0C bytes */
typedef struct {
    u8 unknown000[0xD4];
    u16 kind;                            /* 0x0D4 */
    u8 pad0D6[2];
    s32 flags;
    u8 pad0DC[0x48];
    u8 *effectColor;
    u8 pad128[0x164];
    FieldUnitAnimationLayer layers[5];    /* 0x28C */
    u8 pad2C8[4];
    u8 *effectList;
} FieldUnitModel;
typedef struct {
    u16 resourceId;                       /* 0x000 */
    u8 unknown002[0x162];
    FieldUnitModel *model;            /* 0x164 */
    u8 unknown168[0xB8];
    u8 *movementTask;                     /* 0x220: position/yaw/radius */
    u8 *effectTask;                       /* 0x224 */
    Model *markerModel;                   /* 0x228: scaled by the radius */
} FieldUnitSceneResource;
typedef struct {
    f32 value0;
    f32 value1;
} FieldUnitSamplePair;
typedef struct {
    u8 unknown000[0x40];
    s32 flags;
    s32 ownsModel;
    void *unitData;                       /* 0x048: NULL means unused */
    void *modelData;                      /* 0x04C */
    FieldUnitModel *model;            /* 0x050 */
    FieldUnitSceneResource *scene;        /* 0x054: NULL until initialized */
    u16 placementId;                      /* 0x058 */
    u8 unknown05A[2];
    FieldUnitPlacement placementStorage; /* 0x05C */
    FieldUnitPlacement *placement;        /* 0x1AC */
    s32 followerTask;                     /* 0x1B0: follows the previous unit */
    s32 iconTask;
    s32 tintTask;
    u8 pad1BC[4];
    s32 level;
    s32 calculatedLevel;
    u16 encounterCategory;
    u8 variant;
    u8 levelBand;
    s16 cellX;
    s16 cellZ;
    u8 state1D0[0x40];
    FieldUnitSamplePair samples[0x40];    /* 0x210 */
    u8 state410[0x300];
    u8 pad710[4];
    s32 animationData[5];
    u16 characterId;                      /* 0x728: datGetPartyId result */
    u8 pad72A[6];
    s32 file;
    void *fileData;
    s32 fileSize;
    u8 pad73C[0x14];
} FieldUnitRecord;                       /* 0x750 bytes */
/* The NPC scene tail holds its copied file data and control-task handle.
 * Reuse the common 0x140 resource prefix; the remaining offsets are proven
 * by FldUnit_InstallResources and the shared ResrcRecord teardown fields. */
typedef struct FieldUnitNpcResource {
    ResrcHeader base;
    u8 pad140[0x24];
    void *model;
    u8 pad168[0xC0];
    s32 unk228;
    void *marker;
    u8 pad230[4];
    s32 unk234;
    u8 pad238[0x50];
    void *fileData;
    u32 fileSize;
    u8 pad290[4];
    s32 controllerTask;
} FieldUnitNpcResource;

/* Layer assets expose an integer value at 0x2FC; its meaning is unknown. */
typedef struct FieldUnitLayerResource {
    u8 pad000[0x2FC];
    s32 unk2FC;
} FieldUnitLayerResource;

typedef struct FieldUnitEffectNode {
    struct FieldUnitEffectNode *first;
    u8 pad04[4];
    u8 *effect;
    u8 pad0C[4];
    struct FieldUnitEffectNode *next;
} FieldUnitEffectNode;

/* Callback allocations: encounter/tint work is 0x10 bytes; the party
 * replacement request is 0x28 bytes with four requested and selected slots. */
typedef struct FieldUnitEncounterWork {
    s32 state, mode, suspended;
    u32 limit;
} FieldUnitEncounterWork;
typedef struct FieldUnitTintWork {
    s32 unk00;
    u8 *unit;
    s32 frame, period;
} FieldUnitTintWork;
typedef struct FieldUnitPartyWork {
    s32 state;
    s32 requestedIds[4];
    s32 selectedCount;
    s32 selectedIndices[4];
} FieldUnitPartyWork;

/* Eight-byte model-cache entries and 0x168-byte field-object slots. */
typedef struct FieldUnitModelCache {
    u16 fieldId, roomId;
    u8 *model;
} FieldUnitModelCache;
typedef struct FieldUnitModelCacheGroup {
    FieldUnitModelCache player;
    FieldUnitModelCache members[3];
} FieldUnitModelCacheGroup;
typedef struct FieldUnitNearbySelection {
    u8 *units[8], *objects[8];
} FieldUnitNearbySelection;
typedef struct FieldUnitObject {
    s32 active, flags, unk08;
    u16 resourceId, placementIndex;
    FieldUnitPlacement placement;
    u8 *encounter;
    u8 *marker;
} FieldUnitObject;

typedef struct FldPairSelection {
    s32 active;
    u16 modelType, modelId;
    s32 nodeIndex;
    s32 actorId;
} FldPairSelection;

/* Locate a model animation layer for the selected unit. measured: retail loads the model pointer
 * after computing the layer index, which only the inline wrapper reproduces. */
static inline FieldUnitAnimationLayer *fldUnitLayerAt(FieldUnitRecord *unit, s32 index)
{
    return &unit->model->layers[index];
}
/* Locate the indexed pair of cached unit samples. measured: writing the access out inline swaps the
 * address-add operand order for the first sample member, unlike retail. */
static inline FieldUnitSamplePair *fldUnitSampleAt(FieldUnitRecord *unit, s32 index)
{
    return &unit->samples[index];
}
/* Locate a party unit using an index read through its original pointer. measured: inlining by hand
 * changes how the unit index is allocated and enlarges the facing-update stack frame. */
static inline FieldUnitRecord *fldUnitSlotAt(const s32 *index)
{
    return &((FieldUnitRecord *)D_007EF9B0)[*index];
}
/* Test the current room and calendar parity, excluding March twentieth. */
static inline s32 fldUnitCalendarRoomMatch(void)
{
    extern s32 calIsCurrentMonthDay(s32 unused, s32 month, s32 day);
    extern s16 datGetDateIndex(void);
    extern u8 datGetTimeSlot(void);
    extern s64 calGetDayEntryByPhase(s32 day, u32 phase);
    extern FieldUnitRoomKey D_005F1350[];
    u8 *fieldState;
    s32 fieldId;
    s32 found;
    s32 roomIndex;
    s32 calendarDay;
    s32 calendarValue;
    s32 remainder;
    FieldUnitRoomKey *entry;

    found = 0;
    /* March 20 bypasses the room scan. */
    if (calIsCurrentMonthDay((s16)datGetDateIndex(), 3, 0x14) == 1) {
        return 0;
    }
    roomIndex = 0;
    goto room_test;
room_body:
    fieldState = iGpffff9db0;
    if (((FieldUnitRoomKey *)fieldState)->fieldId == fieldId &&
        ((FieldUnitRoomKey *)fieldState)->roomId == entry->roomId) {
        calendarDay = (s16)datGetDateIndex();
        calendarValue = (s8)calGetDayEntryByPhase(calendarDay, datGetTimeSlot() & 0xFF);
        /* The signed calendar value can be negative; keep the signed remainder. */
        remainder = calendarValue % 2;
        if (remainder != 0) {
            found = 1;
            goto room_done;
        }
    }
    roomIndex += 1;
room_test:
    entry = (FieldUnitRoomKey *)((u8 *)D_005F1350 + roomIndex * 8);
    fieldId = entry->fieldId;
    if (fieldId != -1) {
        goto room_body;
    }
room_done:
    return found;
}
s32 FldEvent_IsCellOccupied(u8 *position);
/* Pick a random placement and reject it when it is too close to a party member. */
/* Choose an unoccupied placement away from the active party members. */
static inline u8 *fldChooseRandomSpawn(V3 *delta)
{
    u32 count;
    s32 rejected;
    u8 *choice;
    u8 *cursor;
    s32 index;
    s32 walked;
    s32 used;
    s32 ready;
    u8 *unit;
    u8 *model;
    void **modelSlot;
    f32 coordinate;

retry:
    count = 0;
    rejected = 0;
    cursor = MT_Scene_GetResListHead(0xF);
    goto count_test;
count_body:
    count++;
    cursor = *(u8 * *)&((FieldUnitPlacement *)cursor)->next;
count_test:
    if (cursor != NULL) {
        goto count_body;
    }
    count = RpRandom() % count;
    choice = MT_Scene_GetResListHead(0xF);
    walked = 0;
    goto walk_test;
walk_body:
    choice = *(u8 * *)&((FieldUnitPlacement *)choice)->next;
    walked++;
walk_test:
    if (walked < (s32)count) {
        goto walk_body;
    }
    index = 0;
    goto party_test;
party_body:
    used = 0;
    unit = D_007EF9B0 + index * 0x750;
    if (*(s32 *)&((FieldUnitRecord *)unit)->unitData != 0 && *(s32 *)&((FieldUnitRecord *)unit)->scene != 0) {
        used = 1;
    }
    ready = used != 0;
    if (ready) {
        unit = D_007EF9B0 + index * 0x750;
        modelSlot = (void **)&((FieldUnitRecord *)unit)->model;
        model = (u8 *)mdlGetMatrix(*(void * *)&((FieldUnitRecord *)unit)->model);
        coordinate = ((FieldUnitMatrix *)model)->position.x;
        delta->x = ((FieldUnitPlacement *)choice)->position.x - coordinate;
        model = (u8 *)mdlGetMatrix(*modelSlot);
        coordinate = ((FieldUnitMatrix *)model)->position.y;
        delta->y = ((FieldUnitPlacement *)choice)->position.y - coordinate;
        model = (u8 *)mdlGetMatrix(*modelSlot);
        coordinate = ((FieldUnitMatrix *)model)->position.z;
        delta->z = ((FieldUnitPlacement *)choice)->position.z - coordinate;
        if (RwV3dLength(&delta->x) < 3000.0f) {
            goto checked_party;
        }
    }
    index++;
party_test:
    if (index < 4) {
        goto party_body;
    }
checked_party:
    if (index < 4) {
        rejected = 1;
    }
    {
        s32 result;
        s32 yes;

        result = FldEvent_IsCellOccupied(choice + 0x140);
        yes = 1;
        if (result == yes || rejected == yes) {
            goto retry;
        }
    }
    return choice;
}
/* measured: common-subexpression elimination is off so the unit base address is computed again
 * after the allocator call, as in retail. */
#pragma push
/* Wait for party models and animation slots, then copy loaded per-unit resource data. */
// FUN_00162C30
/* measured: retail's block lifetimes need common-subexpression elimination off for this function. */
#pragma opt_common_subs off
s32 FldUnit_UpdateTable(void)
{
    s32 field;
    s32 i;
    s32 j;
    s32 k;
    s32 *unitWords;
    s32 *loadedUnitWords;
    s32 copySize;
    s32 fileHandle;
    s32 resource;

    for (i = 0; i < 4; i++) {
        unitWords = ((s32 *)D_007EF9B0) + i * 468;
        if ((*(s32 *)&((FieldUnitRecord *)unitWords)->unitData != 0) && (*(s32 *)&((FieldUnitRecord *)unitWords)->scene == 0)) {
            if (mdlPrepareModel((u8 *)(*(s32 *)&((FieldUnitRecord *)unitWords)->model)) == 0) {
                return 0;
            }
            for (j = 0; j < 5; j++) {
                if (mdlPrepareSlotModel((u8 *)(*(s32 *)&((FieldUnitRecord *)unitWords)->model), j) == 0) {
                    return 0;
                }
            }
            if ((fileHandle = ((FieldUnitRecord *)unitWords)->file) != 0) {
                if (H_Cdvd_IsFileLoaded((HCdvd *)(fileHandle)) == 0) {
                    return 0;
                }
                chkmemAllocSiteTag(D_005F1500, 0x218);
                loadedUnitWords = ((s32 *)D_007EF9B0) + i * 468;
                field = (s32)&((FieldUnitRecord *)loadedUnitWords)->file;
                resource = *(s32 *)&((HCdvd *)((FieldUnitRecord *)loadedUnitWords)->file)->fileSize;
                *(s32 *)&((FieldUnitRecord *)loadedUnitWords)->fileData = (s32)(*DAT_008873F4)(1, resource, 0x40000);
                ((FieldUnitRecord *)loadedUnitWords)->fileSize = *(s32 *)&((HCdvd *)*(s32 *)field)->fileSize;
                resource = *(s32 *)field;
                copySize = *(s32 *)&((HCdvd *)resource)->fileSize;
                memcpy((void *)*(s32 *)&((FieldUnitRecord *)loadedUnitWords)->fileData,
                              (const void *)(*(s32 *)&((HCdvd *)resource)->fileMemory), copySize);
                H_Cdvd_Destroy((HCdvd *)(*(s32 *)field));
                *(s32 *)field = 0;
                for (k = 0; k < 5; k++) {
                    resource = *(s32 *)&((FieldUnitRecord *)loadedUnitWords)->model;
                    copySize = (s32)((FieldUnitModel *)resource)->layers[k].resource;
                    if (copySize != 0) {
                        ((FieldUnitRecord *)loadedUnitWords)->animationData[k] =
                            ((FieldUnitLayerResource *)copySize)->unk2FC;
                    }
                }
            }
        }
    }
    return 1;
}
#pragma pop

/* measured: the slot setup, spawn and facing functions below need this optimizer setting to
 * reproduce retail code. Initialize the four occupied party slots lacking scene resources: attach
 * models and placements, apply the leader's calendar/room animation rule, position the party, then
 * create follower controllers. */
#pragma push
/* measured: retail keeps dead assignments and separate variable lifetimes here; the initializer and
 * FldUnit_UpdateFacing need these settings. */
// FUN_00162E10
/* measured: retail keeps assignments the optimizer would drop, so dead-assignment elimination is
 * off. */
#pragma opt_dead_assignments off
void FldUnit_UpdateFacing(void)
{
    extern u8 *func_003e0f80(void);
    extern void func_003e0f40(u8 *);
    extern f32 RwV3dNormalize(f32 *, f32 *);
    extern void FldFrameTask_SetHeight(u8 *task, f32 height);
    extern f32 FldFrameTask_GetHeight(u8 *task);
    extern void FldFrameTask_SetFlags(u8 *task, s32 flags);
    extern void FldFrameTask_SetPosition(u8 *task, u8 *position);
    extern void FldShadow_SetRingParticles(u8 *task, f32 radius);
    extern s32 FldMap_IsCurrentInEitherBand(void);
    extern s32 MT_Scene_CreateModelCharShadowRes(u16 resourceId, u16 shadowModelId, void *model);
    extern f32 D_007615DC;
    RwV3d formationOffset;
    RwV3d markerScale;
    RwV3d spawnPosition;
    s32 partyIndex;
    FieldUnitMatrix *formationMatrix;
    u16 resourceVariant;
    FieldUnitRecord *unit;
    FieldUnitSceneResource **sceneResource;
    FieldUnitModel **characterModel;

    formationMatrix = (FieldUnitMatrix *)func_003e0f80();
    for (partyIndex = 0; partyIndex < 4; partyIndex++) {
        resourceVariant = 1;
        unit = (FieldUnitRecord *)(D_007EF9B0 + partyIndex * 0x750);
        if (unit->unitData == NULL) {
            continue;
        }
        sceneResource = &unit->scene;
        if (unit->scene != NULL) {
            continue;
        }
        if (FldStepIndex() != 0 &&
            FldRoomIsListed(((u16 *)iGpffff9db0)[0],
                          ((u16 *)iGpffff9db0)[2]) == 0) {
            resourceVariant = 3;
        }
        /* Register this model with the scene and initialize its attached effect. */
        {
            FieldUnitRecord *unitForSetup =
                (FieldUnitRecord *)(D_007EF9B0 + (s32)partyIndex * 0x750);

            FieldUnitSceneResource **createdResource;
            u16 resourceId;

            characterModel = &unitForSetup->model;
            resourceId = MT_Scene_CreateModelCharShadowRes(partyIndex, resourceVariant, unitForSetup->model);
            createdResource = &unitForSetup->scene;
            *createdResource = (FieldUnitSceneResource *)MT_Scene_GetRes(resourceId);
            FldShadow_SetRingParticles((*createdResource)->effectTask, 60.0f);
        }
        /* Look up the placement resource. When both the list and ID are absent,
         * retail leaves the existing unit->placement untouched. */
        {
            FieldUnitPlacement *placementHead =
                (FieldUnitPlacement *)MT_Scene_GetResListHead(0xE);

            if (placementHead != NULL || unit->placementId != 0xFFFF) {
                FieldUnitPlacement *placementCursor = placementHead;

                while (placementCursor != NULL) {
                    if ((placementCursor->resourceId & 0x3FF) == unit->placementId) {
                        break;
                    }
                    placementCursor = placementCursor->next;
                }
                unit->placement = placementCursor;
            }
        }
        /* Only the leader applies the calendar/room test to animation flags. */
        if (partyIndex == 0) {
            FldFrameTask_SetHeight((*sceneResource)->movementTask, 60.0f);
            if ((*characterModel)->kind != 1) {
                s32 foundEligibleRoom = fldUnitCalendarRoomMatch();

                if (foundEligibleRoom == 0) {
                    s32 layerIndex;

                    for (layerIndex = 0; layerIndex < 5; layerIndex++) {
                        fldUnitLayerAt(unit, layerIndex)->flags &= ~1;
                    }
                } else {
                    s32 layerIndex;

                    for (layerIndex = 0; layerIndex < 5; layerIndex++) {
                        fldUnitLayerAt(unit, layerIndex)->flags |= 1;
                    }
                }
                mdlDispatchAnimIfPresent((u8 *)*characterModel, 0,
                              FldCharacterAnimSelect(fldUnitSlotAt(&partyIndex)->characterId), 0, 1);
            }
        } else {
            FldFrameTask_SetHeight((*sceneResource)->movementTask, 35.0f);
        }
        /* Scale the marker, then obtain the spawn position and yaw. */
        {
            FieldUnitRecord *unitForSetup =
                (FieldUnitRecord *)(D_007EF9B0 + (u32)partyIndex * 0x750);
            FieldUnitSceneResource **setupResource = &unitForSetup->scene;
            f32 markerScaleValue;
            FieldUnitPlacement *placement;

            (*setupResource)->markerModel = (Model *)mdlCloneModelObject((u8 *)iGpffffb274);
            markerScaleValue = FldFrameTask_GetHeight((*setupResource)->movementTask);
            markerScale.x = markerScale.y = markerScale.z = markerScaleValue;
            mdlScale((*setupResource)->markerModel, &markerScale, 2);
            mdlAdvanceModelFromFlags((u8 *)(*setupResource)->markerModel);
            placement = unitForSetup->placement;
            if (placement == NULL) {
                u8 *gridRow;

                /* Retail queries the frame state separately for each grid read and casts the bytes
                 * to float as unsigned. */
                spawnPosition.x = 1200.0f *
                    (f32)(u32)((FldFrame *)MT_Scene_GetFrameState())->spawnColumn;
                spawnPosition.y = 2.0f;
                spawnPosition.z = 1200.0f *
                    (f32)(u32)((FldFrame *)MT_Scene_GetFrameState())->spawnRow;
                unitForSetup = fldUnitSlotAt(&partyIndex);
                gridRow = (u8 *)MT_Scene_GetFrameState() +
                    (((FldFrame *)MT_Scene_GetFrameState())->spawnRow << 8);
                FldFrameTask_Rotate((*sceneResource)->movementTask, D_00756510,
                    90.0f * (f32)((FldFrameCellInRow((u8 *)(u32)gridRow, ((FldFrame *)MT_Scene_GetFrameState())->spawnColumn)->kind + 2) % 4));
                mdlDispatchAnimIfPresent((u8 *)*characterModel, 0,
                              FldCharacterAnimSelect(unitForSetup->characterId), 0, 1);
                *formationMatrix = *(FieldUnitMatrix *)mdlGetMatrix(
                    (*(FieldUnitSceneResource **)D_007EFA04)->model);
                if (partyIndex == 0 && FldMap_IsCurrentInEitherBand() != 0) {
                    formationOffset = formationMatrix->forward;
                    RwV3dNormalize(&formationOffset.x, &formationOffset.x);
                    formationOffset.x *= 400.0f;
                    formationOffset.y *= 400.0f;
                    formationOffset.z *= 400.0f;
                    spawnPosition.x += formationOffset.x;
                    spawnPosition.y += formationOffset.y;
                    spawnPosition.z += formationOffset.z;
                }
            } else {
                FieldUnitPlacement **placementSlot =
                    &((FieldUnitRecord *)(D_007EF9B0 + partyIndex * 0x750))->placement;

                FldFrameTask_Rotate((*sceneResource)->movementTask, D_00756510, placement->yawDegrees);
                spawnPosition = (*placementSlot)->position;
            }
        }
        /* D_007EFA04 is the leader's scene-resource slot. Followers start at its
         * current matrix position, not the not-yet-published spawnPosition. */
        *formationMatrix = *(FieldUnitMatrix *)mdlGetMatrix(
            (*(FieldUnitSceneResource **)D_007EFA04)->model);
        switch (partyIndex) {
        case 0:
            FldFrameTask_SetPosition((*sceneResource)->movementTask, (u8 *)&spawnPosition);
            break;
        case 1: /* 60 right, 60 behind the leader. */
            formationOffset = formationMatrix->right;
            RwV3dNormalize(&formationOffset.x, &formationOffset.x);
            formationOffset.x *= 60.0f;
            formationOffset.y *= 60.0f;
            formationOffset.z *= 60.0f;
            formationMatrix->position.x += formationOffset.x;
            formationMatrix->position.y += formationOffset.y;
            formationMatrix->position.z += formationOffset.z;
            formationOffset = formationMatrix->forward;
            RwV3dNormalize(&formationOffset.x, &formationOffset.x);
            formationOffset.x = -formationOffset.x;
            formationOffset.y = -formationOffset.y;
            formationOffset.z = -formationOffset.z;
            formationOffset.x *= 60.0f;
            formationOffset.y *= 60.0f;
            formationOffset.z *= 60.0f;
            formationMatrix->position.x += formationOffset.x;
            formationMatrix->position.y += formationOffset.y;
            formationMatrix->position.z += formationOffset.z;
            FldFrameTask_SetPosition((*sceneResource)->movementTask, (u8 *)&formationMatrix->position);
            break;
        case 2: /* 60 left, 120 behind the leader. */
            formationOffset = formationMatrix->right;
            RwV3dNormalize(&formationOffset.x, &formationOffset.x);
            formationOffset.x = -formationOffset.x;
            formationOffset.y = -formationOffset.y;
            formationOffset.z = -formationOffset.z;
            formationOffset.x *= 60.0f;
            formationOffset.y *= 60.0f;
            formationOffset.z *= 60.0f;
            formationMatrix->position.x += formationOffset.x;
            formationMatrix->position.y += formationOffset.y;
            formationMatrix->position.z += formationOffset.z;
            formationOffset = formationMatrix->forward;
            RwV3dNormalize(&formationOffset.x, &formationOffset.x);
            formationOffset.x = -formationOffset.x;
            formationOffset.y = -formationOffset.y;
            formationOffset.z = -formationOffset.z;
            formationOffset.x *= 120.0f;
            formationOffset.y *= 120.0f;
            formationOffset.z *= 120.0f;
            formationMatrix->position.x += formationOffset.x;
            formationMatrix->position.y += formationOffset.y;
            formationMatrix->position.z += formationOffset.z;
            FldFrameTask_SetPosition((*sceneResource)->movementTask, (u8 *)&formationMatrix->position);
            break;
        case 3: /* 200 behind the leader. */
            formationOffset = formationMatrix->forward;
            RwV3dNormalize(&formationOffset.x, &formationOffset.x);
            formationOffset.x = -formationOffset.x;
            formationOffset.y = -formationOffset.y;
            formationOffset.z = -formationOffset.z;
            formationOffset.x *= 200.0f;
            formationOffset.y *= 200.0f;
            formationOffset.z *= 200.0f;
            formationMatrix->position.x += formationOffset.x;
            formationMatrix->position.y += formationOffset.y;
            formationMatrix->position.z += formationOffset.z;
            FldFrameTask_SetPosition((*sceneResource)->movementTask, (u8 *)&formationMatrix->position);
            break;
        }
        /* Each follower tracks the preceding party member. */
        if (partyIndex != 0) {
            FieldUnitRecord *unitForUpdate = fldUnitSlotAt(&partyIndex);

            ((FieldUnitRecord *)(u32)unitForUpdate)->followerTask =
                FldAI_SpawnChaser(0, (u8 *)unitForUpdate,
                             D_007EF9B0 + (partyIndex - 1) * 0x750);
        }
        {
            FieldUnitRecord *unitForUpdate = fldUnitSlotAt(&partyIndex);
            FieldUnitSceneResource **resourceForUpdate;
            f32 initialSampleValue;
            s32 sampleIndex;

            RwMatrixUpdate((u8 *)mdlGetMatrix((void *)*characterModel));
            resourceForUpdate = &((FieldUnitRecord *)(u32)unitForUpdate)->scene;
            SceneDraw_SetResVisibleChecked(unitForUpdate->scene->resourceId, 1);
            FldFrameTask_SetFlags((*resourceForUpdate)->movementTask, 0x40000000);
            sampleIndex = 0;
            initialSampleValue = D_007615DC;
            for (; sampleIndex < 0x40; sampleIndex++) {
                fldUnitSampleAt(unitForUpdate, sampleIndex)->value0 = initialSampleValue;
                (&(unitForUpdate)->samples[sampleIndex])->value1 = initialSampleValue;
            }
        }
        {
            FieldUnitRecord *unitForUpdate =
                (FieldUnitRecord *)(D_007EF9B0 + (s32)(u32)partyIndex * 0x750);

            memset(unitForUpdate->state1D0, 0, sizeof(unitForUpdate->state1D0));
            memset(unitForUpdate->state410, 0, sizeof(unitForUpdate->state410));
        }
    }
    func_003e0f40((u8 *)formationMatrix);
}

#pragma pop
/* Loop-invariant motion keeps the slot stride and copy-loop scheduling. */
#pragma push
/* Raw word cursors copy the 0x150-byte placement image in word pairs. */
// FUN_00163990
/* measured: retail hoists the slot stride and copy-loop values, so loop-invariant motion is on. */
#pragma opt_loop_invariants on
u8 *FldUnit_CreateEncounterUnit(u32 encounter, u8 *placement, s32 variant)
{
    u8 message[0x100];
    u32 encounterId;
    s32 category;
    u32 modelVariant;
    s32 slotIndex;
    s32 unitIndex;
    s32 levelSum;
    u16 unitCount;
    u8 *candidate;
    u8 *slot;
    u8 *source;
    u8 *destination;
    s32 copyCount;
    u8 *group;

    slot = NULL;
    for (slotIndex = 0; slotIndex < 0xF; slotIndex++) {
        candidate = D_007E8C00 + (slotIndex * 0x750);
        if (*(s32 *)&((FieldUnitRecord *)candidate)->unitData == 0) {
            slot = candidate;
            break;
        }
    }
    modelVariant = 0;
    if (slot == NULL) {
        return NULL;
    }
    encounterId = encounter & 0xFFFF;
    *(u8 * *)&((FieldUnitRecord *)slot)->unitData = (u8 *)datUnitCreateEncounterGroup((u16)encounterId);
    *(s32 *)&((FieldUnitRecord *)slot)->modelData = (s32)(iGpffffb414 + (encounterId * 0x18));
    *(s16 *)&((FieldUnitRecord *)slot)->characterId = 0;
    category = (encounter >> 0x10) & 0xFFFF;
    switch (category) {
    case 1:
        *(s16 *)&((FieldUnitRecord *)slot)->encounterCategory = 1;
        break;
    case 2:
        *(s16 *)&((FieldUnitRecord *)slot)->encounterCategory = 2;
        break;
    case 4:
        *(s16 *)&((FieldUnitRecord *)slot)->encounterCategory = 3;
        break;
    default:
        sprintf((char *)message, (const char *)D_005F1510, encounter);
        kAssertFailAt(message, D_005F1500, 0x4B6);
        break;
    }
    switch (variant) {
    case 0:
        modelVariant = 0;
        break;
    case 1:
        modelVariant = 1;
        break;
    case 2:
        modelVariant = RpRandom() & 1;
        break;
    default:
        break;
    }
    if (modelVariant == 0) {
        *(s32 *)&((FieldUnitRecord *)slot)->model = (s32)mdlFindOrCreateModelObject(8U, 1U, 0);
        *(s8 *)&((FieldUnitRecord *)slot)->variant = 0;
    } else {
        *(s32 *)&((FieldUnitRecord *)slot)->model = (s32)mdlFindOrCreateModelObject(8U, 2U, 0);
        *(s8 *)&((FieldUnitRecord *)slot)->variant = 1;
    }
    destination = slot + 0x5C;
    copyCount = 0x2A;
    source = placement;
    do {
        s32 word0 = *(s32 *)source;
        s32 word1 = (s32)(((S8 *)source)->h[1]);
        source += 8;
        copyCount -= 1;
        *(s32 *)destination = word0;
        ((S8 *)destination)->h[1] = word1;
        destination += 8;
    } while (copyCount > 0);
    *(u8 * *)&((FieldUnitRecord *)slot)->placement = slot + 0x5C;
    ((FieldUnitRecord *)slot)->cellX = (s16)(s32)((600.0f + ((FieldUnitPlacement *)placement)->position.x) / 1200.0f);
    ((FieldUnitRecord *)slot)->cellZ = (s16)(s32)((600.0f + ((FieldUnitPlacement *)placement)->position.z) / 1200.0f);
    unitIndex = 0;
    levelSum = 0;
    unitCount = ((DatUnitGenusBase *)(MEMBER(u8 *, slot, FieldUnitRecord, unitData)))->count;
    for (; unitIndex < (s32)unitCount; unitIndex++) {
        /* measured: retail reloads unitData on every iteration; no plain spelling or pragma
         * reproduces it without volatile. */
        group = MEMBER(u8 *volatile, slot, FieldUnitRecord, unitData);
        levelSum += ((DatUnitGenusBase *)group)->unit[unitIndex].level;
    }
    ((FieldUnitRecord *)slot)->level = levelSum / (s32)unitCount;
    iGpffffb2e8 += 1;
    return slot;
}

#pragma pop
/* Create an encounter slot scene object and size its shadow and marker from the level difference. */
// FUN_00163C90
s32 FldUnit_SetupSlot(s32 slotIndex)
{
    FieldUnitRecord *unitRecord;
  u8 rotationAxis[12];
  f32 markerScale[3];
  u16 mode;
  s64 axisWords;
  f32 markerRadius;
  s32 levelDifference;
  u8 *unit;
  s64 axisPair;
  f32 axisZ;
  axisPair = (axisWords = *((s64 *) D_005F1520));
  axisZ = *((f32 *) D_005F1528);
  *((s64 *) rotationAxis) = axisPair;
  ((V3 *)rotationAxis)->z = axisZ;
  unit = D_007E8C00 + (slotIndex * 0x750);
  unitRecord = (FieldUnitRecord *)unit;
  if ((*(s32 *)&((FieldUnitRecord *)unit)->unitData) == 0)
  {
    return 1;
  }
  if ((*(s32 *)&((FieldUnitRecord *)unit)->scene) != 0)
  {
    return 1;
  }
  if ((*(s32 *)&((FieldUnitRecord *)unit)->model) == 0)
  {
    return 1;
  }
  if (mdlPrepareModel((u8 *)(*(s32 *)&((FieldUnitRecord *)unit)->model)) == 0)
  {
    return 0;
  }
  mode = 0;
  if ((((FieldUnitRecord *)unit)->variant) == 1)
  {
    mode = 3;
  }
  unitRecord->scene = (FieldUnitSceneResource *)(s32) MT_Scene_GetRes(MT_Scene_CreateModelCharShadowRes((slotIndex + 0x64) & 0xFFFF, mode, (u8 *)(unitRecord->model)) & 0xFFFF);
  mdlDispatchAnimIfPresent((u8 *)(unitRecord->model), 0, 0, 0x10, 1);
  mdlSetAttachedOwner((u8 *)(unitRecord->model), D_005DC920);
  levelDifference = (((FieldUnitRecord *)unit)->level) - FldEvent_AverageEntryValue();
  if (levelDifference < (-3))
  {
    ((FieldUnitRecord *)unit)->levelBand = 0;
  }
  else
    if (levelDifference < (-1))
  {
    ((FieldUnitRecord *)unit)->levelBand = 1;
  }
  else
    if (levelDifference < 3)
  {
    ((FieldUnitRecord *)unit)->levelBand = 2;
  }
  else
    if (levelDifference >= 3)
  {
    ((FieldUnitRecord *)unit)->levelBand = 3;
  }
  if ((unitRecord->variant) == 1)
  {
    FldShadow_SetRingParticles(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->effectTask, ((f32 *)D_005F1340)[((FieldUnitRecord *)unit)->levelBand]);
  }
  mdlScale((Model *)((void *)(unitRecord->model)), (const RwV3d *)((D_005F12E0 + ((unitRecord->variant) * 0x30)) + ((((FieldUnitRecord *)unit)->levelBand) * 0xC)), 2);
  RwMatrixUpdate((u8 *)mdlGetMatrix((void *)(unitRecord->model)));
  FldFrameTask_Rotate((u8 *)(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->movementTask), rotationAxis, ((FieldUnitPlacement *)(*(u8 * *)&((FieldUnitRecord *)unit)->placement))->yawDegrees);
  FldFrameTask_SetPosition(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->movementTask, ((u8 *)(unitRecord->placement)) + 0x140);
  SceneDraw_SetResVisibleChecked(*((u16 *) ((u8 *)(unitRecord->scene))), 1);
  FldFrameTask_SetFlags(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->movementTask, 0x40000000);
  FldFrameTask_SetHeight(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->movementTask, 35.0f);
  *(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->markerModel = (s32)mdlCloneModelObject((u8 *)(iGpffffb274));
  markerRadius = FldFrameTask_GetHeight(*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->movementTask);
  markerScale[2] = markerRadius;
  markerScale[1] = markerRadius;
  markerScale[0] = markerRadius;
  mdlScale((Model *)((*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->markerModel)), (const RwV3d *)(markerScale), 2);
  mdlAdvanceModelFromFlags((u8 *) (*(s32 *)&((FieldUnitSceneResource *)((u8 *)(unitRecord->scene)))->markerModel));
  ((FieldUnitRecord *)unit)->followerTask = FldAI_SpawnPatrol(0, unit, unitRecord->variant);
  ((FieldUnitRecord *)unit)->tintTask = FldUnit_SpawnTintTask((u8 *) 0, unit);
  return 1;
}

/* Poll all fifteen encounter slots; stop as soon as one model is not ready. */
// FUN_00163FC0
s32 FldUnit_AllSlotsReady(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        if (FldUnit_SetupSlot(i) == 0) {
            return 0;
        }
    }
    return 1;
}

/* Release unit data, scene resources, model ownership and controller tasks for one occupied slot.
 * measured: retail reads the model fields and clears the slot through raw pointers after the
 * teardown calls, so those accesses stay untyped. */
// FUN_00164020
void FldUnit_ReleaseSlot(u8 *unit)
{
    FieldUnitRecord *unitRecord = (FieldUnitRecord *)unit;
    s32 i;
    s32 unitData;
    u16 *sceneId;

    unitData = *(s32 *)&((FieldUnitRecord *)unit)->unitData;
    if (unitData != 0) {
        datUnitFree(unitData);
        sceneId = *(u16 * *)&((FieldUnitRecord *)unit)->scene;
        if (sceneId != NULL) {
            MT_Scene_DestroyRes(*sceneId);
        }
        if ((*(s32 *)&((FieldUnitRecord *)unit)->model != 0) &&
            ((((FieldUnitRecord *)unit)->characterId == 0) || (((FieldUnitRecord *)unit)->ownsModel == 1))) {
            for (i = 0; i < 5; i++) {
                ((FieldUnitModel *)(MEMBER(s32, unit, FieldUnitRecord, model)))->layers[i].flags |= 1;
            }
            KMisc_CreateDelayMdlFree(MEMBER(s32, unit, FieldUnitRecord, model), 0);
        }
        if (((FieldUnitRecord *)unit)->followerTask != 0) {
            kwlnTaskDestroyWithHierarchy(((FieldUnitRecord *)unit)->followerTask);
        }
        if (*(s32 *)&((FieldUnitRecord *)unit)->fileData != 0) {
            DAT_008873EC[0](((FieldUnitRecord *)unit)->fileData);
        }
        if (((FieldUnitRecord *)unit)->iconTask != 0) {
            kwlnTaskDestroyWithHierarchy(((FieldUnitRecord *)unit)->iconTask);
        }
        if (((FieldUnitRecord *)unit)->tintTask != 0) {
            kwlnTaskDestroyWithHierarchy(((FieldUnitRecord *)unit)->tintTask);
        }
        unitRecord->unitData = 0;
        MEMBER(s32, unit, FieldUnitRecord, model) = 0;
        unitRecord->scene = 0;
        MEMBER(s32, unit, FieldUnitRecord, followerTask) = 0;
        MEMBER(s32, unit, FieldUnitRecord, fileData) = 0;
        MEMBER(s32, unit, FieldUnitRecord, iconTask) = 0;
        MEMBER(s32, unit, FieldUnitRecord, tintTask) = 0;
        if (((FieldUnitRecord *)unit)->encounterCategory != 0) {
            iGpffffb2e8 -= 1;
        }
    }
}

/* Release the four party slots. */
// FUN_00164170
void FldUnit_ReleaseGroupSlots(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        FldUnit_ReleaseSlot(D_007EF9B0 + i * 0x750);
    }
}

/* Release all fifteen encounter slots. */
// FUN_001641D0
void FldUnit_ReleaseAllSlots(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        FldUnit_ReleaseSlot(D_007E8C00 + i * 0x750);
    }
}

/* Script records contain fixed 32-byte paths indexed by the 16-bit PC ID; model-cache records start
 * eight bytes beyond the biased cursor. */
// FUN_00164230
void FldUnit_SpawnAtEntry(u16 fieldId, u16 roomId, u16 entryId)
{
    u8 **modelSlot;

    {
        u8 *unit;

        unit = FldSlotFindFree();
        if (unit != NULL) {
            *(DatUnitPc * *)&((FieldUnitRecord *)unit)->unitData = datUnitCreatePc(1);
            *(u8 * *)&((FieldUnitRecord *)unit)->model = FldPartyModelGet(fieldId, roomId, 1);
            ((FieldUnitRecord *)unit)->characterId = 1;
            ((FieldUnitRecord *)unit)->ownsModel = 0;
            ((FieldUnitRecord *)unit)->level = datPersonaGetLevelByPcId(1) & 0xFF;
            ((FieldUnitRecord *)unit)->calculatedLevel = datCalcGetLevelById(1) & 0xFF;
            *(u8 * *)&((FieldUnitRecord *)unit)->iconTask = (u8 *)FldPlayerIconTaskCreate(NULL);
            ((FieldUnitRecord *)unit)->placementId = entryId;
        }
    }
    if (FldRoomIsListed(fieldId, roomId) == 1) {
        s32 i;
        u8 *cache;
        u8 *record;

        i = 0;
        while (i < 3) {
            cache = D_007F16F0 + (u32)i * 8;
            if (((FieldUnitModelCache *)(cache + 8))->model != NULL) {
                s32 j;

                j = 0;
                while (j < 5) {
                    record = ((FieldUnitModelCacheGroup *)cache)->members[0].model + (j * 3) * 4;
                    ((FieldUnitModel *)record)->layers[0].flags = ((FieldUnitModel *)record)->layers[0].flags | 1;
                    j += 1;
                }
                record = D_007F16F0 + i * 8;
                modelSlot = &((FieldUnitModelCache *)(record + 8))->model;
                mdlDestroyModelObject(((FieldUnitModelCache *)(record + 8))->model);
                *modelSlot = NULL;
                ((FieldUnitModelCache *)(record + 8))->fieldId = 0;
                ((FieldUnitModelCache *)(record + 8))->roomId = 0;
            }
            i += 1;
        }
    } else {
        u16 pcId;
        s16 selectedId;
        s32 i;
        s32 modelId;
        u8 *unit;
        u8 *cache;
        u8 *record;

        i = 0;
        while (i < 3) {
            selectedId = (s16)datGetPartyId(i);
            if (selectedId > 0) {
                unit = FldSlotFindFree();
                if (unit != NULL) {
                    pcId = (u16)selectedId;
                    *(DatUnitPc * *)&((FieldUnitRecord *)unit)->unitData = datUnitCreatePc(pcId);
                    modelId = pcId;
                    *(u8 * *)&((FieldUnitRecord *)unit)->model = FldPartyModelGet(fieldId, roomId, modelId);
                    ((FieldUnitRecord *)unit)->characterId = pcId;
                    ((FieldUnitRecord *)unit)->ownsModel = 0;
                    ((FieldUnitRecord *)unit)->level = datPersonaGetLevelByPcId(pcId) & 0xFF;
                    if (modelId == 1) {
                        ((FieldUnitRecord *)unit)->calculatedLevel = datCalcGetLevelById((s16)pcId) & 0xFF;
                        *(u8 * *)&((FieldUnitRecord *)unit)->iconTask = (u8 *)FldPlayerIconTaskCreate(NULL);
                    } else {
                        func_00440b68((const char *)D_00763008, D_005F1500, 0x1DD);
                        *(u8 * *)&((FieldUnitRecord *)unit)->file =
                            H_Cdvd_AcquireDirectory(((u8 (*)[32])D_005F13C0)[pcId], 0);
                    }
                    ((FieldUnitRecord *)unit)->placementId = entryId;
                }
            } else {
                cache = D_007F16F0 + (u32)i * 8;
                if (((FieldUnitModelCache *)(cache + 8))->model != NULL) {
                    s32 j;

                    j = 0;
                    while (j < 5) {
                        record = ((FieldUnitModelCacheGroup *)cache)->members[0].model + (j * 3) * 4;
                        ((FieldUnitModel *)record)->layers[0].flags = ((FieldUnitModel *)record)->layers[0].flags | 1;
                        j += 1;
                    }
                    record = D_007F16F0 + i * 8;
                    modelSlot = &((FieldUnitModelCache *)(record + 8))->model;
                    mdlDestroyModelObject(((FieldUnitModelCache *)(record + 8))->model);
                    *modelSlot = NULL;
                    ((FieldUnitModelCache *)(record + 8))->fieldId = 0;
                    ((FieldUnitModelCache *)(record + 8))->roomId = 0;
                }
            }
            i += 1;
        }
    }
}

/* Populate encounter placements up to the requested limit, using field-mode distance thresholds. */
// FUN_00164570
s32 FldUnit_SpawnEncounter(u32 limit, s32 refill)
{
    s32 cellX;
    s32 cellZ;
    f32 minimumDistance;
    s32 fieldId;
    s32 spawnCount;
    u32 encounter;
    u8 *gridPlacement;
    u8 *fieldState;
    u8 *placement;
    u8 *fieldStateForCheck;

    spawnCount = 0;
    if (D_00764344 == 1) {
        return 0;
    }
    fieldStateForCheck = iGpffff9db0;
    fieldId = *(s32 *)fieldStateForCheck;
    if ((fieldId >= 0x28) && (fieldId < 0x3C) && (((FieldUnitRoomKey *)fieldStateForCheck)->roomId != 0)) {
        return 0;
    }
    if (refill != 0) {
        while ((placement = FldUnit_FindNearestUnits(spawnCount, limit, (f32)0xBB8)) != NULL) {
            fieldState = iGpffff9db0;
            encounter = Encount_PickEncounter(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF), 2);
            if ((encounter & 0xFFFF) == 0xFFFF) {
                encounter = 1;
            }
            FldUnit_CreateEncounterUnit(encounter, placement, 2);
            spawnCount += 1;
        }
    } else {
        while ((placement = FldUnit_FindNearestUnits(spawnCount, limit, (f32)0x1770)) != NULL) {
            fieldState = iGpffff9db0;
            encounter = Encount_PickEncounter(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF), 2);
            if ((encounter & 0xFFFF) == 0xFFFF) {
                encounter = 1;
            }
            FldUnit_CreateEncounterUnit(encounter, placement, 1);
            spawnCount += 1;
        }
        minimumDistance = (f32)0xBB8;
        if (FldMap_IsCurrentInBandB() == 1) {
            minimumDistance = 100.0f;
        }
        while ((placement = FldUnit_FindNearestUnits(spawnCount, limit, minimumDistance)) != NULL) {
            fieldState = iGpffff9db0;
            encounter = Encount_PickEncounter(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF), 2);
            if ((encounter & 0xFFFF) == 0xFFFF) {
                encounter = 1;
            }
            FldUnit_CreateEncounterUnit(encounter, placement, 0);
            spawnCount += 1;
        }
        if ((datGetFlag(0x1410) == 0) && (datGetFlag(0x1411) == 0)) {
            FldEvent_BeginGridScan();
            while (FldEvent_NextGridCell(&cellX, &cellZ) == 1) {
                gridPlacement = FldEvent_GetGridCellEntry(cellX, cellZ);
                if (gridPlacement != NULL) {
                    fieldState = iGpffff9db0;
                    encounter = Encount_PickEncounter(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF), 2);
                    if ((encounter & 0xFFFF) == 0xFFFF) {
                        encounter = 1;
                    }
                    FldUnit_CreateEncounterUnit(encounter, gridPlacement, 0);
                }
            }
        }
    }
    return spawnCount;
}

#pragma push
/* measured: retail output for FldUnit_FindNearestUnits needs this pragma scope. Both field modes
 * use real position and difference vectors; the selection temporary holds a saved or current node,
 * depending on the mode. */
/* Search the field unit placements for a spawn candidate that is away from the party and other
 * units, and return the best one found. */
// FUN_00164880
/* measured: retail block lifetimes need common-subexpression and propagation optimizations disabled
 * for this function. */
#pragma opt_common_subs off
#pragma opt_propagation off
u8 *FldUnit_FindNearestUnits(s32 unused, u32 limit, f32 minimumDistance)
{
    V3 primaryPosition;
    V3 primaryDelta;
    V3 secondaryPosition;
    V3 secondaryDelta;
    f32 primaryDistance;
    f32 secondaryDistance;
    f32 savedPrimaryDistance;
    f32 savedSecondaryDistance;
    f32 bestDistance;
    f32 positionY;
    f32 positionZ;
    s32 primaryUsed;
    s32 ready;
    s32 secondaryUsed;
    u32 secondaryIndex;
    u8 *savedSecondaryNode;
    u8 *selection;
    u8 *primaryEntry;
    u8 *modelX;
    u8 *source;
    u8 *modelOrEntry;
    u8 *secondarySource;
    u8 *primaryRow;
    u8 *primarySpawned;
    u8 *secondaryRow;
    u8 *secondarySpawned;
    u8 *candidate;
    u32 index;
    u8 *best;

    MT_Scene_GetResListHead(0xF);
    best = NULL;
    FldStepIndex();
    bestDistance = 1.1754944e-38f;
    if (FldMap_IsCurrentInBandA() == 1) {
        if (FldUnit_GetActiveCount() < (s32)limit) {
            candidate = MT_Scene_GetResListHead(0xF);
            while (candidate != NULL) {
                primaryPosition = *(V3 *)&((FieldUnitPlacement *)candidate)->position.x;
                index = 0;
                positionY = primaryPosition.y;
                positionZ = primaryPosition.z;
                goto primary_party_test;
primary_party_body:
                primaryUsed = 0;
                primaryRow = D_007EF9B0 + index * 0x750;
                if (*(s32 *)&((FieldUnitRecord *)primaryRow)->unitData != 0 && *(s32 *)&((FieldUnitRecord *)primaryRow)->scene != 0) {
                    primaryUsed = 1;
                }
                ready = primaryUsed != 0;
                if (ready) {
                    primaryEntry = D_007EF9B0 + index * 0x750;
                    {
                        u8 *modelSlot = primaryEntry + 0x50;

                        modelX = (u8 *)mdlGetMatrix(*(void * *)&((FieldUnitRecord *)primaryEntry)->model);
                        primaryDelta.x = primaryPosition.x - ((FieldUnitMatrix *)modelX)->position.x;
                        source = (u8 *)mdlGetMatrix(*(void **)modelSlot);
                        primaryDelta.y = positionY - ((FieldUnitMatrix *)source)->position.y;
                        modelOrEntry = (u8 *)mdlGetMatrix(*(void **)modelSlot);
                        primaryDelta.z = positionZ - ((FieldUnitMatrix *)modelOrEntry)->position.z;
                    }
                    if (RwV3dLength(&primaryDelta.x) < 3000.0f) {
                        goto primary_party_checked;
                    }
                }
                index++;
primary_party_test:
                if (index < 4U) {
                    goto primary_party_body;
                }
primary_party_checked:
                if (index < 4U) {
                    candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
                    continue;
                }
                if (FldUnit_GetActiveCount() == 0) {
                    return fldChooseRandomSpawn(&primaryDelta);
                }
                if (FldEvent_IsCellOccupied(candidate + 0x140) == 1) {
                    candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
                    continue;
                }
                savedPrimaryDistance = bestDistance;
                selection = best;
                index = 0;
                goto primary_neighbor_test;
primary_neighbor_body:
                primarySpawned = D_007E8C00 + index * 0x750;
                if (*(s32 *)&((FieldUnitRecord *)primarySpawned)->unitData != 0) {
                    source = *(u8 * *)&((FieldUnitRecord *)primarySpawned)->placement;
                    primaryDelta.x = primaryPosition.x - ((FieldUnitPlacement *)source)->position.x;
                    primaryDelta.y = positionY - ((FieldUnitPlacement *)source)->position.y;
                    primaryDelta.z = positionZ - ((FieldUnitPlacement *)source)->position.z;
                    primaryDistance = RwV3dLength(&primaryDelta.x);
                    if (!(primaryDistance <= bestDistance)) {
                        bestDistance = primaryDistance;
                        best = candidate;
                    }
                    if (primaryDistance < minimumDistance) {
                        bestDistance = savedPrimaryDistance;
                        best = selection;
                        goto next_primary_node;
                    }
                }
                index++;
primary_neighbor_test:
                if (index < 0xFU) {
                    goto primary_neighbor_body;
                }
next_primary_node:
                candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
            }
            goto done;
        }
    } else if (FldMap_IsCurrentInBandB() == 1 && FldUnit_GetActiveCount() < (s32)limit) {
        selection = MT_Scene_GetResListHead(0xF);
        goto secondary_node_test;
secondary_node_body:
        secondaryPosition = *(V3 *)&((FieldUnitPlacement *)selection)->position.x;
        index = 0;
        positionY = secondaryPosition.y;
        positionZ = secondaryPosition.z;
        goto secondary_party_test;
secondary_party_body:
        secondaryUsed = 0;
        secondaryRow = D_007EF9B0 + index * 0x750;
        if (*(s32 *)&((FieldUnitRecord *)secondaryRow)->unitData != 0 && *(s32 *)&((FieldUnitRecord *)secondaryRow)->scene != 0) {
            secondaryUsed = 1;
        }
        ready = secondaryUsed != 0;
        if (ready) {
            modelOrEntry = D_007EF9B0 + index * 0x750;
            {
                u8 *modelSlot = modelOrEntry + 0x50;

                secondarySource = (u8 *)mdlGetMatrix(*(void * *)&((FieldUnitRecord *)modelOrEntry)->model);
                secondaryDelta.x = secondaryPosition.x - ((FieldUnitMatrix *)secondarySource)->position.x;
                source = (u8 *)mdlGetMatrix(*(void **)modelSlot);
                secondaryDelta.y = positionY - ((FieldUnitMatrix *)source)->position.y;
                modelX = (u8 *)mdlGetMatrix(*(void **)modelSlot);
                secondaryDelta.z = positionZ - ((FieldUnitMatrix *)modelX)->position.z;
            }
            if (RwV3dLength(&secondaryDelta.x) < 3000.0f) {
                goto secondary_party_checked;
            }
        }
        index++;
secondary_party_test:
        if (index < 4U) {
            goto secondary_party_body;
        }
secondary_party_checked:
        if (index < 4U) {
            selection = *(u8 * *)&((FieldUnitPlacement *)selection)->next;
            goto secondary_node_test;
        }
        if (FldUnit_GetActiveCount() == 0) {
            return selection;
        }
        savedSecondaryDistance = bestDistance;
        savedSecondaryNode = best;
        secondaryIndex = 0;
        goto secondary_neighbor_test;
secondary_neighbor_body:
        secondarySpawned = D_007E8C00 + secondaryIndex * 0x750;
        if (*(s32 *)&((FieldUnitRecord *)secondarySpawned)->unitData != 0) {
            secondarySource = *(u8 * *)&((FieldUnitRecord *)secondarySpawned)->placement;
            secondaryDelta.x = secondaryPosition.x - ((FieldUnitPlacement *)secondarySource)->position.x;
            secondaryDelta.y = positionY - ((FieldUnitPlacement *)secondarySource)->position.y;
            secondaryDelta.z = positionZ - ((FieldUnitPlacement *)secondarySource)->position.z;
            secondaryDistance = RwV3dLength(&secondaryDelta.x);
            if (!(secondaryDistance <= bestDistance)) {
                bestDistance = secondaryDistance;
                best = selection;
            }
            if (secondaryDistance < minimumDistance) {
                bestDistance = savedSecondaryDistance;
                best = savedSecondaryNode;
                goto next_secondary_node;
            }
        }
        secondaryIndex++;
secondary_neighbor_test:
        if (secondaryIndex < 0xFU) {
            goto secondary_neighbor_body;
        }
next_secondary_node:
        selection = *(u8 * *)&((FieldUnitPlacement *)selection)->next;
secondary_node_test:
        if (selection != NULL) {
            goto secondary_node_body;
        }
    }
done:
    return best;
}

// FUN_00164F40
s32 FldUnit_GetActiveCount(void)
{
    return iGpffffb2e8;
}

/* Recreate party scene slots, optionally including the leader. */
// FUN_00164F50
void FldUnit_UpdateSlots(s32 includeLeader)
{
    s32 i = !includeLeader;
    for (; i < 4; i++) {
        FldUnit_UpdateSlot(i);
    }
}

/* Reattach a party slot from its saved matrix and recreate its marker and follower controller. */
// FUN_00164FA0
/* measured: retail block lifetimes need the scoped optimizer settings for this function. */
void FldUnit_UpdateSlot(s32 slotIndex)
{
    f32 markerScale[3];
    f32 markerRadius;
    s32 *unitDataSlot;
    s32 *link;
    s32 stride;
    s32 unitOffset;
    s32 followerTask;
    s32 secondWord;
    s32 firstWord;
    u16 actorId;
    u8 **modelSlot;
    u8 **sceneSlot;
    u8 **markerSceneSlot;
    u8 *unit;
    u8 *sceneResource;
    u8 *matrixDestination;
    u8 *matrixSource;
    s32 i;

    unitOffset = slotIndex * 0x750;
    unitDataSlot = (s32 *)(D_007EF9F8 + unitOffset);
    if (*unitDataSlot != 0) {
        modelSlot = (u8 **)(D_007EFA00 + unitOffset);
        actorId = MT_Scene_CreateModelCharShadowRes(slotIndex & 0xFFFF, 3, *modelSlot) & 0xFFFF;
        sceneSlot = (u8 **)(D_007EFA04 + unitOffset);
        sceneResource = (u8 *)MT_Scene_GetRes(actorId);
        *sceneSlot = sceneResource;
        FldShadow_SetRingParticles(*(s32 *)&((FieldUnitSceneResource *)sceneResource)->effectTask, 60.0f);
        unit = D_007EF9B0 + unitOffset;
        matrixDestination = (u8 *)mdlGetMatrix(*modelSlot);
        i = 8;
        matrixSource = unit;
        do {
            firstWord = *(s32 *)matrixSource;
            secondWord = (s32)(((S8 *)matrixSource)->h[1]);
            matrixSource += 8;
            i -= 1;
            *(s32 *)matrixDestination = firstWord;
            ((S8 *)matrixDestination)->h[1] = secondWord;
            matrixDestination += 8;
        } while (i > 0);
        RwMatrixUpdate((u8 *)mdlGetMatrix(*modelSlot));
        SceneDraw_SetResVisibleChecked(*(u16 *)*sceneSlot, 1);
        FldFrameTask_SetFlags(*(s32 *)&((FieldUnitSceneResource *)*sceneSlot)->movementTask, 0x40000000);
        FldFrameTask_UpdateTile(*(s32 *)&((FieldUnitSceneResource *)*sceneSlot)->movementTask);
        if (slotIndex == 0) {
            FldFrameTask_SetHeight(*(s32 *)&((FieldUnitSceneResource *)*sceneSlot)->movementTask, 60.0f);
        } else {
            FldFrameTask_SetHeight(*(s32 *)&((FieldUnitSceneResource *)*sceneSlot)->movementTask, 35.0f);
        }
        markerSceneSlot = (u8 **)(D_007EFA04 + (slotIndex * 0x750));
        *(u8 * *)&((FieldUnitSceneResource *)*markerSceneSlot)->markerModel = (u8 *)mdlCloneModelObject((u8 *)(iGpffffb274));
        markerRadius = FldFrameTask_GetHeight(*(s32 *)&((FieldUnitSceneResource *)*markerSceneSlot)->movementTask);
        markerScale[0] = markerScale[1] = markerScale[2] = markerRadius;
        mdlScale((Model *)(*(u8 * *)&((FieldUnitSceneResource *)*markerSceneSlot)->markerModel), (const RwV3d *)(&markerScale[0]), 2);
        mdlAdvanceModelFromFlags(*(u8 * *)&((FieldUnitSceneResource *)*markerSceneSlot)->markerModel);
        if (datUnitGroupIsDefeated((DatUnitGenusBase *)*unitDataSlot) == 0) {
            mdlDispatchAnimIfPresent(*modelSlot, 0, (s16)FldCharacterAnimSelect(((u16 *)D_007F00D8)[(slotIndex) * (0x750 / sizeof(u16))]), 0, 1);
        }
        if (slotIndex != 0) {
            stride = 0x750;
            link = (s32 *)(D_007EFB60 + slotIndex * stride);
            followerTask = FldAI_SpawnChaser(0, unit, D_007EF9B0 + ((slotIndex - 1) * stride));
            *link = followerTask;
            FldAI_ChaserEnable(followerTask);
        }
        if (slotIndex == 0) {
            ((FieldUnitIconTask *)((u8 *)D_007EFB64 + unitOffset))->task = FldPlayerIconTaskCreate(0);
        }
    }
}

/* Request each occupied encounter slot model using its stored variant. */
// FUN_00165270
void FldUnit_StartSlotAnims(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)&((FieldUnitRecord *)p)->unitData != 0) {
            *(s32 *)&((FieldUnitRecord *)p)->model = (s32)mdlFindOrCreateModelObject(8, (u16)(((FieldUnitRecord *)p)->variant + 1), 0);
        }
    }
}

/* Poll occupied encounter models and report when all have loaded. */
// FUN_00165300
s32 FldUnit_AllSlotAnimsDone(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)&((FieldUnitRecord *)p)->unitData != 0 && mdlPrepareModel((u8 *)(*(s32 *)&((FieldUnitRecord *)p)->model)) == 0) {
            return 0;
        }
    }
    return 1;
}

/* Recreate encounter scene models while preserving each slot matrix and tint controller. */
/* Remaining raw accesses retain paired-word matrix transfers, the radius table lookup and the native resource-ID halfword load. */
// FUN_00165380
/* measured: with common-subexpression elimination off, the slot address is recomputed at each
 * assignment; with propagation off, the slot pointer bump stays out of the store offset. */
void FldUnit_UpdateSlotModels(void)
{
    s32 i;
    u8 *slot;
    u8 *variantSlot;
    u8 *modelSlot;
    u8 *sceneSlot;
    u8 *tintTaskSlot;
    u8 *unitForTint;
    u16 mode;
    u8 *matrixSource;
    s32 copyCount;
    u8 *matrixDestination;
    s32 firstWordOrResourceId;
    s32 secondWordOrResourceId;
    f32 markerScale[3];
    f32 markerRadius;

    for (i = 0; i < 0xF; i++) {
        slot = D_007E8C00 + i * 0x750;
        if (*(s32 *)&((FieldUnitRecord *)slot)->unitData != 0) {
            mode = 0;
            ((FieldUnitRecord *)slot)->flags &= ~2;
            variantSlot = slot + 0x1CA;
            if (*variantSlot == 1) {
                mode = 3;
            }
            slot = D_007E8C00 + i * 0x750;
            modelSlot = slot + 0x50;
            firstWordOrResourceId = MT_Scene_CreateModelCharShadowRes((i + 0x64) & 0xFFFF, mode, *(u8 * *)&((FieldUnitRecord *)slot)->model);
            secondWordOrResourceId = firstWordOrResourceId & 0xFFFF;
            slot += 0x54;
            *(s32 *)slot = (s32)MT_Scene_GetRes(secondWordOrResourceId);
            mdlSetAttachedOwner(*(u8 **)modelSlot, D_005DC920);
            if (*variantSlot == 1) {
                unitForTint = D_007E8C00 + i * 0x750;
                FldShadow_SetRingParticles(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)slot)->effectTask, ((f32 *)D_005F1340)[((FieldUnitRecord *)unitForTint)->levelBand]);
            }
            slot = D_007E8C00 + i * 0x750;
            variantSlot = slot + 0x1CA;
            modelSlot = slot + 0x50;
            mdlScale((Model *)(*(void **)modelSlot), (const RwV3d *)(D_005F12E0 + *variantSlot * 0x30 + ((FieldUnitRecord *)slot)->levelBand * 0xC), 2);
            matrixDestination = (u8 *)mdlGetMatrix(*(void **)modelSlot);
            copyCount = 8;
            matrixSource = slot;
            do {
                firstWordOrResourceId = *(s32 *)matrixSource;
                secondWordOrResourceId = (s32)(((S8 *)matrixSource)->h[1]);
                matrixSource += 8;
                copyCount -= 1;
                *(s32 *)matrixDestination = firstWordOrResourceId;
                ((S8 *)matrixDestination)->h[1] = secondWordOrResourceId;
                matrixDestination += 8;
            } while (copyCount > 0);
            RwMatrixUpdate((u8 *)mdlGetMatrix(*(void **)modelSlot));
            sceneSlot = slot + 0x54;
            SceneDraw_SetResVisibleChecked(((FieldUnitSceneResource *)*(u8 **)sceneSlot)->resourceId, 1);
            FldFrameTask_SetFlags(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->movementTask, 0x40000000);
            FldFrameTask_UpdateTile(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->movementTask);
            FldFrameTask_SetHeight(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->movementTask, 35.0f);
            *(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->markerModel = (s32)mdlCloneModelObject((u8 *)(iGpffffb274));
            markerRadius = FldFrameTask_GetHeight(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->movementTask);
            markerScale[2] = markerRadius;
            markerScale[1] = markerRadius;
            markerScale[0] = markerRadius;
            mdlScale((Model *)(*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->markerModel), (const RwV3d *)(markerScale), 2);
            mdlAdvanceModelFromFlags((u8 *)*(s32 *)&((FieldUnitSceneResource *)*(u8 **)sceneSlot)->markerModel);
            ((FieldUnitRecord *)slot)->followerTask = FldAI_SpawnPatrol(0, slot, *variantSlot);
            tintTaskSlot = slot + 0x1B8;
            if (*(s32 *)tintTaskSlot == 0) {
                *(s32 *)tintTaskSlot = FldUnit_SpawnTintTask((u8 *)0, D_007E8C00 + i * 0x750);
            }
        }
    }
}
#pragma pop

/* Save the current model matrix before detaching scene resources and optional model ownership; the
 * matrix is copied word by word through paired source/destination cursors, as retail does. */
// FUN_00165670
void FldUnit_SetSlotModel(u8 *unit, s32 destroyModel)
{
    u8 *slot = unit;
    u8 *matrix;
    u8 *matrixSource;
    u8 *matrixDestination;
    s32 copyCount;
    s32 ready;
    s32 i;
    ready = *(u32 *)&((FieldUnitRecord *)slot)->unitData != 0 && *(u32 *)&((FieldUnitRecord *)slot)->scene != 0;
    if (ready != 0) {
        matrix = (u8 *)mdlGetMatrix(*(void * *)&((FieldUnitRecord *)slot)->model);
        matrixSource = matrix;
        copyCount = 8;
        matrixDestination = slot;
        do {
            u32 w0 = *(u32 *)matrixSource;
            u32 w1 = ((S8 *)matrixSource)->h[1];
            matrixSource += 8;
            copyCount--;
            *(u32 *)matrixDestination = w0;
            ((S8 *)matrixDestination)->h[1] = w1;
            matrixDestination += 8;
        } while (copyCount > 0);
        MT_Scene_DestroyRes(((FieldUnitSceneResource *)*(u32 *)&((FieldUnitRecord *)slot)->scene)->resourceId);
        MEMBER(u32, slot, FieldUnitRecord, scene) = 0;
        if (MEMBER(u32, slot, FieldUnitRecord, model) != 0) {
            mdlClearAlphaBlend(MEMBER(u32, slot, FieldUnitRecord, model));
            mdlSetColor(MEMBER(u32, slot, FieldUnitRecord, model), D_00763010);
        }
        if (MEMBER(u32, slot, FieldUnitRecord, model) != 0 && destroyModel == 1) {
            for (i = 0; i < 5; i++) {
                ((FieldUnitModel *)(*(u32 *)&((FieldUnitRecord *)slot)->model))->layers[i].flags |= 1;
            }
            mdlDestroyModelObject(MEMBER(u8 *, slot, FieldUnitRecord, model));
            MEMBER(u32, slot, FieldUnitRecord, model) = 0;
        }
        if (*(u32 *)&((FieldUnitRecord *)slot)->followerTask != 0) {
            kwlnTaskDestroyWithHierarchy(*(u32 *)&((FieldUnitRecord *)slot)->followerTask);
            MEMBER(u32, slot, FieldUnitRecord, followerTask) = 0;
        }
        if (*(u32 *)&((FieldUnitRecord *)slot)->tintTask != 0) {
            kwlnTaskDestroyWithHierarchy(*(u32 *)&((FieldUnitRecord *)slot)->tintTask);
            MEMBER(u32, slot, FieldUnitRecord, tintTask) = 0;
        }
        if (*(u32 *)&((FieldUnitRecord *)slot)->iconTask != 0) {
            kwlnTaskDestroyWithHierarchy(*(u32 *)&((FieldUnitRecord *)slot)->iconTask);
            MEMBER(u32, slot, FieldUnitRecord, iconTask) = 0;
        }
    }
}

/* Detach party scene models, optionally including the leader. */
// FUN_001657E0
void FldUnit_SetPartySlotModel(s32 includeLeader)
{
    s32 i = !includeLeader;
    for (; i < 4; i++) {
        FldUnit_SetSlotModel(D_007EF9B0 + i * 0x750, 0);
    }
}

/* Detach every encounter scene model, optionally destroying the underlying models. */
// FUN_00165840
void FldUnit_SetFieldSlotModel(s32 destroyModels)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        FldUnit_SetSlotModel(D_007E8C00 + i * 0x750, destroyModels);
    }
}

/* Keep the saved halfword and allocator word in the same assignment chain. */
/* Request up to two NPC model/script pairs selected by field step and calendar parity. */
// FUN_001658B0
void FldUnit_RequestSceneResource(void)
{
    s32 i;
    s32 j;
    u16 code;
    s32 value;
    s32 count;

    count = 0;
    j = 0;
    memset(D_007E8BE0, 0, 0x20);
    D_007E8BE8[0] = -1;
    D_007E8BF8[0] = -1;
    if (FldMap_IsCurrentInBandA() == 0) {
        goto done;
    }
    if (FldMap_IsCurrentInBandA() != 0) {
        goto loop;
    }
done:
    return;
loop:
    for (i = 0; i < 8; i++) {
        value = FldStepIndex();
        if (value == datGetScriptValue(i + 1)) {
            s32 state;
            s32 parity;
            s32 base;
            base = 10;
            state = calGetDayWindowFlags((s16)datGetDateIndex());
            parity = state & 1;
            if (state < 0 && parity != 0) {
                parity -= 2;
            }
            if (parity != 0) {
                base = 20;
            }
            if (i < 6) {
                value = i + 2;
                code = (u16)((value << 8) | base);
            } else if (i == 6) {
                code = 0x80A;
                value = i + 2;
            } else {
                code = 0x120A;
                value = 9;
            }
            if (count >= 2) {
                kAssertFail(D_005F1500, 0x916);
            }
            if (D_007643C8[count] != 0) {
                kAssertFail(D_005F1500, 0x917);
            }
            D_007643C8[count] = (s32)mdlFindOrCreateModelObject(9, code, 0);
            func_00440b68((const char *)D_00763008, D_005F1500, 0x91C);
            D_007643C0[count] =
                (s32)H_Cdvd_AcquireDirectory(D_005F13C0 + value * 0x20, 0);
            ((FldPairSelection *)D_007E8BE0)[j].active = 1;
            ((FldPairSelection *)D_007E8BE0)[j].modelType = 9;
            ((FldPairSelection *)D_007E8BE0)[j].modelId = code;
            ((FldPairSelection *)D_007E8BE0)[j].actorId = value;
            j++;
            count++;
        }
    }
}

/* Reissue model and script loads for active NPC requests. */
// FUN_00165B00
void FldUnit_RequestUnitResource(void)
{
    s32 i;
    s32 j = 0;
    for (i = 0; i < 2; i++) {
        u8 *p = D_007E8BE0 + i * 16;
        if (*(s32 *)p != 0) {
            D_007643C8[j] = (s32)mdlFindOrCreateModelObject(((FldPairSelection *)p)->modelType, ((FldPairSelection *)p)->modelId, 0);
            func_00440b68((const char *)D_00763008, D_005F1500, 0x939);
            D_007643C0[j] = (s32)H_Cdvd_AcquireDirectory(D_005F13C0 + (((FldPairSelection *)p)->actorId << 5), 0);
            j++;
        }
    }
}

/* Install the selected NPC placement pair with copied scripts, markers and control tasks. The
 * script-handle array is addressed by byte-offset slots. */
// FUN_00165BE0
#pragma push
/* measured: retail hoists loop-invariant loads out of the resource install loops; only invariant
 * motion is needed here. */
#pragma opt_loop_invariants on
s32 FldUnit_InstallResources(void)
{
    s32 *fileRequestSlot;
    ResrcRecord *sceneInstance;
    FieldUnitNpcResource *npcResource;
    u8* instance;
    s32 pair;
    u8* node;
    s32 handleOffset;
    u8* modelSlot;
    s32 resourceIndex;
    s32 nodeCount;
    s32* selection;
    s32 modelHandle;
    s32 fileHandle;
    u16 resourceId;
    void* allocation;
    RwV3d scale;

    if (FldMap_IsCurrentInBandA() == 0 || FldMap_IsCurrentInBandA() == 0)
    {
        return 1;
    }
    for (resourceIndex = 0; resourceIndex < 2; resourceIndex++)
    {
        modelHandle = D_007643C8[resourceIndex];
        if (modelHandle != 0 && mdlPrepareModel((u8 *)(modelHandle)) == 0)
        {
            return 0;
        }
        fileHandle = D_007643C0[resourceIndex];
        if (fileHandle != 0 && H_Cdvd_IsFileLoaded((HCdvd *)(fileHandle)) == 0)
        {
            return 0;
        }
    }
    {
        u8* cursor = MT_Scene_GetResListHead(0x11);
        nodeCount = 0;
        while (cursor != NULL)
        {
            nodeCount++;
            cursor = (u8 *)(((FieldUnitPlacement *)cursor)->next);
        }
    }
    if (nodeCount == 0)
    {
        return 1;
    }
    if (nodeCount == 0)
    {
        kAssertFail(D_005F1500, 0x965);
    }
    if (nodeCount % 2 != 0)
    {
        kAssertFail(D_005F1500, 0x966);
    }
    pair = (s32)(RpRandom() % (u32)(nodeCount >> 1));
    {
        s32 index;
        u8* records;

        index = 0;
        records = D_007E8BE0;
        for (; index < 2; index++)
        {
            FldPairSelection* record = (FldPairSelection*)(records + index * 16);
            if (record->active != 1)
            {
                continue;
            }
            selection = &record->nodeIndex;
            if (*selection >= 0)
            {
                continue;
            }
            *selection = pair + index;
        }
    }
    if (D_007E8BE8[0] >= 0)
    {
        pair = D_007E8BE8[0];
    }
    node = MT_Scene_GetResListHead(0x11);
    {
        s32 steps;
        s32 walked;

        walked = 0;
        steps = (s32)((u32)pair * 2U);
        while (walked < steps)
        {
            walked++;
            node = *(u8* *)&((FieldUnitPlacement *)node)->next;
        }
    }
    for (pair = 0; pair < 2; pair++)
    {
        handleOffset = pair * 4;
        modelSlot = (u8*)D_007643C8 + handleOffset;
        modelHandle = *(s32*)modelSlot;
        if (modelHandle == 0)
        {
            continue;
        }
        resourceId = MT_Scene_CreateModelNpcShadowRes((u16)(0x3FF - pair), 3, modelHandle);
        SceneDraw_SetResVisibleChecked(resourceId, 1);
        instance = (u8*)MT_Scene_GetRes(resourceId);
        sceneInstance = (ResrcRecord *)instance;
        npcResource = (FieldUnitNpcResource *)instance;
        ((FieldUnitNpcResource *)instance)->unk234 = 3;
        {
            u8* loaded;
            fileRequestSlot = (s32 *)((u8 *)D_007643C0 + handleOffset);
            loaded = (u8*)*fileRequestSlot;
            if (loaded != NULL)
            {
                u8* fileSlot;
                fileSlot = (u8*)&D_007643C0[(u32)pair];
                ((FieldUnitNpcResource *)instance)->fileSize = ((HCdvd *)loaded)->fileSize;
                chkmemAllocSiteTag(D_005F1500, 0x990);
                allocation = DAT_008873F4[0](1, npcResource->fileSize, 0x40000);
                *(void* *)&((ResrcRecord *)instance)->handle288 = allocation;
                {
                    u8* file = (u8*)*(s32*)fileSlot;
                    memcpy(allocation, (const void *)(((HCdvd *)file)->fileMemory), npcResource->fileSize);
                }
                H_Cdvd_Destroy((HCdvd *)(*(s32*)fileSlot));
                *(s32*)fileSlot = 0;
            }
        }
        {
            s32 model;
            model = (s32)mdlCloneModelObject((u8 *)(iGpffffb274));
            *(s32 *)&((ResrcRecord *)instance)->handle22C = model;
            scale.x = scale.y = scale.z = 30.0f;
            mdlScale((Model *)(*(s32 *)&((ResrcRecord *)instance)->handle22C), &scale, 2);
            mdlAdvanceModelFromFlags((u8*)(sceneInstance->handle22C));
            mdlRotateMatrix(((ResrcRecord *)instance)->modelHandle164, D_00756510, ((FieldUnitPlacement *)node)->yawDegrees, 2);
            mdlTranslateMatrix(sceneInstance->modelHandle164, (void*)(node + 0x140), 2);
            ((ResrcRecord *)instance)->handle294 = FldNpcControlTaskCreate(*(s32 *)&((ResrcRecord *)instance)->handle228, (s32)(instance));
            node = *(u8* *)&((FieldUnitPlacement *)node)->next;
            *(s32*)modelSlot = 0;
        }
    }
    return 1;
}

#pragma pop
/* Create the placed field model and its marker, propagating model and effect tint colors. The +4
 * color byte reuses the colorOrEffect loop temporary because retail computes it before the +7 byte.
 * Scene, model and placement reads stay as raw byte-pointer accesses across callbacks. */
// FUN_00165FB0
void FldUnit_ApplySlotTint(u8 *entry, u8 *placement, s32 resourceId)
{
    s32 *modelSlot;
    FieldUnitPlacement *spawnPlacement = (FieldUnitPlacement *)placement;
    FieldUnitObject *fieldObject = (FieldUnitObject *)entry;
    s32 cellX;
    s32 cellZ;
    s32 variant;
    s32 scaleOffset;
    s32 colorOrEffect;
    u8 *sceneResource;
    u8 *markerModel;
    u8 *modelForFlags;
    u8 *modelForEffects;
    u8 *attachedMarker;
    u8 *modelColor;
    u8 *effectNode;
    u8 color3;
    u8 color1;
    u8 color2;
    u8 color0;

    if (entry != NULL) {
        variant = (s32)(((((FieldUnitObject *)entry)->encounter + 7)[0] & 1) != 0);
        modelSlot = (s32 *)fldStepGetModelSlot();
        ((FieldUnitObject *)entry)->resourceId = (u16)MT_Scene_CreateModelFldRes(resourceId & 0xFFFF, (s32)mdlCloneModelObject((u8 *)(*modelSlot)));
        sceneResource = (u8 *)MT_Scene_GetRes(fieldObject->resourceId);
        mdlSetAttachedOwner(*(u8 * *)&((ResrcRecord *)sceneResource)->slotHandle[1], D_005DC920);
        scaleOffset = variant * 0xC;
        mdlScale((Model *)(MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1])), (const RwV3d *)(D_005F1530 + scaleOffset), 2);
        mdlRotateMatrix(MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), D_00756510, ((FieldUnitPlacement *)placement)->yawDegrees, 2);
        mdlTranslateMatrix((RwMatrix *)MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), (const RwV3d *)(placement + 0x140), 2);
        if (((FieldUnitObject *)entry)->unk08 != 0) {
            mdlDispatchAnimIfPresent(MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), 0, 2, 0, 0);
        } else if (variant == 1) {
            mdlDispatchAnimIfPresent(MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), 0, 3, 0, 0);
        }
        modelForFlags = MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]);
        ((FieldUnitModel *)modelForFlags)->flags |= 0x80;
        modelForEffects = MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]);
        effectNode = (u8 *)(((FieldUnitEffectNode *)((FieldUnitModel *)modelForEffects)->effectList)->first);
        modelColor = ((FieldUnitModel *)modelForEffects)->effectColor;
        colorOrEffect = iGpffff9f28;
        color1 = iGpffff9f29;
        color2 = iGpffff9f2a;
        color0 = iGpffff9f2b;
        modelColor[4] = colorOrEffect;
        modelColor[5] = color1;
        modelColor[6] = color2;
        modelColor[7] = color0;
        while (effectNode != NULL) {
            colorOrEffect = *(s32 *)&((FieldUnitEffectNode *)effectNode)->effect;
            if (colorOrEffect != 0) {
                mdlEffectSetPackedColor((u8 *)colorOrEffect, (u8 *)&iGpffff9f28);
            }
            effectNode = *(u8 * *)&((FieldUnitEffectNode *)effectNode)->next;
        }
        if (variant == 1) {
            mdlSetColor((s32)MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), (u8 *)&iGpffff9f24);
        } else {
            mdlSetColor((s32)MEMBER(u8 *, sceneResource, ResrcRecord, slotHandle[1]), D_005F1570 + ((FldStepIndex() / 20U) * 4));
        }
        markerModel = (u8 *)mdlCloneModelObject((u8 *)(D_00764364));
        *(u8 * *)&((ResrcRecord *)sceneResource)->handle16C = markerModel;
        mdlRotateMatrix(markerModel, D_00756510, spawnPlacement->yawDegrees, 2);
        mdlScale((Model *)(MEMBER(u8 *, sceneResource, ResrcRecord, handle16C)), (const RwV3d *)(D_005F1550 + scaleOffset), 2);
        mdlTranslateMatrix((RwMatrix *)MEMBER(u8 *, sceneResource, ResrcRecord, handle16C), (const RwV3d *)(placement + 0x140), 2);
        attachedMarker = MEMBER(u8 *, sceneResource, ResrcRecord, handle16C);
        ((FieldUnitObject *)entry)->marker = attachedMarker;
        mdlAdvanceModelFromFlags(attachedMarker);
        cellX = (s32)((600.0f + ((FieldUnitPlacement *)placement)->position.x) / 1200.0f);
        cellZ = (s32)((600.0f + ((FieldUnitPlacement *)placement)->position.z) / 1200.0f);
        *(u8 * *)&((ResrcRecord *)sceneResource)->slotHandle[0] = (u8 *)MT_Scene_GetRes(((FldFrame *)MT_Scene_GetFrameState())->cells[cellZ][cellX].resourceId);
        SceneDraw_SetResVisible(fieldObject->resourceId, 1);
        iGpffffb2e4 += 1;
    }
}

/* Select encounter placements and initialize the eight-entry field-object table. Raw word cursors
 * copy a placement image, and the slot-table scan uses a 0x168-byte record stride. */
// FUN_001662D0
void FldUnit_UpdateEnemySlot(void)
{
    u32 placementIndex;
    u32 stepIndex;
    u8 *placement;
    u8 *entryLimit;
    u8 *encounter;
    u8 *slot;
    s32 i;
    s32 j;
    u16 fieldId;
    u16 roomId;
    u8 *slotTable;
    u8 *copySource;
    u8 *copyDestination;
    s32 copyCount;

    stepIndex = FldStepIndex();
    if (iGpffffb260 == 1) {
        return;
    }
    memset(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    fieldId = *(u16 *)iGpffff9db0;
    roomId = *(u16 *)&((FieldUnitRoomKey *)iGpffff9db0)->roomId;
    entryLimit = (u8 *)Encount_GetEntryRate(fieldId, roomId, stepIndex);
    if (entryLimit == 0) {
        return;
    }
    if (fldStepGetModelSlot() == 0) {
        return;
    }
    i = 0;
    while ((placement = FldUnit_FindNearestSlot(entryLimit, &placementIndex, i)) != NULL) {
        fieldId = *(u16 *)iGpffff9db0;
        roomId = *(u16 *)&((FieldUnitRoomKey *)iGpffff9db0)->roomId;
        encounter = Encount_FindRecord(fieldId, roomId, stepIndex, 2);
        if (encounter == NULL) {
            kAssertFail(D_005F1500, 0xA63);
        }
        slot = NULL;
        j = 0;
        slotTable = D_007E80A0;
        for (; j < 8; j++) {
            if (((FieldUnitObject *)(slotTable + j * 0x168))->active == 0) {
                slot = slotTable + j * 0x168;
                break;
            }
        }
        *(s32 *)slot = 1;
        *(s32 *)&((FieldUnitObject *)slot)->encounter = (s32)encounter;
        *(s16 *)&((FieldUnitObject *)slot)->placementIndex = (s16)placementIndex;
        copyDestination = slot + 0x10;
        copyCount = 0x2A;
        copySource = placement;
        do {
            u32 w0 = *(u32 *)copySource;
            u32 w1 = ((S8 *)copySource)->h[1];
            copySource += 8;
            copyCount--;
            *(u32 *)copyDestination = w0;
            ((S8 *)copyDestination)->h[1] = w1;
            copyDestination += 8;
        } while (copyCount > 0);
        FldUnit_ApplySlotTint(slot, placement, 0x3FE - i);
        i++;
    }
}

/* Rebuild active field-object placements from the current scene resource list. */
/* Raw word cursors preserve the native paired-word copy of each placement image. */
// FUN_001664A0
void FldUnit_UpdateAllEnemySlots(void)
{
    s32 i;
    s32 k;
    s32 j = 0;
    u8 *node;
    u8 *p;
    if (D_00764350 != 1) {
        for (i = 0; i < 8; i++) {
            p = D_007E80A0 + i * 360;
            if (*(s32 *)p != 0) {
                node = MT_Scene_GetResListHead(0x10);
                if (node == 0) {
                    return;
                }
                for (k = 0; k < ((FieldUnitObject *)p)->placementIndex; k++) {
                    node = *(u8 * *)&((FieldUnitPlacement *)node)->next;
                    if (node == 0) {
                        kAssertFail(D_005F1500, 0xA87);
                    }
                }
                {
                    u8 *s;
                    u8 *d;
                    s32 n;
                    d = D_007E80A0 + (u32)i * 360 + 0x10;
                    n = 0x2A;
                    s = node;
                    do {
                        u32 w0 = *(u32 *)s;
                        u32 w1 = ((S8 *)s)->h[1];
                        s += 8;
                        n--;
                        *(u32 *)d = w0;
                        ((S8 *)d)->h[1] = w1;
                        d += 8;
                    } while (n > 0);
                }
                FldUnit_ApplySlotTint(D_007E80A0 + (u32)i * 360, node, 0x3FE - j);
                j++;
            }
        }
    }
}

/* Choose a placement away from the leader and existing objects, or select by index in band B. */
// FUN_00166600
u8 *FldUnit_FindNearestSlot(u8 *limit, u32 *selectedIndex, s32 requestedIndex)
{
    V3 pos;
    V3 vec;
    f32 distance;
    f32 bestDistanceSum;
    f32 distanceSum;
    u8 *candidate;
    u8 *selected;
    u8 *entry;
    s32 walked;
    s32 tooClose;
    s32 entryIndex;
    s32 candidateIndex;

    candidate = MT_Scene_GetResListHead(0x10);
    selected = NULL;
    FldStepIndex();
    *selectedIndex = 0;
    candidateIndex = 0;
    if (FldMap_IsCurrentInBandA() == 1) {
        if (iGpffffb2e4 < (s32)limit) {
            bestDistanceSum = 1.1754944e-38f;
            while (candidate != NULL) {
                pos = *(V3 *)&((FieldUnitPlacement *)candidate)->position.x;
                vec.x = pos.x - ((FieldUnitMatrix *)mdlGetMatrix(*(u8 **)D_007EFA00))->position.x;
                vec.y = pos.y - ((FieldUnitMatrix *)mdlGetMatrix(*(u8 **)D_007EFA00))->position.y;
                vec.z = pos.z - ((FieldUnitMatrix *)mdlGetMatrix(*(u8 **)D_007EFA00))->position.z;
                if (RwV3dLength(&vec.x) < 500.0f) {
                    candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
                    candidateIndex += 1;
                } else {
                    if (iGpffffb2e4 == 0) {
                        return candidate;
                    }
                    distanceSum = 1.1754944e-38f;
                    tooClose = 0;
                    entryIndex = 0;
                    while (entryIndex < 8) {
                        entry = D_007E80A0 + entryIndex * 0x168;
                        if (*(s32 *)entry != 0) {
                            vec.x = pos.x - ((FieldUnitObject *)entry)->placement.position.x;
                            vec.y = pos.y - ((FieldUnitObject *)entry)->placement.position.y;
                            vec.z = pos.z - ((FieldUnitObject *)entry)->placement.position.z;
                            distance = RwV3dLength(&vec.x);
                            if (distance < 100.0f) {
                                tooClose = 1;
                                break;
                            }
                            distanceSum += distance;
                        }
                        entryIndex += 1;
                    }
                    if (tooClose == 1) {
                        candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
                        candidateIndex += 1;
                    } else {
                        if (!(distanceSum <= bestDistanceSum)) {
                            bestDistanceSum = distanceSum;
                            *selectedIndex = candidateIndex;
                            selected = candidate;
                        }
                        candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
                        candidateIndex += 1;
                    }
                }
            }
        }
    } else if (FldMap_IsCurrentInBandB() == 1) {
        walked = 0;
        while (candidate != NULL) {
            if (walked == requestedIndex) {
                *selectedIndex = requestedIndex;
                selected = candidate;
                break;
            }
            candidate = *(u8 * *)&((FieldUnitPlacement *)candidate)->next;
            walked += 1;
        }
    }
    return selected;
}

/* Advance encounter creation, wait for slot readiness, and refill when the field limit permits. The
 * refill-limit read stays untyped, through the original work cursor. */
// FUN_001668E0
s32 FldUnit_SetupEncounter(u8 *task)
{
    FieldUnitEncounterWork *encounterWork;
    s32 value;
    s32 initialSlotIndex;
    s32 refillSlotIndex;
    s32 initialReady;
    s32 refillReady;
    u32 refillLimit;
    u32 spawnLimit;
    u8 *work;
    u8 *fieldState;

    work = ((KwlnTask *)task)->work;

    encounterWork = (FieldUnitEncounterWork *)work;
    if (((FieldUnitEncounterWork *)work)->mode == 1) {
        return 0;
    }
    if (((FieldUnitEncounterWork *)work)->suspended == 1) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        iGpffffb2e8 = 0;
        spawnLimit = ((FieldUnitEncounterWork *)work)->limit;
        if (spawnLimit == -1U) {
            fieldState = iGpffff9db0;
            spawnLimit = Encount_GetEntryRateOrOverride(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF));
        }
        if (FldMap_IsCurrentInBandB() == 1) {
            spawnLimit = encounterWork->limit;
            if (spawnLimit == -1U) {
                spawnLimit = 0xF;
            }
        }
        FldUnit_SpawnEncounter(spawnLimit, 0);
        *(s32 *)work += 1;
        break;
    case 1:
        initialSlotIndex = 0;
        while (initialSlotIndex < 0xF) {
            if (FldUnit_SetupSlot(initialSlotIndex) == 0) {
                initialReady = 0;
                goto out1;
            }
            initialSlotIndex += 1;
        }
        initialReady = 1;
    out1:
        if (initialReady != 0) {
            *(s32 *)work = 3;
        }
        break;
    case 2:
        refillSlotIndex = 0;
        while (refillSlotIndex < 0xF) {
            if (FldUnit_SetupSlot(refillSlotIndex) == 0) {
                refillReady = 0;
                goto out2;
            }
            refillSlotIndex += 1;
        }
        refillReady = 1;
    out2:
        if (refillReady != 0) {
            FldSlotBroadcastState(0);
            *(s32 *)work += 1;
        }
        break;
    case 3:
        fieldState = iGpffff9db0;
        refillLimit = Encount_GetEntryFlags(*(u16 *)fieldState, *(u16 *)&((FieldUnitRoomKey *)fieldState)->roomId, (u16)(FldStepIndex() & 0xFFFF));
        if ((u32)iGpffffb2e8 < refillLimit && FldUnit_SpawnEncounter(refillLimit, 1) > 0) {
            *(s32 *)work = 2;
        }
        break;
    }
    return 0;
}

// FUN_00166B10
void FldUnit_FreeEncounterState(u8 *task)
{
    (*DAT_008873EC)(*(void * *)&((KwlnTask *)task)->work);
}

/* Allocate the encounter controller work and attach its task to the supplied parent. */
// FUN_00166B40
s32 FldUnit_SpawnEncounterTask(u8 *parent, s32 spawnLimit)
{
    s32 workAddress;
    s32 task;
    if (FldMap_IsCurrentInBandA() == 0 && FldMap_IsCurrentInBandB() == 0) {
        return 0;
    }
    chkmemAllocSiteTag(D_005F1500, 0xB93);
    workAddress = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (workAddress == 0) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1590), 0xF, 0, 0, FldUnit_SetupEncounter, FldUnit_FreeEncounterState, (u8 *)(workAddress));
    *(s32 *)&((FieldUnitEncounterWork *)workAddress)->limit = spawnLimit;
    return task;
}

// FUN_00166C30
u32 FldUnit_IsSettled(u8 *task)
{
    if (task == 0) {
        return 1;
    } else {
        return (*(u32 *)&((FieldUnitEncounterWork *)((KwlnTask *)task)->work)->state ^ 3) < 1;
    }
}

/* Set the encounter task mode; a missing task intentionally leaves state unchanged. */
// FUN_00166C60
void FldUnit_SetMode(u8 *task, s32 mode)
{
    if (task != NULL) {
        ((FieldUnitEncounterWork *)((KwlnTask *)task)->work)->mode = mode;
    }
}

/* Apply the fixed violet tint while whitening ordinary model effects. Work and effect fields are
 * accessed through byte pointers across the tint callbacks. */
// FUN_00166C80
s32 FldUnit_PulseTintStep(u8 *task)
{
    FieldUnitEffectNode *effectEntry;
    FieldUnitTintWork *tintWork;
    u8 *work;
    u8 *node;
    u8 *sourceColor;
    u8 modelColor[4];
    u8 effectColor[4];
    u8 markerColor[4];
    s32 variant;
    s32 i;
    work = ((KwlnTask *)task)->work;
    tintWork = (FieldUnitTintWork *)work;
    sinf(D_007613EC * (f32)(((FieldUnitTintWork *)work)->frame) / 10.0f);
    sourceColor = mdlGetColor((u32)(((FieldUnitRecord *)*(u32 *)&((FieldUnitTintWork *)work)->unit)->model));
    *(S4 *)modelColor = *(S4 *)sourceColor;
    modelColor[0] = 0x34;
    modelColor[1] = 0x2E;
    modelColor[2] = 0x61;
    tintWork->frame = tintWork->frame + 1;
    if (tintWork->frame > 10) {
        tintWork->frame = 0;
    }
    variant = ((FieldUnitRecord *)(u32)(tintWork->unit))->variant;
    if (variant == 0) {
        u8 *unit = tintWork->unit;
        u8 *model = *(u8 * *)&((FieldUnitRecord *)unit)->model;
        u8 *effectList = ((FieldUnitModel *)model)->effectList;
        node = *(u8 **)effectList;
        effectEntry = (FieldUnitEffectNode *)node;
        while (node != NULL) {
            if (((FieldUnitEffectNode *)node)->effect != NULL) {
                mdlEffectGetPackedColor(((FieldUnitEffectNode *)node)->effect, effectColor);
                effectColor[0] = 0xFF;
                effectColor[1] = 0xFF;
                effectColor[2] = 0xFF;
                mdlEffectSetPackedColor(effectEntry->effect, effectColor);
            }
            node = *(u8 * *)&((FieldUnitEffectNode *)node)->next;
            effectEntry = (FieldUnitEffectNode *)node;
        }
    } else if (variant == 1) {
        u8 *unit = tintWork->unit;
        u8 *model = *(u8 * *)&((FieldUnitRecord *)unit)->model;
        u8 *effectList = ((FieldUnitModel *)model)->effectList;
        u8 *firstEffect = *(u8 **)effectList;
        u8 *secondEffect = *(u8 * *)&((FieldUnitEffectNode *)firstEffect)->next;
        node = *(u8 * *)&((FieldUnitEffectNode *)secondEffect)->next;
        effectEntry = (FieldUnitEffectNode *)node;
        if (((FieldUnitEffectNode *)node)->effect != NULL) {
            mdlEffectGetPackedColor(((FieldUnitEffectNode *)node)->effect, markerColor);
            markerColor[0] = modelColor[0];
            markerColor[1] = modelColor[1];
            markerColor[2] = modelColor[2];
            mdlEffectSetPackedColor(effectEntry->effect, markerColor);
        }
    }
    mdlSetColor((u32)(((FieldUnitRecord *)(u32)(tintWork->unit))->model), modelColor);
    return 0;
}

/* Pulse the model RGB over forty frames and propagate it to the marker effect. Counter reloads and
 * accesses across callbacks are kept as retail does them. */
// FUN_00166E30
s32 FldUnit_PulseTintPeriod(u8 *task)
{
    FieldUnitEffectNode *markerEffectEntry;
    FieldUnitEffectNode *effectEntry;
    FieldUnitTintWork *tintWork;
    u8 modelColor[4];
    u8 effectColor[4];
    u8 markerColor[4];
    f32 red;
    f32 green;
    f32 blue;
    f32 pulse;
    s32 nextFrame;
    u8 variant;
    u8 *work;
    u8 *markerEffect;
    u8 *sourceColor;
    u8 *unit;
    u8 *effectNode;
    u8 sourceRed;
    u8 sourceGreen;
    u8 sourceBlue;
    u8 sourceAlpha;

    work = ((KwlnTask *)task)->work;

    tintWork = (FieldUnitTintWork *)work;
    pulse = sinf(D_007613EC *
                             (f32)(((FieldUnitTintWork *)work)->frame) /
                             (f32)(((FieldUnitTintWork *)work)->period));
    sourceColor = mdlGetColor((s32)(((FieldUnitRecord *)((FieldUnitTintWork *)work)->unit)->model));
    sourceRed = *sourceColor++;
    sourceGreen = *sourceColor++;
    sourceBlue = *sourceColor++;
    sourceAlpha = *sourceColor++;
    modelColor[0] = sourceRed;
    modelColor[1] = sourceGreen;
    modelColor[2] = sourceBlue;
    modelColor[3] = sourceAlpha;
    tintWork->period = 0x28;
    red = (175.0f + 0.0f) + (70.0f * pulse);
    modelColor[0] = (u8)red;
    green = (37.0f + 0.0f) - (10.0f * pulse);
    modelColor[1] = (u8)green;
    blue = (255.0f + 0.0f) - (208.0f * pulse);
    modelColor[2] = (u8)blue;
    nextFrame = tintWork->frame + 1;
    tintWork->frame = nextFrame;
    if (tintWork->period < nextFrame) {
        tintWork->frame = 0;
    }
    unit = tintWork->unit;
    variant = ((FieldUnitRecord *)unit)->variant;
    if (variant == 0) {
        effectNode = ((FieldUnitModel *)*(u8 * *)&((FieldUnitRecord *)unit)->model)->effectList;
        effectEntry = (FieldUnitEffectNode *)effectNode;
        effectNode = *(u8 **)effectNode;
        effectEntry = (FieldUnitEffectNode *)effectNode;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)&((FieldUnitEffectNode *)effectNode)->effect != 0) {
            mdlEffectGetPackedColor(((FieldUnitEffectNode *)effectNode)->effect, effectColor);
            effectColor[0] = 0xFF;
            effectColor[1] = 0xFF;
            effectColor[2] = 0xFF;
            mdlEffectSetPackedColor(effectEntry->effect, effectColor);
        }
        effectNode = *(u8 * *)&((FieldUnitEffectNode *)effectNode)->next;
        effectEntry = (FieldUnitEffectNode *)effectNode;
loop_16_check:
        if (effectNode == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (variant == 1) {
        markerEffect = ((FieldUnitModel *)*(u8 * *)&((FieldUnitRecord *)unit)->model)->effectList;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 **)markerEffect;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 * *)&((FieldUnitEffectNode *)markerEffect)->next;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 * *)&((FieldUnitEffectNode *)markerEffect)->next;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        if (*(s32 *)&((FieldUnitEffectNode *)markerEffect)->effect != 0) {
            mdlEffectGetPackedColor(((FieldUnitEffectNode *)markerEffect)->effect, markerColor);
            markerColor[0] = modelColor[0];
            markerColor[1] = modelColor[1];
            markerColor[2] = modelColor[2];
            mdlEffectSetPackedColor(markerEffectEntry->effect, markerColor);
        }
    }
mode_done:
    mdlSetColor((s32)(((FieldUnitRecord *)tintWork->unit)->model), modelColor);
    return 0;
}

/* Pulse the model RGB over twenty frames and propagate it to the marker effect. */
// FUN_00167120
s32 FldUnit_PulseTintBlend(u8 *task)
{
    FieldUnitEffectNode *markerEffectEntry;
    FieldUnitEffectNode *effectEntry;
    FieldUnitTintWork *tintWork;
    u8 modelColor[4];
    u8 effectColor[4];
    u8 markerColor[4];
    f32 red;
    f32 green;
    f32 blue;
    f32 pulse;
    s32 nextFrame;
    u8 variant;
    u8 *work;
    u8 *markerEffect;
    u8 *sourceColor;
    u8 *unit;
    u8 *effectNode;
    u8 sourceRed;
    u8 sourceGreen;
    u8 sourceBlue;
    u8 sourceAlpha;

    work = ((KwlnTask *)task)->work;

    tintWork = (FieldUnitTintWork *)work;
    pulse = sinf(D_007613EC *
                             (f32)(((FieldUnitTintWork *)work)->frame) /
                             (f32)(((FieldUnitTintWork *)work)->period));
    sourceColor = mdlGetColor((s32)(((FieldUnitRecord *)((FieldUnitTintWork *)work)->unit)->model));
    sourceRed = *sourceColor++;
    sourceGreen = *sourceColor++;
    sourceBlue = *sourceColor++;
    sourceAlpha = *sourceColor++;
    modelColor[0] = sourceRed;
    modelColor[1] = sourceGreen;
    modelColor[2] = sourceBlue;
    modelColor[3] = sourceAlpha;
    tintWork->period = 0x14;
    red = 255.0f;
    modelColor[0] = (u8)red;
    green = (198.0f + 0.0f) + (57.0f * pulse);
    modelColor[1] = (u8)green;
    blue = 100.0f * pulse;
    modelColor[2] = (u8)blue;
    nextFrame = tintWork->frame + 1;
    tintWork->frame = nextFrame;
    if (tintWork->period < nextFrame) {
        tintWork->frame = 0;
    }
    unit = tintWork->unit;
    variant = ((FieldUnitRecord *)unit)->variant;
    if (variant == 0) {
        effectNode = ((FieldUnitModel *)*(u8 * *)&((FieldUnitRecord *)unit)->model)->effectList;
        effectEntry = (FieldUnitEffectNode *)effectNode;
        effectNode = *(u8 **)effectNode;
        effectEntry = (FieldUnitEffectNode *)effectNode;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)&((FieldUnitEffectNode *)effectNode)->effect != 0) {
            mdlEffectGetPackedColor(((FieldUnitEffectNode *)effectNode)->effect, effectColor);
            effectColor[0] = 0xFF;
            effectColor[1] = 0xFF;
            effectColor[2] = 0xFF;
            mdlEffectSetPackedColor(effectEntry->effect, effectColor);
        }
        effectNode = *(u8 * *)&((FieldUnitEffectNode *)effectNode)->next;
        effectEntry = (FieldUnitEffectNode *)effectNode;
loop_16_check:
        if (effectNode == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (variant == 1) {
        markerEffect = ((FieldUnitModel *)*(u8 * *)&((FieldUnitRecord *)unit)->model)->effectList;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 **)markerEffect;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 * *)&((FieldUnitEffectNode *)markerEffect)->next;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        markerEffect = *(u8 * *)&((FieldUnitEffectNode *)markerEffect)->next;
        markerEffectEntry = (FieldUnitEffectNode *)markerEffect;
        if (*(s32 *)&((FieldUnitEffectNode *)markerEffect)->effect != 0) {
            mdlEffectGetPackedColor(((FieldUnitEffectNode *)markerEffect)->effect, markerColor);
            markerColor[0] = modelColor[0];
            markerColor[1] = modelColor[1];
            markerColor[2] = modelColor[2];
            mdlEffectSetPackedColor(markerEffectEntry->effect, markerColor);
        }
    }
mode_done:
    mdlSetColor((s32)(((FieldUnitRecord *)tintWork->unit)->model), modelColor);
    return 0;
}

// FUN_001673F0
void FldUnit_FreeTintState(u8 *task)
{
    (*DAT_008873EC)(*(void * *)&((KwlnTask *)task)->work);
}

/* Create the encounter-category tint callback and initialize its pulse period. measured: the model
 * and flag accesses stay untyped because typed forms change retail codegen. */
// FUN_00167420
s32 FldUnit_SpawnTintTask(u8 *parent, u8 *unit)
{
    FieldUnitRecord *unitRecord = (FieldUnitRecord *)unit;
    s32 workAddress;
    s32 task;
    chkmemAllocSiteTag(D_005F1500, 0xD36);
    workAddress = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (workAddress == 0) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F15C0), 0xF, 0, 0, D_005F15B0[((FieldUnitRecord *)unit)->encounterCategory], FldUnit_FreeTintState, (u8 *)(workAddress));
    ((FieldUnitTintWork *)workAddress)->unit = unit;
    ((FieldUnitTintWork *)workAddress)->period = 0x28;
    ((FieldUnitModel *)*(u32 *)&((FieldUnitRecord *)unit)->model)->flags |= 0x80;
    if (((FieldUnitRecord *)unit)->variant == 1) {
        ((FieldUnitModel *)(u32)(unitRecord->model))->flags &= ~0x100;
    }
    return task;
}

// FUN_00167530
void FldUnit_ClearFlagBlock(void)
{
    memset(D_007E8020, 0, 0x40);
}

/* measured: the field and party state updates share the same reload settings. */
#pragma push
/* Keeps per-site unit addresses and each scan's readiness value; grid coordinates are signed, and
 * the second scan reuses the center and grid size, addressing its nearby-pointer list as base plus
 * offset. */
// FUN_00167560
/* measured: retail does not merge common subexpressions or propagate copies in this function, so
 * both optimizations are turned off here. */
#pragma opt_common_subs off
#pragma opt_propagation off
void FldUnit_UpdateFieldState(void)
{
    s32 playerCellX;
    s32 playerCellZ;
    s32 unitCellX;
    s32 unitCellZ;
    s32 objectCellX;
    s32 objectCellZ;
    s32 unitIndex;
    s32 objectIndex;
    s32 unitCount;
    s32 objectCount;
    s32 offset;
    s32 ready;
    u8 *unit;
    u8 *object;
    u8 *unitEntry;
    u8 **modelSlot;
    u8 *selectedUnit;
    u8 *selected;
    u8 *objectResource;
    s32 used;

    memset(D_007E8020, 0, 0x40);
    ready = *(u32 *)D_007EF9F8 != 0;
    if (ready) {
        ready = *(u32 *)D_007EFA04 != 0;
    }
    if (ready) {
        playerCellX = (s32)((600.0f + ((FieldUnitMatrix *)mdlGetMatrix(*(u8 **)D_007EFA00))->position.x) / 1200.0f);
        playerCellZ = (s32)((600.0f + ((FieldUnitMatrix *)mdlGetMatrix(*(u8 **)D_007EFA00))->position.z) / 1200.0f);
        unitIndex = 0;
        unitCount = 0;
        while (unitIndex < 0xF) {
            used = 0;
            unit = D_007E8C00 + unitIndex * 0x750;
            if (*(s32 *)&((FieldUnitRecord *)unit)->unitData != 0 && *(s32 *)&((FieldUnitRecord *)unit)->scene != 0) {
                used = 1;
            }
            ready = used != 0;
            if (ready) {
                unitEntry = D_007E8C00 + unitIndex * 0x750;
                modelSlot = (u8 **)(unitEntry + 0x50);
                unitCellX = (s32)((600.0f + ((FieldUnitMatrix *)mdlGetMatrix(*modelSlot))->position.x) / 1200.0f);
                unitCellZ = (s32)((600.0f + ((FieldUnitMatrix *)mdlGetMatrix(*modelSlot))->position.z) / 1200.0f);
                selected = (u8 *)MT_Scene_GetRes(((FldFrame *)MT_Scene_GetFrameState())->cells[unitCellZ][unitCellX].resourceId);
                if (!(unitCellX < playerCellX - 3 || unitCellX > playerCellX + 3 ||
                      unitCellZ < playerCellZ - 3 || unitCellZ > playerCellZ + 3 ||
                      selected == NULL || !(*(s32 *)&((ResrcRecord *)selected)->unk28 & 2))) {
                    if (unitCount >= 8) {
                        kAssertFail(D_005F1500, 0xE1F);
                    }
                    selectedUnit = D_007E8C00 + unitIndex * 0x750;
                    ((FieldUnitRecord *)selectedUnit)->flags |= 1;
                    ((u8 **)D_007E8020)[unitCount] = selectedUnit;
                    unitCount += 1;
                } else {
                    ((FieldUnitRecord *)unit)->flags &= ~1;
                }
            }
            unitIndex += 1;
        }
        objectIndex = 0;
        objectCount = 0;
        while (objectIndex < 8) {
            offset = objectIndex * 0x168;
            object = D_007E80A0 + offset;
            if (*(s32 *)object != 0) {
                f32 center;
                f32 gridSize;
                f32 positionX;
                f32 shiftedX;

                positionX = ((FieldUnitObject *)object)->placement.position.x;
                center = 600.0f;
                shiftedX = center + positionX;
                gridSize = 1200.0f;
                objectCellX = (s32)(shiftedX / gridSize);
                objectCellZ = (s32)((center + ((FieldUnitObject *)object)->placement.position.z) / gridSize);
                objectResource = (u8 *)MT_Scene_GetRes(((FldFrame *)MT_Scene_GetFrameState())->cells[objectCellZ][objectCellX].resourceId);
                if (!(objectCellX < playerCellX - 2 || objectCellX > playerCellX + 2 ||
                      objectCellZ < playerCellZ - 2 || objectCellZ > playerCellZ + 2 ||
                      objectResource == NULL || !(*(s32 *)&((ResrcRecord *)objectResource)->unk28 & 2))) {
                    if (objectCount >= 8) {
                        kAssertFail(D_005F1500, 0xE3C);
                    }
                    selected = D_007E80A0 + objectIndex * 0x168;
                    ((FieldUnitObject *)selected)->flags |= 1;
                    ((FieldUnitNearbySelection *)D_007E8020)->objects[objectCount] = selected;
                    objectCount += 1;
                } else {
                    ((FieldUnitObject *)object)->flags &= ~1;
                }
            }
            objectIndex += 1;
        }
    }
}

/* Model replacement waits for all selected units before completing the task; the scoped lifetime
 * settings keep the kind field across model teardown. */
// FUN_001679D0
#pragma push
/* measured: FldUnit_UpdatePartyState needs lifetime optimization on; typed access and block-scoped
 * lifetimes did not reproduce retail register allocation. */
#pragma opt_lifetimes on
s32 FldUnit_UpdatePartyState(u8 *task)
{
    u8 *entry;
    s32 index;
    u8 *work;
    u8 *unit;
    u8 *retainedField;
    u8 *field;
    s32 requestIndex;
    s32 attached;
    s32 selectedCount;
    s32 isAttached;
    s32 selectedIndex;
    s32 requestedKind;
    s32 kind;
    u16 fieldId;
    u16 fieldSubId;
    s32 replacementKind;

    work = ((KwlnTask *)task)->work;
    switch (*(s32 *)work) {
    case 0:
        for (index = 0; index < 4; index++) {
            attached = 0;
            unit = D_007EF9B0 + index * 0x750;
            if (*(s32 *)&((FieldUnitRecord *)unit)->unitData != 0) {
                if (*(s32 *)&((FieldUnitRecord *)unit)->scene != 0) {
                    attached = 1;
                }
            }
            isAttached = attached != 0;
            if (isAttached) {
                for (requestIndex = 0; requestIndex < 4; requestIndex++) {
                    requestedKind = ((FieldUnitPartyWork *)work)->requestedIds[requestIndex];
                    kind = ((FieldUnitRecord *)unit)->characterId;
                    if (requestedKind != kind) {
                        continue;
                    }
                    /* The kind address survives model teardown; its value selects the path. */
                    retainedField = unit + 0x728;
                    if (kind == 3) {
                        FldUnit_SetSlotModel(unit, 0);
                        entry = D_007F16F0 + index * 8;
                        if (*(s32 *)&((FieldUnitModelCache *)entry)->model != 0) {
                            s32 layer;

                            for (layer = 0; layer < 5; layer++) {
                                ((FieldUnitModel *)(*(s32 *)&((FieldUnitModelCache *)entry)->model))->layers[layer].flags |= 1;
                            }
                            entry = D_007F16F0 + index * 8;
                            unit = entry + 4;
                            mdlDestroyModelObject((u8 *)(*(s32 *)&((FieldUnitModelCache *)entry)->model));
                            *(s32 *)unit = 0;
                            *(s16 *)&((FieldUnitModelCache *)entry)->fieldId = 0;
                            *(s16 *)&((FieldUnitModelCache *)entry)->roomId = 0;
                        }
                        unit = D_007EF9B0 + index * 0x750;
                        /* Load the field context once, then pass both native halfword IDs. */
                        field = iGpffff9db0;
                        fieldId = *(u16 *)field;
                        fieldSubId = *(u16 *)&((FieldUnitRoomKey *)field)->roomId;
                        replacementKind = *(u16 *)retainedField;
                        *(u8 * *)&((FieldUnitRecord *)unit)->model = FldPartyModelGet(fieldId, fieldSubId, replacementKind);
                    } else {
                        s32 layer;

                        for (layer = 0; layer < 5; layer++) {
                            mdlDetachSlotModel((u8 *)(*(s32 *)&((FieldUnitRecord *)unit)->model), layer & 0xFFFF);
                        }
                        mdlRunSetupCallback((void *)(*(s32 *)&((FieldUnitRecord *)unit)->model));
                    }
                    selectedCount = ((FieldUnitPartyWork *)work)->selectedCount;
                    ((FieldUnitPartyWork *)work)->selectedIndices[selectedCount] = index;
                    ((FieldUnitPartyWork *)work)->selectedCount = ((FieldUnitPartyWork *)work)->selectedCount + 1;
                    break;
                }
            }
        }
        *(s32 *)work = *(s32 *)work + 1;
        break;
    case 1:
        for (index = 0; (u32)index < (u32)((FieldUnitPartyWork *)work)->selectedCount; index++) {
            entry = work + index * 4;
            retainedField = entry + 0x18;
            unit = D_007EF9B0 + ((FieldUnitPartyWork *)entry)->selectedIndices[0] * 0x750;
            if (((FieldUnitRecord *)unit)->characterId == 3) {
                if (mdlPrepareModel((u8 *)(*(s32 *)&((FieldUnitRecord *)unit)->model)) == 0) {
                    return 0;
                }
                attached = 0;
                selectedIndex = *(s32 *)retainedField;
                unit = D_007EF9B0 + selectedIndex * 0x750;
                if (*(s32 *)&((FieldUnitRecord *)unit)->unitData != 0) {
                    if (*(s32 *)&((FieldUnitRecord *)unit)->scene != 0) {
                        attached = 1;
                    }
                }
                isAttached = attached != 0;
                if (!isAttached) {
                    FldUnit_UpdateSlot(selectedIndex);
                }
            } else {
                s32 layer;

                for (layer = 0; layer < 5; layer++) {
                    if (mdlPrepareSlotModel((u8 *)(MEMBER(s32, D_007EF9B0 + ((FieldUnitPartyWork *)entry)->selectedIndices[0] * 0x750, FieldUnitRecord, model)), layer & 0xFFFF) == 0) {
                        return 0;
                    }
                }
            }
        }
        *(s32 *)work = *(s32 *)work + 1;
        /* fallthrough */
    case 2:
        return -1;
    }
    return 0;
}

#pragma pop
#pragma pop
// FUN_00167D60
void FldUnit_FreePartyState(u8 *task)
{
    (*DAT_008873EC)(*(void * *)&((KwlnTask *)task)->work);
}

/* Pack nonzero requested party IDs and launch a task to replace their models. */
// FUN_00167D90
s32 FldUnit_SpawnPartyTask(u8 *requests)
{
    s32 workAddress;
    s32 task;
    u32 packedIds = 0;
    s32 i = 0;
    s32 j = 0;
    while (i < 4) {
        u32 requestedId = *(u32 *)requests;
        if (requestedId != 0) {
            packedIds |= (requestedId & 0xFF) << (j * 8);
            j++;
        }
        i++;
        requests += 8;
    }
    if (packedIds == 0) {
        return 0;
    }
    if (FldRoomIsListed(*(u16 *)D_00762EA0, *(u16 *)&((FieldUnitRoomKey *)D_00762EA0)->roomId) == 1 || FldStepIndex() == 0) {
        return 0;
    }
    chkmemAllocSiteTag(D_005F1500, 0xED8);
    workAddress = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x28, 0x40000);
    if (workAddress == 0) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_005F15E0), 0xF, 0, 0, FldUnit_UpdatePartyState, FldUnit_FreePartyState, (u8 *)(workAddress));
    ((FieldUnitPartyWork *)workAddress)->requestedIds[0] = packedIds & 0xFF;
    ((FieldUnitPartyWork *)workAddress)->requestedIds[1] = (packedIds >> 8) & 0xFF;
    ((FieldUnitPartyWork *)workAddress)->requestedIds[2] = (packedIds >> 16) & 0xFF;
    ((FieldUnitPartyWork *)workAddress)->requestedIds[3] = (packedIds >> 24) & 0xFF;
    return task;
}

