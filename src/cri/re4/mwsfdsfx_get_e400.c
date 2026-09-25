#include "cri_xpt.h"

extern void func_00524ff8();

// FUN_0050E400
Uint32 func_0050e400(void)
{
	Uint32 value;
	func_00524ff8(0, 0x3d, &value);
	return value;
}
