/* CRI Sofdec MPEG video: 8x8 block motion compensation, "tuned C" versions. One reference block is
 * copied (1p), horizontally (H2) / vertically (V2) / four-point (4p) half-pel averaged into the
 * word-packed destination; the source alignment selects the load strategy. Pure C reconstruction of
 * the original's instruction stream (integer SWAR code: byte averages through 0x01010101/0xFEFEFEFE
 * masks, four-point sums `a0 + a1 + b0 + b1 + 2` packed with rlwinm/rlwimi; the H2 average is the
 * two-definition `t = w & a; t += x & m2; t + ((x & m1) >> 1)` with the masks as function-level
 * variables, the 1p rows are hand-unrolled with the original's dcbt placement); mpv_mcy.c holds the
 * 16x16 counterparts. Residues: instruction schedule / register assignment, and the 1p update-form
 * loads (lfdux/lwzux), which this compiler never emits from C (docs/research/ "CRI SWAR kernels pass 2"). */
#include "cri_xpt.h"
#include "mpv.h"

/* four-point average of the pixel pairs (a, a+1) x (b, b+1), packed as four bytes */
#define MPVMC08_AVG4(p0, p1, p2, p3) \
	((((p0) << 22) & 0xFF000000) | (((p1) << 14) & 0x00FF0000) | (((p2) << 6) & 0x0000FF00) | (((p3) >> 2) & 0x000000FF))

/* byte-wise average of two packed words (V2 form): with the masks as VARIABLES the frontend keeps the
 * target's association `(w & a) + (((x & m1) >> 1) + (x & m2))`; with constants it rebuilds
 * `sh + ((w & a) + (x & m2))` whatever the spelling */
#define MPVMC08_AVG2(w, a, x, m1, m2) (((w) & (a)) + (((x) & (m1)) >> 1) + ((x) & (m2)))

#define MPVMC08_W(p, n) (*(Uint32 *)((Uint8 *)(p) + (n)))
#define MPVMC08_H(p, n) (*(Uint16 *)((Uint8 *)(p) + (n)))

// 8x8 block, half-pel in both directions: each output byte is the rounded average of a 2x2
// reference neighbourhood, written as four packed bytes per word.
void MPVMC08_OneRef4p_TuneC(MPVMC *mc)
{
	/* Three rotating pixel pairs (pixel k in pair k % 3), each pair loaded right before the sum that
	 * needs it, the prefetch after the first pair, the loop variables declared before the pixel
	 * words and the sums (CRI SWAR kernels pass 12: byte-identical). */
	Sint32 i;
	Sint32 stride;
	Uint8 *s0;
	Uint8 *s1;
	Uint32 *d;
	Uint32 a0, b0, a1, b1, a2, b2;
	Uint32 p0, p1, p2, p3, p4, p5, p6, p7;

	stride = mc->stride;
	s0 = mc->src;
	s1 = mc->src2;
	d = mc->dst;
	for (i = 0; i < 8; i++) {
		a0 = s0[0];
		b0 = s1[0];
		__dcbt(s1, stride);
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
		d[0] = MPVMC08_AVG4(p0, p1, p2, p3);
		d[1] = MPVMC08_AVG4(p4, p5, p6, p7);
		s0 += stride;
		s1 += stride;
		d += 2;
	}
}

/* H2: one row per iteration, unrolled x2 by the backend (a counted-loop body of <= 35 pcodes after the copy/add
 * propagation passes). The row variables are the locals of an inlined helper so that the pack copies coalesce into
 * them (helper locals are `@N` webs, own locals are not), the whole helper is one web per variable across the four
 * cases (`opt_lifetimes off` on the CALLER), and the packs are written so that the or->rlwimi peephole inserts into
 * the variable's own register: `V = base_shift; V = (fused_shift) | (V & complement_mask)` (a rotate-0 mask that is
 * the complement of the insert range is replaced by its source, `mr V, V` disappears) or `V = __rlwimi(V, ..)` on a
 * value whose web is not redefined while the K6 temp lives. Cases 2/3: their target order is the pre-RA schedule
 * of a DAG with NO leftover pcode at all (the or-pack's fused shift stays as a dead def until the RA, the
 * intrinsic's K6 copy is a node; the scheduler model shows every such extra node moving the order), so the
 * inserts are asm-emitted `rlwimi` single instructions there (COMPILER-DIFF; the vendor's "tuned C" had them as
 * asm too: no C spelling of this compiler produces a bare rlwimi). Masks: function-level webs, materialised once
 * (the target's `lis r5, 0xfeff; lis r4, 0x101` at the top). docs/research/ "CRI SWAR kernels pass 14-18". */
