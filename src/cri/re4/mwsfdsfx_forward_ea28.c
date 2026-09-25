#include "cri_xpt.h"

extern Uint32 func_0052ba80();
extern Uint32 func_0052bad0();

// FUN_0050EA28
Uint32 func_0050ea28(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ba80(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050EA40
Uint32 func_0050ea40(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bad0(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}
