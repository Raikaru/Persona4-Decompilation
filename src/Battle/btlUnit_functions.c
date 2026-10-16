#include "btl_motion_internal.h"
/* Source unit: src/Battle/btlUnit_00198300.c */
#include "include_asm.h"
#include "type.h"

typedef struct BtlUnit BtlUnit;
typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;
typedef struct RotateTowardUnitWork {
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u32 flags;
    u32 timer;
} RotateTowardUnitWork;

BtlPacket* btlPacketAlloc(u32 type, u32 workSize);
u32 btlUnitHoldPendingPair(void* work);
u32 btlUnitRotateTowardUnitPacketUpdate(void* work);
u32 btlUnitReleasePendingPair(void* work);
typedef struct BtlUnitPacket {
    BtlUnit* unit;
    s16 value;
    u8 padding_06[2];
} BtlUnitPacket;
u32 btlUnitHoldPendingMotionRequest(void* work);
u32 btlUnitReleasePendingMotionRequest(void* work);
typedef struct BtlUnitPacketResNullifiedAnim {
    BtlUnit* unit;
    f32 value;
    u32 padding_08;
} BtlUnitPacketResNullifiedAnim;
u32 btlUnitHoldPendingResNullified(void* work);
u32 btlUnitResNullifiedPacketUpdate(void* work);
u32 btlUnitReleasePendingResNullified(void* work);
typedef struct BtlUnitMotionWork {
    f32 position[3];
    BtlUnit* unit;
    s16 value;
    s16 counter;
    f32 phase;
} BtlUnitMotionWork;
u32 btlUnitHoldPendingUnit(void* work);
u32 btlUnitPacketArcOffsetUpdate(void* work);
u32 btlUnitReleasePendingUnit(void* work);
typedef struct BtlUnitPacketEnmDodgeAnim {
    BtlUnit* unit;
    s32 value;
    u8 padding_08[8];
} BtlUnitPacketEnmDodgeAnim;
u32 btlUnitHoldPendingEnemyDodge(void* work);
u32 btlUnitEnemyDodgePacketUpdate(void* work);
u32 btlUnitReleasePendingEnemyDodge(void* work);
u32 btlUnitHoldPendingMotionSettle(void* work);
u32 btlUnitMotionSettlePacketUpdate(void* work);
u32 btlUnitReleasePendingMotionSettle(void* work);
u32 btlUnitHoldPendingModelFrame(void* work);
u32 btlUnitModelFramePacketUpdate(void* work);
u32 btlUnitReleasePendingModelFrame(void* work);
typedef struct BtlUnitSpeedWork {
    BtlUnit* unit;
    u16 value;
    u8 padding_06[2];
    f32 speed;
    u16 mode;
    u8 padding_0e[2];
} BtlUnitSpeedWork;
u32 btlUnitHoldPendingMotionSpeed(void* work);
u32 btlUnitReleasePendingMotionSpeed(void* work);
u32 btlUnitHoldPendingModelRelease(void* work);
u32 btlUnitModelReleasePacketUpdate(void* work);
u32 btlUnitReleasePendingModelRelease(void* work);
typedef struct BtlUnitColorWork {
    BtlUnit* unit;
    u32 startColor;
    u32 targetColor;
    s16 startFrame;
    s16 duration;
    u8 mode;
    u8 flags;
    s16 counter;
} BtlUnitColorWork;
u32 func_0019b710(void* work);
u32 func_0019b730(void* work);
u32 func_0019bbc0(void* work);
u32 btlUnitHoldPendingShow(void* work);
u32 btlUnitShowPacketUpdate(void* work);
u32 btlUnitReleasePendingShow(void* work);
u32 btlUnitHoldPendingHide(void* work);
u32 btlUnitHidePacketUpdate(void* work);
u32 btlUnitReleasePendingHide(void* work);
struct BtlUnit {
    u8 padding_00[0x98];
    u32 flags2;
    u32 flags3;
    u8 padding_a0[2];
    u8 genus;
    u8 padding_a3[0xd];
    s16 lookAtMode;
    u8 padding_b2[0x94e];
    void* mdl;
    u8 padding_a04[0x64];
    struct BtlUnit* prev;
};
typedef struct BtlUnitResourceWork {
    BtlUnit* unit;
    u16 type;
    u16 id;
    u16 flags;
    u8 padding_0a[2];
    u32 state;
} BtlUnitResourceWork;
u32 btlUnitResourceLoadPacketInit(void* work);
u32 btlUnitResourceLoadPacketUpdate(void* work);
u32 btlUnitReleasePendingResourceLoad(void* work);
typedef struct LookAtUnitWork {
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u16 flags;
    u8 padding_0a[2];
} LookAtUnitWork;
u32 btlUnitHoldPendingLookAtUnits(void* work);
u32 btlUnitLookAtUnitPacketUpdate(void* work);
u32 btlUnitReleasePendingLookAtUnits(void* work);
typedef struct BtlUnitPacketLookAtDeactivate {
    BtlUnit* unit;
    u16 flags;
    u8 padding_06[2];
} BtlUnitPacketLookAtDeactivate;
u32 func_0019e5d0(void* work);
u32 func_0019e5f0(void* work);
u32 func_0019e7a0(void* work);

