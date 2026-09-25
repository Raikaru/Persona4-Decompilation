/* ADX RNA forwards renderer state without changing the caller's arguments. */
#include "cri_xpt.h"

extern Uint32 func_004ecb40();
extern Uint32 func_004ecba8();

// FUN_004CD750
Uint32 func_004cd750(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ecb40(a0, a1, a2, a3);
}

// FUN_004CD768
Uint32 func_004cd768(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004ecba8(a0, a1, a2, a3);
}
