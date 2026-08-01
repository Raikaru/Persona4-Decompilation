/* Source unit: src/datCalc/datCalc_00242930.c (1 function markers) */
#include "type.h"

extern u16 func_00231f80(int unit);

void func_00243f20(u16 characterId);



// FUN_00242930
u32 datCalcIsLowHp(int unit)
{
    u16 hp;

    hp = *(u16*)(unit + 8);

    return ((hp * 100) / func_00231f80(unit)) < 26;
}



// FUN_00243ED0
void datCalcInitializeCharacters(void)
{
    u16 characterId;

    for (characterId = 1; characterId < 0xb; characterId++)
    {
        func_00243f20(characterId);
    }
}
