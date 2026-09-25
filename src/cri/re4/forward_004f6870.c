/* CRI server delegates at the contiguous 0x004f6870 source boundary. */
#include "cri_xpt.h"

extern Uint32 func_004f9a58();
extern Uint32 func_004f99e0();
extern Uint32 func_004f99f8();

// FUN_004F6870
Uint32 func_004f6870(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f9a58(a0, a1, a2, a3);
}

// FUN_004F6888
Uint32 func_004f6888(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f99e0(a0, a1, a2, a3);
}

// FUN_004F68A0
Uint32 func_004f68a0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f99f8(a0, a1, a2, a3);
}
