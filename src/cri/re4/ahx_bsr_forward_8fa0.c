/* CRI AHX bitstream reader direct-call stubs; each passes the four incoming ABI words unchanged to its retail relocation target. */
#include "cri_xpt.h"

extern Uint32 func_004bf238();
extern Uint32 func_004bf240();
extern Uint32 func_004bf350();
extern Uint32 func_004bfb28();

// FUN_004D8FA0
Uint32 func_004d8fa0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf238(a0, a1, a2, a3);
}

// FUN_004D8FB8
Uint32 func_004d8fb8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf240(a0, a1, a2, a3);
}

// FUN_004D8FD0
Uint32 func_004d8fd0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf350(a0, a1, a2, a3);
}

// FUN_004D8FE8
Uint32 func_004d8fe8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bfb28(a0, (Sint8)a1, a2, a3);
}
