/* ACSSND start operations; the four diagnostics identify their distinct entry points. */
#include "cri_xpt.h"

extern Char8 D_00756D80[];
extern Char8 D_00756DB8[];
extern Char8 D_00756DE8[];
extern Char8 D_00756E18[];
extern void func_004bd6a0(const void *message);
extern void *func_00442de8(void *destination, const void *source, Uint32 length);
extern void func_004bfca0(Uint32 *object, Uint32 *request);

// FUN_004BEAA0
void func_004beaa0(Uint32 *object, const void *filename)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756D80);
		return;
	}
	object[0x30 / 4] = 0;
	func_00442de8((void *)object[0x34 / 4], filename, 0x100);
	func_004bfca0(object, object + 0x30 / 4);
}

// FUN_004BEB00
void func_004beb00(Uint32 *object, Uint32 archive, Uint32 index)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756DB8);
		return;
	}
	object[0x38 / 4] = archive;
	object[0x3c / 4] = index;
	object[0x30 / 4] = 1;
	func_004bfca0(object, object + 0x30 / 4);
}

// FUN_004BEB50
void func_004beb50(Uint32 *object, Uint32 memory, Uint32 size)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756DE8);
		return;
	}
	object[0x40 / 4] = memory;
	object[0x44 / 4] = size;
	object[0x30 / 4] = 2;
	func_004bfca0(object, object + 0x30 / 4);
}

// FUN_004BEBA0
void func_004beba0(Uint32 *object, Uint32 memory, Uint32 index)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756E18);
		return;
	}
	object[0x48 / 4] = memory;
	object[0x4c / 4] = index;
	object[0x30 / 4] = 3;
	func_004bfca0(object, object + 0x30 / 4);
}
