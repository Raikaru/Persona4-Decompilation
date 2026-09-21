/* CRI Sofdec MW player: handle creation (mwsfdcre.c)
 *
 * Matching (CRI pass 66). Two tagged codeless asm forms: mwPlyCalcWorkSfd's second read of `size`
 * (CRI pass 65) and the `case 4:` self-copy of mwsfcre_IsUseAdxt (the original's case-4-first arm
 * held a statement a backend pass deleted, leaving a dead `b` at both inlined sites). */
#include "cri_xpt.h"
#include "sfd.h"
#include "lsc.h"
#include "mwsfd.h"
#include <string.h>

extern const SFD_TR_IF SFD_tr_in_mem;
extern const SFD_TR_IF SFD_tr_sd_mps;
extern const SFD_TR_IF SFD_tr_vd_mpv;
extern const SFD_TR_IF SFD_tr_vo_manu;
extern const SFD_TR_IF SFD_tr_ad_adxt;
extern const SFD_TR_IF SFD_tr_ao_auto_p;
extern const SFD_TR_IF SFD_tr_uo;

/* the SFD creation parameters with the driver table typed (sfd.h keeps x00 a word) */
typedef struct {
	const SFD_TR_IF *const *trif_tbl; /* 0x00 */
	Uint32 adr;                /* 0x04 */
	Sint32 size[7];            /* 0x08 */
	Sint32 x24;
	Sint32 unit;               /* 0x28 */
	Sint32 x2c;
	Sint32 x30;                /* 0x30 max width */
	Sint32 x34;                /* 0x34 max height */
	Sint32 x38;                /* 0x38 frame buffer format */
	void *hnwork;              /* 0x3C */
	Sint32 hnwksiz;            /* 0x40 */
} MWSFD_SFDCREPRM;

/* MPEG video decoder parameters (SFD_SetMpvParaTbl) */
typedef struct {
	Sint32 cwidth;             /* 0x00 chroma plane width (32-byte rounded half width) */
	Sint32 cheight;            /* 0x04 */
	Sint32 width;              /* 0x08 */
	Sint32 height;             /* 0x0C */
	Sint32 x10;
	Sint32 max_width;          /* 0x14 */
	Sint32 max_height;         /* 0x18 */
	Sint32 nfrm;               /* 0x1C */
	Sint32 x20;
} MWSFD_MPVPARA;

/* reference frame buffer pair (mwsfcre_MallocRfb output) */
typedef struct {
	void *buf[2];
} MWSFD_RFB;

extern void mwSfdStopDec(MWPLY mwply);
extern void MWSFTAG_DestroyAinfSj(MWPLY mwply);
extern void MWSFSFX_Destroy(SFX_OBJ *sfx);
extern void MWSTM_Destroy(void *stm);
extern Sint32 SFD_Destroy(void *sfd);
extern Sint32 MWSFSFX_CalcHnWorkSiz(Sint32 width, Sint32 height);
extern Bool MWSFTAG_IsUseAinfSj(MWSFD_CRPRM *prm);
extern void SFD_AnalyCreInf(void *data, Sint32 size, SFD_CREINF *inf);
extern void MWSFFRM_AnalyTotalFrmNum(void *data, Sint32 size, MWSFD_HDRINF *inf);
extern Sint32 MWSFD_GetUsePicUsr(void);
extern Sint32 SFD_SetPicUsrBuf(void *sfd, void *buf, Sint32 num, Sint32 usize);
extern Sint32 SFD_SetMpvCond(void *sfd, Sint32 id, Sint32 val);
extern Sint32 SFD_GetTrHn(void *sfd, Sint32 strm, void **hn);
extern void MWSFSVR_SetHnMwplySvrFlg(MWPLY mwply, Sint32 flg);
extern void MWSFSVR_SetHnSfdSvrFlg(MWPLY mwply, Sint32 flg);
extern void *MWSTM_Create(SJ sj);
extern void MWSFPLY_SetFlowLimit(MWPLY mwply);
extern SFX_OBJ *MWSFSFX_Create(void *work, Sint32 wsize, Sint32 width, Sint32 height);
extern void MWSFSFX_SetCompoMode(MWPLY mwply, Sint32 mode);
extern SJ MWSFTAG_CreateAinfSj(MWPLY mwply);
extern Sint32 MWSFTAG_SetAinfSj(MWPLY mwply);
extern void MWSFTAG_InitTagInf(MWPLY mwply);
extern void MWSFFRM_InitSfhInfTable(MWPLY mwply);
extern void MWSFFRM_SetShfCbFn(MWPLY mwply);
extern Sint32 SFD_Stop(void *sfd);
extern Sint32 SFD_SetErrFn(void *sfd, void (*fn)(void *obj, Sint32 code), void *obj);
extern void SFD_SetMpvParaTbl(MWSFD_MPVPARA *para, MWSFD_RFB *rfb, void **frmtbl);
extern void SFD_SetAdxtPara(SFADXT_PARA *para);
extern SFD SFD_Create(SFD_CREPRM *prm, Sint32 x);
extern Sint32 SFD_SetSupplySj(void *sfd, SFBUF_SUP *sup);

extern void mwSfdVsync(void);
extern Sint32 mwSfdExecSvrHndl(MWPLY mwply);
extern void mwSfdStartFname(MWPLY mwply, const Char8 *fname);
extern void mwSfdStop(MWPLY mwply);
extern void mwSfdGetTime(MWPLY mwply, Sint32 *ncount, Sint32 *tscale);
extern void mwSfdPause(MWPLY mwply, Sint32 sw);
extern void mwSfdSetOutVol(MWPLY mwply, Sint32 vol);
extern Sint32 mwSfdGetOutVol(MWPLY mwply);
extern void mwSfdSetOutPan(MWPLY mwply, Sint32 ch, Sint32 pan);
extern Sint32 mwSfdGetOutPan(MWPLY mwply, Sint32 ch);
extern void mwSfdStartSj(MWPLY mwply, SJ sj);
extern void mwSfdStartMem(MWPLY mwply, void *buf, Sint32 size);

void mwSfdDestroy(MWPLY mwply);
static void *mwsfcre_CreateSfd(MWPLY mwply, MWSFD_CRPRM *cprm);
Sint32 mwsfcre_MallocRfb(MWPLY mwply, MWSFD_CRPRM *cprm, MWSFD_RFB *rfb);
Sint32 mwPlyCalcWorkSfd(MWSFD_CRPRM *cprm);

#define MWSFD_FTYPE_SFD 1
#define MWSFD_FTYPE_MPV 2
#define MWSFD_FTYPE_VONLYSFD 3

