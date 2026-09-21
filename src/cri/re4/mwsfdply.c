/* CRI Sofdec MW player start / stop / pause (mwsfdply.c): the MWPLY_IF entries behind mwPlyStartFname
 * / StartSj / StartMem / Stop / Pause. A start stops the previous play, resets the SFD handle
 * (MWSFCRE_ResetSfdHn), puts it in standby, records the source and lets the decode server
 * (mwSfdExecDecSvrHndl) open the stream and start decoding on the next pass. */
#include "cri_xpt.h"
#include "mwsfd.h"
#include <string.h>
#include <stdio.h>

extern Sint32 MWSTM_GetStat(void *stm);
extern void MWSTM_ReqStop(void *stm);
extern void LSC_Stop(void *lsc);
extern Sint32 SFD_TermSupply(void *sfd);
extern Sint32 SFD_Stop(void *sfd);
extern Sint32 SFD_Standby(void *sfd);
extern Sint32 SFD_Start(void *sfd);
extern Sint32 SFD_Pause(void *sfd, Sint32 sw);
extern Sint32 SFD_GetCond(void *sfd, Sint32 id, Sint32 *val);
extern Sint32 SFD_GetPaStat(void *sfd);
extern Sint32 MWSFD_GetPauseBdr(void);
extern void MWSFD_SetFlowLimit(MWPLY mwply, Sint32 min_nsct, Sint32 max_nsct);
extern void mwlSfdSleepDecSvr(MWPLY mwply);
extern void mwPlyLinkStm(MWPLY mwply, Sint32 sw);
extern Sint32 MWSFCRE_ResetSfdHn(MWPLY mwply);
extern void MWSFCRE_SetSupplySj(MWPLY mwply);
extern void MWSFTAG_ResetAinfSj(MWPLY mwply);
extern Sint32 MWSFTAG_SetAinfSj(MWPLY mwply);
extern void MWSFTAG_InitTagInf(MWPLY mwply);
extern void MWSFFRM_InitSfhInfTable(MWPLY mwply);
extern void MWSFSEE_StartFnameSub1(MWPLY mwply, Sint32 ofst, Sint32 nsct);
extern void MWSFSEE_StartFnameSub2(MWPLY mwply, Sint32 ofst, Sint32 nsct);
extern Sint32 ADXF_GetFnameRangeEx(const Char8 *fname, Sint32 *ofst, Sint32 *nsct);

void mwSfdStartFnameSub(MWPLY mwply, const Char8 *fname, Sint32 ofst, Sint32 nsct);

/* copy the file name into the handle (clipped to the handle's buffer). Macros rather than static
 * helpers for the shared blocks: the .rodata string order is the order of first use inside the
 * public functions (a helper compiled at its definition would emit its strings there). */
#define MWSFD_SET_FNAME(mwply, fname) \
	if ((Sint32)strlen(fname) > (mwply)->x1bc) { \
		MWSFSVM_Error("E211121: filename is longer."); \
		strncpy((Char8 *)(mwply)->fname, fname, (mwply)->x1bc); \
	} else { \
		strcpy((Char8 *)(mwply)->fname, fname); \
	}

/* stop the decoder side of the handle */
#define MWSFD_STOP_SFD(mwply) \
	{ \
		void *sfd = (mwply)->sfd; \
		if (sfd != NULL) { \
			mwlSfdSleepDecSvr(mwply); \
			(mwply)->stat = MWSFD_STAT_STOP; \
			if (SFD_Stop(sfd) != 0) { \
				MWSFLIB_SetErrCode(-0x134); \
				MWSFSVM_Error("E2003 mwSfdStop:can't stop SFD"); \
			} \
			MWSST_Stop(&(mwply)->sst); \
			(mwply)->x2b4 = 0; \
			if ((mwply)->stm != NULL) { \
				MWSTM_ReqStop((mwply)->stm); \
			} \
			LSC_Stop((mwply)->lsc); \
		} \
	}

/* re-create the decoder handle for a new play and put it into standby; `end` is the label after
 * the block */
