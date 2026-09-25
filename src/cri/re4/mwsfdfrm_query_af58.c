/* Sofdec frame query helpers; the result word is filled through a stack local. */
#include "cri_xpt.h"

extern Uint32 func_00529750();
extern Uint32 func_005297a0();

// FUN_0050AF58
Sint32 func_0050af58(Uint32 a0)
{
	Uint32 local;

	if (func_00529750(a0, &local) == 1)
		return (Sint32)local;
	return -1;
}

// FUN_0050AF88
Sint32 func_0050af88(Uint32 a0)
{
	Uint32 local;

	if (func_005297a0(a0, &local) == 1)
		return (Sint32)local;
	return -1;
}
