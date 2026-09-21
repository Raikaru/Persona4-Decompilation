/* CRI Sofdec video driver (sfd_mpv.c): the SFD transfer driver that feeds the MPEG video decoder
 * (MPV) from the video input ring buffer, times the decoded pictures and hands them to the frame
 * pool (sfd_mpvf.c).
 *
 * Compiled with `-inline auto,deferred` (CRI_CFLAG_OVERRIDES): the file is written in the reverse
 * of the DOL's .text order, .bss is the reverse of the declaration order, and the static helpers
 * are `static inline` (deferred emits every static that is not forced). Not Matching: 33/38
 * functions byte-identical, .rodata/.bss identical. Residues: register ranking (a parameter ranked
 * above the pool temp in SFMPV_Destroy / SFMPV_Create, the geometry / loop-IV colours and the
 * nfrm-vs-frm early slot of sfmpv_ChkBufSiz, one extra callee-saved register and the -1/zero
 * constant sharing of sfmpv_DecodePicAtr) and the address-taken slot order of sfmpv_ExecServerSub.
 * sfmpv_Pts2Tc carries the one tagged form of the unit (`#pragma pool_data off`, COMPILER-DIFF M2:
 * the original addresses its three .rodata tables with separate lis/addi pairs). */
#include "cri_xpt.h"
#include "sfd.h"
#include "mpv.h"
#include <string.h>

#define SFMPV_TR 2
#define SFMPV_WK(sfd) ((SFMPV_WORK *)(sfd)->tr[SFMPV_TR].hn)
#define SFMPV_BUFIN(sfd) ((sfd)->tr[SFMPV_TR].bufin)
#define SFMPV_BUFOUT(sfd) ((sfd)->tr[SFMPV_TR].bufout)

/* start code classes returned by MPV_CheckDelim */
#define SFMPV_DLM_SLICE 0x02
#define SFMPV_DLM_PIC 0x04
#define SFMPV_DLM_GOP 0x08
#define SFMPV_DLM_SEQ 0x40
#define SFMPV_DLM_END 0x80

/* repeated-field record of the time work (sfd.h SFTIM rfld[64]) */
typedef struct {
	Sint16 rpt;                /* 0x00 repeat_first_field count of the picture */
	Sint16 acc;                /* 0x02 accumulated repeated fields */
} SFMPV_RFLD;

/* picture user data work of the handle (SFMPV_WORK picusr_buf .. picusr[], 0x94 bytes) */
typedef struct {
	void *buf;                 /* 0x00 */
	Sint32 num;                /* 0x04 */
	Sint32 siz;                /* 0x08 */
	Uint8 *dat;                /* 0x0C */
	Sint32 len;                /* 0x10 */
	SFMPV_PICUSR slot[SFMPV_FRM_NUM]; /* 0x14 */
} SFMPV_PICUSRWK;

/* frame parameter block handed to MPV_DecodeFrmSj (mpv.h MPV_FRM, 0x30 bytes) */
typedef struct {
	SFMPV_PLANE ref[2];        /* 0x00 forward / backward reference planes */
	void *dst;                 /* 0x20 decoded frame buffer */
	MPV_PICATR *picatr;        /* 0x24 */
	Sint32 nfrm;               /* 0x28 */
	Sint32 nbyte;              /* 0x2C */
} SFMPV_MPVFRM;

/* video stream information kept in the handle (SFD_OBJ + 0x90C) */
typedef struct {
	Sint32 width;              /* 0x00 */
	Sint32 height;             /* 0x04 */
	Sint32 mb_width;           /* 0x08 */
	Sint32 mb_height;          /* 0x0C */
	Sint32 bitrate;            /* 0x10 */
	Sint32 picrate;            /* 0x14 */
	Sint32 x18;
	Sint32 x1c;
	Sint32 vbvsiz;             /* 0x20 */
} SFMPV_STMINF;

/* video header cache of the seek work (SFSEE_WORK + 0xAD0, sfd.h a1hdr) */
typedef struct {
	Sint32 analyzed;           /* 0x000 */
	Sint32 byterate;           /* 0x004 */
	Sint32 tunit;              /* 0x008 */
	SFTIM_TTU ttu;             /* 0x00C video start time */
	Uint8 raw[0x200];          /* 0x038 first bytes of the sequence header */
	Sint32 rawlen;             /* 0x238 */
} SFSEE_VHDR;

/* the cached header bytes and their length (SFSEE_VHDR raw/rawlen) as one object */
typedef struct {
	Uint8 dat[0x200];          /* 0x000 */
	Sint32 len;                /* 0x200 */
} SFSEE_VRAW;

/* decoded frame information block handed to the user (SFD_VFRM.inf, 0x80 bytes) */
typedef struct {
	Sint32 width;              /* 0x00 */
	Sint32 height;             /* 0x04 */
	Sint32 mb_width;           /* 0x08 */
	Sint32 mb_height;          /* 0x0C */
	Sint32 pic_type;           /* 0x10 */
	Sint32 ftime;              /* 0x14 */
	Sint32 tunit;              /* 0x18 */
	Sint32 fmt;                /* 0x1C */
	void *buf;                 /* 0x20 */
	Sint32 ndct;               /* 0x24 */
	Sint32 nbyte;              /* 0x28 */
	Sint32 gopno;              /* 0x2C */
	Sint32 x30;
	Sint32 x34;
	SFMPV_PICUSR *picusr;      /* 0x38 */
	Sint32 x3c;
	Sint32 x40;
	Sint32 x44;
	Sint32 pstruct;            /* 0x48 */
	Sint32 x4c;
	Sint64 pts;                /* 0x50 */
	Sint32 x58;
	Sint32 x5c;
	Sint32 x60;
	Sint32 x64;
	Sint16 x68;
	Sint16 x6a;
	Sint8 x6c;
	Sint8 x6d;
	Sint8 x6e;
	Sint8 x6f;
	Sint8 x70;
	Sint8 x71;
	Sint8 x72;
	Sint8 x73;
	Sint8 x74;
	Sint8 x75;
	Sint8 x76;
	Sint8 x77;
	Sint8 x78;
	Sint8 x79;
	Sint8 x7a;
	Uint8 pad7b[5];
} SFMPV_VINF;

/* SFD_VFRM with its first word as the flag the driver keeps there */
typedef struct {
	Sint32 used;               /* 0x00 */
	Sint32 x04;
	SFMPV_VINF inf;            /* 0x08 */
} SFMPV_VFRM;

typedef Sint32 (*SFMPV_ISSKIPFN)(SFD sfd, Sint32 ptype, Sint32 t, Sint32 unit);
typedef Sint32 (*SFMPV_SEQFN)(void *obj, Sint32 width, Sint32 height);
typedef void (*SFMPV_HDRFN)(void *obj, Sint8 *data, Sint32 len);

extern Sint32 SFBUF_RingAddRead(SFD sfd, Sint32 n, Sint32 nbyte);
extern void SFBUF_AddRtotSj(SFD sfd, Sint32 n, Sint32 nbyte);
extern Sint32 SFBUF_RingGetSj(SFD sfd, Sint32 n, SJ *sj);
extern Sint32 SFBUF_GetWTot(SFD sfd, Sint32 n);
extern Sint32 SFBUF_GetRTot(SFD sfd, Sint32 n);
extern Sint32 SFBUF_GetRingBufSiz(SFD sfd, Sint32 n);
extern Sint32 SFBUF_RingGetDataSiz(SFD sfd, Sint32 n);
extern void SFBUF_RingSetDlm(SFD sfd, Sint32 n, Uint8 *pos, Uint8 *end);
extern void SFBUF_RingGetDlm(SFD sfd, Sint32 n, Uint8 **pos, Uint8 **end);
extern void SFBUF_GetFlowCnt(SJ sj, Sint32 *wcnt, Sint32 *rcnt);
extern Sint64 SFBUF_UpdateFlowCnt(Sint64 cnt, Uint32 pos);
extern void SFBUF_SetTermFlg(SFD sfd, Sint32 buf, Sint32 flg);
extern void SFTIM_Tc2Time(SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
extern void SFTIM_InitTtu(SFTIM_TTU *ttu, Sint32 val);
extern Sint32 SFTIM_GetSpeed(SFD sfd);
extern Sint32 SFTIM_GetNextItime(SFTIM tim, Sint32 t);
extern void SFTIM_UpdateItime(SFTIM tim, Sint32 t);
extern void UTY_MemsetDword(void *dst, Uint32 val, Sint32 ndword);
extern Sint64 UTY_MulDivRound64(Sint64 a, Sint64 b, Sint64 c);
extern Sint64 UTY_GetTmr(void);
extern Bool UTY_CmpTime(Sint32 cnt1, Sint32 tscl1, Sint32 cnt2, Sint32 tscl2);
extern void MEM_Copy(void *dst, const void *src, Uint32 nbytes);
extern Sint32 SJRBF_GetFlowCnt(SJ sj, Sint32 id, Sint32 dir);
extern void SFTMR_AddTsum(SFTMR_TSUM *ts, Sint64 t);
extern Sint32 SFPTS_ReadPtsQue(SFD sfd, Sint32 strm, Sint8 *pos, SFPTS_ENT *out);
extern Sint32 SFPLY_GetResetFlg(void);
extern void SFPLY_AddSkipPic(SFD sfd, Sint32 n, Sint32 ptype);
extern void SFPLY_AddDecPic(SFD sfd, Sint32 n, Sint32 ptype);
extern Sint32 SFCON_ReadTotSmplQue(SFD sfd, Sint32 *val, Sint32 *last);
extern void SFCON_UpdateConcatTime(SFD sfd, Sint32 t);
extern Sint32 SFCON_IsVideoEndcodeSkip(SFD sfd);
extern Sint32 MPV_Init(Sint32 nhn, void *work);
extern void MPV_Finish(void);
extern MPV MPV_Create(void);
extern Sint32 MPV_Destroy(MPV mpv);
extern Sint32 MPV_SetErrFunc(MPV mpv, void (*func)(void *obj, Sint32 code), void *obj);
extern Sint32 MPV_SetCond(MPV mpv, Sint32 id, Sint32 val);
extern Sint32 MPV_GetCond(MPV mpv, Sint32 id, Sint32 *val);
extern Sint32 MPV_DecodePicAtr(MPV mpv, SJCK *ck, Sint32 *used);
extern Sint32 MPV_DecodePicAtrSj(MPV mpv, SJ sj);
extern Sint32 MPV_GetPicAtr(MPV mpv, MPV_PICATR *picatr);
extern void MPV_GetPicUsr(MPV mpv, Uint8 **buf, Sint32 *len);
extern void MPV_SetPicUsrBuf(MPV mpv, Uint8 *buf, Sint32 bufsiz);
extern Sint32 MPV_DecodeFrmSj(MPV mpv, SJ sj, SFMPV_MPVFRM *frm);
extern Sint32 MPV_SkipFrmSj(MPV mpv, SJ sj);
extern void MPV_GetDctCnt(MPV mpv, Sint32 *a, Sint32 *b);
extern Sint32 MPV_GetLinkFlg(MPV mpv, Sint32 *flg1, Sint32 *flg2);
extern Sint32 MPV_GetBitRate(MPV mpv, Sint32 *bitrate);
extern Sint32 MPV_GetVbvBufSiz(MPV mpv, Sint32 *bufsiz, Sint32 *delay, Sint32 *delay_byte);
extern Sint8 *MPV_BsearchDelim(Sint8 *p, Sint32 n, Sint32 mask);
extern SFD_VFRM *SFMPVF_SearchVfrmData(SFD sfd, SFMPV_FRM *frm);
extern SFMPV_FRM *SFMPVF_SearchFrmObj(SFD sfd, SFD_VFRM_INF *inf);
extern void SFMPVF_EndDrawFrm(SFMPV_FRM *frm);
extern void SFMPVF_EndRefFrm(SFMPV_FRM *frm);
extern void SFMPVF_RefStbyFrm(SFMPV_FRM *frm);
extern void SFMPVF_StbyFrm(SFMPV_FRM *frm);
extern void SFMPVF_FreeFrm(SFMPV_FRM *frm);
extern SFMPV_FRM *SFMPVF_AllocFrm(SFD sfd);
extern SFMPV_FRM *SFMPVF_HoldFrm(SFD sfd, Sint32 *lastflg);
extern Sint32 SFMPVF_GetNumFrm(SFD sfd);
extern void SFMPVF_SetGopStat(SFD sfd, Sint32 stat);
extern Sint32 SFMPVF_IsTermDec(SFD sfd);
extern void SFMPVF_TermDec(SFD sfd);
extern const SFD_TR_IF SFD_tr_ad_adxt;

Sint32 SFMPV_Init(void);
Sint32 SFMPV_Finish(void);
Sint32 SFMPV_ExecServer(SFD sfd);
static Sint32 SFMPV_Create(void *obj);
Sint32 SFMPV_Destroy(SFD sfd);
Sint32 SFMPV_Standby(SFD sfd);
Sint32 SFMPV_Start(SFD sfd);
Sint32 SFMPV_Stop(SFD sfd);
Sint32 SFMPV_Pause(SFD sfd);
static Sint32 SFMPV_GetWrite(SFD sfd);
Sint32 SFMPV_AddWrite(SFD sfd);
Sint32 SFMPV_GetRead(SFD sfd, SFD_VFRM_INF **inf);
Sint32 SFMPV_AddRead(SFD sfd, SFD_VFRM_INF *inf);
Sint32 SFMPV_Seek(SFD sfd);
void sfmpv_ErrFn(void *obj, Sint32 code);
Sint32 sfmpv_InitInf(SFD sfd, SFMPV_WORK *mpv);
Sint32 sfmpv_ChkBufSiz(SFD sfd, SFMPV_STMINF *inf, Sint32 bitrate, Sint32 vbvsiz);
Sint32 sfmpv_DecodePicAtr(SFD sfd, SJCK *ck, SJ sj, Sint32 mask, Sint32 *result);
Sint32 sfmpv_Concat(SFD sfd, SJ sj);
Sint32 sfmpv_DecodeOneUnit(SFD sfd, Sint32 size, Sint32 code, Sint32 flag, Sint32 *done);
Bool sfmpv_NeedSafeDlmRefresh(SFBUF_RINF *inf, Sint32 code, Uint8 *dlm);
Sint32 sfmpv_GetActiveSize(SFD sfd, Sint32 *size, Sint32 *code, Sint32 *flag);
Sint32 sfmpv_ExecServerSub(SFD sfd);
Sint32 sfmpv_IsSkip(SFD sfd, SJCK *ck);
Sint32 sfmpv_DecodeFrm(SFD sfd, SJ sj);
Sint32 sfmpv_SetFrmPara(SFD sfd, MPV_PICATR *atr, SFMPV_MPVFRM *mfrm, SFMPV_FRM **pfrm);
void sfmpv_SetFrmInf(SFD sfd, SFMPV_FRM *frm, SFMPV_VINF **inf);
Sint32 sfmpv_GoDdelim(SFD sfd, SJ sj, Sint32 mask);
void sfmpv_DoReformTc(SFD sfd, MPV_PICATR *atr, Sint64 pts, Sint32 newgop);
void sfmpv_Pts2Tc(Sint64 pts, Sint32 prate, Sint32 drop, Sint32 tmpref, SFTIM_TC *tc);
Sint32 SFD_SetMpvCond(SFD sfd, Sint32 id, Sint32 val);
void SFD_CalcYccPlane(void *buf, Sint32 width, Sint32 height, SFMPV_PLANE *plane);

static Sint32 sfmpv_ChkFatal(void);
static void sfmpv_DecUsrHdr(SFD sfd, SJCK *ck, Sint32 *used);
static void sfmpv_ChkPrep(SFD sfd);
static inline Bool sfmpv_IsPrepared(SFD sfd);
static inline Bool sfmpv_IsEnoughData(SFD sfd);
static inline Bool sfmpv_IsTerm(SFD sfd, Sint32 size, Sint32 code);
static void sfmpv_CalcRepeatField(SFD sfd, MPV_PICATR *atr, Sint32 newgop);
static inline Bool sfmpv_IsLateSkip(SFD sfd, Sint32 ptype);
static inline Bool sfmpv_IsGopSkip(SFD sfd, Sint32 ptype);
static inline Bool sfmpv_IsEmptySkip(SFD sfd, Sint32 ptype, SJCK *ck);
static inline Bool sfmpv_IsCondSkip(SFD sfd, Sint32 ptype);
static inline Bool sfmpv_IsSeekSkip(SFD sfd);
static Sint32 SFMPV_Create(void *obj);
static inline Sint32 sfmpv_ChkPara(SFMPV_PARA *para);
static Sint32 SFMPV_GetWrite(SFD sfd);
static inline Sint32 sfmpv_SeekVhdr(SFD sfd, Sint32 *flg);
static inline Sint32 sfmpv_ChkRingSpace(SFD sfd);
static inline void sfmpv_SkipEndcode(SFD sfd, SJ sj);
static inline Sint32 sfmpv_SetPicUsrBuf(SFD sfd, void *buf, Sint32 num, Sint32 siz);
static inline void sfmpv_SetFrmTime(SFD sfd, SFMPV_FRM *frm);
static inline void sfmpv_InitFrm(SFMPV_FRM *frm, void **pbuf);
static inline Sint32 sfmpv_CalcFrmSiz(Sint32 width, Sint32 height);
static inline void sfmpv_CalcYccPlane(void *buf, Sint32 width, Sint32 height, SFMPV_PLANE *plane);
static inline void sfmpv_SetPlane(void **pbuf, Sint32 ywidth, Sint32 cwidth, Sint32 ysize, Sint32 csize, SFMPV_PLANE *plane);
static inline Sint32 sfmpv_DlmOfst(SFBUF_RINF *inf, Sint8 *p);
static inline Sint8 *sfmpv_BsearchDlm(SFBUF_RINF *inf, Sint32 mask, Sint32 *code);
static inline Sint8 *sfmpv_SearchDlm(SFBUF_RINF *inf, Sint32 mask, Sint32 *code);
static inline void sfmpv_AddRtot(SFD sfd, Sint32 nbyte);
static inline Sint32 sfmpv_ChkDecRet(SFD sfd, Sint32 ret, Sint32 flow, Sint32 code);

const SFD_TR_IF SFD_tr_vd_mpv = {
	(Sint32 (*)())SFMPV_Init, (Sint32 (*)())SFMPV_Finish, (Sint32 (*)())SFMPV_ExecServer,
	(Sint32 (*)())SFMPV_Create, (Sint32 (*)())SFMPV_Destroy, (Sint32 (*)())SFMPV_Standby,
	(Sint32 (*)())SFMPV_Start, (Sint32 (*)())SFMPV_Stop, (Sint32 (*)())SFMPV_Pause,
	(Sint32 (*)())SFMPV_GetWrite, (Sint32 (*)())SFMPV_AddWrite, (Sint32 (*)())SFMPV_GetRead,
	(Sint32 (*)())SFMPV_AddRead, (Sint32 (*)())SFMPV_Seek,
};

/* frames per second of each SFTIM_prate entry, rounded up */
const Sint32 sfmpv_fps_round[9] = { 0, 24, 24, 25, 30, 30, 50, 60, 60 };
/* drop-frame time code constants: frames per hour, per 10 minutes, in the first minute of a
 * 10-minute block, in the other minutes, before the dropped frames, per second, minutes per block,
 * dropped frames per minute */
const Sint32 sfmpv_conv_29_97[8] = { 107892, 17982, 1800, 1798, 28, 30, 10, 2 };
const Sint32 sfmpv_conv_59_94[8] = { 215784, 35964, 3600, 3596, 56, 60, 10, 4 };

/* `-inline auto,deferred` unit (CRI_CFLAG_OVERRIDES): .text is the reverse of the source order and
 * .bss the reverse of the declaration order */
Uint8 sfmpv_work[0x12020];
SFMPV_PARA sfmpv_para;
void *sfmpv_rfb_adr_tbl[2];
void *sfmpv_ta_adr_tbl[SFMPV_FRM_NUM];
void *sfmpv_picusr_pbuf;
Sint32 sfmpv_picusr_bufnum;
Sint32 sfmpv_picusr_buf1siz;
Sint32 sfmpv_discard_wsiz;

/* buffers for the next creation: reference frames and decoded frames, 32-byte aligned */
void SFD_SetMpvParaTbl(SFMPV_PARA *para, void **rfb, void **tbl)
{
	Sint32 i;

	sfmpv_para = *para;
	sfmpv_para.x10 = 0;
	sfmpv_para.x20 = 0;
	sfmpv_rfb_adr_tbl[0] = (void *)(((Uint32)rfb[0] + 31) & ~31);
	sfmpv_rfb_adr_tbl[1] = (void *)(((Uint32)rfb[1] + 31) & ~31);
	for (i = 0; i < SFMPV_FRM_NUM; i++) {
		if (i < para->nfrm) {
			sfmpv_ta_adr_tbl[i] = (void *)(((Uint32)tbl[i] + 31) & ~31);
		} else {
			sfmpv_ta_adr_tbl[i] = NULL;
		}
	}
}

// Y/Cb/Cr plane addresses and row strides of a planar YCC 4:2:0 buffer of width x height (the MW
// player's mwPlyCalcYccPlane).
void SFD_CalcYccPlane(void *buf, Sint32 width, Sint32 height, SFMPV_PLANE *plane)
{
	sfmpv_CalcYccPlane(buf, width, height, plane);
}

/* a NULL handle sets the decoder's default (MPV_SetCond(NULL, ..)) */
// FUN_0051A1C0
Sint32 SFD_SetMpvCond(SFD sfd, Sint32 id, Sint32 val)
{
	MPV hn;

	if (sfd == NULL) {
		hn = NULL;
	} else {
		if (SFLIB_CheckHn(sfd) != 0) {
			return SFLIB_SetErr(NULL, 0xFF000181);
		}
		hn = SFMPV_WK(sfd)->mpv;
	}
	if (id == 5) {
		val = 0;
	}
	if (MPV_SetCond(hn, id, val) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000F12);
	}
	return 0;
}

