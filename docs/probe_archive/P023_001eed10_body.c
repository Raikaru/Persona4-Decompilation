/* P023: retained route-search investigation, 2026-09-08.
 * Production remains ASM: 001EED10..001EF10F, 1024-byte window.
 * Preferred full-owner candidate: 1000/1024 bytes, nd364, 24 relocations.
 * Frame is the retail 0xB0, but 24 executable bytes are missing. This is
 * not a register-only floor, exact recovery, or impossibility claim.
 *
 * Initial typed-provider flat candidate: 992/716, frame0xA0. Typed edge
 * condition preserves two distinct live edge pointers: 1016/430. Matching
 * the open/closed membership loop exits reaches the preferred 1000/364.
 * CSE-off flat source:1080/695; propagation/loop profiles do not close it.
 * Typed cost field:1000/438; integer insertion address:1012/742;
 * float-array cost:1004/431; array insertion:1016/762. These pairs list
 * emitted bytes / normalized byte differences. Literal final addresses
 * were resolved for inspection, not treated as arbitrary relocations.
 *
 * Remaining source-shape differences: cost-address scheduling, membership
 * register lifetimes, recomputation of update/insertion index projections,
 * global/neighbor reload ordering and closed-unlink loop alignment.
 *
 * Input ABI: route a0, start/end two-float arrays a1/a2, radius f12.
 * Collision test receives half radius. Direct path stages each endpoint's
 * two loads, writes two points/count2/mode2, returns1. Obstructed path
 * clears count, stages global endpoints, builds adjacency. Missing start
 * or goal adjacency returns0/mode3 before list initialization.
 *
 * Search clears open/closed heads, start g/parent; start f is distance to
 * goal. The exact 001EEC60 provider removes the best open node. A neighbor
 * is reopened only when absent from both lists or !(current.g<=newCost).
 * This compares CURRENT g, not neighbor g: do not fix the retail algorithm.
 * Reopening updates g/f/parent, unlinks the closed node and inserts it in
 * open when absent. NaN behavior follows the ordered comparison literally.
 * Goal selection invokes 001EE610 and returns1/mode2 regardless of that
 * provider's return; exhausted open returns0/mode3.
 *
 * External contracts still govern provider inputs/results. In particular,
 * 001EEC60 needs a nonempty open list with a selectable score below 350000
 * (or an unordered score); its source leaves best unwritten otherwise.
 * This investigation proves no game-data bound excluding that provider
 * path, and makes no native/gameplay validation claim for this candidate.
 *
 * To reproduce: start from current full owner, replace P4NeighborNode's
 * opaque rest[0x114] with the fields below, add these provider declarations,
 * replace only target INCLUDE_ASM with this body. All other source remains.
 * Standalone archive declarations are not a production ABI migration.
 */
