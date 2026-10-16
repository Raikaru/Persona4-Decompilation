#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern void btlUnitSetRot(void *arg0, void *arg1);
extern void btlTargetBlendVectors(void *out, void *first, void *second);
extern void btlTargetPositionToCell(s16 *arg0, s16 *arg1, f32 *position);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void btlUnitSetPos(u8 *arg0, f32 *arg1);
extern void btlUnitGetAnimBoundsWorldCenterTowardUnit(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *btlUnitGetRecordPtr(u8 *arg0, s32 arg1);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();








extern s32 btlUnitRealignCells(void);

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d1310-001d1cc0 */

static inline f32 formationCapacityLimit(s32 limit)
{
    return (f32)limit;
}
// FUN_001D1310
void func_001d1310(u16 *arg0) {
    u8 *node;
    f32 scale;
    f32 x;
    f32 y;
    memset((u8 *)arg0, 0, 8);
    node = *(u8 **)(iGpffffb3ac + 0x184);
    while (node != NULL) {
        if (datCalcIsDead(*(u8 **)(node + 0xA64), 0) == 0) {
            scale = *(f32 *)(node + 0x2C);
            x = (f32)(s32)(*(f32 *)(node + 0x90) * scale);
            y = (f32)(s32)(*(f32 *)(node + 0x8C) * scale);
            if (y <= 200.0f) {
                if (x <= 75.0f) {
                    *(u16 *)((u8 *)arg0 + 0) = *(u16 *)((u8 *)arg0 + 0) + 1;
                } else if (x <= 125.0f) {
                    *(u16 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)arg0 + 2) + 1;
                } else if (x <= 200.0f) {
                    *(u16 *)((u8 *)arg0 + 4) = *(u16 *)((u8 *)arg0 + 4) + 1;
                }
            } else if (y <= 300.0f) {
                if (x <= 125.0f) {
                    *(u16 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)arg0 + 2) + 1;
                } else if (x <= 200.0f) {
                    *(u16 *)((u8 *)arg0 + 4) = *(u16 *)((u8 *)arg0 + 4) + 1;
                }
            } else {
                *(u16 *)((u8 *)arg0 + 4) = *(u16 *)((u8 *)arg0 + 4) + 1;
            }
            *(u16 *)((u8 *)arg0 + 6) = *(u16 *)((u8 *)arg0 + 6) + 1;
        }
        node = *(u8 **)(node + 0xA68);
    }
}

/* measured: opt_propagation off probe for func_001d14b0 loop masks. */
/* measured: func_001d14b0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001D14B0
s32 func_001d14b0(u8 *arg0)
{
    s32 index;
    u16 masked_index;
    u16 test_index;
    u8 *table;
    u8 *entry;

    index = 0;
    table = D_00607E50;
    goto test;
loop:
    masked_index = (u16)index;
    entry = table + (masked_index * 0xE0);
    if (*(u16 *)(arg0 + 0) > *(u16 *)(entry + 0xD8)) {
        goto next;
    }
    if (*(u16 *)(arg0 + 2) > *(u16 *)(entry + 0xDA)) {
        goto next;
    }
    if (*(u16 *)(arg0 + 4) > *(u16 *)(entry + 0xDC)) {
        goto next;
    }
    return index;
next:
    index = (index + 1) & 0xFFFF;
test:
    test_index = (u16)index;
    if (test_index < 0x19U) {
        goto loop;
    }
    return 0x18;
}

/* measured: close opt_propagation after func_001d14b0 probe. */
/* measured: func_001d1680 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_001D1540
void func_001d1540(u8 *arg0, s32 arg1, s32 arg2) {
    u8 temp_4;

    temp_4 = *(u8 *)(arg0 + 0xA2);
    switch (temp_4) {
    case 0:
        ((s32 *)(iGpffffb3ac + 0xA74))[(u16)arg1] = arg2;
        return;
    case 1:
        ((s32 *)(iGpffffb3ac + 0xA84))[(u16)arg1] = arg2;
        return;
    }
}

/* measured: 212B/224B, all four relocations resolved; twelve zero-tail bytes.
   The four output counters are a complete helper buffer. A two-halfword
   cursor keeps induction and explicitly narrowed selection in retail's
   distinct registers without adding stack storage. */
// FUN_001D15A0
s16 func_001d15a0(void)
{
    u16 counts[4];
    struct {
        u16 index;
        u16 selected;
    } cursor;
    u16 result;
    s32 first;
    s32 second;
    s32 third;
    u8 *table;
    u8 *entry;

    if (btlUnitRealignCells() == 1) {
        return -1;
    }
    func_001d1310(counts);
    cursor.index = 0;
    first = counts[0];
    second = counts[1];
    third = counts[2];
    table = D_00607E50;
    for (; cursor.index < 0x19U; cursor.index++) {
        cursor.selected = (u16)cursor.index;
        entry = table + (s32)cursor.selected * 0xE0;
        if (first > *(u16 *)(entry + 0xD8)) continue;
        if (second > *(u16 *)(entry + 0xDA)) continue;
        if (third > *(u16 *)(entry + 0xDC)) continue;
        result = cursor.selected;
        goto done;
    }
    result = 0x18;
done:
    return (s16)result;
}

