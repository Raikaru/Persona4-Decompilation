/* CRI Sofdec MW stream-server callback dispatch through func_0050b3d0. */
#include "cri_xpt.h"

extern Uint32 func_0050b3d0();

// FUN_00511AD0
void func_00511ad0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 *context = (Uint32 *)func_0050b3d0(a0, a1, a2, a3);
	void (*callback)(Uint32) = (void (*)(Uint32))context[20];
	Uint32 handle = context[21];
	if (callback != 0)
		callback(handle);
}
