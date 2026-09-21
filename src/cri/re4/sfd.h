/* CRI Sofdec decoder core (SFD) object layout, from the field offsets used by the DOL. */
#ifndef CRI_SFD_H
#define CRI_SFD_H

#include "cri_xpt.h"
#include "sj.h"

typedef struct SFD_OBJ *SFD;

/* user-output (usr sj) channel */
typedef struct {
	void *sj;
	void *prm;
	Sint32 rsv1;
	Sint32 rsv2;
} SFUO_CH;

typedef struct {
	Sint32 nch;
	SFUO_CH ch[3];
} SFUO;

/* audio output (auto-play) driver work (sfd_aoap.c), at SFD_OBJ + 0x3474: user callbacks */
typedef struct {
	Sint32 x00;
	Sint32 (*SetOutPan)(SFD sfd, Sint32 ch, Sint32 pan); /* 0x04 */
	Sint32 (*GetOutPan)(SFD sfd, Sint32 ch);             /* 0x08 */
	Sint32 (*SetOutVol)(SFD sfd, Sint32 vol);            /* 0x0C */
	Sint32 (*GetOutVol)(SFD sfd);                        /* 0x10 */
	void (*SetSpeed)(SFD sfd, Sint32 speed);             /* 0x14 */
	Sint32 x18;
} SFAOAP;

/* concatenated-play work (sfd_con.c), at SFD_OBJ + 0xD28 */
typedef struct {
	Uint8 pad0[0xB8];
	Sint32 tottime;            /* 0xB8 total time of the concatenated files */
	Sint32 tunit;              /* 0xBC */
	Uint8 padc0[0x150 - 0xC0];
	Sint64 scr_base;           /* 0x150 first SCR of the file (sfd_mps.c, kept in the seek work) */
	Sint64 scr_ofst;           /* 0x158 audio PTS minimum - seek work SCR (sfd_mps.c) */
	Sint32 pad160;             /* 0x160 */
	Sint32 ctime;              /* 0x164 accumulated concat time */
	Sint32 ctime_idx;          /* 0x168 */
	Sint32 ctime_que[32];      /* 0x16C */
	Sint32 tot_last;           /* 0x1EC */
	Sint32 pad1F0;
	Sint32 que_wr;             /* 0x1F4 */
	Sint32 que_rd;             /* 0x1F8 */
	Sint32 tot_que[32];        /* 0x1FC */
} SFCON;

/* timecode as the user passes it to SFD_Tc2Time (0x20 bytes) */
typedef struct {
	Sint32 type;               /* 0x00 frame rate (index into SFTIM_prate) */
	Sint32 drop;               /* 0x04 drop frame */
	Sint32 hour;               /* 0x08 */
	Sint32 min;                /* 0x0C */
	Sint32 sec;                /* 0x10 */
	Sint32 frm;                /* 0x14 */
	Sint32 frm2;               /* 0x18 added to frm */
	Sint16 x1c;
	Sint16 field;              /* 0x1E half frame */
} SFTIM_TC;

/* time with its timecode (0x2C bytes) */
typedef struct {
	Sint32 valid;              /* 0x00 */
	SFTIM_TC tc;               /* 0x04 */
	Sint32 val;                /* 0x24 */
	Sint32 unit;               /* 0x28 */
} SFTIM_TTU;

typedef Sint32 (*SFTIM_FN)(SFD sfd, Sint32 *ncount, Sint32 *tscale);

/* timing work (sfd_tim.c), the same memory as SFCON at SFD_OBJ + 0xD28 (SFD_TIM(sfd)) */
typedef struct {
	SFTIM_FN timefn[6];        /* 0x000 clock sources (SFTIM_SetTimeFn / cond 0xF) */
	Bool (*isskipfn)();        /* 0x018 SFD_SetUsrIsSkipFn */
	SFTIM_TC tc;               /* 0x01C */
	SFTIM_TTU ttu0;            /* 0x03C (INT_MAX) */
	SFTIM_TTU ttu1;            /* 0x068 (-1) */
	SFTIM_TTU tot;             /* 0x094 (-1) total time (SFCON.tottime/tunit) */
	SFTIM_TTU ttu3;            /* 0x0C0 (0) */
	SFTIM_TTU vstart;          /* 0x0EC (-1) video start time */
	SFTIM_TTU vofst;           /* 0x118 (INT_MAX) video start offset (SFTIM_GetVideoStartSample) */
	Sint32 astart_smpl;        /* 0x144 SFTIM_SetStartTime */
	Sint32 astart_sfreq;       /* 0x148 */
	Sint32 x14c;
	Sint64 x150;               /* 0x150 (-1) */
	Sint64 as_pts;             /* 0x158 (-1) audio start PTS (90 kHz) */
	Sint32 x160;
	Sint32 ctime;              /* 0x164 (SFCON) */
	Sint32 ctime_idx;          /* 0x168 */
	Sint32 ctime_que[32];      /* 0x16C */
	Sint32 tot_last;           /* 0x1EC (1) */
	Sint32 x1f0;
	Sint32 que_wr;             /* 0x1F4 */
	Sint32 que_rd;             /* 0x1F8 */
	Sint32 tot_que[32];        /* 0x1FC */
	Sint32 vterm;              /* 0x27C (-5) video end time */
	Sint32 vterm_unit;         /* 0x280 (1) */
	Sint32 x284;               /* 0x284 (-5) */
	Sint32 x288;               /* 0x288 (1) */
	Sint32 cur;                /* 0x28C (-1) current time (SFTIM_GetTime) */
	Sint32 cur_unit;           /* 0x290 (1) */
	Sint32 itime;              /* 0x294 (-5) */
	Sint32 itime_min;          /* 0x298 (INT_MAX) */
	Sint32 itime_max;          /* 0x29C (0) */
	Sint32 x2a0;               /* 0x2A0 (INT_MAX) */
	Sint32 x2a4;
	Sint32 vsync;              /* 0x2A8 vsync clock count */
	Sint32 speed;              /* 0x2AC (1000) */
	Sint32 x2b0;
	Sint32 x2b4;
	Sint32 x2b8;               /* 0x2B8 (1) */
	Sint32 x2bc;               /* 0x2BC (100) frame decision count */
	Float32 x2c0;              /* 0x2C0 (-1.0) frame time (ft) of the last decision count */
	Sint32 x2c4;               /* 0x2C4 last frame decision */
	Float32 x2c8;              /* 0x2C8 (-1.0) frame time (ft) of the last decided frame */
	Sint32 vcnt;               /* 0x2CC (-1) vsync count while requested */
	Sint32 chg_base;           /* 0x2D0 clock at the last time change */
	SFTIM_FN extfn;            /* 0x2D4 external clock (SFD_SetExtClockFn) */
	volatile Sint32 ext_last;  /* 0x2D8 (-5) last external clock count (volatile: sftim_GetTimeExtClock
	                              re-reads it after the SFTIM_NONE test) */
	Sint32 ext_cnt;            /* 0x2DC */
	Sint32 ext_unit;           /* 0x2E0 (1) */
	Sint32 ext_wrap;           /* 0x2E4 (-1) */
	void *ext_obj;             /* 0x2E8 */
	Sint32 x2ec;
	Uint8 tst[0x1C0];          /* 0x2F0 (SFD_OBJ + 0x1018) */
	struct {
		Sint16 rpt;            /* repeat_first_field count of the picture */
		Sint16 acc;            /* accumulated repeated fields */
	} rfld[64];                /* 0x4B0 per temporal reference (sfd_mpv.c) */
	Sint32 x5b0;
	Sint32 x5b4;
	Sint32 x5b8;
} SFTIM_WORK;

