/* ADX stream-joint loop-position accessors delegate to the block decoder. */
#include "cri_xpt.h"

extern Uint32 func_004c3cc0();
extern Uint32 func_004c3cc8();

// FUN_004CEEC8
Uint32 func_004ceec8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3cc0(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CEEE0
Uint32 func_004ceee0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3cc8(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
