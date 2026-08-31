/* Source unit: src/btlTarget/btlTarget_001eb420.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern f32 RwV3dLength(const RwV3d* vector);
extern f32 func_003e41e0(f32* out, f32* in);
extern f32 fabsf(f32 x);

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket
{
    u8 data_00[0x6c];
    BtlPacketUpdateFunc updateFunc;
    u8 data_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlTargetWork
{
    u32 param_00;
    u16 param_04;
    u16 pad_06;
    u32 param_08;
    u32 param_0c;
    u32 param_10;
    u32 param_14;
} BtlTargetWork;

extern BtlPacket* func_00194470(u32 id, s32 workDataSize);
extern u32 func_001f5ed0(void* work);

typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;

extern void func_001f6220(u16 command, u32 param);
u32 func_001f6000(BtlTargetSimpleWork* work);
extern u32 func_001f6090(void* work);



// FUN_001EB420
void func_001eb420(u8* target)
{
    *(u16*)(target + 0x44) = *(u16*)(target + 0x34);
    *(u16*)(target + 0x46) = *(u16*)(target + 0x36);
}



// FUN_001EC250
f32 func_001ec250(const RwV3d* first, const RwV3d* second)
{
    RwV3d delta;

    delta.x = first->x - second->x;
    delta.y = first->y - second->y;
    delta.z = first->z - second->z;
    delta.y = 0.0f;
    return RwV3dLength(&delta);
}



// FUN_001EC6D0
void func_001ec6d0(s16* outX, s16* outZ, f32* position)
{
    s32 x = (s32)(position[0] + 1750.0f);
    s32 z = (s32)(position[2] + 1750.0f);
    s16 tileX = (s16)(x / 0x19);
    s16 tileZ = (s16)(z / 0x19);

    if (x % 0x19 > 0x0C)
    {
        tileX++;
    }
    if (z % 0x19 > 0x0C)
    {
        tileZ++;
    }
    if (outX != NULL)
    {
        *outX = tileX;
    }
    if (outZ != NULL)
    {
        *outZ = tileZ;
    }
}



// FUN_001EC790
/* measured: opt_propagation off keeps zMax materialization before the
   xMaxWorld conversion, matching retail's instruction order. */
#pragma opt_propagation off
void func_001ec790(void* work, s32 x, s32 z, f32 radius)
{
    s32 radiusInt;
    s32 radiusTiles;
    s16 xMin;
    s16 zMin;
    s16 diameterTiles;
    s16 xMax;
    s16 zMax;
    f32 xMinWorld;
    f32 zMinWorld;
    f32 xMaxWorld;
    f32 zMaxWorld;

    radiusInt = (s32)radius;
    radiusTiles = (s32)(s16)(radiusInt / 25);
    if (radiusInt % 25 != 0) {
        radiusTiles = (s32)(s16)(radiusTiles + 1);
    }
    xMin = x - radiusTiles;
    zMin = z - radiusTiles;
    xMinWorld = (f32)(xMin * 25 - 1750);
    zMinWorld = (f32)(zMin * 25 - 1750);
    diameterTiles = (s16)radiusTiles * 2;
    xMax = xMin + diameterTiles;
    zMax = zMin + diameterTiles;
    xMaxWorld = (f32)(xMax * 25 - 1750);
    zMaxWorld = (f32)(zMax * 25 - 1750);

    *(f32*)((u8*)work + 0x510) = xMinWorld;
    *(f32*)((u8*)work + 0x514) = zMinWorld;
    *(f32*)((u8*)work + 0x640) = xMaxWorld;
    *(f32*)((u8*)work + 0x644) = zMinWorld;
    *(f32*)((u8*)work + 0x770) = xMaxWorld;
    *(f32*)((u8*)work + 0x774) = zMaxWorld;
    *(f32*)((u8*)work + 0x8A0) = xMinWorld;
    *(f32*)((u8*)work + 0x8A4) = zMaxWorld;
}
/* measured: opt_propagation on restores the unit baseline after this match. */
#pragma opt_propagation on
/* measured: opt_propagation off is required for this function's exact
   floating-point scheduling. */
#pragma opt_propagation off
// FUN_001EC8C0
s32 func_001ec8c0(RwV3d* first, RwV3d* second, RwV3d* point, f32 threshold)
{
    f32 delta[2];
    f32 pointDeltaX;
    f32 pointDeltaY;
    f32 cross;
    f32 projectedX;
    f32 projectedY;

    delta[0] = first->x - second->x;
    delta[1] = first->y - second->y;
    func_003e41e0(delta, delta);
    pointDeltaX = point->x - first->x;
    pointDeltaY = point->y - first->y;
    cross = pointDeltaX * delta[1] + pointDeltaY * -delta[0];
    projectedX = point->x - cross * delta[1];
    projectedY = point->y - cross * -delta[0];
    if (((first->x < projectedX || second->x > projectedX) &&
         (first->x > projectedX || second->x < projectedX)) ||
        ((first->y < projectedY || second->y > projectedY) &&
         (first->y > projectedY || second->y < projectedY)))
    {
        return 0;
    }
    return fabsf(cross) < threshold;
}
/* measured: opt_propagation on restores the unit baseline after this match. */
#pragma opt_propagation on
// FUN_001ECA10
INCLUDE_ASM("asm/nonmatchings/btlTarget", func_001eca10);
// FUN_001ECDE0
s32 func_001ecde0(const f32* param_1, const f32* param_2, const f32* param_3)
{
    f32 cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
                (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);

    if (cross <= 0.0f)
    {
        goto nonpositive;
    }
    return 1;

nonpositive:
    return -(cross < 0.0f);
}



// FUN_001EEC50
void func_001eec50(void* work)
{
    *(u16*)((u8*)work + 0x400) = 0;
    *(u16*)((u8*)work + 0x402) = 0;
}



// FUN_001F0A40
void func_001f0a40(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x14) = 0;
}



// FUN_001F3850
void func_001f3850(s32* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}



// FUN_001F3930
void func_001f3930(s32* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}



// FUN_001F3B00
void func_001f3b00(s32* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}



// FUN_001F5F70
BtlPacket* func_001f5f70(u32 param_1, u16 param_2, u32 param_3,
                        u32 param_4, u32 param_5)
{
    BtlPacket* packet;
    BtlTargetWork* work;

    packet = func_00194470(0x800, 0x18);
    packet->updateFunc = func_001f5ed0;
    work = (BtlTargetWork*)packet->workData;
    work->param_00 = param_1;
    work->param_04 = param_2;
    work->param_08 = param_3;
    work->param_0c = param_4;
    work->param_10 = param_5;
    work->param_14 = 0;
    return packet;
}



// FUN_001F6000
u32 func_001f6000(BtlTargetSimpleWork* work)
{
    func_001f6220(work->command, work->param);
    return 1;
}



// FUN_001F6030
BtlPacket* func_001f6030(u16 command, u32 param)
{
    BtlPacket* packet = func_00194470(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_001f6000;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}



// FUN_001F60C0
BtlPacket* func_001f60c0(void)
{
    BtlPacket* packet = func_00194470(0x802, 0);
    packet->updateFunc = func_001f6090;
    return packet;
}
