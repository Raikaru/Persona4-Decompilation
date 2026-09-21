/* CRI Sofdec concatenated playback (sfd_con.c, SFCON): when several files are streamed back to back
 * (cond 0x31, SFD_SetConcatPlay) the end codes are skipped and the clock is offset by the accumulated
 * duration of the finished files; a 32-entry queue passes each file's total sample count from the
 * demuxer to the audio driver. Unused by this game (single-file movies). */
#include "cri_xpt.h"
#include "sfd.h"

#define SFCON_QUE_NUM 32

// Pops the next total-sample entry of the concatenation queue (the audio driver reads the sample
// count of each concatenated file); *val = -1 and 0 when empty.
Sint32 SFCON_ReadTotSmplQue(SFD sfd, Sint32 *val, Sint32 *last)
{
	SFCON *con = &sfd->con;
	Sint32 cs;
	Sint32 ret;

	SFLIB_LockCs(&cs);
	if (con->que_wr - con->que_rd <= 0) {
		*val = -1;
		ret = 0;
	} else {
		*last = con->tot_last;
		ret = 1;
		*val = con->tot_que[con->que_rd % SFCON_QUE_NUM];
		con->que_rd++;
	}
	SFLIB_UnlockCs(&cs);
	return ret;
}

// Pushes a file's total sample count onto the 32-entry queue (from the demuxer at each concatenated
// file); 0 when full.
// FUN_00515D98
Sint32 SFCON_WriteTotSmplQue(SFD sfd, Sint32 val, Sint32 last)
{
	SFCON *con = &sfd->con;
	Sint32 cs;
	Sint32 ret;

	SFLIB_LockCs(&cs);
	if (con->que_wr - con->que_rd >= SFCON_QUE_NUM) {
		ret = 0;
	} else {
		con->tot_last = last;
		ret = 1;
		con->tot_que[con->que_wr % SFCON_QUE_NUM] = val;
		con->que_wr++;
	}
	SFLIB_UnlockCs(&cs);
	return ret;
}

// Adds a finished file's duration to the accumulated concatenation time and records it in the
// per-file ring (the clock adds it to the next file's timestamps).
// FUN_00515D10
void SFCON_UpdateConcatTime(SFD sfd, Sint32 t)
{
	SFCON *con = &sfd->con;
	Sint32 cs;
	Sint32 idx;

	SFLIB_LockCs(&cs);
	con->ctime += t;
	idx = con->ctime_idx;
	idx++;
	con->ctime_que[idx % SFCON_QUE_NUM] = con->ctime;
	con->ctime_idx = idx;
	SFLIB_UnlockCs(&cs);
}

// Concatenated play (cond 0x31) or video end-code skip (0x39): a sequence end code does not end
// the video.
// FUN_00515CC8
Sint32 SFCON_IsVideoEndcodeSkip(SFD sfd)
{
	if (SFSET_GetCond(sfd, 0x31) != 0 || SFSET_GetCond(sfd, 0x39) != 0) {
		return 1;
	}
	return 0;
}

// Concatenated play or system end-code skip (0x38): a program end code does not end the demux.
// FUN_00515C80
Sint32 SFCON_IsSystemEndcodeSkip(SFD sfd)
{
	if (SFSET_GetCond(sfd, 0x31) != 0 || SFSET_GetCond(sfd, 0x38) != 0) {
		return 1;
	}
	return 0;
}

// Concatenated play is on (cond 0x31).
// FUN_00515C60
Sint32 SFCON_IsEndcodeSkip(SFD sfd)
{
	return SFSET_GetCond(sfd, 0x31) != 0;
}

// Enables concatenated play: the streams continue across end codes (linked file playback,
// mwPlyLinkStm).
Sint32 SFD_SetConcatPlay(SFD sfd)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000161);
	}
	SFSET_SetCond(sfd, 0x31, 1);
	return 0;
}
