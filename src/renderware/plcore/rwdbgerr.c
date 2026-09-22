/* rwdbgerr.c - RenderWare Graphics 3.7.0.2 core/src/plcore/rwdbgerr.c source mirror.
   Compiles with MWCCPS2 3.0.1 b119 (config/compiler_units.txt and
   config/version_flags.txt). No function in this source revision fingerprints
   byte-exact against retail, so this unit intentionally owns no FUN marker. */
#include "include_asm.h"

/**
 * defgroup rwcore RwCore
 *
 * Debug handling
 *
 ****************************************************************************
 *
 * This file is a product of Criterion Software Ltd.
 *
 * This file is provided as is with no warranties of any kind and is
 * provided without any obligation on Criterion Software Ltd.
 * to assist in its use or modification.
 *
 * Criterion Software Ltd. will not, under any
 * circumstances, be liable for any lost revenue or other damages arising
 * from the use of this file.
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 * All Rights Reserved.
 *
 * RenderWare is a trademark of Criterion Software Ltd.
 *
 ****************************************************************************/

/****************************************************************************
 Includes
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #include <rwcore.h> */
#include "batypes.h"
#include "balibtyp.h"

#ifdef RWDEBUG

/****************************************************************************
 Defines
 */

#define rwvsprintf  RWSRCGLOBAL(stringFuncs).vecVsprintf
#define rwstrcpy    RWSRCGLOBAL(stringFuncs).vecStrcpy
#define rwstrcat    RWSRCGLOBAL(stringFuncs).vecStrcat
#define rwstrlen    RWSRCGLOBAL(stringFuncs).vecStrlen

 /****************************************************************************
 Local (static) Globals
 */

/* The strings used in the debug error reporting are derived from the
 * .def files
 */

#define RWECODE(a,b) RWSTRING(b),

static const
RwChar         *rw_err_str[] =
{
#include "errcore.def"
};

#undef RWECODE
#define RWECODE(a,b) RWSTRING(#a),

static const RwChar *rw_err_cstr[] =
{
#include "errcore.def"
};

#undef RWECODE

extern RwChar dberr[512];  /* P4: file static, at its retail address */

RwChar         *
_rwdb_errcore(RwInt32 code,...)
{
    va_list         ap;

#if (0)
    RWFUNCTION(RWSTRING("_rwdb_errcore"));
#endif /* (0) */

    va_start(ap, code);

    rwstrcpy(dberr, rw_err_cstr[code]);
    rwstrcat(dberr, RWSTRING(" : "));
    rwvsprintf(&dberr[rwstrlen(dberr)], rw_err_str[code], ap);
    va_end(ap);
    return dberr;
}
#endif /* RWDEBUG */