// Saves up to 16 MPV decoder conditions into `tbl` (kept across a handle reset).
// FUN_0051A278
Sint32 SFMPV_SaveCond(SFD sfd, Sint32 *tbl, Sint32 size)
{
	MPV hn = SFMPV_WK(sfd)->mpv;
	Sint32 i;
	Sint32 n;

	if (hn == NULL) {
		return 0;
	}
	n = ((Uint32)size / sizeof(Sint32) > 16) ? 16 : (Uint32)size / sizeof(Sint32);
	for (i = 0; i < n; i++) {
		MPV_GetCond(hn, i, &tbl[i]);
	}
	return n;
}

// Restores the MPV decoder conditions saved by SFMPV_SaveCond.
void SFMPV_RestoreCond(SFD sfd, Sint32 *tbl, Sint32 n)
{
	MPV hn = SFMPV_WK(sfd)->mpv;
	Sint32 i;

	if (hn == NULL) {
		return;
	}
	for (i = 0; i < n; i++) {
		MPV_SetCond(hn, i, tbl[i]);
	}
}

// Buffer for the picture user data of the frames in flight (`num` slots of `siz` bytes); the MW
// player passes max_skip + 3 slots of 64 bytes.
Sint32 SFD_SetPicUsrBuf(SFD sfd, void *buf, Sint32 num, Sint32 siz)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000185);
	}
	return sfmpv_SetPicUsrBuf(sfd, buf, num, siz);
}

// Library init: layout checks, MPV decoder init with 8 handles, cleared driver parameters and
// frame-buffer tables.
Sint32 SFMPV_Init(void)
{
	Sint32 ret;

	ret = sfmpv_ChkFatal();
	if (ret != 0) {
		for (;;) {
		}
	}
	ret = MPV_Init(8, sfmpv_work);
	if (ret != 0) {
		return SFLIB_SetErr(NULL, (ret == (Sint32)0xFF03FF05) ? 0xFF000F13 : 0xFF000F01);
	}
	memset(&sfmpv_para, 0, sizeof(sfmpv_para));
	memset(sfmpv_rfb_adr_tbl, 0, sizeof(sfmpv_rfb_adr_tbl));
	memset(sfmpv_ta_adr_tbl, 0, sizeof(sfmpv_ta_adr_tbl));
	sfmpv_discard_wsiz = 0;
	return 0;
}

/* layout assumptions of the driver: CRI's compile-time check idiom (cmptime.c; the sizeof compares
 * are kept). COMPILER-DIFF: M3 - the original keeps it out of line (`bl sfmpv_ChkFatal`), ours
 * auto-inlines it into SFMPV_Init under `-inline auto,deferred`. */
// Compile-time layout checks of the driver (MPV_PICATR 0x80 bytes, ...).
static Sint32 sfmpv_ChkFatal(void)
{
	Sint32 sz1 = sizeof(MPV_PICATR);
	Sint32 sz2 = sizeof(SFSEE_VHDR) - 0x38;
	Sint32 sz3 = sizeof(Sint32);

	if (sz1 != 0x80) {
		return SFLIB_SetErr(NULL, 0xFF000F19);
	}
	if (sz2 > 0x204) {
		return SFLIB_SetErr(NULL, 0xFF000F1A);
	}
	if (sz3 != 4) {
		return SFLIB_SetErr(NULL, 0xFF000F1E);
	}
	return 0;
}

// Library finish: MPV decoder.
Sint32 SFMPV_Finish(void)
{
	MPV_Finish();
	return 0;
}

// Driver ExecServer (SFD_tr_vd_mpv slot 2).
Sint32 SFMPV_ExecServer(SFD sfd)
{
	return sfmpv_ExecServerSub(sfd);
}

// Video decode pass: when video is on and not finished, decodes the user-supplied sequence header
// in PREP, then loops "find the next start-code unit in the video ring -> decode it" (sequence /
// GOP / picture headers, skip or decode pictures into pool frames) until the ring runs dry or a
// frame is complete; updates the flow counter, marks the output prepared once enough frames are
// decoded, and terminates the output when the stream ended and the pool is drained.
Sint32 sfmpv_ExecServerSub(SFD sfd)
{
	Sint32 ret;
	/* address-taken scalars: frame slots top-down in declaration order (used 0x28 .. sj 0xc) */
	Sint32 used;
	Sint32 flag;
	Sint32 code;
	Sint32 done;
	Sint32 size;
	Sint32 rcnt;
	Sint32 wcnt;
	SJ sj;
	SJCK ck;
	Sint32 n;

	if (SFSET_GetCond(sfd, 5) == 0) {
		return 0;
	}
	if (SFBUF_GetTermFlg(sfd, SFMPV_BUFOUT(sfd)) == 1) {
		return 0;
	}
	if (SFSET_GetCond(sfd, 0x1C) != 0 && SFHDS_GetColType(sfd) != -1) {
		SFD_SetMpvCond(sfd, 5, 0);
	}
	if (sfd->stat == 2) {
		sfmpv_DecUsrHdr(sfd, &ck, &used);
	}
	for (;;) {
		ret = sfmpv_GetActiveSize(sfd, &size, &code, &flag);
		if (ret != 0) {
			break;
		}
		ret = sfmpv_DecodeOneUnit(sfd, size, code, flag, &done);
		if (ret != 0) {
			break;
		}
		if (done == 0) {
			break;
		}
	}
	SFBUF_RingGetSj(sfd, SFMPV_BUFIN(sfd), &sj);
	if (sj != NULL) {
		SFBUF_GetFlowCnt(sj, &wcnt, &rcnt);
		SFD_CNT(sfd)->v_flow = SFBUF_UpdateFlowCnt(SFD_CNT(sfd)->v_flow, wcnt);
	}
	sfmpv_ChkPrep(sfd);
	n = SFMPVF_GetNumFrm(sfd);
	if (n == -1 || (SFMPVF_IsTermDec(sfd) && n == 1 && sfd->plyinf.raw[6] != 0)) {
		SFBUF_SetTermFlg(sfd, SFMPV_BUFOUT(sfd), 1);
		if (sfd->plyinf.raw[0] == 0) {
			SFSET_SetCond(sfd, 5, 0);
		}
	}
	return ret;
}

/* decode the sequence header the user supplied before the stream starts. Inlined helper: its
 * locals mpv/hn are created before the later helpers' locals and colour r31/r29 ahead of them
 * (as own locals of ExecServerSub they rank below every temporary: r28/r29). */
static void sfmpv_DecUsrHdr(SFD sfd, SJCK *ck, Sint32 *used)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	MPV hn = mpv->mpv;

	ck->data = (void *)SFSET_GetCond(sfd, 0x5D);
	ck->len = SFSET_GetCond(sfd, 0x5E);
	if (ck->data != NULL && (Uint32)ck->len != 0 && mpv->dlmmask == (SFMPV_DLM_END | SFMPV_DLM_SEQ)) {
		if (MPV_DecodePicAtr(hn, ck, used) == 0) {
			mpv->picstat = 2;
			mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP;
		}
	}
}

/* set the output prepared flag once enough frames are decoded (helper locals bufout/bufin colour
 * r28/r29 before the nested IsPrepared/IsEnoughData locals) */
