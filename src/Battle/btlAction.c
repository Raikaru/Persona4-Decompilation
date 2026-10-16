#include "datCalc_internal.h"
/* Source unit: src/Battle/btlAction_001a1100.c */
#include "include_asm.h"
#include "type.h"
#include "btl_action_internal.h"

typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x58];
    u64 unk58;                 // 0x58
    u64 actionUID;             // 0x60
    BtlPacketFunc initFunc;    // 0x68
    BtlPacketFunc updateFunc;  // 0x6c
    BtlPacketFunc destroyFunc; // 0x70
    u8 _pad74[4];              // 0x74
    void* workData;            // 0x78
};

extern u32 btlUnitIsMoving(void* unit);
extern void btlUnitGetAnchorPose(void* unit, void* arg1, void* arg2, RwV3d* rot);
extern BtlPacket* btlUnitCreateRotatePacket(void* unit, const RwV3d* rot, u32 flags);
extern void btlPacketEnqueue(BtlPacket* packet, u32 type);
extern void btlActionSetState(BtlAction* action, u16 state);

#define BTL_UIDMAX 0x3FFFFFFFFFFFFFFF
#define BTLACTION_STATE_START 2

extern BtlPacket* btlPacketFindFirstByActionUID(u64 actionUID, u64 mask);



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



// FUN_001A1190
void btlActionChangeFormationInit(BtlAction* action)
{
    extern u8* D_0076449C;
    extern f32 fGpffff809c;
    extern void btlActionFinishPresentation(BtlAction* action);
    extern BtlPacket* btlFormationCreateReturnPacket(u16 param_1);
    extern BtlPacket* btlFormationCreateSlotPacket(u16 param_1, u16 param_2);
    extern BtlPacket* func_001f99c0(BtlAction* action, u16 param_2, s32 param_3,
                                     s32 param_4, s32 param_5);
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

    if (((u8*)action)[0x28] == 0)
    {
        BtlPacket* packet;

        packet = func_001f99c0(action, 19, 0, 0, 0);
        btlPacketEnqueue(packet, 1);
    }

    unit = *(BtlUnit**)(D_0076449C + 0x178);
    while (unit != NULL)
    {
        if (datCalcChkBadStatus(unit->datUnit, 0x180017) == 0 &&
            datCalcIsDead(unit->datUnit, 0) == 0)
        {
            BtlPacket* packet;

            packet = btlUnitCreateMovePacket(unit, NULL, fGpffff809c, 24);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 1);
        }

        unit = unit->nextUnit;
    }

    {
        BtlPacket* packet;

        packet = btlFormationCreateSlotPacket(2, 1);
        *(u8*)packet = 4;
        *(u64*)((u8*)packet + 8) = rootPacket->unk58;
        packet->actionUID = action->uid;
        btlPacketEnqueue(packet, 0);
    }

    unit = *(BtlUnit**)(D_0076449C + 0x180);
    while (unit != NULL)
    {
        if (datCalcIsDead(unit->datUnit, 0) != 0)
        {
            BtlPacket* packet;

            packet = btlUnitCreateResourceFreePacket(unit);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 0);
        }
        else
        {
            BtlPacket* packet;

            packet = btlUnitCreateRotateTowardUnitPacket(
                unit, action->unit, 34);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            btlPacketEnqueue(packet, 0);
        }

        unit = unit->nextUnit;
    }

    {
        BtlPacket* packet;

        packet = btlCameraCreateSetStatePacket(action, 41);
        *(u8*)packet = 4;
        *(u64*)((u8*)packet + 8) = rootPacket->unk58;
        packet->actionUID = action->uid;
        btlPacketEnqueue(packet, 0);
    }
}
// FUN_001A13E0
void btlActionChangeFormationUpdate(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        btlActionSetState(action, BTLACTION_STATE_START);
    }
}



// FUN_001B07D0
void btlActionTestUpdate(BtlAction* action)
{
    btlActionSetState(action, 5);
}



// FUN_001B0800
void btlActionSetState(BtlAction* action, u16 state)
{
    action->oldState = action->currState;
    action->currState = state;
    action->stateTimer = 0;

    D_005f6e20[state].init(action);
}



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
void func_001b08d0(void* action)
{
    *(u16*)((u8*)action + 0x18) |= 1;
}



// FUN_001B08F0
void func_001b08f0(void* action)
{
    *(u16*)((u8*)action + 0x18) &= ~1;
}



// FUN_001B0910
void btlActionSetUnit(void* action, void* unit)
{
    *(void**)((u8*)action + 0x30) = unit;
    *(u16*)((u8*)action + 0x1A) |= 1;
}
