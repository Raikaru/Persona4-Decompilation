#ifndef DATUNIT_INTERNAL_H
#define DATUNIT_INTERNAL_H

#include "type.h"

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
void datUnitFree(s32 arg0);
/* Returns 1 when every occupied unit in the group is dead. */
u32 datUnitGroupIsDefeated(DatUnitGenusBase* genusBase);
/* Initialises a unit from the enemy table (EC) or clears PC flags, then sets its id. */
u32 datUnitInit(DatUnit* unit, u8 genus, u16 id);

#endif
