/* CRI Sofdec: stream buffers between the transfer drivers (sfd_buf.c). Buffers 0..2 are ring buffers
 * (stream joints), 3/5 video frame tables, 4/6 audio output, 7 the user output channels. */
#include "cri_xpt.h"
#include "sj.h"
#include "sfd.h"

extern Sint32 SJRBF_GetFlowCnt(SJ sj, Sint32 id, Sint32 dir);
extern Sint32 SJMEM_GetBufSize(SJ sj);
extern void SFPTS_InitPtsQue(SFPTS_QUE *que);
extern SJ func_004ed600(void *buf, Sint32 bsize);

#define SFBUF_TR_NONE 9
#define SFBUF_PRV_XSIZE 0x800

/* buffer n is addressed as SFD + n * sizeof(SFBUF_WORK) with the offsets of buf[0] folded into the
 * displacements: a view of the SFD object shifted by n buffers */
typedef struct {
	Uint8 pad[0x1308];
	SFBUF_WORK w;
} SFBUF_HN;

#define SFBUF_GET_HN(sfd, n) ((SFBUF_HN *)((Uint8 *)(sfd) + (n) * sizeof(SFBUF_WORK)))

/* creation parameters of SFBUF_InitHn */
typedef struct {
	Sint32 x00;
	Uint32 adr;                /* 0x04 work base */
	Sint32 size[7];            /* 0x08 sizes of buffers 0..6 */
	Sint32 x24;
	Sint32 unit;               /* 0x28 ring buffer 0 alignment */
} SFBUF_PRM;

static const SJUUID *sfbuf_sjmem_uuid;
static const SJUUID *sfbuf_sjrbf_uuid;

// The stream joint is a memory joint (UUID compare).
static Bool sfbuf_IsSjmem(SJ sj)
{
	if (SJ_GetUuid(sj) == sfbuf_sjmem_uuid) {
		return 1;
	}
	return 0;
}

// The stream joint is a ring-buffer joint.
static Bool sfbuf_IsSjrbf(SJ sj)
{
	if (SJ_GetUuid(sj) == sfbuf_sjrbf_uuid) {
		return 1;
	}
	return 0;
}

// Extends a 32-bit ring position into the 64-bit flow counter `cnt`: bumps the high word when the
// position wrapped below the previous low word (stream counters in the player information).
Sint64 SFBUF_UpdateFlowCnt(Sint64 cnt, Uint32 pos)
{
	Sint64 up;
	Sint64 hi;

	if (pos < (Uint32)cnt) {
		up = 1;
	} else {
		up = 0;
	}
	hi = cnt >> 32;
	hi += up;
	hi <<= 32;
	hi |= pos;
	return hi;
}

// Bytes ever written / read through a supply joint (ring: SJRBF put counters; memory joint: size and
// size minus what is left).
// FUN_00515A10
void SFBUF_GetFlowCnt(SJ sj, Sint32 *wcnt, Sint32 *rcnt)
{
	if (sfbuf_IsSjrbf(sj)) {
		*wcnt = SJRBF_GetFlowCnt(sj, 1, 1);
		*rcnt = SJRBF_GetFlowCnt(sj, 0, 1);
	} else if (sfbuf_IsSjmem(sj)) {
		*wcnt = SJMEM_GetBufSize(sj);
		*rcnt = *wcnt - SJ_GetNumData(sj, 1);
	} else {
		*wcnt = 0;
		*rcnt = 0;
	}
}

/* a flow total counts only while it is not unknown (-1) */
static void sfbuf_AddTot(Sint32 *tot, Sint32 nbyte)
{
	if (*tot >= 0) {
		*tot += nbyte;
	}
}

/* the two chunks (before / after the wrap) that make up the data of `id` */
static void sfbuf_RingGetCk(SJ sj, Sint32 id, SJCK *ck1, SJCK *ck2)
{
	Sint32 num;

	num = SJ_GetNumData(sj, id);
	SJ_GetChunk(sj, id, 0x7FFFFFFF, ck1);
	if (ck1->len < num) {
		SJ_GetChunk(sj, id, 0x7FFFFFFF, ck2);
		SJ_UngetChunk(sj, id, ck2);
	} else {
		ck2->data = NULL;
		ck2->len = 0;
	}
	SJ_UngetChunk(sj, id, ck1);
}

/* the body is a static helper: its len1/len2 are inlined-helper temporaries, so the backend CSE turns
 * len2's `li 0` into the target's `mr r5, r4` copy of len1 (it never rewrites a named variable's
 * `li`); len1 is assigned first (copy direction) and declared last (register r4) */
