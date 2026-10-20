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
#include "btl_battle_internal.h"
#include "btl_effect_internal.h"
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

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;

extern s64 scrGetParamInt(s32 paramIdx);
extern u8 *datUnitGetRecord(s16 unitId);
extern void datCalcSetUnitClass(u8 *unit, s16 tactic);
extern s32 datCalcUnitClass(u8 *unit);
extern void scrSetReturnInt(s32 retVal);

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

extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00193630-00193730 */

/* measured: opt_propagation off is scoped to func_001927c0. */
/* measured: closes opt_propagation around func_001927c0. */
/* measured: opt_propagation off is scoped to func_001928c0. */
/* measured: opt_loop_invariants on is scoped to func_001928c0. */
/* measured: closes opt_loop_invariants around func_001928c0. */
/* measured: closes opt_propagation around func_001928c0. */
/* Set a character record class from the two AI script integer parameters. */
// FUN_00193630
s32 btlScriptSetUnitClass(void) {
    s64 characterId;
    s64 unitClass;

    characterId = scrGetParamInt(0);
    unitClass = scrGetParamInt(1);
    datCalcSetUnitClass(datUnitGetRecord((s16)characterId), (s16)unitClass);
    return 1;
}

/* Return the selected character record class to the AI script. */
// FUN_001936A0
s32 btlScriptGetUnitClass(void) {
    scrSetReturnInt((s16)datCalcUnitClass(datUnitGetRecord((s16)scrGetParamInt(0))));
    return 1;
}

/* Return the owning task handle, or zero when no battle runtime exists. */
// FUN_00193700
s32 btlIsRunning(void) {
    s32 result;

    if (iGpffffb3ac != NULL) {
        result = ((BtlBattleState *)iGpffffb3ac)->cutinTaskParent;
    } else {
        result = 0;
    }
    return result;
}

// FUN_00193730
void btlSetFreeUnitsOnTeardown(void) {
    ((BtlBattleState *)D_0076449C)->flags |= BTL_FLAG_FREE_UNITS;
}

