#include "mt_scene_internal.h"
#include "model_motion_internal.h"
/* Original translation unit k_fldUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "model_matrix_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "Kosaka/k_model_internal.h"
#include "rw/std/stddef.h"

typedef struct HCdvd HCdvd;
typedef struct Model Model;
typedef struct Resrc Resrc;
typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

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
extern s32 KMisc_CreateDelayMdlFree(s32 arg0, s32 arg1);
extern void datUnitFree(s32 arg0);
extern s32 mdlPrepareSlotModel(u8 *arg0, u16 arg1);
extern void mdlDetachSlotModel(u8 *arg0, u16 arg1);
extern u32 H_Cdvd_IsFileLoaded(HCdvd *arg0);
extern u32 H_Cdvd_Destroy(HCdvd *arg0);
extern void *memcpy(void *arg0, const void *arg1, u32 arg2);
extern s32 Encount_GetEntryRateOrOverride(u16 arg0, u16 arg1, u16 arg2);
extern s32 Encount_GetEntryFlags(u16 arg0, u16 arg1, u16 arg2);
extern void func_00182310(s32 arg0);
extern s32 FldUnit_SpawnEncounter(u32 arg0, s32 arg1);
typedef struct DatUnitEc DatUnitEc;
extern DatUnitEc *datUnitCreateEncounterGroup(u16 encountId);
extern u8 *FldUnit_CreateEncounterUnit(u32 arg0, u8 *arg1, s32 arg2);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);
extern u32 RpRandom(void);
extern void mdlSetAttachedOwner(u8 *arg0, u8 *arg1);
extern s32 FldEvent_AverageEntryValue(void);
extern void FldShadow_SetRingParticles(s32 arg0, f32 arg1);
extern void mdlScale(Model *arg0, const RwV3d *arg1, s32 arg2);
extern void RwMatrixUpdate(u8 *arg0);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
extern void FldFrameTask_SetPosition();
extern void SceneDraw_SetResVisibleChecked(u16 arg0, u32 arg1);
extern void FldFrameTask_SetFlags(s32 arg0, s32 arg1);
extern void FldFrameTask_SetHeight(s32 arg0, f32 arg1);
extern u32 *mdlCloneModelObject(u8 *arg0);
extern f32 FldFrameTask_GetHeight(s32 arg0);
extern void mdlAdvanceModelFromFlags(u8 *arg0);
extern s32 FldAI_SpawnPatrol(s32 arg0, u8 *arg1, s32 arg2);
extern s32 datUnitGroupIsDefeated(s32 arg0);
extern s32 func_0016fd00(s32 arg0);
extern s32 FldAI_SpawnChaser(s32 arg0, u8 *arg1, u8 *arg2);
extern void FldAI_ChaserEnable(s32 arg0);
extern s32 func_0017d070(u8 *arg0);
extern void FldFrameTask_UpdateTile(s32 arg0);
extern f32 RwV3dLength(f32 *arg0);
extern s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level);
extern u8 *FldUnit_FindNearestUnits(s32 arg0, u32 arg1, f32 arg2);
extern u8 *FldEvent_GetGridCellEntry(s32 arg0, s32 arg1);
extern void FldEvent_BeginGridScan(void);
extern s32 FldEvent_NextGridCell(s32 *arg0, s32 *arg1);
extern s32 datGetFlag(s32 arg0);
extern s32 MT_Scene_CreateModelFldRes(s32 arg0, s32 arg1);
extern u8 *FldSlotFindFree(void);
typedef struct DatUnitPc DatUnitPc;
extern DatUnitPc *datUnitCreatePc(u16 arg0);
extern u8 *FldPartyModelGet(u16 arg0, u16 arg1, s32 arg2);
extern u8 datPersonaGetLevelByPcId(u16 arg0);
extern s16 datGetPartyId(s32 arg0);
extern s32 datCalcGetLevelById(s32 arg0);
extern s32 *MT_Scene_GetFrameState(void);
extern void SceneDraw_SetResVisible(u16 arg0, s32 arg1);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern s32 func_0018bb20(s32 arg0, s32 arg1);

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
extern u8 D_007EFB64[];
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

s32 FldUnit_SetupSlot(s32 arg0);
void FldUnit_ReleaseSlot(u8 *arg0);
void FldUnit_UpdateSlot(s32 arg0);
void FldUnit_SetSlotModel(u8 *arg0, s32 arg1);
s32 mdlPrepareModel(u8 *arg0);
s32 func_00440b68(const char *fmt, ...);
u8 *func_00454a60(u8 *arg0, s32 arg1);
s32 FldMap_IsCurrentInBandA(void);
s32 FldMap_IsCurrentInBandB(void);
s32 FldUnit_SetupEncounter(u8 *arg0);
void chkmemAllocSiteTag(u8 *arg0, s32 arg1);
f32 sinf(f32 arg0);
u8 *mdlGetColor(s32 arg0);
void mdlSetColor(s32 arg0, u8 *arg1);
void func_004b14f0(u8 *arg0, u8 *arg1);
void func_004b13f0(u8 *arg0, u8 *arg1);
void *mdlGetMatrix(void *arg0);
void MT_Scene_DestroyRes(u16 arg0);
void mdlClearAlphaBlend(s32 arg0);
void mdlDestroyModelObject(u8 *arg0);
void kwlnTaskDestroyWithHierarchy(s32 arg0);
s32 FldRoomIsListed(u16 arg0, u16 arg1);
s32 FldStepIndex(void);
s32 FldUnit_UpdatePartyState(u8 *arg0);
u8 *MT_Scene_GetResListHead(s32 arg0);
void kAssertFail(void *arg0, s32 arg1);
void FldUnit_ApplySlotTint(u8 *arg0, u8 *arg1, s32 arg2);
u8 *FldUnit_FindNearestSlot(u8 *arg0, u32 *arg1, s32 arg2);
extern s64 datGetDateIndex(void);
extern s32 func_001064f0(s32 arg0);
extern s32 calGetDayWindowFlags(s16 arg0);
extern s32 D_007E8BF8[];
void *memset(void *arg0, s32 arg1, u32 arg2);
s32 Encount_GetEntryRate(u16 arg0, u16 arg1, u16 arg2);
s32 func_0015a320(void);
u8 *Encount_FindRecord(s32 field, s32 room, u16 index, u16 mode);






extern s32 FldUnit_UpdateTable(void);
#pragma opt_common_subs off
/* measured: restore common-subexpression elimination after FldUnit_UpdateTable. */
#pragma opt_common_subs on
/* Initialize the four occupied party slots that do not yet have scene resources:
 * attach models and placements, apply the leader's calendar/room animation rule,
 * position the party, then create follower controllers and reset per-unit state.
 *
 * measured: 1 -> 0 fnalign edits, 736 instructions. The remaining operand was a
 * real inline-result lifetime, not a compiler floor. The calendar search below
 * follows matched sibling FldDayEventActive: its initial found = 0 and early return 0
 * both survive allocation, giving found four counted references and retail's $s5.
 * Post-color CSE removes the early-return zero; the success store is then the
 * required addiu $s5, $zero, 1. A capture confirms that exact deletion.
 *
 * Typed views document observed offsets; unknown fields remain unnamed. Separate
 * placementCursor preserves the node-loop entry branch. Per-phase slot lookups,
 * address conversions and word-aligned copies preserve retail's evaluation order.
 */
