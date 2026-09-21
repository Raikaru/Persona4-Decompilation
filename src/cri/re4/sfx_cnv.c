/* CRI Sofdec SFX conversion tables and layout helpers (sfx_cnv.c): builds the per-layout lookup
 * table in the converter's buf[0] on demand (luma, alpha ramps, colour adjustment, Z), decides the
 * alpha table type of the three-level layouts, and the upper-half / bottom-up plane helpers the
 * frame converters share. */
#include "cri_xpt.h"
#include "sfx.h"

/* dead-stripped by the linker */
void SFX_MakeTblZ32(SFX_OBJ *sfx, SFX_FRM *frm)
{
	if (sfx->x30 == 0) {
		SFXLIB_Error(sfx, frm, "E202281: SFX_MakeTblZ32 : zclip is not set.");
		return;
	}
	SFXZ_MakeCnvZTbl(sfx->sfxz, frm->tblsrc, sfx->buf[0]);
}

/* dead-stripped by the linker */
void SFX_MakeTblZ16(SFX_OBJ *sfx, SFX_FRM *frm)
{
	if (sfx->x30 == 0) {
		SFXLIB_Error(sfx, frm, "E202282: SFX_MakeTblZ16 : zclip is not set.");
		return;
	}
	SFXZ_MakeCnvZTbl(sfx->sfxz, frm->tblsrc, sfx->buf[0]);
}

/* the luminance table: 0 below 16, 1.164 * (Y - 16) up to 235, saturated above */
static void sfxcnv_MakeLumiTbl(Uint8 *tbl)
{
	Sint32 i;

	for (i = 0; i <= 15; i++) {
		tbl[i] = 0;
	}
	for (i = 16; i <= 235; i++) {
		tbl[i] = (Uint8)(1.164f * (Float32)(i - 16));
	}
	for (i = 236; i <= 255; i++) {
		tbl[i] = 0xFF;
	}
}

// Builds the conversion table of `type` in buf[0] unless the same type is already there (the luma
// alpha table is rebuilt when its settings changed): Z tables, alpha ramps, colour adjustment
// (ARGB / YCC422) or the plain luma table. Error for unknown types.
void SFX_MakeTable(SFX_OBJ *sfx, SFX_FRM *frm, Sint32 type)
{
	Bool need;

	need = TRUE;
	if (sfx->tbl_type == SFX_TBL_NONE) {
		need = FALSE;
	} else if (sfx->tbl_type == type) {
		switch (type) {
		case SFX_TBL_ALP_LUMI:
			if (SFXA_IsNeedUpdateLumiTbl(sfx->sfxa) != TRUE) {
				need = FALSE;
			}
			break;
		case SFX_TBL_LUMI:
		case SFX_TBL_ALP3110:
		case SFX_TBL_ALP3211:
		case SFX_TBL_ARGB8888_COLADJ:
		case SFX_TBL_YCC422_COLADJ:
			need = FALSE;
			break;
		case 0:
		case SFX_TBL_Z32:
		case SFX_TBL_Z32 + 1:
		case SFX_TBL_NONE:
		default:
			break;
		}
	}
	if (need != TRUE) {
		return;
	}
	sfx->tbl_type = type;
	switch (type) {
	case SFX_TBL_Z32:
	case SFX_TBL_Z16:
		SFXZ_MakeCnvZTbl(sfx->sfxz, frm->tblsrc, sfx->buf[0]);
		break;
	case SFX_TBL_ALP_LUMI:
		SFXA_MakeAlpLumiTbl(sfx->sfxa, frm->tblsrc, sfx->buf[0]);
		break;
	case SFX_TBL_ALP3110:
		SFXA_MakeAlp3110Tbl(sfx->sfxa, frm->tblsrc, sfx->buf[0]);
		break;
	case SFX_TBL_ALP3211:
		SFXA_MakeAlp3211Tbl(sfx->sfxa, frm->tblsrc, sfx->buf[0]);
		break;
	case SFX_TBL_ARGB8888_COLADJ:
		CFT_MakeArgb8888ColAdjTbl(sfx->buf[0]);
		break;
	case SFX_TBL_YCC422_COLADJ:
		CFT_MakeYcc422ColAdjTbl(sfx->buf[0]);
		break;
	case SFX_TBL_LUMI:
		sfxcnv_MakeLumiTbl(sfx->buf[0]);
		break;
	case 0:
	case SFX_TBL_NONE:
	default:
		SFXLIB_Error(sfx, frm, "E201311: sfxcnv_MakeTable : compo is not support.");
		break;
	}
}

// Alpha table type for the three-level layouts: 0x51 -> 3110, 0x61 -> 3211, 0x41 by the output
// fxtype (default 3211).
Sint32 SFX_DecideTableAlph3(SFX_OBJ *sfx, Sint32 compo)
{
	Sint32 fxtype;
	Sint32 ret;

	if (compo == SFX_COMPO_0x51) {
		return SFX_TBL_ALP3110;
	}
	if (compo == SFX_COMPO_0x61) {
		return SFX_TBL_ALP3211;
	}
	fxtype = SFX_GetFxType(sfx);
	if (fxtype == SFX_COMPO_0x51) {
		ret = SFX_TBL_ALP3110;
	} else if (fxtype == SFX_COMPO_0x61) {
		ret = SFX_TBL_ALP3211;
	} else {
		ret = SFX_TBL_ALP3211;
	}
	return ret;
}

// Whether the layout stores the picture in the upper half of the frame (0x21 / 0x101: the lower
// half carries alpha or Z), so the output height is halved.
// FUN_0052A788
Sint32 sfxcnv_IsCnvUpHalf(SFX_OBJ *sfx)
{
	switch (sfx->compo) {
	case SFX_COMPO_YCC420PLN:
	case SFX_COMPO_0x31:
	case SFX_COMPO_0x41:
	case SFX_COMPO_0x51:
	case SFX_COMPO_0x61:
	case SFX_COMPO_0x71:
	case SFX_COMPO_0xF1:
	case SFX_COMPO_0x111:
	case SFX_COMPO_0x1001:
		return 0;
	case SFX_COMPO_YCC420PLN_UPHALF:
	case SFX_COMPO_0x101:
		return 1;
	default:
		SFXLIB_Error(NULL, NULL, "E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
		break;
	}
	return 0;
}

// Flips a plane to bottom-up: start at the last line, negative pitch.
// FUN_0052A738
void SFX_SetBottomUpPlnBuf(SFX_PLN *pln)
{
	pln->buf += pln->pitch * (pln->height - 1);
	pln->pitch = -pln->pitch;
}
