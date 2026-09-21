/* CRI Sofdec MPEG video: "unified" motion compensation front end (mpv_umc.c). Macroblocks are
 * built from the reference frame planes through the 8x8 (chroma) / 16x16 (luma) one-reference
 * kernels of mpv_mc.c / mpv_mcy.c and merged with the IDCT output into the word-packed output
 * frame; skipped macroblocks are copied from the reference (`mpvumc_PpicSkipMb`: C, unrolled
 * double copies with `__dcbz`). The paired-single merge kernels (`mpvumc_BiMakeMb`,
 * `mpvumc_OneMakeMb`, `mpvumc_OutputIntra6blk`) and the GQR setup are inline assembly: MWCC 2.4.7
 * has no paired-single intrinsics (its `__vec2x32float__` operators emit only psq_lx/psq_stx
 * through GQR0 and ps_add/sub/mul/madd; no quantised GQR, update forms, merges, ps_sel or mtspr),
 * so their asm bodies stay (they need the scheduler ON for two swapped adjacent instructions).
 * The wrappers set the output block pointers through `ob = &mpv->outblk` (assigned AFTER the read
 * call, in the block of the stores: add-propagation folds the stores to `mpv` offsets and the
 * `addi r4` definition stays where `ob` is assigned, before the `mr r3, wk` argument move).
 * All 16 functions match (CRI pass 68: mpvumc_OneReadMb, see its comment). */
#include "cri_xpt.h"
#include "mpv.h"

/* a frame's planes: the two chroma planes first, then luma, with their pitches */
typedef struct {
	Uint8 *pln[3];             /* 0x00 */
	Sint16 cpitch;             /* 0x0C */
	Sint16 ypitch;             /* 0x0E */
} MPVUMC_RFB;

/* the MPV object as seen here */
/* the MC work pointers (MPV_OBJ + 0x110) */
typedef struct {
	Uint8 *clip;               /* 0x00 */
	Uint8 *buf0;               /* 0x04 */
	Uint8 *work;               /* 0x08 the first prediction */
	Uint8 *work2;              /* 0x0C the second prediction */
} MPVUMC_WORK;

/* the output blocks of the current macroblock: the coded count and the six block pointers */
typedef struct {
	Sint32 ccnt;               /* 0x00 */
	MPVCMC_REF rt[6];          /* 0x04 */
} MPVUMC_OUTBLK;

typedef struct {
	Uint8 pad0[0x40];
	Uint8 *clip_base;          /* 0x040 */
	Uint8 pad44[0xCC - 0x44];
	Uint8 pad_mc[0x44];        /* 0x0CC MPVMC (its 0x44 kernel fields) */
	MPVUMC_WORK mcwk;          /* 0x110 */
	MPVUMC_OUTBLK outblk;      /* 0x120 */
	Uint8 pad154[0x19C - 0x154];
	Sint32 mcflag;             /* 0x19C cond[3] */
	Uint8 pad1a0[0x1D0 - 0x1A0];
	Sint32 width;              /* 0x1D0 */
	Sint32 height;             /* 0x1D4 */
	Sint32 mb_width;           /* 0x1D8 */
	Uint8 pad1dc[0x264 - 0x1DC];
	MPVUMC_RFB out;            /* 0x264 */
	MPVUMC_RFB ref;            /* 0x274 */
	Uint8 *frmbuf;             /* 0x284 */
	Uint8 pad288[0x294 - 0x288];
	Uint8 *out_pln[3];         /* 0x294 output planes (chroma, chroma, luma) */
	Sint16 out_cpitch;         /* 0x2A0 */
	Sint16 out_ypitch;         /* 0x2A2 */
	Uint8 pad2a4[0x2D4 - 0x2A4];
	void (*mc_func[4])(void *mpv); /* 0x2D4 */
	Uint8 pad2e4[0x2EC - 0x2E4];
	MPV_MV fwd;                /* 0x2EC */
	MPV_MV bwd;                /* 0x310 */
	Sint32 mb_addr;            /* 0x334 */
	Sint32 mb_y;               /* 0x338 */
	Sint32 mb_x;               /* 0x33C */
	Uint8 pad340[0x348 - 0x340];
	Sint32 cbp_code;           /* 0x348 */
	Uint8 pad34c[0x380 - 0x34C];
	Uint8 mcbuf[0x100];        /* 0x380 */
} MPVUMC_OBJ;

