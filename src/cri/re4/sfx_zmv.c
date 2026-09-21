/* Sofdec SFX: Z (depth) movie conversion tables (sfx_zmv.c). The Z component of an SFX frame is
 * 8-bit; the conversion table maps it to a 16/32-bit Z buffer value through the original Z range
 * ("ZMFSIZE"/"ZMFDATA" tags of the stream) and the near/far clip planes of the handle. The
 * frame-format converters of this file were dead-stripped by the linker (their error strings and
 * constants remain in .rodata). */
#include "cri_xpt.h"
#include <string.h>
#include <stdio.h>
#include "sj.h"
#include "sfx.h"

#define SFXZ_MAX_HN 8
#define SFXZ_INVALID_Z 0x80000000
#define SFXZ_MAX_Z 0x7FFFFFFF

typedef struct SFXZ_OBJ {
	Sint32 used;               /* 0x00 */
	Sint32 zbit;               /* 0x04 output Z depth (16/32) */
	Sint32 taginf_flg;         /* 0x08 */
	Uint8 *tag_a;              /* 0x0C */
	Sint32 tag_b;              /* 0x10 */
	Sint32 pad14;
	Sint32 hdr_flg;            /* 0x18 "ZMHDR" searched */
	Sint32 hdr_a;              /* 0x1C */
	Sint32 hdr_b;              /* 0x20 */
	Sint32 pad24;
	Sint32 frm_flg;            /* 0x28 "ZMVFRM" searched */
	Uint8 *frm_ptr;            /* 0x2C */
	Sint32 frm_len;            /* 0x30 */
	Sint32 pad34;
	Sint32 pad38;
	Float32 zmin;              /* 0x3C */
	Float32 zmax;              /* 0x40 */
	void (*cnvfunc)(Uint32 *orgtbl, void *tbl, Float32 zmin, Float32 zmax); /* 0x44 user table maker */
	Sint32 pad48;
} SFXZ_OBJ;

typedef struct {
	Sint32 cnt;                /* 0x00 */
	Sint32 linear;             /* 0x04 linear Z mapping */
	Sint32 nobj;               /* 0x08 */
	SFXZ_OBJ obj[SFXZ_MAX_HN]; /* 0x0C */
} SFXZ_WORK;

extern Sint32 SFX_GetCcirFx(void);
extern Sint32 sscanf(const Char8 *s, const Char8 *fmt, ...);

SFXZ_WORK sfxz_work;

void sfxzmv_MakeOrgZ32TblByCCIR(SFXZ_OBJ *sfxz, Uint32 zmf_dat, Uint32 zmf_siz, Uint32 *tbl);
void sfxzmv_MakeOrgZ32TblByDirect(SFXZ_OBJ *sfxz, Uint32 zmf_dat, Uint32 zmf_siz, Uint32 *tbl);

/* dead */
static Sint32 sfxcnv_CnvZbitToCft(Sint32 zbit)
{
	Sint32 ret;

	switch (zbit) {
	case 16:
		ret = 1;
		break;
	case 24:
		ret = 2;
		break;
	case 32:
		ret = 3;
		break;
	default:
		SFXLIB_Error(NULL, NULL, "E201313: sfxcnv_CnvZbitToCft : zbit is invalid.");
		ret = 0;
		break;
	}
	return ret;
}

/* dead */
static void sfxcnv_CnvFrmZcmn(SFX_OBJ *sfx, SFX_FRM *frm, void *buf)
{
	SFXZ_OBJ *sfxz = sfx->sfxz;

	if (sfx->compo == 0) {
		sfx->compo = SFXINF_GetStmInf(frm, "COMPO");
	}
	if (sfxz->zmin == 0.0f && sfxz->zmax == 0.0f) {
		SFXLIB_Error(sfx, frm, "E201315: sfxcnv_CnvFrmZcmn : zclip is not set.");
		return;
	}
	sfxz->zbit = sfxcnv_CnvZbitToCft(sfxz->zbit);
}

/* dead */
void SFX_CnvFrmZcmn(SFX_OBJ *sfx, SFX_FRM *frm, void *buf)
{
	if (frm->frmfmt != 3) {
		SFXLIB_Error(sfx, frm, "E201191: SFX_CnvFrmZcmn : frmfmt is not support.");
		return;
	}
	sfxcnv_CnvFrmZcmn(sfx, frm, buf);
}

