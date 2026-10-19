#include "btl_effect_internal.h"
#include "btl_action_internal.h"
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
/* Formation offsets are signed XYZ halfwords; slot arithmetic advances by six bytes. */
typedef struct BtlUnitSlotOffset {
    s16 x, y, z;
} BtlUnitSlotOffset;

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

extern void (*D_00887300[])(s32 arg0, s32 arg1);
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
extern void btlUnitGetGridSphereCenter(void *arg0, void *arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 btlUnitGetEntryPosition(u8 *arg0, f32 *arg1, s32 arg2);
extern u8 *btlActionGetActiveOrQueueFront(void);
extern void btlTargetBlendVectors(void *arg0, void *arg1, void *arg2);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void btlUnitGetSphereCenterTowardTarget(void *arg0, void *arg1, void *arg2);
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
static inline u8 *btlUnitAddPersonaOffset(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}

extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s32 iGpffffb444;

extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00194ff0-00195530 */

/* measured: opt_propagation off is scoped to func_001927c0. */
/* measured: closes opt_propagation around func_001927c0. */
/* measured: opt_propagation off is scoped to func_001928c0. */
/* measured: opt_loop_invariants on is scoped to func_001928c0. */
/* measured: closes opt_loop_invariants around func_001928c0. */
/* measured: closes opt_propagation around func_001928c0. */
/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
/* measured: aggregate Vec3 copies and float frame fields reproduce the 500-byte body. */
/* Return the grid anchor and optionally its facing rotation and selected target point. */
/* measured: the remaining action-state halfword changed MATCH when typed; selected-action/unit pointer chains retain their existing callback ABI. */
// FUN_00194FF0
void btlUnitGetAnchorPose(u8 *unit, u8 *outPosition, f32 *outRotation, f32 *outTarget)
{
    struct Work {
        f32 vec[3];
        u8 gap[4];
        f32 x;
        f32 y;
        f32 z;
    } frame;
    s16 gridZ;
    s32 entryOffset;
    u8 genus;
    u8 *activeAction;
    u8 *activeUnit;

    frame.x = (f32)(s32)((((BtlUnit *)unit)->unk_94 * 0x19) - 0x6D6);
    frame.y = 0;
    gridZ = ((BtlUnit *)unit)->unk_96;
    entryOffset = gridZ * 5;
    frame.z = (f32)((gridZ * 0x19) - 0x6D6);
    if (outPosition != NULL) {
        *(P4_95730_Vec3 *)outPosition = *(P4_95730_Vec3 *)&frame.x;
    }
    if ((outTarget != NULL) || (outRotation != NULL)) {
        genus = ((BtlUnit *)unit)->genus;
        switch (genus) {
        case 0:
            if (datCalcChkBadStatus((s32)((BtlUnit *)unit)->datUnit, 0x100) == 0) {
                btlUnitGetGroupBounds(2, 1, (RwV3d *)frame.vec, NULL, NULL, 1);
            } else {
                btlUnitGetGridSphereCenter(
                    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                    frame.vec);
            }
            break;
        case 1:
            if (btlUnitGetEntryPosition(unit, frame.vec, entryOffset) != 1) {
                activeAction = btlActionGetActiveOrQueueFront();
                if ((activeAction != NULL) &&
                    ((activeUnit = (u8 *)((BtlAction *)activeAction)->unit),
                     (((BtlUnit *)activeUnit)->genus == 0)) &&
                    ((((BtlAction *)activeAction)->flags & 4) == 0 ||
                     *(u16 *)(activeAction + 0x16) != 0x1E)) {
                    btlUnitGetGridSphereCenter(activeUnit, frame.vec);
                } else {
                    btlUnitGetGridSphereCenter(
                        *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                        frame.vec);
                }
            }
            break;
        }
        if (outTarget != NULL) {
            *(P4_95730_Vec3 *)outTarget = *(P4_95730_Vec3 *)frame.vec;
        }
        if (outRotation != NULL) {
            btlTargetBlendVectors(outRotation, &frame.x, frame.vec);
        }
    }
}

/* measured: object 832B/window 832B, nd 0. slot is an s32 param copied to a u8
   temporary before each use (retail keeps the raw value in $s0 and re-masks);
   `kind` is a plain u16 local (a redundant & 0xFFFF becomes a hoisted $s
   constant under propagation off) and outTarget goes through a u16 temporary. The
   table addresses: `(u8 *)off + (s32)((u8 *)(kind * 0x58) + (s32)iGpffffb3e0)`
   for the deferred GP load with addu kind,base / off,sum; and a `tbl = gp`
   local plus `(u8 *)(kind * 0x58) + (s32)tbl` where retail loads the base first.
   `dist = call; dist += 50.0f` gives the result-first add.s; stack arrays in
   declaration order tmp, pos, scaled, origin, rot. */
/* Compute a slot position/rotation from character offsets or a motion-distance approach to the target. */
/* Raw quaternion copies preserve the original aggregate type; the final signed formation halfword keeps offset-first integer address construction. */
// FUN_001951F0
/* measured: opt_propagation off keeps the per-use u8/u16 conversions and the
   named scaled index (`slotOffset = slotIndex * 6`) from being folded into one address. */
/* measured: func_001951f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void btlUnitGetSlotPose(u8 *unit, u8 *anchorUnit, u8 *targetUnit, s32 motion, f32 *outPosition, f32 *outRotation, s32 slot)
{
    f32 direction[3];
    f32 position[3];
    f32 scaled[3];
    f32 origin[3];
    f32 rotation[4];
    u16 characterId;
    u8 *entry;
    f32 distance;
    f32 forwardX;
    f32 forwardZ;
    f32 side;
    u8 slotIndex;
    f32 offsetX;
    f32 offsetZ;
    f32 sideOffset;
    u8 *slotTable;
    s32 slotOffset;
    u16 motionId;

    characterId = ((BtlUnit *)unit)->charId;
    slotIndex = slot;
    if (slotIndex == 2) {
        if (((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x01000000) {
            slot = 0;
        }
    }
    slotIndex = slot;
    if (slotIndex != 2) {
        if (outRotation != NULL) {
            *(P4_95730_Vec4 *)outRotation = *(P4_95730_Vec4 *)(anchorUnit + 0x1C);
        }
        if (outPosition != NULL) {
            btlUnitGetSphereWorldCenter(anchorUnit, origin);
            origin[1] = 0.0f;
            slotIndex = slot;
            slotOffset = slotIndex * 6;
            entry = (u8 *)slotOffset + (s32)((u8 *)(characterId * 0x58) + (s32)iGpffffb3e0);
            position[0] = ((BtlUnitSlotOffset *)(entry + 0xC))->x;
            position[1] = ((BtlUnitSlotOffset *)(entry + 0xC))->y;
            position[2] = ((BtlUnitSlotOffset *)(entry + 0xC))->z;
            scaled[0] = position[0] * ((BtlUnit *)unit)->scale;
            scaled[1] = position[1] * ((BtlUnit *)unit)->scale;
            scaled[2] = position[2] * ((BtlUnit *)unit)->scale;
            RtQuatTransformVectors(position, scaled, 1, anchorUnit + 0x1C);
            outPosition[0] = position[0] + origin[0];
            outPosition[1] = position[1] + origin[1];
            outPosition[2] = position[2] + origin[2];
        }
    } else {
        btlUnitGetSphereCenterTowardTarget(targetUnit, anchorUnit, origin);
        motionId = motion;
        distance = btlUnitGetMotionDistance(unit, targetUnit, motionId);
        distance = distance + 50.0f;
        btlTargetBlendVectors(rotation, anchorUnit + 4, origin);
        RtQuatTransformVectors(direction, &D_0060A100, 1, rotation);
        forwardX = direction[0] * distance;
        forwardZ = direction[2] * distance;
        slotTable = iGpffffb3e0;
        sideOffset = *(s16 *)((u8 *)(characterId * 0x58) + (s32)slotTable + 0xC);
        side = sideOffset * ((BtlUnit *)unit)->scale;
        RtQuatTransformVectors(direction, &D_0060A0D0, 1, rotation);
        direction[0] *= side;
        direction[1] *= side;
        direction[2] *= side;
        offsetX = forwardX + direction[0];
        offsetZ = forwardZ + direction[2];
        position[0] = origin[0] + offsetX;
        position[2] = origin[2] + offsetZ;
        position[1] = 0.0f;
        if (outPosition != NULL) {
            *(P4_95730_Vec3 *)outPosition = *(P4_95730_Vec3 *)position;
        }
        if (outRotation != NULL) {
            btlTargetBlendVectors(outRotation, position, origin);
        }
    }
}

/* measured: closes the propagation bracket; the file default is on. */
/* measured: func_00195530 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* Build the child-unit alpha color from its character-table entry, otherwise return -1. */
// FUN_00195530
s32 btlUnitGetPersonaAlphaColor(u8 *context) {
    u8 *e;

    if (context[0xA2] != 2) {
        return -1;
    }
    e = btlUnitAddPersonaOffset(((BtlUnit *)context)->charId * 0x58, iGpffffb3e0);
    return (e[0x56] << 24) | 0xFFFFFF;
}

