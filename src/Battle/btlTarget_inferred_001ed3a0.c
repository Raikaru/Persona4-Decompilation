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
                          const void *second, const void *up);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *btlTargetOffsetAddress(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;





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
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001ed3a0-001ee610 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern void btlTargetInitSpring(u8 *, f32);
extern int btlTargetCheckObstacleCrossings(float *first, float *second);
typedef struct BtlTargetNeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    u8 rest[0x114];
} BtlTargetNeighborNode;
typedef struct BtlTargetNeighborGroup {
    s32 unknown0;
    s32 unknown4;
    BtlTargetNeighborNode nodes[4];
    struct BtlTargetNeighborGroup *previous;
    struct BtlTargetNeighborGroup *next;
} BtlTargetNeighborGroup;
extern s32 btlTargetRangeCheck(u8 *first, u8 *second);
extern f32 RwV2dLength(f32 *vector);
typedef struct BtlTargetNeighborWorld {
    u8 prefix[0x318];
    BtlTargetNeighborGroup *groups;
    BtlTargetNeighborNode nodes[4];
    BtlTargetNeighborNode start;
    BtlTargetNeighborNode goal;
} BtlTargetNeighborWorld;
extern s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin);
extern void btlTargetRebuildRadiusLinks(f32 radius);
extern s32 btlTargetBuildSmoothRoute(u8 *route, f32 radius);
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
// FUN_001ED3A0
/* 852/864 bytes; all eighteen relocations resolve exactly.
   Array types preserve halfword indexing; local order preserves lifetimes. */
