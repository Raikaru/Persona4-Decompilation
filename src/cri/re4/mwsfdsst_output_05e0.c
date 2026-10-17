/* Sofdec side-stream output wrappers. */
#include "cri_xpt.h"

extern Uint32 MWSST_CalcAdxWorkSize(Uint32 *out0, Uint32 *out1, Uint32 *out2, Uint32 a3);
extern Uint32 MWSST_CalcAixWorkSize(Uint32 *out0, Uint32 *out1, Uint32 *out2, Uint32 a3);

// FUN_005105E0
Uint32 func_005105e0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 output[3];

	return MWSST_CalcAdxWorkSize(&output[0], &output[1], &output[2], a3);
}

// FUN_00510608
Uint32 func_00510608(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 output[3];

	return MWSST_CalcAixWorkSize(&output[0], &output[1], &output[2], a3);
}
