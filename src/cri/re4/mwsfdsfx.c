/* MW Sofdec player: SFX (frame conversion) front end and the additional-info (tag) stream. The
 * mwPly* Z-buffer / colour conversion entry points were dead-stripped by the linker; their bodies
 * only reproduce the error strings left in .rodata (STRIP_UNUSED). */
#include "mwsfd.h"
#include "sfd.h"
#include <string.h>

#define MWSFD_FXTYPE_NONE 0
#define MWSFD_FXTYPE_ZAUTO 0x101

/* MWS_FRM.fmt */
#define MWSFD_BUFFMT_1 1
#define MWSFD_BUFFMT_2 2
#define MWSFD_BUFFMT_YCC420PLN 3

Sint32 mwPlyGetFxType(MWPLY mwply);
void mwPlyCalcYccPlane(void *buf, Sint32 width, Sint32 height, CFT_YCC420PLN *pln);
void mwSfdDestroy(MWPLY mwply);
Sint32 SFD_SetUsrSj(SFD sfd, Sint32 chno, void *sj, void *prm);
void SFX_SetCompoMode(SFX_OBJ *sfx, Sint32 mode);
Sint32 SFX_GetTypeDivField(SFX_OBJ *sfx);
Sint32 SFX_GetTypeCcs(SFX_OBJ *sfx);
void SFX_SetPicUsrDat(SFX_OBJ *sfx, void *dat, Sint32 size);
void SFX_SetTagInf(SFX_OBJ *sfx, void *tag, Sint32 size);
void SFX_GetTagInf(SFX_OBJ *sfx, Sint32 *a, Sint32 *b);
void SFX_SetOutBufSize(SFX_OBJ *sfx, Sint32 width, Sint32 height);
void SFX_SetUnitWidth(SFX_OBJ *sfx, Sint32 width);
void SFX_SetColAdj(SFX_OBJ *sfx, void *coladj);
void SFX_SetFxType(SFX_OBJ *sfx, Sint32 fxtype);
void SFX_Destroy(SFX_OBJ *sfx);
SFX_OBJ *SFX_Create(void *work, Sint32 wsize);
void SFX_Init(void);
void SFX_SetErrFn(void (*fn)(void *obj, const Char8 *msg), void *obj);
Sint32 SFX_GetOutZoffset(SFX_OBJ *sfx);
void SFX_SetOutZoffset(SFX_OBJ *sfx, Sint32 ofst);
Sint32 SFX_GetOutZscale(SFX_OBJ *sfx);
void SFX_SetOutZscale(SFX_OBJ *sfx, Sint32 scale);
Sint32 SFX_GetCompoMode(SFX_OBJ *sfx);
Sint32 SFX_GetCnvBottomUp(SFX_OBJ *sfx);
void SFX_SetCnvBottomUp(SFX_OBJ *sfx, Sint32 sw);
void SFX_MakeTblZ32(SFX_OBJ *sfx, SFX_FRM *frm, void *tbl);
void SFX_MakeTblZ16(SFX_OBJ *sfx, SFX_FRM *frm, void *tbl);
void SFX_CnvFrmZ32(SFX_OBJ *sfx, SFX_FRM *frm, void *dst);
void SFX_CnvFrmZ16(SFX_OBJ *sfx, SFX_FRM *frm, void *dst);
Sint32 mwPlyGetCurFrm(MWPLY mwply, MWS_FRM *frm);

/* the creation parameters asked for the additional-info stream */
static Bool mwsftag_IsUseAinfSj(MWSFD_CRPRM *prm)
{
	if (prm->compo == MWSFD_FXTYPE_NONE || prm->compo == MWSFD_FXTYPE_ZAUTO) {
		return TRUE;
	}
	return FALSE;
}

// MPEG-only files (mode 2) have no additional-info stream.
static Bool mwsftag_IsNoAinf(MWPLY mwply)
{
	return mwply->prm.mode == 2;
}

// At play start: unless fixed by the creation parameters, takes the component layout from the Sofdec
// header of the current frame and programs the SFX converter with it.
void MWSFSFX_DecideCompoMode(MWPLY mwply)
{
	Sint32 fxtype;

	if (mwply->compo_fix == 0) {
		fxtype = mwPlyGetFxType(mwply);
		if (fxtype != -1) {
			mwply->compo = fxtype;
		} else {
			mwply->compo = SFX_COMPO_YCC420PLN;
		}
	}
	SFX_SetCompoMode(mwply->sfx, mwply->compo);
}

