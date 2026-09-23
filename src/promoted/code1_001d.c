#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001da5f0_xor(s32 left, s32 right)
{
    return left ^ right;
}
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern void btlUnitSetRot(void *arg0, void *arg1);
extern void func_001ec1c0(void *out, void *first, void *second);
extern void func_001ec6d0(s16 *arg0, s16 *arg1, f32 *position);
extern s32 func_001ef720(s32 groupFlags, s32 excludedFlags);
extern s64 func_0023a6b0(s32 arg0, s64 arg1);
extern u16 func_00231f80(u8 *arg0);
extern u16 func_00232290(u8 *arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 func_00231e20(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern u16 datCalcGetHp(u8 *arg0);
extern u16 datCalcGetSp(u8 *arg0);
extern s32 func_002340c0(s32 arg0, s32 arg1);
extern void func_001d6de0(s32 arg0, s32 arg1);
extern s32 func_001d6360(u8 *arg0);
extern void func_001d42e0(s32 arg0);
extern void func_00485b20(s32 arg0);
extern void func_004787e0(s32 arg0);
extern void func_001d6880(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void func_001d3e00(s32 arg0);
extern void func_001d6910(u8 *arg0);
extern void func_001d75d0(u8 *arg0);
extern void H_Cdvd_Destroy(u8 *arg0);
extern u32 iGpffffb3b8;
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern s32 func_0047a6d0();
extern void func_004789c0(u8 *arg0);
extern void func_0047a320(u8 *arg0);
extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern void func_00485870(s32 arg0);
extern s32 func_00481450(void);
extern void func_00481440(s32 arg0);
extern void mdlSetColor(u8 *arg0, u32 *arg1);
extern void func_004865c0(s32 arg0, u32 arg1);
extern void func_00478e70(s32 arg0);
extern void func_00485630(s32 arg0);
extern void func_001d53e0(s32 arg0);
extern void func_00479100(s32 arg0, u8 *arg1);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern u8 *func_00460990(void);
extern void func_00460ac0(char *arg0, u8 *arg1);
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
extern void func_001d44a0(f32 arg0, f32 arg1, f32 *arg2, s32 *arg3, u8 *arg4, u8 *arg5);
struct RwV3d;
extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void btlUnitSetPos(u8 *arg0, f32 *arg1);
extern void func_00195b60(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_0019eda0(u8 *arg0, s32 arg1);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern void func_0044ea90(u8 *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern s8 func_00231d70(s32 arg0);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern void func_0048a250(u8 *arg0);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);


extern s32 btlCond_MYBAD(u8 *task, s32 mask);
extern u8 *func_00457120();
extern void func_003e8110(u8 *arg0);
extern void func_003e8120(u8 *arg0);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();

extern int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6);
extern s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);



extern s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1);

extern s32 btlCond_MYHP(u8 *arg0, s32 arg1);

extern s32 func_001d97b0(u8 *arg0, s32 arg1);
extern s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1);
extern s32 btlCond_MYWEAK(u8 *arg0, s16 arg1);
extern s32 btlCond_MYUSEATTR(u8 *arg0, s32 arg1);
extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
extern u32 func_0023e130(u8 *arg0);
extern s32 func_00122640(s32 arg0, s32 arg1);

extern void func_001d7bb0(void);
extern void *func_00194470();

extern s32 func_001d7b30(u16 *arg0);
extern s32 func_0022ead0(void);

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

extern s32 func_001b1540(void);
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern f32 tanf(f32 arg0);
extern void func_001bac20(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Two-unit framing: stage all three vector sums before subtracting focus.
 * MWCC: 1004/1008 bytes, 19 resolved relocations, four zero tail bytes. */
// FUN_001D01C0
void btlAct_PURSUIT(u8 *arg0)
{
    struct
    {
        RwV3d firstPosition;
        RtQuat firstRotation;
        RwV3d secondPosition;
        RtQuat secondRotation;
    } poses;
    RwV3d firstCenter;
    RwV3d secondCenter;
    RwV3d direction;
    RwV3d side;
    RwV3d focus;
    RwV3d eye;
    u8 *action;
    u8 *unitA;
    u8 *unitB;
    f32 radius;
    f32 along;
    f32 spread;
    f32 distance;
    f32 length;
    RwV3d sum;

    u8 *temp = (u8 *)func_001b1540();
    action = *(u8 **)(arg0 + 0xE0);
    unitA = *(u8 **)(action + 0x30);
    unitB = *(u8 **)(temp + 0x30);
    btlUnitGetSphereWorldCenter(unitA, (f32 *)&firstCenter);
    radius = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C);
    btlUnitGetSphereWorldCenter(unitB, (f32 *)&secondCenter);
    direction.x = firstCenter.x - secondCenter.x;
    direction.y = firstCenter.y - secondCenter.y;
    direction.z = firstCenter.z - secondCenter.z;
    along = fGpffff8030 * RwV3dNormalize((f32 *)&direction, (f32 *)&direction);
    focus.x = direction.x * along;
    focus.y = direction.y * along;
    focus.z = direction.z * along;
    focus.x = focus.x + secondCenter.x;
    focus.y = focus.y + secondCenter.y;
    focus.z = focus.z + secondCenter.z;
    eye = firstCenter;
    eye.y = secondCenter.y;
    side.x = eye.x - secondCenter.x;
    side.y = eye.y - secondCenter.y;
    side.z = eye.z - secondCenter.z;
    RwV3dNormalize((f32 *)&side, (f32 *)&side);
    spread = 1.25f * radius;
    eye.x = (0.0f + eye.x) - side.z * spread;
    eye.z = (0.0f + eye.z) + side.x * spread;
    eye.y = (0.0f + firstCenter.y) +
            fGpffff803c * (*(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C));
    func_001bd780(&poses.firstRotation, &eye, &focus, D_0060A0E0);
    distance = (2.5f * radius) /
               tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    sum.x = eye.x + direction.x;
    sum.y = eye.y + direction.y;
    sum.z = eye.z + direction.z;
    direction.x = sum.x - focus.x;
    direction.y = sum.y - focus.y;
    direction.z = sum.z - focus.z;
    length = RwV3dNormalize((f32 *)&direction, (f32 *)&direction);
    along = 100.0f + length;
    direction.x = direction.x * along;
    direction.y = direction.y * along;
    direction.z = direction.z * along;
    poses.firstPosition.x = focus.x + direction.x;
    poses.firstPosition.y = focus.y + direction.y;
    poses.firstPosition.z = focus.z + direction.z;
    poses.secondRotation = poses.firstRotation;
    RtQuatTransformVectors((f32 *)&direction, D_0060A100, 1, (u8 *)&poses.firstRotation);
    along = 15.0f + length;
    direction.x = direction.x * along;
    direction.y = direction.y * along;
    direction.z = direction.z * along;
    poses.secondPosition.x = focus.x + direction.x;
    poses.secondPosition.y = focus.y + direction.y;
    poses.secondPosition.z = focus.z + direction.z;
    if (poses.firstPosition.y < 25.0f) {
        poses.firstPosition.y = 25.0f;
    }
    if (poses.secondPosition.y < 25.0f) {
        poses.secondPosition.y = 25.0f;
    }
    func_001bac20((u16 *)arg0, (f32 *)&poses.firstPosition, (f32 *)&poses.secondPosition, 1);
    func_001bbef0(arg0, 5.0f);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), (u8 *)&firstCenter, (f32 *)&secondCenter,
                  50.0f, 9);
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

    if (func_0022ead0() == 1) {
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
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
static inline f32 formationCapacityLimit(s32 limit)
{
    return (f32)limit;
}

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
    if (func_0022ead0() == 1) {
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
            func_001ec6d0((s16 *)(actor + 0x94), (s16 *)(actor + 0x96), (f32 *)&position);
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
                func_001ec6d0((s16 *)(enemy + 0x94), (s16 *)(enemy + 0x96), (f32 *)&position);
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

        func_00196040(2, 1, &enemyCenter, NULL, NULL, 1);
        btlUnitGetSphereWorldCenter(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30), (f32 *)&actorCenter);
        facingUnit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            func_001ec1c0(&rotation, &position, &enemyCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = *(u8 **)(facingUnit + 0xA68);
        }
        facingUnit = *(u8 **)(iGpffffb3ac + 0x184);
        while (facingUnit != NULL) {
            btlUnitGetSphereWorldCenter(facingUnit, (f32 *)&position);
            func_001ec1c0(&rotation, &position, &actorCenter);
            btlUnitSetRot(facingUnit, &rotation);
            facingUnit = *(u8 **)(facingUnit + 0xA68);
        }
        *(s16 *)(iGpffffb3ac + 0xA70) = formation;
        *(s16 *)(iGpffffb3ac + 0xA72) = func_001ef720(2, 0x80000);
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
    func_00195b60(temp_16, (s32)temp_17, (u8 *)&frame.value40);
    frame.value60 = *(f32 *)(temp_17 + 4) - frame.value40;
    frame.value64 = 0.0f;
    frame.value68 = *(f32 *)(temp_17 + 0xC) - frame.value48;
    RwV3dNormalize(&frame.value60, &frame.value60);
    if ((frame.value60 == 0.0f) && (frame.value68 == 0.0f)) {
        return 1;
    }
    bounds = func_0019eda0(temp_16, 0xA);
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
// FUN_001D41B0
u8 *func_001d41b0(u8 *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4)
{
    u32 temp_3;
    u32 offset;
    u32 base;
    u8 *result;
    u32 size;

    temp_3 = arg2;
    offset = (u16)arg1 * 0x314;
    base = (u32)arg0;
    size = *(u16 *)((u8 *)p4_001d7f10_add((s32)offset, (s32)base) + 0x10) * 4 + 0x68;
    func_0044ea90(D_00609498, 0x51);
    result = jtbl_008873E8[0](size, 0x40000);
    memset(result, 0, size);
    *(u8 **)(result + 0) = arg0;
    *(u8 **)(result + 4) = arg0 + offset + 8;
    *(u16 *)(result + 0x54) = *(u16 *)(*(u8 **)(result + 4) + 8);
    *(u8 **)(result + 0x58) = result + 0x68;
    *(s32 *)(result + 0x10) = -1;
    *(s32 *)(result + 0x18) = temp_3;
    *(s32 *)(result + 0x1C) = arg3;
    *(s32 *)(result + 8) = arg4;
    if ((arg1 & 0xFFFF) == 1) {
        *(s8 *)(result + 0x14) = func_00231d70(0x64);
    }
    return result;
}
// FUN_001D44A0
void func_001d44a0(f32 fparg0, f32 fparg1, f32 *arg0, s32 *arg1, u8 *arg2, u8 *arg3)
{
    struct Vec4 {
        f32 value[4];
    };
    f32 fStack_10[4];
    f32 uStack_20[4];
    f32 vectorWork[4];
    f32 origin[4];
    f32 var_f20;
    f32 neg_limit;
    s32 var_16;
    u8 temp_6;
    u8 temp_7;

    temp_6 = *(u8 *)(arg2 + 1);
    temp_7 = *(u8 *)(arg2 + 2);
    if (temp_6 == 4) {
        var_16 = temp_7 & 0xFF;
        if (var_16 == 8) {
            var_f20 = (*(u16 *)(arg2 + 4) == 0) ? 2.0f : fparg0;
        } else {
            var_f20 = 2.0f;
        }
    } else {
        var_f20 = *(f32 *)((u8 *)arg0 + 4) + fparg1 * D_006094B0[temp_6];
        var_16 = temp_7 & 0xFF;
        if ((var_16 == 8) && (*(u16 *)(arg2 + 4) != 0)) {
            var_f20 += fparg0;
        }
    }
    switch (var_16) {
    case 8:
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0);
        *(f32 *)((u8 *)arg3 + 4) = var_f20;
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8);
        break;
    case 9:
    case 10:
        func_0048a250((u8 *)origin);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            :
            : "r"(origin)
            : "$vf10", "memory");
        if (fparg0 < fparg1) {
            fparg1 = fparg1;
        } else {
            fparg1 = fparg0;
        }
        neg_limit = -fparg1;
        if (var_16 == 9) {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = *(f32 *)((u8 *)arg0 + 4);
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        } else {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = var_f20;
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        }
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vsub.xyzw $vf11, $vf11, $vf10 \n"
            :
            : "r"(origin)
            : "$vf10", "$vf11", "memory");
        if (var_16 == 10) {
            __asm__ volatile(
                "sqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
            vectorWork[1] = 0.0f;
            __asm__ volatile(
                "lqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2, $vf11, $vf11 \n"
            "vmulax.w $ACC, $vf0, $vf2x \n"
            "vmadday.w $ACC, $vf0, $vf2y \n"
            "vmaddz.w $vf2, $vf0, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf11, $vf11, $Q \n"
            :
            :
            : "$vf2", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile(
            "mfc1 $3, %0 \n"
            "nop \n"
            "qmtc2 $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(neg_limit)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vadd.xyzw $vf10, $vf10, $vf11 \n"
            "sqc2 $vf10, 0(%1) \n"
            :
            : "r"(origin), "r"(arg3)
            : "$vf10", "$vf11", "memory");
        break;
    default:
        *(struct Vec4 *)uStack_20 = *(struct Vec4 *)arg1;
        func_003dc740(uStack_20, D_0060A0E0, D_006094D0[temp_7], 2);
        RtQuatTransformVectors(fStack_10, (f32 *)D_0060A0F0, 1, (u8 *)uStack_20);
        fStack_10[0] = fStack_10[0] * fparg0;
        fStack_10[1] = fStack_10[1] * fparg0;
        fStack_10[2] = fStack_10[2] * fparg0;
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0) + fStack_10[0];
        *(f32 *)((u8 *)arg3 + 4) = var_f20 + fStack_10[1];
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8) + fStack_10[2];
        break;
    }
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}
// FUN_001D4780
void func_001d4780(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    s32 temp_2;
    f32 var_f20;
    f32 temp_f21;
    u8 *temp_s0;

    temp_s0 = arg2 + 8;
    temp_2 = *(u16 *)(arg2 + 0xC);
    if (temp_2 == 0) {
        var_f20 = *(f32 *)(arg0 + 0x30) * *(f32 *)(arg1 + 0x2C);
    } else {
        var_f20 = (f32)temp_2;
    }
    temp_f21 = 0.5f * (*(f32 *)(arg0 + 0x2C) * *(f32 *)(arg1 + 0x2C));
    frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
    frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
    frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
    RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
    frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
    frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
    frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
    func_001d44a0(var_f20, temp_f21, &frame.value70, (s32 *)(arg0 + 0x40), temp_s0, arg3);
}
// FUN_001D48B0
void func_001d48b0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value30;
        f32 value34;
        f32 value38;
        f32 pad3C;
        f32 value40;
        f32 value44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
    } frame;
    u16 temp_2;
    u8 *temp_16;

    temp_16 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value50);
    } else {
        temp_2 = *(u16 *)(temp_16 + 4);
        if (func_0047a6d0(*(u8 **)(arg1 + 0xA00), temp_2, &frame.value50) == 0) {
            frame.value40 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value44 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value48 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value30, &frame.value40, 1, arg0 + 0x40);
            frame.value50 = frame.value30 + *(f32 *)(arg0 + 0x34);
            frame.value54 = frame.value34 + *(f32 *)(arg0 + 0x38);
            frame.value58 = frame.value38 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value50;
    *(f32 *)(arg3 + 4) = frame.value54;
    *(f32 *)(arg3 + 8) = frame.value58;
}
// FUN_001D49C0
void func_001d49c0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x29C);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        func_004789c0(var_19);
        func_0047a320(var_19);
        if (func_0047a6d0(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value70;
    *(f32 *)(arg3 + 4) = frame.value74;
    *(f32 *)(arg3 + 8) = frame.value78;
}
// FUN_001D4B00
void func_001d4b00(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x290);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        func_004789c0(var_19);
        func_0047a320(var_19);
        if (func_0047a6d0(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value70;
    *(f32 *)(arg3 + 4) = frame.value74;
    *(f32 *)(arg3 + 8) = frame.value78;
}
// FUN_001D4C40
void func_001d4c40(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 temp;
    u8 *temp16;

    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(3, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, arg3);
}
// FUN_001D4CF0
void func_001d4cf0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, arg3);
}
// FUN_001D4DC0
void func_001d4dc0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, arg3);
}
// FUN_001D4E90
void func_001d4e90(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    *(s32 *)((u8 *)arg3 + 0) = 0;
    *(s32 *)((u8 *)arg3 + 4) = 0;
    *(s32 *)((u8 *)arg3 + 8) = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}

