/* MPEG video: detect "empty" P/B pictures (a single slice whose macroblocks are all skipped). The
 * bit reader is a two-word window (`bbuf` current word, `nbuf` next word, `bitpos` bits consumed of
 * `bbuf`) written as macros; three forms exist in the original (GET, SKIP, GET1). */
#include "cri_xpt.h"
#include "mpv.h"

/* macroblock_address_increment VLC: (code << 8) | length, indexed by the increment */
Sint16 mpvemp_mbai[36] = {
	0x0000, 0x0101, 0x0303, 0x0203, 0x0304, 0x0204, 0x0305, 0x0205,
	0x0707, 0x0607, 0x0B08, 0x0A08, 0x0908, 0x0808, 0x0708, 0x0608,
	0x170A, 0x160A, 0x150A, 0x140A, 0x130A, 0x120A, 0x230B, 0x220B,
	0x210B, 0x200B, 0x1F0B, 0x1E0B, 0x1D0B, 0x1C0B, 0x1B0B, 0x1A0B,
	0x190B, 0x180B, 0x0F0B, 0x080B,
};

#define MPVEMP_INIT(buf)                                                                       \
	ptr = (Uint32 *)((Uint32)(buf) & ~3);                                                  \
	bitpos = ((Uint32)(buf) - (Uint32)ptr) << 3;                                           \
	bbuf = *ptr++;                                                                         \
	bbuf <<= bitpos;                                                                       \
	nbuf = *ptr++

#define MPVEMP_PEEK(val, n)                                                                    \
	val = bbuf >> (32 - (n));                                                              \
	if (bitpos > 32 - (n)) {                                                               \
		val |= nbuf >> (64 - (n) - bitpos);                                            \
	}

/* the first read consumes the whole 32-bit window */
#define MPVEMP_GET32(val)                                                                      \
	if (bitpos != 0) {                                                                     \
		val = bbuf | (nbuf >> (32 - bitpos));                                          \
		bbuf = nbuf << bitpos;                                                         \
	} else {                                                                               \
		val = bbuf;                                                                    \
		bbuf = nbuf;                                                                   \
	}                                                                                      \
	nbuf = *ptr++

#define MPVEMP_GET(val, n)                                                                     \
	if (bitpos >= 32 - (n)) {                                                              \
		bitpos -= 32 - (n);                                                            \
		if (bitpos != 0) {                                                             \
			bbuf |= nbuf >> ((n) - bitpos);                                        \
			val = bbuf >> (32 - (n));                                              \
			bbuf = nbuf << bitpos;                                                 \
		} else {                                                                       \
			val = bbuf >> (32 - (n));                                              \
			bbuf = nbuf;                                                           \
		}                                                                              \
		nbuf = *ptr++;                                                                 \
	} else {                                                                               \
		val = bbuf >> (32 - (n));                                                      \
		bitpos += (n);                                                                 \
		bbuf <<= (n);                                                                  \
	}

#define MPVEMP_SKIP(n)                                                                         \
	bitpos += (n);                                                                         \
	if (bitpos >= 32) {                                                                    \
		bitpos -= 32;                                                                  \
		bbuf = nbuf << bitpos;                                                         \
		nbuf = *ptr++;                                                                 \
	} else {                                                                               \
		bbuf <<= (n);                                                                  \
	}

#define MPVEMP_GET1(val)                                                                       \
	val = bbuf >> 31;                                                                      \
	if (bitpos == 31) {                                                                    \
		bbuf = nbuf;                                                                   \
		nbuf = *ptr++;                                                                 \
		bitpos = 0;                                                                    \
	} else {                                                                               \
		bbuf <<= 1;                                                                    \
		bitpos++;                                                                      \
	}

/* current byte position (rounded up to the next byte boundary) */
#define MPVEMP_BYTEPTR(q)                                                                      \
	q = (Sint8 *)ptr;                                                                      \
	q += (bitpos + 7) >> 3;                                                                \
	q -= 8

