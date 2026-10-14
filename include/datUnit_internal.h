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
DatUnitPc* func_00231580(u16 pcId);
DatUnitEc* func_00231630(u16 encountId);
DatUnit* func_002317a0(DatUnitEc* ec, u16 id);
void func_002318c0(DatUnitEc* ec, DatUnit* unit);
void func_002319c0(s32 arg0);
u32 func_002319f0(DatUnitGenusBase* genusBase);
u32 func_00231af0(DatUnit* unit, u8 genus, u16 id);

#endif
