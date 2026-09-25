/* CRI ADX stream controller (adx_stmc.c, ADXSTM): keeps one file range flowing from the CVFS into a
 * ring-buffer stream joint. A controller is bound to a file (name, device, sector offset/count),
 * started, and then every file-server pass issues one asynchronous sector read when the ring is
 * below its refill level and publishes completed reads as DATA chunks. Bind/release/stop requests
 * are deferred to the server pass so the callers never block on the DVD; the blocking variants pump
 * ADXT_ExecFsSvr until the request has settled. 40 controllers: 16 real-time (ADXT streams), 24
 * normal (ADXF files). */
#include "cri_xpt.h"
#include "sj.h"
#include "adx_stm.h"
#include "adx_t.h"
#include <string.h>

// ADXSTM's private lock pair forwards to SVM but is a distinct retail call target.
extern void func_004d1880(void);
extern void func_004d1898(void);
extern Sint32 SVM_TestAndSet(Sint32 *flg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void func_004d18c8(void);
extern void func_004d18d0(void);
extern void ADXERR_CallErrFunc2(const Char8 *msg1, const Char8 *msg2);
extern void *cvFsOpen(const Char8 *fname, void *dir, void *prm);
extern void cvFsClose(void *fs);
extern Sint32 cvFsSeek(void *fs, Sint32 pos, Sint32 type);
extern Sint32 cvFsTell(void *fs);
extern Sint32 cvFsGetFileSize(const Char8 *fname);
extern Sint32 cvFsReqRd(void *fs, Sint32 nsct, void *buf);
extern Sint32 cvFsGetStat(void *fs);
extern void cvFsStopTr(void *fs);
extern void func_004c9d48(void);

#define ADXSTM_MAX_OBJ 40
#define ADXSTM_SCT_SHIFT 11
#define ADXSTM_SCT_SIZE 2048
#define ADXSTM_NSCT_INF 0xFFFFF
#define ADXSTM_MIN(a, b) ((a) < (b) ? (a) : (b))

/* cvFsGetStat results */
#define CVFS_STAT_COMPLETE 1
#define CVFS_STAT_ERROR 3

/* ADXSTM_OBJ is 0x60 (96) bytes; the 40-slot pool is 3840 bytes (0xF00, retail Init's `li a2,3840`
 * at 0x4D193C). 3840 % 0x48 != 0: the 0x48 stride seen nearby belongs to another struct, so do NOT
 * shrink this to 0x48. Retail ADXSTMF_SetupHandleMember (0x4D19A8, 264B) stores prove these offsets:
 * `sw s1,8(s3)` fp at 8, `sw s2,12(s3)` fofst at 0x0C, `sw a3,44(s3)` 0x200 at 0x2C (rd_lim),
 * `sw a2,92(s3)` 0xFFFFF at 0x5C (lim), `sw v1,48(s3)`+`sw v1,20(s3)` nsct at 0x30 (eos) and 0x14,
 * `sb 1,1` stat PREP, `sb 0,2` rd_flg, `sw s4,4` sj at 4, `sw s0,16` fsize at 0x10,
 * `sw 0,88` pos at 0x58 (when sj!=0), `sw s0,28/64/24` buf sizes at 0x1C/0x40/0x18, `sb 1,0` used,
 * `sb 0,68` x44 at 0x44. Do NOT change this struct. */
typedef struct ADXSTM_OBJ {
	Sint8 used;                /* 0x00 */
	Sint8 stat;                /* 0x01 */
	Sint8 rd_flg;              /* 0x02 read request outstanding */
	Sint8 rtry_cnt;            /* 0x03 */
	SJ sj;                     /* 0x04 */
	void *fs;                  /* 0x08 */
	Sint32 ofst;               /* 0x0C file offset (sectors) */
	Sint32 fsize;              /* 0x10 bytes */
	Sint32 nsct;               /* 0x14 */
	Sint32 rd_max;             /* 0x18 chunk request size */
	Sint32 rd_min;             /* 0x1C buffer level below which reads are issued */
	Sint32 rd_nsct;            /* 0x20 sectors of the outstanding request */
	SJCK ck;                   /* 0x24 */
	Sint32 rd_lim;             /* 0x2C sectors per request */
	Sint32 eos_nsct;           /* 0x30 */
	Sint32 rd_byte;            /* 0x34 total bytes read */
	void (*eos_func)(void *obj); /* 0x38 */
	void *eos_obj;             /* 0x3C */
	Sint32 buf_size;           /* 0x40 */
	Sint8 x44;                 /* 0x44 */
	Sint8 bind_req;            /* 0x45 */
	Sint8 release_req;         /* 0x46 */
	Sint8 start_req;           /* 0x47 */
	Sint8 stop_req;            /* 0x48 */
	Sint8 bound;               /* 0x49 */
	Sint8 rtim;                /* 0x4A */
	Uint8 pad4b;
	Sint32 x4c;
	const Char8 *fname;        /* 0x50 */
	void *dir;                 /* 0x54 */
	Sint32 pos;                /* 0x58 */
	Uint32 lim_nsct;           /* 0x5C */
} ADXSTM_OBJ;

static Sint32 adxstm_init_cnt = 0;
static Sint32 adxstmf_rtim_ofst = 0;
static Sint32 adxstmf_rtim_num = 16;
static Sint32 adxstmf_nrml_ofst = 16;
static Sint32 adxstmf_nrml_num = 24;
Sint32 adxstmf_execsvr_flg = 0;
Sint32 adxstmf_num_rtry = 0;
static Sint32 adxstm_sj_internal_error_cnt = 0;
ADXSTM_OBJ adxstmf_obj[ADXSTM_MAX_OBJ];

void ADXSTMF_ExecHndl(ADXSTM stm);
void adxstmf_stat_exec(ADXSTM stm);

// Sets the read policy in bytes: issue a read when less than `min_nsct` bytes are buffered, and ask
// the stream joint for at most `max_nsct` bytes per request (ADXT passes sectors << 11).
Sint32 ADXSTM_SetBufSize(ADXSTM stm, Sint32 min_nsct, Sint32 max_nsct)
{
	stm->rd_min = min_nsct;
	stm->rd_max = max_nsct;
	return 1;
}

// File-server pass: runs ADXSTMF_ExecHndl on every live controller; a test-and-set flag rejects
// re-entry. Called twice per ADXT_ExecFsSvr.
void ADXSTM_ExecServer(void)
{
	Sint32 i;
	ADXSTM stm;

	if (SVM_TestAndSet(&adxstmf_execsvr_flg) == 0) {
		return;
	}
	for (i = 0; i < ADXSTM_MAX_OBJ; i++) {
		stm = &adxstmf_obj[i];
		if (stm->used == 1) {
			ADXSTMF_ExecHndl(stm);
		}
	}
	adxstmf_execsvr_flg = 0;
}

// Per-controller step of the deferred (no-wait) requests once no read is in flight: stop_req ->
// PREP, release_req -> cvFsClose, bind_req -> cvFsOpen the bound file, measure it (whole file when
// the range was "infinite", clamp ofst/nsct to the file) and rewind; then, in EXEC and bound, run the
// reading state (adxstmf_stat_exec).
void ADXSTMF_ExecHndl(ADXSTM stm)
{
	void *fs;
	Sint32 fnsct;
	Sint32 fsize;

	if (stm->rd_flg == 0) {
		if (stm->stop_req == 1) {
			stm->stop_req = 0;
			if (stm->start_req == 0) {
				stm->stat = ADXSTM_STAT_PREP;
			}
		}
		if (stm->release_req == 1) {
			/* retail 0x4D2894-0x4D28A4: `lw a0,8(s0)`/`beql a0,zero` then `jal cvFsClose`
			 * with `sw zero,8(s0)` in the delay slot (close before clear). Direct
			 * `stm->fs` use keeps `a0` (no `move a0,v0` temp). */
			if (stm->fs != NULL) {
				cvFsClose(stm->fs);
				stm->fs = NULL;
			}
			stm->release_req = 0;
			stm->bound = 0;
		}
		func_004d1880();
		if (stm->bind_req == 1) {
			stm->bound = 1;
			func_004d1898();
			if (stm->fs == NULL) {
				fs = cvFsOpen(stm->fname, stm->dir, NULL);
				stm->fs = fs;
				if (fs == NULL) {
					ADXERR_CallErrFunc2("E02110501 adxstmf_stat_exec: can't open ", stm->fname);
					stm->stat = ADXSTM_STAT_ERROR;
					stm->bound = 0;
					stm->bind_req = 0;
					return;
				}
				cvFsSeek(stm->fs, 0, 2);
				fnsct = cvFsTell(stm->fs);
				if (stm->dir == NULL) {
					fsize = cvFsGetFileSize(stm->fname);
				} else {
					fsize = fnsct << ADXSTM_SCT_SHIFT;
				}
				cvFsSeek(stm->fs, 0, 0);
				if (stm->fsize == (ADXSTM_NSCT_INF << ADXSTM_SCT_SHIFT)) {
					stm->fsize = fsize;
					stm->nsct = fnsct;
				}
				if (stm->ofst > fnsct) {
					stm->ofst = fnsct;
				}
				if (stm->nsct + stm->ofst > fnsct) {
					stm->nsct = fnsct - stm->ofst;
					stm->fsize = stm->nsct << ADXSTM_SCT_SHIFT;
				}
				/* retail 0x4D29B4-0x4D29BC: `jal 0x4D2038` (Seek wrapper) with
				 * `move a1,zero` in the delay slot instead of the 7-instr
				 * `pos=0; if (pos>nsct) pos=nsct` movn sequence. Jal target is
				 * linker-owned and masked. */
				ADXSTM_Seek(stm, 0);
				stm->bind_req = 0;
			}
		} else {
			func_004d1898();
		}
		if (stm->start_req == 1) {
			stm->start_req = 0;
		}
	}
	if (stm->stat == ADXSTM_STAT_EXEC && stm->bound == 1) {
		adxstmf_stat_exec(stm);
	}
}

// A failed CVFS read: counts a retry up to adxstmf_num_rtry (0 here, so the first failure goes to
// ADXSTM_STAT_ERROR).
static void adxstmf_retry(ADXSTM stm)
{
	if (adxstmf_num_rtry >= 0) {
		if (stm->rtry_cnt >= adxstmf_num_rtry) {
			stm->stat = ADXSTM_STAT_ERROR;
		} else {
			stm->rtry_cnt++;
		}
	}
}

// The reading state: if a request is outstanding, on CVFS completion publish the sectors read as DATA
// in the stream joint, advance pos, fire the end-of-stream callback at eos_nsct and go to END at the
// range end or the read limit; on CVFS error give the chunk back and retry. Otherwise, when the ring
// holds less than rd_min bytes, take a FREE chunk (<= rd_max), clamp to eos/range/rd_lim (0x200
// sectors) and issue cvFsReqRd at ofst + pos.
void adxstmf_stat_exec(ADXSTM stm)
{
	SJ sj;
	Sint32 fstat;
	Sint32 nbyte;
	Sint32 nsct;
	Sint32 rd;
	Sint32 n;
	SJCK ck1;
	SJCK ck2;
	SJCK ck;

	sj = stm->sj;
	fstat = cvFsGetStat(stm->fs);
	func_004d1880();
	if (stm->rd_flg == 1) {
		if (fstat == CVFS_STAT_COMPLETE) {
			stm->rd_flg = 0;
			func_004d1898();
			nbyte = stm->rd_nsct << ADXSTM_SCT_SHIFT;
			SJ_SplitChunk(&stm->ck, nbyte, &ck1, &ck2);
			SJ_PutChunk(sj, SJ_CK_DATA, &ck1);
			SJ_UngetChunk(sj, SJ_CK_FREE, &ck2);
			stm->pos += stm->rd_nsct;
			stm->rd_byte += nbyte;
			stm->ck.data = NULL;
			stm->ck.len = 0;
			nsct = stm->nsct;
			if (stm->pos == stm->eos_nsct && stm->eos_func != NULL) {
				stm->eos_func(stm->eos_obj);
			}
			if (stm->pos >= nsct) {
				stm->stat = ADXSTM_STAT_END;
			} else if ((Uint32)stm->rd_byte >> ADXSTM_SCT_SHIFT >= stm->lim_nsct &&
				   stm->lim_nsct < ADXSTM_NSCT_INF) {
				stm->stat = ADXSTM_STAT_END;
			}
			stm->rtry_cnt = 0;
		} else if (fstat == CVFS_STAT_ERROR) {
			stm->rd_flg = 0;
			func_004d1898();
			SJ_UngetChunk(sj, SJ_CK_FREE, &stm->ck);
			stm->ck.data = NULL;
			stm->ck.len = 0;
			adxstmf_retry(stm);
		} else {
			func_004d1898();
		}
		return;
	}
	stm->rd_flg = 1;
	stm->ck.data = NULL;
	stm->ck.len = 0;
	func_004d1898();
	if (stm->x44 == 1 || stm->stop_req == 1) {
		stm->rd_flg = 0;
		return;
	}
	if (stm->nsct == 0) {
		stm->rd_flg = 0;
		stm->rd_nsct = 0;
		stm->stat = ADXSTM_STAT_END;
		return;
	}
	if (sj == NULL || sj->vtbl == NULL) {
		stm->rd_flg = 0;
		adxstm_sj_internal_error_cnt++;
		return;
	}
	if (stm->buf_size - SJ_GetNumData(sj, SJ_CK_FREE) >= stm->rd_min) {
		stm->rd_flg = 0;
		return;
	}
	SJ_GetChunk(sj, SJ_CK_FREE, stm->rd_max, &ck);
	n = ck.len / ADXSTM_SCT_SIZE;
	n = ADXSTM_MIN(n, stm->eos_nsct - stm->pos);
	n = ADXSTM_MIN(n, stm->nsct - stm->pos);
	rd = ADXSTM_MIN(n, stm->rd_lim);
	cvFsSeek(stm->fs, stm->ofst + stm->pos, 0);
	if (stm->lim_nsct != ADXSTM_NSCT_INF) {
		n = stm->lim_nsct - stm->rd_byte / ADXSTM_SCT_SIZE;
		if (rd < n) {
			n = rd;
		}
		rd = n;
	}
	stm->rd_nsct = cvFsReqRd(stm->fs, rd, ck.data);
	stm->ck.data = ck.data;
	stm->ck.len = ck.len;
	if (stm->rd_nsct <= 0) {
		SJ_UngetChunk(sj, SJ_CK_FREE, &stm->ck);
		stm->ck.data = NULL;
		stm->ck.len = 0;
		stm->rd_flg = 0;
		if (cvFsGetStat(stm->fs) == CVFS_STAT_ERROR) {
			adxstmf_retry(stm);
		}
	}
}

// Sector count at which eos_func fires (ADXT uses 25 sectors before the end to arm the loop/link
// trap); negative = the range end.
void ADXSTM_SetEos(ADXSTM stm, Sint32 nsct)
{
	if (nsct >= 0) {
		stm->eos_nsct = nsct;
	} else {
		stm->eos_nsct = stm->nsct;
	}
}

// Registers the end-of-stream callback (func(obj)).
void ADXSTM_EntryEosFunc(ADXSTM stm, void (*func)(void *obj), void *obj)
{
	stm->eos_func = func;
	stm->eos_obj = obj;
}

// Non-blocking stop: defers to the server if a read is in flight (stop_req), else PREP at once.
// FUN_004D2260
static void adxstm_stop_nw(ADXSTM stm)
{
	func_004d1880();
	if (stm->stat == ADXSTM_STAT_EXEC && stm->rd_flg == 1) {
		stm->stop_req = 1;
		if (stm->start_req == 1) {
			stm->start_req = 0;
		}
	} else {
		stm->stat = ADXSTM_STAT_PREP;
	}
	func_004d1898();
}

// Blocking stop: cancels the CVFS transfer, forces PREP and pumps ADXT_ExecFsSvr until the controller
// has settled with no chunk held.
static void adxstm_stop(ADXSTM stm)
{
	if (stm->fs != NULL && stm->release_req == 0) {
		cvFsStopTr(stm->fs);
	}
	func_004d1880();
	stm->stat = ADXSTM_STAT_PREP;
	stm->rd_flg = 0;
	stm->ck.data = NULL;
	func_004d1898();
	adxstm_stop_nw(stm);
	do {
		ADXT_ExecFsSvr();
	} while (stm->stat != ADXSTM_STAT_PREP || stm->ck.data != NULL);
}

// Non-blocking unbind: stop, then ask the server to close the CVFS file (release_req).
// FUN_004D1F30
static void adxstm_release_nw(ADXSTM stm)
{
	adxstm_stop_nw(stm);
	func_004d1880();
	if (stm->bound == 1) {
		stm->release_req = 1;
	}
	stm->bind_req = 0;
	func_004d1898();
}

// Blocking unbind: stop, request the release and pump the file server until `bound` clears.
// FUN_004D1FA0
static void adxstm_release(ADXSTM stm)
{
	adxstm_stop(stm);
	adxstm_release_nw(stm);
	for (;;) {
		if (stm->bound == 0) {
			break;
		}
		func_004c9d48();
	}
}

// Blocking stop (adxstm_stop).
// FUN_004D22C8
void ADXSTM_Stop(ADXSTM stm)
{
	func_004d18c8();
	adxstm_stop(stm);
	func_004d18d0();
}

// Non-blocking stop (adxstm_stop_nw).
// FUN_004D2230
void ADXSTM_StopNw(ADXSTM stm)
{
	func_004d18c8();
	adxstm_stop_nw(stm);
	func_004d18d0();
}

// Starts streaming the bound range: clears the byte/retry counters and the read limit, EXEC (or END
// for an empty range); the actual open happens in the next server pass.
Sint32 ADXSTM_Start(ADXSTM stm)
{
	ADXCRS_Lock();
	stm->rd_byte = 0;
	stm->rtry_cnt = 0;
	if (stm->nsct == 0) {
		stm->stat = ADXSTM_STAT_END;
	} else {
		stm->stat = ADXSTM_STAT_EXEC;
	}
	stm->rd_flg = 0;
	stm->ck.data = NULL;
	stm->ck.len = 0;
	stm->start_req = 1;
	stm->lim_nsct = ADXSTM_NSCT_INF;
	ADXCRS_Unlock();
	return 1;
}

// Current position in sectors from the range start (0 when no file is open).
Sint32 ADXSTM_Tell(ADXSTM stm)
{
	if (stm->fs != NULL) {
		return stm->pos;
	}
	return 0;
}

// Sets the position in sectors (clamped to the range length); the next read starts there.
Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 pos)
{
	stm->pos = pos;
	if (stm->pos > stm->nsct) {
		stm->pos = stm->nsct;
	}
	return stm->pos;
}

