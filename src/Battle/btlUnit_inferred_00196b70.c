#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "rw_types_internal.h"
typedef RwV3d P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;
typedef struct DatUnit DatUnit;

extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;


extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    btlUnitSetMotion(arg0, arg1, arg2, arg3, arg4);
}
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    scrStartProcedureChecked(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s32 iGpffffb444;

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];



/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00196b70-001973d0 */

extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlPacketStepSide(s32 arg0);
extern void btlTargetResetWork(void *work);
extern s32 btlRouteFindPath(u8 *route, f32 *start, f32 *end, f32 radius);
extern s32 btlRouteBuildArc(u8 *route, const f32 *startXZ, const f32 *endXZ, const f32 *centerXZ);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
// FUN_00196B70
void btlUnitClearMoveFlags(u8 *arg0) {
    *(s32 *)(arg0 + 0xC4) &= ~1;
    *(u16 *)(arg0 + 0xC8) &= ~BTLUNIT_MOVEMENTFLAGS_MOVE;
}

// FUN_00196BA0
void btlUnitClearRotateFlags(u8 *arg0) {
    *(s32 *)(arg0 + 0xC4) &= ~2;
    *(u16 *)(arg0 + 0xC8) &= ~BTLUNIT_MOVEMENTFLAGS_ROTATE;
}

// FUN_00196BD0
f32 btlUnitGetMotionDistance(u8 *unit, u8 *target, u16 motion)
{
    f32 temp_f20;
    f32 temp_f0;
    u8 *table;
    s32 temp_4;

    temp_4 = (s16)btlUnitGetMotionId(unit, motion);
    if (temp_4 < (s32)*(u16 *)(unit + 0x9E4)) {
        table = *(u8 **)(unit + 0x9F8);
        temp_f20 = *(f32 *)(unit + 0x2C) *
                   (f32)*(s16 *)((u8 *)p4_base_add_00194590(
                       temp_4 * 0xA, (s32)(table, table)) + 6);
        temp_f0 = btlUnitGetActionAnchorHeight(unit, target, motion);
        if (!(temp_f0 < 0.0f)) {
            temp_f20 += temp_f0;
            goto add_base_00196bd0;
        }
        temp_f20 += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        temp_f20 += *(f32 *)(target + 0x88) * *(f32 *)(target + 0x2C);
add_base_00196bd0:
        temp_f20 += *(f32 *)(unit + 0x88) *
                    *(f32 *)(unit + 0x2C);
    } else {
        temp_f20 = 0.0f;
    }
    return temp_f20;
}

