#include "cri_xpt.h"

extern void (*D_00743CA8)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CAC)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CB0)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CB4)(Uint32, Uint32, Uint32, Uint32);
extern Uint32 (*D_00743CB8)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CBC)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CC0)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CC4)(Uint32, Uint32, Uint32, Uint32);
extern void (*D_00743CC8)(Uint32, Uint32, Uint32, Uint32);
extern Uint32 D_00743CD0;
extern Uint32 func_004fb500();

// FUN_004FB370
void func_004fb370(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CA8;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB398
void func_004fb398(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CAC;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB3C0
void func_004fb3c0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CB0;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB3E8
void func_004fb3e8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CB4;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB410
Uint32 func_004fb410(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CB8;
	if (callback != 0)
		return callback(a0, a1, a2, a3);
	return 0;
}

// FUN_004FB440
void func_004fb440(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CBC;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB468
void func_004fb468(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CC0;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB490
void func_004fb490(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CC4;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB4B8
void func_004fb4b8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*callback)(Uint32, Uint32, Uint32, Uint32) = D_00743CC8;
	if (callback != 0)
		callback(a0, a1, a2, a3);
}

// FUN_004FB4E0
Uint32 func_004fb4e0(void)
{
	return func_004fb500((Uint32)&D_00743CD0);
}
