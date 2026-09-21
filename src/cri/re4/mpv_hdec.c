/* CRI Sofdec MPEG video: header decoding (sequence / GOP / picture / slice headers, user data) on a
 * stream joint. Header bits are read with the two-word bit reader (mpv_bit.h); the consumed bytes
 * are split off the chunk, returned to the free side and the rest is pushed back. */
#include "cri_xpt.h"
#include "sj.h"
#include "mpv.h"
#include "mpv_bit.h"

#define MPV_HDR_SEQ 1
#define MPV_HDR_GOP 2
#define MPV_HDR_PIC 3

#define MPV_DLM_SLICE 0x03
#define MPV_DLM_PIC 0x04
#define MPV_DLM_GOP 0x08
#define MPV_DLM_EXT 0x10
#define MPV_DLM_UD 0x20
#define MPV_DLM_SEQ 0x40
#define MPV_DLM_END 0x80

typedef void (*MPV_MCFUNC)(MPV mpv);

extern Sint32 MPVDEC_DecIpicMb();
extern Sint32 MPVDEC_DecPpicMb();
extern Sint32 MPVDEC_DecBpicMb();
extern Sint32 MPVDEC_DecDpicMb();
extern void MPVDEC_ResetMv(MPV_MV *mv);
extern void MPVDEC_ResetDc(MPV mpv);
extern Sint32 MPVCDEC_IntraBlocks(MPV mpv);
extern Sint32 MPVCDEC_NintraBlocks(MPV mpv);
extern Sint32 MPVABDEC_IntraBlock();
extern Sint32 MPVABDEC_IntraBlockDc11();
extern Sint32 MPVABDEC_NintraBlock();
extern Sint32 MPVM2V_DecodePicAtr(MPV mpv, SJ sj);
extern void MPVUMC_PpicSkipped(MPV mpv);
extern void MPVUMC_BpicSkipped(MPV mpv);
extern void MPVUMC_Intra(MPV mpv);
extern void MPVUMC_Forward(MPV mpv);
extern void MPVUMC_Backward(MPV mpv);
extern void MPVUMC_BiDirect(MPV mpv);
extern void UTY_MemcpyDword(void *dst, const void *src, Sint32 ndword);
extern void UTY_MemsetDword(void *dst, Sint32 val, Sint32 ndword);
extern void *memcpy(void *dst, const void *src, Uint32 n);
extern void *memset(void *dst, int c, Uint32 n);
extern int strncmp(const char *a, const char *b, Uint32 n);
extern int atoi(const char *s);

extern void *mpvvlc_y_dcsiz;
extern void *mpvvlc_c_dcsiz;
extern void *mpvvlc2_y_dcsiz;
extern void *mpvvlc2_c_dcsiz;
extern Sint8 mpvbdec_zigzag[64];
extern Uint8 mpvbdec_dfl_iqm[64];

Sint32 (*const dec_mbs_func[5])() = {
	NULL, MPVDEC_DecIpicMb, MPVDEC_DecPpicMb, MPVDEC_DecBpicMb, MPVDEC_DecDpicMb,
};

/* motion compensation entry points by [cond[6] != 3][picture type] */
static MPV_MCFUNC mc_bidirect_func[2][5];
MPV_MCFUNC mc_backward_func[2][5];
MPV_MCFUNC mc_forward_func[2][5];
static MPV_MCFUNC mc_intra_func[2][2][5];
static MPV_MCFUNC skip_func[2][5];

/* dead-stripped by the linker; its references put the tables in this .bss order */
void MPVHDEC_SetMcFunc(Sint32 dc11, Sint32 type, MPV_MCFUNC bi, MPV_MCFUNC bw, MPV_MCFUNC fw,
                       MPV_MCFUNC in, MPV_MCFUNC sk)
{
	mc_bidirect_func[dc11][type] = bi;
	mc_backward_func[dc11][type] = bw;
	mc_forward_func[dc11][type] = fw;
	mc_intra_func[0][dc11][type] = in;
	skip_func[dc11][type] = sk;
}