static Sint32 sfbuf_RingGetDataSizHn(SFBUF_HN *hn)
{
	SJ sj;
	SJCK ck1;
	SJCK ck2;
	Sint32 len2;
	Sint32 len1;

	len1 = 0;
	len2 = 0;
	sj = hn->w.u.ring.sup.sj;
	if (hn->w.used != 0 && sj != NULL) {
		sfbuf_RingGetCk(sj, 1, &ck1, &ck2);
		len1 = ck1.len;
		len2 = ck2.len;
	}
	return len1 + len2;
}

// Readable bytes of ring buffer `n` (both halves around the wrap).
Sint32 SFBUF_RingGetDataSiz(SFD sfd, Sint32 n)
{
	return sfbuf_RingGetDataSizHn(SFBUF_GET_HN(sfd, n));
}

// "no more data will arrive" flag of buffer n.
Sint32 SFBUF_GetTermFlg(SFD sfd, Sint32 n)
{
	return sfd->buf[n].termflg;
}

// Sets the terminate flag (the writer driver ended; the reader drains and terminates too).
void SFBUF_SetTermFlg(SFD sfd, Sint32 n, Sint32 flg)
{
	sfd->buf[n].termflg = flg;
}

// "buffer is prepared/primed" flag of buffer n.
Sint32 SFBUF_GetPrepFlg(SFD sfd, Sint32 n)
{
	return sfd->buf[n].prepflg;
}

// Sets the prepared flag (the reader driver may start).
void SFBUF_SetPrepFlg(SFD sfd, Sint32 n, Sint32 flg)
{
	sfd->buf[n].prepflg = flg;
}

// Frame table buffer (3/5): returns a frame to the driver that wrote it (its AddRead, fn 12) and
// flags a change; used by the manual video output when the user releases a frame.
Sint32 SFBUF_VfrmAddRead(SFD sfd, Sint32 n, void *frm)
{
	Sint32 ret = 0;
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);

	if (hn->w.used == 0) {
		ret = SFTRN_CallTrtTrif(sfd, hn->w.in_tr, 0xC, (Sint32)frm, 0);
	}
	sfd->chg_flg = 1;
	return ret;
}

// Frame table buffer: asks the writer driver (the MPV video driver) for the next displayable frame.
Sint32 SFBUF_VfrmGetRead(SFD sfd, Sint32 n, void **frm)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);

	if (hn->w.used == 0) {
		return SFTRN_CallTrtTrif(sfd, hn->w.in_tr, 0xB, (Sint32)frm, 0);
	}
	return 0;
}

// Advances the ring's total-read counter (when known).
void SFBUF_AddRtotSj(SFD sfd, Sint32 n, Sint32 nbyte)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);

	if (hn->w.u.ring.rtot >= 0) {
		hn->w.u.ring.rtot += nbyte;
	}
}

// The supply stream joint of ring buffer n (error 0xFF000401 when unsupplied).
Sint32 SFBUF_RingGetSj(SFD sfd, Sint32 n, SJ *sj)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);

	*sj = NULL;
	if (hn->w.used == 0) {
		return SFLIB_SetErr(sfd, 0xFF000401);
	}
	*sj = hn->w.u.ring.sup.sj;
	return 0;
}

// Total bytes written into ring n; derived from rtot + pending data when the writer does not count,
// INT_MAX when unknown (-1). sfply_StatPrep drops a stream whose buffer never got data.
Sint32 SFBUF_GetWTot(SFD sfd, Sint32 n)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);
	Sint32 cs;
	Sint32 wtot;
	Sint32 rtot;

	SFLIB_LockCs(&cs);
	wtot = hn->w.u.ring.wtot;
	rtot = hn->w.u.ring.rtot;
	if (wtot == 0 && rtot != 0) {
		wtot = rtot + SJ_GetNumData(hn->w.u.ring.sup.sj, 1);
	}
	if (wtot < 0) {
		wtot = 0x7FFFFFFF;
	}
	SFLIB_UnlockCs(&cs);
	return wtot;
}

// Total bytes read from ring n.
Sint32 SFBUF_GetRTot(SFD sfd, Sint32 n)
{
	return sfd->buf[n].u.ring.rtot;
}

// Size of ring buffer n in bytes.
Sint32 SFBUF_GetRingBufSiz(SFD sfd, Sint32 n)
{
	return sfd->buf[n].u.ring.sup.size;
}

