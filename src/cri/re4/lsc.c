/* CRI LSC load scheduler (lsc.c, LSC): queues up to 16 file ranges on one ADX stream controller
 * so several files stream back to back into one ring buffer (ADXT mode 4 "scheduled" playback, the
 * base of linked/gapless file playback). Entries are consumed in order by lsc_ExecHndl (lsc_svr.c);
 * the handle table is in lsc_ini.c. Created for every ADXT handle but only driven in mode 4. */
#include "cri_xpt.h"
#include "lsc.h"
#include <string.h>

void (*lsc_stat_func)(void *obj1, void *obj2);
void *lsc_stat_obj1;
void *lsc_stat_obj2;

// Calls the optional status callback when a scheduler's queue runs empty (none installed here).
void LSC_CallStatFunc(void)
{
	if (lsc_stat_func != NULL) {
		lsc_stat_func(lsc_stat_obj1, lsc_stat_obj2);
	}
}

/* dead-stripped by the linker */
void LSC_EntryStatFunc(void (*func)(void *obj1, void *obj2), void *obj1, void *obj2)
{
	lsc_stat_func = func;
	lsc_stat_obj1 = obj1;
	lsc_stat_obj2 = obj2;
}

// Refill threshold in bytes for the stream controller (default 80% of the stream joint size).
void LSC_SetFlowLimit(LSC lsc, Sint32 min_val)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return;
	}
	if (min_val < 0 || min_val > lsc->bufsize) {
		LSC_CallErrFunc("E0010: Illigal parameter min_val=%d\n", min_val);
		return;
	}
	lsc->min_val = min_val;
}

// Entries still queued (including the one loading).
Sint32 LSC_GetNumStm(LSC lsc)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return -3;
	}
	return lsc->num_stm;
}

// LSC_STAT_STOP 0, PREP 1 (idle, queue empty), EXEC 2, ERROR 3 (ADXT maps 3 to its own error state).
Sint32 LSC_GetStat(LSC lsc)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return -3;
	}
	return lsc->stat;
}

/* dead-stripped by the linker */
Sint32 LSC_GetStmStat(LSC lsc, Sint32 id)
{
	Sint32 i;

	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return -3;
	}
	for (i = 0; i < LSC_MAX_ENTRY; i++) {
		if (lsc->tbl[i].id == id) {
			return lsc->tbl[i].stat;
		}
	}
	LSC_CallErrFunc("E0012: Can not find stream ID =%d\n", id);
	return -1;
}

/* dead-stripped by the linker */
Sint32 LSC_GetStmPos(LSC lsc, Sint32 no)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return -3;
	}
	if (no < 0 || no >= LSC_MAX_ENTRY) {
		LSC_CallErrFunc("E0009: Illigal parameter no=%d\n", no);
		return -1;
	}
	return lsc->tbl[(lsc->rd_idx + no) % LSC_MAX_ENTRY].pos;
}

// Scheduler server pass (from the SVM main callback): lsc_ExecHndl on every live scheduler, under
// the stream-joint lock.
void LSC_ExecServer(void)
{
	Sint32 msk;
	LSC_OBJ *lsc;
	Sint32 i;

	LSC_LockCrs(&msk);
	for (i = 0; i < LSC_MAX_OBJ; i++) {
		lsc = &lsc_obj[i];
		if (lsc->used == 1) {
			lsc_ExecHndl(lsc);
		}
	}
	LSC_UnlockCrs(&msk);
}

// Empties the queue of a stopped scheduler.
// FUN_004E9250
static void lsc_ClearEntry(LSC lsc)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return;
	}
	if (lsc->stat == LSC_STAT_STOP) {
		lsc->wr_idx = 0;
		lsc->rd_idx = 0;
		lsc->num_stm = 0;
	}
}

// Stops the stream controller if this scheduler started it, clears the queue, state STOP.
void LSC_Stop(LSC lsc)
{
	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return;
	}
	if (lsc->stat == LSC_STAT_STOP) {
		return;
	}
	lsc->stat = LSC_STAT_STOP;
	if (lsc->stm != NULL && lsc->stm_start == 1) {
		ADXSTM_Stop(lsc->stm);
		lsc->stm_start = 0;
	}
	lsc->cur_nsct = 0;
	lsc_ClearEntry(lsc);
	lsc->pad34 = 0;
}

