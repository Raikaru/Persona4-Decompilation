/* CRI ADXT server (adx_tsvr.c): the per-handle state machine run from ADXT_ExecServer, the
 * decoder-information stage and the decoder trap / stream end-of-sector callbacks (looping and
 * linked files). 6/6 functions byte-identical; adxt_nlp_trap_entry carries one tagged form (the
 * `lha ofst` temporary takes r4 in the original = a no-r0 web: a dead conditional keeps an addi
 * use of it to the register allocator, see docs/research/ "CRI pass 79").
 * The decoder trap callbacks are `void (*)(void *obj)` handlers: the `void *` -> ADXT conversion
 * keeps the handle copy as its own node, ranked above the locals (r31) like the original (CRI pass
 * 12; replaces the pass-5 `` pins). */
#include <string.h>
#include "cri_xpt.h"
#include "sj.h"
#include "adx_t.h"
#include "adx_stm.h"

extern void ADXERR_CallErrFunc1(Char8 *msg);
extern void ADXERR_CallErrFunc2(Char8 *msg1, Char8 *msg2);
extern void ADXERR_ItoA2(Sint32 a, Sint32 b, Char8 *str, Sint32 len);
extern Sint32 ADXSJD_GetStat(void *sjd);
extern Sint32 ADXSJD_GetNumChan(void *sjd);
extern Sint32 ADXSJD_GetSfreq(void *sjd);
extern Sint32 ADXSJD_GetNumLoop(void *sjd);
extern Sint32 ADXSJD_GetBlkSmpl(void *sjd);
extern void ADXSJD_SetMaxDecSmpl(void *sjd, Sint32 nsmpl);
extern Sint32 ADXSJD_GetLpEndOfst(void *sjd);
extern Sint32 ADXSJD_GetLpEndPos(void *sjd);
extern Sint32 ADXSJD_GetLpStartPos(void *sjd);
extern Sint32 ADXSJD_GetLpStartOfst(void *sjd);
extern void ADXSJD_SetTrapNumSmpl(void *sjd, Sint32 nsmpl);
extern void ADXSJD_SetTrapDtLen(void *sjd, Sint32 len);
extern void ADXSJD_SetTrapCnt(void *sjd, Sint32 cnt);
extern void ADXSJD_EntryTrapFunc(void *sjd, void (*fn)(void *obj), void *obj);
extern Sint32 ADXSJD_GetTotalNumSmpl(void *sjd);
extern Sint32 ADXSJD_GetOutBps(void *sjd);
extern Sint16 ADXSJD_GetDefOutVol(void *sjd);
extern Sint32 ADXSJD_GetFormat(void *sjd);
extern void *ADXSJD_GetSpsdInfo(void *sjd);
extern Sint32 ADXSJD_GetDecNumSmpl(void *sjd);
extern void ADXSJD_Stop(void *sjd);
extern void ADXSJD_Start(void *sjd);
extern void ADXSJD_ExecHndl(void *sjd);
extern void ADXSJD_TermSupply(void *sjd);
extern void ADXSJD_SetDecPos(void *sjd, Sint32 pos);
extern void ADXSJD_TakeSnapshot(void *sjd);
extern void ADXSJD_RestoreSnapshot(void *sjd);
extern void ADXSTM_EntryEosFunc(ADXSTM stm, void (*fn)(ADXT adxt), void *obj);
extern Sint32 ADXRNA_GetNumData(void *rna);
extern Sint32 ADXRNA_GetNumRoom(void *rna);
extern void ADXRNA_SetPlaySw(void *rna, Sint32 sw);
extern void ADXRNA_SetTransSw(void *rna, Sint32 sw);
extern void ADXRNA_SetBitPerSmpl(void *rna, Sint32 bps);
extern void ADXRNA_SetSfreq(void *rna, Sint32 sfreq);
extern void ADXRNA_SetNumChan(void *rna, Sint32 nch);
extern void ADXRNA_SetTotalNumSmpl(void *rna, Sint32 nsmpl);
extern void ADXRNA_SetOutVol(void *rna, Sint32 vol);
extern Sint32 ADXRNA_SetStmHdInfo(void *rna, void *hdinfo);
extern void ADXAMP_SetSfreq(void *amp, Sint32 sfreq);
extern Sint32 LSC_GetStat(void *lsc);
extern Sint32 ADX_DecodeFooter(Uint8 *data, Sint32 len, Sint16 *ofst);
extern Sint32 ADX_ScanInfoCode(Uint8 *data, Sint32 len, Sint16 *ofst);
extern Sint32 ADXT_GetStat(ADXT adxt);
extern Sint32 ADXT_GetNumChan(ADXT adxt);
extern void ADXT_Stop(ADXT adxt);
extern void ADXT_GetTranspose(ADXT adxt, Sint32 *oct, Sint32 *cent);
extern void ADXT_SetTranspose(ADXT adxt, Sint32 oct, Sint32 cent);
extern Sint32 ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan);
extern void ADXT_SetLnkSw(ADXT adxt, Sint32 sw);
extern void adxt_start_stm(ADXT adxt, void *fname, void *dir, Sint32 ofst, Sint32 nsct);

