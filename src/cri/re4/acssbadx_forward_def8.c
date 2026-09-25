/* ACSS BADX delegates forward through the object handle at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004d6f78();
extern Uint32 func_004d6d18();
extern Uint32 func_004d7030();
extern Uint32 func_004d7160();
extern Uint32 func_004d4308();
extern Uint32 func_004d6050();
extern Uint32 func_004d61c0();

// FUN_004BDEF8
Uint32 func_004bdef8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d6f78(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF10
Uint32 func_004bdf10(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d6d18(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF28
Uint32 func_004bdf28(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d7030(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF40
Uint32 func_004bdf40(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d7160(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF58
Uint32 func_004bdf58(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d4308(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF70
Uint32 func_004bdf70(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d6050(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// FUN_004BDF88
Uint32 func_004bdf88(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004d61c0(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}
