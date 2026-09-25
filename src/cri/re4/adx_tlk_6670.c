/* Retail ADXT callback forwarding at 0x004D6670–0x004D66D4. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004ced28(void *sjd, void (*func)(), void *obj);

void func_004d66c0(ADXT adxt, void (*func)(), void *obj);

// FUN_004D6670
void func_004d6670(ADXT adxt, void (*func)(), void *obj)
{
	func_004c54d8();
	func_004d66c0(adxt, func, obj);
	func_004c54e0();
}

// FUN_004D66C0
void func_004d66c0(ADXT adxt, void (*func)(), void *obj)
{
	func_004ced28(adxt->sjd, func, obj);
}