/* consume the header bytes up to the reader position: return them to the free side, push the rest
 * back to the data side (needs the locals `Uint8 *q`, `Uint32 *ptr`, `Sint32 bitpos`).
 * The byte pointer is `(Uint8 *)(ptr - 2) + n` (the two pre-loaded words as a word-pointer step): the
 * codegen emits `(ptr + n) - 8` with the sum a backend temporary created after the `ck.data` load, so
 * the sum takes the argument register and the load a fresh one (target `lwz r7; add r4; subi r0, r4,
 * 8; subf r4, r7, r0`); MPVBIT_BYTEPTR's `q = ptr; q += n; q -= 8` keeps q a variable ranked below
 * the load, and `ptr + n - 8` is folded to `ptr + (n - 8)` (CRI pass 14; replaced the pass-7 asm
 * `lwz data` pins here and in mpvhdec_DecSlice). */
#define MPVHDEC_BYTEPTR_M2(q) q = (Uint8 *)(ptr - 2) + ((bitpos + 7) >> 3)
#define MPVHDEC_FLUSH(mpv, sj)                                                                 \
	{                                                                                      \
		SJCK rest;                                                                     \
		MPVHDEC_BYTEPTR_M2(q);                                                         \
		SJ_SplitChunk(&(mpv)->ck, q - (mpv)->ck.data, &(mpv)->ck, &rest);              \
		SJ_PutChunk(sj, SJ_CK_FREE, &(mpv)->ck);                                       \
		SJ_UngetChunk(sj, SJ_CK_DATA, &rest);                                          \
	}


// Slice header: quantiser scale (and extra information bits), then hands the slice data to the
// picture type's macroblock decoder (dec_mbs_func) with the bit offset of the first macroblock.
static void mpvhdec_DecSlice(MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 *ptr;
	Uint32 bbuf;
	Uint32 nbuf;
	Uint32 val;
	Sint32 row;
	Uint8 *q;
	SJCK rest;

	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVBIT_INIT(mpv->ck.data);
	MPVBIT_GET32(val);
	row = (val & 0xFF) - 1;
	mpv->mb_addr = row * mpv->picatr.mb_width - 1;
	mpv->mb_y = row;
	mpv->mb_x = -1;
	MPVBIT_GET(mpv->qscale, 5);
	MPVDEC_ResetMv(&mpv->fwd);
	MPVDEC_ResetMv(&mpv->bwd);
	MPVDEC_ResetDc(mpv);
	for (;;) {
		val = bbuf >> 31;
		if (val == 0) {
			MPVBIT_SKIP(1);
			break;
		}
		MPVBIT_SKIP(9);
		MPVHDEC_BYTEPTR_M2(q);
		if (mpv->ck.len <= q - mpv->ck.data) {
			return;
		}
	}
	mpv->bitofs = bitpos & 7;
	q = (Uint8 *)(ptr - 2) + ((bitpos - mpv->bitofs + 7) >> 3);
	SJ_SplitChunk(&mpv->ck, q - mpv->ck.data, &mpv->ck, &rest);
	SJ_PutChunk(sj, SJ_CK_FREE, &mpv->ck);
	SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
	mpv->dec_mbs_func(mpv, sj);
}

// Moves `nbyte` bytes of a stream joint from side `id` to the other (DATA -> FREE consumes them);
// returns the bytes moved.
Sint32 MPV_MoveChunk(SJ sj, Sint32 id, Sint32 nbyte)
{
	SJCK ck;
	Sint32 dst;

	if (id == 0) {
		dst = 1;
	} else {
		dst = 0;
	}
	SJ_GetChunk(sj, id, nbyte, &ck);
	SJ_PutChunk(sj, dst, &ck);
	return ck.len;
}

/* MPV_GoNextDelimSj's body: inlined into mpvhdec_NextDelim / MPVHDEC_DecPicture, the public function
 * is emitted after MPVHDEC_DecPicture (the original's .text order) */
