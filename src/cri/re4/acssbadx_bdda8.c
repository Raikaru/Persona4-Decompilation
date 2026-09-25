/* ACSSBADX object and decoder-handle lifetime. */
#include "cri_xpt.h"

extern Uint8 D_00756980[];
extern Uint8 D_007569B8[];
extern Uint8 D_007569F0[];
extern void func_004bd6a0(const void *message);
extern void func_004be0d0(Uint32 *object);
extern Uint32 func_004d3850(Uint32 source, Uint32 size, Uint32 limit);
extern Uint32 func_004d3bc0(Uint32 size, Uint32 limit);
extern void func_004d3cd8(Uint32 handle);

// FUN_004BDDA8
Uint32 *func_004bdda8(Uint32 *object, Uint32 size)
{
	if (object == NULL) {
		func_004bd6a0(D_00756980);
		return NULL;
	}
	if (size < 12) {
		func_004bd6a0(D_007569B8);
		return NULL;
	}
	func_004be0d0(object);
	return object;
}

// FUN_004BDE10
void func_004bde10(Uint32 *object)
{
	if (object != NULL) {
		func_004be0d0(object);
	}
}

// FUN_004BDE38
Uint32 func_004bde38(Uint32 *object, const Uint32 *source, Uint32 size, Uint32 limit)
{
	if (source[2] != 0) {
		object[1] = func_004d3bc0(size, limit - 12);
	} else {
		object[1] = func_004d3850(source[0], size, limit - 12);
	}
	if (object[1] == 0) {
		func_004bd6a0(D_007569F0);
		return 0;
	}
	object[2] = source[0];
	return 1;
}

// FUN_004BDEC0
void func_004bdec0(Uint32 *object)
{
	if (object[1] != 0) {
		func_004d3cd8(object[1]);
		object[1] = 0;
	}
}
