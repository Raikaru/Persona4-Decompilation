/* CRI Sofdec MW player library init (mwsfdlib.c, MWSFD/GC Ver.3.33, Sep 22 2004): mwPlyInitSfdFx
 * (the game's SofdecInit) brings up ADXT, the stream joints, the SFD decoder core with the driver
 * table (memory input, MPS demux, MPV video, ADXT audio, manual video out, auto audio out, user
 * output), the load scheduler and the SFX converter, and registers the player's server callbacks
 * with the SVM. Holds the library work (8 player handles) and the SFD error callback that turns
 * error codes into the messages the game's ap_mwply_err_func receives. */
#include "cri_xpt.h"
#include "sfd.h"
#include "lsc.h"
#include "mwsfd.h"
#include <string.h>
#include <stdio.h>

extern const SFD_TR_IF SFD_tr_in_mem;
extern const SFD_TR_IF SFD_tr_sd_mps;
extern const SFD_TR_IF SFD_tr_vd_mpv;
extern const SFD_TR_IF SFD_tr_vo_manu;
extern const SFD_TR_IF SFD_tr_ad_adxt;
extern const SFD_TR_IF SFD_tr_ao_auto_p;
extern const SFD_TR_IF SFD_tr_uo;

void ADXT_Init(void);
void SJRBF_Init(void);
void SJMEM_Init(void);
void SJUNI_Init(void);
void LSC_Init(void);
Sint32 SFD_Init(SFD_INIT_PRM *prm);
Sint32 SFD_SetErrFn(SFD sfd, void (*fn)(void *obj, Sint32 code), void *obj);
Sint32 SFD_IsVersionCompatible(const Char8 *str, Sint32 ver);
void mwsflib_LscErrFunc(void *obj, Char8 *msg);

#define MWSFD_SFD_VERSION 0x3598
#define MWSFD_MAX_ERRCODE 16

static const Char8 mwsfd_ver_str[] =
	"\nMWSFD/GC Ver.3.33 Build:Sep 22 2004 10:34:45\n\0Append: MW2407 GC20Apr2004Patch1\n";

