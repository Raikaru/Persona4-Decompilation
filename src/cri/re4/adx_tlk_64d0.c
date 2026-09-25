/* Retail ADXT locked time-offset getter at 0x004D64D0. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Sint32 func_004d6508(ADXT adxt);

// FUN_004D64D0
Sint32 func_004d64d0(ADXT adxt)
{
	Sint32 ofst;

	func_004c54d8();
	ofst = func_004d6508(adxt);
	func_004c54e0();
	return ofst;
}
