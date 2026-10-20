#include "btl_effect_internal.h"
#include "btl_unit_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"

typedef struct RotateTowardUnitWork {
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u32 flags;
    u32 timer;
} RotateTowardUnitWork;

BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
u32 btlUnitHoldPendingPair(void* packet);
u32 btlUnitRotateTowardUnitPacketUpdate(void* packetData);
u32 btlUnitReleasePendingPair(void* packet);
typedef struct BtlUnitPacket {
    BtlUnit* unit;
    s16 value;
    u8 padding_06[2];
} BtlUnitPacket;
u32 btlUnitHoldPendingMotionRequest(void* packetWork);
u32 btlUnitReleasePendingMotionRequest(void* packetWork);
typedef struct BtlUnitPacketResNullifiedAnim {
    BtlUnit* unit;
    f32 value;
    u32 padding_08;
} BtlUnitPacketResNullifiedAnim;
u32 btlUnitHoldPendingResNullified(void* packetWork);
u32 btlUnitResNullifiedPacketUpdate(void* packetWork);
u32 btlUnitReleasePendingResNullified(void* packetWork);
typedef struct BtlUnitMotionWork {
    f32 position[3];
    BtlUnit* unit;
    s16 value;
    s16 counter;
    f32 phase;
} BtlUnitMotionWork;
u32 btlUnitHoldPendingUnit(void* packet);
u32 btlUnitPacketArcOffsetUpdate(void* work);
u32 btlUnitReleasePendingUnit(void* packet);
typedef struct BtlUnitPacketEnmDodgeAnim {
    BtlUnit* unit;
    s32 value;
    u8 padding_08[8];
} BtlUnitPacketEnmDodgeAnim;
u32 btlUnitHoldPendingEnemyDodge(void* packetWork);
u32 btlUnitEnemyDodgePacketUpdate(void* packetWork);
u32 btlUnitReleasePendingEnemyDodge(void* packetWork);
u32 btlUnitHoldPendingMotionSettle(void* packetWork);
u32 btlUnitMotionSettlePacketUpdate(void* work);
u32 btlUnitReleasePendingMotionSettle(void* packetWork);
u32 btlUnitHoldPendingModelFrame(void* packetWork);
u32 btlUnitModelFramePacketUpdate(void* packetWork);
u32 btlUnitReleasePendingModelFrame(void* packetWork);
typedef struct BtlUnitSpeedWork {
    BtlUnit* unit;
    u16 value;
    u8 padding_06[2];
    f32 speed;
    u16 mode;
    u8 padding_0e[2];
} BtlUnitSpeedWork;
u32 btlUnitHoldPendingMotionSpeed(void* packetWork);
u32 btlUnitReleasePendingMotionSpeed(void* packetWork);
u32 btlUnitHoldPendingModelRelease(void* packetWork);
u32 btlUnitModelReleasePacketUpdate(void* packetWork);
u32 btlUnitReleasePendingModelRelease(void* packetWork);
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
u32 btlUnitHoldPendingColor(void* packetWork);
u32 btlUnitColorPacketUpdate(void* workData);
u32 btlUnitReleasePendingColor(void* packetWork);
u32 btlUnitHoldPendingShow(void* packetWork);
u32 btlUnitShowPacketUpdate(void* context);
u32 btlUnitReleasePendingShow(void* packetWork);
u32 btlUnitHoldPendingHide(void* packetWork);
u32 btlUnitHidePacketUpdate(void* context);
u32 btlUnitReleasePendingHide(void* packetWork);
typedef struct BtlUnitResourceWork {
    BtlUnit* unit;
    u16 type;
    u16 id;
    u16 flags;
    u8 padding_0a[2];
    u32 state;
} BtlUnitResourceWork;
u32 btlUnitResourceLoadPacketInit(void* packetWork);
u32 btlUnitResourceLoadPacketUpdate(void* packetWork);
u32 btlUnitReleasePendingResourceLoad(void* packetWork);
typedef struct LookAtUnitWork {
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u16 flags;
    u8 padding_0a[2];
} LookAtUnitWork;
u32 btlUnitHoldPendingLookAtUnits(void* packet);
u32 btlUnitLookAtUnitPacketUpdate(void* packet);
u32 btlUnitReleasePendingLookAtUnits(void* packet);
typedef struct BtlUnitPacketLookAtDeactivate {
    BtlUnit* unit;
    u16 flags;
    u8 padding_06[2];
} BtlUnitPacketLookAtDeactivate;
u32 btlUnitHoldPendingLookAtDeactivate(void* context);
u32 btlUnitLookAtDeactivatePacketUpdate(void* work);
u32 btlUnitReleasePendingLookAtDeactivate(void* context);


typedef struct RotateTowardUnitPacket {
    BtlUnit* unit;
    BtlUnit* targetUnit;
} RotateTowardUnitPacket;


/* Create target-facing work and retain both units through the paired lifecycle callbacks. */
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


