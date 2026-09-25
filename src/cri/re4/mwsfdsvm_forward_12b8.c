#include "cri_xpt.h"

extern Uint32 func_004f0e40();
extern Uint32 func_004cc200();

// FUN_005112B8
Uint32 func_005112b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f0e40(6, a1, a2, a3);
}

// FUN_005112D0
Uint32 func_005112d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004cc200(a0, a1, a2, a3);
}