typedef void (*MPVUMC_MCFUNC)(MPVMC *mc);

extern void MPVMC08_OneRef1p_TuneC(MPVMC *mc);
extern void MPVMC08_OneRefH2_TuneC(MPVMC *mc);
extern void MPVMC08_OneRefV2_TuneC(MPVMC *mc);
extern void MPVMC08_OneRef4p_TuneC(MPVMC *mc);
extern void MPVMC16_OneRef1p_TuneC(MPVMC *mc);
extern void MPVMC16_OneRefH2_TuneC(MPVMC *mc);
extern void MPVMC16_OneRefV2_TuneC(MPVMC *mc);
extern void MPVMC16_OneRef4p_TuneC(MPVMC *mc);

/* 1.0f of the paired-single average (compiler constant `const_mem$89` in the original) */
static const Float32 mpvumc_ps_one = 1.0f;

MPVUMC_MCFUNC mpvumc_oneref_y[2][2][2];
static MPVUMC_MCFUNC mpvumc_oneref[2][2][2];

void mpvumc_PpicSkipMb(Sint32 *ofs, MPVUMC_RFB *out, MPVUMC_RFB *ref);
void mpvumc_BiMakeMb(MPVUMC_WORK *wk, MPVUMC_OUTBLK *ob, Sint32 cbp);
void mpvumc_OneMakeMb(MPVUMC_WORK *wk, MPVUMC_OUTBLK *ob, Sint32 cbp);
void mpvumc_OneReadMb(MPVUMC_OBJ *mpv, Uint8 *dst, Sint32 *ofs, MPVUMC_RFB *rfb, MPV_MV *mv);
void mpvumc_OutputIntra6blk(Uint8 *blk, MPVUMC_OUTBLK *ob, Uint8 *clip);

/* B picture: `n` skipped macroblocks repeat the previous macroblock's prediction */
void MPVUMC_BpicSkipped(MPVUMC_OBJ *mpv, Sint32 n)
{
	Sint32 mb_end;
	void (*func)(void *mpv);

	mpv->cbp_code = 0;
	mb_end = mpv->mb_addr;
	func = mpv->mc_func[0];
	mpv->mb_addr -= n - 1;
	mpv->mb_x -= n - 1;
	while (mpv->mb_x < 0) {
		mpv->mb_x += mpv->mb_width;
		mpv->mb_y--;
	}
	while (mpv->mb_addr < mb_end) {
		func(mpv);
		mpv->mb_x++;
		if (mpv->mb_x >= mpv->mb_width) {
			mpv->mb_x = 0;
			mpv->mb_y++;
		}
		mpv->mb_addr++;
	}
}

/* two chroma rows (one double each) / one luma row (two doubles), with and without the cache-line clear */
#define MPVUMC_CPY_C2Z(d, s, p)   __dcbz(d, 0); a = s[0]; __dcbz(d, (p) * 8); b = s[p]; s += (p) * 2; d[0] = a; d[p] = b; d += (p) * 2
#define MPVUMC_CPY_C2(d, s, p)    a = s[0]; b = s[p]; s += (p) * 2; d[0] = a; d[p] = b; d += (p) * 2
#define MPVUMC_CPY_YZ(d, s, p)    __dcbz(d, 0); a = s[0]; b = s[1]; s += (p); d[0] = a; d[1] = b; d += (p)
#define MPVUMC_CPY_Y(d, s, p)     a = s[0]; b = s[1]; s += (p); d[0] = a; d[1] = b; d += (p)

/* copy the macroblock at ofs[] (chroma, luma) from the reference to the output frame, two chroma rows /
 * one luma row per step, with the cache-line clear when the offset is 32-byte aligned (`p` = the
 * pitch in doubles, declared first: p r9 above d r10; `s` assigned before `d`; ofs[] re-read per
 * plane; the scheduler ON interleaves the pitch shifts and swaps the last row's two loads) */
