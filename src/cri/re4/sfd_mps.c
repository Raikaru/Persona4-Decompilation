/* CRI Sofdec: MPEG system stream driver (sfd_mps.c). Transfer driver 1: takes the muxed stream out
 * of ring buffer 0, demultiplexes it through an MPS handle and copies the packet payloads into the
 * video (buf 1), audio (buf 2) and private/user-output (buf 7) buffers or user element stream joints.
 *
 * Status: 25/26 functions identical. sfmps_DecodeOneUnit (5w: the scan counter's colour r21/r23,
 * one M1 pin) has the target's instruction stream with a different register assignment. */
#include "cri_xpt.h"
#include "sfd.h"
#include "mps.h"
#include "sj.h"

extern void MEM_Copy(void *dst, const void *src, Uint32 nbytes);
extern Sint32 SFBUF_GetWTot(SFD sfd, Sint32 buf);
extern Sint32 SFBUF_GetRTot(SFD sfd, Sint32 buf);
extern Sint32 SFBUF_RingGetRead(SFD sfd, Sint32 buf, SFBUF_RINF *inf);
extern Sint32 SFBUF_RingAddRead(SFD sfd, Sint32 buf, Sint32 nbyte);
extern void SFBUF_GetFlowCnt(SJ sj, Sint32 *wcnt, Sint32 *rcnt);
extern Sint64 SFBUF_UpdateFlowCnt(Sint64 cnt, Uint32 pos);
extern void SFBUF_SetTermFlg(SFD sfd, Sint32 buf, Sint32 flg);
extern void SFBUF_GetUoch(SFD sfd, Sint32 buf, Sint32 chno, SFUO_CH *ch);
extern Sint32 SFPTS_IsPtsQueFull(SFD sfd, Sint32 strm);
extern Sint32 SFPTS_WritePtsQue(SFD sfd, Sint32 strm, SFPTS_ENT *in, Sint32 *full);
extern Sint32 SFCON_IsSystemEndcodeSkip(SFD sfd);
extern Sint32 (*SFPLY_SetPtsInfo)(SFPLY_PTSM *ptsm, SFPTS_ENT *ent);
extern Sint32 MPS_SetErrFn(MPS mps, void (*fn)(void *obj, Sint32 code), void *obj);
extern void MPS_SetPesFn(MPS mps, void *fn, void *obj);
extern void MPS_SetPsMapFn(MPS mps, void *fn, void *obj);
extern void MPS_SetSystemFn(MPS mps, void *fn, void *obj);
extern Sint32 MPS_Init(Sint32 num_hn, void *work);
extern void MPS_Finish(void);

#define SFMPS_TR 1
#define SFMPS_NUM_HN 8
#define SFMPS_WORK_MAX 0x200

/* SFD condition ids */
#define SFD_COND_VIDEO_ON 0x05
#define SFD_COND_PREPSIZE 0x16
#define SFD_COND_AUDIO_ON 0x06
#define SFD_COND_VID_STMID 0x1D
#define SFD_COND_AUD_STMID 0x1E
#define SFD_COND_STMID_STRICT 0x37
#define SFD_COND_VID_SELECT 0x3B
#define SFD_COND_AUDIO_AUTO_OFF 0x4F
#define SFD_COND_VIDEO_AUTO_OFF 0x50
#define SFD_COND_SYSFN 0x55
#define SFD_COND_SYSOBJ 0x56
#define SFD_COND_PSMAPFN 0x57
#define SFD_COND_PSMAPOBJ 0x58
#define SFD_COND_PESFN 0x5B
#define SFD_COND_PESOBJ 0x5C

/* error codes */
#define SFMPS_ERR_INIT 0xFF000D01
#define SFMPS_ERR_DECHD 0xFF000D03
#define SFMPS_ERR_PKETHD 0xFF000D06
#define SFMPS_ERR_CREATE 0xFF000D08
#define SFMPS_ERR_SETERRFN 0xFF000D09
#define SFMPS_ERR_DESTROY 0xFF000D0A
#define SFMPS_ERR_NOTSUPPORTED 0xFF000D0B
#define SFMPS_ERR_WORKSIZE 0xFF000D0C
#define SFMPS_ERR_SEEK 0xFF000D0D
#define SFMPS_ERR_PKETLEN 0xFF000D0E
#define SFD_ERR_SETELEMOUTSJ 0xFF000171

/* MPS_DecHd flags */
#define MPS_DECHD_SYSHD 0x00020000
#define MPS_DECHD_PKET 0x00040000
#define MPS_DECHD_END 0x00080000

/* packet header type field (MPS_PKETHD.raw[MPS_PKT_TYPE]) */
#define SFMPS_PKT_AUDIO 0
#define SFMPS_PKT_VIDEO 1
#define SFMPS_PKT_PRIVATE 2
#define SFMPS_PKT_PADDING 3

#define INT64_MAX_VAL 0x7FFFFFFFFFFFFFFF

typedef Sint32 (*SFMPS_COPYFN)(SFD sfd, Sint32 stmid, Uint8 *data, Sint32 len, Sint64 pts);
typedef void (*SFMPS_UOCB)(void *obj, Sint32 chno);

static Sint32 copy_sj_error;
static Uint8 sfmps_libwork[0x10 + SFMPS_NUM_HN * sizeof(MPS_OBJ)];

/* buffer n addressed as SFD + n * sizeof(SFBUF_WORK) (sfd_buf.c's SFBUF_HN view) */
typedef struct {
	Uint8 pad[0x1308];
	SFBUF_WORK w;
} SFMPS_BUFHN;

