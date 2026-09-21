/* Sofdec SFX: YCC 4:2:0 planar frame -> Y8 / C4:4 (GameCube texture) conversion front end */
#include "cri_xpt.h"
#include "sfx.h"

/* Inlined; the returned value is allocated before the caller's `width` (r31), which a direct
 * in-line computation of height is not. */
static Sint32 sfxcnv_GetOutHeight(SFX_OBJ *sfx, SFX_FRM *frm)
{
	Sint32 height;

	height = sfx->outbuf_height;
	if (height == 0) {
		height = frm->pln[0].height;
	}
	if (sfxcnv_IsCnvUpHalf(sfx) == 1) {
		height /= 2;
	}
	return height;
}

// Planar YCC 4:2:0 (layouts 0x11 / 0x101) -> Y8 and CbCr 4:4 GameCube textures of the output size
// (frame size when unset, half height for upper-half layouts) through CFT_Ycc420plnToY84C44.
void SFX_CnvFrmYcc420plnToY84C44(SFX_OBJ *sfx, SFX_FRM *frm, void *ybuf, void *cbuf)
{
	CFT_YCC420PLN src;
	Sint32 width;
	Sint32 height;

	switch (sfx->compo) {
	case SFX_COMPO_YCC420PLN:
	case SFX_COMPO_0x101:
		src.y = frm->pln[0].buf;
		src.cb = frm->pln[1].buf;
		src.cr = frm->pln[2].buf;
		src.ywidth = frm->pln[0].width;
		src.cbwidth = frm->pln[1].width;
		src.crwidth = frm->pln[2].width;
		width = (sfx->outbuf_width == 0) ? frm->pln[0].width : sfx->outbuf_width;
		height = sfxcnv_GetOutHeight(sfx, frm);
		CFT_Ycc420plnToY84C44(&src, ybuf, cbuf, width, height);
		break;
	case SFX_COMPO_YCC420PLN_UPHALF:
	case SFX_COMPO_0x31:
	case SFX_COMPO_0x41:
	case SFX_COMPO_0x51:
	case SFX_COMPO_0x61:
	case SFX_COMPO_0x71:
	case SFX_COMPO_0xF1:
	case SFX_COMPO_0x111:
	case SFX_COMPO_0x1001:
	default:
		SFXLIB_Error(sfx, frm, "E201192: CnvToY84C44 : compo is not support.");
		break;
	}
}
