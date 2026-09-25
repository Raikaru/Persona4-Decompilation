/* ADX stream-joint decoder controls at retail 004CDCF0..004CDD30. */
#include "cri_xpt.h"

extern void func_004c1c80(void *adxb, Sint32 nsmpl);
extern void func_004c1a98(void *adxb, Sint32 nsmpl);
extern void func_004c1d10(void *adxb);
extern void func_004c1ab8(void *adxb);

// FUN_004CDCF0
void ADXSJD_SetMaxDecSmpl(Uint32 sjd, Sint32 nsmpl)
{
	*(Sint32 *)((Uint8 *)sjd + 0x38) = nsmpl;
	func_004c1c80(*(void **)((Uint8 *)sjd + 0x04), nsmpl);
	func_004c1a98(*(void **)((Uint8 *)sjd + 0x04), nsmpl);
}

// FUN_004CDD30
void ADXSJD_TermSupply(Uint32 sjd)
{
	func_004c1d10(*(void **)((Uint8 *)sjd + 0x04));
	func_004c1ab8(*(void **)((Uint8 *)sjd + 0x04));
}