static void sfmpv_ChkPrep(SFD sfd)
{
	SFTIM tim = SFD_TIM(sfd);
	Sint32 bufout = SFMPV_BUFOUT(sfd);
	Sint32 bufin = SFMPV_BUFIN(sfd);

	if (SFBUF_GetPrepFlg(sfd, bufout) != 1 && SFBUF_GetPrepFlg(sfd, bufin) == 1) {
		if (sfmpv_IsPrepared(sfd)) {
			SFBUF_SetPrepFlg(sfd, bufout, 1);
			if (tim->vofst.val != 0x7FFFFFFF) {
				tim->vofst.valid = 1;
			}
		}
	}
}

/* the driver is ready to play when enough frames are decoded */
static inline Bool sfmpv_IsPrepared(SFD sfd)
{
	Sint32 n;
	Sint32 nfrm;

	if (SFMPVF_IsTermDec(sfd)) {
		return TRUE;
	}
	n = sfd->cond[0x17];
	nfrm = sfd->prm.x2c;
	if (n == -1) {
		n = nfrm;
	}
	if (nfrm < n) {
		n = nfrm;
	}
	if (SFMPVF_GetNumFrm(sfd) >= n && sfmpv_IsEnoughData(sfd)) {
		return TRUE;
	}
	return FALSE;
}

/* enough data buffered to start decoding */
static inline Bool sfmpv_IsEnoughData(SFD sfd)
{
	Sint32 n;                  /* declared first: coloured after mpv/hn (r27 after their r29/r27) */
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	MPV hn = mpv->mpv;
	Sint32 bitrate;
	Sint32 rsiz;

	if (SFBUF_GetTermFlg(sfd, SFMPV_BUFIN(sfd)) == 1) {
		return TRUE;
	}
	if (sfd->fhd.valid != 0 && sfd->fhd.vid.ftr_fixflg == 0) {
		return TRUE;
	}
	MPV_GetBitRate(hn, &bitrate);
	if (bitrate == 0x3FFFF) {
		return TRUE;
	}
	if (SFBUF_GetWTot(sfd, 1) >= mpv->vbvsiz) {
		return TRUE;
	}
	n = (SFTRN_IsSetup(sfd, 1) == 0);
	rsiz = SFBUF_GetRingBufSiz(sfd, n);
	if (SFBUF_GetWTot(sfd, n) >= rsiz) {
		return TRUE;
	}
	return FALSE;
}

/* size of the unit at the read position: a start code (4 bytes, `code` set) or the data before
 * the next one (`flag` set when data has to be skipped) */
Sint32 sfmpv_GetActiveSize(SFD sfd, Sint32 *size, Sint32 *code, Sint32 *flag)
{
	SFBUF_RINF inf;
	Sint32 bufin = SFMPV_BUFIN(sfd);
	Sint8 *p;
	Sint32 dcode;
	Uint8 *dlm;
	Uint8 *dlmend;
	Uint8 *end;
	Sint32 dummy;
	Sint32 ret;
	Sint32 n;

	*size = 0;
	*code = 0;
	*flag = 0;
	ret = SFBUF_RingGetRead(sfd, bufin, &inf);
	if (ret != 0) {
		return ret;
	}
	if (inf.ck1.len == 0) {
		return 0;
	}
	dcode = 0;
	p = sfmpv_SearchDlm(&inf, SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC | SFMPV_DLM_SLICE, &dcode);
	if (p != (Sint8 *)inf.ck1.data) {
		if (p != NULL) {
			*size = sfmpv_DlmOfst(&inf, p);
		} else {
			n = inf.ck1.len + inf.ck2.len - 3;
			*size = (n < 0) ? 0 : n;
		}
		if (*size > 0) {
			*flag = 1;
		}
		return 0;
	}
	*code = dcode;
	*size = 4;
	if (dcode & SFMPV_DLM_END) {
		return 0;
	}
	/* the next start code, remembered across calls */
	SFBUF_RingGetDlm(sfd, bufin, &dlm, &dlmend);
	if (sfmpv_NeedSafeDlmRefresh(&inf, dcode, dlm)) {
		dlm = NULL;
		if (inf.ck2.len == 0) {
			end = (Uint8 *)inf.ck1.data + inf.ck1.len;
		} else {
			end = (Uint8 *)inf.ck2.data + inf.ck2.len;
		}
		if (dlmend != end) {
			dlmend = end;
			p = sfmpv_BsearchDlm(&inf, SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC, &dummy);
			dlm = (Uint8 *)p;
			SFBUF_RingSetDlm(sfd, bufin, (Uint8 *)p, dlmend);
		}
	}
	if (dlm == NULL) {
		return sfmpv_ChkRingSpace(sfd);
	}
	switch (MPV_CheckDelim(dlm)) {
	case SFMPV_DLM_GOP:
		if (dcode & SFMPV_DLM_SEQ) {
			p = sfmpv_SearchDlm(&inf, SFMPV_DLM_GOP, &dummy);
			if (p == NULL || (Uint8 *)p == dlm) {
				return sfmpv_ChkRingSpace(sfd);
			}
		}
		break;
	case SFMPV_DLM_PIC:
		if (dcode & (SFMPV_DLM_SEQ | SFMPV_DLM_GOP)) {
			p = sfmpv_SearchDlm(&inf, SFMPV_DLM_PIC, &dummy);
			if (p == NULL || (Uint8 *)p == dlm) {
				return sfmpv_ChkRingSpace(sfd);
			}
		}
		break;
	case SFMPV_DLM_SEQ:
	case SFMPV_DLM_END:
	default:
		break;
	}
	*size = sfmpv_DlmOfst(&inf, (Sint8 *)dlm);
	return 0;
}

/* the delimiter remembered by the ring buffer is no longer the next start code */
Bool sfmpv_NeedSafeDlmRefresh(SFBUF_RINF *inf, Sint32 code, Uint8 *dlm)
{
	Uint8 tmp[4];
	Sint32 n;
	Sint32 dcode;
	Sint32 dummy;
	Sint8 *p;

	if (dlm == NULL) {
		return TRUE;
	}
	if (dlm == (Uint8 *)inf->ck1.data) {
		return TRUE;
	}
	if (dlm > (Uint8 *)inf->ck1.data) {
		if (dlm - (Uint8 *)inf->ck1.data <= 3) {
			return TRUE;
		}
	}
	if (dlm >= (Uint8 *)inf->ck1.data && dlm < (Uint8 *)inf->ck1.data + inf->ck1.len) {
		n = (dlm + 4) - ((Uint8 *)inf->ck1.data + inf->ck1.len);
		if (n > 0) {
			if (n > inf->ck2.len) {
				return TRUE;
			}
			memcpy(tmp, dlm, 4 - n);
			memcpy(tmp + 4 - n, inf->ck2.data, n);
		} else {
			memcpy(tmp, dlm, 4);
		}
	} else if (dlm >= (Uint8 *)inf->ck2.data && dlm < (Uint8 *)inf->ck2.data + inf->ck2.len) {
		n = (dlm + 4) - ((Uint8 *)inf->ck2.data + inf->ck2.len);
		if (n > 0) {
			return TRUE;
		}
		memcpy(tmp, dlm, 4);
	} else {
		return TRUE;
	}
	dcode = MPV_CheckDelim(tmp);
	switch (dcode) {
	case SFMPV_DLM_SEQ:
	case SFMPV_DLM_END:
		break;
	case SFMPV_DLM_GOP:
		if ((code & SFMPV_DLM_SEQ) == 0) {
			break;
		}
		p = sfmpv_SearchDlm(inf, SFMPV_DLM_GOP, &dummy);
		if (p == NULL || (Uint8 *)p == dlm) {
			return TRUE;
		}
		break;
	case SFMPV_DLM_PIC:
		if ((code & (SFMPV_DLM_SEQ | SFMPV_DLM_GOP)) == 0) {
			break;
		}
		p = sfmpv_SearchDlm(inf, SFMPV_DLM_PIC, &dummy);
		if (p == NULL || (Uint8 *)p == dlm) {
			return TRUE;
		}
		break;
	default:
		return TRUE;
	}
	return FALSE;
}

/* skip the picture at the read position (the decoder parses it without output) */
static inline Sint32 sfmpv_SkipPic(SFD sfd, SJ sj)
{
	SFMPV_WORK *wk = SFMPV_WK(sfd);
	SFTIM tim = SFD_TIM(sfd);
	SFTIM_TTU *ttu3 = &tim->ttu3;
	SFTIM_TTU *vstart = &tim->vstart;
	MPV hn; /* declared after ttu3/vstart: scanned after them, 27 neighbours left = level 1 (r25) */
	Sint32 flow;
	Sint32 ret;
	Sint32 err;

	hn = wk->mpv;

	if (ttu3->val < tim->vofst.val) {
		*vstart = *ttu3;
	}
	flow = SJRBF_GetFlowCnt(sj, 0, 1);
	ret = MPV_SkipFrmSj(hn, sj);
	flow = SJRBF_GetFlowCnt(sj, 0, 1) - flow;
	err = sfmpv_ChkDecRet(sfd, ret, flow, 0xFF000F07);
	sfmpv_AddRtot(sfd, flow);
	switch (err) {
	case 0:
		if (((MPV_PICATR *)wk->picatr)->x58 == 0) {
			wk->skipret = 1;
		}
		SFPLY_AddSkipPic(sfd, 1, ((MPV_PICATR *)wk->picatr)->pic_type);
		err = 0;
		break;
	}
	return err;
}

/* decode one start-code-delimited unit at the read position */
Sint32 sfmpv_DecodeOneUnit(SFD sfd, Sint32 size, Sint32 code, Sint32 flag, Sint32 *done)
{
	/* ret and tot declared before mpv: coloured before it (ret r30, tot r31, mpv r29) */
	Sint32 ret;
	SFTIM_TTU *tot;
	SFMPV_WORK *mpv;
	SFTIM tim = SFD_TIM(sfd);
	Sint32 bufin;
	SJ sj;
	Sint32 res;
	SJCK ck;
	SFBUF_RINF rinf;
	SFBUF_RINF rinf2;

	*done = 0;
	mpv = SFMPV_WK(sfd);
	bufin = SFMPV_BUFIN(sfd);
	sfd->plyinf.raw[9] = 0;
	if (mpv->dlmmask != (SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC) || mpv->dlmwait == 0) {
		code &= SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC;
	}
	ret = SFBUF_RingGetSj(sfd, bufin, &sj);
	if (ret != 0) {
		return 0;
	}
	if (sj == NULL) {
		return 0;
	}
	if (code & (SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP)) {
		SFMPVF_SetGopStat(sfd, 1);
	}
	if (code == SFMPV_DLM_END) {
		Sint32 n = SFMPV_BUFIN(sfd); /* loaded before the test (not substituted across the branch) */
		tot = &tim->tot;
		if (sfd->tr[SFMPV_TR].x20 < 0) {
			sfd->tr[SFMPV_TR].x20 = SFBUF_GetRTot(sfd, n) + 4;
		}
		if (tot->val < 0) {
			*tot = tim->ttu1;
		}
	}
	if (code == SFMPV_DLM_END && SFCON_IsEndcodeSkip(sfd) != 0) {
		if (sfmpv_Concat(sfd, sj) == 0) {
			*done = 1;
		}
	} else if (code == SFMPV_DLM_END && SFCON_IsVideoEndcodeSkip(sfd) != 0) {
		sfmpv_SkipEndcode(sfd, sj);
		*done = 1;
	} else if (flag == 0 && sfmpv_IsTerm(sfd, size, code)) {
		SFMPVF_TermDec(sfd);
	} else if (flag == 0 && size <= 4) {
		sfd->plyinf.raw[9] = 1;
	} else if (code & (SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC)) {
		if (SFBUF_RingGetRead(sfd, SFMPV_BUFIN(sfd), &rinf) != 0) {
			ck.data = NULL;
			ck.len = 0;
		} else {
			ck = rinf.ck1;
		}
		ret = sfmpv_DecodePicAtr(sfd, &ck, sj, code, &res);
		if (ret != 0) {
			return ret;
		}
		if (res == 0) {
			if (code & mpv->dlmmask) {
				mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC;
			}
			mpv->dlmwait = 1;
		}
		if (code == SFMPV_DLM_SEQ && res == -2) {
			mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ;
		}
		*done = 1;
	} else if (code & SFMPV_DLM_SLICE) {
		if (SFBUF_RingGetRead(sfd, SFMPV_BUFIN(sfd), &rinf2) != 0) {
			ck.data = NULL;
			ck.len = 0;
		} else {
			ck = rinf2.ck1;
		}
		if (sfmpv_IsSkip(sfd, &ck)) {
			ret = sfmpv_SkipPic(sfd, sj);
			if (ret == 0) {
				*done = 1;
			}
		} else {
			ret = sfmpv_DecodeFrm(sfd, sj);
		}
	} else if (code != SFMPV_DLM_END) {
		if (sfmpv_GoDdelim(sfd, sj, SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP | SFMPV_DLM_PIC) > 0) {
			*done = 1;
		}
	}
	return ret;
}

/* the sequence end code: the stream ends unless data follows */
static inline Bool sfmpv_IsTerm(SFD sfd, Sint32 size, Sint32 code)
{
	if (code == SFMPV_DLM_END) {
		return TRUE;
	}
	if (size <= 4 && SFBUF_GetTermFlg(sfd, SFMPV_BUFIN(sfd)) == 1) {
		return TRUE;
	}
	return FALSE;
}

/* a sequence end code inside a concatenated file: the next file continues the time line */
/* The arithmetic block is DoReformTc's (in-place `op=` chain, `f %= rnd`); the time tests are
 * separate `if`s reached through labels: the cond-6 paths jump straight to `t > 0` and only the
 * sample-count path tests `t < 0` (two `cmpwi r4, 0` in the target, one CSE'd compare otherwise). */
