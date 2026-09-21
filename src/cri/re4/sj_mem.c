/* CRI Stream Joint: memory joint (sj_mem.c, SJMEM). A read-only joint over one fixed buffer: the
 * whole buffer is DATA at creation, GetChunk(DATA) walks through it, nothing can be put back as
 * FREE. Used for memory-resident ADX data (ADXT memory playback, the SFA header insertion). 32 objects. */
#include "cri_xpt.h"
#include "sj.h"
#include <string.h>

#define SJMEM_MAX_OBJ 32

typedef struct {
	SJ_IF *vtbl;                              /* 0x00 */
	Sint32 used;                              /* 0x04 */
	const SJUUID *uuid;                       /* 0x08 */
	Sint32 ndata;                             /* 0x0C */
	Sint32 rdofs;                             /* 0x10 */
	Uint8 *buf;                               /* 0x14 */
	Sint32 bsize;                             /* 0x18 */
	void (*errfunc)(void *obj, Char8 *msg);   /* 0x1C */
	void *errobj;                             /* 0x20 */
} SJMEM_OBJ;

static const SJUUID sjmem_uuid = {
	{0xDD, 0x9E, 0xEE, 0x41, 0x16, 0x79, 0x11, 0xD2, 0x93, 0x6C, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC}
};

void SJMEM_Destroy(SJMEM_OBJ *sj);
const SJUUID *SJMEM_GetUuid(SJMEM_OBJ *sj);
void SJMEM_Reset(SJMEM_OBJ *sj);
void SJMEM_GetChunk(SJMEM_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck);
void SJMEM_UngetChunk(SJMEM_OBJ *sj, Sint32 id, SJCK *ck);
void SJMEM_PutChunk(SJMEM_OBJ *sj, Sint32 id, SJCK *ck);
Sint32 SJMEM_GetNumData(SJMEM_OBJ *sj, Sint32 id);
Sint32 SJMEM_IsGetChunk(SJMEM_OBJ *sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJMEM_EntryErrFunc(SJMEM_OBJ *sj, void (*func)(void *obj, Char8 *msg), void *obj);
void SJMEM_Error(void *obj, Char8 *msg);

static SJ_IF sjmem_vtbl = {
	NULL,
	NULL,
	NULL,
	(void (*)(SJ))SJMEM_Destroy,
	(const SJUUID *(*)(SJ))SJMEM_GetUuid,
	(void (*)(SJ))SJMEM_Reset,
	(void (*)(SJ, Sint32, Sint32, SJCK *))SJMEM_GetChunk,
	(void (*)(SJ, Sint32, SJCK *))SJMEM_UngetChunk,
	(void (*)(SJ, Sint32, SJCK *))SJMEM_PutChunk,
	(Sint32 (*)(SJ, Sint32))SJMEM_GetNumData,
	(Sint32 (*)(SJ, Sint32, Sint32, Sint32 *))SJMEM_IsGetChunk,
	(void (*)(SJ, void (*)(void *, Char8 *), void *))SJMEM_EntryErrFunc,
};

Sint32 sjmem_init_cnt = 0;
SJMEM_OBJ sjmem_obj[SJMEM_MAX_OBJ];

#define SJMEM_CALL_ERR(sj) \
	if ((sj)->errfunc != NULL) { \
		(sj)->errfunc((sj)->errobj, SJ_ERR_PRM); \
	}

// The fixed buffer size in bytes.
Sint32 SJMEM_GetBufSize(SJMEM_OBJ *sj)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090251 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090252 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = sj->bsize;
	}
	SJCRS_Unlock();
	return ret;
}

/* dead-stripped by the linker */
void *SJMEM_GetBufPtr(SJMEM_OBJ *sj)
{
	void *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090249 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090250 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->buf;
	}
	SJCRS_Unlock();
	return ret;
}

// Whether `nbyte` DATA bytes remain (FREE is always 0: a memory joint is read-only).
Sint32 SJMEM_IsGetChunk(SJMEM_OBJ *sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
	Sint32 ret;
	Sint32 n;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090247 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090248 : Specified handle is invalid.");
		ret = 0;
	} else {
		if (id == SJ_CK_FREE) {
			n = 0;
		} else if (id == SJ_CK_DATA) {
			n = nbyte;
			if (sj->ndata < nbyte) {
				n = sj->ndata;
			}
		} else {
			n = 0;
			SJMEM_CALL_ERR(sj);
		}
		*rbyte = n;
		if (n != nbyte) {
			ret = 0;
		} else {
			ret = 1;
		}
	}
	SJCRS_Unlock();
	return ret;
}

