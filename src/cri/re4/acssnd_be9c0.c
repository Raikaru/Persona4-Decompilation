/* Release each sound channel, its attached decoder and its output buffer. */
#include "cri_xpt.h"

extern void func_004bd720(Uint32 handle);
extern void func_004be150(Uint32 *handle);
extern void func_004bde10(Uint32 *handle);
typedef void (*ACSSND_CloseBuffer)(Uint32 handle);

// FUN_004BE9C0
void func_004be9c0(Uint32 *object)
{
	Sint32 i;
	Uint32 handle;

	if (object[0x50 / 4] != 1 && object[0x54 / 4] != 1) {
		return;
	}
	object[0x50 / 4] = 0;
	object[0x54 / 4] = 0;
	for (i = 0; i < (Sint32)object[0xA0 / 4]; i++) {
		func_004bd720(object[(0x20 / 4) + 3 * i]);
		handle = object[i];
		if (handle != 0) {
			(*(ACSSND_CloseBuffer *)(*(Uint32 *)handle + 4))(handle);
			if (object[0x94 / 4] != 0) {
				func_004be150((Uint32 *)object[i]);
			} else {
				func_004bde10((Uint32 *)object[i]);
			}
		}
	}
}
