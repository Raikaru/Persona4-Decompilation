/* CRI Sofdec playback control (sfd_pl2.c): speed, standby and the nested pause used both by the
 * user (SFD_Pause) and by the buffering pause of the player state machine; a pause stops the clock
 * and the audio output driver. */
#include "cri_xpt.h"
#include "sfd.h"

#define SFD_REQ_STANDBY 3
#define SFD_REQ_START 4
#define SFD_STAT_PLAYING 4

// Playback speed in 1/1000 (1000 = normal) to the clock and the audio output.
// FUN_00521670
Sint32 SFD_SetSpeed(SFD sfd, Sint32 speed)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000144);
	}
	SFTIM_SetSpeed(sfd, speed);
	SFAOAP_SetSpeed(sfd, speed);
	return 0;
}

// Requests standby (req 3): prepare and buffer but do not start.
Sint32 SFPL2_Standby(SFD sfd)
{
	sfd->req = SFD_REQ_STANDBY;
	return 0;
}

// Public standby request.
Sint32 SFD_Standby(SFD sfd)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000143);
	}
	SFPL2_Standby(sfd);
	return 0;
}

// Pauses/resumes the clock and the audio output driver (slot 7, fn 8) when a start/standby is
// requested; sw 2 = re-pause while playing.
static Sint32 sfpl2_PauseSub(SFD sfd, Sint32 sw)
{
	Sint32 ret;
	Sint32 r;

	if (sfd->req != SFD_REQ_STANDBY && sfd->req != SFD_REQ_START) {
		ret = 0;
	} else {
		SFTIM_Pause(sfd, sw);
		r = SFTRN_CallTrtTrif(sfd, 7, 8, sw, 0);
		ret = 0;
		if (r != 0) {
			ret = r;
		}
	}
	return ret;
}

// Nested pause: 1 pauses on the first request, 0 resumes when the count returns to 0, 2 re-applies
// the pause to a playing handle. Used by both the user pause and the buffering pause.
Sint32 SFPL2_Pause(SFD sfd, Sint32 sw)
{
	Sint32 ret;

	ret = 0;
	switch (sw) {
	case 2:
		if (sfd->stat == SFD_STAT_PLAYING) {
			ret = sfpl2_PauseSub(sfd, 2);
		}
		break;
	case 1:
		if (sfd->pause_cnt++ == 0) {
			ret = sfpl2_PauseSub(sfd, 1);
		}
		break;
	case 0:
		if (--sfd->pause_cnt == 0) {
			ret = sfpl2_PauseSub(sfd, 0);
		}
		break;
	}
	return ret;
}

// Public pause (mwPlyPause): sw 1 pauses (or re-pauses), 0 resumes; flags a state change.
Sint32 SFD_Pause(SFD sfd, Sint32 sw)
{
	Sint32 psw;
	Sint32 mode;
	Sint32 ret;

	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000142);
	}
	psw = sfd->pause_sw;
	if (sw == 0) {
		if (psw == 0) {
			return 0;
		}
		mode = 0;
	} else {
		if (psw == 0) {
			mode = 1;
		} else {
			mode = 2;
		}
	}
	sfd->pause_sw = sw;
	ret = SFPL2_Pause(sfd, mode);
	sfd->chg_flg = 1;
	return ret;
}
