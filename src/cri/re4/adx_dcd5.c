/* ADX 4-bit decoder (adx_dcd5.c): 18-byte frames of a 2-byte scale and 32 nibbles, second-order
 * prediction with the coefficients c1/c2 (12-bit fixed point); the scale header is descrambled
 * with the running key *scl (key = key * smul + sadd). Stereo frames are interleaved (L, R). */
#include "cri_xpt.h"

extern Sint32 adx_decode_output_mono_flag;

#define ADX_CLAMP(v) \
	if ((v) > 0x7FFF || (v) < -0x8000) { \
		if ((v) < -0x8000) { \
			(v) = -0x8000; \
		} else if ((v) > 0x7FFF) { \
			(v) = 0x7FFF; \
		} \
	}

const Sint32 AdxQtbl[16] = {
	0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1,
};

Sint32 ADX_DecodeSte4AsSte(Sint8 *src, Sint32 nfrm, Sint16 *outl, Sint16 *histl, Sint16 *outr, Sint16 *histr,
                           Sint16 c1, Sint16 c2, Sint16 *scl, Sint16 smul, Sint16 sadd);
Sint32 ADX_DecodeSte4AsMono(Sint8 *src, Sint32 nfrm, Sint16 *outl, Sint16 *histl, Sint16 *outr, Sint16 *histr,
                            Sint16 c1, Sint16 c2, Sint16 *scl, Sint16 smul, Sint16 sadd);

// Decodes `nfrm` interleaved stereo 4-bit ADX frames; with adx_decode_output_mono_flag set
// (ADXT_SetOutputMono(1), the game's mono option) both channels get the L+R mix instead.
// FUN_004C6990
Sint32 ADX_DecodeSte4(Sint8 *src, Sint32 nfrm, Sint16 *outl, Sint16 *histl, Sint16 *outr, Sint16 *histr,
                      Sint16 c1, Sint16 c2, Sint16 *scl, Sint16 smul, Sint16 sadd)
{
	if (adx_decode_output_mono_flag == 0) {
		return ADX_DecodeSte4AsSte(src, nfrm, outl, histl, outr, histr, c1, c2, scl, smul, sadd);
	}
	return ADX_DecodeSte4AsMono(src, nfrm, outl, histl, outr, histr, c1, c2, scl, smul, sadd);
}

/* COMPILER-DIFF: M1 - register ranking of the 4-bit decode loop (115 words): the original keeps
 * c1/c2 extended in place (r9/r10), the table pointer in r22 below sc_l/sc_r, one callee-saved
 * register less (r19..r31) and hands r21 out before t (r20) and nblk (r19). The scales are Sint16
 * locals (the extsh is their definition, as in ADX_DecodeMono4), the table values are the last-
 * declared locals defined before the stores, the declaration order is the original's colouring
 * order (pass 34: chaitin.py reproduces the target up to the r21 node once the nfrm ghost is gone).
 * Pass 72: the table is indexed directly (its address is the backend's hoisted preheader temporary,
 * coloured r22 after sc_r like the original's). Pass 73: the original's graph keeps the c1/c2
 * parameter copies (two coalesced ghosts dying at the widening `extsh`, one more neighbour on the
 * entry-block values sadd/smul/scl/nblk/l1/l2/rr1/rr2), which is what puts sadd/smul in the top level
 * (r0/r11) with all three stack loads before the `add`; the table value is written back into the
 * nibble (`d = AdxQtbl[d & 0xF]`, a range-split web) as in the mono decoder. Pass 78: the original
 * pops the `c1 * t` product of the right channel's second sample before `c2 * rr1` (one more
 * neighbour on it), reproduced by the `x` copy of `t` below (3 -> 0 words). The pass-44 ``
 * neighbour pin is redundant since pass 73 (removed, bytes unchanged); the c1/c2 writes are not: they need
 * the register of a parameter live across the loop (r6 histl or r8 histr give the same bytes, every other
 * volatile shifts the colouring), so they are not a swappable codeless neighbour pin. */