Sint32 sfmpv_Concat(SFD sfd, SJ sj)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	SFTIM tim = SFD_TIM(sfd);
	Sint32 t;
	Sint32 rnd;
	Sint32 field;
	Sint32 f;
	Sint32 sec;
	Sint32 min;
	Sint32 hour;
	Sint32 type;
	Sint32 fld;
	SFTIM_TC tc;
	Sint32 tscale;
	Sint32 ncount;
	Sint32 unit;
	Sint32 smpl;
	Sint32 ret;
	Sint32 tunit;

	if (SFSET_GetCond(sfd, 6) == 0) {
		SFTIM_TTU *ttu1 = &tim->ttu1;
		SFTIM_TTU *ttu0 = &tim->ttu0;
		if (ttu1->valid == 0) {
			t = 0;
		} else {
			type = ttu1->tc.type;
			rnd = sfmpv_fps_round[type];
			fld = ttu1->tc.x1c + ttu1->tc.field;
			f = ttu1->tc.frm + ttu1->tc.frm2 + 1;
			f += fld / 2;
			field = fld % 2;
			hour = ttu1->tc.hour;
			min = ttu1->tc.min;
			sec = ttu1->tc.sec;
			sec += f / rnd;
			f %= rnd;
			min += sec / 60;
			sec %= 60;
			hour += min / 60;
			min %= 60;
			if (ttu1->tc.drop != 0 && sec == 0 && min % 10 != 0 && (f == 0 || f == 1)) {
				f = 2;
			}
			tc.type = type;
			tc.drop = ttu1->tc.drop;
			tc.hour = hour;
			tc.min = min;
			tc.sec = sec;
			tc.frm = f;
			tc.field = (Sint16)field;
			tc.frm2 = 0;
			SFTIM_Tc2Time(&tc, &ncount, &tscale);
			t = ncount - ttu0->val;
		}
	} else {
		if (((const SFD_TR_IF **)sfd->prm.x00)[3] != &SFD_tr_ad_adxt) {
			smpl = 0;
			unit = 44100;
		} else if (SFCON_ReadTotSmplQue(sfd, &smpl, &unit) == 0) {
			t = -1;
			goto neg;
		}
		tunit = tim->ttu0.unit;
		tim->x1f0 += smpl;
		t = UTY_MulDiv(tim->x1f0, tunit, unit) - tim->ctime;
		if (t < 0) {
			t = 0;
		}
neg:
		if (t < 0) {
			ret = -1;
			goto chk;
		}
	}
	if (t > 0) {
		SFCON_UpdateConcatTime(sfd, t);
		mpv->nconcat++;
	}
	SFTIM_InitTtu(&tim->ttu0, 0x7FFFFFFF);
	SFTIM_InitTtu(&tim->ttu1, -1);
	mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ;
	ret = 0;
chk:
	if (ret == -1) {
		return -1;
	}
	sfmpv_SkipEndcode(sfd, sj);
	return 0;
}

/* the GOP time code disagrees with the running time: reform the time codes. Inlined helper so that
 * `flag` is a helper local: its `li 0` is CSE'd with the zero of the caller's 64-bit `d < 0` compare
 * (one `li r5, 0`), and the emptied `valid == 0` THEN arm leaves the target's `bne body; b test`
 * pair (an emptied ELSE arm folds to a plain `beq`). t1/t2/unit declared in this order = slots 8/c/10. */
static inline Sint32 sfmpv_ChkGopTc(SFD sfd)
{
	SFTIM tim = SFD_TIM(sfd);
	SFTIM_TTU *ttu1 = &tim->ttu1;
	SFTIM_TC tc;
	Sint32 t1;
	Sint32 t2;
	Sint32 unit;
	Sint32 k;
	Sint32 flag;

	if (ttu1->valid == 0) {
		flag = 0;
	} else {
		tc = tim->tc;
		SFTIM_Tc2Time(&tc, &t1, &unit);
		SFTIM_Tc2Time(&ttu1->tc, &t2, &unit);
		k = unit * SFSET_GetCond(sfd, 0x35);
		if (t1 <= t2) {
			flag = 1;
		} else if (t1 >= t2 + k) {
			flag = 1;
		} else {
			flag = 0;
		}
	}
	return flag;
}

/* reform the time codes when the GOP time code disagrees with the running time. Inlined helper so
 * that `reform` (last declared) outranks the reloaded `newgop` and ChkGopTc's `ttu1` in the colouring
 * (reform r17, newgop r18, ttu1 r19); as own locals of DecodePicAtr they colour in the other order. */
static inline void sfmpv_ReformTc(SFD sfd, SFMPV_WORK *mpv, MPV_PICATR *atr, Sint64 d)
{
	Sint32 newgop = mpv->newgop;
	Sint32 reform;

	reform = SFSET_GetCond(sfd, 0x34);
	if (reform == 0) {
		if (d < 0 && atr->ngop != 0 && atr->x57 == 0) {
			if (newgop == 0) {
				goto reform_chk;
			}
			if (sfmpv_ChkGopTc(sfd) == 0) {
				goto reform_chk;
			}
		}
		SFSET_SetCond(sfd, 0x34, 1);
		reform = 1;
	}
reform_chk:
	if (reform == 1) {
		sfmpv_DoReformTc(sfd, atr, d, newgop);
	}
}

/* decode a sequence / GOP / picture header and derive the picture's time */
Sint32 sfmpv_DecodePicAtr(SFD sfd, SJCK *ck, SJ sj, Sint32 mask, Sint32 *result)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	MPV hn = mpv->mpv;
	MPV_PICATR *atr = (MPV_PICATR *)mpv->picatr;
	SFTIM tim = SFD_TIM(sfd);
	SFMPV_STMINF *inf;
	SFMPV_WORK *wk;
	SFSEE_WORK *swk;
	SFSEE_VHDR *vhdr;
	Sint32 bufin;
	/* frame layout: aggregates and address-taken scalars in the REVERSE of the natural order (first
	 * declared = highest slot): tc2 0x88, tc3 0x68, tc 0x48, ent 0x38; tscale0 0x30 .. t1 0x8. The two
	 * Tc2Time out-parameter pairs are distinct variables (two more slots, frame 0xf0). */
	SFTIM_TC tc2;
	SFTIM_TC tc3;
	SFPTS_ENT ent;
	Sint32 flow;
	Sint32 err;
	Sint32 ret;
	Sint32 seq;
	Sint32 last;
	Sint32 newgop;
	Sint8 *p;
	Sint64 pts;
	Sint64 d;
	Sint64 t;
	Sint32 prate;
	Sint32 tmpref;
	Sint32 k;
	Sint32 tscale0;
	Sint32 ncount0;
	Sint32 tscale;
	Sint32 ncount;
	Sint32 delay_byte;
	Sint32 delay;
	Sint32 vbvsiz;
	Sint32 bitrate;
	Sint32 rsiz;
	Sint32 n;
	Sint32 len;
	Sint32 br;
	Sint32 vb;
	SFSEE_VRAW *raw;
	SFTIM_TTU *ttu0;
	SFMPV_SEQFN seqfn;
	void *seqobj;
	SFMPV_HDRFN hdrfn;
	void *hdrobj;

	mpv->picusr_len = 0;
	MPV_SetPicUsrBuf(hn, mpv->picusr_dat, mpv->picusr_siz);
	flow = SJRBF_GetFlowCnt(sj, 0, 1);
	*result = MPV_DecodePicAtrSj(hn, sj);
	flow = SJRBF_GetFlowCnt(sj, 0, 1) - flow;
	err = sfmpv_ChkDecRet(sfd, *result, flow, 0xFF000F04);
	sfmpv_AddRtot(sfd, flow);
	if (err != 0) {
		return err;
	}
	if (*result == -2) {
		return 0;
	}
	ret = MPV_GetPicAtr(hn, atr);
	*result = ret;
	if (ret != 0) {
		return SFLIB_SetErr(sfd, 0xFF000F05);
	}
	seq = mask & SFMPV_DLM_SEQ;
	if (seq) {
		/* a size change is a stream error */
		inf = (SFMPV_STMINF *)&sfd->x90c;
		if (inf->width > 0 && (inf->width != atr->width || inf->height != atr->height)) {
			*result = -2;
			return 0;
		}
		seqfn = (SFMPV_SEQFN)SFSET_GetCond(sfd, 0x5F);
		seqobj = (void *)SFSET_GetCond(sfd, 0x5F);
		if (seqfn != NULL && seqfn(seqobj, atr->width, atr->height) != 0) {
			*result = -2;
			return 0;
		}
	}
	/* a P picture before / a B picture after its backward reference repeats the reference */
	if (atr->pic_type == 1) {
		mpv->tmpref_adj = 0;
	} else if (sfd->prm.x38 == 3 && mpv->ref[1] != NULL) {
		last = mpv->ref[1]->tmpref;
		if (atr->pic_type == 2) {
			if (atr->temp_ref < last && last < 0x200) {
				mpv->tmpref_adj = 1;
			}
		} else if (atr->pic_type == 3) {
			if (atr->temp_ref >= last) {
				mpv->tmpref_adj = 1;
			}
		}
	}
	MPV_GetPicUsr(hn, NULL, &mpv->picusr_len);
	if (mpv->last_ngop != atr->ngop) {
		mpv->last_ngop = atr->ngop;
		mpv->newgop = 1;
	} else {
		mpv->newgop = 0;
	}
	if (seq) {
		hdrfn = (SFMPV_HDRFN)SFSET_GetCond(sfd, 0x4D);
		hdrobj = (void *)SFSET_GetCond(sfd, 0x4E);
		if (hdrfn != NULL) {
			p = MPV_SearchDelim((Sint8 *)ck->data, ck->len, 1);
			if (p != NULL) {
				hdrfn(hdrobj, (Sint8 *)ck->data, (p + 4) - (Sint8 *)ck->data);
			}
		}
	}
	/* PTS of the picture */
	p = MPV_SearchDelim((Sint8 *)ck->data, ck->len, SFMPV_DLM_PIC);
	newgop = mpv->newgop;
	wk = SFMPV_WK(sfd);
	bufin = SFMPV_BUFIN(sfd);
	d = -1;
	pts = -1;
	if (p != NULL) {
		SFPTS_ReadPtsQue(sfd, bufin, p, &ent);
		if (ent.pts >= 0) {
			/* the running time is computed in a block-scoped `dd` and copied to `d` at the block end:
			 * the frontend splits dd (the subtraction) from its clamped web, the low word of `d = dd`
			 * is coalesced and the high word stays a copy (target `mr r22, r21`), d keeps the -1 init in
			 * r20/r22. A single `d` is range-split into a pair that outranks wk/prate/tmpref (r25/r26,
			 * one more callee-saved register). tmpref/prate are loaded before the origin test. */
			Sint64 dd;

			tmpref = atr->temp_ref;
			prate = SFTIM_prate[atr->frame_rate];
			if (!(tim->x150 >= 0)) {
				/* the first PTS seen fixes the origin */
				t = ent.pts - (Sint64)tmpref * 90000000 / prate;
				t = (t > 0) ? t : 0;
				tim->x150 = t;
			}
			dd = ent.pts - tim->x150;
			dd = (dd > 0) ? dd : 0;
			if (memcmp(&wk->ptsent, &ent, 4) != 0) {
				wk->ptsent = ent;
				wk->pts_ofst = 0;
				wk->pts_tmpref = tmpref;
				if (atr->pic_type == 3) {
					wk->pts_max = 1;
				} else {
					wk->pts_max = 0;
				}
				pts = ent.pts;
			} else {
				if (newgop) {
					wk->pts_ofst += wk->pts_max + 1;
					wk->pts_max = 0;
					wk->pts_tmpref = 0;
				}
				k = tmpref - wk->pts_tmpref;
				wk->pts_max = (wk->pts_max > k) ? wk->pts_max : k;
				dd += (Sint64)(wk->pts_ofst + k) * 90000000 / prate;
				dd = (dd > 0) ? dd : 0;
			}
			d = dd;
		}
	}
	mpv->pts = pts;
	if ((mask & mpv->dlmmask) == 0) {
		return 0;
	}
	sfmpv_CalcRepeatField(sfd, atr, mpv->newgop);
	sfmpv_ReformTc(sfd, mpv, atr, d);
	/* video start time */
	/* the three SFTIM_TTU blocks are addressed through pointer locals (struct copies through a kept
	 * base: ttu0 r17 before its test, ttu1/ttu3 for the picture time and the ttu1 = ttu3 copy) */
	ttu0 = &tim->ttu0;
	if (ttu0->valid == 0) {
		tc2 = tim->tc;
		tc2.frm2 = 0;
		SFTIM_Tc2Time(&tc2, &ncount0, &tscale0);
		ttu0->tc = tc2;
		ttu0->val = ncount0;
		ttu0->unit = tscale0;
		ttu0->valid = 1;
	}
	/* time of this picture */
	{
		/* declaration order gives the colours (ttu3 r18, ttu1b r17), statement order the addi order */
		SFTIM_TTU *ttu3;
		SFTIM_TTU *ttu1b;

		ttu1b = &tim->ttu1;
		ttu3 = &tim->ttu3;
		tc3 = tim->tc;
		SFTIM_Tc2Time(&tc3, &ncount, &tscale);
		ttu3->tc = tc3;
		ttu3->val = ncount - tim->ttu0.val;
		ttu3->unit = tscale;
		ttu3->valid = 1;
		if (ttu1b->val <= ttu3->val) {
			*ttu1b = *ttu3;
		}
	}
	/* stream information from the sequence header */
	inf = (SFMPV_STMINF *)&sfd->x90c;
	wk = SFMPV_WK(sfd);
	if (inf->bitrate != 0) {
		return 0;
	}
	if (MPV_GetBitRate(hn, &bitrate) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000F16);
	}
	MPV_GetVbvBufSiz(hn, &vbvsiz, &delay, &delay_byte);
	if (SFSET_GetCond(sfd, 0x3C) == 0) {
		wk->vbvsiz = 0;
	} else {
		rsiz = SFBUF_GetRingBufSiz(sfd, 1);
		if (delay_byte == -1) {
			delay_byte = vbvsiz;
		}
		if (delay_byte < rsiz) {
			rsiz = delay_byte;
		}
		wk->vbvsiz = rsiz;
	}
	br = bitrate;
	/* both pointers loaded before the test (`swk` r4 / the mpv reload r3: swk is the later-declared
	 * own local, wk's second definition a range-split copy coloured before it); the header bytes and
	 * their length through the SFSEE_VRAW view (`stw/lwz 0x200(raw)`), `len` a local declared after
	 * `n` so that n colours r0 and the length r4 */
	swk = sfd->see.wk;
	wk = SFMPV_WK(sfd);
	if (swk == NULL) {
		vhdr = NULL;
	} else if (wk->nconcat > 0) {
		vhdr = NULL;
	} else {
		vhdr = (SFSEE_VHDR *)&swk->a1hdr;
	}
	if (vhdr != NULL && vhdr->analyzed == 0) {
		raw = (SFSEE_VRAW *)vhdr->raw;
		len = ck->len;
		n = 0x200;
		if (len < 0x200) {
			n = len;
		}
		raw->len = n;
		MEM_Copy(raw->dat, ck->data, raw->len);
		if (br == 0x3FFFF) {
			vhdr->byterate = 0;
			vhdr->tunit = 0;
		} else {
			vhdr->byterate = br * 50;
			vhdr->tunit = 1;
		}
		vhdr->ttu = tim->ttu0;
		vhdr->analyzed = 1;
	}
	vb = vbvsiz;
	br = bitrate;
	inf->width = atr->width;
	inf->height = atr->height;
	inf->mb_width = atr->mb_width;
	inf->mb_height = atr->mb_height;
	inf->picrate = atr->frame_rate;
	inf->bitrate = br;
	inf->vbvsiz = vb;
	return sfmpv_ChkBufSiz(sfd, inf, br, vb);
}