void (*adxt_enddecinfo_cbfn)(ADXT adxt, Sint32 sfreq, Sint32 nch, Sint32 nsmpl) = NULL;
static Sint32 adxt_dbg_rna_ndata = 0;
Sint32 adxt_dbg_ndt = 0;
Sint32 adxt_dbg_nch = 0;

static void adxt_stat_decinfo(ADXT adxt);
void adxt_nlp_trap_entry(void *obj);
void adxt_eos_entry(ADXT adxt);
void adxt_trap_entry(void *obj);
void adxt_trap_entry_lps(void *obj);

// Per-handle server step (every ADXT_ExecServer): PLAYING -> PLAYEND_WAIT when the decoder has ended
// and less than 64 bytes are left in every output ring; DECINFO parses the header (adxt_stat_decinfo);
// PREP starts the renderer once enough PCM is buffered (or the stream is already over, padding the
// rings with silence); PLAYEND_WAIT -> PLAYEND when the renderer has drained. Then terminates the
// decoder's supply at the stream end (mode 0/1 file, 2 memory) and turns stream / scheduler errors
// into ADXT_ISTAT_ERROR with errcode -1.
void ADXT_ExecHndl(ADXT adxt)
{
	/* register ranking (CRI pass 11): locals get virtual ids in reverse declaration order and are
	 * coloured highest id first, so the loop-1 values (i, p) must be declared before the loop-2
	 * values (j, sj, nbyte, p2) and each stepping pointer after its counter */
	Sint32 nch;
	Sint32 i;
	Uint8 *p;
	Sint32 j;
	SJ sj;
	Sint32 nbyte;
	void *sjd;
	void *rna;
	Sint32 ndata;
	Sint32 nroom;
	Uint8 *p2;
	SJCK ck;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080842 ADXT_ExecHndl: parameter error");
		return;
	}
	if (adxt->stat == ADXT_ISTAT_PLAYING) {
		if (ADXSJD_GetStat(adxt->sjd) == 3) {
			nch = ADXSJD_GetNumChan(adxt->sjd);
			adxt_dbg_nch = nch;
			p = (Uint8 *)adxt;
			for (i = 0; i < nch; i++) {
				adxt_dbg_ndt = SJ_GetNumData(*(SJ *)(p + 0x18), SJ_CK_DATA);
				if (adxt_dbg_ndt >= 0x40) {
					break;
				}
				p += 4;
			}
			if (i == nch) {
				ADXRNA_SetTransSw(adxt->rna, 0);
				adxt->stat = ADXT_ISTAT_PLAYEND_WAIT;
			}
		}
	} else if (adxt->stat == ADXT_ISTAT_DECINFO) {
		adxt_stat_decinfo(adxt);
	} else if (adxt->stat == ADXT_ISTAT_PREP) {
		rna = adxt->rna;
		sjd = adxt->sjd;
		ndata = ADXRNA_GetNumData(rna);
		nroom = ADXRNA_GetNumRoom(rna);
		if (ndata >= adxt->maxdecsmpl * 2 || nroom <= ADXSJD_GetBlkSmpl(sjd) || ADXSJD_GetStat(adxt->sjd) == 3) {
			if (adxt->pausesw == 0) {
				if (adxt->x72 == 0) {
					ADXRNA_SetPlaySw(rna, 1);
					adxt->x9c = 0;
					adxt->startvsync = adxt_vsync_cnt;
				}
				adxt->stat = ADXT_ISTAT_PLAYING;
			}
			adxt->x71 = 1;
		}
		if (ADXSJD_GetStat(adxt->sjd) == 3) {
			nch = ADXT_GetNumChan(adxt);
			nbyte = adxt->maxdecsmpl * nch * 2;
			p2 = (Uint8 *)adxt;
			for (j = 0; j < nch; j++) {
				sj = *(SJ *)(p2 + 0x18);
				SJ_GetChunk(sj, SJ_CK_FREE, nbyte, &ck);
				memset(ck.data, 0, ck.len);
				SJ_PutChunk(sj, SJ_CK_DATA, &ck);
				p2 += 4;
			}
		}
	} else if (adxt->stat == ADXT_ISTAT_PLAYEND_WAIT) {
		adxt_dbg_rna_ndata = ADXRNA_GetNumData(adxt->rna);
		if (ADXRNA_GetNumData(adxt->rna) <= 0) {
			ADXRNA_SetPlaySw(adxt->rna, 0);
			adxt->stat = ADXT_ISTAT_PLAYEND;
		}
	}

	if (adxt->stm != NULL && ADXT_GetStat(adxt) != 0) {
		switch (adxt->mode) {
		case 0:
		case 1:
			if (ADXSTM_GetStat(adxt->stm) == ADXSTM_STAT_END) {
				ADXSJD_TermSupply(adxt->sjd);
			}
			break;
		case 2:
			ADXSJD_TermSupply(adxt->sjd);
			break;
		case 3:
			break;
		}
	}
	if (adxt->stm != NULL && ADXSTM_GetStat(adxt->stm) == ADXSTM_STAT_ERROR) {
		adxt->errcode = -1;
		adxt->stat = ADXT_ISTAT_ERROR;
	}
	if (adxt->lsc != NULL && LSC_GetStat(adxt->lsc) == 3) {
		adxt->errcode = -1;
		adxt->stat = ADXT_ISTAT_ERROR;
	}
}