// Whether the P picture at `buf` (nbyte bytes, nmb macroblocks) codes nothing: one slice whose
// macroblocks are all skipped or "forward, no coded blocks, zero vector". The video driver drops
// such pictures without decoding (their reference frame is re-shown).
Sint32 MPV_IsEmptyPpic(Sint8 *buf, Sint32 nbyte, Sint32 nmb)
{
	Sint32 bitpos;
	Uint32 *ptr;
	Uint32 bbuf;
	Uint32 nbuf;
	Sint32 cnt;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 pos;
	Sint8 *q;
	Sint8 *p;
	Sint32 flg;

	MPVEMP_INIT(buf);
	/* slice_start_code 1 */
	MPVEMP_GET32(val);
	if (val != 0x101) {
		return 0;
	}
	/* quantiser_scale_code */
	MPVEMP_GET(val, 5);
	/* extra_bit_slice */
	MPVEMP_GET1(val);
	if (val != 0) {
		return 0;
	}
	/* macroblock_address_increment = 1 */
	MPVEMP_GET1(val);
	if (val == 0) {
		return 0;
	}
	/* macroblock_type "001" (MC, not coded) + zero motion vectors "1" "1" */
	MPVEMP_PEEK(val, 5);
	if (val != 7) {
		return 0;
	}
	MPVEMP_SKIP(5);
	/* macroblock_escape codes for the remaining nmb - 1 macroblocks */
	cnt = nmb - 1;
	for (;;) {
		MPVEMP_PEEK(val, 11);
		if (val != 8) {
			break;
		}
		MPVEMP_SKIP(11);
		cnt -= 33;
		if (cnt <= 33) {
			break;
		}
	}
	if (cnt <= 0 || cnt > 33) {
		return 0;
	}
	code = mpvemp_mbai[cnt];
	len = code & 0xFF;
	MPVEMP_GET(val, len);
	if (val != code >> 8) {
		return 0;
	}
	MPVEMP_PEEK(val, 5);
	if (val != 7) {
		return 0;
	}
	MPVEMP_SKIP(5);
	MPVEMP_BYTEPTR(q);
	pos = q - buf;
	if (pos > nbyte) {
		return 0;
	}
	/* the picture must be followed by a delimiter inside the buffer */
	for (;;) {
		p = MPV_SearchDelim(q, nbyte - pos, 0xCC);
		if (p == NULL) {
			return 0;
		}
		flg = MPV_CheckDelim(p);
		if (flg & 0x04) {
			/* picture_start_code: only a following B picture keeps this one empty */
			if ((((p[5] & 3) << 1) | ((p[6] >> 7) & 1)) != 3) {
				return 0;
			}
			q = p + 1;
			pos = q - buf;
			continue;
		}
		if (flg & 0x40) {
			q = p + 1;
			pos = q - buf;
			continue;
		}
		if (flg & 0x80) {
			if (p + 4 - buf > nbyte) {
				return 0;
			}
			break;
		}
		if (flg & 0x08) {
			if (p[7] & 0x40) {
				if (p + 7 - buf > nbyte) {
					return 0;
				}
				break;
			}
			return 0;
		}
		return 0;
	}
	return 1;
}

// Whether the B picture at `buf` codes nothing (every macroblock skipped or an uncoded interpolated
// block with zero vectors).
Sint32 MPV_IsEmptyBpic(Sint8 *buf, Sint32 nbyte, Sint32 nmb)
{
	Sint32 bitpos;
	Uint32 *ptr;
	Uint32 bbuf;
	Uint32 nbuf;
	Sint32 cnt;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 pos;
	Sint8 *q;

	MPVEMP_INIT(buf);
	MPVEMP_GET32(val);
	if (val != 0x101) {
		return 0;
	}
	MPVEMP_GET(val, 5);
	MPVEMP_GET1(val);
	if (val != 0) {
		return 0;
	}
	MPVEMP_GET1(val);
	if (val == 0) {
		return 0;
	}
	/* macroblock_type: "01011x" forward/backward not coded (5 bits) or "001011" (6 bits) */
	MPVEMP_PEEK(val, 6);
	switch (val) {
	case 0x16:
	case 0x17:
		MPVEMP_SKIP(5);
		break;
	case 0x0B:
		MPVEMP_SKIP(6);
		break;
	default:
		return 0;
	}
	cnt = nmb - 1;
	for (;;) {
		MPVEMP_PEEK(val, 11);
		if (val != 8) {
			break;
		}
		MPVEMP_SKIP(11);
		cnt -= 33;
		if (cnt <= 33) {
			break;
		}
	}
	if (cnt <= 0 || cnt > 33) {
		return 0;
	}
	code = mpvemp_mbai[cnt];
	len = code & 0xFF;
	MPVEMP_GET(val, len);
	if (val != code >> 8) {
		return 0;
	}
	MPVEMP_PEEK(val, 6);
	switch (val) {
	case 0x16:
	case 0x17:
		MPVEMP_SKIP(5);
		break;
	case 0x0B:
		MPVEMP_SKIP(6);
		break;
	default:
		return 0;
	}
	MPVEMP_BYTEPTR(q);
	pos = q - buf;
	if (pos > nbyte) {
		return 0;
	}
	return 1;
}