typedef SFTIM_WORK *SFTIM;

/* library-wide timing work (SFLIB_WORK.tim) */
typedef struct {
	Sint32 vcnt;               /* 0x00 vsync count (SFTIM_VbIn) */
	Sint32 x04;
	Sint32 vrate;              /* 0x08 vsyncs per second (59940 = 59.94 Hz) */
} SFTIM_LIB;

extern const Sint32 SFTIM_prate[9];

/* PTS queue entry (16 bytes, 8-byte aligned) */
typedef struct {
	Sint64 pts;
	Uint32 pos;
	Uint32 len;
} SFPTS_ENT;

typedef struct {
	SFPTS_ENT *ent;            /* 0x00 */
	Sint32 num;                /* 0x04 */
	Sint32 cnt;                /* 0x08 */
	Sint32 wr;                 /* 0x0C */
	Sint32 rd;                 /* 0x10 */
} SFPTS_QUE;

/* per-frame picture information handed to the user (0x80 bytes) */
typedef struct {
	Sint32 raw[0x20];
} SFD_VFRM_INF;

/* video frame slot (0x88 bytes), SFD_OBJ + 0x16A8 + n * 0x88; slot n pairs with SFMPV frame n */
typedef struct {
	void *frm;                 /* 0x00 */
	Sint32 x04;
	SFD_VFRM_INF inf;          /* 0x08 */
} SFD_VFRM;

/* ring-buffer supply of an SFBUF (sfd_buf.c): kind 0 = a memory range (ofst/size), else a stream joint */
typedef struct {
	Sint32 kind;               /* 0x00 */
	SJ sj;                     /* 0x04 */
	Uint32 ofst;               /* 0x08 ring buffer start */
	Sint32 size;               /* 0x0C ring buffer size */
	Sint32 xsize;              /* 0x10 extra (wrap) size */
	Sint32 x14;
} SFBUF_SUP;

/* ring buffer state (SFBUF_WORK.u.ring) */
typedef struct {
	SFBUF_SUP sup;             /* 0x00 */
	Uint8 *dlm_pos;            /* 0x18 delimiter position */
	Sint32 dlm_len;            /* 0x1C */
	Sint32 wtot;               /* 0x20 total written (-1: unknown) */
	Sint32 rtot;               /* 0x24 total read */
	SFPTS_QUE ptsque;          /* 0x28 */
} SFBUF_RING;

/* SFBUF_WORK.mode */
#define SFBUF_MODE_VFRM 1
#define SFBUF_MODE_AOUT 2
#define SFBUF_MODE_UO 3
#define SFBUF_MODE_NONE 4
#define SFBUF_MODE_RING 5

/* SFBUF work (0x74 bytes): buffer n links transfer driver in_tr -> out_tr; SFD_OBJ + 0x1308 + n * 0x74 */
typedef struct {
	Sint32 mode;               /* 0x00 SFBUF_MODE_* */
	Sint32 used;               /* 0x04 supplied */
	Sint32 prepflg;            /* 0x08 */
	Sint32 termflg;            /* 0x0C */
	union {
		SFBUF_RING ring;       /* 0x10 */
		struct {
			Uint32 adr;        /* 0x10 */
			Sint32 size;       /* 0x14 */
			Sint32 x18;
			Sint32 x1c;
			SFD_VFRM *vfrm;    /* 0x20 */
		} vfrm;
		struct {
			Uint32 adr;        /* 0x10 */
			Sint32 size;       /* 0x14 */
			Sint32 rsv[7];     /* 0x18 */
			Sint32 rsv2[3];    /* 0x34 (cleared by SFBUF_InitHn together with rsv) */
		} aout;
		SFUO_CH uoch[3];       /* 0x10 user-output channels */
	} u;
	Sint32 in_tr;              /* 0x4C transfer driver writing this buffer (9: none) */
	Sint32 out_tr;             /* 0x50 transfer driver reading this buffer */
	Sint32 rsv[8];             /* 0x54 */
} SFBUF_WORK;