#define MWSFD_HNWORK_SIZE 0x4000
#define MWSFD_PICUSR_SIZE 0x800
#define MWSFD_PICUSR_UNIT 0x40
#define MWSFD_FNAME_SIZE 0x100
#define MWSFD_AINFSJ_BSIZE 0x20000

static const SFD_TR_IF *const mwsfd_mps_trsetup[SFD_TR_NUM] = {
	&SFD_tr_in_mem, &SFD_tr_sd_mps, &SFD_tr_vd_mpv, &SFD_tr_ad_adxt, NULL, NULL,
	&SFD_tr_vo_manu, &SFD_tr_ao_auto_p, &SFD_tr_uo,
};
static const SFD_TR_IF *const mwsfd_mpv_trsetup[SFD_TR_NUM] = {
	&SFD_tr_in_mem, NULL, &SFD_tr_vd_mpv, NULL, NULL, NULL, &SFD_tr_vo_manu, NULL, NULL,
};
const SFD_TR_IF *const mwsfd_vonlysfd_trsetup[SFD_TR_NUM] = {
	&SFD_tr_in_mem, &SFD_tr_sd_mps, &SFD_tr_vd_mpv, NULL, NULL, NULL, &SFD_tr_vo_manu, NULL, &SFD_tr_uo,
};

MWPLY_IF mwsfd_if = {
	NULL, NULL, NULL,
	mwSfdVsync, mwSfdExecSvrHndl, mwSfdDestroy, mwSfdStartFname, mwSfdStop, mwSfdGetStat,
	mwSfdGetTime, mwSfdPause, mwSfdSetOutVol, mwSfdGetOutVol, mwSfdSetOutPan, mwSfdGetOutPan,
	mwSfdStartSj, mwSfdStartMem,
};

MWSFD_SFDCREPRM mwsfd_sfdmps_crepara = {
	mwsfd_mps_trsetup, 0, { 0x10000, 0x50800, 0x12000, 0, 0, 0, 0 }, 0, 0x800, 3, 0, 0, 3, NULL, 0,
};
MWSFD_SFDCREPRM mwsfd_sfdmpv_crepara = {
	mwsfd_mpv_trsetup, 0, { 0x10000, 0x50800, 0x12000, 0, 0, 0, 0 }, 0, 0x800, 3, 0, 0, 3, NULL, 0,
};
MWSFD_SFDCREPRM mwsfd_vonlysfd_crepara = {
	mwsfd_vonlysfd_trsetup, 0, { 0x10000, 0x50800, 0x12000, 0, 0, 0, 0 }, 0, 0x800, 3, 0, 0, 3, NULL, 0,
};
MWSFD_MPVPARA mwsfd_mpvpara = { 0xC0, 0xF0, 0x160, 0x1E0, 0, 0x160, 0x1E0, 4, 0 };
SFADXT_PARA mwsfd_adxtpara = { 0x5DCC, 0x120, NULL, 2, 0xBB80, 0xC1C0, NULL };
Sint32 mwsfd_packsize = 0x800;

/* user-supplied frame buffers */
Sint32 mwsfdcre_bufnum;
Sint32 mwsfdcre_bufsize;
void *mwsfdcre_bufptr[16];
/* component buffer sizes decided by mwsfcre_CreateSfd */
static Sint32 adxibuf;         /* ADXT input ring buffer */
Sint32 adxwk;                  /* ADXT work */
Sint32 tab;                    /* decoded frame buffers */
Sint32 rfb;                    /* reference frame buffers */
Sint32 aib;                    /* audio input buffer */
Sint32 vib;                    /* video input buffer */
Sint32 sib;                    /* system input buffer */
Sint32 sjb;                    /* file stream joint ring buffer */
static Uint32 mwsfd_sisjadr;   /* 64-byte aligned start of the stream joint ring buffer */

/* allocate a component buffer: from the user work when one was given, else through the library's
 * malloc callback; every block is remembered so mwSfdDestroy can free it (dead-stripped, inlined) */
void *MWSFD_Malloc(MWPLY mwply, Sint32 size)
{
	MWSFD_LIBWORK *lw;
	void *ptr;

	if (mwply->cwk_cnt >= MWSFD_CWK_NUM) {
		MWSFSVM_Error("E2053001 MWSFD_Malloc: cnt over.");
		return NULL;
	}
	if (size < 0) {
		return NULL;
	}
	if (mwply->cwk_buf != NULL) {
		if (mwply->cwk_used + size > mwply->cwk_size) {
			ptr = NULL;
		} else {
			ptr = mwply->cwk_ptr;
			mwply->cwk_ptr += size;
			mwply->cwk_used += size;
		}
	} else {
		lw = MWSFLIB_GetLibWorkPtr();
		ptr = lw->malloc_fn(lw->mem_obj, size);
	}
	if (ptr != NULL) {
		mwply->cwk_tbl[mwply->cwk_cnt] = ptr;
		mwply->cwk_cnt++;
	}
	return ptr;
}

// Releases every component block in reverse allocation order (through the library free callback
// when no user work was given) and empties the block table.
static void mwsfcre_FreeAll(MWPLY mwply)
{
	MWSFD_LIBWORK *lw;
	Sint32 i;
	void *ptr;

	for (i = 0; i < MWSFD_CWK_NUM; i++) {
		ptr = mwply->cwk_tbl[MWSFD_CWK_NUM - 1 - i];
		if (ptr != NULL) {
			if (mwply->cwk_buf == NULL) {
				lw = MWSFLIB_GetLibWorkPtr();
				lw->free_fn(lw->mem_obj, ptr);
			}
			mwply->cwk_cnt--;
			mwply->cwk_tbl[MWSFD_CWK_NUM - 1 - i] = NULL;
		}
	}
}

/* file type from the drivers SFD_AnalyCreInf found */
static Sint32 mwsfcre_GetFtype(SFD_CREINF *inf)
{
	Sint32 ftype = 0;

	if (inf->strif == NULL) {
		if (inf->vtrif != NULL && inf->atrif == NULL) {
			ftype = MWSFD_FTYPE_MPV;
		}
	} else {
		if (inf->atrif == NULL) {
			ftype = MWSFD_FTYPE_VONLYSFD;
		} else {
			ftype = MWSFD_FTYPE_SFD;
		}
	}
	return ftype;
}

