/* CRI Sofdec MPEG video: macroblock layer of a slice (I/P/B/D pictures). The slice data is read with
 * the two-word bit reader (mpv_bit.h); its state lives in the MPV object while the coefficient and
 * motion compensation callbacks run. Every 0x800 bytes the consumed part of the chunk is returned to
 * the stream joint and the reader restarted on the remainder. */
#include "cri_xpt.h"
#include "sj.h"
#include "mpv.h"
#include "mpv_bit.h"

#define MPVDEC_MBT_INTRA 0x01
#define MPVDEC_MBT_PATTERN 0x02
#define MPVDEC_MBT_BACKWARD 0x04
#define MPVDEC_MBT_FORWARD 0x08
#define MPVDEC_MBT_QUANT 0x10
#define MPVDEC_MBT_FIXED 0x20 /* macroblock_type already given by the address increment table */

#define MPVDEC_MBAI_STUFFING 34
#define MPVDEC_MBAI_ESCAPE 35
#define MPVDEC_MBAI_ERROR 36

#define MPVDEC_ERR (Uint32)-2

#define MPVDEC_REFILL_SIZE 0x800

extern Sint16 *mpvvlc_mbai_i_0;
extern Sint16 *mpvvlc_mbai_i_1;
extern Sint16 *mpvvlc_mbai_p_0;
extern Sint16 *mpvvlc_mbai_p_1;
extern Sint16 *mpvvlc_mbai_b_0;
extern Sint16 *mpvvlc_mbai_b_1;
extern Sint16 *mpvvlc_p_mbtype;
extern Sint16 *mpvvlc_b_mbtype;
extern Sint16 *mpvvlc_cbp;
extern Sint16 *mpvvlc_motion_0;
extern Sint16 *mpvvlc_motion_1;
extern int strcmp(const char *a, const char *b);

Sint32 MPV_GoNextDelimSj(SJ sj);
Sint32 mpvdec_MotionSub(MPV mpv, MPV_MV *mv, Sint32 *vec, Sint32 *pred);

#define MPVDEC_RESET_DC(mpv)                                                                   \
	(mpv)->dcpred[0] = 0x400;                                                              \
	(mpv)->dcpred[2] = 0x400;                                                              \
	(mpv)->dcpred[1] = 0x400

#define MPVDEC_RESET_MV(mv)                                                                    \
	(mv)->pred[0] = 0;                                                                     \
	(mv)->pred[1] = 0;                                                                     \
	(mv)->vec[0] = 0;                                                                      \
	(mv)->vec[1] = 0

#define MPVDEC_SAVE(mpv)                                                                       \
	(mpv)->bbuf = bbuf;                                                                    \
	(mpv)->nbuf = nbuf;                                                                    \
	(mpv)->bitpos = bitpos;                                                                \
	(mpv)->bitptr = ptr

#define MPVDEC_LOAD(mpv)                                                                       \
	bbuf = (mpv)->bbuf;                                                                    \
	nbuf = (mpv)->nbuf;                                                                    \
	bitpos = (mpv)->bitpos;                                                                \
	ptr = (mpv)->bitptr

/* start reading the slice data of the chunk at bit offset `ofs` */
#define MPVDEC_START(mpv, ofs)                                                                 \
	MPVBIT_INIT((mpv)->ck.data);                                                           \
	MPVBIT_SKIP(ofs)

/* macroblock_address_increment: returns the increment in `n` (MPVDEC_ERR on error) and sets the
 * macroblock_type given by the table */
