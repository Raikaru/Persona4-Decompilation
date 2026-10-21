#include "type.h"

typedef int (*code)();
extern code DAT_008873ec_abs[];


// kwlnTaskGetWork is left undeclared because a typed prototype adds zero-extension code that retail
// does not have.

// FUN_0021DD60
/* Free the shuffle-overlay work block; registered by btlShuffleStartOverlay. */
void btlShuffleDestroyOverlayWork(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}


// kwlnTaskGetWork is left undeclared on purpose: a typed prototype adds zero-extension code that
// retail does not have.

// FUN_002230A0
/* Free the hero level-up work block; registered alongside btlResultHeroLvUpRun. */
void btlResultDestroyHeroLevelUpWork(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
