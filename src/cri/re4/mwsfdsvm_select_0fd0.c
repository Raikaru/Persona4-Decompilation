/* Sofdec server registration and callback selection. */
#include "cri_xpt.h"

extern Uint32 D_00932C84;
extern Uint32 D_00932C88;
extern Uint32 D_00932C8C;

extern Uint32 func_004f0a60(Uint32 type, Uint32 callback, Uint32 obj, Uint32 name);
extern Uint32 func_004f0b88(Uint32 type, Uint32 fid);
extern Uint32 func_004f1320(Uint32 (*callback)(Uint32, Uint32, Uint32, Uint32), Uint32 obj);
extern Uint32 func_004f1338(Uint32 (*callback)(Uint32, Uint32, Uint32, Uint32), Uint32 obj);
extern Uint32 func_005110f8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3);
extern Uint32 func_00511110(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3);

// FUN_00510FD0
Uint32 func_00510fd0(void)
{
	return func_004f0b88(2, D_00932C84);
}

// FUN_00510FF0
Uint32 func_00510ff0(Uint32 callback, Uint32 obj, Uint32 name)
{
	Uint32 fid = func_004f0a60(6, callback, obj, name);
	D_00932C88 = fid;
	return fid;
}

// FUN_00511028
Uint32 func_00511028(void)
{
	return func_004f0b88(6, D_00932C88);
}

// FUN_00511048
Uint32 func_00511048(Uint32 callback, Uint32 obj, Uint32 name)
{
	Uint32 fid = func_004f0a60(5, callback, obj, name);
	D_00932C8C = fid;
	return fid;
}

// FUN_00511080
Uint32 func_00511080(void)
{
	return func_004f0b88(5, D_00932C8C);
}

// FUN_005110A0
Uint32 func_005110a0(void)
{
	func_004f1320(func_005110f8, 0);
	return func_004f1338(func_00511110, 0);
}

// FUN_005110D0
Uint32 func_005110d0(void)
{
	func_004f1320(0, 0);
	return func_004f1338(0, 0);
}
