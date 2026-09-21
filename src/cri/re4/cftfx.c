/* Sofdec colour format transforms (cftfx.c): colour adjustment table generation for the ARGB8888
 * and YCC422 outputs (CCIR601 matrix through the custom inverse tables), the 4:2:0 planar luma ->
 * alpha ("A256V") fill of RGBA8 4x4 tiles and the ARGB 4:2:0 -> RGBA8 tile conversion. */
#include "cri_xpt.h"

extern void CFT_MakeMtx3D(Float32 *a, Float32 *b, Float32 *out);
extern void CFT_MakeInverseMtx3D(Float32 *m, Float32 *inv);
extern void CFT_MakeInvConvTableCustom(Uint8 *ytbl, Uint8 *cbtbl, Uint8 *crtbl);
extern Uint32 __cvt_fp2unsigned(Float32 f);

/* source planes of the 4:2:0 converters */
typedef struct {
	Uint8 *y;                  /* 0x00 */
	Uint8 *cb;                 /* 0x04 */
	Uint8 *cr;                 /* 0x08 */
	Sint32 ywidth;             /* 0x0C */
	Sint32 cbwidth;            /* 0x10 */
	Sint32 crwidth;            /* 0x14 */
} CFT_YCC420PLN;

/* destination of the tile converters */
typedef struct {
	Uint32 *buf;               /* 0x00 */
	Sint32 width;              /* 0x04 */
	Sint32 height;             /* 0x08 */
	Sint32 pitch;              /* 0x0C */
} CFT_ARGBDST;

extern void mwPlyCalcYccPlane(void *buf, Sint32 width, Sint32 height, CFT_YCC420PLN *pln);

/* RGB -> YUV matrices: Sofdec's own coefficients and CCIR601 */
Float32 cft_rgb_yuv_coeff[9] = {
	0.30078125f, 0.5859375f, 0.11328125f, -0.171875f, -0.33984375f, 0.51171875f, 0.51171875f,
	-0.4296875f, -0.08203125f,
};
Float32 cft_rgb_yuv_ccir601[9] = {
	0.257f, 0.504f, 0.098f, -0.148f, -0.291f, 0.439f, 0.439f, -0.368f, -0.071f,
};

/* (`-inline auto,deferred`: .bss in reverse declaration order, .text in reverse source order) */
Uint8 cft_conv_y_itbl[0x100];
Uint8 cft_conv_u_itbl[0x100];
Uint8 cft_conv_v_itbl[0x100];
Float32 *cft_ptr_y_rgb;
static Float32 *cft_ptr_cb_rgb;
Float32 *cft_ptr_cr_rgb;
Float32 cft_yuv_rgb_coeff[9];
Float32 cft_basic_ccir601[9];

void cnvDynamicYcc420plnToA256UserTable(const CFT_YCC420PLN *src, const CFT_ARGBDST *dst, const Uint8 *tbl);
void cnvStaticYcc420plnToA256V(const CFT_YCC420PLN *src, const CFT_ARGBDST *dst);

/* one tile row pair of the ARGB 4:2:0 conversion (four pixels): AR half from the alpha plane word
 * and the Cb pair, GB half from the luma word and the Cr pair */
#define CFT_ARGB420_ROW(ar, gb, ap, yp, cbp, crp)                                              \
	av = *(Uint32 *)(ap);                                                                  \
	yv = *(Uint32 *)(yp);                                                                  \
	cbv = *(cbp);                                                                          \
	crv = *(crp);                                                                          \
	(ar)[1] = ((((av) << 16) & 0xFF000000) | (((av) & 0xFF) << 8)) | (((cbv) << 16) & 0x00FF0000) | \
		  ((cbv) & 0xFF);                                                                 \
	(gb)[1] = ((((yv) << 16) & 0xFF000000) | (((yv) & 0xFF) << 8)) | (((crv) << 16) & 0x00FF0000) | \
		  ((crv) & 0xFF);                                                                 \
	(ar)[0] = (((av) & 0xFF000000) | (((av) >> 8) & 0xFF00)) | (((cbv) << 8) & 0x00FF0000) |    \
		  ((cbv) >> 8);                                                                   \
	(gb)[0] = (((yv) & 0xFF000000) | (((yv) >> 8) & 0xFF00)) | (((crv) << 8) & 0x00FF0000) |    \
		  ((crv) >> 8)

