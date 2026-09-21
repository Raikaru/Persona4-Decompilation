/* CRI Sofdec MPEG video: the block coefficient decoders (MPEG-1 dct_coeff VLC table B.5,
 * dequantisation, zigzag store into the Float32 coefficient block). The AC loop is a 256-way
 * switch on an 8-bit look-ahead of the bit stream that decodes up to two coefficients (and a
 * following EOB) per step; look-aheads of longer codes fall back to the run/level tables.
 *
 * Bit reader: `bbuf` holds the current 32 bits left-aligned, `nbuf` the next word, `bitpos` the
 * number of bits of `bbuf` already consumed, `ptr` the word after `nbuf` (mpv_bit.h). The
 * look-ahead cases add their length to `bitpos` before the coefficient stores and refill after. */
#include "cri_xpt.h"
#include "mpv.h"

#define MPVABDEC_ESCAPE_RUN 0x40
#define MPVABDEC_D_PICTURE 4

#define MPVABDEC_SAVE_BIT()                                                                    \
	mpv->bbuf = bbuf;                                                                      \
	mpv->nbuf = nbuf;                                                                      \
	mpv->bitpos = bitpos;                                                                  \
	mpv->bitptr = ptr

/* the 32-bit look-ahead window */
#define MPVABDEC_PEEK32(val)                                                                   \
	val = bbuf;                                                                            \
	if (bitpos != 0) {                                                                     \
		val |= nbuf >> (32 - bitpos);                                                  \
	}

/* refill after `bitpos` was advanced: a new word when the window is used up, else shift `from` */
#define MPVABDEC_FINISH(from, n)                                                               \
	if (bitpos >= 32) {                                                                    \
		bitpos -= 32;                                                                  \
		bbuf = nbuf << bitpos;                                                         \
		nbuf = *ptr++;                                                                 \
	} else {                                                                               \
		bbuf = (from) << (n);                                                          \
	}

#define MPVABDEC_SKIP(n)                                                                       \
	{                                                                                      \
		Uint32 nbit = (Uint32)(n);                                                     \
		bitpos += nbit;                                                                \
		MPVABDEC_FINISH(bbuf, nbit);                                                   \
	}

/* dequantised coefficient (forced odd) of a constant level into the block at prm->idx */
#define MPVABDEC_STORE(level, sgn)                                                             \
	{                                                                                      \
		Sint32 lq;                                                                     \
		Sint32 val;                                                                    \
		lq = MPVABDEC_LEVEL(level) * prm->qscale;                                      \
		val = ((lq * (Sint32)prm->iqm[prm->idx]) >> 4) - 1;                            \
		val |= 1;                                                                      \
		if (sgn) {                                                                     \
			val = -val;                                                            \
		}                                                                              \
		((Float32 *)prm->dst)[prm->idx] = (Float32)val * ((const Float32 *)mpv->scale_tbl)[prm->idx]; \
	}

/* the same for the decoded (prm->run, prm->level, prm->sign) coefficient */
#define MPVABDEC_STORERL()                                                                     \
	{                                                                                      \
		Sint32 lv = MPVABDEC_LEVEL(prm->level);                                        \
		Sint32 val;                                                                    \
		val = (((Sint32)prm->iqm[prm->idx] * (lv * prm->qscale)) >> 4) - 1;            \
		val |= 1;                                                                      \
		if (prm->sign) {                                                               \
			val = -val;                                                            \
		}                                                                              \
		((Float32 *)prm->dst)[prm->idx] = (Float32)val * ((const Float32 *)mpv->scale_tbl)[prm->idx]; \
	}

#define MPVABDEC_STORE_AT(ofs, level, sgn)                                                     \
	prm->idx = zz[ofs];                                                                    \
	MPVABDEC_STORE(level, sgn)

/* constant run/level/sign coefficients of the look-ahead cases: `ofs` = run + 1 zigzag steps */
#define MPVABDEC_AC1(ofs, level, sgn, n)                                                       \
	prm->idx = zz[ofs];                                                                    \
	bitpos += (n);                                                                         \
	MPVABDEC_STORE(level, sgn);                                                            \
	zz += (ofs);                                                                           \
	MPVABDEC_FINISH(bbuf, n)

#define MPVABDEC_AC2(ofs1, level1, sgn1, ofs2, level2, sgn2, n)                                \
	prm->idx = zz[ofs1];                                                                   \
	bitpos += (n);                                                                         \
	MPVABDEC_STORE(level1, sgn1);                                                          \
	MPVABDEC_STORE_AT(ofs2, level2, sgn2);                                                 \
	zz += (ofs2);                                                                          \
	MPVABDEC_FINISH(bbuf, n)

