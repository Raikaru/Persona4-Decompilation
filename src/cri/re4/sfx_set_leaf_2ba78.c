/* CRI Sofdec SFX settings (sfx_set.c) leaf: 32-bit store to offset 0x10. */
#include "cri_xpt.h"

// FUN_0052BA78
void func_0052ba78(Uint32 a0, Uint32 a1)
{
	*(Uint32 *)((Uint8 *)a0 + 0x10) = a1;
}
