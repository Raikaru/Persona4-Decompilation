/* CRI ADXT file-system server (adx_fsvr.c): one pass of the data-loading side of the pipeline (CVFS
 * device servers, ADX stream controllers, ADX file handles). Called from the SVM main callback
 * (adxt_exec_main_nothrd) once per game frame; the phase counter adxt_fssvr_enter_cnt rejects
 * re-entry from a callback. */
#include "cri_xpt.h"

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void cvFsExecServer(void);
extern void ADXSTM_ExecServer(void);
extern void ADXF_ExecServer(void);

Sint32 adxt_fssvr_enter_cnt;
Sint32 adxt_fssvr_exec_cnt;

// Runs the CVFS server (DVD reads), the stream controllers (refill the ring buffers), the file handles
// and the stream controllers/CVFS again, recording the phase in adxt_fssvr_enter_cnt.
void ADXT_ExecFsSvr(void)
{
	ADXCRS_Lock();
	if (adxt_fssvr_enter_cnt != 0) {
		ADXCRS_Unlock();
		return;
	}
	adxt_fssvr_enter_cnt = 1;
	ADXCRS_Unlock();
	adxt_fssvr_enter_cnt = 3;
	cvFsExecServer();
	adxt_fssvr_enter_cnt = 4;
	ADXSTM_ExecServer();
	adxt_fssvr_enter_cnt = 5;
	ADXF_ExecServer();
	adxt_fssvr_enter_cnt = 6;
	ADXSTM_ExecServer();
	adxt_fssvr_enter_cnt = 7;
	cvFsExecServer();
	adxt_fssvr_enter_cnt = 0;
}
