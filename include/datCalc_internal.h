#ifndef DATCALC_INTERNAL_H
#define DATCALC_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

/* One row of the skill table (iGpffffb3b8), stride 0x28, indexed by skill id. The
   table is read as u8 bytes in datCalc.c. Offsets are named by the
   code that reads them; roles marked [inferred] are not yet pinned. Typed access
   moves codegen where the constant offset folds (datCalc.c), so most sites stay raw. */
typedef struct DatSkillEntry
{
    u8 flags00;         // 0x00. Bit 0x2 (skill is used), bit 0x40 (not applied to a target).
    u8 flags01;         // 0x01. Bit 0x2.
    u8 field02;         // 0x02. Compared with 1 and 2 [inferred: mode].
    u8 kind03;          // 0x03. Switch selector for the skill effect kind.
    u8 unknown04[0x0A]; // 0x04..0x0D
    u8 field0E;         // 0x0E. Cost or power, tested against 0 and 100 [inferred].
    u8 unknown0F[2];    // 0x0F..0x10
    u8 field11;         // 0x11. Tested against 0x10 and 8 [inferred].
    u8 unknown12[2];    // 0x12..0x13
    u8 field14;         // 0x14
    u8 unknown15[3];    // 0x15..0x17
    u8 mode18;          // 0x18. Mode tested against 1, 2 and 3 [inferred].
    u8 field19;         // 0x19. Compared with 100 (0x64) [inferred].
    u8 unknown1A[0x0A]; // 0x1A..0x23
    u8 kind24;          // 0x24. Switch selector and compared with 3, 6, 0xD, 0xE.
    u8 field25;         // 0x25
    u8 field26;         // 0x26
    u8 unknown27;       // 0x27
} DatSkillEntry;

/* Battle unit HP, SP, bad-status, and death accessors defined in datCalc.c.
 * The unit argument is the battle unit's DatUnit record; retail reads its fields. */
u16 datCalcGetHp(DatUnit *unit);
u16 datCalcGetSp(DatUnit *unit);
void datCalcSetHp(DatUnit *unit, u16 hp);
void datCalcSetSp(DatUnit *unit, u16 sp);
u32 datCalcSetBadStatus(DatUnit *unit, u32 badStatus);
u32 datCalcGetBadStatusNoDown(DatUnit *unit);
u32 datCalcGetBadStatus(DatUnit *unit);
u32 datCalcClearBadStatus(DatUnit *unit, u32 badStatus);
u32 datCalcChkBadStatus(DatUnit *unit, u32 badStatus);
/* Zeroes the unit record, sets its id, level 1, HP/SP 1 (datCalc.c). */
void datCalcInitUnit(DatUnit *unit, s16 id);
/* Level of the unit: its stored level for flag-4 units or id 1, otherwise its persona record's level. */
s32 datCalcGetLevel(DatUnit *unit);
/* Stores the level, clamped to 99 unless flag 4 (datCalc.c). */
void datCalcSetLevel(DatUnit *unit, u8 level);
/* Clears the word at byte offset 0x18 of an object block. */
void datCalcClearField18(int object);
u32 datCalcIsSpecialItem(u16 itemId);
u32 datCalcIsDead(DatUnit *unit, s32 hpDelta);
u32 datCalcIsLowHp(DatUnit *unit);
void datCalcInitializeCharacters(void);
// Intent: seeds the per-character tables for character id arg0; see datCalcInitializeCharacters.
void datCalcInitializeCharacter(u16 characterId);
/* Returns the fixed skill-table length (8) for a unit's table. */
u32 datCalcGetTableLength(u8 *unused);
// Intent: maximum HP of unit arg0 from its level and skill/equipment bonuses; capped at 999 unless flag 4.
u16 datCalcMaxHp(DatUnit *unit);
// Intent: maximum SP of unit arg0 from its level and SP bonuses; capped at 999 unless flag 4.
u16 datCalcMaxSp(DatUnit *unit);
/* Returns 1 when the unit is flagged (flag 4) and its id's table entry has bit 0x80 set. */
s32 func_00243d80(DatUnit *unit);

#endif
