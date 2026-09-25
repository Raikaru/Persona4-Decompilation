/* CRI Sofdec memory input driver (sfd_mem.c, SFD_tr_in_mem): transfer driver slot 0 of every player
 * in this game. It has no data source of its own: the input buffer (SFBUF ring 0/1/2) is supplied
 * through a stream joint (SFD_SetSupplySj), so the driver only marks the buffer prepared each server
 * pass and forwards GetWrite/AddWrite to the ring for callers that push data by hand. */
#include "cri_xpt.h"

typedef struct {
	Uint8 pad[0x1F44];
	void *sfbuf;
} SFD_OBJ;

typedef struct {
	Sint32 (*Init)();
	Sint32 (*Finish)();
	Sint32 (*ExecServer)();
	Sint32 (*Create)();
	Sint32 (*Destroy)();
	Sint32 (*Standby)();
	Sint32 (*Start)();
	Sint32 (*Stop)();
	Sint32 (*Pause)();
	Sint32 (*GetWrite)();
	Sint32 (*AddWrite)();
	Sint32 (*GetRead)();
	Sint32 (*AddRead)();
	Sint32 (*Seek)();
} SFD_TR_IF;

extern void SFLIB_SetErr(void *sfd, Sint32 code);
// The prep-flag helper still exports only its retail address name.
#define SFBUF_SetPrepFlg func_00515940
extern Sint32 SFBUF_RingAddWrite(SFD_OBJ *sfd, void *sfbuf, Sint32 a, Sint32 b);
extern Sint32 SFBUF_RingGetWrite(SFD_OBJ *sfd, void *sfbuf, void *a);
extern void SFBUF_SetPrepFlg(SFD_OBJ *sfd, void *sfbuf, Sint32 flg);

// No seek support (0).
Sint32 SFMEM_Seek(void)
{
	return 0;
}

// Not an output driver: error 0xFF000501.
// FUN_00517E70
Sint32 SFMEM_AddRead(void *sfd)
{
	SFLIB_SetErr(sfd, 0xFF000501);
}

// Not an output driver: error 0xFF000501.
// FUN_00517E90
Sint32 SFMEM_GetRead(void *sfd)
{
	SFLIB_SetErr(sfd, 0xFF000501);
}

// Commits `a` bytes written into the input ring (SFBUF_RingAddWrite).
// FUN_00517E48
Sint32 SFMEM_AddWrite(SFD_OBJ *sfd, Sint32 a, Sint32 b)
{
	return SFBUF_RingAddWrite(sfd, sfd->sfbuf, a, b);
}

// Writable region of the input ring (SFBUF_RingGetWrite).
// FUN_00517E28
Sint32 SFMEM_GetWrite(SFD_OBJ *sfd, void *a)
{
	return SFBUF_RingGetWrite(sfd, sfd->sfbuf, a);
}

// Nothing to do.
Sint32 SFMEM_Pause(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Stop(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Start(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Standby(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Destroy(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Create(void)
{
	return 0;
}

// Each pass: the input buffer counts as prepared (the stream joint fills it asynchronously).
// FUN_00517DD0
Sint32 SFMEM_ExecServer(SFD_OBJ *sfd)
{
	SFBUF_SetPrepFlg(sfd, sfd->sfbuf, 1);
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Finish(void)
{
	return 0;
}

// Nothing to do.
Sint32 SFMEM_Init(void)
{
	return 0;
}

const SFD_TR_IF SFD_tr_in_mem = {
	SFMEM_Init,
	SFMEM_Finish,
	SFMEM_ExecServer,
	SFMEM_Create,
	SFMEM_Destroy,
	SFMEM_Standby,
	SFMEM_Start,
	SFMEM_Stop,
	SFMEM_Pause,
	SFMEM_GetWrite,
	SFMEM_AddWrite,
	SFMEM_GetRead,
	SFMEM_AddRead,
	SFMEM_Seek,
};
