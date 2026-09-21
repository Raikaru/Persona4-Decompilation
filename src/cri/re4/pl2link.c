#include "cri_xpt.h"

/* ADXT <-> Dolby Pro Logic II link. Every function of this unit was dead-stripped by the linker; only
 * the error strings of the stripped bodies survive in .rodata. */

typedef struct {
	Sint32 stat;
	Sint32 nch;
	Sint32 is3d;
	void *pl2;
} ADXT_PL2;

extern void ADXERR_CallErrFunc1(Char8 *msg);

// Dead: attach a Pro Logic II encoder to a 3D-sound ADXT handle.
Sint32 ADXT_AttachPl2_3D(ADXT_PL2 *adxt, void *pl2)
{
	if (adxt == NULL || pl2 == NULL) {
		ADXERR_CallErrFunc1("E2003091605 : NULL pointer is specified.");
		return -1;
	}
	if (adxt->is3d == 0) {
		ADXERR_CallErrFunc1("E2003091606 : ADXT handle must be created for 3D sound.");
		return -1;
	}
	adxt->pl2 = pl2;
	return 0;
}

// Dead: attach a Pro Logic II encoder to a stereo ADXT handle.
Sint32 ADXT_AttachPl2(ADXT_PL2 *adxt, void *pl2)
{
	if (adxt->nch != 2) {
		ADXERR_CallErrFunc1("E2003091101 : ADXT handle must be created for stereo output.");
		return -1;
	}
	if (pl2 == NULL) {
		ADXERR_CallErrFunc1("E2003091002 : Fail to attach Dolby Pro Logic II.");
		return -1;
	}
	adxt->pl2 = pl2;
	return 0;
}
