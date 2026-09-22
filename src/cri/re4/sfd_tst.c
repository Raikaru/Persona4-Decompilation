/* CRI Sofdec: time stabiliser (sfd_tst.c). Smooths the master clock against a helper clock: the
 * difference history is averaged and the output time base is shifted in tolerance steps. */
#include "cri_xpt.h"
#include "sfd.h"
#include <string.h>
#include <stdio.h>

extern Sint32 sfadxt_stat;

/* 64-bit time: count / unit */
typedef struct {
	Sint64 cnt;
	Sint64 unit;
} SFTST_TIME;

#define SFTST_HIST_NUM 60
#define SFTST_DEBOUT_MARGIN 0x400

typedef struct {
	Sint32 tstflg;             /* 0x000 */
	Sint32 pastat;             /* 0x004 pause */
	Sint32 adjmode;            /* 0x008 */
	Sint32 adjflg;             /* 0x00C */
	Sint32 movave_range;       /* 0x010 */
	Sint32 hist_idx;           /* 0x014 */
	Sint32 hist[SFTST_HIST_NUM]; /* 0x018 */
	SFTST_TIME mt;             /* 0x108 last master time */
	SFTST_TIME hlp;            /* 0x118 last helper time */
	SFTST_TIME out;            /* 0x128 last output time */
	SFTST_TIME tolerance;      /* 0x138 */
	SFTST_TIME excesserr;      /* 0x148 */
	SFTST_TIME adjstart;       /* 0x158 */
	SFTST_TIME adjpoff;        /* 0x168 */
	Sint64 base_hlp;           /* 0x178 helper time at the last base (-1: none) */
	Sint64 base_out;           /* 0x180 output time at the last base */
	Sint64 mt_max;             /* 0x188 */
	Sint32 adj_limit;          /* 0x190 */
	Sint32 adj_front;          /* 0x194 */
	Sint32 adj_rear;           /* 0x198 */
	Sint32 resethist;          /* 0x19C */
	Sint32 excesserr_cnt;      /* 0x1A0 */
	Sint32 movave_1st;         /* 0x1A4 */
	Sint32 movave_2nd;         /* 0x1A8 */
	Sint32 diff_l_max;         /* 0x1AC */
	Sint32 diff_l_min;         /* 0x1B0 */
	Sint32 diff_a_max;         /* 0x1B4 */
	Sint32 diff_a_min;         /* 0x1B8 */
	Sint32 rsv;                /* 0x1BC */
} SFTST_WORK;

typedef SFTST_WORK *SFTST;

Sint32 sftst_debout_siz;
Char8 *sftst_debout_buf;
Char8 *sftst_debout_round;
Char8 *sftst_debout_write;
SFTST sftst_last;

/* debug log buffer (dead: keeps the .bss order siz, buf, round, write, last) */
void SFTST_SetDebugOut(Char8 *buf, Sint32 siz)
{
	sftst_debout_siz = siz;
	sftst_debout_buf = buf;
	sftst_debout_round = buf;
	sftst_debout_write = buf;
}

// Clears the difference history and its index.
// FUN_00527A60
static void sftst_ResetHist(SFTST tst)
{
	memset(tst->hist, 0, sizeof(tst->hist));
	tst->hist_idx = 0;
	tst->resethist++;
}

/* a * b / c in the unit of another time */
static Sint64 sftst_Conv(SFTST_TIME *t, Sint64 unit)
{
	return unit * t->cnt / t->unit;
}

/* `i` declared before `sum`: an inlined helper's locals get ascending virtual ids in declaration order, and the
 * second inline's sum/i (both level 1) are coloured by id: sum first -> r4, i -> r5. CRI pass 64. */
static Sint32 sftst_SumHist(SFTST tst)
{
	Sint32 i;
	Sint32 sum;

	sum = 0;
	for (i = 0; i < tst->movave_range; i++) {
		sum += tst->hist[i];
	}
	return sum;
}

/* hist[] -= step as a helper: its `i` is an inlined-helper web (id above the own locals, level 1), coloured
 * after the step-computation temporaries (r6) instead of before them as Calc's own local (r3). CRI pass 64. */
