/* CRI ADXT (ADX talk) handle API (adx_tlk.c): creation/destruction of the stream playback handles
 * over the ADX work layout, start/stop, pause, volume/pan/balance, status and time queries, the
 * sample-time bookkeeping used for the vsync-based time mode, silence insertion and the header/end
 * code tests. Built with `-inline auto,deferred` (CRI_CFLAG_OVERRIDES): the DOL's .text is the
 * reverse of this file, the string literals are in codegen (= .text) order and .bss in reverse
 * declaration order; the public accessors are inlined into their users (the dead-stripped
 * functions of the original are kept for their strings). */
#include <string.h>
#include "cri_xpt.h"
#include "sj.h"
#include "adx_t.h"
#include "adx_stm.h"

extern void ADXERR_CallErrFunc1(Char8 *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern Uint32 __cvt_fp2unsigned(Float32 f);
extern Sint32 ADX_DecodeInfo(Uint8 *data, Sint32 len, Sint16 *hdrlen, Sint8 *fmt, Sint8 *bps, Sint8 *blksiz,
                             Sint8 *nch, Sint32 *sfreq, Sint32 *nsmpl, Sint32 *blksmpl);
extern void *ADXSJD_Create(SJ sji, Sint32 nch, SJ *sjo);
extern void ADXSJD_Destroy(void *sjd);
extern void ADXSJD_Start(void *sjd);
extern void ADXSJD_Stop(void *sjd);
extern void ADXSJD_ExecServer(void);
extern void ADXSJD_SetInSj(void *sjd, SJ sji);
extern void ADXSJD_SetLnkSw(void *sjd, Sint32 sw);
extern void ADXSJD_SetKeyString(void *sjd, Char8 *str);
extern void ADXSJD_TermSupply(void *sjd);
extern Sint32 ADXSJD_GetNumChan(void *sjd);
extern Sint32 ADXSJD_GetSfreq(void *sjd);
extern Sint32 ADXSJD_GetTotalNumSmpl(void *sjd);
extern Sint32 ADXSJD_GetDecNumSmpl(void *sjd);
extern Sint32 ADXSJD_GetDecDtLen(void *sjd);
extern Sint32 ADXSJD_GetOutBps(void *sjd);
extern Sint32 ADXSJD_GetFmtBps(void *sjd);
extern Sint32 ADXSJD_GetHdrLen(void *sjd);
extern Sint16 ADXSJD_GetDefOutVol(void *sjd);
extern Sint16 ADXSJD_GetDefPan(void *sjd, Sint32 ch);
extern void *ADXRNA_Create(SJ *sjo, Sint32 nch, void *work);
extern void ADXRNA_Destroy(void *rna);
extern void ADXRNA_ExecServer(void);
extern void ADXRNA_SetPlaySw(void *rna, Sint32 sw);
extern void ADXRNA_SetTransSw(void *rna, Sint32 sw);
extern void ADXRNA_SetOutVol(void *rna, Sint32 vol);
extern void ADXRNA_SetOutPan(void *rna, Sint32 ch, Sint32 pan);
extern void ADXRNA_SetOutBalance(void *rna, Sint32 bal);
extern Sint32 ADXRNA_GetNumData(void *rna);
extern Sint32 ADXRNA_DiscardData(void *rna, Sint32 nsmpl);
extern void ADXAMP_Start(void *amp);
extern void ADXAMP_Stop(void *amp);
extern void ADXAMP_Destroy(void *amp);
extern void *LSC_Create(SJ sj);
extern void LSC_Destroy(void *lsc);
extern void LSC_Stop(void *lsc);
extern void LSC_SetStmHndl(void *lsc, ADXSTM stm);
extern void ADXSTM_EntryEosFunc(ADXSTM stm, void (*fn)(ADXT adxt), void *obj);
extern Sint32 ADXSTM_GetNumSctIbuf(ADXSTM stm);
extern void ADXT_ExecHndl(ADXT adxt);

/* work layout of one handle: the decoder output rings (0x3060 16-bit samples per channel), the
 * renderer work (0x40C0 bytes per channel) and the file stream ring (the rest, in sectors) */
#define ADXT_OBUF_NSMPL 0x3060
#define ADXT_OBUF_BSIZE 0x2000
#define ADXT_OBUF_STRIDE 0x2060
#define ADXT_RNA_WORK 0x40C0
#define ADXT_IBUF_XSIZE 0x24
#define ADXT_SCT_SIZE 0x800

/* ADXT_OBJ.stat (public) */
#define ADXT_STAT_PLAYEND 5

/* (.bss is the reverse of this order) */
static Float32 adxt_mviop_f;
Sint32 adxt_mviop_d;
static Sint32 adxt_mvtmp_d;
Sint32 adxt_time_unit;
static Float32 adxt_diff_av;
Sint32 adxt_fileid_buf[4];
Sint32 adxt_svrcnt_hndl;
Sint32 adxt_svrcnt_adxstm;
Sint32 adxt_svrcnt_adxf;
Sint32 adxt_svrcnt_rna;
Sint32 adxt_svrcnt_sjd;
Sint32 adxt_svrcnt;
static Sint32 adxt_time_adjust_cnt;
void (*pl2detachfunc)(ADXT adxt);
void (*ahxdetachfunc)(ADXT adxt);
static Sint32 adxt_last_svrfreq;
Sint32 adxt_def_svrfreq;
Sint32 adxt_tsvr_enter_cnt;
Sint32 adxt_time_mode;

static Sint32 adxstm_seteos_sct = 25;
Uint32 adxt_time_adjust_sw = 1;

Sint32 ADXT_GetStat(ADXT adxt);
Sint32 ADXT_GetNumChan(ADXT adxt);
Sint32 ADXT_GetSfreq(ADXT adxt);
Sint32 ADXT_GetOutPan(ADXT adxt, Sint32 ch);
void ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan);
Sint32 ADXT_GetOutBalance(ADXT adxt);
void ADXT_SetOutBalance(ADXT adxt, Sint32 bal);
Sint32 ADXT_GetNumSmplObuf(ADXT adxt);
void ADXT_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale);
void ADXT_SetLnkSw(ADXT adxt, Sint32 sw);
void ADXT_Stop(ADXT adxt);
void ADXT_Destroy(ADXT adxt);
void ADXT_ExecServer(void);

