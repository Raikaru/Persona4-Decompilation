/* CRI Sofdec MPEG video: 16x16 block motion compensation, "tuned C" versions. One reference block
 * is copied (1p), horizontally (H2) / vertically (V2) / four-point (4p) half-pel averaged into the
 * word-packed destination (four 8x8 blocks: rows 0-7 into blocks 0/1 at d[0]/d[1] and d[16]/d[17],
 * rows 8-15 into blocks 2/3 after the +0x40 step); the source alignment selects the load strategy.
 * Pure C reconstruction of the original's instruction stream (CRI paired-single kernels pass 1): the
 * words/bytes of a row are read into variables before the stores (each byte is loaded once), the
 * 8-iteration copy loops are unrolled by the compiler (1p case 0 is the hand software-pipelined
 * two-row form), the 16-row loops keep the `i == 7` block step. Residue: instruction schedule and
 * register assignment (see docs/research/ "CRI paired-single kernels pass 1"). */
#include "cri_xpt.h"
#include "mpv.h"

/* four-point average of the pixel pairs (a, a+1) x (b, b+1), packed as four bytes */
#define MPVMC16_AVG4(p0, p1, p2, p3) \
	((((p0) << 22) & 0xFF000000) | (((p1) << 14) & 0x00FF0000) | (((p2) << 6) & 0x0000FF00) | (((p3) >> 2) & 0x000000FF))

/* byte-wise average of two packed words */
#define MPVMC16_AVG2(w, a, x) (((w) & (a)) + (((x) & 0xFEFEFEFE) >> 1) + ((x) & 0x01010101))
/* the same through mask VARIABLES (propagated to the same constants): the frontend then keeps the
 * target's association `(w & a) + (sh + (x & m2))`; with literal masks it rebuilds `sh + ((w & a) + (x & m2))` */
#define MPVMC16_AVG2V(w, a, x, m1, m2) (((w) & (a)) + (((x) & (m1)) >> 1) + ((x) & (m2)))
/* the same with the xor computed inside the macro: the frontend CSEs the two `(w) ^ (a)` into ONE @temp per pair,
 * numbered after every range-split web of the function (CRI SWAR kernels pass 19: the original's x0..x3 are such
 * temps, not variables -- the case-0 packs of the 16x16 H2 then take the original's registers) */
#define MPVMC16_AVG2X(w, a, m1, m2) (((w) & (a)) + ((((w) ^ (a)) & (m1)) >> 1) + (((w) ^ (a)) & (m2)))

