/* Retail locked decoder sample-count getter at 0x004D66D8. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Sint32 adxt_GetDecNumSmpl(ADXT adxt);

// FUN_004D66D8
Sint32 func_004d66d8(ADXT adxt)
{
	Sint32 n;

	func_004c54d8();
	n = adxt_GetDecNumSmpl(adxt);
	func_004c54e0();
	return n;
}
