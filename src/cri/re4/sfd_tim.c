/* Sofdec timing (sfd_tim.c): the player clock (vsync / external / user / audio driven, selected
 * by cond 0xF), frame display decisions against that clock, timecode conversion and the
 * per-handle timing work initialisation. */
#include "cri_xpt.h"
#include "sfd.h"

#define SFTIM_NONE -5
#define SFTIM_INTMAX 0x7FFFFFFF
#define SFTIM_TC2TIME_NUM 9

extern Sint32 UTY_CmpTime(Sint32 a, Sint32 aunit, Sint32 b, Sint32 bunit);

void sftim_Tc2Time59D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
void sftim_Tc2Time29D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
void sftim_Tc2Time23D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
static void sftim_Tc2Time59N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
static void sftim_Tc2Time29N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
void sftim_Tc2Time23N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
void sftim_Tc2TimeN(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);
Sint32 sftim_GetTimeExtClock(SFD sfd, Sint32 *ncount, Sint32 *tscale);
Sint32 sftim_GetTimeUfrm(SFD sfd, Sint32 *ncount, Sint32 *tscale);
Sint32 sftim_GetTimeVsync(SFD sfd, Sint32 *ncount, Sint32 *tscale);
static Sint32 sftim_GetTimeNone(SFD sfd, Sint32 *ncount, Sint32 *tscale);

typedef void (*SFTIM_TC2TIME_FN)(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale);

/* frame rates by type (x1000; 0 = unknown) */
const Sint32 SFTIM_prate[SFTIM_TC2TIME_NUM] = {
	1, 23976, 24000, 25000, 29970, 30000, 50000, 59940, 60000,
};

/* timecode converters by [type][drop] */
static const SFTIM_TC2TIME_FN sftim_tc2time[SFTIM_TC2TIME_NUM][2] = {
	{NULL, NULL},
	{sftim_Tc2Time23N, sftim_Tc2Time23D},
	{sftim_Tc2TimeN, sftim_Tc2TimeN},
	{sftim_Tc2TimeN, sftim_Tc2TimeN},
	{sftim_Tc2Time29N, sftim_Tc2Time29D},
	{sftim_Tc2TimeN, sftim_Tc2TimeN},
	{sftim_Tc2TimeN, sftim_Tc2TimeN},
	{sftim_Tc2Time59N, sftim_Tc2Time59D},
	{sftim_Tc2TimeN, sftim_Tc2TimeN},
};

Sint32 sftim_v_sample = 0;
Sint32 sftim_v_time = 0;
Sint32 sftim_a_sample = 0;
Sint64 sftim_as_pts = 0;

// Playback speed in 1/1000 (1000 = normal).
Sint32 SFTIM_GetSpeed(SFD sfd)
{
	return SFD_TIM(sfd)->speed;
}

// Sets the speed; the vsync clocks advance by `speed` per vsync instead of 1000.
void SFTIM_SetSpeed(SFD sfd, Sint32 speed)
{
	SFD_TIM(sfd)->speed = speed;
}

/* the clock passed the video end time (plus one frame at 59.94) */
Bool SFTIM_IsVideoTerm(SFD sfd)
{
	SFTIM tim;
	Sint32 vterm;
	Sint32 unit;

	tim = SFD_TIM(sfd);
	vterm = tim->vterm;
	unit = tim->vterm_unit;
	if (sfd->plyinf.raw[0] == 0) {
		return TRUE;
	}
	if (vterm == SFTIM_NONE) {
		return FALSE;
	}
	vterm += unit * 2000 / 59940;
	return UTY_CmpTime(vterm, unit, tim->cur, tim->cur_unit) != 0;
}

/* the frame with time ftime/tunit is due against the current clock */
/* dead (stripped by the linker); its int -> float conversion creates the unit's 0x43300000_80000000
 * conversion constant before the 10000.0f literal of the helper below, which is the original .rodata
 * order [double][10000.0f][-1.0f] (a literal is placed by creation order, not by first use) */
static Float32 sftim_Sint32ToFloat32(Sint32 v)
{
	return (Float32)v;
}

