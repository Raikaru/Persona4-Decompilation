#include "type.h"
#define BTLUNIT_FLAG2_DIRTY (1 << 2)
#define BTLUNIT_FLAG3_NOROT (1 << 13)

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

typedef struct BtlUnit BtlUnit;
struct BtlUnit
{
    u16 flags;
    u16 _pad04;
    RwV3d pos;
    u8 _pad10[0xc];
    RtQuat rot;
    f32 scale;
    RwRGBA cols[1];
    u8 _pad34[0x4c];
    RwV3d sphereCenter;
    f32 unk_8c;
    f32 sphereRadius;
    s16 unk_94;
    s16 unk_96;
    u32 flags2;
    u32 flags3;
    u16 packetCount;
    u8 _padA2[0x22];
    u32 stateFlags;
    u16 movementFlags;
};

typedef struct BtlUnitPacketMove BtlUnitPacketMove;
struct BtlUnitPacketMove
{
    BtlUnit* unit;
    RwV3d targetPos;
    u32 flags;
    u16 state;
    u8 _pad16[2];
    u32 timer;
    f32 unk_1c;
    f32 speed;
};

typedef struct BtlUnitPacketPosRotCol BtlUnitPacketPosRotCol;
struct BtlUnitPacketPosRotCol
{
    BtlUnit* unit;
    RwV3d pos;
    RtQuat rot;
    RwRGBA col;
    u16 flags;
};

typedef struct BtlUnitPacketCountRef BtlUnitPacketCountRef;
struct BtlUnitPacketCountRef
{
    u8 _pad00[0x24];
    BtlUnit* unit;
};

typedef struct BtlUnitPacketPair BtlUnitPacketPair;
struct BtlUnitPacketPair
{
    BtlUnit* first;
    BtlUnit* second;
    u8 _pad08[8];
};

typedef struct BtlUnitPacketUnitAtC BtlUnitPacketUnitAtC;
struct BtlUnitPacketUnitAtC
{
    u8 _pad00[0xc];
    BtlUnit* unit;
};

typedef struct BtlUnitPacketTwoUnits BtlUnitPacketTwoUnits;
struct BtlUnitPacketTwoUnits
{
    BtlUnit* first;
    BtlUnit* second;
};

typedef struct BtlUnitStateWork BtlUnitStateWork;
struct BtlUnitStateWork
{
    u8 _pad00[0xa2];
    u8 state;
    u8 _padA3[9];
    u8 value;
};
typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
};

typedef struct BtlUnitPacketMoveToUnit BtlUnitPacketMoveToUnit;
struct BtlUnitPacketMoveToUnit
{
    BtlUnit* unit;
    u8 _pad04[0xc];
    u32 flags;
    u8 _pad14[8];
    f32 param;
    f32 speed;
    BtlUnit* targetUnit;
};

BtlPacket* func_00194470(u32 id, s32 workDataSize);
RwV3d* func_003dcb40(RwV3d* vectorsOut, const RwV3d* vectorsIn,
                     s32 numPoints, const RtQuat* quat);
void func_001ec1c0(RwV3d* dst, const RwV3d* from, const RwV3d* to);
void func_00196ce0(BtlUnitPacketMove* work);
u32 func_00196d00(void* work);
void func_001973d0(BtlUnitPacketMove* work);
void func_001974d0(BtlUnitPacketCountRef* work);
u32 func_001974f0(void* work);
void func_001979c0(BtlUnitPacketCountRef* work);

// FUN_001979E0
BtlPacket* func_001979e0(BtlUnit* unit, BtlUnit* targetUnit, f32 param, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMoveToUnit* work;

    packet = func_00194470(0x10B, sizeof(BtlUnitPacketMoveToUnit));

    packet->initFunc = (BtlPacketFunc)func_001974d0;
    packet->updateFunc = func_001974f0;
    packet->destroyFunc = (BtlPacketFunc)func_001979c0;

    work = (BtlUnitPacketMoveToUnit*)packet->workData;

    work->unit = unit;
    work->param = param;
    work->speed = speed;
    work->flags = flags;
    work->targetUnit = targetUnit;

    return packet;
}

typedef struct BtlUnitPacketRotate BtlUnitPacketRotate;
struct BtlUnitPacketRotate
{
    BtlUnit* unit;
    RwV3d rot;
    u32 flags;
    u32 timer;
};

