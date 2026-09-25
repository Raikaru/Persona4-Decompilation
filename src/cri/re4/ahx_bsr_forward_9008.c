/* CRI AHX bitstream reader delegates and shared-context lifecycle. */
#include "cri_xpt.h"
#include <string.h>

extern Uint32 func_004bf438();
extern Uint32 func_004bf498();
extern Uint32 func_004bf510();
extern Uint32 func_004bf590();
extern Uint32 func_004bf5e0();
extern Uint32 func_004bf638();
extern Uint32 func_004bf6a8();
extern Uint32 func_004bf718();
extern Uint32 func_004bf758();
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
	return func_004bf438(a0, a1, a2, a3);
}

// FUN_004D9020
Uint32 func_004d9020(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf498(a0, a1, a2, a3);
}

// FUN_004D9038
Uint32 func_004d9038(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf510(a0, a1, a2, a3);
}

// FUN_004D9050
Uint32 func_004d9050(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf590(a0, a1, a2, a3);
}

// FUN_004D9068
Uint32 func_004d9068(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf5e0(a0, a1, a2, a3);
}

// FUN_004D9080
Uint32 func_004d9080(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf638(a0, a1, a2, a3);
}

// FUN_004D9098
Uint32 func_004d9098(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf6a8(a0, a1, a2, a3);
}

// FUN_004D90B0
Uint32 func_004d90b0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf718(a0, a1, a2, a3);
}

// FUN_004D90C8
Uint32 func_004d90c8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf758(a0, a1, a2, a3);
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
