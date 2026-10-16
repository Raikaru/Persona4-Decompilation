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
    func_00198920(arg0, arg1, arg2, arg3, arg4);
}
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern void mdlSetColor(void *arg0, s32 *arg1);
extern u8 iGpffffa4d8;
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *arg0, s32 arg1);
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern void SceneDraw_SetResVisibleChecked(u16 arg0, u32 arg1);




extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *arg0, u16 arg1);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *arg0);
extern void btlUnitHideModel();
extern void btlUnitShowModel(u8 *arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 0019c0d0-0019d0c0 */

extern void func_00198380(u8 *arg0);
typedef struct { u8 r, g, b, a; } Col4_0019;
typedef struct {
    f32 right[3];
    s32 flags;
    f32 up[3];
    s32 pad1;
    f32 at[3];
    s32 pad2;
    f32 pos[3];
    s32 pad3;
} Mtx_0019;
static inline void colMul_0019(Col4_0019 *dst, const u8 *src)
{
    f32 scale;
    f32 bias;
    f32 g = (0.003921569f * (f32)(u32)dst->g) * (0.003921569f * (f32)(u32)src[1]);
    f32 b = (0.003921569f * (f32)(u32)dst->b) * (0.003921569f * (f32)(u32)src[2]);
    f32 a = (0.003921569f * (f32)(u32)dst->a) * (0.003921569f * (f32)(u32)src[3]);
    f32 r = (0.003921569f * (f32)(u32)dst->r) * (0.003921569f * (f32)(u32)src[0]);

    scale = 255.0f;
    bias = 0.5f;
    dst->r = (s32)(scale * r + bias);
    dst->g = (s32)(scale * g + bias);
    dst->b = (s32)(scale * b + bias);
    dst->a = (s32)(scale * a + bias);
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
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
// FUN_0019C0D0
void func_0019c0d0(void)
{
    extern u32 btlUnitUpdateFollowPath(u8 *arg0);
    extern void btlBossCopyPartnerMark(u8 *arg0);
    extern void SceneDraw_SetResPersona(u16 arg0, u32 arg1);
    extern void func_001b70c0(u8 *arg0);
    extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
    extern void mdlScale(void *arg0, void *arg1, s32 arg2);
    extern void *mdlTranslateMatrix(void *arg0, void *arg1, s32 arg2);
    extern void mdlAdvanceModelFromFlags(void *arg0);
    extern s32 func_001ee490(u8 *arg0);
    extern u32 btlUnitIsModelVisible(u8 *arg0);
    extern s32 func_001d72e0(s32 arg0);
    extern s16 func_001d7130(s32 arg0);
    extern void func_001d7400(s32 arg0, u8 *arg1);
    /* Retail passes the sign-extended word from (s16)func_001d72e0() in $a1
     * without narrowing; the s16 definition's prototype adds a re-extension. */
    extern void func_001d7100(u8 *arg0, s32 arg1);
    extern void func_001d72c0(void *arg0, u32 arg1);
    extern void func_001d7140(u8 *arg0);
    u8 *entry;
    u32 i;
    s32 v41;
    s32 chk;

    for (i = 0; i < 4; i++) {
        entry = *(u8 **)(D_0076449C + (i * 8) + 0x17C);
        while (entry != NULL) {
            btlUnitUpdateFollowPath(entry);
            func_00198380(entry);
            switch (i) {
            case 1:
                btlBossCopyPartnerMark(entry);
                break;
            case 2:
                if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                    u16 id;

                    if ((id = *(u16 *)(entry + 0x9FE)) != 0) {
                        SceneDraw_SetResPersona(id, *(u8 *)(entry + 0xAC) == 1);
                    }
                }
                break;
            }
            if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                s32 v;
                s32 n;

                func_001b70c0(entry);
                v = *(u16 *)entry;
                if ((v & 3) != 0 && (v & 4) == 0) {
                    u8 base;
                    s32 t;

                    if ((v & 8) != 0) {
                        base = 0x58;
                    } else {
                        base = 0;
                    }
                    t = *(u8 *)(entry + 0x37);
                    if (base + 0x20 < t) {
                        *(u8 *)(entry + 0x37) = t - 0x20;
                    } else {
                        *(u8 *)(entry + 0x37) = base;
                    }
                    *(s32 *)(entry + 0x98) |= 4;
                } else {
                    s32 t = *(u8 *)(entry + 0x37);

                    if (t < 0xFF) {
                        if (t < 0xDF) {
                            *(u8 *)(entry + 0x37) = t + 0x20;
                        } else {
                            *(u8 *)(entry + 0x37) = 0xFF;
                        }
                        *(s32 *)(entry + 0x98) |= 4;
                    }
                }
                n = *(u16 *)(entry + 0x4C);
                if (n > 0) {
                    f32 fdiv = (f32)(u32)n / 8.0f;
                    u32 b;

                    b = *(u8 *)(entry + 0x48);
                    *(u8 *)(entry + 0x40) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x44) - b));
                    b = *(u8 *)(entry + 0x49);
                    *(u8 *)(entry + 0x41) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x45) - b));
                    b = *(u8 *)(entry + 0x4A);
                    *(u8 *)(entry + 0x42) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x46) - b));
                    *(s32 *)(entry + 0x98) |= 4;
                    *(u16 *)(entry + 0x4C) = *(u16 *)(entry + 0x4C) - 1;
                }
                if ((*(s32 *)(entry + 0x98) & 4) != 0) {
                    Mtx_0019 m;
                    f32 vec[3];
                    Col4_0019 col;
                    s32 mode;
                    u8 *obj;
                    f32 x = *(f32 *)(entry + 0x1C);
                    f32 y = *(f32 *)(entry + 0x20);
                    f32 z = *(f32 *)(entry + 0x24);
                    f32 w = *(f32 *)(entry + 0x28);
                    f32 xx = x * x;
                    f32 yy = y * y;
                    f32 zz = z * z;
                    f32 yz = y * z;
                    f32 zx = z * x;
                    f32 xy = x * y;
                    f32 wx = w * x;
                    f32 wy = w * y;
                    f32 wz = w * z;
                    f32 two = 2.0f;
                    f32 one = 1.0f;

                    m.right[0] = one - two * (yy + zz);
                    m.right[1] = two * (xy + wz);
                    m.right[2] = two * (zx - wy);
                    m.up[0] = two * (xy - wz);
                    m.up[1] = one - two * (xx + zz);
                    m.up[2] = two * (yz + wx);
                    m.at[0] = two * (zx + wy);
                    m.at[1] = two * (yz - wx);
                    m.at[2] = one - two * (xx + yy);
                    m.pos[0] = 0.0f;
                    m.pos[1] = 0.0f;
                    m.pos[2] = 0.0f;
                    m.flags = 3;
                    mdlApplyModelMatrix(*(u8 **)(entry + 0xA00), &m, 0);
                    vec[0] = vec[1] = vec[2] = *(f32 *)(entry + 0x2C);
                    mdlScale(*(u8 **)(entry + 0xA00), vec, 2);
                    vec[0] = *(f32 *)(entry + 4) + *(f32 *)(entry + 0x10);
                    vec[1] = *(f32 *)(entry + 8) + *(f32 *)(entry + 0x14);
                    vec[2] = *(f32 *)(entry + 0xC) + *(f32 *)(entry + 0x18);
                    mdlTranslateMatrix(*(u8 **)(entry + 0xA00), vec, 2);
                    col = *(Col4_0019 *)(entry + 0x30);
                    colMul_0019(&col, entry + 0x34);
                    colMul_0019(&col, entry + 0x3C);
                    colMul_0019(&col, entry + 0x40);
                    if (col.a >= 0xFE) {
                        col.a = 0xFF;
                        mode = 0x737FB;
                        btlUnitClearModelState(entry, 2);
                        btlUnitClearModelState(entry, 5);
                    } else if (i != 2) {
                        mode = 0x737FB;
                        btlUnitApplyModelState(entry, 2);
                        btlUnitApplyModelState(entry, 5);
                    }
                    {
                        s32 *e8 = (s32 *)(*(u8 **)(entry + 0xA00) + 0xE8);

                        if (*e8 != mode) {
                            u32 j;

                            *e8 = mode;
                        for (j = 0; j < 5; j++) {
                            u8 *sub = *(u8 **)((u32)*(u8 **)(entry + 0xA00) + j * 12 + 0x290);

                            if (sub != NULL) {
                                *(s32 *)(sub + 0xE8) = mode;
                            }
                        }
                        }
                    }
                    {
                        Col4_0019 *cp = &col;

                        *(Col4_0019 *)(entry + 0x4E) = *cp;
                        mdlSetColor(*(u8 **)(entry + 0xA00), (s32 *)cp);
                    }
                    func_001ee490(entry);
                    *(s32 *)(entry + 0x98) &= ~4;
                }
                {
                    u8 *obj2 = *(u8 **)(entry + 0xA00);

                    if ((*(s32 *)(obj2 + 0xD8) & 4) != 0) {
                        mdlAdvanceModelFromFlags(obj2);
                    }
                }
                if (*(s32 *)(entry + 0xA04) != 0 && btlUnitIsModelVisible(entry) != 0) {
                    u8 *p = *(u8 **)(entry + 0xA64);

                    if (p != NULL) {
                        v41 = *(u32 *)(p + 0xC) & 0xFFFFF;
                        chk = (s16)func_001d72e0(v41);

                        if (chk != (s16)func_001d7130(*(s32 *)(entry + 0xA04))) {
                            func_001d7400(v41, entry + 0x48);
                            *(Col4_0019 *)(entry + 0x44) = *(Col4_0019 *)(entry + 0x40);
                            *(u16 *)(entry + 0x4C) = 8;
                            func_001d7100(*(u8 **)(entry + 0xA04), chk);
                        }
                    }
                    func_001d72c0(*(u8 **)(entry + 0xA04), *(u32 *)(entry + 0x4E));
                    func_001d7140(*(u8 **)(entry + 0xA04));
                }
            }
            entry = *(u8 **)(entry + 0xA68);
        }
    }
}

#pragma pop
// FUN_0019CFB0
void func_0019cfb0(void) {
    u32 i;
    u8 *entry;

    i = 0;
    goto loop_7;
loop_5:
    entry = *(u8 **)(D_0076449C + (i * 8) + 0x17C);
    goto loop_check;
loop_body:
    if (*(s32 *)(entry + 0x98) & 2) {
        btlUnitUpdateLookAtTarget(entry);
    }
    entry = *(u8 **)(entry + 0xA68);
loop_check:
    if (entry != NULL) {
        goto loop_body;
    }
    i += 1;
loop_7:
    if (i < 4U) {
        goto loop_5;
    }
}

// FUN_0019D040
void btlUnitShowModel(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) &= ~0x1000;
    btlUnitClearModelState(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        SceneDraw_SetResVisibleChecked(*(u16 *)(arg0 + 0x9FE), 1);
        *(s32 *)(arg0 + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(arg0 + 0x9C) |= 2;
}

// FUN_0019D0C0
void btlUnitHideModel(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) |= 0x1000;
    btlUnitClearModelState(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        SceneDraw_SetResVisibleChecked(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}

