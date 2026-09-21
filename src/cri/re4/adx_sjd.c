/* CRI ADX stream-joint decoder (ADXSJD): feeds an ADXB block decoder from an input stream joint and
 * writes the PCM into one ring-buffer stream joint per channel */
#include "cri_xpt.h"
#include "sj.h"
#include "adx_b.h"
#include <string.h>

#define ADXSJD_MAX_OBJ 16
#define ADXSJD_MAX_NCH 2

/* ADXSJD_OBJ.stat */
#define ADXSJD_STAT_STOP 0
#define ADXSJD_STAT_PREP 1
#define ADXSJD_STAT_DECODE 2
#define ADXSJD_STAT_END 3
#define ADXSJD_STAT_ERROR 4

/* ADXB formats handled as raw (undecoded) streams */
#define ADXSJD_IS_RAW_FMT(fmt) ((fmt) == 10 || (fmt) == 11 || (fmt) == 12 || (fmt) == 20 || (fmt) == 15)

typedef struct {
	Sint8 used;                /* 0x00 */
	Sint8 stat;                /* 0x01 */
	Sint8 nch;                 /* 0x02 */
	Sint8 spsd;                /* 0x03 SPSD stream: the input must hold data before a block starts */
	ADXB adxb;                 /* 0x04 */
	SJ sji;                    /* 0x08 input */
	SJ sjo[ADXSJD_MAX_NCH];    /* 0x0C outputs */
	SJCK inck;                 /* 0x14 input chunk handed to the decoder */
	SJCK outck[ADXSJD_MAX_NCH]; /* 0x1C output chunks being written */
	Sint32 dec_nsmpl;          /* 0x2C samples decoded */
	Sint32 dec_nbyte;          /* 0x30 input bytes consumed */
	Sint32 decpos;             /* 0x34 decode position in samples */
	Sint32 maxdecsmpl;         /* 0x38 */
	Sint32 trap_nsmpl;         /* 0x3C (-1: none) */
	Sint32 trap_cnt;           /* 0x40 */
	Sint32 trap_dtlen;         /* 0x44 */
	void (*trapfn)(void *obj); /* 0x48 */
	void *trapobj;             /* 0x4C */
	void (*outfn)(void *obj, Sint32 ch, Uint8 *data, Sint32 len); /* 0x50 */
	void *outobj;              /* 0x54 */
	Uint8 spsdinf[0x40];       /* 0x58 SPSD header copy */
	Sint32 hdrlen;             /* 0x98 */
	Sint32 lnksw;              /* 0x9C linked (concatenated) files */
	Sint32 pad_nsmpl;          /* 0xA0 silence samples to insert before the output */
	Sint32 skip_nsmpl;         /* 0xA4 output samples to discard */
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXB_Init(void);
extern ADXB ADXB_Create(Sint32 nch, void *buf, Sint32 bsize, Sint32 xsize);
extern void ADXB_Destroy(ADXB adxb);
extern void ADXB_EntryGetWrFunc(ADXB adxb, void *(*fn)(void *, Sint32 *, Sint32 *, Sint32 *), void *obj);
extern void ADXB_Start(ADXB adxb);
extern void ADXB_Stop(ADXB adxb);
extern void ADXB_Reset(ADXB adxb);
extern void ADXB_ExecHndl(ADXB adxb);
extern Sint32 ADXB_GetStat(ADXB adxb);
extern void ADXB_EntryData(ADXB adxb, Uint8 *data, Sint32 len);
extern Sint32 ADXB_DecodeHeader(ADXB adxb, Uint8 *data);
extern void ADXB_SetDefPrm(ADXB adxb);
extern Sint32 ADXB_GetFormat(ADXB adxb);
extern Sint32 ADXB_GetSfreq(ADXB adxb);
extern Sint32 ADXB_GetNumChan(ADXB adxb);
extern Sint32 ADXB_GetOutBps(ADXB adxb);
extern Sint32 ADXB_GetBlkSmpl(ADXB adxb);
extern Sint32 ADXB_GetTotalNumSmpl(ADXB adxb);
extern Sint32 ADXB_GetNumLoop(ADXB adxb);
extern Sint32 ADXB_GetLpStartPos(ADXB adxb);
extern Sint32 ADXB_GetLpStartOfst(ADXB adxb);
extern Sint32 ADXB_GetLpEndPos(ADXB adxb);
extern Sint32 ADXB_GetLpEndOfst(ADXB adxb);
extern Sint32 ADXB_GetAinfLen(ADXB adxb);
extern Sint32 ADXB_GetDefOutVol(ADXB adxb);
extern Sint32 ADXB_GetDefPan(ADXB adxb, Sint32 ch);
extern Sint32 ADXB_GetDecNumSmpl(ADXB adxb);
extern Sint32 ADXB_GetDecDtLen(ADXB adxb);
extern void *ADXB_GetPcmBuf(ADXB adxb);
extern void ADXB_TakeSnapshot(ADXB adxb);
extern void ADXB_RestoreSnapshot(ADXB adxb);
extern void ADXB_AhxTermSupply(ADXB adxb);
extern void ADXB_SetAhxDecSmpl(ADXB adxb, Sint32 nsmpl);
extern void ADXB_SetAhxInSj(ADXB adxb, SJ sji);
extern Sint32 ADX_DecodeFooter(Uint8 *data, Sint32 len, Sint16 *ofst);
extern void ADXERR_CallErrFunc2(const Char8 *msg1, const Char8 *msg2);
extern Sint32 SJRBF_GetBufSize(SJ sj);
extern Sint32 SJRBF_GetXtrSize(SJ sj);
extern void *SJRBF_GetBufPtr(SJ sj);

void (*pl2setsfreqfunc)(ADXB adxb, Sint32 sfreq);
ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ];

