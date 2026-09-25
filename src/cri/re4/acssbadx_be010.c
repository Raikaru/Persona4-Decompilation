/* ACSS BADX controls forward through the decoder handle at offset 4. */
#include "cri_xpt.h"

extern Uint32 func_004d5110();
extern Uint32 func_004d51c0();
extern Uint32 func_004d5dc8();

// FUN_004BE010
Uint32 func_004be010(Uint32 object, Sint32 value)
{
	if (value < -960) {
		value = -960;
	}
	return func_004d5110(*(Uint32 *)((Uint8 *)object + 4), value);
}

// FUN_004BE038
Uint32 func_004be038(Uint32 object)
{
	return func_004d51c0(*(Uint32 *)((Uint8 *)object + 4));
}

// FUN_004BE050
void func_004be050(Uint32 object, Uint32 flag, Sint32 value)
{
	if (flag == 0) {
		func_004d5110(*(Uint32 *)((Uint8 *)object + 4), value);
	}
}

// FUN_004BE080
Uint32 func_004be080(Uint32 object, Uint32 flag)
{
	if (flag == 0) {
		return func_004d51c0(*(Uint32 *)((Uint8 *)object + 4));
	}
	return 0;
}

// FUN_004BE0B0
Uint32 func_004be0b0(Uint32 object, Uint32 value)
{
	return func_004d5dc8(*(Uint32 *)((Uint8 *)object + 4), value);
}
