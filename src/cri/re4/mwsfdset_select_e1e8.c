/* Sofdec settings selectors through the handle at offset 0x3c. */
#include "cri_xpt.h"

extern Uint32 func_00524d90();

// FUN_0050E1E8
Uint32 func_0050e1e8(Uint32 a0, Uint32 a1)
{
	return func_00524d90(*(Uint32 *)((Uint8 *)a0 + 0x3c), 0x4f, a1);
}

// FUN_0050E208
Uint32 func_0050e208(Uint32 a0, Uint32 a1)
{
	return func_00524d90(*(Uint32 *)((Uint8 *)a0 + 0x3c), 0x50, a1);
}

// FUN_0050E228
Uint32 func_0050e228(Uint32 a0, Uint32 a1)
{
	return func_00524d90(*(Uint32 *)((Uint8 *)a0 + 0x3c), 0x49, a1);
}

// FUN_0050E248
Uint32 func_0050e248(Uint32 a0, Uint32 a1)
{
	return func_00524d90(*(Uint32 *)((Uint8 *)a0 + 0x3c), 0x38, a1);
}

// FUN_0050E268
Uint32 func_0050e268(Uint32 a0, Uint32 a1)
{
	return func_00524d90(*(Uint32 *)((Uint8 *)a0 + 0x3c), 0x39, a1);
}

// FUN_0050E288
Uint32 func_0050e288(Uint32 settings, Uint32 first, Uint32 second)
{
	func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5d, first);
	return func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5e, second);
}