#define SFD_BUF_NUM 8

/* transfer/stream driver interface (SFD_tr_in_mem, SFD_tr_vo_manu, ...) */
typedef struct {
	Sint32 (*Init)();
	Sint32 (*Finish)();
	Sint32 (*ExecServer)();
	Sint32 (*Create)();
	Sint32 (*Destroy)();
	Sint32 (*Standby)();
	Sint32 (*Start)();
	Sint32 (*Stop)();
	Sint32 (*Pause)();
	Sint32 (*GetWrite)();
	Sint32 (*AddWrite)();
	Sint32 (*GetRead)();
	Sint32 (*AddRead)();
	Sint32 (*Seek)();
} SFD_TR_IF;

typedef Sint32 (*SFD_TR_FUNC)();

/* per-transfer-driver slot (0x44 bytes), SFD_OBJ + 0x1F28 + n * 0x44 */
typedef struct {
	Sint32 prepflg;            /* 0x00 */
	Sint32 termflg;            /* 0x04 */
	void *hn;                  /* 0x08 driver handle (tr[8]: SFUO *) */
	SFD_TR_FUNC *trif;         /* 0x0C driver function table */
	Sint32 bufin;              /* 0x10 SFBUF id read by this driver */
	Sint32 bufout;             /* 0x14 SFBUF id written by this driver */
	Sint32 bufout2;            /* 0x18 */
	Sint32 bufout3;            /* 0x1C */
	Sint32 x20;                /* 0x20 (-1) */
	Uint8 pad24[0x44 - 0x24];
} SFD_TR;

#define SFD_TR_NUM 9
#define SFD_COND_NUM 100
#define SFD_VFRM_NUM 16


/* SFMPV_FRM.stat */
#define SFMPV_FRM_FREE 0
#define SFMPV_FRM_ALLOC 1
#define SFMPV_FRM_STBY 2
#define SFMPV_FRM_DRAWN 3
#define SFMPV_FRM_REF 4

/* reference frame buffer planes handed to the MPEG decoder (sfd_mpv.c, 0x10 bytes) */
typedef struct {
	void *cb;                  /* 0x00 y + luma plane size */
	void *cr;                  /* 0x04 cb + chroma plane size */
	void *y;                   /* 0x08 */
	Sint16 cwidth;             /* 0x0C chroma row bytes */
	Sint16 ywidth;             /* 0x0E luma row bytes */
} SFMPV_PLANE;

/* picture user data slot of a decoded frame */
typedef struct {
	void *buf;
	Sint32 len;
} SFMPV_PICUSR;

/* decoded frame object of the video driver (0xE0 bytes) */
typedef struct {
	Sint32 stat;               /* 0x00 */
	Sint32 lock;               /* 0x04 */
	void *buf;                 /* 0x08 frame buffer (sfmpv_ta_adr_tbl entry) */
	SFTIM_TTU ttu;             /* 0x0C display time (ttu.tc: GOP time code + temporal reference) */
	Sint32 ftime;              /* 0x38 */
	Sint32 tunit;              /* 0x3C */
	Sint32 ndct;               /* 0x40 DCT blocks of the frame */
	Sint32 nbyte;              /* 0x44 */
	Sint32 gopno;              /* 0x48 concatenation count when decoded */
	Sint32 x4c;                /* 0x4C ttu.val */
	Sint32 x50;                /* 0x50 ttu.val + concatenation time */
	SFMPV_PICUSR *picusr;      /* 0x54 */
	/* 0x58: the MPV_PICATR of the picture (mpv.h), 0x80 bytes */
	Sint32 pa_width;           /* 0x58 */
	Sint32 pa_height;          /* 0x5C */
	Sint32 pa_mb_width;        /* 0x60 */
	Sint32 pa_mb_height;       /* 0x64 */
	Sint32 pa_frame_rate;      /* 0x68 */
	Sint32 tmpref;             /* 0x6C temporal reference (10-bit) */
	Sint32 pa_pic_type;        /* 0x70 */
	Sint32 pa_tc_drop;         /* 0x74 */
	Sint32 pa_tc_hour;         /* 0x78 */
	Sint32 pa_tc_min;          /* 0x7C */
	Sint32 pa_tc_sec;          /* 0x80 */
	Sint32 pa_tc_pic;          /* 0x84 */
	Sint32 x88;                /* 0x88 GOP headers seen */
	Sint32 x8c;                /* 0x8C sequence headers seen */
	Sint32 pa_x90[3];          /* 0x90 */
	Sint32 pa_x9c[3];          /* 0x9C */
	Sint16 pa_xa8;             /* 0xA8 */
	Sint16 pa_xaa;             /* 0xAA */
	Sint8 pa_xac;              /* 0xAC */
	Sint8 pa_xad;              /* 0xAD */
	Sint8 pa_xae;              /* 0xAE */
	Sint8 pa_xaf;              /* 0xAF */
	Sint8 pa_xb0;              /* 0xB0 */
	Sint8 pa_xb1;              /* 0xB1 */
	Sint8 pa_xb2;              /* 0xB2 */
	Sint8 pa_xb3;              /* 0xB3 */
	Sint8 pa_xb4;              /* 0xB4 */
	Sint8 pa_xb5;              /* 0xB5 */
	Sint8 pa_xb6;              /* 0xB6 */
	Sint8 pa_xb7;              /* 0xB7 */
	Sint8 pa_xb8;              /* 0xB8 */
	Sint8 pa_xb9;              /* 0xB9 */
	Sint8 pa_xba;              /* 0xBA */
	Sint8 pa_xbb;              /* 0xBB */
	Sint8 pa_xbc;              /* 0xBC */
	Uint8 padbd[0xD8 - 0xBD];
	Sint64 pts;                /* 0xD8 */
} SFMPV_FRM;

