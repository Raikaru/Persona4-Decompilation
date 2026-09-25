/* Sound-unit pair setter at retail 004FBA98. */
#include "cri_xpt.h"

// FUN_004FBA98
void func_004fba98(Uint8 *unit, Uint32 first, Uint32 second)
{
	volatile Uint32 *pair = (volatile Uint32 *)(unit + 0x148);
	pair[1] = second;
	pair[0] = first;
}
