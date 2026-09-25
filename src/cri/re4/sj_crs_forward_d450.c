/* StreamJoint critical-section entry points forward unchanged to their backing routines. */
#include "cri_xpt.h"

extern Uint32 func_004f0608();
extern Uint32 func_004f0620();
extern Uint32 func_004f07e0();

// FUN_004ED450
Uint32 func_004ed450(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f0608(a0, a1, a2, a3);
}

// FUN_004ED468
Uint32 func_004ed468(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f0620(a0, a1, a2, a3);
}

// FUN_004ED480
Uint32 func_004ed480(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f07e0(a0, a1, a2, a3);
}