void ADXSJD_ExecHndl(ADXSJD sjd);
void adxsjd_decexec_start(ADXSJD sjd);
void *adxsjd_get_wr(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *trap);
void adxsjd_decode_prep(ADXSJD sjd);

// Restores the block decoder's ADPCM history/key snapshot (see ADXB_RestoreSnapshot); ADXT uses it to
// resume after a loop/seek.
void ADXSJD_RestoreSnapshot(ADXSJD sjd)
{
	ADXB_RestoreSnapshot(sjd->adxb);
}

// Saves the block decoder's ADPCM history/key snapshot.
void ADXSJD_TakeSnapshot(ADXSJD sjd)
{
	ADXB_TakeSnapshot(sjd->adxb);
}

// The 64-byte header copy kept for SPSD/PCM16 streams (spsdinf).
void *ADXSJD_GetSpsdInfo(ADXSJD sjd)
{
	return sjd->spsdinf;
}

// Default pan of channel `ch` from the stream's AINF chunk, only once the header has been decoded
// (stat DECODE/END); -128 otherwise.
Sint32 ADXSJD_GetDefPan(ADXSJD sjd, Sint32 ch)
{
	if (ADXB_GetAinfLen(sjd->adxb) > 0 && (sjd->stat == ADXSJD_STAT_DECODE || sjd->stat == ADXSJD_STAT_END)) {
		return ADXB_GetDefPan(sjd->adxb, ch);
	}
	return -128;
}

// Default output volume from the stream's AINF chunk once decoding has begun; 0 otherwise.
// FUN_004CEFB8
Sint32 ADXSJD_GetDefOutVol(ADXSJD sjd)
{
	if (ADXB_GetAinfLen(sjd->adxb) > 0 && (sjd->stat == ADXSJD_STAT_DECODE || sjd->stat == ADXSJD_STAT_END)) {
		return ADXB_GetDefOutVol(sjd->adxb);
	}
	return 0;
}

