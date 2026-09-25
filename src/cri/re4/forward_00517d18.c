/* Contiguous Sofdec player delegates. */
#include "cri_xpt.h"

extern Uint32 func_004edf18();
extern Uint32 func_004edf98();

// FUN_00517D18
Uint32 func_00517d18(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004edf18(a0, a1, a2, a3);
}

// FUN_00517D30
Uint32 func_00517d30(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004edf98(a0, a1, a2, a3);
}
