/* Sofdec stream-list effects operations through the sub-effect state at offset 0xa8. */
#include "cri_xpt.h"

extern Uint32 func_0052ad30();
extern Uint32 func_0052ad40();
extern Uint32 func_0052ad50();

// FUN_0050FC78
Uint32 func_0050fc78(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ad30(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050FC90
Uint32 func_0050fc90(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ad40(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050FCA8
Uint32 func_0050fca8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ad50(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}