#define MWSFD_STANDBY(mwply, end) \
	{ \
		Sint32 pause; \
		MWSFLIB_GetLibWorkPtr(); \
		if ((mwply)->sfd != NULL) { \
			if (MWSFCRE_ResetSfdHn(mwply) != 0) { \
				MWSFSVM_Error("E0203263: mw_sfd_start_ex: RESET failed."); \
				goto end; \
			} \
			MWSST_Reset(mwply); \
			MWSFTAG_ResetAinfSj(mwply); \
			if (MWSFTAG_SetAinfSj(mwply) != 0) { \
				MWSFSVM_Error("E201213 mw_sfd_start_ex: can't set AddInfSJ"); \
				goto end; \
			} \
			MWSFTAG_InitTagInf(mwply); \
			MWSFFRM_InitSfhInfTable(mwply); \
		} \
		(mwply)->ngetfrm = 0; \
		(mwply)->nrelfrm = 0; \
		if (SFD_Standby((mwply)->sfd) != 0) { \
			MWSFLIB_SetErrCode(-0x137); \
			MWSFSVM_Error("E20010703F mwPlySfdStandby: "); \
		} \
		pause = (mwply)->pause_flg; \
		mwSfdPause(mwply, pause); \
		MWSST_Pause(&(mwply)->sst, 1); \
		MWSST_StartSj(&(mwply)->sst); \
		(mwply)->nskipdisp = 0; \
		(mwply)->linkstm_req = 0; \
		(mwply)->stat = MWSFD_STAT_PREP; \
	}

void mwSfdPause(MWPLY mwply, Sint32 sw);

/* dead: play a range of a file given as "%08x.%08x" */
void mwPlyStartFnameRange(MWPLY mwply, const Char8 *fname, Sint32 ofst, Sint32 nsct)
{
	Char8 buf[32];

	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E407021: mwPlyStartFnameRange: handle is invalid.");
		return;
	}
	if (fname == NULL) {
		MWSFSVM_Error("E407022: mwPlyStartFnameRange: fname is NULL.");
		return;
	}
	MWSFD_SET_FNAME(mwply, fname);
	sprintf(buf, "%08x.%08x", ofst, nsct);
	if (ADXF_GetFnameRangeEx(buf, &ofst, &nsct) < 0) {
		MWSFSVM_Error("E211151: ADXF_GetFnameRangeEx() faild.");
		return;
	}
	mwSfdStartFnameSub(mwply, fname, ofst, nsct);
}

/* the file stream reached its end: tell the decoder no more data comes */
void mwPlyChkSupply(MWPLY mwply)
{
	void *sfd = mwply->sfd;

	if (mwply->stm != NULL) {
		if (MWSTM_GetStat(mwply->stm) == 3) {
			SFD_TermSupply(sfd);
		}
	}
}

/* the stream flow limits: 80% of the handle's sector count as the minimum, all of it as the maximum */
void MWSFPLY_SetFlowLimit(MWPLY mwply)
{
	Sint32 n = mwply->flow_nsct;

	MWSFD_SetFlowLimit(mwply, (Sint32)(0.8 * n), n);
}

/* dead */
void mwPlyStartAfs(MWPLY mwply, Sint32 patid, Sint32 fid)
{
	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122638: mwPlyStartAfs: handle is invalid.");
		return;
	}
}

// MWPLY_IF.Pause (mwPlyPause): pauses/resumes the SFD decoder and the audio side stream; when the
// pause border is on and the file has audio, first waits for the decode server to reach its border.
void mwSfdPause(MWPLY mwply, Sint32 sw)
{
	void *sfd;
	Sint32 val;

	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122604 mwSfdPause; handle is invalid.");
		return;
	}
	sfd = mwply->sfd;
	if (mwply->pause_flg == 0 && sw == 0) {
		return;
	}
	if (MWSFD_GetPauseBdr() == 1 && mwply->prm.mode == 1) {
		if (SFD_GetCond(sfd, 6, &val) == 0) {
			if (val == 1) {
				mwlSfdSleepDecSvr(mwply);
			}
		} else {
			mwlSfdSleepDecSvr(mwply);
		}
	}
	if (SFD_Pause(sfd, sw) != 0) {
		MWSFLIB_SetErrCode(-0x136);
		MWSFSVM_Error("E2007 mwSfdPause; can't pause (%s)", (sw == 1) ? "ON" : "OFF");
	}
	MWSST_Pause(&mwply->sst, sw);
	mwply->pause_flg = sw;
}