// The queue slot the next LSC_EntryFileRange fills.
static LSC_ENTRY *lsc_GetWrEntry(LSC lsc)
{
	return &lsc->tbl[lsc->wr_idx];
}

// Queues a file range (name, CVFS device, sector offset/count) to be streamed after the previous
// entries, giving it the next id (0..0x7FFFFFFF, wrapping); the file name is checksummed so a
// changed string is detected at load time. PREP -> EXEC. -1 when the 16-entry queue is full.
Sint32 LSC_EntryFileRange(LSC lsc, Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
	LSC_ENTRY *ent;
	Sint32 id;
	Uint32 len;
	Sint32 i;

	if (lsc == NULL) {
		LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
		return -3;
	}
	if (lsc->num_stm >= LSC_MAX_ENTRY) {
		return -1;
	}
	if (fname == NULL) {
		LSC_CallErrFunc("E0011: Illigal parameter fname=%s\n", fname);
		return -1;
	}
	id = lsc->tbl[(lsc->wr_idx + LSC_MAX_ENTRY - 1) % LSC_MAX_ENTRY].id;
	ent = lsc_GetWrEntry(lsc);
	id = (id == LSC_ID_MAX) ? 0 : id + 1;
	ent->id = id;
	ent->fname = fname;
	len = strlen(fname);
	ent->fname_sum = 0;
	for (i = 0; i < len; i++) {
		ent->fname_sum += (Uint8)fname[i];
	}
	ent->ofst = ofst;
	ent->nsct = nsct;
	ent->dir = dir;
	ent->stat = LSC_ENT_WAIT;
	ent->pos = 0;
	lsc->num_stm++;
	lsc->wr_idx = (lsc->wr_idx + 1) % LSC_MAX_ENTRY;
	if (lsc->stat == LSC_STAT_PREP) {
		lsc->stat = LSC_STAT_EXEC;
	}
	return id;
}

// The ADXSTM controller the scheduler drives (ADXT hands over its own stream controller for mode 4
// scheduled playback).
void LSC_SetStmHndl(LSC lsc, ADXSTM stm)
{
	lsc->stm = stm;
}

// Stops and clears the scheduler.
// FUN_004E9038
void LSC_Destroy(LSC lsc)
{
	if (lsc == NULL) {
		return;
	}
	LSC_Stop(lsc);
	lsc->used = 0;
	memset(lsc, 0, sizeof(LSC_OBJ));
}

// First unused of the 32 schedulers, NULL when none.
// FUN_004E8ED0
static LSC lsc_SearchFreeObj(void)
{
	LSC lsc;
	Sint32 i;

	lsc = NULL;
	for (i = 0; i < LSC_MAX_OBJ; i++) {
		if (lsc_obj[i].used == 0) {
			lsc = &lsc_obj[i];
			break;
		}
	}
	return lsc;
}

// Creates a scheduler feeding stream joint `sj`: the refill threshold is 80% of the joint size, the
// queue is empty, state STOP. ADXT_Create makes one per handle.
// FUN_004E8F30
LSC LSC_Create(SJ sj)
{
	Sint32 msk;
	LSC_OBJ *lsc;
	Sint32 i;

	if (sj == NULL) {
		LSC_CallErrFunc("E0001: Illigal parameter=sj (LSC_Create)\n");
		return NULL;
	}
	LSC_LockCrs(&msk);
	lsc = lsc_SearchFreeObj();
	if (lsc == NULL) {
		LSC_CallErrFunc("E0002: Not enough instance (LSC_Create)\n");
	} else {
		lsc->sj = sj;
		lsc->stat = LSC_STAT_STOP;
		lsc->bufsize = SJ_GetNumData(sj, 0) + SJ_GetNumData(sj, 1);
		lsc->min_val = lsc->bufsize * 8 / 10;
		for (i = 0; i < LSC_MAX_ENTRY; i++) {
			lsc->tbl[i].stat = LSC_ENT_WAIT;
		}
		lsc->used = 1;
	}
	LSC_UnlockCrs(&msk);
	return lsc;
}
