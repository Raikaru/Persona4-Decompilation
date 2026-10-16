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
#include "datPersona_internal.h"
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
extern u32 datUnitInit(DatUnit *unit, u8 genus, u16 id);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern s32 btlActionAnyTargetHitRowFlagged(u8 *arg0);
extern s32 btlTargetIsEntryActive(s16 arg0);
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
extern void mdlLookAtSetupSetRange(void *arg0, float arg1, float arg2);
extern f32 DAT_0076112c;



extern u8 *btlUnitCreate(s32 arg0);
extern void btlUnitInitFromRecord(u8 *arg0, s32 arg1);



extern s32 datPersonaNamePart1(s16 arg0);
extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s32 datPersonaNamePart1Alt(s16 arg0);
extern s32 iGpffffb444;
extern s32 btlUnitIsMoving(u8 *arg0);
extern s32 btlUnitIdleAnimTick(u8 *arg0);
extern u8 *btlUnitCreateLookAtPacket(u8 *arg0, f32 *arg1, s32 arg2);
extern s32 datCalcIsLowHp(u8 *arg0);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern struct DatPersonaRecord *datPersonaGetRecord(u16 character);
extern s32 datPersonaGetRosterSlot(s32 arg0);
extern void btlActionSetState(u8 *arg0, u32 arg1);
extern void func_001b08d0(void *arg0);
extern void btlActionSetUnit(u8 *arg0, u8 *arg1);
extern u8 *btlActionCreate(void);
extern s32 btlActionQueuePush(u8 *arg0);
extern s32 btlUnitApplyEncounterRoster(u8 *arg0);
extern s32 func_00243d80(u8 *arg0);
extern void btlUnitInitChild(u8 *arg0, u16 arg1);
extern void btlUnitApplyBodySizeScale(u8 *arg0);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlUnitHoldPendingLookAt(u8 *arg0);
extern s32 btlUnitLookAtSidePacketUpdate(u8 *arg0);
extern void btlUnitReleasePendingLookAt(u8 *arg0);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 0019e9f0-0019ff60 */

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
#pragma push
#pragma pop
/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus named call_angle locals preserve retail's stack reloads before mdlLookAtSetupSetRange. */
#pragma push
/* measured: restore pragma state after func_0019df20. */
#pragma pop
// FUN_0019E9F0
u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 value)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x11A, 8);
    *(void **)(packet + 0x68) = (void *)btlUnitHoldPendingLookAt;
    *(void **)(packet + 0x6C) = (void *)btlUnitLookAtSidePacketUpdate;
    *(void **)(packet + 0x70) = (void *)btlUnitReleasePendingLookAt;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)work = unit;
    *(s16 *)(work + 4) = value;

    return packet;
}

