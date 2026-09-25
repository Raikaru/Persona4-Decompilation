/* ACSS sound object initialization and lifetime. */
#include "cri_xpt.h"

extern Uint32 D_00756A50[];
extern Uint8 D_00756B78[];
extern Uint8 D_00756BB0[];
extern void func_004bd6a0(const void *message);
extern void func_004bfba0(Uint32 *object);

// FUN_004BE3F8
void func_004be3f8(volatile Uint32 *object)
{
	object[3] = 0;
	object[1] = 0;
	object[0] = (Uint32)D_00756A50;
	object[2] = 0;
}

// FUN_004BE418
Uint32 *func_004be418(Uint32 *object, Uint32 size)
{
	if (object == NULL) {
		func_004bd6a0(D_00756B78);
		return NULL;
	}
	if (size < 208) {
		func_004bd6a0(D_00756BB0);
		return NULL;
	}
	func_004bfba0(object);
	return object;
}

// FUN_004BE480
void func_004be480(Uint32 *object)
{
	if (object != NULL) {
		func_004bfba0(object);
	}
}