// Rewinds the read cursor by the chunk (DATA only; the chunk must end at the cursor).
void SJMEM_UngetChunk(SJMEM_OBJ *sj, Sint32 id, SJCK *ck)
{
	Sint32 ofs;
	Sint32 ndata;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090245 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090246 : Specified handle is invalid.");
	} else if (ck->len > 0 && ck->data != NULL) {
		if (id == SJ_CK_FREE) {
			SJMEM_CALL_ERR(sj);
		} else if (id == SJ_CK_DATA) {
			ofs = sj->rdofs - ck->len;
			ofs = (ofs > 0) ? ofs : 0;
			sj->rdofs = ofs;
			ndata = sj->ndata + ck->len;
			if (sj->bsize < ndata) {
				ndata = sj->bsize;
			}
			sj->ndata = ndata;
			if (ofs != ck->data - sj->buf) {
				SJMEM_CALL_ERR(sj);
			}
		} else {
			ck->len = 0;
			ck->data = NULL;
			SJMEM_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// No-op for FREE/DATA (nothing is produced into a memory joint); other ids are errors.
void SJMEM_PutChunk(SJMEM_OBJ *sj, Sint32 id, SJCK *ck)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090243 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090244 : Specified handle is invalid.");
	} else if (ck->len > 0 && ck->data != NULL) {
		if (id != SJ_CK_FREE && id != SJ_CK_DATA) {
			ck->len = 0;
			ck->data = NULL;
			SJMEM_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// DATA: the next `nbyte` unread bytes of the buffer, advancing the read cursor. FREE: empty chunk.
void SJMEM_GetChunk(SJMEM_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090241 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090242 : Specified handle is invalid.");
	} else {
		if (id == SJ_CK_FREE) {
			ck->len = 0;
			ck->data = NULL;
		} else if (id == SJ_CK_DATA) {
			ck->len = (sj->ndata < nbyte) ? sj->ndata : nbyte;
			ck->data = sj->buf + sj->rdofs;
			sj->rdofs += ck->len;
			sj->ndata -= ck->len;
		} else {
			ck->len = 0;
			ck->data = NULL;
			SJMEM_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// Unread bytes (DATA); 0 for FREE.
Sint32 SJMEM_GetNumData(SJMEM_OBJ *sj, Sint32 id)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090239 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090240 : Specified handle is invalid.");
		ret = 0;
	} else if (id == SJ_CK_DATA) {
		ret = sj->ndata;
	} else if (id == SJ_CK_FREE) {
		ret = 0;
	} else {
		SJMEM_CALL_ERR(sj);
		ret = 0;
	}
	SJCRS_Unlock();
	return ret;
}

// Rewinds: the whole buffer is unread data again.
static void sjmem_Reset(SJMEM_OBJ *sj)
{
	if (sj == NULL) {
		SJERR_CallErr("E2004090237 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090238 : Specified handle is invalid.");
	} else {
		sj->ndata = sj->bsize;
		sj->rdofs = 0;
	}
}

// Locked sjmem_Reset.
void SJMEM_Reset(SJMEM_OBJ *sj)
{
	SJCRS_Lock();
	sjmem_Reset(sj);
	SJCRS_Unlock();
}

// Replaces the per-joint error callback.
void SJMEM_EntryErrFunc(SJMEM_OBJ *sj, void (*func)(void *obj, Char8 *msg), void *obj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090235 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090236 : Specified handle is invalid.");
	} else {
		sj->errfunc = func;
		sj->errobj = obj;
	}
	SJCRS_Unlock();
}

// The memory joint's class UUID.
const SJUUID *SJMEM_GetUuid(SJMEM_OBJ *sj)
{
	const SJUUID *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090233 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090234 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->uuid;
	}
	SJCRS_Unlock();
	return ret;
}

// Clears the object.
void SJMEM_Destroy(SJMEM_OBJ *sj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090231 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090232 : Specified handle is invalid.");
	} else {
		memset(sj, 0, sizeof(SJMEM_OBJ));
		sj->used = 0;
	}
	SJCRS_Unlock();
}

// Index of the first unused slot (32 = full).
static Sint32 sjmem_SearchFreeObj(void)
{
	Sint32 i;

	for (i = 0; i < SJMEM_MAX_OBJ; i++) {
		if (sjmem_obj[i].used == 0) {
			break;
		}
	}
	return i;
}

// Creates a read-only joint presenting the `bsize` bytes at `buf` as data (used for memory-resident
// ADX data, e.g. the SFA header insertion's dummy inputs).
SJ SJMEM_Create(void *buf, Sint32 bsize)
{
	SJMEM_OBJ *sj;
	Sint32 i;

	SJCRS_Lock();
	i = sjmem_SearchFreeObj();
	if (i == SJMEM_MAX_OBJ) {
		sj = NULL;
	} else {
		sj = &sjmem_obj[i];
		sj->used = 1;
		sj->vtbl = &sjmem_vtbl;
		sj->buf = buf;
		sj->bsize = bsize;
		sj->uuid = &sjmem_uuid;
		sj->errfunc = SJMEM_Error;
		sj->errobj = sj;
		sjmem_Reset(sj);
	}
	SJCRS_Unlock();
	return (SJ)sj;
}

// Clears the table on the last release.
void SJMEM_Finish(void)
{
	SJCRS_Lock();
	if (--sjmem_init_cnt == 0) {
		memset(sjmem_obj, 0, sizeof(sjmem_obj));
	}
	SJCRS_Unlock();
}

// Clears the table on the first init.
void SJMEM_Init(void)
{
	SJCRS_Lock();
	if (sjmem_init_cnt == 0) {
		memset(sjmem_obj, 0, sizeof(sjmem_obj));
	}
	sjmem_init_cnt++;
	SJCRS_Unlock();
}

// Default per-joint error callback: reports "SJMEM Error".
void SJMEM_Error(void *obj, Char8 *msg)
{
	SJERR_CallErr("SJMEM Error");
}
