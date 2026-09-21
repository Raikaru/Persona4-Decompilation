/* CRI Sofdec decoder core library init and errors (sfd_lib.c, "CRI SFD/GC Ver.1.947", Sep 22 2004):
 * SFD_Init sets up the library work (default conditions, driver table, timing, buffers), SFLIB_CheckHn
 * validates handles and SFLIB_SetErr is the error path every SFD_* function returns through
 * (0xFF00xxxx codes, first code kept, handle state negated, callback to the MW player). */
#include "cri_xpt.h"
#include "sfd.h"

#define SFD_VERSION 0x3598

extern void SVM_Lock(void);
extern void SVM_Unlock(void);
extern void SJRBF_Init(void);
extern void UTY_MemsetDword(Uint32 *dst, Uint32 val, Uint32 ndw);
extern void MEM_Copy(void *dst, const void *src, Uint32 nbytes);
extern const Sint32 SFPLY_cond_dfl[SFD_COND_NUM];
extern void SFTIM_Init(void *work);
extern void SFBUF_Init(void *work);
extern Sint32 SFTRN_Init(SFTRN_TRIF_TBL *dst, SFTRN_TRIF_TBL *src);
extern void SFPLY_Init(void);
extern void SFHDS_Init(void);

const Char8 SFLIB_version_str[] = "\nCRI SFD/GC Ver.1.947 Build:Sep 22 2004 10:35:15\n\0Append: MW2407 GC20Apr2004Patch1\n";

static Sint32 sflib_sizeof_sfdhn = 0;
Char8 *SFD_pts_error_msg = NULL;
SFD sfd_hn_last = NULL;
static const Char8 *cri_verstr_ptr = NULL;
SFLIB_WORK SFLIB_libwork;

// Leaves the SFD critical section (SVM_Unlock, a no-op in this game).
void SFLIB_UnlockCs(Sint32 *cs)
{
	SVM_Unlock();
}

// Enters the SFD critical section.
void SFLIB_LockCs(Sint32 *cs)
{
	SVM_Lock();
}

// -1 for a NULL or destroyed handle (stat 0); records the handle in sfd_hn_last for debugging.
Sint32 SFLIB_CheckHn(SFD sfd)
{
	sfd_hn_last = sfd;
	if (sfd == NULL) {
		return -1;
	}
	if (sfd->stat == 0) {
		return -1;
	}
	return 0;
}

// Records the first error code (per handle or library-wide), calls the error callback, and makes the
// handle's state negative so the player sees an error.
static Sint32 sflib_SetErr(SFD sfd, Sint32 code)
{
	if (sfd == NULL) {
		if (SFLIB_libwork.err.code == 0) {
			SFLIB_libwork.err.code = code;
		}
		if (code != 0 && SFLIB_libwork.err.fn != NULL) {
			SFLIB_libwork.err.fn(SFLIB_libwork.err.obj, code);
		}
	} else {
		if (sfd->err.code == 0) {
			sfd->err.code = code;
		}
		if (code != 0 && sfd->err.fn != NULL) {
			sfd->err.fn(sfd->err.obj, code);
		}
		if (sfd->stat > 0) {
			sfd->stat = -sfd->stat;
		}
	}
	return code;
}

// Installs the error callback (fn(obj, code)) library-wide (sfd NULL) or per handle; the MW player
// installs MWSFLIB_SfdErrFunc.
Sint32 SFD_SetErrFn(SFD sfd, void (*fn)(void *obj, Sint32 code), void *obj)
{
	if (sfd == NULL) {
		SFLIB_libwork.err.fn = fn;
		SFLIB_libwork.err.obj = obj;
	} else {
		if (SFLIB_CheckHn(sfd) != 0) {
			return sflib_SetErr(NULL, 0xFF000101);
		}
		sfd->err.fn = fn;
		sfd->err.obj = obj;
	}
	return 0;
}

// Error return helper used by every SFD_* API: reports `code` (0xFF00xxxx) unless it is 0 and
// returns it.
Sint32 SFLIB_SetErr(SFD sfd, Sint32 code)
{
	if (code == 0) {
		return 0;
	}
	return sflib_SetErr(sfd, code);
}

// Clears an error record.
void SFLIB_InitErrInf(SFLIB_ERRINF *err)
{
	err->fn = NULL;
	err->obj = NULL;
	err->code = 0;
	err->x0c = 0;
	err->x10 = 0;
}

// Passes a driver init result through (nonzero = error).
static Sint32 sflib_ChkRet(Sint32 r)
{
	Sint32 ret;

	ret = 0;
	if (r != 0) {
		ret = r;
	}
	return ret;
}

// Library init (from mwPlySfdInit): clears the library work, copies the default conditions, stores
// the driver table and the refresh rate (prm1, 1/1000 Hz), initialises timing, buffers, the drivers
// (each driver's Init), the player and the header analyser.
Sint32 SFD_Init(register SFD_INIT_PRM *prm)
{
	register Sint32 p1;
	register SFTRN_TRIF_TBL *tbl;
	Sint32 ret;
	Sint32 i;

	sflib_sizeof_sfdhn = SFD_VERSION;
	cri_verstr_ptr = SFLIB_version_str;
	SJRBF_Init();
	UTY_MemsetDword((Uint32 *)&SFLIB_libwork, 0, sizeof(SFLIB_libwork) / 4 - 1);
	MEM_Copy(&SFLIB_libwork, SFPLY_cond_dfl, sizeof(SFLIB_libwork.cond));
	/* The original loads prm1 (word 4) before trif_tbl (word 0) and stores trif_tbl first: both are
	 * own locals (p1 declared first = coloured first, r4/r5) loaded in statement order. p1 stays a
	 * variable because the trif_tbl store sits between its load and its use; tbl's only use is that
	 * first store, so the frontend would substitute the load into it (a backend temp above p1 -> r4).
	 * The cast `+ 0` redefinition is a second def the frontend keeps; the backend turns the
	 * `addi tbl, tbl, 0` into a self copy that the RA deletes. */
	p1 = prm->prm1;
	tbl = prm->trif_tbl;
	tbl = (SFTRN_TRIF_TBL *)((Uint32)tbl + 0);
	SFLIB_libwork.trif_tbl = tbl;
	SFLIB_libwork.prm1 = p1;
	SFLIB_libwork.x198 = 0;
	SFLIB_InitErrInf(&SFLIB_libwork.err);
	SFTIM_Init(SFLIB_libwork.tim);
	SFBUF_Init(&SFLIB_libwork.buf);
	SFLIB_libwork.x1fc = 0;
	SFLIB_libwork.x200 = 0;
	for (i = 0; i < 8; i++) {
		SFLIB_libwork.hn[i] = NULL;
	}
	ret = sflib_ChkRet(SFTRN_Init(&SFLIB_libwork.trif, prm->trif_tbl));
	if (ret != 0) {
		return ret;
	}
	SFPLY_Init();
	SFHDS_Init();
	return 0;
}

// Header/library version check: the caller's structure size must be this build's 0x3598.
Sint32 SFD_IsVersionCompatible(Sint32 a, Sint32 ver)
{
	return ver == SFD_VERSION;
}