/* MPEG video decoder parameters (mwsfd_mpvpara, SFD_SetMpvParaTbl; 0x24 bytes) */
typedef struct {
	Sint32 cwidth;             /* 0x00 chroma plane width (32-byte rounded half width) */
	Sint32 cheight;            /* 0x04 */
	Sint32 width;              /* 0x08 */
	Sint32 height;             /* 0x0C */
	Sint32 x10;
	Sint32 max_width;          /* 0x14 */
	Sint32 max_height;         /* 0x18 */
	Sint32 nfrm;               /* 0x1C decoded frame buffers */
	Sint32 x20;
} SFMPV_PARA;

#define SFMPV_FRM_NUM 16

/* video driver work (tr[2].hn, SFD_OBJ + 0x23A0, 0x1020 bytes) */
typedef struct {
	struct MPV_OBJ *mpv;       /* 0x000 */
	SFMPV_PARA para;           /* 0x004 */
	void *rfb_adr[2];          /* 0x028 reference frame buffers */
	void *ta_adr[SFMPV_FRM_NUM]; /* 0x030 decoded frame buffers */
	SFMPV_FRM *curfrm;         /* 0x070 frame handed out by SFMPV_GetRead */
	Sint32 picstat;            /* 0x074 decode state (2, 3, 5) */
	Sint32 dlmmask;            /* 0x078 start codes accepted by the decoder (0xC0, 0xC8, 0xCC) */
	Sint32 termflg;            /* 0x07C decoder terminated */
	Sint32 gopstat;            /* 0x080 */
	Sint32 nskip;              /* 0x084 frames skipped in a row */
	Sint32 nconcat;            /* 0x088 sequence end codes passed */
	Uint8 picatr[0x80];        /* 0x08C MPV_PICATR of the picture being decoded */
	Sint32 last_ngop;          /* 0x10C */
	Sint32 newgop;             /* 0x110 the picture starts a new GOP */
	Sint32 vbvsiz;             /* 0x114 */
	Sint32 pts_tmpref;         /* 0x118 temporal reference of the picture carrying the PTS */
	Sint32 pts_ofst;           /* 0x11C pictures since the PTS */
	Sint32 pts_max;            /* 0x120 */
	Sint32 pad124;
	SFPTS_ENT ptsent;          /* 0x128 last PTS queue entry seen */
	Sint32 refidx[2];          /* 0x138 reference frame buffer indices (forward, backward) */
	SFMPV_PLANE rfbuf[2];      /* 0x140 */
	SFMPV_FRM *ref[2];         /* 0x160 reference frames (forward, backward) */
	SFMPV_FRM *pendfrm;        /* 0x168 B picture decoded into a standby frame */
	Sint32 skipret;            /* 0x16C */
	Sint32 dlmwait;            /* 0x170 */
	Sint32 tmpref_adj;         /* 0x174 */
	Sint32 nfrm;               /* 0x178 */
	Sint32 pad17c;
	SFMPV_FRM frm[SFMPV_FRM_NUM]; /* 0x180 */
	void *picusr_buf;          /* 0xF80 */
	Sint32 picusr_num;         /* 0xF84 */
	Sint32 picusr_siz;         /* 0xF88 */
	Uint8 *picusr_dat;         /* 0xF8C user data of the picture being decoded */
	Sint32 picusr_len;         /* 0xF90 */
	SFMPV_PICUSR picusr[SFMPV_FRM_NUM]; /* 0xF94 */
	Sint32 pad1014;
	Sint64 pts;                /* 0x1018 PTS of the picture being decoded */
} SFMPV_WORK;

/* 0xA0-byte player information block returned by SFD_GetPlyInf */
typedef struct {
	Sint32 raw[0x28];
} SFD_PLYINF;

/* creation parameters passed to SFTRN_InitHn: trif_tbl[n] is driver n's function table
 * (0 input, 1 system, 2 video, 3 audio, 4 video out, 5 audio out, 6/7 output, 8 user) */
typedef struct {
	SFD_TR_FUNC **trif_tbl;    /* 0x00 */
} SFTRN_PRM;

/* the 15 driver interfaces known to the library (SFTRN_Init) */
typedef struct {
	SFD_TR_IF *tbl[15];
} SFTRN_TRIF_TBL;

/* error callback state (sfd_lib.c), per handle at SFD_OBJ + 0x9F0 and library-wide */
typedef struct {
	void (*fn)(void *obj, Sint32 code); /* 0x00 */
	void *obj;                          /* 0x04 */
	Sint32 code;                        /* 0x08 first error code */
	Sint32 x0c;
	Sint32 x10;
} SFLIB_ERRINF;

/* Sofdec file header analysis results (sfd_hds.c, 0x894 bytes): SFD_OBJ + 0x78, SFSEE_WORK + 0xC */
#define SFHDS_RAW_SIZE 0x800

typedef struct {
	Sint32 codec;              /* 0x4C */
	Sint32 layer;              /* 0x50 */
	Sint32 chnum;              /* 0x54 */
	Sint32 smphz;              /* 0x58 */
} SFHDS_AUD;

