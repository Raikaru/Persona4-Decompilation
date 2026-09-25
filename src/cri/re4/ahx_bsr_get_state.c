/* AHX bitstream reader state is held at offset 0x10. */
#include "cri_xpt.h"

// FUN_004D9878
Uint32 func_004d9878(Uint32 object)
{
	return *(Uint32 *)((Uint8 *)object + 0x10);
}