// Loop end byte offset of the stream (ADXB_GetLpEndOfst).
Sint32 ADXSJD_GetLpEndOfst(ADXSJD sjd)
{
	return ADXB_GetLpEndOfst(sjd->adxb);
}

// Loop end sample position of the stream.
Sint32 ADXSJD_GetLpEndPos(ADXSJD sjd)
{
	return ADXB_GetLpEndPos(sjd->adxb);
}

// Loop start byte offset; 0 for a NULL handle.
Sint32 ADXSJD_GetLpStartOfst(ADXSJD sjd)
{
	if (sjd == NULL) {
		return 0;
	}
	return ADXB_GetLpStartOfst(sjd->adxb);
}

// Loop start sample position.
Sint32 ADXSJD_GetLpStartPos(ADXSJD sjd)
{
	return ADXB_GetLpStartPos(sjd->adxb);
}

// Loop count from the ADX header.
Sint32 ADXSJD_GetNumLoop(ADXSJD sjd)
{
	return ADXB_GetNumLoop(sjd->adxb);
}

// Total samples per channel of the current stream.
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd)
{
	return ADXB_GetTotalNumSmpl(sjd->adxb);
}

// Samples per block of the current stream (32 for ADX).
Sint32 ADXSJD_GetBlkSmpl(ADXSJD sjd)
{
	return ADXB_GetBlkSmpl(sjd->adxb);
}

// Output bits per sample.
Sint32 ADXSJD_GetOutBps(ADXSJD sjd)
{
	return ADXB_GetOutBps(sjd->adxb);
}

// Output channel count (2 when a Pro Logic II encoder upmixes mono).
Sint32 ADXSJD_GetNumChan(ADXSJD sjd)
{
	return ADXB_GetNumChan(sjd->adxb);
}

// Sampling rate in Hz of the current stream.
Sint32 ADXSJD_GetSfreq(ADXSJD sjd)
{
	return ADXB_GetSfreq(sjd->adxb);
}

// Container type id of the current stream (ADXB_TYPE_*).
Sint32 ADXSJD_GetFormat(ADXSJD sjd)
{
	return ADXB_GetFormat(sjd->adxb);
}

// Presets the input-byte counter of the trap (used by ADXT to align the loop-end trap to a file position).
void ADXSJD_SetTrapDtLen(ADXSJD sjd, Sint32 len)
{
	sjd->trap_dtlen = len;
}

// Presets the trap's decoded-sample counter.
void ADXSJD_SetTrapCnt(ADXSJD sjd, Sint32 cnt)
{
	sjd->trap_cnt = cnt;
}

// Sets the sample count at which the trap callback fires before the next block starts (-1: no trap).
// ADXT uses it for the loop end and for the linked-file boundary.
void ADXSJD_SetTrapNumSmpl(ADXSJD sjd, Sint32 nsmpl)
{
	sjd->trap_nsmpl = nsmpl;
}

// Registers the trap callback (`fn(obj)`) run by adxsjd_decexec_start when trap_cnt reaches trap_nsmpl.
void ADXSJD_EntryTrapFunc(ADXSJD sjd, void (*fn)(void *obj), void *obj)
{
	sjd->trapfn = fn;
	sjd->trapobj = obj;
}

// Enables linked playback: after an ADX footer the decoder skips the zero padding and continues with
// the next concatenated file instead of ending.
void ADXSJD_SetLnkSw(ADXSJD sjd, Sint32 sw)
{
	sjd->lnksw = sw;
}

// Overrides the decode position in samples (ADXT sets it to the loop start after a loop jump).
void ADXSJD_SetDecPos(ADXSJD sjd, Sint32 pos)
{
	sjd->decpos = pos;
}

// Total samples decoded since ADXSJD_Start.
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD sjd)
{
	return sjd->dec_nsmpl;
}