#define SFMPS_BUF_HN(sfd, n) ((SFMPS_BUFHN *)((Uint8 *)(sfd) + (n) * sizeof(SFBUF_WORK)))

#define SFMPS_WK(sfd) ((SFMPS_WORK *)(sfd)->tr[SFMPS_TR].hn)
#define SFMPS_MPS(sfd) (SFMPS_WK(sfd)->mps)

Sint32 SFMPS_Init(void);
Sint32 SFMPS_Finish(void);
static Sint32 SFMPS_ExecServer(SFD sfd);
Sint32 SFMPS_Create(SFD sfd);
Sint32 SFMPS_Destroy(SFD sfd);
Sint32 SFMPS_Standby(SFD sfd);
Sint32 SFMPS_Start(SFD sfd);
Sint32 SFMPS_Stop(SFD sfd);
Sint32 SFMPS_Pause(SFD sfd);
Sint32 SFMPS_GetWrite(SFD sfd);
Sint32 SFMPS_AddWrite(SFD sfd);
Sint32 SFMPS_GetRead(SFD sfd);
Sint32 SFMPS_AddRead(SFD sfd);
static Sint32 SFMPS_Seek(SFD sfd);

const SFD_TR_IF SFD_tr_sd_mps = {
	SFMPS_Init,
	SFMPS_Finish,
	SFMPS_ExecServer,
	SFMPS_Create,
	SFMPS_Destroy,
	SFMPS_Standby,
	SFMPS_Start,
	SFMPS_Stop,
	SFMPS_Pause,
	SFMPS_GetWrite,
	SFMPS_AddWrite,
	SFMPS_GetRead,
	SFMPS_AddRead,
	SFMPS_Seek,
};

// Program end codes passed so far in concatenated play (0 in a single-file movie).
Sint32 SFMPS_GetConcatCnt(SFD sfd)
{
	return SFMPS_WK(sfd)->concat_cnt;
}

/* the seek work's system stream analysis, when a seek work is attached and no concatenation
 * happened */
static SFSEE_SHDR *sfmps_GetSeeShdr(SFD sfd)
{
	SFSEE_WORK *wk = sfd->see.wk;

	if (wk == NULL) {
		return NULL;
	}
	if (SFMPS_GetConcatCnt(sfd) > 0) {
		return NULL;
	}
	return &wk->shdr;
}

// Seek support: re-feeds the saved pack/system headers to the MPS parser and restores the first
// stream ids / SCR base / minimum PTS from the seek work; no-op without a seek work.
static Sint32 SFMPS_Seek(SFD sfd)
{
	Sint32 ret1, ret2;
	SFSEE_SHDR *shdr = sfmps_GetSeeShdr(sfd);
	SFSEE_SYSHD *sh;
	MPS mps;
	SFMPS_WORK *wk;
	Sint32 len, flags;
	Sint32 ret;

	if (shdr == NULL) {
		return 0;
	}
	if (shdr->analyzed == 0) {
		return 0;
	}
	wk = SFMPS_WK(sfd);
	SFHDS_ReprocessHdr(sfd);
	sh = &shdr->syshd;
	mps = wk->mps;
	ret1 = MPS_DecHd(mps, sh->data[0], sh->len[0], &len, &flags);
	ret2 = MPS_DecHd(mps, sh->data[1], sh->len[1], &len, &flags);
	if (ret1 != 0 || ret2 != 0) {
		ret = SFLIB_SetErr(sfd, SFMPS_ERR_SEEK);
	} else {
		ret = 0;
	}
	if (ret != 0) {
		return ret;
	}
	wk->first_vid = shdr->stmid_vid;
	wk->first_aud = shdr->stmid_aud;
	sfd->con.scr_base = shdr->scr_base;
	wk->pts_min = shdr->pts_min;
	return 0;
}

// Not supported: error 0xFF000B03.
Sint32 SFMPS_AddRead(SFD sfd)
{
	return SFLIB_SetErr(sfd, SFMPS_ERR_NOTSUPPORTED);
}

// Not supported: error 0xFF000B03.
Sint32 SFMPS_GetRead(SFD sfd)
{
	return SFLIB_SetErr(sfd, SFMPS_ERR_NOTSUPPORTED);
}

// Not supported: error 0xFF000B03.
Sint32 SFMPS_AddWrite(SFD sfd)
{
	return SFLIB_SetErr(sfd, SFMPS_ERR_NOTSUPPORTED);
}

// Not supported: error 0xFF000B03.
Sint32 SFMPS_GetWrite(SFD sfd)
{
	return SFLIB_SetErr(sfd, SFMPS_ERR_NOTSUPPORTED);
}

// Nothing to do.
Sint32 SFMPS_Pause(SFD sfd)
{
	return 0;
}

// Nothing to do.
Sint32 SFMPS_Stop(SFD sfd)
{
	return 0;
}

// Nothing to do.
Sint32 SFMPS_Start(SFD sfd)
{
	return 0;
}

// Nothing to do.
Sint32 SFMPS_Standby(SFD sfd)
{
	return 0;
}

// Destroys the MPS parser handle.
// FUN_00519C38
Sint32 SFMPS_Destroy(SFD sfd)
{
	if (MPS_Destroy(SFMPS_MPS(sfd)) != 0) {
		return SFLIB_SetErr(sfd, SFMPS_ERR_DESTROY);
	}
	return 0;
}

// MPS parser errors -> the handle's SFLIB_SetErr.
// FUN_00519C20
void sfmps_ErrFn(void *obj, Sint32 code)
{
	SFLIB_SetErr(obj, code);
}

