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
#include "btl_result_ui_internal.h"

/* Encounter flag rows are indexed at the observed 0x18-byte stride. */
typedef struct BtlXpEncounterRecord {
    s32 flags;
    u8 pad04[0x14];
} BtlXpEncounterRecord;
typedef struct PersonaWork PersonaWork;

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb414; /* encounter flags: 0x18-byte rows */
extern f32 *iGpffffb40c; /* level-difference experience scales */
extern u8 *datUnitGetRecord(s16);
extern u32 datPersonaGetExpById(s16);
extern void datSetHeroExp(s16, u32 value);
extern u8 datLevelFromExp(s32);
extern s32 datAddMoney(s32);
extern s32 datItemCount(s16 id);
extern void datCalcSetLevel(u8 *, u8);
extern u32 datGetFlag(s32);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290D0[];
extern void chkmemAllocSiteTag(const void *, s32);
extern s32 kwlnTaskGetTaskByName(void *);
extern u8 D_006290E0[];
extern void btlShuffleDrawSweep(s32, s32 *);
extern void btlShuffleDestroyOverlayWork(u8 *task);
extern s32 datPersonaCanLevelUp(PersonaWork *);
extern void datPersonaApplyLevelUp(u8 *, u8 *);
extern s32 btlShuffleTickFrame(u8 *task);
extern void btlXpPrepareAwards(u8 *, u8 *);
extern void btlXpApplyAwards(u8 *, u8 *);
extern void btlXpAddRosterExp(u8 *);
extern void btlXpAddPartyExp(s32);
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
        ((PrimQueueNode *)(work + 4))->callback = (void *)btlShuffleDrawSweep;
        ((PrimQueueNode *)(work + 4))->argument.data = work;
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
s32 btlXpComputeAward(s32 level, u8 *reward)
{
    s32 value;
    u32 result;
    f32 scale;
    f32 levelScale;
    s32 delta;
    s32 index;

    value = ((BtlXpReward *)reward)->experience;
    if (value <= 0) {
        return 0;
    }
    if ((((BtlXpReward *)reward)->flags & 8) == 0 && datGetFlag(0x1403) != 0) {
        if (datGetFlag(0x1428) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (datGetFlag(0x1429) != 0) {
            value = 0;
        }
    }
    scale = 1.0f / (f32)((BtlXpReward *)reward)->divisor;
    if ((((BtlXpEncounterRecord *)iGpffffb414)[((BtlXpReward *)reward)->encounterIndex].flags & 0x80) != 0) {
        result = (s32)((f32)value * scale);
    } else {
        delta = ((BtlXpReward *)reward)->enemyLevel - level;
        if (delta >= 10) {
            index = 20;
        } else if (delta < -9) {
            index = 0;
        } else {
            index = delta + 10;
        }
        levelScale = iGpffffb40c[index];
        result = (s32)(scale * ((f32)value * levelScale));
    }
    if ((s32)result > 0xFFFF) {
        result = 0xFFFF;
    } else if ((s32)result <= 0) {
        result = 1;
    }

    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: return the base XP award for one persona after the award flags. [inferred]
// FUN_0021E050
s32 btlXpBaseAward(u8 *reward)
{
    s32 value;

    value = ((BtlXpReward *)reward)->money;
    if (value <= 0) {
        return 0;
    }
    if ((((BtlXpReward *)reward)->flags & 8) == 0 && (datGetFlag(0x1403) != 0)) {
        if (datGetFlag(0x1420) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (datGetFlag(0x1421) != 0) {
            value = 1;
        }
    }
    return value;
}
#pragma pop

extern s32 datCalcGetLevelById(s32);
extern u8 datPersonaGetLevel(int persona);
extern u32 datPersonaGetExp(int persona);
extern u16 datItemValue(s16);
extern s16 datGetEquippedItemByUnit(s16, s16);
#pragma push
#pragma opt_loop_invariants on
// Intent: prepare the XP award blocks for the leader and the party without applying them. [inferred]
// FUN_0021E110
void btlXpPrepareAwards(u8 *awards, u8 *reward)
{
    s32 rosterIndex;
    s32 partyIndex;
    s32 partyOutput;
    s32 award;
    s32 baseAward;
    s32 rosterBaseAward;
    s32 partyBaseAward;
    s32 extraBaseAward;
    s32 partyAward;
    s32 expOffset;
    s32 idOffset;
    u16 *partyPersona;

    s32 skillAward;
    s32 rosterCount;
    s32 partyCount;
    s32 personaLevel;
    s32 memberId;
    s32 skills;
    s32 skill;
    s32 experience;
    s32 nextLevelExp;
    s32 partyLevel;
    s32 skillIndex;
    u8 heroLevel;
    u16 *heroPersona;
    u16 *rosterPersona;
    s32 heroPersonaId;

    memset(awards, 0, 0x8D4);
    partyOutput = 0;
    if (((BtlXpReward *)reward)->flags & 1) {
        ((BtlXpAwards *)awards)->flags |= 1;
    }
    heroLevel = datCalcGetLevelById(1) & 0xFF;
    award = btlXpComputeAward(heroLevel, reward);
    baseAward = award;
    if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
        award += (s32)(0.5f * (f32)award);
    }
    if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
        award += (s32)(0.5f * (f32)baseAward);
    }
    if (heroLevel != (datLevelFromExp(award + datPersonaGetExpById(1)) & 0xFF)) {
        ((BtlXpAwards *)awards)->flags |= 2;
    }
    ((BtlXpAwards *)awards)->unk698 = ((BtlXpReward *)reward)->unk10;
    ((BtlXpAwards *)awards)->heroExp = award;
    heroPersona = (u16 *)datPersonaGetRecord(1);
    datUnitGetRecord(1);
    heroPersonaId = heroPersona[1];
    rosterCount = datPersonaCountValidMembers() & 0xFFFF;
    for (rosterIndex = 0; rosterIndex < rosterCount; rosterIndex++) {
        rosterPersona = (u16 *)datPersonaRosterSlot((s16)rosterIndex);
        personaLevel = datPersonaGetLevel((s32)rosterPersona) & 0xFF;
        rosterBaseAward = btlXpComputeAward(personaLevel, reward);
        if (rosterPersona[1] == heroPersonaId) {
            award = rosterBaseAward;
            if (datPersonaLeadBoosted(1) != 0) {
                award += (s32)(0.5f * (f32)rosterBaseAward);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
                award += (s32)(0.5f * (f32)rosterBaseAward);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
                award += (s32)(0.5f * (f32)rosterBaseAward);
            }
        } else {
            skills = (s32)datPersonaGetSkills((struct DatPersonaRecord *)rosterPersona);
            award = 0;
            for (skillIndex = 0; skillIndex < 8; skillIndex++) {
                skill = ((u16 *)skills)[skillIndex];
                if (skill != 0) {
                    switch (skill) {
                    case 0x1FF:
                        award += (s32)(0.25f * (f32)rosterBaseAward);
                        break;
                    case 0x200:
                        award += (s32)(0.5f * (f32)rosterBaseAward);
                        break;
                    case 0x201:
                        award += (s32)(f32)rosterBaseAward;
                        break;
                    }
                }
            }
            skillAward = award;
            if (rosterPersona[0] & 4) {
                award += (s32)(0.5f * (f32)award);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 0)) == 0x86) {
                award += (s32)(0.5f * (f32)skillAward);
            }
            if (datItemValue(datGetEquippedItemByUnit(1, 1)) == 0x86) {
                award += (s32)(0.5f * (f32)skillAward);
            }
        }
        if (personaLevel < 99) {
            experience = datPersonaGetExp((s32)rosterPersona);
            nextLevelExp = (s32)datPersonaGetExpForLevel(rosterPersona, (u16)(personaLevel + 1));
            if (nextLevelExp <= experience + award) {
                ((BtlXpAwards *)awards)->flags |= 8;
                datPersonaPreviewLevelUp((u8 *)rosterPersona, awards + rosterIndex * 0x88 + 0x38, award);
            }
            if (award != 0) {
                ((BtlXpAwards *)awards)->rosterExp[rosterIndex] = award;
            }
        }
    }
    partyCount = ((BtlXpReward *)reward)->partyCount;
    for (partyIndex = 0; partyIndex < partyCount; partyIndex++) {
        memberId = ((BtlXpReward *)reward)->partyIds[partyIndex];
        if (memberId != 1) {
            partyPersona = (u16 *)datPersonaGetRecord((u16)memberId);
            partyLevel = datPersonaGetLevel((s32)partyPersona) & 0xFF;
            partyBaseAward = btlXpComputeAward(partyLevel, reward);
            partyAward = partyBaseAward;
            if (datItemValue(datGetEquippedItemByUnit((s16)memberId, 0)) == 0x86) {
                partyAward += (s32)(0.5f * (f32)partyBaseAward);
            }
            if (datItemValue(datGetEquippedItemByUnit((s16)memberId, 1)) == 0x86) {
                partyAward += (s32)(0.5f * (f32)partyBaseAward);
            }
            if (partyLevel < 99) {
                experience = datPersonaGetExp((s32)partyPersona);
                nextLevelExp = (s32)datPersonaGetExpForLevel(partyPersona, (u16)(partyLevel + 1));
                if (nextLevelExp <= experience + partyAward) {
                    ((BtlXpAwards *)awards)->flags |= 0x10;
                    datPersonaPreviewLevelUp((u8 *)partyPersona, awards + partyOutput * 0x88 + 0x6B4, partyAward);
                }
                ((BtlXpAwards *)awards)->partyExp[partyOutput] = partyAward;
            }
            ((BtlXpAwards *)awards)->partyIds[partyOutput] = memberId;
            partyOutput += 1;
        }
    }
    if (datGetFlag(0x38) != 0) {
        partyPersona = (u16 *)datPersonaGetRecord(5);
        partyLevel = datPersonaGetLevel((s32)partyPersona) & 0xFF;
        extraBaseAward = btlXpComputeAward(partyLevel, reward);
        partyAward = extraBaseAward;
        if (datItemValue(datGetEquippedItemByUnit(5, 0)) == 0x86) {
            partyAward += (s32)(0.5f * (f32)extraBaseAward);
        }
        if (datItemValue(datGetEquippedItemByUnit(5, 1)) == 0x86) {
            partyAward += (s32)(0.5f * (f32)extraBaseAward);
        }
        if (partyLevel < 99) {
            experience = datPersonaGetExp((s32)partyPersona);
            nextLevelExp = (s32)datPersonaGetExpForLevel(partyPersona, (u16)(partyLevel + 1));
            if (nextLevelExp <= experience + partyAward) {
                ((BtlXpAwards *)awards)->flags |= 0x10;
                datPersonaPreviewLevelUp((u8 *)partyPersona, awards + partyOutput * 0x88 + 0x6B4, partyAward);
            }
            expOffset = partyOutput * 4;
            *(u32 *)(expOffset + (s32)awards + 0x6A4) /* partyExp: typed indexing changes retail instruction bytes. */ = partyAward;
        }
        idOffset = partyOutput * 2;
        *(u16 *)(idOffset + (s32)awards + 0x69A) /* partyIds: typed indexing changes retail instruction bytes. */ = 5;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: apply the prepared level and skill-point awards to the leader and party. [inferred]
// FUN_0021E9A0
void btlXpApplyAwards(u8 *awards, u8 *reward)
{
    s32 heroExperience;
    s32 hero;
    s32 previousExperience;
    s32 money;
    s32 itemIndex;
    u8 *itemCursor;
    u8 *item;
    s32 previousCount;
    s16 sum;
    hero = (s32)datUnitGetRecord(1);
    previousExperience = (s32)datPersonaGetExpById(1);
    if ((datLevelFromExp(previousExperience) & 0xFF) < 0x63) {
        heroExperience = previousExperience + ((BtlXpAwards *)awards)->heroExp;
        datSetHeroExp(1, heroExperience);
        datCalcSetLevel((u8 *)hero, datLevelFromExp(heroExperience));
    }
    money = ((BtlXpReward *)reward)->money;
    if (money <= 0) {
        money = 0;
    } else if ((((BtlXpReward *)reward)->flags & 8) == 0 && datGetFlag(0x1403) != 0) {
        if (datGetFlag(0x1420) != 0) {
            money = (s32)(2.0f * (f32)money);
        } else if (datGetFlag(0x1421) != 0) {
            money = 1;
        }
    }
    datAddMoney(money);
    itemIndex = 0;
    while (itemIndex < ((BtlXpReward *)reward)->itemCount) {
        itemCursor = reward + itemIndex * 4;
        item = itemCursor + 0x24;
        previousCount = (s16)(datItemCount(((BtlXpItem *)(itemCursor + 0x24))->id) & 0xFF);
        sum = previousCount + ((BtlXpItem *)(itemCursor + 0x24))->count;
        if (sum > 0x63) {
            sum = 0x63;
        }
        datItemSetCount((s32)*(s16 *)item, (u8)sum);
        itemIndex += 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: add prepared experience to each roster member and apply any level-ups. [inferred]
// FUN_0021EB60
void btlXpAddRosterExp(u8 *awards)
{
    s32 limit;
    s32 value;
    u8 *persona;
    s32 i;

    limit = datPersonaCountValidMembers() & 0xFFFF;
    i = 0;
    while (i < limit) {
        value = ((BtlXpAwards *)awards)->rosterExp[i];
        if (value != 0) {
            persona = (u8 *)datPersonaRosterSlot((s16)i);
            datPersonaAddExp((DatPersonaRecord *)persona, value);
            if (datPersonaCanLevelUp((PersonaWork *)persona) != 0) {
                datPersonaApplyLevelUp(persona, awards + (i * 0x88) + 0x38);
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
void btlXpAddPartyExp(s32 awardsAddress)
{
    s32 persona;
    s32 experience;
    s32 partyIndex;

    partyIndex = 0;
    while (partyIndex < 4) {
        experience = ((BtlXpAwards *)awardsAddress)->partyExp[partyIndex];
        if (experience != 0) {
            persona = (s32)datPersonaGetRecord(((BtlXpAwards *)awardsAddress)->partyIds[partyIndex]);
            datPersonaAddExp((DatPersonaRecord *)persona, experience);
            if (datPersonaCanLevelUp((PersonaWork *)persona) != 0) {
                datPersonaApplyLevelUp((u8 *)persona,
                              (u8 *)awardsAddress + (partyIndex * 0x88) + 0x6B4);
            }
        }
        partyIndex += 1;
    }
}
#pragma pop
#pragma pop