// Whether the converter treats the frame as two fields.
Sint32 MWSFD_IsFrmDivField(MWPLY mwply)
{
	return SFX_GetTypeDivField(mwply->sfx);
}

// Whether the converter's current layout asks for colour-space conversion.
Sint32 MWSFSFX_IsFrmCcs(MWPLY mwply)
{
	return SFX_GetTypeCcs(mwply->sfx);
}

// Hands the frame's picture user data to the converter (it may carry conversion parameters).
void MWSFSFX_SetPicUsrDat(MWPLY mwply, void *dat, Sint32 size)
{
	SFX_SetPicUsrDat(mwply->sfx, dat, size);
}

// Dead: bottom-up conversion switch.
Sint32 mwPlyGetCnvBottomUp(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E404011: mwPlyGetCnvBottomUp: handle is invalid.");
		return 0;
	}
	return SFX_GetCnvBottomUp(mwply->sfx);
}

// Dead: bottom-up conversion switch.
void mwPlySetCnvBottomUp(MWPLY mwply, Sint32 sw)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E404010: mwPlySetCnvBottomUp: handle is invalid.");
		return;
	}
	SFX_SetCnvBottomUp(mwply->sfx, sw);
}

// Dead: Z-buffer table (32-bit) from the current frame.
void MWSFD_MakeTblZ32(MWPLY mwply, void *tbl)
{
	MWS_FRM frm;
	SFX_FRM sfxfrm;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E202285: MWSFD_MakeTblZ32: handle is invalid.");
		return;
	}
	if (mwPlyGetCurFrm(mwply, &frm) == 0) {
		MWSFSVM_Error("E202286: MWSFD_MakeTblZ32: getfrm is failed.");
		return;
	}
	MWSFSFX_CnvFrmInfToSfx(mwply, &frm, &sfxfrm);
	SFX_MakeTblZ32(mwply->sfx, &sfxfrm, tbl);
}

// Dead: Z-buffer table (16-bit) from the current frame.
void MWSFD_MakeTblZ16(MWPLY mwply, void *tbl)
{
	MWS_FRM frm;
	SFX_FRM sfxfrm;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E202283: MWSFD_MakeTblZ16: handle is invalid.");
		return;
	}
	if (mwPlyGetCurFrm(mwply, &frm) == 0) {
		MWSFSVM_Error("E202284: MWSFD_MakeTblZ16: getfrm is failed.");
		return;
	}
	MWSFSFX_CnvFrmInfToSfx(mwply, &frm, &sfxfrm);
	SFX_MakeTblZ16(mwply->sfx, &sfxfrm, tbl);
}

/* COMPILER-DIFF: M3 (.rodata order) - the original parsed mwsftag_GetAinfFromSj's "CRITAGS"/"CRITAGE"
 * after MWSFTAG_UpdateTagInf's "SFXINFS"/"SFXINFE" and mwPlyAttachAddInfBuf's message (literal
 * numbers @773/@774 > @742/@743/@746) while its .text precedes UpdateTagInf (the callee was emitted
 * before its first caller). A named string is emitted at its declaration, so the three later
 * strings are declared here, ahead of mwsftag_GetAinfFromSj's literals. */
static const Char8 mwsftag_sfxinfs[] = "SFXINFS"; // COMPILER-DIFF: M3
static const Char8 mwsftag_sfxinfe[] = "SFXINFE";
static const Char8 mwsftag_msg_bufsize[] = "W2121001 : mwPlyAttachAddInfBuf(): bufsize is short.";

/* pick the tag block out of the additional-info stream */
static void mwsftag_GetAinfFromSj(MWPLY mwply)
{
	SJCK ck;
	SJCK out;
	SJCK rd;
	SJ sj;
	Sint32 ndata;

	sj = mwply->ainf_sj;
	ndata = SJ_GetNumData(sj, SJ_CK_DATA);
	if (ndata == 0) {
		mwply->tag_ptr = NULL;
		mwply->tag_size = 0;
		mwply->tag_flg = 1;
		return;
	}
	ck.data = mwply->ainf_buf;
	ck.len = ndata;
	if (SJ_SearchTag(&ck, "CRITAGS", "CRITAGE", &out) == NULL) {
		mwply->tag_ptr = NULL;
		mwply->tag_size = 0;
		mwply->tag_flg = 1;
		return;
	}
	if (mwply->addinf_buf != NULL) {
		memcpy(mwply->addinf_buf, out.data, out.len);
		mwply->tag_ptr = mwply->addinf_buf;
		mwply->tag_size = out.len;
		mwply->tag_flg = 1;
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &rd);
		SJ_PutChunk(sj, SJ_CK_FREE, &rd);
		SJ_Reset(sj);
	} else {
		mwply->tag_ptr = out.data;
		mwply->tag_size = out.len;
		mwply->tag_flg = 1;
		if (mwsftag_IsNoAinf(mwply) != TRUE) {
			if (mwply->ainf_sj != NULL) {
				SFD_SetUsrSj(mwply->sfd, 2, NULL, NULL);
			}
		}
	}
}

