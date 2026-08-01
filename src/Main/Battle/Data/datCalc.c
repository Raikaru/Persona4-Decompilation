/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002325A0)
/* Source unit: src/Main/Battle/Data/datCalc_002325a0.c */
#include "type.h"

typedef struct DatUnit
{
    u16 flags;         // 0x00
    u16 id;            // 0x02
    u16 id2;           // 0x04
    u8 level;          // 0x06
    u16 hp;            // 0x08
    u16 sp;            // 0x0a
    u32 bad;           // 0x0c
    s8 aiTactic;       // 0x10
    u8 unkData1[0x28];
} DatUnit;

extern u16 func_00231f80(DatUnit* unit);

/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300410 (verified MATCH there). */
// FUN_002325A0
s32 func_002325a0(DatUnit* unit, s32 hpDelta)
{
    s32 maxHp;
    s32 newHp;

    newHp = unit->hp + hpDelta;
    if (newHp < 0) {
        newHp = 0;
    }
    maxHp = func_00231f80(unit) & 0xFFFF;
    if (maxHp < newHp) {
        newHp = maxHp;
    }
    unit->hp = (u16)newHp;
    return newHp & 0xFFFF;
}
#endif /* P4_UNIT_002325A0 */

#if defined(P4_UNIT_00232610)
/* Source unit: src/Main/Battle/Data/datCalc_00232610.c */
#include "type.h"

typedef struct DatUnit
{
    u16 flags;         // 0x00
    u16 id;            // 0x02
    u16 id2;           // 0x04
    u8 level;          // 0x06
    u16 hp;            // 0x08
    u16 sp;            // 0x0a
    u32 bad;           // 0x0c
    s8 aiTactic;       // 0x10
    u8 unkData1[0x28];
} DatUnit;

extern u32 func_00232290(DatUnit* unit);

/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300480 (verified MATCH there). */
// FUN_00232610
s32 func_00232610(DatUnit* unit, s32 spDelta)
{
    s32 maxSp;
    s32 newSp;

    newSp = unit->sp + spDelta;
    if (newSp < 0) {
        newSp = 0;
    }
    maxSp = func_00232290(unit) & 0xFFFF;
    if (maxSp < newSp) {
        newSp = maxSp;
    }
    unit->sp = (u16)newSp;
    return newSp & 0xFFFF;
}
#endif /* P4_UNIT_00232610 */

#if defined(P4_UNIT_00243F20)
/* Source unit: src/Main/Battle/Data/datCalc_00243f20.c */
#include "type.h"

extern u32 func_00104dc0();
extern u32 func_001056e0();
extern u32 func_00104e30();
extern u32 func_00105730();
extern u32 func_00105d50();

/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_0030c490 (verified MATCH there). */
// FUN_00243F20
void func_00243f20(u16 characterId)
{
    s16 id;
    s16 value;

    id = (s16)characterId;
    value = (s16)func_00104dc0(id);
    func_001056e0(id, value);
    value = (s16)func_00104e30(id);
    func_00105730(id, value);
    func_00105d50(id, -1);
}
#endif /* P4_UNIT_00243F20 */
