/* CRI Sofdec SFX ARGB8888 output entry (sfx_cnv_to_ARGB8888PLN.c): SFX_CnvFrmARGB8888 dispatches on
 * the frame buffer format (only 3, planar YCC 4:2:0, is supported) to the per-layout converter. */
#include "cri_xpt.h"

typedef struct {
	Sint32 pad0;
	Sint32 compo;
} SFX_OBJ;

typedef struct {
	Sint32 frmfmt;
} SFX_FRM;

extern Sint32 SFXINF_GetStmInf(SFX_FRM *frm, const Char8 *tag);
extern void SFX_CnvFrmYcc420plnToArgb8888(SFX_OBJ *sfx, SFX_FRM *frm, void *buf);
extern void SFXLIB_Error(SFX_OBJ *sfx, SFX_FRM *frm, const Char8 *msg);

// Converts a decoded frame to 32-bit ARGB (mwPlyFxCnvFrmARGB8888): reads the component layout from
// the stream info on first use, then SFX_CnvFrmYcc420plnToArgb8888 for planar frames.
void SFX_CnvFrmARGB8888(SFX_OBJ *sfx, SFX_FRM *frm, void *buf)
{
	Sint32 frmfmt = frm->frmfmt;

	if (sfx->compo == 0) {
		sfx->compo = SFXINF_GetStmInf(frm, "COMPO");
	}
	switch (frmfmt) {
	case 3:
		SFX_CnvFrmYcc420plnToArgb8888(sfx, frm, buf);
		break;
	default:
		SFXLIB_Error(sfx, frm, "E201181: SFX_CnvFrmArgb8888 : frmfmt is not support.");
		break;
	}
}
