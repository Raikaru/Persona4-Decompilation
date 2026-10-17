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

#include "rw_types_internal.h"
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
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 iGpffffa0b8;
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
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 btlTargetSmoothStep(f32 value, f32 *state);
extern u32 btlCameraSampleKeyframes(u8 *arg0, f32 *arg1, f32 *arg2);
extern u32 btlCameraAdvanceKeyframes(u8 *arg0, f32 arg1);
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
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

s32 btlTargetIsSlotAlive(u8 *arg0);





#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001bbf40-001bc330 */

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
// FUN_001BBF40
void btlCameraSetTransitionDuration(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x84) = (f32) ((60.0f * fparg0) / 2.0f);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFD);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFB);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFF7);
}

// FUN_001BBF90
void btlCameraUpdateTransition(u8 *arg0)
{
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f12;
    u16 temp_3;
    u8 *temp_2;

    temp_3 = *(u16 *)arg0;
    if ((temp_3 & 2) != 0) {
        var_f12 =
            btlTargetSmoothStep(1.0f, (f32 *)(arg0 + 0x84)) -
            *(f32 *)(arg0 + 0x80);
    } else if ((temp_3 & 4) != 0) {
        temp_f2 = *(f32 *)(arg0 + 0x94);
        if (temp_f2 < fGpffff8430) {
            temp_f4 = temp_f2 + (1.0f / *(f32 *)(arg0 + 0x84));
            *(f32 *)(arg0 + 0x94) = temp_f4;
            temp_f2 = 0.0f + (-1.0f) +
                      ((-2.0f * temp_f4) * temp_f4) +
                      (4.0f * temp_f4);
            var_f12 =
                (2.0f * (temp_f2 - 0.5f)) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else if ((temp_3 & 8) != 0) {
        if (*(f32 *)(arg0 + 0x88) >
            (0.5f * *(f32 *)(arg0 + 0x84))) {
            var_f12 =
                func_001ba790_mul(btlTargetSmoothStep(1.0f, (f32 *)(arg0 + 0x84)), 2.0f) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else {
        var_f12 = 1.0f / *(f32 *)(arg0 + 0x84);
    }
    *(f32 *)(arg0 + 0x80) =
        *(f32 *)(arg0 + 0x80) + var_f12;
    btlCameraAdvanceKeyframes(arg0, var_f12);
    temp_2 = D_0076449C;
    btlCameraSampleKeyframes(temp_2 + 0x24, (f32 *)(temp_2 + 0xC0),
                  (f32 *)(temp_2 + 0xCC));
}

// FUN_001BC140
s32 btlCameraIsActionBlocked(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0xE0));
    if (temp_16 == NULL) {
        return 0;
    }
    if (datCalcChkBadStatus(*(s32 *)((u8 *)(*(u8 **)(temp_16 + 0x30)) + 0xA64), 0x60) != 0) {
        return 1;
    }
    return (s32)(btlActionAnyTargetSpecialHit(temp_16) != 0);
}

// FUN_001BC1B0
s32 btlCameraIsTargetEligible(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_3;
    BtlSkillFlags *base;
    s32 index;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(*(u8 **)(temp_3 + 0x30) + 0xA0C);
    index = *(u16 *)(temp_3 + 0x6E);
    if ((temp_2 != NULL) &&
        (*(u16 *)(iGpffffb3e0 + (*(u16 *)(temp_2 + 0xA4) * 0x58)) & 1)) {
        return 0;
    }
    base = iGpffffb3bc;
    if ((base[index & 0xFFFF].flags & 0x10) != 0) {
        return 0;
    }
    return 1;
}

// FUN_001BC240
/* measured: opt_propagation off probe for bc240 table-address order. */
s32 btlCameraIsTargetPrioritized(s32 arg0)
{
    s32 result;
    u8 *temp;
    u8 *base;

    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) != 0) {
        result = 1;
        goto done;
    }
    temp = *(u8 **)((u8 *)arg0 + 0xE0);
    arg0 = *(u16 *)(temp + 0x6E);
    temp = *(u8 **)(*(u8 **)(temp + 0x30) + 0xA0C);
    if ((temp != NULL) &&
        ((*(u16 *)(iGpffffb3e0 +
                   (*(u16 *)(temp + 0xA4) * 0x58))) & 1) != 0) {
        result = 0;
        goto check20;
    }
    base = (u8 *)iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x10) != 0) {
        result = 0;
        goto check20;
    }
    result = 1;
check20:
    if (result == 0) {
        goto final_zero;
    }
    base = (u8 *)iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x20) != 0) {
        result = 1;
        goto done;
    }
final_zero:
    result = 0;
done:
    return result;
}

/* measured: close opt_propagation probe for bc240. */
// FUN_001BC330
s32 btlCameraIsOrbitAction(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xE0);
    if (ptr == NULL) {
        return 0;
    }
    if (btlTargetIsSlotAlive(ptr) == 0) {
        return 1;
    }
    return *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6C) == 3;
}

