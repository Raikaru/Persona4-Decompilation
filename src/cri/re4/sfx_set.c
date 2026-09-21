/* CRI Sofdec SFX settings (sfx_set.c): colour adjustment, the additional-info tag block, output
 * size / unit, output layout and component mode of a converter handle; the setters the MW player's
 * mwPlyFx* accessors forward to. */
#include "cri_xpt.h"

typedef struct {
	Sint32 pad0;
	Sint32 compo_mode;
	Sint32 fxtype;
	Sint32 outbuf_width;
	Sint32 outbuf_height;
	Sint32 unit_width;
	Sint32 taginf_flg;
	Sint32 tag_a;
	Sint32 tag_b;
	Sint32 pad24;
	void *sfxz;
	Sint32 pad2C[3];
	void *coladj;
} SFX_OBJ;

typedef struct {
	Sint32 a;
	Sint32 b;
} SFX_TAGINF;

extern void *SJ_SearchTag(SFX_TAGINF *inf, const Char8 *tag, const Char8 *name, SFX_TAGINF *out);
extern void SFXZ_SetTagInf(void *sfxz, Sint32 a, Sint32 b);

// The colour adjustment table pointer / flag (1 = adjust) the converter uses.
void *SFX_GetColAdj(SFX_OBJ *sfx)
{
	return sfx->coladj;
}

// Sets the colour adjustment (from the Sofdec header colour type or picture user data).
void SFX_SetColAdj(SFX_OBJ *sfx, void *coladj)
{
	sfx->coladj = coladj;
}

// The tag info block (address, length) given by SFX_SetTagInf, 0/0 when none.
void SFX_GetTagInf(SFX_OBJ *sfx, Sint32 *a, Sint32 *b)
{
	if (sfx->taginf_flg != 1) {
		*a = 0;
		*b = 0;
	} else {
		*a = sfx->tag_a;
		*b = sfx->tag_b;
	}
}

// Records the "SFXINFS" tag block of the additional-info stream and passes its "SFXZ" record to the
// Z sub-object.
void SFX_SetTagInf(SFX_OBJ *sfx, Sint32 a, Sint32 b)
{
	SFX_TAGINF inf;
	SFX_TAGINF out;
	void *sfxz = sfx->sfxz;

	sfx->tag_a = a;
	sfx->tag_b = b;
	inf.a = a;
	inf.b = b;
	if (SJ_SearchTag(&inf, "SFXZ", "SFXINFE", &out) == NULL) {
		SFXZ_SetTagInf(sfxz, 0, 0);
	} else {
		SFXZ_SetTagInf(sfxz, out.a, out.b);
	}
	sfx->taginf_flg = 1;
}

// 1: the output size is in pixels; 0: the width is a byte pitch (mwPlyFxSetOutBufPitchHeight).
void SFX_SetUnitWidth(SFX_OBJ *sfx, Sint32 width)
{
	sfx->unit_width = width;
}

// Output texture size; 0 = the frame size.
void SFX_SetOutBufSize(SFX_OBJ *sfx, Sint32 width, Sint32 height)
{
	sfx->outbuf_width = width;
	sfx->outbuf_height = height;
}

// Output layout type.
Sint32 SFX_GetFxType(SFX_OBJ *sfx)
{
	return sfx->fxtype;
}

// Output layout type.
void SFX_SetFxType(SFX_OBJ *sfx, Sint32 fxtype)
{
	sfx->fxtype = fxtype;
}

// Component layout mode requested by the player (MWSFSFX_DecideCompoMode).
void SFX_SetCompoMode(SFX_OBJ *sfx, Sint32 mode)
{
	sfx->compo_mode = mode;
}
