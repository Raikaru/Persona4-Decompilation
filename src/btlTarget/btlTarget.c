/* Source unit: src/btlTarget/btlTarget_001eb420.c (1 function markers) */
#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern f32 RwV3dLength(const RwV3d* vector);
extern f32 func_003e41e0(f32* out, f32* in);
extern f32 fabsf(f32 x);
extern u8 *iGpffffb3ac;

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
s32 func_001ec8c0(f32* first, f32* second, f32* point, f32 threshold)
{
    f32 delta[2];
    f32 pointDeltaX;
    f32 pointDeltaY;
    f32 cross;
    f32 projectedX;
    f32 projectedY;

    delta[0] = first[0] - second[0];
    delta[1] = first[1] - second[1];
    func_003e41e0(delta, delta);
    pointDeltaX = point[0] - first[0];
    pointDeltaY = point[1] - first[1];
    cross = pointDeltaX * delta[1] + pointDeltaY * -delta[0];
    projectedX = point[0] - cross * delta[1];
    projectedY = point[1] - cross * -delta[0];
    if (((first[0] < projectedX || second[0] > projectedX) &&
         (first[0] > projectedX || second[0] < projectedX)) ||
        ((first[1] < projectedY || second[1] > projectedY) &&
         (first[1] > projectedY || second[1] < projectedY)))
    {
        return 0;
    }
    return fabsf(cross) < threshold;
}
/* measured: opt_propagation on restores the unit baseline after this match. */
#pragma opt_propagation on
/* MATCH.  Reject a graph edge when it crosses an active link or an obstacle
   edge.  The last eleven words were one saved-register exchange: retail
   colours the second loop's counter $s2 and its next-corner pointer $s3,
   this body had them the other way round.  Three things together close it
   and all three are needed - `next` lives at function scope declared between
   `i` and `j`, `edge` is declared without an initialiser, and the two are
   assigned as statements with `next` first.  Declaring `next` after `j`
   keeps the exchange; leaving `edge` initialised at its declaration keeps it
   too.  Same statement-order sensitivity as handoff 7l, one level below
   declaration order.  The first loop keeps its own block-scoped `next`;
   folding both onto one variable costs 19.  Keep the private orientation
   leaf defined below this caller - moving it above changes the compiler's
   clobber knowledge and costs 920/976 bytes.
   Earlier measurements on the way down, kept because they bound the search:
   23 -> 11 came from declaring `corner` last in the first inner block;
   at 11, reversing that whole block tied, `&node[i * 0x130]` tied, swapping
   `i`/`j` tied, moving `corner` to the top of its block cost 23, hoisting
   `i` above `node` cost 40, and spelling `corner` as `node + i * 0x130 + 8`
   cost 223.  A 28-pair pragma sweep was entirely neutral or worse. */
