/* Tell the ADX decoder that no further input will arrive. */
#include "adx_t.h"
extern void func_004cdd30(void *sjd);

// FUN_004D6340
void ADXT_TermSupply(ADXT adxt)
{
	func_004cdd30(adxt->sjd);
}