#define MPVDEC_MBAI(mpv, tbl0, tbl1, nbit, hibit)                                              \
	mba0 = (mpv)->mb_addr;                                                                 \
	for (;;) {                                                                             \
		MPVBIT_PEEK(code, nbit);                                                       \
		if ((code >> (hibit)) == 0) {                                                  \
			val = tbl0[code];                                                      \
		} else {                                                                       \
			val = tbl1[code >> 6];                                                 \
		}                                                                              \
		len = val & 0xF;                                                               \
		MPVBIT_SKIP(len);                                                              \
		inc = (Uint8)(val >> 2) >> 2;                                                  \
		if (inc == MPVDEC_MBAI_STUFFING) {                                             \
			continue;                                                              \
		}                                                                              \
		if (inc == MPVDEC_MBAI_ESCAPE) {                                               \
			(mpv)->mb_addr += 33;                                                  \
			continue;                                                              \
		}                                                                              \
		if (inc == MPVDEC_MBAI_ERROR) {                                                \
			n = MPVDEC_ERR;                                                        \
			break;                                                                 \
		}                                                                              \
		(mpv)->mb_addr += inc;                                                         \
		(mpv)->mbtype = val >> 10;                                                     \
		if ((mpv)->mb_addr > (mpv)->mb_last) {                                         \
			n = MPVDEC_ERR;                                                        \
			break;                                                                 \
		}                                                                              \
		n = (mpv)->mb_addr - mba0;                                                     \
		(mpv)->mb_x += n;                                                              \
		while ((mpv)->mb_x >= (mpv)->picatr.mb_width) {                                \
			(mpv)->mb_x -= (mpv)->picatr.mb_width;                                 \
			(mpv)->mb_y++;                                                         \
		}                                                                              \
		break;                                                                         \
	}

/* macroblock_type (when not implied by the address increment) */
#define MPVDEC_MBTYPE(mpv, tbl, nbit)                                                          \
	if (((mpv)->mbtype & MPVDEC_MBT_FIXED) == 0) {                                         \
		MPVBIT_PEEK(code, nbit);                                                       \
		val = tbl[code];                                                               \
		(mpv)->mbtype = val >> 8;                                                      \
		MPVBIT_SKIP((Uint8)val);                                                       \
	}

#define MPVDEC_QUANT(mpv)                                                                      \
	if ((mpv)->mbtype & MPVDEC_MBT_QUANT) {                                                \
		MPVBIT_GET(val, 5);                                                            \
		(mpv)->qscale = val;                                                           \
	}

#define MPVDEC_CBP(mpv)                                                                        \
	if ((mpv)->mbtype & MPVDEC_MBT_PATTERN) {                                              \
		MPVBIT_PEEK(code, 9);                                                          \
		val = mpvvlc_cbp[code];                                                        \
		(mpv)->cbp_code = (val >> 4) << 20;                                            \
		MPVBIT_SKIP((Uint8)val);                                                       \
	} else {                                                                               \
		(mpv)->cbp_code = 0;                                                           \
	}

/* the per-macroblock callback (cond[8](cond[9]) every cond[7] macroblocks) */
#define MPVDEC_MBCB(mpv)                                                                       \
	if (--(mpv)->x1324 <= 0) {                                                             \
		(mpv)->x1324 = (mpv)->cond[7];                                                 \
		((void (*)(Sint32))(mpv)->cond[8])((mpv)->cond[9]);                            \
	}

/* return the consumed part of the chunk once more than MPVDEC_REFILL_SIZE bytes are used and go on
 * with the rest */
#define MPVDEC_REFILL(mpv, sj)                                                                 \
	bofs = bitpos & 7;                                                                     \
	q = (Uint8 *)ptr;                                                                      \
	q += (bitpos - bofs + 7) >> 3;                                                         \
	q -= 8;                                                                                \
	if ((mpv)->ck.len - (q - (mpv)->ck.data) <= MPVDEC_REFILL_SIZE) {                      \
		SJCK rest;                                                                     \
		SJ_SplitChunk(&(mpv)->ck, q - (mpv)->ck.data, &(mpv)->ck, &rest);              \
		SJ_PutChunk(sj, SJ_CK_FREE, &(mpv)->ck);                                       \
		SJ_UngetChunk(sj, SJ_CK_DATA, &rest);                                          \
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &(mpv)->ck);                           \
		MPVDEC_START(mpv, bofs);                                                       \
	}

