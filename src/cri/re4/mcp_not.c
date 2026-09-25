/* CRI MEM_Copy (mcp_not.c): the byte copy every Sofdec unit uses, a memcpy wrapper on this platform. */
#include "cri_xpt.h"
#include <string.h>

// memcpy wrapper.
// FUN_005010A0
void MEM_Copy(void *dst, const void *src, Uint32 nbytes)
{
	memcpy(dst, src, nbytes);
}

// FUN_005010B8
void func_005010b8(void *dst, const void *src, Uint32 nbytes)
{
	memcpy(dst, src, nbytes);
}

// FUN_005010D0
void func_005010d0(void *dst, const void *src, Uint32 nbytes)
{
	memcpy(dst, src, nbytes);
}

// FUN_005010E8
void func_005010e8(void *dst, const void *src, Uint32 nbytes)
{
	memcpy(dst, src, nbytes);
}

// FUN_00501100
void func_00501100(void *dst, const void *src, Uint32 nbytes)
{
	MEM_Copy(dst, src, nbytes);
}
