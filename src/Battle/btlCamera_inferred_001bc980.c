#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_camera_sequence_internal.h"

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void btlUnitSetFlags(u8 *arg0, s32 arg1);
extern void btlUnitClearFlags(u8 *arg0, s32 arg1);
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern u8 *btlPacketAlloc(s32 size, s32 align);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 iGpffffa0b8;
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void btlCameraSetState(s32 state, BtlAction *action, u32 param_3);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern void btlCameraCopyPose(f32 *arg0, f32 *arg1);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern u32 btlMainCurveAppendKeyframe(u16 *arg0, f32 *arg1, f32 *arg2);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern s32 func_00457120(void);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void btlCameraUpdateUnitInRangeFlags(void);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;


void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);




#pragma push
#pragma pop

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001bc980-001bd530 */

extern s32 btlActionGetQueueSecond(void);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0);
static inline u8 *cameraVisibilityTarget(u8 *action, u16 index)
{
    return *(u8 **)(action + index * 4 + 0x38);
}
struct RwV3d;
/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_001BC980
s32 btlCameraPlayPoseSequence(u8 *arg0)
{
    struct C980Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct C980Frame {
        f32 v30[4];
        u8 gap40[0x10];
        f32 v50[3];
        f32 v5C[4];
        f32 v6C[3];
        f32 v78[4];
        u8 tail[8];
    } frame;
    s32 temp_17;
    u8 *temp_3;
    u8 *temp_3_2;

    btlCameraSetState(1, *(BtlAction **)(arg0 + 0), 1);
    if (*(s32 *)(arg0 + 0x40) != 0) {
        btlCameraCopyPose(frame.v50, (f32 *)(D_0076449C + 0xC0));
    } else {
        btlCameraLookAtQuat(frame.v5C, arg0 + 4, arg0 + 0x10, D_0060A0E0);
        *(struct C980Vec3 *)frame.v50 =
            *(struct C980Vec3 *)(arg0 + 4);
    }
    btlCameraLookAtQuat(frame.v78, arg0 + 0x1C, arg0 + 0x28, D_0060A0E0);
    *(struct C980Vec3 *)frame.v6C =
        *(struct C980Vec3 *)(arg0 + 0x1C);
    temp_3 = D_0076449C;
    temp_17 = (s32)(temp_3 + 0x24);
    *(u16 *)(temp_3 + 0x24) = 1;
    *(s16 *)(temp_3 + 0x98) = 0;
    *(s16 *)(temp_3 + 0x9A) = 0;
    *(s16 *)(temp_3 + 0x9C) = 0;
    *(s32 *)(temp_3 + 0xA4) = 0;
    *(s32 *)(temp_3 + 0xA0) = 0;
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v50, frame.v5C);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff82f8);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff80c8);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v30, frame.v30 + 3);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v6C, frame.v78);
    temp_3_2 = D_0076449C;
    *(f32 *)(temp_3_2 + 0xA8) =
        (60.0f * (2.0f * *(f32 *)(arg0 + 0x3C))) / 2.0f;
    *(s32 *)(temp_3_2 + 0xB8) = 0x3F000000;
    *(u16 *)(temp_3_2 + 0x24) &= 0xFFF5;
    *(u16 *)(temp_3_2 + 0x24) |= 4;
    return 1;
}