/* end of slice: return the consumed bytes, skip to the next start code. The byte pointer is
 * `(Uint8 *)(ptr - 2) + n` as in mpv_hdec's MPVHDEC_BYTEPTR_M2: the codegen emits `(ptr + n) - 8` with
 * the sum a backend temporary created after the `ck.data` load (target `lwz r8; add r4; subi r0, r4,
 * 8; subf r4, r8, r0`), while MPVBIT_BYTEPTR's `q = ptr; q += n; q -= 8` reuses the dying argument
 * register in place. */
#define MPVDEC_END(mpv, sj)                                                                    \
	{                                                                                      \
		SJCK rest;                                                                     \
		q = (Uint8 *)(ptr - 2) + ((bitpos + 7) >> 3);                                  \
		SJ_SplitChunk(&(mpv)->ck, q - (mpv)->ck.data, &(mpv)->ck, &rest);              \
		SJ_PutChunk(sj, SJ_CK_FREE, &(mpv)->ck);                                       \
		SJ_UngetChunk(sj, SJ_CK_DATA, &rest);                                          \
	}                                                                                      \
	return MPV_GoNextDelimSj(sj)

// Slice macroblock loop of a D picture (DC-only intra): address increments, intra DC decode,
// output of each macroblock until the slice's 23 zero bits.
Sint32 MPVDEC_DecDpicMb(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 *ptr;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 inc;
	Uint32 n;
	Sint32 mba0;
	Sint32 bofs;
	Uint8 *q;

	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVDEC_START(mpv, mpv->bitofs);
	for (;;) {
		MPVBIT_PEEK(val, 23);
		if (val == 0) {
			break;
		}
		MPVDEC_MBAI(mpv, mpvvlc_mbai_i_0, mpvvlc_mbai_i_1, 12, 8);
		if (n == MPVDEC_ERR) {
			break;
		}
		MPVDEC_SAVE(mpv);
		mpv->intra_blocks(mpv);
		mpv->mc_intra_func(mpv);
		MPVDEC_MBCB(mpv);
		MPVDEC_LOAD(mpv);
		MPVBIT_GET1(val);
		if (val != 1) {
			break;
		}
		MPVDEC_REFILL(mpv, sj);
	}
	MPVDEC_END(mpv, sj);
}

