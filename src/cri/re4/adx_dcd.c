/* ADX header / info decoding (adx_dcd.c): the 0x8000 header block, its AINF / loop / delay
 * extensions, the 0x8001 footer, the info code scan for linked files and the second-order
 * prediction coefficients of the encoder cut-off (MSL inline sqrt / sqrtf / fpclassify). */
#include <string.h>
#include "cri_xpt.h"

extern double cos(double x);
extern float __float_nan;

#define FP_NAN 1
#define FP_INFINITE 2
#define FP_ZERO 3
#define FP_NORMAL 4
#define FP_SUBNORMAL 5

#define ADX_LD16(p) (((p)[0] << 8) | (p)[1])
#define ADX_LD32(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])
#define ADX_HDR 0x8000
#define ADX_FOOTER 0x8001
#define ADX_AINF 0x41494E46

/* MSL math.h inline sqrt (double): three Newton steps on the reciprocal square root estimate */
static inline double adx_sqrt(double x)
{
	const double _half = .5;
	const double _three = 3.0;

	if (x > 0.0) {
		double guess = __frsqrte(x);
		guess = _half * guess * (_three - guess * guess * x);
		guess = _half * guess * (_three - guess * guess * x);
		guess = _half * guess * (_three - guess * guess * x);
		return x * guess;
	} else if (x == 0.0) {
		return 0.0;
	} else if (x < 0.0) {
		return __float_nan;
	}
	return x;
}

// MSL fpclassify for floats (inlined into adx_sqrtf's NaN check).
static inline long adx_fpclassifyf(float x)
{
	switch ((*(unsigned long *)&x) & 0x7f800000) {
	case 0x7f800000:
		if ((*(unsigned long *)&x) & 0x007fffff) {
			return FP_NAN;
		}
		return FP_INFINITE;
	case 0:
		if ((*(unsigned long *)&x) & 0x007fffff) {
			return FP_SUBNORMAL;
		}
		return FP_ZERO;
	default:
		return FP_NORMAL;
	}
}

// MSL inline sqrtf: three Newton steps on __frsqrte; NaN for negative or NaN input.
static inline float adx_sqrtf(float x)
{
	const double _half = .5;
	const double _three = 3.0;

	if (x > 0.0f) {
		double guess = __frsqrte((double)x);
		guess = _half * guess * (_three - guess * guess * x);
		guess = _half * guess * (_three - guess * guess * x);
		guess = _half * guess * (_three - guess * guess * x);
		return (float)(x * guess);
	} else if (x < 0.0) {
		return __float_nan;
	} else if (adx_fpclassifyf(x) == FP_NAN) {
		return __float_nan;
	}
	return x;
}

/* header block length rounded to the block alignment (with / without the loop extension).
 * The leading constant keeps the add chain in source order (the constant becomes the trailing
 * `addi`); without it MWCC defers the leaf next to the strlen() call to the end of the chain. */
Sint32 ADX_CalcHdrInfoLen(Sint32 loop, Sint32 infolen, Sint32 ofst, Sint32 align)
{
	if (loop == 0) {
		return (Uint32)(0x1B + infolen + strlen("(c)CRI") + ofst + align) / align * align - ofst;
	}
	return (Uint32)(0x33 + infolen + strlen("(c)CRI") + ofst + align) / align * align - ofst;
}

// Parses an ADX end code (0x8001) block: *ofst = its length (padding + 4). -1 if fewer than 16
// bytes, -2 if not an end code.
Sint32 ADX_DecodeFooter(Uint8 *data, Sint32 len, Sint16 *ofst)
{
	if (len < 0x10) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_FOOTER) {
		return -2;
	}
	*ofst = *(Sint16 *)(data + 2) + 4;
	return 0;
}

/* header check and encoder version bytes */
static Sint32 adx_GetVer(Uint8 *data, Sint32 len, Uint8 *major, Uint8 *minor)
{
	if (len < 0x14) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_HDR) {
		return -2;
	}
	if (*(Sint16 *)(data + 2) < 0x10) {
		return -1;
	}
	*major = data[0x12];
	*minor = data[0x13];
	return 0;
}

