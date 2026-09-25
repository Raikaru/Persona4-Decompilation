/* Retail ADXT decoder data-length getter at 0x004D6780. */
#include "adx_t.h"
extern char D_00759288[];

extern void func_004c6a98(const char *msg);
extern Sint32 func_004cebf0(void *sjd);

// FUN_004D6780
Sint32 adxt_GetDecDtLen(ADXT adxt)
{
	if (adxt == 0) {
		func_004c6a98(D_00759288);
		return -1;
	}
	return func_004cebf0(adxt->sjd);
}