// Allocates a stream playback handle for up to `maxnch` channels inside the caller's `work` buffer
// (64-byte aligned): the decoder output rings (0x3060 samples per channel), the AX renderer work and
// the file stream ring (the rest, in 2 KiB sectors; reload threshold 85% of it). Builds the stream
// joints, the ADXSTM stream controller, the ADXSJD decoder, the ADXRNA renderer and an LSC scheduler. Returns NULL (with an error message) if no slot is
// free or the parameters are bad.
ADXT ADXT_Create(Sint32 maxnch, void *work, Sint32 worksize)
{
	ADXT adxt;
	Sint32 i;
	Uint8 *wk = (Uint8 *)(((Uint32)work + 63) & ~63);
	Sint32 wksize = worksize - ((Sint32)wk - (Sint32)work);
	Sint32 obufbytes;

	if (maxnch < 0 || work == NULL || worksize < 0) {
		ADXERR_CallErrFunc1("E02080804 ADXT_Create: parameter error");
		return NULL;
	}
	for (i = 0; i < ADXT_MAX_OBJ; i++) {
		if (adxt_obj[i].used == 0) {
			break;
		}
	}
	if (i == ADXT_MAX_OBJ) {
		ADXERR_CallErrFunc1("E03100801 ADXT_Create: Too many handles.\n");
		return NULL;
	}
	adxt = &adxt_obj[i];
	memset(adxt, 0, sizeof(ADXT_OBJ));
	adxt->maxnch = maxnch;
	obufbytes = (maxnch * ADXT_OBUF_NSMPL) << 1;
	adxt->ibuf = wk + obufbytes;
	adxt->ibufsize = (wksize - obufbytes - 0x124) / ADXT_SCT_SIZE * ADXT_SCT_SIZE;
	adxt->ibufxsize = ADXT_IBUF_XSIZE;
	adxt->wkend = adxt->ibufsize + adxt->ibufxsize + adxt->ibuf;
	adxt->obuf = wk;
	adxt->obufsize = ADXT_OBUF_BSIZE;
	adxt->obufstride = ADXT_OBUF_STRIDE;
	adxt->sji = NULL;
	adxt->sjf = SJRBF_Create(adxt->ibuf, adxt->ibufsize, adxt->ibufxsize);
	if (adxt->sjf == NULL) {
		ADXT_Destroy(adxt);
		return NULL;
	}
	if ((adxt->stm = ADXSTM_Create(adxt->sjf, 0)) == NULL) {
		ADXT_Destroy(adxt);
		return NULL;
	}
	for (i = 0; i < maxnch; i++) {
		adxt->sjo[i] = SJRBF_Create(adxt->obuf + adxt->obufstride * i * 2, adxt->obufsize * 2,
					    (adxt->obufstride - adxt->obufsize) * 2);
		if (adxt->sjo[i] == NULL) {
			ADXT_Destroy(adxt);
			return NULL;
		}
	}
	if ((adxt->sjd = ADXSJD_Create(adxt->sjf, maxnch, adxt->sjo)) == NULL) {
		ADXT_Destroy(adxt);
		return NULL;
	}
	if ((adxt->rna = ADXRNA_Create(adxt->sjo, maxnch, wk + maxnch * ADXT_RNA_WORK)) == NULL) {
		ADXT_Destroy(adxt);
		return NULL;
	}
	if ((adxt->lsc = LSC_Create(adxt->sjf)) == NULL) {
		ADXT_Destroy(adxt);
		return NULL;
	}
	LSC_SetStmHndl(adxt->lsc, adxt->stm);
	ADXCRS_Lock();
	adxt->svrfreq = adxt_def_svrfreq;
	adxt->ibuf_nsct = adxt->ibufsize / ADXT_SCT_SIZE;
	adxt->reload_nsct = (Sint16)(0.85f * (Float32)adxt->ibuf_nsct);
	adxt->outvol = 0;
	for (i = 0; i < maxnch; i++) {
		adxt->outpan[i] = -128;
	}
	adxt->outbal = 0;
	adxt->lpsw = 1;
	adxt->x54 = 0;
	adxt->x58 = 0;
	adxt->x5c = 0;
	adxt->errcode = 0;
	adxt->x64 = 0;
	adxt->x68 = 0;
	adxt->x6a = 0;
	adxt->autorcvr = 1;
	adxt->x72 = 0;
	adxt->timeofst = 0;
	ADXT_SetLnkSw(adxt, 0);
	adxt->used = 1;
	ADXCRS_Unlock();
	return adxt;
}

