/* ADX stream-joint delegates through the block decoder at offset 0x04. */
#include "cri_xpt.h"

extern Uint32 func_004c3d70();
extern Uint32 func_004c3dd8();
extern Uint32 func_004c3e20();

// FUN_004CEC38
Uint32 func_004cec38(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3d70(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CEC50
Uint32 func_004cec50(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3dd8(a0, a1, a2, a3);
}

// FUN_004CEC68
Uint32 func_004cec68(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3e20(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
