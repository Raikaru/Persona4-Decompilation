/* Sofdec bitstream delegates; the active substream is at offset 0x3c. */
#include "cri_xpt.h"

extern Uint32 func_00513f00();
extern Uint32 func_00513f80();
extern Uint32 func_00513df8();
extern Uint32 func_00513e88();
extern Uint32 func_0050cae0();

// FUN_0050C8B0
Uint32 func_0050c8b0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00513f00(*(Uint32 *)((Uint8 *)a0 + 0x3c), a1, a2, a3);
}

// FUN_0050C8C8
Uint32 func_0050c8c8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00513f80(*(Uint32 *)((Uint8 *)a0 + 0x3c), a1, a2, a3);
}

// FUN_0050C8E0
Uint32 func_0050c8e0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00513df8(*(Uint32 *)((Uint8 *)a0 + 0x3c), a1, a2, a3);
}

// FUN_0050C8F8
Uint32 func_0050c8f8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_00513e88(*(Uint32 *)((Uint8 *)a0 + 0x3c), a1, a2, a3);
}

// FUN_0050C910
Uint32 func_0050c910(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0050cae0(a0, a1, a2, a3);
}

// FUN_0050C928
Uint32 func_0050c928(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0050cae0(a0, a1, a2, a3);
}
