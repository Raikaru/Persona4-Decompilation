/* ADXT locked decoder supply-termination wrapper at 0x004D6310. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
void ADXT_TermSupply(ADXT adxt);

// FUN_004D6310
void func_004d6310(ADXT adxt)
{
	func_004c54d8();
	ADXT_TermSupply(adxt);
	func_004c54e0();
}