Sint32 ADX_DecodeSte4AsSte(Sint8 *src, Sint32 nfrm, Sint16 *outl, Sint16 *histl, Sint16 *outr, Sint16 *histr,
                           register Sint16 c1, register Sint16 c2, Sint16 *scl, Sint16 smul, Sint16 sadd)
{
	Sint32 l2;
	Sint32 rr2;
	Sint32 rr1;
	Sint32 l1;
	Sint32 i;
	Sint32 d;
	Sint32 dr;
	Sint16 sc_l;
	Sint16 sc_r;
	Sint32 s;
	Sint32 t;
	Sint32 nblk;
	Sint32 key;
	Sint32 j;
	Sint32 x;

	nblk = nfrm / 2;
	/* COMPILER-DIFF: M1 (kept parameter copies) - dead writes into the already pinned r6: the copies
	 * `mr r38,r9` / `mr r39,r10` survive to the allocator and coalesce into r9/r10 (pass 73: 11 -> 3
	 * words; r6 is already out of the colour set, so nothing else moves and both writes are deleted). */
	 
	l1 = histl[0];
	l2 = histl[1];
	rr1 = histr[0];
	rr2 = histr[1];
	for (i = 0; i < nblk; i++) {
		s = *(Sint16 *)src;
		if (s & 0x8000) {
			return i * 2;
		}
		key = *scl;
		sc_l = ((s ^ key) & 0x1FFF) + 1;
		key = sadd + key * smul;
		*scl = key;
		*scl = *scl & 0x7FFF;
		s = *(Sint16 *)(src + 0x12);
		if (s & 0x8000) {
			return i * 2;
		}
		key = *scl;
		sc_r = ((s ^ key) & 0x1FFF) + 1;
		key = sadd + key * smul;
		*scl = key;
		*scl = *scl & 0x7FFF;
		src += 2;
		for (j = 0; j < 16; j++) {
			d = src[0];
			dr = src[0x12];
			src++;
			l2 = (d >> 4) * sc_l + ((c1 * l1 + c2 * l2) >> 12);
			ADX_CLAMP(l2);
			t = (dr >> 4) * sc_r;
			t += (c1 * rr1 + c2 * rr2) >> 12;
			ADX_CLAMP(t);
			d = AdxQtbl[d & 0xF];
			outl[0] = l2;
			dr = AdxQtbl[dr & 0xF];
			outr[0] = t;
			l1 = d * sc_l + ((c1 * l2 + c2 * l1) >> 12);
			ADX_CLAMP(l1);
			/* The second sample's `c1 * t` product must be coloured before `c2 * rr1` (one more
			 * neighbour, pass 78). The cast keeps the frontend from substituting the copy; `t` has
			 * three reaching definitions (the clamp), so the backend keeps `mr x, t` too; `x` takes
			 * the dying `t`'s register and the `mr r20,r20` is deleted after allocation: `x` is a
			 * real node live across both products, `rr2 = x` is the original's `mr r30,r20`. */
			x = (Sint32)(Uint32)t;
			rr1 = dr * sc_r + ((c1 * x + c2 * rr1) >> 12);
			ADX_CLAMP(rr1);
			outl[1] = l1;
			rr2 = x;
			outl += 2;
			outr[1] = rr1;
			outr += 2;
		}
		src += 0x12;
	}
	histl[0] = l1;
	histl[1] = l2;
	histr[0] = rr1;
	histr[1] = rr2;
	return nfrm;
}