/* dead-stripped: the first reference to pl2setsfreqfunc places it before adxsjd_obj in .bss */
void ADXSJD_EntryPl2SetSfreqFunc(void (*func)(ADXB adxb, Sint32 sfreq))
{
	pl2setsfreqfunc = func;
}

// Server tick: runs ADXSJD_ExecHndl on every live decoder (called from ADXT's main server).
// FUN_004CEB90
void ADXSJD_ExecServer(void)
{
	Sint32 i;

	for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
		if (adxsjd_obj[i].used == 1) {
			ADXSJD_ExecHndl(&adxsjd_obj[i]);
		}
	}
}

/* insert the requested silence in front of the output */
static void adxsjd_pad_out(ADXSJD sjd)
{
	SJCK ck;
	Sint32 i;
	Sint32 nbyte;
	Sint32 nsmpl;
	Sint32 n;

	if (sjd->pad_nsmpl <= 0) {
		return;
	}
	ADXCRS_Lock();
	nbyte = sjd->pad_nsmpl * 2;
	for (i = 0; i < sjd->nch; i++) {
		SJ_GetChunk(sjd->sjo[i], SJ_CK_FREE, 0x7FFFFFFF, &ck);
		n = ck.len;
		if (nbyte < n) {
			n = nbyte;
		}
		nbyte = n;
		SJ_UngetChunk(sjd->sjo[i], SJ_CK_FREE, &ck);
	}
	nsmpl = nbyte / 2;
	nbyte = nsmpl * 2;
	if (nbyte > 0) {
		for (i = 0; i < sjd->nch; i++) {
			SJ_GetChunk(sjd->sjo[i], SJ_CK_FREE, nbyte, &ck);
			memset(ck.data, 0, nbyte);
			SJ_PutChunk(sjd->sjo[i], SJ_CK_DATA, &ck);
		}
		sjd->pad_nsmpl -= nsmpl;
	}
	ADXCRS_Unlock();
}

/* a block was decoded: hand the input to the free side and the PCM to the data side */
static void adxsjd_decexec_end(ADXSJD sjd)
{
	SJCK ck1;
	SJCK ck2;
	Sint32 rem;
	ADXB adxb;
	Sint32 nbyte;
	SJ sji;
	Sint32 nsmpl;
	Sint32 i;

	adxb = sjd->adxb;
	sji = sjd->sji;
	rem = ADXB_GetTotalNumSmpl(adxb);
	nbyte = ADXB_GetDecDtLen(adxb);
	nsmpl = ADXB_GetDecNumSmpl(adxb);
	rem -= sjd->decpos;
	if (nsmpl < rem) {
		rem = nsmpl;
	}
	SJ_SplitChunk(&sjd->inck, nbyte, &ck1, &ck2);
	SJ_PutChunk(sji, SJ_CK_FREE, &ck1);
	SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
	for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) {
		SJ_SplitChunk(&sjd->outck[i], rem * 2, &ck1, &ck2);
		if (sjd->outfn != NULL) {
			sjd->outfn(sjd->outobj, i, ck1.data, ck1.len);
		}
		SJ_PutChunk(sjd->sjo[i], SJ_CK_DATA, &ck1);
		SJ_UngetChunk(sjd->sjo[i], SJ_CK_FREE, &ck2);
	}
	sjd->dec_nsmpl += rem;
	sjd->dec_nbyte += nbyte;
	sjd->decpos += rem;
	sjd->trap_cnt += rem;
	sjd->trap_dtlen += nbyte;
	ADXB_Reset(adxb);
}

/* raw formats: the decoder consumed the block without output */
static void adxsjd_rawexec_end(ADXSJD sjd)
{
	ADXB adxb;
	Sint32 rem;
	Sint32 nbyte;
	Sint32 nsmpl;

	adxb = sjd->adxb;
	rem = ADXB_GetTotalNumSmpl(adxb);
	nbyte = ADXB_GetDecDtLen(adxb);
	nsmpl = ADXB_GetDecNumSmpl(adxb);
	rem -= sjd->decpos;
	if (nsmpl < rem) {
		rem = nsmpl;
	}
	sjd->dec_nsmpl += rem;
	sjd->dec_nbyte += nbyte;
	sjd->decpos += rem;
}