// 16x16 luma block, half-pel in both directions: rounded 2x2 averages into the four 8x8 output blocks.
void MPVMC16_OneRef4p_TuneC(MPVMC *mc)
{
	/* Three rotating pixel pairs (a0/b0, a1/b1, a2/b2: pixel k lives in pair k % 3) and the sums p0..p7
	 * reused for both halves (the 9th sum is p0 again, computed after the d[1] store like a copy-pasted
	 * second half): the first webs of the pairs are own locals and every later web a range-split
	 * frontend temporary, which gives the original's register classes -- a6, a7, a2, a8 (the pixels
	 * whose degree stays >= 29 at their scan) and p2, p3, p4 form the level coloured first (r7-r12),
	 * the long-lived pixels a3/b2/a4/a5/b5 and the sums are coloured last, and the second half's
	 * sums stay variables (q/p in one register) except p6' (CRI SWAR kernels pass 12). The pixel
	 * words are declared BEFORE the sums and the loop variables (pass 10: the five loop variables
	 * must be the only nodes of the top level). The dead pixel initialisers move the pairs' range-split
	 * web groups first (CRI SWAR kernels pass 22: 30 -> 26w). Pixel 9 is loaded BEFORE the d[0]/d[1]
	 * stores: a `Uint8 *` load written after a store shares the store's alias class and cannot be
	 * scheduled above it, and the original issues both pixel-9 loads before the stores (CRI SWAR
	 * kernels pass 23: 26 -> 0w; the >100 block split is the same in both builds). */
	Uint32 a0 = 0, b0 = 0, a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	Uint32 p0, p1, p2, p3, p4, p5, p6, p7;
	Sint32 i;
	Sint32 stride;
	Uint8 *s0;
	Uint8 *s1;
	Uint32 *d;

	stride = mc->stride;
	s0 = mc->src;
	s1 = mc->src2;
	d = mc->dst;
	for (i = 0; i < 16; i++) {
		__dcbt(s1, stride);
		a0 = s0[0];
		b0 = s1[0];
		a1 = s0[1];
		b1 = s1[1];
		p0 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		a2 = s0[2];
		b2 = s1[2];
		p1 = (Uint32)a1 + (Uint32)a2 + (Uint32)b1 + (Uint32)b2 + 2;
		a0 = s0[3];
		b0 = s1[3];
		p2 = (Uint32)a2 + (Uint32)a0 + (Uint32)b2 + (Uint32)b0 + 2;
		a1 = s0[4];
		b1 = s1[4];
		p3 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		a2 = s0[5];
		b2 = s1[5];
		p4 = (Uint32)a1 + (Uint32)a2 + (Uint32)b1 + (Uint32)b2 + 2;
		a0 = s0[6];
		b0 = s1[6];
		p5 = (Uint32)a2 + (Uint32)a0 + (Uint32)b2 + (Uint32)b0 + 2;
		a1 = s0[7];
		b1 = s1[7];
		p6 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		a2 = s0[8];
		b2 = s1[8];
		p7 = (Uint32)a1 + (Uint32)a2 + (Uint32)b1 + (Uint32)b2 + 2;
		a0 = s0[9];
		b0 = s1[9];
		d[0] = MPVMC16_AVG4(p0, p1, p2, p3);
		d[1] = MPVMC16_AVG4(p4, p5, p6, p7);
		p0 = (Uint32)a2 + (Uint32)a0 + (Uint32)b2 + (Uint32)b0 + 2;
		a1 = s0[10];
		b1 = s1[10];
		p1 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		a2 = s0[11];
		b2 = s1[11];
		p2 = (Uint32)a1 + (Uint32)a2 + (Uint32)b1 + (Uint32)b2 + 2;
		a0 = s0[12];
		b0 = s1[12];
		p3 = (Uint32)a2 + (Uint32)a0 + (Uint32)b2 + (Uint32)b0 + 2;
		a1 = s0[13];
		b1 = s1[13];
		p4 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		a2 = s0[14];
		b2 = s1[14];
		p5 = (Uint32)a1 + (Uint32)a2 + (Uint32)b1 + (Uint32)b2 + 2;
		a0 = s0[15];
		b0 = s1[15];
		p6 = (Uint32)a2 + (Uint32)a0 + (Uint32)b2 + (Uint32)b0 + 2;
		a1 = s0[16];
		b1 = s1[16];
		p7 = (Uint32)a0 + (Uint32)a1 + (Uint32)b0 + (Uint32)b1 + 2;
		d[16] = MPVMC16_AVG4(p0, p1, p2, p3);
		d[17] = MPVMC16_AVG4(p4, p5, p6, p7);
		s0 += stride;
		s1 += stride;
		d += 2;
		if (i == 7) {
			d += 16;
		}
	}
}