/* the original did not inline mwsftag_GetAinfFromSj here */
// When a new frame arrives: pulls the additional-info (tag) block from its stream joint and hands the
// "SFXINFS".."SFXINFE" record, if present, to the converter as its tag info.
void MWSFTAG_UpdateTagInf(MWPLY mwply)
{
	SJCK out;
	SJCK ck;
	SFX_OBJ *sfx;

	if (mwply->ainf_sj == NULL) {
		return;
	}
	mwsftag_GetAinfFromSj(mwply);
	sfx = mwply->sfx;
	if (mwply->tag_ptr == NULL) {
		SFX_SetTagInf(sfx, NULL, 0);
		return;
	}
	ck.data = mwply->tag_ptr;
	ck.len = mwply->tag_size;
	if (SJ_SearchTag(&ck, mwsftag_sfxinfs, mwsftag_sfxinfe, &out) == NULL) {
		SFX_SetTagInf(sfx, NULL, 0);
		return;
	}
	SFX_SetTagInf(sfx, out.data, out.len);
}

// Dead: user buffer that receives a copy of the tag block.
Sint32 mwPlyAttachAddInfBuf(MWPLY mwply, void *buf, Sint32 bsize)
{
	if (bsize < mwply->ainf_bsize) {
		MWSFSVM_Error(mwsftag_msg_bufsize);
		return 0;
	}
	mwply->addinf_buf = buf;
	return 1;
}

// Empties the additional-info ring (new play).
void MWSFTAG_ResetAinfSj(MWPLY mwply)
{
	if (mwply->ainf_sj != NULL) {
		SJ_Reset(mwply->ainf_sj);
	}
}

// No tag block seen yet.
void MWSFTAG_InitTagInf(MWPLY mwply)
{
	mwply->tag_flg = 0;
	mwply->tag_ptr = NULL;
	mwply->tag_size = 0;
	mwply->tag_x1a4 = -1;
}

// Registers the additional-info ring as SFD user-output channel 2 (private stream 2 data); -1 on failure.
Sint32 MWSFTAG_SetAinfSj(MWPLY mwply)
{
	if (mwsftag_IsNoAinf(mwply) == TRUE) {
		return 0;
	}
	if (mwply->ainf_sj == NULL) {
		return 0;
	}
	return (SFD_SetUsrSj(mwply->sfd, 2, mwply->ainf_sj, NULL) != 0) ? -1 : 0;
}

// Destroys the additional-info stream joint.
void MWSFTAG_DestroyAinfSj(MWPLY mwply)
{
	if (mwply->ainf_sj != NULL) {
		SJ_Destroy(mwply->ainf_sj);
	}
}

// Creates the additional-info ring joint over the 128 KiB block when the layout uses it (compo 0 or
// 0x101), else NULL.
SJ MWSFTAG_CreateAinfSj(MWPLY mwply)
{
	SJ sj;

	if (!mwsftag_IsUseAinfSj(&mwply->prm)) {
		return NULL;
	}
	sj = SJRBF_Create(mwply->ainf_buf, mwply->ainf_bsize, 0);
	if (sj == NULL) {
		MWSFSVM_Error("E201211 mwPlyCreate: can't create AddInfSJ");
		mwSfdDestroy(mwply);
		return NULL;
	}
	return sj;
}

// Whether the creation parameters use the additional-info stream (compo 0 or 0x101).
Bool MWSFTAG_IsUseAinfSj(MWSFD_CRPRM *prm)
{
	return mwsftag_IsUseAinfSj(prm);
}

// Dead: Z output offset.
Sint32 mwPlyFxGetOutZoffset(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011921: mwPlyFxGetOutZoffset: handle is invalid.");
		return 0;
	}
	return SFX_GetOutZoffset(mwply->sfx);
}