// Stops the stream, detaches the AHX / Pro Logic II extensions if any, releases the stream controller,
// the decoder, the renderer and every stream joint, and frees the adxt_obj slot.
void ADXT_Destroy(ADXT adxt)
{
	ADXSTM stm;
	Sint32 i;
	SJ sj;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080805 ADXT_Destroy: parameter error");
		return;
	}
	if (ahxdetachfunc != NULL) {
		ahxdetachfunc(adxt);
	}
	if (pl2detachfunc != NULL) {
		pl2detachfunc(adxt);
	}
	if (adxt->used == 1) {
		ADXT_Stop(adxt);
	}
	if (adxt->rna != NULL) {
		void *rna = adxt->rna;
		adxt->rna = NULL;
		ADXRNA_Destroy(rna);
	}
	if (adxt->sjd != NULL) {
		void *sjd = adxt->sjd;
		adxt->sjd = NULL;
		ADXSJD_Destroy(sjd);
	}
	stm = adxt->stm;
	if (stm != NULL) {
		adxt->stm = NULL;
		ADXSTM_EntryEosFunc(stm, NULL, NULL);
		ADXSTM_Destroy(stm);
	}
	if (adxt->lsc != NULL) {
		void *lsc = adxt->lsc;
		adxt->lsc = NULL;
		LSC_Destroy(lsc);
	}
	ADXCRS_Lock();
	if (adxt->sjf != NULL) {
		sj = adxt->sjf;
		adxt->sjf = NULL;
		SJ_Destroy(sj);
	}
	for (i = 0; i < adxt->maxnch; i++) {
		if (adxt->sjo[i] != NULL) {
			sj = adxt->sjo[i];
			adxt->sjo[i] = NULL;
			SJ_Destroy(sj);
		}
		if (adxt->sjx[i] != NULL) {
			sj = adxt->sjx[i];
			adxt->sjx[i] = NULL;
			SJ_Destroy(sj);
		}
		if (adxt->sjy[i] != NULL) {
			sj = adxt->sjy[i];
			adxt->sjy[i] = NULL;
			SJ_Destroy(sj);
		}
	}
	if (adxt->amp != NULL) {
		void *amp = adxt->amp;
		adxt->amp = NULL;
		ADXAMP_Destroy(amp);
	}
	memset(adxt, 0, sizeof(ADXT_OBJ));
	adxt->used = 0;
	ADXCRS_Unlock();
}

// Destroys every live handle (ADXT_Finish).
// FUN_004D3F08
void ADXT_DestroyAll(void)
{
	Sint32 i;

	for (i = 0; i < ADXT_MAX_OBJ; i++) {
		if (adxt_obj[i].used == 1) {
			ADXT_Destroy(&adxt_obj[i]);
		}
	}
}

/* start the decoder on the input stream joint sj (shared by the file stream and SJ starts) */
static void adxt_start_sjd(ADXT adxt, SJ sj)
{
	Sint32 i;

	for (i = 0; i < adxt->maxnch; i++) {
		SJ_Reset(adxt->sjo[i]);
	}
	ADXSJD_SetInSj(adxt->sjd, sj);
	adxt->sji = sj;
	ADXSJD_Start(adxt->sjd);
	adxt->stat = ADXT_ISTAT_DECINFO;
	adxt->lpcnt = 0;
	adxt->x71 = 0;
	adxt->lpendsct = 0x7FFFFFFF;
	adxt->trapnsmpl = -1;
	adxt->x9c = 0;
	adxt->decsmpl = 0;
	adxt->startvsync = adxt_vsync_cnt;
	if (adxt->amp != NULL) {
		ADXAMP_Start(adxt->amp);
	}
}

// Starts file playback: sizes the stream ring (reload threshold / total, sectors -> bytes), sets the
// end-of-stream lead (adxstm_seteos_sct sectors), rewinds and binds the file range (`ofst`, `nsct`
// sectors, no-wait) on the ADXSTM, starts the transfer and the decoder on the file stream joint.
// FUN_004D40A0
void adxt_start_stm(ADXT adxt, void *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
	ADXSTM_SetBufSize(adxt->stm, adxt->reload_nsct << 11, adxt->ibuf_nsct << 11);
	ADXSTM_SetEos(adxt->stm, adxstm_seteos_sct);
	ADXSTM_EntryEosFunc(adxt->stm, NULL, NULL);
	ADXSTM_Seek(adxt->stm, 0);
	ADXSTM_StopNw(adxt->stm);
	ADXSTM_ReleaseFileNw(adxt->stm);
	ADXSTM_BindFileNw(adxt->stm, fname, dir, ofst, nsct);
	ADXSTM_Start(adxt->stm);
	adxt_start_sjd(adxt, adxt->sjf);
}