// No user element output joints (stream ids 0xBC..0xFF).
static void sfmps_ClrOutSj(SFMPS_WORK *wk)
{
	int i;

	for (i = 0; i < SFMPS_OUTSJ_NUM; i++) {
		wk->outsj[i] = NULL;
	}
}

// Driver Create: resets the demux work (no streams seen, PTS minimum unknown, no end code) and
// creates the MPS parser with sfmps_ErrFn as its error callback.
Sint32 SFMPS_Create(SFD sfd)
{
	SFMPS_WORK *wk = &sfd->mps;
	MPS mps;

	sfd->tr[SFMPS_TR].hn = wk;
	wk->mps = NULL;
	wk->nvid = 0;
	wk->naud = 0;
	wk->pts_min = INT64_MAX_VAL;
	wk->pts_min2 = INT64_MAX_VAL;
	wk->concat_cnt = 0;
	wk->last_vid = 0x7FFFFFFF;
	wk->last_aud = 0x7FFFFFFF;
	wk->first_vid = -1;
	wk->first_aud = -1;
	wk->cur_vid = -1;
	wk->cur_aud = -1;
	wk->endcode = 0;
	sfmps_ClrOutSj(wk);
	wk->outfn = NULL;
	wk->outobj = NULL;
	wk->skip = -1;
	mps = MPS_Create();
	if (mps == NULL) {
		return SFLIB_SetErr(NULL, SFMPS_ERR_CREATE);
	}
	if (MPS_SetErrFn(mps, sfmps_ErrFn, sfd) != 0) {
		MPS_Destroy(mps);
		return SFLIB_SetErr(NULL, SFMPS_ERR_SETERRFN);
	}
	wk->mps = mps;
	return 0;
}

/* stream counts from the three system headers */
static void sfmps_UpdateNumStm(SFMPS_WORK *wk, MPS_SYSHD *hd)
{
	MPS mps = wk->mps;
	Sint32 naud = 0, nvid = 0;
	Sint32 i;

	for (i = 0; i < 3; i++) {
		MPS_GetSysHd(mps, hd, i);
		naud = (naud > hd->raw[2]) ? naud : hd->raw[2];
		nvid = (nvid > hd->raw[3]) ? nvid : hd->raw[3];
	}
	wk->naud = naud;
	wk->nvid = nvid;
}

/* the seek-work header fill as an inlined helper: its `w` is created at inlining, before the
 * nested sfmps_GetSeeShdr's return temporary, so `w` is coloured first (r4) and shdr takes r5 */
static inline void sfmps_ProcPrepSee(SFD sfd)
{
	SFMPS_WORK *w;
	SFSEE_SHDR *shdr;

	shdr = sfmps_GetSeeShdr(sfd);
	if (shdr != NULL) {
		w = SFMPS_WK(sfd);
		if (w->pts_min2 != INT64_MAX_VAL) {
			sfd->con.scr_ofst = w->pts_min2 - shdr->pts_min;
			if (shdr->analyzed == 0) {
				shdr->ncount = sfd->x924 * 50;
				shdr->tscale = sfd->x928;
				shdr->nvid = w->nvid;
				shdr->naud = w->naud;
				shdr->scr_base = sfd->con.scr_base;
				shdr->pts_min = w->pts_min;
				shdr->stmid_vid = w->first_vid;
				shdr->stmid_aud = w->first_aud;
			}
		}
	}
}

// PREP-state bookkeeping each pass: marks the three output buffers prepared once the input ring
// holds cond 0x16 bytes (or its whole size), records mux rate and system-header rate scale, publishes
// the stream counts, auto-disables audio/video whose element buffer never received data, and fills
// the seek work's system analysis.
static void sfmps_ProcPrep(SFD sfd)
{
	MPS mps;
	SFMPS_WORK *wk;
	MPS_SYSHD hd;
	MPS_SYSHD syshd;
	MPS_PACKHD packhd;
	Sint32 prep1, prep2, prep3;
	SFMPS_BUFHN *hn;
	Sint32 size;
	Sint32 need;

	sfmps_UpdateNumStm(SFMPS_WK(sfd), &hd);
	prep1 = SFBUF_GetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout2);
	prep2 = SFBUF_GetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout);
	prep3 = SFBUF_GetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout3);
	if ((prep1 | prep2 | prep3) != 1) {
		if (SFBUF_GetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufin) == 1) {
			size = sfd->prm.size[0];
			need = sfd->cond[SFD_COND_PREPSIZE];
			hn = SFMPS_BUF_HN(sfd, sfd->tr[SFMPS_TR].bufin);
			if (size <= 0) {
				size = hn->w.u.ring.sup.size;
			}
			if (size <= 0) {
				size = need;
			}
			if (size < need) {
				need = size;
			}
			if (SFBUF_GetWTot(sfd, 0) >= need) {
				SFBUF_SetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout2, 1);
				SFBUF_SetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout, 1);
				SFBUF_SetPrepFlg(sfd, sfd->tr[SFMPS_TR].bufout3, 1);
			}
		}
	}
	wk = SFMPS_WK(sfd);
	mps = wk->mps;
	MPS_GetPackHd(mps, &packhd);
	if (packhd.mux_rate != -1 && packhd.mux_rate > 0) {
		sfd->x924 = packhd.mux_rate;
	}
	MPS_GetSysHd(mps, &syshd, 1);
	if (syshd.raw[4] != -1) {
		sfd->x928 = syshd.raw[4];
	}
	if (sfd->numelem_aud == -1) {
		sfd->numelem_aud = wk->naud;
	}
	if (sfd->numelem_vid == -1) {
		sfd->numelem_vid = wk->nvid;
	}
	wk = SFMPS_WK(sfd);
	if (SFSET_GetCond(sfd, SFD_COND_AUDIO_ON) != 0 && SFSET_GetCond(sfd, SFD_COND_VIDEO_AUTO_OFF) != 0 &&
	    SFBUF_GetWTot(sfd, 2) == 0 && wk->naud == 0 && SFTRN_GetPrepFlg(sfd, 6) != 0) {
		SFSET_SetCond(sfd, SFD_COND_AUDIO_ON, 0);
	}
	if (SFSET_GetCond(sfd, SFD_COND_VIDEO_ON) != 0 && SFSET_GetCond(sfd, SFD_COND_AUDIO_AUTO_OFF) != 0 &&
	    SFBUF_GetWTot(sfd, 1) == 0 && wk->nvid == 0 && SFTRN_GetPrepFlg(sfd, 7) != 0) {
		SFSET_SetCond(sfd, SFD_COND_VIDEO_ON, 0);
	}
	sfmps_ProcPrepSee(sfd);
}

