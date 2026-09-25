/* Sofdec MPV input-ring end flag at retail 0051BBE8. */
#include "cri_xpt.h"

typedef struct SFD_TAG *SFD;

extern Sint32 func_005159a0(SFD sfd, Sint32 buf);

// FUN_0051BBE8
Sint32 func_0051bbe8(SFD sfd)
{
	return func_005159a0(sfd, *(Sint32 *)((Uint8 *)sfd + 0x1FC8));
}
