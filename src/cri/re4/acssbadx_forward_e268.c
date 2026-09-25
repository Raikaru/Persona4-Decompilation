/* Audio stream operations forwarded to the decoder handle stored at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004deb58();
extern Uint32 func_004decb8();

// FUN_004BE268
Uint32 func_004be268(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004deb58(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BE280
Uint32 func_004be280(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004decb8(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
