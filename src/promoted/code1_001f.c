#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern void func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern s32 func_00457120(void);
extern void func_0045c870(u8 *arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBadStatus(s32 arg0);
extern s32 func_00243ce0(s32 arg0);
extern u8 *iGpffffb3c4;
extern s32 datCalcGetHp(u8 *arg0);
extern s32 datCalcGetSp(u8 *arg0);
extern s32 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern s32 datCalcGetBadStatusNoDown(u8 *arg0);
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 func_0010f420(s32 arg0, s32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 func_001f56d0(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_001f62b0();
extern void func_001f58d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0045af90(s32 arg0);

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2);

extern u32 datCalcRandomBelow();
extern s32 datCalcEnemyExp(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern u16 datCalcPickWeightedSkill(u8 *arg0, s32 *arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_0060AB08[];
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s16 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern s32 func_001f65d0(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 func_001ef9a0(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern s32 func_00459880(void);

extern void H_Cdvd_Destroy(u8 *arg0);
extern void datCalcClearFlaggedBuffs(s32 arg0);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3c0(void);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3e0(void);
extern void func_002bd410(void);
extern s32 func_0022bad0(u8 *arg0, s16 arg1);
extern s32 func_0022bc80(s32 arg0);
extern s32 func_001fa7a0(s32 *arg0);
extern s32 func_001fa940(void);
extern s32 func_001faa00(void);
extern s32 func_0022bd00(void);
extern s32 func_00120ee0(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern void datCalcClearStatusBlocked(s32 arg0);
extern void datCalcSetHp(s32 arg0, s32 arg1);
extern void datCalcClearBadStatus(s32 arg0, s32 arg1);
extern void datCalcSetBadStatus(s32 arg0, s32 arg1);

extern void func_00485b20(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern s32 func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 func_001fa660(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];
extern s32 kwlnTaskGetTaskByName(void *arg0);

extern s32 func_001fbb50(u8 *arg0);


extern void btlTargetAdvanceWorkPtr(u8 **arg0);
extern u16 datPersonaGetRecordId(u16 arg0);
extern u16 *datPersonaGetRecord(u16 character);
extern s32 datPersonaFindSkillSlot(u8 *persona, u16 skill);
extern s32 func_001f3900(u8 **arg0);
extern void btlTargetAdvanceWorkCount(void);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);

extern void btlTargetRewindWorkPtr(u8 **arg0);

extern s32 func_001f39d0(u8 **arg0);
extern void btlTargetRewindWorkCount(void);

extern s32 func_001f8380(u8 **arg0);
extern s32 func_00106600(s16 arg0);
extern s32 datCalcAddHp(s32 arg0, s32 arg1);
extern s32 datCalcAddSp(s32 arg0, s32 arg1);
extern u32 datCalcSkillCost(u8 *arg0, s32 arg1);

extern s32 func_001f8400(u8 **arg0);
extern s32 iGpffffb464;
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void sprintf(void *dst, void *fmt, ...);
extern s32 func_00456250(s32 arg0, void *arg1, s32 arg2, void *arg3);
extern s32 func_004c7ef8(s32 arg0);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

extern s32 func_001f0950(s32 arg0, s32 arg1);



#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on
#pragma pop



#pragma opt_loop_invariants on
#pragma opt_loop_invariants off


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

/* measured: compiler residual in call argument materialization. Committed at nd 3. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
#pragma optimization_level 1
// FUN_001F0FF0
s32 func_001f0ff0(u32 arg0)
{
    s32 index;
    index = *(u16 *)(arg0 + 0x6E);
    return (func_001d7f10((u8 *)arg0, 0, index, 0) & 0xFFFF) == 0;
}
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma optimization_level 2

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
typedef struct BtlHit_001f14f0 {
    s32 damageA;
    s32 damageB;
    s32 maskA;
    s32 maskB;
    s32 bonus;
    s32 effect;
    u16 absoluteA;
    u16 absoluteB;
    s8 reaction;
    u8 pad1D;
    u16 flags;
} BtlHit_001f14f0;

static inline s32 btlAnyUnitE4_001f14f0(u8 *arg0, s32 n)
{
    u16 k;

    for (k = 0; k < n; k++) {
        if (*(s32 *)(*((u8 **)arg0 + 0xE + k) + 0xE4) != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_pulloutconstants off

#pragma pop

#pragma opt_propagation off
#pragma opt_propagation on














extern u32 datCalcIsLowHp(s32 unit);
extern u8 *func_001b0c80(s32 arg0);
#pragma push
#pragma opt_propagation off
#pragma opt_propagation on
#pragma pop





// FUN_001F6100
void func_001f6100(void)
{
    memset(iGpffffb3ac + 0xA44, 0, 0x2C);
    *(s32 *)(iGpffffb3ac + 0xA54) = 0;
    *(s32 *)(iGpffffb3ac + 0xA58) = -1;
    *(s16 *)(iGpffffb3ac + 0xA5C) = -1;
    *(s32 *)(iGpffffb3ac + 0xA60) = -1;
    *(s16 *)(iGpffffb3ac + 0xA64) = -1;
    *(s32 *)(iGpffffb3ac + 0xA68) = -1;
    *(s16 *)(iGpffffb3ac + 0xA6C) = -1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4E) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4C) = 8;
    *(s16 *)(iGpffffb3ac + 0xA6E) = 0;
}
// FUN_001F6190
void func_001f6190(void)
{
    func_001f58d0();
}

// FUN_001F61B0
void func_001f61b0(void)
{
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0xA54);
    if (var_4 != NULL) {
        H_Cdvd_Destroy(var_4);
        *(u8 **)(iGpffffb3ac + 0xA54) = NULL;
        temp_3 = iGpffffb3ac;
        *(s32 *)(temp_3 + 0xC) = *(s32 *)(temp_3 + 0xC) & 0xFEFFFFFF;
    }
    temp_3 = iGpffffb3ac;
    *(u16 *)(temp_3 + 0xA4E) = *(u16 *)(temp_3 + 0xA4E) & 0xFFFE;
    func_002bd3c0();
}

// FUN_001F6220
s32 func_001f6220(s16 arg0, s32 arg1)
{
    u8 *temp_3;

    temp_3 = iGpffffb3ac;
    if ((*(u16 *)(temp_3 + 0xA4E) & 1) != 0) {
        if (*(s32 *)(temp_3 + 0xA58) == arg1) {
            return 1;
        }
        if (*(s32 *)(temp_3 + 0xA60) == arg1) {
            return 1;
        }
    }
    *(s16 *)(temp_3 + 0xA64) = arg0;
    *(s32 *)(iGpffffb3ac + 0xA60) = arg1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 1;
    return 1;
}

// FUN_001F6290
s32 func_001f6290(void) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA4E) & 1) != 0);
}



// FUN_001F62B0
void func_001f62b0(void) {
    u8 *temp_4;

    func_002bd3e0();
    func_002bd410();
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    temp_4 = iGpffffb3ac;
    *(u16 *)(temp_4 + 0xA4E) &= 0xFFFE;
}
/* 728/736 bytes; thirteen resolved code relocations and seven jump-table
 * entries; eight zero tail bytes. Preserve eligibility-argument timing. */
struct EffRandState;

static inline s32 battleMessageBand(s32 value, s32 band)
{
    return value + band;
}

// FUN_001F62F0
s32 func_001f62f0(u8 *arg0)
{
    extern s32 datCalcGetLevel(u8 *arg0);
    extern s32 datCalcStatusResistance(u8 *arg0, s32 arg1);
    extern u32 effMiscRand(struct EffRandState *state);
    s32 code;
    s32 base;
    s32 random;
    u16 mode;
    u16 count;
    s16 i;
    s32 flags;
    s32 offset;
    u16 values[8];

    base = datGetFlag(0x38) != 0 ? 0xFA : 0xC8;
    random = func_001ef4d0(2, 0x80000) & 0xFFFF;
    flags = datCalcGetLevel(
        *(u8 **)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) + 0xA64)) &
        0xFF;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        mode = 0;
    } else if ((random - flags) >= 4) {
        mode = 0;
    } else if ((flags - random) >= 4) {
        mode = 2;
    } else {
        mode = 1;
    }
    count = 0;
    i = 0;
    offset = mode * 0x1E;
    for (; i < 7; i++) {
        switch (i) {
        case 0:
            code = 0;
            break;
        case 1:
            code = 1;
            break;
        case 2:
            code = 2;
            break;
        case 3:
            code = 4;
            break;
        case 4:
            code = 3;
            break;
        case 5:
            code = 6;
            break;
        case 6:
            code = 7;
            break;
        default:
            break;
        }
        if ((*(u8 *)(arg0 + 0xA2) != 1) ||
            ((flags = (u16)code, func_001f0950(*(u16 *)(arg0 + 0xA4), flags)) != 0)) {
            flags = datCalcStatusResistance(*(u8 **)(arg0 + 0xA64), code);
            if ((flags & 0x08000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1));
            } else if ((flags & 0x07000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1) + 0xE);
            }
        }
    }
    if (count > 0) {
        return values[datCalcRandomBelow(count)];
    }
    return base + (effMiscRand(NULL) & 1) + offset;
}
// FUN_001F65D0
s32 func_001f65d0(u8 *arg0)
{
    extern void func_002bd240(u32 arg0);
    extern void func_00440b68();
    extern s32 func_00454a60();
    extern u8 iGpffffa4e8;
    extern u8 iGpffffa4e0;
    extern u8 D_0060ABE8[];
    u16 temp_3;
    u16 var_3;
    u8 *temp_4;

    temp_3 = *(u16 *)(arg0 + 6);
    switch (temp_3) {
    case 0:
        if (*(u16 *)(arg0 + 4) == 0) {
            var_3 = 8;
        } else {
            var_3 = 5;
        }
        *(u16 *)(iGpffffb3ac + 0xA4C) = var_3;
    case 1:
        func_00440b68(&iGpffffa4e8, D_0060ABE8, 0x713);
        *(s32 *)(iGpffffb3ac + 0xA54) =
            func_00454a60(
                *(u8 **)((u8 *)&iGpffffa4e0 +
                         (*(u16 *)(arg0 + 4) * 4)),
                0);
        *(u16 *)(arg0 + 6) = 2;
        goto block_14;
    case 2:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(iGpffffb3ac + 0xA54)) != 0) {
    case 3:
            func_002bd240(
                (1 << *(u16 *)(iGpffffb3ac + 0xA4C)) | 1);
            *(u16 *)(arg0 + 6) = 4;
    case 4:
            temp_4 = iGpffffb3ac;
            *(s32 *)(temp_4 + 0xC) =
                *(s32 *)(temp_4 + 0xC) | 0x01000000;
            return 1;
        }
        goto block_14;
    block_14:
    default:
        return 0;
    }
}
// FUN_001F6710
u8 *func_001f6710(s32 arg0) {
    u8 *p;
    u8 *q;

    p = (u8 *)btlPacketAlloc(0x803, 8);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_001f65d0;
    q = *(u8 **)(p + 0x78);
    *(s16 *)(q + 4) = (s16)arg0;
    *(s16 *)(q + 6) = 0;
    return p;
}