/* (Byte pointers and byte steps. The setup's registers are all vid order (CRI pass 56): the three
 * `pln.y`/`pln.cb` reads are frontend-CSE'd into two load temps, so `y = ..`/`cb = ..` are user
 * copies (`mr r6,r5`/`mr r9,r4`, never coalesced) and `a` is computed from the y temp; the
 * two-def `cstep`/`ystep` make the width loads OWN locals (cstep declared first = coloured first
 * = r7, ystep r10) below every backend temp, so the hblk `srawi` (a backend temp, coloured before
 * the loads) takes r0 and the y temp r5; wblk/hblk are computed after ar/gb so their temps do not
 * overlap the step values, and ystep in bytes is a statement (before cstep's mask) rather than a
 * hoisted `ystep << 2`. The chroma increments sit between the row steps and the `y += 4`/`a += 4`:
 * the post-schedule addi sink moves them to the block end in statement order and the post-RA
 * scheduler uses them as the `subf` latency fillers in that order.) */
void CFT_Argb420ToArgb8(void *src, void *dst, Sint32 width, Sint32 height)
{
	CFT_YCC420PLN pln;
	Sint32 i;
	Sint32 j;
	Sint32 wblk;
	Sint32 hblk;
	Uint8 *y;
	Uint8 *a;
	Uint16 *cb;
	Uint16 *cr;
	Uint16 *cb2;
	Uint16 *cr2;
	Uint32 *ar;
	Uint32 *gb;
	Sint32 cstep;
	Sint32 ystep;
	Sint32 yback;
	Uint32 half;
	Uint32 av;
	Uint32 yv;
	Uint32 cbv;
	Uint32 crv;

	mwPlyCalcYccPlane(src, width, height, &pln);
	y = pln.y;
	cb = (Uint16 *)pln.cb;
	half = (((Uint32)pln.cb - (Uint32)pln.y) >> 1) & ~3;
	a = pln.y + half;
	cr = (Uint16 *)pln.cr;
	ar = (Uint32 *)dst;
	gb = (Uint32 *)((Uint8 *)dst + 0x20);
	wblk = width / 4;
	hblk = height / 4;
	cstep = pln.cbwidth;
	ystep = pln.ywidth;
	ystep = ystep / sizeof(Uint32) * sizeof(Uint32);
	cstep = cstep / sizeof(Uint16) * sizeof(Uint16);
	yback = ystep * 2;
	for (i = 0; i < hblk; i++) {
		cr2 = (Uint16 *)(cstep + (Uint32)cr);
		cb2 = (Uint16 *)(cstep + (Uint32)cb);
		for (j = 0; j < wblk;) {
			if (j >= 0 && j < wblk) {
				CFT_ARGB420_ROW(ar, gb, a, y, cb, cr);
				CFT_ARGB420_ROW(ar + 2, gb + 2, a, y, cb, cr);
			} else {
				ar[0] = 0; gb[0] = 0; ar[1] = 0; gb[1] = 0;
				ar[2] = 0; gb[2] = 0; ar[3] = 0; gb[3] = 0;
			}
			y += ystep;
			a += ystep;
			if (j >= 0 && j < wblk) {
				CFT_ARGB420_ROW(ar + 4, gb + 4, a, y, cb2, cr2);
				CFT_ARGB420_ROW(ar + 6, gb + 6, a, y, cb, cr);
			} else {
				ar[4] = 0; gb[4] = 0; ar[5] = 0; gb[5] = 0;
				ar[6] = 0; gb[6] = 0; ar[7] = 0; gb[7] = 0;
			}
			y += ystep;
			a += ystep;
			cb++;
			cb2++;
			cr++;
			cr2++;
			y += 4;
			a += 4;
			y -= yback;
			a -= yback;
			j++;
			ar += 16;
			gb += 16;
		}
		y += ystep;
		a += ystep;
		cb = (Uint16 *)((Uint32)cb + cstep);
		cr = (Uint16 *)((Uint32)cr + cstep);
	}
}

// YCC 4:2:0 luma -> the alpha channel of RGBA8 4x4 tiles (static, or through a user luma table).
void CFT_Ycc420plnToA256V(CFT_YCC420PLN *src, CFT_ARGBDST *dst, Uint8 *tbl)
{
	if (tbl == NULL) {
		cnvStaticYcc420plnToA256V(src, dst);
	} else {
		cnvDynamicYcc420plnToA256UserTable(src, dst, tbl);
	}
}

/* the same with the luma itself as alpha (four samples read as one word): the low word goes
 * through `t` first (an own-local web, below the row's backend temps in vid order: coloured after
 * the high word r11 and the destination load r12 -> r31), the high word is an expression */
