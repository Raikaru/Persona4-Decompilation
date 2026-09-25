/* Retail ADXT locked decoder sample-adjustment call at 0x004D6558. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Sint32 func_004d65a0(ADXT adxt, Sint32 nsmpl);

// FUN_004D6558
Sint32 func_004d6558(ADXT adxt, Sint32 nsmpl)
{
	Sint32 n;

	func_004c54d8();
	n = func_004d65a0(adxt, nsmpl);
	func_004c54e0();
	return n;
}