// Analyses the first `size` bytes of a Sofdec file (the game reads 0x5000 bytes in cSofdec::initApp):
// file type (1 Sofdec A/V, 2 MPEG video only, 3 video-only Sofdec), picture size, frame rate, audio
// rate/channels and the total frame count from the Sofdec header. valid = 0 when it is not playable.
void mwPlyGetHdrInf(void *data, Sint32 size, MWSFD_HDRINF *hdrinf)
{
	MWSFD_HDRINF inf;
	SFD_CREINF cinf;

	if (data == NULL || hdrinf == NULL) {
		MWSFSVM_Error("E204161: mwPlyGetHdrInf(): NULL pointer");
		return;
	}
	if (size <= 0) {
		MWSFSVM_Error("E204162: mwPlyGetHdrInf(): bufsize error");
		return;
	}
	memset(&inf, 0, sizeof(inf));
	SFD_AnalyCreInf(data, size, &cinf);
	if (cinf.creatable == 0 || cinf.avail == 0) {
		*hdrinf = inf;
		hdrinf->valid = 0;
		return;
	}
	inf.mode = mwsfcre_GetFtype(&cinf);
	inf.width = cinf.picw;
	inf.height = cinf.pich;
	inf.picrate = cinf.picrate;
	inf.afreq = cinf.afreq;
	inf.ach = cinf.ach;
	MWSFFRM_AnalyTotalFrmNum(data, size, &inf);
	inf.valid = (inf.mode != 0);
	*hdrinf = inf;
}

/* release the decoder side of a handle and clear it (dead-stripped, inlined into mwSfdDestroy) */
void MWSFCRE_DestroySfd(MWPLY mwply)
{
	if (mwply->lsc != NULL) {
		LSC_Destroy(mwply->lsc);
	}
	if (mwply->stm != NULL) {
		MWSTM_Destroy(mwply->stm);
	}
	if (mwply->file_sj != NULL) {
		SJ_Destroy(mwply->file_sj);
	}
	if (mwply->mem_sj != NULL) {
		SJ_Destroy(mwply->mem_sj);
	}
	if (mwply->sfd != NULL) {
		if (SFD_Destroy(mwply->sfd) != 0) {
			MWSFLIB_SetErrCode(-0x132);
			MWSFSVM_Error("E20010703E MWSFCRE_DestroySfd: ");
		}
	}
	MWSST_Destroy(&mwply->sst);
	mwsfcre_FreeAll(mwply);
	if (mwply->cwk_cnt != 0) {
		MWSFSVM_Error("E2053005: forgot free.");
	}
	memset(mwply, 0, sizeof(MWPLY_OBJ));
	mwply->used = 0;
	mwply->ifc = &mwsfd_if;
}

// MWPLY_IF.Destroy (mwPlyDestroy): stops the decoder, destroys the additional-info stream joint and
// the SFX converter, then the SFD handle, scheduler, stream controller and joints (MWSFCRE_DestroySfd)
// and frees the component work.
void mwSfdDestroy(MWPLY obj)
{
	MWPLY mwply = (MWPLY)(MWPLY_OBJ *)obj;

	if (mwply == NULL) {
		return;
	}
	mwSfdStopDec(mwply);
	mwply->used = 0;
	MWSFTAG_DestroyAinfSj(mwply);
	if (mwply->sfx != NULL) {
		MWSFSFX_Destroy(mwply->sfx);
	}
	MWSFCRE_DestroySfd(mwply);
}

/* SFX handle work and additional-information stream joint buffer */
/* COMPILER-DIFF: M1 (codeless K-pin) - the original colours mwply (r31) before the .rodata pool base
 * (r30), i.e. mwply survives the second Chaitin scan. The kept `void *` copy declared last is visited
 * first in that scan with 25 never-removed neighbours (11 volatile registers, 11 r3 ghosts of the call
 * results, pool, prm, size) and needs 29; every plain form removes it there (pool r31, mwply r28..r30).
 * The asm copies to four volatile registers no value of this function takes remove those four from
 * the colour set (K 29 -> 25), all five `mr` are deleted (r5/r6/r7 in place of r8/r9/r10 give identical
 * bytes; three registers do not hold it). */
Sint32 mwsfcre_MallocCompoWork(void *obj)
{
	MWSFD_CRPRM *prm;
	Sint32 size;
	void *wk;
	register MWPLY mwply = obj;

	 // COMPILER-DIFF: M1 (codeless K-pin)
	prm = &mwply->prm;
	size = MWSFSFX_CalcHnWorkSiz(prm->max_width, prm->max_height);
	wk = MWSFD_Malloc(mwply, size);
	if (wk == NULL) {
		MWSFSVM_Error("E2053003: not enough work: sfx_wk");
		mwsfcre_FreeAll(mwply);
		return -1;
	}
	mwply->sfx_wk = wk;
	mwply->sfx_wksiz = size;
	if (MWSFTAG_IsUseAinfSj(prm) == TRUE) {
		wk = MWSFD_Malloc(mwply, MWSFD_AINFSJ_BSIZE);
		if (wk == NULL) {
			MWSFSVM_Error("E2053004: not enough work: ainfsj_buf");
			mwsfcre_FreeAll(mwply);
			return -1;
		}
		mwply->ainf_buf = wk;
		mwply->ainf_bsize = MWSFD_AINFSJ_BSIZE;
	} else {
		mwply->ainf_buf = NULL;
		mwply->ainf_bsize = 0;
	}
	return 0;
}

/* dead: user frame buffers instead of the component work. Fixes the .bss order (MWCC lays .bss out in
 * first-reference order over the TU) and sits AFTER mwsfcre_MallocCompoWork, the first function that
 * pools .rodata: the per-function pool bases are created in the reverse of the TU-wide order in which
 * the sections were first POOLED (rodata by MallocCompoWork, bss by this function, data by
 * mwsfcre_CreateSfd), which is what colours CreateSfd's bases rodata r31 / bss r30 / data r29. */
void mwPlySetFrmBuf(Sint32 num, Sint32 size, void **buf)
{
	Sint32 i;

	mwsfdcre_bufnum = num;
	mwsfdcre_bufsize = size;
	for (i = 0; i < 16; i++) {
		mwsfdcre_bufptr[i] = buf[i];
	}
	adxibuf = 0;
	adxwk = 0;
	tab = 0;
	rfb = 0;
	aib = 0;
	vib = 0;
	sib = 0;
	sjb = 0;
	mwsfd_sisjadr = 0;
}

// Only frame buffer formats 0 (default) and 3 (planar YCC 4:2:0) are accepted.
static Bool mwsfcre_IsValidBufFmt(MWSFD_CRPRM *cprm)
{
	Bool ret = TRUE;

	if (cprm->buffmt != 0 && cprm->buffmt != 3) {
		MWSFSVM_Error("E3012102: Buffer format is invalid.");
		ret = FALSE;
	}
	return ret;
}

