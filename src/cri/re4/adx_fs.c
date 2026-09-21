/* ADX file system: file handles (open / read / stop / seek / close) on top of ADXSTM.
 * Compiled with `-inline auto,deferred` (CRI_CFLAG_OVERRIDES): the functions are emitted in reverse
 * source order and later-defined functions (ADXF_Stop) are inlined. Only ADXF_ExecServer,
 * ADXF_CloseAll and ADXF_Close survived the linker's dead-stripping; the other bodies reproduce the
 * error strings left in .rodata and the two statics in .bss (STRIP_UNUSED). */
#include "adx_f.h"
#include <string.h>

#define ADXF_SCT_SIZE 2048
#define ADXF_SEEK_SET 0
#define ADXF_SEEK_CUR 1
#define ADXF_SEEK_END 2

static void *adxf_ldpt_tmpbuf;
static Sint32 adxf_ldpt_tbsize;

// Debug trace: records command `cmd` (entry sub 0 / exit sub 1) with its call count, handle and two
// parameters in the 16-entry ring adxf_cmd_hstry.
static void adxf_SetCmdHstry(Sint32 cmd, Sint32 sub, ADXF adxf, Sint32 prm1, Sint32 prm2)
{
	ADXF_CMD_HSTRY *h;

	adxf_hstry_no %= ADXF_CMD_HSTRY_NUM;
	h = &adxf_cmd_hstry[adxf_hstry_no];
	if (sub == 0) {
		adxf_cmd_ncall[cmd]++;
	}
	h->cmd = cmd;
	h->sub = sub;
	h->ncall = adxf_cmd_ncall[cmd];
	h->adxf = adxf;
	h->prm1 = prm1;
	h->prm2 = prm2;
	adxf_hstry_no++;
}

/* release the stream joint of a finished read (after flushing the destination buffer) */
// FUN_004C89F0
static void adxf_ReleaseSj(ADXF adxf)
{
	SJ sj;

	if (adxf->sj != NULL && adxf->sjmode == 0) {
		if (adxf_ocbi_fg == 1) {
			ADXF_Ocbi(adxf->ocbi_buf, adxf->ocbi_len);
		}
		sj = adxf->sj;
		adxf->sj = NULL;
		SJ_Destroy(sj);
	}
}

