/* Sofdec MPV read-chunk fetch at retail 0051B768. */
#include "cri_xpt.h"

typedef struct SFD_TAG *SFD;
typedef struct {
	Uint8 *data;
	Sint32 len;
} SJCK;

extern Sint32 func_00514ca8(SFD sfd, Sint32 n, void *inf);
// FUN_0051B768
void func_0051b768(SFD sfd, SJCK *out)
{
	Uint8 inf[0x20];

	if (func_00514ca8(sfd, *(Sint32 *)((Uint8 *)sfd + 0x1FC8), inf) != 0) {
		out->data = NULL;
		out->len = 0;
	} else {
		out->data = ((SJCK *)inf)->data;
		out->len = ((SJCK *)inf)->len;
	}
}