#pragma opt_propagation off /* COMPILER-DIFF: the masks would be propagated into every case (lis/addi per case, bodies > 35 pcodes, no unroll) */
#pragma inline_max_size(100000) /* COMPILER-DIFF: the ~120-statement helper is not inlined under -inline auto */
#pragma inline_max_total_size(100000)
// 8x8 block, horizontal half-pel: byte-wise average of each reference word with its one-byte-shifted
// neighbour (SWAR through the 0xFEFEFEFE / 0x01010101 masks); the source alignment case selects the
// load pattern.
static inline void mpvmc08_OneRefH2Body(MPVMC *mc)
{
	Uint32 m2;
	Uint32 m1;
	Uint32 x0;
	register Uint32 a1, w1; /* asm operands (cases 2/3) */
	Uint8 *s = mc->src;
	Uint32 *d = mc->dst;
	register Uint32 a0, w0;
	Sint32 stride = mc->stride;
	register Uint32 x1;
	Sint32 i;

	/* web vids in declaration order (m2 lowest = r12, m1 = r11); the `lis` temps in statement order (m2's created
	 * later = coloured first = r4, then m1's r5) */
	m1 = 0xFEFEFEFE;
	m2 = 0x01010101;

	switch ((Uint32)s & 3) {
	case 0:
		for (i = 0; i < 8; i++) {
			__dcbt(s, stride);
			w0 = MPVMC08_W(s, 0);
			w1 = MPVMC08_W(s, 4);
			a1 = s[8];
			a0 = (w1 >> 24) | (w0 << 8);
			a1 = __rlwimi(a1, w1, 8, 0, 23);
			x0 = w0 ^ a0;
			s += stride;
			w0 &= a0;
			x1 = w1 ^ a1;
			a0 = x0 & m1;
			x0 &= m2;
			w1 &= a1;
			a1 = x1 & m1;
			x1 &= m2;
			a0 >>= 1;
			w0 += x0;
			a1 >>= 1;
			w0 += a0;
			w1 += x1;
			d[0] = w0;
			w1 += a1;
			d[1] = w1;
			d += 2;
		}
		break;
	case 1:
		s -= 1;
		for (i = 0; i < 8; i++) {
			__dcbt(s, stride);
			w1 = MPVMC08_W(s, 4);
			a0 = MPVMC08_W(s, 0);
			a1 = MPVMC08_H(s, 8);
			w0 = w1 >> 24;
			w0 = __rlwimi(w0, a0, 8, 0, 23);
			a0 = (w1 & 0xFFFF0000) | (a0 & 0xFFFF);
			a0 = __rlwinm(a0, 16, 0, 31);
			a1 = __rlwimi(a1, w1, 16, 0, 15);
			x0 = w0 ^ a0;
			w1 <<= 8;
			w1 = __rlwimi(w1, a1, 24, 24, 31);
			w0 &= a0;
			a0 = x0 & m1;
			x0 &= m2;
			x1 = w1 ^ a1;
			w1 &= a1;
			a1 = x1 & m1;
			a0 >>= 1;
			w0 += x0;
			x1 &= m2;
			w0 += a0;
			a1 >>= 1;
			w1 += x1;
			d[0] = w0;
			w1 += a1;
			s += stride;
			d[1] = w1;
			d += 2;
		}
		break;
	case 2:
		s -= 2;
		for (i = 0; i < 8; i++) {
			__dcbt(s, stride);
			w0 = MPVMC08_W(s, 0);
			w1 = MPVMC08_W(s, 4);
			x1 = MPVMC08_W(s, 8);
			a0 = w0 << 24;
			 /* COMPILER-DIFF: in-place insert with no leftover pcode (see below) */
			w0 <<= 16;
			
			x0 = w0 ^ a0;
			w0 &= a0;
			a1 = w1 << 24;
			
			a0 = x0 & m1;
			w1 <<= 16;
			
			x0 &= m2;
			s += stride;
			x1 = w1 ^ a1;
			w1 &= a1;
			a1 = x1 & m1;
			a0 >>= 1;
			w0 += x0;
			x1 &= m2;
			w0 += a0;
			a1 >>= 1;
			w1 += x1;
			d[0] = w0;
			w1 += a1;
			d[1] = w1;
			d += 2;
		}
		break;
	case 3:
		s -= 3;
		for (i = 0; i < 8; i++) {
			__dcbt(s, stride);
			a0 = MPVMC08_W(s, 4);
			w0 = __lwbrx(s, 0);
			
			a1 = MPVMC08_W(s, 8);
			x0 = w0 ^ a0;
			w1 = a0 << 24;
			
			w0 &= a0;
			a0 = x0 & m1;
			x0 &= m2;
			x1 = w1 ^ a1;
			w1 &= a1;
			a1 = x1 & m1;
			a0 >>= 1;
			w0 += x0;
			x1 &= m2;
			w0 += a0;
			a1 >>= 1;
			w1 += x1;
			d[0] = w0;
			w1 += a1;
			s += stride;
			d[1] = w1;
			d += 2;
		}
		break;
	}
}