// Frame display decision: with an integer clock (unit 1: no clock / vsync count) compares the frame
// time with the vsync counter; with a real clock compares in 1/10000 s, offset by the audio-video
// adjustment cond 44, with a tolerance of one frame time and the skip judgement (isskipfn / the
// stabiliser's last decision). TRUE = the frame is due now.
static inline Bool sftim_IsGetFrmTime(SFD sfd, Sint32 ftime, Sint32 tunit)
{
	SFTIM tim;
	SFTIM_LIB *lib;
	Sint32 ncount;
	Sint32 tscale;
	Sint32 adj;
	Sint32 vrate;
	Sint32 cnt;
	Sint32 fast;
	Float32 tol;
	Float32 ct;
	Float32 ft;
	Bool ret;

	tim = SFD_TIM(sfd);
	lib = SFTIM_LIBWK;
	tscale = tim->cur_unit;
	adj = sfd->cond[44];
	ncount = tim->cur;
	if (tscale == 1) {
		if (ncount == -2) {
			ret = TRUE;
		} else if (tim->vcnt < 0) {
			tim->vcnt = 0;
			ret = TRUE;
		} else {
			/* the original re-reads vcnt after the sign test (a second load in both callers) */
			cnt = *(volatile Sint32 *)&tim->vcnt;
			if (UTY_CmpTime(ftime, tunit, cnt, lib->vrate) != 0) {
				ret = TRUE;
			} else {
				ret = FALSE;
			}
		}
	} else {
		vrate = lib->vrate;
		ncount += tscale * adj / vrate;
		ft = (Float32)ftime;
		ft = 10000.0f * ft / (Float32)tunit;
		ct = 10000.0f * (Float32)ncount / (Float32)tscale;
		if (sfd->cond[15] != 1) {
			tol = (Float32)sfd->cond[46];
			if (ct + tol < ft) {
				ret = FALSE;
			} else if (ct - tol >= ft) {
				ret = TRUE;
				if (tim->x2c8 != ft) {
					if (tim->x2c0 != ft) {
						tim->x2c0 = ft;
						tim->x2bc++;
					}
				}
			} else {
				cnt = tim->x2bc;
				fast = 0;
				if (vrate == 59940 && sfd->picrate <= 2 && tim->speed == 1000) {
					fast = 1;
				}
				if (cnt <= (fast != 0)) {
					ret = tim->x2c4;
				} else if (ct < ft) {
					ret = FALSE;
				} else {
					ret = TRUE;
				}
				tim->x2bc = 0;
				tim->x2c4 = ret;
				tim->x2c8 = ft;
			}
		} else {
			if (ft <= ct) {
				ret = TRUE;
			} else {
				ret = FALSE;
			}
		}
	}
	return ret;
}

/* the frame-taking copy of sftim_IsGetFrmTime: the target ranks `tunit` between the body's own
 * `tscale` and `vrate` (r10 between r9 and r11), which only a local of the SAME inlined body gets --
 * a wrapper local or the Tunit call's argument temporary ranks above all of them (6w). `tunit` is
 * read before `ftime`, as the target loads them */