// FUN_001D4EB0
void func_001d4eb0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3)
{
    struct Frame {
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6c;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 pad7c;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 pad8c;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 pad9c;
    } frame;
    u8 *temp_16;
    u8 *temp_2;
    u32 temp_4;
    f32 temp_f20;

    temp_16 = arg2 + 8;
    if ((*(u8 *)(arg2 + 0xA) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 != *(s32 *)(arg0 + 0xC))) {
        arg3[0] = *(f32 *)(arg0 + 0x5C);
        arg3[1] = *(f32 *)(arg0 + 0x60);
        arg3[2] = *(f32 *)(arg0 + 0x64);
        goto end;
    }

    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value90);
    } else if (func_0047a6d0(*(u8 **)(arg1 + 0xA00),
                             *(u16 *)(temp_16 + 4),
                             &frame.value90) == 0) {
        frame.value70 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
        frame.value74 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
        frame.value78 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
        RtQuatTransformVectors(&frame.value60, &frame.value70, 1, arg0 + 0x40);
        frame.value90 = frame.value60 + *(f32 *)(arg0 + 0x34);
        frame.value94 = frame.value64 + *(f32 *)(arg0 + 0x38);
        frame.value98 = frame.value68 + *(f32 *)(arg0 + 0x3C);
    }

    arg3[0] = frame.value90;
    arg3[1] = frame.value94;
    arg3[2] = frame.value98;
    temp_4 = *(u16 *)(temp_16 + 6);
    if (temp_4 != 0) {
        if (temp_4 >= 0) {
            temp_f20 = (f32)temp_4;
        } else {
            temp_4 = (temp_4 >> 1) | (temp_4 & 1);
            temp_f20 = (f32)temp_4;
            temp_f20 = temp_f20 + temp_f20;
        }
        temp_2 = *(u8 **)(func_00457120() + 4);
        frame.value80 = *(f32 *)(temp_2 + 0x40) - frame.value90;
        frame.value84 = *(f32 *)(temp_2 + 0x44) - frame.value94;
        frame.value88 = *(f32 *)(temp_2 + 0x48) - frame.value98;
        RwV3dNormalize(&frame.value80, &frame.value80);
        arg3[0] = arg3[0] - frame.value80 * temp_f20;
        arg3[1] = arg3[1] - frame.value84 * temp_f20;
        arg3[2] = arg3[2] - frame.value88 * temp_f20;
    }

    if ((*(u8 *)(temp_16 + 2) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 == *(s32 *)(arg0 + 0xC))) {
        *(f32 *)(arg0 + 0x5C) = arg3[0];
        *(f32 *)(arg0 + 0x60) = arg3[1];
        *(f32 *)(arg0 + 0x64) = arg3[2];
    }