// FUN_0019EA60
void btlUnitInitFromRecord(u8 *arg0, s32 arg1)
{
    extern void btlUiInitSpritePair(u8 *arg0, u8 *arg1);
    u8 *data;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    u16 temp_6;
    s32 temp_4_2;
    s32 temp_4_4;
    s32 temp_4_5;
    u16 temp_2;
    u16 temp_2_2;
    u16 temp_2_3;
    u16 temp_2_4;
    u16 temp_3;
    u8 temp_4;
    u8 *temp_4_3;

    temp_6 = arg1 & 0xFFFF;
    *(u16 *)(arg0 + 0xA4) = arg1;
    temp_4 = *(u8 *)(arg0 + 0xA2);
    switch (temp_4) {
    case 0:
        *(s16 *)(*(u8 **)(arg0 + 0xA64) + 2) = temp_6;
        datUnitInit((DatUnit *)*(u8 **)(arg0 + 0xA64), 0, temp_6);
        temp_4_2 = arg1 * 0x14C;
        temp_2 = *(u16 *)((u8 *)((u32)temp_4_2 + (u32)iGpffffb3c0) + 0x14);
        var_f1 = (f32)(u32)temp_2;
        *(f32 *)(arg0 + 0x2C) = var_f1 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3c0 + temp_4_2;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3c0 + temp_4_2 + 0x3C;
        *(s16 *)(arg0 + 0x9E4) = 0x1B;
        if ((u32)(arg1 - 3) < 3U) {
            temp_4_3 = *(u8 **)(arg0 + 0xA64);
            *(u16 *)(temp_4_3 + 0) |= 0x1000;
        }
        break;
    case 1:
        *(s16 *)(*(u8 **)(arg0 + 0xA64) + 2) = temp_6;
        temp_4_4 = arg1 * 0xE8;
        temp_2_2 = *(u16 *)((u8 *)((u32)temp_4_4 + (u32)iGpffffb3cc) + 0x14);
        var_f1_2 = (f32)(u32)temp_2_2;
        *(f32 *)(arg0 + 0x2C) = var_f1_2 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3cc + temp_4_4;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3cc + temp_4_4 + 0x2A;
        *(s16 *)(arg0 + 0x9E4) = 0x13;
        break;
    case 2:
        temp_4_5 = arg1 * 0x58;
        temp_2_3 = *(u16 *)((u8 *)((u32)temp_4_5 + (u32)iGpffffb3e0) + 0x18);
        var_f1_3 = (f32)(u32)temp_2_3;
        *(f32 *)(arg0 + 0x2C) = var_f1_3 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3e0 + temp_4_5 + 2;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3e0 + temp_4_5 + 0x1A;
        *(s16 *)(arg0 + 0x9E4) = 6;
        break;
    case 3:
    default:
        break;
    }
    *(f32 *)(arg0 + 0x80) = (f32)(s16)*(s16 *)(data + 0);
    *(f32 *)(arg0 + 0x84) = (f32)(s16)*(s16 *)(data + 2);
    *(f32 *)(arg0 + 0x88) = (f32)(s16)*(s16 *)(data + 4);
    temp_3 = *(u16 *)(data + 6);
    var_f0 = (f32)(u32)temp_3;
    *(f32 *)(arg0 + 0x8C) = var_f0;
    temp_2_4 = *(u16 *)(data + 8);
    var_f0_2 = (f32)(u32)temp_2_4;
    *(f32 *)(arg0 + 0x90) = var_f0_2;
    btlUiInitSpritePair(arg0, arg0 + 0xA10);
}

// FUN_0019EDA0
u8 *btlUnitGetRecordPtr(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_3;
    u8 *var_2;
    u8 *var_2_2;
    s32 var_4;
    s32 flags;

    temp_16 = *(u16 *)(arg0 + 0xA4);
    temp_3 = arg1 & 0xFFFF;
    switch (temp_3) {
    case 9:
    case 10:
        var_4 = 1;
        break;
    case 2:
        flags = *(s32 *)(arg0 + 0xA64);
        if ((flags != 0) && (datCalcChkBadStatus(flags, 0x100000) != 0)) {
            var_4 = 1;
            break;
        }
    default:
        var_4 = 0;
    }
    switch (*(u8 *)(arg0 + 0xA2)) {
    case 0:
        if (var_4 != 0) {
            var_2 = iGpffffb3c0 + temp_16 * 0x14C + 0xA;
        } else {
            var_2 = iGpffffb3c0 + temp_16 * 0x14C;
        }
        return var_2;
    case 1:
        if (var_4 != 0) {
            var_2_2 = iGpffffb3cc + temp_16 * 0xE8 + 0xA;
        } else {
            var_2_2 = iGpffffb3cc + temp_16 * 0xE8;
        }
        return var_2_2;
    case 2:
        return iGpffffb3e0 + temp_16 * 0x58 + 2;
    default:
        return NULL;
    }
}

// FUN_0019EF30
void btlUnitInitChild(u8 *arg0, u16 arg1) {
    extern void btlUnitInitFromRecord(u8 *arg0, u16 arg1);
    if (*(u8 **)(arg0 + 0xA0C) == NULL) {
        *(u8 **)(arg0 + 0xA0C) = btlUnitCreate(2);
    }
    btlUnitInitFromRecord(*(u8 **)(arg0 + 0xA0C), arg1);
}

