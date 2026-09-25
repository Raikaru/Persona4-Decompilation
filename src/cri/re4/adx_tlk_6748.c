/* Retail locked decoder data-length getter at 0x004D6748. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Sint32 adxt_GetDecDtLen(ADXT adxt);

// FUN_004D6748
Sint32 func_004d6748(ADXT adxt)
{
	Sint32 n;

	func_004c54d8();
	n = adxt_GetDecDtLen(adxt);
	func_004c54e0();
	return n;
}