// State step: DECODE starts a block when the ADXB is idle, runs it, collects a finished block and
// accounts raw (undecoded) formats; PREP parses the header.
static void adxsjd_decode(ADXSJD sjd)
{
	ADXB adxb;
	Sint32 stat;
	Sint16 fmt;

	stat = sjd->stat;
	if (stat == ADXSJD_STAT_DECODE) {
		adxb = sjd->adxb;
		if (ADXB_GetStat(adxb) == ADXB_STAT_STOP) {
			adxsjd_decexec_start(sjd);
		}
		ADXB_ExecHndl(adxb);
		if (ADXB_GetStat(adxb) == ADXB_STAT_DONE) {
			adxsjd_decexec_end(sjd);
		}
		fmt = adxb->x98;
		if (fmt == 10 || fmt == 20 || (Uint16)(fmt - 11) <= 1 || fmt == 15) {
			adxsjd_rawexec_end(sjd);
		}
	} else if (stat == ADXSJD_STAT_PREP) {
		adxsjd_decode_prep(sjd);
	}
}

/* discard the requested samples from the output */
static void adxsjd_skip_out(ADXSJD sjd)
{
	SJCK ck;
	Sint32 i;
	Sint32 nbyte;
	Sint32 nsmpl;
	Sint32 n;

	if (sjd->skip_nsmpl <= 0) {
		return;
	}
	ADXCRS_Lock();
	nbyte = sjd->skip_nsmpl * 2;
	for (i = 0; i < sjd->nch; i++) {
		SJ_GetChunk(sjd->sjo[i], SJ_CK_DATA, 0x7FFFFFFF, &ck);
		n = ck.len;
		if (nbyte < n) {
			n = nbyte;
		}
		nbyte = n;
		SJ_UngetChunk(sjd->sjo[i], SJ_CK_DATA, &ck);
	}
	nsmpl = nbyte / 2;
	nbyte = nsmpl * 2;
	if (nbyte > 0) {
		for (i = 0; i < sjd->nch; i++) {
			SJ_GetChunk(sjd->sjo[i], SJ_CK_DATA, nbyte, &ck);
			SJ_PutChunk(sjd->sjo[i], SJ_CK_FREE, &ck);
		}
		sjd->skip_nsmpl -= nsmpl;
	}
	ADXCRS_Unlock();
}

// One tick of one decoder: insert pending silence, decode, then drop pending skip samples.
// FUN_00521C98
void ADXSJD_ExecHndl(ADXSJD sjd)
{
	adxsjd_pad_out(sjd);
	adxsjd_decode(sjd);
	adxsjd_skip_out(sjd);
}

