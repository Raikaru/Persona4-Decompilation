/* CRI Sofdec MPEG video decoder (MPV) object layout, from the field offsets used by the DOL. */
#ifndef CRI_MPV_H
#define CRI_MPV_H

#include "cri_xpt.h"
#include "sj.h"

typedef struct {
	void *p;
	Sint32 n;
} MPVCMC_REF;

typedef struct {
	void (*func)(void *obj, Sint32 code);
	void *obj;
	Sint32 code;
} MPVERR_INF;

/* picture attributes (0x80 bytes; MPV_OBJ + 0x1D0, copied out by MPV_GetPicAtr) */
typedef struct {
	Sint32 width;        /* 0x00 horizontal_size */
	Sint32 height;       /* 0x04 vertical_size */
	Sint32 mb_width;     /* 0x08 */
	Sint32 mb_height;    /* 0x0C */
	Sint32 frame_rate;   /* 0x10 picture_rate code */
	Sint32 temp_ref;     /* 0x14 temporal_reference */
	Sint32 pic_type;     /* 0x18 picture_coding_type */
	Sint32 tc_drop;      /* 0x1C GOP time code: drop_frame_flag */
	Sint32 tc_hour;      /* 0x20 */
	Sint32 tc_min;       /* 0x24 */
	Sint32 tc_sec;       /* 0x28 */
	Sint32 tc_pic;       /* 0x2C */
	Sint32 ngop;         /* 0x30 GOP headers seen */
	Sint32 nseq;         /* 0x34 sequence headers seen */
	Sint32 x38;          /* 0x38 */
	Sint32 x3c, x40, x44;
	Sint32 bitrate;      /* 0x48 */
	Sint32 vbv_size;     /* 0x4C */
	Sint16 x50, x52;
	Sint8 x54;
	Sint8 x55, x56, x57;
	Sint8 x58;
	Uint8 aspect;        /* 0x59 pel_aspect_ratio */
	Uint8 constrained;   /* 0x5A constrained_parameters_flag */
	Uint8 x5b, x5c;
	Uint8 x5d;
	Sint8 x5e, x5f, x60;
	Uint8 x61;
	Uint8 x62, x63, x64;
	Uint8 pad65[0x80 - 0x65];
} MPV_PICATR;

/* frame parameter block passed to MPV_DecodeFrmSj (0x30 bytes) */
typedef struct {
	Uint8 pad0[0x1C];
	Sint16 width;        /* 0x1C */
	Sint16 height;       /* 0x1E */
	Uint8 pad20[4];
	MPV_PICATR *picatr;  /* 0x24 */
	Sint32 nfrm;         /* 0x28 */
	Sint32 nbyte;        /* 0x2C */
} MPV_FRM;

/* run/level VLC table selector (mpv_bdec.c) */
typedef struct {
	Uint32 *tbl;
	Sint32 bits;
} MPV_RUNLEVEL;

typedef struct MPV_OBJ *MPV;

/* motion compensation work (MPV_OBJ + 0xCC, 0x54 bytes; mpv_mc.c / mpv_mcy.c / mpv_umc.c) */
typedef struct MPVMC {
	void (*oneref08[4])(struct MPVMC *mc); /* 0x00 8x8 block: 1p, H2, V2, 4p */
	Uint8 pad10[8];
	Uint32 *dst;                    /* 0x18 */
	Uint8 pad1C[4];
	Sint32 stride;                  /* 0x20 */
	Uint8 *src;                     /* 0x24 */
	Uint8 *src2;                    /* 0x28 second reference row / block */
	Uint8 pad2C[8];
	void (*oneref16[4])(struct MPVMC *mc); /* 0x34 16x16 block */
	Uint8 pad44[0x54 - 0x44];
} MPVMC;

/* block decoder parameters (mpv_cdec.c -> intra/nintra block decode function; the first six are
 * the run/level decode state of mpvabdec.c) */