// Slice macroblock loop of a B picture: macroblock_type (intra / forward / backward / interpolated /
// quant / pattern), both motion vectors with their predictors, coded block pattern, coefficient
// decode and the two-reference motion compensation; skipped macroblocks repeat the last vectors.
Sint32 MPVDEC_DecBpicMb(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 *ptr;
	Sint32 first;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 inc;
	Uint32 n;
	Sint32 mba0;
	Sint32 bofs;
	Sint32 ret;
	Sint32 ret2;
	Uint8 *q;

	first = 1;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVDEC_START(mpv, mpv->bitofs);
	for (;;) {
		MPVBIT_PEEK(val, 23);
		if (val == 0) {
			break;
		}
		MPVDEC_MBAI(mpv, mpvvlc_mbai_b_0, mpvvlc_mbai_b_1, 11, 7);
		if (n == MPVDEC_ERR) {
			break;
		}
		if (first == 0 && n > 1) {
			mpv->skip_func(mpv);
			MPVDEC_RESET_DC(mpv);
		}
		MPVDEC_MBTYPE(mpv, mpvvlc_b_mbtype, 6);
		MPVDEC_QUANT(mpv);
		if (mpv->mbtype & MPVDEC_MBT_FORWARD) {
			MPVDEC_SAVE(mpv);
			ret = mpvdec_MotionSub(mpv, &mpv->fwd, &mpv->fwd.vec[0], &mpv->fwd.pred[0]);
			ret2 = mpvdec_MotionSub(mpv, &mpv->fwd, &mpv->fwd.vec[1], &mpv->fwd.pred[1]);
			MPVDEC_LOAD(mpv);
			if (ret | ret2) {
				break;
			}
		}
		if (mpv->mbtype & MPVDEC_MBT_BACKWARD) {
			MPVDEC_SAVE(mpv);
			ret = mpvdec_MotionSub(mpv, &mpv->bwd, &mpv->bwd.vec[0], &mpv->bwd.pred[0]);
			ret2 = mpvdec_MotionSub(mpv, &mpv->bwd, &mpv->bwd.vec[1], &mpv->bwd.pred[1]);
			MPVDEC_LOAD(mpv);
			if (ret | ret2) {
				break;
			}
		}
		MPVDEC_CBP(mpv);
		MPVDEC_SAVE(mpv);
		if (mpv->mbtype & MPVDEC_MBT_INTRA) {
			mpv->intra_blocks(mpv);
			mpv->mc_intra_func(mpv);
			MPVDEC_RESET_MV(&mpv->fwd);
			MPVDEC_RESET_MV(&mpv->bwd);
		} else {
			mpv->mc_func[0] = mpv->mc_func[(mpv->mbtype & (MPVDEC_MBT_FORWARD | MPVDEC_MBT_BACKWARD)) >> 2];
			if (mpv->cbp_code != 0) {
				mpv->nintra_blocks(mpv);
			}
			mpv->mc_func[0](mpv);
			MPVDEC_RESET_DC(mpv);
		}
		MPVDEC_MBCB(mpv);
		MPVDEC_LOAD(mpv);
		MPVDEC_REFILL(mpv, sj);
		first = 0;
	}
	MPVDEC_END(mpv, sj);
}

/* one motion vector component; returns -1 on an invalid code */
Sint32 mpvdec_MotionSub(MPV mpv, MPV_MV *mv, Sint32 *vec, Sint32 *pred)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 *ptr;
	Sint32 ret;
	Uint32 code;
	Sint32 mcode;
	Uint32 val;
	Sint32 len;
	Sint32 res;
	Sint32 r_size;
	Sint32 shift;
	Sint32 delta;

	ret = 0;
	MPVDEC_LOAD(mpv);
	r_size = mv->r_size;
	shift = mv->shift;
	MPVBIT_PEEK(code, 11);
	if ((code >> 7) == 0) {
		val = mpvvlc_motion_0[code];
	} else {
		val = mpvvlc_motion_1[code >> 6];
	}
	mcode = (Sint8)val;
	if (mcode == 0x7F) {
		ret = -1;
	} else {
		len = (Uint8)(val >> 8);
		MPVBIT_SKIP(len);
		if (mcode == 0) {
			*vec = *pred;
		} else {
			if (r_size != 0) {
				MPVBIT_GET(res, r_size);
				delta = mv->f - 1 - res;
				mcode <<= r_size;
				if (mcode > 0) {
					mcode -= delta;
				} else {
					mcode += delta;
				}
			}
			mcode += *pred;
			*vec = (mcode << shift) >> shift;
			*pred = *vec;
		}
		if (mv->full_pel) {
			*vec <<= 1;
		}
	}
	MPVDEC_SAVE(mpv);
	return ret;
}

// Resets the three intra DC predictors (slice start, non-intra macroblock).
void MPVDEC_ResetDc(MPV mpv)
{
	MPVDEC_RESET_DC(mpv);
}

// Resets a motion vector predictor pair (slice start, intra / skipped macroblock).
void MPVDEC_ResetMv(MPV_MV *mv)
{
	MPVDEC_RESET_MV(mv);
}

