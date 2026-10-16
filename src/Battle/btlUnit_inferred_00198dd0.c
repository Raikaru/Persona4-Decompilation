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
#include "btl_unit_internal.h"
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

extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
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
extern s32 datCalcIsLowHp(u8 *arg0);
extern s32 datCalcIsStatusBlocked(s32 arg0);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00198dd0-00198dd0 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
/* Recovered.  Two shapes closed it: the availability flag is an if/else
   (`if (r == 1) flag = 0; else flag = 1;`) rather than `flag = 1` with a
   conditional clear - retail reuses the materialised 1 as both the flag
   value and the comparison constant, and keeps the unreachable clear the
   else arm leaves behind - and the kind test is a `switch` with `case 0:
   case 1:` falling into one body, which emits retail's three-branch chain
   (beq 1, beqz, b default) instead of the inverted two-branch form an
   `||` condition produces.  The case labels are written 0 then 1 because
   the compare chain is emitted in reverse label order. */
// FUN_00198DD0
#pragma push
void btlUnitUpdateStatusMotion(u8 *arg0, u16 arg1)
{
    s16 var_18;
    s64 value;
    u16 var_17;
    u16 var_16;
    s32 same;
    s32 flag;
    s32 r;
    s16 temp;
    extern s32 mdlIsLayerKeyEmpty(u8 *a, u32 b, s16 c);
    extern s32 datCalcChkBadStatus();

    var_18 = 0;
    if (datCalcIsLowHp(*(u8 **)(arg0 + 0xA64)) != 0) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(btlUnitGetMotionId(arg0, 0x12) & 0xFFFF);
            if (mdlLayerHasAnimation(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = mdlIsLayerKeyEmpty(*(u8 **)(arg0 + 0xA00), 0, temp);
                if (r == 1) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x12;
        }
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0xFFFFF) != 0) {
        var_18 = 3;
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100000) != 0) {
        var_18 = 0xA;
    }
    if (datCalcIsStatusBlocked(*(s32 *)(arg0 + 0xA64)) != 0) {
        var_18 = 0x18;
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
        var_18 = 0;
    }
    if ((datCalcIsDead(*(u8 **)(arg0 + 0xA64), 0) != 0) && ((*(s32 *)(arg0 + 0x9C) & 0x20) != 0)) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(btlUnitGetMotionId(arg0, 0x13) & 0xFFFF);
            if (mdlLayerHasAnimation(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = mdlIsLayerKeyEmpty(*(u8 **)(arg0 + 0xA00), 0, temp);
                if (r == 1) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x13;
        }
    }
    value = (s64)var_18;
    if (value != 0x13) {
        var_17 = 1;
        var_16 = *(u16 *)(arg0 + 0x9EE);
    } else {
        var_17 = 2;
        var_16 = 0;
    }
    {
        u8 kind;
        s16 ref;

        kind = *(u8 *)(arg0 + 0xA2);
        switch (kind) {
        case 0:
        case 1:
            if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
                ref = *(s16 *)(arg0 + 0x9DA);
            } else {
                ref = 0;
            }
            same = (s32)(*(s16 *)(arg0 + 0x9EC) == (s16)ref);
            break;
        default:
            same = 0;
            break;
        }
    }
    if ((same != 0) && ((s64)(*(s16 *)(arg0 + 0x9EC)) != value)) {
        btlUnitSetMotion(arg0, var_18, arg1, 1.0f, var_17);
    }
    *(s16 *)(arg0 + 0x9EC) = var_18;
    *(u16 *)(arg0 + 0x9EE) = var_16;
    *(f32 *)(arg0 + 0x9F0) = 1.0f;
    *(s8 *)(arg0 + 0x9F4) = var_17;
}

