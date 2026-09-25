#include "cri_xpt.h"

extern Uint32 MWSFSFX_SetOutBufSize();
extern Uint32 mwPlyFxGetOutBufPitchHeight();

// FUN_0050EDF8
Uint32 func_0050edf8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return MWSFSFX_SetOutBufSize(a0, a1, a2, 0);
}

// FUN_0050EE10
Uint32 func_0050ee10(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return mwPlyFxGetOutBufPitchHeight(a0, a1, a2, a3);
}
