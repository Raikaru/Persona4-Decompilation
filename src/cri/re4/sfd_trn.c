/* CRI Sofdec transfer driver table (sfd_trn.c, SFTRN): the 9 driver slots of a handle (0 input,
 * 1 system demux, 2 video decoder, 3 audio decoder, 4/5 filters, 6 video out, 7 audio out, 8 user
 * output), each an SFD_TR_IF function table, and the wiring of the 8 SFBUF buffers between them
 * (buffer n: in_tr writes, out_tr reads). SFTRN_CallTrSetup / CallTrtTrif dispatch the driver
 * functions by index. */
#include "cri_xpt.h"
#include "sfd.h"

#define SFTRN_TRIF_NUM 15

// Whether driver slot `strm` has a driver (0 input, 1 system, 2 video, 3 audio, 6 video out, 7 audio
// out, 8 user output).
Sint32 SFTRN_IsSetup(SFD sfd, Sint32 strm)
{
	return sfd->tr[strm].trif != NULL;
}

// The driver's "stream ended" flag.
Sint32 SFTRN_GetTermFlg(SFD sfd, Sint32 strm)
{
	return sfd->tr[strm].termflg;
}

// Sets the driver's "stream ended" flag.
void SFTRN_SetTermFlg(SFD sfd, Sint32 strm, Sint32 flg)
{
	sfd->tr[strm].termflg = flg;
}

// The driver's "prepared" flag.
Sint32 SFTRN_GetPrepFlg(SFD sfd, Sint32 strm)
{
	return sfd->tr[strm].prepflg;
}

// Sets the driver's "prepared" flag.
void SFTRN_SetPrepFlg(SFD sfd, Sint32 strm, Sint32 flg)
{
	sfd->tr[strm].prepflg = flg;
}

// Calls function `fn` of driver `strm` (SFD_TR_IF index: 6 Start, 7 Stop, 9 GetWrite, 10 AddWrite,
// 11 GetRead, 12 AddRead) with two arguments; 0 when the slot is empty.
Sint32 SFTRN_CallTrtTrif(SFD sfd, Sint32 strm, Sint32 fn, Sint32 a, Sint32 b)
{
	SFD_TR_FUNC *trif;

	trif = sfd->tr[strm].trif;
	if (trif == NULL) {
		return 0;
	}
	return trif[fn](sfd, a, b, 0);
}

// Calls function `fn` (2 ExecServer, 3 Create, 4 Destroy) on every installed driver in slot order,
// stopping at the first error.
Sint32 SFTRN_CallTrSetup(SFD sfd, Sint32 fn)
{
	Sint32 i;
	SFD_TR *tr;
	Sint32 ret;

	ret = 0;
	tr = sfd->tr;
	for (i = 0; i < SFD_TR_NUM; i++, tr++) {
		if (tr->trif != NULL) {
			ret = tr->trif[fn](sfd, 0, 0, 0);
			if (ret != 0) {
				break;
			}
		}
	}
	return ret;
}

// Wires the buffers of a program-stream layout: input -> buf 0 -> MPS demux (tr 1) -> buf 1 -> video
// decoder (tr 2) -> buf 3 -> [video filter tr 4 -> buf 5 ->] video out (tr 6); tr 1 -> buf 2 -> audio
// decoder (tr 3) -> buf 4 -> [audio filter tr 5 -> buf 6 ->] audio out (tr 7); tr 1 -> buf 7 -> user
// output (tr 8). Disables video/audio (cond 5/6) when the decoder is absent.
void sftrn_BuildSystem(SFD sfd, SFD_TR_FUNC **tbl)
{
	sfd->buf[0].out_tr = 1;
	sfd->tr[1].bufin = 0;
	if (tbl[2] != NULL) {
		sfd->tr[1].bufout = 1;
		sfd->buf[1].in_tr = 1;
		sfd->buf[1].out_tr = 2;
		sfd->tr[2].bufin = 1;
		sfd->tr[2].bufout = 3;
		sfd->buf[3].in_tr = 2;
		if (tbl[4] != NULL) {
			sfd->buf[3].out_tr = 4;
			sfd->tr[4].bufin = 3;
			sfd->tr[4].bufout = 5;
			sfd->buf[5].in_tr = 4;
			sfd->buf[5].out_tr = 6;
			sfd->tr[6].bufin = 5;
		} else {
			sfd->buf[3].out_tr = 6;
			sfd->tr[6].bufin = 3;
		}
	} else {
		SFSET_SetCond(sfd, 5, 0);
		sfd->cond_def[5] = 0;
	}
	if (tbl[3] != NULL) {
		sfd->tr[1].bufout2 = 2;
		sfd->buf[2].in_tr = 1;
		sfd->buf[2].out_tr = 3;
		sfd->tr[3].bufin = 2;
		sfd->tr[3].bufout = 4;
		sfd->buf[4].in_tr = 3;
		if (tbl[5] != NULL) {
			sfd->buf[4].out_tr = 5;
			sfd->tr[5].bufin = 4;
			sfd->tr[5].bufout = 6;
			sfd->buf[6].in_tr = 5;
			sfd->buf[6].out_tr = 7;
			sfd->tr[7].bufin = 6;
		} else {
			sfd->buf[4].out_tr = 7;
			sfd->tr[7].bufin = 4;
		}
	} else {
		SFSET_SetCond(sfd, 6, 0);
		sfd->cond_def[6] = 0;
	}
	if (tbl[8] != NULL) {
		sfd->tr[1].bufout3 = 7;
		sfd->buf[7].in_tr = 1;
		sfd->buf[7].out_tr = 8;
		sfd->tr[8].bufin = 7;
	}
}

