#include "btl_motion_internal.h"
/* Source unit: src/Battle/btlTarget_001eb440.c */
#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"

typedef struct BtlTarget {
    BtlAction* targetedActions[12]; // 0x00
    u8 padding_30[2];               // 0x30
    u16 targetedCount;              // 0x32
} BtlTarget;

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
typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;
struct BtlPacket* btlTargetCreateEmptyPacket(void);
extern u8 *func_001f6030(s32 arg0, s64 arg1); /* lint: allow H011 -- raw s64 argument is passed unconverted, as in code1_001e */

extern s64 scrGetParamInt(); /* lint: allow H011 -- raw s64 call result feeds s64 temporaries, as in code1_001e */
extern s32 scrGetParamIntS32(s32 index);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern u8 *scrGetAiState(void); /* lint: allow H011 -- pointer view of the s32 definition, as in code1_001e */
extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
extern s32 btlAICommandPickTableAction(u8 *arg0); /* lint: allow H011 -- s32 view of the u8 definition, as in code1_001e; the u8 view changes the caller's extension */
extern u8 *func_001dea90(u8 *arg0, u32 arg1);
extern void *D_00609CE0[];
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
extern f32 sqrtf(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern s32 func_001f3900(u8 **arg0);
extern s32 func_001f39d0(u8 **arg0);
extern void btlSoundRequestPlayback(u16 command, u32 param); /* lint: allow H011 -- argument view used by the target packet callers, as in code1_001f */
extern u32 btlActionCachedDispatch(void* work); /* lint: allow H011 -- packet callback view (u32 return), as in code1_001f */
extern u32 func_001f6090(void* work); /* lint: allow H011 -- packet callback view (u32 return), as in code1_001f */
extern f32 RwV3dLength(const RwV3d* vector);
extern f32 func_003e41e0(f32* out, f32* in);
extern f32 fabsf(f32 x);
extern u8 *iGpffffb3ac;

// FUN_001EA9A0
s32 btlTargetScriptEnqueue(void) {
    s64 temp_16;
    s64 temp_17;
    u8 *temp_2;
    u8 *temp_2_2;

    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    temp_2 = (u8 *)btlTargetCreateEmptyPacket();
    *(s16 *)(temp_2 + 0x48) = (s16)temp_16;
    btlPacketEnqueue(temp_2, 1);
    temp_2_2 = func_001f6030(0x20, temp_17);
    *(s16 *)(temp_2_2 + 0x48) = (s16)temp_16;
    btlPacketEnqueue(temp_2_2, 1);
    return 1;
}

// FUN_001EAA30
s32 btlTargetScriptEnqueueS32(void)
{
    s32 temp_16;
    u8 *temp_2;

    temp_16 = scrGetParamIntS32(0);
    temp_2 = (u8 *)btlTargetCreateEmptyPacket();
    *(s16 *)(temp_2 + 0x48) = (s16)temp_16;
    btlPacketEnqueue(temp_2, 1);
    return 1;
}

// FUN_001EB1D0
s32 btlTargetAIPickAction(void) {
    s32 temp_3;
    u32 index;
    u8 *temp_2;
    u8 *temp_2_2;
    s32 (*callback)(u8 *, s64);

    temp_2 = scrGetAiState();
    temp_2_2 = func_001dea90(temp_2, (u32)btlAICommandPickTableAction(temp_2) & 0xFFFF);
    btlAICommandSetActionCode(temp_2, temp_2 + 0x38, *(u16 *)(temp_2_2 + 2));
    temp_3 = *(s32 *)(temp_2_2 + 4);
    index = ((u32)temp_3 & 0xFF000000) >> 24;
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 + index * 8);
    if (callback(temp_2, ((u64)temp_3 << 40) >> 40) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    return 1;
}

/* Ported from the P3FES btlTarget donor at 002d1600 (verified MATCH there),
 * which wraps this function in the same pragma. It is load-bearing:
 * measured: without it MWCC rematerializes the loop constant inside the loop
 * (addiu/sllv with swapped operands) instead of hoisting it, giving nd 28. */
#pragma opt_loop_invariants on

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d21e0 (verified MATCH there).
 * The `volatile` on `state` is load-bearing and carried over from the donor.
 * measured: removing it takes this function MATCH nd0 -> nd6 (size 148/160),
 * matching the donor's own recorded W170 measurement of nd0 -> nd6. */

typedef struct BtlTargetPacketWork {
    BtlAction* source; // 0x00
    BtlAction* action; // 0x04
    u8 data[0x20]; /* P4 result payload; P3FES uses 0x1c. */
    u16 effect;
    u16 targetFlags;
} BtlTargetPacketWork;

typedef struct BtlTargetStatePacketWork {
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;
typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 _pad00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
} BtlPacket;

BtlPacket* btlPacketAlloc(u32 type, u32 workSize);
void memcpy(void* dst, const void* src, u32 size);
void btlTargetPacketReleasePending(void* arg);
s32 btlTargetApplyHpSpChange(u8* arg);
extern u8* iGpffffb3ac;
extern void datAddMoney(s32 arg);
extern void func_00113480(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void btlSoundClearStatusCounters(void* action, s32 flags);
extern void btlActionRunTargetCallback(void* action, s32 effect, s32 arg2, s32 arg3, s32 arg4);
extern void btlPanelStartRingEffect(void* unit);
extern void btlPanelStartPulseEffect(void* unit);
extern s32 datCalcGetLevel(void* data);
extern void datCalcSetHp(void* data, s32 value);
extern void datCalcAddHp(void* data, s32 value);
extern void datCalcAddSp(void* data, s32 value);
extern void datCalcSetBadStatus(void* data, s32 value);
extern void datCalcClearBadStatus(void* data, s32 value);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void datCalcApplyBuffMask(void* data, s32 value, s32 mode);
extern s32 datCalcIsDead(void* data, s32 mode);
extern s32 datCalcIsLowHp(void* data);
extern s32 datCalcIsStatusBlocked(void* data);
extern void datCalcSetStatusBlocked(void* data);
extern void datCalcClearStatusBlocked(void* data);
extern void btlUnitUpdateHpGauge(void* source, u8* packet, s32* hpDelta);



// FUN_001EB440
u16 btlTargetGetUnitIndex(BtlTarget* target)
{
    u16 mask = 0;
    u16 i = 0;
    u16 bit = 1;
    s32 count = target->targetedCount;

    for (; i < count; i++) {
        mask |= bit << target->targetedActions[i]->unit->genus;
    }
    return mask;
}
/* measured: see the annotation above the matching `on` pragma (btlTargetGetUnitIndex). */
#pragma opt_loop_invariants off


// FUN_001EBA20
s32 btlTargetSpawnActionProc(u8 *arg0) {
    s32 result;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 8) == 0) {
        btlAICommandSpawnActionProc(*(u8 **)arg0, *(u8 **)arg0 + 0x38,
                     *(s32 *)(arg0 + 0xC), *(s32 *)(arg0 + 4));
        *(u8 *)(*(u8 **)arg0 + 0x68) = 1;
        *(s32 *)(arg0 + 8) = 1;
        goto zero_path;
    }
    temp_16 = *(u8 **)arg0 + 0x38;
    if (*(u8 *)(*(u8 **)arg0 + 0x68) != 0)
        goto check_flags;
    result = 1;
    goto common;
check_flags:
    if (*(s32 *)(temp_16 + 0x4C) != 0)
        goto check_call;
    result = 1;
    goto common;
check_call:
    if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x4C)) != 0)
        goto result_zero;
    *(s8 *)(temp_16 + 0x30) = 0;
    *(s32 *)(temp_16 + 0x4C) = 0;
    result = 1;
    goto common;
