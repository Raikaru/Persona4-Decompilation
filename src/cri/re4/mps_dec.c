/* CRI Sofdec MPS MPEG-1 system stream header decoder (mps_dec.c): parses pack headers (SCR, mux
 * rate), system headers (rate/stream bounds, STD buffer sizes -> the system header callback) and
 * packet headers (stream id, PTS/DTS, payload length) into the MPS object; MPS_DecHd is the entry
 * the Sofdec demux driver (sfd_mps.c) calls per unit. */
#include "cri_xpt.h"
#include "mps.h"

/* system header information handed to the system header callback */
typedef struct {
	Uint8 id;                  /* 0x00 stream id */
	Uint8 scale;               /* 0x01 STD buffer bound scale */
	Uint16 bound;              /* 0x02 STD buffer size bound */
} MPSDEC_STMINF;

typedef struct {
	Sint32 rate_bound;         /* 0x00 */
	Uint8 audio_bound;         /* 0x04 */
	Uint8 fixed;               /* 0x05 */
	Uint8 csps;                /* 0x06 */
	Uint8 alock;               /* 0x07 */
	Uint8 vlock;               /* 0x08 */
	Uint8 video_bound;         /* 0x09 */
	Uint8 rsv_hi;              /* 0x0A */
	Uint8 rsv_lo;              /* 0x0B */
	Sint32 nstm;               /* 0x0C */
	MPSDEC_STMINF stm[48];     /* 0x10 */
} MPSDEC_SYSHDINF;

typedef void (*MPSDEC_SYSFN)(void *obj, MPSDEC_SYSHDINF *inf);
typedef void (*MPSDEC_PESFN)(void *obj, Uint8 stmid);

/* bit reader: a 32-bit window `cur` (already shifted so that the next bit is bit 31), the next word
 * `nxt`, the read position `pos` inside cur and the word pointer */
#define BS_INIT(adr)                                            \
	p = (Uint32 *)((Uint32)(adr) & ~3);                     \
	pos = ((Uint32)(adr) - (Uint32)p) * 8;                  \
	cur = p[0] << pos;                                      \
	nxt = p[1];                                             \
	p += 2

#define BS_GET(n, val)                                          \
	if (pos >= 32 - (n)) {                                  \
		pos -= 32 - (n);                                \
		if (pos != 0) {                                 \
			cur |= nxt >> ((n) - pos);              \
			val = cur >> (32 - (n));                \
			cur = nxt << pos;                       \
		} else {                                        \
			val = cur >> (32 - (n));                \
			cur = nxt;                              \
		}                                               \
		nxt = *p++;                                     \
	} else {                                                \
		val = cur >> (32 - (n));                        \
		cur <<= (n);                                    \
		pos += (n);                                     \
	}

/* the last field of a header: nothing but the value is needed (the compiler drops the dead state
 * updates of BS_GET differently: the original recomputes `pos - 10` into r0 twice) */
#define BS_GET_LAST(n, val)                                     \
	if (pos >= 32 - (n)) {                                  \
		if (pos - (32 - (n)) != 0) {                    \
			cur |= nxt >> ((n) - (pos - (32 - (n))));  \
			val = cur >> (32 - (n));                \
		} else {                                        \
			val = cur >> (32 - (n));                \
		}                                               \
	} else {                                                \
		val = cur >> (32 - (n));                        \
	}

/* the 2-bit read at the start of the pack header: the original has the wrap shifts as the
 * constant 1 (pos can only be 31 there) */
#define BS_GET2_FIRST(val)                                      \
	if (pos >= 30) {                                        \
		pos -= 30;                                      \
		if (pos != 0) {                                 \
			cur |= nxt >> 1;                        \
			val = cur >> 30;                        \
			cur = nxt << 1;                         \
		} else {                                        \
			val = cur >> 30;                        \
			cur = nxt;                              \
		}                                               \
		nxt = *p++;                                     \
	} else {                                                \
		val = cur >> 30;                                \
		cur <<= 2;                                      \
		pos += 2;                                       \
	}

/* a full word: the read always spans into nxt */
#define BS_GET32(val)                                           \
	if (pos != 0) {                                         \
		val = cur | (nxt >> (32 - pos));                \
		cur = nxt << pos;                               \
	} else {                                                \
		val = cur;                                      \
		cur = nxt;                                      \
	}                                                       \
	nxt = *p++;