typedef struct BattleUnit {
    u8 pad[0xa0];
    u16 pendingPacketCount;
} BattleUnit;

typedef struct RotateTowardUnitPacket {
    BattleUnit* unit;
    BattleUnit* targetUnit;
} RotateTowardUnitPacket;



// FUN_00198300
BtlPacket* btlUnitCreateRotateTowardUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u32 flags)
{
    BtlPacket* packet;
    RotateTowardUnitWork* work;

    packet = btlPacketAlloc(0x10e, sizeof(RotateTowardUnitWork));
    packet->initFunc = btlUnitHoldPendingPair;
    packet->updateFunc = btlUnitRotateTowardUnitPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingPair;
    work = (RotateTowardUnitWork*)packet->workData;
    work->unit = unit;
    work->targetUnit = targetUnit;
    work->flags = flags;

    return packet;
}



// FUN_0019A0C0
BtlPacket* btlUnitCreateMotionRequestPacket(BtlUnit* unit, u16 value)
{
    BtlPacket* packet;
    BtlUnitPacket* work;

    packet = btlPacketAlloc(0x104, sizeof(BtlUnitPacket));
    packet->initFunc = btlUnitHoldPendingMotionRequest;
    packet->updateFunc = btlUnitMotionRequestPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingMotionRequest;
    work = (BtlUnitPacket*)packet->workData;
    work->unit = unit;
    work->value = value;

    return packet;
}



// FUN_0019A2E0
BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 value)
{
    BtlPacket* packet;
    BtlUnitPacketResNullifiedAnim* work;

    packet = btlPacketAlloc(0x107, sizeof(BtlUnitPacketResNullifiedAnim));
    packet->initFunc = btlUnitHoldPendingResNullified;
    packet->updateFunc = btlUnitResNullifiedPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingResNullified;
    work = (BtlUnitPacketResNullifiedAnim*)packet->workData;
    work->unit = unit;
    work->value = value;

    return packet;
}



// FUN_0019A5E0
BtlPacket* btlUnitCreateArcOffsetPacket(BtlUnit* unit, s32 value)
{
    BtlPacket* packet;
    BtlUnitMotionWork* work;

    packet = btlPacketAlloc(0x108, sizeof(BtlUnitMotionWork));
    packet->initFunc = btlUnitHoldPendingUnit;
    packet->updateFunc = btlUnitPacketArcOffsetUpdate;
    packet->destroyFunc = btlUnitReleasePendingUnit;
    work = (BtlUnitMotionWork*)packet->workData;
    work->unit = unit;
    work->value = value;
    work->counter = 0;

    return packet;
}



