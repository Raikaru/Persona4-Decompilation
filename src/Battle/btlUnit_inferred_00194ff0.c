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
typedef struct RwV3d RwV3d;
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00194ff0-00195530 */

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
// FUN_00194FF0
void func_00194ff0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3)
{
    struct Work {
        f32 vec[3];
        u8 gap[4];
        f32 x;
        f32 y;
        f32 z;
    } frame;
    s16 temp_6;
    s32 temp_6_2;
    u8 temp_5;
    u8 *temp_2;
    u8 *temp_4;

    frame.x = (f32)(s32)((*(s16 *)(arg0 + 0x94) * 0x19) - 0x6D6);
    frame.y = 0;
    temp_6 = *(s16 *)(arg0 + 0x96);
    temp_6_2 = temp_6 * 5;
    frame.z = (f32)((temp_6 * 0x19) - 0x6D6);
    if (arg1 != NULL) {
        *(P4_95730_Vec3 *)arg1 = *(P4_95730_Vec3 *)&frame.x;
    }
    if ((arg3 != NULL) || (arg2 != NULL)) {
        temp_5 = *(u8 *)(arg0 + 0xA2);
        switch (temp_5) {
        case 0:
            if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) == 0) {
                btlUnitGetGroupBounds(2, 1, (RwV3d *)frame.vec, NULL, NULL, 1);
            } else {
                btlUnitGetGridSphereCenter(
                    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                    frame.vec);
            }
            break;
        case 1:
            if (btlUnitGetEntryPosition(arg0, frame.vec, temp_6_2) != 1) {
                temp_2 = btlActionGetActiveOrQueueFront();
                if ((temp_2 != NULL) &&
                    ((temp_4 = *(u8 **)(temp_2 + 0x30)),
                     (*(u8 *)(temp_4 + 0xA2) == 0)) &&
                    ((*(u16 *)(temp_2 + 0x18) & 4) == 0 ||
                     *(u16 *)(temp_2 + 0x16) != 0x1E)) {
                    btlUnitGetGridSphereCenter(temp_4, frame.vec);
                } else {
                    btlUnitGetGridSphereCenter(
                        *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                        frame.vec);
                }
            }
            break;
        }
        if (arg3 != NULL) {
            *(P4_95730_Vec3 *)arg3 = *(P4_95730_Vec3 *)frame.vec;
        }
        if (arg2 != NULL) {
            btlTargetBlendVectors(arg2, &frame.x, frame.vec);
        }
    }
}

/* measured: object 832B/window 832B, nd 0. arg6 is an s32 param copied to a u8
   temporary before each use (retail keeps the raw value in $s0 and re-masks);
   `kind` is a plain u16 local (a redundant & 0xFFFF becomes a hoisted $s
   constant under propagation off) and arg3 goes through a u16 temporary. The
   table addresses: `(u8 *)off + (s32)((u8 *)(kind * 0x58) + (s32)iGpffffb3e0)`
   for the deferred GP load with addu kind,base / off,sum; and a `tbl = gp`
   local plus `(u8 *)(kind * 0x58) + (s32)tbl` where retail loads the base first.
   `dist = call; dist += 50.0f` gives the result-first add.s; stack arrays in
   declaration order tmp, pos, scaled, origin, rot. */
// FUN_001951F0
/* measured: opt_propagation off keeps the per-use u8/u16 conversions and the
   named scaled index (`off = k * 6`) from being folded into one address. */
/* measured: func_001951f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void func_001951f0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4, f32 *arg5, s32 arg6)
{
    f32 tmp[3];
    f32 pos[3];
    f32 scaled[3];
    f32 origin[3];
    f32 rot[4];
    u16 kind;
    u8 *entry;
    f32 dist;
    f32 fx;
    f32 fz;
    f32 side;
    u8 k;
    f32 sx;
    f32 sz;
    f32 t;
    u8 *tbl;
    s32 off;
    u16 a3;

    kind = *(u16 *)(arg0 + 0xA4);
    k = arg6;
    if (k == 2) {
        if (*(s32 *)(iGpffffb3ac + 0x10) & 0x01000000) {
            arg6 = 0;
        }
    }
    k = arg6;
    if (k != 2) {
        if (arg5 != NULL) {
            *(P4_95730_Vec4 *)arg5 = *(P4_95730_Vec4 *)(arg1 + 0x1C);
        }
        if (arg4 != NULL) {
            btlUnitGetSphereWorldCenter(arg1, origin);
            origin[1] = 0.0f;
            k = arg6;
            off = k * 6;
            entry = (u8 *)off + (s32)((u8 *)(kind * 0x58) + (s32)iGpffffb3e0);
            pos[0] = *(s16 *)(entry + 0xC);
            pos[1] = *(s16 *)(entry + 0xE);
            pos[2] = *(s16 *)(entry + 0x10);
            scaled[0] = pos[0] * *(f32 *)(arg0 + 0x2C);
            scaled[1] = pos[1] * *(f32 *)(arg0 + 0x2C);
            scaled[2] = pos[2] * *(f32 *)(arg0 + 0x2C);
            RtQuatTransformVectors(pos, scaled, 1, arg1 + 0x1C);
            arg4[0] = pos[0] + origin[0];
            arg4[1] = pos[1] + origin[1];
            arg4[2] = pos[2] + origin[2];
        }
    } else {
        btlUnitGetSphereCenterTowardTarget(arg2, arg1, origin);
        a3 = arg3;
        dist = func_00196bd0(arg0, arg2, a3);
        dist = dist + 50.0f;
        btlTargetBlendVectors(rot, arg1 + 4, origin);
        RtQuatTransformVectors(tmp, &D_0060A100, 1, rot);
        fx = tmp[0] * dist;
        fz = tmp[2] * dist;
        tbl = iGpffffb3e0;
        t = *(s16 *)((u8 *)(kind * 0x58) + (s32)tbl + 0xC);
        side = t * *(f32 *)(arg0 + 0x2C);
        RtQuatTransformVectors(tmp, &D_0060A0D0, 1, rot);
        tmp[0] *= side;
        tmp[1] *= side;
        tmp[2] *= side;
        sx = fx + tmp[0];
        sz = fz + tmp[2];
        pos[0] = origin[0] + sx;
        pos[2] = origin[2] + sz;
        pos[1] = 0.0f;
        if (arg4 != NULL) {
            *(P4_95730_Vec3 *)arg4 = *(P4_95730_Vec3 *)pos;
        }
        if (arg5 != NULL) {
            btlTargetBlendVectors(arg5, pos, origin);
        }
    }
}

/* measured: closes the propagation bracket; the file default is on. */
/* measured: func_00195530 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_00195530
s32 func_00195530(u8 *arg0) {
    u8 *e;

    if (arg0[0xA2] != 2) {
        return -1;
    }
    e = p4_unit_00195530(*(u16 *)(arg0 + 0xA4) * 0x58, iGpffffb3e0);
    return (e[0x56] << 24) | 0xFFFFFF;
}

