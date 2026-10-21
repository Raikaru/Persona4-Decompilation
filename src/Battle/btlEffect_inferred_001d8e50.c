#include "member_access.h"
#include "dat_skill_entry_internal.h"
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

extern u16 datCalcMaxHp(u8 *unit);
extern u16 datCalcMaxSp(u8 *unit);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern u16 datCalcGetHp(u8 *unit);
extern u16 datCalcGetSp(u8 *unit);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;
extern void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u32 sideFlags, u32 filterFlags, u32 statusMask);

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();


extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* measured: opt_propagation off keeps the loop masks in btlCameraFindFormationForCounts as retail
 * computes them. */
#pragma push
#pragma pop
/* measured: optimization_level 1 keeps retail's stack reload scheduling in func_001d5990. */
#pragma push
#pragma pop
/* measured: opt_propagation off keeps retail's default GP load/store register order. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Prefer status/buff-relevant targets, then choose a damaged HP or SP candidate according to the skill parameters. */
// FUN_001D8E50
void btlEffectSelectTargetByStatus(u8 *action, u8 *selection)
{
    BtlTargetSelection *selectionFields = (BtlTargetSelection *)selection;
    BtlUnit *workFields;
    u16 best_value1;
    s16 best_index1;
    u16 best_value2;
    s16 best_index2;
    s32 index;
    u32 offset;
    s32 target;
    u16 value;
    u16 alternate;
    u8 *work;

    if (((BtlTargetSelection *)(selection))->count <= 1)
        return;
    switch (((BtlAction *)(action))->unk_6c) {
    case 2:
        goto mode_valid;
    default:
        switch (((BtlAction *)(action))->unk_6c) {
        case 3:
            goto mode_valid;
        default:
            switch (((BtlAction *)(action))->unk_6c) {
            case 1:
                goto mode_valid;
            default:
                goto mode_done;
            }
        }
    }

mode_valid:

        offset = (u32)((BtlAction *)(action))->unk_6e * 0x28;
        {
            u8 *entry;
            entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
            if (entry[8] != 0)
                return;

            if (entry[0x18] == 2) {
            target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + MEMBER_OFFSET(DatSkillEntry, statusMask)) + offset);
            if (target != 0) {
                index = 0;
                while ((u16)index < selectionFields->count) {
                    if ((u8 *)((BtlAction *)(action))->unit ==
                        (u8 *)((BtlAction *)(selectionFields->entries[(u32)(u16)index]))->unit &&
                        datCalcChkBadStatus(
                            (s32)(u8 *)((BtlUnit *)((u8 *)((BtlAction *)(selectionFields->entries[(u32)(u16)index]))->unit))->datUnit,
                            target) != 0) {
                        ((BtlTargetSelection *)(selection))->selected = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }

                index = 0;
                while ((u16)index < selectionFields->count) {
                    if (datCalcChkBadStatus(
                            (s32)(u8 *)((BtlUnit *)((u8 *)((BtlAction *)(((BtlTargetSelection *)(selection))->entries[(u32)(u16)index]))->unit))->datUnit,
                            target) != 0) {
                        ((BtlTargetSelection *)(selection))->selected = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }
            }
        }
        }

        target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + MEMBER_OFFSET(DatSkillEntry, buffMask)) + offset);
        if (target != 0) {
            index = 0;
            while ((u16)index < selectionFields->count) {
                if (datCalcHasBuffMask(
                        (DatUnit *)((BtlAction *)((BtlTargetSelection *)(selection))->entries[(u32)(u16)index])->unit->datUnit,
                        target) == 0) {
                    ((BtlTargetSelection *)(selection))->selected = (u16)index;
                    return;
                }
                index = (index + 1) & 0xFFFF;
            }
        }

        switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->effectKind) {
        case 15:
            goto mode1_select;
        default:
            switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->effectKind) {
            case 11:
                goto mode1_select;
            default:
                switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->effectKind) {
                case 9:
                    goto mode1_select;
                default:
                    switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->effectKind) {
                    case 5:
                        goto mode1_select;
                    default:
                        switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->effectKind) {
                        case 2:
                            goto mode1_select;
                        default:
                            goto mode2_check;
                        }
                    }
                }
            }
        }