#pragma push
/* measured: func_001d1680 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_001d1680 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* Assign party/enemy formation slots, optionally snap positions, then face
 * each side toward the other. MWCC b210: 1592 bytes and eight zero tail bytes.
 * The capacity scan has five candidates; 5 denotes no fitting candidate. */
// FUN_001D1680
void func_001d1680(s32 applyPositions, s32 unused)
{
    RwV3d position;
    RwV3d actorCenter;
    RwV3d enemyCenter;
    u16 counts[4];
    /* The failure sentinel can write cell 5; only cells 0..4 are scanned. */
    s32 occupied[6];
    RtQuat rotation;
    u8 *actor;
    u16 nextSlot;
    s16 formation;
    u8 *layout;
    u16 selectedSlot;
    u16 chosen;
    u8 *enemy;
    u8 *facingUnit;

    position.y = 0.0f;
    *(s16 *)(iGpffffb3ac + 0xA70) = -1;
    if (btlUnitRealignCells() == 1) {
        formation = -1;
    } else {
        func_001d1310(counts);
        formation = (s16)func_001d14b0((u8 *)counts);
    }
    /* Keep sentinel comparison separate from the signed table-row conversion. */
    if ((s64)formation != -1) {
        memset(iGpffffb3ac + 0xA74, 0, 0x24);
        nextSlot = 1;
        actor = *(u8 **)(iGpffffb3ac + 0x178);
        layout = D_00607E50 + formation * 0xE0;
        while (actor != NULL) {
            s32 slot;
            u8 *entry;
            if (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) == actor) {
                selectedSlot = 0;
            } else {
                while (layout[(u16)nextSlot * 0x18] == 0 && (u16)nextSlot < 4) {
                    nextSlot++;
                }
                selectedSlot = (u16)nextSlot;
                nextSlot++;
            }
            slot = (u16)selectedSlot;
            entry = layout + slot * 0x18;
            position.x = *(f32 *)(entry + 4);
            position.z = *(f32 *)(entry + 8);
            btlTargetPositionToCell((s16 *)(actor + 0x94), (s16 *)(actor + 0x96), (f32 *)&position);
            if (applyPositions != 0) {
                position.x = (f32)(*(s16 *)(actor + 0x94) * 25 - 1750);
                position.z = (f32)(*(s16 *)(actor + 0x96) * 25 - 1750);
                btlUnitSetPos(actor, (f32 *)&position);
            }
            switch (actor[0xA2]) {
            case 0:
                *(s32 *)(iGpffffb3ac + slot * 4 + 0xA74) = 1;
                break;
            case 1:
                *(s32 *)(iGpffffb3ac + slot * 4 + 0xA84) = 1;
                break;
            }
            actor[0x9FC] = (s8)selectedSlot;
            actor = *(u8 **)(actor + 0xA6C);
        }

        enemy = *(u8 **)(iGpffffb3ac + 0x180);
        memset((u8 *)occupied, 0, 5 * sizeof(occupied[0]));
        while (enemy != NULL) {
            if (datCalcIsDead(*(u8 **)(enemy + 0xA64), 0) == 0) {
                f32 radius;
                f32 height;
                f32 radiusSlack;
                f32 leastRadius;
                f32 leastHeight;
                f32 scale;
                /* Induction and the current array index have separate lifetimes. */
                struct { u16 index; u16 current; } cursor;
                s32 slot;
                s32 occupiedOffset;
                u8 *entry;
                chosen = 5;
                leastRadius = formationCapacityLimit(100000000);
                leastHeight = leastRadius;
                scale = *(f32 *)(enemy + 0x2C);
                radius = (f32)(s32)(*(f32 *)(enemy + 0x90) * scale);
                height = (f32)(s32)(*(f32 *)(enemy + 0x8C) * scale);
                for (cursor.index = 0; (u16)cursor.index < 5; cursor.index++) {
                    cursor.current = (u16)cursor.index;
                    if (occupied[cursor.current] != 1) {
                        u8 *candidate = layout + (s32)cursor.current * 0x18;
                        if (candidate[0x60] != 0) {
                            f32 heightSlack;
                            radiusSlack = *(f32 *)(candidate + 0x70) - radius;
                            heightSlack = *(f32 *)(candidate + 0x74) - height;
                            if (!(radiusSlack < 0.0f) && !(heightSlack < 0.0f) &&
                                (radiusSlack < leastRadius || heightSlack < leastHeight)) {
                                leastRadius = radiusSlack;
                                leastHeight = heightSlack;
                                chosen = (u64)cursor.index;
                            }
                        }
                    }
                }
                if ((u16)chosen >= 5) {
                    chosen = 5;
                    leastRadius = formationCapacityLimit(100000000);
                    leastHeight = leastRadius;
                    for (cursor.index = 0; (u16)cursor.index < 5; cursor.index++) {
                        cursor.current = (u16)cursor.index;
                        if (occupied[cursor.current] != 1) {
                            u8 *candidate = layout + (s32)cursor.current * 0x18;
                            if (candidate[0x60] != 0) {
                                f32 heightSlack;
                                radiusSlack = *(f32 *)(candidate + 0x70) - radius;
                                heightSlack = *(f32 *)(candidate + 0x74) - height;
                                if (radiusSlack < leastRadius || heightSlack < leastHeight) {
                                    leastRadius = radiusSlack;
                                    leastHeight = heightSlack;
                                    chosen = (u64)cursor.index;
                                }
                            }
                        }
                    }
                }
                slot = (u16)chosen;
                occupiedOffset = slot * 4;
                occupied[slot] = 1;
                entry = layout + slot * 0x18;
                position.x = *(f32 *)(entry + 0x64);
                position.z = *(f32 *)(entry + 0x68);
                btlTargetPositionToCell((s16 *)(enemy + 0x94), (s16 *)(enemy + 0x96), (f32 *)&position);
                if (applyPositions != 0) {
                    position.x = (f32)(*(s16 *)(enemy + 0x94) * 25 - 1750);
                    position.z = (f32)(*(s16 *)(enemy + 0x96) * 25 - 1750);
                    btlUnitSetPos(enemy, (f32 *)&position);
                }
                switch (enemy[0xA2]) {
                case 0:
                    *(s32 *)(iGpffffb3ac + occupiedOffset + 0xA74) = 1;
                    break;
                case 1:
                    *(s32 *)(iGpffffb3ac + occupiedOffset + 0xA84) = 1;
                    break;
                }
                enemy[0x9FC] = (s8)chosen;
            }
            enemy = *(u8 **)(enemy + 0xA6C);
        }

        btlUnitGetGroupBounds(2, 1, &enemyCenter, NULL, NULL, 1);
        btlUnitGetSphereWorldCenter(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30), (f32 *)&actorCenter);
        facingUnit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            btlTargetBlendVectors(&rotation, &position, &enemyCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = *(u8 **)(facingUnit + 0xA68);
        }
        facingUnit = *(u8 **)(iGpffffb3ac + 0x184);
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            btlTargetBlendVectors(&rotation, &position, &actorCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = *(u8 **)(facingUnit + 0xA68);
        }
        *(s16 *)(iGpffffb3ac + 0xA70) = formation;
        *(s16 *)(iGpffffb3ac + 0xA72) = btlSideCountNotBad(2, 0x80000);
    }
}