// FUN_0019A860
BtlPacket* btlUnitCreateEnemyDodgePacket(BtlUnit* unit, s32 unused)
{
    BtlPacket* packet;
    BtlUnitPacketEnmDodgeAnim* work;

    packet = btlPacketAlloc(0x109, sizeof(BtlUnitPacketEnmDodgeAnim));
    packet->initFunc = btlUnitHoldPendingEnemyDodge;
    packet->updateFunc = btlUnitEnemyDodgePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingEnemyDodge;
    work = (BtlUnitPacketEnmDodgeAnim*)packet->workData;
    work->unit = unit;
    work->value = 0;

    return packet;
}



// FUN_0019A980
BtlPacket* btlUnitCreateMotionSettlePacket(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x105, sizeof(BtlUnit*));
    packet->initFunc = btlUnitHoldPendingMotionSettle;
    packet->updateFunc = btlUnitMotionSettlePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingMotionSettle;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019AA70
BtlPacket* btlUnitCreateModelFramePacket(BtlUnit* unit, s16 value)
{
    BtlPacket* packet;
    BtlUnitPacket* work;

    packet = btlPacketAlloc(0x102, sizeof(BtlUnitPacket));
    packet->initFunc = btlUnitHoldPendingModelFrame;
    packet->updateFunc = btlUnitModelFramePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingModelFrame;
    work = (BtlUnitPacket*)packet->workData;
    work->unit = unit;
    work->value = value;

    return packet;
}



// FUN_0019AC40
BtlPacket* btlUnitCreateMotionSpeedPacket(BtlUnit* unit, u16 value, f32 speed, u16 mode)
{
    BtlPacket* packet;
    BtlUnitSpeedWork* work;

    packet = btlPacketAlloc(0x103, sizeof(BtlUnitSpeedWork));
    packet->initFunc = btlUnitHoldPendingMotionSpeed;
    packet->updateFunc = btlUnitMotionSpeedPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingMotionSpeed;
    work = (BtlUnitSpeedWork*)packet->workData;
    work->unit = unit;
    work->value = value;
    work->speed = speed;
    work->mode = mode;

    return packet;
}



// FUN_0019B6A0
BtlPacket* btlUnitCreateModelReleasePacket(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x110, sizeof(BtlUnit*));
    packet->flags &= ~(1 << 0);
    packet->initFunc = btlUnitHoldPendingModelRelease;
    packet->updateFunc = btlUnitModelReleasePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingModelRelease;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019BBE0
BtlPacket* func_0019bbe0(BtlUnit* unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags)
{
    BtlPacket* packet;
    BtlUnitColorWork* work;

    packet = btlPacketAlloc(0x112, sizeof(BtlUnitColorWork));
    packet->initFunc = func_0019b710;
    packet->updateFunc = func_0019b730;
    packet->destroyFunc = func_0019bbc0;
    work = (BtlUnitColorWork*)packet->workData;
    work->unit = unit;
    work->targetColor = targetColor;
    work->startFrame = startFrame;
    work->duration = duration;
    work->mode = mode;
    work->flags = flags;

    return packet;
}



// FUN_0019BD00
BtlPacket* btlUnitCreateShowPacket(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x113, sizeof(BtlUnit*));
    packet->initFunc = btlUnitHoldPendingShow;
    packet->updateFunc = btlUnitShowPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingShow;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019BDD0
BtlPacket* btlUnitCreateHidePacket(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x114, sizeof(BtlUnit*));
    packet->initFunc = btlUnitHoldPendingHide;
    packet->updateFunc = btlUnitHidePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingHide;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019C030
BtlPacket* btlUnitCreateResourceLoadPacket(BtlUnit* unit, u16 id, u16 flags)
{
    BtlPacket* packet;
    BtlUnitResourceWork* work;

    packet = btlPacketAlloc(0x111, sizeof(BtlUnitResourceWork));
    packet->flags &= ~(1 << 0);
    packet->initFunc = btlUnitResourceLoadPacketInit;
    packet->updateFunc = btlUnitResourceLoadPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingResourceLoad;
    work = (BtlUnitResourceWork*)packet->workData;
    work->unit = unit;
    work->flags = flags;
    work->type = unit->genus + 1;
    work->id = id;
    work->state = 0;

    return packet;
}



