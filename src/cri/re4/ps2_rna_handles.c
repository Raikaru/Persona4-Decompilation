/* PS2 RNA output delegates through its playback stream at offset 0xe8. */
#include "cri_xpt.h"

extern Uint32 func_004eae58();
extern Uint32 func_004eaf58();
extern Uint32 func_004c6a98();

// FUN_004EB2D0
Uint32 func_004eb2d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004eae58(*(Uint32 *)((Uint8 *)a0 + 0xe8), a1, a2, a3);
}

// FUN_004EB2E8
Uint32 func_004eb2e8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004eaf58(*(Uint32 *)((Uint8 *)a0 + 0xe8), a1, a2, a3);
}

// FUN_004EB300
Uint32 func_004eb300(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c6a98(a1, a1, a2, a3);
}
