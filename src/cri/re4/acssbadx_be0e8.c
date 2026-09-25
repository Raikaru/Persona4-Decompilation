/* ACSSBADX handle construction and decoder attachment. */
#include "cri_xpt.h"

extern Uint32 D_00756A90[];
extern Uint32 D_00756AC8[];
extern Uint32 D_00756B00[];
extern void func_004bd6a0(const void *message);
extern void func_004be3f8(Uint32 *object);
extern Uint32 func_004de4c0(Uint32 source, Uint32 offset, Uint32 size, Uint32 limit);
extern Uint32 func_004de540(Uint32 source, Uint32 size, Uint32 limit);
extern void func_004de860(Uint32 handle);
extern Uint32 func_004deb38(Uint32 handle, Uint32 offset, Uint32 size);

// FUN_004BE0E8
Uint32 *func_004be0e8(Uint32 *object, Uint32 size)
{
	if (object == NULL) {
		func_004bd6a0(D_00756A90);
		return NULL;
	}
	if (size < 16) {
		func_004bd6a0(D_00756AC8);
		return NULL;
	}
	func_004be3f8(object);
	return object;
}

// FUN_004BE150
void func_004be150(Uint32 *object)
{
	if (object != NULL) {
		func_004be3f8(object);
	}
}

// FUN_004BE178
Uint32 func_004be178(Uint32 *object, const Uint32 *source, Uint32 size, Uint32 limit)
{
	if (source[2] != 0) {
		object[1] = func_004de540(source[1], size, limit - 16);
	} else {
		object[1] = func_004de4c0(source[1], source[0], size, limit - 16);
	}
	if (object[1] == 0) {
		func_004bd6a0(D_00756B00);
		return 0;
	}
	object[3] = source[1];
	object[2] = source[0];
	return 1;
}

// FUN_004BE210
void func_004be210(Uint32 *object)
{
	if (object[1] != 0) {
		func_004de860(object[1]);
		object[1] = 0;
	}
}

// FUN_004BE248
Uint32 func_004be248(Uint32 *object, Uint32 offset)
{
	return func_004deb38(object[1], offset, 0);
}
