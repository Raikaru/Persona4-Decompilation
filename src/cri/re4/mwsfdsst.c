/* CRI Sofdec MW player side stream (mwsfdsst.c, MWSST): wrapper for a second audio stream decoded by
 * a separately registered core library (mwsstmng.ifc). No such library is registered in this game,
 * so every call is a guarded no-op; the player still embeds one MWSST_OBJ per handle. */
#include "cri_xpt.h"
#include "sj.h"
#include "mwsfd.h"

extern void SFD_SetElementOutSj(void *sfd, void *buf, SJ sj, Sint32 a, Sint32 b);

MWSST_MNG mwsstmng = {0};

/* every interface call is guarded: mwsstmng.ifc and the function pointer may be NULL */
#define MWSST_CALL(func, args) \
	if (mwsstmng.ifc != NULL && mwsstmng.ifc->func != NULL) { \
		mwsstmng.ifc->func args; \
	}

// A side stream exists only when a core library is registered and the object has a core handle.
static Bool mwsst_IsValid(MWSST sst)
{
	if (mwsstmng.ifc == NULL) {
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
static void mwsst_Stop(MWSST sst)
{
	MWSST hn;

	if (mwsst_IsValid(sst) == TRUE) {
		hn = sst->hn;
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
Sint32 MWSST_GetOutVol(MWSST sst)
{
	Sint32 vol = 0;
	MWSST hn;

	if (mwsst_IsValid(sst) != TRUE) {
		return 0;
	}
	hn = sst->hn;
	if (mwsstmng.ifc != NULL && mwsstmng.ifc->GetOutVol != NULL) {
		vol = mwsstmng.ifc->GetOutVol(hn);
	}
	return vol;
}

// Volume of the side stream.
void MWSST_SetOutVol(MWSST sst, Sint32 vol)
{
	MWSST hn;

	if (mwsst_IsValid(sst) == TRUE) {
		hn = sst->hn;
		MWSST_CALL(SetOutVol, (hn, vol));
	}
}

// Pause/resume of the side stream.
void MWSST_Pause(MWSST sst, Sint32 sw)
{
	MWSST hn;

	if (mwsst_IsValid(sst) == TRUE) {
		hn = sst->hn;
		MWSST_CALL(Pause, (hn, sw));
	}
}

// State of the side stream (0 without a core library).
Sint32 MWSST_GetStat(MWSST sst)
{
	Sint32 stat = 0;
	MWSST hn;

	if (mwsst_IsValid(sst) != TRUE) {
		return 0;
	}
	hn = sst->hn;
	if (mwsstmng.ifc != NULL && mwsstmng.ifc->GetStat != NULL) {
		stat = mwsstmng.ifc->GetStat(hn);
	}
	return stat;
}

// Stops the side stream.
void MWSST_Stop(MWSST sst)
{
	mwsst_Stop(sst);
}

// Starts the side stream on its ring buffer joint.
void MWSST_StartSj(MWSST sst)
{
	MWSST hn;
	SJ sj;

	if (mwsst_IsValid(sst) == TRUE) {
		hn = sst->hn;
		sj = sst->sj;
		MWSST_CALL(StartSj, (hn, sj));
	}
}