// Starts playback from a caller-supplied stream joint (mode 3, no file stream): the decoder reads the
// ADX data the caller puts into `sj`, linked playback is enabled. This is how the Sofdec player feeds
// the movie's audio track (sfd_adxt.c).
// FUN_004D41B0
void ADXT_StartSj(ADXT adxt, SJ sj)
{
	if (adxt == NULL || sj == NULL) {
		ADXERR_CallErrFunc1("E02080812 ADXT_StartSj: parameter error");
		return;
	}
	ADXT_Stop(adxt);
	ADXCRS_Lock();
	adxt_start_sjd(adxt, sj);
	adxt->mode = 3;
	ADXT_SetLnkSw(adxt, 1);
	ADXCRS_Unlock();
}

// Stops playback: releases the file binding, stops the load scheduler (mode 4), the renderer's
// transfer and voices and the decoder, destroys a memory-source stream joint (mode 2) and returns the
// handle to ADXT_ISTAT_STOP.
void ADXT_Stop(ADXT adxt)
{
	SJ sj;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080813 ADXT_Stop: parameter error");
		return;
	}
	if (adxt->stm != NULL) {
		ADXSTM_ReleaseFileNw(adxt->stm);
	}
	ADXCRS_Lock();
	if (adxt->mode == 4) {
		LSC_Stop(adxt->lsc);
		if (adxt->sji != NULL) {
			SJ_Reset(adxt->sji);
		}
	}
	ADXCRS_Lock();
	ADXRNA_SetTransSw(adxt->rna, 0);
	ADXRNA_SetPlaySw(adxt->rna, 0);
	ADXSJD_Stop(adxt->sjd);
	if (adxt->mode == 2 && adxt->sji != NULL) {
		sj = adxt->sji;
		adxt->sji = NULL;
		SJ_Destroy(sj);
	}
	if (adxt->amp != NULL) {
		ADXAMP_Stop(adxt->amp);
	}
	adxt->sji = NULL;
	adxt->stat = ADXT_ISTAT_STOP;
	adxt->stmstart = 0;
	ADXCRS_Unlock();
	ADXCRS_Unlock();
}

// Public handle state: 0 stop, 1 decinfo, 2 prep, 3 playing, 4 playend-wait, 5 playend, 6 error
// (ADXT_ISTAT_*); -1 for a NULL handle.
Sint32 ADXT_GetStat(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080814 ADXT_GetStat: parameter error");
		return -1;
	}
	return adxt->stat;
}

/* the decoded sample count and its rate: samples handed to the decoder minus what is still
 * waiting in the renderer and the output stream joint, plus the earlier linked files */
static void adxt_get_smpl_time(ADXT adxt, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 dec;

	if (adxt->stat == ADXT_ISTAT_PLAYING || adxt->stat == ADXT_ISTAT_PLAYEND_WAIT) {
		*tscale = ADXSJD_GetSfreq(adxt->sjd);
		dec = ADXSJD_GetDecNumSmpl(adxt->sjd);
		*ncount = adxt->decsmpl + (dec - (ADXRNA_GetNumData(adxt->rna) + ADXT_GetNumSmplObuf(adxt)));
	} else if (adxt->stat == ADXT_ISTAT_PLAYEND) {
		*ncount = ADXSJD_GetTotalNumSmpl(adxt->sjd);
		*tscale = ADXSJD_GetSfreq(adxt->sjd);
		*ncount = *ncount * (16 / ADXSJD_GetOutBps(adxt->sjd));
		*ncount = *ncount + adxt->decsmpl;
	} else {
		*ncount = 0;
		*tscale = 1;
	}
	*ncount = *ncount + adxt->timeofst;
	if (*ncount < 0) {
		*ncount = 0;
	}
}

/* the vsync-based time position in adxt_time_unit units from the current sample time */
#define ADXT_SET_TIME_POS(adxt, nc, ts) \
	(adxt)->x9c = __cvt_fp2unsigned((Float32)adxt_time_unit * ((Float32)(nc) / (Float32)(ts)))

