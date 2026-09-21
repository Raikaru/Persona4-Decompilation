/* CRI Sofdec MPEG video decoder: library/handle management (mpv_lib.c). The library work holds the
 * default conditions and the handle array; each handle (MPV_OBJ, 0x1380 bytes) gets pointers into
 * the shared table area (MPV_IXA) laid out behind the handles. */
#include "cri_xpt.h"

#define MPV_OBJ_SIZE 0x1380
#define MPV_OBJ_SIZE_REAL 0x1378
#define MPV_IXA_SIZE 0x1C60
#define MPV_COND_NUM 16
#define MPV_STAT_STOP 1
#define MPV_STAT_READY 2
#define MPV_HID2_LCE 0x10000000

typedef struct {
	void (*func)(void *obj, Sint32 code);
	void *obj;
	Sint32 code;
	Sint32 reserved[2];
} MPVERR_INF;

/* DCT parameter block (dct_fsri.c), MPV_OBJ + 0x78 */
typedef struct {
	Uint8 pad0[0x18];
	Sint32 cnt0;                    /* 0x18 */
	Sint32 cnt1;                    /* 0x1C */
	Uint8 pad20[0x2C - 0x20];
	Float64 *blk;                   /* 0x2C */
	void *tbl;                      /* 0x30 */
	Uint8 pad34[0x48 - 0x34];
	Uint8 *work;                    /* 0x48 */
} DCT_PA;

/* picture attributes (0x80 bytes) */
typedef struct {
	Sint32 x00, x04, x08, x0c, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34;
	Sint32 x38;
	Sint32 x3c, x40, x44;
	Sint32 x48, x4c;
	Sint16 x50, x52;
	Uint8 x54;
	Sint8 x55, x56, x57;
	Uint8 x58, x59, x5a, x5b, x5c;
	Uint8 x5d;
	Sint8 x5e, x5f, x60;
	Uint8 x61;
	Uint8 x62, x63, x64;
	Uint8 pad65[0x80 - 0x65];
} MPV_PICATR;

/* shared table area (mpvlib_siz_mpvixa bytes) behind the handle array */
typedef struct {
	Uint8 pad0[0x1100];
	Uint16 bitmsk[16];              /* 0x1100 */
	Sint8 zigzag[64];               /* 0x1120 */
	Uint8 scale[0x100];             /* 0x1160 */
	Uint8 group_tbl[32];            /* 0x1260 */
	Uint8 rl[0x30];                 /* 0x1280 */
	Uint8 vlc[0x1860 - 0x12B0];     /* 0x12B0 */
	Uint32 clip[0x60];              /* 0x1860 */
	Uint32 clip_base[0x1C60 - 0x19E0]; /* 0x19E0 */
} MPV_IXA;

