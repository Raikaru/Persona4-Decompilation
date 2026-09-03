
























#ifndef RPRANDOM_H
#define RPRANDOM_H

/**
 * \defgroup rprandom RpRandom
 * \ingroup mathtools
 *
 * Random Number Generation Plugin for RenderWare Graphics.
 */

/*--- Include files ---*/
#include "rwcore.h"

#include "rprandom.rpe"    /* automatically generated header file */

/*--- Plugin API Functions ---*/

#define RPRANDMAX (~((~0)<<31))

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

RwBool RpRandomPluginAttach(void);

/* Getting values */

extern RwUInt32 RpRandom(void);
extern void RpRandomSeed(RwUInt32 seed);

extern RwUInt32 RpRandomMT(void);
extern void RpRandomSeedMT(RwUInt32 seed);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#endif /* RPRANDOM_H */

