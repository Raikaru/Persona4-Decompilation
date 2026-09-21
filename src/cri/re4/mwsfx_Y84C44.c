/* CRI Sofdec MW player frame conversion to Y8 + C44 (mwsfx_Y84C44.c): the GameCube path the game
 * uses. The decoded YCC 4:2:0 frame becomes a luma texture (I8) and an interleaved Cb/Cr texture
 * (IA8) which sofdec.cpp combines back to RGB in the TEV (setTevPrm). */
#include "mwsfd.h"

// Converts the frame from mwPlyGetCurFrm into the Y (ybuf) and CbCr (cbuf) textures of the size set
// by mwPlyFxSetOutBufSize; called every frame by cSofdec::loadMvFrmFx.
void mwPlyFxCnvFrmY84C44(MWPLY_OBJ *mwply, MWS_FRM *frm, void *ybuf, void *cbuf)
{
	SFX_FRM sfxfrm;
	SFX_OBJ *sfx;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E201199: mwPlyFxCnvFrmYUV422: handle is invalid.");
		return;
	}
	if (frm->bufadr == NULL) {
		MWSFSVM_Error("E2011910: mwPlyFxCnvFrmYUV422: getfrm is failed.");
		return;
	}
	sfx = MWSFSFX_GetSfxHn(mwply);
	MWSFSFX_CnvFrmInfToSfx(mwply, frm, &sfxfrm);
	SFX_CnvFrmY84C44(sfx, &sfxfrm, ybuf, cbuf);
}