typedef struct MPV_OBJ {
	Uint8 pad0[0x10];
	Uint32 *rl_8;                   /* 0x010 run/level VLC tables */
	Uint32 *rl_4;                   /* 0x014 */
	Uint32 *rl_2;                   /* 0x018 */
	Uint32 *rl_1;                   /* 0x01C */
	Uint32 *rl_0a;                  /* 0x020 */
	Uint32 *rl_0b;                  /* 0x024 */
	Uint32 *rl_0c;                  /* 0x028 */
	Sint8 *zigzag;                  /* 0x02C */
	Uint16 *bitmsk;                 /* 0x030 */
	Uint8 *scale;                   /* 0x034 */
	Uint8 *group_tbl;               /* 0x038 */
	void *rl;                       /* 0x03C */
	Uint8 *clip_base;               /* 0x040 */
	Uint8 pad44[0x78 - 0x44];
	DCT_PA dctpa;                   /* 0x078 DCT parameters (DCT_FsriInitPa) */
	Uint8 padC4[0x110 - 0xC4];
	Uint8 *mc_clip;                 /* 0x110 */
	Uint8 *mc_buf0;                 /* 0x114 */
	Uint8 *mc_work;                 /* 0x118 */
	Uint8 *mc_work2;                /* 0x11C */
	Uint8 pad120[0x188 - 0x120];
	Sint32 stat;                    /* 0x188 */
	Sint32 x18c;                    /* 0x18C */
	Sint32 cond[MPV_COND_NUM];      /* 0x190 */
	MPV_PICATR picatr;              /* 0x1D0 */
	MPVERR_INF errinf;              /* 0x250 */
	Uint8 pad264[0x2E4 - 0x264];
	Sint32 x2e4;                    /* 0x2E4 */
	Uint8 pad2E8[0x358 - 0x2E8];
	Sint32 x358;                    /* 0x358 */
	Sint32 x35c;                    /* 0x35C */
	Sint32 x360;                    /* 0x360 */
	Sint32 x364;                    /* 0x364 */
	Uint8 *tbl368[6];               /* 0x368 */
	Uint8 mcbuf[0x680 - 0x380];     /* 0x380 */
	Float64 blk[6][32];             /* 0x680 */
	Uint8 intra_iqm[64];            /* 0xC80 */
	Uint8 nintra_iqm[64];           /* 0xCC0 */
	Uint8 work[0x1300 - 0xD00];     /* 0xD00 */
	Sint32 x1300;                   /* 0x1300 */
	Sint32 x1304;                   /* 0x1304 */
	Uint8 pad1308[0x1314 - 0x1308];
	Sint32 x1314;                   /* 0x1314 */
	void *intra_func;               /* 0x1318 */
	void *nintra_func;              /* 0x131C */
	Sint32 pad1320;
	Sint32 x1324;                   /* 0x1324 */
	void *dctbl_y;                  /* 0x1328 */
	void *dctbl_c;                  /* 0x132C */
	void *m2v;                      /* 0x1330 */
	Uint8 pad1334[MPV_OBJ_SIZE - 0x1334];
} MPV_OBJ;

typedef MPV_OBJ *MPV;

typedef struct {
	Sint32 cond[MPV_COND_NUM + 1];  /* 0x00 default conditions (copy of mpvlib_cond_dfl) */
	Sint32 use_lc_work;             /* 0x44 place the work in the locked cache */
	Uint32 hid2;                    /* 0x48 */
	void *hn_end;                   /* 0x4C */
	MPV_IXA *ixa;                   /* 0x50 */
	Sint32 nhn;                     /* 0x54 */
	MPV_OBJ *hn;                    /* 0x58 */
} MPVLIB_WORK;

extern Sint32 MPVERR_SetCode(MPV mpv, Sint32 code);
extern void MPVERR_InitErrInf(MPVERR_INF *inf);
extern void MPVERR_Init(void);
extern void MPVM2V_SetCond(MPV mpv, Sint32 id, Sint32 val);
extern void MPVM2V_Destroy();
extern void *MPVM2V_Create();
extern void MPVM2V_Finish(void);
extern void MPVM2V_Init(void);
extern void MPVCMC_InitObj(MPV mpv);
extern void MPVCMC_Init(void);
extern void MPVUMC_Init(void);
extern void MPVUMC_Finish(void);
extern void MPVHDEC_Init(void);
extern void MPVFRM_Init(void);
extern void MPVVLC_Init(void *vlc, MPV_IXA *ixa);
extern Sint32 MPVVLC_IsVlcSizErr(void);
extern void MPVBDEC_Init(MPV_IXA *ixa);
extern Sint32 MPVDEC_CheckVersion(const Char8 *ver, Sint32 objsiz, Sint32 picatrsiz);
extern void MPV_SetUsrSj(MPV mpv, Sint32 id, void *sj, Sint32 a, Sint32 b);
extern void MPV_SetPicUsrBuf(MPV mpv, void *buf, Sint32 size);
extern void DCT_FsriInit(void);
extern void DCT_FsriInitPa(void *pa);
extern void DCT_FsriInitScaleTbl(void *tbl);
extern void UTY_MemcpyDword(void *dst, const void *src, Sint32 ndword);
extern void UTY_MemsetDword(void *dst, Sint32 val, Sint32 ndword);
extern void *memset(void *dst, int c, Uint32 n);