/* -1 when the component work has to come from the library callbacks and none were registered */
// FUN_005095F0
static Sint32 mwsfcre_ChkMallocFn(MWSFD_CRPRM *cprm)
{
	MWSFD_LIBWORK *lw = MWSFLIB_GetLibWorkPtr();
	Sint32 ret = 0;

	if (cprm->work == NULL) {
		if (lw->malloc_fn == NULL) {
			ret = -1;
		}
		if (lw->free_fn == NULL) {
			ret = -1;
		}
	}
	return ret;
}

// Starts the component allocator on the caller's work (MWSFD_CRPRM.work / wksize): nothing used, no
// blocks recorded.
static void mwsfcre_InitCompoWork(MWPLY mwply, MWSFD_CRPRM *cprm)
{
	Sint32 i;

	mwply->cwk_buf = cprm->work;
	mwply->cwk_size = cprm->wksize;
	mwply->cwk_ptr = cprm->work;
	mwply->cwk_used = 0;
	mwply->cwk_cnt = 0;
	for (i = 0; i < MWSFD_CWK_NUM; i++) {
		mwply->cwk_tbl[i] = NULL;
	}
}

/* largest integer not above f */
#define MWSFCRE_FLOOR(f, n) \
	{ \
		n = (Sint32)(f); \
		if ((Float32)n > (f)) { \
			n--; \
		} \
	}

/* component buffer sizes for a file type: the system / video / audio input buffers, the file
 * stream joint ring buffer and the ADXT buffers. mwsfcre_CreateSfd's copy (mode is its own local,
 * initialised at the declaration = the target's first load): the computed sizes come FIRST in every
 * arm, so the merged `li 0` of the constant stores gets a higher temp id than the bps chain and is
 * coloured first (`li r3, 0`, chain r4..). */
#define MWSFCRE_CALC_BUFSIZ(cprm, mode, sib, vib, aib, sjb, adxibuf, adxwk) \
	{ \
		Sint32 nsec = (cprm)->nsec; \
		Sint32 bps; \
		bps = (cprm)->max_bps; \
		if (nsec <= 0) { \
			nsec = 1; \
		} \
		if (mode == MWSFD_FTYPE_MPV) { \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
			sib = 0; \
			vib = 0; \
			aib = 0; \
			adxibuf = 0; \
			adxwk = 0; \
		} else if (mode == MWSFD_FTYPE_VONLYSFD) { \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
			vib = bps / 8 / 0x800 * 0x800 / 2 + 0x800; \
			sib = 0; \
			aib = 0; \
			adxibuf = 0; \
			adxwk = 0; \
		} else { \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
			vib = bps / 8 / 0x800 * 0x800 / 2 + 0x800; \
			sib = 0; \
			aib = 0x5DCC; \
			adxibuf = 0x5F0C; \
			adxwk = 0xC1C0; \
		} \
	}

/* one YCC 4:2:0 frame: 16-aligned dimensions, 32-byte rows, 32 bytes of slack */
/* h16 declared before w16: w16 (higher inlined-local id) coloured first (w16 r10 / h16 r11) */
static Sint32 mwsfcre_CalcYccSize(Sint32 width, Sint32 height)
{
	Sint32 h16;
	Sint32 w16;
	Sint32 ysize;
	Sint32 csize;

	w16 = (width + 15) / 16 * 16;
	h16 = (height + 15) / 16 * 16;
	ysize = h16 * ((w16 + 31) / 32 * 32);
	csize = (h16 / 2) * ((w16 / 2 + 31) / 32 * 32);

	return ysize + csize * 2 + 0x20;
}

/* frame buffer size of the creation parameters (the format check is repeated at every use so the
 * string lands where the original emitted it) */
#define MWSFCRE_CALC_FRMSIZ(cprm, fsize) \
	{ \
		Sint32 height; \
		Sint32 width; \
		width = (cprm)->max_width; \
		height = (cprm)->max_height; \
		if ((cprm)->buffmt >= 4 || (cprm)->buffmt < 0) { \
			MWSFSVM_Error("E206011: MwsfdCrePrm: illigal buffmt."); \
		} \
		fsize = mwsfcre_CalcYccSize(width, height); \
	}

/* COMPILER-DIFF: M1 (codeless arm) - the original's `case 4:` arm came FIRST and held a statement
 * the frontend kept but a backend pass deleted: its block (`b T`) is laid out between the tree
 * and the FALSE arm, so the emptied block still needs its branch (the two dead `b` of the
 * inlined copies in mwsfcre_CreateSfd, 0x2c28). An empty arm is folded onto the default label at
 * the frontend and an arm laid out after the FALSE arm falls into T without a `b`. The asm
 * self-copy is the codeless stand-in: kept by the frontend, deleted by the RA (CRI pass 66). */
static Bool mwsfcre_IsUseAdxt(register Sint32 mode)
{
	switch (mode) {
	case 4:
		
		break;
	case MWSFD_FTYPE_MPV:
	case MWSFD_FTYPE_VONLYSFD:
		return FALSE;
	default:
		break;
	}
	return TRUE;
}

/* hand the picture user data buffer to the decoder: one slot per frame that may be in flight.
 * Inlined helper (not a macro): its locals rank above the frontend's strength-reduction temporaries
 * of the inlined mwSfdDestroy loops, which then take the lowest handed-out registers r23/r24/r25
 * instead of fresh ones (frame 0x50 = 9 callee-saved registers, target). Declared buf, usize,
 * nskip: nskip (last) colours first (r27), usize r25, buf r24. */
static inline void mwsfcre_AttachPicUsrBuf(MWPLY mwply)
{
	MWSFD_PICUSR *pu = mwply->picusr_ptr;
	void *buf;
	Sint32 usize;
	Sint32 nskip;

	if (pu == NULL) {
		MWSFSVM_Error("E02120501: Internal Error: mwsfcre_AttachPicUsrBuf().");
	} else {
		nskip = mwply->prm.max_skip;
		usize = pu->usize;
		buf = pu->buf;
		if (pu->bsize < (nskip + 3) * usize) {
			MWSFSVM_Error("E02120502: mwsfcre_AttachPicUsrBuf(): usrdatbuf is short.");
		} else if (MWSFD_GetUsePicUsr() == 1) {
			SFD_SetPicUsrBuf(mwply->sfd, buf, nskip + 3, usize);
		}
	}
}

/* decoder conditions of a new handle: the frame pool size in frames of the reference rate.
 * Inlined helper for the same reason; sfdhn (declared last) r24, vfreq r25, npool r23, nfrm r23. */