result_zero:
    result = 0;
common:
    if (result == 0)
        goto zero_path;
    result = 1;
    goto done;
zero_path:
    result = 0;
done:
    return result;
}

// FUN_001EC1C0
void btlTargetBlendVectors(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f12;
    f32 temp_f13;
    f32 var_f0;

    temp_f12 = *(f32 *)(arg2 + 0) - *(f32 *)(arg1 + 0);
    temp_f13 = *(f32 *)(arg2 + 8) - *(f32 *)(arg1 + 8);
    var_f0 = 0.0f;
    if ((temp_f12 != 0.0f) || (temp_f13 != 0.0f))
        var_f0 = fGpffff8048 * func_0044b950(temp_f12, temp_f13);
    func_003dc740(arg0, D_0060A0E0, var_f0, 0);
}

// FUN_001EC250
f32 btlTargetVectorDistance(const RwV3d* first, const RwV3d* second)
{
    RwV3d delta;

    delta.x = first->x - second->x;
    delta.y = first->y - second->y;
    delta.z = first->z - second->z;
    delta.y = 0.0f;
    return RwV3dLength(&delta);
}

/* measured: opt_propagation off probe for ec2b0 load ordering. */
#pragma opt_propagation off
// FUN_001EC2B0
f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left)
{
    extern f32 func_0044b920(f32 arg0);
    f32 dot;

    dot = right->quat.x * left->quat.x +
          right->quat.y * left->quat.y +
          right->quat.z * left->quat.z;
    dot += right->quat.w * left->quat.w;
    if (dot < 0.0f) {
        dot = right->quat.x * -left->quat.x +
              right->quat.y * -left->quat.y +
              right->quat.z * -left->quat.z;
        dot += right->quat.w * -left->quat.w;
    }
    return 2.0f * func_0044b920(dot);
}
/* measured: close opt_propagation probe for btlTargetQuatAngle. */
#pragma opt_propagation on