// Slice macroblock loop of a P picture: macroblock_type, forward vector with predictor, coded block
// pattern, coefficients and forward motion compensation; skipped macroblocks copy the reference.
Sint32 MPVDEC_DecPpicMb(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 *ptr;
	Sint32 first;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 inc;
	Uint32 n;
	Sint32 mba0;
	Sint32 bofs;
	Sint32 ret;
	Sint32 ret2;
	Uint8 *q;

	first = 1;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVDEC_START(mpv, mpv->bitofs);
	for (;;) {
		MPVBIT_PEEK(val, 23);
		if (val == 0) {
			break;
		}
		MPVDEC_MBAI(mpv, mpvvlc_mbai_p_0, mpvvlc_mbai_p_1, 11, 7);
		if (n == MPVDEC_ERR) {
			break;
		}
		if (first == 0 && n > 1) {
			mpv->skip_func(mpv);
			MPVDEC_ResetMv(&mpv->fwd);
			MPVDEC_ResetDc(mpv);
		}
		MPVDEC_MBTYPE(mpv, mpvvlc_p_mbtype, 5);
		MPVDEC_QUANT(mpv);
		if (mpv->mbtype & MPVDEC_MBT_FORWARD) {
			MPVDEC_SAVE(mpv);
			ret = mpvdec_MotionSub(mpv, &mpv->fwd, &mpv->fwd.vec[0], &mpv->fwd.pred[0]);
			ret2 = mpvdec_MotionSub(mpv, &mpv->fwd, &mpv->fwd.vec[1], &mpv->fwd.pred[1]);
			MPVDEC_LOAD(mpv);
			if (ret | ret2) {
				break;
			}
		} else {
			MPVDEC_ResetMv(&mpv->fwd);
		}
		MPVDEC_CBP(mpv);
		MPVDEC_SAVE(mpv);
		if (mpv->mbtype & MPVDEC_MBT_INTRA) {
			mpv->intra_blocks(mpv);
			mpv->mc_intra_func(mpv);
		} else {
			if (mpv->cbp_code != 0) {
				mpv->nintra_blocks(mpv);
			}
			mpv->mc_func[2](mpv);
			MPVDEC_ResetDc(mpv);
		}
		MPVDEC_MBCB(mpv);
		MPVDEC_LOAD(mpv);
		MPVDEC_REFILL(mpv, sj);
		first = 0;
	}
	MPVDEC_END(mpv, sj);
}

// Slice macroblock loop of an I picture: address increment, optional quantiser scale, intra block
// decode and intra output; ends at the slice's 23 zero bits.
Sint32 MPVDEC_DecIpicMb(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 *ptr;
	Uint32 val;
	Uint32 code;
	Sint32 len;
	Sint32 inc;
	Uint32 n;
	Sint32 mba0;
	Sint32 bofs;
	Uint8 *q;

	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVDEC_START(mpv, mpv->bitofs);
	for (;;) {
		MPVBIT_PEEK(val, 23);
		if (val == 0) {
			break;
		}
		MPVDEC_MBAI(mpv, mpvvlc_mbai_i_0, mpvvlc_mbai_i_1, 12, 8);
		if (n == MPVDEC_ERR) {
			break;
		}
		MPVDEC_QUANT(mpv);
		MPVDEC_SAVE(mpv);
		mpv->intra_blocks(mpv);
		mpv->mc_intra_func(mpv);
		MPVDEC_MBCB(mpv);
		MPVDEC_LOAD(mpv);
		MPVDEC_REFILL(mpv, sj);
	}
	MPVDEC_END(mpv, sj);
}

// Library/header compatibility: version string "1.933" and the MPV_OBJ / MPV_PICATR sizes.
Sint32 MPVDEC_CheckVersion(const Char8 *ver, Sint32 objsiz, Sint32 picatrsiz)
{
	if (strcmp("1.933", ver) != 0) {
		return -1;
	}
	if (objsiz != sizeof(MPV_OBJ)) {
		return -1;
	}
	if (picatrsiz != sizeof(MPV_PICATR)) {
		return -1;
	}
	return 0;
}