// ADXSTM_STAT_STOP/PREP/EXEC/END/ERROR.
Sint32 ADXSTM_GetStat(ADXSTM stm)
{
	return stm->stat;
}

// Blocking unbind of the file (adxstm_release).
// FUN_004D1F70
void ADXSTM_ReleaseFile(ADXSTM stm)
{
	func_004d18c8();
	adxstm_release(stm);
	func_004d18d0();
}

// Non-blocking unbind (adxstm_release_nw).
// FUN_004D1F00
void ADXSTM_ReleaseFileNw(ADXSTM stm)
{
	func_004d18c8();
	adxstm_release_nw(stm);
	func_004d18d0();
}

// Records the file to stream (`fname` on CVFS device `dir`, `ofst`/`nsct` in sectors; nsct 0xFFFFF =
// whole file) and asks the server to open it (bind_req). The inner worker at 0x4D1DE0 calls
// the private ADX stream lock adapter 0x4D1880 at 0x4D1E0C.
// FUN_004D1DE0
static void adxstm_BindFileNw(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
	func_004d1880();
	stm->ofst = ofst;
	stm->fsize = nsct << ADXSTM_SCT_SHIFT;
	stm->nsct = nsct;
	stm->fname = fname;
	stm->dir = dir;
	stm->bind_req = 1;
	func_004d1898();
}