static Sint32 mpvhdec_GoNextDelim(SJ sj)
{
	SJCK ck;
	SJCK rest;
	Sint32 delim;
	Uint8 *p;

	for (;;) {
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &ck);
		if (ck.len < 4) {
			SJ_UngetChunk(sj, SJ_CK_DATA, &ck);
			delim = 0;
			break;
		}
		p = (Uint8 *)MPV_SearchDelim((Sint8 *)ck.data, ck.len, -1);
		if (p == NULL) {
			SJ_SplitChunk(&ck, ck.len - 3, &ck, &rest);
			SJ_PutChunk(sj, SJ_CK_FREE, &ck);
			SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
			continue;
		}
		delim = MPV_CheckDelim(p);
		SJ_SplitChunk(&ck, p - ck.data, &ck, &rest);
		SJ_PutChunk(sj, SJ_CK_FREE, &ck);
		SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
		break;
	}
	return delim;
}

/* account for a decoded picture, then skip to the next delimiter matching `mask`; returns -2 when
 * the picture is complete (or nothing was found in single-picture mode), -3 when no delimiter was
 * found, 0 when one was */
static Sint32 mpvhdec_NextDelim(MPV mpv, SJ sj, Sint32 mask)
{
	Sint32 ret;
	Sint32 delim;
	Sint32 c1;

	c1 = mpv->cond[1];
	if (mpv->pic_done != 0) {
		mpv->pic_done = 0;
		mpv->npic++;
		mpv->nfrm_dec++;
		if (c1 == 0) {
			return -2;
		}
		mpv->nbyte_dec++;
	}
	if (c1 == 0) {
		ret = -2;
	} else {
		ret = -3;
	}
	for (;;) {
		delim = mpvhdec_GoNextDelim(sj);
		if (delim == 0) {
			break;
		}
		if (delim & mask) {
			ret = 0;
			break;
		}
		if (MPV_MoveChunk(sj, SJ_CK_DATA, 4) != 4) {
			break;
		}
	}
	return ret;
}

// Decodes the slices of the picture whose headers were parsed by MPV_DecodePicAtrSj: repeatedly
// advances to the next start code and, while it is a slice, decodes it. Called by MPV_DecodeFrmSj.
Sint32 MPVHDEC_DecPicture(MPV mpv, SJ sj)
{
	SJCK ck;
	Sint32 ret;

	mpv->x1324 = mpv->cond[7];
	for (;;) {
		ret = mpvhdec_NextDelim(mpv, sj, -1);
		if (ret != 0) {
			return MPVERR_SetCode(mpv, ret);
		}
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &ck);
		SJ_UngetChunk(sj, SJ_CK_DATA, &ck);
		if (ck.len < 4) {
			break;
		}
		if ((MPV_CheckDelim(ck.data) & 1) == 0) {
			break;
		}
		mpvhdec_DecSlice(mpv, sj);
	}
	return 0;
}

/* the public copy of mpvhdec_GoNextDelim: a real function (its own locals: ck above rest on the
 * frame), emitted after MPVHDEC_DecPicture like the original */
Sint32 MPV_GoNextDelimSj(SJ sj)
{
	SJCK ck;
	SJCK rest;
	Sint32 delim;
	Uint8 *p;

	for (;;) {
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &ck);
		if (ck.len < 4) {
			SJ_UngetChunk(sj, SJ_CK_DATA, &ck);
			delim = 0;
			break;
		}
		p = (Uint8 *)MPV_SearchDelim((Sint8 *)ck.data, ck.len, -1);
		if (p == NULL) {
			SJ_SplitChunk(&ck, ck.len - 3, &ck, &rest);
			SJ_PutChunk(sj, SJ_CK_FREE, &ck);
			SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
			continue;
		}
		delim = MPV_CheckDelim(p);
		SJ_SplitChunk(&ck, p - ck.data, &ck, &rest);
		SJ_PutChunk(sj, SJ_CK_FREE, &ck);
		SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
		break;
	}
	return delim;
}

/* `p` is defined twice (`buf + i`, then the word step `+ 1`), which gives the target's `add p, buf, i;
 * addi p, p, 4` in place: `&buf[i + 4]` / `(buf + 4) + i` fold to `buf + (i + 4)` (index first), and with
 * range splitting on the two definitions become two webs (`add r3; addi r26, r3, 4`). */