static inline Bool sftim_IsGetFrmTimeFrm(SFD sfd, SFD_VFRM *frm)
{
	SFTIM tim;
	SFTIM_LIB *lib;
	Sint32 ncount;
	Sint32 tscale;
	Sint32 tunit;
	Sint32 adj;
	Sint32 vrate;
	Sint32 cnt;
	Sint32 fast;
	Float32 tol;
	Float32 ct;
	Float32 ft;
	Bool ret;
	Sint32 ftime;

	tunit = frm->inf.raw[4];
	ftime = frm->inf.raw[3];
	if (sfd->cond[14] != 0) {
		return TRUE;
	}
	tim = SFD_TIM(sfd);
	lib = SFTIM_LIBWK;
	tscale = tim->cur_unit;
	adj = sfd->cond[44];
	ncount = tim->cur;
	if (tscale == 1) {
		if (ncount == -2) {
			ret = TRUE;
		} else if (tim->vcnt < 0) {
			tim->vcnt = 0;
			ret = TRUE;
		} else {
			/* the original re-reads vcnt after the sign test (a second load in both callers) */
			cnt = *(volatile Sint32 *)&tim->vcnt;
			if (UTY_CmpTime(ftime, tunit, cnt, lib->vrate) != 0) {
				ret = TRUE;
			} else {
				ret = FALSE;
			}
		}
	} else {
		vrate = lib->vrate;
		ncount += tscale * adj / vrate;
		ft = (Float32)ftime;
		ft = 10000.0f * ft / (Float32)tunit;
		ct = 10000.0f * (Float32)ncount / (Float32)tscale;
		if (sfd->cond[15] != 1) {
			tol = (Float32)sfd->cond[46];
			if (ct + tol < ft) {
				ret = FALSE;
			} else if (ct - tol >= ft) {
				ret = TRUE;
				if (tim->x2c8 != ft) {
					if (tim->x2c0 != ft) {
						tim->x2c0 = ft;
						tim->x2bc++;
					}
				}
			} else {
				cnt = tim->x2bc;
				fast = 0;
				if (vrate == 59940 && sfd->picrate <= 2 && tim->speed == 1000) {
					fast = 1;
				}
				if (cnt <= (fast != 0)) {
					ret = tim->x2c4;
				} else if (ct < ft) {
					ret = FALSE;
				} else {
					ret = TRUE;
				}
				tim->x2bc = 0;
				tim->x2c4 = ret;
				tim->x2c8 = ft;
			}
		} else {
			if (ft <= ct) {
				ret = TRUE;
			} else {
				ret = FALSE;
			}
		}
	}
	return ret;
}

/* the force flag is tested here, not in the helper: this function returns TRUE directly */
Bool SFTIM_IsGetFrmTimeTunit(SFD sfd, Sint32 ftime, Sint32 tunit)
{
	if (sfd->cond[14] != 0) {
		return TRUE;
	}
	return sftim_IsGetFrmTime(sfd, ftime, tunit);
}

// Whether decoded frame `frm` should be handed to the application now (the manual video output's
// GetRead); FALSE for a NULL frame.
Bool SFTIM_IsGetFrmTime(SFD sfd, SFD_VFRM *frm)
{
	if (frm == NULL) {
		return FALSE;
	}
	return sftim_IsGetFrmTimeFrm(sfd, frm);
}

// The stream's frame rate x1000 (SFTIM_prate[picrate]), -1 when unknown yet.
// FUN_00526A10
Sint32 SFD_GetFps(SFD sfd, Sint32 *fps)
{
	*fps = -1;
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF00011B);
	}
	if (sfd->picrate == 0) {
		return 0;
	}
	*fps = SFTIM_prate[sfd->picrate];
	return 0;
}

// Duration of one video frame as count/scale (1000 / prate; 29.97 fps assumed when unknown).
void SFTIM_GetTimeOneFrmVideo(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 picrate;

	picrate = sfd->picrate;
	if (picrate == 0) {
		*ncount = 0;
		*tscale = 29970;
		return;
	}
	*ncount = 1000;
	*tscale = SFTIM_prate[picrate];
}

/* pause mode 2: advance the clocks by one video frame */
void SFTIM_Pause(SFD sfd, Sint32 sw)
{
	SFTIM tim;
	Sint32 ncount;
	Sint32 tscale;
	Sint32 n;
	Sint32 cs1;
	Sint32 cs2;

	tim = SFD_TIM(sfd);
	switch (sw) {
	case 2:
		SFTIM_GetTimeOneFrmVideo(sfd, &ncount, &tscale);
		n = UTY_MulDiv(SFTIM_LIBWK->vrate, ncount, tscale);
		SFLIB_LockCs(&cs1);
		tim->vsync += n;
		tim->vcnt += n;
		SFLIB_UnlockCs(&cs1);
		n = UTY_MulDiv(tim->ext_unit, ncount, tscale);
		SFLIB_LockCs(&cs2);
		tim->ext_cnt += n;
		SFLIB_UnlockCs(&cs2);
		break;
	case 1:
	default:
		break;
	}
}

/* timecode -> time; drop frame: two frames dropped every minute except every tenth. The frame sum
 * is the right operand of the product chain: the backend creates the operands of `+` right first, so
 * the frm/frm2 loads get the lowest temporary ids (coloured last: r12/r11) while the frontend still
 * adds the hour term last. */
