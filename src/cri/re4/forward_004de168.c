/* CRI object delegates through the first word of the stream handle. */
#include "cri_xpt.h"

extern Uint32 func_004da430();
extern Uint32 func_004da448();
extern Uint32 func_004da460();
extern Uint32 func_004da468();
extern Uint32 func_004da480();

// FUN_004DE168
Uint32 func_004de168(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da430(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE180
Uint32 func_004de180(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da448(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE198
Uint32 func_004de198(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da460(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE1B0
Uint32 func_004de1b0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da468(*(Uint32 *)a0, a1, a2, a3);
}

// FUN_004DE1C8
Uint32 func_004de1c8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004da480(*(Uint32 *)a0, a1, a2, a3);
}
