#ifndef SDK_DBPRT_H
#define SDK_DBPRT_H

#include "type.h"

/* The low/high words of position hold the X/Y floating-point coordinates. */
void H_Dbprt_FmtAt(s64 position, const char* format, ...);

#endif