// Dead: Z output offset.
void mwPlyFxSetOutZoffset(MWPLY mwply, Sint32 ofst)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011920: mwPlyFxSetOutZoffset: handle is invalid.");
		return;
	}
	SFX_SetOutZoffset(mwply->sfx, ofst);
}

// Dead: Z output scale.
Sint32 mwPlyFxGetOutZscale(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011919: mwPlyFxGetOutZscale: handle is invalid.");
		return 0;
	}
	return SFX_GetOutZscale(mwply->sfx);
}

// Dead: Z output scale.
void mwPlyFxSetOutZscale(MWPLY mwply, Sint32 scale)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011918: mwPlyFxSetOutZscale: handle is invalid.");
		return;
	}
	SFX_SetOutZscale(mwply->sfx, scale);
}

// Output texture size in pixels for the frame converters (the game sets it before
// mwPlyFxCnvFrmY84C44 with the texture width/height).
void mwPlyFxSetOutBufSize(MWPLY mwply, Sint32 width, Sint32 height)
{
	SFX_OBJ *sfx;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E306091: MWSFSFX_SetOutBufSize: handle is invalid.");
		return;
	}
	sfx = mwply->sfx;
	SFX_SetOutBufSize(sfx, width, height);
	SFX_SetUnitWidth(sfx, 1);
}

// Output size as a byte pitch and height (the game uses it for the ARGB8888 path: width * 4).
void mwPlyFxSetOutBufPitchHeight(MWPLY mwply, Sint32 pitch, Sint32 height)
{
	SFX_OBJ *sfx;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E306091: MWSFSFX_SetOutBufSize: handle is invalid.");
		return;
	}
	sfx = mwply->sfx;
	SFX_SetOutBufSize(sfx, pitch, height);
	SFX_SetUnitWidth(sfx, 0);
}

// Dead: current output pitch/height.
void mwPlyFxGetOutBufPitchHeight(MWPLY mwply, Sint32 *pitch, Sint32 *height)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E307092: mwPlyFxGetOutBufPitchHeight: handle is invalid.");
		return;
	}
	*pitch = mwply->sfx->outbuf_width;
	*height = mwply->sfx->outbuf_height;
}

// Colour adjustment table for the converter (from the Sofdec header / picture user data).
void MWSFD_SetColAdj(MWPLY mwply, void *coladj)
{
	SFX_SetColAdj(mwply->sfx, coladj);
}

// Same as MWSFD_SetColAdj.
void MWSFSFX_SetColAdj(MWPLY mwply, void *coladj)
{
	SFX_SetColAdj(mwply->sfx, coladj);
}

// Converter effect type.
void MWSFSFX_SetFxType(MWPLY mwply, Sint32 fxtype)
{
	SFX_SetFxType(mwply->sfx, fxtype);
}

// Converter component layout.
void MWSFSFX_SetCompoMode(MWPLY mwply, Sint32 mode)
{
	SFX_SetCompoMode(mwply->sfx, mode);
}

// Dead: current component layout.
Sint32 mwPlyFxGetCompoMode(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011915: mwPlyFxGetCompoMode: handle is invalid.");
		return 0;
	}
	return SFX_GetCompoMode(mwply->sfx);
}

// Dead: fixes the component layout by hand.
void mwPlyFxSetCompoMode(MWPLY mwply, Sint32 mode)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E201214: mwPlyFxSetCompoMode: handle is invalid.");
		return;
	}
	if (mode == SFX_COMPO_0x101 && mwply->prm.compo != SFX_COMPO_0x101) {
		MWSFSVM_Error("E204011: mwPlyFxSetCompoMode: COMPO_Z needs setting in MWPLY Creation.");
		return;
	}
	if (mode == 0 && mwply->prm.compo != 0) {
		MWSFSVM_Error("E204012: mwPlyFxSetCompoMode: COMPO_AUTO needs setting in MWPLY Creation.");
		return;
	}
	mwply->compo = mode;
	mwply->compo_fix = 1;
	SFX_SetCompoMode(mwply->sfx, mode);
}