extern Uint32 *mpvvlc_run_level_8;
extern Uint32 *mpvvlc_run_level_4;
extern Uint32 *mpvvlc_run_level_2;
extern Uint32 *mpvvlc_run_level_1;
extern Uint32 *mpvvlc_run_level_0a;
extern Uint32 *mpvvlc_run_level_0b;
extern Uint32 *mpvvlc_run_level_0c;
extern void *mpvvlc_y_dcsiz;
extern void *mpvvlc_c_dcsiz;
extern Sint32 MPVABDEC_IntraBlock();
extern Sint32 MPVABDEC_NintraBlock();

void MPV_MbCbFn(void);

const Char8 MPVLIB_version_str[] =
	"\nCRI MPV/GC Ver.1.933 Build:Sep 22 2004 10:34:55\n\0Append: MW2407 GC20Apr2004Patch1\n";

const Sint32 mpvlib_cond_dfl[MPV_COND_NUM + 1] = {
	0, 1, 1, 0, 0, 0, 3, 0x7FFFFFFF, (Sint32)MPV_MbCbFn, 0, 0, 0, 0, 0, 0, 0, 0x5A5A5A5A,
};
const Sint32 mpvlib_siz_mpvwork = sizeof(MPVLIB_WORK);
const Sint32 mpvlib_siz_mpvobj = MPV_OBJ_SIZE_REAL;
const Sint32 mpvlib_siz_mpvixa = MPV_IXA_SIZE;

static Sint32 mpvlib_use_lc;
Uint8 mpv_clip_0_255_tbl[0x400];
static Uint8 *mpv_clip_0_255_base;
static MPV mpvlib_mpvobj;
static Sint32 mpvlib_oix;
Sint32 mpvlib_iix;
static MPVLIB_WORK mpvlib_libwork;
static const Char8 *cri_verstr_ptr;

/* dead-stripped by the linker; they fix the .bss order (first reference) */
void MPVLIB_SetUseLc(Sint32 sw)
{
	mpvlib_use_lc = sw;
}

// The 0..255 clip table (0x180 zeros, identity, 0x180 0xFF).
Uint8 *MPVLIB_GetClipTbl(void)
{
	return mpv_clip_0_255_tbl;
}

// The clip table's zero point (index 0x180), which the output stages index with signed values.
Uint8 *MPVLIB_GetClipBase(void)
{
	return mpv_clip_0_255_base;
}

// -1 for a NULL or not-ready handle (stat != READY); records it in mpvlib_mpvobj.
// FUN_00507480
Sint32 MPVLIB_CheckHn(MPV mpv)
{
	mpvlib_mpvobj = mpv;
	if (mpv == NULL) {
		return -1;
	}
	if (mpv->stat != MPV_STAT_READY) {
		return -1;
	}
	return 0;
}

/* dead-stripped by the linker */
Sint32 MPVLIB_GetOix(void)
{
	return mpvlib_oix;
}

// Dead: input index.
Sint32 MPVLIB_GetIix(void)
{
	return mpvlib_iix;
}

// Decoder condition `id` of the handle (or the library default when mpv is NULL).
// FUN_005073F0
Sint32 MPV_GetCond(MPV mpv, Sint32 id, Sint32 *val)
{
	Sint32 *cond;

	if (mpv == NULL) {
		cond = mpvlib_libwork.cond;
	} else {
		if (MPVLIB_CheckHn(mpv) != 0) {
			return MPVERR_SetCode(NULL, 0xFF030210);
		}
		cond = mpv->cond;
	}
	*val = cond[id];
	return 0;
}

// Sets decoder condition `id` (id 8 with 0 installs the empty macroblock callback); mpv NULL sets
// the library default and every ready handle. The SFD driver sets 5 (MC chroma flag) = 0.
Sint32 MPV_SetCond(MPV mpv, Sint32 id, Sint32 val)
{
	Sint32 *cond;
	Sint32 i;
	Sint32 nhn;
	MPV hn;

	if (id == 8 && val == 0) {
		val = (Sint32)MPV_MbCbFn;
	}
	if (mpv == NULL) {
		nhn = mpvlib_libwork.nhn;
		hn = mpvlib_libwork.hn;
		for (i = 0; i < nhn; i++) {
			if (hn->stat == MPV_STAT_READY) {
				hn->cond[id] = val;
			}
			hn++;
		}
		cond = mpvlib_libwork.cond;
	} else {
		if (MPVLIB_CheckHn(mpv) != 0) {
			return MPVERR_SetCode(NULL, 0xFF030202);
		}
		cond = mpv->cond;
	}
	cond[id] = val;
	MPVM2V_SetCond(mpv, id, val);
	return 0;
}

