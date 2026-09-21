/* CRI Stream Joint: ring buffer joint (sj_rbf.c). One buffer of `bsize` bytes plus `xsize` extra
 * bytes mirroring its start, so chunks crossing the wrap point stay contiguous. */
#include "cri_xpt.h"
#include "sj.h"
#include <string.h>

#define SJRBF_MAX_OBJ 256

typedef struct {
	SJ_IF *vtbl;                              /* 0x00 */
	Sint32 used;                              /* 0x04 */
	const SJUUID *uuid;                       /* 0x08 */
	Sint32 ndata;                             /* 0x0C data bytes in the buffer */
	Sint32 nfree;                             /* 0x10 free bytes in the buffer */
	Sint32 wrofs;                             /* 0x14 next free (write) position */
	Sint32 rdofs;                             /* 0x18 next data (read) position */
	Uint8 *buf;                               /* 0x1C */
	Sint32 bsize;                             /* 0x20 */
	Sint32 xsize;                             /* 0x24 extra bytes mirroring the buffer start */
	Sint32 flow[2][2];                        /* 0x28 [id][0 = got, 1 = put] byte counters */
	void (*errfunc)(void *obj, Char8 *msg);   /* 0x38 */
	void *errobj;                             /* 0x3C */
} SJRBF_OBJ;

static const Char8 sj_build[] = "\nSJ/GC Ver.6.28 Build:Oct  8 2004 13:32:10\n";

const SJUUID sjrbf_uuid = {
	{0x3B, 0x9A, 0x9E, 0x81, 0x0D, 0xBB, 0x11, 0xD2, 0xA6, 0xBF, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}
};

void SJRBF_Destroy(SJRBF_OBJ *sj);
const SJUUID *SJRBF_GetUuid(SJRBF_OBJ *sj);
void SJRBF_Reset(SJRBF_OBJ *sj);
void SJRBF_GetChunk(SJRBF_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck);
void SJRBF_UngetChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck);
void SJRBF_PutChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck);
Sint32 SJRBF_GetNumData(SJRBF_OBJ *sj, Sint32 id);
Sint32 SJRBF_IsGetChunk(SJRBF_OBJ *sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJRBF_EntryErrFunc(SJRBF_OBJ *sj, void (*func)(void *obj, Char8 *msg), void *obj);
void SJRBF_Error(void *obj, Char8 *msg);

SJ_IF sjrbf_vtbl = {
	NULL,
	NULL,
	NULL,
	(void (*)(SJ))SJRBF_Destroy,
	(const SJUUID *(*)(SJ))SJRBF_GetUuid,
	(void (*)(SJ))SJRBF_Reset,
	(void (*)(SJ, Sint32, Sint32, SJCK *))SJRBF_GetChunk,
	(void (*)(SJ, Sint32, SJCK *))SJRBF_UngetChunk,
	(void (*)(SJ, Sint32, SJCK *))SJRBF_PutChunk,
	(Sint32 (*)(SJ, Sint32))SJRBF_GetNumData,
	(Sint32 (*)(SJ, Sint32, Sint32, Sint32 *))SJRBF_IsGetChunk,
	(void (*)(SJ, void (*)(void *, Char8 *), void *))SJRBF_EntryErrFunc,
};

Sint32 sjrbf_init_cnt = 0;
static SJRBF_OBJ sjrbf_obj[SJRBF_MAX_OBJ];

#define SJRBF_CALL_ERR(sj) \
	if ((sj)->errfunc != NULL) { \
		(sj)->errfunc((sj)->errobj, SJ_ERR_PRM); \
	}

// Byte counters of one side: flow[id][0] = bytes taken with GetChunk, [1] = bytes returned with
// PutChunk (debug/statistics).
Sint32 SJRBF_GetFlowCnt(SJRBF_OBJ *sj, Sint32 id, Sint32 dir)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090229 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090230 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = sj->flow[id][dir];
	}
	SJCRS_Unlock();
	return ret;
}

/* dead-stripped by the linker */
Sint32 SJRBF_GetNumObj(SJRBF_OBJ *sj)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090227 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090228 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = SJRBF_MAX_OBJ;
	}
	SJCRS_Unlock();
	return ret;
}

