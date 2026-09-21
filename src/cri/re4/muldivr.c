/* CRI UTY_MulDivRound64 (muldivr.c): 64-bit a * b / c rounded to nearest, sign handled separately. */
#include "cri_xpt.h"

// Rounded (a * b) / c in 64 bits; saturates when c is 0.
// FUN_005078A0
Sint64 UTY_MulDivRound64(Sint64 a, Sint64 b, Sint64 c)
{
	Sint32 sign;
	Sint64 r;

	if (c == 0) {
		if ((a ^ b) >= 0) {
			return 0x7FFFFFFFFFFFFFFFLL;
		}
		return (Sint64)0x8000000000000000ULL;
	}
	sign = 1;
	if (a < 0) {
		a = -a;
		sign = -1;
	}
	if (b < 0) {
		b = -b;
		sign = -sign;
	}
	if (c < 0) {
		c = -c;
		sign = -sign;
	}
	r = (a * b + c / 2) / c;
	if (sign < 0) {
		r = -r;
	}
	return r;
}