#pragma push
/* measured: dead assignments off + lifetimes on took 180 -> 173 edits;
 * retain these scopes for the byte-exact initializer below. */
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
/* The current field's prefix and each sentinel-terminated table entry share
 * this key layout. iGpffff9db0 points to the current field/room state;
 * D_005F1350 terminates when fieldId is -1.
 */
typedef struct {
    s32 fieldId;
    s32 roomId;
} FieldUnitRoomKey;

typedef struct {
    u8 unknown00[9];
    u8 direction;                        /* 0x09: quarter-turn orientation */
    u8 unknown0A[6];
} FieldUnitGridCell;                     /* 0x10-byte cell, 0x100-byte row */

/* Only the header and first row are described; later rows use a 0x100-byte
 * displacement from this view. This is not the complete grid allocation. */
typedef struct {
    u8 unknown00[0x44];
    u8 spawnColumn;                      /* 0x44 */
    u8 spawnRow;                         /* 0x45 */
    u8 unknown46[0xA];
    FieldUnitGridCell cells[16];          /* 0x50: first-row view only */
} FieldUnitGridView;

/* Partial object views recovered from the accesses below and the constructors
 * MT_Scene_CreateModelCharShadowRes (scene resource) and FldUnit_CreateEncounterUnit (0x750-byte unit).
 * Unknown bytes describe real, unclassified fields, not extra storage.
 */
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
    u8 unknown0D6[0x1B6];
    FieldUnitAnimationLayer layers[5];    /* 0x28C */
} FieldUnitModelView;

typedef struct {
    u16 resourceId;                       /* 0x000 */
    u8 unknown002[0x162];
    FieldUnitModelView *model;            /* 0x164 */
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
    u8 unknown000[0x48];
    void *unitData;                       /* 0x048: NULL means unused */
    void *modelData;                      /* 0x04C */
    FieldUnitModelView *model;            /* 0x050 */
    FieldUnitSceneResource *scene;        /* 0x054: NULL until initialized */
    u16 placementId;                      /* 0x058 */
    u8 unknown05A[2];
    FieldUnitPlacement placementStorage; /* 0x05C */
    FieldUnitPlacement *placement;        /* 0x1AC */
    s32 followerTask;                     /* 0x1B0: follows the previous unit */
    u8 unknown1B4[0x1C];
    u8 state1D0[0x40];
    FieldUnitSamplePair samples[0x40];    /* 0x210 */
    u8 state410[0x300];
    u8 unknown710[0x18];
    u16 characterId;                      /* 0x728: datGetPartyId result */
    u8 unknown72A[0x26];
} FieldUnitRecord;                       /* 0x750 bytes */

