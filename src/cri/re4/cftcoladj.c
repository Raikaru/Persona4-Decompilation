/* Sofdec colour adjustment tables (cftcoladj.c): 3x3 colour matrix product / inverse and the
 * custom inverse conversion tables (luma and the two chroma ramps). */
#include "cri_xpt.h"

// 3x3 matrix product out = a * b (row major), for chaining colour matrices.
void CFT_MakeMtx3D(Float32 *a, Float32 *b, Float32 *out)
{
	out[0] = a[0] * b[0] + a[1] * b[3] + a[2] * b[6];
	out[1] = a[0] * b[1] + a[1] * b[4] + a[2] * b[7];
	out[2] = a[0] * b[2] + a[1] * b[5] + a[2] * b[8];
	out[3] = a[3] * b[0] + a[4] * b[3] + a[5] * b[6];
	out[4] = a[3] * b[1] + a[4] * b[4] + a[5] * b[7];
	out[5] = a[3] * b[2] + a[4] * b[5] + a[5] * b[8];
	out[6] = a[6] * b[0] + a[7] * b[3] + a[8] * b[6];
	out[7] = a[6] * b[1] + a[7] * b[4] + a[8] * b[7];
	out[8] = a[6] * b[2] + a[7] * b[5] + a[8] * b[8];
}

// 3x3 matrix inverse by cofactors.
void CFT_MakeInverseMtx3D(Float32 *m, Float32 *inv)
{
	Float32 det;
	Float32 s;
	Float32 a;
	Float32 b;
	Float32 c;
	Float32 d;
	Float32 e;
	Float32 f;
	Float32 g;
	Float32 h;
	Float32 i;

	a = m[0];
	b = m[1];
	c = m[2];
	d = m[3];
	e = m[4];
	f = m[5];
	g = m[6];
	h = m[7];
	i = m[8];
	s = 1.0f;
	det = (a * e * i + b * f * g + c * d * h) - (a * f * h + b * d * i + c * e * g);
	inv[0] = s * ((e * i - f * h) / det);
	inv[1] = s * (-(b * i - c * h) / det);
	inv[2] = s * ((b * f - c * e) / det);
	inv[3] = s * (-(d * i - f * g) / det);
	inv[4] = s * ((a * i - c * g) / det);
	inv[5] = s * (-(a * f - c * d) / det);
	inv[6] = s * ((d * h - e * g) / det);
	inv[7] = s * (-(a * h - b * g) / det);
	inv[8] = s * ((a * e - b * d) / det);
}

/* luma table: 0..15 spread (2 of 3), 16..175 halved, 176..191 linear, then doubled and clipped;
 * chroma tables: 3-wide steps for 24 values either side of 128 and linear ramps to the ends */
void CFT_MakeInvConvTableCustom(Uint8 *ytbl, Uint8 *cbtbl, Uint8 *crtbl)
{
	Sint32 i;
	Sint32 j;
	Sint32 v;
	Sint32 t;

	j = 0;
	v = 0;
	while (j < 0x10) {
		ytbl[j++] = v++;
		ytbl[j++] = v;
		v += 2;
	}
	while (j < 0xB0) {
		ytbl[j] = v;
		ytbl[j + 1] = v;
		j += 2;
		v++;
	}
	while (j < 0xC0) {
		ytbl[j] = v;
		v++;
		j++;
	}
	while (j < 0x100) {
		t = 0xFF;
		if (v < 0xFF) {
			t = v;
		}
		ytbl[j] = t;
		v += 2;
		j++;
	}

	j = 0x80;
	v = j;
	while (j > 0x68) {
		cbtbl[j] = v;
		crtbl[j] = v;
		cbtbl[j - 1] = v;
		crtbl[j - 1] = v;
		cbtbl[j - 2] = v;
		crtbl[j - 2] = v;
		j -= 3;
		v--;
	}
	for (i = j; i >= 0; i--) {
		cbtbl[i] = i * v / j;
		crtbl[i] = i * v / j;
	}

	v = 0x80;
	t = v;
	while (v < 0x98) {
		cbtbl[v] = t;
		crtbl[v] = t;
		cbtbl[v + 1] = t;
		crtbl[v + 1] = t;
		cbtbl[v + 2] = t;
		crtbl[v + 2] = t;
		v += 3;
		t++;
	}
	i = v;
	for (; v <= 0xFF; v++) {
		cbtbl[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
		crtbl[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
	}
}
