/* Sofdec stream-list output wrapper. */
#include "cri_xpt.h"

extern Uint32 func_00510630(Uint32 *out0, Uint32 *out1, Uint32 *out2, Uint32 a3);

// FUN_005105B8
Uint32 func_005105b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 output[3];

	return func_00510630(&output[0], &output[1], &output[2], a3);
}