// Sequence-level user data of the Sofdec encoder: "IDCPREC n" selects the 8- or 11-bit intra DC
// precision (and the matching DC size tables / intra block decoder), "STCCODE a b c" records the
// encoder's stream type codes (code 8 = unsupported -> -1).
Sint32 mpvhdec_DecSeqUdsc(MPV mpv, Char8 *buf, Sint32 len)
{
	Sint32 ret;
	Char8 *p;
	Sint32 i;

	ret = 0;
	for (i = 0; i < len - 4; i++) {
		p = buf + i;
		p = (Char8 *)((Uint32 *)p + 1);
		if (strncmp(p, "IDCPREC", 7) == 0) {
			if (atoi(p + 16) == 0) {
				mpv->dcprec = 0;
			} else {
				mpv->dcprec = 3;
			}
		}
		if (strncmp(p, "STCCODE", 7) == 0) {
			mpv->stc[0] = atoi(p + 16);
			mpv->stc[1] = atoi(p + 24);
			mpv->stc[2] = atoi(p + 32);
		}
		if (MPV_CheckDelim(p) != 0) {
			break;
		}
	}
	if (mpv->dcprec == 0) {
		mpv->intra_func = MPVABDEC_IntraBlock;
		mpv->dctbl_y = mpvvlc_y_dcsiz;
		mpv->dctbl_c = mpvvlc_c_dcsiz;
	} else {
		mpv->intra_func = MPVABDEC_IntraBlockDc11;
		mpv->dctbl_y = mpvvlc2_y_dcsiz;
		mpv->dctbl_c = mpvvlc2_c_dcsiz;
	}
	if (mpv->stc[0] == 8) {
		ret = -1;
	} else {
		if (mpv->dcprec == 0) {
			mpv->intra_func = MPVABDEC_IntraBlock;
		} else {
			mpv->intra_func = MPVABDEC_IntraBlockDc11;
		}
		mpv->nintra_func = MPVABDEC_NintraBlock;
	}
	return ret;
}


// A user data block (after 0x1B2) up to the next start code: parsed as sequence user data after a
// sequence header, copied into the user stream joint registered for the header type (MPV_SetUsrSj),
// and for picture user data copied into the picture user data buffer (Sofdec's per-frame data).
Sint32 mpvhdec_AnalyUd(MPV mpv, Uint8 *buf, Sint32 len)
{
	SJCK ck;
	SJCK ck2;
	Sint32 ret;
	Sint32 ret2;
	Sint32 type;
	Sint32 n;
	SJ sj;
	Sint32 siz;
	int i;

	ret2 = 0;
	ret = 0;
	type = mpv->hdrtype;
	/* n has one definition (below): a second one would be range-split into a temporary that ranks
	 * above type/ret/ret2 (CRI pass 11) */
	for (i = 4; i < len - 3; i++) {
		if (MPV_CheckDelim(buf + i) != 0) {
			break;
		}
	}
	if (i == len - 3) {
		ret = -1;
	}
	n = i;
	if (type == MPV_HDR_SEQ) {
		ret2 = mpvhdec_DecSeqUdsc(mpv, (Char8 *)buf, i);
	}
	sj = mpv->usr[type].sj;
	if (sj != NULL) {
		SJ_GetChunk(sj, SJ_CK_FREE, n, &ck);
		memcpy(ck.data, buf, ck.len);
		SJ_PutChunk(sj, SJ_CK_DATA, &ck);
		if (ck.len < n) {
			SJ_GetChunk(sj, SJ_CK_FREE, n - ck.len, &ck2);
			memcpy(ck2.data, buf + ck.len, ck2.len);
			SJ_PutChunk(sj, SJ_CK_DATA, &ck2);
		}
		if (mpv->usr[type].func != NULL) {
			mpv->usr[type].func(mpv->usr[type].obj, type);
		}
	}
	if (type == MPV_HDR_PIC && mpv->picusr_buf != NULL) {
		siz = mpv->picusr_bufsiz;
		if (n < siz) {
			siz = n;
		}
		mpv->picusr_len = siz;
		memcpy(mpv->picusr_buf, buf, mpv->picusr_len);
	}
	if (ret2 != 0) {
		return ret2;
	}
	return ret;
}