static inline void mwsfcre_SetSfdCond(MWPLY mwply, MWSFD_LIBWORK *lw)
{
	Float32 ftime;
	Sint32 nfrm;
	Sint32 npool;
	Sint32 vfreq;
	void *sfdhn;

	sfdhn = mwply->sfd;
	npool = lw->nfrm_pool;
	vfreq = lw->x08;
	SFD_SetCond(sfdhn, 8, 0);
	SFD_SetCond(sfdhn, 1, 1);
	SFD_SetCond(sfdhn, 0, 0);
	SFD_SetCond(sfdhn, 0x17, 4);
	ftime = 0.5f + (Float32)(vfreq * npool * 1000);
	MWSFCRE_FLOOR(ftime, nfrm);
	SFD_SetCond(sfdhn, 0x2D, nfrm);
	SFD_SetCond(sfdhn, 0x2C, nfrm);
	SFD_SetCond(sfdhn, 0x2A, nfrm);
	SFD_SetCond(sfdhn, 0xF, 2);
	SFD_SetCond(sfdhn, 0x33, 0);
	SFD_SetCond(sfdhn, 0xE, 0);
	SFD_SetCond(sfdhn, 0x1C, 0);
	SFD_SetMpvCond(sfdhn, 5, 0);
}

/* mwPlyCalcWorkSfd's copy of the size macro: `mode` is a block local declared after bps (bps r0,
 * mode r4 = the target's colouring; a function-level mode is coloured first). */
#define CWS_BUFSIZ(cprm, sib, vib, aib, sjb, adxibuf, adxwk) \
	{ \
		Sint32 nsec = (cprm)->nsec; \
		Sint32 bps; \
		Sint32 mode; \
		mode = (cprm)->mode; \
		bps = (cprm)->max_bps; \
		if (nsec <= 0) { \
			nsec = 1; \
		} \
		if (mode == MWSFD_FTYPE_MPV) { \
			sib = 0; \
			vib = 0; \
			aib = 0; \
			adxibuf = 0; \
			adxwk = 0; \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
		} else if (mode == MWSFD_FTYPE_VONLYSFD) { \
			sib = 0; \
			aib = 0; \
			adxibuf = 0; \
			adxwk = 0; \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
			vib = bps / 8 / 0x800 * 0x800 / 2 + 0x800; \
		} else { \
			sib = 0; \
			aib = 0x5DCC; \
			sjb = nsec * (bps / 8 / 0x800 * 0x800); \
			vib = bps / 8 / 0x800 * 0x800 / 2 + 0x800; \
			adxibuf = 0x5F0C; \
			adxwk = 0xC1C0; \
		} \
	}

// Creates a player handle from the creation parameters (the game: ftype 1, max_bps 8 Mbit/s, frame
// pool 4, movie size, max_stm 2, work from mwPlyCalcWorkCprmSfd): takes one of the 8 MWPLY slots,
// builds the SFD decoder with the buffers of the file type (mwsfcre_CreateSfd), the decoder
// conditions (frame pool in 1/1000 s of the refresh rate), the file and memory stream joints, the
// ADXSTM controller + LSC scheduler feeding the file joint, the SFX frame converter and the
// additional-info joint, and installs the Sofdec header callback. NULL with an error on any failure.
MWPLY mwPlyCreateSofdec(MWSFD_CRPRM *cprm)
{
	MWSFD_LIBWORK *lw;
	MWPLY mwply;
	void *sfd;
	Sint32 sibsiz;
	Sint32 vibsiz;
	Sint32 aibsiz;
	Sint32 sjbsiz;
	Sint32 adxibsiz;
	Sint32 adxwksiz;
	Sint32 i;
	SFX_OBJ *sfx;

	if (cprm == NULL) {
		MWSFSVM_Error("E1122612 mwPlyCreateSofdec : cprm is NULL.");
		return NULL;
	}
	if (mwsfcre_IsValidBufFmt(cprm) != TRUE) {
		return NULL;
	}
	lw = MWSFLIB_GetLibWorkPtr();
	for (i = 0; i < MWSFD_MAX_HN; i++) {
		mwply = &lw->hn[i];
		if (mwply->used == 0) {
			break;
		}
	}
	if (i == MWSFD_MAX_HN) {
		MWSFLIB_SetErrCode(-0xB);
		MWSFSVM_Error("E4061801 mwPlyCreateSofdec: Number of MWPLY handles exceeds its maximum number.");
		return NULL;
	}
	if (mwsfcre_ChkMallocFn(cprm) == -1) {
		MWSFSVM_Error("E2053006 mwPlyCreateSofdec: Didn't set malloc/free func.");
		return NULL;
	}
	if (mwply != NULL) {
		memset(mwply, 0, sizeof(MWPLY_OBJ));
	}
	mwsfcre_InitCompoWork(mwply, cprm);
	mwply->prm = *cprm;
	sfd = mwsfcre_CreateSfd(mwply, cprm);
	mwply->sfd = sfd;
	if (mwply->sfd == NULL) {
		MWSFSVM_Error("E2012 mwPlyCreate:can't create SFD");
		mwSfdDestroy(mwply);
		return NULL;
	}
	mwsfcre_AttachPicUsrBuf(mwply);
	CWS_BUFSIZ(cprm, sibsiz, vibsiz, aibsiz, sjbsiz, adxibsiz, adxwksiz);
	mwsfcre_SetSfdCond(mwply, lw);
	mwply->file_sj = SJRBF_Create((void *)mwply->x1d8, mwply->flow_nsct, mwply->x1e0);
	if (mwply->file_sj == NULL) {
		MWSFSVM_Error("E2013 mwPlyCreate:can't create SJ");
		mwSfdDestroy(mwply);
		return NULL;
	}
	mwply->mem_sj = SJMEM_Create(NULL, 0);
	if (mwply->mem_sj == NULL) {
		MWSFSVM_Error("E2020 mwPlyCreate:can't create SJ");
		mwSfdDestroy(mwply);
		return NULL;
	}
	mwply->ifc = &mwsfd_if;
	mwply->x5c = sjbsiz;
	mwply->x3c = 1;
	mwply->dec_svr_flg = 0;
	mwply->stat = MWSFD_STAT_STOP;
	mwply->compo_fix = cprm->compo;
	mwply->compo = cprm->compo;
	if (SFD_GetTrHn(sfd, 3, (void **)&mwply->x48) != 0) {
		mwply->x48 = 0;
	}
	mwply->x70 = 1;
	mwply->linkstm = 0;
	mwply->linkstm_req = 0;
	mwply->pause_flg = 0;
	mwply->pad77 = 0;
	mwply->sleep_bdr = 0;
	MWSFSVR_SetHnMwplySvrFlg(mwply, 0);
	MWSFSVR_SetHnSfdSvrFlg(mwply, 0);
	mwply->noskip = 1;
	mwply->nskipdisp = 0;
	mwply->stm = MWSTM_Create(mwply->file_sj);
	if (mwply->stm == NULL) {
		mwSfdDestroy(mwply);
		return NULL;
	}
	MWSFPLY_SetFlowLimit(mwply);
	mwply->lsc = LSC_Create(mwply->file_sj);
	mwply->x78 = 0;
	LSC_SetStmHndl(mwply->lsc, mwply->stm);
	if (mwsfcre_MallocCompoWork(mwply) == -1) {
		mwSfdDestroy(mwply);
		return NULL;
	}
	sfx = MWSFSFX_Create(mwply->sfx_wk, mwply->sfx_wksiz, cprm->max_width, cprm->max_height);
	if (sfx == NULL) {
		MWSFSVM_Error("E201185: can't create SfxHn");
		mwSfdDestroy(mwply);
		return NULL;
	}
	mwply->sfx = sfx;
	MWSFSFX_SetCompoMode(mwply, mwply->prm.compo);
	mwply->ainf_sj = MWSFTAG_CreateAinfSj(mwply);
	if (MWSFTAG_SetAinfSj(mwply) != 0) {
		MWSFSVM_Error("E201212 mwPlyCreate: can't set AddInfSJ");
		mwSfdDestroy(mwply);
		return NULL;
	}
	MWSFTAG_InitTagInf(mwply);
	MWSFFRM_InitSfhInfTable(mwply);
	MWSFFRM_SetShfCbFn(mwply);
	mwply->used = 1;
	return mwply;
}