/* the same followed by an EOB (the block is finished, zz is not advanced) */
#define MPVABDEC_AC1_EOB(ofs, level, sgn, n)                                                   \
	prm->idx = zz[ofs];                                                                    \
	bitpos += (n);                                                                         \
	MPVABDEC_STORE(level, sgn);                                                            \
	MPVABDEC_FINISH(bbuf, n)

#define MPVABDEC_AC2_EOB(ofs1, level1, sgn1, ofs2, level2, sgn2, n)                            \
	prm->idx = zz[ofs1];                                                                   \
	bitpos += (n);                                                                         \
	MPVABDEC_STORE(level1, sgn1);                                                          \
	MPVABDEC_STORE_AT(ofs2, level2, sgn2);                                                 \
	MPVABDEC_FINISH(bbuf, n)

/* escape: 6-bit run, 8-bit level, 16-bit level when the first byte is 0x00/0x80 (`bits` holds
 * the look-ahead shifted left by one) */
#define MPVABDEC_ESCAPE(bits)                                                                  \
	{                                                                                      \
		Sint32 level;                                                                  \
		level = (Uint16)((bits) >> 11);                                                \
		level >>= 2;                                                                   \
		prm->run = (Sint8)((Uint32)level >> 8);                                        \
		level = (Sint8)level;                                                          \
		prm->len = 20;                                                                 \
		if ((level & 0x7F) == 0) {                                                     \
			Sint32 hi = level * 2;                                                 \
			level = hi | (Uint8)((bits) >> 5);                                     \
			prm->len += 8;                                                         \
		}                                                                              \
		if (level < 0) {                                                               \
			level = -level;                                                        \
			prm->sign = 1;                                                         \
		} else {                                                                       \
			prm->sign = 0;                                                         \
		}                                                                              \
		prm->level = level;                                                            \
	}

/* codes up to 8 bits after the leading zero through the (len << 16) | (level << 8) | run table;
 * `bits` (the shifted look-ahead) is consumed into the sign */
#define MPVABDEC_RL8(idx, bits)                                                                \
	{                                                                                      \
		Uint32 rl = mpv->rl_8[idx];                                                    \
		prm->run = (Uint8)mpv->rl_8[idx];                                              \
		if (prm->run != MPVABDEC_ESCAPE_RUN) {                                         \
			prm->len = rl >> 16;                                                   \
			prm->level = (Sint8)(rl >> 8);                                         \
			(bits) >>= 33 - prm->len;                                              \
			(bits) &= 1;                                                           \
			prm->sign = (bits);                                                    \
		} else {                                                                       \
			MPVABDEC_ESCAPE(bits);                                                 \
		}                                                                              \
	}

/* run/level tables of the 11..17-bit codes: (level << 8) | run halfwords; the low index bit is
 * the sign */
#define MPVABDEC_RLTBL(tbl, idx, n)                                                            \
	{                                                                                      \
		Sint32 rl;                                                                     \
		prm->len = (n);                                                                \
		rl = ((const Sint16 *)mpv->tbl)[((idx) & ~1U) >> 1];                          \
		prm->run = (Uint8)rl;                                                          \
		prm->level = (Sint8)((Uint32)rl >> 8);                                         \
		prm->sign = (idx) & 1;                                                         \
	}

/* 14..17-bit codes (`bits` = the look-ahead shifted left by one, consumed into the index) */
#define MPVABDEC_RL15(bits)                                                                    \
	{                                                                                      \
		Sint32 rl;                                                                     \
		if (((bits) >> 24) != 0) {                                                     \
			(bits) = (bits) >> 19;                                                 \
			prm->len = 14;                                                         \
			rl = ((const Sint16 *)mpv->rl_1)[((bits) & ~1U) >> 1];                 \
		} else if ((Sint32)((bits) << 8) < 0) {                                        \
			(bits) = ((bits) >> 18) & 0x1F;                                        \
			prm->len = 15;                                                         \
			rl = ((const Sint16 *)mpv->rl_0a)[((bits) & ~1U) >> 1];                \
		} else if ((Sint32)((bits) << 9) < 0) {                                        \
			(bits) = ((bits) >> 17) & 0x1F;                                        \
			prm->len = 16;                                                         \
			rl = ((const Sint16 *)mpv->rl_0b)[((bits) & ~1U) >> 1];                \
		} else {                                                                       \
			(bits) = ((bits) >> 16) & 0x1F;                                        \
			prm->len = 17;                                                         \
			rl = ((const Sint16 *)mpv->rl_0c)[((bits) & ~1U) >> 1];                \
		}                                                                              \
		prm->run = (Uint8)rl;                                                          \
		prm->level = (Sint8)((Uint32)rl >> 8);                                         \
		prm->sign = (bits) & 1;                                                        \
	}