// Picture header (0x100): temporal reference, picture type, vbv_delay, the forward/backward vector
// f_codes (full_pel, r_size, shift, range), then selects the macroblock decoder, skip and motion
// compensation functions for the picture type / DC precision / cond 4, and skips the extra bits.
Sint32 mpvhdec_DecPscSj(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 *ptr;
	Uint32 nbuf;
	Uint32 val;
	Sint32 type;
	Sint32 dc11;
	Sint32 c4;
	Sint32 r_size;
	Uint8 *q;

	mpv->hdrtype = MPV_HDR_PIC;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVBIT_INIT(mpv->ck.data);
	MPVBIT_GET32(val);
	MPVBIT_GET(mpv->picatr.temp_ref, 10);
	MPVBIT_GET(val, 3);
	mpv->picatr.pic_type = val;
	MPVBIT_GET(mpv->vbv_delay, 16);
	type = mpv->picatr.pic_type;
	if (type == 2 || type == 3) {
		MPVBIT_GET1(mpv->fwd.full_pel);
		MPVBIT_GET(r_size, 3);
		mpv->fwd.r_size = --r_size; /* the decrement inside the store: a statement `r_size--` is forward-substituted into the three uses (CRI pass 13) */
		mpv->fwd.shift = 27 - r_size;
		mpv->fwd.f = 1 << r_size;
	}
	if (type == 3) {
		MPVBIT_GET1(mpv->bwd.full_pel);
		MPVBIT_GET(r_size, 3);
		mpv->bwd.r_size = --r_size; /* the decrement inside the store: a statement `r_size--` is forward-substituted into the three uses (CRI pass 13) */
		mpv->bwd.shift = 27 - r_size;
		mpv->bwd.f = 1 << r_size;
	}
	dc11 = (mpv->cond[6] == 3) ? 0 : 1; /* `!= 3` ranks the dc11*20 / type*4 index temporaries the other way (CRI pass 11) */
	c4 = mpv->cond[4];
	mpv->intra_blocks = MPVCDEC_IntraBlocks;
	mpv->nintra_blocks = MPVCDEC_NintraBlocks;
	mpv->dec_mbs_func = dec_mbs_func[type];
	mpv->skip_func = skip_func[dc11][type];
	mpv->mc_intra_func = mc_intra_func[c4][dc11][type];
	mpv->mc_func[1] = mc_backward_func[dc11][type];
	mpv->mc_func[2] = mc_forward_func[dc11][type];
	mpv->mc_func[3] = mc_bidirect_func[dc11][type];
	mpv->mc_func[0] = mpv->mc_func[2];
	for (;;) {
		val = bbuf >> 31;
		if (val == 0) {
			MPVBIT_SKIP(1);
			break;
		}
		MPVBIT_SKIP(9);
		MPVBIT_BYTEPTR(q);
		if (mpv->ck.len <= q - mpv->ck.data) {
			return -3;
		}
	}
	MPVHDEC_FLUSH(mpv, sj);
	return 0;
}

// GOP header (0x1B8): the 25-bit timecode (drop, h, m, s, pictures) into the picture attributes,
// closed_gop and broken_link.
static Sint32 mpvhdec_DecGscSj(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 *ptr;
	Uint32 nbuf;
	Uint32 val;
	Uint32 tc;
	Uint8 *q;

	mpv->hdrtype = MPV_HDR_GOP;
	mpv->picatr.ngop++;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVBIT_INIT(mpv->ck.data);
	MPVBIT_GET32(val);
	MPVBIT_GET(tc, 25);
	mpv->picatr.tc_pic = tc & 0x3F;
	mpv->picatr.tc_sec = (tc >> 6) & 0x3F;
	mpv->picatr.tc_min = (tc >> 13) & 0x3F;
	mpv->picatr.tc_hour = (tc >> 19) & 0x1F;
	mpv->picatr.tc_drop = tc >> 24;
	MPVBIT_GET1(mpv->linkflg1);
	MPVBIT_GET1(mpv->linkflg2);
	MPVHDEC_FLUSH(mpv, sj);
	return 0;
}

