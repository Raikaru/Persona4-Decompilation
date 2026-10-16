/* Source unit: src/Script/scrComuCommand_0024a0b0.c */
#include "type.h"
#include "datPersona_internal.h"

u16 cmmCommunityGetTableHead();
void scrSetReturnInt();




// Returns the community table head id [inferred].
// FUN_0024A0B0
u32 cmmGetTableHead(void)
{
    u16 uVar1;

    uVar1 = cmmCommunityGetTableHead();
    scrSetReturnInt(uVar1);
    return 1;
}



// Returns the lead persona id [inferred].
// FUN_0025CFD0
u32 scrGetLeadPersonaId(void)
{
    u16 uVar1;

    uVar1 = datPersonaLeadPersonaId();
    scrSetReturnInt(uVar1);
    return 1;
}
