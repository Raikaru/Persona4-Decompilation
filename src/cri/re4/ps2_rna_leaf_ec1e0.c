/* CRI PS2 RNA (ps2_rna.c) leaf: signed byte field at offset 0x57. */
#include "cri_xpt.h"

// FUN_004EC1E0
Sint32 func_004ec1e0(Uint32 object)
{
	return *(Sint8 *)((Uint8 *)object + 0x57);
}
