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
    func_00198920(arg0, arg1, arg2, arg3, arg4);
}
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern void mdlSetLayerWeight(u8 *arg0, s32 arg1, f32 arg2);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern void mdlSetLayerHandleFlag(void *arg0);
extern void mdlClearLayerHandleFlag(void *arg0);
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

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00198920-00198920 */

typedef struct MotionTableEntry {
    s16 followMotion;
    s16 ratePercent;
    s16 followFrame;
    s16 unknown6;
    s16 nextMotion;
} MotionTableEntry;
static inline u16 motionModeFlags(u16 option)
{
    switch (option) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        return 0;
    default:
        return 1;
    }
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* Measured: 1196 instruction bytes, nine resolved relocations and four zero
 * tail bytes. Animation and blend frames retain their halfword domains through
 * the model dispatcher. The table views keep rate and follow-up lifetimes
 * separate; the shared motion contracts preserve all existing callers. */
// FUN_00198920
void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4)
{
    extern f32 iGpffff80d4;
    extern f32 iGpffff812c;
    extern u8 *btlUnitGetRecordPtr(u8 *arg0, s32 arg1);
    s32 a1m;
    u16 v11;
    s32 v12;
    s16 *sp;
    MotionTableEntry *base;
    MotionTableEntry *table;

    *(s16 *)(arg0 + 0x9DC) = arg4;
    if ((*(u32 *)(arg0 + 0x98) & 2) != 0) {
        a1m = (u16)arg1;
        *(s16 *)(arg0 + 0x9DA) = arg1;
        v11 = (u16)btlUnitGetMotionId(arg0, a1m);
        if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
            table = *(MotionTableEntry **)(arg0 + 0x9F8);
            *(f32 *)(arg0 + 0x9E0) = arg3 * ((f32)table[v11].ratePercent / 100.0f);
        } else {
            *(s32 *)(arg0 + 0x9E0) = 0x3F800000;
        }
        arg4 = arg4 & 0xFFFF;
        v12 = motionModeFlags(arg4);
        if (arg3 < iGpffff80d4 || !(arg3 <= iGpffff812c)) {
            switch (arg1) {
            case 4:
            case 12:
            case 8:
                v12 = (u16)(v12 | 0x60);
                break;
            default:
                break;
            }
        }
        if (((*(u16 *)(arg0 + 0x9D8) & 0x10) != 0) || (*(s32 *)(arg0 + 0xA64) != 0 && datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 256) != 0)) {
            v12 = (u16)(v12 | 0x100);
        }
        if (arg1 == 19) {
            mdlClearLayerHandleFlag(*(u8 **)(arg0 + 0xA00));
        } else {
            mdlSetLayerHandleFlag(*(u8 **)(arg0 + 0xA00));
        }
        if ((*(u16 *)(arg0 + 0x9D8) & 0x20) != 0) {
            arg2 = 0;
        }
        if ((*(u16 *)(arg0 + 0x9D8) & 0x40) != 0) {
            v11 = 27;
        }
        mdlDispatchAnimIfPresent(*(u8 **)(arg0 + 0xA00), 0, (s32)(s16)v11, arg2, v12);
        mdlSetLayerWeight(*(u8 **)(arg0 + 0xA00), 0, *(f32 *)(arg0 + 0x9E0));
        sp = (s16 *)btlUnitGetRecordPtr(arg0, a1m);
        *(f32 *)(arg0 + 0x80) = (f32)sp[0];
        *(f32 *)(arg0 + 0x84) = (f32)sp[1];
        *(f32 *)(arg0 + 0x88) = (f32)sp[2];
        *(f32 *)(arg0 + 0x8C) = (f32)(u16)sp[3];
        *(f32 *)(arg0 + 0x90) = (f32)(u16)sp[4];
        switch (arg1) {
        case 8:
        case 16:
            if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
                base = &((MotionTableEntry *)*(u8 **)(arg0 + 0x9F8))[(u16)v11];
                if (base->followMotion >= 0 && base->followFrame > 0) {
                    *(u16 *)(arg0 + 0x9D8) = *(u16 *)(arg0 + 0x9D8) | 4;
                    *(s16 *)(arg0 + 0x9E6) = ((MotionTableEntry *)*(u8 **)(arg0 + 0x9F8))[(u16)v11].followMotion;
                    *(s16 *)(arg0 + 0x9E8) = ((MotionTableEntry *)p4_base_add_00194590((u16)v11 * sizeof(MotionTableEntry), *(s32 *)(arg0 + 0x9F8)))->followFrame;
                }
            }
            break;
        default:
            *(u16 *)(arg0 + 0x9D8) = *(u16 *)(arg0 + 0x9D8) & 0xFFFB;
            break;
        }
        if (arg4 == 0) {
            switch (arg1) {
            case 2:
            case 8:
            case 12:
            case 9:
            case 11:
            case 22:
            case 23:
            case 20:
                *(s16 *)(arg0 + 0x9EE) = 0;
                break;
            case 4:
                *(s16 *)(arg0 + 0x9EE) = 0;
                break;
            default:
                if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
                    table = *(MotionTableEntry **)(arg0 + 0x9F8);
                    *(s16 *)(arg0 + 0x9EE) = table[v11].nextMotion;
                } else {
                    *(s16 *)(arg0 + 0x9EE) = 0;
                }
                break;
            }
        }
    }
}

