/* CRI UTY_MulDiv (muldiv.c): a * b / c in 64-bit intermediate, the time unit conversion of the
 * Sofdec clock (saturates on c == 0). */
#include "cri_xpt.h"

// (a * b) / c without intermediate overflow; +-INT_MAX by the sign of a*b when c is 0.
Sint32 UTY_MulDiv(Sint32 a, Sint32 b, Sint32 c)
{
	if (c == 0) {
		if ((a ^ b) >= 0) {
			return 0x7FFFFFFF;
		}
		return (Sint32)0x80000000;
	}
	return (Sint32)(((Sint64)a * (Sint64)b) / c);
}
