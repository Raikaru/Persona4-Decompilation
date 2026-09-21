/* CRI Sofdec PTS queues (sfd_pts.c): the demuxer records the presentation time stamp of each video
 * packet together with its ring-buffer position; the video driver reads the entry whose position
 * matches the picture it decodes to timestamp the frame (SFPTS_ReadPtsQue). Storage comes from
 * SFD_SetVideoPts. */
#include "cri_xpt.h"
#include "sfd.h"
#include <string.h>

#define PQ(sfd, strm) ((sfd)->buf[strm].u.ring.ptsque)

typedef struct {
	Uint8 pad[0x1308];
	SFBUF_WORK w;
} SFBUF_HN;

#define SFBUF_GET_HN(sfd, n) ((SFBUF_HN *)((Uint8 *)(sfd) + (n) * sizeof(SFBUF_WORK)))


// Ring index wrap (n - num when n >= num).
static Sint32 sfpts_Wrap(Sint32 n, Sint32 num)
{
	Sint32 r;

	r = n - num;
	if (n < num) {
		r = n;
	}
	return r;
}

// Whether the PTS queue of ring `strm` is full (0 without a queue).
Sint32 SFPTS_IsPtsQueFull(SFD sfd, Sint32 strm)
{
	if (PQ(sfd, strm).ent == NULL) {
		return 0;
	}
	return PQ(sfd, strm).cnt >= PQ(sfd, strm).num;
}

/* Register order (all volatile, no calls): the CSE temporaries e->pos (st r3) and e->pos + e->len (en r0)
 * are coloured first, then the own locals in declaration order: idx r4, hn r7 (r5/r6 are pos/out),
 * i r8, e r9, end r10, ent r11, rd r12, num/ofst/size r31/r30/r29. The search loop is therefore
 * written in this function (a helper's counter would be coloured before hn); the found blocks keep
 * their `b found` through the codeless self copy (deleted by the RA, no register reserved).
 * COMPILER-DIFF: M1 (codeless arm) */
Sint32 SFPTS_ReadPtsQue(SFD sfd, Sint32 strm, Uint32 pos, SFPTS_ENT *out)
{
	Sint32 idx;
	SFBUF_HN *hn;
	register Sint32 i;
	SFPTS_ENT *e;
	Uint32 end;
	SFPTS_ENT *ent;
	Sint32 rd;
	Sint32 num;
	Uint32 ofst;
	Uint32 size;
	Sint32 cnt;
	Sint32 n;

	out->pts = -1;
	hn = SFBUF_GET_HN(sfd, strm);
	ent = hn->w.u.ring.ptsque.ent;
	ofst = hn->w.u.ring.sup.ofst;
	size = hn->w.u.ring.sup.size;
	if (ent == NULL) {
		return 0;
	}
	end = ofst + size;
	if (pos >= end) {
		pos -= size;
	}
	cnt = hn->w.u.ring.ptsque.cnt;
	if (cnt != 0) {
		num = hn->w.u.ring.ptsque.num;
		rd = hn->w.u.ring.ptsque.rd;
		idx = rd;
		for (i = 0; i < cnt; i++) {
			e = &ent[idx];
			if (e->pos + e->len <= end) {
				if (e->pos <= pos && pos < e->pos + e->len) {
					 // COMPILER-DIFF: M1 (codeless arm: keeps the found block as `b found`)
					goto found;
				}
			} else {
				if ((e->pos <= pos && pos < end) || (ofst <= pos && pos < e->pos + e->len - size)) {
					 // COMPILER-DIFF: M1 (codeless arm: keeps the found block as `b found`)
					goto found;
				}
			}
			n = idx + 1; /* sfpts_Wrap(idx + 1, num) written into idx (no helper copy) */
			idx = n - num;
			if (n < num) {
				idx = n;
			}
		}
		i = -1;
found:
		if (i != -1) {
			idx = sfpts_Wrap(rd + i, num);
			hn->w.u.ring.ptsque.cnt -= i;
			hn->w.u.ring.ptsque.rd = idx;
			*out = hn->w.u.ring.ptsque.ent[idx];
		}
	}
	return 0;
}

// Queues a (PTS, ring position, length) entry for ring `strm` (the demuxer records the PTS of each
// video packet); *full set when the queue is full; error 0xFF000421 when it was already full.
Sint32 SFPTS_WritePtsQue(SFD sfd, Sint32 strm, SFPTS_ENT *in, Sint32 *full)
{
	Sint32 wr;
	SFPTS_ENT *ent;
	Sint32 ret;

	*full = 0;
	if (in->pts < 0) {
		return 0;
	}
	ent = PQ(sfd, strm).ent;
	if (ent == NULL) {
		return 0;
	}
	if (PQ(sfd, strm).cnt == PQ(sfd, strm).num) {
		*full = 1;
		ret = -1;
	} else {
		wr = PQ(sfd, strm).wr;
		ent[wr] = *in;
		wr = sfpts_Wrap(wr + 1, PQ(sfd, strm).num);
		PQ(sfd, strm).cnt++;
		PQ(sfd, strm).wr = wr;
		if (PQ(sfd, strm).cnt >= PQ(sfd, strm).num) {
			*full = 1;
		} else {
			*full = 0;
		}
		ret = 0;
	}
	if (ret == -1) {
		return SFLIB_SetErr(sfd, 0xFF000421);
	}
	return 0;
}

// Gives the video ring (1) a PTS queue in the caller's buffer (8-byte aligned, 16 bytes per entry).
Sint32 SFD_SetVideoPts(SFD sfd, Uint8 *buf, Sint32 size)
{
	Uint8 *p;

	if (buf == NULL || size <= 0) {
		return 0;
	}
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000165);
	}
	p = (Uint8 *)(((Uint32)buf + 7) & ~7);
	size -= p - buf;
	memset(p, 0, size);
	sfd->buf[1].u.ring.ptsque.ent = (SFPTS_ENT *)p;
	sfd->buf[1].u.ring.ptsque.num = size / 16;
	sfd->buf[1].u.ring.ptsque.cnt = 0;
	sfd->buf[1].u.ring.ptsque.wr = 0;
	sfd->buf[1].u.ring.ptsque.rd = 0;
	return 0;
}

// Empty queue, no storage.
void SFPTS_InitPtsQue(SFPTS_QUE *que)
{
	que->ent = NULL;
	que->num = 0;
	que->cnt = 0;
	que->wr = 0;
	que->rd = 0;
}
