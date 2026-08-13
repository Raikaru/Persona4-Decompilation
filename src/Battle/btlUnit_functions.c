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

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_00198020(void* work);
u32 func_00198050(void* work);
u32 func_001982d0(void* work);
typedef struct BtlUnitPacket {
    BtlUnit* unit;
    s16 value;
    u8 padding_06[2];
} BtlUnitPacket;
u32 func_0019a010(void* work);
u32 func_0019a030(void* work);
u32 func_0019a0a0(void* work);
typedef struct BtlUnitPacketResNullifiedAnim {
    BtlUnit* unit;
    f32 value;
    u32 padding_08;
} BtlUnitPacketResNullifiedAnim;
u32 func_0019a130(void* work);
u32 func_0019a150(void* work);
u32 func_0019a2c0(void* work);
typedef struct BtlUnitMotionWork {
    f32 position[3];
    BtlUnit* unit;
    s16 value;
    s16 counter;
    f32 phase;
} BtlUnitMotionWork;
u32 func_0019a350(void* work);
u32 func_0019a370(void* work);
u32 func_0019a5c0(void* work);
typedef struct BtlUnitPacketEnmDodgeAnim {
    BtlUnit* unit;
    s32 value;
    u8 padding_08[8];
} BtlUnitPacketEnmDodgeAnim;
u32 func_0019a660(void* work);
u32 func_0019a680(void* work);
u32 func_0019a840(void* work);
u32 func_0019a8d0(void* work);
u32 func_0019a8f0(void* work);
u32 func_0019a960(void* work);
u32 func_0019a9e0(void* work);
u32 func_0019aa00(void* work);
u32 func_0019aa50(void* work);
typedef struct BtlUnitSpeedWork {
    BtlUnit* unit;
    u16 value;
    u8 padding_06[2];
    f32 speed;
    u16 mode;
    u8 padding_0e[2];
} BtlUnitSpeedWork;
u32 func_0019aae0(void* work);
u32 func_0019ab00(void* work);
u32 func_0019ac20(void* work);
u32 func_0019b620(void* work);
u32 func_0019b640(void* work);
u32 func_0019b680(void* work);
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
u32 func_0019bc90(void* work);
u32 func_0019bcb0(void* work);
u32 func_0019bce0(void* work);
u32 func_0019bd60(void* work);
u32 func_0019bd80(void* work);
u32 func_0019bdb0(void* work);
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
u32 func_0019bf10(void* work);
u32 func_0019bf80(void* work);
u32 func_0019c010(void* work);
typedef struct LookAtUnitWork {
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u16 flags;
    u8 padding_0a[2];
} LookAtUnitWork;
u32 func_0019e1f0(void* work);
u32 func_0019e220(void* work);
u32 func_0019e520(void* work);
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
    u16 packetCount;
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

    packet = func_00194470(0x10e, sizeof(RotateTowardUnitWork));
    packet->initFunc = func_00198020;
    packet->updateFunc = func_00198050;
    packet->destroyFunc = func_001982d0;
    work = (RotateTowardUnitWork*)packet->workData;
    work->unit = unit;
    work->targetUnit = targetUnit;
    work->flags = flags;

    return packet;
}



// FUN_0019A0C0
BtlPacket* func_0019a0c0(BtlUnit* unit, s16 value)
{
    BtlPacket* packet;
    BtlUnitPacket* work;

    packet = func_00194470(0x104, sizeof(BtlUnitPacket));
    packet->initFunc = func_0019a010;
    packet->updateFunc = func_0019a030;
    packet->destroyFunc = func_0019a0a0;
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

    packet = func_00194470(0x107, sizeof(BtlUnitPacketResNullifiedAnim));
    packet->initFunc = func_0019a130;
    packet->updateFunc = func_0019a150;
    packet->destroyFunc = func_0019a2c0;
    work = (BtlUnitPacketResNullifiedAnim*)packet->workData;
    work->unit = unit;
    work->value = value;

    return packet;
}



// FUN_0019A5E0
BtlPacket* func_0019a5e0(BtlUnit* unit, s32 value)
{
    BtlPacket* packet;
    BtlUnitMotionWork* work;

    packet = func_00194470(0x108, sizeof(BtlUnitMotionWork));
    packet->initFunc = func_0019a350;
    packet->updateFunc = func_0019a370;
    packet->destroyFunc = func_0019a5c0;
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

    packet = func_00194470(0x109, sizeof(BtlUnitPacketEnmDodgeAnim));
    packet->initFunc = func_0019a660;
    packet->updateFunc = func_0019a680;
    packet->destroyFunc = func_0019a840;
    work = (BtlUnitPacketEnmDodgeAnim*)packet->workData;
    work->unit = unit;
    work->value = 0;

    return packet;
}



