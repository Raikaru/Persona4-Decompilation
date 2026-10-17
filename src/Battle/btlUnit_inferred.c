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
extern s32 scrStartProcedureChecked(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    scrStartProcedureChecked(arg0, arg1, arg2, arg3);
}
extern void mdlSetLayerWeight(u8 *arg0, s32 arg1, f32 arg2);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *arg0, u16 arg1);

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


extern s64 btlUnitGetMotionId(u8 *arg0, u16 arg1);
extern s16 btlUnitMotionFrames(u8 *arg0, u16 arg1, f32 fparg0);
extern void btlUnitSetMotion(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00198380-00198380 */

extern s32 btlUnitGetMotionState(u8 *arg0);
extern u32 btlUnitIsAtRestMotion(u8 *arg0);
extern u32 btlUnitIsWalkingMotion(u8 *arg0);
extern s64 btlUnitModelAnimFrame(u8 *arg0);
static inline u32 p4_add_index_base(u32 offset, u32 base)
{
    return offset + base;
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: declaration-corrected C candidate for func_00198380. */
// FUN_00198380
void btlUnitUpdateMotionLayer(u8 *arg0) {
    f32 var_f12;
    s16 temp_16_2;
    s16 temp_2;
    u32 temp_4;
    s32 temp_18;
    s32 temp_19;
    u16 temp_3;
    u16 temp_3_2;
    u16 temp_3_3;
    u16 var_6;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 0x98) & 2) {
        temp_16 = (u8 *)(*(u8 **)(arg0 + 0xA00));
        temp_3 = (u16)(*(u16 *)(arg0 + 0x9D8));
        if (temp_3 & 2) {
            mdlSetLayerWeight(temp_16, 0, 0.0f);
            return;
        }
        if ((temp_3 & 4) && ((s16)btlUnitModelAnimFrame(arg0) >= *(s16 *)(arg0 + 0x9E6)) && (*(s16 *)(arg0 + 0x9E8) > 0)) {
            mdlSetLayerWeight(temp_16, 0, 0.0f);
            *(s16 *)(arg0 + 0x9E8) = (s16) (*(s16 *)(arg0 + 0x9E8) - 1);
            return;
        }
        mdlSetLayerWeight(*(u8 **)(arg0 + 0xA00), 0, *(f32 *)(arg0 + 0x9E0));
        if (!(*(u16 *)(arg0 + 0x9D8) & 8)) {
            temp_3_2 = (u16)(*(u16 *)(arg0 + 0xC8));
            if ((temp_3_2 & 1) && !(temp_3_2 & 4)) {
                if (btlUnitIsWalkingMotion(arg0) == 0) {
                    if (*(s32 *)(arg0 + 0xC4) & 4) {
                        var_f12 = 2.0f;
                    } else {
                        var_f12 = 1.0f;
                    }
                    btlUnitSetMotion(arg0, 1, 4U, var_f12, 1);
                }
            } else if ((btlUnitIsWalkingMotion(arg0) != 0) && (btlUnitIsAtRestMotion(arg0) == 0)) {
                btlUnitSetMotion(arg0, *(s16 *)(arg0 + 0x9EC), 6U, *(f32 *)(arg0 + 0x9F0), *(s8 *)(arg0 + 0x9F4));
            }
        }
        temp_3_3 = (u16)(*(u16 *)(arg0 + 0x9DC));
        switch (temp_3_3) {
        case 1:
        case 2:
            break;
        case 0:
            if (*(u8 *)(temp_16 + 0xEE) == 1) {
                temp_16_2 = (s16)(*(s16 *)(arg0 + 0x9EC));
                if (temp_16_2 != (s16)btlUnitGetMotionState(arg0)) {
                    temp_2 = (s16)(*(s16 *)(arg0 + 0x9EE));
                    if (temp_2 > 0) {
                        var_6 = temp_2 & 0xFFFF;
                    } else {
                        switch (temp_16_2) {
                        case 3:
                        case 0xE:
                        case 0x12:
                        case 0x18:
                            temp_4 = (u16)btlUnitGetMotionId(arg0, temp_16_2 & 0xFFFF);
                            if ((s32)temp_4 < (s32)(*(u16 *)(arg0 + 0x9E4))) {
                                var_6 = (u16)(*(u16 *)(p4_add_index_base(temp_4 * 0xA, (u32)*(s32 *)(arg0 + 0x9F8)) + 8));
                            } else {
                                var_6 = 6;
                            }
                            break;
                        default:
                            var_6 = 0;
                            break;
                        }
                    }
                    btlUnitSetMotion(arg0, *(s16 *)(arg0 + 0x9EC), var_6, *(f32 *)(arg0 + 0x9F0), *(s8 *)(arg0 + 0x9F4));
                }
            }
            break;
        case 3:
            if (!(*(f32 *)(temp_16 + 0x108) < 1.0f)) {
                temp_19 = (s16)btlUnitGetMotionState(arg0);
                temp_18 = (s16)btlUnitModelAnimFrame(arg0);
                if (temp_18 >= (s16)btlUnitMotionFrames(arg0, temp_19 & 0xFFFF, 1.0f)) {
                    mdlSetLayerWeight(temp_16, 0, 0.0f);
                }
            }
            break;
        case 4:
            if ((*(u8 *)(temp_16 + 0xEE) == 1) && ((s16)btlUnitGetMotionState(arg0) != 0xE)) {
                btlUnitSetMotion(arg0, 0xE, 0U, 1.0f, 1);
            }
            break;
        case 5:
            if ((*(u8 *)(temp_16 + 0xEE) == 1) && ((s16)btlUnitGetMotionState(arg0) != 0x10)) {
                btlUnitSetMotion(arg0, 0x10, 0U, 1.0f, 1);
            }
            break;
        }
        *(u16 *)(arg0 + 0x9D8) = (u16) (*(u16 *)(arg0 + 0x9D8) & 0xFFF7);
    }
}

