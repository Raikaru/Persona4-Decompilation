/* Host transport interface entrypoints forward ABI registers to their transport helpers. */
#include "cri_xpt.h"

extern Uint32 func_004e4770();
extern Uint32 func_004e4648();
extern Uint32 func_004e4688();
extern Uint32 func_004e4698();
extern Uint32 func_004e46f0();

// FUN_004E7378
Uint32 func_004e7378(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e4770(a0, a1, a2, a3);
}

// FUN_004E7390
Uint32 func_004e7390(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e4648(a0, a1, a2, a3);
}

// FUN_004E73A8
Uint32 func_004e73a8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e4688(a0, a1, a2, a3);
}

// FUN_004E73C0
Uint32 func_004e73c0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e4698(a0, a1, a2, a3);
}

// FUN_004E73D8
Uint32 func_004e73d8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e46f0(a0, a1, a2, a3);
}