void func_00197d50(BtlUnitPacketCountRef* work);
u32 func_00197d70(void* work);
void func_00197f30(BtlUnitPacketCountRef* work);
extern RwV3d D_00881430;

// FUN_00197F50
BtlPacket* func_00197f50(BtlUnit* unit, const RwV3d* rot, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketRotate* work;

    packet = func_00194470(0x10D, sizeof(BtlUnitPacketRotate));

    packet->initFunc = (BtlPacketFunc)func_00197d50;
    packet->updateFunc = func_00197d70;
    packet->destroyFunc = (BtlPacketFunc)func_00197f30;

    work = (BtlUnitPacketRotate*)packet->workData;

    work->unit = unit;
    work->flags = flags;

    if (rot != NULL)
    {
        work->rot = *rot;
    }
    else
        work->rot = D_00881430;

    return packet;
}

typedef struct BtlUnitPacketAnim BtlUnitPacketAnim;
struct BtlUnitPacketAnim
{
    BtlUnit* unit;
    s16 id;
    u16 blendFrameCount;
    f32 speed;
    u16 mode;
};

BtlPacket* func_0019a2e0(BtlUnit* unit, f32 param);
BtlPacket* func_0019a5e0(BtlUnit* unit, s32 param);
BtlPacket* func_0019a860(BtlUnit* unit, s32 param);
void func_00199e50(BtlUnitPacketCountRef* work);
u32 func_00199e70(void* work);
void func_00199ec0(BtlUnitPacketCountRef* work);

// FUN_00199EE0
BtlPacket* func_00199ee0(BtlUnit* unit, u16 id, u16 blendFrameCount, f32 speed, u16 mode)
{
    BtlPacket* packet;
    BtlUnitPacketAnim* work;
    s16 _id;

    _id = id;
    switch (_id)
    {
        case -2: return func_0019a2e0(unit, 32.0f);
        case -3: return func_0019a5e0(unit, 6);
        case -4: return func_0019a860(unit, 6);
    }

    packet = func_00194470(0x100, sizeof(BtlUnitPacketAnim));

    packet->initFunc = (BtlPacketFunc)func_00199e50;
    packet->updateFunc = func_00199e70;
    packet->destroyFunc = (BtlPacketFunc)func_00199ec0;

    work = (BtlUnitPacketAnim*)packet->workData;
    work->unit = unit;

    switch (_id)
    {
        case -5:
            _id = -1;
    }

    work->id = _id;
    work->blendFrameCount = blendFrameCount;
    work->speed = speed;
    work->mode = mode;

    return packet;
}

typedef struct BtlUnitPacketLookAt BtlUnitPacketLookAt;
struct BtlUnitPacketLookAt
{
    BtlUnit* unit;
    RwV3d targetPos;
    u16 flags;
};

void func_0019df00(BtlUnitPacketCountRef* work);
u32 func_0019df20(void* work);
void func_0019e130(BtlUnitPacketCountRef* work);

// FUN_0019E150
BtlPacket* func_0019e150(BtlUnit* unit, const RwV3d* targetPos, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAt* work;

    packet = func_00194470(0x117, sizeof(BtlUnitPacketLookAt));

    packet->initFunc = (BtlPacketFunc)func_0019df00;
    packet->updateFunc = func_0019df20;
    packet->destroyFunc = (BtlPacketFunc)func_0019e130;

    work = (BtlUnitPacketLookAt*)packet->workData;

    work->unit = unit;
    work->flags = flags;
    work->targetPos = *targetPos;

    return packet;
}

