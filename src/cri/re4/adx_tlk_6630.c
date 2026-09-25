/* Retail ADXT locked link-switch getter at 0x004D6630. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern Sint8 func_004d6668(ADXT adxt);

// FUN_004D6630
Sint32 func_004d6630(ADXT adxt)
{
	Sint32 sw;

	func_004c54d8();
	sw = func_004d6668(adxt);
	func_004c54e0();
	return sw;
}
