/* CRI UTY timer callback dispatch. */
#include "cri_xpt.h"

extern Uint32 D_00743C78;
extern Uint32 D_00743C7C;
extern Uint32 D_00743C80;
extern Uint32 D_00743C84;
extern Uint32 D_00743C88;
extern Uint32 D_00743C8C;
extern Uint32 D_00743C90;
extern Uint32 D_00743C94;
extern Uint32 D_00743C98;
extern Uint32 D_00743C9C;
extern Uint32 D_00743CA0;
extern Uint32 D_00743CA4;

// FUN_004FB190
Uint32 func_004fb190(void)
{
	return D_00743C78;
}

// FUN_004FB1A0
Uint32 func_004fb1a0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(Uint32 (*)(Uint32, Uint32, Uint32, Uint32))D_00743C7C;
	if (cb)
		return cb(a0, a1, a2, a3);
	return 0;
}

// FUN_004FB1D0
Uint32 func_004fb1d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(Uint32 (*)(Uint32, Uint32, Uint32, Uint32))D_00743C80;
	if (cb)
		return cb(a0, a1, a2, a3);
	return 0;
}

// FUN_004FB200
void func_004fb200(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C84;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB228
void func_004fb228(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C88;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB250
Uint32 func_004fb250(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(Uint32 (*)(Uint32, Uint32, Uint32, Uint32))D_00743C8C;
	if (cb)
		return cb(a0, a1, a2, a3);
	return 0;
}

// FUN_004FB280
void func_004fb280(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C90;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB2A8
void func_004fb2a8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C98;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB2D0
void func_004fb2d0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C94;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB2F8
void func_004fb2f8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743C9C;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB320
void func_004fb320(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743CA0;
	if (cb)
		cb(a0, a1, a2, a3);
}

// FUN_004FB348
void func_004fb348(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	void (*cb)(Uint32, Uint32, Uint32, Uint32) =
		(void (*)(Uint32, Uint32, Uint32, Uint32))D_00743CA4;
	if (cb)
		cb(a0, a1, a2, a3);
}