// FUN_0019A980
BtlPacket* func_0019a980(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x105, sizeof(BtlUnit*));
    packet->initFunc = func_0019a8d0;
    packet->updateFunc = func_0019a8f0;
    packet->destroyFunc = func_0019a960;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019AA70
BtlPacket* func_0019aa70(BtlUnit* unit, s16 value)
{
    BtlPacket* packet;
    BtlUnitPacket* work;

    packet = func_00194470(0x102, sizeof(BtlUnitPacket));
    packet->initFunc = func_0019a9e0;
    packet->updateFunc = func_0019aa00;
    packet->destroyFunc = func_0019aa50;
    work = (BtlUnitPacket*)packet->workData;
    work->unit = unit;
    work->value = value;

    return packet;
}



// FUN_0019AC40
BtlPacket* func_0019ac40(BtlUnit* unit, u16 value, f32 speed, u16 mode)
{
    BtlPacket* packet;
    BtlUnitSpeedWork* work;

    packet = func_00194470(0x103, sizeof(BtlUnitSpeedWork));
    packet->initFunc = func_0019aae0;
    packet->updateFunc = func_0019ab00;
    packet->destroyFunc = func_0019ac20;
    work = (BtlUnitSpeedWork*)packet->workData;
    work->unit = unit;
    work->value = value;
    work->speed = speed;
    work->mode = mode;

    return packet;
}



// FUN_0019B6A0
BtlPacket* func_0019b6a0(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x110, sizeof(BtlUnit*));
    packet->flags &= ~(1 << 0);
    packet->initFunc = func_0019b620;
    packet->updateFunc = func_0019b640;
    packet->destroyFunc = func_0019b680;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019BBE0
BtlPacket* func_0019bbe0(BtlUnit* unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags)
{
    BtlPacket* packet;
    BtlUnitColorWork* work;

    packet = func_00194470(0x112, sizeof(BtlUnitColorWork));
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
BtlPacket* func_0019bd00(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x113, sizeof(BtlUnit*));
    packet->initFunc = func_0019bc90;
    packet->updateFunc = func_0019bcb0;
    packet->destroyFunc = func_0019bce0;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019BDD0
BtlPacket* func_0019bdd0(BtlUnit* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x114, sizeof(BtlUnit*));
    packet->initFunc = func_0019bd60;
    packet->updateFunc = func_0019bd80;
    packet->destroyFunc = func_0019bdb0;
    *(BtlUnit**)packet->workData = unit;

    return packet;
}



// FUN_0019C030
BtlPacket* func_0019c030(BtlUnit* unit, u16 id, u16 flags)
{
    BtlPacket* packet;
    BtlUnitResourceWork* work;

    packet = func_00194470(0x111, sizeof(BtlUnitResourceWork));
    packet->flags &= ~(1 << 0);
    packet->initFunc = func_0019bf10;
    packet->updateFunc = func_0019bf80;
    packet->destroyFunc = func_0019c010;
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

    packet = func_00194470(0x118, sizeof(LookAtUnitWork));
    packet->initFunc = func_0019e1f0;
    packet->updateFunc = func_0019e220;
    packet->destroyFunc = func_0019e520;
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
    extern void func_0047a890(void* arg0, f32 arg1);
    extern void func_0047a8a0(void* arg0, f32 arg1, f32 arg2);
    extern void func_0047a990(void* arg0);
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
                    func_0047a890(curr->mdl, 0.25f);
                    func_0047a8a0(curr->mdl, 70.0f, 60.0f);
                    func_0047a990(curr->mdl);
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
                    func_0047a890(curr->mdl, 0.25f);
                    func_0047a8a0(curr->mdl, 70.0f, 60.0f);
                    func_0047a990(curr->mdl);
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
            func_0047a890(curr->mdl, 0.25f);
            func_0047a8a0(curr->mdl, 70.0f, 60.0f);
            func_0047a990(curr->mdl);
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

    packet = func_00194470(0x119, sizeof(BtlUnitPacketLookAtDeactivate));
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

    packet->unit->packetCount--;
    packet->targetUnit->packetCount--;
}