// Validates an AFS partition id (0..255) and a non-NULL partition info pointer.
static Sint32 adxf_ChkPrmPt(Sint32 ptid, void *ptinfo)
{
	if (ptid < 0 || ptid >= ADXF_MAX_PTINFO) {
		ADXERR_CallErrFunc1("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
		return NG;
	}
	if (ptinfo == NULL) {
		ADXERR_CallErrFunc1("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
		return NG;
	}
	return OK;
}

// Dead: starts loading the AFS table of contents of `fname` into `ptinfo` for partition `ptid`
// (one at a time, through the temporary buffer set by ADXF_SetLdPtTmpBuf).
Sint32 ADXF_LoadPartitionNw(Sint32 ptid, const Char8 *fname, void *dir, void *ptinfo)
{
	ADXF adxf;

	if (adxf_ldptnw_hn != NULL) {
		ADXERR_CallErrFunc1("E20040917 : It is impossible to load AFS files in parallel.");
		return NG;
	}
	if (adxf_ldpt_tmpbuf == NULL) {
		ADXERR_CallErrFunc1("E1110701:'tmpbuf' is null.(load partition)");
		return NG;
	}
	if (adxf_ldpt_tbsize <= 0) {
		ADXERR_CallErrFunc1("E1110702:'tbsize' <= 0.(load partition)");
		return NG;
	}
	if (adxf_ChkPrmPt(ptid, ptinfo) == NG) {
		return NG;
	}
	if (adxf_ptinfo[ptid] != NULL) {
		ADXERR_CallErrFunc1("E0042401:multi-load partition.(load partition)");
		return NG;
	}
	adxf = ADXF_Open(fname, dir);
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040804:can't open file.(load partition)");
		return NG;
	}
	adxf_ptinfo[ptid] = ptinfo;
	adxf_ldptnw_hn = adxf;
	return OK;
}

// Dead: 1 when partition `ptid` has a valid loaded "AFS" table, 0 when nothing is loaded, NG on a
// malformed table (bad tag, no files, entry >= 128 MB).
Sint32 ADXF_GetPtStat(Sint32 ptid)
{
	ADXF_PTINFO *pt;

	if (ptid < 0 || ptid >= ADXF_MAX_PTINFO) {
		ADXERR_CallErrFunc1("E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
		return NG;
	}
	pt = adxf_ptinfo[ptid];
	if (pt == NULL) {
		return 0;
	}
	if (strncmp(pt->tag, "AFS", 3) != 0) {
		ADXERR_CallErrFunc1("E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
		return NG;
	}
	if (pt->nfile <= 0) {
		ADXERR_CallErrFunc1("E0040702:Illigal number of file.(ADXF_GetPtStat)");
		return NG;
	}
	if (pt->fl[0].ofst < 0) {
		ADXERR_CallErrFunc1("E2122501:AFS file has 128MB or more of inside file.(ADXF_GetPtStat)");
		return NG;
	}
	return 1;
}

// Dead: opens `fname` (CVFS device `dir`) for sector reads: a handle with its own ADXSTM bound to the
// whole file, state STOP.
ADXF ADXF_Open(const Char8 *fname, void *dir)
{
	ADXF adxf;

	if (fname == NULL) {
		ADXERR_CallErrFunc1("E9081901:illigal parameter fname=null.(ADXF_Open)");
		return NULL;
	}
	adxf = adxf_CreateAdxFs();
	if (adxf == NULL) {
		return NULL;
	}
	ADXSTM_BindFileNw(adxf->stm, fname, dir, 0, 0);
	adxf->stat = ADXF_STAT_STOP;
	return adxf;
}

// Takes a free adxf_obj slot and creates its ADXSTM controller (normal slot, no stream joint).
ADXF adxf_CreateAdxFs(void)
{
	ADXF adxf;
	Sint32 i;

	ADXCRS_Lock();
	for (i = 0; i < ADXF_MAX_OBJ; i++) {
		if (adxf_obj[i].used == 0) {
			break;
		}
	}
	if (i == ADXF_MAX_OBJ) {
		ADXCRS_Unlock();
		ADXERR_CallErrFunc1("E04041201:not enough ADXF handle (adxf_CreateAdxFs)");
		return NULL;
	}
	adxf = &adxf_obj[i];
	memset(adxf, 0, sizeof(ADXF_OBJ));
	adxf->used = 1;
	ADXCRS_Unlock();
	adxf->stm = ADXSTM_Create(NULL, 0);
	if (adxf->stm == NULL) {
		adxf->used = 0;
		ADXERR_CallErrFunc1("E02111001:can't create stm handle (adxf_CreateAdxFs)");
		return NULL;
	}
	return adxf;
}

// Stops a reading handle, unbinds and destroys its stream controller and clears the slot.
void ADXF_Close(ADXF adxf)
{
	ADXSTM stm;

	adxf_SetCmdHstry(ADXF_CMD_CLOSE, 0, adxf, -1, -1);
	if (adxf == NULL) {
		return;
	}
	if (adxf->stat == ADXF_STAT_READING) {
		ADXF_Stop(adxf);
	}
	if (adxf->stm != NULL) {
		adxf->used = 0;
		stm = adxf->stm;
		adxf->stm = NULL;
		ADXSTM_ReleaseFile(stm);
		ADXSTM_Destroy(stm);
	}
	memset(adxf, 0, sizeof(ADXF_OBJ));
	adxf_SetCmdHstry(ADXF_CMD_CLOSE, 1, adxf, -1, -1);
}

// Closes every open handle (ADXF_Finish).
// FUN_004C8B70
void ADXF_CloseAll(void)
{
	Sint32 i;
	ADXF adxf;

	for (i = 0; i < ADXF_MAX_OBJ; i++) {
		adxf = &adxf_obj[i];
		if (adxf->used == 1) {
			ADXF_Close(adxf);
		}
	}
}

// File-server pass: for reading handles copies the ADXSTM state (2 reading, 3 read end, 4 error) and
// the sectors read so far; at the end or on error advances ofst and releases the read's stream joint
// (flushing the destination buffer); completes a pending ADXF_StopNw once the controller is in PREP.
void ADXF_ExecServer(void)
{
	Sint32 i;
	ADXF adxf;

	ADXCRS_Lock();
	for (i = 0; i < ADXF_MAX_OBJ; i++) {
		adxf = &adxf_obj[i];
		if (adxf->used != 1) {
			continue;
		}
		if (adxf->stat == ADXF_STAT_READING) {
			adxf->stat = ADXSTM_GetStat(adxf->stm);
			adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->ofst;
			if (adxf->stat == ADXF_STAT_READEND || adxf->stat == ADXF_STAT_ERROR) {
				adxf->ofst += adxf->rdsct;
				adxf_ReleaseSj(adxf);
			}
		}
		if (adxf->stopnw_flg == 1) {
			if (ADXSTM_GetStat(adxf->stm) == ADXSTM_STAT_PREP) {
				adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->ofst;
				adxf_ReleaseSj(adxf);
				adxf->stat = ADXF_STAT_STOP;
				adxf->stopnw_flg = 0;
			}
		}
	}
	ADXCRS_Unlock();
}

// Dead: asynchronous read of `nsct` sectors into a caller-owned stream joint.
Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
		return NG;
	}
	if (nsct < 0) {
		ADXERR_CallErrFunc1("E9040812:'nsct'is negative.(ADXF_ReadSj32)");
		return NG;
	}
	if (sj == NULL) {
		ADXERR_CallErrFunc1("E9040813:'sj'is NULL.(ADXF_ReadSj32)");
		return NG;
	}
	adxf->sj = sj;
	adxf->sjmode = 1;
	adxf->rqsct = nsct;
	adxf->rdsct = 0;
	adxf->stat = ADXF_STAT_READING;
	return nsct;
}

// Dead: asynchronous read of `nsct` sectors into `buf` (32-byte aligned); the buffer range is
// invalidated from the cache when the read completes.
Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
		return NG;
	}
	if (nsct < 0) {
		ADXERR_CallErrFunc1("E9040817:'nsct' is negative.(ADXF_ReadNw32)");
		return NG;
	}
	if (buf == NULL) {
		ADXERR_CallErrFunc1("E9040818:'buf' is NULL.(ADXF_ReadNw32)");
		return NG;
	}
	if (adxf->sj != NULL) {
		ADXERR_CallErrFunc1("E9040821:'sj' must be NULL.(ADXF_ReadNw32)");
		return NG;
	}
	adxf->ocbi_buf = buf;
	adxf->ocbi_len = nsct * ADXF_SCT_SIZE;
	adxf->sjmode = 0;
	adxf->rqsct = nsct;
	adxf->rdsct = 0;
	adxf->stat = ADXF_STAT_READING;
	return nsct;
}