void mpvumc_PpicSkipMb(Sint32 *ofs, MPVUMC_RFB *out, MPVUMC_RFB *ref)
{
	Sint32 p;
	Float64 *s;
	Float64 *d;
	Float64 a;
	Float64 b;

	p = ref->cpitch / 8;
	if ((ofs[0] & 0x1f) == 0) {
		s = (Float64 *)(out->pln[0] + ofs[0]);
		d = (Float64 *)(ref->pln[0] + ofs[0]);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
		s = (Float64 *)(out->pln[1] + ofs[0]);
		d = (Float64 *)(ref->pln[1] + ofs[0]);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
		MPVUMC_CPY_C2Z(d, s, p);
	} else {
		s = (Float64 *)(out->pln[0] + ofs[0]);
		d = (Float64 *)(ref->pln[0] + ofs[0]);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
		s = (Float64 *)(out->pln[1] + ofs[0]);
		d = (Float64 *)(ref->pln[1] + ofs[0]);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
		MPVUMC_CPY_C2(d, s, p);
	}
	p = ref->ypitch / 8;
	if ((ofs[1] & 0x1f) == 0) {
		s = (Float64 *)(out->pln[2] + ofs[1]);
		d = (Float64 *)(ref->pln[2] + ofs[1]);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
		MPVUMC_CPY_YZ(d, s, p);
	} else {
		s = (Float64 *)(out->pln[2] + ofs[1]);
		d = (Float64 *)(ref->pln[2] + ofs[1]);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
		MPVUMC_CPY_Y(d, s, p);
	}
}

/* P picture: `n` skipped macroblocks are copied from the reference frame */
void MPVUMC_PpicSkipped(MPVUMC_OBJ *mpv, Sint32 n)
{
	Sint32 mb_end;
	MPVUMC_RFB *out;
	MPVUMC_RFB *ref;
	Sint32 ofs[2];
	Sint32 y8;
	Sint32 y16;

	out = &mpv->out;
	mb_end = mpv->mb_addr;
	ref = out + 1;
	mpv->mb_addr -= n - 1;
	mpv->mb_x -= n - 1;
	while (mpv->mb_x < 0) {
		mpv->mb_x += mpv->mb_width;
		mpv->mb_y--;
	}
	while (mpv->mb_addr < mb_end) {
		/* the row offsets as named locals (y16 derived from y8): `mb_y * 8 * cpitch` inline puts cpitch
		 * first in the mullw and recomputes the shifts */
		y8 = mpv->mb_y * 8;
		y16 = y8 * 2;
		ofs[0] = mpv->mb_x * 8 + y8 * out->cpitch;
		ofs[1] = mpv->mb_x * 16 + y16 * out->ypitch;
		mpvumc_PpicSkipMb(ofs, out, ref);
		mpv->mb_x++;
		if (mpv->mb_x >= mpv->mb_width) {
			mpv->mb_x = 0;
			mpv->mb_y++;
		}
		mpv->mb_addr++;
	}
}

/* average the two predictions in oi[] with the IDCT blocks into the output blocks oi_rt[] */
void mpvumc_BiMakeMb(MPVUMC_WORK *wk, MPVUMC_OUTBLK *ob, Sint32 cbp)
{
	
}

/* add the IDCT blocks to the prediction in oi[] into the output blocks oi_rt[] */
void mpvumc_OneMakeMb(MPVUMC_WORK *wk, MPVUMC_OUTBLK *ob, Sint32 cbp)
{
	
}

