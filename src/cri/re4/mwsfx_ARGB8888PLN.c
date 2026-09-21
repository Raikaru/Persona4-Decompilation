/* CRI Sofdec MW player frame conversion to ARGB8888 (mwsfx_ARGB8888PLN.c): the 32-bit RGB texture
 * path of loadMvFrmFx (sofdec.cpp), used when the YUV TEV path is not taken. */
#include "mwsfd.h"

/* dead-stripped by the linker (its two error strings stay in .rodata) */
void MWSFD_CnvFrmClipARGB8888(MWPLY_OBJ *mwply, MWS_FRM *frm, void *buf)
{
	SFX_FRM sfxfrm;
	SFX_OBJ *sfx;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E306165: MWSFD_CnvFrmClipARGB8888: handle is invalid.");
		return;
	}
	if (frm->bufadr == NULL) {
		MWSFSVM_Error("E306166: MWSFD_CnvFrmClipARGB8888: getfrm is failed.");
		return;
	}
	sfx = MWSFSFX_GetSfxHn(mwply);
	MWSFSFX_CnvFrmInfToSfx(mwply, frm, &sfxfrm);
	SFX_CnvFrmARGB8888(sfx, &sfxfrm, buf);
}

// Converts the frame from mwPlyGetCurFrm into a 32-bit ARGB buffer of the size set by
// mwPlyFxSetOutBufPitchHeight (the game's non-YUV texture path in loadMvFrmFx).
void mwPlyFxCnvFrmARGB8888(MWPLY_OBJ *mwply, MWS_FRM *frm, void *buf)
{
	SFX_FRM sfxfrm;
	SFX_OBJ *sfx;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E201195: mwPlyFxCnvFrmARGB8888: handle is invalid.");
		return;
	}
	if (frm->bufadr == NULL) {
		MWSFSVM_Error("E201196: mwPlyFxCnvFrmARGB8888: getfrm is failed.");
		return;
	}
	sfx = MWSFSFX_GetSfxHn(mwply);
	MWSFSFX_CnvFrmInfToSfx(mwply, frm, &sfxfrm);
	SFX_CnvFrmARGB8888(sfx, &sfxfrm, buf);
}