/* Collect reachable radius-qualified neighbors and their planar distances, including start and goal. */
s32 btlTargetCollectRouteNeighbors(u8 *node, f32 threshold)
{
    /* measured: typed forms of the retained raw accesses changed code generation;
     * keep byte-pointer aliasing at these sites to preserve the retail sequence. */
    f32 linkedDelta[2];
    f32 fixedDelta[2];
    f32 startDelta[2];
    f32 goalDelta[2];
    f32 distance;
    BtlTargetNeighborGroup *group;
    s32 count;
    u16 index;
    u8 *neighbor;

    count = 0;
    group = (BtlTargetNeighborGroup *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles);
    while (group != 0) {
        for (index = 0; index < 4; index++) {
            neighbor = (u8 *)&group->nodes[index];
            if (neighbor == node)
                continue;
            if (group->nodes[index].active <= 0.0f)
                continue;
            if (group->nodes[index].clearance < threshold)
                continue;
            if (btlTargetRangeCheck(node, neighbor) != 0)
                continue;
            linkedDelta[0] = ((RouteNode *)node)->pos.x - *(f32 *)((u8 *)group + index * 0x130 + 0x10);
            linkedDelta[1] = ((RouteNode *)node)->pos.z - *(f32 *)((u8 *)group + index * 0x130 + 0x14);
            distance = RwV2dLength(linkedDelta);
        ((RouteNode *)node)->distances[(u16)count] = distance;
            ((RouteNode *)node)->neighbors[(u16)count] = (RouteNode *)(neighbor);
            count = (u16)(count + 1);
        }
        group = group->next;
    }
    for (index = 0; index < 4; index++) {
        if ((u8 *)&((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index] == node)
            continue;
        if (((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index].active <= 0.0f)
            continue;
        if (btlTargetRangeCheck(node, (u8 *)&((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index]) != 0)
            continue;
        fixedDelta[0] = ((RouteNode *)node)->pos.x - ((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index].x;
        fixedDelta[1] = ((RouteNode *)node)->pos.z - ((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index].z;
        distance = RwV2dLength(fixedDelta);
        ((RouteNode *)node)->distances[(u16)count] = distance;
        ((RouteNode *)node)->neighbors[(u16)count] = (RouteNode *)((u8 *)&((BtlTargetNeighborWorld *)iGpffffb3ac)->nodes[index]);
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x7DC != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x7DC) == 0) {
        startDelta[0] = ((RouteNode *)node)->pos.x - ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.position.x;
        startDelta[1] = ((RouteNode *)node)->pos.z - ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.position.z;
        distance = RwV2dLength(startDelta);
        *(f32 *)(btlTargetOffsetAddress((u16)count * 4, node) + 0xB0) = distance;
        ((RouteNode *)node)->neighbors[(u16)count] = (RouteNode *)(iGpffffb3ac + 0x7DC);
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x90C != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x90C) == 0) {
        goalDelta[0] = ((RouteNode *)node)->pos.x - ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->goal.position.x;
        goalDelta[1] = ((RouteNode *)node)->pos.z - ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->goal.position.z;
        distance = RwV2dLength(goalDelta);
        *(f32 *)(btlTargetOffsetAddress((u16)count * 4, node) + 0xB0) = distance;
        ((RouteNode *)node)->neighbors[(u16)count] = (RouteNode *)(iGpffffb3ac + 0x90C);
        count = (u16)(count + 1);
    }
    *(u8 **)(btlTargetOffsetAddress((u16)count * 4, node) + 0x30) = 0;
    return count;
}

#pragma push
/* measured: btlTargetRebuildRadiusLinks MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: btlTargetRebuildRadiusLinks MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: btlTargetRebuildRadiusLinks MATCH -> MISMATCH without this pragma. */
#pragma opt_dead_assignments off
// FUN_001ED700
/* Rebuild obstacle midpoint links and route neighbors for the requested clearance radius. */
void btlTargetRebuildRadiusLinks(f32 radius)
{
    /* measured: typed forms of the retained raw accesses changed code generation;
     * keep byte-pointer aliasing at these sites to preserve the retail sequence. */
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 RwV2dLength(f32 *vec);
    extern f32 D_0060A120[];
    extern f32 fGpffff8330;
    typedef BtlTargetPoint FieldPair;
    struct { s16 x; s16 y; } corners[4];
    f32 bounds[4];
    f32 f0;
    u8 *other;
    f32 cur[2];
    f32 norm[2];
    f32 delta[2];
    f32 bestDir[2];
    f32 wpos[2];
    f32 bestH;
    f32 wposZ;
    s32 j;
    u8 *group;
    u8 *best;
    s32 i;
    s32 t;
    s16 tx;
    s16 ty;
    s16 q;
    f32 dist;
    f32 bestDist;
    f32 bestX;
    f32 bestZ;
    f32 curZ;
    s32 first;

    first = 0;
    for (group = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles); group != NULL; group = (u8 *)(((BtlTargetObstacle *)group)->next)) {
        if (first == 0) {
            s16 v;

            v = ((BtlTargetObstacle *)group)->cellX;
            corners[3].x = v;
            corners[2].x = v;
            corners[1].x = v;
            corners[0].x = v;
            v = ((BtlTargetObstacle *)group)->cellZ;
            corners[3].y = v;
            corners[2].y = v;
            corners[1].y = v;
            corners[0].y = v;
            f0 = ((BtlTargetObstacle *)group)->radius;
            bounds[3] = f0;
            bounds[2] = f0;
            bounds[1] = f0;
            bounds[0] = f0;
            first = 1;
        } else {
            tx = ((BtlTargetObstacle *)group)->cellX;
            ty = ((BtlTargetObstacle *)group)->cellZ;
            if ((corners[0].x >= tx) && (corners[0].y >= ty)) {
                corners[0].x = tx;
                corners[0].y = ty;
                bounds[0] = ((BtlTargetObstacle *)group)->radius;
            }
            if ((corners[1].x <= tx) && (corners[1].y >= ty)) {
                corners[1].x = tx;
                corners[1].y = ty;
                bounds[1] = ((BtlTargetObstacle *)group)->radius;
            }
            if ((corners[2].x <= tx) && (corners[2].y <= ty)) {
                corners[2].x = tx;
                corners[2].y = ty;
                bounds[2] = ((BtlTargetObstacle *)group)->radius;
            }
            if ((corners[3].x >= tx) && (corners[3].y <= ty)) {
                corners[3].x = tx;
                corners[3].y = ty;
                bounds[3] = ((BtlTargetObstacle *)group)->radius;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        t = (s32)(bounds[i] + 500.0f);
        q = (s16)(t / 25);
        if (t % 25 != 0) {
            q++;
        }
        switch (i) {
        case 0:
            tx = (s16)(corners[i].x - q);
            ty = (s16)(corners[i].y - q);
            if (tx < 0) {
                tx = 0;
            }
            if (ty < 0) {
                ty = 0;
            }
            break;
        case 1:
            tx = (s16)(q + corners[i].x);
            ty = (s16)(corners[i].y - q);
            if (ty < 0) {
                ty = 0;
            }
            break;
        case 2:
            tx = (s16)(q + corners[i].x);
            ty = (s16)(q + corners[i].y);
            break;
        case 3:
            tx = (s16)(corners[i].x - q);
            ty = (s16)(q + corners[i].y);
            if (tx < 0) {
                tx = 0;
            }
            break;
        }
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x31C) = (f32)(tx * 25 - 1750);
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x320) = (f32)(ty * 25 - 1750);
    }
    for (group = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles); group != NULL; group = (u8 *)(((BtlTargetObstacle *)group)->next)) {
        for (i = 0; i < 4; i++) {
            best = NULL;
            bestDist = 7000.0f;
            *(FieldPair *)cur = ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].position;
            other = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles);
            curZ = cur[1];
            for (; other != NULL; other = (u8 *)(((BtlTargetObstacle *)other)->next)) {
                if (group != other) {
                    for (j = 0; j < 4; j++) {
                        u8 *entry = other + j * 0x130;

                        delta[0] = ((BtlTargetObstacle *)entry)->corners[0].position.x - cur[0];
                        delta[1] = ((BtlTargetObstacle *)entry)->corners[0].position.z - curZ;
                        dist = func_003e41e0(norm, delta);
                        if (!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) {
                            if (btlTargetCheckObstacleCrossings((float *)(group + i * 0x130 + 8), (float *)(entry += 8)) == 0) {
                                *(s64 *)bestDir = *(s64 *)norm;
                                best = entry;
                                bestDist = dist;
                                bestX = (f32)(((BtlTargetObstacle *)other)->cellX * 25 - 1750);
                                bestZ = (f32)(((BtlTargetObstacle *)other)->cellZ * 25 - 1750);
                                bestH = ((BtlTargetObstacle *)other)->radius;
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 4; j++) {
                u8 *base = iGpffffb3ac;

                delta[0] = *(f32 *)(base + j * 0x130 + 0x31C) - cur[0];
                delta[1] = ((BtlTargetNavigation *)(base + 0x318))->boundary[j].position.z - curZ;
                dist = func_003e41e0(norm, delta);
                if ((!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) && (btlTargetCheckObstacleCrossings((float *)(group + i * 0x130 + 8), (float *)(iGpffffb3ac + j * 0x130 + 0x31C)) == 0)) {
                    *(s64 *)bestDir = *(s64 *)norm;
                    best = iGpffffb3ac + j * 0x130 + 0x31C;
                    bestDist = dist;
                    bestX = ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[j].position.x;
                    bestZ = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x320);
                    bestH = 0.0f;
                }
            }
            if (best != NULL) {
                f32 half;
                f32 dx;
                half = 0.5f * bestDist;
                dx = bestDir[0] * half;
                bestDir[0] = dx;
                bestDir[1] = bestDir[1] * half;
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].midpoint.x = cur[0] + dx;
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].midpoint.z = curZ + bestDir[1];
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].link = (BtlTargetPoint *)(best);
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].linkDistance = bestDist;
                delta[0] = (f32)(((BtlTargetObstacle *)group)->cellX * 25 - 1750);
                delta[1] = (f32)(((BtlTargetObstacle *)group)->cellZ * 25 - 1750);
                delta[0] = delta[0] - bestX;
                delta[1] = delta[1] - bestZ;
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].clearance = RwV2dLength(delta) - (((BtlTargetObstacle *)group)->radius + bestH);            } else {
                ((BtlTargetObstacle *)(group + i * 0x130))->corners[0].linkDistance = -1.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        best = NULL;
        bestDist = 7000.0f;
        {
            u8 *base = iGpffffb3ac;

            *(FieldPair *)wpos = *(FieldPair *)(base + i * 0x130 + 0x31C);
            other = (u8 *)(((BtlTargetNavigation *)(base + 0x318))->obstacles);
        }
        wposZ = wpos[1];
        for (; other != NULL; other = (u8 *)(((BtlTargetObstacle *)other)->next)) {
            for (j = 0; j < 4; j++) {
                u8 *entry = other + j * 0x130;

                delta[0] = ((BtlTargetObstacle *)entry)->corners[0].position.x - wpos[0];
                delta[1] = ((BtlTargetObstacle *)entry)->corners[0].position.z - wposZ;
                dist = RwV2dLength(delta);
                if (dist < bestDist) {
                    func_003e41e0(bestDir, delta);
                    best = entry + 8;
                    bestDist = dist;
                }
            }
        }
        if (best != NULL) {
            if ((u8 *)(((BtlTargetCorner *)best)->link) != iGpffffb3ac + i * 0x130 + 0x31C) {
                f32 half;
                half = 0.5f * bestDist;
                bestDir[0] = bestDir[0] * half;
                bestDir[1] = bestDir[1] * half;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x324) = wpos[0] + bestDir[0];
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x328) = wposZ + bestDir[1];
                *(u8 **)(iGpffffb3ac + i * 0x130 + 0x32C) = best;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = bestDist;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x334) = 500.0f;
            } else {
                ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[i].linkDistance = -1.0f;
            }
        } else {
            *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
        }
    }
    for (group = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles); group != NULL; group = (u8 *)(((BtlTargetObstacle *)group)->next)) {
        for (i = 0; i < 4; i++) {
            u8 *corner = group + i * 0x130 + 8;

            if (!(((BtlTargetCorner *)corner)->linkDistance <= 0.0f) && !(((BtlTargetCorner *)corner)->clearance < radius)) {
                btlTargetCollectRouteNeighbors(corner, radius);
            } else {
                *(s32 *)(corner + 0x30) = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        u8 *corner = iGpffffb3ac + i * 0x130 + 0x31C;

        if (!(((BtlTargetCorner *)corner)->linkDistance <= 0.0f)) {
            btlTargetCollectRouteNeighbors(corner, radius);
        } else {
            *(s32 *)(corner + 0x30) = 0;
        }
    }
    btlTargetCollectRouteNeighbors(iGpffffb3ac + 0x7DC, radius);
    btlTargetCollectRouteNeighbors(iGpffffb3ac + 0x90C, radius);
}

#pragma pop
// FUN_001EE1C0
/* Clear the obstacle list and restore the four world boundary corners at +/-1750. */
void btlTargetResetRadiusState(void) {
    f32 maximum;
    f32 minimum;

    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles = (BtlTargetObstacle *)(0);
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->start.unk14.bits = 0xBF800000;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->goal.unk14.bits = 0xBF800000;
    minimum = (f32)(-0x6D6);
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[0].position.x = minimum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[0].position.z = minimum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[1].position.x = minimum;
    maximum = (f32)0x6D6;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[1].position.z = maximum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[2].position.x = maximum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[2].position.z = minimum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[3].position.x = maximum;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->boundary[3].position.z = maximum;
}

// FUN_001EE250
/* Round the unit sphere to grid bounds and prepend its embedded obstacle to the list. */
void btlTargetAddRadiusNode(u8 *unit, u8 *position)
{
    extern void btlTargetSetRadiusArea(u8 *unit, s16 position, s16, f32);
    f32 coords[3];
    s16 cellX;
    s16 cellZ;
    f32 scale;
    s32 x;
    s32 y;
    s32 roundedX;
    s32 roundedZ;
    u8 *work;

    btlUnitGetSphereWorldCenter(unit, coords);
    scale = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    x = (s32)((f32)0x6D6 + coords[0]);
    y = (s32)((f32)0x6D6 + coords[2]);
    roundedX = (s64)(s16)(x / 25);
    roundedZ = (s64)(s16)(y / 25);
    if ((x % 25) > 12)
        roundedX = (s64)(s16)(roundedX + 1);
    if ((y % 25) > 12)
        roundedZ = (s64)(s16)(roundedZ + 1);
    if (&cellX != NULL)
        cellX = roundedX;
    if (&cellZ != NULL)
        cellZ = roundedZ;
    work = unit;
    btlTargetSetRadiusArea(work, cellX, cellZ, scale);
    if (position != NULL) {
        ((RwV3d *)position)->x = (f32)(cellX * 25 - 0x6D6);
        ((RwV3d *)position)->y = 0;
        ((RwV3d *)position)->z = (f32)(cellZ * 25 - 0x6D6);
    }
    ((BtlTargetObstacle *)(unit + 0x508))->cellX = cellX;
    ((BtlTargetObstacle *)(unit + 0x508))->cellZ = cellZ;
    ((BtlTargetObstacle *)(unit + 0x508))->radius = scale;
    ((BtlUnit *)unit)->flags3 |= 4;
    ((BtlTargetObstacle *)(unit + 0x508))->previous = (BtlTargetObstacle *)(0);
    if ((u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles) == NULL)
        goto ee250_no_head;
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles->previous =
        (BtlTargetObstacle *)(unit + 0x508);
    ((BtlTargetObstacle *)(unit + 0x508))->next = (BtlTargetObstacle *)((u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles));
    goto ee250_link_done;
ee250_no_head:
    ((BtlTargetObstacle *)(unit + 0x508))->next = (BtlTargetObstacle *)(NULL);
ee250_link_done:
    ((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles = (BtlTargetObstacle *)(unit + 0x508);
}

// FUN_001EE430
/* Unlink the unit obstacle only when its radius-node flag is set. */
void btlTargetRemoveRadiusNode(u8 *unit) {
    /* measured: typed forms of the retained raw accesses changed code generation;
     * keep byte-pointer aliasing at these sites to preserve the retail sequence. */
    s32 flags;
    u8 *next;
    u8 *previous;

    flags = (s32)(((BtlUnit *)unit)->flags3);
    if (flags & 4) {
        *(s32 *)(unit + 0x9C) = flags & ~4;
        next = (u8 *)(((BtlTargetObstacle *)(unit + 0x508))->next);
        if (next != 0) {
            ((BtlTargetObstacle *)next)->previous = (BtlTargetObstacle *)((u8 *)(((BtlTargetObstacle *)(unit + 0x508))->previous));
        }
        previous = (u8 *)(((BtlTargetObstacle *)(unit + 0x508))->previous);
        if (previous != 0) {
            *(u8 **)(previous + 0x4CC) = *(u8 **)(unit + 0x9D4);
            return;
        }
        *(u8 **)(iGpffffb3ac + 0x318) = *(u8 **)(unit + 0x9D4);
    }
}

// FUN_001EE490
/* Recompute obstacle bounds only when the sphere changes cell or scaled radius. */
s32 btlTargetRefreshRadiusNode(u8 *unit) {
    extern void btlTargetSetRadiusArea(u8 *unit, s16, s16, f32);
    extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *);
    f32 coords[3];
    s16 cellX;
    s16 cellZ;
    f32 scale;
    f32 base;
    s32 x;
    s32 y;
    s32 roundedX;
    s32 roundedZ;

    if (((s32)(((BtlUnit *)unit)->flags3) & 4) == 0) {
        return 0;
    }
    btlUnitGetSphereWorldCenter(unit, coords);
    scale = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    base = (f32)1750;
    x = (s32)(base + coords[0]);
    y = (s32)(base + coords[2]);
    roundedX = (s64)(s16)(x / 25);
    roundedZ = (s64)(s16)(y / 25);
    if ((x % 25) > 12) {
        roundedX = (s64)(s16)(roundedX + 1);
    }
    if ((y % 25) > 12) {
        roundedZ = (s64)(s16)(roundedZ + 1);
    }
    if (&cellX != NULL) {
        cellX = (s16)roundedX;
    }
    if (&cellZ != NULL) {
        cellZ = (s16)roundedZ;
    }
    if (((BtlTargetObstacle *)(unit + 0x508))->cellX != cellX ||
        ((BtlTargetObstacle *)(unit + 0x508))->cellZ != cellZ ||
        ((BtlTargetObstacle *)(unit + 0x508))->radius != scale) {
        btlTargetSetRadiusArea(unit, cellX, cellZ, scale);
        ((BtlTargetObstacle *)(unit + 0x508))->cellX = cellX;
        ((BtlTargetObstacle *)(unit + 0x508))->cellZ = cellZ;
        ((BtlTargetObstacle *)(unit + 0x508))->radius = scale;
        return 1;
    }
    return 0;
}

/* The first pass through the route loop reads `cur`, `last` and `seg[1]`
   before anything has written them (001ee71c/001ee730); retail uses the
   stack slots as they are. The C keeps those reads of the uninitialised
   locals. opt_loop_invariants hoists &pts[n] (retail $s5) and pts[0].z
   (retail $f20) out of the subdivision loop. */
#pragma push
/* measured: btlTargetBuildSmoothRoute MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001EE610
s32 btlTargetBuildSmoothRoute(u8 *route, f32 radius)
{
    extern f32 func_003e41e0(f32 *out, f32 *in);
    RoutePoint last;
    RoutePoint tmp;
    RoutePoint cur;
    RoutePoint edge;
    RoutePoint norm[2];
    RoutePoint seg[2];
    RoutePoint ctrl[4];
    RoutePoint pts[128];
    RouteNode *goal;
    RouteNode *node;
    RouteNode *prev;
    u8 *base;
    s32 i;
    s32 n;
    s32 k;
    f32 margin;
    f32 dot;
    f32 segLen;
    f32 prevLen;
    f32 s;

    n = 0;
    base = iGpffffb3ac;
    goal = (RouteNode *)(base + 0x90C);
    margin = 0.5f * radius;
    if (btlTargetLineClear((f32 *)(base + 0x7E4), (f32 *)(base + 0x914), margin) == 0) {
        /* The start is already in reach of the goal: a straight segment. */
        base = iGpffffb3ac;
        pts[0] = ((RouteNode *)(base + 0x90C))->pos;
        pts[1] = ((RouteNode *)(base + 0x7DC))->pos;
        n = 2;
    } else {
        node = goal;
        while (node != NULL) {
            if (n > 0) {
                /* Skip ahead along the parent chain while the last point
                   still reaches the next node. */
                prev = node;
                while (node != NULL) {
                    if (btlTargetLineClear(&cur.x, &node->pos.x, margin) != 0) {
                        break;
                    }
                    prev = node;
                    node = node->parent;
                }
                node = prev;
                cur = prev->pos;
            } else {
                cur = node->pos;
            }
            seg[0] = seg[1];
            seg[1].x = cur.x - last.x;
            seg[1].z = cur.z - last.z;
            dot = seg[0].x * seg[1].x + seg[0].z * seg[1].z;
            if (n > 1 && dot <= 0.173648f) {
                /* Sharp corner: round it with two extra points. */
                segLen = func_003e41e0(&norm[0].x, &seg[1].x);
                prevLen = func_003e41e0(&norm[1].x, &seg[0].x);
                if (segLen < 250.0f && prevLen < 250.0f) {
                    n--;
                } else {
                    s = (1.0f - 0.65f) * segLen;
                    tmp.x = norm[0].x * s;
                    tmp.z = norm[0].z * s;
                    tmp.x = tmp.x + pts[n - 1].x;
                    tmp.z = tmp.z + pts[n - 1].z;
                    pts[n] = tmp;
                    s = 0.65f * prevLen;
                    tmp.x = norm[1].x * s;
                    tmp.z = norm[1].z * s;
                    tmp.x = tmp.x + pts[n - 2].x;
                    tmp.z = tmp.z + pts[n - 2].z;
                    pts[n - 1] = tmp;
                    n++;
                }
                pts[n] = cur;
                n++;
            } else {
                pts[n] = cur;
                n++;
            }
            last = pts[n - 1];
            node = node->parent;
        }
    }
    if (n < 2) {
        return 0;
    }
    if (n < 3) {
        ((RoutePoint *)route)[0] = pts[1];
        ((RoutePoint *)route)[1] = pts[0];
        ((BtlTargetRoute *)route)->count = 2;
    } else {
        /* Subdivide each span into four points of a cubic spline, with
           phantom points extrapolated past the start. */
        k = 0;
        i = n - 1;
        do {
            RoutePoint *out;

            if (i + 1 >= n) {
                ctrl[0] = pts[n - 1];
            } else {
                ctrl[0] = pts[i + 1];
            }
            ctrl[1] = pts[i];
            if (i - 1 < 0) {
                edge.x = pts[0].x - ctrl[1].x;
                edge.z = pts[0].z - ctrl[1].z;
                func_003e41e0(&edge.x, &edge.x);
                edge.x = edge.x * 300.0f;
                edge.z = edge.z * 300.0f;
                edge.x = edge.x + pts[0].x;
                edge.z = edge.z + pts[0].z;
                ctrl[2] = edge;
            } else {
                ctrl[2] = pts[i - 1];
            }
            if (i - 2 < 0) {
                edge.x = pts[0].x - ctrl[1].x;
                edge.z = pts[0].z - ctrl[1].z;
                func_003e41e0(&edge.x, &edge.x);
                edge.x = edge.x * 500.0f;
                edge.z = edge.z * 500.0f;
                edge.x = edge.x + pts[0].x;
                edge.z = edge.z + pts[0].z;
                ctrl[3] = edge;
            } else {
                ctrl[3] = pts[i - 2];
            }
            out = (RoutePoint *)route + k;
            out[0] = pts[i];
            tmp.x = -0.0703125f * ctrl[0].x + 0.8671875f * ctrl[1].x + 0.2265625f * ctrl[2].x + -0.0234375f * ctrl[3].x;
            tmp.z = -0.0703125f * ctrl[0].z + 0.8671875f * ctrl[1].z + 0.2265625f * ctrl[2].z + -0.0234375f * ctrl[3].z;
            out[1] = tmp;
            tmp.x = -0.0625f * ctrl[0].x + 0.5625f * ctrl[1].x + 0.5625f * ctrl[2].x + -0.0625f * ctrl[3].x;
            tmp.z = -0.0625f * ctrl[0].z + 0.5625f * ctrl[1].z + 0.5625f * ctrl[2].z + -0.0625f * ctrl[3].z;
            out[2] = tmp;
            tmp.x = -0.0234375f * ctrl[0].x + 0.226563f * ctrl[1].x + 0.8671875f * ctrl[2].x + -0.0703125f * ctrl[3].x;
            tmp.z = -0.0234375f * ctrl[0].z + 0.226563f * ctrl[1].z + 0.8671875f * ctrl[2].z + -0.0703125f * ctrl[3].z;
            out[3] = tmp;
            k += 4;
            i--;
        } while (i > 0);
        ((RoutePoint *)route)[k] = pts[0];
        ((BtlTargetRoute *)route)->count = k + 1;
    }
    return 1;
}


/* Restore the caller compilation settings after the route builder. */
#pragma pop
