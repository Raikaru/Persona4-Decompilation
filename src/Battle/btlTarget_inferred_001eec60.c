#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern f32 RwV3dLength(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rotation);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern u32 datCalcRandomBelow(u32 arg0);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u32 datCalcRandomBelow(u32 arg0);



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
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBattleStat(s32 arg0, s32 arg1);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *iGpffffb428;
extern u16 func_00107ac0(s32 arg0);
extern void func_00106550(s32 arg0, s32 arg1);
extern s32 datCalcIsStatusBlocked(u16 *arg0);
extern u16 cmmCommunityForArcana(s64 arg0);
extern u8 *iGpffffb42c;

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001eec60-001eff50 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern void func_001ec5e0(u8 *arg0, f32 arg1);
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
#define ROUTE_NEIGHBOR(n, i) (*(RouteNode **)((u8 *)(n) + (i) * 4 + 0x30))
#define ROUTE_DISTANCE(n, i) (*(f32 *)((u8 *)(n) + (i) * 4 + 0xB0))
static inline s32 routeInOpenList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->openNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}
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
/* measured: closes opt_propagation probe for func_001ec5e0. */
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
    value = *(f32 *)(scan + 0x20);
    if (max <= value)
        goto scan_next;
    best = (u8 *)scan;
    max = value;
scan_next:
    scan = *(u8 **)(scan + 0x24);
scan_test:
    if (scan != 0)
        goto scan_body;
    scan = 0;
    goto unlink_test;
unlink_body:
    if (current == best)
        goto unlink_done;
    scan = current;
    current = *(u8 **)(current + 0x24);
unlink_test:
    if (current != 0)
        goto unlink_body;
unlink_done:
    if (current == 0)
        goto return_best;
    if (scan != 0) {
        *(u8 **)(scan + 0x24) = *(u8 **)(current + 0x24);
        goto return_best;
    }
    *headp = *(u8 **)(current + 0x24);
return_best:
    return best;
}

