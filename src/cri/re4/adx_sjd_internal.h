#ifndef CRI_ADX_SJD_INTERNAL_H
#define CRI_ADX_SJD_INTERNAL_H

#include "adx_b.h"

#define ADXSJD_MAX_NCH 2

typedef struct {
	Sint8 used;                /* 0x00 */
	Sint8 stat;                /* 0x01 */
	Sint8 nch;                 /* 0x02 */
	Sint8 spsd;                /* 0x03 SPSD stream: the input must hold data before a block starts */
	ADXB adxb;                 /* 0x04 */
	SJ sji;                    /* 0x08 input */
	SJ sjo[ADXSJD_MAX_NCH];    /* 0x0C outputs */
	SJCK inck;                 /* 0x14 input chunk handed to the decoder */
	SJCK outck[ADXSJD_MAX_NCH]; /* 0x1C output chunks being written */
	Sint32 dec_nsmpl;          /* 0x2C samples decoded */
	Sint32 dec_nbyte;          /* 0x30 input bytes consumed */
	Sint32 decpos;             /* 0x34 decode position in samples */
	Sint32 maxdecsmpl;         /* 0x38 */
	Sint32 trap_nsmpl;         /* 0x3C (-1: none) */
	Sint32 trap_cnt;           /* 0x40 */
	Sint32 trap_dtlen;         /* 0x44 */
	void (*trapfn)(void *obj); /* 0x48 */
	void *trapobj;             /* 0x4C */
	void (*outfn)(void *obj, Sint32 ch, Uint8 *data, Sint32 len); /* 0x50 */
	void *outobj;              /* 0x54 */
	Uint8 spsdinf[0x40];       /* 0x58 SPSD header copy */
	Sint32 hdrlen;             /* 0x98 */
	Sint32 lnksw;              /* 0x9C linked (concatenated) files */
	Sint32 pad_nsmpl;          /* 0xA0 silence samples to insert before the output */
	Sint32 skip_nsmpl;         /* 0xA4 output samples to discard */
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

Sint32 ADXSJD_GetSfreq(ADXSJD sjd);
Sint32 ADXSJD_GetNumChan(ADXSJD sjd);
Sint32 ADXSJD_GetHdrLen(ADXSJD sjd);
Sint32 ADXSJD_GetFmtBps(ADXSJD sjd);

#endif
