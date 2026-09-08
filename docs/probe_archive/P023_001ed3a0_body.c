/* P023: exact geometry neighbor builder, 2026-09-08.
 * Production: src/promoted/code1_001e.c, 001ED3A0..001ED6FF.
 * 852 emitted bytes / 864-byte window, all 18 relocations fully resolved;
 * the remaining twelve retail bytes are zero alignment. No scoped pragmas.
 *
 * 0x130-byte node arrays, four per linked group and four in the world,
 * preserve the redundant halfword index projections. Raw linked coordinate
 * reads preserve base-first address scheduling. Existing p4_slot_001eb320
 * preserves offset-first addressing for special nodes and the sentinel.
 * Group/count/index/neighbor declaration order closes register allocation.
 * The s32 count with explicit u16 updates preserves the final return move.
 * Four independent two-float vectors reproduce frame offsets 88,80,78,70.
 *
 * Native freestanding 32-bit Clang smoke: 65,597 scenarios, exact candidate
 * body, real 32-bit pointers/strides. Exhaustive 14-neighbor collision masks
 * across four activity/clearance/NaN profiles; all self-node positions;
 * NaN threshold; empty group chain; ordered distances, null sentinel and
 * untouched output guards. Collision and axis-aligned length boundaries
 * are explicit native models, not game/PS2 SDK execution.
 *
 * Current retail initializer 001ED700 calls this for eligible linked/fixed
 * nodes, then the start and goal nodes. Linked groups use next at +4CC;
 * ordinary nodes reject active<=0 and clearance<threshold, preserving NaN
 * admission. Fixed nodes only reject active<=0. Special nodes only reject
 * identity/collision. Order is linked groups, fixed array, start, goal.
 *
 * There is no retail capacity guard. The 32 neighbor slots also need the
 * sentinel; caller data must keep admitted count below 32 for in-node
 * storage. No global population bound or game-data safety is asserted.
 *
 * Reproduce in the current full owner with its existing p4_slot helper;
 * do not merge duplicate definitions from this standalone archive.
 */
#include "type.h"
extern u8 *iGpffffb3ac;
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
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
extern s32 func_001eca10(u8 *first, u8 *second);
extern f32 func_003e41b0(f32 *vector);
typedef struct P4NeighborWorld {
    u8 prefix[0x318];
    P4NeighborGroup *groups;
    P4NeighborNode nodes[4];
    P4NeighborNode start;
    P4NeighborNode goal;
} P4NeighborWorld;
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
            if (func_001eca10(node, neighbor) != 0)
                continue;
            linkedDelta[0] = *(f32 *)(node + 8) - *(f32 *)((u8 *)group + index * 0x130 + 0x10);
            linkedDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)((u8 *)group + index * 0x130 + 0x14);
            distance = func_003e41b0(linkedDelta);
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
        if (func_001eca10(node, (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index]) != 0)
            continue;
        fixedDelta[0] = *(f32 *)(node + 8) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].x;
        fixedDelta[1] = *(f32 *)(node + 0xC) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].z;
        distance = func_003e41b0(fixedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
        *(u8 **)(node + (u16)count * 4 + 0x30) = (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index];
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x7DC != node && func_001eca10(node, iGpffffb3ac + 0x7DC) == 0) {
        startDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x7E4);
        startDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x7E8);
        distance = func_003e41b0(startDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x7DC;
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x90C != node && func_001eca10(node, iGpffffb3ac + 0x90C) == 0) {
        goalDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x914);
        goalDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x918);
        distance = func_003e41b0(goalDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x90C;
        count = (u16)(count + 1);
    }
    *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = 0;
    return count;
}