// FUN_001EC3D0
f32 btlTargetAngleBetween(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 fabsf(f32 arg0);
    f32 delta[2];
    f32 vx;
    f32 vy;
    f32 cross;

    delta[0] = *(f32 *)(arg0 + 0) - *(f32 *)(arg1 + 0);
    delta[1] = *(f32 *)(arg0 + 4) - *(f32 *)(arg1 + 4);
    func_003e41e0(delta, delta);
    vx = *(f32 *)(arg2 + 0) - *(f32 *)(arg0 + 0);
    vy = *(f32 *)(arg2 + 4) - *(f32 *)(arg0 + 4);
    cross = (vx * delta[1]) + (vy * -delta[0]);
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = *(f32 *)(arg2 + 0) - cross * delta[1];
        *(f32 *)(arg3 + 4) = *(f32 *)(arg2 + 4) - cross * -delta[0];
    }
    return fabsf(cross);
}

// FUN_001EC4A0
s32 btlTargetFindInRange(s32 arg0, u8 *arg1)
{
    extern void func_003e42a0();
    extern u8 *func_00457120(); /* lint: allow H011 -- pointer view of the s32 definition, as in code1_001e */
    f32 sp40[3];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    u8 *camera;

    camera = func_00457120() + 0x20;
    func_003e42a0(sp40, arg0, camera);
    temp_f20 = *(f32 *)(func_00457120() + 0x80);
    temp_f0 = *(f32 *)(func_00457120() + 0x84);
    if ((sp40[2] <= temp_f20) || !(sp40[2] < temp_f0)) {
        return 0;
    }
    temp_f2 = 640.0f * (sp40[0] / sp40[2]);
    temp_f1 = 448.0f * (sp40[1] / sp40[2]);
    if ((temp_f2 < -640.0f) || !(temp_f2 <= 1280.0f) ||
        (temp_f1 < -448.0f) || !(temp_f1 <= 896.0f)) {
        return 0;
    }
    *(f32 *)(arg1 + 0) = temp_f2;
    *(f32 *)(arg1 + 4) = temp_f1;
    return 1;
}

/* measured: the `volatile` on `state` is load-bearing (see annotation above);
 * removing it costs FUN_001EC630 MATCH nd0 -> nd6. */
