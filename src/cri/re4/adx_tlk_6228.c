/* ADX talk entrypoints for the PS2 RNA output buffer. */
#include "cri_xpt.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004cd918(void *buffer);
extern void *func_004cd930(void);
void func_004d6258(void *buffer);
void *func_004d62a8(void);

// FUN_004D6228
void func_004d6228(void *buffer)
{
	func_004c54d8();
	func_004d6258(buffer);
	func_004c54e0();
}

// FUN_004D6258
void func_004d6258(void *buffer)
{
	func_004cd918(buffer);
}

// FUN_004D6270
void *func_004d6270(void)
{
	void *buffer;

	func_004c54d8();
	buffer = func_004d62a8();
	func_004c54e0();
	return buffer;
}

// FUN_004D62A8
void *func_004d62a8(void)
{
	return func_004cd930();
}