// Before a new play: stops the SFD handle, re-installs the error callback and re-attaches the
// picture user data buffer (max_skip + 3 slots).
Sint32 MWSFCRE_ResetSfdHn(MWPLY mwply)
{
	MWSFD_PICUSR *pu;
	Sint32 nskip;
	Sint32 usize;
	void *buf;
	void *sfd;

	sfd = mwply->sfd;
	if (SFD_Stop(sfd) != 0) {
		MWSFSVM_Error("E0203261: MWSFCRE_ResetSfdHn: SFD_Stop() failed.");
		return -1;
	}
	if (SFD_SetErrFn(sfd, MWSFLIB_SfdErrFunc, mwply) != 0) {
		MWSFLIB_SetErrCode(-0x12F);
		MWSFSVM_Error("E0203262: MWSFCRE_ResetSfdHn: SFD_SetErrFn() failed.");
		return -1;
	}
	/* the picture user data buffer again (MWSFCRE_ATTACH_PICUSRBUF written out: the locals are
	 * the function's own, declared above the handle) */
	pu = mwply->picusr_ptr;
	if (pu == NULL) {
		MWSFSVM_Error("E02120501: Internal Error: mwsfcre_AttachPicUsrBuf().");
	} else {
		nskip = mwply->prm.max_skip;
		usize = pu->usize;
		buf = pu->buf;
		if (pu->bsize < (nskip + 3) * usize) {
			MWSFSVM_Error("E02120502: mwsfcre_AttachPicUsrBuf(): usrdatbuf is short.");
		} else if (MWSFD_GetUsePicUsr() == 1) {
			SFD_SetPicUsrBuf(mwply->sfd, buf, nskip + 3, usize);
		}
	}
	return 0;
}

/* dead: user-supplied picture user data buffer */
void mwPlyAttachPicUsrBuf(MWPLY mwply, void *buf, Sint32 bsize, Sint32 usize)
{
	if (bsize < (mwply->prm.max_skip + 3) * usize) {
		MWSFSVM_Error("E02120503: mwPlyAttachPicUsrBuf(): bufsize is short.");
		return;
	}
	mwply->picusr.buf = buf;
	mwply->picusr.bsize = bsize;
	mwply->picusr.usize = usize;
	MWSFCRE_ATTACH_PICUSRBUF(mwply);
}

// Creation buffmt -> SFD frame buffer format (0 and 3 -> 3 planar; 1, 2 pass through).
static Sint32 mwsfcre_CnvBufFmt(Sint32 buffmt)
{
	Sint32 fmt;

	switch (buffmt) {
	case 0:
		fmt = 3;
		break;
	case 1:
		fmt = 1;
		break;
	case 2:
		fmt = 2;
		break;
	case 3:
		fmt = 3;
		break;
	default:
		MWSFSVM_Error("E206011: MwsfdCrePrm: illigal buffmt.");
		fmt = 3;
		break;
	}
	return fmt;
}

// MWSFD_Malloc through a local (keeps the original's size test; see the register note below).
static void *mwsfcre_MallocWk(MWPLY mwply, Sint32 wksize)
{
	Sint32 size = wksize;

	return MWSFD_Malloc(mwply, size);
}

/* the same wrapper without the local: the constant folds (no `cmpwi size, 0`), but the inner Malloc's
 * result temp is numbered with the MallocWk ones (inlined helpers are cloned breadth-first: a
 * two-level result is numbered after every one-level result), so picusr_p > hnwork_p > buf700_p >
 * fname_p in call order (r25..r22) */
static void *mwsfcre_MallocX(MWPLY mwply, Sint32 size)
{
	return MWSFD_Malloc(mwply, size);
}

/* the decoded frame buffers: user frame buffers 2.. or one component allocation per frame.
 * Inlined helper: its `ret` is a temp numbered between the cwk2 and picusr_p Malloc results (r26) */
static Sint32 mwsfcre_MallocFrmTbl(MWPLY mwply, MWSFD_CRPRM *cprm, void **frmtbl)
{
	Sint32 ret = 0;
	Sint32 height;
	Sint32 width;
	Sint32 nfrm = cprm->max_skip;
	Sint32 fsize;
	Sint32 i;

	/* the size macro expanded by hand so height/width are declared BEFORE nfrm: inlined-helper
	 * locals take ids in declaration order and the L2 nodes colour by descending id, so nfrm
	 * (declared after height) takes r19 and height r20 (the macro's block locals came after nfrm) */
	width = cprm->max_width;
	height = cprm->max_height;
	if (cprm->buffmt >= 4 || cprm->buffmt < 0) {
		MWSFSVM_Error("E206011: MwsfdCrePrm: illigal buffmt.");
	}
	fsize = mwsfcre_CalcYccSize(width, height);
	if (mwsfdcre_bufnum != 0) {
		if (mwsfdcre_bufnum < nfrm + 2 || mwsfdcre_bufsize < fsize) {
			ret = -1;
		} else {
			for (i = 0; i < nfrm; i++) {
				frmtbl[i] = mwsfdcre_bufptr[i + 2];
				if (frmtbl[i] == NULL) {
					ret = -1;
				}
			}
		}
	} else {
		for (i = 0; i < nfrm; i++) {
			frmtbl[i] = MWSFD_Malloc(mwply, fsize);
			if (frmtbl[i] == NULL) {
				ret = -1;
			}
		}
	}
	return ret;
}

