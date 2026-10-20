#include "mdl_effect_internal.h"
#include "member_access.h"
#include "btl_target_internal.h"
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
    u32 unk00;
    u16 unk04;
    u16 pad_06;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
    u32 unk14;
} BtlTargetWork;
typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;
struct BtlPacket* btlTargetCreateEmptyPacket(void);
extern u8 *btlTargetCreateSimplePacket(s32, s64); /* lint: allow H011 -- raw s64 argument is passed unconverted, as in code1_001e */

extern s64 scrGetParamInt(); /* lint: allow H011 -- raw s64 call result feeds s64 temporaries, as in code1_001e */
extern s32 scrGetParamIntS32(s32 index);
extern s64 btlPacketEnqueue(u8 *, u32);
extern u8 *scrGetAiState(void); /* lint: allow H011 -- pointer view of the s32 definition, as in code1_001e */
extern void btlAICommandSetActionCode(u8 *, u8 *, u16);
extern s32 btlAICommandPickTableAction(u8 *); /* lint: allow H011 -- s32 view of the u8 definition, as in code1_001e; the u8 view changes the caller's extension */
extern u8 *btlAISelectWeightedEntry(u8 *, u32);
extern void *D_00609CE0[];
extern f32 sqrtf(f32);
extern f32 func_0044b950(f32, f32);
extern void func_003dc740(void *, void *, f32, s32);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern s32 btlTargetClearFlaggedBuffs(u8 **);
extern s32 btlTargetConsumeActionCost(u8 **);
extern void btlSoundRequestPlayback(u16 channel, u32 playbackId); /* lint: allow H011 -- argument view used by the target packet callers, as in code1_001f */
extern u32 btlActionCachedDispatch(void* context); /* lint: allow H011 -- packet callback view (u32 return), as in code1_001f */
extern u32 btlTargetCancelPlayback(void* work); /* lint: allow H011 -- packet callback view (u32 return), as in code1_001f */
extern f32 RwV3dLength(const RwV3d* vector);
extern f32 func_003e41e0(f32* out, f32* in);
extern f32 fabsf(f32 x);
extern u8 *iGpffffb3ac;

/* Submit an empty packet and command 0x20 with the same script delay. */
// FUN_001EA9A0
s32 btlTargetScriptEnqueue(void) {

    s64 delay;
    s64 command;
    u8 *emptyPacket;
    u8 *commandPacket;


    command = scrGetParamInt(0);
    delay = scrGetParamInt(1);
    emptyPacket = (u8 *)btlTargetCreateEmptyPacket();
    ((BtlPacket *)emptyPacket)->delay = (s16)delay;
    btlPacketEnqueue(emptyPacket, 1);
    commandPacket = btlTargetCreateSimplePacket(0x20, command);
    MEMBER(s16, commandPacket, BtlPacket, delay) = (s16)delay;
    btlPacketEnqueue(commandPacket, 1);
    return 1;
}

/* Submit an empty target packet with the script-specified frame delay. */
// FUN_001EAA30
/* Submit an empty target packet with a script-specified frame delay. */
s32 btlTargetScriptEnqueueS32(void)
{
    s32 delay;
    u8 *packet;

    delay = scrGetParamIntS32(0);
    packet = (u8 *)btlTargetCreateEmptyPacket();
    ((BtlPacket *)packet)->delay = (s16)delay;
    btlPacketEnqueue(packet, 1);
    return 1;
}

/* Choose a weighted AI command and dispatch its packed target condition. */
// FUN_001EB1D0
s32 btlTargetAIPickAction(void) {
    s32 targetCondition;
    u32 index;
    u8 *action;
    u8 *entry;
    s32 (*callback)(u8 *, s64);

    action = scrGetAiState();
    entry = btlAISelectWeightedEntry(action, (u32)btlAICommandPickTableAction(action) & 0xFFFF);
    btlAICommandSetActionCode(action, action + 0x38, ((BtlAiWeightedCommand *)entry)->command);
    targetCondition = (s32)(((BtlAiWeightedCommand *)entry)->targetCondition);
    index = ((u32)targetCondition & 0xFF000000) >> 24;
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 + index * 8);
    if (callback(action, ((u64)targetCondition << 40) >> 40) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
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
    LargeBattleHitResult result; /* P4: 0x20-byte payload; P3FES uses 0x1c. */
    u16 effect;
    u16 targetFlags;
} BtlTargetPacketWork;