// Records where the demuxer found the next start-code delimiter in ring n (position/length), so the
// video driver can stop at picture boundaries.
void SFBUF_RingSetDlm(SFD sfd, Sint32 n, Uint8 *pos, Sint32 len)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);
	Sint32 cs;

	SFLIB_LockCs(&cs);
	hn->w.u.ring.dlm_pos = pos;
	hn->w.u.ring.dlm_len = len;
	SFLIB_UnlockCs(&cs);
}

// Reads the recorded delimiter of ring n.
void SFBUF_RingGetDlm(SFD sfd, Sint32 n, Uint8 **pos, Sint32 *len)
{
	SFBUF_HN *hn = SFBUF_GET_HN(sfd, n);
	Sint32 cs;

	SFLIB_LockCs(&cs);
	*pos = hn->w.u.ring.dlm_pos;
	*len = hn->w.u.ring.dlm_len;
	SFLIB_UnlockCs(&cs);
}

/* AddRead/AddWrite: the bodies are inlined helpers so that the first arm's `ret = 0` is a helper
 * temporary (the backend CSE turns it into the entry zero and the arm empties: `bne body; b end`);
 * the helper locals are declared in reverse of the target's register order. `ring` is reached in two
 * steps through `wk` (an own local with its own uses): add-propagation folds `addi wk` into
 * `addi ring, wk, 0x10` but never propagates the addi it has just rewritten, so `ring` stays a node
 * (`addi rR, hn, 0x1318`) while the sj/used reads through wk fold into hn. The delimiter check reads
 * `ring->dlm_pos` inline (a `pos` local would outrank the ck.data CSE temporaries). */
static inline Sint32 sfbuf_RingAddReadSub(SFD sfd, Sint32 n, Sint32 nbyte)
{
	SJCK ck1;
	SJCK ckw;
	Sint32 ret = 0;
	Sint32 rest;
	SJCK ck2;
	SJCK ck;
	SJ sj2;
	SJ sj;
	SFBUF_RING *ring;
	SFBUF_WORK *wk;
	SFBUF_HN *hn;

	hn = SFBUF_GET_HN(sfd, n);
	wk = &hn->w;
	ring = &wk->u.ring;
	sj = hn->w.u.ring.sup.sj;
	if (nbyte == 0) {
		ret = 0;
	} else if (wk->used == 0 || sj == NULL) {
		ret = 0;
	} else {
		SJ_GetChunk(sj, 1, nbyte, &ck);
		SJ_PutChunk(sj, 0, &ck);
		if (ck.len < nbyte) {
			rest = nbyte - ck.len;
			SJ_GetChunk(sj, 1, rest, &ck2);
			SJ_PutChunk(sj, 0, &ck2);
			if (ck2.len < rest) {
				ret = SFLIB_SetErr(sfd, 0xFF00040B);
			}
		}
		if (n == 1) {
			sj2 = ring->sup.sj;
			sfbuf_RingGetCk(sj2, 1, &ck1, &ckw);
			if ((ring->dlm_pos < ck1.data || ring->dlm_pos >= ck1.data + ck1.len) && (ring->dlm_pos < ckw.data || ring->dlm_pos >= ckw.data + ckw.len)) {
				ring->dlm_pos = NULL;
				ring->dlm_len = 0;
			}
		}
		sfbuf_AddTot(&ring->rtot, nbyte);
		sfd->chg_flg = 1;
	}
	return ret;
}

// Consumes `nbyte` bytes of ring n (DATA -> FREE, in up to two chunks around the wrap); on the video
// ring (1) forgets the delimiter if it was consumed; adds to rtot and flags a change. Error
// 0xFF00040B on underflow.
Sint32 SFBUF_RingAddRead(SFD sfd, Sint32 n, Sint32 nbyte)
{
	return sfbuf_RingAddReadSub(sfd, n, nbyte);
}