/* repeat_first_field accounting: the field offset of each picture of the GOP */
static void sfmpv_CalcRepeatField(SFD sfd, MPV_PICATR *atr, Sint32 newgop)
{
	SFMPV_FRM *ref;
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	SFTIM tim = SFD_TIM(sfd);
	SFMPV_RFLD *rfld = (SFMPV_RFLD *)tim->rfld;
	Sint32 i;
	Sint32 idx;
	Sint32 t;
	Sint32 last;
	Sint32 cur;
	Sint32 j;
	Sint32 tscale;
	Sint32 ncount;

	tim->tc.type = atr->frame_rate;
	tim->tc.drop = atr->tc_drop;
	tim->tc.hour = atr->tc_hour;
	tim->tc.min = atr->tc_min;
	tim->tc.sec = atr->tc_sec;
	tim->tc.frm = atr->tc_pic;
	tim->tc.frm2 = atr->temp_ref;
	tim->tc.x1c = atr->x54;
	tim->tc.field = 0;
	if (newgop != 0) {
		for (i = 0; i < 64; i++) {
			rfld[i].rpt = -1;
		}
		rfld[0].acc = -1;
	} else if (atr->pic_type == 1 || atr->pic_type == 2) {
		ref = mpv->ref[1];
		cur = atr->temp_ref;
		last = ref->tmpref;
		if (cur < last) {
			cur += 0x400;
		}
		for (t = last + 1; t < cur; t++) {
			rfld[t % 64].rpt = -1;
		}
	}
	idx = atr->temp_ref % 64;
	rfld[idx].rpt = tim->tc.x1c;
	if (newgop != 0) {
		rfld[idx].acc = 0;
	} else if (atr->temp_ref == 0 && rfld[0].acc == -1) {
		rfld[0].acc = 0;
	} else {
		for (i = 0; i < 64; i++) {
			j = (idx - i + 63) % 64;
			if (rfld[j].rpt != -1) {
				rfld[idx].acc = rfld[j].rpt + rfld[j].acc;
				break;
			}
		}
	}
	tim->tc.field = rfld[idx].acc;
	if (atr->pic_type == 3 && rfld[idx].rpt != 0) {
		/* a repeated field of a B picture delays the backward reference */
		j = mpv->ref[1]->tmpref % 64;
		rfld[j].acc = rfld[idx].rpt + rfld[idx].acc;
		mpv->ref[1]->ttu.tc.field = rfld[j].acc;
		ref = mpv->ref[1];
		SFTIM_Tc2Time(&ref->ttu.tc, &ncount, &tscale);
		ref->ttu.val = ncount - tim->ttu0.val;
		ref->ttu.unit = tscale;
		ref->ttu.valid = 1;
		if (tim->ttu1.val <= ref->ttu.val) {
			tim->ttu1 = ref->ttu;
		}
		sfmpv_SetFrmTime(sfd, mpv->ref[1]);
	}
}

/* time code of the picture: from its PTS, or the previous picture's advanced by one frame.
 * The running values are loaded into their own variables and advanced with compound assignments
 * (`sec += ..; sec %= 60`): a plain `sec = sec % 60` after a use is range-split by the frontend into
 * a temporary that costs a fourth callee-saved register, while `x op= e` keeps one node whose range
 * starts at the load (>= 29 neighbours -> coloured before the temporaries). The frame count is the
 * reduced `f` itself (`f %= rnd`), the empty-else `return` gives the second `b end`. */
void sfmpv_DoReformTc(SFD sfd, MPV_PICATR *atr, Sint64 pts, Sint32 newgop)
{
	Sint32 prate = atr->frame_rate;
	Sint32 drop = atr->tc_drop;
	Sint32 rnd;
	Sint32 field;
	Sint32 f;
	Sint32 sec;
	Sint32 min;
	Sint32 hour;
	Sint32 type;
	SFTIM tim = SFD_TIM(sfd);
	Sint32 tmpref = atr->temp_ref;
	Sint32 fld;

	if (newgop != 0 && pts >= 0) {
		sfmpv_Pts2Tc(pts, prate, drop, tmpref, &tim->tc);
	} else if (tim->ttu1.valid == 0) {
		if (sfd->see.wk == NULL) {
			tim->tc.type = prate;
			tim->tc.drop = 0;
			tim->tc.hour = 0;
			tim->tc.min = 0;
			tim->tc.sec = 0;
			tim->tc.frm = 0;
		} else {
			return;
		}
	} else if (newgop != 0) {
		type = tim->ttu1.tc.type;
		rnd = sfmpv_fps_round[type];
		fld = tim->ttu1.tc.x1c + tim->ttu1.tc.field;
		f = tim->ttu1.tc.frm + tim->ttu1.tc.frm2 + 1;
		f += fld / 2;
		field = fld % 2;
		hour = tim->ttu1.tc.hour;
		min = tim->ttu1.tc.min;
		sec = tim->ttu1.tc.sec;
		sec += f / rnd;
		f %= rnd;
		min += sec / 60;
		sec %= 60;
		hour += min / 60;
		min %= 60;
		if (tim->ttu1.tc.drop != 0 && sec == 0 && min % 10 != 0 && (f == 0 || f == 1)) {
			f = 2;
		}
		tim->tc.type = type;
		tim->tc.drop = tim->ttu1.tc.drop;
		tim->tc.hour = hour;
		tim->tc.min = min;
		tim->tc.sec = sec;
		tim->tc.frm = f;
		tim->tc.field = (Sint16)field;
		tim->rfld[0].acc = tim->tc.field;
		tim->rfld[tmpref].acc = tim->tc.field;
	} else {
		tim->tc.type = tim->ttu1.tc.type;
		tim->tc.drop = tim->ttu1.tc.drop;
		tim->tc.hour = tim->ttu1.tc.hour;
		tim->tc.min = tim->ttu1.tc.min;
		tim->tc.sec = tim->ttu1.tc.sec;
		tim->tc.frm = tim->ttu1.tc.frm;
	}
}

/* time code of a picture from its PTS (90 kHz).
 * COMPILER-DIFF: M2 - the original addresses the three .rodata tables with separate lis/addi pairs;
 * deferred codegen pools them through a `...rodata.0` base (the tables were not yet defined, or the
 * function was compiled non-deferred, when CRI built it). `pool_data off` around the function
 * reproduces the target byte for byte; `hour` declared last (level 2 -> r0), `tbl` a ternary (no
 * ECOND copies), `rnd` before `rate`, `fno` before the field store. */
// Converts a 90 kHz PTS plus the picture's temporal reference into a timecode (h:m:s:frame, drop
// frame aware) at the given frame rate; the frame's display time is derived from it.
void sfmpv_Pts2Tc(Sint64 pts, Sint32 prate, Sint32 drop, Sint32 tmpref, SFTIM_TC *tc)
{
	Sint32 rnd = sfmpv_fps_round[prate];
	Sint32 rate = SFTIM_prate[prate];
	Sint32 m;
	Sint64 n;
	const Sint32 *tbl;
	Sint32 rem;
	Sint32 fno;
	Sint32 min;
	Sint32 ten;
	Sint32 sec;
	Sint32 frm;
	Sint32 sec_tot;
	Sint32 min_tot;
	Sint32 hour;

	n = UTY_MulDivRound64(pts, (Sint64)(rate * 2), 90000000);
	m = (Sint32)n;
	fno = (m >> 1) - tmpref;
	tc->field = (Sint16)(m & 1);
	fno = (fno > 0) ? fno : 0;
	tc->type = prate;
	tc->drop = drop;
	if (drop != 0 && (rate == 29970 || rate == 59940)) {
		tbl = (rate == 29970) ? sfmpv_conv_29_97 : sfmpv_conv_59_94;
		hour = fno / tbl[0];
		rem = fno % tbl[0];
		ten = rem / tbl[1];
		rem = rem % tbl[1];
		if (rem < tbl[2]) {
			min = 0;
			sec = rem / tbl[5];
			frm = rem % tbl[5];
		} else {
			rem -= tbl[2];
			min = rem / tbl[3] + 1;
			rem = rem % tbl[3];
			if (rem < tbl[4]) {
				sec = 0;
				frm = rem + tbl[7];
			} else {
				rem -= tbl[4];
				sec = rem / tbl[5] + 1;
				frm = rem % tbl[5];
			}
		}
		min += tbl[6] * ten;
	} else {
		sec_tot = fno / rnd;
		frm = fno % rnd;
		min_tot = sec_tot / 60;
		sec = sec_tot % 60;
		hour = min_tot / 60;
		min = min_tot % 60;
	}
	tc->hour = hour;
	tc->min = min;
	tc->sec = sec;
	tc->frm = frm;
}

/* frame table initialisation loops of sfmpv_ChkBufSiz. Inlined helpers: the counter is a helper
 * local and colours (r23) before the two strength-reduced pointers (r24/r25); `i++, frm++` steps
 * the frame pointer as a source statement after the counter (the target's increment order). */
static void sfmpv_InitRfbFrm(SFMPV_WORK *mpv, SFMPV_FRM *frm)
{
	Sint32 i;

	for (i = 0; i < 2; i++, frm++) {
		sfmpv_InitFrm(frm, &mpv->rfb_adr[i]);
	}
}

// Initialises the `n` decoded-frame objects with their buffers from the ta_adr table.
static void sfmpv_InitTaFrm(SFMPV_WORK *mpv, SFMPV_FRM *frm, Sint32 n)
{
	Sint32 i;

	for (i = 0; i < n; i++, frm++) {
		sfmpv_InitFrm(frm, &mpv->ta_adr[i]);
	}
}

/* the decoded frame buffers must hold the pictures the stream announces; when the buffers were
 * given as one block, split it into as many frames as fit. The long-lived locals are all in the
 * second colouring level and take r5.. in declaration order: tabuf r5, fsize r6, ywidth r7,
 * cwidth r8, ysize r9, csize r10, nfrm/i r11, n r12 (h16 reuses r5). */
Sint32 sfmpv_ChkBufSiz(SFD sfd, SFMPV_STMINF *inf, Sint32 bitrate, Sint32 vbvsiz)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	Uint8 *tabuf;
	Sint32 fsize;
	Sint32 ywidth;
	Sint32 cwidth;
	Sint32 ysize;
	Sint32 csize;
	Sint32 nfrm = mpv->para.nfrm;
	Sint32 i;
	Sint32 n;
	Sint32 h16;
	Sint32 fsize2;
	Sint32 tot;
	Sint32 acc;
	Sint32 n2;
	Uint8 *rfbuf;
	Sint32 width;
	Sint32 height;
	Sint32 w16;
	SFMPV_FRM *frm = mpv->frm;

	width = inf->width;
	height = inf->height;
	w16 = (width + 15) / 16 * 16;
	h16 = (height + 15) / 16 * 16;
	ywidth = (w16 + 31) / 32 * 32;
	ysize = h16 * ywidth;
	/* cwidth assigned inside the csize expression: the h16/2 sign chain is then created before the
	 * w16/2 chain, h16/2 (r0) and ywidth (r7) live across it, and the cwidth temporaries colour r8
	 * in place of w16 (a separate `cwidth = ...` statement gives w16 r9 / the chain r0,r7: 18w) */
	csize = (h16 / 2) * (cwidth = (w16 / 2 + 31) / 32 * 32);
	fsize = ysize + csize * 2 + 0x20;
	fsize2 = sfmpv_CalcFrmSiz(mpv->para.width, mpv->para.height);
	if (fsize * 2 > fsize2 * 2) {
		return SFLIB_SetErr(sfd, 0xFF000F17);
	}
	tabuf = (Uint8 *)mpv->para.x20;
	if (tabuf == NULL) {
		n = nfrm;
	} else {
		tot = nfrm * fsize2;
		acc = fsize;
		for (n = 1; n <= SFMPV_FRM_NUM; n++) {
			if (acc > tot) {
				n--;
				break;
			}
			acc += fsize;
		}
		if (n < nfrm) {
			return SFLIB_SetErr(sfd, 0xFF000F17);
		}
		rfbuf = (Uint8 *)mpv->para.x10;
		mpv->rfb_adr[0] = rfbuf;
		mpv->rfb_adr[1] = rfbuf + fsize;
		for (i = 0; i < n; i++) {
			mpv->ta_adr[i] = tabuf + i * fsize;
		}
	}
	sfmpv_SetPlane(&mpv->rfb_adr[0], ywidth, cwidth, ysize, csize, &mpv->rfbuf[0]);
	sfmpv_SetPlane(&mpv->rfb_adr[1], ywidth, cwidth, ysize, csize, &mpv->rfbuf[1]);
	if (sfd->prm.x38 == 3) {
		n2 = (n < SFMPV_FRM_NUM - 2) ? n : SFMPV_FRM_NUM - 2;
		mpv->nfrm = n2 + 2;
		sfmpv_InitRfbFrm(mpv, frm);
		sfmpv_InitTaFrm(mpv, frm + 2, n2);
		mpv->ref[0] = SFMPVF_AllocFrm(sfd);
		mpv->ref[1] = SFMPVF_AllocFrm(sfd);
	} else {
		n2 = (n < SFMPV_FRM_NUM) ? n : SFMPV_FRM_NUM;
		mpv->nfrm = n2;
		sfmpv_InitTaFrm(mpv, frm, n2);
	}
	return 0;
}

/* decode state after the skip decision of a picture */
static inline void sfmpv_UpdatePicStat(SFD sfd, MPV_PICATR *atr, Sint32 skip)
{
	SFMPV_WORK *wk = SFMPV_WK(sfd);
	MPV hn = wk->mpv;
	Sint32 st;
	Sint32 flg1;
	Sint32 flg2;

	st = wk->picstat;
	if (wk->newgop != 0) {
		MPV_GetLinkFlg(hn, &flg1, &flg2);
		if (flg1 == 1) {
			st = 5;
		} else {
			if (SFD_TIM(sfd)->vofst.valid == 0 && SFSET_GetCond(sfd, 0x49) == 1) {
				flg2 = 1;
			}
			if (flg2 == 1) {
				st = 2;
			}
		}
	}
	if (skip == 1) {
		if (atr->pic_type == 1 || atr->pic_type == 2) {
			st = 2;
		}
	} else {
		if (st == 2) {
			st = 3;
		} else if (st == 3) {
			st = 5;
		}
	}
	wk->picstat = st;
}

