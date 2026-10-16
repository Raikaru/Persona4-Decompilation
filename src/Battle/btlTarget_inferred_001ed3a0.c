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

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001ed3a0-001ee610 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern void btlTargetInitSpring(u8 *arg0, f32 arg1);
extern int func_001ed060(float *param_1, float *param_2);
typedef struct P4NeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    u8 rest[0x114];
} P4NeighborNode;
typedef struct P4NeighborGroup {
    s32 unknown0;
    s32 unknown4;
    P4NeighborNode nodes[4];
    struct P4NeighborGroup *previous;
    struct P4NeighborGroup *next;
} P4NeighborGroup;
extern s32 btlTargetRangeCheck(u8 *first, u8 *second);
extern f32 RwV2dLength(f32 *vector);
typedef struct P4NeighborWorld {
    u8 prefix[0x318];
    P4NeighborGroup *groups;
    P4NeighborNode nodes[4];
    P4NeighborNode start;
    P4NeighborNode goal;
} P4NeighborWorld;
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
s32 func_001ed3a0(u8 *node, f32 threshold)
{
    f32 linkedDelta[2];
    f32 fixedDelta[2];
    f32 startDelta[2];
    f32 goalDelta[2];
    f32 distance;
    P4NeighborGroup *group;
    s32 count;
    u16 index;
    u8 *neighbor;

    count = 0;
    group = *(P4NeighborGroup **)(iGpffffb3ac + 0x318);
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
            linkedDelta[0] = *(f32 *)(node + 8) - *(f32 *)((u8 *)group + index * 0x130 + 0x10);
            linkedDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)((u8 *)group + index * 0x130 + 0x14);
            distance = RwV2dLength(linkedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
            *(u8 **)(node + (u16)count * 4 + 0x30) = neighbor;
            count = (u16)(count + 1);
        }
        group = group->next;
    }
    for (index = 0; index < 4; index++) {
        if ((u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index] == node)
            continue;
        if (((P4NeighborWorld *)iGpffffb3ac)->nodes[index].active <= 0.0f)
            continue;
        if (btlTargetRangeCheck(node, (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index]) != 0)
            continue;
        fixedDelta[0] = *(f32 *)(node + 8) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].x;
        fixedDelta[1] = *(f32 *)(node + 0xC) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].z;
        distance = RwV2dLength(fixedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
        *(u8 **)(node + (u16)count * 4 + 0x30) = (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index];
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x7DC != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x7DC) == 0) {
        startDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x7E4);
        startDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x7E8);
        distance = RwV2dLength(startDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x7DC;
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x90C != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x90C) == 0) {
        goalDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x914);
        goalDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x918);
        distance = RwV2dLength(goalDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x90C;
        count = (u16)(count + 1);
    }
    *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = 0;
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
void btlTargetRebuildRadiusLinks(f32 radius)
{
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 RwV2dLength(f32 *vec);
    extern f32 D_0060A120[];
    extern f32 fGpffff8330;
    typedef struct { f32 x, z; } FieldPair;
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
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        if (first == 0) {
            s16 v;

            v = *(s16 *)(group + 0);
            corners[3].x = v;
            corners[2].x = v;
            corners[1].x = v;
            corners[0].x = v;
            v = *(s16 *)(group + 2);
            corners[3].y = v;
            corners[2].y = v;
            corners[1].y = v;
            corners[0].y = v;
            f0 = *(f32 *)(group + 4);
            bounds[3] = f0;
            bounds[2] = f0;
            bounds[1] = f0;
            bounds[0] = f0;
            first = 1;
        } else {
            tx = *(s16 *)(group + 0);
            ty = *(s16 *)(group + 2);
            if ((corners[0].x >= tx) && (corners[0].y >= ty)) {
                corners[0].x = tx;
                corners[0].y = ty;
                bounds[0] = *(f32 *)(group + 4);
            }
            if ((corners[1].x <= tx) && (corners[1].y >= ty)) {
                corners[1].x = tx;
                corners[1].y = ty;
                bounds[1] = *(f32 *)(group + 4);
            }
            if ((corners[2].x <= tx) && (corners[2].y <= ty)) {
                corners[2].x = tx;
                corners[2].y = ty;
                bounds[2] = *(f32 *)(group + 4);
            }
            if ((corners[3].x >= tx) && (corners[3].y <= ty)) {
                corners[3].x = tx;
                corners[3].y = ty;
                bounds[3] = *(f32 *)(group + 4);
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
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            best = NULL;
            bestDist = 7000.0f;
            *(FieldPair *)cur = *(FieldPair *)(group + i * 0x130 + 8);
            other = *(u8 **)(iGpffffb3ac + 0x318);
            curZ = cur[1];
            for (; other != NULL; other = *(u8 **)(other + 0x4CC)) {
                if (group != other) {
                    for (j = 0; j < 4; j++) {
                        u8 *entry = other + j * 0x130;

                        delta[0] = *(f32 *)(entry + 8) - cur[0];
                        delta[1] = *(f32 *)(entry + 12) - curZ;
                        dist = func_003e41e0(norm, delta);
                        if (!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) {
                            if (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(entry += 8)) == 0) {
                                *(s64 *)bestDir = *(s64 *)norm;
                                best = entry;
                                bestDist = dist;
                                bestX = (f32)(*(s16 *)(other + 0) * 25 - 1750);
                                bestZ = (f32)(*(s16 *)(other + 2) * 25 - 1750);
                                bestH = *(f32 *)(other + 4);
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 4; j++) {
                u8 *base = iGpffffb3ac;

                delta[0] = *(f32 *)(base + j * 0x130 + 0x31C) - cur[0];
                delta[1] = *(f32 *)(base + j * 0x130 + 0x320) - curZ;
                dist = func_003e41e0(norm, delta);
                if ((!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) && (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(iGpffffb3ac + j * 0x130 + 0x31C)) == 0)) {
                    *(s64 *)bestDir = *(s64 *)norm;
                    best = iGpffffb3ac + j * 0x130 + 0x31C;
                    bestDist = dist;
                    bestX = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x31C);
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
                *(f32 *)(group + i * 0x130 + 0x10) = cur[0] + dx;
                *(f32 *)(group + i * 0x130 + 0x14) = curZ + bestDir[1];
                *(u8 **)(group + i * 0x130 + 0x18) = best;
                *(f32 *)(group + i * 0x130 + 0x1C) = bestDist;
                delta[0] = (f32)(*(s16 *)(group + 0) * 25 - 1750);
                delta[1] = (f32)(*(s16 *)(group + 2) * 25 - 1750);
                delta[0] = delta[0] - bestX;
                delta[1] = delta[1] - bestZ;
                *(f32 *)(group + i * 0x130 + 0x20) = RwV2dLength(delta) - (*(f32 *)(group + 4) + bestH);            } else {
                *(f32 *)(group + i * 0x130 + 0x1C) = -1.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        best = NULL;
        bestDist = 7000.0f;
        {
            u8 *base = iGpffffb3ac;

            *(FieldPair *)wpos = *(FieldPair *)(base + i * 0x130 + 0x31C);
            other = *(u8 **)(base + 0x318);
        }
        wposZ = wpos[1];
        for (; other != NULL; other = *(u8 **)(other + 0x4CC)) {
            for (j = 0; j < 4; j++) {
                u8 *entry = other + j * 0x130;

                delta[0] = *(f32 *)(entry + 8) - wpos[0];
                delta[1] = *(f32 *)(entry + 12) - wposZ;
                dist = RwV2dLength(delta);
                if (dist < bestDist) {
                    func_003e41e0(bestDir, delta);
                    best = entry + 8;
                    bestDist = dist;
                }
            }
        }
        if (best != NULL) {
            if (*(u8 **)(best + 0x10) != iGpffffb3ac + i * 0x130 + 0x31C) {
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
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
            }
        } else {
            *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
        }
    }
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            u8 *corner = group + i * 0x130 + 8;

            if (!(*(f32 *)(corner + 0x14) <= 0.0f) && !(*(f32 *)(corner + 0x18) < radius)) {
                func_001ed3a0(corner, radius);
            } else {
                *(s32 *)(corner + 0x30) = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        u8 *corner = iGpffffb3ac + i * 0x130 + 0x31C;

        if (!(*(f32 *)(corner + 0x14) <= 0.0f)) {
            func_001ed3a0(corner, radius);
        } else {
            *(s32 *)(corner + 0x30) = 0;
        }
    }
    func_001ed3a0(iGpffffb3ac + 0x7DC, radius);
    func_001ed3a0(iGpffffb3ac + 0x90C, radius);
}

#pragma pop
// FUN_001EE1C0
void btlTargetResetRadiusState(void) {
    f32 temp_f0;
    f32 temp_f1;

    *(s32 *)(iGpffffb3ac + 0x318) = 0;
    *(s32 *)(iGpffffb3ac + 0x7F0) = 0xBF800000;
    *(s32 *)(iGpffffb3ac + 0x920) = 0xBF800000;
    temp_f1 = (f32)(-0x6D6);
    *(f32 *)(iGpffffb3ac + 0x31C) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x320) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x44C) = temp_f1;
    temp_f0 = (f32)0x6D6;
    *(f32 *)(iGpffffb3ac + 0x450) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x57C) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x580) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x6AC) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x6B0) = temp_f0;
}