// FUN_001EED10
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
        *(f32 *)(route + 0x0) = x;
        *(f32 *)(route + 0x4) = z;
        x = end[0];
        z = end[1];
        *(f32 *)(route + 0x8) = x;
        *(f32 *)(route + 0xC) = z;
        *(u16 *)(route + 0x400) = 2;
        route[0x404] = 2;
        return 1;
    }
    *(u16 *)(route + 0x400) = 0;
    world = iGpffffb3ac;
    x = start[0];
    z = start[1];
    *(f32 *)(world + 0x7E4) = x;
    *(f32 *)(world + 0x7E8) = z;
    x = end[0];
    z = end[1];
    *(f32 *)(world + 0x914) = x;
    *(f32 *)(world + 0x918) = z;
    btlTargetRebuildRadiusLinks(radius);
    world = iGpffffb3ac;
    if (*(s32 *)(world + 0x80C) == 0 || *(s32 *)(world + 0x93C) == 0) {
        route[0x404] = 3;
        return 0;
    }
    *(u8 **)(world + 0xA3C) = NULL;
    *(u8 **)(iGpffffb3ac + 0xA40) = NULL;
    *(f32 *)(iGpffffb3ac + 0x7F8) = 0.0f;
    world = iGpffffb3ac;
    startDelta[0] = *(f32 *)(world + 0x7E4) - *(f32 *)(world + 0x914);
    startDelta[1] = *(f32 *)(world + 0x7E8) - *(f32 *)(world + 0x918);
    *(f32 *)(iGpffffb3ac + 0x7FC) = RwV2dLength(startDelta);
    *(u8 **)(iGpffffb3ac + 0x808) = NULL;
    world = iGpffffb3ac;
    *(u8 **)(world + 0x800) = *(u8 **)(world + 0xA3C);
    world = iGpffffb3ac;
    *(u8 **)(world + 0xA3C) = world + 0x7DC;
    found = 0;
    while (*(u8 **)(iGpffffb3ac + 0xA3C) != NULL) {
        node = (RouteNode *)btlRouteExtractBestOpenNode();
        if ((u8 *)node == iGpffffb3ac + 0x90C) {
            found = 1;
            break;
        }
        for (index = 0; ROUTE_NEIGHBOR(node, index) != NULL; index++) {
            cost = node->g + ROUTE_DISTANCE(node, index);
            world = iGpffffb3ac;
            inOpen = routeInOpenList(*(RouteNode **)(world + 0xA3C), ROUTE_NEIGHBOR(node, index));
            inClosed = routeInClosedList(*(RouteNode **)(world + 0xA40), ROUTE_NEIGHBOR(node, index));
            if ((inOpen != 0 || inClosed != 0) && node->g <= cost) {
                continue;
            }
            ROUTE_NEIGHBOR(node, index)->g = cost;
            ROUTE_NEIGHBOR(node, index)->f = cost;
            world = iGpffffb3ac;
            goalDelta[0] = ROUTE_NEIGHBOR(node, index)->pos.x - *(f32 *)(world + 0x914);
            goalDelta[1] = ROUTE_NEIGHBOR(node, index)->pos.z - *(f32 *)(world + 0x918);
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
                ROUTE_NEIGHBOR(node, index)->openNext = *(RouteNode **)(iGpffffb3ac + 0xA3C);
                *(RouteNode **)(iGpffffb3ac + 0xA3C) = ROUTE_NEIGHBOR(node, index);
            }
        }
        node->closedNext = *(RouteNode **)(iGpffffb3ac + 0xA40);
        *(RouteNode **)(iGpffffb3ac + 0xA40) = node;
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
s32 btlRouteBuildArc(u8 *route, const f32 *startXZ,
                  const f32 *endXZ, const f32 *centerXZ)
{
    P4RouteSlerp_001EF110 interpolation;
    P4Vec4_001EC2B0 rotation;
    P4Vec4_001EC2B0 startRotation;
    P4Vec4_001EC2B0 endRotation;
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

    *(u16 *)(route + 0x400) = 0;
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
            rotation.x = interpolation.first.x * firstWeight;
            rotation.y = interpolation.first.y * firstWeight;
            rotation.z = interpolation.first.z * firstWeight;
            rotation.x = interpolation.second.x * secondWeight +
                         (0.0f + rotation.x);
            rotation.y = interpolation.second.y * secondWeight +
                         (0.0f + rotation.y);
            rotation.z = interpolation.second.z * secondWeight +
                         (0.0f + rotation.z);
            rotation.w = interpolation.first.w * firstWeight +
                         interpolation.second.w * secondWeight;
        }
        RtQuatTransformVectors(direction, D_0060A0F0, 1, &rotation);
        length = blend * lengthDelta + (0.0f + startLength);
        direction[0] = direction[0] * length;
        direction[1] = direction[1] * length;
        direction[2] = direction[2] * length;
        *(f32 *)(route + index * 8) = center[0] + direction[0];
        *(f32 *)(route + index * 8 + 4) = center[2] + direction[2];
        blend = blend + 0.125f;
        index = index + 1;
    }
    {
        f32 endX = endXZ[0];
        f32 endZ = endXZ[1];
        *(f32 *)(route + 0x38) = endX;
        *(f32 *)(route + 0x3C) = endZ;
    }
    *(u16 *)(route + 0x400) = 8;
    *(u8 *)(route + 0x404) = 2;
    return 1;
}

#pragma pop
// FUN_001EF4A0
s32 btlUnitSlotValueOrOne(s32 arg0)
{
    s32 value;

    value = ((u8 *)iGpffffb3bc)[(arg0 & 0xFFFF) * 4];
    if (value == 0)
    {
        value = 1;
    }
    return value;
}

// FUN_001EF4D0
/* measured: preserve retail count-result branch shape while probing ef4d0. */
s32 btlSideAverageLevel(s32 arg0, s32 arg1)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg1 == 0) ||
                    (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg1) == 0)) {
                    total = (total +
                             (datCalcGetLevel(*(s32 *)(entry + 0xA64)) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}

/* measured: close ef4d0 branch-shape probe. */
// FUN_001EF5F0
/* measured: preserve retail count-result branch shape while probing ef5f0. */
s32 btlSideAverageBattleStat(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg2 == 0) ||
                    (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg2) == 0)) {
                    total = (total +
                             (datCalcGetBattleStat(*(s32 *)(entry + 0xA64), arg1) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}

/* measured: close ef5f0 branch-shape probe. */
// FUN_001EF720
s32 btlSideCountNotBad(s32 arg0, s32 arg1)
{
    u8 *current;
    s32 count;
    u8 *entry;
    s32 mask;

    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL)
    {
        if ((*(u16 *)(current + 0x1A) & 1) && (*(u16 *)(current + 0x1A) & 8))
        {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) && (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg1) == 0))
            {
                count = (count + 1) & 0xFFFF;
            }
        }
        current = *(u8 **)(current + 0x450);
    }

    return count;
}

