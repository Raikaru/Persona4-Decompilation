/* Retail ADXT locked time-offset setter at 0x004D6510. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004d6550(ADXT adxt, Sint32 ofst);

// FUN_004D6510
void func_004d6510(ADXT adxt, Sint32 ofst)
{
	func_004c54d8();
	func_004d6550(adxt, ofst);
	func_004c54e0();
}