// FUN_001EC630
f32 btlTargetSmoothStep(f32 value, volatile f32* state)
{
    f32 current;
    f32 slopeBase;
    f32 remaining;
    f32 resultBase;
    f32 slope;
    f32 result;

    current = state[1];
    slopeBase = state[3];
    resultBase = state[4];
    remaining = current - value;

    if (remaining <= 0.0f)
    {
        return 1.0f;
    }
    if (remaining < state[0] * 0.5f)
    {
        slope = slopeBase - state[2] * value;
    }
    else
    {
        slope = state[2] * value + slopeBase;
    }
    result = slope * value + resultBase;
    state[1] = remaining;
    state[3] = slope;
    state[4] = result;
    return result;
}



// FUN_001EC6D0
void btlTargetPositionToCell(s16* outX, s16* outZ, f32* position)
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
void btlTargetSetRadiusArea(void* work, s32 x, s32 z, f32 radius)
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
s32 btlTargetNearSegment(f32* first, f32* second, f32* point, f32 threshold)
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
s32 btlTargetRangeCheck(u8 *first, u8 *second)
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
            side_a = btlTargetCrossSign(edge, next, (f32 *)(first + 8));
            side_b = btlTargetCrossSign(edge, next, (f32 *)(second + 8));
            if (side_a != side_b) {
                side_a = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), corner);
                side_b = btlTargetCrossSign((f32 *)(first + 8),
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
            side_a = btlTargetCrossSign(edge, next, (f32 *)(first + 8));
            side_b = btlTargetCrossSign(edge, next, (f32 *)(second + 8));

            if (side_a != side_b) {
                side_a = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), edge);
                side_b = btlTargetCrossSign((f32 *)(first + 8),
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
static s32 btlTargetCrossSign(const f32* param_1, const f32* param_2, const f32* param_3)
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
s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin)
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
            s32 side_a = btlTargetCrossSign(edge, next, first);
            s32 side_b = btlTargetCrossSign(edge, next, second);

            if (side_a != side_b) {
                side_a = btlTargetCrossSign(first, second, edge);
                side_b = btlTargetCrossSign(first, second, next);
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
            if (btlTargetNearSegment(first, second, edge, margin) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// FUN_001ED330
int btlTargetCheckSide(const float* param_1, const float* param_2, const float* param_3)
{
    int side;
    float cross;

    cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
            (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);
    if (cross >= 0.0f)
    {
        side = 1;
    }
    else
    {
        side = -(cross < 0.0f);
    }
    return side;
}


// FUN_001EEC50
void btlTargetResetWork(void* work)
{
    *(u16*)((u8*)work + 0x400) = 0;
    *(u16*)((u8*)work + 0x402) = 0;
}

// FUN_001F0A40
void btlTargetClearWork(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x14) = 0;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */
// FUN_001F0610
s32 func_001f0610(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7970 (verified MATCH there). */

// FUN_001F2FE0
void btlTargetPacketAddPending(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->pendingPacketCount++;
    work->action->unit->pendingPacketCount++;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7df0 (verified MATCH there). */

// FUN_001F3010
s32 btlTargetApplyHpSpChange(u8* arg0)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_5;
    s32 temp_4;
    s32 temp_5;
    u16 temp_3_8;
    u8 temp_3_6;
    u8 temp_3_7;
    u8* temp_16_2;
    u8* temp_19;
    u8* temp_18;
    u8* temp_2_2;
    u8* temp_3_2;
    u8* temp_3_3;
    u8* temp_3_4;
    u8* temp_4_2;

    temp_19 = *(u8**)(arg0 + 4);
    if ((*(u16*)(temp_19 + 0x1a) & 1) == 0) {
        return 1;
    }
    temp_18 = *(u8**)(temp_19 + 0x30);
    temp_17 = datCalcIsDead(*(u8**)(temp_18 + 0xa64), 0);
    temp_21 = datCalcIsLowHp(*(u8**)(temp_18 + 0xa64));
    temp_22 = datCalcChkBadStatus((s32)*(u8**)(temp_18 + 0xa64), 1);
    temp_16 = datCalcChkBadStatus((s32)*(u8**)(temp_18 + 0xa64), 0x100000);
    if (*(u16*)(arg0 + 0x2a) & 2) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x1000;
    }
    if (*(u16*)(arg0 + 0x2a) & 4) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x800;
    }
    if (*(s32*)(arg0 + 0x10) & 0x100000) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x2000;
    }
    if (*(u16*)(arg0 + 0x26) & 0x200) {
        *(u16*)(temp_19 + 0x1a) = *(u16*)(temp_19 + 0x1a) | 0x80;
    }
    if (*(u16*)(arg0 + 0x26) & 0x80) {
        if (datCalcIsStatusBlocked(*(u8**)(temp_18 + 0xa64)) != 0) {
            datCalcClearStatusBlocked(*(u8**)(temp_18 + 0xa64));
        } else {
            datCalcSetStatusBlocked(*(u8**)(temp_18 + 0xa64));
        }
    }
    if (*(s32*)(iGpffffb3ac + 0xc) & 0x10) {
        datCalcAddHp(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 8));
        datCalcAddSp(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0xc));
        datAddMoney(*(s32*)(arg0 + 0x1c));
    }
    temp_3 = *(s32*)(arg0 + 8);
    if ((temp_3 < 0) || (temp_2 = *(s32*)(arg0 + 0xc), temp_2 < 0)) {
        btlPanelStartRingEffect(temp_18);
        if ((*(u16*)(arg0 + 0x26) & 0x300) == 0) {
            datCalcClearStatusBlocked(*(u8**)(temp_18 + 0xa64));
        }
    } else if ((temp_3 > 0) || (temp_2 > 0)) {
        btlPanelStartPulseEffect(temp_18);
    }
    if (*(s32*)(iGpffffb3ac + 0xc) & 0x20) {
        btlSoundClearStatusCounters(temp_19, *(s32*)(arg0 + 0x10));
        datCalcSetBadStatus(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0x10));
        datCalcClearBadStatus(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0x14));
    }
    temp_5 = *(s32*)(arg0 + 0x18);
    if (temp_5 != 0) {
        datCalcApplyBuffMask(*(u8**)(temp_18 + 0xa64), temp_5, 1);
    }
    if ((datCalcIsDead(*(u8**)(temp_18 + 0xa64), 0) != 0) && (temp_17 == 0)) {
        if (*(u8*)(temp_18 + 0xa2) == 1) {
            temp_3_2 = iGpffffb3ac;
            *(u16*)(temp_3_2 + 0xc5a) = *(u16*)(temp_3_2 + 0xc5a) + 1;
            if (*(u16*)(arg0 + 0x26) & 8) {
                temp_3_3 = iGpffffb3ac;
                *(u16*)(temp_3_3 + 0xc5c) = *(u16*)(temp_3_3 + 0xc5c) + 1;
            }
            temp_4 = datCalcGetLevel(*(u8**)(temp_18 + 0xa64)) & 0xff;
            temp_3_4 = iGpffffb3ac;
            *(s32*)(temp_3_4 + 0xce4) = *(s32*)(temp_3_4 + 0xce4) + temp_4;
            temp_2_2 = iGpffffb3ac + 0xce0;
            if (*(s32*)temp_2_2 < temp_4) {
                *(s32*)temp_2_2 = temp_4;
            }
        }
        temp_17_2 = (*(u16*)(arg0 + 0x26) & 0x10) != 0;
        temp_16_2 = *(u8**)(temp_19 + 0x30);
        datCalcClearStatusBlocked(*(u8**)(temp_16_2 + 0xa64));
        if (temp_17_2 == 1) {
            if (*(u16*)(temp_19 + 0x3f4) != 0x154) {
                datCalcSetHp(*(u8**)(temp_16_2 + 0xa64), 1);
            }
            datCalcClearBadStatus(*(u8**)(temp_16_2 + 0xa64), 0x80000);
            *(s32*)(temp_16_2 + 0x9c) = *(s32*)(temp_16_2 + 0x9c) | 0x10;
        } else {
            datCalcSetHp(*(u8**)(temp_16_2 + 0xa64), 0);
            datCalcClearBadStatus(*(u8**)(temp_16_2 + 0xa64), 0xffffff);
            datCalcSetBadStatus(*(u8**)(temp_16_2 + 0xa64), 0x80000);
            temp_3_5 = *(s32*)(temp_16_2 + 0x9c) | 1;
            *(s32*)(temp_16_2 + 0x9c) = temp_3_5;
            *(s32*)(temp_16_2 + 0x9c) = temp_3_5 & ~0x10;
        }
        if (datCalcIsDead(*(u8**)(temp_18 + 0xa64), 0) != 0) {
            if (*(u8**)(iGpffffb3ac + 0x170) == temp_19) {
                func_00113480(0x19, 0x96, 0x19, 0);
                btlActionRunTargetCallback(temp_19, 0x10, (*(s32*)(arg0 + 0x10) & 0x80000) != 0, 0, 2);
            } else {
                btlActionRunTargetCallback(temp_19, 0x1c, 0, 0, 0);
            }
        }
    } else if ((datCalcIsLowHp(*(u8**)(temp_18 + 0xa64)) != 0) && (temp_21 == 0)) {
        btlActionRunTargetCallback(temp_19, 0x1b, 0, 0, 0);
    } else {
        temp_3_6 = *(u8*)(*(u8**)(temp_19 + 0x30) + 0xa2);
        if ((temp_3_6 == 0) && (temp_3_6 != *(u8*)(*(u8**)(*(u8**)(arg0 + 0) + 0x30) + 0xa2))) {
            if ((datCalcChkBadStatus((s32)*(u8**)(temp_18 + 0xa64), 1) != 0) && (temp_22 == 0)) {
                btlActionRunTargetCallback(temp_19, 0x16, 0, 0, 0);
            } else if ((datCalcChkBadStatus((s32)*(u8**)(temp_18 + 0xa64), 0x100000) != 0) && (temp_16 == 0)) {
                btlActionRunTargetCallback(temp_19, 0x17, 0, 0, 0);
            } else if (*(u16*)(arg0 + 0x28) & 6) {
                btlActionRunTargetCallback(temp_19, 0x1a, 0, 0, 0);
            }
        } else if ((datCalcChkBadStatus((s32)*(u8**)(temp_18 + 0xa64), 0x100000) == 0) || (temp_16 == 1)) {
            temp_4_2 = *(u8**)(arg0 + 0);
            temp_3_7 = *(u8*)(*(u8**)(temp_4_2 + 0x30) + 0xa2);
            if ((temp_3_7 == 0) &&
                (temp_3_7 != *(u8*)(*(u8**)(temp_19 + 0x30) + 0xa2)) &&
                !(*(u16*)(arg0 + 0x28) & 4) &&
                (*(s32*)(arg0 + 8) != 0 || *(s32*)(arg0 + 0xc) != 0 ||
                 *(s32*)(arg0 + 0x10) != 0 || *(s32*)(arg0 + 0x14) != 0 ||
                 *(s32*)(arg0 + 0x18) != 0)) {
                temp_3_8 = *(u16*)(arg0 + 0x2a);
                if (temp_3_8 & 2) {
                    btlActionRunTargetCallback(temp_4_2, 0x14, 0, 0, 0);
                } else if (temp_3_8 & 4) {
                    btlActionRunTargetCallback(temp_4_2, 0x15, 0, 0, 0);
                }
            }
        }
    }
    btlUnitUpdateHpGauge(*(u8**)(arg0 + 0), temp_19, (s32 *)(arg0 + 8));
    btlUnitUpdateStatusMotion(temp_18, 6);
    return 1;
}
// FUN_001F36B0
void btlTargetPacketReleasePending(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->pendingPacketCount--;
    work->action->unit->pendingPacketCount--;
}



