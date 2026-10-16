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
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} P4_95730_Vec3;
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
extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
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
typedef struct RwV3d RwV3d;
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

extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
extern void mdlSetLayerTime(void *arg0, s32 arg1, f32 arg2);
static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    btlUnitSetMotion(arg0, arg1, arg2, arg3, arg4);
}
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 001991c0-00199ec0 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma push
#pragma pop
/* measured: opt_propagation off is scoped to func_001990d0. */
/* measured: closes opt_propagation around func_001990d0. */
// FUN_001991C0
s16 btlUnitMotionFrames(u8 *arg0, u16 arg1, f32 fparg0)
{
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    u8 type;
    u8 *entry;

    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(btlFormationLookupSlot(arg0, arg1));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            (s32)final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return (s64)(s32)((f32)*(s16 *)(entry + 0) /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
    return 0;
}

// FUN_00199350
s16 btlUnitMotionFollowFrames(u8 *arg0, u16 arg1, f32 fparg0)
{
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    u8 type;
    u8 *entry;
    s16 numerator;

    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(btlFormationLookupSlot(arg0, arg1));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
{
    s32 final_result;
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            (s32)final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        numerator = *(s16 *)(entry + 4);
        if (numerator < 0) {
            return 0;
        }
        return (s64)(s32)((f32)numerator /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
}
return 0;
}

// FUN_00199500
s16 btlUnitMotionModelFrames(u8 *arg0, u16 arg1, f32 fparg0)
{
    extern f32 mdlGetLayerKeyTime(s32 arg0, s32 arg1, s64 arg2);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    f32 temp_f0;
    u8 type;
    u8 *entry;

    if (!(*(s32 *)(arg0 + 0x98) & 2)) {
        return 0;
    }
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(btlFormationLookupSlot(arg0, arg1));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    temp_f0 = mdlGetLayerKeyTime(*(s32 *)(arg0 + 0xA00), 0, result);
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return (s64)(s32)(temp_f0 /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
    return (s64)(s32)temp_f0;
}

// FUN_001996D0
s16 btlUnitGetMotionTableFrames(u8 *arg0, u16 arg1)
{
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    u8 type;
    u8 *entry;

    if (!(*(s32 *)(arg0 + 0x98) & 2)) {
        return 6;
    }
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(btlFormationLookupSlot(arg0, arg1));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return *(s16 *)(entry + 8);
    }
    return 6;
}

// FUN_00199830
s64 btlUnitModelAnimFrame(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x98) & 2) {
        return (s64)(s16)(s32)mdlGetLayerWeight(*(s32 *)(arg0 + 0xA00), 0);
    }
    return 0;
}

// FUN_00199890
void btlUnitSetModelAnimFrame(u8 *arg0, s32 arg1)
{
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0)
        mdlSetLayerTime(*(u8 **)(arg0 + 0xA00), 0, (f32)arg1);
}

/* measured: opt_propagation off is scoped to func_001998e0. */
// FUN_001998E0
s32 btlUnitMotionClassValue(u8 *arg0, s32 arg1)
{
    s32 index;
    s32 result;
    s64 signedResult;
    u8 kind;
    u16 id;
    s32 offset;
    s32 base;
    s32 finalResult;

    kind = *(u8 *)(arg0 + 0xA2);
    if (kind == 1) {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            result = 0;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    } else {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 5:
            result = 0;
            goto classification_done_001998e0;
        case 6:
        case 7:
            result = 1;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    }
result_invalid_001998e0:
    result = -1;
classification_done_001998e0:
    signedResult = (s64)(s16)result;
    if (signedResult == -1) {
        return 1;
    }
    if (kind == 1) {
        id = *(u16 *)(arg0 + 0xA4);
        offset = id * 0xE8;
        base = (s32)iGpffffb3cc;
        offset = offset + base;
        index = (s16)result;
        finalResult = *(s16 *)((u8 *)p4_base_add_00194590(
            index * 4, offset) + 0x1A);
        goto function_done_001998e0;
    }
    finalResult = 1;
function_done_001998e0:
    return finalResult;
}

/* measured: closes opt_propagation around func_001998e0. */
/* Measured: the hit ordinal is s64 and motion is u16. Propagation off
   retains the entry mask and the late unsigned-halfword table index. */