// FUN_0019EF90
/* measured: opt_propagation off reproduces ef90's retail address setup order. */
/* measured: func_0019ef90 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
u8 *btlUnitFindInSideById(s32 arg0, s32 arg1)
{
    u8 *base;
    u8 *packet;
    u32 address;

    base = iGpffffb3ac;
    arg0 = (u16)arg0;
    address = (u32)p4_unit_00195530((u16)arg0 * 8, base) + 0x17C;
    packet = *(u8 **)address;
    arg1 = (u16)arg1;
    while (packet != NULL) {
        if (*(u16 *)(packet + 0xA4) == arg1) {
            return packet;
        }
        packet = *(u8 **)(packet + 0xA68);
    }
    return NULL;
}

/* measured: closes opt_propagation around ef90. */
/* measured: func_0019f050, func_0019f0f0, func_0019f5f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0019EFE0
u8 *btlUnitFindById(s32 arg0)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    arg0 = (u16)arg0;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x17C);
        while (packet != NULL) {
            if (*(s32 *)(packet + 0xA8) == arg0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0xA68);
        }
    }
    return NULL;
}

// FUN_0019F050
s32 btlUnitGetDataRow(u8 *arg0)
{
    u16 id;
    u8 type;
    s32 result;

    result = 0;
    id = *(u16 *)(arg0 + 0xA4);
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 0:
        result = datPersonaNamePart1Alt((s16)id);
        break;
    case 1:
        result = p4_base_add_0019f050((u32)id * 0x15,
                                      (s32)iGpffffb444);
        break;
    case 2:
        result = (s32)datPersonaGetRow(id);
        break;
    default:
        break;
    }
    return result;
}

/* Identical body to btlUnitGetDataRow (its type-0 callee datPersonaNamePart1 has the same
 * body as datPersonaNamePart1Alt); a separate retail function at its own address. */
