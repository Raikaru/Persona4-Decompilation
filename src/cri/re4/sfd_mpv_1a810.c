/* Sofdec sequence-header decode and output-buffer flag query. */
typedef unsigned char Uint8;
typedef unsigned int Uint32;
typedef signed int Sint32;
typedef struct SFD_TAG *SFD;
typedef struct {
	void *mpv;
	Uint8 pad04[0x74 - 0x04];
	Sint32 picstat;
	Sint32 dlmmask;
} SFMPV_WORK;
typedef struct {
	Uint8 pad[0x1FC0];
	SFMPV_WORK *mpv_wk;
} SFD_MPV_VIEW;
typedef struct {
	Uint8 *data;
	Sint32 len;
} SJCK;
#define NULL 0

extern Sint32 func_00525098(SFD sfd, Sint32 id);
extern Sint32 func_00505360(void *mpv, SJCK *ck, Sint32 *used);
extern Uint32 func_005159a0(SFD sfd, Sint32 buf);

// FUN_0051A810
void sfmpv_DecUsrHdr(SFD sfd)
{
	SFMPV_WORK *wk = ((SFD_MPV_VIEW *)sfd)->mpv_wk;
	void *mpv = wk->mpv;
	SJCK ck;
	Sint32 used;

	ck.data = (Uint8 *)func_00525098(sfd, 0x5D);
	ck.len = func_00525098(sfd, 0x5E);
	if (ck.data == NULL || ck.len == 0) {
		return;
	}
	if (wk->dlmmask != 0xC0) {
		return;
	}
	if (func_00505360(mpv, &ck, &used) != 0) {
		return;
	}
	wk->picstat = 2;
	wk->dlmmask = 0xC8;
}

// FUN_0051A8B0
Uint32 func_0051a8b0(SFD sfd)
{
	return func_005159a0(sfd, *(Sint32 *)((Uint8 *)sfd + 0x1FCC));
}
