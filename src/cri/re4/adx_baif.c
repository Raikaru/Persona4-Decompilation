/* CRI ADXB AIFF support (adx_baif.c): signature test, COMM/SSND header parse and the per-tick PCM
 * copy steps for 8- and 16-bit big-endian AIFF into the ADXB PCM ring. Selected by
 * ADXB_DecodeHeader / ADXB_ExecHndl for type 3. */
#include "cri_xpt.h"
#include "adx_b.h"
#include <string.h>

#define LE16(p) (((Uint16)(p)[1] << 8) | (p)[0])
#define LE32(p) ((Uint32)(p)[0] | ((Uint32)(p)[1] << 8) | ((Uint32)(p)[2] << 16) | ((Uint32)(p)[3] << 24))
#define SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) & 0xFF) << 8))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

#define AIFF_FORM 0x4D524F46 /* "FORM" read little-endian */
#define AIFF_AIFF 0x46464941 /* "AIFF" */
#define AIFF_COMM 0x4D4D4F43 /* "COMM" */
#define AIFF_SSND 0x444E5353 /* "SSND" */

void ADXB_ExecOneAiff8(ADXB adxb);
void ADXB_ExecOneAiff16(ADXB adxb);
Uint8 *AIFF_GetInfo(Uint8 *buf, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl);

// Dispatches on the sample width recorded at header time (x9c 1 = 8-bit, else 16-bit).
// FUN_004C2678
void ADXB_ExecOneAiff(ADXB adxb)
{
	if (adxb->x9c == 1) {
		ADXB_ExecOneAiff8(adxb);
	} else {
		ADXB_ExecOneAiff16(adxb);
	}
}

// Decode step for 8-bit AIFF: copies as many samples as fit the write window into the PCM ring
// (deinterleaving stereo, scaling to 16 bits) and reports the bytes consumed / samples produced.
void ADXB_ExecOneAiff8(ADXB adxb)
{
	Sint8 *inbuf;
	Sint16 *out0;
	Sint16 *out1;
	Sint32 i;
	Sint32 n;

	inbuf = (Sint8 *)adxb->inbuf;
	if (adxb->stat == ADXB_STAT_DECODE && ADXPD_GetStat(adxb->pd) == 0) {
		adxb->getwr_func(adxb->getwr_obj, &adxb->wr_pos, &adxb->wr_nsmpl, &adxb->wr_x70);
		n = adxb->pcmbuf_nsmpl - adxb->wr_pos;
		if (n > adxb->wr_nsmpl) {
			n = adxb->wr_nsmpl;
		}
		if (n > adxb->inbuf_nsmpl) {
			n = adxb->inbuf_nsmpl;
		}
		out0 = adxb->pcmbuf + adxb->wr_pos;
		if (adxb->nch == 2) {
			out1 = adxb->pcmbuf + (adxb->pcmbuf_chofst + adxb->wr_pos);
			for (i = 0; i < n; i++) {
				out0[i] = (Uint8)inbuf[i * 2] << 8;
				out1[i] = (Uint8)inbuf[i * 2 + 1] << 8;
			}
		} else {
			for (i = 0; i < n; i++) {
				out0[i] = (Uint8)inbuf[i] << 8;
			}
		}
		adxb->dec_nsmpl = n;
		adxb->dec_nbyte = n * adxb->nch;
		adxb->stat = ADXB_STAT_WRITE;
	}
	if (adxb->stat == ADXB_STAT_WRITE) {
		adxb->addwr_func(adxb->addwr_obj, adxb->dec_nbyte, adxb->dec_nsmpl);
		adxb->stat = ADXB_STAT_DONE;
	}
}

/* the 2ch swap goes through a `Uint16` temporary (see adx_bau ADXB_ExecOneAu16) */
void ADXB_ExecOneAiff16(ADXB adxb)
{
	Uint16 *inbuf;
	Uint16 *out0;
	Uint16 *out1;
	Sint32 i;
	Sint32 n;
	Uint16 x;

	inbuf = (Uint16 *)adxb->inbuf;
	if (adxb->stat == ADXB_STAT_DECODE && ADXPD_GetStat(adxb->pd) == 0) {
		adxb->getwr_func(adxb->getwr_obj, &adxb->wr_pos, &adxb->wr_nsmpl, &adxb->wr_x70);
		n = adxb->pcmbuf_nsmpl - adxb->wr_pos;
		if (n > adxb->wr_nsmpl) {
			n = adxb->wr_nsmpl;
		}
		if (n > adxb->inbuf_nsmpl) {
			n = adxb->inbuf_nsmpl;
		}
		out0 = (Uint16 *)adxb->pcmbuf + adxb->wr_pos;
		if (adxb->nch == 2) {
			out1 = (Uint16 *)adxb->pcmbuf + (adxb->pcmbuf_chofst + adxb->wr_pos);
			for (i = 0; i < n; i++) {
				x = inbuf[i * 2];
				out0[i] = (x << 8) | (x >> 8);
				x = inbuf[i * 2 + 1];
				out1[i] = (x << 8) | (x >> 8);
			}
		} else {
			for (i = 0; i < n; i++) {
				out0[i] = (inbuf[i] >> 8) | (inbuf[i] << 8);
			}
		}
		adxb->dec_nsmpl = n;
		adxb->dec_nbyte = adxb->nch * (n * 2);
		adxb->stat = ADXB_STAT_WRITE;
	}
	if (adxb->stat == ADXB_STAT_WRITE) {
		adxb->addwr_func(adxb->addwr_obj, adxb->dec_nbyte, adxb->dec_nsmpl);
		adxb->stat = ADXB_STAT_DONE;
	}
}

