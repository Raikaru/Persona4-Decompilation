/* CRI Sofdec MW stream-server state accessors and setup. */
#include "cri_xpt.h"

extern Uint32 D_00743C68;
extern Uint32 D_00743C6C;
extern Uint32 D_00743C70;

Uint32 func_004f9b50(void);
void func_004f9b60(Uint32 value);

// FUN_004F9AE0
void func_004f9ae0(void)
{
}

// FUN_004F9AE8
void func_004f9ae8(Uint32 value)
{
	D_00743C68 = value;
}

// FUN_004F9AF8
Uint32 func_004f9af8(void)
{
	return D_00743C68;
}

// FUN_004F9B08
void func_004f9b08(Uint32 value)
{
	D_00743C6C = value;
}

// FUN_004F9B18
Uint32 func_004f9b18(void)
{
	return D_00743C6C;
}

// FUN_004F9B28
void func_004f9b28(void)
{
	*(Uint32 *)func_004f9b50() = 0;
	func_004f9b60(0x80);
}

// FUN_004F9B50
Uint32 func_004f9b50(void)
{
	return (Uint32)&D_00743C70;
}

// FUN_004F9B60
void func_004f9b60(Uint32 value)
{
	*(Uint32 *)func_004f9b50() = value;
}

// FUN_004F9B88
Uint32 func_004f9b88(void)
{
	return *(Uint32 *)func_004f9b50();
}