// FUN_001F36E0
BtlPacket* btlTargetCreateDataPacket(s32 param_1, s32 param_2, const void* param_3, u16 param_4, u16 param_5)
{
    BtlPacket* packet;
    u8* work;

    packet = btlPacketAlloc(0x700, 0x2c);
    packet->initFunc = (BtlPacketFunc)btlTargetPacketAddPending;
    packet->updateFunc = (BtlPacketFunc)btlTargetApplyHpSpChange;
    packet->destroyFunc = (BtlPacketFunc)btlTargetPacketReleasePending;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = param_1;
    *(s32*)(work + 4) = param_2;
    memcpy(work + 8, param_3, 0x20);
    *(u16*)(work + 0x28) = param_4;
    *(u16*)(work + 0x2a) = param_5;
    return packet;
}
// FUN_001F37B0
void btlTargetActionAddPending(u8* arg)
{
    BtlAction* action;

    action = *(BtlAction**)arg;
    action->unit->pendingPacketCount++;
}
// FUN_001F37D0
u32 btlTargetStatePacketUpdate(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    u8 value;

    if ((work->flags & 2) != 0)
    {
        work->action->unk_28 = 0;
    }
    else if ((work->flags & 1) != 0)
    {
        work->action->unk_28++;
    }
    else
    {
        value = work->action->unk_28;
        if (value > 0)
        {
            if (value > 1)
            {
                value = 1;
            }
            work->action->unk_28 = value - 1;
        }
    }
    return 1;
}