/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
#pragma opt_loop_invariants on
// FUN_001F6770
s32 func_001f6770(u8 *arg0)
{
    extern u32 datCalcRandomBelow(s32 arg0);
    extern s32 datCalcHasSkill(u8 *arg0, s32 arg1);
    u16 chance;
    u8 *status;
    u32 mask;
    u32 one;
    u32 i;

    status = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    if (datCalcChkBadStatus((s32)status, 0x100000) != 0) {
        return 1;
    }
    if (datCalcChkBadStatus((s32)status, 0x1001DF) == 0) {
        return 0;
    }
    chance = 100;
    mask = 0;
    switch (datCalcGetBadStatusNoDown(status)) {
    case 4:
        chance = 70;
        mask = 4;
        break;
    default:
        break;
    }
    chance &= 0xFFFF;
    if (chance == 100) {
        return 1;
    }
    chance = datCalcRandomBelow(100) < chance;
    if (chance == 0 && datCalcHasSkill(status, 0x230) != 0) {
        one = 1;
        i = 0;
        while (i < 0x18U) {
            if ((mask & (one << i)) != 0) {
                if (*(u8 *)((u8 *)addOffsetFirst(i, (u32)arg0) + 0x3F6) > 0) {
                    return 1;
                }
                *(u8 *)((u8 *)addOffsetFirst(i, (u32)arg0) + 0x3F6) += 1;
                break;
            }
            i++;
        }
    }
    return chance;
}
/* measured: close opt_loop_invariants after func_001f6770. */
#pragma opt_loop_invariants off
// FUN_001F68E0
s32 func_001f68e0(u8 *arg0)
{
    u8 *unit;
    s32 status;

    unit = *(u8 **)(arg0 + 0x30);
    status = *(s32 *)(unit + 0xA64);
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        return 0;
    }
    return (datCalcChkBadStatus(status, 0x60) != 0);
}

/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma opt_propagation off
// FUN_001F6930
s32 func_001f6930(u8 *arg0)
{
    extern s32 datCalcHasSkill(s32 arg0, s32 arg1);
    extern s32 func_00244f60(u32 arg0, u16 *arg1, u16 *arg2, u16 arg3, s32 arg4);
    s32 var_22;
    u32 var_21;
    s32 var_20;
    s32 var_19;
    s32 var_3;
    u8 *temp_17;
    s32 temp_16;
    s32 temp_30;
    u16 *temp_5;
    u16 *temp_5_2;
    u16 *temp_5_3;
    u16 *temp_5_4;
    u16 *temp_5_5;
    u16 *temp_5_6;
    s32 temp_3;

    temp_17 = *(u8 **)(arg0 + 0x30);
    temp_30 = datCalcGetBadStatus(*(s32 *)(temp_17 + 0xA64));
    var_22 = 0;
    var_21 = 0;
    goto loop_31_test;
loop_31_body:
    var_3 = 1;
    temp_16 = 1 << var_21;
    if (temp_30 & temp_16) {
        switch (temp_16) {
        case 0x10:
            temp_5 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5, temp_5, 0xFFFF, 0x10);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x4:
            temp_5_2 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_2, temp_5_2, 0xFFFF, 4);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x2:
            temp_5_3 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_3, temp_5_3, 0xFFFF, 2);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x40:
            temp_5_4 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_4, temp_5_4, 0xFFFF, 0x40);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x80:
            temp_5_5 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_5, temp_5_5, 0xFFFF, 0x80);
            var_19 = 6;
            temp_3 = var_3;
            break;
        case 8:
            temp_5_6 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_6, temp_5_6, 0xFFFF, 8);
            var_19 = 6;
            temp_3 = var_3;
            break;
        default:
            var_20 = 0;
            var_19 = 0;
            temp_3 = 0;
            break;
        }
        if ((temp_3 == 1) && (var_19 != 0)) {
            if (datCalcHasSkill(*(s32 *)(temp_17 + 0xA64), 0x22F) != 0) {
                var_19 = var_19 >> 1;
                if (var_19 <= 0) {
                    var_19 = 1;
                }
            }
            if (datCalcHasSkill(*(s32 *)(temp_17 + 0xA64), 0x230) != 0) {
                var_19 = 1;
            }
        }
        if (var_3 == 1) {
            if (*(u8 *)(arg0 + var_21 + 0x3F6) <= 1) {
                goto loop_31_increment;
            }
        }
        if ((*(u8 *)(arg0 + var_21 + 0x3F6) >= var_19) && (var_19 != 0)) {
            var_22 |= temp_16;
        } else if ((s32)datCalcRandomBelow(0x64) < var_20) {
            var_22 |= temp_16;
        }
    }