void sftim_Tc2Time59D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 f;

	f = tc->hour * 215892 + tc->min * 3598 + (tc->min / 10) * 2 + tc->sec * 60 + (tc->frm + tc->frm2);
	*ncount = f * 1000 + tc->field * 500;
	*tscale = prate;
}

// 29.97 drop-frame timecode -> frame count x1000 (+500 per field) over prate.
void sftim_Tc2Time29D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 f;

	f = tc->hour * 107892 + tc->min * 1798 + (tc->min / 10) * 2 + tc->sec * 30 + (tc->frm + tc->frm2);
	*ncount = f * 1000 + tc->field * 500;
	*tscale = prate;
}

// 23.976 drop-frame timecode -> frame count x1000 over prate.
void sftim_Tc2Time23D(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 f;

	f = tc->hour * 86292 + tc->min * 1438 + (tc->min / 10) * 2 + tc->sec * 24 + (tc->frm + tc->frm2);
	*ncount = f * 1000 + tc->field * 500;
	*tscale = prate;
}

// 59.94 non-drop timecode -> frames x1000 over prate.
static void sftim_Tc2Time59N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 frm;

	frm = tc->frm + tc->frm2;
	*ncount = tc->min * (60000 * 60) + tc->hour * (60000 * 3600) + tc->sec * 60000 + frm * 1000 + tc->field * 500;
	*tscale = 60000;
	*tscale = prate;
}

// 29.97 non-drop timecode -> frames x1000 over prate.
static void sftim_Tc2Time29N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 frm;

	frm = tc->frm + tc->frm2;
	*ncount = tc->min * (30000 * 60) + tc->hour * (30000 * 3600) + tc->sec * 30000 + frm * 1000 + tc->field * 500;
	*tscale = 30000;
	*tscale = prate;
}

// 23.976 non-drop timecode -> frames x1000 over prate.
void sftim_Tc2Time23N(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 frm;

	frm = tc->frm + tc->frm2;
	*ncount = tc->min * (24000 * 60) + tc->hour * (24000 * 3600) + tc->sec * 24000 + frm * 1000 + tc->field * 500;
	*tscale = 24000;
	*tscale = prate;
}

// Integer-rate non-drop timecode -> frames x1000 over prate.
void sftim_Tc2TimeN(Sint32 prate, SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 sec;
	Sint32 frm;

	sec = tc->min * 60 + tc->hour * 3600 + tc->sec;
	frm = tc->frm + tc->frm2;
	*ncount = frm * 1000 + sec * prate + tc->field * 500;
	*tscale = prate;
}

// Converts a GOP timecode (type = frame rate index, drop flag, h:m:s:f + field) into count/scale
// with the converter table; error 0xFF000221 for an unknown rate.
// FUN_00526500
void SFTIM_Tc2Time(SFTIM_TC *tc, Sint32 *ncount, Sint32 *tscale)
{
	SFTIM_TC2TIME_FN fn;
	Sint32 prate;

	prate = SFTIM_prate[tc->type];
	fn = sftim_tc2time[tc->type][tc->drop];
	if (fn == NULL) {
		SFLIB_SetErr(NULL, 0xFF000221);
		*ncount = 0;
		*tscale = 1;
		return;
	}
	fn(prate, tc, ncount, tscale);
}

// Installs a clock source (type 0 none, 1 vsync, 2 audio driver, 3 ufrm, 4 user, 5 external); the
// ADXT driver installs sfadxt_GetTime as type 2.
void SFTIM_SetTimeFn(SFD sfd, SFTIM_FN fn, Sint32 type)
{
	SFD_TIM(sfd)->timefn[type] = fn;
}

// Installs an external clock callback (with its wrap value) and selects it (cond 0xF = 5); NULL
// reverts to the vsync clock.
Sint32 SFD_SetExtClockFn(SFD sfd, SFTIM_FN fn, Sint32 wrap, void *obj)
{
	SFTIM tim;

	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000129);
	}
	tim = SFD_TIM(sfd);
	if (fn != NULL) {
		tim->extfn = fn;
		tim->ext_wrap = wrap;
		tim->ext_obj = obj;
		SFSET_SetCond(sfd, 0xF, 5);
		SFSET_SetCond(sfd, 0x47, 0);
	} else {
		SFSET_SetCond(sfd, 0x47, 1);
		SFSET_SetCond(sfd, 0xF, 1);
		tim->ext_obj = obj;
		tim->ext_wrap = wrap;
		tim->extfn = NULL;
	}
	return 0;
}

