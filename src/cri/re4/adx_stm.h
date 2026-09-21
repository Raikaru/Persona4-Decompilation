/* CRI ADX stream controller (adx_stmc.c) public interface. Argument roles from the callers
 * (lsc_svr, mwstm) and the stores in adx_stmc. */
#ifndef CRI_ADX_STM_H
#define CRI_ADX_STM_H

#include "cri_xpt.h"
#include "sj.h"

typedef struct ADXSTM_OBJ *ADXSTM;

#define ADXSTM_STAT_STOP 0
#define ADXSTM_STAT_PREP 1
#define ADXSTM_STAT_EXEC 2
#define ADXSTM_STAT_END 3
#define ADXSTM_STAT_ERROR 4

Sint32 ADXSTM_Init(void);
void ADXSTM_Finish(void);
ADXSTM ADXSTM_Create(SJ sj, Sint32 mode);
void ADXSTM_Destroy(ADXSTM stm);
Sint32 ADXSTM_SetBufSize(ADXSTM stm, Sint32 min_nsct, Sint32 max_nsct);
void ADXSTM_ExecServer(void);
void ADXSTM_SetEos(ADXSTM stm, Sint32 nsct);
void ADXSTM_Stop(ADXSTM stm);
void ADXSTM_StopNw(ADXSTM stm);
Sint32 ADXSTM_Start(ADXSTM stm);
Sint32 ADXSTM_Tell(ADXSTM stm);
Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 pos);
Sint32 ADXSTM_GetStat(ADXSTM stm);
void ADXSTM_ReleaseFile(ADXSTM stm);
void ADXSTM_ReleaseFileNw(ADXSTM stm);
void ADXSTM_BindFileNw(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct);

#endif
