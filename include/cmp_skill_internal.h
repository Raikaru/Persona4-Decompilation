#ifndef CMP_SKILL_INTERNAL_H
#define CMP_SKILL_INTERNAL_H

#include "type.h"

/* func_0013f720 indexes 12-byte records at work+0x100, saves/restores
 * persona context, and subtracts the two costs from the caster's HP/SP. */
typedef struct CmpSkillEntry {
    s16 personaId;
    u16 skillId;
    s32 hpCost;
    s32 spCost;
} CmpSkillEntry;

typedef struct CmpSkillMenu {
    u8 pad0[0xF4];
    s16 targetIds[4];
    s16 targetCount;
    u8 padFE[2];
} CmpSkillMenu;

#endif
