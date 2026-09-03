/*
 * rwgrp.c - RenderWare Graphics 3.7 chunk groups (core/src/plcore/rwgrp.c),
 * ported verbatim and verified byte-exact against the retail image with
 * MWCCPS2 3.0.1 b119 (config/compiler_units.txt, -O2,p). Module statics are
 * externs at their retail addresses (config/symbol_data_addrs.txt) so the
 * unit links; functions not yet ported keep INCLUDE_ASM fallbacks in the
 * promoted code1_00XX.c units.
 */
#include "include_asm.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "babinary.h"
#include "batypes.h"
#include "balibtyp.h"
#include "bastream.h"
#include "osintf.h"
#include "bamemory.h"
#include "rwgrp.h"

/****************************************************************************
 Local Defines
 */

#define RWCHUNKGROUPGLOBAL(var) (RWPLUGINOFFSET(rwChunkGroupGlobals, RwEngineInstance, chunkGroupModule.globalsOffset)->var)

/****************************************************************************
 Local (static) Globals
 */

/* P4: file statics live at their retail addresses so the unit links. */
extern RwModuleInfo chunkGroupModule;
extern RwInt32 _rwChunkGroupFListBlockSize;
extern RwInt32 _rwChunkGroupFListPreallocBlocks;
extern RwFreeList _rwChunkGroupFList;

/* P4: not yet ported; keeps the func_ name until it is. */
#define RwFreeListCreateAndPreallocateSpace func_003e1220
extern RwFreeList *func_003e1220(RwInt32, RwInt32, RwInt32, RwInt32, RwFreeList *, RwUInt32);

// FUN_003E46E0
#pragma schedule on
void *
_rwChunkGroupOpen(void *instance,
             RwInt32 __RWUNUSED__ offset ,
             RwInt32 __RWUNUSED__ size )
{
    RWFUNCTION(RWSTRING("_rwChunkGroupOpen"));
    RWASSERT(instance);

    /* Store the globals offset (same for all instances) */
    chunkGroupModule.globalsOffset = offset;

    /* Get on with the initialization */
    RWCHUNKGROUPGLOBAL(groupFList) =
        RwFreeListCreateAndPreallocateSpace(sizeof(RwChunkGroup), _rwChunkGroupFListBlockSize, sizeof(RwUInt32),
        _rwChunkGroupFListPreallocBlocks, &_rwChunkGroupFList, rwID_CHUNKGROUPMODULE | rwMEMHINTDUR_GLOBAL);
    if (!RWCHUNKGROUPGLOBAL(groupFList))
    {
        /* Failure */
        RWRETURN(NULL);
    }

    /* One more module instance */
    chunkGroupModule.numInstances++;

    RWRETURN(instance);
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

