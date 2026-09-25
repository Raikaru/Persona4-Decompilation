/* CRI Sofdec MW stream-server callback dispatch through func_0050b3d0. */
#include "cri_xpt.h"

extern Uint32 func_0050b3d0();

// FUN_00511A38
void func_00511a38(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 *context = (Uint32 *)func_0050b3d0(a0, a1, a2, a3);
	void (*callback)(Uint32) = (void (*)(Uint32))context[16];
	Uint32 handle = context[17];
	if (callback != 0)
		callback(handle);
}

// FUN_00511A68
void func_00511a68(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 *context = (Uint32 *)func_0050b3d0(a0, a1, a2, a3);
	void (*callback)(Uint32) = (void (*)(Uint32))context[18];
	Uint32 handle = context[19];
	if (callback != 0)
		callback(handle);
}