mode1_select:
        {
            best_value1 = 0xFFFF;
            best_index1 = -1;
            index = 0;
            while ((u16)index < selectionFields->count) {
                work = (u8 *)((BtlAction *)(((BtlTargetSelection *)(selection))->entries[(u32)(u16)index]))->unit;
                workFields = (BtlUnit *)work;
                value = datCalcGetHp((u8 *)((BtlUnit *)(work))->datUnit);
                alternate = datCalcMaxHp((u8 *)workFields->datUnit);
                if (value < best_value1 && value < alternate) {
                    best_value1 = value;
                    best_index1 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index1 != -1) {
                ((BtlTargetSelection *)(selection))->selected = (u16)best_index1;
                return;
            }
        }

mode2_check:
        switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->spEffectKind) {
        case 15:
            goto mode2_select;
        default:
            switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->spEffectKind) {
            case 11:
                goto mode2_select;
            default:
                switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->spEffectKind) {
                case 9:
                    goto mode2_select;
                default:
                    switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->spEffectKind) {
                    case 5:
                        goto mode2_select;
                    default:
                        switch (((DatSkillEntry *)((u8 *)((u32)offset + (u32)iGpffffb3b8)))->spEffectKind) {
                        case 2:
                            goto mode2_select;
                        default:
                            goto mode_done;
                        }
                    }
                }
            }
        }

mode2_select:
        {
            best_value2 = 0xFFFF;
            best_index2 = -1;
            index = 0;
            while ((u16)index < selectionFields->count) {
                work = (u8 *)((BtlAction *)(((BtlTargetSelection *)(selection))->entries[(u32)(u16)index]))->unit;
                workFields = (BtlUnit *)work;
                value = datCalcGetSp((u8 *)((BtlUnit *)(work))->datUnit);
                alternate = datCalcMaxSp((u8 *)workFields->datUnit);
                if (value < best_value2 && value < alternate) {
                    best_value2 = value;
                    best_index2 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index2 != -1)
                ((BtlTargetSelection *)(selection))->selected = (u16)best_index2;
        }

mode_done:
    return;
}

/* Find an active action with the requested character ID, genus mask and excluded-status mask. */
// FUN_001D9280
u8 *btlEffectFindUnitByIdAndStatus(s32 unitId, s32 sideMask, s32 statusMask) {
    s32 work_flags;
    u8 *unit;
    u8 *work;
    u16 flags;
    u32 mask;
    u32 filter;
    s32 id;

    work_flags = statusMask;
    unit = ((BtlBattleState *)iGpffffb3ac)->actions;
    mask = (u16)sideMask;
    filter = work_flags & 0x80000;
    id = (u16)unitId;
    goto next_branch;
loop:
    flags = ((BtlAction *)unit)->unk_1a;
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = (u8 *)((BtlAction *)unit)->unit;
            if ((mask & (1 << ((BtlUnit *)work)->genus)) != 0) {
                if (filter != 0) {
                    if (datCalcIsDead((u8 *)((BtlUnit *)work)->datUnit, 0) != 0) {
                        goto next;
                    }
                }
                if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)work)->datUnit, work_flags) != 0) {
                    goto next;
                }
                if (((BtlUnit *)work)->charId == id) {
                    return unit;
                }
            }
        }
    }
next:
    unit = (u8 *)((BtlAction *)unit)->next;
next_branch:
    if (unit != NULL) {
        goto loop;
    }
    return NULL;
}