loop_31_increment:
    var_21 += 1;
loop_31_test:
    if (var_21 < 0x18U) {
        goto loop_31_body;
    }
    return var_22;
}
#pragma opt_propagation on
#pragma pop
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
s32 func_001f6bf0(u8 *arg0) {
    s32 i;
    s32 one;

    i = 0;
    one = 1;
    while ((u32)i < 0x18) {
        if ((one << i) == one) {
            return arg0[i + 0x3F6] >= 2;
        }
        i++;
    }
    return 1;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants on

// FUN_001F6C40
void func_001f6c40(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    s32 temp_4;
    u32 var_6;

    if (arg1 != 0) {
        temp_2 = datCalcGetBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
        var_6 = 0;
        goto loop_test_6;
loop_6:
        temp_4 = 1 << var_6;
        if ((arg1 & temp_4) && !(temp_2 & temp_4)) {
            *(s8 *)(arg0 + var_6 + 0x3F6) = 0;
        }
        var_6 += 1;
loop_test_6:
        if (var_6 < 0x18U) {
            goto loop_6;
        }
    }
}
// FUN_001F6CD0
void func_001f6cd0(u8 *arg0)
{
    s32 temp_2;
    u32 var_6;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_2 = datCalcGetBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
    var_6 = 0;
    goto loop_test_5;
loop_5:
    if ((temp_2 & (1 << var_6)) != 0) {
        temp_3 = arg0 + var_6;
        temp_4 = temp_3 + 0x3F6;
        temp_3_2 = *(u8 *)(temp_3 + 0x3F6);
        if ((s32)temp_3_2 < 0xFF) {
            *temp_4 = (u8)(temp_3_2 + 1);
        }
    }
    var_6 += 1;
loop_test_5:
    if (var_6 < 0x18U) {
        goto loop_5;
    }
}

// FUN_001F6D60
s16 func_001f6d60(u8 *arg0)
{
    u8 *temp_17;
    s16 var_16;
    s32 temp_16;
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    u16 temp_3;

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    var_16 = 0;
    temp_2 = datCalcGetBadStatusNoDown(temp_17);
    switch (temp_2) {
    case 0x20:
        temp_4 = datCalcMaxHp(temp_17) & 0xFFFF;
        if ((*(u16 *)temp_17 & 4) == 0) {
            var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
        } else {
            temp_3 = *(u16 *)(iGpffffb3c4 +
                              (*(u16 *)(temp_17 + 2) * 0x3C));
            if ((temp_3 & 0x400) != 0) {
                var_16 = -0x32;
            } else if ((temp_3 & 0x800) != 0) {
                var_16 = -0x64;
            } else {
                var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
            }
            if (var_16 > 0x3E7) {
                var_16 = 0x3E7;
            }
            }
        if (datCalcIsDead((s32)(temp_17), var_16) != 0) {
            var_16 = -((datCalcGetHp(temp_17) & 0xFFFF) - 1);
        }
        break;
    case 0x40:
        temp_16 = datCalcMaxSp(temp_17) & 0xFFFF;
        temp_4_2 = datCalcGetSp(temp_17) & 0xFFFF;
        var_16 = -((temp_16 & 0xFFFF) * 0x64) / 1000;
        if (temp_4_2 < var_16) {
            var_16 = temp_4_2;
        }
        break;
    default:
        break;
    }
    return var_16;
}

/* measured: opt_rebuildconditionals off probe for func_001f6f60 final branch. */
#pragma opt_rebuildconditionals off
// FUN_001F6F60
s32 func_001f6f60(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;
    u16 temp_3;
    u16 temp_3_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = datCalcGetBadStatusNoDown(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        if ((*(u8 *)(arg0 + 0x28) == 0) &&
            (*(u8 *)(arg0 + 0x29) == 0)) {
            var_17 = 0xC;
        }
        break;
    case 4:
        temp_3 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3) {
        case 6:
        case 12:
            var_17 = 8;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xA;
            break;
        default:
            break;
        }
        break;
    case 8:
        break;
    case 0x10:
        switch (*(u16 *)(arg0 + 0x6C)) {
        case 1:
            var_17 = 4;
            break;
        default:
            var_17 = 6;
            break;
        }
        break;
    case 0x100:
        temp_3_2 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3_2) {
        case 2:
        case 1:
            var_17 = 0xAA;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xAB;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_6f60;
        temp_18 = var_17;
        goto done_6f60;
    increment_6f60:
        temp_18 = var_17 + 1;
    done_6f60:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off preserves func_001f7140's positive flag branch. */
#pragma opt_rebuildconditionals off
// FUN_001F7140
s32 func_001f7140(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = datCalcGetBadStatusNoDown(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        var_17 = 0x2E;
        break;
    case 4:
        var_17 = 0x2C;
        break;
    case 8:
        var_17 = 0x34;
        break;
    case 0x10:
        var_17 = 0x2A;
        break;
    case 0x40:
        var_17 = 0x30;
        break;
    case 0x80:
        var_17 = 0x32;
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_7140;
        temp_18 = var_17;
        goto done_7140;
    increment_7140:
        temp_18 = var_17 + 1;
    done_7140:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f7140. */
#pragma opt_rebuildconditionals on
// FUN_001F7260
void func_001f7260(void)
{
    s32 offset;
    s32 empty;
    u16 i;
    u8 state;

    *(s16 *)(iGpffffb3ac + 0xAC8) = 5;
    empty = -1;
    *(s8 *)(iGpffffb3ac + 0xACA) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++) {
        offset = (u32)i * 6;
        *(s16 *)(iGpffffb3ac + offset + 0xACC) = empty;
        *(s16 *)(iGpffffb3ac + offset + 0xACE) = empty;
        *(s8 *)(iGpffffb3ac + offset + 0xAD0) = state;
    }
}
// measured: required for exact retail loop codegen in func_001f7260.
/* measured: optimization_level 1 required for exact func_001f72e0 codegen. */
#pragma optimization_level 1
/* measured: opt_loop_invariants off baseline for func_001f72e0. */
#pragma opt_loop_invariants off
// FUN_001F72E0
void func_001f72e0(void)
{
    s32 var_8;
    u8 *temp_3_4;
    u8 *temp_3_8;
    s32 temp_6;
    s32 index_8;
    s32 empty;
    s32 temp_3_5;

    {
        u8 *temp_3;
        u8 *temp_3_7;
        s32 temp_3_2;

        temp_3 = iGpffffb3ac;
        temp_3_7 = temp_3 + 0xACA;
        temp_3_2 = *(s8 *)temp_3_7;
        if (temp_3_2 >= 0) {
            temp_3_2 = temp_3_2 + 1;
            *(s8 *)temp_3_7 = (s8)temp_3_2;
            if ((s8)temp_3_2 >= 3) {
                *(s8 *)(iGpffffb3ac + 0xACA) = -1;
            }
        }
    }
    var_8 = 0;
    empty = -1;
    goto loop_test_8;
loop_8:
    temp_3_4 = iGpffffb3ac;
    index_8 = var_8 & 0xFFFF;
    temp_6 = index_8 * 6;
    temp_3_8 = temp_3_4 + temp_6;
    index_8 = (s32)(temp_3_8 + 0xAD0);
    temp_3_5 = *(s8 *)(temp_3_8 + 0xAD0);
    if (temp_3_5 >= 0) {
        temp_3_5 = temp_3_5 + 1;
        *(s8 *)index_8 = (s8)temp_3_5;
        if ((s8)temp_3_5 >= 3) {
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACC) = empty;
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACE) = empty;
            *(s8 *)(iGpffffb3ac + temp_6 + 0xAD0) = empty;
        }
    }
    var_8 = (var_8 + 1) & 0xFFFF;
loop_test_8:
    if ((var_8 & 0xFFFF) < 0x10) {
        goto loop_8;
    }
}
/* measured: restore optimization_level 2 after func_001f72e0. */
#pragma optimization_level 2
// FUN_001F73C0
void func_001f73c0(void)
{
}

/* Retail selectors 4/5/6 request tracks 5/6/4. Preserve block order:
 * the eleven resolved jump-table entries at 0x00747550 must also match. */
// FUN_001F73D0
void func_001f73d0(void)
{
    u16 temp_2;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x40) {
        temp_2 = *(u16 *)(*(u8 **)(temp_4 + 0xC68) + 8);
        temp_2 = *(u16 *)(iGpffffb414 + (temp_2 * 0x18) + 0x16);
        switch (temp_2) {
        case 2:
            func_0045a3e0(2, 1);
            break;
        case 3:
            func_0045a3e0(3, 1);
            break;
        case 6:
            func_0045a3e0(4, 1);
            break;
        case 4:
            func_0045a3e0(5, 1);
            break;
        case 5:
            func_0045a3e0(6, 1);
            break;
        case 7:
            func_0045a3e0(0x29, 1);
            break;
        case 8:
            func_0045a3e0(0x30, 1);
            break;
        case 9:
            func_0045a3e0(0x2F, 1);
            break;
        case 10:
            func_0045a3e0(0x2D, 1);
            break;
        default:
            func_0045a3e0(1, 1);
            break;
        }
    }
}
// FUN_001F75B0
void func_001f75b0(void)
{
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x40) != 0) {
        func_0045a9a0(1, 0);
        func_0045a9a0(2, 0);
        func_0045a9a0(3, 0);
        func_00459880();
    }
}