// FUN_0019E550
BtlPacket* btlUnitCreateLookAtUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u16 flags)
{
    BtlPacket* packet;
    LookAtUnitWork* work;

    packet = btlPacketAlloc(0x118, sizeof(LookAtUnitWork));
    packet->initFunc = btlUnitHoldPendingLookAtUnits;
    packet->updateFunc = btlUnitLookAtUnitPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingLookAtUnits;
    work = (LookAtUnitWork*)packet->workData;
    work->unit = unit;
    work->targetUnit = targetUnit;
    work->flags = flags;

    return packet;
}



// FUN_0019E5D0
u32 func_0019e5d0(void *arg0)
{
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL)
    {
        *(u16 *)(temp + 0xa0) = *(u16 *)(temp + 0xa0) + 1;
    }
}
// FUN_0019E5F0
u32 func_0019e5f0(void* work)
{
    extern u8* iGpffffb3ac;
    extern void mdlSetBlendWeight(void* arg0, f32 arg1);
    extern void mdlLookAtSetupSetRange(void* arg0, f32 arg1, f32 arg2);
    extern void mdlSetLookAtRequested(void* arg0);
    BtlUnitPacketLookAtDeactivate* packet;
    BtlUnit* curr;

    packet = (BtlUnitPacketLookAtDeactivate*)work;

    if (packet->flags & 3)
    {
        if (packet->flags & 1)
        {
            curr = *(BtlUnit**)((u8*)iGpffffb3ac + 0x17c);
            while (curr != NULL)
            {
                if ((curr->flags3 & 8) && (curr->flags2 & 2))
                {
                    mdlSetBlendWeight(curr->mdl, 0.25f);
                    mdlLookAtSetupSetRange(curr->mdl, 70.0f, 60.0f);
                    mdlSetLookAtRequested(curr->mdl);
                    curr->lookAtMode = 0;
                }
                curr = curr->prev;
            }
        }

        if (packet->flags & 2)
        {
            curr = *(BtlUnit**)((u8*)iGpffffb3ac + 0x184);
            while (curr != NULL)
            {
                if ((curr->flags3 & 8) && (curr->flags2 & 2))
                {
                    mdlSetBlendWeight(curr->mdl, 0.25f);
                    mdlLookAtSetupSetRange(curr->mdl, 70.0f, 60.0f);
                    mdlSetLookAtRequested(curr->mdl);
                    curr->lookAtMode = 0;
                }
                curr = curr->prev;
            }
        }
    }
    else
    {
        curr = packet->unit;
        if (curr->flags2 & 2)
        {
            mdlSetBlendWeight(curr->mdl, 0.25f);
            mdlLookAtSetupSetRange(curr->mdl, 70.0f, 60.0f);
            mdlSetLookAtRequested(curr->mdl);
            curr->lookAtMode = 0;
        }
    }

    return 1;
}
// FUN_0019E7A0
u32 func_0019e7a0(void *arg0)
{
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL)
    {
        *(u16 *)(temp + 0xa0) = *(u16 *)(temp + 0xa0) - 1;
    }
}
// FUN_0019E7C0
BtlPacket* btlUnitCreateLookAtDeactivatePacket(BtlUnit* unit, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAtDeactivate* work;

    packet = btlPacketAlloc(0x119, sizeof(BtlUnitPacketLookAtDeactivate));
    packet->initFunc = func_0019e5d0;
    packet->updateFunc = func_0019e5f0;
    packet->destroyFunc = func_0019e7a0;
    work = (BtlUnitPacketLookAtDeactivate*)packet->workData;
    work->unit = unit;
    work->flags = flags;

    return packet;
}



// FUN_00201DB0
void func_00201db0(void* work)
{
    RotateTowardUnitPacket* packet;

    packet = (RotateTowardUnitPacket*)work;

    packet->unit->pendingPacketCount--;
    packet->targetUnit->pendingPacketCount--;
}
