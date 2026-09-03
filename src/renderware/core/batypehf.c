/* batypehf.c - RenderWare Graphics 3.7.0.2 core/src/batypehf.c, verbatim;
   verified byte-exact against the retail image with MWCCPS2 3.0.1 b119
   (config/compiler_units.txt, config/version_flags.txt). File-scope statics
   are externs at their retail addresses (config/symbol_data_addrs.txt). */
#include "include_asm.h"

/* P4: callees not yet ported under their RenderWare names; the header
   prototypes then declare the retail func_ symbols. */
#define RwFrameUpdateObjects func_003e9680

/*
 * Generic type handling
 * Generic types enable limitted polymorphism capabilities in RenderWare
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 */


/****************************************************************************
 Includes
 */

#include <stdlib.h>

#include "batypes.h"
#include "balibtyp.h"
#include "badebug.h"

#include "batypehf.h"

/****************************************************************************
 Local Types
 */

/****************************************************************************
 Local (Static) Prototypes
 */

/****************************************************************************
 Local Defines
 */

/****************************************************************************
 Globals (across program)
 */

/****************************************************************************
 Local (static) Globals
 */

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   Generic types

   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

#if (defined(DOXYGEN))

/**
 * \ingroup rwobject
 * \ref RwObjectGetType is used to retrieve the type ID of the specified
 * object. The ID can be used to identify the type of the object.
 *
 * \param object  Pointer to the object.
 *
 * \return Returns aa \ref RwUInt32 value equal to the type ID. Supported
 * types are:
 *
 *     \li rwCAMERA        Object has type \ref RwCamera
 *     \li rwFRAME         Object has type \ref RwFrame
 *     \li rwTEXDICTIONARY Object has type \ref RwTexDictionary
 *     \li rpATOMIC        Object has type \ref RpAtomic
 *     \li rpCLUMP         Object has type \ref RpClump
 *     \li rpGEOMETRY      Object has type \ref RpGeometry
 *     \li rpLIGHT         Object has type \ref RpLight
 *     \li rpWORLD         Object has type \ref RpWorld
 */
RwUInt32
RwObjectGetType(RwObject * object)
{
    RWAPIFUNCTION(RWSTRING("RwObjectGetType"));

    RWRETURN(0);
}

#endif /* (defined(DOXYGEN)) */

 /****************************************************************************
 RwHasFrameObjectSetFrame

 On entry   : Object
 On exit    :
 */

// FUN_003EFD20
#pragma schedule on
void
_rwObjectHasFrameSetFrame(void *object, RwFrame * frame)
{
    RwObjectHasFrame   *ohf = (RwObjectHasFrame *) object;

    RWFUNCTION(RWSTRING("_rwObjectHasFrameSetFrame"));

    if (rwObjectGetParent(ohf))
    {
        rwLinkListRemoveLLLink(&ohf->lFrame);
    }

    /* Set the pointer */
    rwObjectSetParent(object, frame);

    /* Add it to the frames list of objects */
    if (frame)
    {
        rwLinkListAddLLLink(&frame->objectList, &ohf->lFrame);

        /* Force the objects using this frame to be updated */
        RwFrameUpdateObjects(frame);
    }

    /* All done */
    RWRETURNVOID();
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/****************************************************************************
 _rwObjectHasFrameReleaseFrame

 On entry   : Object
 On exit    :
 */

// FUN_003EFDA0
#pragma schedule on
void
_rwObjectHasFrameReleaseFrame(void *object)
{
    RwObjectHasFrame   *ohf = (RwObjectHasFrame *) object;

    RWFUNCTION(RWSTRING("_rwObjectHasFrameReleaseFrame"));

    if (rwObjectGetParent(ohf))
    {
        rwLinkListRemoveLLLink(&ohf->lFrame);
    }

    RWRETURNVOID();
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off


/**
 * \ingroup rwobject
 * \page rwobjectoverview RwObject Overview
 *
 * \par Requirements
 * \li \b Headers: rwcore.h
 * \li \b Libraries: rwcore.lib
 *
 * \subsection objectoverview Overview
 *
 * A base object from which some RenderWare objects are derived.
 *
 * RwObject-derived objects are:
 * - \ref RwCamera
 * - \ref RwFrame
 * - \ref RwTexDictionary
 * - \ref RpAtomic
 * - \ref RpClump
 * - \ref RpGeometry
 * - \ref RpLight
 * - \ref RpWorld
 *
 * It is therefore possible to write functions that
 * simulate C++'s polymorphism features
 * by querying the RwObject ID of a passed RwObject
 * and acting on the result.
 */
