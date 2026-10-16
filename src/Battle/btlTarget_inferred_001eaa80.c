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
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

extern u8 *btlActionGetActiveOrQueueFront(void);

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void func_00213b80(s32 task);
extern void func_00213b50(s32 task);
extern s32 func_001eb860(void);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
extern s32 D_00724504;
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern void btlActionFinishPresentation(s32 arg0);
extern BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 *btlEffectFindUnitByIdAndStatus();


extern void btlPacketEnqueue(u8 *arg0, s32 arg1);
extern s32 btlUnitRecordFindByUID(s64 arg0, s64 arg1);
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
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern BtlPacket *btlBossCreateStepEndBgmPacket(void);
extern u8 *btlSoundCreateStreamPacket(s32 arg0, void *arg1);
extern void sprintf(void *arg0, void *arg1, s64 arg2);
extern u8 D_00609E40[];
extern u8 *btlFormationGetRecord(s32 arg0);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001eaa80-001eb110 */

extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
#pragma push
#pragma pop
/* AI script command 0x20c2 (p4flow AI.json AI_FUNCTION_00C2). */
// FUN_001EAA80
s32 btlEffectScriptSetBattleFlag2000(void) {
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    }
    return 1;
}

/* AI script command 0x20c3 (p4flow AI.json AI_FUNCTION_00C3). */
// FUN_001EAAC0
s32 btlEffectScriptClearBattleFlag2000(void)
{
    u8 *temp_4;

    if (func_001eb860() == 1) {
        temp_4 = iGpffffb3ac;
        *(s32 *)(temp_4 + 0xC) = *(s32 *)(temp_4 + 0xC) & ~0x2000;
        func_001eb7f0();
    }
    return 1;
}

/* AI script command 0x20c4 (p4flow AI.json AI_FUNCTION_00C4). */
// FUN_001EAB10
s32 btlEffectScriptSetDamageSourceOn(void) {
    func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        btlDamageSetSource(*(u8 **)(iGpffffb3ac + 0xDD4), 1);
    }
    return 1;
}

/* AI script command 0x20c5 (p4flow AI.json AI_FUNCTION_00C5). */
// FUN_001EAB60
s32 btlEffectScriptSetDamageSourceOff(void) {
    func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        btlDamageSetSource(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
    }
    return 1;
}

/* AI script command 0x20c8 (p4flow AI.json AI_FUNCTION_00C8). */
// FUN_001EABC0
s32 btlEffectScriptCheckSideAndId(void) {
    u8 *p = btlActionGetActiveOrQueueFront();
    u32 a = scrGetParamIntS32(0) & 0xFFFF;
    u32 b = scrGetParamIntS32(1) & 0xFFFF;
    u32 flag = 1;

    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    scrSetReturnInt(flag != 0);
    return 1;
}

// FUN_001EACA0
/* measured probe: preserve the retail filter branch chain */
#pragma push
/* AI script command 0x20fb (p4flow AI.json AI_FUNCTION_00FB). */
s32 btlEffectScriptFormationMoveUnit(void) {
    extern s32 btlFormationAllocWork(u32 arg0);
    extern void btlFormationCopyRecord(u8 *arg0, u8 *arg1);
    extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
    extern void btlFormationSetPlacement(u8 *arg0);
    extern s32 func_00243ce0(s32 arg0);
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_2;
    u8 *temp_16;
    s32 temp_4;
    u16 temp_3_2;

    temp_16 = (u8 *)btlFormationAllocWork(0);
    temp_4 = scrGetParamIntS32(0) & 0xFFFF;
    temp_4 = temp_4 + 1;
    btlFormationCopyRecord(temp_16, btlFormationGetRecord(temp_4 & 0xFFFF));
    temp_18 = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_17 = *(u8 **)(iGpffffb3ac + 0x180);
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(var_17 + 0xA64);
    if (temp_4 == 0)
        goto loop_advance;
    if (func_00243ce0(temp_4) == 0)
        goto loop_advance;
    temp_3_2 = *(u16 *)(var_17 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x10F:
    case 0x110:
    case 0x111:
        goto loop_advance;
    default:
        goto selected;
    }
loop_advance:
    var_17 = *(u8 **)(var_17 + 0xA6C);
loop_test:
    if (var_17 != NULL)
        goto loop_body;
selected:
    if (var_17 == NULL)
        var_17 = temp_18;
    temp_2 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_18, (u32)var_17, 0, 0x200);
    btlPacketEnqueue(temp_2, 2);
    *(s64 *)(iGpffffb3ac + 0xBD0) = *(s64 *)(temp_2 + 0x58);
    var_17 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_18, (u32)var_17, 1, 0x200);
    btlPacketEnqueue(var_17, 2);
    *(s64 *)(iGpffffb3ac + 0xBD8) = *(s64 *)(var_17 + 0x58);
    btlFormationSetPlacement(temp_16);
    return 1;
}