typedef struct {
	Sint32 codec;              /* 0x5C */
	Sint32 bitrate;            /* 0x60 */
	Sint32 picw;               /* 0x64 */
	Sint32 pich;               /* 0x68 */
	Sint32 picrate;            /* 0x6C */
	Sint32 ftr_eff;            /* 0x70 feature information present */
	Sint32 ftr_coltype;        /* 0x74 */
	Sint32 ftr_pictype;        /* 0x78 */
	Sint32 ftr_fixflg;         /* 0x7C */
	Sint32 ftr_shcfixflg;      /* 0x80 */
	Sint32 ftr_expand;         /* 0x84 */
	Sint32 ftr_gopn;           /* 0x88 */
	Sint32 ftr_gopm;           /* 0x8C */
} SFHDS_VID;

typedef struct {
	Sint32 valid;              /* 0x00 header analysed */
	Sint32 ver_major;          /* 0x04 muxer tool version */
	Sint32 ver_minor;          /* 0x08 */
	Sint32 byterate;           /* 0x0C (negative for tool versions before 1.10) */
	Sint32 hdrsiz;             /* 0x10 */
	Sint32 packtype;           /* 0x14 */
	Sint32 pketsizlen;         /* 0x18 */
	Sint32 packsiz;            /* 0x1C */
	Sint32 numelem_tot;        /* 0x20 */
	Sint32 numelem_aud;        /* 0x24 */
	Sint32 numelem_vid;        /* 0x28 */
	Sint32 numelem_prv;        /* 0x2C */
	Sint32 maxplylen_aud;      /* 0x30 */
	Sint32 maxplylen_vid;      /* 0x34 */
	Sint32 maxfrmnum;          /* 0x38 */
	Sint32 stmid_prv1;         /* 0x3C 0xBD when present */
	Sint32 stmid_prv2;         /* 0x40 0xBF when present */
	Sint32 stmid_aud;          /* 0x44 first audio stream id (0xC0..0xDF) */
	Sint32 stmid_vid;          /* 0x48 first video stream id (0xE0..0xEF) */
	SFHDS_AUD aud;             /* 0x4C */
	SFHDS_VID vid;             /* 0x5C */
	Sint32 rawsiz;             /* 0x90 */
	Uint8 raw[SFHDS_RAW_SIZE]; /* 0x94 */
} SFHDS_FHD;

/* raw copies of the pack + system header (video one, audio one) kept for seeking (sfd_mps.c) */
typedef struct {
	Uint8 data[2][0xB0];       /* 0x00 */
	Sint32 len[2];             /* 0x160 */
} SFSEE_SYSHD;

/* system stream analysis kept in the seek work (sfd_mps.c), SFSEE_WORK + 0x8A0 */
typedef struct {
	Sint32 analyzed;           /* 0x00 (sfd_see.c: vhdr) */
	Sint32 ncount;             /* 0x04 picrate * 50 (sfd_see.c: vncount) */
	Sint32 tscale;             /* 0x08 (sfd_see.c: vtscale) */
	Sint32 nvid;               /* 0x0C video streams of the system header */
	Sint32 naud;               /* 0x10 audio streams */
	Sint32 pad14;
	Sint64 scr_base;           /* 0x18 */
	Sint64 pts_min;            /* 0x20 */
	Sint32 stmid_vid;          /* 0x28 first video stream id */
	Sint32 stmid_aud;          /* 0x2C first audio stream id */
	SFSEE_SYSHD syshd;         /* 0x30 */
} SFSEE_SHDR;                  /* 0x198 */

/* seek support work supplied by the user through SFD_EntrySeek (sfd_see.c); the header analysis
 * results of the video / audio streams are kept here, followed by the user-set totals */
typedef struct {
	Sint32 analyzed;           /* 0x000 total time known */
	Sint32 ncount;             /* 0x004 total time */
	Sint32 tscale;             /* 0x008 */
	SFHDS_FHD fhd;             /* 0x00C system header analysis */
	SFSEE_SHDR shdr;           /* 0x8A0 system stream analysis (sfd_mps.c), 0x198 bytes */
	Uint8 pada38[0xAD0 - 0xA38];
	Sint32 a1hdr;              /* 0xAD0 audio 1 header analysed */
	Sint32 a1ncount;           /* 0xAD4 */
	Sint32 a1tscale;           /* 0xAD8 */
	Uint8 padadc[0xD0C - 0xADC];
	Sint32 a2hdr;              /* 0xD0C audio 2 header analysed */
	Sint32 a2ncount;           /* 0xD10 */
	Sint32 a2tscale;           /* 0xD14 */
	Uint8 padd18[0xDA8 - 0xD18];
	Sint32 rate;               /* 0xDA8 estimated byte rate */
	Sint32 fsize_est;          /* 0xDAC file size seen by the input driver */
	Sint32 tot_est;            /* 0xDB0 total time from the concatenation work */
	Sint32 tunit_est;          /* 0xDB4 */
	Sint32 av_a;               /* 0xDB8 */
	Sint32 av_b;               /* 0xDBC */
	Sint32 paddc0;
	Sint32 fsize;              /* 0xDC4 SFD_SetFileSize */
	Sint32 tottime;            /* 0xDC8 SFD_SetTotTime */
	Sint32 tunit;              /* 0xDCC */
	Sint32 byterate;           /* 0xDD0 SFD_SetByteRate */
	Sint32 seekpos;            /* 0xDD4 SFD_SetSeekPos */
} SFSEE_WORK;