// Reads the COMM/SSND chunks (AIFF_GetInfo) into the handle: rate, channels, bits, sample count,
// block size; returns the header length up to the sample data.
static Sint32 adxb_DecodeInfoAiff(ADXB adxb, Uint8 *buf, Sint32 bsize, Sint16 *hdrlen)
{
	Sint32 sfreq;
	Sint32 nch;
	Sint32 bps;
	Sint32 nsmpl;
	Uint8 *p;

	if (bsize < 0x1000) {
		*hdrlen = 0;
		return -1;
	}
	p = AIFF_GetInfo(buf, &sfreq, &nch, &bps, &nsmpl);
	if (p == NULL) {
		return -1;
	}
	*hdrlen = p - buf;
	if (*hdrlen <= 0) {
		return -1;
	}
	adxb->sfreq = sfreq;
	adxb->nch = nch;
	adxb->bps = bps;
	adxb->total_nsmpl = nsmpl;
	adxb->x0c = -1;
	adxb->x0f = (adxb->nch * adxb->bps) / 8;
	adxb->fmt = 1;
	return 0;
}

// Container-specific header decode for ADXB_DecodeHeader: fills the handle, clears the loop info,
// type ADXB_TYPE_AIFF; returns the header length (0 if the header could not be parsed).
Sint32 ADXB_DecodeHeaderAiff(ADXB adxb, void *buf, Sint32 bsize)
{
	Sint16 hdrlen;

	adxb->x02 = 1;
	if (adxb_DecodeInfoAiff(adxb, buf, bsize, &hdrlen) < 0) {
		return 0;
	}
	adxb->x1c = 0;
	adxb->x26 = 0;
	adxb->x24 = 0;
	adxb->x34 = 0;
	adxb->x30 = 0;
	adxb->x2c = 0;
	adxb->x28 = 0;
	adxb->x20 = 0;
	adxb->out_nch = adxb->nch;
	adxb->x54 = adxb->x0f;
	adxb->out_fmt = adxb->fmt;
	adxb->pcmbuf = (Sint16 *)adxb->x3c;
	adxb->pcmbuf_nsmpl = adxb->x40;
	adxb->pcmbuf_chofst = adxb->x44;
	adxb->x8c = 0;
	adxb->x88 = 0;
	adxb->x98 = 3;
	if (adxb->bps == 8) {
		adxb->x9c = 1;
	} else {
		adxb->x9c = 0;
	}
	return hdrlen;
}

// "FORM" .... "AIFF" signature test.
Sint32 ADXB_CheckAiff(Uint8 *buf)
{
	if (memcmp(buf, "FORM", 4) == 0 && memcmp(buf + 8, "AIFF", 4) == 0) {
		return 1;
	}
	return 0;
}

/* CRI pass 62: the header ckid/type are Sint32 locals compared with int constants: MWCC reads a
 * `long` compared with an `int` as an int-typed indirection, which the frontend does not propagate
 * into (the kept variable = the target's `mr r27,r30` before the last rlwimi); `end = p + cksz - 4`
 * gives the target's `subi; add`; the two 16-bit reads stored to *nch/*bps carry explicit
 * `& 0xFF` / `& 0xFFFF` masks (the `clrlslwi 16,8` + `rlwimi 0,24,31` shape), the exp/mant reads
 * do not; exp/mant are Uint16 own locals (kept: the `clrlwi r27/r28` write the variables) and
 * the `(Uint16)` cast on SWAP16's argument breaks the frontend CSE, so the 16-bit value is a
 * backend temp (coloured before the block's byte temps: r29/r30 handed out in the COMM block). */
Uint8 *AIFF_GetInfo(Uint8 *buf, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl)
{
	Uint8 *p;
	Uint8 *end;
	Uint8 *data;
	Sint32 ckid;
	Sint32 cksz;
	Sint32 type;
	Sint32 comm_flg;
	Sint32 ssnd_flg;
	Uint16 exp;
	Uint16 mant;
	Uint32 ofst;

	p = buf + 12;
	comm_flg = 0;
	ssnd_flg = 0;
	data = NULL;
	ckid = LE32(buf);
	cksz = LE32(buf + 4);
	cksz = SWAP32(cksz);
	type = LE32(buf + 8);
	if (ckid != AIFF_FORM) {
		return NULL;
	}
	if (type != AIFF_AIFF) {
		return NULL;
	}
	end = p + cksz - 4;
	while (p < end) {
		ckid = LE32(p);
		cksz = LE32(p + 4);
		cksz = SWAP32(cksz);
		p += 8;
		switch (ckid) {
		case AIFF_COMM:
			if (comm_flg != 0) {
				break;
			}
			if (cksz < 0x12) {
				return NULL;
			}
			comm_flg = 1;
			*nch = (p[0] & 0xFF) | ((p[1] & 0xFFFF) << 8);
			*nch = SWAP16(*nch);
			*nsmpl = LE32(p + 2);
			*nsmpl = SWAP32(*nsmpl);
			*bps = (p[6] & 0xFF) | ((p[7] & 0xFFFF) << 8);
			*bps = SWAP16(*bps);
			exp = SWAP16((Uint16)(p[8] | (p[9] << 8)));
			mant = SWAP16((Uint16)(p[10] | (p[11] << 8)));
			p += 0x12;
			*sfreq = (Sint32)mant >> (0x400E - exp);
			if (ssnd_flg != 0) {
				return data;
			}
			break;
		case AIFF_SSND:
			if (ssnd_flg != 0) {
				break;
			}
			ssnd_flg = 1;
			ofst = LE32(p);
			ofst = SWAP32(ofst);
			p += 4;
			data = p + ofst;
			if (comm_flg != 0) {
				return data;
			}
			break;
		default:
			p += (cksz + 1) & ~1;
			break;
		}
	}
	return data;
}
