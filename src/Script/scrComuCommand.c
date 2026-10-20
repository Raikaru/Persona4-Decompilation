#include "type.h"
#include "datPersona_internal.h"

u16 cmmCommunityGetTableHead();
void scrSetReturnInt();


// Script command 0x3008: returns the community table head id.
// FUN_0024A0B0
u32 cmmGetTableHead(void)
{
    u16 communityId;

    communityId = cmmCommunityGetTableHead();
    scrSetReturnInt(communityId);
    return 1;
}


// Returns the lead persona id.
// FUN_0025CFD0
u32 scrGetLeadPersonaId(void)
{
    u16 personaId;

    personaId = datPersonaLeadPersonaId();
    scrSetReturnInt(personaId);
    return 1;
}