// FUN_001F7650
u8 *func_001f7650(u8 *arg0)
{
    u8 *var_2;
    u32 temp_3;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        if (func_00110d60((s16)func_001060b0()) & 1) {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20);
        } else {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20) + 0x6F60;
        }
        return var_2;
    }
    temp_3 = *(u16 *)(arg0 + 0xA4);
    if ((s32)temp_3 < 0x100) {
        return NULL;
    }
    if ((s32)temp_3 <= 0x112) {
        goto dispatch;
    }
    return NULL;
dispatch:
    if (temp_3 == 0x214) {
        goto return_214;
    } else if (temp_3 == 0x112) {
        goto return_group;
    } else if (temp_3 == 0x10E) {
        goto return_group;
    } else if (temp_3 == 0x10B) {
        goto return_group;
    } else if (temp_3 == 0x10A) {
        goto return_group;
    } else if (temp_3 == 0x109) {
        goto return_group;
    } else if (temp_3 == 0x108) {
        goto return_group;
    } else if (temp_3 == 0x107) {
        goto return_group;
    } else if (temp_3 == 0x106) {
        goto return_group;
    } else if (temp_3 == 0x105) {
        goto return_group;
    } else if (temp_3 == 0x104) {
        goto return_group;
    } else if (temp_3 == 0x103) {
        goto return_group;
    } else if (temp_3 == 0x102) {
        goto return_group;
    } else if (temp_3 == 0x101) {
        goto return_group;
    } else {
        switch (temp_3) {
        case 0x100:
            goto return_group;
        default:
            goto return_null;
        }
    }
return_group:
    return D_00618AC0 + ((temp_3 - 0x100) * 0xA20);
return_214:
    return D_0061F000;
return_null:
    var_2 = NULL;
    return var_2;
}
// FUN_001F7830
void func_001f7830(u8 *arg0, s32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)datCalcPrimaryPersonaId(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        switch (*(u16 *)(arg0 + 0xA4)) {
        case 7:
            if (arg2 != 0) {
                if (arg1 == 3) {
                    *arg3 = -1;
                    *arg4 = -1;
                    goto done;
                }
            }
        default:
            *arg3 = 0;
            *arg4 = *(s16 *)(D_00624B20 + (temp_5 * 4));
            goto done;
        }
    }
    *arg3 = -1;
    *arg4 = -1;
done:
    ;
}
// FUN_001F7910
void func_001f7910(u8 *arg0, u32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;
    u16 temp_4;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)datCalcPrimaryPersonaId(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        *arg3 = 0;
        temp_4 = *(u16 *)(arg0 + 0xA4);
        switch (temp_4) {
        case 4:
            if ((arg2 != 0) && (arg1 < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 6:
            if ((arg2 != 0) && ((u32)(arg1 - 1) < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 7:
            if ((arg2 != 0) && (arg1 == 3)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        default:
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        }
    }
    *arg3 = 0;
    switch (*(u16 *)(arg0 + 0xA4)) {
    case 0x109:
        *arg4 = 8;
        break;
    default:
        *arg4 = 0;
        break;
    }
}
// FUN_001F7AD0
void func_001f7ad0(u8 *arg0)
{
    u16 temp_7;
    u8 *temp_6;
    u32 offset;

    temp_7 = *(u16 *)arg0;
    offset = temp_7 * 6;
    temp_6 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_6 + 0xACC) != *(u16 *)(arg0 + 2)) ||
        (*(s16 *)(temp_6 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045aa90(1, (s16)temp_7);
    }
}
// FUN_001F7B40
s32 func_001f7b40(u8 *arg0)
{
    u16 temp_4;
    u16 temp_6;
    u8 *temp_3;
    u32 offset;

    temp_6 = *(u16 *)(arg0 + 2);
    temp_4 = *(u16 *)arg0;
    offset = temp_4 * 6;
    temp_3 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_3 + 0xACC) != temp_6) ||
        (*(s16 *)(temp_3 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045af60(1, (s16)temp_4, (s16)temp_6,
                      (s16)*(u16 *)(arg0 + 4));
        temp_6 = *(u16 *)(arg0 + 2);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACC) = temp_6;
        temp_6 = *(u16 *)(arg0 + 4);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACE) = temp_6;
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u8 *)((u8 *)offset + 0xAD0) = 0;
    }
    return 1;
}
// FUN_001F8380
s32 func_001f8380(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) |= 0x40;
    }
    return 1;
}
// FUN_001F83B0
u8 *func_001f83b0(u32 value)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8380;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
    return packet;
}

// FUN_001F8400
s32 func_001f8400(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) &= 0xFFBF;
    }
    return 1;
}
// FUN_001F8430
u8 *func_001f8430(u32 value)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8400;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
    return packet;
}

