/* CRI Sofdec MW player server-manager glue (mwsfdsvm.c): registers the player's servers with the
 * SVM (main type 5, idle type 6, vsync type 2) and routes the player's error messages
 * (MWSFSVM_Error) to the SVM error callback. */
#include "cri_xpt.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

extern void SVM_Init(void);
extern void SVM_GotoSvrBorder(Sint32 kind);
extern Sint32 SVM_TestAndSet(Sint32 *flag);
extern Sint32 SVM_SetCbSvr(Sint32 kind, Sint32 (*func)(void *obj), void *obj);
extern void SVM_SetCbSvrId(Sint32 kind, Sint32 id, Sint32 (*func)(void *obj), void *obj);
extern void SVM_CallErr1(Char8 *msg);

Sint32 mwg_main_fid;
Sint32 mwg_idle_fid;
Sint32 mwg_vsync_fid;
Sint32 mwg_vbin_fid;

// Waits for the idle-type server border (SVM type 6; a no-op without threads).
// FUN_004CD130
void MWSFSVM_GotoIdleBorder(void)
{
	/* P4: 9.44 uses border 7, not 6 - retail loads `addiu $a0, $zero, 7`
	 * at 0x004CD134. */
	SVM_GotoSvrBorder(7);
}

// printf-style error of the MW player: formats into a 256-byte static and reports through
// SVM_CallErr1 to the game's callback (ap_mwply_err_func).
void MWSFSVM_Error(const Char8 *fmt, ...)
{
	static Char8 errstr[256];
	va_list ap;

	memset(errstr, 0, sizeof(errstr));
	va_start(ap, fmt);
	vsprintf(errstr, fmt, ap);
	va_end(ap);
	SVM_CallErr1(errstr);
}

// Re-entry guard for the server flags.
Sint32 MWSFSVM_TestAndSet(Sint32 *flag)
{
	return SVM_TestAndSet(flag);
}

// Registers the decode server on the SVM main type (5), run by ADXM_ExecMain.
void MWSFSVM_EntryMainFunc(Sint32 (*func)(void *obj), void *obj)
{
	mwg_main_fid = SVM_SetCbSvr(5, func, obj);
}

// Registers the idle-thread server (type 6).
void MWSFSVM_EntryIdleFunc(Sint32 (*func)(void *obj), void *obj)
{
	mwg_idle_fid = SVM_SetCbSvr(6, func, obj);
}

// Registers the vsync server in a fixed slot of type 2.
void MWSFSVM_EntryIdVfunc(Sint32 id, Sint32 (*func)(void *obj), void *obj)
{
	SVM_SetCbSvrId(2, id, func, obj);
	mwg_vsync_fid = id;
}

// SVM init and cleared callback ids.
// FUN_00510EA0
void MWSFSVM_Init(void)
{
	SVM_Init();
	mwg_vbin_fid = 0;
	mwg_vsync_fid = 0;
	mwg_idle_fid = 0;
	mwg_main_fid = 0;
}