// Installs a user clock callback and selects it (cond 0xF = 4).
Sint32 SFD_SetUsrTimeFn(SFD sfd, SFTIM_FN fn)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000123);
	}
	SFD_TIM(sfd)->timefn[4] = fn;
	if (fn != NULL) {
		SFSET_SetCond(sfd, 0xF, 4);
	}
	return 0;
}

// Compares two count/unit times (UTY_CmpTime: nonzero when a >= b).
Sint32 SFD_CmpTime(Sint32 a, Sint32 aunit, Sint32 b, Sint32 bunit)
{
	return UTY_CmpTime(a, aunit, b, bunit);
}

// Installs the user's frame-skip judgement callback.
Sint32 SFD_SetUsrIsSkipFn(SFD sfd, Bool (*fn)())
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000124);
	}
	SFD_TIM(sfd)->isskipfn = fn;
	return 0;
}

/* the handle is in a state whose clock runs (playing / paused-playing, 4 or 6); otherwise the
 * time is reported as -1/1 */
Bool SFTIM_ChkRegularTime(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 stat;

	stat = sfd->stat;
	if (stat != 4 && stat != -4 && stat != 6 && stat != -6) {
		*ncount = -1;
		*tscale = 1;
		return FALSE;
	}
	return TRUE;
}

// Playing, not paused and not in a buffering pause.
static Bool sftim_IsClockRunning(SFD sfd)
{
	if (sfd->stat != 4) {
		return FALSE;
	}
	if (sfd->pause_sw != 0) {
		return FALSE;
	}
	if (sfd->plyinf.raw[7] != 0) {
		return FALSE;
	}
	return TRUE;
}

// External clock source: accumulates the callback's count deltas (wrapping at ext_wrap) while the
// clock runs; -2/1 without a callback.
Sint32 sftim_GetTimeExtClock(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	SFTIM_FN fn;
	Sint32 cnt;
	Sint32 unit;
	Sint32 d;
	Sint32 ret;

	if (!SFTIM_ChkRegularTime(sfd, ncount, tscale)) {
		return 0;
	}
	fn = SFD_TIM(sfd)->extfn;
	if (fn == NULL) {
		*ncount = -2;
		*tscale = 1;
		return 0;
	}
	ret = fn(SFD_TIM(sfd)->ext_obj, &cnt, &unit);
	if (sftim_IsClockRunning(sfd)) {
		if (SFD_TIM(sfd)->ext_last != SFTIM_NONE) {
			d = cnt - SFD_TIM(sfd)->ext_last;
			if (d < 0) {
				d = SFD_TIM(sfd)->ext_wrap + d;
				d++;
			}
			SFD_TIM(sfd)->ext_cnt += d;
		}
	}
	SFD_TIM(sfd)->ext_last = cnt;
	SFD_TIM(sfd)->ext_unit = unit;
	*ncount = SFD_TIM(sfd)->ext_cnt;
	*tscale = SFD_TIM(sfd)->ext_unit;
	return ret;
}

// Clock type 3 placeholder: no time.
Sint32 sftim_GetTimeUfrm(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	if (!SFTIM_ChkRegularTime(sfd, ncount, tscale)) {
		return 0;
	}
	return 0;
}

// Vsync clock source: vsyncs elapsed while playing (x speed) over the refresh rate x1000.
Sint32 sftim_GetTimeVsync(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	if (!SFTIM_ChkRegularTime(sfd, ncount, tscale)) {
		return 0;
	}
	*ncount = SFD_TIM(sfd)->vsync;
	*tscale = SFTIM_LIBWK->vrate;
	return 0;
}

// No clock: -2/1 (every frame is due at once).
// FUN_00525F28
static Sint32 sftim_GetTimeNone(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	if (!SFTIM_ChkRegularTime(sfd, ncount, tscale)) {
		return 0;
	}
	*ncount = -2;
	*tscale = 1;
	return 0;
}