// FUN_00196CE0
void btlUnitHoldPendingMove(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

/* The vector snapshot preserves all three coordinates before flattening Y.
   Separate vector/pair objects retain their natural stack lifetimes. Native
   proof: 1736 executable bytes, ten resolved calls, 150 unchanged siblings. */
// FUN_00196D00
u32 btlUnitMovePacketUpdate(void *workData)
{
    union MovementVector {
        P4_95730_Vec3 vector;
        f32 values[3];
    } direction;
    union MovementVector flatTarget;
    union MovementVector position;
    f32 routeStart[2];
    f32 routeEnd[2];
    f32 routeCenter[2];
    u8 *arg0;
    u8 *unit;
    u16 state;
    s32 flags;
    u16 work_state;
    s32 mask;
    u8 active;
    u8 *work;
    u16 index;

    arg0 = (u8 *)workData;
    unit = *(u8 **)arg0;
    flags = *(s32 *)(arg0 + 0x10);
    if ((flags & 8) != 0) {
        state = *(u16 *)(arg0 + 0x14);
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                btlUnitGetAnchorPose(unit, (u8 *)position.values, NULL, NULL);
                *(P4_95730_Vec3 *)(arg0 + 4) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 1:
            btlTargetResetWork(unit + 0xEC);
            *(f32 *)(unit + 0xE8) = *(f32 *)(arg0 + 0x1C);
            *(s32 *)(unit + 0xC4) = *(s32 *)(arg0 + 0x10);
            *(f32 *)(unit + 0xCC) = 2.0f * (13.5f * *(f32 *)(arg0 + 0x20));
            if ((*(s32 *)(unit + 0xC4) & 1) == 0) {
                *(f32 *)(unit + 0xEC) = *(f32 *)(unit + 4);
                *(f32 *)(unit + 0xF0) = *(f32 *)(unit + 0xC);
                *(f32 *)(unit + 0xF4) = *(f32 *)(arg0 + 4);
                *(f32 *)(unit + 0xF8) = *(f32 *)(arg0 + 0xC);
                *(u16 *)(unit + 0x4EC) = 2;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                direction.values[0] = *(f32 *)(unit + 4) - *(f32 *)(arg0 + 4);
                direction.values[1] = *(f32 *)(unit + 8) - *(f32 *)(arg0 + 8);
                direction.values[2] = *(f32 *)(unit + 0xC) - *(f32 *)(arg0 + 0xC);
                direction.values[1] = 0.0f;
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                *(f32 *)(unit + 0xDC) = *(f32 *)(arg0 + 4) + direction.values[0];
                *(f32 *)(unit + 0xE0) = *(f32 *)(arg0 + 8) + direction.values[1];
                *(f32 *)(unit + 0xE4) = *(f32 *)(arg0 + 0xC) + direction.values[2];
            } else {
                if (*(f32 *)(arg0 + 0x1C) != 0.0f) {
                    direction.values[0] = *(f32 *)(unit + 4) - *(f32 *)(arg0 + 4);
                    direction.values[1] = *(f32 *)(unit + 8) - *(f32 *)(arg0 + 8);
                    direction.values[2] = *(f32 *)(unit + 0xC) - *(f32 *)(arg0 + 0xC);
                    direction.values[1] = 0.0f;
                    RwV3dNormalize(direction.values, direction.values);
                    direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                    direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                    direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                    position.values[0] = *(f32 *)(arg0 + 4) + direction.values[0];
                    position.values[1] = *(f32 *)(arg0 + 8) + direction.values[1];
                    position.values[2] = *(f32 *)(arg0 + 0xC) + direction.values[2];
                } else {
                    position.vector = *(P4_95730_Vec3 *)(arg0 + 4);
                }
                position.values[1] = *(f32 *)(unit + 8);
                *(P4_95730_Vec3 *)(unit + 4) = position.vector;
                *(s32 *)(unit + 0x98) |= 4;
                *(s32 *)(unit + 0xC4) &= ~1;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) &= 0xFFFE;
                *(u16 *)(unit + 0xC8) &= 0xFFEF;
                *(P4_95730_Vec3 *)(unit + 0xDC) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            goto done;
        case 2:
            work_state = *(u16 *)(unit + 0xC8);
            mask = work_state & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = work_state & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    } else {
        state = *(u16 *)(arg0 + 0x14);
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                btlUnitGetAnchorPose(unit, (u8 *)position.values, NULL, NULL);
                *(P4_95730_Vec3 *)(arg0 + 4) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 1:
            btlTargetResetWork(unit + 0xEC);
            *(f32 *)(unit + 0xE8) = *(f32 *)(arg0 + 0x1C);
            *(s32 *)(unit + 0xC4) = *(s32 *)(arg0 + 0x10);
            *(f32 *)(unit + 0xCC) = 2.0f * (13.5f * *(f32 *)(arg0 + 0x20));
            routeStart[0] = *(f32 *)(unit + 4);
            routeStart[1] = *(f32 *)(unit + 0xC);
            routeEnd[0] = *(f32 *)(arg0 + 4);
            routeEnd[1] = *(f32 *)(arg0 + 0xC);
            if ((*(s32 *)(arg0 + 0x10) & 0x80) == 0) {
                btlRouteFindPath(unit + 0xEC, routeStart, routeEnd, 50.0f);
            } else {
                btlUnitGetGroupBounds(3, 1, &position.vector, NULL, NULL, 1);
                routeCenter[0] = position.values[0];
                routeCenter[1] = position.values[2];
                btlRouteBuildArc(unit + 0xEC, routeStart, routeEnd, routeCenter);
            }
            index = *(u16 *)(unit + 0x4EC);
            if (index == 0) {
                *(P4_95730_Vec3 *)(unit + 0xDC) = *(P4_95730_Vec3 *)(arg0 + 4);
            } else {
                work = (u8 *)p4_base_add_00194590(index * 8, (s32)unit);
                direction.values[0] = *(f32 *)(work + 0xDC);
                direction.values[1] = 0.0f;
                direction.values[2] = *(f32 *)(work + 0xE0);
                flatTarget.vector = *(P4_95730_Vec3 *)(arg0 + 4);
                flatTarget.values[1] = 0.0f;
                direction.values[0] = direction.values[0] - flatTarget.values[0];
                direction.values[1] = direction.values[1] - flatTarget.values[1];
                direction.values[2] = direction.values[2] - flatTarget.values[2];
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                flatTarget.values[0] += direction.values[0];
                flatTarget.values[1] += direction.values[1];
                flatTarget.values[2] += direction.values[2];
                *(P4_95730_Vec3 *)(unit + 0xDC) = flatTarget.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 2:
            work_state = *(u8 *)(unit + 0x4F0);
            if (work_state == 2) {
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
                goto done;
            } else if (work_state == 3) {
                *(f32 *)(unit + 0xEC) = *(f32 *)(unit + 4);
                *(f32 *)(unit + 0xF0) = *(f32 *)(unit + 0xC);
                *(f32 *)(unit + 0xF4) = *(f32 *)(arg0 + 4);
                *(f32 *)(unit + 0xF8) = *(f32 *)(arg0 + 0xC);
                *(u16 *)(unit + 0x4EC) = 2;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
                goto done;
            }
            goto done;
        case 3:
            work_state = *(u16 *)(unit + 0xC8);
            mask = work_state & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = work_state & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    }
done:
    *(s32 *)(arg0 + 0x18) += 1;
    return 0;
}

// FUN_001973D0
void btlUnitReleasePendingMove(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