/* copies a packet payload into ring buffer `buf`, registering its PTS */
// FUN_00519008
Sint32 sfmps_CopyDstBuft(SFD sfd, Sint32 buf, Uint8 *data, Sint32 len, Sint64 pts)
{
	SFBUF_RINF inf;
	SFPTS_ENT ent;
	SFPTS_ENT ent2;
	Sint32 full;
	Sint32 ret;
	Uint8 *p1;
	Sint32 n1;
	Uint8 *p2;
	Sint32 rsv;

	ret = SFBUF_RingGetWrite(sfd, buf, &inf);
	if (ret != 0) {
		return ret;
	}
	p1 = inf.ck1.data;
	n1 = inf.ck1.len;
	p2 = inf.ck2.data;
	rsv = inf.rsv[1];
	if (len > n1 + inf.ck2.len) {
		return 0;
	}
	if (buf == 1) {
		if (pts >= 0) {
			if (SFPTS_IsPtsQueFull(sfd, buf) != 0) {
				return 0;
			}
			ent.pts = pts;
			ent.pos = (Uint32)p1;
			ent.len = len;
			ret = SFPTS_WritePtsQue(sfd, buf, &ent, &full);
			if (ret != 0) {
				return ret;
			}
		}
	} else if (buf == 2) {
		if (SFPLY_SetPtsInfo != NULL) {
			ent2.pts = pts;
			ent2.pos = len;
			if (SFPLY_SetPtsInfo(&sfd->ptsm, &ent2) == -1) {
				return 0;
			}
		}
	}
	if (len <= n1) {
		MEM_Copy(p1, data, len);
	} else {
		MEM_Copy(p1, data, n1);
		MEM_Copy(p2, data + n1, len - n1);
	}
	ret = SFBUF_RingAddWrite(sfd, buf, len, rsv);
	if (ret != 0) {
		return ret;
	}
	return 1;
}

// Padding stream packets are dropped (always consumed).
Sint32 sfmps_CopyPadding(SFD sfd, Sint32 stmid, Uint8 *data, Sint32 len, Sint64 pts)
{
	return 1;
}

/* copies `len` bytes into a user stream joint; the whole payload has to fit */
static Sint32 sfmps_CopySj(SJ sj, Uint8 *data, Sint32 len)
{
	SJCK ck2;
	SJCK ck1;

	if (SJ_GetNumData(sj, SJ_CK_FREE) < len) {
		return 0;
	}
	SJ_GetChunk(sj, SJ_CK_FREE, len, &ck1);
	MEM_Copy(ck1.data, data, ck1.len);
	SJ_PutChunk(sj, SJ_CK_DATA, &ck1);
	if (ck1.len == 0) {
		return 0;
	}
	len -= ck1.len;
	data += ck1.len;
	if (len > 0) {
		SJ_GetChunk(sj, SJ_CK_FREE, len, &ck2);
		MEM_Copy(ck2.data, data, ck2.len);
		SJ_PutChunk(sj, SJ_CK_DATA, &ck2);
		if (ck2.len != len) {
			copy_sj_error++;
		}
	}
	return 1;
}

/* copies a private packet into the user-output channel `chno` and reports it */
static Sint32 sfmps_CopyUoch(SFD sfd, Sint32 chno, Uint8 *data, Sint32 len)
{
	SFUO_CH ch;
	SFMPS_UOCB fn1;
	SFMPS_UOCB fn2;
	void *obj;
	Sint32 ret;

	SFBUF_GetUoch(sfd, sfd->tr[SFMPS_TR].bufout3, chno, &ch);
	fn1 = (SFMPS_UOCB)ch.prm;
	fn2 = (SFMPS_UOCB)ch.rsv1;
	obj = (void *)ch.rsv2;
	if (ch.sj == NULL) {
		return 1;
	}
	ret = sfmps_CopySj(ch.sj, data, len);
	if (ret == 1) {
		if (fn1 != NULL) {
			fn1(sfd, chno);
		}
		if (fn2 != NULL) {
			fn2(obj, chno);
		}
	}
	return ret;
}

// Copies a private payload to user-output channel `chno` if the handle has a user output buffer.
static Sint32 sfmps_CopyUo(SFD sfd, Sint32 chno, Uint8 *data, Sint32 len)
{
	if (sfd->tr[SFMPS_TR].bufout3 == 8) {
		return 1;
	}
	return sfmps_CopyUoch(sfd, chno, data, len);
}

