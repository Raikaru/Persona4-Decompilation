#ifndef BTL_SKILL_TARGET_INTERNAL_H
#define BTL_SKILL_TARGET_INTERNAL_H

#include "type.h"

/* The classification is consumed as an unsigned halfword by the battle
 * command, condition and camera callers. The table stores its current
 * values in a byte. A non-NULL target record also receives target setup. */
u16 func_001d7f10(u8 *action, u8 *targets, u16 skill, u32 reverseGroups);

#endif
