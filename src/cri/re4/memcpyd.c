/* CRI UTY_MemcpyDword (memcpyd.c): word copy, 16-way unrolled, used for the MPV table setup. */
#include "cri_xpt.h"

// Copies `ndw` 32-bit words.
void UTY_MemcpyDword(Uint32 *dst, Uint32 *src, Uint32 ndw)
{
	Uint32 a, b, c, d;
	Uint32 cnt1, cnt2;

	cnt1 = (ndw & 15) + 1;
	while (--cnt1) {
		*dst++ = *src++;
	}
	cnt2 = (ndw >> 4) + 1;
	while (--cnt2) {
		a = src[0];
		b = src[1];
		c = src[2];
		d = src[3];
		dst[0] = a;
		dst[1] = b;
		dst[2] = c;
		dst[3] = d;
		a = src[4];
		b = src[5];
		c = src[6];
		d = src[7];
		dst[4] = a;
		dst[5] = b;
		dst[6] = c;
		dst[7] = d;
		a = src[8];
		b = src[9];
		c = src[10];
		d = src[11];
		dst[8] = a;
		dst[9] = b;
		dst[10] = c;
		dst[11] = d;
		a = src[12];
		b = src[13];
		c = src[14];
		d = src[15];
		src += 16;
		dst[12] = a;
		dst[13] = b;
		dst[14] = c;
		dst[15] = d;
		dst += 16;
	}
}