/* Create a rest-motion request with the requested blend-frame halfword. */
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


/* Create the alternating resource-nullified displacement animation with the supplied amplitude. */
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


/* Create temporary arc-offset work with its requested mode and a cleared counter. */
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


/* Create enemy-dodge animation work with its starting counter cleared; the second argument is unused. */
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


/* Create a model-frame request carrying the signed frame value. */
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


/* Create a motion-speed request carrying blend frames, playback rate, and playback option. */
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


/* Create a timed color transition with its target color, start frame, duration and mode flags. */
// FUN_0019BBE0
BtlPacket* btlUnitCreateColorPacket(BtlUnit* unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags)
{
    BtlPacket* packet;
    BtlUnitColorWork* work;

    packet = btlPacketAlloc(0x112, sizeof(BtlUnitColorWork));
    packet->initFunc = btlUnitHoldPendingColor;
    packet->updateFunc = btlUnitColorPacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingColor;
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


/* Create resource-loading work for genus plus one; clear dispatcher flag bit zero before enqueueing. */
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


/* Create unit-targeted look-at work; selection flags may apply it to whole party or enemy lists. */
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


/* Retain a supplied unit while its look-at deactivation request is pending. */
// FUN_0019E5D0
u32 btlUnitHoldPendingLookAtDeactivate(void *context)
{
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL)
    {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount + 1;
    }
}
/* Restore default look-at ranges and request a model update for one unit or both selected lists. */
// FUN_0019E5F0
u32 btlUnitLookAtDeactivatePacketUpdate(void* work)
{
    extern u8* iGpffffb3ac;
    extern void mdlSetBlendWeight(void* model, f32 value);
    extern void mdlLookAtSetupSetRange(void* model, f32 pitchLimit, f32 yawLimit);
    extern void mdlSetLookAtRequested(void* model);
    BtlUnitPacketLookAtDeactivate* packet;
    BtlUnit* curr;

    packet = (BtlUnitPacketLookAtDeactivate*)work;

    if (packet->flags & 3)
    {
        if (packet->flags & 1)
        {
            curr = (BtlUnit *)((BtlBattleState *)iGpffffb3ac)->unitLists[1];
            while (curr != NULL)
            {
                if ((curr->flags3 & 8) && (curr->flags2 & 2))
                {
                    mdlSetBlendWeight(curr->layerHandle, 0.25f);
                    mdlLookAtSetupSetRange(curr->layerHandle, 70.0f, 60.0f);
                    mdlSetLookAtRequested(curr->layerHandle);
                    curr->lookAtMode = 0;
                }
                curr = curr->prevUnit;
            }
        }

        if (packet->flags & 2)
        {
            curr = (BtlUnit *)((BtlBattleState *)iGpffffb3ac)->unitLists[3];
            while (curr != NULL)
            {
                if ((curr->flags3 & 8) && (curr->flags2 & 2))
                {
                    mdlSetBlendWeight(curr->layerHandle, 0.25f);
                    mdlLookAtSetupSetRange(curr->layerHandle, 70.0f, 60.0f);
                    mdlSetLookAtRequested(curr->layerHandle);
                    curr->lookAtMode = 0;
                }
                curr = curr->prevUnit;
            }
        }
    }
    else
    {
        curr = packet->unit;
        if (curr->flags2 & 2)
        {
            mdlSetBlendWeight(curr->layerHandle, 0.25f);
            mdlLookAtSetupSetRange(curr->layerHandle, 70.0f, 60.0f);
            mdlSetLookAtRequested(curr->layerHandle);
            curr->lookAtMode = 0;
        }
    }

    return 1;
}
/* Release the optional unit reference held by look-at deactivation work. */
// FUN_0019E7A0
u32 btlUnitReleasePendingLookAtDeactivate(void *context)
{
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL)
    {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount - 1;
    }
}
/* Create look-at deactivation work for one unit or the lists selected by flags. */
// FUN_0019E7C0
BtlPacket* btlUnitCreateLookAtDeactivatePacket(BtlUnit* unit, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAtDeactivate* work;

    packet = btlPacketAlloc(0x119, sizeof(BtlUnitPacketLookAtDeactivate));
    packet->initFunc = btlUnitHoldPendingLookAtDeactivate;
    packet->updateFunc = btlUnitLookAtDeactivatePacketUpdate;
    packet->destroyFunc = btlUnitReleasePendingLookAtDeactivate;
    work = (BtlUnitPacketLookAtDeactivate*)packet->workData;
    work->unit = unit;
    work->flags = flags;

    return packet;
}


/* Release both unit references held by the target-facing packet. */
// FUN_00201DB0
void btlUnitRotateTowardUnitPacketDestroy(void* work)
{
    RotateTowardUnitPacket* packet;

    packet = (RotateTowardUnitPacket*)work;

    packet->unit->pendingPacketCount--;
    packet->targetUnit->pendingPacketCount--;
}
