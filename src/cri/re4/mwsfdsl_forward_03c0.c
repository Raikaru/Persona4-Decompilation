/* Sofdec stream-list delegates; the active stream is at offset 0x48. */
#include "cri_xpt.h"

extern Uint32 func_004e9420();
extern Uint32 func_004e9480();
extern Uint32 func_004e9510();
extern Uint32 func_004e95a8();
extern Uint32 func_004e9640();

// FUN_005103C0
Uint32 func_005103c0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e9420(*(Uint32 *)((Uint8 *)a0 + 0x48), a1, a2, a3);
}

// FUN_005103D8
Uint32 func_005103d8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e9480(*(Uint32 *)((Uint8 *)a0 + 0x48), a1, a2, a3);
}

// FUN_005103F0
Uint32 func_005103f0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e9510(*(Uint32 *)((Uint8 *)a0 + 0x48), a1, a2, a3);
}

// FUN_00510408
Uint32 func_00510408(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e95a8(*(Uint32 *)((Uint8 *)a0 + 0x48), a1, a2, a3);
}

// FUN_00510420
Uint32 func_00510420(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e9640(*(Uint32 *)((Uint8 *)a0 + 0x48), a1, a2, a3);
}