// FUN_001F8480
void func_001f8480(void)
{
    void **allocator;
    u8 sp30[0x100];
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;

    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    allocator = (void **)jtbl_008873E8;
    temp_17 = ((u8 *(*)(u32, u32))allocator[0])(0xBE4, 0x40000);
    sprintf(sp30, &D_00624F60);
    func_00456250(3, sp30, 0, temp_17);
    goto loop_3_test;
loop_3_retry:
    if (temp_2 != 4) {
        goto loop_3_test;
    }
    func_00456250(3, sp30, 0, temp_17);
loop_3_test:
    temp_2 = func_004c7ef8(3);
    if (temp_2 != 3) {
        goto loop_3_retry;
    }
    iGpffffb460 = 1;
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    temp_17_2 = ((u8 *(*)(u32, u32))allocator[0])(0x630, 0x40000);
    sprintf(sp30, &D_00624F80);
    func_00456250(4, sp30, 0, temp_17_2);
    goto loop_7_test;
loop_7_retry:
    if (temp_2_2 != 4) {
        goto loop_7_test;
    }
    func_00456250(4, sp30, 0, temp_17_2);
loop_7_test:
    temp_2_2 = func_004c7ef8(4);
    if (temp_2_2 != 3) {
        goto loop_7_retry;
    }
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    temp_16 = ((u8 *(*)(u32, u32))allocator[0])(0x4A0, 0x40000);
    sprintf(sp30, &D_00624FA0);
    func_00456250(5, sp30, 0, temp_16);
    goto loop_11_test;
loop_11_retry:
    if (temp_2_3 != 4) {
        goto loop_11_test;
    }
    func_00456250(5, sp30, 0, temp_16);
loop_11_test:
    temp_2_3 = func_004c7ef8(5);
    if (temp_2_3 != 3) {
        goto loop_11_retry;
    }
    iGpffffb464 = 1;
}
// FUN_001F8690
void func_001f8690(s32 arg0) {
    s32 value;
    u16 index;

    value = *(u16 *)(iGpffffb3ac + 0xB30);
    index = (u16)arg0;
    func_0045ae10(value, 3, index);
}
// FUN_001F86D0
void func_001f86d0(void) {
    func_0045aac0(3, 0, 8);
}
// FUN_001F8700
s32 func_001f8700(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(s32 *)(temp_4 + 0xA0C) == 0)
    {
        return -1;
    }
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return arg1 - 1;
    }
    temp_2 = datPersonaGetRecordId(*(u16 *)(temp_4 + 0xA4)) & 0xFFFF;
    switch (temp_2)
    {
    case 0xC0:
    case 0xC2:
    case 0xC4:
    case 0xC6:
    case 0xC8:
    case 0xCA:
    case 0xCC:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x22;
    case 0xC1:
    case 0xC3:
    case 0xC5:
    case 0xC7:
    case 0xC9:
    case 0xCB:
    case 0xCD:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x23;
    default:
        return -1;
    }
}
// FUN_001F8810
s32 func_001f8810(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return -1;
    }
    if (arg1 >= 5)
    {
        return -1;
    }
    if (datCalcIsDead((s32)((u8 *)*(s32 *)(temp_4 + 0xA64)), 0) != 0)
    {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x1001D7) != 0)
    {
        return -1;
    }
    return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] +
           (s32)D_00624FD8[arg1];
}
// FUN_001F8920
s32 func_001f8920(u8 *arg0)
{
    extern s32 func_0022bd20(void);
    s32 temp_16;
    s32 var_2;
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
            var_2 = -1;
        } else {
            temp_16 = (s32)D_00624FC0[*(u16 *)(temp_3 + 0xA4)] + 7;
            var_2 = temp_16 + datCalcRandomBelow(3);
        }
        return var_2;
    }
    if (func_0022bd20() == 0) {
        return -1;
    }
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 0x100:
        return datCalcRandomBelow(3) + 0x417;
    case 0x101:
        return datCalcRandomBelow(3) + 0x429;
    case 0x102:
        return datCalcRandomBelow(3) + 0x43C;
    case 0x103:
        return datCalcRandomBelow(3) + 0x44F;
    case 0x104:
        return datCalcRandomBelow(3) + 0x462;
    case 0x105:
        return datCalcRandomBelow(3) + 0x475;
    case 0x106:
        return datCalcRandomBelow(3) + 0x488;
    case 0x107:
        return datCalcRandomBelow(3) + 0x49B;
    case 0x108:
        return datCalcRandomBelow(3) + 0x4AE;
    case 0x109:
        return datCalcRandomBelow(3) + 0x4C3;
    case 0x112:
        return datCalcRandomBelow(3) + 0x4FC;
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x10F:
    case 0x110:
    case 0x111:
    default:
        return -1;
    }
}
// FUN_001F8B00
s32 func_001f8b00(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x78;
    return value + datCalcRandomBelow(5);
}
// FUN_001F8B90
s32 func_001f8b90(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x63;
    return value + datCalcRandomBelow(3);
}
// FUN_001F8C20
s32 func_001f8c20(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x6F;
        return value + datCalcRandomBelow(3);
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x72;
    return value + datCalcRandomBelow(3);
}
// FUN_001F8CE0
s32 func_001f8ce0(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x75;
    return value + datCalcRandomBelow(3);
}
// FUN_001F8D70
s32 func_001f8d70(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x2C;
    return value + datCalcRandomBelow(3);
}
// FUN_001F8E10
s32 func_001f8e10(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x29;
    return value + datCalcRandomBelow(3);
}
/* measured: opt_propagation off preserves func_001f8ea0's loop constants. */
#pragma opt_propagation off
// FUN_001F8EA0
s32 func_001f8ea0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x10;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
done:
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8ea0 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8f40's loop constants. */
#pragma opt_propagation off
// FUN_001F8F40
s32 func_001f8f40(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x16;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8f40 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8fe0's loop constants. */
#pragma opt_propagation off
// FUN_001F8FE0
s32 func_001f8fe0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x1C;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8fe0 probe. */
#pragma opt_propagation on
// FUN_001F9080
s32 func_001f9080(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    return D_00624FC0[*(u16 *)(p + 0xA4)] + 0x45;
}

/* measured: opt_propagation off tested for func_001f90e0; retains loop constants. */
#pragma opt_propagation off
// FUN_001F90E0
s32 func_001f90e0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    u8 *var_17;
    s32 var_16;
    s32 var_5;
    u32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *temp_4_2;
    u8 *sp60[12];

    if (func_0045af90(3) == 1) {
        return -1;
    }
    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(temp_3 + 0xA64), 0x110) != 0) {
        return -1;
    }
    var_16 = 0;
    var_17 = *(u8 **)(iGpffffb3ac + 0x178);
    while (var_17 != NULL) {
        if ((datCalcIsDead((s32)(*(u8 **)(var_17 + 0xA64)), 0) == 0) &&
            (datCalcChkBadStatus(*(s32 *)(var_17 + 0xA64), 0x1001D7) == 0) &&
            (*(u16 *)(var_17 + 0xA4) != 1) &&
            (var_17 != *(u8 **)(arg0 + 0x30))) {
            sp60[(u16)var_16] = var_17;
            var_16 = (u16)(var_16 + 1);
        }
        var_17 = *(u8 **)(var_17 + 0xA6C);
    }
    temp_4 = (u16)var_16;
    if (temp_4 == 0) {
        return -1;
    }
    temp_4_2 = sp60[datCalcRandomBelow(temp_4)];
    if (temp_4_2 == NULL) {
        return -1;
    }
    var_6 = 0x32;
    var_5 = 1;
    var_7 = 5;
    while (var_5 <= 8) {
        if (var_5 == *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
            break;
        }
        if ((var_5 != var_7) && (var_5 != *(u16 *)(temp_4_2 + 0xA4))) {
            var_6 += 3;
        }
        var_5 += 1;
    }
    temp_16 = var_6 + D_00624FC0[*(u16 *)(temp_4_2 + 0xA4)];
    return temp_16 + datCalcRandomBelow(3, var_5, var_6);
}
/* measured: close opt_propagation after func_001f90e0. */
#pragma opt_propagation on
// FUN_001F92C0
s32 func_001f92c0(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x51;
    return value + datCalcRandomBelow(3);
}
// FUN_001F93A0
s32 func_001f93a0(u8 *arg0)
{
    s32 type;
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    type = func_001ef720(2, 0x80000) & 0xFFFF;
    switch (type) {
    case 4:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x54;
        return value + datCalcRandomBelow(3);
    case 3:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x57;
        return value + datCalcRandomBelow(3);
    case 2:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5A;
        return value + datCalcRandomBelow(3);
    case 1:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5D;
        return value + datCalcRandomBelow(3);
    }
    return -1;
}
// FUN_001F9570
s32 func_001f9570(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x69;
    return value + datCalcRandomBelow(3);
}
// FUN_001F9650
s32 func_001f9650(u8 *arg0)
{
    s32 value;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x66;
    return value + datCalcRandomBelow(3);
}
// FUN_001F9750
s32 func_001f9750(s32 *arg0) {
    s32 r;

    if (arg0[1] == 0) {
        if (iGpffffb460 != 0) {
            arg0[0] = 0;
        }
        arg0[1] = 1;
    }
    if (arg0[0] == 0) {
        *(u16 *)(D_0076449C + 0xB2E) |= 1;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

// FUN_001F9800
s32 btlVoicePacketUpdate(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;

    if ((*(u16 *)(iGpffffb3ac + 0xB2E) & 1) == 0) {
        return 1;
    }
    temp_16 = *(u8 **)arg0;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        if ((temp_16 != NULL) &&
            ((*(u16 *)(temp_16 + 0x1A) & 1) == 0)) {
            return 1;
        }
        temp_2 = D_00624FF0[*(u16 *)(arg0 + 4)](
            temp_16, *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 0xC));
        if (temp_2 == -1) {
            return 1;
        }
        func_0045ae10(*(u16 *)(iGpffffb3ac + 0xB30), 3, (u16)temp_2);
        *(s32 *)(arg0 + 0x14) = 1;
        goto block_15_9800;
    }
    if (func_0045af90(3) != 1) {
        if ((*(u16 *)(arg0 + 0x10) & 1) == 0 && (temp_16 != NULL)) {
            temp_3 = *(u8 **)(temp_16 + 0x30);
            if ((*(s32 *)(temp_3 + 0x98) & 2) != 0) {
                *(u16 *)(temp_3 + 0x9D8) &= 0xFFEF;
                temp_3_2 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
                *(u16 *)(temp_3_2 + 0x2E0) |= 0x20;
            }
        }
        return 1;
    }
block_15_9800:
    if ((*(u16 *)(arg0 + 0x10) & 1) == 0 &&
        *(s32 *)(arg0 + 0x14) == 1 && (temp_16 != NULL)) {
        temp_3_3 = *(u8 **)(temp_16 + 0x30);
        if ((*(s32 *)(temp_3_3 + 0x98) & 2) != 0) {
            *(u16 *)(temp_3_3 + 0x9D8) |= 0x10;
            temp_3_4 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
            *(u16 *)(temp_3_4 + 0x2E0) &= 0xFFDF;
        }
    }
    return 0;
}
// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpffffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}