/* the escape case of the look-ahead switch: the escape code bits in a fresh window */
#define MPVABDEC_CASE_ESC()                                                                    \
	{                                                                                      \
		Uint32 esc = mpvabdec_EscapeCode(code);                                        \
		MPVABDEC_ESCAPE(esc);                                                          \
	}                                                                                      \
	zz += prm->run + 1;                                                                    \
	prm->idx = *zz;                                                                        \
	MPVABDEC_STORERL();                                                                    \
	MPVABDEC_SKIP(prm->len)

/* the same in place (MPVABDEC_IntraBlock) */
#define MPVABDEC_CASE_ESC_INPLACE()                                                            \
	code <<= 1;                                                                            \
	MPVABDEC_ESCAPE(code);                                                                 \
	zz += prm->run + 1;                                                                    \
	prm->idx = *zz;                                                                        \
	MPVABDEC_STORERL();                                                                    \
	MPVABDEC_SKIP(prm->len)

/* the AC coefficient loop: a switch on the top 8 bits of the look-ahead (case bodies in source
 * order: the coefficient cases from 0xFF down, then the cases ending in an EOB, 0xFE down) */
#define MPVABDEC_AC_LOOP(ESC)                                                                  \
	do {                                                                                   \
		MPVABDEC_PEEK32(code);                                                         \
		switch (code >> 24) {                                                          \
		case 0xFC: case 0xFD: case 0xFF:                                               \
			MPVABDEC_AC2(1, 1, 1, 2, 1, 1, 6);                                     \
			continue;                                                              \
		case 0xF8: case 0xF9: case 0xFB:                                               \
			MPVABDEC_AC2(1, 1, 1, 2, 1, 0, 6);                                     \
			continue;                                                              \
		case 0xEE: case 0xEF:                                                          \
			MPVABDEC_AC2(1, 1, 1, 3, 1, 1, 7);                                     \
			continue;                                                              \
		case 0xEC: case 0xED:                                                          \
			MPVABDEC_AC2(1, 1, 1, 3, 1, 0, 7);                                     \
			continue;                                                              \
		case 0xEB:                                                                     \
			MPVABDEC_AC2(1, 1, 1, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0xEA:                                                                     \
			MPVABDEC_AC2(1, 1, 1, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0xE9:                                                                     \
			MPVABDEC_AC2(1, 1, 1, 2, 2, 1, 8);                                     \
			continue;                                                              \
		case 0xE8:                                                                     \
			MPVABDEC_AC2(1, 1, 1, 2, 2, 0, 8);                                     \
			continue;                                                              \
		case 0xE0: case 0xE1: case 0xE2: case 0xE3: case 0xE4: case 0xE5: case 0xE6: case 0xE7:\
			MPVABDEC_AC1(1, 1, 1, 3);                                              \
			continue;                                                              \
		case 0xDC: case 0xDD: case 0xDF:                                               \
			MPVABDEC_AC2(1, 1, 0, 2, 1, 1, 6);                                     \
			continue;                                                              \
		case 0xD8: case 0xD9: case 0xDB:                                               \
			MPVABDEC_AC2(1, 1, 0, 2, 1, 0, 6);                                     \
			continue;                                                              \
		case 0xCE: case 0xCF:                                                          \
			MPVABDEC_AC2(1, 1, 0, 3, 1, 1, 7);                                     \
			continue;                                                              \
		case 0xCC: case 0xCD:                                                          \
			MPVABDEC_AC2(1, 1, 0, 3, 1, 0, 7);                                     \
			continue;                                                              \
		case 0xCB:                                                                     \
			MPVABDEC_AC2(1, 1, 0, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0xCA:                                                                     \
			MPVABDEC_AC2(1, 1, 0, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0xC9:                                                                     \
			MPVABDEC_AC2(1, 1, 0, 2, 2, 1, 8);                                     \
			continue;                                                              \
		case 0xC8:                                                                     \
			MPVABDEC_AC2(1, 1, 0, 2, 2, 0, 8);                                     \
			continue;                                                              \
		case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5: case 0xC6: case 0xC7:\
			MPVABDEC_AC1(1, 1, 0, 3);                                              \
			continue;                                                              \
		case 0x7E: case 0x7F:                                                          \
			MPVABDEC_AC2(2, 1, 1, 3, 1, 1, 7);                                     \
			continue;                                                              \
		case 0x7C: case 0x7D:                                                          \
			MPVABDEC_AC2(2, 1, 1, 3, 1, 0, 7);                                     \
			continue;                                                              \
		case 0x77:                                                                     \
			MPVABDEC_AC2(2, 1, 1, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x76:                                                                     \
			MPVABDEC_AC2(2, 1, 1, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75:              \
			MPVABDEC_AC1(2, 1, 1, 4);                                              \
			continue;                                                              \
		case 0x6E: case 0x6F:                                                          \
			MPVABDEC_AC2(2, 1, 0, 3, 1, 1, 7);                                     \
			continue;                                                              \
		case 0x6C: case 0x6D:                                                          \
			MPVABDEC_AC2(2, 1, 0, 3, 1, 0, 7);                                     \
			continue;                                                              \
		case 0x67:                                                                     \
			MPVABDEC_AC2(2, 1, 0, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x66:                                                                     \
			MPVABDEC_AC2(2, 1, 0, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x60: case 0x61: case 0x62: case 0x63: case 0x64: case 0x65:              \
			MPVABDEC_AC1(2, 1, 0, 4);                                              \
			continue;                                                              \
		case 0x5F:                                                                     \
			MPVABDEC_AC2(3, 1, 1, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x5E:                                                                     \
			MPVABDEC_AC2(3, 1, 1, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x58: case 0x59: case 0x5A: case 0x5B:                                    \
			MPVABDEC_AC1(3, 1, 1, 5);                                              \
			continue;                                                              \
		case 0x57:                                                                     \
			MPVABDEC_AC2(3, 1, 0, 4, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x56:                                                                     \
			MPVABDEC_AC2(3, 1, 0, 4, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x50: case 0x51: case 0x52: case 0x53:                                    \
			MPVABDEC_AC1(3, 1, 0, 5);                                              \
			continue;                                                              \
		case 0x4F:                                                                     \
			MPVABDEC_AC2(1, 2, 1, 2, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x4E:                                                                     \
			MPVABDEC_AC2(1, 2, 1, 2, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x48: case 0x49: case 0x4A: case 0x4B:                                    \
			MPVABDEC_AC1(1, 2, 1, 5);                                              \
			continue;                                                              \
		case 0x47:                                                                     \
			MPVABDEC_AC2(1, 2, 0, 2, 1, 1, 8);                                     \
			continue;                                                              \
		case 0x46:                                                                     \
			MPVABDEC_AC2(1, 2, 0, 2, 1, 0, 8);                                     \
			continue;                                                              \
		case 0x40: case 0x41: case 0x42: case 0x43:                                    \
			MPVABDEC_AC1(1, 2, 0, 5);                                              \
			continue;                                                              \
		case 0x3C: case 0x3D: case 0x3F:                                               \
			MPVABDEC_AC1(4, 1, 1, 6);                                              \
			continue;                                                              \
		case 0x38: case 0x39: case 0x3B:                                               \
			MPVABDEC_AC1(4, 1, 0, 6);                                              \
			continue;                                                              \
		case 0x34: case 0x35: case 0x37:                                               \
			MPVABDEC_AC1(5, 1, 1, 6);                                              \
			continue;                                                              \
		case 0x30: case 0x31: case 0x33:                                               \
			MPVABDEC_AC1(5, 1, 0, 6);                                              \
			continue;                                                              \
		case 0x2C: case 0x2D: case 0x2F:                                               \
			MPVABDEC_AC1(1, 3, 1, 6);                                              \
			continue;                                                              \
		case 0x28: case 0x29: case 0x2B:                                               \
			MPVABDEC_AC1(1, 3, 0, 6);                                              \
			continue;                                                              \
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27:\
			code <<= 1;                                                            \
			x = code >> 25;                                                        \
			MPVABDEC_RL8(x, code);                                                 \
			MPVABDEC_SKIP(prm->len);                                               \
			zz += prm->run + 1;                                                    \
			prm->idx = *zz;                                                        \
			MPVABDEC_STORERL();                                                    \
			continue;                                                              \
		case 0x1E: case 0x1F:                                                          \
			MPVABDEC_AC1(6, 1, 1, 7);                                              \
			continue;                                                              \
		case 0x1C: case 0x1D:                                                          \
			MPVABDEC_AC1(6, 1, 0, 7);                                              \
			continue;                                                              \
		case 0x1A: case 0x1B:                                                          \
			MPVABDEC_AC1(2, 2, 1, 7);                                              \
			continue;                                                              \
		case 0x18: case 0x19:                                                          \
			MPVABDEC_AC1(2, 2, 0, 7);                                              \
			continue;                                                              \
		case 0x16: case 0x17:                                                          \
			MPVABDEC_AC1(7, 1, 1, 7);                                              \
			continue;                                                              \
		case 0x14: case 0x15:                                                          \
			MPVABDEC_AC1(7, 1, 0, 7);                                              \
			continue;                                                              \
		case 0x12: case 0x13:                                                          \
			MPVABDEC_AC1(8, 1, 1, 7);                                              \
			continue;                                                              \
		case 0x10: case 0x11:                                                          \
			MPVABDEC_AC1(8, 1, 0, 7);                                              \
			continue;                                                              \
		case 0x0F:                                                                     \
			MPVABDEC_AC1(9, 1, 1, 8);                                              \
			continue;                                                              \
		case 0x0E:                                                                     \
			MPVABDEC_AC1(9, 1, 0, 8);                                              \
			continue;                                                              \
		case 0x0D:                                                                     \
			MPVABDEC_AC1(1, 4, 1, 8);                                              \
			continue;                                                              \
		case 0x0C:                                                                     \
			MPVABDEC_AC1(1, 4, 0, 8);                                              \
			continue;                                                              \
		case 0x0B:                                                                     \
			MPVABDEC_AC1(10, 1, 1, 8);                                             \
			continue;                                                              \
		case 0x0A:                                                                     \
			MPVABDEC_AC1(10, 1, 0, 8);                                             \
			continue;                                                              \
		case 0x09:                                                                     \
			MPVABDEC_AC1(3, 2, 1, 8);                                              \
			continue;                                                              \
		case 0x08:                                                                     \
			MPVABDEC_AC1(3, 2, 0, 8);                                              \
			continue;                                                              \
		case 0x04: case 0x05: case 0x06: case 0x07:                                    \
			ESC();                                                                 \
			continue;                                                              \
		case 0x02: case 0x03:                                                          \
			x = (code >> 21) & 0x3FF;                                              \
			MPVABDEC_RLTBL(rl_4, x, 11);                                           \
			MPVABDEC_SKIP(prm->len);                                               \
			zz += prm->run + 1;                                                    \
			prm->idx = *zz;                                                        \
			MPVABDEC_STORERL();                                                    \
			continue;                                                              \
		case 0x01:                                                                     \
			x = (code >> 19) & 0xFFF;                                              \
			MPVABDEC_RLTBL(rl_2, x, 13);                                           \
			MPVABDEC_SKIP(prm->len);                                               \
			zz += prm->run + 1;                                                    \
			prm->idx = *zz;                                                        \
			MPVABDEC_STORERL();                                                    \
			continue;                                                              \
		case 0x00:                                                                     \
			code <<= 1;                                                            \
			MPVABDEC_RL15(code);                                                   \
			MPVABDEC_SKIP(prm->len);                                               \
			zz += prm->run + 1;                                                    \
			prm->idx = *zz;                                                        \
			MPVABDEC_STORERL();                                                    \
			continue;                                                              \
		case 0xFE:                                                                     \
			MPVABDEC_AC2_EOB(1, 1, 1, 2, 1, 1, 8);                                 \
			break;                                                                 \
		case 0xFA:                                                                     \
			MPVABDEC_AC2_EOB(1, 1, 1, 2, 1, 0, 8);                                 \
			break;                                                                 \
		case 0xF0: case 0xF1: case 0xF2: case 0xF3: case 0xF4: case 0xF5: case 0xF6: case 0xF7:\
			MPVABDEC_AC1_EOB(1, 1, 1, 5);                                          \
			break;                                                                 \
		case 0xDE:                                                                     \
			MPVABDEC_AC2_EOB(1, 1, 0, 2, 1, 1, 8);                                 \
			break;                                                                 \
		case 0xDA:                                                                     \
			MPVABDEC_AC2_EOB(1, 1, 0, 2, 1, 0, 8);                                 \
			break;                                                                 \
		case 0xD0: case 0xD1: case 0xD2: case 0xD3: case 0xD4: case 0xD5: case 0xD6: case 0xD7:\
			MPVABDEC_AC1_EOB(1, 1, 0, 5);                                          \
			break;                                                                 \
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87:\
		case 0x88: case 0x89: case 0x8A: case 0x8B: case 0x8C: case 0x8D: case 0x8E: case 0x8F:\
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97:\
		case 0x98: case 0x99: case 0x9A: case 0x9B: case 0x9C: case 0x9D: case 0x9E: case 0x9F:\
		case 0xA0: case 0xA1: case 0xA2: case 0xA3: case 0xA4: case 0xA5: case 0xA6: case 0xA7:\
		case 0xA8: case 0xA9: case 0xAA: case 0xAB: case 0xAC: case 0xAD: case 0xAE: case 0xAF:\
		case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4: case 0xB5: case 0xB6: case 0xB7:\
		case 0xB8: case 0xB9: case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:\
			MPVABDEC_SKIP(2);                                                      \
			break;                                                                 \
		case 0x78: case 0x79: case 0x7A: case 0x7B:                                    \
			MPVABDEC_AC1_EOB(2, 1, 1, 6);                                          \
			break;                                                                 \
		case 0x68: case 0x69: case 0x6A: case 0x6B:                                    \
			MPVABDEC_AC1_EOB(2, 1, 0, 6);                                          \
			break;                                                                 \
		case 0x5C: case 0x5D:                                                          \
			MPVABDEC_AC1_EOB(3, 1, 1, 7);                                          \
			break;                                                                 \
		case 0x54: case 0x55:                                                          \
			MPVABDEC_AC1_EOB(3, 1, 0, 7);                                          \
			break;                                                                 \
		case 0x4C: case 0x4D:                                                          \
			MPVABDEC_AC1_EOB(1, 2, 1, 7);                                          \
			break;                                                                 \
		case 0x44: case 0x45:                                                          \
			MPVABDEC_AC1_EOB(1, 2, 0, 7);                                          \
			break;                                                                 \
		case 0x3E:                                                                     \
			MPVABDEC_AC1_EOB(4, 1, 1, 8);                                          \
			break;                                                                 \
		case 0x3A:                                                                     \
			MPVABDEC_AC1_EOB(4, 1, 0, 8);                                          \
			break;                                                                 \
		case 0x36:                                                                     \
			MPVABDEC_AC1_EOB(5, 1, 1, 8);                                          \
			break;                                                                 \
		case 0x32:                                                                     \
			MPVABDEC_AC1_EOB(5, 1, 0, 8);                                          \
			break;                                                                 \
		case 0x2E:                                                                     \
			MPVABDEC_AC1_EOB(1, 3, 1, 8);                                          \
			break;                                                                 \
		case 0x2A:                                                                     \
			MPVABDEC_AC1_EOB(1, 3, 0, 8);                                          \
			break;                                                                 \
		}                                                                              \
		break;                                                                         \
	} while (1)

/* the return value: the zigzag position of the only coefficient, negative when there were more */
#define MPVABDEC_RESULT()                                                                      \
	MPVABDEC_SAVE_BIT();                                                                   \
	val = prm->idx;                                                                        \
	if (val != prm->idx0) {                                                                \
		val = -val;                                                                    \
	}                                                                                      \
	prm->idx = val;                                                                        \
	return prm->idx

// Escape-code case of the AC look-ahead table: the 8-bit window is doubled to index the run/level
// escape decoder.
static inline Uint32 mpvabdec_EscapeCode(Uint32 code)
{
	return code << 1;
}

/* non-intra dequantisation: (2 * level + 1) * quantiser_scale * iqm / 16 */
#define MPVABDEC_LEVEL(level) ((level) * 2 + 1)

/* the whole non-intra decoder is one function: the first-coefficient helpers are inlined into
 * the AC loop body */
#pragma inline_max_size(100000)
#pragma inline_max_total_size(100000)

/* the first coefficient of a non-intra block: '1s' is run 0 level 1, the rest through the
 * run/level tables (no 8-bit look-ahead cases) */
static inline void mpvabdec_NintraFirst(MPV mpv, MPV_BLKPRM *prm, Uint32 bbuf0, Uint32 nbuf, Sint32 bitpos)
{
	Uint32 code = bbuf0;
	Uint32 n;
	Sint32 rl;

	if (bitpos != 0) {
		code |= nbuf >> (32 - bitpos);
	}
	if ((Sint32)code < 0) {
		prm->sign = (code >> 30) & 1;
		prm->level = 1;
		prm->run = 0;
		prm->len = 2;
		return;
	}
	code <<= 1;
	n = code >> 24;
	switch ((Sint32)n) {
	default:
		MPVABDEC_RL8(n >> 1, code);
		return;
	case 4: case 5: case 6: case 7:
		code >>= 22;
		prm->len = 11;
		rl = ((const Sint16 *)mpv->rl_4)[(code & ~1U) >> 1];
		break;
	case 2: case 3:
		code >>= 20;
		prm->len = 13;
		rl = ((const Sint16 *)mpv->rl_2)[(code & ~1U) >> 1];
		break;
	case 1:
		code >>= 19;
		prm->len = 14;
		rl = ((const Sint16 *)mpv->rl_1)[(code & ~1U) >> 1];
		break;
	case 0:
		if ((Sint32)(code << 8) < 0) {
			code = (code >> 18) & 0x1F;
			prm->len = 15;
			rl = ((const Sint16 *)mpv->rl_0a)[(code & ~1U) >> 1];
		} else if ((Sint32)(code << 9) < 0) {
			code = (code >> 17) & 0x1F;
			prm->len = 16;
			rl = ((const Sint16 *)mpv->rl_0b)[(code & ~1U) >> 1];
		} else {
			code = (code >> 16) & 0x1F;
			prm->len = 17;
			rl = ((const Sint16 *)mpv->rl_0c)[(code & ~1U) >> 1];
		}
		break;
	}
	prm->run = (Uint8)rl;
	prm->level = (Sint8)((Uint32)rl >> 8);
	prm->sign = code & 1;
}

/* skip the first coefficient's code */
static inline Uint32 mpvabdec_NintraSkipFirst(Uint32 bbuf0, Uint32 n, Sint32 *bitpos_p, Uint32 *nbuf_p, Uint32 **ptr_p)
{
	Uint32 bbuf;
	*bitpos_p += n;
	if (*bitpos_p >= 32) {
		*bitpos_p -= 32;
		bbuf = *nbuf_p << *bitpos_p;
		*nbuf_p = *(*ptr_p)++;
	} else {
		bbuf = bbuf0 << n;
	}
	return bbuf;
}

/* store the first coefficient, decode the rest, save the bit reader */
static inline Sint32 mpvabdec_NintraAc(MPV mpv, MPV_BLKPRM *prm, Uint32 bbuf, Uint32 nbuf, Sint32 bitpos, Uint32 *ptr)
{
	const Sint8 *zz;
	Sint32 val;

	zz = mpv->zigzag_tbl + prm->run;
	prm->idx = prm->idx0 = *zz;
	MPVABDEC_STORERL();
	{
		Uint32 code;
		Uint32 x;
		MPVABDEC_AC_LOOP(MPVABDEC_CASE_ESC);
	}
	MPVABDEC_RESULT();
}

// Non-intra block: first coefficient by the special first-coefficient code, then the AC loop
// (dequantise with the non-intra matrix and qscale, store zigzag into the Float32 block) up to EOB;
// returns the last zigzag index (negative when more than one coefficient).
static inline Sint32 mpvabdec_NintraDecode(MPV mpv, MPV_BLKPRM *prm)
{
	Uint32 bbuf0;
	Uint32 *ptr;
	Uint32 bbuf;
	Uint32 nbuf;
	Sint32 bitpos;

	bitpos = mpv->bitpos;
	bbuf0 = mpv->bbuf;
	nbuf = mpv->nbuf;
	ptr = mpv->bitptr;
	mpvabdec_NintraFirst(mpv, prm, bbuf0, nbuf, bitpos);
	bbuf = mpvabdec_NintraSkipFirst(bbuf0, prm->len, &bitpos, &nbuf, &ptr);
	return mpvabdec_NintraAc(mpv, prm, bbuf, nbuf, bitpos, ptr);
}

/* non-intra block: the coefficient block is cleared first */
Sint32 MPVABDEC_NintraBlock(MPV mpv, MPV_BLKPRM *prm)
{
	Float64 *blk = prm->dst;

	blk[0] = 0.0;
	blk[1] = 0.0;
	blk[2] = 0.0;
	blk[3] = 0.0;
	blk[4] = 0.0;
	blk[5] = 0.0;
	blk[6] = 0.0;
	blk[7] = 0.0;
	blk[8] = 0.0;
	blk[9] = 0.0;
	blk[10] = 0.0;
	blk[11] = 0.0;
	blk[12] = 0.0;
	blk[13] = 0.0;
	blk[14] = 0.0;
	blk[15] = 0.0;
	blk[16] = 0.0;
	blk[17] = 0.0;
	blk[18] = 0.0;
	blk[19] = 0.0;
	blk[20] = 0.0;
	blk[21] = 0.0;
	blk[22] = 0.0;
	blk[23] = 0.0;
	blk[24] = 0.0;
	blk[25] = 0.0;
	blk[26] = 0.0;
	blk[27] = 0.0;
	blk[28] = 0.0;
	blk[29] = 0.0;
	blk[30] = 0.0;
	blk[31] = 0.0;
	return mpvabdec_NintraDecode(mpv, prm);
}

/* intra dequantisation: 2 * level * quantiser_scale * iqm / 16 */
#undef MPVABDEC_LEVEL
#define MPVABDEC_LEVEL(level) ((level) * 2)

/* intra block, 8-bit DC (MPEG-1): dct_dc_size from the 7-bit look-ahead table */
Sint32 MPVABDEC_IntraBlock(MPV mpv, MPV_BLKPRM *prm)
{
	Uint32 bbuf = mpv->bbuf;
	Uint32 nbuf = mpv->nbuf;
	Sint32 bitpos = mpv->bitpos;
	Uint32 *ptr = mpv->bitptr;
	const Sint8 *zz;
	Sint32 val;
	Uint32 dcv;
	Uint32 dcx;
	Uint32 len;
	Sint32 dc;

	dcv = bbuf >> 16;
	if (bitpos > 16) {
		dcv |= nbuf >> (48 - bitpos);
	}
	dcx = ((const Uint8 *)prm->dctbl)[dcv >> 9];
	dc = dcx >> 4;
	len = dcx & 0xF;
	if (dc != 0) {
		Uint32 sbit;

		dcv &= ((const Sint16 *)mpv->bitmsk_tbl)[len];
		len += dc;
		dcv >>= 16 - len;
		sbit = 1U << (dc - 1);
		if ((dcv & sbit) == 0) {
			dcv += 1 - (Sint32)(sbit * 2);
		}
		dc = (Sint32)dcv * 8;
	}
	MPVABDEC_SKIP(len);
	dc += *prm->dcpred;
	*prm->dcpred = dc;
	((Float32 *)prm->dst)[0] = 0.125f * (Float32)dc;
	prm->idx0 = 0;
	prm->idx = 0;
	zz = mpv->zigzag_tbl;
	if (mpv->picatr.pic_type != MPVABDEC_D_PICTURE) {
		Uint32 code;
		Uint32 x;
		MPVABDEC_AC_LOOP(MPVABDEC_CASE_ESC_INPLACE);
	}
	MPVABDEC_RESULT();
}

/* intra block, 11-bit DC (MPEG-2 intra_dc_precision 3): 10-bit look-ahead table */
Sint32 MPVABDEC_IntraBlockDc11(MPV mpv, MPV_BLKPRM *prm)
{
	Uint32 bbuf0 = mpv->bbuf;
	Uint32 bbuf;
	Uint32 nbuf = mpv->nbuf;
	Sint32 bitpos = mpv->bitpos;
	Uint32 *ptr = mpv->bitptr;
	const Sint8 *zz;
	Uint32 code;
	Uint32 x;
	Sint32 val;
	Uint32 dcx;
	Uint32 len;
	Sint32 dc;

	code = bbuf0;
	if (bitpos != 0) {
		code |= nbuf >> (32 - bitpos);
	}
	dcx = ((const Uint8 *)prm->dctbl)[code >> 22];
	dc = dcx >> 4;
	len = dcx & 0xF;
	if (dc != 0) {
		code <<= len;
		len += dc;
		code = (Uint32)(((Sint32)code >> 1) ^ (Sint32)0x80000000);
		dc = ((Sint32)code >> (31 - dc)) + (Sint32)(code >> 31);
	}
	bitpos += len;
	MPVABDEC_FINISH(bbuf0, len);
	dc += *prm->dcpred;
	*prm->dcpred = dc;
	((Float32 *)prm->dst)[0] = 0.125f * (Float32)dc;
	prm->idx0 = 0;
	prm->idx = 0;
	zz = mpv->zigzag_tbl;
	MPVABDEC_AC_LOOP(MPVABDEC_CASE_ESC);
	MPVABDEC_RESULT();
}
