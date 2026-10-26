#ifndef BTL_SKILL_TARGET_INTERNAL_H
#define BTL_SKILL_TARGET_INTERNAL_H

#include "type.h"

/* The classification is consumed as an unsigned halfword by the battle
 * command, condition and camera callers. The table stores its current
 * values in a byte. A non-NULL target record also receives target setup. */
u16 btlSkillClassifyTargets(u8 *action, u8 *selection, u16 skillId, u32 reverseSides);

/* The table classifier consumes the signed skill halfword. Retail narrows
 * this domain on entry, including the callers that supply a stored u16. */
s32 btlTargetIsEntryActive(s16 context);
s32 btlTargetCanSelectEntry(u8 *context, s16 value, s32 option);

/* Battle unit group queries defined in code1_001e.c. */
s32 btlSideAverageLevel(s32 sideMask, s32 excludedStatus);
s32 btlSideCountNotBad(s32 sideMask, s32 excludedStatus);

/* These call sites supply flags/context words even where the release hook does
 * not consume them. The formal inputs keep caller evaluation and the C ABI
 * consistent without removing retail GP-register setup. */
s32 btlBuffMaskCheckEntries(u8 *action, s32 skillId, s32 unusedFlags);
s32 btlBuffMaskCheckUnit(u8 *action, s32 skillId, s32 unusedFlags);
void btlTargetSpecialHitNoop(u8 *unusedContext, u8 *unusedUnit, s32 unusedId);
s32 btlTargetAffinityKnowledgeBypassNoop(u8 *unusedAction, s32 unusedAffinity);

s32 btlTargetSkillAuxiliaryMessageNoop(s32 unusedSkillId);


/* Existing callers supply these inputs; unused inputs are retained explicitly. */
s32 btlActionEscapeCondition(u8 *action, s32 skillId, s32 unusedMode);

#endif
