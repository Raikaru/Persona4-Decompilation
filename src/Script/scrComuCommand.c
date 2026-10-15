/* Source unit: src/Script/scrComuCommand_0024a0b0.c */
#include "type.h"

u16 func_00108ee0();
void scrSetReturnInt();

u16 datPersonaLeadPersonaId();



// FUN_0024A0B0
u32 func_0024A0B0(void)
{
    u16 uVar1;

    uVar1 = func_00108ee0();
    scrSetReturnInt(uVar1);
    return 1;
}



// FUN_0025CFD0
u32 func_0025CFD0(void)
{
    u16 uVar1;

    uVar1 = datPersonaLeadPersonaId();
    scrSetReturnInt(uVar1);
    return 1;
}