/* Gather the selected sides, reject bad status, and count or store actions whose predicate differs from rejectedResult. */
// FUN_001D9390
int btlSideSelectUnits(s32 action, s32 conditionValue, s32 statusMask, s32 sideFlags, s32 rejectedResult, s32 (*predicate)(u8 *, s32), u8 **output) {
    struct Frame {
        u8 *entries[14];
        u16 count;
        u16 unknown3a;
        u8 flags;
    } frame;
    u8 *unit;
    s32 index;
    s32 matches;
    u8 *work;
    u16 flags;

    btlEffectCollectTargetUnits((u8 *)action, (u8 *)&frame, sideFlags, 0, 0);
    matches = 0;
    index = 0;
    goto test;
loop:
    unit = frame.entries[(u16)index];
    flags = ((BtlAction *)unit)->unk_1a;
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = (u8 *)((BtlAction *)unit)->unit;
            if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)work)->datUnit, statusMask) == 0) {
                if (predicate(unit, conditionValue) != rejectedResult) {
                    if (output != NULL) {
                        output[(u16)matches] = unit;
                    }
                    matches = (matches + 1) & 0xFFFF;
                }
            }
        }
    }
    index = (index + 1) & 0xFFFF;
test:
    if ((u16)index < frame.count) {
        goto loop;
    }
    return matches;
}

/* Search active actions by genus, status and optional skill filters, returning at the first successful predicate. */
// FUN_001D94D0
int btlEffectFindUnitMatchingCallback(int action, int conditionValue, int sideMask, int statusMask, int filterFlags, code predicate)
{
    BtlUnit *workFields;
    u8 *unit;
    u8 *work;
    u16 flags;
    s32 type_mask;
    s32 options;
    s32 option_one;
    s32 option_two;
    s32 option_four_eight;
    s32 option_four_value;
    s32 ignore_dead_value;
    s32 status;
    s32 effects;

    extern s32 datCalcElementBit(s16 element);
    extern s8 datCalcGetBuffStatus(u8 *unit, s32 buffIndex);
    extern s32 btlTargetAffinityKnowledgeBypassNoop(u8 *value, s32 index);
    extern s32 datTestBitmapBit(u16 entryIndex, u16 bitIndex);

    (void)action;
    unit = ((BtlBattleState *)(iGpffffb3ac))->actions;
    type_mask = (u16)sideMask;
    options = (u16)filterFlags;
    option_one = options & 1;
    option_two = options & 2;
    option_four_eight = options & 0xC;
    option_four_value = options & 4;
    ignore_dead_value = statusMask & 0x80000;
    goto test;

loop:
    flags = ((BtlAction *)(unit))->unk_1a;
    if ((flags & 1) != 0 && (flags & 8) != 0) {
        work = (u8 *)((BtlAction *)(unit))->unit;
        workFields = (BtlUnit *)work;
        if ((type_mask & (1 << ((BtlUnit *)(work))->genus)) != 0) {
            if (options == 0)
                goto check_general;
            if (option_one != 0 &&
                datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)(work))->datUnit, 0x100000) == 0)
                goto next;
            if (option_two != 0) {
                status = datCalcElementBit((s16)conditionValue);
                if ((status & 0xE0001) == 0) {
                    if ((status & 2) != 0) {
                        effects = datCalcGetBuffStatus((u8 *)((BtlUnit *)(work))->datUnit, 0x10);
                        if (effects > 0)
                            goto next;
                    } else if ((status & 0x40) == 0) {
                        effects = datCalcGetBuffStatus((u8 *)((BtlUnit *)(work))->datUnit, 0x11);
                        if (effects > 0)
                            goto next;
                    }
                }
            }
            if (option_four_eight != 0 &&
                workFields->genus == 1 &&
                btlTargetAffinityKnowledgeBypassNoop(unit, (s16)conditionValue) == 0 &&
                datTestBitmapBit(((BtlUnit *)(work))->charId, (u16)conditionValue) == 0) {
                if (option_four_value != 0)
                    goto next;
                return 1;
            }
check_general:
            if ((ignore_dead_value == 0 ||
                 datCalcIsDead((u8 *)((BtlUnit *)(work))->datUnit, 0) == 0) &&
                datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)(work))->datUnit, statusMask) == 0 &&
                predicate(unit, conditionValue) != 0)
                return 1;
        }
    }
next:
    unit = (u8 *)((BtlAction *)(unit))->next;
test:
    if (unit != NULL)
        goto loop;
    return 0;
}