// Public wrapper (retail 0x4D1D70, 112B): saves the 5 args across the outer lock
// (`move s4,t0` in the delay of `jal 0x4D18C8`, `move t0,s4` for the inner call, `j 0x4D18D0`
// tail). The decoded call targets distinguish the public bind locks from the private adapters.
// FUN_004D1D70
void ADXSTM_BindFileNw(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
	func_004d18c8();
	adxstm_BindFileNw(stm, fname, dir, ofst, nsct);
	func_004d18d0();
}

// Stops and unbinds the controller (blocking) and clears the slot.
// FUN_004D1D18
void ADXSTM_Destroy(ADXSTM stm)
{
	if (stm == NULL) {
		return;
	}
	adxstm_stop(stm);
	adxstm_release(stm);
	stm->used = 0;
	memset(stm, 0, sizeof(ADXSTM_OBJ));
}

// Takes a free slot in the given part of adxstmf_obj (real-time slots 0..15, normal 16..39): PREP,
// unbound, 0x200-sector request limit, read policy = the whole stream joint size.
static inline ADXSTM adxstmf_create(SJ sj, Sint32 ofst, Sint32 num, Sint32 rtim)
{
	ADXSTM stm = NULL;
	Sint32 i;

	for (i = 0; i < num; i++) {
		stm = (ADXSTM)((Uint8 *)adxstmf_obj + ofst * sizeof(ADXSTM_OBJ));
		if (stm->used == 0) {
			break;
		}
		ofst++;
	}
	if (i == num) {
		return NULL;
	}
	ADXCRS_Lock();
	stm->stat = ADXSTM_STAT_PREP;
	stm->rd_flg = 0;
	stm->sj = sj;
	stm->fs = NULL;
	stm->ofst = 0;
	stm->fsize = 0;
	stm->nsct = 0;
	stm->rd_lim = 0x200;
	stm->pos = 0;
	stm->lim_nsct = ADXSTM_NSCT_INF;
	stm->eos_nsct = stm->nsct;
	if (stm->sj != NULL) {
		stm->buf_size = SJ_GetNumData(sj, SJ_CK_FREE) + SJ_GetNumData(sj, SJ_CK_DATA);
		stm->rd_min = stm->rd_max = stm->buf_size;
	}
	stm->x44 = 0;
	stm->used = 1;
	ADXCRS_Unlock();
	stm->rtim = rtim;
	return stm;
}