// Private stream 1/2 packet: a Sofdec header packet goes to the header analyser (SFHDS_SetHdr; when
// flagged also to user channel 0 with its 0x12-byte packet header), any other private payload to the
// user output channel of its stream id (the MW player's additional-info ring).
Sint32 sfmps_CopyPrvate(SFD sfd, Sint32 stmid, Uint8 *data, Sint32 len, Sint64 pts)
{
	Sint32 result;
	Sint32 ret;

	if (SFHDS_SetHdr(sfd, stmid, data, len, &result)) {
		if (result != 0) {
			data -= 0x12;
			len += 0x12;
			sfmps_CopyUo(sfd, 0, data, len);
		}
		return 1;
	}
	ret = sfmps_CopyUo(sfd, stmid, data, len);
	return ret;
}

/* sequence header / GOP start code at the head of a video packet */
static Bool sfmps_IsVideoHead(Uint8 *data, Sint32 len)
{
	Sint8 *p = (Sint8 *)data;
	Uint8 c;

	if (len < 4) {
		return FALSE;
	}
	if ((Uint8)p[0] != 0) {
		return FALSE;
	}
	if ((Uint8)p[1] != 0) {
		return FALSE;
	}
	if ((Uint8)p[2] != 1) {
		return FALSE;
	}
	c = p[3];
	if (c == 0xB3) {
		return TRUE;
	}
	return (c == 0xB8);
}

// Video packet: when video is on, selects the video stream on the first packet (cond 0x1D/0x1E
// policy), drops packets of other video streams, and copies the payload into the video ring (buf 1)
// with its PTS.
Sint32 sfmps_CopyVideo(SFD sfd, Sint32 stmid, Uint8 *data, Sint32 len, Sint64 pts)
{
	SFMPS_WORK *wk;
	SFMPS_WORK *w;
	MPS_SYSHD hd;
	Sint32 sel;
	Sint32 cur;
	Bool chg;

	if (SFSET_GetCond(sfd, SFD_COND_VIDEO_ON) == 0) {
		return 1;
	}
	wk = SFMPS_WK(sfd);
	if (wk->cur_vid == -1) {
		switch (SFSET_GetCond(sfd, SFD_COND_VID_SELECT)) {
		case 1:
			sel = stmid;
			break;
		case 2:
			w = SFMPS_WK(sfd);
			sfmps_UpdateNumStm(w, &hd);
			if (w->nvid >= 2) {
				sel = 2;
			} else {
				sel = stmid;
			}
			break;
		case 0:
		default:
			sel = stmid;
			break;
		}
		wk->cur_vid = sel;
	}
	if (wk->first_vid == -1) {
		wk->first_vid = stmid;
	}
	cur = SFSET_GetCond(sfd, SFD_COND_VID_STMID);
	if (cur != -1) {
		if (SFSET_GetCond(sfd, SFD_COND_STMID_STRICT) != 0) {
			chg = (stmid < wk->last_vid);
		} else {
			chg = (stmid == wk->first_vid);
		}
		if (chg && wk->cur_vid != cur) {
			if (sfmps_IsVideoHead(data, len)) {
				wk->cur_vid = cur;
			}
		}
	}
	wk->last_vid = stmid;
	if (wk->cur_vid != stmid) {
		return 1;
	}
	return sfmps_CopyDstBuft(sfd, sfd->tr[SFMPS_TR].bufout, data, len, pts);
}

// Audio packet: when audio is on, selects the audio stream (cond 0x1F..), drops other streams, tracks
// the minimum audio PTS (start alignment) and copies the payload into the audio ring (buf 2).
Sint32 sfmps_CopyAudio(SFD sfd, Sint32 stmid, Uint8 *data, Sint32 len, Sint64 pts)
{
	SFMPS_WORK *wk;
	Sint32 cur;
	Bool chg;
	Sint64 min;

	if (SFSET_GetCond(sfd, SFD_COND_AUDIO_ON) == 0) {
		return 1;
	}
	wk = SFMPS_WK(sfd);
	if (wk->cur_aud == -1) {
		wk->cur_aud = stmid;
	}
	if (wk->first_aud == -1) {
		wk->first_aud = stmid;
	}
	cur = SFSET_GetCond(sfd, SFD_COND_AUD_STMID);
	if (cur != -1) {
		if (SFSET_GetCond(sfd, SFD_COND_STMID_STRICT) != 0) {
			chg = (stmid < wk->last_aud);
		} else {
			chg = (stmid == wk->first_aud);
		}
		if (chg) {
			wk->cur_aud = cur;
		}
	}
	wk->last_aud = stmid;
	if (wk->cur_aud != stmid) {
		return 1;
	}
	if (pts >= 0) {
		min = wk->pts_min;
		if (pts < min) {
			min = pts;
		}
		wk->pts_min = min;
		min = wk->pts_min2;
		if (pts < min) {
			min = pts;
		}
		wk->pts_min2 = min;
	}
	return sfmps_CopyDstBuft(sfd, sfd->tr[SFMPS_TR].bufout2, data, len, pts);
}

const SFMPS_COPYFN sfmps_CopyPketFn[4] = {
	sfmps_CopyAudio,
	sfmps_CopyVideo,
	sfmps_CopyPrvate,
	sfmps_CopyPadding,
};

/* all three output buffers terminate when the input buffer has */
static void sfmps_TermOut(SFD sfd)
{
	SFBUF_SetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout2, 1);
	SFBUF_SetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout, 1);
	SFBUF_SetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout3, 1);
}