#define BS_SHOW1(val) val = cur >> 31

#define BS_GET1(val)                                            \
	val = cur >> 31;                                        \
	if (pos == 31) {                                        \
		cur = nxt;                                      \
		nxt = *p++;                                     \
		pos = 0;                                        \
	} else {                                                \
		cur <<= 1;                                      \
		pos++;                                          \
	}

#define BS_SKIP(n)                                              \
	pos += (n);                                             \
	if (pos >= 32) {                                        \
		pos -= 32;                                      \
		cur = nxt << pos;                               \
		nxt = *p++;                                     \
	} else {                                                \
		cur <<= (n);                                    \
	}

#define BS_SHOW(n, val)                                         \
	val = cur >> (32 - (n));                                \
	if (pos > 32 - (n)) {                                   \
		val |= nxt >> (64 - (n) - pos);                 \
	}

/* 33-bit time stamp from its three fields */
#define BS_TIMESTAMP(hi, mid, lo) (((Sint64)(hi) << 30) | ((Sint64)(mid) << 15) | (Sint64)(lo))

/* packet header: adr points at the 00 00 01 start code, hdrlen receives the header length,
 * mode 2 is MPEG-1 (16-bit packet length) */
void mpsdec_DecPketHd(MPS mps, Uint8 *adr, Sint32 *hdrlen, Sint32 mode)
{
	Uint32 cur;
	Sint32 pos;
	Uint32 nxt;
	Uint32 *p;
	Sint32 stmid;
	Sint32 type;
	Sint32 idx;
	Uint32 v;
	Sint32 scale;
	Uint32 size;
	Uint32 hi;
	Uint32 mid;
	Uint32 lo;
	Sint32 len;
	Uint8 *end;

	BS_INIT(adr + 3);
	BS_GET(8, stmid);
	mps->pkethd.raw[MPS_PKT_STMID] = stmid;
	if (stmid >= 0xE0 && stmid <= 0xEF) {
		type = 1;
		idx = stmid - 0xE0;
	} else if (stmid >= 0xC0 && stmid <= 0xDF) {
		type = 0;
		idx = stmid - 0xC0;
	} else if (stmid == 0xBD) {
		type = 2;
		idx = 1;
	} else if (stmid == 0xBF) {
		type = 2;
		idx = 2;
	} else if (stmid == 0xBE) {
		type = 3;
		idx = 0;
	} else {
		type = 4;
		idx = 0;
	}
	mps->pkethd.raw[MPS_PKT_TYPE] = type;
	mps->pkethd.raw[MPS_PKT_IDX] = idx;
	if (mode == 2) {
		BS_GET(16, mps->pkethd.raw[MPS_PKT_LEN]);
		len = 6;
	} else {
		BS_GET32(mps->pkethd.raw[MPS_PKT_LEN]);
		len = 8;
	}
	if (stmid == 0xBF || stmid == 0xBE) {
		*hdrlen = len;
		mps->pkethd.raw[MPS_PKT_PAYLOAD] = mps->pkethd.raw[MPS_PKT_LEN];
		return;
	}
	for (;;) {
		BS_SHOW(8, v);
		if (v != 0xFF) {
			break;
		}
		BS_SKIP(8);
	}
	BS_SHOW(2, v);
	if (v == 1) {
		BS_SKIP(2);
		BS_GET1(scale);
		BS_GET(13, size);
		size <<= 7;
		if (scale) {
			size <<= 3;
		}
		mps->pkethd.raw[MPS_PKT_STDBUF] = size;
	}
	BS_SHOW(4, v);
	if (v == 2) {
		BS_SKIP(4);
		BS_GET(3, hi);
		BS_SKIP(1);
		BS_GET(15, mid);
		BS_SKIP(1);
		BS_GET(15, lo);
		BS_SKIP(1);
		mps->pkethd.pts = BS_TIMESTAMP(hi, mid, lo);
		mps->pkethd.dts = -1;
	} else if (v == 3) {
		BS_SKIP(4);
		BS_GET(3, hi);
		BS_SKIP(1);
		BS_GET(15, mid);
		BS_SKIP(1);
		BS_GET(15, lo);
		BS_SKIP(1);
		mps->pkethd.pts = BS_TIMESTAMP(hi, mid, lo);
		BS_SKIP(4);
		BS_GET(3, hi);
		BS_SKIP(1);
		BS_GET(15, mid);
		BS_SKIP(1);
		BS_GET(15, lo);
		BS_SKIP(1);
		mps->pkethd.dts = BS_TIMESTAMP(hi, mid, lo);
	} else {
		BS_SKIP(8);
		mps->pkethd.pts = -1;
		mps->pkethd.dts = -1;
	}
	end = (Uint8 *)(p - 2) + ((pos + 7) >> 3);
	*hdrlen = end - adr;
	mps->pkethd.raw[MPS_PKT_PAYLOAD] = mps->pkethd.raw[MPS_PKT_LEN] + len - *hdrlen;
}