// FUN_001EE250
void btlTargetAddRadiusNode(u8 *arg0, u8 *arg1)
{
    extern void btlTargetSetRadiusArea(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;
    u8 *work;

    btlUnitGetSphereWorldCenter(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    x = (s32)((f32)0x6D6 + coords[0]);
    y = (s32)((f32)0x6D6 + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12)
        rounded_x = (s64)(s16)(rounded_x + 1);
    if ((y % 25) > 12)
        rounded_y = (s64)(s16)(rounded_y + 1);
    if (&out_x != NULL)
        out_x = rounded_x;
    if (&out_y != NULL)
        out_y = rounded_y;
    work = arg0;
    btlTargetSetRadiusArea(work, out_x, out_y, scale);
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32)(out_x * 25 - 0x6D6);
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)(out_y * 25 - 0x6D6);
    }
    *(s16 *)(arg0 + 0x508) = out_x;
    *(s16 *)(arg0 + 0x50A) = out_y;
    *(f32 *)(arg0 + 0x50C) = scale;
    *(s32 *)(arg0 + 0x9C) |= 4;
    *(s32 *)(arg0 + 0x9D0) = 0;
    if (*(u8 **)(iGpffffb3ac + 0x318) == NULL)
        goto ee250_no_head;
    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x318) + 0x4C8) =
        arg0 + 0x508;
    *(u8 **)(arg0 + 0x9D4) =
        *(u8 **)(iGpffffb3ac + 0x318);
    goto ee250_link_done;