// Commits `nbyte` bytes written into ring n (FREE -> DATA, two chunks around the wrap), adds to wtot
// and flags a change; error 0xFF00040B on overflow.
static inline Sint32 sfbuf_RingAddWriteSub(SFD sfd, Sint32 n, Sint32 nbyte)
{
	Sint32 rest;
	Sint32 ret = 0;
	SJCK ck2;
	SJCK ck;
	SFBUF_RING *ring;
	SJ sj;
	SFBUF_WORK *wk;
	SFBUF_HN *hn;

	hn = SFBUF_GET_HN(sfd, n);
	wk = &hn->w;
	ring = &wk->u.ring;
	sj = hn->w.u.ring.sup.sj;
	if (nbyte == 0) {
		ret = 0;
	} else if (wk->used == 0 || sj == NULL) {
		ret = 0;
	} else {
		SJ_GetChunk(sj, 0, nbyte, &ck);
		SJ_PutChunk(sj, 1, &ck);
		if (ck.len < nbyte) {
			rest = nbyte - ck.len;
			SJ_GetChunk(sj, 0, rest, &ck2);
			SJ_PutChunk(sj, 1, &ck2);
			if (ck2.len < rest) {
				ret = SFLIB_SetErr(sfd, 0xFF00040B);
			}
		}
		sfbuf_AddTot(&ring->wtot, nbyte);
		sfd->chg_flg = 1;
	}
	return ret;
}

// Public wrapper of sfbuf_RingAddWriteSub (the memory input driver's AddWrite).
Sint32 SFBUF_RingAddWrite(SFD sfd, Sint32 n, Sint32 nbyte, Sint32 rsv)
{
	return sfbuf_RingAddWriteSub(sfd, n, nbyte);
}

/* the handle address is computed AFTER the inf clear (in both Get functions): the n*0x74 product is
 * then the younger temporary and takes r0 while the zero takes the dying r5, and inf lives in r31
 * from the top */
Sint32 SFBUF_RingGetRead(SFD sfd, Sint32 n, SFBUF_RINF *inf)
{
	SFBUF_HN *hn;
	SJ sj;
	SJCK ck2;
	SJCK ck1;

	inf->ck1.data = NULL;
	inf->ck1.len = 0;
	inf->ck2.data = NULL;
	inf->ck2.len = 0;
	inf->rsv[0] = 0;
	inf->rsv[1] = 0;
	inf->rsv[2] = 0;
	hn = SFBUF_GET_HN(sfd, n);
	sj = hn->w.u.ring.sup.sj;
	if (hn->w.used == 0 || sj == NULL) {
		return 0;
	}
	sfbuf_RingGetCk(sj, 1, &ck1, &ck2);
	inf->ck1.data = ck1.data;
	inf->ck1.len = ck1.len;
	inf->ck2.data = ck2.data;
	inf->ck2.len = ck2.len;
	return 0;
}

// Writable region of ring n as two chunks (before / after the wrap) in `inf`.
Sint32 SFBUF_RingGetWrite(SFD sfd, Sint32 n, SFBUF_RINF *inf)
{
	SFBUF_HN *hn;
	SJ sj;
	SJCK ck2;
	SJCK ck1;

	inf->ck1.data = NULL;
	inf->ck1.len = 0;
	inf->ck2.data = NULL;
	inf->ck2.len = 0;
	inf->rsv[0] = 0;
	inf->rsv[1] = 0;
	inf->rsv[2] = 0;
	hn = SFBUF_GET_HN(sfd, n);
	sj = hn->w.u.ring.sup.sj;
	if (hn->w.used == 0 || sj == NULL) {
		return 0;
	}
	sfbuf_RingGetCk(sj, 0, &ck1, &ck2);
	inf->ck1.data = ck1.data;
	inf->ck1.len = ck1.len;
	inf->ck2.data = ck2.data;
	inf->ck2.len = ck2.len;
	return 0;
}

// Copies user-output channel `chno` of buffer n.
void SFBUF_GetUoch(SFD sfd, Sint32 n, Sint32 chno, SFUO_CH *ch)
{
	*ch = sfd->buf[n].u.uoch[chno];
}

// Stores user-output channel `chno` (stream joint + parameter) into buffer n.
void SFBUF_SetUoch(SFD sfd, Sint32 n, Sint32 chno, SFUO_CH *ch)
{
	sfd->buf[n].u.uoch[chno] = *ch;
}

// Validates a supply: a joint is required; a memory-range supply (kind 0) needs a base, a positive
// size and no extra field.
static Sint32 sfbuf_CheckSup(SFBUF_SUP *sup)
{
	if (sup->sj == NULL) {
		return -1;
	}
	if (sup->kind == 0) {
		if (sup->ofst == 0) {
			return -1;
		}
		if (sup->size <= 0) {
			return -1;
		}
		if (sup->x14 > 0) {
			return -1;
		}
	}
	return 0;
}