// Playback time: sample mode (adxt_time_mode 0) returns decoded-and-rendered samples over the sampling
// rate; vsync mode counts vsyncs since start in adxt_time_unit units and resynchronises to the sample
// time when they drift more than 60 ms apart (adxt_time_adjust_cnt). The Sofdec player uses this to
// slave the video clock to the audio.
void ADXT_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale)
{
	Sint32 nc;
	Sint32 ts;
	Sint32 mode;
	Float32 diff;

	if (adxt == NULL || ncount == NULL || tscale == NULL) {
		ADXERR_CallErrFunc1("E02080815 ADXT_GetTime: parameter error");
		return;
	}
	if (adxt_time_mode == 0) {
		adxt_get_smpl_time(adxt, ncount, tscale);
		return;
	}
	adxt_diff_av = 0.0f;
	if (adxt->stat == ADXT_ISTAT_PLAYING || adxt->stat == ADXT_ISTAT_PLAYEND_WAIT) {
		if (adxt->x72 == 0) {
			*ncount = adxt->x9c + (adxt_vsync_cnt - adxt->startvsync) * 100;
		} else {
			*ncount = adxt->x9c;
		}
		adxt_get_smpl_time(adxt, &nc, &ts);
		diff = 1000.0f * ((Float32)nc / (Float32)ts - (Float32)*ncount / (Float32)adxt_time_unit);
		adxt_diff_av = diff;
		if (diff > 60.0f || diff < -60.0f) {
			if (adxt_time_adjust_sw == 1) {
				mode = adxt_time_mode;
				adxt_time_mode = 0;
				ADXT_GetTime(adxt, &nc, &ts);
				adxt_time_mode = mode;
				adxt_time_adjust_cnt++;
			}
			ADXT_SET_TIME_POS(adxt, nc, ts);
			adxt->startvsync = adxt_vsync_cnt;
		}
	} else if (adxt->stat == ADXT_ISTAT_PLAYEND) {
		nc = ADXSJD_GetTotalNumSmpl(adxt->sjd);
		ts = ADXSJD_GetSfreq(adxt->sjd);
		nc = nc * (16 / ADXSJD_GetOutBps(adxt->sjd));
		*ncount = (Sint32)((Float32)adxt_time_unit * ((Float32)nc / (Float32)ts));
		*ncount += adxt->x9c + 1;
	} else {
		*ncount = 0;
	}
	*ncount = *ncount + adxt->timeofst;
	*tscale = adxt_time_unit;
}

/* (dead-stripped) movie synchronisation: the decoded position in 1/100 vsync units */
Float32 ADXT_GetMvTime(ADXT adxt)
{
	adxt_mvtmp_d = adxt_vsync_cnt - adxt->startvsync;
	adxt_mviop_d = adxt_mvtmp_d * 100;
	adxt_mviop_f = (Float32)adxt_mviop_d / 100.0f;
	return adxt_mviop_f;
}

// Total sample count of the stream once the header is known (stat >= PREP), else 0.
Sint32 ADXT_GetNumSmpl(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080817 ADXT_GetNumSmpl: parameter error");
		return -1;
	}
	if (adxt->stat >= ADXT_ISTAT_PREP) {
		return ADXSJD_GetTotalNumSmpl(adxt->sjd);
	}
	return 0;
}

/* (dead-stripped) */
Sint32 ADXT_GetHdrLen(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080822 ADXT_GetHdrLen: parameter error");
		return -1;
	}
	if (adxt->stat >= ADXT_ISTAT_PREP) {
		return ADXSJD_GetHdrLen(adxt->sjd);
	}
	return 0;
}

/* (dead-stripped) */
Sint32 ADXT_GetFmtBps(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080821 ADXT_GetFmtBps: parameter error");
		return -1;
	}
	if (adxt->stat >= ADXT_ISTAT_PREP) {
		return ADXSJD_GetFmtBps(adxt->sjd);
	}
	return 0;
}

// Sampling rate of the stream in Hz once the header is known, else 0.
Sint32 ADXT_GetSfreq(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080819 ADXT_GetSfreq: parameter error");
		return -1;
	}
	if (adxt->stat >= ADXT_ISTAT_PREP) {
		return ADXSJD_GetSfreq(adxt->sjd);
	}
	return 0;
}

// Channel count of the stream once the header is known, else 0.
Sint32 ADXT_GetNumChan(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080820 ADXT_GetNumChan: parameter error");
		return -1;
	}
	if (adxt->stat >= ADXT_ISTAT_PREP) {
		return ADXSJD_GetNumChan(adxt->sjd);
	}
	return 0;
}

/* pan: -128 = default (the stream's own, +-15 for stereo), else the value plus the stream's;
 * everything centred when the output is mono */
void ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan)
{
	Sint32 defpan;
	Sint32 p;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080825 ADXT_SetOutPan: parameter error");
		return;
	}
	defpan = ADXSJD_GetDefPan(adxt->sjd, ch);
	if (defpan == -128) {
		defpan = 0;
	}
	if (adxt_output_mono_flag == 0) {
		if (pan == -128) {
			if (ADXSJD_GetNumChan(adxt->sjd) == 2) {
				p = (ch == 0) ? -15 : 15;
			} else {
				p = 0;
			}
			p += defpan;
		} else {
			p = pan + defpan;
		}
	} else {
		p = 0;
	}
	adxt->outpan[ch] = pan;
	if (ch < adxt->maxnch) {
		ADXRNA_SetOutPan(adxt->rna, ch, p);
	} else {
		ADXERR_CallErrFunc1("E8101208 ADXT_SetOutPan: parameter error");
	}
}

// The pan last set for channel `ch` (-15..15, -128 = the stream default).
// FUN_004D4FA0
Sint32 ADXT_GetOutPan(ADXT adxt, Sint32 ch)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080826 ADXT_GetOutPan: parameter error");
		return 0;
	}
	return adxt->outpan[ch];
}

// Sets the output volume in 1/10 dB (0 = full, down to -999) and pushes it, plus the stream's own AINF
// default volume, to the renderer.
void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080823 ADXT_SetOutVol: parameter error");
		return;
	}
	adxt->outvol = vol;
	ADXRNA_SetOutVol(adxt->rna, adxt->outvol + ADXSJD_GetDefOutVol(adxt->sjd));
}

