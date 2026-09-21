/* CRI Sofdec MW player servers (mwsfdsvr.c): the decode server (MWSFSVR_DecodeServer -> SFD_ExecOne
 * per handle + the player state machine mwSfdExecDecSvrHndl: PREP starts the stream/decoder,
 * PLAYING watches for the end and stream errors), the vsync tick (mwSfdVsync -> SFD_VbIn) and the
 * three SVM thread entry points. In this game there are no CRI threads, so MWSFSVR_MainThrdProc
 * runs the vsync tick and the decode server from the game's ADXM_ExecMain() every frame. */
#include "cri_xpt.h"
#include "sj.h"
#include "mwsfd.h"
#include "adx_stm.h"

extern void mwPlySaveRsc(void);
extern void mwPlyRestoreRsc(void);
extern void ADXM_WaitVsync(void);
extern Sint32 ADXM_IsSetupThrd(void);
extern void SFD_ExecOne(void *sfd);
extern Sint32 SFD_IsHnSvrWait(void *sfd);
extern Sint32 SFD_IsSvrWait(void);
extern void SFD_VbIn(void);
extern Sint32 SFD_GetHnStat(void *sfd);
extern Sint32 SFD_SetConcatPlay(void *sfd);
extern Sint32 SFD_TermSupply(void *sfd);
extern Sint32 MWSTM_GetStat(ADXSTM stm);
extern void MWSTM_SetFileRange(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
extern Sint32 MWSTM_ReqStart(ADXSTM stm);
extern Sint32 MWSTM_IsFsStatErr(ADXSTM stm);
extern Sint32 MWSFLSC_IsFsStatErr(void *lsc);
extern Sint32 LSC_GetNumStm(void *lsc);
extern void MWSFCRE_SetSupplySj(MWPLY mwply);
extern void mwPlySfdStart(MWPLY mwply);
extern void mwSfdPause(MWPLY mwply, Sint32 sw);
extern void mwPlyChkSupply(void);
extern void MWSFSFX_DecideCompoMode(MWPLY mwply);
extern void MWSFSEE_ChkSupply(MWPLY mwply);

static Sint32 mwg_field_no = 0;
Sint32 mwg_vcnt = 0;
MWPLY mwsfd_hn_last = NULL;
static Sint32 mwsfd_svr_bdr_cnt = 0;

Sint32 mwSfdExecDecSvrHndl(void *obj);

/* dead-stripped; its string heads the unit's literal pool */

Bool MWSFSVR_IsSvrBdrHndl(MWPLY mwply)
{
	if (mwply == NULL || mwply->used != 1) {
		MWSFSVM_Error("E2011101: MWSFSVR_IsSvrBdrHndl: handle is invalid.");
		return FALSE;
	}
	mwsfd_svr_bdr_cnt++;
	return mwply->sleep_bdr == 1;
}

// Marks the handle (and the library) as sleeping at the server border.
static void mwsfd_SetSleepBdr(MWPLY mwply, Sint32 sw)
{
	MWSFD_LIBWORK *lw;

	lw = MWSFLIB_GetLibWorkPtr();
	mwply->sleep_bdr = sw;
	lw->svr_bdr = sw;
}

// Clears the sleep-at-border marks.
static void mwsfd_ClrSleepBdr(MWPLY mwply)
{
	MWSFD_LIBWORK *lw;

	lw = MWSFLIB_GetLibWorkPtr();
	mwply->sleep_bdr = 0;
	lw->svr_bdr = 0;
}

/* the wait loop is its own (inlined) helper: its `i = 0` then shares the block with the hoisted
 * loop constants, so the two zero stores become copies of i's zero (`mr r30, r28; mr r31, r28`)
 * instead of one `li` (CRI pass 12) */
static void mwsfd_SleepLoop(MWPLY mwply)
{
	Sint32 i;

	for (i = 0; i < 10; i++) {
		mwsfd_SetSleepBdr(mwply, 1);
		ADXM_WaitVsync();
		mwsfd_ClrSleepBdr(mwply);
		if (mwply->mwply_svr_flg == 0) {
			break;
		}
	}
}

// Waits until the decode server is between passes before a stop/pause touches the decoder: goes to
// the SVM idle border and, if the handle server is still running, waits up to 10 vsyncs.
void mwlSfdSleepDecSvr(MWPLY mwply)
{
	mwPlySaveRsc();
	mwsfd_SetSleepBdr(mwply, 1);
	MWSFSVM_GotoIdleBorder();
	mwsfd_ClrSleepBdr(mwply);
	mwPlyRestoreRsc();
	if (mwply->mwply_svr_flg == 1) {
		mwsfd_SleepLoop(mwply);
	}
}

// "SFD_ExecOne running" flag of a handle.
void MWSFSVR_SetHnSfdSvrFlg(MWPLY mwply, Sint32 flg)
{
	mwply->sfd_svr_flg = flg;
}

// "handle server running" flag of a handle.
void MWSFSVR_SetHnMwplySvrFlg(MWPLY mwply, Sint32 flg)
{
	mwply->mwply_svr_flg = flg;
}

// "decode server running" flag of the library.
// FUN_00511D78
void MWSFSVR_SetMwsfdSvrFlg(Sint32 flg)
{
	MWSFD_LIBWORK *lw;

	lw = MWSFLIB_GetLibWorkPtr();
	lw->svr_flg = flg;
}

/* OPEN: our 2.4.7 auto-inlines this 0xB8-byte helper and MWSFSVR_DecodeServer, the original did not */
/* COMPILER-DIFF: M3 - the original did not inline this helper while inlining smaller ones (auto-inlining decision). Pure C by project decision (CRI pass 8). */
static Sint32 mwsfd_ExecSvrHndl(void *obj)
{
	/* the handle arrives as a server object: the `void *` -> MWPLY conversion keeps the copy as its
	 * own node (a plain `p = mwply` is propagated away), which ranks mwply above sfd (CRI pass 12) */
	MWPLY mwply;
	void *sfd;

	mwply = obj;
	sfd = mwply->sfd;
	mwply->mwply_svr_flg = 1;
	if (mwply->used != 1) {
		mwply->mwply_svr_flg = 0;
		return 0;
	}
	mwsfd_hn_last = mwply;
	mwply->sfd_svr_flg = 1;
	SFD_ExecOne(sfd);
	mwply->sfd_svr_flg = 0;
	if (mwply->stat == MWSFD_STAT_STOP) {
		mwply->dec_svr_flg = 0;
	} else {
		mwply->dec_svr_flg = 1;
		mwSfdExecDecSvrHndl(mwply);
	}
	mwply->mwply_svr_flg = 0;
	return SFD_IsHnSvrWait(sfd) != 1;
}

// MWPLY_IF.ExecSvrHndl: one decode-server step of a handle unless the library is not initialised,
// the handle is unused, already running, or a handle sleeps at the border.
Sint32 mwSfdExecSvrHndl(MWPLY mwply)
{
	MWSFD_LIBWORK *lw;

	if (mwsfd_init_flag != 1) {
		return 0;
	}
	if (mwply == NULL) {
		MWSFSVM_Error("E1071901 mwPlyExecSvrHndl: NULL handle.");
		return 0;
	}
	if (mwply->used != 1) {
		return 0;
	}
	if (mwply->mwply_svr_flg == 1) {
		return 0;
	}
	lw = MWSFLIB_GetLibWorkPtr();
	if (lw->svr_bdr == 1) {
		return 0;
	}
	return mwsfd_ExecSvrHndl(mwply);
}

// The Sofdec decode server pass: pre hook, mwSfdExecSvrHndl on all 8 handles (SFD_ExecOne = demux +
// video decode + audio feed, then the player state machine), post hook, and the idle hook when no
// handle is waiting for more time. Returns 1 while a handle still has work.
Sint32 MWSFSVR_DecodeServer(void *obj)
{
	MWSFD_LIBWORK *lw;
	MWSFD_LIBWORK *lw2;
	Sint32 i;
	Sint32 wait;
	MWPLY mwply;
	Sint32 (*func)(void *obj);
	void *fobj;

	if (mwsfd_init_flag != 1) {
		return 0;
	}
	lw = MWSFLIB_GetLibWorkPtr();
	if (MWSFSVM_TestAndSet(&lw->svr_flg) == 0) {
		return 0;
	}
	lw2 = MWSFLIB_GetLibWorkPtr();
	func = lw2->pre_func;
	fobj = lw2->pre_obj;
	if (func != NULL) {
		func(fobj);
	}
	for (i = 0; i < MWSFD_MAX_HN; i++) {
		mwply = &lw->hn[i];
		if (mwply != NULL) {
			mwSfdExecSvrHndl(mwply);
		}
	}
	lw2 = MWSFLIB_GetLibWorkPtr();
	lw2->svr_flg = 0;
	wait = SFD_IsSvrWait() != 1;
	lw2 = MWSFLIB_GetLibWorkPtr();
	func = lw2->post_func;
	fobj = lw2->post_obj;
	if (func != NULL) {
		func(fobj);
	}
	if (wait == 0) {
		lw2 = MWSFLIB_GetLibWorkPtr();
		if (lw2->svr_bdr != 1) {
			lw2 = MWSFLIB_GetLibWorkPtr();
			func = lw2->idle_func;
			fobj = lw2->idle_obj;
			if (func != NULL) {
				func(fobj);
			}
		}
	}
	return wait;
}

// Vsync tick: counts fields/vsyncs (mwg_vcnt) and advances the SFD clock (SFD_VbIn).
void mwSfdVsync(void)
{
	MWSFD_LIBWORK *lw;

	mwg_field_no++;
	mwg_vcnt++;
	if (mwsfd_init_flag != 1) {
		return;
	}
	lw = MWSFLIB_GetLibWorkPtr();
	if (MWSFSVM_TestAndSet(&lw->x5c) == 0) {
		return;
	}
	if (mwsfd_init_flag == 1) {
		SFD_VbIn();
	}
	lw->x5c = 0;
}

// SVM idle-type callback (threaded setups only): the decode server on the idle thread.
Sint32 MWSFSVR_IdleThrdProc(void *obj)
{
	Sint32 ret = 0;
	MWSFD_LIBWORK *lw;

	if (ADXM_IsSetupThrd() == 1) {
		lw = MWSFLIB_GetLibWorkPtr();
		if (lw->x10 != 1) {
			ret = MWSFSVR_DecodeServer(obj);
		}
	}
	return ret;
}

// SVM main-type callback: in this game (no threads) it runs mwSfdVsync and the decode server, i.e.
// one vsync + decode pass per ADXM_ExecMain() call from the game loop.
Sint32 MWSFSVR_MainThrdProc(void *obj)
{
	Sint32 ret = 0;
	MWSFD_LIBWORK *lw;

	if (ADXM_IsSetupThrd() == 1) {
		lw = MWSFLIB_GetLibWorkPtr();
		if (lw->x10 == 1) {
			ret = MWSFSVR_DecodeServer(obj);
		}
	} else {
		mwSfdVsync();
		ret = MWSFSVR_DecodeServer(obj);
	}
	return ret;
}

// SVM vsync-type callback (threaded setups only).
Sint32 MWSFSVR_VsyncThrdProc(void *obj)
{
	if (ADXM_IsSetupThrd() == 1) {
		mwSfdVsync();
		return 0;
	}
	return 0;
}

// Starts the file stream controller on the handle's file range (name, device, ofst, nsct) and points
// the decoder input at the file joint; -1 if the controller is still running or refuses.
static Sint32 mwsfd_StartStm(MWPLY mwply)
{
	if (MWSTM_GetStat(mwply->stm) == ADXSTM_STAT_EXEC) {
		return -1;
	}
	if (mwply->sji != NULL) {
		SJ_Reset(mwply->sji);
	}
	MWSTM_SetFileRange(mwply->stm, mwply->fname, mwply->dir, mwply->ofst, mwply->nsct);
	if (MWSTM_ReqStart(mwply->stm) == -1) {
		mwply->stat = MWSFD_STAT_ERROR;
		MWSFLIB_SetErrCode(-102);
		MWSFSVM_Error("E211141 MWSTM_ReqStart: can't start '%s'", mwply->fname);
		mwply->stm_start_req = 0;
		return -1;
	}
	MWSFCRE_SetSupplySj(mwply);
	return 1;
}

// Starts the SFD decoder, releases the pause if none is requested and enables concatenated play for
// a linked stream.
static void mwsfd_StartPlay(MWPLY mwply)
{
	mwPlySfdStart(mwply);
	if (mwply->pause_flg == 0) {
		mwSfdPause(mwply, 0);
	}
	if (mwply->linkstm == 1) {
		if (SFD_SetConcatPlay(mwply->sfd) != 0) {
			MWSFSVM_Error("E99072103 mwPlyStartXX: can't link stream");
		}
	}
}

/* COMPILER-DIFF: M1 - the pool base `lis r4` above the prologue stores. Pure C by project decision (CRI pass 8). */
Sint32 mwSfdExecDecSvrHndl(void *obj)
{
	/* one function-scope `sfd` (its PLAYING redefinition is a range-split frontend copy ranked above
	 * the backend temporaries -> r28) and the handle converted from the `void *` server object (the
	 * kept copy schedules the pool `lis` above the parameter move; CRI pass 12) */
	void *sfd;
	MWPLY mwply;

	mwply = obj;
	switch (mwply->stat) {
	case MWSFD_STAT_STOP:
		break;
	case MWSFD_STAT_PREP: {
		Sint32 sfdstat;
		Sint32 sststat;
		MWSST sst;

		sfd = mwply->sfd;
		if (mwply->stm_start_req == 1) {
			if (mwsfd_StartStm(mwply) == 1) {
				mwply->stm_start_req = 0;
			}
		}
		if (mwply->sst.used == 1) {
			sst = &mwply->sst;
			sfdstat = SFD_GetHnStat(mwply->sfd);
			sststat = MWSST_GetStat(sst);
			if (sfdstat == 3 && (sststat == 2 || SJ_GetNumData(sst->sj, SJ_CK_DATA) == 0)) {
				mwsfd_StartPlay(mwply);
				if (mwply->pause_flg == 0) {
					MWSST_Pause(sst, 0);
				}
			}
		} else {
			if (SFD_GetHnStat(mwply->sfd) == 3) {
				mwsfd_StartPlay(mwply);
			}
		}
		sfdstat = SFD_GetHnStat(sfd);
		if (sfdstat == 4 || sfdstat == 6) {
			mwply->stat = MWSFD_STAT_PLAYING;
			MWSFSFX_DecideCompoMode(mwply);
		}
		break;
	}
	case MWSFD_STAT_PLAYING: {
		sfd = mwply->sfd;
		if (mwply->linkstm_req == 1) {
			if (LSC_GetNumStm(mwply->lsc) == 0) {
				if (SFD_TermSupply(sfd) != 0) {
					MWSFSVM_Error("E99072102 mwlSfdExecDecSvrPlaying: can't term");
				}
				mwply->linkstm_req = 0;
			}
		} else {
			mwPlyChkSupply();
		}
		if (SFD_GetHnStat(sfd) == 6) {
			mwply->stat = MWSFD_STAT_PLAYEND;
		}
		break;
	}
	case MWSFD_STAT_PLAYEND:
		break;
	}
	if (mwply->stm != NULL && MWSTM_IsFsStatErr(mwply->stm) != 0) {
		mwply->stat = MWSFD_STAT_ERROR;
	}
	if (mwply->lsc != NULL && MWSFLSC_IsFsStatErr(mwply->lsc) == 1) {
		mwply->stat = MWSFD_STAT_ERROR;
	}
	MWSFSEE_ChkSupply(mwply);
	return 0;
}