/* one reference's prediction of the macroblock into dst (two 8x8 chroma blocks, one 16x16 luma
 * block) through the half-pel kernels selected by the motion vector; ofs[] receives the
 * macroblock's chroma/luma offsets in the frame. Declaration order = the target's callee-saved
 * order (cpitch r31 .. fn_y r25; the two-definition chx/yhx are computed before the first call).
 * The `(Uint32)vx & 1` / `(Uint32)cvx & 1` casts keep yhx/chx apart from the kernel indices (the
 * frontend CSEs identical expressions): yhx r24 / chx r23 as the target. Statement order = the
 * target's issue order: `srawi vx>>1`/`srawi vy>>1` are the 3rd/6th instructions after the vector
 * loads, so ypos is written before `cvx = vx / 2` (with `lwz ofs[1]` before `lwz ofs[0]`); the sums
 * are `ofs + (v >> 1) + mul` (target `add r29, cvx>>1, mul`); the luma `src2` is `ypitch + yhx + src`
 * (the add chain rule `a + b + c` -> `t = b + c; r = a + t` puts ypitch first: target `add r0, yhx,
 * src; add r0, ypitch, r0`). CRI pass 23/27/31: 68 -> 56 -> 48w. The first definitions `yhx = vx & 1`
 * / `chx = cvx & 1` are written BEFORE the fn_y / fn_c table loads: a range-split web is kept (not
 * sunk into `&= mcflag`) only when a load statement sits between its two definitions, which gives
 * the target's `clrlwi r24, vx; .. and r24, r24, mcflag` / `clrlwi r23; and r23, r23` own-register
 * pairs (chx r23 = target). CRI pass 68: 48 -> 11w. The chroma half-vectors are NOT own locals but
 * the frontend's CSE temps of `vx / 2` / `vy / 2`, first evaluated inside the cpos expression: the
 * target's six `srawi` (XER writers, serialised in statement order by the scheduler) come as
 * `vx>>1, vy>>1, cvx, cvx>>1, cvy, cvy>>1`, which only `((vx / 2) >> 1) + ((vy / 2) >> 1) * cpitch`
 * produces (`cvx = vx / 2; cvy = vy / 2;` gives cvx, cvy, cvx>>1, cvy>>1). As @temps they are
 * coloured before the own locals (cvx r28 / cvy r7), and vx then dies into fn_y's r25 as the
 * target. `mby8`/`mby16` as own locals give the target's `mullw r0, mby8, cpitch` operand order
 * (CRI pass 18b). `mbx8 = mbx * 8` is a two-use own local declared LAST (`ofs[1]` uses `mbx8 * 2`,
 * which the peephole folds back into `slwi mbx,4`): with the lowest vid it is coloured after mby /
 * mbx and takes r12 (r10/r11 = mby/mbx), where a single-use `mbx * 8` is a backend temp coloured
 * before them (r10, pushing mby/mbx to r11/r12). 11 -> 0w, IDENTICAL. */
void mpvumc_OneReadMb(MPVUMC_OBJ *mpv, Uint8 *dst, Sint32 *ofs, MPVUMC_RFB *rfb, MPV_MV *mv)
{
	Sint32 cpitch;
	Sint32 ypitch;
	Sint32 cpos;
	Sint32 ypos;
	MPVMC *mc = (MPVMC *)mpv->pad_mc;
	MPVUMC_MCFUNC fn_c;
	MPVUMC_MCFUNC fn_y;
	Sint32 yhx;
	Sint32 chx;
	Uint8 *src;
	Sint32 vy;
	Sint32 vx;
	Sint32 mby;
	Sint32 mbx;
	MPVUMC_MCFUNC (*tbl_c)[2];
	MPVUMC_MCFUNC (*tbl_y)[2];
	Sint32 mcflag;
	Sint32 mby8;
	Sint32 mby16;
	Sint32 mbx8;

	mby = mpv->mb_y;
	cpitch = rfb->cpitch;
	mbx = mpv->mb_x;
	mcflag = mpv->mcflag;
	ypitch = rfb->ypitch;
	mby8 = mby * 8;
	mbx8 = mbx * 8;
	ofs[0] = mbx8 + mby8 * cpitch;
	mby16 = mby * 16;
	ofs[1] = mbx8 * 2 + mby16 * rfb->ypitch;
	tbl_y = mpvumc_oneref_y[mcflag];
	tbl_c = mpvumc_oneref[mcflag];
	vx = mv->vec[0];
	vy = mv->vec[1];
	ypos = ofs[1] + (vx >> 1) + (vy >> 1) * ypitch;
	yhx = (Uint32)vx & 1;
	fn_y = tbl_y[vy & 1][vx & 1];
	cpos = ofs[0] + ((vx / 2) >> 1) + ((vy / 2) >> 1) * cpitch;
	chx = (Uint32)(vx / 2) & 1;
	fn_c = tbl_c[(vy / 2) & 1][(vx / 2) & 1];
	chx &= mcflag;
	yhx &= mcflag;
	mc->stride = cpitch;
	mc->dst = (Uint32 *)dst;
	src = rfb->pln[0] + cpos;
	mc->src = src;
	mc->src2 = src + cpitch + chx;
	fn_c(mc);
	mc->dst = (Uint32 *)(dst + 0x40);
	src = rfb->pln[1] + cpos;
	mc->src = src;
	mc->src2 = src + cpitch + chx;
	fn_c(mc);
	mc->stride = ypitch;
	mc->dst = (Uint32 *)(dst + 0x80);
	src = rfb->pln[2] + ypos;
	mc->src = src;
	mc->src2 = ypitch + yhx + src;
	fn_y(mc);
}

