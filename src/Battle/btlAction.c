/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001A1100)
/* Source unit: src/Battle/btlAction_001a1100.c */
#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x60];
    u64 actionUID;
};

typedef struct BtlAction BtlAction;
struct BtlAction
{
    u64 uid;
    u8 _pad08[0xc];
    u16 state;
    u8 _pad16[0x1a];
    void* unit;
};

extern u32 func_00196b50(void* unit);
extern void func_00194ff0(void* unit, void* arg1, void* arg2, RwV3d* rot);
extern BtlPacket* func_00197f50(void* unit, const RwV3d* rot, u32 flags);
extern void func_00194590(BtlPacket* packet, u32 type);
extern void func_001b0800(BtlAction* action, u16 state);

// FUN_001A1100
void func_001a1100(BtlAction* action)
{
    RwV3d rot;
    BtlPacket* packet;

    if (func_00196b50(action->unit) == 0)
    {
        func_00194ff0(action->unit, NULL, NULL, &rot);

        packet = func_00197f50(action->unit, &rot, 0);
        packet->actionUID = action->uid;
        func_00194590(packet, 1);

        func_001b0800(action, action->state);
    }
}
#endif /* P4_UNIT_001A1100 */

#if defined(P4_UNIT_001B07D0)
/* Source unit: src/Battle/btlAction_001b07d0.c */
#include "type.h"

typedef struct BtlAction BtlAction;

void btlActionSetState(BtlAction* action, u16 state);

// FUN_001B07D0
void btlActionUpdateStateTest(BtlAction* action)
{
    btlActionSetState(action, 5);
}
#endif /* P4_UNIT_001B07D0 */

#if defined(P4_UNIT_001B0800)
/* Source unit: src/Battle/btlAction_001b0800.c */
#include "type.h"

typedef struct BtlAction {
    u8 padding_00[0x0c];
    u16 currState;
    u16 pendingState;
    u16 oldState;
    u16 pendingStateTimer;
    u8 padding_14[8];
    u32 stateTimer;
} BtlAction;

typedef void (*BtlActionStateFn)(BtlAction* action);
typedef struct BtlActionState {
    BtlActionStateFn init;
    BtlActionStateFn update;
    const char* name;
} BtlActionState;

extern BtlActionState D_005f6e20[];

// FUN_001B0800
void btlActionSetState(BtlAction* action, u16 state)
{
    action->oldState = action->currState;
    action->currState = state;
    action->stateTimer = 0;

    D_005f6e20[state].init(action);
}
#endif /* P4_UNIT_001B0800 */

#if defined(P4_UNIT_001B0850)
/* Source unit: src/Battle/btlAction_001b0850.c */
#include "type.h"

typedef struct BtlAction {
    u8 padding_00[0x0c];
    u16 currState;
    u16 pendingState;
    u16 oldState;
    u16 pendingStateTimer;
    u8 padding_14[8];
    u32 stateTimer;
} BtlAction;

typedef void (*BtlActionStateFn)(BtlAction* action);
typedef struct BtlActionState {
    BtlActionStateFn init;
    BtlActionStateFn update;
    const char* name;
} BtlActionState;

extern BtlActionState D_005f6e20[];

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
#endif /* P4_UNIT_001B0850 */

#if defined(P4_UNIT_001B08D0)
/* Source unit: src/Battle/btlAction_001b08d0.c */
#include "type.h"

// FUN_001B08D0
void func_001b08d0(void* action)
{
    *(u16*)((u8*)action + 0x18) |= 1;
}
#endif /* P4_UNIT_001B08D0 */

#if defined(P4_UNIT_001B08F0)
/* Source unit: src/Battle/btlAction_001b08f0.c */
#include "type.h"

// FUN_001B08F0
void func_001b08f0(void* action)
{
    *(u16*)((u8*)action + 0x18) &= ~1;
}
#endif /* P4_UNIT_001B08F0 */

#if defined(P4_UNIT_001B0910)
/* Source unit: src/Battle/btlAction_001b0910.c */
#include "type.h"

// FUN_001B0910
void func_001b0910(void* action, void* unit)
{
    *(void**)((u8*)action + 0x30) = unit;
    *(u16*)((u8*)action + 0x1A) |= 1;
}
#endif /* P4_UNIT_001B0910 */