// 16x16 luma block, horizontal half-pel average.
void MPVMC16_OneRefH2_TuneC(MPVMC *mc)
{
	/* The original's register classes (CRI SWAR kernels pass 19): the xor of every AVG is a frontend CSE
	 * temporary (xor-inside macro, no x variables); case 0 loads into w0..w3 and packs into a0..a3 with the
	 * byte `a3` declared first (its own-local web is coloured after w0/a0's = r20); cases 1/2 load the five
	 * words into their OWN locals v0..v4 (first defined here: coloured last, like the original's r22/r23
	 * words) and write the pixel word of pair k into w[(k+2)&3] and its neighbour into a[(k+2)&3]: range-
	 * split webs of case-0 variables (the base shifts coalesce into them, no `mr`) whose numbering pops
	 * pairs 2, 3, 1 in that order, as the original's r8/r9/r10 and r11/r12/r31 do; case 3 loads the aligned
	 * neighbours into a0..a3 and packs into w0..w3. Pair 1's neighbour is `a1` as well (pass 20): a copy into
	 * or out of an own local never coalesces, so it must be a web, and the earlier definition of a variable has
	 * the higher @ -- it pops right after pair 3's `a1` and takes r31 as the function's first callee-saved
	 * hand-out, before case 3's a1/a2/a3 loads hand out r31/r30/r29 and the own locals v2/v3 take r29/r30.
	 * Case 1 loads v3 before v2 so that case 2's range-split webs (numbered by first definition) pop v3 first. */
	Sint32 i;
	Uint8 *s = mc->src;
	Sint32 stride = mc->stride;
	Uint32 *d = mc->dst;
	Uint32 a3, w0, a0, w1, a1, w2, a2, w3, v0, v1, v2, v3, v4;
	Uint32 m1 = 0xFEFEFEFE;
	Uint32 m2 = 0x01010101;

	switch ((Uint32)s & 3) {
	case 0:
		for (i = 0; i < 16; i++) {
			__dcbt(s, stride);
			w0 = ((Uint32 *)s)[0];
			w1 = ((Uint32 *)s)[1];
			w2 = ((Uint32 *)s)[2];
			w3 = ((Uint32 *)s)[3];
			a0 = (w0 << 8) | (w1 >> 24);
			a1 = (w1 << 8) | (w2 >> 24);
			a2 = (w2 << 8) | (w3 >> 24);
			a3 = s[16];
			a3 = (w3 << 8) | a3;
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(w3, a3, m1, m2);
			s += stride;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 1:
		s -= 1;
		for (i = 0; i < 16; i++) {
			__dcbt(s, stride);
			v0 = ((Uint32 *)s)[0];
			v1 = ((Uint32 *)s)[1];
			v3 = ((Uint32 *)s)[3];
			v2 = ((Uint32 *)s)[2];
			v4 = ((Uint32 *)s)[4];
			w2 = (v0 << 8) | (v1 >> 24);
			a2 = (v0 << 16) | (v1 >> 16);
			d[0] = MPVMC16_AVG2X(w2, a2, m1, m2);
			w3 = (v1 << 8) | (v2 >> 24);
			a1 = (v1 << 16) | (v2 >> 16);
			d[1] = MPVMC16_AVG2X(w3, a1, m1, m2);
			w0 = (v2 << 8) | (v3 >> 24);
			a0 = (v2 << 16) | (v3 >> 16);
			d[16] = MPVMC16_AVG2X(w0, a0, m1, m2);
			w1 = (v3 << 8) | (v4 >> 24);
			a1 = (v3 << 16) | (v4 >> 16);
			d[17] = MPVMC16_AVG2X(w1, a1, m1, m2);
			s += stride;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 2:
		s -= 2;
		for (i = 0; i < 16; i++) {
			__dcbt(s, stride);
			v0 = ((Uint32 *)s)[0];
			v1 = ((Uint32 *)s)[1];
			v2 = ((Uint32 *)s)[2];
			v3 = ((Uint32 *)s)[3];
			v4 = ((Uint32 *)s)[4];
			w2 = (v0 << 16) | (v1 >> 16);
			a2 = (v0 << 24) | (v1 >> 8);
			d[0] = MPVMC16_AVG2X(w2, a2, m1, m2);
			w3 = (v1 << 16) | (v2 >> 16);
			a1 = (v1 << 24) | (v2 >> 8);
			d[1] = MPVMC16_AVG2X(w3, a1, m1, m2);
			w0 = (v2 << 16) | (v3 >> 16);
			a0 = (v2 << 24) | (v3 >> 8);
			d[16] = MPVMC16_AVG2X(w0, a0, m1, m2);
			w1 = (v3 << 16) | (v4 >> 16);
			a1 = (v3 << 24) | (v4 >> 8);
			d[17] = MPVMC16_AVG2X(w1, a1, m1, m2);
			s += stride;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 3:
		s -= 3;
		for (i = 0; i < 16; i++) {
			__dcbt(s, stride);
			w0 = ((Uint32 *)s)[0];
			a0 = ((Uint32 *)s)[1];
			a1 = ((Uint32 *)s)[2];
			a2 = ((Uint32 *)s)[3];
			a3 = ((Uint32 *)s)[4];
			w0 = (w0 << 24) | (a0 >> 8);
			w1 = (a0 << 24) | (a1 >> 8);
			w2 = (a1 << 24) | (a2 >> 8);
			w3 = (a2 << 24) | (a3 >> 8);
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(w3, a3, m1, m2);
			s += stride;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	}
}

// 16x16 luma block, vertical half-pel average.
void MPVMC16_OneRefV2_TuneC(MPVMC *mc)
{
	/* Byte-identical (CRI SWAR kernels pass 22). Case 0: xor-inside macro (frontend CSE temporaries). Cases
	 * 1-3: every word is loaded INTO the case-0 variable of its pair and the pack is written into the SAME
	 * variable (`w1 = (w1 << 24) | (w2 >> 8)`), the offset-0 pair included (`w0 = ((Uint32 *)s0)[0]; s0 +=
	 * stride;` -- the pointer step right after the load keeps it a variable, a single-use load is substituted
	 * into its pack otherwise); the fifth pair is packed in place on its own loads (`p4 = (w3 << 24) | (p4 >>
	 * 8)`), p4 loaded before q4. Why this colours: the frontend numbers a variable's range-split webs by the
	 * variable's FIRST definition (case 0's load order w0,a0,w1,..,a3, then p4,q4) and pack-then-load per case,
	 * so the pops run W0 r10, p0 r8, A0 r11, W1 r12, p1 r31 (first hand-out), A1 r30, q1 r29, ... in case 3
	 * and the later cases take the latest hand-outs; the offset-0 loads of cases 1-3 are webs with the HIGHEST
	 * web ids (w0/a0 are defined first), so they are visited last in the simplification scan, removed in
	 * scan 1 (r17/r18 = the last hand-outs, after the xor temporaries), and case 1 has no own local besides
	 * p4/q4 -- with own locals p0/q0 in case 1 they were removed before p1/q1/p2 and pulled those into the
	 * volatile level, and case 3's q0 web (lowest web id) was visited first and stayed a spill-level node
	 * that pushed stride/masks off r0/r3/r7. */
	Uint32 *d;
	Uint8 *s0;
	Uint8 *s1;
	Sint32 stride;
	Sint32 i;
	Uint32 w0, a0, w1, a1, w2, a2, w3, a3, p4, q4;
	Uint32 m1 = 0xFEFEFEFE;
	Uint32 m2 = 0x01010101;

	s1 = mc->src2;
	s0 = mc->src;
	d = mc->dst;
	stride = mc->stride;
	__dcbt(s1, 0);
	switch ((Uint32)s0 & 3) {
	case 0:
		for (i = 0; i < 16; i++) {
			__dcbt(s1, stride);
			w0 = ((Uint32 *)s0)[0];
			a0 = ((Uint32 *)s1)[0];
			w1 = ((Uint32 *)s0)[1];
			a1 = ((Uint32 *)s1)[1];
			w2 = ((Uint32 *)s0)[2];
			a2 = ((Uint32 *)s1)[2];
			w3 = ((Uint32 *)s0)[3];
			a3 = ((Uint32 *)s1)[3];
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(w3, a3, m1, m2);
			s0 += stride;
			s1 += stride;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 1:
		s0 -= 1;
		s1 -= 1;
		for (i = 0; i < 16; i++) {
			__dcbt(s1, stride);
			w1 = ((Uint32 *)s0)[1];
			a1 = ((Uint32 *)s1)[1];
			w2 = ((Uint32 *)s0)[2];
			a2 = ((Uint32 *)s1)[2];
			w3 = ((Uint32 *)s0)[3];
			a3 = ((Uint32 *)s1)[3];
			p4 = s0[16];
			q4 = s1[16];
			w0 = ((Uint32 *)s0)[0];
			s0 += stride;
			a0 = ((Uint32 *)s1)[0];
			s1 += stride;
			w0 = (w0 << 8) | (w1 >> 24);
			a0 = (a0 << 8) | (a1 >> 24);
			w1 = (w1 << 8) | (w2 >> 24);
			a1 = (a1 << 8) | (a2 >> 24);
			w2 = (w2 << 8) | (w3 >> 24);
			a2 = (a2 << 8) | (a3 >> 24);
			p4 = (w3 << 8) | p4;
			q4 = (a3 << 8) | q4;
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(p4, q4, m1, m2);
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 2:
		s0 -= 2;
		s1 -= 2;
		for (i = 0; i < 16; i++) {
			__dcbt(s1, stride);
			w1 = ((Uint32 *)s0)[1];
			a1 = ((Uint32 *)s1)[1];
			w2 = ((Uint32 *)s0)[2];
			a2 = ((Uint32 *)s1)[2];
			w3 = ((Uint32 *)s0)[3];
			p4 = *(Uint16 *)(s0 + 16);
			a3 = ((Uint32 *)s1)[3];
			q4 = *(Uint16 *)(s1 + 16);
			w0 = ((Uint32 *)s0)[0];
			s0 += stride;
			a0 = ((Uint32 *)s1)[0];
			s1 += stride;
			w0 = (w0 << 16) | (w1 >> 16);
			a0 = (a0 << 16) | (a1 >> 16);
			w1 = (w1 << 16) | (w2 >> 16);
			a1 = (a1 << 16) | (a2 >> 16);
			w2 = (w2 << 16) | (w3 >> 16);
			a2 = (a2 << 16) | (a3 >> 16);
			p4 = (w3 << 16) | p4;
			q4 = (a3 << 16) | q4;
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(p4, q4, m1, m2);
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	case 3:
		s0 -= 3;
		s1 -= 3;
		for (i = 0; i < 16; i++) {
			__dcbt(s1, stride);
			w1 = ((Uint32 *)s0)[1];
			a1 = ((Uint32 *)s1)[1];
			w2 = ((Uint32 *)s0)[2];
			a2 = ((Uint32 *)s1)[2];
			w3 = ((Uint32 *)s0)[3];
			p4 = ((Uint32 *)s0)[4];
			a3 = ((Uint32 *)s1)[3];
			q4 = ((Uint32 *)s1)[4];
			w0 = ((Uint32 *)s0)[0];
			s0 += stride;
			a0 = ((Uint32 *)s1)[0];
			s1 += stride;
			w0 = (w0 << 24) | (w1 >> 8);
			a0 = (a0 << 24) | (a1 >> 8);
			w1 = (w1 << 24) | (w2 >> 8);
			a1 = (a1 << 24) | (a2 >> 8);
			w2 = (w2 << 24) | (w3 >> 8);
			a2 = (a2 << 24) | (a3 >> 8);
			p4 = (w3 << 24) | (p4 >> 8);
			q4 = (a3 << 24) | (q4 >> 8);
			d[0] = MPVMC16_AVG2X(w0, a0, m1, m2);
			d[1] = MPVMC16_AVG2X(w1, a1, m1, m2);
			d[16] = MPVMC16_AVG2X(w2, a2, m1, m2);
			d[17] = MPVMC16_AVG2X(p4, q4, m1, m2);
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	}
}

// 16x16 luma block, full-pel: straight copy of 16 rows into the four output blocks (alignment cases).
void MPVMC16_OneRef1p_TuneC(MPVMC *mc)
{
	Uint8 *s = mc->src;

	__dcbt(s, 0);
	switch ((Uint32)s & 7) {
	case 0: {
		Sint32 stride = mc->stride;
		Float64 *d = (Float64 *)mc->dst;
		Uint32 pitch = (Uint32)stride & ~7;
		Uint8 *p;
		Float64 a0, a1, b0, b1;

		a0 = ((Float64 *)s)[0];
		a1 = ((Float64 *)s)[1];
		p = s + pitch;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[0] = a0;
		d[8] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[1] = b0;
		d[9] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[2] = a0;
		d[10] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[3] = b0;
		d[11] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[4] = a0;
		d[12] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[5] = b0;
		d[13] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[6] = a0;
		d[14] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[7] = b0;
		d[15] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[16] = a0;
		d[24] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[17] = b0;
		d[25] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[18] = a0;
		d[26] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[19] = b0;
		d[27] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		p += pitch;
		d[20] = a0;
		d[28] = a1;
		a0 = ((Float64 *)p)[0];
		a1 = ((Float64 *)p)[1];
		p += pitch;
		d[21] = b0;
		d[29] = b1;
		b0 = ((Float64 *)p)[0];
		b1 = ((Float64 *)p)[1];
		d[22] = a0;
		d[30] = a1;
		d[23] = b0;
		d[31] = b1;
		break;
	}
	case 4: {
		Sint32 stride = mc->stride;
		Sint32 i;
		Uint32 *d = mc->dst;
		Uint32 pitch = (Uint32)stride & ~3;
		Uint8 *p = s;
		Uint32 w0, w1, w2, w3;

		for (i = 0; i < 8; i++) {
			w0 = ((Uint32 *)p)[0];
			w1 = ((Uint32 *)p)[1];
			w2 = ((Uint32 *)p)[2];
			w3 = ((Uint32 *)p)[3];
			p += pitch;
			d[0] = w0;
			d[1] = w1;
			d[16] = w2;
			d[17] = w3;
			d += 2;
		}
		d += 16;
		for (i = 0; i < 8; i++) {
			w0 = ((Uint32 *)p)[0];
			w1 = ((Uint32 *)p)[1];
			w2 = ((Uint32 *)p)[2];
			w3 = ((Uint32 *)p)[3];
			p += pitch;
			d[0] = w0;
			d[1] = w1;
			d[16] = w2;
			d[17] = w3;
			d += 2;
		}
		break;
	}
	case 2:
	case 6: {
		Sint32 stride = mc->stride;
		Sint32 i;
		Uint32 *d = mc->dst;
		Uint8 *p = s;
		Uint32 h0, w0, w1, w2, h1;

		/* Unaligned rows (2/6, 1/5, 3/7) are a sliding window shifted in place: the words are
		 * loaded in address order, the source pointer is stepped BEFORE the packs (so the first
		 * word's single-use load cannot be substituted into its use and stays a variable), and
		 * each word is redefined with its packed value (so the pack webs cannot be sunk into the
		 * stores: they are frontend temporaries numbered in load order, coloured r0/r3/r4 before
		 * the loop's own locals). The pitch is the frontend-hoisted invariant, not a local. */
		for (i = 0; i < 16; i++) {
			h0 = *(Uint16 *)p;
			w0 = *(Uint32 *)(p + 2);
			w1 = *(Uint32 *)(p + 6);
			w2 = *(Uint32 *)(p + 10);
			h1 = *(Uint16 *)(p + 14);
			p += (Uint32)stride & ~1;
			h0 = (h0 << 16) | (w0 >> 16);
			w0 = (w0 << 16) | (w1 >> 16);
			w1 = (w1 << 16) | (w2 >> 16);
			w2 = (w2 << 16) | h1;
			d[0] = h0;
			d[1] = w0;
			d[16] = w1;
			d[17] = w2;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	}
	case 1:
	case 5: {
		Sint32 stride;
		Sint32 i;
		Uint32 *d;
		Uint8 *p = s;
		Uint32 w0, w1, w2, w3, b;

		/* dst before stride: the two preheader loads are scheduled in statement order */
		d = mc->dst;
		stride = mc->stride;
		for (i = 0; i < 16; i++) {
			__dcbt(p, stride);
			w0 = *(Uint32 *)(p - 1);
			w1 = *(Uint32 *)(p + 3);
			w2 = *(Uint32 *)(p + 7);
			w3 = *(Uint32 *)(p + 11);
			b = p[15];
			p += stride;
			w0 = (w0 << 8) | (w1 >> 24);
			w1 = (w1 << 8) | (w2 >> 24);
			w2 = (w2 << 8) | (w3 >> 24);
			w3 = (w3 << 8) | b;
			d[0] = w0;
			d[1] = w1;
			d[16] = w2;
			d[17] = w3;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	}
	case 3:
	case 7: {
		Sint32 stride;
		Sint32 i;
		Uint32 *d;
		Uint8 *p = s;
		Uint32 w0, w1, w2, w3, w4;

		d = mc->dst;
		stride = mc->stride;
		for (i = 0; i < 16; i++) {
			__dcbt(p, stride);
			w0 = *(Uint32 *)(p - 3);
			w1 = *(Uint32 *)(p + 1);
			w2 = *(Uint32 *)(p + 5);
			w3 = *(Uint32 *)(p + 9);
			w4 = *(Uint32 *)(p + 13);
			p += stride;
			w0 = (w0 << 24) | (w1 >> 8);
			w1 = (w1 << 24) | (w2 >> 8);
			w2 = (w2 << 24) | (w3 >> 8);
			w3 = (w3 << 24) | (w4 >> 8);
			d[0] = w0;
			d[1] = w1;
			d[16] = w2;
			d[17] = w3;
			d += 2;
			if (i == 7) {
				d += 16;
			}
		}
		break;
	}
	}
}

/* the generic (non-tuned) versions were dead-stripped; the table keeps their slots */
void (*const mpvmc16_oneref1p_func_table[4])(MPVMC *mc) = {NULL, NULL, NULL, NULL};

// Fills the handle's 16x16 kernel slots (generic table, stripped to NULLs).
void MPVMC16_Init(MPVMC *mc)
{
	mc->oneref16[0] = mpvmc16_oneref1p_func_table[0];
	mc->oneref16[1] = mpvmc16_oneref1p_func_table[1];
	mc->oneref16[2] = mpvmc16_oneref1p_func_table[2];
	mc->oneref16[3] = mpvmc16_oneref1p_func_table[3];
}