/* Keep the index product separate from the model load, as retail does. */
static inline FieldUnitAnimationLayer *fieldUnitLayerAt(FieldUnitRecord *unit, s32 index)
{
    return (FieldUnitAnimationLayer *)(
        *(u8 **)((u8 *)unit + (s32)offsetof(FieldUnitRecord, model)) +
        index * (s32)sizeof(FieldUnitAnimationLayer) +
        (s32)offsetof(FieldUnitModelView, layers));
}

/* Preserve the byte-address addition used for the two adjacent samples. */
static inline FieldUnitSamplePair *fieldUnitSampleAt(FieldUnitRecord *unit, s32 index)
{
    return (FieldUnitSamplePair *)((u8 *)unit +
        index * (s32)sizeof(FieldUnitSamplePair) +
        (s32)offsetof(FieldUnitRecord, samples));
}

/* Taking the index address retains retail's separate per-phase lookups. */
static inline FieldUnitRecord *fieldUnitSlotAt(const s32 *index)
{
    return (FieldUnitRecord *)(D_007EF9B0 + (*index * 0x750));
}

/* The same date/room search as FldDayEventActive, kept inline so its internal result
 * and early-return value remain separate until the compiler merges their lives.
 * Before allocation the result has two zero definitions, one success definition
 * and one test (score 4). Post-color CSE deletes the redundant early-return zero.
 * No helper-specific optimization override is needed.
 */
static inline s32 fieldUnitCalendarRoomMatch(void)
{
    extern s32 calIsCurrentMonthDay(s32 date, s32 month, s32 day);
    extern s16 datGetDateIndex(void);
    extern u8 datGetTimeSlot(void);
    extern s64 calGetDayEntryByPhase(s32 date, u32 phase);
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

#pragma pop



#pragma push
#pragma opt_loop_invariants on
#pragma pop
































s32 FldEvent_IsCellOccupied(u8 *position);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* Keep the random node, its rejection state and the loop count in their
   own selection lifetime. The same vector is reused for each distance test. */
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
    cursor = *(u8 **)(cursor + 0x138);
count_test:
    if (cursor != NULL) {
        goto count_body;
    }
    count = RpRandom() % count;
    choice = MT_Scene_GetResListHead(0xF);
    walked = 0;
    goto walk_test;
walk_body:
    choice = *(u8 **)(choice + 0x138);
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
    if (*(s32 *)(unit + 0x48) != 0 && *(s32 *)(unit + 0x54) != 0) {
        used = 1;
    }
    ready = used != 0;
    if (ready) {
        unit = D_007EF9B0 + index * 0x750;
        modelSlot = (void **)(unit + 0x50);
        model = (u8 *)mdlGetMatrix(*(void **)(unit + 0x50));
        coordinate = *(f32 *)(model + 0x30);
        delta->x = *(f32 *)(choice + 0x140) - coordinate;
        model = (u8 *)mdlGetMatrix(*modelSlot);
        coordinate = *(f32 *)(model + 0x34);
        delta->y = *(f32 *)(choice + 0x144) - coordinate;
        model = (u8 *)mdlGetMatrix(*modelSlot);
        coordinate = *(f32 *)(model + 0x38);
        delta->z = *(f32 *)(choice + 0x148) - coordinate;
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

#pragma pop








#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop









#pragma opt_common_subs off
#pragma opt_propagation off
/* measured: closes the two brackets above; the file default is on. */
#pragma opt_common_subs on
#pragma opt_propagation on


















/* measured: b210 -O2 emits 964 bytes and twelve zero alignment bytes.
 * Loop-invariant motion preserves the active-record comparison. Disabling
 * constant extraction keeps the scale stores inside the creation loop;
 * propagation-off retains the file-slot and selected-index address lifetimes.
 * Readiness uses the two owner handle arrays; D_007E8BE0 holds selection rows.
 * Evidence: build/first-party-continue-live/field/constructor-release/. */
#pragma push
#pragma opt_pulloutconstants off
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
































/* measured: nd 164 after four attempts. The u8 sp buffer must be ONE array
   (separate u8 locals get dead-store-eliminated â€” only the address-taken
   byte aliases; cascades into the sp[9]/sp[10] conversions). The saturation
   idiom from gc_model.c (if (x < 2.1474836e9f) {(u8)(s32)x} else {(u8)(s32)
   (x - 2.1474836e9f)}) reproduces the cvt.w.s guard for VARIABLE values
   (blocks 2/3), but: (1) block 1's 255.0f constant still folds the whole
   compare+guard away under mwccgap (real b210 emitted c.ole.s/bc1t for it;
   tried literal, single- and multi-assigned f32 locals â€” all fold); (2) the
   guard comes out c.olt.s+bc1f with the normal arm inline where retail has
   c.ole.s $f0,$f1 + bc1t with the saturate arm out of line â€” 2 words per
   block; (3) temp_4_2 lands in $s2 (frame 0x60) where retail keeps it in a
   caller-saved temp (frame 0x50). Everything else (FMA adda.s/madd.s
   198+57*f20, mul.s 100*f20, the f20 spill at 0x0, byte copies, node loops,
   func_0047a220 tail) matches. */














#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop


#pragma push
#pragma opt_lifetimes on
#pragma opt_common_subs off
#pragma opt_propagation off

#pragma pop