#pragma pop
// FUN_001D1CC0
s32 func_001d1cc0(u8 *arg0)
{
    struct Frame {
        f32 value40;
        f32 pad44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
    } frame;
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_4;
    u8 *bounds;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f3;

    temp_17 = *(u8 **)(arg0 + 0);
    temp_16 = *(u8 **)(arg0 + 4);
    btlUnitGetAnimBoundsWorldCenterTowardUnit(temp_16, (s32)temp_17, (u8 *)&frame.value40);
    frame.value60 = *(f32 *)(temp_17 + 4) - frame.value40;
    frame.value64 = 0.0f;
    frame.value68 = *(f32 *)(temp_17 + 0xC) - frame.value48;
    RwV3dNormalize(&frame.value60, &frame.value60);
    if ((frame.value60 == 0.0f) && (frame.value68 == 0.0f)) {
        return 1;
    }
    bounds = btlUnitGetRecordPtr(temp_16, 0xA);
    temp_f3 = (f32)*(s16 *)(bounds + 4);
    temp_f2 = *(f32 *)(temp_16 + 0x2C);
    temp_f1 = *(f32 *)(arg0 + 8);
    temp_f1 -= temp_f3 * temp_f2;
    temp_f3 = frame.value60 * temp_f1;
    frame.value60 = temp_f3;
    temp_f2 = frame.value64 * temp_f1;
    frame.value64 = temp_f2;
    temp_f1_2 = frame.value68 * temp_f1;
    frame.value68 = temp_f1_2;
    if ((*(u16 *)(arg0 + 0xC) & 1) != 0) {
        frame.value50 = *(f32 *)(temp_17 + 4) + frame.value60;
        frame.value54 = *(f32 *)(temp_17 + 8) + frame.value64;
        frame.value58 = *(f32 *)(temp_17 + 0xC) + frame.value68;
        btlUnitSetPos(temp_17, &frame.value50);
        temp_4 = *(u8 **)(temp_17 + 0xA0C);
        if (temp_4 != NULL) {
            frame.value50 = *(f32 *)(temp_4 + 4) + frame.value60;
            frame.value54 = *(f32 *)(temp_4 + 8) + frame.value64;
            frame.value58 = *(f32 *)(temp_4 + 0xC) + frame.value68;
            btlUnitSetPos(temp_4, &frame.value50);
        }
    }
    if ((*(u16 *)(arg0 + 0xC) & 2) != 0) {
        frame.value50 = *(f32 *)(temp_16 + 4) + frame.value60;
        frame.value54 = *(f32 *)(temp_16 + 8) + frame.value64;
        frame.value58 = *(f32 *)(temp_16 + 0xC) + frame.value68;
        btlUnitSetPos(temp_16, &frame.value50);
    }
    return 1;
}

