#include "mwsfd.h"
#include "sfd.h"

/* This unit is compiled with `-inline auto,deferred` (CRI_CFLAG_OVERRIDES): every accessor inlines
 * MWSFD_IsEnableHndl / mwPlyGetSfdHn / mwPlyGetNumSkipDec, which are defined at the top of the file,
 * and deferred code generation emits the functions in reverse source order (the DOL's .text and
 * string order). Most mwPly* accessors were dead-stripped by the linker; their bodies below only
 * reproduce the error strings and constants left in .rodata (STRIP_UNUSED). */

void *mwPlyGetSfdHn(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122640: mwPlyGetSfdHn: handle is invalid.");
		return NULL;
	}
	return mwply->sfd;
}

// Frames the decoder skipped (decoded pictures - displayed frames from SFD_GetPlyInf); shown by the
// game's movie debug display.
Sint32 mwPlyGetNumSkipDec(MWPLY mwply)
{
	SFD_PLYINF inf;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122619: mwPlyGetNumSkipDec: handle is invalid.");
		return 0;
	}
	SFD_GetPlyInf(mwPlyGetSfdHn(mwply), &inf);
	return inf.raw[1] - inf.raw[4];
}

// Sets an SFD condition on the player's decoder (NULL player: the library default).
void MWSFD_SetCond(MWPLY mwply, Sint32 id, Sint32 val)
{
	SFD_SetCond((mwply != NULL) ? mwply->sfd : NULL, id, val);
}

// Refill thresholds (sectors) of the stream controller and the load scheduler.
void MWSFD_SetFlowLimit(MWPLY mwply, Sint32 min_nsct, Sint32 max_nsct)
{
	MWSTM_SetFlowLimit(mwply->stm, min_nsct, max_nsct);
	MWSFLSC_SetFlowLimit(mwply, min_nsct);
}

// Non-NULL and in use.
Bool MWSFD_IsEnableHndl(MWPLY mwply)
{
	if (mwply == NULL) {
		return FALSE;
	}
	return mwply->used;
}

// Dead: audio on/off (cond 28).
void mwPlySetAudioSw(MWPLY mwply, Sint32 sw)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122617 mwPlySetAudioSw: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 28, sw);
}

// Dead: returns NULL (the ADXT handle is not exposed on this platform).
void *mwPlyGetAdxtHn(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122639: mwPlyGetAdxtHn: handle is invalid.");
		return NULL;
	}
	return NULL;
}

// Dead: allow skipping P pictures (cond 27).
void mwPlySetPpicSkip(MWPLY mwply, Sint32 sw)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122628: mwPlySetBpicSkip mwPlySetPpicSkip: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 27, sw);
}

// Dead: allow skipping B pictures (cond 26).
void mwPlySetBpicSkip(MWPLY mwply, Sint32 sw)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122628: mwPlySetBpicSkip mwPlySetPpicSkip: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 26, sw);
}

// Dead: select the audio stream (cond 25, < cond 24 streams).
void mwPlySetAudioCh(MWPLY mwply, Sint32 ch)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122616 mwPlySetAudioCh: handle is invalid.");
		return;
	}
	if (ch < 0 || ch >= SFSET_GetCond(mwply->sfd, 24)) {
		MWSFSVM_Error("E10911A mwPlySetAudioCh: Invalid ch no.");
		return;
	}
	SFD_SetCond(mwply->sfd, 25, ch);
}

// Dead: number of audio streams (cond 24).
Sint32 mwPlyGetNumAudioCh(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2080801 mwPlyGetNumAudioCh: handle is invalid.");
		return 0;
	}
	return SFSET_GetCond(mwply->sfd, 24);
}

// Dead: select the video stream (cond 23, < cond 22 streams).
void mwPlySetVideoCh(MWPLY mwply, Sint32 ch)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2080601 mwPlySetVideoCh: handle is invalid.");
		return;
	}
	if (ch < 0 || ch >= SFSET_GetCond(mwply->sfd, 22)) {
		MWSFSVM_Error("E2080602 mwPlySetVideoCh: Invalid ch no.");
		return;
	}
	SFD_SetCond(mwply->sfd, 23, ch);
}