// FUN_00194EE0
void func_00194ee0(BtlUnit* unit, const RwV3d* pos)
{
    unit->pos = *pos;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194F10
void func_00194f10(BtlUnit* unit, const RtQuat* rot)
{
    if (!(unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit->rot = *rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
}

// FUN_00194F60
void func_00194f60(BtlUnit* unit, RwRGBA col)
{
    unit->cols[0] = col;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194FA0
void func_00194fa0(BtlUnit* unit, u16 flags)
{
    unit->flags |= flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194FC0
void func_00194fc0(BtlUnit* unit, u16 flags)
{
    unit->flags &= ~flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}
// FUN_00195630
u32 func_00195630(BtlUnitPacketPosRotCol* packet)
{
    BtlUnit* unit;

    if (packet->flags & 0x1)
    {
        unit = packet->unit;
        unit->pos = packet->pos;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if ((packet->flags & 0x2) &&
        !(packet->unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit = packet->unit;
        unit->rot = packet->rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if (packet->flags & 0x4)
    {
        unit = packet->unit;
        unit->cols[0] = packet->col;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    return 1;
}

// FUN_00195850
void func_00195850(BtlUnit* unit, RwV3d* dst)
{
    RwV3d scaledCenter;
    RwV3d rotatedCenter;

    scaledCenter.x = unit->sphereCenter.x * unit->scale;
    scaledCenter.y = unit->sphereCenter.y * unit->scale;
    scaledCenter.z = unit->sphereCenter.z * unit->scale;

    func_003dcb40(&rotatedCenter, &scaledCenter, 1, &unit->rot);

    dst->x = rotatedCenter.x + unit->pos.x;
    dst->y = rotatedCenter.y + unit->pos.y;
    dst->z = rotatedCenter.z + unit->pos.z;
}

// FUN_001958F0
void func_001958f0(BtlUnit* unit, RwV3d* dst)
{
    RwV3d scaledCenter;
    RwV3d rotatedCenter;

    scaledCenter.x = unit->sphereCenter.x * unit->scale;
    scaledCenter.y = unit->sphereCenter.y * unit->scale;
    scaledCenter.z = unit->sphereCenter.z * unit->scale;

    func_003dcb40(&rotatedCenter, &scaledCenter, 1, &unit->rot);

    dst->x = rotatedCenter.x + (unit->unk_94 * 25 - 0x6d6);
    dst->y = rotatedCenter.y + unit->pos.y;
    dst->z = rotatedCenter.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00195C50
void func_00195c50(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    func_001ec1c0((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    func_003dcb40(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + (unit->unk_94 * 25 - 0x6d6);
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00196B50
u32 func_00196b50(BtlUnit* unit)
{
    return (unit->movementFlags & 0x1) != 0;
}

// FUN_001973F0
BtlPacket* func_001973f0(BtlUnit* unit, const RwV3d* targetPos, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMove* work;

    packet = func_00194470(0x10A, sizeof(BtlUnitPacketMove));

    packet->initFunc = (BtlPacketFunc)func_00196ce0;
    packet->updateFunc = func_00196d00;
    packet->destroyFunc = (BtlPacketFunc)func_001973d0;

    work = (BtlUnitPacketMove*)packet->workData;

    work->unit = unit;
    work->speed = speed;
    work->flags = flags;

    if (targetPos != NULL)
    {
        work->targetPos = *targetPos;
    }
    else
    {
        work->targetPos = D_00881430;
    }

    return packet;
}

// FUN_001974D0
void func_001974d0(BtlUnitPacketCountRef* packet)
{
    packet->unit->packetCount++;
}

// FUN_001979C0
void func_001979c0(BtlUnitPacketCountRef* packet)
{
    packet->unit->packetCount--;
}

// FUN_00198020
void func_00198020(BtlUnitPacketPair* packet)
{
    packet->first->packetCount++;
    packet->second->packetCount++;
}

// FUN_001982D0
void func_001982d0(BtlUnitPacketPair* packet)
{
    packet->first->packetCount--;
    packet->second->packetCount--;
}

// FUN_0019A350
void func_0019a350(BtlUnitPacketUnitAtC* packet)
{
    packet->unit->packetCount++;
}

// FUN_0019A5C0
void func_0019a5c0(BtlUnitPacketUnitAtC* packet)
{
    packet->unit->packetCount--;
}

// FUN_0019D130
u32 func_0019d130(BtlUnit* unit)
{
    return !((unit->flags3 & (1 << 12)) != 0);
}

// FUN_0019DE70
void func_0019de70(BtlUnitStateWork* work, u8 value)
{
    if (work != NULL && work->state == 2)
    {
        work->value = value;
    }
}

// FUN_0019E1F0
void func_0019e1f0(BtlUnitPacketTwoUnits* packet)
{
    if (packet->first != NULL)
    {
        packet->first->packetCount++;
    }
    packet->second->packetCount++;
}

// FUN_0019E520
void func_0019e520(BtlUnitPacketTwoUnits* packet)
{
    if (packet->first != NULL)
    {
        packet->first->packetCount--;
    }
    packet->second->packetCount--;
}