// Dead: converts the current frame to a 32-bit Z buffer.
void mwPlyFxCnvFrmZ32(MWPLY mwply, void *dst)
{
	MWS_FRM frm;
	SFX_FRM sfxfrm;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011913: mwPlyFxCnvFrmZ32: handle is invalid.");
		return;
	}
	if (mwPlyGetCurFrm(mwply, &frm) == 0) {
		MWSFSVM_Error("E2011914: mwPlyFxCnvFrmZ32: getfrm is failed.");
		return;
	}
	MWSFSFX_CnvFrmInfToSfx(mwply, &frm, &sfxfrm);
	SFX_CnvFrmZ32(mwply->sfx, &sfxfrm, dst);
}

// Dead: converts the current frame to a 16-bit Z buffer.
void mwPlyFxCnvFrmZ16(MWPLY mwply, void *dst)
{
	MWS_FRM frm;
	SFX_FRM sfxfrm;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2011911: mwPlyFxCnvFrmZ16: handle is invalid.");
		return;
	}
	if (mwPlyGetCurFrm(mwply, &frm) == 0) {
		MWSFSVM_Error("E2011912: mwPlyFxCnvFrmZ16: getfrm is failed.");
		return;
	}
	MWSFSFX_CnvFrmInfToSfx(mwply, &frm, &sfxfrm);
	SFX_CnvFrmZ16(mwply->sfx, &sfxfrm, dst);
}

/* translate a player frame into the SFX frame description. The empty `case N: break;` arms are
 * written `case N: v = N; break;` (v already N): MWCC drops the redundant assignment after block
 * layout and keeps the arm's dead `b end`, which the original has in all four switches; the first
 * switch's variable must be `v` too (the elimination needs a prior definition of the variable).
 * The four messages are named statics declared in reverse use order: the original's pool holds
 * them reversed (OPEN why; anonymous literals are emitted in use order). Register ranking: the
 * original colours the parameters mwply/sfxfrm r30/r31 above the pool base r29, i.e. the pool
 * base (a backend temp, the highest vid) is removed in the FIRST Chaitin scan: at its turn it
 * counts 12 physical registers, the width r4 ghost, mwply, sfxfrm and every backend temp of the
 * function (single-use loads substituted into their stores) and needs < 29. Five of those loads
 * are therefore written as own locals with a cast `+ 0` second definition (the frontend keeps a
 * two-def local as a web instead of substituting it, the backend folds `addi x, x, 0` to nothing):
 * cb/cbw of plane 1 (also the original's load order there: buf r0 before width r3, both own locals
 * in declaration order, while planes 0/2 load the inlined helper's kept width parameter first) and
 * the three mwply->x94/x98/x9c copies. The .rodata order of the tag strings is fixed at
 * mwsftag_GetAinfFromSj (COMPILER-DIFF: M3). */
static const Char8 mwsfsfx_msg_chromapos[] = "E301274 : chromapos is invalid.";
static const Char8 mwsfsfx_msg_chroma_format[] = "E301273 : chroma_format is invalid.";
static const Char8 mwsfsfx_msg_pic_struct[] = "E301272 : picture_structure is invalid.";
static const Char8 mwsfsfx_msg_buffmt[] = "E201184 : MwsfdBufFmt value is invalid.";

// Fills one SFX plane descriptor (buffer, width, height).
static void mwsfsfx_SetPln(SFX_PLN *p, void *buf, Sint32 width, Sint32 height)
{
	p->buf = buf;
	p->width = width;
	p->height = height;
}

/* mwPlyCalcYccPlane output: the six live words of CFT_YCC420PLN (the sfx.h type carries a
 * 0x10-byte frame-only tail; the original's stack frame is 0x40, so its local was this size) */
typedef struct {
	void *y;
	void *cb;
	void *cr;
	Sint32 ywidth;
	Sint32 cbwidth;
	Sint32 crwidth;
} MWSFSFX_YCC420PLN;