static void sftst_SubHist(SFTST tst, Sint32 sub)
{
	Sint32 i;

	for (i = 0; i < tst->movave_range; i++) {
		tst->hist[i] -= sub;
	}
}

/* .rodata order: the original emitted SFTST_Create's header string before SFTST_Calc's format (its
 * .text follows); both are named here (a named string is emitted at its declaration) */
static const Char8 sftst_msg_hdr[] = "tst, help_time_sec, help_time_msec, help_time_64, help_time, mt_max, master_time, out_time,  mt_ot, mtmax_ot,  diff_l_max, diff_l_min, diff_a_max, tst->diff_a_min, pastat, adjmode, resethist, excesserr, adj_limit, adj_front, adj_rear,  movave_1st, movave_2nd,  adxt_stat \n\n"; // COMPILER-DIFF: M1
typedef struct {
	Char8 s[sizeof(sftst_msg_hdr)];
} SFTST_HDRSTR;
static const Char8 sftst_msg_fmt[] = "%p, %ld, %ld, %08lX%08lX, %ld, %ld, %ld, %ld,   %ld, %ld,   %ld, %ld, %ld, %ld,   %ld, %ld,   %ld, %ld, %ld, %ld, %ld,   %ld, %ld,   %ld \n";

/* The 64-bit abs diamond: `adiff = (diff < 0) ? -diff : diff` (and the if/else form) becomes a single-def
 * ECONDASS that the frontend forward-substitutes into `excess < adiff` BELOW the sftst_Conv call; the
 * nested `diff = ..` assignment inside the condition is a side effect that anchors it above the call with
 * the target's arm shape (`beq; subfic; subfze` in place; else `mr` of the low word, adiff.hi coalesced
 * with the dying diff.hi). CRI pass 14. The register residue that followed (diff lo/hi, ave/tol, the sprintf
 * group) was one colouring fact: `tol` had become the inlined Conv's return temporary; see the notes at
 * `tol = ..`, sftst_SubHist and sftst_SumHist. CRI pass 64. */