// Default (empty) per-macroblock callback.
void MPV_MbCbFn(void)
{
}

// Frees the handle (invalidating its locked-cache lines when the L1 lock cache is enabled).
Sint32 MPV_Destroy(MPV mpv)
{
	register MPV p = mpv;
	register Sint32 i;

	if (MPVLIB_CheckHn(p) != 0) {
		return MPVERR_SetCode(NULL, 0xFF030201);
	}
	MPVM2V_Destroy(p);
	if (mpvlib_libwork.hid2 & MPV_HID2_LCE) {
		for (i = 0; i < MPV_OBJ_SIZE; i += 0x20) {
			
		}
	}
	p->stat = MPV_STAT_STOP;
	return 0;
}

// The two IDCT block counters of the DCT parameter block (statistics: full / DC-only blocks).
void MPV_GetDctCnt(MPV mpv, Sint32 *a, Sint32 *b)
{
	*a = mpv->dctpa.cnt0;
	*b = mpv->dctpa.cnt1;
}

static void mpvlib_InitPicAtr(MPV_PICATR *atr);

// Builds a handle: bit reader cleared, VLC / zigzag / bit-mask / scale / clip table pointers into
// the shared table area, default conditions, cleared picture attributes and error record, motion
// compensation objects, DCT parameter block, MPEG-1 mode, no user joints.
MPV mpvlib_InitHn(MPV mpv)
{
	MPV_IXA *ixa = mpvlib_libwork.ixa;
	Sint32 i;
	DCT_PA *pa;

	mpv->rl_8 = mpvvlc_run_level_8;
	mpv->rl_4 = mpvvlc_run_level_4 - 4;
	mpv->rl_2 = mpvvlc_run_level_2 - 8;
	mpv->rl_1 = mpvvlc_run_level_1 - 8;
	mpv->rl_0a = mpvvlc_run_level_0a;
	mpv->rl_0b = mpvvlc_run_level_0b;
	mpv->rl_0c = mpvvlc_run_level_0c;
	mpv->group_tbl = ixa->group_tbl;
	mpv->rl = ixa->rl;
	mpv->zigzag = ixa->zigzag;
	mpv->bitmsk = ixa->bitmsk;
	mpv->scale = ixa->scale;
	mpv->clip_base = mpv_clip_0_255_base;
	mpv->mc_clip = mpv->clip_base;
	mpv->mc_buf0 = mpv->mcbuf;
	mpv->mc_work = mpv->work;
	mpv->mc_work2 = mpv->mc_work + 0x180;
	mpv->tbl368[0] = mpv->mcbuf + 0x100;
	mpv->tbl368[1] = mpv->mcbuf + 0x180;
	mpv->tbl368[2] = mpv->mcbuf + 0x200;
	mpv->tbl368[3] = mpv->mcbuf + 0x280;
	mpv->tbl368[4] = mpv->mcbuf;
	mpv->tbl368[5] = mpv->mcbuf + 0x80;
	mpv->x2e4 = 0;
	mpv->x18c = 0;
	UTY_MemcpyDword(mpv->cond, mpvlib_libwork.cond, MPV_COND_NUM);
	MPVERR_InitErrInf(&mpv->errinf);
	MPVCMC_InitObj(mpv);
	pa = &mpv->dctpa;
	DCT_FsriInitPa(pa);
	pa->work = mpv->work;
	pa->blk = mpv->blk[0];
	pa->tbl = mpv->tbl368;
	mpvlib_InitPicAtr(&mpv->picatr);
	mpv->x1300 = 0;
	mpv->x1304 = 0;
	mpv->dctbl_y = mpvvlc_y_dcsiz;
	mpv->dctbl_c = mpvvlc_c_dcsiz;
	mpv->x358 = 0;
	mpv->x35c = 0;
	mpv->x360 = 0;
	mpv->x364 = 0;
	mpv->x1314 = 0;
	mpv->intra_func = MPVABDEC_IntraBlock;
	mpv->nintra_func = MPVABDEC_NintraBlock;
	mpv->x1324 = mpv->cond[7];
	for (i = 0; i < 4; i++) {
		MPV_SetUsrSj(mpv, i, NULL, 0, 0);
	}
	MPV_SetPicUsrBuf(mpv, NULL, 0);
	mpv->stat = MPV_STAT_READY;
	return mpv;
}