// If the system input ring terminated, terminates the three output buffers; *term reports it.
static void sfmps_TermIfInTerm(SFD sfd, Sint32 *term)
{
	Sint32 t;

	if (SFBUF_GetTermFlg(sfd, sfd->tr[SFMPS_TR].bufin) == 1) {
		sfmps_TermOut(sfd);
		t = 1;
	} else {
		t = 0;
	}
	if (term != NULL) {
		*term = t;
	}
}

/* copies the payload of the packet whose header was just decoded */
Sint32 sfmps_CopyPketData(void *obj, Uint8 *data, Sint32 len, Sint32 *nbyte, Sint32 *result)
{
	SFMPS_WORK *wk;
	SFD sfd;
	MPS_PKETHD hd;
	Sint32 ret;
	Sint32 stmid, type, idx, plen;
	Sint64 pts;
	SJ sj;
	void *outobj;
	void (*fn)(void *obj, Sint32 stmid);
	Sint32 res;

	sfd = obj;
	*nbyte = 0;
	*result = 0;
	ret = 0;
	wk = SFMPS_WK(sfd);
	if (MPS_GetPketHd(wk->mps, &hd) != 0) {
		ret = SFLIB_SetErr(sfd, SFMPS_ERR_PKETHD);
	}
	plen = hd.raw[MPS_PKT_PAYLOAD];
	stmid = hd.raw[MPS_PKT_STMID];
	type = hd.raw[MPS_PKT_TYPE];
	idx = hd.raw[MPS_PKT_IDX];
	pts = hd.pts;
	if (plen < 0) {
		return SFLIB_SetErr(sfd, SFMPS_ERR_PKETLEN);
	}
	if (plen == 0) {
		*nbyte = 0;
		*result = 1;
		return 0;
	}
	if (len < plen) {
		sfmps_TermIfInTerm(sfd, NULL);
		return 0;
	}
	sj = wk->outsj[stmid - SFMPS_STMID_MIN];
	if (sj != NULL) {
		outobj = wk->outobj;
		fn = wk->outfn;
		res = sfmps_CopySj(sj, data, plen);
		if (res == 1 && fn != NULL) {
			fn(outobj, stmid);
		}
		*result = res;
	} else {
		*result = sfmps_CopyPketFn[type](sfd, idx, data, plen, pts);
	}
	switch (*result) {
	case 1:
		*nbyte = plen;
		break;
	case 0:
		break;
	default:
		ret = *result;
		break;
	}
	return ret;
}

/* the input buffer's terminate flag (terminating the outputs when set) */
// FUN_004EA020
static Sint32 sfmps_IsInTerm(SFD sfd)
{
	Sint32 term;

	sfmps_TermIfInTerm(sfd, &term);
	return term;
}

/* all bytes of a possible padding unit are zero */
static Bool sfmps_IsZero(Sint8 *p, Sint32 n)
{
	Sint32 i;

	for (i = 0; i < n; i++) {
		if (*p++ != 0) {
			return FALSE;
		}
	}
	return TRUE;
}

/* the PES callback pair as a helper: its `obj`/`fn` locals are inlined `@N` webs, so the two call-result
 * copies are compiler copies (coalesced, codeless ghosts) - the two extra permanent neighbours that keep
 * `ret` out of the second Chaitin round (cnt r21; CRI pass 65, replaces the pass-29 M1 pin) */
static void sfmps_SetPesFns(SFD sfd, MPS mps)
{
	void *fn;
	void *obj;

	obj = (void *)SFSET_GetCond(sfd, SFD_COND_PESOBJ);
	fn = (void *)SFSET_GetCond(sfd, SFD_COND_PESFN);
	MPS_SetPesFn(mps, fn, obj);
}

