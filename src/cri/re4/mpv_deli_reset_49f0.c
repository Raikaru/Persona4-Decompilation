/* CRI MPEG delimiter state reset at retail 005049F0..00504A10. */
#include "cri_xpt.h"

extern Uint32 D_00743D38[];

void func_00504a10(Uint32 *state);

// FUN_005049F0
void func_005049f0(void)
{
	func_00504a10(D_00743D38);
}

// FUN_00504A10
void func_00504a10(Uint32 *state)
{
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;
}
