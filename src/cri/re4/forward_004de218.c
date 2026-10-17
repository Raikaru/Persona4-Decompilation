/* CRI object delegates through the first word of the stream handle. */
#include "cri_xpt.h"

extern Uint32 AHXDCD_GetOutVol();
extern Uint32 AHXDCD_GetDrctLvl();
extern Uint32 AHXDCD_GetFx();
extern Uint32 AHXDCD_GetOutPan();
extern Uint32 AHXDCD_SetExtString();
extern Uint32 AHXDCD_SetExtPrm();

// FUN_004DE218
Uint32 func_004de218(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_GetOutVol(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE230
Uint32 func_004de230(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_GetDrctLvl(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE248
Uint32 func_004de248(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_GetFx(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE260
Uint32 func_004de260(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_GetOutPan(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE278
Uint32 func_004de278(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_SetExtString(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE290
Uint32 func_004de290(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return AHXDCD_SetExtPrm(*(Uint32 *)a0, a1, a2, a3);
}
