/* P4 Sofdec frame count and user-SJ selection; SFD+0x1FC0 holds the video work. */
typedef unsigned char Uint8;
typedef unsigned int Uint32;
typedef signed int Sint32;
typedef struct SFD_TAG *SFD;
typedef struct {
	void *mpv;
} SFMPV_WORK;
typedef struct {
	Uint8 pad[0x1FC0];
	SFMPV_WORK *mpv_wk;
} SFD_MPV_VIEW;
#define NULL 0

extern Sint32 func_00517cf0(SFD sfd);
extern Sint32 func_00517ad0(void *sfd, Sint32 code);
extern Sint32 func_0051f608(SFD sfd);
extern void func_00505078(void *mpv, Sint32 p1, Uint32 p2, Uint32 p3, Uint32 p4);

// FUN_0051A378: frame count out-param; CheckHn failure reports 0xFF000182.
Sint32 SFD_GetNumFrm(SFD sfd, Sint32 *num)
{
	*num = 0;
	if (func_00517cf0(sfd) != 0) {
		return func_00517ad0(NULL, 0xFF000182);
	}
	*num = func_0051f608(sfd);
	return 0;
}

// FUN_0051A3E8: CheckHn-guarded MPV user-SJ store; failure is 0xFF000184.
Sint32 SFD_SetVideoUsrSj(SFD sfd, Sint32 p1, Uint32 p2, Uint32 p3, Uint32 p4)
{
	SFMPV_WORK *wk;

	if (func_00517cf0(sfd) != 0) {
		return func_00517ad0(NULL, 0xFF000184);
	}
	wk = ((SFD_MPV_VIEW *)sfd)->mpv_wk;
	func_00505078(wk->mpv, p1, p2, p3, p4);
	return 0;
}