// The volume last set with ADXT_SetOutVol.
// FUN_004D51F8
Sint32 ADXT_GetOutVol(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080824 ADXT_GetOutVol: parameter error");
		return 0;
	}
	return adxt->outvol;
}

// Sets the assumed server call rate (Hz) used when sizing the per-call decode step of new handles
// (ADXT_Init sets 60).
void ADXT_SetDefSvrFreq(Sint32 freq)
{
	adxt_def_svrfreq = freq;
	adxt_last_svrfreq = freq;
}

// Per-handle server call rate (Hz); adxt_stat_decinfo derives maxdecsmpl = sfreq / svrfreq from it.
// FUN_004D54C8
void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080840 ADXT_SetSvrFreq: parameter error");
		return;
	}
	adxt->svrfreq = freq;
	adxt_last_svrfreq = freq;
}

/* (dead-stripped) reload threshold from a time in seconds */
void ADXT_SetReloadTime(ADXT adxt, Float32 time)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080838 ADXT_SetReloadTime: parameter error");
		return;
	}
	adxt->reload_nsct = (Sint16)(time * (Float32)(ADXSJD_GetSfreq(adxt->sjd) * adxt->maxnch * 18 / 32 / ADXT_SCT_SIZE));
}

/* (dead-stripped) */
void ADXT_ResetReloadTime(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E03111501 ADXT_ResetReloadTime: parameter error");
		return;
	}
	adxt->reload_nsct = (Sint16)(0.85f * (Float32)adxt->ibuf_nsct);
}

/* (dead-stripped) */
void ADXT_SetReloadSct(ADXT adxt, Sint32 nsct)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080839 ADXT_SetReloadSct: parameter error");
		return;
	}
	adxt->reload_nsct = nsct;
}

/* (dead-stripped) */
Sint32 ADXT_GetNumSctIbuf(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080834 ADXT_GetNumSctIbuf: parameter error");
		return -1;
	}
	return ADXSTM_GetNumSctIbuf(adxt->stm);
}

/* samples waiting in the first output stream joint (16-bit) */
Sint32 ADXT_GetNumSmplObuf(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080837 ADXT_GetNumSmplObuf: parameter error");
		return -1;
	}
	if (adxt->sjo[0] != NULL) {
		return SJ_GetNumData(adxt->sjo[0], SJ_CK_DATA) / 2;
	}
	return 0;
}

/* (dead-stripped) playback time left in the input buffer, in seconds */
Float32 ADXT_GetIbufRemainTime(ADXT adxt)
{
	Float32 rtime = 0.0f;
	Sint32 stat;
	Sint32 nch;
	Sint32 sfreq;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080835 ADXT_GetIbufRemainTime: parameter error");
		return -1.0f;
	}
	stat = ADXT_GetStat(adxt);
	nch = ADXT_GetNumChan(adxt);
	sfreq = ADXT_GetSfreq(adxt);
	if (stat >= ADXT_ISTAT_PREP && nch > 0 && sfreq > 0) {
		rtime = (Float32)(ADXSTM_GetNumSctIbuf(adxt->stm) * ADXT_SCT_SIZE / (nch * 18) * 32) / (Float32)sfreq;
	}
	return rtime;
}

/* (dead-stripped) */
Bool ADXT_IsIbufSafety(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080836 ADXT_IsIbufSafety: parameter error");
		return FALSE;
	}
	if (ADXSTM_GetNumSctIbuf(adxt->stm) >= adxt->reload_nsct) {
		return TRUE;
	}
	return FALSE;
}

/* (dead-stripped) */
// FUN_004D5AF8
Bool ADXT_IsCompleted(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080802 ADXT_IsCompleted: parameter error");
		/* P4: 9.44 reports the parameter error as -1 rather than FALSE;
		 * retail loads `addiu $v0, $zero, -1` on this path at 0x004D5B14. */
		return -1;
	}
	if (adxt->stat == ADXT_STAT_PLAYEND) {
		return TRUE;
	}
	return FALSE;
}

// Automatic recovery switch: when set, a stream underrun restarts the renderer instead of stopping.
void ADXT_SetAutoRcvr(ADXT adxt, Sint32 sw)
{
	adxt->autorcvr = sw;
}

/* decoders, handles, renderer; the phase counter keeps a nested call (a callback calling the
 * server) out */
void ADXT_ExecServer(void)
{
	Sint32 i;

	ADXCRS_Lock();
	if (adxt_tsvr_enter_cnt != 0) {
		ADXCRS_Unlock();
		return;
	}
	adxt_tsvr_enter_cnt = 1;
	ADXCRS_Unlock();
	ADXSJD_ExecServer();
	adxt_tsvr_enter_cnt = 2;
	for (i = 0; i < ADXT_MAX_OBJ; i++) {
		if (adxt_obj[i].used == 1) {
			ADXT_ExecHndl(&adxt_obj[i]);
		}
	}
	adxt_tsvr_enter_cnt = 3;
	ADXRNA_ExecServer();
	adxt_tsvr_enter_cnt = 0;
}

