/* Source unit: src/rw/rpworld_003d4d70.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern int func_003cc0d0(int);

extern int func_003cc010(int);

extern int func_003cc070(int);


#pragma optimization_level 3

// FUN_003D4D70
int func_003d4d70(void)
{
    return func_003cc0d0(0);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_003D4D80
INCLUDE_ASM("asm/nonmatchings/rpworld", func_003d4d80);
// FUN_003D4E00
int func_003d4e00(void)
{
    return func_003cc010(0);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_003D4E10
INCLUDE_ASM("asm/nonmatchings/rpworld", func_003d4e10);
// FUN_003D4E90
int func_003d4e90(void)
{
    return func_003cc070(0);
}
#pragma optimization_level 2
