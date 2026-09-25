/* Sofdec effect delegates through the active sub-effect at offset 0xa8. */
#include "cri_xpt.h"

extern Uint32 func_0052ad18();
extern Uint32 func_0052ad20();

// FUN_0050FC48
Uint32 func_0050fc48(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ad18(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050FC60
Uint32 func_0050fc60(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052ad20(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}