/* start decoding the next block: hand the input chunk to the decoder, or finish at the footer. */
void adxsjd_decexec_start(ADXSJD sjd)
{
	SJCK ck2;
	Sint16 ftrlen;
	ADXB adxb;
	SJ sji;
	Sint32 blksmpl;
	Sint32 len;
	Sint32 i;
	Sint32 n;
	Sint32 z;

	adxb = sjd->adxb;
	sji = sjd->sji;
	if (sjd->trap_nsmpl >= 0 && sjd->trap_cnt >= sjd->trap_nsmpl && sjd->trapfn != NULL) {
		sjd->trapfn(sjd->trapobj);
	}
	if (sjd->spsd == 1) {
		if (SJ_GetNumData(sji, SJ_CK_DATA) == 0) {
			sjd->stat = ADXSJD_STAT_END;
			return;
		}
	}
	SJ_GetChunk(sji, SJ_CK_DATA, 0x7FFFFFFF, &sjd->inck);
	if (ADXB_GetFormat(adxb) == ADXB_FMT_ADX && sjd->inck.len >= 4 &&
	    (Uint16)*(Sint16 *)sjd->inck.data == 0x8001) {
		sjd->stat = ADXSJD_STAT_END;
		if (ADX_DecodeFooter(sjd->inck.data, sjd->inck.len, &ftrlen) == 0) {
			if (ftrlen > sjd->inck.len) {
				SJ_UngetChunk(sji, SJ_CK_DATA, &sjd->inck);
				return;
			}
			SJ_SplitChunk(&sjd->inck, ftrlen, &sjd->inck, &ck2);
			SJ_PutChunk(sji, SJ_CK_FREE, &sjd->inck);
			SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
		}
		if (sjd->lnksw != 0) {
			/* skip the zero padding up to the next linked file */
			for (;;) {
				SJ_GetChunk(sji, SJ_CK_DATA, 0x7FFFFFFF, &sjd->inck);
				len = sjd->inck.len;
				if (len == 0) {
					return;
				}
				for (i = 0; i < len; i++) {
					if (((Sint8 *)sjd->inck.data)[i] != 0) {
						break;
					}
				}
				SJ_SplitChunk(&sjd->inck, i, &sjd->inck, &ck2);
				SJ_PutChunk(sji, SJ_CK_FREE, &sjd->inck);
				SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
				if (i < len) {
					break;
				}
			}
		}
		return;
	}
	if (sjd->decpos >= ADXB_GetTotalNumSmpl(sjd->adxb)) {
		sjd->stat = ADXSJD_STAT_END;
		SJ_UngetChunk(sji, SJ_CK_DATA, &sjd->inck);
		return;
	}
	/* COMPILER-DIFF: M4 (dead conditional) -- the hoisted 0x7FFFFFFF (`lis 0x8000` + subi) of the
	 * padding-skip loop is coloured r31 and len r28 in the target, which needs blksmpl coloured AFTER
	 * that temporary: blksmpl must survive as an own local (`mr r28, r3`). Backend copy propagation
	 * replaces a single-def copy of the call result by the `@ret` temp (coloured first, it hands out
	 * r28 and the `lis` takes it); the dead second def `blksmpl = sjd->decpos` blocks it. Placed after
	 * the SJ_GetNumData call so the copy stays in that call's setup block; the post-RA peephole folds
	 * `li; cmpi; bt` into the fall-through and deletes the unreachable arm. */
	blksmpl = ADXB_GetBlkSmpl(sjd->adxb);
	n = SJ_GetNumData(sjd->sjo[0], SJ_CK_FREE);
	z = 0;
	if (z != 0) {
		blksmpl = sjd->decpos;
	}
	if (n / 2 < blksmpl) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &sjd->inck);
		return;
	}
	if (ADXB_GetFormat(adxb) == 10) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &sjd->inck);
	}
	ADXB_EntryData(adxb, sjd->inck.data, sjd->inck.len);
	ADXB_Start(adxb);
}

/* ADXB write callback: where and how much PCM may be written. */
// FUN_004CE0C8
void *adxsjd_get_wr(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *trap)
{
	/* the typed copy of the `void *` handle is a kept user copy (`mr r31, r3`) that ranks s r31 above
	 * trap r30 / nsmpl r29; a typed parameter gets r29 below them */
	ADXSJD s = obj;
	SJ sjo0;
	Sint32 i;
	Sint32 n;

	sjo0 = s->sjo[0];
	for (i = 0; i < ADXB_GetNumChan(s->adxb); i++) {
		SJ_GetChunk(s->sjo[i], SJ_CK_FREE, 0x4000, &s->outck[i]);
	}
	*pos = (s->outck[0].data - (Uint8 *)SJRBF_GetBufPtr(sjo0)) / 2;
	n = s->maxdecsmpl;
	if (s->outck[0].len / 2 < n) {
		n = s->outck[0].len / 2;
	}
	*nsmpl = n;
	if (s->trap_nsmpl >= 0) {
		*trap = s->trap_nsmpl - s->trap_cnt;
	} else {
		*trap = 0x1FFFFFFF;
	}
	return ADXB_GetPcmBuf(s->adxb);
}

