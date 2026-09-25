/* CRI AHX bitstream reader delegates and shared-context lifecycle. */
#include "cri_xpt.h"
#include <string.h>

extern Uint32 ACSSND_GetActiveAdxt();
extern Uint32 ACSSND_GetNextAdxt();
extern Uint32 ACSSND_GetAdxt();
extern Uint32 ACSSND_GetNumAdxt();
extern Uint32 ACSSND_GetActiveAixp();
extern Uint32 ACSSND_GetNextAixp();
extern Uint32 ACSSND_GetAixp();
extern Uint32 ACSSND_GetNumAixp();
extern Uint32 ACSSND_CancelFading();
extern Uint32 func_004bf930();
extern Uint32 D_00725294;
extern Uint32 func_004c0e00();
extern Uint32 func_004c0fc0();
extern Uint32 func_004c0fd0();
extern Uint32 func_004c1000();
extern Uint32 func_004c1008();
extern Uint32 func_004c1010();
extern Uint32 func_004c1018();
extern Uint32 func_004c1020();
extern Uint32 func_004c1028();
extern Uint32 func_004c0ce0();
extern Uint32 func_004c0d60();
extern Uint32 D_007282A0;
extern Uint8 D_00728330[];

// FUN_004D9008
Uint32 func_004d9008(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetActiveAdxt(a0, a1, a2, a3);
}

// FUN_004D9020
Uint32 func_004d9020(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetNextAdxt(a0, a1, a2, a3);
}

// FUN_004D9038
Uint32 func_004d9038(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetAdxt(a0, a1, a2, a3);
}

// FUN_004D9050
Uint32 func_004d9050(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetNumAdxt(a0, a1, a2, a3);
}

// FUN_004D9068
Uint32 func_004d9068(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetActiveAixp(a0, a1, a2, a3);
}

// FUN_004D9080
Uint32 func_004d9080(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetNextAixp(a0, a1, a2, a3);
}

// FUN_004D9098
Uint32 func_004d9098(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetAixp(a0, a1, a2, a3);
}

// FUN_004D90B0
Uint32 func_004d90b0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetNumAixp(a0, a1, a2, a3);
}

// FUN_004D90C8
Uint32 func_004d90c8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_CancelFading(a0, a1, a2, a3);
}

// FUN_004D90E0
Uint32 func_004d90e0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf930(a0, a1, a2, a3);
}

// FUN_004D90F8
Uint32 func_004d90f8(void)
{
	return func_004c0fc0(func_004c0e00(D_00725294));
}

// FUN_004D9120
Uint32 func_004d9120(void)
{
	return func_004c0fd0(func_004c0e00(D_00725294));
}

// FUN_004D9148
Uint32 func_004d9148(Uint32 value)
{
	return func_004c1000(func_004c0e00(D_00725294), value);
}

// FUN_004D9180
Uint32 func_004d9180(Uint32 value)
{
	return func_004c1008(func_004c0e00(D_00725294), value);
}

// FUN_004D91B8
Uint32 func_004d91b8(Uint32 value)
{
	return func_004c1010(func_004c0e00(D_00725294), value);
}

// FUN_004D91F0
Uint32 func_004d91f0(void)
{
	return func_004c1018(func_004c0e00(D_00725294));
}

// FUN_004D9218
Uint32 func_004d9218(void)
{
	return func_004c1020(func_004c0e00(D_00725294));
}

// FUN_004D9240
Uint32 func_004d9240(void)
{
	return func_004c1028(func_004c0e00(D_00725294));
}

// FUN_004D9268
Uint32 func_004d9268(void)
{
	return func_004c0ce0(D_00725294);
}

// FUN_004D9288
Uint32 func_004d9288(Uint32 value)
{
	return func_004c0d60(D_00725294, value);
}

// FUN_004D92A8
void func_004d92a8(void)
{
	if (D_007282A0 == 0) {
		memset(D_00728330, 0, 0x2c0);
	}
	++D_007282A0;
}

// FUN_004D92F8
void func_004d92f8(void)
{
	--D_007282A0;
	if (D_007282A0 == 0) {
		memset(D_00728330, 0, 0x2c0);
	}
}
