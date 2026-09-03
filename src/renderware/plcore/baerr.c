/*
 * baerr.c - RenderWare Graphics 3.7 error handling (core/src/plcore/baerr.c),
 * ported verbatim and verified byte-exact against the retail image with
 * MWCCPS2 3.0.1 b119 (config/compiler_units.txt, -O2,p). Module statics are
 * externs at their retail addresses (config/symbol_data_addrs.txt) so the
 * unit links; functions not yet ported keep INCLUDE_ASM fallbacks in the
 * promoted code1_00XX.c units.
 */
#include "include_asm.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "batypes.h"
#include "balibtyp.h"

/* Error handling */
#include "baerr.h"
#include "badebug.h"

/****************************************************************************
 Local Defines
 */

#define RWERRORGLOBAL(var) \
    (RWPLUGINOFFSET(rwErrorGlobals, RwEngineInstance, \
    errorModule.globalsOffset)->var)

/****************************************************************************
 Local (static) Globals
 */

/* P4: file statics live at their retail addresses so the unit links. */
extern RwModuleInfo errorModule;

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   Error handling

   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// FUN_003DF480
#pragma schedule on
void *
_rwErrorOpen(void *object, RwInt32 offset, RwInt32 __RWUNUSED__ size )
{
    RWFUNCTION(RWSTRING("_rwErrorOpen"));

    /* Cache the globals offset */
    errorModule.globalsOffset = offset;

    /* One more module instance */
    errorModule.numInstances++;

    /* Initialise the variables */
    RWERRORGLOBAL(errorCode).pluginID = 0;
    RWERRORGLOBAL(errorCode).errorCode = (RwInt32) E_RW_NOERROR;

    /* All done */
    RWRETURN(object);
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003DF4B0
#pragma schedule on
void *
_rwErrorClose(void *object,
              RwInt32 __RWUNUSED__ offset ,
              RwInt32 __RWUNUSED__ size)
{
    RWFUNCTION(RWSTRING("_rwErrorClose"));

    /* One less module instance */
    errorModule.numInstances--;

    RWRETURN(object);
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off


// FUN_003DF4D0
#pragma schedule on
RwError *
RwErrorSet(RwError *code)
{
    RWAPIFUNCTION(RWSTRING("RwErrorSet"));
    RWASSERT(code);

    if ((RWERRORGLOBAL(errorCode).pluginID == 0x0) &&
        (RWERRORGLOBAL(errorCode).errorCode == (RwInt32) E_RW_NOERROR))
    {
        if (code->errorCode & 0x80000000)
        {
            /* common error */
            RWERRORGLOBAL(errorCode).pluginID = 0x0;
        }
        else
        {
            /* plugin error */
            RWERRORGLOBAL(errorCode).pluginID = code->pluginID;
        }
        /* No current error status */
        RWERRORGLOBAL(errorCode).errorCode = code->errorCode;
    }
    RWRETURN(code);
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off


// FUN_003DF550
#pragma schedule on
RwError *
RwErrorGet(RwError *code)
{
    RWAPIFUNCTION(RWSTRING("RwErrorGet"));
    RWASSERT(code);

    *code = RWERRORGLOBAL(errorCode);
    RWERRORGLOBAL(errorCode).pluginID = 0x0;
    RWERRORGLOBAL(errorCode).errorCode = (RwInt32) E_RW_NOERROR;

    RWRETURN(code);
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

