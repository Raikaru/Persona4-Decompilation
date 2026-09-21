#ifndef _SJR_CLT_H_
#define _SJR_CLT_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>

/* P4: measured and REVERTED, recorded so nobody repeats it. Retail's
 * SJUNI_CreateRmt sends `addiu $a0, $zero, 0x20` at 0x004EFBFC, and the
 * eleven calls that follow use 0x20..0x2A consecutively - exactly the span
 * from UNI_CREATE to FINISH, so shifting the whole enumeration down by two
 * looks right and does fix SJUNI_CreateRmt. It costs more than it buys:
 * byte-exact functions fell 317 -> 309 and the name-driven measure 177 ->
 * 175, so some other caller needs the numbering as it stands. The command
 * space is evidently not one flat enumeration in 9.44 and needs more
 * evidence than one function's immediate. */
typedef enum 
{
	SJRMT_RBF_CREATE = 32,
	SJRMT_MEM_CREATE = 33,
	SJRMT_UNI_CREATE = 34,
	SJRMT_DESTROY = 35,
	SJRMT_GET_UUID = 36,
	SJRMT_RESET = 37,
	SJRMT_GET_CHUNK = 38,
	SJRMT_UNGET_CHUNK = 39,
	SJRMT_PUT_CHUNK = 40,
	SJRMT_GET_NUM_DATA = 41,
	SJRMT_IS_GET_CHUNK = 42,
	SJRMT_INIT = 43,
	SJRMT_FINISH = 44,
	SJRMT_CMD_END = 45
} SJRMT_CMD;

SJ SJMEM_CreateRmt(Sint8 *data, Sint32 dtsize);
SJ SJRBF_CreateRmt(Sint8 *buf, Sint32 bsize, Sint32 xsize);
void SJRMT_Destroy(SJ sj);
void SJRMT_Finish(void);
void SJRMT_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJRMT_GetNumData(SJ sj, Sint32 id);
const UUID* SJRMT_GetUuid(SJ sj);
void SJRMT_Init(void);
Sint32 SJRMT_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJRMT_PutChunk(SJ sj, Sint32 id, SJCK *ck);
void SJRMT_Reset(SJ sj);
void SJRMT_UngetChunk(SJ sj, Sint32 id, SJCK *ck);
SJ SJUNI_CreateRmt(Sint32 mode, Sint8 *wk, Sint32 wksize);

#endif