// Installs a supply on a ring: copies it, clears the delimiter, totals and PTS queue.
static void sfbuf_SetSup(SFBUF_WORK *wk, SFBUF_RING *ring, SFBUF_SUP *sup, Sint32 used)
{
	Sint32 cs;

	SFLIB_LockCs(&cs);
	wk->used = used;
	ring->sup = *sup;
	ring->dlm_pos = NULL;
	ring->dlm_len = 0;
	ring->wtot = 0;
	ring->rtot = 0;
	SFPTS_InitPtsQue(&ring->ptsque);
	SFLIB_UnlockCs(&cs);
}

/* ring computed before the mode test through wk (two-step address, see AddRead); declared before
 * hn so it colours first (ring r29, hn r28) */
Sint32 SFBUF_SetSupplySj(SFD sfd, SFBUF_SUP *sup)
{
	Sint32 n;
	SFBUF_RING *ring;
	SFBUF_WORK *wk;
	SFBUF_HN *hn;

	if (sfbuf_CheckSup(sup) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000408);
	}
	if (SFTRN_IsSetup(sfd, 1)) {
		n = 0;
	} else if (SFTRN_IsSetup(sfd, 2)) {
		n = 1;
	} else if (SFTRN_IsSetup(sfd, 3)) {
		n = 2;
	} else {
		n = 0;
	}
	hn = SFBUF_GET_HN(sfd, n);
	wk = &hn->w;
	ring = &wk->u.ring;
	if (hn->w.mode != SFBUF_MODE_NONE) {
		return SFLIB_SetErr(sfd, 0xFF000409);
	}
	sfbuf_SetSup(wk, ring, sup, sup->sj != NULL);
	return 0;
}

// Destroys the supply's stream joint (library-created rings only).
static void sfbuf_DestroySup(SFBUF_SUP *sup)
{
	if (sup->sj != NULL) {
		SJ_Destroy(sup->sj);
		sup->sj = NULL;
	}
}

/* each sup pointer is `&wk->u.ring.sup` off a `wk` local that also tests the mode: the two-step
 * address keeps `addi sup, sfd, 0x1318 + n*0x74` as a node (three defs, one register) */
void SFBUF_DestroySj(SFD sfd)
{
	SFBUF_WORK *wk;
	SFBUF_SUP *sup;

	wk = &sfd->buf[0];
	sup = &wk->u.ring.sup;
	if (wk->mode == SFBUF_MODE_RING) {
		sfbuf_DestroySup(sup);
	}
	wk = &sfd->buf[1];
	sup = &wk->u.ring.sup;
	if (wk->mode == SFBUF_MODE_RING) {
		sfbuf_DestroySup(sup);
	}
	wk = &sfd->buf[2];
	sup = &wk->u.ring.sup;
	if (wk->mode == SFBUF_MODE_RING) {
		sfbuf_DestroySup(sup);
	}
}

/* the stream joint of a ring buffer of bsize bytes at adr (xsize of them the wrap area) */
static Sint32 sfbuf_CreateSj(SFBUF_SUP *sup, Uint32 adr, Sint32 bsize, Sint32 xsize)
{
	if (bsize <= 0) {
		return SFLIB_SetErr(NULL, 0xFF00040C);
	}
	sup->xsize = xsize;
	sup->x14 = 0;
	sup->sj = SJRBF_Create((void *)adr, bsize, xsize);
	if (sup->sj == NULL) {
		return SFLIB_SetErr(NULL, 0xFF00040A);
	}
	return 0;
}

/* ring buffer of `size` bytes at adr; size 0 leaves the buffer unsupplied */
static Sint32 sfbuf_InitRing(SFBUF_WORK *wk, Uint32 *adr, Sint32 size, Sint32 xsize)
{
	Sint32 used;
	Sint32 mode;
	SFBUF_SUP sup;
	Sint32 err;

	if (size == 0) {
		used = 0;
		mode = SFBUF_MODE_NONE;
	} else {
		used = 1;
		mode = SFBUF_MODE_RING;
		sup.kind = 0;
		sup.ofst = *adr;
		sup.size = size - xsize;
		err = sfbuf_CreateSj(&sup, *adr, sup.size, xsize);
		if (err != 0) {
			return err;
		}
		sfbuf_SetSup(wk, &wk->u.ring, &sup, 1);
	}
	wk->mode = mode;
	wk->used = used;
	wk->prepflg = 0;
	wk->termflg = 0;
	wk->in_tr = SFBUF_TR_NONE;
	wk->out_tr = SFBUF_TR_NONE;
	return 0;
}

/* Vfrm/Aout take the size by pointer and read it twice: `used` before the mode store, the size
 * field after the adr store (the target reloads it there) */
