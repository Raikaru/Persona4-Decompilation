/* Halfword store of zero at offset 0x9a. */
#include "cri_xpt.h"

// FUN_004c3978
void func_004c3978(Uint32 object)
{
	*(Sint16 *)((Uint8 *)object + 0x9a) = 0;
}
