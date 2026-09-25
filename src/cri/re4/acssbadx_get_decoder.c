/* ACSSBADX exposes its block decoder handle at offset 4. */
#include "cri_xpt.h"

extern Uint32 D_00756940[];

// FUN_004BE0C8
Uint32 func_004be0c8(Uint32 object)
{
	return *(Uint32 *)((Uint8 *)object + 4);
}

// FUN_004BE0D0
void func_004be0d0(Uint32 object)
{
	*(Uint32 *)((Uint8 *)object + 8) = 0;
	*(Uint32 *)((Uint8 *)object + 4) = 0;
	*(Uint32 *)object = (Uint32)D_00756940;
}
