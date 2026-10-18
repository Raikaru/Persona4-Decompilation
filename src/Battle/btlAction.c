#include "datCalc_internal.h"
/* Source unit: src/Battle/btlAction_001a1100.c */
#include "include_asm.h"
#include "type.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"

extern u32 btlUnitIsMoving(void* unit);
extern void btlUnitGetAnchorPose(void* unit, void* arg1, void* arg2, RwV3d* rot);
extern BtlPacket* btlUnitCreateRotatePacket(void* unit, const RwV3d* rot, u32 flags);
extern void btlPacketEnqueue(BtlPacket* packet, u32 type);
extern void btlActionSetState(BtlAction* action, u16 state);

#define BTL_UIDMAX 0x3FFFFFFFFFFFFFFF
#define BTLACTION_STATE_START 2

extern BtlPacket* btlPacketFindFirstByActionUID(u64 actionUID, u64 mask);



/* Wait for movement to finish, restore the anchor rotation, and resume the action state. */
// FUN_001A1100
void btlActionStartHomeUpdate(BtlAction* action)
{
    RwV3d rot;
    BtlPacket* packet;

    if (btlUnitIsMoving(action->unit) == 0)
    {
        btlUnitGetAnchorPose(action->unit, NULL, NULL, &rot);

        packet = btlUnitCreateRotatePacket(action->unit, &rot, 0);
        packet->actionUID = action->uid;
        btlPacketEnqueue(packet, 1);

        btlActionSetState(action, action->state);
    }
}



/* Queue formation return and dependent movement, cleanup, rotation and camera packets. */
// FUN_001A1190
void btlActionChangeFormationInit(BtlAction* action)
{
    extern u8* D_0076449C;
    extern f32 fGpffff809c;
    extern void btlActionFinishPresentation(BtlAction* action);
    extern BtlPacket* btlFormationCreateReturnPacket(u16 mode);
    extern BtlPacket* btlFormationCreateSlotPacket(u16 mode, u16 kind);
    extern BtlPacket* func_001f99c0(BtlAction* action, u16 kind, s32 firstValue,
                                     s32 secondValue, s32 thirdValue);
    extern BtlPacket* btlUnitCreateMovePacket(void* unit, const RwV3d* targetPos,
                                               f32 speed, u32 flags);
    extern BtlPacket* btlUnitCreateResourceFreePacket(void* unit);
    extern BtlPacket* btlUnitCreateRotateTowardUnitPacket(void* unit,
                                                           void* targetUnit,
                                                           u32 flags);
    extern BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state);

    BtlPacket* rootPacket;
    BtlUnit* unit;

    btlActionFinishPresentation(action);

    rootPacket = btlFormationCreateReturnPacket(1);
    rootPacket->actionUID = action->uid;
    btlPacketEnqueue(rootPacket, 0);

    if (action->unk_28 == 0)
    {
        BtlPacket* packet;

        packet = func_001f99c0(action, 19, 0, 0, 0);
        btlPacketEnqueue(packet, 1);
    }

    unit = (BtlUnit *)((BtlBattleState *)D_0076449C)->unitLists[0];
    while (unit != NULL)
    {
        if (datCalcChkBadStatus(unit->datUnit, 0x180017) == 0 &&
            datCalcIsDead(unit->datUnit, 0) == 0)
        {
            BtlPacket* packet;

            packet = btlUnitCreateMovePacket(unit, NULL, fGpffff809c, 24);
            packet->dependencyKind = 4;
            packet->dependencyUID = rootPacket->uid;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 1);
        }

        unit = unit->nextUnit;
    }

    {
        BtlPacket* packet;

        packet = btlFormationCreateSlotPacket(2, 1);
        packet->dependencyKind = 4;
        packet->dependencyUID = rootPacket->uid;
        packet->actionUID = action->uid;
        btlPacketEnqueue(packet, 0);
    }

    unit = (BtlUnit *)((BtlBattleState *)D_0076449C)->unitLists[2];
    while (unit != NULL)
    {
        if (datCalcIsDead(unit->datUnit, 0) != 0)
        {
            BtlPacket* packet;

            packet = btlUnitCreateResourceFreePacket(unit);
            packet->dependencyKind = 4;
            packet->dependencyUID = rootPacket->uid;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 0);
        }
        else
        {
            BtlPacket* packet;

            packet = btlUnitCreateRotateTowardUnitPacket(
                unit, action->unit, 34);
            packet->dependencyKind = 4;
            packet->dependencyUID = rootPacket->uid;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 0);
        }

        unit = unit->nextUnit;
    }

    {
        BtlPacket* packet;

        packet = btlCameraCreateSetStatePacket(action, 41);
        packet->dependencyKind = 4;
        packet->dependencyUID = rootPacket->uid;
        packet->actionUID = action->uid;
        btlPacketEnqueue(packet, 0);
    }
}
/* Resume the start phase after every packet owned by this action completes. */
// FUN_001A13E0
void btlActionChangeFormationUpdate(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        btlActionSetState(action, BTLACTION_STATE_START);
    }
}



u8 *btlUnitRecordFindByActionUID(u64 actionUID, u64 mask);
/* Wait for persona records to finish, clear the party presentation flag, and resume. */
// FUN_001ADE10
void btlActionPersonaUpdate(BtlAction *action)
{
    if (btlUnitRecordFindByActionUID((s64)action->uid, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        if (action->unit->genus == 0) {
            action->flags &= 0xFBFF;
        }
        btlActionSetState(action, action->state);
    }
}


// FUN_001B07D0
void btlActionTestUpdate(BtlAction* action)
{
    btlActionSetState(action, 5);
}



/* Record the previous state, reset elapsed time and invoke the new state initializer. */
// FUN_001B0800
void btlActionSetState(BtlAction* action, u16 state)
{
    action->oldState = action->currState;
    action->currState = state;
    action->stateTimer = 0;

    D_005f6e20[state].init(action);
}



/* Schedule a delayed transition, or perform it immediately when delay is zero. */
// FUN_001B0850
void btlActionSetStateWithDelay(BtlAction* action, u16 state, u16 delay)
{
    if (delay == 0)
    {
        action->pendingState = 0;
        action->pendingStateTimer = 0;
        action->oldState = action->currState;
        action->currState = state;
        action->stateTimer = 0;

        D_005f6e20[state].init(action);
        return;
    }

    action->pendingState = state;
    action->pendingStateTimer = delay;
}



// FUN_001B08D0
void btlActionSetCallbackPending(void* action)
{
    ((BtlAction *)action)->flags |= 1;
}



// FUN_001B08F0
void btlActionClearCallbackPending(void* action)
{
    ((BtlAction *)action)->flags &= ~1;
}



/* Attach the unit and mark this action as owning a valid unit. */
// FUN_001B0910
void btlActionSetUnit(void* action, void* unit)
{
    ((BtlAction *)action)->unit = unit;
    ((BtlAction *)action)->unk_1a |= 1;
}