void MPVMC08_OneRefH2_TuneC(MPVMC *mc)
{
	mpvmc08_OneRefH2Body(mc);
}
#pragma opt_propagation reset
// 8x8 block, vertical half-pel: byte-wise average of each row with the next.
void MPVMC08_OneRefV2_TuneC(MPVMC *mc)
{
	Sint32 i;
	Uint32 *d;
	Uint8 *s0;
	Uint8 *s1;
	Sint32 stride;
	/* Cases 1-3 (CRI SWAR pass 18): the range-split webs are numbered by the FIRST definition of each variable in the function and
	 * coloured in that order, so x0/x1 carry dead initialisers (deleted, no code) to be numbered before the word webs; the third
	 * word/half/byte of a row (w2/a2) is kept as a variable by the pointer step placed right after its load, and the second pack is
	 * written INTO it (`w2 = (w1 << 8) | w2`), which gives the target's `lbz r31; mr r28, r31` in case 1 and the in-place `srwi r28, r28, 8`
	 * in case 3 (w1/a1 then hold the loads only). */
	Uint32 x0 = 0, x1 = 0;
	Uint32 w0, a0, w1, a1, w2, a2;
	Uint32 m1 = 0xFEFEFEFE;
	Uint32 m2 = 0x01010101;

	s0 = mc->src;
	s1 = mc->src2;
	d = mc->dst;
	stride = mc->stride;
	switch ((Uint32)s0 & 3) {
	case 0:
		for (i = 0; i < 8; i++) {
			w0 = MPVMC08_W(s0, 0);
			a0 = MPVMC08_W(s1, 0);
			w1 = MPVMC08_W(s0, 4);
			a1 = MPVMC08_W(s1, 4);
			x0 = w0 ^ a0;
			x1 = w1 ^ a1;
			d[0] = MPVMC08_AVG2(w0, a0, x0, m1, m2);
			d[1] = MPVMC08_AVG2(w1, a1, x1, m1, m2);
			s0 += stride;
			s1 += stride;
			d += 2;
		}
		break;
	case 1:
		s0 -= 1;
		s1 -= 1;
		for (i = 0; i < 8; i++) {
			w1 = MPVMC08_W(s0, 4);
			a1 = MPVMC08_W(s1, 4);
			w0 = MPVMC08_W(s0, 0);
			w2 = s0[8];
			s0 += stride;
			a0 = MPVMC08_W(s1, 0);
			a2 = s1[8];
			s1 += stride;
			w0 = (w0 << 8) | (w1 >> 24);
			a0 = (a0 << 8) | (a1 >> 24);
			w2 = (w1 << 8) | w2;
			a2 = (a1 << 8) | a2;
			x0 = w0 ^ a0;
			x1 = w2 ^ a2;
			d[0] = MPVMC08_AVG2(w0, a0, x0, m1, m2);
			d[1] = MPVMC08_AVG2(w2, a2, x1, m1, m2);
			d += 2;
		}
		break;
	case 2:
		s0 -= 2;
		s1 -= 2;
		for (i = 0; i < 8; i++) {
			w1 = MPVMC08_W(s0, 4);
			a1 = MPVMC08_W(s1, 4);
			w0 = MPVMC08_W(s0, 0);
			w2 = MPVMC08_H(s0, 8);
			s0 += stride;
			a0 = MPVMC08_W(s1, 0);
			a2 = MPVMC08_H(s1, 8);
			s1 += stride;
			w0 = (w0 << 16) | (w1 >> 16);
			a0 = (a0 << 16) | (a1 >> 16);
			w2 = (w1 << 16) | w2;
			a2 = (a1 << 16) | a2;
			x0 = w0 ^ a0;
			x1 = w2 ^ a2;
			d[0] = MPVMC08_AVG2(w0, a0, x0, m1, m2);
			d[1] = MPVMC08_AVG2(w2, a2, x1, m1, m2);
			d += 2;
		}
		break;
	case 3:
		s0 -= 3;
		s1 -= 3;
		for (i = 0; i < 8; i++) {
			w1 = MPVMC08_W(s0, 4);
			a1 = MPVMC08_W(s1, 4);
			w0 = MPVMC08_W(s0, 0);
			w2 = MPVMC08_W(s0, 8);
			s0 += stride;
			a0 = MPVMC08_W(s1, 0);
			a2 = MPVMC08_W(s1, 8);
			s1 += stride;
			w0 = (w0 << 24) | (w1 >> 8);
			a0 = (a0 << 24) | (a1 >> 8);
			w2 = (w1 << 24) | (w2 >> 8);
			a2 = (a1 << 24) | (a2 >> 8);
			x0 = w0 ^ a0;
			x1 = w2 ^ a2;
			d[0] = MPVMC08_AVG2(w0, a0, x0, m1, m2);
			d[1] = MPVMC08_AVG2(w2, a2, x1, m1, m2);
			d += 2;
		}
		break;
	}
}

