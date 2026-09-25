/* Sofdec zoom/scaler delegates forward through the subhandle at offset 0x24. */
#include "cri_xpt.h"

extern Uint32 SFXZ_SetZclip();
extern Uint32 func_0052c828();

// FUN_0052BBD8
Uint32 func_0052bbd8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return SFXZ_SetZclip(*(Uint32 *)((Uint8 *)a0 + 0x24), a1, a2, a3);
}

// FUN_0052BBF0
Uint32 func_0052bbf0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052c828(*(Uint32 *)((Uint8 *)a0 + 0x24), a1, a2, a3);
}