end:
    ;
}
// FUN_001D5130
void func_001d5130(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    struct Frame {
        f32 input[16];
        f32 output[16];
        f32 vector[4];
    } frame;
    u8 type;
    u8 *entry;
    s32 flags;
    s32 lookup;
    s32 lookup_offset;
    u8 *lookup_base;

    extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
    extern f32 func_0044b950(f32 arg0, f32 arg1);
    extern s32 func_0047a510(u8 *arg0, s32 arg1, f32 *arg2);
    extern void func_0048a980(f32 *arg0);
    extern void func_004bcf20(f32 arg0, f32 arg1, f32 arg2);

    entry = arg2 + 8;
    type = *(u8 *)(arg2 + 8);
    switch (type) {
    case 0:
        RtQuatTransformVectors(frame.vector, (f32 *)D_0060A0F0, 1, arg0 + 0x40);
        if (frame.vector[0] != 0.0f)
            goto case0_nonzero;
        if (frame.vector[2] == 0.0f)
            goto case0_zero;
case0_nonzero:
        func_004bcf20(0.0f,
                      func_0044b950(frame.vector[0], frame.vector[2]),
                      0.0f);
        __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
        goto case0_done;
case0_zero:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
case0_done:
        break;
    case 2:
    case 3:
    case 4:
    case 0xC:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 1:
    case 0xD:
        flags = *(s32 *)(arg1 + 0x98);
        if ((flags & 2) == 0)
            goto case1_no_flags;
        if (func_0047a510(*(u8 **)(arg1 + 0xA00),
                          *(u16 *)(entry + 4), frame.input) == 0)
            goto case1_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            func_0048a980(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
        break;
case1_failure:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
case1_no_flags:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 8:
    case 9:
        flags = *(s32 *)(arg1 + 0x98);
        if ((flags & 2) != 0) {
            lookup_offset = 12 * (type == 8);
            lookup_base = *(u8 **)(arg1 + 0xA00);
            lookup_base += 0x290;
            lookup = *(s32 *)(lookup_base + lookup_offset);
            if (lookup == 0)
                break;
            if (func_0047a510((u8 *)lookup,
                              *(u16 *)(entry + 4), frame.input) == 0)
                goto case8_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            func_0048a980(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
            break;
case8_failure:
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        } else {
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        }
        break;
    case 7:
    case 0xA:
    case 0xB:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 5:
    case 6:
        break;
    default:
        break;
    }
}
/* measured: retail window to func_001d5990, frame 0x210 (sq s16-s23 s30 ra + swc1 f20-f25); 158 emitted instrs per assignment. */
/* measured: neighbours mined: MATCHed func_001d1680 (opt_loop_invariants hoist), func_001d8010 floor (2992B window), plus externs func_00195850 func_001ec1c0 func_001fc2c0 func_00485c80 already declared; conventions are u8-star base-pointer field access and explicit index vars. */
/* measured: m2c draft at src-generated code1_001d line 2834 is clean of M2C_ERROR in prologue/fork (colour-table blocks mirror retail) but carries mula-madd MAC M2C_ERROR plus saved_reg_gp pseudo and s128 lq-sq locals in tail loop needing GP-type lowering; no slt-at entry guard here (bltz sign tests for half-u8-to-float), slti-at and dead-store levers checked N/A for current shape. First reconstruction in progress, retained ASM pending MAC-GP lowering; any body will be kept full-size (within 3 percent). */
/* retail 1456B window to func_001d5990, frame 0x210 (sq s16-s23 s30 ra plus swc1 f20-f25); GP D_00609500 and GP offsets pending mapping; residual is MAC staging plus s128-quad and two-arg GP-ABI lowering. */
// FUN_001D53E0 NONMATCHING
#ifdef SKIP_ASM
void func_001d53e0(s32 arg0) {
    extern void func_001fc2c0(u8 *a0, u8 *a1);
    extern u32 func_00485c80(u32 a0);
    extern s32 func_004861f0(u8 *a0, f32 *a1);
    extern void func_00486330(s32 a0, u8 *a1);
    extern void func_00486400(u8 *a0, f32 a1);
    extern float fGpffff8354;
    extern float fGpffff838c;
    extern void (*D_00609500[])(u8 *a0, u8 *a1, u8 *a2, u8 *a3);
    struct Frame {
        f32 spA0[4];
        f32 spB0[4];
        f32 spC0[4];
        f32 spD0[4];
    } frame;
    u8 *base;
    u8 *temp_16;
    s32 temp_22;
    u32 temp_19;
    s32 *var_18;
    u8 *var_17;
    s32 var_21;
    s32 var_23;
    u16 temp_30;
    s32 temp_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f12;
    u8 temp_3;
    u8 temp_4_3;
    u8 temp_5;
    u8 temp_5_2;
    u8 *temp_4_2;

    base = (u8 *)arg0;
    temp_16 = *(u8 **)(base + 0x18);
    temp_22 = *(s32 *)(base + 0x10);
    temp_4 = *(s32 *)(base + 8);
    if ((temp_4 & 0x800) != 0) {
        return;
    }
    if ((temp_22 & 0xFF000000) == 0) {
        return;
    }
    temp_19 = *(u32 *)(base + 0xC);
    if ((temp_19 == 0) || ((temp_4 & 0x1000) && (temp_19 == *(s32 *)(*(u8 **)(base + 0) + 0x320))) || (temp_4 & 0x100)) {
        *(f32 *)(base + 0x20) = *(f32 *)(temp_16 + 0x80);
        *(f32 *)(base + 0x24) = *(f32 *)(temp_16 + 0x84);
        *(f32 *)(base + 0x28) = *(f32 *)(temp_16 + 0x88);
        *(f32 *)(base + 0x2C) = *(f32 *)(temp_16 + 0x8C);
        *(f32 *)(base + 0x30) = *(f32 *)(temp_16 + 0x90);
        *(f32 *)(base + 0x34) = *(f32 *)(temp_16 + 4);
        *(f32 *)(base + 0x38) = *(f32 *)(temp_16 + 8);
        *(f32 *)(base + 0x3C) = *(f32 *)(temp_16 + 0xC);
        temp_4_2 = *(u8 **)(base + 0x1C);
        if ((temp_16 == temp_4_2) || (*(s32 *)(temp_16 + 0x9C) & 0x2000)) {
            *(f32 *)(base + 0x40) = *(f32 *)(temp_16 + 0x1C);
            *(f32 *)(base + 0x44) = *(f32 *)(temp_16 + 0x20);
            *(f32 *)(base + 0x48) = *(f32 *)(temp_16 + 0x24);
            *(f32 *)(base + 0x4C) = *(f32 *)(temp_16 + 0x28);
        } else {
            temp_3 = *(u8 *)(temp_16 + 0xA2);
            if ((temp_3 == *(u8 *)(temp_4_2 + 0xA2)) && (temp_3 == 1)) {
                *(f32 *)(base + 0x40) = *(f32 *)(temp_16 + 0x1C);
                *(f32 *)(base + 0x44) = *(f32 *)(temp_16 + 0x20);
                *(f32 *)(base + 0x48) = *(f32 *)(temp_16 + 0x24);
                *(f32 *)(base + 0x4C) = *(f32 *)(temp_16 + 0x28);
            } else {
                btlUnitGetSphereWorldCenter(temp_16, frame.spD0);
                btlUnitGetSphereWorldCenter(*(u8 **)(base + 0x1C), frame.spC0);
                func_001ec1c0(base + 0x40, frame.spD0, frame.spC0);
            }
        }
        *(f32 *)(base + 0x50) = *(f32 *)(temp_16 + 0x2C);
    }
    func_001fc2c0(*(u8 **)(base + 0x18), *(u8 **)(base + 0x1C));
    var_18 = *(s32 **)(base + 0x58);
    temp_30 = *(u16 *)(base + 0x54);
    var_17 = *(u8 **)(base + 4) + 0x14;
    for (var_21 = 0; (var_21 & 0xFFFF) < temp_30; var_21 = (var_21 + 1) & 0xFFFF, var_17 += 0x18, var_18 += 1) {
        if ((u32)*(u32 *)(var_17 + 0x10) < temp_19) {
            temp_5 = *(u8 *)(var_17 + 0);
            if (temp_5 != 0xFE) {
                if (*var_18 == 0) {
                    if ((*(u16 *)(*(u8 **)(base + 0) + 0x630) & 4) && (temp_5 != 0xFD)) {
                        *var_18 = *(s32 *)(var_17 + 4);
                        var_23 = 0;
                        *(u8 *)(var_17 + 0) = 0xFD;
                    } else {
                        *var_18 = (s32)func_00485c80(*(u32 *)(var_17 + 4));
                        var_23 = 1;
                    }
                    temp_5_2 = *(u8 *)(*(u8 **)(base + 4) + 0x10);
                    if ((temp_5_2 != 0) && (temp_16 != NULL)) {
                        temp_4_3 = *(u8 *)(var_17 + 8);
                        if ((temp_4_3 == 7) || (temp_4_3 == 6) || (temp_4_3 == 0xD) || (temp_4_3 == 1) || (temp_4_3 == 0)) {
                            if (temp_5_2 != 1) {
                                var_f12 = fGpffff8354 * ((*(f32 *)(*(u8 **)(base + 0x1C) + 0x90) * *(f32 *)(*(u8 **)(base + 0x1C) + 0x2C) + *(f32 *)(*(u8 **)(base + 0x1C) + 0x8C) * *(f32 *)(*(u8 **)(base + 0x1C) + 0x2C) * 0.5f) * 0.5f);
                                if (var_f12 > 2.5f) {
                                    var_f12 = 2.5f;
                                } else if (var_f12 < fGpffff838c) {
                                    var_f12 = fGpffff838c;
                                }
                            } else if ((*(s32 *)(base + 8) & 0x20000) == 0) {
                                var_f12 = fGpffff8354 * ((*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C) + *(f32 *)(temp_16 + 0x8C) * *(f32 *)(temp_16 + 0x2C) * 0.5f) * 0.5f);
                                if (var_f12 > 2.5f) {
                                    var_f12 = 2.5f;
                                } else if (var_f12 < fGpffff838c) {
                                    var_f12 = fGpffff838c;
                                }
                            } else if (*(s32 *)(iGpffffb3ac + 0x314) == 0) {
                                var_f12 = 4.25f;
                            } else {
                                var_f12 = (2.0f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C))) / 100.0f;
                                if (var_f12 > 5.0f) {
                                    var_f12 = 5.0f;
                                } else if (var_f12 < 2.0f) {
                                    var_f12 = 2.0f;
                                }
                            }
                            func_00486400((u8 *)*var_18, var_f12);
                        }
                    }
                    if (var_23 != 0) {
                        continue;
                    }
                }
                    if ((*(u16 *)(var_17 + 0xE) != 1) || ((*(s32 *)(base + 8) & 0x1E) == 0 && (s32)*(u8 *)(base + 0x14) >= 0x32)) {
                        if ((*(s32 *)(base + 8) & 0x20000) == 0) {
                            D_00609500[*(u8 *)(var_17 + 8)](base, temp_16, var_17, (u8 *)frame.spB0);
                        } else {
                            if (*(s32 *)(iGpffffb3ac + 0x314) != 0) {
                                frame.spB0[0] = *(f32 *)(temp_16 + 4);
                                frame.spB0[1] = *(f32 *)(temp_16 + 8);
                                frame.spB0[2] = *(f32 *)(temp_16 + 0xC);
                            } else {
                                *(s32 *)&frame.spB0[0] = 0;
                                *(s32 *)&frame.spB0[1] = 0;
                                *(s32 *)&frame.spB0[2] = 0xC2AA0000;
                            }
                            *(s32 *)&frame.spB0[3] = 0;
                        }
                        func_004861f0((u8 *)*var_18, frame.spB0);
                        func_001d5130(base, temp_16, var_17, (u8 *)frame.spA0);
                        func_00486330(*var_18, (u8 *)frame.spA0);
                        func_004865c0(*var_18, (u32)temp_22);
                        func_00485630(*var_18);
                    }
            }
        }
    }
    *(u32 *)(base + 0xC) = *(u32 *)(base + 0xC) + 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d53e0);
#endif
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
#pragma optimization_level 1
// FUN_001D5990
void func_001d5990(void)
{
    struct Frame {
        f32 sp10;
        f32 sp14;
        f32 sp18;
        s32 sp1C;
        f32 sp20;
        f32 sp24;
        f32 sp28;
        f32 pad2C;
        f32 sp30;
        f32 sp34;
        f32 sp38;
        f32 pad3C;
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 pad4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
    } frame;
    u32 *source;
    u32 *destination;
    s32 count;
    u32 first;
    u32 second;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    extern f32 fGpffff8444;
    extern f32 fGpffff8448;
    extern f32 fGpffff844c;
    extern f32 fGpffff8450;
    extern f32 fGpffff8454;
    extern f32 fGpffff8458;
    extern f32 fGpffff845c;
    extern f32 fGpffff8460;
    extern f32 fGpffff8464;
    extern f32 fGpffff8468;
    extern f32 fGpffff846c;
    extern f32 fGpffff8470;
    extern f32 fGpffff8474;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;

    func_003e8110(func_00457120());
    source = (u32 *)(*(u8 **)(func_00457120() + 4) + 0x10);
    destination = (u32 *)D_008813B0;
    count = 8;
    do {
        first = source[0];
        second = source[1];
        source += 2;
        count--;
        destination[0] = first;
        destination[1] = second;
        destination += 2;
    } while (count > 0);
    frame.sp10 = fGpffff8444;
    frame.sp14 = fGpffff8448;
    frame.sp18 = fGpffff844c;
    frame.sp20 = fGpffff8450;
    frame.sp24 = fGpffff8454;
    frame.sp28 = fGpffff8458;
    frame.sp30 = fGpffff845c;
    frame.sp34 = fGpffff8460;
    frame.sp38 = fGpffff8464;
    frame.sp40 = 0;
    frame.sp44 = 0;
    frame.sp48 = 0;
    frame.sp1C = 3;
    frame.sp50 = fGpffff8468;
    frame.sp54 = fGpffff846c;
    frame.sp58 = fGpffff8470;
    temp1 = frame.sp50;
    temp2 = frame.sp54;
    temp3 = frame.sp58;
    frame.sp40 = temp1;
    frame.sp44 = temp2;
    frame.sp48 = temp3;
    func_003e9cb0(*(s32 *)(func_00457120() + 4), (u8 *)&frame.sp10, 0);
    func_003e8120(func_00457120());
}
/* measured: restore optimization_level 2 after func_001d5990. */
#pragma optimization_level 2
// FUN_001D5AC0
void func_001d5ac0(void) {
    func_003e8110(func_00457120());
    func_003e9cb0(*(s32 *)(func_00457120() + 4), D_008813B0, 0);
    func_003e8120(func_00457120());
}