/* measured: object 224B / window 224B / normalized_diff 0; direct pointer/index locals reproduce retail order. */
// FUN_001EF7E0
s32 btlEncountRollChance(void)
{
    s32 *temp_3;
    s32 temp_3_2;
    s32 var_3;
    u16 temp_16;

    temp_3 = (s32 *)((s32)gEncountTbl + btlCurrentUnitId() * 24);
    if (*(u16 *)(iGpffffb3ac + 0xC5A) == 0) {
        return 0;
    }
    temp_3_2 = *temp_3;
    if ((temp_3_2 & 2) != 0) {
        return 0;
    }
    if ((temp_3_2 & 4) != 0) {
        return 1;
    }
    if (*(u32 *)(iGpffffb3ac + 0x20) == 0) {
        var_3 = 0;
    } else if (*(u32 *)(iGpffffb3ac + 0x20) > 5) {
        var_3 = 4;
    } else {
        var_3 = *(u32 *)(iGpffffb3ac + 0x20) - 1;
    }
    temp_16 = *(&iGpffffa9b0 + var_3);
    return (u32)datCalcRandomBelow(100) < (u32)temp_16;
}

// FUN_001EF8C0
s32 btlUnitGetMoveStateCode(void)
{
    u8 *base;
    u8 *table;
    u16 index;
    s32 flags;
    s64 result;
    u16 flags2;

    base = iGpffffb3ac;
    index = *(u16 *)(*(u8 **)(base + 0xC68) + 8);
    table = iGpffffb414 + index * 0x18;
    if (*(s32 *)(base + 0xC) & 0x20000000)
        return 0;
    flags = *(s32 *)table;
    if (flags & 8)
        return 0;
    if (flags & 0x10)
        return 2;
    if (flags & 0x800)
        return 1;
    flags2 = *(u16 *)(base + 0xC70);
    if (flags2 & 4)
        return 0;
    if (flags2 & 1)
        return 2;
    result = (flags2 & 0x10) != 0;
    return (u16)result;
}

// FUN_001EF9A0
s32 btlCurrentUnitId(void) {
    return *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
}

// FUN_001EF9C0
/* 904/912 bytes; all fifteen relocations resolve exactly. */
s32 btlActionPickStatusTarget(u8 *action)
{
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

    *(s16 *)(action + 0x448) = -1;
    *(u8 **)(action + 0x444) = NULL;
    actor = *(u8 **)(action + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) {
        return 0;
    }
    if (*(u16 *)(actor + 0xA4) == 1) {
        return 0;
    }
    if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x1001FF) != 0) {
        return 0;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x1000) ||
        *(u16 *)(action + 0x14) == 9) {
        return 0;
    }
    if (datCalcIsStatusBlocked(*(u16 **)(*(u8 **)(action + 0x30) + 0xA64)) != 0) {
        return 0;
    }
    rank = func_00107ac0(cmmCommunityForArcana(
        *(s16 *)(*(u8 **)(action + 0x30) + 0xA4)) & 0xFFFF) & 0xFFFF;
    count1 = 0;
    count100000 = 0;
    count1e = 0;
    preferred1 = NULL;
    preferred100000 = NULL;
    preferred1e = NULL;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    flags = *(u16 *)(node + 0x1A);
    if ((flags & 1) == 0) goto next;
    if ((flags & 8) == 0) goto next;
    if (node == action) goto next;
    actor = *(u8 **)(node + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) goto next;
    if (rank >= 5) {
        if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 1) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1 = node;
            }
            status1Targets[count1] = node;
            count1++;
        } else if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x100000) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred100000 = node;
            }
            status100000Targets[count100000] = node;
            count100000++;
        }
    }
    if (rank >= 7) {
        if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x1E) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1e = node;
            }
            status1eTargets[count1e] = node;
            count1e++;
        }
    }
next:
    node = *(u8 **)(node + 0x450);
