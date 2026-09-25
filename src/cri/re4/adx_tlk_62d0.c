/* Retail ADXT stream handle query at 0x004D62D0. */
#include "cri_xpt.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Uint32 func_004d6308(Uint32 adxt);

// FUN_004D62D0
Uint32 func_004d62d0(Uint32 adxt)
{
	Uint32 stm;

	func_004c54d8();
	stm = func_004d6308(adxt);
	func_004c54e0();
	return stm;
}