/* NOTE (76B gap to P4 1040B at 0x004D7968, kept as-is this pass): retail hoists
 * `addiu $s3,$zero,0x800` at 0x4D7978 and reuses $s3 for every sector calc, and
 * clears `sw $zero,0xa8($s0)` (flush_nsmpl) at 0x4D79A8 before testing
 * `lb $v1,0xac($s0)` (stmstart) at 0x4D79AC; this spelling uses 0x800 literals
 * and never touches 0xA8 there. The tail keeps the proven 0xB0/0xB4/0xB8/0xBC/0xC0
 * fname_wk/fname/dir/ofst/nsct (`lw $a1,0xb4`/`lw $a2,0xb8`/`lw $a3,0xbc`/
 * `lw $t0,0xc0` at 0x4D79D8/0x4D79F4/0x4D79F8/0x4D7A00) and `jal 0x004D40A0`
 * (adxt_start_stm) at 0x4D79FC. Loop setup keeps lpendmod at 0x50, trapnsmpl at
 * 0x90 and lpcnt at 0x4C, matching `sw $v1,0x50`/`sw $v0,0x90` in retail. */
/* the decoder has read the header: size the decode step, set up looping / end handling and
 * program the renderer */
static void adxt_stat_decinfo(ADXT adxt)
{
	ADXT p;
	void *sjd;
	Sint32 sfreq;
	Sint32 nloop;
	Sint32 blk;
	Sint32 nch;
	Sint32 nsmpl;
	Sint32 tmp;
	void *info;
	Sint32 lpendofst;
	Sint32 lpendsct;
	Char8 buf[32];
	Sint32 oct;
	Sint32 cent;

	p = adxt;
	sjd = p->sjd;
	oct = 0;
	cent = 0;
	if ((p->mode == 0 || p->mode == 1) && p->stmstart == 1) {
		if (ADXSTM_GetStat(p->stm) == ADXSTM_STAT_EXEC) {
			return;
		}
		if (p->sjf != NULL) {
			SJ_Reset(p->sjf);
		}
		adxt_start_stm(p, p->stm_fname, p->stm_dir, p->stm_ofst, p->stm_nsct);
		p->stmstart = 0;
	}
	if (ADXSJD_GetStat(sjd) != 2) {
		return;
	}
	nch = ADXSJD_GetNumChan(sjd);
	if (nch > p->maxnch) {
		ADXERR_ItoA2(nch, p->maxnch, buf, 16);
		ADXERR_CallErrFunc2("E9081001 adxt_stat_decinfo: can't play this number of channels", buf);
		ADXT_Stop(p);
		return;
	}
	sfreq = ADXSJD_GetSfreq(sjd);
	nloop = ADXSJD_GetNumLoop(sjd);
	if (nloop > 0) {
		p->maxdecsmpl = sfreq / p->svrfreq * 3;
	} else {
		p->maxdecsmpl = sfreq / p->svrfreq * 3 / 2;
	}
	blk = ADXSJD_GetBlkSmpl(sjd) * 2;
	p->maxdecsmpl = blk * ((p->maxdecsmpl + blk) / blk);
	ADXSJD_SetMaxDecSmpl(sjd, p->maxdecsmpl);
	if (nloop > 0) {
		if (p->mode == 2) {
			p->lpendmod = 0;
		} else {
			lpendofst = ADXSJD_GetLpEndOfst(sjd);
			p->lpendmod = 0x800 - lpendofst % 0x800;
			lpendsct = (lpendofst + 0x7FF) / 0x800;
			p->lpendmod = p->lpendmod % 0x800;
			p->lpendsct = lpendsct;
			ADXSTM_SetEos(p->stm, lpendsct);
			ADXSTM_EntryEosFunc(p->stm, adxt_eos_entry, p);
		}
		nsmpl = ADXSJD_GetLpEndPos(sjd);
		p->trapnsmpl = ADXSJD_GetLpStartPos(sjd);
		ADXSJD_SetTrapNumSmpl(sjd, p->trapnsmpl);
		ADXSJD_SetTrapDtLen(sjd, 0);
		ADXSJD_SetTrapCnt(sjd, 0);
		ADXSJD_EntryTrapFunc(sjd, adxt_trap_entry_lps, p);
	} else {
		if (p->stm != NULL) {
			ADXSTM_SetEos(p->stm, 0x7FFFFFFF);
		}
		ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
		ADXSJD_SetTrapDtLen(sjd, 0);
		ADXSJD_SetTrapCnt(sjd, 0);
		ADXSJD_EntryTrapFunc(sjd, adxt_nlp_trap_entry, p);
	}
	sfreq = ADXSJD_GetSfreq(sjd);
	nch = ADXSJD_GetNumChan(sjd);
	nsmpl = ADXSJD_GetTotalNumSmpl(sjd);
	tmp = ADXSJD_GetOutBps(sjd);
	ADXRNA_SetBitPerSmpl(p->rna, tmp);
	ADXRNA_SetSfreq(p->rna, sfreq);
	ADXRNA_SetNumChan(p->rna, nch);
	ADXRNA_SetTotalNumSmpl(p->rna, nsmpl);
	ADXRNA_SetOutVol(p->rna, p->outvol + ADXSJD_GetDefOutVol(p->sjd));
	ADXT_GetTranspose(p, &oct, &cent);
	if (oct != 0 || cent != 0) {
		ADXT_SetTranspose(p, oct, cent);
	}
	if (ADXSJD_GetNumChan(p->sjd) == 1) {
		ADXT_SetOutPan(p, 0, p->outpan[0]);
	} else {
		ADXT_SetOutPan(p, 0, p->outpan[0]);
		ADXT_SetOutPan(p, 1, p->outpan[1]);
	}
	if (p->amp != NULL) {
		ADXAMP_SetSfreq(p->amp, sfreq);
	}
	if (ADXSJD_GetFormat(sjd) == 2) {
		info = ADXSJD_GetSpsdInfo(sjd);
		ADXRNA_SetStmHdInfo(p->rna, info);
	}
	ADXRNA_SetTransSw(p->rna, 1);
	if (adxt_enddecinfo_cbfn != NULL) {
		adxt_enddecinfo_cbfn(p, sfreq, nch, nsmpl);
	}
	p->stat = ADXT_ISTAT_PREP;
}

