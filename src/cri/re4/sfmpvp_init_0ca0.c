#include "cri_xpt.h"

extern Uint32 func_00520338();
extern Uint32 func_00520438();

// FUN_00520CA0
Uint32 func_00520ca0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_00520338(*(Uint32 *)((Uint8 *)a2 + 0x1fc0) + 0x1198, a1, a2, a3);
	return 1;
}

// FUN_00520CC8
Uint32 func_00520cc8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_00520438(*(Uint32 *)((Uint8 *)a2 + 0x1fc0) + 0x1198, a1, a2, a3);
	return 1;
}
