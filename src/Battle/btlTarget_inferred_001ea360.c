#include "btl_target_internal.h"
#include "member_access.h"
#include "g_data_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);

extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern void btlActionFinishPresentation(s32);
extern BtlPacket *btlFormationCreateSlotPacket(u16, u16);
extern u8 *btlCameraCreateSetStatePacket(s32, s32);


extern void btlPacketEnqueue(u8 *, s32);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 scrGetParamFloat(s32);
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern void kAssertFail(void *, s32);
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 *btlCameraCreatePoseSequencePacket(s32, f32 *, f32 *, f32, f32 *, f32 *, f32, f32);
extern u8 D_00609E40[];
extern s32 btlUnitFindInSideById(s32, s32);
extern s32 btlActionFindByUnit(s32);
extern void btlEncounterSetSequence(s32 start, s32 update, s32 argument);
extern void btlActionRunFormationSequence(u8 *action);
extern s32 btlEncounterFinishSetup(u8 *action);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

extern s32 btlCurrentUnitId(void);
#pragma push
#pragma pop
/* Set the current AI action's mode field to 5 and return 1 so the script continues. */
// FUN_001EA360
s32 btlEffectScriptSetActionMode5(void) {
    u8 *action;

    action = scrGetAiState();
    ((BtlAction *)action)->unk_6c = 5;
    return 1;
}

/* Set the AI state's action mode to 1 using the slot index from parameter 0, and assert if that
 * slot is not flagged as present. */
// FUN_001EA390
s32 btlEffectScriptSetActionModeWithSlot(void)
{
    u8 *work;
    s32 index;

    work = scrGetAiState();
    index = scrGetParamIntS32(0);
    if ((iGpffffb3b8[index * 0x28] & 2) == 0) {
        kAssertFail(D_00609E30, 5711);
    }
    ((BtlAction *)work)->unk_6c = 1;
    ((BtlAction *)work)->unk_6e = index;
    return 1;
}

// FUN_001EA420
s32 btlEffectScriptCheckUnitKindFlag20(void)
{
    /* The encounter track rule shares its leading flags with the sound selectors. */
    scrSetReturnInt((((u32)((BtlSoundTrackRule *)D_00724504)[((BtlSoundEncounterRecord *)((u8 *)(((BtlBattleState *)iGpffffb3ac)->encounterRecord)))->trackRule].flags) & 0x20) != 0);
    return 1;
}

// FUN_001EA470
s32 btlEffectScriptGetStoredValueC34(void) {
    scrSetReturnInt(((BtlBattleState *)iGpffffb3ac)->bossPhase);
    return 1;
}

// FUN_001EA4A0
s32 btlEffectScriptQueueFormationSequence(void) {
    /* Retail loads and compares the sequence callback in this order. */
    s32 unit;
    s32 action;

    if (btlCurrentUnitId() != 0x20B)
        goto set_flag;
    if (datGetFlag(0x15FF) != 1)
        goto body;
set_flag:
    ((BtlBattleState *)iGpffffb3ac)->battleFlags |= 0x10000000;
    goto done;
body:
    if ((void *)(((BtlSoundEncounterSequence *)(iGpffffb3ac + 0xB40))->start) == (void *)btlActionRunFormationSequence)
        goto done;
    if ((void *)((BtlBattleState *)iGpffffb3ac)->encounterSequenceUpdate == (void *)btlEncounterFinishSetup)
        goto done;
    unit = btlUnitFindInSideById(1, 0x10B);
    if (unit == 0)
        goto done;
    action = btlActionFindByUnit(unit);
    if (action == 0)
        goto done;
    btlEncounterSetSequence((s32)btlActionRunFormationSequence, (s32)btlEncounterFinishSetup, action);
done:
    return 1;
}

/* Finish the selected action's presentation, then queue a formation slot packet and a packet that
 * sets camera state 0x21. */
// FUN_001EA580
s32 btlEffectScriptFinishWithCameraState21(void)
{
    btlActionFinishPresentation((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction), 0x21), 0);
    return 1;
}

/* Finish the selected action's presentation, then queue a formation slot packet and a packet that
 * sets camera state 0x2C. */
// FUN_001EA5F0
s32 btlEffectScriptFinishWithCameraState2C(void)
{
    btlActionFinishPresentation((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction), 0x2C), 0);
    return 1;
}

/* Finish the selected action's presentation and queue a camera pose sequence. The two camera
 * vectors and the duration come from the seven float script parameters. */
// FUN_001EA660
s32 btlEffectScriptFinishWithCameraMove(void)
{

    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 firstCopy;
    struct Vec3 second;
    struct Vec3 secondCopy;
    f32 value;

    btlActionFinishPresentation((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    first.x = scrGetParamFloat(0);
    first.y = scrGetParamFloat(1);
    first.z = scrGetParamFloat(2);
    second.x = scrGetParamFloat(3);
    second.y = scrGetParamFloat(4);
    second.z = scrGetParamFloat(5);
    value = scrGetParamFloat(6);
    firstCopy = first;
    secondCopy = second;
    btlPacketEnqueue(btlCameraCreatePoseSequencePacket(
        MEMBER(s32, iGpffffb3ac, BtlBattleState, selectedAction),
        (f32 *)&first,
        (f32 *)&second,
        value,
        (f32 *)&firstCopy,
        (f32 *)&secondCopy,
        value,
        1.0f), 0);
    return 1;
}

/* Read two camera vectors and a trailing value from the seven float script parameters and store
 * them in the first camera vector globals. */
// FUN_001EA780
s32 btlEffectScriptStoreCameraVectorsA(void) {
    D_00881420[0] = scrGetParamFloat(0);
    D_00881424[0] = scrGetParamFloat(1);
    D_00881428[0] = scrGetParamFloat(2);
    D_00881400[0] = scrGetParamFloat(3);
    D_00881404[0] = scrGetParamFloat(4);
    D_00881408[0] = scrGetParamFloat(5);
    fGpffffb458 = scrGetParamFloat(6);
    return 1;
}

/* Read seven float script parameters and store them as the second pair of camera position and
 * target vectors plus the matching camera parameter in fGpffffb454. */
// FUN_001EA830
s32 btlEffectScriptStoreCameraVectorsB(void) {
    D_00881410[0] = scrGetParamFloat(0);
    D_00881414[0] = scrGetParamFloat(1);
    D_00881418[0] = scrGetParamFloat(2);
    D_008813F0[0] = scrGetParamFloat(3);
    D_008813F4[0] = scrGetParamFloat(4);
    D_008813F8[0] = scrGetParamFloat(5);
    fGpffffb454 = scrGetParamFloat(6);
    return 1;
}

/* Finish the selected action's presentation, then queue a formation slot packet and a camera pose
 * sequence that moves between the stored camera vectors. The duration comes from the first script
 * parameter, given in frames. */
// FUN_001EA8E0
s32 btlEffectScriptFinishWithStoredCameraMove(void) {
    btlActionFinishPresentation((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreatePoseSequencePacket(
        (s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction),
        &D_00881420[0],
        &D_00881400[0],
        fGpffffb458,
        &D_00881410[0],
        &D_008813F0[0],
        fGpffffb454,
        (f32)scrGetParamIntS32(0) / 30.0f), 0);
    return 1;
}

