/* ACSSND start operations; the four diagnostics identify their distinct entry points. */
#include "cri_xpt.h"

extern Char8 D_00756D80[];
extern Char8 D_00756DB8[];
extern Char8 D_00756DE8[];
extern Char8 D_00756E18[];
extern void func_004bd6a0(const void *message);
extern void *strncpy(void *destination, const void *source, Uint32 length);
extern void ACSSND_Start(Uint32 *object, Uint32 *request);

// FUN_004BEAA0
void ACSSND_StartFname(Uint32 *object, const void *filename)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756D80);
		return;
	}
	object[0x30 / 4] = 0;
	strncpy((void *)object[0x34 / 4], filename, 0x100);
	ACSSND_Start(object, object + 0x30 / 4);
}

// FUN_004BEB00
void ACSSND_StartAfs(Uint32 *object, Uint32 archive, Uint32 index)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756DB8);
		return;
	}
	object[0x38 / 4] = archive;
	object[0x3c / 4] = index;
	object[0x30 / 4] = 1;
	ACSSND_Start(object, object + 0x30 / 4);
}

// FUN_004BEB50
void ACSSND_StartMem(Uint32 *object, Uint32 memory, Uint32 size)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756DE8);
		return;
	}
	object[0x40 / 4] = memory;
	object[0x44 / 4] = size;
	object[0x30 / 4] = 2;
	ACSSND_Start(object, object + 0x30 / 4);
}

// FUN_004BEBA0
void ACSSND_StartMemIdx(Uint32 *object, Uint32 memory, Uint32 index)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756E18);
		return;
	}
	object[0x48 / 4] = memory;
	object[0x4c / 4] = index;
	object[0x30 / 4] = 3;
	ACSSND_Start(object, object + 0x30 / 4);
}
