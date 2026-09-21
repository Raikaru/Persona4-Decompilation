/* CRI Stream Joint: universal joint. Everything but Init/Finish was dead-stripped by the linker;
 * the other bodies only reproduce the .rodata string pool. */
#include "cri_xpt.h"
#include "sj.h"
#include <string.h>

#define SJUNI_MAX_OBJ 32

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
	Uint8 pad[0x60 - 0x24];
} SJUNI_OBJ;

static const SJUUID sjuni_uuid = {
	{0x2E, 0x53, 0x4F, 0xA3, 0xAF, 0x97, 0x11, 0xD2, 0xA5, 0x27, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC}
};

static Sint32 sjuni_init_cnt = 0;
SJUNI_OBJ sjuni_obj[SJUNI_MAX_OBJ];

extern SJ_IF sjuni_vtbl;
void SJUNI_Error(void *obj, Char8 *msg);

#define SJUNI_CALL_ERR(sj) \
	if ((sj)->errfunc != NULL) { \
		(sj)->errfunc((sj)->errobj, SJ_ERR_PRM); \
	}

// Dead: buffer size.
Sint32 SJUNI_GetBufSize(SJUNI_OBJ *sj)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090281 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090282 : Specified handle is invalid.");
		ret = 0;
	} else {
		ret = sj->bsize;
	}
	SJCRS_Unlock();
	return ret;
}

// Dead: buffer base.
void *SJUNI_GetBufPtr(SJUNI_OBJ *sj)
{
	void *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090279 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090280 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->buf;
	}
	SJCRS_Unlock();
	return ret;
}

// Dead: same semantics as the memory joint (read-only).
Sint32 SJUNI_IsGetChunk(SJUNI_OBJ *sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
	Sint32 ret;
	Sint32 n;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090277 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090278 : Specified handle is invalid.");
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
			SJUNI_CALL_ERR(sj);
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

// Dead: rewind the read cursor.
void SJUNI_UngetChunk(SJUNI_OBJ *sj, Sint32 id, SJCK *ck)
{
	Sint32 ofs;
	Sint32 ndata;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090275 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090276 : Specified handle is invalid.");
	} else if (ck->len > 0 && ck->data != NULL) {
		if (id == SJ_CK_FREE) {
			SJUNI_CALL_ERR(sj);
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
				SJUNI_CALL_ERR(sj);
			}
		} else {
			ck->len = 0;
			ck->data = NULL;
			SJUNI_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// Dead: no-op for FREE/DATA.
void SJUNI_PutChunk(SJUNI_OBJ *sj, Sint32 id, SJCK *ck)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090273 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090274 : Specified handle is invalid.");
	} else if (ck->len > 0 && ck->data != NULL) {
		if (id != SJ_CK_FREE && id != SJ_CK_DATA) {
			ck->len = 0;
			ck->data = NULL;
			SJUNI_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// Dead: next unread bytes.
void SJUNI_GetChunk(SJUNI_OBJ *sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090271 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090272 : Specified handle is invalid.");
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
			SJUNI_CALL_ERR(sj);
		}
	}
	SJCRS_Unlock();
}

// Dead: unread bytes.
Sint32 SJUNI_GetNumData(SJUNI_OBJ *sj, Sint32 id)
{
	Sint32 ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090269 : NULL pointer is specified.");
		ret = 0;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090270 : Specified handle is invalid.");
		ret = 0;
	} else if (id == SJ_CK_DATA) {
		ret = sj->ndata;
	} else if (id == SJ_CK_FREE) {
		ret = 0;
	} else {
		SJUNI_CALL_ERR(sj);
		ret = 0;
	}
	SJCRS_Unlock();
	return ret;
}

// Dead: rewind.
static void sjuni_Reset(SJUNI_OBJ *sj)
{
	if (sj == NULL) {
		SJERR_CallErr("E2004090267 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090268 : Specified handle is invalid.");
	} else {
		sj->ndata = sj->bsize;
		sj->rdofs = 0;
	}
}

// Dead: locked rewind.
void SJUNI_Reset(SJUNI_OBJ *sj)
{
	SJCRS_Lock();
	sjuni_Reset(sj);
	SJCRS_Unlock();
}

// Dead: error callback.
void SJUNI_EntryErrFunc(SJUNI_OBJ *sj, void (*func)(void *obj, Char8 *msg), void *obj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090265 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090266 : Specified handle is invalid.");
	} else {
		sj->errfunc = func;
		sj->errobj = obj;
	}
	SJCRS_Unlock();
}

// Dead: class UUID.
const SJUUID *SJUNI_GetUuid(SJUNI_OBJ *sj)
{
	const SJUUID *ret;

	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090263 : NULL pointer is specified.");
		ret = NULL;
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090264 : Specified handle is invalid.");
		ret = NULL;
	} else {
		ret = sj->uuid;
	}
	SJCRS_Unlock();
	return ret;
}

// Dead: clear the object.
void SJUNI_Destroy(SJUNI_OBJ *sj)
{
	SJCRS_Lock();
	if (sj == NULL) {
		SJERR_CallErr("E2004090261 : NULL pointer is specified.");
	} else if (sj->used == 0) {
		SJERR_CallErr("E2004090262 : Specified handle is invalid.");
	} else {
		memset(sj, 0, sizeof(SJUNI_OBJ));
		sj->used = 0;
	}
	SJCRS_Unlock();
}

// Dead: first unused slot.
static Sint32 sjuni_SearchFreeObj(void)
{
	Sint32 i;

	for (i = 0; i < SJUNI_MAX_OBJ; i++) {
		if (sjuni_obj[i].used == 0) {
			break;
		}
	}
	return i;
}

// Dead: create over a buffer.
SJ SJUNI_Create(void *buf, Sint32 bsize)
{
	SJUNI_OBJ *sj;
	Sint32 i;

	SJCRS_Lock();
	i = sjuni_SearchFreeObj();
	if (i == SJUNI_MAX_OBJ) {
		sj = NULL;
	} else {
		sj = &sjuni_obj[i];
		sj->used = 1;
		sj->vtbl = &sjuni_vtbl;
		sj->buf = buf;
		sj->bsize = bsize;
		sj->uuid = &sjuni_uuid;
		sj->errfunc = SJUNI_Error;
		sj->errobj = sj;
		sjuni_Reset(sj);
	}
	SJCRS_Unlock();
	return (SJ)sj;
}

// Clears the table on the last release (called by ADXT_Finish).
void SJUNI_Finish(void)
{
	SJCRS_Lock();
	if (--sjuni_init_cnt == 0) {
		memset(sjuni_obj, 0, sizeof(sjuni_obj));
	}
	SJCRS_Unlock();
}

// Clears the table on the first init (called by ADXT_Init).
void SJUNI_Init(void)
{
	SJCRS_Lock();
	if (sjuni_init_cnt == 0) {
		memset(sjuni_obj, 0, sizeof(sjuni_obj));
	}
	sjuni_init_cnt++;
	SJCRS_Unlock();
}

// Dead: default error callback.
void SJUNI_Error(void *obj, Char8 *msg)
{
	SJERR_CallErr("SJUNI Error");
}