// Converts a player frame (MWS_FRM) into the converter's SFX_FRM: the three YCC planes with their
// strides (mwPlyCalcYccPlane), size, picture structure, chroma format/positions, field flags and the
// tag info; errors for unknown buffmt / pic_struct / chroma values.
void MWSFSFX_CnvFrmInfToSfx(MWPLY mwply, MWS_FRM *frm, SFX_FRM *sfxfrm)
{
	MWSFSFX_YCC420PLN pln;
	Sint32 tag_b;
	Sint32 tag_a;
	Sint32 width;
	Sint32 height;
	Sint32 v;
	void *cb;
	Sint32 cbw;
	Sint32 x94;
	Sint32 x98;
	Sint32 x9c;

	switch (frm->fmt) {
	case MWSFD_BUFFMT_1:
		v = 1;
		break;
	case MWSFD_BUFFMT_2:
		v = 2;
		break;
	case MWSFD_BUFFMT_YCC420PLN:
		v = 3;
		break;
	default:
		MWSFSVM_Error(mwsfsfx_msg_buffmt);
		v = 3;
		break;
	}
	sfxfrm->frmfmt = v;
	width = frm->width;
	height = frm->height;
	sfxfrm->width = width;
	sfxfrm->height = height;
	if (frm->fmt != MWSFD_BUFFMT_YCC420PLN) {
		mwsfsfx_SetPln(&sfxfrm->pln[0], frm->bufadr, width, height);
	} else {
		mwPlyCalcYccPlane(frm->bufadr, width, height, (CFT_YCC420PLN *)&pln);
		mwsfsfx_SetPln(&sfxfrm->pln[0], pln.y, pln.ywidth, height);
		cb = pln.cb;
		cbw = pln.cbwidth;
		cb = (void *)((Uint32)cb + 0);
		cbw = (Sint32)((Uint32)cbw + 0);
		mwsfsfx_SetPln(&sfxfrm->pln[1], cb, cbw, height);
		mwsfsfx_SetPln(&sfxfrm->pln[2], pln.cr, pln.crwidth, height);
	}
	sfxfrm->tblsrc = frm->tblsrc;
	SFX_GetTagInf(mwply->sfx, &tag_a, &tag_b);
	sfxfrm->tag_a = tag_a;
	sfxfrm->tag_b = tag_b;
	sfxfrm->x58 = 0;
	sfxfrm->x5c = 0;
	v = 3;
	switch (mwply->pic_struct) {
	case 1:
		v = 1;
		break;
	case 2:
		v = 2;
		break;
	case 3:
		v = 3;
		break;
	default:
		MWSFSVM_Error(mwsfsfx_msg_pic_struct);
		break;
	}
	sfxfrm->pic_struct = v;
	v = 1;
	switch (mwply->chroma_format) {
	case 1:
		v = 1;
		break;
	case 2:
		v = 2;
		break;
	case 3:
		v = 3;
		break;
	default:
		MWSFSVM_Error(mwsfsfx_msg_chroma_format);
		break;
	}
	sfxfrm->chroma_format = v;
	v = 1;
	x94 = mwply->x94;
	x94 = (Sint32)((Uint32)x94 + 0);
	sfxfrm->x68 = x94;
	x98 = mwply->x98;
	x98 = (Sint32)((Uint32)x98 + 0);
	sfxfrm->x6c = x98;
	x9c = mwply->x9c;
	x9c = (Sint32)((Uint32)x9c + 0);
	sfxfrm->x70 = x9c;
	switch (mwply->chromapos_h) {
	case 0:
		v = 0;
		break;
	case 1:
		v = 1;
		break;
	default:
		MWSFSVM_Error(mwsfsfx_msg_chromapos);
		break;
	}
	sfxfrm->chromapos_h = v;
	v = 1;
	switch (mwply->chromapos_v) {
	case 0:
		v = 0;
		break;
	case 1:
		v = 1;
		break;
	default:
		MWSFSVM_Error(mwsfsfx_msg_chromapos);
		break;
	}
	sfxfrm->chromapos_v = v;
}

// The player's SFX converter handle.
SFX_OBJ *MWSFSFX_GetSfxHn(MWPLY mwply)
{
	return mwply->sfx;
}

// Destroys the converter.
void MWSFSFX_Destroy(SFX_OBJ *sfx)
{
	SFX_Destroy(sfx);
}

// Creates the converter in the given work.
SFX_OBJ *MWSFSFX_Create(void *work, Sint32 wsize)
{
	return SFX_Create(work, wsize);
}

// Work needed by one converter (SFX_WORK_SIZE).
Sint32 MWSFSFX_CalcHnWorkSiz(void)
{
	return SFX_WORK_SIZE;
}

// SFX errors -> MWSFSVM_Error.
void mwsfsfx_SfxErrCbFn(void *obj, const Char8 *msg)
{
	MWSFSVM_Error(msg);
}

// SFX library init with the error callback.
// FUN_0050E428
void MWSFSFX_Init(void)
{
	SFX_Init();
	SFX_SetErrFn(mwsfsfx_SfxErrCbFn, NULL);
}