// FUN_001D5B20
void func_001d5b20(u8 *arg0)
{
    s32 old_state;
    u8 **entries;
    s32 count;
    s32 index;
    u8 *task;

    if ((*(s32 *)(arg0 + 8) & 0x400) != 0) {
        return;
    }
    entries = *(u8 ***)(arg0 + 0x58);
    count = (u16)(*(u16 *)(arg0 + 0x54) & 0xFFFF);
    if ((*(s32 *)(arg0 + 8) & 0x8000) == 0) {
        index = 0;
        count = (u16)(count & 0xFFFF);
        while ((u16)index < count) {
            if (*entries != NULL) {
                func_00485870((s32)*entries);
            }
            index = (index + 1) & 0xFFFF;
            entries++;
        }
        return;
    }
    old_state = func_00481450();
    func_00481440((s32)D_005DC824);
    task = func_00460990();
    *(s32 *)(task + 0) = 0;
    *(s32 *)(task + 4) = 0;
    *(void (**)(void))(task + 8) = func_001d5990;
    *(u8 **)(task + 0x10) = iGpffffb3ac;
    func_00460ac0(D_00794AE0, task);
    index = 0;
    count = (u16)(count & 0xFFFF);
    while ((u16)index < count) {
        if (*entries != NULL) {
            func_00485870((s32)*entries);
        }
        index = (index + 1) & 0xFFFF;
        entries++;
    }
    func_00481440(old_state);
    task = func_00460990();
    *(s32 *)(task + 0) = 0;
    *(s32 *)(task + 4) = 0;
    *(void (**)(void))(task + 8) = func_001d5ac0;
    *(u8 **)(task + 0x10) = iGpffffb3ac;
    func_00460ac0(D_00794C00, task);
}
// FUN_001D6300
void func_001d6300(u8 *arg0) {
    u8 *temp_3;

    *(s32 *)(arg0 + 0x1C) = 0;
    func_001d40d0(*(u8 **)(arg0 + 0));
    temp_3 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_3 + 0xA0) = (u16) (*(u16 *)(temp_3 + 0xA0) + 1);
    *(s32 *)(arg0 + 0x18) = func_001d6ce0(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA08));
}

/* measured: opt_propagation off probe for func_001d6360 argument setup and register coloring. */
#pragma push
#pragma opt_propagation off
// FUN_001D6360
s32 func_001d6360(u8 *arg0)
{
    extern s32 func_00193b70(s64 arg0, s64 arg1);
    extern s32 func_001d4120(s32 arg0);
    extern s32 func_001d4140(s32 arg0, s32 arg1);
    extern s32 func_001d41b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    s32 count;
    s32 value;
    s32 arg1;
    s32 index;
    s32 index_temp;
    s64 key;
    u8 *packet;
    u8 *abort_packet;
    s32 arg4;
    if (func_001d4120(*(s32 *)(arg0 + 0)) == 0)
        return 0;
    packet = *(u8 **)(arg0 + 0x18);
    if ((*(s32 *)(packet + 4) & 0xFF000000) == 0)
        return 1;
    if ((*(u16 *)(packet + 0) & 0x40) == 0) {
        if ((*(s32 *)(arg0 + 0x20) & 0x4000) == 0) {
            index_temp = func_001d4140(*(s32 *)(arg0 + 0), 0) * 2;
            index = index_temp;
        } else {
            index_temp = *(s32 *)(arg0 + 0x1C) + 1;
            index = index_temp;
        }
        count = *(s32 *)(arg0 + 8);
        if ((count != 0 && *(s32 *)(arg0 + 0x1C) >= count * 2 - 13) ||
            ((key = *(s64 *)(arg0 + 0x10)) != 0 &&
             func_00193b70(key, (s64)0x3FFFFFFFFFFFFFFF) == 0) ||
            (index != 0 && *(s32 *)(arg0 + 0x1C) >= index)) {
            if ((*(s32 *)(arg0 + 0x20) & 0x2000) != 0)
                *(s8 *)(*(u8 **)(arg0 + 0x18) + 8) = 7;
            abort_packet = *(u8 **)(arg0 + 0x18);
            *(u16 *)(abort_packet + 0) |= 0x100;
            return 0;
        } else {
            value = *(s32 *)(arg0 + 0x1C);
            if (value == 0) {
                arg1 = *(s32 *)(arg0 + 4);
                arg4 = *(s32 *)(arg0 + 0x20);
                *(s32 *)(packet + 0x10) =
                    func_001d41b0(*(s32 *)(arg0 + 0), 0, arg1, arg1, arg4);
            } else if (value == 2) {
                if ((*(s32 *)(arg0 + 0x20) & 0x10000) == 0) {
                    *(u16 *)(packet + 0) |= 0xB0;
                    *(s32 *)(packet + 4) =
                        (u32)*(u64 *)(packet + 4) & 0x00FFFFFF;
                } else {
                    *(u16 *)(packet + 0) |= 0x30;
                    *(s32 *)(packet + 4) = -1;
                }
            }
            *(s32 *)(arg0 + 0x1C) = *(s32 *)(arg0 + 0x1C) + 2;
        }
    }
    return 0;
}
/* measured: restore pragma state after func_001d6360. */
#pragma pop
// FUN_001D6570
void func_001d6570(u8 *arg0)
{
    func_001d6de0(*(s32 *)(*(u8 **)(arg0 + 4) + 0xA08), *(s32 *)(arg0 + 0x18));
    func_001d3e00(*(s32 *)arg0);
    *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) =
        *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) - 1;
}

// FUN_001D65D0
u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x302, 0x28);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void (**)(u8 *))(packet + 0x68) = func_001d6300;
    *(s32 (**)(u8 *))(packet + 0x6C) = func_001d6360;
    *(void (**)(u8 *))(packet + 0x70) = func_001d6570;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)(work + 0) = arg0;
    *(s32 *)(work + 4) = arg1;
    *(s32 *)(work + 8) = arg2;
    *(s64 *)(work + 0x10) = arg3;
    *(s32 *)(work + 0x20) = arg4;
    return packet;
}
/* The 0x24-byte records built by func_001d6ad0 store packed RGBA at +4
 * and a wrapping frame counter at +0xC. Fade-out wins over fade-in;
 * bit 0x40 freezes update/cleanup, not drawing.
 * Retail: 504/512B, 14 resolved relocations, eight zero tail bytes. */
// FUN_001D6680
void func_001d6680(void)
{
    struct BtlPacket {
        u16 flags;
        u16 unknown02;
        u32 color;
        u8 step;
        u8 unknown09;
        u8 unknown0a;
        u8 unknown0b;
        u32 counter;
        u8 *unknown10;
        u8 *unknown14;
        u8 *unknown18;
        u8 *unknown1c;
        u8 *next;
    };
    struct BtlPacket *node;
    u32 color;
    u16 flags;
    u32 step;
    u32 arg;

    func_00481440((s32)D_005DC7D0);
    node = *(struct BtlPacket **)(iGpffffb3ac + 0x1B8);
    while (node != NULL) {
        color = node->color;
        flags = node->flags;
        if ((flags & 0x40) == 0) {
            if ((flags & 0x100) != 0) {
                step = (u32)node->step << 24;
                if (step < (color & 0xFF000000)) {
                    color = color - step;
                } else {
                    color = color & 0x00FFFFFF;
                    node->flags = flags & 0xFE7F;
                }
            } else if ((flags & 0x80) != 0) {
                step = (u32)node->step << 24;
                if (step < (u32)(0xFF000000 - (color & 0xFF000000))) {
                    color = color + step;
                } else {
                    color = color & 0x00FFFFFF;
                    color = color | 0xFF000000;
                    node->flags = flags & 0xFE7F;
                }
            }
            if ((node->flags & 0x220) == 0x220) {
                if (node->unknown18 != NULL) {
                    func_00478e70((s32)node->unknown18);
                }
                if (node->unknown14 != NULL) {
                    func_00485630((s32)node->unknown14);
                }
                if (node->unknown10 != NULL) {
                    func_001d53e0((s32)node->unknown10);
                }
            }
        }
        if ((node->flags & 0x210) == 0x210 && (color & 0xFF000000) != 0) {
            if (node->unknown18 != NULL) {
                arg = color;
                mdlSetColor(node->unknown18, &arg);
                func_00479100((s32)D_00794150, node->unknown18);
            }
            if (node->unknown14 != NULL) {
                func_004865c0((s32)node->unknown14, color);
                func_00485870((s32)node->unknown14);
            }
            if (node->unknown10 != NULL) {
                *(u32 *)(node->unknown10 + 0x10) = color;
                func_001d5b20(node->unknown10);
            }
        }
        node->color = color;
        node->counter = node->counter + 1;
        node = (struct BtlPacket *)node->next;
    }
}
// FUN_001D6910
void func_001d6910(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x10) != 0) {
        func_001d42e0(*(s32 *)(arg0 + 0x10));
        *(s32 *)(arg0 + 0x10) = 0;
    }
    if (*(s32 *)(arg0 + 0x14) != 0) {
        func_00485b20(*(s32 *)(arg0 + 0x14));
        *(s32 *)(arg0 + 0x14) = 0;
    }
    if (*(s32 *)(arg0 + 0x18) != 0) {
        func_004787e0(*(s32 *)(arg0 + 0x18));
        *(s32 *)(arg0 + 0x18) = 0;
    }
    *(s32 *)(arg0 + 4) = -1;
    *(u8 *)(arg0 + 8) = 0x14;
    *(s32 *)(arg0 + 0xC) = 0;
    *(u16 *)(arg0 + 0) = 0x200;
    if (*(u8 **)(arg0 + 0x20) != NULL) {
        *(u8 **)(*(u8 **)(arg0 + 0x20) + 0x1C) = *(u8 **)(arg0 + 0x1C);
    }
    if (*(u8 **)(arg0 + 0x1C) != NULL) {
        *(u8 **)(*(u8 **)(arg0 + 0x1C) + 0x20) = *(u8 **)(arg0 + 0x20);
    } else {
        *(u8 **)(iGpffffb3ac + 0x1B8) = *(u8 **)(arg0 + 0x20);
    }
    (*jtbl_008873EC)(arg0);
}
// FUN_001D6A60
void func_001d6a60(void)
{
}

// FUN_001D6A70
void func_001d6a70(void)
{
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x1B8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x20);
        func_001d6910(var_4);
        var_4 = temp_16;
    }
    func_001d75d0(var_4);
}