static void sfbuf_InitVfrm(SFD sfd, SFBUF_WORK *wk, Uint32 *adr, Sint32 *size)
{
	Sint32 i;
	Sint32 used;

	used = (*size != 0);
	wk->mode = SFBUF_MODE_VFRM;
	wk->used = used;
	wk->prepflg = 0;
	wk->termflg = 0;
	wk->in_tr = SFBUF_TR_NONE;
	wk->out_tr = SFBUF_TR_NONE;
	wk->u.vfrm.adr = *adr;
	wk->u.vfrm.size = *size;
	wk->u.vfrm.x18 = 0;
	wk->u.vfrm.x1c = 0;
	wk->u.vfrm.vfrm = sfd->vfrm;
	for (i = 0; i < SFD_VFRM_NUM; i++) {
		wk->u.vfrm.vfrm[i].frm = NULL;
	}
}

// Audio output buffer (4/6): records the region and clears the reserve words; used only when a size
// was given.
static void sfbuf_InitAout(SFBUF_WORK *wk, Uint32 *adr, Sint32 *size)
{
	Sint32 i;
	Sint32 used;

	used = (*size != 0);
	wk->mode = SFBUF_MODE_AOUT;
	wk->used = used;
	wk->prepflg = 0;
	wk->termflg = 0;
	wk->in_tr = SFBUF_TR_NONE;
	wk->out_tr = SFBUF_TR_NONE;
	wk->u.aout.adr = *adr;
	wk->u.aout.size = *size;
	for (i = 0; i < 7; i++) {
		wk->u.aout.rsv[i] = 0;
	}
	wk->u.aout.rsv2[0] = 0;
	wk->u.aout.rsv2[1] = 0;
	wk->u.aout.rsv2[2] = 0;
}

/* adr[] stays a stack array (9 elements: with 8 the backend's array-register transform turns it into
 * registers) and the running address is one variable stored through a stepping pointer: the chain is
 * then a single register and the first InitRing reloads adr[0] from the frame like the target */
Sint32 SFBUF_InitHn(SFD sfd, SFBUF_WORK *wk, SFBUF_PRM *prm)
{
	Uint32 adr[9];
	Sint32 xsize;
	Sint32 err;
	Sint32 i;
	Uint32 *p;
	Uint32 a;

	a = prm->adr;
	p = adr;
	for (i = 0; i < 7; i++) {
		*p++ = a;
		a += prm->size[i];
	}
	*p = a;
	xsize = prm->size[0] % prm->unit;
	err = sfbuf_InitRing(&wk[0], &adr[0], prm->size[0], xsize);
	if (err != 0) {
		return err;
	}
	err = sfbuf_InitRing(&wk[1], &adr[1], prm->size[1], SFBUF_PRV_XSIZE);
	if (err != 0) {
		return err;
	}
	err = sfbuf_InitRing(&wk[2], &adr[2], prm->size[2], 0);
	if (err != 0) {
		return err;
	}
	sfbuf_InitVfrm(sfd, &wk[3], &adr[3], &prm->size[3]);
	sfbuf_InitAout(&wk[4], &adr[4], &prm->size[4]);
	sfbuf_InitVfrm(sfd, &wk[5], &adr[5], &prm->size[5]);
	sfbuf_InitAout(&wk[6], &adr[6], &prm->size[6]);
	wk[7].mode = SFBUF_MODE_UO;
	wk[7].used = 1;
	wk[7].prepflg = 0;
	wk[7].termflg = 0;
	wk[7].in_tr = SFBUF_TR_NONE;
	wk[7].out_tr = SFBUF_TR_NONE;
	for (i = 0; i < 3; i++) {
		wk[7].u.uoch[i].sj = NULL;
		wk[7].u.uoch[i].prm = NULL;
		wk[7].u.uoch[i].rsv1 = 0;
		wk[7].u.uoch[i].rsv2 = 0;
	}
	return 0;
}

// Library init: learns the UUIDs of the ring-buffer and memory joint classes from throwaway objects
// so sfbuf_IsSjrbf/IsSjmem can classify supplies.
// FUN_00515AC8
void SFBUF_Init(void *work)
{
	Uint8 dmy[8];
	SJ sj;

	sj = SJRBF_Create(dmy, 8, 0);
	sfbuf_sjrbf_uuid = SJ_GetUuid(sj);
	SJ_Destroy(sj);
	sj = func_004ed600(dmy, 8);
	sfbuf_sjmem_uuid = SJ_GetUuid(sj);
	SJ_Destroy(sj);
}
