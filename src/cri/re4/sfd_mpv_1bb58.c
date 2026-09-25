/* Sofdec MPV 64-bit input-byte accounting at retail 0051BB58. */
#include "cri_xpt.h"

typedef struct SFD_TAG *SFD;

extern void func_005152e0(SFD sfd, Sint32 n, Sint32 nbyte);
// FUN_0051BB58
void func_0051bb58(SFD sfd, Sint32 n)
{
	func_005152e0(sfd, *(Sint32 *)((Uint8 *)sfd + 0x1FC8), n);
	*(Sint64 *)((Uint8 *)sfd + 0x9A8) += n;
}