// The extra (mirror) area size in bytes.
Sint32 SJRBF_GetXtrSize(SJRBF_OBJ *sj)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090225 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090226 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = sj->xsize;
	}
	SJCRS_Unlock();
	return ret;
}

// The ring size in bytes.
Sint32 SJRBF_GetBufSize(SJRBF_OBJ *sj)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090223 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090224 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = sj->bsize;
	}
	SJCRS_Unlock();
	return ret;
}

// The ring buffer base; ADXSJD/AXRNA use it to turn chunk pointers into ring offsets.
void *SJRBF_GetBufPtr(SJRBF_OBJ *sj)
{
	void *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090221 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090222 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->buf;
	}
	SJCRS_Unlock();
	return ret;
}

// Whether a GetChunk of `nbyte` on side `id` would return the full amount; *rbyte gets the amount
// actually available contiguously (bounded by the wrap point + mirror).
Sint32 SJRBF_IsGetChunk(SJRBF_OBJ *sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
	Sint32 n;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090217 : NULL pointer is specified.");
		nbyte = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090218 : Specified handle is invalid.");
		nbyte = 0;
	} else {
		if (id == SJ_CK_FREE) {
			n = sj->bsize - sj->wrofs + sj->xsize;
			if (sj->nfree < n) {
				n = sj->nfree;
			}
			id = nbyte;
			if (n < nbyte) {
				id = n;
			}
		} else if (id == SJ_CK_DATA) {
			n = sj->bsize - sj->rdofs + sj->xsize;
			if (sj->ndata < n) {
				n = sj->ndata;
			}
			id = nbyte;
			if (n < nbyte) {
				id = n;
			}
		} else {
			id = 0;
			SJRBF_CALL_ERR(sj);
		}
		*rbyte = id;
		if (id != nbyte) {
			nbyte = 0;
		} else {
			nbyte = 1;
		}
	}
	SJCRS_Unlock();
	return nbyte;
}

// Gives back the tail of the last GetChunk on side `id` (only the most recent chunk can be
// ungotten: the chunk must end where the side's cursor now stands); rewinds the cursor and the count.
void sjrbf_UngetChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck)
{
	Sint32 ofs;
	Sint32 pos;

	if (sj == NULL) {
		SJERR_CallErr("E2004090215 : NULL pointer is specified.");
		return;
	}
	if (sj->used == 0) {
		SJERR_CallErr("E2004090216 : Specified handle is invalid.");
		return;
	}
	if (sj->bsize == 0) {
		SJERR_CallErr("E2004090220 : Illegal buffer size.");
		return;
	}
	if (ck->len <= 0 || ck->data == NULL) {
		return;
	}
	{
		if (id == SJ_CK_FREE) {
			ofs = (sj->wrofs + sj->bsize - ck->len) % sj->bsize;
			pos = (ck->data - sj->buf) % sj->bsize;
			if (ofs == pos) {
				sj->wrofs = ofs;
				sj->nfree += ck->len;
			} else {
				SJRBF_CALL_ERR(sj);
			}
			sj->flow[SJ_CK_FREE][0] -= ck->len;
		} else if (id == SJ_CK_DATA) {
			ofs = (sj->rdofs + sj->bsize - ck->len) % sj->bsize;
			pos = (ck->data - sj->buf) % sj->bsize;
			if (ofs == pos) {
				sj->rdofs = ofs;
				sj->ndata += ck->len;
			} else {
				SJRBF_CALL_ERR(sj);
			}
			sj->flow[SJ_CK_DATA][0] -= ck->len;
		} else {
			ck->len = 0;
			ck->data = NULL;
			SJRBF_CALL_ERR(sj);
		}
	}
}

// Locked wrapper of sjrbf_UngetChunk (SJCRS: interrupts off).
void SJRBF_UngetChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck)
{
	SJCRS_Lock();
	sjrbf_UngetChunk(sj, id, ck);
	SJCRS_Unlock();
}