// FUN_001F3850
void btlTargetReleaseUnitPending(u8* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *(s32*)param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}

// FUN_001F3870
/* The allocator result remains in v0 through packet initialization; all eleven
 * retail callers use it for submission or dependency setup. */
u8 *btlTargetCreateActionPacket(u8 *action, u8 flags)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x701, 8);
    *(BtlTargetStateHook *)(packet + 0x68) = btlTargetActionAddPending;
    *(BtlTargetStateUpdate *)(packet + 0x6C) = btlTargetStatePacketUpdate;
    *(BtlTargetStateHook *)(packet + 0x70) = btlTargetReleaseUnitPending;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)(work + 0) = action;
    *(u8 *)(work + 4) = flags;
    return packet;
}

// FUN_001F38E0
void btlTargetAdvanceWorkPtr(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}

// FUN_001F3930
void btlTargetAdvanceWorkCount(s32* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}

// FUN_001F3950
u8 *btlTargetCreateRecordPacket(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x703, 4);
    *(void **)(packet + 0x68) = (void *)btlTargetAdvanceWorkPtr;
    *(void **)(packet + 0x6C) = (void *)func_001f3900;
    *(void **)(packet + 0x70) = (void *)btlTargetAdvanceWorkCount;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F39B0
void btlTargetRewindWorkPtr(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}

