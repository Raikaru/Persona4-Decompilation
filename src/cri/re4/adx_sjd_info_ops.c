/* ADX stream-joint format metadata delegates through its block decoder. */
#include "cri_xpt.h"

extern Uint32 func_004c3c80();
extern Uint32 func_004c3c90();
extern Uint32 func_004c3c88();

// FUN_004CEE20
Uint32 func_004cee20(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3c80(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CEE38
Uint32 func_004cee38(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3c90(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004CEE50
Uint32 func_004cee50(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3c88(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