static const SFD_TR_IF *const mwsfd_trentry[15] = {
	&SFD_tr_in_mem, &SFD_tr_sd_mps, &SFD_tr_vd_mpv, &SFD_tr_vo_manu, &SFD_tr_ad_adxt,
	&SFD_tr_ao_auto_p, &SFD_tr_uo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

static const SFD_INIT_PRM mwsfd_initsfdpara = { (SFTRN_TRIF_TBL *)mwsfd_trentry, 0xEA24 };

const Sint32 mwsfd_siz_mwplyhn = 0x2B8;

Sint32 mwsfd_init_cnt;
Sint32 mwsfd_init_flag;
void *mwsfd_err_sfdhn;
MWPLY mwsfd_err_mwsfdhn;
Char8 mwg_sfd_errstr[0x100];
Sint32 mwg_sfd_errcnt;
Sint32 mwg_sfd_errcode[MWSFD_MAX_ERRCODE];
MWSFD_LIBWORK mwsfd_libwork;
static const Char8 *cri_verstr_ptr;

void SFD_Finish(void);

/* dead-stripped by the linker; its references fix the .bss order (first-reference rule) */
void mwPlyFinishSfdFx(void)
{
	if (--mwsfd_init_cnt == 0) {
		mwsfd_init_flag = 0;
		mwsfd_err_sfdhn = NULL;
		mwsfd_err_mwsfdhn = NULL;
		mwg_sfd_errstr[0] = 0;
		mwg_sfd_errcnt = 0;
		mwg_sfd_errcode[0] = 0;
		memset(&mwsfd_libwork, 0, sizeof(MWSFD_LIBWORK));
		SFD_Finish();
	}
}

// SFD error callback: remembers the failing player/SFD handle and the last 16 codes, formats the
// message for the known codes (data error, picture size, read buffer, frame pool, ADXT handle
// count) and reports it through MWSFSVM_Error to the game's callback.
void MWSFLIB_SfdErrFunc(void *obj, Sint32 code)
{
	MWPLY mwply = (MWPLY)obj;
	void *sfd;

	if (mwply != NULL) {
		sfd = mwPlyGetSfdHn(mwply);
		mwsfd_err_mwsfdhn = mwply;
		mwsfd_err_sfdhn = sfd;
	} else {
		mwsfd_err_mwsfdhn = NULL;
		mwsfd_err_sfdhn = NULL;
	}
	if (code != 0) {
		mwg_sfd_errcode[mwg_sfd_errcnt] = code;
		if (mwg_sfd_errcnt < MWSFD_MAX_ERRCODE - 1) {
			mwg_sfd_errcnt++;
		}
	}
	switch (code) {
	case -3:
	case -2:
		sprintf(mwg_sfd_errstr, "DATA ERROR(%08X)", code);
		break;
	case 0xFF000F17:
	case 0xFF000F18:
		sprintf(mwg_sfd_errstr,
			"SFD ERROR(%08X): 'max_width, max_height' of creation parameter is small. Increase this value.",
			code);
		break;
	case 0xFF000408:
	case 0xFF00040C:
	case 0xFF000F1C:
		sprintf(mwg_sfd_errstr,
			"SFD ERROR(%08X): Read buffer is small. Increase 'max_bps' of creation parameter.", code);
		break;
	case 0xFF000F15:
		sprintf(mwg_sfd_errstr,
			"SFD ERROR(%08X): Frame pool size is incorrect. Set positive integer to 'nfrm_pool_wk' of creation parameter.",
			code);
		break;
	case 0xFF000C04:
		sprintf(mwg_sfd_errstr,
			"SFD ERROR(%08X): Number of ADXT handles exceeds its maximum number. MWPLY handle uses one ADXT handle(stereo) for MWSFD_FTYPE_SFD.",
			code);
		break;
	default:
		sprintf(mwg_sfd_errstr, "SFD ERROR(%08X)", code);
		break;
	}
	MWSFSVM_Error(mwg_sfd_errstr);
}

// Records the library error code (returned unchanged, 0 for success).
Sint32 MWSFLIB_SetErrCode(Sint32 code)
{
	mwsfd_libwork.errcode = code;
	if (code == 0) {
		return 0;
	}
	return code;
}

// Whether pausing must wait for the decode server border (1 in this build).
Sint32 MWSFD_GetPauseBdr(void)
{
	return mwsfd_libwork.pause_bdr;
}

// Whether picture user data is captured (1 in this build).
Sint32 MWSFD_GetUsePicUsr(void)
{
	return mwsfd_libwork.use_picusr;
}

// Initialises the SFD core with the driver table and the refresh rate in 1/1000 Hz (59940) after
// checking the "1.947" version string; installs the library-wide error callback.
static Sint32 mwPlySfdInit(Sint32 vcnt)
{
	SFD_INIT_PRM sfdprm;
	Sint32 ret;

	sfdprm = mwsfd_initsfdpara;
	sfdprm.prm1 = vcnt;
	if (SFD_IsVersionCompatible("1.947", MWSFD_SFD_VERSION) != TRUE) {
		MWSFSVM_Error("E011081 mwPlySfdInit: Not compatible SFD Version.");
		ret = -1;
	} else if (SFD_Init(&sfdprm) != 0) {
		ret = MWSFLIB_SetErrCode(-0x12D);
	} else if (SFD_SetErrFn(NULL, MWSFLIB_SfdErrFunc, NULL) != 0) {
		ret = MWSFLIB_SetErrCode(-0x12F);
	} else {
		ret = 0;
	}
	return ret;
}

// Copies the init parameters (refresh rate, frame pool size, main-thread decode flag) into the
// library work, or the defaults (59.94 Hz, pool 1).
static void mwsflib_SetLibPrm(MWSFD_LIBWORK *lw, MWSFD_INIT_PRM *prm)
{
	if (prm != NULL) {
		lw->vfreq = prm->vfreq;
		lw->x08 = prm->x04;
		lw->nfrm_pool = prm->nfrm_pool;
		lw->x10 = prm->x0c;
	} else {
		lw->vfreq = 59.94f;
		lw->x08 = 1;
		lw->nfrm_pool = 1;
		lw->x10 = 0;
	}
}

// Library init (mwPlyInitSfdFx from SofdecInit: 59.94 Hz, pool 1 -> 0 after the -2 adjustment):
// ADXT, stream joints, SFD core, LSC and SFX, then registers the vsync, main and idle server
// callbacks with the SVM. Without CRI threads everything runs from the main callback
// (MWSFSVR_MainThrdProc) when the game calls ADXM_ExecMain.
void mwPlyInitSfdFx(MWSFD_INIT_PRM *iprm)
{
	MWSFD_INIT_PRM prm;
	MWSFD_INIT_PRM *pprm;
	MWSFD_LIBWORK *lw;

	if (iprm == NULL) {
		MWSFSVM_Error("E1122611 mwPlyInitSfdFx: iprm is NULL.");
		return;
	}
	memset(&prm, 0, sizeof(prm));
	pprm = &prm;
	prm.vfreq = iprm->vfreq;
	prm.x04 = iprm->x04;
	prm.nfrm_pool = iprm->nfrm_pool;
	prm.x0c = iprm->x0c;
	prm.x10 = iprm->x10;
	prm.x14 = iprm->x14;
	prm.x18 = iprm->x18;
	prm.x1c = iprm->x1c;
	cri_verstr_ptr = mwsfd_ver_str;
	MWSFSVM_Init();
	prm.nfrm_pool -= 2;
	if (prm.nfrm_pool < 0) {
		prm.nfrm_pool = 0;
	}
	if (mwsfd_init_cnt == 0) {
		ADXT_Init();
		SJRBF_Init();
		SJMEM_Init();
		SJUNI_Init();
		if (MWSTM_InitStatic() != 0) {
			MWSFLIB_SetErrCode(-0x65);
			MWSFSVM_Error("E2005 mwPlyInitSfdFx: can't init GSC");
		}
		lw = &mwsfd_libwork;
		memset(lw, 0, sizeof(MWSFD_LIBWORK));
		MWSFSVR_SetMwsfdSvrFlg(0);
		lw->x5c = 0;
		mwsflib_SetLibPrm(&mwsfd_libwork, pprm);
		lw->use_picusr = 1;
		lw->pause_bdr = 1;
		mwg_vcnt = 0;
		if (mwPlySfdInit((Sint32)(0.5f + prm.vfreq * 1000.0f)) != 0) {
			MWSFSVM_Error("ERR20010421A : mwPlyInitSfdFx");
		}
		mwsfd_init_flag = 1;
		MWSFD_SetCond(NULL, 0x1B, (Sint32)prm.vfreq);
		MWSFD_SetCond(NULL, 7, 1);
		LSC_Init();
		LSC_EntryErrFunc(mwsflib_LscErrFunc, NULL);
		MWSFSFX_Init();
		MWSFSVM_EntryIdVfunc(2, MWSFSVR_VsyncThrdProc, NULL);
		MWSFSVM_EntryMainFunc(MWSFSVR_MainThrdProc, NULL);
		MWSFSVM_EntryIdleFunc(MWSFSVR_IdleThrdProc, NULL);
	}
	mwsfd_init_cnt++;
}

// Load scheduler errors -> MWSFSVM_Error.
void mwsflib_LscErrFunc(void *obj, Char8 *msg)
{
	MWSFSVM_Error(msg);
}

// The library work (player handles, callbacks, frame pool setting).
MWSFD_LIBWORK *MWSFLIB_GetLibWorkPtr(void)
{
	return &mwsfd_libwork;
}