/* create the SFD decoder handle of a player: decide the component buffer sizes, allocate them
 * and fill the creation parameters of the file type. Own locals colour in declaration order:
 * mode r21, adxibuf_p r20, adxwk_p r19, nfrm r18, (width spilled), height r17 */
static void *mwsfcre_CreateSfd(MWPLY mwply, MWSFD_CRPRM *cprm)
{
	Sint32 mode = cprm->mode;
	void *adxibuf_p;
	void *adxwk_p;
	Sint32 nfrm = cprm->max_skip;
	Sint32 width = cprm->max_width;
	Sint32 height = cprm->max_height;
	MWSFD_RFB rfbbuf;
	void *frmtbl[16];
	MWSFD_SFDCREPRM crepara;
	Sint32 size;
	void *cwk1;
	void *cwk2;
	Sint32 rfbret;
	Sint32 frmret;
	Sint32 fsize;
	Sint32 nfrm2;
	void *picusr_p;
	void *hnwork_p;
	void *buf700_p;
	void *fname_p;
	Sint32 fmt;
	void *sfd;

	MWSFCRE_CALC_BUFSIZ(cprm, mode, sib, vib, aib, sjb, adxibuf, adxwk);
	if (mwsfdcre_bufnum != 0) {
		rfb = 0;
		tab = 0;
	} else {
		nfrm2 = cprm->max_skip;
		MWSFCRE_CALC_FRMSIZ(cprm, fsize);
		rfb = fsize * 2;
		tab = nfrm2 * fsize;
	}
	size = sib + vib + aib + 0x20;
	cwk1 = MWSFD_Malloc(mwply, size);
	size = sjb + 0x40;
	cwk2 = MWSFD_Malloc(mwply, size);
	rfbret = mwsfcre_MallocRfb(mwply, cprm, &rfbbuf);
	frmret = mwsfcre_MallocFrmTbl(mwply, cprm, frmtbl);
	if (mwsfcre_IsUseAdxt(mode) == TRUE) {
		size = adxibuf;
		adxibuf_p = MWSFD_Malloc(mwply, size);
		size = adxwk;
		adxwk_p = MWSFD_Malloc(mwply, size);
	} else {
		adxibuf_p = NULL;
		adxwk_p = NULL;
	}
	picusr_p = mwsfcre_MallocX(mwply, MWSFD_PICUSR_SIZE);
	hnwork_p = mwsfcre_MallocWk(mwply, MWSFD_HNWORK_SIZE);
	buf700_p = mwsfcre_MallocWk(mwply, 0x700);
	fname_p = mwsfcre_MallocX(mwply, MWSFD_FNAME_SIZE);
	if (cwk1 == NULL || cwk2 == NULL || rfbret != 0 || frmret != 0 || picusr_p == NULL ||
	    hnwork_p == NULL || fname_p == NULL || buf700_p == NULL) {
		MWSFSVM_Error("E2053002: not enough work");
		mwsfcre_FreeAll(mwply);
		return NULL;
	}
	if (mwsfcre_IsUseAdxt(mode) == TRUE) {
		if (adxibuf_p == NULL || adxwk_p == NULL) {
			MWSFSVM_Error("E4041301: not enough work");
			mwsfcre_FreeAll(mwply);
			return NULL;
		}
	}
	mwsfd_sisjadr = ((Uint32)cwk2 + 0x3F) & ~0x3F;
	/* h declared before w (h r0, w r3) and the chroma sizes stored first: the mpvpara address temp
	 * is then created after the adxtpara address and the zero (r6, r4, r5) */
	{
		Sint32 h;
		Sint32 w;
		w = cprm->max_width;
		h = cprm->max_height;
		mwsfd_mpvpara.cwidth = (w / 2 + 31) / 32 * 32;
		mwsfd_mpvpara.cheight = h / 2;
		mwsfd_mpvpara.width = w;
		mwsfd_mpvpara.height = h;
		mwsfd_mpvpara.x10 = 0;
		mwsfd_mpvpara.max_width = w;
		mwsfd_mpvpara.max_height = h;
		mwsfd_mpvpara.nfrm = nfrm;
		mwsfd_mpvpara.x20 = 0;
	}
	mwsfd_adxtpara.buf = adxibuf_p;
	mwsfd_adxtpara.work = adxwk_p;
	switch (mode) {
	case MWSFD_FTYPE_SFD:
		crepara = mwsfd_sfdmps_crepara;
		mwply->x1d8 = mwsfd_sisjadr;
		mwply->flow_nsct = sjb - mwsfd_packsize;
		mwply->x1e0 = mwsfd_packsize;
		break;
	case MWSFD_FTYPE_MPV:
		crepara = mwsfd_sfdmpv_crepara;
		mwply->x1d8 = mwsfd_sisjadr;
		mwply->flow_nsct = sjb - 0x800;
		mwply->x1e0 = 0x800;
		break;
	case MWSFD_FTYPE_VONLYSFD:
		crepara = mwsfd_vonlysfd_crepara;
		mwply->x1d8 = mwsfd_sisjadr;
		mwply->flow_nsct = sjb - mwsfd_packsize;
		mwply->x1e0 = mwsfd_packsize;
		break;
	default:
		break;
	}
	crepara.unit = mwsfd_packsize;
	if (sib != 0) {
		sib = sib - sib % mwsfd_packsize;
	}
	fmt = mwsfcre_CnvBufFmt(cprm->buffmt);
	crepara.adr = (Uint32)cwk1;
	crepara.size[0] = sib;
	crepara.size[1] = vib;
	crepara.size[2] = aib;
	crepara.x2c = nfrm;
	crepara.x30 = width;
	crepara.x34 = height;
	crepara.x38 = fmt;
	crepara.hnwork = hnwork_p;
	crepara.hnwksiz = MWSFD_HNWORK_SIZE;
	SFD_SetMpvParaTbl(&mwsfd_mpvpara, &rfbbuf, frmtbl);
	switch (mode) {
	case MWSFD_FTYPE_SFD:
		SFD_SetAdxtPara(&mwsfd_adxtpara);
		break;
	case MWSFD_FTYPE_MPV:
	case MWSFD_FTYPE_VONLYSFD:
		break;
	}
	sfd = SFD_Create((SFD_CREPRM *)&crepara, 0);
	if (sfd == NULL) {
		MWSFLIB_SetErrCode(-0x131);
		MWSFSVM_Error("E20010703C mwPlyCreateSofdec: create error");
		return NULL;
	}
	if (SFD_SetErrFn(sfd, MWSFLIB_SfdErrFunc, mwply) != 0) {
		MWSFLIB_SetErrCode(-0x12F);
		MWSFSVM_Error("E20010703D mwPlyCreateSofdec: set errcb");
		return NULL;
	}
	mwply->fname = fname_p;
	mwply->x1bc = MWSFD_FNAME_SIZE;
	mwply->picusr_buf = picusr_p;
	mwply->picusr_bsize = MWSFD_PICUSR_UNIT;
	mwply->picusr_dat = NULL;
	mwply->picusr_len = 0;
	{
		MWSFD_PICUSR *pu = &mwply->picusr;
		pu->buf = (Uint8 *)picusr_p + MWSFD_PICUSR_UNIT;
		pu->bsize = MWSFD_PICUSR_SIZE - MWSFD_PICUSR_UNIT;
		pu->usize = MWSFD_PICUSR_UNIT;
		mwply->picusr_ptr = pu;
	}
	return sfd;
}