// Decides whether the picture whose header was just parsed is skipped instead of decoded: never in
// seek mode (cond 0x2F forces skip, 0x27 forbids it); otherwise skipped when seeking, when the
// condition table excludes its type (P/B skip switches), when it is an empty B picture, when the GOP
// is being skipped, or when it would be displayed late. Records the decision in picstat.
Sint32 sfmpv_IsSkip(SFD sfd, SJCK *ck)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	MPV_PICATR *atr = (MPV_PICATR *)mpv->picatr;
	Sint32 ptype;
	Sint32 skip;

	if (SFSET_GetCond(sfd, 0x2F) == 1) {
		return 1;
	}
	if (SFSET_GetCond(sfd, 0x27) == 1) {
		return 0;
	}
	if (atr->x58 != 0) {
		return mpv->skipret;
	}
	ptype = atr->pic_type;
	if (sfmpv_IsSeekSkip(sfd)) {
		skip = 1;
	} else if (sfmpv_IsCondSkip(sfd, ptype)) {
		skip = 1;
	} else if (sfmpv_IsEmptySkip(sfd, ptype, ck)) {
		skip = 1;
	} else if (sfmpv_IsGopSkip(sfd, ptype)) {
		skip = 1;
	} else if (sfmpv_IsLateSkip(sfd, ptype)) {
		skip = 1;
	} else {
		skip = 0;
	}
	sfmpv_UpdatePicStat(sfd, atr, skip);
	return skip;
}

/* the picture would be displayed late */
static inline Bool sfmpv_IsLateSkip(SFD sfd, Sint32 ptype)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	Sint32 t;
	Sint32 unit;
	Sint32 cur;
	Sint32 curunit;
	SFMPV_ISSKIPFN fn;
	SFTIM tim = SFD_TIM(sfd);

	if (tim->vofst.valid == 0) {
		t = 0;
	} else {
		t = tim->ctime + (tim->ttu3.val - tim->vofst.val);
	}
	fn = (SFMPV_ISSKIPFN)tim->isskipfn;
	unit = tim->ttu3.unit;
	if (fn != NULL) {
		return fn(sfd, ptype, t, unit);
	}
	if (ptype == 1) {
		SFTIM_UpdateItime(tim, t);
	}
	if (ptype == 1 || ptype == 2) {
		t = SFTIM_GetNextItime(tim, t);
	}
	if (SFTIM_GetSpeed(sfd) <= 1000 && mpv->nskip >= sfd->cond[0x26]) {
		return FALSE;
	}
	SFTIM_GetTime(sfd, &cur, &curunit);
	if (cur < 0) {
		return FALSE;
	}
	t = t - unit * sfd->cond[0x2A] / sfd->cond[0x2B];
	if (UTY_CmpTime(cur, curunit, t, unit) != 0) {
		return FALSE;
	}
	mpv->nskip++;
	return TRUE;
}

/* pictures that cannot be decoded before the first I picture of the GOP */
static inline Bool sfmpv_IsGopSkip(SFD sfd, Sint32 ptype)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	/* a volatile read keeps `stat` a helper local ranked below `ret` (ret r0, stat r3); a plain
	 * `switch (mpv->picstat)` makes the load a backend temporary coloured before ret */
	Sint32 stat = *(volatile Sint32 *)&mpv->picstat;
	Bool ret = FALSE;

	switch (stat) {
	case 2:
		if (ptype == 2 || ptype == 3) {
			ret = TRUE;
		}
		break;
	case 3:
		if (ptype == 3) {
			ret = TRUE;
		}
		break;
	case 4:
		ret = FALSE;
		break;
	case 5:
		break;
	default:
		break;
	}
	return ret;
}

/* an all-skipped P/B picture need not be decoded */
static inline Bool sfmpv_IsEmptySkip(SFD sfd, Sint32 ptype, SJCK *ck)
{
	SFMPV_STMINF *inf = (SFMPV_STMINF *)&sfd->x90c;
	Sint32 ret;

	if (SFSET_GetCond(sfd, 7) != 0) {
		return FALSE;
	}
	if (ptype == 3) {
		ret = MPV_IsEmptyBpic((Sint8 *)ck->data, ck->len, inf->mb_width * inf->mb_height);
		if (ret) {
			sfd->plyinf.raw[4]++;
		}
		return ret;
	}
	if (ptype == 2) {
		ret = MPV_IsEmptyPpic((Sint8 *)ck->data, ck->len, inf->mb_width * inf->mb_height);
		if (ret) {
			sfd->plyinf.raw[5]++;
		}
		return ret;
	}
	return FALSE;
}

/* the user disabled this picture type */
static inline Bool sfmpv_IsCondSkip(SFD sfd, Sint32 ptype)
{
	Sint32 v;

	switch (ptype) {
	case 1:
		v = sfd->cond[2];
		break;
	case 2:
		v = sfd->cond[3];
		break;
	case 3:
		v = sfd->cond[4];
		break;
	default:
		return TRUE;
	}
	if (v == 0) {
		return TRUE;
	}
	return FALSE;
}

/* a seek target lies beyond this picture */
static inline Bool sfmpv_IsSeekSkip(SFD sfd)
{
	SFTIM tim = SFD_TIM(sfd);
	SFTIM_TTU *ttu3 = &tim->ttu3;
	SFTIM_TTU *vofst = &tim->vofst;

	if (sfd->see.req.pos < 0) {
		return FALSE;
	}
	if (vofst->valid != 0) {
		return FALSE;
	}
	if (UTY_CmpTime(sfd->see.req.pos, sfd->see.req.x08, ttu3->val, ttu3->unit) != 0) {
		return FALSE;
	}
	return TRUE;
}

/* the video offset time: the time code of the first decoded picture */
static inline void sfmpv_SetVofst(SFD sfd)
{
	SFTIM tim = SFD_TIM(sfd);
	SFTIM_TTU *ttu0 = &tim->ttu0;
	SFTIM_TTU *vofst = &tim->vofst;
	SFTIM_TC tc;
	Sint32 ncount;
	Sint32 tscale;
	Sint32 flag;
	/* function-scope pointer = the struct-copy source kept in a register (`addi r4, sfd, 0xde8`);
	 * declared after flag so it is coloured first (ttu3 r4, flag r5) */
	SFTIM_TTU *ttu3 = &tim->ttu3;

	if (vofst->valid == 0) {
		tc = ttu3->tc;
		flag = 0;
		switch (SFMPV_WK(sfd)->picstat) {
		case 2:
			flag = 1;
			break;
		case 3:
			flag = 1;
			break;
		case 4:
			flag = 0;
			break;
		case 5:
			break;
		default:
			break;
		}
		if (flag == 0 && sfd->cond[4] != 0) {
			tc.frm2 = 0;
		}
		SFTIM_Tc2Time(&tc, &ncount, &tscale);
		vofst->tc = tc;
		vofst->val = ncount - ttu0->val;
		vofst->unit = tscale;
		vofst->valid = 1;
	}
}

/* the time of a decoded frame: the current picture time */
static inline void sfmpv_SetFrmTtu(SFD sfd, SFMPV_FRM *frm)
{
	frm->ttu = SFD_TIM(sfd)->ttu3;
	sfmpv_SetFrmTime(sfd, frm);
}

// Decodes one picture: takes a pool frame and the reference planes (sfmpv_SetFrmPara), copies the
// picture user data, runs MPV_DecodeFrmSj on the video ring, times it into tsum[pic_type], then
// stamps the frame (display time, GOP number, DCT/byte counts) and marks it STBY (B) or REF (I/P),
// or keeps a B frame pending until its second field. Counts the decoded picture.
Sint32 sfmpv_DecodeFrm(SFD sfd, SJ sj)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	MPV hn = mpv->mpv;
	MPV_PICATR *atr = (MPV_PICATR *)mpv->picatr;
	SFTIM tim = SFD_TIM(sfd);
	SFMPV_MPVFRM mfrm;
	SFMPV_FRM *frm;
	Sint32 ndct0;
	Sint32 nbyte0;
	Sint64 t0;
	Sint32 flow;
	Sint32 ret;
	Sint32 err;
	SFMPV_PICUSR *slot;

	if (sfmpv_SetFrmPara(sfd, atr, &mfrm, &frm) != 0) {
		return 0;
	}
	if (sfd->prm.x38 == 3) {
		switch (((MPV_PICATR *)mpv->picatr)->pic_type) {
		case 1:
		default:
			ndct0 = 0;
			nbyte0 = 0;
			break;
		case 2:
			ndct0 = mpv->ref[0]->ndct;
			nbyte0 = mpv->ref[0]->nbyte;
			break;
		case 3:
			ndct0 = mpv->ref[0]->ndct + mpv->ref[1]->ndct;
			nbyte0 = mpv->ref[0]->nbyte + mpv->ref[1]->nbyte;
			break;
		}
	} else {
		ndct0 = 0;
		nbyte0 = 0;
	}
	slot = frm->picusr;
	memcpy(slot->buf, mpv->picusr_dat, mpv->picusr_len);
	slot->len = mpv->picusr_len;
	sfmpv_SetVofst(sfd);
	t0 = UTY_GetTmr();
	flow = SJRBF_GetFlowCnt(sj, 0, 1);
	ret = MPV_DecodeFrmSj(hn, sj, &mfrm);
	flow = SJRBF_GetFlowCnt(sj, 0, 1) - flow;
	SFTMR_AddTsum(&sfd->tsum[atr->pic_type], UTY_GetTmr() - t0);
	sfd->err.x0c += mfrm.nfrm;
	sfd->err.x10 += mfrm.nbyte;
	err = sfmpv_ChkDecRet(sfd, ret, flow, 0xFF000F06);
	sfmpv_AddRtot(sfd, flow);
	if (err != 0) {
		SFMPVF_FreeFrm(frm);
		return err;
	}
	if (flow > 0) {
		SFMPVF_SetGopStat(sfd, 0);
		sfmpv_SetFrmTtu(sfd, frm);
		frm->gopno = mpv->nconcat;
		frm->ndct = mfrm.nfrm + ndct0 + mpv->tmpref_adj;
		frm->nbyte = mfrm.nbyte + nbyte0;
		if (atr->x38 != 3 && mpv->pendfrm == NULL) {
			mpv->pendfrm = frm;
		} else {
			mpv->pendfrm = NULL;
		}
		mpv->skipret = 0;
		mpv->dlmwait = 0;
		if (mpv->pendfrm == NULL) {
			if (sfd->prm.x38 == 3 && (atr->pic_type == 1 || atr->pic_type == 2)) {
				SFMPVF_RefStbyFrm(frm);
			} else {
				SFMPVF_StbyFrm(frm);
			}
			MPV_GetDctCnt(hn, &sfd->plyinf.raw[2], &sfd->plyinf.raw[3]);
			mpv->nskip = 0;
		}
		/* outside the pendfrm test: the target's `bne` lands on the `lwz r5, pic_type` */
		SFPLY_AddDecPic(sfd, 1, atr->pic_type);
	} else {
		if (mpv->pendfrm == NULL) {
			SFMPVF_FreeFrm(frm);
		}
	}
	return 0;
}

/* frame buffers of the picture about to be decoded */
Sint32 sfmpv_SetFrmPara(SFD sfd, MPV_PICATR *atr, SFMPV_MPVFRM *mfrm, SFMPV_FRM **pfrm)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	/* colouring order = declaration order: ywidth (in place r4), cwidth r5, h16 r6, ysize (in place
	 * r6), csize r7 */
	Sint32 w;
	Sint32 h;
	Sint32 w16;
	Sint32 ywidth;
	Sint32 cwidth;
	Sint32 h16;
	Sint32 ysize;
	Sint32 csize;
	SFMPV_PLANE *rfbuf;

	if (mpv->pendfrm != NULL) {
		*pfrm = mpv->pendfrm;
	} else {
		*pfrm = SFMPVF_AllocFrm(sfd);
		if (*pfrm == NULL) {
			sfd->plyinf.raw[10] = 1;
			return -1;
		}
	}
	*(MPV_PICATR *)&(*pfrm)->pa_width = *atr;
	(*pfrm)->pts = mpv->pts;
	if (sfd->prm.x38 == 3) {
		if ((atr->pic_type == 1 || atr->pic_type == 2) && mpv->pendfrm == NULL) {
			SFMPVF_EndRefFrm(mpv->ref[0]);
			mpv->ref[0] = mpv->ref[1];
			mpv->ref[1] = *pfrm;
		}
		/* the volatile read keeps `h` a variable (loaded into r4 next to the propagated `w` r3, the
		 * `h + 15` after the w16 chain); the nested ysize/csize assignments anchor the products in
		 * the ref[0] block */
		h = *(volatile Sint32 *)&atr->height;
		w = atr->width;
		w16 = (w + 15) / 16 * 16;
		ywidth = (w16 + 31) / 32 * 32;
		cwidth = (w16 / 2 + 31) / 32 * 32;
		h16 = (h + 15) / 16 * 16;
		mfrm->ref[0].ywidth = (Sint16)ywidth;
		mfrm->ref[0].cwidth = (Sint16)cwidth;
		mfrm->ref[0].y = mpv->ref[0]->buf;
		mfrm->ref[0].cb = (Uint8 *)mfrm->ref[0].y + (ysize = h16 * ywidth);
		mfrm->ref[0].cr = (Uint8 *)mfrm->ref[0].cb + (csize = (h16 / 2) * cwidth);
		mfrm->ref[1].ywidth = (Sint16)ywidth;
		mfrm->ref[1].cwidth = (Sint16)cwidth;
		mfrm->ref[1].y = mpv->ref[1]->buf;
		mfrm->ref[1].cb = (Uint8 *)mfrm->ref[1].y + ysize;
		mfrm->ref[1].cr = (Uint8 *)mfrm->ref[1].cb + csize;
	} else {
		if (atr->pic_type == 1 || atr->pic_type == 2) {
			mpv->refidx[0] ^= 1;
			mpv->refidx[1] ^= 1;
			mpv->ref[1] = *pfrm;
		}
		rfbuf = mpv->rfbuf;
		mfrm->ref[0] = rfbuf[mpv->refidx[0]];
		mfrm->ref[1] = rfbuf[mpv->refidx[1]];
	}
	mfrm->dst = (*pfrm)->buf;
	mfrm->picatr = (MPV_PICATR *)&(*pfrm)->pa_width;
	mfrm->nfrm = 0;
	mfrm->nbyte = 0;
	sfd->plyinf.raw[10] = 0;
	return 0;
}

