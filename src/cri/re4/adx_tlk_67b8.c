/* Retail locked ADXT decoder callback setter at 0x004D67B8. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void ADXT_SetCbDec(ADXT adxt, void (*func)(), void *obj);

// FUN_004D67B8
void func_004d67b8(ADXT adxt, void (*func)(), void *obj)
{
	func_004c54d8();
	ADXT_SetCbDec(adxt, func, obj);
	func_004c54e0();
}
