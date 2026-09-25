/* Sofdec server mode delegates and completion-status wrappers. */
#include "cri_xpt.h"

extern Uint32 func_004f0638();
extern Uint32 func_004f06b0();
extern Uint32 func_004f0650();
extern Uint32 func_004f06c8();
extern Uint32 func_004f0668();
extern Uint32 func_004f06e0();
extern Uint32 func_004f0680();

// FUN_00511128
Uint32 func_00511128(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_004f0638(a0, a1, a2, a3);
	return 1;
}

// FUN_00511148
Uint32 func_00511148(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f06b0(a0, a1, a2, a3);
}

// FUN_00511160
Uint32 func_00511160(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_004f0650(a0, a1, a2, a3);
	return 1;
}

// FUN_00511180
Uint32 func_00511180(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f06c8(a0, a1, a2, a3);
}

// FUN_00511198
Uint32 func_00511198(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_004f0668(a0, a1, a2, a3);
	return 1;
}

// FUN_005111B8
Uint32 func_005111b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004f06e0(a0, a1, a2, a3);
}

// FUN_005111D0
Uint32 func_005111d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_004f0680(a0, a1, a2, a3);
	return 1;
}