/* measured: func_001999f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001999F0
s16 btlUnitMotionHitFrames(u8 *arg0, u16 arg1, f32 fparg0, s64 arg2)
{
    u16 index;
    s16 class_result;
    u8 type;
    s64 value;
    s64 raw_value;
    s32 numerator;
    s16 denominator;
    s32 offset;
    s32 base;
    u16 array_index;

    type = *(u8 *)(arg0 + 0xA2);
    if (type == 1) {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            class_result = p4_sign16_001991c0(0);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    } else {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 5:
            class_result = p4_sign16_001991c0(0);
            goto classification_done_001999f0;
        case 6:
        case 7:
            class_result = p4_sign16_001991c0(1);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    }
result_invalid_001999f0:
    class_result = p4_sign16_001991c0(-1);
classification_done_001999f0:
    if (class_result == -1) {
        return 0;
    }
    switch (type) {
    case 1:
        {
            value = p4_sign16_001991c0(btlFormationLookupSlot(arg0, arg1));
        }
        switch (value) {
        case -1:
            goto lookup_001999f0;
        default:
            goto finish_001999f0;
        }
    case 0:
    case 2:
lookup_001999f0:
        type = *(u8 *)(arg0 + 0xA2);
        raw_value = p4_sign16_001991c0(
            *(u8 *)((u8 *)D_005F6CA0 + type * 0x1E + (u16)arg1));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (index == 1)) {
            raw_value = p4_sign16_001991c0(0x1C);
        }
        goto value_done_001999f0;
    default:
        value = 0;
        goto finish_001999f0;
    }
value_done_001999f0:
    value = p4_sign16_001991c0(raw_value);
finish_001999f0:
    if (*(u8 *)(arg0 + 0xA2) == 1) {
        {
            s64 product;
            offset = *(u16 *)(arg0 + 0xA4) * 0xE8;
            base = (s32)iGpffffb3cc;
            offset = p4_base_add_00194590(offset, base);
            offset = p4_base_add_00194590(
                (s32)(s16)class_result * 4, offset);
            numerator = *(s16 *)((u8 *)offset + 0x1C);
            product = (s64)(s16)(numerator * (s16)arg2);
            /* Retail normalizes the requested motion again at this lookup,
             * independently of the earlier classification/override mapping. */
            numerator = (s32)product +
                        *(s16 *)((u8 *)(*(s32 *)(arg0 + 0x9F8) +
                                        (s32)((u32)arg1 % 0x10000U) * 0xA));
            product = (s64)(s16)numerator;
            numerator = (s32)product;
        }
    } else {
        offset = *(u16 *)(arg0 + 0xA4) * 0x14C;
        base = (s32)iGpffffb3c0;
        offset = p4_base_add_00194590(offset, base);
        offset = p4_base_add_00194590(
            (s32)class_result * 0x12, offset);
        offset = p4_base_add_00194590(
            (s32)(u16)arg2 * 2, offset);
        numerator = *(s16 *)((u8 *)(offset + 0x1A));
    }
    base = *(s32 *)(arg0 + 0x9F8);
    denominator = *(s16 *)((u8 *)(p4_base_add_00194590(
        (s16)value * 0xA, base) + 2));
    return (s16)(s32)((f32)numerator /
                      (fparg0 * ((f32)denominator / 100.0f)));
}

/* Measured: 336B/336B, nd 0. Keep the full-width ID for the predicate;
   scoped propagation preserves the staged unsigned table offset. */
// FUN_00199D00
#pragma push
s32 btlUnitOpeningMotionMode(s32 unused, u8 *arg1, s16 arg2, s32 arg3)
{
    s32 temp_16;
    u32 offset;
    u16 temp_3;
    s64 raw_3;
    s16 narrowed_3;

    temp_16 = (s64)(s16)arg2;
    if (temp_16 == -1 || temp_16 >= 0x1B8)
        return 1;
    if (btlTargetIsEntryActive(arg2) != 0) {
        offset = (u32)temp_16 << 2;
        temp_3 = *(u16 *)((u32)iGpffffb3bc + 2U + offset);
        if ((temp_3 & 0x200) == 0) {
            if ((arg3 == 0) || ((temp_3 & 1) == 0)) {
                return 1;
            }
            return 2;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 &&
            arg3 == 0) {
            return 1;
        }
        return 0;
    }
    raw_3 = datCalcSkillElement(*(u8 **)(arg1 + 0xA64), (u16)arg2);
    narrowed_3 = (s16)raw_3;
    switch (narrowed_3) {
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 3;
    }
}

#pragma pop
// FUN_00199E50
void btlUnitHoldPendingAnim(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00199E70
u32 btlUnitPlayMotionPacketUpdate(void *workData)
{
    u8 *packet = (u8 *)workData;
    s16 motion;
    s32 frame;
    f32 rate;
    u16 option;

    motion = *(s16 *)(packet + 4);
    if (motion >= 0 && motion < 0x1E) {
        workData = *(u8 **)packet;
        frame = *(u16 *)(packet + 6);
        rate = *(f32 *)(packet + 8);
        option = *(u16 *)(packet + 0xC);
        btlUnitSetMotion((u8 *)workData, motion, frame, rate, option);
    }
    return 1;
}

// FUN_00199EC0
void btlUnitReleasePendingAnim(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

