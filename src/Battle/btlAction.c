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
    u8 _pad00[0x60];
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
INCLUDE_ASM("asm/nonmatchings/btlAction", func_001a1190);
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