/* system header: adr points at the 00 00 01 BB start code */
void mpsdec_DecSysHd(MPS mps, Uint8 *adr, Sint32 *hdrlen)
{
	MPSDEC_SYSHDINF inf;
	Uint32 cur;
	Sint32 pos;
	Uint32 nxt;
	Uint32 *p;
	Uint32 v;
	Uint32 rsv;
	Uint32 id;
	Uint32 scale;
	Uint32 bound;
	Uint8 *end;

	BS_INIT(adr + 4);
	BS_GET(16, mps->last_syshd.raw[0]);
	BS_SKIP(1);
	BS_GET(22, mps->last_syshd.raw[1]);
	BS_SKIP(1);
	BS_GET(6, mps->last_syshd.raw[2]);
	BS_GET1(mps->last_syshd.raw[4]);
	BS_GET1(mps->last_syshd.raw[5]);
	BS_GET1(mps->last_syshd.raw[6]);
	BS_GET1(mps->last_syshd.raw[7]);
	BS_SKIP(1);
	BS_GET(5, mps->last_syshd.raw[3]);
	BS_GET(8, rsv);
	inf.nstm = 0;
	for (;;) {
		BS_SHOW1(v);
		if (v == 0) {
			break;
		}
		BS_GET(8, id);
		BS_SKIP(2);
		BS_GET1(scale);
		BS_GET(13, bound);
		inf.stm[inf.nstm].id = id;
		inf.stm[inf.nstm].scale = scale;
		inf.stm[inf.nstm].bound = bound;
		inf.nstm++;
	}
	end = (Uint8 *)(p - 2) + ((pos + 7) >> 3);
	*hdrlen = end - adr;
	if ((Sint32)MPS_CheckDelim(end) == 0 && MPS_CheckDelim(end + 1) == MPS_DELIM_PKET) {
		(*hdrlen)++;
	}
	if (mps->sysfn != NULL) {
		inf.rate_bound = mps->last_syshd.raw[1];
		inf.audio_bound = mps->last_syshd.raw[2];
		inf.fixed = mps->last_syshd.raw[4];
		inf.csps = mps->last_syshd.raw[5];
		inf.alock = mps->last_syshd.raw[6];
		inf.vlock = mps->last_syshd.raw[7];
		inf.video_bound = mps->last_syshd.raw[3];
		inf.rsv_hi = (rsv >> 7) & 1;
		inf.rsv_lo = rsv & 0x7F;
		((MPSDEC_SYSFN)mps->sysfn)(mps->sysobj, &inf);
	}
}

/* pack header: adr points at the 00 00 01 BA start code; MPEG-1 packs are 12 bytes. The reader
 * init is written out: `cur = p[0]; ... cur <<= pos;` loads p[0] straight into cur's register and
 * shifts in place (the BS_INIT macro's `cur = p[0] << pos` goes through r0), which is the target's
 * shape here (the other decoders use the macro); with it the declaration order p, pos, cur, nxt
 * gives the target's p r4 (adr's register, dead after the init) / nxt r8. */
