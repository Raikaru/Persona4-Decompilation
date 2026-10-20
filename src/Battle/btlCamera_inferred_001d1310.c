#include "member_access.h"
#include "btl_unit_record_internal.h"
#include "btl_camera_framing_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;

extern void btlUnitSetRot(void *unit, void *rot);
extern void btlTargetBlendVectors(void *rotation, void *first, void *second);
extern void btlTargetPositionToCell(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3ac; /* battle-state allocation */
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void btlUnitSetPos(u8 *unit, f32 *pos);
extern void btlUnitGetAnimBoundsWorldCenterTowardUnit(u8 *context, s32 value, u8 *option);
extern u8 *btlUnitGetRecordPtr(u8 *unit, s32 motion);
extern f32 RwV3dNormalize(f32 *first, f32 *second);
extern u8 *(*jtbl_008873E8[])(s32 first, s32 second);
extern void memset(u8 *first, s32 second, s32 third);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[]; /* 0xE0-byte formation rows */
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();


extern s32 btlUnitRealignCells(void);


extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;


/* Count living enemies into three radius/height capacity bands plus a total. */
// FUN_001D1310
void btlCameraCountUnitsByBand(u16 *counts) {
    u8 *unit;
    f32 scale;
    f32 radius;
    f32 height;
    memset((u8 *)counts, 0, 8);
    unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[3];
    while (unit != NULL) {
        if (datCalcIsDead((u8*)((BtlUnit *)unit)->datUnit, 0) == 0) {
            scale = ((BtlUnit *)unit)->scale;
            radius = (f32)(s32)(((BtlUnit *)unit)->sphereRadius * scale);
            height = (f32)(s32)(((BtlUnit *)unit)->unk_8c * scale);
            if (height <= 200.0f) {
                if (radius <= 75.0f) {
                    counts[0] = counts[0] + 1;
                } else if (radius <= 125.0f) {
                    counts[1] = counts[1] + 1;
                } else if (radius <= 200.0f) {
                    counts[2] = counts[2] + 1;
                }
            } else if (height <= 300.0f) {
                if (radius <= 125.0f) {
                    counts[1] = counts[1] + 1;
                } else if (radius <= 200.0f) {
                    counts[2] = counts[2] + 1;
                }
            } else {
                counts[2] = counts[2] + 1;
            }
            counts[3] = counts[3] + 1;
        }
        unit = (u8 *)((BtlUnit *)unit)->prevUnit;
    }
}

/* Return the first fitting formation row, or the final row if no capacities fit. */
// FUN_001D14B0
s32 btlCameraFindFormationForCounts(u8 *counts)
{
    s32 index;
    u16 maskedIndex;
    u16 testIndex;
    u8 *table;
    u8 *entry;

    index = 0;
    table = D_00607E50;
    goto test;
loop:
    maskedIndex = (u16)index;
    entry = (u8 *)&((BtlCameraFormation *)table)[maskedIndex];
    if (((u16 *)counts)[0] > ((BtlCameraFormation *)entry)->capacity[0]) {
        goto next;
    }
    if (((u16 *)counts)[1] > ((BtlCameraFormation *)entry)->capacity[1]) {
        goto next;
    }
    if (((u16 *)counts)[2] > ((BtlCameraFormation *)entry)->capacity[2]) {
        goto next;
    }
    return index;
next:
    index = (index + 1) & 0xFFFF;
test:
    testIndex = (u16)index;
    if (testIndex < 0x19U) {
        goto loop;
    }
    return 0x18;
}

#pragma opt_propagation on
/* Write the party or enemy occupancy slot selected by unit genus. */
// FUN_001D1540
void btlCameraSetUnitSlotValue(u8 *unit, s32 slotIndex, s32 slotValue) {
    u8 genus;

    genus = ((BtlUnit *)unit)->genus;
    switch (genus) {
    case 0:
        ((BtlCameraFormationOccupancy *)(iGpffffb3ac + 0xA74))->party[(u16)slotIndex] = slotValue;
        return;
    case 1:
        ((BtlCameraFormationOccupancy *)(iGpffffb3ac + 0xA74))->enemies[(u16)slotIndex] = slotValue;
        return;
    }
}

/* Realign units and select the first formation capacity triple fitting the living counts. The index
 * and selection share a cursor struct so retail keeps them in separate registers. */
// FUN_001D15A0
s16 btlCameraSelectFormationIndex(void)
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
    btlCameraCountUnitsByBand(counts);
    cursor.index = 0;
    first = counts[0];
    second = counts[1];
    third = counts[2];
    table = D_00607E50;
    for (; cursor.index < 0x19U; cursor.index++) {
        cursor.selected = (u16)cursor.index;
        entry = table + (s32)cursor.selected * 0xE0;
        if (first > ((BtlCameraFormation *)entry)->capacity[0]) continue;
        if (second > ((BtlCameraFormation *)entry)->capacity[1]) continue;
        if (third > ((BtlCameraFormation *)entry)->capacity[2]) continue;
        result = cursor.selected;
        goto done;
    }
    result = 0x18;
done:
    return (s16)result;
}