/* first unused handle */
static MPV mpvlib_SearchFreeHn(void)
{
	Sint32 nhn;
	MPV hn;
	Sint32 i;

	nhn = mpvlib_libwork.nhn;
	hn = mpvlib_libwork.hn;
	for (i = 0; i < nhn; i++) {
		if (hn->stat == MPV_STAT_STOP) {
			return hn;
		}
		hn++;
	}
	return NULL;
}

// Takes a free handle (locked-cache lines zeroed when enabled), initialises it and creates the
// (absent) MPEG-2 sub-object.
MPV MPV_Create(void)
{
	register MPV mpv;
	register Sint32 i;
	register MPV hn;

	hn = mpvlib_SearchFreeHn();
	mpv = hn;
	if (mpv == NULL) {
		return NULL;
	}
	if (mpvlib_libwork.hid2 & MPV_HID2_LCE) {
		for (i = 0; i < MPV_OBJ_SIZE; i += 0x20) {
			
			
		}
	}
	mpv = mpvlib_InitHn(mpv);
	mpv->m2v = MPVM2V_Create(mpv);
	return mpv;
}

// Library finish: unified MC and M2V, locked-cache invalidate of the table area.
void MPV_Finish(void)
{
	register Sint32 i;
	register MPV_IXA *ixa;

	MPVUMC_Finish();
	MPVM2V_Finish();
	ixa = mpvlib_libwork.ixa;
	if (mpvlib_libwork.hid2 & MPV_HID2_LCE) {
		for (i = 0; i < MPV_IXA_SIZE; i += 0x20) {
			
		}
	}
}

// Cleared picture attributes (unknown = 0, the three last bytes 0xFF).
static void mpvlib_InitPicAtr(MPV_PICATR *atr)
{
	memset(atr, 0, 4);
	atr->x00 = 0;
	atr->x04 = 0;
	atr->x08 = 0;
	atr->x0c = 0;
	atr->x10 = 0;
	atr->x14 = 0;
	atr->x18 = 0;
	atr->x1c = 0;
	atr->x20 = 0;
	atr->x24 = 0;
	atr->x28 = 0;
	atr->x2c = 0;
	atr->x30 = 0;
	atr->x34 = 0;
	atr->x38 = 3;
	atr->x3c = 1;
	atr->x40 = 1;
	atr->x44 = 1;
	atr->x48 = 0;
	atr->x4c = 0;
	atr->x50 = -1;
	atr->x52 = -1;
	atr->x54 = 0;
	atr->x55 = -1;
	atr->x56 = -1;
	atr->x57 = -1;
	atr->x58 = 0;
	atr->x59 = 1;
	atr->x5a = 0;
	atr->x5b = 0;
	atr->x5c = 0;
	atr->x5d = 0xFF;
	atr->x5e = -1;
	atr->x5f = -1;
	atr->x60 = -1;
	atr->x61 = 0;
	atr->x62 = 0xFF;
	atr->x63 = 0xFF;
	atr->x64 = 0xFF;
}

static const Uint32 test_wrok = 0x01020304;