/* dead */
void SFXZ_SetZclip(SFXZ_OBJ *sfxz, Float32 zmin, Float32 zmax)
{
	if (zmin < -14.0f || zmax <= zmin) {
		SFXLIB_Error(NULL, NULL, "E201314: SFXZ_SetZclip : zclip is invalid.");
		return;
	}
	sfxz->zmin = zmin;
	sfxz->zmax = zmax;
}

/* the 32-bit conversion table from the original Z values: linear mapping keeps the upper bits,
 * otherwise the perspective mapping between the clip planes (inlined into sfxzmv_MakeCnvZTbl) */
static void sfxzmv_MakeZ32Tbl(SFXZ_OBJ *sfxz, Uint32 *orgtbl, Uint32 *tbl)
{
	Float64 zmin = sfxz->zmin;
	Float64 zmax = sfxz->zmax;

	if (sfxz_work.linear == 1) {
		Sint32 i;

		for (i = 0; i < 256; i++) {
			tbl[i] = orgtbl[i] & 0x7FFFFF80;
			tbl[i] <<= 1;
		}
	} else {
		Sint32 i;
		Uint32 *dst;
		Uint32 *src;
		Float64 rcp;
		Float64 a;
		Float64 b;

		src = orgtbl;
		dst = tbl;
		rcp = 1.0 / (zmax - zmin);
		a = 16777215.0 * zmax * rcp;
		b = zmax * (16777215.0 * rcp * zmin);
		for (i = 0; i < 256; i++) {
			if (*src == 0) {
				*src = 1;
			}
			*dst = (Uint32)(a - b / (zmax * (Float64)*src / 2147483647.0));
			src++;
			dst++;
		}
	}
}

/* the 16-bit conversion table */
static void sfxzmv_MakeZ16Tbl(SFXZ_OBJ *sfxz, Uint32 *orgtbl, Uint16 *tbl)
{
	Float64 zmin = sfxz->zmin;
	Float64 zmax = sfxz->zmax;

	if (sfxz_work.linear == 1) {
		Sint32 i;

		for (i = 0; i < 256; i++) {
			tbl[i] = (Uint16)(orgtbl[i] >> 15);
		}
	} else {
		Sint32 i;
		Uint16 *dst;
		Uint32 *src;
		Float64 rcp;
		Float64 a;
		Float64 b;

		src = orgtbl;
		dst = tbl;
		rcp = 1.0 / (zmax - zmin);
		a = 65535.0 * zmax * rcp;
		b = zmax * (65535.0 * rcp * zmin);
		for (i = 0; i < 256; i++) {
			if (*src == 0) {
				*src = 1;
			}
			*dst++ = (Sint32)(a - b / (zmax * (Float64)*src / 2147483647.0));
			src++;
		}
	}
}

/* the 256-entry conversion table at tbl (Uint16 or Uint32 per zbit) from the original 32-bit Z
 * values built at tbl + 0x400 (or by the handle's own table maker). The helpers' src/dst pairs are
 * declared dst-first and assigned src-first (CRI pass 19b, 96 -> 12w, pure C): the copy assigned
 * first ranks above the other (src r3/r5/r29 before dst r4/r6/r28) and tbl stays live across the
 * src copy (its three extra neighbours keep it in level 2 = r31). The linear loops index tbl/orgtbl
 * directly: the strength-reduced pointers are initialised in the loop preheader (after the guard),
 * where user copies sit in the guard block (CRI pass 20, 12 -> 0w). The Z32 perspective loop
 * increments src before dst (`*dst = ...; src++; dst++`). */
void sfxzmv_MakeCnvZTbl(SFXZ_OBJ *sfxz, Uint32 zmf_dat, Uint32 zmf_siz, void *tbl)
{
	Uint32 *orgtbl;

	orgtbl = (Uint32 *)((Uint8 *)tbl + 0x400);
	memset(tbl, 0, 0x400);
	if (SFX_GetCcirFx() == 1) {
		sfxzmv_MakeOrgZ32TblByCCIR(sfxz, zmf_dat, zmf_siz, orgtbl);
	} else {
		sfxzmv_MakeOrgZ32TblByDirect(sfxz, zmf_dat, zmf_siz, orgtbl);
	}
	if (sfxz->cnvfunc == NULL) {
		if (sfxz->zbit == 16) {
			sfxzmv_MakeZ16Tbl(sfxz, orgtbl, (Uint16 *)tbl);
		} else {
			sfxzmv_MakeZ32Tbl(sfxz, orgtbl, (Uint32 *)tbl);
		}
	} else {
		sfxz->cnvfunc(orgtbl, tbl, sfxz->zmin, sfxz->zmax);
	}
}

