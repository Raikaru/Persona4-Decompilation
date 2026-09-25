/* memcpyd.c copy aliases delegate to mcp_not.c with the same destination, source, and length. */
#include "cri_xpt.h"

extern void func_005010b8(void *dst, const void *src, Uint32 nbytes);
extern void func_005010d0(void *dst, const void *src, Uint32 nbytes);
extern void func_005010e8(void *dst, const void *src, Uint32 nbytes);

// FUN_00501118
void func_00501118(void *dst, const void *src, Uint32 nbytes)
{
	func_005010b8(dst, src, nbytes);
}

// FUN_00501130
void func_00501130(void *dst, const void *src, Uint32 nbytes)
{
	func_005010d0(dst, src, nbytes);
}

// FUN_00501148
void func_00501148(void *dst, const void *src, Uint32 nbytes)
{
	func_005010e8(dst, src, nbytes);
}