// Sequence header (0x1B3): picture size (and macroblock counts), aspect ratio, picture rate code,
// bit rate, vbv buffer size, constrained flag and the optional intra / non-intra quantiser matrices
// (default matrices otherwise); resets the picture attributes for a new sequence.
Sint32 mpvhdec_DecShcSj(register MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 bbuf;
	Uint32 *ptr;
	Uint32 nbuf;
	Uint32 val;
	Sint32 i;
	Uint8 *q;

	mpv->hdrtype = MPV_HDR_SEQ;
	mpv->picatr.nseq++;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVBIT_INIT(mpv->ck.data);
	MPVBIT_GET32(val);
	MPVBIT_GET(mpv->picatr.width, 12);
	MPVBIT_GET(mpv->picatr.height, 12);
	MPVBIT_GET(mpv->aspect, 4);
	MPVBIT_GET(val, 4);
	mpv->picatr.frame_rate = val;
	MPVBIT_GET(mpv->bitrate, 18);
	MPVBIT_SKIP(1);
	MPVBIT_GET(mpv->vbv_size, 10);
	MPVBIT_GET1(mpv->constrained);
	MPVBIT_GET1(val);
	if (val != 0) {
		for (i = 0; i < 64; i++) {
			MPVBIT_GET(val, 8);
			mpv->intra_iqm[mpvbdec_zigzag[i]] = val;
		}
	} else {
		UTY_MemcpyDword(mpv->intra_iqm, mpvbdec_dfl_iqm, 16);
	}
	MPVBIT_GET1(val);
	if (val != 0) {
		for (i = 0; i < 64; i++) {
			MPVBIT_GET(val, 8);
			mpv->nintra_iqm[mpvbdec_zigzag[i]] = val;
		}
	} else {
		UTY_MemsetDword(mpv->nintra_iqm, 0x10101010, 16);
	}
	mpv->picatr.mb_width = (mpv->picatr.width + 15) >> 4;
	mpv->picatr.mb_height = (mpv->picatr.height + 15) >> 4;
	mpv->mb_last = mpv->picatr.mb_height * mpv->picatr.mb_width - 1;
	mpv->picatr.bitrate = mpv->bitrate;
	mpv->picatr.vbv_size = mpv->vbv_size;
	mpv->picatr.aspect = mpv->aspect;
	mpv->picatr.constrained = mpv->constrained;
	MPVHDEC_FLUSH(mpv, sj);
	return 0;
}

Sint32 MPV_DecodePicAtrSj(MPV mpv, SJ sj);

// Decodes the headers found in a memory chunk (wrapped in a temporary memory joint) up to the first
// slice; *used = bytes consumed. Used by the SFD video driver for the user-supplied sequence header.
// FUN_00505360
Sint32 MPV_DecodePicAtr(MPV mpv, SJCK *ck, Sint32 *used)
{
	Sint32 ret;
	SJ sj;

	sj = SJMEM_Create(ck->data, ck->len);
	if (sj == NULL) {
		return -1;
	}
	ret = MPV_DecodePicAtrSj(mpv, sj);
	*used = ck->len - SJ_GetNumData(sj, SJ_CK_DATA);
	SJ_Destroy(sj);
	return ret;
}

/* MPEG-1 or MPEG-2? decided once from the start code following the first sequence header */
static Sint32 mpvhdec_GetM2vMode(MPV mpv, Sint8 *data, Sint32 len)
{
	Sint8 *p;
	Sint32 delim;

	if (mpv->m2v_mode != 0) {
		return mpv->m2v_mode;
	}
	p = MPV_SearchDelim(data, len, MPV_DLM_SEQ);
	if (p == NULL) {
		return mpv->m2v_mode;
	}
	p += 4;
	p = MPV_SearchDelim(p, len - (p - data), -1);
	if (p == NULL) {
		return mpv->m2v_mode;
	}
	delim = MPV_CheckDelim(p);
	if (delim & MPV_DLM_EXT) {
		mpv->m2v_mode = 2;
	} else if (delim != 0) {
		mpv->m2v_mode = 1;
	}
	return mpv->m2v_mode;
}