typedef struct BtlTargetStatePacketWork {
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;

BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
void memcpy(void* dst, const void* src, u32 size);
void btlTargetPacketReleasePending(void* arg);
s32 btlTargetApplyHpSpChange(u8* work);
extern u8* iGpffffb3ac;
extern void datAddMoney(s32 delta);
extern void datEntryDrawGatedByFlag39(s32, s32, s32, s32);
extern void btlSoundClearStatusCounters(void* action, s32 previousStatuses);
extern void btlActionRunTargetCallback(void* action, s32 effect, s32, s32, s32);
extern void btlPanelStartRingEffect(void* unit);
extern void btlPanelStartPulseEffect(void* unit);
extern s32 datCalcGetLevel(void* unit);
extern void datCalcSetHp(void* unit, s32 hp);
extern void datCalcAddHp(void* unit, s32 hpDelta);
extern void datCalcAddSp(void* unit, s32 spDelta);
extern void datCalcSetBadStatus(void* unit, s32 badStatus);
extern void datCalcClearBadStatus(void* unit, s32 badStatus);
extern u32 datCalcChkBadStatus(s32, u32);
extern void datCalcApplyBuffMask(void* unit, s32 mask, s32 delta);
extern s32 datCalcIsDead(void* unit, s32 hpDelta);
extern s32 datCalcIsLowHp(void* unit);
extern s32 datCalcIsGuarding(void* unitFlags);
extern void datCalcSetStatusBlocked(void* unitFlags);
extern void datCalcClearStatusBlocked(void* unitFlags);
extern void btlUnitUpdateHpGauge(void* source, u8* packet, s32* hpDelta);



/* Return the genus bitmask of selected actions; duplicate targets share a bit. */
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


/* Start the action procedure once, then wait until its task is unlinked. */
// FUN_001EBA20
s32 btlTargetSpawnActionProc(u8 *work) {

    s32 result;
    u8 *command;
    BtlTargetProcedure *procedureWork = (BtlTargetProcedure *)work;


    if (((BtlTargetProcedure *)work)->started == 0) {
        btlAICommandSpawnActionProc(*(u8 **)work, *(u8 **)work + 0x38,
                     ((BtlTargetProcedure *)work)->script, ((BtlTargetProcedure *)work)->procedure);
        ((BtlAiCommandWork *)((u8 *)((BtlTargetProcedure *)work)->action + 0x38))->procedureActive = 1;
        procedureWork->started = 1;
        goto zero_path;
    }
    command = *(u8 **)work + 0x38;
    if (((BtlAiCommandWork *)((u8 *)((BtlTargetProcedure *)work)->action + 0x38))->procedureActive != 0)
        goto check_flags;
    result = 1;
    goto common;
check_flags:
    if ((s32)(((BtlAiCommandWork *)command)->procedureTask) != 0)
        goto check_call;
    result = 1;
    goto common;
check_call:
    if (kwlnTaskIsLinked((s32)(((BtlAiCommandWork *)command)->procedureTask)) != 0)
        goto result_zero;
    ((BtlAiCommandWork *)command)->procedureActive = 0;
    MEMBER(s32, command, BtlAiCommandWork, procedureTask) = 0;
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

/* Build a yaw rotation from the XZ displacement; coincident positions use zero heading. */
// FUN_001EC1C0
void btlTargetBlendVectors(u8 *rotation, u8 *first, u8 *second) {
    f32 deltaX;
    f32 deltaZ;
    f32 heading;

    deltaX = ((RwV3d *)second)->x - ((RwV3d *)first)->x;
    deltaZ = ((RwV3d *)second)->z - ((RwV3d *)first)->z;
    heading = 0.0f;
    if ((deltaX != 0.0f) || (deltaZ != 0.0f))
        heading = fGpffff8048 * func_0044b950(deltaX, deltaZ);
    func_003dc740(rotation, D_0060A0E0, heading, 0);
}

/* Return the planar XZ distance, deliberately ignoring vertical displacement. */
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
/* Return twice the inverse-cosine of the absolute quaternion dot product. */
f32 btlTargetQuatAngle(BtlTargetQuaternionHolder *right, BtlTargetQuaternionHolder *left)
{
    extern f32 func_0044b920(f32);
    f32 dot;

    dot = right->quat.imag.x * left->quat.imag.x +
          right->quat.imag.y * left->quat.imag.y +
          right->quat.imag.z * left->quat.imag.z;
    dot += right->quat.real * left->quat.real;
    if (dot < 0.0f) {
        dot = right->quat.imag.x * -left->quat.imag.x +
              right->quat.imag.y * -left->quat.imag.y +
              right->quat.imag.z * -left->quat.imag.z;
        dot += right->quat.real * -left->quat.real;
    }
    return 2.0f * func_0044b920(dot);
}
/* measured: close opt_propagation probe for btlTargetQuatAngle. */
#pragma opt_propagation on

/* Return perpendicular line distance and optionally write the two-coordinate projection. */
// FUN_001EC3D0
f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection)
{

    extern f32 func_003e41e0(f32 *first, f32 *second);
    extern f32 fabsf(f32 first);
    f32 delta[2];
    f32 vx;
    f32 vy;
    f32 cross;


    delta[0] = ((RwV3d *)first)->x - ((RwV3d *)second)->x;
    delta[1] = ((RwV3d *)first)->y - ((RwV3d *)second)->y;
    func_003e41e0(delta, delta);
    vx = ((RwV3d *)point)->x - ((RwV3d *)first)->x;
    vy = MEMBER(f32, point, RwV3d, y) - MEMBER(f32, first, RwV3d, y);
    cross = (vx * delta[1]) + (vy * -delta[0]);
    if (projection != NULL) {
        ((RwV3d *)projection)->x = ((RwV3d *)point)->x - cross * delta[1];
        ((RwV3d *)projection)->y = ((RwV3d *)point)->y - cross * -delta[0];
    }
    return fabsf(cross);
}

// FUN_001EC4A0
/* Project through the active camera; reject clipped depth and the expanded screen rectangle. */
s32 btlTargetFindInRange(s32 position, u8 *output)
{
    extern void func_003e42a0();
    extern u8 *kwlnGetCamera(); /* lint: allow H011 -- pointer view of the s32 definition, as in code1_001e */
    f32 cameraPosition[3];
    f32 farPlane;
    f32 screenY;
    f32 nearPlane;
    f32 screenX;
    u8 *camera;

    camera = kwlnGetCamera() + 0x20;
    func_003e42a0(cameraPosition, position, camera);
    nearPlane = ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    farPlane = ((MdlEffectCamera *)kwlnGetCamera())->farPlane;
    if ((cameraPosition[2] <= nearPlane) || !(cameraPosition[2] < farPlane)) {
        return 0;
    }
    screenX = 640.0f * (cameraPosition[0] / cameraPosition[2]);
    screenY = 448.0f * (cameraPosition[1] / cameraPosition[2]);
    if ((screenX < -640.0f) || !(screenX <= 1280.0f) ||
        (screenY < -448.0f) || !(screenY <= 896.0f)) {
        return 0;
    }
    ((RwV3d *)output)->x = screenX;
    ((RwV3d *)output)->y = screenY;
    return 1;
}

/* measured: the `volatile` on `state` is load-bearing (see annotation above);
 * removing it costs FUN_001EC630 MATCH nd0 -> nd6. */
// FUN_001EC630
/* Advance the stored spring slope and result toward completion using the remaining interval. */
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



/* Round XZ coordinates to 25-unit cells relative to the 1750-unit origin. */
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

/* Write the four cell-rounded XZ radius bounds into the unit obstacle. */
// FUN_001EC790
/* measured: opt_propagation off keeps zMax materialization before the
   xMaxWorld conversion, matching retail's instruction order. */
#pragma opt_propagation off
/* Write the four XZ corners of the cell-rounded radius bounds embedded in the unit. */
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

    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[0].position.x = xMinWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[0].position.z = zMinWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[1].position.x = xMaxWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[1].position.z = zMinWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[2].position.x = xMaxWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[2].position.z = zMaxWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[3].position.x = xMinWorld;
    ((BtlTargetObstacle *)((u8 *)work + 0x508))->corners[3].position.z = zMaxWorld;
}
/* measured: opt_propagation on restores the unit baseline after this match. */
#pragma opt_propagation on
/* measured: opt_propagation off is required for this function's exact
   floating-point scheduling. */
