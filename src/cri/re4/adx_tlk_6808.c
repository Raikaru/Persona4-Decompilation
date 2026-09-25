/* Register the ADX decoder callback and its object through the attached joint. */
#include "adx_t.h"

extern char D_007592B8[];
extern void func_004c6a98(const char *message);
extern void func_004cec00(void *sjd, void (*callback)(), void *object);

// FUN_004D6808
void ADXT_SetCbDec(ADXT adxt, void (*callback)(), void *object)
{
	if (adxt == NULL) {
		func_004c6a98(D_007592B8);
		return;
	}
	func_004cec00(adxt->sjd, callback, object);
}
