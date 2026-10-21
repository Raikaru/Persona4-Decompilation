#include "byte_address_internal.h"
#include "btl_target_internal.h"
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
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);


extern u8 *btlActionGetActiveOrQueueFront(void);

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void btlEncounterEntrySetRetracted(s32 task);
extern void btlEncounterEntryClearRetracted(s32 task);
extern s32 btlTargetCanControlDamagePhase(void);
extern void btlDamageSetSource(u8 *, s32);
extern s32 D_00724504;
extern void btlTargetEndDamagePhase(void);
extern s32 btlTargetCanControlDamagePhase(void);
extern void btlActionFinishPresentation(s32);
extern BtlPacket *btlFormationCreateSlotPacket(u16, u16);
extern u8 *btlEffectFindUnitByIdAndStatus();


extern void btlPacketEnqueue(u8 *, s32);
extern s32 btlUnitRecordFindByUID(s64, s64);
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
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern BtlPacket *btlBossCreateStepEndBgmPacket(void);
extern u8 *btlSoundCreateStreamPacket(s32, void *);
extern void sprintf(void *, void *, s64);
extern u8 D_00609E40[];
extern u8 *btlFormationGetRecord(s32);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

extern void btlTargetEndDamagePhase(void);
extern s32 btlTargetCanControlDamagePhase(void);
#pragma push
#pragma pop
/* Set flag 0x2000 on the battle state if the current target can control the damage phase. */
// FUN_001EAA80
s32 btlEffectScriptSetBattleFlag2000(void) {
    if (btlTargetCanControlDamagePhase() == 1) {
        ((BtlBattleState *)iGpffffb3ac)->flags |= 0x2000;
    }
    return 1;
}

/* Clear flag 0x2000 on the battle state and end the damage phase if the current target can control
 * it. */
// FUN_001EAAC0
s32 btlEffectScriptClearBattleFlag2000(void)
{
    u8 *battle;

    if (btlTargetCanControlDamagePhase() == 1) {
        battle = iGpffffb3ac;
        ((BtlBattleState *)battle)->flags = (s32)(((BtlBattleState *)battle)->flags) & ~0x2000;
        btlTargetEndDamagePhase();
    }
    return 1;
}

/* Clear the retracted state of the battle UI task's encounter entry, then mark it as the damage
 * source if the target can control the damage phase. */
// FUN_001EAB10
s32 btlEffectScriptSetDamageSourceOn(void) {
    btlEncounterEntryClearRetracted(((BtlBattleState *)iGpffffb3ac)->uiTask);
    if (btlTargetCanControlDamagePhase() == 1) {
        btlDamageSetSource((u8 *)(((BtlBattleState *)iGpffffb3ac)->uiTask), 1);
    }
    return 1;
}

/* Mark the battle UI task's encounter entry as retracted and, when the target is allowed to control
 * the damage phase, clear its damage source. */
// FUN_001EAB60
s32 btlEffectScriptSetDamageSourceOff(void) {
    btlEncounterEntrySetRetracted(((BtlBattleState *)iGpffffb3ac)->uiTask);
    if (btlTargetCanControlDamagePhase() == 1) {
        btlDamageSetSource((u8 *)(((BtlBattleState *)iGpffffb3ac)->uiTask), 0);
    }
    return 1;
}

/* Return true to the script when the active action's unit matches the requested side (genus) and
 * character ID. A side value other than 0 or 1 skips the side check. */
