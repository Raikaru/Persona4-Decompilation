/* Sofdec SFX: YCC 4:2:0 planar frame -> ARGB8888 conversion front end (per component layout) */
#include "cri_xpt.h"
#include "sfx.h"

/* planar source as the CFT ARGB converters take it (0x1C bytes) */
typedef struct {
	void *y;                   /* 0x00 */
	void *cb;                  /* 0x04 */
	void *cr;                  /* 0x08 */
	Sint32 ywidth;             /* 0x0C */
	Sint32 cbwidth;            /* 0x10 */
	Sint32 crwidth;            /* 0x14 */
	Sint32 x18;
} SFXCNV_YCC420PLN;

extern Sint32 SFX_GetColAdj(SFX_OBJ *sfx);
extern Sint32 SFX_GetCcirFx(void);
extern void SFX_MakeTable(SFX_OBJ *sfx, SFX_FRM *frm, Sint32 type);
extern Sint32 SFX_DecideTableAlph3(SFX_OBJ *sfx, Sint32 compo);
extern void SFX_SetBottomUpPlnBuf(SFX_PLN *pln);
extern void CFT_Ycc420plnToArgb8888(void *src, void *dst, void *tbl);
extern void CFT_Ycc420plnToA256V(void *src, void *dst, void *tbl);
extern void CFT_Argb420ToArgb8(void *src, void *dst, Sint32 width, Sint32 height);

/* destination plane as the CFT ARGB converters take it (0x18 bytes) */
typedef struct {
	void *buf;                 /* 0x00 */
	Sint32 width;              /* 0x04 */
	Sint32 height;             /* 0x08 */
	Sint32 pitch;              /* 0x0C */
	Sint32 x10;
	Sint32 x14;
} SFXCNV_ARGBDST;

/* the destination is the frame size (halved when only the upper half is converted) with the pitch
 * from the output buffer width */
#define SFXCNV_SET_ARGB_DST(sfx, frm, buf, dst) \
	(dst).buf = (buf); \
	(dst).width = (frm)->width; \
	if (sfxcnv_IsCnvUpHalf(sfx) == 1) { \
		(dst).height = (frm)->height / 2; \
	} else { \
		(dst).height = (frm)->height; \
	} \
	if ((sfx)->outbuf_width == 0) { \
		(dst).pitch = (frm)->pln[0].width * 4; \
	} else if ((sfx)->unit_width == 0) { \
		(dst).pitch = (sfx)->outbuf_width / 4; \
	} else { \
		(dst).pitch = (sfx)->outbuf_width; \
	} \
	if ((sfx)->x74 == 1) { \
		SFX_SetBottomUpPlnBuf((SFX_PLN *)&(dst)); \
	}

/* tblflg: convert through the table in buf[0]. A macro with block locals rather than a static helper:
 * with a helper sfxcnv_CnvAlphFulYcc420plnToArgb8888 becomes small enough to be inlined into
 * SFX_CnvFrmYcc420plnToArgb8888 (the original calls it). */
#define SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, tblflg) \
	{ \
		SFXCNV_ARGBDST dst; \
		SFXCNV_YCC420PLN src; \
		void *tbl; \
		src.y = (frm)->pln[0].buf; \
		src.cb = (frm)->pln[1].buf; \
		src.cr = (frm)->pln[2].buf; \
		src.ywidth = (frm)->pln[0].width; \
		src.cbwidth = (frm)->pln[1].width; \
		src.crwidth = (frm)->pln[2].width; \
		SFXCNV_SET_ARGB_DST(sfx, frm, buf, dst); \
		tbl = (tblflg) ? (sfx)->buf[0] : NULL; \
		if ((frm)->chromapos_h == 1) { \
			if (tbl != NULL) { \
				CFT_Ycc420plnToArgb8888(&src, &dst, tbl); \
			} else { \
				CFT_Ycc420plnToArgb8888(&src, &dst, NULL); \
			} \
		} else { \
			if (tbl != NULL) { \
				CFT_Ycc420plnToArgb8888(&src, &dst, tbl); \
			} else { \
				CFT_Ycc420plnToArgb8888(&src, &dst, NULL); \
			} \
		} \
	}

