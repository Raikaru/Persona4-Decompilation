/* Sofdec effects delegates; the active effects state is at offset 0xa8. */
#include "cri_xpt.h"

extern Uint32 func_0052bcb0();
extern Uint32 func_0052bcb8();
extern Uint32 func_0052bcc0();
extern Uint32 func_0052bcc8();
extern Uint32 func_0052b9e0();
extern Uint32 func_0052b9f0();

// FUN_0050F8E8
Uint32 func_0050f8e8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bcb0(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F900
Uint32 func_0050f900(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bcb8(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F918
Uint32 func_0050f918(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bcc0(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F930
Uint32 func_0050f930(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bcc8(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F948
Uint32 func_0050f948(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052b9e0(a0, a1, a2, a3);
}

// FUN_0050F960
Uint32 func_0050f960(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052b9f0(a0, a1, a2, a3);
}