// Hands a chunk to the other side: a DATA put makes the bytes readable (mirroring the bytes that
// lie in the first xsize bytes to the tail copy, and bytes written past bsize back to the start), a
// FREE put releases consumed bytes for writing.
void sjrbf_PutChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck)
{
	Sint32 ofs;
	Sint32 n;
	Uint8 *p;

	if (sj == NULL) {
		SJERR_CallErr("E2004090213 : NULL pointer is specified.");
		return;
	}
	if (sj->used == 0) {
		SJERR_CallErr("E2004090214 : Specified handle is invalid.");
		return;
	}
	if (ck->len <= 0 || ck->data == NULL) {
		return;
	}
	{
		if (id == SJ_CK_DATA) {
			/* data written into the first xsize bytes is mirrored behind the buffer end */
			ofs = ck->data - sj->buf;
			if (ofs < sj->xsize) {
				n = sj->xsize - ofs;
				if (ck->len < n) {
					n = ck->len;
				}
				p = (Uint8 *)((Uint32)ofs + (Uint32)sj->buf);
				p = (Uint8 *)((Uint32)sj->bsize + (Uint32)p);
				memcpy(p, ck->data, n);
			}
			/* data written into the extra area is mirrored to the buffer start */
			ofs = (ck->data - sj->buf) + ck->len;
			if (ofs > sj->bsize) {
				n = ofs - sj->bsize;
				if (ck->len < n) {
					n = ck->len;
				}
				memcpy(sj->buf, sj->buf + (ofs - n), n);
			}
			sj->ndata += ck->len;
			sj->flow[SJ_CK_DATA][1] += ck->len;
		} else if (id == SJ_CK_FREE) {
			sj->nfree += ck->len;
			sj->flow[SJ_CK_FREE][1] += ck->len;
		} else {
			ck->len = 0;
			ck->data = NULL;
			SJRBF_CALL_ERR(sj);
		}
	}
}

// Locked wrapper of sjrbf_PutChunk.
void SJRBF_PutChunk(SJRBF_OBJ *sj, Sint32 id, SJCK *ck)
{
	SJCRS_Lock();
	sjrbf_PutChunk(sj, id, ck);
	SJCRS_Unlock();
}

// Takes up to `nbyte` contiguous bytes from side `id` (FREE = writable space at wrofs, DATA =
// readable bytes at rdofs); contiguous means up to the ring end plus the mirror area. Advances the
// side's cursor and count; ck->len may be less than asked.
static void sjrbf_GetChunk(SJRBF_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
	Sint32 n;

	if (sj == NULL) {
		SJERR_CallErr("E2004090211 : NULL pointer is specified.");
		return;
	}
	if (sj->used == 0) {
		SJERR_CallErr("E2004090212 : Specified handle is invalid.");
		return;
	}
	if (sj->bsize == 0) {
		SJERR_CallErr("E2004090219 : Illegal buffer size.");
		return;
	}
	if (id == SJ_CK_FREE) {
		n = sj->bsize - sj->wrofs + sj->xsize;
		if (sj->nfree < n) {
			n = sj->nfree;
		}
		ck->len = n;
		if (ck->len < nbyte) {
			nbyte = ck->len;
		}
		ck->len = nbyte;
		ck->data = sj->buf + sj->wrofs;
		sj->wrofs = (sj->wrofs + ck->len) % sj->bsize;
		sj->nfree -= ck->len;
		sj->flow[SJ_CK_FREE][0] += ck->len;
	} else if (id == SJ_CK_DATA) {
		n = sj->bsize - sj->rdofs + sj->xsize;
		if (sj->ndata < n) {
			n = sj->ndata;
		}
		ck->len = n;
		if (ck->len < nbyte) {
			nbyte = ck->len;
		}
		ck->len = nbyte;
		ck->data = sj->buf + sj->rdofs;
		sj->rdofs = (sj->rdofs + ck->len) % sj->bsize;
		sj->ndata -= ck->len;
		sj->flow[SJ_CK_DATA][0] += ck->len;
	} else {
		ck->len = 0;
		ck->data = NULL;
		SJRBF_CALL_ERR(sj);
	}
}

// Locked wrapper of sjrbf_GetChunk; the main primitive every producer/consumer in the pipeline uses.
void SJRBF_GetChunk(SJRBF_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
	SJCRS_Lock();
	sjrbf_GetChunk(sj, id, nbyte, ck);
	SJCRS_Unlock();
}