/* non-loop end trap: with the link switch on, look for a following ADX file behind the footer
 * (its info code) and restart the decoder on it */
// FUN_004D7680
void adxt_nlp_trap_entry(void *obj)
{
	ADXT p;
	void *sjd;
	SJ sji;
	SJCK ck;
	SJCK ck3;
	SJCK ck2;
	SJCK ck4;
	Sint16 ofst;
	Sint16 ofst2;
	Sint32 ofst1;
	Sint32 n1;
	Sint32 n2;
	Sint32 ofst2v;
	register Sint32 t;
	Sint32 z;

	p = obj;
	sjd = p->sjd;
	sji = p->sji;
	if (p->lnksw == 0) {
		return;
	}
	ofst2 = 0;
	SJ_GetChunk(sji, SJ_CK_DATA, 0x7FFFFFFF, &ck);
	SJ_GetChunk(sji, SJ_CK_DATA, 0x7FFFFFFF, &ck2);
	if (ADX_DecodeFooter(ck.data, ck.len, &ofst) != 0) {
		ADXT_SetLnkSw(p, 0);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
		return;
	}
	ofst1 = ofst;
	n1 = ADX_ScanInfoCode(ck.data + ofst1, ck.len - ofst1, &ofst);
	if (n1 == 0) {
		n2 = -1;
	} else {
		n2 = ADX_ScanInfoCode(ck2.data, ck2.len, &ofst2);
	}
	/* COMPILER-DIFF: M1 (rA use of the lha temp kept to the RA by a dead conditional): the
	 * original colours the `lha ofst` temporary r4, i.e. its web had a physical-r0 neighbour (an
	 * addi/base use) that left no instruction. `z = 0; if (z != 0)` is kept by the frontend (own-
	 * local constants are not propagated into relational compares) and folded away only by the
	 * post-RA peephole (`li; cmpi; bt` -> nothing, the arm deleted), so the arm's `addi ofst1,t,4`
	 * exists at RA time (t no-r0 -> r4) and leaves no code. */
	t = ofst;
	z = 0;
	if (z != 0) {
		ofst1 = t + 4;
	}
	ofst1 += t;
	ofst2v = ofst2;
	if (n1 != 0 && n2 != 0) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
		ADXT_SetLnkSw(p, 0);
		return;
	}
	if (n1 == 0) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
		SJ_SplitChunk(&ck, ofst1, &ck, &ck3);
		SJ_PutChunk(sji, SJ_CK_FREE, &ck);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck3);
	} else {
		SJ_PutChunk(sji, SJ_CK_FREE, &ck);
		SJ_SplitChunk(&ck2, ofst2v, &ck2, &ck4);
		SJ_PutChunk(sji, SJ_CK_FREE, &ck2);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck4);
	}
	p->decsmpl += ADXSJD_GetDecNumSmpl(sjd);
	ADXSJD_Stop(sjd);
	ADXSJD_Start(sjd);
	ADXSJD_ExecHndl(sjd);
	if (ADXSJD_GetStat(sjd) != 2) {
		ADXT_SetLnkSw(p, 0);
		return;
	}
	ADXSJD_SetMaxDecSmpl(sjd, p->maxdecsmpl);
	ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
	ADXSJD_SetTrapDtLen(sjd, 0);
	ADXSJD_SetTrapCnt(sjd, 0);
}

