#include "member_access.h"
#include "btl_sound_internal.h"
#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern f32 RwV3dLength(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rotation);
extern void *D_00609850[];


extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern u32 datCalcRandomBelow(u32);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u32 datCalcRandomBelow(u32);



extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 D_00609E40[];
extern u32 datCalcChkBadStatus(s32, u32);
extern s32 datCalcGetBattleStat(s32, s32);
extern s32 datCalcIsDead(s32, s32);
extern u8 *iGpffffb428;
extern u16 cmmCommunityRecordValue(s32);
extern void datSetScriptValue(s32, s32);
extern s32 datCalcIsGuarding(u16 *);
extern u16 cmmCommunityForArcana(s64);
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001eec60-001eff50 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern void btlTargetInitSpring(u8 *, f32);
extern void btlTargetRebuildRadiusLinks(f32 radius);
extern s32 btlTargetBuildSmoothRoute(u8 *route, f32 radius);
extern f32 RwV2dLength(f32 *vector);
extern s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin);
typedef struct RoutePoint {
    f32 x;
    f32 z;
} RoutePoint;
typedef struct RouteNode {
    u8 unknown00[8];
    RoutePoint pos;
    u8 unknown10[0xC];
    f32 g;
    f32 f;
    struct RouteNode *openNext;
    struct RouteNode *closedNext;
    struct RouteNode *parent;
    struct RouteNode *neighbors[32];
    f32 distances[32];
} RouteNode;
/* measured: direct arrays, a separate node alias and edge-array locals all lose MATCH.
 * MEMBER retains the original byte-stride loads while naming the two edge arrays. */
#define ROUTE_NEIGHBOR(n, i) MEMBER(RouteNode *, (u8 *)(n) + (i) * 4, RouteNode, neighbors)
#define ROUTE_DISTANCE(n, i) MEMBER(f32, (u8 *)(n) + (i) * 4, RouteNode, distances)
/* Test whether a route node is already linked into the open search list. */
static inline s32 routeInOpenList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->openNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}
/* Test whether a route node has already moved into the closed search list. */
static inline s32 routeInClosedList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->closedNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}
#pragma push
#pragma pop
/* measured probe: preserve the retail filter branch chain */
#pragma push
/* measured probe: close the filter branch chain */
#pragma pop
/* measured probe: preserve retail conditional branch shape */
#pragma push
/* measured probe: close conditional branch shape */
#pragma pop
/* measured: optimization_level 1 probe for retail GP-load scheduling. */
/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: closes opt_propagation probe for btlAiSetGlobal. */
/* 1468/1472 bytes; all four call relocations resolve exactly. */
/* measured: third 001ec5e0 probe tests opt_propagation off for FPU-zero placement. */
/* measured: closes opt_propagation probe for btlTargetInitSpring. */
#pragma push
#pragma pop
/* The first pass through the route loop reads `cur`, `last` and `seg[1]`
   before anything has written them (001ee71c/001ee730); retail uses the
   stack slots as they are. The C keeps those reads of the uninitialised
   locals. opt_loop_invariants hoists &pts[n] (retail $s5) and pts[0].z
   (retail $f20) out of the subdivision loop. */
#pragma push
#pragma pop
/* measured: object 172B vs window 176B, normalized_diff 2; the remaining
   residual is the best-node register assignment. Committed at nd 2. */
// FUN_001EEC60
/* Remove the lowest-score node from the open list and return it. */
u8 *btlRouteExtractBestOpenNode(void) {
    f32 value;
    f32 max;
    u8 *best;
    u8 *base;
    u8 **headp;
    u8 *scan;
    u8 *current;
    max = (f32)(s32)0x55730;
    base = iGpffffb3ac;
    headp = (u8 **)(base + 0xA3C);
    current = *headp;
    scan = current;
    goto scan_test;
scan_body:
    value = ((RouteNode *)scan)->f;
    if (max <= value)
        goto scan_next;
    best = (u8 *)scan;
    max = value;
scan_next:
    scan = (u8 *)(((RouteNode *)scan)->openNext);
scan_test:
    if (scan != 0)
        goto scan_body;
    scan = 0;
    goto unlink_test;
unlink_body:
    if (current == best)
        goto unlink_done;
    scan = current;
    current = (u8 *)(((RouteNode *)current)->openNext);
unlink_test:
    if (current != 0)
        goto unlink_body;
unlink_done:
    if (current == 0)
        goto return_best;
    if (scan != 0) {
        ((RouteNode *)scan)->openNext = (RouteNode *)((u8 *)(((RouteNode *)current)->openNext));
        goto return_best;
    }
    *headp = (u8 *)(((RouteNode *)current)->openNext);
return_best:
    return best;
}

