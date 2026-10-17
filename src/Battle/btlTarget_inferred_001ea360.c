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
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern void btlActionFinishPresentation(s32 arg0);
extern BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 *btlCameraCreateSetStatePacket(s32 arg0, s32 arg1);


extern void btlPacketEnqueue(u8 *arg0, s32 arg1);
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
extern f32 scrGetParamFloat(s32 arg0);
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 *btlCameraCreatePoseSequencePacket(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7);
extern u8 D_00609E40[];
extern s32 btlUnitFindInSideById(s32 arg0, s32 arg1);
extern s32 btlActionFindByUnit(s32 arg0);
extern void btlEncounterSetSequence(s32 initialize, s32 update, s32 packet);
extern void btlActionRunFormationSequence(u8 *action);
extern s32 btlEncounterFinishSetup(u8 *action);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001ea360-001ea8e0 */

extern s32 btlCurrentUnitId(void);
#pragma push
#pragma pop
/* AI script command 0x2106 (p4flow AI.json AI_FUNCTION_0106). */
// FUN_001EA360
s32 btlEffectScriptSetActionMode5(void) {
    u8 *temp;

    temp = scrGetAiState();
    *(s16 *)(temp + 0x6C) = 5;
    return 1;
}

/* AI script command 0x2107 (p4flow AI.json AI_FUNCTION_0107). */
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
    *(u16 *)(work + 0x6C) = 1;
    *(u16 *)(work + 0x6E) = index;
    return 1;
}

/* AI script command 0x2103 (p4flow AI.json AI_FUNCTION_0103). */
// FUN_001EA420
s32 btlEffectScriptCheckUnitKindFlag20(void)
{
    scrSetReturnInt(((*(u32 *)(D_00724504 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18))) & 0x20) != 0);
    return 1;
}

/* AI script command 0x2108 (p4flow AI.json AI_FUNCTION_0108). */
// FUN_001EA470
s32 btlEffectScriptGetStoredValueC34(void) {
    scrSetReturnInt(*(s16 *)(iGpffffb3ac + 0xC34));
    return 1;
}

/* AI script command 0x210a (p4flow AI.json AI_FUNCTION_010A). */
// FUN_001EA4A0
s32 btlEffectScriptQueueFormationSequence(void) {
    s32 temp_2;
    s32 temp_2_2;

    if (btlCurrentUnitId() != 0x20B)
        goto set_flag;
    if (datGetFlag(0x15FF) != 1)
        goto body;
set_flag:
    *(s32 *)(iGpffffb3ac + 0x10) |= 0x10000000;
    goto done;
body:
    if (*(void **)(iGpffffb3ac + 0xB40) == (void *)btlActionRunFormationSequence)
        goto done;
    if (*(void **)(iGpffffb3ac + 0xB44) == (void *)btlEncounterFinishSetup)
        goto done;
    temp_2 = btlUnitFindInSideById(1, 0x10B);
    if (temp_2 == 0)
        goto done;
    temp_2_2 = btlActionFindByUnit(temp_2);
    if (temp_2_2 == 0)
        goto done;
    btlEncounterSetSequence((s32)btlActionRunFormationSequence, (s32)btlEncounterFinishSetup, temp_2_2);
done:
    return 1;
}

/* AI script command 0x20bb (p4flow AI.json AI_FUNCTION_00BB). */
// FUN_001EA580
s32 btlEffectScriptFinishWithCameraState21(void)
{
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket(*(s32 *)(iGpffffb3ac + 0x170), 0x21), 0);
    return 1;
}

/* AI script command 0x20bc (p4flow AI.json AI_FUNCTION_00BC). */
// FUN_001EA5F0
s32 btlEffectScriptFinishWithCameraState2C(void)
{
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket(*(s32 *)(iGpffffb3ac + 0x170), 0x2C), 0);
    return 1;
}

/* AI script command 0x20bd (p4flow AI.json AI_FUNCTION_00BD). */
// FUN_001EA660
s32 btlEffectScriptFinishWithCameraMove(void)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 first_copy;
    struct Vec3 second;
    struct Vec3 second_copy;
    f32 value;

    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    first.x = scrGetParamFloat(0);
    first.y = scrGetParamFloat(1);
    first.z = scrGetParamFloat(2);
    second.x = scrGetParamFloat(3);
    second.y = scrGetParamFloat(4);
    second.z = scrGetParamFloat(5);
    value = scrGetParamFloat(6);
    first_copy = first;
    second_copy = second;
    btlPacketEnqueue(btlCameraCreatePoseSequencePacket(
        *(s32 *)(iGpffffb3ac + 0x170),
        (f32 *)&first,
        (f32 *)&second,
        value,
        (f32 *)&first_copy,
        (f32 *)&second_copy,
        value,
        1.0f), 0);
    return 1;
}

/* AI script command 0x20be (p4flow AI.json AI_FUNCTION_00BE). */
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

/* AI script command 0x20bf (p4flow AI.json AI_FUNCTION_00BF). */
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

/* AI script command 0x20c0 (p4flow AI.json AI_FUNCTION_00C0). */
// FUN_001EA8E0
s32 btlEffectScriptFinishWithStoredCameraMove(void) {
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreatePoseSequencePacket(
        *(s32 *)(iGpffffb3ac + 0x170),
        &D_00881420[0],
        &D_00881400[0],
        fGpffffb458,
        &D_00881410[0],
        &D_008813F0[0],
        fGpffffb454,
        (f32)scrGetParamIntS32(0) / 30.0f), 0);
    return 1;
}

