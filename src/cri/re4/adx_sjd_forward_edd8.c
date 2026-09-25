/* ADX stream-joint metadata accessors forward through the block decoder at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004c3c68();
extern Uint32 func_004c3c70();

// FUN_004CEDD8
Uint32 func_004cedd8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3c68(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CEDF0
Uint32 func_004cedf0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3c70(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