// Library init in the caller's work: sanity checks (MC buffer alignment, VLC area size, object size,
// condition table guard word, version "1.933", big-endian), reads HID2 for the locked-cache option,
// lays out `nhn` 0x1380-byte handles followed by the shared table area (MPV_IXA: VLC tables, block
// decoder tables, clip table), copies the default conditions and initialises the sub-modules.
Sint32 MPV_Init(Sint32 nhn, void *work)
{
	Sint32 siz_mcbuf = 0x380;
	Sint32 siz_obj = MPV_OBJ_SIZE;
	Uint8 *hn_end;
	register MPV_OBJ *hn;
	register MPV_IXA *ixa;
	register Sint32 i;
	Uint32 hid2;
	Sint32 ret;
	Uint8 *wk;
	Uint8 *p;

	cri_verstr_ptr = MPVLIB_version_str;
	if ((siz_mcbuf & 0x1F) != 0) {
		ret = MPVERR_SetCode(NULL, 0xFF03FF06);
	} else if (MPVVLC_IsVlcSizErr() != 0) {
		ret = MPVERR_SetCode(NULL, 0xFF03FF03);
	} else if ((Uint32)siz_obj > 0x2000) {
		ret = MPVERR_SetCode(NULL, 0xFF03FF01);
	} else if (mpvlib_cond_dfl[MPV_COND_NUM] != 0x5A5A5A5A) {
		ret = MPVERR_SetCode(NULL, 0xFF03FF02);
	} else if (MPVDEC_CheckVersion("1.933", MPV_OBJ_SIZE_REAL, 0x80) != 0) {
		ret = MPVERR_SetCode(NULL, 0xFF03FF07);
	} else {
		if (*(const Uint8 *)&test_wrok != 1) {
			for (;;) {
				((void (*)(void))-1)();
			}
		}
		ret = 0;
	}
	if (ret != 0) {
		if (ret == 0xFF03FF05) {
			return ret;
		}
		for (;;) {
		}
	}

	
	if (mpvlib_use_lc == 0) {
		hid2 &= ~MPV_HID2_LCE;
	}
	mpvlib_libwork.hid2 = hid2;
	wk = work;
	if (mpvlib_libwork.use_lc_work != 0) {
		wk = (Uint8 *)((Uint32)work | 0x02000000);
	}
	hn = (MPV_OBJ *)(((Uint32)wk + 0x1F) & ~0x1F);
	UTY_MemsetDword(hn, 0, (Uint32)(nhn * 0x2000 + 0x2000) / 4);
	hn_end = (Uint8 *)hn + nhn * MPV_OBJ_SIZE;
	ixa = (MPV_IXA *)(hn_end + 0x3A0);
	if (mpvlib_libwork.hid2 & MPV_HID2_LCE) {
		for (i = 0; i < MPV_IXA_SIZE; i += 0x20) {
			
			
		}
	}
	UTY_MemcpyDword(mpvlib_libwork.cond, mpvlib_cond_dfl, MPV_COND_NUM);
	mpvlib_libwork.hn_end = hn_end;
	mpvlib_libwork.ixa = ixa;
	mpvlib_libwork.nhn = nhn;
	mpvlib_libwork.hn = hn;
	MPVERR_Init();
	MPVHDEC_Init();
	MPVFRM_Init();
	MPVVLC_Init(ixa->vlc, ixa);
	MPVBDEC_Init(ixa);
	MPVUMC_Init();
	MPVCMC_Init();
	p = mpv_clip_0_255_tbl;
	for (i = 0; i < 0x180; i++) {
		*p++ = 0;
	}
	for (i = 0; i < 0x100; i++) {
		*p++ = i;
	}
	for (i = 0; i < 0x180; i++) {
		*p++ = 0xFF;
	}
	mpv_clip_0_255_base = &mpv_clip_0_255_tbl[0x180];
	if (ixa->clip != NULL) {
		UTY_MemcpyDword(ixa->clip, mpv_clip_0_255_tbl, 0x100);
		mpv_clip_0_255_base = (Uint8 *)ixa->clip_base;
	}
	{
		Sint32 n = mpvlib_libwork.nhn;
		MPV_OBJ *p = mpvlib_libwork.hn;

		for (i = 0; i < n; i++) {
			p->stat = MPV_STAT_STOP;
			p++;
		}
	}
	DCT_FsriInit();
	DCT_FsriInitScaleTbl(ixa->scale);
	MPVM2V_Init();
	return 0;
}