// Chooses the wiring from the driver table: with a system driver the full demux graph, else an
// elementary video-only, audio-only or user-output-only chain. -1 when no usable driver exists.
static Sint32 sftrn_BuildAll(SFD sfd, SFD_TR_FUNC **tbl)
{
	if (tbl[1] != NULL) {
		sfd->tr[0].bufout = 0;
		sfd->buf[0].in_tr = 0;
		sftrn_BuildSystem(sfd, tbl);
	} else if (tbl[2] != NULL) {
		sfd->tr[0].bufout = 1;
		sfd->buf[1].in_tr = 0;
		sfd->buf[1].out_tr = 2;
		sfd->tr[2].bufin = 1;
		sfd->tr[2].bufout = 3;
		sfd->buf[3].in_tr = 2;
		if (tbl[4] != NULL) {
			sfd->buf[3].out_tr = 4;
			sfd->tr[4].bufin = 3;
			sfd->tr[4].bufout = 5;
			sfd->buf[5].in_tr = 4;
			sfd->buf[5].out_tr = 6;
			sfd->tr[6].bufin = 5;
		} else {
			sfd->buf[3].out_tr = 6;
			sfd->tr[6].bufin = 3;
		}
		SFSET_SetCond(sfd, 6, 0);
		sfd->cond_def[6] = 0;
	} else if (tbl[3] != NULL) {
		sfd->tr[0].bufout = 2;
		sfd->buf[2].in_tr = 0;
		sfd->buf[2].out_tr = 3;
		sfd->tr[3].bufin = 2;
		sfd->tr[3].bufout = 4;
		sfd->buf[4].in_tr = 3;
		if (tbl[5] != NULL) {
			sfd->buf[4].out_tr = 5;
			sfd->tr[5].bufin = 4;
			sfd->tr[5].bufout = 6;
			sfd->buf[6].in_tr = 5;
			sfd->buf[6].out_tr = 7;
			sfd->tr[7].bufin = 6;
		} else {
			sfd->buf[4].out_tr = 7;
			sfd->tr[7].bufin = 4;
		}
		SFSET_SetCond(sfd, 5, 0);
		sfd->cond_def[5] = 0;
	} else if (tbl[8] != NULL) {
		sfd->tr[0].bufout = 7;
		sfd->buf[7].in_tr = 0;
		sfd->buf[7].out_tr = 8;
		sfd->tr[8].bufin = 7;
		SFSET_SetCond(sfd, 6, 0);
		SFSET_SetCond(sfd, 5, 0);
		sfd->cond_def[6] = 0;
		sfd->cond_def[5] = 0;
	} else {
		return -1;
	}
	return 0;
}

// Fills the 9 driver slots from the creation table (no handle, flags cleared, buffer ids 8 = none)
// and wires the buffers (error 0xFF000302 when nothing can be built).
Sint32 SFTRN_InitHn(SFD sfd, SFD_TR *tr, SFTRN_PRM *prm)
{
	SFD_TR_FUNC **trif;
	SFD_TR_FUNC **tbl;
	SFD_TR_FUNC *f;
	Sint32 i;

	tbl = prm->trif_tbl;
	trif = tbl;
	for (i = 0; i < SFD_TR_NUM; i++, tr++, trif++) {
		tr->hn = NULL;
		f = *trif;
		tr->termflg = 0;
		tr->prepflg = 0;
		tr->trif = f;
		tr->bufin = 8;
		tr->bufout = 8;
		tr->bufout2 = 8;
		tr->bufout3 = 8;
		tr->x20 = -1;
	}
	if (sftrn_BuildAll(sfd, tbl) != 0) {
		return SFLIB_SetErr(sfd, 0xFF000302);
	}
	return 0;
}

// Runs Init on every driver interface of the table until a NULL entry.
static Sint32 sftrn_CallInit(SFD_TR_IF **p, Sint32 ret)
{
	SFD_TR_IF *trif;
	Sint32 i;

	for (i = 0; i < SFTRN_TRIF_NUM; i++, p++) {
		trif = *p;
		if (trif == NULL) {
			break;
		}
		ret = trif->Init(0, 0, 0, 0);
		if (ret != 0) {
			break;
		}
	}
	return ret;
}

// Library init: copies the driver table into the library work and initialises the drivers.
// FUN_00527180
Sint32 SFTRN_Init(SFTRN_TRIF_TBL *dst, SFTRN_TRIF_TBL *src)
{
	Sint32 ret;

	ret = 0;
	*dst = *src;
	ret = sftrn_CallInit(src->tbl, ret);
	return ret;
}