#include "type.h"
extern u8 *iGpffffb3ac;
extern u8 *func_001eec60(void);
typedef struct P4NeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    f32 pathCost;
    f32 estimatedCost;
    struct P4NeighborNode *openNext;
    struct P4NeighborNode *closedNext;
    struct P4NeighborNode *parent;
    struct P4NeighborNode *neighbors[32];
    f32 distances[32];
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
extern void func_001ed700(f32 radius);
extern s32 func_001ee610(u8 *route, f32 radius);
extern s32 func_001ece50(f32 *start, f32 *end, f32 radius);
s32 func_001eed10(u8 *route, f32 *start, f32 *end, f32 radius)
{
    f32 initialDelta[2];
    f32 goalDelta[2];
    f32 x;
    f32 z;
    f32 oldCost;
    f32 newCost;
    f32 distance;
    u8 *base;
    u8 *current;
    u8 *neighbor;
    u8 **edge;
    u8 **updateEdge;
    u8 *scan;
    u8 *previous;
    u8 **closedHead;
    u8 *remove;
    s32 found;
    s32 inOpen;
    s32 inClosed;
    u16 index;

    *(u8 *)(route + 0x404) = 1;
    if (func_001ece50(start, end, 0.5f * radius) == 0) {
        x = start[0];
        z = start[1];
        *(f32 *)(route + 0) = x;
        *(f32 *)(route + 4) = z;
        x = end[0];
        z = end[1];
        *(f32 *)(route + 8) = x;
        *(f32 *)(route + 0xC) = z;
        *(u16 *)(route + 0x400) = 2;
        *(u8 *)(route + 0x404) = 2;
        return 1;
    }
    *(u16 *)(route + 0x400) = 0;
    base = iGpffffb3ac;
    x = start[0];
    z = start[1];
    *(f32 *)(base + 0x7E4) = x;
    *(f32 *)(base + 0x7E8) = z;
    x = end[0];
    z = end[1];
    *(f32 *)(base + 0x914) = x;
    *(f32 *)(base + 0x918) = z;
    func_001ed700(radius);
    base = iGpffffb3ac;
    if (*(s32 *)(base + 0x80C) == 0 || *(s32 *)(base + 0x93C) == 0) {
        *(u8 *)(route + 0x404) = 3;
        return 0;
    }
    *(u8 **)(base + 0xA3C) = 0;
    *(u8 **)(iGpffffb3ac + 0xA40) = 0;
    *(s32 *)(iGpffffb3ac + 0x7F8) = 0;
    base = iGpffffb3ac;
    initialDelta[0] = *(f32 *)(base + 0x7E4) - *(f32 *)(base + 0x914);
    initialDelta[1] = *(f32 *)(base + 0x7E8) - *(f32 *)(base + 0x918);
    distance = func_003e41b0(initialDelta);
    *(f32 *)(iGpffffb3ac + 0x7FC) = distance;
    *(s32 *)(iGpffffb3ac + 0x808) = 0;
    base = iGpffffb3ac;
    *(u8 **)(base + 0x800) = *(u8 **)(base + 0xA3C);
    base = iGpffffb3ac;
    *(u8 **)(base + 0xA3C) = base + 0x7DC;
    found = 0;
    while (*(u8 **)(iGpffffb3ac + 0xA3C) != 0) {
        current = func_001eec60();
        if (current == iGpffffb3ac + 0x90C) {
            found = 1;
            break;
        }
        for (index = 0; (neighbor = *(edge = (u8 **)&((P4NeighborNode *)current)->neighbors[index])) != 0; index++) {
            oldCost = *(f32 *)(current + 0x1C);
            newCost = oldCost + *(f32 *)(current + index * 4 + 0xB0);
            base = iGpffffb3ac;
            scan = *(u8 **)(base + 0xA3C);
            while (scan != 0) {
                if (scan == neighbor) { inOpen = 1; goto open_done; }
                scan = *(u8 **)(scan + 0x24);
            }
            inOpen = 0;
open_done:
            scan = *(u8 **)(base + 0xA40);
            while (scan != 0) {
                if (scan == neighbor) { inClosed = 1; goto closed_done; }
                scan = *(u8 **)(scan + 0x28);
            }
            inClosed = 0;
closed_done:
            if ((inOpen != 0 || inClosed != 0) && oldCost <= newCost)
                continue;
            updateEdge = (u8 **)(current + index * 4 + 0x30);
            *(f32 *)(neighbor + 0x1C) = newCost;
            *(f32 *)(*updateEdge + 0x20) = newCost;
            base = iGpffffb3ac;
            neighbor = *updateEdge;
            goalDelta[0] = *(f32 *)(neighbor + 8) - *(f32 *)(base + 0x914);
            goalDelta[1] = *(f32 *)(neighbor + 0xC) - *(f32 *)(base + 0x918);
            distance = func_003e41b0(goalDelta);
            *(f32 *)(*updateEdge + 0x20) = *(f32 *)(*updateEdge + 0x20) + distance;
            *(u8 **)(*updateEdge + 0x2C) = current;
            if (inClosed != 0) {
                remove = *edge;
                previous = 0;
                closedHead = (u8 **)(iGpffffb3ac + 0xA40);
                scan = *closedHead;
                while (scan != 0) {
                    if (scan == remove) break;
                    previous = scan;
                    scan = *(u8 **)(scan + 0x28);
                }
                if (scan != 0) {
                    if (previous != 0)
                        *(u8 **)(previous + 0x28) = *(u8 **)(scan + 0x28);
                    else
                        *closedHead = *(u8 **)(scan + 0x28);
                }
            }
            if (inOpen == 0) {
                updateEdge = (u8 **)(current + index * 4 + 0x30);
                *(u8 **)(*updateEdge + 0x24) = *(u8 **)(iGpffffb3ac + 0xA3C);
                *(u8 **)(iGpffffb3ac + 0xA3C) = *updateEdge;
            }
        }
        *(u8 **)(current + 0x28) = *(u8 **)(iGpffffb3ac + 0xA40);
        *(u8 **)(iGpffffb3ac + 0xA40) = current;
    }
    if (found != 0) {
        func_001ee610(route, radius);
        *(u8 *)(route + 0x404) = 2;
    } else {
        *(u8 *)(route + 0x404) = 3;
    }
    return found;
}
