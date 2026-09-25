/* CRI Sofdec MW stream-server (mwsfdsvr.c) leaf: 32-bit field at offset 0x64. */
#include "cri_xpt.h"

// FUN_00511DD8
Uint32 func_00511dd8(Uint32 object)
{
	return *(Uint32 *)((Uint8 *)object + 0x64);
}