// The current player time (count/unit) as sampled at the last vsync.
Sint32 SFTIM_GetTime(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	*ncount = SFD_TIM(sfd)->cur;
	*tscale = SFD_TIM(sfd)->cur_unit;
	return 0;
}

/* current time plus the start offset (audio start sample or the video start offset) */
Sint32 SFTIM_GetTimeSub(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	SFTIM tim;
	SFTIM_TTU *vofst;

	tim = SFD_TIM(sfd);
	vofst = &tim->vofst;
	SFTIM_GetTime(sfd, ncount, tscale);
	if (*tscale == 1) {
		return 0;
	}
	if (*tscale == tim->astart_sfreq) {
		*ncount = *ncount + tim->astart_smpl;
	} else if (vofst->valid != 0) {
		*ncount += UTY_MulDiv(vofst->val, *tscale, vofst->unit);
	}
	return 0;
}

// Public time (mwPlyGetTime): current time plus the start offset (audio start sample when the unit is
// the audio rate, else the video start offset).
Sint32 SFD_GetTime(SFD sfd, Sint32 *ncount, Sint32 *tscale)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000121);
	}
	return SFTIM_GetTimeSub(sfd, ncount, tscale);
}

// Records the audio start position (samples at sfreq) that SFTIM_GetTimeSub adds.
void SFTIM_SetStartTime(SFTIM tim, Sint32 smpl, Sint32 sfreq)
{
	tim->astart_smpl = smpl;
	tim->astart_sfreq = sfreq;
}

/* video start (offset if known, else the start time) in audio samples; -1 while unknown */
Sint32 SFTIM_GetVideoStartSample(SFTIM tim, Sint32 sfreq, Sint32 *ofstflg)
{
	Sint32 v;
	Sint32 unit;
	Sint32 smpl;

	*ofstflg = tim->vofst.valid;
	if (*ofstflg != 0) {
		v = tim->vofst.val;
		unit = tim->vofst.unit;
	} else if (tim->vstart.val >= 0) {
		v = tim->vstart.val;
		unit = tim->vstart.unit;
	} else {
		return -1;
	}
	smpl = UTY_MulDiv(v, sfreq, unit);
	sftim_v_time = v;
	sftim_v_sample = smpl;
	return smpl;
}

/* audio start PTS (90 kHz) in audio samples; -1 while unknown */
// FUN_00525B58
Sint32 SFTIM_GetAudioStartSample(SFTIM tim, Sint32 sfreq)
{
	Sint64 pts;
	Sint32 smpl;

	pts = tim->as_pts;
	if (pts < 0) {
		return -1;
	}
	smpl = (Sint32)(pts * sfreq / 90000);
	sftim_as_pts = pts;
	sftim_a_sample = smpl;
	return smpl;
}

/* the clock advanced more than cond 0x33 seconds since the time last changed */
static Bool sftim_ChkStagnant(SFD sfd)
{
	SFTIM tim;
	SFTIM_LIB *lib;
	Sint32 lim;
	Sint32 base;
	Sint32 d;
	Sint32 unit;

	tim = SFD_TIM(sfd);
	if (SFSET_GetCond(sfd, 6) == 0) {
		return FALSE;
	}
	lim = SFSET_GetCond(sfd, 0x33);
	if (lim == 0) {
		return FALSE;
	}
	lib = SFTIM_LIBWK;
	if (SFSET_GetCond(sfd, 0x47) == 1) {
		unit = lib->vrate;
		d = tim->vsync - tim->chg_base;
	} else {
		/* the external clock path loads the count first and subtracts the base in place: the base
		 * is a second (volatile) read into a local declared before d, so d (declared later =
		 * coloured first) takes r0 and the base r3 */
		d = tim->ext_cnt;
		base = *(volatile Sint32 *)&tim->chg_base;
		d -= base;
		unit = tim->ext_unit;
	}
	if (d / unit > lim) {
		return TRUE;
	}
	return FALSE;
}