// Dead: ADXF_ReadNw32 with an alignment check on `buf`.
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf)
{
	if (((Uint32)buf & 31) != 0) {
		ADXERR_CallErrFunc1("E0120401:'buf' isn't 32byte alignment.(ADXF_ReadNw)");
		return NG;
	}
	return ADXF_ReadNw32(adxf, nsct, buf);
}

// Dead: non-blocking stop of a read; ADXF_ExecServer finishes it.
void ADXF_StopNw(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E2092301:'adxf' is NULL.(ADXF_StopNw)");
		return;
	}
	if (adxf->stat != ADXF_STAT_READING) {
		return;
	}
	if (adxf->stm == NULL) {
		ADXERR_CallErrFunc1("E2092302:'adxf->stm' is NULL.(ADXF_StopNw)");
		return;
	}
	ADXSTM_StopNw(adxf->stm);
	adxf->stopnw_flg = 1;
}

// Dead: blocking stop of a read; records the sectors read and releases the stream joint.
void ADXF_Stop(ADXF adxf)
{
	adxf_SetCmdHstry(ADXF_CMD_STOP, 0, adxf, -1, -1);
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040822:'adxf' is NULL.(ADXF_Stop)");
		return;
	}
	if (adxf->stat == ADXF_STAT_STOP) {
		return;
	}
	if (adxf->stat == ADXF_STAT_READEND) {
		adxf->stat = ADXF_STAT_STOP;
		return;
	}
	if (adxf->stm == NULL) {
		ADXERR_CallErrFunc1("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
		return;
	}
	ADXSTM_Stop(adxf->stm);
	ADXCRS_Lock();
	adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->ofst;
	adxf_ReleaseSj(adxf);
	adxf->stat = ADXF_STAT_STOP;
	ADXCRS_Unlock();
	adxf_SetCmdHstry(ADXF_CMD_STOP, 1, adxf, -1, -1);
}