#define CFT_A256_ROW_STATIC(dst, w, t)                                                         \
	(t) = (((w) << 16) & 0xFF000000) | (((w) & 0xFF) << 8);                                \
	(dst)[0] &= (((w) & 0xFF000000) | (((w) >> 8) & 0x0000FF00)) | 0x00FF00FF;             \
	(dst)[1] &= (t) | 0x00FF00FF

/* (the `const` parameters are the original's: loads through a pointer-to-const get an alias class
 * disjoint from the stores, so the post-RA scheduler hoists the parameter loads above the
 * prologue's `stwu`/`stw` as the target does. The frontend splits a reused variable into webs
 * numbered per variable in order of FIRST DEF, each variable's webs in reverse statement order,
 * and sinks the LAST TWO defs into their uses: `t = 0` at the declaration puts t's webs before
 * w's (w's web of each row then outranks t's: w r30, t r31), and the two pointer round trips of
 * the loop tail are the sunk defs, so all four rows keep their `t` web.) */
void cnvStaticYcc420plnToA256V(const CFT_YCC420PLN *src, const CFT_ARGBDST *dst)
{
	Sint32 i;
	Sint32 j;
	Sint32 wblk = dst->width / 4;
	Sint32 hblk = dst->height / 4;
	Sint32 ystep = src->ywidth / sizeof(Uint32);
	Sint32 dskip = (dst->pitch - dst->width) / 4 * 16;
	Uint32 *d = dst->buf;
	Uint32 *y = (Uint32 *)src->y;
	Uint32 w;
	Uint32 t = 0;

	for (i = 0; i < hblk; i++) {
		for (j = 0; j < wblk; j++) {
			w = *y;
			y += ystep;
			CFT_A256_ROW_STATIC(d, w, t);
			w = *y;
			y += ystep;
			CFT_A256_ROW_STATIC(d + 2, w, t);
			w = *y;
			y += ystep;
			CFT_A256_ROW_STATIC(d + 4, w, t);
			w = *y;
			y += ystep;
			CFT_A256_ROW_STATIC(d + 6, w, t);
			y -= ystep * 4;
			t = (Uint32)y + 4;
			y = (Uint32 *)t;
			t = (Uint32)d + 64;
			d = (Uint32 *)t;
		}
		y += ystep * 3;
		d += dskip;
	}
}

/* one row of a 4x4 RGBA8 tile's AR half: the alpha bytes replaced (masked) by the table values of
 * the four luma samples, packed in two own locals; the pointer moves on by the four samples with
 * ONE increment placed inside the last index expression (a statement-level `y += 4` is forwarded
 * into the next row pointer's add and the +4 sunk; post-increments on every byte give the same
 * real `addi` but 4 pcodes more per row, see docs/research/ "CRI pass 57").  The `& 0xFF` masks emit
 * nothing (a byte load is already zero-extended: the index masks are deleted by load-deletion,
 * the value masks fold into the `rlwinm 24,0,7` that the or->rlwimi peephole replaces) but they
 * count in the block-splitting pass: 31 initial pcodes per row put the split of the inner body
 * exactly after the third row-pointer add, as in the original (docs/research/ "CRI pass 58").  A mask
 * on the `<< 8` operand would fuse into `clrlslwi` -- only the `<< 24` values may carry one.
 * Each pack is TWO statements (`v = A << 24; v |= B << 8;`, docs/research/ "CRI pass 59"): the
 * or->rlwimi peephole gives the same `slwi B; mr v, B; rlwimi v, a, 24, 0, 7`, but the `<< 24`
 * rlwinm now writes v itself and stays a dead def until the RA, i.e. a WAW predecessor of the
 * `mr` at scheduling time: the pack chain starts one cycle later and the destination load and
 * the byte-3 table load take the LSU ahead of it (the original's rows 3-4 registers). */
#define CFT_A256_ROW(dst, y, tbl)                                                              \
	v0 = (((Uint32)(tbl)[(y)[0] & 0xFF] & 0xFF) << 24);                                    \
	v0 |= (Uint32)(tbl)[(y)[1] & 0xFF] << 8;                                               \
	v1 = (((Uint32)(tbl)[(y)[2] & 0xFF] & 0xFF) << 24);                                    \
	v1 |= (Uint32)(tbl)[((y) += 4)[-1] & 0xFF] << 8;                                       \
	(dst)[0] &= v0 | 0x00FF00FF;                                                           \
	(dst)[1] &= v1 | 0x00FF00FF