/* the output block pointers of the current macroblock (two chroma blocks, four luma blocks) */
#define MPVUMC_SET_OUT_BLOCKS(mpv, ob, cofs, yofs, ypitch)                                     \
	(ob)->rt[0].p = (mpv)->out_pln[0] + (cofs);                                            \
	(ob)->rt[1].p = (mpv)->out_pln[1] + (cofs);                                            \
	(ob)->rt[2].p = (mpv)->out_pln[2] + (yofs);                                            \
	(ob)->rt[3].p = (Uint8 *)(ob)->rt[2].p + 8;                                            \
	(ob)->rt[4].p = (Uint8 *)(ob)->rt[2].p + (ypitch) * 8;                                 \
	(ob)->rt[5].p = (Uint8 *)(ob)->rt[4].p + 8

// Interpolated (B) macroblock: reads the forward and backward reference macroblocks with their
// vectors (half-pel kernels), sets the six output block pointers and merges both predictions with
// the IDCT residual into the output frame.
void MPVUMC_BiDirect(MPVUMC_OBJ *mpv)
{
	Sint32 ofs[2];
	MPVUMC_RFB *out = &mpv->out;
	MPVUMC_WORK *wk = &mpv->mcwk;
	MPVUMC_OUTBLK *ob;

	mpvumc_OneReadMb(mpv, mpv->mcwk.work, ofs, out, &mpv->fwd);
	mpvumc_OneReadMb(mpv, wk->work2, ofs, out + 1, &mpv->bwd);
	ob = &mpv->outblk;
	MPVUMC_SET_OUT_BLOCKS(mpv, ob, ofs[0], ofs[1], mpv->out_ypitch);
	mpvumc_BiMakeMb(wk, ob, mpv->cbp_code);
}

// Backward-predicted macroblock: reference from the next frame + residual.
void MPVUMC_Backward(MPVUMC_OBJ *mpv)
{
	Sint32 ofs[2];
	MPVUMC_WORK *wk = &mpv->mcwk;
	MPVUMC_OUTBLK *ob;

	mpvumc_OneReadMb(mpv, wk->work, ofs, &mpv->ref, &mpv->bwd);
	ob = &mpv->outblk;
	MPVUMC_SET_OUT_BLOCKS(mpv, ob, ofs[0], ofs[1], mpv->out_ypitch);
	mpvumc_OneMakeMb(wk, ob, mpv->cbp_code);
}

// Forward-predicted macroblock: reference from the previous frame + residual.
void MPVUMC_Forward(MPVUMC_OBJ *mpv)
{
	Sint32 ofs[2];
	MPVUMC_WORK *wk = &mpv->mcwk;
	MPVUMC_OUTBLK *ob;

	mpvumc_OneReadMb(mpv, wk->work, ofs, &mpv->out, &mpv->fwd);
	ob = &mpv->outblk;
	MPVUMC_SET_OUT_BLOCKS(mpv, ob, ofs[0], ofs[1], mpv->out_ypitch);
	mpvumc_OneMakeMb(wk, ob, mpv->cbp_code);
}

/* clip the six IDCT blocks of an intra macroblock into the output blocks oi_rt[] (`addi r5, 0, 6`
 * instead of `li`: the inline assembler hoists an `li` above the preceding independent `addi`) */
void mpvumc_OutputIntra6blk(Uint8 *blk, MPVUMC_OUTBLK *ob, Uint8 *clip)
{
	
}

/* the nested assignments keep x8/yofs as variables (the frontend would otherwise substitute them and
 * reassociate yofs into `(y16 * ypitch + pln) + x16`); mbx/mby own locals declared in this order */
