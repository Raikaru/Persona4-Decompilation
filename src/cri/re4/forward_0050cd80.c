/* Sofdec transfer delegates at the contiguous 0x0050cd80 source boundary. */
#include "cri_xpt.h"

extern Uint32 func_004ccc98();
extern Uint32 func_0050c940();
extern Uint32 func_0050c9d0();

// FUN_0050CD80
Uint32 func_0050cd80(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ccc98(a0, a1, a2, a3);
}

// FUN_0050CD98
Uint32 func_0050cd98(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0050c940(a0, a1, a2, a3);
}

// FUN_0050CDB0
Uint32 func_0050cdb0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0050c9d0(a0, a1, a2, a3);
}