/* advance the read position to the next start code of `mask`; returns the bytes skipped */
Sint32 sfmpv_GoDdelim(SFD sfd, SJ sj, Sint32 mask)
{
	SFBUF_RINF inf;
	Sint8 *p;
	register Sint32 n;
	register Sint32 t;
	Sint32 code;
	Sint32 found;
	Sint32 i;
	Sint32 rest;

	if (SFBUF_RingGetRead(sfd, SFMPV_BUFIN(sfd), &inf) != 0) {
		return 0;
	}
	if (inf.ck1.len == 0) {
		return 0;
	}
	p = sfmpv_SearchDlm(&inf, mask, &code);
	if (p == NULL) {
		rest = inf.ck1.len + inf.ck2.len;
		rest = rest - 3;
		/* the original copies the branchless max out of a temporary (`and r0; mr n, r0`); every C
		 * spelling renames the single-use temporary into n (28 forms). The codeless self copy is an
		 * opaque second def of t, so `n = t` stays a user copy (COMPILER-DIFF: codeless self copy). */
		t = (rest > 0) ? rest : 0;
		
		n = t;
	} else if ((Uint8 *)inf.ck1.data <= (Uint8 *)p && (Uint8 *)p < (Uint8 *)inf.ck1.data + inf.ck1.len) {
		/* sfmpv_DlmOfst written out: its inlined return value would be a second copy into n, and
		 * only one of the two copies coalesces */
		n = p - (Sint8 *)inf.ck1.data;
	} else if ((Uint8 *)inf.ck2.data <= (Uint8 *)p && (Uint8 *)p < (Uint8 *)inf.ck2.data + inf.ck2.len) {
		n = inf.ck1.len + (p - (Sint8 *)inf.ck2.data);
	} else {
		n = 0;
	}
	SFBUF_RingAddRead(sfd, SFMPV_BUFIN(sfd), n);
	/* skipped data other than zero stuffing counts as a stream error */
	found = 0;
	for (i = 0; i < ((n < 3) ? n : 3); i++) {
		Uint8 *r;
		if (i < inf.ck1.len) {
			r = (Uint8 *)inf.ck1.data + i;
		} else {
			r = (Uint8 *)inf.ck2.data + (i - inf.ck1.len);
		}
		if (*(Sint8 *)r != 0) {
			found = 1;
			break;
		}
	}
	if (found) {
		SFD_CNT(sfd)->v_skip += n;
	}
	SFD_CNT(sfd)->v_byte += n;
	return n;
}

// Driver Create: work from the library parameters (frame buffers), an MPV decoder handle with
// sfmpv_ErrFn, the decoder conditions and the picture user data buffer.
static Sint32 SFMPV_Create(void *obj)
{
	SFD sfd;
	SFMPV_WORK *mpv;
	MPV hn;
	Sint32 ret;
	register Sint32 z;

	/* the original colours sfd r31 > mpv r30 > .bss pool base r29 > hn r28. The pool base is the
	 * first backend temporary (above every frontend id), so mpv can only precede it by popping from
	 * a higher Chaitin level: the dead conditional before the return extends mpv (and one read of
	 * sfd) across the inlined sfmpv_SetPicUsrBuf, lifting both to level 2 (36 neighbours), and sfd
	 * as an own local declared before mpv outranks it there (the copy of `obj` is the original's
	 * `mr r31, r3`). `z = 0`, kept to the scheduler by the self copy, is a dead `li` of the entry
	 * block that takes the issue slot next to the copy, so the pool `addi` is issued before
	 * `li r4, 5` and the pool `lis` temporary keeps r4 (COMPILER-DIFF: M4 (dead conditional),
	 * codeless self copy). */
	sfd = obj;
	z = 0;
	

	if (SFSET_GetCond(sfd, 5) == 0) {
		return 0;
	}
	/* the inlined sfmpv_SetPicUsrBuf is exact (see the `p = buf` note there). */
	mpv = &sfd->mpv;
	sfd->tr[SFMPV_TR].hn = mpv;
	ret = sfmpv_InitInf(sfd, mpv);
	if (ret != 0) {
		return ret;
	}
	hn = MPV_Create();
	if (hn == NULL) {
		return SFLIB_SetErr(NULL, 0xFF000F0A);
	}
	if (MPV_SetErrFunc(hn, sfmpv_ErrFn, sfd) != 0) {
		MPV_Destroy(hn);
		return SFLIB_SetErr(NULL, 0xFF000F0B);
	}
	MPV_SetCond(hn, 1, SFSET_GetCond(sfd, 0));
	MPV_SetCond(hn, 2, SFSET_GetCond(sfd, 1));
	MPV_SetCond(hn, 6, sfd->prm.x38);
	mpv->mpv = hn;
	if (SFPLY_GetResetFlg() != 0) {
		sfmpv_SetPicUsrBuf(sfd, sfmpv_picusr_pbuf, sfmpv_picusr_bufnum, sfmpv_picusr_buf1siz);
	}
	ret = 0;
	z = 0;
	if (z != 0) {
		ret = ret + mpv->picstat + sfd->prm.x38;
	}
	return ret;
}

/* the frame records of a fresh handle. `frm` stepped in the `for` increment (a source IV, not a
 * strength-reduced `&frm[i]`) puts its `addi 0xe0` before the counter compare in the latch and the
 * `ta_adr` pointer's `addi 4` after it. */
static inline void sfmpv_InitFrmTbl(SFMPV_WORK *mpv)
{
	SFMPV_FRM *frm = mpv->frm;
	Sint32 i;

	for (i = 0; i < SFMPV_FRM_NUM; i++, frm++) {
		sfmpv_InitFrm(frm, &mpv->ta_adr[i]);
	}
}

// Driver work from the library-wide parameters (SFD_SetMpvParaTbl): geometry, reference and decoded
// frame buffer tables; error 0xFF000F15 when the frame pool count is invalid.
Sint32 sfmpv_InitInf(SFD sfd, SFMPV_WORK *mpv)
{
	int i;
	int j;

	if (sfmpv_ChkPara(&sfmpv_para) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000F15);
	}
	mpv->para = sfmpv_para;
	memcpy(mpv->rfb_adr, sfmpv_rfb_adr_tbl, sizeof(mpv->rfb_adr));
	memcpy(mpv->ta_adr, sfmpv_ta_adr_tbl, sizeof(mpv->ta_adr));
	mpv->mpv = NULL;
	mpv->curfrm = NULL;
	mpv->picstat = 5;
	mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ;
	mpv->refidx[0] = 0;
	mpv->refidx[1] = 1;
	mpv->termflg = 0;
	mpv->gopstat = 0;
	mpv->ref[0] = NULL;
	mpv->ref[1] = NULL;
	mpv->pendfrm = NULL;
	mpv->skipret = 0;
	mpv->dlmwait = 0;
	mpv->tmpref_adj = 0;
	sfmpv_InitFrmTbl(mpv);
	mpv->nskip = 0;
	mpv->nconcat = 0;
	UTY_MemsetDword(mpv->picatr, 0xFFFFFFFF, 0x20);
	mpv->last_ngop = -1;
	mpv->newgop = 0;
	mpv->vbvsiz = 0x7FFFFFFF;
	mpv->pts_tmpref = 0;
	mpv->pts_ofst = 0;
	mpv->pts_max = 0;
	mpv->ptsent.pts = -1;
	mpv->ptsent.pos = 0;
	mpv->ptsent.len = -1;
	mpv->picusr_buf = NULL;
	mpv->picusr_num = 0;
	mpv->picusr_siz = 0;
	mpv->picusr_dat = NULL;
	mpv->picusr_len = 0;
	for (i = 0; i < SFMPV_FRM_NUM; i++) {
		mpv->picusr[i].buf = NULL;
		mpv->picusr[i].len = 0;
	}
	for (j = 0; j < SFMPV_FRM_NUM; j++) {
		mpv->frm[j].picusr = &mpv->picusr[j];
	}
	return 0;
}

/* buffers the creation parameters supplied. `para` as the helper's parameter (a node ranked below
 * the frontend temporaries: r4, the reference-table pointer r3) and the two reference buffers
 * tested in a counted loop (fully unrolled by the frontend, its induction pointer materialised
 * before the first load: `addi r3; lwz 0(r3); .. lwz 4(r3)`). */
static inline Sint32 sfmpv_ChkPara(SFMPV_PARA *para)
{
	Sint32 i;

	if (para->nfrm <= 0 || para->nfrm > SFMPV_FRM_NUM) {
		return -1;
	}
	if ((Uint32)para->x10 == 0 || (Uint32)para->x20 == 0) {
		for (i = 0; i < 2; i++) {
			if (sfmpv_rfb_adr_tbl[i] == NULL) {
				return -1;
			}
		}
		for (i = 0; i < para->nfrm; i++) {
			if (sfmpv_ta_adr_tbl[i] == NULL) {
				return -1;
			}
		}
	}
	return 0;
}

// MPV decoder errors: -1 -> data error 0xFF000F0A, others -> 0xFF000F0B; 0/-2/-3 ignored.
void sfmpv_ErrFn(void *obj, Sint32 code)
{
	switch (code) {
	case -3:
	case -2:
	case 0:
		return;
	case -1:
	default:
		SFLIB_SetErr((SFD)obj, code);
		break;
	}
}

/* the buffers survive in the file statics for the next creation.
 * COMPILER-DIFF: M1 (codeless neighbour pin) - the original ranks the handle above the .bss pool base
 * (sfd r31, pool r30, mpv r29): a level-2 node where ours has exactly 28 neighbours; the pinned r11
 * leaves the colour set (28 colours), so sfd survives its scan; both `mr`s are deleted by the RA
 * (CRI pass 40) */
Sint32 SFMPV_Destroy(register SFD sfd)
{
	SFMPV_WORK *mpv;
	MPV hn;

	 // COMPILER-DIFF: M1 (codeless neighbour pin)
	mpv = sfd->tr[SFMPV_TR].hn;
	hn = mpv->mpv;

	if (hn == NULL) {
		return 0;
	}
	sfmpv_para = mpv->para;
	memcpy(sfmpv_rfb_adr_tbl, mpv->rfb_adr, sizeof(sfmpv_rfb_adr_tbl));
	memcpy(sfmpv_ta_adr_tbl, mpv->ta_adr, sizeof(sfmpv_ta_adr_tbl));
	sfmpv_picusr_pbuf = mpv->picusr_buf;
	sfmpv_picusr_bufnum = mpv->picusr_num;
	sfmpv_picusr_buf1siz = mpv->picusr_siz;
	if (MPV_Destroy(hn) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000F0C);
	}
	mpv->mpv = NULL;
	return 0;
}

// Nothing to do.
Sint32 SFMPV_Standby(SFD sfd)
{
	return 0;
}

// Nothing to do.
Sint32 SFMPV_Start(SFD sfd)
{
	return 0;
}

/* the arm's `ret = 0` is a helper local: the backend CSE turns its `li` into a copy of the entry zero,
 * the arm empties and the branch to the next instruction is dropped (target: `li r3, 0; cmplwi; blr`) */
static Sint32 sfmpv_StopSub(SFD sfd)
{
	Sint32 ret;

	ret = 0;
	if (SFMPV_WK(sfd) == NULL) {
		ret = 0;
	}
	return ret;
}

// Nothing to do (the frame pool is rebuilt by the handle reset).
Sint32 SFMPV_Stop(SFD sfd)
{
	return sfmpv_StopSub(sfd);
}

// Nothing to do.
Sint32 SFMPV_Pause(SFD sfd)
{
	return 0;
}

// Not supported: error 0xFF000F0D.
static Sint32 SFMPV_GetWrite(SFD sfd)
{
	return SFLIB_SetErr(sfd, 0xFF000F0D);
}

// Not supported: error 0xFF000F0D.
Sint32 SFMPV_AddWrite(SFD sfd)
{
	return SFLIB_SetErr(sfd, 0xFF000F0D);
}

// The earliest decoded frame waiting for display, as the user-visible SFD_VFRM_INF (NULL when none
// or the decoder is finished); records its time as the current video end time.
Sint32 SFMPV_GetRead(SFD sfd, SFD_VFRM_INF **inf)
{
	Sint32 lastflg;
	SFMPV_FRM *frm;

	if (SFMPVF_GetNumFrm(sfd) == -1) {
		*inf = NULL;
		return 0;
	}
	if ((frm = SFMPVF_HoldFrm(sfd, &lastflg)) == NULL) {
		*inf = NULL;
		return 0;
	}
	sfmpv_SetFrmInf(sfd, frm, (SFMPV_VINF **)inf);
	SFD_TIM(sfd)->vterm = ((SFMPV_VINF *)*inf)->ftime;
	SFD_TIM(sfd)->vterm_unit = ((SFMPV_VINF *)*inf)->tunit;
	return 0;
}

// Fills the SFD_VFRM_INF the application sees from the frame object: size, macroblock size, picture
// type, display time, buffer format/address, DCT/byte counts, GOP number, picture user data, picture
// structure (field/frame) and the remaining picture attributes; marks the slot in use.
void sfmpv_SetFrmInf(SFD sfd, SFMPV_FRM *frm, SFMPV_VINF **inf)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	SFMPV_VFRM *vfrm;

	vfrm = (SFMPV_VFRM *)SFMPVF_SearchVfrmData(sfd, frm);
	*inf = &vfrm->inf;
	vfrm->used = 1;
	mpv->curfrm = frm;
	(*inf)->width = frm->pa_width;
	(*inf)->height = frm->pa_height;
	(*inf)->mb_width = frm->pa_mb_width;
	(*inf)->mb_height = frm->pa_mb_height;
	(*inf)->pic_type = frm->pa_pic_type;
	(*inf)->ftime = frm->ftime;
	(*inf)->tunit = frm->tunit;
	(*inf)->fmt = sfd->prm.x38;
	(*inf)->buf = frm->buf;
	(*inf)->ndct = frm->ndct;
	(*inf)->nbyte = frm->nbyte;
	(*inf)->gopno = frm->gopno;
	(*inf)->x30 = frm->x4c;
	(*inf)->x34 = frm->x50;
	(*inf)->picusr = frm->picusr;
	(*inf)->x3c = frm->pa_x90[2];
	(*inf)->x40 = frm->pa_x9c[0];
	if (frm->pa_x90[2] == 0) {
		(*inf)->pstruct = 2;
	} else {
		(*inf)->pstruct = 1;
	}
	(*inf)->pts = frm->pts;
	(*inf)->x58 = frm->pa_x90[0];
	(*inf)->x5c = frm->pa_x90[1];
	(*inf)->x60 = frm->pa_x9c[1];
	(*inf)->x64 = frm->pa_x9c[2];
	(*inf)->x68 = frm->pa_xa8;
	(*inf)->x6a = frm->pa_xaa;
	(*inf)->x6c = frm->pa_xad;
	(*inf)->x6d = frm->pa_xae;
	(*inf)->x6e = frm->pa_xaf;
	(*inf)->x6f = frm->pa_xb1;
	(*inf)->x70 = frm->pa_xb2;
	(*inf)->x71 = frm->pa_xb3;
	(*inf)->x72 = frm->pa_xb4;
	(*inf)->x73 = frm->pa_xb5;
	(*inf)->x74 = frm->pa_xb6;
	(*inf)->x75 = frm->pa_xb7;
	(*inf)->x76 = frm->pa_xb8;
	(*inf)->x77 = frm->pa_xb9;
	(*inf)->x78 = frm->pa_xba;
	(*inf)->x79 = frm->pa_xbb;
	(*inf)->x7a = frm->pa_xbc;
}