typedef struct {
	Sint32 run;                     /* 0x00 */
	Sint32 level;                   /* 0x04 */
	Sint32 sign;                    /* 0x08 */
	Sint32 len;                     /* 0x0C code length in bits */
	Sint32 idx0;                    /* 0x10 zigzag position of the first coefficient */
	Sint32 idx;                     /* 0x14 zigzag position of the last coefficient */
	Sint32 pad18;
	Float64 *dst;                   /* 0x1C block coefficient buffer (64 Float32) */
	Uint8 *iqm;                     /* 0x20 quantiser matrix */
	Sint32 qscale;                  /* 0x24 */
	Sint32 *dcpred;                 /* 0x28 intra DC predictor of the component */
	void *dctbl;                    /* 0x2C intra DC size table */
	Sint32 nintra;                  /* 0x30 */
} MPV_BLKPRM;

typedef Sint32 (*MPV_BLKDEC_FUNC)(MPV mpv, MPV_BLKPRM *prm);

/* motion vector parameters of one direction (mpv_hdec.c picture header, MPVDEC_ResetMv) */
typedef struct {
	Sint32 full_pel;                /* 0x00 full_pel_*_vector */
	Sint32 r_size;                  /* 0x04 f_code - 1 */
	Sint32 shift;                   /* 0x08 27 - r_size */
	Sint32 f;                       /* 0x0C 1 << r_size */
	Sint32 pred[2];                 /* 0x10 predictors (h, v) */
	Sint32 vec[2];                  /* 0x18 decoded vector (h, v) */
	Sint32 pad;
} MPV_MV;

/* user data stream joints (MPV_SetUsrSj) */
typedef struct {
	SJ sj;
	void (*func)(void *obj, Sint32 id);
	void *obj;
} MPV_USRSJ;

