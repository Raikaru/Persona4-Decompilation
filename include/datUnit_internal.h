#ifndef DATUNIT_INTERNAL_H
#define DATUNIT_INTERNAL_H

#include "type.h"

/* DatUnit.bad: bits 0-19 are ailments, bits 20-31 the high half (kept
   separately by datCalcSetBadStatus; bit 20 is DOWN). KO is bit 19: datCalcIsDead returns
   1 when bad & 0x80000 (datCalc.c), kills set it and btlTarget.c:837 clears it on revive. */
#define BTL_STATUS_KO 0x80000
/* DatUnit.bad bit 20, named UNIT_BADSTATUS_DOWN in P3FES datUnit.h. It sits in the
   high half that datCalcSetBadStatus keeps apart; btlCond_MYBAD tests it, and the
   0x180000 pickers (btlCond_MYWEAK, btlCond_MYNOMAL) pair it with KO. */
#define BTL_STATUS_DOWN 0x100000
/* DatUnit.flags bit 0x8: btlCond_DOWN (btlAICommand.c) returns 0 while it is set. */
#define DAT_UNIT_FLAG_DOWN 0x8
/* DatUnit.flags bit 0x4: enemy unit. Enemy stats come from the enemy table (iGpffffb3c4/3c8, id-indexed); clear means a persona record. */
#define DAT_UNIT_FLAG_ENEMY 0x4

/* One battle unit record (stride 0x30). Shared by datUnit.c and datCalc.c. */
typedef struct DatUnit
{
    u16 flags;          // 0x00
    u16 id;             // 0x02
    u16 id2;            // 0x04
    u8 level;           // 0x06
    u16 hp;             // 0x08
    u16 sp;             // 0x0A
    u32 bad;            // 0x0C
    s8 aiTactic;        // 0x10
    u8 unknown11[0x1F]; // 0x11
} DatUnit;

typedef struct DatUnitGenusBase
{
    u16 genus;     // 0x00
    u16 count;     // 0x02
    DatUnit* unit; // 0x04
} DatUnitGenusBase;

typedef struct DatUnitPc
{
    DatUnitGenusBase base;
    u32 unknown08;
} DatUnitPc;

typedef struct DatUnitEc
{
    DatUnitGenusBase base; // 0x00
    u16 encountId;         // 0x08
    u16 unknown0A;         // 0x0A
    DatUnit units[6];      // 0x0C
} DatUnitEc;

/* Character record (0x48 bytes) of the protagonist D_007973C4 and of each party slot.
   Its first 0x30 bytes are a DatUnit, which datCalc reads through the unit accessors. */
typedef struct DatCharRecord
{
    DatUnit unit;       // 0x00
    u8 unknown30[0x18]; // 0x30
} DatCharRecord;

/* One persona record (0x30 stride) of the roster and party slots. Roster flags at +0 (bit 0 active,
   bit 4 lead boost), persona id at +2. Layout pinned by the datPersona.c accessors. */
typedef struct DatPersonaRecord
{
    u16 flags;               // 0x00. Bit 0 active. A roster rebuild keeps bits 2 and 3 (0xC) and sets bit 0.
    u16 id;                  // 0x02
    u8 level;                // 0x04. Also the ranking key of roster slot arg0.
    u8 unknown05;            // 0x05. Set from the level-table row at load [inferred: growth index].
    u8 unknown06[2];         // 0x06..0x07
    s32 exp;                 // 0x08. Experience, added to by datPersonaAddExp.
    u16 skills[8];           // 0x0C..0x1B. Skill slots, 0 when empty.
    u8 stats[5];             // 0x1C..0x20. Battle stats in DatPersonaStat order.
    s8 statBonusA[5];        // 0x21..0x25. Per-stat bonus summed into the totals.
    s8 statBonusB[5];        // 0x26..0x2A. Second per-stat bonus summed into the totals.
    u8 unknown2B;            // 0x2B
    s32 unknown2C;           // 0x2C
} DatPersonaRecord;

/* One party slot (0x88 stride) of D_00796E50. Index arg0 - 2 for party id arg0 (2..10). */
typedef struct DatPartySlot
{
    u8 unknown00[4];         // 0x00
    DatCharRecord character; // 0x04. Saved to the save file as 0x48 bytes.
    u8 unknown4C[8];         // 0x4C
    DatPersonaRecord personaRecord; // 0x54. datPersonaGetRecord returns a pointer to it (flags, id at +2).
    u8 unknown84[4];         // 0x84
} DatPartySlot;


/* Battle unit table accessors defined in datUnit.c. */
/* Allocates and fills the PC unit record for pcId. */
DatUnitPc* datUnitCreatePc(u16 pcId);
/* Allocates an encounter group and fills its enemy slots from the encount table. */
DatUnitEc* datUnitCreateEncounterGroup(u16 encountId);
/* Places id into the first free slot of ec and returns that unit. */
DatUnit* datUnitAddEncounterUnit(DatUnitEc* ec, u16 id);
/* Clears the slot holding unit and decrements the group count. */
void datUnitRemoveEncounterUnit(DatUnitEc* ec, DatUnit* unit);
/* Releases a block through the battle heap free jump table. */
void datUnitFree(s32 allocation);
/* Returns 1 when every occupied unit in the group is dead. */
u32 datUnitGroupIsDefeated(DatUnitGenusBase* genusBase);
/* Initialises a unit from the enemy table (EC) or clears PC flags, then sets its id. */
u32 datUnitInit(DatUnit* unit, u8 genus, u16 id);

#endif
