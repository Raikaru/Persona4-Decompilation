/* ADX talk-controller close-all and adjacent library delegates. */
#include "cri_xpt.h"

extern void func_004e7258(void);
extern Uint32 func_004e6460();
extern Uint32 func_004e6480();
extern Uint32 func_004e7378();

// FUN_004D3528
void ADXT_CloseAllHandles(void)
{
	func_004e7258();
}

// FUN_004D3540
Uint32 func_004d3540(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e6460(a0, a1, a2, a3);
}

// FUN_004D3558
Uint32 func_004d3558(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e6480(a0, a1, a2, a3);
}

// FUN_004D3570
Uint32 func_004d3570(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004e7378(a0, a1, a2, a3);
}
