/* Forward the signed sample-count adjustment to the attached ADX decoder. */
#include "adx_t.h"

extern Sint32 func_004cecc8(void *sjd, Sint32 nsmpl);

// FUN_004D65A0
Sint32 func_004d65a0(ADXT adxt, Sint32 nsmpl)
{
	return func_004cecc8(adxt->sjd, nsmpl);
}
