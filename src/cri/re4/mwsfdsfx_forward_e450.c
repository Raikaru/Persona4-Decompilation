#include "cri_xpt.h"

extern Uint32 func_00511220();
extern Uint32 func_0052b6c8();

// FUN_0050E450
Uint32 func_0050e450(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00511220(a1, a1, a2, a3);
}

// FUN_0050E468
Uint32 func_0050e468(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052b6c8(a0, a1, a2, a3);
}