// FUN_001BCB50
u8 *btlCameraCreatePoseSequencePacket(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0,
                  u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2)
{
    struct Bcb50Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_2;
    u8 *temp_4;

    temp_2 = (u8 *)(btlPacketAlloc(0x201, 0x44));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) =
        (s32 (*)(u8 *))((s32 (**)(u8 *))(btlCameraPlayPoseSequence));
    temp_4 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_4 + 0) = arg0;
    *(f32 *)(temp_4 + 0x3C) = fparg2;
    if ((arg1 != NULL) && (arg2 != NULL)) {
        *(struct Bcb50Vec3 *)(temp_4 + 4) =
            *(struct Bcb50Vec3 *)arg1;
        *(struct Bcb50Vec3 *)(temp_4 + 0x10) =
            *(struct Bcb50Vec3 *)arg2;
        *(s32 *)(temp_4 + 0x40) = 0;
    } else {
        *(s32 *)(temp_4 + 0x40) = 1;
    }
    *(struct Bcb50Vec3 *)(temp_4 + 0x1C) =
        *(struct Bcb50Vec3 *)arg3;
    *(struct Bcb50Vec3 *)(temp_4 + 0x28) =
        *(struct Bcb50Vec3 *)arg4;
    *(f32 *)(temp_4 + 0x34) = fparg0;
    *(f32 *)(temp_4 + 0x38) = fparg1;
    return temp_2;
}

// FUN_001BCC80
s32 btlCameraRunPacketCommand(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}

// FUN_001BCCC0
u8 *btlCameraCreatePacketCommand(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)(btlPacketAlloc(0x202, 0x10));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) = (s32 (*)(u8 *))((s32 (**)(u8 *))(btlCameraRunPacketCommand));
    temp_3 = (u8 *)(*(u8 **)(temp_2 + 0x78));
    *(s32 *)(temp_3 + 0) = arg0;
    *(s16 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = arg2;
    *(s32 *)(temp_3 + 0xC) = arg3;
    return temp_2;
}