// Extracts the AINF chunk of a header (after the loop block): its size, the 16-byte id, the default
// output volume *a and pans b[0..1]. -1 short data, -2 no AINF.
Sint32 ADX_DecodeInfoAinf(Uint8 *data, Sint32 len, Sint32 *ainfsiz, void *ainf, Sint16 *a, Sint16 *b)
{
	Uint8 ver;
	Uint8 minor;
	Sint32 err;
	Sint32 need;
	Sint32 ofs;
	Uint8 *p;

	*ainfsiz = 0;
	err = adx_GetVer(data, len, &ver, &minor);
	if (err != 0) {
		return err;
	}
	need = (ver == 4) ? 0x48 : 0x3C;
	if (len < need) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_HDR) {
		return -2;
	}
	if (*(Sint16 *)(data + 2) < need - 4) {
		return -1;
	}
	/* default + conditional store defines ofs in its callee-saved register (`li r28`); the ternary
	 * computes a temporary and lets `ofs += 4` define the variable. */
	ofs = 0x14;
	if (ver == 4) {
		ofs = 0x20;
	}
	p = (Uint8 *)((Uint32)ofs + (Uint32)data);
	ofs += 4;
	if (*(Sint16 *)(p + 2) != 0) {
		ofs += 0x14;
	}
	/* the AINF address is an expression, not a local: `data + ofs` of data[ofs] and of the +4 read is
	 * one frontend CSE temp (byte 0 = `lbz 0(t)`), the +1..+3 reads and the memcpy argument recompute
	 * it as backend adds that the pre-RA CSE folds into that one add; the argument's copy `mr r4, t;
	 * addi r4, r4, 8` is coalesced, so the address takes r4 and the byte temporaries r3/r7/r8. A `q`
	 * local ranks below the byte temporaries (q r8). */
	if (ADX_LD32(&data[ofs]) != ADX_AINF) {
		return -2;
	}
	*ainfsiz = *(Sint32 *)(data + ofs + 4);
	memcpy(ainf, &data[ofs + 8], 16);
	p = (Uint8 *)((Uint32)ofs + (Uint32)data);
	*a = *(Sint16 *)(p + 0x18);
	b[0] = *(Sint16 *)(p + 0x1C);
	b[1] = *(Sint16 *)(p + 0x1E);
	return 0;
}

// Extracts the loop block (version 3 at 0x14, version 4 at 0x20): type, count (must be 1), flag,
// start/end in samples and in bytes. -2 when there is no single loop.
Sint32 ADX_DecodeInfoExLoop(Uint8 *data, Sint32 len, Sint32 *lptype, Sint16 *nloop, Sint16 *lpflg, Sint32 *lpstart,
                            Sint32 *lpstartofst, Sint32 *lpend, Sint32 *lpendofst)
{
	Uint8 ver;
	Uint8 minor;
	Sint32 err;
	Sint32 need;
	Sint32 ofs;
	Uint8 *p;

	*nloop = 0;
	err = adx_GetVer(data, len, &ver, &minor);
	if (err != 0) {
		return err;
	}
	need = (ver == 4) ? 0x3C : 0x30;
	if (len < need) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_HDR) {
		return -2;
	}
	if (*(Sint16 *)(data + 2) < need - 4) {
		return -1;
	}
	ofs = (ver == 4) ? 0x20 : 0x14;
	*lptype = *(Sint16 *)(data + ofs);
	p = (Uint8 *)((Uint32)ofs + (Uint32)data);
	*nloop = *(Sint16 *)(p + 2);
	if (*nloop != 1) {
		return -2;
	}
	*lpflg = *(Sint16 *)(p + 6);
	*lpstart = *(Sint32 *)(p + 8);
	*lpstartofst = *(Sint32 *)(p + 0xC);
	*lpend = *(Sint32 *)(p + 0x10);
	*lpendofst = *(Sint32 *)(p + 0x14);
	return 0;
}

/* initial delay of the two channels (version 4 headers only) */
Sint32 ADX_DecodeInfoExIdly(Uint8 *data, Sint32 len, Uint16 *idly, Uint16 *idly2)
{
	Uint8 ver;
	Uint8 minor;

	if (adx_GetVer(data, len, &ver, &minor) != 0) {
		return -1;
	}
	if (ver >= 4) {
		if (len < 0x20) {
			return -1;
		}
		if (*(Uint16 *)data != ADX_HDR) {
			return -2;
		}
		if (*(Sint16 *)(data + 2) < 0x1C) {
			return -1;
		}
		idly[0] = *(Uint16 *)(data + 0x18);
		idly2[0] = *(Uint16 *)(data + 0x1A);
		idly[1] = *(Uint16 *)(data + 0x1C);
		idly2[1] = *(Uint16 *)(data + 0x1E);
	} else {
		idly2[1] = 0;
		idly[1] = 0;
		idly2[0] = 0;
		idly[0] = 0;
	}
	return 0;
}

