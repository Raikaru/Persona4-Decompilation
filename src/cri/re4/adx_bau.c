/* CRI ADXB Sun AU (.snd) support (adx_bau.c): magic test, header parse and the per-tick decode
 * steps for u-law (table expansion), 8-bit and 16-bit linear PCM into the ADXB PCM ring. Selected by
 * ADXB_DecodeHeader / ADXB_ExecHndl for type 4. */
#include "cri_xpt.h"
#include "adx_b.h"
#include <string.h>

#define LE16(p) (((Uint16)(p)[1] << 8) | (p)[0])
#define LE32(p) ((Uint32)(p)[0] | ((Uint32)(p)[1] << 8) | ((Uint32)(p)[2] << 16) | ((Uint32)(p)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

#define AU_MAGIC1 0x0064732E /* ".sd" read little-endian */
#define AU_MAGIC2 0x646E732E /* ".snd" */

#define AU_ENC_ULAW 1
#define AU_ENC_PCM8 2
#define AU_ENC_PCM16 3

void ADXB_ExecOneAuUlaw(ADXB adxb);
void ADXB_ExecOneAu8(ADXB adxb);
void ADXB_ExecOneAu16(ADXB adxb);
Uint8 *AU_GetInfo(Uint8 *buf, Sint32 bsize, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *type);

Sint16 ulaw_exp_table[256] = {
	-32124, -31100, -30076, -29052, -28028, -27004, -25980, -24956,
	-23932, -22908, -21884, -20860, -19836, -18812, -17788, -16764,
	-15996, -15484, -14972, -14460, -13948, -13436, -12924, -12412,
	-11900, -11388, -10876, -10364, -9852, -9340, -8828, -8316,
	-7932, -7676, -7420, -7164, -6908, -6652, -6396, -6140,
	-5884, -5628, -5372, -5116, -4860, -4604, -4348, -4092,
	-3900, -3772, -3644, -3516, -3388, -3260, -3132, -3004,
	-2876, -2748, -2620, -2492, -2364, -2236, -2108, -1980,
	-1884, -1820, -1756, -1692, -1628, -1564, -1500, -1436,
	-1372, -1308, -1244, -1180, -1116, -1052, -988, -924,
	-876, -844, -812, -780, -748, -716, -684, -652,
	-620, -588, -556, -524, -492, -460, -428, -396,
	-372, -356, -340, -324, -308, -292, -276, -260,
	-244, -228, -212, -196, -180, -164, -148, -132,
	-120, -112, -104, -96, -88, -80, -72, -64,
	-56, -48, -40, -32, -24, -16, -8, 0,
	32124, 31100, 30076, 29052, 28028, 27004, 25980, 24956,
	23932, 22908, 21884, 20860, 19836, 18812, 17788, 16764,
	15996, 15484, 14972, 14460, 13948, 13436, 12924, 12412,
	11900, 11388, 10876, 10364, 9852, 9340, 8828, 8316,
	7932, 7676, 7420, 7164, 6908, 6652, 6396, 6140,
	5884, 5628, 5372, 5116, 4860, 4604, 4348, 4092,
	3900, 3772, 3644, 3516, 3388, 3260, 3132, 3004,
	2876, 2748, 2620, 2492, 2364, 2236, 2108, 1980,
	1884, 1820, 1756, 1692, 1628, 1564, 1500, 1436,
	1372, 1308, 1244, 1180, 1116, 1052, 988, 924,
	876, 844, 812, 780, 748, 716, 684, 652,
	620, 588, 556, 524, 492, 460, 428, 396,
	372, 356, 340, 324, 308, 292, 276, 260,
	244, 228, 212, 196, 180, 164, 148, 132,
	120, 112, 104, 96, 88, 80, 72, 64,
	56, 48, 40, 32, 24, 16, 8, 0,
};

// Dispatches on the encoding recorded at header time (x9c 2 u-law, 1 8-bit, else 16-bit PCM).
void ADXB_ExecOneAu(ADXB adxb)
{
	if (adxb->x9c == 2) {
		ADXB_ExecOneAuUlaw(adxb);
	} else if (adxb->x9c == 1) {
		ADXB_ExecOneAu8(adxb);
	} else {
		ADXB_ExecOneAu16(adxb);
	}
}