/* the two reference frame buffers: user frame buffers 0 and 1 or two component allocations */
Sint32 mwsfcre_MallocRfb(MWPLY mwply, MWSFD_CRPRM *cprm, MWSFD_RFB *rfb)
{
	Sint32 ret = 0;
	Sint32 fsize;

	fsize = mwsfcre_CalcYccSize(cprm->max_width, cprm->max_height);
	if (mwsfdcre_bufnum != 0) {
		/* the size test is written twice (a macro in the original): `blt fail; bge ok` off one compare */
		if (mwsfdcre_bufnum < 2 || mwsfdcre_bufsize < fsize || mwsfdcre_bufsize < fsize) {
			rfb->buf[0] = NULL;
			rfb->buf[1] = NULL;
			ret = -1;
		} else {
			rfb->buf[0] = mwsfdcre_bufptr[0];
			rfb->buf[1] = mwsfdcre_bufptr[1];
		}
	} else {
		rfb->buf[0] = MWSFD_Malloc(mwply, fsize);
		rfb->buf[1] = MWSFD_Malloc(mwply, fsize);
	}
	if (rfb->buf[0] == NULL || rfb->buf[1] == NULL) {
		ret = -1;
	}
	return ret;
}

/* tell the decoder where the input stream joint of the current play gets its data from */
void MWSFCRE_SetSupplySj(MWPLY mwply)
{
	SFBUF_SUP sup;
	SJ sj = mwply->sji;
	void *sfd = mwply->sfd;

	if (sj == NULL) {
		return;
	}
	if (sj == mwply->mem_sj) {
		sup.kind = 1;
		sup.sj = sj;
		sup.ofst = (Uint32)mwply->mem_buf;
		sup.size = mwply->mem_size;
		sup.xsize = 0;
		sup.x14 = 0;
	} else if (sj == mwply->file_sj) {
		sup.kind = 0;
		sup.sj = sj;
		sup.ofst = mwply->x1d8;
		sup.size = mwply->flow_nsct;
		sup.xsize = mwply->x1e0;
		sup.x14 = 0;
	} else {
		sup.kind = mwply->x1e4;
		sup.sj = sj;
		sup.ofst = mwply->x1e8;
		sup.size = mwply->x1ec;
		sup.xsize = mwply->x1f0;
		sup.x14 = 0;
	}
	if (SFD_SetSupplySj(sfd, &sup) != 0) {
		MWSFLIB_SetErrCode(-0x138);
		MWSFSVM_Error("E20010703B MWSFCRE_SetSupplySj: ");
	}
}

// Work of the SFX converter handle plus the 128 KiB additional-info ring when the layout uses it.
// FUN_005082B8
static Sint32 mwsfcre_CalcWorkSfx(MWSFD_CRPRM *cprm)
{
	Sint32 size = MWSFSFX_CalcHnWorkSiz(cprm->max_width, cprm->max_height);

	if (MWSFTAG_IsUseAinfSj(cprm) == TRUE) {
		size += MWSFD_AINFSJ_BSIZE;
	}
	return size;
}

// Total work the creation parameters need (SFD component buffers + SFX converter); the game
// allocates exactly this much and passes it back as cprm->work.
// FUN_00508310
Sint32 mwPlyCalcWorkCprmSfd(MWSFD_CRPRM *cprm)
{
	Sint32 sfdsiz;
	Sint32 sfxsiz;

	if (cprm == NULL) {
		MWSFSVM_Error("E1122613 mwPlyCalcWorkCprmSfd: cprm is NULL.");
		return 0;
	}
	sfdsiz = mwPlyCalcWorkSfd(cprm);
	sfxsiz = mwsfcre_CalcWorkSfx(cprm);
	return sfdsiz + sfxsiz;
}

/* component work needed by mwsfcre_CreateSfd */

Sint32 mwPlyCalcWorkSfd(MWSFD_CRPRM *cprm)
{
	Sint32 nfrm2;
	Sint32 sjbsiz;
	Sint32 sibsiz;
	Sint32 vibsiz;
	Sint32 aibsiz;
	Sint32 adxibsiz;
	Sint32 adxwksiz;
	register Sint32 size; /* declared above rfbsiz/tabsiz: coloured first (r3), they take r4/r5 */
	Sint32 rfbsiz;
	Sint32 tabsiz;
	Sint32 fsize;
	Sint32 size2;

	CWS_BUFSIZ(cprm, sibsiz, vibsiz, aibsiz, sjbsiz, adxibsiz, adxwksiz);
	if (mwsfdcre_bufnum != 0) {
		rfbsiz = 0;
		tabsiz = 0;
	} else {
		nfrm2 = cprm->max_skip;
		MWSFCRE_CALC_FRMSIZ(cprm, fsize);
		rfbsiz = fsize * 2;
		tabsiz = nfrm2 * fsize;
	}
	/* two alternating accumulators (target r3 / r0): `b = a + c` is a new node, `b += x` stays in place;
	 * a single `size` collapses the chain into one node with the constants reassociated. The total is
	 * `return sibsiz + size` computed straight into r3 (sib first, no @ret copy for the RA to delete, so
	 * the epilogue `lwz r0` is not hoisted); the frontend pulls a single-read `size` web into that
	 * expression and reassociates it, so the web needs a second read that leaves no code: the identity
	 * asm copy below (deleted by backend copy propagation before scheduling). CRI pass 65. */
	size = vibsiz + aibsiz;
	size2 = size + 0x20;
	size = size2 + sjbsiz;
	size2 = size + 0x40 + MWSFD_PICUSR_SIZE;
	size2 += rfbsiz;
	size2 += tabsiz;
	size2 += adxibsiz;
	size = size2 + adxwksiz;
	size += MWSFD_HNWORK_SIZE;
	size += 0x700;
	size += MWSFD_FNAME_SIZE;
	 // COMPILER-DIFF: codeless second read of `size` (every C second read is folded or is code)
	return sibsiz + size;
}