/* measured probe: close the filter branch chain */
#pragma pop
/* AI script command 0x20fc (p4flow AI.json AI_FUNCTION_00FC). */
// FUN_001EAE30
s32 btlEffectScriptNoHitRecorded(void) {
    s64 mask;
    s32 hit;

    mask = 0x3FFFFFFFFFFFFFFFLL;
    if (btlUnitRecordFindByUID(*(s64 *)(iGpffffb3ac + 0xBD0), mask) != 0)
        return 0;
    hit = btlUnitRecordFindByUID(*(s64 *)(iGpffffb3ac + 0xBD8), mask) != 0;
    return hit ^ 1;
}

/* AI script command 0x20fd (p4flow AI.json AI_FUNCTION_00FD). */
// FUN_001EAEC0
s32 btlEffectScriptApplyToSideUnit(void)
{
    extern u8 *btlEffectFindUnitByIdAndStatus(s64 arg0, s32 arg1, s32 arg2);
    s64 temp_20;
    s64 temp_19;
    s64 temp_18;
    s64 temp_17;
    s64 temp_16;
    s32 var_2;
    u8 *temp_2;

    temp_20 = scrGetParamInt(0);
    temp_19 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    temp_17 = scrGetParamInt(3);
    temp_16 = scrGetParamInt(4);
    if (temp_20 == 0) {
        var_2 = 1;
    } else {
        var_2 = 2;
    }
    temp_2 = btlEffectFindUnitByIdAndStatus(temp_19 & 0xFFFF, var_2 & 0xFFFF, 0x80000);
    if (temp_2 != NULL) {
        func_00198920(*(u8 **)(temp_2 + 0x30), (s16)temp_18, (u16)temp_17, 1.0f, (u16)temp_16);
    }
    return 1;
}

// FUN_001EAFB0
/* measured probe: preserve retail conditional branch shape */
#pragma push
/* measured: btlEffectScriptSetUnitPositionByIndex MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20fe (p4flow AI.json AI_FUNCTION_00FE). */
s32 btlEffectScriptSetUnitPositionByIndex(void) {
    extern void btlTargetPositionToCell();
    extern void btlUnitSetPos();
    extern s64 scrGetParamInt();
    extern f32 scrGetParamFloat();
    f32 sp30[3];
    s32 temp_16;
    s32 temp_17;
    s32 var_2;
    s32 var_4;
    u8 *var_17;

    temp_17 = scrGetParamIntS32(0);
    temp_16 = scrGetParamIntS32(1);
    sp30[0] = scrGetParamFloat(2);
    sp30[1] = scrGetParamFloat(3);
    sp30[2] = scrGetParamFloat(4);
    var_4 = 0;
    if (temp_17 != 0)
        goto set_one;
    var_2 = 0;
    goto select_table;
set_one:
    var_2 = 1;
select_table:
    var_17 = *(u8 **)(p4_slot_001eb320((u32)(var_2 * 8), iGpffffb3ac) + 0x17C);
    goto loop_test;
loop_body:
    if (temp_16 == var_4) {
        btlTargetPositionToCell(var_17 + 0x94, var_17 + 0x96, &sp30[0]);
        btlUnitSetPos(var_17, &sp30[0]);
        goto done;
    }
    var_4 += 1;
    var_17 = (u8 *)(*(u8 **)(var_17 + 0xA68));
loop_test:
    if (var_17 != NULL)
        goto loop_body;
done:
    return 1;
}

/* measured probe: close conditional branch shape */
#pragma pop
/* AI script command 0x20ff (p4flow AI.json AI_FUNCTION_00FF). */
// FUN_001EB0B0
s32 btlEffectScriptFinishPresentation(void) {
    u8 *o;

    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    o = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s16 *)(o + 0x48) = 3;
    btlPacketEnqueue(o, 0);
    return 1;
}

/* AI script command 0x210b (p4flow AI.json AI_FUNCTION_010B). */
// FUN_001EB110
s32 btlEffectScriptEnqueueEventPacket(void) {
    u8 sp20[0x200];
    s64 temp_16;
    s64 temp_2;
    u8 *temp_2_2;

    temp_16 = scrGetParamInt(0);
    temp_2 = scrGetParamInt(1);
    switch (temp_2) {
    case 0:
        temp_2_2 = (u8 *)btlBossCreateStepEndBgmPacket();
        *(s16 *)(temp_2_2 + 0x48) = 2;
        btlPacketEnqueue(temp_2_2, 1);
        break;
    case 1:
        sprintf(&sp20[0], &D_00609E40[0], temp_16);
        btlPacketEnqueue(btlSoundCreateStreamPacket(2, &sp20[0]), 1);
        break;
    }
    return 1;
}