void SFTST_Calc(SFTST tst, SFTST_TIME *mt, SFTST_TIME *hlp, SFTST_TIME *out)
{
	Sint64 est;
	Sint64 q;
	Sint64 adj;
	Sint64 diff;
	Sint64 adiff;
	Sint64 ave;
	Sint64 aave;
	Sint64 tol;
	Sint64 step;
	Sint32 idx;
	Sint32 d;
	Sint64 t;
	Sint64 excess;
	Char8 buf[0x100];
	Sint32 n;

	if (hlp->unit == 1 || tst->tstflg == 0) {
		*out = *mt;
		return;
	}
	mt->cnt = (tst->mt_max > mt->cnt) ? tst->mt_max : mt->cnt;
	if (tst->pastat == 1) {
		tst->adjmode = 0;
	} else if (tst->adjmode == 0) {
		if (mt->cnt > tst->mt_max) {
			tst->adjmode = 1;
			if (tst->base_hlp == -1) {
				adj = sftst_Conv(&tst->adjstart, mt->unit);
			} else {
				adj = sftst_Conv(&tst->adjpoff, mt->unit);
			}
			tst->base_hlp = hlp->cnt;
			tst->base_out = mt->cnt + adj;
			sftst_ResetHist(tst);
		} else if (tst->adjflg == 0) {
			tst->adjmode = 1;
		}
	}
	tst->mt_max = (tst->mt_max > mt->cnt) ? tst->mt_max : mt->cnt;
	if (tst->base_hlp == -1) {
		est = 0;
	} else {
		est = tst->base_out + mt->unit * (hlp->cnt - tst->base_hlp) / hlp->unit;
	}
	if (tst->adjmode == 0) {
		if (tst->mt_max < est) {
			if (tst->adjflg != 0) {
				tst->base_hlp = hlp->cnt;
				tst->base_out = tst->mt_max;
			} else {
				tst->base_hlp = hlp->cnt;
				tst->base_out = tst->out.cnt;
			}
			tst->adj_limit++;
		}
	} else if (tst->adjflg == 1) {
		adiff = ((diff = mt->cnt - est) < 0) ? -diff : diff;
		excess = sftst_Conv(&tst->excesserr, mt->unit);
		if (excess < adiff) {
			tst->base_hlp = hlp->cnt;
			tst->base_out = mt->cnt;
			sftst_ResetHist(tst);
			tst->excesserr_cnt++;
		} else {
			idx = tst->hist_idx;
			tst->hist_idx = idx + 1;
			tst->hist[idx % tst->movave_range] = (Sint32)diff;
			ave = sftst_SumHist(tst) / tst->movave_range;
			tst->movave_1st = (Sint32)ave;
			tst->movave_2nd = (Sint32)ave;
			/* written out, not sftst_Conv(): a local assigned a plain copy of an inlined helper's result is
			 * replaced by the helper's return temporary (id above every own local); `tol` must stay an own
			 * local below `ave` so ave.hi is removed after tol in the same Chaitin scan. CRI pass 64. */
			tol = mt->unit * tst->tolerance.cnt / tst->tolerance.unit;
			aave = (ave < 0) ? -ave : ave;
			if (tol < aave) {
				if (tol < ave) {
					q = ave * 2 / tol - 1;
					tst->adj_front += (Sint32)q;
				} else {
					q = ave * 2 / tol + 1;
					tst->adj_rear += (Sint32)-q;
				}
				adj = q;
				step = adj * tol / 2;
				tst->base_hlp = hlp->cnt;
				tst->base_out = est + step;
				sftst_SubHist(tst, (Sint32)step);
				tst->movave_2nd = sftst_SumHist(tst) / tst->movave_range;
			}
		}
	}
	if (tst->base_hlp == -1) {
		t = 0;
	} else {
		t = tst->base_out + mt->unit * (hlp->cnt - tst->base_hlp) / hlp->unit;
	}
	out->cnt = t;
	out->unit = mt->unit;
	if (out->cnt < tst->out.cnt) {
		*out = tst->out;
	}
	tst->mt = *mt;
	tst->hlp = *hlp;
	tst->out = *out;
	d = (Sint32)(mt->cnt - out->cnt);
	if (tst->adjmode == 0) {
		tst->diff_l_max = (tst->diff_l_max > d) ? tst->diff_l_max : d;
		tst->diff_l_min = (tst->diff_l_min < d) ? tst->diff_l_min : d;
	} else {
		tst->diff_a_max = (tst->diff_a_max > d) ? tst->diff_a_max : d;
		tst->diff_a_min = (tst->diff_a_min < d) ? tst->diff_a_min : d;
	}
	sftst_last = tst;
	if (sftst_debout_buf != NULL) {
		n = sprintf(buf, sftst_msg_fmt,
			tst, (Sint32)(tst->hlp.cnt / tst->hlp.unit),
			UTY_MulDiv(1000, (Sint32)tst->hlp.cnt, (Sint32)tst->hlp.unit),
			(Sint32)(tst->hlp.cnt >> 32), (Sint32)tst->hlp.cnt, (Sint32)(tst->hlp.cnt & 0x7FFFFFFF),
			(Sint32)tst->mt_max, (Sint32)tst->mt.cnt, (Sint32)tst->out.cnt,
			(Sint32)(tst->mt.cnt - tst->out.cnt), (Sint32)(tst->mt_max - tst->out.cnt),
			tst->diff_l_max, tst->diff_l_min, tst->diff_a_max, tst->diff_a_min,
			tst->pastat, tst->adjmode, tst->resethist, tst->excesserr_cnt,
			tst->adj_limit, tst->adj_front, tst->adj_rear, tst->movave_1st, tst->movave_2nd,
			sfadxt_stat);
		strcpy(sftst_debout_write, buf);
		sftst_debout_write += n;
		if (sftst_debout_write >= sftst_debout_buf + sftst_debout_siz - SFTST_DEBOUT_MARGIN) {
			sftst_debout_write = sftst_debout_round;
		}
	}
}