void mpsdec_DecPackHd(MPS mps, Uint8 *adr, Sint32 *hdrlen)
{
	Uint32 *p;
	Sint32 pos;
	Uint32 cur;
	Uint32 nxt;
	Uint32 ver;
	Uint32 hi;
	Uint32 mid;
	Uint32 lo;
	Uint32 rate;

	p = (Uint32 *)((Uint32)(adr + 4) & ~3);
	pos = ((Uint32)(adr + 4) - (Uint32)p) * 8;
	cur = p[0];
	nxt = p[1];
	cur <<= pos;
	p += 2;
	BS_GET2_FIRST(ver);
	BS_SKIP(2);
	BS_GET(3, hi);
	BS_SKIP(1);
	BS_GET(15, mid);
	BS_SKIP(1);
	BS_GET(15, lo);
	BS_SKIP(1);
	BS_SKIP(1);
	BS_GET_LAST(22, rate);
	mps->packhd.scr = BS_TIMESTAMP(hi, mid, lo);
	mps->packhd.rsv = ver == 0;
	mps->packhd.mux_rate = rate;
	*hdrlen = 12;
}

/* decode the headers at the start of a buffer; used / flags accumulate the consumed bytes and the
 * start codes seen */
Sint32 MPSDEC_DecHdMpeg1(MPS mps, Uint8 *adr, Sint32 len, Sint32 *used, Sint32 *flags)
{
	Sint32 hdrlen;
	Sint32 cont;
	Uint32 code;
	Sint32 idx;

	while (len >= 4) {
		hdrlen = cont = 0;
		code = MPS_CheckDelim(adr);
		switch (code) {
		case MPS_DELIM_PACK:
			mpsdec_DecPackHd(mps, adr, &hdrlen);
			cont = 1;
			break;
		case MPS_DELIM_SYSHD:
			mpsdec_DecSysHd(mps, adr, &hdrlen);
			cont = 1;
			break;
		case MPS_DELIM_PKET:
			mpsdec_DecPketHd(mps, adr, &hdrlen, mps->x10);
			if (mps->pesfn != NULL) {
				((MPSDEC_PESFN)mps->pesfn)(mps->pesobj, (Uint8)mps->pkethd.raw[MPS_PKT_STMID]);
			}
			break;
		case MPS_DELIM_END:
			break;
		default:
			break;
		}
		*flags |= code;
		adr += hdrlen;
		len -= hdrlen;
		*used += hdrlen;
		if (cont == 0) {
			break;
		}
	}
	if (*flags & MPS_DELIM_SYSHD) {
		if (mps->last_syshd.raw[2] != 0) {
			idx = 0;
		} else if (mps->last_syshd.raw[3] != 0) {
			idx = 1;
		} else {
			idx = 2;
		}
		mps->syshd[idx] = mps->last_syshd;
	}
	return 0;
}

// Decodes the pack / system / packet header at `adr` through the handle's header decoder
// (MPSDEC_DecHdMpeg1): *used = header bytes consumed, *flags = what was found; the payload follows.
// Error 0xFF020301 for a bad handle.
// FUN_00501730
Sint32 MPS_DecHd(MPS mps, Uint8 *adr, Sint32 len, Sint32 *used, Sint32 *flags)
{
	*used = 0;
	*flags = 0;
	if (MPSLIB_CheckHn(mps) != 0) {
		return MPSLIB_SetErr(NULL, 0xFF020301);
	}
	return mps->dechd_func(mps, adr, len, used, flags);
}

// Installs the PES (packet header) callback; unused by the Sofdec driver.
// FUN_005016E0
void MPS_SetPesFn(MPS mps, void *fn, void *obj)
{
	if (MPSLIB_CheckHn(mps) == 0) {
		mps->pesfn = fn;
		mps->pesobj = obj;
	}
}

// Installs the program stream map callback; unused.
// FUN_00501690
void MPS_SetPsMapFn(MPS mps, void *fn, void *obj)
{
	if (MPSLIB_CheckHn(mps) == 0) {
		mps->psmapfn = fn;
		mps->psmapobj = obj;
	}
}

// Installs the system header callback (fn(obj, MPSDEC_SYSINF)); the SFD driver passes the user's
// cond 0x3B/0x3C hook.
// FUN_00501640
void MPS_SetSystemFn(MPS mps, void *fn, void *obj)
{
	if (MPSLIB_CheckHn(mps) == 0) {
		mps->sysfn = fn;
		mps->sysobj = obj;
	}
}

/* the original .data holds one zero-initialised 8-byte object */
static Sint32 mpsdec_rsv[2] = {0, 0};

/* dead */
Sint32 *MPSDEC_GetRsv(void)
{
	return mpsdec_rsv;
}

// Nothing to release.
void MPSDEC_Finish(void)
{
}

// Nothing to initialise.
void MPSDEC_Init(void)
{
}
