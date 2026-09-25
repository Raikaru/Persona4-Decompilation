/* Sofdec settings delegates through the configuration handle at offset 0x40. */
#include "cri_xpt.h"

extern Uint32 func_005120e0();
extern Uint32 func_00511f98();
extern Uint32 func_00511fc0();

// FUN_0050D3C0
Uint32 func_0050d3c0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_005120e0(*(Uint32 *)((Uint8 *)a0 + 0x40), a1, a2, a3);
}

// FUN_0050D3D8
Uint32 func_0050d3d8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00511f98(*(Uint32 *)((Uint8 *)a0 + 0x40), a1, a2, a3);
}

// FUN_0050D3F0
Uint32 func_0050d3f0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00511fc0(*(Uint32 *)((Uint8 *)a0 + 0x40), a1, a2, a3);
}