// FUN_001EED10
/* Use a direct segment when clear, otherwise search the radius-filtered graph and smooth the parent chain. */
s32 btlRouteFindPath(u8 *route, f32 *start, f32 *end, f32 radius)
{
    f32 startDelta[2];
    f32 goalDelta[2];
    u8 *world;
    RouteNode *node;
    f32 x;
    f32 z;
    f32 cost;
    u16 index;
    s32 found;
    s32 inOpen;
    s32 inClosed;

    route[0x404] = 1;
    if (btlTargetLineClear(start, end, 0.5f * radius) == 0) {
        x = start[0];
        z = start[1];
        ((BtlTargetRoute *)route)->points[0].x = x;
        ((BtlTargetRoute *)route)->points[0].z = z;
        x = end[0];
        z = end[1];
        ((BtlTargetRoute *)route)->points[1].x = x;
        ((BtlTargetRoute *)route)->points[1].z = z;
        ((BtlTargetRoute *)route)->count = 2;
        route[0x404] = 2;
        return 1;
    }
    ((BtlTargetRoute *)route)->count = 0;
    world = iGpffffb3ac;
    x = start[0];
    z = start[1];
    ((BtlTargetNavigation *)(world + 0x318))->start.position.x = x;
    ((BtlTargetNavigation *)(world + 0x318))->start.position.z = z;
    x = end[0];
    z = end[1];
    ((BtlTargetNavigation *)(world + 0x318))->goal.position.x = x;
    ((BtlTargetNavigation *)(world + 0x318))->goal.position.z = z;
    btlTargetRebuildRadiusLinks(radius);
    world = iGpffffb3ac;
    if ((s32)(((BtlTargetNavigation *)(world + 0x318))->start.neighbors[0]) == 0 || (s32)(((BtlTargetNavigation *)(world + 0x318))->goal.neighbors[0]) == 0) {
        route[0x404] = 3;
        return 0;
    }
    ((BtlTargetNavigation *)(world + 0x318))->open = (BtlTargetPathNode *)(NULL);
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->closed = (BtlTargetPathNode *)(NULL);
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.cost = 0.0f;
    world = iGpffffb3ac;
    startDelta[0] = ((BtlTargetNavigation *)(world + 0x318))->start.position.x - ((BtlTargetNavigation *)(world + 0x318))->goal.position.x;
    startDelta[1] = ((BtlTargetNavigation *)(world + 0x318))->start.position.z - ((BtlTargetNavigation *)(world + 0x318))->goal.position.z;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.score = RwV2dLength(startDelta);
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.parent = (BtlTargetPathNode *)(NULL);
    world = iGpffffb3ac;
    ((BtlTargetNavigation *)(world + 0x318))->start.openNext = (BtlTargetPathNode *)((u8 *)(((BtlTargetNavigation *)(world + 0x318))->open));
    world = iGpffffb3ac;
    ((BtlTargetNavigation *)(world + 0x318))->open = (BtlTargetPathNode *)(world + 0x7DC);
    found = 0;
    while ((u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->open) != NULL) {
        node = (RouteNode *)btlRouteExtractBestOpenNode();
        if ((u8 *)node == iGpffffb3ac + 0x90C) {
            found = 1;
            break;
        }
        for (index = 0; ROUTE_NEIGHBOR(node, index) != NULL; index++) {
            cost = node->g + ROUTE_DISTANCE(node, index);
            world = iGpffffb3ac;
            inOpen = routeInOpenList((RouteNode *)(((BtlTargetNavigation *)(world + 0x318))->open), ROUTE_NEIGHBOR(node, index));
            inClosed = routeInClosedList((RouteNode *)(((BtlTargetNavigation *)(world + 0x318))->closed), ROUTE_NEIGHBOR(node, index));
            if ((inOpen != 0 || inClosed != 0) && node->g <= cost) {
                continue;
            }
            ROUTE_NEIGHBOR(node, index)->g = cost;
            ROUTE_NEIGHBOR(node, index)->f = cost;
            world = iGpffffb3ac;
            goalDelta[0] = ROUTE_NEIGHBOR(node, index)->pos.x - ((BtlTargetNavigation *)(world + 0x318))->goal.position.x;
            goalDelta[1] = ROUTE_NEIGHBOR(node, index)->pos.z - ((BtlTargetNavigation *)(world + 0x318))->goal.position.z;
            ROUTE_NEIGHBOR(node, index)->f += RwV2dLength(goalDelta);
            ROUTE_NEIGHBOR(node, index)->parent = node;
            if (inClosed != 0) {
                RouteNode **head;
                RouteNode *scanNode;
                RouteNode *prevNode;
                RouteNode *removed;

                removed = ROUTE_NEIGHBOR(node, index);
                prevNode = NULL;
                head = (RouteNode **)(iGpffffb3ac + 0xA40);
                for (scanNode = *head; scanNode != NULL; scanNode = scanNode->closedNext) {
                    if (scanNode == removed) {
                        break;
                    }
                    prevNode = scanNode;
                }
                if (scanNode != NULL) {
                    if (prevNode != NULL) {
                        prevNode->closedNext = scanNode->closedNext;
                    } else {
                        *head = scanNode->closedNext;
                    }
                }
            }
            if (inOpen == 0) {
                ROUTE_NEIGHBOR(node, index)->openNext = (RouteNode *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->open);
                ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->open = (BtlTargetPathNode *)(ROUTE_NEIGHBOR(node, index));
            }
        }
        node->closedNext = (RouteNode *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->closed);
        ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->closed = (BtlTargetPathNode *)(node);
    }
    if (found != 0) {
        btlTargetBuildSmoothRoute(route, radius);
        route[0x404] = 2;
    } else {
        route[0x404] = 3;
    }
    return found;
}

