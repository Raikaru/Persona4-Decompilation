/* ADX RNA delegates the last renderer operations without altering arguments. */
#include "cri_xpt.h"

extern Uint32 func_004ed180();
extern Uint32 func_004ed240();

// FUN_004CD8D8
Uint32 func_004cd8d8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ed180(a0, a1, a2, a3);
}

// FUN_004CD8F0
Uint32 func_004cd8f0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ed240(a0, a1, a2, a3);
}
