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
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern void func_001d1540(u8 *arg0, s32 arg1, s32 arg2);
extern void btlTargetRemoveRadiusNode(u8 *arg0);
extern int mdlHasActiveMode(void *arg0);
extern void mdlSetLookAtActive(void *arg0);
extern void mdlSetLookAtRequested(void *arg0);
extern u8 *resrcMngFindResById(u8 *arg0, u16 arg1);
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern void mdlSetBattleStateFlag(void *arg0);
extern void mdlSetAlphaBlend(void *arg0);
extern void mdlSetLookStateWord(void *arg0, u16 arg1);
extern u16 mdlGetLookStateWord(void *arg0);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlClearBattleStateFlag(void *arg0);
extern void mdlClearAlphaBlend(void *arg0);
extern void mdlSetBlendWeight(void *arg0, float arg1);
extern void mdlLookAtSetupSetRange(void *arg0, float arg1, float arg2);
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *arg0, s32 arg1);
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern u8 *btlSoundGetCharacterBank(u8 *arg0);




extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s32 iGpffffb444;

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlUnitFreeRemovedUnits(void);
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 0019d670-0019db40 */

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
// FUN_0019D670
void btlUnitFreeRemovedUnits(void)
{
    u8 *unit;
    u8 *next;
    u32 i;
    u8 *linked;
    u8 *linked2;
    u8 unitType;
    s8 status;

    for (i = 0; i < 4; i++) {
        unit = *(u8 **)(iGpffffb3ac + (i * 8) + 0x178);
        while (unit != NULL) {
            next = *(u8 **)(unit + 0xA6C);
            unitType = *(u8 *)(unit + 0xA2);
            btlUnitReleaseAllResources(unit);
            btlTargetRemoveRadiusNode(unit);
            status = *(s8 *)(unit + 0x9FC);
            if (status >= 0)
                func_001d1540(unit, status, 0);
            linked = *(u8 **)(unit + 0xA6C);
            if (linked != NULL)
                *(u8 **)(linked + 0xA68) = *(u8 **)(unit + 0xA68);
            else
                *(u8 **)(iGpffffb3ac + ((unitType & 0xFF) * 8) + 0x17C) =
                    *(u8 **)(unit + 0xA68);
            linked2 = *(u8 **)(unit + 0xA68);
            if (linked2 != NULL)
                *(u8 **)(linked2 + 0xA6C) = *(u8 **)(unit + 0xA6C);
            else
                *(u8 **)(iGpffffb3ac + ((unitType & 0xFF) * 8) + 0x178) =
                    *(u8 **)(unit + 0xA6C);
            jtbl_008873EC[0](unit);
            unit = next;
        }
    }
}

