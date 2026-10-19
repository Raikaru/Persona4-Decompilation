/* Source unit: src/comuTimerSequence_0021dd60.c */
#include "type.h"

typedef int (*code)();
extern code DAT_008873ec_abs[];



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0021DD60
/* Free the shuffle-overlay work block; registered by btlShuffleStartOverlay. */
void btlShuffleDestroyOverlayWork(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_002230A0
/* Free the hero level-up work block; registered alongside btlResultHeroLvUpRun. */
void btlResultDestroyHeroLevelUpWork(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