// FUN_001F9A90
void func_001f9a90(void) {
    func_0045aac0(1, 0, 8);
}
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
#pragma opt_propagation off
// FUN_001F9AC0
s32 btlVoiceIdPacketUpdate(u8 *arg0)
{
    s32 value;
    s32 code;
    s32 flag;

    if (*(s32 *)(arg0 + 4) == 0) {
        if (*(u16 *)(arg0 + 8) == 0) {
            value = 0x6C;
        } else {
            value = 0x69;
        }
        code = value & 0xFFFF;
        switch (code) {
        case 0x6C:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 5;
            break;
        case 0x69:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 4;
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0) = 0;
        *(s32 *)(arg0 + 4) = 1;
    }
    if (*(s32 *)(arg0 + 0) == 0) {
        goto return_one_a;
    }
    flag = (*(u16 *)(iGpffffb3ac + 0xB38) & 1) != 0;
    if (flag == 0) {
        goto return_zero;
    }
return_one_b:
    return 1;
return_one_a:
    return 1;
return_zero:
    return 0;
}
/* measured: close opt_propagation after btlVoiceIdPacketUpdate probe. */
#pragma opt_propagation on
// FUN_001F9BE0
void func_001f9be0(void)
{
}
// FUN_001F9BF0
void func_001f9bf0(void) {
    memset(iGpffffb3ac + 0xB2C, 0, 0x14);
    *(s16 *)(iGpffffb3ac + 0xB30) = 3;
    *(s16 *)(iGpffffb3ac + 0xB3A) = 0;
}
// FUN_001F9C40
void func_001f9c40(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB34) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB34));
        *(s32 *)(iGpffffb3ac + 0xB34) = 0;
        *(u16 *)(iGpffffb3ac + 0xB2E) &= 0xFFFE;
    }
    if (*(s32 *)(iGpffffb3ac + 0xB3C) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB3C));
        *(s32 *)(iGpffffb3ac + 0xB3C) = 0;
        *(u16 *)(iGpffffb3ac + 0xB38) &= 0xFFFE;
    }
}
// FUN_001F9CD0
void func_001f9cd0(void)
{
}
// FUN_001F9CE0
s32 func_001f9ce0(void)
{
    return 0;
}
// FUN_001FA660
s32 func_001fa660(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = iGpffffb3ac;
    if (*(u16 *)(base + 0xB7C) == 5) {
        return func_00120ee0(*(s32 *)(base + 0xB88));
    }
    if (H_Cdvd_IsFileLoaded(*(u8 **)(base + 0xB84)) != 0) {
        base = iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = *(u8 **)(base + 0xB84);
            *(u8 **)(iGpffffb3ac + 0xB80) =
                func_00484bb0(*(u8 **)(work + 0x110));
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        H_Cdvd_Destroy(*(u8 **)(iGpffffb3ac + 0xB84));
        *(u8 **)(iGpffffb3ac + 0xB84) = NULL;
        return 1;
    }
    return 0;
}
// FUN_001FA720
u8 *func_001fa720(const void *arg0) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC04, 0xA);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x68) = (void *)func_001fa490;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa660;
    memcpy(*(s32 **)(temp_2 + 0x78), (void *)arg0, 0xA);
    return temp_2;
}
// FUN_001FA7A0
s32 func_001fa7a0(s32 *arg0)
{
    extern void func_00120f00(s32 arg0);
    extern s32 func_004b1520(s32 arg0);
    extern s32 func_00481450(void);
    extern void func_00481440(void *arg0);
    extern void func_00485630(s32 arg0);
    extern void func_00485870(s32 arg0);
    extern void func_00485b20(s32 arg0);
    extern u8 D_005DC8CC[];
    void *temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xB7C) == 5) {
        temp_4_2 = *(s32 *)(temp_4 + 0xB88);
        if (temp_4_2 == 0) {
            return 1;
        }
        if (*arg0 == 0) {
            func_00120f00(temp_4_2);
        }
        goto block_12;
    }
    temp_4_3 = *(s32 *)(temp_4 + 0xB80);
    if (temp_4_3 == 0) {
        return 1;
    }
    if (func_004b1520(temp_4_3) == 0) {
        if (*arg0 == 0) {
            func_0045af60(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)func_00481450();
        func_00481440(&D_005DC8CC);
        func_00485630(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00485870(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00481440(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    func_00485b20(*(s32 *)(iGpffffb3ac + 0xB80));
    *(s32 *)(iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
}
// FUN_001FA8F0
void func_001fa8f0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC05, 4);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa7a0;
    *(s32 **)(*(u8 **)(temp_2 + 0x78)) = NULL;
}
// FUN_001FA940
s32 func_001fa940(void) {
    s32 temp_4;
    s32 temp_4_2;
    u8 *temp_3;

    temp_3 = D_0076449C;
    if (*(s32 *)(temp_3 + 0xB84) != 0) {
        *(s32 *)(temp_3 + 0xB4C) |= 2;
    } else {
        temp_4 = *(s32 *)(temp_3 + 0xB80);
        if (temp_4 != 0) {
            func_00485b20(temp_4);
            *(s32 *)(D_0076449C + 0xB80) = 0;
        }
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FA9C0
void func_001fa9c0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC06, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa940;
}
// FUN_001FAA00
s32 func_001faa00(void) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = *(s32 *)(D_0076449C + 0xB80);
    if (temp_4 != 0) {
        func_00486180(temp_4);
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FAA60
void func_001faa60(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC07, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001faa00;
}
// FUN_001FAAA0
s32 func_001faaa0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 0);
    }
    return 0;
}
// FUN_001FAAF0
s32 func_001faaf0(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(0);
    }
    return 0;
}
// FUN_001FAB40
s32 func_001fab40(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 1);
    }
    return 0;
}
// FUN_001FAB90
s32 func_001fab90(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(1);
    }
    return 0;
}
// FUN_001FABE0
s32 func_001fabe0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 2);
    }
    return 0;
}
// FUN_001FAC30
s32 func_001fac30(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(2);
    }
    return 0;
}
// FUN_001FAC80
s32 func_001fac80(u8 *arg0)
{
    u8 *base;

    base = iGpffffb3ac;
    if ((*(s32 *)(base + 0xC) & 0x200000) == 0) {
        goto return_zero;
    }
    if (func_0022bd00() == 0) {
        base = iGpffffb3ac;
        if (*(s32 *)(base + 0xB40) != 0) {
            ((void (*)(void *))(*(void **)(base + 0xB40)))(
                *(void **)(base + 0xB48));
            return 1;
        }
    }
    return func_0022bad0(arg0, 3);
return_zero:
    return 0;
}
// FUN_001FAD10
s32 func_001fad10(void)
{
    s32 (*callback)(s32);
    s32 result;
    u8 *base;

    result = 0;
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        if (func_0022bd00() == 0) {
            base = iGpffffb3ac;
            callback = *(s32 (**)(s32))(base + 0xB44);
            if (callback != NULL) {
                result = callback(*(s32 *)(base + 0xB48));
                if (result == 0) {
                    *(s32 *)(iGpffffb3ac + 0xB40) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB44) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB48) = 0;
                }
            }
        }
        if (result == 0) {
            result = func_0022bc80(3);
        }
    }
    return result;
}
// FUN_001FADC0
s32 func_001fadc0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 4);
    }
    return 0;
}
// FUN_001FAE10
s32 func_001fae10(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(4);
    }
    return 0;
}
// FUN_001FAE60
void func_001fae60(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}
// FUN_001FAE80
s32 func_001fae80(u8 *arg0, s32 arg1)
{
    extern void func_001d7c60(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3,
                              u32 arg4);
    u8 sp30[0x38];
    s32 temp_16;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_16 = arg1 * 0x28;
    temp_3 = (u8 *)((u32)iGpffffb3b8 + temp_16);
    if ((*(u8 *)temp_3 & 8) == 0) {
        return 0;
    }
    func_001d7c60(arg0, sp30,
                   *(u8 *)(temp_3 + 9),
                   *(u8 *)(temp_3 + 0xA),
                   *(u16 *)(temp_3 + 0xC));
    if (*(u16 *)(sp30 + 0x38) == 0) {
        return 2;
    }
    switch (*(u8 *)((u8 *)addOffsetFirst((u32)temp_16,
                                         (u32)iGpffffb3b8) + 0x24)) {
    case 2:
        if (btlCond_ESCAPE(arg0, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_001FAF70
s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 datCalcSkillEffectFlags(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
    s32 temp_18;
    u32 var_21;
    u32 var_20;
    s32 temp_19;
    s32 temp_2;
    s32 var_2;
    u32 var_18;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!( *(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_18 = *(s32 *)(temp_3 + 0x20);
    if ((temp_18 & 0x7F7FFFFF) && !(temp_18 & 0x80800000)) {
        var_21 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_19 = 1 << var_21;
        if (temp_18 & temp_19) {
            var_20 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask((u8 *)(
                    *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_20 * 4) + 0x38) +
                                      0x30) + 0xA64)),
                    temp_19) != 0) {
                var_20 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_20 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_20 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_21 += 1;
loop_outer_test:
        if (var_21 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_21 == 0x20) {
            if (temp_18 & 0x3000) {
                var_2 = 5;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    var_18 = 0;
    goto loop_24_test;
loop_24_body:
    temp_2 = datCalcSkillEffectFlags(
        arg1 & 0xFFFF,
        (u8 *)*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
        (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) +
                            0x30) + 0xA64),
        arg2);
    if (temp_2 != 0 && temp_2 != 0xFFFF) {
        var_18 += 1;
        goto loop_24_test;
    } else {
        goto loop_24_exit;
    }
loop_24_test:
    if (var_18 < *(u16 *)(arg0 + 0x6A)) {
        goto loop_24_body;
    }
loop_24_exit:
    if (var_18 == *(u16 *)(arg0 + 0x6A)) {
        return 4;
    }
    return 0;
}
// FUN_001FB170
s32 func_001fb170(s32 arg0) {
    u32 temp_2;

    temp_2 = arg0 & 0xFFFF;
    switch (temp_2) {
    case 2:
        return 0x8A;
    case 3:
        return 0x8B;
    case 4:
        return 0x8C;
    case 5:
        return 0x8D;
    case 6:
        return 0x8E;
    case 7:
        return 0x98;
    default:
        return 0;
    }
}
// FUN_001FB1F0
s32 func_001fb1f0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    u32 var_19;
    u32 var_18;
    s32 temp_17;
    s32 var_2;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7F7FFFFF) && !(temp_16 & 0x80800000)) {
        var_19 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_17 = 1 << var_19;
        if (temp_16 & temp_17) {
            var_18 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask((u8 *)(
                *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) + 0x30) + 0xA64)),
                temp_17) != 0) {
                var_18 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_18 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_18 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_19 += 1;
loop_outer_test:
        if (var_19 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_19 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
done:
        return 0;
}
/* measured: candidate object 284B/window 288B, normalized_diff 1. Committed at nd 1. */
// FUN_001FB360
s32 func_001fb360(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_5;
    s32 var_2;
    u32 var_17;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7C7FFFFF) && !(temp_16 & 0x83800000)) {
        var_17 = 0;
        goto loop_test;
loop_body:
        temp_5 = 1 << var_17;
        if (!(temp_16 & temp_5)) {
            goto loop_increment;
        }
        if (datCalcHasBuffMask((u8 *)(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64)),
                          temp_5) == 0) {
            goto loop_after_call;
        }
