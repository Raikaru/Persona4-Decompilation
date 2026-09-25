/* Sofdec zoom/scaler delegates forward through the subhandle at offset 0x30. */
#include "cri_xpt.h"

extern Uint32 func_0052a668();
extern Uint32 func_0052a688();

// FUN_0052BC28
Uint32 func_0052bc28(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052a668(*(Uint32 *)((Uint8 *)a0 + 0x30), a1, a2, a3);
}

// FUN_0052BC40
Uint32 func_0052bc40(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052a688(*(Uint32 *)((Uint8 *)a0 + 0x30), a1, a2, a3);
}