/* audio stream header analysis kept in the seek work (a1hdr / a2hdr and the words after them) */
typedef struct {
	Sint32 analyzed;           /* 0x00 */
	Sint32 byterate;           /* 0x04 bytes per second */
	Sint32 tunit;              /* 0x08 (1) */
	Sint32 nch;                /* 0x0C */
	Sint32 sfreq;              /* 0x10 */
	Sint32 nsmpl;              /* 0x14 */
} SFSEE_AHDR;

typedef struct {
	Sint32 x00;
	Sint32 pos;                /* 0x04 requested seek position (-3: none) */
	Sint32 x08;
} SFSEE_REQ;

/* ADX audio driver creation parameters (SFD_SetAdxtPara, 0x1C bytes) */
typedef struct {
	Sint32 bsize;              /* 0x00 ring buffer size */
	Sint32 xsize;              /* 0x04 ring buffer extra size */
	void *buf;                 /* 0x08 ring buffer (32-byte aligned) */
	Sint32 maxnch;             /* 0x0C */
	Sint32 x10;
	Sint32 worksize;           /* 0x14 */
	void *work;                /* 0x18 ADXT work (32-byte aligned) */
} SFADXT_PARA;

/* ADX audio driver work (sfd_adxt.c, tr[3].hn), SFD_OBJ + 0x33C0 */
typedef struct {
	void *adxt;                /* 0x00 ADXT handle */
	SJ sj;                     /* 0x04 ring buffer stream joint fed by the transfer */
	SFADXT_PARA para;          /* 0x08 */
	Sint32 tcount;             /* 0x24 last time (-1) */
	Sint32 tunit;              /* 0x28 (1) */
	Sint32 pause;              /* 0x2C */
	Sint32 discard;            /* 0x30 samples still to discard */
	Sint32 seekflg;            /* 0x34 */
	Sint32 smplofst;           /* 0x38 samples skipped before the audio start */
	void (*func)(SFD sfd, Uint8 *data, Sint32 len, Sint32 *nbyte); /* 0x3C transfer state function */
	Sint32 x40;
	Sint32 svrfreq;            /* 0x44 (-1) */
	Sint32 totbyte;            /* 0x48 bytes copied into the stream joint */
	Sint32 x4c;
} SFADXT_WORK;

typedef struct {
	SFSEE_WORK *wk;            /* 0x34C8 */
	SFSEE_REQ req;             /* 0x34CC */
} SFSEE_HN;

/* creation parameters (SFD_Create, 0x44 bytes); the handle starts with a copy of them (sfd_ply.c).
 * The first 0x2C bytes are what sfd_buf.c reads as SFBUF_PRM. */
typedef struct {
	Sint32 x00;
	Uint32 adr;                /* 0x04 buffer work base (aligned to 32 in place by sfply_InitHn) */
	Sint32 size[7];            /* 0x08 sizes of buffers 0..6 */
	Sint32 x24;
	Sint32 unit;               /* 0x28 ring buffer 0 alignment */
	Sint32 x2c;
	Sint32 x30;
	Sint32 x34;
	Sint32 x38;
	void *hnwork;              /* 0x3C handle work (SFD_OBJ, aligned to 32) */
	Sint32 hnwksiz;            /* 0x40 its size (>= 0x35B8) */
} SFD_CREPRM;

/* video PTS manager entry kept across a player reset (sfd_ply.c), SFD_OBJ + 0x12D8 */
typedef struct {
	void *x00;
	Sint32 x04;
	Sint32 x08;
} SFPLY_PTSM;

/* server time statistics (sfd_tmr.c, 0x20 bytes) */
typedef struct {
	Sint64 sum;
	Sint64 min;
	Sint64 max;
	Sint32 cnt;
} SFTMR_TSUM;

/* system stream (MPS) driver work (sfd_mps.c), SFD_OBJ + 0x2190, tr[1].hn */
#define SFMPS_STMID_MIN 0xBC
#define SFMPS_STMID_MAX 0xFF
#define SFMPS_OUTSJ_NUM (SFMPS_STMID_MAX - SFMPS_STMID_MIN + 1)

typedef struct {
	struct MPS_OBJ *mps;       /* 0x000 */
	Sint32 nvid;               /* 0x004 video_bound of the system headers */
	Sint32 naud;               /* 0x008 audio_bound */
	Sint32 x0c;
	Sint64 pts_min;            /* 0x010 minimum audio PTS */
	Sint64 pts_min2;           /* 0x018 */
	Sint32 concat_cnt;         /* 0x020 end codes passed in concatenated play */
	Sint32 last_vid;           /* 0x024 stream id of the last video packet */
	Sint32 last_aud;           /* 0x028 stream id of the last audio packet */
	Sint32 first_vid;          /* 0x02C first video stream id seen (-1) */
	Sint32 first_aud;          /* 0x030 */
	Sint32 cur_vid;            /* 0x034 video stream id being decoded (-1) */
	Sint32 cur_aud;            /* 0x038 */
	Sint32 endcode;            /* 0x03C an end code was seen at the pack start */
	void *outsj[SFMPS_OUTSJ_NUM]; /* 0x040 element output stream joints by stream id - 0xBC */
	void (*outfn)(void *obj, Sint32 stmid); /* 0x150 */
	void *outobj;              /* 0x154 */
	Sint32 skip;               /* 0x158 bytes of the pack still to skip (-1: none) */
	Sint32 x15c;
	Sint32 x160;
	Sint32 x164;
} SFMPS_WORK;                  /* 0x168 */

