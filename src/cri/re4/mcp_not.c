/* CRI MEM_Copy (mcp_not.c): the byte copy every Sofdec unit uses, a memcpy wrapper on this platform. */
#include "cri_xpt.h"
#include <string.h>

// memcpy wrapper.
void MEM_Copy(void *dst, const void *src, Uint32 nbytes)
{
	memcpy(dst, src, nbytes);
}
