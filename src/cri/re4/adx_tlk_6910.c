/* Retail ADXT locked silence-insertion wrapper. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);

Sint32 func_004d6968(ADXT adxt, Sint32 nch, Sint32 nsmpl);

// FUN_004D6910
Sint32 func_004d6910(ADXT adxt, Sint32 nch, Sint32 nsmpl)
{
	Sint32 inserted;

	func_004c54d8();
	inserted = func_004d6968(adxt, nch, nsmpl);
	func_004c54e0();
	return inserted;
}

