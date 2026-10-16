#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "field_event_internal.h"
#include "model_motion_internal.h"
/* Original translation unit k_fldEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

struct RwV3d;
struct RwMatrix;
struct RwMatrixTag;
struct Resrc;
struct DatUnitGenusBase;
struct P4_0015_Vec3;
void *mdlGetMatrix(void *);


extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 D_007243EC;
extern s32 D_007243E8;
extern f32 D_007243DC;
extern s32 D_00724358;
extern char D_005F1798[];
extern char D_005F1828[];
extern char D_005F1848[];
extern u32 D_007EFA00[];
typedef struct { f32 x, y, z; } FldEventVec3;
extern FldEventVec3 D_005F1838;

void chkmemAllocSiteTag(const void *, u32);

void FldAmbientFlagClear(void);
void FldEvent_SetTriggerParam(s32, s32);
s32 FldEvent_FindNearbyEntry(void);
s32 FldEvent_MoverUpdate(u8 *);
struct DatPersonaRecord *datPersonaGetRecord(u16);
s32 datPersonaFindSkillSlot(u8 *, u16);
s16 datGetPartyId(s32);
s16 func_00106cd0(s16, s32);
s32 FldEvent_TriggerUpdate(u8 *);
s32 FldMap_IsCurrentInEitherBand(void);
s32 FldStepIndex(void);
s32 FldEvent_FindFirstRegionActor(f32, f32, void *);
u8 *FldAmbientFlagPtr(void);
s32 FldStepFileTask(s32);
s32 FldRc_RequestPositionSlot(u8 *, f32 *);
void FldSlotBroadcastState(s32);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
void FldFrameTask_SetOrientation(u8 *, u8 *);
s32 *MT_Scene_GetFrameState(void);
void FldFrameObjSetActive(s32, s32);
void fclMiscStopAndClose(void);
void fclMiscSetDoneFlag(void);
s32 FldStepGetScriptData(void);
s32 FldStepGetScriptSize(void);
s32 scrStartProcedureChecked(s32, s32, s32, s32);
s32 kwlnTaskIsLinked(void *);
s32 *FldObjFindFree(void);
s32 datUnitCreateEncounterGroup(s32);
s32 FldEvent_FieldToBattle(u8 *);
u32 datUnitGroupIsDefeated(struct DatUnitGenusBase *);
f32 RwV3dLength(f32 *);
s32 MT_Scene_GetResListHead(s32);
s32 FldNpcControlReady(s32);
u32 K_FldEvent_IsPosWithinFov(const struct RwMatrix *, const struct RwV3d *, f32);
void FldStepCopyTableEntry(s32, s32, s32);
void kAssertFail(const void *, u32);
void FldUnit_UpdateFieldState(void);
s32 MT_Scene_AllResFlagSet(void);
s16 mdlGetLayerAnimation(s32, s32);
s32 FldMoveAnimPrimary(s32);
s32 FldMoveAnimSecondary(s32);
s32 FldCharacterAnimSelect(s32);
void FldFrame_SetStateFlags(s32, s32);
void FldFrame_ClearStateFlags(s32, s32);
void FldPlayerIconUpdatePos(u8 *);
void FldPlayerIconSetActive(s32, s32);
s32 FldEvent_StepMoveToward(u8 *);
s32 func_0018bea0();
void FldNpcControlFacePlayer(s32);
void FldNpcSetPositionLock(s32, s32);
void FldNpcControlTurnBack(s32);
void mdlSetLayerWeight(u8 *, s32, f32);
void MT_Scene_BeginValueStep(u8 *, u16, u16, u16);

extern u32 D_005F17D0[];
extern u32 D_005F17D4[];
extern u32 D_007EFB64[];

extern f32 D_007615DC;

extern s32 D_007243E0;
extern s32 D_007243E4;
extern s32 D_00724504;
typedef struct { s32 x; } FldEventFlag;
extern FldEventFlag D_007EF9F8[];

extern u16 D_008C024E[];
extern s32 D_007243D0;
extern u8 D_007EF9B0[];

extern char D_005F1770[];
extern char D_005F1780[];
extern u32 D_007EFA04[];
extern u8 *mdlGetClump(s32);
extern s32 K_Clump_ClumpHasMatUsrData(u8 *, char *);
extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *, const struct RwV3d *, f32);
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldMap_IsCurrentInBandB(void);

extern s32 FldEvent_SelectEntryAtPosition(u8 *arg0);
#pragma opt_loop_invariants on
/* measured: restore loop-invariant optimization after FldEvent_SelectEntryAtPosition. */
#pragma opt_loop_invariants off
/* Field event record (0x2C bytes) in the table at (s32)MT_Scene_GetFrameState() + 0x18DC. */
typedef struct
{
    u8 pad0[0x10];
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u8 pad1C[0x10];
} FldEvtEntry;
#define FLD_EVT_TABLE() (*(FldEvtEntry **)((u8 *)(s32)MT_Scene_GetFrameState() + 0x18DC))
#define FLD_EVT_ENTRY(h) (&FLD_EVT_TABLE()[*(u16 *)((h) + 0x2C) & 0x3FF])
#pragma push
#pragma opt_common_subs off
#pragma pop
#undef FLD_EVT_ENTRY
#undef FLD_EVT_TABLE



#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
#pragma pop
#pragma pop


#pragma push
#pragma opt_dead_assignments off

#pragma pop





