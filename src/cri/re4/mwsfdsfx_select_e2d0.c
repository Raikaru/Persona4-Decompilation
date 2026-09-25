/* Sofdec effect settings update related selector values on the same handle. */
#include "cri_xpt.h"

extern Uint32 func_00524d90();
extern Uint32 func_00517eb8();

// FUN_0050E2D0
Uint32 func_0050e2d0(Uint32 settings, Uint32 first, Uint32 second)
{
	func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x4e, second);
	return func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x4d, first);
}

// FUN_0050E318
Uint32 func_0050e318(Uint32 settings, Uint32 first, Uint32 second)
{
	func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5c, second);
	return func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5b, first);
}

// FUN_0050E360
Uint32 func_0050e360(Uint32 settings, Uint32 first, Uint32 second)
{
	func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5f, second);
	return func_00524d90(*(Uint32 *)((Uint8 *)settings + 0x3c), 0x5f, first);
}

// FUN_0050E3A8
Uint32 func_0050e3a8(Uint32 settings, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00517eb8(*(Uint32 *)((Uint8 *)settings + 0x3c), a1, a2, a3);
}
