/* Sign-extended halfword field at offset 0x3e. */
#include "cri_xpt.h"

// FUN_004d5758
Sint16 func_004d5758(Uint32 object)
{
	return *(Sint16 *)((Uint8 *)object + 0x3e);
}
