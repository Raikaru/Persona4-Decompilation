/* Sofdec effects delegates through the active sub-effect at offset 0xa8. */
#include "cri_xpt.h"

extern Uint32 func_0052bbd8();
extern Uint32 func_0052bbf0();

// FUN_0050F538
Uint32 func_0050f538(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bbd8(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F550
Uint32 func_0050f550(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_0052bbf0(*(Uint32 *)((Uint8 *)a0 + 0xa8), a1, a2, a3);
}

// FUN_0050F568
void func_0050f568(Uint32 object, Uint32 *first, Uint32 *second)
{
	Uint32 *fields = (Uint32 *)((Uint8 *)object + 0x194);
	Uint32 first_value = fields[1];
	Uint32 second_value = fields[2];
	*second = second_value;
	*first = first_value;
}