/* COMPILER-DIFF: M1 - the pass-44/67 `` neighbour pin after the loop is redundant since
 * pass 81 (removed, bytes unchanged); the five r6 writes below remain (r6 histl / r8 histr only, see
 * ADX_DecodeSte4AsSte). The body is the stereo body with the mix in `t` (the original keeps `mr r31,r21` = rr2 = t and the
 * mix in t's register, so t is redefined between the copy and `c1 * rr2`), the same declaration
 * order as the stereo decoder, and the right channel's second sample predicted from the OLD rr1
 * (`c2 * rr1` = `mullw r26,r10,r30` in the original; the pass-44 split read the new one). Pass 73:
 * the c1/c2 parameter copies are kept as in the stereo decoder (the two `lis` pairs then colour like
 * the original's), and the table value is written back into the nibble (`d = AdxQtbl[d & 0xF]`): a
 * range-split web of a variable first defined before `t`, so it is coloured before the first mix
 * (q_l r20, the mix r21). Pass 80: the l1 statement's shift is an own local `sh` read once more in a
 * dead conditional inside the l1 clamp (see the M1 comment there): its `addi` marks `sh` no-r0 = one
 * never-removed neighbour, so the shift is coloured before the `d * sc_l` product (5 -> 2 words).
 * Pass 81: the `nfrm / 2` add temporary is r12 in the original = the entry block issued the scl,
 * smul and sadd loads before the `srawi` and the hist loads after it, with the two pool `lis`
 * before the sadd load (they keep the argument-base pair as neighbours and stay spill picks:
 * magic r20, table r21). Reproduced with the dead consumers below (see the M1 comment there;
 * 2 -> 0 words, 4/4). */
Sint32 ADX_DecodeSte4AsMono(Sint8 *src, Sint32 nfrm, Sint16 *outl, Sint16 *histl, Sint16 *outr, Sint16 *histr,
                            register Sint16 c1, register Sint16 c2, register Sint16 *scl, register Sint16 smul, Sint16 sadd)
{
	Sint32 l2;
	Sint32 rr2;
	Sint32 rr1;
	Sint32 l1;
	Sint32 i;
	Sint32 d;
	Sint32 dr;
	Sint16 sc_l;
	Sint16 sc_r;
	Sint32 s;
	Sint32 t;
	register Sint32 nblk;
	register Sint32 x;
	register Sint32 y;
	Sint32 key;
	Sint32 j;
	Sint16 *ps;
	Sint32 sh;
	Sint32 sum;
	Sint32 pq;
	Sint32 z;

	nblk = nfrm / 2;
	/* CRI pass 70: the scramble addend is read through its address, so its loop value is the
	 * hoisted load (a backend temporary above the c1/c2 widenings in the Chaitin scan) instead
	 * of the entry load of the stack parameter (62 -> 28 words). */
	ps = &sadd;
	/* COMPILER-DIFF: M1 (dead consumers, entry-block order) - `x`, `y` and the five r6 writes are
	 * dead and deleted by the allocator (no code, r6 is the pinned register). Pass 81: `x = c2 + *ps`
	 * reads the addend once in this block, so the loop's hoisted load is CSE'd into this backend
	 * temporary (the sadd node keeps its level, r0) and the load is scheduled here: it waits for
	 * c2's widening (its other operand), so it is issued after the two pool `lis` (they keep the
	 * argument-base pair as neighbours -> spill picks -> magic r20, table r21) and before the
	 * `srawi` (the add temporary is adjacent to sadd -> r12), the hist loads follow. `y` gives the
	 * scl/smul loads a consumer (issued first, in parameter order); the `nblk` write lifts the
	 * `srawi` above the hist loads; the c1/c2 writes are pass 73's kept parameter copies. */
	x = c2 + *ps;
	y = (Sint32)scl + smul;
	    
	l1 = histl[0];
	l2 = histl[1];
	rr1 = histr[0];
	rr2 = histr[1];
	for (i = 0; i < nblk; i++) {
		s = *(Sint16 *)src;
		if (s & 0x8000) {
			return i * 2;
		}
		key = *scl;
		sc_l = ((s ^ key) & 0x1FFF) + 1;
		key = *ps + key * smul;
		*scl = key;
		*scl = *scl & 0x7FFF;
		s = *(Sint16 *)(src + 0x12);
		if (s & 0x8000) {
			return i * 2;
		}
		key = *scl;
		sc_r = ((s ^ key) & 0x1FFF) + 1;
		key = *ps + key * smul;
		*scl = key;
		*scl = *scl & 0x7FFF;
		src += 2;
		for (j = 0; j < 16; j++) {
			d = src[0];
			dr = src[0x12];
			src++;
			l2 = (d >> 4) * sc_l + ((c1 * l1 + c2 * l2) >> 12);
			ADX_CLAMP(l2);
			t = (dr >> 4) * sc_r + ((c1 * rr1 + c2 * rr2) >> 12);
			ADX_CLAMP(t);
			rr2 = t;
			t = (l2 + t) * 7 / 10;
			ADX_CLAMP(t);
			d = AdxQtbl[d & 0xF];
			outr[0] = t;
			dr = AdxQtbl[dr & 0xF];
			outl[0] = t;
			/* COMPILER-DIFF: M1 (dead conditional) - the original colours the `>> 12` shift of this
			 * statement before the `d * sc_l` product (one more never-removed neighbour on the shift
			 * only, pass 80). The shift and the sum are own locals read once more in the dead arm
			 * below (`z = 0; if (z != 0)` reaches the allocator and is folded by the post-RA peephole,
			 * the arm's `addi rr2, sh, 1` marks `sh` no-r0 = the neighbour; `l2 = sum` keeps the sum
			 * live into the arm so it is coloured before the product as well). The arm sits inside the
			 * clamp's outer test so its block boundary splits none of the loop's blocks, and `pq`
			 * keeps the add's operand order (product, shift). */
			pq = d * sc_l;
			sum = c1 * l2 + c2 * l1;
			sh = sum >> 12;
			l1 = pq + sh;
			if (l1 > 0x7FFF || l1 < -0x8000) {
				z = 0;
				if (z != 0) {
					rr2 = sh + 1;
					l2 = sum;
				}
				if (l1 < -0x8000) {
					l1 = -0x8000;
				} else if (l1 > 0x7FFF) {
					l1 = 0x7FFF;
				}
			}
			rr1 = dr * sc_r + ((c1 * rr2 + c2 * rr1) >> 12);
			ADX_CLAMP(rr1);
			t = (l1 + rr1) * 7 / 10;
			ADX_CLAMP(t);
			outr[1] = t;
			outr += 2;
			outl[1] = t;
			outl += 2;
		}
		src += 0x12;
	}
	histl[0] = l1;
	histl[1] = l2;
	histr[0] = rr1;
	histr[1] = rr2;
	return nfrm;
}

