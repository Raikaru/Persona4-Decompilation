/* CRI Sofdec MPEG system-stream demultiplexer (MPS) object layout, from the DOL's field offsets. */
#ifndef CRI_MPS_H
#define CRI_MPS_H

#include "cri_xpt.h"

typedef struct MPS_OBJ *MPS;

/* pack header (16 bytes, 8-byte aligned: holds the 64-bit SCR) */
typedef struct {
	Sint64 scr;
	Sint32 rsv;
	Sint32 mux_rate;      /* 0x0C (sfd_cre reads it) */
} MPS_PACKHD;

/* system header (32 bytes) */
typedef struct {
	Sint32 raw[8];
} MPS_SYSHD;

/* packet header (40 bytes, 8-byte aligned: holds the 64-bit PTS/DTS) */
typedef struct {
	Sint64 pts;
	Sint64 dts;
	Sint32 raw[6];
} MPS_PKETHD;

/* MPS_OBJ.used */
#define MPS_HN_FREE 1
#define MPS_HN_USED 2

typedef struct MPS_OBJ {
	Sint32 used;              /* 0x00 */
	void (*errfn)(void *obj); /* 0x04 */
	void *errobj;             /* 0x08 */
	Sint32 errcode;           /* 0x0C */
	Sint32 x10;               /* 0x10 (2) */
	Sint32 x14;               /* 0x14 */
	MPS_PACKHD packhd;        /* 0x18 */
	MPS_SYSHD last_syshd;     /* 0x28 */
	MPS_SYSHD syshd[3];       /* 0x48 */
	MPS_PKETHD pkethd;        /* 0xA8 */
	Sint32 xd0;               /* 0xD0 */
	Sint32 (*dechd_func)();   /* 0xD4 */
	Sint32 xd8;               /* 0xD8 */
	Sint32 xdc;               /* 0xDC */
	Sint32 xe0;               /* 0xE0 */
	void *sysfn;              /* 0xE4 system header callback (MPS_SetSystemFn) */
	void *sysobj;             /* 0xE8 */
	void *psmapfn;            /* 0xEC (MPS_SetPsMapFn) */
	void *psmapobj;           /* 0xF0 */
	void *pesfn;              /* 0xF4 PES header callback (MPS_SetPesFn) */
	void *pesobj;             /* 0xF8 */
	Sint32 xfc;
} MPS_OBJ;

/* MPS_PKETHD.raw */
#define MPS_PKT_STMID 0
#define MPS_PKT_TYPE 1
#define MPS_PKT_IDX 2
#define MPS_PKT_LEN 3
#define MPS_PKT_STDBUF 4
#define MPS_PKT_PAYLOAD 5

/* start codes as MPS_CheckDelim classifies them */
#define MPS_DELIM_PACK 0x10000
#define MPS_DELIM_SYSHD 0x20000
#define MPS_DELIM_PKET 0x40000
#define MPS_DELIM_END 0x80000

/* library work (mps_lib.c): header + num_hn handles */
typedef struct {
	void (*errfn)(void *obj); /* 0x00 */
	void *errobj;             /* 0x04 */
	Sint32 errcode;           /* 0x08 */
	Sint32 num_hn;            /* 0x0C */
	MPS_OBJ hn[1];            /* 0x10 */
} MPSLIB_WORK;

extern MPSLIB_WORK *MPSLIB_libwork;

Sint32 MPSLIB_CheckHn(MPS mps);
Sint32 MPSLIB_SetErr(MPS mps, Sint32 code);
MPS MPS_Create(void);
Sint32 MPS_Destroy(MPS mps);
Uint32 MPS_CheckDelim(Uint8 *p);
Sint32 MPS_DecHd(MPS mps, Uint8 *data, Sint32 size, Sint32 *len, Sint32 *flags);
Sint32 MPS_GetPackHd(MPS mps, MPS_PACKHD *hd);
Sint32 MPS_GetSysHd(MPS mps, MPS_SYSHD *hd, Sint32 no);
Sint32 MPS_GetLastSysHd(MPS mps, MPS_SYSHD *hd);
Sint32 MPS_GetPketHd(MPS mps, MPS_PKETHD *hd);

#endif