// FUN_001EABC0
s32 btlEffectScriptCheckSideAndId(void) {
    u8 *p = btlActionGetActiveOrQueueFront();
    u32 a = scrGetParamIntS32(0) & 0xFFFF;
    u32 b = scrGetParamIntS32(1) & 0xFFFF;
    u32 flag = 1;

    switch (a & 0xFFFF) {
    case 0:
        if (((BtlUnit *)((u8 *)(((BtlAction *)p)->unit)))->genus != 0)
            flag = 0;
        break;
    case 1:
        if (((BtlUnit *)((u8 *)(((BtlAction *)p)->unit)))->genus != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && ((BtlUnit *)((u8 *)(((BtlAction *)p)->unit)))->charId != (b & 0xFFFF))
        flag = 0;
    scrSetReturnInt(flag != 0);
    return 1;
}

/* Queue both formation moves for the first eligible enemy, falling back to the acting unit. */
// FUN_001EACA0
/* measured: retail keeps the filter conditions as a separate branch chain. */
#pragma push
s32 btlEffectScriptFormationMoveUnit(void) {
    extern s32 btlFormationAllocWork(u32);
    extern void btlFormationCopyRecord(u8 *, u8 *);
    extern BtlPacket *btlFormationCreatePacket(u32, u32, u32, u16, u32);
    extern void btlFormationSetPlacement(u8 *);
    extern s32 datCalcEnemyHasTableFlag(s32);
    u8 *actor;
    u8 *candidate;
    u8 *packet;
    u8 *formation;
    s32 value;
    u16 unitId;

    formation = (u8 *)btlFormationAllocWork(0);
    value = scrGetParamIntS32(0) & 0xFFFF;
    value = value + 1;
    btlFormationCopyRecord(formation, btlFormationGetRecord(value & 0xFFFF));
    actor = (u8 *)(((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit);
    candidate = ((BtlBattleState *)iGpffffb3ac)->unitLists[2];
    goto loop_test;
loop_body:
    value = (s32)(((BtlUnit *)candidate)->datUnit);
    if (value == 0)
        goto loop_advance;
    if (datCalcEnemyHasTableFlag(value) == 0)
        goto loop_advance;
    unitId = ((BtlUnit *)candidate)->charId;
    switch (unitId) {
    case 0x10D:
    case 0x10F:
    case 0x110:
    case 0x111:
        goto loop_advance;
    default:
        goto selected;
    }
loop_advance:
    candidate = (u8 *)(((BtlUnit *)candidate)->nextUnit);
loop_test:
    if (candidate != NULL)
        goto loop_body;
selected:
    if (candidate == NULL)
        candidate = actor;
    packet = (u8 *)btlFormationCreatePacket((u32)formation, (u32)actor, (u32)candidate, 0, 0x200);
    btlPacketEnqueue(packet, 2);
    ((BtlTargetFormationPackets *)(iGpffffb3ac + 0xBD0))->firstUID = (s64)(((BtlPacket *)packet)->uid);
    candidate = (u8 *)btlFormationCreatePacket((u32)formation, (u32)actor, (u32)candidate, 1, 0x200);
    btlPacketEnqueue(candidate, 2);
    ((BtlTargetFormationPackets *)(iGpffffb3ac + 0xBD0))->secondUID = (s64)((BtlPacket *)candidate)->uid;
    btlFormationSetPlacement(formation);
    return 1;
}

#pragma pop
/* Return 1 when neither the first nor the second UID in the target formation packets has a unit
 * record, and 0 otherwise. */
// FUN_001EAE30
s32 btlEffectScriptNoHitRecorded(void) {
    s64 mask;
    s32 hit;

    mask = 0x3FFFFFFFFFFFFFFFLL;
    if (btlUnitRecordFindByUID(((BtlTargetFormationPackets *)(iGpffffb3ac + 0xBD0))->firstUID, mask) != 0)
        return 0;
    hit = btlUnitRecordFindByUID(((BtlTargetFormationPackets *)(iGpffffb3ac + 0xBD0))->secondUID, mask) != 0;
    return hit ^ 1;
}

/* Find the unit with the given ID on the chosen side and play the requested motion on it with the
 * script-supplied options. */
// FUN_001EAEC0
s32 btlEffectScriptApplyToSideUnit(void)
{
    extern u8 *btlEffectFindUnitByIdAndStatus(s64, s32, s32);
    s64 side;
    s64 unitId;
    s64 motion;
    s64 motionOption;
    s64 option;
    s32 sideMask;
    u8 *action;

    side = scrGetParamInt(0);
    unitId = scrGetParamInt(1);
    motion = scrGetParamInt(2);
    motionOption = scrGetParamInt(3);
    option = scrGetParamInt(4);
    if (side == 0) {
        sideMask = 1;
    } else {
        sideMask = 2;
    }
    action = btlEffectFindUnitByIdAndStatus(unitId & 0xFFFF, sideMask & 0xFFFF, 0x80000);
    if (action != NULL) {
        btlUnitSetMotion((u8 *)(((BtlAction *)action)->unit), (s16)motion, (u16)motionOption, 1.0f, (u16)option);
    }
    return 1;
}

/* Set one indexed side-list unit position and update its rounded grid coordinates. */
#pragma push
/* measured: retail keeps the explicit if/else branch shape; a switch or rebuilt conditionals
 * produce different code. */
#pragma opt_rebuildconditionals off
// FUN_001EAFB0
s32 btlEffectScriptSetUnitPositionByIndex(void) {
    extern void btlTargetPositionToCell();
    extern void btlUnitSetPos();
    extern s64 scrGetParamInt();
    extern f32 scrGetParamFloat();
    f32 position[3];
    s32 selectedIndex;
    s32 side;
    s32 listIndex;
    s32 unitIndex;
    u8 *unit;

    side = scrGetParamIntS32(0);
    selectedIndex = scrGetParamIntS32(1);
    position[0] = scrGetParamFloat(2);
    position[1] = scrGetParamFloat(3);
    position[2] = scrGetParamFloat(4);
    unitIndex = 0;
    if (side != 0)
        goto set_one;
    listIndex = 0;
    goto select_table;
set_one:
    listIndex = 1;
select_table:
    unit = ((BtlBattleState *)byteAddressAdd((u32)(listIndex * 8), (u8 *)(iGpffffb3ac)))->unitLists[1];
    goto loop_test;
loop_body:
    if (selectedIndex == unitIndex) {
        btlTargetPositionToCell(unit + 0x94, unit + 0x96, &position[0]);
        btlUnitSetPos(unit, &position[0]);
        goto done;
    }
    unitIndex += 1;
    unit = (u8 *)(((BtlUnit *)unit)->prevUnit);
loop_test:
    if (unit != NULL)
        goto loop_body;
done:
    return 1;
}

#pragma pop
/* Finish the selected action's presentation, then queue a formation slot packet with a delay of 3. */
// FUN_001EB0B0
s32 btlEffectScriptFinishPresentation(void) {
    u8 *o;

    btlActionFinishPresentation((s32)(((BtlBattleState *)iGpffffb3ac)->selectedAction));
    o = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    ((BtlPacket *)o)->delay = 3;
    btlPacketEnqueue(o, 0);
    return 1;
}

/* AI script command that queues a battle event packet: kind 0 queues a boss step-end BGM packet,
 * and kind 1 queues a sound stream packet built from the given stream id. */
// FUN_001EB110
s32 btlEffectScriptEnqueueEventPacket(void) {
    u8 path[0x200];
    s64 streamId;
    s64 kind;
    u8 *packet;

    streamId = scrGetParamInt(0);
    kind = scrGetParamInt(1);
    switch (kind) {
    case 0:
        packet = (u8 *)btlBossCreateStepEndBgmPacket();
        ((BtlPacket *)packet)->delay = 2;
        btlPacketEnqueue(packet, 1);
        break;
    case 1:
        sprintf(&path[0], &D_00609E40[0], streamId);
        btlPacketEnqueue(btlSoundCreateStreamPacket(2, &path[0]), 1);
        break;
    }
    return 1;
}

