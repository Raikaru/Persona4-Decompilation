/* CRI UTY_CmpTime (cmptime.c): the count/scale time comparison used by every Sofdec timing decision. */
#include "cri_xpt.h"

// TRUE when time cnt1/tscl1 <= cnt2/tscl2 (cross-multiplied in 64 bits); the compile-time sizeof
// check is CRI's idiom.
Bool UTY_CmpTime(Sint32 cnt1, Sint32 tscl1, Sint32 cnt2, Sint32 tscl2)
{
	Bool ret;
	Sint32 sz = sizeof(Sint64);

	if (sz < 8) {
		for (;;) {
		}
	}
	if ((Sint64)cnt1 * tscl2 <= (Sint64)cnt2 * tscl1) {
		ret = TRUE;
	} else {
		ret = FALSE;
	}
	return ret;
}