// FUN_001EF110
/* 904/912 bytes; all eighteen relocations resolve exactly.
   Stage both endpoint loads before either store to preserve overlap. */
#pragma push
/* measured: btlRouteBuildArc MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Generate eight XZ samples by interpolating endpoint rotations and distances about a center. */
s32 btlRouteBuildArc(u8 *route, const f32 *startXZ,
                  const f32 *endXZ, const f32 *centerXZ)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
    BtlTargetRotationInterpolation interpolation;
    BtlCameraQuaternion rotation;
    BtlCameraQuaternion startRotation;
    BtlCameraQuaternion endRotation;
    f32 center[3];
    f32 endpoint[3];
    f32 direction[3];
    f32 startLength;
    f32 blend;
    f32 lengthDelta;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 square;
    f32 polynomial;
    f32 finalPolynomial;
    f32 length;
    s32 index;

    ((BtlTargetRoute *)route)->count = 0;
    endpoint[1] = 0.0f;
    center[0] = centerXZ[0];
    center[1] = 0.0f;
    center[2] = centerXZ[1];
    endpoint[0] = startXZ[0];
    endpoint[2] = startXZ[1];
    btlCameraLookAtQuat(&startRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    startLength = RwV3dLength(direction);

    endpoint[0] = endXZ[0];
    endpoint[2] = endXZ[1];
    btlCameraLookAtQuat(&endRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    lengthDelta = RwV3dLength(direction);
    blend = 0.0f;
    func_003dcc70(&startRotation, &endRotation, &interpolation);
    index = 0;
    lengthDelta = lengthDelta - startLength;
    while (index < 7)
    {
        if (blend <= 0.0f)
        {
            rotation = startRotation;
        }
        else if (1.0f <= blend)
        {
            rotation = endRotation;
        }
        else
        {
            firstWeight = 1.0f - blend;
            secondWeight = blend;
            if (interpolation.mode == 0)
            {
                angle = firstWeight * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                firstWeight = polynomial * finalPolynomial + angle;

                angle = blend * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                secondWeight = polynomial * finalPolynomial + angle;
            }
            rotation.imag.x = interpolation.first.imag.x * firstWeight;
            rotation.imag.y = interpolation.first.imag.y * firstWeight;
            rotation.imag.z = interpolation.first.imag.z * firstWeight;
            rotation.imag.x = interpolation.second.imag.x * secondWeight +
                         (0.0f + rotation.imag.x);
            rotation.imag.y = interpolation.second.imag.y * secondWeight +
                         (0.0f + rotation.imag.y);
            rotation.imag.z = interpolation.second.imag.z * secondWeight +
                         (0.0f + rotation.imag.z);
            rotation.real = interpolation.first.real * firstWeight +
                         interpolation.second.real * secondWeight;
        }
        RtQuatTransformVectors(direction, D_0060A0F0, 1, &rotation);
        length = blend * lengthDelta + (0.0f + startLength);
        direction[0] = direction[0] * length;
        direction[1] = direction[1] * length;
        direction[2] = direction[2] * length;
        (((BtlTargetRoute *)(route))->points[index].x) = center[0] + direction[0];
        (((BtlTargetRoute *)(route))->points[index].z) = center[2] + direction[2];
        blend = blend + 0.125f;
        index = index + 1;
    }
    {
        f32 endX = endXZ[0];
        f32 endZ = endXZ[1];
        (((BtlTargetRoute *)(route))->points[7].x) = endX;
        (((BtlTargetRoute *)(route))->points[7].z) = endZ;
    }
    MEMBER(u16, route, BtlTargetRoute, count) = 8;
    ((BtlTargetRoute *)route)->state = 2;
    return 1;
}

#pragma pop
/* Read the low byte of an ID-indexed four-byte record, returning one when it is zero. */
// FUN_001EF4A0
s32 btlUnitSlotValueOrOne(s32 unitId)
{
    s32 value;

    value = ((u8 *)iGpffffb3bc)[(unitId & 0xFFFF) * 4];
    if (value == 0)
    {
        value = 1;
    }
    return value;
}

/* Average levels on the genus-mask sides after excluding statuses; the 16-bit sum wraps and empty results become one. */
// FUN_001EF4D0
/* measured: preserve retail count-result branch shape while probing ef4d0. */
/* Average eligible side levels with 16-bit accumulation; empty and zero results become one. */
s32 btlSideAverageLevel(s32 sideMask, s32 excludedStatus)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 countMask;
    s32 value;

    total = 0;
    count = 0;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    mask = sideMask & 0xFFFF;
    while (current != NULL) {
        if ((((BtlAction *)current)->unk_1a & 1) != 0) {
            entry = (u8 *)(((BtlAction *)current)->unit);
            if ((mask & (1 << ((BtlUnit *)entry)->genus)) != 0) {
                if ((excludedStatus == 0) ||
                    (datCalcChkBadStatus((s32)(((BtlUnit *)entry)->datUnit), excludedStatus) == 0)) {
                    total = (total +
                             (datCalcGetLevel((s32)(((BtlUnit *)entry)->datUnit)) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = (u8 *)(((BtlAction *)current)->next);
    }
    countMask = count & 0xFFFF;
    if (countMask == 0)
        return 1;
    value = ((total & 0xFFFF) / countMask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}

/* measured: close ef4d0 branch-shape probe. */
// FUN_001EF5F0
/* measured: preserve retail count-result branch shape while probing ef5f0. */
/* Average an eligible side stat with 16-bit accumulation; empty and zero results become one. */
s32 btlSideAverageBattleStat(s32 sideMask, s32 stat, s32 excludedStatus)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 countMask;
    s32 value;

    total = 0;
    count = 0;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    mask = sideMask & 0xFFFF;
    while (current != NULL) {
        if ((((BtlAction *)current)->unk_1a & 1) != 0) {
            entry = (u8 *)(((BtlAction *)current)->unit);
            if ((mask & (1 << ((BtlUnit *)entry)->genus)) != 0) {
                if ((excludedStatus == 0) ||
                    (datCalcChkBadStatus((s32)(((BtlUnit *)entry)->datUnit), excludedStatus) == 0)) {
                    total = (total +
                             (datCalcGetBattleStat((s32)(((BtlUnit *)entry)->datUnit), stat) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = (u8 *)(((BtlAction *)current)->next);
    }
    countMask = count & 0xFFFF;
    if (countMask == 0)
        return 1;
    value = ((total & 0xFFFF) / countMask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}

/* measured: close ef5f0 branch-shape probe. */
// FUN_001EF720
/* Count active targetable actions on the selected sides that lack the supplied status mask. */
s32 btlSideCountNotBad(s32 sideMask, s32 excludedStatus)
{
    u8 *current;
    s32 count;
    u8 *entry;
    s32 mask;

    count = 0;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    mask = sideMask & 0xFFFF;
    while (current != NULL)
    {
        if ((((BtlAction *)current)->unk_1a & 1) && (((BtlAction *)current)->unk_1a & 8))
        {
            entry = (u8 *)(((BtlAction *)current)->unit);
            if ((mask & (1 << ((BtlUnit *)entry)->genus)) && (datCalcChkBadStatus((s32)(((BtlUnit *)entry)->datUnit), excludedStatus) == 0))
            {
                count = (count + 1) & 0xFFFF;
            }
        }
        current = (u8 *)(((BtlAction *)current)->next);
    }

    return count;
}

/* measured: object 224B / window 224B / normalized_diff 0; direct pointer/index locals reproduce retail order. */
// FUN_001EF7E0
/* Honor encounter overrides, otherwise roll the turn-indexed chance after an enemy defeat. */
s32 btlEncountRollChance(void)
{
    s32 *encounter;
    s32 flags;
    s32 chanceIndex;
    u16 chance;

    encounter = (s32 *)((s32)gEncountTbl + btlCurrentUnitId() * 24);
    if (((BtlBattleState *)iGpffffb3ac)->unkC5A == 0) {
        return 0;
    }
    flags = *encounter;
    if ((flags & 2) != 0) {
        return 0;
    }
    if ((flags & 4) != 0) {
        return 1;
    }
    if ((u32)(((BtlBattleState *)iGpffffb3ac)->protagonistTurns) == 0) {
        chanceIndex = 0;
    } else if ((u32)(((BtlBattleState *)iGpffffb3ac)->protagonistTurns) > 5) {
        chanceIndex = 4;
    } else {
        chanceIndex = (u32)(((BtlBattleState *)iGpffffb3ac)->protagonistTurns) - 1;
    }
    chance = *(&iGpffffa9b0 + chanceIndex);
    return (u32)datCalcRandomBelow(100) < (u32)chance;
}

// FUN_001EF8C0
/* Combine encounter and setup flags into the movement-state selector. */
s32 btlUnitGetMoveStateCode(void)
{
    /* Read only the low setup flags halfword, not the full packed setup word. */
    u8 *base;
    u8 *table;
    u16 index;
    s32 flags;
    s64 result;
    u16 flags2;

    base = iGpffffb3ac;
    index = ((BtlSoundEncounterRecord *)((u8 *)(((BtlBattleState *)base)->encounterRecord) ))->trackRule;
    table = iGpffffb414 + index * 0x18;
    if ((s32)(((BtlBattleState *)base)->flags) & 0x20000000)
        return 0;
    flags = *(s32 *)table;
    if (flags & 8)
        return 0;
    if (flags & 0x10)
        return 2;
    if (flags & 0x800)
        return 1;
    flags2 = (((BtlBattleState *)(base))->encounter.flags);
    if (flags2 & 4)
        return 0;
    if (flags2 & 1)
        return 2;
    result = (flags2 & 0x10) != 0;
    return (u16)result;
}

// FUN_001EF9A0
s32 btlCurrentUnitId(void) {
    return ((BtlSoundEncounterRecord *)((u8 *)(((BtlBattleState *)iGpffffb3ac)->encounterRecord) ))->trackRule;
}

// FUN_001EF9C0
/* 904/912 bytes; all fifteen relocations resolve exactly. */
/* Select a community-enabled status-assistance target, preferring the selected action. */
s32 btlActionPickStatusTarget(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
    s32 rank;
    u8 *status1Targets[4];
    u8 *status100000Targets[4];
    u8 *status1eTargets[4];
    u8 *node;
    s32 count1;
    s32 count100000;
    s32 count1e;
    u8 *preferred1;
    u8 *preferred100000;
    u8 *preferred1e;
    u8 *actor;
    u16 flags;

    ((BtlTargetAssistance *)(action + 0x444))->kind = -1;
    ((BtlTargetAssistance *)(action + 0x444))->action = NULL;
    actor = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)actor)->genus != 0) {
        return 0;
    }
    if (((BtlUnit *)actor)->charId == 1) {
        return 0;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)actor)->datUnit), 0x1001FF) != 0) {
        return 0;
    }
    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x1000) ||
        ((BtlAction *)action)->state == 9) {
        return 0;
    }
    if (datCalcIsGuarding(((u16 *)(((BtlUnit *)(MEMBER(u8 *, action, BtlAction, unit)))->datUnit))) != 0) {
        return 0;
    }
    rank = cmmCommunityRecordValue(cmmCommunityForArcana(
        ((s16)(((BtlUnit *)(MEMBER(u8 *, action, BtlAction, unit)))->charId))) & 0xFFFF) & 0xFFFF;
    count1 = 0;
    count100000 = 0;
    count1e = 0;
    preferred1 = NULL;
    preferred100000 = NULL;
    preferred1e = NULL;
    node = ((BtlBattleState *)iGpffffb3ac)->actions;
    goto check;
loop:
    flags = ((BtlAction *)node)->unk_1a;
    if ((flags & 1) == 0) goto next;
    if ((flags & 8) == 0) goto next;
    if (node == action) goto next;
    actor = (u8 *)(((BtlAction *)node)->unit);
    if (((BtlUnit *)actor)->genus != 0) goto next;
    if (rank >= 5) {
        if (datCalcChkBadStatus((s32)(((BtlUnit *)actor)->datUnit), 1) != 0) {
            if (((BtlBattleState *)iGpffffb3ac)->selectedAction == node) {
                preferred1 = node;
            }
            status1Targets[count1] = node;
            count1++;
        } else if (datCalcChkBadStatus(MEMBER(s32, actor, BtlUnit, datUnit), 0x100000) != 0) {
            if (((BtlBattleState *)iGpffffb3ac)->selectedAction == node) {
                preferred100000 = node;
            }
            status100000Targets[count100000] = node;
            count100000++;
        }
    }
    if (rank >= 7) {
        if (datCalcChkBadStatus((s32)(((BtlUnit *)actor)->datUnit), 0x1E) != 0) {
            if (((BtlBattleState *)iGpffffb3ac)->selectedAction == node) {
                preferred1e = node;
            }
            status1eTargets[count1e] = node;
            count1e++;
        }
    }
next:
    node = (u8 *)(((BtlAction *)node)->next);
check:
    if (node != NULL) goto loop;
    if (count100000 == 0 && count1e == 0 && count1 == 0) {
        return 0;
    }
    if (count1 != 0) {
        (((BtlAction *)(action))->cooperation.mode) = 1;
        preferred1 = preferred1 != NULL ? preferred1 :
            status1Targets[datCalcRandomBelow(count1)];
        ((BtlTargetAssistance *)(action + 0x444))->action = preferred1;
        return 1;
    }
    if (count100000 != 0) {
        (((BtlAction *)(action))->cooperation.mode) = 1;
        preferred100000 = preferred100000 != NULL ? preferred100000 :
            status100000Targets[datCalcRandomBelow(count100000)];
        ((BtlTargetAssistance *)(action + 0x444))->action = preferred100000;
        return 1;
    }
    if (count1e != 0) {
        (((BtlAction *)(action))->cooperation.mode) = 0;
        preferred1e = preferred1e != NULL ? preferred1e :
            status1eTargets[datCalcRandomBelow(count1e)];
        ((BtlTargetAssistance *)(action + 0x444))->action = preferred1e;
        return 1;
    }
    return 0;
}

// FUN_001EFD50
/* Choose an eligible party action, with skill flag 0x80 bypassing the usual community/status filters. */
u8 *btlActionPickRandomCandidate(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
    s16 skill;
    u8 *candidate;
    s32 count;
    s32 overrideConditions;
    u16 flags;
    u8 *unit;
    s32 candidates[4];

    if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 1) {
        return NULL;
    }
    overrideConditions = 0;
    skill = (s16)(((BtlAction *)action)->unk_6e);
    if ((skill < 0x1B8) &&
        ((((BtlSoundSkill *)iGpffffb3b8)[skill ].flags & 0x80) != 0)) {
        overrideConditions = 1;
    }
    if ((overrideConditions == 0) &&
        ((((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x1000) != 0) ||
         (((BtlAction *)action)->state == 9))) {
        return NULL;
    }
    count = 0;
    candidate = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (candidate != NULL) {
        flags = ((BtlAction *)candidate)->unk_1a;
        if (((flags & 1) != 0) &&
            ((flags & 8) != 0) &&
            ((overrideConditions != 0) || ((flags & 0x80) == 0)) &&
            (candidate != action)) {
            unit = (u8 *)(((BtlAction *)candidate)->unit);
            if ((((BtlUnit *)unit)->genus == 0) &&
                (((BtlUnit *)unit)->charId != 1) &&
                ((overrideConditions != 0) ||
                 (datCalcChkBadStatus((s32)(((BtlUnit *)unit)->datUnit), 0x1001FF) == 0)) &&
                (datCalcIsDead((s32)(((BtlUnit *)unit)->datUnit), 0) == 0) &&
                ((overrideConditions != 0) ||
                 ((cmmCommunityRecordValue((cmmCommunityForArcana(MEMBER(s16, unit, BtlUnit, charId)) &
                                   0xFFFF)) &
                   0xFFFF) > 0))) {
                candidates[count] = (s32)candidate;
                count += 1;
            }
        }
        candidate = (u8 *)(((BtlAction *)candidate)->next);
    }
    if (count == 0) {
        return NULL;
    }
    return (u8 *)candidates[datCalcRandomBelow(count)];
}

// FUN_001EFF50
/* Choose an eligible community counter target after cooldown and per-unit probability checks. */
s32 btlActionPickCounterTarget(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
    s32 bonus;
    s32 roll;
    u8 *candidate;
    s32 count;
    u16 flags;
    u8 *unit;
    s32 candidates[4];

    if ((((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x1000) != 0) ||
        (((BtlAction *)action)->state == 9)) {
        return 0;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit),
                      0x100117) != 0) {
        return 0;
    }
    if (((BtlAction *)action)->unk_28 < 2) {
        roll = datGetScriptValue(0x79) -
                 (MEMBER(u8, action, BtlAction, unk_28) + 1);
        if (roll > 0) {
            datSetScriptValue(0x79, roll);
            return 0;
        }
    }
    count = 0;
    candidate = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (candidate != NULL) {
        flags = ((BtlAction *)candidate)->unk_1a;
        if (((flags & 1) != 0) &&
            ((flags & 8) != 0) &&
            (candidate != action)) {
            unit = (u8 *)(((BtlAction *)candidate)->unit);
            if ((((BtlUnit *)unit)->genus == 0) &&
                (((BtlUnit *)unit)->charId != 1) &&
                (datCalcChkBadStatus((s32)(((BtlUnit *)unit)->datUnit),
                                0x1001FF) == 0) &&
                (datCalcIsDead(MEMBER(s32, unit, BtlUnit, datUnit), 0) == 0) &&
                (datCalcIsGuarding(MEMBER(u16 *, unit, BtlUnit, datUnit)) == 0) &&
                ((cmmCommunityRecordValue((cmmCommunityForArcana(
                                    MEMBER(s16, unit, BtlUnit, charId)) &
                                  0xFFFF)) &
                  0xFFFF) >= 3)) {
                bonus =
                    (datCalcCountSlotsWithValue(MEMBER(u8 *, unit, BtlUnit, datUnit), 0x88) &
                     0xFFFF) *
                    10;
                roll = datCalcRandomBelow(0x64);
                if ((u32)roll > (u32)(bonus + 0x3C)) {
                } else {
                    candidates[count] = (s32)candidate;
                    count += 1;
                }
            }
        }
        candidate = (u8 *)(((BtlAction *)candidate)->next);
    }
    if (count == 0) {
        return 0;
    }
    datSetScriptValue(0x79, datCalcRandomBelow(3) + 3);
    return candidates[datCalcRandomBelow(count)];
}

