/* CRI Sofdec MW player stream-controller glue (mwstm.c): MWSTM_* wrappers over the ADX stream
 * controller (ADXSTM) that pulls the movie file from the DVD into the player's file ring buffer. */
#include "cri_xpt.h"
#include "adx_stm.h"

// ADXSTM_STAT_* of the controller.
// FUN_005122A0
Sint32 MWSTM_GetStat(ADXSTM stm)
{
	return ADXSTM_GetStat(stm);
}

// Non-blocking stop and unbind.
// FUN_00512250
void MWSTM_ReqStop(ADXSTM stm)
{
	ADXSTM_StopNw(stm);
	ADXSTM_ReleaseFileNw(stm);
}

// Starts streaming the bound range.
// FUN_00512238
Sint32 MWSTM_ReqStart(ADXSTM stm)
{
	return ADXSTM_Start(stm);
}

// Stops the movie file and releases its binding before returning.
// FUN_00512278
void func_00512278(ADXSTM stm)
{
	ADXSTM_Stop(stm);
	ADXSTM_ReleaseFile(stm);
}

// Unbinds, binds the new file range (no-wait) and sets the end-of-stream at its length.
// FUN_005121C0
void MWSTM_SetFileRange(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
	ADXSTM_ReleaseFileNw(stm);
	ADXSTM_BindFileNw(stm, fname, dir, ofst, nsct);
	ADXSTM_SetEos(stm, nsct);
}

// Destroys the controller.
void MWSTM_Destroy(ADXSTM stm)
{
	ADXSTM_Destroy(stm);
}

// Creates a real-time controller writing into `sj`.
// FUN_00512138
ADXSTM MWSTM_Create(void *sj)
{
	return ADXSTM_Create(sj, 0);
}

// Refill policy in bytes (min = refill when below, max = request size).
void MWSTM_SetFlowLimit(ADXSTM stm, Sint32 min_nsct, Sint32 max_nsct)
{
	if (stm != NULL) {
		ADXSTM_SetBufSize(stm, min_nsct, max_nsct);
	}
}

// Whether the controller is in ADXSTM_STAT_ERROR.
// FUN_00512088
Bool MWSTM_IsFsStatErr(ADXSTM stm)
{
	return ADXSTM_GetStat(stm) == 4;
}

// Nothing to initialise on this platform (0).
Sint32 MWSTM_InitStatic(void)
{
	return 0;
}