// Whether the clock has stopped advancing for longer than allowed (error 0xFF000222); ends the play.
Bool SFTIM_IsStagnant(SFD sfd)
{
	if (sftim_ChkStagnant(sfd)) {
		SFLIB_SetErr(sfd, 0xFF000222);
		return TRUE;
	}
	return FALSE;
}

// The requested-start vsync counter runs while a start is requested.
static Bool sftim_IsVcntRunning(SFD sfd)
{
	if (SFD_TIM(sfd)->vcnt == -1) {
		return FALSE;
	}
	if (sfd->req != 4) {
		return FALSE;
	}
	return TRUE;
}

/* per vsync: advance the vsync clocks and read the selected clock source */
static void sftim_VbInHn(SFD sfd)
{
	Sint32 cs;
	Sint32 ncount;
	Sint32 tscale;
	SFTIM_FN fn;

	if (sftim_IsClockRunning(sfd)) {
		SFD_TIM(sfd)->vsync += SFD_TIM(sfd)->speed;
	}
	if (sftim_IsVcntRunning(sfd)) {
		SFD_TIM(sfd)->vcnt += SFD_TIM(sfd)->speed;
	}
	if (SFSET_GetCond(sfd, 0x47) != 1) {
		return;
	}
	SFLIB_LockCs(&cs);
	fn = *(SFTIM_FN *)((Uint8 *)sfd + 0xD28 + SFSET_GetCond(sfd, 0xF) * 4);
	if (fn == NULL) {
		fn = sftim_GetTimeNone;
	}
	fn(sfd, &ncount, &tscale);
	SFLIB_UnlockCs(&cs);
	if (SFD_TIM(sfd)->cur != ncount || SFD_TIM(sfd)->cur_unit != tscale) {
		if (SFSET_GetCond(sfd, 0x47) == 1) {
			SFD_TIM(sfd)->chg_base = SFD_TIM(sfd)->vsync;
		} else {
			SFD_TIM(sfd)->chg_base = SFD_TIM(sfd)->ext_cnt;
		}
		SFD_TIM(sfd)->cur = ncount;
		SFD_TIM(sfd)->cur_unit = tscale;
	}
	sfd->chg_flg = 1;
}

// Library vsync tick: counts vsyncs and, for every live handle, advances its vsync clocks and
// samples the selected clock source (cond 0xF) into cur/cur_unit, flagging a change when it moved.
void SFTIM_VbIn(void)
{
	SFD *hn;
	Sint32 i;
	SFD sfd;

	SFTIM_LIBWK->vcnt++;
	hn = SFLIB_libwork.hn;
	for (i = 0; i < 8; i++) {
		sfd = hn[i];
		if (SFLIB_CheckHn(sfd) == -1) {
			continue;
		}
		sftim_VbInHn(sfd);
	}
}

/* next input time boundary after t */
Sint32 SFTIM_GetNextItime(SFTIM tim, Sint32 t)
{
	Sint32 itime;
	Sint32 mn;
	Sint32 mx;
	Sint32 ret;

	itime = tim->itime;
	mn = itime + tim->itime_min;
	mx = itime + tim->itime_max;
	if (t < mn) {
		ret = mn;
	} else if (t < mx) {
		ret = mx;
	} else {
		ret = SFTIM_INTMAX;
	}
	return ret;
}

/* track the input time and the min / max / smoothed-min interval between updates */
void SFTIM_UpdateItime(SFTIM tim, Sint32 t)
{
	Sint32 d;
	Sint32 mn;
	Sint32 step;

	if (tim->itime == SFTIM_NONE) {
		tim->itime = t;
		return;
	}
	d = t - tim->itime;
	if (d == 0) {
		return;
	}
	tim->itime = t;
	tim->itime_max = (tim->itime_max > d) ? tim->itime_max : d;
	tim->x2a0 = (tim->x2a0 < d) ? tim->x2a0 : d;
	mn = tim->itime_min;
	if (mn == SFTIM_INTMAX) {
		tim->itime_min = d;
		return;
	}
	if (mn <= d) {
		tim->itime_min = d;
		return;
	}
	step = (mn - d) / 8;
	if (step != 0) {
		tim->itime_min = mn - step;
		return;
	}
	tim->itime_min = d;
}

