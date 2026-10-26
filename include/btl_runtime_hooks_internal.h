#ifndef BTL_RUNTIME_HOOKS_INTERNAL_H
#define BTL_RUNTIME_HOOKS_INTERNAL_H

#include "type.h"

/* Callers evaluate and provide these context values. The release hooks and
 * global battle queries below do not consume that context. */
void btlAdvantageInitNoop(void *unusedWork);
void btlGaugeInitNoop(void *unusedWork);
void btlGaugeRefreshAll(s32 unusedContext);
s32 btlEncountRollChance(u8 *unusedAction);
s32 btlEncounterIsInactive(s32 unusedContext);
s32 btlIsLeaderStandardUnit(u8 *unusedAction);
void btlPanelInitNoop(void *unusedWork);

#endif
