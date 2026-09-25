/* ACSS sound delegates forward through the object handle at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004ded60();
extern Uint32 func_004df220();
extern Uint32 func_004df2e8();
extern Uint32 func_004dee18();

// FUN_004BE2B8
Uint32 func_004be2b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ded60(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BE2D0
Uint32 func_004be2d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004df220(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BE2E8
Uint32 func_004be2e8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004df2e8(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BE300
Uint32 func_004be300(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004dee18(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