// Encoder version bytes (major at 0x12, minor at 0x13) that select the decryption key scheme.
Sint32 ADX_DecodeInfoExVer(Uint8 *data, Sint32 len, Uint8 *major, Uint8 *minor)
{
	if (len < 0x14) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_HDR) {
		return -2;
	}
	if (*(Sint16 *)(data + 2) < 0x10) {
		return -1;
	}
	*major = data[0x12];
	*minor = data[0x13];
	return 0;
}

// The encoder's high-pass cut-off frequency (Hz) at offset 0x10, used to derive the prediction
// coefficients.
Sint32 ADX_DecodeInfoExADPCM2(Uint8 *data, Sint32 len, Uint16 *cutoff)
{
	if (len < 0x12) {
		return -1;
	}
	if (*(Uint16 *)data != ADX_HDR) {
		return -2;
	}
	if (*(Sint16 *)(data + 2) < 0xE) {
		return -1;
	}
	*cutoff = *(Uint16 *)(data + 0x10);
	return 0;
}

// Parses the fixed 16-byte ADX header: header length (offset field + 4), encoding type, block size
// in bytes, bits per sample, channels, sampling rate, total samples and the derived samples per
// block. -1 short, -2 not 0x8000.
Sint32 ADX_DecodeInfo(Uint8 *data, Sint32 len, Sint16 *hdrlen, Sint8 *fmt, Sint8 *bps, Sint8 *blksiz, Sint8 *nch,
                      Sint32 *sfreq, Sint32 *nsmpl, Sint32 *blksmpl)
{
	if (len < 0x10) {
		return -1;
	}
	if ((Uint16)ADX_LD16(data) != ADX_HDR) {
		return -2;
	}
	*hdrlen = ADX_LD16(data + 2) + 4;
	*fmt = data[4];
	*blksiz = data[5];
	*bps = data[6];
	*nch = data[7];
	*sfreq = ADX_LD32(data + 8);
	*nsmpl = ADX_LD32(data + 12);
	if (*bps == 0) {
		*blksmpl = 0;
	} else {
		*blksmpl = (*blksiz - 2) * 8 / *bps;
	}
	return 0;
}

/* offset of the first 0x8000 info code word in data (-1: none) */
// FUN_004C5648
Sint32 ADX_ScanInfoCode(Uint8 *data, Sint32 len, Sint16 *ofst)
{
	Sint32 i;
	Sint32 pos;
	Uint16 code;

	pos = 0x7FFFFFFF;
	/* retail keeps 0x80 in $t1 (`addiu $t1, $zero, 0x80` at 0x004C5654) and
	 * loads `lhu`, not big-endian `-0x8000` via `lh`. */
	code = 0x80;
	for (i = 0; i < len - 1; i += 2) {
		if (*(Uint16 *)(data + i) == code) {
			pos = (i < pos) ? i : pos;
			break;
		}
	}
	if (pos != 0x7FFFFFFF) {
		*ofst = pos;
		return 0;
	}
	*ofst = 0;
	return -1;
}

/* prediction coefficients (12-bit fixed point) of a high-pass with the given cut-off.
 * COMPILER-DIFF: M2 - the original does not count float literals first created by the function
 * towards the >= 3 pool-member threshold and loads the nine literals unpooled; our 2.4.7 counts
 * them and addresses them through a `...rodata.0` base. `pool_data off` switches the pool off for
 * this function (the unit has no .bss pool that would be lost). */
// Second-order prediction coefficients (12-bit fixed point) of the ADX high-pass for `cutoff` Hz at
// `sfreq`: c1 = 2c, c2 = -c^2 with c from the cosine of the normalised cut-off.
void ADX_GetCoefficient(Sint32 cutoff, Sint32 sfreq, Sint16 *c1, Sint16 *c2)
{
	Float32 z;
	Float32 a;
	Float32 b;
	Float32 d;
	Float32 c;

	z = (Float32)cos(6.2831855f * (Float32)cutoff / (Float32)sfreq);
	a = (Float32)adx_sqrt(2.0) - z;
	b = (Float32)adx_sqrt(2.0) - 1.0f;
	d = adx_sqrtf((a + b) * (a - b));
	c = (a - d) / b;
	*c1 = (Sint16)(4096.0f * (2.0f * c));
	*c2 = (Sint16)(4096.0f * (-c * c));
}