/* skip an extension / user data header: consume its 4 start-code bytes and go to the next delimiter.
 * Inline helpers (not macros) so that their `rest` chunks are first-round inlined aggregates and the
 * GoNextDelim copies they call are second-round ones, laid out below the loop-top NextDelim's (frame
 * order own ck/ck2, the two rests, NextDelim's nested chunks, then these; CRI pass 13).
 * MPVHDEC_SETPOS_KEEP: the word pointer is assigned INSIDE the bit-position expression, so the
 * frontend cannot forward-substitute the single-use `bitpos` into the byte-pointer computation
 * (the nested assignment is a side effect): bitpos stays a variable coloured after ptr (EXT: ptr r4 /
 * bitpos r7) and, in the UD case, is computed before the mpvhdec_AnalyUd call (r26/r29 live across
 * it) like the target. MPVHDEC_SKIPWORD: `(Uint8 *)(ptr + 1) + n` - the codegen turns it into
 * `(ptr + n) + 4` with the sum a backend temporary created after the `ck.data` reload (r4 / r7);
 * `ptr + n + 4` is folded to `ptr + (n + 4)`, and a `q += ..` variable ranks below the reload (CRI pass
 * 14). */
#define MPVHDEC_SETPOS_KEEP(buf) \
	bitpos = ((Uint32)(buf) - (Uint32)(ptr = (Uint32 *)((Uint32)(buf) & ~3))) << 3
#define MPVHDEC_SKIPWORD(q) q = (Uint8 *)(ptr + 1) + ((bitpos + 7) >> 3)

// Skips an extension start code (0x1B5) and its data up to the next start code.
static inline void mpvhdec_SkipExt(MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 *ptr;
	Uint8 *q;
	SJCK rest;

	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVHDEC_SETPOS_KEEP(mpv->ck.data);
	MPVHDEC_SKIPWORD(q);
	SJ_SplitChunk(&mpv->ck, q - mpv->ck.data, &mpv->ck, &rest);
	SJ_PutChunk(sj, SJ_CK_FREE, &mpv->ck);
	SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
	MPV_GoNextDelimSj(sj);
}

// Analyses a user data block (mpvhdec_AnalyUd) and skips it.
static inline void mpvhdec_SkipUd(MPV mpv, SJ sj)
{
	Sint32 bitpos;
	Uint32 *ptr;
	Uint8 *q;
	SJCK rest;

	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &mpv->ck);
	MPVHDEC_SETPOS_KEEP(mpv->ck.data);
	mpvhdec_AnalyUd(mpv, mpv->ck.data, mpv->ck.len);
	MPVHDEC_SKIPWORD(q);
	SJ_SplitChunk(&mpv->ck, q - mpv->ck.data, &mpv->ck, &rest);
	SJ_PutChunk(sj, SJ_CK_FREE, &mpv->ck);
	SJ_UngetChunk(sj, SJ_CK_DATA, &rest);
	MPV_GoNextDelimSj(sj);
}

