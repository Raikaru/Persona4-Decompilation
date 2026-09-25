/* Contiguous Sofdec state-control delegates. */
#include "cri_xpt.h"

extern Uint32 func_004fb228();
extern Uint32 func_004fb250();
extern Uint32 func_004fb280();

// FUN_005074F0
Uint32 func_005074f0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004fb228(a0, a1, a2, a3);
}

// FUN_00507508
Uint32 func_00507508(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004fb250(a0, a1, a2, a3);
}

// FUN_00507520
Uint32 func_00507520(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004fb280(*(Uint32 *)((Uint8 *)a0 + 0x3b0), a1, a2, a3);
}