check:
    if (node != NULL) goto loop;
    if (count100000 == 0 && count1e == 0 && count1 == 0) {
        return 0;
    }
    if (count1 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred1 = preferred1 != NULL ? preferred1 :
            status1Targets[datCalcRandomBelow(count1)];
        *(u8 **)(action + 0x444) = preferred1;
        return 1;
    }
    if (count100000 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred100000 = preferred100000 != NULL ? preferred100000 :
            status100000Targets[datCalcRandomBelow(count100000)];
        *(u8 **)(action + 0x444) = preferred100000;
        return 1;
    }
    if (count1e != 0) {
        *(s16 *)(action + 0x448) = 0;
        preferred1e = preferred1e != NULL ? preferred1e :
            status1eTargets[datCalcRandomBelow(count1e)];
        *(u8 **)(action + 0x444) = preferred1e;
        return 1;
    }
    return 0;
}

// FUN_001EFD50
u8 *btlActionPickRandomCandidate(u8 *arg0)
{
    s16 temp_3;
    u8 *var_19;
    s32 var_18;
    s32 var_17;
    u16 temp_3_2;
    u8 *temp_16;
    s32 candidates[4];

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return NULL;
    }
    var_17 = 0;
    temp_3 = *(s16 *)(arg0 + 0x6E);
    if ((temp_3 < 0x1B8) &&
        ((*(u8 *)(iGpffffb3b8 + (temp_3 * 0x28)) & 0x80) != 0)) {
        var_17 = 1;
    }
    if ((var_17 == 0) &&
        (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
         (*(u16 *)(arg0 + 0x14) == 9))) {
        return NULL;
    }
    var_18 = 0;
    var_19 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_19 != NULL) {
        temp_3_2 = *(u16 *)(var_19 + 0x1A);
        if (((temp_3_2 & 1) != 0) &&
            ((temp_3_2 & 8) != 0) &&
            ((var_17 != 0) || ((temp_3_2 & 0x80) == 0)) &&
            (var_19 != arg0)) {
            temp_16 = *(u8 **)(var_19 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                ((var_17 != 0) ||
                 (datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0x1001FF) == 0)) &&
                (datCalcIsDead(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                ((var_17 != 0) ||
                 ((func_00107ac0((cmmCommunityForArcana(*(s16 *)(temp_16 + 0xA4)) &
                                   0xFFFF)) &
                   0xFFFF) > 0))) {
                candidates[var_18] = (s32)var_19;
                var_18 += 1;
            }
        }
        var_19 = *(u8 **)(var_19 + 0x450);
    }
    if (var_18 == 0) {
        return NULL;
    }
    return (u8 *)candidates[datCalcRandomBelow(var_18)];
}

// FUN_001EFF50
s32 btlActionPickCounterTarget(u8 *arg0)
{
    s32 temp_16_2;
    s32 temp_5;
    u8 *var_18;
    s32 var_17;
    u16 temp_3;
    u8 *temp_16;
    s32 candidates[4];

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
        (*(u16 *)(arg0 + 0x14) == 9)) {
        return 0;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x100117) != 0) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x28) < 2) {
        temp_5 = func_001064f0(0x79) -
                 (*(u8 *)(arg0 + 0x28) + 1);
        if (temp_5 > 0) {
            func_00106550(0x79, temp_5);
            return 0;
        }
    }
    var_17 = 0;
    var_18 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_18 != NULL) {
        temp_3 = *(u16 *)(var_18 + 0x1A);
        if (((temp_3 & 1) != 0) &&
            ((temp_3 & 8) != 0) &&
            (var_18 != arg0)) {
            temp_16 = *(u8 **)(var_18 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                (datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64),
                                0x1001FF) == 0) &&
                (datCalcIsDead(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                (datCalcIsStatusBlocked(*(u16 **)(temp_16 + 0xA64)) == 0) &&
                ((func_00107ac0((cmmCommunityForArcana(
                                    *(s16 *)(temp_16 + 0xA4)) &
                                  0xFFFF)) &
                  0xFFFF) >= 3)) {
                temp_16_2 =
                    (datCalcCountSlotsWithValue(*(u8 **)(temp_16 + 0xA64), 0x88) &
                     0xFFFF) *
                    10;
                temp_5 = datCalcRandomBelow(0x64);
                if ((u32)temp_5 > (u32)(temp_16_2 + 0x3C)) {
                } else {
                    candidates[var_17] = (s32)var_18;
                    var_17 += 1;
                }
            }
        }
        var_18 = *(u8 **)(var_18 + 0x450);
    }
    if (var_17 == 0) {
        return 0;
    }
    func_00106550(0x79, datCalcRandomBelow(3) + 3);
    return candidates[datCalcRandomBelow(var_17)];
}

