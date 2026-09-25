/* CRI DTR (dtr.c) leaf: signed byte field at offset 2. */
#include "cri_xpt.h"

// FUN_004E39B0
Sint32 func_004e39b0(Uint32 object)
{
	return *(Sint8 *)((Uint8 *)object + 2);
}