void MPVUMC_Intra(MPVUMC_OBJ *mpv)
{
	Sint32 mbx;
	Sint32 mby;
	Sint32 x8;
	Sint32 y8;
	Sint32 cofs;
	Sint32 yofs;
	Sint32 ypitch;
	MPVUMC_OUTBLK *ob;

	x8 = (mbx = mpv->mb_x) * 8;
	y8 = (mby = mpv->mb_y) * 8;
	cofs = x8 + y8 * mpv->out_cpitch;
	yofs = mbx * 16 + mby * 16 * (ypitch = mpv->out_ypitch);
	ob = &mpv->outblk;
	MPVUMC_SET_OUT_BLOCKS(mpv, ob, cofs, yofs, ypitch);
	mpvumc_OutputIntra6blk(mpv->mcbuf, ob, mpv->clip_base);
}

/* GQR3: 8-bit unsigned loads/stores, GQR4: 16-bit signed (scale 0), GQR5: 8-bit unsigned with
 * scale 2^-63 (the 0..255 -> 0..1 range) */
void MPVUMC_SetGqr(void)
{
	
}

// Nothing to do at frame end.
void MPVUMC_EndOfFrame(MPVUMC_OBJ *mpv)
{
}

/* the output frame's planes from the picture size: chroma first (8 pixels per macroblock,
 * 32-byte aligned pitch), luma last */
void MPVUMC_InitOutRfb(MPVUMC_OBJ *mpv)
{
	Sint32 w = mpv->width;
	Sint32 h = mpv->height;
	Sint32 mbw;
	Sint32 mbh;
	Sint32 yw;
	Sint32 ypitch;
	Sint32 cpitch;
	Sint32 yh;
	Uint8 *buf = mpv->frmbuf;

	mbw = (w + 15) / 16;
	yw = mbw * 16;
	ypitch = (yw + 31) / 32 * 32;
	cpitch = (yw / 2 + 31) / 32 * 32;
	mpv->out_ypitch = ypitch;
	mpv->out_cpitch = cpitch;
	mbh = (h + 15) / 16;
	yh = mbh * 16;
	mpv->out_pln[2] = buf;
	mpv->out_pln[0] = mpv->out_pln[2] + yh * ypitch;
	mpv->out_pln[1] = mpv->out_pln[0] + yh / 2 * cpitch;
}

// Nothing to release.
void MPVUMC_Finish(void)
{
}

/* the half-pel kernel tables of the two block sizes: [mcflag][vy&1 * 2 + vx&1]; the second
 * (mcflag) set repeats the first with the four-point entry replaced by the vertical one */
void MPVUMC_Init(void)
{
	mpvumc_oneref[0][0][0] = MPVMC08_OneRef1p_TuneC;
	mpvumc_oneref[0][0][1] = MPVMC08_OneRefH2_TuneC;
	mpvumc_oneref[0][1][0] = MPVMC08_OneRefV2_TuneC;
	mpvumc_oneref[0][1][1] = MPVMC08_OneRef4p_TuneC;
	mpvumc_oneref[1][0][0] = MPVMC08_OneRef1p_TuneC;
	mpvumc_oneref[1][0][1] = MPVMC08_OneRefH2_TuneC;
	mpvumc_oneref[1][1][0] = MPVMC08_OneRefV2_TuneC;
	mpvumc_oneref[1][1][1] = MPVMC08_OneRefV2_TuneC;
	mpvumc_oneref_y[0][0][0] = MPVMC16_OneRef1p_TuneC;
	mpvumc_oneref_y[0][0][1] = MPVMC16_OneRefH2_TuneC;
	mpvumc_oneref_y[0][1][0] = MPVMC16_OneRefV2_TuneC;
	mpvumc_oneref_y[0][1][1] = MPVMC16_OneRef4p_TuneC;
	mpvumc_oneref_y[1][0][0] = MPVMC16_OneRef1p_TuneC;
	mpvumc_oneref_y[1][0][1] = MPVMC16_OneRefH2_TuneC;
	mpvumc_oneref_y[1][1][0] = MPVMC16_OneRefV2_TuneC;
	mpvumc_oneref_y[1][1][1] = MPVMC16_OneRefV2_TuneC;
}