// Decode step for u-law AU: expands each byte through the u-law table into the PCM ring
// (deinterleaving stereo), reports bytes consumed / samples produced.
void ADXB_ExecOneAuUlaw(ADXB adxb)
{
	Uint8 *inbuf;
	Sint16 *out0;
	Sint16 *out1;
	Sint32 i;
	Sint32 n;

	inbuf = (Uint8 *)adxb->inbuf;
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
				out0[i] = ulaw_exp_table[inbuf[i * 2]];
				out1[i] = ulaw_exp_table[inbuf[i * 2 + 1]];
			}
		} else {
			for (i = 0; i < n; i++) {
				out0[i] = ulaw_exp_table[inbuf[i]];
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

// Decode step for 8-bit linear AU: samples scaled to 16 bits into the PCM ring.
void ADXB_ExecOneAu8(ADXB adxb)
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

/* The 2ch swap goes through a `Uint16` temporary: the unroller's 15th copy is then `extrwi 8,16`
 * like the original (the direct `inbuf[i * 2] >> 8` form gives `srawi 8` for all 16 copies). */
void ADXB_ExecOneAu16(ADXB adxb)
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

// Reads the AU header (AU_GetInfo) into the handle: encoding, rate, channels, bits, sample count;
// returns the data offset as the header length.
static Sint32 adxb_DecodeInfoAu(ADXB adxb, Uint8 *buf, Sint32 bsize, Sint16 *hdrlen, Sint32 *type)
{
	Sint32 sfreq;
	Sint32 nch;
	Sint32 bps;
	Sint32 nsmpl;
	Uint8 *p;

	if (bsize < 8) {
		*hdrlen = 0;
		return -1;
	}
	p = AU_GetInfo(buf, bsize, &sfreq, &nch, &bps, &nsmpl, type);
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
// type ADXB_TYPE_AU; returns the header length (0 on failure).
Sint32 ADXB_DecodeHeaderAu(ADXB adxb, void *buf, Sint32 bsize)
{
	Sint16 hdrlen;
	Sint32 type;

	adxb->x02 = 1;
	if (adxb_DecodeInfoAu(adxb, buf, bsize, &hdrlen, &type) < 0) {
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
	adxb->x98 = 4;
	adxb->x9c = type;
	return hdrlen;
}

// ".snd" / ".sd" magic test.
// FUN_004C29B8
Sint32 ADXB_CheckAu(Uint8 *buf)
{
	if (memcmp(buf, ".snd", 4) == 0 || memcmp(buf, ".sd", 4) == 0) {
		return 1;
	}
	return 0;
}

// Parses the big-endian AU header: encoding (1 u-law, 2 PCM8, 3 PCM16 -> *type 2/1/0 and bits),
// rate, channels and sample count from the data size; returns the start of the sample data or NULL.
Uint8 *AU_GetInfo(Uint8 *buf, Sint32 bsize, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *type)
{
	Uint32 magic;
	Sint32 hdrsize;
	Uint32 dsize;
	Uint32 enc;

	magic = LE32(buf);
	if (magic != AU_MAGIC1 && magic != AU_MAGIC2) {
		return NULL;
	}
	hdrsize = LE32(buf + 4);
	hdrsize = SWAP32(hdrsize);
	if (hdrsize > bsize) {
		return NULL;
	}
	dsize = LE32(buf + 8);
	enc = LE32(buf + 0xC);
	enc = SWAP32(enc);
	dsize = SWAP32(dsize);
	switch (enc) {
	case AU_ENC_ULAW:
		*type = 2;
		*bps = 8;
		break;
	case AU_ENC_PCM8:
		*type = 1;
		*bps = 8;
		break;
	case AU_ENC_PCM16:
		*type = 0;
		*bps = 16;
		break;
	default:
		return NULL;
	}
	*sfreq = LE32(buf + 0x10);
	*sfreq = SWAP32(*sfreq);
	*nch = LE32(buf + 0x14);
	*nch = SWAP32(*nch);
	if (*type == 2) {
		*nsmpl = (Sint32)dsize / *nch;
	} else if (*type == 1) {
		*nsmpl = (Sint32)dsize / *nch;
	} else if (*type == 0) {
		*nsmpl = ((Sint32)dsize / 2) / *nch;
	} else {
		*nsmpl = 0x7FFF0000;
	}
	return buf + hdrsize;
}