#pragma push
/* measured: btlCameraSetupActionGeometry MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001BCD40
void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode)
{
    extern void btlUnitSetFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitClearFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, struct RwV3d *out);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
    struct {
        f32 first[2];
        f32 second[2];
        f32 point[2];
        f32 closest[2];
        f32 center[3];
    } geometry;
    u8 *current;
    u8 *unit;
    u16 targetGroups;
    f32 distance;

    if ((*(u32 *)(D_0076449C + 0x10) & 4) != 0)
        return;

    if (first != NULL && second != NULL) {
        geometry.first[0] = ((f32 *)first)[0];
        geometry.first[1] = ((f32 *)first)[2];
        geometry.second[0] = second[0];
        geometry.second[1] = second[2];
    } else {
        radius = 0.0f;
    }

    targetGroups = 0;
    if ((mode & 0x10) != 0) {
        s32 index;
        index = 0;
        while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
            targetGroups |= (u16)(1u << *(u8 *)(*(u8 **)(
                cameraVisibilityTarget(action, index) + 0x30) + 0xA2));
            index = (index + 1) & 0xFFFF;
        }
    }

    for (current = *(u8 **)(D_0076449C + 0x174); current != NULL;
         current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0)
            continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(u32 *)(unit + 0x9C) & 8) == 0)
            continue;

        if ((mode & 0x20) != 0 && current != action) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if ((mode & 0x100) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            if ((mode & 0x400) != 0) btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (current == *(u8 **)(D_0076449C + 0x170) && (mode & 4) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (action != NULL) {
            if (current == action && (mode & 1) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((targetGroups & (1u << *(u8 *)(unit + 0xA2))) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 0x800) != 0 && current == (u8 *)(uintptr_t)btlActionGetQueueSecond()) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 2) != 0) {
                s32 index;
                index = 0;
                while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
                    if (current == cameraVisibilityTarget(action, index)) {
                        btlUnitClearFlags((BtlUnit *)unit, 2);
                        btlUnitSetFlags((BtlUnit *)unit, 4);
                        if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                        break;
                    }
                    index = (index + 1) & 0xFFFF;
                }
                if ((index & 0xFFFF) != *(u16 *)(action + 0x6A) ||
                    current == *(u8 **)(action + 0x88))
                    continue;
            }
            if (*(u8 *)(unit + 0xA2) == *(u8 *)(*(u8 **)(action + 0x30) + 0xA2) &&
                (mode & 8) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
        }

        if (first != NULL && second != NULL) {
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, (struct RwV3d *)geometry.center);
            geometry.point[0] = geometry.center[0];
            geometry.point[1] = geometry.center[2];
            distance = btlTargetAngleBetween((u8 *)geometry.first, (u8 *)geometry.second,
                                     (u8 *)geometry.point, (u8 *)geometry.closest);
            distance = 0.0f + distance - *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
            if (((geometry.first[0] < geometry.closest[0] ||
                  !(geometry.second[0] <= geometry.closest[0])) &&
                 (!(geometry.first[0] <= geometry.closest[0]) ||
                  geometry.second[0] < geometry.closest[0])) ||
                ((geometry.first[1] < geometry.closest[1] ||
                  !(geometry.second[1] <= geometry.closest[1])) &&
                 (!(geometry.first[1] <= geometry.closest[1]) ||
                  geometry.second[1] < geometry.closest[1])))
                continue;
        } else {
            distance = 0.0f;
        }
        if (distance <= radius) {
            btlUnitSetFlags((BtlUnit *)unit, 2);
            if ((mode & 0x80) == 0) *(u8 *)(unit + 0x37) = 0;
            if ((mode & 0x200) != 0) btlUnitClearFlags((BtlUnit *)unit, 4);
        }
    }
}

#pragma pop
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
/* measured: btlCameraClearAllUnitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_001BD300
void btlCameraClearAllUnitFlags(void)
{
    s32 var_16;
    s32 index;
    u8 *var_17;

    var_16 = 0;
    goto outer_check;
outer_body:
    index = var_16 & 0xFFFF;
    var_17 = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    btlUnitClearFlags(var_17, 0xF);
    var_17 = *(u8 **)(var_17 + 0xA6C);
inner_check:
    if (var_17 != NULL) goto inner_body;
    var_16 = (var_16 + 1) & 0xFFFF;
outer_check:
    if ((var_16 & 0xFFFF) < 2) goto outer_body;
}

/* measured: closes opt_common_subs for the following translation-unit code. */
/* measured: closes opt_propagation for the following translation-unit code. */
/* measured: opt_common_subs off preserves the retail per-use masked index. */
// FUN_001BD390
void btlCameraUpdateUnitInRangeFlags(void)
{
    extern void btlUnitSetFlags();
    extern s32 func_00243d80(u8 *arg0);
    extern f32 RwV3dLength(f32 *arg0);
    u8 *current;
    s32 counter;
    u8 *base;
    s32 index;
    s32 ability;
    f32 values[3];
    f32 delta[3];

    base = *(u8 **)(((u8 *)func_00457120()) + 4) + 0x10;
    counter = 0;
    goto outer_check;
outer_body:
    index = counter & 0xFFFF;
    current = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    ability = *(s32 *)(current + 0xA64);
    if ((ability != 0 && func_00243d80((u8 *)ability) != 0) ||
        (*(s32 *)(current + 0x9C) & 8) != 0) {
        btlUnitGetSphereWorldCenter(current, values);
        delta[0] = *(f32 *)(base + 0x30) - values[0];
        delta[1] = *(f32 *)(base + 0x34) - values[1];
        delta[2] = *(f32 *)(base + 0x38) - values[2];
        if (RwV3dLength(delta) <=
            0.0f + 200.0f +
            *(f32 *)(current + 0x90) * *(f32 *)(current + 0x2C)) {
            btlUnitSetFlags(current, 1);
        } else {
            btlUnitClearFlags(current, 1);
        }
    }
    current = *(u8 **)(current + 0xA6C);
inner_check:
    if (current != NULL) goto inner_body;
    counter = (counter + 1) & 0xFFFF;
outer_check:
    if ((counter & 0xFFFF) < 2) goto outer_body;
}

/* measured: restore common-subexpression optimization after btlCameraUpdateUnitInRangeFlags. */
/* measured: btlCameraMarkUnitFramed MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// FUN_001BD4F0
void btlCameraMarkUnitFramed(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}

// FUN_001BD530
void btlCameraClearUnitFramed(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}

