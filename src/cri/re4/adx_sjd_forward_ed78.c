/* ADX stream-joint format accessors forward through the block decoder at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004c3bc0();
extern Uint32 func_004c3bc8();

// FUN_004CED78
Uint32 func_004ced78(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3bc0(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CED90
Uint32 func_004ced90(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3bc8(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