loop_increment:
        var_17 += 1;
loop_test:
        if (var_17 < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (var_17 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    return 0;
}
/* Matched: the textured colour-quad Im2D upload (four 0x40-byte vertices).
   Conventions follow the matched code1_004b func_004b2780 (640/448 display
   scales, D_008872FC_abs depth, raw-offset stores) and the (f32)(u32)
   byte-colour idiom.  Levers: `x = a + (-b) * c` contracts to
   adda.s/madd.s; staging each negation as its own local emits lui + neg.s
   instead of a folded negative constant; staging each display-field
   conversion in a float local puts the lwc1 before the divide; the
   float-first signature is ABI-identical to the draft's order and fixes
   the mov.s materialisation order.  The opt_propagation-off bracket is
   load-bearing: without it the D_00887300 base rematerialises per call
   and the frame shrinks from 0x1A0 to 0x190. */
#pragma push
#pragma opt_propagation off
// FUN_001FB480
void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 sx;
    f32 sy;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 z;
    f32 inv;
    f32 cx;
    f32 cy;
    f32 w320;
    f32 w224;
    f32 n320;
    f32 n224;
    f32 f;
    f32 g;
    BattleRenderStateFunction *base;
    u8 *cam;
    u8 *disp;
    extern u8 *func_00401b80(void);
    extern void (*D_00887310[])(u32 arg0, void *arg1, u32 arg2);
    extern f32 fGpffff82e8;
    extern f32 fGpffff82ec;

    cam = (u8 *)func_00457120();
    disp = func_00401b80();
    f = (f32)*(s32 *)(disp + 0xC);
    sx = 640.0f / f;
    g = (f32)*(s32 *)(disp + 0x10);
    sy = 448.0f / g;
    x1 = 640.0f;
    y1 = 448.0f;
    if (scale == 0.0f) {
        x0 = 0.0f;
        y0 = 0.0f;
    } else {
        w320 = 320.0f;
        n320 = -w320;
        cx = fGpffff82e8;
        x0 = cx + n320 * scale;
        w224 = 224.0f;
        n224 = -w224;
        cy = fGpffff82ec;
        y0 = cy + n224 * scale;
        x1 = cx + w320 * scale;
        y1 = cy + w224 * scale;
    }
    base = D_00887300;
    base[0](rwRENDERSTATESHADEMODE, (void *)2);
    base[0](rwRENDERSTATECULLMODE, (void *)1);
    base[0](rwRENDERSTATEFOGENABLE, (void *)0);
    base[0](rwRENDERSTATEZTESTENABLE, (void *)0);
    base[0](rwRENDERSTATEZWRITEENABLE, (void *)0);
    base[0](rwRENDERSTATETEXTUREFILTER, arg3);
    base[0](rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
    base[0](rwRENDERSTATETEXTURERASTER, disp);
    RpSkyRenderStateSet(2, (void *)arg1);
    RpSkyRenderStateSet(3, (void *)arg2);
    z = *(f32 *)D_008872FC_abs;
    inv = 1.0f / *(f32 *)(cam + 0x84);
    *(f32 *)(work.packet + 0x00) = x0;
    *(f32 *)(work.packet + 0x04) = y0;
    *(f32 *)(work.packet + 0x08) = z;
    *(f32 *)(work.packet + 0x20) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x24) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x28) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x2C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x18) = inv;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(f32 *)(work.packet + 0x40) = x0;
    *(f32 *)(work.packet + 0x44) = y1;
    *(f32 *)(work.packet + 0x48) = z;
    *(f32 *)(work.packet + 0x60) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x64) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x68) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x6C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x58) = inv;
    *(s32 *)(work.packet + 0x50) = 0;
    *(f32 *)(work.packet + 0x54) = sy;
    *(f32 *)(work.packet + 0x80) = x1;
    *(f32 *)(work.packet + 0x84) = y0;
    *(f32 *)(work.packet + 0x88) = z;
    *(f32 *)(work.packet + 0xA0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xA4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xA8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xAC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x98) = inv;
    *(f32 *)(work.packet + 0x90) = sx;
    *(s32 *)(work.packet + 0x94) = 0;
    *(f32 *)(work.packet + 0xC0) = x1;
    *(f32 *)(work.packet + 0xC4) = y1;
    *(f32 *)(work.packet + 0xC8) = z;
    *(f32 *)(work.packet + 0xE0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xE4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xE8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xEC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0xD8) = inv;
    *(f32 *)(work.packet + 0xD0) = sx;
    *(f32 *)(work.packet + 0xD4) = sy;
    D_00887310[0](4, work.packet, 4);
    base[0](1, 0);
}
#pragma pop
/* Native b210 -O2 recovery: 1620 bytes plus 12 zero tail bytes.
   The state table is addressed through uintptr_t so ordinary propagation
   retains its base while reloading each callback. Ordinary common-subexpression
   optimization gives both unsigned alpha conversions their retail temporaries.
   The radial draw takes depth before packed color in both owners.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001FBB50
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
s32 func_001fbb50(u8 *work) {
    void *savedStates[7];
    struct {
        union { s32 word; u8 bytes[4]; } radial;
        u8 screen[4];
    } colors;
    f32 fadeProgress;
    f32 layerScale;
    s32 result;
    u32 stateIndex;

    if (func_003e8120(func_00457120()) == 0) {
        return 0;
    }
    result = 0;
    for (stateIndex = 0; stateIndex < 7; stateIndex++) {
        u32 offset = stateIndex * sizeof(savedStates[0]);
        D_00887304[0](*(RwRenderState *)((u8 *)D_00625210 + offset), (u8 *)savedStates + offset);
    }
    work = *(u8 **)(work + 0x38);
    {
        u32 state = *work;
        switch (state) {
        case 0:
            break;
        case 1: {
            u32 countdown = D_0076455C;
            if (countdown == 0) {
                f32 square;
                uintptr_t stateInterface;

                D_0076455A++;
                fadeProgress = (f32)(u32)D_0076455A / 20.0f;
                /* Keep the table address; each draw state reloads its callback. */
                stateInterface = (uintptr_t)D_00887300;
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                RpSkyRenderStateSet(2, (void *)0x44);
                RpSkyRenderStateSet(3, (void *)0x31801);
                func_00489f80();
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                square = fadeProgress * fadeProgress;
                {
                    f32 progressCubed = fadeProgress * square;
                    f32 progressFourth = fadeProgress * progressCubed;
                    f32 progressFifth = fadeProgress * progressFourth;
                    f32 screenOpacity = 255.0f * (1.0f - fadeProgress * progressFifth);
                    u8 screenAlpha = (u8)screenOpacity;
                    colors.screen[3] = screenAlpha;
                }
                func_0045c870(colors.screen, 0);
                colors.radial.bytes[2] = colors.radial.bytes[1] = colors.radial.bytes[0] = 0xFF;
                {
                    f32 radialOpacity = 160.0f * (1.0f - square);
                    u8 radialAlpha = (u8)radialOpacity;
                    colors.radial.bytes[3] = radialAlpha;
                }
                layerScale = 1.5f * ((f32)(u32)D_0076455A / 20.0f);
                func_00457120();
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                RpSkyRenderStateSet(2, (void *)0x44);
                RpSkyRenderStateSet(3, (void *)0x31801);
                btlPanelDrawCircle(0, layerScale, layerScale, D_008872FC_abs[0], colors.radial.word);
                func_0048a000();
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x54, 0x31801, (u8 *)1);
                if ((s32)D_0076455A >= 0x14) {
                    *work = 3;
                }
                break;
            }
            D_0076455C = countdown - 1;
            /* Continue the waiting-state draw after decrementing. */
        }
        case 2: {
            if (iGpffffb469 == 0) {
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x44, 0x31801, (u8 *)1);
                if (*(u16 *)(work + 6) == 1) {
                    layerScale = D_007613E0;
                } else {
                    layerScale = D_007613E4;
                }
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                {
                    u8 alpha;

                    if (*(u16 *)(work + 6) == 1) {
                        alpha = 6;
                    } else {
                        alpha = 0x0A;
                    }
                    colors.screen[3] = alpha;
                }
                func_001fb480(layerScale, colors.screen, 0x44, 0x31801, (u8 *)2);
                colors.screen[3] = 5;
                func_001fb480(layerScale, colors.screen, 0x48, 0x31801, (u8 *)2);
            }
            break;
        }
        case 3: {
            if (func_00122720() != 0) {
                func_00122640(1, 0x1E);
                iGpffffb468 = 0;
                result = -1;
            }
            break;
        }
        default:
            break;
        }
        {
            u32 k;

            for (k = 0; k < 7; k++) {
                u32 offset = k * sizeof(savedStates[0]);
                D_00887300[0](*(RwRenderState *)((u8 *)D_00625210 + offset), *(void **)((u8 *)savedStates + offset));
            }
        }
        D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        func_003e8110(func_00457120());
    }
    return result;
}
#pragma pop
// FUN_001FC1B0
void func_001fc1b0(s16 arg0) {
    if (kwlnTaskGetTaskByName(&D_006251F0) == 0) {
        iGpffffb468 = 2;
        iGpffffb46e = arg0;
        iGpffffb469 = 0;
        (s32)kwlnTaskCreate((const void *)(&D_006251F0), 0xC9, 0, 0, func_001fbb50, 0, (u8 *)((void *)&iGpffffb468));
    }
}
// FUN_001FC270
s32 func_001fc270(void)
{
    return 1;
}
// FUN_001FC280
void func_001fc280(void) {
    iGpffffb469 = 1;
    func_00122520(1, 1);
    H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
}