/* stream end-of-sector callback (looping): seek back to the loop start sector */
void adxt_eos_entry(ADXT adxt)
{
	ADXSTM stm;
	void *sjd;
	Sint32 ofst;

	stm = adxt->stm;
	sjd = adxt->sjd;
	if (stm == NULL || sjd == NULL) {
		return;
	}
	ofst = ADXSJD_GetLpStartOfst(sjd);
	if (adxt->lpsw == 0) {
		ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
		ADXSTM_SetEos(adxt->stm, 0x7FFFFFFF);
	} else {
		ADXSTM_Seek(stm, ofst / 0x800);
	}
}

/* decoder trap at the loop end: rewind the decoder to the loop start */
// FUN_004D73D8
void adxt_trap_entry(void *obj)
{
	ADXT adxt;
	void *sjd;
	SJ sji;
	Sint32 lpstart;
	Sint32 lpstartofst;
	Sint32 lpend;
	SJCK ck;

	adxt = obj;
	sjd = adxt->sjd;
	sji = adxt->sji;
	lpstart = ADXSJD_GetLpStartPos(sjd);
	lpstartofst = ADXSJD_GetLpStartOfst(sjd);
	lpend = ADXSJD_GetLpEndPos(sjd);
	if ((adxt->mode == 2 || adxt->mode == 3) && adxt->lpsw == 0) {
		ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
		return;
	}
	SJ_GetChunk(sji, SJ_CK_DATA, adxt->lpendmod, &ck);
	if (ck.len < adxt->lpendmod) {
		ADXERR_CallErrFunc1("E8101201 adxt_trap_entry: not enough data");
	}
	SJ_PutChunk(sji, SJ_CK_FREE, &ck);
	ADXSJD_SetTrapCnt(sjd, 0);
	ADXSJD_SetTrapNumSmpl(sjd, adxt->trapnsmpl = lpend - lpstart);
	ADXSJD_SetTrapDtLen(sjd, lpstartofst);
	ADXSJD_SetDecPos(sjd, lpstart);
	if (adxt->mode == 2) {
		SJ_Reset(sji);
		SJ_GetChunk(sji, SJ_CK_DATA, lpstartofst, &ck);
		SJ_PutChunk(sji, SJ_CK_FREE, &ck);
	}
	ADXSJD_RestoreSnapshot(sjd);
	adxt->lpcnt++;
}

/* first trap at the loop start: remember the decoder state and arm the loop end trap */
// FUN_004D7320
void adxt_trap_entry_lps(void *obj)
{
	ADXT p;
	void *sjd;
	Sint32 lpstart;
	Sint32 lpstartofst;
	Sint32 lpend;

	p = obj;
	sjd = p->sjd;
	lpstart = ADXSJD_GetLpStartPos(sjd);
	lpstartofst = ADXSJD_GetLpStartOfst(sjd);
	lpend = ADXSJD_GetLpEndPos(sjd);
	ADXSJD_TakeSnapshot(sjd);
	ADXSJD_SetTrapCnt(sjd, 0);
	ADXSJD_SetTrapNumSmpl(sjd, p->trapnsmpl = lpend - lpstart);
	ADXSJD_SetTrapDtLen(sjd, lpstartofst);
	ADXSJD_SetDecPos(sjd, lpstart);
	ADXSJD_EntryTrapFunc(sjd, adxt_trap_entry, p);
}
