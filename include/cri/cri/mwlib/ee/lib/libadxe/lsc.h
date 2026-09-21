#ifndef	_LSC_H_
#define	_LSC_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>

#define	LSC_VER				"2.00"

#define	LSC_STM_MAX			(16)

#define	LSC_OBJ_MAX			(8) 

#define	LSC_FNAME_MAX		(40)

#define	LSC_STAT_STOP		(0)
#define	LSC_STAT_WAIT		(1)
#define	LSC_STAT_EXEC		(2)
#define	LSC_STAT_ERR		(3)

#define	LSC_STM_STAT_WAIT	(0)
#define	LSC_STM_STAT_READ	(1)
#define	LSC_STM_STAT_END	(2)

typedef Sint32 LSC_CRS;

typedef void (*LSC_ERRFN)(void *obj, Sint8 *msg);
typedef void (*LSC_STATFN)(void *obj1, void *obj2);

typedef struct _lsc_sinfo
 {
	Sint32 sid;         /* 0x00 id (retail 0x4E9180 8c430038 lw v1,56(v0); 0x4E9194 ae130000 sw s3,0(s0)) */
	Sint8 *fname;       /* 0x04 fname pointer (retail 0x4E9170 ae120004 sw s2,4(s0)) */
	Sint32 chksum;      /* 0x08 checksum (retail 0x4E9198 ae000008 sw zero,8(s0) + sum loop 0x4E91A8-0x4E91C4) */
	void *dir;          /* 0x0C (retail 0x4E91DC ae16000c sw s6,12(s0)) */
	Sint32 ofst;        /* 0x10 (retail 0x4E91C8 ae140010 sw s4,16(s0)) */
	Sint32 fsct;        /* 0x14 (retail 0x4E91D0 ae150014 sw s5,20(s0)) */
	Sint32 stat;        /* 0x18 (retail 0x4E91D8 ae000018 sw zero,24(s0)) */
	Sint32 rdsct;       /* 0x1C (retail 0x4E91D4 ae00001c sw zero,28(s0)) */
} LSC_SINFO;
typedef void	*LSC_FP;

typedef struct _lsc_obj
{
    Sint8       used;
    Sint8       stat;
    Sint8       rdflg;
    Sint8       lpflg;
    Sint8       pause;
    Sint8       rsv1;
    Sint16      rsv2;
    SJ          sj;
    SJCK        ck;
    Sint32      bufmin;
    Sint32      bsize;
    Sint32      wpos;
    Sint32      rpos;
    Sint32      nstm;
    LSC_FP      fp;
    Sint32      fsct;
    Sint32      reqsct;
    Sint32      errcnt;
    LSC_SINFO   sinfo[16];
} LSC_OBJ;
typedef LSC_OBJ *LSC;

LSC lsc_Alloc(void);
void LSC_CallStatFunc(void);
LSC LSC_Create(SJ sj);
void LSC_Destroy(LSC lsc);
void LSC_EntryChgStatFunc(LSC_STATFN statfn, void *obj1, void *obj2);
Sint32 LSC_EntryFileRange(LSC lsc, Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname);
void LSC_ExecServer(void);
Sint32 LSC_GetFlowLimit(LSC lsc);
Sint32 LSC_GetNumStm(LSC lsc);
Sint32 LSC_GetStat(LSC lsc);
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmId(LSC lsc, Sint32 no);
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid);
void LSC_Pause(LSC lsc, Sint32 sw);
void LSC_SetFlowLimit(LSC lsc, Sint32 min);
void LSC_SetLpFlg(LSC lsc, Sint32 flg);
void LSC_Start(LSC lsc);
void LSC_Stop(LSC lsc);

#endif