typedef struct SFD_OBJ {
	SFD_CREPRM prm;            /* 0x00 */
	Sint32 chg_flg;            /* 0x44 set after a control change */
	Sint32 stat;               /* 0x48 */
	Sint32 req;                /* 0x4C requested state (3 = standby, 4 = start) */
	Sint32 pause_sw;           /* 0x50 */
	Sint32 pause_cnt;          /* 0x54 */
	Uint8 pad58[0x74 - 0x58];
	Sint32 pad74;
	SFHDS_FHD fhd;             /* 0x78 file header analysis */
	Sint32 x90c;               /* 0x90C stream information (16 words cleared by sfply_InitHn) */
	Sint32 x910;
	Sint32 x914;
	Sint32 x918;
	Sint32 x91c;
	Sint32 picrate;            /* 0x920 frame rate type (index into SFTIM_prate, 0: unknown) */
	Sint32 x924;
	Sint32 x928;               /* 0x928 (1) */
	Sint32 x92c;
	Sint32 numelem_aud;        /* 0x930 copied from fhd after (re)processing */
	Sint32 numelem_vid;        /* 0x934 */
	Sint32 numelem_prv;        /* 0x938 */
	Sint32 x93c;
	Sint32 x940;
	Sint32 x944;
	Sint32 x948;
	Sint32 x94c;
	SFD_PLYINF plyinf;         /* 0x950 */
	SFLIB_ERRINF err;          /* 0x9F0 */
	Sint32 cond[SFD_COND_NUM]; /* 0xA04 */
	Sint32 cond_def[SFD_COND_NUM]; /* 0xB94 */
	Uint8 padD24[4];
	/* 0xD28 */
	SFCON con;                 /* 0xD28 (also the SFTIM handle: &sfd->con) */
	Uint8 padFA4[(int)(0x1018 - 0xD28 - sizeof(SFCON))];
	Uint8 tst[0x1C0];          /* 0x1018 time stabiliser work (sfd_tst.c SFTST_WORK) */
	Uint8 pad11D8[0x12D8 - 0x11D8];
	SFPLY_PTSM ptsm;           /* 0x12D8 */
	Uint8 pad12E4[0x1308 - 0x12E4];
	SFBUF_WORK buf[SFD_BUF_NUM]; /* 0x1308 */
	SFD_VFRM vfrm[SFD_VFRM_NUM]; /* 0x16A8 */
	SFD_TR tr[SFD_TR_NUM];     /* 0x1F28 (tr[2].hn = SFMPV_WORK *, tr[3].hn = SFADXT_WORK *, tr[8].hn = SFUO *, tr[8].bufin = user-output SFBUF id) */
	Sint32 pad218c;
	SFMPS_WORK mps;            /* 0x2190 system stream driver work (tr[1].hn) */
	Uint8 pad22F8[0x23A0 - 0x22F8];
	SFMPV_WORK mpv;            /* 0x23A0 video driver work (tr[2].hn) */
	SFADXT_WORK adxt;          /* 0x33C0 */
	Uint8 pad3410[0x3474 - 0x3410];
	SFAOAP aoap;               /* 0x3474 (tr[7].hn) */
	SFUO uo_tbl;               /* 0x3490 */
	Sint32 pad34c4;
	SFSEE_HN see;              /* 0x34C8 */
	SFTMR_TSUM tsum[6];        /* 0x34D8 server time statistics (tsum[5]: sfply_ExecOne) */
} SFD_OBJ;                     /* 0x3598; SFD_Create wants 0x35B8 (32-byte alignment slack) */

/* 64-bit stream counters inside plyinf (SFD_OBJ + 0x9B0..0x9D8) seen through a separate view:
 * SFD_PLYINF itself has to stay 4-byte aligned (SFD_GetPlyInf copies it with a lwz/stw loop) */
typedef struct {
	Uint8 pad0[0x980];
	Sint64 s_flow;             /* 0x980 system stream ring: flow count (sfd_mps.c) */
	Sint64 s_byte;             /* 0x988 system stream bytes demultiplexed */
	Sint64 s_skip;             /* 0x990 system stream bytes skipped */
	Sint64 v_flow;             /* 0x998 video input ring: flow count (sfd_mpv.c) */
	Sint64 v_byte;             /* 0x9A0 video bytes handed to the decoder */
	Sint64 v_skip;             /* 0x9A8 video bytes skipped up to a start code */
	Sint64 a_in_wcnt;          /* 0x9B0 audio input ring: written */
	Sint64 a_in_rcnt;          /* 0x9B8 audio input ring: read */
	Sint64 a_byte;             /* 0x9C0 audio bytes handed to the decoder */
	Sint64 a_sj_wcnt;          /* 0x9C8 decoder stream joint: written */
	Sint64 a_sj_rcnt;          /* 0x9D0 decoder stream joint: read */
} SFD_CNT64;

#define SFD_CNT(sfd) ((SFD_CNT64 *)(sfd))
#define SFD_TIM(sfd) ((SFTIM)&(sfd)->con)
#define SFTIM_LIBWK ((SFTIM_LIB *)SFLIB_libwork.tim)


/* library-wide work (sfd_lib.c), 0x228 bytes */
typedef struct {
	Sint32 cond[SFD_COND_NUM];  /* 0x000 default conditions */
	SFTRN_TRIF_TBL *trif_tbl;   /* 0x190 from the init parameters */
	Sint32 prm1;                /* 0x194 */
	Sint32 x198;
	SFLIB_ERRINF err;           /* 0x19C */
	Uint8 tim[0xC];             /* 0x1B0 SFTIM work */
	Sint32 buf;                 /* 0x1BC SFBUF work */
	SFTRN_TRIF_TBL trif;        /* 0x1C0 */
	Sint32 x1fc;
	Sint32 x200;
	SFD hn[8];                  /* 0x204 created handles */
	Sint32 x224;
} SFLIB_WORK;