// FUN_001D6AD0
u8 *func_001d6ad0(void)
{
    u8 *array;
    u32 i;
    u8 *node;
    u8 *head;
    u32 table;
    func_0044ea90(D_00609558, 0x51);
    table = (u32)jtbl_008873E8;
    array = (u8 *)((u8 *(*)(s32, s32))*(u32 *)table)(0xC8, 0x40000);
    memset(array, 0, 0xC8);
    i = 0;
    while (i < 0x30) {
        func_0044ea90(D_00609558, 0x51);
        node = (u8 *)((u8 *(*)(s32, s32))*(u32 *)table)(0x24, 0x40000);
        memset(node, 0, 0x24);
        *(s32 *)(node + 4) = -1;
        *(u8 *)(node + 8) = 0x14;
        *(s32 *)(node + 0xC) = 0;
        *(u16 *)(node + 0) = 0x200;
        *(s32 *)(node + 0x1C) = 0;
        head = *(u8 **)(iGpffffb3ac + 0x1B8);
        if (head != NULL) {
            *(u8 **)(head + 0x1C) = node;
            head = *(u8 **)(iGpffffb3ac + 0x1B8);
            *(u8 **)(node + 0x20) = head;
        } else {
            *(u8 **)(node + 0x20) = NULL;
        }
        *(u8 **)(iGpffffb3ac + 0x1B8) = node;
        *(u8 **)(array + i * 4) = node;
        i++;
    }
    return array;
}
// FUN_001D6C10
void func_001d6c10(u8 *arg0)
{
    u32 i;
    u8 *entry;
    u8 *next;
    u8 *prev;

    i = 0;
    while (i < 0x30U) {
        entry = *(u8 **)(arg0 + (i * 4));
        func_001d6880(entry);
        next = *(u8 **)(entry + 0x20);
        if (next != NULL) {
            *(u8 **)(next + 0x1C) = *(u8 **)(entry + 0x1C);
        }
        prev = *(u8 **)(entry + 0x1C);
        if (prev != NULL) {
            *(u8 **)(prev + 0x20) = *(u8 **)(entry + 0x20);
        } else {
            *(u8 **)(iGpffffb3ac + 0x1B8) = *(u8 **)(entry + 0x20);
        }
        (*jtbl_008873EC)(entry);
        i++;
    }
    (*jtbl_008873EC)(arg0);
}
// FUN_001D72E0
s32 func_001d72e0(s32 arg0)
{
    if (arg0 == 0) {
        return -1;
    }
    switch (arg0) {
    case 2:
        return 0x12;
    case 4:
        return 0x13;
    case 8:
        return 0x14;
    case 0x10:
        return 0x15;
    case 1:
        return 0x16;
    case 0x20:
        return 0x17;
    case 0x40:
        return 0x18;
    case 0x80:
        return 0x19;
    case 0x100:
        return 0x1A;
    case 0x80000:
    case 0x100000:
    default:
        return -1;
    }
}
/* measured: opt_propagation off plus ascending default loads reproduces retail exactly (object 452B/window 464B, normalized_diff 0). */
// FUN_001D7400
/* measured: opt_propagation off is required for the default GP load/store register order. */
#pragma opt_propagation off
void func_001d7400(s32 arg0, u8 *arg1)
{
    u8 * arg1_p = arg1;
    s32 arg0_p = arg0;
    u8 temp_0;
    u8 temp_1;
    u8 temp_2;
    u8 temp_3;

    *(u8 *)(arg1_p + 3) = 0xFF;
    switch (arg0_p) {
    case 2:
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(1 + arg1_p) = 0xB2;
        *(u8 *)(arg1 + 2) = 0x9E;
        break;
    case 4:
        *(u8 *)(arg1_p + 0) = 0xB2;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(arg1 + 2) = 0xFF;
        break;
    case 8:
        *(u8 *)(arg1_p + 0) = 0xB2;
        *(u8 *)(arg1 + 1) = 0xFF;
        *(u8 *)(2 + arg1_p) = 0xB2;
        break;
    case 0x10:
        *(u8 *)(arg1_p + 0) = 0xEE;
        *(u8 *)(arg1_p + 1) = 0x9B;
        *(u8 *)(arg1 + 2) = 0xDA;
        break;
    case 1:
        *(u8 *)(arg1_p + 0) = 0xFF;
        *(u8 *)(arg1_p + 1) = 0x94;
        *(u8 *)(arg1 + 2) = 0x76;
        break;
    case 0x20:
        *(u8 *)(0 + arg1_p) = 0xBC;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(arg1_p + 2) = 0xFF;
        break;
    case 0x40:
        *(u8 *)(arg1 + 0) = 0x9E;
        *(u8 *)(arg1 + 1) = 0xE4;
        *(u8 *)(arg1_p + 2) = 0xE1;
        break;
    case 0x80:
        *(u8 *)(0 + arg1_p) = 0xCD;
        *(u8 *)(arg1_p + 1) = 0xB9;
        *(u8 *)(arg1_p + 2) = 0xD7;
        break;
    case 0x100:
        *(u8 *)(0 + arg1_p) = 0x94;
        *(u8 *)(arg1_p + 1) = 0x10;
        *(u8 *)(arg1_p + 2) = 0x26;
        break;
    case 0x100000:
    case 0x80000:
    default:
        temp_0 = iGpffffa4d8;
        temp_1 = iGpffffa4d9;
        temp_2 = iGpffffa4da;
        temp_3 = iGpffffa4db;
        *(u8 *)(arg1 + 0) = temp_0;
        *(u8 *)(arg1 + 1) = temp_1;
        *(u8 *)(arg1 + 2) = temp_2;
        *(u8 *)(arg1 + 3) = temp_3;
        break;
    }
}
/* measured: close opt_propagation after func_001d7400. */
#pragma opt_propagation on
// FUN_001D75D0
#pragma opt_propagation off
void func_001d75d0(u8 *arg0)
{
    int iVar1 = 0;
    u32 firstIndex = 0;
    u32 uVar2 = 0;
    int iVar3 = 0;
    u8 *state;

    if ((*(u32 *)(iGpffffb3ac + 0x14) & 0x4000000) == 0) {
        for (firstIndex = 0; firstIndex < 0x30; firstIndex = firstIndex + 1) {
            state = iGpffffb3ac;
            if (*(int *)(state + firstIndex * 4 + 0xD04) != 0) {
                func_001d3e00(*(u32 *)(state + firstIndex * 4 + 0xD04));
                *(u32 *)(iGpffffb3ac + firstIndex * 4 + 0xD04) = 0;
            }
        }
        if (*(int *)(iGpffffb3ac + 0xDC4) != 0) {
            H_Cdvd_Destroy((u8 *)(u32)*(u32 *)(iGpffffb3ac + 0xDC4));
            *(u32 *)(iGpffffb3ac + 0xDC4) = 0;
        }
    }
    else {
        for (uVar2 = 0; uVar2 < 0x30; uVar2 = uVar2 + 1) {
            state = iGpffffb3ac;
            iVar3 = uVar2 * 4;
            iVar1 = *(int *)(state + iVar3 + 0xD04);
            if (iVar1 != 0) {
                (*jtbl_008873EC)((u8 *)(u32)*(u32 *)(iVar1 + 0x634));
                func_001d3e00(*(u32 *)(iGpffffb3ac + iVar3 + 0xD04));
                *(u32 *)(iGpffffb3ac + iVar3 + 0xD04) = 0;
            }
        }
    }
    *(u32 *)(iGpffffb3ac + 0xC) = *(u32 *)(iGpffffb3ac + 0xC) & 0xfffbffff;
}
#pragma opt_propagation on
// FUN_001D7700
void func_001d7700(void)
{
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffffb3ac;
    if ((*(s32 *)(temp_5 + 0x14) & 0x4000000) == 0) {
        temp_4 = *(u8 **)(temp_5 + 0xDC4);
        if (temp_4 != NULL) {
            H_Cdvd_Destroy(temp_4);
        }
        *(u8 **)(iGpffffb3ac + 0xDC4) = NULL;
        return;
    }
    *(u8 **)(temp_5 + 0xDC4) = NULL;
}

// FUN_001D7A60
s32 func_001d7a60(u8 *arg0) {
    func_00122520(1, *(u16 *)(arg0 + 4));
    H_Fade_SetCustomColor(*(u8 *)(arg0 + 0), *(u8 *)(arg0 + 1), *(u8 *)(arg0 + 2));
    return 1;
}

// FUN_001D7B30
s32 func_001d7b30(u16 *arg0) {
    func_00122640(1, *arg0);
    return 1;
}
// FUN_001D7B60
BtlPacket *func_001d7b60(u16 param_1)
{
  int iVar1 = 0;

  iVar1 = (int)func_00194470(0x30B, 2);
  *(code *)(iVar1 + 0x6c) = (code)func_001d7b30;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return (BtlPacket *)iVar1;
}

// FUN_001D7BF0
void func_001d7bf0(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0x309, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d7bb0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
}
/* 680/688 bytes; five resolved relocations and eight zero alignment bytes.
 * Active battle actions receive type-0/1 work from func_0019f5f0 through
 * btlActionSetUnit. Type-2 auxiliary work lives at work+0xA0C instead.
 * This construction contract defines both sides before they are used. */
// FUN_001D7C60
void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4)
{
    u16 sideA;
    u16 sideB;
    u16 mask;
    s32 eff;
    s32 flt;
    s32 mcopy;
    s32 need4;
    s32 needExcl;
    s32 skipDead;
    s32 needAlive;
    u8 *unit;
    u8 *work;
    u8 utype;
    memset(arg1, 0, 0x30);
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x3A) = 0;
    *(u8 *)(arg1 + 0x3C) = 0;
    *(u8 *)(arg1 + 0x3C) |= 1;
    if (arg0 != NULL) {
        switch (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) {
        case 0:
            sideA = 1;
            sideB = 2;
            break;
        case 1:
            sideA = 2;
            sideB = 1;
            break;
        }
    } else {
        sideA = 1;
        sideB = 2;
    }
    mask = 0;
    eff = arg2 & 0xFF;
    if ((eff & 1) != 0) {
        mask |= sideA;
    }
    if ((eff & 2) != 0) {
        mask |= sideB;
    }
    if ((eff & 4) != 0) {
        mask |= 4;
    }
    flt = arg3 & 0xFF;
    if ((flt & 1) != 0) {
        *(u8 **)(arg1 + 0) = arg0;
        *(u16 *)(arg1 + 0x38) = 1;
        return;
    }
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    mcopy = mask & 0xFFFF;
    need4 = mcopy & 4;
    needExcl = flt & 2;
    skipDead = flt & 4;
    needAlive = flt & 8;
    while (unit != NULL) {
        if ((arg0 == NULL || (*(u16 *)(unit + 0x1A) & 8) != 0) &&
            (*(u16 *)(unit + 0x1A) & 1) != 0) {
            work = *(u8 **)(unit + 0x30);
            utype = *(u8 *)(work + 0xA2);
            if (utype == 2 || (*(s32 *)(work + 0x9C) & 8) != 0) {
                if ((mcopy & (1 << utype)) != 0) {
                    if (need4 != 0) {
                        goto store;
                    }
                    if (needExcl == 0 || arg0 != unit) {
                        if (skipDead != 0 || datCalcIsDead(*(u8 **)(work + 0xA64), 0) == 0) {
                            if (needAlive != 0) {
                                if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), 0x100000) == 0) {
                                    goto next;
                                }
                                goto store;
                            } else if (arg4 == 0 ||
                                ((*(s32 *)(*(u8 **)(work + 0xA64) + 0xC) & 0xFFEFFFFF) != 0 &&
                                 datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), arg4) == 0)) {
                                goto store;
                            }
                        }
                    }
                    goto next;
store:
                    *(u8 **)(arg1 + (u32)*(u16 *)(arg1 + 0x38) * 4) = unit;
                    *(u16 *)(arg1 + 0x38) = (u16)(*(u16 *)(arg1 + 0x38) + 1);
                }
            }
        }