// Advances the output clock by one frame duration when the stabiliser is not adjusting.
// FUN_00527B28
void SFTST_GoNextFrame(SFTST tst, SFTST_TIME *frm)
{
	if (tst->adjflg == 0) {
		tst->out.cnt += tst->out.unit * frm->cnt / frm->unit;
	}
}

// Adjustment on/off.
void SFTST_SetAdjFlg(SFTST tst, Sint32 flg)
{
	tst->adjflg = flg;
}

// Pause state of the stabiliser (differences are not accumulated while paused).
void SFTST_Pause(SFTST tst, Sint32 sw)
{
	tst->pastat = sw;
}

// Moving-average window (frames) for the difference history.
// FUN_00527B08
void SFTST_SetMovaveRange(SFTST tst, Sint32 range)
{
	if (range > 0) {
		tst->movave_range = range;
	}
}

// Time after which an adjustment is switched off.
// FUN_00527AF0
void SFTST_SetAdjPoff(SFTST tst, SFTST_TIME *t)
{
	tst->adjpoff = *t;
}

// Difference from which an adjustment starts.
// FUN_00527AD8
void SFTST_SetAdjStart(SFTST tst, SFTST_TIME *t)
{
	tst->adjstart = *t;
}

// Difference treated as a gross error (history reset).
// FUN_00527AC0
void SFTST_SetExcessErr(SFTST tst, SFTST_TIME *t)
{
	tst->excesserr = *t;
}

// Step size of an output time base shift.
// FUN_00527AA8
void SFTST_SetTolerance(SFTST tst, SFTST_TIME *t)
{
	tst->tolerance = *t;
}

// Stabiliser enable flag.
// FUN_004C1030
void SFTST_SetTstFlg(SFTST tst, Sint32 flg)
{
	tst->tstflg = flg;
}

/* COMPILER-DIFF: M1 - the `lwz sftst_debout_buf` scheduled above the hdr copy tail. Pure C by project decision (CRI pass 8). */
void SFTST_Create(SFTST tst)
{
	memset(tst, 0, sizeof(SFTST_WORK));
	tst->tstflg = 1;
	tst->pastat = 0;
	tst->adjmode = 0;
	tst->adjflg = 1;
	tst->movave_range = 10;
	sftst_ResetHist(tst);
	tst->mt.cnt = 0;
	tst->mt.unit = 1;
	tst->hlp.cnt = 0;
	tst->hlp.unit = 1;
	tst->out.cnt = 0;
	tst->out.unit = 1;
	tst->tolerance.cnt = 16683;
	tst->tolerance.unit = 1000000;
	tst->excesserr.cnt = 200000;
	tst->excesserr.unit = 1000000;
	tst->adjstart.cnt = -16683;
	tst->adjstart.unit = 1000000;
	tst->adjpoff.cnt = -16683;
	tst->adjpoff.unit = 1000000;
	tst->base_hlp = -1;
	tst->base_out = 0;
	tst->mt_max = 0;
	tst->adj_limit = 0;
	tst->adj_front = 0;
	tst->adj_rear = 0;
	tst->resethist = 0;
	tst->excesserr_cnt = 0;
	tst->movave_1st = 0;
	tst->movave_2nd = 0;
	tst->diff_l_max = 0;
	tst->diff_l_min = 0;
	tst->diff_a_max = 0;
	tst->diff_a_min = 0;
	{
		/* `Char8 hdr[] = "..."` with the literal named (see sftst_msg_hdr): a struct copy is the
		 * same inline block copy as the array initialiser */
		SFTST_HDRSTR hdr = *(const SFTST_HDRSTR *)sftst_msg_hdr;

		if (sftst_debout_buf != NULL) {
			memset(sftst_debout_buf, 0, sftst_debout_siz);
			sftst_debout_write = sftst_debout_buf;
			strcpy(sftst_debout_write, hdr.s);
			sftst_debout_write += strlen(hdr.s);
			sftst_debout_round = sftst_debout_write;
		}
	}
}
