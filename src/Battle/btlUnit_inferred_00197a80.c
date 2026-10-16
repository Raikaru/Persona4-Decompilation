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
extern f32 func_0044b950(f32 x, f32 y);
extern f32 fGpffff8048;
extern void func_003dc740(void *dst, const void *src, s32 mode, f32 angle);
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(u8 *arg0);
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
    func_00198920(arg0, arg1, arg2, arg3, arg4);
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
extern float btlFormationGetScale(int arg0);
extern s32 btlUnitArcMovePacketUpdate(u8 *arg0);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00197a80-00197f30 */

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
/* measured: opt_propagation off keeps the per-use u8/u16 conversions and the
   named scaled index (`off = k * 6`) from being folded into one address. */
/* measured: closes the propagation bracket; the file default is on. */
/* measured: opt_propagation off preserves the COP1 chain's intermediate colouring. */
/* measured: func_00197a80 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00197A80
s32 btlUnitArcMovePacketUpdate(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec3 transformed;
    P4_95730_Vec3 delta;
    P4_95730_Vec3 position;
    f32 temp_f2;
    f32 progress;
    s32 use_scaled;
    unit = *(u8 **)arg0;
    if (func_0023df70(*(u16 *)(arg0 + 4)) != 0) {
        if (*(u16 *)(arg0 + 6) == 0) {
            *(f32 *)(arg0 + 0x24) = 0.5f;
            *(P4_95730_Vec3 *)(arg0 + 0xC) =
                *(P4_95730_Vec3 *)(unit + 4);
            RtQuatTransformVectors(&transformed, &D_0060A100, 1, unit + 0x1C);
            *(f32 *)(arg0 + 0x18) = 400.0f * transformed.x;
            *(f32 *)(arg0 + 0x1C) = 400.0f * transformed.y;
            *(f32 *)(arg0 + 0x20) = 400.0f * transformed.z;
        }
        progress = *(f32 *)(arg0 + 0x24);
        progress += 0.03125f;
        *(f32 *)(arg0 + 0x24) = progress;
        temp_f2 = 0.0f + (-1.0f) +
                  ((-2.0f * progress) * progress) +
                  (4.0f * progress);
        progress = 2.0f * (temp_f2 - 0.5f);
        if (progress < fGpffff82d4) {
            delta.x = *(f32 *)(arg0 + 0x18) * progress;
            delta.y = *(f32 *)(arg0 + 0x1C) * progress;
            delta.z = *(f32 *)(arg0 + 0x20) * progress;
            use_scaled = 0;
        } else {
            delta = *(P4_95730_Vec3 *)(arg0 + 0x18);
            use_scaled = 1;
        }
        position.x = *(f32 *)(arg0 + 0xC) + delta.x;
        position.y = *(f32 *)(arg0 + 0x10) + delta.y;
        position.z = *(f32 *)(arg0 + 0x14) + delta.z;
        *(P4_95730_Vec3 *)(unit + 4) = position;
        *(s32 *)(unit + 0x98) |= 4;
        *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 6) + 1;
        return use_scaled;
    }
    *(s32 *)(unit + 0x10) = 0;
    *(f32 *)(unit + 0x14) =
        *(f32 *)(arg0 + 8) * D_005F6C10[*(u16 *)(arg0 + 6)];
    *(s32 *)(unit + 0x18) = 0;
    *(s32 *)(unit + 0x98) |= 4;
    return ++*(u16 *)(arg0 + 6) >= 0x23U;
}

/* measured: restore opt_propagation after func_00197a80 FPR temporary colouring probe. */
// FUN_00197CC0
u8 *btlUnitCreateArcMovePacket(s32 arg0, s16 arg1, s16 arg2)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x10C, 0x28);
    *(void **)(packet + 0x6C) = (void *)btlUnitArcMovePacketUpdate;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)work = arg0;
    *(s16 *)(work + 4) = arg1;
    *(s16 *)(work + 6) = arg2;
    *(f32 *)(work + 8) = btlFormationGetScale(arg0);
    return packet;
}

// FUN_00197D50
void btlUnitHoldPendingRotate(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00197D70
s32 btlUnitRotatePacketUpdate(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec4 rotation;
    P4_95730_Vec3 output;
    f32 dx;
    f32 dz;
    s32 flags;
    s32 mask;
    u8 active;
    s32 result;

    unit = *(u8 **)arg0;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        if ((*(s32 *)(arg0 + 0x10) & 0x1000) != 0) {
            dx = *(f32 *)(arg0 + 4) - *(f32 *)(unit + 4);
            dz = *(f32 *)(arg0 + 0xC) - *(f32 *)(unit + 0xC);
            if ((dx != 0.0f) || (dz != 0.0f)) {
                func_003dc740(&rotation, D_0060A0E0, 0,
                              fGpffff8048 * func_0044b950(dx, dz));
                if ((*(s32 *)(unit + 0x9C) & 0x2000) == 0) {
                    *(P4_95730_Vec4 *)(unit + 0x1C) = rotation;
                    *(s32 *)(unit + 0x98) |= 4;
                }
            }
            *(s32 *)(unit + 0xC4) &= ~2;
            *(u16 *)(unit + 0xC8) &= 0xFFFD;
            btlUnitRequestLookAt(unit);
        } else {
            if ((*(s32 *)(arg0 + 0x10) & 0x20) != 0) {
                func_00194ff0(unit, NULL, NULL, (f32 *)&output);
                *(P4_95730_Vec3 *)(arg0 + 4) = output;
            }
            flags = *(s32 *)(arg0 + 0x10);
            *(P4_95730_Vec3 *)(unit + 0xD0) =
                *(P4_95730_Vec3 *)(arg0 + 4);
            *(s32 *)(unit + 0x504) = 0;
            *(s32 *)(unit + 0xE8) = 0;
            *(s32 *)(unit + 0xC4) = flags;
            *(u16 *)(unit + 0xC8) |= 2;
        }
    }
    mask = *(u16 *)(unit + 0xC8) & 2;
    active = (mask != 0);
    if (active == 0) {
        result = 1;
    } else {
        *(s32 *)(arg0 + 0x14) += 1;
        result = 0;
    }
    return result;
}

// FUN_00197F30
void btlUnitReleasePendingRotate(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

