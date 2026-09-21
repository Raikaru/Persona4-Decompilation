/* CRI Sofdec SFX Y8 + C44 output entry (sfx_cnv_to_Y84C44.c): SFX_CnvFrmY84C44 dispatches on the
 * frame buffer format (only 3, planar YCC 4:2:0) to the GameCube texture converter. */
#include "cri_xpt.h"

typedef struct {
	Sint32 pad0;
	Sint32 compo;
} SFX_OBJ;

typedef struct {
	Sint32 frmfmt;
} SFX_FRM;

extern Sint32 SFXINF_GetStmInf(SFX_FRM *frm, const Char8 *tag);
extern void SFX_CnvFrmYcc420plnToY84C44(SFX_OBJ *sfx, SFX_FRM *frm, void *ybuf, void *cbuf);
extern void SFXLIB_Error(SFX_OBJ *sfx, SFX_FRM *frm, const Char8 *msg);

// Converts a decoded frame to the Y (I8) and CbCr (IA8) textures (mwPlyFxCnvFrmY84C44): reads the
// component layout on first use, then SFX_CnvFrmYcc420plnToY84C44 for planar frames.
void SFX_CnvFrmY84C44(SFX_OBJ *sfx, SFX_FRM *frm, void *ybuf, void *cbuf)
{
	Sint32 frmfmt = frm->frmfmt;

	if (sfx->compo == 0) {
		sfx->compo = SFXINF_GetStmInf(frm, "COMPO");
	}
	switch (frmfmt) {
	case 3:
		SFX_CnvFrmYcc420plnToY84C44(sfx, frm, ybuf, cbuf);
		break;
	case 2:
	default:
		SFXLIB_Error(sfx, frm, "E201193: SFX_CnvFrmY84C44 : frmfmt is not support.");
		break;
	}
}
