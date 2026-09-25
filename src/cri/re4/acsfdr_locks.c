/* CRI sound-driver critical-section adapters. */
#include "cri_xpt.h"

extern void func_004f0638(void);
extern void func_004f06b0(void);
extern void func_004f0650(void);
extern void func_004f06c8(void);
extern void func_004f1278(void);
extern Uint32 func_004c6a98();

// FUN_004BD628
void func_004bd628(void)
{
	func_004f0638();
}

// FUN_004BD640
void func_004bd640(void)
{
	func_004f06b0();
}

// FUN_004BD658
void func_004bd658(void)
{
	func_004f0650();
}

// FUN_004BD670
void func_004bd670(void)
{
	func_004f06c8();
}

// FUN_004BD688
void func_004bd688(void)
{
	func_004f1278();
}

// FUN_004BD6A0
Uint32 func_004bd6a0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c6a98(a0, a1, a2, a3);
}
