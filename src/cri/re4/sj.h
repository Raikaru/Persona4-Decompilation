/* CRI Stream Joint (SJ) interface: a handle is a pointer to an object whose first word is its
 * interface table (layout from sj_mem's sjmem_vtbl). */
#ifndef CRI_SJ_H
#define CRI_SJ_H

#include "cri_xpt.h"

typedef struct SJ_OBJ *SJ;

typedef struct {
	Uint8 *data;
	Sint32 len;
} SJCK;

typedef struct {
	Uint8 data[16];
} SJUUID;

/* chunk ids */
#define SJ_CK_FREE 0
#define SJ_CK_DATA 1

/* error codes passed to the error callback in place of the message */
#define SJ_ERR_PRM ((Char8 *)-3)

typedef struct {
	void *QueryInterface;                             /* 0x00 (unused) */
	void *AddRef;                                     /* 0x04 (unused) */
	void *Release;                                    /* 0x08 (unused) */
	void (*Destroy)(SJ sj);                           /* 0x0C */
	const SJUUID *(*GetUuid)(SJ sj);                  /* 0x10 */
	void (*Reset)(SJ sj);                             /* 0x14 */
	void (*GetChunk)(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck); /* 0x18 */
	void (*UngetChunk)(SJ sj, Sint32 id, SJCK *ck);   /* 0x1C */
	void (*PutChunk)(SJ sj, Sint32 id, SJCK *ck);     /* 0x20 */
	Sint32 (*GetNumData)(SJ sj, Sint32 id);           /* 0x24 */
	Sint32 (*IsGetChunk)(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte); /* 0x28 */
	void (*EntryErrFunc)(SJ sj, void (*func)(void *obj, Char8 *msg), void *obj); /* 0x2C */
} SJ_IF;

struct SJ_OBJ {
	SJ_IF *vtbl;
};

#define SJ_Destroy(sj) (*(sj)->vtbl->Destroy)(sj)
#define SJ_GetUuid(sj) (*(sj)->vtbl->GetUuid)(sj)
#define SJ_Reset(sj) (*(sj)->vtbl->Reset)(sj)
#define SJ_GetChunk(sj, id, nbyte, ck) (*(sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_UngetChunk(sj, id, ck) (*(sj)->vtbl->UngetChunk)(sj, id, ck)
#define SJ_PutChunk(sj, id, ck) (*(sj)->vtbl->PutChunk)(sj, id, ck)
#define SJ_GetNumData(sj, id) (*(sj)->vtbl->GetNumData)(sj, id)
#define SJ_IsGetChunk(sj, id, nbyte, rbyte) (*(sj)->vtbl->IsGetChunk)(sj, id, nbyte, rbyte)
#define SJ_EntryErrFunc(sj, func, obj) (*(sj)->vtbl->EntryErrFunc)(sj, func, obj)

SJ SJRBF_Create(void *buf, Sint32 bsize, Sint32 xsize);
SJ SJMEM_Create(void *buf, Sint32 bsize);
void SJCRS_Lock(void);
void SJCRS_Unlock(void);
void SJERR_CallErr(Char8 *msg);
void *SJ_SearchTag(SJCK *inf, const Char8 *tag, const Char8 *name, SJCK *out);
void SJ_SplitChunk(SJCK *src, Sint32 n, SJCK *a, SJCK *b);

#endif