/* the original Z range of the frame from the "ZMFSIZE"/"ZMFDATA" tags of the stream information
 * (the frame's entry is `n * src` bytes into the data tag) */
// Builds the Z conversion table for the current frame: the frame's Z range from the "ZMFSIZE" /
// "ZMFDATA" tags and the handle's near/far planes, through the 16- or 32-bit Z converter.
void SFXZ_MakeCnvZTbl(SFXZ_OBJ *sfxz, void *src, void *tbl)
{
	SJCK out1;
	SJCK inf1;
	SJCK out2;
	SJCK inf2;
	Uint32 zmf_c;
	Uint32 zmf_b;
	Uint32 zmf_a;
	Uint32 n;
	Char8 *p;
	Uint32 zmf_dat;
	Uint32 zmf_siz;

	if (sfxz->frm_flg != 1 || sfxz->frm_ptr == NULL) {
		p = NULL;
	} else {
		inf1.data = sfxz->frm_ptr;
		inf1.len = sfxz->frm_len;
		SJ_SearchTag(&inf1, "ZMFSIZE", "SFXINFE", &out1);
		p = (Char8 *)out1.data;
	}
	if (p == NULL) {
		zmf_dat = 0;
		zmf_siz = SFXZ_MAX_Z;
	} else {
		sscanf(p, "%lx", &n);
		if (sfxz->frm_flg != 1 || sfxz->frm_ptr == NULL) {
			p = NULL;
		} else {
			inf2.data = sfxz->frm_ptr;
			inf2.len = sfxz->frm_len;
			SJ_SearchTag(&inf2, "ZMFDATA", "SFXINFE", &out2);
			p = (Char8 *)out2.data;
		}
		if (p == NULL) {
			zmf_dat = SFXZ_MAX_Z;
		} else {
			sscanf(p + n * (Uint32)src, "%lx %lx %lx", &zmf_a, &zmf_b, &zmf_c);
			zmf_dat = zmf_b;
			zmf_siz = zmf_c;
		}
	}
	sfxzmv_MakeCnvZTbl(sfxz, zmf_dat, zmf_siz, tbl);
}

/* the 32-bit Z of each of the 256 Z index values: 0 below 9, the near value up to 16, a ramp
 * from the near to the far value up to 0xDF, the far value up to 0xEF and the maximum above */
#define SFXZ_MAKE_ORG_Z32_TBL(zmf_dat, zmf_siz, tbl)                                          \
	{                                                                                      \
		Sint32 i;                                                                      \
		Uint32 *p;                                                                     \
		if ((zmf_siz) == SFXZ_INVALID_Z) {                                             \
			(zmf_siz) = SFXZ_MAX_Z;                                                \
		}                                                                              \
		if ((zmf_dat) == SFXZ_INVALID_Z) {                                             \
			(zmf_dat) = SFXZ_MAX_Z;                                                \
		}                                                                              \
		p = (tbl);                                                                     \
		for (i = 0; i < 9; i++) {                                                      \
			*p++ = 0;                                                              \
		}                                                                              \
		for (i = 9; i < 17; i++) {                                                     \
			(tbl)[i] = (zmf_dat);                                                  \
		}                                                                              \
		if ((zmf_dat) == (zmf_siz)) {                                                  \
			for (i = 17; i < 0xE0; i++) {                                          \
				(tbl)[i] = (zmf_dat);                                          \
			}                                                                      \
		} else {                                                                       \
			for (i = 17; i < 0xE0; i++) {                                          \
				(tbl)[i] = (zmf_dat) + (i - 17) * (((zmf_siz) - (zmf_dat)) / (0xE0 - 17)); \
			}                                                                      \
		}                                                                              \
		for (i = 0xE0; i < 0xF0; i++) {                                                \
			(tbl)[i] = (zmf_siz);                                                  \
		}                                                                              \
		for (i = 0xF0; i < 0x100; i++) {                                               \
			(tbl)[i] = SFXZ_MAX_Z;                                                 \
		}                                                                              \
	}