#pragma push
/* measured: retail needs loop-invariant hoisting and lifetime analysis both enabled; either one
 * alone differs. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Assign party/enemy formation slots, optionally snap positions, then face each side toward the
 * other. The capacity scan has five candidates; 5 means none fit. */
// FUN_001D1680
void btlCameraAssignFormationSlots(s32 applyPositions, s32 unused)
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
    ((BtlBattleState *)iGpffffb3ac)->unkA70 = -1;
    if (btlUnitRealignCells() == 1) {
        formation = -1;
    } else {
        btlCameraCountUnitsByBand(counts);
        formation = (s16)btlCameraFindFormationForCounts((u8 *)counts);
    }
    /* Keep sentinel comparison separate from the signed table-row conversion. */
    if ((s64)formation != -1) {
        memset(iGpffffb3ac + 0xA74, 0, 0x24);
        nextSlot = 1;
        actor = ((BtlBattleState *)iGpffffb3ac)->unitLists[0];
        layout = D_00607E50 + formation * 0xE0;
        while (actor != NULL) {
            s32 slot;
            u8 *entry;
            if ((u8 *)((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit == actor) {
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
            position.x = ((BtlCameraFormationSlot *)entry)->x;
            position.z = ((BtlCameraFormationSlot *)entry)->z;
            btlTargetPositionToCell((s16 *)(actor + 0x94), (s16 *)(actor + 0x96), (f32 *)&position);
            if (applyPositions != 0) {
                position.x = (f32)(((BtlUnit *)actor)->unk_94 * 25 - 1750);
                position.z = (f32)(((BtlUnit *)actor)->unk_96 * 25 - 1750);
                btlUnitSetPos(actor, (f32 *)&position);
            }
            switch (actor[0xA2]) {
            case 0:
                ((BtlCameraFormationOccupancy *)(iGpffffb3ac + slot * 4 + 0xA74))->party[0] = 1;
                break;
            case 1:
                ((BtlBattleState *)(iGpffffb3ac))->cameraEnemyOccupancy[slot] = 1;
                break;
            }
            actor[0x9FC] = (s8)selectedSlot;
            actor = (u8 *)((BtlUnit *)actor)->nextUnit;
        }

        enemy = ((BtlBattleState *)iGpffffb3ac)->unitLists[2];
        memset((u8 *)occupied, 0, 5 * sizeof(occupied[0]));
        while (enemy != NULL) {
            if (datCalcIsDead((u8*)((BtlUnit *)enemy)->datUnit, 0) == 0) {
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
                leastRadius = ((f32)(100000000));
                leastHeight = leastRadius;
                scale = ((BtlUnit *)enemy)->scale;
                radius = (f32)(s32)(((BtlUnit *)enemy)->sphereRadius * scale);
                height = (f32)(s32)(((BtlUnit *)enemy)->unk_8c * scale);
                for (cursor.index = 0; (u16)cursor.index < 5; cursor.index++) {
                    cursor.current = (u16)cursor.index;
                    if (occupied[cursor.current] != 1) {
                        u8 *candidate = layout + (s32)cursor.current * 0x18;
                        if (candidate[0x60] != 0) {
                            f32 heightSlack;
                            radiusSlack = ((BtlCameraFormationSlot *)(candidate + 0x60))->radius - radius;
                            heightSlack = ((BtlCameraFormationSlot *)(candidate + 0x60))->height - height;
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
                    leastRadius = ((f32)(100000000));
                    leastHeight = leastRadius;
                    for (cursor.index = 0; (u16)cursor.index < 5; cursor.index++) {
                        cursor.current = (u16)cursor.index;
                        if (occupied[cursor.current] != 1) {
                            u8 *candidate = layout + (s32)cursor.current * 0x18;
                            if (candidate[0x60] != 0) {
                                f32 heightSlack;
                                radiusSlack = ((BtlCameraFormationSlot *)(candidate + 0x60))->radius - radius;
                                heightSlack = ((BtlCameraFormationSlot *)(candidate + 0x60))->height - height;
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
                position.x = ((BtlCameraFormationSlot *)(entry + 0x60))->x;
                position.z = ((BtlCameraFormationSlot *)(entry + 0x60))->z;
                btlTargetPositionToCell((s16 *)(enemy + 0x94), (s16 *)(enemy + 0x96), (f32 *)&position);
                if (applyPositions != 0) {
                    position.x = (f32)(((BtlUnit *)enemy)->unk_94 * 25 - 1750);
                    position.z = (f32)(((BtlUnit *)enemy)->unk_96 * 25 - 1750);
                    btlUnitSetPos(enemy, (f32 *)&position);
                }
                switch (enemy[0xA2]) {
                case 0:
                    ((BtlCameraFormationOccupancy *)(iGpffffb3ac + occupiedOffset + 0xA74))->party[0] = 1;
                    break;
                case 1:
                    MEMBER(s32, iGpffffb3ac + occupiedOffset, BtlBattleState, cameraEnemyOccupancy[0]) = 1;
                    break;
                }
                enemy[0x9FC] = (s8)chosen;
            }
            enemy = (u8 *)((BtlUnit *)enemy)->nextUnit;
        }

        btlUnitGetGroupBounds(2, 1, &enemyCenter, NULL, NULL, 1);
        btlUnitGetSphereWorldCenter((u8 *)((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit, (f32 *)&actorCenter);
        facingUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            btlTargetBlendVectors(&rotation, &position, &enemyCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = (u8 *)((BtlUnit *)facingUnit)->prevUnit;
        }
        facingUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[3];
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            btlTargetBlendVectors(&rotation, &position, &actorCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = (u8 *)((BtlUnit *)facingUnit)->prevUnit;
        }
        ((BtlBattleState *)iGpffffb3ac)->unkA70 = formation;
        ((BtlBattleState *)iGpffffb3ac)->unkA72 = btlSideCountNotBad(2, 0x80000);
    }
}
#pragma pop

/* Move the flagged units along their horizontal animation-bound separation; return completion. */
// FUN_001D1CC0
s32 btlCameraNudgeUnitPair(u8 *work)
{
    /* Motion record 0xA supplies its signed Z bound for separation. */

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
    u8 *firstUnit;
    u8 *secondUnit;
    u8 *childUnit;
    u8 *bounds;
    f32 distance;
    f32 offsetZ;
    f32 scaleOrY;
    f32 radiusOrX;

    firstUnit = (u8 *)((BtlCameraUnitPair *)work)->first;
    secondUnit = (u8 *)((BtlCameraUnitPair *)work)->second;
    btlUnitGetAnimBoundsWorldCenterTowardUnit(secondUnit, (s32)firstUnit, (u8 *)&frame.value40);
    frame.value60 = MEMBER(f32, firstUnit, BtlUnit, pos.x) - frame.value40;
    frame.value64 = 0.0f;
    frame.value68 = MEMBER(f32, firstUnit, BtlUnit, pos.z) - frame.value48;
    RwV3dNormalize(&frame.value60, &frame.value60);
    if ((frame.value60 == 0.0f) && (frame.value68 == 0.0f)) {
        return 1;
    }
    bounds = btlUnitGetRecordPtr(secondUnit, 0xA);
    radiusOrX = (f32)((BtlUnitBoundsRecord *)(bounds))->z;
    scaleOrY = ((BtlUnit *)secondUnit)->scale;
    distance = ((BtlCameraUnitPair *)work)->separation;
    distance -= radiusOrX * scaleOrY;
    radiusOrX = frame.value60 * distance;
    frame.value60 = radiusOrX;
    scaleOrY = frame.value64 * distance;
    frame.value64 = scaleOrY;
    offsetZ = frame.value68 * distance;
    frame.value68 = offsetZ;
    if ((MEMBER(u16, work, BtlCameraUnitPair, flags) & 1) != 0) {
        frame.value50 = ((BtlUnit *)firstUnit)->pos.x + frame.value60;
        frame.value54 = ((BtlUnit *)firstUnit)->pos.y + frame.value64;
        frame.value58 = ((BtlUnit *)firstUnit)->pos.z + frame.value68;
        btlUnitSetPos(firstUnit, &frame.value50);
        childUnit = (u8 *)((BtlUnit *)firstUnit)->childUnit;
        if (childUnit != NULL) {
            frame.value50 = ((BtlUnit *)childUnit)->pos.x + frame.value60;
            frame.value54 = ((BtlUnit *)childUnit)->pos.y + frame.value64;
            frame.value58 = ((BtlUnit *)childUnit)->pos.z + frame.value68;
            btlUnitSetPos(childUnit, &frame.value50);
        }
    }
    if ((((BtlCameraUnitPair *)work)->flags & 2) != 0) {
        frame.value50 = ((BtlUnit *)secondUnit)->pos.x + frame.value60;
        frame.value54 = ((BtlUnit *)secondUnit)->pos.y + frame.value64;
        frame.value58 = ((BtlUnit *)secondUnit)->pos.z + frame.value68;
        btlUnitSetPos(secondUnit, &frame.value50);
    }
    return 1;
}

