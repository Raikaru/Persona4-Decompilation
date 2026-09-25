#include "cri_xpt.h"

extern Uint32 func_005265a0();

// FUN_00526630
Uint32 func_00526630(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 result = func_005265a0(0x5dc0, a1, a2, a3);
	*(Uint32 *)a3 = a0;
	return result;
}

// FUN_00526668
Uint32 func_00526668(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 result = func_005265a0(0x7530, a1, a2, a3);
	*(Uint32 *)a3 = a0;
	return result;
}

// FUN_005266A0
Uint32 func_005266a0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 result = func_005265a0(0xea60, a1, a2, a3);
	*(Uint32 *)a3 = a0;
	return result;
}