typedef struct MPV_OBJ {
	Uint32 bbuf;                    /* 0x000 bit reader state saved around the block decoders */
	Uint32 nbuf;                    /* 0x004 */
	Sint32 bitpos;                  /* 0x008 */
	Uint32 *bitptr;                 /* 0x00C */
	Uint32 *rl_8;                   /* 0x010 run/level VLC tables (mpv_lib.c) */
	Uint32 *rl_4;                   /* 0x014 */
	Uint32 *rl_2;                   /* 0x018 */
	Uint32 *rl_1;                   /* 0x01C */
	Uint32 *rl_0a;                  /* 0x020 */
	Uint32 *rl_0b;                  /* 0x024 */
	Uint32 *rl_0c;                  /* 0x028 */
	Sint8 *zigzag_tbl;              /* 0x02C */
	Uint16 *bitmsk_tbl;             /* 0x030 */
	Uint8 *scale_tbl;               /* 0x034 */
	Uint8 *group_tbl_p;             /* 0x038 */
	void *rl_p;                     /* 0x03C */
	Uint8 *clip_base;               /* 0x040 */
	MPV_BLKPRM blkprm;              /* 0x044 */
	Sint8 cbp[6];                   /* 0x078 per-block coded flags */
	Uint8 pad7E[0xA0 - 0x7E];
	Sint32 cbp_msk;                 /* 0x0A0 */
	Uint8 padA4[0xCC - 0xA4];
	MPVMC mc;                       /* 0x0CC */
	Sint32 ccnt_rt;                 /* 0x120 */
	MPVCMC_REF oi_rt[6];            /* 0x124 */
	Sint32 ccnt;                    /* 0x154 */
	MPVCMC_REF oi[6];               /* 0x158 */
	Sint32 stat;                    /* 0x188 */
	Sint32 x18c;                    /* 0x18C */
	Sint32 cond[16];                /* 0x190 (cond[5] = mcflag) */
	MPV_PICATR picatr;              /* 0x1D0 */
	MPVERR_INF errinf;              /* 0x250 */
	Sint32 nfrm_dec;                /* 0x25C */
	Sint32 nbyte_dec;               /* 0x260 */
	MPV_FRM frm;                    /* 0x264 */
	Uint8 pad294[0x2A4 - 0x294];
	Sint32 aspect;                  /* 0x2A4 pel_aspect_ratio */
	Sint32 bitrate;                 /* 0x2A8 */
	Sint32 vbv_size;                /* 0x2AC */
	Sint32 constrained;             /* 0x2B0 constrained_parameters_flag */
	Sint32 linkflg1;                /* 0x2B4 closed_gop */
	Sint32 linkflg2;                /* 0x2B8 broken_link */
	Sint32 vbv_delay;               /* 0x2BC */
	Sint32 (*dec_mbs_func)(MPV mpv, SJ sj);   /* 0x2C0 slice macroblock decoder of the picture type */
	void (*skip_func)(MPV mpv);     /* 0x2C4 */
	Sint32 (*intra_blocks)(MPV mpv);          /* 0x2C8 */
	Sint32 (*nintra_blocks)(MPV mpv);         /* 0x2CC */
	void (*mc_intra_func)(MPV mpv); /* 0x2D0 */
	void (*mc_func[4])(MPV mpv);    /* 0x2D4 [0] current, [1] backward, [2] forward, [3] both */
	Sint32 x2e4;                    /* 0x2E4 */
	Sint32 qscale;                  /* 0x2E8 */
	MPV_MV fwd;                     /* 0x2EC */
	MPV_MV bwd;                     /* 0x310 */
	Sint32 mb_addr;                 /* 0x334 macroblock address */
	Sint32 mb_y;                    /* 0x338 */
	Sint32 mb_x;                    /* 0x33C */
	Sint32 mb_last;                 /* 0x340 mb_width * mb_height - 1 */
	Sint32 mbtype;                  /* 0x344 macroblock_type flags (1 intra, 2 pattern, 4 bwd, 8 fwd, 0x10 quant) */
	Sint32 cbp_code;                /* 0x348 coded block pattern */
	Sint32 dcpred[3];               /* 0x34C */
	Sint32 m2v_mode;                /* 0x358 0 unknown, 1 MPEG-1, 2 MPEG-2 */
	Sint32 stc[3];                  /* 0x35C "STCCODE" user data values */
	Uint8 *tbl368[6];               /* 0x368 */
	Uint8 mcbuf[0x680 - 0x380];     /* 0x380 */
	Float64 blk[6][32];             /* 0x680 six 0x100-byte coefficient blocks */
	Uint8 intra_iqm[64];            /* 0xC80 */
	Uint8 nintra_iqm[64];           /* 0xCC0 */
	Uint8 work[0x1100 - 0xD00];     /* 0xD00 */
	Uint16 bitmsk[16];              /* 0x1100 */
	Sint8 zigzag[64];               /* 0x1120 */
	Uint8 pad1160[0x1260 - 0x1160];
	Uint8 group_tbl[32];            /* 0x1260 */
	MPV_RUNLEVEL rl[6];             /* 0x1280 */
	Uint8 pad12B0[0x1300 - 0x12B0];
	Sint32 pic_done;                /* 0x1300 set when a picture has been decoded */
	Sint32 npic;                    /* 0x1304 */
	SJCK ck;                        /* 0x1308 chunk being parsed */
	Sint32 bitofs;                  /* 0x1310 bit offset of the slice data in its first byte */
	Sint32 dcprec;                  /* 0x1314 "IDCPREC" (0: 8 bit, 3: 11 bit DC) */
	MPV_BLKDEC_FUNC intra_func;     /* 0x1318 */
	MPV_BLKDEC_FUNC nintra_func;    /* 0x131C */
	Sint32 pad1320;
	Sint32 x1324;                   /* 0x1324 copy of cond[7] */
	void *dctbl_y;                  /* 0x1328 */
	void *dctbl_c;                  /* 0x132C */
	void *m2v;                      /* 0x1330 */
	Sint32 hdrtype;                 /* 0x1334 header being decoded: 1 sequence, 2 GOP, 3 picture */
	MPV_USRSJ usr[4];               /* 0x1338 */
	Uint8 *picusr_buf;              /* 0x1368 */
	Sint32 picusr_bufsiz;           /* 0x136C */
	Sint32 picusr_len;              /* 0x1370 */
	Sint32 pad1374;
} MPV_OBJ;

Sint8 *MPV_SearchDelim(Sint8 *p, Sint32 n, Sint32 mask);
Sint32 MPV_CheckDelim(void *ptr);
Sint32 MPV_IsEmptyPpic(Sint8 *buf, Sint32 nbyte, Sint32 nmb);
Sint32 MPV_IsEmptyBpic(Sint8 *buf, Sint32 nbyte, Sint32 nmb);
Sint32 MPVLIB_CheckHn(MPV_OBJ *mpv);
Sint32 MPVERR_SetCode(MPV_OBJ *mpv, Sint32 code);

#define MPV_ERR_INVALID_HN 0xFF030200

#endif
