/* CRI UTY_MemsetDword (memsetd.c): word fill, 16-way unrolled, used for the Sofdec handle clears. */
#include "cri_xpt.h"

// Fills `ndw` 32-bit words at dst with val (filling from the end).
void UTY_MemsetDword(Uint32 *dst, Uint32 val, Uint32 ndw)
{
	Uint32 *p;
	Uint32 cnt;

	p = dst + ndw;
	cnt = (ndw & 15) + 1;
	while (--cnt) {
		*--p = val;
	}
	cnt = (ndw >> 4) + 1;
	while (--cnt) {
		p[-1] = val;
		p[-2] = val;
		p[-3] = val;
		p[-4] = val;
		p[-5] = val;
		p[-6] = val;
		p[-7] = val;
		p[-8] = val;
		p[-9] = val;
		p[-10] = val;
		p[-11] = val;
		p[-12] = val;
		p[-13] = val;
		p[-14] = val;
		p[-15] = val;
		p -= 16;
		*p = val;
	}
}
