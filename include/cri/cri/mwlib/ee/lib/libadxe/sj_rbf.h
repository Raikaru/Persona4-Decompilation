#ifndef _SJ_RBF_H_
#define _SJ_RBF_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "macros.h"

typedef void (*SJRBF_ERRFN)(void *obj, Sint32 errcode);

typedef struct 
{ 
	SJIF vtbl;
	Sint32 used;
	const UUID *uuid;
	Sint32 ndata;
	Sint32 nroom;
	Sint32 wpos;
	Sint32 rpos;
	Sint8 *buf;
	Sint32 bsize;
	Sint32 xsize;
	Sint32 flow[2][2]; /* 0x28: retail SJRBF_GetNumData lw 0x38 vs 0x28, SJRBF_Create sw 0x38, sjrbf_Reset clears 0x28..0x34 */
	SJRBF_ERRFN errfunc; /* 0x38 */
	void *errobj; /* 0x3C */
} SJRBF_OBJ;
typedef SJRBF_OBJ *SJRBF;

SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize);
void SJRBF_Destroy(SJ sj);
void SJRBF_EntryErrFunc(SJ sj, SJRBF_ERRFN func, void *obj);
void SJRBF_Error(SJRBF rbf, Sint32 errcode);
void SJRBF_Finish(void);
Sint8* SJRBF_GetBufPtr(SJRBF sjrbf);
Sint32 SJRBF_GetBufSize(SJRBF sjrbf);
void SJRBF_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJRBF_GetNumData(SJ sj, Sint32 id);
const UUID* SJRBF_GetUuid(SJ sj);
Sint32 SJRBF_GetXtrSize(SJRBF sjrbf);
void SJRBF_Init(void);
Sint32 SJRBF_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJRBF_PutChunk(SJ sj, Sint32 id, SJCK *ck);
void SJRBF_Reset(SJ sj);
void SJRBF_UngetChunk(SJ sj, Sint32 id, SJCK *ck);

#endif
