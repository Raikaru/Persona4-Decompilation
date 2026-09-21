/* CRI Sofdec MPEG video: the bit reader used by the header/slice parsers (mpv_emp.c, mpv_hdec.c,
 * mpv_dec.c). A two-word window: `bbuf` holds the current 32 bits left-aligned, `nbuf` the next
 * word, `bitpos` the number of bits of `bbuf` already consumed, `ptr` the word after `nbuf`. */
#ifndef CRI_MPV_BIT_H
#define CRI_MPV_BIT_H

#define MPVBIT_INIT(buf)                                                                       \
	ptr = (Uint32 *)((Uint32)(buf) & ~3);                                                  \
	bitpos = ((Uint32)(buf) - (Uint32)ptr) << 3;                                           \
	bbuf = *ptr++;                                                                         \
	bbuf <<= bitpos;                                                                       \
	nbuf = *ptr++

#define MPVBIT_PEEK(val, n)                                                                    \
	val = bbuf >> (32 - (n));                                                              \
	if (bitpos > 32 - (n)) {                                                               \
		val |= nbuf >> (64 - (n) - bitpos);                                            \
	}

/* the first read consumes the whole 32-bit window (start code) */
#define MPVBIT_GET32(val)                                                                      \
	if (bitpos != 0) {                                                                     \
		val = bbuf | (nbuf >> (32 - bitpos));                                          \
		bbuf = nbuf << bitpos;                                                         \
	} else {                                                                               \
		val = bbuf;                                                                    \
		bbuf = nbuf;                                                                   \
	}                                                                                      \
	nbuf = *ptr++

#define MPVBIT_GET(val, n)                                                                     \
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

#define MPVBIT_SKIP(n)                                                                         \
	bitpos += (n);                                                                         \
	if (bitpos >= 32) {                                                                    \
		bitpos -= 32;                                                                  \
		bbuf = nbuf << bitpos;                                                         \
		nbuf = *ptr++;                                                                 \
	} else {                                                                               \
		bbuf <<= (n);                                                                  \
	}

#define MPVBIT_GET1(val)                                                                       \
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
#define MPVBIT_BYTEPTR(q)                                                                      \
	q = (Uint8 *)ptr;                                                                      \
	q += (bitpos + 7) >> 3;                                                                \
	q -= 8

/* position only (no words loaded), for skipping a header by its start code */
#define MPVBIT_SETPOS(buf)                                                                     \
	ptr = (Uint32 *)((Uint32)(buf) & ~3);                                                  \
	bitpos = ((Uint32)(buf) - (Uint32)ptr) << 3

#endif
