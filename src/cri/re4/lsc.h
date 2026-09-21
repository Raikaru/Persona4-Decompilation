/* CRI LSC (load scheduler): queues file ranges on one ADX stream handle (lsc.c, lsc_svr.c,
 * lsc_ini.c, lsc_err.c, lsc_crs.c). Layout reconstructed from the asm. */
#ifndef CRI_LSC_H
#define CRI_LSC_H

#include "cri_xpt.h"
#include "sj.h"
#include "adx_stm.h"

#define LSC_MAX_OBJ 32
#define LSC_MAX_ENTRY 16
#define LSC_ID_MAX 0x7FFFFFFF

/* LSC_OBJ.stat */
#define LSC_STAT_STOP 0
#define LSC_STAT_PREP 1
#define LSC_STAT_EXEC 2
#define LSC_STAT_ERROR 3

/* LSC_ENTRY.stat */
#define LSC_ENT_WAIT 0
#define LSC_ENT_LOADING 1
#define LSC_ENT_DONE 2

typedef struct {
	Sint32 id;           /* 0x00 */
	Char8 *fname;        /* 0x04 */
	Sint32 fname_sum;    /* 0x08 checksum of fname */
	void *dir;           /* 0x0C */
	Sint32 ofst;         /* 0x10 */
	Sint32 nsct;         /* 0x14 */
	Sint32 stat;         /* 0x18 */
	Sint32 pos;          /* 0x1C */
} LSC_ENTRY;

typedef struct {
	Sint8 used;                        /* 0x00 */
	Sint8 stat;                        /* 0x01 */
	Sint8 stm_start;                   /* 0x02 */
	Sint8 loop_flag;                   /* 0x03 */
	Sint8 pause_flag;                  /* 0x04 */
	Uint8 pad5[3];
	SJ sj;                             /* 0x08 */
	Sint32 pad0c;                      /* 0x0C */
	Sint32 pad10;                      /* 0x10 */
	Sint32 min_val;                    /* 0x14 flow limit */
	Sint32 bufsize;                    /* 0x18 total sj size in sectors */
	Sint32 wr_idx;                     /* 0x1C */
	Sint32 rd_idx;                     /* 0x20 */
	Sint32 num_stm;                    /* 0x24 */
	ADXSTM stm;                        /* 0x28 */
	Sint32 cur_nsct;                   /* 0x2C */
	Sint32 pad30;                      /* 0x30 */
	Sint32 pad34;                      /* 0x34 */
	LSC_ENTRY tbl[LSC_MAX_ENTRY];      /* 0x38 */
} LSC_OBJ;

typedef LSC_OBJ *LSC;

extern LSC_OBJ lsc_obj[LSC_MAX_OBJ];

void LSC_Init(void);
void LSC_Finish(void);
LSC LSC_Create(SJ sj);
void LSC_Destroy(LSC lsc);
void LSC_SetStmHndl(LSC lsc, ADXSTM stm);
Sint32 LSC_EntryFileRange(LSC lsc, Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
void LSC_Stop(LSC lsc);
void LSC_ExecServer(void);
Sint32 LSC_GetStat(LSC lsc);
Sint32 LSC_GetNumStm(LSC lsc);
void LSC_SetFlowLimit(LSC lsc, Sint32 min_val);
void LSC_CallStatFunc(void);
void LSC_CallErrFunc(Char8 *fmt, ...);
void LSC_EntryErrFunc(void (*func)(void *obj, Char8 *msg), void *obj);
void LSC_LockCrs(Sint32 *msk);
void LSC_UnlockCrs(Sint32 *msk);
void lsc_ExecHndl(LSC lsc);

#endif
