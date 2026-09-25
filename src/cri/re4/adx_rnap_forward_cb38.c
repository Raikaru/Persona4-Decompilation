/* ADX RNA delegates to the stream-time accessor and PS2 renderer. */
#include "cri_xpt.h"

extern Uint32 func_004cca10();
extern Uint32 func_004cb2d0();

// FUN_004CCB38
Uint32 func_004ccb38(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004cca10(a0, a1, a2, a3);
}

// FUN_004CCB50
Uint32 func_004ccb50(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004cb2d0(a0, a1, a2, a3);
}
