/* CRI ADXT (ADX talk: stream playback handle) internals shared by the adx_*.c units.
 * ADXT_OBJ is 0xC0 bytes (adxt_obj[16] = 0xC00); only the fields seen so far are named. */
#ifndef CRI_ADX_T_H
#define CRI_ADX_T_H

#include "cri_xpt.h"
#include "sj.h"

#define ADXT_MAX_OBJ 16
#define ADXT_MAX_NCH 8

/* ADXT_OBJ.stat (internal) */
#define ADXT_ISTAT_STOP 0
#define ADXT_ISTAT_DECINFO 1
#define ADXT_ISTAT_PREP 2
#define ADXT_ISTAT_PLAYING 3
#define ADXT_ISTAT_PLAYEND_WAIT 4
#define ADXT_ISTAT_PLAYEND 5
#define ADXT_ISTAT_ERROR 6

typedef struct {
	Sint8 used;           /* 0x00 */
	Sint8 stat;           /* 0x01 ADXT_ISTAT_* */
	Sint8 mode;           /* 0x02 input kind (0/1: file stream, 2: memory, 3: stream joint) */
	Sint8 maxnch;         /* 0x03 */
	void *sjd;            /* 0x04 ADXSJD decoder */
	void *stm;            /* 0x08 ADXSTM stream controller */
	void *rna;            /* 0x0C ADXRNA renderer (SFADXT_Create copies it into SFAOAP.x00) */
	SJ sjf;               /* 0x10 file stream joint */
	SJ sji;               /* 0x14 decoder input stream joint */
	SJ sjo[2];            /* 0x18 decoder output stream joints (one per channel) */
	Uint8 *ibuf;          /* 0x20 file stream ring buffer (ADXT_Create work layout) */
	Sint32 ibufsize;      /* 0x24 */
	Sint32 ibufxsize;     /* 0x28 */
	Uint8 *obuf;          /* 0x2C decoder output ring buffers */
	Sint32 obufsize;      /* 0x30 (samples) */
	Sint32 obufstride;    /* 0x34 (samples, including the extra area) */
	Sint32 svrfreq;       /* 0x38 server calls per second */
	Sint16 ibuf_nsct;     /* 0x3C input (file stream) buffer size in sectors */
	Sint16 reload_nsct;   /* 0x3E reload threshold in sectors (85% of the buffer) */
	Sint16 outvol;        /* 0x40 */
	Sint16 outpan[2];     /* 0x42 */
	Sint16 outbal;        /* 0x46 output balance (-15..15) */
	Sint32 maxdecsmpl;    /* 0x48 samples decoded per server call */
	Sint32 lpcnt;         /* 0x4C loops done */
	Sint32 lpendmod;      /* 0x50 loop end offset within its sector */
	Sint32 x54;
	Sint32 x58;
	Sint32 x5c;
	Sint16 errcode;       /* 0x60 */
	Sint16 x62;
	Sint32 x64;
	Sint16 x68;
	Sint16 x6a;
	Sint8 lpsw;           /* 0x6C loop switch */
	Sint8 autorcvr;       /* 0x6D automatic recovery switch */
	Sint8 x6e;
	Sint8 x6f;
	Sint8 pausesw;        /* 0x70 */
	Sint8 x71;
	Sint8 x72;            /* pause state (ADXT_Pause) */
	Sint8 x73;
	void *amp;            /* 0x74 ADXAMP */
	SJ sjx[2];            /* 0x78 extra stream joints destroyed with the handle */
	SJ sjy[2];            /* 0x80 */
	Sint32 timeofst;      /* 0x88 ADXT_SetTimeOfst */
	Sint32 lpendsct;      /* 0x8C loop end in sectors */
	Sint32 trapnsmpl;     /* 0x90 */
	void *lsc;            /* 0x94 load scheduler handle */
	Sint8 lnksw;          /* 0x98 link (concatenated file) switch */
	Uint8 pad99[0x9C - 0x99];
	Uint32 x9c;           /* 0x9C time position at the last (re)start in adxt_time_unit units */
	Sint32 startvsync;    /* 0xA0 adxt_vsync_cnt at start */
	Sint32 decsmpl;       /* 0xA4 samples decoded before the current (linked) file */
	Sint8 stmstart;       /* 0xA8 start the stream when the decoder is ready */
	Uint8 pada9[0xAC - 0xA9];
	Uint8 *wkend;         /* 0xAC end of the file stream ring buffer (ADXT_Create) */
	void *stm_fname;      /* 0xB0 pending adxt_start_stm arguments */
	void *stm_dir;        /* 0xB4 */
	Sint32 stm_ofst;      /* 0xB8 */
	Sint32 stm_nsct;      /* 0xBC */
} ADXT_OBJ;

typedef ADXT_OBJ *ADXT;

extern ADXT_OBJ adxt_obj[ADXT_MAX_OBJ];
extern const Char8 adxt_build[];
extern Sint32 adxt_init_cnt;
extern Sint32 adxt_svr_main_id;
extern Sint32 adxt_output_mono_flag;
extern Sint32 adxt_svr_fs_id;
extern Sint32 adxt_vsync_svr_flag;
extern Sint32 adxt_vsync_cnt;

void ADXT_Init(void);
void ADXT_Finish(void);
void ADXT_ExecServer(void);
void ADXT_ExecFsSvr(void);
void ADXT_DestroyAll(void);
void ADXT_SetDefSvrFreq(Sint32 freq);

#endif
