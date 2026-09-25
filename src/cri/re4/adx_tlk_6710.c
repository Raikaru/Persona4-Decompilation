/* Report the attached decoder's sample count; null handles report a CRI error. */
#include "adx_t.h"

extern char D_00759258[];
extern void func_004c6a98(const char *message);
extern Sint32 func_004cebf8(void *sjd);

// FUN_004D6710
Sint32 adxt_GetDecNumSmpl(ADXT adxt)
{
	if (adxt == NULL) {
		func_004c6a98(D_00759258);
		return -1;
	}
	return func_004cebf8(adxt->sjd);
}
