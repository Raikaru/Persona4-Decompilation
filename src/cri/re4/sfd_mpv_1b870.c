/* Sofdec MPV concatenated-stream end-code handler at retail 0051B870. */
#include "cri_xpt.h"

typedef struct SFD_TAG *SFD;
typedef void *SJ;

extern Sint32 sfmpv_ConcatSub(SFD sfd);
extern void func_0051ba98(SFD sfd, SJ sj);
// FUN_0051B870
Sint32 func_0051b870(SFD sfd, SJ sj)
{
	if (sfmpv_ConcatSub(sfd) == -1) {
		return -1;
	}
	func_0051ba98(sfd, sj);
	return 0;
}

