#ifndef DAT_ENEMY_INTERNAL_H
#define DAT_ENEMY_INTERNAL_H

#include "type.h"

/* Enemy defaults, eight skills, rewards and weighted choices share a 0x3C row.
 * Offsets are pinned by datUnitInit and the reward/property readers in datCalc.c. */
typedef struct DatEnemyUnitInit
{
    u16 flags;
    u8 unknown02;
    u8 level;
    u16 hp;
    u16 sp;
    u8 stats[5];
    u8 unknown0D;
    u16 skills[8];
    u16 exp;
    u16 money;
    struct { u16 skill; u8 weight; u8 unknown03; } choices[4];
    u16 specialFlag;
    u16 specialSkill;
    u8 specialChance;
    u8 unknown37;
    u8 weaponElement;
    u8 weaponValue;
    u16 weaponPower;
} DatEnemyUnitInit;

#endif