// Error code of the handle (-1 after a stream controller / load scheduler error), 0 if none.
// FUN_004D5CC0
Sint32 ADXT_GetErrCode(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080843 ADXT_GetErrCode: parameter error");
		return -1;
	}
	return adxt->errcode;
}

/* (dead-stripped) */
void ADXT_ClearErrCode(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080844 ADXT_ClearErrCode: parameter error");
		return;
	}
	adxt->errcode = 0;
}

/* (dead-stripped) */
// FUN_004D5D98
Sint32 ADXT_GetLpCnt(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080829 ADXT_GetLpCnt: parameter error");
		return -1;
	}
	return adxt->lpcnt;
}

/* (dead-stripped) */
void ADXT_SetLpFlg(ADXT adxt, Sint32 flg)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080828 ADXT_SetLpFlg: parameter error");
		return;
	}
	adxt->lpsw = flg;
}

/* (dead-stripped) */
SJ ADXT_GetInputSj(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080833 ADXT_GetInputSj: parameter error");
		return NULL;
	}
	return adxt->sji;
}

/* (dead-stripped) */
// FUN_004D5FB8
void ADXT_SetWaitPlayStart(ADXT adxt, Sint32 sw)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080830 ADXT_SetWaitPlayStart: parameter error");
		return;
	}
	adxt->pausesw = sw;
}

/* (dead-stripped) */
Bool ADXT_IsReadyPlayStart(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080831 ADXT_IsReadyPlayStart: parameter error");
		return FALSE;
	}
	return adxt->x71;
}

// Pause (sw 1) / resume (sw 0): stops or restarts the AX renderer voices and rebases the vsync time
// position so ADXT_GetTime stays continuous.
void ADXT_Pause(ADXT adxt, Sint32 sw)
{
	Sint32 stat;
	Sint32 mode;
	Sint32 nc;
	Sint32 ts;

	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080846 ADXT_Pause: parameter error");
		return;
	}
	stat = adxt->stat;
	if (sw == adxt->x72) {
		return;
	}
	ADXCRS_Lock();
	adxt->x72 = sw;
	if (stat == ADXT_ISTAT_PLAYING || stat == ADXT_ISTAT_PLAYEND_WAIT) {
		if (sw == 1) {
			ADXRNA_SetPlaySw(adxt->rna, 0);
		} else {
			ADXRNA_SetPlaySw(adxt->rna, 1);
			adxt->startvsync = adxt_vsync_cnt;
		}
		mode = adxt_time_mode;
		adxt_time_mode = 0;
		ADXT_GetTime(adxt, &nc, &ts);
		adxt_time_mode = mode;
		ADXT_SET_TIME_POS(adxt, nc, ts);
	}
	ADXCRS_Unlock();
}

/* (dead-stripped) */
// FUN_004D61F8
Sint32 ADXT_GetStatPause(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080847 ADXT_GetStatPause: parameter error");
		return 0;
	}
	return adxt->x72;
}

// Pitch transpose is not supported by the AX renderer: no-op kept for the API.
void ADXT_SetTranspose(ADXT adxt, Sint32 oct, Sint32 cent)
{
}

// No-op (see ADXT_SetTranspose).
void ADXT_GetTranspose(ADXT adxt, Sint32 *oct, Sint32 *cent)
{
}

// Tells the decoder that no more input data will arrive (end of a memory / stream-joint source).
void ADXT_TermSupply(ADXT adxt)
{
	ADXSJD_TermSupply(adxt->sjd);
}

/* drop nsmpl samples of renderer data (while paused); the server is run once so the decoder
 * refills, then the time position is resynchronised */
Sint32 ADXT_DiscardSmpl(ADXT adxt, Sint32 nsmpl)
{
	Sint32 n;
	Sint32 mode;
	Sint32 nc;
	Sint32 ts;

	if (adxt->x72 == 0) {
		return 0;
	}
	n = ADXRNA_DiscardData(adxt->rna, nsmpl);
	ADXT_ExecServer();
	mode = adxt_time_mode;
	adxt_time_mode = 0;
	ADXT_GetTime(adxt, &nc, &ts);
	adxt_time_mode = mode;
	ADXT_SET_TIME_POS(adxt, nc, ts);
	adxt->startvsync = adxt_vsync_cnt;
	return n;
}

/* (dead-stripped) */
Sint32 ADXT_GetDecNumSmpl(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080818 ADXT_GetDecNumSmpl: parameter error");
		return -1;
	}
	return ADXSJD_GetDecNumSmpl(adxt->sjd) + adxt->decsmpl;
}

/* (dead-stripped) */
// FUN_004D6710
Sint32 ADXT_GetDecDtLen(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E04041901 ADXT_GetDecDtLen: parameter error");
		return -1;
	}
	return ADXSJD_GetDecDtLen(adxt->sjd);
}

// Offset in samples added to every ADXT_GetTime result (the Sofdec player uses it to align the audio
// clock with the video's first PTS).
void ADXT_SetTimeOfst(ADXT adxt, Sint32 ofst)
{
	adxt->timeofst = ofst;
}