// Dead: sets the read position in sectors (SET/CUR/END), stopping any read first.
Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type)
{
	Sint32 ofst;

	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040825:'adxf' is NULL.(ADXF_Seek)");
		return NG;
	}
	ADXF_Stop(adxf);
	switch (type) {
	case ADXF_SEEK_SET:
		ofst = pos;
		break;
	case ADXF_SEEK_CUR:
		ofst = adxf->ofst + pos;
		break;
	case ADXF_SEEK_END:
		ofst = adxf->fnsct + pos;
		break;
	default:
		ADXERR_CallErrFunc1("E9040826:'type' is illigal.(ADXF_Seek)");
		return NG;
	}
	if (ofst < 0) {
		ofst = 0;
	}
	if (ofst > adxf->fnsct) {
		ofst = adxf->fnsct;
	}
	adxf->ofst = ofst;
	ADXSTM_Seek(adxf->stm, ofst);
	return ofst;
}

// Dead: current position in sectors.
Sint32 ADXF_Tell(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040827:'adxf' is NULL.(ADXF_Tell)");
		return NG;
	}
	return adxf->ofst;
}

// Dead: file size in sectors.
Sint32 ADXF_GetFsizeSct(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
		return NG;
	}
	return adxf->fnsct;
}

// Dead: sectors requested by the current read.
Sint32 ADXF_GetNumReqSct(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040830:'adxf' is NULL.(ADXF_GetNumReqSct)");
		return NG;
	}
	return adxf->rqsct;
}

// Dead: sectors read so far by the current read.
Sint32 ADXF_GetNumReadSct(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040831:'adxf' is NULL.(ADXF_GetNumReadSct)");
		return NG;
	}
	return adxf->rdsct;
}

// Dead: handle state (ADXF_STAT_STOP 1, READING 2, READEND 3, ERROR 4).
Sint32 ADXF_GetStat(ADXF adxf)
{
	if (adxf == NULL) {
		ADXERR_CallErrFunc1("E9040832:'adxf' is NULL.(ADXF_GetStat)");
		return NG;
	}
	return adxf->stat;
}

// Dead: size in sectors of file `flid` inside AFS partition `ptid`.
Sint32 ADXF_GetFsizeSctAfs(Sint32 ptid, Sint32 flid)
{
	ADXF_PTINFO *pt;

	if (ptid < 0 || ptid >= ADXF_MAX_PTINFO) {
		ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
		return NG;
	}
	pt = adxf_ptinfo[ptid];
	if (flid < 0 || flid >= pt->nfile) {
		ADXERR_CallErrFunc1("E9040828:'flid' is range outside.");
		return NG;
	}
	return (pt->fl[flid].fnbyte + ADXF_SCT_SIZE - 1) / ADXF_SCT_SIZE;
}

// Dead: presets the request size for the next read (rejected while reading).
void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct)
{
	if (adxf->stat == ADXF_STAT_READING) {
		ADXERR_CallErrFunc1("E0041201:state is reading(ADXF_SetReqRdSct)");
		return;
	}
	adxf->rqsct = nsct;
}
