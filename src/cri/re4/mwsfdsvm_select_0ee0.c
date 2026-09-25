/* Sofdec server registration and callback selection. */
#include "cri_xpt.h"

extern Uint32 D_00932C80;
extern Uint32 D_00932C84;

extern void func_004f1220(void);
extern Uint32 func_004f0a60(Uint32 type, Uint32 callback, Uint32 obj, Uint32 name);
extern Uint32 func_004f0b88(Uint32 type, Uint32 fid);

// FUN_00510EE0
void func_00510ee0(void)
{
	func_004f1220();
}

// FUN_00510EF8
Uint32 func_00510ef8(Uint32 callback, Uint32 obj, Uint32 name)
{
	Uint32 fid = func_004f0a60(0, callback, obj, name);
	D_00932C80 = fid;
	return fid;
}

// FUN_00510F30
Uint32 func_00510f30(void)
{
	return func_004f0b88(0, D_00932C80);
}

// FUN_00510F50
Uint32 func_00510f50(Uint32 callback, Uint32 obj, Uint32 name)
{
	Uint32 fid = func_004f0a60(2, callback, obj, name);
	D_00932C84 = fid;
	return fid;
}