/* The scale is a Sint16 local: its definition is the `extsh` itself (the frontend's hoisted
 * `(long)sc` in the inner-loop preheader becomes a copy of it), so the scale keeps its own-local
 * register rank; the `key = ..; *scl = key;` redefinition between the scale and the loop keeps the
 * frontend from substituting the scale into the hoist. The table value is the local `q` (declared
 * last) defined before the store, so it takes the dying nibble's register. */
Sint32 ADX_DecodeMono4(Sint8 *src, Sint32 nfrm, Sint16 *out, Sint16 *hist, Sint16 c1, Sint16 c2, Sint16 *scl,
                       Sint16 smul, Sint16 sadd)
{
	Sint32 i;
	Sint32 l2;
	Sint32 l1;
	Sint32 j;
	Sint32 s;
	Sint32 key;
	Sint16 sc;
	Sint32 d;
	Sint32 t;
	Sint32 q;

	l1 = hist[0];
	l2 = hist[1];
	for (i = 0; i < nfrm; i++) {
		s = *(Sint16 *)src;
		if (s & 0x8000) {
			return i;
		}
		key = *scl;
		sc = ((s ^ key) & 0x1FFF) + 1;
		key = sadd + key * smul;
		*scl = key;
		*scl = *scl & 0x7FFF;
		src += 2;
		for (j = 0; j < 16; j++) {
			d = src[0];
			src++;
			t = (d >> 4) * sc + ((c1 * l1 + c2 * l2) >> 12);
			ADX_CLAMP(t);
			q = AdxQtbl[d & 0xF];
			out[0] = t;
			l1 = q * sc + ((c1 * t + c2 * l1) >> 12);
			ADX_CLAMP(l1);
			out[1] = l1;
			l2 = t;
			out += 2;
		}
	}
	hist[0] = l1;
	hist[1] = l2;
	return nfrm;
}