/* measured: plain-C switch reconstruction reproduces the 488-byte object against the 496-byte retail window; the jump-table base register remains the residual. Committed at nd 61. */
// FUN_0019D7A0
void btlUnitApplyModelState(u8 *arg0, s32 arg1)
{
    s32 temp_4;
    u16 temp_5;
    u16 temp_3;
    u8 *temp_2;
    u8 *temp_3_2;
    u8 *temp_4_2;
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        temp_3 = (u16)arg1;
        switch (temp_3) {
        case 6:
            temp_5 = *(u16 *)(arg0 + 0x9FE);
            if ((temp_5 != 0) &&
                (((s32)(temp_5 & 0xFFC00) >> 10) == 1)) {
                temp_2 = resrcMngFindResById(*(u8 **)(iGpffff9db0 + 8), temp_5);
                *(s32 *)(temp_2 + 0x22C) = 0x34;
                *(s32 *)(temp_2 + 0x28) |= 0x04000000;
                return;
            }
            break;
        case 1:
            temp_4 = *(s32 *)(iGpffffb3ac + 0x10);
            if (((temp_4 & 0x100) == 0) ||
                (*(u8 *)(arg0 + 0xA2) != 0)) {
                if (((temp_4 & 0x200) == 0) ||
                    (*(u8 *)(arg0 + 0xA2) != 1)) {
                    mdlSetBattleStateFlag(*(u8 **)(arg0 + 0xA00));
                    *(u8 **)(*(u8 **)(arg0 + 0xA00) + 0x2F8) =
                        D_007940F0;
                    *(f32 *)(*(u8 **)(arg0 + 0xA00) + 0x274) =
                        fGpffff80fc;
                    temp_3_2 = *(u8 **)(arg0 + 0xA00);
                    *(f32 *)(temp_3_2 + 0x278) =
                        *(f32 *)(temp_3_2 + 0x274);
                    *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x27C) =
                        0x3F800000;
                    return;
                }
            }
            break;
        case 2:
            mdlSetAlphaBlend(*(u8 **)(arg0 + 0xA00));
            return;
        case 3:
            mdlSetLookStateWord(*(u8 **)(arg0 + 0xA00), (u16)((mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) &
                   0xFFFF) | 0x1000));
            mdlSetLookStateWord(*(u8 **)(arg0 + 0xA00), (u16)((mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) &
                   0xFFFF) | 0x2000));
            temp_4 = mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x801;
            mdlSetLookStateWord(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            return;
        case 4:
            *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x2DC) =
                (s32)btlSoundGetCharacterBank(arg0);
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u16 *)(temp_4_2 + 0x2E0) |= 0x10;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

