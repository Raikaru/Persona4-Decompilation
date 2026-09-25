/* Contiguous CRI server lock delegates. */
#include "cri_xpt.h"

extern Uint32 func_004f0608();
extern Uint32 func_004f0620();

// FUN_004CC9D0
Uint32 func_004cc9d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f0608(a0, a1, a2, a3);
}

// FUN_004CC9E8
Uint32 func_004cc9e8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f0620(a0, a1, a2, a3);
}
