/* Sofdec zoom/scaler delegates preserve incoming argument registers. */
#include "cri_xpt.h"

extern Uint32 func_004f9b88();
extern Uint32 func_004f9b08();
extern Uint32 func_0052cd98();
extern Uint32 func_0052cdf8();
extern Uint32 func_0052bf10();

// FUN_0052BE98
Uint32 func_0052be98(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f9b88(a0, a1, a2, a3);
}

// FUN_0052BEB0
Uint32 func_0052beb0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f9b08(a0, a1, a2, a3);
}

// FUN_0052BEC8
Uint32 func_0052bec8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052cd98(a0, a1, a2, a3);
}

// FUN_0052BEE0
Uint32 func_0052bee0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052cdf8(a0, a1, a2, a3);
}

// FUN_0052BEF8
Uint32 func_0052bef8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bf10(a0, a1, a2, a3);
}