// Linked-file switch: after an ADX end code the decoder continues with the next concatenated stream
// instead of finishing (forwarded to the ADXSJD).
void ADXT_SetLnkSw(ADXT adxt, Sint32 sw)
{
	adxt->lnksw = sw;
	if (adxt->sjd != NULL) {
		ADXSJD_SetLnkSw(adxt->sjd, sw);
	}
}

// True if `data` starts with an ADX header (magic 0x8000) whose info decodes; returns its length in
// *hdrsiz. Used by the Sofdec audio demuxer to find the start of an ADX track.
Bool ADXT_IsHeader(Uint8 *data, Sint32 size, Sint32 *hdrsiz)
{
	Sint16 hdrlen;
	Sint8 fmt;
	Sint8 bps;
	Sint8 blksiz;
	Sint8 nch;
	Sint32 sfreq;
	Sint32 nsmpl;
	Sint32 blksmpl;

	if (size < 2) {
		return FALSE;
	}
	if (*(Uint16 *)data != 0x8000) {
		return FALSE;
	}
	if (ADX_DecodeInfo(data, size, &hdrlen, &fmt, &bps, &blksiz, &nch, &sfreq, &nsmpl, &blksmpl) < 0) {
		return FALSE;
	}
	*hdrsiz = hdrlen;
	return TRUE;
}

// True if `data` starts with an ADX end code (magic 0x8001); *ecsiz gets the remaining size.
Bool ADXT_IsEndcode(Uint8 *data, Sint32 size, Sint32 *ecsiz)
{
	if (size < 2) {
		return FALSE;
	}
	if (*(Uint16 *)data != 0x8001) {
		return FALSE;
	}
	*ecsiz = size;
	return TRUE;
}

/* put nsmpl samples of zero ADX blocks (18 bytes per channel per 32 samples) in front of the
 * decoder input, in two pieces around the ring buffer wrap; returns the samples inserted */
Sint32 ADXT_InsertSilence(ADXT adxt, Sint32 nch, Sint32 nsmpl)
{
	Sint32 blksz;
	Sint32 nbyte;
	SJ sji;
	Sint32 n1;
	Sint32 n2;
	SJCK ck;
	SJCK ck2;

	sji = adxt->sji;
	if (adxt->sji == NULL) {
		return 0;
	}
	blksz = nch * 18;
	nbyte = nsmpl / 32 * blksz;
	SJ_GetChunk(sji, SJ_CK_FREE, nbyte, &ck);
	n1 = ck.len / blksz * blksz;
	memset(ck.data, 0, n1);
	SJ_SplitChunk(&ck, n1, &ck, &ck2);
	SJ_PutChunk(sji, SJ_CK_DATA, &ck);
	SJ_UngetChunk(sji, SJ_CK_FREE, &ck2);
	nbyte -= n1;
	SJ_GetChunk(sji, SJ_CK_FREE, nbyte, &ck);
	n2 = ck.len / blksz * blksz;
	memset(ck.data, 0, n2);
	SJ_SplitChunk(&ck, n2, &ck, &ck2);
	SJ_PutChunk(sji, SJ_CK_DATA, &ck);
	SJ_UngetChunk(sji, SJ_CK_FREE, &ck2);
	return (n1 + n2) / blksz * 32;
}

/* (dead-stripped) balance: -15..15, centred when the output is mono */
// FUN_004D5020
void ADXT_SetOutBalance(ADXT adxt, Sint32 bal)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080870 ADXT_SetOutBalance: parameter error");
		return;
	}
	if (bal < -15) {
		adxt->outbal = -15;
	} else if (bal > 15) {
		adxt->outbal = 15;
	} else {
		adxt->outbal = bal;
	}
	if (adxt_output_mono_flag == 0) {
		ADXRNA_SetOutBalance(adxt->rna, adxt->outbal);
	} else {
		ADXRNA_SetOutBalance(adxt->rna, -128);
	}
}

/* (dead-stripped) */
// FUN_004D50E0
Sint32 ADXT_GetOutBalance(ADXT adxt)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080871 ADXT_GetOutBalance: parameter error");
		return 0;
	}
	return adxt->outbal;
}

/* mono output switch: every live handle's pan and balance are re-applied */
// FUN_004D6B10
void ADXT_SetOutputMono(Sint32 flag)
{
	Sint32 i;
	Sint32 ch;
	ADXT adxt;

	adxt_output_mono_flag = flag;
	for (i = 0; i < ADXT_MAX_OBJ; i++) {
		adxt = &adxt_obj[i];
		if (adxt->used == 1) {
			for (ch = 0; ch < adxt->maxnch; ch++) {
				ADXT_SetOutPan(adxt, ch, ADXT_GetOutPan(adxt, ch));
			}
			ADXT_SetOutBalance(adxt, ADXT_GetOutBalance(adxt));
		}
	}
}

/* (dead-stripped) */
// FUN_004D6808
void ADXT_SetKeyString(ADXT adxt, Char8 *str)
{
	if (adxt == NULL) {
		ADXERR_CallErrFunc1("E02080860 ADXT_SetKeyString: parameter error");
		return;
	}
	ADXSJD_SetKeyString(adxt->sjd, str);
}