// MWPLY_IF.Stop (mwPlyStop): stops the decoder, ends any linked play, stops the load scheduler.
void mwSfdStop(MWPLY mwply)
{
	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122602 mwSfdStop: handle is invalid.");
		return;
	}
	MWSFD_STOP_SFD(mwply);
	mwPlyLinkStm(mwply, 0);
	mwply->x78 = 0;
	LSC_Stop(mwply->lsc);
}

// Stops only the decoder side (used by mwSfdDestroy).
void mwSfdStopDec(MWPLY mwply)
{
	MWSFD_STOP_SFD(mwply);
}

// MWPLY_IF.StartSj: play from a caller-supplied stream joint; stops, puts the SFD in standby and
// points the decoder input at the joint.
void mwSfdStartSj(MWPLY mwply, SJ sj)
{
	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122609 mwSfdStartSj: handle is invalid.");
		return;
	}
	MWSFD_STOP_SFD(mwply);
	mwply->sji = sj;
	mwply->x1e4 = 2;
	mwply->x1e8 = 0;
	mwply->x1ec = 0;
	mwply->x1f0 = 0;
	MWSFD_STANDBY(mwply, standby_end);
standby_end:
	MWSFCRE_SetSupplySj(mwply);
}

// MWPLY_IF.StartMem: play from a memory buffer through a fresh memory joint.
void mwSfdStartMem(MWPLY mwply, void *buf, Sint32 size)
{
	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122610 mwSfdStartMem: handle is invalid.");
		return;
	}
	MWSFD_STOP_SFD(mwply);
	SJ_Destroy(mwply->mem_sj);
	mwply->mem_sj = SJMEM_Create(buf, size);
	mwply->sji = mwply->mem_sj;
	mwply->mem_buf = buf;
	mwply->mem_size = size;
	MWSFD_STANDBY(mwply, standby_end);
standby_end:
	MWSFCRE_SetSupplySj(mwply);
}

// File start: stops, standby, copies the file name into the handle, whole file (0xFFFFF sectors)
// from sector 0, and asks the decode server to start the stream controller (stm_start_req).
void mwSfdStartFnameSub(MWPLY mwply, const Char8 *fname, Sint32 ofst, Sint32 nsct)
{
	mwply->sji = mwply->file_sj;
	MWSFD_STOP_SFD(mwply);
	MWSFD_STANDBY(mwply, standby_end);
standby_end:
	MWSFD_SET_FNAME(mwply, fname);
	mwply->dir = NULL;
	mwply->ofst = 0;
	mwply->nsct = 0xFFFFF;
	mwply->stm_start_req = 1;
	MWSFSEE_StartFnameSub1(mwply, ofst, nsct);
	MWSFSEE_StartFnameSub2(mwply, ofst, nsct);
}

// MWPLY_IF.StartFname (mwPlyStartFname, what the game calls with the movie path).
void mwSfdStartFname(MWPLY mwply, const Char8 *fname)
{
	if (MWSFD_IsEnableHndl(mwply) == 0) {
		MWSFSVM_Error("E1122601: mwPlyStartFname: handle is invalid.");
		return;
	}
	if (fname == NULL) {
		MWSFSVM_Error("E10915C: mwPlyStartFname: fname is NULL.");
		return;
	}
	mwSfdStartFnameSub(mwply, fname, 0, -1);
}

/* dead */
Sint32 mwPlySfdGetPaStat(MWPLY mwply)
{
	Sint32 stat = SFD_GetPaStat(mwply->sfd);

	switch (stat) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		MWSFSVM_Error("E10821A : Invalid value of SFD_GetPaStat : %d", stat);
		break;
	}
	return 0;
}

// Starts the SFD decoder once it is in standby (called by the decode server); error -0x133 on failure.
Sint32 mwPlySfdStart(MWPLY mwply)
{
	if (SFD_Start(mwply->sfd) != 0) {
		MWSFLIB_SetErrCode(-0x133);
		MWSFSVM_Error("E20010703G mwPlySfdStart: ");
		return -0x133;
	}
	return 0;
}
