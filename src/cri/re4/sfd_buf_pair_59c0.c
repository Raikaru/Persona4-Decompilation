#include "cri_xpt.h"

extern Uint32 func_00514ca8();
extern Uint32 func_00514c90();

// FUN_005159C0
Uint32 func_005159c0(Uint32 a0, Uint32 a1)
{
	Uint32 parts[8];

	func_00514ca8(a0, a1, parts);
	return parts[1] + parts[3];
}

// FUN_005159E8
Uint32 func_005159e8(Uint32 a0, Uint32 a1)
{
	Uint32 parts[8];

	func_00514c90(a0, a1, parts);
	return parts[1] + parts[3];
}
