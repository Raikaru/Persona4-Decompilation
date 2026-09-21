/* CRI Sofdec SFX library (sfx_lib.c, "CRI SFX/GC Ver.2.08", Sep 22 2004): the frame conversion
 * ("special effects") layer between the decoded YCC 4:2:0 frames and the application's textures.
 * A converter handle (8 max) carries the stream's component layout, the output size, the
 * conversion table buffer and the Z / alpha sub-objects; the MW player creates one per movie
 * (MWSFSFX_Create) and drives it through mwPlyFxCnvFrm*. */
#include "cri_xpt.h"
#include "sfx.h"
#include <string.h>

const Char8 sfx_ver_str[] = "\nCRI SFX/GC Ver.2.08 Build:Sep 22 2004 10:35:23\n";

Sint32 sfx_init_cnt = 0;
Sint32 sfxcnv_forcesplit = 0;
SFX_LIBWORK sfx_libwork;
const Char8 *sfx_dummy;

// CCIR601 range conversion switch (1: studio range 16..235 is scaled to full range).
Sint32 SFX_GetCcirFx(void)
{
	return sfx_libwork.ccir_fx;
}

// Counts the error and calls the registered callback (the MW player's mwsfsfx_SfxErrCbFn).
void SFXLIB_Error(SFX_OBJ *sfx, SFX_FRM *frm, const Char8 *msg)
{
	void (*fn)(void *obj, const Char8 *msg);
	void *obj;

	fn = sfx_libwork.errfn;
	obj = sfx_libwork.errobj;
	sfx_libwork.err_cnt++;
	if (fn != NULL) {
		fn(obj, msg);
	}
}

// Frees the converter and its Z / alpha sub-objects.
void SFX_Destroy(SFX_OBJ *sfx)
{
	SFXZ_OBJ *sfxz;
	SFXA_OBJ *sfxa;

	if (sfx == NULL) {
		return;
	}
	sfxz = sfx->sfxz;
	sfxa = sfx->sfxa;
	sfx->used = 0;
	SFXZ_Destroy(sfxz);
	SFXA_Destroy(sfxa);
	sfx_libwork.hn_cnt--;
}

// First unused of the 8 converters, NULL when none.
static SFX_OBJ *sfx_GetFreeHn(void)
{
	SFX_OBJ *sfx;
	Sint32 i;

	sfx = sfx_libwork.hn;
	for (i = 0; i < sfx_libwork.max_hn; i++) {
		if (sfx->used == 0) {
			return sfx;
		}
		sfx++;
	}
	return NULL;
}

// The work must hold the four 0x400-byte buffers plus alignment (0x301F bytes).
static Bool sfx_IsEnoughWork(Sint32 wsize)
{
	return wsize >= SFX_WORK_SIZE;
}

// Takes a converter handle over `work`: four 32-byte-aligned 1 KiB buffers (buf[0] holds the
// conversion table), default output layout YCC 4:2:0 planar, layout unknown until the first frame,
// plus a Z and an alpha sub-object. NULL with an error when the work is short.
SFX_OBJ *SFX_Create(void *work, Sint32 wsize)
{
	SFX_OBJ *sfx;
	SFXZ_OBJ *sfxz;
	SFXA_OBJ *sfxa;

	sfx = sfx_GetFreeHn();
	if (sfx == NULL) {
		return sfx;
	}
	if (sfx_IsEnoughWork(wsize) != TRUE) {
		SFXLIB_Error(NULL, NULL, "E201194: sfx_InitHn: work size is short.");
		return NULL;
	}
	memset(sfx, 0, sizeof(SFX_OBJ));
	sfx->compo = 0;
	sfx->fxtype = SFX_COMPO_YCC420PLN;
	sfx->outbuf_width = 0;
	sfx->outbuf_height = 0;
	sfx->x2c = 1;
	sfx->x30 = 0;
	sfx->tbl_type = 0;
	sfx->buf[0] = (Uint8 *)(((Uint32)work + 0x1F) & ~0x1F);
	sfx->buf[1] = sfx->buf[0] + SFX_BUF_SIZE;
	sfx->buf[2] = sfx->buf[1] + SFX_BUF_SIZE;
	sfx->buf[3] = sfx->buf[2] + SFX_BUF_SIZE;
	sfx->work = work;
	sfx->wsize = wsize;
	sfx->x68 = -1;
	sfx->x74 = 0;
	sfx->used = 1;
	sfxz = SFXZ_Create();
	if (sfxz == NULL) {
		SFXLIB_Error(NULL, NULL, "E201281: SfxZHn: can't create.");
		SFX_Destroy(sfx);
		return NULL;
	}
	sfx->sfxz = sfxz;
	sfxa = SFXA_Create();
	if (sfxa == NULL) {
		SFXLIB_Error(NULL, NULL, "E202011: SfxAHn: can't create.");
		SFX_Destroy(sfx);
		return NULL;
	}
	sfx->sfxa = sfxa;
	sfx_libwork.hn_cnt++;
	return sfx;
}

// Installs the library error callback.
void SFX_SetErrFn(void (*fn)(void *obj, const Char8 *msg), void *obj)
{
	sfx_libwork.errfn = fn;
	sfx_libwork.errobj = obj;
}

// Library init (once): clears the work (8 handles, CCIR range on), builds the YCC -> RGB tables and
// initialises the user-data, Z and alpha modules.
void SFX_Init(void)
{
	if (sfx_init_cnt < 1) {
		sfx_dummy = sfx_ver_str;
		memset(&sfx_libwork, 0, sizeof(sfx_libwork));
		sfx_libwork.max_hn = SFX_MAX_HN;
		sfx_libwork.ccir_fx = 1;
		CFT_Ycc420plnToArgb8888Init();
		SFXSUD_Init();
		SFXZ_Init();
		SFXA_Init();
		sfxcnv_forcesplit = 0;
		sfx_init_cnt++;
	}
}
