/* ACSS sound operation delegated to the decoder handle. */
#include "cri_xpt.h"

extern Uint32 func_004df068(Uint32 handle);

// FUN_004BE3D8
Uint32 func_004be3d8(Uint32 *object)
{
	return func_004df068(object[1]);
}