/* SFD_Init parameters */
typedef struct {
	SFTRN_TRIF_TBL *trif_tbl;   /* 0x00 */
	Sint32 prm1;                /* 0x04 */
} SFD_INIT_PRM;

/* creation information filled by SFD_AnalyCreInf (sfd_cre.c, 0x40 bytes) */
typedef struct {
	Sint8 creatable;           /* 0x00 a driver set or an irregular pack size */
	Sint8 avail;               /* 0x01 a video or audio driver was found */
	const SFD_TR_IF *strif;    /* 0x04 system driver */
	const SFD_TR_IF *vtrif;    /* 0x08 video driver */
	const SFD_TR_IF *atrif;    /* 0x0C audio driver */
	Sint32 packsiz;            /* 0x10 (-1: irregular) */
	Sint32 picw;               /* 0x14 */
	Sint32 pich;               /* 0x18 */
	Sint32 bitrate;            /* 0x1C */
	Sint32 picrate;            /* 0x20 */
	Sint32 vbvsiz;             /* 0x24 */
	Sint8 ach;                 /* 0x28 */
	Sint32 afreq;              /* 0x2C */
	Sint32 rsv[4];             /* 0x30 */
} SFD_CREINF;

extern SFLIB_WORK SFLIB_libwork;

Sint32 SFLIB_SetErr(SFD sfd, Sint32 code);
Sint32 SFLIB_CheckHn(SFD sfd);
void SFLIB_LockCs(Sint32 *cs);
void SFLIB_UnlockCs(Sint32 *cs);
void SFSET_SetCond(SFD sfd, Sint32 id, Sint32 val);
void SFTIM_Pause(SFD sfd, Sint32 sw);
void SFTIM_SetSpeed(SFD sfd, Sint32 speed);
void SFAOAP_SetSpeed(SFD sfd, Sint32 speed);
Sint32 SFTRN_CallTrtTrif(SFD sfd, Sint32 a, Sint32 b, Sint32 c, Sint32 d);
Sint32 SFTRN_IsSetup(SFD sfd, Sint32 id);
void SFBUF_SetUoch(SFD sfd, Sint32 buf, Sint32 chno, SFUO_CH *ch);
Sint32 SFSET_GetCond(SFD sfd, Sint32 id);
Sint32 SFTRN_GetTermFlg(SFD sfd, Sint32 id);
void SFTRN_SetTermFlg(SFD sfd, Sint32 id, Sint32 flg);
Sint32 SFTRN_GetPrepFlg(SFD sfd, Sint32 id);
void SFTRN_SetPrepFlg(SFD sfd, Sint32 id, Sint32 flg);
Sint32 SFBUF_GetTermFlg(SFD sfd, Sint32 buf);
Sint32 SFBUF_GetPrepFlg(SFD sfd, Sint32 buf);
void SFBUF_SetPrepFlg(SFD sfd, Sint32 buf, Sint32 flg);
/* readable / writable regions of a ring buffer (two chunks each, sfd_buf.c) */
typedef struct {
	SJCK ck1;                  /* 0x00 */
	SJCK ck2;                  /* 0x08 */
	Sint32 rsv[3];             /* 0x10 */
} SFBUF_RINF;

Sint32 SFBUF_RingAddWrite(SFD sfd, Sint32 buf, Sint32 nbyte, Sint32 rsv); /* rsv: SFBUF_RINF.rsv[1] of the caller, unused */
Sint32 SFBUF_RingGetWrite(SFD sfd, Sint32 buf, SFBUF_RINF *inf);
Sint32 SFBUF_VfrmAddRead(SFD sfd, Sint32 buf, void *frm);
Sint32 SFBUF_VfrmGetRead(SFD sfd, Sint32 buf, void **frm);
Sint32 UTY_MulDiv(Sint32 a, Sint32 b, Sint32 c);
Sint32 SFCON_IsEndcodeSkip(SFD sfd);
Sint32 SFHDS_GetMuxVerNum(SFD sfd);
Sint32 SFHDS_GetColType(SFD sfd);
void SFHDS_ProcessHdr(SFHDS_FHD *fhd);
void SFHDS_ReprocessHdr(SFD sfd);
Bool SFHDS_IsSfdHeader(void *data, Sint32 size);
Bool SFHDS_SetHdr(SFD sfd, Sint32 type, Uint8 *data, Sint32 size, Sint32 *result);
void SFHDS_FinishFhd(SFHDS_FHD *fhd);
void SFHDS_InitFhd(SFHDS_FHD *fhd);
void SFHDS_Init(void);
Sint32 SFMPS_GetConcatCnt(SFD sfd);
void SFSEE_InitHn(SFSEE_HN *see);
void SFSEE_ExecServer(SFD sfd);
void SFSEE_FixAvPlay(SFD sfd, Sint32 a, Sint32 b);
Sint32 SFD_GetPlyInf(SFD sfd, SFD_PLYINF *inf);
Sint32 SFD_SetCond(SFD sfd, Sint32 id, Sint32 val);
Sint32 SFD_GetHnStat(SFD sfd);
Sint32 SFD_GetTime(SFD sfd, Sint32 *ncount, Sint32 *tscale);
Sint32 SFD_SetSpeed(SFD sfd, Sint32 speed);
Bool SFTIM_IsGetFrmTime(SFD sfd, SFD_VFRM *frm);
Bool SFTIM_IsGetFrmTimeTunit(SFD sfd, Sint32 ftime, Sint32 tunit);
Bool SFTIM_IsVideoTerm(SFD sfd);

#endif
