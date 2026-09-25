/* CRI object delegates through the first word of the stream handle. */
#include "cri_xpt.h"

extern Uint32 func_004da530();
extern Uint32 func_004da550();
extern Uint32 func_004da570();
extern Uint32 func_004da5b8();
extern Uint32 func_004da4c8();
extern Uint32 func_004da518();

// FUN_004DE218
Uint32 func_004de218(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da530(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE230
Uint32 func_004de230(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da550(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE248
Uint32 func_004de248(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da570(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE260
Uint32 func_004de260(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da5b8(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE278
Uint32 func_004de278(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da4c8(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE290
Uint32 func_004de290(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da518(*(Uint32 *)a0, a1, a2, a3);
}
