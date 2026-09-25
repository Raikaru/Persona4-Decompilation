#include "cri_xpt.h"

extern Uint32 func_004d4df0();
extern Uint32 func_004d4f58();
extern Uint32 func_004d5110();
extern Uint32 func_004d51c0();

// FUN_00512358
Uint32 func_00512358(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d4df0(*(Uint32 *)*(Uint32 *)((Uint8 *)a0 + 0x2004), a1, a2, a3);
}

// FUN_00512378
Uint32 func_00512378(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d4f58(*(Uint32 *)*(Uint32 *)((Uint8 *)a0 + 0x2004), a1, a2, a3);
}

// FUN_00512398
Uint32 func_00512398(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d5110(*(Uint32 *)*(Uint32 *)((Uint8 *)a0 + 0x2004), a1, a2, a3);
}

// FUN_005123B8
Uint32 func_005123b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d51c0(*(Uint32 *)*(Uint32 *)((Uint8 *)a0 + 0x2004), a1, a2, a3);
}
