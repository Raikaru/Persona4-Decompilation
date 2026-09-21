/* CRI ADXB: basic ADX/WAV/AIFF/AU/AHX/SPSD block decoder object (adx_bsc.c, adx_b*.c).
 * Field names/offsets reconstructed from the asm; unknown fields are padded. */
#ifndef CRI_ADX_B_H
#define CRI_ADX_B_H

#include "cri_xpt.h"
#include "sj.h"

typedef struct ADXPD_OBJ *ADXPD;

/* ADXB_OBJ.stat */
#define ADXB_STAT_STOP 0
#define ADXB_STAT_DECODE 1
#define ADXB_STAT_WRITE 2
#define ADXB_STAT_DONE 3

/* format ids stored in fmt / decoded by ADXB_DecodeHeader */
#define ADXB_FMT_ADX 0
#define ADXB_FMT_AHX 1
#define ADXB_FMT_PCM16 2
#define ADXB_FMT_PCM8 3
#define ADXB_FMT_SPSD 4

typedef struct {
	Sint16 used;                                             /* 0x00 */
	Sint16 x02;                                              /* 0x02 */
	Sint32 stat;                                             /* 0x04 */
	ADXPD pd;                                                /* 0x08 */
	Sint8 x0c;                                               /* 0x0C */
	Sint8 bps;                                               /* 0x0D bits per sample */
	Sint8 nch;                                               /* 0x0E */
	Sint8 x0f;                                               /* 0x0F */
	Sint32 fmt;                                              /* 0x10 */
	Sint32 sfreq;                                            /* 0x14 */
	Sint32 total_nsmpl;                                      /* 0x18 */
	Sint16 x1c;                                              /* 0x1C */
	Uint8 pad1e[2];
	Sint32 x20;                                              /* 0x20 */
	Sint16 x24;                                              /* 0x24 */
	Sint16 x26;                                              /* 0x26 */
	Sint32 x28;                                              /* 0x28 */
	Sint32 x2c;                                              /* 0x2C */
	Sint32 x30;                                              /* 0x30 */
	Sint32 x34;                                              /* 0x34 */
	Sint32 x38;                                              /* 0x38 */
	Sint32 x3c;                                              /* 0x3C */
	Sint32 x40;                                              /* 0x40 */
	Sint32 x44;                                              /* 0x44 */
	Sint16 *inbuf;                                           /* 0x48 */
	Sint32 inbuf_nsmpl;                                      /* 0x4C */
	Sint32 out_nch;                                          /* 0x50 */
	Sint32 x54;                                              /* 0x54 */
	Sint32 out_fmt;                                          /* 0x58 */
	Sint16 *pcmbuf;                                          /* 0x5C */
	Sint32 pcmbuf_nsmpl;                                     /* 0x60 */
	Sint32 pcmbuf_chofst;                                    /* 0x64 */
	Sint32 wr_pos;                                           /* 0x68 */
	Sint32 wr_nsmpl;                                         /* 0x6C */
	Sint32 wr_x70;                                           /* 0x70 */
	Sint32 x74;                                              /* 0x74 */
	void (*getwr_func)(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *x70); /* 0x78 */
	void *getwr_obj;                                         /* 0x7C */
	void (*addwr_func)(void *obj, Sint32 nbyte, Sint32 nsmpl); /* 0x80 */
	void *addwr_obj;                                         /* 0x84 */
	Sint32 x88;                                              /* 0x88 */
	Sint32 x8c;                                              /* 0x8C */
	Sint32 dec_nsmpl;                                        /* 0x90 */
	Sint32 dec_nbyte;                                        /* 0x94 */
	Sint16 x98;                                              /* 0x98 */
	Sint16 x9a;                                              /* 0x9A */
	Sint16 x9c;                                              /* 0x9C */
	Uint8 pad9e[2];
	Sint16 key[3];                                           /* 0xA0 encryption keys (k0, km, ka) */
	Sint16 extprm[3];                                        /* 0xA6 decoder extension parameters */
	Sint16 dly[2][2];                                        /* 0xAC decoder history (snapshot) */
	void *ahx;                                               /* 0xB4 */
	Sint32 nsmpl;                                            /* 0xB8 */
	Sint32 nsmpl96;                                          /* 0xBC */
	Sint32 ainf_len;                                         /* 0xC0 */
	Uint8 ainf[16];                                          /* 0xC4 */
	Sint16 def_outvol;                                       /* 0xD4 */
	Sint16 def_pan[2];                                       /* 0xD6 */
	Uint8 padda[2];
	void *xdc;                                               /* 0xDC (adx_sjd: pl2setsfreqfunc called when set) */
	Uint8 pade0[8];
	Sint32 cb_nbyte;                                         /* 0xE8 dec_nbyte at the last callback */
	Sint32 xec;                                              /* 0xEC */
	void (*cb_func)(void *obj, Sint32 nbyte, Sint32 nsmpl);  /* 0xF0 decode callback */
	void *cb_obj;                                            /* 0xF4 */
} ADXB_OBJ;

#define ADXB_MAX_OBJ 16

typedef ADXB_OBJ *ADXB;

Sint32 ADXPD_GetStat(ADXPD pd);

Sint32 ADXB_CheckSpsd(void *buf);
void ADXB_ExecOneSpsd(ADXB adxb);
Sint32 ADXB_DecodeHeaderSpsd(ADXB adxb, void *buf, Sint32 bsize);
Sint32 ADX_DecodeInfoSpsd(Uint8 *buf, Sint32 bsize, Sint16 *hdrlen, Sint8 *x0c, Sint8 *bps, Sint8 *x0f,
			  Sint8 *nch, Sint32 *sfreq, Sint32 *nsmpl, Sint32 *fmt, Sint16 *x9c);

#endif
