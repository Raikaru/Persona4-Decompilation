/* ADX input sound-joint setter at retail 004CDCA0. */
#include "cri_xpt.h"

extern void ADXB_SetAhxInSj(void *adxb);
extern void func_004c1a68(void *adxb, void *sji);
// FUN_004CDCA0
void ADXSJD_SetInSj(Uint32 sjd, Uint32 sji)
{
	*(Uint32 *)((Uint8 *)sjd + 0x08) = sji;
	ADXB_SetAhxInSj(*(void **)((Uint8 *)sjd + 0x04));
	func_004c1a68(*(void **)((Uint8 *)sjd + 0x04), (void *)sji);
}