#pragma opt_propagation off
// FUN_001EC8C0
/* Test perpendicular distance only when the projection lies inside the segment bounds. */
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
/* Reject a graph edge crossing an active midpoint link or an obstacle edge. */
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
    for (node = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles);
         node != NULL && blocked == 0;
         node = (u8 *)(((BtlTargetObstacle *)node)->next)) {
        for (i = 0; i < 4; i++) {
            u8 *vertex = node + i * 0x130;
            f32 *midpointX;
            f32 *midpointY;
            f32 *edge;
            f32 *next;
            f32 *corner;
            s32 firstSide;
            s32 secondSide;
            s32 intersects;

            if (((BtlTargetObstacle *)vertex)->corners[0].linkDistance <= 0.0f) {
                continue;
            }
            corner = (f32 *)(vertex + 8);
            if ((u8 *)corner == first || (u8 *)corner == second) {
                continue;
            }
            midpointX = (f32 *)(vertex + 0x10);
            coordinate = *midpointX;
            delta[0] = coordinate - ((BtlTargetCorner *)first)->midpoint.x;
            midpointY = (f32 *)(vertex + 0x14);
            coordinate = *midpointY;
            delta[1] = coordinate - ((BtlTargetCorner *)first)->midpoint.z;
            if (RwV2dLength(delta) < 1.0f) {
                continue;
            }
            coordinate = *midpointX;
            delta[0] = coordinate - ((BtlTargetCorner *)second)->midpoint.x;
            coordinate = *midpointY;
            delta[1] = coordinate - ((BtlTargetCorner *)second)->midpoint.z;
            if (RwV2dLength(delta) < 1.0f) {
                continue;
            }
            next = (f32 *)(((BtlTargetObstacle *)(node + i * 0x130))->corners[0].link);
            edge = (f32 *)(node + i * 0x130 + 8);
            firstSide = btlTargetCrossSign(edge, next, (f32 *)(first + 8));
            secondSide = btlTargetCrossSign(edge, next, (f32 *)(second + 8));
            if (firstSide != secondSide) {
                firstSide = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), corner);
                secondSide = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (firstSide != secondSide) {
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
        if ((((BtlTargetObstacle *)node)->corners[0].position.x < ((BtlTargetCorner *)first)->midpoint.x) &&
            (((BtlTargetObstacle *)node)->corners[0].position.z < ((BtlTargetCorner *)first)->midpoint.z) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.x <= ((BtlTargetCorner *)first)->midpoint.x) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.z <= ((BtlTargetCorner *)first)->midpoint.z)) {
            continue;
        }
        if ((((BtlTargetObstacle *)node)->corners[0].position.x < ((BtlTargetCorner *)second)->midpoint.x) &&
            (((BtlTargetObstacle *)node)->corners[0].position.z < ((BtlTargetCorner *)second)->midpoint.z) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.x <= ((BtlTargetCorner *)second)->midpoint.x) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.z <= ((BtlTargetCorner *)second)->midpoint.z)) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            s32 wrap = (j + 1) & 3;
            f32 *edge;
            s32 intersects;
            s32 firstSide;
            s32 secondSide;
            next = (f32 *)(node + wrap * 0x130 + 8);
            edge = (f32 *)(node + j * 0x130 + 8);
            firstSide = btlTargetCrossSign(edge, next, (f32 *)(first + 8));
            secondSide = btlTargetCrossSign(edge, next, (f32 *)(second + 8));

            if (firstSide != secondSide) {
                firstSide = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), edge);
                secondSide = btlTargetCrossSign((f32 *)(first + 8),
                                     (f32 *)(second + 8), next);
                if (firstSide != secondSide) {
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
/* Return -1, zero or one for the oriented planar cross product. */
// FUN_001ECDE0
/* Private leaf: all twelve retail calls belong to this geometry unit. */
static s32 btlTargetCrossSign(const f32* first, const f32* second, const f32* point)
{
    f32 cross = (second[0] - first[0]) * (point[1] - first[1]) -
                (second[1] - first[1]) * (point[0] - first[0]);

    if (cross <= 0.0f)
    {
        goto nonpositive;
    }
    return 1;

nonpositive:
    return -(cross < 0.0f);
}

/* Return one for an obstacle crossing or a corner within the segment margin.
 * Obstacles containing either endpoint are skipped. */
/* Return one for obstacle crossings or corners within the segment margin; skip endpoint-containing obstacles. */
// FUN_001ECE50
/* 520/528 bytes; all six relocations resolve exactly with the private leaf. */
s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin)
{
    u8 *node;
    s32 i;

    for (node = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles);
         node != NULL;
         node = (u8 *)(((BtlTargetObstacle *)node)->next)) {
        if ((((BtlTargetObstacle *)node)->corners[0].position.x < first[0]) &&
            (((BtlTargetObstacle *)node)->corners[0].position.z < first[1]) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.x <= first[0]) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.z <= first[1])) {
            continue;
        }
        if ((((BtlTargetObstacle *)node)->corners[0].position.x < second[0]) &&
            (((BtlTargetObstacle *)node)->corners[0].position.z < second[1]) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.x <= second[0]) &&
            !(((BtlTargetObstacle *)node)->corners[2].position.z <= second[1])) {
            continue;
        }
        for (i = 0; i < 4; i++) {
            s32 wrap = (i + 1) & 3;
            f32 *next = (f32 *)(node + wrap * 0x130 + 8);
            f32 *edge = (f32 *)(node + i * 0x130 + 8);
            s32 intersects;
            s32 firstSide = btlTargetCrossSign(edge, next, first);
            s32 secondSide = btlTargetCrossSign(edge, next, second);

            if (firstSide != secondSide) {
                firstSide = btlTargetCrossSign(first, second, edge);
                secondSide = btlTargetCrossSign(first, second, next);
                if (firstSide != secondSide) {
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

/* Return the planar cross-product sign, assigning collinear points to the positive side. */
// FUN_001ED330
int btlTargetCheckSide(const float* first, const float* second, const float* point)
{
    int side;
    float cross;

    cross = (second[0] - first[0]) * (point[1] - first[1]) -
            (second[1] - first[1]) * (point[0] - first[0]);
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


/* Reset the route point count and traversal cursor without clearing its points. */
// FUN_001EEC50
void btlTargetResetWork(void* work)
{
    ((BtlTargetRoute *)work)->count = 0;
    ((BtlTargetRoute *)work)->cursor = 0;
}

// FUN_001F0A40
void btlTargetClearWork(void* work)
{
    ((BtlActionResolutionMessage *)((u8 *)work + 0x10))->messageCode = 0;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */
// FUN_001F0610
s32 btlTargetSkillAuxiliaryMessageNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7970 (verified MATCH there). */

// FUN_001F2FE0
/* Retain each participating unit until the target-result packet is destroyed. */
void btlTargetPacketAddPending(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->pendingPacketCount++;
    work->action->unit->pendingPacketCount++;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7df0 (verified MATCH there). */

/* Apply recorded HP/SP, status and buff changes, then notify death and reaction transitions. */
// FUN_001F3010
s32 btlTargetApplyHpSpChange(u8* work)
{
    /* MEMBER preserves the three measured status-word reloads across callbacks. */

    s32 wasStatusHigh;
    s32 wasDead;
    s32 preserveHp;
    s32 wasLowHp;
    s32 wasStatusOne;
    s32 spDelta;
    s32 hpDelta;
    s32 unitFlags;
    s32 level;
    s32 buffMask;
    u16 hitFlags;
    u8 targetGenus;
    u8 sourceGenus;
    u8* deadUnit;
    u8* action;
    u8* unit;
    s32* maxLevel;
    u8* battle;
    u8* killBattle;
    u8* levelBattle;
    u8* source;
    BtlTargetPacketWork *packetWork = (BtlTargetPacketWork *)work;
    BtlUnit *targetUnit;
    BtlUnit *defeatedUnit;
    BtlAction *targetAction;

    action = (u8*)(((BtlTargetPacketWork *)work)->action);
    targetAction = (BtlAction *)action;
    if ((((BtlAction *)action)->unk_1a & 1) == 0) {
        return 1;
    }
    unit = (u8*)(((BtlAction *)action)->unit);
    targetUnit = (BtlUnit *)unit;
    wasDead = datCalcIsDead((u8 *)targetUnit->datUnit, 0);
    wasLowHp = datCalcIsLowHp((u8 *)targetUnit->datUnit);
    wasStatusOne = datCalcChkBadStatus((s32)(u8 *)targetUnit->datUnit, 1);
    wasStatusHigh = datCalcChkBadStatus((s32)(u8 *)targetUnit->datUnit, 0x100000);
    if (packetWork->targetFlags & BTL_HIT_RESULT_CRITICAL) {
        ((BtlAction *)action)->flags = ((BtlAction *)action)->flags | BTL_ACTION_FLAG_HIT_CRITICAL;
    }
    if (((BtlTargetPacketWork *)work)->targetFlags & BTL_HIT_RESULT_WEAK) {
        ((BtlAction *)action)->flags = ((BtlAction *)action)->flags | BTL_ACTION_FLAG_HIT_WEAK;
    }
    if ((s32)(((BtlTargetPacketWork *)work)->result.addedStatus) & 0x100000) {
        ((BtlAction *)action)->flags = ((BtlAction *)action)->flags | BTL_ACTION_FLAG_DOWN;
    }
    if (((BtlTargetPacketWork *)work)->result.flags & 0x200) {
        ((BtlAction *)action)->unk_1a = ((BtlAction *)action)->unk_1a | 0x80;
    }
    if (packetWork->result.flags & 0x80) {
        if (datCalcIsGuarding((u8 *)targetUnit->datUnit) != 0) {
            datCalcClearStatusBlocked((u8*)(((BtlUnit *)unit)->datUnit));
        } else {
            datCalcSetStatusBlocked((u8*)(((BtlUnit *)unit)->datUnit));
        }
    }
    if ((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x10) {
        datCalcAddHp((u8*)(((BtlUnit *)unit)->datUnit), ((BtlTargetPacketWork *)work)->result.hpDelta);
        datCalcAddSp((u8 *)targetUnit->datUnit, ((BtlTargetPacketWork *)work)->result.spDelta);
        datAddMoney(((BtlTargetPacketWork *)work)->result.field14);
    }
    hpDelta = ((BtlTargetPacketWork *)work)->result.hpDelta;
    if ((hpDelta < 0) || (spDelta = ((BtlTargetPacketWork *)work)->result.spDelta, spDelta < 0)) {
        btlPanelStartRingEffect(unit);
        if ((packetWork->result.flags & 0x300) == 0) {
            datCalcClearStatusBlocked((u8*)(((BtlUnit *)unit)->datUnit));
        }
    } else if ((hpDelta > 0) || (spDelta > 0)) {
        btlPanelStartPulseEffect(unit);
    }
    if ((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x20) {
        btlSoundClearStatusCounters(action, MEMBER(s32, work, BtlTargetPacketWork, result.addedStatus));
        datCalcSetBadStatus((u8 *)((BtlUnit *)unit)->datUnit, MEMBER(s32, work, BtlTargetPacketWork, result.addedStatus));
        datCalcClearBadStatus((u8 *)targetUnit->datUnit, MEMBER(s32, work, BtlTargetPacketWork, result.removedStatus));
    }
    buffMask = (s32)(((BtlTargetPacketWork *)work)->result.field10);
    if (buffMask != 0) {
        datCalcApplyBuffMask((u8*)(((BtlUnit *)unit)->datUnit), buffMask, 1);
    }
    if ((datCalcIsDead((u8*)(((BtlUnit *)unit)->datUnit), 0) != 0) && (wasDead == 0)) {
        if (((BtlUnit *)unit)->genus == 1) {
            battle = iGpffffb3ac;
            ((BtlBattleState *)battle)->unkC5A = ((BtlBattleState *)battle)->unkC5A + 1;
            if (packetWork->result.flags & 8) {
                killBattle = iGpffffb3ac;
                ((BtlBattleState *)killBattle)->unkC5C = ((BtlBattleState *)killBattle)->unkC5C + 1;
            }
            level = datCalcGetLevel((u8 *)targetUnit->datUnit) & 0xff;
            levelBattle = iGpffffb3ac;
            ((BtlBattleState *)levelBattle)->unkCE4 = ((BtlBattleState *)levelBattle)->unkCE4 + level;
            maxLevel = &((BtlBattleState *)iGpffffb3ac)->maximumDefeatedLevel;
            if (*maxLevel < level) {
                *maxLevel = level;
            }
        }
        preserveHp = (packetWork->result.flags & 0x10) != 0;
        deadUnit = (u8 *)targetAction->unit;
        defeatedUnit = (BtlUnit *)deadUnit;
        datCalcClearStatusBlocked((u8 *)defeatedUnit->datUnit);
        if (preserveHp == 1) {
            if (((BtlAction *)action)->targetBlock.recovery.enduranceSkill != 0x154) {
                datCalcSetHp((u8*)(((BtlUnit *)deadUnit)->datUnit), 1);
            }
            datCalcClearBadStatus((u8*)(((BtlUnit *)deadUnit)->datUnit), 0x80000);
            ((BtlUnit *)deadUnit)->flags3 = (s32)(((BtlUnit *)deadUnit)->flags3) | 0x10;
        } else {
            datCalcSetHp((u8*)(((BtlUnit *)deadUnit)->datUnit), 0);
            datCalcClearBadStatus((u8 *)defeatedUnit->datUnit, 0xffffff);
            datCalcSetBadStatus((u8 *)defeatedUnit->datUnit, 0x80000);
            unitFlags = (s32)(((BtlUnit *)deadUnit)->flags3) | 1;
            ((BtlUnit *)deadUnit)->flags3 = unitFlags;
            ((BtlUnit *)deadUnit)->flags3 = unitFlags & ~0x10;
        }
        if (datCalcIsDead((u8 *)targetUnit->datUnit, 0) != 0) {
            if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
                datEntryDrawGatedByFlag39(0x19, 0x96, 0x19, 0);
                btlActionRunTargetCallback(action, 0x10, ((s32)packetWork->result.addedStatus & 0x80000) != 0, 0, 2);
            } else {
                btlActionRunTargetCallback(action, 0x1c, 0, 0, 0);
            }
        }
    } else if ((datCalcIsLowHp((u8 *)targetUnit->datUnit) != 0) && (wasLowHp == 0)) {
        btlActionRunTargetCallback(action, 0x1b, 0, 0, 0);
    } else {
        targetGenus = targetAction->unit->genus;
        if ((targetGenus == 0) && (targetGenus != ((BtlTargetPacketWork *)work)->source->unit->genus)) {
            if ((datCalcChkBadStatus((s32)(u8 *)targetUnit->datUnit, 1) != 0) && (wasStatusOne == 0)) {
                btlActionRunTargetCallback(action, 0x16, 0, 0, 0);
            } else if ((datCalcChkBadStatus((s32)(u8 *)targetUnit->datUnit, 0x100000) != 0) && (wasStatusHigh == 0)) {
                btlActionRunTargetCallback(action, 0x17, 0, 0, 0);
            } else if (((BtlTargetPacketWork *)work)->effect & 6) {
                btlActionRunTargetCallback(action, 0x1a, 0, 0, 0);
            }
        } else if ((datCalcChkBadStatus((s32)(u8 *)targetUnit->datUnit, 0x100000) == 0) || (wasStatusHigh == 1)) {
            source = (u8*)(((BtlTargetPacketWork *)work)->source);
            sourceGenus = ((BtlUnit *)((u8*)(((BtlAction *)source)->unit)))->genus;
            if ((sourceGenus == 0) &&
                (sourceGenus != targetAction->unit->genus) &&
                !(((BtlTargetPacketWork *)work)->effect & 4) &&
                (packetWork->result.hpDelta != 0 || ((BtlTargetPacketWork *)work)->result.spDelta != 0 ||
                 (s32)packetWork->result.addedStatus != 0 || (s32)((BtlTargetPacketWork *)work)->result.removedStatus != 0 ||
                 (s32)packetWork->result.field10 != 0)) {
                hitFlags = packetWork->targetFlags;
                if (hitFlags & 2) {
                    btlActionRunTargetCallback(source, 0x14, 0, 0, 0);
                } else if (hitFlags & 4) {
                    btlActionRunTargetCallback(source, 0x15, 0, 0, 0);
                }
            }
        }
    }
    btlUnitUpdateHpGauge((u8*)(((BtlTargetPacketWork *)work)->source), action, (s32 *)(work + 8));
    btlUnitUpdateStatusMotion(unit, 6);
    return 1;
}
/* Release the source and target unit references acquired by packet initialization. */
// FUN_001F36B0
void btlTargetPacketReleasePending(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->pendingPacketCount--;
    work->action->unit->pendingPacketCount--;
}



/* Copy the hit result into packet 0x700 and retain both participating units. */
// FUN_001F36E0
BtlPacket* btlTargetCreateDataPacket(s32 source, s32 action, const void* result, u16 effect, u16 targetFlags)
{
    BtlPacket* packet;
    u8* work;

    packet = btlPacketAlloc(0x700, 0x2c);
    packet->initFunc = (BtlPacketFunc)btlTargetPacketAddPending;
    packet->updateFunc = (BtlPacketFunc)btlTargetApplyHpSpChange;
    packet->destroyFunc = (BtlPacketFunc)btlTargetPacketReleasePending;
    work = (u8*)packet->workData;
    ((BtlTargetPacketWork *)work)->source = (BtlAction *)source;
    ((BtlTargetPacketWork *)work)->action = (BtlAction *)action;
    memcpy(work + 8, result, 0x20);
    ((BtlTargetPacketWork *)work)->effect = effect;
    ((BtlTargetPacketWork *)work)->targetFlags = targetFlags;
    return packet;
}
/* Retain the action unit while its state packet remains queued. */
// FUN_001F37B0
void btlTargetActionAddPending(u8* arg)
{
    BtlAction* action;

    action = *(BtlAction**)arg;
    action->unit->pendingPacketCount++;
}
/* Reset or increment the action counter; otherwise clamp positive values before decrementing. */
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

/* Release the unit reference held by the action state packet. */
// FUN_001F3850
void btlTargetReleaseUnitPending(u8* work)
{
    s32 action;
    s32 unit;

    action = *(s32*)work;
    unit = (s32)(((BtlAction *)action)->unit);
    ((BtlUnit *)unit)->pendingPacketCount = ((BtlUnit *)unit)->pendingPacketCount - 1;
}

/* Create packet 0x701 with pending-unit lifetime hooks and an action-counter update. */
// FUN_001F3870
/* The allocator result remains in v0 through packet initialization; all eleven
 * retail callers use it for submission or dependency setup. */
u8 *btlTargetCreateActionPacket(u8 *action, u8 flags)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x701, 8);
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlTargetActionAddPending;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlTargetStatePacketUpdate;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlTargetReleaseUnitPending;
    work = (u8 *)(((BtlPacket *)packet)->workData);
    ((BtlTargetStatePacketWork *)work)->action = (BtlAction *)(action);
    ((BtlTargetStatePacketWork *)work)->flags = flags;
    return packet;
}

/* Acquire the pending-unit reference for a flagged-buff packet. */
// FUN_001F38E0
void btlTargetAdvanceWorkPtr(u8 **work)
{
    u8 *unit;

    unit = (u8 *)((BtlAction *)*work)->unit;
    ((BtlUnit *)unit)->pendingPacketCount = (u16)(((BtlUnit *)unit)->pendingPacketCount + 1);
}

/* Release the pending-unit reference acquired for the flagged-buff packet. */
// FUN_001F3930
void btlTargetAdvanceWorkCount(s32* work)
{
    s32 action;
    s32 unit;

    action = *work;
    unit = (s32)(((BtlAction *)action)->unit);
    ((BtlUnit *)unit)->pendingPacketCount = ((BtlUnit *)unit)->pendingPacketCount - 1;
}

/* Create packet 0x703 to clear flagged buffs while retaining its action unit. */
// FUN_001F3950
u8 *btlTargetCreateRecordPacket(u8 *action)
{
    /* This packet owns only an action reference, without the state flags. */
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x703, 4);
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlTargetAdvanceWorkPtr;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlTargetClearFlaggedBuffs;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlTargetAdvanceWorkCount;
    ((BtlTargetStatePacketWork *)((BtlPacket *)packet)->workData)->action = (BtlAction *)action;
    return packet;
}

/* Acquire the pending-unit reference for the target-hit packet. */
// FUN_001F39B0
/* Acquire the pending-unit reference for the target-hit packet. */
void btlTargetRewindWorkPtr(u8 **work)
{
    u8 *unit;

    unit = (u8 *)((BtlAction *)*work)->unit;
    ((BtlUnit *)unit)->pendingPacketCount = (u16)(((BtlUnit *)unit)->pendingPacketCount + 1);
}

/* Release the pending-unit reference acquired for the target-hit packet. */
// FUN_001F3B00
void btlTargetRewindWorkCount(s32* work)
{
    s32 action;
    s32 unit;

    action = *work;
    unit = (s32)(((BtlAction *)action)->unit);
    ((BtlUnit *)unit)->pendingPacketCount = ((BtlUnit *)unit)->pendingPacketCount - 1;
}

/* Create packet 0x702 to consume action cost while retaining its action unit. */
// FUN_001F3B20
u8 *btlTargetCreateHitPacket(u8 *action)
{
    /* This packet owns only an action reference, without the state flags. */
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x702, 4);
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlTargetRewindWorkPtr;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlTargetConsumeActionCost;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlTargetRewindWorkCount;
    ((BtlTargetStatePacketWork *)((BtlPacket *)packet)->workData)->action = (BtlAction *)action;
    return packet;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F3FD0
s32 btlTargetMessageReservedFirstNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4250
s32 btlTargetMessageReservedSecondNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4260
s32 btlTargetMessageReservedThirdNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4270
s32 btlTargetMessageReservedFourthNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4280
s32 btlTargetMessageReservedFifthNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4290
s32 btlTargetMessageReservedSixthNoop(void)
{
    return -1;
}

/* Create a cached-dispatch command packet and clear its execution state. */
// FUN_001F5F70
BtlPacket* btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument,
                        u32 extraArgument, u32 flags)
{
    BtlPacket* packet;
    BtlTargetWork* work;

    packet = btlPacketAlloc(0x800, 0x18);
    packet->updateFunc = btlActionCachedDispatch;
    work = (BtlTargetWork*)packet->workData;
    work->unk00 = action;
    work->unk04 = command;
    work->unk08 = argument;
    work->unk0c = extraArgument;
    work->unk10 = flags;
    work->unk14 = 0;
    return packet;
}

/* Issue the packet's sound playback request and complete immediately. */
/* Issue the packet sound playback request and complete immediately. */
// FUN_001F6000
u32 btlTargetSimpleCommand(BtlTargetSimpleWork* work)
{
    btlSoundRequestPlayback(work->command, work->param);
    return 1;
}

/* Create a workless packet whose update cancels target playback. */
// FUN_001F60C0
BtlPacket* btlTargetCreateEmptyPacket(void)
{
    BtlPacket* packet = btlPacketAlloc(0x802, 0);
    packet->updateFunc = btlTargetCancelPlayback;
    return packet;
}

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */
// FUN_001F9710
s32 btlTargetVoiceReservedFirstNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9720
s32 btlTargetVoiceReservedSecondNoop(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9730
s32 btlTargetVoiceReservedThirdNoop(void)
{
    return -1;
}

// FUN_001F9740
s32 btlTargetVoiceReservedFourthNoop(void)
{
    return -1;
}