// Time-with-timecode record: invalid, zero timecode, value `val`, unit 1.
void SFTIM_InitTtu(SFTIM_TTU *ttu, Sint32 val)
{
	Sint32 zero;

	zero = 0;
	ttu->valid = zero;
	ttu->tc.type = zero;
	ttu->tc.drop = zero;
	ttu->tc.hour = zero;
	ttu->tc.min = zero;
	ttu->tc.sec = zero;
	ttu->tc.frm = zero;
	ttu->tc.frm2 = zero;
	ttu->tc.x1c = zero;
	ttu->tc.field = zero;
	ttu->val = val;
	ttu->unit = 1;
}

// Per-handle timing work defaults: clock source table, unset start/end/video times, speed 1000,
// frame decision history and the field-repeat table.
void SFTIM_InitHn(SFD sfd, SFTIM tim)
{
	Sint32 i;

	SFD_TIM(sfd)->timefn[0] = sftim_GetTimeNone;
	SFD_TIM(sfd)->timefn[1] = sftim_GetTimeVsync;
	SFD_TIM(sfd)->timefn[2] = NULL;
	SFD_TIM(sfd)->timefn[3] = sftim_GetTimeUfrm;
	SFD_TIM(sfd)->timefn[4] = NULL;
	SFD_TIM(sfd)->timefn[5] = sftim_GetTimeExtClock;
	tim->isskipfn = NULL;
	tim->tc.type = 0;
	tim->tc.drop = 0;
	tim->tc.hour = 0;
	tim->tc.min = 0;
	tim->tc.sec = 0;
	tim->tc.frm = 0;
	tim->tc.frm2 = 0;
	tim->tc.x1c = 0;
	tim->tc.field = 0;
	SFTIM_InitTtu(&tim->ttu3, 0);
	SFTIM_InitTtu(&tim->ttu0, SFTIM_INTMAX);
	SFTIM_InitTtu(&tim->ttu1, -1);
	SFTIM_InitTtu(&tim->tot, -1);
	SFTIM_InitTtu(&tim->vstart, -1);
	SFTIM_InitTtu(&tim->vofst, SFTIM_INTMAX);
	tim->astart_smpl = 0;
	tim->astart_sfreq = 0;
	tim->x150 = -1;
	tim->as_pts = -1;
	tim->x160 = 0;
	tim->ctime = 0;
	tim->ctime_idx = 0;
	for (i = 0; i < 32; i++) {
		tim->ctime_que[i] = 0;
	}
	tim->tot_last = 1;
	tim->x1f0 = 0;
	tim->que_wr = 0;
	tim->que_rd = 0;
	for (i = 0; i < 32; i++) {
		tim->tot_que[i] = 0;
	}
	tim->vterm = SFTIM_NONE;
	tim->vterm_unit = 1;
	tim->x284 = SFTIM_NONE;
	tim->x288 = 1;
	tim->cur = -1;
	tim->cur_unit = 1;
	tim->itime = SFTIM_NONE;
	tim->itime_min = SFTIM_INTMAX;
	tim->itime_max = 0;
	tim->x2a0 = SFTIM_INTMAX;
	tim->x2a4 = 0;
	tim->vsync = 0;
	tim->speed = 1000;
	tim->x2b0 = 0;
	tim->x2b4 = 0;
	tim->x2b8 = 1;
	tim->x2bc = 100;
	tim->x2c0 = -1.0f;
	tim->x2c4 = 0;
	tim->x2c8 = -1.0f;
	tim->vcnt = -1;
	tim->chg_base = tim->vsync;
	tim->extfn = NULL;
	tim->ext_last = SFTIM_NONE;
	tim->ext_cnt = 0;
	tim->ext_unit = 1;
	tim->ext_wrap = -1;
	tim->ext_obj = NULL;
	tim->x5b0 = 0;
	tim->x5b4 = 0;
	tim->x5b8 = 0;
}

// Library timing work: vsync count 0 and the refresh rate x1000 (59940).
void SFTIM_Init(SFTIM_LIB *lib, Sint32 vrate)
{
	lib->vcnt = 0;
	lib->x04 = 0;
	lib->vrate = vrate;
}