/* MPVMC08_OneRef1p_TuneC: kept as inline asm -- `lfdux`/`lwzux` are never emitted from C by MWCC 2.4.7
 * (13 probe forms; only constant loop steps fold to `lwzu`) and case 3/7 row 3 carries a `dcbt` stride typo, so
 * this kernel was asm in CRI's source (see docs/research/ "CRI SWAR kernels pass 2"). */
void MPVMC08_OneRef1p_TuneC(MPVMC *mc)
{
	register Uint8 *s = mc->src;

	
	switch ((Uint32)s & 7) {
	case 0:
	{
		register Sint32 st;

		
		break;
	}
	case 4:
	{
		register Sint32 st;
		register Uint8 *p;
		register Uint32 w;

		
		break;
	}
	case 2:
	case 6:
	{
		register Uint32 t0;
		register Uint32 st;

		
		break;
	}
	case 1:
	case 5:
	{
		register Sint32 st;
		register Uint32 *d;

		
		break;
	}
	case 3:
	case 7:
	{
		register Sint32 st;
		register Uint32 *d;

		
		break;
	}
	}
}

/* the generic (non-tuned) versions were dead-stripped; the table keeps their slots */
void (*const mpvmc_oneref1p_func_table[4])(MPVMC *mc) = {NULL, NULL, NULL, NULL};

// Fills the handle's 8x8 kernel slots (from the generic table, which the linker stripped to NULLs;
// the tuned kernels are reached through mpvcmc_oneref).
void MPVMC08_Init(MPVMC *mc)
{
	mc->oneref08[0] = mpvmc_oneref1p_func_table[0];
	mc->oneref08[1] = mpvmc_oneref1p_func_table[1];
	mc->oneref08[2] = mpvmc_oneref1p_func_table[2];
	mc->oneref08[3] = mpvmc_oneref1p_func_table[3];
}