/* analyse the header at the start of the input. */
void adxsjd_decode_prep(ADXSJD sjd)
{
	SJCK ck;
	SJCK ck2;
	ADXB adxb;
	SJ sji;
	Sint32 hdrlen;
	Sint32 i;
	Sint32 fmt;
	Sint32 len;
	Sint32 z;

	sji = sjd->sji;
	adxb = sjd->adxb;
	SJ_GetChunk(sji, SJ_CK_DATA, 0xC800, &ck);
	for (i = 0; i < ck.len; i++) {
		if (((Sint8 *)ck.data)[i] != 0) {
			break;
		}
	}
	SJ_SplitChunk(&ck, i, &ck2, &ck);
	SJ_PutChunk(sji, SJ_CK_FREE, &ck2);
	/* COMPILER-DIFF: M4 (dead conditional) -- the post-call single-use length is r5 in the target, i.e.
	 * its web has r0/r3/r4 neighbours that leave no instruction. The dead arm's three field loads are
	 * live together with len at RA time (coloured r0, r3, r4 before it) and are deleted with the arm by
	 * the post-RA peephole (`li; cmpi; bt` folded into the fall-through). One load gives r3, two r4. */
	len = ck.len;
	z = 0;
	if (z != 0) {
		len = len + sjd->decpos + sjd->trap_cnt + sjd->trap_nsmpl;
	}
	if (len < 16) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
		return;
	}
	hdrlen = ADXB_DecodeHeader(adxb, ck.data);
	if (hdrlen == 0 || hdrlen > ck.len) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
		return;
	}
	if (hdrlen < 0) {
		if (adxb->x9a != 0) {
			ADXB_SetDefPrm(adxb);
			hdrlen = 0;
		} else {
			SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
			ADXERR_CallErrFunc2("E03010901 ADXB_DecodeHeader: ", "Can not decode this file format.");
			sjd->stat = ADXSJD_STAT_ERROR;
			return;
		}
	}
	sjd->hdrlen = hdrlen;
	if (ADXB_GetFormat(adxb) == ADXB_FMT_SPSD) {
		sjd->spsd = 1;
	}
	if (ADXB_GetFormat(adxb) == ADXB_FMT_PCM16) {
		memcpy(sjd->spsdinf, ck.data, (ck.len < 0x40) ? ck.len : 0x40);
	}
	fmt = ADXB_GetFormat(adxb);
	if (ADXSJD_IS_RAW_FMT(fmt)) {
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck);
	} else {
		SJ_SplitChunk(&ck, hdrlen, &ck, &ck2);
		SJ_PutChunk(sji, SJ_CK_FREE, &ck);
		SJ_UngetChunk(sji, SJ_CK_DATA, &ck2);
	}
	if (adxb->xdc != 0 && pl2setsfreqfunc != NULL) {
		pl2setsfreqfunc(adxb, adxb->sfreq);
	}
	sjd->stat = ADXSJD_STAT_DECODE;
}

// Stops the block decoder and the SJD (stat STOP).
void ADXSJD_Stop(ADXSJD sjd)
{
	ADXB_Stop(sjd->adxb);
	sjd->stat = ADXSJD_STAT_STOP;
}

/* per-play state */
static void adxsjd_reset(ADXSJD sjd)
{
	sjd->hdrlen = 0;
	sjd->dec_nsmpl = 0;
	sjd->dec_nbyte = 0;
	sjd->decpos = 0;
	sjd->maxdecsmpl = 0x7FFFFFFF;
	sjd->trap_nsmpl = -1;
	sjd->trap_cnt = 0;
	sjd->trap_dtlen = 0;
	sjd->spsd = 0;
	sjd->pad_nsmpl = 0;
	sjd->skip_nsmpl = 0;
}