ee250_no_head:
    *(u8 **)(arg0 + 0x9D4) = NULL;
ee250_link_done:
    *(u8 **)(iGpffffb3ac + 0x318) = arg0 + 0x508;
}

// FUN_001EE430
void btlTargetRemoveRadiusNode(u8 *arg0) {
    s32 temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;

    temp_5 = *(s32 *)(arg0 + 0x9C);
    if (temp_5 & 4) {
        *(s32 *)(arg0 + 0x9C) = temp_5 & ~4;
        temp_5_2 = *(u8 **)(arg0 + 0x9D4);
        if (temp_5_2 != 0) {
            *(u8 **)(temp_5_2 + 0x4C8) = *(u8 **)(arg0 + 0x9D0);
        }
        temp_5_3 = *(u8 **)(arg0 + 0x9D0);
        if (temp_5_3 != 0) {
            *(u8 **)(temp_5_3 + 0x4CC) = *(u8 **)(arg0 + 0x9D4);
            return;
        }
        *(u8 **)(iGpffffb3ac + 0x318) = *(u8 **)(arg0 + 0x9D4);
    }
}

// FUN_001EE490
s32 btlTargetRefreshRadiusNode(u8 *arg0) {
    extern void btlTargetSetRadiusArea(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    f32 base;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;

    if ((*(s32 *)(arg0 + 0x9C) & 4) == 0) {
        return 0;
    }
    btlUnitGetSphereWorldCenter(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    base = (f32)1750;
    x = (s32)(base + coords[0]);
    y = (s32)(base + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12) {
        rounded_x = (s64)(s16)(rounded_x + 1);
    }
    if ((y % 25) > 12) {
        rounded_y = (s64)(s16)(rounded_y + 1);
    }
    if (&out_x != NULL) {
        out_x = (s16)rounded_x;
    }
    if (&out_y != NULL) {
        out_y = (s16)rounded_y;
    }
    if (*(s16 *)(arg0 + 0x508) != out_x ||
        *(s16 *)(arg0 + 0x50A) != out_y ||
        *(f32 *)(arg0 + 0x50C) != scale) {
        btlTargetSetRadiusArea(arg0, out_x, out_y, scale);
        *(s16 *)(arg0 + 0x508) = out_x;
        *(s16 *)(arg0 + 0x50A) = out_y;
        *(f32 *)(arg0 + 0x50C) = scale;
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
        *(s16 *)(route + 0x400) = 2;
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
        *(s16 *)(route + 0x400) = k + 1;
    }
    return 1;
}

