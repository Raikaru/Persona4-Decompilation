/* Pause or resume every sound channel in its twelve-byte record. */
#include "cri_xpt.h"

extern Char8 D_00756E80[];
extern void func_004bd6a0(const void *message);
extern void func_004bd658(void);
extern void func_004bd670(void);
typedef void (*ACSSND_PauseOperation)(Uint32 handle, Sint32 paused);

// FUN_004BED38
void ACSSND_Pause(Uint32 *object, Sint32 paused)
{
	Uint32 *channel;
	Uint32 handle;
	Sint32 i;

	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756E80);
		return;
	}
	func_004bd658();
	for (i = 0; i < (Sint32)object[0xa0 / 4]; i++) {
		channel = (Uint32 *)((Uint8 *)object + 0x18 + i * 12);
		handle = channel[0];
		(*(ACSSND_PauseOperation *)(*(Uint32 *)handle + 0x1c))(handle, paused);
	}
	object[0x60 / 4] = paused;
	func_004bd670();
}