// Header pass of one picture: consumes sequence / GOP / picture headers, extensions and user data
// from the stream joint until the first slice (or the data ends), filling the picture attributes
// (MPV_GetPicAtr). The SFD video driver calls it before deciding to skip or decode the picture.
Sint32 MPV_DecodePicAtrSj(MPV hn, SJ sj)
{
	SJCK ck;
	SJCK ck2;
	Sint8 *data;
	Sint32 len;
	Sint32 delim;
	Sint32 ret;
	MPV mpv;

	mpv = (MPV)(MPV_OBJ *)hn; /* kept copy (explicit cast): mpv r28 above sj r27, CRI pass 12 rule */
	if (MPVLIB_CheckHn(mpv) != 0) {
		return MPVERR_SetCode(NULL, 0xFF03020C);
	}
	mpv->picusr_len = 0;
	SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &ck);
	SJ_UngetChunk(sj, SJ_CK_DATA, &ck);
	data = (Sint8 *)ck.data;
	len = ck.len;
	if (mpvhdec_GetM2vMode(mpv, data, len) == 2) {
		return MPVM2V_DecodePicAtr(mpv, sj);
	}
	for (;;) {
		ret = mpvhdec_NextDelim(mpv, sj, -1);
		if (ret != 0) {
			return MPVERR_SetCode(mpv, ret);
		}
		SJ_GetChunk(sj, SJ_CK_DATA, 0x7FFFFFFF, &ck2);
		SJ_UngetChunk(sj, SJ_CK_DATA, &ck2);
		if (ck2.len < 4) {
			delim = 0;
		} else {
			delim = MPV_CheckDelim(ck2.data);
		}
		if (delim == 0 || (delim & MPV_DLM_SLICE)) {
			break;
		}
		switch (delim) {
		case MPV_DLM_SEQ:
			mpvhdec_DecShcSj(mpv, sj);
			break;
		case MPV_DLM_GOP:
			mpvhdec_DecGscSj(mpv, sj);
			break;
		case MPV_DLM_PIC:
			mpvhdec_DecPscSj(mpv, sj);
			break;
		case MPV_DLM_EXT:
			mpvhdec_SkipExt(mpv, sj);
			break;
		case MPV_DLM_UD:
			mpvhdec_SkipUd(mpv, sj);
			break;
		default:
			break;
		}
	}
	return ret;
}

// The user data of the last picture header (buffer and length).
void MPV_GetPicUsr(MPV mpv, Uint8 **buf, Sint32 *len)
{
	if (buf != NULL) {
		*buf = mpv->picusr_buf;
	}
	if (len != NULL) {
		*len = mpv->picusr_len;
	}
}

// Buffer that receives each picture's user data (Sofdec per-frame data, SFD_SetPicUsrBuf).
void MPV_SetPicUsrBuf(MPV mpv, Uint8 *buf, Sint32 bufsiz)
{
	mpv->picusr_buf = buf;
	mpv->picusr_bufsiz = bufsiz;
	mpv->picusr_len = 0;
}

// Stream joint (+ notification callback) that receives the user data of header type `id`
// (1 sequence, 2 GOP, 3 picture).
void MPV_SetUsrSj(MPV mpv, Sint32 id, SJ sj, void (*func)(void *obj, Sint32 id), void *obj)
{
	MPV_USRSJ *usr = &mpv->usr[id];

	usr->sj = sj;
	usr->func = func;
	usr->obj = obj;
}

// Library init: the skip / intra / forward / backward / bidirectional macroblock output function
// tables by picture type (only the unified MC versions of mpv_umc.c are installed).
void MPVHDEC_Init(void)
{
	memset(skip_func, 0, sizeof(skip_func));
	memset(mc_intra_func, 0, sizeof(mc_intra_func));
	memset(mc_forward_func, 0, sizeof(mc_forward_func));
	memset(mc_backward_func, 0, sizeof(mc_backward_func));
	memset(mc_bidirect_func, 0, sizeof(mc_bidirect_func));
	skip_func[0][2] = MPVUMC_PpicSkipped;
	skip_func[0][3] = MPVUMC_BpicSkipped;
	mc_intra_func[0][0][1] = MPVUMC_Intra;
	mc_intra_func[0][0][2] = MPVUMC_Intra;
	mc_intra_func[0][0][3] = MPVUMC_Intra;
	mc_intra_func[0][0][4] = MPVUMC_Intra;
	mc_intra_func[1][0][1] = MPVUMC_Intra;
	mc_intra_func[1][0][2] = MPVUMC_Intra;
	mc_intra_func[1][0][3] = MPVUMC_Intra;
	mc_intra_func[1][0][4] = MPVUMC_Intra;
	mc_forward_func[0][2] = MPVUMC_Forward;
	mc_forward_func[0][3] = MPVUMC_Forward;
	mc_backward_func[0][3] = MPVUMC_Backward;
	mc_bidirect_func[0][3] = MPVUMC_BiDirect;
}
