/* ADX critical-section helper adapter followed by two distinct no-op callbacks. */
#include "cri_xpt.h"

extern Uint32 func_004d2d78();
extern void func_004c54d8(void);
extern void func_004c54e0(void);

// FUN_004C9D00
Uint32 func_004c9d00(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d2d78(a0, a1, a2, a3);
}

// FUN_004C9D18
void func_004c9d18(void)
{
	func_004c54d8();
}

// FUN_004C9D30
void func_004c9d30(void)
{
	func_004c54e0();
}
