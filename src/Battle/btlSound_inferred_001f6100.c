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
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBadStatus(s32 arg0);
extern u8 *iGpffffb3c4;
extern s32 datCalcGetHp(u8 *arg0);
extern s32 datCalcGetSp(u8 *arg0);
extern s32 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern s32 datCalcGetBadStatusNoDown(u8 *arg0);
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void btlSoundCancelPlayback();
extern void btlActionStepMessagePhase();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);

extern void memset(void *destination, s32 value, u32 size);


extern u32 datCalcRandomBelow();
extern u8 D_0060AB08[];
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
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
extern s32 btlSoundLoadPlaybackFile(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];

extern void H_Cdvd_Destroy(u8 *arg0);
extern void fclMiscSetDoneFlag(void);

extern void fclMiscPruneGlobal(void);
extern void fclMiscStopAndClose(void);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);

extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];



extern u8 *btlPacketAlloc(s32 type, s32 workSize);




extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

extern s32 func_001f0950(s32 arg0, s32 arg1);



#pragma push
#pragma pop






/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f6100-001f73d0 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
struct EffRandState;
static inline s32 battleMessageBand(s32 value, s32 band)
{
    return value + band;
}
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_001F6100
void btlSoundResetPlaybackState(void)
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
void btlSoundStepMessagePhase(void)
{
    btlActionStepMessagePhase();
}

// FUN_001F61B0
void btlSoundStopAndReleaseHandle(void)
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
    fclMiscSetDoneFlag();
}

// FUN_001F6220
s32 btlSoundRequestPlayback(s16 arg0, s32 arg1)
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
s32 btlSoundIsPlaybackActive(void) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA4E) & 1) != 0);
}

// FUN_001F62B0
void btlSoundCancelPlayback(void) {
    u8 *temp_4;

    fclMiscPruneGlobal();
    fclMiscStopAndClose();
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    temp_4 = iGpffffb3ac;
    *(u16 *)(temp_4 + 0xA4E) &= 0xFFFE;
}

// FUN_001F62F0
s32 btlSoundPickResistVoice(u8 *arg0)
{
    extern s32 datCalcGetLevel(u8 *arg0);
    extern s32 datCalcGetAffinity(u8 *arg0, s32 arg1);
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
            flags = datCalcGetAffinity(*(u8 **)(arg0 + 0xA64), code);
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
s32 btlSoundLoadPlaybackFile(u8 *arg0)
{
    extern void fclMiscOrStateFlags(u32 arg0);
    extern void func_00440b68();
    extern s32 H_Cdvd_AcquireDirectory();
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
            H_Cdvd_AcquireDirectory(
                *(u8 **)((u8 *)&iGpffffa4e0 +
                         (*(u16 *)(arg0 + 4) * 4)),
                0);
        *(u16 *)(arg0 + 6) = 2;
        goto block_14;
    case 2:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(iGpffffb3ac + 0xA54)) != 0) {
    case 3:
            fclMiscOrStateFlags(
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
u8 *btlSoundCreateLoadPlaybackPacket(s32 arg0) {
    u8 *p;
    u8 *q;

    p = (u8 *)btlPacketAlloc(0x803, 8);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)btlSoundLoadPlaybackFile;
    q = *(u8 **)(p + 0x78);
    *(s16 *)(q + 4) = (s16)arg0;
    *(s16 *)(q + 6) = 0;
    return p;
}

/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: btlSoundRollStatusCure MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001F6770
s32 btlSoundRollStatusCure(u8 *arg0)
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

/* measured: close opt_loop_invariants after btlSoundRollStatusCure. */
/* measured: btlSoundSelectCureableStatuses MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
// FUN_001F68E0
s32 btlSoundCanReceiveStatus(u8 *arg0)
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

#pragma push
/* measured: btlSoundSelectCureableStatuses MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001F6930
s32 btlSoundSelectCureableStatuses(u8 *arg0)
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

#pragma pop
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: btlSoundIsStatusCounterHigh MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 btlSoundIsStatusCounterHigh(u8 *arg0) {
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
// FUN_001F6C40
void btlSoundClearStatusCounters(u8 *arg0, s32 arg1)
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
void btlSoundBumpStatusCounters(u8 *arg0)
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
s16 btlSoundCalcStatusHpSpDelta(u8 *arg0)
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

/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: btlSoundPickStatusTalkVoiceA MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001F6F60
s32 btlSoundPickStatusTalkVoiceA(u8 *arg0)
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

/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
// FUN_001F7140
s32 btlSoundPickStatusTalkVoiceB(u8 *arg0)
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

/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
// FUN_001F7260
void btlSoundResetSlotQueue(void)
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

// measured: required for exact retail loop codegen in btlSoundResetSlotQueue.
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: btlSoundAdvanceSlotQueue MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
// FUN_001F72E0
void btlSoundAdvanceSlotQueue(void)
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

/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
/* measured: btlSoundPlayRetailSelectTrack MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001F73C0
void func_001f73c0(void)
{
}

/* Retail selectors 4/5/6 request tracks 5/6/4. Preserve block order:
 * the eleven resolved jump-table entries at 0x00747550 must also match. */
// FUN_001F73D0
void btlSoundPlayRetailSelectTrack(void)
{
    u16 temp_2;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x40) {
        temp_2 = *(u16 *)(*(u8 **)(temp_4 + 0xC68) + 8);
        temp_2 = *(u16 *)(iGpffffb414 + (temp_2 * 0x18) + 0x16);
        switch (temp_2) {
        case 2:
            sdkSndPlayCue(2, 1);
            break;
        case 3:
            sdkSndPlayCue(3, 1);
            break;
        case 6:
            sdkSndPlayCue(4, 1);
            break;
        case 4:
            sdkSndPlayCue(5, 1);
            break;
        case 5:
            sdkSndPlayCue(6, 1);
            break;
        case 7:
            sdkSndPlayCue(0x29, 1);
            break;
        case 8:
            sdkSndPlayCue(0x30, 1);
            break;
        case 9:
            sdkSndPlayCue(0x2F, 1);
            break;
        case 10:
            sdkSndPlayCue(0x2D, 1);
            break;
        default:
            sdkSndPlayCue(1, 1);
            break;
        }
    }
}

