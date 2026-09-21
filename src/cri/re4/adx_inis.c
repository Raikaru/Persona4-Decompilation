/* CRI ADXT library init / finish (adx_inis.c, ADXT/GC Ver.9.31): ADXT_Init brings up every ADX module
 * (stream joints, error, ADXSTM, ADXSJD, ADXF, renderer, LSC, SVM) and registers the server callbacks
 * with the SVM; ADXT_Finish undoes it. Holds the handle table adxt_obj, the build string and the
 * server ids. In this game the threads were never set up, so the single main callback
 * adxt_exec_main_nothrd runs everything from ADXM_ExecMain(). */
#include "cri_xpt.h"
#include "adx_t.h"
#include "adx_stm.h"
#include "lsc.h"
#include <string.h>

extern void ADXCRS_Init(void);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXERR_Init(void);
extern void ADXERR_Finish(void);
extern void ADXERR_CallErrFunc1(Char8 *msg);
extern void ADXSJD_Init(void);
extern void ADXSJD_Finish(void);
extern void ADXF_Init(void);
extern void ADXF_Finish(void);
extern void ADXRNA_Init(void);
extern void ADXRNA_Finish(void);
extern void ADXRNA_EntryErrFunc(void (*func)(void *obj, Char8 *msg), void *obj);
extern void SVM_Init(void);
extern void SVM_Finish(void);
extern Sint32 SVM_SetCbSvr(Sint32 kind, Sint32 (*func)(void *obj), void *obj);
extern void SVM_SetCbSvrId(Sint32 kind, Sint32 id, Sint32 (*func)(void *obj), void *obj);
extern void SVM_DelCbSvr(Sint32 kind, Sint32 id);
extern void SJUNI_Init(void);
extern void SJUNI_Finish(void);
extern void SJRBF_Init(void);
extern void SJRBF_Finish(void);
extern void SJMEM_Init(void);
extern void SJMEM_Finish(void);
extern Sint32 ADXM_IsSetupThrd(void);

Sint32 adxt_exec_fssvr(void *obj);
Sint32 adxt_exec_tsvr(void *obj);
Sint32 adxt_exec_main_nothrd(void *obj);
Sint32 adxt_exec_main_thrd(void *obj);
void adxini_lscerr_cbfn(void *obj, Char8 *msg);
static void adxini_rnaerr_cbfn(void *obj, Char8 *msg);

const Char8 adxt_build[] = "\nADXT/GC Ver.9.31 Build:Oct  8 2004 13:33:06\n\0Append: MW2407 GC20Apr2004Patch1\n";

Sint32 adxt_vsync_svr_flag = 1;

Sint32 adxt_init_cnt = 0;
static Sint32 adxt_svr_id = 0;
Sint32 adxt_svr_main_id = 0;
Sint32 adxt_output_mono_flag = 0;
Sint32 adxt_svr_fs_id = 0;
Sint32 adxt_vsync_cnt = 0;
ADXT_OBJ adxt_obj[ADXT_MAX_OBJ];
const Char8 *cri_verstr_ptr;

// Library shutdown (reference counted): destroys the handles, shuts down the renderer, file system,
// stream controller, scheduler, removes the server callbacks from the SVM and finishes the SVM,
// decoder, error and stream-joint modules.
void ADXT_Finish(void)
{
	if (--adxt_init_cnt == 0) {
		ADXT_DestroyAll();
		ADXRNA_Finish();
		ADXF_Finish();
		ADXSTM_Finish();
		LSC_Finish();
		ADXCRS_Lock();
		SVM_DelCbSvr(2, 1);
		SVM_DelCbSvr(4, adxt_svr_fs_id);
		SVM_DelCbSvr(5, adxt_svr_main_id);
		SVM_Finish();
		ADXSJD_Finish();
		ADXERR_Finish();
		SJMEM_Finish();
		SJRBF_Finish();
		SJUNI_Finish();
		ADXCRS_Unlock();
	}
}

/* dead-stripped by the linker; puts adxt_obj before cri_verstr_ptr in .bss */
ADXT ADXT_GetObj(Sint32 no)
{
	return &adxt_obj[no];
}

// Library init (reference counted): brings up the stream joints, error module, ADXSTM, ADXSJD, ADXF,
// renderer, LSC and SVM, and registers the server callbacks. Without ADXM_SetupThrd (dead-stripped in
// this game) every server (talk, file system, scheduler) runs from adxt_exec_main_nothrd on the SVM
// main type, i.e. from the game's ADXM_ExecMain() call each frame. Default server rate 60 Hz.
void ADXT_Init(void)
{
	cri_verstr_ptr = adxt_build;
	if (adxt_init_cnt == 0) {
		ADXCRS_Init();
		ADXCRS_Lock();
		SJUNI_Init();
		SJRBF_Init();
		SJMEM_Init();
		ADXERR_Init();
		ADXSTM_Init();
		ADXSJD_Init();
		ADXF_Init();
		ADXRNA_Init();
		LSC_Init();
		SVM_Init();
		ADXRNA_EntryErrFunc(adxini_rnaerr_cbfn, NULL);
		LSC_EntryErrFunc(adxini_lscerr_cbfn, NULL);
		memset(adxt_obj, 0, sizeof(adxt_obj));
		if (ADXM_IsSetupThrd() == 1 && adxt_vsync_svr_flag == 1) {
			SVM_SetCbSvrId(2, 1, adxt_exec_tsvr, NULL);
			adxt_svr_fs_id = SVM_SetCbSvr(4, adxt_exec_fssvr, NULL);
			adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_thrd, NULL);
		} else {
			adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_nothrd, NULL);
		}
		adxt_vsync_cnt = 0;
		adxt_output_mono_flag = 0;
		ADXT_SetDefSvrFreq(60);
		ADXCRS_Unlock();
	}
	adxt_init_cnt++;
}

// SVM callback (type 4, file system): one ADXT_ExecFsSvr pass.
Sint32 adxt_exec_fssvr(void *obj)
{
	ADXT_ExecFsSvr();
	return 0;
}

// SVM callback (type 2, vsync): one ADXT_ExecServer pass (threaded setup only).
Sint32 adxt_exec_tsvr(void *obj)
{
	ADXT_ExecServer();
	return 0;
}

// SVM main callback used by this game: talk server, file-system server and load scheduler in one pass
// per ADXM_ExecMain().
Sint32 adxt_exec_main_nothrd(void *obj)
{
	ADXT_ExecServer();
	ADXT_ExecFsSvr();
	LSC_ExecServer();
	return 0;
}

// SVM main callback of the threaded setup: only the load scheduler runs on the main thread.
Sint32 adxt_exec_main_thrd(void *obj)
{
	LSC_ExecServer();
	return 0;
}

// Forwards load scheduler error messages to the ADX error callback.
void adxini_lscerr_cbfn(void *obj, Char8 *msg)
{
	ADXERR_CallErrFunc1(msg);
}

// Forwards renderer error messages to the ADX error callback.
static void adxini_rnaerr_cbfn(void *obj, Char8 *msg)
{
	ADXERR_CallErrFunc1(msg);
}