// FUN_001F3B00
void btlTargetRewindWorkCount(s32* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = *param_1;
    iVar2 = *(s32*)(iVar1 + 0x30);
    *(u16*)(iVar2 + 0xA0) = *(u16*)(iVar2 + 0xA0) - 1;
}

// FUN_001F3B20
u8 *btlTargetCreateHitPacket(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x702, 4);
    *(void **)(packet + 0x68) = (void *)btlTargetRewindWorkPtr;
    *(void **)(packet + 0x6C) = (void *)func_001f39d0;
    *(void **)(packet + 0x70) = (void *)btlTargetRewindWorkCount;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F3FD0
s32 func_001f3fd0(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4250
s32 func_001f4250(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4260
s32 func_001f4260(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4270
s32 func_001f4270(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4280
s32 func_001f4280(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4290
s32 func_001f4290(void)
{
    return -1;
}

// FUN_001F5F70
BtlPacket* btlTargetCreateTargetPacket(u32 param_1, u16 param_2, u32 param_3,
                        u32 param_4, u32 param_5)
{
    BtlPacket* packet;
    BtlTargetWork* work;

    packet = btlPacketAlloc(0x800, 0x18);
    packet->updateFunc = btlActionCachedDispatch;
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
u32 btlTargetSimpleCommand(BtlTargetSimpleWork* work)
{
    btlSoundRequestPlayback(work->command, work->param);
    return 1;
}

// FUN_001F60C0
BtlPacket* btlTargetCreateEmptyPacket(void)
{
    BtlPacket* packet = btlPacketAlloc(0x802, 0);
    packet->updateFunc = func_001f6090;
    return packet;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */
// FUN_001F9710
s32 func_001f9710(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9720
s32 func_001f9720(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9730
s32 func_001f9730(void)
{
    return -1;
}

// FUN_001F9740
s32 func_001f9740(void)
{
    return -1;
}