next:
        unit = *(u8 **)(unit + 0x450);
    }
}
// FUN_001D7F10
u16 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3)
{
    u32 effect;
    s32 offset;
    u32 bVar4;
    if (arg1 != NULL) {
        offset = (arg2 & 0xFFFF) * 0x28;
        effect = *(u8 *)((u8 *)p4_001d7f10_add(
            offset, (s32)iGpffffb3b8) + 9);
        bVar4 = *(u8 *)((u8 *)(u32)iGpffffb3b8 + offset + 0xA);
        if (arg3 != 0) {
            arg3 = (u8)effect;
            if (((arg3 & 1) != 0) && ((arg3 & 2) == 0)) {
                effect = (u8)(effect & 0xFE);
                effect = (u8)(effect | 2);
            } else if (((arg3 & 2) != 0) && ((arg3 & 1) == 0)) {
                effect = (u8)(effect & 0xFD);
                effect = (u8)(effect | 1);
            }
            if (((u8)bVar4 & 1) != 0) {
                bVar4 = (u8)(bVar4 & 0xFE);
                bVar4 = (u8)(bVar4 | 2);
            }
        }
        func_001d7c60(arg0, arg1, effect, bVar4,
                      *(u16 *)((u8 *)p4_001d7f10_add(
                          (s32)offset, (s32)iGpffffb3b8) + 0xC));
    }
    arg0 = (u8 *)(u32)iGpffffb3b8;
    return (arg0 + (arg2 & 0xFFFF) * 0x28)[8];
}
// FUN_001D8010 NONMATCHING
/* measured: func_001d8010 floor, retail 2992B window (748 instrs), candidate 3000B object (750 instrs, +0.27% size), probe_variants normalized_diff 687 (reloc-masked), 30 retail relocations (D_008C027A/0276, jtbl_00747110, 001d8df0/8bc0, 195850/196040/1ec3d0, 3e42a0/41e0, 457120, 881430, 76449C).
 * Structure: early count<2 return, D_008C027A 0x2000/8000/1000/4000 -> mode 5/4/2/3 with D_008C0276 hasFlag, 1d8df0==1 remap (5/1->3, 4/0->2), switch in object order 4/5,0/1,2/3 sharing bodies via jtbl_00747110, u16 entry idx/chain (Entry[12] at sp+0x90 -> sp+0x120 exactly), three bubble sorts (score/score/chain, descending), chain filter over *(D_0076449C+0x17C) via +0xA68, 1ec3d0 transform for 0/1, shared tail storing *(arg1+0x3A) with +0x3C|1.
 * Phases measured (probe_variants, cwd REPO): v1 separate floats 695, v2 stk[24]+Entry[12] 687 best, v3 s64 mode 699 (regresses, retail daddiu not reached via s64), v4 s32 mode+arg0 reuse+m-inside 687 tie best (banked), v5 u16 counters+dummy s16 687 tie, v6 u16+s16 depth 696 (regresses). (s64)(x<<0x30)>>0x30 tried as s16 depth, regresses.
 * v7 branch-layout (this session): head PROJ divide == -> != with arms swapped (matches the per-entry != site, div-first + bc1t at both), two score stores < -> >= with arms swapped (POS/dist-first like retail). 720 -> 709 edits (-5 head, -6 stores, additive); words 687 -> 689 (+2 from c.olt->c.ole/bc1f at the two store compares, the documented arms-corrected tradeoff). Rejected: nested else-if remap (722, duplicates mode=3), swapped=1/while/bound sorts (727, +9 instrs), s64 mode/hasFlag (722/720/722).
 * Blockers for MATCH: 0/1 dot uses mula.s/madd.s accumulator (plain C gives mul/add, 2-word MAC floor per compiler-floors), mode sets need daddiu (6 words, s64 tried, still addiu), frame retail -0x180 vs candidate -0x1a0 (+32, extra s7/f22/f23 saves from 8 live ints vs 7), integer/FPR coloring (arg1 s0/mode s1/arg0 s2/hasFlag s3/n s4/i s5/unit s6) and stack offsets (entries 0x90, fixed 0x120-0x17C) remain.
 * Guarded floor, production stays INCLUDE_ASM; verify.py src/promoted/code1_001d.c still 91 MATCH/3 ASM, no regression. */