// Dead: number of video streams (cond 22).
Sint32 mwPlyGetNumVideoCh(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2080802 mwPlyGetNumVideoCh: handle is invalid.");
		return 0;
	}
	return SFSET_GetCond(mwply->sfd, 22);
}

// Dead: decode time limit (cond 21).
void mwPlySetLimitTime(MWPLY mwply, Sint32 time)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122625: mwPlySetLimitTime: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 21, time);
}

// MWPLY_IF.GetStat (mwPlyGetStat): 0 stop, 1 prep, 2 playing, 3 playend, 4 error; while the player
// thinks it is playing the SFD state decides (4/6 playing, negative error, else still prep). The
// game ends the movie on 3 or 4.
Sint32 mwSfdGetStat(MWPLY mwply)
{
	Sint32 stat;
	Sint32 sfdstat;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFLIB_SetErrCode(-12);
		MWSFSVM_Error("W2004 mwSfdGetStat: handle is invalid");
		return MWSFD_STAT_STOP;
	}
	stat = mwply->stat;
	if (stat == MWSFD_STAT_PLAYING) {
		sfdstat = SFD_GetHnStat(mwply->sfd);
		if (sfdstat == 4 || sfdstat == 6) {
			return MWSFD_STAT_PLAYING;
		}
		if (sfdstat < 0) {
			return MWSFD_STAT_ERROR;
		}
		return MWSFD_STAT_PREP;
	}
	return stat;
}

// Dead: sync mode (cond 9: 0 none, 1 audio, 2 vsync).
void mwPlySetSyncMode(MWPLY mwply, Sint32 mode)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122626: mwPlySetSyncMode: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 9, mode);
}

// Dead: current sync mode.
Sint32 mwPlyGetSyncMode(MWPLY mwply)
{
	Sint32 mode;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E2010802: mwPlyGetSyncMode: handle is invalid.");
		return 0;
	}
	mode = SFSET_GetCond(mwply->sfd, 9);
	if (mode < 0 || mode > 2) {
		MWSFSVM_Error("E2010803: mwPlyGetSyncMode: mode is invalid.");
		return 0;
	}
	return mode;
}

// Dead: not supported (error).
Sint32 mwPlyGetNumDecPool(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122621: mwPlyGetNumDecPool: handle is invalid.");
		return 0;
	}
	MWSFSVM_Error("E1121601 mwPlyGetNumDecPool");
	return 0;
}

// Dead: total decoded pictures.
Sint32 mwPlyGetNumTotalDec(MWPLY mwply)
{
	SFD_PLYINF inf;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122620: mwPlyGetNumTotalDec: handle is invalid.");
		return 0;
	}
	SFD_GetPlyInf(mwply->sfd, &inf);
	return inf.raw[1];
}

// MWPLY_IF.GetTime (mwPlyGetTime): playback time as count/scale from the SFD clock (audio-slaved
// when there is audio); the game shows it as hh:mm:ss.ff.
void mwSfdGetTime(MWPLY mwply, Sint32 *ncount, Sint32 *tscale)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122603 mwSfdGetTime; handle is invalid.");
		*ncount = 0;
		*tscale = 1;
		return;
	}
	if (SFD_GetTime(mwply->sfd, ncount, tscale) != 0) {
		MWSFLIB_SetErrCode(-0x135);
		MWSFSVM_Error("E2006 mwSfdGetTime; can't get time");
		*ncount = 0;
		*tscale = 1;
	}
	if (*ncount < 0) {
		*ncount = 0;
		*tscale = 1;
	}
}