// FUN_0019D990
void btlUnitClearModelState(u8 *arg0, s32 arg1)
{
    s32 temp_4;
    u16 temp_5;
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_4_2;
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        temp_3 = (u32)arg1 & 0xFFFF;
        switch (temp_3) {
        case 6:
            temp_5 = *(u16 *)(arg0 + 0x9FE);
            if ((temp_5 != 0) &&
                (((s32)(temp_5 & 0xFFC00) >> 10) == 1)) {
                temp_2 = resrcMngFindResById(*(u8 **)(iGpffff9db0 + 8), temp_5);
                *(s32 *)(temp_2 + 0x28) &= 0xFBFFFFFF;
                return;
            }
            break;
        case 1:
            mdlClearBattleStateFlag(*(u8 **)(arg0 + 0xA00));
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u8 *)(temp_4_2 + 0x260) &= 0xE2;
            return;
        case 2:
            mdlClearAlphaBlend(*(u8 **)(arg0 + 0xA00));
            return;
        case 3:
            mdlSetBlendWeight(*(u8 **)(arg0 + 0xA00), DAT_0076112c);
            mdlLookAtSetupSetRange(*(u8 **)(arg0 + 0xA00), 70.0f, 80.0f);
            mdlSetLookAtActive(*(u8 **)(arg0 + 0xA00));
            mdlSetLookAtRequested(*(u8 **)(arg0 + 0xA00));
            temp_4 = mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x2001;
            mdlSetLookStateWord(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            temp_4 = mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x1001;
            mdlSetLookStateWord(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            *(s16 *)(arg0 + 0xB0) = 0;
            return;
        case 4:
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u16 *)(temp_4_2 + 0x2E0) &= 0xFFEF;
            *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x2DC) = 0;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

// FUN_0019DB40
/* measured: object 812B/window 816B, nd 0. The mode dispatch is an explicit goto
   chain (`== 0x11` -> case11, `!= 0` -> def, fall to case0; a switch sorts the
   zero test first and drops the `b default`). func_00232710 is called with two
   arguments through an unprototyped block-scope extern; func_0019efe0 needs its
   real prototype at block scope (it is defined later in the unit). The scale
   multiplies are inline `*(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C)` so the
   0x80 load precedes the 0x2C load. */
void btlUnitUpdateLookAtTarget(u8 *arg0)
{
    extern void mdlSetLookAtTargetPoint(void *arg0, void *arg1);
    extern s32 mdlComputeIndexedAttachMatrix(void *arg0, s32 arg1, void *arg2);
    extern f32 DAT_007613f8;
    extern u8 *func_0019efe0(s32 arg0);
    P4_95730_Vec3 pos;
    P4_95730_Vec3 scaled;
    P4_95730_Vec3 rotated;
    P4_95730_Vec3 scaled2;
    P4_95730_Vec3 rotated2;
    s16 mode;
    u8 *target;

    if (*(s32 *)(arg0 + 0x98) & 2) {
        if (*(s32 *)(arg0 + 0x98) & 2) {
            mode = *(s16 *)(arg0 + 0x9DA);
        } else {
            mode = 0;
        }
        if (mode == 0x11) {
            goto case11;
        }
        if (mode != 0) {
            goto def;
        }
        goto case0;
    case11:
        if (mdlHasActiveMode(*(u8 **)(arg0 + 0xA00)) != 0) {
            mdlSetLookAtRequested(*(u8 **)(arg0 + 0xA00));
        }
        return;
    def:
        if (mdlHasActiveMode(*(u8 **)(arg0 + 0xA00)) != 0) {
            mdlSetLookAtActive(*(u8 **)(arg0 + 0xA00));
            mdlSetLookAtRequested(*(u8 **)(arg0 + 0xA00));
        }
        return;
    case0:
            if (*(s32 *)(arg0 + 0xA64) != 0 && datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
                if (mdlHasActiveMode(*(u8 **)(arg0 + 0xA00)) != 0) {
                    mdlSetLookAtRequested(*(u8 **)(arg0 + 0xA00));
                }
                return;
            }
            if (*(u16 *)(arg0 + 0xB0) != 0 && !(*(f32 *)(*(u8 **)(arg0 + 0xA00) + 0x108) < 1.0f) && !(mdlGetLookStateWord(*(u8 **)(arg0 + 0xA00)) & 0x200)) {
                switch (*(u16 *)(arg0 + 0xB0)) {
                case 1:
                    mdlSetLookAtTargetPoint(*(u8 **)(arg0 + 0xA00), arg0 + 0xB8);
                    return;
                case 2:
                    if (*(s32 *)(arg0 + 0xB4) != 0) {
                        target = func_0019efe0(*(s32 *)(arg0 + 0xB4) & 0xFFFF);
                        if (target != NULL && target != arg0) {
                            if (!(*(s32 *)(target + 0x98) & 2)) {
                                scaled.x = *(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C);
                                scaled.y = *(f32 *)(target + 0x84) * *(f32 *)(target + 0x2C);
                                scaled.z = *(f32 *)(target + 0x88) * *(f32 *)(target + 0x2C);
                                RtQuatTransformVectors(&rotated, &scaled, 1, target + 0x1C);
                                pos.x = rotated.x + *(f32 *)(target + 4);
                                pos.y = rotated.y + *(f32 *)(target + 8);
                                pos.z = rotated.z + *(f32 *)(target + 0xC);
                            } else if (mdlComputeIndexedAttachMatrix(*(u8 **)(target + 0xA00), 0, &pos) == 0) {
                                scaled2.x = *(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C);
                                scaled2.y = *(f32 *)(target + 0x84) * *(f32 *)(target + 0x2C);
                                scaled2.z = *(f32 *)(target + 0x88) * *(f32 *)(target + 0x2C);
                                RtQuatTransformVectors(&rotated2, &scaled2, 1, target + 0x1C);
                                pos.x = rotated2.x + *(f32 *)(target + 4);
                                pos.y = rotated2.y + *(f32 *)(target + 8);
                                pos.z = rotated2.z + *(f32 *)(target + 0xC);
                            }
                            pos.y += *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C) * DAT_007613f8;
                            mdlSetLookAtTargetPoint(*(u8 **)(arg0 + 0xA00), &pos);
                            return;
                        }
                        mdlSetLookAtRequested(*(u8 **)(arg0 + 0xA00));
                        *(s32 *)(arg0 + 0xB4) = 0;
                    }
                    break;
                }
            }
    }
}

