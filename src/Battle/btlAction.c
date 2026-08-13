/* Source unit: src/Battle/btlAction_001a1100.c */
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

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

typedef struct BtlAction BtlAction;
struct BtlAction
{
    u64 uid;               // 0x00
    u8 _pad08[0x4];        // 0x08
    u16 currState;         // 0x0c
    u16 pendingState;      // 0x0e
    u16 oldState;          // 0x10
    u16 pendingStateTimer; // 0x12
    u16 state;             // 0x14
    u16 _pad16;            // 0x16
    u16 _pad18;            // 0x18
    u16 _pad1a;            // 0x1a
    u32 stateTimer;        // 0x1c
    u8 _pad20[0x10];       // 0x20
    void* unit;            // 0x30
};

extern u32 btlUnitIsMoving(void* unit);
extern void func_00194ff0(void* unit, void* arg1, void* arg2, RwV3d* rot);
extern BtlPacket* btlUnitCreateRotatePacket(void* unit, const RwV3d* rot, u32 flags);
extern void func_00194590(BtlPacket* packet, u32 type);
extern void btlActionSetState(BtlAction* action, u16 state);

#define BTL_UIDMAX 0x3FFFFFFFFFFFFFFF
#define BTLACTION_STATE_START 2

extern BtlPacket* btlPacketFindFirstByActionUID(u64 actionUID, u64 mask);

typedef void (*BtlActionStateFn)(BtlAction* action);
typedef struct BtlActionState {
    BtlActionStateFn init;
    BtlActionStateFn update;
    const char* name;
} BtlActionState;

extern BtlActionState D_005f6e20[];



// FUN_001A1100
void btlActionUpdateStateStartHome(BtlAction* action)
{
    RwV3d rot;
    BtlPacket* packet;

    if (btlUnitIsMoving(action->unit) == 0)
    {
        func_00194ff0(action->unit, NULL, NULL, &rot);

        packet = btlUnitCreateRotatePacket(action->unit, &rot, 0);
        packet->actionUID = action->uid;
        func_00194590(packet, 1);

        btlActionSetState(action, action->state);
    }
}



// FUN_001A1190
void func_001a1190(BtlAction* action)
{
    extern u8* D_0076449C;
    extern f32 fGpffff809c;
    extern void func_001a03b0(BtlAction* action);
    extern BtlPacket* func_001d3900(u16 param_1);
    extern BtlPacket* func_001d3700(u16 param_1, u16 param_2);
    extern BtlPacket* func_001f99c0(BtlAction* action, s32 param_2, s32 param_3,
                                     s32 param_4, s32 param_5);
    extern u32 datCalcChkBadStatus(u32 unit, u32 badStatus);
    extern u32 datCalcIsDead(u32 unit, s32 hpDelta);
    extern BtlPacket* btlUnitCreateMovePacket(void* unit, const RwV3d* targetPos,
                                               f32 speed, u32 flags);
    extern BtlPacket* func_0019beb0(void* unit);
    extern BtlPacket* btlUnitCreateRotateTowardUnitPacket(void* unit,
                                                           void* targetUnit,
                                                           u32 flags);
    extern BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state);

    BtlPacket* rootPacket;
    u8* unit;

    func_001a03b0(action);

    rootPacket = func_001d3900(1);
    rootPacket->actionUID = action->uid;
    func_00194590(rootPacket, 0);

    if (((u8*)action)[0x28] == 0)
    {
        BtlPacket* packet;

        packet = func_001f99c0(action, 19, 0, 0, 0);
        func_00194590(packet, 1);
    }

    unit = *(u8**)(D_0076449C + 0x178);
    while (unit != NULL)
    {
        if (datCalcChkBadStatus(*(u32*)(unit + 0xA64), 0x180017) == 0 &&
            datCalcIsDead(*(u32*)(unit + 0xA64), 0) == 0)
        {
            BtlPacket* packet;

            packet = btlUnitCreateMovePacket(unit, NULL, fGpffff809c, 24);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            func_00194590(packet, 1);
        }

        unit = *(u8**)(unit + 0xA6C);
    }

    {
        BtlPacket* packet;

        packet = func_001d3700(2, 1);
        *(u8*)packet = 4;
        *(u64*)((u8*)packet + 8) = rootPacket->unk58;
        packet->actionUID = action->uid;
        func_00194590(packet, 0);
    }

    unit = *(u8**)(D_0076449C + 0x180);
    while (unit != NULL)
    {
        if (datCalcIsDead(*(u32*)(unit + 0xA64), 0) != 0)
        {
            BtlPacket* packet;

            packet = func_0019beb0(unit);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            func_00194590(packet, 0);
        }
        else
        {
            BtlPacket* packet;

            packet = btlUnitCreateRotateTowardUnitPacket(
                unit, action->unit, 34);
            *(u8*)packet = 4;
            *(u64*)((u8*)packet + 8) = rootPacket->unk58;
            packet->actionUID = action->uid;
            func_00194590(packet, 0);
        }

        unit = *(u8**)(unit + 0xA6C);
    }

    {
        BtlPacket* packet;

        packet = btlCameraCreateSetStatePacket(action, 41);
        *(u8*)packet = 4;
        *(u64*)((u8*)packet + 8) = rootPacket->unk58;
        packet->actionUID = action->uid;
        func_00194590(packet, 0);
    }
}
// FUN_001A13E0
void btlActionUpdateStateChangeFormation(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        btlActionSetState(action, BTLACTION_STATE_START);
    }
}



// FUN_001B07D0
void btlActionUpdateStateTest(BtlAction* action)
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