// FUN_0019F0F0
s32 btlUnitGetDataRowAlt(u8 *arg0)
{
    u16 id;
    u8 type;
    s32 result;

    result = 0;
    id = *(u16 *)(arg0 + 0xA4);
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 0:
        result = datPersonaNamePart1((s16)id);
        break;
    case 1:
    case 2:
        result = 0;
        switch (type) {
        case 0:
            result = datPersonaNamePart1Alt((s16)id);
            break;
        case 1:
            result = p4_base_add_0019f050((u32)id * 0x15,
                                          (s32)iGpffffb444);
            break;
        case 2:
            result = (s32)datPersonaGetRow(id);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return result;
}

#pragma push
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_0019F1D0
void btlUnitApplyBodySizeScale(u8 *unit)
{
    extern u8 *iGpffffb3c4;
    u8 *resource;
    f32 radius;
    f32 height;
    f32 minRadius;
    f32 minHeight;
    f32 factor;
    f32 lower;
    f32 scale;
    f32 upper;
    f32 lowerHeight;
    f32 upperHeight;
    u16 band;
    s32 bound;

    if (*(u8 *)(unit + 0xA2) == 1) {
        resource = *(u8 **)(unit + 0xA64);
        if (resource != NULL &&
            (*(u16 *)(iGpffffb3c4 + *(u16 *)(resource + 2) * 0x3C) & 0x8000)) {
            return;
        }
    }

    scale = *(f32 *)(unit + 0x2C);
    radius = (f32)(s32)(*(f32 *)(unit + 0x90) * scale);
    height = (f32)(s32)(*(f32 *)(unit + 0x8C) * scale);
    lowerHeight = 200.0f;
    if (!(radius <= lowerHeight) || !(height <= 400.0f) ||
        radius < 50.0f || height < 100.0f) {
        return;
    }

    if (height <= lowerHeight) {
        if (radius <= 75.0f) {
            band = 0;
        } else if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else if (height <= 300.0f) {
        if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else {
        band = 2;
    }

    switch (band) {
    case 0:
        minRadius = 50.0f;
        minHeight = 100.0f;
        upper = 74.0f;
        lower = 199.0f;
        break;
    case 1:
        minRadius = 76.0f;
        minHeight = 201.0f;
        upper = 124.0f;
        bound = 299;
        lower = (f32)bound;
        break;
    case 2:
        minRadius = 126.0f;
        bound = 301;
        minHeight = (f32)bound;
        upper = 199.0f;
        bound = 399;
        lower = (f32)bound;
        break;
    }

    if (upper <= radius) goto upper_radius_one;
    upper = upper / radius;
    goto upper_radius_done;
upper_radius_one:
    upper = 1.0f;
upper_radius_done:
    if (lower <= height) goto upper_height_one;
    upperHeight = lower / height;
    goto upper_height_done;
upper_height_one:
    upperHeight = 1.0f;
upper_height_done:
    upper = upper < upperHeight ? upper : upperHeight;

    if (minRadius < radius) {
        lower = minRadius / radius;
    } else {
        lower = -1.0f;
    }
    if (minHeight < height) {
        lowerHeight = minHeight / height;
    } else {
        lowerHeight = -1.0f;
    }
    upperHeight = 0.0f;
    if (!(lower <= upperHeight) && !(lowerHeight <= upperHeight)) {
        lower = lower > lowerHeight ? lower : lowerHeight;
    } else {
        lower = 1.0f;
    }

    switch (*(u32 *)(unit + 0xA8) & 3) {
    case 0:
        factor = upper;
        break;
    case 1:
        factor = (0.0f + lower) + 0.5f * (upper - lower);
        break;
    case 2:
        factor = lower;
        break;
    case 3:
        factor = 1.0f;
        break;
    }
    *(f32 *)(unit + 0x2C) = factor * scale;
    *(u32 *)(unit + 0x98) |= 4;
}

#pragma pop
// FUN_0019F5F0
u8 *btlActionCreateWork(s32 arg0, u16 arg1, u16 *arg2)
{
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    u8 *temp_3;
    u8 *var_18;
    u8 *var_17;

    var_18 = NULL;
    temp_16 = arg0 & 0xFFFF;
    switch (temp_16) {
    case 0:
        var_17 = btlUnitCreate(0);
        var_18 = btlActionCreate();
        btlActionSetUnit(var_18, var_17);
        btlActionQueuePush(var_18);
        func_001b08d0(var_18);
        btlActionSetState(var_18, 1);
        if ((arg1 & 0xFFFF) == 1) {
            *(s16 *)(var_18 + 0x14) = 5;
            *(u8 **)(iGpffffb3ac + 0x170) = var_18;
        }
        p4_call_0019ef30(*(u16 *)((u8 *)datPersonaGetRecord(arg1) + 2),
                         var_17);
        *(s32 *)(var_18 + 0x3F0) = datPersonaGetRosterSlot((s16)arg1);
        *(u16 *)(var_18 + 0x1A) |= 0x10;
        break;
    case 1:
        var_17 = btlUnitCreate(1);
        var_18 = btlActionCreate();
        btlActionSetUnit(var_18, var_17);
        btlActionQueuePush(var_18);
        func_001b08d0(var_18);
        btlActionSetState(var_18, 1);
        break;
    default:
        break;
    }
    if (arg2 != NULL) {
        *(u16 **)(var_17 + 0xA64) = arg2;
        btlUnitInitFromRecord(var_17, (u16)(arg1 & 0xFFFF));
        if (temp_16 == 1 &&
            (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
            btlUnitApplyBodySizeScale(var_17);
        }
        if (datCalcIsDead((u8 *)arg2, 0) != 0) {
            *(s32 *)(var_17 + 0x9C) |= 1;
        }
    }
    temp_3 = *(u8 **)(var_18 + 0x30);
    *(s32 *)(temp_3 + 0x9C) |= 8;
    *(u16 *)(var_18 + 0x1A) |= 8;
    switch (temp_16) {
    case 0:
        *(u16 *)(var_18 + 0x1A) |= 0x200;
        temp_2 = *(s32 *)(var_17 + 0x9C) | 0x20;
        *(s32 *)(var_17 + 0x9C) = temp_2;
        temp_2_2 = temp_2 | 0x40;
        *(s32 *)(var_17 + 0x9C) = temp_2_2;
        temp_2_3 = temp_2_2 | 0x80;
        *(s32 *)(var_17 + 0x9C) = temp_2_3;
        temp_2_4 = temp_2_3 | 0x200;
        *(s32 *)(var_17 + 0x9C) = temp_2_4;
        *(s32 *)(var_17 + 0x9C) = temp_2_4 | 0x4000;
        break;
    case 1:
        if (arg2 != NULL && func_00243d80((u8 *)arg2) != 0) {
            temp_2_5 = *(s32 *)(var_17 + 0x9C) | 0x20;
            *(s32 *)(var_17 + 0x9C) = temp_2_5;
            temp_2_6 = temp_2_5 | 0x100;
            *(s32 *)(var_17 + 0x9C) = temp_2_6;
            temp_2_7 = temp_2_6 | 0x40;
            *(s32 *)(var_17 + 0x9C) = temp_2_7;
            *(s32 *)(var_17 + 0x9C) = temp_2_7 | 0x400;
        }
        break;
    default:
        break;
    }
    btlUnitApplyEncounterRoster(var_18);
    return var_18;
}

// FUN_0019F8A0
s32 btlUnitIdleAnimTick(u8 *arg0)
{
    s32 temp_2;
    u16 *temp_4;

    if (*(s32 *)(arg0 + 0x24) < 0) {
        *(s32 *)(arg0 + 0x24) = (effMiscRand(0) % 240U) + 0x78;
    }
    temp_2 = *(s32 *)(arg0 + 0x24);
    if (temp_2 == 0) {
        if (btlUnitIsAtRestMotion(*(u8 **)(arg0 + 0x30)) == 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          0x100000) != 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          0xFFFFF) != 0) {
            return 0;
        }
        temp_4 = *(u16 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        if ((*temp_4 & 0x200) != 0) {
            return 0;
        }
        if (datCalcIsLowHp((u8 *)temp_4) != 0 ||
            datCalcIsDead(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
            return 0;
        }
        if ((s16)btlUnitModelAnimFrame(*(u8 **)(arg0 + 0x30)) < 4) {
            btlPacketEnqueue(btlUnitCreateAnimPacket(*(u8 **)(arg0 + 0x30),
                                         0x11, 4, 0, 1.0f),
                          0);
            *(s32 *)(arg0 + 0x24) = -1;
        }
        return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_2 - 1;
    return 0;
}

// FUN_0019FA40
void btlUnitTickIdleAnims(void)
{
    u16 flags;
    u16 type;
    u8 *packet;
    u8 *work;

    work = *(u8 **)(iGpffffb3ac + 0x174);
    while (work != NULL) {
        flags = *(u16 *)(work + 0x1A);
        if ((flags & 0x200) != 0 && (flags & 1) != 0) {
            packet = *(u8 **)(work + 0x30);
            if ((*(s32 *)(packet + 0x9C) & 8) != 0 &&
                btlUnitIsMoving(packet) == 0) {
                type = *(u16 *)(work + 0xC);
                switch (type) {
                case 1:
                case 5:
                    btlUnitIdleAnimTick(work);
                    break;
                default:
                    break;
                }
            }
        }
        work = *(u8 **)(work + 0x450);
    }
}

// FUN_0019FAF0
void btlUnitRequestLookAtOthers(u8 *arg0)
{
    f32 sp40[3];
    u16 temp_4;
    u8 *var_17;
    u8 *temp_16;

    var_17 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_17 != NULL) {
        if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(var_17 + 0x30);
            if ((*(s32 *)(temp_16 + 0x9C) & 8) != 0 &&
                btlUnitIsAtRestMotion(temp_16) != 0 &&
                btlUnitIsMoving(temp_16) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0x100000) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0xFFFFF) == 0 &&
                datCalcIsLowHp(*(u8 **)(temp_16 + 0xA64)) == 0 &&
                datCalcIsDead(*(u8 **)(temp_16 + 0xA64), 0) == 0) {
                temp_4 = *(u16 *)(var_17 + 0xC);
                switch (temp_4) {
                case 1:
                case 5:
                    if (arg0 != var_17) {
                        btlUnitGetAnchorPose(temp_16, NULL, NULL, sp40);
                        btlPacketEnqueue(btlUnitCreateLookAtPacket(temp_16, sp40, 0), 1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        var_17 = *(u8 **)(var_17 + 0x450);
    }
}

// FUN_0019FC60
void func_0019fc60(void) {
}

/* measured: opt_propagation off with named table pointers preserves retail load order. */
#pragma push
/* measured: func_0019fc70 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0019FC70
s32 btlActionSkillReachesTargets(u8 *arg0)
{
    u16 temp_18;
    u16 temp_17;
    s32 temp_16;
    u16 result;
    u8 *temp_4;

    temp_18 = *(u16 *)(arg0 + 0x6E);
    result = (u16)btlSkillClassifyTargets(arg0, NULL, temp_18, 0);
    temp_4 = *(u8 **)(arg0 + 0x30);
    temp_17 = *(u16 *)(*(u8 **)(temp_4 + 0xA64) + 2);
    if (result != 0)
        goto result_zero_0019fc70;

    temp_16 = temp_18 & 0xFFFF;
    if ((iGpffffb3b8[temp_16 * 0x28] & 2) != 0) {
        switch (*(u8 *)(temp_4 + 0xA2)) {
        case 1:
            goto type_one_0019fc70;
        default:
            goto result_one_0019fc70;
        }
type_one_0019fc70:
        if (btlActionAnyTargetHitRowFlagged(arg0) != 0) {
            {
                u8 *table18;
                table18 = iGpffffb3cc;
                if ((*(s16 *)(p4_unit_00195530(
                    (u16)temp_17 * 0xE8, table18) + 0x18) &
                     0x100) != 0) {
                    return 1;
                }
            }
        }
        {
            u8 *table22;
            table22 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table22) + 0x22) == 1)
                return 0;
        }
result_one_0019fc70:
        return 1;
    }
    if (btlTargetIsEntryActive((s16)temp_18) != 0) {
        {
            u8 *flags_table;
            flags_table = (u8 *)iGpffffb3bc;
            if ((*(u16 *)(p4_unit_00195530(
                temp_16 * 4, flags_table) + 2) & 1) == 0)
                return 0;
        }
        /* Deliberately write case 0 before case 1: MWCC tests the last-written case first. */
        switch (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) {
        case 0:
        default:
            goto second_default_0019fc70;
        case 1:
            goto second_type_one_0019fc70;
        }
second_type_one_0019fc70:
        {
            u8 *table26;
            table26 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table26) + 0x26) == 1)
                return 0;
        }
second_default_0019fc70:
        return 1;
    }
result_zero_0019fc70:
    return 0;
}

#pragma pop
/* measured: opt_propagation off is scoped to func_0019fe60. */
/* measured: func_0019fe60 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0019FE60
s32 btlUnitIsUnavailable(u8 *arg0, s32 arg1, s32 arg2)
{
    u16 temp_6;
    u8 *temp_2;
    u8 *temp_4;
    u8 *table;
    u8 *table2;
    u8 kind;
    u8 status;

    temp_2 = *(u8 **)(arg0 + 0x30);
    temp_4 = *(u8 **)(temp_2 + 0xA64);
    temp_6 = *(u16 *)(temp_4 + 2);
    kind = *(u8 *)(temp_2 + 0xA2);
    switch (kind) {
    case 0:
        status = func_0023e1f0(temp_4);
        if (status == 5) {
            return 1;
        }
        if (status == 3) {
            table = (u8 *)iGpffffb3bc;
            if ((*(u16 *)(p4_unit_00195530((arg1 & 0xFFFF) * 4,
                                           table) + 2) &
                 0x8000) != 0 ||
                arg2 == 0) {
                return 1;
            }
        }
        break;
    case 1:
        table2 = iGpffffb3cc;
        if (*(s16 *)(p4_unit_00195530((temp_6 & 0xFFFF) * 0xE8,
                                      table2) + 0x22) == 1) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* measured: closes opt_propagation around func_0019fe60. */
/* measured: func_0019ff60 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0019FF60
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *arg0)
{
    u8 *state;
    u8 *current;
    u8 *unit;
    u16 enemyCount;

    state = *(u8 **)(iGpffffb3ac + 0x170);
    if (datCalcIsDead(*(u8 **)(*(u8 **)(state + 0x30) + 0xA64), 0) != 0 ||
        datCalcChkBadStatus(*(s32 *)(*(u8 **)(state + 0x30) + 0xA64),
                       0x100117) != 0) {
        return 0;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1 &&
        datCalcIsDead(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
        return 0;
    }
    *(u16 *)(iGpffffb3ac + 0xC58) = 0;
    enemyCount = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    for (; current != NULL; current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0) continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(s32 *)(unit + 0x9C) & 8) == 0 ||
            datCalcIsDead(*(u8 **)(unit + 0xA64), 0) != 0) continue;
        if (*(u8 *)(unit + 0xA2) == 1) {
            if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000) == 0) return 0;
            enemyCount++;
        } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100117) == 0 &&
                   state != current) {
            *(u8 **)(iGpffffb3ac +
                     (*(u16 *)(iGpffffb3ac + 0xC58) * 4) + 0xC48) = current;
            (*(u16 *)(iGpffffb3ac + 0xC58))++;
        }
    }
    if (enemyCount == 0) return 0;
    return *(u16 *)(iGpffffb3ac + 0xC58) >= 1;
}