// Resets the per-play counters and enters PREP: the next tick parses the header at the input.
void ADXSJD_Start(ADXSJD sjd)
{
	adxsjd_reset(sjd);
	sjd->stat = ADXSJD_STAT_PREP;
}

// Tells the AHX decoder that no more input will arrive (flushes its last block).
void ADXSJD_TermSupply(ADXSJD sjd)
{
	ADXB_AhxTermSupply(sjd->adxb);
}

// Caps the samples decoded per server tick (ADXT: obufsize/svrfreq derived), also for the AHX path.
void ADXSJD_SetMaxDecSmpl(ADXSJD sjd, Sint32 nsmpl)
{
	sjd->maxdecsmpl = nsmpl;
	ADXB_SetAhxDecSmpl(sjd->adxb, nsmpl);
}

// Changes the input stream joint (ADXT swaps between the file stream and a memory stream).
void ADXSJD_SetInSj(ADXSJD sjd, SJ sji)
{
	sjd->sji = sji;
	ADXB_SetAhxInSj(sjd->adxb, sji);
}

// Decoder state (ADXSJD_STAT_STOP/PREP/DECODE/END/ERROR).
Sint32 ADXSJD_GetStat(ADXSJD sjd)
{
	return sjd->stat;
}

// Destroys the block decoder and clears the slot.
// FUN_004CDC38
void ADXSJD_Destroy(ADXSJD sjd)
{
	ADXB adxb;

	if (sjd == NULL) {
		return;
	}
	adxb = sjd->adxb;
	if (adxb != NULL) {
		sjd->adxb = NULL;
		ADXB_Destroy(adxb);
	}
	ADXCRS_Lock();
	memset(sjd, 0, sizeof(ADXSJD_OBJ));
	ADXCRS_Unlock();
}

// Takes a free adxsjd_obj slot; the ADXB writes into the ring buffer of the first output stream joint
// (`sjo[0]`, its size and extra area in samples), the other channels are `chofst` samples apart.
ADXSJD ADXSJD_Create(SJ sji, Sint32 nch, SJ *sjo)
{
	ADXSJD sjd;
	Sint32 i;
	void *buf;
	SJ sjo0;
	Sint32 bsize;
	Sint32 xsize;

	sjo0 = sjo[0];
	for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
		if (adxsjd_obj[i].used == 0) {
			break;
		}
	}
	if (i == ADXSJD_MAX_OBJ) {
		return NULL;
	}
	sjd = &adxsjd_obj[i];
	buf = SJRBF_GetBufPtr(sjo0);
	bsize = SJRBF_GetBufSize(sjo0) / 2;
	xsize = SJRBF_GetXtrSize(sjo0) / 2;
	sjd->adxb = ADXB_Create(nch, buf, bsize, bsize + xsize);
	if (sjd->adxb == NULL) {
		return NULL;
	}
	ADXB_EntryGetWrFunc(sjd->adxb, adxsjd_get_wr, sjd);
	sjd->sji = sji;
	sjd->nch = nch;
	for (i = 0; i < nch; i++) {
		sjd->sjo[i] = sjo[i];
	}
	sjd->stat = ADXSJD_STAT_STOP;
	adxsjd_reset(sjd);
	sjd->trapfn = NULL;
	sjd->trapobj = NULL;
	sjd->outfn = NULL;
	sjd->outobj = NULL;
	sjd->used = 1;
	return sjd;
}

// Clears all decoder slots (library shutdown).
void ADXSJD_Finish(void)
{
	memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

// Library init: ADXB_Init plus clearing the slots.
void ADXSJD_Init(void)
{
	ADXB_Init();
	memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}
