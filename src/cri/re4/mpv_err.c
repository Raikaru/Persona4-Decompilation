/* CRI Sofdec MPV error reporting (mpv_err.c): the per-handle / library error record (callback,
 * object, last code) and MPVERR_SetCode, the return path of every MPV_* API (0xFF03xxxx codes).
 * The SFD video driver installs sfmpv_ErrFn. */
#include "cri_xpt.h"

typedef struct {
	void (*func)(void *obj, Sint32 code);
	void *obj;
	Sint32 code;
	Sint32 reserved[2];
} MPVERR_INF;

typedef struct {
	Uint8 pad[0x250];
	MPVERR_INF errinf;
} MPV_OBJ;

extern Sint32 MPVLIB_CheckHn(MPV_OBJ *mpv);

MPVERR_INF mpverrinf;
Sint32 mpverr_work;

// Records `code` on the handle (or the library when mpv is NULL) and calls the error callback for a
// nonzero code; returns the code.
Sint32 MPVERR_SetCode(MPV_OBJ *mpv, Sint32 code)
{
	if (mpv == NULL) {
		mpverrinf.code = code;
		if (code != 0) {
			if (mpverrinf.func != NULL) {
				mpverrinf.func(mpverrinf.obj, code);
			}
		}
	} else {
		mpv->errinf.code = code;
		if (code != 0) {
			if (mpv->errinf.func != NULL) {
				mpv->errinf.func(mpv->errinf.obj, code);
			}
		}
	}
	return code;
}

// Installs the handle's error callback (func(obj, code)).
Sint32 MPV_SetErrFunc(MPV_OBJ *mpv, void (*func)(void *obj, Sint32 code), void *obj)
{
	if (MPVLIB_CheckHn(mpv) != 0) {
		return MPVERR_SetCode(NULL, 0xFF030203);
	}
	mpv->errinf.func = func;
	mpv->errinf.obj = obj;
	return 0;
}

// Clears an error record.
void MPVERR_InitErrInf(MPVERR_INF *inf)
{
	inf->func = NULL;
	inf->obj = NULL;
	inf->code = 0;
	inf->reserved[0] = 0;
	inf->reserved[1] = 0;
}

// Clears the library-wide error record.
void MPVERR_Init(void)
{
	MPVERR_InitErrInf(&mpverrinf);
}
