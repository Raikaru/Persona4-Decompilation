/* CRI Sofdec MW player side stream (mwsfdsst.c, MWSST): wrapper for a second audio stream decoded by
 * a separately registered core library (mwsstmng.ifc). No such library is registered in this game,
 * so every call is a guarded no-op; the player still embeds one MWSST_OBJ per handle. */
#include "cri_xpt.h"
#include "sj.h"
#include "mwsfd.h"

extern void SFD_SetElementOutSj(void *sfd, void *buf, SJ sj, Sint32 a, Sint32 b);
extern MWSST_IF *func_00510e40(void);

MWSST_MNG mwsstmng = {0};

/* Read the registered interface through the library's shared accessor. */
#define MWSST_CALL(func, args) \
	do { \
		MWSST_IF *ifc = func_00510e40(); \
		MWSST hn = sst->hn; \
		if (ifc != NULL && ifc->func != NULL) { \
			ifc->func args; \
		} \
	} while (0)

// A side stream exists only when a core library is registered and the object has a core handle.
// FUN_00510E60
static Bool mwsst_IsValid(MWSST sst)
{
	if (func_00510e40() == NULL) {
		return FALSE;
	}
	if (sst->used != 1) {
		return FALSE;
	}
	if (sst->hn == NULL) {
		return FALSE;
	}
	return TRUE;
}

// Stops the core handle.
// FUN_00510968
static void mwsst_Stop(MWSST sst)
{
	if (mwsst_IsValid(sst) == TRUE) {
		MWSST_CALL(Stop, (hn));
	}
}

// Destroys the core handle.
static void mwsst_DestroyHn(MWSST hn)
{
	MWSST_IF *ifc;

	ifc = mwsstmng.ifc;
	if (hn != NULL && ifc != NULL && ifc->Destroy != NULL) {
		ifc->Destroy(hn);
	}
}

// Drops a reference on the core library, finishing it with the last one.
static void mwsst_ReleaseLib(void)
{
	MWSST_IF *ifc;

	ifc = mwsstmng.ifc;
	if (ifc != NULL && mwsstmng.cnt != 0) {
		mwsstmng.cnt--;
		if (mwsstmng.cnt == 0 && ifc->Finish != NULL) {
			ifc->Finish();
		}
	}
}

// Builds a side-stream object in `work` (ring buffer after the first 0xC0 bytes) over the core
// library's handle. Unused in this game (no side-stream library is registered: mwsstmng.ifc NULL).
MWSST MWSST_Create(void *work, Sint32 wksize, MWSST_IF *ifc)
{
	MWSST sst;

	if (wksize < 0x100) {
		MWSFSVM_Error("E303111: MWSST_Create: worksize is short.");
		return NULL;
	}
	sst = work;
	sst->sj = SJRBF_Create((Uint8 *)work + 0xC0, wksize - 0xC0, 0);
	if (sst->sj == NULL) {
		MWSFSVM_Error("E303112: MWSST_Create: can't create SJ.");
		return NULL;
	}
	sst->hn = ifc->x0c;
	if (sst->hn == NULL) {
		MWSFSVM_Error("E303112: MWSST_Create: can't create corehn.");
		return NULL;
	}
	sst->used = 1;
	return sst;
}

// Stops and destroys the side stream at the idle border.
void MWSST_Destroy(MWSST sst)
{
	MWSST hn;
	SJ sj;

	if (mwsst_IsValid(sst) == TRUE) {
		hn = sst->hn;
		sj = sst->sj;
		if (hn != NULL) {
			MWSFSVM_GotoIdleBorder();
			mwsst_Stop(hn);
			sst->used = 0;
			mwsst_DestroyHn(hn);
			SJ_Destroy(sj);
			sst->hn = NULL;
			mwsst_ReleaseLib();
		}
	}
}

// Resets the ring and re-registers it as the SFD element output for the side stream.
void MWSST_Reset(MWPLY mwply)
{
	void *sfd;
	MWSST sst;
	MWSST hn;
	SJ sj;
	void *buf;

	sfd = mwply->sfd;
	sst = &mwply->sst;
	hn = sst->hn;
	sj = sst->sj;
	buf = sst->buf;
	if (mwsst_IsValid(sst) == TRUE) {
		if (hn != NULL) {
			mwsst_Stop(hn);
		}
		SJ_Reset(sj);
		SFD_SetElementOutSj(sfd, (Uint8 *)buf + 0xC0, sj, 0, 0);
	}
}

// Volume of the side stream (0 without a core library).
// FUN_005109C0
Sint32 MWSST_GetOutVol(MWSST sst)
{
	Sint32 vol = 0;
	MWSST hn;
	MWSST_IF *ifc;

	if (mwsst_IsValid(sst) != TRUE) {
		return 0;
	}
	ifc = func_00510e40();
	hn = sst->hn;
	if (ifc != NULL && ifc->GetOutVol != NULL) {
		vol = ifc->GetOutVol(hn);
	}
	return vol;
}

// Volume of the side stream.
// FUN_00510AF8
void MWSST_SetOutVol(MWSST sst, Sint32 vol)
{
	if (mwsst_IsValid(sst) == TRUE) {
		MWSST_CALL(SetOutVol, (hn, vol));
	}
}

// Pause/resume of the side stream.
// FUN_00510A98
void MWSST_Pause(MWSST sst, Sint32 sw)
{
	if (mwsst_IsValid(sst) == TRUE) {
		MWSST_CALL(Pause, (hn, sw));
	}
}

// State of the side stream (0 without a core library).
// FUN_00510B58
Sint32 MWSST_GetStat(MWSST sst)
{
	Sint32 stat = 0;
	MWSST hn;
	MWSST_IF *ifc;

	if (mwsst_IsValid(sst) != TRUE) {
		return 0;
	}
	ifc = func_00510e40();
	hn = sst->hn;
	if (ifc != NULL && ifc->GetStat != NULL) {
		stat = ifc->GetStat(hn);
	}
	return stat;
}

// Stops the side stream.
void MWSST_Stop(MWSST sst)
{
	mwsst_Stop(sst);
}

// Starts the side stream on its ring buffer joint.
// FUN_00510910
void MWSST_StartSj(MWSST sst)
{
	if (mwsst_IsValid(sst) == TRUE) {
		MWSST_IF *ifc = func_00510e40();
		MWSST hn = sst->hn;
		SJ sj = sst->sj;
		if (ifc != NULL && ifc->StartSj != NULL) {
			ifc->StartSj(hn, sj);
		}
	}
}
