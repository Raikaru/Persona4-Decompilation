/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0021dda0-0021ec40 */

#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "datPersona_internal.h"
typedef struct PersonaWork PersonaWork;

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb414;
extern f32 *iGpffffb40c;
extern u8 *datUnitGetRecord(s16 arg0);
extern u32 datPersonaGetExpById(s16 arg0);
extern void datSetHeroExp(s16 arg0, u32 value);
extern u8 datLevelFromExp(s32 arg0);
extern s32 datAddMoney(s32 arg0);
extern s32 datItemCount(s16 id);
extern void datCalcSetLevel(u8 *arg0, u8 arg1);
extern u32 datGetFlag(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290D0[];
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);
extern s32 kwlnTaskGetTaskByName(void *arg0);
extern u8 D_006290E0[];
extern void btlShuffleDrawSweep(s32 arg0, s32 *arg1);
extern void btlShuffleDestroyOverlayWork(u8 *task);
extern s32 datPersonaCanLevelUp(PersonaWork *arg0);
extern void datPersonaApplyLevelUp(u8 *arg0, u8 *arg1);
extern s32 btlShuffleTickFrame(u8 *task);
extern void btlXpPrepareAwards(u8 *arg0, u8 *arg1);
extern void btlXpApplyAwards(u8 *arg0, u8 *arg1);
extern void btlXpAddRosterExp(u8 *arg0);
extern void btlXpAddPartyExp(s32 arg0);
#pragma push
#pragma opt_loop_invariants off
// Intent: start the shuffle overlay task if it is not already running. [inferred]
// FUN_0021DDA0
void btlShuffleStartOverlay(void)
{
    u8 *work;

    if (kwlnTaskGetTaskByName(&D_006290E0) == 0) {
        chkmemAllocSiteTag(&D_006290D0, 0x3A);
        work = (u8 *)jtbl_008873E8[0](0x34, 0x40000);
        memset(work, 0, 0x34);
        (s32)kwlnTaskCreate((const void *)(&D_006290E0), 0x10, 0, 0, btlShuffleTickFrame, btlShuffleDestroyOverlayWork, (u8 *)(work));
        *(void **)(work + 0xC) = (void *)btlShuffleDrawSweep;
        *(u8 **)(work + 0x14) = work;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: report whether the shuffle overlay task has finished. [inferred]
// FUN_0021DE60
s32 btlShuffleOverlayIdle(void)
{
    return kwlnTaskGetTaskByName(&D_006290E0) == 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: compute an XP award for one persona from its level scaling and the award flags. [inferred]
// FUN_0021DE90
#pragma push
#pragma opt_propagation off
s32 btlXpComputeAward(s32 arg0, u8 *arg1)
{
    s32 value;
    u32 result;
    f32 scale;
    f32 table_value;
    s32 delta;
    s32 index;

    value = *(s32 *)(arg1 + 4);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg1 & 8) == 0 && datGetFlag(0x1403) != 0) {
        if (datGetFlag(0x1428) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (datGetFlag(0x1429) != 0) {
            value = 0;
        }
    }
    scale = 1.0f / (f32)*(s32 *)(arg1 + 0x20);
    if ((*(s32 *)(iGpffffb414 + (*(s32 *)(arg1 + 0xC) * 0x18)) & 0x80) != 0) {
        result = (s32)((f32)value * scale);
    } else {
        delta = *(s32 *)(arg1 + 0x38) - arg0;
        if (delta >= 10) {
            index = 20;
        } else if (delta < -9) {
            index = 0;
        } else {
            index = delta + 10;
        }
        table_value = iGpffffb40c[index];
        result = (s32)(scale * ((f32)value * table_value));
    }
    if ((s32)result <= 0xFFFF) {
        goto normal_result;
    }
    result = 0xFFFF;
    goto finish;
normal_result:
    if ((s32)result > 0) {
        goto finish;
    }
    result = 1;
finish:

    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: return the base XP award for one persona after the award flags. [inferred]
// FUN_0021E050
s32 btlXpBaseAward(u8 *arg0)
{
    s32 value;

    value = *(s32 *)(arg0 + 8);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg0 & 8) == 0 && (datGetFlag(0x1403) != 0)) {
        if (datGetFlag(0x1420) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (datGetFlag(0x1421) != 0) {
            value = 1;
        }
    }
    return value;
}
#pragma pop

extern s32 datCalcGetLevelById(s32 arg0);
extern u8 datPersonaGetLevel(int persona);
extern u32 datPersonaGetExp(int persona);
extern u16 datItemValue(s16 arg0);
extern s16 datGetEquippedItemByUnit(s16 arg0, s16 arg1);
#pragma push
#pragma opt_loop_invariants on
// Intent: prepare the XP award blocks for the leader and the party without applying them. [inferred]
// FUN_0021E110
void btlXpPrepareAwards(u8 *arg0, u8 *arg1)
{
    s32 i;
    s32 j;
    s32 out;
    s32 level;
    s32 base;
    s32 lv;
    s32 lv2;
    s32 lv3;
    s32 level2;
    s32 v6;
    s32 v7;
    u16 *entry3;

    s32 sum;
    s32 count;
    s32 count2;
    s32 id;
    s32 id2;
    s32 v;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 k;
    u8 c;
    u16 *entry;
    u16 *entry2;
    s32 ref;

    memset(arg0, 0, 0x8D4);
    out = 0;
    if (*(u16 *)arg1 & 1) {
        *(u32 *)arg0 |= 1;
    }
    c = datCalcGetLevelById(1) & 0xFF;
    level = btlXpComputeAward(c, arg1);
    base = level;
    if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
        level += (s32)(0.5f * (f32)level);
    }
    if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
        level += (s32)(0.5f * (f32)base);
    }
    if (c != (datLevelFromExp(level + datPersonaGetExpById(1)) & 0xFF)) {
        *(u32 *)arg0 |= 2;
    }
    *(s16 *)(arg0 + 0x698) = *(s16 *)(arg1 + 0x10);
    *(u32 *)(arg0 + 4) = level;
    entry = (u16 *)datPersonaGetRecord(1);
    datUnitGetRecord(1);
    ref = entry[1];
    count = datPersonaCountValidMembers() & 0xFFFF;
    for (i = 0; i < count; i++) {
        entry2 = (u16 *)datPersonaRosterSlot((s16)i);
        id = datPersonaGetLevel((s32)entry2) & 0xFF;
        lv = btlXpComputeAward(id, arg1);
        if (entry2[1] == ref) {
            level = lv;
            if (datPersonaLeadBoosted(1) != 0) {
                level += (s32)(0.5f * (f32)lv);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
                level += (s32)(0.5f * (f32)lv);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
                level += (s32)(0.5f * (f32)lv);
            }
        } else {
            v = (s32)datPersonaGetSkills((struct DatPersonaRecord *)entry2);
            level = 0;
            for (k = 0; k < 8; k++) {
                v2 = *(u16 *)(v + k * 2);
                if (v2 != 0) {
                    switch (v2) {
                    case 0x1FF:
                        level += (s32)(0.25f * (f32)lv);
                        break;
                    case 0x200:
                        level += (s32)(0.5f * (f32)lv);
                        break;
                    case 0x201:
                        level += (s32)(f32)lv;
                        break;
                    }
                }
            }
            sum = level;
            if (entry2[0] & 4) {
                level += (s32)(0.5f * (f32)level);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
                level += (s32)(0.5f * (f32)sum);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
                level += (s32)(0.5f * (f32)sum);
            }
        }
        if (id < 99) {
            v3 = datPersonaGetExp((s32)entry2);
            v4 = (s32)datPersonaGetExpForLevel(entry2, (u16)(id + 1));
            if (v4 <= v3 + level) {
                *(u32 *)arg0 |= 8;
                datPersonaPreviewLevelUp((u8 *)entry2, arg0 + i * 0x88 + 0x38, level);
            }
            if (level != 0) {
                *(u32 *)(arg0 + i * 4 + 8) = level;
            }
        }
    }
    count2 = *(s32 *)(arg1 + 0x1C);
    for (j = 0; j < count2; j++) {
        id2 = *(u16 *)(arg1 + j * 2 + 0x12);
        if (id2 != 1) {
            entry3 = (u16 *)datPersonaGetRecord((u16)id2);
            v5 = datPersonaGetLevel((s32)entry3) & 0xFF;
            lv2 = btlXpComputeAward(v5, arg1);
            level2 = lv2;
            if (datItemValue(datGetEquippedItemByUnit((s16)id2, 0)) == 0x86) {
                level2 += (s32)(0.5f * (f32)lv2);
            }
            if (datItemValue(datGetEquippedItemByUnit((s16)id2, 1)) == 0x86) {
                level2 += (s32)(0.5f * (f32)lv2);
            }
            if (v5 < 99) {
                v3 = datPersonaGetExp((s32)entry3);
                v4 = (s32)datPersonaGetExpForLevel(entry3, (u16)(v5 + 1));
                if (v4 <= v3 + level2) {
                    *(u32 *)arg0 |= 0x10;
                    datPersonaPreviewLevelUp((u8 *)entry3, arg0 + out * 0x88 + 0x6B4, level2);
                }
                *(u32 *)(arg0 + out * 4 + 0x6A4) = level2;
            }
            *(u16 *)(arg0 + out * 2 + 0x69A) = id2;
            out += 1;
        }
    }
    if (datGetFlag(0x38) != 0) {
        entry3 = (u16 *)datPersonaGetRecord(5);
        v5 = datPersonaGetLevel((s32)entry3) & 0xFF;
        lv3 = btlXpComputeAward(v5, arg1);
        level2 = lv3;
        if (datItemValue(datGetEquippedItemByUnit(5, 0)) == 0x86) {
            level2 += (s32)(0.5f * (f32)lv3);
        }
        if (datItemValue(datGetEquippedItemByUnit(5, 1)) == 0x86) {
            level2 += (s32)(0.5f * (f32)lv3);
        }
        if (v5 < 99) {
            v3 = datPersonaGetExp((s32)entry3);
            v4 = (s32)datPersonaGetExpForLevel(entry3, (u16)(v5 + 1));
            if (v4 <= v3 + level2) {
                *(u32 *)arg0 |= 0x10;
                datPersonaPreviewLevelUp((u8 *)entry3, arg0 + out * 0x88 + 0x6B4, level2);
            }
            v6 = out * 4;
            *(u32 *)(v6 + (s32)arg0 + 0x6A4) = level2;
        }
        v7 = out * 2;
        *(u16 *)(v7 + (s32)arg0 + 0x69A) = 5;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: apply the prepared level and skill-point awards to the leader and party. [inferred]
// FUN_0021E9A0
void btlXpApplyAwards(u8 *arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 var_16;
    s32 var_17;
    u8 *temp_19;
    u8 *temp_20;
    s32 temp_21;
    s16 sum;
    temp_17 = (s32)datUnitGetRecord(1);
    temp_2 = (s32)datPersonaGetExpById(1);
    if ((datLevelFromExp(temp_2) & 0xFF) < 0x63) {
        temp_16 = temp_2 + *(s32 *)(arg0 + 4);
        datSetHeroExp(1, temp_16);
        datCalcSetLevel((u8 *)temp_17, datLevelFromExp(temp_16));
    }
    var_16 = *(s32 *)(arg1 + 8);
    if (var_16 <= 0) {
        var_16 = 0;
    } else if ((*(u16 *)arg1 & 8) == 0 && datGetFlag(0x1403) != 0) {
        if (datGetFlag(0x1420) != 0) {
            var_16 = (s32)(2.0f * (f32)var_16);
        } else if (datGetFlag(0x1421) != 0) {
            var_16 = 1;
        }
    }
    datAddMoney(var_16);
    var_17 = 0;
    while (var_17 < *(s32 *)(arg1 + 0x30)) {
        temp_19 = arg1 + var_17 * 4;
        temp_20 = temp_19 + 0x24;
        temp_21 = (s16)(datItemCount(*(s16 *)(temp_19 + 0x24)) & 0xFF);
        sum = temp_21 + *(s16 *)(temp_19 + 0x26);
        if (sum > 0x63) {
            sum = 0x63;
        }
        datItemSetCount((s32)*(s16 *)temp_20, (u8)sum);
        var_17 += 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: add prepared experience to each roster member and apply any level-ups. [inferred]
// FUN_0021EB60
void btlXpAddRosterExp(u8 *arg0)
{
    s32 limit;
    s32 value;
    u8 *persona;
    s32 i;

    limit = datPersonaCountValidMembers() & 0xFFFF;
    i = 0;
    while (i < limit) {
        value = *(s32 *)(arg0 + (i * 4) + 8);
        if (value != 0) {
            persona = (u8 *)datPersonaRosterSlot((s16)i);
            datPersonaAddExp((DatPersonaRecord *)persona, value);
            if (datPersonaCanLevelUp((PersonaWork *)persona) != 0) {
                datPersonaApplyLevelUp(persona, arg0 + (i * 0x88) + 0x38);
            }
        }
        i += 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: add prepared experience to the four party slots and apply any level-ups. [inferred]
// FUN_0021EC40
void btlXpAddPartyExp(s32 arg0)
{
    s32 temp_2;
    s32 temp_19;
    s32 var_16;

    var_16 = 0;
    goto loop_test;
loop_body:
    temp_19 = *(s32 *)((u8 *)arg0 + (var_16 * 4) + 0x6A4);
    if (temp_19 != 0) {
        temp_2 = (s32)datPersonaGetRecord(*(u16 *)((u8 *)arg0 + (var_16 * 2) + 0x69A));
        datPersonaAddExp((DatPersonaRecord *)temp_2, temp_19);
        if (datPersonaCanLevelUp((PersonaWork *)temp_2) != 0) {
            datPersonaApplyLevelUp((u8 *)temp_2,
                          (u8 *)arg0 + (var_16 * 0x88) + 0x6B4);
        }
    }
    var_16 += 1;
loop_test:
    if (var_16 < 4) {
        goto loop_body;
    }
}
#pragma pop