// The application returned a frame (SFD_RelFrm): must be the one handed out; releases the slot and
// moves the frame to DRAWN/FREE.
Sint32 SFMPV_AddRead(SFD sfd, SFD_VFRM_INF *inf)
{
	Sint32 cs;
	SFMPV_WORK *mpv;
	SFMPV_VFRM *vfrm = (SFMPV_VFRM *)((Uint8 *)inf - 8);
	Sint32 ret;

	SFLIB_LockCs(&cs);
	mpv = SFMPV_WK(sfd);
	if (vfrm->used != 1) {
		ret = SFLIB_SetErr(sfd, 0xFF000F0E);
	} else if (mpv->curfrm != SFMPVF_SearchFrmObj(sfd, inf)) {
		ret = SFLIB_SetErr(sfd, 0xFF000F0F);
	} else {
		vfrm->used = 0;
		SFMPVF_EndDrawFrm(mpv->curfrm);
		ret = 0;
	}
	SFLIB_UnlockCs(&cs);
	return ret;
}

// Seek support: re-decodes the saved video sequence header and rebuilds the frame pool; unused here.
Sint32 SFMPV_Seek(SFD sfd)
{
	Sint32 flg = 0;
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	Sint32 ret;

	ret = sfmpv_SeekVhdr(sfd, &flg);
	if (ret != 0) {
		return ret;
	}
	mpv->picstat = 2;
	if (flg == 0 || SFSET_GetCond(sfd, 0x30) == 0) {
		mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ;
	} else {
		mpv->dlmmask = SFMPV_DLM_END | SFMPV_DLM_SEQ | SFMPV_DLM_GOP;
	}
	return 0;
}

/* restart from the cached sequence header after a seek */
static inline Sint32 sfmpv_SeekVhdr(SFD sfd, Sint32 *flg)
{
	SFMPV_WORK *mpv = SFMPV_WK(sfd);
	SFSEE_WORK *wk = sfd->see.wk;
	SFSEE_VHDR *vhdr;
	SFSEE_VRAW *raw;
	MPV hn;
	SJCK ck;
	Sint32 used;

	if (wk == NULL) {
		vhdr = NULL;
	} else if (mpv->nconcat > 0) {
		vhdr = NULL;
	} else {
		vhdr = (SFSEE_VHDR *)&wk->a1hdr;
	}
	if (vhdr == NULL) {
		return 0;
	}
	if (vhdr->analyzed == 0) {
		return 0;
	}
	hn = mpv->mpv;
	SFD_TIM(sfd)->ttu0 = vhdr->ttu;
	/* `raw` is a node (its store use is not foldable) ranked below the ttu copy's temporaries
	 * (addi r7 hoisted above the copy; the len load folds to 0x238(vhdr)) */
	raw = (SFSEE_VRAW *)vhdr->raw;
	ck.data = raw->dat;
	ck.len = raw->len;
	if (MPV_DecodePicAtr(hn, &ck, &used) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000F1B);
	}
	*flg = 1;
	return 0;
}

/* the video decoder cannot use the ring buffer unless a whole pack fits */
// FUN_0051B150
static inline Sint32 sfmpv_ChkRingSpace(SFD sfd)
{
	Sint32 n = SFMPV_BUFIN(sfd);

	if (SFBUF_GetRingBufSiz(sfd, n) - SFBUF_RingGetDataSiz(sfd, n) < sfd->prm.unit) {
		return SFLIB_SetErr(sfd, 0xFF000F1C);
	}
	return 0;
}

/* skip the sequence end codes at the read position */
static inline void sfmpv_SkipEndcode(SFD sfd, SJ sj)
{
	SJCK ck;

	for (;;) {
		SJ_GetChunk(sj, 1, 4, &ck);
		if (ck.len != 4) {
			break;
		}
		if (MPV_CheckDelim(ck.data) != SFMPV_DLM_END) {
			break;
		}
		SJ_PutChunk(sj, 0, &ck);
		sfmpv_AddRtot(sfd, 4);
	}
	SJ_UngetChunk(sj, 1, &ck);
}

/* the picture user data buffers: one slot per decoded frame after the decoder's own */
static inline Sint32 sfmpv_SetPicUsrBuf(SFD sfd, void *buf, Sint32 num, Sint32 siz)
{
	SFMPV_PICUSRWK *pu = (SFMPV_PICUSRWK *)&SFMPV_WK(sfd)->picusr_buf;
	int i;
	Sint32 n;
	Sint32 j;
	Uint8 *p; /* declared after j: coloured first (r4), j r5, n r6 */

	/* `p` is the buffer pointer from the first statement on and `buf` is not read again: at the
	 * SFMPV_Create site the argument is a global load, and the frontend substitutes the single-use
	 * load into `p` (one node, so `p += siz` stays after the `pu->dat = p` store: `add r4, r4, r7`),
	 * while at the SFD_SetPicUsrBuf site `p = buf` is a plain copy of the parameter that is
	 * propagated (stores use r29, the add is a new node hoisted above them). `p = buf + siz` after
	 * the stores, or the copy after the NULL test, is a second node whose add the pre-RA scheduler
	 * hoists above the `dat` store (p r4 / buf r9 at the Create site). */
	p = buf;
	if (p == NULL || num == 0 || siz == 0) {
		pu->buf = NULL;
		pu->num = 0;
		pu->siz = 0;
		pu->dat = NULL;
		pu->len = 0;
		for (i = 0; i < SFMPV_FRM_NUM; i++) {
			pu->slot[i].buf = NULL;
			pu->slot[i].len = 0;
		}
		return 0;
	}
	if (num < sfd->prm.x2c + 3) {
		return SFLIB_SetErr(sfd, 0xFF000F1D);
	}
	pu->buf = p;
	pu->num = num;
	pu->siz = siz;
	pu->dat = p;
	pu->len = 0;
	p += siz;
	n = num - 1;
	for (j = 0; j < ((n < SFMPV_FRM_NUM) ? n : SFMPV_FRM_NUM); j++) {
		pu->slot[j].buf = p;
		pu->slot[j].len = 0;
		p += siz;
	}
	return 0;
}

/* display time of a frame from its time code relative to the video start */
static inline void sfmpv_SetFrmTime(SFD sfd, SFMPV_FRM *frm)
{
	SFTIM tim = SFD_TIM(sfd);

	frm->tunit = frm->ttu.unit;
	frm->ftime = tim->ctime + (frm->ttu.val - tim->vofst.val);
	frm->x4c = frm->ttu.val;
	frm->x50 = frm->ttu.val + tim->ctime;
	if (tim->x284 < frm->ftime) {
		tim->x284 = frm->ftime;
		tim->x288 = frm->tunit;
	}
}

// A frame object in its FREE state with its buffer and cleared picture attributes (all 0xFF).
static inline void sfmpv_InitFrm(SFMPV_FRM *frm, void **pbuf)
{
	frm->stat = SFMPV_FRM_FREE;
	frm->lock = 0;
	SFTIM_InitTtu(&frm->ttu, 0);
	frm->buf = *pbuf;
	frm->ftime = 0;
	frm->tunit = 1;
	frm->ndct = 0;
	frm->nbyte = 0;
	frm->gopno = 0;
	frm->x4c = 0;
	frm->x50 = 0;
	UTY_MemsetDword(&frm->pa_width, 0xFFFFFFFF, 0x20);
}

/* bytes of one YCC 4:2:0 frame buffer (mwsfdcre.c uses the same formula) */
static inline Sint32 sfmpv_CalcFrmSiz(Sint32 width, Sint32 height)
{
	Sint32 w16 = (width + 15) / 16 * 16;
	Sint32 h16 = (height + 15) / 16 * 16;
	Sint32 ysize = h16 * ((w16 + 31) / 32 * 32);
	Sint32 csize = (h16 / 2) * ((w16 / 2 + 31) / 32 * 32);

	return ysize + csize * 2 + 0x20;
}

/* plane addresses of a frame buffer from its row and plane sizes; `void **pbuf` keeps the buffer
 * load after the two `sth` (a load through a pointer parameter is not hoisted over the plane stores) */
static inline void sfmpv_SetPlane(void **pbuf, Sint32 ywidth, Sint32 cwidth, Sint32 ysize, Sint32 csize, SFMPV_PLANE *plane)
{
	plane->ywidth = (Sint16)ywidth;
	plane->cwidth = (Sint16)cwidth;
	plane->y = *pbuf;
	plane->cb = (Uint8 *)plane->y + ysize;
	plane->cr = (Uint8 *)plane->cb + csize;
}

/* plane addresses of a YCC 4:2:0 frame buffer: 16-aligned picture, 32-byte rows. Declaration order
 * h16, cwidth, ywidth = colouring order ywidth (in place, r5), cwidth (r7), h16 (r8); the
 * assignments keep the evaluation order ywidth, cwidth. */
static inline void sfmpv_CalcYccPlane(void *buf, Sint32 width, Sint32 height, SFMPV_PLANE *plane)
{
	Sint32 w16 = (width + 15) / 16 * 16;
	Sint32 h16;
	Sint32 cwidth;
	Sint32 ywidth;

	ywidth = (w16 + 31) / 32 * 32;
	cwidth = (w16 / 2 + 31) / 32 * 32;
	plane->ywidth = (Sint16)ywidth;
	plane->cwidth = (Sint16)cwidth;
	plane->y = buf;
	h16 = (height + 15) / 16 * 16;
	plane->cb = (Uint8 *)plane->y + h16 * ywidth;
	plane->cr = (Uint8 *)plane->cb + (h16 / 2) * cwidth;
}

/* byte offset of a position inside the readable data (0 when it is in neither chunk) */
static inline Sint32 sfmpv_DlmOfst(SFBUF_RINF *inf, Sint8 *p)
{
	if ((Uint8 *)inf->ck1.data <= (Uint8 *)p && (Uint8 *)p < (Uint8 *)inf->ck1.data + inf->ck1.len) {
		return p - (Sint8 *)inf->ck1.data;
	}
	if ((Uint8 *)inf->ck2.data <= (Uint8 *)p && (Uint8 *)p < (Uint8 *)inf->ck2.data + inf->ck2.len) {
		return inf->ck1.len + (p - (Sint8 *)inf->ck2.data);
	}
	return 0;
}

/* the same search backwards from the end of the readable data */
static inline Sint8 *sfmpv_BsearchDlm(SFBUF_RINF *inf, Sint32 mask, Sint32 *code)
{
	Uint8 tmp[8];
	Sint8 *p;
	Sint32 n1;
	Sint32 n2;
	Sint32 i;
	Sint32 c;

	if (inf->ck2.len != 0) {
		p = MPV_BsearchDelim((Sint8 *)inf->ck2.data + inf->ck2.len, inf->ck2.len, mask);
		if (p != NULL) {
			*code = MPV_CheckDelim(p);
			return p;
		}
		n1 = (inf->ck1.len < 3) ? inf->ck1.len : 3;
		n2 = (inf->ck2.len < 3) ? inf->ck2.len : 3;
		memcpy(tmp, (Uint8 *)inf->ck1.data + inf->ck1.len - n1, n1);
		memcpy(tmp + n1, inf->ck2.data, n2);
		for (i = 0; i < n1 + n2 - 3; i++) {
			c = MPV_CheckDelim(&tmp[i]);
			if (c & mask) {
				*code = c;
				return (Sint8 *)inf->ck1.data + inf->ck1.len - n1 + i;
			}
		}
	}
	p = MPV_BsearchDelim((Sint8 *)inf->ck1.data + inf->ck1.len, inf->ck1.len, mask);
	if (p != NULL) {
		*code = MPV_CheckDelim(p);
		return p;
	}
	return NULL;
}

/* start code search over the two chunks of the ring buffer; `code` receives MPV_CheckDelim of it */
static inline Sint8 *sfmpv_SearchDlm(SFBUF_RINF *inf, Sint32 mask, Sint32 *code)
{
	Uint8 tmp[8];
	Sint8 *p;
	Sint32 n1;
	Sint32 n2;
	Sint32 i;
	Sint32 c;

	p = MPV_SearchDelim((Sint8 *)inf->ck1.data, inf->ck1.len, mask);
	if (p != NULL) {
		*code = MPV_CheckDelim(p);
		return p;
	}
	if (inf->ck2.len == 0) {
		return NULL;
	}
	n1 = (inf->ck1.len < 3) ? inf->ck1.len : 3;
	n2 = (inf->ck2.len < 3) ? inf->ck2.len : 3;
	memcpy(tmp, (Uint8 *)inf->ck1.data + inf->ck1.len - n1, n1);
	memcpy(tmp + n1, inf->ck2.data, n2);
	for (i = 0; i < n1 + n2 - 3; i++) {
		c = MPV_CheckDelim(&tmp[i]);
		if (c & mask) {
			*code = c;
			return (Sint8 *)inf->ck1.data + inf->ck1.len - n1 + i;
		}
	}
	p = MPV_SearchDelim((Sint8 *)inf->ck2.data, inf->ck2.len, mask);
	if (p != NULL) {
		*code = MPV_CheckDelim(p);
		return p;
	}
	return NULL;
}

/* account the bytes the decoder took from the input ring */
static inline void sfmpv_AddRtot(SFD sfd, Sint32 nbyte)
{
	SFBUF_AddRtotSj(sfd, SFMPV_BUFIN(sfd), nbyte);
	SFD_CNT(sfd)->v_byte += nbyte;
}

/* decoder result of one picture / header: -2 and -3 (not enough data) are errors only when the
 * decoder consumed nothing */
static inline Sint32 sfmpv_ChkDecRet(SFD sfd, Sint32 ret, Sint32 flow, Sint32 code)
{
	Sint32 err;

	switch (ret) {
	case 0:
		err = 0;
		break;
	case -2:
		if (flow > 0) {
			err = 0;
		} else {
			err = SFLIB_SetErr(sfd, -2);
		}
		break;
	case -3:
		if (flow > 0) {
			err = 0;
		} else {
			err = SFLIB_SetErr(sfd, -3);
		}
		break;
	case -1:
	default:
		err = SFLIB_SetErr(sfd, code);
		break;
	}
	return err;
}