/* decodes one pack / system header / packet at `data`: *nbyte consumed, *nskip skipped */
Sint32 sfmps_DecodeOneUnit(SFD sfd, Uint8 *data, Sint32 len, Sint32 *nbyte, Sint32 *nskip, Sint32 total)
{
	Sint8 *p;
	Sint32 delim;
	register Sint32 ret = 0;
	register Sint32 err;
	SFMPS_WORK *wk;
	MPS mps;
	Sint32 bufin;
	MPS_SYSHD syshd;
	Sint32 flags;
	Sint32 hdrlen;
	Sint32 copied;
	Sint32 cres;
	Sint32 term2;
	SFSEE_SHDR *shdr;
	Uint8 *dst;
	Sint32 n;
	Sint32 cnt;
	SFMPS_BUFHN *hn;
	Bool go;
	Bool ok;

	*nskip = *nbyte = delim = 0;
	wk = SFMPS_WK(sfd);
	bufin = sfd->tr[SFMPS_TR].bufin;
	mps = wk->mps;
	if (len >= 4) {
		delim = MPS_CheckDelim(data);
		if (delim == MPS_DELIM_END) {
			if (sfd->tr[SFMPS_TR].x20 < 0) {
				sfd->tr[SFMPS_TR].x20 = SFBUF_GetRTot(sfd, bufin) + 4;
			}
			wk->endcode = 1;
		} else if (delim != 0) {
			wk->endcode = 0;
		}
	}
	if (delim != MPS_DELIM_END) {
		go = FALSE;
	} else if (SFCON_IsEndcodeSkip(sfd) != 0 || SFCON_IsSystemEndcodeSkip(sfd) != 0) {
		go = FALSE;
	} else {
		go = TRUE;
	}
	if (go) {
		sfmps_TermOut(sfd);
		go = FALSE;
	} else if (total < 4 && sfmps_IsInTerm(sfd)) {
		go = FALSE;
	} else if (len < 0x40) {
		if (delim == MPS_DELIM_PACK || delim == MPS_DELIM_PKET) {
			sfmps_TermIfInTerm(sfd, NULL);
			go = FALSE;
		} else {
			go = TRUE;
		}
	} else {
		go = TRUE;
	}
	if (!go) {
		return 0;
	}
	if (len >= 4) {
		delim = MPS_CheckDelim(data);
	} else {
		delim = 0;
	}
	MPS_SetPsMapFn(mps, (void *)SFSET_GetCond(sfd, SFD_COND_PSMAPFN), (void *)SFSET_GetCond(sfd, SFD_COND_PSMAPOBJ));
	sfmps_SetPesFns(sfd, mps);
	if (MPS_DecHd(mps, data, len, &hdrlen, &flags) != 0) {
		ret = SFLIB_SetErr(sfd, SFMPS_ERR_DECHD);
	}
	if (flags & MPS_DECHD_SYSHD) {
		shdr = sfmps_GetSeeShdr(sfd);
		if (shdr != NULL && shdr->analyzed == 0) {
			dst = (Uint8 *)shdr + 0x30;
			MPS_GetLastSysHd(mps, &syshd);
			n = (len < 0xB0) ? len : 0xB0;
			if (syshd.raw[3] > 0) {
				*(Sint32 *)(dst + 0x160) = n;
			} else if (syshd.raw[2] > 0) {
				*(Sint32 *)(dst + 0x164) = n;
				dst += 0xB0;
			} else {
				goto no_syshd;
			}
			MEM_Copy(dst, data, n);
		}
	}
no_syshd:
	if (flags == MPS_DELIM_END && SFCON_IsEndcodeSkip(sfd) != 0) {
		SFMPS_WK(sfd)->concat_cnt++;
		*nbyte = 4;
		wk->skip = 4;
	} else if (flags == MPS_DELIM_END && SFCON_IsSystemEndcodeSkip(sfd) != 0) {
		*nbyte = 4;
		wk->skip = 4;
	} else if (delim == 0) {
		*nskip = 0;
		p = (Sint8 *)data;
		/* COMPILER-DIFF: M (frontend CSE) - the original's unit value is the compare's own load (a backend
		 * temp, coloured before IsZero's cloned `p`: r3/r4), the argument and store loads merged into it by
		 * the backend; `sfd->prm.unit` three times is frontend-CSE'd into a @temp created after the inlining
		 * (a lower vid, r4/r3). The creation-parameter view of the handle keeps the compare's read a separate
		 * expression (CRI pass 54). */
		if (len >= ((SFD_CREPRM *)sfd)->unit + 3 && sfmps_IsZero(p, sfd->prm.unit)) {
			*nskip = sfd->prm.unit;
		} else {
			cnt = 0;
			while (len >= 4) {
				if (MPS_CheckDelim((Uint8 *)p) & (MPS_DELIM_PACK | MPS_DELIM_PKET | MPS_DELIM_END)) {
					*nskip = cnt;
					goto skip_done;
				}
				cnt++;
				p++;
				len--;
			}
			if (len > 0 && len < 4) {
				hn = SFMPS_BUF_HN(sfd, sfd->tr[SFMPS_TR].bufin);
				if (hn->w.u.ring.sup.kind == 0 && (hn->w.u.ring.sup.xsize != 0 || hn->w.u.ring.sup.x14 != 0)) {
					ok = FALSE;
				} else if ((Uint32)(p + len) == hn->w.u.ring.sup.ofst + hn->w.u.ring.sup.size) {
					ok = TRUE;
				} else {
					ok = FALSE;
				}
				if (ok) {
					cnt += len;
				}
			}
			*nskip = cnt;
		}
	skip_done:
		*nbyte = *nskip;
		if (*nskip > 0 && wk->skip >= 0) {
			if (wk->skip >= sfd->prm.unit) {
				wk->skip += *nskip;
			} else if (wk->skip + *nskip > sfd->prm.unit) {
				*nskip = *nskip - (sfd->prm.unit - wk->skip);
				wk->skip = sfd->prm.unit + *nskip;
			} else {
				wk->skip += *nskip;
				*nskip = 0;
			}
		}
	} else if (!(flags & MPS_DECHD_PKET)) {
		sfmps_TermIfInTerm(sfd, &term2);
		if (term2 == 0 && len > sfd->prm.unit) {
			if (hdrlen > 0) {
				*nbyte = hdrlen;
				*nskip = hdrlen;
			} else {
				*nbyte = 1;
				*nskip = 1;
			}
		}
	} else {
		data += hdrlen;
		len -= hdrlen;
		err = sfmps_CopyPketData(sfd, data, len, &copied, &cres);
		ret = err;
		if (cres == 1) {
			*nbyte = hdrlen + copied;
		}
		wk->skip = -1;
	}
	return ret;
}

/* the readable region of the input ring buffer */
static Sint32 sfmps_GetRead(SFD sfd, Uint8 **data, Sint32 *len, Sint32 *total)
{
	SFBUF_RINF inf;
	Sint32 ret;

	ret = SFBUF_RingGetRead(sfd, sfd->tr[SFMPS_TR].bufin, &inf);
	if (ret != 0) {
		return ret;
	}
	*len = inf.ck1.len;
	*data = inf.ck1.data;
	*total = *len + inf.ck2.len;
	return 0;
}

// Parses one unit (pack header / system header / packet) at `data` through the MPS parser and
// dispatches its payload; *nbyte consumed, *nskip garbage skipped.
// FUN_004EA710
static Sint32 sfmps_Decode(SFD sfd, Uint8 *data, Sint32 len, Sint32 *nbyte, Sint32 *nskip, Sint32 total)
{
	return sfmps_DecodeOneUnit(sfd, data, len, nbyte, nskip, total);
}