/* CRI pass 57 (109w, was 135w): the original computes `ywidth - 4` per block into a row-step
 * variable (in-loop `subi`), copies it into two more (`mr`), and moves each row pointer INTO the
 * step register with the pointer as the FIRST add operand (`add p, y, p`): `p += (Uint32)(y + 4)
 * - 4` is the only spelling that keeps one web (a full assignment `p = y + p` starts a new web
 * and hoists the subi) and puts the added value first (the codegen reassociates `X + (Y + K)` into
 * `add X, Y, X; addi K`, the +-4 cancel).  Declaration order = the target's colouring order
 * (p4 r4, y r6, p3 r7 above i; d r12, p2 r31, yskip r30).  The fourth step is a fresh
 * `ywidth - 4` (not CSE'd, not hoisted) and `y = p3 - ywidth * 4 + 4` = subf temp + addi.
 * CRI pass 58 (73w): `const Uint8 *tbl` gives the table loads their own alias class (the
 * original's, like the StaticV `const` parameters): without the load->store edges the scheduler
 * orders the two packs' loads by chain length (byte 3 before byte 2), the tail add/subf fall
 * after the last store, and the block split above lands after `p4 += ...` -- the original's
 * two blocks (77/28 instructions), frame (`stmw r25`, the row-1 packs' `mr r25` copies) and
 * size.  The fourth step reuses p3: its second web competes with the row-4 packs for r26 (the
 * original's `subi r26`, packs r27), and range-split webs are numbered per variable in first-def
 * order with the vids descending along them, so p3/p4 are copied BEFORE row 1 (p3's webs above
 * v0/v1's = coloured first; CRI pass 59).  CRI pass 61 (0w): the setup's `slwi r0` (ywidth * 4)
 * before `add r30` (yskip) is a pre-RA tie resolved by input order, and a hoisted @temp is always
 * appended after the for-init; so the two strides are OWN locals declared first (w4 r0, dskip r3
 * = the two highest vids of the level, coloured before p4) with `w4 = ywidth * 4` as a statement
 * ahead of yskip's.  dskip is kept in bytes (`/ 4 * 64` and a byte-pointer add): `d += dskip`
 * with a Uint32 step is folded by the frontend into a new hoisted `<< 6` @temp (dskip's own
 * node vanishes and w4 falls behind it, r3/r0 swapped). */
void cnvDynamicYcc420plnToA256UserTable(const CFT_YCC420PLN *src, const CFT_ARGBDST *dst, const Uint8 *tbl)
{
	Sint32 w4;
	Sint32 dskip;
	const Uint8 *p4;
	const Uint8 *y = src->y;
	const Uint8 *p3;
	Sint32 i;
	Sint32 j;
	Sint32 wblk = dst->width / 4;
	Sint32 hblk = dst->height / 4;
	Sint32 ywidth = src->ywidth;
	Uint32 *d = dst->buf;
	const Uint8 *p2;
	Sint32 yskip;
	Uint32 v0, v1;

	w4 = ywidth * 4;
	yskip = ywidth * 3 + (ywidth - dst->width);
	dskip = (dst->pitch - dst->width) / 4 * 64;
	for (i = 0; i < hblk; i++) {
		for (j = 0; j < wblk; j++) {
			p2 = (Uint8 *)(ywidth - 4);
			p3 = p2;
			p4 = p2;
			CFT_A256_ROW(d, y, tbl);
			p2 += (Uint32)(y + 4) - 4;
			CFT_A256_ROW(d + 2, p2, tbl);
			p3 += (Uint32)(p2 + 4) - 4;
			CFT_A256_ROW(d + 4, p3, tbl);
			p4 += (Uint32)(p3 + 4) - 4;
			CFT_A256_ROW(d + 6, p4, tbl);
			p3 = (Uint8 *)(ywidth - 4);
			p3 += (Uint32)(p4 + 4) - 4;
			y = p3 - w4 + 4;
			d += 16;
		}
		y += yskip;
		d = (Uint32 *)((Uint8 *)d + dskip);
	}
}

/* clamp to the byte range */
#define CFT_CLIP255(f)                                                                         \
	if ((f) < 0.0f) {                                                                      \
		(f) = 0.0f;                                                                    \
	}                                                                                      \
	if ((f) > 255.0f) {                                                                    \
		(f) = 255.0f;                                                                  \
	}