// MWPLY_IF.SetOutVol: audio volume (1/10 dB) to the main and side audio streams.
void mwSfdSetOutVol(MWPLY mwply, Sint32 vol)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122605 mwSfdSetOutVol: handle is invalid.");
		return;
	}
	MWSFRNA_SetOutVol(mwply, vol);
	MWSST_SetOutVol(&mwply->sst, vol);
}

// MWPLY_IF.GetOutVol.
Sint32 mwSfdGetOutVol(MWPLY mwply)
{
	Sint32 vol;
	Sint32 sstvol;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122606 mwSfdGetOutVol: handle is invalid.");
		return 0;
	}
	vol = MWSFRNA_GetOutVol(mwply);
	sstvol = MWSST_GetOutVol(&mwply->sst);
	if (vol == sstvol) {
		return vol;
	}
	if (vol != 0) {
		return vol;
	}
	return sstvol;
}

// MWPLY_IF.SetOutPan: channel pan.
void mwSfdSetOutPan(MWPLY mwply, Sint32 ch, Sint32 pan)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122607 mwSfdSetOutPan: handle is invalid.");
		return;
	}
	MWSFRNA_SetOutPan(mwply, ch, pan);
}

// MWPLY_IF.GetOutPan.
Sint32 mwSfdGetOutPan(MWPLY mwply, Sint32 ch)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122608 mwSfdGetOutPan: handle is invalid.");
		return 0;
	}
	return MWSFRNA_GetOutPan(mwply, ch);
}

// Dead: skip empty B pictures (cond 20).
void mwPlySetEmptyBpicSkip(MWPLY mwply, Sint32 sw)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122627: mwPlySetEmptyBpicSkip: handle is invalid.");
		return;
	}
	SFD_SetCond(mwply->sfd, 20, sw);
}

// Dead: the input stream joint of the current play.
SJ mwPlyGetInputSj(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122624: mwPlyGetInputSj: handle is invalid.");
		return NULL;
	}
	return mwply->sji;
}

// Dead: empty B pictures skipped.
Sint32 mwPlyGetNumSkipEmptyB(MWPLY mwply)
{
	SFD_PLYINF inf;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122623: mwPlyGetNumSkipEmptyB: handle is invalid.");
		return 0;
	}
	SFD_GetPlyInf(mwply->sfd, &inf);
	return inf.raw[5];
}

// Dead: skipped + empty-B frames.
Sint32 mwPlyGetNumDropFrm(MWPLY mwply)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E202232: mwPlyGetNumDropFrm: handle is invalid.");
		return 0;
	}
	return mwPlyGetNumSkipDec(mwply) + mwPlyGetNumSkipEmptyB(mwply);
}

// Dead: raw SFD player information block.
void mwPlyGetPlyInf(MWPLY mwply, SFD_PLYINF *inf)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E202191: mwPlyGetPlyInf: handle is invalid.");
		return;
	}
	SFD_GetPlyInf(mwply->sfd, inf);
}

// Dead: stream flow information.
void mwPlyGetFlowInf(MWPLY mwply, Sint32 *inf)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E1122643: mwPlyGetFlowInf: handle is invalid.");
		return;
	}
	*inf = 0;
}

// Dead: playback speed in 1/1000.
void mwPlySetSpeed(MWPLY mwply, Sint32 speed)
{
	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E302251: mwPlySetSpeed: handle is invalid.");
		return;
	}
	SFD_SetSpeed(mwply->sfd, speed);
}

// Dead: playback speed as a float ratio.
void mwPlySetFloatSpeed(MWPLY mwply, Float32 speed)
{
	SFD sfd;
	Sint32 ispeed;

	if (!MWSFD_IsEnableHndl(mwply)) {
		MWSFSVM_Error("E211051: mwPlySetFloatSpeed: handle is invalid.");
		return;
	}
	sfd = mwPlyGetSfdHn(mwply);
	ispeed = (Sint32)(speed * 1000.0f + 0.5f);
	if ((Float32)ispeed != speed * 1000.0f) {
		SFD_SetSpeed(sfd, ispeed);
	}
}