// Bytes available on side `id` (DATA readable, FREE writable) in the whole ring.
Sint32 SJRBF_GetNumData(SJRBF_OBJ *sj, Sint32 id)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090209 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090210 : Specified handle is invalid.");
		ret = 0;
	} else if (id == SJ_CK_DATA) {
		ret = sj->ndata;
	} else if (id == SJ_CK_FREE) {
		ret = sj->nfree;
	} else {
		SJRBF_CALL_ERR(sj);
		ret = 0;
	}
	SJCRS_Unlock();
	return ret;
}

// Empties the ring: all bytes free, both cursors at 0, counters cleared.
static void sjrbf_Reset(SJRBF_OBJ *sj)
{
	if (sj == NULL) {
		SJERR_CallErr("E2004090207 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090208 : Specified handle is invalid.");
	} else {
		sj->ndata = 0;
		sj->nfree = sj->bsize;
		sj->wrofs = 0;
		sj->rdofs = 0;
		sj->flow[0][0] = 0;
		sj->flow[0][1] = 0;
		sj->flow[1][0] = 0;
		sj->flow[1][1] = 0;
	}
}

// Locked wrapper of sjrbf_Reset (ADXT_Stop / ADXRNA_SetPlaySw(0) reset their rings this way).
void SJRBF_Reset(SJRBF_OBJ *sj)
{
	SJCRS_Lock();
	sjrbf_Reset(sj);
	SJCRS_Unlock();
}

// Replaces the per-joint error callback (default SJRBF_Error).
void SJRBF_EntryErrFunc(SJRBF_OBJ *sj, void (*func)(void *obj, Char8 *msg), void *obj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090205 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090206 : Specified handle is invalid.");
	} else {
		sj->errfunc = func;
		sj->errobj = obj;
	}
	SJCRS_Unlock();
}

// The ring-buffer joint's class UUID.
const SJUUID *SJRBF_GetUuid(SJRBF_OBJ *sj)
{
	const SJUUID *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090203 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090204 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->uuid;
	}
	SJCRS_Unlock();
	return ret;
}

// Clears the object (the caller owns the buffer memory).
void SJRBF_Destroy(SJRBF_OBJ *sj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090201 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090202 : Specified handle is invalid.");
	} else {
		memset(sj, 0, sizeof(SJRBF_OBJ));
		sj->used = 0;
	}
	SJCRS_Unlock();
}

// Index of the first unused slot (256 = full).
static Sint32 sjrbf_SearchFreeObj(void)
{
	Sint32 i;

	for (i = 0; i < SJRBF_MAX_OBJ; i++) {
		if (sjrbf_obj[i].used == 0) {
			break;
		}
	}
	return i;
}

// Creates a ring-buffer joint over the caller's `buf` (`bsize` bytes + `xsize` mirror bytes after it),
// empty. Every ADX/Sofdec buffer (file ring, decoder output, ARAM ring, MPEG input) is one of these.
SJ SJRBF_Create(void *buf, Sint32 bsize, Sint32 xsize)
{
	SJRBF_OBJ *sj;
	Sint32 i;

	SJCRS_Lock();
	i = sjrbf_SearchFreeObj();
	if (i == SJRBF_MAX_OBJ) {
		sj = NULL;
	} else {
		sj = &sjrbf_obj[i];
		sj->used = 1;
		sj->vtbl = &sjrbf_vtbl;
		sj->buf = buf;
		sj->bsize = bsize;
		sj->xsize = xsize;
		sj->uuid = &sjrbf_uuid;
		sj->errfunc = SJRBF_Error;
		sj->errobj = sj;
		sjrbf_Reset(sj);
	}
	SJCRS_Unlock();
	return (SJ)sj;
}

// Clears the object table on the last release.
void SJRBF_Finish(void)
{
	SJCRS_Lock();
	if (--sjrbf_init_cnt == 0) {
		memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
	}
	SJCRS_Unlock();
}

// Clears the object table on the first init (called by ADXT_Init).
void SJRBF_Init(void)
{
	SJCRS_Lock();
	if (sjrbf_init_cnt == 0) {
		memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
	}
	sjrbf_init_cnt++;
	SJCRS_Unlock();
}

// Default per-joint error callback: reports "SJRBF Error" through SJERR.
void SJRBF_Error(void *obj, Char8 *msg)
{
	SJERR_CallErr("SJRBF Error");
}