/* colour in the upper half of the frame, the alpha plane (as luminance) in the lower half */
void sfxcnv_CnvAlphFulYcc420plnToArgb8888(SFX_OBJ *sfx, SFX_FRM *frm, void *buf)
{
	SFXCNV_YCC420PLN src;
	SFXCNV_ARGBDST dst;
	void *tbl;
	Sint32 half;

	SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 0)
	half = frm->pln[0].width * frm->pln[0].height / 2;
	src.y = frm->pln[0].buf + half;
	src.cb = frm->pln[1].buf + half / 2;
	src.cr = frm->pln[2].buf + half / 2;
	src.ywidth = frm->pln[0].width;
	src.cbwidth = frm->pln[1].width;
	src.crwidth = frm->pln[2].width;
	dst.buf = buf;
	dst.width = frm->width;
	dst.height = frm->height / 2;
	if (sfx->outbuf_width == 0) {
		dst.pitch = frm->pln[0].width * 4;
	} else if (sfx->unit_width == 0) {
		dst.pitch = sfx->outbuf_width / 4;
	} else {
		dst.pitch = sfx->outbuf_width;
	}
	if (SFX_GetCcirFx() == 1) {
		tbl = sfx->buf[0];
	} else {
		tbl = NULL;
	}
	CFT_Ycc420plnToA256V(&src, &dst, tbl);
}

// Planar YCC 4:2:0 -> ARGB8888 by component layout: plain (0x11, optionally through the colour
// adjustment table), upper-half picture (0x101), packed ARGB 4:2:0 (0xF1), luma-alpha (0x21/0x31)
// and three-level alpha layouts (0x41/0x51/0x61) through their tables; others are errors.
void SFX_CnvFrmYcc420plnToArgb8888(SFX_OBJ *sfx, SFX_FRM *frm, void *buf)
{
	Sint32 compo = sfx->compo;

	switch (compo) {
	case SFX_COMPO_YCC420PLN:
		if (SFX_GetColAdj(sfx) != 1) {
			SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 0)
		} else {
			SFX_MakeTable(sfx, frm, SFX_TBL_ARGB8888_COLADJ);
			SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 1)
		}
		break;
	case SFX_COMPO_0x101:
		SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 0)
		break;
	case SFX_COMPO_0xF1:
		CFT_Argb420ToArgb8(frm->pln[0].buf, buf, frm->pln[0].width, frm->pln[0].height);
		break;
	case SFX_COMPO_YCC420PLN_UPHALF:
		SFX_MakeTable(sfx, frm, SFX_TBL_LUMI);
		sfxcnv_CnvAlphFulYcc420plnToArgb8888(sfx, frm, buf);
		break;
	case SFX_COMPO_0x31:
		SFX_MakeTable(sfx, frm, SFX_TBL_ALP_LUMI);
		SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 1)
		break;
	case SFX_COMPO_0x41:
	case SFX_COMPO_0x51:
	case SFX_COMPO_0x61:
		SFX_MakeTable(sfx, frm, SFX_DecideTableAlph3(sfx, compo));
		SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 1)
		break;
	case SFX_COMPO_0x1001:
		SFX_MakeTable(sfx, frm, SFX_TBL_ARGB8888_COLADJ);
		SFXCNV_CNV_YCC420PLN_TO_ARGB8888(sfx, frm, buf, 1)
		break;
	case SFX_COMPO_0x71:
	case SFX_COMPO_0x111:
	default:
		SFXLIB_Error(sfx, frm, "E201182: CnvToArgb8888 : compo is not support.");
		break;
	}
}
