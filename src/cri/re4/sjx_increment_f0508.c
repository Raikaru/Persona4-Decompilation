/* SJX halfword counter increment at retail 004F0508. */
#include "cri_xpt.h"

// FUN_004F0508
void func_004f0508(Uint8 *object)
{
	++*(Uint16 *)(object + 2);
}