#ifdef SKIP_ASM
void func_001d8010(u8 *arg0, u8 *arg1) {
    extern void btlUnitGetSphereWorldCenter(u8 *a0, f32 *a1);
    extern void func_003e42a0(f32 *dst, f32 *src, u8 *cam);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_001ec3d0(f32 *a0, f32 *a1, f32 *a2, f32 *a3);
    extern s32 func_001d8df0(u8 *a0);
    extern u8 *func_001d8bc0(u8 *a0);
    extern u16 D_008C027A[];
    extern u16 D_008C0276[];
    extern u8 D_00881430[];
    extern u8 *D_0076449C;
    typedef struct {
        u8 *unit;
        u16 idx;
        u16 chain;
        f32 score;
    } Entry;
    Entry entries[12];
    f32 stk[24];
    s32 mode;
    s32 hasFlag;
    s32 i;
    s32 n;
    u16 selected;
#define PROJ ((f32 *)&stk[4])
#define POS ((f32 *)&stk[12])
#define CENTER ((f32 *)&stk[8])
#define BASEXZ ((f32 *)&stk[0])
#define CENTERXZ ((f32 *)&stk[2])
#define CURXZ ((f32 *)&stk[22])
#define OUTXZ ((f32 *)&stk[20])
#define DELTA ((f32 *)&stk[18])
#define DIR ((f32 *)&stk[16])
    if (*(u16 *)(arg1 + 0x38) < 2) {
        return;
    }
    if (D_008C027A[0] & 0x2000) {
        mode = 5;
        hasFlag = (D_008C0276[0] & 0x2000) != 0;
    } else if (D_008C027A[0] & 0x8000) {
        mode = 4;
        hasFlag = (D_008C0276[0] & 0x8000) != 0;
    } else if (D_008C027A[0] & 0x1000) {
        mode = 2;
        hasFlag = (D_008C0276[0] & 0x1000) != 0;
    } else if (D_008C027A[0] & 0x4000) {
        mode = 3;
        hasFlag = (D_008C0276[0] & 0x4000) != 0;
    } else {
        return;
    }
    if ((func_001d8df0(arg1) & 0xFFFF) == 1) {
        s32 m = mode & 0xFFFF;
        if (m == 5 || m == 1) {
            mode = 3;
        } else if (m == 4 || m == 0) {
            mode = 2;
        }
    }
    switch (mode & 0xFFFF) {
    case 4:
    case 5: {
        arg0 = func_00457120() + 0x20;
        func_003e42a0(PROJ, (f32 *)D_00881430, arg0);
        if (PROJ[2] != 0.0f) {
            stk[20] = 640.0f * (PROJ[0] / PROJ[2]);
            stk[21] = 448.0f * (PROJ[1] / PROJ[2]);
        } else {
            stk[20] = 640.0f * PROJ[0];
            stk[21] = 448.0f * PROJ[1];
        }
        n = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            u8 *unit = *(u8 **)(arg1 + ((i & 0xFFFF) * 4));
            u8 *ud = *(u8 **)(unit + 0x30);
            f32 len;
            btlUnitGetSphereWorldCenter(ud, POS);
            func_003e42a0(PROJ, POS, arg0);
            if (PROJ[2] != 0.0f) {
                stk[22] = 640.0f * (PROJ[0] / PROJ[2]);
                stk[23] = 448.0f * (PROJ[1] / PROJ[2]);
            } else {
                stk[20] = 640.0f * PROJ[0];
                stk[21] = 448.0f * PROJ[1];
            }
            DELTA[0] = stk[22] - stk[20];
            DELTA[1] = stk[23] - stk[21];
            len = func_003e41e0(DELTA, DELTA);
            if (0.0f >= DELTA[0]) {
                entries[n & 0xFFFF].score = len;
            } else {
                entries[n & 0xFFFF].score = -len;
            }
            entries[n & 0xFFFF].unit = unit;
            entries[n & 0xFFFF].idx = (u16)(i & 0xFFFF);
            n = (n + 1) & 0xFFFF;
            i = (i + 1) & 0xFFFF;
        }
        {
            s32 swapped;
            s32 nn = n & 0xFFFF;
            do {
                s32 j;
                swapped = 0;
                j = 0;
                while ((j & 0xFFFF) < nn - 1) {
                    s32 jj = j & 0xFFFF;
                    if (entries[jj].score < entries[jj + 1].score) {
                        u8 *tp = entries[jj].unit;
                        u16 ti = entries[jj].idx;
                        f32 ts = entries[jj].score;
                        entries[jj].unit = entries[jj + 1].unit;
                        entries[jj].idx = entries[jj + 1].idx;
                        entries[jj].score = entries[jj + 1].score;
                        entries[jj + 1].unit = tp;
                        entries[jj + 1].idx = ti;
                        entries[jj + 1].score = ts;
                        swapped = 1;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            } while (swapped != 0);
            {
                u8 *curPtr = func_001d8bc0(arg1);
                i = 0;
                while ((i & 0xFFFF) < nn && entries[i & 0xFFFF].unit != curPtr) {
                    i = (i + 1) & 0xFFFF;
                }
                if ((mode & 0xFFFF) == 5) {
                    if ((i + 1) == nn) {
                        if (hasFlag != 0) {
                            selected = entries[0].idx;
                        } else {
                            selected = *(u16 *)(arg1 + 0x3A);
                        }
                    } else {
                        selected = entries[(i + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        if (hasFlag != 0) {
                            selected = entries[(nn - 1) & 0xFFFF].idx;
                        } else {
                            selected = *(u16 *)(arg1 + 0x3A);
                        }
                    } else {
                        selected = entries[(i - 1) & 0xFFFF].idx;
                    }
                }
            }
        }
        break;
    }
    case 0:
    case 1: {
        s32 tmp;
        tmp = func_001d8df0(arg1) & 0xFFFF;
        btlUnitGetSphereWorldCenter(*(u8 **)(arg0 + 0x30), POS);
        func_00196040(tmp, 0, (RwV3d *)CENTER, 0, 0, 1);
        BASEXZ[0] = POS[0];
        BASEXZ[1] = POS[2];
        CENTERXZ[0] = CENTER[0];
        CENTERXZ[1] = CENTER[2];
        DELTA[0] = POS[0] - CENTER[0];
        DELTA[1] = POS[2] - CENTER[2];
        DIR[0] = DELTA[1];
        DIR[1] = -DELTA[0];
        func_003e41e0(DIR, DIR);
        n = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            u8 *unit = *(u8 **)(arg1 + ((i & 0xFFFF) * 4));
            u8 *ud = *(u8 **)(unit + 0x30);
            f32 dist;
            f32 dot;
            btlUnitGetSphereWorldCenter(ud, POS);
            CURXZ[0] = POS[0];
            CURXZ[1] = POS[2];
            dist = func_001ec3d0(BASEXZ, CENTERXZ, CURXZ, OUTXZ);
            DELTA[0] = CURXZ[0] - OUTXZ[0];
            DELTA[1] = CURXZ[1] - OUTXZ[1];
            func_003e41e0(DELTA, DELTA);
            dot = DELTA[1] * DIR[1] + DELTA[0] * DIR[0];
            if (0.0f >= dot) {
                entries[n & 0xFFFF].score = dist;
            } else {
                entries[n & 0xFFFF].score = -dist;
            }
            entries[n & 0xFFFF].unit = unit;
            entries[n & 0xFFFF].idx = (u16)(i & 0xFFFF);
            n = (n + 1) & 0xFFFF;
            i = (i + 1) & 0xFFFF;
        }
        {
            s32 swapped;
            s32 nn = n & 0xFFFF;
            do {
                s32 j;
                swapped = 0;
                j = 0;
                while ((j & 0xFFFF) < nn - 1) {
                    s32 jj = j & 0xFFFF;
                    if (entries[jj].score < entries[jj + 1].score) {
                        u8 *tp = entries[jj].unit;
                        u16 ti = entries[jj].idx;
                        f32 ts = entries[jj].score;
                        entries[jj].unit = entries[jj + 1].unit;
                        entries[jj].idx = entries[jj + 1].idx;
                        entries[jj].score = entries[jj + 1].score;
                        entries[jj + 1].unit = tp;
                        entries[jj + 1].idx = ti;
                        entries[jj + 1].score = ts;
                        swapped = 1;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            } while (swapped != 0);
            {
                u8 *curPtr = func_001d8bc0(arg1);
                i = 0;
                while ((i & 0xFFFF) < nn && entries[i & 0xFFFF].unit != curPtr) {
                    i = (i + 1) & 0xFFFF;
                }
                if ((mode & 0xFFFF) == 1) {
                    if ((i + 1) == nn) {
                        if (hasFlag != 0) {
                            selected = entries[0].idx;
                        } else {
                            selected = *(u16 *)(arg1 + 0x3A);
                        }
                    } else {
                        selected = entries[(i + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        if (hasFlag != 0) {
                            selected = entries[(nn - 1) & 0xFFFF].idx;
                        } else {
                            selected = *(u16 *)(arg1 + 0x3A);
                        }
                    } else {
                        selected = entries[(i - 1) & 0xFFFF].idx;
                    }
                }
            }
        }
        break;
    }
    case 2:
    case 3: {
        n = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            u8 *unit = *(u8 **)(arg1 + ((i & 0xFFFF) * 4));
            if ((*(u16 *)(unit + 0x1A) & 1) != 0) {
                u8 *ud = *(u8 **)(unit + 0x30);
                if (*(u8 *)(ud + 0xA2) == 0) {
                    u16 depth = 0;
                    u8 *node = *(u8 **)(D_0076449C + 0x17C);
                    while (node != 0 && node != ud) {
                        depth = (depth + 1) & 0xFFFF;
                        node = *(u8 **)(node + 0xA68);
                    }
                    entries[n & 0xFFFF].unit = unit;
                    entries[n & 0xFFFF].idx = (u16)(i & 0xFFFF);
                    entries[n & 0xFFFF].chain = depth;
                    n = (n + 1) & 0xFFFF;
                }
            }
            i = (i + 1) & 0xFFFF;
        }
        if ((n & 0xFFFF) == 0) {
            return;
        }
        if ((n & 0xFFFF) >= 2) {
            s32 swapped;
            s32 nn = n & 0xFFFF;
            do {
                s32 j;
                swapped = 0;
                j = 0;
                while ((j & 0xFFFF) < nn - 1) {
                    s32 jj = j & 0xFFFF;
                    if (entries[jj].chain < entries[jj + 1].chain) {
                        u8 *tp = entries[jj].unit;
                        u16 ti = entries[jj].idx;
                        u16 tc = entries[jj].chain;
                        entries[jj].unit = entries[jj + 1].unit;
                        entries[jj].idx = entries[jj + 1].idx;
                        entries[jj].chain = entries[jj + 1].chain;
                        entries[jj + 1].unit = tp;
                        entries[jj + 1].idx = ti;
                        entries[jj + 1].chain = tc;
                        swapped = 1;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            } while (swapped != 0);
        }
        {
            u8 *curPtr = func_001d8bc0(arg1);
            s32 nn = n & 0xFFFF;
            i = 0;
            while ((i & 0xFFFF) < nn && entries[i & 0xFFFF].unit != curPtr) {
                i = (i + 1) & 0xFFFF;
            }
            if ((i & 0xFFFF) == (nn & 0xFFFF) || i == nn) {
                return;
            }
            if ((mode & 0xFFFF) == 2) {
                if ((i + 1) == nn) {
                    if (hasFlag != 0) {
                        selected = entries[0].idx;
                    } else {
                        selected = *(u16 *)(arg1 + 0x3A);
                    }
                } else {
                    selected = entries[(i + 1) & 0xFFFF].idx;
                }
            } else {
                if ((i & 0xFFFF) == 0) {
                    if (hasFlag != 0) {
                        selected = entries[(nn - 1) & 0xFFFF].idx;
                    } else {
                        selected = *(u16 *)(arg1 + 0x3A);
                    }
                } else {
                    selected = entries[(i - 1) & 0xFFFF].idx;
                }
            }
        }
        break;
    }
    }
    if (*(u16 *)(arg1 + 0x3A) != (selected & 0xFFFF)) {
        *(u16 *)(arg1 + 0x3A) = selected;
        *(u8 *)(arg1 + 0x3C) |= 1;
    }
}
#undef PROJ
#undef POS
#undef CENTER
#undef BASEXZ
#undef CENTERXZ
#undef CURXZ
#undef OUTXZ
#undef DELTA
#undef DIR
#else
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8010);
#endif
// FUN_001D8C00
u8 *func_001d8c00(u8 *arg0)
{
    u16 flags;
    u8 *data;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            data = *(u8 **)(*(u8 **)(unit + 0x30) + 0xA64);
            if ((data == NULL || datCalcIsDead(data, 0) == 0) &&
                *(s64 *)unit == *(s64 *)(arg0 + 0x30)) {
                return unit;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return NULL;
}
/* Recovered from docs/probe_archive/R1EE_001d8cb0_body.c by swapping the
   two operands of the nearest-target test: retail emits the float
   comparison first (`c.olt.s`, `bc1t`, then `beqz` on the first-entry
   flag), so the source reads `(temp_f0 < var_f20) || (first != 0)`.
   That order reads the best distance before the first iteration has
   written it, which is exactly what retail does; the defensive order
   this floor used to carry - first-entry guard first, to avoid the
   uninitialised read - was the whole residual. */
// FUN_001D8CB0
#pragma push
#pragma opt_loop_invariants on
s32 func_001d8cb0(u8 *arg0, u8 *arg1)
{
    struct BtlUnit;
    struct BtlAction {
        u64 uid;
        u8 unknown08[4];
        u16 currState;
        u16 pendingState;
        u16 oldState;
        u16 pendingStateTimer;
        u16 state;
        u16 unknown16;
        u16 unknown18;
        u16 unknown1a;
        u32 stateTimer;
        u8 unknown20[0x10];
        struct BtlUnit *unit;
    };
    struct DistanceSelection {
        struct BtlAction *entries[12];
        u64 key;
        u16 count;
        u16 selected;
        u8 flags;
    };
    struct RwV3d {
        f32 x;
        f32 y;
        f32 z;
    };
    extern void func_001958f0(struct BtlUnit *unit, struct RwV3d *dst);
    extern f32 func_001ec250(const struct RwV3d *first, const struct RwV3d *second);
    struct RwV3d sp60;
    struct RwV3d sp50;
    f32 temp_f0;
    f32 var_f20;
    struct DistanceSelection *selection = (struct DistanceSelection *)arg1;
    s32 first;
    s32 index;
    selection->selected = 0;
    {
        u64 key;
        u16 key_index;
        key = selection->key;
        if (key != 0) {
            key_index = 0;
            while (key_index < selection->count) {
                if (key == selection->entries[key_index]->uid) {
                    selection->selected = key_index;
                    return 1;
                }
                key_index++;
            }
        }
    }
    if (arg0 == NULL)
        goto return_one;
    first = 1;
    func_001958f0(((struct BtlAction *)arg0)->unit, &sp60);
    index = 0;
    goto distance_test;
distance_loop:
    func_001958f0(selection->entries[index & 0xFFFF]->unit, &sp50);
    temp_f0 = func_001ec250(&sp60, &sp50);
    if ((temp_f0 < var_f20) || (first != 0)) {
        selection->selected = (u16)index;
        var_f20 = temp_f0;
        first = 0;
    }
    index = (index + 1) & 0xFFFF;
distance_test:
    if ((u16)index < selection->count)
        goto distance_loop;
return_one:
    return 1;
}
#pragma pop
// FUN_001D8E50
void func_001d8e50(u8 *arg0, u8 *arg1)
{
    u16 best_value1;
    s16 best_index1;
    u16 best_value2;
    s16 best_index2;
    s32 index;
    u32 offset;
    s32 target;
    u16 value;
    u16 alternate;
    u8 *work;

    if (*(u16 *)(arg1 + 0x38) <= 1)
        return;
    switch (*(u16 *)(arg0 + 0x6C)) {
    case 2:
        goto mode_valid;
    default:
        switch (*(u16 *)(arg0 + 0x6C)) {
        case 3:
            goto mode_valid;
        default:
            switch (*(u16 *)(arg0 + 0x6C)) {
            case 1:
                goto mode_valid;
            default:
                goto mode_done;
            }
        }
    }

mode_valid:

        offset = (u32)*(u16 *)(arg0 + 0x6E) * 0x28;
        {
            u8 *entry;
            entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
            if (entry[8] != 0)
                return;

            if (entry[0x18] == 2) {
            target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + 0x1C) + offset);
            if (target != 0) {
                index = 0;
                while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                    if (*(u8 **)(arg0 + 0x30) ==
                        *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30) &&
                        datCalcChkBadStatus(
                            (s32)*(u8 **)(*(u8 **)(*(u8 **)(arg1 +
                                                          (u32)(u16)index * 4) +
                                                     0x30) +
                                     0xA64),
                            target) != 0) {
                        *(u16 *)(arg1 + 0x3A) = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }

                index = 0;
                while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                    if (datCalcChkBadStatus(
                            (s32)*(u8 **)(*(u8 **)(*(u8 **)(arg1 +
                                                          (u32)(u16)index * 4) +
                                                     0x30) +
                                     0xA64),
                            target) != 0) {
                        *(u16 *)(arg1 + 0x3A) = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }
            }
        }
        }

        target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + 0x20) + offset);
        if (target != 0) {
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                if (func_002340c0(
                        *(s32 *)(*(u8 **)(*(u8 **)(arg1 +
                                                      (u32)(u16)index * 4) +
                                         0x30) +
                                 0xA64),
                        target) == 0) {
                    *(u16 *)(arg1 + 0x3A) = (u16)index;
                    return;
                }
                index = (index + 1) & 0xFFFF;
            }
        }

        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
        case 15:
            goto mode1_select;
        default:
            switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
            case 11:
                goto mode1_select;
            default:
                switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                case 9:
                    goto mode1_select;
                default:
                    switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                    case 5:
                        goto mode1_select;
                    default:
                        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                        case 2:
                            goto mode1_select;
                        default:
                            goto mode2_check;
                        }
                    }
                }
            }
        }

mode1_select:
        {
            best_value1 = 0xFFFF;
            best_index1 = -1;
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                work = *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30);
                value = datCalcGetHp(*(u8 **)(work + 0xA64));
                alternate = func_00231f80(*(u8 **)(work + 0xA64));
                if (value < best_value1 && value < alternate) {
                    best_value1 = value;
                    best_index1 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index1 != -1) {
                *(u16 *)(arg1 + 0x3A) = (u16)best_index1;
                return;
            }
        }

mode2_check:
        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
        case 15:
            goto mode2_select;
        default:
            switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
            case 11:
                goto mode2_select;
            default:
                switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                case 9:
                    goto mode2_select;
                default:
                    switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                    case 5:
                        goto mode2_select;
                    default:
                        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                        case 2:
                            goto mode2_select;
                        default:
                            goto mode_done;
                        }
                    }
                }
            }
        }

