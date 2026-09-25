/* CRI ring-buffer writable and readable byte-commit adapters. */
#include "cri_xpt.h"
#include "sfd.h"

extern Sint32 func_00514d98(SFD sfd, Sint32 n, Sint32 nbyte, Sint32 mode);

// FUN_00514D68
Sint32 SFBUF_RingAddWrite(SFD sfd, Sint32 n, Sint32 nbyte, Sint32 rsv)
{
	return func_00514d98(sfd, n, nbyte, 0);
}

// FUN_00514D80
Sint32 SFBUF_RingAddRead(SFD sfd, Sint32 n, Sint32 nbyte)
{
	return func_00514d98(sfd, n, nbyte, 1);
}