// FUN_001ECA10
s32 func_001eca10(u8 *first, u8 *second)
{
    extern f32 RwV2dLength(const f32 *vector);
    u8 *node;
    s32 blocked;
    s32 i;
    f32 *next;
    s32 j;
    f32 delta[2];
    f32 coordinate;

    blocked = 0;
    for (node = *(u8 **)(iGpffffb3ac + 0x318);
         node != NULL && blocked == 0;
         node = *(u8 **)(node + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            u8 *vertex = node + i * 0x130;
            f32 *midpointX;
            f32 *midpointY;
            f32 *edge;
            f32 *next;
            f32 *corner;
            s32 side_a;
            s32 side_b;
            s32 intersects;

            if (*(f32 *)(vertex + 0x1C) <= 0.0f) {
                continue;
            }
            corner = (f32 *)(vertex + 8);
            if ((u8 *)corner == first || (u8 *)corner == second) {
                continue;
            }
            midpointX = (f32 *)(vertex + 0x10);
            coordinate = *midpointX;
            delta[0] = coordinate - *(f32 *)(first + 8);
            midpointY = (f32 *)(vertex + 0x14);
            coordinate = *midpointY;
            delta[1] = coordinate - *(f32 *)(first + 0xC);
            if (RwV2dLength(delta) < 1.0f) {
                continue;
            }
            coordinate = *midpointX;
            delta[0] = coordinate - *(f32 *)(second + 8);
            coordinate = *midpointY;
            delta[1] = coordinate - *(f32 *)(second + 0xC);
            if (RwV2dLength(delta) < 1.0f) {
                continue;
            }
            next = *(f32 **)(node + i * 0x130 + 0x18);
            edge = (f32 *)(node + i * 0x130 + 8);
            side_a = func_001ecde0(edge, next, (f32 *)(first + 8));
            side_b = func_001ecde0(edge, next, (f32 *)(second + 8));
            if (side_a != side_b) {
                side_a = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), corner);
                side_b = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                blocked = 1;
                break;
            }
        }
        if (blocked != 0) {
            continue;
        }
        if ((*(f32 *)(node + 8) < *(f32 *)(first + 8)) &&
            (*(f32 *)(node + 0xC) < *(f32 *)(first + 0xC)) &&
            !(*(f32 *)(node + 0x268) <= *(f32 *)(first + 8)) &&
            !(*(f32 *)(node + 0x26C) <= *(f32 *)(first + 0xC))) {
            continue;
        }
        if ((*(f32 *)(node + 8) < *(f32 *)(second + 8)) &&
            (*(f32 *)(node + 0xC) < *(f32 *)(second + 0xC)) &&
            !(*(f32 *)(node + 0x268) <= *(f32 *)(second + 8)) &&
            !(*(f32 *)(node + 0x26C) <= *(f32 *)(second + 0xC))) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            s32 wrap = (j + 1) & 3;
            f32 *edge;
            s32 intersects;
            s32 side_a;
            s32 side_b;
            next = (f32 *)(node + wrap * 0x130 + 8);
            edge = (f32 *)(node + j * 0x130 + 8);
            side_a = func_001ecde0(edge, next, (f32 *)(first + 8));
            side_b = func_001ecde0(edge, next, (f32 *)(second + 8));

            if (side_a != side_b) {
                side_a = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), edge);
                side_b = func_001ecde0((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                blocked = 1;
                break;
            }
        }
    }
    return blocked;
}
// FUN_001ECDE0
/* Private leaf: all twelve retail calls belong to this geometry unit. */
static s32 func_001ecde0(const f32* param_1, const f32* param_2, const f32* param_3)
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

// FUN_001ECE50
/* 520/528 bytes; all six relocations resolve exactly with the private leaf. */
s32 func_001ece50(f32 *first, f32 *second, f32 margin)
{
    u8 *node;
    s32 i;

    for (node = *(u8 **)(iGpffffb3ac + 0x318);
         node != NULL;
         node = *(u8 **)(node + 0x4CC)) {
        if ((*(f32 *)(node + 8) < first[0]) &&
            (*(f32 *)(node + 0xC) < first[1]) &&
            !(*(f32 *)(node + 0x268) <= first[0]) &&
            !(*(f32 *)(node + 0x26C) <= first[1])) {
            continue;
        }
        if ((*(f32 *)(node + 8) < second[0]) &&
            (*(f32 *)(node + 0xC) < second[1]) &&
            !(*(f32 *)(node + 0x268) <= second[0]) &&
            !(*(f32 *)(node + 0x26C) <= second[1])) {
            continue;
        }
        for (i = 0; i < 4; i++) {
            s32 wrap = (i + 1) & 3;
            f32 *next = (f32 *)(node + wrap * 0x130 + 8);
            f32 *edge = (f32 *)(node + i * 0x130 + 8);
            s32 intersects;
            s32 side_a = func_001ecde0(edge, next, first);
            s32 side_b = func_001ecde0(edge, next, second);

            if (side_a != side_b) {
                side_a = func_001ecde0(first, second, edge);
                side_b = func_001ecde0(first, second, next);
                if (side_a != side_b) {
                    intersects = 1;
                } else {
                    intersects = 0;
                }
            } else {
                intersects = 0;
            }
            if (intersects != 0) {
                return 1;
            }
            if (func_001ec8c0(first, second, edge, margin) != 0) {
                return 1;
            }
        }
    }
    return 0;
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
void func_001f3850(u8* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *(s32*)param_1;
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