// Consumes `nbyte` bytes of the system input ring.
static Sint32 sfmps_AddRead(SFD sfd, Sint32 nbyte)
{
	Sint32 r;
	Sint32 ret;

	r = SFBUF_RingAddRead(sfd, sfd->tr[SFMPS_TR].bufin, nbyte);
	ret = 0;
	if (r != 0) {
		ret = r;
	}
	return ret;
}

/* `len` is the caller's own local passed by address: an own local of ExecServerSub ranks below the
 * AddRead clone's `ret` (the leader of ret's coalesced class), so ret colours r26 above len r25 */
static Sint32 sfmps_ExecServerLoop(SFD sfd, Sint32 *len)
{
	Sint32 wcnt, rcnt;
	Sint32 nbyte, nskip;
	Sint32 r;
	Sint32 limit;
	Sint32 ret;
	Uint8 *data;
	Sint32 tot;
	Sint32 total;
	Sint32 skiptot;

	ret = 0;
	skiptot = 0;
	tot = 0;
	limit = 0x7FFFFFFF;
	while (tot < limit) {
		ret = sfmps_GetRead(sfd, &data, len, &total);
		if (ret != 0) {
			break;
		}
		ret = sfmps_Decode(sfd, data, *len, &nbyte, &nskip, total);
		if (ret != 0) {
			break;
		}
		if (nbyte == 0) {
			break;
		}
		ret = sfmps_AddRead(sfd, nbyte);
		if (ret != 0) {
			break;
		}
		skiptot += nskip;
		tot += nbyte;
	}
	if (sfd->buf[0].u.ring.sup.sj != NULL) {
		SFBUF_GetFlowCnt(sfd->buf[0].u.ring.sup.sj, &wcnt, &rcnt);
		SFD_CNT(sfd)->s_flow = SFBUF_UpdateFlowCnt(SFD_CNT(sfd)->s_flow, wcnt);
		SFD_CNT(sfd)->s_byte += tot;
		SFD_CNT(sfd)->s_skip += skiptot;
	}
	if (sfd->stat == 2) {
		sfmps_ProcPrep(sfd);
	}
	return ret;
}

// Demux pass: unless all outputs terminated, installs the user system-header callback (cond
// 0x3B/0x3C) and runs the decode loop over the input ring, updating the 64-bit flow / byte / skip
// counters and, in PREP, sfmps_ProcPrep.
Sint32 sfmps_ExecServerSub(SFD sfd)
{
	Sint32 term1, term2, term3;
	MPS mps;
	Sint32 len;

	term1 = SFBUF_GetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout2);
	term2 = SFBUF_GetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout);
	term3 = SFBUF_GetTermFlg(sfd, sfd->tr[SFMPS_TR].bufout3);
	if ((term1 & term2 & term3) == 1) {
		return 0;
	}
	mps = SFMPS_MPS(sfd);
	MPS_SetSystemFn(mps, (void *)SFSET_GetCond(sfd, SFD_COND_SYSFN), (void *)SFSET_GetCond(sfd, SFD_COND_SYSOBJ));
	return sfmps_ExecServerLoop(sfd, &len);
}

/* COMPILER-DIFF: M3 -- sfmps_ExecServerSub's loop lives in the inlined sfmps_ExecServerLoop helper (its locals
 * are @temps: `li ret,0; mr skiptot,ret; mr tot,ret` shares the entry zero), which makes ExecServerSub small enough
 * for -inline auto to inline it here; the target keeps the `bl` (CRI pass 29). */
// Driver ExecServer (SFD_tr_sd_mps slot 2).
// FUN_004EA728
static Sint32 SFMPS_ExecServer(SFD sfd)
{
	return sfmps_ExecServerSub(sfd);
}

// Library finish: MPS parser.
// FUN_00511900
Sint32 SFMPS_Finish(void)
{
	MPS_Finish();
	return 0;
}

// Library init: checks the work size (spins on a mismatch) and initialises the MPS parser with 8 handles.
Sint32 SFMPS_Init(void)
{
	Sint32 ret;
	Sint32 wksize = sizeof(SFMPS_WORK);

	if (wksize > SFMPS_WORK_MAX) {
		ret = SFLIB_SetErr(NULL, SFMPS_ERR_WORKSIZE);
	} else {
		ret = 0;
	}
	if (ret != 0) {
		for (;;) {
		}
	}
	if (MPS_Init(SFMPS_NUM_HN, sfmps_libwork) != 0) {
		return SFLIB_SetErr(NULL, SFMPS_ERR_INIT);
	}
	copy_sj_error = 0;
	return 0;
}

// Registers a stream joint that receives the raw payload of element stream `stmid` (0xBC..0xFF)
// instead of the internal buffers, with a notification callback (side audio streams).
// FUN_00517EB8
Sint32 SFD_SetElementOutSj(SFD sfd, Sint32 stmid, void *sj, void (*fn)(void *obj, Sint32 stmid), void *obj)
{
	SFMPS_WORK *wk;

	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, SFD_ERR_SETELEMOUTSJ);
	}
	if (stmid < SFMPS_STMID_MIN || stmid > SFMPS_STMID_MAX) {
		return 0;
	}
	wk = SFMPS_WK(sfd);
	wk->outsj[stmid - SFMPS_STMID_MIN] = sj;
	wk->outobj = obj;
	wk->outfn = fn;
	return 0;
}
