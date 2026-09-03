/*
 * osintf.h - RenderWare OS interface for the PlayStation 2 build.
 *
 * The 3.7.0.2 source tree carries only core/os/win/osintf.h; this is that
 * header's platform-independent part (the only part the core sources use).
 */
#ifndef    _OSINTF_H
#define    _OSINTF_H

#include "batypes.h"

#define SLASH '/'

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef TRUE
#undef TRUE
#endif
#define TRUE !FALSE

#define RwIsAlpha(_c) \
   (  ( ((_c)>='A') && ((_c)<='Z') ) || \
      ( ((_c)>='a') && ((_c)<='z') ) )

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern int _rwpathisabsolute (const RwChar *path);
extern RwChar *_rwgetcurrenttime(RwChar *buffer, RwInt32 bufSiz);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#endif /* _OSINTF_H */
