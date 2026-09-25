/* Sign-extended byte field at offset 1. */
#include "cri_xpt.h"

// FUN_004d2030
Sint8 func_004d2030(Uint32 object)
{
	return *(Sint8 *)((Uint8 *)object + 1);
}