/* YCC422 colour adjustment: four 256-entry Uint32 tables (Y << 24, Y << 8, Cb << 16, Cr) of the
 * CCIR601-corrected components (the coefficient locals: i declared last for its register) */
void CFT_MakeYcc422ColAdjTbl(void *tbl)
{
	Uint32 *ty1 = (Uint32 *)tbl;
	Uint32 *ty2 = ty1 + 0x100;
	Uint32 *tu = ty2 + 0x100;
	Uint32 *tv = tu + 0x100;
	Float32 f;
	Float32 ou;
	Float32 ov;
	Float32 my;
	Float32 mu;
	Float32 mv;
	Uint32 v;
	Sint32 i;

	CFT_MakeInvConvTableCustom(cft_conv_y_itbl, cft_conv_u_itbl, cft_conv_v_itbl);
	CFT_MakeInverseMtx3D(cft_rgb_yuv_coeff, cft_yuv_rgb_coeff);
	CFT_MakeMtx3D(cft_rgb_yuv_ccir601, cft_yuv_rgb_coeff, cft_basic_ccir601);
	my = cft_basic_ccir601[0];
	mu = cft_basic_ccir601[4];
	mv = cft_basic_ccir601[8];
	ou = 128.0f * mu;
	ov = 128.0f * mv;
	for (i = 0; i < 256; i++) {
		f = my * (Float32)cft_conv_y_itbl[i] + 16.5f;
		CFT_CLIP255(f);
		v = (Uint32)f;
		ty1[i] = v << 24;
		ty2[i] = v << 8;
		f = 128.5f + (mu * (Float32)cft_conv_u_itbl[i] - ou);
		CFT_CLIP255(f);
		v = (Uint32)f;
		tu[i] = v << 16;
		f = 128.5f + (mv * (Float32)cft_conv_v_itbl[i] - ov);
		CFT_CLIP255(f);
		v = (Uint32)f;
		tv[i] = v;
	}
}

/* ARGB8888 colour adjustment: three 256-entry float tables (alpha, R, G, B contribution of the
 * component) at tbl, tbl + 0x1000, tbl + 0x2000 */
void CFT_MakeArgb8888ColAdjTbl(void *tbl)
{
	Sint32 i;

	cft_ptr_y_rgb = (Float32 *)tbl;
	cft_ptr_cb_rgb = (Float32 *)((Uint8 *)tbl + 0x1000);
	cft_ptr_cr_rgb = (Float32 *)((Uint8 *)tbl + 0x2000);
	CFT_MakeInvConvTableCustom(cft_conv_y_itbl, cft_conv_u_itbl, cft_conv_v_itbl);
	CFT_MakeInverseMtx3D(cft_rgb_yuv_coeff, cft_yuv_rgb_coeff);
	for (i = 0; i < 256; i++) {
		cft_ptr_y_rgb[(i << 2) + 1] = cft_yuv_rgb_coeff[0] * (Float32)cft_conv_y_itbl[i];
		cft_ptr_y_rgb[(i << 2) + 2] = cft_yuv_rgb_coeff[3] * (Float32)cft_conv_y_itbl[i];
		cft_ptr_y_rgb[(i << 2) + 3] = cft_yuv_rgb_coeff[6] * (Float32)cft_conv_y_itbl[i];
		cft_ptr_y_rgb[(i << 2) + 0] = 255.0f;
		cft_ptr_cb_rgb[(i << 2) + 1] = cft_yuv_rgb_coeff[1] * ((Float32)cft_conv_u_itbl[i] - 128.0f);
		cft_ptr_cb_rgb[(i << 2) + 2] = cft_yuv_rgb_coeff[4] * ((Float32)cft_conv_u_itbl[i] - 128.0f);
		cft_ptr_cb_rgb[(i << 2) + 3] = cft_yuv_rgb_coeff[7] * ((Float32)cft_conv_u_itbl[i] - 128.0f);
		cft_ptr_cr_rgb[(i << 2) + 1] = cft_yuv_rgb_coeff[2] * ((Float32)cft_conv_v_itbl[i] - 128.0f);
		cft_ptr_cr_rgb[(i << 2) + 2] = cft_yuv_rgb_coeff[5] * ((Float32)cft_conv_v_itbl[i] - 128.0f);
		cft_ptr_cr_rgb[(i << 2) + 3] = cft_yuv_rgb_coeff[8] * ((Float32)cft_conv_v_itbl[i] - 128.0f);
	}
}
