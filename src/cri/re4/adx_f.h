/* CRI ADXF (ADX file system: file handles on top of ADXSTM, AFS partitions). Layout of the
 * 0x44-byte handle and the command history reconstructed from adx_fs.c; the globals are defined in
 * adx_fini.c (as raw byte arrays). */
#ifndef CRI_ADX_F_H
#define CRI_ADX_F_H

#include "cri_xpt.h"
#include "sj.h"
#include "adx_stm.h"

#define ADXF_MAX_OBJ 16
#define ADXF_MAX_PTINFO 0x100
#define ADXF_CMD_HSTRY_NUM 16
#define ADXF_CMD_NUM 16

/* ADXF_OBJ.stat */
#define ADXF_STAT_STOP 1
#define ADXF_STAT_READING 2
#define ADXF_STAT_READEND 3
#define ADXF_STAT_ERROR 4

/* command history ids */
#define ADXF_CMD_OPEN 1
#define ADXF_CMD_OPEN_AFS 2
#define ADXF_CMD_CLOSE 3
#define ADXF_CMD_READ 4
#define ADXF_CMD_STOP 5
#define ADXF_CMD_SEEK 6

typedef struct {
	Sint8 used;                /* 0x00 */
	Sint8 stat;                /* 0x01 */
	Sint8 sjmode;              /* 0x02 sj supplied by the caller (not released) */
	Sint8 stopnw_flg;          /* 0x03 ADXF_StopNw pending */
	ADXSTM stm;                /* 0x04 */
	SJ sj;                     /* 0x08 */
	Sint32 ptid;               /* 0x0C */
	Sint32 flid;               /* 0x10 */
	Sint32 ofst;               /* 0x14 current position (sectors) */
	Sint32 fnsct;              /* 0x18 file size (sectors) */
	Sint32 rqsct;              /* 0x1C requested sectors */
	Sint32 rdsct;              /* 0x20 sectors read so far */
	void *ocbi_buf;            /* 0x24 */
	Uint32 ocbi_len;           /* 0x28 */
	Sint32 x2c;
	Sint32 x30;
	Sint32 x34;
	Sint32 x38;
	Sint32 x3c;
	Sint32 x40;
} ADXF_OBJ;

typedef ADXF_OBJ *ADXF;

typedef struct {
	Uint8 cmd;                 /* 0x00 */
	Uint8 sub;                 /* 0x01 0 = entry, 1 = exit */
	Uint16 ncall;              /* 0x02 */
	ADXF adxf;                 /* 0x04 */
	Sint32 prm1;               /* 0x08 */
	Sint32 prm2;               /* 0x0C */
} ADXF_CMD_HSTRY;

/* AFS partition info header */
typedef struct {
	Char8 tag[4];              /* "AFS" */
	Sint32 nfile;
	struct {
		Sint32 ofst;
		Sint32 fnbyte;
	} fl[1];
} ADXF_PTINFO;

extern Sint32 adxf_init_cnt;
extern Sint32 adxf_hstry_no;
extern Uint16 adxf_cmd_ncall[ADXF_CMD_NUM];
extern ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_NUM];
extern Sint32 adxf_ocbi_fg;
extern ADXF_PTINFO *adxf_ptinfo[ADXF_MAX_PTINFO];
extern ADXF_OBJ adxf_obj[ADXF_MAX_OBJ];
extern void *adxf_ldptnw_hn;

void ADXF_Ocbi(void *addr, Uint32 nbytes);
ADXF ADXF_Open(const Char8 *fname, void *dir);
ADXF adxf_CreateAdxFs(void);
void ADXF_Stop(ADXF adxf);
Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf);
void ADXF_Close(ADXF adxf);
void ADXF_CloseAll(void);
void ADXF_ExecServer(void);

void ADXCRS_Lock(void);
void ADXCRS_Unlock(void);
void ADXERR_CallErrFunc1(const Char8 *msg);

#endif
