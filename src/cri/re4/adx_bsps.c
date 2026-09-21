/* CRI ADXB SPSD (Dreamcast sound data) support (adx_bsps.c): magic test, header parse and the
 * per-tick 16-bit PCM copy step into the ADXB PCM ring. Selected by ADXB_DecodeHeader /
 * ADXB_ExecHndl for type 2; the ADXSJD keeps a copy of the header for SPSD streams. */
#include "cri_xpt.h"
#include "adx_b.h"
#include <string.h>

// "SPSD" magic test.
// FUN_004C4B80
Sint32 ADXB_CheckSpsd(void *buf)
{
	return memcmp(buf, "SPSD", 4) == 0;
}

// Decode step for SPSD 16-bit PCM: copies (deinterleaving stereo) as many samples as fit the write
// window into the PCM ring; reports bytes consumed / samples produced.
void ADXB_ExecOneSpsd(ADXB adxb)
{
	Uint16 *inbuf;
	Uint16 *out0;
	Uint16 *out1;
	Sint32 i;
	Sint32 n;

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
				out0[i] = inbuf[i * 2];
				out1[i] = inbuf[i * 2 + 1];
			}
		} else {
			for (i = 0; i < n; i++) {
				out0[i] = inbuf[i];
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

// Container-specific header decode for ADXB_DecodeHeader: fills the handle, clears the loop info,
// type ADXB_TYPE_SPSD; returns the header length.
// FUN_004C4910
Sint32 ADXB_DecodeHeaderSpsd(ADXB adxb, void *buf, Sint32 bsize)
{
	Sint16 hdrlen;

	adxb->x02 = 1;
	if (ADX_DecodeInfoSpsd(buf, bsize, &hdrlen, &adxb->x0c, &adxb->bps, &adxb->x0f, &adxb->nch,
			       &adxb->sfreq, &adxb->total_nsmpl, &adxb->fmt, &adxb->x9c) < 0) {
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
	adxb->x98 = 2;
	return hdrlen;
}

// Parses the SPSD header (header length = byte 7 << 4, channels from byte 9, rate at 0x2A, codec at
// byte 8); the trailing overrides force 16-bit PCM in 2-byte frames whatever the codec byte says.
Sint32 ADX_DecodeInfoSpsd(Uint8 *buf, Sint32 bsize, Sint16 *hdrlen, Sint8 *x0c, Sint8 *bps, Sint8 *x0f,
			  Sint8 *nch, Sint32 *sfreq, Sint32 *nsmpl, Sint32 *fmt, Sint16 *x9c)
{
	*hdrlen = buf[7] << 4;
	*nch = (buf[9] & 3) + 1;
	*sfreq = *(Uint16 *)(buf + 0x2a);
	switch (buf[8]) {
	case 0:
		*bps = 16;
		*x0f = *nch * 2;
		*fmt = 1;
		*nsmpl = *(Sint32 *)(buf + 0xc) / 2;
		*x9c = 0;
		break;
	case 1:
		*bps = 8;
		*x0f = *nch;
		*fmt = 1;
		*nsmpl = *(Sint32 *)(buf + 0xc);
		*x9c = 1;
		break;
	case 2:
	case 3:
		*bps = 4;
		*x0f = *nch;
		*fmt = 2;
		*nsmpl = *(Sint32 *)(buf + 0xc) * 2;
		*x9c = 2;
		break;
	}
	*x0f = 2;
	*fmt = 1;
	*nsmpl = *(Sint32 *)(buf + 0xc) / 2;
	*bps = 16;
	*x0c = -1;
	return 0;
}