/* the 32-bit Z of each 8-bit Z sample: the CCIR601 luma range (16..235) is stretched to 0..255
 * first, then the index maps to the original range. One counter per loop: the 1.164 loop's counter
 * must be the ninth local (virtual r43) so that the post-schedule addi sink stops at `stfd f43`
 * and the 8x unrolled body keeps its pre-RA schedule (CRI pass 41). */
void sfxzmv_MakeOrgZ32TblByCCIR(SFXZ_OBJ *sfxz, Uint32 zmf_dat, Uint32 zmf_siz, Uint32 *tbl)
{
	Sint32 i, j, k, l;
	Uint32 *d;
	Uint8 *ytbl;
	Uint32 *ztbl;

	ztbl = tbl + 0x100;
	ytbl = (Uint8 *)(ztbl + 0x100);
	for (j = 0; j <= 0x0F; j++) {
		ytbl[j] = 0;
	}
	for (i = 0x10; i <= 0xEB; i++) {
		ytbl[i] = 1.164f * (Float32)(i - 16);
	}
	for (k = 0xEC; k <= 0xFF; k++) {
		ytbl[k] = 0xFF;
	}
	SFXZ_MAKE_ORG_Z32_TBL(zmf_dat, zmf_siz, ztbl);
	d = tbl;
	for (l = 0; l <= 0xFF; l++) {
		*d++ = ztbl[ytbl[l]];
	}
}

/* the same without the luma range correction */
void sfxzmv_MakeOrgZ32TblByDirect(SFXZ_OBJ *sfxz, Uint32 zmf_dat, Uint32 zmf_siz, Uint32 *tbl)
{
	SFXZ_MAKE_ORG_Z32_TBL(zmf_dat, zmf_siz, tbl);
}

/* the stream's SFX tag information: the "ZMHDR" and "ZMVFRM" sub-tags */
void SFXZ_SetTagInf(SFXZ_OBJ *sfxz, Uint8 *tag_a, Sint32 tag_b)
{
	SJCK out;
	SJCK inf;

	sfxz->taginf_flg = 1;
	sfxz->tag_a = tag_a;
	sfxz->tag_b = tag_b;
	if (sfxz->tag_a == NULL) {
		sfxz->hdr_flg = 1;
		sfxz->hdr_a = 0;
		sfxz->hdr_b = 0;
		sfxz->frm_flg = 1;
		sfxz->frm_ptr = NULL;
		sfxz->frm_len = 0;
	} else {
		inf.data = sfxz->tag_a;
		inf.len = sfxz->tag_b;
		SJ_SearchTag(&inf, "ZMHDR", "SFXINFE", &out);
		sfxz->hdr_flg = 1;
		sfxz->hdr_a = (Sint32)out.data;
		sfxz->hdr_b = out.len;
		SJ_SearchTag(&inf, "ZMVFRM", "SFXINFE", &out);
		sfxz->frm_flg = 1;
		sfxz->frm_ptr = out.data;
		sfxz->frm_len = out.len;
	}
}

// Frees the object.
void SFXZ_Destroy(SFXZ_OBJ *sfxz)
{
	if (sfxz == NULL) {
		return;
	}
	sfxz->used = 0;
	sfxz_work.cnt--;
}

// First unused Z object, NULL when none.
static SFXZ_OBJ *sfxz_search_free(void)
{
	SFXZ_OBJ *sfxz;
	Sint32 i;

	sfxz = sfxz_work.obj;
	for (i = 0; i < sfxz_work.nobj; i++) {
		if (sfxz->used == 0) {
			return sfxz;
		}
		sfxz++;
	}
	return NULL;
}

// Takes a Z object: zero range, no converter.
SFXZ_OBJ *SFXZ_Create(void)
{
	SFXZ_OBJ *sfxz;

	sfxz = sfxz_search_free();
	if (sfxz == NULL) {
		return sfxz;
	}
	sfxz->zmin = 0.0f;
	sfxz->zmax = 0.0f;
	sfxz->cnvfunc = NULL;
	sfxz->pad48 = 0;
	sfxz->zbit = 0;
	sfxz_work.cnt++;
	sfxz->used = 1;
	return sfxz;
}

// Clears the Z object table.
void SFXZ_Init(void)
{
	memset(&sfxz_work, 0, sizeof(sfxz_work));
	sfxz_work.nobj = SFXZ_MAX_HN;
	sfxz_work.linear = 0;
}