mode2_select:
        {
            best_value2 = 0xFFFF;
            best_index2 = -1;
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                work = *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30);
                value = datCalcGetSp(*(u8 **)(work + 0xA64));
                alternate = func_00232290(*(u8 **)(work + 0xA64));
                if (value < best_value2 && value < alternate) {
                    best_value2 = value;
                    best_index2 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index2 != -1)
                *(u16 *)(arg1 + 0x3A) = (u16)best_index2;
        }

mode_done:
    return;
}
// FUN_001D9280
u8 *func_001d9280(s32 arg0, s32 arg1, s32 arg2) {
    s32 work_flags;
    u8 *unit;
    u8 *work;
    u16 flags;
    u32 mask;
    u32 filter;
    s32 id;

    work_flags = arg2;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    mask = (u16)arg1;
    filter = work_flags & 0x80000;
    id = (u16)arg0;
    goto next_branch;
loop:
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(work + 0xA2))) != 0) {
                if (filter != 0) {
                    if (datCalcIsDead(*(u8 **)(work + 0xA64), 0) != 0) {
                        goto next;
                    }
                }
                if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), work_flags) != 0) {
                    goto next;
                }
                if (*(u16 *)(work + 0xA4) == id) {
                    return unit;
                }
            }
        }
    }
next:
    unit = *(u8 **)(unit + 0x450);
next_branch:
    if (unit != NULL) {
        goto loop;
    }
    return NULL;
}
// FUN_001D9390
int func_001d9390(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 (*arg5)(u8 *, s32), u8 **arg6) {
    struct Frame {
        u8 *entries[14];
        u16 count;
        u16 unknown3a;
        u8 flags;
    } frame;
    u8 *unit;
    s32 index;
    s32 matches;
    u8 *work;
    u16 flags;

    func_001d7c60((u8 *)arg0, (u8 *)&frame, arg3, 0, 0);
    matches = 0;
    index = 0;
    goto test;
loop:
    unit = frame.entries[(u16)index];
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), arg2) == 0) {
                if (arg5(unit, arg1) != arg4) {
                    if (arg6 != NULL) {
                        arg6[(u16)matches] = unit;
                    }
                    matches = (matches + 1) & 0xFFFF;
                }
            }
        }
    }
    index = (index + 1) & 0xFFFF;
test:
    if ((u16)index < frame.count) {
        goto loop;
    }
    return matches;
}
// FUN_001D94D0
int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6)
{
    u8 *unit;
    u8 *work;
    u16 flags;
    s32 type_mask;
    s32 options;
    s32 option_one;
    s32 option_two;
    s32 option_four_eight;
    s32 option_four_value;
    s32 ignore_dead_value;
    s32 status;
    s32 effects;

    extern s32 func_0023d6e0(s16 arg0);
    extern s8 func_00233a90(u8 *arg0, s32 arg1);
    extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
    extern s32 func_0010f420(u16 arg0, u16 arg1);

    (void)param_1;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    type_mask = (u16)param_3;
    options = (u16)param_5;
    option_one = options & 1;
    option_two = options & 2;
    option_four_eight = options & 0xC;
    option_four_value = options & 4;
    ignore_dead_value = param_4 & 0x80000;
    goto test;

loop:
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0 && (flags & 8) != 0) {
        work = *(u8 **)(unit + 0x30);
        if ((type_mask & (1 << *(u8 *)(work + 0xA2))) != 0) {
            if (options == 0)
                goto check_general;
            if (option_one != 0 &&
                datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), 0x100000) == 0)
                goto next;
            if (option_two != 0) {
                status = func_0023d6e0((s16)param_2);
                if ((status & 0xE0001) == 0) {
                    if ((status & 2) != 0) {
                        effects = func_00233a90(*(u8 **)(work + 0xA64), 0x10);
                        if (effects > 0)
                            goto next;
                    } else if ((status & 0x40) == 0) {
                        effects = func_00233a90(*(u8 **)(work + 0xA64), 0x11);
                        if (effects > 0)
                            goto next;
                    }
                }
            }
            if (option_four_eight != 0 &&
                *(u8 *)(work + 0xA2) == 1 &&
                func_001f9ce0(unit, (s16)param_2) == 0 &&
                func_0010f420(*(u16 *)(work + 0xA4), (u16)param_2) == 0) {
                if (option_four_value != 0)
                    goto next;
                return 1;
            }
check_general:
            if ((ignore_dead_value == 0 ||
                 datCalcIsDead(*(u8 **)(work + 0xA64), 0) == 0) &&
                datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), param_4) == 0 &&
                param_6(unit, param_2) != 0)
                return 1;
        }
    }
next:
    unit = *(u8 **)(unit + 0x450);
test:
    if (unit != NULL)
        goto loop;
    return 0;
}
// FUN_001D9740
s32 btlCond_MYHP(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D97B0
s32 func_001d97b0(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return !((u32)uVar1 * 100 < (uVar2 & 0xFFFF) * arg1);
}

// FUN_001D9820
s32 btlCond_MYMP(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 0xA);
    uVar2 = func_00232290(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D9890
void btlCond_FRHP(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHP);
}

// FUN_001D98E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHP(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHP);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D9940
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHP_O(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001d97b0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D99A0
s32 btlCond_MYLV_O(u8 *arg0, u32 arg1)
{
    return (u32)(func_00231e20(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) & 0xFF) >= arg1;
}
// FUN_001D9B60
s32 btlCond_MYBAD(u8 *task, s32 mask) {
    return datCalcChkBadStatus(*(s32 *)(*(u8 **)(task + 0x30) + 0xA64), (u32)mask);
}
// FUN_001D9B90
void btlCond_FRBAD(u8 *arg0, u32 arg1)
{
    u32 mask;

    mask = (1 << *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        func_001d94d0((int)arg0, arg1, mask, 0, 0, btlCond_MYBAD);
    } else {
        func_001d94d0((int)arg0, arg1, mask, 0x80000, 0, btlCond_MYBAD);
    }
}

/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
// FUN_001D9C00
#pragma opt_rebuildconditionals off
void btlCond_ENBAD(u8 *arg0, u32 arg1)
{
    u32 shift;
    u32 temp_3;

    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero_1;
        shift = 1;
        goto done_1;
    nonzero_1:
        shift = 0;
    done_1:
        ;
    }
    temp_3 = shift & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        func_001d94d0((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0, 0, btlCond_MYBAD);
    } else {
        func_001d94d0((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0x80000, 0, btlCond_MYBAD);
    }
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9CA0
s32 btlCond_ENBAD_ALL(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 mode;
    s32 mask;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    mode = 1;
    goto done;
nonzero:
    mode = 0;
done:
    ;
    mask = (1 << (mode & 0xFFFF)) & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(temp + 0xA2))) != 0 &&
                datCalcIsDead(*(u8 **)(temp + 0xA64), 0) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), arg1) == 0) {
                break;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    if (unit != NULL)
        goto found;
    return 1;
found:
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9ca0. */
#pragma opt_rebuildconditionals on
// FUN_001D9DB0
s32 btlCond_FRID(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    *(u16 *)(temp + 0xA4) == arg1) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9E80
s32 btlCond_ENID(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                *(u16 *)(temp + 0xA4) == arg1) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9e80. */
#pragma opt_rebuildconditionals on
// FUN_001D9F60
s32 btlCond_FRHOJO(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    func_002340c0(*(s32 *)(temp + 0xA64), arg1) != 0) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DA040
s32 btlCond_ENHOJO(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                func_002340c0(*(s32 *)(temp + 0xA64), arg1) != 0) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001da040. */
#pragma opt_rebuildconditionals on
// FUN_001DA130
s32 btlCond_ESCAPE(u8 *arg0) {
    s32 r;

    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180010) != 0) {
        r = 0;
    } else {
        r = (*(s32 *)(iGpffffb414 + *(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18) & 1) != 0;
    }
    return r;
}

// FUN_001DA1A0
s32 btlCond_SUMMON(void)
{
    return 0;
}

// FUN_001DA1B0
s32 btlCond_SENSEI(u8 *arg0)
{
    u8 genus;

    if (*(s32 *)(arg0 + 0x20) > 0)
        return 0;
    genus = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (genus) {
    case 0:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 1;
    case 1:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 2;
    default:
        return 0;
    }
}

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x02000000) != 0);
}



// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x04000000) != 0);
}



// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x01000000) != 0);
}



// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x08000000) != 0);
}



// FUN_001DA330
void btlCond_FRHANSYA(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHANSYA);
}

// FUN_001DA380
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHANSYA(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHANSYA);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

// FUN_001DA430
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENKYUSYU(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYKYUSYU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA490
void btlCond_FRMUKOU(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYMUKOU);
}
// FUN_001DA4E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENMUKOU(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYMUKOU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA540
void btlCond_FRWEAK(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYWEAK);
}
// FUN_001DA590
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENWEAK(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYWEAK);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA5F0
s32 btlCond_MYUSEATTR(u8 *arg0, s32 arg1)
{
    return p4_001da5f0_xor((s16)func_0023d8e0(
        *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64),
        *(u16 *)(arg0 + 0x7E)), arg1) < 1U;
}
// FUN_001DA640
void btlCond_FRUSEATTR(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
// FUN_001DA690
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENUSEATTR(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
/* Twin port from P3 Battle/btlEffect.c func_002c2510; P4 constants and callees recovered from retail asm. */
// FUN_001DA930
s32 btlCond_MYHREC(u8 *arg0)
{
    s32 data;
    s32 count;
    u16 *skills;
    u16 index;

    data = *(s32 *)(arg0 + 0x30);
    count = (u16)func_0023e130(*(u8 **)(data + 0xA64));
    skills = (u16 *)func_0023e140(*(u32 *)(data + 0xA64));
    index = 0;
    count = (u16)count;
    while (index < count) {
        u16 skillId = skills[index];

        if (skillId != 0 && skillId < 0x1B8 && func_0023df20(skillId) != 0)
            return 1;
        index++;
    }
    return 0;
}
// FUN_001DAA00
void btlCond_FRHANSYA_ST(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYHANSYA);
}
// FUN_001DAA50
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENHANSYA_ST(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYHANSYA);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAAB0
void btlCond_FRKYUSYU_ST(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
// FUN_001DAB00
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENKYUSYU_ST(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAB60
void btlCond_FRMUKOU_ST(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYMUKOU);
}
// FUN_001DABB0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENMUKOU_ST(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYMUKOU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAC10
void btlCond_FRWEAK_ST(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYWEAK);
}
// FUN_001DAC60
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENWEAK_ST(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYWEAK);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DACE0
s32 btlCond_FRALLHP(u8 *arg0, s32 arg1)
{
    extern u16 datCalcGetHp(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    temp_18 = (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            datCalcIsDead(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += datCalcGetHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += func_00231f80(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Opening state measured: opt_rebuildconditionals off is required for this mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DAE00
s32 btlCond_ENALLHP(u8 *arg0, s32 arg1)
{
    extern u16 datCalcGetHp(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        temp_18 = 1;
        goto done;
    nonzero:
        temp_18 = 0;
    done:
        ;
    }
    temp_18 = (1 << (temp_18 & 0xFFFF)) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            datCalcIsDead(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += datCalcGetHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += func_00231f80(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Closing state measured: restore opt_rebuildconditionals on after this function. */
#pragma opt_rebuildconditionals on
