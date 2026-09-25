/* CRI ring-buffer writable and readable chunk adapters. */
#include "cri_xpt.h"
#include "sfd.h"

extern Sint32 func_00514cc0(SFD sfd, Sint32 n, SFBUF_RINF *inf, Sint32 mode);

// FUN_00514C90
Sint32 SFBUF_RingGetWrite(SFD sfd, Sint32 n, SFBUF_RINF *inf)
{
	return func_00514cc0(sfd, n, inf, 0);
}

// FUN_00514CA8
Sint32 SFBUF_RingGetRead(SFD sfd, Sint32 n, SFBUF_RINF *inf)
{
	return func_00514cc0(sfd, n, inf, 1);
}