// Creates a stream controller writing into `sj`; mode < 0x100 takes a real-time slot (ADXT), higher
// modes a normal slot. ADXF creates one with sj NULL and supplies the joint per read.
/* adxstmf_create's search: the byte-offset cast form `(Uint8 *)adxstmf_obj + ofst * sizeof(..)` with
 * `ofst++` after the test keeps the scaled index as the IV (stepped in the latch after the `beq`,
 * `add r31, base, ofs` per iteration); `&adxstmf_obj[ofst++]` steps before the load and
 * `&adxstmf_obj[ofst]; ...; ofst++` becomes a pointer IV. */
ADXSTM ADXSTM_Create(SJ sj, Sint32 mode)
{
	if (mode < 0x100) {
		return adxstmf_create(sj, adxstmf_rtim_ofst, adxstmf_rtim_num, 1);
	}
	return adxstmf_create(sj, adxstmf_nrml_ofst, adxstmf_nrml_num, 0);
}

// Nothing to release.
void ADXSTM_Finish(void)
{
}

// Clears the 40 controller slots on the first init (retail 0x4D1908: `lw v1,0(v0)`/`addiu v1,1`/
// `bne v1,a0` guard at 0x4D191C-0x4D1924 with `li a2,3840` at 0x4D193C).
// FUN_004D1908
Sint32 ADXSTM_Init(void)
{
	if (++adxstm_init_cnt == 1) {
		memset(adxstmf_obj, 0, sizeof(adxstmf_obj));
	}
	return 1;
}
