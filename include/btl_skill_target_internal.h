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

#endif
