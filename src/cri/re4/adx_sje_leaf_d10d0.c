/* Sign-extended byte field at offset 1. */
#include "cri_xpt.h"

// FUN_004d10d0
Sint8 func_004d10d0(Uint32 object)
{
	return *(Sint8 *)((Uint8 *)object + 1);
}
